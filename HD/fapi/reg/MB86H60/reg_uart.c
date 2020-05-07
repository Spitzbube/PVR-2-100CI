

#include "reg_uart.h"


unsigned FREG_UART_EcrMirror[2]; //21b13800
unsigned FREG_UART_IcrMirror[2]; //21b13808


/* 21c74864 - complete */
void FREG_UART_Init(void)
{
   /*empty*/
}


/* 21c74868 - complete */
void FREG_UART_SetDr(int a, int b)
{   
   *((volatile int*)(0xc2000000 + a*0xC000000)) = b;
}


void FREG_UART_SetDr_Data(int a, int b)
{
   b = (b << 0) & 0xFF;
   b |= (*((volatile int*)(0xc2000000 + a*0xC000000)) & ~0xFF);
   
   *((volatile int*)(0xc2000000 + a*0xC000000)) = b;
}


/* 21c7487c - complete */
int FREG_UART_GetDr_Data(int a)
{   
   return *((volatile int*)(0xc2000000 + a*0xC000000)) & 0xFF;
}


/* 21c74894 - complete */
int FREG_UART_GetFr_Txff(int a)
{
   return (*((volatile int*)(0xc2000018 + a*0xC000000)) & 0x20) >> 5;
}


/* 21c748b4 - complete */
int FREG_UART_GetFr_Rxfe(int a)
{
   return (*((volatile int*)(0xc2000018 + a*0xC000000)) & 0x10) >> 4;
}


/* 21c748d4 - complete */
int FREG_UART_GetFr_Busy(int a)
{
   return (*((volatile int*)(0xc2000018 + a*0xC000000)) & 0x08) >> 3;
}


/* 21c748f4 - complete */
void FREG_UART_SetIbrd_BaudDivint(int a, int b)
{
   *((volatile int*)(0xc2000024 + a*0xC000000)) = b & 0xFFFF;
}


/* 21c74910 - complete */
void FREG_UART_SetFbrd_BaudDivfrac(int a, int b)
{
   *((volatile int*)(0xc2000028 + a*0xC000000)) = b & 0x3F;
}


/* 21c7492c - complete */
void FREG_UART_SetLcrH_Wlen(int a, int b)
{
   b = (b << 5) & (3 << 5);
   b |= (*((volatile int*)(0xc200002c + a*0xC000000)) & ~(3 << 5));
   
   *((volatile int*)(0xc200002c + a*0xC000000)) = b;
}


/* 21c74958 - complete */
void FREG_UART_SetLcrH_Fen(int a, int b)
{
   b = (b << 4) & (1 << 4);
   b |= (*((volatile int*)(0xc200002c + a*0xC000000)) & ~(1 << 4));
   
   *((volatile int*)(0xc200002c + a*0xC000000)) = b;
}


/* 21c74984 - complete */
void FREG_UART_SetLcrH_Stp2(int a, int b)
{
   b = (b << 3) & (1 << 3);
   b |= (*((volatile int*)(0xc200002c + a*0xC000000)) & ~(1 << 3));
   
   *((volatile int*)(0xc200002c + a*0xC000000)) = b;
}


/* 21c749b0 - complete */
void FREG_UART_SetLcrH_Eps(int a, int b)
{
   b = (b << 2) & (1 << 2);
   b |= (*((volatile int*)(0xc200002c + a*0xC000000)) & ~(1 << 2));
   
   *((volatile int*)(0xc200002c + a*0xC000000)) = b;
}


/* 21c749dc - complete */
void FREG_UART_SetLcrH_Pen(int a, int b)
{
   b = (b << 1) & (1 << 1);
   b |= (*((volatile int*)(0xc200002c + a*0xC000000)) & ~(1 << 1));
   
   *((volatile int*)(0xc200002c + a*0xC000000)) = b;
}


/* 21c74a08 - complete */
int FREG_UART_GetLcrH_Wlen(int a)
{
   return (*((volatile int*)(0xc200002c + a*0xC000000)) & (3 << 5)) >> 5;
}


/* 21c74a28 - complete */
int FREG_UART_GetLcrH_Stp2(int a)
{
   return (*((volatile int*)(0xc200002c + a*0xC000000)) & (1 << 3)) >> 3;
}


/* 21c74a48 - complete */
int FREG_UART_GetLcrH_Eps(int a)
{
   return (*((volatile int*)(0xc200002c + a*0xC000000)) & (1 << 2)) >> 2;
}


/* 21c74a68 - complete */
int FREG_UART_GetLcrH_Pen(int a)
{
   return (*((volatile int*)(0xc200002c + a*0xC000000)) & (1 << 1)) >> 1;
}


/* 21c74a88 - complete */
void FREG_UART_SetCr_Ctsen(int a, int b)
{
   b = (b << 15) & (1 << 15);
   b |= (*((volatile int*)(0xc2000030 + a*0xC000000)) & ~(1 << 15));
   
   *((volatile int*)(0xc2000030 + a*0xC000000)) = b;
}


/* 21c74ab4 - complete */
void FREG_UART_SetCr_Rtsen(int a, int b)
{
   b = (b << 14) & (1 << 14);
   b |= (*((volatile int*)(0xc2000030 + a*0xC000000)) & ~(1 << 14));
   
   *((volatile int*)(0xc2000030 + a*0xC000000)) = b;
}


/* 21c74ae0 - complete */
void FREG_UART_SetCr_Rxe(int a, int b)
{
   b = (b << 9) & (1 << 9);
   b |= (*((volatile int*)(0xc2000030 + a*0xC000000)) & ~(1 << 9));
   
   *((volatile int*)(0xc2000030 + a*0xC000000)) = b;
}


/* 21c74b0c - complete */
void FREG_UART_SetCr_Txe(int a, int b)
{
   b = (b << 8) & (1 << 8);
   b |= (*((volatile int*)(0xc2000030 + a*0xC000000)) & ~(1 << 8));
   
   *((volatile int*)(0xc2000030 + a*0xC000000)) = b;
}


/* 21c74b38 - complete */
void FREG_UART_SetCr_Uarten(int a, int b)
{
   b = (b << 0) & (1 << 0);
   b |= (*((volatile unsigned*)(0xc2000030 + a*0xC000000)) & ~(1 << 0));
   
   *((volatile unsigned*)(0xc2000030 + a*0xC000000)) = b;
}


/* 21c74b60 - complete */
int FREG_UART_GetCr_Ctsen(int a)
{
   return (*((volatile unsigned*)(0xc2000030 + a*0xC000000)) & (1 << 15)) >> 15;
}


/* 21c74b80 - complete */
int FREG_UART_GetCr_Rtsen(int a)
{
   return (*((volatile unsigned*)(0xc2000030 + a*0xC000000)) & (1 << 14)) >> 14;
}


/* 21c74ba0 - complete */
void FREG_UART_SetIfls_Rxiflsel(int a, int b)
{
   b = (b << 3) & (7 << 3);
   b |= (*((volatile int*)(0xc2000034 + a*0xC000000)) & ~(7 << 3));
   
   *((volatile int*)(0xc2000034 + a*0xC000000)) = b;
}


/* 21c74bcc - complete */
void FREG_UART_SetIfls_Txiflsel(int a, int b)
{
   b = (b << 0) & (7 << 0);
   b |= (*((volatile int*)(0xc2000034 + a*0xC000000)) & ~(7 << 0));
   
   *((volatile int*)(0xc2000034 + a*0xC000000)) = b;
}


/* 21c74bf4 - complete */
void FREG_UART_SetImsc(int a, int b)
{
   *((volatile int*)(0xc2000038 + a*0xC000000)) = b;
}


/* 21c74c0c - complete */
void FREG_UART_SetImsc_Oeim(int a, int b)
{
   b = (b << 10) & (1 << 10);
   b |= (*((volatile int*)(0xc2000038 + a*0xC000000)) & ~(1 << 10));
   
   *((volatile int*)(0xc2000038 + a*0xC000000)) = b;
}


/* 21c74c38 - complete */
void FREG_UART_SetImsc_Rtim(int a, int b)
{
   b = (b << 6) & (1 << 6);
   b |= (*((volatile int*)(0xc2000038 + a*0xC000000)) & ~(1 << 6));
   
   *((volatile int*)(0xc2000038 + a*0xC000000)) = b;
}


/* 21c74c64 - complete */
void FREG_UART_SetImsc_Txim(int a, int b)
{
   b = (b << 5) & (1 << 5);
   b |= (*((volatile int*)(0xc2000038 + a*0xC000000)) & ~(1 << 5));
   
   *((volatile int*)(0xc2000038 + a*0xC000000)) = b;
}


/* 21c74c90 - complete */
void FREG_UART_SetImsc_Rxim(int a, int b)
{
   b = (b << 4) & (1 << 4);
   b |= (*((volatile int*)(0xc2000038 + a*0xC000000)) & ~(1 << 4));
   
   *((volatile int*)(0xc2000038 + a*0xC000000)) = b;
}


/* 21c74cbc - complete */
int FREG_UART_GetMis(int a)
{
   return *((volatile unsigned*)(0xc2000040 + a*0xC000000));
}


/* 21c74cd4 - complete */
void FREG_UART_SetIcr_Oeic(int a, int b)
{
   b = ((b << 10) & (1 << 10)) | (FREG_UART_IcrMirror[a] & ~(1 << 10));
   FREG_UART_IcrMirror[a] = b;
   *((volatile unsigned*)(0xc2000044 + a*0xC000000)) = b;
}


/* 21c74d0c - complete */
void FREG_UART_SetIcr_Rtic(int a, int b)
{
   b = ((b << 6) & (1 << 6)) | (FREG_UART_IcrMirror[a] & ~(1 << 6));
   FREG_UART_IcrMirror[a] = b;
   *((volatile unsigned*)(0xc2000044 + a*0xC000000)) = b;
}


/* 21c74d44 - complete */
void FREG_UART_SetIcr_Txic(int a, int b)
{
   b = ((b << 5) & (1 << 5)) | (FREG_UART_IcrMirror[a] & ~(1 << 5));
   FREG_UART_IcrMirror[a] = b;
   *((volatile unsigned*)(0xc2000044 + a*0xC000000)) = b;
}


/* 21c74d7c - complete */
void FREG_UART_SetIcr_Rxic(int a, int b)
{
   b = ((b << 4) & (1 << 4)) | (FREG_UART_IcrMirror[a] & ~(1 << 4));
   FREG_UART_IcrMirror[a] = b;
   *((volatile unsigned*)(0xc2000044 + a*0xC000000)) = b;
}









