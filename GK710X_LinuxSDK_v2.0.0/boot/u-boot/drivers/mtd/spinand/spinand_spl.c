/*
 * Copyright (C) 2011 Marek Vasut <marek.vasut@gmail.com>
 *
 * Based on code:
 *  Copyright (C) 2005-2009 Samsung Electronics
 *  Kyungmin Park <kyungmin.park@samsung.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
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
 */
//#include <stdio.h>
//#include <string.h>
#include <common.h>
#include <asm/io.h>
#include <linux/mtd/spinand.h>

/* Kewell add for debug >> */
#define KE_DEBUG_R
/* Kewell add for debug << */


/* base address for uboot */
#define CONFIG_SYS_PHY_UBOOT_BASE       CONFIG_SYS_SDRAM_BASE

#define CONFIG_SYS_NAND_U_BOOT_DST      (CONFIG_SYS_PHY_UBOOT_BASE + 0x2000000)   /* NUB load-addr      */
#define CONFIG_SYS_NAND_U_BOOT_START    CONFIG_SYS_NAND_U_BOOT_DST  /* NUB start-addr     */

#define CONFIG_SYS_NAND_U_BOOT_OFFS     0x100000//(4 * 1024)      /* Offset to RAM U-Boot image */
#define CONFIG_SYS_NAND_U_BOOT_SIZE     (512 * 1024)    /* Size of RAM U-Boot image   */

/*
 * board_nand_init - Board specific NAND initialization
 * @nand:   mtd private chip structure
 *
 * Called by nand_init to initialize the board specific functions
 */
void board_spinand_init(struct mtd_info *mtd)
{
    struct spinand_chip *chip = mtd->priv;
    int res;

    /*
        * It's used for some board init required
        */
    res = spinand_board_init(mtd);
    if (res)
    {
        debug("[%s_%d]board init failed with %d\n", __FUNCTION__, __LINE__, res);
        return;
    }

    debug("SpiNAND: ");
    debug("Chipsize : 0x%llx\n", chip->chipsize);
}

static int spinand_is_bad_block(struct mtd_info *mtd, int block)
{
    struct spinand_chip *chip = mtd->priv;
    struct spinand_info *info = chip->info;
    struct nand_bbt_descr *badblock_ptn = info->badblock_pattern;

    uint32_t    pageId, baddr;
    uint16_t    is_bad = 0;
    int    i = 0, res = 0;

    /* get the address of the current block */
    baddr = block << info->block_shift;

    if (chip->bbt_options & NAND_BBT_SCANLASTPAGE)
        baddr += mtd->erasesize - mtd->writesize;

    pageId = (uint32_t)(baddr >> chip->page_shift) & chip->pagemask;

#ifdef KE_DEBUG_R
    debug("[%s]: page_id = 0x%08x, block_id = %d\n",
            __FUNCTION__, pageId, block);
#endif

    do
    {
        if (chip->options & NAND_BUSWIDTH_16)
        {
            chip->read_page(chip, pageId,
                    (info->page_main_size + chip->badblockpos), badblock_ptn->len, (uint8_t*)&is_bad);
            is_bad = cpu_to_le16(is_bad);
            if (chip->badblockpos & 0x1)
                is_bad >>= 8;
            else
                is_bad &= 0xFF;
        }
        else
        {
            chip->read_page(chip, pageId,
                    (info->page_main_size + chip->badblockpos), badblock_ptn->len, (uint8_t*)&is_bad);
        }

        if (likely(chip->badblockbits == 8))
        {
            res = is_bad != 0xFF;
        }
        else
        {
            res = hweight8(is_bad) < chip->badblockbits;
        }
        baddr += mtd->writesize;
        pageId = (uint32_t)(baddr >> chip->page_shift) & chip->pagemask;
        i++;
    } while (!res && i < 2 && (chip->bbt_options & NAND_BBT_SCAN2NDPAGE));

#ifdef KE_DEBUG_R
    debug("[%s]: Block = 0x%04x, is %s\n",
                __FUNCTION__, (uint32_t)block, (res > 0)? "bad":"good");
#endif

    return res;

}

static int spinand_load(struct mtd_info *mtd, unsigned int offs,
             unsigned int uboot_size, uchar *dst)
{
    struct spinand_chip *chip = mtd->priv;
    struct spinand_info *info = chip->info;

    unsigned int block, lastblock;
    unsigned int pageid, pageaddr;

    /*
     * offs has to be aligned to a page address!
     */
    block = (offs / info->block_main_size);
    lastblock = ((offs + uboot_size - 1) / info->block_main_size);
    pageid = ((offs % info->block_main_size) / info->page_main_size);

#ifdef KE_DEBUG_R
    debug("%s:\n", __FUNCTION__);
    debug ("startblk     0x%08x\n"
            "lastblk      0x%08x\n"
            "startpid     0x%08x\n",
            block,
            lastblock,
            pageid);
#endif

    while (block <= lastblock)
    {
        pageaddr = block << (info->block_shift - info->page_shift);

        if (!spinand_is_bad_block(mtd, block))
        {
            /*
                    * Skip bad blocks
                    */
            while (pageid < info->page_per_block)
            {
                chip->read_page(chip, (pageaddr + pageid), 0, info->page_main_size, dst);
                dst += info->page_main_size;
                pageid++;
            }

            pageid = 0;
        }
        else
        {
            lastblock++;
        }

        block++;

    }

    return 0;

}

/*
 * The main entry for NAND booting. It's necessary that SDRAM is already
 * configured and available since this code loads the main U-Boot image
 * from NAND into SDRAM and starts it from there.
 */
void nand_boot(void)
{
    struct spinand_chip chip;
    struct mtd_info mtd;
    __attribute__((noreturn)) void (*uboot)(void);

    //memset(&mtd, 0, sizeof(struct mtd_info));
    //memset(&chip, 0, sizeof(struct spinand_chip));

    /*
     * Init board specific nand support
     */
    mtd.priv = &chip;
    chip.mtd = &mtd;
    chip.options = 0;
    board_spinand_init(&mtd);

    /*
     * Load U-Boot image from NAND into RAM
     */
    spinand_load(&mtd, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
          (uchar *)CONFIG_SYS_NAND_U_BOOT_DST);

#ifdef CONFIG_NAND_ENV_DST
    spinand_load(&mtd, CONFIG_ENV_OFFSET, CONFIG_ENV_SIZE,
          (uchar *)CONFIG_NAND_ENV_DST);

#ifdef CONFIG_ENV_OFFSET_REDUND
    spinand_load(&mtd, CONFIG_ENV_OFFSET_REDUND, CONFIG_ENV_SIZE,
          (uchar *)CONFIG_NAND_ENV_DST + CONFIG_ENV_SIZE);
#endif
#endif

    /*
     * Jump to U-Boot image
     */
    uboot = (void *)CONFIG_SYS_NAND_U_BOOT_START;
    (*uboot)();
}

