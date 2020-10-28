


#include <string.h>
#include <stdio.h>
#include <fapi/drv_mmu.h>
#include "famos_memory.h"
#include "famos.h"
#include "famos_thread.h"
#include "famos_timer.h"



int famos_numTimer; //21f71c88 


/* 21c7cc5c - complete */
void* famos_timer_create(int cyclic, struct famos_semaphore* semaphore, int c_)
{
   struct famos_timer* timer = 0;
   struct famos_thread* thread = famos_get_current_thread();
   
   thread->lastError = 0;
   
   unsigned sl = famos_save_flags_and_cli();   

   if ((famos_resources != 0) ||
         (0 != famosAllocateListData()))
   {
      timer = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm,
            sizeof(struct famos_timer));   
      
      if (timer == 0)
      {
         timer = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, 
               sizeof(struct famos_timer));
      }

      if (timer == 0)
      {
         timer = famos_malloc_cached(sizeof(struct famos_timer));         
      } 

      if (timer != 0)
      {
         timer = memset(timer, 0, sizeof(struct famos_timer));

         famos_numTimer++;
         
         sprintf(timer->name, "tmr#%03d", famos_numTimer);
         
         if (famos_resources->timer == 0)
         {
            famos_resources->timer = timer;
            famos_resources->lastTimer = timer;
         }
         else
         {
            //insert at the end of the double-linked list
            famos_resources->lastTimer->next = timer;
            timer->prev = famos_resources->lastTimer;
            timer->next = 0;
            famos_resources->lastTimer = timer;
         }
      }
   }   
   
   if (timer == 0)
   {
      thread->lastError = 0xffef36b5;
   }
   else
   {
      timer->thread = famos_get_current_thread();
      timer->type = FAMOS_EVENT_TYPE_TIMER;
      timer->Data_16 = 1;
      timer->counter = 0;
      timer->active = 0;
      timer->cyclic = cyclic;
      timer->reload = 0;
      timer->semaphore = semaphore;
   }
   
   famos_restore_flags(sl);
   
   return timer;
}


/* 21c7cb58 - complete */
int famos_timer_destroy(struct famos_timer* a)
{
   struct famos_timer* t;
   struct famos_thread* thread = famos_get_current_thread();
   
   thread->lastError = 0;
   
   if ((a == 0) ||
         (a->type != FAMOS_EVENT_TYPE_TIMER))
   {
      thread->lastError = 0xffef36b8;
      return 0;
   }
   
   unsigned sr = famos_save_flags_and_cli();

   if (famos_resources != 0)
   {           
      for (t = famos_resources->timer; t != 0; t = t->next)
      {
         if (a == t)
         {
            if (a->prev != 0)
            {
               a->prev->next = a->next;
            }
            else
            {
               famos_resources->timer = t->next;
            }
            
            if (t->next != 0)
            {
               t->next->prev = t->prev;
            }
            else
            {
               famos_resources->lastTimer = t->prev;
            }

            memset(t, 0, sizeof(struct famos_timer));
            
            famos_free(t);
            
            break;
         }
      }
   }
   
   famos_restore_flags(sr);
   
   return 1;
}


/* 21c7cac4 - complete */
int famos_timer_start(struct famos_timer* a, unsigned b)
{
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;

   if ((a == 0) ||
         (a->type != FAMOS_EVENT_TYPE_TIMER))
   {
      thread->lastError = 0xffef36b8;
      return 0;
   }
   
   unsigned sr = famos_save_flags_and_cli();
   
   if (b < famos->Data_164)
   {
      b = famos->Data_164;
   }
   
   a->counter = b / famos->Data_164;
   a->reload = b / famos->Data_164;
   a->active = 1;
   
   famos_restore_flags(sr);
   
   return 1;
}


/* 21c7ca6c - complete */
int famos_timer_stop(struct famos_timer* a)
{
   struct famos_thread* thread = famos_get_current_thread();

    thread->lastError = 0;

    if ((a == 0) ||
          (a->type != FAMOS_EVENT_TYPE_TIMER))
    {
       thread->lastError = 0xffef36b8;
       return 0;
    }

    unsigned sr = famos_save_flags_and_cli();

    a->active = 0;

    famos_restore_flags(sr);
    
    return 1;
}




