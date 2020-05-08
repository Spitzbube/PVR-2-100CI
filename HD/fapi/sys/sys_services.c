
#include <string.h>
#include "sys_services.h"




static int sysMasterCpuId; //21b12a2c

struct FAPI_SYS_Services FAPI_SYS_Services; //21b140a0


/* 21b025c4 - complete */
void FAPI_SYS_SetServices(struct FAPI_SYS_Services* a)
{
   if (a != 0)
   {
      memcpy(&FAPI_SYS_Services, a, sizeof(FAPI_SYS_Services));
   }
}


/* 21b025e0 - complete (RVCT3.1) */
void FAPI_SYS_InvalidateDataCache(int a, int b)
{
   int cpu_sr;
   int r2, r3;
   
   DI(cpu_sr);
   
   r3 = (a + b - 1);
   r2 = a & ~3;
   r3 &= ~3;
   
#if defined(__GNUC__)
   asm("mcrr 15, 0, %0, %1, cr6":: "r" (r3), "r" (r2));
#else
   __asm
   {
      mcrr p15, 0, r3, r2, c6
   }
#endif
   
   EI(cpu_sr);
}


/* 21b02624 - complete (RVCT3.1) */
void FAPI_SYS_FlushDataCache(void* a, int b)
{
   int cpu_sr;
   int r2, r3;
   
   DI(cpu_sr);
   
   r3 = (int)((char*)a + (b - 1));
   r2 = (int)a & ~3;
   r3 &= ~3; 

#if defined(__GNUC__)
   asm("mcrr 15, 0, %0, %1, cr12":: "r" (r3), "r" (r2));
#else
   __asm
   {
      mcrr p15, 0, r3, r2, c12
   }
#endif
   
   EI(cpu_sr);
}


/* 21b02668 - complete (RVCT3.1) */
void FAPI_SYS_InvalidateInstructionCache(void* a, int b)
{
   int cpu_sr;
   int r1;
   
   DI(cpu_sr);
   
   r1 = 0;
   
#if defined(__GNUC__)
   asm("mcr 15, 0, %0, cr7, cr5, 0":: "r" (r1));
#else
   __asm
   {
      mcr p15, 0, r1, c7, c5, 0
   }
#endif
   
   EI(cpu_sr);
}


/* 21b02698 - complete */
int FAPI_SYS_GetDeviceId(void)
{     
   volatile int* reg = (void*) 0xd5000000;
   int r1 = reg[0];
   int r0 = reg[3];
   
   if (r1 != -1)
   {
      if ((r0 & 0xFF) == 0xFF)
      {
         return 0x48363000; //H60
      }
      
      if ((r0 & 0xFF) == 0xFE)
      {
         return 0x48363042; //H60B
      }
   }
         
   return 0;
}


/* 21b026dc - complete */
int FAPI_SYS_IsIrqEnabled(void)
{
   unsigned my_cpsr;
   
#if defined(__GNUC__)
   asm("mrs %0, CPSR": "=r" (my_cpsr));
#else
   __asm
   {
      mrs my_cpsr, CPSR
   }
#endif

   my_cpsr &= 3 << 6;
   return 1 & ~(my_cpsr >> 7);
}


/* 21b026f0 - complete */
int FAPI_SYS_IsIsrActive(void)
{
   unsigned my_cpsr;
   
#if defined(__GNUC__)
   asm("mrs %0, CPSR": "=r" (my_cpsr));
#else
   __asm 
   {
      mrs my_cpsr, CPSR
   }
#endif

   my_cpsr &= 0x1F;      
   return ((my_cpsr == 0x10) || (my_cpsr == 0x1F))? 0: 1;
}


/* 21b0270c - complete */
void FAPI_SYS_SetMasterCpu(void)
{
   sysMasterCpuId = 0;
}


/* 21b0271c - complete */
int FAPI_SYS_IsMasterCpu(void)
{
   return !sysMasterCpuId;
}


