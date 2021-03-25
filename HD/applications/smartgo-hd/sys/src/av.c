
#define DEBUG 5

#include <string.h>
#include <fapi/sys_services.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_tsd.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_videc.h>
#if 0
#include "rtos.h"
#include "frontend.h"
#endif
#include "sys.h"
#include "app_main.h"
#include "av.h"
#include "val/val.h"


int Data_21f029e0; //21f029e0
struct av* av; //21f029e4

int AVINT_Activate(void);
#if 0
int func_21b7a764(void);
#endif
int32_t AV_PowerupScreenShow(int);
int AVINT_VideoStop(int);



/* 21b7addc - todo */
void av_thread(int a)
{
   AV_Message sp4;

   func_21b8961c(); //->device.c

   while (1)
   {
      //21b7ae00
      if (av->Data_4232 != 0)
      {
         //21b7af54
         func_21b7a260();
      }
      //21b7ae18
      void* r4 = SYS_ReceiveRequestMessage(&av->Data_0);
      if (r4 != 0)
      {
         //21b7ae28
         memcpy(&sp4, r4, sizeof(sp4));

         SYS_SendResponseMessage(&av->Data_0, r4);

         FAPI_SYS_PRINT_MSG("\n\n [AV] cmd received: %i\n",
               sp4.tag);

         switch (sp4.tag)
         {
         case 0:
            //21b7ae00
            break;

         case 1:
            //21b7b488 - av start message
            AVINT_Activate();
            //->21b7ae00
            break;

#if 0
         case 2:
            //21b7b480 - av stop message
            func_21b7a764();
            //->21b7ae00
            break;

         case 3:
            //21b7b468
            break;

         case 4:
            //21b7b458
            break;

         case 5:
            //21b7b44c
            break;

         case 6:
            //21b7b43c
            break;

         case 7:
            //21b7b430
            break;

         case 8:
            //21b7b418
            break;

         case 9:
         case 10:
         case 11:
         case 12:
            //21b7b3d8
            break;

         case 13:
            //21b7b3a8
            break;

         case 14:
            //21b7b39c
            break;

         case 15:
            //21b7b390
            break;

         case 16:
            //21b7b384
            break;

         case 17:
            //21b7b370
            break;

         case 18:
            //21b7b368
            break;

         case 22:
            //21b7b328
            break;

         case 23:
            //21b7b2f8
            break;

         case 24:
            //21b7b2b8
            break;

         case 25:
            //21b7b280
            break;

         case 26:
            //21b7b248
            break;

         case 27:
            //21b7b20c
            break;

         case 28:
            //21b7b1d0
            break;

         case 29:
            //21b7b198
            break;

         case 30:
            //21b7b160
            break;

         case 31:
            //21b7b128
            break;

         case 32:
            //21b7b0f0
            break;

         case 33:
            //21b7b0b4
            break;

         case 34:
            //21b7b06c
            break;

         case 37:
            //21b7b038
            break;

         case 38:
            //21b7b024
            break;

         case 41:
            //21b7aff4
            break;

         case 42:
            //21b7afe0
            break;

         case 43:
            //21b7afd4
            break;

         case 44:
            //21b7afc4
            break;
#endif

         case 45: //AV_CMD_VIDEO_IFRAME_HIDE
            //21b7afb8
             AVINT_VideoStop(0);
            break;

#if 0
         case 46:
            //21b7af88
            break;
#endif

         default:
            //21b7af28
            FAPI_SYS_PRINT_MSG("[AV] ERROR UNKNOWN COMMAND = %d\n",
                  sp4.tag);
            break;
         }
      }
      else
      {
         //21b7af68
         FAPI_SYS_PRINT_MSG("\n %s %d pCmd == NULL ",
               "sys/src/av.c", 1143);
         //->21b7ae00
      }
   }
}


/* 21b7f7dc - complete */
int AVINT_VideoInit(void)
{
//   FAPI_SYS_PRINT_MSG("AVINT_VideoInit\n");
   
   struct av_72740* pVideo = &av->video;
   
   memset(pVideo, 0, sizeof(struct av_72740));

   pVideo->Data_72748 = 5;
   pVideo->Data_72752 = 0;
   pVideo->Data_72756 = -1;
   pVideo->Data_72760 = 0;
   pVideo->Data_72764 = 1;
   pVideo->bootScreenActive = 0;
   pVideo->Data_72772 = 1;

   pVideo->Data_72792 = 0;

   return VAL_Init();
}


/* 21b790e8 - todo */
int32_t AVINT_SetTsInput (uint8_t tsd, /*RSRC_TS_E*/int ts)
{
    FAPI_TSD_TsInputSettingsT   tsInputSettings;
    int32_t                     retVal = FAPI_OK;
    uint32_t                    tsSelect;

    if ( (ts  >= 2/*RSRC_TS_NUMS*/)
      || (tsd >= 4/*RSRC_TSD_NUMS*/) )
    {
        retVal = -0x989681; //APPL_SMARTGO_ERR_BAD_PARAMETER;
    }
    else
    {
        memset (&tsInputSettings, 0, sizeof(tsInputSettings));

        switch ( ts )
        {
            case 0/*RSRC_TS_A*/:     tsSelect = FAPI_TS_A;       break;
            case 1/*RSRC_TS_B*/:     tsSelect = FAPI_TS_B;       break;
            case -1/*RSRC_TS_NONE*/:
            default:            tsSelect = FAPI_TS_DISABLE; break;
        }

        /* TS input settings */
        tsInputSettings.version              = 0x00050000; //FAPI_TSD_VERSION;
        tsInputSettings.tsSelect             = tsSelect;
        tsInputSettings.automaticSync        = 0;
        tsInputSettings.packetStartPolarity  = 0;
        tsInputSettings.enablePolarity       = 0;
        tsInputSettings.clockInvert          = 0;
        tsInputSettings.serialParallelMode  = 0x3;
//        tsInputSettings.packetBufferOverflow = 0;
//        tsInputSettings.writeEndian          = 0;
        tsInputSettings.sbz                  = 0;
        tsInputSettings.syncByteDistance     = 0;
//        tsInputSettings.tsErrorSettings.version         = FAPI_TSD_VERSION;
//        tsInputSettings.tsErrorSettings.removeTsPacket  = 1;
//        tsInputSettings.tsErrorSettings.irqMode         = 0x2;
//        tsInputSettings.tsErrorSettings.countStartValue = 0;
//        tsInputSettings.tsErrorSettings.sbz             = 0;

//        retVal = FAPI_TSD_Configure(tsd, &tsInputSettings, NULL);
        retVal = FAPI_TSD_Configure(tsd, (tsd == 0)? 1: 0, &tsInputSettings, NULL);
    }

    if ( retVal != FAPI_OK )
    {
        FAPI_SYS_PRINT_DEBUG(1,"[AV] AVINT_SetTsInput failed: %i\n", retVal);
    }

    return retVal;
}


/* 21b7b4f4 - todo */
int av_init(void)
{
   unsigned r5, r4;
   int res;

   struct
   {
      unsigned short wData_0; //0
      unsigned short wData_2; //2
   } sp8;

   struct
   {
      int Data_0; //0
      int Data_4; //4
   } sp36;

   int sp48;

   struct appData* fp = SYS_GetConfig();

   if (av != 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/av.c", 202);

      rtos_halt(-1);
   }

   av = SYS_MemoryAllocate(sizeof(struct av));
   if (av == 0)
   {
      return 0xff67697e;
   }

   memset(av, 0, sizeof(struct av));

#if 0
   av->bData_55524 = -1;
   av->bData_55532 = -1;
   av->Data_19712 = 8;
   av->sleepMode = 1;
   av->Data_72836 = 3;
   av->wData_55534 = 0x1fff; //0xe000;
   av->Data_4220 = 3;
   av->Data_4224 = 0;
   av->videoOutCurr = 0;
   av->Data_19716 = 0;
   av->Data_4232 = 0;
   av->Data_72840 = 0;
   av->Data_55520 = 0;
   av->Data_55528 = 0;
   av->Data_55536 = 0;
   av->wData_55516 = 0x1fff;
   av->wData_55526 = 0x1fff;
#else
   av->Data_4220 = 3;
   av->Data_19712 = 8;
   av->sleepMode = 1;
   av->Data_72836 = 3;
   av->Data_4224 = 0;
   av->videoOutCurr = 0;
   av->Data_19716 = 0;
   av->Data_4232 = 0;
   av->Data_72840 = 0;
   av->Data_55520 = 0;
   av->bData_55524 = -1;
   av->wData_55526 = 0x1fff;
   av->Data_55528 = 0;
   av->bData_55532 = -1;
   av->wData_55534 = 0x1fff; //0xe000;
   av->Data_55536 = 0;
   av->wData_55516 = 0x1fff;
#endif

   for (r5 = 0; r5 < fp->bData_0; r5++)
   {
#if 0
      av->Data_19720[r5].bData_0 = r5;
      av->Data_19720[r5].Data_48.Data_48 = 0;
      av->Data_19720[r5].Data_48.Data_56 = 0;
      av->Data_19720[r5].Data_48.wData_52 = -1;
      av->Data_19720[r5].Data_48.wData_96 = -1;
      av->Data_19720[r5].Data_100 =
            av->Data_19720[r5].Data_48;
      av->Data_19720[r5].Data_4 = 0;
      av->Data_19720[r5].Data_16 = 0;
      av->Data_19720[r5].Data_20 = 0;
      av->Data_19720[r5].Data_40 = 1;
      av->Data_19720[r5].Data_152 = 1;
      av->Data_19720[r5].Data_156 = 1;
#else
      av->Data_19720[r5].bData_0 = r5;
      av->Data_19720[r5].Data_4 = 0;
      av->Data_19720[r5].Data_16 = 0;
      av->Data_19720[r5].Data_20 = 0;
      av->Data_19720[r5].Data_40 = 1;
      av->Data_19720[r5].Data_48.Data_48 = 0;
      av->Data_19720[r5].Data_48.wData_52 = -1;
      av->Data_19720[r5].Data_48.Data_56 = 0;
      av->Data_19720[r5].Data_48.wData_96 = -1;
      av->Data_19720[r5].Data_100 =
            av->Data_19720[r5].Data_48;
      av->Data_19720[r5].Data_152 = 1;
      av->Data_19720[r5].Data_156 = 1;
#endif
   }
   //21b7b6f0
   for (r4 = 0; r4 < 4; r4++)
   {
       AVINT_SetTsInput/*func_21b790e8*/(r4, -1);
   }

   sp36.Data_0 = 20;
   sp36.Data_4 = 100;

   res = func_21cb3d4c(&sp36); //->TODO: test.c
   if (res != 0)
   {
      return res;
   }

   res = func_21b7e0a8(); //->TODO: test.c
   if (res != 0)
   {
      return res;
   }

   res = AVINT_VideoInit();
   if (res != 0)
   {
      return res;
   }

   res = func_21bbbf58();
   if (res != 0)
   {
      return res;
   }

   res = func_21b807e8();
   if (res != 0)
   {
      return res;
   }

   sp48 = 0;

   // Create message channel
   res = ITC_Init(&av->Data_0, &sp48);
   if (res != 0)
   {
      return res;
   }

   res = func_21b946b0();
   if (res != 0)
   {
      return res;
   }

   if (28 == SYS_FlashReadFcData(&sp8))
   {
      //21b7b7cc
      av->wData_55500 = sp8.wData_0;
      av->wData_55502 = sp8.wData_2;

      av->wData_55504 = sp8.wData_0;
      av->wData_55506 = sp8.wData_2;
   }
   //21b7b79c
   func_21b98028(0);

   return SYS_ThreadCreate(av_thread,
         0, 38, 0x4000, "AV", 0);
}


/* 21b7ad50 - complete */
int AVINT_Activate(void)
{
   if (av->Data_4232 != 1)
   {
      AVINT_VideoOpen();
      func_21b7e044();
      func_21b802f0(1);
      AV_PowerupScreenShow(0);
#if 0 //TODO
      av_open_tuner();
#endif

      av->Data_72816 = 0;

      av->Data_72820 =
            FAPI_TIMER_GetTimeStamp(1000);

      func_21b98560(&av->Data_72816); //->settings.c

      av->Data_4232 = 1;
   }

   return 0;
}

#if 0

/* 21b7a764 - complete */
int func_21b7a764(void)
{
//   printf("func_21b7a764\n");

   unsigned i;

   if (av->Data_4232 != 0)
   {
      for (i = 0; (char)i < SYS_GetConfig()->bData_0; i++)
      {
         func_21b793b8(&av->Data_19720[(char)i]);
      }

      func_21b7dfd8();
      func_21b7ef40();
      func_21b7a670();

      av->Data_4232 = 0;
   }

   return 0;
}


/* 21b7a7f8 - todo */
int av_open_tuner(void)
{
   struct Struct_19720* r5_;
   char r6_;
   unsigned i;
   int sp36;
   int sp40;
   int sp44;
   int sp48;
   struct frontend_params sp28;
   struct
   {
      int Data_0; //0
      char bData_4; //4
   } sp20;
   FAPI_GPIO_OpenParamsT sp4;
   struct appData* sp;

   sp = SYS_GetConfig();

   func_21b8e9b0(21, 0);

   frontend_init();

   FAPI_SYS_PRINT_MSG("\n CHK_MT_Driver %s %d ",
         "sys/src/av.c", 408);

   Data_21f029e0 = 0;

   sp4.version = FAPI_GPIO_VERSION;
   sp4.pin = 86; //0x56;
   sp4.function = 0x80;
   sp4.callback = 0;

   void* r6 = FAPI_GPIO_Open(&sp4, &sp40);

   sp4.pin = 87; //0x57;
   sp4.function = 0x810000;

   void* r5 = FAPI_GPIO_Open(&sp4, &sp40);

   for (i = 0; i < 10; i++)
   {
      FAPI_GPIO_WriteBit(r6, 0);

      rtos_wait(50);

      if ((0xFF & FAPI_GPIO_ReadBit(r5)) == 0)
      {
         Data_21f029e0 = 1;
      }
      else
      {
         Data_21f029e0 = 0;
      }
   }

   if (Data_21f029e0 == 1)
   {
      //21b7abbc
      for (i = 0; i < 10; i++)
      {
         //21b7abc0
         FAPI_GPIO_WriteBit(r6, 1);

         rtos_wait(50);

         if ((0xFF & FAPI_GPIO_ReadBit(r5)) == 1)
         {
            Data_21f029e0 = 1;
         }
         else
         {
            Data_21f029e0 = 0;
         }
      }
   }
   //21b7a8dc / 21b7abfc
   FAPI_GPIO_Close(r6);
   FAPI_GPIO_Close(r5);

   if (Data_21f029e0 == 1)
   {
      //21b7ac18
      sp4.version = FAPI_GPIO_VERSION;
      sp4.pin = 86; //0x56;
      sp4.function = 0x810000;
      sp4.callback = 0;

      r6 = FAPI_GPIO_Open(&sp4, &sp40);

      sp4.pin = 87; //0x57;
      sp4.function = 0x80;

      r5 = FAPI_GPIO_Open(&sp4, &sp40);

      for (i = 0; i < 10; i++)
      {
         //21b7ac68
         FAPI_GPIO_WriteBit(r6, 0);

         rtos_wait(50);

         if ((0xFF & FAPI_GPIO_ReadBit(r5)) == 0)
         {
            Data_21f029e0 = 1;
         }
         else
         {
            Data_21f029e0 = 0;
         }
      }
      //21b7aca4
      if (Data_21f029e0 == 1)
      {
         //21b7acc4
         for (i = 0; i < 10; i++)
         {
            //21b7acc8
            FAPI_GPIO_WriteBit(r6, 1);

            rtos_wait(50);

            if ((0xFF & FAPI_GPIO_ReadBit(r5)) == 1)
            {
               Data_21f029e0 = 1;
            }
            else
            {
               Data_21f029e0 = 0;
            }
         }
      }
      //21b7acb0
      FAPI_GPIO_Close(r6);
      FAPI_GPIO_Close(r5);
      //->21b7a8f8
   }
   //21b7a8f8
   FAPI_SYS_PRINT_MSG("\n chk_mt_drivr_flag %d %d ",
         Data_21f029e0, 0x215);

   FAPI_SYS_PRINT_MSG("\n chk_mt_drivr_flag %d %d ",
         Data_21f029e0, 0x216);

   FAPI_SYS_PRINT_MSG("\n chk_mt_drivr_flag %d %d ",
         Data_21f029e0, 0x217);

   FAPI_SYS_PRINT_MSG("\n chk_mt_drivr_flag %d %d ",
         Data_21f029e0, 0x218);

   sp4.version = FAPI_GPIO_VERSION;
   sp4.pin = 64; //0x40;
   sp4.function = 0x80;
   sp4.callback = 0;

   void* r4 = FAPI_GPIO_Open(&sp4, &sp40);

   FAPI_SYS_PRINT_MSG("[FRONTEND] gpioHandle error_code %d .\n",
         sp40);

   FAPI_GPIO_WriteBit(r4, 1);

   rtos_wait(50);

   FAPI_GPIO_WriteBit(r4, 0);

   rtos_wait(50);

   FAPI_GPIO_WriteBit(r4, 1);

   rtos_wait(50);

   for (r6_ = 0; r6_ < sp->bData_0; r6_++)
   {
      //21b7aa54
      r5_ = &av->Data_19720[r6_];

      r5_->Data_20 = 0;
      r5_->Data_152 = 1;
      r5_->Data_156 = 1;
      r5_->hFrontend = 0;

      sp28.Data_0 = 0x10000;
      sp28.bData_4 = r6_;

      if (0 != frontend_detect(r6_))
      {
         //21b7aa14
         r5_->hFrontend = 0;

         FAPI_SYS_PRINT_MSG("[AV] FE-%i: Not detected!\n",
               r5_->bData_0 + 1);
         //->21b7aa3c
      }
      else
      {
         //21b7aab8
         r5_->hFrontend = frontend_open(&sp28, &sp40);

         if (r5_->hFrontend == 0)
         {
            //->21b7abb4
            //r0 = sp40;
            //->21b7ab84
            return sp40; //r0
         }
         //21b7aad0
         func_21c9aae0(r5_->hFrontend, &sp44);

         if (sp44 == 1)
         {
            r5_->Data_4 = 1;
            r5_->Data_48.Data_48 = 1;

            func_21b95498(r5_->bData_0, 1); //->resources.c ?

            if (0 == settings_get_lnb_power(r5_->bData_0, &sp48))
            {
               //->21b7ab9c
               func_21b7a648(&av->Data_19720[r6_], (char)sp48); //av_set_lnb_power?
            }
            //21b7ab18
            if (r5_->Data_4 == 1)
            {
               //21b7ab24
               sp20.Data_0 = r5_->hFrontend;
               sp20.bData_4 = 0x31; //49

               sp40 = func_21bb0c88(&sp20, &r5_->Data_12);

               if (sp40 != 0)
               {
                  r5_->Data_12 = 0;
               }
            }
            //->21b7aa3c
         }
         //->21b7aa3c
      }
   }
   //21b7ab70
   if (0 == SETTINGS_VideoOutputGet(&sp36))
   {
      //21b7ab8c
      SETTINGS_VideoOutputSet(sp36);
   }

   return 0;
}

#endif

/* 21b802f0 - todo */
void func_21b802f0(int a)
{
   printf("func_21b802f0\n");
}


/* 21b7e92c - complete */
int av_display_iframe(uint32_t* dataPtr, uint32_t sizeInBytes)
{
   VAL_OpenParamsT sp;
   int32_t res = 0;
   struct av_72740* r4 = &av->video;
   
   if (r4->valDataPtr != 0)
   {
      if (r4->valOpenPtr == 0)
      {
         memset(&sp, 0, sizeof(sp));
         
         sp.environment = VAL_ENV_LIVE;
         sp.decoder.system = 1;
         sp.decoder.frameBankSize = 0;
         sp.enableAfd = 0;
         
         r4->valOpenPtr = 
            VAL_Open(r4->valDataPtr, &sp, &res);
         
         if (r4->valOpenPtr != 0)
         {
            res = VAL_IFrameDecode(r4->valOpenPtr,
                  dataPtr, sizeInBytes);
            
            if (res == 0)
            {
               res = VAL_IFrameDisplay(r4->valOpenPtr);
            }
         }
      }
   }
   else
   {
      res = -12;
   }
   
   return res;
}


/* 21b79318 - complete */
int32_t AV_PowerupScreenShow(int openVideo)
{
   int videoOutput;
   int res = 0;
   struct appData* sysCfg = SYS_GetConfig();

   //FAPI_SYS_PRINT_MSG("21b79318\n");

   if ((av->video.bootScreenActive == 0) &&
         (sysCfg->bootScreen != 0))
   {
      if (openVideo != 0)
      {
         res = AVINT_VideoOpen();
      }

      if (res == 0)
      {
         SCART_SetMode(2);

         if (0 == SETTINGS_VideoOutputGet(&videoOutput))
         {
            SCART_SetVideoOutput(videoOutput);
         }

         res = av_display_iframe(sysCfg->bootScreen, sysCfg->bootScreenSize);

         av->video.bootScreenActive = 1;
      }
   }

   return res;
}


/* 21b7e044 - todo */
void func_21b7e044(void)
{
   printf("func_21b7e044\n");
}

#if 0

struct Struct_21b7e2fc
{
   FAPI_VIDEC_VESParamsT vesParams; //0
   FAPI_VIDEC_GetStateT state; //44
   //144
};


/* 21b7e2fc - complete */
int func_21b7e2fc(struct Struct_21b7e2fc* a)
{
   FAPI_SYS_HandleT videcHandle;
   int res = 0;
   struct av_72740* r4 = &av->video;

   if (a != 0)
   {
      memset(a, 0, sizeof(struct Struct_21b7e2fc));

      if (r4->valOpenPtr != 0)
      {
         videcHandle = VAL_GetVidecHandle(r4->valOpenPtr);

         if (videcHandle != 0)
         {
            FAPI_VIDEC_GetVesParams(videcHandle, &a->vesParams, 0);
            FAPI_VIDEC_GetState(videcHandle, &a->state);
         }
      }
   }

   return res;
}


/* 21b7e3f4 - complete */
void func_21b7e3f4(int a)
{
   struct av_72740* r4 = &av->video;

   if (a != 0)
   {
      func_21ca7a28(r4->valDataPtr, a);
   }
}

#endif

/* 21b7e41c - todo */
void func_21b7e41c(int a, int b, int* hdSys, int* sdSys)
{
   printf("func_21b7e41c\n");
   
   *hdSys = a; //5;
   *sdSys = 20;
}


/* 21b7f594 - complete */
int AVINT_VideoOpen(void)
{
   struct av_72740* r6;
   char sp51;
   char sp50;
   int32_t res; //sp44
   int hdSys; //sp40
   int sdSys; //sp36
   int sp32;
   int sp28;
   int sp24;
   int sp20;
   
   FAPI_SYS_PRINT_MSG("\n AVINT_VideoOpen");
   
   r6 = &av->video;
   
   if (r6->valDataPtr != 0)
   {
      return -13;
   }
   
   sp50 = 0;
   sp51 = 0;
   sp24 = 5;
   sp20 = 0;
   sp28 = 0;
   sp32 = 1;
   res = 0;
   
   settings_get_tv_out_system(&sp24, &sp20);
   
   func_21b98f24(&sp32, &sp28); //->settings.c
   
   r6->Data_72748 = sp24;
   r6->Data_72752 = sp20;
   r6->Data_72756 = -1;
   r6->Data_72772 = 1;
   
   func_21b7e41c(sp24, sp20, &hdSys, &sdSys);
      
   VAL_UpParamsT sp;
   
   memset(&sp, 0, sizeof(sp));
   
   if (sp32 == 1)
   {
      sp.displayAspectRatio[1] = FAPI_VISCALE_AR_16_9;
   }
   else
   {
      sp.displayAspectRatio[1] = FAPI_VISCALE_AR_4_3;
   }
   
   sp.hdSystemType = hdSys;
   sp.sdSystemType = sdSys;
   sp.displayAspectRatio[0] = FAPI_VISCALE_AR_NONE;
   sp.scalingMethod = FAPI_VISCALE_SM_PLBOX;
   
   switch (sp28)
   {
   case 1:
      //21b7f788
      sp.scalingMethod = FAPI_VISCALE_SM_FSZOOM;
      break;
      
   case 2:
      //21b7f77c
      sp.scalingMethod = FAPI_VISCALE_SM_FSCCO;
      break;
      
   case 3:
      //21b7f770
      sp.scalingMethod = FAPI_VISCALE_SM_LTVS;
      break;
      
   case -1:
      //21b7f6bc
      sp.scalingMethod = FAPI_VISCALE_SM_NONE;
      break;
   }

   FAPI_SYS_PRINT_MSG("\n hdSys=%d sdSys=%d",
         hdSys, sdSys);

   r6->valDataPtr = VAL_GoUp(&sp, &res);
   r6->valOpenPtr = 0;
#if 0
   r6->Data_72776 = 0;
   r6->Data_72780 = -1;
#else
   r6->freezeDecoder.system = 0;
   r6->freezeDecoder.frameBankSize = -1;
#endif
   
   FAPI_VISCALE_SetWssState(
         VAL_GetViscaleHd(r6->valDataPtr), 
         FAPI_VISCALE_WSS_ENABLE_AUTO);
   
   FAPI_VIENC_EnableDisableWss(
         VAL_GetViencSd(av->video.valDataPtr),
         FAPI_VIENC_PARAMETER_ON);
   
   res = func_21ca9b8c(r6->valDataPtr, &sp51, &sp50);
   
   if ((res == 0) && (sp51 != 0))
   {
      r6->Data_72792 = 1;
      
      func_21cadb54(0);
      func_21cadb54(1);
   }
   else
   {
      r6->Data_72792 = 0;
   }

   return res;
}


/* 21b7bc6c - complete */
int av_send_message(AV_Message* a)
{
   return SYS_SendRequestMessage(
         &av->Data_0, a, 0);
}


/* 21b7bc48 - complete */
FAPI_SYS_HandleT av_get_vienc_hd(void)
{
//   printf("av_get_vienc_hd");
   
   if (av->video.valDataPtr != 0)
   {
      return VAL_GetViencHd(av->video.valDataPtr);
   }
   
   return 0;
}


/* 21b7bc84 - complete */
int AV_IFrameHide(void)
{
    AV_Message sp;

    if (av == 0)
    {
        return -0x989684;
    }

    sp.tag = 45; //AV_CMD_VIDEO_IFRAME_HIDE
    return av_send_message(&sp);
}


/* 21b7c214 - complete */
int AV_PowerupScreenHide(void)
{
    if (av == 0)
    {
        return -0x989684;
    }

    if (av->video.bootScreenActive == 0)
    {
        return 0;
    }

    struct appData* fp = SYS_GetConfig();
    if (fp->bootScreen == 0)
    {
        return 0;
    }

    return AV_IFrameHide();
}


/* 21b7ea54 - complete */
int AVINT_VideoStop(int freezeVideo)
{
    AV_VIDEO_S* pVideo = &(av->video);
    int32_t     retVal = FAPI_OK;
    VAL_StatusT status;

    if ( pVideo->valOpenPtr != NULL )
    {
        if ( freezeVideo
          && (VAL_GetStatus (pVideo->valOpenPtr, &status) == FAPI_OK) )
        {
            pVideo->freezeDecoder = status.decoder;
        }
        else
        {
            pVideo->freezeDecoder.system        = 0; //FAPI_VIDEC_UNKNOWN_DECODER;
            pVideo->freezeDecoder.frameBankSize = -1; //FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
        }

        (void)VAL_Stop (pVideo->valOpenPtr, freezeVideo);
        (void)VAL_Close(pVideo->valOpenPtr);

        pVideo->valOpenPtr       = NULL;
        pVideo->bootScreenActive = 0; //FFALSE;
#if 0
        pVideo->haveFrameRate    = FFALSE;
        pVideo->currPid = 0;

        avData->hdmiLipSyncSet   = FFALSE;
#endif
    }

    return retVal;
}






