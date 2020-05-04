/*
 *  drivers/mtd/spinand/spinand_uboot.c
 *
 *  Copyright (c) 2013 Gofortune Semiconductor Corporation.
 *   Kewell Liu  <liujingke@gofortune-semi.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

/*
 * SpiNAND initialization at U-Boot
 */

#include <common.h>
#include <malloc.h>

#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>

#include <linux/mtd/spinand.h>

struct mtd_info snand_mtd;
struct spinand_chip snand_chip;
static __attribute__((unused)) char dev_name[] = "spinand0";

/*
 * board_nand_init - Board specific NAND initialization
 * @nand:   mtd private chip structure
 *
 * Called by nand_init to initialize the board specific functions
 */
void board_nand_init(void)
{
    int res;
    
    memset(&snand_mtd, 0, sizeof(struct mtd_info));
    memset(&snand_chip, 0, sizeof(struct spinand_chip));

    snand_mtd.priv = &snand_chip;
    snand_chip.mtd = &snand_mtd;

    /*
        * It's used for some board init required
        */
    res = spinand_board_init(&snand_mtd);
    if (res)
    {
        debug("[%s_%d]board init failed with %d\n", __FUNCTION__, __LINE__, res);
        return;
    }

    res = spinand_scan(&snand_mtd);
    if (res)
    {
        debug("[%s_%d]SpiNAND scan failed with %d\n", __FUNCTION__, __LINE__, res);
        kfree(snand_chip.buffers);
        kfree(snand_chip.oobbuf);
        return;
    }

#ifdef CONFIG_MTD_DEVICE
    /*
     * Add MTD device so that we can reference it later
     * via the mtdcore infrastructure (e.g. ubi).
     */
    snand_mtd.name = dev_name;
    res = add_mtd_device(&snand_mtd);
    if (res)
    {
        debug("[%s_%d]add mtd device failed!\n", __FUNCTION__, __LINE__);
        kfree(snand_chip.buffers);
        kfree(snand_chip.oobbuf);
        return;
    }

#endif

}

