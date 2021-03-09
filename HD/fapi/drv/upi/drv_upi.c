
#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/reg_upi.h>
#include <fapi/drv_upi.h>



struct fapi_upi_handle;


static int upiCheckHandle(struct fapi_upi_handle* a);
static struct fapi_upi_handle* fapi_upi_get_handle(int);
static void fapi_upi_release_handle(struct fapi_upi_handle*);



FAPI_SYS_DriverT FAPI_UPI_Driver = //21efc748
{
      "UPI",
      -1,
      0,
      FAPI_UPI_Init, 
      FAPI_UPI_Exit,
      0,
      0,
      0,
      0,
};

FAPI_UPI_ConfigT fapi_upi_configurations[3] = //21efc76c
{
      {
         1,
         2,
         2,
         2,
         19, 
         2,
         5,
         5,
         9,
         2,
         0,
         0,
         0,          
      },
      {
            5, 
            2,
            2, 
            2, 
            19, 
            2,
            5, 
            5, 
            20, 
            2,
            0, 
            0,
            0,             
      },
      {
            3,
            0, 
            0, 
            0, 
            3,
            0, 
            0, 
            0, 
            3,
            0,
            1, 
            0, 
            0,
      }
};


FAPI_SYS_SemaphoreT upiSemaphore; //21f66fec
int upiInitialized; //21f66ff0
struct fapi_upi_handle
{
   int magic; //0
   int inUse; //4
   unsigned index; //8
   FAPI_UPI_OpenParamsT openParams; //12
   //20
} upiHandleArray[3]; //21f66ff4




/* 21c42c94 - complete */
int32_t FAPI_UPI_Init(void)
{
   uint32_t i;
   
   if (upiInitialized != 0)
   {
      return -26003;      
   }
   
   upiSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (upiSemaphore == 0)
   {
      return -26009;
   }
   
   for (i = 0; i < 3; i++)
   {
      memset(&upiHandleArray[i], 0, sizeof(struct fapi_upi_handle));
      
      upiHandleArray[i].magic = 0x75706130; //upa0
      upiHandleArray[i].inUse = 0;
      upiHandleArray[i].index = i;
   }
   
   upiInitialized = 1;
   
   return 0;
}


/* 21c42c24 - complete */
void FAPI_UPI_Exit(void)
{
   if (upiInitialized != 0)
   {
      uint32_t i;
      
      for (i = 0; i < 3; i++)
      {
         FAPI_UPI_Close(&upiHandleArray[i]);
      }
      
      FAPI_SYS_DESTROY_SEMAPHORE(upiSemaphore);
      
      upiSemaphore = 0;
      upiInitialized = 0;
   }
}


/* 21c42d4c - complete */
FAPI_SYS_HandleT FAPI_UPI_Open(const FAPI_UPI_OpenParamsT* paramsPtr, int32_t* errorCodePtr)
{
   struct fapi_upi_handle* h;
   int32_t res = 0;
   
   if (upiInitialized == 0)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -26004;
      }
      return 0;
   }
   
   if (paramsPtr == 0)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -26001;
      }
      return 0;
   }
   
   if (paramsPtr->version > FAPI_UPI_VERSION)
   {
      if (errorCodePtr != 0)
      {
         *errorCodePtr = -26010;
      }
      return 0;      
   }
   
   FAPI_SYS_GET_SEMAPHORE(upiSemaphore, FAPI_SYS_SUSPEND);
   
   h = fapi_upi_get_handle(paramsPtr->index);
   
   if (0 != upiCheckHandle(h))
   {
      memcpy(&h->openParams, paramsPtr, sizeof(FAPI_UPI_OpenParamsT));
   }
   else
   {
      res = -26002;
   }
   
   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);
   
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }
   
   return h;
}


/* 21c42b7c - complete */
int32_t FAPI_UPI_Close(FAPI_SYS_HandleT handle)
{
   struct fapi_upi_handle* h = handle;
   int res = 0;
   
   FAPI_SYS_GET_SEMAPHORE(upiSemaphore, FAPI_SYS_SUSPEND);
   
   if (0 != upiCheckHandle(h))
   {
      fapi_upi_release_handle(h);
   }
   else
   {
      res = -26008;
   }
   
   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c42b24 - complete */
int32_t FAPI_UPI_SetDefaults(FAPI_SYS_HandleT handle, uint32_t valueSet)
{
   if (0 == upiCheckHandle(handle))
   {
      return -26008;
   }
   
   if (valueSet > 2)
   {
      return -26001;
   }
   
   return FAPI_UPI_SetConfiguration(handle, &fapi_upi_configurations[valueSet]);
}


/* 21c42a0c - complete */
int32_t FAPI_UPI_SetConfiguration(FAPI_SYS_HandleT handle, FAPI_UPI_ConfigT* configPtr)
{
   struct fapi_upi_handle* h = handle;
   
   if (0 == upiCheckHandle(handle))
   {
      return -26008;
   }

   if (configPtr == 0)
   {
      return -26001;
   }

   FAPI_SYS_GET_SEMAPHORE(upiSemaphore, FAPI_SYS_SUSPEND);
   
   FREG_UPI_SetModeX_UpiMode(h->index, configPtr->mode);
   FREG_UPI_SetTalsX_UpiTals(h->index, configPtr->latchAddressSetupTime);
   FREG_UPI_SetTalhX_UpiTalh(h->index, configPtr->latchAddressHoldTime);
   FREG_UPI_SetTrsX_UpiTrs(h->index, configPtr->readAddressTime);
   FREG_UPI_SetTrdsX_UpiTrds(h->index, configPtr->readDataSetupTime);
   FREG_UPI_SetTrdhX_UpiTrdh(h->index, configPtr->readDataHoldTime);
   FREG_UPI_SetTrrX_UpiTrr(h->index, configPtr->readRecoveryTime);
   FREG_UPI_SetTwsX_UpiTws(h->index, configPtr->writeDataSetupTime);
   FREG_UPI_SetTwpX_UpiTwp(h->index, configPtr->writeDataHoldTime);
   FREG_UPI_SetTwrX_UpiTwr(h->index, configPtr->writeRecoveryTime);
   FREG_UPI_SetWmmaskX_UpiWmmask(h->index, configPtr->enableWait);
   FREG_UPI_SetBufenX_UpiBufen(h->index, configPtr->enableExternalBuffer);
   FREG_UPI_SetCssel(configPtr->chipSelect);

   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);
   
   return 0;
}


/* 21c428f4 - complete */
int32_t FAPI_UPI_GetConfiguration(FAPI_SYS_HandleT handle, FAPI_UPI_ConfigT* configPtr)
{
   struct fapi_upi_handle* h = handle;
   
   if (0 == upiCheckHandle(handle))
   {
      return -26008;
   }

   if (configPtr == 0)
   {
      return -26001;
   }

   FAPI_SYS_GET_SEMAPHORE(upiSemaphore, FAPI_SYS_SUSPEND);
   
   configPtr->mode = FREG_UPI_GetModeX_UpiMode(h->index);
   configPtr->latchAddressSetupTime = FREG_UPI_GetTalsX_UpiTals(h->index);
   configPtr->latchAddressHoldTime = FREG_UPI_GetTalhX_UpiTalh(h->index);
   configPtr->readAddressTime = FREG_UPI_GetTrsX_UpiTrs(h->index);
   configPtr->readDataSetupTime = FREG_UPI_GetTrdsX_UpiTrds(h->index);
   configPtr->readDataHoldTime = FREG_UPI_GetTrdhX_UpiTrdh(h->index);
   configPtr->readRecoveryTime = FREG_UPI_GetTrrX_UpiTrr(h->index);
   configPtr->writeDataSetupTime = FREG_UPI_GetTwsX_UpiTws(h->index);
   configPtr->writeDataHoldTime = FREG_UPI_GetTwpX_UpiTwp(h->index);
   configPtr->writeRecoveryTime = FREG_UPI_GetTwrX_UpiTwr(h->index);
   configPtr->enableWait = FREG_UPI_GetWmmaskX_UpiWmmask(h->index);
   configPtr->enableExternalBuffer = FREG_UPI_GetBufenX_UpiBufen(h->index);
   configPtr->chipSelect = FREG_UPI_GetCssel();

   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);
   
   return 0;
}


/* 21c4284c - complete */
int32_t FAPI_UPI_SetWaitTimer(FAPI_SYS_HandleT handle, uint32_t value)
{
   if (0 == upiCheckHandle(handle))
   {
      return -26008;
   }

   FAPI_SYS_GET_SEMAPHORE(upiSemaphore, FAPI_SYS_SUSPEND);

   if (value != 0)
   {
      FREG_UPI_SetWaittime_WaitTime(value);
      FREG_UPI_SetWaittimeen_WaitTimeEn(1);
   }
   else
   {
      FREG_UPI_SetWaittimeen_WaitTimeEn(0);
      FREG_UPI_SetWaittime_WaitTime(0);
   }
   
   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);
   
   return 0;
}


/* 21c427b8 - complete */
int32_t FAPI_UPI_GetWaitTimer(FAPI_SYS_HandleT handle, FAPI_UPI_TimerInfoT* timerInfoPtr)
{
   if (0 == upiCheckHandle(handle))
   {
      return -26008;
   }

   if (timerInfoPtr == 0)
   {
      return -26001;
   }
   
   FAPI_SYS_GET_SEMAPHORE(upiSemaphore, FAPI_SYS_SUSPEND);

   timerInfoPtr->timeout = FREG_UPI_GetmWaittime_WaitTime();
   timerInfoPtr->lastTime = FREG_UPI_GetLastwaittime_LastWaitTime();
   timerInfoPtr->isActive = FREG_UPI_GetWaittimestatus_WaitTimeAct();
   
   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);
   
   return 0;
}


/* 21c42774 - complete */
int32_t FAPI_UPI_GetBaseAddress(FAPI_SYS_HandleT handle, uint32_t* addressPtr)
{
   struct fapi_upi_handle* h = handle;
   
   if (0 == upiCheckHandle(h))
   {
      return -26008;
   }
   
   if (addressPtr == 0)
   {
      return -26001;
   }
   
   *addressPtr = (h->index << 27) + 0x80000000;
   
   return 0;
}


/* 21c426bc - complete */
int32_t FAPI_UPI_Lock(void)
{
   if (FAPI_SYS_Services.getSemaphoreFunc == 0)
   {
      return -1;
   }
   
   return (FAPI_SYS_Services.getSemaphoreFunc)(upiSemaphore, FAPI_SYS_SUSPEND);
}


/* 21c426f0 - complete */
void FAPI_UPI_Unlock(void)
{
   FAPI_SYS_SET_SEMAPHORE(upiSemaphore, FAPI_SYS_NO_SUSPEND);
}


/* 21c42720 - complete */
int upiCheckHandle(struct fapi_upi_handle* a)
{
   int res = 0;
   
   if ((upiInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x75706130) &&
         (a->index < 3)) //upa0
   {
      res = 1;
   }
   
   return res;
}


struct fapi_upi_handle* fapi_upi_get_handle(int a)
{
   if (upiHandleArray[a].inUse == 0)
   {
      upiHandleArray[a].inUse = 1;
      upiHandleArray[a].index = a;
      
      return &upiHandleArray[a];
   }
   
   return 0;
}


void fapi_upi_release_handle(struct fapi_upi_handle* a)
{   
   if (0 != upiCheckHandle(a))
   {      
      if (0 != memset(a, 0, sizeof(struct fapi_upi_handle)))
      {
         a->inUse = 0;
         a->magic = 0x75706130; //upa0
      }
   }
}




