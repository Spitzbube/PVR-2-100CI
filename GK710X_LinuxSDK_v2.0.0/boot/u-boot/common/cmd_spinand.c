/*
 *  U-Boot command for SpiNAND support
 *
 *  Copyright (c) 2013 Gofortune Semiconductor Corporation.
 *   Kewell Liu  <liujingke@gofortune-semi.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <common.h>
#include <command.h>
#include <malloc.h>

#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/spinand.h>
#include <bootimg.h>
#include <bootloader.h>

#include <asm/io.h>
#include <watchdog.h>
#include <asm/byteorder.h>
#include <jffs2/jffs2.h>
#include <nand.h>

#if defined(CONFIG_CMD_MTDPARTS)

/* partition handling routines */
int mtdparts_init(void);
int find_dev_and_part(const char *id, struct mtd_device **dev,
              u8 *part_num, struct part_info **part);
#endif

static int snand_dump(struct mtd_info *mtd, ulong off, int only_oob, int repeat)
{
    int i;
    u_char *datbuf, *oobbuf, *p;
    static loff_t last;

    if (repeat)
        off = last + mtd->writesize;

    last = off;

    datbuf = memalign(ARCH_DMA_MINALIGN, mtd->writesize);
    oobbuf = memalign(ARCH_DMA_MINALIGN, mtd->oobsize);
    if (!datbuf || !oobbuf) {
        puts("snand_dump: No memory for page buffer\n");
        return 1;
    }
    off &= ~(mtd->writesize - 1);
    loff_t addr = (loff_t) off;
    struct mtd_oob_ops ops;
    memset(&ops, 0, sizeof(ops));
    ops.datbuf = datbuf;
    ops.oobbuf = oobbuf;
    ops.len = mtd->writesize;
    ops.ooblen = mtd->oobsize;
    ops.mode = MTD_OOB_RAW;
    i = mtd->read_oob(mtd, addr, &ops);
    if (i < 0) {
        printf("snand_dump: Error (%d) reading page %08lx\n", i, off);
        free(datbuf);
        free(oobbuf);
        return 1;
    }
    printf("Page %08lx dump:\n", off);
    i = mtd->writesize >> 4;
    p = datbuf;

    while (i--) {
        if (!only_oob)
            printf("\t%02x %02x %02x %02x %02x %02x %02x %02x"
                   "  %02x %02x %02x %02x %02x %02x %02x %02x\n",
                   p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7],
                   p[8], p[9], p[10], p[11], p[12], p[13], p[14],
                   p[15]);
        p += 16;
    }
    puts("OOB:\n");
    i = mtd->oobsize >> 3;
    p = oobbuf;
    while (i--) {
        printf("\t%02x %02x %02x %02x %02x %02x %02x %02x\n",
               p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
        p += 8;
    }
    free(datbuf);
    free(oobbuf);

    return 0;
}

static inline int snand_str2off(const char *p, loff_t *num)
{
    char *endptr;

    *num = simple_strtoull(p, &endptr, 16);
    return *p != '\0' && *endptr == '\0';
}

static inline int snand_str2long(const char *p, ulong *num)
{
    char *endptr;

    *num = simple_strtoul(p, &endptr, 16);
    return *p != '\0' && *endptr == '\0';
}

static int snand_get_part(const char *partname, loff_t *off, loff_t *size)
{
#ifdef CONFIG_CMD_MTDPARTS
    struct mtd_device *dev;
    struct part_info *part;
    u8 pnum;
    int ret;

    ret = mtdparts_init();
    if (ret)
        return ret;

    ret = find_dev_and_part(partname, &dev, &pnum, &part);
    if (ret)
        return ret;

    if (dev->id->type != MTD_DEV_TYPE_NAND) {
        puts("snand_get_part: not a NAND device\n");
        return -1;
    }

    *off = part->offset;
    *size = part->size;

    return 0;
#else
    puts("snand_get_part: offset is not a number\n");
    return -1;
#endif
}

static int snand_arg_off(const char *arg, loff_t *off, loff_t *maxsize)
{
    struct mtd_info *mtd = &snand_mtd;

    if (!snand_str2off(arg, off))
        return snand_get_part(arg, off, maxsize);

    if (*off >= mtd->size) {
        puts("Offset exceeds device limit\n");
        return -1;
    }

    *maxsize = mtd->size - *off;
    return 0;
}

static int snand_arg_off_size(int argc, char *const argv[],
            loff_t *off, loff_t *size)
{
    struct mtd_info *mtd = &snand_mtd;
    int ret;
    loff_t maxsize = 0;

    if (argc == 0) {
        *off = 0;
        *size = mtd->size;
        goto print;
    }

    ret = snand_arg_off(argv[0], off, &maxsize);
    if (ret)
        return ret;

    if (argc == 1) {
        *size = maxsize;
        goto print;
    }

    if (!snand_str2off(argv[1], size)) {
        printf("'%s' is not a number\n", argv[1]);
        return -1;
    }

    if (*size > maxsize) {
        puts("Size exceeds partition or device limit\n");
        return -1;
    }

print:
    printf("device : ");
    if (*size == mtd->size)
        puts("whole chip\n");
    else
        printf("offset 0x%llx, size 0x%llx\n",
               (unsigned long long)*off, (unsigned long long)*size);
    return 0;
}

#ifdef CONFIG_ENV_OFFSET_OOB
unsigned long snand_env_oob_offset;

int do_snand_env_oob(cmd_tbl_t *cmdtp, int argc, char *const argv[])
{
    int ret;
    uint32_t oob_buf[ENV_OFFSET_SIZE/sizeof(uint32_t)];
    struct mtd_info *mtd = &snand_mtd;
    char *cmd = argv[1];

    if (CONFIG_SYS_MAX_NAND_DEVICE == 0 || !mtd->name) {
        puts("no devices available\n");
        return 1;
    }

    if (!strcmp(cmd, "get")) {
        ret = get_spinand_env_oob(mtd, &snand_env_oob_offset);
        if (ret)
            return 1;

        printf("0x%08lx\n", snand_env_oob_offset);
    } else if (!strcmp(cmd, "set")) {
        loff_t addr;
        loff_t maxsize;
        struct mtd_oob_ops ops;
        int idx = 0;

        if (argc < 3)
            goto usage;

        if (snand_arg_off(argv[2], &idx, &addr, &maxsize)) {
            puts("Offset or partition name expected\n");
            return 1;
        }

        if (idx != 0) {
            puts("Partition not on first NAND device\n");
            return 1;
        }

        if (mtd->oobavail < ENV_OFFSET_SIZE) {
            printf("Insufficient available OOB bytes:\n"
                   "%d OOB bytes available but %d required for "
                   "env.oob support\n",
                   mtd->oobavail, ENV_OFFSET_SIZE);
            return 1;
        }

        if ((addr & (mtd->erasesize - 1)) != 0) {
            printf("Environment offset must be block-aligned\n");
            return 1;
        }

        ops.datbuf = NULL;
        ops.len = 0;
        ops.mode = MTD_OOB_AUTO;
        ops.ooboffs = 0;
        ops.ooblen = ENV_OFFSET_SIZE;
        ops.oobbuf = (void *) oob_buf;

        oob_buf[0] = ENV_OOB_MARKER;
        oob_buf[1] = addr / mtd->erasesize;

        ret = mtd->write_oob(mtd, ENV_OFFSET_SIZE, &ops);
        if (ret) {
            printf("Error writing OOB block 0\n");
            return ret;
        }

        ret = get_spinand_env_oob(mtd, &snand_env_oob_offset);
        if (ret) {
            printf("Error reading env offset in OOB\n");
            return ret;
        }

        if (addr != snand_env_oob_offset) {
            printf("Verification of env offset in OOB failed: "
                   "0x%08llx expected but got 0x%08lx\n",
                   (unsigned long long)addr, snand_env_oob_offset);
            return 1;
        }
    }
    else {
        goto usage;
    }

    return ret;

usage:
    return CMD_RET_USAGE;

}

#endif

static void snand_print_and_set_info(struct mtd_info *mtd)
{
    const int bufsz = 32;
    char buf[bufsz];

    printf("Device %d: ", 0);
    printf("%s, sector size %u KiB\n",
           mtd->name, mtd->erasesize >> 10);
    printf("  Page size  %8d b\n", mtd->writesize);
    printf("  OOB size   %8d b\n", mtd->oobsize);
    printf("  Erase size %8d b\n", mtd->erasesize);

    /* Set geometry info */
    sprintf(buf, "%x", mtd->writesize);
    setenv("nand_writesize", buf);

    sprintf(buf, "%x", mtd->oobsize);
    setenv("nand_oobsize", buf);

    sprintf(buf, "%x", mtd->erasesize);
    setenv("nand_erasesize", buf);
}

static int snand_raw_access(struct mtd_info *mtd, ulong addr, loff_t off, ulong count,
            int read)
{
    int ret = 0;

    while (count--)
    {
        /* Raw access */
        mtd_oob_ops_t ops = {
            .datbuf = (u8 *)addr,
            .oobbuf = ((u8 *)addr) + mtd->writesize,
            .len = mtd->writesize,
            .ooblen = mtd->oobsize,
            .mode = MTD_OOB_RAW
        };

        if (read)
            ret = mtd->read_oob(mtd, off, &ops);
        else
            ret = mtd->write_oob(mtd, off, &ops);

        if (ret) {
            printf("%s: error at offset %llx, ret %d\n",__func__, (long long)off, ret);
            break;
        }

        addr += mtd->writesize + mtd->oobsize;
        off += mtd->writesize;
    }

    return ret;

}

int do_snand(cmd_tbl_t * cmdtp, int flag, int argc, char * const argv[])
{
    int ret = 0;
    ulong addr;
    loff_t off, size;
    char *cmd, *s;
    struct mtd_info *mtd = &snand_mtd;
    int quiet = 0;

    const char *quiet_str = getenv("quiet");
    int repeat = flag & CMD_FLAG_REPEAT;

    /* at least two arguments please */
    if (argc < 2)
        goto usage;

    if (quiet_str)
        quiet = simple_strtoul(quiet_str, NULL, 0) != 0;

    cmd = argv[1];

    /* Only "dump" is repeatable. */
    if (repeat && strcmp(cmd, "dump"))
        return 0;

    if (strcmp(cmd, "info") == 0) {

        putc('\n');
        if (mtd->name)
            snand_print_and_set_info(mtd);
        return 0;
    }

    if (strcmp(cmd, "reset") == 0) {

        putc('\n');
        if (mtd->name)
            mtd->sync(mtd);
        return 0;
    }

#ifdef CONFIG_ENV_OFFSET_OOB
    /* this command operates only on the first nand device */
    if (strcmp(cmd, "env.oob") == 0)
        return do_snand_env_oob(cmdtp, argc - 1, argv + 1);
#endif

    /* The following commands operate on the current device, unless
     * overridden by a partition specifier.  Note that if somehow the
     * current device is invalid, it will have to be changed to a valid
     * one before these commands can run, even if a partition specifier
     * for another device is to be used.
     */

    if (strcmp(cmd, "bad") == 0) {
        printf("\nDevice bad blocks:\n");
        for (off = 0; off < mtd->size; off += mtd->erasesize)
            if (mtd->block_isbad(mtd, off))
                printf("  %08llx\n", (unsigned long long)off);
        return 0;
    }

    /*
        * Syntax is:
        *      0        1        2       3    4
        *   snand erase [clean] [off size]
        */
    if (strncmp(cmd, "erase", 5) == 0 || strncmp(cmd, "scrub", 5) == 0)
    {
        nand_erase_options_t opts;

        /* "clean" at index 2 means request to write cleanmarker */
        int clean = argc > 2 && !strcmp("clean", argv[2]);
        int scrub_yes = argc > 2 && !strcmp("-y", argv[2]);
        int o = (clean || scrub_yes) ? 3 : 2;
        int scrub = !strncmp(cmd, "scrub", 5);
        int spread = 0;
        int args = 2;
        const char *scrub_warn =
            "Warning: "
            "scrub option will erase all factory set bad blocks!\n"
            "         "
            "There is no reliable way to recover them.\n"
            "         "
            "Use this command only for testing purposes if you\n"
            "         "
            "are sure of what you are doing!\n"
            "\nReally scrub this NAND flash? <y/N>\n";

        if (cmd[5] != 0) {
            if (!strcmp(&cmd[5], ".spread")) {
                spread = 1;
            } else if (!strcmp(&cmd[5], ".part")) {
                args = 1;
            } else if (!strcmp(&cmd[5], ".chip")) {
                args = 0;
            } else {
                goto usage;
            }
        }

        /*
         * Don't allow missing arguments to cause full chip/partition
         * erases -- easy to do accidentally, e.g. with a misspelled
         * variable name.
         */
        if (argc != o + args)
            goto usage;

        printf("\nNAND %s: ", cmd);
        /* skip first two or three arguments, look for offset and size */
        if (snand_arg_off_size(argc - o, argv + o, &off, &size) != 0)
            return 1;

        memset(&opts, 0, sizeof(opts));
        opts.offset = off;
        opts.length = size;
        opts.jffs2  = clean;
        opts.quiet  = quiet;
        opts.spread = spread;

        if (scrub) {
            if (!scrub_yes)
                puts(scrub_warn);

            if (scrub_yes)
                opts.scrub = 1;
            else if (getc() == 'y') {
                puts("y");
                if (getc() == '\r')
                    opts.scrub = 1;
                else {
                    puts("scrub aborted\n");
                    return -1;
                }
            } else {
                puts("scrub aborted\n");
                return -1;
            }
        }
        ret = spinand_erase_opts(mtd, &opts);
        printf("%s\n", ret ? "ERROR" : "OK");

        return ret == 0 ? 0 : 1;
    }

    if (strncmp(cmd, "dump", 4) == 0) {
        if (argc < 3)
            goto usage;

        off = (int)simple_strtoul(argv[2], NULL, 16);
        ret = snand_dump(mtd, off, !strcmp(&cmd[4], ".oob"), repeat);

        return ret == 0 ? 1 : 0;
    }

    if (strncmp(cmd, "read", 4) == 0 || strncmp(cmd, "write", 5) == 0) {
        size_t rwsize;
        ulong pagecount = 1;
        int read;
        int raw = 0;

        if (argc < 4)
            goto usage;

        addr = (ulong)simple_strtoul(argv[2], NULL, 16);

        read = strncmp(cmd, "read", 4) == 0; /* 1 = read, 0 = write */
        printf("\nNAND %s: ", read ? "read" : "write");

        s = strchr(cmd, '.');

        if (s && !strcmp(s, ".raw")) {
            raw = 1;

            if (snand_arg_off(argv[3], &off, &size))
                return 1;

            if (argc > 4 && !snand_str2long(argv[4], &pagecount)) {
                printf("'%s' is not a number\n", argv[4]);
                return 1;
            }

            if (pagecount * mtd->writesize > size) {
                puts("Size exceeds partition or device limit\n");
                return -1;
            }

            rwsize = pagecount * (mtd->writesize + mtd->oobsize);
        } else {
            if (snand_arg_off_size(argc - 3, argv + 3, &off, &size) != 0)
                return 1;

            rwsize = size;
        }

        if (!s || !strcmp(s, ".jffs2") ||
            !strcmp(s, ".e") || !strcmp(s, ".i"))
        {
            if (read)
                ret = spinand_read_skip_bad(mtd, off, &rwsize,
                             (u_char *)addr);
            else
                ret = spinand_write_skip_bad(mtd, off, &rwsize,
                              (u_char *)addr, 0);
        }
        else if (!strcmp(s, ".oobr"))
        {
            /* out-of-band data */
            mtd_oob_ops_t ops = {
                .oobbuf = (u8 *)addr,
                .ooblen = rwsize,
                .mode = MTD_OOB_RAW,
                .len = 0,
                .datbuf = NULL,
            };

            if (read)
                ret = mtd->read_oob(mtd, off, &ops);
            else
                ret = mtd->write_oob(mtd, off, &ops);
        }
        else if (!strcmp(s, ".oobp"))
        {
            /* out-of-band data */
            mtd_oob_ops_t ops = {
                .oobbuf = (u8 *)addr,
                .ooblen = rwsize,
                .mode = MTD_OOB_PLACE,
                .len = 0,
                .datbuf = NULL,
            };

            if (read)
                ret = mtd->read_oob(mtd, off, &ops);
            else
                ret = mtd->write_oob(mtd, off, &ops);
        }
        else if (!strcmp(s, ".ooba"))
        {
            /* out-of-band data */
            mtd_oob_ops_t ops = {
                .oobbuf = (u8 *)addr,
                .ooblen = rwsize,
                .mode = MTD_OOB_AUTO,
                .len = 0,
                .datbuf = NULL,
            };

            if (read)
                ret = mtd->read_oob(mtd, off, &ops);
            else
                ret = mtd->write_oob(mtd, off, &ops);
        }
        else if (raw)
        {
            ret = snand_raw_access(mtd, addr, off, pagecount, read);
        }
        else
        {
            printf("Unknown spinand command suffix '%s'.\n", s);
            return 1;
        }

        printf(" %zu bytes %s: %s\n", rwsize,
               read ? "read" : "written", ret ? "ERROR" : "OK");

        return ret == 0 ? 0 : 1;

    }

    if (strcmp(cmd, "markbad") == 0) {
        argc -= 2;
        argv += 2;

        if (argc <= 0)
            goto usage;

        while (argc > 0) {
            addr = simple_strtoul(*argv, NULL, 16);

            if (mtd->block_markbad(mtd, addr)) {
                printf("block 0x%08lx NOT marked as bad! ERROR %d\n", addr, ret);
                ret = 1;
            } else {
                printf("block 0x%08lx successfully marked as bad\n", addr);
            }
            --argc;
            ++argv;
        }
        return ret;
    }

usage:

    return CMD_RET_USAGE;

}

U_BOOT_CMD(
    snand,    CONFIG_SYS_MAXARGS, 1,  do_snand,
    "SpiNAND sub-system",
    "info - show available SpiNAND devices\n"
    "snand read - addr off|partition size\n"
    "snand write - addr off|partition size\n"
    "    read/write 'size' bytes starting at offset 'off'\n"
    "    to/from memory address 'addr', skipping bad blocks.\n"
    "snand read.raw - addr off|partition [count]\n"
    "snand write.raw - addr off|partition [count]\n"
    "    Use read.raw/write.raw to avoid ECC and access the flash as-is.\n"
    "snand erase[.spread] [clean] off size - erase 'size' bytes from offset 'off'\n"
    "    With '.spread', erase enough for given file size, otherwise,\n"
    "    'size' includes skipped bad blocks.\n"
    "snand erase.part [clean] partition - erase entire mtd partition'\n"
    "snand bad - show bad blocks\n"
    "snand reset - reset the nand flash\n"
    "snand dump[.oob] off - dump page\n"
    "snand scrub [-y] off size | scrub.part partition | scrub.chip\n"
    "    really clean NAND erasing bad blocks (UNSAFE)\n"
    "snand markbad off [...] - mark bad block(s) at offset (UNSAFE)\n"
#ifdef CONFIG_ENV_OFFSET_OOB
    "\n"
    "snand env.oob - environment offset in OOB of block 0 of first device.\n"
    "snand env.oob set off|partition - set enviromnent offset\n"
    "snand env.oob get - get environment offset"
#endif

);

#ifdef CONFIG_GK6202_ANDROID
#ifdef CONFIG_CHECK_RECOVERY_COMMAND_FILE
extern int spinand_yaffs_devconfig(char *_mp, int start_block, int end_block);
extern int spinand_yaffs_mount(char *mp);
extern void spinand_yaffs_umount(char *mp);
extern int spinand_yaffs_open_file(char *fn);
extern void spinand_yaffs_close_file(int handle);
#endif

typedef enum BCB_COMMAND
{
	BCB_COMMAND_NULL,
	BCB_COMMAND_RECOVERY
}BCB_COMMAND_E;

typedef enum BOOT_MODE
{
	NORMAL_BOOT_MODE,
	RECOVERY_BOOT_MODE
}BOOT_MODE_E;

unsigned char raw_header[2048];

static int boot_linux_from_flash(cmd_tbl_t *cmdtp, struct mtd_device *dev,
			   struct part_info *part, char *cmd)
{
	struct mtd_info *mtd = &snand_mtd;
    boot_img_hdr *hdr = (void*) raw_header;
	unsigned hdr_len = sizeof(raw_header);
    unsigned n;
    unsigned offset = part->offset;
	char buf[32];
	/*use uboot bootargs*/
#if 0
    const char *cmdline;
#endif
	
	printf("\nBoot from partition:%s @(0x%x)\n",part->name,part->offset);

	if ((part->offset & (mtd->erasesize - 1)) != 0) {
        printf("mtd partition non block aligned \n");
        return -1;
    }

    if(spinand_read_skip_bad(mtd, offset, &hdr_len, raw_header)) {
        printf("READ BOOT IMAGE HEADER FAILED\n");
        return -1;
    }
        
    if(memcmp(hdr->magic, BOOT_MAGIC, BOOT_MAGIC_SIZE)) {
        printf("INVALID BOOT IMAGE HEADER\n");
        return -1;
    }

	offset += 2048;
   	while(mtd->block_isbad(mtd, offset))
	{
		offset += mtd->erasesize;
		if (offset >= part->offset + part->size)
			return -1;   	
   	}
	
    n = (hdr->kernel_size + (mtd->writesize - 1)) & (~(mtd->writesize - 1));
    if(spinand_read_skip_bad(mtd, offset, &n,(void*) hdr->kernel_addr)) {
        printf("READ KERNEL IMAGE FAILED\n");
        return -1;
    }
	
    offset += n;
	while(mtd->block_isbad(mtd, offset))
	{
		offset += mtd->erasesize;
		if (offset >= part->offset + part->size)
			return -1;  	
   	}

    n = (hdr->ramdisk_size + (mtd->writesize - 1)) & (~(mtd->writesize - 1));
    if(spinand_read_skip_bad(mtd, offset, &n, (void*) hdr->ramdisk_addr)) {
        printf("READ RAMDISK IMAGE FAILED\n");
        return -1;
    }
	sprintf(buf, "%x", hdr->ramdisk_addr);
	setenv("ramdiskaddr", buf);

	sprintf(buf, "%x", hdr->ramdisk_addr + hdr->ramdisk_size);
	setenv("ramdiskend", buf);
	
    printf("\nkernel  @ %x (%d bytes)\n", hdr->kernel_addr, hdr->kernel_size);
    printf("ramdisk @ %x (%d bytes)\n\n\n", hdr->ramdisk_addr,hdr->ramdisk_size);

	/* Loading ok, update default load address */
	load_addr = hdr->kernel_addr;
	

/*use uboot bootargs*/
#if 0
    if(hdr->cmdline[0]) {
        cmdline = (char*) hdr->cmdline;
		setenv("bootargs", cmdline);
    } else {
        cmdline = getenv("bootargs");
        if(cmdline == 0) {
            cmdline = "mem=96M console=null";
			setenv("bootargs", cmdline);
        }
    }
    printf("cmdline = '%s'\n", cmdline);
#endif

	return bootm_maybe_autostart(cmdtp, cmd);
}

#ifdef CONFIG_CHECK_RECOVERY_COMMAND_FILE
int check_recovery_cmd_file(void)
{
	struct mtd_info *mtd = &snand_mtd;
	struct spinand_chip *chip = mtd->priv;
	struct mtd_device *dev;
	struct part_info *part;
	u8 pnum;
	char *mtpoint;
	int start_block;
	int end_block;
	int ret = 0;
	int yhandle = -1;

	if ((find_dev_and_part(CONFIG_ANDROID_PARTITION_CACHE, &dev, &pnum, &part) == 0)) {
		if (dev->id->type != MTD_DEV_TYPE_SPINAND) {
				puts("Not a SPINAND device\n");
				goto error;
		}	
	}	
	else {
		printf("NO Cache PARTITION\n");
        goto error;
	}

	if ((part->offset & (mtd->erasesize - 1)) != 0) {
        printf("mtd partition non block aligned \n");
        return -1;
    }
	
	mtpoint = part->name;
	start_block = part->offset >> chip->phys_erase_shift;
	end_block = (part->offset + part->size) >> chip->phys_erase_shift;
	/*preparing to mount cache partition*/
	ret = spinand_yaffs_devconfig(mtpoint, start_block, end_block);
	if(ret < 0){
		printf("error: %s config failed", mtpoint);
		goto error;
	}
	/*mount cache partition*/
	ret = spinand_yaffs_mount(mtpoint);
	if(ret < 0){
		printf("error: %s mount failed", mtpoint);
		goto error;
	}
	/*try to open recovery command file*/
	yhandle = spinand_yaffs_open_file(CONFIG_ANDROID_RECOVERY_COMMAND_FILE);
	if(yhandle < 0){
		/*recovery command file not exist*/
		spinand_yaffs_umount(mtpoint);
		return 0;
	}
	/*Find recovery command file*/
	spinand_yaffs_close_file(yhandle);
	spinand_yaffs_umount(mtpoint);
	return 1;

error:
	printf("check recovery mode failed\n");
	return -1;
		
}
#endif

int read_BCB_command(BCB_COMMAND_E *cmd)
{
	struct mtd_info *mtd = &snand_mtd;
	struct mtd_device *dev;
	struct part_info *part;
	unsigned offset;
	unsigned read_size;
	struct bootloader_message boot;
	char *data;
	u8 pnum;

	read_size = mtd->writesize * MISC_PAGES;
	data = malloc(read_size);
	
	if ((find_dev_and_part(CONFIG_ANDROID_PARTITION_MISC, &dev, &pnum, &part) == 0)) {
		if (dev->id->type != MTD_DEV_TYPE_SPINAND) {
				puts("Not a SPINAND device\n");
				goto error;
		}	
	}	
	else {
		printf("NO %s PARTITION\n",part->name);
        goto error;
	}
	
	if ((part->offset & (mtd->erasesize - 1)) != 0) {
        printf("mtd partition non block aligned \n");
        goto error;
    }

	if(spinand_read_skip_bad(mtd, part->offset, &read_size, (void*)data)) {
        printf("READ BCB FAILED\n");
		goto error;
    }

	memcpy((void*)&boot, (void*)(data + mtd->writesize * MISC_COMMAND_PAGE), sizeof(boot));

	if(!memcmp(boot.command, BOOT_RECOVERY_COMMAND, BOOT_RECOVERY_COMMAND_SIZE)) {
        printf("Find command \"%s\"\n",boot.command);
        *cmd = BCB_COMMAND_RECOVERY;
		free(data);
		return 0;
    }

	free(data);
	*cmd = BCB_COMMAND_NULL;
	return 0;	
error:
	free(data);
	return -1;
}

BOOT_MODE_E check_boot_mode(void)
{
	BOOT_MODE_E mode;
	BCB_COMMAND_E command;

	if(read_BCB_command(&command) < 0){
		printf("Check boot mode failed, try to normal boot\n");
		mode = NORMAL_BOOT_MODE;
	}
	else{
		switch(command){
		case BCB_COMMAND_RECOVERY:
			mode = RECOVERY_BOOT_MODE;
			break;
		
		case BCB_COMMAND_NULL:
			mode = NORMAL_BOOT_MODE;
		}
	}

#ifdef CONFIG_CHECK_RECOVERY_COMMAND_FILE
	if(mode != RECOVERY_BOOT_MODE){
		/*check recovery command file*/
		if(check_recovery_cmd_file()){
			printf("\rFind:recovery command file\n");
			mode = RECOVERY_BOOT_MODE;
		}
	}
#endif
	
	return mode;
}

int do_spinandboot(cmd_tbl_t * cmdtp, int flag, int argc, char * const argv[])
{
	struct mtd_device *dev;
	struct part_info *part;
	u8 pnum;
	char *bootpart;

	if (!getenv("mtdids")) {
		setenv("mtdids", MTDIDS_DEFAULT);
	}	
	if(!getenv("mtdparts")) {
		setenv("mtdparts", MTDPARTS_DEFAULT);
	}
	mtdparts_init();
		
	switch(check_boot_mode()){
		case RECOVERY_BOOT_MODE:
			/*boot recovery*/
			bootpart = CONFIG_ANDROID_PARTITION_RECOVERY;
			break;
			
		case NORMAL_BOOT_MODE:
			/*normal boot*/
			bootpart = CONFIG_ANDROID_PARTITION_BOOT;
	}
	
	if ((find_dev_and_part(bootpart, &dev, &pnum, &part) == 0)) {
		if (dev->id->type != MTD_DEV_TYPE_SPINAND) {
				puts("Not a SPINAND device\n");
				return 1;
		}
		return boot_linux_from_flash(cmdtp, dev, part, argv[0]);
	}
	else {
		printf("NO %s PARTITION\n", bootpart);
        return 1;
	}		
}

U_BOOT_CMD(snboot, 1, 1, do_spinandboot,
	"boot from SPINAND device",
	""
);
#endif
