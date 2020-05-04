/*
 * arch/arm/mach-mb86hxx/include/mach/clkpwr.h
 *
 * Copyright (C) 2009 FUJITSU MICROELECTRONICS LIMITED
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
#ifndef __ARCH_ARM_MACH_CLKPWR_H
#define __ARCH_ARM_MACH_CLKPWR_H

/*
 * Register Offset Address from MB86HXX_CLKPWR_BASE
 */
#define CLKPWR_CLK324ENABLE	0x00000000
#define CLKPWR_CLK162ENABLE	0x00000004
#define CLKPWR_CLK81ENABLE	0x00000008
#define CLKPWR_CLK104ENABLE	0x0000000C
#define CLKPWR_SOFTRESET324	0x00000014
#define CLKPWR_SOFTRESET162	0x00000018
#define CLKPWR_SOFTRESET81	0x0000001C
#define CLKPWR_SOFTRESET108	0x00000020
#define CLKPWR_SOFTRESET54	0x00000024

#define CLKPWR_WATCHDOG		0x0000003C

#define CLKPWR_CONFIGARM	0x00000070
#define CLKPWR_CONFIGAUDIO	0x00000074

/*
 * CLK162ENALBE bit definition
 */
#define CLK_162_UPI_EN		(1<<2)
#define CLK_162_DDR_EN		(1<<1)
#define CLK_162_AXI_EN		(1<<0)

/*
 * CLK81ENALBE bit definition
 */
#define CLK_81_UPI_EN		(1<<8)
#define CLK_81_SFLASH_EN	(1<<7)
#define CLK_81_SSP_EN		(1<<6)
#define CLK_81_UART_EN		(1<<5)
#define CLK_81_I2C2_EN		(1<<4)
#define CLK_81_I2C_EN		(1<<3)
#define CLK_81_GPIO_EN		(1<<2)
#define CLK_81_PERI_EN		(1<<1)
#define CLK_81_AXI_EN		(1<<0)

/*
 * SOFTRESET81 bit definition
 */
#define RESET_SFLASH		(1<<8)
#define RESET_SSP		(1<<7)
#define RESET_UART		(1<<6)
#define RESET_I2C2		(1<<5)
#define RESET_I2C		(1<<4)
#define RESET_ICC		(1<<3)
#define RESET_GPIO		(1<<2)
#define RESET_IRQCTRL		(1<<1)

/*
 * WATCHDOG bit definition
 */
#define WATCHDOG_MASK		0x0FFFF000

/*
 * CONFIGARM bit definition
 */
#define RESETARM_MASK		0x000F0000
#define CONFARM7		(1<<7) /* 0=324MHz, 1=162MHz */
#define CONFARM2		(1<<2)
#define CONFARM1		(1<<1)
#define CONFARM0		(1<<1)

/*
 * CONFIGAUDIO bit definition
 */
#define RESET_AOUT		(1<<23)
#define RESET_ETH		(1<<22)
#define RESET_USB		(1<<21)
#define RESET_DMA		(1<<20)
#define RESET_AUDIO		(1<<17)
#define RESET_AXIMOD		(1<<16)

#define CLK_81_AOUT_EN		(1<<15)
#define CLK_81_USB_EN		(1<<14)
#define CLK_81_ETH_EN		(1<<13)
#define CLK_81_AXIIF_EN		(1<<10)
#define CLK_81_AUDIO_EN		(1<<9)

#define CLK_162_AXIIF_EN	(1<<4)

#define CONFAUDIO			(1<<2) /* 0=324MHz, 1=162MHz */
#define CLK_324_AUDIO_EN	(1<<1) /* 0=324MHz, 1=162MHz */

#endif				/* __ARCH_ARM_MACH_CLKPWR_H */
