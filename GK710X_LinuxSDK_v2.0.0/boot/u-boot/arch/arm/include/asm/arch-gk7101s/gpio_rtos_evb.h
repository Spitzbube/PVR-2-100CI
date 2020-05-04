#ifndef _GPIO_RTOS_EVB_H_
#define _GPIO_RTOS_EVB_H_

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
    { GPIO_40, GPIO_TYPE_INOUT_SD_DATA_2               }, \
    { GPIO_41, GPIO_TYPE_INOUT_SD_DATA_3               }, \
    { GPIO_42, GPIO_TYPE_INPUT                         }, \
    { GPIO_43, GPIO_TYPE_INOUT_SD_CMD                  }, \
    { GPIO_44, GPIO_TYPE_OUTPUT_SDIO_CLK               }, \
    { GPIO_45, GPIO_TYPE_INPUT_SD_CD_N                 }, \
    { GPIO_46, GPIO_TYPE_INOUT_SD_DATA_0               }, \
    { GPIO_47, GPIO_TYPE_INOUT_SD_DATA_1               },
#else
#define SYSTEM_GPIO_SD_TABLE                              \
    { GPIO_40, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_41, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_42, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_43, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_44, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_45, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_46, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_47, GPIO_TYPE_INPUT_0                       },
#endif

#define SYSTEM_GPIO_EXTPHY_TABLE                          \
    { GPIO_54, GPIO_TYPE_OUTPUT_EPHY_LED_3             }

#define SYSTEM_GPIO_INTPHY_TABLE                          \
    { GPIO_48, SYSTEM_GPIO_PHY_CLK              /*CLK*/}, \
    { GPIO_54, GPIO_TYPE_OUTPUT_EPHY_LED_3             }


//------------------------system gpio map---------------------------
#define SYSTEM_GPIO_XREF_TABLE                            \
    { GPIO_0 , GPIO_TYPE_OUTPUT_SF_CS0                 }, \
    { GPIO_1 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_2 , GPIO_TYPE_INPUT_0                      }, \
    { GPIO_3 , GPIO_TYPE_OUTPUT_0                      }, \
    { GPIO_4 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_5 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_6 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_7 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_8 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_9 , GPIO_TYPE_INPUT_0                       }, \
    { GPIO_10, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_11, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_12, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_13, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_14, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_15, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_16, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_17, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_18, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_19, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_20, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_21, GPIO_TYPE_INPUT_0			           }, \
    { GPIO_22, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_23, GPIO_TYPE_OUTPUT_1   /*Sensor pwdn*/    }, \
    { GPIO_24, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_25, GPIO_TYPE_INPUT_UART0_RX                }, \
    { GPIO_26, GPIO_TYPE_OUTPUT_UART0_TX               }, \
    { GPIO_27, GPIO_TYPE_OUTPUT_1      /*Sensor reset*/}, \
    { GPIO_28, GPIO_TYPE_INOUT_I2C_DATA         /*S D*/}, \
    { GPIO_29, GPIO_TYPE_INOUT_I2C_CLK          /*S C*/}, \
    { GPIO_30, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_31, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_32, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_33, GPIO_TYPE_OUTPUT_0                      }, \
    { GPIO_34, GPIO_TYPE_OUTPUT_0                      }, \
    { GPIO_35, GPIO_TYPE_OUTPUT_1                      }, \
    { GPIO_36, GPIO_TYPE_OUTPUT_1                      }, \
    { GPIO_37, GPIO_TYPE_INOUT_I2C_DATA2               }, \
    { GPIO_38, GPIO_TYPE_INOUT_I2C_CLK2                }, \
    { GPIO_39, GPIO_TYPE_INPUT_0                       }, \
    SYSTEM_GPIO_SD_TABLE\
    { GPIO_48, SYSTEM_GPIO_PHY_CLK                     }, \
    { GPIO_49, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_50, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_51, GPIO_TYPE_OUTPUT_1                      }, \
    { GPIO_52, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_53, GPIO_TYPE_INPUT_0                       }, \
    { GPIO_54, GPIO_TYPE_OUTPUT_EPHY_LED_3             }, \
    { GPIO_55, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_56, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_57, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_58, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_59, GPIO_TYPE_UNDEFINED                     }, \
    { GPIO_60, GPIO_TYPE_INPUT                         }, \
    { GPIO_61, GPIO_TYPE_INPUT                         }, \
    { GPIO_62, GPIO_TYPE_INPUT                         },

#define SYSTEM_GPIO_IR_LED_CTRL     GPIO_12		// not real pin
#define SYSTEM_GPIO_IR_CUT1         GPIO_10		
#define SYSTEM_GPIO_IR_CUT2         GPIO_9
#define SYSTEM_GPIO_SENSOR_RESET    GPIO_27
#define SYSTEM_GPIO_PHY_RESET       GPIO_32
#define SYSTEM_GPIO_PHY_SPEED_LED   GPIO_54

#define SYSTEM_GPIO_SPI0_EN0        GPIO_8		// not real pin
#define SYSTEM_GPIO_SPI1_EN0        GPIO_9		// not real pin
#define SYSTEM_GPIO_PWM0            GPIO_6  	// not real pin
#define SYSTEM_GPIO_PWM1            GPIO_17  	// not real pin
#define SYSTEM_GPIO_PWM2            GPIO_33   	// not real pin
#define SYSTEM_GPIO_PWM3            GPIO_34  	// not real pin
#define SYSTEM_GPIO_USB_HOST        GPIO_51 	// not real pin
#define SYSTEM_GPIO_SD_DETECT       GPIO_45
#define SYSTEM_GPIO_SD_POWER        GPIO_53 	// not real pin
#define SYSTEM_GPIO_PMU_CTL         GPIO_55 // not real pin

#endif /* _GPIO_RTOS_EVB_H_ */
