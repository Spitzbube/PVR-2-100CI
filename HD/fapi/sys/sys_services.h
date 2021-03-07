#ifndef SYS_SERVICES_H_
#define SYS_SERVICES_H_

#include <fapi/sys_driver.h>

struct FAPI_SYS_Services
{
    void (*lockSchedulerFunc)(void); //0
    void (*unlockSchedulerFunc)(void); //4
    void (*sleepFunc)(uint32_t mSecs); //8
   unsigned (*disableIrq)(void); //12
   void (*enableIrq)(unsigned); //16
   void* (*createSemaphore)(int); //20
   void (*deleteSemaphore)(void*); //24
   int (*requestSemaphore)(void*, int); //28
   void (*releaseSemaphore)(void*, int); //32
   void* (*mallocFunc)(size_t size); //60??
#if 0
   void* (*mallocUncachedFunc)(size_t size); //64
#endif
   void* (*mallocCachedFunc)(size_t size); //68
#if 0
   void* (*mallocSegmentFunc)(FAPI_SYS_HandleT segment, size_t size); //72
#endif
   void (*freeFunc)(void* ptr); //76
   int (*printfFunc)(const char*, ...); //80
   int (*initDrivers)(FAPI_SYS_DriverT* a[]); //84
   //88
};


extern struct FAPI_SYS_Services FAPI_SYS_Services; //21b140a0

extern void FAPI_SYS_SetServices(struct FAPI_SYS_Services*);
extern void FAPI_SYS_InvalidateDataCache(int, int);
extern void FAPI_SYS_FlushDataCache(void*, int);
extern int FAPI_SYS_GetDeviceId(void);
extern int FAPI_SYS_IsIrqEnabled(void);
extern int FAPI_SYS_IsIsrActive(void);
extern void FAPI_SYS_SetMasterCpu(void);
extern int FAPI_SYS_IsMasterCpu(void);

#define FAPI_SYS_DISABLE_IRQ                           \
        ( ( FAPI_SYS_Services.disableIrq != NULL ) \
        ? FAPI_SYS_Services.disableIrq()           \
        : 0 )

#define FAPI_SYS_ENABLE_IRQ(irqFlags)                      \
        {                                                  \
            if( FAPI_SYS_Services.enableIrq != NULL )  \
            {                                              \
                FAPI_SYS_Services.enableIrq(irqFlags); \
            }                                              \
        }

 
#define DI(cpu_sr) \
   cpu_sr = (FAPI_SYS_Services.disableIrq != 0)?\
      (FAPI_SYS_Services.disableIrq)(): 0;\
      
#define EI(cpu_sr) \
   if (FAPI_SYS_Services.enableIrq != 0)\
   {\
      (FAPI_SYS_Services.enableIrq)(cpu_sr);\
   }

#define LOCK(lock) \
   if (FAPI_SYS_Services.requestSemaphore != 0)\
   {\
      (FAPI_SYS_Services.requestSemaphore)(lock, -1);\
   }

#define UNLOCK(lock) \
   if (FAPI_SYS_Services.releaseSemaphore != 0)\
   {\
      (FAPI_SYS_Services.releaseSemaphore)(lock, 0);\
   }



#define FAPI_SYS_CREATE_SEMAPHORE(val)                      \
        ( ( FAPI_SYS_Services.createSemaphore != NULL ) \
        ? FAPI_SYS_Services.createSemaphore(val)        \
        : 0)

#define FAPI_SYS_DESTROY_SEMAPHORE(sem )                         \
        {                                                        \
            if( FAPI_SYS_Services.deleteSemaphore != NULL ) \
            {                                                    \
                FAPI_SYS_Services.deleteSemaphore(sem);     \
            }                                                    \
        }

#define FAPI_SYS_GET_SEMAPHORE(sem,timeout)               \
        ( ( FAPI_SYS_Services.requestSemaphore != NULL )  \
        ? FAPI_SYS_Services.requestSemaphore(sem,timeout) \
        : -1 )                                            \

#define FAPI_SYS_SET_SEMAPHORE(sem,timeout)                      \
        {                                                        \
            if( FAPI_SYS_Services.releaseSemaphore != NULL )     \
            {                                                    \
                FAPI_SYS_Services.releaseSemaphore(sem,timeout); \
            }                                                    \
        }


#define FAPI_SYS_FREE(ptr)                           \
        {                                            \
            if( FAPI_SYS_Services.freeFunc != NULL ) \
            {                                        \
                FAPI_SYS_Services.freeFunc(ptr);     \
            }                                        \
        }


#define FAPI_SYS_INIT_DRIVERS(pDriverArr)                              \
        ((FAPI_SYS_Services.initDrivers != NULL)                   \
         ? FAPI_SYS_Services.initDrivers(pDriverArr)               \
         : 0)


//#define FAPI_SYS_PRINT_MSG printf
#define FAPI_SYS_PRINT_MSG(...)                                  \
        {                                                        \
            if( FAPI_SYS_Services.printfFunc )                   \
            {                                                    \
                /*lint -save -e522 */                            \
                (void)FAPI_SYS_Services.printfFunc(__VA_ARGS__); \
                /*lint -restore */                                \
            }                                                     \
        }


typedef uint32_t FAPI_SYS_SemaphoreT;


#endif /*SYS_SERVICES_H_*/
