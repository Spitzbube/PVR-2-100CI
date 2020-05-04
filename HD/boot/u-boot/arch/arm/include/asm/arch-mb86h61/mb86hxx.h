/*
 * arch/arm/mach-mb86hxx/include/mach/mb86hxx.h
 *
 * Copyright (C) 2008 FUJITSU MICROELECTRONICS LIMITED
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
#ifndef __ARCH_ARM_MACH_MB86HXX_H
#define __ARCH_ARM_MACH_MB86HXX_H

/* Clocks */
#define MB86HXX_CPU_HZ          396000000        /* Core    */
#define MB86HXX_AXI_HZ          198000000        /* AXI/AHB */
#define MB86HXX_AVH_HZ          198000000        /* AV High */
#define MB86HXX_HDMIH_HZ        148500000        /* HDMI Hi */

#define MB86HXX_APB_HZ          (MB86HXX_AXI_HZ / 2)  /* APB     */
#define MB86HXX_AVM_HZ          (MB86HXX_AVH_HZ / 4)  /* AV Mid  */
#define MB86HXX_AVL_HZ          (MB86HXX_AVH_HZ / 8)  /* AV Low  */

/* Memory Map */
#define MB86HXX_BOOTROM_BASE    0x00000000
#define MB86HXX_SRAM_BASE       0x02000000
#define MB86HXX_DDR1_BASE       0x20000000

#define MB86HXX_UART0_BASE      0xCD000000
#define MB86HXX_I2C0_BASE       0xD1000000
#define MB86HXX_SSP0_BASE       0xD4000000
#define MB86HXX_SSP1_BASE       0xD5000000
#define MB86HXX_EFUSE_BASE      0xC4000000
#define MB86HXX_ETH_BASE        0xE2000000

/* new module for H61*/
#define MB86HXX_IRP_BASE        0xC2000000
#define MB86HXX_R2R_BASE        0xC6000000
#define MB86HXX_CEC_BASE        0xC9000000
#define MB86HXX_HDMI_BASE       0xD0000000
#define MB86HXX_GRAPHENG_BASE   0xD6000000
#define MB86HXX_ADC_BASE        0xD7000000
#define MB86HXX_AXICFG_BASE     0xDC000000
#define MB86HXX_SATA_BASE       0xE4000000
#define MB86HXX_HDMAC_BASE      0xE6000000
#define MB86HXX_NAND_BASE       0xE8000000
#define MB86HXX_NANDCFG_BASE    0xEA000000
#define MB86HXX_SDIO_BASE       0xEC000000

#define MB86HXX_DDR2_BASE       0x40000000
#define MB86HXX_VIDDEC_BASE     0x60000000
#define MB86HXX_PINT_BASE       0x610e0000
#define MB86HXX_UPI_BASE        0x80000000
#define MB86HXX_SFLASH_BASE     0xC0000000
#define MB86HXX_IRR_BASE        0xC1000000
#define MB86HXX_GPIO_BASE       0xC3000000
#define MB86HXX_ICC_BASE        0xC5000000
#define MB86HXX_DMA_BASE        0xC7000000
#define MB86HXX_USB_BASE        0xC7000800
#define MB86HXX_TSD_BASE        0xC8000000
#define MB86HXX_CLKPWR_BASE     0xCA000000
#define MB86HXX_VIDOUT_BASE     0xCB000000
#define MB86HXX_AUD_BASE        0xCC000000
#define MB86HXX_UART1_BASE      0xCE000000
#define MB86HXX_TIMER0_BASE     0xCF000000
#define MB86HXX_TIMER1_BASE     0xCF000040
#define MB86HXX_TIMER2_BASE     0xCF000080
#define MB86HXX_IRC_BASE        0xCF000200
#define MB86HXX_I2C1_BASE       0xD2000000
#define MB86HXX_I2C2_BASE       0xD3000000
#define MB86HXX_PIRLO_BASE      0xDB000000
#define MB86HXX_SCHED_BASE      0xDC000000
#define MB86HXX_RAMIFS_BASE     0xDD000000
#define MB86HXX_RAMIFV_BASE     0xDE000000
#define MB86HXX_VIC_BASE        0xE0000000

/* IRQ Signal Map */
#define IRQ_RESERVED0           0
#define IRQ_COMMRx              1
#define IRQ_COMMTx              2
#define IRQ_RESERVED3           3
#define IRQ_RESERVED4           4
#define IRQ_TIMER0              5
#define IRQ_TIMER1              6
#define IRQ_TIMER2              7
#define IRQ_UART0               8
#define IRQ_UART1               9
#define IRQ_SSP0                10
#define IRQ_SSP1                11
#define IRQ_ICC0                12
#define IRQ_ICC1                13
#define IRQ_IRR                 14
#define IRQ_I2C0                15
#define IRQ_I2C1                16
#define IRQ_I2C2                17
#define IRQ_VIDDEC              18
#define IRQ_GPIO                19
#define IRQ_DMA                 20
#define IRQ_USB                 21
#define IRQ_ETH                 22
#define IRQ_AUD                 23
#define IRQ_TSDBM01             24
#define IRQ_TSDBM23             25
#define IRQ_TSD01               26
#define IRQ_TSD23               27
#define IRQ_VIDOUT0             28
#define IRQ_VIDOUT1             29
#define IRQ_VIDOUT2             30
#define IRQ_RESERVED31          31

/* IRC */
#define IRC_VA_BASE             MB86HXX_IRC_VA_BASE
#define IRC_ARC_VALID_IRQ_MASK  0x0           /* mask all */
#define IRC_ARM_VALID_IRQ_MASK  0xFFFFFFFF    /* no mask */

/* VIC */
#define VIC_BASE                MB86HXX_VIC_BASE
#define VIC_VA_BASE             MB86HXX_VIC_VA_BASE
#define VIC_VALID_IRQ_MASK      0xFFFFFFFF
 /* all interrupts enabled */

/* Timer */
#define TIMER_HZ                MB86HXX_APB_HZ
#define TIMER_VA_BASE           MB86HXX_TIMER0_VA_BASE
#define IRQMASK_TIMERINT        IRQ_TIMER0

/* UART */
#define UART_HZ                 MB86HXX_APB_HZ
#define UART_BASE               MB86HXX_UART0_BASE
#define UART_VA_BASE            MB86HXX_UART0_BASE

/* Ethernet */
#define ETH_MHZ                 MB86HXX_APB_HZ/1000000

/* UPI */
#define UPI_HZ                  MB86HXX_AXI_HZ

/* USB */
#define USB_HZ                  MB86HXX_APB_HZ

/* UPI --- nand */
#define MB86H61_NAND_CMD_OFFSET         0x0
#define MB86H61_NAND_ADDR_OFFSET        0x4
#define MB86H61_NAND_DATA_OFFSET        0x8
#define MB86H61_NAND_END_OFFSET         0xc


/* UPI Device Config Register Offset */
#define MB86H61_UPI_MODE_OFFSET         0x00
#define MB86H61_UPI_TALS_OFFSET         0x04
#define MB86H61_UPI_TALH_OFFSET         0x08
#define MB86H61_UPI_TRS_OFFSET          0x0C
#define MB86H61_UPI_TRDS_OFFSET         0x10
#define MB86H61_UPI_TRDH_OFFSET         0x14
#define MB86H61_UPI_TRR_OFFSET          0x18
#define MB86H61_UPI_TWS_OFFSET          0x1C
#define MB86H61_UPI_TWP_OFFSET          0x20
#define MB86H61_UPI_TWR_OFFSET          0x24
#define MB86H61_UPI_WMMASK_OFFSET       0x28
#define MB86H61_UPI_BUFEN_OFFSET        0x2C

#define MB86H61_UPI_ADDREXT             (MB86HXX_UPI_BASE + 0x180000C0)
#define MB86H61_UPI_CSSEL               (MB86HXX_UPI_BASE + 0x180000C4)
#define MB86H61_UPI_CSMODE              (MB86HXX_UPI_BASE + 0x180000C8)

#define MB86H61_UPI_WAIT_TIME           (MB86HXX_UPI_BASE + 0x18000030)
#define MB86H61_UPI_WAIT_TIME_EN        (MB86HXX_UPI_BASE + 0x18000034)
#define MB86H61_UPI_LAST_WAIT_TIME      (MB86HXX_UPI_BASE + 0x18000038)
#define MB86H61_UPI_WAIT_TIME_STATUS    (MB86HXX_UPI_BASE + 0x1800003C)



#endif        /* __ARCH_ARM_MACH_MB86HXX_H */
