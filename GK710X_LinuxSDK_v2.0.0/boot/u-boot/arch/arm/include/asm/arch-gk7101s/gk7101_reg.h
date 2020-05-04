#ifndef _GK7101S_REG_H_
#define _GK7101S_REG_H_

//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************
typedef union { /* PLL_IOCTRL_GPIO */
    unsigned long all;
    struct {
        unsigned long io1                         : 6;
        unsigned long                             : 2;
        unsigned long io2                         : 6;
        unsigned long                             : 2;
        unsigned long io0                         : 6;
        unsigned long                             : 2;
        unsigned long io3                         : 6;
        unsigned long                             : 2;
    } bitc;
} PLL_IOCTRL_GPIO_S;

#define REG_GPIO_BASE                                       0xA0009000
#define REG_GPIO_IN_EN                                      0xA0009038
#define REG_GPIO_30_INPUT_CFG                               0xA0009278

#define REG_TIMER_CNTNSTS                                   0xA0000000
#define REG_TIMER_RELOADN                                   0xA0000030
#define REG_TIMER_MATCH1                                    0xA0000004
#define REG_TIMER_MATCH2                                    0xA0000008
#define REG_TIMER_CONTROL                                   0xA000000C

#define REG_WDT_CTRL                                        0xA0006000
#define REG_WDT_RELOAD                                      0xA0006010
#define REG_WDT_RESTART                                     0xA0006014

#define REG_PLL_CORE_CTRL                                   0xA0170014
#define REG_PLL_CORE_FRAC                                   0xA017001C
#define REG_PLL_CORE_CTRL_REG2                              0xA0170108
#define REG_PLL_SCALER_SD48_REG                             0xA0170018
#define REG_PLL_AUDIO_CTRL                                  0xA0170024
#define REG_PLL_AUDIOO_FRAC                                 0xA0170078
#define REG_PLL_DIV_AUDIO_PST                               0xA0170084
#define REG_PLL_DIV_AUDIO_PRE                               0xA0170080

#define REG_PLL_IOCTRL_MISC2                                0xA0170198
#define REG_PLL_IOCTRL_GPIO                                 0xA0170230
#define REG_PLL_SCALER_UART                                 0xA0170028

#define REG_ETH_MAC_CONFIG                                  0x9000E000
#define REG_EPHY_AHB_GENNERNAL0                             0x90020E00
#define REG_EPHY_CONTROL                                    0x90022000
#define REG_EPHY_SPEED_SEL                                  0x90022058
#define REG_EPHY_MUX_SEL                                    0x900220C8
#define REG_EPHY_SIGNAL_SEL                                 0x900220E0
#define REG_EPHY_MDIIO_ERR_CNT_CLEAR                        0x90022540
#define REG_EPHY_CLK_200                                    0x90022588

#define REG_SFLASH_DATA                                     0x90016000
#define REG_SFLASH_COMMAND                                  0x90016004
#define REG_SFLASH_CE                                       0x90016008
#define REG_SFLASH_SPEED                                    0x9001600C

#define REG_UART0_BASE                                      0xA0005000
#define REG_RECEVIE_BUFFER                                  0xA0005004
#define REG_INTERRUPT_IDENTITY                              0xA0005008

#define REG_SDIO_ADDRR                                      0x90000000
#define REG_SDIO_MOD                                        0x90000004
#define REG_SDIO_NOR_INT_SIG_EN                             0x90000006
#define REG_SDIO_ERR_INT_SIG_EN                             0x90000008
#define REG_SDIO_BLK_COU                                    0x9000000A
#define REG_SDIO_BLK_SIZ                                    0x9000000C
#define REG_SDIO_NOR_INT_STA_EN                             0x9000000E
#define REG_SDIO_ERR_INT_STA_EN                             0x90000010
#define REG_SDIO_NOR_INT_STA                                0x90000012
#define REG_SDIO_ERR_INT_STA                                0x90000014
#define REG_SDIO_SFRST_CONTROL                              0x90000018
#define REG_SDIO_CLK_CONTROL                                0x9000001A
#define REG_SDIO_RESP0REG                                   0x9000001C 
#define REG_SDIO_RESP1REG                                   0x90000020 
#define REG_SDIO_RESP2REG                                   0x90000024 
#define REG_SDIO_RESP3REG                                   0x90000028
#define REG_SDIO_CONTROL00REG                               0x9000002C
#define REG_SDIO_PRESENTSTATEREG                            0x90000030
#define REG_SDIO_ARGU                                       0x90000034
#define REG_SDIO_CAPREG                                     0x90000038
#define REG_SDIO_AUTOCMD12ERRSTATUSREG                      0x9000003c
#define REG_SDIO_BUFFERDATAPORTREG                          0x90000040

#define REG_SDIO_SYSADDRREG                                 0x90000000 
#define REG_SDIO_COMM                                       0x90000016 
#define REG_SDIO_SF_RST_CTRL                                0x90000018 
#define REG_SDIO_CLK_CTRL                                   0x9000001A 
#define REG_SDIO_ARGREG                                     0x90000034

#define REG_VIC_IRQSTS                                      0x90008030
#define REG_VIC_FIQSTS                                      0x90008034
#define REG_VIC_RAWSTS                                      0x90008018
#define REG_VIC_SELECT                                      0x9000800C
#define REG_VIC_ENABLE                                      0x90008010
#define REG_VIC_ENCLR                                       0x90008014
#define REG_VIC_SOFTINT                                     0x9000801c
#define REG_VIC_SOFTINTRCLR                                 0x90008020
#define REG_VIC_PROTECT                                     0x90008024
#define REG_VIC_SENSE                                       0x90008000
#define REG_VIC_BOTHEDGE                                    0x90008008
#define REG_VIC_EVENT                                       0x90008004
#define REG_VIC_EDGECLR                                     0x90008038

#endif /* _GK7101S_REG_H_ */
