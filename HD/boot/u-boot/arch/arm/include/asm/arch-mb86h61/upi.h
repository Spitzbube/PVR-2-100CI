/*
 *  arch/arm/mach-mb86hxx/include/mach/upi_ata.h
 *
 * Copyright (C) 2010 FUJITSU MICROELECTRONICS LIMITED
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


#ifndef __ARM_MACH_UPI_H
#define __ARM_MACH_UPI_H

#include <asm/arch/mb86hxx.h>

/*************************************************************
 * UPI0/1/2 common part
 *************************************************************/

/* UPI Device Config Register Base */
#define MB86H61_UPI0_CONFIG_BASE	(MB86HXX_UPI_BASE + 0x18000000)
#define MB86H61_UPI1_CONFIG_BASE	(MB86HXX_UPI_BASE + 0x18000040)
#define MB86H61_UPI2_CONFIG_BASE	(MB86HXX_UPI_BASE + 0x18000080)

/*************************************************************
 * FLASH part
 *************************************************************/

/* UPI Device Config Register Offset */
#define MB86H61_UPI_MODE_OFFSET		0x00
#define MB86H61_UPI_TALS_OFFSET		0x04
#define MB86H61_UPI_TALH_OFFSET		0x08
#define MB86H61_UPI_TRS_OFFSET		0x0C
#define MB86H61_UPI_TRDS_OFFSET		0x10
#define MB86H61_UPI_TRDH_OFFSET		0x14
#define MB86H61_UPI_TRR_OFFSET		0x18
#define MB86H61_UPI_TWS_OFFSET		0x1C
#define MB86H61_UPI_TWP_OFFSET		0x20
#define MB86H61_UPI_TWR_OFFSET		0x24
#define MB86H61_UPI_WMMASK_OFFSET	0x28
#define MB86H61_UPI_BUFEN_OFFSET	0x2C

#define MB86H61_UPI_ADDREXT			(MB86HXX_UPI_BASE + 0x180000C0)

/* UPI_ADDREXT Bit Flags */
#define ADDREXT_EXT_MODE_0_BIT	(1 << 0)
#define ADDREXT_EXT_MODE_1_BIT	(1 << 1)
#define ADDREXT_EXT_MODE_2_BIT	(1 << 2)
#define ADDREXT_LIN_MODE_0_BIT	(1 << 3)
#define ADDREXT_LIN_MODE_1_BIT	(1 << 4)
#define ADDREXT_LIN_MODE_2_BIT	(1 << 5)

#define MB86H61_UPI_CSSEL			(MB86HXX_UPI_BASE + 0x180000C4)
#define MB86H61_UPI_CSMODE			(MB86HXX_UPI_BASE + 0x180000C8)

/* UPI_CSMODE Bit Flags*/
#define CSMODE_CS1_INVERT_BIT	(1 << 0)
#define CSMODE_CS2_INVERT_BIT	(1 << 1)
#define CSMODE_CS1_WEMODE_BIT	(1 << 2)
#define CSMODE_CS2_WEMODE_BIT	(1 << 3)

#define MB86H61_UPI_WAIT_TIME			(MB86HXX_UPI_BASE + 0x18000030)
#define MB86H61_UPI_WAIT_TIME_EN		(MB86HXX_UPI_BASE + 0x18000034)
#define MB86H61_UPI_LAST_WAIT_TIME		(MB86HXX_UPI_BASE + 0x18000038)
#define MB86H61_UPI_WAIT_TIME_STATUS	(MB86HXX_UPI_BASE + 0x1800003C)

/* UPI_WAIT_TIME_STATUS Bit Flags */
#define WTSTS_WAIT_TIME_ACT_BIT		(1 << 0)
#define WTSTS_WAIT_LINE_STATUS_BIT	(1 << 1)

#if 0
#define UPI_MODE_PARAM		0x01
#define UPI_TALS_PARAM		0x02
#define UPI_TALH_PARAM		0x02
#define UPI_TRS_PARAM		0x02
#define UPI_TRDS_PARAM		0x13
#define UPI_TRDH_PARAM		0x02
#define UPI_TRR_PARAM		0x05
#define UPI_TWS_PARAM		0x05
#define UPI_TWP_PARAM		0x09
#define UPI_TWR_PARAM		0x02
#define UPI_WMMASK_PARAM	0x01
#define UPI_BUFEN_PARAM		0x00
#endif
#define UPI_MODE_PARAM                  0x03
#define UPI_TALS_PARAM                  0x0
#define UPI_TALH_PARAM                  0x0
#define UPI_TRS_PARAM                   0x0
#define UPI_TRDS_PARAM                  0x06
#define UPI_TRDH_PARAM                  0x0
#define UPI_TRR_PARAM                   0x0
#define UPI_TWS_PARAM                   0x0
#define UPI_TWP_PARAM                   0x06
#define UPI_TWR_PARAM                   0x0
#define UPI_WMMASK_PARAM                0x01
#define UPI_BUFEN_PARAM                 0x0


#define UPI_ADDREXT_PARAM		0x00
#define UPI_CSSEL_PARAM			0x00
#define UPI_CSMODE_PARAM		0x00
#define UPI_WAIT_TIME_PARAM		0x00
#define UPI_WAIT_TIME_EN_PARAM		0x00

#if 1
#define UPI_LAST_WAIT_TIME_PARAM	0x00
#define UPI_WAIT_TIME_STATUS_PARAM	0x03
#endif

/*************************************************************
 * ATA/IDE part
 *************************************************************/

/** Hard disk reset timing **/
#define MB86HXX_ATA_RESET_ON_MWAIT   50    /* Reset on duration (msec) */
#define MB86HXX_ATA_RESET_OFF_MWAIT  50    /* After reset wait  (msec) */

/* UPI2 related registers */
#define REG_UPI_MODE_0         		0x18000000
#define REG_UPI_MODE_2         		0x18000080
#define REG_UPI_BUFEN_2        		0x180000AC
#define REG_UPI_CSSEL          		0x180000C4
#define REG_UPI_ATACTL		   		0x18001000
#define REG_UPI_IODATA		   		0x18001040
#define REG_LCX373MTC		   		0x18001060

/** ATA related register offsets **/
#define MB86HXX_ATA_CFG_BASE     	(MB86HXX_UPI_BASE + REG_UPI_ATACTL) /* Controller address */
#define MB86HXX_ATA_IO_BASE      	(MB86HXX_UPI_BASE + REG_UPI_IODATA) /* ATA IO registers */
#define MB86HXX_LCX373MTC_BASE   	(MB86HXX_UPI_BASE + REG_LCX373MTC) /* Latch logic */

/** ATA Controller(OCIDEC-3) access macros **/
#define __get_MB86HXX_ATA_CFG(X) ({ *((volatile uint32_t*)(MB86HXX_ATA_CFG_BASE + (X))); })
#define __set_MB86HXX_ATA_CFG(X,V) {(*((volatile uint32_t*)( MB86HXX_ATA_CFG_BASE + (X) )) = V);}

/* OCIDEC-3 registers address*/
#define OCIDEC3_CFG_CTRL   0x00
#define OCIDEC3_CFG_STAT   0x04
#define OCIDEC3_CFG_PCTR   0x08
#define OCIDEC3_CFG_PFTR0  0x0C
#define OCIDEC3_CFG_PFTR1  0x10
#define OCIDEC3_CFG_DTR0   0x14
#define OCIDEC3_CFG_DTR1   0x18
#define OCIDEC3_CFG_DTxDB  0x3C

/* Macros for OCIDEC-3 Control registers */
#define CTRL_TOC_SHIFT		24
#define CTRL_TOC_MASK		(0xFF << CTRL_TOC_SHIFT )
#define CTRL_DMAba			(1 << 16)
#define CTRL_DMAen			(1 << 15)
#define CTRL_DMAdir_WRITE	(1 << 14)
#define CTRL_BeLeC1			(1 << 9)
#define CTRL_BeLeC0			(1 << 8)
#define CTRL_IDEen			(1 << 7)
#define CTRL_FTE1			(1 << 6)
#define CTRL_FTE0			(1 << 5)
#define CTRL_PWPP			(1 << 4)
#define CTRL_IORDYen_ft1	(1 << 3)
#define CTRL_IORDYen_ft0	(1 << 2)
#define CTRL_IORDYen_ct		(1 << 1)
#define CTRL_ATA_BUF_EN		(1)

/* Macros for OCIDEC-3 Status registers */
#define STAT_DMAFIFOF_SHIFT	20
#define STAT_DMAFIFOF_MASK	(0xF <<  STAT_DMAFIFOF_SHIFT )
#define STAT_DMAFIFOU_SHIFT	16
#define STAT_DMAFIFOU_MASK	(0xF <<  STAT_DMAFIFOU_SHIFT )
#define STAT_DMAtip			(1 << 15)
#define STAT_DMAbe			(1 << 10)
#define STAT_DMAbf			(1 << 9)
#define STAT_DMARQ			(1 << 8)
#define STAT_PIOtip			(1 << 7)
#define STAT_PWPPF			(1 << 6)
#define STAT_TIMEOUT		(1)

/* Macros for OCIDEC-3 PIO Timing registers */
#define PxTR_Teoc_SHIFT		24
#define PxTR_Teoc_MASK		(0xFF <<  PxTR_Teoc_SHIFT )
#define PxTR_T4_SHIFT		16
#define PxTR_T4_MASK		(0xFF <<  PxTR_T4_SHIFT )
#define PxTR_T2_SHIFT		8
#define PxTR_T2_MASK		(0xFF <<  PxTR_T2_SHIFT )
#define PxTR_T1_SHIFT		0
#define PxTR_T1_MASK		(0xFF)

/* Macros for OCIDEC-3 DMA Timing registers */
#define DTR_Teoc_SHIFT		24
#define DTR_Teoc_MASK		(0xFF <<  DTR_Teoc_SHIFT )
#define DTR_Td_SHIFT		8
#define DTR_Td_MASK			(0xFF <<  DTR_Td_SHIFT )
#define DTR_Tm_SHIFT		0
#define DTR_Tm_MASK			(0xFF)


/** Latch logic(LCX373MTC) access macros **/
#define __get_MB86HXX_LCX373MTC()	({ *((volatile uint32_t*)(MB86HXX_LCX373MTC_BASE)); })
#define __set_MB86HXX_LCX373MTC(V)	{(*((volatile uint32_t*)( MB86HXX_LCX373MTC_BASE)) = V);}

/* Macros for Latch logic bit */
#define LCX373MTC_HDRST_BIT	1


/** IDE Timing setting structure **/
struct ocidec3_ModeParam {
	u8	Teoc;	/* End of Cycle Time */
	u8	T4;		/* DIOW-data hold */
	u8	T2;		/* DIOR/DIOW-pulse width */
	u8	T1;		/* Address valid to DIOR/DIOW */
};

#endif /* __ARM_MACH_UPI_H */
