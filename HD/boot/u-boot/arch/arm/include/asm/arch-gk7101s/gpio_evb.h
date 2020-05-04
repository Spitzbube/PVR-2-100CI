#ifndef _GPIO_EVB_H_
#define _GPIO_EVB_H_

#ifdef CONFIG_PHY_USE_AO_MCLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_OUTPUT_AOMCLK
#endif
#ifdef CONFIG_PHY_USE_SD_CLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_OUTPUT_SDIO_CLK
#endif
#ifdef CONFIG_PHY_USE_EXTERN_CLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_INPUT_0
#endif

#define SYSTEM_GPIO_SD_TABLE                              \
    { GPIO_39, GPIO_TYPE_OUTPUT_SDIO_CLK               }, \
    { GPIO_40, GPIO_TYPE_INOUT_SD_CMD |GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_41, GPIO_TYPE_INPUT_SD_CD_N|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_42, GPIO_TYPE_INPUT_SD_WP_N|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_43, GPIO_TYPE_INOUT_SD_DATA_0|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_44, GPIO_TYPE_INOUT_SD_DATA_1|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_45, GPIO_TYPE_INOUT_SD_DATA_2|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_46, GPIO_TYPE_INOUT_SD_DATA_3|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_47, GPIO_TYPE_INOUT_SD1_DATA_0|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_48, GPIO_TYPE_INOUT_SD1_DATA_1|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_49, GPIO_TYPE_INOUT_SD1_DATA_2|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_50, GPIO_TYPE_INOUT_SD1_DATA_3|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_51, GPIO_TYPE_OUTPUT_SDIO1_CLK              }, \
    { GPIO_52, GPIO_TYPE_INOUT_SD1_CMD |GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_53, GPIO_TYPE_INPUT_SD1_CD_N|GPIO_SET_IOCTRL(IOCTRL_4MA)}, \
    { GPIO_54, GPIO_TYPE_INPUT_SD1_WP_N|GPIO_SET_IOCTRL(IOCTRL_4MA)},

#define CONFIG_SYSTEM_VOUT

#ifdef CONFIG_SYSTEM_VOUT
#define SYSTEM_GPIO_IMAGE_TABLE                           \
    { GPIO_4 , GPIO_TYPE_OUTPUT_VD_DATA0               }, \
    { GPIO_5 , GPIO_TYPE_OUTPUT_VD_DATA1               }, \
    { GPIO_6 , GPIO_TYPE_OUTPUT_VD_DATA2               }, \
    { GPIO_7 , GPIO_TYPE_OUTPUT_VD_DATA3               }, \
    { GPIO_8 , GPIO_TYPE_OUTPUT_VD_DATA4               }, \
    { GPIO_9 , GPIO_TYPE_OUTPUT_VD_DATA5               }, \
    { GPIO_10, GPIO_TYPE_OUTPUT_VD_DATA6               }, \
    { GPIO_11, GPIO_TYPE_OUTPUT_VD_DATA7               }, \
    { GPIO_12, GPIO_TYPE_OUTPUT_VD_DATA8               }, \
    { GPIO_13, GPIO_TYPE_OUTPUT_VD_DATA9               }, \
    { GPIO_14, GPIO_TYPE_OUTPUT_VD_DATA10              }, \
    { GPIO_15, GPIO_TYPE_OUTPUT_VD_DATA11              }, \
    { GPIO_16, GPIO_TYPE_OUTPUT_VD_DATA12              }, \
    { GPIO_17, GPIO_TYPE_OUTPUT_VD_DATA13              }, \
    { GPIO_20, GPIO_TYPE_OUTPUT_VD_DATA14              }, \
    { GPIO_21, GPIO_TYPE_OUTPUT_VD_DATA15              }, \
    { GPIO_22, GPIO_TYPE_OUTPUT_VD_CLOCK               },
#else
#define SYSTEM_GPIO_IMAGE_TABLE                           \
    { GPIO_4 , GPIO_TYPE_INOUT_I80_DATA0               }, \
    { GPIO_5 , GPIO_TYPE_INOUT_I80_DATA1               }, \
    { GPIO_6 , GPIO_TYPE_INOUT_I80_DATA2               }, \
    { GPIO_7 , GPIO_TYPE_INOUT_I80_DATA3               }, \
    { GPIO_8 , GPIO_TYPE_INOUT_I80_DATA4               }, \
    { GPIO_9 , GPIO_TYPE_INOUT_I80_DATA5               }, \
    { GPIO_10, GPIO_TYPE_INOUT_I80_DATA6               }, \
    { GPIO_11, GPIO_TYPE_INOUT_I80_DATA7               }, \
    { GPIO_12, GPIO_TYPE_INOUT_I80_DATA8               }, \
    { GPIO_13, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_14, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_15, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_16, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_17, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_20, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_21, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_22, GPIO_TYPE_UNDEFINED                     },
#endif

#define SYSTEM_GPIO_EXTPHY_TABLE                          \
    { GPIO_2 , GPIO_TYPE_OUTPUT_EPHY_LED_3             }, \
    { GPIO_3 , GPIO_TYPE_OUTPUT_EPHY_LED_0             }
#define SYSTEM_GPIO_INTPHY_TABLE                          \
    { GPIO_2 , GPIO_TYPE_OUTPUT_EPHY_LED_3             }, \
    { GPIO_3 , GPIO_TYPE_OUTPUT_EPHY_LED_0             }

#define SYSTEM_GPIO_XREF_TABLE                            \
    { GPIO_0 , GPIO_TYPE_OUTPUT_SF_CS0                 }, \
    { GPIO_1 , GPIO_TYPE_OUTPUT_SF_CS1                 }, \
    { GPIO_18, GPIO_TYPE_UNDEFINED        /*IRCUT+*/   }, \
    { GPIO_19, GPIO_TYPE_UNDEFINED        /*IRCUT-*/   }, \
    SYSTEM_GPIO_IMAGE_TABLE                             \
    { GPIO_23, GPIO_TYPE_INPUT_UART1_RX                }, \
    { GPIO_24, GPIO_TYPE_OUTPUT_UART1_TX               }, \
    { GPIO_25, GPIO_TYPE_INPUT_UART0_RX                }, \
    { GPIO_26, GPIO_TYPE_OUTPUT_UART0_TX               }, \
    { GPIO_27, GPIO_TYPE_UNDEFINED    /*sensor RST*/    }, \
    { GPIO_28, GPIO_TYPE_INOUT_I2C_DATA    /*SDA*/     }, \
    { GPIO_29, GPIO_TYPE_INOUT_I2C_CLK    /*SCL*/      }, \
    { GPIO_30, GPIO_TYPE_OUTPUT_1     /*USB_PD*/       }, \
    { GPIO_31, GPIO_TYPE_OUTPUT_SPI1_SCLK              }, \
    { GPIO_32, GPIO_TYPE_OUTPUT_SPI1_CS0               }, \
    { GPIO_33, GPIO_TYPE_OUTPUT_SPI0_SCLK              }, \
    { GPIO_34, GPIO_TYPE_OUTPUT_SPI0_CS0               }, \
    { GPIO_35, GPIO_TYPE_OUTPUT_SPI0_SO                }, \
    { GPIO_36, GPIO_TYPE_INPUT_SPI0_SI                 }, \
    { GPIO_37, GPIO_TYPE_INOUT_I2C_CLK2    /*SCL*/     }, \
    { GPIO_38, GPIO_TYPE_INOUT_I2C_DATA2   /*SDA*/     }, \
    SYSTEM_GPIO_SD_TABLE                                 \
    { GPIO_55, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_56, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_57, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_58, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_59, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_60, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_61, GPIO_TYPE_UNDEFINED     /*sensor bit11*/  }, \
    { GPIO_62, GPIO_TYPE_UNDEFINED     /*sensor bit12*/  }


#define SYSTEM_GPIO_IR_LED_CTRL     GPIO_COUNT
#define SYSTEM_GPIO_IR_CUT1         GPIO_18
#define SYSTEM_GPIO_IR_CUT2         GPIO_19
#define SYSTEM_GPIO_SENSOR_RESET    GPIO_27
#define SYSTEM_GPIO_PHY_RESET       GPIO_COUNT
#define SYSTEM_GPIO_PHY_SPEED_LED   GPIO_COUNT

#define SYSTEM_GPIO_SPI0_EN0        GPIO_35
#define SYSTEM_GPIO_SPI1_EN0        GPIO_32
#define SYSTEM_GPIO_PWM0            GPIO_COUNT
#define SYSTEM_GPIO_PWM1            GPIO_COUNT
#define SYSTEM_GPIO_PWM2            GPIO_COUNT
#define SYSTEM_GPIO_PWM3            GPIO_COUNT // not real pin
#define SYSTEM_GPIO_USB_HOST        GPIO_30
#define SYSTEM_GPIO_SD_DETECT       GPIO_41
#define SYSTEM_GPIO_SD_POWER        GPIO_COUNT // not real pin
#define SYSTEM_GPIO_SD1_DETECT      GPIO_53
#define SYSTEM_GPIO_SD1_POWER       GPIO_COUNT // not real pin
#define SYSTEM_GPIO_PMU_CTL         GPIO_COUNT // not real pin, only for test
#endif /* _GPIO_EVB_H_ */
