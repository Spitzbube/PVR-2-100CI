#ifndef RTOS_H_
#define RTOS_H_


#define RTOS_SUSPEND        FAPI_SYS_SUSPEND
#define RTOS_NO_SUSPEND     FAPI_SYS_NO_SUSPEND


typedef struct
{
   
}* RTOS_MailboxT;


typedef struct 
{
   
}* RTOS_ThreadT;


typedef struct
{
   
}* RTOS_SemaphoreT;


typedef void* RTOS_MailqueueT;


extern void* rtos_thread_create(int a,
                  int stacksize,
                  int prio,
                  void (*func)(int),
                  int e,
                  int f,
                  const char* thread_name);
extern void rtos_delete_thread(void* a);
extern int32_t rtos_get_current_thread_error(void);


extern void* RTOS_CreateSemaphore(uint32_t);
extern void* rtos_create_semaphore(unsigned a);
extern int rtos_delete_semaphore(void* a);
extern int rtos_request_semaphore(void* a, int b);
extern int rtos_release_semaphore(void* a, int b);


extern void* RTOS_CreateMailbox(uint32_t);
extern void* rtos_mailbox_create(unsigned a);
extern void RTOS_DestroyMailbox(void* a);
extern int rtos_mailbox_send(void* a, int* b, int c);
extern int rtos_mailbox_receive(void* a, int* b, int c);


extern RTOS_MailqueueT RTOS_CreateMailqueue( uint32_t queueElements,
                                             uint32_t elementBytes );
extern uint32_t RTOS_DestroyMailqueue( RTOS_MailqueueT mailqueuePtr );
extern uint32_t RTOS_GetMailqueue( RTOS_MailqueueT mailqueueHandle,
                                 void* resultBuffer, uint32_t msecsTimeout );
extern uint32_t RTOS_SetMailqueue(RTOS_MailqueueT mailqueueHandle,
      void* messagePtr, uint32_t toFront,
      uint32_t msecsTimeout);


extern int32_t RTOS_GetLastError(void);


#endif /*RTOS_H_*/
