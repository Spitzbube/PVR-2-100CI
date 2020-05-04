/*
 * Copyright (C) 2015 Goke Microelectronic Ltd
 *
 * GPL-2.0+
 */

#ifndef _GK7101_GPIO_H_
#define _GK7101_GPIO_H_

#include <asm/arch-gk7101/gk7101_reg.h>

//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************
#define GPIO(x)     (x)

/****************************************************/
/* Capabilities based on chip revision              */
/****************************************************/
#define GPIO_INSTANCES          1

#define GPIO_BANK_SIZE          64
#define GPIO_TOTAL_NUM          (GPIO_INSTANCES * GPIO_BANK_SIZE)

#define GPIO0_BASE              (REG_GPIO_BASE)

#define GPIO0_REG(x)            (GPIO0_BASE + (x))

#define GPIO_MAX_LINES          64

/****************************************************/
/*      Controller registers definitions                                      */
/****************************************************/
#define GPIO_IS_LOW_OFFSET              0x000 /* read/write */
#define GPIO_IS_HIGH_OFFSET             0x004 /* read/write */
#define GPIO_IBE_LOW_OFFSET             0x008 /* read/write */
#define GPIO_IBE_HIGH_OFFSET            0x00C /* read/write */
#define GPIO_IEV_LOW_OFFSET             0x010 /* read/write */
#define GPIO_IEV_HIGH_OFFSET            0x014 /* read/write */
#define GPIO_IE_LOW_OFFSET              0x018 /* read/write */
#define GPIO_IE_HIGH_OFFSET             0x01C /* read/write */
#define GPIO_IC_LOW_OFFSET              0x020 /* write */
#define GPIO_IC_HIGH_OFFSET             0x024 /* write */
#define GPIO_RIS_LOW_OFFSET             0x028 /* read */
#define GPIO_RIS_HIGH_OFFSET            0x02C /* read */
#define GPIO_MIS_LOW_OFFSET             0x030 /* read */
#define GPIO_MIS_HIGH_OFFSET            0x034 /* read */
#define GPIO_INT_EN_OFFSET              0x038 /* write */
#define GPIO_PER_SEL_OFFSET             0x03C /* read/write */
#define GPIO_DIN_LOW_OFFSET             0x040 /* read */
#define GPIO_DIN_HIGH_OFFSET            0x044 /* read */
#define GPIO_OUTPUT_CFG_OFFSET          0x100 /* write */
#define GPIO_INPUT_CFG_OFFSET           0x200 /* write */

#define REG_OUTCFG_OEN_INVERT           0x8000
#define REG_OUTCFG_OUT_INVERT           0x4000
#define REG_OUTCFG_OEN_SELECT           0x3F00
#define REG_CONFIG_IN_OUT_SEL           0x003F


#define GPIO0_IS_LOW_REG                GPIO0_REG(GPIO_IS_LOW_OFFSET    )
#define GPIO0_IS_HIGH_REG               GPIO0_REG(GPIO_IS_HIGH_OFFSET   )
#define GPIO0_IBE_LOW_REG               GPIO0_REG(GPIO_IBE_LOW_OFFSET   )
#define GPIO0_IBE_HIGH_REG              GPIO0_REG(GPIO_IBE_HIGH_OFFSET  )
#define GPIO0_IEV_LOW_REG               GPIO0_REG(GPIO_IEV_LOW_OFFSET   )
#define GPIO0_IEV_HIGH_REG              GPIO0_REG(GPIO_IEV_HIGH_OFFSET  )
#define GPIO0_IE_LOW_REG                GPIO0_REG(GPIO_IE_LOW_OFFSET    )
#define GPIO0_IE_HIGH_REG               GPIO0_REG(GPIO_IE_HIGH_OFFSET   )
#define GPIO0_IC_LOW_REG                GPIO0_REG(GPIO_IC_LOW_OFFSET    )
#define GPIO0_IC_HIGH_REG               GPIO0_REG(GPIO_IC_HIGH_OFFSET   )
#define GPIO0_RIS_LOW_REG               GPIO0_REG(GPIO_RIS_LOW_OFFSET   )
#define GPIO0_RIS_HIGH_REG              GPIO0_REG(GPIO_RIS_HIGH_OFFSET  )
#define GPIO0_MIS_LOW_REG               GPIO0_REG(GPIO_MIS_LOW_OFFSET   )
#define GPIO0_MIS_HIGH_REG              GPIO0_REG(GPIO_MIS_HIGH_OFFSET  )
#define GPIO0_INT_EN_REG                GPIO0_REG(GPIO_INT_EN_OFFSET    )
#define GPIO0_PER_SEL_REG               GPIO0_REG(GPIO_PER_SEL_OFFSET   )
#define GPIO0_DIN_LOW_REG               GPIO0_REG(GPIO_DIN_LOW_OFFSET   )
#define GPIO0_DIN_HIGH_REG              GPIO0_REG(GPIO_DIN_HIGH_OFFSET  )
#define GPIO0_OUTPUT_CFG_REG            GPIO0_REG(GPIO_OUTPUT_CFG_OFFSET)
#define GPIO0_INPUT_CFG_REG             GPIO0_REG(GPIO_INPUT_CFG_OFFSET )


/************************/
/*   GPIO pins definition       */
/************************/

#define GPIO_OUT_OEN_INVERT     0x80
#define GPIO_OUT_OUT_INVERT     0x40

#define GPIO_DIRECTION_OUT(n)   (n)
#define GPIO_DIRECTION_IN(n)    ((n) & 0xff00)


#define GPIO_SET_OUT_SEL(n)     ((n))
#define GPIO_SET_IN_SEL(n)      ((n)<<8)
#define GPIO_SET_OEN_SEL(n)     ((n)<<16)
#define GPIO_SET_OUT_INVERT(n)  ((n)<<22)
#define GPIO_SET_OEN_INVERT(n)  ((n)<<23)
#define GPIO_SET_IOCTRL(n)      ((n)<<24)
#define GPIO_SET_FUNC(n)        ((n)<<30)

#define GPIO_GET_OUT_SEL(n)     (((n)&0x000000FF))
#define GPIO_GET_IN_SEL(n)      (((n)&0x0000FF00)>>8)
#define GPIO_GET_OEN_SEL(n)     (((n)&0x003F0000)>>16)
#define GPIO_GET_OUT_INVERT(n)  (((n)&0x00400000)>>22)
#define GPIO_GET_OEN_INVERT(n)  (((n)&0x00800000)>>23)
#define GPIO_GET_IOCTRL(n)      (((n)&0x3F000000)>>24)
#define GPIO_GET_FUNC(n)        (((n)&0xC0000000)>>30)

#define IOCTRL_NORMAL           0x00    //!< Hi-z
#define IOCTRL_PULL_UP          0x10    //!< PULL_UP
#define IOCTRL_PULL_DOWN        0x20    //!< PULL_DOWN
#define IOCTRL_REPEAT           0x30    //!< REPEAT

#define IOCTRL_2MA              0x00    //!< 2mA
#define IOCTRL_4MA              0x01    //!< 4mA
#define IOCTRL_8MA              0x02    //!< 8mA
#define IOCTRL_12MA             0x03    //!< 12mA


//*****************************************************************************
//*****************************************************************************
//** Enumerated types
//*****************************************************************************
//*****************************************************************************
/* SW definitions */
#define GPIO_HIGH               1
#define GPIO_LOW                0

/* GPIO function selection */
/* Select SW or HW control and input/output direction of S/W function */
#define GPIO_FUNC_SW_INPUT      0
#define GPIO_FUNC_SW_OUTPUT     1
#define GPIO_FUNC_HW            2

/* GPIO function selection */
typedef enum
{
    GPIO_FUNC_IN     = 1,
    GPIO_FUNC_OUT    = 2,
    GPIO_FUNC_INOUT  = 3,
}GPIO_FUNC_TYPE_E;

typedef enum
{
    /* ----------------------------------- GPIO output function define ----------------------------------- */
    GPIO_TYPE_OUTPUT_0               = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 0),    //!< Output type: value = 0
    GPIO_TYPE_OUTPUT_1               = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 1),    //!< Output type: value = 1
    GPIO_TYPE_OUTPUT_SPI1_SO         = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 2) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 2),    //!< Output type: tssi_txd
    GPIO_TYPE_OUTPUT_SPI1_CS0        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 3),    //!< Output type: tssi_cs0_n
    GPIO_TYPE_OUTPUT_SPI1_SCLK       = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 4),    //!< Output type: tssi_sclk_out
    GPIO_TYPE_OUTPUT_UART2_RTS_N     = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 5),    //!< Output type: uart2_rts_n
    GPIO_TYPE_OUTPUT_UART2_DTR_N     = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 6),    //!< Output type: uart2_dtr_n
    GPIO_TYPE_OUTPUT_UART2_TX        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)     | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 7),    //!< Output type: uart2_tx
    GPIO_TYPE_OUTPUT_UART1_TX        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)     | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 8),    //!< Output type: uart1_tx
    GPIO_TYPE_OUTPUT_UART0_TX        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)     | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL( 9),    //!< Output type: uart0_tx
    GPIO_TYPE_OUTPUT_PWM3_OUT        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(10),    //!< Output type: pwm3_out
    GPIO_TYPE_OUTPUT_PWM2_OUT        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(11),    //!< Output type: pwm2_out
    GPIO_TYPE_OUTPUT_PWM1_OUT        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(12),    //!< Output type: pwm1_out
    GPIO_TYPE_OUTPUT_PWM0_OUT        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(13),    //!< Output type: pwm0_out
    GPIO_TYPE_OUTPUT_SPI0_SO         = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 7) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(14),    //!< Output type: ssi_txd
    GPIO_TYPE_OUTPUT_SPI0_CS7        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(15),    //!< Output type: ssi_cs7_n
    GPIO_TYPE_OUTPUT_SPI0_CS6        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(16),    //!< Output type: ssi_cs6_n
    GPIO_TYPE_OUTPUT_SPI0_CS5        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(17),    //!< Output type: ssi_cs5_n
    GPIO_TYPE_OUTPUT_SPI0_CS4        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(18),    //!< Output type: ssi_cs4_n
    GPIO_TYPE_OUTPUT_SPI0_CS1        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(19),    //!< Output type: ssi_cs1_n
    GPIO_TYPE_OUTPUT_SPI0_CS0        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(20),    //!< Output type: ssi_cs0_n
    GPIO_TYPE_OUTPUT_SPI0_SCLK       = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(21),    //!< Output type: ssi_sclk_out
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL( 8)                          GPIO_SET_OUT_SEL(22)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL( 9)                          GPIO_SET_OUT_SEL(23)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL(10)                          GPIO_SET_OUT_SEL(24)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL(11)                          GPIO_SET_OUT_SEL(25)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL(12)                          GPIO_SET_OUT_SEL(26)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL(13)                          GPIO_SET_OUT_SEL(27)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL(14)                          GPIO_SET_OUT_SEL(28)
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                         GPIO_SET_OEN_SEL(15)                          GPIO_SET_OUT_SEL(29)
    //GPIO_TYPE_INOUT_SDIO_CMD                                                                                                                                          GPIO_SET_OEN_SEL(16)                          GPIO_SET_OUT_SEL(30)
    GPIO_TYPE_OUTPUT_SDIO_CLK        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)     | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(31),    //!< Output type: sd_clk_sdcard
    GPIO_TYPE_OUTPUT_AOMCLK          = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(32),    //!< Output type: i2s_au_clk
    GPIO_TYPE_OUTPUT_AOBCLK          = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(17) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(33),    //!< Output type: i2s_clk_o
    GPIO_TYPE_OUTPUT_AOLRCLK         = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(18) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(34),    //!< Output type: i2s_ws_o
    GPIO_TYPE_OUTPUT_AO_DATA0        = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(35),    //!< Output type: i2s_so
    GPIO_TYPE_OUTPUT_SF_CS0          = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(36),    //!< Output type: sf_cs0_n
    GPIO_TYPE_OUTPUT_SF_CS1          = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(37),    //!< Output type: sf_cs1_n
    GPIO_TYPE_OUTPUT_EPHY_LED_0      = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(38),    //!< Output type: ephy_led[0] hcd ok
    GPIO_TYPE_OUTPUT_EPHY_LED_1      = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(39),    //!< Output type: ephy_led[1] duplex
    GPIO_TYPE_OUTPUT_EPHY_LED_2      = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(40),    //!< Output type: ephy_led[2] 10M CRS out
    GPIO_TYPE_OUTPUT_EPHY_LED_3      = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(41),    //!< Output type: ephy_led[3] 100M CRS out
    GPIO_TYPE_OUTPUT_EPHY_LED_4      = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(42),    //!< Output type: ephy_led[4] clo gs
    GPIO_TYPE_OUTPUT_ENET_PHY_TXD_0  = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(43),    //!< Output type: enet_phy_txd[0]
    GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1  = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(44),    //!< Output type: enet_phy_txd[1]
    GPIO_TYPE_OUTPUT_ENET_PHY_TXD_2  = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(45),    //!< Output type: enet_phy_txd[2]
    GPIO_TYPE_OUTPUT_ENET_PHY_TXD_3  = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(46),    //!< Output type: enet_phy_txd[3]
    GPIO_TYPE_OUTPUT_ENET_PHY_TXER   = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(47),    //!< Output type: enet_phy_txer
    GPIO_TYPE_OUTPUT_ENET_PHY_TXEN   = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(48),    //!< Output type: enet_phy_txen
    // GPIO_TYPE_INOUT_ETH_MDIO                                                                                                                                                                                      GPIO_SET_OUT_SEL(49)
    GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(50),    //!< Output type: enet_gmii_mdc_o
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_0    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(51),    //!< Output type: ahb_dac_dr[0]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_1    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(52),    //!< Output type: ahb_dac_dr[1]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_2    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(53),    //!< Output type: ahb_dac_dr[2]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_3    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(54),    //!< Output type: ahb_dac_dr[3]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_4    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(55),    //!< Output type: ahb_dac_dr[4]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_5    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(56),    //!< Output type: ahb_dac_dr[5]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_6    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(57),    //!< Output type: ahb_dac_dr[6]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_7    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(58),    //!< Output type: ahb_dac_dr[7]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_8    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(59),    //!< Output type: ahb_dac_dr[8]
    GPIO_TYPE_OUTPUT_AHB_DAC_DR_9    = GPIO_SET_FUNC(GPIO_FUNC_OUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 0) | GPIO_SET_IN_SEL( 0)   | GPIO_SET_OUT_SEL(60),    //!< Output type: ahb_dac_dr[9]

    /* ----------------------------------- GPIO input function define ----------------------------------- */

    GPIO_TYPE_INPUT                  = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_NORMAL|IOCTRL_2MA)       | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(   0) | GPIO_SET_OUT_SEL( 0),    //!< Input type: normal input
    GPIO_TYPE_INPUT_0                = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(   0) | GPIO_SET_OUT_SEL( 0),    //!< Input type: normal input
    GPIO_TYPE_INPUT_1                = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)      | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(   1) | GPIO_SET_OUT_SEL( 0),    //!< Input type: normal input
    GPIO_TYPE_INPUT_SPI1_SI          = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+ 0) | GPIO_SET_OUT_SEL( 0),    //!< Input type: tssi_rxd
    //GPIO_TYPE_INOUT_I2C_DATA                                                                                                                                                                GPIO_SET_IN_SEL(2+ 1)
    //GPIO_TYPE_INOUT_I2C_CLK                                                                                                                                                                 GPIO_SET_IN_SEL(2+ 2)
    //GPIO_TYPE_INOUT_I2C_DATA2                                                                                                                                                               GPIO_SET_IN_SEL(2+ 3)
    //GPIO_TYPE_INOUT_I2C_CLK2                                                                                                                                                                GPIO_SET_IN_SEL(2+ 4)
    GPIO_TYPE_INPUT_UART2_RX         = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)      | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+ 5) | GPIO_SET_OUT_SEL( 0),    //!< Input type: uart2_rx
    GPIO_TYPE_INPUT_UART1_RX         = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)      | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+ 6) | GPIO_SET_OUT_SEL( 0),    //!< Input type: uart1_rx
    GPIO_TYPE_INPUT_UART0_RX         = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)      | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+ 7) | GPIO_SET_OUT_SEL( 0),    //!< Input type: uart0_rx
    GPIO_TYPE_INPUT_TIMER1_CLK       = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+ 8) | GPIO_SET_OUT_SEL( 0),    //!< Input type: timer1_clk
    GPIO_TYPE_INPUT_TIMER2_CLK       = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+ 9) | GPIO_SET_OUT_SEL( 0),    //!< Input type: timer2_clk
    GPIO_TYPE_INPUT_TIMER3_CLK       = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+10) | GPIO_SET_OUT_SEL( 0),    //!< Input type: timer3_clk
    GPIO_TYPE_INPUT_SPI0_SI          = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+11) | GPIO_SET_OUT_SEL( 0),    //!< Input type: ssi_rxd
    GPIO_TYPE_INPUT_SD_WP_N          = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)      | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+12) | GPIO_SET_OUT_SEL( 0),    //!< Input type: sd_wp_n
    GPIO_TYPE_INPUT_SD_CD_N          = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)      | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+13) | GPIO_SET_OUT_SEL( 0),    //!< Input type: sd_cd_n
    //GPIO_TYPE_INOUT_SD_DATA_0                                                                                                                                                               GPIO_SET_IN_SEL(2+14)
    //GPIO_TYPE_INOUT_SD_DATA_1                                                                                                                                                               GPIO_SET_IN_SEL(2+15)
    //GPIO_TYPE_INOUT_SD_DATA_2                                                                                                                                                               GPIO_SET_IN_SEL(2+16)
    //GPIO_TYPE_INOUT_SD_DATA_3                                                                                                                                                               GPIO_SET_IN_SEL(2+17)
    //GPIO_TYPE_INOUT_SD_DATA_4                                                                                                                                                               GPIO_SET_IN_SEL(2+18)
    //GPIO_TYPE_INOUT_SD_DATA_5                                                                                                                                                               GPIO_SET_IN_SEL(2+19)
    //GPIO_TYPE_INOUT_SD_DATA_6                                                                                                                                                               GPIO_SET_IN_SEL(2+20)
    //GPIO_TYPE_INOUT_SD_DATA_7                                                                                                                                                               GPIO_SET_IN_SEL(2+21)
    //GPIO_TYPE_INOUT_SDIO_CMD                                                                                                                                                                GPIO_SET_IN_SEL(2+22)
    GPIO_TYPE_INPUT_I2S_CLK          = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+23) | GPIO_SET_OUT_SEL( 0),    //!< Input type: i2s_clk
    GPIO_TYPE_INPUT_I2S_WS           = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+24) | GPIO_SET_OUT_SEL( 0),    //!< Input type: i2s_ws
    GPIO_TYPE_INPUT_I2S_SI           = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+25) | GPIO_SET_OUT_SEL( 0),    //!< Input type: i2s_si
    GPIO_TYPE_INPUT_CLK_AU           = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+26) | GPIO_SET_OUT_SEL( 0),    //!< Input type: clk_au
    GPIO_TYPE_INPUT_ENET_PHY_RXD_0   = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+27) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_rxd[0]
    GPIO_TYPE_INPUT_ENET_PHY_RXD_1   = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+28) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_rxd[1]
    GPIO_TYPE_INPUT_ENET_PHY_RXD_2   = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+29) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_rxd[2]
    GPIO_TYPE_INPUT_ENET_PHY_RXD_3   = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+30) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_rxd[3]
    GPIO_TYPE_INPUT_ENET_PHY_COL     = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+31) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_col
    GPIO_TYPE_INPUT_ENET_PHY_CRS     = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+32) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_crs
    GPIO_TYPE_INPUT_ENET_PHY_RXER    = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+33) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_rxer
    GPIO_TYPE_INPUT_ENET_PHY_RXDV    = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+34) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_phy_rxdv
    // GPIO_TYPE_INOUT_ETH_MDIO                                                                                                                                                               GPIO_SET_IN_SEL(2+35)
    GPIO_TYPE_INPUT_ENET_CLK_RX      = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+36) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_clk_rx
    GPIO_TYPE_INPUT_ENET_CLK_TX      = GPIO_SET_FUNC(GPIO_FUNC_IN) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA)    | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 1) | GPIO_SET_IN_SEL(2+37) | GPIO_SET_OUT_SEL( 0),    //!< Input type: enet_clk_tx

    /* ----------------------------------- GPIO input&&output function define ----------------------------------- */
    GPIO_TYPE_INOUT_I2C_DATA         = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 3) | GPIO_SET_IN_SEL(2+ 1) | GPIO_SET_OUT_SEL( 0),    //!< Input/Output type: i2c_sda
    GPIO_TYPE_INOUT_I2C_CLK          = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 4) | GPIO_SET_IN_SEL(2+ 2) | GPIO_SET_OUT_SEL( 0),    //!< Input/Output type: i2c_scl
    GPIO_TYPE_INOUT_I2C_DATA2        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 5) | GPIO_SET_IN_SEL(2+ 3) | GPIO_SET_OUT_SEL( 0),    //!< Input/Output type: i2c_sda2
    GPIO_TYPE_INOUT_I2C_CLK2         = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(0) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 6) | GPIO_SET_IN_SEL(2+ 4) | GPIO_SET_OUT_SEL( 0),    //!< Input/Output type: i2c_scl2

    GPIO_TYPE_INOUT_ETH_MDIO         = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_DOWN|IOCTRL_2MA) | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(19) | GPIO_SET_IN_SEL(2+35) | GPIO_SET_OUT_SEL(49),    //!< Input/Output type: enet_gmii_mdi/enet_gmii_mod_o

    GPIO_TYPE_INOUT_SD_DATA_0        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 8) | GPIO_SET_IN_SEL(2+14) | GPIO_SET_OUT_SEL(22),    //!< Input/Output type: sd_data_out[0]
    GPIO_TYPE_INOUT_SD_DATA_1        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL( 9) | GPIO_SET_IN_SEL(2+15) | GPIO_SET_OUT_SEL(23),    //!< Input/Output type: sd_data_out[1]
    GPIO_TYPE_INOUT_SD_DATA_2        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(10) | GPIO_SET_IN_SEL(2+16) | GPIO_SET_OUT_SEL(24),    //!< Input/Output type: sd_data_out[2]
    GPIO_TYPE_INOUT_SD_DATA_3        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(11) | GPIO_SET_IN_SEL(2+17) | GPIO_SET_OUT_SEL(25),    //!< Input/Output type: sd_data_out[3]
    GPIO_TYPE_INOUT_SD_DATA_4        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(12) | GPIO_SET_IN_SEL(2+18) | GPIO_SET_OUT_SEL(26),    //!< Input/Output type: sd_data_out[4]
    GPIO_TYPE_INOUT_SD_DATA_5        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(13) | GPIO_SET_IN_SEL(2+19) | GPIO_SET_OUT_SEL(27),    //!< Input/Output type: sd_data_out[5]
    GPIO_TYPE_INOUT_SD_DATA_6        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(14) | GPIO_SET_IN_SEL(2+20) | GPIO_SET_OUT_SEL(28),    //!< Input/Output type: sd_data_out[6]
    GPIO_TYPE_INOUT_SD_DATA_7        = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(15) | GPIO_SET_IN_SEL(2+21) | GPIO_SET_OUT_SEL(29),    //!< Input/Output type: sd_data_out[7]
    GPIO_TYPE_INOUT_SD_CMD           = GPIO_SET_FUNC(GPIO_FUNC_INOUT) | GPIO_SET_IOCTRL(IOCTRL_PULL_UP|IOCTRL_2MA)   | GPIO_SET_OEN_INVERT(1) | GPIO_SET_OUT_INVERT(0) | GPIO_SET_OEN_SEL(16) | GPIO_SET_IN_SEL(2+22) | GPIO_SET_OUT_SEL(30),    //!< Input/Output : sd_cmd

    GPIO_TYPE_UNDEFINED              = 0,
} GPIO_TYPE_E;

/*!
*******************************************************************************
**
** \brief All available GPIO pins named by number.
**
** \sa GPIO_Open()
** \sa GPIO_OpenFunctionMode()
** \sa GPIO_SetType()
**
*******************************************************************************
*/
typedef enum
{
    GPIO_0  =  0, //!< Value representing GPIO  0.
    GPIO_1  =  1, //!< Value representing GPIO  1.
    GPIO_2  =  2, //!< Value representing GPIO  2.
    GPIO_3  =  3, //!< Value representing GPIO  3.
    GPIO_4  =  4, //!< Value representing GPIO  4.
    GPIO_5  =  5, //!< Value representing GPIO  5.
    GPIO_6  =  6, //!< Value representing GPIO  6.
    GPIO_7  =  7, //!< Value representing GPIO  7.
    GPIO_8  =  8, //!< Value representing GPIO  8.
    GPIO_9  =  9, //!< Value representing GPIO  9.
    GPIO_10 = 10, //!< Value representing GPIO 10.
    GPIO_11 = 11, //!< Value representing GPIO 11.
    GPIO_12 = 12, //!< Value representing GPIO 12.
    GPIO_13 = 13, //!< Value representing GPIO 13.
    GPIO_14 = 14, //!< Value representing GPIO 14.
    GPIO_15 = 15, //!< Value representing GPIO 15.
    GPIO_16 = 16, //!< Value representing GPIO 16.
    GPIO_17 = 17, //!< Value representing GPIO 17.
    GPIO_18 = 18, //!< Value representing GPIO 18.
    GPIO_19 = 19, //!< Value representing GPIO 19.
    GPIO_20 = 20, //!< Value representing GPIO 20.
    GPIO_21 = 21, //!< Value representing GPIO 21.
    GPIO_22 = 22, //!< Value representing GPIO 22.
    GPIO_23 = 23, //!< Value representing GPIO 23.
    GPIO_24 = 24, //!< Value representing GPIO 24.
    GPIO_25 = 25, //!< Value representing GPIO 25.
    GPIO_26 = 26, //!< Value representing GPIO 26.
    GPIO_27 = 27, //!< Value representing GPIO 27.
    GPIO_28 = 28, //!< Value representing GPIO 28.
    GPIO_29 = 29, //!< Value representing GPIO 29.
    GPIO_30 = 30, //!< Value representing GPIO 30.
    GPIO_31 = 31, //!< Value representing GPIO 31.
    GPIO_32 = 32, //!< Value representing GPIO 32.
    GPIO_33 = 33, //!< Value representing GPIO 33.
    GPIO_34 = 34, //!< Value representing GPIO 34.
    GPIO_35 = 35, //!< Value representing GPIO 35.
    GPIO_36 = 36, //!< Value representing GPIO 36.
    GPIO_37 = 37, //!< Value representing GPIO 37.
    GPIO_38 = 38, //!< Value representing GPIO 38.
    GPIO_39 = 39, //!< Value representing GPIO 39.
    GPIO_40 = 40, //!< Value representing GPIO 40.
    GPIO_41 = 41, //!< Value representing GPIO 41.
    GPIO_42 = 42, //!< Value representing GPIO 42.
    GPIO_43 = 43, //!< Value representing GPIO 43.
    GPIO_44 = 44, //!< Value representing GPIO 44.
    GPIO_45 = 45, //!< Value representing GPIO 45.
    GPIO_46 = 46, //!< Value representing GPIO 46.
    GPIO_47 = 47, //!< Value representing GPIO 47.
    GPIO_48 = 48, //!< Value representing GPIO 48.
    GPIO_49 = 49, //!< Value representing GPIO 49.
    GPIO_50 = 50, //!< Value representing GPIO 50.
    GPIO_51 = 51, //!< Value representing GPIO 51.
    GPIO_52 = 52, //!< Value representing GPIO 52.
    GPIO_53 = 53, //!< Value representing GPIO 53.
    GPIO_54 = 54, //!< Value representing GPIO 54.
    GPIO_55 = 55, //!< Value representing GPIO 55.
    GPIO_COUNT,
}GPIO_PIN_E;

#if defined(CONFIG_MACH_GK7101_FPGA)
#include "gpio_fpga.h"
#elif defined(CONFIG_MACH_GK7101_EVB)
#include "gpio_evb.h"
#elif defined(CONFIG_MACH_GK7101_EVB_V2_0)
#include "gpio_evb_new.h"
#elif defined(CONFIG_MACH_GK7102_RTOS_EVB_V1_0)
#include "gpio_rtos_evb.h"
#elif defined(CONFIG_MACH_GK7101_RB_V1_00) \
    || defined(CONFIG_MACH_GK7101_RB_V1_10)
#include "gpio_rb.h"
#elif defined(CONFIG_MACH_GK7101_RB_IMX222_V1_00)
#include "gpio_rb_imx222.h"
#elif defined(CONFIG_MACH_GK7101_RB_OV2710_V1_00) \
    || defined(CONFIG_MACH_GK7101_RB_OV2710_V2_00) \
    || defined(CONFIG_MACH_GK7101_RB_OV2710_V2_10) \
    || defined(CONFIG_MACH_GK7101_RB_OV2710_V2_20)
#include "gpio_rb_ov2710.h"
#elif defined(CONFIG_MACH_GK7101_RB_PS1210_V1_00)
#include "gpio_rb_ps1210.h"
#elif defined(CONFIG_MACH_GK7101_RB_AR0230_V1_00)
#include "gpio_rb_ar0230.h"
#elif defined(CONFIG_MACH_GK7102_RB_IMX225_V1_00)
#include "gpio_rb_imx225.h"
#elif defined(CONFIG_MACH_GK7102_RB_OV9750_V1_00)
#include "gpio_rb_ov9750.h"
#elif defined(CONFIG_MACH_GK7102_RB_OV9712_V1_00)
#include "gpio_rb_ov9712.h"
#elif defined(CONFIG_MACH_GK7102_RB_AR0130_V1_00)
#include "gpio_rb_ar0130.h"
#elif defined(CONFIG_MACH_GK7102_RB_JXH42_V1_00) \
    || defined(CONFIG_MACH_GK7102_RB_JXH42_V2_00)
#include "gpio_rb_jxh42.h"
#elif defined(CONFIG_MACH_GK7102_RB_BG0703_V1_00)
#include "gpio_rb_bg0703.h"
#elif defined(CONFIG_MACH_GK7102_RB_SC1035_V2_10)
#include "gpio_rb_sc1035.h"
#elif defined(CONFIG_MACH_GK7102_RB_SC1045_V2_00)
#include "gpio_rb_sc1045.h"
#elif defined(CONFIG_MACH_GK7102_AK_GC1024_V1_00)
#include "gpio_ak_gc1024.h"
#else
#error "Undefine gpio configure header file or no support. "
#endif

typedef struct gpio_info
{
	u32 gpio_id;
	u32 gpio_type;
}gpio_info_t;

/* ==========================================================================*/
struct gk7101_gpio_io_info {
    int gpio_id;
    int active_level;
    int active_delay;       //ms
};

extern void gk7101_gpio_config(int id, u32 func);
extern void gk7101_gpio_set(int id, int value);
extern int gk7101_gpio_get(int id);
extern int gk7101_set_gpio_output(struct gk7101_gpio_io_info *pinfo, u32 on);
extern u32 gk7101_get_gpio_input(struct gk7101_gpio_io_info *pinfo);
extern int gk7101_set_gpio_reset(struct gk7101_gpio_io_info *pinfo);
extern void gk7101_gpio_initialize(void);
extern void gk7101_phy_gpio_initialize(void);
extern void gk7101_gpio_set_incfg(u32 value, u32 gpioid);

#endif /* _GK7101_GPIO_H_ */
