

#include <fapi/sys_services.h>
#include <fapi/reg_clkpwr.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>




FAPI_SYS_DriverT FAPI_VIENC_Driver0 = //21efe44c 
{
      "VIENC",
      -1,
      FAPI_SYS_BSR_EXEC_UNDEFINED,
      FAPI_VIENC_Init, 
      FAPI_VIENC_Exit,
      0,
      0,
      0,
      0,
};


struct Struct_21f6a660
{
   int Data_0; //0
   int fill_4[8]; //4
   int Data_36; //36
   int Data_40; //40
   int Data_44; //44
   int fill_48[2]; //48
   int Data_56; //56
   int Data_60; //60
   int fill_64[8]; //64
   int (*Data_96)(void*); //96
   int fill_100[6]; //100
   //124
};

static int viencInitialized; //21f6a650
static FAPI_SYS_SemaphoreT viencSemaphore; //21f6a654
static int viencSdEncoderCount; //21f6a658
static int viencHdEncoderCount; //21f6a65c
static FAPI_VIENC_VideoEncoderHandleT viencHandleArray[2]; //21f6a660

FAPI_VIENC_VideoEncoderGpioDataT viencGpioDataArray[1]; //2206bf1c


void fapi_vienc_release_handle(FAPI_VIENC_VideoEncoderHandleT*);
void fapi_vienc_clear_handle(FAPI_VIENC_VideoEncoderHandleT*);
static int vienc_check_handle(FAPI_VIENC_VideoEncoderHandleT*);


/* 21c62c8c - complete */
int32_t FAPI_VIENC_Init(void)
{
   unsigned i = 0;
   
   if (viencInitialized != 0)
   {
      return FAPI_VIENC_ERR_ALREADY_INITIALIZED;
   }
   
   viencSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
   
   if (viencSemaphore == 0)
   {
      return FAPI_VIENC_ERR_SEMAPHORE_CREATE;
   }
   
   for (i = 0; i < 2; i++)
   {
      fapi_vienc_clear_handle(&viencHandleArray[i]);
   }
   
   FREG_VE_SetSdCcfilterhorstart(0x200);
   FREG_VE_SetSdCcfilterhorstop(0xd60);
   FREG_VE_SetSdCcfilterverstart(0x18);
   FREG_VE_SetSdCcfilterverstop(0x130);
   FREG_VE_SetSdCcfilterblankstart(0x200);
   FREG_VE_SetSdCcfilterblankstop(0xd20);
   FREG_VE_SetSdCcfilterlum0(3);
   FREG_VE_SetSdCcfilterlum1(8);
   FREG_VE_SetSdCcfilterlum2(3);
   FREG_VE_SetSdCcfilterlum3(0xf1);
   FREG_VE_SetSdCcfilterlum4(0xdb);
   FREG_VE_SetSdCcfilterlum5(0xe0);
   FREG_VE_SetSdCcfilterlum6(0x1f);
   FREG_VE_SetSdCcfilterlum7(0x8f);
   FREG_VE_SetSdCcfilterlum8(0x140);
   FREG_VE_SetSdCcfilterlum9(0x12e);
   FREG_VE_SetSdCcfilterchrom2(7);
   FREG_VE_SetSdCcfilterchrom3(0x15);
   FREG_VE_SetSdCcfilterchrom4(0x27);
   FREG_VE_SetSdCcfilterchrom5(0x3f);
   FREG_VE_SetSdCcfilterchrom6(0x57);
   FREG_VE_SetSdCcfilterchrom7(0x6c);
   FREG_VE_SetSdCcfilterchrom8(0x7b);
   FREG_VE_SetSdCcfilterchrom9(0x80);
   
   viencInitialized = 1;
   
   return 0;
}

extern int32_t func_21c2ffcc(int); //->fapi_sync.c?


/*  21c62a54 - complete */
int32_t FAPI_VIENC_InitClocks(FAPI_VIENC_InitClocksEnumT a)
{
   uint32_t deviceId;
   int32_t res = 0;
   
   if (a == -1)
   {
      return -29001;
   }
   
   vienc_lock();
   
   deviceId = FAPI_SYS_GetDeviceId();
   
   if (a == 0)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);         
      }
      else
      {
         res = func_21c2ffcc(1);         
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 1)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 2)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 3)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(1);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 4) 
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 5) 
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 6)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(1);         
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 7) 
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 8)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
      }
      else
      {
         res = func_21c2ffcc(1);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
      }
   }
   else if (a == 9)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
      }
   }
   else if (a == 10) 
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 11)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(1);         
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 12) 
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 13)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 14)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(1);         
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 15)      
   {      
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
      }
   }
   else if (a == 16)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
   }
   else if (a == 17)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
   }
   else if (a == 18)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
   }
   else if (a == 19)
   {
      if (deviceId != FAPI_SYS_DEVICE_ID_MB86H60B)
      {
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
      else
      {
         res = func_21c2ffcc(0);
         FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
      }
   }
   else if (a == 20)
   {
      res = func_21c2ffcc(0);
      FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
   }
   else
   {
      res = -29001;
   }
   
   vienc_unlock();

   return res;
}


/* 21c62390 - complete */
void FAPI_VIENC_Exit(void)
{
   unsigned i = 0;
   
   if (viencInitialized != 0)
   {
      vienc_lock();
      
      viencInitialized = 0;
      
      for (i = 0; i < 2; i++)
      {
         if (0 != vienc_check_handle(&viencHandleArray[i]))
         {
            FAPI_VIENC_Close(&viencHandleArray[i]);
         }
      }
      
      vienc_unlock();
      
      FAPI_SYS_DESTROY_SEMAPHORE(viencSemaphore);
      
      viencSemaphore = 0;
   }   
}


static INLINE FAPI_VIENC_VideoEncoderGpioDataT* viencGpioInit(int32_t* errorCodePtr)
{
   int32_t res = 0;

   unsigned i = 0;
   unsigned k = 0;
   unsigned pin = 0;
   FAPI_SYS_HandleT handle = 0;
   FAPI_VIENC_VideoEncoderGpioDataT* gpioDataPtr = 0;

   FAPI_GPIO_OpenParamsT gpioParams;
   gpioParams.version = FAPI_GPIO_VERSION;

   for (i = 0; i < 1; i++)
   {
      if (viencGpioDataArray[i].inUse == 0)
      {
         for (pin = 72; pin < 96; pin++, k++)
         {
            gpioParams.pin = pin;
            gpioParams.function = FAPI_GPIO_OUT_0; //0x80;
            gpioParams.callback = 0;

            handle = FAPI_GPIO_Open(&gpioParams, &res);

            if (res != 0)
            {
               break;
            }

            viencGpioDataArray[i].pin[k].inUse = 1;
            viencGpioDataArray[i].pin[k].number = pin;
            viencGpioDataArray[i].pin[k].handle = handle;
         } //for (pin = 72; pin < 96; pin++, k++)

         if (res == 0)
         {
            pin = 69;
            gpioParams.pin = pin; //69;
            gpioParams.function = FAPI_GPIO_OUT_LCD_CLK; //0xAA;
            gpioParams.callback = 0;

            handle = FAPI_GPIO_Open(&gpioParams, &res);

            if (res != 0)
            {
               break;
            }

            viencGpioDataArray[i].clk.inUse = 1;
            viencGpioDataArray[i].clk.number = pin; //69;
            viencGpioDataArray[i].clk.handle = handle;

            pin = 70;
            gpioParams.pin = pin; //70;
            gpioParams.function = FAPI_GPIO_OUT_HD_DE; //FAPI_GPIO_OUT_HD_HSYNC; ?
            gpioParams.callback = 0;

            handle = FAPI_GPIO_Open(&gpioParams, &res);

            if (res != 0)
            {
               break;
            }

            viencGpioDataArray[i].hSync.inUse = 1;
            viencGpioDataArray[i].hSync.number = pin; //70;
            viencGpioDataArray[i].hSync.handle = handle;

            pin = 71;
            gpioParams.pin = pin; //71;
            gpioParams.function = FAPI_GPIO_OUT_HD_VSYNC; //0xd3;
            gpioParams.callback = 0;

            handle = FAPI_GPIO_Open(&gpioParams, &res);

            if (res != 0)
            {
               break;
            }

            viencGpioDataArray[i].vSync.inUse = 1;
            viencGpioDataArray[i].vSync.number = pin; //71;
            viencGpioDataArray[i].vSync.handle = handle;

            viencGpioDataArray[i].inUse = 1;

            gpioDataPtr = &viencGpioDataArray[i];
            break;
         } //if (res == 0)
      } //if (viencGpioDataArray[i].inUse == 0)
   } //for (i = 0; i < 1; i++)

   *errorCodePtr = res;

   return gpioDataPtr;
}


static FAPI_VIENC_VideoEncoderHandleT* viencAllocateHandle(
      const FAPI_VIENC_OpenParamsT* paramsPtr, 
      int32_t* errorCodePtr)
{
   unsigned i = 0;
   int32_t errorCode = 0;
   FAPI_VIENC_VideoEncoderHandleT* handle = 0;

   switch (paramsPtr->encoderType)
   {
   case FAPI_VIENC_ENCODER_SD:
      if (viencSdEncoderCount != 0)
      {
         errorCode = FAPI_VIENC_ERR_EXCEEDED_MAX_HANDLES;
      }
      else
      {
         viencSdEncoderCount++; // = 1;
      }
      break;

   case FAPI_VIENC_ENCODER_LCD:
   case FAPI_VIENC_ENCODER_HD:
      if (viencHdEncoderCount != 0)
      {
         errorCode = FAPI_VIENC_ERR_EXCEEDED_MAX_HANDLES;
      }
      else
      {
         viencHdEncoderCount++; // = 1;
      }
      break;

   default:
      errorCode = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
      break;
   }

   if (errorCode == 0)
   {
      for (i = 0; i < 2; i++)
      {
         if (viencHandleArray[i].inUse == 0)
         {
            if (paramsPtr->encoderType == FAPI_VIENC_ENCODER_LCD)
            {
               viencHandleArray[i].gpioDataPtr = viencGpioInit(&errorCode);
            }

            if (errorCode == 0)
            {
               viencHandleArray[i].inUse = 1;

               handle = &viencHandleArray[i];
               break;
            }
         }
      } //for (i = 0; i < 2; i++)
   }
   else
   {
      switch (paramsPtr->encoderType)
      {
      case FAPI_VIENC_ENCODER_LCD:
      case FAPI_VIENC_ENCODER_HD:
         viencHdEncoderCount--;
         break;

      case FAPI_VIENC_ENCODER_SD:
         viencSdEncoderCount--;
         break;

      default:
         errorCode = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
         break;
      }
   }

   if (errorCodePtr != 0)
   {
      *errorCodePtr = errorCode;
   }

   return handle;
}


/* 21c62420 - todo */
FAPI_SYS_HandleT FAPI_VIENC_Open(const FAPI_VIENC_OpenParamsT* paramsPtr,
                                 int32_t* errorCodePtr)
{
   FAPI_VIENC_VideoEncoderHandleT* r4;
   int32_t res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r8 = 0;
   
   if (viencInitialized == 0)
   {
      //21c6259c
      res = FAPI_VIENC_ERR_NOT_INITIALIZED;
      if (errorCodePtr) *errorCodePtr = res;
      return 0; //r8; //0;
   }
   
   if (paramsPtr == 0)
   {
      //21c6262c
      res = FAPI_VIENC_ERR_BAD_PARAMETER;
      if (errorCodePtr) *errorCodePtr = res;
      return 0; //r8; //0;
   }
   
   if (paramsPtr->version > FAPI_VIENC_VERSION)
   {
      //21c625b0
      res = FAPI_VIENC_ERR_DRV_VERSION_CHECK_FAILED;
      if (errorCodePtr) *errorCodePtr = res;
      return 0; //r8; //0;
   }
   
   if ((paramsPtr->encoderType == FAPI_VIENC_UNKNOWN_ENCODER) ||
         (paramsPtr->interlaceProgressive == FAPI_VIENC_UNKNOWN_IP_MODE))
   {
      //21c62534
      res = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
      if (errorCodePtr) *errorCodePtr = res;
      return 0; //r8; //0;
   }   

   vienc_lock();
   
   r4 = viencAllocateHandle(paramsPtr, &res);
   
   vienc_unlock();
   //21c62728
   if (r4 == 0)
   {
      //21c62514
      res = FAPI_VIENC_ERR_EXCEEDED_MAX_HANDLES;
      if (errorCodePtr != 0) *errorCodePtr = res;
      return 0; //r8; //0;
   }

   vienc_lock();

   switch (paramsPtr->encoderType)
   {
   case FAPI_VIENC_ENCODER_LCD:
   case FAPI_VIENC_ENCODER_HD:
      //21c62750
      r4->inUse = 1;
      strncpy(r4->coreName, "Vienc", 32);
      memcpy(&r4->opParams, paramsPtr, sizeof(FAPI_VIENC_OpenParamsT));
      r4->coreID = FAPI_VIENC_ID;
      r4->baseAddress = FAPI_VIENC_HD_ENCODER_START_ADDRESS;
      r4->deviceType = FAPI_SYS_GetDeviceId();
      r4->opParams.crossChrominanceFilter = FAPI_VIENC_UNKNOWN_CROSS_CHROMIANACE_FILTER;
      r4->Start = fapi_vienc_hd_start;
      r4->Stop = fapi_vienc_hd_stop;
      r4->EnableDisableWss = 0;
      r4->SetWssData = 0;
      r4->GetWssData = 0;
      r4->SetColourComponent = fapi_vienc_hd_setcolourcomponent;
      r4->GetColourComponent = fapi_vienc_hd_getcolourcomponent;
      r4->ChangeColourComponent = fapi_vienc_hd_changecolourcomponent;
      //->21c627e4
      break;

   case FAPI_VIENC_ENCODER_SD:
      //21c628f0
      r4->inUse = 1;
      strncpy(r4->coreName, "Vienc", 32);
      memcpy(&r4->opParams, paramsPtr, sizeof(FAPI_VIENC_OpenParamsT));
      r4->coreID = FAPI_VIENC_ID;
      r4->baseAddress = FAPI_VIENC_SD_ENCODER_START_ADDRESS;
      r4->deviceType = FAPI_SYS_GetDeviceId();
      r4->Start = fapi_vienc_sd_start;
      r4->Stop = fapi_vienc_sd_stop;
      r4->EnableDisableWss = fapi_vienc_sd_enabledisablewss;
      r4->SetWssData = fapi_vienc_sd_setwssdata;
      r4->GetWssData = fapi_vienc_sd_getwssdata;
      r4->SetColourComponent = fapi_vienc_sd_setcolourcomponent;
      r4->GetColourComponent = fapi_vienc_sd_getcolourcomponent;
      r4->ChangeColourComponent = 0;
      //->21c627e4
      break;

   default:
      //21c62984
      r4->inUse = 0;
      strncpy(r4->coreName, "Unknown Encoder", 32);
      r4->coreID = 0;
      r4->baseAddress = 0;
      r4->deviceType = 0;
      r4->opParams.crossChrominanceFilter = FAPI_VIENC_UNKNOWN_CROSS_CHROMIANACE_FILTER;
      r4->Start = 0;
      r4->Stop = 0;
      r4->EnableDisableWss = 0;
      r4->SetWssData = 0;
      r4->GetWssData = 0;
      r4->SetColourComponent = 0;
      r4->GetColourComponent = 0;
      r4->ChangeColourComponent = 0;

      res = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
      //->21c627e4
      break;
   }
   //21c627e4
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res;
   }

   if (res != 0)
   {
      //218d2abc
      fapi_vienc_release_handle(r4);
      //r8 = 0;
      //->21c62800
   }
   else
   {
      //21c6280c
      unsigned r5 = 0;
      int r6 = 8;

      FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
      FREG_VO_SetDispmixconfenable_Enablergblut(0);
      
      for (r5 = 0; r5 < 1024; r5++)
      {
         int r1 = r5 + r6;
         if (r1 < 64) r1 = 64;
         else if (r1 > 960) r1 = 960;
         
         FREG_VO_SetGLut_Value(r5, r1);
      }

      for (r5 = 0; r5 < 1024; r5++)
      {
         int r1 = r5 + r6;
         if (r1 < 64) r1 = 64;
         else if (r1 > 960) r1 = 960;
         
         FREG_VO_SetRLut_Value(r5, r1);
      }

      for (r5 = 0; r5 < 1024; r5++)
      {
         int r1 = r5;
         if (r1 < 64) r1 = 64;
         else if (r1 > 960) r1 = 960;
         
         FREG_VO_SetBLut_Value(r5, r1);
      }

      FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
      FREG_VO_SetDispmixconfenable_Enablergblut(1);

      r8 = r4;
   }
   //21c62800
   vienc_unlock();
   
   return r8;
}


/* 21c62338 - complete */
int32_t FAPI_VIENC_Close(FAPI_SYS_HandleT handle)
{
//   printf("FAPI_VIENC_Close\n");
   
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();
   
   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->Stop == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->Stop)(h);
      }
      
      fapi_vienc_release_handle(h);
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c620d0 - complete */
int32_t FAPI_VIENC_Start(FAPI_SYS_HandleT handle)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->Start == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->Start)(h);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c6207c - complete */
int32_t FAPI_VIENC_Stop(FAPI_SYS_HandleT handle)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->Stop == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->Stop)(h);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c6203c - complete */
FAPI_VIENC_InterlaceProgressiveEnumT FAPI_VIENC_GetSystemType(FAPI_SYS_HandleT handle)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -1;
   }
   else
   {
      if (h->opParams.encoderType == FAPI_VIENC_ENCODER_HD)
      {
         res = h->opParams.interlaceProgressive;
      }
      else
      {
         res = -1;
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c61fd0 - complete */
int32_t FAPI_VIENC_EnableDisableWss(FAPI_SYS_HandleT handle,
                                    FAPI_VIENC_ParameterModeEnumT mode)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->opParams.encoderType != FAPI_VIENC_ENCODER_SD)
      {
         res = -29105;
      }
      else
      {
         if (h->EnableDisableWss == 0)
         {
            res = -29105;
         }
         else
         {
            res = (h->EnableDisableWss)(h, mode);
         }
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c61f74 - complete */
int32_t FAPI_VIENC_SetWssData(FAPI_SYS_HandleT handle,
                              uint32_t wssData)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->SetWssData == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->SetWssData)(h, wssData);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c61f18 - complete */
int32_t FAPI_VIENC_GetWssData(FAPI_SYS_HandleT handle,
                              uint32_t* wssData)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->GetWssData == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->GetWssData)(h, wssData);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c61ebc - complete */
int32_t FAPI_VIENC_SetColourComponent(FAPI_SYS_HandleT handle,
                      FAPI_VIENC_ComponentEnumT colourComponent)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->SetColourComponent == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->SetColourComponent)(h, colourComponent);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c61e60 - complete */
int32_t  FAPI_VIENC_GetColourComponent(FAPI_SYS_HandleT handle,
                        FAPI_VIENC_ComponentEnumT* colourComponent)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->GetColourComponent == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->GetColourComponent)(h, colourComponent);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c61dfc - complete */
int32_t FAPI_VIENC_ChangeColourComponent(
              FAPI_SYS_HandleT handle,
              FAPI_VIENC_ColourSelectorEnumT col,
              uint32_t offset)
{
   int res;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;
   
   vienc_lock();

   if (0 == vienc_check_handle(h))
   {
      res = -29106;
   }
   else
   {
      if (h->ChangeColourComponent == 0)
      {
         res = -29105;
      }
      else
      {
         res = (h->ChangeColourComponent)(h, col, offset);
      }
   }
   
   vienc_unlock();
   
   return res;
}


/* 21c622ec - complete */
void fapi_vienc_release_handle(FAPI_VIENC_VideoEncoderHandleT* a)
{
//   printf("fapi_vienc_release_handle\n");
   
   switch (a->opParams.encoderType)
   {
   case FAPI_VIENC_ENCODER_LCD:
   case FAPI_VIENC_ENCODER_HD:
      viencHdEncoderCount--;
      break;
      
   case FAPI_VIENC_ENCODER_SD:
      viencSdEncoderCount--;
      break;
      
   default:
      break;
   }   

   fapi_vienc_clear_handle(a);
}


/* 21c61d38 - complete */
void vienc_lock(void)
{   
   FAPI_SYS_GET_SEMAPHORE(viencSemaphore, -1);
}


/* 21c61d68 - complete */
void vienc_unlock(void)
{
   FAPI_SYS_SET_SEMAPHORE(viencSemaphore, 0);
}


/* 21c61d98 - complete */
int vienc_check_handle(FAPI_VIENC_VideoEncoderHandleT* a)
{
//   printf("vienc_check_handle\n");
   
   if ((a != 0) &&
         (a->inUse == 1) &&
         (a->coreID == FAPI_VIENC_ID) &&
         (a->baseAddress != 0) &&
         (a->opParams.encoderType != FAPI_VIENC_UNKNOWN_ENCODER) &&
         (a->opParams.interlaceProgressive != FAPI_VIENC_UNKNOWN_IP_MODE))
   {
      return 1;
   }
   
   return 0;
}


/* 21c62124 - complete */
void fapi_vienc_clear_handle(FAPI_VIENC_VideoEncoderHandleT* a)
{
//   printf("fapi_vienc_clear_handle\n");
   
   unsigned i = 0;
   
   a->inUse = 0;
   strncpy(a->coreName, "Unknown Encoder", 32);   
   a->coreID = 0;
   a->baseAddress = 0;
   a->deviceType = 0;
   a->opParams.version = FAPI_VIENC_VERSION;
   a->opParams.encoderType = FAPI_VIENC_UNKNOWN_ENCODER;
   a->opParams.interlaceProgressive = FAPI_VIENC_UNKNOWN_IP_MODE;
   a->opParams.colourSystem = FAPI_VIENC_UNKNOWN_COLOUR_SYSTEM;
   a->opParams.colourComponent = FAPI_VIENC_UNKNOWN_COLOUR_COMPONENT;
   a->opParams.crossChrominanceFilter = FAPI_VIENC_UNKNOWN_CROSS_CHROMIANACE_FILTER;
   a->enableDisable = 0;
   a->enableDisableWss = 0;
   a->colourComponent = FAPI_VIENC_UNKNOWN_COLOUR_COMPONENT;
   
   if (a->gpioDataPtr != 0)
   {
      for (i = 0; i < 24; i++)
      {
         if ((a->gpioDataPtr->pin[i].handle != 0) &&
               (a->gpioDataPtr->pin[i].inUse == 1))
         {
            FAPI_GPIO_Close(a->gpioDataPtr->pin[i].handle);
         }

         a->gpioDataPtr->pin[i].inUse = 0;
         a->gpioDataPtr->pin[i].number = FAPI_GPIO_PIN_AUTODETECT;
         a->gpioDataPtr->pin[i].handle = 0;
      }

      if ((a->gpioDataPtr->clk.handle != 0) &&
            (a->gpioDataPtr->clk.inUse == 1))
      {
         FAPI_GPIO_Close(a->gpioDataPtr->clk.handle);
      }
      
      a->gpioDataPtr->clk.inUse = 0;
      a->gpioDataPtr->clk.number = FAPI_GPIO_PIN_AUTODETECT;
      a->gpioDataPtr->clk.handle = 0;
      
      if ((a->gpioDataPtr->vSync.handle != 0) &&
            (a->gpioDataPtr->vSync.inUse == 1))
      {
         FAPI_GPIO_Close(a->gpioDataPtr->vSync.handle);
      }
      
      a->gpioDataPtr->vSync.inUse = 0;
      a->gpioDataPtr->vSync.number = FAPI_GPIO_PIN_AUTODETECT;
      a->gpioDataPtr->vSync.handle = 0;
      
      if ((a->gpioDataPtr->hSync.handle != 0) &&
            (a->gpioDataPtr->hSync.inUse == 1))
      {
         FAPI_GPIO_Close(a->gpioDataPtr->hSync.handle);
      }
      
      a->gpioDataPtr->hSync.inUse = 0;
      a->gpioDataPtr->hSync.number = FAPI_GPIO_PIN_AUTODETECT;
      a->gpioDataPtr->hSync.handle = 0;
      
      a->gpioDataPtr->inUse = 0;
   }

   a->gpioDataPtr = 0;
   a->Start = 0;
   a->Stop = 0;
   a->SetWssData = 0;
   a->GetWssData = 0;
   a->SetColourComponent = 0;
   a->GetColourComponent = 0;
   a->ChangeColourComponent = 0;
}

