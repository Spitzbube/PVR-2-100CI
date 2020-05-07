#ifndef DRV_UART_H_
#define DRV_UART_H_


struct fapi_driver;

struct fapi_uart_open_params
{
   int Data_0; //0
   int index; //4
};


extern void* uartRetargetHandle;

extern struct fapi_driver FAPI_UART_Driver0; 
extern struct fapi_driver FAPI_UART_Driver1; 


extern int FAPI_UART_Init(void);
extern void* FAPI_UART_Open(struct fapi_uart_open_params*, int*);
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
