/*
 * (C) Copyright 2010
 * Fujitsu Semiconductor Limited
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/mb86hxx.h>
#include <asm/io.h>
#include <spi_flash.h>

typedef unsigned short FLASH_PORT_WIDTH;
typedef volatile unsigned short FLASH_PORT_WIDTHV;

#define FPW	    FLASH_PORT_WIDTH
#define FPWV	FLASH_PORT_WIDTHV

flash_info_t	flash_info[CONFIG_SYS_MAX_FLASH_BANKS]; /* info for FLASH chips */

/*-----------------------------------------------------------------------
 * Functions
 */
static ulong flash_get_size(FPWV *addr, flash_info_t *info);
static void flash_reset(flash_info_t *info);
flash_info_t *flash_get_info(ulong base);

/*-----------------------------------------------------------------------
 * flash_init()
 *
 * sets up flash_info and returns size of FLASH (bytes)
 */
/*
	GPIO    name     func
	GPIO_43	SDIN_SF  2
	GPIO_44	HOLD_SF  49
	GPIO_45	CS_SF    50
	GPIO_46	CLK_SF   51
	GPIO_47	SDO_SF   52
*/
unsigned long flash_init (void)
{
	printf("Configure serial flash Gpio.\n");
	writel(43+2,  MB86HXX_GPIO_BASE+0x200+4*2);					/*configure GPIO 43 as SDIN_SF*/
	writel(49, MB86HXX_GPIO_BASE+4*44	); 					/*configure GPIO 44 as HOLD_SF*/
	writel(50, MB86HXX_GPIO_BASE+4*45	); 					/*configure GPIO 45 as CS_SF*/
	writel(51, MB86HXX_GPIO_BASE+4*46	); 					/*configure GPIO 46 as CLK_SF*/
	writel(52, MB86HXX_GPIO_BASE+4*47	); 					/*configure GPIO 47 as SDO_SF*/

	return (unsigned long)PHYS_FLASH_SIZE;

}

/*-----------------------------------------------------------------------
 */
static void flash_reset(flash_info_t *info)
{
	printf("flash_reset()\n");
}

/*-----------------------------------------------------------------------
 */

flash_info_t *flash_get_info(ulong base)
{
	printf("flash_get_info()\n");
	return NULL;
}

/*-----------------------------------------------------------------------
 */

void flash_print_info (flash_info_t *info)
{
	printf ("flash_print_info()\n");
}

/*-----------------------------------------------------------------------
 */

/*
 * The following code cannot be run from FLASH!
 */

ulong flash_get_size (FPWV *addr, flash_info_t *info)
{
	printf ("flash_get_size()\n");
	return -1;
}

/*-----------------------------------------------------------------------
 */

int	flash_erase (flash_info_t *info, int s_first, int s_last)
{
	printf (" flash_erase\n");
	return -1;
}

/*-----------------------------------------------------------------------
 * Copy memory to flash, returns:
 * 0 - OK
 * 1 - write timeout
 * 2 - Flash not erased
 */
int write_buff (flash_info_t *info, uchar *src, ulong addr, ulong cnt)
{
	printf ("write_buff\n");
	return -1;
}

