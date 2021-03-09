
#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>


int32_t func_21c5d108(FAPI_VISCALE_VideoScalerHandleT*, 
      FAPI_VISCALE_ActiveRegionDataT*);
static int32_t waitEnableDisable(FAPI_VISCALE_VideoScalerHandleT*);
void fapi_viscale_set_clut_acbycr(uint32_t index, uint32_t colour);
void fapi_viscale_set_clut_cbycra(uint32_t index, uint32_t colour);
void fapi_viscale_set_clut_rgba(uint32_t index, uint32_t colour);
void fapi_viscale_set_clut_argb(uint32_t index, uint32_t colour);



/* 21c5dd64 - complete */
int32_t fapi_viscale_osd1start(FAPI_SYS_HandleT handle,
                    FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1start\n");
   
   FAPI_VISCALE_ActiveRegionDataT sp;
   
   unsigned r7;
   int32_t res;  
   unsigned i = 0;
   unsigned sl = 0;   
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   
   if (h->hdMode == FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }
   
   if (scaleParamsPtr->osdLayout == FAPI_VISCALE_UNKNOWN_OSD_LAYOUT)
   {
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   
   h->scalerParams.osdLayout = scaleParamsPtr->osdLayout;
   
   if (scaleParamsPtr->osdMode == FAPI_VISCALE_UNKNOWN_OSD_MODE)
   {
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   
   h->scalerParams.osdMode = scaleParamsPtr->osdMode;
   h->scalerParams.cpMode = FAPI_VISCALE_UNKNOWN_CURSOR_MODE;
   
   if (scaleParamsPtr->picBase == 0)
   {
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   
   h->scalerParams.picBase = 
      FAPI_SYS_GET_PHYSICAL_ADDRESS(scaleParamsPtr->picBase);
   
   if (h->scalerParams.picBase % 1024)
   {
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   
   h->scalerParams.picBase &= ~0x3ff; //%= 1024;
   
   if (scaleParamsPtr->osdMode != FAPI_VISCALE_OSD_MODE_5551)
   {
      switch (scaleParamsPtr->osdLayout)
      {
      case FAPI_VISCALE_OSD_LAYOUT_ARGB:
         //21c5e62c
         FREG_VO_SetOsdrgbyuv11(0, 0x81);
         FREG_VO_SetOsdrgbyuv12(0, 0x42);
         FREG_VO_SetOsdrgbyuv13(0, 0x19);
         FREG_VO_SetOsdrgbyuv14(0, 0x10);
         FREG_VO_SetOsdrgbyuv21(0, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(0, 0x1da);
         FREG_VO_SetOsdrgbyuv23(0, 0x70);
         FREG_VO_SetOsdrgbyuv24(0, 0x80);
         FREG_VO_SetOsdrgbyuv31(0, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(0, 0x70);
         FREG_VO_SetOsdrgbyuv33(0, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(0, 0x80);
         FREG_VO_SetOsdmode_CbSelect(0, 3);
         FREG_VO_SetOsdmode_YSelect(0, 3);
         FREG_VO_SetOsdmode_CrSelect(0, 3);
         FREG_VO_SetOsdmode_AlphaSelect(0, 3);
         FREG_VO_SetOsdmode_RgbEnable(0, 1);
         //->21c5de90
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_RGBA:
         //21c5e55c
         FREG_VO_SetOsdrgbyuv11(0, 0x81);
         FREG_VO_SetOsdrgbyuv12(0, 0x42);
         FREG_VO_SetOsdrgbyuv13(0, 0x19);
         FREG_VO_SetOsdrgbyuv14(0, 0x10);
         FREG_VO_SetOsdrgbyuv21(0, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(0, 0x1da);
         FREG_VO_SetOsdrgbyuv23(0, 0x70);
         FREG_VO_SetOsdrgbyuv24(0, 0x80);
         FREG_VO_SetOsdrgbyuv31(0, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(0, 0x70);
         FREG_VO_SetOsdrgbyuv33(0, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(0, 0x80);
         FREG_VO_SetOsdmode_CbSelect(0, 0);
         FREG_VO_SetOsdmode_YSelect(0, 0);
         FREG_VO_SetOsdmode_CrSelect(0, 0);
         FREG_VO_SetOsdmode_AlphaSelect(0, 0);
         FREG_VO_SetOsdmode_RgbEnable(0, 1);
         //->21c5de90
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_ACbYCr:
         //21c5ded0
         FREG_VO_SetOsdmode_CbSelect(0, 3);
         FREG_VO_SetOsdmode_YSelect(0, 3);
         FREG_VO_SetOsdmode_CrSelect(0, 3);
         FREG_VO_SetOsdmode_AlphaSelect(0, 3);
         FREG_VO_SetOsdmode_RgbEnable(0, 0);
         //->21c5de90
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_CbYCrA:
         //21c5de54
         FREG_VO_SetOsdmode_CbSelect(0, 0);
         FREG_VO_SetOsdmode_YSelect(0, 0);
         FREG_VO_SetOsdmode_CrSelect(0, 0);
         FREG_VO_SetOsdmode_AlphaSelect(0, 0);
         FREG_VO_SetOsdmode_RgbEnable(0, 0);
         //21c5de90
         break;
         
      default:
         //->21c5dd9c
         return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
      }
   }
   else
   {
      //21c5de30
      switch (scaleParamsPtr->osdLayout)
      {
      case FAPI_VISCALE_OSD_LAYOUT_ARGB:
         //21c5e73c
         FREG_VO_SetOsdrgbyuv11(0, 0x81);
         FREG_VO_SetOsdrgbyuv12(0, 0x42);
         FREG_VO_SetOsdrgbyuv13(0, 0x19);
         FREG_VO_SetOsdrgbyuv14(0, 0x10);
         FREG_VO_SetOsdrgbyuv21(0, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(0, 0x1da);
         FREG_VO_SetOsdrgbyuv23(0, 0x70);
         FREG_VO_SetOsdrgbyuv24(0, 0x80);
         FREG_VO_SetOsdrgbyuv31(0, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(0, 0x70);
         FREG_VO_SetOsdrgbyuv33(0, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(0, 0x80);
         FREG_VO_SetOsdmode_CbSelect(0, 0);
         FREG_VO_SetOsdmode_YSelect(0, 0);
         FREG_VO_SetOsdmode_CrSelect(0, 0);
         FREG_VO_SetOsdmode_AlphaSelect(0, 1);
         FREG_VO_SetOsdmode_RgbEnable(0, 1);
         //->21c5de90
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_RGBA:
         //21c5e55c
         FREG_VO_SetOsdrgbyuv11(0, 0x81);
         FREG_VO_SetOsdrgbyuv12(0, 0x42);
         FREG_VO_SetOsdrgbyuv13(0, 0x19);
         FREG_VO_SetOsdrgbyuv14(0, 0x10);
         FREG_VO_SetOsdrgbyuv21(0, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(0, 0x1da);
         FREG_VO_SetOsdrgbyuv23(0, 0x70);
         FREG_VO_SetOsdrgbyuv24(0, 0x80);
         FREG_VO_SetOsdrgbyuv31(0, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(0, 0x70);
         FREG_VO_SetOsdrgbyuv33(0, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(0, 0x80);
         FREG_VO_SetOsdmode_CbSelect(0, 0);
         FREG_VO_SetOsdmode_YSelect(0, 0);
         FREG_VO_SetOsdmode_CrSelect(0, 0);
         FREG_VO_SetOsdmode_AlphaSelect(0, 0);
         FREG_VO_SetOsdmode_RgbEnable(0, 1);
         //->21c5de90
         break;
        
      case FAPI_VISCALE_OSD_LAYOUT_ACbYCr:
         //21c5e6fc
         FREG_VO_SetOsdmode_CbSelect(0, 0);
         FREG_VO_SetOsdmode_YSelect(0, 0);
         FREG_VO_SetOsdmode_CrSelect(0, 0);
         FREG_VO_SetOsdmode_AlphaSelect(0, 1);
         FREG_VO_SetOsdmode_RgbEnable(0, 0);
         //->21c5de90
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_CbYCrA:
         //21c5de54
         FREG_VO_SetOsdmode_CbSelect(0, 0);
         FREG_VO_SetOsdmode_YSelect(0, 0);
         FREG_VO_SetOsdmode_CrSelect(0, 0);
         FREG_VO_SetOsdmode_AlphaSelect(0, 0);
         FREG_VO_SetOsdmode_RgbEnable(0, 0);
         //21c5de90
         break;
         
      default:
         //->21c5dd9c
         return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
      }
   }
   //21c5de90   
   switch (scaleParamsPtr->osdMode)
   {
   case FAPI_VISCALE_OSD_MODE_32_24BIT:
      //21c5e454
      h->pixPerBurst = 32;
      h->bitsPerPix = 8;
      r7 = 4;
      //->21c5df38
      break;
      
   case FAPI_VISCALE_OSD_MODE_5551:
   case FAPI_VISCALE_OSD_MODE_4444:
   case FAPI_VISCALE_OSD_MODE_16BIT:
      //21c5e43c
      h->pixPerBurst = 64;
      h->bitsPerPix = 4;
      r7 = 2;
      //->21c5df38
      break;
      
   case FAPI_VISCALE_OSD_MODE_CLUT_4BIT:
      //21c5e3a4
      h->pixPerBurst = 256;
      h->bitsPerPix = 1;
      r7 = 1;
      //->21c5df38
      break;
      
   case FAPI_VISCALE_OSD_MODE_CLUT_8BIT:
      //21c5df24
      h->pixPerBurst = 128;
      h->bitsPerPix = 2;
      r7 = 1;
      //21c5df38
      break;
      
   default:
      //21c5df10
      h->pixPerBurst = -1;
      h->bitsPerPix = -1;
      //->21c5dd84
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5df38
   switch (scaleParamsPtr->osdMode)
   {
   case FAPI_VISCALE_OSD_MODE_32_24BIT:
   case FAPI_VISCALE_OSD_MODE_5551:
   case FAPI_VISCALE_OSD_MODE_4444:
   case FAPI_VISCALE_OSD_MODE_16BIT:
      //21c5df98
      break;
      
   case FAPI_VISCALE_OSD_MODE_CLUT_4BIT:
   case FAPI_VISCALE_OSD_MODE_CLUT_8BIT:
      //21c5df58
      if (scaleParamsPtr->osdLayout == 
         FAPI_VISCALE_OSD_LAYOUT_ARGB) //1)
      {
         //21c5e414
         for (i = 0; i < 256; i++)
         {
            fapi_viscale_set_clut_argb(i, 
                  scaleParamsPtr->colourLut[i]);
         }
         //->21c5df98
      }
      else if (scaleParamsPtr->osdLayout == 
         FAPI_VISCALE_OSD_LAYOUT_RGBA) //2)
      {
         //21c5e3ec
         for (i = 0; i < 256; i++)
         {
            fapi_viscale_set_clut_rgba(i, 
                  scaleParamsPtr->colourLut[i]);
         }
         //->21c5df98
      }
      else if (scaleParamsPtr->osdLayout == 
         FAPI_VISCALE_OSD_LAYOUT_ACbYCr) //3)
      {
         //21c5df74
         for (i = 0; i < 256; i++)
         {
            fapi_viscale_set_clut_acbycr(i, 
                  scaleParamsPtr->colourLut[i]);
         }
         //21c5df98
      }
      //21c5e3bc
      else if (scaleParamsPtr->osdLayout == 
         FAPI_VISCALE_OSD_LAYOUT_CbYCrA) //4)
      {
         //21c5e3c4
         for (i = 0; i < 256; i++)
         {
            fapi_viscale_set_clut_cbycra(i, 
                  scaleParamsPtr->colourLut[i]);
         }
         //->21c5df98
      }
      else
      {
         //->21c5dd9c
         return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
      }
      break;
      
   default:
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5df98
   h->scalerParams.layerEnable = scaleParamsPtr->layerEnable;
   h->scalerParams.useGlobalAlpha = scaleParamsPtr->useGlobalAlpha;
   h->scalerParams.hilightOnOff = scaleParamsPtr->hilightOnOff;
   h->scalerParams.cpTileNumX = 0;
   h->scalerParams.cpTileNumY = 0;
   h->scalerParams.inputWindowX0 = 0;
   h->scalerParams.inputWindowY0 = 0;
   //21c5dfc4
   for (i = 0; i < 256; i++)
   {
      h->scalerParams.colourLut[i] = 
         scaleParamsPtr->colourLut[i];
   }
   //21c5dfec
   if (scaleParamsPtr->globalAlpha > 255)
   {
      h->scalerParams.globalAlpha = 255;
   }
   else
   {
      h->scalerParams.globalAlpha = 
         scaleParamsPtr->globalAlpha;
   }
   //21c5e004
   if (scaleParamsPtr->inputPicWidth == 0)
   {
      //->21c5e534
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;
      h->scalerParams.inputPicWidth = 0;
      h->scalerParams.inputPicHeight = 0;
      h->scalerParams.inputWindowWidth = 0;
      h->scalerParams.inputWindowHeight = 0;
      h->scalerParams.outputWindowWidth = 0;
      h->scalerParams.outputWindowHeight = 0;
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5e00c
   if (scaleParamsPtr->inputPicHeight == 0)
   {
      //->21c5e50c
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;
      h->scalerParams.inputPicWidth = 0;
      h->scalerParams.inputPicHeight = 0;
      h->scalerParams.inputWindowWidth = 0;
      h->scalerParams.inputWindowHeight = 0;
      h->scalerParams.outputWindowWidth = 0;
      h->scalerParams.outputWindowHeight = 0;
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5e018
   if (scaleParamsPtr->inputWindowWidth == 0)
   {
      //->21c5e4e4
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;
      h->scalerParams.inputPicWidth = 0;
      h->scalerParams.inputPicHeight = 0;
      h->scalerParams.inputWindowWidth = 0;
      h->scalerParams.inputWindowHeight = 0;
      h->scalerParams.outputWindowWidth = 0;
      h->scalerParams.outputWindowHeight = 0;
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5e024
   if (scaleParamsPtr->inputWindowHeight == 0)
   {
      //->21c5e4bc
      h->scalerParams.cpTileNumX = 0;
      h->scalerParams.cpTileNumY = 0;
      h->scalerParams.inputPicWidth = 0;
      h->scalerParams.inputPicHeight = 0;
      h->scalerParams.inputWindowWidth = 0;
      h->scalerParams.inputWindowHeight = 0;
      h->scalerParams.outputWindowWidth = 0;
      h->scalerParams.outputWindowHeight = 0;
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5e030
   h->scalerParams.cpTileNumX = 0;
   h->scalerParams.cpTileNumY = 0;
   h->scalerParams.inputPicWidth = scaleParamsPtr->inputPicWidth;
   h->scalerParams.inputPicHeight = scaleParamsPtr->inputPicHeight;
   h->scalerParams.frameField = scaleParamsPtr->frameField;
   
   if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I)
   {
      //->21c5e498
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I)
   {
      //->21c5e498
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I)
   {
      //->21c5e498
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50I)
   {
      //->21c5e498
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I)
   {
      //->21c5e498
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB)
   {
      //->21c5e4a8
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else
   {
      //21c5e100
      h->scalerParams.diMode = 0;
   }
   //21c5e10c
   if (scaleParamsPtr->inputWindowWidth > 
         scaleParamsPtr->inputPicWidth)
   {
      //21c5e114
      h->scalerParams.inputWindowWidth = 
         scaleParamsPtr->inputPicWidth;
      //->21c5e14c
   }
   else
   {
      //21c5e120
      sl = scaleParamsPtr->inputPicWidth / h->pixPerBurst;
      if (sl)
      {
         sl--;
      }
      
      if ((((sl * 128) + 8) / r7) > scaleParamsPtr->inputWindowWidth)
      {
         h->scalerParams.inputWindowWidth = 
            ((sl * 128) + 8) / r7;
      }
      else
      {
         h->scalerParams.inputWindowWidth =
            scaleParamsPtr->inputWindowWidth;
      }
   }
   //21c5e14c
   if (scaleParamsPtr->inputWindowHeight > 
         scaleParamsPtr->inputPicHeight)
   {
      //21c5e158
      if (scaleParamsPtr->frameField == 0)
      {
         //21c5e15c
         h->scalerParams.inputWindowHeight = 
            scaleParamsPtr->inputPicHeight / 2;
         //->21c5e16c
      }
      else
      {
         //21c5e168
         h->scalerParams.inputWindowHeight =
            scaleParamsPtr->inputPicHeight;
         //->21c5e16c
      }
   }
   else
   {
      //->21c5e46c
      if (scaleParamsPtr->frameField == 0)
      {
         //21c5e478
         h->scalerParams.inputWindowHeight = 
            scaleParamsPtr->inputWindowHeight / 2;
         //->21c5e16c
      }
      else
      {
         //21c5e470
         h->scalerParams.inputWindowHeight =
            scaleParamsPtr->inputWindowHeight;
         //->21c5e16c
      }
   }
   //21c5e16c
   res = func_21c5d108(h, &sp);
   if (res != 0)
   {
      return res;
   }
   
   h->scalerParams.outputWindowX0 = sp.startX0 +    
      scaleParamsPtr->outputWindowX0;
   h->scalerParams.outputWindowY0 = sp.startY0 +  
      scaleParamsPtr->outputWindowY0;
   
   if (sp.horSize < h->scalerParams.inputWindowWidth)
   {
      h->scalerParams.outputWindowWidth = sp.horSize;
   }
   else
   {
      h->scalerParams.outputWindowWidth = 
         h->scalerParams.inputWindowWidth;
   }

   if (h->scalerParams.inputWindowHeight > sp.verSize)
   {
      h->scalerParams.outputWindowHeight = sp.verSize;
   }
   else
   {
      h->scalerParams.outputWindowHeight = 
         h->scalerParams.inputWindowHeight;
   }
   
   h->isrDataPtr->iFilter.hStartPos = 0;
   h->isrDataPtr->iFilter.hSize = sl;
   h->isrDataPtr->iFilter.initalShift = 4;
   h->isrDataPtr->iFilter.horDispPixel = 
      h->scalerParams.outputWindowWidth;
   h->isrDataPtr->iFilter.horReadPixel = 
      h->scalerParams.inputWindowWidth;

   h->isrDataPtr->iFilter.horD = 0x10000;
   h->isrDataPtr->iFilter.horN = 0x10000;
   h->isrDataPtr->iFilter.horFilterOn = 0;
   h->isrDataPtr->iFilter.horFilterUp = 0;
   
   h->isrDataPtr->iFilter.verD = 0x10000;
   h->isrDataPtr->iFilter.verN = 0x10000;
   h->isrDataPtr->iFilter.verFilterOn = 0;
   h->isrDataPtr->iFilter.verFilterUp = 0;
   
   h->isrDataPtr->iFilter.horStart = 
      h->scalerParams.outputWindowX0;
   h->isrDataPtr->iFilter.horStop =
      h->scalerParams.outputWindowX0 +
      h->scalerParams.outputWindowWidth;
   h->isrDataPtr->iFilter.verStart = 
      h->scalerParams.outputWindowY0;
   h->isrDataPtr->iFilter.verStop = 
      h->scalerParams.outputWindowY0 +
      h->scalerParams.outputWindowHeight;
   
   FREG_VO_SetOsdmode_AlphaSource(0, 
         h->scalerParams.useGlobalAlpha);
   FREG_VO_SetOsdalpha1_Osdalpha1(0,
         h->scalerParams.globalAlpha);
   FREG_VO_SetOsdhsize_Hsize(0, 
         h->isrDataPtr->iFilter.hSize);
   FREG_VO_SetOsdinitialshift_Initialshift(0, 
         h->isrDataPtr->iFilter.initalShift);
   FREG_VO_SetOsdhordisppixel_Hordisppixel(0,
         h->isrDataPtr->iFilter.horDispPixel);
   FREG_VO_SetOsdhorreadpixel_Horreadpixel(0,
         h->isrDataPtr->iFilter.horReadPixel);
   FREG_VO_SetOsdbitperpixel_Bitperpixel(0,
         h->bitsPerPix);
   FREG_VO_SetOsdhordenum_Hordenum(0, 
         h->isrDataPtr->iFilter.horD);
   FREG_VO_SetOsdhornum_Hornum(0, 
         h->isrDataPtr->iFilter.horN);
   FREG_VO_SetOsdfiltermode_Horfilteron(0, 
         h->isrDataPtr->iFilter.horFilterOn);
   FREG_VO_SetOsdfiltermode_Horfilterup(0,
         h->isrDataPtr->iFilter.horFilterUp);
   FREG_VO_SetOsdverdenum_Verdenum(0, 
         h->isrDataPtr->iFilter.verD);
   FREG_VO_SetOsdvernum_Vernum(0, 
         h->isrDataPtr->iFilter.verN);
   FREG_VO_SetOsdfiltermode_Verfilteron(0, 
         h->isrDataPtr->iFilter.verFilterOn);
   FREG_VO_SetOsdfiltermode_Verfilterup(0, 
         h->isrDataPtr->iFilter.verFilterUp);
   FREG_VO_SetDisposd1horstartstop_Osd1horstart( 
         h->isrDataPtr->iFilter.horStart);
   FREG_VO_SetDisposd1horstartstop_Osd1horstop( 
         h->isrDataPtr->iFilter.horStop);
   FREG_VO_SetDisposd1verstartstop_Osd1verstart( 
         h->isrDataPtr->iFilter.verStart);
   FREG_VO_SetDisposd1verstartstop_Osd1verstop( 
         h->isrDataPtr->iFilter.verStop);
   FREG_VO_SetOsdmode_Osdmode(0, 
         h->scalerParams.osdMode);
   FREG_VO_SetOsdglobaloffset(0, 
         h->scalerParams.picBase);
   FREG_VO_SetOsdmode_Osdfieldmode(0, 
         h->scalerParams.frameField);
   
   h->isrDataPtr->iFilterState = 
      FAPI_VISCALE_FILTERS_UPDATED;
   
   if (h->scalerParams.layerEnable == 1)
   {
      //->21c5e480
      h->isrDataPtr->iEnableState = 
         FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE;
      
      res = waitEnableDisable(h);
   }
   else if (h->scalerParams.layerEnable == 0)
   {
      //21c5e390
      h->isrDataPtr->iEnableState = 
         FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE;
      
      res = waitEnableDisable(h);
   }
   else
   {
      res = 0;
   }
   //21c5dd84
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1start: res=%d\n", res);
   
   return res;
}


/* 21c5dbcc - complete */
int32_t fapi_viscale_osd1stop(FAPI_SYS_HandleT handle)
{
   int32_t res;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1stop\n");

   res = fapi_viscale_osd1enabledisable(h, FAPI_VISCALE_PARAMETER_OFF);
   
   fapi_viscale_osd1alpha(h, FAPI_VISCALE_PARAMETER_OFF, 0);
   fapi_viscale_osd1alpha(h, FAPI_VISCALE_PARAMETER_SET, 0);
   
   h->scalerParams.osdMode = FAPI_VISCALE_UNKNOWN_OSD_MODE;
   h->scalerParams.frameField = 0;
   h->scalerParams.picBase = 0;
   h->scalerParams.cpTileNumX = 0;
   h->scalerParams.cpTileNumY = 0;
   h->scalerParams.inputPicWidth = 0;
   h->scalerParams.inputPicHeight = 0;
   h->scalerParams.inputWindowX0 = 0;
   h->scalerParams.inputWindowY0 = 0;
   h->scalerParams.inputWindowWidth = 0;
   h->scalerParams.inputWindowHeight = 0;
   h->scalerParams.outputWindowX0 = 0;
   h->scalerParams.outputWindowY0 = 0;
   h->scalerParams.outputWindowWidth = 0;
   h->scalerParams.outputWindowHeight = 0;
   
   h->isrDataPtr->iFilter.initalShift = 4;
   h->isrDataPtr->iFilter.hStartPos = 0;
   h->isrDataPtr->iFilter.hSize = 0;
   h->isrDataPtr->iFilter.horDispPixel = 0;
   h->isrDataPtr->iFilter.horReadPixel = 0;
   h->isrDataPtr->iFilter.horFilterOn = 0;
   h->isrDataPtr->iFilter.verFilterOn = 0;
   h->isrDataPtr->iFilter.horStart = 0;
   h->isrDataPtr->iFilter.horStop = 0;
   h->isrDataPtr->iFilter.verStart = 0;
   h->isrDataPtr->iFilter.verStop = 0;

   FREG_VO_SetOsdinitialshift_Initialshift(0, 4);
   FREG_VO_SetOsdhsize_Hsize(0, 0);
   FREG_VO_SetOsdhordisppixel_Hordisppixel(0, 0);
   FREG_VO_SetOsdhorreadpixel_Horreadpixel(0, 0);
   FREG_VO_SetOsdbitperpixel_Bitperpixel(0, 0);
   FREG_VO_SetOsdfiltermode_Horfilteron(0, 0);
   FREG_VO_SetOsdfiltermode_Verfilteron(0, 0);
   FREG_VO_SetDisposd1horstartstop_Osd1horstart(0);
   FREG_VO_SetDisposd1horstartstop_Osd1horstop(0);
   FREG_VO_SetDisposd1verstartstop_Osd1verstart(0);
   FREG_VO_SetDisposd1verstartstop_Osd1verstop(0);
   FREG_VO_SetOsdmode_YSelect(0, 0);
   FREG_VO_SetOsdmode_CrSelect(0, 0);
   FREG_VO_SetOsdmode_CbSelect(0, 0);
   FREG_VO_SetOsdmode_AlphaSelect(0, 0);
   FREG_VO_SetOsdmode_RgbEnable(0, 0);
   FREG_VO_SetOsdmode_AlphaSource(0, 1);
   FREG_VO_SetOsdmode_Osdmode(0, 0);
   FREG_VO_SetOsdalpha1_Osdalpha1(0, 0);
   FREG_VO_SetOsdglobaloffset(0, 0);
   
   h->isrDataPtr->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1stop: res=%d\n", res);

   return res;
}


/* 21c5d600 - complete */
int32_t fapi_viscale_osd1enabledisable(FAPI_SYS_HandleT handle,
                          FAPI_VISCALE_ParameterModeEnumT mode)
{
   int32_t res;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1enabledisable: mode=%d\n",
         mode);

   switch (mode)
   {
   case FAPI_VISCALE_PARAMETER_ON:
      h->isrDataPtr->iEnableState = FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE;
      
      res = waitEnableDisable(h);
      
      if (res == FAPI_OK)
      {
         h->scalerParams.layerEnable = 1;
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_OFF:
      h->isrDataPtr->iEnableState = FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE;
      
      res = waitEnableDisable(h);
      
      if (res == FAPI_OK)
      {
         h->scalerParams.layerEnable = 0;
      }
      break;
      
   default:
      res = FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY;
      break;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1enabledisable: res=%d\n", res);

   return res;
}


/* 21c5dabc - complete */
uint32_t fapi_viscale_osd1alpha(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ParameterModeEnumT mode,
                                uint32_t level)
{
   int alpha;
   uint32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* r4 = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1alpha: mode=%d, level=%d\n",
         mode, level);

   switch (mode)
   {
   case FAPI_VISCALE_PARAMETER_GET:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         r4->scalerParams.globalAlpha = 
            FREG_VO_GetOsdalpha1_Osdalpha1(0);
         res = r4->scalerParams.globalAlpha;
      }
      break;      

   case FAPI_VISCALE_PARAMETER_SET:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         r4->scalerParams.globalAlpha = level = 
            (level < 255)? level: 255;
         FREG_VO_SetOsdalpha1_Osdalpha1(0, r4->scalerParams.globalAlpha);
         res = level; 
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_INCREASE:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         alpha = r4->scalerParams.globalAlpha + level;
         if (alpha >= 255) alpha = 255;
         r4->scalerParams.globalAlpha = alpha;
         FREG_VO_SetOsdalpha1_Osdalpha1(0, r4->scalerParams.globalAlpha);
         res = r4->scalerParams.globalAlpha;
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_DECREASE:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         alpha = r4->scalerParams.globalAlpha - level;
         if (alpha < 0) alpha = 0;
         r4->scalerParams.globalAlpha = alpha;
         FREG_VO_SetOsdalpha1_Osdalpha1(0, r4->scalerParams.globalAlpha);
         res = r4->scalerParams.globalAlpha;
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_ON:
      r4->scalerParams.useGlobalAlpha = 1;
      FREG_VO_SetOsdmode_AlphaSource(0, 1);
      break;
      
   case FAPI_VISCALE_PARAMETER_OFF:
      r4->scalerParams.useGlobalAlpha = 0;
      FREG_VO_SetOsdmode_AlphaSource(0, 0);
      break;      
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1alpha: res=%d\n", res);

   return res;   
}


/* 21c5d65c - todo */
int32_t fapi_viscale_osd1resize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_osd1resize\n");
   return 0;
}


/* 21c5d4e8 - complete */
int32_t fapi_viscale_osd1autoplanefading(FAPI_SYS_HandleT handle,
            FAPI_VISCALE_VideoFadingModeEnumT fadingMode)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1autoplanefading: fadingMode=%d\n",
         fadingMode);
   
   if (h->scalerParams.useGlobalAlpha == 1)
   {
      if (fadingMode == FAPI_VISCALE_VIDEO_FADE_IN)
      {
         h->isrDataPtr->iFadeState = FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN;
         h->isrDataPtr->iFadeCurrValue = 0;
         h->isrDataPtr->iFadeLimitValue = h->scalerParams.globalAlpha;
         
         FREG_VO_SetOsdalpha1_Osdalpha1(0, h->isrDataPtr->iFadeCurrValue);
      }
      else if (fadingMode == FAPI_VISCALE_VIDEO_FADE_OUT)
      {
         h->isrDataPtr->iFadeState = FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT;
         h->isrDataPtr->iFadeCurrValue = h->scalerParams.globalAlpha;
         h->isrDataPtr->iFadeLimitValue = 0;
         
         FREG_VO_SetOsdalpha1_Osdalpha1(0, h->isrDataPtr->iFadeCurrValue);
      }
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1autoplanefading: res=%d\n", res);

   return res;
}


/* 21c5ce64 - complete */
int32_t fapi_viscale_osd1autoplanefadingstepsize(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                    uint32_t* stepSizePtr)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1autoplanefadingstepsize: mode=%d\n",
         mode);
   
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

   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1autoplanefadingstepsize: res=%d\n", res);

   return res;
}


/* 21c5d3b8 - todo */
int32_t fapi_viscale_osd1updateclut(FAPI_SYS_HandleT handle, 
                                    uint32_t* colour)
{
   int32_t res = FAPI_OK;
   uint32_t i = 0;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1updateclut\n");

   if ((h->scalerParams.osdMode == FAPI_VISCALE_OSD_MODE_CLUT_4BIT) ||
         (h->scalerParams.osdMode == FAPI_VISCALE_OSD_MODE_CLUT_8BIT))
   {
      if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_ARGB)
      {
         //21c5d468
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            fapi_viscale_set_clut_argb(i, colour[i]);
         }
      }
      else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_RGBA)
      {
         //21c5d430
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            fapi_viscale_set_clut_rgba(i, colour[i]);
         }
      }
      else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_ACbYCr)
      {
         //21c5d3f4      
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            fapi_viscale_set_clut_acbycr(i, colour[i]);
         }
      }
      else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_CbYCrA)
      {
         //21c5d4ac
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            fapi_viscale_set_clut_cbycra(i, colour[i]);
         }
      }
      else
      {
         //21c5d3d0
         res = FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS;
      }
   }
   else
   {
      res = FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1updateclut: res=%d\n", res);

   return res;
}


/* 21c5d308 - todo */
int32_t fapi_viscale_osd1updatesingleclut(FAPI_SYS_HandleT handle, 
      uint32_t entryNumber, uint32_t entryColour)
{   
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   int32_t res = FAPI_OK;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd1updatesingleclut: entryNumber=%d, entryColour=%d\n",
         entryNumber, entryColour);

   if (entryNumber < 256)
   {
      if ((h->scalerParams.osdMode == FAPI_VISCALE_OSD_MODE_CLUT_4BIT) ||
            (h->scalerParams.osdMode == FAPI_VISCALE_OSD_MODE_CLUT_8BIT))
      {
         h->scalerParams.colourLut[entryNumber] = entryColour;
         
         if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_ARGB)
         {
            fapi_viscale_set_clut_argb(entryNumber, entryColour);
         }
         else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_RGBA)
         {
            fapi_viscale_set_clut_rgba(entryNumber, entryColour);
         }
         else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_ACbYCr)
         {
            fapi_viscale_set_clut_acbycr(entryNumber, entryColour);
         }
         else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_CbYCrA)
         {
            fapi_viscale_set_clut_cbycra(entryNumber, entryColour);
         }
         else
         {
            res = FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS;
         }
      }
      else
      {
         res = FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS;
      }
   }
   else
   {
      res = FAPI_VISCALE_ERR_EXCEEDED_MAX_VALUE;
   }
      
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd1updatesingleclut: res=%d\n", res);

   return res;
}


/* 21c5ceb4 - complete */
int32_t fapi_viscale_setosd1scalertohdencoder(FAPI_SYS_HandleT handle,
                    FAPI_SYS_HandleT viencHdHandle)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   FAPI_VIENC_VideoEncoderHandleT* r1 = viencHdHandle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_setosd1scalertohdencoder\n");

   if (r1 == 0)
   {
      h->hdMode = FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE;
      h->sdMode = FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE;
      
      return FAPI_OK;
   }
   
   switch (r1->opParams.interlaceProgressive)
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
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setosd1scalertohdencoder: res=%d\n", res);

   return res;
}


FAPI_VISCALE_ActiveRegionDataT Data_21efcb24[23] = //21efcb24
{
      //FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE
      {0x00000000, 
       0x00000000, 
       0x00000000, 
       0x00000000, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P
      {0x000000c0, 
       0x00000029, 
       0x00000780, 
       0x00000438, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P
      {0x000000c0, 
       0x00000029, 
       0x00000780, 
       0x00000438, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P
      {0x000000c0, 
       0x00000029, 
       0x00000780, 
       0x00000438, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P
      {0x000000c0, 
       0x00000029, 
       0x00000780, 
       0x00000438, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P
      {0x000000c0, 
       0x00000029, 
       0x00000780, 
       0x00000438, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I
      {0x000000c0, 
       0x00000014, 
       0x00000780, 
       0x0000021c, 
       0x00000002, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I
      {0x000000c0, 
       0x00000014, 
       0x00000780, 
       0x0000021c, 
       0x00000002, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I
      {0x000000c0, 
       0x00000014, 
       0x00000780, 
       0x0000021c, 
       0x00000002, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001,
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P
      {0x00000104, 
       0x00000019, 
       0x00000500, 
       0x000002d0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x576x50I
      {0x00000108, 
       0x00000016, 
       0x000005a0, 
       0x00000120, 
       0x00000002, 
       0x00000002, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x576x50P
      {0x00000084, 
       0x0000002c, 
       0x000002d0, 
       0x00000240, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I
      {0x000000ee, 
       0x00000012, 
       0x000005a0, 
       0x000000f0, 
       0x00000002, 
       0x00000002, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P
      {0x0000007a, 
       0x00000024, 
       0x000002d0, 
       0x000001e0, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
       //FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01
      {0x00000064, 
       0x00000014, 
       0x00000280, 
       0x000001e0, 
       0x00000001, 
       0x00000001, 
       0x00000000},
       //FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB
      {0x00000064, 
       0x00000014, 
       0x00000400, 
       0x00000300, 
       0x00000001, 
       0x00000001, 
       0x00000000}, 
};


/* 21c5d108 - complete */
int32_t func_21c5d108(FAPI_VISCALE_VideoScalerHandleT* a, 
      FAPI_VISCALE_ActiveRegionDataT* b)
{   
   FAPI_VISCALE_ActiveRegionDataT* r1 = 0;
   int32_t res = 0;
   
   if (a->hdMode != FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      r1 = &Data_21efcb24[a->hdMode];
   }

   if (r1 != NULL)
   {      
      b->startX0 = r1->startX0;
      b->startY0 = r1->startY0;
      b->horSize = r1->horSize;
      b->verSize = r1->verSize;
   }
   else
   {
      b->startX0 = 0;
      b->startY0 = 0;
      b->horSize = 0;
      b->verSize = 0;
      b->sdHorWriteStart = 0;
      b->sdHorWriteStop = 0;
      b->sdDispcvbshorstartstop = 0;      
      
      res = FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }
   
   return res;   
}


/* 21c5d1f0 - complete */
void fapi_viscale_set_clut_acbycr(uint32_t index, uint32_t colour)
{   
   unsigned a, cb, y, cr;
   
   a = (colour & 0xff000000) >> 24;
   cb = (colour & 0xff0000) >> 16;
   cb = CLIP(235, 16, cb);
   y = (colour & 0xff00) >> 8;
   y = CLIP(240, 16, y);
   cr = (colour & 0xff);
   cr = CLIP(235, 16, cr);
   
   FREG_VE_SetVoOsd1clut(index,
         (cb << 24) | (y << 16) | (cr << 8) | (a << 0));
}


/* 21c5d190 - complete */
void fapi_viscale_set_clut_cbycra(uint32_t index, uint32_t colour)
{
   unsigned cb, cr, y, a;
   
   cb = (colour & 0xff000000) >> 24;
   cb = CLIP(235, 16, cb);
   y = (colour & 0xff0000) >> 16;
   y = CLIP(240, 16, y);
   cr = (colour & 0xff00) >> 8;
   cr = CLIP(235, 16, cr);
   a = (colour & 0xff);
   
   FREG_VE_SetVoOsd1clut(index,
         (cb << 24) | (y << 16) | (cr << 8) | (a << 0));
}


/* 21c5d24c - complete */
void fapi_viscale_set_clut_rgba(uint32_t index, uint32_t colour)
{
   unsigned r, g, b, a;

   r = (colour & 0xff000000) >> 24;
   r = CLIP(240, 16, r);
   g = (colour & 0xff0000) >> 16;
   g = CLIP(240, 16, g);
   b = (colour & 0xff00) >> 8;
   b = CLIP(240, 16, b);
   a = colour & 0xff;
   
   FREG_VE_SetVoOsd1clut(index,
         (r << 24) | (g << 16) | (b << 8) | (a << 0));
}


/* 21c5d2ac - complete */
void fapi_viscale_set_clut_argb(uint32_t index, uint32_t colour)
{   
   unsigned r, g, b, a;

   a = (colour & 0xff000000) >> 24;
   r = (colour & 0x00ff0000) >> 16;
   r = CLIP(240, 16, r);
   g = (colour & 0x0000ff00) >> 8;
   g = CLIP(240, 16, g);
   b = colour & 0xff;
   b = CLIP(240, 16, b);
   
   FREG_VE_SetVoOsd1clut(index,
         (r << 24) | (g << 16) | (b << 8) | (a << 0));
}


/* 21c5d55c - complete */
int32_t waitEnableDisable(FAPI_VISCALE_VideoScalerHandleT* a)
{
   uint64_t t1 = FAPI_TIMER_GetTimeStamp(1000);
   
   while (1)
   {
      uint64_t t2 = FAPI_TIMER_GetTimeStamp(1000) - t1;
            
      if (a->isrDataPtr->iEnableState == FAPI_VISCALE_FORCE_ENABLED)
      {
         return FAPI_OK;
      }
      
      if (a->isrDataPtr->iEnableState == FAPI_VISCALE_FORCE_DISABLED)
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


