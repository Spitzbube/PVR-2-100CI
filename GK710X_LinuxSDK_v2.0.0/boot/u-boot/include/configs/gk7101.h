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

#define CONFIG_CPU_GK710X


// note: add a new board
// 1. add a gpio map file at arch\arm\include\asm\arch-gk7101
// 2. add a board define at include\configs\gk7101.h
/*
 * GK7101 board
 */
//#define CONFIG_MACH_GK7101_FPGA
//#define CONFIG_MACH_GK7101_EVB
//#define CONFIG_MACH_GK7101_EVB_V2_0
#define CONFIG_MACH_GK7102_RTOS_EVB_V1_0
//#define CONFIG_MACH_GK7101_RB_V1_00
//#define CONFIG_MACH_GK7101_RB_V1_10
//#define CONFIG_MACH_GK7101_RB_IMX222_V1_00
//#define CONFIG_MACH_GK7102_RB_IMX225_V1_00
//#define CONFIG_MACH_GK7101_RB_OV2710_V1_00
//#define CONFIG_MACH_GK7101_RB_OV2710_V2_00
//#define CONFIG_MACH_GK7101_RB_OV2710_V2_10
//#define CONFIG_MACH_GK7101_RB_OV2710_V2_20
//#define CONFIG_MACH_GK7102_RB_OV9712_V1_00
//#define CONFIG_MACH_GK7102_RB_OV9750_V1_00
//#define CONFIG_MACH_GK7102_RB_AR0130_V1_00
//#define CONFIG_MACH_GK7101_RB_AR0230_V1_00
//#define CONFIG_MACH_GK7102_RB_JXH42_V1_00
//#define CONFIG_MACH_GK7102_RB_JXH42_V2_00
//#define CONFIG_MACH_GK7102_RB_BG0703_V1_00
//#define CONFIG_MACH_GK7101_RB_PS1210_V1_00
//#define CONFIG_MACH_GK7101_HSL_E681XA4_V1_20
//#define CONFIG_MACH_GK7101_KST_OV2710_V1_00
//#define CONFIG_MACH_GK7102_KST_JXH42_V1_00
//#define CONFIG_MACH_GK7102_KST_SC1035_V1_00
//#define CONFIG_MACH_GK7102_RB_SC1035_V2_10
//#define CONFIG_MACH_GK7102_RB_SC1045_V2_00
//#define CONFIG_MACH_GK7102_AK_GC1024_V1_00

/*
 * GK7101 board specific data
 */
#define BOARD_VERSION(a, b) (((a) << 16) + (b))
#define BOARD_MK_STR1(x)     #x
#define BOARD_MK_STR(x)     BOARD_MK_STR1(x)

// TODO: board info configure
#if defined(CONFIG_MACH_GK7101_FPGA)
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "fpga"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_EVB)
#define CONFIG_SYSTEM_USE_EXTERN_I2S
#define CONFIG_SYSTEM_USE_SDCARD
#define CONFIG_PHY_USE_EXTERN_CLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "devkit-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_EVB_V2_0)
#define CONFIG_SYSTEM_USE_EXTERN_I2S
#define CONFIG_SYSTEM_USE_SDCARD
#define CONFIG_PHY_USE_EXTERN_CLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "devkit-v2.0"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RTOS_EVB_V1_0)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rtos-devkit-v1.1"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_V1_00)
#define CONFIG_PHY_USE_EXTERN_CLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_V1_10)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-v1.1"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.1
#define CONFIG_BOARD_VERSION_MINOR      1

#elif defined(CONFIG_MACH_GK7101_RB_IMX222_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-imx222"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_IMX225_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb imx225"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_OV2710_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-ov2710-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_OV2710_V2_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-ov2710-v2.0"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v2.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_OV2710_V2_10)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-ov2710-v2.1"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v2.1
#define CONFIG_BOARD_VERSION_MINOR      1

#elif defined(CONFIG_MACH_GK7101_RB_OV2710_V2_20)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-ov2710-v2.2"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v2.2
#define CONFIG_BOARD_VERSION_MINOR      2

#elif defined(CONFIG_MACH_GK7102_RB_OV9712_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-ov9712-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_OV9750_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-ov9750-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_AR0130_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-ar0130-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_AR0230_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-ar0230-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_JXH42_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-jxh42-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_JXH42_V2_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-jxh42-v2.0"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v2.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_BG0703_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-bg0703-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_RB_PS1210_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "rb-ps1210-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7101_KST_OV2710_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7101
#define CONFIG_BOARD_TYPE               "kst-ov2710-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_KST_JXH42_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "kst-jxh42-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_KST_SC1035_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "kst-sc1035-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v1.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_RB_SC1035_V2_10)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-sc1035-v2.1"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v2.1
#define CONFIG_BOARD_VERSION_MINOR      1

#elif defined(CONFIG_MACH_GK7102_RB_SC1045_V2_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "rb-sc1045-v2.0"
#define CONFIG_BOARD_VERSION_MAJOR      2       //v2.0
#define CONFIG_BOARD_VERSION_MINOR      0

#elif defined(CONFIG_MACH_GK7102_AK_GC1024_V1_00)
#define CONFIG_PHY_USE_AO_MCLK
#define CONFIG_CPU_GK7102
#define CONFIG_BOARD_TYPE               "AK-gc1024-v1.0"
#define CONFIG_BOARD_VERSION_MAJOR      1       //v2.0
#define CONFIG_BOARD_VERSION_MINOR      0

#else
#error "Undefine gpio configure header file or no support. "
#endif


#define CONFIG_BOARD_VARSION_CODE       BOARD_VERSION(CONFIG_BOARD_VERSION_MAJOR, CONFIG_BOARD_VERSION_MINOR)

#if defined(CONFIG_CPU_GK7101)
#define CONFIG_IDENT_STRING             " for GK7101 " CONFIG_BOARD_TYPE " (GOKE)"
#elif defined(CONFIG_CPU_GK7102)
#define CONFIG_IDENT_STRING             " for GK7102 " CONFIG_BOARD_TYPE " (GOKE)"
#endif

/* Uboot Debug information */
#define CONFIG_BOARD_HARDWARE_INFO  1

/*Disable DCACHE */
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_SYS_ICACHE_OFF

/*Config GK7101 OS(Default:Linux)*/
#define CONFIG_SYS_USE_SPIFLASH

/* total memory available to uboot */
#define CONFIG_SYS_UBOOT_SIZE           (8*1024 * 1024)

#define CONFIG_BOARD_EARLY_INIT_F

/*
 *Physical Memory Map
 */

#define CONFIG_SYS_SDRAM_BASE           0xC0000000

#define CONFIG_USR_SDRAM_SIZE           0x10000    /* 64K */


#define CONFIG_SYS_TEXT_BASE            0xC0800000

#define CONFIG_SYS_MEMTEST_START       (CONFIG_SYS_SDRAM_BASE)
#define CONFIG_SYS_MEMTEST_END         (CONFIG_SYS_SDRAM_BASE - CONFIG_SYS_UBOOT_SIZE)

#define CONFIG_NR_DRAM_BANKS            1   /* we have 1 bank of DDR RAM */

/*
 *Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN           (CONFIG_ENV_SIZE + 128 * 1024 * 5)

/*
 *env config
 */
/* bootstrap + u-boot + env + linux in spi flash */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET               0x40000
#define CONFIG_ENV_SIZE                 0x10000

/*
 *allow to overwrite serial and ethaddr
 */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_ENV_ADDR                 (CONFIG_ENV_OFFSET)
#define CONFIG_SYS_LONGHELP


#if defined(CONFIG_CPU_GK7101)
#define CONFIG_SYS_PROMPT               "GK7101 # "
#define CONFIG_CHIP_NAME                "gk7101"

#elif defined (CONFIG_CPU_GK7102)
#define CONFIG_SYS_PROMPT               "GK7102 # "
#define CONFIG_CHIP_NAME                "gk7102"

#endif

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

/*
 *High Level Configuration Options
 */
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_SDRAM_BASE + 0x100000 - GENERATED_GBL_DATA_SIZE)




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
 *GPIO
 */
#define CONFIG_GK7101_GPIO
/*
 *Timer
 */
#define CONFIG_SYS_HZ                   1000

/*
 *UART & serial
 */
#define CONFIG_GK7101_SERIAL
#define CONFIG_CONS_INDEX               0
#define CONFIG_BAUDRATE                 115200
#define CONFIG_SYS_BAUDRATE_TABLE       { 4800, 9600, 19200, 38400, 57600, 115200 }

/*
 *Ethernet
 */
#define CONFIG_DRIVER_GK7101ETH

/*
 *mmc driver  SUPORT SD CARD
 */
//#define CONFIG_CMD_MMC_UPDATE
#ifdef CONFIG_CMD_MMC_UPDATE
#define CONFIG_USE_IRQ
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ            (4 * 1024)   /* IRQ stack */
#define CONFIG_STACKSIZE_FIQ            (4 * 1024)   /* FIQ stack */
#endif

#define CONFIG_GENERIC_MMC
#define CONFIG_SPL_LIBDISK_SUPPORT

#define CONFIG_CMD_MMC
#define CONFIG_MMC
#define CONFIG_MMC_GK
#define CONFIG_MMC_WIDE
#define CONFIG_MMC_FAT
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_FAT
#define CONFIG_SUPPORT_VFAT
#define CONFIG_FS_FAT
#define CONFIG_FAT_WRITE


#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_SYSTEM_USE_SDCARD
#endif
/*
 *SPI NANDFLASH
 */
#define CONFIG_GK7101_SPINAND
#define CONFIG_CMD_NAND
#define CONFIG_CMD_SPINAND
#define CONFIG_SYS_NAND_SELF_INIT
#define CONFIG_GK7101_SPINANDFLASH
#define CONFIG_SYS_MAX_NAND_DEVICE      1

/*
 *SPI FLASH
 */
#define CONFIG_GK7101_SFLASH
#define CONFIG_ENV_SECT_SIZE            (0x00010000)
#define CONFIG_SYS_MAX_FLASH_SECT       (128)
#define CONFIG_SYS_MAX_FLASH_BANKS      1
#define CONFIG_SYS_FLASH_BASE           0x00000000
#define CONFIG_SYS_FLASH_EMPTY_INFO     /* flinfo indicates empty blocks */

/*
 * USB
 */
#if 0
#define CONFIG_CMD_USB
#define CONFIG_MUSB_HCD
#define CONFIG_USB_GK7101
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION        1
#define CONFIG_MUSB_TIMEOUT 2000   // the timer isn't correct(udelay failed), so we set timeout value from 100000 (100ms)to 2000;
#endif

/*
 *MTD Support
 */
#undef CONFIG_MTD_DEVICE
#undef CONFIG_MTD_PARTITIONS
#undef CONFIG_CMD_MTDPARTS
//#define MTDIDS_DEFAULT                    "spinand0=GK7101-spinand"
//#define MTDPARTS_DEFAULT ""

/*
 *UBIFS Support
 */
//#define CONFIG_CMD_UBI                1
//#define CONFIG_CMD_MTDPARTS           1
//#define CONFIG_RBTREE                 1
//#define CONFIG_CMD_UBIFS              1
//#define CONFIG_LZO                    1

/*
 *Boot zImage and Image
 */
#define CONFIG_GK7101
#define CONFIG_CMD_BOOTZ
#define CONFIG_UBOOT_TO_KERNEL			1


#define CONFIG_GK_HAL_ADDR              0xC0012000

#define CONFIG_U2K_PHY_TYPE             0xC0000000
#define CONFIG_U2K_ARM_FREQ             0xC0000004
#define CONFIG_U2K_HAL_ADDR             0xC0000008

#define CONFIG_U2K_SOC_ADDR             0xC0000010		//0:7101, 1:7102
#define CONFIG_U2K_MEM_ADDR             0xC0000014
#define CONFIG_U2K_BSB_ADDR             0xC0000018
#define CONFIG_U2K_DSP_ADDR             0xC000001C
#define CONFIG_U2K_ENABLE               0xC0000020

#define CONFIG_U2K_USR_ADDR             0xC0000024

#define CONFIG_U2K_TOTAL_MEM            0xC0000028


/*-----------------------------------------------------------------------
 * Boot parameters
 -----------------------------------------------------------------------*/
#if defined(CONFIG_CPU_GK7101)
#define CONFIG_HOSTNAME                 "gk7101"
#elif defined (CONFIG_CPU_GK7102)
#define CONFIG_HOSTNAME                 "gk7102"
#endif

/* definition SOC types */
#define CONFIG_SOC_GK7101           0
#define CONFIG_SOC_GK7102           1

#define CONFIG_ETHADDR                  3C:97:0E:22:E1:14
#define CONFIG_IPADDR                   11.1.4.200
#define CONFIG_GATEWAYIP                11.1.4.1
#define CONFIG_NETMASK                  255.255.255.0
#define CONFIG_SERVERIP                 11.1.4.19
#define CONFIG_ROOTPATH                 "/opt/work"
#define CONFIG_BOOTFILE                 "zImage"            /* file to load */
#define CONFIG_LOADADDR                 0xC1000000          /* default load address */
#define CONFIG_SYS_LOAD_ADDR            CONFIG_LOADADDR     /* default load address */
#define CONFIG_CMDLINE_TAG              1                   /* enable passing cmdline */
#define CONFIG_SETUP_MEMORY_TAGS        1
#define CONFIG_SYS_MAXARGS              64                  /* max number of command args */
#define CONFIG_BOOTDELAY                5
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_USE_EXT_PHY              0

#if defined(CONFIG_CPU_GK7101)
#define CONFIG_SOC_TYPE					CONFIG_SOC_GK7101		//0:7101, 1:7102
#define CONFIG_KERNEL_MEM_SIZE			50		//MB
#define CONFIG_BSB_MEM_SIZE				4		//MB
#define CONFIG_USR_MEM_SIZE				0		//MB
#elif defined (CONFIG_CPU_GK7102)
#define CONFIG_SOC_TYPE					CONFIG_SOC_GK7102		//0:7101, 1:7102
#define CONFIG_KERNEL_MEM_SIZE			36		//MB
#define CONFIG_BSB_MEM_SIZE				2		//MB
#define CONFIG_USR_MEM_SIZE				0		//MB
#endif

#undef  CONFIG_BOOTARGS                                     /* the boot command will set bootargs */

#define CONFIG_EXTRA_ENV_SETTINGS           \
    "arm_freq=0x00112032\0"                 \
    "mem=" BOARD_MK_STR(CONFIG_KERNEL_MEM_SIZE) "M\0"                         \
    "bsbsize=" BOARD_MK_STR(CONFIG_BSB_MEM_SIZE) "M\0"                         \
    "netdev=eth0\0"                         \
    "consoledev=ttySGK0\0"                  \
    "rootfstype=ubi.mtd=3 rootfstype=ubifs root=ubi0:rootfs\0"  \
    "sfkernel=0x50000\0"  \
    "sfboot=setenv bootargs console=${consoledev},${baudrate} noinitrd mem=${mem} rw ${rootfstype} init=linuxrc ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}:${netdev} mac=${ethaddr} phytype=${phytype};sf probe 0 0;sf read ${loadaddr} ${sfkernel} ${filesize}; bootm\0"    \
    "nfsserver=11.1.4.19\0"                        \
    "tftpboot=setenv bootargs root=/dev/nfs nfsroot=${nfsserver}:${rootpath},proto=tcp,nfsvers=3,nolock ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}:${netdev} mac=${ethaddr} phytype=${phytype} console=${consoledev},${baudrate} mem=${mem};tftpboot ${bootfile};bootm\0"

#define CONFIG_BOOTCOMMAND          \
    "run tftpboot"

#endif   /* __CONFIG_H */
