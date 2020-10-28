
#include "fapi/reg_vic.h"
#include "fapi/reg_irq_ctrl.h"
#include "fapi/sys_services.h"
#include "fapi/drv_intr.h"
#include "fapi/drv_gpreg.h"

#if 0

#include "drv_timer.h"

#endif

void* FAPI_INTR_Isr31(void);
int FAPI_INTR_Init(void);

#if 0
struct fapi_driver FAPI_INTR_Driver = //21b131f8
{
      "INTR",
      -1,
      0,
      FAPI_INTR_Init, 
      FAPI_INTR_Exit,
      0,
      0,
#if 0
      0,
      0,
#endif
};

#endif

void* (*FAPI_INTR_IsrFunctionTable[32])(void); //flasher: 21b15114
int (*FAPI_INTR_BsrFunctionTable[32])(void*); //flasher: 21b15194
int (*FAPI_INTR_SwiFunctionTable[6])(int); //flasher: 21b15214

static int intrInitialized; //21b12ed4
static void* intrSemaphore; //21b12ed8

void* intrPipeArmStatusHandle; //21b12edc
void* intrPipeArmValueHandle; //21b12ee0
void* intrPipeArcStatusHandle; //21b12ee4
void* intrPipeArcValueHandle; //21b12ee8
void (*intrPipeCallbackFunction)(int); //21b12eec

#if 0
struct fapi_gpreg_param intrGpregOpenParams = //21b12ef0 
{
   0x20000, 0,
};
#endif

static struct Struct_21efb580
{
   int Data_0; //0
   int prio; //4
   int fill_8; //8
   int fill_12; //12
   int fill_16; //16
   int receiver; //20
   //24
} 
intrInfoArray[32] = //21b12ef8 
{
      {0, 0, 0, 0, 0, 0}, //0
      {0, 0, 0, 0, 0, 0}, //1
      {0, 0, 0, 0, 0, 0}, //2
      {0, 0, 0, 0, 0, 0}, //3
      {0, 0, 0, 0, 0, 0}, //4
      {0, 15, 0, 5, 0, 0}, //5
      {0, 15, 0, 5, 0, 0}, //6
      {0, 15, 0, 5, 0, 0}, //7
      {0, 15, 0, 5, 0, 0}, //8
      {0, 15, 0, 5, 0, 0}, //9
      {0, 15, 0, 5, 0, 0}, //10
      {0, 15, 0, 5, 0, 0}, //11
      {0, 15, 0, 5, 0, 0}, //12
      {0, 15, 0, 5, 0, 0}, //13
      {0, 15, 0, 5, 0, 0}, //14
      {0, 15, 0, 5, 0, 0}, //15
      {0, 15, 0, 5, 0, 0}, //16
      {0, 15, 0, 5, 0, 0}, //17
      {0, 15, 0, 5, 0, 0}, //18
      {0, 15, 0, 5, 0, 0}, //19
      {0, 15, 0, 5, 0, 0}, //20
      {0, 15, 0, 5, 0, 0}, //21
      {0, 15, 0, 5, 0, 0}, //22
      {0, 15, 0, 5, 0, 0}, //23
      {0, 15, 0, 5, 0, 0}, //24
      {0, 15, 0, 5, 0, 0}, //25
      {0, 15, 0, 5, 0, 0}, //26
      {0, 15, 0, 5, 0, 0}, //27
      {0, 15, 0, 5, 0, 0}, //28
      {0, 15, 0, 5, 0, 0}, //29
      {0, 15, 0, 5, 0, 0}, //30
      {0, 15, 0, 5, 0, 0}, //31
};





/* 21b04f8c - complete */
int FAPI_INTR_Init(void)
{   
   int reg;
   int my_cpsr;
   unsigned i = 0;
   
   if (intrInitialized != 0)
   {
      return 0;
   }
   
   intrSemaphore = (FAPI_SYS_Services.createSemaphore != 0)?
         (FAPI_SYS_Services.createSemaphore)(1): 0;
         
   if (intrSemaphore == 0)
   {
      return -17009;
   }

   for (i = 0; i < 32; i++)
   {
      FAPI_INTR_IsrFunctionTable[i] = 0;
      FAPI_INTR_BsrFunctionTable[i] = 0;
   }
   
   for (i = 0; i < 6; i++)
   {
      FAPI_INTR_SwiFunctionTable[i] = 0;
   }
      
   FREG_IRQ_CTRL_SetArmirqmask(0);
   FREG_IRQ_CTRL_SetArmirqxor(0);

   for (i = 0; i < 32; i++)
   {
      FREG_VIC_SetVectpriorityx(i, intrInfoArray[i].prio);
   }
   
   FREG_VIC_SetIntenable(-1);
   FREG_VIC_SetIntselect(0);

#if defined(__GNUC__)
   asm("mrc 15, 0, %0, cr1, cr0, 0": "=r" (reg));
   asm("mcr 15, 0, %0, cr1, cr0, 0":: "r" (reg | 0x1000000));

   // Enable IRQ and FIQ
   asm("mrs %0, CPSR": "=r" (my_cpsr));
   asm("msr CPSR_c, %0":: "r" (my_cpsr & ~0xC0));
#else
   __asm {mrc p15, 0, reg, c1, c0, 0}
   reg |= 0x1000000;
   __asm {mcr p15, 0, reg, c1, c0, 0}
   
   __asm {mrs my_cpsr, CPSR}   
   my_cpsr &= ~0xC0;
   __asm {msr CPSR_c, my_cpsr}
#endif
   
#if 0
   intrGpregOpenParams.Data_0 = 0x20000;
   intrGpregOpenParams.Data_4 = 2;      
   intrPipeArmStatusHandle = FAPI_GPREG_Open(&intrGpregOpenParams, 0);
   
   intrGpregOpenParams.Data_4 = 3;      
   intrPipeArmValueHandle = FAPI_GPREG_Open(&intrGpregOpenParams, 0);
   
   intrGpregOpenParams.Data_4 = 4;      
   intrPipeArcStatusHandle = FAPI_GPREG_Open(&intrGpregOpenParams, 0);
   
   intrGpregOpenParams.Data_4 = 5;      
   intrPipeArcValueHandle = FAPI_GPREG_Open(&intrGpregOpenParams, 0);
   
   FAPI_INTR_RegisterIrq(31, FAPI_INTR_Isr31, 0);
   FAPI_INTR_EnableIrqCtrl(31);
#endif
   
   intrInitialized = 1;
   
   return 0;
}


/* 21b04d4c - complete */
void FAPI_INTR_Exit(void)
{
   int reg;
   unsigned i;
   
   if (intrInitialized != 0)
   {
#if defined(__GNUC__)
      asm("mrc 15, 0, %0, cr1, cr0, 0": "=r" (reg));
      asm("mcr 15, 0, %0, cr1, cr0, 0":: "r" (reg & ~0x1000000));
#else
      __asm {mrc p15, 0, reg, c1, c0, 0}      
      reg &= ~0x1000000;
      __asm {mcr p15, 0, reg, c1, c0, 0}
#endif
      
      for (i = 0; i < 32; i++)
      {
         FAPI_INTR_DisableIrqCtrl(i);
      }
      
      LOCK(intrSemaphore);
      
      for (i = 0; i < 32; i++)
      {
         FAPI_INTR_IsrFunctionTable[i] = 0;
         FAPI_INTR_BsrFunctionTable[i] = 0;
      }
      
      for (i = 0; i < 6; i++)
      {
         FAPI_INTR_SwiFunctionTable[i] = 0;
      }

      FREG_IRQ_CTRL_SetArmirqmask(0);
      FREG_IRQ_CTRL_SetArmirqxor(0);

      FAPI_GPREG_Close(intrPipeArmStatusHandle);
      FAPI_GPREG_Close(intrPipeArmValueHandle);
      FAPI_GPREG_Close(intrPipeArcStatusHandle);
      FAPI_GPREG_Close(intrPipeArcValueHandle);
      
      UNLOCK(intrSemaphore);
      
      if (FAPI_SYS_Services.deleteSemaphore != 0)
      {
         (FAPI_SYS_Services.deleteSemaphore)(intrSemaphore);         
      }
      
      intrSemaphore = 0;
      intrInitialized = 0;
   }
}


/* 21b04e38 - complete */
void* FAPI_INTR_Isr31(void)
{
   int value = 0;
   
   if (1 == FAPI_GPREG_Read(intrPipeArmStatusHandle))
   {
      FREG_IRQ_CTRL_SetArmirqxor(
            FREG_IRQ_CTRL_GetArmirqxor() & ~(1 << 31));
      
      if (0 == FAPI_GPREG_Write(intrPipeArmStatusHandle, 2))
      {
         value = FAPI_GPREG_Read(intrPipeArmValueHandle);
         
         if (0 == FAPI_GPREG_Write(intrPipeArmValueHandle, 0))
         {
            if (intrPipeCallbackFunction != 0)
            {
               (intrPipeCallbackFunction)(value);
            }
         }
      }
      
      return 0;
   }
   else
   {
      PRINTF("polling request interrupt (#31) detected\n");
      
      FAPI_INTR_Exit();
      
      CPU_Polling();
      
      return 0;
   }   
}


/* 21b04f10 - complete */
int FAPI_INTR_RegisterIrq(unsigned a, void* (*b)(void), int (*c)(void*))
{
   if (a >= 32)
   {
      return -17001;      
   }
   
   if (0 != FAPI_INTR_DisableIrqCtrl(a))
   {
      return -17001;      
   }
   
   LOCK(intrSemaphore);
   
   FAPI_INTR_IsrFunctionTable[a] = b;
   FAPI_INTR_BsrFunctionTable[a] = c;

   UNLOCK(intrSemaphore);   
   
   return 0;
}


/* 21b04c50 - complete */
int FAPI_INTR_EnableIrqCtrl(unsigned a)
{
   int mask;
   int cpu_sr;
   
   if (a >= 32)
   {
      return -17001;
   }
   
   mask = (1 << a);
   
#if 1
   //ARM
   if (intrInfoArray[a].receiver & 1)
   {
      DI(cpu_sr);
                  
      if (intrInfoArray[a].Data_0 != 0)
      {
         FREG_IRQ_CTRL_SetArmirqxor(
               FREG_IRQ_CTRL_GetArmirqxor() | mask);
      }
      
      FREG_IRQ_CTRL_SetArmirqmask(
            FREG_IRQ_CTRL_GetArmirqmask() | mask);
      
      EI(cpu_sr);
   }
#else
   //ARC
   if (intrInfoArray[a].receiver & 2)
   {
      DI(cpu_sr);
                  
      if (intrInfoArray[a].Data_0 != 0)
      {
         FREG_IRQ_CTRL_SetArcirqxor(
               FREG_IRQ_CTRL_GetArcirqxor() | mask);
      }
      
      FREG_IRQ_CTRL_SetArcirqmask(
            FREG_IRQ_CTRL_GetArcirqmask() | mask);
      
      EI(cpu_sr);
   }
#endif
   
   return 0;
}


/* 21b04cd4 - complete */
int FAPI_INTR_DisableIrqCtrl(unsigned a)
{   
   int mask;
   
   if (a >= 32)
   {
      return -17001;
   }
   
   mask = 1 << a;
   
#if 1
   //ARM
   if (intrInfoArray[a].receiver & 1)
   {
      int cpu_sr;
      
      DI(cpu_sr);
            
      FREG_IRQ_CTRL_SetArmirqmask(
            FREG_IRQ_CTRL_GetArmirqmask() & ~mask);
      
      FREG_IRQ_CTRL_SetArmirqxor(
            FREG_IRQ_CTRL_GetArmirqxor() & ~mask);
      
      EI(cpu_sr);
   }
#else
   //ARC
   if (intrInfoArray[a].receiver & 2)
   {
      DI(cpu_sr);
            
      FREG_IRQ_CTRL_SetArcirqmask(
            FREG_IRQ_CTRL_GetArcirqmask() & ~mask);
      
      FREG_IRQ_CTRL_SetArcirqxor(
            FREG_IRQ_CTRL_GetArcirqxor() & ~mask);
      
      EI(cpu_sr);
   }
#endif
   
   return 0;
}


#if 0

/* 21b05138 - complete */
void FAPI_INTR_SetPriority(unsigned a, unsigned b)
{
   if (a >= 32)
   {
      return;
   }
   
   if ((b >= 5) && (b < 16))
   {
      intrInfoArray[a].prio = b;
   }
}

#endif


/* 21b0515c - complete */
void FAPI_INTR_SetReceiver(unsigned a, unsigned b)
{
   if (a >= 32)
   {
      return;
   }
   
   if (b <= 3)
   {
      intrInfoArray[a].receiver = b;
   }
}

#if 0

/* 21b05180 - complete */
int FAPI_INTR_UnregisterIrq(unsigned a)
{
   if (a >= 32)
   {
      return -17001;
   }
   
   if (0 != FAPI_INTR_DisableIrqCtrl(a))
   {
      return -17001;
   }
   
   LOCK(intrSemaphore);
   
   FAPI_INTR_IsrFunctionTable[a] = 0;
   FAPI_INTR_BsrFunctionTable[a] = 0;
   
   UNLOCK(intrSemaphore);
   
   return 0;
}


/* 21b051f8 - todo */
int FAPI_INTR_RegisterSwi(unsigned a, int (*b)(int))
{      
   if (((a & 0xffff00) != 0x800000) ||
         ((a & 0xff) >= 6))
   {
      return -17001;
   }
      
   LOCK(intrSemaphore);
   
   FAPI_INTR_SwiFunctionTable[a & 0xff] = b;
   
   UNLOCK(intrSemaphore);
   
   return 0;
}


/* 21b05260 - todo */
int FAPI_INTR_UnregisterSwi(unsigned a)
{
   if (((a & ~0xff0000ff) != 0x800000) ||
         ((a & 0xff) >= 6))
   {
      return -17001;
   }
   
   LOCK(intrSemaphore);
   
   FAPI_INTR_SwiFunctionTable[a & 0xff] = 0;
   
   UNLOCK(intrSemaphore);
   
   return 0;
}


/* 21b052c8 - complete */
int FAPI_INTR_ThrowPollingModeIrq(unsigned a)
{   
   if ((a == 1) || (a == 3))
   {
      FREG_IRQ_CTRL_SetArmirqxor(0x80000000);      
   }
   else if (a == 2)
   {
      FREG_IRQ_CTRL_SetArcirqxor(0x80000000);
   }
   else
   {
      return -17001;
   }

   return 0;
}


static int func_21c2a2a8(unsigned a)
{   
   int res = -17001;
   
   if (((a & ~0xff0000ff) != 0x800000) ||
         ((a & 0xff) >= 6))
   {
      return res;
   }
   
   return 0;
}


/* 21b05304 - todo */
int FAPI_INTR_ThrowSwi(unsigned a)
{   
   int res = -17001;
   
   if (((a & ~0xff0000ff) != 0x800000) ||
         ((a & 0xff) >= 6))
   {
      return -17001;
   }
   else
   {
      __asm
      {
         SVC      #0
      }
      
      return 0;
   } 
}


/* 21b0533c - complete */
void FAPI_INTR_RegisterPipeCallback(void (*a)(int))
{
   intrPipeCallbackFunction = a;
}


/* 21b05348 - todo */
int FAPI_INTR_WritePipe(int r5, int r4, unsigned timeout)
{
   int irqFlags;
   int res;
   unsigned long long to;
   int r4_ = 0;
   unsigned long long t = FAPI_TIMER_GetTimeStamp(1000);
   
   if (r4 == 1)
   {
      res = FAPI_GPREG_Write(intrPipeArmStatusHandle, 1);
      if (res != 0)
      {
         //FAPI_GPREG_Write(intrPipeArmStatusHandle, 0);

         return 0xffffbd97;
      }

      res = FAPI_GPREG_Write(intrPipeArmValueHandle, r5);
      if (res != 0)
      {
         //FAPI_GPREG_Write(intrPipeArmStatusHandle, 0);
         //FAPI_GPREG_Write(intrPipeArmValueHandle, 0);

         return 0xffffbd97;
      }

      DI(irqFlags);
            
      FREG_IRQ_CTRL_SetArmirqxor(
            FREG_IRQ_CTRL_GetArmirqxor() | 0x80000000);
      
      EI(irqFlags);
      
      to = timeout;
      
      while (r4_ != 2)
      {
         r4_ = FAPI_GPREG_Read(intrPipeArmStatusHandle);
         
         if ((FAPI_TIMER_GetTimeStamp(1000) - t) > to)
         {
            res = -17006;
            break;
         }
      }         

      DI(irqFlags);
            
      FREG_IRQ_CTRL_SetArmirqxor(
            FREG_IRQ_CTRL_GetArmirqxor() & ~0x80000000);
      
      EI(irqFlags);
   }
   else if (r4 == 2)
   {
      res = FAPI_GPREG_Write(intrPipeArcStatusHandle, 1);
      if (res != 0)
      {
         //FAPI_GPREG_Write(intrPipeArcStatusHandle, 0);

         return 0xffffbd97;
      }

      res = FAPI_GPREG_Write(intrPipeArcValueHandle, r5);
      if (res != 0)
      {
         //FAPI_GPREG_Write(intrPipeArcStatusHandle, 0);
         //FAPI_GPREG_Write(intrPipeArcValueHandle, 0);

         return 0xffffbd97;
      }

      DI(irqFlags);
            
      FREG_IRQ_CTRL_SetArcirqxor(
            FREG_IRQ_CTRL_GetArcirqxor() | 0x80000000);
      
      EI(irqFlags);

      to = timeout;
      
      while (r4_ != 2)
      {
         r4_ = FAPI_GPREG_Read(intrPipeArcStatusHandle);
         
         if ((FAPI_TIMER_GetTimeStamp(1000) - t) > to)
         {
            res = -17006;
            break;
         }
      }

      DI(irqFlags);
            
      FREG_IRQ_CTRL_SetArcirqxor(
            FREG_IRQ_CTRL_GetArcirqxor() & ~0x80000000);
      
      EI(irqFlags);
   }
   else
   {
      return 0xffffbd97;
   }
         
   return res;
}

#endif
