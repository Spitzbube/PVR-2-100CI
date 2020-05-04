/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2008
 * Guennadi Liakhovetki, DENX Software Engineering, <lg@denx.de>
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

#include <common.h>
#include <asm/arch/gk6202.h>


#define iowrite32(val, addr) (*(volatile unsigned int *)(addr) = (val))
#define ioread32(addr) (*(volatile unsigned int *)(addr))

DECLARE_GLOBAL_DATA_PTR;

static inline void delay(unsigned long loops)
{
	__asm__ volatile ("1:\n" "subs %0, %1, #1\n"
			  "bne 1b"
			  : "=r" (loops) : "0" (loops));
}

int console_init(void)
{
	return 0;
}

int board_early_init_f(void)
{
	*(volatile unsigned int *)0x300030 = 0x87650002;
#if 0	
	/*configure GPIO 16 as UART0_TXDATA*/
	iowrite32(8, GK6202_GPIO_BASE+ 7 * 0x4);

	/*configure GPIO 17 as UART0_RXDATA*/
	iowrite32(0x40, GK6202_GPIO_BASE+ 6 * 0x4);
	iowrite32((6+2), GK6202_GPIO_BASE + 0x100 + 3 * 0x4);
#endif
	*(volatile unsigned int *)0x300034 = 0x87650003;
	return 0;	
}

int board_init(void)
{
	/* arch number of GK6202-Board */
	gd->bd->bi_arch_number = MACH_TYPE_GOKE_TVSTBSOC;
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + CONFIG_RESERVED_MEMORY_SIZE + 0x100;
	gd->flags = 0;

	icache_enable ();
	
	return 0;
}

void dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1 + CONFIG_RESERVED_MEMORY_SIZE;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE  - CONFIG_RESERVED_MEMORY_SIZE;
}

int dram_init(void)
{
	gd->ram_size = get_ram_size((long *)(PHYS_SDRAM_1 + CONFIG_RESERVED_MEMORY_SIZE),
				PHYS_SDRAM_1_SIZE - CONFIG_RESERVED_MEMORY_SIZE);

	return 0;
}

#ifdef CONFIG_DRIVER_FMAC3H
int board_eth_init(bd_t *bis)
{
	return fmac3h_initialize(bis);
}
#endif


#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard(void)
{
    printf("Board:  GK6202_EVB\n");
    return 0;
}
#endif
