#ifndef REG_UART_H_
#define REG_UART_H_

extern void FREG_UART_Init(void);
extern void FREG_UART_SetDr(int a, int b);
extern void FREG_UART_SetDr_Data(int a, int b);
extern int FREG_UART_GetDr_Data(int a);
extern int FREG_UART_GetFr_Txff(int a);
extern int FREG_UART_GetFr_Rxfe(int a);
extern int FREG_UART_GetFr_Busy(int a);
extern void FREG_UART_SetIbrd_BaudDivint(int a, int b);
extern void FREG_UART_SetFbrd_BaudDivfrac(int a, int b);
extern void FREG_UART_SetLcrH_Wlen(int a, int b);
extern void FREG_UART_SetLcrH_Fen(int a, int b);
extern void FREG_UART_SetLcrH_Stp2(int a, int b);
extern void FREG_UART_SetLcrH_Eps(int a, int b);
extern void FREG_UART_SetLcrH_Pen(int a, int b);
extern int FREG_UART_GetLcrH_Wlen(int a);
extern int FREG_UART_GetLcrH_Stp2(int a);
extern int FREG_UART_GetLcrH_Eps(int a);
extern int FREG_UART_GetLcrH_Pen(int a);
extern void FREG_UART_SetCr_Ctsen(int a, int b);
extern void FREG_UART_SetCr_Rtsen(int a, int b);
extern void FREG_UART_SetCr_Rxe(int a, int b);
extern void FREG_UART_SetCr_Txe(int a, int b);
extern void FREG_UART_SetCr_Uarten(int a, int b);
extern int FREG_UART_GetCr_Ctsen(int a);
extern int FREG_UART_GetCr_Rtsen(int a);
extern void FREG_UART_SetIfls_Rxiflsel(int a, int b);
extern void FREG_UART_SetIfls_Txiflsel(int a, int b);
extern void FREG_UART_SetImsc(int a, int b);
extern void FREG_UART_SetImsc_Oeim(int a, int b);
extern void FREG_UART_SetImsc_Rtim(int a, int b);
extern void FREG_UART_SetImsc_Txim(int a, int b);
extern void FREG_UART_SetImsc_Rxim(int a, int b);
extern int FREG_UART_GetMis(int a);
extern void FREG_UART_SetIcr_Oeic(int a, int b);
extern void FREG_UART_SetIcr_Rtic(int a, int b);
extern void FREG_UART_SetIcr_Txic(int a, int b);
extern void FREG_UART_SetIcr_Rxic(int a, int b);

#endif /*REG_UART_H_*/
