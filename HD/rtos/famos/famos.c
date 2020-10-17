
#if 0

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fapi/sys_services.h>
#include "cpu_polling.h"
#include "reg_irq_ctrl.h"
#include "drv_uart.h"
#endif
#include "fapi_adapter.h"
#include "fapi/drv_mmu.h"
#if 0
#include "drv_intr.h"
#include "drv_gpreg.h"
#include "drv_timer.h"
#include "drv_mmu_heap.h"
#endif
#include "famos_thread.h"
#include "famos_semaphore.h"
#if 0
#include "famos_mailbox.h"
#include "famos_mailqueue.h"
#include "famos_timer.h"
#include "famos_interrupt.h"
#endif
#include "famos.h"

#if 0

extern void func_21b00870(void);
extern void func_21b00874(void);



int Data_21efe4a4; //21efe4a4
int Data_21efe4a8; //21efe4a8
void (*Data_21efe4ac[])(int) = //21efe4ac
{
      0,
      ARM1176_INTR_UndefFunction, 
      ARM1176_INTR_SwiFunction,  
      ARM1176_INTR_PrefetchFunction, 
      ARM1176_INTR_AbortFunction, 
      0,
      ARM1176_INTR_IrqFunction,
      ARM1176_INTR_FiqFunction,
};


//int famos_numThreads; //21f71c58 -> famos_thread.c 
//int famos_numMailboxes; //21f71c5c -> famos_mailbox.c
//int famos_numSemaphores; //21f71c60 -> famos_semaphore.c 
#endif
struct famos* famos; //21f71c64
struct famos_irq* famos_irq; //21f71c68
struct Struct_21f71c6c* famos_resources; //21f71c6c
#if 0
struct Struct_21f71c70
{
   int fill_0[128]; //0
   int Data_512[256]; //512
   int Data_1536[2048]; //1536
   int Data_9728[1280]; //9728
   //14848
}* Data_21f71c70; //21f71c70
struct Struct_21f71c74
{
   void (*Data_0[8])(void); //0
   unsigned Data_32; //32
   void (*Data_36[4])(void); //36
   unsigned Data_52; //52
   //56
}* Data_21f71c74; //21f71c74
#endif
struct famos_thread* famos_Current; //21f71c78
#if 0
struct famos_thread* famos_HighRdy; //21f71c7c
//int famos_numMailqueues; //21f71c84 -> famos_mailqueue.c

void* Data_2206c064; //2206c064
FAPI_TIMER_OpenParamsT Data_2206c068; //2206c068
void (*famos_driver_bsr[32])(void); //2206c094
struct fapi_driver** famos_drivers; //2206c114
void* Data_2206c118; //2206c118
#endif
struct Struct_21f19580 famos_services; //2206c11c
struct famos_thread Data_2206c174; //2206c174
#if 0
int famos_bsr_flags[32]; //2206c1f0
void* (*famos_driver_isr[32])(void); //2206c270
struct famos_bsr_threads
{
   struct famos_bsr_fifo
   {
      void* p; //0
      void (*bsr)(void*); //4
      //8
   }* fifo; //0
   unsigned fifoSize; //4
   unsigned readPtr; //8
   unsigned writePtr; //12
   unsigned count; //16
   unsigned peak; //20
   struct famos_thread* thread; //24
   //28
} famos_bsr_threads[32]; //2206c2f0

#endif

void* famos_malloc_segment(int a, int b);
void* famos_malloc_cached(int a);
#if 0
void famos_bsr_thread(int a);
void famos_print_report(void);




/* 21c79e00 - complete */
void famos_idle_thread(int a)
{   
   while (1)
   {
      //printf("famos->idleCount: %d\n", famos->idleCount);
      
      famos->idleCount++;
   }
}


/* 21c79e1c - complete */
void func_21c79e1c(void)
{   
   struct famos_thread* thread = famos_resources->threads;
   
   for (; thread != 0; thread = thread->next)
   {      
      void* event = thread->event;
      
      if (thread->state == FAMOS_THREAD_STATE_EVENTWAIT) 
      {
         if (event != 0)
         {
            if ((thread->event->type == FAMOS_EVENT_TYPE_SEMAPHORE) &&
                  (((struct famos_semaphore*)event)->Data_32 != 0))
            {
               thread->state = FAMOS_THREAD_STATE_READY;
            }
            else if ((thread->event->type == FAMOS_EVENT_TYPE_MAILBOX) &&
                  (((struct famos_mailbox*)event)->busy == 1))
            {
               thread->state = FAMOS_THREAD_STATE_READY;
            }
            else if ((thread->event->type == 68) &&
                  (((struct famos_mailbox*)event)->busy != 0))
            {
               thread->state = FAMOS_THREAD_STATE_READY;
            }
         }
      }
      else if (thread->state == FAMOS_THREAD_STATE_DESTROYWAIT)
      {
         if (((struct famos_event*)event)->Data_16 == 0)
         {
            thread->state = FAMOS_THREAD_STATE_READY;
         }
      }
   }
}


/*
*********************************************************************************************************
*                              FIND HIGHEST PRIORITY TASK READY TO RUN
*
* Description: This function is called by other uC/OS-II services to determine the highest priority task
*              that is ready to run.  The global variable 'OSPrioHighRdy' is changed accordingly.
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 1) This function is INTERNAL to uC/OS-II and your application should not call it.
*              2) Interrupts are assumed to be disabled when this function is called.
*********************************************************************************************************
*/
/* 21c79ee4 - complete */
void famos_SchedNew(void)
{
   if (famos_irq != 0)
   {
      func_21c79e1c();
      
      famos_HighRdy = famos_Current;
      
      if (famos_irq->schedLock == 0)
      {
         struct famos_thread* thread;
         unsigned prio = 0;
         for (thread = famos_Current->next; thread != 0; thread = thread->next)
         {
            if ((thread->Data_4 != 0) &&
                  (thread->state == FAMOS_THREAD_STATE_READY) &&
                  ((thread->priority & 0xFFFF) > prio))
            {
               famos_HighRdy = thread;
               prio = thread->priority & 0xFFFF;
            }
         }

         for (thread = famos_resources->threads; thread != 0; thread = thread->next)
         {
            if (thread == famos_Current)
            {
               break;
            }
            
            if ((thread->Data_4 != 0) &&
                  (thread->state == FAMOS_THREAD_STATE_READY) &&
                  ((thread->priority & 0xFFFF) > prio))
            {
               famos_HighRdy = thread;
               prio = thread->priority & 0xFFFF;
            }
         }

         if ((famos_HighRdy == famos_Current) &&
               (famos_Current->state != FAMOS_THREAD_STATE_READY))
         {
            famos_HighRdy = famos->idleThread;
         }
      }

      if (famos_Current != 0)
      {
         if (famos_Current->sp < famos_Current->spPeakTop)
         {
            famos_Current->spPeakTop = famos_Current->sp;
         }
         
         if (famos_Current->sp > famos_Current->spPeakBottom)
         {
            famos_Current->spPeakBottom = famos_Current->sp;
         }
      }

      if (famos_HighRdy != 0)
      {
         if (famos_HighRdy->sp < famos_HighRdy->spPeakTop)
         {
            famos_HighRdy->spPeakTop = famos_HighRdy->sp;
         }
         
         if (famos_HighRdy->sp > famos_HighRdy->spPeakBottom)
         {
            famos_HighRdy->spPeakBottom = famos_HighRdy->sp;
         }
      }
      
      if (famos_HighRdy != 0)
      {
         int r2 = famos_HighRdy->priority & 0xFF00;
         int r3 = famos_HighRdy->priority & 0xFF0000;
         int r0 = famos_HighRdy->priority & 0xFF;
         if (r0 == 0) 
         {
            r0 = famos_HighRdy->Data_60;
         }
         famos_HighRdy->priority = r3 | r2 | r0;
      }
   }
}


/* 21c7a0a4 - complete */
void func_21c7a0a4(void)
{
   unsigned i;
   
   for (i = 0; i < Data_21f71c74->Data_52; i++)
   {
      if (Data_21f71c74->Data_36[i] != 0)
      {
         (Data_21f71c74->Data_36[i])();
      }
   }
}


/* 21c7a0f4 - complete */
int func_21c7a0f4(struct famos_thread* a, int b)
{
   return 1;
}


/* 21c7a0fc - complete */
int mailqueue_write(void* a, void* b, int c)
{
   struct famos_mailqueue* q = a;
   
   int res = famos_mailqueue_write(q, b, 0, c);
      
   if (res == 0)
   {
      res = famos_get_current_thread_error();
      if (res < 0)
      {
         return res;
      }
   }
         
   return q->itemSize & ~0x80000000; 
}


/* 21c7a13c - complete */
int mailqueue_read(void* a, void* b, int c)
{
   struct famos_mailqueue* q = a;
   
   int res = FAMOS_GetMailqueue(q, b, c);
      
   if (res == 0)
   {
      res = famos_get_current_thread_error();
      if (res < 0)
      {
         return res;
      }
   }
         
   return q->itemSize & ~0x80000000; 
}


/* 21c7a178 - complete */
static int semaphore_request(void* a, int b)
{
   int res = FAMOS_GetSemaphore(a, b);
   
   if ((res == 0) &&
         (famos_get_current_thread_error() < 0))
   {
      return -1;
   }
      
   return (res - 1) & ~0x80000000;
}


/* 21c7a174 - complete */
static int semaphore_release(void* a, int b)
{
   return famos_release_semaphore(a, b);
}


/* 21c7a1d8 - complete */
void* famos_malloc_uncached(int a)
{
   return FAPI_MMU_Malloc(FAPI_MMU_HeapHandleSys0, a);
}

#endif

/* 21c7a1c4 - complete */
void* famos_malloc_cached(int a)
{
   return FAPI_MMU_Malloc(FAPI_MMU_HeapHandleSys1, a);
}


/* 21c7a1c0 - complete */
void* famos_malloc_segment(int a, int b)
{   
   return FAPI_MMU_Malloc(a, b);
}

#if 0

/* 21c7a1a8 - complete */
void famos_free(void* a)
{   
   FAPI_MMU_Free(FAPI_MMU_GetSegment(a), a);
}


/* 21c7a1ec - complete */
int famos_printf(const char* format, ...)
{
   int len;
   va_list ap;   
   struct famos_thread* r6;   
   struct famos_thread* printThread;
   
   if (famos_irq->context == 0)
   {
      r6 = famos_get_current_thread();      
      FAMOS_GetSemaphore(famos->Data_192, -1);
   }
   else
   {
      r6 = famos->idleThread;
   }

   printThread = famos->printThread;
   va_start(ap, format); 
   
   len = vsprintf(r6->printBuffer, format, ap);
   
   if (len >= 1024)
   {
      printf("\nERROR: thread specific print buffer overflow (%u>%u), exiting...\n\n", len, 1024);      
      famos_exit(-1);
   }

   if ((famos->running != 0) &&
         (printThread->state != FAMOS_THREAD_STATE_SUSPEND))
   {
      famos_mailqueue_write(famos->mailQueue, 
            r6->printBuffer, 0, 0);
   }
   else
   {
      fputs(r6->printBuffer, stdout); 
      fflush(stdout); 
   }

   if (famos_irq->context == 0)
   {
      famos_release_semaphore(famos->Data_192, 0);
   }

   return len;
}


/* 21c7a318 - complete */
void famos_print_thread(int a)
{
   char buffer[256];
   
   while (1)
   {
      FAMOS_GetMailqueue(famos->mailQueue, buffer, -1);
   
      buffer[255] = 0;
      
      fputs(buffer, stdout); 
      fflush(stdout); 
   }
}


/* 21c7a36c - complete */
unsigned long long famos_get_timestamp(void)
{   
   return FAPI_TIMER_GetTimeStamp(1);
}


/* 21c7a374 - todo */
void famos_timer_func(void)
{
   unsigned i;
   unsigned long long t;
   struct famos_timer* timer;
   struct famos_thread* thread;
   int refresh = 0;
   unsigned prio = famos_Current->priority & 0xFF;
   
   if ((famos_Current != 0) &&
         (prio != 0))
   {
      prio--;
   }
      
   famos_Current->priority = prio |
      (famos_Current->priority & 0xFF00) |
      (famos_Current->priority & 0xFF0000); 
   
   t = famos_get_timestamp();
   
   if (((t - famos->refreshTimestamp) > famos->refresh) &&
         (famos->Data_168 == 0))
   {
      refresh = 1;
   }

   timer = famos_resources->timer;
   
   for (; timer != 0; timer = timer->next)
   {
      if (timer->active != 0)
      {
         if (timer->counter != 0)
         {
            timer->counter--;
         }
         
         if (timer->counter == 0)
         {
            if ((timer->semaphore != 0) &&
                  (timer->semaphore->type == FAMOS_EVENT_TYPE_SEMAPHORE))
            {
               timer->semaphore->Data_32++;
            }

            if (timer->cyclic == 0)
            {
               timer->active = 0;
            }
            
            timer->counter = timer->reload;
         }
      }
   } //for (; timer != 0; timer = timer->next)

   if (famos_resources != 0)
   {
      thread = famos_resources->threads;
      
      for (; thread != 0; thread = thread->next)
      {
         switch (thread->state)
         {
            case FAMOS_THREAD_STATE_DELAYWAIT:
               if (thread->Data_72 != 0)
               {
                  thread->Data_72--;
               }
               
               if (thread->Data_72 == 0)
               {
                  thread->state = FAMOS_THREAD_STATE_READY;
               }
               break;
               
            case FAMOS_THREAD_STATE_EVENTWAIT:
               if ((thread->Data_72-1) < -2)
               //if ((thread->Data_72-3) < 0)
               //if ((thread->Data_72 > 0) && (thread->Data_72 < 3))
               {
                  thread->Data_72--;
                  
                  if (thread->Data_72 == 0)
                  {
                     thread->state = FAMOS_THREAD_STATE_READY;
                  }
               }
               break;
         }

         if (refresh != 0)
         {
            thread->Data_108_112 = 0;
            thread->Data_100_104 = 0;
         }
      } //for (; thread != 0; thread = thread->next)
   }

   if (refresh != 0)
   {
      t = famos_get_timestamp();
      
      famos->refreshTimestamp = t;      
      famos_irq->minTime = -1;
      famos_irq->totalTime = 0;
      famos_irq->entryTime = t;
      famos_irq->maxTime = 0; 
   }

   for (i = 0; i < Data_21f71c74->Data_32; i++)
   {
      if (Data_21f71c74->Data_0[i] != 0)
      {
         (Data_21f71c74->Data_0[i])();
      }
   }
}


/* 21c7a5dc - complete */
void famos_irq_entry(int irq)
{
   famos_irq->context++;
   famos_irq->currentIrq = irq;
   famos_irq->count++;
   
   unsigned long long t = famos_get_timestamp();
   
   famos_Current->Data_100_104 -= famos_Current->Data_108_112;
   famos_Current->Data_100_104 += t;
   
   famos_irq->entryTime = t;
}


/* 21c7a650 - todo */
int famos_enable_driver_irq(void)
{
   unsigned i;
   unsigned err;
   
   famos_save_flags_and_cli();
      
   for (i = err = 0; famos_drivers[i] && !err; i++)
   {            
      if (famos_drivers[i]->irq >= 0)
      {
         err = FAPI_INTR_EnableIrqCtrl(famos_drivers[i]->irq);         
      }      
   }
   
   return !err;
}

#endif


/* 21c7a6b4 - complete */
int func_21c7a6b4(void)
{   
   famos_resources = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm, 
         sizeof(struct Struct_21f71c6c));
   
   if (famos_resources == 0)
   {
      return 0;
   }
   
   memset(famos_resources, 0, 
      sizeof(struct Struct_21f71c6c));
   
   return 1;
}

#if 0

/* 21c7a71c - todo */
int famos_init_drivers(struct fapi_driver* a[])
{
   int i;
   struct fapi_driver* drv;
   
   famos_drivers = a;

   int err = 0;
   
   for (i = 0; famos_drivers[i] && !err; i++)
   {      
      drv = famos_drivers[i];
      
      if (drv->irq >= 0)
      {
         famos_driver_isr[drv->irq] = drv->isr;
         famos_driver_bsr[drv->irq] = drv->bsr;            
         famos_bsr_flags[drv->irq] = (drv->Data_8 == 2)? 1: 0;
      }

      err = (drv->init)();         
      
#if 0
      if (err)
      {
         rtos_printf("ERROR: ""%s"" driver initialization failed. (err=%d)\n",
               drv->name, err);
      }      
#endif
   }
   
   for (i = 0; (drv = famos_drivers[i++]) && !err; )
   {                           
      if ((drv->irq >= 0) &&
            (drv->bsr != 0) &&
            (drv->Data_8 != 2) &&
            (famos_bsr_threads[drv->irq].thread == 0))
      {
         struct famos_bsr_threads* r8;
         char thread_name[16] = {0};
         
         sprintf(thread_name, "bsr:int%02d", drv->irq);
               
         r8 = &famos_bsr_threads[drv->irq];
         
         r8->fifo = famos_malloc_cached(drv->fifoSize * sizeof(struct famos_bsr_fifo));         
         r8->fifoSize = drv->fifoSize;
         r8->readPtr = 0;
         r8->writePtr = 0;
         r8->count = 0;
         r8->peak = 0;
         r8->thread = 
            famos_thread_create(0, 
                  drv->stackSize, 
                  243, //prio, 
                  famos_bsr_thread,  
                  0, 
                  drv->irq,
                  thread_name);
         
         r8->thread->Data_88 = r8;
         
         famos_thread_suspend(r8->thread);

         if ((r8->thread == 0) ||
               (r8->fifo == 0))
         {
            famos_thread_delete(r8->thread);
            
            famos_free(r8->fifo);
            
            memset(r8, 0, 28);
         
            err = -2;
            break;
         }
      }
   }

   famos_driver_isr[31] = FAPI_INTR_Isr31;
   famos_driver_bsr[31] = 0;
   famos_bsr_flags[31] = 0;
      
   return err;
}


/*
*********************************************************************************************************
*                                              SCHEDULER
*
* Description: This function is called by other uC/OS-II services to determine whether a new, high
*              priority task has been made ready to run.  This function is invoked by TASK level code
*              and is not used to reschedule tasks from ISRs (see OSIntExit() for ISR rescheduling).
*
* Arguments  : none
*
* Returns    : none
*
* Notes      : 1) This function is INTERNAL to uC/OS-II and your application should not call it.
*              2) Rescheduling is prevented when the scheduler is locked (see OS_SchedLock())
*********************************************************************************************************
*/
/* 21c7a950 - complete */
void famos_Sched(int r8)
{
   if ((famos != 0) &&
         (famos->running != 0))
   {
      int irqFlags = famos_save_flags_and_cli();
      
      if (r8 == 0)
      {        
         famos_Current->Data_100_104 = famos_get_timestamp() + 
            famos_Current->Data_100_104 - 
            famos_Current->Data_108_112;
      }

      famos_SchedNew();
      
      famos_HighRdy->Data_108_112 = famos_get_timestamp();
      
      //Inc. # of context switches to this task
      famos_HighRdy->CtxSwCtr++;
      
      //No Ctx Sw if current task is highest rdy
      if (famos_Current != famos_HighRdy)
      {
         //Perform a context switch
         if (r8 != 0)
         {
            func_21b00870(); //OS_TASK_SW
         }
         else
         {
            func_21b00874(); //OS_TASK_SW
         }
      }
      
      famos_restore_flags(irqFlags);
   }      
}


/* 21c7aa6c - complete */
void famos_irq_leave(int a)
{
   unsigned long long t = 
      famos_get_timestamp() - famos_irq->entryTime;
   
   famos_irq->totalTime += t;
   
   if (famos_irq->context != 0)
   {
      famos_irq->context--;
   }
   
   famos_irq->currentIrq = 0;   
   
   if (famos_irq->minTime > t)
   {
      famos_irq->minTime = t;
   }

   if (famos_irq->maxTime < t)
   {
      famos_irq->maxTime = t;
   }
   
   if (a != 0)
   {
      famos_Sched(1);
   }
   else
   {
      famos_Current->Data_108_112 = famos_get_timestamp();
   }
}


/* 21c7ab50 - todo */
void famos_write_bsr_fifo(void* p, void (*bsr)(void*), int irq)
{
   if (famos != 0)
   {
      struct famos_bsr_threads* r5 = &famos_bsr_threads[irq]; 
      
      if ((r5->count < r5->fifoSize) &&
            (r5->thread != 0))
      {
         unsigned r0 = famos_save_flags_and_cli();
                           
#if 0
         struct famos_bsr_fifo* ip = &r5->fifo[r5->writePtr];         
         ip->p = p;
         ip->bsr = bsr;
#else
         r5->fifo[r5->writePtr].p = p;
         r5->fifo[r5->writePtr].bsr = bsr;
#endif
              
         r5->writePtr++;
         
         if (r5->writePtr >= r5->fifoSize)
         {
            r5->writePtr = 0;
         }
         
         r5->count++;
         
         if (r5->count > r5->peak)
         {
            r5->peak = r5->count;
         }
         
         struct famos_thread* r4 = r5->thread;
         
         famos_restore_flags(r0);
         
         if (r4->state == FAMOS_THREAD_STATE_SUSPEND)
         {
            famos_thread_relinquish(r5->thread);
         }
      }
      else
      {
         FAPI_SYS_PRINT_MSG("[FAMOS] BSR thread ""%s"" fifo overflow detected <%d/%d>\n",
               famos_thread_get_name(r5->thread),
               r5->count,
               r5->fifoSize);
      }
   }
}


/* 21c7ac48 - todo */
void famos_bsr_thread(int a)
{   
   struct famos_bsr_threads* r5 = 
      &famos_bsr_threads[famos_thread_get_private(famos_get_current_thread())]; 

   while (1)
   {            
      if (r5->count != 0)
      {    
         void (*bsr)(void*) = r5->fifo[r5->readPtr].bsr;
         
         if (bsr != 0)
         {
            void* p = r5->fifo[r5->readPtr].p;
            
            r5->fifo[r5->readPtr].p = 0;
            r5->fifo[r5->readPtr].bsr = 0;
            
            (bsr)(p);
         }
         
         unsigned r6 = famos_save_flags_and_cli();
         
         r5->readPtr++;
         if (r5->readPtr >= r5->fifoSize)
         {
            r5->readPtr = 0;
         }
         
         r5->count--;
               
         if (r5->count == 0)
         {
            struct famos_thread* r0 = famos_get_current_thread();
            
            r0->event = 0;
            r0->Data_72 = 0;
            r0->state = FAMOS_THREAD_STATE_SUSPEND;
            
            famos_restore_flags(r6);
            
            famos_Sched(0);
         }
         else
         {
            famos_restore_flags(r6);
            
            func_21c789b0(1);
         }
      }

      if (r5->count == 0)
      {         
         famos_thread_suspend(famos_get_current_thread());         
      }
   }
}


/* 21c7ad24 - complete */
void famos_report_thread(int a)
{
   while (1)
   {
      FAMOS_GetSemaphore(famos->Data_200, -1);
      
      famos_print_report();
   }
}

/* 21c7ad48 - complete */
char* famos_get_version(void)
{
   if (famos == 0)
   {
      return 0;
   }
   
   if (famos->initialized == 0)
   {
      return 0;
   }
   
   return famos->version;
}


#endif


/* 21c7ad7c - complete */
/* Disable Interrupts */
int famos_save_flags_and_cli(void)
{
   int cpsr;
   
   asm("mov %[result], #0;"
       "mrs %[result], CPSR" 
         : [result] "=r" (cpsr): );

   // Disable IRQ and FIQ
   asm("msr CPSR_c, %0" 
         : : "r" (cpsr | 0xC0));
   
   return cpsr;
}


/* 21c7ad7c - complete */
/* Enable Interrupts */
void famos_restore_flags(int cpsr)
{
   asm("msr CPSR_c, %0": : "r" (cpsr));
}

#if 0

/* 21c7ad98 - complete */
void famos_lock_scheduler(void)
{
   unsigned sr = famos_save_flags_and_cli();
   
   if (famos_irq != 0)
   {
      if (famos_irq->schedLock == 0)
      {
         famos_irq->schedLock++;
      }
   }
   
   famos_restore_flags(sr);
}


/* 21c7adcc - complete */
void famos_unlock_scheduler(void)
{
   unsigned sr = famos_save_flags_and_cli();
   
   if (famos_irq != 0)
   {
      if (famos_irq->schedLock == 1)
      {
         famos_irq->schedLock--;
      }
   }
   
   famos_restore_flags(sr);
}


/* 21c7ae00 - nearly complete */
int famos_check_stack(void)
{
   static struct famos_thread* thread; //21f71c80

   thread = famos_resources->threads;

   for (; thread != 0; thread = thread->next)
   {
      //->21c7afb0
      Data_21efe4a4 = 1;
      
      if ((thread->Data_4 != 0) &&
            (thread->stackBuffer != 0))
      {
         if (thread->stackBuffer[0] != 0xdeadbeef)
         {
            FAPI_SYS_PRINT_MSG("FATAL ERROR: thread stack top corrupted\n");
         
            Data_21efe4a4 = 0;
         }
         //21c7b004
         if (thread->stackBuffer[thread->stacksize - 1] != 0xbeefface)
         {
            FAPI_SYS_PRINT_MSG("FATAL ERROR: thread stack bottom corrupted\n");
         
            Data_21efe4a4 = 0;
         }
         //21c7b048
         if (thread->sp < thread->stackBuffer)
         {
            FAPI_SYS_PRINT_MSG("FATAL ERROR: thread stack pointer corrupted\n");
         
            Data_21efe4a4 = 0;
         }
         //21c7b07c
         if (thread->spPeakTop <= thread->stackBuffer)
         {
            FAPI_SYS_PRINT_MSG("FATAL ERROR: thread stack top overflow\n");
         
            Data_21efe4a4 = 0;
         }
         //21c7b0b0
         if ((int) (thread->spPeakBottom) >= 
               thread->stackBuffer[thread->stacksize - 1])
         {
            //21c7ae30
            FAPI_SYS_PRINT_MSG("FATAL ERROR: thread stack bottom underflow\n");
            //21c7ae4c
            Data_21efe4a4 = 0;
         }
         //21c7b0d4
         if (Data_21efe4a4 == 0)
         {
            //->21c7ae54
            Data_21efe4a8 = 0;
            
            FAPI_SYS_PRINT_MSG("thread             = 0x%08x\n", thread);
            FAPI_SYS_PRINT_MSG("->name             = ""%s""\n", thread->name);
            FAPI_SYS_PRINT_MSG("->sp               = 0x%08x\n", thread->sp);
            FAPI_SYS_PRINT_MSG("->spPeakTop        = 0x%08x\n", thread->spPeakTop);
            FAPI_SYS_PRINT_MSG("->spPeakBottom     = 0x%08x\n", thread->spPeakBottom);
            FAPI_SYS_PRINT_MSG("->stackBuffer      = 0x%08x\n", thread->stackBuffer);
            FAPI_SYS_PRINT_MSG("->stackBuffer[0]   = 0x%08x\n", thread->stackBuffer[0]);
            FAPI_SYS_PRINT_MSG("->stackBuffer[1]   = 0x%08x\n", thread->stackBuffer[1]);
            FAPI_SYS_PRINT_MSG("->stackBuffer[n-2] = 0x%08x\n", 
                  thread->stackBuffer[thread->stacksize-2]);
            FAPI_SYS_PRINT_MSG("->stackBuffer[n-1] = 0x%08x\n", 
                  thread->stackBuffer[thread->stacksize-1]);
         }
         //->21c7af9c
      }
      //->21c7af9c
   } //for (; thread != 0; thread = thread->Data_8)
   //->21c7b0ec
   return Data_21efe4a8;
}


/* 21c7b1b4 - nearly complete */
void famos_print_report(void)
{
   struct famos_thread* currentThread;
   struct famos_thread* thread;
   char* threadState;
   char* threadEvent;
   int r4;
//   long long sp28_32;
   long long cpuIsr; //sp36_40
   int irqFlags; //sp44
   unsigned long long uptime; //sp48_52
   int cpuKernel; //sp56
   int cpuUser; //sp60
   int cpuIdle; //sp64
   int sp68;
   int sp72;
//   long sp76_80;
   FAPI_MMU_HeapSegmentInfoT sp84;
   
   famos->Data_168 = 1;
   
   currentThread = famos_get_current_thread();
   
   famos->Data_152_156 = famos_get_timestamp() - 
      famos->startTimestamp;
   
   famos_get_timestamp();
   
   uptime = famos->Data_152_156;
   
   r4 = famos->Data_140 - famos->versionStrLen;
   
   FAPI_SYS_PRINT_MSG("\n");
   FAPI_SYS_PRINT_MSG("****%-*s****\n", famos->versionStrLen,
         &famos->Data_76[r4]);
   FAPI_SYS_PRINT_MSG("*** %-*s ***\n", famos->versionStrLen,
         famos->version);
   FAPI_SYS_PRINT_MSG("****%-*s****\n", famos->versionStrLen,
         &famos->Data_76[r4]);
   FAPI_SYS_PRINT_MSG("\n");
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");
   FAPI_SYS_PRINT_MSG("Priority Thread            CPU State       Event         Ticks Stack  Activated\n");
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");

   irqFlags = famos_save_flags_and_cli();

   unsigned long long r7_r8 = famos_get_timestamp() - 
      famos->refreshTimestamp;
   
   thread = famos_resources->threads;   
   while (thread != 0)
   {
      //21c7b344
      if (thread == currentThread)
      {
         //->21c7ba0c
         thread->Data_100_104 = famos_get_timestamp() - 
            thread->Data_108_112;
         //->21c7b34c
      }
      //21c7b34c
      thread->Data_120 = thread->Data_100_104 * 100 / r7_r8;
      
      thread = thread->next;
   }
   //21c7b37c
   famos_restore_flags(irqFlags);
   
   thread = famos_resources->lastThread;
   
   if (thread == 0)
   {
      cpuUser = 0;
      cpuIdle = 0;
      sp68 = 100;
      //->21c7b4e8
   }
   else
   {
      //21c7b3a8
      cpuUser = 0;
      cpuIdle = 0;
      
      while (thread != 0)
      {
         //21c7b3b4
         if (thread->Data_4 != 0)
         {            
            //21c7b3c0
            switch (thread->state)
            {
               case FAMOS_THREAD_STATE_RUNNING:
                  //21c7b9dc
                  threadState = "Running";
                  break;
               
               case FAMOS_THREAD_STATE_READY:
                  //21c7b3d8
                  threadState = "Ready";
                  break;
                  
               case FAMOS_THREAD_STATE_SUSPEND:
                  //21c7b3e4
                  threadState = "Suspended";
                  break;
               
               case 24:
                  //21c7b3c8
                  threadState = "Finished";
                  break;
                  
               case FAMOS_THREAD_STATE_DELAYWAIT:
                  //21c7ba04
                  threadState = "DelayWait";
                  break;
                  
               case FAMOS_THREAD_STATE_EVENTWAIT:
                  //21c7b9e8
                  threadState = "EventWait";
                  break;
                  
               case FAMOS_THREAD_STATE_DESTROYWAIT:
                  //21c7b9f4
                  threadState = "DestroyWait";
                  break;   
                  
               default:
                  //21c7b3f4
                  threadState = "Undefined";
                  break;
            }
            //21c7b3f8
            if (thread->event == 0)
            {
               threadEvent = "none";
            }
            else
            {
               threadEvent = thread->event->name;
            }
            
            int stack = 100 - 
               4*(thread->spPeakTop - thread->stackBuffer) * 100 /
               (4*thread->stacksize);
            
            //"Priority Thread            CPU State       Event         Ticks Stack  Activated\n"
            FAPI_SYS_PRINT_MSG("%c %3d.%02d %-16s %3d%% %-11s %-9s %9d %4d%% %10d\n",
                  (thread == famos_Current)? '*': ' ',
                  (thread->priority & 0xff00) >> 8, //Prio MSB
                  thread->priority & 0xFF, //Prio LSB
                  thread->name, 
                  thread->Data_120, //CPU
                  threadState, 
                  threadEvent,
                  thread->Data_72, //Ticks
                  stack, //Stack
                  thread->CtxSwCtr); //Activated
            //21c7b4a0
         }
         //21c7b4a0
         if (thread == famos->idleThread)
         {
            cpuIdle = thread->Data_120;
         }
         else
         {
            cpuUser += thread->Data_120;
         }
         
         thread = thread->prev;
      } 
      //21c7b4d4
      sp68 = (100 - cpuUser) - cpuIdle;
   }
   //21c7b4e8
   irqFlags = famos_save_flags_and_cli();
   
   long long r8_r9 = famos_get_timestamp();
   long long r6_r7 = famos->refreshTimestamp;
   unsigned long long r4_r5 = famos_irq->totalTime;
   
   famos_restore_flags(irqFlags);

   int cpsr;
   asm volatile ("mrs %[result], CPSR" 
         : [result] "=r" (cpsr): );
   
   cpuIsr = r4_r5 * 100 / (r8_r9 - r6_r7);   
   cpuKernel = sp68 - cpuIsr; 

   FAPI_SYS_PRINT_MSG("         %-16s %3d%%\n",
         "famos:kernel", cpuKernel);
   
   FAPI_SYS_PRINT_MSG("         %-16s %3d%% %48d\n",
         "famos:isr", (long)cpuIsr,
         famos_irq->count);
   
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");
   
   sp72 = 0;
   //21c7b5d0   
   unsigned long long h = uptime / 3600000000;
   uptime -= (h * 3600000000);
   unsigned long long min = uptime / 60000000;
   uptime -= (min * 60000000);
   unsigned long long sec = uptime / 1000000;
   uptime -= (sec * 1000000);
   unsigned long usec = uptime / 1000;
   
   FAPI_SYS_PRINT_MSG("SYS uptime.....: %ldh %ldm %ld.%lds\n",
         (unsigned)h, (unsigned)min, (unsigned)sec, usec);
   
   FAPI_SYS_PRINT_MSG("CPU usage......: user=%d%% kernel=%d%% isr=%d%% idle=%d%% timer=%dms refresh=%dms\n",
         cpuUser, 
         cpuKernel, 
         (long)cpuIsr, 
         cpuIdle, 
         famos->Data_164, 
         famos->refresh / 1000);
   
   FAPI_SYS_PRINT_MSG("ISR duration...: min=%ldus max=%ldus\n",
         (unsigned) famos_irq->minTime,
         (unsigned) famos_irq->maxTime);
   
   FAPI_SYS_PRINT_MSG("\n");
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");
   FAPI_SYS_PRINT_MSG("Priority Thread           FifoSize MaxUsage ActUsage\n");
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");

   thread = famos_resources->lastThread;
   
   while (thread != 0)
   {
      //21c7b800
      if ((thread->Data_4 != 0) &&
            (thread->Data_88 != 0))
      {
         FAPI_SYS_PRINT_MSG("  %3d.%02d %-16s %8d %8d %8d\n",
               (thread->priority & 0xFF00) >> 8, //Prio MSB
               thread->priority & 0xFF, //Prio LSB
               thread->name, //Thread
               thread->Data_88->Data_4, //FifoSize
               thread->Data_88->Data_20, //MaxUsage
               thread->Data_88->Data_16); //ActUsage
      }
      
      thread = thread->prev;
   }
   //21c7b800
   FAPI_SYS_PRINT_MSG("\n");
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");
   FAPI_SYS_PRINT_MSG("Heap Cached AlignBits Size(MB)    Address Available(B)\n");
   FAPI_SYS_PRINT_MSG("-------------------------------------------------------------------------------\n");
   
   FAPI_MMU_GetSegmentInfo(FAPI_MMU_HeapHandleDTcm, &sp84);
   
   FAPI_SYS_PRINT_MSG("%-4s %6s %9d %8d 0x%08x %12d\n",
         "dtcm", //Heap
         (sp84.params.memoryMode == 2)? "yes": "no", //Cached 
         sp84.params.alignmentBits,           
         sp84.params.sizeMBytes, //Size(MB)     
         sp84.startAddress,
         sp84.bytesAvailable); 
   
   FAPI_MMU_GetSegmentInfo(FAPI_MMU_HeapHandleSRam, &sp84);
   
   FAPI_SYS_PRINT_MSG("%-4s %6s %9d %8d 0x%08x %12d\n",
         "sram", //Heap
         (sp84.params.memoryMode == 2)? "yes": "no", //Cached 
         sp84.params.alignmentBits,           
         sp84.params.sizeMBytes, //Size(MB)     
         sp84.startAddress,
         sp84.bytesAvailable); 

   FAPI_MMU_GetSegmentInfo(FAPI_MMU_HeapHandleSys0, &sp84);
   
   FAPI_SYS_PRINT_MSG("%-4s %6s %9d %8d 0x%08x %12d\n",
         "sys0", //Heap
         (sp84.params.memoryMode == 2)? "yes": "no", //Cached 
         sp84.params.alignmentBits,           
         sp84.params.sizeMBytes, //Size(MB)     
         sp84.startAddress, 
         sp84.bytesAvailable); 

   FAPI_MMU_GetSegmentInfo(FAPI_MMU_HeapHandleSys1, &sp84);
   
   FAPI_SYS_PRINT_MSG("%-4s %6s %9d %8d 0x%08x %12d\n",
         "sys1", //Heap
         (sp84.params.memoryMode == 2)? "yes": "no", //Cached 
         sp84.params.alignmentBits,           
         sp84.params.sizeMBytes, //Size(MB)     
         sp84.startAddress, 
         sp84.bytesAvailable); 

   FAPI_SYS_PRINT_MSG("\n");
   
   famos_check_stack();

   famos->Data_168 = 0;   
}


/* 21c7bae8 - complete */
void famos_start(void)
{
   if (famos == 0) return;

   if (famos->initialized == 0) return;
   
   Data_2206c064 = FAPI_TIMER_Open(&Data_2206c068, 0);
   
   if (Data_2206c064 == 0) return;
   
   if (0 == famos_enable_driver_irq()) return;
   
   famos_SchedNew();

   famos_Current = famos_HighRdy;

   famos->running = 1;
      
   func_21b007f0();
}


/* 21c7bb6c - complete */
void famos_exit(int a)
{   
   printf("famos_exit\n");
   
   famos_save_flags_and_cli();   
   
   FAPI_INTR_Exit();
   
   _exit(a);
}


/* 21c7bb84 - nearly complete */
int famos_init(void)
{
   FAPI_GPREG_OpenParamsT sp12;
   unsigned i;
   
   if ((famos != 0) && 
         (famos->initialized != 0))
   {
      return 0;
   }

   ARM1176_INTR_Initialise();
   
   famos_irq = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm, 
         sizeof(struct famos_irq));
   
   if (famos_irq == 0)
   {
      return 0;
   }

   memset(famos_irq, 0, sizeof(struct famos_irq));
   
   famos_irq->minTime = -1;
   famos_irq->maxTime = 0;
   
   if ((famos_resources == 0) &&
         (0 == func_21c7a6b4()))
   {
      return 0;
   }

   famos = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, 
         sizeof(struct famos));      
   if (famos == 0)
   {
      return 0;
   }
   
   memset(famos, 0, sizeof(struct famos));
   
   famos->startTimestamp = famos_get_timestamp();
   famos->refreshTimestamp = famos_get_timestamp();
   famos->refresh = 5000000;
   
   sprintf(famos->version,
         "%s v%d.%d (%s)",
         "FAMOS", 2, 1, "ARM/GCC");
   
   famos->versionStrLen = strlen(famos->version);

   for (i = 0; i < 64; i++)
   {
      famos->Data_76[i] = '*';
   }
   famos->Data_76[i-1] = 0;

   famos->Data_140 = strlen(famos->Data_76);
   
   Data_21f71c74 = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, 
         sizeof(struct Struct_21f71c74));
   if (Data_21f71c74 == 0)
   {
      return 0;
   }
   
   memset(Data_21f71c74, 0, sizeof(struct Struct_21f71c74));
   
   Data_21f71c70 = famos_malloc_cached(sizeof(struct Struct_21f71c70));
   if (Data_21f71c70 == 0)
   {
      return 0;
   }
   
   memset(Data_21f71c70, 0, sizeof(struct Struct_21f71c70));
   
   sp12.version = FAPI_GPREG_VERSION;
   sp12.index = 0;
   Data_2206c118 = FAPI_GPREG_Open(&sp12, 0);
   if (Data_2206c118 == 0)
   {
      return 0;
   }
   
   FAPI_GPREG_UnlockMutex(Data_2206c118);
   
   famos->Data_200 = famos_semaphore_create(0);
   if (famos->Data_200 == 0)
   {
      return 0;
   }

   famos->Data_192 = famos_semaphore_create(1);
   if (famos->Data_192 == 0)
   {
      return 0;
   }
   
   famos->timer = famos_timer_create(1, famos->Data_200, 0);
   if (famos->timer == 0)
   {
      return 0;
   }
   
   famos->mailQueue = famos_mailqueue_create(128, 256);
   if (famos->mailQueue == 0)
   {
      return 0;
   }
   
   famos->idleThread = famos_thread_create(
         Data_21f71c70->Data_512,
         256, 0, famos_idle_thread, 0, 0,
         "famos:idle");
   
   if (famos->idleThread == 0)
   {
      return 0;
   }

   famos->reportThread = famos_thread_create(
         Data_21f71c70->Data_1536,
         2048, 242, famos_report_thread, 5000, 0,
         "famos:report");
   
   if (famos->reportThread == 0)
   {
      return 0;
   }

   famos->printThread = famos_thread_create(
         Data_21f71c70->Data_9728,
         1280, 241, famos_print_thread, 0, 0,
         "famos:print");
   
   if (famos->printThread == 0)
   {
      return 0;
   }
               
   Data_2206c068.version = FAPI_TIMER_VERSION;
   Data_2206c068.type_ = 1;
   Data_2206c068.mode = 2;
   Data_2206c068.resolution = 1000000;
   Data_2206c068.multiplier = 1;
   Data_2206c068.callback1 = 0;
   Data_2206c068.optData1 = 0;
   Data_2206c068.callback2 = 0;
   Data_2206c068.optData2 = 0;
   Data_2206c068.exec1InIsr = 0;
   Data_2206c068.exec2InIsr = 0;

   int timerIndex  = FAPI_TIMER_GetIndex(1);
   
   famos->Data_160 = 1000000 / FAPI_TIMER_GetResolution(timerIndex);
   famos->Data_164 = 1000 / famos->Data_160;
   
   famos->initialized = 1;
   
   return 1;
}

#endif

/* V49: 21c7bfd0 - complete */
void famos_init_services(void)
{
#if 0
   famos_drivers = 0;
   famos_Current = 0;
   famos_HighRdy = 0;

   memset(&Data_2206c174, 0, sizeof(Data_2206c174));
   memset(&famos_driver_isr, 0, sizeof(famos_driver_isr));
   memset(&famos_driver_bsr, 0, sizeof(famos_driver_bsr));
   memset(&famos_bsr_flags, 0, sizeof(famos_bsr_flags));

   famos_services.lock = famos_lock_scheduler;
   famos_services.unlock = famos_unlock_scheduler;
   famos_services.sleep = func_21c789b0;
#endif
   famos_services.disableIrq = famos_save_flags_and_cli;
   famos_services.enableIrq = famos_restore_flags;
   famos_services.createSemaphore = famos_semaphore_create;
   famos_services.deleteSemaphore = famos_semaphore_delete;
#if 0
   famos_services.requestSemaphore = semaphore_request;
   famos_services.releaseSemaphore = semaphore_release;
   famos_services.createMailqueue = famos_mailqueue_create;
   famos_services.destroyMailqueue = famos_mailqueue_destroy;
   famos_services.getMailqueue = mailqueue_read;
   famos_services.setMailqueue = mailqueue_write;
   famos_services.getPhysAddr = FAPI_MMU_GetPhysAddr;
   famos_services.getVirtAddr = FAPI_MMU_GetVirtAddr;
   famos_services.mallocUncached = famos_malloc_uncached;
   famos_services.Data_64 = famos_malloc_uncached;
   famos_services.mallocCached = famos_malloc_cached;
   famos_services.mallocSegment = famos_malloc_segment;
   famos_services.free = famos_free;
   famos_services.printf = famos_printf;
   famos_services.initDrivers = famos_init_drivers;
#endif
   
   FAPI_SYS_SetServices(&famos_services);
}


