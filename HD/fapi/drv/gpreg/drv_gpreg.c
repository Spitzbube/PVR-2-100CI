
#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/reg_irq_ctrl.h>
#include <fapi/drv_gpreg.h>


struct fapi_gpreg_handle;

static int gpregCheckHandle(struct fapi_gpreg_handle*);
static struct fapi_gpreg_handle* fapi_gpreg_get_handle(unsigned);
static void gpregReleaseHandle(struct fapi_gpreg_handle*);


FAPI_SYS_DriverT FAPI_GPREG_Driver = //21efb16c
{
      "GPREG",
      -1,
      0,
      FAPI_GPREG_Init,
      FAPI_GPREG_Exit,
      0,
      0,
      0,
      0,      
};


static int gpregInitialized; //21f22f34
static FAPI_SYS_SemaphoreT gpregSemaphore; //21f22f38
static struct fapi_gpreg_handle
{
   int magic; //0
   int inUse; //4
   int Data_8; //8
   int Data_12; //12
   int Data_16; //16
   //20
} gpregHandleArray[8]; //21f22f3c




/* 21c1f4ac - complete */
int32_t FAPI_GPREG_Init(void)
{
   unsigned i;
   
   if (gpregInitialized != 0)
   {
      return 0;
   }

   gpregSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (gpregSemaphore == 0)
   {
      return -13009;
   }
   
   memset(gpregHandleArray, 0, 8 * sizeof(struct fapi_gpreg_handle));
   
   for (i = 0; i < 8; i++)
   {
      gpregHandleArray[i].magic = 0x67707267; //gprg
      gpregHandleArray[i].inUse = 0;
      gpregHandleArray[i].Data_8 = i;
      gpregHandleArray[i].Data_12 = FREG_IRQ_CTRL_GPX + i*4;
      gpregHandleArray[i].Data_16 = FREG_IRQ_CTRL_MUTEXX + i*4;
      
      ((volatile unsigned*)gpregHandleArray[i].Data_16)[0] = 0;
   }

   gpregInitialized = 1;
   
   return 0;
}


/* 21c1f43c - complete */
void FAPI_GPREG_Exit(void)
{
   if (gpregInitialized != 0)
   {
      unsigned i;
      for (i = 0; i < 8; i++)
      {
         FAPI_GPREG_Close(&gpregHandleArray[i]);
      }

      FAPI_SYS_DESTROY_SEMAPHORE(gpregSemaphore);
      
      gpregSemaphore = 0;
      gpregInitialized = 0;
   }
}


/* 21c1f268 - complete */
FAPI_SYS_HandleT FAPI_GPREG_Open( const FAPI_GPREG_OpenParamsT* pParams, int32_t* errorCodePtr )
{
   int res = 0;
   struct fapi_gpreg_handle* h;
   
   if (gpregInitialized == 0)
   {
      res = -13004;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   if (pParams == 0)
   {
      res = -13001; 
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   if (pParams->index > FAPI_GPREG_USER_1)
   {
      res = -13001; 
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   if (pParams->version > FAPI_GPREG_VERSION)
   {
      res = -13010;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   FAPI_SYS_GET_SEMAPHORE(gpregSemaphore, -1);
   
   h = fapi_gpreg_get_handle(pParams->index);

   if (0 == gpregCheckHandle(h))
   {
      res = -13002;
   }
   
   FAPI_SYS_SET_SEMAPHORE(gpregSemaphore, 0);
   
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return h;
}


/* 21c1f3c8 - complete */
int32_t FAPI_GPREG_Close( FAPI_SYS_HandleT handlePtr )
{
   struct fapi_gpreg_handle* h = handlePtr;
   int res = 0;
   
   FAPI_SYS_GET_SEMAPHORE(gpregSemaphore, -1);
   
   if (0 != gpregCheckHandle(h))
   {
      gpregReleaseHandle(h);
   }
   else
   {
      res = -13008;
   }
   
   FAPI_SYS_SET_SEMAPHORE(gpregSemaphore, 0);
   
   return res;
}


/* 21c1f22c - complete */
int32_t FAPI_GPREG_Read(FAPI_SYS_HandleT handlePtr)
{
   int res;
   volatile unsigned* r4;
   struct fapi_gpreg_handle* h = handlePtr;
   
   if (0 == gpregCheckHandle(h))
   {
      return -13008;
   }
   
   r4 = (void*) h->Data_12;
   
   FAPI_GPREG_LockMutex(handlePtr);
   
   res = *r4;
   
   FAPI_GPREG_UnlockMutex(handlePtr);
   
   return res;
}


/* 21c1f1ec - complete */
int32_t FAPI_GPREG_Write(FAPI_SYS_HandleT handlePtr, uint32_t data)
{
   volatile unsigned* r4;
   struct fapi_gpreg_handle* h = handlePtr;
   
   if (0 == gpregCheckHandle(h))
   {
      return -13008;
   }
   
   r4 = (void*) h->Data_12;
   
   FAPI_GPREG_LockMutex(handlePtr);
   
   *r4 = data;
   
   FAPI_GPREG_UnlockMutex(handlePtr);
   
   return 0;
}


/* 21c1f1b0 - complete */
int32_t FAPI_GPREG_LockMutex(FAPI_SYS_HandleT handlePtr)
{
   struct fapi_gpreg_handle* h = handlePtr;
   
   if (0 == gpregCheckHandle(h))
   {
      return 0xffffcd30;
   }
   
   volatile unsigned* r0 = (void*) h->Data_16;

   while (1)
   {
#if 1
      //ARM
      *r0 = 1;
      if (*r0 == 1) break;          
#else
      //ARC725D
      *r0 = 2;         
      if (*r0 == 2) break;          
#endif
   }
   
   return 0;
}


/* 21c1f184 - complete */
int32_t FAPI_GPREG_UnlockMutex(FAPI_SYS_HandleT handlePtr)
{
   volatile unsigned* r2;
   struct fapi_gpreg_handle* h = handlePtr;
   
   if (0 == gpregCheckHandle(h))
   {
      return 0xffffcd30;
   }
   
   r2 = (void*) h->Data_16;
   
   *r2 = 0;
   
   return 0;
}


/* 21c1f128 - complete */
int gpregCheckHandle(struct fapi_gpreg_handle* a)
{
   int res = 0;
   
   if ((gpregInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x67707267) && //gprg
         (a->Data_12 != 0) &&
         (a->Data_16 != 0))
   {
      res = 1;
   }
   
   return res;
}


struct fapi_gpreg_handle* fapi_gpreg_get_handle(unsigned a)
{      
   struct fapi_gpreg_handle* h = 0;
   
   if ((a <= 7) &&
         (gpregHandleArray[a].inUse == 0))
   {
      gpregHandleArray[a].inUse = 1;
      h = &gpregHandleArray[a];      
   }
   
   return h;
}


void gpregReleaseHandle(struct fapi_gpreg_handle* a)
{   
   if (0 != gpregCheckHandle(a))
   {
      a->inUse = 0;
   }
}










