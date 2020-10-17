

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

    FAPI_MMU_Init();
    FAPI_GPIO_Init();
    FAPI_UART_Init();

    FREG_UART_SetDr(0, '?');

#endif

    printf("Hello FAMOS!\n");
}

