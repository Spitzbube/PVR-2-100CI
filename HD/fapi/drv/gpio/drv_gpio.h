#ifndef DRV_GPIO_H_
#define DRV_GPIO_H_


    #define FAPI_GPIO_OUT_OFFSET          0x0080                          //!< offset for output functions
    #define FAPI_GPIO_IN_OFFSET           0x0100                          //!< offset for input functions
    #define FAPI_GPIO_BIDI_OFFSET         0x0180                          //!< offset for bidi functions
    #define FAPI_GPIO_UNDEFINED           0xFF                            //!< undefined value
    #define FAPI_GPIO_RESERVED_39         FAPI_GPIO_UNDEFINED             //!< reserved boot pin #39 (master select)
    #define FAPI_GPIO_RESERVED_41         FAPI_GPIO_UNDEFINED             //!< reserved boot pin #41 (sflash boot enable)

    #define FAPI_GPIO_OUT_0               (0 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: value = 0
    #define FAPI_GPIO_OUT_1               (1 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: value = 1
    #define FAPI_GPIO_OUT_SYSTEM_PWM      (3 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: System PulseWidthModulation
    #define FAPI_GPIO_OUT_FD1_CLK         (4 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: FractionalDivider clock
    #define FAPI_GPIO_OUT_FPC_CLK         (5 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC clock
    #define FAPI_GPIO_OUT_FPC_DATA        (6 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC cata
    #define FAPI_GPIO_OUT_FPC_STROBE      (7 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC strobe
    #define FAPI_GPIO_OUT_FPC_SEG_0       (8 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC segment#0
    #define FAPI_GPIO_OUT_FPC_SEG_1       (9 +FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC segment#1
    #define FAPI_GPIO_OUT_FPC_SEG_2       (10+FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC segment#2
    #define FAPI_GPIO_OUT_FPC_SEG_3       (11+FAPI_GPIO_OUT_OFFSET)       //!< Output function: (serial) FPC segment#3
    #define FAPI_GPIO_OUT_AD0_DATA        (12+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO data
    #define FAPI_GPIO_OUT_AD0_LRCLK       (13+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO left/right clock
    #define FAPI_GPIO_OUT_AD0_BCLK        (14+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO Byte clock
    #define FAPI_GPIO_OUT_AD0_CLK         (15+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO clock output
    #define FAPI_GPIO_OUT_SPDIF_OUT       (16+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SPDIF output
    #define FAPI_GPIO_OUT_ICC1_VPEN       (17+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#1 VP enable
    #define FAPI_GPIO_OUT_ICC1_VCC        (18+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#1 VCC
    #define FAPI_GPIO_OUT_ICC1_RST        (19+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#1 reset
    #define FAPI_GPIO_OUT_ICC1_DATA       (20+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#1 data
    #define FAPI_GPIO_OUT_ICC1_CLK        (21+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#1 clock
    #define FAPI_GPIO_OUT_UART0_RTS       (22+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UART0 ready-to-send
    #define FAPI_GPIO_OUT_UART0_DATA      (23+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UART0 transmission data
    #define FAPI_GPIO_OUT_I2C0_DATA       (24+FAPI_GPIO_OUT_OFFSET)       //!< Output function: I2C data
    #define FAPI_GPIO_OUT_I2C0_CLK        (25+FAPI_GPIO_OUT_OFFSET)       //!< Output function: I2C clock
    #define FAPI_GPIO_OUT_ICC0_VPEN       (26+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#0 VP enable
    #define FAPI_GPIO_OUT_ICC0_VCC        (27+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#0 VCC
    #define FAPI_GPIO_OUT_ICC0_RST        (28+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#0 reset
    #define FAPI_GPIO_OUT_ICC0_DATA       (29+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#0 data
    #define FAPI_GPIO_OUT_ICC0_CLK        (30+FAPI_GPIO_OUT_OFFSET)       //!< Output function: ICC#0 clock
    #define FAPI_GPIO_OUT_CCIR_DATA_0     (31+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#0
    #define FAPI_GPIO_OUT_CCIR_DATA_1     (32+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#1
    #define FAPI_GPIO_OUT_CCIR_DATA_2     (33+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#2
    #define FAPI_GPIO_OUT_CCIR_DATA_3     (34+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#3
    #define FAPI_GPIO_OUT_CCIR_DATA_4     (35+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#4
    #define FAPI_GPIO_OUT_CCIR_DATA_5     (36+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#5
    #define FAPI_GPIO_OUT_CCIR_DATA_6     (37+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#6
    #define FAPI_GPIO_OUT_CCIR_DATA_7     (38+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output data bit#7
    #define FAPI_GPIO_OUT_CCIR_CLK        (39+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR output clock
    #define FAPI_GPIO_OUT_CCIR_VSYNC      (40+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR vertical sync
    #define FAPI_GPIO_OUT_CCIR_HSYNC      (41+FAPI_GPIO_OUT_OFFSET)       //!< Output function: CCIR horizontal sync
    #define FAPI_GPIO_OUT_LCD_CLK         (42+FAPI_GPIO_OUT_OFFSET)       //!< Output function: LCD clock
    #define FAPI_GPIO_OUT_UART1_RTS       (43+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UART1 RTS signal
    #define FAPI_GPIO_OUT_UART1_DATA      (44+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UART1 TX data
    #define FAPI_GPIO_OUT_SSP0_CLK        (45+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP clock
    #define FAPI_GPIO_OUT_SSP0_FFS        (46+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP ffs
    #define FAPI_GPIO_OUT_SSP0_OE         (47+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP oe
    #define FAPI_GPIO_OUT_SSP0_DATA       (48+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP TX data
    #define FAPI_GPIO_OUT_SFLASH_HOLD     (49+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SFLASH hold
    #define FAPI_GPIO_OUT_SFLASH_CS       (50+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SFLASH_chip select
    #define FAPI_GPIO_OUT_SFLASH_CLK      (51+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SFLASH_clock
    #define FAPI_GPIO_OUT_SFLASH_DATA     (52+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SFLASH data
    #define FAPI_GPIO_OUT_AD1_DATA        (53+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO data
    #define FAPI_GPIO_OUT_AD1_LRCLK       (54+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO left/right clock
    #define FAPI_GPIO_OUT_AD1_BCLK        (55+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO Byte clock
    #define FAPI_GPIO_OUT_AD1_CLK         (56+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO clock output
    #define FAPI_GPIO_OUT_AD2_DATA        (57+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO data
    #define FAPI_GPIO_OUT_AD2_LRCLK       (58+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO left/right clock
    #define FAPI_GPIO_OUT_AD2_BCLK        (59+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO Byte clock
    #define FAPI_GPIO_OUT_AD2_CLK         (60+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO clock output
    #define FAPI_GPIO_OUT_AD3_DATA        (61+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO data
    #define FAPI_GPIO_OUT_AD3_LRCLK       (62+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO left/right clock
    #define FAPI_GPIO_OUT_AD3_BCLK        (63+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO Byte clock
    #define FAPI_GPIO_OUT_AD3_CLK         (64+FAPI_GPIO_OUT_OFFSET)       //!< Output function: AO clock output
    #define FAPI_GPIO_OUT_I2C1_DATA       (65+FAPI_GPIO_OUT_OFFSET)       //!< Output function: I2C data
    #define FAPI_GPIO_OUT_I2C1_CLK        (66+FAPI_GPIO_OUT_OFFSET)       //!< Output function: I2C clock
    #define FAPI_GPIO_OUT_SSP1_CLK        (67+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP clock
    #define FAPI_GPIO_OUT_SSP1_FFS        (68+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP ffs
    #define FAPI_GPIO_OUT_SSP1_OE         (69+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP oe
    #define FAPI_GPIO_OUT_SSP1_DATA       (70+FAPI_GPIO_OUT_OFFSET)       //!< Output function: SSP TX data
    #define FAPI_GPIO_OUT_TS_CLK          (71+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS clock input
    #define FAPI_GPIO_OUT_TS_PSTART       (72+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS packet start
    #define FAPI_GPIO_OUT_TS_EN           (73+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS enable
    #define FAPI_GPIO_OUT_TS_DATA_0       (74+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#0
    #define FAPI_GPIO_OUT_TS_DATA_1       (75+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#1
    #define FAPI_GPIO_OUT_TS_DATA_2       (76+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#2
    #define FAPI_GPIO_OUT_TS_DATA_3       (77+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#3
    #define FAPI_GPIO_OUT_TS_DATA_4       (78+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#4
    #define FAPI_GPIO_OUT_TS_DATA_5       (79+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#5
    #define FAPI_GPIO_OUT_TS_DATA_6       (80+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#6
    #define FAPI_GPIO_OUT_TS_DATA_7       (81+FAPI_GPIO_OUT_OFFSET)       //!< Output function: TS data bit#7
    #define FAPI_GPIO_OUT_HD_DE           (82+FAPI_GPIO_OUT_OFFSET)       //!< Output function: HD DE
    #define FAPI_GPIO_OUT_HD_VSYNC        (83+FAPI_GPIO_OUT_OFFSET)       //!< Output function: HD VSYNC
    #define FAPI_GPIO_OUT_HD_HSYNC        (84+FAPI_GPIO_OUT_OFFSET)       //!< Output function: HD HSYNC
    #define FAPI_GPIO_OUT_FD3_CLK         (85+FAPI_GPIO_OUT_OFFSET)       //!< Output function: FD3 CLK
    #define FAPI_GPIO_OUT_UPI_ADDRX0      (86+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UPI ADDRX0
    #define FAPI_GPIO_OUT_UPI_ADDRX1      (87+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UPI ADDRX1
    #define FAPI_GPIO_OUT_UPI_ADDRX2      (88+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UPI ADDRX2
    #define FAPI_GPIO_OUT_UPI_ADDRX3      (89+FAPI_GPIO_OUT_OFFSET)       //!< Output function: UPI ADDRX3

    #define FAPI_GPIO_IN_SSP0_DATA        (1 +FAPI_GPIO_IN_OFFSET)        //!< Input function: SFLASH data input
    #define FAPI_GPIO_IN_SFLASH_DATA      (2 +FAPI_GPIO_IN_OFFSET)        //!< Input function: SFLASH data input
    #define FAPI_GPIO_IN_CCIR_DATA_0      (3 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#0
    #define FAPI_GPIO_IN_CCIR_DATA_1      (4 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#1
    #define FAPI_GPIO_IN_CCIR_DATA_2      (5 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#2
    #define FAPI_GPIO_IN_CCIR_DATA_3      (6 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#3
    #define FAPI_GPIO_IN_CCIR_DATA_4      (7 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#4
    #define FAPI_GPIO_IN_CCIR_DATA_5      (8 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#5
    #define FAPI_GPIO_IN_CCIR_DATA_6      (9 +FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#6
    #define FAPI_GPIO_IN_CCIR_DATA_7      (10+FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input data bit#7
    #define FAPI_GPIO_IN_CCIR_CLK         (11+FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR input CLOCK
    #define FAPI_GPIO_IN_CCIR_EXT_EN      (12+FAPI_GPIO_IN_OFFSET)        //!< Input function: CCIR enable external CCIR input
    #define FAPI_GPIO_IN_IR_DATA          (13+FAPI_GPIO_IN_OFFSET)        //!< Input function: IR input data
    #define FAPI_GPIO_IN_I2C0_DATA        (14+FAPI_GPIO_IN_OFFSET)        //!< Input function: I2C data
    #define FAPI_GPIO_IN_I2C0_CLK         (15+FAPI_GPIO_IN_OFFSET)        //!< Input function: I2C clock
    #define FAPI_GPIO_IN_ICC1_DATA        (16+FAPI_GPIO_IN_OFFSET)        //!< Input function: ICC#1 data
    #define FAPI_GPIO_IN_ICC1_IN          (17+FAPI_GPIO_IN_OFFSET)        //!< Input function: ICC#1 card detection
    #define FAPI_GPIO_IN_ICC0_DATA        (18+FAPI_GPIO_IN_OFFSET)        //!< Input function: ICC#0 data
    #define FAPI_GPIO_IN_ICC0_IN          (19+FAPI_GPIO_IN_OFFSET)        //!< Input function: ICC#0 card detection
    #define FAPI_GPIO_IN_UART0_CTS        (20+FAPI_GPIO_IN_OFFSET)        //!< Input function: UART0 CTS signal
    #define FAPI_GPIO_IN_UART0_DATA       (21+FAPI_GPIO_IN_OFFSET)        //!< Input function: UART0 RX data
    #define FAPI_GPIO_IN_SSP1_DATA        (22+FAPI_GPIO_IN_OFFSET)        //!< Input function: SFLASH data input
    #define FAPI_GPIO_IN_TS_C_CLK         (23+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C clock input
    #define FAPI_GPIO_IN_TS_C_PSTART      (24+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C packet start
    #define FAPI_GPIO_IN_TS_C_EN          (25+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C enable
    #define FAPI_GPIO_IN_TS_C_DATA_0      (26+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#0
    #define FAPI_GPIO_IN_TS_C_DATA_1      (27+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#1
    #define FAPI_GPIO_IN_TS_C_DATA_2      (28+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#2
    #define FAPI_GPIO_IN_TS_C_DATA_3      (29+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#3
    #define FAPI_GPIO_IN_TS_C_DATA_4      (30+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#4
    #define FAPI_GPIO_IN_TS_C_DATA_5      (31+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#5
    #define FAPI_GPIO_IN_TS_C_DATA_6      (32+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#6
    #define FAPI_GPIO_IN_TS_C_DATA_7      (33+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS C data bit#7
    #define FAPI_GPIO_IN_TS_B_CLK         (34+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B clock input
    #define FAPI_GPIO_IN_TS_B_PSTART      (35+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B packet start
    #define FAPI_GPIO_IN_TS_B_EN          (36+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B enable
    #define FAPI_GPIO_IN_TS_B_DATA_0      (37+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#0
    #define FAPI_GPIO_IN_TS_B_DATA_1      (38+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#1
    #define FAPI_GPIO_IN_TS_B_DATA_2      (39+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#2
    #define FAPI_GPIO_IN_TS_B_DATA_3      (40+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#3
    #define FAPI_GPIO_IN_TS_B_DATA_4      (41+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#4
    #define FAPI_GPIO_IN_TS_B_DATA_5      (42+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#5
    #define FAPI_GPIO_IN_TS_B_DATA_6      (43+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#6
    #define FAPI_GPIO_IN_TS_B_DATA_7      (44+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS B data bit#7
    #define FAPI_GPIO_IN_TS_A_CLK         (45+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A clock input
    #define FAPI_GPIO_IN_TS_A_PSTART      (46+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A packet start
    #define FAPI_GPIO_IN_TS_A_EN          (47+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A enable
    #define FAPI_GPIO_IN_TS_A_DATA_0      (48+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#0
    #define FAPI_GPIO_IN_TS_A_DATA_1      (49+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#1
    #define FAPI_GPIO_IN_TS_A_DATA_2      (50+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#2
    #define FAPI_GPIO_IN_TS_A_DATA_3      (51+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#3
    #define FAPI_GPIO_IN_TS_A_DATA_4      (52+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#4
    #define FAPI_GPIO_IN_TS_A_DATA_5      (53+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#5
    #define FAPI_GPIO_IN_TS_A_DATA_6      (54+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#6
    #define FAPI_GPIO_IN_TS_A_DATA_7      (55+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#7
    #define FAPI_GPIO_IN_IRQ_IN0          (56+FAPI_GPIO_IN_OFFSET)        //!< Input function: TS A data bit#7
    #define FAPI_GPIO_IN_EXT_AO_DATA      (57+FAPI_GPIO_IN_OFFSET)        //!< Input function: external AO data
    #define FAPI_GPIO_IN_EXT_AO_LRCLK     (58+FAPI_GPIO_IN_OFFSET)        //!< Input function: external AO left/right clock
    #define FAPI_GPIO_IN_EXT_AO_BCLK      (59+FAPI_GPIO_IN_OFFSET)        //!< Input function: external AO byte clock
    #define FAPI_GPIO_IN_FPC_KEY_0        (60+FAPI_GPIO_IN_OFFSET)        //!< Input function: (serial) FPC key#0
    #define FAPI_GPIO_IN_FPC_KEY_1        (61+FAPI_GPIO_IN_OFFSET)        //!< Input function: (serial) FPC key#1
    #define FAPI_GPIO_IN_LCD_CLK          (62+FAPI_GPIO_IN_OFFSET)        //!< Input function: (serial) FPC key#1
    #define FAPI_GPIO_IN_UART1_CTS        (63+FAPI_GPIO_IN_OFFSET)        //!< Input function: UART1 CTS signal
    #define FAPI_GPIO_IN_UART1_DATA       (64+FAPI_GPIO_IN_OFFSET)        //!< Input function: UART1 RX data
    #define FAPI_GPIO_IN_I2C1_DATA        (65+FAPI_GPIO_IN_OFFSET)        //!< Input function: I2C data
    #define FAPI_GPIO_IN_I2C1_CLK         (66+FAPI_GPIO_IN_OFFSET)        //!< Input function: I2C clock
    #define FAPI_GPIO_IN_GPIO_IRQ         (67+FAPI_GPIO_IN_OFFSET)        //!< Input function: I2C clock

    #define FAPI_GPIO_BIDI_I2C0_DATA \
            ((FAPI_GPIO_OUT_I2C0_DATA<<16)+FAPI_GPIO_IN_I2C0_DATA)        //!< In/Out function: I2C data
    #define FAPI_GPIO_BIDI_I2C0_CLK \
            ((FAPI_GPIO_OUT_I2C0_CLK<<16)+FAPI_GPIO_IN_I2C0_CLK)          //!< In/Out function: I2C clock

    #define FAPI_GPIO_IN_GENERIC_SW_FUNCTION \
            ((FAPI_GPIO_OUT_1<<16)+0)                                     //!< A generic input SW function



extern FAPI_SYS_DriverT FAPI_GPIO_Driver; //21b12e94

struct fapi_gpio_params
{
   int Data_0; //0
   unsigned index; //4
   unsigned Data_8; //8
   void (*func)(int); //12
};

extern int FAPI_GPIO_Init(void);
extern void* FAPI_GPIO_Open(struct fapi_gpio_params*, int*);
extern int FAPI_GPIO_Close(void*);
extern int FAPI_GPIO_WriteBit(void*, int);
extern int FAPI_GPIO_ReadBit(void*);
extern void FAPI_GPIO_SetIrqTrigger(unsigned);
extern void FAPI_GPIO_SetIrqEnable(unsigned);
extern void FAPI_GPIO_SetPinFunction(uint32_t pin, uint32_t function);

#endif /*DRV_GPIO_H_*/
