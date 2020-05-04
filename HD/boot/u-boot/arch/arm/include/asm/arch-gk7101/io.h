/*
 * arch/arm/mach-gk7101/include/mach/io.h
 *
 * History:
 *  2014/06/18 - [Kewell Liu] created file
 *
 * Copyright (C) 2002-2014, Goke Microelectronics China.
 *
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef __ASM_ARM_ARCH_IO_H
#define __ASM_ARM_ARCH_IO_H

/* ==========================================================================*/
#define IO_SPACE_LIMIT      0xffffffff

#include <asm/io.h>
#include <configs/gk7101.h>
#include <asm/arch/gk7101_reg.h>

#define USB_DMA_ADD_MODE    0   
#define SPI_API_MODE        0   

#define     ADC_HAL_MODE    1
#define     AUD_HAL_MODE    1
#define     CRY_HAL_MODE    1
#define     DDR_HAL_MODE    1
#define     DSP_HAL_MODE    1
#define     ETH_HAL_MODE    1
#define     GREG_HAL_MODE   1
#define     GPIO_HAL_MODE   1
#define     I2C_HAL_MODE    1
#define     I2S_HAL_MODE    1
#define     IR_HAL_MODE     1
#define     IRQ_HAL_MODE    1
#define     MCU_HAL_MODE    1
#define     PWM_HAL_MODE    1
#define     RCT_HAL_MODE    1
#define     SD_HAL_MODE     1
#define     SF_HAL_MODE     1
#define     SSI_HAL_MODE    1
#define     TIMER_HAL_MODE  1
#define     UART_HAL_MODE   1
#define     USB_HAL_MODE    1
#define     VOUT_HAL_MODE   1
#define     WDT_HAL_MODE    1


struct hw_ops{
    int (*get_version)(void);
	unsigned int (*reserved)(unsigned int );

    unsigned char (*hw_readb)(unsigned int);
    unsigned short (*hw_readw)(unsigned int);
    unsigned int (*hw_readl)(unsigned int);

    void (*hw_writeb)(unsigned char , unsigned int );
    void (*hw_writew)(unsigned short , unsigned int );
    void (*hw_writel)(unsigned int , unsigned int );

    unsigned int (*flash_read)(void);
    void (*flash_write)(unsigned int);

    unsigned char (*usb_readb)(unsigned int ptr, unsigned int offset);
    unsigned short (*usb_readw)(unsigned int ptr, unsigned int offset);
    unsigned int (*usb_readl)(unsigned int ptr, unsigned int offset);
    void (*usb_writeb)(unsigned int ptr, unsigned int offset, unsigned char value);
    void (*usb_writew)(unsigned int ptr, unsigned int offset, unsigned short value);
    void (*usb_writel)(unsigned int ptr, unsigned int offset, unsigned int value);

    unsigned int (*dma_readl)(unsigned int ptr);
    void (*dma_writel)(unsigned int ptr, unsigned int value);
};

extern struct hw_ops *g_hw;

/* ==========================================================================*/

/* #define __io(a)         ((void __iomem *)(a)) */

/* ==========================================================================*/
#ifndef __ASSEMBLER__
#if 0
#define gk_readb(v)             g_hw->hw_readb(v)
#define gk_readw(v)             g_hw->hw_readw(v)
#define gk_writeb(a,v)          g_hw->hw_writeb(v,a)
#define gk_writew(a,v)          g_hw->hw_writew(v,a)

#define gk_readl(v)             g_hw->hw_readl(v)
#define gk_writel(a,v)          g_hw->hw_writel(v,a)

#define gk_flash_read()         g_hw->flash_read()
#define gk_flash_write(v)       g_hw->flash_write(v)

#define gk_usb_readb(a,o)       g_hw->usb_readb(a,o)
#define gk_usb_readw(a,o)       g_hw->usb_readw(a,o)
#define gk_usb_readl(a,o)       g_hw->usb_readl(a,o)
#define gk_usb_writeb(a,o,v)    g_hw->usb_writeb(a,o,v)
#define gk_usb_writew(a,o,v)    g_hw->usb_writew(a,o,v)
#define gk_usb_writel(a,o,v)    g_hw->usb_writel(a,o,v)

#define gk_dma_readl(v)         g_hw->dma_readl(v)
#define gk_dma_writel(a,v)      g_hw->dma_writel(v,a)

#define gk_setbitsb(v, mask)  gk_writeb((v),(gk_readb(v) | (mask)))
#define gk_setbitsw(v, mask)  gk_writew((v),(gk_readw(v) | (mask)))
#define gk_setbitsl(v, mask)  gk_writel((v),(gk_readl(v) | (mask)))

#define gk_clrbitsb(v, mask)  gk_writeb((v),(gk_readb(v) & ~(mask)))
#define gk_clrbitsw(v, mask)  gk_writew((v),(gk_readw(v) & ~(mask)))
#define gk_clrbitsl(v, mask)  gk_writel((v),(gk_readl(v) & ~(mask)))

#define gk_tstbitsb(v, mask)  (gk_readb(v) & (mask))
#define gk_tstbitsw(v, mask)  (gk_readw(v) & (mask))
#define gk_tstbitsl(v, mask)  (gk_readl(v) & (mask))

#else
#define gk_hal_readb(a)             g_hw->hw_readb((u32)(a))
#define gk_hal_readw(a)             g_hw->hw_readw((u32)(a))
#define gk_hal_writeb(a,v)          g_hw->hw_writeb((v),(u32)(a))
#define gk_hal_writew(a,v)          g_hw->hw_writew((v),(u32)(a))
#define gk_hal_readl(a)             g_hw->hw_readl((u32)(a))
#define gk_hal_writel(a,v)          g_hw->hw_writel((v),(u32)(a))

#define gk_flash_read()         g_hw->flash_read()
#define gk_flash_write(v)       g_hw->flash_write((v))
#endif

#if USB_DMA_ADD_MODE
extern unsigned char (*gk_musb_readb)(unsigned int ptr, unsigned int offset);
extern unsigned short (*gk_musb_readw)(unsigned int ptr, unsigned int offset);
extern unsigned int (*gk_musb_readl)(unsigned int ptr, unsigned int offset);
extern void (*gk_musb_writeb)(unsigned int ptr, unsigned int offset, unsigned char value);
extern void (*gk_musb_writew)(unsigned int ptr, unsigned int offset, unsigned short value);
extern void (*gk_musb_writel)(unsigned int ptr, unsigned int offset, unsigned int value);

extern unsigned int (*gk_dma_readl)(unsigned int ptr);
extern void (*gk_dma_writel)(unsigned int ptr, unsigned int value);
#else
#define gk_musb_readb(a, o)      (*((volatile unsigned char*)(a+o)))
#define gk_musb_readw(a, o)      (*((volatile unsigned short*)(a+o)))
#define gk_musb_readl(a, o)      (*((volatile unsigned int*)(a+o)))
#define gk_musb_writeb(a, o, v)  ((*((volatile unsigned char*)(a+o))) = v)
#define gk_musb_writew(a, o, v)  ((*((volatile unsigned short*)(a+o))) = v)
#define gk_musb_writel(a, o, v)  ((*((volatile unsigned int*)(a+o))) = v)

#define gk_dma_readl(a)         (*((volatile unsigned int*)(a)))
#define gk_dma_writel(a, v)     ((*((volatile unsigned int*)a)) = v)
#endif

#if SPI_API_MODE
extern unsigned char (*gk_spi_readb)(unsigned int ptr);
extern unsigned short (*gk_spi_readw)(unsigned int ptr);
extern unsigned int (*gk_spi_readl)(unsigned int ptr);
extern void (*gk_spi_writeb)(unsigned int ptr, unsigned char value);
extern void (*gk_spi_writew)(unsigned int ptr, unsigned short value);
extern void (*gk_spi_writel)(unsigned int ptr, unsigned int value);
#else
#define gk_spi_readb(a)      gk_hal_readb(a)
#define gk_spi_readw(a)      gk_hal_readw(a)
#define gk_spi_readl(a)      gk_hal_readl(a)
#define gk_spi_writeb(a, v)  gk_hal_writeb((a), v)
#define gk_spi_writew(a, v)  gk_hal_writew((a), v)
#define gk_spi_writel(a, v)  gk_hal_writel((a), v)
#endif


#define MODULES_WR_IO
#ifdef MODULES_WR_IO



#if ADC_HAL_MODE
#define gk_adc_readb(a)      gk_hal_readb((a))
#define gk_adc_readw(a)      gk_hal_readw((a))
#define gk_adc_readl(a)      gk_hal_readl((a))
#define gk_adc_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_adc_writew(a, v)  gk_hal_writew((a), (v))
#define gk_adc_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_adc_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_adc_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_adc_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_adc_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_adc_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_adc_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_adc_setbitsb(v, mask)    gk_adc_writeb((v),(gk_adc_readb((v)) | (mask)))
#define gk_adc_setbitsw(v, mask)    gk_adc_writew((v),(gk_adc_readw((v)) | (mask)))
#define gk_adc_setbitsl(v, mask)    gk_adc_writel((v),(gk_adc_readl((v)) | (mask)))
#define gk_adc_clrbitsb(v, mask)    gk_adc_writeb((v),(gk_adc_readb((v)) & ~(mask)))
#define gk_adc_clrbitsw(v, mask)    gk_adc_writew((v),(gk_adc_readw((v)) & ~(mask)))
#define gk_adc_clrbitsl(v, mask)    gk_adc_writel((v),(gk_adc_readl((v)) & ~(mask)))
#define gk_adc_tstbitsb(v, mask)    (gk_adc_readb((v)) & (mask))
#define gk_adc_tstbitsw(v, mask)    (gk_adc_readw((v)) & (mask))
#define gk_adc_tstbitsl(v, mask)    (gk_adc_readl((v)) & (mask))


#if AUD_HAL_MODE
#define gk_aud_readb(a)      gk_hal_readb((a))
#define gk_aud_readw(a)      gk_hal_readw((a))
#define gk_aud_readl(a)      gk_hal_readl((a))
#define gk_aud_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_aud_writew(a, v)  gk_hal_writew((a), (v))
#define gk_aud_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_aud_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_aud_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_aud_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_aud_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_aud_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_aud_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_aud_setbitsb(v, mask)    gk_aud_writeb((v),(gk_aud_readb((v)) | (mask)))
#define gk_aud_setbitsw(v, mask)    gk_aud_writew((v),(gk_aud_readw((v)) | (mask)))
#define gk_aud_setbitsl(v, mask)    gk_aud_writel((v),(gk_aud_readl((v)) | (mask)))
#define gk_aud_clrbitsb(v, mask)    gk_aud_writeb((v),(gk_aud_readb((v)) & ~(mask)))
#define gk_aud_clrbitsw(v, mask)    gk_aud_writew((v),(gk_aud_readw((v)) & ~(mask)))
#define gk_aud_clrbitsl(v, mask)    gk_aud_writel((v),(gk_aud_readl((v)) & ~(mask)))
#define gk_aud_tstbitsb(v, mask)    (gk_aud_readb((v)) & (mask))
#define gk_aud_tstbitsw(v, mask)    (gk_aud_readw((v)) & (mask))
#define gk_aud_tstbitsl(v, mask)    (gk_aud_readl((v)) & (mask))



#if CRY_HAL_MODE
#define gk_cry_readb(a)      gk_hal_readb((a))
#define gk_cry_readw(a)      gk_hal_readw((a))
#define gk_cry_readl(a)      gk_hal_readl((a))
#define gk_cry_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_cry_writew(a, v)  gk_hal_writew((a), (v))
#define gk_cry_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_cry_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_cry_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_cry_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_cry_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_cry_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_cry_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_cry_setbitsb(v, mask)    gk_cry_writeb((v),(gk_cry_readb((v)) | (mask)))
#define gk_cry_setbitsw(v, mask)    gk_cry_writew((v),(gk_cry_readw((v)) | (mask)))
#define gk_cry_setbitsl(v, mask)    gk_cry_writel((v),(gk_cry_readl((v)) | (mask)))
#define gk_cry_clrbitsb(v, mask)    gk_cry_writeb((v),(gk_cry_readb((v)) & ~(mask)))
#define gk_cry_clrbitsw(v, mask)    gk_cry_writew((v),(gk_cry_readw((v)) & ~(mask)))
#define gk_cry_clrbitsl(v, mask)    gk_cry_writel((v),(gk_cry_readl((v)) & ~(mask)))
#define gk_cry_tstbitsb(v, mask)    (gk_cry_readb((v)) & (mask))
#define gk_cry_tstbitsw(v, mask)    (gk_cry_readw((v)) & (mask))
#define gk_cry_tstbitsl(v, mask)    (gk_cry_readl((v)) & (mask))

#if DDR_HAL_MODE
#define gk_ddr_readb(a)      gk_hal_readb((a))
#define gk_ddr_readw(a)      gk_hal_readw((a))
#define gk_ddr_readl(a)      gk_hal_readl((a))
#define gk_ddr_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_ddr_writew(a, v)  gk_hal_writew((a), (v))
#define gk_ddr_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_ddr_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_ddr_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_ddr_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_ddr_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_ddr_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_ddr_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_ddr_setbitsb(v, mask)    gk_ddr_writeb((v),(gk_ddr_readb((v)) | (mask)))
#define gk_ddr_setbitsw(v, mask)    gk_ddr_writew((v),(gk_ddr_readw((v)) | (mask)))
#define gk_ddr_setbitsl(v, mask)    gk_ddr_writel((v),(gk_ddr_readl((v)) | (mask)))
#define gk_ddr_clrbitsb(v, mask)    gk_ddr_writeb((v),(gk_ddr_readb((v)) & ~(mask)))
#define gk_ddr_clrbitsw(v, mask)    gk_ddr_writew((v),(gk_ddr_readw((v)) & ~(mask)))
#define gk_ddr_clrbitsl(v, mask)    gk_ddr_writel((v),(gk_ddr_readl((v)) & ~(mask)))
#define gk_ddr_tstbitsb(v, mask)    (gk_ddr_readb((v)) & (mask))
#define gk_ddr_tstbitsw(v, mask)    (gk_ddr_readw((v)) & (mask))
#define gk_ddr_tstbitsl(v, mask)    (gk_ddr_readl((v)) & (mask))


#if DSP_HAL_MODE
#define gk_dsp_readb(a)      gk_hal_readb((a))
#define gk_dsp_readw(a)      gk_hal_readw((a))
#define gk_dsp_readl(a)      gk_hal_readl((a))
#define gk_dsp_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_dsp_writew(a, v)  gk_hal_writew((a), (v))
#define gk_dsp_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_dsp_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_dsp_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_dsp_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_dsp_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_dsp_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_dsp_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_dsp_setbitsb(v, mask)    gk_dsp_writeb((v),(gk_dsp_readb((v)) | (mask)))
#define gk_dsp_setbitsw(v, mask)    gk_dsp_writew((v),(gk_dsp_readw((v)) | (mask)))
#define gk_dsp_setbitsl(v, mask)    gk_dsp_writel((v),(gk_dsp_readl((v)) | (mask)))
#define gk_dsp_clrbitsb(v, mask)    gk_dsp_writeb((v),(gk_dsp_readb((v)) & ~(mask)))
#define gk_dsp_clrbitsw(v, mask)    gk_dsp_writew((v),(gk_dsp_readw((v)) & ~(mask)))
#define gk_dsp_clrbitsl(v, mask)    gk_dsp_writel((v),(gk_dsp_readl((v)) & ~(mask)))
#define gk_dsp_tstbitsb(v, mask)    (gk_dsp_readb((v)) & (mask))
#define gk_dsp_tstbitsw(v, mask)    (gk_dsp_readw((v)) & (mask))
#define gk_dsp_tstbitsl(v, mask)    (gk_dsp_readl((v)) & (mask))

#if ETH_HAL_MODE
#define gk_eth_readb(a)      gk_hal_readb((a))
#define gk_eth_readw(a)      gk_hal_readw((a))
#define gk_eth_readl(a)      gk_hal_readl((a))
#define gk_eth_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_eth_writew(a, v)  gk_hal_writew((a), (v))
#define gk_eth_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_eth_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_eth_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_eth_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_eth_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_eth_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_eth_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))

#endif
#define gk_eth_setbitsb(v, mask)    gk_eth_writeb((v),(gk_eth_readb((v)) | (mask)))
#define gk_eth_setbitsw(v, mask)    gk_eth_writew((v),(gk_eth_readw((v)) | (mask)))
#define gk_eth_setbitsl(v, mask)    gk_eth_writel((v),(gk_eth_readl((v)) | (mask)))
#define gk_eth_clrbitsb(v, mask)    gk_eth_writeb((v),(gk_eth_readb((v)) & ~(mask)))
#define gk_eth_clrbitsw(v, mask)    gk_eth_writew((v),(gk_eth_readw((v)) & ~(mask)))
#define gk_eth_clrbitsl(v, mask)    gk_eth_writel((v),(gk_eth_readl((v)) & ~(mask)))
#define gk_eth_tstbitsb(v, mask)    (gk_eth_readb((v)) & (mask))
#define gk_eth_tstbitsw(v, mask)    (gk_eth_readw((v)) & (mask))
#define gk_eth_tstbitsl(v, mask)    (gk_eth_readl((v)) & (mask))

#if GREG_HAL_MODE
#define gk_greg_readb(a)      gk_hal_readb((a))
#define gk_greg_readw(a)      gk_hal_readw((a))
#define gk_greg_readl(a)      gk_hal_readl((a))
#define gk_greg_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_greg_writew(a, v)  gk_hal_writew((a), (v))
#define gk_greg_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_greg_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_greg_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_greg_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_greg_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_greg_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_greg_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_greg_setbitsb(v, mask)    gk_greg_writeb((v),(gk_greg_readb((v)) | (mask)))
#define gk_greg_setbitsw(v, mask)    gk_greg_writew((v),(gk_greg_readw((v)) | (mask)))
#define gk_greg_setbitsl(v, mask)    gk_greg_writel((v),(gk_greg_readl((v)) | (mask)))
#define gk_greg_clrbitsb(v, mask)    gk_greg_writeb((v),(gk_greg_readb((v)) & ~(mask)))
#define gk_greg_clrbitsw(v, mask)    gk_greg_writew((v),(gk_greg_readw((v)) & ~(mask)))
#define gk_greg_clrbitsl(v, mask)    gk_greg_writel((v),(gk_greg_readl((v)) & ~(mask)))
#define gk_greg_tstbitsb(v, mask)    (gk_greg_readb((v)) & (mask))
#define gk_greg_tstbitsw(v, mask)    (gk_greg_readw((v)) & (mask))
#define gk_greg_tstbitsl(v, mask)    (gk_greg_readl((v)) & (mask))


#if GPIO_HAL_MODE
#define gk_gpio_readb(a)      gk_hal_readb((a))
#define gk_gpio_readw(a)      gk_hal_readw((a))
#define gk_gpio_readl(a)      gk_hal_readl((a))
#define gk_gpio_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_gpio_writew(a, v)  gk_hal_writew((a), (v))
#define gk_gpio_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_gpio_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_gpio_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_gpio_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_gpio_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_gpio_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_gpio_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_gpio_setbitsb(v, mask)    gk_gpio_writeb((v),(gk_gpio_readb((v)) | (mask)))
#define gk_gpio_setbitsw(v, mask)    gk_gpio_writew((v),(gk_gpio_readw((v)) | (mask)))
#define gk_gpio_setbitsl(v, mask)    gk_gpio_writel((v),(gk_gpio_readl((v)) | (mask)))
#define gk_gpio_clrbitsb(v, mask)    gk_gpio_writeb((v),(gk_gpio_readb((v)) & ~(mask)))
#define gk_gpio_clrbitsw(v, mask)    gk_gpio_writew((v),(gk_gpio_readw((v)) & ~(mask)))
#define gk_gpio_clrbitsl(v, mask)    gk_gpio_writel((v),(gk_gpio_readl((v)) & ~(mask)))
#define gk_gpio_tstbitsb(v, mask)    (gk_gpio_readb((v)) & (mask))
#define gk_gpio_tstbitsw(v, mask)    (gk_gpio_readw((v)) & (mask))
#define gk_gpio_tstbitsl(v, mask)    (gk_gpio_readl((v)) & (mask))


#if I2C_HAL_MODE
#define gk_i2c_readb(a)      gk_hal_readb((a))
#define gk_i2c_readw(a)      gk_hal_readw((a))
#define gk_i2c_readl(a)      gk_hal_readl((a))
#define gk_i2c_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_i2c_writew(a, v)  gk_hal_writew((a), (v))
#define gk_i2c_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_i2c_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_i2c_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_i2c_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_i2c_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_i2c_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_i2c_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_i2c_setbitsb(v, mask)    gk_i2c_writeb((v),(gk_i2c_readb((v)) | (mask)))
#define gk_i2c_setbitsw(v, mask)    gk_i2c_writew((v),(gk_i2c_readw((v)) | (mask)))
#define gk_i2c_setbitsl(v, mask)    gk_i2c_writel((v),(gk_i2c_readl((v)) | (mask)))
#define gk_i2c_clrbitsb(v, mask)    gk_i2c_writeb((v),(gk_i2c_readb((v)) & ~(mask)))
#define gk_i2c_clrbitsw(v, mask)    gk_i2c_writew((v),(gk_i2c_readw((v)) & ~(mask)))
#define gk_i2c_clrbitsl(v, mask)    gk_i2c_writel((v),(gk_i2c_readl((v)) & ~(mask)))
#define gk_i2c_tstbitsb(v, mask)    (gk_i2c_readb((v)) & (mask))
#define gk_i2c_tstbitsw(v, mask)    (gk_i2c_readw((v)) & (mask))
#define gk_i2c_tstbitsl(v, mask)    (gk_i2c_readl((v)) & (mask))

#if I2S_HAL_MODE
#define gk_i2s_readb(a)      gk_hal_readb((a))
#define gk_i2s_readw(a)      gk_hal_readw((a))
#define gk_i2s_readl(a)      gk_hal_readl((a))
#define gk_i2s_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_i2s_writew(a, v)  gk_hal_writew((a), (v))
#define gk_i2s_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_i2s_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_i2s_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_i2s_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_i2s_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_i2s_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_i2s_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_i2s_setbitsb(v, mask)    gk_i2s_writeb((v),(gk_i2s_readb((v)) | (mask)))
#define gk_i2s_setbitsw(v, mask)    gk_i2s_writew((v),(gk_i2s_readw((v)) | (mask)))
#define gk_i2s_setbitsl(v, mask)    gk_i2s_writel((v),(gk_i2s_readl((v)) | (mask)))
#define gk_i2s_clrbitsb(v, mask)    gk_i2s_writeb((v),(gk_i2s_readb((v)) & ~(mask)))
#define gk_i2s_clrbitsw(v, mask)    gk_i2s_writew((v),(gk_i2s_readw((v)) & ~(mask)))
#define gk_i2s_clrbitsl(v, mask)    gk_i2s_writel((v),(gk_i2s_readl((v)) & ~(mask)))
#define gk_i2s_tstbitsb(v, mask)    (gk_i2s_readb((v)) & (mask))
#define gk_i2s_tstbitsw(v, mask)    (gk_i2s_readw((v)) & (mask))
#define gk_i2s_tstbitsl(v, mask)    (gk_i2s_readl((v)) & (mask))

#if IR_HAL_MODE
#define gk_ir_readb(a)      gk_hal_readb((a))
#define gk_ir_readw(a)      gk_hal_readw((a))
#define gk_ir_readl(a)      gk_hal_readl((a))
#define gk_ir_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_ir_writew(a, v)  gk_hal_writew((a), (v))
#define gk_ir_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_ir_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_ir_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_ir_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_ir_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_ir_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_ir_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_ir_setbitsb(v, mask)    gk_ir_writeb((v),(gk_ir_readb((v)) | (mask)))
#define gk_ir_setbitsw(v, mask)    gk_ir_writew((v),(gk_ir_readw((v)) | (mask)))
#define gk_ir_setbitsl(v, mask)    gk_ir_writel((v),(gk_ir_readl((v)) | (mask)))
#define gk_ir_clrbitsb(v, mask)    gk_ir_writeb((v),(gk_ir_readb((v)) & ~(mask)))
#define gk_ir_clrbitsw(v, mask)    gk_ir_writew((v),(gk_ir_readw((v)) & ~(mask)))
#define gk_ir_clrbitsl(v, mask)    gk_ir_writel((v),(gk_ir_readl((v)) & ~(mask)))
#define gk_ir_tstbitsb(v, mask)    (gk_ir_readb((v)) & (mask))
#define gk_ir_tstbitsw(v, mask)    (gk_ir_readw((v)) & (mask))
#define gk_ir_tstbitsl(v, mask)    (gk_ir_readl((v)) & (mask))

#if IRQ_HAL_MODE
#define gk_irq_readb(a)      gk_hal_readb((a))
#define gk_irq_readw(a)      gk_hal_readw((a))
#define gk_irq_readl(a)      gk_hal_readl((a))
#define gk_irq_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_irq_writew(a, v)  gk_hal_writew((a), (v))
#define gk_irq_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_irq_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_irq_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_irq_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_irq_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_irq_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_irq_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_irq_setbitsb(v, mask)    gk_irq_writeb((v),(gk_irq_readb((v)) | (mask)))
#define gk_irq_setbitsw(v, mask)    gk_irq_writew((v),(gk_irq_readw((v)) | (mask)))
#define gk_irq_setbitsl(v, mask)    gk_irq_writel((v),(gk_irq_readl((v)) | (mask)))
#define gk_irq_clrbitsb(v, mask)    gk_irq_writeb((v),(gk_irq_readb((v)) & ~(mask)))
#define gk_irq_clrbitsw(v, mask)    gk_irq_writew((v),(gk_irq_readw((v)) & ~(mask)))
#define gk_irq_clrbitsl(v, mask)    gk_irq_writel((v),(gk_irq_readl((v)) & ~(mask)))
#define gk_irq_tstbitsb(v, mask)    (gk_irq_readb((v)) & (mask))
#define gk_irq_tstbitsw(v, mask)    (gk_irq_readw((v)) & (mask))
#define gk_irq_tstbitsl(v, mask)    (gk_irq_readl((v)) & (mask))


#if MCU_HAL_MODE
#define gk_mcu_readb(a)      gk_hal_readb((a))
#define gk_mcu_readw(a)      gk_hal_readw((a))
#define gk_mcu_readl(a)      gk_hal_readl((a))
#define gk_mcu_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_mcu_writew(a, v)  gk_hal_writew((a), (v))
#define gk_mcu_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_mcu_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_mcu_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_mcu_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_mcu_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_mcu_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_mcu_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_mcu_setbitsb(v, mask)    gk_mcu_writeb((v),(gk_mcu_readb((v)) | (mask)))
#define gk_mcu_setbitsw(v, mask)    gk_mcu_writew((v),(gk_mcu_readw((v)) | (mask)))
#define gk_mcu_setbitsl(v, mask)    gk_mcu_writel((v),(gk_mcu_readl((v)) | (mask)))
#define gk_mcu_clrbitsb(v, mask)    gk_mcu_writeb((v),(gk_mcu_readb((v)) & ~(mask)))
#define gk_mcu_clrbitsw(v, mask)    gk_mcu_writew((v),(gk_mcu_readw((v)) & ~(mask)))
#define gk_mcu_clrbitsl(v, mask)    gk_mcu_writel((v),(gk_mcu_readl((v)) & ~(mask)))
#define gk_mcu_tstbitsb(v, mask)    (gk_mcu_readb((v)) & (mask))
#define gk_mcu_tstbitsw(v, mask)    (gk_mcu_readw((v)) & (mask))
#define gk_mcu_tstbitsl(v, mask)    (gk_mcu_readl((v)) & (mask))

#if PWM_HAL_MODE
#define gk_pwm_readb(a)      gk_hal_readb((a))
#define gk_pwm_readw(a)      gk_hal_readw((a))
#define gk_pwm_readl(a)      gk_hal_readl((a))
#define gk_pwm_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_pwm_writew(a, v)  gk_hal_writew((a), (v))
#define gk_pwm_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_pwm_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_pwm_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_pwm_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_pwm_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_pwm_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_pwm_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_pwm_setbitsb(v, mask)    gk_pwm_writeb((v),(gk_pwm_readb((v)) | (mask)))
#define gk_pwm_setbitsw(v, mask)    gk_pwm_writew((v),(gk_pwm_readw((v)) | (mask)))
#define gk_pwm_setbitsl(v, mask)    gk_pwm_writel((v),(gk_pwm_readl((v)) | (mask)))
#define gk_pwm_clrbitsb(v, mask)    gk_pwm_writeb((v),(gk_pwm_readb((v)) & ~(mask)))
#define gk_pwm_clrbitsw(v, mask)    gk_pwm_writew((v),(gk_pwm_readw((v)) & ~(mask)))
#define gk_pwm_clrbitsl(v, mask)    gk_pwm_writel((v),(gk_pwm_readl((v)) & ~(mask)))
#define gk_pwm_tstbitsb(v, mask)    (gk_pwm_readb((v)) & (mask))
#define gk_pwm_tstbitsw(v, mask)    (gk_pwm_readw((v)) & (mask))
#define gk_pwm_tstbitsl(v, mask)    (gk_pwm_readl((v)) & (mask))

#if RCT_HAL_MODE
#define gk_rct_readb(a)      gk_hal_readb((a))
#define gk_rct_readw(a)      gk_hal_readw((a))
#define gk_rct_readl(a)      gk_hal_readl((a))
#define gk_rct_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_rct_writew(a, v)  gk_hal_writew((a), (v))
#define gk_rct_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_rct_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_rct_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_rct_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_rct_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_rct_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_rct_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_rct_setbitsb(v, mask)    gk_rct_writeb((v),(gk_rct_readb((v)) | (mask)))
#define gk_rct_setbitsw(v, mask)    gk_rct_writew((v),(gk_rct_readw((v)) | (mask)))
#define gk_rct_setbitsl(v, mask)    gk_rct_writel((v),(gk_rct_readl((v)) | (mask)))
#define gk_rct_clrbitsb(v, mask)    gk_rct_writeb((v),(gk_rct_readb((v)) & ~(mask)))
#define gk_rct_clrbitsw(v, mask)    gk_rct_writew((v),(gk_rct_readw((v)) & ~(mask)))
#define gk_rct_clrbitsl(v, mask)    gk_rct_writel((v),(gk_rct_readl((v)) & ~(mask)))
#define gk_rct_tstbitsb(v, mask)    (gk_rct_readb((v)) & (mask))
#define gk_rct_tstbitsw(v, mask)    (gk_rct_readw((v)) & (mask))
#define gk_rct_tstbitsl(v, mask)    (gk_rct_readl((v)) & (mask))


#if SD_HAL_MODE
#define gk_sd_readb(a)      gk_hal_readb((a))
#define gk_sd_readw(a)      gk_hal_readw((a))
#define gk_sd_readl(a)      gk_hal_readl((a))
#define gk_sd_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_sd_writew(a, v)  gk_hal_writew((a), (v))
#define gk_sd_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_sd_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_sd_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_sd_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_sd_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_sd_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_sd_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_sd_setbitsb(v, mask)    gk_sd_writeb((v),(gk_sd_readb((v)) | (mask)))
#define gk_sd_setbitsw(v, mask)    gk_sd_writew((v),(gk_sd_readw((v)) | (mask)))
#define gk_sd_setbitsl(v, mask)    gk_sd_writel((v),(gk_sd_readl((v)) | (mask)))
#define gk_sd_clrbitsb(v, mask)    gk_sd_writeb((v),(gk_sd_readb((v)) & ~(mask)))
#define gk_sd_clrbitsw(v, mask)    gk_sd_writew((v),(gk_sd_readw((v)) & ~(mask)))
#define gk_sd_clrbitsl(v, mask)    gk_sd_writel((v),(gk_sd_readl((v)) & ~(mask)))
#define gk_sd_tstbitsb(v, mask)    (gk_sd_readb((v)) & (mask))
#define gk_sd_tstbitsw(v, mask)    (gk_sd_readw((v)) & (mask))
#define gk_sd_tstbitsl(v, mask)    (gk_sd_readl((v)) & (mask))


#if SF_HAL_MODE
#define gk_sf_readb(a)      gk_hal_readb((a))
#define gk_sf_readw(a)      gk_hal_readw((a))
#define gk_sf_readl(a)      gk_hal_readl((a))
#define gk_sf_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_sf_writew(a, v)  gk_hal_writew((a), (v))
#define gk_sf_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_sf_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_sf_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_sf_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_sf_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_sf_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_sf_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_sf_setbitsb(v, mask)    gk_sf_writeb((v),(gk_sf_readb((v)) | (mask)))
#define gk_sf_setbitsw(v, mask)    gk_sf_writew((v),(gk_sf_readw((v)) | (mask)))
#define gk_sf_setbitsl(v, mask)    gk_sf_writel((v),(gk_sf_readl((v)) | (mask)))
#define gk_sf_clrbitsb(v, mask)    gk_sf_writeb((v),(gk_sf_readb((v)) & ~(mask)))
#define gk_sf_clrbitsw(v, mask)    gk_sf_writew((v),(gk_sf_readw((v)) & ~(mask)))
#define gk_sf_clrbitsl(v, mask)    gk_sf_writel((v),(gk_sf_readl((v)) & ~(mask)))
#define gk_sf_tstbitsb(v, mask)    (gk_sf_readb((v)) & (mask))
#define gk_sf_tstbitsw(v, mask)    (gk_sf_readw((v)) & (mask))
#define gk_sf_tstbitsl(v, mask)    (gk_sf_readl((v)) & (mask))

#if SSI_HAL_MODE
#define gk_ssi_readb(a)      gk_hal_readb((a))
#define gk_ssi_readw(a)      gk_hal_readw((a))
#define gk_ssi_readl(a)      gk_hal_readl((a))
#define gk_ssi_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_ssi_writew(a, v)  gk_hal_writew((a), (v))
#define gk_ssi_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_ssi_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_ssi_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_ssi_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_ssi_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_ssi_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_ssi_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_ssi_setbitsb(v, mask)    gk_ssi_writeb((v),(gk_ssi_readb((v)) | (mask)))
#define gk_ssi_setbitsw(v, mask)    gk_ssi_writew((v),(gk_ssi_readw((v)) | (mask)))
#define gk_ssi_setbitsl(v, mask)    gk_ssi_writel((v),(gk_ssi_readl((v)) | (mask)))
#define gk_ssi_clrbitsb(v, mask)    gk_ssi_writeb((v),(gk_ssi_readb((v)) & ~(mask)))
#define gk_ssi_clrbitsw(v, mask)    gk_ssi_writew((v),(gk_ssi_readw((v)) & ~(mask)))
#define gk_ssi_clrbitsl(v, mask)    gk_ssi_writel((v),(gk_ssi_readl((v)) & ~(mask)))
#define gk_ssi_tstbitsb(v, mask)    (gk_ssi_readb((v)) & (mask))
#define gk_ssi_tstbitsw(v, mask)    (gk_ssi_readw((v)) & (mask))
#define gk_ssi_tstbitsl(v, mask)    (gk_ssi_readl((v)) & (mask))

#if TIMER_HAL_MODE
#define gk_timer_readb(a)      gk_hal_readb((a))
#define gk_timer_readw(a)      gk_hal_readw((a))
#define gk_timer_readl(a)      gk_hal_readl((a))
#define gk_timer_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_timer_writew(a, v)  gk_hal_writew((a), (v))
#define gk_timer_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_timer_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_timer_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_timer_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_timer_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_timer_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_timer_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_timer_setbitsb(v, mask)    gk_timer_writeb((v),(gk_timer_readb((v)) | (mask)))
#define gk_timer_setbitsw(v, mask)    gk_timer_writew((v),(gk_timer_readw((v)) | (mask)))
#define gk_timer_setbitsl(v, mask)    gk_timer_writel((v),(gk_timer_readl((v)) | (mask)))
#define gk_timer_clrbitsb(v, mask)    gk_timer_writeb((v),(gk_timer_readb((v)) & ~(mask)))
#define gk_timer_clrbitsw(v, mask)    gk_timer_writew((v),(gk_timer_readw((v)) & ~(mask)))
#define gk_timer_clrbitsl(v, mask)    gk_timer_writel((v),(gk_timer_readl((v)) & ~(mask)))
#define gk_timer_tstbitsb(v, mask)    (gk_timer_readb((v)) & (mask))
#define gk_timer_tstbitsw(v, mask)    (gk_timer_readw((v)) & (mask))
#define gk_timer_tstbitsl(v, mask)    (gk_timer_readl((v)) & (mask))

#if UART_HAL_MODE
#define gk_uart_readb(a)      gk_hal_readb((a))
#define gk_uart_readw(a)      gk_hal_readw((a))
#define gk_uart_readl(a)      gk_hal_readl((a))
#define gk_uart_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_uart_writew(a, v)  gk_hal_writew((a), (v))
#define gk_uart_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_uart_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_uart_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_uart_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_uart_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_uart_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_uart_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_uart_setbitsb(v, mask)    gk_uart_writeb((v),(gk_uart_readb((v)) | (mask)))
#define gk_uart_setbitsw(v, mask)    gk_uart_writew((v),(gk_uart_readw((v)) | (mask)))
#define gk_uart_setbitsl(v, mask)    gk_uart_writel((v),(gk_uart_readl((v)) | (mask)))
#define gk_uart_clrbitsb(v, mask)    gk_uart_writeb((v),(gk_uart_readb((v)) & ~(mask)))
#define gk_uart_clrbitsw(v, mask)    gk_uart_writew((v),(gk_uart_readw((v)) & ~(mask)))
#define gk_uart_clrbitsl(v, mask)    gk_uart_writel((v),(gk_uart_readl((v)) & ~(mask)))
#define gk_uart_tstbitsb(v, mask)    (gk_uart_readb((v)) & (mask))
#define gk_uart_tstbitsw(v, mask)    (gk_uart_readw((v)) & (mask))
#define gk_uart_tstbitsl(v, mask)    (gk_uart_readl((v)) & (mask))

#if USB_HAL_MODE
#define gk_usb_readb(a)      gk_hal_readb((a))
#define gk_usb_readw(a)      gk_hal_readw((a))
#define gk_usb_readl(a)      gk_hal_readl((a))
#define gk_usb_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_usb_writew(a, v)  gk_hal_writew((a), (v))
#define gk_usb_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_usb_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_usb_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_usb_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_usb_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_usb_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_usb_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_usb_setbitsb(v, mask)    gk_usb_writeb((v),(gk_usb_readb((v)) | (mask)))
#define gk_usb_setbitsw(v, mask)    gk_usb_writew((v),(gk_usb_readw((v)) | (mask)))
#define gk_usb_setbitsl(v, mask)    gk_usb_writel((v),(gk_usb_readl((v)) | (mask)))
#define gk_usb_clrbitsb(v, mask)    gk_usb_writeb((v),(gk_usb_readb((v)) & ~(mask)))
#define gk_usb_clrbitsw(v, mask)    gk_usb_writew((v),(gk_usb_readw((v)) & ~(mask)))
#define gk_usb_clrbitsl(v, mask)    gk_usb_writel((v),(gk_usb_readl((v)) & ~(mask)))
#define gk_usb_tstbitsb(v, mask)    (gk_usb_readb((v)) & (mask))
#define gk_usb_tstbitsw(v, mask)    (gk_usb_readw((v)) & (mask))
#define gk_usb_tstbitsl(v, mask)    (gk_usb_readl((v)) & (mask))

#if VOUT_HAL_MODE
#define gk_vout_readb(a)      gk_hal_readb((a))
#define gk_vout_readw(a)      gk_hal_readw((a))
#define gk_vout_readl(a)      gk_hal_readl((a))
#define gk_vout_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_vout_writew(a, v)  gk_hal_writew((a), (v))
#define gk_vout_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_vout_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_vout_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_vout_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_vout_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_vout_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_vout_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_vout_setbitsb(v, mask)    gk_vout_writeb((v),(gk_vout_readb((v)) | (mask)))
#define gk_vout_setbitsw(v, mask)    gk_vout_writew((v),(gk_vout_readw((v)) | (mask)))
#define gk_vout_setbitsl(v, mask)    gk_vout_writel((v),(gk_vout_readl((v)) | (mask)))
#define gk_vout_clrbitsb(v, mask)    gk_vout_writeb((v),(gk_vout_readb((v)) & ~(mask)))
#define gk_vout_clrbitsw(v, mask)    gk_vout_writew((v),(gk_vout_readw((v)) & ~(mask)))
#define gk_vout_clrbitsl(v, mask)    gk_vout_writel((v),(gk_vout_readl((v)) & ~(mask)))
#define gk_vout_tstbitsb(v, mask)    (gk_vout_readb((v)) & (mask))
#define gk_vout_tstbitsw(v, mask)    (gk_vout_readw((v)) & (mask))
#define gk_vout_tstbitsl(v, mask)    (gk_vout_readl((v)) & (mask))

#if WDT_HAL_MODE
#define gk_wdt_readb(a)      gk_hal_readb((a))
#define gk_wdt_readw(a)      gk_hal_readw((a))
#define gk_wdt_readl(a)      gk_hal_readl((a))
#define gk_wdt_writeb(a, v)  gk_hal_writeb((a), (v))
#define gk_wdt_writew(a, v)  gk_hal_writew((a), (v))
#define gk_wdt_writel(a, v)  gk_hal_writel((a), (v))
#else
#define gk_wdt_readb(a)      (*((volatile unsigned char*)(a)))
#define gk_wdt_readw(a)      (*((volatile unsigned short*)(a)))
#define gk_wdt_readl(a)      (*((volatile unsigned int*)(a)))
#define gk_wdt_writeb(a, v)  ((*((volatile unsigned char*)(a))) = (v))
#define gk_wdt_writew(a, v)  ((*((volatile unsigned short*)(a))) = (v))
#define gk_wdt_writel(a, v)  ((*((volatile unsigned int*)(a))) = (v))
#endif
#define gk_wdt_setbitsb(v, mask)    gk_wdt_writeb((v),(gk_wdt_readb((v)) | (mask)))
#define gk_wdt_setbitsw(v, mask)    gk_wdt_writew((v),(gk_wdt_readw((v)) | (mask)))
#define gk_wdt_setbitsl(v, mask)    gk_wdt_writel((v),(gk_wdt_readl((v)) | (mask)))
#define gk_wdt_clrbitsb(v, mask)    gk_wdt_writeb((v),(gk_wdt_readb((v)) & ~(mask)))
#define gk_wdt_clrbitsw(v, mask)    gk_wdt_writew((v),(gk_wdt_readw((v)) & ~(mask)))
#define gk_wdt_clrbitsl(v, mask)    gk_wdt_writel((v),(gk_wdt_readl((v)) & ~(mask)))
#define gk_wdt_tstbitsb(v, mask)    (gk_wdt_readb((v)) & (mask))
#define gk_wdt_tstbitsw(v, mask)    (gk_wdt_readw((v)) & (mask))
#define gk_wdt_tstbitsl(v, mask)    (gk_wdt_readl((v)) & (mask))

#endif

#endif /* __ASSEMBLER__ */
/* ==========================================================================*/

#endif /* __ASM_ARM_ARCH_IO_H */
