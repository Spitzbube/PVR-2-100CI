

#define DEBUG 4


#include <fapi/reg_vo.h>
#include <fapi/sys_services.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>


int32_t func_21c604e8(FAPI_VISCALE_VideoScalerHandleT*);



/* 21c60b00 - complete */
int32_t fapi_viscale_sdstart(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_sdstart: sdMode=%d, encoderType=%d, layerEnable=%d\n",
         h->sdMode, 
         h->opParams.encoderType, 
         h->scalerParams.layerEnable);
   
   if (h->sdMode == FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS; 
   }

   if (h->sdMode == FAPI_VISCALE_UNSUPPORTED_SD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
   }

   if (h->opParams.encoderType == FAPI_VISCALE_ENCODER_PAL)
   {
      h->scalerParams.osdLayout = FAPI_VISCALE_UNKNOWN_OSD_LAYOUT;
      h->scalerParams.osdMode = FAPI_VISCALE_UNKNOWN_OSD_MODE;
      h->scalerParams.cpMode = FAPI_VISCALE_UNKNOWN_CURSOR_MODE;
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;
      h->scalerParams.inputWindowX0 = 96;
      h->scalerParams.inputWindowY0 = 22;
      h->scalerParams.inputWindowWidth = 1920;
      h->scalerParams.inputWindowHeight = 540;
      h->scalerParams.outputWindowX0 = 132;
      h->scalerParams.outputWindowY0 = 23;
      h->scalerParams.outputWindowWidth = 720;
      h->scalerParams.outputWindowHeight = 288;
      
      FREG_VO_SetSdfiltermode_Horfilteron(1);
      FREG_VO_SetSdfiltermode_Horfilterup(0);      
      FREG_VO_SetSdhornum_Hornum(0x6000);
      FREG_VO_SetSdhordenum_Hordenum(0x10000);      
      
      FREG_VO_SetSdfiltermode_Verfilteron(1);
      FREG_VO_SetSdfiltermode_Verfilterup(0);
      FREG_VO_SetSdvernum_Vernum(0x8000);
      FREG_VO_SetSdverdenum_Verdenum(0xf000);
      
      FREG_VO_SetSdhorwritestart_Horwritestart(45);
      FREG_VO_SetSdhorwritestop_Horwritestop(765);
      FREG_VO_SetDispcvbshorstartstop(0x600000);
      FREG_VO_SetDispcvbsverstartstop_Cvbsverstart(22);
      FREG_VO_SetDispcvbsverstartstop_Cvbsverstop(569);
      
      FREG_VO_SetSdenable_Sdenable(h->scalerParams.layerEnable);
   }
   else if (h->opParams.encoderType == FAPI_VISCALE_ENCODER_NTSC)
   {
      h->scalerParams.osdLayout = FAPI_VISCALE_UNKNOWN_OSD_LAYOUT;
      h->scalerParams.osdMode = FAPI_VISCALE_UNKNOWN_OSD_MODE;
      h->scalerParams.cpMode = FAPI_VISCALE_UNKNOWN_CURSOR_MODE;
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;

      h->scalerParams.inputWindowX0 = 205;
      h->scalerParams.inputWindowY0 = 20;
      h->scalerParams.inputWindowWidth = 1440;
      h->scalerParams.inputWindowHeight = 240;
      h->scalerParams.outputWindowX0 = 132;
      h->scalerParams.outputWindowY0 = 23;
      h->scalerParams.outputWindowWidth = 720;
      h->scalerParams.outputWindowHeight = 240;

      FREG_VO_SetSdfiltermode_Horfilteron(1);
      FREG_VO_SetSdfiltermode_Horfilterup(0);      
      FREG_VO_SetSdhornum_Hornum(0x8000);
      FREG_VO_SetSdhordenum_Hordenum(0x10000);      
      
      FREG_VO_SetSdfiltermode_Verfilteron(0);
      FREG_VO_SetSdfiltermode_Verfilterup(0);
      FREG_VO_SetSdvernum_Vernum(0x10000);
      FREG_VO_SetSdverdenum_Verdenum(0x10000);
      
      FREG_VO_SetSdhorwritestart_Horwritestart(16);
      FREG_VO_SetSdhorwritestop_Horwritestop(736);
      FREG_VO_SetDispcvbshorstartstop(0xcd0000);
      FREG_VO_SetDispcvbsverstartstop_Cvbsverstart(20);
      FREG_VO_SetDispcvbsverstartstop_Cvbsverstop(263);
      
      FREG_VO_SetSdenable_Sdenable(h->scalerParams.layerEnable);
   }
   else
   {
      res = FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_sdstart: res=%d\n", res);

   return res;
}


/* 21c601ec - todo */
int32_t fapi_viscale_sdenabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode)
{
   int32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_sdenabledisable: mode=%d\n", mode);

   if (h->sdMode == FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }
   
   if (h->sdMode == FAPI_VISCALE_UNSUPPORTED_SD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
   }
   
   if (mode == FAPI_VISCALE_PARAMETER_ON)
   {
      h->scalerParams.layerEnable = 1;
      h->isrDataPtr->iEnableState = FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE;
   }
   else if (mode == FAPI_VISCALE_PARAMETER_OFF)
   {
      h->scalerParams.layerEnable = 0;
      h->isrDataPtr->iEnableState = FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE;
   }
   else
   {
      res = FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_sdenabledisable: res=%d\n", res);

   return res;
}


/* 21c609c0 - complete */
int32_t fapi_viscale_sdresize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   int32_t res;
   uint64_t t1, t2;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_sdresize\n");

   res = func_21c604e8(h);

   if (res != 0)
   {
      return res;
   }

   t1 = FAPI_TIMER_GetTimeStamp(1000);

   while (1)
   {
      t2 = FAPI_TIMER_GetTimeStamp(1000) - t1;

      if (h->isrDataPtr->iFilterState == 0)
      {
         return FAPI_OK;
      }

      if (t2 > 500)
      {
         return FAPI_VISCALE_ERR_OPERATION_TIMEOUT;
      }

      FAPI_SYS_SLEEP(50);
   }
}


