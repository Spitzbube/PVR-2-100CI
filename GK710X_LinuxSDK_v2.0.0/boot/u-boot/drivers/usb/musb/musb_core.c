/*
 * Mentor USB OTG Core functionality common for both Host and Device
 * functionality.
 *
 * Copyright (c) 2008 Texas Instruments
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

#include "musb_core.h"
struct musb_regs *musbr;

/*
 * program the mentor core to start (enable interrupts, dma, etc.)
 */
void musb_start(void)
{
#if defined(CONFIG_MUSB_HCD)
	u8 devctl;
	u8 busctl;
#endif

	/* disable all interrupts */
	musb_writew(0, &musbr->intrtxe);
	musb_writew(0, &musbr->intrrxe);
	musb_writeb(0, &musbr->intrusbe);
	musb_writeb(0, &musbr->testmode);

	/* put into basic highspeed mode and start session */
	musb_writeb(MUSB_POWER_HSENAB, &musbr->power);
#if defined(CONFIG_MUSB_HCD)
	/* Program PHY to use EXT VBUS if required */
	if (musb_cfg.extvbus == 1) {
		busctl = musb_read_ulpi_buscontrol(musbr);
		musb_write_ulpi_buscontrol(musbr, busctl | ULPI_USE_EXTVBUS);
	}

	devctl = musb_readb(&musbr->devctl);
	musb_writeb(devctl | MUSB_DEVCTL_SESSION, &musbr->devctl);
#endif
}

#ifdef MUSB_NO_DYNAMIC_FIFO
# define config_fifo(dir, idx, addr)
#else
# define config_fifo(dir, idx, addr) \
	do { \
		musb_writeb(idx, &musbr->dir##fifosz); \
		musb_writew(fifoaddr >> 3, &musbr->dir##fifoadd); \
	} while (0)
#endif

/*
 * This function configures the endpoint configuration. The musb hcd or musb
 * device implementation can use this function to configure the endpoints
 * and set the FIFO sizes. Note: The summation of FIFO sizes of all endpoints
 * should not be more than the available FIFO size.
 *
 * epinfo	- Pointer to EP configuration table
 * cnt		- Number of entries in the EP conf table.
 */
void musb_configure_ep(const struct musb_epinfo *epinfo, u8 cnt)
{
	u16 csr;
	u16 fifoaddr = 64; /* First 64 bytes of FIFO reserved for EP0 */
	u32 fifosize;
	u8  idx;

	while (cnt--) {
		/* prepare fifosize to write to register */
		fifosize = epinfo->epsize >> 3;
		idx = ffs(fifosize) - 1;

		musb_writeb(epinfo->epnum, &musbr->index);
		if (epinfo->epdir) {
			/* Configure fifo size and fifo base address */
			config_fifo(tx, idx, fifoaddr);

			csr = musb_readw(&musbr->txcsr);
#if defined(CONFIG_MUSB_HCD)
			/* clear the data toggle bit */
			musb_writew(csr | MUSB_TXCSR_CLRDATATOG, &musbr->txcsr);
#endif
			/* Flush fifo if required */
			if (csr & MUSB_TXCSR_TXPKTRDY)
				musb_writew(csr | MUSB_TXCSR_FLUSHFIFO,
					&musbr->txcsr);
		} else {
			/* Configure fifo size and fifo base address */
			config_fifo(rx, idx, fifoaddr);

			csr = musb_readw(&musbr->rxcsr);
#if defined(CONFIG_MUSB_HCD)
			/* clear the data toggle bit */
			musb_writew(csr | MUSB_RXCSR_CLRDATATOG, &musbr->rxcsr);
#endif
			/* Flush fifo if required */
			if (csr & MUSB_RXCSR_RXPKTRDY)
				musb_writew(csr | MUSB_RXCSR_FLUSHFIFO,
					&musbr->rxcsr);
		}
		fifoaddr += epinfo->epsize;
		epinfo++;
	}
}



//#define OLD_FIFO

#ifdef OLD_FIFO

/*
 * This function writes data to endpoint fifo
 *
 * ep		- endpoint number
 * length	- number of bytes to write to FIFO
 * fifo_data	- Pointer to data buffer that contains the data to write
 */
__attribute__((weak))
void write_fifo(u8 ep, u32 length, void *fifo_data)
{
	u8  *data = (u8 *)fifo_data;

	/* select the endpoint index */
	musb_writeb(ep, &musbr->index);

	/* write the data to the fifo */
	while (length--)
		musb_writeb(*data++, &musbr->fifox[ep]);
}

/*
 * AM35x supports only 32bit read operations so
 * use seperate read_fifo() function for it.
 */

/*
 * This function reads data from endpoint fifo
 *
 * ep           - endpoint number
 * length       - number of bytes to read from FIFO
 * fifo_data    - pointer to data buffer into which data is read
 */

__attribute__((weak))
void read_fifo(u8 ep, u32 length, void *fifo_data)
{
	u8  *data = (u8 *)fifo_data;

	/* select the endpoint index */
	musb_writeb(ep, &musbr->index);

	/* read the data to the fifo */
	while (length--)
		*data++ = musb_readb(&musbr->fifox[ep]);

}
#else


void AccessUSBRegByDMA(unsigned long addr, int usbLenAccess )
{
    u32 usb_mode;
    usb_mode = readl(GK6202_USB1_MODE);
	usb_mode &= ~GK6202_USB_LENGTH_MASK;

    writel(usbLenAccess<<1 | usb_mode, GK6202_USB1_MODE);
}

__attribute__((weak))
void read_fifo(u8 ep, u32 length, void *fifo_data)
{
    unsigned int *fifo = &musbr->fifox[ep];
    u32 offset;
    u8 *dst = fifo_data;
    u32 len = length;

    musb_writeb(ep, &musbr->index);
    
	offset = (u32)((void *)fifo - (void*)musbr);
	fifo = (void*)musbr + (offset << GK6202_USB_OFFSET);
	/* we can't assume unaligned writes work */
	if (likely((0x01 & (unsigned long) dst) == 0)) {
		u16	index = 0;

		/* best case is 32bit-aligned destination address */
		if ((0x02 & (unsigned long) dst) == 0) {
			if (len >= 4) {
                AccessUSBRegByDMA(0,GK6202_USB_4BYTE_ACCESS);
				__raw_readsl((unsigned int)fifo, dst, len >> 2);
				index = len & ~0x03;
			}
			if (len & 0x02) {
				//*(u16 *)&dst[index] = musb_readw(fifo, 0);
				AccessUSBRegByDMA(0,GK6202_USB_2BYTE_ACCESS);
				__raw_readsw((unsigned int)fifo, &(dst[index]), 1);
				index += 2;
			}
		} else {
			if (len >= 2) {
                AccessUSBRegByDMA(0,GK6202_USB_2BYTE_ACCESS);
				__raw_readsw((unsigned int)fifo, dst, len >> 1);
				index = len & ~0x01;
			}
		}
		if (len & 0x01)
		{
            AccessUSBRegByDMA(0,GK6202_USB_1BYTE_ACCESS);
            dst[index] = readb(fifo);
		}
	} else  {
		/* byte aligned */
        AccessUSBRegByDMA(0,GK6202_USB_1BYTE_ACCESS);
		__raw_readsb((unsigned int)fifo, dst, len);
	}
}

__attribute__((weak))
void write_fifo(u8 ep, u32 length, void *fifo_data) //(struct musb_hw_ep *hw_ep, u16 len, const u8 *src)
{
    unsigned int *fifo = &musbr->fifox[ep];
    u32 offset;
    u8 *src = fifo_data;
    u32 len = length;

    musb_writeb(ep, &musbr->index);
    
	offset = (u32)((void *)fifo - (void*)musbr);
	fifo = (void*)musbr + (offset << GK6202_USB_OFFSET);
    
	/* we can't assume unaligned reads work */
	if (likely((0x01 & (unsigned long) src) == 0)) {
		u16	index = 0;

		/* best case is 32bit-aligned source address */
		if ((0x02 & (unsigned long) src) == 0) {
			if (len >= 4) {
                AccessUSBRegByDMA(0,GK6202_USB_4BYTE_ACCESS);
				__raw_writesl((unsigned int)fifo, src + index, len >> 2);
				index += len & ~0x03;
			}
			if (len & 0x02) {
                AccessUSBRegByDMA(0,GK6202_USB_2BYTE_ACCESS);
				__raw_writesw((unsigned int)fifo, src + index,1);
				index += 2;
			}
		} else {
			if (len >= 2) {
                AccessUSBRegByDMA(0,GK6202_USB_2BYTE_ACCESS);
				__raw_writesw((unsigned int)fifo, src + index, len >> 1);
				index += len & ~0x01;
			}
		}
		if (len & 0x01)
		{
            AccessUSBRegByDMA(0,GK6202_USB_1BYTE_ACCESS);
            writeb(src[index],fifo);
		}
	} else  {
		/* byte aligned */
        AccessUSBRegByDMA(0,GK6202_USB_1BYTE_ACCESS);
		__raw_writesb((unsigned int)fifo, src, len);
	}
}

#endif
