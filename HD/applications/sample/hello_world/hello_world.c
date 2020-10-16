
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fapi/sys_services.h"
#include "fapi/drv_gpio.h"
#include "fapi/drv_uart.h"
#include "fapi/drv_intr.h"

extern void* FAPI_UART_Isr0(void);

int main()
{
    FAPI_GPIO_SetPinFunction( 33, 23 + 0x0080 /*0x97*/ );
    FAPI_GPIO_SetPinFunction( 32, 21 + 0x0100 /*0x115*/ );

    FAPI_UART_SetBaudrate( 0, 115200 );
    FAPI_UART_SetDataBits( 0, 8 );
    FAPI_UART_SetStopBits( 0, 1 );
    FAPI_UART_SetParity( 0, 0 );
    FAPI_UART_SetFlowControl( 0, 0 );
    FAPI_UART_SetStdioBlockIndex( 0 );
    FAPI_UART_SetInterruptMode( 0, 1 );
    FAPI_INTR_SetReceiver(8, 1); //uart0 -> arm

    RTOS_InitServices();

    FAPI_INTR_Init();
    FAPI_GPIO_Init();
    FAPI_UART_Init();

    FAPI_INTR_RegisterIrq(8, FAPI_UART_Isr0, 0);
    FAPI_INTR_EnableIrqCtrl(8); //uart0

    FREG_UART_SetLcrH_Fen(0, 1);
    FREG_UART_SetImsc_Rxim(0, 1);
    FREG_UART_SetImsc_Txim(0, 0);
    FREG_UART_SetImsc_Rtim(0, 1);
    FREG_UART_SetImsc_Oeim(0, 1);
    FREG_UART_SetIfls_Rxiflsel(0, 0);
    FREG_UART_SetIfls_Txiflsel(0, 0x04);


    printf("\nHello World\n");

    FAPI_UART_ReadByte(uartRetargetHandle);

    exit(0);
}

