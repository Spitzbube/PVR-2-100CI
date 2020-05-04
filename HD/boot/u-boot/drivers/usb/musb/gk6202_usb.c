/*
 * TI's GK6202 platform specific USB wrapper functions.
 *
 * Copyright (c) 2013 GoKe Microelectronics LIMITED
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Author: Thomas Abraham t-abraham@ti.com, Texas Instruments
 */

#include <common.h>
#include <asm/io.h>
#include "musb_core.h"
#include "gk6202_usb.h"


static u32 usb0_phy = 0x130e;
volatile u32 usb0_mode = 0;
static u32 usb1_phy = 0x130e;
volatile u32 usb1_mode = 0;

struct musb_config musb_cfg = {
	.regs 			= (struct	musb_regs *)GK6202_USBLINK1_BASE,
	.timeout 		= GK6202_USB_TIMEOUT,
    .musb_speed  	= 0	,
};

/*
 * Enable the USB phy
 */
static u8 phy_on(void)
{
	u32 timeout;
	/* Wait until the USB phy is turned on */

	/* USB phy was not turned on */
	return 1;
}

/*
 * Disable the USB phy
 */
static void phy_off(void)
{
	/* powerdown the on-chip PHY and its oscillator */
}

void __enable_vbus(void)
{
	/*
	 *  nothing to do, vbus is handled through the cpu.
	 *  Define this function in board code, if it is
	 *  different on your board.
	 */
}
void  enable_vbus(void)
	__attribute__((weak, alias("__enable_vbus")));

/*
 * This function performs Davinci platform specific initialization for usb0.
 */
int musb_platform_init(void)
{
	u32  revision;
	u32  reg;	
	u32	  usb_clk;	

	/* enable USB VBUS */
	//enable_vbus();

	/* start the on-chip USB phy and its pll */
	if (!phy_on())
		return -1;
	
	reg = readl(GK6202_CLKPWR_CONFIGDMAC_RESET);
	writel(reg & ~(1<<GK6202_CLK_DMA_USB_RESET_N9), GK6202_CLKPWR_CONFIGDMAC_RESET);
	reg = readl(GK6202_CLKPWR_CONFIGDMAC_RESET);
	udelay(1000);
	writel(reg | (1<<GK6202_CLK_DMA_USB_RESET_N9), GK6202_CLKPWR_CONFIGDMAC_RESET);
	reg = readl(GK6202_CLKPWR_CONFIGDMAC_RESET);
	
	/* USB PHY reset */
	usb_clk = readl(GK6202_USB_CLK_CTL);
	usb_clk &=~(GK6202_USB_PHY0_RESET | GK6202_USB_PHY1_RESET);
	writel(usb_clk, GK6202_USB_CLK_CTL);
	
	usb_clk |= (GK6202_USB_PHY0_RESET | GK6202_USB_PHY1_RESET);
	writel(usb_clk, GK6202_USB_CLK_CTL);
	
    /* set PHY config for usb core 0  */
    writel(usb0_mode, GK6202_USB0_MODE);
    writel(usb0_phy, GK6202_USB0_PHY_CFG);

    /* set PHY config for usb core 1*/
    writel(usb1_mode, GK6202_USB1_MODE);
    writel(usb1_phy, GK6202_USB1_PHY_CFG);
    writel(1,GK6202_GPIO_BASE + 4 * 18 );
    udelay(1000);   

	return 0;
}

/*
 * This function performs Davinci platform specific deinitialization for usb0.
 */
void musb_platform_deinit(void)
{
}


void musb_hcd_set_speed(int speed)
{
    if(speed == MUSB_TYPE_SPEED_HIGH || speed == MUSB_TYPE_SPEED_FULL)
         usb1_phy &= ~GK6202_USB_UTMI_FS;
    else
        usb1_phy |= GK6202_USB_UTMI_FS;

    writel(usb1_phy, GK6202_USB1_PHY_CFG);


}

