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
#include <asm/arch/upi.h>

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

void upi_flash_init(void)
{
	unsigned long base = MB86H61_UPI0_CONFIG_BASE;

	/* initialize UPI */
	iowrite32(UPI_MODE_PARAM, base + MB86H61_UPI_MODE_OFFSET);
	iowrite32(UPI_TALS_PARAM, base + MB86H61_UPI_TALS_OFFSET);
	iowrite32(UPI_TALH_PARAM, base + MB86H61_UPI_TALH_OFFSET);
	iowrite32(UPI_TRS_PARAM, base + 	MB86H61_UPI_TRS_OFFSET);
	iowrite32(UPI_TRDS_PARAM, base + MB86H61_UPI_TRDS_OFFSET);
	iowrite32(UPI_TRDH_PARAM, base + MB86H61_UPI_TRDH_OFFSET);
	iowrite32(UPI_TRR_PARAM, base + 	MB86H61_UPI_TRR_OFFSET);
	iowrite32(UPI_TWS_PARAM, base + 	MB86H61_UPI_TWS_OFFSET);
	iowrite32(UPI_TWP_PARAM, base + 	MB86H61_UPI_TWP_OFFSET);
	iowrite32(UPI_TWR_PARAM, base + 		MB86H61_UPI_TWR_OFFSET);
	iowrite32(UPI_WMMASK_PARAM, base +	MB86H61_UPI_WMMASK_OFFSET);
	iowrite32(UPI_BUFEN_PARAM, base + 	MB86H61_UPI_BUFEN_OFFSET);

	iowrite32(UPI_ADDREXT_PARAM, 	MB86H61_UPI_ADDREXT);
	iowrite32(UPI_CSSEL_PARAM, 	MB86H61_UPI_CSSEL);
	iowrite32(UPI_CSMODE_PARAM, 	MB86H61_UPI_CSMODE);

	iowrite32(UPI_WAIT_TIME_PARAM, 			MB86H61_UPI_WAIT_TIME);
	iowrite32(UPI_WAIT_TIME_EN_PARAM, 		MB86H61_UPI_WAIT_TIME_EN);
	iowrite32(UPI_LAST_WAIT_TIME_PARAM, 	MB86H61_UPI_LAST_WAIT_TIME);
	iowrite32(UPI_WAIT_TIME_STATUS_PARAM, 	MB86H61_UPI_WAIT_TIME_STATUS);
}

int board_init(void)
{

	gd->bd->bi_arch_number = MACH_TYPE;
	/* should be MACH_TYPE_XXX in mach-types.h */
	gd->bd->bi_boot_params = load_addr -0x8000 + 0x100;//_armboot_start - CONFIG_SYS_MALLOC_LEN - sizeof(gd_t) - 4096;//PHYS_SDRAM_1 + 0x100;
	//gd = (gd_t*)(_armboot_start - CONFIG_SYS_MALLOC_LEN - sizeof(gd_t));
	gd->flags = 0;

	icache_enable ();

//	upi_flash_init ();

	/*gpio configure for uart0*/
	iowrite32(23, MB86HXX_GPIO_BASE+4*3	); 						/*configure GPIO 3 as UART0_TXDATA*/
	iowrite32(2+2, MB86HXX_GPIO_BASE+0x200+4*21 );			/*configure GPIO 2 as UART0_RXDATA*/

	return 0;
}

int dram_init(void)
{
	gd->bd->bi_dram[0].start = 0x22a00000;
	gd->bd->bi_dram[0].size = 0x08000000-0x02a00000;

	return 0;
}

#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard(void)
{
    printf("Board:   MB86H61 DEVKIT\n");
    return 0;
}
#endif
