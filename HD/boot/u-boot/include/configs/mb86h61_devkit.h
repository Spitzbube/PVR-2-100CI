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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_IDENT_STRING             " for MB86H61 devkit (Fujitsu Semiconductor)"

/*-----------------------------------------------------------------------
 * Your favorites
 -----------------------------------------------------------------------*/

/* U-boot layout in SDRAM and/or Flash */
/* base address for uboot */
#define CONFIG_SYS_UBOOT_STACK_SETUP_BASE		(CONFIG_SYS_SDRAM_BASE + 0x01000000)
#define CONFIG_SYS_UBOOT_TEXT_BASE				(CONFIG_SYS_SDRAM_BASE + 0x03e00000)
/* total memory available to uboot */
#define CONFIG_SYS_UBOOT_SIZE           (1024 * 1024)

/*
   env config
*/
#define CONFIG_ENV_IS_IN_SPI_FLASH
#ifndef CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_IS_IN_NAND
#endif
#define CONFIG_ENV_SIZE                 8192//0x80000    /* on memory */
#define FLASH_TOP                       (CONFIG_SYS_FLASH_BASE + PHYS_FLASH_SIZE)

#ifdef CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET                 0x100000
#else
#define CONFIG_ENV_OFFSET                 0x100000
#endif
#define CONFIG_ENV_ADDR               CONFIG_ENV_OFFSET

#define CONFIG_SYS_MONITOR_LEN          (2 * CONFIG_ENV_SECT_SIZE)
#define CONFIG_SYS_MONITOR_BASE         (CONFIG_ENV_ADDR - CONFIG_SYS_MONITOR_LEN)

#define CONFIG_FMAC3H_BUF               (CONFIG_SYS_SDRAM_BASE + 0x03f00000)
/*
 * Command interface options
 */

#include <config_cmd_default.h>

#if 0
#define CONFIG_CMD_USB
#define CONFIG_MUSB_HCD
//#define CONFIG_MUSB_UDC
#define CONFIG_USB_MB86H6X
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_FAT
#endif
////#define CONFIG_USB_DEVICE


#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_ELF
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PING
#define CONFIG_CMD_SF
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

#define CONFIG_SYS_LONGHELP             /* undef to save memory */
#define CONFIG_SYS_PROMPT               "MB86H61 # "

#ifdef  CONFIG_SYS_HUSH_PARSER
   #define CONFIG_SYS_PROMPT_HUSH_PS2   "> "
#endif

/*
 * Miscellaneous parameters
 */
#define CONFIG_ENV_OVERWRITE    /* allow to overwrite serial and ethaddr */
#define CONFIG_DOS_PARTITION            1

#if (CONFIG_COMMANDS & CONFIG_CMD_KGDB)
   #define CONFIG_KGDB_BAUDRATE         115200   /* speed to run kgdb serial port */
   #define CONFIG_KGDB_SER_INDEX        1      /* which serial port to use    */
#endif

/*-----------------------------------------------------------------------
 * Architecture and/or Board-specific data
 * - You don't need to edit these normally.
 -----------------------------------------------------------------------*/
/*
 * High Level Configuration Options
 * (easy to change)
 */

#define CONFIG_MB86H61_DEVKIT            1
#define CONFIG_MB86H61_DEVKIT_LOGO               1
#define CONFIG_LOGO_WIDTH_MAX		960
#define CONFIG_LOGO_HEIGHT_MAX		540

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

/*
 * Architecture magic and machine type
 */
//!!MNG, 0xa3c for H60 ,0xa3d for H61
#define MACH_TYPE                       0xa3d
                                 /* FIXME: Use MACH_XX in mach-types.h */
/*
 * Physical Memory Map
 */
#define CONFIG_MEM_SIZE_RAMIFS            0x08000000 /* 128MB */
#if (CONFIG_MEM_SIZE_RAMIFS == 0)
#define CONFIG_SINGLE_DDR_SYSTEM
#endif

#ifndef  CONFIG_SINGLE_DDR_SYSTEM
#define CONFIG_SYS_MEMTEST_START        0x20000000
#define CONFIG_SYS_MEMTEST_END             0x23E00000

#define CONFIG_SYS_SDRAM_BASE              0x20000000
#else
#define CONFIG_SYS_MEMTEST_START        0x40000000
#define CONFIG_SYS_MEMTEST_END             0x43E00000
#define CONFIG_FIRM_FRAME_BUFFER_SIZE   0x02000000

#define CONFIG_SYS_SDRAM_BASE           0x40000000
#endif
#define CONFIG_SYS_SDRAM_SIZE           0x08000000   /* 128 MB */

#define CONFIG_NR_DRAM_BANKS            1   /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1                    CONFIG_SYS_SDRAM_BASE   /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE               CONFIG_SYS_SDRAM_SIZE   /* 128 MB */
#define CONFIG_FIRMWARE_EMBEDDED
#ifndef CONFIG_FIRMWARE_EMBEDDED
#define CONFIG_FIRMWARE_SIZE 0x100000
#define CONIFG_FIRMWARE_EXTERNAL
#endif
/*
 *ARC Register
 */
#define IRQ_CTRL_ARCSTATUS 0xCF000210
#define IRQ_CTRL_ARCJMPADDRESS 0xCF000214
#define FAPI_FLASH_DEVICE_PFLASH    0   //!< the parallel flash device
#define FAPI_FLASH_DEVICE_SFLASH    1   //!< the serial flash device
#define FAPI_FLASH_DEVICE_NFLASH    2   //!< the nand flash device

/*
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_SYS_INIT_SP_ADDR        CONFIG_SYS_UBOOT_STACK_SETUP_BASE - GENERATED_GBL_DATA_SIZE
#define CONFIG_STACKSIZE                (128 * 1024)   /* regular stack */
#ifndef CONFIG_USE_IRQ
#define CONFIG_USE_IRQ      1			/* Viscale need interrupt */
#endif
#define CONFIG_STACKSIZE_IRQ         (4 * 1024)   /* IRQ stack */
#define CONFIG_STACKSIZE_FIQ         (4 * 1024)   /* FIQ stack */

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN           (CONFIG_ENV_SIZE + 2280 * 1024)//(CONFIG_ENV_SIZE + 128 * 1024)

/* size in bytes reserved for initial data */
#define CONFIG_SYS_GBL_DATA_SIZE   128

/*
 * Buffers
 */
#define CONFIG_SYS_CBSIZE               1024      /* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE   \
         (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_BARGSIZE             CONFIG_SYS_CBSIZE /* Boot Argument Buffer Size */

/*-----------------------------------------------------------------------
 * Hardware drivers
 -----------------------------------------------------------------------*/
/*
 * Timer
 */
#define CONFIG_SYS_HZ                   1000

/*
 * UART & serial
 */
#define CONFIG_PL011_SERIAL
#define CONFIG_PL011_CLOCK              99000000
#define CONFIG_PL01x_PORTS              {(void *)CONFIG_SYS_SERIAL0, }
#define CONFIG_CONS_INDEX               0

#define CONFIG_BAUDRATE                 115200
#define CONFIG_SYS_BAUDRATE_TABLE       { 9600, 19200, 38400, 57600, 115200 }
#define CONFIG_SYS_SERIAL0              0xCD000000UL //MB86HXX_UART0_BASE

/*
 * Ethernet
 */
/* #define CONFIG_NET_MULTI */

#define CONFIG_DRIVER_FMAC3H
#define CONFIG_MII

/*
 * FLASH
 */
/*
 * Use the SPI flash driver for ease of use
 */
#define CONFIG_SPI_CTRL_FUJITSU


#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS

#if (!defined(CONFIG_NAND_SPL))&&0
#define CONFIG_ENABLE_MMU
#endif
#ifdef CONFIG_ENABLE_MMU
#define CONFIG_CMD_CACHE
#endif

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT     (2 * CONFIG_SYS_HZ) /* Erase Timeout */
#define CONFIG_SYS_FLASH_WRITE_TOUT     (2 * CONFIG_SYS_HZ) /* Write Timeout */

/*
 * Note that CONFIG_SYS_MAX_FLASH_SECT allows for a parameter block
 * i.e.
 *   the bottom "sector" (bottom boot), or top "sector"
 *   (top boot), is a seperate erase region divided into
 *   4 (equal) smaller sectors. This, notionally, allows
 *   quicker erase/rewrire of the most frequently changed
 *   area......
 *   CONFIG_SYS_MAX_FLASH_SECT is padded up to a multiple of 4
 */

#define FLASH_SECTOR_SIZE               0x00010000   /* 64 KB sectors */
#define CONFIG_ENV_SECT_SIZE            (1 * FLASH_SECTOR_SIZE)
#define CONFIG_SYS_MAX_FLASH_SECT       (128)


#define CONFIG_SYS_MAX_FLASH_BANKS      1
#define CONFIG_SYS_FLASH_BASE           0x00000000
#define PHYS_FLASH_SIZE                 0x01000000   /* 16M */

#define CONFIG_SYS_FLASH_EMPTY_INFO      /* flinfo indicates empty blocks */
/*
 * boot
 */
#define CONFIG_BOOTM_LINUX              1
/*
 * nand flash driver
 */
#define CONFIG_CMD_NAND                 1
#ifdef CONFIG_CMD_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#endif
#define CONFIG_NAND_MB86HXX
#ifdef CONFIG_NAND_MB86HXX
#define CONFIG_SYS_NAND_BASE            0x80000008UL
#define CONFIG_MB86H61_NAND_UPI0        1
#else
#define CONFIG_SYS_NAND_BASE            0xE8000000UL
#define CONFIG_NAND_MB86HXX_CTRL        1
#endif

#define CONFIG_FUJITSU_BOARDTYPE_MB86H61_FMC_DEVKIT
#ifndef CONFIG_FUJITSU_BOARDTYPE_MB86H61_FMC_DEVKIT
#define CONFIG_FUJITSU_BOARDTYPE_MB86H61_FME_DEVKIT
#ifndef CONFIG_FUJITSU_BOARDTYPE_MB86H61_FME_DEVKIT
#define CONFIG_FUJITSU_BOARDTYPE_MB86H612_FMC_DEVKIT
#endif
#endif

/*
* Support mtdparts and ubi and ubifs
*/
#if 1
#define CONFIG_CMD_UBI					1
#define CONFIG_CMD_MTDPARTS			1
#define CONFIG_RBTREE					1
#define CONFIG_CMD_UBIFS				1
#define CONFIG_LZO						1
#define MTDIDS_DEFAULT				"nand0=mb86h61-nand"
#define MTDPARTS_DEFAULT			"mtdparts=mb86h61-nand:6m@0x0(kernel),8m@0x600000(root-ubifs),114m@0xe00000(app-ubifs)"
#endif

//#define DEBUG  1
//#define CONFIG_MTD_DEBUG             1
//#define CONFIG_MTD_DEBUG_VERBOSE 3

/*-----------------------------------------------------------------------
 * Boot parameters
 -----------------------------------------------------------------------*/

#define CONFIG_FMAC3H
#define CONFIG_HOSTNAME                 "mb86h61_devkit"
#define CONFIG_ETHADDR                  00:0b:5d:af:f9:0a
#define CONFIG_IPADDR                   192.168.1.101
#define CONFIG_GATEWAYIP                192.168.1.1
#define CONFIG_NETMASK                  255.255.255.0

#define CONFIG_SERVERIP                 192.168.1.100
#define CONFIG_BOOTFILE                 "zImage"          /* file to load */

#ifndef  CONFIG_SINGLE_DDR_SYSTEM
#define CONFIG_LOADADDR                 0x22a08000       /* default load address */
#define CONFIG_SYS_LOAD_ADDR            0x22a08000       /* default load address */
#else
#define CONFIG_LOADADDR                 0x42a08000       /* default load address */
#define CONFIG_SYS_LOAD_ADDR            0x42a08000       /* default load address */
#endif

#define CONFIG_CMDLINE_TAG              1                /* enable passing cmdline */
#define CONFIG_SETUP_MEMORY_TAGS        1
#define CONFIG_SYS_MAXARGS              64               /* max number of command args */

#define CONFIG_BOOTDELAY                1
#define CONFIG_ZERO_BOOTDELAY_CHECK

#ifndef  CONFIG_SINGLE_DDR_SYSTEM
#define CONFIG_BOOTARGS                 "console=ttyAMA0,115200 root=/dev/nfs rw nfsroot=192.168.1.100:/opt/ubq/devkit/arm/arm11/target ip=192.168.1.101::192.168.1.1:255.255.255.0:h61linux:eth0:off mem=64m"
#define CONFIG_BOOTCOMMAND              "tftp 0x22a08000 zImage; bootm"
#else
#define CONFIG_BOOTARGS                 "console=ttyAMA0,115200 root=/dev/nfs rw nfsroot=192.168.1.100:/opt/ubq/devkit/arm/arm11/target ip=192.168.1.101::192.168.1.1:255.255.255.0:h61linux:eth0:off"
#define CONFIG_BOOTCOMMAND              "tftp 0x42a08000 zImage; bootm"
#endif
/*
 * BOOTP options
 */
#if 0
   #define CONFIG_BOOTP_BOOTPATH
   #define CONFIG_BOOTP_GATEWAY
   #define CONFIG_BOOTP_HOSTNAME
   #define CONFIG_BOOTP_SUBNETMASK
#endif

#endif   /* __CONFIG_H */
