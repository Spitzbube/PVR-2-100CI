
#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_bm.h>
#include <fapi/reg_tsd.h>
#include <fapi/drv_bm.h>
#include <fapi/drv_intr.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_gpreg.h>
#include <fapi/drv_sync.h>
#include <fapi/drv_tsd.h>
#include <fapi/drv_tsd_priv.h>
#include <fapi/drv_timer.h>
//#include "reg_tsd_old.h"



FAPI_SYS_DriverT FAPI_TSD_Driver0 = //21efc060
{
      "TSD0",
      FAPI_INTR_TSD01,
      1,
      FAPI_TSD_Init,
      FAPI_TSD_Exit,
      FAPI_TSD_Isr01,
      FAPI_TSD_Bsr,
      0x800,
      0x100,
};

FAPI_SYS_DriverT FAPI_TSD_Driver1 = //21efc084
{
      "TSD1",
      FAPI_INTR_TSD01,
      1,
      FAPI_TSD_Init,
      FAPI_TSD_Exit,
      FAPI_TSD_Isr01,
      FAPI_TSD_Bsr,
      0x800,
      0x100,
};
FAPI_SYS_DriverT FAPI_TSD_Driver2 = //21efc0a8
{
      "TSD2",
      FAPI_INTR_TSD23,
      1,
      FAPI_TSD_Init,
      FAPI_TSD_Exit,
      FAPI_TSD_Isr23,
      FAPI_TSD_Bsr,
      0x800,
      0x100,
};
FAPI_SYS_DriverT FAPI_TSD_Driver3 = //21efc0cc
{
      "TSD3",
      FAPI_INTR_TSD23,
      1,
      FAPI_TSD_Init,
      FAPI_TSD_Exit,
      FAPI_TSD_Isr23,
      FAPI_TSD_Bsr,
      0x800,
      0x100,
};


struct fapi_tsd_handle
{
   int magic; //0
   uint32_t inUse; //4
   uint32_t blockIndex; //8
   FAPI_TSD_OpenParamsT openParams; //12
   int32_t channelId; //24
   uint32_t pid; //28
   FAPI_BM_InfoT bufferInfo; //32
   int Data_68; //68
   uint32_t Data_72; //72
   void (*Data_76)(void*); //76
   void* Data_80; //80
   FAPI_TSD_PtsEvaluateT ptsEvaluator; //84
   void* ptsEvaluatorDataPtr; //88;
   uint32_t Data_92; //92
   uint32_t Data_96; //96
   uint32_t Data_100; //100
   int fill_104; //104
   int Data_108; //108
   FAPI_TSD_SectionNotifyT Data_112[32]; //112
   void* Data_240[32]; //240
   uint32_t Data_368; //368
   uint32_t Data_372; //372
   int fill_376[3]; //376
   FAPI_TSD_GeneralNotifyT Data_388; //388
   void* Data_392; //392
   FAPI_TSD_GeneralNotifyT Data_396; //396
   void* Data_400; //400
   uint32_t Data_404; //404
   FAPI_TSD_GeneralNotifyT Data_408; //408
   void* Data_412; //412
   uint32_t Data_416[32]; //416
   int fill_544; //544
   //548
};


struct Struct_21f280b0
{
   void* Data_0; //0
   void* Data_4; //4
   void* Data_8; //8
   void* Data_12; //12
   void* Data_16; //16
   void* Data_20; //20
   void* Data_24; //24
   void* Data_28; //28
   void* Data_32; //32
   void* Data_36; //36
   void* Data_40; //40
   //44
};


static int32_t Data_21efc0f0[4] = {-1, -1, -1, -1}; //21efc0f0
static FAPI_SYS_SemaphoreT fapi_tsd_semaphore; //21efc100
static uint32_t Data_21efc104[4] = //21efc104
{
      1, 128, 128, 128,
};
static uint32_t Data_21efc114[] = //21efc114
{
      0x80, //TODO
#if 0
128, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 0xFFFFFFFF, 0xFFFFFFFF,
#endif
};
static int Data_21efc178; //21efc178
static int Data_21efc17c; //21efc17c
static int fapi_tsd_initialized; //21f27fc4
static uint32_t Data_21f27fc8[1000]; //21f27fc8 size todo???
static FAPI_SYS_HandleT tsdSyncHandle; //21f28028
static struct
{
   uint32_t Data_0; //0
   int Data_4; //4
   int Data_8; //8
   //12
} Data_21f2802c[4]; //21f2802c
static int Data_21f2805c[4]; //21f2805c
static FAPI_SYS_HandleT fapi_tsd_gpreg; //21f2806c
static struct Struct_21f280b0 fapi_tsd_gpio[4]; //21f280b0
static uint32_t Data_21f285c0[2][4]; //21f285c0
static uint32_t tsdChannelUse[4][32]; //21f285e0
static struct fapi_tsd_handle fapi_tsd_handles[128]; //21f287e0
static struct
{
   int Data_0; //0
   int Data_4; //4
   int fill_8[3]; //8
   //20
} Data_21f399e0[2][0x1000]; //21f399e0
static int Data_21f619e0[2]; //21f619e0
static int Data_21f619e8[2]; //21f619e8
static int Data_21f619f0[2]; //21f619f0
static int Data_21f619f8[2]; //21f619f8
static uint64_t Data_21f61a00[4]; //21f61a00
static uint32_t Data_21f61a20[4][128]; //21f61a20


static uint32_t fapi_tsd_check_handle(struct fapi_tsd_handle*);
int32_t func_21c352f4(struct fapi_tsd_handle*);
int32_t func_21c31e88(FAPI_SYS_HandleT handle, void (*notifier)(void*),
      void* optDataPtr, const uint32_t enableNotifier);
static void func_21c32398(struct fapi_tsd_handle*, uint32_t);
int32_t func_21c38100(FAPI_SYS_HandleT handle);
static void func_21c31434(struct fapi_tsd_handle* a, int b);
static void fapi_tsd_clear_handle(struct fapi_tsd_handle*);
static struct fapi_tsd_handle* tsdGetHandle(uint32_t blockIndex);
void func_21c34e8c(struct fapi_tsd_handle* a);
static void tsdSetChannelPid(struct fapi_tsd_handle* a,
      uint32_t enableContinuityCheck,
      uint32_t removeTsHeader);


/* 21c37984 - complete */
int32_t FAPI_TSD_Init(void)
{
   unsigned i, j;
   int32_t res = 0;
   FAPI_GPIO_OpenParamsT gpioParams;
   FAPI_GPREG_OpenParamsT gpregParams;

   memset(&gpioParams, 0, sizeof(FAPI_GPIO_OpenParamsT));
   memset(&gpregParams, 0, sizeof(FAPI_GPREG_OpenParamsT));

   if (fapi_tsd_initialized != 0)
   {
      return 0;
   }

   memset(fapi_tsd_handles, 0, sizeof(fapi_tsd_handles));

   for (i = 0; i < 128; i++)
   {
      fapi_tsd_handles[i].magic = 0x747364;
      fapi_tsd_handles[i].blockIndex = -1;
      fapi_tsd_handles[i].pid = -1;
      fapi_tsd_handles[i].Data_72 = -1;
   }

   memset(tsdChannelUse, 0, sizeof(tsdChannelUse));

   memset(Data_21f61a00, 0, sizeof(Data_21f61a00));

   memset(Data_21f61a20, 0, sizeof(Data_21f61a20));

   memset(Data_21f285c0, 0, sizeof(Data_21f285c0));

   fapi_tsd_semaphore = FAPI_SYS_CREATE_SEMAPHORE(1);

   if (fapi_tsd_semaphore == 0)
   {
      return FAPI_TSD_ERR_SEMAPHORE_CREATE; //-23009;
   }

   memset(Data_21f399e0, 0, sizeof(Data_21f399e0));

   memset(Data_21f619e0, 0, sizeof(Data_21f619e0));

   memset(Data_21f619f0, 0, sizeof(Data_21f619f0));

   memset(Data_21f619e8, 0, sizeof(Data_21f619e8));

   memset(Data_21f619f8, 0, sizeof(Data_21f619f8));

   for (j = 0; j < 4; j++)
   {
      Data_21f2802c[j].Data_4 = 0;

      for (i = 0; i < 32; i++)
      {
         /*func_21c72d00_1*/tsdSetPidChannelActive(j, i, 1);
         /*func_21c72f24_1*/tsdSetPidConfig_1(j, i, 0);
         /*func_21c72f70_1*/tsdSetPidConfig_2(j, i, 0);
         /*func_21c73728_1*/tsdSetCrc(j, i, -1);
         /*func_21c73718_1*/tsdSetSbCtrl(j, i, 0);
         /*func_21c731c4_1*/tsdSetPidConfig_2_PesPayload(j, i, 1);
         /*func_21c73284_1*/tsdSetPidConfig_2_BypassDsc(j, i, 1);
      }
      //21c37bd0
      for (i = 0; i < 13; i++)
      {
         /*func_21c72ef8_1*/tsdSetPidValue(j, i, 0);
      }
      //21c37c1c
      for (i = 0; i < 256; i++)
      {
         /*func_21c73758_1*/tsdSetSfTargets(j, i, 0);
      }
      //21c37c68
      for (i = 0; i < 128; i++)
      {
         /*func_21c73880_1*/tsdSetSfPtr(j, i, 0);
      }
      //21c37cb4
      /*func_21c73758_1*/tsdSetSfTargets(j, 0, 0);
      /*func_21c73758_1*/tsdSetSfTargets(j, 1, 0);
      /*func_21c73880_1*/tsdSetSfPtr(j, 0, 0x80);
      /*func_21c72d78_1*/tsdSetStartDistance_TsStartDistance(j, 203);
   }

   gpioParams.version = FAPI_GPIO_VERSION;
   gpioParams.pin = FAPI_GPIO_PIN_AUTODETECT;
   gpioParams.function = FAPI_GPIO_IN_TS_A_CLK; //0x12d;
   gpioParams.callback = 0;

   for (j = 0; j < 4; j++)
   {
      if (j == 1)
      {
         gpioParams.function = FAPI_GPIO_IN_TS_B_CLK; //0x122;
      }
      else if (j == 2)
      {
         gpioParams.function = FAPI_GPIO_IN_TS_C_CLK; //0x117;
      }
      else if (j == 3)
      {
         gpioParams.function = FAPI_GPIO_OUT_TS_CLK; //0xc7;
      }

      fapi_tsd_gpio[j].Data_0 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_PSTART

      fapi_tsd_gpio[j].Data_4 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_EN

      fapi_tsd_gpio[j].Data_8 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_0

      fapi_tsd_gpio[j].Data_12 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_1

      fapi_tsd_gpio[j].Data_16 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_2

      fapi_tsd_gpio[j].Data_20 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_3

      fapi_tsd_gpio[j].Data_24 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_4

      fapi_tsd_gpio[j].Data_28 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_5

      fapi_tsd_gpio[j].Data_32 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_6

      fapi_tsd_gpio[j].Data_36 = FAPI_GPIO_Open(&gpioParams, 0);

      gpioParams.function++; //FAPI_GPIO_OUT_TS_DATA_7

      fapi_tsd_gpio[j].Data_40 = FAPI_GPIO_Open(&gpioParams, 0);
   }

   gpregParams.version = FAPI_GPREG_VERSION;
   gpregParams.index = FAPI_GPREG_RECOVERY; //6;

   fapi_tsd_gpreg = FAPI_GPREG_Open(&gpregParams, &res);

   /*func_21c736fc*/FREG_TSD01_SetIrqClear(0);
   /*func_21c743e0*/FREG_TSD23_SetIrqClear(0);

   func_21c2f7a4(); //->fapi_sync.c

   Data_21efc17c = -1;
   Data_21efc178 = -1;

   fapi_tsd_initialized = 1;

   return res;
}


/* 21c38994 - complete */
void FAPI_TSD_Exit(void)
{
   int i;

   if (fapi_tsd_initialized != 0)
   {
      for (i = 127; i >= 0; i--)
      {
         if (fapi_tsd_handles[i].inUse == 1)
         {
            FAPI_TSD_Close(&fapi_tsd_handles[i]);
         }
      }
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, -1);

   for (i = 0; i < 4; i++)
   {
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_0);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_4);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_8);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_12);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_16);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_20);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_24);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_28);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_32);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_36);
      FAPI_GPIO_Close(fapi_tsd_gpio[i].Data_40);
   }

   FAPI_SYNC_Close(tsdSyncHandle);

   FAPI_GPREG_Close(fapi_tsd_gpreg);

   fapi_tsd_initialized = 0;

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, 0);

   FAPI_SYS_DESTROY_SEMAPHORE(fapi_tsd_semaphore);

   fapi_tsd_semaphore = 0;
}


/* 21c3679c - todo */
uint32_t FAPI_TSD_Isr01(void)
{

}


/* 21c356c8 - todo */
uint32_t FAPI_TSD_Isr23(void)
{

}


/* 21c3186c - todo */
void FAPI_TSD_Bsr(uint32_t privData)
{

}


/* 21c3179c - todo */
uint32_t func_21c3179c(uint64_t pts, void* optDataPtr)
{
   FAPI_SYS_PRINT_MSG("func_21c3179c\n");
}


/* 21c324dc - complete */
FAPI_SYS_HandleT FAPI_TSD_Open(const FAPI_TSD_OpenParamsT* paramsPtr,
                               int32_t* errorCodePtr)
{
   struct fapi_tsd_handle* h; //r7
   int32_t res = 0; //r4
   uint32_t i;
   int32_t channelId = -1; //sp

   if (fapi_tsd_initialized == 0)
   {
      res = FAPI_TSD_ERR_NOT_INITIALIZED; //-23004;
   }

   if (paramsPtr == 0)
   {
      //21c327a0
      res = FAPI_TSD_ERR_BAD_PARAMETER;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   
   if (paramsPtr->version > (int32_t)0x00050000) //FAPI_TSD_VERSION)
   {
      res = FAPI_TSD_ERR_UNSUPPORTED_VERSION;
   }

   if (paramsPtr->blockIndex > 3)
   {
      res = FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if (Data_21f2802c[paramsPtr->blockIndex].Data_4 == 0)
   {
      res = FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if ((paramsPtr->channelId < FAPI_TSD_CHANNEL_AUTODETECT) ||
         (paramsPtr->channelId > 31))
   {
      res = FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if (paramsPtr->channelId != FAPI_TSD_CHANNEL_AUTODETECT)
   {
      if (tsdChannelUse[paramsPtr->blockIndex][paramsPtr->channelId] == 1)
      {
         res = FAPI_TSD_ERR_BAD_PARAMETER;
      }
   }

   if (res != 0)
   {
      //21c326c8
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   if (paramsPtr->channelId == FAPI_TSD_CHANNEL_AUTODETECT)
   {
      //21c326dc
      for (i = 0; i < 32; i++)
      {
         if (tsdChannelUse[paramsPtr->blockIndex][i] == 0)
         {
            //21c32710
            channelId = i;
            break;
         }
      }

      if (channelId == -1)
      {
         res = FAPI_TSD_ERR_OUT_OF_MEMORY;
      }
   }
   else
   {
      //21c325ac
      //sp = -1;
   }
   //21c325b4
   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);
   //21c325d4
   if (res != 0)
   {
      //21c326c8
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   //21c325dc
   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);
   //21c325fc
   h = tsdGetHandle(paramsPtr->blockIndex);
   //21c32680
   if (fapi_tsd_check_handle(h))
   {
      //21c32720
      memcpy(&h->openParams, paramsPtr, sizeof(FAPI_TSD_OpenParamsT));

      if (paramsPtr->channelId != FAPI_TSD_CHANNEL_AUTODETECT)
      {
         h->channelId = paramsPtr->channelId;
      }
      else
      {
         h->channelId = channelId;
      }

      tsdChannelUse[paramsPtr->blockIndex][h->channelId] = 1;

      if (Data_21f2802c[paramsPtr->blockIndex].Data_8 != 0)
      {
         //21c32790
         func_21c32398(h, 1);
      }
      //21c32770
      h->ptsEvaluator = func_21c3179c;
      h->ptsEvaluatorDataPtr = h;
   }
   else
   {
      res = FAPI_TSD_ERR_OUT_OF_MEMORY;
   }
   //21c32694
   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);
   //21c326b4
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }

   return h;
}


/* 21c386f8 - complete */
int32_t FAPI_TSD_Close(FAPI_SYS_HandleT handle)
{
   int32_t res;
   struct fapi_tsd_handle* a = handle;

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   if (0 != fapi_tsd_check_handle(a))
   {
      res = func_21c352f4(a);

      if (res == FAPI_TSD_ERR_NO_PID_ASSIGNED) //-23101)
      {
         res = 0;
      }

      FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

      if (res != 0)
      {
         return res;
      }

      res = FAPI_TSD_SetPesParser(handle, 0, 0, 0);

      if ((res < 0) && (res != FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED)) //-23110))
      {
         return res;
      }

      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      tsdChannelUse[a->blockIndex][a->channelId] = 0;

      func_21c32398(a, 0);

      FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

      res = FAPI_TSD_SetPacketEndNotifier(handle, 0, 0, 0);

      if (res == 0)
      {
         res = FAPI_TSD_SetScrambledPacketNotifier(handle, 0, 0, 0, 0);
      }

      if (res == 0)
      {
         res = FAPI_TSD_SetPacketTimeoutNotifier(handle, 0, 0, 0, 0);
      }

      if (res == 0)
      {
         res = func_21c31e88(handle, 0, 0, 0);
      }

      if (res == FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED) //-23110)
      {
         res = 0;
      }

      if (res == 0)
      {
         res = FAPI_TSD_SetPtsEvaluator(handle, 0, 0, 0);
      }

      if (res == FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED) //-23110)
      {
         res = 0;
      }

      if (res == 0)
      {
         res = func_21c38100(handle);
      }

      if (res == FAPI_TSD_ERR_NO_FILTER_ASSIGNED) //-23109)
      {
         res = 0;
      }

      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      if (res == 0)
      {
         fapi_tsd_clear_handle(a);
      }
   }
   else
   {
      res = FAPI_TSD_ERR_INVALID_HANDLE; //-23008;
   }

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);
   
   return res;
}


/* 21c33984 - todo */
int32_t FAPI_TSD_SetPesParser(FAPI_SYS_HandleT handle,
                              uint32_t removeHeader,
                              uint32_t enableNewPtsIrq,
                              uint32_t enablePesParser)
{
   uint32_t sl;
   uint32_t i;
   struct fapi_tsd_handle* a = handle;
   int32_t res = 0;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (tsdGetPidChannelActive(a->blockIndex, a->channelId) & 2)
   {
      return FAPI_TSD_ERR_PID_ACTIVE; //-23113;
   }

   if (a->blockIndex < 2) sl = 0; else sl = 1;

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   if (enablePesParser)
   {
      //21c33a18
      if (removeHeader) removeHeader = 1; else removeHeader = 0;

      for (i = 0; i < 4; i++)
      {
         if (Data_21f285c0[sl][i] == 0)
         {
            //->21c33b14
            a->Data_72 = i;
            Data_21f285c0[sl][i] = 1;
            res = i;
            break;
         }
      }

      if (i == 4)
      {
         //->21c33a4c
         FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

         return FAPI_TSD_ERR_PES_PARSER_COUNT_EXEEDED; //-23102;
      }
      //21c33b34
      if ((a->blockIndex == 0) || (a->blockIndex == 2))
      {
         tsdSetPesCfg_Tsd13Select(a->blockIndex, a->Data_72, 0);
      }
      else
      {
         //21c33bd8
         tsdSetPesCfg_Tsd13Select(a->blockIndex, a->Data_72, 1);
      }
      tsdSetPesCfg_PidIndex(a->blockIndex, a->Data_72, a->channelId);
      tsdSetPesCfg_RemovePesHeader(a->blockIndex, a->Data_72, removeHeader);
      tsdSetPesCfg_NewPtsIrqEn(a->blockIndex, a->Data_72, 0);

      if (enableNewPtsIrq)
      {
         //21c33ba4
         tsdSetPesCfg_NewPtsIrqEn(a->blockIndex, a->Data_72, 1);
//         tsdSetPesCfg_PesEn(a->blockIndex, a->Data_72, 1);
         //->21c33ac0
      }
      else
      {
         //21c33bf4
         tsdSetPesCfg_NewPtsIrqEn(a->blockIndex, a->Data_72, 0);
//         tsdSetPesCfg_PesEn(a->blockIndex, a->Data_72, 1);
      }

      tsdSetPesCfg_PesEn(a->blockIndex, a->Data_72, 1);
      //->21c33ac0
   }
   else
   {
      //21c33a60
      res = a->Data_72;

      if (a->Data_72 == -1)
      {
         //21c33c54
         FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

         return FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED; //-23110;
      }
      //21c33a6c
      tsdSetPesCfg_PesEn(a->blockIndex, a->Data_72, 0);
      tsdSetPesCfg_NewPtsIrqEn(a->blockIndex, a->Data_72, 0);

      Data_21f285c0[sl][a->Data_72] = 0;

      a->Data_72 = -1;
      //->21c33ac0
   }

   //21c33ac0
   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c33cb0 - complete */
int32_t FAPI_TSD_SetPacketEndNotifier(const FAPI_SYS_HandleT handle,
                                      FAPI_TSD_GeneralNotifyT notifier,
                                      void* optDataPtr,
                                      const uint32_t enableNotifier)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (enableNotifier)
   {
      if (a->Data_388 != 0)
      {
         return FAPI_TSD_ERR_NOTIFIER_ALREADY_ASSIGNED;
      }

      if (notifier == NULL)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      a->Data_388 = notifier;
      a->Data_392 = optDataPtr;

      tsdSetPidConfig_2_PacketEndIrqEn(a->blockIndex, a->channelId, 1);
   }
   else
   {
      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      a->Data_388 = 0;
      a->Data_392 = 0;

      tsdSetPidConfig_2_PacketEndIrqEn(a->blockIndex, a->channelId, 0);

      func_21c31434(a, 224);

   }

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c34348 - complete */
int32_t FAPI_TSD_SetPacketTimeoutNotifier(const FAPI_SYS_HandleT handle,
                                          FAPI_TSD_GeneralNotifyT notifier,
                                          void* optDataPtr,
                                          const uint32_t enableNotifier,
                                          const uint32_t timeout)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (enableNotifier)
   {
      if (a->Data_408 != NULL)
      {
         return FAPI_TSD_ERR_NOTIFIER_ALREADY_ASSIGNED; //-23107;
      }

      if (notifier == NULL)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      if (timeout > 32400000)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      a->Data_408 = notifier;
      a->Data_412 = optDataPtr;

      tsdSetValidInputTimeout(a->blockIndex, timeout);
      tsdSetPidConfig_2_ValidInputTimeoutIrqEn(a->blockIndex, a->channelId, 1);
   }
   else
   {
      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      a->Data_408 = NULL;
      a->Data_412 = NULL;

      tsdSetPidConfig_2_ValidInputTimeoutIrqEn(a->blockIndex, a->channelId, 0);

      func_21c31434(a, 226);
   }

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c31d20 - complete */
int32_t FAPI_TSD_GetBuffer(FAPI_SYS_HandleT handle,
                           FAPI_BM_InfoT* bufferInfoPtr)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (a->Data_68 == 0)
   {
      return FAPI_TSD_ERR_NO_MAPPED_BUFFER;
   }

   if (bufferInfoPtr == NULL)
   {
      return FAPI_TSD_ERR_BAD_PARAMETER;
   }

   //memcpy(bufferInfoPtr, &a->bufferInfo, sizeof(FAPI_BM_InfoT));
   *bufferInfoPtr = a->bufferInfo;

   return res;
}


/* 21c32398 - complete */
void func_21c32398(struct fapi_tsd_handle* a, uint32_t b)
{
   uint32_t r5 = 0;

   if (fapi_tsd_check_handle(a))
   {
      if (b == 0)
      {
//         r5 = 0;
      }
      else
      {
         if (Data_21f2805c[0] == 0)
         {
            if (a->blockIndex > 1)
               r5 = 0;
            else
               r5 = 1;
         }
         else
         {
            if ((a->blockIndex > 1) && (a->blockIndex < 4))
               r5 = 1;
            else
               r5 = 0;
         }
      }

      tsdSetPidConfig_2_ExtractPcr(a->blockIndex, a->channelId, r5);
      tsdSetLoadPcr(a->blockIndex, r5);
      tsdSetPidConfig_2_NewPcrIrqEn(a->blockIndex, a->channelId, r5);
   }
}


/* 21c32378 - complete */
int32_t tsdGetChannelId(struct fapi_tsd_handle* a)
{
   if (fapi_tsd_check_handle(a))
   {
      return a->channelId;
   }
   else
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }
}


/* 21c35158 - complete */
int32_t FAPI_TSD_SetScrambledPacketNotifier(const FAPI_SYS_HandleT handle,
                                            FAPI_TSD_GeneralNotifyT notifier,
                                            void* optDataPtr,
                                            const uint32_t enableNotifier,
                                            const uint32_t enableOneShot)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (enableNotifier)
   {
      if (a->Data_396 != NULL)
      {
         return FAPI_TSD_ERR_NOTIFIER_ALREADY_ASSIGNED; //-23107;
      }

      if (notifier == NULL)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      a->Data_396 = notifier;
      a->Data_400 = optDataPtr;

      tsdSetPidConfig_2_ScrambledPacketIrqEn(a->blockIndex, a->channelId, 1);

      if (enableOneShot)
      {
         a->Data_404 = 1;
      }
   }
   else
   {
      FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

      a->Data_396 = NULL;
      a->Data_400 = NULL;
      a->Data_404 = 0;

      tsdSetPidConfig_2_ScrambledPacketIrqEn(a->blockIndex, a->channelId, 0);
   }

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c31f08 - complete */
int32_t FAPI_TSD_SetPtsEvaluator(const FAPI_SYS_HandleT handle,
                                 FAPI_TSD_PtsEvaluateT evaluator,
                                 void* optDataPtr,
                                 const uint32_t enableEvaluator)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (a->Data_72 == -1)
   {
      return FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED;
   }

   if (enableEvaluator)
   {
      if ((a->ptsEvaluator != NULL) &&
            (a->ptsEvaluator != func_21c3179c))
      {
         return FAPI_TSD_ERR_EVALUATOR_ALREADY_ASSIGNED;
      }

      if (evaluator == NULL)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      a->ptsEvaluatorDataPtr = optDataPtr;
      a->ptsEvaluator = evaluator;
   }
   else
   {
      a->ptsEvaluator = NULL;
      a->ptsEvaluatorDataPtr = NULL;
   }

   return res;
}


/* 21c31e88 - complete */
int32_t func_21c31e88(FAPI_SYS_HandleT handle,
      void (*notifier)(void*),
      void* optDataPtr, const uint32_t enableNotifier)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (a->Data_72 == -1)
   {
      return FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED;
   }

   if (enableNotifier)
   {
      if (a->Data_76 != NULL)
      {
         return FAPI_TSD_ERR_NOTIFIER_ALREADY_ASSIGNED;
      }

      if (notifier == NULL)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      a->Data_80 = optDataPtr;
      a->Data_76 = notifier;
   }
   else
   {
      a->Data_76 = NULL;
      a->Data_80 = NULL;
   }

   return res;
}


/* 21c377fc - todo */
int32_t FAPI_TSD_SetBuffer(FAPI_SYS_HandleT handle,
                           const FAPI_BM_InfoT bufferInfo)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (bufferInfo.channelId > 31)
   {
      return FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if (bufferInfo.blockIndex != a->blockIndex)
   {
      return FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if (2 & tsdGetPidChannelActive(a->blockIndex, a->channelId))
   {
      return FAPI_TSD_ERR_PID_ACTIVE; //-23113;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   func_21c31434(a, 225);

   tsdSetPidConfig_1_BufferIndex(a->blockIndex,
         a->channelId, bufferInfo.channelId);

   a->bufferInfo = bufferInfo;

   a->Data_68 = 1;
   a->Data_368 = 0;
   a->Data_372 = 0;

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c38100 - todo */
int32_t func_21c38100(FAPI_SYS_HandleT handle)
{
   uint32_t r7, r6;
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (a->Data_108 == 0)
   {
      return FAPI_TSD_ERR_NO_FILTER_ASSIGNED; //-23109;
   }

   if (2 & tsdGetPidChannelActive(a->blockIndex, a->channelId))
   {
      return FAPI_TSD_ERR_PID_ACTIVE; //-23113;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   func_21c31434(a, 225);

   r6 = a->Data_92;

   tsdSetPidConfig_2_CrcErrIrqEn(a->blockIndex, a->channelId, 0);
   tsdSetPidConfig_2_PtrTarget(a->blockIndex, a->channelId, 0);
   tsdSetPidConfig_2_NTarget(a->blockIndex, a->channelId, 0);
   tsdSetPidConfig_2_PesPayload(a->blockIndex, a->channelId, 1);
   tsdSetPidConfig_2_SectionEndIrqEn(a->blockIndex, a->channelId, 0);
   tsdSetPidConfig_2_TargetLength(a->blockIndex, a->channelId, 0);

   for (r7 = a->Data_92; r7 <= a->Data_96; r7++) //, r6++)
   {
      //21c38288 -> 21c38430
#if 1
      uint32_t r5 = r6++ * 2;

      tsdSetSfTargets_SecData0(a->blockIndex, r5, 0);
      //21c382b8
      tsdSetSfTargets_FilterEnable0(a->blockIndex, r5, 0);
      tsdSetSfTargets_SecData1(a->blockIndex, r5, 0);
      tsdSetSfTargets_FilterEnable1(a->blockIndex, r5, 0);
      //21c38330
//      r5 = r6*2 + 1;
      r5++;

      tsdSetSfTargets_SecData0(a->blockIndex, r5, 0);
      tsdSetSfTargets_FilterEnable0(a->blockIndex, r5, 0);
      tsdSetSfTargets_SecData1(a->blockIndex, r5, 0);
      tsdSetSfTargets_FilterEnable1(a->blockIndex, r5, 0);
#else
      uint32_t j;
      for (j = 0; j < 2; j++)
      {
         tsdSetSfTargets_SecData0(a->blockIndex, r7+j, 0);
         tsdSetSfTargets_FilterEnable0(a->blockIndex, r7+j, 0);
         tsdSetSfTargets_SecData1(a->blockIndex, r7+j, 0);
         tsdSetSfTargets_FilterEnable1(a->blockIndex, r7+j, 0);
      }
#endif
      //21c383d4
      tsdSetSfPtr(a->blockIndex, r7, 128);

      Data_21efc104[a->blockIndex]++;
      Data_21f61a20[a->blockIndex][r7] = 0;
   }
   //21c3853c
   a->Data_92 = 0;
   a->Data_96 = 0;
   a->Data_108 = 0;

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c38ae8 - todo */
int32_t FAPI_TSD_SetSectionFilter(const FAPI_SYS_HandleT handle,
                                  const FAPI_TSD_NumberOfTablesT numberOfTables,
                                  const FAPI_TSD_FilterDataT* filterDataPtr)
{
   uint32_t r5 = 1;
   uint32_t r8;
   uint32_t r6;
   uint32_t r4;
   uint32_t r3;
   uint32_t sl = 0;
   int32_t r9 = 0;
   uint32_t r0;
   uint32_t r2;
   char sp12[1024]; //1024
   uint32_t sp1036[] = {
0x00000000, 0x00000001, 0x00000002,
0x00000000, 0x00000008, 0x00000000, 0x00000000,
0x00000000, 0x00000009, 0x00000000, 0x00000000,
0x00000000, 0x0000000a, 0x00000000, 0x00000000,
0x00000000, 0x0000000b, 0x00000000, 0x00000000,
0x00000000, 0x0000000c, 0x00000000, 0x00000000,
0x00000000, 0x0000000d, 0x00000000, 0x00000000,
0x00000000, 0x0000000e, 0x00000000, 0x00000000,
0x00000000, 0x0000000f,
   }; //sp1036
   //uint32_t sp1168[10];
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;
   uint32_t lr = 24;
   uint32_t ip = 1;
   uint32_t i;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (filterDataPtr == NULL)
   {
      return FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if (2 & tsdGetPidChannelActive(a->blockIndex, a->channelId))
   {
      return FAPI_TSD_ERR_PID_ACTIVE; //-23113;
   }

   uint32_t sp1168[] = {
0x00000001, 0x00000002,
0x00000004, 0x00000008, 0x0000000c, 0x00000010,
0x00000014, 0x00000018, 0x0000001c, 0x00000020,
};

   switch (numberOfTables)
   {
   case FAPI_TSD_1_TABLE:
      //21c38e24
      break;

   case FAPI_TSD_2_TABLES:
      //21c38e18
      ip = 2;
      break;

   case FAPI_TSD_4_TABLES:
      //21c38e0c
      ip = 4;
      break;

   case FAPI_TSD_8_TABLES:
      //21c38e00
      ip = 8;
      break;

   case FAPI_TSD_12_TABLES:
      //21c38df4
      ip = 12;
      break;

   case FAPI_TSD_16_TABLES:
      //21c38de8
      ip = 16;
      break;

   case FAPI_TSD_20_TABLES:
      //21c38ddc
      ip = 20;
      break;

   case FAPI_TSD_24_TABLES:
      //21c38dd0
      lr = 20;
      ip = 24;
      break;

   case FAPI_TSD_28_TABLES:
      //21c38dc4
      lr = 17;
      ip = 28;
      break;

   case FAPI_TSD_32_TABLES:
      //21c38c54
      lr = 15;
      ip = 32;
      break;

   default:
      //21c38c4c
      return FAPI_TSD_ERR_INVALID_FILTER_SETTINGS; //-23104;
   }
   //21c38c5c
   r0 = 0;
   for (r2 = 0; r2 < ip; r2++)
   {
      //21c38c78
      if (filterDataPtr[r2].notifyOnNewVersion != FAPI_TSD_IGNORE_VERSION)
      {
         r0++;
      }

      if (filterDataPtr[r2].numberOfSectionBytes > lr)
      {
         //21c38c94
         r9 = -r2;
         //21c38c98
         break;
      }
      //21c38c6c
   } //for (r2 = 0; r2 < ip; r2++)
   //21c38c28
   if (r9 >= 0)
   {
      for (r2 = 0; r2 < 10; r2++)
      {
         //21c38c30
         if (sp1168[r2] > (r0+ip))
         {
            //->21c38e5c
            break;
         }
      }
      //21c38e5c
      if (r2 == 10)
      {
         //21c38c4c
         return FAPI_TSD_ERR_INVALID_FILTER_SETTINGS; //-23104;
      }
      //21c38e64
      r9 = sp1168[r2];
   }
   //21c38c98
   if (r9 <= 0)
   {
      //21c38c4c
      return FAPI_TSD_ERR_INVALID_FILTER_SETTINGS; //-23104;
   }
   //21c38ca0
   FAPI_TSD_FilterDataT* sp4 = sp12;

   func_21c38100(a);

   memset(sp4, 0, 1024);

   for (i = 0; i < numberOfTables; i++)
   {
      if (filterDataPtr[i].numberOfSectionBytes > sl)
      {
         sl = filterDataPtr[i].numberOfSectionBytes;
      }
   }

   r3 = (sl+1) * r9;
   r2 = r3 & 3;
   if (r2 != 0)
   {
      r3 = sl+4;
      sl = r3 - r2;
   }
   //21c38d14
   for (i = 0; i < r9; i++)
   {
      //21c38d84
      FAPI_TSD_FilterDataT* r4 = &sp4[i];

      if ((i < numberOfTables) &&
            //21c38d1c
            (filterDataPtr[i].filterBytes != NULL))
      {
         //21c38d28
         memcpy(r4, &filterDataPtr[i], sizeof(FAPI_TSD_FilterDataT));
         //sp4[i] = filterDataPtr[i];

         if ((r4->tableId == FAPI_TSD_TDT_TABLE) ||
               (r4->tableId == FAPI_TSD_ST_TABLE) ||
               (r4->tableId == FAPI_TSD_TOT_TABLE) ||
               (r4->tableId == FAPI_TSD_RST_TABLE) ||
               (r4->tableId == FAPI_TSD_DIT_TABLE) ||
               (r4->tableId == FAPI_TSD_SIT_TABLE))
         {
            //21c38e40
            if (r4->notifyOnNewVersion != FAPI_TSD_IGNORE_VERSION)
            {
               r4->notifyOnNewVersion = FAPI_TSD_IGNORE_VERSION;
            }
            //->21c38d70
         }
         //21c38d70
      }
      else
      {
         //21c38d8c
         r4->tableId = 0xFF;
         r4->numberOfSectionBytes = sl;
         r4->sectionBytes = Data_21f27fc8;
         r4->filterBytes = Data_21efc114;
         r4->oneShotFiltering = 0;
         r4->notifyFunction = 0;
         r4->optData = 0;
         r4->notifyOnNewVersion = FAPI_TSD_IGNORE_VERSION;
      }
      //21c38d70
   } //for (i = 0; i < r9; i++)
   //21c38e78
#if 0
   uint32_t fp = sl + 1;
   r2 = r9 * fp;
   uint32_t r4 = r2 >> 2;
   r3 = Data_21efc104[a->blockIndex];
   if (r4 > r3)
#else
   r4 = ((sl+1) * r9) / 4;
   if (r4 > Data_21efc104[a->blockIndex])
#endif
   {
      return FAPI_TSD_ERR_OUT_OF_MEMORY; //-23002;
   }
   //21c38ea0
   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);
   //21c38ec4
   r6 = 0;
   for (r8 = 0; r8 < 128; r8++)
   {
      //21c38ef4
      if (Data_21f61a20[a->blockIndex][r8] == 0)
      {
         //->21c38edc
         r6++;
         if (r6 > r4)
         {
            //->21c398dc
            r5 = 0;
            //->21c38f18
            break;
         }
      }
      else
      {
         //21c38f04
         if (r6 > r4)
         {
            //->21c398dc
            r5 = 0;
            //->21c38f18
            break;
         }

         r6 = 0;
      }
      //21c38ee8
   } //for (r8 = 0; r8 < 128; r8++)
   //21c38f14
   //r5 = 1;
   //21c38f18
   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   if ((r6 < r4) && (r5 == 1))
   {
      //->21c38e98
      return FAPI_TSD_ERR_OUT_OF_MEMORY; //-23002;
   }
   //21c38f4c
   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);
   //21c38f6c
   tsdSetPidConfig_2_CrcErrIrqEn(a->blockIndex, a->channelId, 1);

   r6--;
   r6 = r8 - r6;
   r4 = r6 * 2;
   a->Data_92 = r6;
   a->Data_108 = r9;

   tsdSetPidConfig_2_PtrTarget(a->blockIndex, a->channelId, r6); //a->Data_92);

   tsdSetPidConfig_2_NTarget(a->blockIndex, a->channelId, sp1036[r9]);

   tsdSetPidConfig_2_PesPayload(a->blockIndex, a->channelId, 0);

   tsdSetPidConfig_2_TargetLength(a->blockIndex, a->channelId, (sl+1)/*fp*/);

   tsdSetPidConfig_2_SectionEndIrqEn(a->blockIndex, a->channelId, 1);
   //21c39080
   //r1 = sp4
   //r8 = a
   //r5 = sp4 + 16
   //->21c3916c
   for (i/*fp*/ = 0; i < r9; i++)
   {
      if (sp4[i].oneShotFiltering)
      {
         a->Data_100 |= (1 << i);
      }

      a->Data_112[i] = sp4[i].notifyFunction;

      a->Data_240[i] = sp4[i].optData;

      if (sp4[i].notifyOnNewVersion != FAPI_TSD_IGNORE_VERSION)
      {
         a->Data_416[i] = FAPI_TSD_CHECK_VERSION;
      }
      else
      {
         a->Data_416[i] = FAPI_TSD_IGNORE_VERSION;
      }

      if (i & 1)
      {
         //->21c39094
         tsdSetSfTargets_SecData1(a->blockIndex, r4, sp4[i].tableId);

         if (sp4[i].filterBytes == 0)
         {
            //->21c397a0
            tsdSetSfTargets_FilterEnable1(a->blockIndex, r4, 0);
         }
         else
         {
            //21c390cc
            tsdSetSfTargets_FilterEnable1(a->blockIndex, r4,
                  sp4[i].filterBytes);
         }
         //21c390f4
         if (r4 & 1)
         {
            //21c390fc
            uint32_t r0;

            Data_21f61a20[a->blockIndex][r6] = 1;
            r0 = r6++;
            tsdSetSfPtr(a->blockIndex, r0, r6);

            Data_21efc104[a->blockIndex]--;
         }
         //21c39154
         r4++;
      }
      else
      {
         //21c391b0
         tsdSetSfTargets_SecData0(a->blockIndex, r4, sp4[i].tableId);

         if (sp4[i].filterBytes == 0)
         {
            //->21c396f4
            tsdSetSfTargets_FilterEnable0(a->blockIndex, r4, 0);
         }
         else
         {
            //21c391e8
            tsdSetSfTargets_FilterEnable0(a->blockIndex, r4,
                  (uint32_t)(sp4[i].filterBytes));
         }
         //->21c39158
      }
   } //for (i/*fp*/ = 0; i < r9; i++)
   //21c39214
   for (i/*fp*/ = 0; i < sl; i++)
   {
      //21c39220
      //r8 = sp4
      //sp8 = fp(i) * 4
      //sp = fp(i)+1
      //r5 = 0
      //->21c392b0
      uint32_t r5;
      for (r5 = 0; r5 < r9; r5++)
      {
         //21c392b0
         if ((r5 & 1) ||
               //21c3923c
               ((r9 == 1) &&
                     //->21c39514
                     ((i & 1) == 0)))
         {
            //21c392b8
            if (i < sp4[r5].numberOfSectionBytes)
            {
               //->21c3937c
               tsdSetSfTargets_SecData1(a->blockIndex, r4,
                     sp4[r5].sectionBytes[i]);
               //21c393ac
               if (sp4[r5].filterBytes[i+1] == 0)
               {
                  //->21c394ec
                  tsdSetSfTargets_FilterEnable1(a->blockIndex, r4, 0);
               }
               else if ((i+1) < sp4[r5].numberOfSectionBytes)
               {
                  //->21c394ec
                  tsdSetSfTargets_FilterEnable1(a->blockIndex, r4,
                        sp4[r5].filterBytes[i+1]);
               }
               else
               {
                  //21c393d4
                  tsdSetSfTargets_FilterEnable1(a->blockIndex, r4, -1);
               }
               //->21c39314
            }
            else
            {
               //21c392c4
               tsdSetSfTargets_SecData1(a->blockIndex, r4, 0);
               tsdSetSfTargets_FilterEnable1(a->blockIndex, r4, 0);
               //21c39314
            }
            //21c39314
            if (r4 & 1)
            {
               //21c3931c
               Data_21f61a20[a->blockIndex][r6] = 1;

               tsdSetSfPtr(a->blockIndex, r6, r6+1);
               r6++;

               Data_21efc104[a->blockIndex]--;
            }
            //21c39374
            r4++;
            //->21c392a0
         }
         else
         {
            //21c39244
            if (i < sp4[r5].numberOfSectionBytes)
            {
               //->21c39468
               tsdSetSfTargets_SecData0(a->blockIndex, r4,
                     sp4[r5].sectionBytes[i]);
               //21c393ac
               if (sp4[r5].filterBytes[i+1] == 0)
               {
                  //->21c39520
                  tsdSetSfTargets_FilterEnable0(a->blockIndex, r4, 0);
               }
               else if ((i+1) < sp4[r5].numberOfSectionBytes)
               {
                  //->21c39520
                  tsdSetSfTargets_FilterEnable0(a->blockIndex, r4,
                        sp4[r5].filterBytes[i+1]);
               }
               else
               {
                  //21c394c0
                  tsdSetSfTargets_FilterEnable0(a->blockIndex, r4, -1);
               }
               //->21c392a0
            }
            else
            {
               //21c39250
               tsdSetSfTargets_SecData0(a->blockIndex, r4, 0);
               tsdSetSfTargets_FilterEnable0(a->blockIndex, r4, 0);
            }
         }
         //21c392a0
      } //for (r5 = 0; r5 < r9; r5++)
      //21c39400
   } //for (i/*fp*/ = 0; i < sl; i++)
   //21c3940c
//   r4 = r6 - 1;
   tsdSetSfPtr(a->blockIndex, r6 - 1, 128);

   a->Data_96 = r6 - 1;

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c354a4 - complete */
int32_t func_21c354a4(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   res = func_21c352f4(a);

   if ((a->channelId == Data_21efc178) &&
         (a->blockIndex == Data_21efc17c))
   {
      func_21c2f7a4();

      Data_21efc178 = -1;
      Data_21efc17c = -1;
   }

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c33e24 - complete */
void tsdSetChannelPid(struct fapi_tsd_handle* a,
      uint32_t enableContinuityCheck,
      uint32_t removeTsHeader)
{
   uint32_t setMask, unsetMask;
   uint32_t irqFlags;
   uint32_t sp[13];
   int32_t i = 0;
   uint32_t pid = a->pid;

   memset(sp, 0, sizeof(sp));

   for (i = 0; i < 13; i++)
   {
      sp[i] = tsdGetmPidValue(a->blockIndex, i);
   }

   setMask = (1 << a->channelId);
   unsetMask = ~(1 << a->channelId);
   for (i = 12; i >= 0; i--)
   {
      if (pid & 1)
      {
         sp[i] |= setMask;
      }
      else
      {
         sp[i] &= unsetMask;
      }
      pid >>= 1;
   }

   irqFlags = FAPI_SYS_DISABLE_IRQ;

   for (i = 0; i < 13; i++)
   {
      tsdSetPidValue(a->blockIndex, i, sp[i]);
   }

   FAPI_SYS_ENABLE_IRQ(irqFlags);

   if (enableContinuityCheck)
   {
      tsdSetPidConfig_2_CcCheck(a->blockIndex, a->channelId, 1);
      tsdSetPidConfig_2_PsiCcCheckMode(a->blockIndex, a->channelId, 1);
      tsdSetPidConfig_2_CcIrqEn(a->blockIndex, a->channelId, 1);
   }
   else
   {
      tsdSetPidConfig_2_CcCheck(a->blockIndex, a->channelId, 0);
      tsdSetPidConfig_2_PsiCcCheckMode(a->blockIndex, a->channelId, 0);
      tsdSetPidConfig_2_CcIrqEn(a->blockIndex, a->channelId, 0);
   }

   if (removeTsHeader)
   {
      tsdSetPidConfig_2_StoreCompletePacket(a->blockIndex, a->channelId, 0);
   }
   else
   {
      tsdSetPidConfig_2_StoreCompletePacket(a->blockIndex, a->channelId, 1);
   }
}


/* 21c34248 - complete */
int32_t FAPI_TSD_SetFreeChannelPid(FAPI_SYS_HandleT handle,
      const uint32_t pid,
      const uint32_t enableContinuityCheck,
      const uint32_t removeTsHeader)
{
   uint32_t i = 0;
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   if (pid != a->pid)
   {
      for (i = 0; i < 128; i++)
      {
         struct fapi_tsd_handle* r1 = &fapi_tsd_handles[i];

         if ((r1->pid == pid) &&
               (r1->blockIndex == a->blockIndex))
         {
            FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

            return FAPI_TSD_ERR_PID_ALREADY_ASSIGNED; //-23105;
         }
      }

      a->pid = pid;
   }

   tsdSetChannelPid(a, enableContinuityCheck, removeTsHeader);

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c350ac - complete */
void func_21c350ac(struct fapi_tsd_handle* a)
{
   uint32_t r0, r1;

   r0 = FAPI_BM_GetBufferReadPointerPosition((FAPI_SYS_HandleT)a->bufferInfo.privData);

   if (r0 > a->bufferInfo.size)
   {
      FAPI_BM_SetBufferReadPointer((FAPI_SYS_HandleT)a->bufferInfo.privData, r0, 1);
   }
   else
   {
      FAPI_BM_SetBufferReadPointer((FAPI_SYS_HandleT)a->bufferInfo.privData, 0, 0);
   }

   r1 = FAPI_BM_GetBufferWritePointerPosition((FAPI_SYS_HandleT)a->bufferInfo.privData);

   if (r1 > a->bufferInfo.size)
   {
      FAPI_BM_SetBufferWritePointer((FAPI_SYS_HandleT)a->bufferInfo.privData, r1, 1);
   }
   else
   {
      FAPI_BM_SetBufferWritePointer((FAPI_SYS_HandleT)a->bufferInfo.privData, 0, 0);
   }

   a->Data_372 = 0;
   a->Data_368 = 0;

   func_21c31434(a, 225);

   func_21c34e8c(a);
}


/* 21c3555c - complete */
int32_t func_21c3555c(FAPI_SYS_HandleT handle)
{
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   func_21c352f4(a);

   a->pid = -1;

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return 0;
}


/* 21c355d8 - complete */
int32_t FAPI_TSD_SetChannelPid(FAPI_SYS_HandleT handle,
                               const uint32_t pid,
                               const uint32_t enableContinuityCheck,
                               const uint32_t removeTsHeader)
{
   uint32_t i = 0;
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   if (pid != a->pid)
   {
      for (i = 0; i < 128; i++)
      {
         if ((fapi_tsd_handles[i].pid == pid) &&
               (fapi_tsd_handles[i].blockIndex == a->blockIndex))
         {
            func_21c352f4(&fapi_tsd_handles[i]);

            fapi_tsd_handles[i].pid = -1;
         }
      }

      a->pid = pid;
   }

   tsdSetChannelPid(a, enableContinuityCheck, removeTsHeader);

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c34978 - complete */
int32_t tsdSetTs(const uint32_t tsdSelect,
      uint32_t tsSelect, const uint32_t useStc)
{
    uint32_t register_setting = 0;
    uint32_t register_mirror  = 0;

    /* check TS */
    if((tsSelect != FAPI_TS_A) &&
       (tsSelect != FAPI_TS_B) &&
       (tsSelect != FAPI_TS_C) &&
       (tsSelect != FAPI_TS_OUTPUT) &&
       (tsSelect != FAPI_TS_DISABLE))
        return(FAPI_TSD_ERR_BAD_PARAMETER);

    /********************/
    /* set MUX settings */
    /********************/

    /* get the current setting */
    register_mirror = FREG_TSD_GetIoChannelSelect();

    /* set TS bit mask */
    if((tsSelect != FAPI_TS_OUTPUT) && (tsSelect != FAPI_TS_DISABLE))
    {
        /* disable current tsSelect */
        register_mirror &= ~(uint32_t)(0x3UL << (tsdSelect * 2));
        /* set current tsSelect */
        register_setting = (tsSelect << (tsdSelect * 2));
        tsdSetInRamCfg_DisableTsInput(tsdSelect, 0);
    }
    else if(tsSelect == FAPI_TS_DISABLE)
    {
        tsdSetInRamCfg_DisableTsInput(tsdSelect, 1);
    }
    else
    {
        /* disable current tsSelect */
        register_mirror &= 0xFFFFFEFF;
        /* set current tsSelect */
        register_setting = ((tsdSelect >> 1) << 8);
    }

    /* enable STC */
    if(useStc)
    {
        register_setting |= ((tsdSelect >> 1) << 12);
    }

    FREG_TSD_SetIoChannelSelect(register_mirror | register_setting);

    return(FAPI_OK);
}


/* 21c34ac8 - todo */
int32_t FAPI_TSD_Configure(const uint32_t blockIndex, const uint32_t useStc,
                           const FAPI_TSD_TsInputSettingsT* tsInputSettingsPtr,
                           const FAPI_TSD_TsOutputSettingsT* tsOutputSettingsPtr)
{
   FAPI_SYNC_OpenParamsT sp;
   uint32_t r0;
   uint32_t fp;
   uint32_t sp8;
   uint32_t r8 = 0;
   uint32_t r9 = 0;
   uint32_t sl = 0;
   int32_t res = 0;

   if (!fapi_tsd_initialized)
   {
      return FAPI_TSD_ERR_NOT_INITIALIZED; //-23004;
   }

   if (blockIndex > 3)
   {
      return FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if ((tsInputSettingsPtr == NULL) &&
         (tsOutputSettingsPtr == NULL))
   {
      return FAPI_TSD_ERR_BAD_PARAMETER;
   }

   if (useStc) fp = 1; else fp = 0;
   //sp8 = 0;

   if ((tsdSyncHandle != 0) && useStc)
   {
      //21c34dbc
      if (FAPI_SYNC_Close(tsdSyncHandle) != 0)
      {
         return FAPI_TSD_ERR_NO_RECONFIGURE; //-23103;
      }
   }
   //21c34b40
   if (tsInputSettingsPtr != NULL)
   {
      //21c34b48
      res = tsdSetTs(blockIndex, tsInputSettingsPtr->tsSelect, useStc);
      if (res != 0)
      {
         //->21c34af4
         return res;
      }
      //21c34b60
      if (tsInputSettingsPtr->tsSelect != FAPI_TS_DISABLE)
      {
         //21c34b70
         if (tsInputSettingsPtr->tsSelect > FAPI_TS_C)
         {
            //->21c34b04
            return FAPI_TSD_ERR_BAD_PARAMETER;
         }
         //21c34b78
         if (tsInputSettingsPtr->version > (int32_t)0x50000)
         {
            //->21c34d4c
            return FAPI_TSD_ERR_UNSUPPORTED_VERSION; //-23010;
         }
         //21c34b84
         if (tsInputSettingsPtr->automaticSync)
         {
            r8 = 0x20;
         }
#if 0
         else
         {
            r8 = 0;
         }
#endif

         if (tsInputSettingsPtr->packetStartPolarity)
         {
            r8 |= 0x10;
         }

         if (tsInputSettingsPtr->enablePolarity)
         {
            r8 |= 0x08;
         }

         if (tsInputSettingsPtr->clockInvert)
         {
            r8 |= 0x04;
         }

         if (tsInputSettingsPtr->serialParallelMode != 0)
         {
            r8 |= tsInputSettingsPtr->serialParallelMode;
         }

#if 0
         if (blockIndex == 1)
         {
            r9 = 1;
         }

         if (blockIndex == 3)
         {
            sl = r9 | 1;
         }
         else
         {
            sl = r9;
         }
#else
         if ((blockIndex == 1) ||
               (blockIndex == 3))
         {
            sl = 1;
         }
#endif

         if (sl != 0)
         {
            r8 = r8 << 8;
         }

         r0 = tsdGetInputCtrl(blockIndex);

         if (sl)
         {
            r0 &= 0xff;
         }
         else
         {
            r0 &= 0xff00;
         }

         r0 |= r8;

         tsdSetInputCtrl(blockIndex, r0);

         if (tsInputSettingsPtr->serialParallelMode == 2)
         {
            //21c34de0
            if (tsInputSettingsPtr->syncByteDistance != 0)
            {
               //21c34dec
               tsdSetStartDistance_TsStartDistance(blockIndex,
                     tsInputSettingsPtr->syncByteDistance - 1);
            }
            //21c34c10
         }
         //21c34c10
         //sp8 = 0;
      }
      //21c34c18
   }
   //21c34c18
   if (tsOutputSettingsPtr != NULL)
   {
      //21c34c20
      tsdSetTs(blockIndex, 3, useStc);

      if (tsOutputSettingsPtr->prescaler == 0)
      {
         return FAPI_TSD_ERR_BAD_PARAMETER;
      }

      if (tsOutputSettingsPtr->version > (int32_t)0x50000)
      {
         //->21c34d4c
         return FAPI_TSD_ERR_UNSUPPORTED_VERSION; //-23010;
      }
      //21c34c48
      if (tsOutputSettingsPtr->tsOutMode)
      {
         tsdSetInRamCfg_TsOutMode(blockIndex,
               tsOutputSettingsPtr->tsOutMode);
      }
      //21c34c68
      if (tsOutputSettingsPtr->clockInvert)
      {
         tsdSetInRamCfg_InvertTsOutClk(blockIndex,
               tsOutputSettingsPtr->clockInvert);
      }
      //21c34c88
      if (tsOutputSettingsPtr->generateSync)
      {
         tsdSetInRamCfg_GenerateSyncSignal(blockIndex,
               tsOutputSettingsPtr->generateSync);
      }
      //21c34ca4
      if (tsOutputSettingsPtr->prescaler)
      {
         tsdSetInRamCfg_TsOutClkPrescaler(blockIndex,
               tsOutputSettingsPtr->prescaler);
      }
   }
   //21c34ccc
   if (fp != 0)
   {
      //21c34cd8
      if (blockIndex == 0)
      {
            //21c34ce0
            Data_21f2802c[0].Data_8 = 1;
            Data_21f2802c[1].Data_8 = 0;
            Data_21f2802c[2].Data_8 = 0;
            Data_21f2802c[3].Data_8 = 0;
            //21c34cf8
//            Data_21f2805c[0] = 0;
            //21c34d04
      }
      else if (blockIndex == 1)
      {
            //21c34e50
            Data_21f2802c[0].Data_8 = 0;
            Data_21f2802c[1].Data_8 = 1;
            Data_21f2802c[2].Data_8 = 0;
            Data_21f2802c[3].Data_8 = 0;
            //->21c34cf8
//            Data_21f2805c[0] = 0;
            //21c34d04
      }
      else if (blockIndex == 2)
      {
            //21c34e30
            Data_21f2802c[0].Data_8 = 0;
            Data_21f2802c[1].Data_8 = 0;
            Data_21f2802c[2].Data_8 = 1;
            Data_21f2802c[3].Data_8 = 0;
            //->21c34d88
//            Data_21f2805c[0] = 1;
            //21c34d04
      }
      else
      {
            //21c34d64
            Data_21f2802c[0].Data_8 = 0;
            Data_21f2802c[1].Data_8 = 0;
            Data_21f2802c[2].Data_8 = 0;
            Data_21f2802c[3].Data_8 = 1;
            //->21c34d88
//            Data_21f2805c[0] = 1;
            //21c34d04
      }
      
      if ((blockIndex == 0) || (blockIndex == 1))
      {
         Data_21f2805c[0] = 0;         
      }
      else
      {
         Data_21f2805c[0] = 1;         
      }
      
      sp.version = FAPI_SYNC_VERSION;
      sp.blockIndex = Data_21f2805c[0];
      
      tsdSyncHandle = FAPI_SYNC_Open(&sp, &res);
      
      if (tsdSyncHandle == 0)
      {
         return res;
      }
   }
   //21c34d30
   Data_21f2802c[blockIndex].Data_4 = 1;

   return res;
}


/* 21c34e8c - complete */
void func_21c34e8c(struct fapi_tsd_handle* a)
{
//   FAPI_SYS_PRINT_MSG("func_21c34e8c\n");

   tsdSetCrc(a->blockIndex, a->channelId, -1);
   tsdSetSbCtrl(a->blockIndex, a->channelId, 0);
   tsdSetPidChannelActive(a->blockIndex, a->channelId,
         1 | //FirstPacketFlag = 1 << 0
         2); //PidChannelEnable = 1 << 1
   tsdSetInputTimeout(a->blockIndex, 32400000);
   tsdSetPidConfig_2_InputTimeoutIrqEn(a->blockIndex, a->channelId, 1);
}


/* 21c352f4 - complete */
int32_t func_21c352f4(struct fapi_tsd_handle* a)
{
   uint64_t t1, t2;
   uint32_t status;

   if (2 & tsdGetPidChannelActive(a->blockIndex, a->channelId))
   {
      tsdSetPidChannelActive(a->blockIndex, a->channelId, 1);
      tsdSetPidConfig_2_InputTimeoutIrqEn(a->blockIndex, a->channelId, 0);

      t1 = FAPI_TIMER_GetTimeStamp(1);

      while (1)
      {
         t2 = FAPI_TIMER_GetTimeStamp(1);

         status = tsdGetStatus(a->blockIndex);

         if ((status & 0x400) == 0) //!TsdActive
         {
            break;
         }
         else if ((status & 0x200) == 0) //!PidMatchValid
         {

         }
         else if ((status & 0x100) == 0) //!PidMatch
         {
            break;
         }
         else if ((status & 0x20) != (a->blockIndex & 1) << 5)
         {
            break;
         }
         else if ((status & 0x1f) != a->channelId)
         {
            break;
         }

         if ((t2 - t1) >= 100)
         {
            return FAPI_TSD_ERR_TIMEOUT; //-23006;
         }
      }

      func_21c31434(a, 255);
   }

   if (a->pid == -1)
   {
      return FAPI_TSD_ERR_NO_PID_ASSIGNED; //-23101;
   }

   return 0;
}


/* 21c34fec - complete */
int32_t func_21c34fec(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   struct fapi_tsd_handle* a = handle;

   if (!fapi_tsd_check_handle(a))
   {
      return FAPI_TSD_ERR_INVALID_HANDLE;
   }

   if (a->pid == -1)
   {
      return FAPI_TSD_ERR_NO_PID_ASSIGNED;
   }

   FAPI_SYS_GET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_SUSPEND);

   func_21c34e8c(a);

   if (a->Data_72 != -1)
   {
      Data_21f61a00[a->Data_72] = 0;

      Data_21efc0f0[a->Data_72] = -1;
   }

   FAPI_SYS_SET_SEMAPHORE(fapi_tsd_semaphore, FAPI_SYS_NO_SUSPEND);

   return res;
}


/* 21c31434 - complete */
void func_21c31434(struct fapi_tsd_handle* a, int b)
{
   uint32_t i;
   uint32_t r2;

   if ((a->blockIndex == 0) || (a->blockIndex == 1))
   {
      r2 = 0;
   }
   else
   {
      r2 = 1;
   }

   if (b == 0xFF)
   {
      for (i = 0; i < 0x1000; i++)
      {
         if ((Data_21f399e0[r2][i].Data_0 & 0xE0) &&
               (fapi_tsd_handles[Data_21f399e0[r2][i].Data_4].blockIndex == a->blockIndex) &&
               (fapi_tsd_handles[Data_21f399e0[r2][i].Data_4].channelId == a->channelId))
         {
            Data_21f399e0[r2][i].Data_0 = 0;
         }
      }
   }
   else
   {
      for (i = 0; i < 0x1000; i++)
      {
         if ((Data_21f399e0[r2][i].Data_0 == b) &&
               (fapi_tsd_handles[Data_21f399e0[r2][i].Data_4].blockIndex == a->blockIndex) &&
               (fapi_tsd_handles[Data_21f399e0[r2][i].Data_4].channelId == a->channelId))
         {
            Data_21f399e0[r2][i].Data_0 = 0;
         }
      }
   }
}


/* 21c31570 - complete */
uint32_t fapi_tsd_check_handle(struct fapi_tsd_handle* a)
{
   uint32_t res = 0;

   if ((fapi_tsd_initialized != 0) &&
         (a != 0) &&
         (a->inUse != 0) &&
         (a->magic == 0x747364))
   {
      res = 1;
   }

   return res;
}


/* inline - complete */
static struct fapi_tsd_handle* tsdGetHandle(uint32_t blockIndex)
{
   struct fapi_tsd_handle* h = 0;
   int32_t i = 0;

   if (Data_21f2802c[blockIndex].Data_0 == 32)
   {
      return 0;
   }

   for (i = 127; i >= 0; i--)
   {
      if (!fapi_tsd_handles[i].inUse)
      {
         Data_21f2802c[blockIndex].Data_0++;

         fapi_tsd_handles[i].inUse = 1;
         fapi_tsd_handles[i].blockIndex = blockIndex;

         h = &fapi_tsd_handles[i];
         break;
      }
   }

   return h;
}


/* inline - complete */
void fapi_tsd_clear_handle(struct fapi_tsd_handle* a)
{
   func_21c31434(a, 0xFF);

   Data_21f2802c[a->blockIndex].Data_0--;

   memset(a, 0, sizeof(struct fapi_tsd_handle));

   a->magic = 0x747364;
   a->blockIndex = -1;
   a->pid = -1;
   a->Data_72 = -1;
}


