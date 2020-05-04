/*
 * Driver for the FMAC3H
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

#include <common.h>
#include <command.h>
#include <net.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <asm/system.h>
#include <malloc.h>
#include "fmac3h.h"
#include <asm/arch/hardware.h>
#include <i2c.h>
#include <linux/mii.h>

#define FORCE_ANEG 1
#define FMAC3H_BASE_ADD   0xE0000000
#define GPIO_OUT_BASE_ADD 0xC6000000
#define REG_ETH_SPEEDCS   0xD7000124

#define PHY_HW_RS         20 //GPIO 16 connect to PHY hardware reset ping

#define READ_REG(r)  readl((volatile u32 *)(FMAC3H_BASE_ADD + r))
#define WRITE_REG(val,r) writel(val, (volatile u32 *)(FMAC3H_BASE_ADD + r))

/* the size of descriptor spaces */
#define FMAC3H_DESC_BYTES  ((sizeof(struct fmac3h_desc) * FMAC3H_TDESC_NUM)) + \
			   ((sizeof(struct fmac3h_desc) * FMAC3H_RDESC_NUM))

#define FMAC3H_CLK GK6202_FMAC3H_CLK/1000000 /* AHB1 100MHz */

/* After reset device, have to wait 2000ns before access the register */
#define DELAY_TIME 2		/* 2us = 2000ns */

/* hope the option will end within this time */
#define WAIT_TIME 1000
#define ANEG_WAIT_TIME (500*1000)

/* MAX size of TX&RX size */
/* frame(1500)+EthernetHeader(14)+FCS(4)+NET_IP_ALIGN(2) */
#define BUFFER_SIZE      1520

/* MAX address of 32 PHYs */
#define MAX_PHY_ADR  31

/*Ring Descriptor Buffer*/
#ifdef CONFIG_ENABLE_MMU
/*ring_des can't put in the memory area that be cached*/
char ring_des[FMAC3H_DESC_BYTES] __attribute__ ((__section__(".uncachedata")));
#endif

/* recive data buffer */
#ifdef CONFIG_ENABLE_MMU
/*rx_buf can't put in the memory area that be cached*/
u32 rx_buf[FMAC3H_RDESC_NUM][BUFFER_SIZE / 4] __attribute__ ((__section__(".uncachedata")));
#else if
u32 rx_buf[FMAC3H_RDESC_NUM][BUFFER_SIZE / 4];
#endif
/*
 * if you have tested this driver on a new type PHY and make sure the driver
 * supports the new type PHY, you should add the ID(get from register ID1&ID2)
 * to this array.
 */

/* suggested PHY type's ID */
#define BCM5241_ID    0x0143BC31
#define LAN8700_ID    0x0007C0C4
#define LAN8710_ID    0x0007c0f1
#define KSZ8041_ID	0x00221513
/*
 * if you have tested this driver on a new type PHY and make sure the driver
 * supports the new type PHY, you should add the ID(get from register ID1&ID2)
 * to this array.
 */
static u32 known_phy_id[] = {
	BCM5241_ID,
	LAN8700_ID,
	LAN8710_ID,
	KSZ8041_ID,
	/* Add the ID above here
	  * 0 should always be the last one of array */
	0
};


static eth_info_t fmac3h_info;

static int fmac3h_write_enetaddr(struct eth_device *dev)
{
	/* Mac Add = UU:VV:WW:XX:YY:ZZ
	 * MAR0H   = 32'h0000ZZYY
	 * MAR0L   = 32'hXXWWVVUU
	 */
	u32 reg_data;
	u8  mac_addr[6];
	int ret;

	ret = eth_getenv_enetaddr_by_index("eth",0,mac_addr);
	if(ret < 0) {
		printf("MAC addr is not setted\n");
		return ret;
	}
	debug("MAC=%x:%x:%x:%x:%x:%x ",mac_addr[0], mac_addr[1],
		mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
	reg_data = (mac_addr[3] << 24)|(mac_addr[2] << 16)
		  |(mac_addr[1] << 8)|mac_addr[0];
	WRITE_REG(reg_data,FMAC3H_MAR0L);
	reg_data = (mac_addr[5] << 8)|mac_addr[4];
	WRITE_REG(reg_data,FMAC3H_MAR0H);

	reg_data = READ_REG(FMAC3H_MAR0L);
	dev->enetaddr[0] = (u8)(reg_data & 0x000000FF);
	dev->enetaddr[1] = (u8)((reg_data & 0x0000FF00) >> 8);
	dev->enetaddr[2] = (u8)((reg_data & 0x00FF0000) >> 16);
	dev->enetaddr[3] = (u8)((reg_data & 0xFF000000) >> 24);

	reg_data = READ_REG(FMAC3H_MAR0H);
	dev->enetaddr[4] = (u8)(reg_data & 0x000000FF);
	dev->enetaddr[5] = (u8)((reg_data & 0x0000FF00) >> 8);

	return ret;
}

/*
 * fmac3h_phy_wait -- confirm that PHY is not busy
 * Description: In this function, the driver will confirm whether PHY is
 *  not busy.  If PHY does not become free in time, the driver will send
 *  warning message to user and continue.
 */
static int fmac3h_phy_wait(void)
{
	u32 wtime;		/* waiting time */
	u32 val;

	/* confirm that PHY is not busy befor write/read GAR and GDR.
	 * We set a waitingtime, if PHY does not become free in time,
	 * we will send warning message to user and continue. */
	wtime = WAIT_TIME;
	while (wtime--) {
		val = READ_REG(FMAC3H_GAR);
		if (!(val & GAR_GB))
			return 0;
		udelay(DELAY_TIME);
	}

	printf("PHY is busy!\n");
	return 1;
}


/*
 * fmac3h_phy_read -- read PHY's register
 * @phy_id: the id of phy. range:0-31
 * @reg: phy register address
 * @read_val: the readen PHY register's value
 *
 * Description: read PHY's register by setting FMAC3H's GAR register and
 *  GDR register.
 */

static int fmac3h_phy_read(int phy_id, int reg, u32 *read_val)
{

	int wval, ret;

	/* Set the GAR register */
	wval = (phy_id << 11) | ((reg & 0x1f) << 6) | GAR_GW_R
	     | ((fmac3h_info.mdc_clk & 0x07) << 2) | GAR_GB;

	/* Wait until GMII/MII is not busy */
	ret = fmac3h_phy_wait();
	if (ret) {
		printf("Read PHY Error!\n");
		return ret;
	}

	WRITE_REG(wval, FMAC3H_GAR);

	/* Wait until GMII/MII is not busy */
	ret = fmac3h_phy_wait();
	if (ret) {
		printf("Read PHY Error!\n");
		return ret;
	}

	*read_val = READ_REG(FMAC3H_GDR);
	return 0;
}

/*
 * fmac3h_phy_write -- write PHY's register
 * @phy_id: the id of phy. range:0-31
 * @reg: phy register address
 * @write_val: the written PHY register's value
 *
 * Description: read PHY's register by setting FMAC3H's GAR register and
 *  GDR register.
 */

static int fmac3h_phy_write(int phy_id, int reg, int write_val)
{

	int wval, ret;

	/* Set the GAR register */
	wval = (phy_id << 11) | ((reg & 0x1f) << 6) | GAR_GW_W
	     | ((fmac3h_info.mdc_clk & 0x03) << 2) | GAR_GB;

	/* Wait until GMII/MII is not busy */
	ret = fmac3h_phy_wait();
	if (ret) {
		printf("Read PHY Error!\n");
		return ret;
	}

	/* Set the value that is want to be written in PHY register */
	WRITE_REG(write_val, FMAC3H_GDR);
	/* Set PHY Register access information */
	WRITE_REG(wval, FMAC3H_GAR);

	/* Wait until GMII/MII is not busy */
	ret = fmac3h_phy_wait();
	if (ret) {
		printf("Read PHY Error!\n");
		return ret;
	}

	return 0;
}


/*
 * fmac3h_get_phyid -- find out PHYs on the device
 * Description: Reads the ID registers of the every PHY addr(0-31) on the
 *   device. If the ID<>0xFFFFFFFF then set the bit of phy_id.
 */

static int fmac3h_get_phyid(void)
{
	u32 phy_reg;
	int i, ret;

	/* initializate PHY installation information */
	fmac3h_info.phy_id = 0;

	for (i = 0; i <= MAX_PHY_ADR; i++) {
		u32 phy_id, temp_id;
		int j;

		/* Read phy ID from PHY's register2&register3 */
		ret = fmac3h_phy_read(i, MII_PHYSID1, &phy_reg);
		if (ret) {
			printf("Failed to read PHY register!!!\n");
			return -EACCES;
		}

		if (phy_reg <= 0) {
			printf("id1 There is no PHY in slot(%d).\n", i);
			continue;
		}

		phy_id = (phy_reg & 0xFFFF) << 16;	/* get PHYID high */

		ret = fmac3h_phy_read(i, MII_PHYSID2, &phy_reg);
		if (ret) {
			printf("Failed to read PHY register!!!\n");
			return -EACCES;
		}

		if (phy_reg <= 0) {
			printf("id2 There is no PHY in slot(%d).\n", i);
			continue;
		}

		phy_id |= (phy_reg & 0xFFFF);		/* get PHYID low */

		debug("PHY%d: ID:0x%08x\n", i, phy_id);

		if (phy_id == 0xFFFFFFFF) {
			debug("There is no PHY in slot(%d).\n", i);
			continue;
		}

		/* determine whether this phy type is known before */
		for (j = 0; (temp_id = known_phy_id[j]) != 0; j++) {
			if (phy_id == temp_id) {
				break;
			}
		}

		if (!temp_id) {
			printf("PHY(TYPE:0x%08x ADDRESS:%d,temp_id = 0x%x) is not known before!!!\n", phy_id, i, temp_id);
		}

		/* set the bit of installed PHY */
		fmac3h_info.phy_id |= (1 << i);
	}
	printf("phy_id : 0x%08x\n", fmac3h_info.phy_id);
	return 0;
}


static int fmac3h_probe(void)
{
	int i,err;

	printf("fmac3h_probe\n");
	/* get MDC clock from SYS_CLOCK */
	if (FMAC3H_CLK < 20) {
		printf("Unavailable FMAC3H_CLK(%d), aborting!!!\n", FMAC3H_CLK);
		return -EINVAL;

	} else if (FMAC3H_CLK < 35) {
		fmac3h_info.mdc_clk = 2;
	} else if (FMAC3H_CLK < 60) {
		fmac3h_info.mdc_clk = 3;
	} else if (FMAC3H_CLK < 100) {
		fmac3h_info.mdc_clk = 0;
	} else if (FMAC3H_CLK < 150) {
		fmac3h_info.mdc_clk = 1;
	} else if (FMAC3H_CLK < 250) {
		fmac3h_info.mdc_clk = 4;
	} else if (FMAC3H_CLK < 300) {
		fmac3h_info.mdc_clk = 5;
	} else {
		printf("Unavailable FMAC3H_CLK(%d), aborting!!!\n", FMAC3H_CLK);
		return -EINVAL;
	}

	err = fmac3h_get_phyid();	/* get phy install information */
	if (err) {
		printf("Failed to find PHY, aborting!!!\n");
		return -EINVAL;
	}

	/* Descriptor and Buffer initializate */
#ifdef CONFIG_ENABLE_MMU
         fmac3h_info.ring_dma = (u32)&ring_des[0];
#else
	fmac3h_info.ring_dma = (u32)malloc(FMAC3H_DESC_BYTES);
#endif
	fmac3h_info.rx_ring = (struct fmac3h_desc *)fmac3h_info.ring_dma;

	if (fmac3h_info.rx_ring == NULL) {
		printf("Failed to alloc DMA descriptor memory!!!\n");
		return -ENOMEM;
	}

	fmac3h_info.tx_ring = &fmac3h_info.rx_ring[FMAC3H_RDESC_NUM];

	memset(fmac3h_info.rx_ring, 0, sizeof(struct fmac3h_desc) * FMAC3H_RDESC_NUM);
	memset(fmac3h_info.tx_ring, 0, sizeof(struct fmac3h_desc) * FMAC3H_TDESC_NUM);

	fmac3h_info.rx_ring[FMAC3H_RDESC_NUM - 1].opts2 = END_RING;
	fmac3h_info.tx_ring[FMAC3H_TDESC_NUM - 1].opts2 = END_RING;
	fmac3h_info.tx_ring[FMAC3H_TDESC_NUM - 1].addr2 = (u32)fmac3h_info.tx_ring;
	fmac3h_info.rx_buf_sz = BUFFER_SIZE;	/* 1520 bytes */

	fmac3h_info.rx_ring_num = 0;
	fmac3h_info.tx_ring_num = 0;

	/* init receive ring */

	for(i = 0; i < FMAC3H_RDESC_NUM; i++) {
		struct fmac3h_desc *rx_ring;
		rx_ring = &fmac3h_info.rx_ring[i];
		rx_ring->opts2 |= DIS_IRQ | BUFFER_SIZE;
		rx_ring->addr1 = (u32)(&rx_buf[i][0]);
		rx_ring->addr2 = 0;
		rx_ring->opts1 = OWN_BIT;
	}
	return 0;
}

#ifdef FORCE_ANEG

/*
 * fmac3h_setup_aneg -- setup autonegotiation
 */

static int fmac3h_setup_aneg(void)
{
	u32 ctl,adv;
	u32 wtime;
	int ret;

	printf("fmac3h_setup_aneg\n");
	/* software reset */
	ret = fmac3h_phy_read(fmac3h_info.phy_id, MII_BMCR, &ctl);
	if (ret) {
		printf("Failed to read PHY register!!!\n");
		return -EACCES;
	}
	ctl |= BMCR_RESET;
	ret = fmac3h_phy_write(fmac3h_info.phy_id, MII_BMCR, ctl);
	if (ret) {
		printf("Failed to write PHY register!!!\n");
		return -EACCES;
	}

	wtime = WAIT_TIME;
	while (wtime--) {
		ret = fmac3h_phy_read(fmac3h_info.phy_id, MII_BMCR, &ctl);
		if (ret) {
			printf("Failed to read PHY register!!!\n");
			return -EACCES;
		}
		if (!(ctl & BMCR_RESET )) { /* BMCR_RESET */
			wtime = 0;
			break;
		}
		udelay(DELAY_TIME);
	}

	/* setup standard advertise */
	ret = fmac3h_phy_read(fmac3h_info.phy_id, MII_ADVERTISE, &adv);
	if (ret) {
		printf("Failed to read PHY register!!!\n");
		return -EACCES;
	}

	adv &= (~(ADVERTISE_ALL | ADVERTISE_100BASE4
		| ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM));
	adv |= ADVERTISE_10HALF | ADVERTISE_10FULL
		| ADVERTISE_100HALF | ADVERTISE_100FULL;

	ret = fmac3h_phy_write(fmac3h_info.phy_id, MII_ADVERTISE, adv);
	if (ret) {
		printf("Failed to write PHY register!!!\n");
		return -EACCES;
	}

	/* start auto negotiation */
	printf("Start autonegotiation\n");
	ret = fmac3h_phy_read(fmac3h_info.phy_id, MII_BMCR, &ctl);
	if (ret) {
		printf("Failed to read PHY register!!!\n");
		return -EACCES;
	}

	ctl |= BMCR_ANENABLE | BMCR_ANRESTART;
	ret = fmac3h_phy_write(fmac3h_info.phy_id, MII_BMCR, ctl);
	if (ret) {
		printf("Failed to write PHY register!!!\n");
		return -EACCES;
	}

	/* sure autonegotiation success */
	wtime = ANEG_WAIT_TIME;
	while (wtime--) {
		ret = fmac3h_phy_read(fmac3h_info.phy_id, MII_BMSR, &ctl);
		if (ret) {
			printf("Failed to read PHY register!!!\n");
			return -EACCES;
		}
		if((ctl & BMSR_LSTATUS) && (ctl & BMSR_ANEGCOMPLETE)) {
			wtime = 0;
			return 0;
		}
		udelay(DELAY_TIME);
	}
	if(!(ctl & BMSR_LSTATUS) && (ctl & BMSR_ANEGCOMPLETE)) {
		printf("Setup Autonegotiation is failed!!!\n");
		return -EBUSY;
	}
	return 0;
}
#endif

/* Initialize fmac3h */

int fmac3h_init(bd_t *bd)
{
	u32 val, phyctrl2;
	int err;
	u32 rx_adr, tx_adr;
	struct eth_device *dev = &(fmac3h_info.netdev);

	printf("eth_init\n");

    /*hardware reset the phy */
    #if 1
    writel(2, (volatile u32 *)(GPIO_OUT_BASE_ADD + PHY_HW_RS*4));
    writel(1, (volatile u32 *)(GPIO_OUT_BASE_ADD + PHY_HW_RS*4));
    udelay(50000);//50ms
    writel(0, (volatile u32 *)(GPIO_OUT_BASE_ADD + PHY_HW_RS*4));
    udelay(50000);//50ms
    writel(1, (volatile u32 *)(GPIO_OUT_BASE_ADD + PHY_HW_RS*4));
    #endif
	/* Load MAC address from CONFIG and write it to register */
	err = fmac3h_write_enetaddr(dev);
	if(err < 0){
		return err;
	}
	err = fmac3h_probe();
	if(err)
		return err;

	/* DMA Initialization */

	/* 1.Set BMR(MDC Bus Mode Register) DMA reg 0 */
	val = (BMR_8XPBL & SET_1)
	    | (BMR_USP & SET_1)
	    | (BMR_FB & SET_1)
	    | (BMR_DA & SET_1)	/* DMA Arbitration Scheme:RX First */
	    | BMR_RPBL_16
	    | BMR_PBL_16	/* When 8xPBL is set max value of PBL is 16 */
	    | BMR_DSL;		/* Descripter Skip Length is 0 */

	WRITE_REG(val, FMAC3H_BMR);

	/* 2.Set IER(MDC Interrupt Enable Register) DMA reg 7 */
#if 0
	val = (IRQ_EARY_RX & SET_0)	/* Early Receive Irq Disable        */
	    | (IRQ_BUS_ERR & SET_0)	/* Fatal BUS Error Irq Disable      */
	    | (IRQ_EARY_TX & SET_0)	/* Early Transmit Irq Disable       */
	    | (IRQ_RX_WT   & SET_0)	/* RX Watchdog Timeout Irq Disable  */
	    | (IRQ_RX_STOP & SET_1)	/* Receive Process Stop Int Enable  */
	    | (IRQ_RXB_UNAV & SET_1)	/* RX Buffer Unaballable Int Enable */
	    | (IRQ_RX_IRQ & SET_1)	/* Receive Int Enable               */
	    | (IRQ_TX_UFLOW & SET_1)	/* Transmit Underflow Int Enable    */
	    | (IRQ_RX_OVERF & SET_1)	/* Receive Overlow Int Enable       */
	    | (IRQ_TX_JT & SET_0)	/* TX Jabber Timeout Int Disable    */
	    | (IRQ_TXB_UNAV & SET_1)	/* TX Buffer Unaballable Int Enable */
	    | (IRQ_TX_STOP & SET_1)	/* Transmit Process Stop Int Enable */
	    | (IRQ_TX_IRQ & SET_1)	/* Transmit Int Enable              */
	    | (IRQ_NORMAL & SET_1)	/* Normal Interrupt Summary Enable */
	    | (IRQ_NORMAL & SET_0)	/* Normal Interrupt Summary Disable */
	    | (IRQ_ABNORMAL & SET_0);	/* Abnormal Interrupt Summary Disable */
#else
	val = 0;
#endif
	WRITE_REG(val, FMAC3H_IER);

	/* Set PMTR GMAC reg 11 */
	/* Disable Wake Up Frame | Disable Magic Packet */
	val = (PMTR_WE & SET_0)		/* Wake Up Frame Disable */
	    | (PMTR_ME & SET_0);	/* Magic Packet Disable  */

	WRITE_REG(val, FMAC3H_PMTR);

	/* Mask MMC interrupt */
#ifdef CONFIG_FMAC3H_HAVE_MMC
	WRITE_REG(MMC_INTR_MASK, FMAC3H_MMC_INTR_MASK_RX);
	WRITE_REG(MMC_INTR_MASK, FMAC3H_MMC_INTR_MASK_TX);
#endif
	/* 3.Set MFFR(MAC Frame Filter Register) GMAC reg 1
	 *   With this set the LAN can do:
	 *   (1).Receive broadcast frames
	 *   (2).Receive packets that has the same multicast address as MARn
	 *   (3).Receive packets that has the same unicast address as MARn   */
#if 1
	val = 0;
#else
	val = PASS_ALL_MUL_ON|REC_ALL_ON|PROMIS_MODE;
#endif
	WRITE_REG(val, FMAC3H_MFFR);

	/* 4.Set MHTRH(MAC Hash Table Register High) GMAC reg 2
	 *       MHTRL(MAC Hash Table Register Low)  GMAC reg 3 */
	WRITE_REG(0, FMAC3H_MHTRH);
	WRITE_REG(0, FMAC3H_MHTRL);

#ifdef CONFIG_FMAC3H_HAVE_MMC
	/* 5.Set MMC Register */
	WRITE_REG(CLEAR_ALL, FMAC3H_MMC_CNTL);
	val = RESET_ON_READ		/* Auto clear after is readed */
	    | STOP_ROLL_OVER;		/* Stop count when arrive MAX */

	WRITE_REG(val, FMAC3H_MMC_CNTL);

	/* Mask all interrupt of MMC */
	WRITE_REG(0x00FFFFFF, FMAC3H_MMC_INTR_MASK_RX);
	WRITE_REG(0x01FFFFFF, FMAC3H_MMC_INTR_MASK_TX);
#endif

#ifdef FORCE_ANEG
	/* 6.Setup PHY Autonegotiation */
	err = fmac3h_setup_aneg();
	if (err) {
		printf("Failed to setup AutoNegotiation!!!\n");
		return err;
	}
#endif

	/* 7.Set MCR(MAC Configuration Register) GMAC reg 0 */
	val = (MCR_WD & SET_1)		/* Disable RX Watchdog timeout     */
	    | (MCR_JD & SET_1)		/* Disable TX Jabber timer         */
	    | (MCR_BE & SET_1)		/* Frame Burst Enable              */
	    | (MCR_JE & SET_0)		/* Jumbo Frame Disable             */
	    | (MCR_DCRS & SET_0)	/* Enable Carrier During Trans     */
	    | (MCR_DO & SET_0)		/* Enable Receive Own              */
/* DEBUG Loop back FIXME */
	    | (MCR_LM & SET_0)		/* Not Loop-back Mode              */
/* DEBUG Loop back FIXME */
	    | (MCR_DR & SET_0)		/* Enable Retry                    */
	    | (MCR_ACS & SET_0)		/* Not Automatic Pad/CRC Stripping */
	    | (MCR_DC & SET_0)		/* Deferral Check Disable          */
	    | (MCR_TX_ENABLE & SET_1)	/* Enable Transmitter              */
	    | (MCR_RX_ENABLE & SET_1)	/* Enable Receiver                 */
	    | MCR_BL_00;		/* Back-off Limit is 0             */

	val |= MII_PORT;

	/* Or read Link Partner ability register */
	err = fmac3h_phy_read(fmac3h_info.phy_id, PHY88E1111_PHY_SPEC_STA, &phyctrl2);
	if (err) {
		printf("Failed to read PHY register!!!\n");
		return err;
	}
	if (phyctrl2 & 0x2000) {
		val |= FULL_DUPLEX;
	}

	WRITE_REG(val, FMAC3H_MCR);

	/* add wait time after setting MCR over 1.6us */
	udelay(10);		/* wait 10us */


	/* 8.Set RDLAR(MDC Receive Descriptor List Address Register)
	 *       TDLAR(MDC Transmit Descriptor List Address Register) */
	rx_adr = fmac3h_info.ring_dma;
	tx_adr = fmac3h_info.ring_dma + (sizeof(struct fmac3h_desc) * FMAC3H_RDESC_NUM);
	WRITE_REG(rx_adr, FMAC3H_RDLAR);
	WRITE_REG(tx_adr, FMAC3H_TDLAR);

	/* 9.Set OMR to start RX and TX */
	val =			/* OMR_SF */
	    OMR_TTC_64B		/* TX after 64byte written in FIFO */
	    /* | START_TX */	/* Start Transmissin */
	    | START_RX;		/* Start Receive     */

	WRITE_REG(val, FMAC3H_OMR);

    #if 0
    
	//100MHz
    writel(2, (volatile u32 *)(REG_ETH_SPEEDCS));
	//10MHz
    //writel(0, (volatile u32 *)(REG_ETH_SPEEDCS));

    #endif

	return 0;

}

/*
 * fmac3h_halt -- stop hardware
 * Description: In this function, the driver will stop the TX/RX engine and
 *  clear the status of hardware.
 */
 void fmac3h_halt()
{
	u32 val;

	printf("fmac3h_halt\n");

	/* stop TX and RX process */
	val = 0;
	WRITE_REG(val, FMAC3H_OMR);

	/* clear desc */
#ifdef CONFIG_ENABLE_MMU
         memset(ring_des,0,sizeof(ring_des));
#else
	free((u32 *)fmac3h_info.ring_dma);
#endif
	fmac3h_info.ring_dma = 0;
	fmac3h_info.rx_ring = 0;
	fmac3h_info.tx_ring = 0;

	/* disable all interrupt */
	/* WRITE_REG(0, FMAC3H_IER);*/

	/* clear status register */
	val = READ_REG(FMAC3H_SR);
	WRITE_REG(val, FMAC3H_SR);

	return;
}

/*
  Hardware start transmission.
  Send a packet to media from the upper layer.
*/
/*

The send function does what you think -- transmit the specified packet whose
size is specified by length (in bytes).  You should not return until the
transmission is complete, and you should leave the state such that the send
function can be called multiple times in a row.

*/

int fmac3h_send(void *packet, int length)
{
	u32 val;
	int tmo;

	struct fmac3h_desc *tx_ring;

	tx_ring = &fmac3h_info.tx_ring[fmac3h_info.tx_ring_num];
	fmac3h_info.tx_ring_num++;
	if(fmac3h_info.tx_ring_num == FMAC3H_TDESC_NUM) {
		fmac3h_info.tx_ring_num = 0;
	}
	/* set up transmit desc (TDES0-TDES3) ande set TDES0[31]*/
	tx_ring->opts2 |= FIRST_SEG | LAST_SEG | length;
	tx_ring->addr1  = (u32)packet;
	tx_ring->addr2  = 0;
	isb();
	tx_ring->opts1  = OWN_BIT;

	/* set ST bit (DMA 6[13]) DMA enters the Runstate*/
	val = READ_REG(FMAC3H_OMR);
	val |= START_TX;
	WRITE_REG(val, FMAC3H_OMR);

	/* Transmit Poll Demand */
	val = 0xffffffff;
	WRITE_REG(val, FMAC3H_TPDR);

	/* wait transmission complete */
	tmo = get_timer(0) + 5 * CONFIG_SYS_HZ; /* timer clk */

	while ((tx_ring->opts1 & 0x80000000) == OWN_BIT) {
		if (get_timer(0) >= tmo) {
			printf("transmission timeout\n");
			break;
		}
	}
	/* set ST bit to stop DMA */
	val = READ_REG(FMAC3H_OMR);
	val &= ~START_TX;
	WRITE_REG(val, FMAC3H_OMR);

	/* clear tx desc */
	tx_ring->addr1  = 0;

	return 0;
}

/*
  Received a packet and pass to upper layer
*/

/*
The recv function should process packets as long as the hardware has them
readily available before returning.  i.e. you should drain the hardware fifo.
For each packet you receive, you should call the NetReceive() function on it
along with the packet length.  The common code sets up packet buffers for you
already in the .bss (NetRxPackets), so there should be no need to allocate your
own.  This doesn't mean you must use the NetRxPackets array however; you're
free to call the NetReceive() function with any buffer you wish.
int ape_recv(struct eth_device *dev)
{
	int length, i = 0;
	...
	while (packets_are_available()) {
		...
		length = ape_get_packet(&NetRxPackets[i]);
		...
		NetReceive(&NetRxPackets[i], length);
		...
		if (++i >= PKTBUFSRX)
			i = 0;
		...
	}
	...
	return 0;
*/

int fmac3h_rx()
{
	u32 RxLen;
	int i;

	struct fmac3h_desc *rx_ring;

	/* recevie packet */
	for(i = 0;i < FMAC3H_RDESC_NUM; i++) {
		rx_ring = &fmac3h_info.rx_ring[i];
		if ((rx_ring->opts1 & 0x80000000)!= OWN_BIT) {
			/* Read error state */
			if (rx_ring->opts1 & RX_DESC_ERR) {
				printf("RX Desc has error status(0x%08x:0x%08x).\n",
					rx_ring->opts1, READ_REG (FMAC3H_SR));
				rx_ring->opts1 = OWN_BIT;
				return 0;
			}
			/* Get data length */
			RxLen = (rx_ring->opts1 >> 16) & 0x3FFF;

			/* Read received packet from buf */
			NetReceive((uchar *)rx_ring->addr1, RxLen);
			rx_ring->opts1 = OWN_BIT;
			break;
		}
	}
	return 0;
}

int fmac3h_initialize(bd_t *bis)
{
	struct eth_device *dev = &(fmac3h_info.netdev);

	dev->init = fmac3h_init;
	dev->halt = fmac3h_halt;
	dev->send = fmac3h_send;
	dev->recv = fmac3h_rx;
	sprintf(dev->name, "fmac3h");

	eth_register(dev);

	return 0;
}



