/*
 * (C) Copyright 2012
 * Goke Micro Limited
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

/*
 * GK6202 board specific data
 */ 

#define CONFIG_IDENT_STRING             " for GK6202 devkit (GOKE)"

/*Disable DCACHE */
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_SYS_ICACHE_OFF
#define CONFIG_SYS_L2CACHE_FIRST

/*Config GK6202 OS(Default:Linux)*/
//#define CONFIG_GK6202_ANDROID
#define CONFIG_SYS_USE_SPIFLASH

/*Reserved Memory For Other Module*/
#define CONFIG_RESERVED_MEMORY_SIZE             0x02000000

/*GK6202 DDR Size */
#define CONFIG_DDR_SIZE_1G
//#define CONFIG_DDR_SIZE_2G

/* total memory available to uboot */
#define CONFIG_SYS_UBOOT_SIZE		(8*1024 * 1024)

#ifdef CONFIG_GK6202_ANDROID
#define CONFIG_ANDROID_PARTITION_CACHE          "cache"
#define CONFIG_ANDROID_PARTITION_BOOT           "boot"
#define CONFIG_ANDROID_PARTITION_MISC          "misc"
#define CONFIG_ANDROID_PARTITION_RECOVERY		"recovery"
#ifdef CONFIG_CHECK_RECOVERY_COMMAND_FILE
#define CONFIG_ANDROID_RECOVERY_COMMAND_FILE "/cache/recovery/command"
#endif
#endif
/* 
 *Physical Memory Map
 */
/* GK6202_EVB has 2 banks of DDR, but we use only one in U-Boot */

#define CONFIG_SYS_SDRAM_BASE           0xC0000000
#if defined(CONFIG_DDR_SIZE_1G)
#define CONFIG_SYS_SDRAM_SIZE           0x08000000 /* 128 MB */
#elif defined(CONFIG_DDR_SIZE_2G)
#define CONFIG_SYS_SDRAM_SIZE           0x10000000 /* 256 MB */
#endif

#define CONFIG_SYS_MEMTEST_START       (CONFIG_SYS_SDRAM_BASE + CONFIG_RESERVED_MEMORY_SIZE)
#define CONFIG_SYS_MEMTEST_END         (CONFIG_SYS_SDRAM_BASE + CONFIG_SYS_SDRAM_SIZE - CONFIG_SYS_UBOOT_SIZE) 

#define CONFIG_NR_DRAM_BANKS            1   /* we have 1 bank of DDR RAM */

#define PHYS_SDRAM_1                     CONFIG_SYS_SDRAM_BASE
#define PHYS_SDRAM_1_SIZE               CONFIG_SYS_SDRAM_SIZE


/* 
 *Size of malloc() pool 
 */
#define CONFIG_SYS_MALLOC_LEN           (CONFIG_ENV_SIZE + 128 * 1024 * 5)


/* Kewell modified 2013-8-16 >> */

//#define CONFIG_SPINANDBOOT

#if defined(CONFIG_SPINANDBOOT)
#define CONFIG_SYS_USE_SPINANDFLASH
#undef CONFIG_SYS_USE_SPIFLASH
#else
#define CONFIG_SYS_USE_SPIFLASH
#undef CONFIG_SYS_USE_SPINANDFLASH
#endif

/*
 *env config
 */
#if defined(CONFIG_SYS_USE_SPINANDFLASH)

/* bootstrap + u-boot + env + linux in nandflash */
#define CONFIG_ENV_IS_IN_SPINAND
#define CONFIG_ENV_OFFSET       0xc0000
#define CONFIG_ENV_SIZE         0x2000     /* 1 sector = 128 kB */

/*                                "root=/dev/mtdblock1 rw "   \
                                    "mem=64m" */
#define CONFIG_BOOTARGS         "console=ttyAMA0,115200 "   \
                                "root=/dev/nfs rw "  \
                                "nfsroot=192.168.1.100:/opt/ubq/devkit/arm/arm11/target "   \
                                "ip=192.168.1.101::192.168.1.1:255.255.255.0:h61linux:eth0:off mem=64m"

#define CONFIG_BOOTCOMMAND      "snand read " \
                                "0x01008000 0x800000 0x700000; " \
                                "bootm 0x01008000"

#elif defined(CONFIG_SYS_USE_SPIFLASH)

/* bootstrap + u-boot + env + linux in spi flash */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET           0x1f0000
#define CONFIG_ENV_SIZE             0x2000

#endif
/* Kewell modified 2013-8-16 << */
/*
 *allow to overwrite serial and ethaddr 
 */
#define CONFIG_ENV_OVERWRITE

/* Kewell modified 2013-8-16 >> */

#define CONFIG_ENV_OFFSET               (0x1f0000)
#define CONFIG_ENV_SIZE                 (0x2000)

/* Kewell modified 2013-8-16 << */

#define CONFIG_ENV_ADDR                 (CONFIG_ENV_OFFSET)
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_PROMPT               "GK6202 # "

/* 
 *Command interface options
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_SF
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_ELF
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PING
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

#ifdef  CONFIG_SYS_HUSH_PARSER
   #define CONFIG_SYS_PROMPT_HUSH_PS2   "> "
#endif


/* 
 *High Level Configuration Options 
 */
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_SDRAM_BASE + \
	CONFIG_RESERVED_MEMORY_SIZE + 0x10000 - GENERATED_GBL_DATA_SIZE)
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ            (4 * 1024)   /* IRQ stack */
#define CONFIG_STACKSIZE_FIQ            (4 * 1024)   /* FIQ stack */
#endif


/* 
 *Buffers 
 */
#define CONFIG_SYS_CBSIZE               1024      /* Console I/O Buffer Size */

/* 
 *Print Buffer Size 
 */
#define CONFIG_SYS_PBSIZE              (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)

/* 
 *Boot Argument Buffer Size 
 */
#define CONFIG_SYS_BARGSIZE            (CONFIG_SYS_CBSIZE)

/*-----------------------------------------------------------------------
 * Hardware drivers
 -----------------------------------------------------------------------*/	
/* 
 *Timer 
 */
#define CONFIG_SYS_HZ                   1000

/* 
 *UART & serial 
 */
#define CONFIG_PL011_SERIAL 
#define CONFIG_PL011_CLOCK              40500000 /* 100000000 */
#define CONFIG_PL01x_PORTS              {(void *)0xC4000000}
#define CONFIG_CONS_INDEX               0
#define CONFIG_BAUDRATE                 115200
#define CONFIG_SYS_BAUDRATE_TABLE       { 9600, 19200, 38400, 57600, 115200 }

/* 
 *Ethernet 
 */
/* #define CONFIG_NET_MULTI */
//#define CONFIG_DRIVER_FMAC3H
//#define CONFIG_MII


/* 
 *SPI FLASH 
 */

#define CONFIG_SPI_CTRL_GOKE

#define CONFIG_ENV_SECT_SIZE            (0x00010000)
#define CONFIG_SYS_MAX_FLASH_SECT       (128)
#define CONFIG_SYS_MAX_FLASH_BANKS      1
#define CONFIG_SYS_FLASH_BASE           0x00000000
#define CONFIG_SYS_FLASH_EMPTY_INFO     /* flinfo indicates empty blocks */

/*
 *NAND FLASH 
 */
/* Kewell added for spinand 2013-8-5 >> */
#define CONFIG_CMD_NAND
#define CONFIG_CMD_SPINAND
#define CONFIG_GK6202_SPINAND
#if defined(CONFIG_CMD_NAND)
#define CONFIG_SYS_NAND_SELF_INIT
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#endif
/* Kewell added for spinand 2013-8-5 << */

/*
 * USB
 */
#if 0
#define CONFIG_CMD_USB
#define CONFIG_MUSB_HCD
#define CONFIG_USB_GK6202
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION		1
#define CONFIG_MUSB_TIMEOUT 2000   // the timer isn't correct(udelay failed), so we set timeout value from 100000 (100ms)to 2000;
#endif

/* 
 *MTD Support 
 */
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS			1
#define MTDIDS_DEFAULT					"spinand0=GK6202-spinand"
#ifdef CONFIG_GK6202_ANDROID
#define MTDPARTS_DEFAULT				"mtdparts=GK6202-spinand:4m@0x100000(boot)ro,6m@0x500000(recovery)," \
"1m@0xb00000(misc),100m@0xc00000(system),20m@0x7000000(cache),20m@0x8400000(backup)," \
"-(userdata)"
#else
#define MTDPARTS_DEFAULT ""
#endif

/* 
 *UBIFS Support 
 */
//#define CONFIG_CMD_UBI					1
//#define CONFIG_CMD_MTDPARTS			1
//#define CONFIG_RBTREE						1
//#define CONFIG_CMD_UBIFS				1
//#define CONFIG_LZO							1

/*
 *Yaffs2 SF Support
*/
//#define CONFIG_USB_HOST_ETHER 			
//#define CONFIG_USB_ETHER_ASIX
//#define CONFIG_USB_ETHER_SMSC95XX 



/*
 *Boot zImage and Image
 */
#define CONFIG_GK6202_EVB
#define CONFIG_CMD_BOOTZ

/*
 * Enable device tree support
 */
#ifndef CONFIG_GK6202_ANDROID
#define CONFIG_OF_LIBFDT				1
#endif
/*-----------------------------------------------------------------------
 * Boot parameters
 -----------------------------------------------------------------------*/
//#define CONFIG_FMAC3H
#define CONFIG_HOSTNAME                 "gk6202_evb"
#define CONFIG_ETHADDR                  00:0b:5d:af:f9:0a
#define CONFIG_IPADDR                   192.168.1.101
#define CONFIG_GATEWAYIP                192.168.1.1
#define CONFIG_NETMASK                  255.255.255.0
#define CONFIG_SERVERIP                 192.168.1.100

#define CONFIG_ROOTPATH		             "/opt/work"
#define CONFIG_BOOTFILE                 "zImage"          /* file to load */
#define CONFIG_LOADADDR                 0x02008000       /* default load address */
#define CONFIG_SYS_LOAD_ADDR           CONFIG_LOADADDR       /* default load address */

#define CONFIG_CMDLINE_TAG              1                /* enable passing cmdline */
#define CONFIG_SETUP_MEMORY_TAGS        1
#ifdef CONFIG_GK6202_ANDROID
#define CONFIG_INITRD_TAG					1
#endif
#define CONFIG_SYS_MAXARGS              64               /* max number of command args */

#define CONFIG_BOOTDELAY                5
#define CONFIG_ZERO_BOOTDELAY_CHECK

#if !defined(CONFIG_SYS_USE_SPINANDFLASH)
#undef  CONFIG_BOOTARGS										/* the boot command will set bootargs */

#define	CONFIG_EXTRA_ENV_SETTINGS				\
	"netdev=eth0\0"						\
	"consoledev=ttyAMA0\0"				\
	"sfboot=sf probe 0 0;sf read ${loadaddr} 0x400000 0x400000; bootm\0" \
	"mtdids=" MTDIDS_DEFAULT "\0"					\
	"mtdparts=" MTDPARTS_DEFAULT "\0"				
#ifdef CONFIG_GK6202_ANDROID
#define CONFIG_BOOTCOMMAND          \
	"setenv bootargs console=${consoledev},${baudrate}"	\
	"${mtdparts} init=/init mem=88m;snboot"
#else
#define CONFIG_BOOTCOMMAND          \
	"setenv bootargs console=${consoledev},${baudrate}"	\
	" root=/dev/nfs rw "	\
	"nfsroot=${serverip}:${rootpath} "		\
	"ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}:${netdev}:off mem=96m;" \
	"run sfboot"
#endif
#endif

#endif   /* __CONFIG_H */
