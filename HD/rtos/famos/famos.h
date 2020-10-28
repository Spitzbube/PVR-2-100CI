#ifndef FAMOS_H_
#define FAMOS_H_

#define FAMOS_EVENT_TYPE_SEMAPHORE    65
#define FAMOS_EVENT_TYPE_MAILBOX      66
#define FAMOS_EVENT_TYPE_MAILQUEUE    68
#define FAMOS_EVENT_TYPE_TIMER        72


struct famos_thread;
struct famos_semaphore;
struct famos_mailbox;
struct famos_mailqueue;
struct famos_timer;

struct famos
{
   int initialized; //0
   int running; //4
   char version[64]; //8
   int versionStrLen; //72
   char Data_76[64]; //76
   int Data_140; //140
   long long startTimestamp; //144
   long long Data_152_156; //152
   unsigned Data_160; //160
   unsigned Data_164; //164
   int Data_168; //168
   struct famos_thread* idleThread; //172
   int idleCount; //176
   int fill_180; //180
   void* printThread; //184
   void* mailQueue; //188
   void* Data_192; //192
   void* reportThread; //196
   void* Data_200; //200
   void* timer; //204
   long long refreshTimestamp; //208
   unsigned refresh; //216
   //220
};

struct famos_irq
{
   int schedLock; //0
   int context; //4
   int currentIrq; //8
   int count; //12
   unsigned long long entryTime; //16
   unsigned long long totalTime; //24
   long long minTime; //32
   long long maxTime; //40
   //48
};

typedef struct
{
   struct famos_semaphore* semaphores; //0
   struct famos_semaphore* lastSemaphore; //4
   void* mailboxes; //8 
   void* lastMailbox; //12
   struct famos_mailqueue* mailqueues; //16 
   struct famos_mailqueue* lastMailqueue; //20
   struct famos_timer* timer; //24
   struct famos_timer* lastTimer; //28
   struct famos_thread* threads; //32
   struct famos_thread* lastThread; //36
   //40
} famosListDataT;

struct fapi_driver
{
   char* name; //0
   int irq; //4
   int Data_8; //8
   int (*init)(void); //12
   void (*deinit)(void); //16
   void* (*isr)(void); //20
   void (*bsr)(void*); //24
   int stackSize; //28
   int fifoSize; //32
   //36
};


extern int fapi_mmu_heap_dtcm_segment;
extern int fapi_mmu_heap_sram_segment;

extern struct famos* famos; //21f71c64
extern struct famos_irq* famos_irq; //21f71c68
extern famosListDataT* famos_resources; //21f71c6c
extern struct famos_thread* famosThreadPtrAct; //21f71c78

extern struct famos_thread Data_2206c174; //2206c174


extern int famos_printf(const char* format, ...);
extern struct famos_thread* famos_get_current_thread(void);
extern int func_21c789b0(unsigned);
extern void* famos_thread_create(int* a, 
                  unsigned stacksize, 
                  unsigned prio, 
                  void (*func)(int), 
                  int e, 
                  int f,
                  const char* thread_name);
extern void famos_thread_delete(struct famos_thread*);
extern int famos_thread_suspend(struct famos_thread*);
extern int famos_thread_relinquish(struct famos_thread*);
extern char* famos_thread_get_name(struct famos_thread*);
extern int famos_thread_get_private(struct famos_thread*);
extern int famos_get_current_thread_error(void);
extern char func_21c78838(struct famos_thread*);

extern int famos_save_flags_and_cli(void);
extern void famos_restore_flags(int cpsr);
extern char* famos_get_version(void);
extern void famos_start(void);
extern void famos_exit(int a);
extern int famos_init(void);
extern void famos_init_services(void);
extern unsigned long long famos_get_timestamp(void);
extern void famos_irq_leave(int);
extern int func_21c7a0f4(struct famos_thread* a, int b);
extern void famos_Sched(int a);
extern int famosAllocateListData(void);
extern int func_21c7a71c(struct fapi_driver* a[]);
extern void* famos_semaphore_create(unsigned);
extern int famos_semaphore_delete(struct famos_semaphore*);
extern int FAMOS_GetSemaphore(struct famos_semaphore*, unsigned);
extern int famos_release_semaphore(struct famos_semaphore*, int);
extern void* famos_mailqueue_create(unsigned, int);
extern int famos_mailqueue_destroy(struct famos_mailqueue*);
extern void famos_mailqueue_remove(struct famos_mailqueue*);
extern int FAMOS_GetMailqueue(struct famos_mailqueue*, void*, unsigned);
extern int famos_mailqueue_write(struct famos_mailqueue*, void*, int, int);
extern void* famos_mailbox_create(unsigned);
extern int famos_mailbox_destroy(struct famos_mailbox*);
extern int famos_mailbox_receive(struct famos_mailbox*, int*, unsigned);
extern int famos_mailbox_send(struct famos_mailbox*, int*, int);
extern void famos_bsr_thread(int);
extern void famos_write_bsr_fifo(void*, void (*)(void*), int);
extern void* famos_timer_create(int, struct famos_semaphore*, int);
extern int famos_timer_start(struct famos_timer*, unsigned);
extern int famos_timer_stop(struct famos_timer*);
extern int famos_timer_destroy(struct famos_timer*);


#endif /*FAMOS_H_*/
