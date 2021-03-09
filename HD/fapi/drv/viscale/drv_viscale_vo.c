
#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_videc.h>
#include <fapi/drv_videc_priv.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>


static int32_t func_21c5a2cc(FAPI_VISCALE_VideoScalerHandleT*,
      FAPI_VISCALE_ScalerParamsT*);
static int32_t waitFiltersUpdated(FAPI_VISCALE_VideoScalerHandleT*);




/* 21c5cdec - complete */
int32_t fapi_viscale_vostart(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   int32_t res = FAPI_OK;   
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_vostart\n");
   
   h->scalerParams = *scaleParamsPtr;
   
   if (h->hdMode != FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      h->scalerParams.osdLayout = FAPI_VISCALE_UNKNOWN_OSD_LAYOUT;
      h->scalerParams.osdMode = FAPI_VISCALE_UNKNOWN_OSD_MODE;      
      h->scalerParams.cpMode = FAPI_VISCALE_UNKNOWN_CURSOR_MODE;      
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;
      h->bitsPerPix = 2;
      
      func_21c5a2cc(h, &h->scalerParams);
      res = waitFiltersUpdated(h);
   }
   else
   {
      res = FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_vostart: res=%d\n", res);

   return res;
}


/* 21c5cc50 - todo */
int32_t fapi_viscale_vostop(FAPI_SYS_HandleT handle)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_vostop\n");
   return 0;
}


/* 21c5cb9c - complete */
uint32_t fapi_viscale_voalpha(FAPI_SYS_HandleT handle,
                              FAPI_VISCALE_ParameterModeEnumT mode,
                              uint32_t level)
{
   int alpha;
   int res = 0;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_voalpha: mode=%d, level=%d\n",
         mode, level);

   switch (mode)
   {
   case FAPI_VISCALE_PARAMETER_SET: //1:
      //21c5cbec
      h->scalerParams.globalAlpha = level;
      FREG_VO_SetDispmixconf_Dispmixvoa(h->scalerParams.globalAlpha);
      break;
      
   case FAPI_VISCALE_PARAMETER_INCREASE: //2:
      //21c5cc00
      alpha = h->scalerParams.globalAlpha + level;
      if (alpha >= 255) alpha = 255;
      h->scalerParams.globalAlpha = alpha;
      FREG_VO_SetDispmixconf_Dispmixvoa(h->scalerParams.globalAlpha);
      break;
      
   case FAPI_VISCALE_PARAMETER_DECREASE: //3:
      //21c5cc20
      alpha = h->scalerParams.globalAlpha - level;
      if (alpha < 0) alpha = 0;
      h->scalerParams.globalAlpha = alpha;
      FREG_VO_SetDispmixconf_Dispmixvoa(h->scalerParams.globalAlpha);
      break;
      
   case FAPI_VISCALE_PARAMETER_ON: //4:
      //21c5cc3c
      h->scalerParams.globalAlpha = 255;
      FREG_VO_SetDispmixconf_Dispmixvoa(h->scalerParams.globalAlpha);
      break;
      
   case FAPI_VISCALE_PARAMETER_OFF: //5:
      //21c5cbd8
      h->scalerParams.globalAlpha = 0;
      FREG_VO_SetDispmixconf_Dispmixvoa(h->scalerParams.globalAlpha);
      break;
      
   case FAPI_VISCALE_PARAMETER_GET: //0:
      //21c5cbc8
      h->scalerParams.globalAlpha = FREG_VO_GetDispmixconf_Dispmixvoa();
      break;      
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_voalpha: res=%d\n", res);

   return res;
}


/* 21c5cb70 - complete */
int32_t fapi_viscale_voresize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{   
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_voresize\n");

   h->isrDataPtr->iUserScalerReqState = FAPI_VISCALE_USER_SCALER_REQUEST;
   
   res = func_21c5a2cc(handle, scaleParamsPtr);
   
   if (res == FAPI_OK)
   {
      res = waitFiltersUpdated(handle);
   }
      
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_voresize: res=%d\n", res);

   return res;
}


/* 21c5ca68 - complete */
int32_t fapi_viscale_voautoplanefading(FAPI_SYS_HandleT handle,
            FAPI_VISCALE_VideoFadingModeEnumT fadingMode)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_voautoplanefading\n");
   
   if (fadingMode == FAPI_VISCALE_VIDEO_FADE_IN)
   {
      h->isrDataPtr->iFadeState = FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN;
      h->isrDataPtr->iFadeCurrValue = 0;
      h->isrDataPtr->iFadeLimitValue = h->scalerParams.globalAlpha;
      
      FREG_VO_SetDispmixconf_Dispmixvoa(h->isrDataPtr->iFadeCurrValue);
   }
   else if (fadingMode == FAPI_VISCALE_VIDEO_FADE_OUT)
   {
      h->isrDataPtr->iFadeState = FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT;
      h->isrDataPtr->iFadeCurrValue = h->scalerParams.globalAlpha;
      h->isrDataPtr->iFadeLimitValue = 0;
      
      FREG_VO_SetDispmixconf_Dispmixvoa(h->isrDataPtr->iFadeCurrValue);
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_voautoplanefading: res=%d\n", res);
   
   return res;
}


/* 21c59d58 - complete */
int32_t fapi_viscale_voautoplanefadingstepsize(FAPI_SYS_HandleT handle, 
            FAPI_VISCALE_ParameterModeEnumT mode,
            uint32_t* stepSizePtr)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_voautoplanefadingstepsize\n");
   
   if (mode == FAPI_VISCALE_PARAMETER_GET)
   {
      *stepSizePtr = h->isrDataPtr->iFadeStepSize;
   }
   else if (mode == FAPI_VISCALE_PARAMETER_SET)
   {
      if (*stepSizePtr != 0)
      {
         h->isrDataPtr->iFadeStepSize = *stepSizePtr;
      }
      else
      {
         res = FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
      }
   }
   else
   {
      res = FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_voautoplanefadingstepsize: res=%d\n", res);

   return res;
}


/* 21c5c39c - todo */
void fapi_viscale_voautoscaler(void* frameCropPtr,
           FAPI_SYS_HandleT handle, uint32_t suspendType)
{
   uint32_t r2;
   FAPI_VIDEC_AspectRatioEnumT ar;
   
   FAPI_VIDEC_FrameCropDataT* r0 = frameCropPtr;
   FAPI_VISCALE_VideoScalerHandleT* r4 = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_voautoscaler\n");
   
   if ((r4 == NULL) ||
         (frameCropPtr == NULL))
   {
      return;
   }
   
   if ((r0->decodedWidth < 64) ||
         (r0->decodedHeight < 48))
   {
      return;
   }
   
   if (r4->hdMode == 1)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 2)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 3)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 4)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 5)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 6)
   {
      //->21c5c918
      r2 = r0->frameField * 2;
   }
   else if (r4->hdMode == 7)
   {
      //->21c5c918
      r2 = r0->frameField * 2;
   }
   else if (r4->hdMode == 8)
   {
      //->21c5c918
      r2 = r0->frameField * 2;
   }
   else if (r4->hdMode == 9)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 10)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 11)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 12)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 13)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 14)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 15)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 16)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 17)
   {
      //->21c5c918
      r2 = r0->frameField * 2;
   }
   else if (r4->hdMode == 18)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 19)
   {
      //->21c5c918
      r2 = r0->frameField * 2;
   }
   else if (r4->hdMode == 20)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 21)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else if (r4->hdMode == 22)
   {
      //->21c5c480
      r2 = r0->frameField * 2 + 1;
   }
   else
   {
      r2 = 0;
   }
   //21c5c48c
   if (r2 != r4->afdScalerReq.diMode)
   {
      //21c5c494
      r4->autoScalerReq.diMode = r2; //2500
      r4->scalerParams.diMode = r2; //1144
      r4->afdScalerReq.diMode = r2; //2344
      r4->userScalerReq.diMode = r2; //2396
      r4->userRawScalerReq.diMode = r2; //2260
      r4->smScalerReq.diMode = r2; //2448
      
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   
   if (r0->frameField != r4->afdScalerReq.frameField)
   {
      //21c5c4cc
      r4->scalerParams.frameField = r0->frameField; //104
      r4->afdScalerReq.frameField = r0->frameField; //2352
      r4->userScalerReq.frameField = r0->frameField; //2404
      r4->userRawScalerReq.frameField = r0->frameField; //1220
      r4->smScalerReq.frameField = r0->frameField; //2456
      r4->autoScalerReq.frameField = r0->frameField; //2508
      
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c500
   if (r0->fieldInversion != r4->afdScalerReq.fieldInversion)
   {
      //21c5c510
      r4->scalerParams.fieldInversion = r0->fieldInversion; //1148
      r4->afdScalerReq.fieldInversion = r0->fieldInversion; //2348
      r4->userScalerReq.fieldInversion = r0->fieldInversion; //2400
      r4->userRawScalerReq.fieldInversion = r0->fieldInversion; //2264
      r4->smScalerReq.fieldInversion = r0->fieldInversion; //2452
      r4->autoScalerReq.fieldInversion = r0->fieldInversion; //2504
      
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c544
   if (r0->decodedWidth != r4->afdScalerReq.inputPicWidth)
   {
      //21c5c554
      r4->scalerParams.inputPicWidth = r0->decodedWidth; //1152
      r4->afdScalerReq.inputPicWidth = r0->decodedWidth; //2356
      r4->userScalerReq.inputPicWidth = r0->decodedWidth; //2408
      r4->userRawScalerReq.inputPicWidth = r0->decodedWidth; //2268
      r4->smScalerReq.inputPicWidth = r0->decodedWidth; //2460
      r4->autoScalerReq.inputPicWidth = r0->decodedWidth; //2512
      
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c588
   if (r0->decodedHeight != r4->afdScalerReq.inputPicHeight)
   {
      //21c5c598
      r4->scalerParams.inputPicHeight = r0->decodedHeight; //1156
      r4->afdScalerReq.inputPicHeight = r0->decodedHeight; //2360
      r4->userScalerReq.inputPicHeight = r0->decodedHeight; //2412
      r4->userRawScalerReq.inputPicHeight = r0->decodedHeight; //2272
      r4->smScalerReq.inputPicHeight = r0->decodedHeight; //2464
      r4->autoScalerReq.inputPicHeight = r0->decodedHeight; //2516
      
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c5cc
   if (r0->aspectRatio == 1)
   {
      ar = 1;
   }
   else if (r0->aspectRatio == 2)
   {
      ar = 2;
   }
   else if (r0->aspectRatio == 3)
   {
      ar = 3;
   }
   else if (r0->aspectRatio == 4)
   {
      ar = 4;
   }
   else if (r0->aspectRatio == 5)
   {
      ar = 5;
   }
   else
   {
      ar = 0;
   }
   //21c5c604
   if (r4->inputAspectRatio != ar)
   {
      r4->inputAspectRatio = ar;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c614
   if (r0->activeAspectRatioL0 == 1)
   {
      ar = 1;
   }
   else if (r0->activeAspectRatioL0 == 2)
   {
      ar = 2;
   }
   else if (r0->activeAspectRatioL0 == 3)
   {
      ar = 3;
   }
   else if (r0->activeAspectRatioL0 == 4)
   {
      ar = 4;
   }
   else if (r0->activeAspectRatioL0 == 5)
   {
      ar = 5;
   }
   else
   {
      ar = 0;
   }
   
   if (r4->inputActiveAspectRatioL0 != ar)
   {
      r4->inputActiveAspectRatioL0 = ar;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c65c
   if (r0->activeAspectRatioL1 == 1)
   {
      ar = 1;
   }
   else if (r0->activeAspectRatioL1 == 2)
   {
      ar = 2;
   }
   else if (r0->activeAspectRatioL1 == 3)
   {
      ar = 3;
   }
   else if (r0->activeAspectRatioL1 == 4)
   {
      ar = 4;
   }
   else if (r0->activeAspectRatioL1 == 5)
   {
      ar = 5;
   }
   else
   {
      ar = 0;
   }
   //21c5c698
   if (r0->currAfd != r4->currAfd)
   {
      r4->currAfd = r0->currAfd;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   
   if (r4->scalingMethod != r4->fill_2340)
   {
      r4->fill_2340 = r4->scalingMethod;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   
   if (r4->wssState != r4->userWssState)
   {
      r4->wssState = r4->userWssState;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   
   if (r4->inputActiveAspectRatioL1 != ar)
   {
      r4->inputActiveAspectRatioL1 = ar;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   
   if (r4->displayAspectRatioL0 != r4->userDisplayAspectRatio)
   {
      //21c5c708
      r4->displayAspectRatioL0 = r4->userDisplayAspectRatio;
      
      if ((r4->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50I) || //17) || 
            (r4->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50P) || //18) || 
            (r4->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I) || //19) || 
            (r4->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P)) //20))
      {
         //->21c5c830
         if (r4->fill_2340 == 1)
         {
            if (r4->userDisplayAspectRatio == 1)
            {
               r4->displayAspectRatioL1 = 1;
            }
            else if (r4->userDisplayAspectRatio == 3)
            {
               r4->displayAspectRatioL1 = 1;
            }
         }
      }
      //21c5c718
      r4->displayAspectRatioL1 = r4->userDisplayAspectRatio;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c724
   r2 = r4->inputActiveAspectRatioL0; //ip;
   
   if (r4->currAfd == 2)
   {
      //->21c5c8c8
      if (r4->displayAspectRatioL1 == 0)
      {
         //->21c5c8a4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //if (r4->displayAspectRatioL1 == 0)
      else if (r4->displayAspectRatioL1 == 1)
      {
         //->21c5c974
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //21c5c998
            r2 = 1;
            //->21c5c7b8
         }         
         //->21c5c908
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 1)
      else if (r4->displayAspectRatioL1 == 3)
      {
         //21c5c8e4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21c5c7b8
   } //if (r4->currAfd == 2)
   else if (r4->currAfd == 3)
   {
      //->21c5c854
      //TODO
      
   } //else if (r4->currAfd == 3)
   else if (r4->currAfd == 4)
   {
      //->21c5c8c8
      if (r4->displayAspectRatioL1 == 0)
      {
         //->21c5c8a4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //if (r4->displayAspectRatioL1 == 0)
      else if (r4->displayAspectRatioL1 == 1)
      {
         //->21c5c974
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //21c5c998
            r2 = 1;
            //->21c5c7b8
         }         
         //->21c5c908
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 1)
      else if (r4->displayAspectRatioL1 == 3)
      {
         //21c5c8e4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21c5c7b8
   } //else if (r4->currAfd == 4)
   else if (r4->currAfd == 8)
   {
      //->21c5c778
      //TODO
      
   } //else if (r4->currAfd == 8)
   else if (r4->currAfd == 9)
   {
      //->21c5c924
      //TODO
      
   } //else if (r4->currAfd == 9)
   else if (r4->currAfd == 10)
   {
      //->21c5c8c8
      if (r4->displayAspectRatioL1 == 0)
      {
         //->21c5c8a4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //if (r4->displayAspectRatioL1 == 0)
      else if (r4->displayAspectRatioL1 == 1)
      {
         //->21c5c974
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //21c5c998
            r2 = 1;
            //->21c5c7b8
         }         
         //->21c5c908
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 1)
      else if (r4->displayAspectRatioL1 == 3)
      {
         //21c5c8e4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21c5c7b8
   } //else if (r4->currAfd == 10)
   else if (r4->currAfd == 11)
   {
      //->21c5c9a0
      //TODO
      
   } //else if (r4->currAfd == 11)
   else if (r4->currAfd == 13)
   {
      //->21c5c924
      //TODO
      
   } //else if (r4->currAfd == 13)
   else if (r4->currAfd == 14)
   {
      //->21c5c8c8
      if (r4->displayAspectRatioL1 == 0)
      {
         //->21c5c8a4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //if (r4->displayAspectRatioL1 == 0)
      else if (r4->displayAspectRatioL1 == 1)
      {
         //->21c5c974
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //21c5c998
            r2 = 1;
            //->21c5c7b8
         }         
         //->21c5c908
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 1)
      else if (r4->displayAspectRatioL1 == 3)
      {
         //21c5c8e4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21c5c7b8
   } //else if (r4->currAfd == 14)
   else if (r4->currAfd == 15)
   {
      //->21c5c8c8
      if (r4->displayAspectRatioL1 == 0)
      {
         //->21c5c8a4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //if (r4->displayAspectRatioL1 == 0)
      else if (r4->displayAspectRatioL1 == 1)
      {
         //->21c5c974
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //21c5c998
            r2 = 1;
            //->21c5c7b8
         }         
         //->21c5c908
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 1)
      else if (r4->displayAspectRatioL1 == 3)
      {
         //21c5c8e4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 4)
         {
            //21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21c5c7b8
   } //else if (r4->currAfd == 15)
   else
   {
      //21c5c778
      if (r4->displayAspectRatioL1 == 0)
      {
         //->21c5c8a4
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //if (r4->displayAspectRatioL1 == 0)
      else if (r4->displayAspectRatioL1 == 1)
      {
         //->21c5ca14
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c96c
            r2 = 1;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 1)
      else if (r4->displayAspectRatioL1 == 3)
      {
         //21c5c794
         if (r4->fill_2340 == 0)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5c8c0
            r2 = 0;
            //->21c5c7b8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c910
            r2 = 3;
            //->21c5c7b8
         }
         //->21c5c7b8
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21c5c7b8
   } //else
   //21c5c7b8
   if (r4->userScalingMethod != r2)
   {
      r4->userScalingMethod = r2;
      r4->isrDataPtr->iAutoScalerReqState = FAPI_VISCALE_AUTO_SCALER_REQUEST;
   }
   //21c5c7c8
   if (r4->isrDataPtr->iAutoScalerReqState == FAPI_VISCALE_AUTO_SCALER_REQUEST)
   {
      func_21c5a2cc(r4, &r4->userRawScalerReq);
      
      r4->isrDataPtr->paramChangeInfo.codedAspectRatio = //680
         r4->inputAspectRatio; //2308
      r4->isrDataPtr->paramChangeInfo.displayAspectRatio = //684
         r4->displayAspectRatioL1; //2328
      r4->isrDataPtr->paramChangeInfo.scalingMethod = //688
         r4->fill_2340; //2340
      r4->isrDataPtr->paramChangeInfo.currAfd = //692
         r4->currAfd; //2552
      r4->isrDataPtr->paramChangeInfo.currWss = //696
         r4->currWss; //2564
      
      if (r4->isrDataPtr->paramChangeCbk != NULL)
      {
         (r4->isrDataPtr->paramChangeCbk)(&r4->isrDataPtr->paramChangeInfo,
               r4->isrDataPtr->paramChangeOptData);
      }
   }
}


/* 21c59da8 - complete */
int32_t fapi_viscale_setvoscalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   FAPI_VIENC_VideoEncoderHandleT* h1 = viencHdHandle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_setvoscalertohdencoder\n");

   if (h1 == 0)
   {
      h->hdMode = FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE;
      h->sdMode = FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE;
      
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }
   
   switch (h1->opParams.interlaceProgressive)
   {
   case FAPI_VIENC_IP_MODE_1920x1080x2397P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x2397P_TO_5994I;
      break;
      
   default:
      h->hdMode = FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE;
      h->sdMode = FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE;
      res = FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x24P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x24P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x25P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x25P_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x2997P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x2997P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x30P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x30P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x50I:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x50I_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x5994I:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x5994I_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1920x1080x60I:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1920x1080x60I_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x2397P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x2397P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x24P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x24P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x25P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x25P_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x2997P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x2997P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x30P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x30P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x50P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x50P_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x5994P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x5994P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_1280x720x60P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_1280x720x60P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_720x576x50I:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_720x576x50I;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_720x576x50I_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_720x576x50P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_720x576x50P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_720x576x50P_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_720x480x5994I:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_720x480x5994I_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_720x480x5994P:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_720x480x5994P_TO_5994I;
      break;
      
   case FAPI_VIENC_IP_MODE_LCD_640x480x50P_LQ080V3DG01:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01_TO_50I;
      break;
      
   case FAPI_VIENC_IP_MODE_LCD_1024x768x50P_SVA150XG10TB:
      h->hdMode = FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB;
      h->sdMode = FAPI_VISCALE_SD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB_TO_50I;
      break;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setvoscalertohdencoder: res=%d\n", res);

   return res;
}


/* 21c59ffc - complete */
int32_t fapi_viscale_setvoscalingmethod(FAPI_SYS_HandleT handle,
                          FAPI_VISCALE_ScalingMethodEnumT scalingMethod)
{
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setvoscalingmethod: scalingMethod=%d\n",
         scalingMethod);

   h->scalingMethod = scalingMethod;
   
   return FAPI_OK;
}


/* 21c5a008 - complete */
int32_t fapi_viscale_setvodisplayaspectratio(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_AspectRatioEnumT displayAr)
{   
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setvodisplayaspectratio: displayAr=%d\n",
         displayAr);

   h->userDisplayAspectRatio = displayAr;
   
   return FAPI_OK;
}


/* 21c5a014 - complete */
int32_t fapi_viscale_setvowssstate(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_WssStateEnumT wssState)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_setvowssstate: wssState=%d\n",
         wssState);

   if ((wssState == FAPI_VISCALE_WSS_ENABLE_4_3_FULLFORMAT) ||
         (wssState == FAPI_VISCALE_WSS_ENABLE_14_9_CENTRE) ||
         (wssState == FAPI_VISCALE_WSS_ENABLE_16_9_BOX_CENTRE) ||
         (wssState == FAPI_VISCALE_WSS_ENABLE_16_9_BOX_GT_CENTRE) ||
         (wssState == FAPI_VISCALE_WSS_ENABLE_4_3_FULL_FORMAT) ||
         (wssState == FAPI_VISCALE_WSS_ENABLE_16_9_ANAMORPHIC) ||
         (wssState == FAPI_VISCALE_WSS_ENABLE_AUTO) ||
         (wssState == FAPI_VISCALE_WSS_DISABLE))
   {
      h->userWssState = wssState;
   }
   else
   {
      res = FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setvowssstate: res=%d\n", res);

   return res;
}


/* 21c5a05c - complete */
int32_t  fapi_viscale_getvowsssignal(FAPI_SYS_HandleT handle,
                                     uint32_t* wssSignalPtr)
{
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   *wssSignalPtr = h->currWss;

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_getvowsssignal: wssSignal=%d\n", 
         *wssSignalPtr);

   return FAPI_OK;
}


/* 21c5a06c - complete */
int32_t fapi_viscale_vosetparamchangecallback(FAPI_SYS_HandleT handle,
            FAPI_VISCALE_ParamChangeCallbackT paramChangeCallbackFunction,
            void* paramChangeOptData)
{   
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_vosetparamchangecallback\n");

   if (paramChangeCallbackFunction == 0)
   {
      h->isrDataPtr->paramChangeCbk = 0;
      h->isrDataPtr->paramChangeOptData = 0;
   }
   else if (h->isrDataPtr->paramChangeCbk == 0)
   {
      h->isrDataPtr->paramChangeCbk = paramChangeCallbackFunction;
      h->isrDataPtr->paramChangeOptData = paramChangeOptData;
   }
   else
   {
      res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_vosetparamchangecallback: res=%d\n", res);

   return res;
}


FAPI_VISCALE_ActiveRegionDataT Data_21efc8a0[23] = //21efc8a0
{
      {0x00000000, 0x00000000, 
         0x00000000, 0x00000000, 0x00000001, 0x00000001, 
         0x00000000, },
      {0x000000c0, 0x00000029, 0x00000780, 
            0x00000438, 0x00000001, 0x00000001, 0x00000000,},
      {0x000000c0, 0x00000029, 0x00000780, 0x00000438, 
            0x00000001, 0x00000001, 0x00000000, },
      {0x000000c0, 
            0x00000029, 0x00000780, 0x00000438, 0x00000001, 
            0x00000001, 0x00000000, },
      {0x000000c0, 0x00000029, 
            0x00000780, 0x00000438, 0x00000001, 0x00000001, 
            0x00000000, },
      {0x000000c0, 0x00000029, 0x00000780, 
            0x00000438, 0x00000001, 0x00000001, 0x00000000,},
      {0x000000c0, 0x00000014, 0x00000780, 0x00000438, 
            0x00000002, 0x00000001, 0x00000000, },
      {0x000000c0, 
            0x00000014, 0x00000780, 0x00000438, 0x00000002, 
            0x00000001, 0x00000000, },
      {0x000000c0, 0x00000014, 
            0x00000780, 0x00000438, 0x00000002, 0x00000001, 
            0x00000000, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000001, 0x00000001, 0x00000000,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000001, 0x00000001, 0x00000000, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000001, 
            0x00000001, 0x00000000, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000001, 0x00000001, 
            0x00000000, },
      {0x00000104, 0x00000019, 0x00000500, 
            0x000002d0, 0x00000001, 0x00000001, 0x00000000,},
      {0x00000104, 0x00000019, 0x00000500, 0x000002d0, 
            0x00000001, 0x00000001, 0x00000000, },
      {0x00000104, 
            0x00000019, 0x00000500, 0x000002d0, 0x00000001, 
            0x00000001, 0x00000000, },
      {0x00000104, 0x00000019, 
            0x00000500, 0x000002d0, 0x00000001, 0x00000001, 
            0x00000000, },
      {0x00000108, 0x00000016, 0x000002d0, 
            0x00000240, 0x00000002, 0x00000002, 0x00000000,},
      {0x00000084, 0x0000002c, 0x000002d0, 0x00000240, 
            0x00000001, 0x00000001, 0x00000000, },
      {0x000000ee, 
            0x00000012, 0x000002d0, 0x000001e0, 0x00000002, 
            0x00000002, 0x00000000, },
      {0x0000007a, 0x00000024, 
            0x000002d0, 0x000001e0, 0x00000001, 0x00000001, 
            0x00000000, },
      {0x00000064, 0x00000014, 0x00000280, 
            0x000001e0, 0x00000001, 0x00000001, 0x00000000,},
      {0x00000064, 0x00000014, 0x00000400, 0x00000306, 
            0x00000001, 0x00000001, 0x00000000, },
};


/* 21931e94 - todo */
static int32_t func_21931e94(FAPI_VISCALE_VideoScalerHandleT* a,
                  FAPI_VISCALE_ScalerParamsT* b)
{   
   int32_t res = FAPI_OK; //r10
   uint32_t sp12 = 1;
   uint32_t r9 = 1;
   uint32_t sp4 = 0;
   uint32_t r11 = 0;
   
   FAPI_VISCALE_ActiveRegionDataT sp0x58 = {0};       
   FAPI_VISCALE_ActiveRegionDataT sp0x3c = {0}; 
   FAPI_VISCALE_ActiveRegionDataT sp0x20 = {0};    
   FAPI_VISCALE_ActiveRegionDataT sp0x04 = {0}; 
      
   if (a->hdMode/*r6*/ == FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      res = FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
      //->21c5a748
   }
   else
   {
      //21c5a560
      FAPI_VISCALE_ActiveRegionDataT* r0 = &Data_21efc8a0[a->hdMode];
      
      sp0x58.startX0/*sp24*/ = r0->startX0;
      sp0x58.startY0/*sp20*/ = r0->startY0;
      sp0x58.horSize/*r7*/ = r0->horSize;
      sp0x58.verSize/*ip*/ = r0->verSize;

      r11/*sp8*/ = r0->sdHorWriteStart;
      sp4 = r0->sdHorWriteStop;
      
      if (a->isrDataPtr/*lr*/->iUserScalerReqState ==
            FAPI_VISCALE_USER_SCALER_REQUEST)
      {
         //21c5aed8
         if (b != 0)
         {
            a->userRawScalerReq.outputWindowX0 = //2292
                  b->outputWindowX0;
            a->userRawScalerReq.outputWindowY0 = //2296
                  b->outputWindowY0;
            a->userRawScalerReq.outputWindowWidth = //2300
                  b->outputWindowWidth;
            a->userRawScalerReq.outputWindowHeight = //2304
                  b->outputWindowHeight;
         }
      }
      //21c5a5a4      
      if (a->userRawScalerReq.outputWindowX0 <= sp0x58.horSize/*r7*/)
      {
         sp0x3c.startX0/*fp*/ = a->userRawScalerReq.outputWindowX0;
      }
      else
      {
         sp0x3c.startX0/*fp*/ = 0;
      }
      //21c5a5b8
      if (a->userRawScalerReq.outputWindowY0 <= sp0x58.verSize/*ip*/)
      {
         sp0x3c.startY0/*sp28*/ = a->userRawScalerReq.outputWindowY0;
      }
      else
      {
         sp0x3c.startY0/*sp28*/ = 0;
      }
      //21c5a5c0      
      if (a->userRawScalerReq.outputWindowWidth == 0)
      {
         sp0x3c.horSize/*r7*/ = sp0x58.horSize/*r7*/;
      }
      else
      {
         if ((sp0x3c.startX0/*fp*/ + a->userRawScalerReq.outputWindowWidth) > sp0x58.horSize/*r7*/)
         {
            sp0x3c.horSize/*r7*/ = sp0x58.horSize/*r7*/ - sp0x3c.startX0/*fp*/;
         }
         else
         {
            sp0x3c.horSize/*r7*/ = a->userRawScalerReq.outputWindowWidth;
         }
      }
      //21c5a5dc      
      if (a->userRawScalerReq.outputWindowHeight == 0)
      {
         sp0x3c.verSize/*r5*/ = sp0x58.verSize/*ip*/;
      }
      else
      {
         if ((sp0x3c.startY0/*sp28*/ + a->userRawScalerReq.outputWindowHeight) > sp0x58.verSize/*ip*/)
         {
            sp0x3c.verSize/*r5*/ = sp0x58.verSize/*ip*/ - sp0x3c.startY0/*sp28*/;
         }
         else
         {
            sp0x3c.verSize/*r5*/ = a->userRawScalerReq.outputWindowHeight;
         }
      }         
      //21c5a5fc
      if ((a->hdMode == 17) || /*sp16 = a->hdMode - 17*/
            (a->hdMode == 18) ||
            (a->hdMode == 19) ||
            (a->hdMode == 20))
      {
         //21c5a60c
         if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0) //2328
         {
            //->21c5ad1c / ->21932170
         }
         else if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
         {
            //->21c5b578
            r9 = 4;
            sp12 = 3;
            if (a->displayAspectRatioL0 == FAPI_VISCALE_AR_4_3) //1) //2324
            {
               //->21c5ad1c
               r9 = 1;
               sp12 = 1;
            }            
            else if (a->displayAspectRatioL0 == FAPI_VISCALE_AR_16_9) //3)
            {
               //21c5bc84
               if (a->fill_2340 == 1) //0x95c
               {
                  //21c5b818
                  r9 = 16;
                  sp12 = 9;
               }
               //21c5bc90
               else if (a->fill_2340 == 2)
               {
                  //->21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 3)
               {
                  //->21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 4)
               {
                  //->21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 0)
               {
                  //->21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b58c
               }
            } //else if (a->displayAspectRatioL0 == 3)
            else
            {
               //21c5b58c
               //r9 = 4;
               //sp12 = 3;
               //->21c5a664
            }
         } //else if (a->displayAspectRatioL1 == 1)
         //21c5a620
         else if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_14_9) //2)
         {
            //21c5a624
            r9 = 14;
            sp12 = 9;
         } //else if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_14_9) //2)
         //21c5a634
         else if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
         {
            //21c5b80c
            r9 = 16;
            sp12 = 9;            
            if (a->displayAspectRatioL0 == FAPI_VISCALE_AR_16_9) //3) //2324
            {
               //21c5acf0
               if (a->fill_2340 == 1)
               {
                  //21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 2)
               {
                  //21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 3)
               {
                  //21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 4) 
               {
                  //21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340 == 0)
               {
                  //21c5ad1c
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b818
                  //r9 = 16;
                  //sp12 = 9;            
                  //21c5a664
               }
            }            
            else
            {
               //21c5b818
               //r9 = 16;
               //sp12 = 9;            
               //21c5a664
            }
         }
         //21c5a63c
         else if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_221_100) //4)
         {
            //21c5a640
            r9 = 221;
            sp12 = 100;
         }
         //21c5a650
         else if (a->displayAspectRatioL1 == FAPI_VISCALE_AR_235_100) //5)
         {
            //21c5a658
            r9 = 235;   
            sp12 = 100;
         }
         else
         {
            //->21c5ad1c / 21932170
         }
         
         if ((r9 == 1) && (sp12 == 1))
         {
            //21c5ad1c / 21932170
            sp0x20.startX0/*sp36*/ = 0;
            sp0x20.startY0/*sp32*/ = 0;
            sp0x20.horSize/*r8*/ = sp0x3c.horSize/*r7*/;
            sp0x20.verSize/*sl*/ = sp0x3c.verSize/*r5*/;
            //->21c5ad38
         }
         else
         {
            //21c5a664
            if (sp0x3c.horSize/*r7*/ > sp0x3c.verSize/*r5*/)
            {
               //21c5a66c
               if (sp0x3c.verSize/*r5*/ * r9/sp12 <= sp0x3c.horSize/*r7*/)
               {
                  //21c5a684
                  sp0x20.startX0/*sp36*/ = (sp0x3c.horSize/*r7*/ - sp0x3c.verSize/*r5*/ * r9/sp12) / 2;
                  sp0x20.startY0/*sp32*/ = 0;
                  sp0x20.horSize/*r8*/ = sp0x3c.verSize/*r5*/ * r9/sp12;
                  sp0x20.verSize/*sl*/ = sp0x3c.verSize/*r5*/;
                  //->21c5ad38
               }
               else
               {
                  //21c5b690
                  sp0x20.startX0/*sp36*/ = 0;
                  sp0x20.startY0/*sp32*/ = (sp0x3c.verSize/*r5*/ - sp0x3c.horSize/*r7*/ * sp12/r9) / 2;
                  sp0x20.horSize/*r8*/ = sp0x3c.horSize/*r7*/;
                  sp0x20.verSize/*sl*/ = sp0x3c.horSize/*r7*/ * sp12/r9;
                  //21c5ad38
               }
            }
            else
            {
               //21c5af44
               if (sp0x3c.horSize/*r7*/ * sp12/r9 <= sp0x3c.verSize/*r5*/)
               {
                  //21c5af60
                  sp0x20.startX0/*sp36*/ = 0; //r8;
                  sp0x20.startY0/*sp32*/ = (sp0x3c.verSize/*r5*/ - sp0x3c.horSize/*r7*/ * sp12/r9) / 2;
                  sp0x20.horSize/*r8*/ = sp0x3c.horSize/*r7*/;
                  sp0x20.verSize/*sl*/ = sp0x3c.horSize/*r7*/ * sp12/r9;
                  //->21c5ad38
               }
               else
               {
                  //21c5b6c0
                  sp0x20.startX0/*sp36*/ = (sp0x3c.horSize/*r7*/ - sp0x3c.verSize/*r5*/ * r9/sp12) / 2;
                  sp0x20.startY0/*sp32*/ = 0;
                  sp0x20.horSize/*r8*/ = sp0x3c.verSize/*r5*/ * r9/sp12;
                  sp0x20.verSize/*sl*/ = sp0x3c.verSize/*r5*/;
                  //->21c5ad38
               }
            }
         }
         //21c5ad38
         sp0x04.horSize/*r5*/ = sp0x20.horSize/*r8*/;
         sp0x04.verSize/*r6*/ = sp0x20.verSize/*sl*/;
         //21c5ad38
         if (a->userScalingMethod/*r0*/ == FAPI_VISCALE_SM_PLBOX) //1) //2332
         {
            //21c5b204
            if (a->displayAspectRatioL0 == FAPI_VISCALE_AR_4_3) //1) //2324
            {
               //->21c5ad70 / 21932cc4
               r9 = 1;
               sp12 = 1;
            }
            //21c5b210
            else if (a->displayAspectRatioL0 == FAPI_VISCALE_AR_16_9) //3)
            {
               //21c5b224
               if ((a->hdMode == 17) || 
                     (a->hdMode == 18))
               {
                  //21c5b22c
                  r9 = 15; //937; 
                  sp12 = 16; //1000;
               }
               else if ((a->hdMode == 19) ||
                     (a->hdMode == 20))
               {
                  //21c5b248                  
                  r9 = 9; //1125; 
                  sp12 = 8; //1000;
               }
               //21c5b254
               if (a->fill_2340 == 1) //2340
               {
                  //->21c5b280 / 21932528
               }
               //21c5b260
               else if (a->fill_2340 == 2)
               {
                  //->21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5b268
               else if (a->fill_2340 == 3)
               {
                  //->21c5b280 / 21932528
               }
               //21c5b270
               else if (a->fill_2340 == 4)
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5b278
               else if (a->fill_2340 == 0)
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b280 / 21932528
               }
            } //else if (a->displayAspectRatioL0 == 3)
            else
            {
               //21c5b214
               r9 = 4;
               sp12 = 3;
               //->21c5adcc / 21932630
            }
         } //if (a->userScalingMethod == 1)
         //21c5ad44
         else if (a->userScalingMethod == FAPI_VISCALE_SM_FSZOOM) //2) //2332
         {
            //21c5ad84
            if (a->displayAspectRatioL0 == FAPI_VISCALE_AR_16_9) //3) //2324
            {
               //21c5ad9c
               if (a->fill_2340/*r0*/ == 1) //0x95c
               {                  
                  //21c5adc0
                  r9 = 8;
                  sp12 = 7;
               }
               else if (a->fill_2340/*r0*/ == 2) //0x95c
               {
                  //21c5adc0
                  r9 = 8;
                  sp12 = 7;
               }
               else if (a->fill_2340/*r0*/ == 3) //0x95c
               {
                  //21c5adc0
                  r9 = 8;
                  sp12 = 7;
               }
               else if (a->fill_2340/*r0*/ == 4) //0x95c
               {
                  //21c5adc0
                  r9 = 8;
                  sp12 = 7;
               }
               //21c5b278
               else if (a->fill_2340/*r0*/ == 0) //0x95c
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b280 / 21932528
               }
            } //else if (a->displayAspectRatioL0 == 3) //0x94c
            else
            {
               //21c5adcc / 21932630
               r9 = 14;
               sp12 = 9;
            }
         } //else if (a->userScalingMethod == 2) //0x954
         //21c5ad4c
         else if (a->userScalingMethod == FAPI_VISCALE_SM_FSCCO) //3) //0x954
         {
            //21c5b530
            if (a->displayAspectRatioL0/*r0*/ == FAPI_VISCALE_AR_4_3) //1) //2324
            {
               //21c5baec
               if (a->fill_2340/*r0*/ == 1) //0x95c
               {
                  //21c5baf4
                  r9 = 16;
                  sp12 = 9;
               }
               //21c5b550
               else if (a->fill_2340/*r0*/ == 2) //0x95c
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5b558
               else if (a->fill_2340/*r0*/ == 3) //0x95c
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5b270
               else if (a->fill_2340/*r0*/ == 4) //0x95c
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5b278
               else if (a->fill_2340/*r0*/ == 0) //0x95c
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b280 / 21932528
               }
            } //if (a->displayAspectRatioL0/*r0*/ == 1) //0x94c
            //21c5b53c
            else if (a->displayAspectRatioL0/*r0*/ == FAPI_VISCALE_AR_16_9) //3) //0x94c
            {
               //21c5b544
               if (a->fill_2340/*r0*/ == 1)
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 2)
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 3)
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5b270
               else if (a->fill_2340/*r0*/ == 4) 
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 0)
               {
                  //21c5ad70 / 21932cc4
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b280 / 21932528
               }
            } //else if (a->displayAspectRatioL0/*r0*/ == FAPI_VISCALE_AR_16_9)
            else
            {
               //21c5b280 / 21932528
            }
         } //else if (a->userScalingMethod == 3) //0x954
         //21c5ad54
         else if (a->userScalingMethod == FAPI_VISCALE_SM_LTVS) //4)
         {
            //21c5ad58
            r9 = 221; 
            sp12 = 100;
         } //else if (a->userScalingMethod == 4)
         //21c5ad68
         else if (a->userScalingMethod == 5)
         {
            //21c5b7f0
            r9 = 235;
            sp12 = 100;
         }
         else
         {
            //21c5ad70 / 21932cc4
            r9 = 1;
            sp12 = 1;
         }
         //21c5b280 / 21932528
         if ((r9 == 1) && (sp12 == 1))
         {
            //21c5ad70 / 21932cc4
            sp0x04.startX0/*r0*/ = 0;
            sp0x04.startY0/*r1*/ = 0;
            //->21932d68
         }
         else
         {
            //21c5adcc / 21932630            
            if (sp0x20.horSize/*r8*/ > sp0x20.verSize/*sl*/)
            {
               //21c5af04
               if (sp0x20.verSize/*sl*/ * r9/sp12 <= sp0x20.horSize/*r8*/)
               {
                  //21c5ae10
                  sp0x04.startX0/*r0*/ = (sp0x20.horSize/*r8*/ - sp0x20.verSize/*sl*/ * r9/sp12) / 2;
                  sp0x04.startY0/*r1*/ = 0;
                  sp0x04.horSize/*r5*/ = sp0x20.verSize/*sl*/ * r9/sp12;
                  //->21c5a6e8
               }
               else
               {
                  //21c5af1c
                  sp0x04.startX0/*r0*/ = 0;
                  sp0x04.startY0/*r1*/ = (sp0x20.verSize/*sl*/ - sp0x20.horSize/*r8*/ * sp12/r9) / 2;
                  sp0x04.verSize/*r6*/ = sp0x20.horSize/*r8*/ * sp12/r9;
                  //->21c5a6e8
               }
            }
            else
            {
               //21c5add4
               if (sp0x20.horSize/*r8*/ * sp12/r9 <= sp0x20.verSize/*sl*/)
               {
                  //21c5ade8
                  sp0x04.startX0/*r0*/ = 0;
                  sp0x04.startY0/*r1*/ = (sp0x20.verSize/*sl*/ - sp0x20.horSize/*r8*/ * sp12/r9) / 2;
                  sp0x04.verSize/*r6*/ = sp0x20.horSize/*r8*/ * sp12/r9;
                  //->21c5a6e8
               }
               else
               {
                  //21c5ae00
                  sp0x04.startX0/*r0*/ = (sp0x20.horSize/*r8*/ - sp0x20.verSize/*sl*/ * r9/sp12) / 2;
                  sp0x04.startY0/*r1*/ = 0;
                  sp0x04.horSize/*r5*/ = sp0x20.verSize/*sl*/ * r9/sp12;
                  //->21c5a6e8
               }
            }
         }
         //->21932d68
      } //if ((r6 == 17) ||
         //(r6 == 18) ||
         //(r6 == 19) ||
         //(r6 == 20))
      else
      {
         //21c5aa58            
         if (a->displayAspectRatioL1/*r7*/ == 0) //2328
         {
            //->21c5ab5c / 21932820
            r9 = 1;
            sp12 = 1;
         }
         //21c5aa64
         else if (a->displayAspectRatioL1/*r7*/ == 1)
         {
            //21c5ab28
            r9 = 4;
            sp12 = 3;
            if (a->fill_2340/*r0*/ == 1) //2340
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            //21c5ab34
            else if (a->fill_2340/*r0*/ == 2)
            {
               //->21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            //21c5ab3c
            else if (a->fill_2340/*r0*/ == 3)
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            //21c5ab44
            else if (a->fill_2340/*r0*/ == 4)
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 0)
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else
            {
               //21c5ab50
               //r9 = 4;
               //sp12 = 3;
            }
         } //else if (a->displayAspectRatioL1 == 1)
         //21c5aa6c
         else if (a->displayAspectRatioL1/*r7*/ == 2)
         {
            //21c5b0dc
            r9 = 14;
            sp12 = 9;
            if (a->fill_2340/*r0*/ == 1) //2340
            {
               //21c5b108
            }
            else if (a->fill_2340/*r0*/ == 2) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 3) //0x95c
            {
               //21c5b108
            }
            else if (a->fill_2340/*r0*/ == 4) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 0) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else
            {
               //21c5b108
               //r9 = 14;
               //sp12 = 9;
            }
         }
         //21c5aa74
         else if (a->displayAspectRatioL1/*r7*/ == 3)
         {
            //->21c5b828
            r9 = 16;
            sp12 = 9;
            if (a->fill_2340/*r0*/ == 1) //0x95c
            {
               //21c5b854
            }
            else if (a->fill_2340/*r0*/ == 2) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 3) //0x95c
            {
               //21c5b854
            }
            else if (a->fill_2340/*r0*/ == 4) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 0) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else
            {
               //21c5b854
               //r9 = 16;
               //sp12 = 9;
            }
         }
         //21c5aa7c
         else if (a->displayAspectRatioL1/*r7*/ == 4)
         {
            //21c5b9e4
            r9 = 221; 
            sp12 = 100;  
            if (a->fill_2340/*r0*/ == 1) //0x95c
            {
               //21c5ba10
            }
            else if (a->fill_2340/*r0*/ == 2) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 3) //0x95c
            {
               //21c5ba10
            }
            else if (a->fill_2340/*r0*/ == 4) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 0) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else
            {
               //21c5ba10
               //r9 = 221; 
               //sp12 = 100;  
            }
         }
         //21c5aa84
         else if (a->displayAspectRatioL1/*r7*/ == 5)
         {
            //21c5aa8c
            r9 = 235;
            sp12 = 100; 
            if (a->fill_2340/*r0*/ == 1) //0x95c
            {
               //21c5aab8
            }
            else if (a->fill_2340/*r0*/ == 2) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 3) //0x95c
            {
               //21c5aab8
            }
            else if (a->fill_2340/*r0*/ == 4) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else if (a->fill_2340/*r0*/ == 0) //0x95c
            {
               //21c5ab5c / 21932820
               r9 = 1;
               sp12 = 1;
            }
            else
            {
               //21c5aab8
               //r9 = 235;
               //sp12 = 100; 
            }
         }
         else
         {
            //21c5ab5c / 21932820
            r9 = 1;
            sp12 = 1;
         }

         if ((r9 == 1) && (sp12 == 1))
         {
            //21c5ab5c / 21932820
            sp0x20.startX0/*sp36*/ = 0;
            sp0x20.startY0/*sp32*/ = 0;
            sp0x20.horSize/*r8*/ = sp0x3c.horSize/*r7*/;
            sp0x20.verSize/*sl*/ = sp0x3c.verSize/*r5*/;
            
            sp0x04.startX0/*r0*/ = 0;
            sp0x04.startY0/*r1*/ = 0;
            sp0x04.horSize/*r5*/ = sp0x3c.horSize/*r7*/;
            sp0x04.verSize/*r6*/ = sp0x3c.verSize/*r5*/;
            //->21c5ab70
         }
         else
         {
            //21c5aac0            
            if (sp0x3c.horSize/*r7*/ > sp0x3c.verSize/*r5*/)
            {
               //21c5aac8
               if (sp0x3c.verSize/*r5*/ * r9/sp12 <= sp0x3c.horSize/*r7*/)
               {
                  //21c5aae8
                  sp0x20.startX0/*sp36*/ = (sp0x3c.horSize/*r7*/ - sp0x3c.verSize/*r5*/ * r9/sp12) / 2;
                  sp0x20.startY0/*sp32*/ = 0;
                  sp0x20.horSize/*r8*/ = sp0x3c.verSize/*r5*/ * r9/sp12;
                  sp0x20.verSize/*sl*/ = sp0x3c.verSize/*r5*/;
               }
               else
               {
                  //21c5bb40
                  sp0x20.startX0/*sp36*/ = 0;
                  sp0x20.startY0/*sp32*/ = (sp0x3c.verSize/*r5*/ - sp0x3c.horSize/*r7*/ * sp12/r9) / 2;
                  sp0x20.horSize/*r8*/ = sp0x3c.horSize/*r7*/;
                  sp0x20.verSize/*sl*/ = sp0x3c.horSize/*r7*/ * sp12/r9;
                  //219328c8
               }
            }
            else
            {
               //21c5b654
               if (sp0x3c.horSize/*r7*/ * sp12/r9 <= sp0x3c.verSize/*r5*//*r1*/)
               {
                  //21c5b674
                  sp0x20.startX0/*sp36*/ = 0;
                  sp0x20.startY0/*sp32*/ = (sp0x3c.verSize/*r5*/ - sp0x3c.horSize/*r7*/ * sp12/r9) / 2;
                  sp0x20.horSize/*r8*/ = sp0x3c.horSize/*r7*/;
                  sp0x20.verSize/*sl*/ = sp0x3c.horSize/*r7*/ * sp12/r9;
               }
               else
               {
                  //21c5bb6c
                  sp0x20.startX0/*sp36*/ = (sp0x3c.horSize/*r7*/ - sp0x3c.verSize/*r5*/ * r9/sp12) / 2;
                  sp0x20.startY0/*sp32*/ = 0;
                  sp0x20.horSize/*r8*/ = sp0x3c.verSize/*r5*/ * r9/sp12;
                  sp0x20.verSize/*sl*/ = sp0x3c.verSize/*r5*/;
               }
            }
         }
         //21c5ab70
         sp0x04.horSize/*r5*/ = sp0x20.horSize/*r8*/;
         sp0x04.verSize/*r6*/ = sp0x20.verSize/*sl*/;
         //21c5ab70
         if (a->userScalingMethod/*r0*/ == 1) //2332
         {
            //21c5abc0
            r9 = 4;
            sp12 = 3;
            if (a->displayAspectRatioL1/*r7*/ == 1)
            {
               //21c5b624
               if (a->fill_2340/*r0*/ == 1)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 2)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }                  
               else if (a->fill_2340/*r0*/ == 3)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 4) 
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 0)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5abd0
               }
            }
            //21c5abc8
            else if (a->displayAspectRatioL1/*r7*/ == 3)
            {
               //21c5b92c
               if (a->fill_2340/*r0*/ == 1) //0x95c
               {
                  //21c5abd0
               }
               //21c5b630
               else if (a->fill_2340/*r0*/ == 2)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 3)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 4)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else if (a->fill_2340/*r0*/ == 0)
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5abd0
               }
            }
            else
            {
               //21c5abd0
            }
         } //if (a->userScalingMethod/*r0*/ == 1) //0x954
         //21c5ab7c
         else if (a->userScalingMethod/*r0*/ == 2) //0x954
         {
            //21c5ab80
            r9 = 14;
            sp12 = 9;
         }
         //21c5ab8c
         else if (a->userScalingMethod/*r0*/ == 3) //0x954
         {
            //21c5b564
            r9 = 16;
            sp12 = 9;
            if (a->displayAspectRatioL1/*r7*/ == 1)
            {
               //21c5bb08
               if (a->fill_2340/*r0*/ == 1) //2340
               {
                  //21c5bb10
                  r9 = 64; //237;
                  sp12 = 27; //100;
               } //if (a->fill_2340/*r0*/ == 1) //0x95c
               //21c5bb1c
               else if (a->fill_2340/*r0*/ == 2) //0x95c
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5bb24
               else if (a->fill_2340/*r0*/ == 3) //0x95c
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5bb2c
               else if (a->fill_2340/*r0*/ == 4) //0x95c
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               //21c5bb34
               else if (a->fill_2340/*r0*/ == 0) //0x95c
               {
                  //21c5abac
                  r9 = 1;
                  sp12 = 1;
               }
               else
               {
                  //21c5b56c
               }
            }
            else
            {
               //21c5b56c
               //r9 = 16;
               //sp12 = 9;
            }
         } //else if (a->userScalingMethod/*r0*/ == 3) //0x954
         //21c5ab94
         else if (a->userScalingMethod/*r0*/ == 4) //0x954
         {
            //21c5ab98
            r9 = 221;
            sp12 = 100;
         } 
         //21c5aba4
         else if (a->userScalingMethod/*r0*/ == 5) //0x954
         {
            //21c5b800
            r9 = 235;
            sp12 = 100;
         } 
         else
         {
            //21c5ad70 / 21932cc4
            r9 = 1;
            sp12 = 1;
         }
         //21932cb8
         if ((r9 == 1) && (sp12 == 1))
         {
            //21c5abac
            sp0x04.startX0/*r0*/ = 0;
            sp0x04.startY0/*r1*/ = 0;
            //->21c5a6e8
         }
         else
         {
            //21c5abd8 / 21932cd0
            if (sp0x20.horSize/*r8*/ > sp0x20.verSize/*sl*/)
            {
               //21932cdc
               if (sp0x20.horSize/*r8*/ * r9/sp12 <= sp0x20.horSize/*r8*//*r1*/)
               {
                  //21932cf4               
                  sp0x04.startX0/*r0*/ = (sp0x20.horSize/*r8*/ - sp0x20.horSize/*r8*/ * r9/sp12) / 2;
                  sp0x04.startY0/*r1*/ = 0;
                  sp0x04.horSize/*r5*/ = sp0x20.horSize/*r8*/ * r9/sp12;
                  //->21932d68
               }
               else
               {
                  //21932d0c
                  sp0x04.startX0/*r0*/ =  0;
                  sp0x04.startY0/*r1*/ = (sp0x20.verSize/*sl*/ - sp0x20.horSize/*r8*/ * sp12/r9) / 2;
                  sp0x04.verSize/*r6*/ = sp0x20.horSize/*r8*/ * sp12/r9;
               }
            }
            else
            {
               //21932d38
               if (sp0x20.verSize/*sl*/ * sp12/r9 <= sp0x20.verSize/*sl*//*r1*/)
               {
                  //21932d50
                  sp0x04.startX0/*r0*/ = 0;
                  sp0x04.startY0/*r1*/ = (sp0x20.verSize/*sl*/ - sp0x20.verSize/*sl*/ * sp12/r9) / 2;
                  sp0x04.verSize/*r6*/ = sp0x20.verSize/*sl*/ * sp12/r9;
                  //21932d68
               }
               else
               {
                  //21932670
                  sp0x04.startX0/*r0*/ = (sp0x20.horSize/*r8*/ - sp0x20.verSize/*sl*/ * r9/sp12) / 2;
                  sp0x04.startY0/*r1*/ = 0;
                  sp0x04.horSize/*r5*/ = sp0x20.verSize/*sl*/ * r9/sp12;
                  //->21932d68
               }
            }
         }
      }
      //21c5a6e8
      a->userScalerReq.outputWindowX0 = //2432
         ((sp0x3c.startX0/*fp*/ + sp0x20.startX0/*sp36*/ + sp0x04.startX0/*r0*/) * sp4) + sp0x58.startX0/*sp24*/;

      a->userScalerReq.outputWindowY0 = //2436
         ((sp0x3c.startY0/*sp28*/ + sp0x20.startY0/*sp32*/ + sp0x04.startY0/*r1*/) / r11/*sp8*/) + sp0x58.startY0/*sp20*/;
            
      a->userScalerReq.outputWindowWidth = //2440
         sp0x04.horSize/*r5*/ * sp4;
         
#if 0
      if (r11/*sp8*/ != 2)
      {
         a->userScalerReq.outputWindowHeight = //2444
            sp0x04.verSize/*r6*/;
      }
      else
      {
         a->userScalerReq.outputWindowHeight = //2444
            (sp0x04.verSize/*r6*/ + 1) / 2;
      }
#else
      a->userScalerReq.outputWindowHeight = sp0x04.verSize/*r6*/ / r11/*sp8*/; //2444
#endif
   }
   
   return res;
}


/* 21932e18 - todo */
static int32_t func_21932e18(FAPI_VISCALE_VideoScalerHandleT* r4,
      FAPI_VISCALE_ScalerParamsT* r11)
{
   int32_t res; // = FAPI_OK;
   unsigned r5;
   //int r6;
   unsigned r7;
   FAPI_VISCALE_ActiveRegionDataT sp0x58 = {0};
   FAPI_VISCALE_ActiveRegionDataT sp0x3c = {0};
   FAPI_VISCALE_ActiveRegionDataT sp0x20 = {0};
   FAPI_VISCALE_ActiveRegionDataT sp4 = {0};

   sp0x58.startX0 = 0;
   sp0x58.startY0 = 0;
   sp0x58.horSize = r4->afdScalerReq.inputPicWidth; //2356 -> r5
   sp0x58.verSize = r4->afdScalerReq.inputPicHeight; //2360 -> r6
   
   //r6 = r4->currAfd; //0xa50
   r5 = 0; //r4->afdScalerReq.inputPicWidth; //2356 -> r5
   r7 = 0; //r4->afdScalerReq.inputPicHeight; //2360 -> r6

   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->currAfd=%d\n",
         r4->currAfd);
   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->afdScalerReq.inputPicWidth=%d\n",
         r4->afdScalerReq.inputPicWidth);
   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->afdScalerReq.inputPicHeight=%d\n",
         r4->afdScalerReq.inputPicHeight);
   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->inputAspectRatio=%d\n",
         r4->inputAspectRatio);
   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->displayAspectRatioL0=%d\n",
         r4->displayAspectRatioL0);
   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->displayAspectRatioL1=%d\n",
         r4->displayAspectRatioL1);
   FAPI_SYS_PRINT_DEBUG(4, "func_21932e18: r4->fill_2340=%d\n",
         r4->fill_2340);
   
   if (/*r6*/r4->currAfd == 2) //2552
   {
      //21c5a818
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         sp0x58.verSize = sp0x58.verSize * 3 / 4;
      }
   }
   else if (/*r6*/r4->currAfd == 3)
   {
      //21c5ac1c
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5b294
         sp0x58.verSize = sp0x58.verSize * 12 / 14;
      }
      else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5ac30
         sp0x58.startX0 = sp0x58.horSize / 16;
         sp0x58.horSize = sp0x58.horSize * 14 / 16;         
      }
   }
   else if (/*r6*/r4->currAfd == 4)
   {
      //21c5ab04
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5ab10
         sp0x58.startY0 = sp0x58.verSize / 8;
         sp0x58.verSize = sp0x58.verSize * 3 / 4;
      }
   }
   else if (/*r6*/r4->currAfd == 8)
   {
      //->21c5a348
   }
#if 0
   else if (/*r6*/r4->currAfd == 0)
   {
      //->21933268
   }
#endif
   else if (/*r6*/r4->currAfd == 9)
   {
      //21c5a93c
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //->21c5a348
      }
      else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5a94c
         sp0x58.startX0 = sp0x58.horSize / 8;
         sp0x58.horSize = sp0x58.horSize * 3 / 4;
      }
   }
   else if (/*r6*/r4->currAfd == 10)
   {
      //21c5ab04
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5ab10
         sp0x58.startY0 = sp0x58.verSize / 8;
         sp0x58.verSize = sp0x58.verSize * 3 / 4;
      }
   }
   else if (/*r6*/r4->currAfd == 11)
   {
      //21c5b404
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5b410
         sp0x58.startY0 = sp0x58.verSize / 14;
         sp0x58.verSize = sp0x58.verSize * 12 / 14;
      }
      //21c5ac28
      else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5ac30
         sp0x58.startX0 = sp0x58.horSize / 16;
         sp0x58.horSize = sp0x58.horSize * 14 / 16;
      }
   }
   else if (/*r6*/r4->currAfd == 13)
   {
      //21c5a93c
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //->21c5a348
      }
      else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5a94c
         sp0x58.startX0 = sp0x58.horSize / 8;
         sp0x58.horSize = sp0x58.horSize * 3 / 4;
      }
   }
   else if (/*r6*/r4->currAfd == 14)
   {
      //21c5b7d8
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5ab10
         sp0x58.startY0 = sp0x58.verSize / 8;
         sp0x58.verSize = sp0x58.verSize * 3 / 4;
      }
      else if (r4->inputAspectRatio == FAPI_VISCALE_AR_14_9) //2)
      {
         //21c5ac30
         sp0x58.startX0 = sp0x58.horSize / 16;
         sp0x58.horSize = sp0x58.horSize * 14 / 16;
      }
   }
   else if (/*r6*/r4->currAfd == 15)
   {
      //21c5ab04
      if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5ab10
         sp0x58.startY0 = sp0x58.verSize / 8;
         sp0x58.verSize = sp0x58.verSize * 3 / 4;
      }
   }
   //21c5a350
   r4->afdScalerReq.inputWindowX0 = //2364
      sp0x58.startX0; //r1
   r4->afdScalerReq.inputWindowY0 = //2368
      sp0x58.startY0; //r0
   r4->afdScalerReq.inputWindowWidth = //2372
      sp0x58.horSize; //r5
   r4->afdScalerReq.inputWindowHeight = //2376
      sp0x58.verSize; //r6
   
   sp0x58.startX0 = 0;
   sp0x58.startY0 = 0;   
   //r8 = 8;
   if (/*r6*/r4->currAfd == 2)
   {
      //21c5a9b0
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      //21c5a9bc
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5b37c
         if (r4->fill_2340 == 0)
         {
            //->21c5b384
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5b398
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5b3b0
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5b3c8
            sp0x58.startX0 = sp0x58.horSize / 8;
            sp0x58.horSize = sp0x58.horSize * 3 / 4;
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4)
         {
            //->21c5b3ec
            r4->currWss = 1;
            //->21933ed0
         }
         //->21933ed0
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5a9cc
         if (r4->fill_2340 == 0)
         {
            //->21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1)
         {
            //->21c5a9e8
            r4->currWss = 13; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 2)
         {
            //->21933d30
            r4->currWss = 13; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 3)
         {
            //->21933d30
            r4->currWss = 13; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 4)
         {
            //->21933d30
            r4->currWss = 13;
            //->21933ed0
         }         
         //->21933ed0
      }
      //->21933ed0
   } //if (/*r6*/r4->currAfd == 2)
   //2193330c
   //r1 = 1;
   else if (/*r6*/r4->currAfd == 3)
   {
      //21c5ac48
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5af7c
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //21933338
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21c5bec0
            sp0x58.startX0 = sp0x58.horSize / 14;
            sp0x58.horSize = sp0x58.horSize * 12 / 14;
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         //->21933ed0
      }
      //21c5ac5c
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5ac64
         if (r4->fill_2340 == 0)
         {
            //21c5ac6c
            r4->currWss = 0;
            //->21933ed0
         }
         //2193336c
         else if (r4->fill_2340 == 1)
         {
            //->21c5ac80
            r4->currWss = 8;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2)
         {
            //->21c5ac9c
            r4->currWss = 8;
            //->21933ed0
         }
         //21933378
         else if (r4->fill_2340 == 3)
         {
            //21c5acb8
            r4->currWss = 8;
            //->21933ed0
         }
         //219333a8
         else if (r4->fill_2340 == 4)
         {
            //->21c5acd4
            r4->currWss = 8;
            //->21933ed0
         }
         //->21933ed0
      }
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 3)
   //219333b4
   //r2 = 13;
   else if (/*r6*/r4->currAfd == 4)
   {
      //21c5ae30
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5b59c
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5b5a4
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5b5b8
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5b5d0
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21c5b5e8
            sp0x58.startX0 = sp0x58.horSize / 8;
            sp0x58.horSize = sp0x58.horSize * 3 / 4;
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5b60c
            r4->currWss = 1;
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5ae4c
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //219333e0
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5ae68
            r4->currWss = 11;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5ae84
            r4->currWss = 11;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21c5aea0
            r4->currWss = 11;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //->21c5aebc
            r4->currWss = 11;
            //->21933ed0
         }         
         //->21933ed0
      }
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 4)
   //2193342c
   //r9 = 7;
   else if ((/*r6*/r4->currAfd == 8) || 0) //(/*r6*/r4->currAfd == 0))
   {
      //21c5a83c
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5b860
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5b868
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //2193345c
         else if (r4->fill_2340 == 1) //0x95c
         {
            //21c5b87c
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5bf80
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //21c5bf88
               sp0x58.startX0 = sp0x58.horSize / 8;
               sp0x58.horSize = sp0x58.horSize * 3 / 4;
               r4->currWss = 1;
            } //if (r4->inputAspectRatio == 3) //0x93c
            //219334ac
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21c5c180
               sp0x58.startX0 = sp0x58.horSize * 132 / (3*221);
               sp0x58.horSize = sp0x58.horSize * (4*100) / (3*221);
               r4->currWss = 1;
               //->21c5a4a8
            } //else if (r4->inputAspectRatio == 4) //0x93c
            //219334e4
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //21c5bfb8
               sp0x58.startX0 = sp0x58.horSize * 152 / (3*235);
               sp0x58.horSize = sp0x58.horSize * (4*100) / (3*235);
               r4->currWss = 1;
               //->21c5a4a8
            } //else if (r4->inputAspectRatio == 5) //0x93c
            //21933ed0
         } //else if (r4->fill_2340 == 3) //0x95c
         //21c5b8b0
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5b8b8
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            //21933574
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21c5b8d8
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21c5b8f4
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->21c5b910
               r4->currWss = 14;
               //->21933ed0
            }            
            //->21933ed0
         } //if (r4->fill_2340 == 4) //0x95c
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      //21c5a850
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5a858
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5a860
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //2193359c
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5a874
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5a890
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5c000
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //21c5c25c
               sp0x58.startY0 = sp0x58.verSize / 8;
               sp0x58.verSize = sp0x58.verSize * 3 / 4;
               r4->currWss = 14;
               //->21c5a4a8
            } //if (r4->inputAspectRatio == 1) //0x93c
            //219335f8
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //21c5c2b8
               sp0x58.startX0 = sp0x58.horSize * 194 / (9*221);
               sp0x58.horSize = sp0x58.horSize * 16*100 / (9*221);
               r4->currWss = 14;
               //->21c5a4a8
            } //else if (r4->inputAspectRatio == 4) //0x93c
            //21933644
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //21c5c01c
               sp0x58.startX0 = sp0x58.horSize * 257 / (9*235);
               sp0x58.horSize = sp0x58.horSize * 16*100 / (9*235);
               r4->currWss = 14;
               //->21c5a4a8
            } //else if (r4->inputAspectRatio == 5) //0x93c
            //->21933ed0
         } //else if (r4->fill_2340 == 3) //0x95c
         //21c5a8b0
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5a8b8
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21c5a8c0
               r4->currWss = 1;
               //->21933ed0
            }
            //219336a8
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) // 4)
            {
               //->219337b0
               r4->currWss = 11;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->219337b0
               r4->currWss = 11;
               //->21933ed0
            }
            //->21933ed0
         } //else if (r4->fill_2340 == 4) //0x95c
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3) //0x950
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 8)
   else if (/*r6*/r4->currAfd == 9)
   {
      //21c5b114
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1) //0x950
      {
         //21c5ba1c
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //219336e8
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5ba84
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      //21c5b128
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5b130
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5b138
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5b14c
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5b168
            r4->currWss = 14;
            //->21933ed0
         }
         //2193373c
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5c05c
            sp0x58.startY0 = sp0x58.verSize / 8;
            sp0x58.verSize = sp0x58.verSize * 3 / 4;
            r4->currWss = 14;
            //->21c5a4a8
         } //else if (r4->fill_2340 == 3) //0x95c
         //21c5b188
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5b190
            if (r4->inputAspectRatio == 1) //0x93c
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == 3) //0x93c
            {
               //->21933e54
               r4->currWss = 1;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == 4) //0x93c
            {
               //219337b0
               r4->currWss = 11;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == 5) //0x93c
            {
               //219337b0
               r4->currWss = 11;
               //->21933ed0
            }
            //->21933ed0
         } //else if (r4->fill_2340 == 4) //0x95c
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3) //0x950
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 9)
   else if (/*r6*/r4->currAfd == 10)
   {
      //21c5b2d4
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0) //0x950
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5bb98
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5bba0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5bbb4
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5bbcc
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21c5bbe4
            sp0x58.startX0 = sp0x58.horSize / 8;
            sp0x58.horSize = sp0x58.horSize * 3 / 4;
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5bc0c
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      //21c5b2e8
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5b2f0
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //->21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3)
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 10)
   //21933844
   else if (/*r6*/r4->currAfd == 11)
   {
      //21c5b43c
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) // 0)
      {
         //->21c5a49c
      }
      //21c5b448
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5bcb4
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5bcbc
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //219338dc
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5bcd0
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5bce8
            r4->currWss = 1;
            //->21933ed0
         }
         //219338e8
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5c080
            sp0x58.startX0 = sp0x58.horSize / 14;
            sp0x58.horSize = sp0x58.horSize * 12 / 14;
            r4->currWss = 1;
            //->21933ed0
         } //else if (r4->fill_2340 == 3) //0x95c
         //21c5bd04
         else if (r4->fill_2340 == 4) //0x95c
         {
            //->21c5bd08
            r4->currWss = 8;
            //->21933ed0
         } //else if (r4->fill_2340 == 4) //0x95c
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      //21c5b450
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5b458
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5b460
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5b474
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5b490
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5c0b4
            sp0x58.startY0 = sp0x58.verSize / 14;
            sp0x58.verSize = sp0x58.verSize * 12 / 14;
            r4->currWss = 14;
            //->21933ed0
         } //else if (r4->fill_2340 == 3) //0x95c
         //21c5b4b0
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5b4b8
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21c5b4c0
               r4->currWss = 8;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            //->21933ed0
         } //else if (r4->fill_2340 == 4) //0x95c
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3) //0x950
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 11)
   else if (/*r6*/r4->currAfd == 13)
   {
      //21c5afe8
      //r1 = 14;
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5bd94
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //21933aac
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21933e54
            r4->currWss = 1;
            //->21933ed0
         }
         //21933abc
         else if (r4->fill_2340 == 4) //0x95c
         {
            //->21933d30
            r4->currWss = 7;
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5b004
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5b00c
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //21933b8c
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5b020
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2)  //0x95c
         {
            //->21c5b03c
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5c280
            sp0x58.startY0 = sp0x58.verSize / 14;
            sp0x58.verSize = sp0x58.verSize * 12 / 14;
            r4->currWss = 14;
         } //else if (r4->fill_2340 == 3) //0x95c
         //21c5b05c
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5b064
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21c5b06c
               r4->currWss = 7;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21c5b088
               r4->currWss = 7;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21c5b0a4
               r4->currWss = 7;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->21c5b0c0
               r4->currWss = 7;
               //->21933ed0
            }
            //->21933ed0
         } //else if (r4->fill_2340 == 4) //0x95c
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3) //0x950
      //->21933ed0      
   } //else if (/*r6*/r4->currAfd == 13)
   else if (/*r6*/r4->currAfd == 14)
   {
      //21c5b6ec
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5be14
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5be1c
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //21933cf0
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5be30
            r4->currWss = 1;
            //->21933ed0
         }         
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5be48
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21c5be60
            sp0x58.startX0 = sp0x58.horSize / 8;
            sp0x58.horSize = sp0x58.horSize * 3 / 4;
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5be88
            sp0x58.startX0 = sp0x58.horSize / 14;
            sp0x58.horSize = sp0x58.horSize * 12 / 14;
            r4->currWss = 8;
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      //21c5b700
      else if (r4->displayAspectRatioL1 == 3) //0x950
      {
         //21c5b708
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5b710
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //21933d4c
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5b724
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5b73c
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //->21c5b754
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21c5b770
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //->21933ecc
               r4->currWss = 14;
               //->21933ed0
            }
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3) //0x950
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 14)
   //21933d80
   else if (/*r6*/r4->currAfd == 15)
   {
      //21c5b93c
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //->21c5a49c
      } //if (r4->displayAspectRatioL1 == 0) //0x950
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //21c5bef4
         if (r4->fill_2340 == 0) //0x95c
         {
            //->21c5befc
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         else if (r4->fill_2340 == 1) //0x95c
         {
            //->21c5bf10
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //->21c5bf28
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21c5bf40
            sp0x58.startX0 = sp0x58.horSize / 8;
            sp0x58.horSize = sp0x58.horSize * 3 / 4;
            r4->currWss = 1;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //->21c5bf64
            r4->currWss = 14;
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 1) //0x950
      //21c5b950
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5b958
         if (r4->fill_2340 == 0) //0x95c
         {
            //21933eb0
            r4->currWss = 0; //0xa5c
            //->21933ed0
         }
         //21933eb8
         else if (r4->fill_2340 == 1) //0x95c
         {
            //21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 2) //0x95c
         {
            //21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 3) //0x95c
         {
            //21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         else if (r4->fill_2340 == 4) //0x95c
         {
            //21933ecc
            r4->currWss = 14;
            //->21933ed0
         }
         //->21933ed0
      } //else if (r4->displayAspectRatioL1 == 3) //0x950
      //->21933ed0
   } //else if (/*r6*/r4->currAfd == 15)
   else
   {
      //21c5a3b0
      if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_NONE) //0)
      {
         //21c5a49c
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_4_3) //1)
      {
         //->21c5bd24
         if (r4->fill_2340 == 0)
         {
            //21c5bd2c
            r4->currWss = 0;
            //->21c5a4a8
         }
         else if (r4->fill_2340 == 1)
         {
            //21c5bd40
            r4->currWss = 1;
            //->21c5a4a8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5bd58
            r4->currWss = 1;
            //->21c5a4a8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c1c4
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //21c5c1cc
               r4->currWss = 1;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //21c5c1e4
               sp0x58.startX0 = sp0x58.horSize / 8;
               sp0x58.horSize = sp0x58.horSize * 3 / 4;
               r4->currWss = 1;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21c5c350
               sp0x58.startX0 = sp0x58.horSize * 132 / (3*221);
               sp0x58.horSize = sp0x58.horSize * (4*100) / (3*221);
               r4->currWss = 1;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //21c5c214
               sp0x58.startX0 = sp0x58.horSize * 152 / (3*235);
               sp0x58.horSize = sp0x58.horSize * (4*100) / (3*235);
               r4->currWss = 1;
               //->21c5a4a8
            }
         }
         else if (r4->fill_2340 == 4)
         {
            //21c5bd78
            r4->currWss = 14;
            //->21c5a4a8
         }
      }
      else if (r4->displayAspectRatioL1 == FAPI_VISCALE_AR_16_9) //3)
      {
         //21c5a3cc
         if (r4->fill_2340 == 0)
         {
            //21c5a3d4
            r4->currWss = 0;
            //->21c5a4a8
         }
         else if (r4->fill_2340 == 1)
         {
            //21c5a3e8
            r4->currWss = 14;
            //->21c5a4a8
         }
         else if (r4->fill_2340 == 2)
         {
            //21c5a404
            r4->currWss = 14;
            //->21c5a4a8
         }
         else if (r4->fill_2340 == 3)
         {
            //->21c5c0ec
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //21c5c0f4
               sp0x58.startY0 = sp0x58.verSize / 8;
               sp0x58.verSize = sp0x58.verSize * 3 / 4;
               r4->currWss = 1;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //21c5c118
               r4->currWss = 14;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //->21c5c304
               sp0x58.startX0 = sp0x58.horSize * 194 / (9*221);
               sp0x58.horSize = sp0x58.horSize * 16*100 / (9*221);
               r4->currWss = 14;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //21c5c140
               sp0x58.startX0 = sp0x58.horSize * 257 / (9*235);
               sp0x58.horSize = sp0x58.horSize * 16*100 / (9*235);
               r4->currWss = 14;
               //->21c5a4a8
            }
         } //else if (a->fill_2340 == 3)
         else if (r4->fill_2340 == 4)
         {
            //21c5a42c
            if (r4->inputAspectRatio == FAPI_VISCALE_AR_4_3) //1)
            {
               //21c5a434
               r4->currWss = 1;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_16_9) //3)
            {
               //21c5a44c
               r4->currWss = 14;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_221_100) //4)
            {
               //21c5a468
               r4->currWss = 11;
               //->21c5a4a8
            }
            else if (r4->inputAspectRatio == FAPI_VISCALE_AR_235_100) //5)
            {
               //21c5a484
               r4->currWss = 11;
               //->21c5a4a8
            }
         }
      }
   }
   //21c5a4a8
   if ((r4->wssState == FAPI_VISCALE_UNKNOWN_WSS_STATE) || //-1) ||
         (r4->wssState == FAPI_VISCALE_WSS_DISABLE)) //0))
   {
      r4->currWss = 0;
      //->21c5a4c8
   }
   else if (r4->wssState != FAPI_VISCALE_WSS_ENABLE_AUTO) //16)
   {
      r4->currWss = r4->wssState;
   }
   //21c5a4c8
   if (1 == FREG_VE_GetmEnc656wss_WssMode())
   {
      //->21c5ae24
      FREG_VE_SetWssdata_Wssword(r4->currWss);
   }
   //21c5a4d4
   r4->smScalerReq.inputWindowX0 = //2468
         sp0x58.startX0; //r7
   r4->smScalerReq.inputWindowY0 = //2472
         sp0x58.startY0; //sp40
   r4->smScalerReq.inputWindowWidth = //2476
         sp0x58.horSize; //r5
   r4->smScalerReq.inputWindowHeight = //2480
         sp0x58.verSize; //r6
   
   res = FAPI_OK;
   
   sp0x3c.startX0 = 0;
   sp0x3c.startY0 = 0;
   sp0x3c.horSize = r4->smScalerReq.inputWindowWidth; //sp0x58.horSize = r5;
   sp0x3c.verSize = r4->smScalerReq.inputWindowHeight; //sp0x58.verSize = r6;
   
   if (r4->isrDataPtr->iUserScalerReqState == //2)
         FAPI_VISCALE_USER_SCALER_REQUEST)
   {
      //->21c5a984
      if (r11 != 0)
      {
         r4->userRawScalerReq.inputWindowX0 = //2276
            r11->inputWindowX0; //1084
         
         r4->userRawScalerReq.inputWindowY0 = //2280
            r11->inputWindowY0; //1088
         
         r4->userRawScalerReq.inputWindowWidth = //2284
            r11->inputWindowWidth; //1092
         
         r4->userRawScalerReq.inputWindowHeight = //2288
            r11->inputWindowHeight; //1096
      }
   }
   //21c5a4f8
   if (r4->userRawScalerReq.inputWindowX0/*2276*/ > sp0x3c.horSize/*r5*/)
   {
      sp0x20.startX0/*r2*/ = 0;
   }
   else
   {
      sp0x20.startX0/*r2*/ = r4->userRawScalerReq.inputWindowX0; //2276
   }
   //21933f7c
   if (r4->userRawScalerReq.inputWindowY0/*2280*/ > sp0x3c.verSize)
   {
      sp0x20.startY0/*r1*/ = 0;
   }
   else
   {
      sp0x20.startY0/*r1*/ = r4->userRawScalerReq.inputWindowY0; //2280
   }

   if (r4->userRawScalerReq.inputWindowWidth == 0) //2284
   {
      //->21c5a934
      sp0x20.horSize = //ip
            sp0x3c.horSize - //r5
            sp0x20.startX0; //r2
      //->21c5a528
   }
   else if ((r4->userRawScalerReq.inputWindowWidth + sp0x20.startX0) <=
         sp0x3c.horSize) //r5
   {
      sp0x20.horSize = r4->userRawScalerReq.inputWindowWidth; //2284
      //->21933fd4
   }
   else
   {
      //->21c5a934
      sp0x20.horSize = //ip
            sp0x3c.horSize - //r5
            sp0x20.startX0; //r2
   }
   //21c5a528
   if (r4->userRawScalerReq.inputWindowHeight == 0) //2288
   {
      //->21c5a92c
      sp0x20.verSize = //r0
            sp0x3c.verSize - //r6
            sp0x20.startY0; //r1
      //->21934018
   }
   //21933ff4
   else if ((r4->userRawScalerReq.inputWindowHeight + sp0x20.startY0) <=
         sp0x3c.verSize)
   {
      sp0x20.verSize = r4->userRawScalerReq.inputWindowHeight; //2288
      //->21934018
   }
   else
   {
      //->21c5a92c
      sp0x20.verSize = //r0
            sp0x3c.verSize - //r6
            sp0x20.startY0; //r1
   }
   //21c5a540
   sp4.horSize = sp0x20.horSize; //ip
   sp4.verSize = sp0x20.verSize; //r0
   
   r4->userScalerReq.inputWindowX0 = //2416
         sp0x20.startX0; //r2
   r4->userScalerReq.inputWindowY0 = //2420
         sp0x20.startY0; //r1
   r4->userScalerReq.inputWindowWidth = //2424
         sp4.horSize; //ip
   r4->userScalerReq.inputWindowHeight = //2428
         sp4.verSize; //r0
   
   return res; //FAPI_OK; //res;
}


/* 21c5a2cc - todo */
/* 21934050 - complete */
int32_t func_21c5a2cc(FAPI_VISCALE_VideoScalerHandleT* a,
      FAPI_VISCALE_ScalerParamsT* b)
{      
   int32_t res = FAPI_OK;
   
   if (a->hdMode == FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   
   res = func_21932e18(a, b);
   
   res = func_21931e94(a, b);
   //21c5a748
   if (a->scalingMethod == 0) //2336
   {
      //21c5a754
      a->autoScalerReq.inputWindowX0 = //2520
            a->userScalerReq.inputWindowX0 + //2416
            a->afdScalerReq.inputWindowX0; //2364
      
      a->autoScalerReq.inputWindowY0 = //2524 
            a->userScalerReq.inputWindowY0 + //2420
            a->afdScalerReq.inputWindowY0; //2368
      
      a->autoScalerReq.inputWindowWidth = //2528
            a->userScalerReq.inputWindowWidth; //2424
      
      a->autoScalerReq.inputWindowHeight = //2532
            a->userScalerReq.inputWindowHeight; //2428
   }
   else
   {

      //->21c5a968
      a->autoScalerReq.inputWindowX0 = //2520 
            a->smScalerReq.inputWindowX0 + //2468
            a->afdScalerReq.inputWindowX0; //2364
      
      a->autoScalerReq.inputWindowY0 = //2524 
            a->smScalerReq.inputWindowY0 + //2472
            a->afdScalerReq.inputWindowY0; //2368
      
      a->autoScalerReq.inputWindowWidth = //2528
            a->smScalerReq.inputWindowWidth; //2476
      
      a->autoScalerReq.inputWindowHeight = //2532
            a->smScalerReq.inputWindowHeight; //2480
   }

   a->autoScalerReq.outputWindowX0 = //2536
         a->userScalerReq.outputWindowX0; //2432
   
   a->autoScalerReq.outputWindowY0 = //2540
         a->userScalerReq.outputWindowY0; //2436
   
   a->autoScalerReq.outputWindowWidth = //2544
         a->userScalerReq.outputWindowWidth; //2440 
   
   a->autoScalerReq.outputWindowHeight = //2548
         a->userScalerReq.outputWindowHeight; //2444
      
   if (a->scalerParams.frameField == 0) //104
   {
      a->scalerParams.inputWindowY0 = //1164
            a->autoScalerReq.inputWindowY0 / 2; //2524
      
      a->scalerParams.inputWindowHeight = //1172
            a->autoScalerReq.inputWindowHeight / 2; //2532
   }
   else
   {
      a->scalerParams.inputWindowY0 = //1164
            a->autoScalerReq.inputWindowY0; //2524
      
      a->scalerParams.inputWindowHeight = //1172
            a->autoScalerReq.inputWindowHeight; //2532
   }

   a->scalerParams.inputWindowX0 = //1160
            a->autoScalerReq.inputWindowX0; //2520
   
   a->scalerParams.inputWindowWidth = //1168
            a->autoScalerReq.inputWindowWidth; //2528
      
   a->scalerParams.outputWindowX0 = //1176 
            a->autoScalerReq.outputWindowX0; //2536
   
   a->scalerParams.outputWindowY0 = //1180
            a->autoScalerReq.outputWindowY0; //2540
   
   a->scalerParams.outputWindowWidth = //1184 
            a->autoScalerReq.outputWindowWidth; //2544
   
   a->scalerParams.outputWindowHeight = //1188
            a->autoScalerReq.outputWindowHeight; //2548
   //21c5a804
   func_21c5a0ac(a); //219359d4
   
   return res;
}


/* 21c5cad4 - complete */
int32_t waitFiltersUpdated(FAPI_VISCALE_VideoScalerHandleT* a)
{   
   uint64_t t1 = FAPI_TIMER_GetTimeStamp(1000);
   
   while (1)
   {
      uint64_t t2 = FAPI_TIMER_GetTimeStamp(1000) - t1;
      
      if (a->isrDataPtr->iFilterState == FAPI_VISCALE_FILTERS_UPDATED)
      {
         return FAPI_OK;
      }

      if (t2 > FAPI_VISCALE_ISR_TIMEOUT)
      {
         return FAPI_VISCALE_ERR_OPERATION_TIMEOUT;
      }
      
      FAPI_SYS_SLEEP(50);
   }
}


