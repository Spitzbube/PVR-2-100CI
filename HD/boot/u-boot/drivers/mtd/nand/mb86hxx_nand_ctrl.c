/*
 *
 *  drivers/mtd/mb86h61_nand_ctrl.c
 *
 *  Copyright (c) 2011 Fujitsu Semiconductor ShangHai
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *  Overview:
 *   This is a device driver for the NAND flash device found on the
 *   FUJITSU MB86H61_PDK_LUX_V3 board
 *
 *    2011-7-25 Initial version
 */
 

#include <common.h>
#include <nand.h>
#include <asm/arch/mb86hxx.h>
#include <asm/arch/upi.h>
#include <asm/io.h>
#include <asm/errno.h>

#ifndef NAND_BBT_SCANFIRSTLASTPAGE
#define NAND_BBT_SCANFIRSTLASTPAGE 0x8000
#endif
#ifndef NAND_BBT_SCANLAST2NDPAGE
#define NAND_BBT_SCANLAST2NDPAGE 0x4000
#endif


/* Nand config mode */
#define CFG_MODE   0x0
#define CFG_MODE_ON  (0x1<<4)

/* Nand config timing */
#define CFG_TIMING 0x20

/* Nand config area */
#define CFG_AREA 0x40

/* Nand config ecc check */
#define CFG_EccCheck 0x60
#define ECCCHECK_ON  (0x1)
#define ECCCHECK_CER (0x1<<1)
#define ECCCHECK_UCE (0x1<<2)
#define ECCCHECK_EER (0x1<<3)
#define ECCCHECK_EBIT_OFFSET (8)
#define ECCCHECK_EBIT_MASK (0xf<<ECCCHECK_EBIT_OFFSET)
#define ECCCHECK_EADR_OFFSET (16)
#define ECCCHECK_EADR_MASK (0x1ff<<ECCCHECK_EADR_OFFSET)
#define ECCCHECK_ERR (ECCCHECK_CER | ECCCHECK_UCE | ECCCHECK_EER)
 


/* Nand config ecc gen */
#define CFG_EccGen 0x64
#define ECCGEN_OFFSET (0)
#define ECCGEN_MASK (0xffffff<<ECCGEN_OFFSET)

/* Nand config ECC checked */
#define CFG_EccChecked 0x68
#define ECCCHECKED_OFFSET (0)
#define ECCCHECKED_MASK (0xffffff<<0)

/* Nand config ecc error */
#define CFG_ECC_ERROR 
#define CFG_ECCERR_FER (0x1)
#define CFG_ECCERR_FION (0x1<<2)

#define NAND_DATA_OFFSET         0x0000
#define NAND_CMD_OFFSET          0x1000
#define NAND_ADDR_OFFSET         0x2000
#define NAND_CLEARALE_OFFSET     0x3000

/*
 * MTD structure for MB98H61 board
 */
static struct mtd_info *mb86h61_mtd = NULL;
static void __iomem *mb86h61_nand_base;





static inline void mb86h61_ctrl_nand_init(void)
{
    /* need we set the GPIO configure here?*/
    //uint32_t gpio_config;
    //gpio_config = readl(MB86HXX_GPIO_BASE + 0x5c4);
    //gpio_config &= (~0x03);
    //gpio_config |= 0x02;
    
    //writel(gpio_config, MB86HXX_GPIO_BASE + 0x5c4); 
    writel(0x0,        MB86HXX_NANDCFG_BASE+CFG_MODE);
    writel(0x0,        MB86HXX_NANDCFG_BASE+CFG_AREA);
    writel(0xF8FFF00F, MB86HXX_NANDCFG_BASE+CFG_TIMING);
    writel(0x0,        MB86HXX_NANDCFG_BASE+CFG_EccCheck);
    writel(0x0,        MB86HXX_NANDCFG_BASE+CFG_EccChecked);
    writel(0x10,       MB86HXX_NANDCFG_BASE+CFG_MODE);  
}

/*
 * disable the ecc hardware 
 */
static inline void mb86h61_ctrl_nand_disecc(void)
{
    uint32_t ecc_mode;
    
    ecc_mode = readl(MB86HXX_NANDCFG_BASE+CFG_EccCheck);
    ecc_mode &= (~ECCCHECK_ON);
    writel(ecc_mode,MB86HXX_NANDCFG_BASE+CFG_EccCheck);
    writel(0x00ffffff,MB86HXX_NANDCFG_BASE+CFG_EccChecked);
}

/*
 * enable the ecc hardware
 */
static inline void mb86h61_ctrl_nand_enableecc(void)
{
    /* Enable ECC */
    uint32_t ecc_mode;
    ecc_mode = readl(MB86HXX_NANDCFG_BASE+CFG_EccCheck);
    ecc_mode |= ECCCHECK_ON;
    writel(ecc_mode,MB86HXX_NANDCFG_BASE+CFG_EccCheck);
    
}

/*
 * enable nand
 */
static inline void mb86h61_ctrl_nand_enable(void)
{
    writel(0x10, MB86HXX_NANDCFG_BASE+CFG_MODE);
}

/*
 * disable nand 
 */
static inline void mb86h61_ctrl_nand_disenable(void)
{
    writel(0x0, MB86HXX_NANDCFG_BASE+CFG_MODE);
}

static void mb86h61_ctrl_select_chip(struct mtd_info *mtd,int chip_nr)
{
    if(chip_nr == -1)
    {
        mb86h61_ctrl_nand_disenable();
    }
    else
    {
        mb86h61_ctrl_nand_enable(); 
    }
}

/*hardware specific access to control-lines
 *
 */
static void mb86h61_ctrl_nand_hwcontrol(struct mtd_info *mtd, int cmd,
           unsigned int ctrl)
{
    struct nand_chip *chip = mtd->priv;
    
    if(ctrl & NAND_CTRL_CHANGE)
    {
        if((ctrl & NAND_CTRL_CLE) == NAND_CTRL_CLE)
            chip->IO_ADDR_W = mb86h61_nand_base + NAND_CMD_OFFSET;
        else if((ctrl & NAND_CTRL_ALE) == NAND_CTRL_ALE)
            chip->IO_ADDR_W = mb86h61_nand_base + NAND_ADDR_OFFSET;
        else
            chip->IO_ADDR_W = mb86h61_nand_base + NAND_DATA_OFFSET;
    }

    if (cmd != NAND_CMD_NONE)
        writeb(cmd, chip->IO_ADDR_W);
}


/* 
 * calculate the Hardware ECc
 */

static int mb86h61_ctrl_nand_calculate(struct mtd_info *mtd,
        const uint8_t *dat, uint8_t *ecc_code)
{
    uint32_t ecc_value;
    
    ecc_value = readl(MB86HXX_NANDCFG_BASE+CFG_EccGen);
    ecc_value &= ECCGEN_MASK;
    ecc_code[0] = ecc_value & 0xFF;
    ecc_code[1] = (ecc_value >> 8) & 0xFF;
    ecc_code[2] = (ecc_value >> 16) & 0xFF;
    ecc_code[3] = (ecc_value >> 24) & 0xFF;
    
    return 0;
}

/*
 * HW ECC Correction
 *
 * Detect and correct a 1 bit error for 512 bytes
 */
static int mb86h61_ctrl_nand_correct(struct mtd_info *mtd, uint8_t *dat,
                uint8_t *read_ecc, uint8_t *isnull)
{
    uint32_t ecc_code;
    uint32_t ecc_status;
    uint32_t ecc_byte, ecc_bit;
    
    ecc_code = read_ecc[0];
    ecc_code |= read_ecc[1] << 8;
    ecc_code |= read_ecc[2] << 16;
    ecc_code |= read_ecc[3] << 24;
    
    writel(ecc_code,MB86HXX_NANDCFG_BASE+CFG_EccChecked);

    ecc_status = readl(MB86HXX_NANDCFG_BASE+CFG_EccCheck);

    /* if there's no error */
    if(likely(!(ecc_status & ECCCHECK_ERR)))
        return 0;

    /* Uncorectable error */
    if(ecc_status & ECCCHECK_UCE)
    {
        printk("Mb86h61_ctrl_nand Uncorrectable error\n");
        return -EIO;
    }
    
    /* ECC itself error */
    if(ecc_status & ECCCHECK_EER)
    {
        printk("mb86h61_ctrl_nand : error on ECC code Nothing to correct\n");
        return 0;
    }
    
    ecc_byte = (ecc_status & ECCCHECK_EADR_MASK) >> ECCCHECK_EADR_OFFSET;
    ecc_bit = (ecc_status & ECCCHECK_EBIT_MASK) & 0x7;
    
    dat[ecc_byte] ^= (1 << ecc_bit);

    printk("mb86h61_ctrl_nand : error corrected\n");
    return 1;
}

/*
 * Enable HW ECC
 */
static void mb86h61_ctrl_nand_hwctl(struct mtd_info *mtd, int mode)
{
    switch (mode) 
    {
        case NAND_ECC_READ:
        case NAND_ECC_WRITE:
            mb86h61_ctrl_nand_enableecc();
        break;
        case NAND_ECC_READSYN:
             default:
        mb86h61_ctrl_nand_disecc();
        break;
    }
}

/**
 * mb86h61_nand_read_page
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 *
 * The hw generator calculates the error syndrome automatically. Therefor
 * we need a special oob layout and handling.
 */
static int mb86h61_nand_read_page(struct mtd_info *mtd, struct nand_chip *chip, uint8_t *buf)
{
    int i, eccsize = chip->ecc.size;
    int eccbytes = chip->ecc.bytes;
    int eccsteps = chip->ecc.steps;
    uint8_t *p = buf;
    uint32_t  data_col_addr = 0;
    uint32_t *eccpos = chip->ecc.layout->eccpos;
    uint8_t *oob = chip->oob_poi + eccpos[0]; 

    for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
    int stat;

        if( data_col_addr != 0)
            chip->cmdfunc(mtd, NAND_CMD_RNDOUT, data_col_addr, -1);
                  
    chip->ecc.hwctl(mtd, NAND_ECC_READ);
    chip->read_buf(mtd, p, eccsize);

    chip->ecc.hwctl(mtd, NAND_ECC_READSYN);

        /* read ecc bytes */
        chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize + eccpos[i] , -1);
    chip->read_buf(mtd, oob, eccbytes);
    stat = chip->ecc.correct(mtd, p, oob, NULL);

    if (stat < 0)
        mtd->ecc_stats.failed++;
    else
        mtd->ecc_stats.corrected += stat;

    oob += eccbytes;
    data_col_addr += eccsize;
    }

   /* Calculate remaining oob bytes */
    i = mtd->oobsize - i;
   if (i)
    {   
        if(eccpos[0])
        { 
            oob = chip->oob_poi;
            chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize, -1);
            chip->read_buf(mtd, oob, eccpos[0]);
            i = i - eccpos[0];
        }
        if(i)
        {
            oob = chip->oob_poi + eccpos[chip->ecc.layout->eccbytes - 1] + 1;
            chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize + eccpos[chip->ecc.layout->eccbytes - 1] + 1 , -1);
       chip->read_buf(mtd, oob, i);
        } 
    }
    return 0;
}

/**
 * mb86h61_nand_read_page_raw
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 *
 * We need a special oob layout and handling even when OOB isn't used.
 */
static int mb86h61_nand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
              uint8_t *buf)
{
    chip->read_buf(mtd, buf, mtd->writesize);
    chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
    return 0;
}

/**
 * mb86h61_nand_write_page
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 *
 * The hw generator calculates the error syndrome automatically. Therefor
 * we need a special oob layout and handling.
 */
static void mb86h61_nand_write_page(struct mtd_info *mtd,
            struct nand_chip *chip, const uint8_t *buf)
{
    int i, eccsize = chip->ecc.size;
    int eccbytes = chip->ecc.bytes;
    int eccsteps = chip->ecc.steps;
    const uint8_t *p = buf;
    uint32_t *eccpos = chip->ecc.layout->eccpos;
    uint8_t *oob = chip->oob_poi + eccpos[0];


    for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
    
    chip->ecc.hwctl(mtd, NAND_ECC_WRITE); /* enable the ecc */
    chip->write_buf(mtd, p, eccsize);

    chip->ecc.hwctl(mtd, NAND_ECC_READSYN); /* disable the ecc */
    chip->ecc.calculate(mtd, p, oob);
    oob += eccbytes;
    }

    /* oob bytes */
    i = mtd->oobsize;
    oob = chip->oob_poi; 
        chip->write_buf(mtd, oob, i);
}

/**
 * mb86h61_nand_write_page_raw
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 *
 * We need a special oob layout and handling even when ECC isn't checked.
 */
static void mb86h61_nand_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
          const uint8_t *buf)
{
    chip->write_buf(mtd, buf, mtd->writesize);
    chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
}

/**
 * mb86h61_ctrl_read_oob_std
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @page:	page number to read
 * @sndcmd:	flag whether to issue read command or not
 */
static int mb86h61_ctrl_read_oob_std(struct mtd_info *mtd, struct nand_chip *chip,
			     int page, int sndcmd)
{
	if (sndcmd) {
		chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
		sndcmd = 0;
	}
	chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
	return sndcmd;
}

/**
 * mb86h61_ctrl_read_oob_syndrome
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @page:	page number to read
 * @sndcmd:	flag whether to issue read command or not
 */
static int mb86h61_ctrl_read_oob_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
				  int page, int sndcmd)
{
	uint8_t *buf = chip->oob_poi;
	int length = mtd->oobsize;
	int chunk = chip->ecc.bytes + chip->ecc.prepad + chip->ecc.postpad;
	int eccsize = chip->ecc.size;
	uint8_t *bufpoi = buf;
	int i, toread, sndrnd = 0, pos;

	chip->cmdfunc(mtd, NAND_CMD_READ0, chip->ecc.size, page);
	for (i = 0; i < chip->ecc.steps; i++) {
		if (sndrnd) {
			pos = eccsize + i * (eccsize + chunk);
			if (mtd->writesize > 512)
				chip->cmdfunc(mtd, NAND_CMD_RNDOUT, pos, -1);
			else
				chip->cmdfunc(mtd, NAND_CMD_READ0, pos, page);
		} else
			sndrnd = 1;
		toread = min_t(int, length, chunk);
		chip->read_buf(mtd, bufpoi, toread);
		bufpoi += toread;
		length -= toread;
	}
	if (length > 0)
		chip->read_buf(mtd, bufpoi, length);

	return 1;
}

/* 
  * gpio31~gpio0      MB86HXX_GPIO_BASE + 0x504
  * gpio_63~gpio32   MB86HXX_GPIO_BASE + 0x508 
  * gpio_95~gpio64   MB86HXX_GPIO_BASE + 0x50c
  */

static int mb86hxx_nand_device_ready(struct mtd_info *mtdinfo)
{
	unsigned int gpio;

	gpio = *((volatile unsigned int*)(MB86HXX_GPIO_BASE+0x50c));
	return (gpio>>16)&0x1; //gpio80
	
	//gpio = *((volatile unsigned int*)(MB86HXX_GPIO_BASE+0x504));
	//return (gpio>>8)&0x1; //gpio8
}

/*
 * Main initialization routine
 */
int board_nand_init(struct nand_chip *nand)
{
	mb86h61_ctrl_nand_init();
	mb86h61_nand_base = (void __iomem *)MB86HXX_NAND_BASE;
	/* Set address of NAND IO lines */
	nand->IO_ADDR_R = mb86h61_nand_base + NAND_DATA_OFFSET;
	nand->IO_ADDR_W = mb86h61_nand_base + NAND_DATA_OFFSET;
	//nand->select_chip = mb86h61_ctrl_select_chip;
	nand->dev_ready = NULL;//mb86hxx_nand_device_ready;
	nand->cmd_ctrl = mb86h61_ctrl_nand_hwcontrol;
	/* 50 us command delay time */
	nand->chip_delay = 50;
	/* Enable the following for a flash based bad block table */
	nand->options = NAND_USE_FLASH_BBT;
	nand->ecc.mode = NAND_ECC_HW_SYNDROME;
	nand->ecc.size = 512;
	nand->ecc.bytes = 4;
	nand->ecc.hwctl  = (void *)mb86h61_ctrl_nand_hwctl;
	nand->ecc.calculate = (void *)mb86h61_ctrl_nand_calculate;
	nand->ecc.correct  = (void *)mb86h61_ctrl_nand_correct;
	nand->ecc.write_page = mb86h61_nand_write_page;
	nand->ecc.write_page_raw = mb86h61_nand_write_page_raw;
	nand->ecc.read_page = mb86h61_nand_read_page;
	nand->ecc.read_page_raw = mb86h61_nand_read_page_raw;

	//nand->ecc.read_oob = mb86h61_ctrl_read_oob_syndrome;
	nand->ecc.read_oob = mb86h61_ctrl_read_oob_std;
#ifdef CONFIG_NAND_MB86HXX_CTRL 
	writel(0x0, MB86HXX_NAND_BASE + 0x3000);	
#endif
	return 0;
}

#if 0
module_init(mb86h61_nand_init);

/*
 * Clean up routine
 */
static void __exit mb86h61_nand_cleanup(void)
{
    /* Release resources, unregister device */
    nand_release(mb86h61_mtd);

    /* Free the MTD device structure */
    kfree(mb86h61_mtd);
}

module_exit(mb86h61_nand_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Fujitsu Semiconductor ShangHai");
MODULE_DESCRIPTION("Glue layer for MB86H61 Nand Controller MTD device");
#endif
