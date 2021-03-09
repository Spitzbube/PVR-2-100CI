
#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>


static int32_t func_21c5eacc(FAPI_VISCALE_VideoScalerHandleT* a,
      FAPI_VISCALE_ActiveRegionDataT* b);
static int32_t waitEnableDisable(FAPI_VISCALE_VideoScalerHandleT* a);
static int32_t waitFiltersUpdated(FAPI_VISCALE_VideoScalerHandleT* a);


/*static*/ void setClutARGB(uint32_t index, uint32_t colour);
/*static*/ void setClutRGBA(uint32_t index, uint32_t colour);
/*static*/ void setClutACbYCr(uint32_t index, uint32_t colour);
/*static*/ void setClutCbYCrA(uint32_t index, uint32_t colour);



/* 21c5f724 - complete */
int32_t fapi_viscale_osd2start(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd2start\n");
   
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
      //21c5f7cc
      switch (scaleParamsPtr->osdLayout)
      {
      case FAPI_VISCALE_OSD_LAYOUT_ARGB:
         //21c5fff0
         FREG_VO_SetOsdrgbyuv11(1, 0x81);
         FREG_VO_SetOsdrgbyuv12(1, 0x42);
         FREG_VO_SetOsdrgbyuv13(1, 0x19);
         FREG_VO_SetOsdrgbyuv14(1, 0x10);
         FREG_VO_SetOsdrgbyuv21(1, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(1, 0x1da);
         FREG_VO_SetOsdrgbyuv23(1, 0x70);
         FREG_VO_SetOsdrgbyuv24(1, 0x80);
         FREG_VO_SetOsdrgbyuv31(1, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(1, 0x70);
         FREG_VO_SetOsdrgbyuv33(1, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(1, 0x80);
         FREG_VO_SetOsdmode_CbSelect(1, 3);
         FREG_VO_SetOsdmode_YSelect(1, 3);
         FREG_VO_SetOsdmode_CrSelect(1, 3);
         FREG_VO_SetOsdmode_AlphaSelect(1, 3);
         FREG_VO_SetOsdmode_RgbEnable(1, 1);
         //->21c5f850
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_RGBA:
         //21c5ff20
         FREG_VO_SetOsdrgbyuv11(1, 0x81);
         FREG_VO_SetOsdrgbyuv12(1, 0x42);
         FREG_VO_SetOsdrgbyuv13(1, 0x19);
         FREG_VO_SetOsdrgbyuv14(1, 0x10);
         FREG_VO_SetOsdrgbyuv21(1, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(1, 0x1da);
         FREG_VO_SetOsdrgbyuv23(1, 0x70);
         FREG_VO_SetOsdrgbyuv24(1, 0x80);
         FREG_VO_SetOsdrgbyuv31(1, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(1, 0x70);
         FREG_VO_SetOsdrgbyuv33(1, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(1, 0x80);
         FREG_VO_SetOsdmode_CbSelect(1, 0);
         FREG_VO_SetOsdmode_YSelect(1, 0);
         FREG_VO_SetOsdmode_CrSelect(1, 0);
         FREG_VO_SetOsdmode_AlphaSelect(1, 0);
         FREG_VO_SetOsdmode_RgbEnable(1, 1);
         //->21c5f850
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_ACbYCr:
         //21c5f890
         FREG_VO_SetOsdmode_CbSelect(1, 3);
         FREG_VO_SetOsdmode_YSelect(1, 3);
         FREG_VO_SetOsdmode_CrSelect(1, 3);
         FREG_VO_SetOsdmode_AlphaSelect(1, 3);
         FREG_VO_SetOsdmode_RgbEnable(1, 0);
         //->21c5f850
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_CbYCrA:
         //21c5f814
         FREG_VO_SetOsdmode_CbSelect(1, 0);
         FREG_VO_SetOsdmode_YSelect(1, 0);
         FREG_VO_SetOsdmode_CrSelect(1, 0);
         FREG_VO_SetOsdmode_AlphaSelect(1, 0);
         FREG_VO_SetOsdmode_RgbEnable(1, 0);
         //21c5f850
         break;
         
      default:
         //->21c5f75c
         return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
      }
   }
   else
   {
      //21c5f7f0
      switch (scaleParamsPtr->osdLayout)
      {
      case FAPI_VISCALE_OSD_LAYOUT_ARGB:
         //21c60100
         FREG_VO_SetOsdrgbyuv11(1, 0x81);
         FREG_VO_SetOsdrgbyuv12(1, 0x42);
         FREG_VO_SetOsdrgbyuv13(1, 0x19);
         FREG_VO_SetOsdrgbyuv14(1, 0x10);
         FREG_VO_SetOsdrgbyuv21(1, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(1, 0x1da);
         FREG_VO_SetOsdrgbyuv23(1, 0x70);
         FREG_VO_SetOsdrgbyuv24(1, 0x80);
         FREG_VO_SetOsdrgbyuv31(1, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(1, 0x70);
         FREG_VO_SetOsdrgbyuv33(1, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(1, 0x80);
         FREG_VO_SetOsdmode_CbSelect(1, 0);
         FREG_VO_SetOsdmode_YSelect(1, 0);
         FREG_VO_SetOsdmode_CrSelect(1, 0);
         FREG_VO_SetOsdmode_AlphaSelect(1, 1);
         FREG_VO_SetOsdmode_RgbEnable(1, 1);
         //->21c5f850
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_RGBA:
         //21c5ff20
         FREG_VO_SetOsdrgbyuv11(1, 0x81);
         FREG_VO_SetOsdrgbyuv12(1, 0x42);
         FREG_VO_SetOsdrgbyuv13(1, 0x19);
         FREG_VO_SetOsdrgbyuv14(1, 0x10);
         FREG_VO_SetOsdrgbyuv21(1, 0x1b6);
         FREG_VO_SetOsdrgbyuv22(1, 0x1da);
         FREG_VO_SetOsdrgbyuv23(1, 0x70);
         FREG_VO_SetOsdrgbyuv24(1, 0x80);
         FREG_VO_SetOsdrgbyuv31(1, 0x1a2);
         FREG_VO_SetOsdrgbyuv32(1, 0x70);
         FREG_VO_SetOsdrgbyuv33(1, 0x1ee);
         FREG_VO_SetOsdrgbyuv34(1, 0x80);
         FREG_VO_SetOsdmode_CbSelect(1, 0);
         FREG_VO_SetOsdmode_YSelect(1, 0);
         FREG_VO_SetOsdmode_CrSelect(1, 0);
         FREG_VO_SetOsdmode_AlphaSelect(1, 0);
         FREG_VO_SetOsdmode_RgbEnable(1, 1);
         //->21c5f850
         break;
        
      case FAPI_VISCALE_OSD_LAYOUT_ACbYCr:
         //21c600c0
         FREG_VO_SetOsdmode_CbSelect(1, 0);
         FREG_VO_SetOsdmode_YSelect(1, 0);
         FREG_VO_SetOsdmode_CrSelect(1, 0);
         FREG_VO_SetOsdmode_AlphaSelect(1, 1);
         FREG_VO_SetOsdmode_RgbEnable(1, 0);
         //->21c5f850
         break;
         
      case FAPI_VISCALE_OSD_LAYOUT_CbYCrA:
         //21c5f814
         FREG_VO_SetOsdmode_CbSelect(1, 0);
         FREG_VO_SetOsdmode_YSelect(1, 0);
         FREG_VO_SetOsdmode_CrSelect(1, 0);
         FREG_VO_SetOsdmode_AlphaSelect(1, 0);
         FREG_VO_SetOsdmode_RgbEnable(1, 0);
         //21c5f850
         break;
         
      default:
         //->21c5f75c
         return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
      }
   }
   //21c5f850   
   switch (scaleParamsPtr->osdMode)
   {
   case FAPI_VISCALE_OSD_MODE_32_24BIT:
      //21c5fe18
      h->pixPerBurst = 32;
      h->bitsPerPix = 8;
      r7 = 4;
      //->21c5f8f8
      break;
      
   case FAPI_VISCALE_OSD_MODE_5551:
   case FAPI_VISCALE_OSD_MODE_4444:
   case FAPI_VISCALE_OSD_MODE_16BIT:
      //21c5fe00
      h->pixPerBurst = 64;
      h->bitsPerPix = 4;
      r7 = 2;
      //->21c5f8f8
      break;
      
   case FAPI_VISCALE_OSD_MODE_CLUT_4BIT:
      //21c5fd68
      h->pixPerBurst = 256;
      h->bitsPerPix = 1;
      r7 = 1;
      //->21c5f8f8
      break;
      
   case FAPI_VISCALE_OSD_MODE_CLUT_8BIT:
      //21c5f8e4
      h->pixPerBurst = 128;
      h->bitsPerPix = 2;
      r7 = 1;
      //21c5f8f8
      break;
      
   default:
      //21c5f8d0
      h->pixPerBurst = -1;
      h->bitsPerPix = -1;
      //->21c5dd84
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5f8f8
   switch (scaleParamsPtr->osdMode)
   {
   case FAPI_VISCALE_OSD_MODE_32_24BIT:
   case FAPI_VISCALE_OSD_MODE_5551:
   case FAPI_VISCALE_OSD_MODE_4444:
   case FAPI_VISCALE_OSD_MODE_16BIT:
      //21c5f958
      break;
      
   case FAPI_VISCALE_OSD_MODE_CLUT_4BIT:
   case FAPI_VISCALE_OSD_MODE_CLUT_8BIT:
      //21c5df58
      if (scaleParamsPtr->osdLayout == FAPI_VISCALE_OSD_LAYOUT_ARGB)
      {
         //21c5fdd8
         for (i = 0; i < 256; i++)
         {
            setClutARGB(i, scaleParamsPtr->colourLut[i]);
         }
         //->21c5f958
      }
      else if (scaleParamsPtr->osdLayout == FAPI_VISCALE_OSD_LAYOUT_RGBA)
      {
         //21c5fdb0
         for (i = 0; i < 256; i++)
         {
            setClutRGBA(i, scaleParamsPtr->colourLut[i]);
         }
         //->21c5f958
      }
      else if (scaleParamsPtr->osdLayout == FAPI_VISCALE_OSD_LAYOUT_ACbYCr)
      {
         //21c5f934
         for (i = 0; i < 256; i++)
         {
            setClutACbYCr(i, scaleParamsPtr->colourLut[i]);
         }
         //21c5f958
      }
      //21c5fd80
      else if (scaleParamsPtr->osdLayout == FAPI_VISCALE_OSD_LAYOUT_CbYCrA)
      {
         //21c5fd88
         for (i = 0; i < 256; i++)
         {
            setClutCbYCrA(i, scaleParamsPtr->colourLut[i]);
         }
         //->21c5f958
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
   //21c5f958
   h->scalerParams.layerEnable = scaleParamsPtr->layerEnable;
   h->scalerParams.useGlobalAlpha = scaleParamsPtr->useGlobalAlpha;
   h->scalerParams.hilightOnOff = scaleParamsPtr->hilightOnOff;
   h->scalerParams.cpTileNumX = 0;
   h->scalerParams.cpTileNumY = 0;
   h->scalerParams.inputWindowX0 = 0;
   h->scalerParams.inputWindowY0 = 0;
   //21c5f984
   for (i = 0; i < 256; i++)
   {
      h->scalerParams.colourLut[i] = 
         scaleParamsPtr->colourLut[i];
   }
   //21c5f9ac
   if (scaleParamsPtr->globalAlpha > 255)
   {
      h->scalerParams.globalAlpha = 255;
   }
   else
   {
      h->scalerParams.globalAlpha = 
         scaleParamsPtr->globalAlpha;
   }
   //21c5f9c4
   if (scaleParamsPtr->inputPicWidth == 0)
   {
      //->21c5fef8
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
   //21c5f9cc
   if (scaleParamsPtr->inputPicHeight == 0)
   {
      //->21c5fed0
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
   //21c5f9d8
   if (scaleParamsPtr->inputWindowWidth == 0)
   {
      //->21c5fea8
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
   //21c5f9e4
   if (scaleParamsPtr->inputWindowHeight == 0)
   {
      //->21c5fe80
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
   //21c5f9f0
   h->scalerParams.cpTileNumX = 0;
   h->scalerParams.cpTileNumY = 0;
   h->scalerParams.inputPicWidth = scaleParamsPtr->inputPicWidth;
   h->scalerParams.inputPicHeight = scaleParamsPtr->inputPicHeight;
   h->scalerParams.frameField = scaleParamsPtr->frameField;
   
   if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I)
   {
      //->21c5fe5c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I)
   {
      //->21c5fe5c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I)
   {
      //->21c5fe5c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50I)
   {
      //->21c5fe5c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I)
   {
      //->21c5fe5c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB)
   {
      //->21c5fe6c
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else
   {
      //21c5fac0
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
   //21c5fb2c
   res = func_21c5eacc(h, &sp);
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
   
   FREG_VO_SetOsdmode_AlphaSource(1, 
         h->scalerParams.useGlobalAlpha);
   FREG_VO_SetOsdalpha1_Osdalpha1(1,
         h->scalerParams.globalAlpha);
   FREG_VO_SetOsdhsize_Hsize(1, 
         h->isrDataPtr->iFilter.hSize);
   FREG_VO_SetOsdinitialshift_Initialshift(1, 
         h->isrDataPtr->iFilter.initalShift);
   FREG_VO_SetOsdhordisppixel_Hordisppixel(1,
         h->isrDataPtr->iFilter.horDispPixel);
   FREG_VO_SetOsdhorreadpixel_Horreadpixel(1,
         h->isrDataPtr->iFilter.horReadPixel);
   FREG_VO_SetOsdbitperpixel_Bitperpixel(1,
         h->bitsPerPix);
   FREG_VO_SetOsdhordenum_Hordenum(1, 
         h->isrDataPtr->iFilter.horD);
   FREG_VO_SetOsdhornum_Hornum(1, 
         h->isrDataPtr->iFilter.horN);
   FREG_VO_SetOsdfiltermode_Horfilteron(1, 
         h->isrDataPtr->iFilter.horFilterOn);
   FREG_VO_SetOsdfiltermode_Horfilterup(1,
         h->isrDataPtr->iFilter.horFilterUp);
   FREG_VO_SetOsdverdenum_Verdenum(1, 
         h->isrDataPtr->iFilter.verD);
   FREG_VO_SetOsdvernum_Vernum(1, 
         h->isrDataPtr->iFilter.verN);
   FREG_VO_SetOsdfiltermode_Verfilteron(1, 
         h->isrDataPtr->iFilter.verFilterOn);
   FREG_VO_SetOsdfiltermode_Verfilterup(1, 
         h->isrDataPtr->iFilter.verFilterUp);
   FREG_VO_SetDisposd2horstartstop_Osd2horstart( 
         h->isrDataPtr->iFilter.horStart);
   FREG_VO_SetDisposd2horstartstop_Osd2horstop( 
         h->isrDataPtr->iFilter.horStop);
   FREG_VO_SetDisposd2verstartstop_Osd2verstart( 
         h->isrDataPtr->iFilter.verStart);
   FREG_VO_SetDisposd2verstartstop_Osd2verstop( 
         h->isrDataPtr->iFilter.verStop);
   FREG_VO_SetOsdmode_Osdmode(1, 
         h->scalerParams.osdMode);
   FREG_VO_SetOsdglobaloffset(1, 
         h->scalerParams.picBase);
   FREG_VO_SetOsdmode_Osdfieldmode(1, h->scalerParams.frameField);
   
   h->isrDataPtr->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
   
   if (h->scalerParams.layerEnable == 1)
   {
      //->21c5fe44
      h->isrDataPtr->iEnableState = 
         FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE;
      
      res = waitEnableDisable(h);
   }
   else if (h->scalerParams.layerEnable == 0)
   {
      //21c5fd54
      h->isrDataPtr->iEnableState = 
         FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE;
      
      res = waitEnableDisable(h);
   }
   else
   {
      res = 0;
   }
   //21c5dd84
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd2start: res=%d\n", res);
   
   return res;
}


/* 21c5f588 - complete */
int32_t fapi_viscale_osd2stop(FAPI_SYS_HandleT handle)
{
   int32_t res;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd2stop\n");

   res = fapi_viscale_osd2enabledisable(h, FAPI_VISCALE_PARAMETER_OFF);
   
   fapi_viscale_osd2alpha(h, FAPI_VISCALE_PARAMETER_OFF, 0);
   fapi_viscale_osd2alpha(h, FAPI_VISCALE_PARAMETER_SET, 0);
   
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

   FREG_VO_SetOsdinitialshift_Initialshift(1, 4);
   FREG_VO_SetOsdhsize_Hsize(1, 0);
   FREG_VO_SetOsdhordisppixel_Hordisppixel(1, 0);
   FREG_VO_SetOsdhorreadpixel_Horreadpixel(1, 0);
   FREG_VO_SetOsdbitperpixel_Bitperpixel(1, 0);
   FREG_VO_SetOsdfiltermode_Horfilteron(1, 0);
   FREG_VO_SetOsdfiltermode_Verfilteron(1, 0);
   FREG_VO_SetDisposd2horstartstop_Osd2horstart(0);
   FREG_VO_SetDisposd2horstartstop_Osd2horstop(0);
   FREG_VO_SetDisposd2verstartstop_Osd2verstart(0);
   FREG_VO_SetDisposd2verstartstop_Osd2verstop(0);
   FREG_VO_SetOsdmode_YSelect(1, 0);
   FREG_VO_SetOsdmode_CrSelect(1, 0);
   FREG_VO_SetOsdmode_CbSelect(1, 0);
   FREG_VO_SetOsdmode_AlphaSelect(1, 0);
   FREG_VO_SetOsdmode_RgbEnable(1, 0);
   FREG_VO_SetOsdmode_AlphaSource(1, 1);
   FREG_VO_SetOsdmode_Osdmode(1, 0);
   FREG_VO_SetOsdalpha1_Osdalpha1(1, 0);
   FREG_VO_SetOsdglobaloffset(1, 0);
   
   h->isrDataPtr->iFilterState = FAPI_VISCALE_FILTERS_UPDATED;
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd2stop: res=%d\n", res);

   return res;
}


/* 21c5efc8 - complete */
int32_t fapi_viscale_osd2enabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode)
{
   int32_t res;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd2enabledisable: mode=%d\n",
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
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd2enabledisable: res=%d\n", res);

   return res;
}


/* 21c5f484 - complete */
uint32_t fapi_viscale_osd2alpha(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ParameterModeEnumT mode,
                                uint32_t level)
{
   int alpha;
   uint32_t res = 0;
   FAPI_VISCALE_VideoScalerHandleT* r4 = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd2alpha: mode=%d, level=%d\n",
         mode, level);

   switch (mode)
   {
   case FAPI_VISCALE_PARAMETER_GET:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         r4->scalerParams.globalAlpha = 
            FREG_VO_GetOsdalpha1_Osdalpha1(1);
         res = r4->scalerParams.globalAlpha;
      }
      break;      

   case FAPI_VISCALE_PARAMETER_SET:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         r4->scalerParams.globalAlpha = level =
            (level < 255)? level: 255;
         FREG_VO_SetOsdalpha1_Osdalpha1(1, r4->scalerParams.globalAlpha);
         res = level;
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_INCREASE:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         alpha = r4->scalerParams.globalAlpha + level;
         if (alpha >= 255) alpha = 255;
         r4->scalerParams.globalAlpha = alpha;
         FREG_VO_SetOsdalpha1_Osdalpha1(1, r4->scalerParams.globalAlpha);
         res = r4->scalerParams.globalAlpha;
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_DECREASE:
      if (r4->scalerParams.useGlobalAlpha == 1)
      {
         alpha = r4->scalerParams.globalAlpha - level;
         if (alpha < 0) alpha = 0;
         r4->scalerParams.globalAlpha = alpha;
         FREG_VO_SetOsdalpha1_Osdalpha1(1, r4->scalerParams.globalAlpha);
         res = r4->scalerParams.globalAlpha;
      }
      break;
      
   case FAPI_VISCALE_PARAMETER_ON:
      r4->scalerParams.useGlobalAlpha = 1;
      FREG_VO_SetOsdmode_AlphaSource(1, 1);
      break;
      
   case FAPI_VISCALE_PARAMETER_OFF:
      r4->scalerParams.useGlobalAlpha = 0;
      FREG_VO_SetOsdmode_AlphaSource(1, 0);
      break;      
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd2alpha: res=%d\n", res);

   return res;   
}


static int32_t func_21938e54(FAPI_VISCALE_VideoScalerHandleT* h,
      FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_ActiveRegionDataT sp;
   uint32_t sl;
   uint32_t r9 = 0;

   if (h->hdMode == FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      //21c5f040
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }

   switch (h->scalerParams.osdMode)
   {
   case FAPI_VISCALE_OSD_MODE_32_24BIT:
      sl = 4;
      break;

   case FAPI_VISCALE_OSD_MODE_5551:
   case FAPI_VISCALE_OSD_MODE_4444:
   case FAPI_VISCALE_OSD_MODE_16BIT:
      sl = 2;
      break;

   case FAPI_VISCALE_OSD_MODE_CLUT_4BIT:
   case FAPI_VISCALE_OSD_MODE_CLUT_8BIT:
      sl = 1;
      break;

   default:
      //->21c5f040
      return FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS;
   }
   //21c5f088
   if (scaleParamsPtr->inputPicWidth == 0) //1076
   {
      //21c5f094
      h->scalerParams.inputPicWidth = 0; //1152
      h->scalerParams.inputPicHeight = 0; //1156
      h->scalerParams.inputWindowWidth = 0; //1168
      h->scalerParams.inputWindowHeight = 0; //1172
      h->scalerParams.outputWindowWidth = 0; //1184
      h->scalerParams.outputWindowHeight = 0; //1188
      //->21c5f040
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5f0b4
   if (scaleParamsPtr->inputPicHeight == 0) //1080
   {
      //21c5f0c0
      h->scalerParams.inputPicWidth = 0; //1152
      h->scalerParams.inputPicHeight = 0; //1156
      h->scalerParams.inputWindowWidth = 0; //1168
      h->scalerParams.inputWindowHeight = 0; //1172
      h->scalerParams.outputWindowWidth = 0; //1184
      h->scalerParams.outputWindowHeight = 0; //1188
      //->21c5f040
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5f0e0
   if (scaleParamsPtr->inputWindowWidth == 0) //1092
   {
      //21c5f0ec
      h->scalerParams.inputPicWidth = 0; //1152
      h->scalerParams.inputPicHeight = 0; //1156
      h->scalerParams.inputWindowWidth = 0; //1168
      h->scalerParams.inputWindowHeight = 0; //1172
      h->scalerParams.outputWindowWidth = 0; //1184
      h->scalerParams.outputWindowHeight = 0; //1188
      //->21c5f040
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5f10c
   if (scaleParamsPtr->inputWindowHeight == 0) //1096
   {
      //21c5f118
      h->scalerParams.inputPicWidth = 0; //1152
      h->scalerParams.inputPicHeight = 0; //1156
      h->scalerParams.inputWindowWidth = 0; //1168
      h->scalerParams.inputWindowHeight = 0; //1172
      h->scalerParams.outputWindowWidth = 0; //1184
      h->scalerParams.outputWindowHeight = 0; //1188
      //->21c5f040
      return FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS;
   }
   //21c5f138
   h->scalerParams.cpTileNumX = 0; //92
   h->scalerParams.cpTileNumY = 0; //96
   h->scalerParams.frameField = scaleParamsPtr->frameField; //104
   h->scalerParams.inputPicWidth = scaleParamsPtr->inputPicWidth; //1152
   h->scalerParams.inputPicHeight = scaleParamsPtr->inputPicHeight; //1156
   h->scalerParams.inputWindowX0 = 0; //1160
   h->scalerParams.inputWindowY0 = 0; //1164

   if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I)
   {
      //->21c5f464
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I)
   {
      //->21c5f464
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I)
   {
      //->21c5f464
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50I)
   {
      //->21c5f464
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x576x50P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I)
   {
      //->21c5f464
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else if (h->hdMode == FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB)
   {
      //->21c5f434
      h->scalerParams.diMode = scaleParamsPtr->frameField * 2 + 1;
   }
   else
   {
      h->scalerParams.diMode = 0; //1144
   }
   //21c5f218
   if (scaleParamsPtr->inputWindowWidth >
         scaleParamsPtr->inputPicWidth) //1076
   {
      h->scalerParams.inputWindowWidth = //1168
         scaleParamsPtr->inputPicWidth;
      //->21c5f258
   }
   else
   {
      //21c5f22c
      r9 = scaleParamsPtr->inputPicWidth / h->pixPerBurst;
      if (r9 != 0)
      {
         r9--;
      }

      if ((((r9 * 128) + 8) / sl) > scaleParamsPtr->inputWindowWidth)
      {
         h->scalerParams.inputWindowWidth = //1168
               ((r9 * 128) + 8) / sl;
      }
      else
      {
         h->scalerParams.inputWindowWidth = //1168
               scaleParamsPtr->inputWindowWidth;
      }
   }
   //21c5f258
   if (scaleParamsPtr->inputWindowHeight >
         scaleParamsPtr->inputPicHeight) //1080
   {
      //21c5f264
      if (scaleParamsPtr->frameField == 0) //r6
      {
         h->scalerParams.inputWindowHeight = //1172
            scaleParamsPtr->inputPicHeight / 2;
         //21c5f274
      }
      else
      {
         //->21c5f42c
         h->scalerParams.inputWindowHeight = //1172
            scaleParamsPtr->inputPicHeight;
         //->21c5f274
      }
   }
   else
   {
      //->21c5f41c
      if (scaleParamsPtr->frameField == 0) //r6
      {
         h->scalerParams.inputWindowHeight = //1172
               scaleParamsPtr->inputWindowHeight / 2;
         //21c5f274
      }
      else
      {
         //->21c5f42c
         h->scalerParams.inputWindowHeight = //1172
               scaleParamsPtr->inputWindowHeight;
         //->21c5f274
      }
   }
   //21c5f274
   res = func_21c5eacc(h, &sp);
   if (res != FAPI_OK)
   {
      return res;
   }

   h->scalerParams.outputWindowX0 = sp.startX0 +
      scaleParamsPtr->outputWindowX0;
   h->scalerParams.outputWindowY0 = sp.startY0 +
      scaleParamsPtr->outputWindowY0;

   if ((scaleParamsPtr->outputWindowWidth - 1) > -3)
   {
      h->scalerParams.outputWindowWidth = //1184
            scaleParamsPtr->inputWindowWidth; //1092
   }

   if ((scaleParamsPtr->outputWindowHeight - 1) > -3)
   {
      h->scalerParams.outputWindowHeight = //1188
            scaleParamsPtr->inputWindowHeight; //1096
   }

   if (sp.horSize < scaleParamsPtr->outputWindowWidth)
   {
      h->scalerParams.outputWindowWidth = sp.horSize;
   }
   else
   {
      h->scalerParams.outputWindowWidth =
            scaleParamsPtr->outputWindowWidth;
   }

   if (scaleParamsPtr->outputWindowHeight > sp.verSize)
   {
      h->scalerParams.outputWindowHeight = sp.verSize;
   }
   else
   {
      h->scalerParams.outputWindowHeight =
            scaleParamsPtr->outputWindowHeight;
   }

   h->isrDataPtr->iFilter.hSize = r9;
   h->isrDataPtr->iFilter.vStartPos = h->scalerParams.inputWindowY0;
   h->isrDataPtr->iFilter.hStartPos = h->scalerParams.inputWindowX0 / 128;
   h->isrDataPtr->iFilter.initalShift = 4;

   if (h->scalerParams.outputWindowWidth > sp.horSize)
   {
      //21c5f32c
      h->isrDataPtr->iFilter.horDispPixel = sp.horSize;
      h->isrDataPtr->iFilter.horReadPixel =
            ((h->isrDataPtr->iFilter.horN * h->isrDataPtr->iFilter.horDispPixel) >> 16) +
            (h->scalerParams.inputWindowX0 & 0x7F);
   }
   else
   {
      //->21c5f448
      h->isrDataPtr->iFilter.horDispPixel = h->scalerParams.outputWindowWidth;
      h->isrDataPtr->iFilter.horReadPixel =
            h->scalerParams.inputWindowWidth +
            (h->scalerParams.inputWindowX0 & 0x7F);
   }
   //21c5f348
   h->isrDataPtr->iFilter.horStart = h->scalerParams.outputWindowX0;
   h->isrDataPtr->iFilter.horStop =
         h->scalerParams.outputWindowX0 +
         h->isrDataPtr->iFilter.horDispPixel;
   h->isrDataPtr->iFilter.verStart = h->scalerParams.outputWindowY0;
   h->isrDataPtr->iFilter.verStop =
         h->scalerParams.outputWindowY0 +
         h->scalerParams.outputWindowHeight;

   FREG_VO_SetOsdhsize_Hsize(1, h->isrDataPtr->iFilter.hSize);

   HSCALE(h, 3, 1);
   VSCALE(h, 3);

   h->isrDataPtr->iFilterState = FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS;

   return res;
}


/* 21c5f024 - todo */
int32_t fapi_viscale_osd2resize(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   int32_t res = FAPI_OK;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd2resize\n");

   res = func_21938e54(handle, scaleParamsPtr);
   
   if (res == FAPI_OK)
   {
      res = waitFiltersUpdated(handle);
   }
      
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd2resize: res=%d\n", res);

   return res;
}


/* 21c5eeac - todo */
int32_t fapi_viscale_osd2autoplanefading(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_osd2autoplanefading\n");
   return 0;
}


/* 21c5e828 - todo */
int32_t fapi_viscale_osd2autoplanefadingstepsize(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_osd2autoplanefadingstepsize\n");
   return 0;
}


/* 21c5ed7c - todo */
int32_t fapi_viscale_osd2updateclut(FAPI_SYS_HandleT handle, 
                                    uint32_t* colour)
{
   int32_t res = FAPI_OK;
   uint32_t i = 0;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_osd2updateclut\n");

   if ((h->scalerParams.osdMode == FAPI_VISCALE_OSD_MODE_CLUT_4BIT) ||
         (h->scalerParams.osdMode == FAPI_VISCALE_OSD_MODE_CLUT_8BIT))
   {
      if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_ARGB)
      {
         //21c5ee2c
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            setClutARGB(i, colour[i]);
         }
      }
      else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_RGBA)
      {
         //21c5edf4
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            setClutRGBA(i, colour[i]);
         }
      }
      else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_ACbYCr)
      {
         //21c5edb8      
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            setClutACbYCr(i, colour[i]);
         }
      }
      else if (h->scalerParams.osdLayout == FAPI_VISCALE_OSD_LAYOUT_CbYCrA)
      {
         //21c5ee70
         for (i = 0; i < 256; i++)
         {
            h->scalerParams.colourLut[i] = colour[i];
            setClutCbYCrA(i, colour[i]);
         }
      }
      else
      {
         //21c5ed94
         res = FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS;
      }
   }
   else
   {
      res = FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_osd2updateclut: res=%d\n", res);

   return res;
}


/* 21c5eccc - todo */
int32_t fapi_viscale_osd2updatesingleclut
                          (FAPI_SYS_HandleT handle, uint32_t entryNumber,
                                                   uint32_t entryColour)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_osd2updatesingleclut\n");
   return 0;
}


/* 21c5e878 - complete */
int32_t fapi_viscale_setosd2scalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle)
{
//   FAPI_SYS_PRINT_MSG("fapi_viscale_setosd2scalertohdencoder\n");
   
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   FAPI_VIENC_VideoEncoderHandleT* r1 = viencHdHandle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_setosd2scalertohdencoder\n");

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
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setosd2scalertohdencoder: res=%d\n", res);

   return res;
}


/* 21c5ec70 - complete */
void setClutARGB(uint32_t index, uint32_t colour)
{   
   unsigned r, g, b, a;

   a = (colour & 0xff000000) >> 24;
   r = (colour & 0x00ff0000) >> 16;
   r = CLIP(240, 16, r);
   g = (colour & 0x0000ff00) >> 8;
   g = CLIP(240, 16, g);
   b = colour & 0xff;
   b = CLIP(240, 16, b);
   
   FREG_VE_SetVoOsd2clut(index,
         (r << 24) | (g << 16) | (b << 8) | (a << 0));
}


/* 21c5ec10 - complete */
void setClutRGBA(uint32_t index, uint32_t colour)
{
   unsigned r, g, b, a;

   r = (colour & 0xff000000) >> 24;
   r = CLIP(240, 16, r);
   g = (colour & 0xff0000) >> 16;
   g = CLIP(240, 16, g);
   b = (colour & 0xff00) >> 8;
   b = CLIP(240, 16, b);
   a = colour & 0xff;
   
   FREG_VE_SetVoOsd2clut(index,
         (r << 24) | (g << 16) | (b << 8) | (a << 0));
}


/* 21c5ebb4 - complete */
void setClutACbYCr(uint32_t index, uint32_t colour)
{   
   unsigned a, cb, y, cr;
   
   a = (colour & 0xff000000) >> 24;
   cb = (colour & 0xff0000) >> 16;
   cb = CLIP(235, 16, cb);
   y = (colour & 0xff00) >> 8;
   y = CLIP(240, 16, y);
   cr = (colour & 0xff);
   cr = CLIP(235, 16, cr);
   
   FREG_VE_SetVoOsd2clut(index,
         (cb << 24) | (y << 16) | (cr << 8) | (a << 0));
}


/* 21c5eb54 - complete */
void setClutCbYCrA(uint32_t index, uint32_t colour)
{
   unsigned cb, cr, y, a;
   
   cb = (colour & 0xff000000) >> 24;
   cb = CLIP(235, 16, cb);
   y = (colour & 0xff0000) >> 16;
   y = CLIP(240, 16, y);
   cr = (colour & 0xff00) >> 8;
   cr = CLIP(235, 16, cr);
   a = (colour & 0xff);
   
   FREG_VE_SetVoOsd2clut(index,
         (cb << 24) | (y << 16) | (cr << 8) | (a << 0));
}


FAPI_VISCALE_ActiveRegionDataT Data_21efcda8[23] = //21efcda8
{
      //FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE
      {0, 
       0, 
       0, 
       0, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P
      {192, 
       41, 
       1920, 
       1080, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P
      {192, 
       41, 
       1920, 
       1080, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P
      {192, 
       41, 
       1920, 
       1080, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P
      {192, 
       41, 
       1920, 
       1080, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P
      {192, 
       41, 
       1920, 
       1080, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I
      {192, 
       20, 
       1920, 
       540, 
       2, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I
      {192, 
       20, 
       1920, 
       540, 
       2, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I
      {192, 
       20, 
       1920, 
       540, 
       2, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1,
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P
      {260, 
       25, 
       1280, 
       720, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x576x50I
      {264, 
       22, 
       1440, 
       288, 
       2, 
       2, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x576x50P
      {132, 
       44, 
       720, 
       576, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I
      {238, 
       18, 
       1440, 
       240, 
       2, 
       2, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P
      {122, 
       36, 
       720, 
       480, 
       1, 
       1, 
       0}, 
       //FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01
      {100, 
       20, 
       640, 
       480, 
       1, 
       1, 
       0},
       //FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB
      {100, 
       20, 
       1024, 
       768, 
       1, 
       1, 
       0}, 
};


/* 21c5eacc - complete */
int32_t func_21c5eacc(FAPI_VISCALE_VideoScalerHandleT* a, 
      FAPI_VISCALE_ActiveRegionDataT* b)
{   
   FAPI_VISCALE_ActiveRegionDataT* r1 = 0;
   int32_t res = 0;
   
   if (a->hdMode != FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE)
   {
      r1 = &Data_21efcda8[a->hdMode];
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


/* 21c5ef24 - complete */
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


