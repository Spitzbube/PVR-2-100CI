/*
 * TI's GK6202 platform specific usb wrapper definitions.
 *
 * Copyright (C) 2013 GoKe Microelectronics LIMITED
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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef __MUSB_GK6202_H__
#define __MUSB_GK6202_H__

#include <asm/arch/gk6202.h>

#define GK6202_USB0_INT_MASK	(GK6202_USB_BASE+ (0xf0))
#define GK6202_USB0_INT_STATUS	(GK6202_USB_BASE + (0xf4))
#define GK6202_USB0_INT_CLEAR	(GK6202_USB_BASE + (0xf8))

//#define GK6202_USB0_EARLY		(GK6202_DMA_BASE + (0x38))
#define GK6202_USB0_MODE		(GK6202_USB_BASE + (0x14))
#define GK6202_USB0_PHY_CFG	    (GK6202_USB_BASE + (0x18))

#define GK6202_USB1_INT_MASK	(GK6202_USB_BASE + (0x2c))
#define GK6202_USB1_INT_STATUS	(GK6202_USB_BASE + (0x30))
#define GK6202_USB1_INT_CLEAR	(GK6202_USB_BASE + (0x34))

//#define GK6202_USB1_EARLY		(GK6202_DMA_BASE + (0x48))
#define GK6202_USB1_MODE		(GK6202_USB_BASE + (0x38))
#define GK6202_USB1_PHY_CFG	    (GK6202_USB_BASE + (0x3c))

#define GK6202_USB_CLK_CTL		        (GK6202_CLKPWR_BASE )
#define GK6202_CLKPWR_CONFIGDMAC	    (GK6202_CLKPWR_BASE)
#define GK6202_CLKPWR_CONFIGDMAC_RESET	(GK6202_CLKPWR_BASE)

#define GK6202_USB_BASE_MASK	(0xfffff000)
#define GK6202_USB_UTMI_FS		(0x80)
#define GK6202_USB_PHY0_RESET	(1<<10)
#define GK6202_USB_PHY1_RESET	(1<<11)
#define GK6202_CLK_EN_DMA_CFG7	    (7)
#define GK6202_CLK_DMA_USB_RESET_N9	    (8)

#define GK6202_USB_1BYTE_ACCESS	(0)
#define GK6202_USB_2BYTE_ACCESS	(1)
#define GK6202_USB_4BYTE_ACCESS	(2)
#define GK6202_USB_LENGTH_MASK		(6)

/* Timeout for USB module */
#define GK6202_USB_TIMEOUT 0x3FFFFFF

#endif	/* __MUSB_GK6202_H__ */

