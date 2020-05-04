/*
 * (C) Copyright 2010
 * Goke Micro Limited
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
#include <asm/io.h>
#include <spi_flash.h>
#include <gk7101_sflash.h>

typedef unsigned short FLASH_PORT_WIDTH;
typedef volatile unsigned short FLASH_PORT_WIDTHV;

#define FPW	    FLASH_PORT_WIDTH
#define FPWV	FLASH_PORT_WIDTHV

flash_info_t	flash_info[CONFIG_SYS_MAX_FLASH_BANKS]; /* info for FLASH chips */

/*-----------------------------------------------------------------------
 * Functions
 */
//static ulong flash_get_size(FPWV *addr, flash_info_t *info);
//static void  flash_reset(flash_info_t *info);
//flash_info_t *flash_get_info(ulong base);

/*-----------------------------------------------------------------------
 * flash_init()
 *
 * sets up flash_info and returns size of FLASH (bytes)
 */
unsigned long flash_init (void)
{	
	unsigned long size;
    int id = FLASH_UNKNOWN;
    int i = 0;
    flash_info_t *info;
	const goke_sflash_dev_s *device;
	
    info = &flash_info[0];
	device = goke_sflash_init();
	if (device == NULL)
	{
		return (GOKE_ERR_SFLASH_TYPE_NOT_SUPPORTED);
	}
	size = (unsigned long)(device->device_bytes);
    info->size = size;
    info->sector_count = device->sector_count;
    switch(device->manufacture_ID)
    {
        case 0xC2:
                id = (FLASH_MAN_MX & FLASH_VENDMASK)
                            | (device->device_ID & FLASH_TYPEMASK);
                break;
        default:
                break;
    }
    info->flash_id = id;
    for(i=0; i<device->sector_count; i++)
    {
        info->start[i] = i * (device->sector_bytes);
    }
	return size;
}

#if 0
/*-----------------------------------------------------------------------
 */

static void flash_reset(flash_info_t *info)
{
	printf("flash_reset()\n");
}
#endif

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
    int size;
    int ret = 0;
    struct spi_flash *flash;
    size = s_last - s_first;
//    flash = goke_spi_flash_probe(0,0,0,0);
    flash = spi_flash_probe(0,0,0,0);
    if(NULL == flash)
        return -1;
    ret = flash->erase(flash, s_first, size);
//    goke_spi_flash_free(flash);
    spi_flash_free(flash);
	printf (" flash_erase\n");
	return ret;
}

/*-----------------------------------------------------------------------
 * Copy memory to flash, returns:
 * 0 - OK
 * 1 - write timeout
 * 2 - Flash not erased
 */
int write_buff (flash_info_t *info, uchar *src, ulong addr, ulong cnt)
{
    int ret = 0;
    struct spi_flash *flash;
//    flash = goke_spi_flash_probe(0,0,0,0);
    flash = spi_flash_probe(0,0,0,0);
    if(NULL == flash)
        return -1;
    ret = flash->write(flash, addr, cnt, src);
//    goke_spi_flash_free(flash);
    spi_flash_free(flash);
	printf ("write_buff\n");
	return ret;
}

