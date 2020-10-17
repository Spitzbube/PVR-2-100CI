#ifndef SYS_SERVICES_H_
#define SYS_SERVICES_H_

struct fapi_driver;

struct FAPI_SYS_Services
{
   unsigned (*disableIrq)(void); //12
   void (*enableIrq)(unsigned); //16
   void* (*createSemaphore)(int); //20
   void (*deleteSemaphore)(void*); //24
   int (*requestSemaphore)(void*, int); //28
   void (*releaseSemaphore)(void*, int); //32
   int (*printf)(const char*, ...); //80
   int (*initDrivers)(struct fapi_driver* a[]); //84
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
extern int FAPI_SYS_Init(void);


#define PRINTF(str) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str);\
   }

#define PRINTF1(str, p1) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str, p1);\
   }

#define PRINTF2(str, p1, p2) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str, p1, p2);\
   }

#define PRINTF3(str, p1, p2, p3) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str, p1, p2, p3);\
   }

#define PRINTF4(str, p1, p2, p3, p4) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str, p1, p2, p3, p4);\
   }

#define PRINTF6(str, p1, p2, p3, p4, p5, p6) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str, p1, p2, p3, p4, p5, p6);\
   }
 
#define PRINTF7(str, p1, p2, p3, p4, p5, p6, p7) \
   if (FAPI_SYS_Services.printf != 0)\
   {\
      (FAPI_SYS_Services.printf)(str, p1, p2, p3, p4, p5, p6, p7);\
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


#define FAPI_SYS_PRINT_MSG printf


#endif /*SYS_SERVICES_H_*/
