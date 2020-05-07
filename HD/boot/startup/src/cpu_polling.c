
#include <stdio.h>
#include "cpu_polling.h"
#include "fapi/drv_uart.h"
#include "fapi/sys_services.h"


struct rom
{
    int fill[65]; //0
    void (*poll)(void); //260
};


/* 21b02468 - complete */
void CPU_Polling(void)
{
    int hwReg;
    void (*poll)(void);
    struct rom* rom = (void*) 0x2000000;

//    FAPI_INTR_Exit();

    hwReg = *((volatile int*)0xcf000310);
    hwReg &= ~0x0F;
    hwReg &= ~0xF0;
    hwReg |= 0x20;
    *((volatile int*)0xcf000310) = hwReg;

    poll = rom->poll;

 #if 0
    //ARM
    asm("msr CPSR_c, #223");
 #endif

    FAPI_UART_LockMutex();

    PRINTF1("jumping to POLLING function in ROM at 0x%08x\n",
       (int) poll);

    FAPI_UART_UnlockMutex();

    (poll)();
}


/* 21b024c4 - complete */
void CPU_Halt(void)
{
    int hwReg;
    void (*poll)(void);
    struct rom* rom = (void*) 0x2000000;

    hwReg = *((volatile int*)0xcf000310);
    hwReg &= ~0x0F;
    hwReg &= ~0xF0;
    hwReg |= 0x10;
    *((volatile int*)0xcf000310) = hwReg;

    poll = rom->poll;

 #if 0
    //ARM
    asm("msr CPSR_c, #223");
 #endif

    FAPI_UART_LockMutex();

    PRINTF1("jumping to POLLING function in ROM at 0x%08x\n",
       (int) poll);

    FAPI_UART_UnlockMutex();

    (poll)();
}



