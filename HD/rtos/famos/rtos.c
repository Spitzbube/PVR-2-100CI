

#if 0

#include <fapi/sys_services.h>
#include "famos.h"
#include <rtos/rtos.h>

#endif

/* V49: 21c786cc - complete */
void RTOS_InitServices(void)
{
   famos_init_services();
}

/* V49: 21c786c8 - complete */
int RTOS_InitKernel(void)
{
   return famos_init();
}


#if 0

/* 21c78638 - complete */
int32_t rtos_get_current_thread_error(void)
{
   return famos_get_current_thread_error();
}


/* 21c7863c - todo */
void rtos_wait(int a)
{
   
}


/* 21c78644 - complete */
void rtos_thread_suspend(void* thread)
{
   famos_thread_suspend(thread);
}


/* 21c78658 - complete */
void* rtos_get_current_thread(void)
{
   return famos_get_current_thread();
}


/* 21c7865c - complete */
void rtos_delete_thread(void* a)
{
   famos_thread_delete(a);
}


/* 21c78660 - complete */
void* rtos_thread_create(int a, 
                  int stacksize, 
                  int prio, 
                  void (*func)(int), 
                  int e, 
                  int f, 
                  const char* thread_name)
{
   return famos_thread_create(a, 
            stacksize, prio, func, e, f, thread_name);
}


/* 21c7867c - complete */
void* rtos_mailbox_create(unsigned a)
{
   return famos_mailbox_create(a);
}


/* 21c78678 - complete */
void RTOS_DestroyMailbox(void* a)
{
   famos_mailbox_destroy(a);
}


/* 21c78674 - complete */
int rtos_mailbox_receive(void* a, int* b, int c)
{
   return famos_mailbox_receive(a, b, c);
}


/* 21c78670 - complete */
int rtos_mailbox_send(void* a, int* b, int c)
{
   return famos_mailbox_send(a, b, c);
}


/* 21c7868c - complete */
void* rtos_create_semaphore(unsigned a)
{
   return famos_semaphore_create(a);
}


/* 21c78688 - complete */
int rtos_delete_semaphore(void* a)
{
   return famos_semaphore_delete(a);
}


/* 21c78684 - complete */
int rtos_request_semaphore(void* a, int b)
{
   return FAMOS_GetSemaphore(a, b);
}


/* 21c78680 - complete */
int rtos_release_semaphore(void* a, int b)
{
   return famos_release_semaphore(a, b);
}


/* 21d01608 - complete */
RTOS_MailqueueT RTOS_CreateMailqueue( uint32_t queueElements,
                                      uint32_t elementBytes )
{
   return famos_mailqueue_create(queueElements, elementBytes);
}


/* 21d01604 - complete */
uint32_t RTOS_DestroyMailqueue( RTOS_MailqueueT mailqueuePtr )
{
   return famos_mailqueue_destroy(mailqueuePtr);
}


/* 21d01600 - complete */
uint32_t RTOS_GetMailqueue( RTOS_MailqueueT mailqueueHandle,
                            void* resultBuffer, uint32_t msecsTimeout )
{
   return FAMOS_GetMailqueue(mailqueueHandle, resultBuffer, msecsTimeout);
}


/* 21d015fc - complete */
uint32_t RTOS_SetMailqueue(RTOS_MailqueueT mailqueueHandle,
      void* messagePtr, uint32_t toFront,
      uint32_t msecsTimeout)
{
   return famos_mailqueue_write(mailqueueHandle, messagePtr, toFront, msecsTimeout);
}


/* 21c786b4 - complete */
void rtos_restore_flags(int a)
{
   famos_restore_flags(a);
}


/* 21c786b8 - complete */
int rtos_save_flags_and_cli(void)
{
   return famos_save_flags_and_cli();
}

#endif


/* 21c786bc - complete */
void rtos_start(void)
{
   famos_start();
}

#if 0

/* 21c786c0 - complete */
char* rtos_get_version(void)
{
   return famos_get_version();
}


/* 21c786c4 - complete */
void rtos_halt(int a)
{
   famos_exit(a);
}

#endif
