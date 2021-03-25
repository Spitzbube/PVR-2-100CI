
#define DEBUG 5

#include <fapi/sys_services.h>
#include <fapi/board_ifc.h>
#include "app_main.h"
#include "sys.h"
#include "rtos/rtos.h"


extern void av_int_set_colour_component_sd(int);




typedef struct Struct_21f02e30
{
   int Data_0; //0
   int Data_4; //4
   int Data_8; //8
   int Data_12; //12
   int Data_16; //16
   int hdTvOutSys; //20
   int sdTvOutSys; //24
   int Data_28; //28
   int Data_32; //32
   int scartVideoMode; //36
   unsigned short wData_40; //40
   int Data_44; //44
   int Data_48; //48
   int Data_52; //52
   int Data_56; //56
   unsigned short wData_60; //60
   int Data_64; //64
   int Data_68; //68
   int Data_72; //72
   int Data_76; //76
   int Data_80[2]; //80
   int Data_88[2]; //88
   int Data_96[2]; //96
   int Data_104[2]; //104
   int Data_112[2]; //112
   int Data_120; //120
   int Data_124; //124
   int Data_128; //128
   int fill_132[11]; //132
   int Data_176; //176
   int Data_180[4]; //180
   int Data_196; //196
   int fill_200[17]; //200
   int Data_268; //268
   int Data_272; //272
   int Data_276; //276
   int Data_280; //280
   int Data_284; //284
   unsigned short wData_288; //288
   //292
} STARTUP_PARAMS_S;


int currVideoOut = -1; //21ed5e58

int currMode; //21f02e28
STARTUP_PARAMS_S* startupDat; //21f02e30
int startupDatDirty; //21f02e34
int Data_21f02e38; //21f02e38

int Data_21f7defc; //21f7defc


void SETTINGS_StartupDefaultsSet(void);


/* 21b9a0dc - complete */
int SETTINGS_StartupInit(void)
{
   FAPI_SYS_PRINT_DEBUG(5, "SETTINGS_StartupInit\n");
   
   if (startupDat != 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/settings.c", 251);
      
      rtos_halt(-1);
   }
   
   startupDat = SYS_MemoryAllocate(sizeof(STARTUP_PARAMS_S));
   
   if (startupDat == 0)
   {
      return -10000002;
   }

   Data_21f02e38 = 0;

   if (0 == func_21b99c00())
   {
      Data_21f02e38 = 1;
   }
   else
   {
      FAPI_SYS_PRINT_MSG("\n %s %d SETTINGS_StartupInit",
            "sys/src/settings.c", 261);

      FAPI_SYS_PRINT_MSG("[SYS] No startup data available, start reformatting...\n");

      SETTINGS_StartupDefaultsSet();
   }
   
   FAPI_SYS_PRINT_MSG("\n %s %d SETTINGS_StartupInit",
         "sys/src/settings.c", 269);

   return 0;
}


/* 21b99f88 - todo */
void SETTINGS_StartupDefaultsSet(void)
{
   unsigned i;

//   FAPI_SYS_PRINT_MSG("SETTINGS_StartupDefaultsSet\n");

   if (startupDat != 0)
   {
      memset(startupDat, 0, sizeof(STARTUP_PARAMS_S));

      Data_21f02e38 = 0;

      startupDat->Data_0 = 0x6a720006;
      startupDat->Data_196 = 0x6a720006;
      startupDat->Data_4 = 4;
      startupDat->Data_8 = 0;
      startupDat->Data_12 = 1;
      startupDat->Data_16 = 0;
      startupDat->hdTvOutSys = 5;
      startupDat->sdTvOutSys = 0;
      startupDat->Data_28 = 5;
      startupDat->Data_32 = 0;
      startupDat->scartVideoMode = 0;
      startupDat->wData_40 = 60;
      startupDat->Data_44 = 1;
      startupDat->Data_48 = 1;
      startupDat->Data_52 = 0;
      startupDat->Data_56 = 0xffffff;
      startupDat->wData_60 = 5;
      startupDat->Data_64 = 0;
      startupDat->Data_68 = 0x676572; //eng
      startupDat->Data_72 = 0;
      startupDat->Data_76 = 0;
      startupDat->Data_120 = 1;
      startupDat->Data_124 = 1;
      startupDat->Data_128 = 1;
      startupDat->Data_176 = 0;
      startupDat->Data_268 = 1;
      startupDat->Data_272 = 0;
      startupDat->Data_276 = 0;
      startupDat->Data_280 = 1;
      startupDat->Data_284 = -1;
      startupDat->wData_288 = 0x100;

      for (i = 0; i < 2; i++)
      {
         startupDat->Data_80[i] = 0xffffff;
      }

      for (i = 0; i < 2; i++)
      {
         startupDat->Data_88[i] = 0xffffff;
      }

      for (i = 0; i < 2; i++)
      {
         startupDat->Data_96[i] = 0xffffff;
      }

      for (i = 0; i < 2; i++)
      {
         startupDat->Data_104[i] = 0xffffff;
      }

      for (i = 0; i < 2; i++)
      {
         startupDat->Data_112[i] = 1;
      }

      for (i = 0; i < 4; i++)
      {
         startupDat->Data_180[i] = 0;
      }

      if (SYS_GetConfig()->setStartupDefaults != 0)
      {
         (SYS_GetConfig()->setStartupDefaults)();
      }

      func_21b7c588(160, 160);

      startupDatDirty = 1;
   }
}


/* 21b99c00 - todo */
int func_21b99c00(void)
{
   FAPI_SYS_PRINT_MSG("func_21b99c00\n");
   
   return 1;
}


/* 21b99a10 - complete */
int SETTINGS_Init(void)
{
   int res = 0;

   if (startupDat == 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/settings.c", 547);
      rtos_halt(-1);
   }

   FAPI_SYS_PRINT_MSG("\n==============================");
   FAPI_SYS_PRINT_MSG("\n %s %d SETTINGS_Init \n",
         "sys/src/settings.c", 549);
   FAPI_SYS_PRINT_MSG("\n==============================");
   
   Data_21f7defc = 0;
   
   return res;
}


/* 21b98f24 - complete */
int func_21b98f24(int* a, int* b)
{
   int res = 0;

   if (startupDat != 0)
   {
      rtos_request_semaphore(sysData->mutexId, -1);

      if (a != 0)
      {
         *a = startupDat->Data_12;
      }

      if (b != 0)
      {
         *b = startupDat->Data_16;
      }

      rtos_release_semaphore(sysData->mutexId, 0);
   }
   else
   {
      res = -10000004;
   }

   FAPI_SYS_PRINT_DEBUG(5, "func_21b98f24: res=%d, *a=%d, *b=%d\n", res, *a, *b);

   return res;
}


/* 21b98644 - complete */
int func_21b98644(int* a)
{
   int res = 0;

   if (startupDat != 0)
   {
      *a = startupDat->Data_268;
   }
   else
   {
      res = -10000004;
   }

   FAPI_SYS_PRINT_DEBUG(5, "func_21b98644: res=%d, *a=%d\n", res, *a);

   return res;
}


/* 21b98560 - complete */
int func_21b98560(int* a)
{
   int res = 0;

   if (startupDat != 0)
   {
      *a = startupDat->Data_124;
   }
   else
   {
      res = -10000004;
   }

   FAPI_SYS_PRINT_DEBUG(5, "func_21b98560: res=%d, *a=%d\n", res, *a);

   return res;
}


/* 21b984ec - complete */
int settings_get_lnb_power(signed char a, int* b)
{
   int res = 0;

   if (startupDat != 0)
   {
      if ((a == 0) || (a == 1))
      {
         *b = startupDat->Data_112[a];
      }
      else
      {
         res = -10000001;
      }
   }
   else
   {
      res = -10000004;
   }

   FAPI_SYS_PRINT_DEBUG(5, "settings_get_lnb_power: res=%d, a=%d, *b=%d\n", res, a, *b);

   return res;
}


/* 21b980bc - complete */
void func_21b980bc(void)
{
   if (startupDat != 0)
   {
      FAPI_SYS_PRINT_MSG("\n SETTINGS_Init \n========================");
      FAPI_SYS_PRINT_MSG("\n hdTvOutSys :%d ", startupDat->hdTvOutSys);
      FAPI_SYS_PRINT_MSG("\n sdTvOutSys :%d ", startupDat->sdTvOutSys);
   }
}


/* 21b97fb8 - complete */
void SCART_SetVideoOutput(int a)
{
   FAPI_SYS_PRINT_DEBUG(5, "SCART_SetVideoOutput: a=%d\n", a);

   if (a == 0)
   {
      FAPI_BOARD_CONTROL_SCART(0, FAPI_BOARD_SCART_VIDEO_OUTPUT_RGB, 0);
   }
   else if (a == 1)
   {
      FAPI_BOARD_CONTROL_SCART(0, FAPI_BOARD_SCART_VIDEO_OUTPUT_CVBS, 0);
   }

   currVideoOut = a;
}


/* 21b97f04 - complete */
void SCART_SetMode(int a)
{
   FAPI_SYS_PRINT_DEBUG(5, "SCART_SetMode: a=%d\n", a);

   switch (a)
   {
   case 1:
      FAPI_BOARD_CONTROL_SCART(0, FAPI_BOARD_SCART_MODE_4_3, 0);
      break;

   case 2:
      FAPI_BOARD_CONTROL_SCART(0, FAPI_BOARD_SCART_MODE_16_9, 0);
      break;

   default:
      FAPI_BOARD_CONTROL_SCART(0, FAPI_BOARD_SCART_MODE_OFF, 0);
      break;
   }

   currMode = a;
}


/* 21b982b0 - complete */
int settings_get_tv_out_system(int* a, int* b)
{
   int res = 0;

   if (startupDat != 0)
   {
      if (a != 0)
      {
         *a = startupDat->hdTvOutSys;
      }

      if (b != 0)
      {
         *b = startupDat->sdTvOutSys;
      }
   }
   else
   {
      res = -10000004;
   }

   FAPI_SYS_PRINT_DEBUG(5, "settings_get_tv_out_system: res=%d, *a=%d, *b=%d\n", res, *a, *b);

   return res;
}


/* 21b98284 - complete */
int SETTINGS_VideoOutputGet(int* a)
{
   int res = 0;

   if (startupDat != 0)
   {
      *a = startupDat->scartVideoMode;
   }
   else
   {
      res = -10000004;
   }

   FAPI_SYS_PRINT_DEBUG(5, "SETTINGS_VideoOutputGet: res=%d, *a=%d\n", res, *a);

   return res;
}


/* 21b9976c - complete */
int SETTINGS_VideoOutputSet(int a)
{
   int res = 0;

   FAPI_SYS_PRINT_DEBUG(5, "SETTINGS_VideoOutputSet\n");

   if (startupDat != 0)
   {
      rtos_request_semaphore(sysData->mutexId, -1);

      if (startupDat->scartVideoMode != a)
      {
         startupDat->scartVideoMode = a;
         startupDatDirty = 1;
      }

      if (1 == SYS_GetPowerOn())
      {
         av_int_set_colour_component_sd(startupDat->scartVideoMode);
      }

      rtos_release_semaphore(sysData->mutexId, 0);
   }
   else
   {
      res = -10000004;
   }

   return res;
}


