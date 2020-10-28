
#include <stdio.h>
//#include "cpu_polling.h"
#include "fapi/reg_irq_ctrl.h"
#include "fapi/drv_intr.h"
#include "famos_interrupt.h"



/* 21c7cf94 - complete */
void ARM1176_INTR_SwiFunction(int a, int b)
{
   puts("famosIntrSwiFunction");
   printf(" execution interrupted at 0x%08x\n", a - 4);
   printf(" got SWI parameter 0x%08x\n", b);
   
   if (b == 0x800000)
   {
      puts(" going to HALT mode");         
      CPU_Halt();
   }
   else if (b == 0x800001)
   {
      puts(" going to POLLING mode");
      CPU_Polling();
   }
   else if (b == 0x800002)
   {
      puts(" calling application specific SWI callback#1");
      
      if (FAPI_INTR_SwiFunctionTable[2] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[2])(b);
      }         
   }
   else if (b == 0x800003)
   {
      puts(" calling application specific SWI callback#2");
      
      if (FAPI_INTR_SwiFunctionTable[3] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[3])(b);
      }         
   }
   else if (b == 0x800004)
   {
      puts(" calling application specific SWI callback#3");
      
      if (FAPI_INTR_SwiFunctionTable[4] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[4])(b);
      }         
   }
   else if (b == 0x800005)
   {
      puts(" calling application specific SWI callback#4");
      
      if (FAPI_INTR_SwiFunctionTable[5] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[5])(b);
      }         
   }

   printf(" continue with execution at 0x%08x\n", a);
}


/* 21c7cf3c - complete */
void ARM1176_INTR_UndefFunction(int a)
{
#if 0
   if (FAPI_INTR_SysIrqFunction != 0)
   {
      (FAPI_INTR_SysIrqFunction)(1, a);
   }
#endif
   
   puts("famosIntrUndefFunction");
   printf(" execution interrupted at 0x%08x\n", a);
   puts(" going to POLLING mode");
   
   CPU_Polling();
}


/* 21c7cee4 - complete */
void ARM1176_INTR_PrefetchFunction(int a)
{
#if 0
   if (FAPI_INTR_SysIrqFunction != 0)
   {
      (FAPI_INTR_SysIrqFunction)(3, a);
   }
#endif
   
   puts("famosIntrPrefetchFunction");
   printf(" execution interrupted at 0x%08x\n", a);
   puts(" going to POLLING mode");
   
   CPU_Polling();
}


/* 21c7ce8c - complete */
void ARM1176_INTR_AbortFunction(int a)
{
#if 0
   if (FAPI_INTR_SysIrqFunction != 0)
   {
      (FAPI_INTR_SysIrqFunction)(4, a);
   }
#endif
   
   puts("famosIntrAbortFunction");
   printf(" execution interrupted at 0x%08x\n", a);
   puts(" going to POLLING mode");
   
   CPU_Polling();
}


/* 21c7ce24 - complete */
void ARM1176_INTR_IrqFunction(int a)
{
   unsigned i, j = 0;
   
   unsigned mask = FREG_IRQ_CTRL_GetArmirqstatus();
      
   for (i = 0; i < 32; i++, mask >>= 1)
   {
      if (mask & 1)
      {
         j = i;
         break;
      }
   }   

   if (j != 0)
   {
      if (FAPI_INTR_IsrFunctionTable[j] != 0)
      {
         void* res = (FAPI_INTR_IsrFunctionTable[j])();
         
         int (*bh)(void*) = FAPI_INTR_BsrFunctionTable[j];
         
         if ((res != 0) && (bh != 0))
         {
            (bh)(res);
         }
      }
   }   
}


/* 21c7cdec - complete */
void ARM1176_INTR_FiqFunction(int a)
{
   puts("famosIntrFiqFunction");
   printf(" execution interrupted at 0x%08x\n", a);
   printf(" continue execution at 0x%08x\n", a);
}


