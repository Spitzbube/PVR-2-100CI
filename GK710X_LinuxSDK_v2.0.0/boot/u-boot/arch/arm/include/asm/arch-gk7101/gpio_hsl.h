#ifndef _GPIO_HSL_H_
#define _GPIO_HSL_H_

#ifdef CONFIG_PHY_USE_AO_MCLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_OUTPUT_AOMCLK
#endif
#ifdef CONFIG_PHY_USE_SD_CLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_OUTPUT_SDIO_CLK
#endif
#ifdef CONFIG_PHY_USE_EXTERN_CLK
    #define SYSTEM_GPIO_PHY_CLK     GPIO_TYPE_INPUT
#endif

#ifdef CONFIG_MACH_GK7101_HSL_E681XA4_V1_20
#define SYSTEM_GPIO_EXTPHY_TABLE                          \
    { GPIO_18, GPIO_TYPE_INPUT                         }, \
    { GPIO_19, GPIO_TYPE_INPUT                         }, \
    { GPIO_31, GPIO_TYPE_INPUT                         },

#define SYSTEM_GPIO_INTPHY_TABLE                          \
    { GPIO_18, GPIO_TYPE_OUTPUT_EPHY_LED_3             }, \
    { GPIO_19, GPIO_TYPE_OUTPUT_EPHY_LED_0             }, \
    { GPIO_31, SYSTEM_GPIO_PHY_CLK                     },

//------------------------system gpio map---------------------------
#define SYSTEM_GPIO_XREF_TABLE                            \
    { GPIO_0 , GPIO_TYPE_OUTPUT_SF_CS0                 }, \
    { GPIO_1 , GPIO_TYPE_OUTPUT_SF_CS1                 }, \
    { GPIO_2 , GPIO_TYPE_INPUT                         }, \
    { GPIO_3 , GPIO_TYPE_INPUT                         }, \
    { GPIO_4 , GPIO_TYPE_INPUT                         }, \
    { GPIO_5 , GPIO_TYPE_INPUT                         }, \
    { GPIO_6 , GPIO_TYPE_INPUT                   /*T3*/}, \
    { GPIO_7 , GPIO_TYPE_INPUT                   /*T4*/}, \
    { GPIO_8 , GPIO_TYPE_INPUT                   /*T1*/}, \
    { GPIO_9 , GPIO_TYPE_INPUT                   /*T2*/}, \
    { GPIO_10, GPIO_TYPE_INPUT                   /*P4*/}, \
    { GPIO_11, GPIO_TYPE_INPUT                   /*P3*/}, \
    { GPIO_12, GPIO_TYPE_INPUT                   /*P1*/}, \
    { GPIO_13, GPIO_TYPE_INPUT                   /*P2*/}, \
    { GPIO_14, GPIO_TYPE_INPUT                         }, \
    { GPIO_15, GPIO_TYPE_INPUT                         }, \
    { GPIO_16, GPIO_TYPE_INPUT                         }, \
    { GPIO_17, GPIO_TYPE_INPUT                         }, \
    { GPIO_20, GPIO_TYPE_INPUT_UART0_RX                }, \
    { GPIO_21, GPIO_TYPE_INPUT                         }, \
    { GPIO_22, GPIO_TYPE_OUTPUT_UART0_TX               }, \
    { GPIO_23, GPIO_TYPE_OUTPUT_UART1_TX               }, \
    { GPIO_24, GPIO_TYPE_OUTPUT_UART2_TX               }, \
    { GPIO_25, GPIO_TYPE_INPUT_UART1_RX                }, \
    { GPIO_26, GPIO_TYPE_INPUT_UART2_RX                }, \
    { GPIO_27, GPIO_TYPE_OUTPUT_1      /*Sensor reset*/}, \
    { GPIO_28, GPIO_TYPE_INOUT_I2C_DATA         /*S D*/}, \
    { GPIO_29, GPIO_TYPE_INOUT_I2C_CLK          /*S C*/}, \
    { GPIO_30, GPIO_TYPE_INOUT_I2C_DATA2               }, \
    { GPIO_32, GPIO_TYPE_INOUT_I2C_CLK2                }, \
    { GPIO_33, GPIO_TYPE_INPUT                         }, \
    { GPIO_34, GPIO_TYPE_INPUT                         }, \
    { GPIO_35, GPIO_TYPE_INPUT             /*ALARM_IN*/}, \
    { GPIO_36, GPIO_TYPE_INPUT            /*ALARM_OUT*/}, \
    { GPIO_37, GPIO_TYPE_INPUT           /*IR_DET_ADC*/}, \
    { GPIO_38, GPIO_TYPE_OUTPUT_0           /*IR_CUT+*/}, \
    { GPIO_39, GPIO_TYPE_OUTPUT_0           /*IR_CUT-*/}, \
    { GPIO_40, GPIO_TYPE_INOUT_SD_DATA_3               }, \
    { GPIO_41, GPIO_TYPE_INPUT_SD_WP_N                 }, \
    { GPIO_42, GPIO_TYPE_INOUT_SD_DATA_0               }, \
    { GPIO_43, GPIO_TYPE_INOUT_SD_DATA_2               }, \
    { GPIO_44, GPIO_TYPE_INOUT_SD_DATA_1               }, \
    { GPIO_45, GPIO_TYPE_INPUT           /*STATUS_LED*/}, \
    { GPIO_46, GPIO_TYPE_OUTPUT_SDIO_CLK               }, \
    { GPIO_47, GPIO_TYPE_OUTPUT_1/*SDIO_CARD_POWER_EN*/}, \
    { GPIO_48, GPIO_TYPE_INOUT_SD_CMD                  }, \
    { GPIO_49, GPIO_TYPE_INPUT                         }, \
    { GPIO_50, GPIO_TYPE_INPUT_SD_CD_N                 }, \
    { GPIO_51, GPIO_TYPE_INPUT                         }, \
    { GPIO_52, GPIO_TYPE_INPUT                         }, \
    { GPIO_53, GPIO_TYPE_INPUT                         }, \
    { GPIO_54, GPIO_TYPE_INPUT                         }, \
    { GPIO_55, GPIO_TYPE_INPUT                         }

#define SYSTEM_GPIO_IR_LED_CTRL     GPIO_37
#define SYSTEM_GPIO_IR_CUT1         GPIO_38
#define SYSTEM_GPIO_IR_CUT2         GPIO_39
#define SYSTEM_GPIO_SENSOR_RESET    GPIO_27
#define SYSTEM_GPIO_PHY_RESET       GPIO_14 // not real pin
#define SYSTEM_GPIO_PHY_SPEED_LED   GPIO_18

#define SYSTEM_GPIO_SPI0_EN0        GPIO_51 // not real pin
#define SYSTEM_GPIO_SPI1_EN0        GPIO_52 // not real pin
#define SYSTEM_GPIO_PWM0            GPIO_53 // not real pin
#define SYSTEM_GPIO_PWM1            GPIO_54 // not real pin
#define SYSTEM_GPIO_PWM2            GPIO_15 // not real pin
#define SYSTEM_GPIO_PWM3            GPIO_16 // not real pin
#define SYSTEM_GPIO_USB_HOST        GPIO_17 // not real pin
#define SYSTEM_GPIO_SD_DETECT       GPIO_50
#define SYSTEM_GPIO_SD_POWER        GPIO_47
#define SYSTEM_GPIO_PMU_CTL         GPIO_55 // not real pin
#endif

#endif /* _GPIO_HSL_H_ */
