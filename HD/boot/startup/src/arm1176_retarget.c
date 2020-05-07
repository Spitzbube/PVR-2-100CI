
#include <stdio.h>
//#include <rt_sys.h>
#include "cpu_polling.h"
#include "fapi/drv_uart.h"


int uartLastReadChar = 0; //21b13970
int uartBackSpaceCalled = 0; //21b13974
struct BOOT_ROM_SymbolT
{
   int fill_0[62]; //0
   int Data_248; //248
}* romSymbolMap = (void*) 0x02000000; //21b13978




/* 21b082e4 - complete */
int fputc(int c, FILE * stream)
{
   int res;

   ((int*)stream)[0] |= 0;

   if (romSymbolMap->Data_248 != 0)
   {
      romSymbolMap->Data_248 = 0;
   }

   if (c == 0x0A)
   {
      FAPI_UART_WriteByte(uartRetargetHandle, 0x0D);
   }

   res = FAPI_UART_WriteByte(uartRetargetHandle, c);

   if (res == 0)
   {
      if (c == 0x0A)
      {
         romSymbolMap->Data_248 = 1;
      }

      return c;
   }

   return -1;
}


/* 21b08378 - nearly complete */
int fgetc(FILE * stream)
{
   int c;

   if (uartBackSpaceCalled != 0)
   {
      uartBackSpaceCalled = 0;

      return uartLastReadChar;
   }

   c = FAPI_UART_ReadByte(uartRetargetHandle);

   if (c >= 0)
   {
      uartLastReadChar = c;

      return c;
   }

   return -1;
}


/* 21b083dc - nearly complete */
int ferror(FILE * stream)
{
   return -1;
}


/* 21b083ec - complete */
void _ttywrch(int ch)
{
   (void) FAPI_UART_WriteByte(uartRetargetHandle, ch);
}


/* 21b08408 - nearly complete */
int __backspace(FILE * stream)
{
   uartBackSpaceCalled = 1;

   return 0;
}


/* 21b08424 - nearly complete */
int _sys_exit(int returncode)   /* never returns */
{
   CPU_Polling();
   return 0;
}


