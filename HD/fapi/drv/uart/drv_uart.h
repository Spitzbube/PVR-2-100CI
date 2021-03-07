#ifndef DRV_UART_H_
#define DRV_UART_H_


#define FAPI_UART_BAUDRATE_115200  115200
#define FAPI_UART_DATABITS_8       8
#define FAPI_UART_STOPBITS_1       1
#define FAPI_UART_PARITY_NONE      0
#define FAPI_UART_FLOWCTRL_NONE    0

typedef enum {
    FAPI_UART_VERSION = (int32_t)0x00020000
} FAPI_UART_VersionEnumT;

typedef struct
{
    FAPI_UART_VersionEnumT version;
    uint32_t               index;
} FAPI_UART_OpenParamsT;


extern void* uartRetargetHandle;

extern FAPI_SYS_DriverT FAPI_UART_Driver0;
extern FAPI_SYS_DriverT FAPI_UART_Driver1;


extern int FAPI_UART_Init(void);
extern void* FAPI_UART_Open(FAPI_UART_OpenParamsT*, int*);
extern int FAPI_UART_Close(void*);
extern int FAPI_UART_WriteByte(void*, char);
extern int FAPI_UART_ReadByte(void*);
extern int FAPI_UART_CheckRxFifo(void*);
extern void FAPI_UART_LockMutex(void);
extern void FAPI_UART_UnlockMutex(void);
extern void FAPI_UART_SetClockFrequency(unsigned);
extern void FAPI_UART_SetBaudrate(unsigned, unsigned);
extern void FAPI_UART_SetDataBits(unsigned, unsigned);
extern void FAPI_UART_SetStopBits(unsigned, unsigned);
extern void FAPI_UART_SetParity(unsigned, unsigned);
extern void FAPI_UART_SetFlowControl(unsigned, unsigned);
extern void FAPI_UART_SetStdioBlockIndex(unsigned);

#endif /*DRV_UART_H_*/
