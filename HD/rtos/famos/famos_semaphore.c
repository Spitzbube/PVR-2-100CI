
#if 0

#include <string.h>
#include <stdio.h>
#endif
#include <fapi/drv_mmu.h>
#include "famos_memory.h"
#include "famos_thread.h"
#include "famos_semaphore.h"
#if 0
#include "drv_timer.h"
#endif
#include "famos.h"


int famos_numSemaphores; //21f71c60 


/* 21c79c90 - nearly complete */
void* famos_semaphore_create(unsigned r8)
{
   struct famos_semaphore* semaphore = 0;
   struct famos_thread* thread = famos_get_current_thread();
   
   thread->lastError = 0;
   
   unsigned sl = FAMOS_EnterCriticalSection();
   
   if ((famos_resources != 0) ||
         (0 != famosAllocateListData()))
   {
      semaphore = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm, 36);   
      
      if (semaphore == 0)
      {
         semaphore = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, 36);
      }

      if (semaphore == 0)
      {
         semaphore = famos_malloc_cached(36);         
      } 
      
      if (semaphore != 0)
      {
         semaphore = memset(semaphore, 0, 36);

         famos_numSemaphores++;
         
         sprintf(semaphore->name, "sem#%03d", famos_numSemaphores);
         
         if (famos_resources->semaphores == 0)
         {
            famos_resources->semaphores = semaphore;
            famos_resources->lastSemaphore = semaphore;
         }
         else
         {
            //insert at the end of the double-linked list
            famos_resources->lastSemaphore->next = semaphore;
            semaphore->prev = famos_resources->lastSemaphore;
            semaphore->next = 0;
            famos_resources->lastSemaphore = semaphore;
         }
      }
   }

   if (semaphore == 0)
   {
      thread->lastError = 0xffef36b5;
   }
   else
   {
      semaphore->thread = famos_get_current_thread();
      semaphore->type = FAMOS_EVENT_TYPE_SEMAPHORE; //65;
      semaphore->Data_16 = 1;
      semaphore->Data_28 = r8;
      semaphore->Data_32 = r8;           
   }

   famos_restore_flags(sl);
   
   return semaphore;
}


/* 21c79b50 - complete */
int famos_semaphore_delete(struct famos_semaphore* semaphore)
{
   int cpu_sr;
   struct famos_thread* thread = famos_get_current_thread();
   
   thread->lastError = 0;
   
   if ((semaphore == 0) ||
         (semaphore->type != FAMOS_EVENT_TYPE_SEMAPHORE)) //65))
   {
      thread->lastError = 0xffef36b8;
      return 0;
   }
   else
   {
      cpu_sr = FAMOS_EnterCriticalSection();

      if (semaphore->Data_16 != 0)
      {
         semaphore->Data_16--;
         
         if (semaphore->Data_16 != 0)
         {
            thread->event = (void*) semaphore;
            thread->state = FAMOS_THREAD_STATE_DESTROYWAIT;
            
            famos_restore_flags(cpu_sr);
            
            famosRunScheduler(0);
            
            cpu_sr = FAMOS_EnterCriticalSection();
         }
      }

      if (famos_resources != 0)
      {
         struct famos_semaphore* r0 = famos_resources->semaphores;
         
         for (; r0 != 0; r0 = r0->next)
         {
            if (semaphore == r0)
            {
               if (semaphore->prev != 0)
               {
                  semaphore->prev->next = semaphore->next;
               }
               else
               {
                  famos_resources->semaphores = r0->next;
               }
               
               if (r0->next != 0)
               {
                  r0->next->prev = r0->prev;
               }
               else
               {
                  famos_resources->lastSemaphore = r0->prev;
               }

               memset(r0, 0, sizeof(struct famos_semaphore));
               
               famos_free(r0);
               
               break;
            }
         }
      }

      thread->event = 0;         
      famos_restore_flags(cpu_sr);         
      return 1;
   }
}


/* 21c79980 - complete */
int FAMOS_GetSemaphore(struct famos_semaphore* semaphore, unsigned r6)
{
   int res;
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;
   
   if ((semaphore == 0) ||
         (semaphore->type != FAMOS_EVENT_TYPE_SEMAPHORE)) //65))
   {
      thread->lastError = 0xffef36b8;
      res = 0;
   }
   else
   {
      if ((famos_irq != 0) &&
            (famos_irq->context != 0) &&
            (r6 != 0))
      {
         thread->lastError = 0xffef36b4;
         
         famos_printf("[FAMOS] FATAL ERROR: %s() called in IRQ#%u context!\n        Stopping application in %d seconds...\n",
               "FAMOS_GetSemaphore", 
               famos_irq->currentIrq,
               5);

         unsigned long long t = FAPI_TIMER_GetTimeStamp(1000);
         
         while (1)
         {
            if ((FAPI_TIMER_GetTimeStamp(1000) - t) > 5)
            {
               famosBreakPoint();
               res = 0;
               break;
            }
         }                        
      }
      else
      {
         int cpu_sr = FAMOS_EnterCriticalSection();
         
         if (r6 != 0)
         {
            while (semaphore->Data_32 == 0)
            {
               semaphore->Data_16++;
               
               thread->event = (void*) semaphore;
               thread->state = FAMOS_THREAD_STATE_EVENTWAIT;
               thread->Data_72 = r6;
            
               if (r6 != -1)
               {
                  if (r6 < famos->Data_164)
                  {
                     r6 = famos->Data_164;
                  }
                  
                  thread->Data_72 = r6/famos->Data_164 + 1;
               }

               famos_restore_flags(cpu_sr);
               
               famosRunScheduler(0);
               
               cpu_sr = FAMOS_EnterCriticalSection();
               
               if (semaphore->type != FAMOS_EVENT_TYPE_SEMAPHORE) //65)
               {
                  break;
               }

               semaphore->Data_16--;
               
               if (thread->Data_72 == 0)
               {
                  break;
               }
            } //while (semaphore->Data_32 == 0)
         }

         if (semaphore->type != FAMOS_EVENT_TYPE_SEMAPHORE) //65)
         {
            thread->lastError = 0xffef36b3;
            res = 0;
         }
         else
         {
            if (semaphore->Data_32 != 0)
            {
               res = semaphore->Data_32--;
            }
            else
            {
               thread->lastError = 0xffef36b6;
               res = 0;
            }
            
            thread->event = 0;               
         }

         famos_restore_flags(cpu_sr);         
      }
   }

   return res;
}


/* 21c79810 - complete */
int famos_release_semaphore(struct famos_semaphore* semaphore, int r5)
{
   int irqFlags;
   unsigned long long t; //r8_r9
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;
   
   if ((semaphore == 0) ||
         (semaphore->type != FAMOS_EVENT_TYPE_SEMAPHORE)) //65))
   {
      thread->lastError = 0xffef36b8;
      r5 = 0;
   }
   else
   {
      if ((famos_irq->context != 0) &&
            (r5 != 0))
      {
         r5 = 0;
      }
      
      famosThreadAdjustPriority(thread, 1);
      
      irqFlags = FAMOS_EnterCriticalSection();
      
      t = famos_get_timestamp();
      
      while (1)
      {
         if (semaphore->Data_32 != -1)
         {
            semaphore->Data_32++;
            r5 = 1;
            break;
         }

         if (r5 == 0)
         {
            thread->lastError = 0xffef36b5;
            break;
         }

         famos_restore_flags(irqFlags);
         
         famosThreadAdjustPriority(thread, 0);
         
         FAMOS_Sleep(famos->Data_164);

         famosThreadAdjustPriority(thread, 1);
         
         if (r5 != -1)
         {
            unsigned r0 = (famos_get_timestamp() - t)/1000;
            if (r5 < r0)
            {
               thread->lastError = 0xffef36b6;
               r5 = 0;
               break;
            }
         }

         irqFlags = FAMOS_EnterCriticalSection();
      } //while (1)

      famos_restore_flags(irqFlags);
      
      famosThreadAdjustPriority(thread, 0);
      
      if ((famos_irq->context == 0) &&
            (semaphore->Data_16 > 1))
      {
         famosRunScheduler(0);
      }
   }

   return r5;
}

