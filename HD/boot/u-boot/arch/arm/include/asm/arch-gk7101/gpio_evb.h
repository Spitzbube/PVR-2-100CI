#ifndef _GPIO_EVB_H_
#define _GPIO_EVB_H_

#ifdef CONFIG_PHY_USE_AO_MCLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_OUTPUT_AOMCLK
#endif
#ifdef CONFIG_PHY_USE_SD_CLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_OUTPUT_SDIO_CLK
#endif
#ifdef CONFIG_PHY_USE_EXTERN_CLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_INPUT
#endif

#ifdef CONFIG_SYSTEM_USE_EXTERN_I2S
#define SYSTEM_GPIO_I2S_TABLE                             \
    { GPIO_4 , GPIO_TYPE_INPUT_CLK_AU                  }, \
    { GPIO_5 , GPIO_TYPE_INPUT_I2S_WS                  }, \
    { GPIO_6 , GPIO_TYPE_INPUT_I2S_SI                  }, \
    { GPIO_7 , GPIO_TYPE_INPUT_I2S_CLK                 },
#else
#define SYSTEM_GPIO_I2S_TABLE                             \
    { GPIO_4 , GPIO_TYPE_OUTPUT_SPI1_SO                }, \
    { GPIO_5 , GPIO_TYPE_OUTPUT_SPI0_SO                }, \
    { GPIO_6 , GPIO_TYPE_OUTPUT_SPI1_SCLK              }, \
    { GPIO_7 , GPIO_TYPE_OUTPUT_PWM3_OUT               },
#endif

#ifdef CONFIG_SYSTEM_USE_SDCARD
#define SYSTEM_GPIO_SD_TABLE                              \
    { GPIO_40, GPIO_TYPE_INOUT_SD_DATA_3               }, \
    { GPIO_41, GPIO_TYPE_INPUT_SD_WP_N                 }, \
    { GPIO_42, GPIO_TYPE_INOUT_SD_DATA_0               }, \
    { GPIO_43, GPIO_TYPE_INOUT_SD_DATA_2               }, \
    { GPIO_44, GPIO_TYPE_INOUT_SD_DATA_1               }, \
    { GPIO_45, GPIO_TYPE_INPUT                         }, \
    { GPIO_46, GPIO_TYPE_OUTPUT_SDIO_CLK               }, \
    { GPIO_47, GPIO_TYPE_INPUT                         }, \
    { GPIO_48, GPIO_TYPE_INOUT_SD_CMD                  }, \
    { GPIO_49, GPIO_TYPE_OUTPUT_1            /*USB_PD*/}, \
    { GPIO_50, GPIO_TYPE_INPUT_SD_CD_N                 },
#else
#define SYSTEM_GPIO_SD_TABLE                              \
    { GPIO_40, GPIO_TYPE_OUTPUT_AHB_DAC_DR_9           }, \
    { GPIO_41, GPIO_TYPE_INPUT                         }, \
    { GPIO_42, GPIO_TYPE_OUTPUT_AHB_DAC_DR_6           }, \
    { GPIO_43, GPIO_TYPE_OUTPUT_AHB_DAC_DR_7           }, \
    { GPIO_44, GPIO_TYPE_OUTPUT_AHB_DAC_DR_8           }, \
    { GPIO_45, GPIO_TYPE_OUTPUT_AHB_DAC_DR_3           }, \
    { GPIO_46, GPIO_TYPE_OUTPUT_AHB_DAC_DR_4           }, \
    { GPIO_47, GPIO_TYPE_OUTPUT_AHB_DAC_DR_5           }, \
    { GPIO_48, GPIO_TYPE_OUTPUT_AHB_DAC_DR_0           }, \
    { GPIO_49, GPIO_TYPE_OUTPUT_AHB_DAC_DR_1           }, \
    { GPIO_50, GPIO_TYPE_OUTPUT_AHB_DAC_DR_2           },
#endif
#define SYSTEM_GPIO_EXTPHY_TABLE                          \
    { GPIO_18, GPIO_TYPE_INPUT_ENET_PHY_RXDV           }, \
    { GPIO_19, GPIO_TYPE_INPUT_ENET_PHY_RXER           }, \
    { GPIO_31, GPIO_TYPE_INPUT_ENET_PHY_RXD_1          }, \
    { GPIO_32, GPIO_TYPE_OUTPUT_AOMCLK                 }, \
    { GPIO_33, GPIO_TYPE_OUTPUT_1         /*ETH reset*/}, \
    { GPIO_34, GPIO_TYPE_OUTPUT_ENET_PHY_TXEN          }, \
    { GPIO_35, GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O        }, \
    { GPIO_36, GPIO_TYPE_INOUT_ETH_MDIO                }, \
    { GPIO_53, GPIO_TYPE_INPUT_ENET_PHY_RXD_0          }, \
    { GPIO_54, GPIO_TYPE_INPUT_ENET_PHY_RXD_2   /*CLK*/}

#define SYSTEM_GPIO_INTPHY_TABLE                          \
    { GPIO_18, GPIO_TYPE_OUTPUT_EPHY_LED_3             }, \
    { GPIO_19, GPIO_TYPE_OUTPUT_EPHY_LED_0             }, \
    { GPIO_31, GPIO_TYPE_INPUT                         }, \
    { GPIO_32, GPIO_TYPE_OUTPUT_AOMCLK                 }, \
    { GPIO_33, GPIO_TYPE_INPUT                         }, \
    { GPIO_34, GPIO_TYPE_INPUT                         }, \
    { GPIO_35, GPIO_TYPE_INPUT                         }, \
    { GPIO_36, GPIO_TYPE_INPUT                         }, \
    { GPIO_53, GPIO_TYPE_INPUT                         }, \
    { GPIO_54, GPIO_TYPE_INPUT                         }

//------------------------system gpio map---------------------------
#define SYSTEM_GPIO_XREF_TABLE                            \
    { GPIO_0 , GPIO_TYPE_OUTPUT_SF_CS0                 }, \
    { GPIO_1 , GPIO_TYPE_OUTPUT_SF_CS1                 }, \
    { GPIO_2 , GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1         }, \
    { GPIO_3 , GPIO_TYPE_OUTPUT_ENET_PHY_TXD_0         }, \
    SYSTEM_GPIO_I2S_TABLE \
    { GPIO_8 , GPIO_TYPE_OUTPUT_1       /* SPI0_HOLD */}, \
    { GPIO_9 , GPIO_TYPE_OUTPUT_PWM2_OUT               }, \
    { GPIO_10, GPIO_TYPE_OUTPUT_PWM1_OUT               }, \
    { GPIO_11, GPIO_TYPE_OUTPUT_SPI1_CS0               }, \
    { GPIO_12, GPIO_TYPE_OUTPUT_PWM0_OUT               }, \
    { GPIO_13, GPIO_TYPE_INPUT_SPI0_SI                 }, \
    { GPIO_14, GPIO_TYPE_INPUT_SPI1_SI                 }, \
    { GPIO_15, GPIO_TYPE_OUTPUT_1           /*SPI0_WP*/}, \
    { GPIO_16, GPIO_TYPE_OUTPUT_SPI0_CS0               }, \
    { GPIO_17, GPIO_TYPE_OUTPUT_SPI0_SCLK              }, \
    { GPIO_20, GPIO_TYPE_INPUT_UART0_RX                }, \
    { GPIO_21, GPIO_TYPE_OUTPUT_UART2_DTR_N/*RS485_RE*/}, \
    { GPIO_22, GPIO_TYPE_OUTPUT_UART0_TX               }, \
    { GPIO_23, GPIO_TYPE_OUTPUT_UART1_TX               }, \
    { GPIO_24, GPIO_TYPE_OUTPUT_UART2_TX               }, \
    { GPIO_25, GPIO_TYPE_INPUT_UART1_RX                }, \
    { GPIO_26, GPIO_TYPE_INPUT_UART2_RX                }, \
    { GPIO_27, GPIO_TYPE_OUTPUT_1      /*Sensor reset*/}, \
    { GPIO_28, GPIO_TYPE_INOUT_I2C_DATA         /*S D*/}, \
    { GPIO_29, GPIO_TYPE_INOUT_I2C_CLK          /*S C*/}, \
    { GPIO_30, GPIO_TYPE_OUTPUT_AO_DATA0               }, \
    { GPIO_37, GPIO_TYPE_OUTPUT_1            /*IR_CUT*/}, \
    { GPIO_38, GPIO_TYPE_INOUT_I2C_DATA2               }, \
    { GPIO_39, GPIO_TYPE_INOUT_I2C_CLK2                }, \
    SYSTEM_GPIO_SD_TABLE \
    { GPIO_51, GPIO_TYPE_OUTPUT_AOBCLK                 }, \
    { GPIO_52, GPIO_TYPE_OUTPUT_AOLRCLK                }, \
    { GPIO_55, GPIO_TYPE_INPUT                         }

#define SYSTEM_GPIO_IR_LED_CTRL     GPIO_12
#define SYSTEM_GPIO_IR_CUT1         GPIO_10
#define SYSTEM_GPIO_IR_CUT2         GPIO_9
#define SYSTEM_GPIO_SENSOR_RESET    GPIO_27
#define SYSTEM_GPIO_PHY_RESET       GPIO_33
#define SYSTEM_GPIO_PHY_SPEED_LED   GPIO_18

#define SYSTEM_GPIO_SPI0_EN0        GPIO_16
#define SYSTEM_GPIO_SPI1_EN0        GPIO_11
#define SYSTEM_GPIO_PWM0            GPIO_12
#define SYSTEM_GPIO_PWM1            GPIO_10
#define SYSTEM_GPIO_PWM2            GPIO_9
#define SYSTEM_GPIO_PWM3            GPIO_55 // not real pin
#define SYSTEM_GPIO_USB_HOST        GPIO_49
#define SYSTEM_GPIO_SD_DETECT       GPIO_50
#define SYSTEM_GPIO_SD_POWER        GPIO_55 // not real pin
#define SYSTEM_GPIO_PMU_CTL         GPIO_12 // not real pin, only for test
#endif /* _GPIO_EVB_H_ */

