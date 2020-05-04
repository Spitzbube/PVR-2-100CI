/*
 * drivers\mtd\spi\gk7101_sflash.c
 *
 * Copyright: 2012 - 2013 (C) GoKe Microelectronics LIMITED
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <common.h>
#include <malloc.h>
#include <spi.h>
#include <spi_flash.h>

#include <gk7101_sflash.h>


#define GK_UBOOT_HEADER_MAGIC      0x474b3731
#define BIG_LITTLE_SWITCH(X)    ((((u32)(X) & 0xff000000) >> 24) | \
                                (((u32)(X) & 0x00ff0000) >> 8) | \
                                (((u32)(X) & 0x0000ff00) << 8) | \
                                (((u32)(X) & 0x000000ff) << 24))
/*-------------------------------------------------------------------------------*/
/* serial flash specific commands for Spansion flash devices                                            */
/*-------------------------------------------------------------------------------*/
static const goke_sflash_cmd_s sflash_commands_mx =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0xbb,
    /*  read_io4        */ 0xeb,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x38,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};
static const goke_sflash_cmd_s sflash_commands_spansion =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0xbb,
    /*  read_io4        */ 0xeb,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x32,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0x35,
};

/*-------------------------------------------------------------------------------*/
/* serial flash specific commands for STmicro flash devices                      */
/*-------------------------------------------------------------------------------*/
static const goke_sflash_cmd_s sflash_commands_stmicro =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0x00,
    /*  read_io4        */ 0x00,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x00,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};

/*-------------------------------------------------------------------------------*/
/* serial flash specific commands for Atmel flash devices                        */
/*-------------------------------------------------------------------------------*/
static const goke_sflash_cmd_s sflash_commands_atmel =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0x00,
    /*  read_io4        */ 0x00,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x00,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};

/*-------------------------------------------------------------------------------*/
/* serial flash specific commands for NUMONYX flash devices                      */
/*-------------------------------------------------------------------------------*/
static const goke_sflash_cmd_s sflash_commands_numonyx =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0xbb,
    /*  read_io4        */ 0xeb,
    /*  program_page2   */ 0xd2,
    /*  program_page4   */ 0x12,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};

static const goke_sflash_cmd_s sflash_commands_wb =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0xbb,
    /*  read_io4        */ 0xeb,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x32,
    /* read_ext_addr    */ 0xC8,
    /* write_ext_addr   */ 0xC5,
    /* read_status2     */ 0x35,
};

static const goke_sflash_cmd_s  sflash_command_sst =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0x20,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x80,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0x00,
    /*  read_io4        */ 0x0B,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x32,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};
static const goke_sflash_cmd_s sflash_commands_gd =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0xbb,
    /*  read_io4        */ 0xeb,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x32,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0x35,
};
static const goke_sflash_cmd_s sflash_commands_eon =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0x00,
    /*  read_io4        */ 0x0b,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x02,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};

static const goke_sflash_cmd_s sflash_commands_issi =
{
    /* read_ID          */ 0x9F,
    /* write_enable     */ 0x06,
    /* write_disable    */ 0x04,
    /* read_status      */ 0x05,
    /* write_status     */ 0x01,
    /* read_data        */ 0x03,
    /* read_data_fast   */ 0x0B,
    /* erase_sector     */ 0xD8,
    /* erase_chip       */ 0xC7,
    /* program_page     */ 0x02,
    /* status_mask_wip  */ 0x01,
    /* status_mask_wel  */ 0x02,
    /*  read_io2        */ 0xbb,
    /*  read_io4        */ 0xeb,
    /*  program_page2   */ 0x00,
    /*  program_page4   */ 0x38,
    /* read_ext_addr    */ 0xFF,
    /* write_ext_addr   */ 0xFF,
    /* read_status2     */ 0xFF,
};
/*-------------------------------------------------------------------------------*/
/* serial flash geometry and information data of all supported devices           */
/*-------------------------------------------------------------------------------*/
static goke_sflash_dev_s sflash_devices_supported[] =
{

   /*
    ** Spansion seem to use unique sectors
    ** with 64kBytes each, they increment the
    ** number of sectors for bigger chips
    */
    {
        /* manufacture_ID   */ 0x01,
        /* device_ID        */ 0x0212,
        /* manufacture_name */ "Spansion",
        /* device_name      */ "S25FL004A",
        /* device_bytes     */ 524288,
        /* sector_count     */ 8,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_spansion,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x9CF5,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x01,
        /* device_ID        */ 0x0213,
        /* manufacture_name */ "Spansion",
        /* device_name      */ "S25FL008A",
        /* device_bytes     */ 1048576,
        /* sector_count     */ 16,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_spansion,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x9CF5,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x01,
        /* device_ID        */ 0x0214,
        /* manufacture_name */ "Spansion",
        /* device_name      */ "S25FL016A",
        /* device_bytes     */ 2097152,
        /* sector_count     */ 32,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_spansion,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x9CF5,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x01,
        /* device_ID        */ 0x0215,
        /* manufacture_name */ "Spansion",
        /* device_name      */ "S25FL032P",
        /* device_bytes     */ 4194304,
        /* sector_count     */ 64,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_spansion,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x9CF5,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x01,
        /* device_ID        */ 0x0216,
        /* manufacture_name */ "Spansion",
        /* device_name      */ "S25FL064A",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_spansion,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x9CF5,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x01,
        /* device_ID        */ 0x2018,
        /* manufacture_name */ "Spansion",
        /* device_name      */ "FL128PIFL",
        /* device_bytes     */ 16777216,
        /* sector_count     */ 256,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_spansion,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x9CF5,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },

    /*
    ** MX seem to use unique sectors
    ** with 64kBytes each, they increment the
    ** number of sectors for bigger chips
    */
    /* gk6105 8M SFlash */
    {
        /* manufacture_ID   */ 0xc2,
        /* device_ID        */ 0x2617,
        /* manufacture_name */ "MX",
        /* device_name      */ "MX25L6455E",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_mx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufactureID    */ 0xc2,
        /* deviceID         */ 0x2017,
        /* manufactureName  */ "MX",
        /* deviceName       */ "MX25L6465E",
        /* deviceBytes      */ 8388608,
        /* sectorCount      */ 128,
        /* sectorBytes      */ 65536,
        /* sectorPages      */ 256,
        /* pageBytes        */ 256,
        /* commands         */ &sflash_commands_mx,
        /* ioMode           */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xc2,
        /* device_ID        */ 0x2018,
        /* manufacture_name */ "MX",
        /* device_name      */ "MX25L12845",
        /* device_bytes     */ 16777216,
        /* sector_count     */ 256,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_mx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xc2,
        /* device_ID        */ 0x5e16,
        /* manufacture_name */ "MX",
        /* device_name      */ "MX253235D",
        /* device_bytes     */ 4194304,
        /* sector_count     */ 64,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_mx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xc2,
        /* device_ID        */ 0x2415,
        /* manufacture_name */ "MX",
        /* device_name      */ "MX25L1605D",
        /* device_bytes     */ 2097152,
        /* sector_count     */ 32,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_mx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xc2,
        /* device_ID        */ 0x2415,
        /* manufacture_name */ "MX",
        /* device_name      */ "MX25L1635D",
        /* device_bytes     */ 2097152,
        /* sector_count     */ 32,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_mx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xc2,
        /* device_ID        */ 0x9e16,
        /* manufacture_name */ "MX",
        /* device_name      */ "MX25L3255D",
        /* device_bytes     */ 4194304,
        /* sector_count     */ 64,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_mx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x00BC,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xef,
        /* device_ID        */ 0x4015,
        /* manufacture_name */ "Winbond",
        /* device_name      */ "W25Q16BV",
        /* device_bytes     */ 2097152,
        /* sector_count     */ 32,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_wb,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x1C00,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xef,
        /* device_ID        */ 0x4017,
        /* manufacture_name */ "Winbond",
        /* device_name      */ "W25Q64FV",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_wb,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x1C00,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufactureID    */ 0xef,
        /* deviceID         */ 0x4018,
        /* manufactureName  */ "Winbond",
        /* deviceName       */ "W25Q128FV",
        /* deviceBytes      */ 16777216,
        /* sectorCount      */ 256,
        /* sectorBytes      */ 65536,
        /* sectorPages      */ 256,
        /* pageBytes        */ 256,
        /* commands         */ &sflash_commands_wb,
        /* ioMode           */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x1C00,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufactureID    */ 0xef,
        /* deviceID         */ 0x4019,
        /* manufactureName  */ "Winbond",
        /* deviceName       */ "W25Q256FV",
        /* deviceBytes      */ (1024*1024*32),
        /* sectorCount      */ 512,
        /* sectorBytes      */ 65536,
        /* sectorPages      */ 256,
        /* pageBytes        */ 256,
        /* commands         */ &sflash_commands_wb,
        /* ioMode           */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x3C00,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xbf,
        /* device_ID        */ 0x2601,
        /* manufacture_name */ "SST",
        /* device_name      */ "SST26VF016",
        /* device_bytes     */ 2097152,
        /* sector_count     */ 512,
        /* sector_bytes     */ 4096,
        /* sector_pages     */ 16,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_command_sst,
        /* iomode           */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0xFFFF,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x20,
        /* device_ID        */ 0xba18,
        /* manufacture_name */ "numonyx",
        /* device_name      */ "N25Q128",
        /* device_bytes     */ 8388608*2,
        /* sector_count     */ 256,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_numonyx,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0xFFFF,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xC8,
        /* device_ID        */ 0x4017,
        /* manufacture_name */ "giga",
        /* device_name      */ "GD25Q64C",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_gd,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0xFC79,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0xC8,
        /* device_ID        */ 0x4018,
        /* manufacture_name */ "giga",
        /* device_name      */ "GD25Q128C",
        /* device_bytes     */ 8388608*2,
        /* sector_count     */ 256,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_gd,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0xFC79,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x1c,
        /* device_ID        */ 0x3017,
        /* manufacture_name */ "EON",
        /* device_name      */ "EN25Q64",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_eon,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x003C,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x1C,
        /* device_ID        */ 0x7017,
        /* manufacture_name */ "EON",
        /* device_name      */ "ENQH64A",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_eon,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x003C,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x1c,
        /* device_ID        */ 0x7018,
        /* manufacture_name */ "EON",
        /* device_name      */ "EN25Q128",
        /* device_bytes     */ 8388608*2,
        /* sector_count     */ 256,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_eon,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0x003C,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x9D,
        /* device_ID        */ 0x6017,
        /* manufacture_name */ "ISSI",
        /* device_name      */ "IC25LP064",
        /* device_bytes     */ 8388608,
        /* sector_count     */ 128,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_issi,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0xFFFF,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    },
    {
        /* manufacture_ID   */ 0x9D,
        /* device_ID        */ 0x6018,
        /* manufacture_name */ "ISSI",
        /* device_name      */ "IC25LP128",
        /* device_bytes     */ 8388608*2,
        /* sector_count     */ 256,
        /* sector_bytes     */ 65536,
        /* sector_pages     */ 256,
        /* page_bytes       */ 256,
        /* commands         */ &sflash_commands_issi,
        /* feature          */ GD_SFLASH_1X_WRITE | GD_SFLASH_1X_READ,
        /* lock_mask        */ 0xFFFF,
        /* io4_mask         */ 0xFFFF,
        /* channel          */ 0x0,
    }
};


static goke_sflash_dev_s *goke_sflash_device[GOKE_SFLASH_CHANNEL_NUM] = {0};
static struct spi_flash *sflash_probe(struct spi_slave *spi, goke_sflash_dev_s *device);
static inline struct goke_spi_flash_t *to_spi_flash(struct spi_flash *flash);
static u32 sflash_cmd_bit_set(goke_sflash_command_s *sflashCmd, u32 *cmdBitSet);
static u32 check_magic_number(u32 offset, size_t len, const void *buf);
static void big_endian_to_little_endian(u32 offset, size_t len, void *buf);
static goke_sflash_feature_e old_feature = GOKE_SFLASH_FEATURE_IO1;
static u32 sflash_write_enable(goke_sflash_dev_s *device);

/*----------------------------------------------------------------------------*/
/* register SFLASH_CE (read/write)                                            */
/*----------------------------------------------------------------------------*/

__inline static void sflash_set_ce(u32 data)
{
    gk_sf_writel(REG_SFLASH_CE, data);
}

/*----------------------------------------------------------------------------*/
/* register SFLASH_Command (read/write)                                       */
/*----------------------------------------------------------------------------*/

__inline static void sflash_set_speed(u32 data)
{
    gk_sf_writel(REG_SFLASH_SPEED, data);
}

/*----------------------------------------------------------------------------*/
/* register SFLASH_Command (read/write)                                       */
/*----------------------------------------------------------------------------*/

__inline static void sflash_set_command(u32 data)
{
    gk_sf_writel(REG_SFLASH_COMMAND, data);
}

/*----------------------------------------------------------------------------*/
/* register SFLASH_Data (read/write)                                          */
/*----------------------------------------------------------------------------*/

__inline static void sflash_set_data(u32 data)
{
    gk_flash_write(data);
}

__inline static u32  sflash_get_data(void)
{
    return gk_flash_read();
}

static u32 sflash_wip_done_wait(goke_sflash_dev_s *device)
{
    u8 wip_mask;
    goke_sflash_command_s   sflash_cmd;
    u32 cmd_bit_set                                     = 0;

    cmd_bit_set |= (device->commands->read_status|
        SFLASH_SEND_CMD|                        /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|            /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|           /*dummy cycle*/
        SFLASH_RWN_READ|                        /*read data*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|          /*set the sflash adr mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)|          /*transfer data number*/
        SFLASH_HOLD_TIME_100ns
        );

    /* set the sflash cmd mode, set the sflash data mode */
    if(device->manufacture_ID == 0xbf)
    {
        cmd_bit_set |= (SFLASH_CMD_MODE_4X|SFLASH_DATA_CYCLE_NUM_2);
    }
    else
    {
        cmd_bit_set |= (SFLASH_CMD_MODE_1X|SFLASH_DATA_CYCLE_NUM_0);
    }

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);

    wip_mask = device->commands->status_mask_wip;
    while(1)
    {
        sflash_set_command(sflash_cmd.all);

        if((sflash_get_data() & wip_mask) != wip_mask) /*flash device ready*/
        {
            return(0);
        }
    }
    return 1;
}

static u32 sflash_wel_done_wait(goke_sflash_dev_s *device)
{
    u8 wel_mask;
    goke_sflash_command_s   sflash_cmd;
    u32 cmd_bit_set                                     = 0;

    cmd_bit_set |= (device->commands->read_status|
        SFLASH_SEND_CMD|                        /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|            /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|           /*dummy cycle*/
        SFLASH_RWN_READ|                        /*read data*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|          /*set the sflash adr mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)|          /*transfer data number*/
        SFLASH_HOLD_TIME_100ns
        );

    /* set the sflash cmd mode, set the sflash data mode */
    if(device->manufacture_ID == 0xbf)
    {
        cmd_bit_set |= (SFLASH_CMD_MODE_4X|SFLASH_DATA_CYCLE_NUM_2);
    }
    else
    {
        cmd_bit_set |= (SFLASH_CMD_MODE_1X|SFLASH_DATA_CYCLE_NUM_0);
    }

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);

    wel_mask = device->commands->status_mask_wel;
    while(1)
    {
        sflash_set_command(sflash_cmd.all);

        if((sflash_get_data() & wel_mask) == wel_mask) /*flash enable ready*/
        {
            return(0);
        }
    }
    return 1;
}

/*!
********************************************************************************
**
** \brief unlock the serial flash
**
** This function unlock the serial flash.
**
** \return
** - GD_ERR_INVALID_HANDLE if the given handle parameter points to 0
** - GD_OK if unlock operation successfully
**
********************************************************************************
*/
static u32 sflash_Unlock(goke_sflash_dev_s *device)
{
    goke_sflash_command_s   sflash_cmd;
    u32 cmd_bit_set                                     = 0;
    u8 status;
    u16 sflashData;
    ulong CESetting = 0x38;

    CESetting = CESetting | ((ulong)device->channel << 6);
    sflash_set_ce(CESetting);

    /* write enable the device */
    sflash_write_enable(device);

    cmd_bit_set = (device->commands->read_status |   // command
                   SFLASH_SEND_CMD               |   // transfer the command
                   SFLASH_SEND_ADDR_BYTE_NUM_0   |   // address num
                   SFLASH_SEND_DUMMY_BYTE_NUM_0  |   // dummy cycle
                   SFLASH_RWN_READ               |   // read data
                   SFLASH_CMD_MODE_1X            |   // set the sflash cmd mode
                   SFLASH_ADDR_DUMMY_CYCLE_NUM_0 |   // set the sflash adr mode
                   SFLASH_DATA_CYCLE_NUM_0       |   // set the sflash data mode
                   (1<<SFLASH_TRANSFER_BYTE_LOC)     // transfer data number
                  );
    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);

    sflash_set_command(sflash_cmd.all);
    status = sflash_get_data()& 0xff;
    sflashData = status;

    if(device->commands->read_status2 != 0xFF)
    {
        cmd_bit_set = (device->commands->read_status2|   // command
                       SFLASH_SEND_CMD               |   // transfer the command
                       SFLASH_SEND_ADDR_BYTE_NUM_0   |   // address num
                       SFLASH_SEND_DUMMY_BYTE_NUM_0  |   // dummy cycle
                       SFLASH_RWN_READ               |   // read data
                       SFLASH_CMD_MODE_1X            |   // set the sflash cmd mode
                       SFLASH_ADDR_DUMMY_CYCLE_NUM_0 |   // set the sflash adr mode
                       SFLASH_DATA_CYCLE_NUM_0       |   // set the sflash data mode
                       (1<<SFLASH_TRANSFER_BYTE_LOC)     // transfer data number
                      );
        sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
        sflash_set_command(sflash_cmd.all);
        status = sflash_get_data()& 0xff;
        sflashData = (sflashData << 8) + status;
    }

    sflash_write_enable(device);
    cmd_bit_set = (device->commands->write_status|   // command
                   SFLASH_SEND_CMD               |   // transfer the command
                   SFLASH_SEND_ADDR_BYTE_NUM_0   |   // address num
                   SFLASH_SEND_DUMMY_BYTE_NUM_0  |   // dummy cycle
                   SFLASH_RWN_WRITE              |   // write data
                   SFLASH_CMD_MODE_1X            |   // set the sflash cmd mode
                   SFLASH_ADDR_DUMMY_CYCLE_NUM_0 |   // set the sflash adr mode
                   SFLASH_DATA_CYCLE_NUM_0       |   // set the sflash data mode
                   (1<<SFLASH_TRANSFER_BYTE_LOC)     // transfer data number
                  );

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    if(device->commands->read_status2 != 0xFF)
    {
        sflash_cmd.bitc.data_num = 0x2;               // transfer data
    }
    sflashData &= ~(device->lock_mask);
    if(device->manufacture_ID == 0x01)
    {
        sflashData |= 0x0024;
    }

    sflash_set_command(sflash_cmd.all);
    sflash_set_data(sflashData);

    sflash_wip_done_wait(device);
    CESetting = CESetting & (~((ulong)device->channel << 6));
    sflash_set_ce(CESetting);
    return(0);
}

const goke_sflash_dev_s *goke_sflash_init(void)
{
    u32 sflash_data;
    u8  manufacture_ID;
    u16 device_ID;
    u32 index;
    u32 count;
    u32 cmd_bit_set                                = 0;
    u8  command,status;
    u32 prot1;
    u32 prot2;
    goke_sflash_dev_s *frist_device          = NULL;
    goke_sflash_dev_s *device;
    goke_sflash_command_s   sflash_cmd;
    u32 ce_setting                           = 0x0E;
    goke_sflash_speed_mode speed_mode        = GOKE_SFLASH_FREQ_DIV2;
    goke_sflash_channel_e  channel           = GOKE_SFLASH_CHANNEL_0;
	int i;

	for(i=0;i<GOKE_SFLASH_CHANNEL_NUM;i++)
	{
		channel = i;
	    ce_setting = 0x0E | ((u32)channel  << 6);

	    sflash_set_ce(ce_setting);
	    sflash_set_speed(speed_mode); /*0 -- 1/2freq 1--1/4freq  2....4*/

	    count = sizeof(sflash_devices_supported)/sizeof(goke_sflash_dev_s);

	    for(index=0; index < count; index++)
	    {
	        device = &(sflash_devices_supported[index]);

	        command = device->commands->read_ID;

	        sflash_set_ce(ce_setting);
	        cmd_bit_set |= (SFLASH_SEND_CMD|                    /*transfer the command*/
	            SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
	            SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
	            SFLASH_RWN_READ|                                /*read data*/
	            SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
	            SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
	            SFLASH_DATA_CYCLE_NUM_0|                        /*set the sflash data mode*/
	            (3<<SFLASH_TRANSFER_BYTE_LOC)                   /*transfer data number*/
	            );

	        cmd_bit_set |= command;
	        sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
	        sflash_set_command(sflash_cmd.all);
	        sflash_data = sflash_get_data();

	        manufacture_ID = (u8)((sflash_data & 0x00ff0000) >> 16);
	        device_ID = (u16)(sflash_data & 0x0000FFFF);

	        if((manufacture_ID == device->manufacture_ID)
	        && (device_ID == device->device_ID))
	        {


	            if(manufacture_ID == 0xbf)                      /*SST sflash which support most quad IO cmd*/
	            {
	                cmd_bit_set |= (0x38|                       /*enable quad command*/
	                    SFLASH_SEND_CMD|                        /*transfer the command*/
	                    SFLASH_SEND_ADDR_BYTE_NUM_0|            /*address num*/
	                    SFLASH_SEND_DUMMY_BYTE_NUM_0|           /* dummy cycle*/
	                    SFLASH_RWN_NOTHING|                     /*no read/write*/
	                    SFLASH_CMD_MODE_1X|                     /*set command mode*/
	                    SFLASH_ADDR_DUMMY_CYCLE_NUM_0|          /*set the sflash adr mode*/
	                    SFLASH_DATA_CYCLE_NUM_0|                /*set the sflash data mode*/
	                    (0<<SFLASH_TRANSFER_BYTE_LOC)           /*transfer data number*/
	                    );

	                sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
	                sflash_set_command( sflash_cmd.all );
	                sflash_get_data();

	                cmd_bit_set |= (0xaf|                       /*enable quad command*/
	                     SFLASH_SEND_CMD|                       /*transfer the command*/
	                     SFLASH_SEND_ADDR_BYTE_NUM_0|           /*address num*/
	                     SFLASH_SEND_DUMMY_BYTE_NUM_0|          /*dummy cycle*/
	                     SFLASH_RWN_READ|                       /*read*/
	                     SFLASH_CMD_MODE_4X|                    /*set command mode*/
	                     SFLASH_ADDR_DUMMY_CYCLE_NUM_0|         /*set the sflash adr mode*/
	                     SFLASH_DATA_CYCLE_NUM_2|               /*set the sflash data mode*/
	                     (3<<SFLASH_TRANSFER_BYTE_LOC)          /*transfer data number*/
	                     );

	                sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
	                sflash_set_command(sflash_cmd.all);

	                sflash_data = sflash_get_data();

	                manufacture_ID = (u8)((sflash_data & 0x00ff0000) >> 16);
	                device_ID = (u16)(sflash_data & 0x0000FFFF);

	                if(manufacture_ID != 0xbf || device_ID!= 0x2601)
	                {
	                    return(NULL);
	                }

	                   /*ok read the protection bit for each block*/
	                sflash_cmd.bitc.code = 0x72;                /*read block protection register*/
	                sflash_cmd.bitc.data_num = 0x6;             /*transfer data number*/

	                sflash_set_command(sflash_cmd.all);
	                prot1 = sflash_get_data();
	                prot2 = sflash_get_data();

	                /*ok write enable the device*/
	                sflash_cmd.bitc.code = 0x06;                    /*enable quad command*/
	                sflash_cmd.bitc.rwn =  SFLASH_RWN_NOTHING>>15;  /*3; no read/write*/
	                sflash_cmd.bitc.data_num = 0;
	                sflash_set_command(sflash_cmd.all);
	                sflash_get_data();

	                /*program the prot bit*/
	                sflash_cmd.bitc.code = 0x42;                    /*enable quad command*/
	                sflash_cmd.bitc.rwn = SFLASH_RWN_WRITE>>15;     /*write*/
	                sflash_cmd.bitc.data_num = 6;
	                prot1 = 0x0;
	                prot2=0x0;
	                sflash_set_command(sflash_cmd.all);
	                sflash_set_data(prot1);
	                sflash_set_data(prot2);

	                /*wait the program*/
	                sflash_cmd.bitc.code = 0x05;                    /*read status*/
	                sflash_cmd.bitc.rwn = SFLASH_RWN_READ>>15;      /*read*/
	                sflash_cmd.bitc.data_num = 1;
	                do
	                {
	                    sflash_set_command(sflash_cmd.all);
	                    status = sflash_get_data()&0xff;
	                }while((status&0x80) == 0x80);

	                /*ok read the protection bit for each block*/
	                sflash_cmd.bitc.code = 0x72;                    /*enable quad command*/
	                sflash_cmd.bitc.data_num = 0x6;                 /*transfer data number*/
	                sflash_set_command(sflash_cmd.all);
	                prot1 = sflash_get_data();
	                prot2 = sflash_get_data();
	            }

	            if(device->manufacture_ID == 0x0c2)
	            {
	                cmd_bit_set |= (0x2b|                           /*command*/
	                     SFLASH_SEND_CMD|                           /*transfer the command*/
	                     SFLASH_SEND_ADDR_BYTE_NUM_0|               /*address num*/
	                     SFLASH_SEND_DUMMY_BYTE_NUM_0|              /* dummy cycle*/
	                     SFLASH_RWN_READ|                           /*read data*/
	                     SFLASH_CMD_MODE_1X|                        /*set the sflash cmd mode*/
	                     SFLASH_ADDR_DUMMY_CYCLE_NUM_0|             /*set the sflash adr mode*/
	                     SFLASH_DATA_CYCLE_NUM_0|                   /*set the sflash data mode*/
	                     (1<<SFLASH_TRANSFER_BYTE_LOC)              /*transfer data number*/
	                     );
	                sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
	                sflash_set_command(sflash_cmd.all);
	                status=sflash_get_data()&0xff;
	                if((status&0x80)==0x80)
	                {
	                    sflash_cmd.bitc.code = device->commands->write_enable;  /*command*/
	                    sflash_cmd.bitc.rwn = SFLASH_RWN_NOTHING>>15;           /* not read & write*/
	                    sflash_cmd.bitc.data_num = 0x0;                         /*not transfer data*/
	                    sflash_set_command( sflash_cmd.all );
	                    sflash_get_data();
	                    sflash_cmd.bitc.code = 0x05;                            /*read status*/
	                    sflash_cmd.bitc.rwn = SFLASH_RWN_READ>>15;              /*read*/
	                    sflash_cmd.bitc.data_num = 1;
	                    do
	                    {
	                        sflash_set_command(sflash_cmd.all);
	                        status = sflash_get_data()&0xff;
	                    }while((status&0x01) == 0x01);

	                    sflash_cmd.bitc.code = 0x98;                            /*command*/
	                    sflash_cmd.bitc.rwn = SFLASH_RWN_NOTHING>>15;           /* not read & write*/
	                    sflash_cmd.bitc.data_num = 0x0;                         /*not transfer data*/
	                    sflash_set_command( sflash_cmd.all );
	                    sflash_get_data();
	                    sflash_cmd.bitc.code = 0x05;                            /*read status*/
	                    sflash_cmd.bitc.rwn = SFLASH_RWN_READ>>15;              /*read*/
	                    sflash_cmd.bitc.data_num = 1;
	                    do
	                    {
	                        sflash_set_command( sflash_cmd.all );
	                        status = sflash_get_data()&0xff;
	                    }while((status&0x01) == 0x01);
	                }
	                // check if the chip support 4X read mode?
	                cmd_bit_set |= (0x5A|                           /*command RDSFDP*/
	                    SFLASH_SEND_CMD|                            /*transfer the command*/
	                    SFLASH_SEND_ADDR_BYTE_NUM_3|                /*address num*/
	                    SFLASH_SEND_DUMMY_BYTE_NUM_1|               /*dummy cycle*/
	                    SFLASH_RWN_READ|                            /*read data*/
	                    SFLASH_CMD_MODE_1X|                         /*set the sflash cmd mode*/
	                    SFLASH_ADDR_DUMMY_CYCLE_NUM_0|              /*set the sflash adr mode*/
	                    SFLASH_DATA_CYCLE_NUM_0|                    /*set the sflash data mode*/
	                    SFLASH_TRANSFER_BYTE_NUM_4|                 /*transfer data number*/
	                    SFLASH_HOLD_TIME_100ns
	                    );

	                sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
	                sflash_set_command(sflash_cmd.all);
	                sflash_set_data(0x30);
	                sflash_data = sflash_get_data();
	                // command-address-data
	                // 0x32[bit12]=1:1-2-2
	                // 0x32[bit13]=1:1-2-4
	                // 0x32[bit14]=1:1-4-4
	                // sflash_data=0x30 31 32 33
	                if((sflash_data != 0x00000000) || (sflash_data != 0xFFFFFFFF))
	                {
	                    device->feature &= 0xFFFFFFF8;
	                    if(sflash_data & 0x00006000)
	                    {
	                        device->feature |= GD_SFLASH_4X_READ;
	                    #if CONFIG_BOARD_HARDWARE_INFO
	                        printf("[4X mode] ");
	                    #endif  /* CONFIG_BOARD_HARDWARE_INFO */
	                        //printf("support 4X mode read:0x%08x\n", sflash_data);
	                    }
	                    else
	                    {
	                        device->feature |= GD_SFLASH_1X_READ;
	                        //printf("not support 4X mode read:0x%08x\n", sflash_data);
	                    }
	                }
	            }
				device->channel = i;
	            goke_sflash_device[channel] = device;
                if (frist_device == NULL) {
                    frist_device = device;
                }
                sflash_Unlock(device);
                break;
	        }
	    }
	}
	
	if (frist_device != NULL) 
	{
	    ce_setting = 0x0E | ((u32)frist_device->channel  << 6);
	    sflash_set_ce(ce_setting);
	}

    return frist_device;
}

static u32 sflash_enable_io4(goke_sflash_dev_s* device )
{
    u8 status1                                  = 0;
    u8 status2                                  = 0;
    u32 data                                    = 0;
    u32  cmd_bit_set                            = 0;
    goke_sflash_command_s   sflash_cmd;
    u32 ce_setting                              = 0x38;

    /*for IO4 mode only*/
    ce_setting = ce_setting | ((u32)device->channel << 6);
    sflash_set_ce(ce_setting);

    /*after Init, the SST enter IO4 mode*/
    if(device->manufacture_ID == 0xbf)
    {
        return 0;
    }
    if(device->manufacture_ID == 0x1c)
    {
        cmd_bit_set |= (0x38|                   /*enable quad command*/
            SFLASH_SEND_CMD|                    /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_0|        /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_0|       /*dummy cycle*/
            SFLASH_RWN_NOTHING|                 /*no read/write*/
            SFLASH_CMD_MODE_1X|                 /*set command mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_0|      /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_0|            /*set the sflash data mode*/
            (0<<SFLASH_TRANSFER_BYTE_LOC)       /*transfer data number*/
            );
        sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
        sflash_set_command( sflash_cmd.all );
        sflash_get_data();
        return 0;
    }
    /* first read the status */
    cmd_bit_set |= (device->commands->read_status|  /*command*/
        SFLASH_SEND_CMD|                            /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|               /* dummy cycle*/
        SFLASH_RWN_READ|                            /*read data*/
        SFLASH_CMD_MODE_1X|                         /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|              /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                    /*set the sflash data mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)            /*transfer data number*/
        );
    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    status1 = sflash_get_data()&0xff;
    if((device->manufacture_ID == 0xef)             /*winbond read status2*/
        ||(device->manufacture_ID == 0x01)          /*for FL064P;Tom.wang;2010-10-21*/
        ||(device->manufacture_ID == 0xc8))         /*for GD liujinyng2011-10-12*/
    {
        sflash_cmd.bitc.code = 0x35;                /*command*/
        sflash_set_command( sflash_cmd.all );
        status2 = sflash_get_data()&0xff;
    }

    /* write enable the device */
    sflash_cmd.bitc.code = device->commands->write_enable;  /*command*/
    sflash_cmd.bitc.rwn = SFLASH_RWN_NOTHING>>15;           /* not read & write*/
    sflash_cmd.bitc.data_num = 0x0;                         /*not transfer data*/
    sflash_set_command(sflash_cmd.all);
    sflash_get_data();


    if(device->manufacture_ID == 0xc2)
    {
        data = status1|0x40;
    }
    else if(device->manufacture_ID == 0xef)
    {
        data = (status1<<8)+(status2|0x2);
    }
    else if(device->manufacture_ID == 0x01)             /*for FL064P;Tom.wang;2010-10-21*/
    {
        data = (status1<<8)+(status2|0x2);
    }
    else if(device->manufacture_ID == 0xc8)
    {
        data = status2|0x2;
    }

     /* write the status register */
    sflash_cmd.bitc.code = device->commands->write_status;  /*command*/
    sflash_cmd.bitc.rwn = SFLASH_RWN_WRITE>>15;             /*write*/
    if(device->manufacture_ID == 0xc2)
    {
        sflash_cmd.bitc.data_num = 0x1;                     /*transfer 1 byte data*/
    }
    else if(device->manufacture_ID == 0xef)
    {
        sflash_cmd.bitc.data_num = 0x2;                     /*transfer 2 byte data*/
    }
    else if(device->manufacture_ID == 0x01)                 /*for FL064P;Tom.wang;2010-10-21*/
    {
        sflash_cmd.bitc.data_num = 0x2;                     /*transfer data*/
    }
    else if(device->manufacture_ID == 0xc8)
    {
        sflash_cmd.bitc.code = 0x31;
        sflash_cmd.bitc.data_num = 0x1;                     /*transfer data*/
    }
    sflash_set_command(sflash_cmd.all);
    sflash_set_data(data);
    sflash_wip_done_wait(device);

    return 0;
}

static u32 sflash_disenable_io4( goke_sflash_dev_s* device )
{
    u8 status1                                  = 0;
    u8 status2                                  = 0;
    u32 data                                    = 0;
    u32 cmd_bit_set                             = 0;
    goke_sflash_command_s   sflash_cmd;
    u32 ce_setting                              = 0x0E;

    /*fix configuration for no pull-high W/P pin*/
    ce_setting = ce_setting | ((u32)device->channel << 6);
    sflash_set_ce(ce_setting);

    /*SST sflash support IO4 mode. don't exit this mode*/
    if(device->manufacture_ID == 0xbf)
    {
        return 0;
    }
    if(device->manufacture_ID == 0x1c)
    {
        cmd_bit_set |= (0xff|                       /*enable quad command*/
            SFLASH_SEND_CMD|                        /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_0|            /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_0|           /* dummy cycle*/
            SFLASH_RWN_NOTHING|                     /*no read/write*/
            SFLASH_CMD_MODE_4X|                     /*set command mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_0|          /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_0|                /*set the sflash data mode*/
            (0<<SFLASH_TRANSFER_BYTE_LOC)           /*transfer data number*/
            );
        sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
        sflash_set_command( sflash_cmd.all );
        sflash_get_data();
        return 0;
    }

    /*first read the status */
    cmd_bit_set |= (device->commands->read_status|      /*command*/
                 SFLASH_SEND_CMD|                       /*transfer the command*/
                 SFLASH_SEND_ADDR_BYTE_NUM_0|           /*address num*/
                 SFLASH_SEND_DUMMY_BYTE_NUM_0|          /* dummy cycle*/
                 SFLASH_RWN_READ|                       /*read data*/
                 SFLASH_CMD_MODE_1X|                    /*set the sflash cmd mode*/
                 SFLASH_ADDR_DUMMY_CYCLE_NUM_0|         /*set the sflash adr mode*/
                 SFLASH_DATA_CYCLE_NUM_0|               /*set the sflash data mode*/
                 (1<<SFLASH_TRANSFER_BYTE_LOC)          /*transfer data number*/
                 );
    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command( sflash_cmd.all );
    status1 = sflash_get_data()&0xff;

    if((device->manufacture_ID == 0xef)                 /*winbond read status2*/
        ||(device->manufacture_ID == 0x01)              /*for FL064P;Tom.wang;2010-10-21*/
        ||(device->manufacture_ID == 0xc8))             /*for GD liujinyng2011-10-12*/
    {
        sflash_cmd.bitc.code = 0x35;                    /*command*/
        sflash_set_command(sflash_cmd.all);
        status2 = sflash_get_data()&0xff;
    }

    /* write enable the device */
    sflash_cmd.bitc.code = device->commands->write_enable;      /*command*/
    sflash_cmd.bitc.rwn = SFLASH_RWN_NOTHING>>15;               /* not read & write*/
    sflash_cmd.bitc.data_num = 0x0;                             /*not transfer data*/
    sflash_set_command( sflash_cmd.all );
    sflash_get_data();

    if(device->manufacture_ID == 0xc2)
    {
        //Steven Yu: // clear quad
        //for GK7101 workaround do not enable reset mode otherwise code can not bootup
        //data = status1&(~0x40);                                  /*clear quad*/
        //write back status1
        data = status1;
    }
    else if(device->manufacture_ID == 0xef)
    {
        data = (status1<<8)+ (status2 & (~0x2));                 /*clear the quad*/
    }
    else if(device->manufacture_ID == 0x01)                      /*for FL064P;Tom.wang;2010-10-21*/
    {
        data = (status1<<8)+ (status2 & (~0x2));                 /*clear the quad*/
    }
    else if(device->manufacture_ID == 0xc8)
    {
        data = status2 & (~0x2);
    }

    /* write the status register */
    sflash_cmd.bitc.code = device->commands->write_status;      /*command*/
    sflash_cmd.bitc.rwn = SFLASH_RWN_WRITE>>15;                 /*write*/
    if(device->manufacture_ID == 0xc2)
    {
        sflash_cmd.bitc.data_num = 0x1;                         /*transfer data*/
    }
    else if(device->manufacture_ID == 0xef)
    {
        sflash_cmd.bitc.data_num = 0x2;                         /*transfer data*/
    }
    else if(device->manufacture_ID == 0x01)                     /*for FL064P;Tom.wang;2010-10-21*/
    {
        sflash_cmd.bitc.data_num = 0x2;                         /*transfer data*/
    }
    else if(device->manufacture_ID == 0xc8)
    {
        sflash_cmd.bitc.code = 0x31;
        sflash_cmd.bitc.data_num = 0x1;                         /*transfer data*/
    }

    sflash_set_command(sflash_cmd.all);
    sflash_set_data(data);
    sflash_wip_done_wait(device);

    return 0;
}

static u32 sflash_write_enable(goke_sflash_dev_s *device)
{
    goke_sflash_command_s   sflash_cmd;
    u32 cmd_bit_set                                     = 0;

    cmd_bit_set = (device->commands->write_enable|     /*command*/
        SFLASH_SEND_CMD|                                /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
        SFLASH_RWN_NOTHING|                             /*no read/write data*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                        /*set the sflash data mode*/
        (0<<SFLASH_TRANSFER_BYTE_LOC)|                  /*transfer data number*/
        SFLASH_HOLD_TIME_100ns
        );
    if(device->manufacture_ID == 0xbf)
    {
        cmd_bit_set |= SFLASH_CMD_MODE_4X;              /*set the sflash cmd mode*/
    }
    else
    {
        cmd_bit_set |= SFLASH_CMD_MODE_1X;              /*set the sflash cmd mode*/
    }

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    sflash_get_data();

    return sflash_wel_done_wait(device);
}

static u32 sflash_set_ext_addr(goke_sflash_dev_s* device, u8 offset)
{
    u32 cmd_bit_set                                 = 0;
    goke_sflash_command_s   sflash_cmd;
    u8 extadd = 0;

    sflash_write_enable(device);

    cmd_bit_set = (device->commands->read_ext_addr|/*command*/
        SFLASH_SEND_CMD|                            /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|               /* dummy cycle*/
        SFLASH_RWN_READ|                            /*read data*/
        SFLASH_CMD_MODE_1X|                         /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|              /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                    /*set the sflash data mode*/
        (2<<SFLASH_TRANSFER_BYTE_LOC)               /*transfer data number*/
        );

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    extadd = sflash_get_data();
    if(offset == extadd)
    {
        return 0;
    }

    sflash_write_enable(device);
    cmd_bit_set = (device->commands->write_ext_addr|/*command*/
        SFLASH_SEND_CMD|                            /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|               /* dummy cycle*/
        SFLASH_RWN_WRITE|                           /*write data*/
        SFLASH_CMD_MODE_1X|                         /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|              /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                    /*set the sflash data mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)               /*transfer data number*/
        );

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    sflash_set_data(offset);
    return 0;
}

static int sflash_read_io1( goke_sflash_dev_s* device, u32 offset, u32* buffer, u32 data_len )
{
    u32 cmd_bit_set                                 = 0;
    goke_sflash_command_s   sflash_cmd;

    cmd_bit_set |= (device->commands->read_data|    /*command*/
        SFLASH_SEND_CMD|                            /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_3|                /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|               /* dummy cycle*/
        SFLASH_RWN_READ|                            /*read data*/
        SFLASH_CMD_MODE_1X|                         /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|              /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                    /*set the sflash data mode*/
        SFLASH_TRANSFER_BYTE_NUM_4|                 /*transfer data number*/
        SFLASH_HOLD_TIME_100ns
        );

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
    }
    sflash_set_command(sflash_cmd.all);
    sflash_set_data(offset);

    while(data_len--)
    {
        *buffer++ = sflash_get_data();
    }
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }

    return 0;
}

static int sflash_read_io2( goke_sflash_dev_s* device, u32 offset, u32* buffer, u32 data_len )
{
    u32 cmd_bit_set                                 = 0;
    goke_sflash_command_s   sflash_cmd;

    if(device->manufacture_ID == 0x20)
    {
        cmd_bit_set |= (device->commands->read_io2|             /*command*/
            SFLASH_SEND_CMD|                                    /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_3|                        /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_2|                       /* dummy cycle*/
            SFLASH_RWN_READ|                                    /*read data*/
            SFLASH_CMD_MODE_1X|                                 /*set the sflash cmd mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_1|                      /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_1|                            /*set the sflash data mode*/
            SFLASH_TRANSFER_BYTE_NUM_4                          /*transfer data number*/
            );
    }
    else
    {
        cmd_bit_set |= (device->commands->read_io2|             /*command*/
            SFLASH_SEND_CMD|                                    /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_3|                        /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_1|                       /* dummy cycle*/
            SFLASH_RWN_READ|                                    /*read data*/
            SFLASH_CMD_MODE_1X|                                 /*set the sflash cmd mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_1|                      /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_1|                            /*set the sflash data mode*/
            SFLASH_TRANSFER_BYTE_NUM_4                          /*transfer data number*/
            );
    }

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
    }
    sflash_set_command(sflash_cmd.all);
    sflash_set_data(offset);

    while(data_len--)
    {
        *buffer++ = sflash_get_data();
    }
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }

    return 0;
}

static int sflash_read_io4( goke_sflash_dev_s* device, u32 offset, u32* buffer, u32 data_len  )
{
    u32 cmd_bit_set                                 = 0;
    u32 err                                         = 0;
    goke_sflash_command_s   sflash_cmd;

    if(device->manufacture_ID == 0x20)
    {
        err = 0;
    }
    else
    {
        err = sflash_enable_io4(device);                 /*enable the IO4 mode*/
    }
    if(err != 0)
    {
        return err;
    }

    if(device->manufacture_ID == 0xbf)
    {
       cmd_bit_set |= (device->commands->read_io4|          /*command*/
        SFLASH_SEND_CMD|                                    /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_3|                        /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_1|                       /*dummy cycle*/
        SFLASH_RWN_READ|                                    /*read data*/
        SFLASH_CMD_MODE_4X|                                 /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_2|                      /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_2|                            /*set the sflash data mode*/
        SFLASH_TRANSFER_BYTE_NUM_4                          /*transfer data number*/
         );
    }
    else if(device->manufacture_ID == 0x1c)
    {
        cmd_bit_set |= (device->commands->read_io4|         /*command*/
            SFLASH_SEND_CMD|                                /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_3|                    /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_3|                   /*dummy cycle*/
            SFLASH_RWN_READ|                                /*read data*/
            SFLASH_CMD_MODE_4X|                             /*set the sflash cmd mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_2|                  /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_2|                        /*set the sflash data mode*/
            SFLASH_TRANSFER_BYTE_NUM_4                      /*transfer data number*/
            );
    }
    else if(device->manufacture_ID == 0x20)
    {
        cmd_bit_set |= (device->commands->read_io4|         /*command*/
            SFLASH_SEND_CMD|                                /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_3|                    /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_5|                   /*dummy cycle*/
            SFLASH_RWN_READ|                                /*read data*/
            SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_2|                  /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_2|                        /*set the sflash data mode*/
            SFLASH_TRANSFER_BYTE_NUM_4                      /*transfer data number*/
            );
    }
    else
    {
        cmd_bit_set |= (device->commands->read_io4|         /*command*/
            SFLASH_SEND_CMD|                                /*transfer the command*/
            SFLASH_SEND_ADDR_BYTE_NUM_3|                    /*address num*/
            SFLASH_SEND_DUMMY_BYTE_NUM_3|                   /*dummy cycle*/
            SFLASH_RWN_READ|                                /*read data*/
            SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
            SFLASH_ADDR_DUMMY_CYCLE_NUM_2|                  /*set the sflash adr mode*/
            SFLASH_DATA_CYCLE_NUM_2|                        /*set the sflash data mode*/
            SFLASH_TRANSFER_BYTE_NUM_4                      /*transfer data number*/
            );
    }

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
    }
    sflash_set_command(sflash_cmd.all);
    sflash_set_data(offset);

    while(data_len--)
    {
        *buffer++ = sflash_get_data();
    }
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }

    //if(device->manufacture_ID == 0x20)
    //{
    //    err = sflash_wip_done_wait(device);
    //}
    //else
    //{
    //    err = sflash_disenable_io4(device);                  /*disable the IO4 mode*/
    //}

    return err;
}

static int sflash_write_io1( goke_sflash_dev_s* device, u32 offset, u32* buffer, u32 data_len )
{
    u32 count                                       = 0;
//    u32 page_words;
    u32 write_words                                 = data_len;
    u32 cmd_bit_set                                 = 0;
    goke_sflash_command_s   sflash_cmd;
    u32 result                                      = 0;
    u32 extadd = 0;

//    page_words = device->page_bytes / sizeof(u32);

    while(write_words--)
    {
        if(count == 0)
        {
            // >16MB
            if((extadd == 0) && (offset >= GD_SFLASH_16M_SIZE))
            {
                extadd = 1;
                sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
            }

            /*issue a write command sequence to prepare the device for data to be written*/
            cmd_bit_set |= (device->commands->write_enable|         /*command*/
                SFLASH_SEND_CMD|                                    /*transfer the command*/
                SFLASH_SEND_ADDR_BYTE_NUM_0|                        /*address num*/
                SFLASH_SEND_DUMMY_BYTE_NUM_0|                       /* dummy cycle*/
                SFLASH_RWN_NOTHING|                                 /*no read/write data*/
                SFLASH_CMD_MODE_1X|                                 /*set the sflash cmd mode*/
                SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                      /*set the sflash adr mode*/
                SFLASH_DATA_CYCLE_NUM_0|                            /*set the sflash data mode*/
                (0<<SFLASH_TRANSFER_BYTE_LOC)|                      /*transfer data number*/
                SFLASH_HOLD_TIME_100ns
                );

            sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
            sflash_set_command(sflash_cmd.all);
            sflash_get_data();

            cmd_bit_set |= (device->commands->program_page|         /*command*/
                SFLASH_SEND_CMD|                                    /*transfer the command*/
                SFLASH_SEND_ADDR_BYTE_NUM_3|                        /*address num*/
                SFLASH_SEND_DUMMY_BYTE_NUM_0|                       /* dummy cycle*/
                SFLASH_RWN_WRITE|                                   /*write data*/
                SFLASH_CMD_MODE_1X|                                 /*set the sflash cmd mode*/
                SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                      /*set the sflash adr mode*/
                SFLASH_DATA_CYCLE_NUM_0|                            /*set the sflash data mode*/
                SFLASH_TRANSFER_BYTE_NUM_4|                         /*transfer data number*/
                SFLASH_HOLD_TIME_100ns
                );

            sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
            sflash_set_command(sflash_cmd.all);
            sflash_set_data(offset);
        }

        sflash_set_data(*buffer++);
        count++;
        offset += 4;

        if((offset % device->page_bytes) == 0)
        {
            /* we are at a page boundary so we have to
                wait until the WIP status to be cleared by the device*/
            result = sflash_wip_done_wait(device);
            if( result != 0 )
            {
                break;
            }
            count = 0;
        }
    }

    /*new added for the case that words < page_words*/
    //if(data_len < page_words)
    {
        result = sflash_wip_done_wait(device);
        if(result != 0)
        {
            return(result);
        }
    }

    if(extadd)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }
    cmd_bit_set |= (device->commands->read_status|      /*command*/
        SFLASH_SEND_CMD|                                /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
        SFLASH_RWN_READ|                                /*read data*/
        SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                        /*set the sflash data mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)|                  /*transfer data number*/
        SFLASH_HOLD_TIME_100ns
        );

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    sflash_get_data();

    return(result);
}

static int sflash_write_io2( goke_sflash_dev_s* device, u32 offset, u32* buffer, u32 data_len  )
{
    u32 count                                       = 0;
//    u32 page_words;
    u32 write_words                                 = data_len;
    u32 cmd_bit_set                                 = 0;
    goke_sflash_command_s   sflash_cmd;
    u32 result                                      = 0;
    u32 extadd = 0;

//    page_words = device->page_bytes / sizeof(u32);

    while(write_words--)
    {
        if(count == 0)
        {
            // >16MB
            if((extadd == 0) && (offset >= GD_SFLASH_16M_SIZE))
            {
                extadd = 1;
                sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
            }
            /* issue a write command sequence to prepare the device for data to be written*/
            cmd_bit_set |= (device->commands->write_enable|     /*command*/
                SFLASH_SEND_CMD|                                /*transfer the command*/
                SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
                SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /*dummy cycle*/
                SFLASH_RWN_NOTHING|                             /*no read/write data*/
                SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
                SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
                SFLASH_DATA_CYCLE_NUM_0|                        /*set the sflash data mode*/
                (0<<SFLASH_TRANSFER_BYTE_LOC)                   /*transfer data number*/
                );

            sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
            sflash_set_command(sflash_cmd.all);
            sflash_get_data();

            cmd_bit_set |= (device->commands->program_page2|    /*command*/
                SFLASH_SEND_CMD|                                /*transfer the command*/
                SFLASH_SEND_ADDR_BYTE_NUM_3|                    /*address num*/
                SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /*dummy cycle*/
                SFLASH_RWN_WRITE|                               /*write data*/
                SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
                SFLASH_ADDR_DUMMY_CYCLE_NUM_1|                  /*set the sflash adr mode*/
                SFLASH_DATA_CYCLE_NUM_1|                        /*set the sflash data mode*/
                (0x1f<<SFLASH_TRANSFER_BYTE_LOC)                /*transfer data number*/
                );

            // >16MB
            if(offset >= GD_SFLASH_16M_SIZE)
            {
                sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
            }
            sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
            sflash_set_command(sflash_cmd.all);
            sflash_set_data(offset);
        }

        sflash_set_data(*buffer++);
        count++;
        offset += 4;

        if((offset % device->page_bytes ) == 0)
        {
            /*we are at a page boundary so we have to
                 wait until the WIP status to be cleared by the device*/
            result = sflash_wip_done_wait(device);
            if(result != 0)
            {
                break;
            }
            count = 0;
        }
    }

    /*new added for the case that words < page_words*/
    //if(data_len < page_words)
    {
        result = sflash_wip_done_wait(device);
        if(result != 0)
        {
            return(result);
        }
    }

    if(extadd)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }
    cmd_bit_set |= (device->commands->read_status|      /*command*/
        SFLASH_SEND_CMD|                                /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
        SFLASH_RWN_READ|                                /*read data*/
        SFLASH_CMD_MODE_1X|                             /*set the sflash cmd mode*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_1|                  /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_1|                        /*set the sflash data mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)                   /*transfer data number*/
        );

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    sflash_get_data();
    return(result);
}

static int sflash_write_io4( goke_sflash_dev_s* device, u32 offset, u32* buffer, u32 data_len )
{
    u32 count                                            = 0;
//    u32 page_words;
    u32 write_words                                     = data_len;
    u32 cmd_bit_set                                     = 0;
    goke_sflash_command_s   sflash_cmd;
    u32 result                                         = 0;
    u32 extadd = 0;

//    page_words = device->page_bytes / sizeof(u32);

    while(write_words--)
    {
        if(count == 0)
        {
            // >16MB
            if((extadd == 0) && (offset >= GD_SFLASH_16M_SIZE))
            {
                extadd = 1;
                sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
            }
            //if(device->manufacture_ID != 0x20)
            //    sflash_enable_io4(device);
            /*issue a write command sequence to prepare the device for data to be written*/
            cmd_bit_set |= (device->commands->write_enable|     /*command*/
                SFLASH_SEND_CMD|                                /*transfer the command*/
                SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
                SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
                SFLASH_RWN_NOTHING|                             /*no read/write data*/
                SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
                SFLASH_DATA_CYCLE_NUM_0|                        /*set the sflash data mode*/
                (0<<SFLASH_TRANSFER_BYTE_LOC)                   /*transfer data number*/
                );

            if(device->manufacture_ID == 0xbf)
            {
                cmd_bit_set |= SFLASH_CMD_MODE_4X;              /*set the sflash cmd mode*/
            }
            else if(device->manufacture_ID == 0x1c)
            {
                cmd_bit_set |= SFLASH_CMD_MODE_4X;              /*set the sflash cmd mode*/
            }
            else
            {
                cmd_bit_set |= SFLASH_CMD_MODE_1X;              /*set the sflash cmd mode*/
            }
            sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
            sflash_set_command(sflash_cmd.all);
            sflash_get_data();

            cmd_bit_set |= (device->commands->program_page4|    /*command*/
                SFLASH_SEND_CMD|                                /*transfer the command*/
                SFLASH_SEND_ADDR_BYTE_NUM_3|                    /*address num*/
                SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
                SFLASH_RWN_WRITE|                               /*write data*/
                SFLASH_DATA_CYCLE_NUM_2|                        /*set the sflash data mode*/
                (0x1f<<SFLASH_TRANSFER_BYTE_LOC)                /*transfer data number*/
                );

            if(device->manufacture_ID == 0xbf)
            {
                cmd_bit_set |= SFLASH_CMD_MODE_4X;              /*set the sflash cmd mode*/
            }
            else if  (device->manufacture_ID == 0x1c)
            {
                cmd_bit_set |= SFLASH_CMD_MODE_4X;
            }
            else
            {
                cmd_bit_set |= SFLASH_CMD_MODE_1X;              /*set the sflash cmd mode*/
            }


            if(device->manufacture_ID == 0xc2)
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_2;   /*set the sflash adr mode*/
            }
            else if(device->manufacture_ID == 0xbf)
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_2;   /*set the sflash adr mode*/
            }
            else if(device->manufacture_ID == 0xef)
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_0;   /*set the sflash adr mode*/
            }
            else if(device->manufacture_ID == 0x01)             /*for FL064P;Tom.wang;2010-10-21*/
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_0;   /*set the sflash adr mode*/
            }
            else  if(device->manufacture_ID == 0x20)
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_2;
            }
            else if(device->manufacture_ID == 0xc8)
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_0;
            }
            else if(device->manufacture_ID == 0x1c)
            {
                cmd_bit_set |= SFLASH_ADDR_DUMMY_CYCLE_NUM_2;
            }
            sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
            sflash_set_command(sflash_cmd.all);
            sflash_set_data(offset);
        }

        sflash_set_data(*buffer++);
        count++;
        offset += 4;

        if((offset % device->page_bytes) == 0)
        {
            //if(device->manufacture_ID != 0x20)
            //sflash_disenable_io4(device);
            /* we are at a page boundary so we have to
             wait until the WIP status to be cleared by the device*/
            result = sflash_wip_done_wait(device);
            if(result != 0)
            {
                break;
            }
            count = 0;
        }
    }

    //if(device->manufacture_ID != 0x20)
    //{
    //    sflash_disenable_io4(device);
    //}

    /*new added for the case that words < page_words*/
    //if(data_len < page_words)
    {
        result = sflash_wip_done_wait(device);
        if(result != 0)
        {
            return(result);
        }
    }
    if(extadd)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }
    cmd_bit_set |= (device->commands->read_status|      /*command*/
        SFLASH_SEND_CMD|                                /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_0|                    /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
        SFLASH_RWN_READ|                                /*read data*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
        (1<<SFLASH_TRANSFER_BYTE_LOC)                   /*transfer data number*/
        );

    if(device->manufacture_ID == 0xbf)
    {
        /*set the sflash cmd mode, set the sflash data mode*/
        cmd_bit_set |= (SFLASH_CMD_MODE_4X|SFLASH_DATA_CYCLE_NUM_2);
    }
    else
    {
        /*set the sflash cmd mode, set the sflash data mode*/
        cmd_bit_set |= (SFLASH_CMD_MODE_1X|SFLASH_DATA_CYCLE_NUM_0);
    }

    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);
    sflash_set_command(sflash_cmd.all);
    sflash_get_data();

    return(result);
}

static int sflash_erase_sector(goke_sflash_dev_s* device, u16 sectorIndex)
{
    u32 offset;
    u32 cmd_bit_set                             = 0;
    goke_sflash_command_s   sflash_cmd;
    u32 result;
    ulong CESetting = 0x38;

    CESetting = CESetting | ((ulong)device->channel << 6);
    sflash_set_ce(CESetting);

    offset = sectorIndex * device->sector_bytes;
    // >16MB
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
    }
    if(old_feature == GOKE_SFLASH_FEATURE_IO4)
    {
        old_feature = GOKE_SFLASH_FEATURE_IO1;
        if(device->manufacture_ID != 0x20)
        {
            sflash_disenable_io4(device);               /*disable the IO4 mode*/
        }
    }

    sflash_write_enable(device);

    cmd_bit_set |= (device->commands->erase_sector|     /*command*/
        SFLASH_SEND_CMD|                                /*transfer the command*/
        SFLASH_SEND_ADDR_BYTE_NUM_3|                    /*address num*/
        SFLASH_SEND_DUMMY_BYTE_NUM_0|                   /* dummy cycle*/
        SFLASH_RWN_NOTHING|                             /*no read/write data*/
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|                  /*set the sflash adr mode*/
        SFLASH_DATA_CYCLE_NUM_0|                        /*set the sflash data mode*/
        (0<<SFLASH_TRANSFER_BYTE_LOC)|                  /*transfer data number*/
        SFLASH_HOLD_TIME_100ns
        );
    sflash_cmd_bit_set(&sflash_cmd,&cmd_bit_set);

    sflash_set_command(sflash_cmd.all);
    sflash_set_data(offset);
    result = sflash_wip_done_wait(device);
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }

    sflash_cmd.bitc.code = device->commands->write_disable; /*command*/
    if(device->manufacture_ID == 0xbf)
    {
        sflash_cmd.bitc.cmd_mode = 2;                       /*set the sflash cmd mode*/
    }
    else if(device->manufacture_ID == 0x1c)
    {
        sflash_cmd.bitc.cmd_mode = 0;
    }
    else
    {
        sflash_cmd.bitc.cmd_mode = 0;                       /*set the sflash cmd mode*/
    }
    sflash_cmd.bitc.adr_num = 0;                            /*address num*/

    sflash_set_command(sflash_cmd.all);
    sflash_get_data();
    CESetting = CESetting & (~((ulong)device->channel << 6));
    sflash_set_ce(CESetting);
    return(result);
}

static goke_sflash_feature_e sflash_get_feature(goke_sflash_dev_s* device, goke_sflash_type_e type)
{
    goke_sflash_feature_e feature               = GOKE_SFLASH_FEATURE_IO1;
    u8 temp                                     = 0;

    if( !device )
    {
        return feature;
    }
    if(type == GOKE_SFLASH_TYPE_READ)
    {
        temp = device->feature & 0x0F;
    }
    else
    {
        temp = (device->feature & 0xF0) >> 4;
    }
    switch(temp)
    {
    case 0x01:
        feature = GOKE_SFLASH_FEATURE_IO1;
        break;
    case 0x02:
        feature = GOKE_SFLASH_FEATURE_IO2;
        break;
    case 0x04:
        feature = GOKE_SFLASH_FEATURE_IO4;
        break;
    default:
        break;
    }
    return feature;
}

static u32 sflash_cmd_bit_set(goke_sflash_command_s *sflashCmd, u32 *cmd_bit_set)
{
    if(!sflashCmd)
    {
        return -1;
    }

    sflashCmd->all = (*cmd_bit_set);
    (*cmd_bit_set) = 0;

    return 0;
}

int spi_flash_write_common(struct spi_flash *flash, u32 offset,
    const void *buf, size_t data_len)
{
    goke_sflash_feature_e feature               = GOKE_SFLASH_FEATURE_IO1;
    u32 byte_left;
    u8* buffer                                  = (u8 *)buf;
    u32 value                                   = 0;
    int ret                                     = 0;
    u32 i;
    ulong CESetting = 0x38;
    struct goke_spi_flash_t *goke_spi_flash     = to_spi_flash(flash);
    goke_sflash_dev_s *device                   = goke_spi_flash->device;

    CESetting = CESetting | ((ulong)device->channel << 6);
    sflash_set_ce(CESetting);

    byte_left = data_len % sizeof(u32);
    if(byte_left > 0)
    {
        for (i = 0; i < byte_left; i++)
        {
            value |= (buffer[data_len - byte_left + i] << (i * 8));
        }
        for (i = 4; i > byte_left; i--)
        {
            value |= 0xff << ((i - 1) * 8);
        }
    }

    feature = sflash_get_feature(device,GOKE_SFLASH_TYPE_WRITE);
    if(feature == GOKE_SFLASH_FEATURE_IO4)
    {
        sflash_set_ce(0x38 | ((u32)device->channel << 6));
        if(old_feature != feature)
        {
            old_feature = feature;
            if(device->manufacture_ID != 0x20)
            {
                ret = sflash_enable_io4(device);                 /*enable the IO4 mode*/
            }
            if(ret != 0)
            {
                return ret;
            }
        }
        ret = sflash_write_io4(device, offset, (u32*)buf, data_len / sizeof(u32));
        if (ret != 0)
        {
            return ret;
        }
        if (value != 0)
        {
            ret = sflash_write_io4(device, offset + data_len - byte_left, &value, 1);
        }
        if (ret != 0)
        {
            return ret;
        }
    }
    else if(feature == GOKE_SFLASH_FEATURE_IO2)
    {
        sflash_set_ce(0x0E | ((u32)device->channel << 6));
        if(old_feature != feature)
        {
            old_feature = feature;
            if(device->manufacture_ID != 0x20)
            {
                ret = sflash_disenable_io4(device);                  /*disable the IO4 mode*/
            }
        }
        ret = sflash_write_io2(device, offset, (u32*)buf, data_len / sizeof(u32));
        if (ret != 0)
        {
            return ret;
        }
        if (value != 0)
        {
            ret = sflash_write_io2(device, offset + data_len - byte_left, &value, 1);
        }
        if (ret != 0)
        {
            return ret;
        }
    }
    else
    {
        sflash_set_ce(0x0E | ((u32)device->channel << 6));
        if(old_feature != feature)
        {
            old_feature = feature;
            if(device->manufacture_ID != 0x20)
            {
                ret = sflash_disenable_io4(device);                  /*disable the IO4 mode*/
            }
        }
        ret = sflash_write_io1(device, offset, (u32*)buf, data_len / sizeof(u32));
        if (ret != 0)
        {
            return ret;
        }
        if (value != 0)
        {
            ret = sflash_write_io1(device, offset + data_len - byte_left, &value, 1);
        }
        if (ret != 0)
        {
            return ret;
        }
    }
    CESetting = CESetting & (~((ulong)device->channel << 6));
    sflash_set_ce(CESetting);

    return ret;
}


int spi_flash_read_common(struct spi_flash *flash, u32 offset,
    const void *buf, size_t data_len)
{
    goke_sflash_feature_e feature           = GOKE_SFLASH_FEATURE_IO1;
    u32 byte_left;
    u8* buffer                              = (u8 *)buf;
    u32 value                               = 0;
    int ret                                 = 0;
    u32 i;
    ulong CESetting = 0x38;
    struct goke_spi_flash_t *goke_spi_flash = to_spi_flash(flash);
    goke_sflash_dev_s *device = goke_spi_flash->device;
    CESetting = CESetting | ((ulong)device->channel << 6);
    sflash_set_ce(CESetting);
    byte_left = data_len % sizeof(u32);

    feature = sflash_get_feature(device, GOKE_SFLASH_TYPE_READ);
    if(feature == GOKE_SFLASH_FEATURE_IO4)             /*support IO4 mode*/
    {
        sflash_set_ce(0x38 | ((u32)device->channel << 6));
        if(old_feature != feature)
        {
            old_feature = feature;
            if(device->manufacture_ID != 0x20)
            {
                sflash_enable_io4(device);                 /*enable the IO4 mode*/
            }
        }
        ret = sflash_read_io4(device, offset, (u32*)buf, data_len / sizeof(u32));
        if (ret != 0)
        {
            return ret;
        }
        if (byte_left > 0)
        {
            ret = sflash_read_io4(device, offset + data_len - byte_left, &value, 1);
        }
        if (ret != 0)
        {
            return ret;
        }
    }
    else if( feature == GOKE_SFLASH_FEATURE_IO2)     /*support IO2 mode*/
    {
        sflash_set_ce(0x0E | ((u32)device->channel << 6));
        if(old_feature != feature)
        {
            old_feature = feature;
            if(device->manufacture_ID != 0x20)
            {
                ret = sflash_disenable_io4(device);                  /*disable the IO4 mode*/
            }
        }
        ret = sflash_read_io2(device, offset, (u32*)buf, data_len / sizeof(u32));
        if (ret != 0)
        {
            return ret;
        }
        if (byte_left > 0)
        {
            ret = sflash_read_io2(device, offset + data_len - byte_left, &value, 1);
        }
        if (ret != 0)
        {
            return ret;
        }
    }
    else
    {
        sflash_set_ce(0x0E | ((u32)device->channel << 6));
        if(old_feature != feature)
        {
            old_feature = feature;
            if(device->manufacture_ID != 0x20)
            {
                ret = sflash_disenable_io4(device);                  /*disable the IO4 mode*/
            }
        }
        ret = sflash_read_io1(device, offset, (u32*)buf, data_len / sizeof(u32));
        if (ret != 0)
        {
            return ret;
        }
        if (byte_left > 0)
        {
            ret = sflash_read_io1(device, offset + data_len - byte_left, &value, 1);
        }
        if (ret != 0)
        {
            return ret;
        }
    }

    if (value != 0)
    {
        for (i = 0; i < byte_left; i++)
        {
            buffer[data_len - byte_left + i] = (u8)((value & (0xff << (i * 8))) >> (i * 8));
        }
    }

    CESetting = CESetting & (~((ulong)device->channel << 6));
    sflash_set_ce(CESetting);
    return ret;
}

struct spi_flash *spi_flash_probe(unsigned int bus, unsigned int cs,
    unsigned int max_hz, unsigned int spi_mode)
{
    struct spi_flash *flash = NULL;
	int i;

    if (goke_sflash_device[cs] != NULL) {
        flash = sflash_probe(NULL, goke_sflash_device[cs]);
    } else {
    	for(i = 0; i < GOKE_SFLASH_CHANNEL_NUM; i++)
    	{
    		if(goke_sflash_device[i] != NULL)
    			flash = sflash_probe(NULL, goke_sflash_device[i]);
    	}
    }

    return flash;

}

void spi_flash_free(struct spi_flash *flash)
{
    free(flash);
}
void spi_release_bus(struct spi_slave *slave)
{
    /* Nothing to do */
}
int spi_claim_bus(struct spi_slave *slave)
{
    /* Nothing to do */
    return 0;
}

static inline struct goke_spi_flash_t *to_spi_flash(struct spi_flash *flash)
{
    return container_of(flash, struct goke_spi_flash_t, flash);
}

static int sflash_read(struct spi_flash *flash,
    u32 offset, size_t len, void *buf)
{
    return spi_flash_read_common(flash, offset, buf, len);
}

static int sflash_write(struct spi_flash *flash,
    u32 offset, size_t len, const void *buf)
{
    struct goke_spi_flash_t *goke_spi_flash     = to_spi_flash(flash);
    goke_sflash_dev_s *device;
    u32 cmd_bit_set                             = 0;
    unsigned long sector_bytes;
    unsigned long byte_addr;
    size_t chunk_len;
    size_t actual;
    u32 words                                   = 0;
    u32 byte_left                               = 0;
    u32 data                                    = 0;
    u32 *dataP                                  = (u32*)buf;
    int ret                                     = 0;
	int channel;
	u32 ce_setting = 0x0E;

    device = goke_spi_flash->device;

    sector_bytes = device->sector_bytes;
    byte_addr = offset % sizeof(u32);

    ret = spi_claim_bus(flash->spi);
    if (ret)
    {
        debug("SF: Unable to claim SPI bus\n");
        return ret;
    }
    if(check_magic_number(offset, len, buf)) {
        big_endian_to_little_endian(offset, len, dataP);
    }
    puts("\nProgramming:\n");

    for (actual = 0; actual < len ; actual += chunk_len)
    {
        chunk_len = min(len - actual, sector_bytes - byte_addr);
        ret = spi_flash_write_common(flash, offset + actual, buf + actual, chunk_len);
        if (ret < 0)
        {
            debug("SF: Page Program failed\n");
            break;
        }
        byte_addr = 0;
        printf("\033[12D   % 2d%%", (actual + chunk_len) * 100 / len);
    }
    printf("\033[12D\n");
    debug("SF: Successfully programmed %d bytes @ 0x%x\n", len, offset);


    puts("\nVerifying:\n");

	channel = device->channel;
    ce_setting = ce_setting | ((u32)channel  << 6);
    sflash_set_ce(ce_setting);
    // >16MB
    if(offset >= GD_SFLASH_16M_SIZE)
    {
        sflash_set_ext_addr(device, offset/GD_SFLASH_16M_SIZE);
    }
    /*issue the slow-read command*/
    cmd_bit_set = (device->commands->read_data|
        SFLASH_SEND_CMD|
        SFLASH_SEND_ADDR_BYTE_NUM_3|
        SFLASH_SEND_DUMMY_BYTE_NUM_0|
        SFLASH_RWN_READ|
        SFLASH_CMD_MODE_1X|
        SFLASH_ADDR_DUMMY_CYCLE_NUM_0|
        SFLASH_DATA_CYCLE_NUM_0|
        SFLASH_TRANSFER_BYTE_NUM_4|
        SFLASH_HOLD_TIME_100ns
        );
    sflash_set_command(cmd_bit_set);
    sflash_set_data(offset);

    byte_left = len % sizeof(u32);
    for(words = 0; words < len / sizeof(u32); words++)
    {
        data = sflash_get_data();
        if(data != *dataP++)
        {
             printf("error\n");
             return -1;
        }
        if(((words * 100 * sizeof(u32) / len )) != ((words + 1) * 100 * sizeof(u32) / len))
        {
            printf("\033[12D   % 2d%%", (words + 1) * 100 * sizeof(u32) / len );
        }
    }
    if(byte_left > 0)
    {
        u8  data8;
        u8  *dataP8 = (u8*)dataP;
        data = sflash_get_data();
        for(words = 0; words < byte_left; words++)
        {
            data8 = (u8)(data >> (words * 8));
            if(data8 != *dataP8++)
            {
                 printf("error\n");
                 return -1;
            }
        }
        printf("\033[12D   % 2d%%", len * 100 / len );
    }
    printf("\033[12D\n");


    if(offset >= GD_SFLASH_16M_SIZE)
    {
        //restore to 0x00
        sflash_set_ext_addr(device, 0x00);
    }
    spi_release_bus(flash->spi);
    return ret;
}

static int sflash_erase(struct spi_flash *flash, u32 offset, size_t len)
{
    struct goke_spi_flash_t *goke_spi_flash = to_spi_flash(flash);
    goke_sflash_dev_s *device;
    unsigned long sector_bytes;
    u16 sectorFirst;
    u16 sectorIndex;
    u16 sector_count;
    int ret;

    device = goke_spi_flash->device;
    sector_bytes = device->sector_bytes;
    /*
     * This function currently uses sector erase only.
     * probably speed things up by using bulk erase
     * when possible.
     */

    if (offset % sector_bytes || len % sector_bytes)
    {
        debug("SF: Erase offset/length not multiple of sector size\n");
        return -1;
    }

    sectorFirst = (u16)(offset / sector_bytes);
    sector_count = (u16)(len / sector_bytes);

    ret = spi_claim_bus(flash->spi);
    if (ret)
    {
        debug("SF: Unable to claim SPI bus\n");
        return ret;
    }

    puts("\nErasing:\n");

    for (sectorIndex = sectorFirst;  sectorIndex < sectorFirst + sector_count; sectorIndex++)
    {
        ret = sflash_erase_sector(device, sectorIndex);
        if (ret < 0)
        {
            debug("SF: page erase failed\n");
            break;
        }

        printf("\033[12D   % 2d%%", (sectorIndex - sectorFirst + 1) * 100 / sector_count);
    }
    printf("\033[12D\n");
    debug("SF: Successfully erased %ld bytes @ 0x%x\n", sector_bytes * len, offset);

    spi_release_bus(flash->spi);
    return ret;
}

static struct spi_flash *sflash_probe(struct spi_slave *spi, goke_sflash_dev_s *device)
{
    struct goke_spi_flash_t *goke_spi_flash;

    goke_spi_flash = malloc(sizeof(struct goke_spi_flash_t));
    if (!goke_spi_flash)
    {
        printf("SF: Failed to allocate memory\n");
        return NULL;
    }

    goke_spi_flash->device = device;
    goke_spi_flash->flash.spi = spi;
    goke_spi_flash->flash.name = device->device_name;

    goke_spi_flash->flash.write = sflash_write;
    goke_spi_flash->flash.erase = sflash_erase;
    goke_spi_flash->flash.read = sflash_read;
    goke_spi_flash->flash.size = device->page_bytes* device->sector_pages
        * device->sector_count;

#if CONFIG_BOARD_HARDWARE_INFO
    printf("SF:    ");
    print_size(goke_spi_flash->flash.size," ");
    printf("[page:");
    print_size(goke_spi_flash->device->page_bytes,"] ");
    printf("[sector:");
    print_size(goke_spi_flash->device->page_bytes * goke_spi_flash->device->sector_pages,"] ");
    printf("[count:%d] (%s)\n", goke_spi_flash->device->sector_count, device->device_name);
#endif  /* CONFIG_BOARD_HARDWARE_INFO */
    return &goke_spi_flash->flash;
}

static u32 check_magic_number(u32 offset, size_t len, const void *buf)
{
    u32 magic;
    if((offset != 0) || (len%4 != 0)){
        return 0;
    }
    magic = *(u32*)buf;
    if(magic == GK_UBOOT_HEADER_MAGIC){
        printf("uboot header magic match!\n");
        return 0;
    }
    else if(magic == BIG_LITTLE_SWITCH(GK_UBOOT_HEADER_MAGIC)) {
        printf("SF: big-endian to little-endian\n");
        return 1;
    }
    else {
        return 0;
    }
}
static void big_endian_to_little_endian(u32 offset, size_t len, void *buf)
{
    u32 data  = 0;
    u32 count = 0;
    u32 *pbuf = (u32 *)buf;
    for (count=0; count < len/sizeof(u32); count++) {
        data = *pbuf;
        *pbuf++ = BIG_LITTLE_SWITCH(data);
    }
    return;
}

