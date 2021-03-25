
#define DEBUG 0

#include <fapi/sys_services.h>
#include <fapi/board_ifc.h>
#include <fapi/drv_gpio.h>
#if 0
#include "frontend.h"
#include "m88ds3k.h"
#endif


FAPI_BOARD_HwPlatformInfosT GmiH60StbCi_HwInfo = //21e07a80
{
   FAPI_BOARD_HWCONFIG_VERSION, //MagicAndVersion;        //!< #FAPI_BOARD_HWCONFIG_VERSION
   "GMI", //pHwManufactString;  //!< Manufacturer-Info
   "MB86H60 STB (SEDVS40130G)", //pHwModelString;         //!< HW-Model Info
   0, //pOptAdditionalInfo;     //!< e.g. can be used for spec. Test purpose
   1, //flagUsbHostOnly;        //!<
   2, //typeOfFlashAvailable;   //!< see 'FAPI_BOARD_BITFLAG_PFLASH' etc.
   0, //AudioConfigurationInfoA;//!< for future use
   0, //AudioConfigurationInfoB;//!< for future use
   1, //numberOfAvlFrontEnds;   //!< number of available frontends
   1, //numberOfAvlCiSlots;     //!< number of available CI-Slots
   {
    {1, 1, 1, 1},
    {1, 2, 0, 2},
   }, //FAPI_BOARD_FeConfigInfoT feCfg[FAPI_BOARD_MAX_TSINP_PATH];  //!< FE-CfgData
   0x10, //flagHardDiskInterface;  //!< see 'FAPI_BOARD_HD1_P_ATA' etc.
   0, //flgDdr2MemoryInfos ;    //!< not really used yet
} ;


FAPI_BOARD_ServicesT FAPI_BOARD_Services; //21f77c50
int Data_21f77c90; //21f77c90
FAPI_BOARD_HwPlatformInfosT* boardHwInfos; //21f77c98
FAPI_SYS_HandleT Data_21f77c9c; //21f77c9c
FAPI_SYS_HandleT Data_21f77ca0; //21f77ca0
FAPI_SYS_HandleT Data_21f77ca4; //21f77ca4
FAPI_SYS_HandleT Data_21f77ca8; //21f77ca8

struct Struct_21f77cac
{
   int Data_0; //0
   int Data_4; //4
   int Data_8; //8
   //12
} Data_21f77cac;



int32_t BOARD_GMI_MB86H60_STB_CI_BoardIfc_InitDetect(uint32_t, void*);
int32_t BOARD_GMI_MB86H60_STB_CI_ControlScartPin8A16(int32_t, FAPI_BOARD_ScartCommandT, void*);
void func_21cb2198(void);
void func_21cb20c4(int, int);
void func_21cb141c(void);



/* 21cb0c6c - complete */
void FAPI_BOARD_SetBoardInitDetectHook(FAPI_BOARD_InitDetectHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_BrdInitDetect = hookPtr;
}


/* 21cb0c7c - complete */
void FAPI_BOARD_SetBoardInfo(FAPI_BOARD_HwPlatformInfosT *boardHwInfosPtr)
{
   boardHwInfos = boardHwInfosPtr;
}


/* 21cb0c8c - complete */
FAPI_BOARD_HwPlatformInfosT * FAPI_BOARD_GetBoardInfo(void)
{
   return boardHwInfos;
}


/* 21cb0c9c - complete */
void FAPI_BOARD_SetControlTestLedKeyHook(FAPI_BOARD_ControlLedHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_Led = hookPtr;
}


/* 21cb0cac - complete */
void FAPI_BOARD_SetControlFeResetHook(FAPI_BOARD_ControlFeHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_FeReset = hookPtr;
}


/* 21cb0cbc - complete */
void FAPI_BOARD_SetControlFeDetectHook(FAPI_BOARD_ControlFeDetectHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_FeDetect = hookPtr;
}


/* 21cb0ccc - complete */
void FAPI_BOARD_SetControlHdResetHook(FAPI_BOARD_ControlHdHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_HdReset = hookPtr;
}


/* 21cb0cdc - complete */
void FAPI_BOARD_SetControlTsPathHook(FAPI_BOARD_ControlTsPathHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_TsPath = hookPtr;
}


/* 21cb0cec - complete */
void FAPI_BOARD_SetControlHdmiPathHook(FAPI_BOARD_ControlHdmiPathHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_HdmiPath = hookPtr;
}


/* 21cb0cfc - complete */
void FAPI_BOARD_SetControlScartHook(FAPI_BOARD_ControlScartHookT hookPtr)
{
   FAPI_BOARD_Services.controlHook_Scart = hookPtr;
}


/* 21cb0d2c - complete */
void func_21cb0d2c(int a)
{
   Data_21f77c90 = a;
}


/* 21cb0d3c - complete */
int func_21cb0d3c(void)
{
   return Data_21f77c90;
}


/* 21cb0e1c - complete */
int BOARD_GMI_MB86H60_STB_CI_ControlAlifeLed(void)
{
   return 0;
}


/* 21cb0e24 - complete */
int BOARD_GMI_MB86H60_STB_CI_ControlFeResetPower(void)
{
   return 0;
}


/* 21cb0e2c - complete */
int BOARD_GMI_MB86H60_STB_CI_ControlHdResetPower(int a, int b, int c)
{
   return 0;
}


/* 21cb0e34 - complete */
int32_t BOARD_GMI_MB86H60_STB_CI_BoardIfc_InitDetect(uint32_t optInitBitFlags, void* optPtr)
{
   FAPI_GPIO_OpenParamsT sp;
   int32_t sp16;
   int32_t res = 0;
   
   if (Data_21f77c9c == 0)
   {
      sp.version = FAPI_GPIO_VERSION;
      sp.pin = 67;
      sp.function = 0x80;
      sp.callback = 0;
      
      Data_21f77c9c = FAPI_GPIO_Open(&sp, &sp16);
      
      FAPI_SYS_PRINT_MSG("scart_16_9 error_code %d .\n", sp16);
      
      FAPI_GPIO_WriteBit(Data_21f77c9c, 0);
   }
   
   if (Data_21f77ca0 == 0)
   {
      sp.version = FAPI_GPIO_VERSION;
      sp.pin = 24;
      sp.function = 0x80;
      sp.callback = 0;
      
      Data_21f77ca0 = FAPI_GPIO_Open(&sp, &sp16);
      
      FAPI_SYS_PRINT_MSG("scart_vcr error_code %d .\n", sp16);
      
      FAPI_GPIO_WriteBit(Data_21f77ca0, 0);
   }
   
   if (Data_21f77ca4 == 0)
   {
      sp.version = FAPI_GPIO_VERSION;
      sp.pin = 65;
      sp.function = 0x80;
      sp.callback = 0;
      
      Data_21f77ca4 = FAPI_GPIO_Open(&sp, &sp16);
      
      FAPI_SYS_PRINT_MSG("scart_tv_sat error_code %d .\n", sp16);
      
      FAPI_GPIO_WriteBit(Data_21f77ca4, 0);
   }
   
   if (Data_21f77ca8 == 0)
   {
      sp.version = FAPI_GPIO_VERSION;
      sp.pin = 68;
      sp.function = 0x80;
      sp.callback = 0;
      
      Data_21f77ca8 = FAPI_GPIO_Open(&sp, &sp16);
      
      FAPI_SYS_PRINT_MSG(" scart_RGB error_code %d .\n", sp16);
      
      FAPI_GPIO_WriteBit(Data_21f77ca8, 0);
   }
   
   memset(&Data_21f77cac, 0, sizeof(struct Struct_21f77cac));
   
   func_21cb2198();
   
   func_21cb20c4(255, 78);

   func_21cb141c();
   
   return res;
}


/* 21cb1018 - complete */
int BOARD_GMI_MB86H60_STB_CI_RegisterBoardIfc(int a, int b)
{
   FAPI_BOARD_SetBoardInfo(&GmiH60StbCi_HwInfo);
   
   FAPI_BOARD_SetBoardInitDetectHook(BOARD_GMI_MB86H60_STB_CI_BoardIfc_InitDetect);
   
   FAPI_BOARD_SetControlTestLedKeyHook(BOARD_GMI_MB86H60_STB_CI_ControlAlifeLed);
   
   FAPI_BOARD_SetControlFeResetHook(BOARD_GMI_MB86H60_STB_CI_ControlFeResetPower);
   
   FAPI_BOARD_SetControlHdResetHook(BOARD_GMI_MB86H60_STB_CI_ControlHdResetPower);
   
   FAPI_BOARD_SetControlScartHook(BOARD_GMI_MB86H60_STB_CI_ControlScartPin8A16);
   
   BOARD_GMI_MB86H60_STB_CI_PreInitGpioPins();
   
   func_21cb21bc();
   
   return 0;
}


/* 21cb1074 - complete */
int32_t BOARD_GMI_MB86H60_STB_CI_ControlScartPin8A16(int32_t index, FAPI_BOARD_ScartCommandT command, void* optPtr)
{
   int32_t res = 0;
   
   FAPI_SYS_PRINT_DEBUG(5, "BOARD_GMI_MB86H60_STB_CI_ControlScartPin8A16: index=%d, command=%d, optPtr=0x%x",
         index, command, optPtr);

   if (index > 0)
   {
      res = -5;
   }
   else
   {
      if (command == FAPI_BOARD_SCART_MODE_OFF) 
      {
         FAPI_GPIO_WriteBit(Data_21f77c9c, 0);
         FAPI_GPIO_WriteBit(Data_21f77ca4, 1);
         
         Data_21f77cac.Data_0 = 0;
      }
      else if (command == FAPI_BOARD_SCART_MODE_16_9)
      {
         FAPI_GPIO_WriteBit(Data_21f77c9c, 1);
         FAPI_GPIO_WriteBit(Data_21f77ca4, 0);
         
         Data_21f77cac.Data_0 = 1;
      }
      else if (command == FAPI_BOARD_SCART_MODE_4_3)
      {
         FAPI_GPIO_WriteBit(Data_21f77c9c, 0);
         FAPI_GPIO_WriteBit(Data_21f77ca4, 0);
         
         Data_21f77cac.Data_0 = 2;
      }
      else if (command == FAPI_BOARD_SCART_VIDEO_OUTPUT_CVBS)
      {
         FAPI_GPIO_WriteBit(Data_21f77ca8, 0);
         
         Data_21f77cac.Data_4 = 1;
      }
      else if (command == FAPI_BOARD_SCART_VIDEO_OUTPUT_RGB)
      {
         FAPI_GPIO_WriteBit(Data_21f77ca8, 1);
         
         Data_21f77cac.Data_4 = 0;
      }
      else if (command == FAPI_BOARD_SCART_TV_SOURCE_VCR)
      {
         FAPI_GPIO_WriteBit(Data_21f77ca0, 1);

         Data_21f77cac.Data_8 = 0;
      }
      else if (command == FAPI_BOARD_SCART_TV_SOURCE_DVB)
      {
         FAPI_GPIO_WriteBit(Data_21f77ca0, 0);

         Data_21f77cac.Data_8 = 1;
      }
      else if (command == FAPI_BOARD_SCART_VCR_GET_STATUS)
      {
         memcpy(optPtr, &Data_21f77cac, sizeof(Data_21f77cac));
      }
      else
      {
         res = -5;
      }
   }
   
   return res;
}


/* 21cb1d28 - todo */
void BOARD_GMI_MB86H60_STB_CI_PreInitGpioPins(void)
{
   printf("BOARD_GMI_MB86H60_STB_CI_PreInitGpioPins: TODO\n");
}


/* 21cb20a0 - complete */
int func_21cb20a0(unsigned a, struct frontend* b)
{
   if (a > 1)
   {
      return -5;
   }

#if 0 //TODO
   if (0 != M88DS3K_HE6306_Detect(a, b))
   {
      return -12;
   }
#endif

   return 0;
}


/* 21cb2088 - complete */
int BOARD_GMI_MB86H60_STB_CI_RegisterFrontends(int a, int b)
{
   FAPI_BOARD_SetControlFeDetectHook(func_21cb20a0);

   return 0;
}


int Data_21f01810; //21f01810


/* 21cb21bc - complete */
void func_21cb21bc(void)
{
   func_21cb0d2c(&Data_21f01810);
}


/* 21cb2198 - todo */
void func_21cb2198(void)
{
   FAPI_SYS_PRINT_MSG("func_21cb2198\n");
}


/* 21cb20c4 - todo */
void func_21cb20c4(int a, int b)
{
   FAPI_SYS_PRINT_MSG("func_21cb20c4\n");
}


/* 21cb141c - todo */
void func_21cb141c(void)
{
   FAPI_SYS_PRINT_MSG("func_21cb141c\n");
   
}



