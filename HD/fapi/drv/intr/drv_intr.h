#ifndef DRV_INTR_H_
#define DRV_INTR_H_


    #define FAPI_INTR_UNDEFINED            -1 //!< undefined, no interrupt
    #define FAPI_INTR_TIMER0               5  //!< interrupt number for TIMER block 0
    #define FAPI_INTR_TIMER1               6  //!< interrupt number for TIMER block 1
    #define FAPI_INTR_TIMER2               7  //!< interrupt number for TIMER block 2
    #define FAPI_INTR_UART0                8  //!< interrupt number for UART block 0
    #define FAPI_INTR_UART1                9  //!< interrupt number for UART block 1
    #define FAPI_INTR_SSP0                 10 //!< interrupt number for SSP block 0
    #define FAPI_INTR_SSP1                 11 //!< interrupt number for SSP block 1
    #define FAPI_INTR_ICC0                 12 //!< interrupt number for ICC block 0
    #define FAPI_INTR_ICC1                 13 //!< interrupt number for ICC block 1
    #define FAPI_INTR_FPC_IR               14 //!< interrupt number for FPC and IR (shared)
    #define FAPI_INTR_I2C0                 15 //!< interrupt number for I2C block 0
    #define FAPI_INTR_I2C1                 16 //!< interrupt number for I2C block 1
    #define FAPI_INTR_I2C2                 17 //!< interrupt number for I2C block 2
    #define FAPI_INTR_AMCPU_AXP            18 //!< interrupt number for AMCPU_IRQ_S, AMCPU_ERRIRQ_S and IRQ_AXP (shared)
    #define FAPI_INTR_GPIO                 19 //!< interrupt number for GPIO blocks 0 and 1 (shared)
    #define FAPI_INTR_DMA                  20 //!< interrupt number for DMA
    #define FAPI_INTR_USB                  21 //!< interrupt number for USB
    #define FAPI_INTR_ETH                  22 //!< interrupt number for ETH
    #define FAPI_INTR_AUDIO                23 //!< interrupt number for AUDIO
    #define FAPI_INTR_BM01                 24 //!< interrupt number for BM block 0
    #define FAPI_INTR_BM23                 25 //!< interrupt number for BM block 1
    #define FAPI_INTR_TSD01                26 //!< interrupt number for TSD block 0
    #define FAPI_INTR_TSD23                27 //!< interrupt number for TSD block 1
    #define FAPI_INTR_DISP0                28 //!< interrupt number for DISP block 0
    #define FAPI_INTR_DISP1                29 //!< interrupt number for DISP block 1
    #define FAPI_INTR_DISP2                30 //!< interrupt number for DISP block 2
    #define FAPI_INTR_POLLING_MODE         31 //!< interrupt number for cpu POLLING mode request
    #define FAPI_INTR_COUNT                32 //!< max. number of interrupts


    #define FAPI_INTR_PRIORITY_ARM_MIN     5  //!< min. interrupt priority for ARM
    #define FAPI_INTR_PRIORITY_ARM_MAX     15 //!< max. interrupt priority for ARM
    #define FAPI_INTR_PRIORITY_ARM_LOWEST  5  //!< lowest interrupt priority for ARM
    #define FAPI_INTR_PRIORITY_ARM_LOW     7  //!< low interrupt priority for ARM
    #define FAPI_INTR_PRIORITY_ARM_MEDIUM  10 //!< medium interrupt priority for ARM
    #define FAPI_INTR_PRIORITY_ARM_HIGH    13 //!< high interrupt priority for ARM
    #define FAPI_INTR_PRIORITY_ARM_HIGHEST 15 //!< highest interrupt priority for ARM

    #if defined(__arm__)
    #define FAPI_INTR_PRIORITY_MIN         FAPI_INTR_PRIORITY_ARM_MIN     //!< min. interrupt priority if compiled for the ARM target
    #define FAPI_INTR_PRIORITY_MAX         FAPI_INTR_PRIORITY_ARM_MAX     //!< max. interrupt priority if compiled for the ARM target
    #define FAPI_INTR_PRIORITY_LOWEST      FAPI_INTR_PRIORITY_ARM_LOWEST  //!< lowest interrupt priority if compiled for the ARM target
    #define FAPI_INTR_PRIORITY_LOW         FAPI_INTR_PRIORITY_ARM_LOW     //!< low interrupt priority if compiled for the ARM target
    #define FAPI_INTR_PRIORITY_MEDIUM      FAPI_INTR_PRIORITY_ARM_MEDIUM  //!< medium interrupt priority if compiled for the ARM target
    #define FAPI_INTR_PRIORITY_HIGH        FAPI_INTR_PRIORITY_ARM_HIGH    //!< high interrupt priority if compiled for the ARM target
    #define FAPI_INTR_PRIORITY_HIGHEST     FAPI_INTR_PRIORITY_ARM_HIGHEST //!< highest interrupt priority if compiled for the ARM target
    #endif

    #define FAPI_INTR_RECEIVER_NONE        0  //!< mask to set none of the cpus as IRQ receiver
    #define FAPI_INTR_RECEIVER_ARM         1  //!< mask to set the ARM cpu as IRQ receiver
    #define FAPI_INTR_RECEIVER_ARC         2  //!< mask to set the ARC cpu as IRQ receiver
    #define FAPI_INTR_RECEIVER_BOTH        3  //!< mask to set both cpus as IRQ receiver


extern FAPI_SYS_DriverT FAPI_INTR_Driver;

extern void* (*FAPI_INTR_IsrFunctionTable[])(void);
extern int (*FAPI_INTR_BsrFunctionTable[])(void*); 
extern int (*FAPI_INTR_SwiFunctionTable[])(int);

extern void FAPI_INTR_Exit(void);
extern int FAPI_INTR_RegisterIrq(unsigned, void* (*)(void), int (*)(void*));
extern int FAPI_INTR_UnregisterIrq(unsigned);
extern int FAPI_INTR_DisableIrqCtrl(unsigned);
extern int FAPI_INTR_EnableIrqCtrl(unsigned);
extern void FAPI_INTR_SetReceiver(unsigned, unsigned);
extern void FAPI_INTR_SetPriority(unsigned, unsigned);
uint32_t FAPI_INTR_Isr31( void );

#endif /*DRV_INTR_H_*/
