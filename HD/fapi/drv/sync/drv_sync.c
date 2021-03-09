

#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_clkpwr.h>
#include <fapi/drv_bm.h>
#include <fapi/drv_tsd.h>
#include <fapi/drv_sync.h>



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
FAPI_SYS_SemaphoreT syncSemaphore; //21efc058
int Data_21efc05c; //21efc05c
int Data_21f27ed0; //21f27ed0
int Data_21f27eb4; //21f27eb4
int Data_21f27eb8; //21f27eb8
uint32_t Data_21f27ebc; //21f27ebc

struct fapi_sync_handle 
{
   int magic; //0
   int inUse; //4
   int fill_8; //8
   int fill_12; //12
   int Data_16; //16
   int Data_20; //20
   int Data_24; //24
   int Data_28; //28
   int Data_32; //32
   int fill_36[42]; //36
   int Data_204; //204
   int Data_208; //208
   int Data_212; //212
   int Data_216; //216
   int Data_220; //220
   FAPI_SYS_HandleT Data_224; //224
   FAPI_SYS_HandleT Data_228; //228
   int Data_232; //232
   int Data_236; //236
   //240
} syncHandleArray[1]; //21f27ed4


void func_21c2fdf8(void);
int fapi_sync_check_handle(struct fapi_sync_handle*);
static void fapi_sync_clear_handle(struct fapi_sync_handle*);



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
      syncHandleArray[i].magic = 0x73796e63;
      syncHandleArray[i].Data_16 = -1;
      syncHandleArray[i].Data_232 = 0;
      syncHandleArray[i].Data_220 = -1;
   }
   
   syncSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
         
   if (syncSemaphore == 0)
   {
      return -21009;
   }
   
   Data_21f27ebc = FAPI_SYS_GetDeviceId();
   
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
FAPI_SYS_HandleT FAPI_SYNC_Open(const FAPI_SYNC_OpenParamsT* pParams,
                                 int32_t* errorCodePtr)
{
   FAPI_SYS_PRINT_MSG("FAPI_SYNC_Open\n");

   return 0;
}


/* 21c30074 - todo */
int32_t FAPI_SYNC_Close(FAPI_SYS_HandleT handle)
{
//   FAPI_SYS_PRINT_MSG("FAPI_SYNC_Close\n");
   
   int32_t res = 0;
   int i = 0;
   struct fapi_sync_handle* a = handle;
   
   if (fapi_sync_check_handle(a))
   {
      FAPI_SYS_GET_SEMAPHORE(syncSemaphore, FAPI_SYS_SUSPEND);
      
      if (syncHandleArray[i].Data_228 != 0)
      {
         res = FAPI_BM_Close(syncHandleArray[i].Data_228);         
      }
      
      if (res != 0)
      {
         FAPI_SYS_SET_SEMAPHORE(syncSemaphore, FAPI_SYS_NO_SUSPEND);      
         return res;
      }      
      
      syncHandleArray[i].Data_228 = 0;
   
      if (syncHandleArray[i].Data_224 != 0)
      {
         res = FAPI_TSD_Close(syncHandleArray[i].Data_224);         
      }
      
      if (res != 0)
      {
         FAPI_SYS_SET_SEMAPHORE(syncSemaphore, FAPI_SYS_NO_SUSPEND);      
         return res;
      }
      
      syncHandleArray[i].Data_224 = 0;
      
      fapi_sync_clear_handle(a);      

      if (Data_21f27ed0 == 0)
      {
         Data_21efc05c = -1;
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
   
   if (Data_21f27ebc == FAPI_SYS_DEVICE_ID_MB86H60B)
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
         
         func_21c2fdf8();
      }
      else
      {
         FREG_CLKPWR_SetFd2audio(0);
         FREG_CLKPWR_SetFd2delta(0);
         
         Data_21f27eb8 = 0;
         
         func_21c2fdf8();
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
void func_21c2fdf8(void)
{
//   FAPI_SYS_PRINT_MSG("func_21c2fdf8\n");
   
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
int fapi_sync_check_handle(struct fapi_sync_handle* a)
{
   int res = 0;
   
   if ((syncInitialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x73796e63))
   {
      res = 1;
   }

   return res;
}


/* 214cdce0 - complete */
void fapi_sync_clear_handle(struct fapi_sync_handle* a)
{
   Data_21f27ed0--;
   
   memset(a, 0, sizeof(struct fapi_sync_handle));
   
   a->magic = 0x73796e63;
   a->Data_16 = -1;
   a->Data_220 = -1;
   a->Data_232 = 0;
}


