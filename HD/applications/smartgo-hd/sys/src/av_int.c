
#define DEBUG 0

#include <fapi/sys_services.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_videc.h>
#include "val/val.h"
#include "rtos/rtos.h"
#include "sys.h"
#include "av.h"


void av_int_set_colour_component_sd(int a);



/* 21b8056c - complete */
int av_send_null_message(void)
{
   AV_Message msg;

   if (av == 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/av_int.c", 377);

      rtos_halt(-1);
   }

   msg.tag = 0;

   return av_send_message(&msg);
}


/* 21b805dc - complete */
int av_send_start_message(void)
{
   int res = 0;
   AV_Message msg;
   int videoOutput;

   if (av == 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/av_int.c", 415);

      rtos_halt(-1);
   }

   if (av->sleepMode == 0)
   {
      return 0;
   }

   msg.tag = 1; //AV_CMD_WAKEUP

   res = av_send_message(&msg);
   if (res == 0)
   {
      av->sleepMode = 0;

      if (0 == SETTINGS_VideoOutputGet(&videoOutput))
      {
         av_int_set_colour_component_sd(videoOutput);
      }
   }

   return res;
}


/* 21b804c0 - complete */
int av_send_stop_message(void)
{
   int res;
   AV_Message msg;

   if (av == 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
         "sys/src/av_int.c", 466);

      rtos_halt(-1);
   }

   if (av->sleepMode != 0)
   {
      return 0;
   }

   SCART_SetMode(0);

   av_int_set_colour_component_sd(-1);

   msg.tag = 2;

   res = av_send_message(&msg);
   if (res == 0)
   {
      av->sleepMode = 1;
   }

   return res;
}


/* 21b803e4 - complete */
void av_int_set_colour_component_sd(int videoOut)
{
   FAPI_SYS_HandleT viencHandle;

   FAPI_SYS_PRINT_DEBUG(5, "av_int_set_colour_component_sd: a=%d\n", videoOut);

   if (av == 0)
   {
      return;
   }

   viencHandle = VAL_GetViencSd(av->video.valDataPtr);

   if (videoOut != av->videoOutCurr)
   {
      switch (videoOut)
      {
      case 0:
         FAPI_VIENC_SetColourComponent(viencHandle, FAPI_VIENC_COMPONENT_CVBS_RGB);
         break;

      case 1:
         FAPI_VIENC_SetColourComponent(viencHandle, FAPI_VIENC_COMPONENT_CVBS_YC);
         break;

      default:
         FAPI_SYS_PRINT_MSG("\n %s %d ",
               "sys/src/av_int.c", 578);
         break;
      }

      SCART_SetVideoOutput(videoOut);

      av->videoOutCurr = videoOut;
   }
}




