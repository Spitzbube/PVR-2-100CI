

#include <string.h>
#include <stdio.h>
#include <fapi/drv_mmu.h>
#include "famos_memory.h"
#include "famos_thread.h"
#include "famos_mailbox.h"
#include "drv_timer.h"
#include "famos.h"



int famos_numMailboxes; //21f71c5c



/* 21c79674 - complete */
void* famos_mailbox_create(unsigned r8)
{
   struct famos_mailbox* mailbox = 0;
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;
   
   if ((r8 - 17) < -18)
   {
      thread->lastError = 0xffef36b4;
      return 0;
   }

   int irqFlags = famos_save_flags_and_cli();
   
   if ((famos_resources != 0) ||
         (0 != func_21c7a6b4()))
   {
      mailbox = famos_malloc_segment(FAPI_MMU_HeapHandleDTcm, 
            sizeof(struct famos_mailbox));         
      
      if (mailbox == 0)
      {
         mailbox = famos_malloc_segment(FAPI_MMU_HeapHandleSRam, 
               sizeof(struct famos_mailbox));
      }

      if (mailbox == 0)
      {
         mailbox = famos_malloc_cached(sizeof(struct famos_mailbox));                  
      }         

      if (mailbox != 0)
      {
         mailbox = memset(mailbox, 0, sizeof(struct famos_mailbox));
         
         famos_numMailboxes++;
         
         sprintf(mailbox->event.name, "mbx#%03d", famos_numMailboxes);
      
         if (famos_resources->mailboxes == 0)
         {
            famos_resources->mailboxes = mailbox;
            famos_resources->lastMailbox = mailbox;
         }
         else
         {
            //insert at the end of the double-linked list
            struct famos_event* last = famos_resources->lastMailbox;
            last->next = mailbox;
            mailbox->event.prev = famos_resources->lastMailbox;
            mailbox->event.next = 0;
            famos_resources->lastMailbox = mailbox;
         }
      }      
   }

   if (mailbox == 0)
   {
      thread->lastError = 0xffef36b5;
   }
   else
   {
      mailbox->event.thread = famos_get_current_thread();
      mailbox->event.type = FAMOS_EVENT_TYPE_MAILBOX; //66;
      mailbox->event.Data_16 = 1;
      mailbox->busy = 0;
      mailbox->size = r8;
   }
      
   famos_restore_flags(irqFlags);

   return mailbox;
}


int famos_mailbox_destroy(struct famos_mailbox* mailbox)
{
   return 0;
}


/* 21c792e8 - nearly complete */
int famos_mailbox_receive(struct famos_mailbox* mailbox, int* data, unsigned r7)
{
   int res;
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;

   if (data == 0)
   {
      thread->lastError = 0xffef36b7;
      res = 0;
      //->21c7933c
   }
   else
   {
      if ((mailbox == 0) ||
            (mailbox->event.type != FAMOS_EVENT_TYPE_MAILBOX)) //66))
      {
         //21c79330
         thread->lastError = 0xffef36b8;
         res = 0;
         //->21c7933c
      }
      else
      {
         //21c79344
         if (mailbox->size == -1)
         {
            data[0] = 0;
         }
         else
         {
            memset(data, 0, mailbox->size);
         }
         //21c79360
         if ((famos_irq != 0) &&
               (famos_irq->context != 0) &&
               (r7 != 0))
         {
            //21c7948c
            thread->lastError = 0xffef36b4;
            
            printf("[FAMOS] FATAL ERROR: %s() called in IRQ#%u context!\n        Stopping application in %d seconds...\n",
                  "FAMOS_GetMailbox", 
                  famos_irq->currentIrq,
                  5);
            
            unsigned long long t = FAPI_TIMER_GetTimeStamp(1000);
            
            while (1)
            {
               //21c794b8
               if ((FAPI_TIMER_GetTimeStamp(1000) - t) > 5)
               {
                  //21c794d0
                  func_21b01c88();
                  res = 0;
                  //->21c7933c
                  break;
               }
            }                        
         }
         else
         {
            //21c79380
            int cpu_sr = famos_save_flags_and_cli();
            
            if (r7 != 0)
            {
               //21c793b8
               while (mailbox->busy == 0)
               {
                  //21c793c4
                  mailbox->event.Data_16++;
                  mailbox->data[0] = 0;
                                    
                  thread->event = &mailbox->event;
                  thread->state = FAMOS_THREAD_STATE_EVENTWAIT;
                  thread->Data_72 = r7;
                  
                  if (r7 != -1)
                  {
                     if (r7 < famos->Data_164)
                     {
                        r7 = famos->Data_164;
                     }
                     
                     thread->Data_72 = r7/famos->Data_164 + 1;
                  }
                  //21c79410
                  famos_restore_flags(cpu_sr);
                  
                  famos_Sched(0);
                  
                  cpu_sr = famos_save_flags_and_cli();
                  //21c79424
                  if (mailbox->event.type != FAMOS_EVENT_TYPE_MAILBOX) //66)
                  {
                     //->21c7939c
                     break;
                  }

                  mailbox->event.Data_16--;
                  
                  if (thread->Data_72 == 0)
                  {
                     //->21c7944c
                     break;
                  }
               } //while (mailbox->busy == 0)
               //->21c79390
            }
            //21c79390
            if (mailbox->event.type != FAMOS_EVENT_TYPE_MAILBOX) //66)
            {
               //21c7939c
               thread->lastError = 0xffef36b3;
               res = 0;
               //->21c793a8
            }               
            else
            {
               //21c7944c
               if (mailbox->busy != 0)
               {
                  //21c79464
                  if (mailbox->size == -1)
                  {
                     //21c79470
                     data[0] = mailbox->data[0];
                  }
                  else
                  {
                     //21c794ec
                     memcpy(data, mailbox->data, mailbox->size);
                  }
                  res = 1;
               }
               else
               {
                  thread->lastError = 0xffef36b6;
                  res = 0;
                  //->21c7947c
               }
               //21c7947c
               mailbox->busy = 0;
               thread->event = 0;
               //->21c793a8
            }            
            //21c793a8
            famos_restore_flags(cpu_sr);
            //21c793b0
         }
      }
   }
   //21c7933c
   return res;
}


/* 21c79158 - nearly complete */
int famos_mailbox_send(struct famos_mailbox* mailbox, int* data, int r4)
{
   int irqFlags;
   unsigned long long t; //r8_r9
   
   struct famos_thread* thread = famos_get_current_thread();

   thread->lastError = 0;
   
   if ((mailbox == 0) ||
         (mailbox->event.type != FAMOS_EVENT_TYPE_MAILBOX)) //66))
   {
      //21c7918c
      thread->lastError = 0xffef36b8;
      r4 = 0;
   }
   else
   {
      //21c791a0
      if ((famos_irq->context != 0) &&
            (r4 != 0))
      {
         r4 = 0;
      }
      
      func_21c7a0f4(thread, 1);
      
      irqFlags = famos_save_flags_and_cli();
      //21c791c8
      t = famos_get_timestamp();
      
      while (1)
      {
         if (mailbox->busy == 0)
         {
            //->21c79254
            mailbox->busy = 1;
            
            if (mailbox->size == -1)
            {
               mailbox->data[0] = data;
            }
            else
            {
               memcpy(mailbox->data, data, mailbox->size);
            }
            
            r4 = 1;
            //->21c79278
            break;
         }
         //21c791e0
         if (r4 == 0)
         {
            //21c792b8
            thread->lastError = 0xffef36b5;
            //->21c79278
            break;
         }
         //21c791ec
         famos_restore_flags(irqFlags);
         
         func_21c7a0f4(thread, 0);
         
         func_21c789b0(famos->Data_164);

         func_21c7a0f4(thread, 1);
         
         if (r4 != -1)
         {
            //21c79220
            unsigned tWait = (famos_get_timestamp() - t)/1000;
            if (tWait > r4)
            {
               //21c792c4
               thread->lastError = 0xffef36b6;
               r4 = 0;
               //->21c79278
               break;
            }
            //21c79240
         }
         //21c79240
         irqFlags = famos_save_flags_and_cli();
      }
      //21c79278
      famos_restore_flags(irqFlags);
      
      func_21c7a0f4(thread, 0);
      
      if ((famos_irq->context == 0) &&
            (mailbox->event.Data_16 > 1))
      {
         //21c792ac
         famos_Sched(0);
      }
      //21c79198
   }
   //21c792b0
   return r4;
}











