
#include <string.h>
#include <fapi/reg_irq_ctrl.h>
#include <fapi/sys_services.h>
#include <fapi/drv_timer.h>



struct fapi_timer_handle;
struct fapi_timer_mail;

void fapi_timer_release_handle(struct fapi_timer_handle* a);
void* timerReadMailFifo(int a);
static struct fapi_timer_handle* fapi_timer_get_handle(void);
int fapi_timer_check_handle(struct fapi_timer_handle* a);
unsigned fapi_timer_get_index(unsigned);
struct fapi_timer_mail* timerWriteMailFifo(struct fapi_timer_mail* a, int b);
static int func_214ca5f4(unsigned a);


FAPI_SYS_DriverT FAPI_TIMER_Driver0 = //21efc180
{
      "TIMER0",
      5,
      2,
      FAPI_TIMER_Init,
      FAPI_TIMER_Exit,
      FAPI_TIMER_Isr0,
      FAPI_TIMER_Bsr0,
      0x400,
      2,
};

FAPI_SYS_DriverT FAPI_TIMER_Driver1 = //21efc1a4
{
      "TIMER1",
      6,
      1,
      FAPI_TIMER_Init,
      FAPI_TIMER_Exit,
      FAPI_TIMER_Isr1,
      FAPI_TIMER_Bsr1,
      0x400,
      2,
};

FAPI_SYS_DriverT FAPI_TIMER_Driver2 = //21efc1c8
{
      "TIMER2",
      7,
      0,
      FAPI_TIMER_Init,
      FAPI_TIMER_Exit,
      0,
      0,
      0,
      0,
};

struct fapi_timer
{
   int users; //0
   int type; //4
   unsigned long long counter; //8
   int resolution; //16
   struct fapi_timer_mail
   {
      unsigned long long Data_0; //0
      FAPI_TIMER_CallbackT func; //8
      uint32_t p; //12
      //16
   } fifo[16]; //20
   unsigned fifoReadPtr; //276
   unsigned fifoWritePtr; //280
   unsigned Data_284; //284
   //288
} 
timerBlockArray[3] = //21efc1ec
{
      {0, FAPI_TIMER_TYPE_RTOS, 0, 1000,},
      {0, FAPI_TIMER_TYPE_SOFT, 0, 1000,},
      {0, FAPI_TIMER_TYPE_HARD, 0, 1,},
};
unsigned timerClockFrequency = 81000000; //21efc54c


int timerInitialized; //21f62220
FAPI_SYS_SemaphoreT timerSemaphore; //21f62224
FAPI_SYS_SemaphoreT Data_21f62228; //21f62228
struct fapi_timer_handle
{
   int magic; //0
   int inUse; //4
   unsigned index; //8
   FAPI_TIMER_OpenParamsT Data_12; //12
   unsigned long long startValue; //56
   int active; //64
   unsigned Data_68; //68
   unsigned counter; //72
   //76
} timerHandleArray[8]; //21f6222c




static inline void timerBsrHandler(unsigned a)
{
   struct fapi_timer_mail* r0 = timerReadMailFifo(a);
   
   while (r0 != 0)
   {
      if (r0->func != 0)
      {
         (r0->func)(r0->Data_0, r0->p);
      }
      
      r0 = timerReadMailFifo(a);
   }
}


/* 21c3a720 - complete */
void FAPI_TIMER_Bsr0(uint32_t privData)
{
   timerBsrHandler(0);
}


/* 21c39d94 - complete */
void FAPI_TIMER_Bsr1(uint32_t privData)
{   
   timerBsrHandler(1);
}


/* 21c3a760 - complete */
void FAPI_TIMER_Bsr2(uint32_t privData)
{
   timerBsrHandler(2);
}


/* 21c3a498 - complete */
static void func_21c3a498(unsigned a, unsigned b)
{
   FREG_IRQ_CTRL_SetTimerxCntPre(a, b/1000000 - 1);
}


/* 21c3a4b0 - complete */
static void func_21c3a4b0(unsigned a, int b, int c)
{
   FREG_IRQ_CTRL_SetTimerxCntHigh(a, b - 1);
   FREG_IRQ_CTRL_SetTimerxCntLow(a, c - 1);
}


/* 21c3a4d4 - complete */
int32_t FAPI_TIMER_Init(void)
{
   unsigned i, j;
   
   if (timerInitialized != 0)
   {
      return 0;
   }
   
   timerSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (timerSemaphore == 0)
   {
      return -22009;
   }

   Data_21f62228 = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (Data_21f62228 == 0)
   {
      FAPI_SYS_DESTROY_SEMAPHORE(timerSemaphore);

      return -22009;
   }
   
   for (j = 0; j < 8; j++)
   {
      memset(&timerHandleArray[j], 0, sizeof(struct fapi_timer_handle));
   
      timerHandleArray[j].magic = 0x74696d72; //timr
      timerHandleArray[j].inUse = 0;
      timerHandleArray[j].index = -1;
   }
   
   for (i = 0; i < 3; i++)
   {
      timerBlockArray[i].fifoReadPtr = 0;
      timerBlockArray[i].fifoWritePtr = 0;
      timerBlockArray[i].Data_284 = 0;
      
      memset(timerBlockArray[i].fifo, 0, 
            16 * sizeof(struct fapi_timer_mail));
   }
      
   if (0 == FAPI_SYS_IsMasterCpu())
   {
      timerInitialized = 1;
      
      return 0;
   }

   for (i = 0; i < 3; i++)
   {
      FREG_IRQ_CTRL_SetTimerxEnable_Enable(i, 0);
      FREG_IRQ_CTRL_SetTimerxIrqReset_IrqReset(i, 1);
      
      if (i == 2)
      {
         func_21c3a498(i, timerClockFrequency);
         func_21c3a4b0(i, 0, 0);
         FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable(i, 0);
      }
      else
      {
         func_21c3a498(i, timerClockFrequency);
         func_21c3a4b0(i, timerBlockArray[i].resolution, 1);
         FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable(i, 1);
      }

      FREG_IRQ_CTRL_SetTimerxEnable_Endless(i, 1);
      FREG_IRQ_CTRL_SetTimerxEnable_Enable(i, 1);
      
      timerBlockArray[i].users = 0;
   }
   
   timerInitialized = 1;
   
   return 0;
}


/* 21c3a3a4 - complete */
void FAPI_TIMER_Exit(void)
{   
   if (timerInitialized != 0)
   {
      unsigned i;
      for (i = 0; i < 8; i++)
      {
         FAPI_TIMER_Close(&timerHandleArray[i]);      
      }
      
      FAPI_SYS_GET_SEMAPHORE(timerSemaphore, -1);
      
      for (i = 0; i < 3; i++)
      {
         FREG_IRQ_CTRL_SetTimerxEnable_Enable(i, 0);
         FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable(i, 0);
         FREG_IRQ_CTRL_SetTimerxEnable_Endless(i, 0);
      }
      
      FAPI_SYS_SET_SEMAPHORE(timerSemaphore, 0);

      FAPI_SYS_DESTROY_SEMAPHORE(timerSemaphore);
   
      FAPI_SYS_DESTROY_SEMAPHORE(Data_21f62228);
      
      timerSemaphore = 0;
      timerInitialized = 0;
   }
}


/* 21c3a0f8 - complete */
FAPI_SYS_HandleT FAPI_TIMER_Open( FAPI_TIMER_OpenParamsT* openParamsPtr, int32_t* errorCodePtr )
{
   struct fapi_timer_handle* h;
   int res = 0;
   
   if (timerInitialized == 0)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -22004;
      }
      return 0;
   }
   
   if (openParamsPtr == 0)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -22001;
      }
      return 0;
   }
   
   if ((0 == func_214ca5f4(openParamsPtr->type_)) ||
         (openParamsPtr->type_ >= 3) ||
         (openParamsPtr->resolution == 0))
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -22001;
      }
      return 0;
   }
   
   if ((int32_t)openParamsPtr->version < 0x20000)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -22010;
      }
      return 0;
   }
   
   if (openParamsPtr->version == 0x20000)
   {
      openParamsPtr->exec1InIsr = 1;
      openParamsPtr->exec2InIsr = 1;
   }
   
   FAPI_SYS_GET_SEMAPHORE(timerSemaphore, -1);
   
   h = fapi_timer_get_handle();

   if (h != 0)
   {
      memcpy(&h->Data_12, openParamsPtr, sizeof(FAPI_TIMER_OpenParamsT));
      
      unsigned index = fapi_timer_get_index(openParamsPtr->type_);
      
      if ((index > 2) ||
            (h->Data_12.resolution < timerBlockArray[index].resolution))
      {
         fapi_timer_release_handle(h);
         h = 0;
         res = -22001;
      }
      else
      {
         int r1 = openParamsPtr->resolution / timerBlockArray[index].resolution * openParamsPtr->multiplier;

         timerBlockArray[index].users++;
         
         h->index = index;
         h->Data_68 = r1;
         h->counter = 0;
         
         if (0 == FREG_IRQ_CTRL_GetTimerxEnable_Enable(h->index))
         {
            FREG_IRQ_CTRL_SetTimerxEnable_Enable(h->index, 1);
         }
         
         res = 0;
      }
   }   
   else
   {
      res = -22002;
   }

   FAPI_SYS_SET_SEMAPHORE(timerSemaphore, 0);

   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return h;
}


static inline uint32_t timerIsrHandler(unsigned a)
{
   int i;
   struct fapi_timer_mail sp;
   unsigned long long r6_r7;
   
   FREG_IRQ_CTRL_SetTimerxIrqReset_IrqReset(a, 1);
   
   timerBlockArray[a].counter++;
   
   if (timerBlockArray[a].users == 0)
   {
      return 0;
   }
   
   uint32_t r9 = 0;
   for (i = 0; i < 8; i++)
   {
      if ((timerHandleArray[i].inUse != 0) &&
            (timerHandleArray[i].index == a) &&
            (timerHandleArray[i].active != 0))
      {
         timerHandleArray[i].counter++;
         
         if (timerHandleArray[i].counter >= timerHandleArray[i].Data_68)
         {
            timerHandleArray[i].counter = 0;
            
            r6_r7 = timerBlockArray[a].counter / timerHandleArray[i].Data_68;
            
            if (timerHandleArray[i].Data_12.callback1 != 0)
            {
               if (timerHandleArray[i].Data_12.exec1InIsr != 0)
               {
                  (timerHandleArray[i].Data_12.callback1)(r6_r7, 
                        timerHandleArray[i].Data_12.optData1);
               }
               else
               {
                  memset(&sp, 0, sizeof(struct fapi_timer_mail));
                  
                  sp.Data_0 = r6_r7;
                  sp.func = timerHandleArray[i].Data_12.callback1;
                  sp.p = timerHandleArray[i].Data_12.optData1;
                  
                  r9 = (uint32_t) timerWriteMailFifo(&sp, a);                  
               }
            }

            if (timerHandleArray[i].Data_12.callback2 != 0)               
            {
               if (timerHandleArray[i].Data_12.exec2InIsr != 0)
               {
                  (timerHandleArray[i].Data_12.callback2)(r6_r7, 
                        timerHandleArray[i].Data_12.optData2);
               }
               else
               {
                  memset(&sp, 0, sizeof(struct fapi_timer_mail));
                  
                  sp.Data_0 = r6_r7;
                  sp.func = timerHandleArray[i].Data_12.callback2;
                  sp.p = timerHandleArray[i].Data_12.optData2;
                  
                  r9 = (uint32_t) timerWriteMailFifo(&sp, a);                  
               }
            }

            if (timerHandleArray[i].Data_12.mode == 1)
            {
               timerHandleArray[i].active = 0;
            }
         } //if (timerHandleArray[i].Data_72 >= timerHandleArray[i].Data_68)
      }
   }

   return r9;
}


/* 21c39f7c - complete */
uint32_t FAPI_TIMER_Isr0(void)
{
   return timerIsrHandler(0);
}


/* 21c3a920 - complete */
uint32_t FAPI_TIMER_Isr1(void)
{
   return timerIsrHandler(1);
}


/* 21c3a7a0 - complete */
uint32_t FAPI_TIMER_Isr2(void)
{
   return timerIsrHandler(2);
}


/* 21c39ef8 - complete */
struct fapi_timer_mail* timerWriteMailFifo(struct fapi_timer_mail* a, int b)
{  
   struct fapi_timer_mail* ip;
   
   if (timerBlockArray[b].Data_284 > 15)
   {
      return 0;
   }
   
   ip = &timerBlockArray[b].fifo[timerBlockArray[b].fifoWritePtr];

   memcpy(ip, a, sizeof(struct fapi_timer_mail));
   
   timerBlockArray[b].fifoWritePtr++;
   
   if (timerBlockArray[b].fifoWritePtr > 15)
   {
      timerBlockArray[b].fifoWritePtr = 0;
   }
   
   timerBlockArray[b].Data_284++;
   
   return ip;
}


/* 21c39e18 - complete */
int32_t FAPI_TIMER_Close(FAPI_SYS_HandleT handle)
{
   struct fapi_timer_handle* a = handle;
   int res = 0;
   
   FAPI_SYS_GET_SEMAPHORE(timerSemaphore, -1);
   
   if (0 != fapi_timer_check_handle(a))
   {
      FAPI_SYS_SET_SEMAPHORE(timerSemaphore, 0);
      
      FAPI_TIMER_Stop(handle);
      
      FAPI_SYS_GET_SEMAPHORE(timerSemaphore, -1);

      if (timerBlockArray[a->index].users != 0)
      {
         timerBlockArray[a->index].users--;
      }
      
      fapi_timer_release_handle(a);
   }
   else
   {
      res = -22008;
   }
   
   FAPI_SYS_SET_SEMAPHORE(timerSemaphore, 0);
   
   return res;
}


/* 21c39dd4 - complete */
void fapi_timer_release_handle(struct fapi_timer_handle* a)
{
   if (0 != fapi_timer_check_handle(a))
   {
      memset(a, 0, sizeof(struct fapi_timer_handle));
      
      a->inUse = 0;
      a->magic = 0x74696d72; //timr
      a->index = -1;
   }
}


/* 21c39cf0 - complete */
void* timerReadMailFifo(int a)
{
   int cpu_sr;
   struct fapi_timer_mail* res = 0;
   
   cpu_sr = FAPI_SYS_DISABLE_IRQ;
   
   if (timerBlockArray[a].Data_284 != 0)
   {
      unsigned readPtr = timerBlockArray[a].fifoReadPtr++;
      if (timerBlockArray[a].fifoReadPtr > 15)
      {
         timerBlockArray[a].fifoReadPtr = 0;
      }      
      
      res = &timerBlockArray[a].fifo[readPtr];      
      timerBlockArray[a].Data_284--;      
   }
   
   FAPI_SYS_ENABLE_IRQ(cpu_sr);

   return res;
}


/* 21c39c50 - complete */
int32_t FAPI_TIMER_Start(FAPI_SYS_HandleT handle)
{
   unsigned cpu_sr;
   struct fapi_timer_handle* r4 = handle;
   
   if (0 == fapi_timer_check_handle(r4))
   {
      return 0xffffaa08;
   }
   
   cpu_sr = FAPI_SYS_DISABLE_IRQ;
   
   r4->startValue = timerBlockArray[r4->index].counter / r4->Data_68;   
   r4->active = 1;
   r4->counter = 0;
   
   FAPI_SYS_ENABLE_IRQ(cpu_sr);
   
   return 0;
}


/* 21c39c28 - complete */
int32_t FAPI_TIMER_Stop(FAPI_SYS_HandleT handle)
{
   struct fapi_timer_handle* a = handle;
   
   if (0 == fapi_timer_check_handle(a))
   {
      return 0xffffaa08;
   }

   a->active = 0;

   return 0;
}


/* 21c39b94 - complete */
unsigned long long FAPI_TIMER_ReadValue(void* h)
{
   unsigned cpu_sr;
   unsigned r6;
   unsigned long long counter;
   struct fapi_timer_handle* a = h;

   if (0 == fapi_timer_check_handle(a))
   {
      return 0;
   }
   
   cpu_sr = FAPI_SYS_DISABLE_IRQ;
   
   counter = timerBlockArray[a->index].counter;
   r6 = a->Data_68;
   
   FAPI_SYS_ENABLE_IRQ(cpu_sr);
   
   return counter / r6 - a->startValue;   
}


int func_214ca5f4(unsigned a)
{
   int r0 = 0;
   unsigned i = 0;
   
   for (i = 0; i < 3; i++)
   {
      if ((timerBlockArray[i].users != 0) &&
            (a == timerBlockArray[i].type))
      {
         r0++;
      }
   }
         
   if ((a == 1) && (r0 != 0))
   {
      return 0;
   }

   if ((a == 3) && (r0 != 0))
   {
      return 0;
   }
   
   return 1;
}


struct fapi_timer_handle* fapi_timer_get_handle(void)
{
   unsigned i;
   struct fapi_timer_handle* r0 = 0;
   
   for (i = 0; i < 8; i++)
   {
      if (timerHandleArray[i].inUse == 0)
      {
         timerHandleArray[i].inUse = 1;
         timerHandleArray[i].index = -1;
         r0 = &timerHandleArray[i];
         break;
      }
   }
   
   return r0;
}


/* 21c39b40 - complete */
int fapi_timer_check_handle(struct fapi_timer_handle* a)
{
   int res = 0;
   
   if ((timerInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x74696d72) && //timr
         (a->index < 8))
   {
      res = 1;
   }
   
   return res;
}


/* 21c39b2c - complete */
uint32_t FAPI_TIMER_GetIndex(uint32_t a)
{
   unsigned i = fapi_timer_get_index(a);
   
   if (i >= 3)
   {
      i = -1;
   }
   
   return i;
}


/* 21c39ae0 - complete */
unsigned fapi_timer_get_index(unsigned type)
{
   unsigned i;
   for (i = 0; i < 3; i++)
   {
      if (timerBlockArray[i].type == type)
      {
         break; 
      }
   }
   return i;
}


/* 21c39a84 - complete */
uint64_t FAPI_TIMER_GetTimeStamp(uint32_t resolution)
{
   if ((resolution-1) > 999999)
   {
      return 0;
   }
      
   unsigned r2 = *((volatile unsigned*)0xcf00008c);
   unsigned long long r0_r1 = 
      *((volatile unsigned long long*)0xcf000088);
   unsigned r3 = *((volatile unsigned*)0xcf00008c); 
   
   if (r3 != r2)
   {
      r0_r1 = *((volatile unsigned long long*)0xcf000088);
   }
   
   return ~r0_r1 / resolution;
}


/* 21c39a5c - complete */
uint32_t FAPI_TIMER_GetResolution(uint32_t index)
{
   if (index > 2)
   {
      return 0;
   }
   
   return timerBlockArray[index].resolution;
}


/* 21c3993c - complete */
void FAPI_TIMER_SetClockFrequency(uint32_t freqencyHz)
{
   if ((freqencyHz >= 4000000) && (freqencyHz <= 256000000))
   {
      if (timerInitialized == 0)
      {
         timerClockFrequency = freqencyHz;
      }
   }
}

