/*
 * drivers/mtd/spinand/spinand_util.c
 *
 *  Copyright (c) 2013 Gofortune Semiconductor Corporation.
 *   Kewell Liu  <liujingke@gofortune-semi.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Copyright 2010 Freescale Semiconductor
 * The portions of this file whose copyright is held by Freescale and which
 * are not considered a derived work of GPL v2-only code may be distributed
 * and/or modified under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 */

#include <common.h>
#include <command.h>
#include <watchdog.h>
#include <malloc.h>
#include <div64.h>

#include <asm/errno.h>
#include <linux/mtd/mtd.h>
#include <nand.h>
#include <jffs2/jffs2.h>
#include <linux/mtd/spinand.h>

/* Kewell debug macro >> */

//#define KE_DEBUG_W
//#define KE_DEBUG_R

/* Kewell debug macro << */


/* support only for native endian JFFS2 */
#define cpu_to_je16(x) (x)
#define cpu_to_je32(x) (x)

/**
 * spinand_erase_opts: - erase NAND flash with support for various options
 *            (jffs2 formating)
 *
 * @param mtd      NAND device to erase
 * @param opts      options,  @see struct nand_erase_options
 * @return      0 in case of success
 *
 * This code is ported from flash_eraseall.c from Linux mtd utils by
 * Arcom Control System Ltd.
 */
int spinand_erase_opts(struct mtd_info *mtd, const struct nand_erase_options *opts)
{
    struct jffs2_unknown_node cleanmarker;
    struct erase_info erase;
    unsigned long erase_length, erased_length; /* in blocks */
    int bbtest = 1;
    int result;
    int percent_complete = -1;
    const char *mtd_device = mtd->name;
    struct mtd_oob_ops oob_opts;
    struct spinand_chip *chip = mtd->priv;

    if ((opts->offset & (mtd->writesize - 1)) != 0) {
        printf("Attempt to erase non page aligned data\n");
        return -1;
    }

    memset(&erase, 0, sizeof(erase));
    memset(&oob_opts, 0, sizeof(oob_opts));

    erase.mtd = mtd;
    erase.len  = mtd->erasesize;
    erase.addr = opts->offset;
    erase_length = lldiv(opts->length + mtd->erasesize - 1, mtd->erasesize);

    cleanmarker.magic = cpu_to_je16 (JFFS2_MAGIC_BITMASK);
    cleanmarker.nodetype = cpu_to_je16 (JFFS2_NODETYPE_CLEANMARKER);
    cleanmarker.totlen = cpu_to_je32(8);

    /* scrub option allows to erase badblock. To prevent internal
     * check from erase() method, set block check method to dummy
     * and disable bad block table while erasing.
     */
    if (opts->scrub) {
        erase.scrub = opts->scrub;
        /*
         * We don't need the bad block table anymore...
         * after scrub, there are no bad blocks left!
         */
        if (chip->bbt) {
            kfree(chip->bbt);
        }
        chip->bbt = NULL;
    }

    for (erased_length = 0;
         erased_length < erase_length;
         erase.addr += mtd->erasesize) {

        WATCHDOG_RESET ();

        if (!opts->scrub && bbtest) {
            int ret = mtd->block_isbad(mtd, erase.addr);
            if (ret > 0) {
                if (!opts->quiet)
                    printf("\rSkipping bad block at  "
                           "0x%08llx                 "
                           "                         \n",
                           erase.addr);

                if (!opts->spread)
                    erased_length++;

                continue;

            } else if (ret < 0) {
                printf("\n%s: MTD get bad block failed: %d\n",
                       mtd_device,
                       ret);
                return -1;
            }
        }

        erased_length++;

        result = mtd->erase(mtd, &erase);
        if (result != 0) {
            printf("\n%s: MTD Erase failure: %d\n",
                   mtd_device, result);
            continue;
        }

        /* format for JFFS2 ? */
        if (opts->jffs2 && mtd->ecclayout->oobavail >= 8)
        {
            struct mtd_oob_ops ops;
            ops.ooblen = 8;
            ops.datbuf = NULL;
            ops.oobbuf = (uint8_t *)&cleanmarker;
            ops.ooboffs = 0;
            ops.mode = MTD_OOB_AUTO;

            result = mtd->write_oob(mtd, erase.addr, &ops);
            if (result != 0) {
                printf("\n%s: MTD writeoob failure: %d\n",
                       mtd_device, result);
                continue;
            }
        }

        if (!opts->quiet) {
            unsigned long long n = erased_length * 100ULL;
            int percent;

            do_div(n, erase_length);
            percent = (int)n;

            /* output progress message only at whole percent
             * steps to reduce the number of messages printed
             * on (slow) serial consoles
             */
            if (percent != percent_complete) {
                percent_complete = percent;

                printf("\rErasing at 0x%llx -- %3d%% complete.",
                       erase.addr, percent);

                if (opts->jffs2 && result == 0)
                    printf(" Cleanmarker written at 0x%llx.",
                           erase.addr);
            }
        }
    }
    if (!opts->quiet)
        printf("\n");

    if (opts->scrub)
        chip->scan_bbt(mtd);

    return 0;

}

/**
 * spinand_check_skip_len
 *
 * Check if there are any bad blocks, and whether length including bad
 * blocks fits into device
 *
 * @param mtd     NAND device
 * @param offset   offset in flash
 * @param length  image length
 * @return 0 if the image fits and there are no bad blocks
 *         1 if the image fits, but there are bad blocks
 *        -1 if the image does not fit
 */
static int spinand_check_skip_len(struct mtd_info *mtd, loff_t offset, size_t length)
{
    size_t len_excl_bad = 0;
    int ret = 0;

#if defined(KE_DEBUG_R) || defined(KE_DEBUG_W)

    printf ("[%s]: offset = 0x%llx, length = 0x%08x\n", __FUNCTION__, offset, length);

#endif

    while (len_excl_bad < length) {
        size_t block_len, block_off;
        loff_t block_start;

        if (offset >= mtd->size)
            return -1;

        block_start = offset & ~(loff_t)(mtd->erasesize - 1);
        block_off = offset & (mtd->erasesize - 1);
        block_len = mtd->erasesize - block_off;

#if defined(KE_DEBUG_R) || defined(KE_DEBUG_W)

        printf ("[%s]: b_start = 0x%08x, b_off = 0x%08x, b_len = 0x%08x\n",
                __FUNCTION__, block_start, block_off, block_len);

#endif

        if (!mtd->block_isbad(mtd, block_start))
            len_excl_bad += block_len;
        else
            ret = 1;

        offset += block_len;
    }

    return ret;
}

/**
 * spinand_write_skip_bad:
 *
 * Write image to NAND flash.
 * Blocks that are marked bad are skipped and the is written to the next
 * block instead as long as the image is short enough to fit even after
 * skipping the bad blocks.
 *
 * @param mtd       NAND device
 * @param offset    offset in flash
 * @param length    buffer length
 * @param buffer    buffer to read from
 * @param flags     flags modifying the behaviour of the write to NAND
 * @return      0 in case of success
 */
int spinand_write_skip_bad(struct mtd_info *mtd, loff_t offset, size_t *length,
            u_char *buffer, int flags)
{
    int rval = 0, blocksize;
    size_t left_to_write = *length;
    u_char *p_buffer = buffer;
    int need_skip;

#ifdef KE_DEBUG_W

    printf ("[%s]: offset = 0x%llx, length = 0x%08x, buf = 0x%08x, flags = %d\n",
                __FUNCTION__, offset, *length, buffer, flags);

#endif

    blocksize = mtd->erasesize;

    /*
     * spinand_write() handles unaligned, partial page writes.
     *
     * We allow length to be unaligned, for convenience in
     * using the $filesize variable.
     *
     * However, starting at an unaligned offset makes the
     * semantics of bad block skipping ambiguous (really,
     * you should only start a block skipping access at a
     * partition boundary).  So don't try to handle that.
     */
    if ((offset & (mtd->writesize - 1)) != 0) {
        printf ("Attempt to write non page aligned data\n");
        *length = 0;
        return -EINVAL;
    }

    need_skip = spinand_check_skip_len(mtd, offset, *length);
    if (need_skip < 0) {
        printf ("Attempt to write outside the flash area\n");
        *length = 0;
        return -EINVAL;
    }

    if (!need_skip && !(flags & WITH_DROP_FFS)) {
        rval = mtd->write(mtd, offset, *length, length, buffer);
        if (rval == 0)
            return 0;

        *length = 0;
        printf ("NAND write to offset %llx failed %d\n",
            offset, rval);
        return rval;
    }

    while (left_to_write > 0) {
        size_t block_offset = offset & (mtd->erasesize - 1);
        size_t write_size, truncated_write_size;

        WATCHDOG_RESET ();

        if (mtd->block_isbad (mtd, offset & ~(mtd->erasesize - 1))) {
            printf ("Skip bad block 0x%08llx\n",
                offset & ~(mtd->erasesize - 1));
            offset += mtd->erasesize - block_offset;
            continue;
        }

#ifdef KE_DEBUG_W

        printf ("[%s]: offset = 0x%llx, b_off = 0x%llx, left_to_write = 0x%08x, buf = 0x%08x\n",
                    __FUNCTION__, offset, block_offset, left_to_write, p_buffer);

#endif


        if (left_to_write < (blocksize - block_offset))
            write_size = left_to_write;
        else
            write_size = blocksize - block_offset;


        truncated_write_size = write_size;

        rval = mtd->write(mtd, offset, truncated_write_size, &truncated_write_size, p_buffer);
        offset += write_size;
        p_buffer += write_size;

        if (rval != 0) {
            printf ("NAND write to offset %llx failed %d\n", offset, rval);
            *length -= left_to_write;
            return rval;
        }

        left_to_write -= write_size;
    }

    return 0;

}

/**
 * spinand_read_skip_bad:
 *
 * Read image from NAND flash.
 * Blocks that are marked bad are skipped and the next block is readen
 * instead as long as the image is short enough to fit even after skipping the
 * bad blocks.
 *
 * @param mtd       NAND device
 * @param offset    offset in flash
 * @param length    buffer length, on return holds remaining bytes to read
 * @param buffer    buffer to write to
 * @return 0 in case of success
 */
int spinand_read_skip_bad(struct mtd_info *mtd, loff_t offset, size_t *length,
               u_char *buffer)
{
    int rval;
    size_t left_to_read = *length;
    u_char *p_buffer = buffer;
    int need_skip;

#ifdef KE_DEBUG_R

    printf ("[%s]: offset = 0x%llx, length = 0x%08x, buf = 0x%08x\n",
                __FUNCTION__, offset, *length, buffer);

#endif

    if ((offset & (mtd->writesize - 1)) != 0) {
        printf ("Attempt to read non page aligned data\n");
        *length = 0;
        return -EINVAL;
    }

    need_skip = spinand_check_skip_len(mtd, offset, *length);
    if (need_skip < 0) {
        printf ("Attempt to read outside the flash area\n");
        *length = 0;
        return -EINVAL;
    }

    if (!need_skip) {
        rval = mtd->read (mtd, offset, *length, length, buffer);
        if (!rval || rval == -EUCLEAN)
            return 0;

        *length = 0;
        printf ("NAND read from offset %llx failed %d\n", offset, rval);
        return rval;
    }

    while (left_to_read > 0)
    {
        size_t block_offset = offset & (mtd->erasesize - 1);
        size_t read_length;

        WATCHDOG_RESET ();

        if (mtd->block_isbad (mtd, offset & ~(mtd->erasesize - 1))) {
            printf ("Skipping bad block 0x%08llx\n",
                offset & ~(mtd->erasesize - 1));
            offset += mtd->erasesize - block_offset;
            continue;
        }

#ifdef KE_DEBUG_R

        printf ("[%s]: offset = 0x%llx, b_off = 0x%llx, left_to_read = 0x%08x, buf = 0x%08x\n",
                    __FUNCTION__, offset, block_offset, left_to_read, p_buffer);

#endif

        if (left_to_read < (mtd->erasesize - block_offset))
            read_length = left_to_read;
        else
            read_length = mtd->erasesize - block_offset;

        rval = mtd->read (mtd, offset, read_length, &read_length, p_buffer);
        if (rval && rval != -EUCLEAN) {
            printf ("NAND read from offset %llx failed %d\n", offset, rval);
            *length -= left_to_read;
            return rval;
        }

        left_to_read -= read_length;
        offset       += read_length;
        p_buffer     += read_length;
    }

    return 0;

}

