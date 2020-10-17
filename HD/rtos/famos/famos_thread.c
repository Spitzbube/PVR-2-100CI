
#include <string.h>
#include <stdio.h>
#include <fapi/sys_services.h>
#include <fapi/drv_mmu.h>
#include "fapi_adapter.h"
#include "famos_thread.h"
//#include "famos_memory.h"
#include "famos.h"


extern void famos_idle_thread(int);
extern void famos_report_thread(int);
extern void famos_print_thread(int);

void famos_create_stack_frame(struct famos_thread* a);


int famos_numThreads; //21f71c58 

#if 0

/* 21c78cfc - todo */
void* famos_thread_create(int* stack, //r7
                  unsigned stacksize, //sl 
                  unsigned r8, //prio, 
                  void (*func)(int), //r9 
                  int e, 
                  int f,
                  const char* thread_name)
{
   unsigned r6;
//   struct famos_thread* p = 0;
   struct famos_thread* r5 = 0;
   int sp; //cpu_sr
   int stackAlloc = 0; //sp4
   char* sp8;
   
   struct 
   {
      int fill_0[4]; //0
   } sp12;
   
   memset(&sp12, 0, 16);
   
   struct famos_thread* fp = famos_get_current_thread();
   
   fp->lastError = 0;
   
   if ((r8 > 128) &&
         (func != famos_report_thread) &&
         (func != famos_print_thread) &&
         (func != famos_bsr_thread))
   {
      fp->lastError = -1;
      //->21c78fb8
      return 0; 
   }
   //21c78d6c
   if ((stack != 0) && (stacksize == 0))
   {
      fp->lastError = -1;
      //->21c78fb8
      return 0; 
   }

   if ((stack != 0) && (stacksize < 128))
   {
      fp->lastError = -1;
      //->21c78fb8
      return 0;
   }
   //21c78db0
   if (stack == 0)
   {
      //->21c78fc0
      if (stacksize < 128) stacksize = 128;

      int r0 = stacksize*4;
      
      stack = (FAPI_SYS_Services.mallocFunc != 0)?
            (FAPI_SYS_Services.mallocFunc)(r0): 0;
            
      if (stack == 0)
      {
         //21c78ff8
         fp->lastError = -2;
         //->21c78fb8
         return 0;
      }
      
      stackAlloc = 1;
   } //if (stack == 0)
   //21c78dbc
   sp = famos_save_flags_and_cli();
   
   if ((famos_resources != 0) ||
         (0 != func_21c7a6b4()))
   {
      //21c78dd4               
      if (func == famos_idle_thread)
      {
         r5 = &Data_2206c174;
      }

      if (r5 == 0)
      {
         //21c7906c
         r5 = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm, sizeof(struct famos_thread));         
         
         if (r5 == 0)
         {
            //->21c79110
            r5 = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, sizeof(struct famos_thread));                                
         }
         //21c79084
         if (r5 == 0)
         {
            //21c79090
            r5 = famos_malloc_cached(sizeof(struct famos_thread));                     
         }         
      }
      //21c78de4
      if (r5 != 0)            
      {
         r5 = memset(r5, 0, sizeof(struct famos_thread));
         
         famos_numThreads++;
         
         sp8 = r5->name;
         sprintf(sp8, "thread#%03d", famos_numThreads);

         r6 = r8 << 8;
         
         if (famos_resources->threads == 0)
         {
            famos_resources->threads = r5;
            famos_resources->lastThread = r5;
         }
         else
         {
            struct famos_thread* r2 = famos_resources->threads;
            //21c78e38
            for (; r2 != 0; r2 = r2->next)
            {
               if (r6 < r2->priority)
               {
                  //21c790c4
                  r5->prev = r2->prev;
                  r5->next = r2;
                  if (r2->prev != 0)
                  {
                     r2->prev->next = r5;
                  }
                  r2->prev = r5;

                  if (r2 == famos_resources->threads)
                  {
                     famos_resources->threads = r5;
                  }
                  //->21c78e70
                  break;
               }
            }

            if (r2 == 0)
            {
               //21c78e50                  
               //insert at the end of the double-linked list
               famos_resources->lastThread->next = r5;
               r5->prev = famos_resources->lastThread;
               r5->next = 0;
               famos_resources->lastThread = r5; 
            }
            //21c78e70
         }
      }
   }
   //21c78e70
   if (r5 != 0)
   {
      //21c78e78
      r5->printBuffer = (FAPI_SYS_Services.mallocFunc != 0)?
            (FAPI_SYS_Services.mallocFunc)(1024): 0;

      if (r5->printBuffer != 0)
      {
         //21c78e9c
         //TODO
         {
            if (r8 > 128)
            {
               r8 = 12;
            }
            else if (r8 == 128)
            {
               r8 = 10;
            }
            else if (r8 > 95)
            {
               r8 = 8;
            }
            else if (r8 > 63)
            {
               r8 = 6;
            }
            else if (r8 > 31)
            {
               r8 = 4;
            }
            else if (r8 != 0)
            {
               r8 = 2;    
            }
         }            
         if (r8 == 0)
         {
            r6 = 0;
         }
         //21c78eb0
         memset(stack, 0, stacksize*4);
         
         stack[0] = 0xdeadbeef;
         stack[stacksize-1] = 0xbeefface;
         
         r5->Data_4 = 1;
         r5->stackBuffer = stack;
         r5->stacksize = stacksize;
         r5->stackAlloc = stackAlloc;
         r5->func = func;
         r5->param = e;
         r5->private = f;
         r5->priority = r6 | r8;
         r5->Data_60 = r8;
         r5->event = 0;
         r5->state = FAMOS_THREAD_STATE_READY;
         r5->Data_72 = 0;
         r5->lastError = 0;
         r5->Data_80 = 0;
         r5->Data_88 = 0;
         r5->Data_100_104 = 0;
         r5->Data_108_112 = 0;
         r5->CtxSwCtr = 0;
         r5->Data_120 = 0;
         
         famos_create_stack_frame(r5);
         
         r5->spPeakTop = r5->sp;
         r5->spPeakBottom = r5->stackBuffer - 2 + r5->stacksize;
         
         if (thread_name != 0)
         {
            memset(sp8, 0, 16);
            strncpy(sp8, thread_name, 15);
         }
         //21c78fa4
         famos_restore_flags(sp);
         
         famos_Sched(0);
         
         //21c78fb8
         return r5;         
      }
      //21c7900c
   }
   //21c7900c
   if (stackAlloc != 0)
   {
      //21c79018
      fp->lastError = -2;
      
      if (FAPI_SYS_Services.freeFunc != 0)
      {
         (FAPI_SYS_Services.freeFunc)(stack);
      }
      //21c79038
   }
   //21c79038
   famos_restore_flags(sp);
   //->21c78fb8
   return 0;
}


/* 21c78b48 - todo */
void famos_thread_delete(struct famos_thread* a)
{
   
}


/* 21c78ad4 - complete */
int famos_thread_suspend(struct famos_thread* a)
{
   int cpu_sr;
   struct famos_thread* r0 = famos_get_current_thread();
   
   r0->lastError = 0;
   
   if ((a == 0) ||
         (a->sp == 0) ||
         (a->Data_4 == 0))
   {
      r0->lastError = -8;
      return 0;
   }
   
   cpu_sr = famos_save_flags_and_cli();
   
   a->event = 0;
   a->Data_72 = 0;
   a->state = FAMOS_THREAD_STATE_SUSPEND;
   
   famos_restore_flags(cpu_sr);
   
   famos_Sched(0);
   
   return 1;
}


/* 21c78a4c - complete */
int famos_thread_relinquish(struct famos_thread* a)
{
   int cpu_sr;
   struct famos_thread* r0 = famos_get_current_thread();
   
   r0->lastError = 0;
   
   if ((a == 0) ||
         (a->sp == 0) ||
         (a->Data_4 == 0))
   {
      r0->lastError = -8;
      return 0;
   }
   
   cpu_sr = famos_save_flags_and_cli();
   
   a->Data_72 = 0;
   a->event = 0;
   a->state = FAMOS_THREAD_STATE_READY;
   
   famos_restore_flags(cpu_sr);
   
   if (famos_irq->context == 0)
   {
      famos_Sched(0);
   }
   
   return 1;
}


/* 21c789b0 - complete */
int func_21c789b0(unsigned r7)
{
   void* p = famos_get_current_thread();
   struct famos_thread* thread = p;
   
   thread->lastError = 0;
   
   if ((p == 0) ||
         (thread->sp == 0) ||
         (thread->Data_4 == 0))
   {
      thread->lastError = -8;      
      return 0;
   }
   
   int irqFlags = famos_save_flags_and_cli();
   
   unsigned r0 = famos->Data_164;   
   if (r7 > r0) r0 = r7;
   
   thread->state = FAMOS_THREAD_STATE_DELAYWAIT;
   thread->Data_72 = r0 / famos->Data_164 + 1;
   thread->event = 0;
   
   famos_restore_flags(irqFlags);
   
   famos_Sched(0);
   
   return 1;
}


/* 21c78948 - complete */
int func_21c78948(struct famos_thread* a)
{
   int state;
   struct famos_thread* r0 = famos_get_current_thread();
   
   r0->lastError = 0;
   
   if ((a == 0) ||
         (a->sp == 0) ||
         (a->Data_4 == 0))
   {
      r0->lastError = -8;
      return 0;
   }
   
   int cpu_sr = famos_save_flags_and_cli();
   
   state = a->state;
   
   famos_restore_flags(cpu_sr);
   
   return (state == (FAMOS_THREAD_STATE_SUSPEND | 8))? 2: 1;
}


/* 21c788ec - complete */
int famos_thread_get_private(struct famos_thread* a)
{
   int r4;
   struct famos_thread* r0 = famos_get_current_thread();
   
   r0->lastError = 0;
   
   if ((a == 0) ||
         (a->sp == 0) ||
         (a->Data_4 == 0))
   {
      r0->lastError = -8;
      return 0;
   }
   
   int cpu_sr = famos_save_flags_and_cli();
   
   r4 = a->private;
   
   famos_restore_flags(cpu_sr);
   
   return r4;
}


/* 21c78894 - complete */
char* famos_thread_get_name(struct famos_thread* a)
{
   char* name;
   struct famos_thread* r0 = famos_get_current_thread();
   
   r0->lastError = 0;
   
   if ((a == 0) ||
         (a->sp == 0) ||
         (a->Data_4 == 0))
   {
      r0->lastError = -8;
      return 0;
   }
   
   int cpu_sr = famos_save_flags_and_cli();
      
   name = a->name;
   
   famos_restore_flags(cpu_sr);
   
   return name;
}


/* 21c78828 - complete */
int famos_get_current_thread_error(void)
{
   return famos_get_current_thread()->lastError;
}


/* 21c78838 - complete */
char func_21c78838(struct famos_thread* a)
{
   char r4;
   struct famos_thread* r0 = famos_get_current_thread();
   
   r0->lastError = 0;
   
   if ((a == 0) ||
         (a->sp == 0) ||
         (a->Data_4 == 0))
   {
      r0->lastError = -8;
      return 0;
   }
   
   int cpu_sr = famos_save_flags_and_cli();
      
   r4 = (a->priority >> 8) & 0xFF;
   
   famos_restore_flags(cpu_sr);
   
   return r4;
}

#endif


/* 21c787a8 - complete */
struct famos_thread* famos_get_current_thread(void)
{   
   void* thread;
   int irqFlags;
   
   if ((famos == 0) ||
         (famos->initialized == 0) ||
         (famos->running == 0))
   {
      return &Data_2206c174;
   }   

   if ((famos_irq == 0) ||
         (famos_irq->context != 0))
   {
      return &Data_2206c174;
   }

   irqFlags = famos_save_flags_and_cli();
   
   thread = famos_Current;
   
   famos_restore_flags(irqFlags);
   
   return thread;
}


#if 0

/* 21c7aa20 - complete */
void func_21c7aa20(void)
{
   struct famos_thread* r4 = famos_get_current_thread();
   
   unsigned cpu_sr = famos_save_flags_and_cli();
   
   r4->state = FAMOS_THREAD_STATE_SUSPEND | 0x08;
   r4->Data_72 = 0;
   r4->event = 0;
   
   famos_restore_flags(cpu_sr);
   
   famos_Sched(0);
}


/* 21c7c160 - complete */
void famos_create_stack_frame(struct famos_thread* a)
{  
   void (*func)(int) = a->func;
   int param = a->param;   
   
   int* sp = &a->stackBuffer[a->stacksize];
   
   sp--;
            
   while ((int)sp & 0x07)
   {
      sp--;
   }
   
   *--sp = (int) func;
   *--sp = (int) func_21c7aa20;
   *--sp = 0xdead0012;
   *--sp = 0xdead0011;
   *--sp = 0xdead0010;
   *--sp = 0xdead0009;
   *--sp = 0xdead0008;
   *--sp = 0xdead0007;
   *--sp = 0xdead0006;
   *--sp = 0xdead0005;
   *--sp = 0xdead0004;
   *--sp = 0xdead0003;
   *--sp = 0xdead0002;
   *--sp = 0xdead0001;
   *--sp = param;
   *--sp = 31;
   
   a->sp = sp;
}

#endif





