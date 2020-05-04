/*
 * (C) Copyright 2012-2013 Stephen Warren
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <netdev.h>
#include <asm/global_data.h>
#include <asm/arch-gk7101s/io.h>
#include <asm/arch-gk7101s/gpio.h>

#include "gk7101s_hal_data.h"

#define iowrite32(val, addr) (*(volatile unsigned int *)(addr) = (val))
#define ioread32(addr) (*(volatile unsigned int *)(addr))

DECLARE_GLOBAL_DATA_PTR;

static inline void delay(unsigned long loops)
{
	__asm__ volatile ("1:\n" "subs %0, %1, #1\n"
			  "bne 1b"
			  : "=r" (loops) : "0" (loops));
}

struct hw_ops *g_hw;

typedef void* (*hal_function_t) (unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);


static inline unsigned int gk_hal_init (int cp_flag)
{
	unsigned int rval=0;
    unsigned int *haladdress;

    haladdress = CONFIG_GK_HAL_ADDR;
    *(volatile u32 *) (CONFIG_U2K_HAL_ADDR) = haladdress;
    if(1 == cp_flag)
        memcpy(haladdress,hal_data,sizeof(hal_data));
	hal_function_t hal_init = (hal_function_t) (haladdress) ;
#if 1
	g_hw = (struct hw_ops *)hal_init (0, 0, 0x90000000, 0xA0000000, 0) ;
#else
    g_hw = &local_hw;
#endif
    return rval ;
}


void gk_hal_print(void)
{
    printf("HAL:  %x \n", g_hw->get_version());
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int board_early_init_f(void)
{
    gk_hal_init(1);

	return 0;
}
#endif

int gpio_init(void)
{

	gk_gpio_writel(REG_PLL_IOCTRL_MISC2,0x12);		//sflash hold pin, pull up

	gk710xs_gpio_initialize();
	return 0;
}

int phy_gpio_init(void)
{
    u32 usrMemory=0;
	gk710xs_phy_gpio_initialize();

    usrMemory = 0xC0000000 + gd->ram_size - CONFIG_USR_SDRAM_SIZE;
    gk710xs_save_gpio_cfg_to_usr_memory(usrMemory);

	return 0;
}

int board_init(void)
{
    /* After Relocate, we need init hal again*/
    gk_hal_init(0);

	/* arch number of GK7101-Board */
	gd->bd->bi_arch_number = MACH_TYPE_GOKE_TVSTBSOC;
	gd->bd->bi_boot_params = CONFIG_SYS_SDRAM_BASE + 0x100;
	gd->flags = 0;

	icache_enable ();

	return 0;
}

void dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE;
	gd->bd->bi_dram[0].size = gd->ram_size;;
}

int dram_init(void)
{
	u32  ddr = *(volatile u32 *) (0x90002004);
	u32  ram_size = 0x04000000;

	if(ddr == 0x00100354) ram_size = 0x08000000;

	gd->ram_size = get_ram_size((long *)(CONFIG_SYS_SDRAM_BASE),
				ram_size);

	return 0;
}

#ifdef CONFIG_DRIVER_GK7101ETH
int board_eth_init(bd_t *bis)
{
	return gk7101_eth_initialize(bis);
}
#endif

#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard(void)
{
    gk_hal_print();
    return 0;
}
#endif

#if defined(CONFIG_GENERIC_MMC)
int board_mmc_init(bd_t *bis)
{
	goke_mmc_init(0);
	return 0;
}
#endif

