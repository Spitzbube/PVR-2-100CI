#ifndef _GK7101_GPIO_FPGA_H_
#define _GK7101_GPIO_FPGA_H_

#define SYSTEM_GPIO_XREF_TABLE                       \
    { GPIO_0 , GPIO_TYPE_OUTPUT_SF_CS0            }, \
    { GPIO_1 , GPIO_TYPE_OUTPUT_SF_CS1            }, \
    { GPIO_2 , GPIO_TYPE_INPUT_ENET_PHY_RXD_0     }, \
    { GPIO_3 , GPIO_TYPE_INPUT_ENET_PHY_RXD_1     }, \
    { GPIO_4 , GPIO_TYPE_OUTPUT_PWM0_OUT          }, \
    { GPIO_5 , GPIO_TYPE_UNDEFINED     /*U28 C*/  }, \
    { GPIO_6 , GPIO_TYPE_INPUT_UART0_RX           }, \
    { GPIO_7 , GPIO_TYPE_OUTPUT_UART0_TX          }, \
    { GPIO_8 , GPIO_TYPE_OUTPUT_UART2_DTR_N       }, \
    { GPIO_9 , GPIO_TYPE_INPUT_UART2_RX           }, \
    { GPIO_10, GPIO_TYPE_OUTPUT_UART2_TX          }, \
    { GPIO_11, GPIO_TYPE_UNDEFINED     /*U28 D*/  }, \
    { GPIO_12, GPIO_TYPE_INPUT_ENET_PHY_RXD_2     }, \
    { GPIO_13, GPIO_TYPE_INPUT_I2S_CLK            }, \
    { GPIO_14, GPIO_TYPE_INPUT_CLK_AU             }, \
    { GPIO_15, GPIO_TYPE_INPUT_I2S_WS             }, \
    { GPIO_16, GPIO_TYPE_INPUT_I2S_SI             }, \
    { GPIO_17, GPIO_TYPE_INPUT_ENET_PHY_RXD_3     }, \
    { GPIO_18, GPIO_TYPE_INPUT_ENET_CLK_TX        }, \
    { GPIO_19, GPIO_TYPE_INPUT_ENET_CLK_RX        }, \
    { GPIO_20, GPIO_TYPE_OUTPUT_ENET_PHY_TXD_0    }, \
    { GPIO_21, GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1    }, \
    { GPIO_22, GPIO_TYPE_OUTPUT_ENET_PHY_TXD_2    }, \
    { GPIO_23, GPIO_TYPE_OUTPUT_ENET_PHY_TXD_3    }, \
    { GPIO_24, GPIO_TYPE_OUTPUT_ENET_PHY_TXEN     }, \
    { GPIO_25, GPIO_TYPE_OUTPUT_1 /*ETH reset*/   }, \
    { GPIO_26, GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O   }, \
    { GPIO_27, GPIO_TYPE_OUTPUT_1 /*Sensor reset*/}, \
    { GPIO_28, GPIO_TYPE_INOUT_I2C_DATA /*S D*/   }, \
    { GPIO_29, GPIO_TYPE_INOUT_I2C_CLK  /*S C*/   }, \
    { GPIO_30, GPIO_TYPE_INOUT_ETH_MDIO           }, \
    { GPIO_31, GPIO_TYPE_INPUT_ENET_PHY_CRS       }, \
    { GPIO_32, GPIO_TYPE_INPUT_ENET_PHY_RXER      }, \
    { GPIO_33, GPIO_TYPE_OUTPUT_SPI0_SCLK         }, \
    { GPIO_34, GPIO_TYPE_OUTPUT_SPI0_CS0          }, \
    { GPIO_35, GPIO_TYPE_OUTPUT_SPI0_SO           }, \
    { GPIO_36, GPIO_TYPE_INPUT_SPI0_SI            }, \
    { GPIO_37, GPIO_TYPE_INPUT_ENET_PHY_RXDV      }, \
    { GPIO_38, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_39, GPIO_TYPE_OUTPUT_SDIO_CLK          }, \
    { GPIO_40, GPIO_TYPE_INOUT_SD_CMD             }, \
    { GPIO_41, GPIO_TYPE_INPUT_SD_CD_N            }, \
    { GPIO_42, GPIO_TYPE_INPUT_SD_WP_N            }, \
    { GPIO_43, GPIO_TYPE_INOUT_SD_DATA_0          }, \
    { GPIO_44, GPIO_TYPE_INOUT_SD_DATA_1          }, \
    { GPIO_45, GPIO_TYPE_INOUT_SD_DATA_2          }, \
    { GPIO_46, GPIO_TYPE_INOUT_SD_DATA_3          }, \
    { GPIO_47, GPIO_TYPE_OUTPUT_AOBCLK            }, \
    { GPIO_48, GPIO_TYPE_OUTPUT_AOLRCLK           }, \
    { GPIO_49, GPIO_TYPE_OUTPUT_AOMCLK            }, \
    { GPIO_50, GPIO_TYPE_OUTPUT_AO_DATA0          }, \
    { GPIO_51, GPIO_TYPE_OUTPUT_1         /*HOLD*/}, \
    { GPIO_52, GPIO_TYPE_OUTPUT_1         /*WP*/  }, \
    { GPIO_53, GPIO_TYPE_INOUT_I2C_CLK2 /*U27 C*/ }, \
    { GPIO_54, GPIO_TYPE_INOUT_I2C_DATA2/*U27 D*/ }, \
    { GPIO_55, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_56, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_57, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_58, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_59, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_60, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_61, GPIO_TYPE_UNDEFINED                }, \
    { GPIO_62, GPIO_TYPE_UNDEFINED                }

#define SYSTEM_GPIO_PHY_RESET       GPIO_25

#endif