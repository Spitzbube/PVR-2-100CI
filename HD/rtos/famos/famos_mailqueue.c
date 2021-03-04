

#include <string.h>
#include <stdio.h>
#include <fapi/sys_services.h>
#include <fapi/drv_mmu.h>
#include "fapi/drv_timer.h"
#include "famos_memory.h"
#include "famos_thread.h"
#include "famos_mailqueue.h"
#include "famos.h"
#include "fapi_adapter.h___"


int famos_numMailqueues; //21f71c84


/* 21c7c880 - todo */
void* famos_mailqueue_create(unsigned queueLength, int itemSize)
{
   unsigned bufferSize;
   struct famos_mailqueue* p = 0;
   struct famos_mailqueue* mailqueue = 0;
   struct famos_thread* thread = famos_get_current_thread();
   
   thread->lastError = 0;
   
   if (queueLength > 0x1000)
   {
      return 0;
   }
   
   if (itemSize == -1)
   {
      bufferSize = queueLength * sizeof(void*);
   }
   else
   {
      itemSize = (itemSize + 3) & ~3;
      bufferSize = queueLength * itemSize;
   }
   
   int sp = FAMOS_EnterCriticalSection();
   
   if ((famos_resources != 0) ||
         (0 != famosAllocateListData()))
   {
      mailqueue = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm, sizeof(struct famos_mailqueue));      
      
      if (mailqueue == 0)
      {
         mailqueue = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, sizeof(struct famos_mailqueue));
      }

      if (mailqueue == 0)
      {
         mailqueue = famos_malloc_cached(sizeof(struct famos_mailqueue));      
      }      

      if (mailqueue != 0)
      {
         p = memset(mailqueue, 0, sizeof(struct famos_mailqueue));
      
         famos_numMailqueues++;
         
         sprintf(mailqueue->name, "mqu#%03d", famos_numMailqueues);
         
         if (famos_resources->mailqueues == 0)
         {
            famos_resources->mailqueues = mailqueue;
            famos_resources->lastMailqueue = mailqueue;
         }
         else
         {
            //insert at the end of the double-linked list
            famos_resources->lastMailqueue->next = mailqueue;
            mailqueue->prev = famos_resources->lastMailqueue;
            mailqueue->next = 0;
            famos_resources->lastMailqueue = mailqueue;
         }
      }      
   }
   
   if (p == 0)
   {
      thread->lastError = 0xffef36b5;
   }
   else
   {
      void* buffer = (FAPI_SYS_Services.mallocFunc != 0)?
            (FAPI_SYS_Services.mallocFunc)(bufferSize): 0;
         
      if (buffer == 0)
      {
         famos_mailqueue_remove(mailqueue);
         p = 0;
      }
      else
      {
         mailqueue->Data_8 = famos_get_current_thread();
         mailqueue->type = FAMOS_EVENT_TYPE_MAILQUEUE;
         mailqueue->Data_16 = 1;
         mailqueue->itemSize = itemSize;
         mailqueue->buffer = buffer;
         mailqueue->queueLength = queueLength - 1;
         mailqueue->tail = 0;
         mailqueue->head = 0;
         mailqueue->itemCount = 0;
      }
   }   
      
   famos_restore_flags(sp);
   
   return p;
}


/* 21c7c7bc - complete */
int famos_mailqueue_destroy(struct famos_mailqueue* a)
{
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;

   if ((a == 0) ||
         (a->type != FAMOS_EVENT_TYPE_MAILQUEUE))
   {
      thread->lastError = 0xffef36b8;
      return 0;
   }
   
   unsigned sr = FAMOS_EnterCriticalSection();
   
   if (a->Data_16 != 0)
   {
      a->Data_16--;
   }
   
   if (a->Data_16 != 0)
   {
      thread->state = FAMOS_THREAD_STATE_DESTROYWAIT;
      thread->event = (void*) a;
      
      famos_restore_flags(sr);
      
      famosRunScheduler(0);
      
      sr = FAMOS_EnterCriticalSection();
   }

   if (FAPI_SYS_Services.freeFunc != 0)
   {
      (FAPI_SYS_Services.freeFunc)(a->buffer);
   }
   
   famos_mailqueue_remove(a);
   
   thread->event = 0;
   
   famos_restore_flags(sr);
   
   return 1;
}


/* 21c7c6fc - complete */
void famos_mailqueue_remove(struct famos_mailqueue* a)
{
   if (famos_resources != 0)
   {
      struct famos_mailqueue* r0 = famos_resources->mailqueues;
      
      for (; r0 != 0; r0 = r0->next)
      {
         if (r0 == a)
         {
            if (a->prev != 0)
            {
               a->prev->next = a->next;
            }
            else
            {
               famos_resources->mailqueues = r0->next;
            }
            
            if (r0->next != 0)
            {
               r0->next->prev = r0->prev;
            }
            else
            {
               famos_resources->lastMailqueue = r0->prev;
            }

            memset(r0, 0, sizeof(struct famos_mailqueue));
            
            famos_free(r0);

            break;
         }
      }
   }
}


/* 21c7c490 - nearly complete */
int FAMOS_GetMailqueue(struct famos_mailqueue* mailqueue, void* b, unsigned c)
{
   int res = 0;
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;
   
   if (b == 0)
   {
      thread->lastError = 0xffef36b7;
      return 0;
   }
   
   if ((mailqueue == 0) ||
         (mailqueue->type != FAMOS_EVENT_TYPE_MAILQUEUE))
   {
      thread->lastError = 0xffef36b8;
      return 0;
   }
   
   if (mailqueue->itemSize == -1)
   {
      *((void**)b) = 0;
   }
   else
   {
      memset(b, 0, mailqueue->itemSize);
   }
   
   if ((famos_irq != 0) &&
         (famos_irq->context != 0) &&
         (c != 0))
   {
      thread->lastError = 0xffef36b4;
      
      printf("[FAMOS] FATAL ERROR: %s() called in IRQ#%u context!\n        Stopping application in %d seconds...\n",
            "FAMOS_GetMailqueue", 
            famos_irq->currentIrq,
            5);
      
      unsigned long long t = FAPI_TIMER_GetTimeStamp(1000);
      
      while (1)
      {
         if ((FAPI_TIMER_GetTimeStamp(1000) - t) > 5)
         {
            famosBreakPoint();
            break;
         }
      }      
   }
   else
   {
      unsigned sr = FAMOS_EnterCriticalSection();
      
      if (c != 0)
      {
         while (mailqueue->itemCount == 0)
         {
            mailqueue->Data_16++;
            
            thread->event = (void*) mailqueue;
            thread->state = FAMOS_THREAD_STATE_EVENTWAIT;
            thread->Data_72 = c;
            
            if (c != -1)
            {
               if (c < famos->Data_164)
               {
                  c = famos->Data_164;
               }
               
               thread->Data_72 = c/famos->Data_164 + 1;
            }

            famos_restore_flags(sr);
            
            famosRunScheduler(0);
            
            sr = FAMOS_EnterCriticalSection();

            if (mailqueue->type != FAMOS_EVENT_TYPE_MAILQUEUE)
            {
               break;
            }

            mailqueue->Data_16--;
            
            if (thread->Data_72 == 0)
            {
               break;
            }
         }
      }

      if (mailqueue->type != FAMOS_EVENT_TYPE_MAILQUEUE)
      {
         thread->lastError = 0xffef36b3;
      }
      else
      {
         if (mailqueue->itemCount == 0)
         {
            thread->lastError = 0xffef36b6;
         }
         else
         {
            if (mailqueue->itemSize == -1)
            {
               *((void**)b) = ((void**)mailqueue->buffer)[mailqueue->tail];
            }
            else
            {
               memcpy(b, (char*) mailqueue->buffer + (mailqueue->itemSize * mailqueue->tail), 
                     mailqueue->itemSize);
            }

            mailqueue->itemCount--;
            
            mailqueue->tail++;            
            if (mailqueue->tail > mailqueue->queueLength)
            {
               mailqueue->tail = 0;               
            }
            
            res = 1;
         }

         thread->event = 0;
      }

      famos_restore_flags(sr);
   }

   return res;
}


/* 21c7c2a0 - complete */
int famos_mailqueue_write(struct famos_mailqueue* a, void* b, int c, int d)
{
   unsigned sr;
   unsigned long long t;
   int res = 0;
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;

   if ((a == 0) || 
         (a->type != FAMOS_EVENT_TYPE_MAILQUEUE))
   {
      thread->lastError = 0xffef36b8;
      return 0;
   }
   
   if ((famos_irq->context != 0) && 
         (d != 0))
   {
      d = 0;
   }
   
   famosThreadAdjustPriority(thread, 1);
   
   sr = FAMOS_EnterCriticalSection();
   
   t = famos_get_timestamp();

   while (1) 
   {
      if (a->itemCount <= a->queueLength)
      {
         int index;
         
         if (c != 0)
         {
            if (a->tail != 0)
            {
               a->tail--;
            }
            else
            {
               a->tail = a->queueLength;
            }
            index = a->tail;         
         }
         else
         {
            index = a->head++;         
            if (a->head > a->queueLength)
            {
               a->head = 0;
            }
         }

         if (a->itemSize == -1)
         {
            ((void**) a->buffer)[index] = b;
         }
         else
         {
            memcpy((char*) a->buffer + (a->itemSize * index), 
                  b, a->itemSize);
         }

         a->itemCount++;
         res = 1;
         break;
      }
            
      if (d == 0)
      {
         thread->lastError = 0xffef36b5;
         break;         
      }
      
      famos_restore_flags(sr);
      
      famosThreadAdjustPriority(thread, 0);
      
      FAMOS_Sleep(famos->Data_164);
      
      famosThreadAdjustPriority(thread, 1);
      
      if (d != -1)
      {
         unsigned tWait = (famos_get_timestamp() - t)/1000;
         if (tWait > d)
         {
            thread->lastError = 0xffef36b6;
            break;
         }
      }

      sr = FAMOS_EnterCriticalSection();
   }

   famos_restore_flags(sr);
   
   famosThreadAdjustPriority(thread, 0);
   
   if ((famos_irq->context == 0) &&
         (a->Data_16 > 1))
   {
      famosRunScheduler(0);
   }
   
   return res;
}














