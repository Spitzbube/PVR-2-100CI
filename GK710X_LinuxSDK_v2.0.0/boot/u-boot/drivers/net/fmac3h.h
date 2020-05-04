/*
 * Copyright (C) 2010-2011 FUJITSU SEMICONDUCTOR LIMITED
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 * FMAC3H Ethernet
 */

#ifndef _FMAC3H_H
#define _FMAC3H_H
#include <asm/types.h>
#include <config.h>
#include <asm/arch/gk6202.h>


/*
 * F_GMAC4 Register Address Map
 */
#define FMAC3H_MCR	0x0000	/* MAC Configuration Register          */
#define FMAC3H_MFFR	0x0004	/* MAC Frame Filter Register           */
#define FMAC3H_MHTRH	0x0008	/* MAC Hash Table Register(High)       */
#define FMAC3H_MHTRL	0x000C	/* MAC Hash Table Register(Low)        */

#define FMAC3H_GAR	0x0010	/* GMII Address Register */
#define FMAC3H_GDR	0x0014	/* GMII Data Register    */

#define FMAC3H_FCR	0x0018	/* Flow Control Register               */
#define FMAC3H_VTR	0x001C	/* VLAN Tag Register                   */
#define FMAC3H_RWFFR	0x0028	/* Remote Wake-up Frame FilterRegister */
#define FMAC3H_PMTR	0x002C	/* PMT Register                        */
#define FMAC3H_MAR0H	0x0040	/* MAC Address0 Register(High)  */
#define FMAC3H_MAR0L	0x0044	/* MAC Address0 Register(Low)   */
#define FMAC3H_MAR1H	0x0048	/* MAC Address1 Register(High)  */
#define FMAC3H_MAR1L	0x004C	/* MAC Address1 Register(Low)   */
#define FMAC3H_MAR2H	0x0050	/* MAC Address2 Register(High)  */
#define FMAC3H_MAR2L	0x0054	/* MAC Address2 Register(Low)   */
#define FMAC3H_MAR3H	0x0058	/* MAC Address3 Register(High)  */
#define FMAC3H_MAR3L	0x005C	/* MAC Address3 Register(Low)   */
#define FMAC3H_MAR4H	0x0060	/* MAC Address4 Register(High)  */
#define FMAC3H_MAR4L	0x0064	/* MAC Address4 Register(Low)   */
#define FMAC3H_MAR5H	0x0068	/* MAC Address5 Register(High)  */
#define FMAC3H_MAR5L	0x006C	/* MAC Address5 Register(Low)   */
#define FMAC3H_MAR6H	0x0070	/* MAC Address6 Register(High)  */
#define FMAC3H_MAR6L	0x0074	/* MAC Address6 Register(Low)   */
#define FMAC3H_MAR7H	0x0078	/* MAC Address7 Register(High)  */
#define FMAC3H_MAR7L	0x007C	/* MAC Address7 Register(Low)   */
#define FMAC3H_MAR8H	0x0080	/* MAC Address8 Register(High)  */
#define FMAC3H_MAR8L	0x0084	/* MAC Address8 Register(Low)   */
#define FMAC3H_MAR9H	0x0088	/* MAC Address9 Register(High)  */
#define FMAC3H_MAR9L	0x008C	/* MAC Address9 Register(Low)   */
#define FMAC3H_MAR10H	0x0090	/* MAC Address10 Register(High) */
#define FMAC3H_MAR10L	0x0094	/* MAC Address10 Register(Low)  */
#define FMAC3H_MAR11H	0x0098	/* MAC Address11 Register(High) */
#define FMAC3H_MAR11L	0x009C	/* MAC Address11 Register(Low)  */
#define FMAC3H_MAR12H	0x00A0	/* MAC Address12 Register(High) */
#define FMAC3H_MAR12L	0x00A4	/* MAC Address12 Register(Low)  */
#define FMAC3H_MAR13H	0x00A8	/* MAC Address13 Register(High) */
#define FMAC3H_MAR13L	0x00AC	/* MAC Address13 Register(Low)  */
#define FMAC3H_MAR14H	0x00B0	/* MAC Address14 Register(High) */
#define FMAC3H_MAR14L	0x00B4	/* MAC Address14 Register(Low)  */
#define FMAC3H_MAR15H	0x00B8	/* MAC Address15 Register(High) */
#define FMAC3H_MAR15L	0x00BC	/* MAC Address15 Register(Low)  */

/* 0x0100-0x0284 MMC(MAC Management Counters(Option)) */
/* MMC(MAC Management Counters) Register Address Map */
#define FMAC3H_MMC_CNTL			0x0100
#define FMAC3H_MMC_INTR_RX		0x0104
#define FMAC3H_MMC_INTR_TX		0x0108
#define FMAC3H_MMC_INTR_MASK_RX		0x010C
#define FMAC3H_MMC_INTR_MASK_TX		0x0110
#define FMAC3H_MMC_TX_OCT_CNT		0x0114
#define FMAC3H_MMC_TX_FRA_CNT		0x0118
#define FMAC3H_MMC_TX_BCAST_FRA		0x011C
#define FMAC3H_MMC_TX_MCAST_FRA		0x0120
#define FMAC3H_MMC_TX_64_OCT		0x0124
#define FMAC3H_MMC_TX_65_127_OCT	0x0128
#define FMAC3H_MMC_TX_128_255_OCT	0x012C
#define FMAC3H_MMC_TX_256_511_OCT	0x0130
#define FMAC3H_MMC_TX_512_1023_OCT	0x0134
#define FMAC3H_MMC_TX_1024_OCT		0x0138
#define FMAC3H_MMC_TX_UCAST_FRA_GB	0x013C
#define FMAC3H_MMC_TX_MCAST_FRA_GB	0x0140
#define FMAC3H_MMC_TX_BCAST_FRA_GB	0x0144
#define FMAC3H_MMC_TX_FLOW_ERR		0x0148
#define FMAC3H_MMC_TX_SINGLE_COL	0x014C
#define FMAC3H_MMC_TX_MULTI_COL		0x0150
#define FMAC3H_MMC_TX_DEFER		0x0154
#define FMAC3H_MMC_TX_LATE_COL		0x0158
#define FMAC3H_MMC_TX_EXESS_COL		0x015C
#define FMAC3H_MMC_TX_CARRY_ERR		0x0160
#define FMAC3H_MMC_TX_OCT_CNT_G		0x0164
#define FMAC3H_MMC_TX_FRA_CNT_G		0x0168
#define FMAC3H_MMC_TX_EXE_DEF		0x016C
#define FMAC3H_MMC_TX_PAUSE_FRA		0x0170
#define FMAC3H_MMC_TX_VLAN_FRA		0x0174
#define FMAC3H_MMC_RX_FRA_CNT		0x0180
#define FMAC3H_MMC_RX_OCT_CNT		0x0184
#define FMAC3H_MMC_RX_OCT_CNT_G		0x0188
#define FMAC3H_MMC_RX_BCAST_FRA		0x018C
#define FMAC3H_MMC_RX_MCAST_FRA		0x0190
#define FMAC3H_MMC_RX_CRC_ERR		0x0194
#define FMAC3H_MMC_RX_ALLIGN_ERR	0x0198
#define FMAC3H_MMC_RX_RUNT_ERR		0x019C
#define FMAC3H_MMC_RX_JAB_ERR		0x01A0
#define FMAC3H_MMC_RX_UNDER_SIZE	0x01A4
#define FMAC3H_MMC_RX_OVER_SIZE		0x01A8
#define FMAC3H_MMC_RX_64_OCT		0x01AC
#define FMAC3H_MMC_RX_65_127_OCT	0x01B0
#define FMAC3H_MMC_RX_128_255_OCT	0x01B4
#define FMAC3H_MMC_RX_256_511_OCT	0x01B8
#define FMAC3H_MMC_RX_512_1023_OCT	0x01BC
#define FMAC3H_MMC_RX_1024_OCT		0x01C0
#define FMAC3H_MMC_RX_UCAST_FRA		0x01C4
#define FMAC3H_MMC_RX_LEN_ERR		0x01C8
#define FMAC3H_MMC_RX_OUT_RANGE		0x01CC
#define FMAC3H_MMC_RX_PAUSE_FRA		0x01D0
#define FMAC3H_MMC_RX_OVER_FLOW		0x01D4
#define FMAC3H_MMC_RX_VLAN_FRA		0x01D8
#define FMAC3H_MMC_RX_WTDOG_ERR		0x01DC

/* MMC_CNTL:MMC Control Register */
#define RESET_ON_READ		0x00000004	/* Auto clear after is readed */
#define STOP_ROLL_OVER		0x00000002	/* Stop when arrive MAX       */
#define CLEAR_ALL		0x00000001	/* Clear all MMC register     */
#define MMC_INTR_MASK		0xFFFFFFFF	/* Mask MMC interrupt         */

#define FMAC3H_TSCR	0x0700	/* Time Stamp Control Register */
#define FMAC3H_SIR	0x0704	/* Sub-Second Increment Register */
#define FMAC3H_TSHR	0x0708	/* Time Stamp High Register */
#define FMAC3H_TSLR	0x070C	/* Time Stamp Low Register */
#define FMAC3H_TSHUR	0x0710	/* Time Stamp High Update Register */
#define FMAC3H_TSLUR	0x0714	/* Time Stamp Low Update Register */
#define FMAC3H_TSAR	0x0718	/* Time Stamp Addend Register */
#define FMAC3H_TTHT	0x071C	/* Target Time High Register */
#define FMAC3H_TTLR	0x0720	/* Target Time low Register */
#define FMAC3H_TSSR	0x0724	/* Time Stamp Status Register */
#define FMAC3H_PCR	0x072C	/* PPC Control Register */
#define FMAC3H_ATNR	0x0730	/* Auxiliary Time Stamp-Nanosecond Register */
#define FMAC3H_ATSR	0x0734	/* Auxiliary Time Stamp-Second Register */

#define FMAC3H_BMR	0x1000	/* DMA BUS Mode Register                   */
#define FMAC3H_TPDR	0x1004	/* DMA Transmit Poll Demand Register       */
#define FMAC3H_RPDR	0x1008	/* DMA Receive Poll Demand Register        */
#define FMAC3H_RDLAR	0x100C	/* DMA Receive Desc List Address Register  */
#define FMAC3H_TDLAR	0x1010	/* DMA Transmit Desc List Address Register */
#define FMAC3H_SR	0x1014	/* DMA Status Register                     */
#define FMAC3H_OMR	0x1018	/* DMA Operation Mode Register             */
#define FMAC3H_IER	0x101C	/* DMA Interrupt Enable Register           */
#define FMAC3H_MFC	0x1020	/* DMA Missed Frame Register               */
#define FMAC3H_CHTDR	0x1048	/* DMA Cur Host Transmit Desc Register     */
#define FMAC3H_CHRDR	0x104C	/* DMA Cur Host Receive Desc Register      */
#define FMAC3H_CHTBAR	0x1050	/* DMA Cur Host TX Buffer Address Register */
#define FMAC3H_CHRBAR	0x1054	/* DMA Cur Host RX Buffer Address Register */

/*
 * Values and Masks
 */
#define SET_0		0x00000000
#define SET_1		0xFFFFFFFF
/* MCR:MAC Configuration Register */
#define MCR_CST		0x02000000	/* CRC stripping for Type frames   */
#define MCR_TC		0x01000000	/* Transmit Configuration in RGMII */
#define MCR_WD		0x00800000	/* Disable RX Watchdog timeout  */
#define MCR_JD		0x00400000	/* Disable TX Jabber timer      */
#define MCR_BE		0x00200000	/* Frame Burst Enable           */
#define MCR_JE		0x00100000	/* Jumbo Frame Enable           */
#define MCR_DCRS	0x00010000	/* Disable Carrier During Trans */
#define MCR_DO		0x00002000	/* Disable Receive Own          */
#define MCR_LM		0x00001000	/* Loop-back Mode               */
#define MCR_DR		0x00000200	/* Disable Retry                */
#define MCR_ACS		0x00000080	/* Automatic Pad/CRC Stripping  */
#define MCR_BL_00	0x00000000	/* Back-off Limit is setted 0   */
#define MCR_DC		0x00000010	/* Deferral Check               */
#define MCR_TX_ENABLE	0x00000008	/* Enable Transmitter           */
#define MCR_RX_ENABLE	0x00000004	/* Enable Receiver              */
	/* bit15:PS(Port Select) */
#define GMII_PORT	0x0
#define MII_PORT	0x00008000
	/* bit11:DM(Duplex mode) */
#define HALF_DUPLEX	0x0
#define FULL_DUPLEX	0x00000800

/* MFFR:MAC Frame Filter Register */
#define REC_ALL_OFF		0x00000000 /* Not Receive all frame        */
#define REC_ALL_ON		0x80000000 /* Receive all frame            */
#define PASS_CTL_OFF		0x00000000 /* Not pass control frames      */
#define BRO_FRA_RX		0x00000000 /* Receive broadcast frames     */
#define PASS_ALL_MUL_OFF	0x00000000 /* Not pass all multicast       */
#define PASS_ALL_MUL_ON		0x00000010 /* pass all multicast           */
#define INV_FILTER_OFF		0x00000000 /* Not inverse filtering        */
#define HASH_ONLY_OFF		0x00000000 /* OFF Hash Only Filtering Mode */
#define HASH_PERFECT_OFF	0x00000000 /* OFF HashPerfect Filtering    */
#define PROMIS_OFF		0x00000000 /* OFF Promiscuous Mode         */
#define PROMIS_MODE		0x00000001 /* Promiscuous Mode             */

/* GAR:GMII Address Register */
#define GAR_GW_R		0x00000000	/* GMII/MII Read  */
#define GAR_GW_W		0x00000002	/* GMII/MII Write */
#define GAR_GB			0x00000001	/* GMII/MII Busy  */

/* BMR:MDC Bus Mode Register */
#define BMR_TXPR	0x08000000	/* Transmit Pririty Higher Than Recevice */
#define BMR_MB		0x04000000	/* Mixed Burst                     */
#define BMR_AAL		0x02000000	/* Address-Aligned Beats           */
#define BMR_8XPBL	0x01000000	/* MAX burst is 8times of PBL      */
#define BMR_USP		0x00800000	/* RxDMA TxDMA Use Separate PBL    */
#define BMR_RPBL_32	0x00400000	/* RX Burst Length is 32 Bytes     */
#define BMR_RPBL_16	0x00200000	/* RX Burst Length is 16 Bytes     */
#define BMR_RPBL_8	0x00100000	/* RX Burst Length is 8 Bytes      */
#define BMR_RPBL_4	0x00080000	/* RX Burst Length is 4 Bytes      */
#define BMR_RPBL_2	0x00040000	/* RX Burst Length is 2 Bytes      */
#define BMR_RPBL_1	0x00020000	/* RX Burst Length is 1 Bytes      */
#define BMR_FB		0x00010000	/* AHB Fixed Burst Mode            */
#define BMR_PR_00	0x00000000	/* RX TX Priority ratio is 1:1     */
#define BMR_PR_01	0x00004000	/* RX TX Priority ratio is 2:1     */
#define BMR_PR_10	0x00008000	/* RX TX Priority ratio is 3:1     */
#define BMR_PR_11	0x0000C000	/* RX TX Priority ratio is 4:1     */
#define BMR_PBL_32	0x00002000	/* Burst Length is 32 Bytes        */
#define BMR_PBL_16	0x00001000	/* Burst Length is 16 Bytes        */
#define BMR_PBL_8	0x00000800	/* Burst Length is 8 bytes         */
#define BMR_PBL_4	0x00000400	/* Burst Length is 4 Bytes         */
#define BMR_PBL_2	0x00000200	/* Burst Length is 2 Bytes         */
#define BMR_PBL_1	0x00000100	/* Burst Length is 1 Bytes         */
#define BMR_ATDS	0x00000080	/* Alternate Descriptor Size       */
#define BMR_DSL		0x00000000	/* Descripter Skip Length          */
#define BMR_DA		0x00000002	/* RX have priority                */
#define BMR_SOFTWARE_RESET	0x00000001 /* software reset, init all regs */


/* OMR:MDC Operation Mode Register */
#define OMR_RSF		0x00200000	/* TX after whole frame in FIFO */
#define START_TX	0x00002000	/* Start Transmissin            */
#define START_RX	0x00000002	/* Start Receive                */
#define OMR_TTC_64B	0x00000000	/* TX after 64byte written in FIFO  */
#define OMR_TTC_128B	0x00004000	/* TX after 128byte written in FIFO */
#define OMR_TTC_192B	0x00008000	/* TX after 192byte written in FIFO */
#define OMR_TTC_256B	0x0000C000	/* TX after 256byte written in FIFO */
#define OMR_TTC_40B	0x00010000	/* TX after 40byte written in FIFO  */
#define OMR_TTC_32B	0x00014000	/* TX after 32byte written in FIFO  */
#define OMR_TTC_24B	0x00018000	/* TX after 24byte written in FIFO  */
#define OMR_TTC_18B	0x0001C000	/* TX after 18byte written in FIFO  */

/* IER:MDC Interrupt Enable Register */
#define IRQ_NORMAL	0x00010000	/* Normal Interrupt Summary     */
#define IRQ_ABNORMAL	0x00008000	/* Abnormal Interrupt Summary   */
#define IRQ_EARY_RX	0x00004000	/* Eary Receive Int             */
#define IRQ_BUS_ERR	0x00002000	/* Fatal Bus Error Int          */
#define IRQ_EARY_TX	0x00000400	/* Eary Transmit Int            */
#define IRQ_RX_WT	0x00000200	/* Receive Watchdog Timeout Int */
#define IRQ_RX_STOP	0x00000100	/* Receive Process Stop Int     */
#define IRQ_RXB_UNAV	0x00000080	/* RX Buffer Unaballable Int    */
#define IRQ_RX_IRQ	0x00000040	/* Receive Int                  */
#define IRQ_TX_UFLOW	0x00000020	/* Transmit Underflow Int       */
#define IRQ_RX_OVERF	0x00000010	/* Receive Overlow Int          */
#define IRQ_TX_JT	0x00000008	/* TX Jabber Timeout Int        */
#define IRQ_TXB_UNAV	0x00000004	/* TX Buffer Unaballable Int    */
#define IRQ_TX_STOP	0x00000002	/* Transmit Process Stop Int    */
#define IRQ_TX_IRQ	0x00000001	/* Transmit Int                 */
#define CHECK_IRQ	0x000067FF	/* All interrupts               */

/* PMTR:PMT Register */
#define PMTR_WE		0x00000004	/* Wake Up Frame Enable         */
#define PMTR_ME		0x00000002	/* Magic Packet Enable          */

#define FMAC3H_TDESC_NUM	10
#define FMAC3H_RDESC_NUM	10

/* Descriptor Status */
#define OWN_BIT		0x80000000
#define IRQ_COMPLET	0x80000000
#define DIS_IRQ		0x80000000
#define LAST_SEG	0x40000000
#define FIRST_SEG	0x20000000
#define END_RING		0x02000000
#define SEC_ADD_CHAINED		0x01000000
#define DESC_TX_DP		0x00800000
/* RX descriptor error status
 *   ES[bit15]:Error Summary
 *   DE[bit14]:Not receive the whole frame to buffer
 *   LE[bit12]:Length Error
 *   OE[bit11]:Overflow Error
 *   RWT[bit4]:Receive watchdog timeout
 *    RE[bit3]:Receive Error
 *    DE[bit2]:DribleBit Error
 *    CE[bit1]:CRC Error */
#define RX_DESC_ERR		0x0000D81E
#define RX_DESC_DE_ERR		0x00004000
#define RX_DESC_LE_ERR		0x00001000
#define RX_DESC_GF_ERR		0x00000080
#define RX_DESC_CE_ERR		0x00000020
#define RX_DESC_OE_ERR		0x00000800
#define RX_DESC_FS		0x00000200
#define RX_DESC_LS		0x00000100
/* VLAN[bit10]:VLAN Frame. This driver does not support VLAN. */
#define RX_DESC_VLAN		0x00000400

/* TX descriptor error status
 * ES[bit15]:Error Summary
 * JT[bit14]:Jabber timeout
 * LC[bit11]:Loss of carrier
 * NC[bit10]:No carrier
 * LCO[bit9]:Late collision
 * EC[bit8]:Excessive collision
 * ED[bit2]:Excessive deferral
 * UF[bit1]:Undeflow error */
#define TX_DESC_ERR		0x0000CF86
#define TX_DESC_LC_ERR		0x00000800
#define TX_DESC_NC_ERR		0x00000400
#define TX_DESC_LCO_ERR		0x00000200
#define TX_DESC_UF_ERR		0x00000002
#define TX_DESC_EC_ERR		0x00000100
/* VF[bit7]:VLAN frame. This driver does not support VLAN. */
#define TX_DESC_VLAN		0x00000080

/* RS */
#define RS_GLPII		0x40000000
#define RS_TTI			0x20000000
#define RS_GPI			0x10000000
#define RS_GMI			0x08000000
#define RS_GLI			0x04000000
#define RS_TS_STOP		0x00000000
#define RS_RS_STOP		0x00000000

/*
 * struct definition
 */
struct fmac3h_desc {
	u32 opts1;
	u32 opts2;
	u32 addr1;
	u32 addr2;
};

/* Structure/enum declaration ------------------------------- */
typedef struct eth_info {
	u32 phy_map;		/* install PHY's information      */
	u32 phy_id;		/* PHY's ID                       */
	int mdc_clk;		/* MDC clock                      */

	dma_addr_t ring_dma;	/* base address of descriptor memory */
	struct fmac3h_desc *rx_ring;	/* RX Desc ring's pointer    */
	struct fmac3h_desc *tx_ring;	/* TX Desc ring's pointer    */
	u32 rx_ring_num;		/* Current RX desc number    */
	u32 tx_ring_num;		/* Current TX desc number    */
	u32 rx_buf_sz;			/* MAX size of socket buffer */
/*
	void (*outblk)(volatile void *data_ptr, int count);
	void (*inblk)(void *data_ptr, int count);
	void (*rx_status)(u16 *RxStatus, u16 *RxLen);
*/
	struct eth_device netdev;
} eth_info_t;

/* Generic MII registers. */

#define MII_BMCR            0x00        /* Basic mode control register */
#define MII_BMSR            0x01        /* Basic mode status register  */
#define MII_PHYSID1         0x02        /* PHYS ID 1                   */
#define MII_PHYSID2         0x03        /* PHYS ID 2                   */
#define MII_ADVERTISE       0x04        /* Auto-Neg Advertisement register */

/*
 * PHY Register Map
 */
/* Register0-Register6 is Generic MII registers. Reger to mii.h */
/* PHY(BCM5241) peculiar register map */
#define PHY_ANEG_NPR		0x07 /* ANEG Next Page Register               */
#define PHY_ANEG_LP_NPTS	0x08 /* ANEG LP Next Page Transmit Register   */
#define PHY_100X_ACR		0x10 /* 100BASE-X Auxiliary Control Register  */
#define PHY_100X_ASR		0x11 /* 100BASE-X Auxiliary Status Register   */
#define PHY_100X_REC		0x12 /* 100BASE-X Receive Error Counter       */
#define PHY_100X_FCSC		0x13 /* 100BASE-X False Carrier Sense Counter */
#define PHY_ACSR		0x18 /* Auxiliary Control Status Register     */
#define PHY_AS_SR		0x19 /* Auxiliary Status Summary Register     */
#define PHY_IR			0x1A /* Interrupt Register                    */
#define PHY_AM2_REG		0x1B /* Auxiliary Mode 2 Register             */
#define PHY_100T_AE_GSR		0x1C /* 100BASE-T Error & Gen Status Register */
#define PHY_AMR			0x1D /* Auxiliary Mode Register               */
#define PHY_AMPHY_REG		0x1E /* Auxiliary Multiple PHY Register       */
#define PHY_BTR			0x1F /* Broadcom Test Register                */

/* PHY(BCM5241) Shadow Register Map */
#define PHY_SHA_MCR		0x10	/* Miscellaneous Control Register   */
#define PHY_SHA_CDR		0x13	/* Cable Diagnostic Register        */
#define PHY_SHA_CDIR		0x14	/* Cable Diagnostic Index Register  */
#define PHY_SHA_MC2R		0x19	/* Miscellaneous Control 2 Register */
#define PHY_SHA_AM4R		0x1A	/* Auxiliary Mode 4 Register        */
#define PHY_SHA_AS2R		0x1B	/* Auxiliary Status 2 Register      */
#define PHY_SHA_AS3R		0x1C	/* Auxiliary Status 3 Register      */
#define PHY_SHA_AS4R		0x1E	/* Auxiliary Status 4 Register      */

/* PHY(KSZ8041TL) register map */
#define PHY8041_ANEG_NEXT	0x07	/* Auto-Negotiation Next Page */
#define PHY8041_LP_NPA		0x08	/* Link Partner Next Page Ability */
#define PHY8041_RXER		0x15	/* RXER Counter */
#define PHY8041_INTR_CS		0x1b	/* Interrupt Control/Status */
#define PHY8041_LINKMD		0x1d	/* LinkMD Control/Status */
#define PHY8041_PHY1_CTRL	0x1e	/* PHY Control 1 */
#define PHY8041_PHY2_CTRL	0x1f	/* PHY Control 2 */

/* PHY(88E1111) register map */
#define PHY88E1111_ANEG_NEXT	0x07	/* Auto-Negotiation Next Page */
#define PHY88E1111_PHY_SPEC_CTL	0x10	/* PHY specific control register */
#define PHY88E1111_PHY_SPEC_STA	0x11	/* PHY specific status register */


#endif	/* _FMAC3H_H */
