/*
 * GK7101 ethernet driver at U-Boot
 *
 * Copyright (c) 2015 Gokemicro Semiconductor Corporation.
 *
 * Implementation:
 *  Emulate the pseudo BufferRAM
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <phy.h>
#include <net.h>
#include <errno.h>
#include <asm/types.h>
#include <asm/io.h>

#if defined(CONFIG_CPU_GK7101) || defined(CONFIG_CPU_GK7102)
#include <asm/arch-gk7101/io.h>
#include <asm/arch-gk7101/gpio.h>
#endif

#if defined(CONFIG_CPU_GK7101S) || defined(CONFIG_CPU_GK7102S)
#include <asm/arch-gk7101s/io.h>
#include <asm/arch-gk7101s/gpio.h>
#endif

#include "goke_eth.h"

/* ==========================================================================*/
#define GKETH_DESC_BYTES   (1536)
#define GKETH_RX_RNG    (8)
#define GKETH_TX_RNG    (4)

#define DEFAULT_DMA_MODE (ETH_DMA_BUS_MODE_FB | \
                ETH_DMA_BUS_MODE_PBL_32 | \
                ETH_DMA_BUS_MODE_DA_RX)

#define DEFAULT_DMA_OPMODE (ETH_DMA_OPMODE_TTC_256 | \
                ETH_DMA_OPMODE_RTC_64 | \
                ETH_DMA_OPMODE_FUF)
#define GKETH_RXDMA_STATUS  (ETH_DMA_STATUS_OVF | ETH_DMA_STATUS_RI | \
                ETH_DMA_STATUS_RU | ETH_DMA_STATUS_RPS | \
                ETH_DMA_STATUS_RWT)
#define GKETH_RXDMA_INTEN   (ETH_DMA_INTEN_OVE | ETH_DMA_INTEN_RIE | \
                ETH_DMA_INTEN_RUE | ETH_DMA_INTEN_RSE | \
                ETH_DMA_INTEN_RWE)
#define GKETH_TXDMA_STATUS  (ETH_DMA_STATUS_TI | ETH_DMA_STATUS_TPS | \
                ETH_DMA_STATUS_TU | ETH_DMA_STATUS_TJT | \
                ETH_DMA_STATUS_UNF)
#define GKETH_TXDMA_INTEN   (ETH_DMA_INTEN_TIE | ETH_DMA_INTEN_TSE | \
                ETH_DMA_INTEN_TUE | ETH_DMA_INTEN_TJE | \
                ETH_DMA_INTEN_UNE)
#define GKETH_DMA_INTEN (ETH_DMA_INTEN_NIE | ETH_DMA_INTEN_AIE | \
                ETH_DMA_INTEN_FBE | GKETH_RXDMA_INTEN | \
                GKETH_TXDMA_INTEN)

/* ==========================================================================*/
struct GKETH_desc {
    u32                 status;
    u32                 length;
    u32                 buffer1;
    u32                 buffer2;
} __attribute((packed));

struct GKETH_tx_rngmng {
    unsigned int                cur_tx;
    struct GKETH_desc           *desc_tx;
};

struct GKETH_rx_rngmng {
    unsigned int                cur_rx;
    struct GKETH_desc           *desc_rx;
};

struct GKETH_info {
    unsigned int                rx_count;
    struct GKETH_rx_rngmng          rx;
    unsigned int                tx_count;
    struct GKETH_tx_rngmng          tx;
    dma_addr_t              rx_dma_desc;
    dma_addr_t              tx_dma_desc;
    int                 oldspeed;
    int                 oldduplex;
    int                 oldlink;

    struct eth_device           netdev;
    struct phy_device           phydev;

    unsigned char            *regbase;
};

static int phy_type = 0;
static int phy_try  = 3;
static struct GKETH_info gk7101_info;
static volatile struct GKETH_desc tx_ring_desbuffer[GKETH_TX_RNG+5] = {};
static volatile struct GKETH_desc rx_ring_des[GKETH_RX_RNG] = {};
static volatile struct GKETH_desc *tx_ring_des;
static volatile u32 rx_buf[GKETH_RX_RNG][GKETH_DESC_BYTES / 4] = { };


/* ==========================================================================*/
static  int gkhw_dma_reset(struct GKETH_info *lp)
{
    int                 errorCode = 0;
    u32                 counter = 0;

    gk_eth_setbitsl(lp->regbase + ETH_DMA_BUS_MODE_OFFSET,
        ETH_DMA_BUS_MODE_SWR);
    do {
        if (counter++ > 5000) {
            errorCode = -EIO;
            break;
        }
        mdelay(1);
    } while (gk_eth_tstbitsl(lp->regbase + ETH_DMA_BUS_MODE_OFFSET,
        ETH_DMA_BUS_MODE_SWR));

    if (errorCode)
        printf("%s: DMA Error: Check PHY.\n", __func__);

    return errorCode;
}

static  void gkhw_dma_rx_start(struct GKETH_info *lp)
{
    gk_eth_setbitsl(lp->regbase + ETH_DMA_OPMODE_OFFSET, ETH_DMA_OPMODE_SR);
}

static  void gkhw_dma_tx_stop(struct GKETH_info *lp)
{
    unsigned int                irq_status;
    int                 i = 1300;

    gk_eth_clrbitsl(lp->regbase + ETH_DMA_OPMODE_OFFSET, ETH_DMA_OPMODE_ST);
    do {
        udelay(1);
        irq_status = gk_eth_readl(lp->regbase + ETH_DMA_STATUS_OFFSET);
    } while ((irq_status & ETH_DMA_STATUS_TS_MASK) && --i);
    if (i <= 0) {
        printf("DMA Error: Stop TX status=0x%x, opmode=0x%x.\n",
            gk_eth_readl(lp->regbase + ETH_DMA_STATUS_OFFSET),
            gk_eth_readl(lp->regbase + ETH_DMA_OPMODE_OFFSET));
    }
    gk_eth_setbitsl(lp->regbase + ETH_DMA_OPMODE_OFFSET, ETH_DMA_OPMODE_FTF);
}

static  void gkhw_dma_tx_start(struct GKETH_info *lp)
{
    gk_eth_setbitsl(lp->regbase + ETH_DMA_OPMODE_OFFSET, ETH_DMA_OPMODE_ST);
}

static  void gkhw_stop_tx_rx(struct GKETH_info *lp)
{
    unsigned int                irq_status;
    int                 i = 1300;

    gk_eth_clrbitsl(lp->regbase + ETH_MAC_CFG_OFFSET, ETH_MAC_CFG_RE);
    gk_eth_clrbitsl(lp->regbase + ETH_DMA_OPMODE_OFFSET,
        (ETH_DMA_OPMODE_SR | ETH_DMA_OPMODE_ST));
    do {
        udelay(1);
        irq_status = gk_eth_readl(lp->regbase + ETH_DMA_STATUS_OFFSET);
    } while ((irq_status & (ETH_DMA_STATUS_TS_MASK |
        ETH_DMA_STATUS_RS_MASK)) && --i);
    if (i <= 0) {
        printf("%s: DMA Error: Stop TX/RX status=0x%x, opmode=0x%x.\n", __func__,
            gk_eth_readl(lp->regbase + ETH_DMA_STATUS_OFFSET),
            gk_eth_readl(lp->regbase + ETH_DMA_OPMODE_OFFSET));
    }
    gk_eth_clrbitsl(lp->regbase + ETH_MAC_CFG_OFFSET, ETH_MAC_CFG_TE);
}

static  void gkhw_set_dma_desc(struct GKETH_info *lp)
{
    gk_eth_writel(lp->regbase + ETH_DMA_RX_DESC_LIST_OFFSET,lp->rx_dma_desc);
    gk_eth_writel(lp->regbase + ETH_DMA_TX_DESC_LIST_OFFSET,lp->tx_dma_desc);
}

static  void gkhw_set_hwaddr(struct GKETH_info *lp, u8 *hwaddr)
{
    u32                 val;

    val = 0x80000000 | (hwaddr[5] << 8) | hwaddr[4];
    gk_eth_writel(lp->regbase + ETH_MAC_MAC0_HI_OFFSET, val);
    udelay(4);
    val = (hwaddr[3] << 24) | (hwaddr[2] << 16) |
        (hwaddr[1] << 8) | hwaddr[0];
    gk_eth_writel(lp->regbase + ETH_MAC_MAC0_LO_OFFSET, val);
}

static int gkhw_mac_enable(struct GKETH_info *lp)
{
    int                 errorCode = 0;

    errorCode = gkhw_dma_reset(lp);
    if (errorCode){
        printf("%s: DMA init fail.\n", __func__);
        goto gkhw_init_exit;
    }

    gkhw_set_hwaddr(lp, lp->netdev.enetaddr);
    gk_eth_writel(lp->regbase + ETH_DMA_BUS_MODE_OFFSET, DEFAULT_DMA_MODE);
    gk_eth_writel(lp->regbase + ETH_MAC_FRAME_FILTER_OFFSET, ETH_MAC_FRAME_FILTER_RA);
    gk_eth_writel(lp->regbase + ETH_DMA_OPMODE_OFFSET, DEFAULT_DMA_OPMODE);
    gk_eth_writel(lp->regbase + ETH_DMA_STATUS_OFFSET, \
        gk_eth_readl(lp->regbase + ETH_DMA_STATUS_OFFSET));
    gk_eth_writel(lp->regbase + ETH_MAC_CFG_OFFSET, \
        (ETH_MAC_CFG_TE | ETH_MAC_CFG_RE | ETH_MAC_CFG_DM));
    gk_eth_writel(lp->regbase + ETH_MAC_HASH_HI_OFFSET, 0xffffffff);
    gk_eth_writel(lp->regbase + ETH_MAC_HASH_LO_OFFSET, 0xffffffff);
    gk_eth_writel(lp->regbase + ETH_MAC_FLOW_CTR_OFFSET, ETH_MAC_FLOW_CTR_TFE | ETH_MAC_FLOW_CTR_RFE);

gkhw_init_exit:
    return errorCode;
}

static void gkhw_mac_disable(struct GKETH_info *lp)
{
    gkhw_stop_tx_rx(lp);
}

/* ==========================================================================*/
static int gkhw_mdio_read(struct GKETH_info *lp,
    int mii_id, int regnum)
{
    int                 val;
    int                 limit;

    for (limit = 200; limit > 0; limit--) {
        if (!gk_eth_tstbitsl(lp->regbase + ETH_MAC_GMII_ADDR_OFFSET,
            ETH_MAC_GMII_ADDR_GB))
            break;
        udelay(10);
    }
    if (limit <= 0) {
        printf("MII Error: Preread tmo!\n");
        val = 0xFFFFFFFF;
        goto gkhw_mdio_read_exit;
    }

    val = ETH_MAC_GMII_ADDR_PA(mii_id) | ETH_MAC_GMII_ADDR_GR(regnum);
    val |= ETH_MAC_GMII_ADDR_CR_100_150MHZ | ETH_MAC_GMII_ADDR_GB;
    gk_eth_writel(lp->regbase + ETH_MAC_GMII_ADDR_OFFSET, val);

    for (limit = 200; limit > 0; limit--) {
        if (!gk_eth_tstbitsl(lp->regbase + ETH_MAC_GMII_ADDR_OFFSET,
            ETH_MAC_GMII_ADDR_GB))
            break;
        udelay(10);
    }
    if (limit <= 0) {
        printf("%s: MII Error: Postread tmo!\n", __func__);
        val = 0xFFFFFFFF;
        goto gkhw_mdio_read_exit;
    }

    val = gk_eth_readl(lp->regbase + ETH_MAC_GMII_DATA_OFFSET);

gkhw_mdio_read_exit:
    return val;
}

static int gkhw_mdio_write(struct GKETH_info *lp,
    int mii_id, int regnum, u16 value)
{
    int                 errorCode = 0;
    int                 val;
    int                 limit = 0;

    for (limit = 200; limit > 0; limit--) {
        if (!gk_eth_tstbitsl(lp->regbase + ETH_MAC_GMII_ADDR_OFFSET,
            ETH_MAC_GMII_ADDR_GB))
            break;
        udelay(10);
    }
    if (limit <= 0) {
        printf("%s: MII Error: Prewrite tmo!\n", __func__);
        errorCode = -EIO;
        goto gkhw_mdio_write_exit;
    }

    val = value;
    gk_eth_writel(lp->regbase + ETH_MAC_GMII_DATA_OFFSET, val);
    val = ETH_MAC_GMII_ADDR_PA(mii_id) | ETH_MAC_GMII_ADDR_GR(regnum);
    val |= ETH_MAC_GMII_ADDR_CR_100_150MHZ | ETH_MAC_GMII_ADDR_GW |
        ETH_MAC_GMII_ADDR_GB;
    gk_eth_writel(lp->regbase + ETH_MAC_GMII_ADDR_OFFSET, val);

    for (limit = 200; limit > 0; limit--) {
        if (!gk_eth_tstbitsl(lp->regbase + ETH_MAC_GMII_ADDR_OFFSET,
            ETH_MAC_GMII_ADDR_GB))
            break;
        udelay(10);
    }
    if (limit <= 0) {
        printf("%s: MII Error: Postwrite tmo!\n", __func__);
        errorCode = -EIO;
        goto gkhw_mdio_write_exit;
    }

gkhw_mdio_write_exit:
    return errorCode;
}

static int gkhw_pht_reset(void)
{
    int retcode = 0;
    struct gk7101_gpio_io_info info = {
        .gpio_id = SYSTEM_GPIO_PHY_RESET,
        .active_level = GPIO_HIGH,
        .active_delay = 1,
    };
    if((retcode = gk7101_set_gpio_output(&info, 0)) != 0)
        return retcode;
    mdelay(200);//200ms
    if((retcode = gk7101_set_gpio_output(&info, 1)) != 0)
        return retcode;
    mdelay(200);//200ms

    return 0;

}

static void GKETH_rx_rngmng_init(struct GKETH_info *lp)
{
    int                 i;

    lp->rx.desc_rx = (struct GKETH_desc *)&rx_ring_des[0];
    lp->rx.cur_rx = 0;
    for (i = 0; i < lp->rx_count; i++) {
        lp->rx.desc_rx[i].status = ETH_RDES0_OWN;
        lp->rx.desc_rx[i].length = ETH_RDES1_DIC |
            ETH_RDES1_RCH | GKETH_DESC_BYTES;
        lp->rx.desc_rx[i].buffer2 = (u32)lp->rx_dma_desc +
            ((i + 1) * sizeof(struct GKETH_desc));
    }
    lp->rx.desc_rx[lp->rx_count - 1].buffer2 = (u32)lp->rx_dma_desc;
}

static void GKETH_rx_rngbuf_setup(struct GKETH_info *lp)
{
    int i;
    for(i = 0; i < lp->rx_count; i++) {

        lp->rx.desc_rx[i].buffer1 = (u32)(&rx_buf[i][0]);
    }
}

static void GKETH_tx_rngmng_init(struct GKETH_info *lp)
{
    int                 i;

    lp->tx.cur_tx = 0;
    lp->tx.desc_tx = (struct GKETH_desc *)&tx_ring_des[0];
    for (i = 0; i < lp->tx_count; i++) {
        lp->tx.desc_tx[i].status &= ~ETH_RDES0_OWN;
        lp->tx.desc_tx[i].length = (ETH_TDES1_LS | ETH_TDES1_FS |
            ETH_TDES1_TCH);
        lp->tx.desc_tx[i].buffer1 = 0;
        lp->tx.desc_tx[i].buffer2 = (u32)lp->tx_dma_desc +
            ((i + 1) * sizeof(struct GKETH_desc));
    }
    lp->tx.desc_tx[lp->tx_count - 1].buffer2 = (u32)lp->tx_dma_desc;
}

static void gk7101_eth_probe(struct GKETH_info *lp)
{
    lp->rx_count = GKETH_RX_RNG;
    lp->rx_dma_desc = (u32)(&rx_ring_des[0]);
    GKETH_rx_rngmng_init(lp);
    GKETH_rx_rngbuf_setup(lp);
    lp->tx_count = GKETH_TX_RNG;
    lp->tx_dma_desc = (u32)(&tx_ring_des[0]);
    GKETH_tx_rngmng_init(lp);
}

void MHal_EMAC_WritReg8( unsigned long bank, unsigned long reg, unsigned char val )
{
    unsigned long address = REG_EPHY_CONTROL + (bank-0x32)*0x100*2;
    address = address + (reg << 1) - (reg & 1);

    gk_eth_writeb(address,val);
}

unsigned char MHal_EMAC_ReadReg8( unsigned long bank, unsigned long reg )
{
    unsigned char val;
    unsigned long address = REG_EPHY_CONTROL + (bank-0x32)*0x100*2;
    address = address + (reg << 1) - (reg & 1);

    val = gk_eth_readb(address);

    return val;
}

static int gk7101_ethphy_init(struct GKETH_info *lp)

{
    int phyid, testr;
    int i, j, retcode;
    int counter = 0;
    unsigned char uRegVal;
    unsigned long tempVal;

    if(phy_type != 0)
    {
        for(j=0;j<phy_try;j++)
        {
            for(i = 0; i < PHY_MAX_ADDR; i++) {
                phyid = gkhw_mdio_read(lp, i, 3);
                phyid |= gkhw_mdio_read(lp, i, 2) << 16;
                //printf("phy id is 0x%08x\n", phyid);
                if((phyid != 0xFFFFFFFF) && (phyid != 0x00000000))
                {
                    printf("[phy:0x%08x] ", phyid);
                    lp->phydev.addr = i;
                    break;
                }
            }
            if(i != PHY_MAX_ADDR){
                break;
            }
            mdelay(100);//100ms
        }

        if(i == PHY_MAX_ADDR){
            printf("[no phy] ");
            retcode = -ENODEV;
            return retcode;
        }

        counter = 0;
        if(phyid == 0x02430c54) // IP101g
        {
        }
		else if((phyid & (~0xf)) == 0x7C0F0)//smsc 8720/8721
        {
            testr  = 0;
            testr  = gkhw_mdio_read(lp, lp->phydev.addr, 31);
            counter = 0;
            while(testr != 0x40){
                //net device need clear regsister, by hardware restart.
                gkhw_pht_reset();
                testr = 0;
                testr = gkhw_mdio_read(lp, lp->phydev.addr, 31);
                counter++;
                if (counter > 20)
                    break;
            }
            //printf("gkhw_mdio_read 31 reg:0x%08x counter:%d\n", testr, counter);
        }
        else
        {
            do {
                testr  = gkhw_mdio_read(lp, lp->phydev.addr, 0x19);
                testr |= (1 << 10);
                testr &= ~(1 << 11);
                gkhw_mdio_write(lp,lp->phydev.addr, 0x19, testr);
                mdelay(5);
                testr  = 0;
                testr  = gkhw_mdio_read(lp, lp->phydev.addr, 0x19);
                counter++;
                if (counter > 20) {
                    break;
                }
            } while ((!(testr & (1 << 10))) || (testr & (1 << 11)));
        }

        gk_gpio_writel(REG_GPIO_30_INPUT_CFG, 1);

    }
    else
    {
        gk_eth_writel(REG_EPHY_MDIIO_ERR_CNT_CLEAR, 0x00000000);
        gk_eth_writel(REG_EPHY_MUX_SEL, 0x0000C400);  // reg_test_out(debug_bus_out)
        gk_eth_writel(REG_EPHY_SIGNAL_SEL, 0x0000810A);  // debug mode
        gk_eth_writel(REG_EPHY_CLK_200, 0x00000007);  // DAC 100M clk gate for 10M TX

        MHal_EMAC_WritReg8(0x0033, 0xde, 0x59);
        MHal_EMAC_WritReg8(0x0033, 0xf4, 0x21);
        MHal_EMAC_WritReg8(0x0032, 0x72, 0x80);
        MHal_EMAC_WritReg8(0x0033, 0xfc, 0x00);
        MHal_EMAC_WritReg8(0x0033, 0xfd, 0x00);
        MHal_EMAC_WritReg8(0x0033, 0xb7, 0x07);
        MHal_EMAC_WritReg8(0x0033, 0xcb, 0x11);
        MHal_EMAC_WritReg8(0x0033, 0xcc, 0x80);
        MHal_EMAC_WritReg8(0x0033, 0xcd, 0xd1);
        MHal_EMAC_WritReg8(0x0033, 0xd4, 0x00);
        MHal_EMAC_WritReg8(0x0033, 0xb9, 0x40);
        MHal_EMAC_WritReg8(0x0033, 0xbb, 0x05);
        MHal_EMAC_WritReg8(0x0033, 0xea, 0x46);
        MHal_EMAC_WritReg8(0x0033, 0xa1, 0x00);
        MHal_EMAC_WritReg8(0x0034, 0x3a, 0x03);
        MHal_EMAC_WritReg8(0x0034, 0x3b, 0x00);

        //gain shift
        MHal_EMAC_WritReg8(0x0033, 0xb4, 0x56);

        //det max
        MHal_EMAC_WritReg8(0x0033, 0x4f, 0x02);

        //det min
        MHal_EMAC_WritReg8(0x0033, 0x51, 0x01);

        //snr len (emc noise)
        MHal_EMAC_WritReg8(0x0033, 0x77, 0x18);

        //snr k value
        MHal_EMAC_WritReg8(0x0033, 0x43, 0x15);

        //100 gat
        MHal_EMAC_WritReg8(0x0034, 0xc5, 0x00);

        //200 gat
        MHal_EMAC_WritReg8(0x0034, 0x30, 0x43);

        //en_100t_phase
        MHal_EMAC_WritReg8(0x0034, 0x39, 0x41);

        //10T waveform
        uRegVal = MHal_EMAC_ReadReg8(0x0034, 0xe8);
        uRegVal &= 0xf8;
        uRegVal |= 0x06;
        MHal_EMAC_WritReg8(0x0034, 0xe8, uRegVal);
        MHal_EMAC_WritReg8(0x0032, 0x2b, 0x00);

        //analog
        MHal_EMAC_WritReg8(0x0033, 0xd8, 0xb0);
        MHal_EMAC_WritReg8(0x0033, 0xd9, 0x30);

        //disable EEE
        uRegVal = MHal_EMAC_ReadReg8(0x0032, 0x2d);
        uRegVal |= 0x40;
        MHal_EMAC_WritReg8(0x0032, 0x2d, uRegVal);

        tempVal = gk_eth_readl(REG_EPHY_SPEED_SEL)| (1 << 12);
        gk_eth_writel(REG_EPHY_SPEED_SEL, tempVal);

    }

    return 0;
}

int gk7101_eth_config_register(void)
{
    int retcode, val;
    struct GKETH_info *lp = &gk7101_info;
#if defined(CONFIG_USE_EXT_PHY)
    char *s;

    s = getenv ("phytype");
    phy_type = s ? (int)simple_strtol(s, NULL, 10) : CONFIG_USE_EXT_PHY;
    s = getenv ("phytry");
    phy_try = s ? (int)simple_strtol(s, NULL, 10) : 3;
#endif

    if(phy_type != 0)
    {
        gk_gpio_writel(GPIO0_PER_SEL_REG, gk_gpio_readl(GPIO0_PER_SEL_REG) | 0x00000001);
#ifdef CONFIG_PHY_USE_SD_CLK
        // modify core pll to 550MHz
        gk_rct_writel(REG_PLL_CORE_CTRL_REG2, gk_rct_readl(REG_PLL_CORE_CTRL_REG2) & 0xFFFFFFE7);
        gk_rct_writel(REG_PLL_CORE_CTRL, 0x0011202D);
        gk_rct_writel(REG_PLL_CORE_FRAC, 0x00D55555);
        gk_rct_writel(REG_PLL_SCALER_SD48_REG, 0x00000016);
#endif
#ifdef CONFIG_PHY_USE_AO_MCLK
        // Fout=(Fin/ REFDIV)*(FBDIV+ FRAC/2^24)/ POSTDIV1/ POSTDIV2
        // Fout=(24 / 1)*(0x20+0x00555555/2^24=0.33333333)/4/2=100Mhz
        gk_rct_writel(REG_PLL_AUDIO_CTRL, 0x00124021);
        gk_rct_writel(REG_PLL_AUDIOO_FRAC, 0x00555555);

        if (phy_type == 2)
            gk_rct_writel(REG_PLL_DIV_AUDIO_PST, 0x00000002);  // 50Mhz
        else//default use 25Mhz
            gk_rct_writel(REG_PLL_DIV_AUDIO_PST, 0x00000004);  // 25Mhz

        gk_rct_writel(REG_PLL_DIV_AUDIO_PRE, 0x00000001);
#endif

        gkhw_pht_reset();
    }
    else
    {
        gk_gpio_writel(GPIO0_PER_SEL_REG, gk_gpio_readl(GPIO0_PER_SEL_REG) & 0xFFFFFFFE);
#ifdef CONFIG_PHY_USE_SD_CLK
        // use sd clk for ethernet clk
        // 552 / 23 = 24MHz
        gk_rct_writel(REG_PLL_CORE_CTRL_REG2, gk_rct_readl(REG_PLL_CORE_CTRL_REG2) | 0x00000018);
        gk_rct_writel(REG_PLL_CORE_CTRL, 0x0011202E);
        gk_rct_writel(REG_PLL_CORE_FRAC, 0x00000000);
        gk_rct_writel(REG_PLL_SCALER_SD48_REG, 0x00000017);
#endif
#ifdef CONFIG_PHY_USE_AO_MCLK
        // use audio mclk
        // Fout=(Fin/ REFDIV)*(FBDIV+ FRAC/2^24)/ POSTDIV1/ POSTDIV2
        // Fout=(24 / 1)*(0x20+0)/4/2=96Mhz
        gk_rct_writel(REG_PLL_AUDIO_CTRL, 0x00124020);
        gk_rct_writel(REG_PLL_AUDIOO_FRAC, 0x00000000);
        gk_rct_writel(REG_PLL_DIV_AUDIO_PST, 0x00000004);  // 24Mhz
        gk_rct_writel(REG_PLL_DIV_AUDIO_PRE, 0x00000001);
#endif
    }

    retcode = gk7101_ethphy_init(lp);
    if(retcode != 0)
        return retcode;
    //set mii/rmii mode
    if (phy_type != 0)
    {
#if CONFIG_BOARD_HARDWARE_INFO
        printf("Net:   Ext PHY %s\n", (phy_type == 2)?"50MHz":"25MHz");
#endif
        val = gk_eth_readl(REG_EPHY_AHB_GENNERNAL0) | (0x1 << 1);
    }
    else
    {
#if CONFIG_BOARD_HARDWARE_INFO
        printf("Net:   Int PHY \n");
#endif
        val = gk_eth_readl(REG_EPHY_AHB_GENNERNAL0) & 0xFFFFFFFD;
    }
    gk_eth_writel(REG_EPHY_AHB_GENNERNAL0, val);
}

int gk7101_eth_init(struct eth_device *dev, bd_t *bis)
{
    int retcode = 0;
    struct GKETH_info *lp;
    u16 bmcr;

    lp = container_of(dev, struct GKETH_info, netdev);
    retcode = gkhw_mac_enable(lp);
    if(retcode != 0)
        return retcode;

    gk7101_eth_probe(lp);
    gkhw_set_dma_desc(lp);
    gkhw_dma_rx_start(lp);
    ///////////////////////////////////////////////////////////////////////////
    // Steven Yu: check link status
    // phy_type = 0, auto set
    if(phy_type != 0)
    {
        bmcr = gkhw_mdio_read(lp, lp->phydev.addr, MII_BMCR);
        if(bmcr & BMCR_SPEED100)
        {
            gk7101_gpio_set_incfg(GPIO_GET_IN_SEL(GPIO_TYPE_INPUT_ENET_PHY_RXD_3) - 0x02, 0x01);
        }
        else
        {
            gk7101_gpio_set_incfg(GPIO_GET_IN_SEL(GPIO_TYPE_INPUT_ENET_PHY_RXD_3) - 0x02, 0x00);
        }
    }
    gk_eth_clrbitsl(lp->regbase + ETH_MAC_CFG_OFFSET, ETH_MAC_CFG_DO);
    gk_eth_setbitsl(lp->regbase + ETH_MAC_CFG_OFFSET, ETH_MAC_CFG_DM);
    ///////////////////////////////////////////////////////////////////////////
    return retcode;
}

int gk7101_eth_send(struct eth_device *dev, void *packet, int length)
{
    int retcode = 0;
    int tmo = 5000;
    struct GKETH_desc *tx_desc;
    struct GKETH_info *lp;
    lp = container_of(dev, struct GKETH_info, netdev);
    tx_desc = &(lp->tx.desc_tx[lp->tx.cur_tx]);
    tx_desc->length &= 0xFFFFF800;
    tx_desc->length |= length & 0x7FF;
    tx_desc->buffer1 = (u32)packet;
    if(lp->tx.cur_tx < (GKETH_TX_RNG - 1))
        lp->tx.cur_tx++;
    else
        lp->tx.cur_tx = 0;
    udelay(5);

    tx_desc->status |= ETH_TDES0_OWN;
    gkhw_dma_tx_start(lp);
    while((tx_desc->status & ETH_TDES0_OWN) == ETH_TDES0_OWN) {
        if (tmo <= 0) {
            gkhw_dma_tx_stop(lp);
            retcode = -ETIMEDOUT;
            break;
        }

        tmo--;
        udelay(10);
    }
    tx_desc->buffer1 = 0;
    gkhw_dma_tx_stop(lp);
    dcache_enable();
    return retcode;
}

int gk7101_eth_recv(struct eth_device *dev)
{
    int retcode = 0;
    int rxlen;
    int index;
    struct GKETH_desc *rx_desc;
    struct GKETH_info *lp;
    lp = container_of(dev, struct GKETH_info, netdev);
    index = lp->rx.cur_rx;
    while(1) {
        rx_desc = &(lp->rx.desc_rx[index]);
        if((rx_desc->status & ETH_RDES0_OWN) != ETH_RDES0_OWN){
            if((rx_desc->status & ETH_RDES0_ES) == ETH_RDES0_ES){
                printf("%s: Receive packages error %08x\n", __func__, rx_desc->status);
                rx_desc->status = ETH_RDES0_OWN;
                retcode = -EIO;
                break;
            }
            rxlen = ETH_RDES0_FL(rx_desc->status);

            NetReceive((u8 *)(rx_desc->buffer1), rxlen);
            rx_desc->status |= ETH_RDES0_OWN;
            if(index < (GKETH_RX_RNG - 1)){
                lp->rx.cur_rx = ++index;
            }else {
                lp->rx.cur_rx = 0;
            }
            index = lp->rx.cur_rx;
            break;
        }else {
            break;
        }
    }
    return retcode;
}

void gk7101_eth_halt(struct eth_device *dev)
{
    struct GKETH_info *lp;
    lp = container_of(dev, struct GKETH_info, netdev);
    gkhw_mac_disable(lp);
}

int gk7101_eth_write_hwaddr(struct eth_device *dev)
{
    int retcode = 0;
    struct GKETH_info *lp;
    lp = container_of(dev, struct GKETH_info, netdev);
    gkhw_set_hwaddr(lp, dev->enetaddr);
    return retcode;
}

int gk7101_eth_initialize(bd_t *bis)
{
    struct eth_device *dev = &(gk7101_info.netdev);
    tx_ring_des = (struct GKETH_desc*)((u32)&tx_ring_desbuffer[0] + (0x20 - ((u32)&tx_ring_desbuffer[0] % 0x20)));
    /* Load MAC address from EEPROM */
    gk7101_info.regbase = (unsigned char *)REG_ETH_MAC_CONFIG;
    dev->init = gk7101_eth_init;
    dev->halt = gk7101_eth_halt;
    dev->send = gk7101_eth_send;
    dev->recv = gk7101_eth_recv;
    dev->write_hwaddr = gk7101_eth_write_hwaddr;
    sprintf(dev->name, "gk7101");
    eth_register(dev);
    gk7101_eth_config_register();

    return 0;
}
