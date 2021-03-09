

#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>



/* 21c61890 - todo */
int32_t fapi_viscale_cpstart(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpstart\n");
   return 0;
}


/* 21c6170c - todo */
int32_t fapi_viscale_cpstop(FAPI_SYS_HandleT handle)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpstop\n");
   return 0;
}


/* 21c612f4 - todo */
int32_t fapi_viscale_cpenabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpenabledisable\n");
   return 0;
}


/* 21c616c0 - todo */
int32_t fapi_viscale_cphilight(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cphilight\n");
   return 0;
}


/* 21c61584 - todo */
uint32_t fapi_viscale_cpalpha(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                         uint32_t level)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpalpha\n");
   return 0;
}


/* 21c61350 - todo */
int32_t fapi_viscale_cpreposition(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpreposition\n");
   return 0;
}


/* 21c6119c - todo */
int32_t fapi_viscale_cpautoplanefading(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpautoplanefading\n");
   return 0;
}


/* 21c60d00 - todo */
int32_t fapi_viscale_cpautoplanefadingstepsize(FAPI_SYS_HandleT handle, 
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpautoplanefadingstepsize\n");
   return 0;
}


/* 21c610e4 - todo */
int32_t fapi_viscale_cpupdateclut
                             (FAPI_SYS_HandleT handle, uint32_t* colour)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpupdateclut\n");
   return 0;
}


/* 21c6102c - todo */
int32_t fapi_viscale_cpupdatesingleclut
                          (FAPI_SYS_HandleT handle, uint32_t entryNumber,
                                                   uint32_t entryColour)
{
   FAPI_SYS_PRINT_MSG("fapi_viscale_cpupdatesingleclut\n");
   return 0;
}


/* 21c60d50 - complete */
int32_t fapi_viscale_setcptohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle)
{
   int32_t res = FAPI_OK;
   FAPI_VISCALE_VideoScalerHandleT* h = handle;
   FAPI_VIENC_VideoEncoderHandleT* r1 = viencHdHandle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_viscale_setcptohdencoder\n");

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
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_viscale_setcptohdencoder: res=%d\n", res);

   return res;
}





