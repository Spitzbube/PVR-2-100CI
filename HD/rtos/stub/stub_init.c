
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "fapi/drv_timer.h"
#include "fapi/sys_services.h"


static int semaphoreInitialized; //21b1397c +0
static void* printfSemaphore; //21b13980 +4
static volatile int semaphoreArray[256]; //21b1d82c
static char usrPrintBuffer[1024]; //21b1dc2c
static char isrPrintBuffer[1024]; //21b1e02c




/* 21b08494 - complete */
void RTOS_STUB_SetSemaphore(void* a, int b)
{
   unsigned cpu_sr;
   unsigned i = (int) a;

   DI(cpu_sr);   
   
   if (i < 256)
   {
      int sem = semaphoreArray[i];
      if ((sem >= 0) && (sem < 0x7fffffff))
      {
         semaphoreArray[i] = sem + 1;
      }
   }
   
   EI(cpu_sr);
}


/* 21b084ec - nearly complete */
int RTOS_STUB_GetSemaphore(void* a, int b)
{
   int sem;
   unsigned cpu_sr;
   unsigned i = (int) a;
   
   unsigned long long r17_15 = 0;
   
   if (i < 256)
   {
      DI(cpu_sr);
   
      sem = semaphoreArray[i];
      
      if (sem < 0)
      {
         EI(cpu_sr);
         return -1;
      }
      
      if (sem > 0)
      {      
         semaphoreArray[i] = sem - 1;
         
         EI(cpu_sr);
   
         return sem - 1;
      }
      else
      {
         EI(cpu_sr);
         
         if (b == 0)
         {
            return -1;
         }
         
         if (b != -1)
         {
            r17_15 = FAPI_TIMER_GetTimeStamp(1000);
         }
         
         while (1)
         {
            sem = semaphoreArray[i];
            if (b != -1)
            {
               if ((FAPI_TIMER_GetTimeStamp(1000) - r17_15) >= (unsigned)b)
               {
                  return -1;
               }
            }
            if (sem != 0)
            {
               break;
            }
         }
         
         if (sem < 0)
         {
            return -1;
         }
         
         DI(cpu_sr);
         
         semaphoreArray[i] = sem - 1;
         
         EI(cpu_sr);
   
         return sem - 1;
      }
   }
   else
   {
      return -1;
   }
}


/* 21b085f0 - complete */
static int RTOS_STUB_Printf(const char* format, ...)
{
   int len;
   va_list ap;  
   char* buffer;
   int lock = (((FAPI_SYS_IsIrqEnabled() != 0)) &&
         (FAPI_SYS_IsIsrActive() == 0));
   
   if (lock != 0)
   {
      buffer = usrPrintBuffer;
      
      RTOS_STUB_GetSemaphore(printfSemaphore, -1);
   }
   else
   {
      buffer = isrPrintBuffer;
   }
   
   memset(buffer, 0, 1024);
   
   va_start(ap, format); 
   
   len = vsprintf(buffer, format, ap);
   
   if (len >= 1024)
   {
      printf("\nERROR: thread specific print buffer overflow (%u>%u), exiting...\n\n", len, 1024);      
      exit(-1);
   }

   fputs(buffer, stdout); 
   
   if (lock != 0)
   {
      unsigned cpu_sr;  
      unsigned sem = (int) printfSemaphore;
      
      DI(cpu_sr);
      
      if (sem < 256)
      {
         unsigned val = semaphoreArray[sem];
         
         if (val < 0x7FFFFFFF) //-0x80000001)
         {
            semaphoreArray[sem] = val + 1;
         }
      }
      
      EI(cpu_sr);
   }

   return len;
}


/* 21b086d4 - complete */
static void RTOS_STUB_Sleep(unsigned t_max)
{
   unsigned long long t1, t2;
   
   t1 = FAPI_TIMER_GetTimeStamp(1000);   
   
   while (1)
   {
      t2 = t_max;
      if ((FAPI_TIMER_GetTimeStamp(1000) - t1) >= t2)
      {
         break;
      }
   }
}


/* 21b08710 - complete */
static unsigned RTOS_STUB_DisableIrq(void)
{
   unsigned my_cpsr, new_cpsr;
   
#if defined(__GNUC__)
   asm volatile( "mrs %0,cpsr"     : "=r"(my_cpsr) : "r"(new_cpsr) );
   asm volatile( "orr %0,%1,#0xC0" : "=r"(new_cpsr) : "r"(my_cpsr) );
   asm volatile( "msr cpsr_c,%0"   : : "r"(new_cpsr) );
#else
   __asm
   {
      MRS      my_cpsr, CPSR
      ORR      new_cpsr,my_cpsr,#0xc0
      MSR      CPSR_c,new_cpsr
   }
#endif
   
   return my_cpsr;
}


/* 21b08720 - complete */
static void RTOS_STUB_EnableIrq(unsigned my_cpsr)
{
#if defined(__GNUC__)
    asm volatile( "msr cpsr_c,%0" : : "r"(my_cpsr) );
#else
   __asm
   {
      MSR      CPSR_c,my_cpsr
   }
#endif
}


/* 21b08728 - complete */
void* RTOS_STUB_CreateSemaphore(int a)
{
   unsigned i;
   unsigned cpu_sr;
   
   if (a < 0)
   {
      return 0;
   }
   
   DI(cpu_sr);
   
   if (semaphoreInitialized == 0)
   {
      for (i = 1; i < 256; i++)
      {
         semaphoreArray[i] = -1;
      }
      semaphoreInitialized = 1;
   }

   for (i = 1; i < 256; i++)
   {
      if (semaphoreArray[i] == -1)
      {
         semaphoreArray[i] = a;
         
         EI(cpu_sr);
         
         return (void*) i;
      }
   }
   
   EI(cpu_sr);
      
   return 0;
}


/* 21b087c0 - complete (3.1) */
void RTOS_STUB_DestroySemaphore(void* a)
{
   unsigned cpu_sr;
   unsigned i = (int) a;
   
   DI(cpu_sr);

   if (i < 256)
   {
      if (semaphoreArray[i] != -1)
      {
         semaphoreArray[i] = -1;
      }
   }
   
   EI(cpu_sr);
}


/* 21b08cbc - todo */
void RTOS_STUB_InitServices(void)
{
   static struct FAPI_SYS_Services RTOS_STUB_Services;
   
   RTOS_STUB_Services.disableIrq = RTOS_STUB_DisableIrq;
   RTOS_STUB_Services.enableIrq = RTOS_STUB_EnableIrq;
   RTOS_STUB_Services.createSemaphore = RTOS_STUB_CreateSemaphore;
   RTOS_STUB_Services.deleteSemaphore = RTOS_STUB_DestroySemaphore;
   RTOS_STUB_Services.requestSemaphore = RTOS_STUB_GetSemaphore;
   RTOS_STUB_Services.releaseSemaphore = RTOS_STUB_SetSemaphore;
   RTOS_STUB_Services.printfFunc = RTOS_STUB_Printf;
   
   FAPI_SYS_SetServices(&RTOS_STUB_Services);
   
   printfSemaphore = RTOS_STUB_CreateSemaphore(1);
}


