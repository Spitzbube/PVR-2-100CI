

#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_clkpwr.h>
#include <fapi/drv_bm.h>
#include <fapi/drv_tsd.h>
#include <fapi/drv_sync.h>

#define SYNC_LOCK   (void)FAPI_SYS_GET_SEMAPHORE( syncSemaphore, FAPI_SYS_SUSPEND )
#define SYNC_UNLOCK FAPI_SYS_SET_SEMAPHORE( syncSemaphore, FAPI_SYS_NO_SUSPEND )

#define SYNC_TOTAL_HANDLE_COUNT       1                    /* handle count of a block */
#define SYNC_BLOCK_UNDEFINED          0xFFFFFFFF           /* SYNC block is undefined */
#define SYNC_ERR_NO_HANDLE            0                    /* don't return handle */


FAPI_SYS_DriverT FAPI_SYNC_Driver = //21efc030
{
      "SYNC",
      -1,
      0,
      FAPI_SYNC_Init,
      FAPI_SYNC_Exit,
      0,
      0,
      0,
      0,
};


int syncInitialized; //21f27ec4
int Data_21efc054; //21efc054
FAPI_SYS_SemaphoreT syncSemaphore = 1; //21efc058
int syncBlock = -1; //21efc05c
int syncHandleCount; //21f27ed0
int Data_21f27eb4; //21f27eb4
int Data_21f27eb8; //21f27eb8
uint32_t syncDeviceId; //21f27ebc

typedef struct fapi_sync_handle
{
   int id; //0
   int inUse; //4
   FAPI_SYNC_OpenParamsT openParams; //8 +8
   int blockIndex; //16
   int Data_20; //20
   int Data_24; //24
   int Data_28; //28
   int Data_32; //32
   int fill_36[42]; //36
   int Data_204; //204
   int Data_208; //208
   int Data_212; //212
   int Data_216; //216
   int pid; //220
   FAPI_SYS_HandleT tsdHandle; //224
   FAPI_SYS_HandleT bmHandle; //228
   int status; //232
   int Data_236; //236
   //240
} syncHandleT;

syncHandleT syncHandleArray[1]; //21f27ed4


static void syncReset(void);
static int syncCheckHandle(struct fapi_sync_handle*);
static syncHandleT* syncAllocateHandle(const uint32_t blockIndex);
static void syncReleaseHandle(struct fapi_sync_handle*);



/* 21c31374 - complete */
int32_t FAPI_SYNC_Init(void)
{
   unsigned i = 0;
   
   if (syncInitialized != 0)
   {
      return 0;
   }
   
   memset(syncHandleArray, 0, sizeof(syncHandleArray));
   
   for (i = 0; i < 1; i++)
   {
      syncHandleArray[i].id = 0x73796e63;
      syncHandleArray[i].blockIndex = -1;
      syncHandleArray[i].status = 0;
      syncHandleArray[i].pid = -1;
   }
   
   syncSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (syncSemaphore == 0)
   {
      return -21009;
   }
   
   syncDeviceId = FAPI_SYS_GetDeviceId();
   
   syncInitialized = 1;
   
   return 0;
}


/* 21c301c4 - complete */
void FAPI_SYNC_Exit(void)
{
   unsigned i = 0;
   
   if (syncInitialized)
   {
      for (i = 0; i < 1; i++)
      {
         if (syncHandleArray[i].inUse == 1)
         {
            FAPI_SYNC_Close(&syncHandleArray[i]);
         }
      }
   }
   
   FAPI_SYS_GET_SEMAPHORE(syncSemaphore, FAPI_SYS_SUSPEND);
   
   syncInitialized = 0;
   
   FAPI_SYS_SET_SEMAPHORE(syncSemaphore, FAPI_SYS_NO_SUSPEND);
         
   FAPI_SYS_DESTROY_SEMAPHORE(syncSemaphore);
   
   syncSemaphore = 0;
}


/* 21c311c0 - todo */
FAPI_SYS_HandleT FAPI_SYNC_Open(const FAPI_SYNC_OpenParamsT* paramsPtr,
                                 int32_t* errorCodePtr)
{
    syncHandleT* sync_handle_ptr = NULL;
    int32_t      error_code      = FAPI_OK;

    /* error if driver not initialized */
    if(syncInitialized == 0)
        error_code = FAPI_SYNC_ERR_NOT_INITIALIZED;
    /* check paramters */
    if(paramsPtr == NULL)
    {
        error_code = FAPI_SYNC_ERR_BAD_PARAMETER;
        if ( errorCodePtr ) *errorCodePtr = error_code;
        return(SYNC_ERR_NO_HANDLE);
    }
    /* check version */
    if(!FAPI_SYS_CHECK_VERSION(paramsPtr->version, FAPI_SYNC_VERSION))
        error_code = FAPI_SYNC_ERR_UNSUPPORTED_VERSION;
    /* check block */
    if((paramsPtr->blockIndex != FAPI_SYNC0) &&
       (paramsPtr->blockIndex != FAPI_SYNC1))
        error_code = FAPI_SYNC_ERR_BAD_PARAMETER;
    /* check valid block */
    if(((paramsPtr->blockIndex == FAPI_SYNC0) && ((syncBlock != FAPI_SYNC0) && (syncBlock != SYNC_BLOCK_UNDEFINED))) ||
       ((paramsPtr->blockIndex == FAPI_SYNC1) && ((syncBlock != FAPI_SYNC1) && (syncBlock != SYNC_BLOCK_UNDEFINED))))
        error_code = FAPI_SYNC_ERR_BAD_PARAMETER;

    if ( error_code != FAPI_OK )
    {
        if ( errorCodePtr ) *errorCodePtr = error_code;
        return(SYNC_ERR_NO_HANDLE);
    }

    /////////
    SYNC_LOCK;
    /////////

    /* allocate handle */
    sync_handle_ptr = syncAllocateHandle(paramsPtr->blockIndex);
    if( syncCheckHandle( sync_handle_ptr ) )
    {
        if(syncBlock == SYNC_BLOCK_UNDEFINED)
            syncBlock = paramsPtr->blockIndex;

        /* copy open params to handle */
        memcpy( &(sync_handle_ptr->openParams),
                paramsPtr, sizeof(FAPI_SYNC_OpenParamsT) );

        /* store first PCR in STC registers */
        syncReset();
    }
    else
    {
        error_code = FAPI_SYNC_ERR_OUT_OF_MEMORY;
    }


    ////////////
    SYNC_UNLOCK;
    ////////////

    if ( errorCodePtr ) *errorCodePtr = error_code;
    return((FAPI_SYS_HandleT)sync_handle_ptr);
}


/* 21c30074 - todo */
int32_t FAPI_SYNC_Close(FAPI_SYS_HandleT handle)
{
//   FAPI_SYS_PRINT_MSG("FAPI_SYNC_Close\n");
   
   int32_t res = 0;
   int i = 0;
   struct fapi_sync_handle* a = handle;
   
   if (syncCheckHandle(a))
   {
      FAPI_SYS_GET_SEMAPHORE(syncSemaphore, FAPI_SYS_SUSPEND);
      
      if (syncHandleArray[i].bmHandle != 0)
      {
         res = FAPI_BM_Close(syncHandleArray[i].bmHandle);
      }
      
      if (res != 0)
      {
         FAPI_SYS_SET_SEMAPHORE(syncSemaphore, FAPI_SYS_NO_SUSPEND);      
         return res;
      }      
      
      syncHandleArray[i].bmHandle = 0;
   
      if (syncHandleArray[i].tsdHandle != 0)
      {
         res = FAPI_TSD_Close(syncHandleArray[i].tsdHandle);
      }
      
      if (res != 0)
      {
         FAPI_SYS_SET_SEMAPHORE(syncSemaphore, FAPI_SYS_NO_SUSPEND);      
         return res;
      }
      
      syncHandleArray[i].tsdHandle = 0;
      
      syncReleaseHandle(a);

      if (syncHandleCount == 0)
      {
         syncBlock = -1;
      }
      
      FAPI_SYS_SET_SEMAPHORE(syncSemaphore, FAPI_SYS_NO_SUSPEND);
   }
   else
   {
      res = FAPI_SYNC_ERR_INVALID_HANDLE;
   }
      
   return res;
}


/* 21c2ffcc - todo */
int32_t func_21c2ffcc(uint32_t a)
{
   int32_t res = 0;
   
   FAPI_SYS_PRINT_DEBUG(4, "func_21c2ffcc: a=%d\n", a);
   
   if (syncDeviceId == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      if (a != 0)
      {
         FREG_CLKPWR_SetFd2audio_ResetFd2(0);
         FREG_CLKPWR_SetFd2audio_Fd2rest(0);
         FREG_CLKPWR_SetFd2audio_Fd2modulo(216);
         FREG_CLKPWR_SetFd2audio_Fd2muxsel(0);
         FREG_CLKPWR_SetFd2audio_ResetFd2(1);
         FREG_CLKPWR_SetFd2delta(51);
         FREG_CLKPWR_SetFdprescale_Fd3divider(0);
         
         Data_21f27eb8 = 1;
         
         syncReset();
      }
      else
      {
         FREG_CLKPWR_SetFd2audio(0);
         FREG_CLKPWR_SetFd2delta(0);
         
         Data_21f27eb8 = 0;
         
         syncReset();
      }
   }
   else
   {
      res = FAPI_SYNC_ERR_FEATURE_NOT_SUPPORTED; //-21005;
   }

   FAPI_SYS_PRINT_DEBUG(4, "func_21c2ffcc: res=%d\n", res);

   return res;
}


struct 
{
   int fill_0[20]; //0
   //80
} Data_21f27ef8; //21f27ef8


struct
{
   int fill_0[20]; //0
   //80
} Data_21f27f48; //21f27f48


/* 21c2fdf8 - todo */
void syncReset(void)
{
//   FAPI_SYS_PRINT_MSG("syncReset\n");
   
   memset(&Data_21f27ef8, 0, 80);
   memset(&Data_21f27f48, 0, 80);

   syncHandleArray[0].Data_20 = 0;
   syncHandleArray[0].Data_24 = 0;
   syncHandleArray[0].Data_28 = -1;
   syncHandleArray[0].Data_32 = -1;
   syncHandleArray[0].Data_204 = 0;
   syncHandleArray[0].Data_208 = 110000;
   syncHandleArray[0].Data_212 = 0;
   syncHandleArray[0].Data_216 = 0;

   Data_21efc054 = 5;
   Data_21f27eb4 = 0;

   FREG_CLKPWR_SetDpllconfig_EnDpllhdmi(0);
   FREG_CLKPWR_SetDpllconfig_EnDpllfd1(0);
   FREG_CLKPWR_SetDpllconfig_EnDpllfd2(0);
   FREG_CLKPWR_SetDpllconfig_EnDpllfd3(0);
   FREG_CLKPWR_SetDplldivcounthdmi(109999);
   FREG_CLKPWR_SetDplldivcountfd1(604999);
   FREG_CLKPWR_SetDplldivcountfd2(604999);
   FREG_CLKPWR_SetDplldivcountfd3(604999);
   FREG_CLKPWR_SetDpllconfig_IncFreqhdmi(0);
   FREG_CLKPWR_SetDpllconfig_IncFreqfd1(0);
   FREG_CLKPWR_SetDpllconfig_IncFreqfd2(0);
   FREG_CLKPWR_SetDpllconfig_IncFreqfd3(0);
   
   if (Data_21f27eb8 != 0)
   {
      FREG_CLKPWR_SetDpllconfig_PptCountReg(45);
      FREG_CLKPWR_SetDpllconfig_EnPptHdmi(1);
      FREG_CLKPWR_SetDpllconfig_IncPptHdmi(0);
      FREG_CLKPWR_SetDpllconfig_IncFreqhdmi(0);
      FREG_CLKPWR_SetDplldivcounthdmi(545);
      FREG_CLKPWR_SetDpllconfig_EnDpllhdmi(1);
   }
   else
   {
      FREG_CLKPWR_SetDpllconfig_PptCountReg(0);
      FREG_CLKPWR_SetDpllconfig_EnPptHdmi(0);
      FREG_CLKPWR_SetDpllconfig_IncPptHdmi(0);
   }
}


/* 21c2f618 - complete */
int syncCheckHandle(struct fapi_sync_handle* a)
{
   int res = 0;
   
   if ((syncInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->id == 0x73796e63))
   {
      res = 1;
   }

   return res;
}


static syncHandleT* syncAllocateHandle(const uint32_t blockIndex)
{
    syncHandleT* sync_handle_ptr = NULL;
    uint32_t      index          = 0;

    /* check if maximum handle count is reached */
    if( (syncHandleCount) == SYNC_TOTAL_HANDLE_COUNT)
    {
        return(0);
    }

    for(index = 0; index < SYNC_TOTAL_HANDLE_COUNT; index++)
    {
        /* search for handle not in use */
        if( !syncHandleArray[index].inUse )
        {
            /* set in use */
            syncHandleArray[index].inUse = 1;
            /* allocate block */
            syncHandleArray[index].blockIndex = blockIndex;
            /* increase block's handle count */
            syncHandleCount++;
            /* set handle pointer */
            sync_handle_ptr = &(syncHandleArray[index]);
            break;
        }
    }

    return(sync_handle_ptr);
}


/* 214cdce0 - complete */
void syncReleaseHandle(struct fapi_sync_handle* a)
{
   syncHandleCount--;
   
   memset(a, 0, sizeof(struct fapi_sync_handle));
   
   a->id = 0x73796e63;
   a->blockIndex = -1;
   a->pid = -1;
   a->status = 0;
}


