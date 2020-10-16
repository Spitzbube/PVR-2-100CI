
#if 0

#include "sys_services.h"
#include "cpu_polling.h"
#include "drv_intr.h"
#include "reg_irq_ctrl.h"

#endif

extern void* (*FAPI_INTR_IsrFunctionTable[32])(void); //flasher: 21b15114
extern int (*FAPI_INTR_BsrFunctionTable[32])(void*); //flasher: 21b15194


/* flasher: 21b0cc10 - complete */
static void ARM1176_INTR_UndefFunction(int a)
{   
#if 0
   PRINTF("ARM1176_INTR_UndefFunction\n");
   PRINTF1(" execution interrupted at 0x%08x\n", a);
   PRINTF(" going to POLLING mode\n");

   CPU_Polling();
#endif
}


/* flasher: 21b0ccbc - nearly complete */
static void ARM1176_INTR_SwiFunction(int a, int b)
{
#if 0
   PRINTF("ARM1176_INTR_SwiFunction\n");
   PRINTF1(" execution interrupted at 0x%08x\n", a - 4);
   PRINTF1(" got SWI parameter 0x%08x\n", b);
   
   if (b == 0x800000)
   {
      PRINTF(" going to HALT mode\n");         
      CPU_Halt();
   }
   else if (b == 0x800001)
   {
      PRINTF(" going to POLLING mode\n");
      CPU_Polling();
   }
   else if (b == 0x800002)
   {
      PRINTF(" calling application specific SWI callback#1\n");
      
      if (FAPI_INTR_SwiFunctionTable[b & 0xFF] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[b & 0xFF])(b);
      }         
   }
   else if (b == 0x800003)
   {
      PRINTF(" calling application specific SWI callback#2\n");
      
      if (FAPI_INTR_SwiFunctionTable[b & 0xFF] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[b & 0xFF])(b);
      }         
   }
   else if (b == 0x800004)
   {
      PRINTF(" calling application specific SWI callback#3\n");
      
      if (FAPI_INTR_SwiFunctionTable[b & 0xFF] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[b & 0xFF])(b);
      }         
   }
   else if (b == 0x800005)
   {
      PRINTF(" calling application specific SWI callback#4\n");
      
      if (FAPI_INTR_SwiFunctionTable[b & 0xFF] != 0)
      {
         (FAPI_INTR_SwiFunctionTable[b & 0xFF])(b);
      }         
   }

   PRINTF1(" continue with execution at 0x%08x\n", a);
#endif
}


/* flasher: 21b0cf60 - complete */
static void ARM1176_INTR_PrefetchFunction(int a)
{
#if 0
   PRINTF("ARM1176_INTR_PrefetchFunction\n");
   PRINTF1(" execution interrupted at 0x%08x\n", a);
   PRINTF(" going to POLLING mode\n");
   
   CPU_Polling();
#endif
}


/* flasher: 21b0cfd0 - complete */
static void ARM1176_INTR_AbortFunction(int a)
{
#if 0
   PRINTF("ARM1176_INTR_AbortFunction\n");
   PRINTF1(" execution interrupted at 0x%08x\n", a);
   PRINTF(" going to POLLING mode\n");
   
   CPU_Polling();
#endif
}


/* flasher: 21b0d03c - complete */
static void ARM1176_INTR_IrqFunction(int a)
{
   unsigned i = 0;
   unsigned j = 0;
   
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


/* flasher: 21b0d09c - complete */
static void ARM1176_INTR_FiqFunction(int a)
{
#if 0
   PRINTF("ARM1176_INTR_FiqFunction\n");
   PRINTF1(" execution interrupted at 0x%08x\n", a);
   PRINTF1(" continue execution at 0x%08x\n", a);
#endif
}


void (*ARM1176_INTR_FunctionTable[])(int) = //Flasher: 21b139dc
{
      0, //Reset
      ARM1176_INTR_UndefFunction,
      ARM1176_INTR_SwiFunction,
      ARM1176_INTR_PrefetchFunction,
      ARM1176_INTR_AbortFunction,
      0,
      ARM1176_INTR_IrqFunction,
      ARM1176_INTR_FiqFunction,
};


