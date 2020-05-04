/*
 * arch/arm/include/asm/arch-gk6202/gk6202.h
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
#ifndef __ARCH_ARM_MACH_GK6202_H
#define __ARCH_ARM_MACH_GK6202_H

/* Clocks */

#define GK6202_FMAC3H_CLK             100000000
#define GK6202_UART_HZ                 100000000


/* Memory Map */
#define GK6202_GPIO_BASE       		0xC6000000
#define GK6202_UART0_BASE      		0xCD000000
#define GK6202_CLKPWR_BASE     		0xC0000000
#define GK6202_USB_BASE      			0xD2000000
#define GK6202_USBLINK0_BASE          0xD2000800  
#define GK6202_USBLINK1_BASE          0xD2001000
#define GK6202_PWM_SYS_BASE			0xA500A000

/* IRQ Signal Map */


/* IRC */


/* VIC */

 /* all interrupts enabled */

/* Timer */


/* UART */
#define UART_BASE               MB86HXX_UART0_BASE

/* Ethernet */


/* UPI */


/* USB */


/* UPI --- nand */



/* UPI Device Config Register Offset */




#endif        /* __ARCH_ARM_MACH_GK6202_H */
