
#include "fapi/sys_services.h"
#include "fapi/drv_mmu.h"
#include "fapi/drv_timer.h"


static struct fapi_driver* FAPI_SYS_DriverArr[] =
{
        &FAPI_TIMER_Driver0,
        &FAPI_TIMER_Driver1,
        &FAPI_TIMER_Driver2,
        0
};

int main()
{
    RTOS_InitServices();

#if 0
    FAPI_SYS_Init();
#else
    FAPI_UART_SetBaudrate( 0, 115200 );
    FAPI_UART_SetDataBits( 0, 8 );
    FAPI_UART_SetStopBits( 0, 1 );
    FAPI_UART_SetParity( 0, 0 );
    FAPI_UART_SetFlowControl( 0, 0 );
    FAPI_UART_SetStdioBlockIndex( 0 );
//    FAPI_UART_SetInterruptMode( 0, 1 );

    FAPI_GPIO_SetPinFunction( 33, 23 + 0x0080 /*0x97*/ );
    FAPI_GPIO_SetPinFunction( 32, 21 + 0x0100 /*0x115*/ );

    FAPI_INTR_SetReceiver(5, 1); //TIMER0
    FAPI_INTR_SetReceiver(6, 1); //TIMER1
    FAPI_INTR_SetReceiver(7, 0); //TIMER2

    FAPI_MMU_Init();
    FAPI_GPREG_Init();
    FAPI_INTR_Init();
    FAPI_GPIO_Init();
    FAPI_UART_Init();

    FAPI_SYS_INIT_DRIVERS(FAPI_SYS_DriverArr);
#endif

    printf("Hello FAMOS!\n");

#if 0
    FAPI_MMU_ReportMemory(FAPI_MMU_HeapHandleDTcm, 0);
    FAPI_MMU_ReportMemory(FAPI_MMU_HeapHandleSRam, 0);
#endif

    RTOS_InitKernel();

#if 0
    FAPI_MMU_ReportMemory(FAPI_MMU_HeapHandleDTcm, 0);
    FAPI_MMU_ReportMemory(FAPI_MMU_HeapHandleSRam, 0);
#endif

    rtos_start();
}

