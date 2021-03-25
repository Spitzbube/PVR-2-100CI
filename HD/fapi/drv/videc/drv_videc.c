

#define DEBUG 4

#include <string.h>
#include <fapi/reg_bm.h>
#include <fapi/reg_ddrramif.h>
#include <fapi/reg_vd.h>
#include <fapi/reg_vd_ext.h>
#include <fapi/reg_vo.h>
#include <fapi/sys_services.h>
#include <fapi/drv_boot.h>
//#include <fapi/board_ifc.h>
#include <fapi/drv_timer.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_videc.h>
#include <fapi/drv_videc_priv.h>


uint32_t Data_21e01a08[] = //21e01a08
{
 0x00000000, 0x00000340, 0x00000680, 0x000009c0,
 0x00000d00, 0x00001040, 0x00001380, 0x000016c0,
 0x00001a00, 0x00002000, 0x00002340, 0x00002680,
 0x000029c0, 0x00002d00, 0x00003040, 0x00003380,
 0x000036c0, 0x00003a00, 0x00004000, 0x00004340,
 0x00004680, 0x000049c0,
};

uint32_t Data_21e01a60[] = //21e01a60
{
 0x00000000, 0x00000270,
 0x000004e0, 0x00000750, 0x000009c0, 0x00000c30,
 0x00000ea0, 0x00001110, 0x00001380, 0x000015f0,
 0x00001860, 0x00001ad0, 0x00001d40, 0x00002000,
 0x00002270, 0x000024e0, 0x00002750, 0x000029c0,
 0x00002c30, 0x00002ea0, 0x00003110, 0x00003380,
};

uint32_t Data_21e01ab8[] = //21e01ab8
{
 0x00000000, 0x00000168, 0x000002d0, 0x00000438,
 0x000005a0, 0x00000708, 0x00000870, 0x000009d8,
 0x00000b40, 0x00000ca8, 0x00000e10, 0x00000f78,
 0x000010e0, 0x00001248, 0x000013b0, 0x00001518,
 0x00001680, 0x000017e8, 0x00001950, 0x00001ab8,
 0x00001c20, 0x00001d88,
};

uint32_t Data_21e01b10[] = //21e01b10
{
 0x00000000, 0x000000a8,
 0x00000150, 0x000001f8, 0x000002a0, 0x00000348,
 0x000003f0, 0x00000498, 0x00000540, 0x000005e8,
 0x00000690, 0x00000738, 0x000007e0, 0x00000888,
 0x00000930, 0x000009d8, 0x00000a80, 0x00000b28,
 0x00000bd0, 0x00000c78, 0x00000d20, 0x00000dc8,
};


struct Struct_21efc808
{
   int Data_0; //0
   int Data_4; //4
   int Data_8; //8
   int Data_12; //12
   int Data_16; //16
   int32_t Data_20; //20

};

struct Struct_21efc808 Data_21efc808 = //21efc808
{
      0, 0, 0, 0, 0, -28138
};

struct Struct_21efc820
{
   int fill_0; //0
   unsigned mpeg2Version; //4
   unsigned h264Version; //8
   int fill_12; //12
   int fill_16; //16
};

struct Struct_21efc820 Data_21efc820 = //21efc820
{
   -1,
   0x4d31001b,
   0x48312004,
   0x5631,
   0x4131
};

int FAPI_VIDEC_MAX_VIDEO_STREAM_BUFFER_SIZE[] = //21b6b934
{
      0,
      0x3ffc00,
      0x7ffc00
};



FAPI_SYS_DriverT FAPI_VIDEC_Driver0 = //21efc834
{
      "VIDEC0",
      28, //FAPI_INTR_DISP0
      FAPI_SYS_BSR_EXEC_THREAD,
      FAPI_VIDEC_Init,
      FAPI_VIDEC_Exit,
      FAPI_VIDEC_IsrDisplay0,
      FAPI_VIDEC_BsrDisplay0,
      0x800,
      0x100,
};


FAPI_SYS_DriverT FAPI_VIDEC_Driver1 = //21efc858
{
      "VIDEC0",
      18, //FAPI_INTR_AMCPU_AXP
      FAPI_SYS_BSR_EXEC_THREAD,
      FAPI_VIDEC_Init,
      FAPI_VIDEC_Exit,
      FAPI_VIDEC_IsrDecode0,
      FAPI_VIDEC_BsrDecode0,
      0x800,
      0x100,
};


int videcDriverIsInitialized = 0; //21f67030
int videcDriverLoadFirmwaresState = 0; //21f67034
int32_t videoDriverLoadFirmwareErrorCode = 0; //21f67038
uint32_t videc0HandleAllocated = 0; //21f67040
FAPI_SYS_SemaphoreT videcSemaphore = 0; //21f6703c
uint32_t fvm0la = 0; //21f67044
uint32_t fvm1la = 0; //21f67048
uint32_t fvm2la = 0; //21f6704c

uint32_t fvm0sz = 0; //21f67050
uint32_t fvm1sz = 0; //21f67054
uint32_t fvm2sz = 0; //21f67058

uint32_t fvh0la = 0; //21f6705c
uint32_t fvh1la = 0; //21f67060
uint32_t fvh2la = 0; //21f67064

uint32_t fvh0sz = 0; //21f67068
uint32_t fvh1sz = 0; //21f6706c
uint32_t fvh2sz = 0; //21f67070

FAPI_VIDEC_VideoDecoderMemoryDataT videcMemoryData[1]; //21f67074

FAPI_VIDEC_VideoDecoderHandleT videcHandles[1]; //21f67164

struct Struct_21bf62c8
{
   int fill_0[33788]; //0
   //135152
};

//struct Struct_21bf62c8
FAPI_VIDEC_VideoDecoderIsrDataT videcIsrData[1]; //21fbea84

FAPI_VIDEC_VideoDecoderHandleT* Data_21f67278; //21f67278


int fapi_videc_set_start_addresses(FAPI_VIDEC_VideoDecoderHandleT*);
int fapi_videc_boot_pcpu(FAPI_VIDEC_VideoDecoderHandleT*);
int32_t fapi_videc_update_buffer_info(FAPI_VIDEC_VideoDecoderIsrDataT*);
void fapi_videc_set_frame_info_fill_level(FAPI_VIDEC_VideoDecoderIsrDataT*);
void fapi_videc_set_aud_info_fill_level(FAPI_VIDEC_VideoDecoderIsrDataT*);
void func_21c4894c(FAPI_VIDEC_VideoDecoderIsrDataT*);
void fapi_videc_clear_aud_info_data(FAPI_VIDEC_VideoDecoderIsrDataT*);
void fapi_videc_clear_entropy_decoding_data(FAPI_VIDEC_VideoDecoderIsrDataT*);

static int32_t videcDriverLoadFirmwares(void);


/* 21c4e204 - todo */
void func_21c4e204(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
//   FAPI_SYS_PRINT_MSG("func_21c4e204\n");
}


static void func_21927d84(FAPI_VIDEC_VideoDecoderIsrDataT* isrDataPtr)
{
   //21c4eff8
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].serialNum=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].serialNum);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].displayFrameBank=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayFrameBank);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].displayWidth=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayWidth);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].displayHeight=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayHeight);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].decodedWidth=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedWidth);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].decodedHeight=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedHeight);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].displayOrderInfo=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].topFieldSerialNo=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topFieldSerialNo);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].botFieldSerialNo=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botFieldSerialNo);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].ptsValidFlag=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].ptsValidFlag);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].dtsValidFlag=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].dtsValidFlag);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].pts=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].pts);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].dts=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].dts);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].state=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].topDecError=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topDecError);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].botDecError=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botDecError);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].vdpbDispCount=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].vdpbDispCount);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].decodedPicAspectRatio=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedPicAspectRatio);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].activePicAspectRatioL0=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].activePicAspectRatioL0);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].activePicAspectRatioL1=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].activePicAspectRatioL1);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].afdUserDataActiveFormatFlag=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].afdUserDataActiveFormatFlag);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].currAfd=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].currAfd);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].codedInterlaceProggState=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].codedInterlaceProggState);
   FAPI_SYS_PRINT_DEBUG(6, "[VIDEC] func_21927d84: isrDataPtr->frameInfo.decodedPic[%d].readoutInterlaceProggState=%d\n",
         isrDataPtr->frameInfo.rPtr,
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].readoutInterlaceProggState);

   isrDataPtr->frameCrop.currAfd = //705360
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].currAfd; //84
   isrDataPtr->frameCrop.topFieldSerialNo = //705352
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topFieldSerialNo; //28
   isrDataPtr->frameCrop.botFieldSerialNo = //705356
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botFieldSerialNo; //32
   isrDataPtr->frameBank = //705304
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayFrameBank; //4
   isrDataPtr->frameDisplayOrderInfo = //705380
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo; //24
   isrDataPtr->frameTopFieldNo = //705384
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topFieldSerialNo; //28
   isrDataPtr->frameBotFieldNo = //705388
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botFieldSerialNo; //32
   isrDataPtr->frameSerialNum = //705392
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].serialNum; //0
   isrDataPtr->frameCrop.aspectRatio = //705308
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedPicAspectRatio; //68
   isrDataPtr->frameIdx = //705396
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].vdpbDispCount; //64
   isrDataPtr->frameCrop.activeAspectRatioL0 = //705312
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].activePicAspectRatioL0; //72
   isrDataPtr->frameCrop.codedInterlaceProggState = //705364
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].codedInterlaceProggState; //88
   isrDataPtr->frameCrop.activeAspectRatioL1 = //705316
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].activePicAspectRatioL1; //76
   isrDataPtr->frameCrop.readoutInterlaceProggState = //705368
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].readoutInterlaceProggState; //92
   isrDataPtr->frameCrop.mpegIFrameState = //705372
         isrDataPtr->mpegIFrameState; //188;

   if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedWidth != 0) //698760=16
   {
      //21c4f100
      if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedWidth <
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayWidth)
      {
         isrDataPtr->frameCrop.decodedWidth = //705344
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedWidth;
      }
      else
      {
         isrDataPtr->frameCrop.decodedWidth = //705344
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayWidth;
      }
   }
   else
   {
      //->21c4f72c
      isrDataPtr->frameCrop.decodedWidth = //705344
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayWidth; //8
      //->21c4f11c
   }
   //21c4f11c
   if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedHeight != 0) //698764=20
   {
      //21c4f144
      if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedHeight <
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayHeight)
      {
         isrDataPtr->frameCrop.decodedHeight = //705348
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedHeight;
      }
      else
      {
         isrDataPtr->frameCrop.decodedHeight = //705348
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayHeight;
      }
   }
   else
   {
      //->21c4f718
      isrDataPtr->frameCrop.decodedHeight = //705348
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayHeight; //698756=12
      //->21c4f160
   }
   //21c4f160
   isrDataPtr->vesInfo.displayWidth =
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayWidth;
   isrDataPtr->vesInfo.displayHeight =
      isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayHeight;

   if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 2)
   {
      //->21c4f908
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 3)
   {
      //->21c4f994
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 4)
   {
      //->21c4fa64
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 5)
   {
      //->21c4fa48
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 1;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 6)
   {
      //->21c4fae4
      isrDataPtr->frameCrop.frameField = 1;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 8)
   {
      //->21c50000
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 9)
   {
      //->21c4fa48
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 1;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 10)
   {
      //->21c4fae4
      isrDataPtr->frameCrop.frameField = 1;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo == 11)
   {
      //->21c4fae4
      isrDataPtr->frameCrop.frameField = 1;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   else
   {
      //21c4f1e0
      isrDataPtr->frameCrop.frameField = 0;
      isrDataPtr->frameCrop.fieldInversion = 0;
   }
   //21c4f1f4
   if ((isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topDecError != 0) ||
         (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botDecError != 0))
   {
      //->21c4f578
      isrDataPtr->frameDecError = //705400
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topDecError |
         isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botDecError;

      isrDataPtr->frameCrop.aspectRatio = //705308
            isrDataPtr->lkgFrameCrop.aspectRatio; //705112
      isrDataPtr->frameCrop.frameField = //705320
            isrDataPtr->lkgFrameCrop.frameField; //705124
      isrDataPtr->frameCrop.fieldInversion = //705324
            isrDataPtr->lkgFrameCrop.fieldInversion; //705128
      isrDataPtr->frameCrop.x0 = //705328
            isrDataPtr->lkgFrameCrop.x0; //705132
      isrDataPtr->frameCrop.y0 = //705332
            isrDataPtr->lkgFrameCrop.y0; //705136
      isrDataPtr->frameCrop.displayWidth = //705336
            isrDataPtr->lkgFrameCrop.displayWidth; //705140
      isrDataPtr->frameCrop.displayHeight = //705340
            isrDataPtr->lkgFrameCrop.displayHeight; //705144
      isrDataPtr->frameCrop.decodedWidth = //705344
            isrDataPtr->lkgFrameCrop.decodedWidth; //705148
      isrDataPtr->frameCrop.decodedHeight = //705348
            isrDataPtr->lkgFrameCrop.decodedHeight; //705152
      isrDataPtr->frameCrop.topFieldSerialNo = //705352
            isrDataPtr->lkgFrameCrop.topFieldSerialNo; //705156
      isrDataPtr->frameCrop.botFieldSerialNo = //705356
            isrDataPtr->lkgFrameCrop.botFieldSerialNo; //705160
      isrDataPtr->frameCrop.currAfd = //705360
            isrDataPtr->lkgFrameCrop.currAfd; //705164
      isrDataPtr->frameCrop.mpegIFrameState = //705372
            isrDataPtr->lkgFrameCrop.mpegIFrameState; //705176

      isrDataPtr->frameCrop.frameIdx = //705376
            isrDataPtr->frameIdx; //705396
   }
   else
   {
      //21c4f230
      isrDataPtr->frameDecError = 0;

      isrDataPtr->lkgFrameCrop.aspectRatio = //705112
            isrDataPtr->frameCrop.aspectRatio; //705308
      isrDataPtr->lkgFrameCrop.frameField = //705124
            isrDataPtr->frameCrop.frameField; //705320
      isrDataPtr->lkgFrameCrop.fieldInversion = //705128
            isrDataPtr->frameCrop.fieldInversion; //705324
      isrDataPtr->lkgFrameCrop.x0 = //705132
            isrDataPtr->frameCrop.x0; //705328
      isrDataPtr->lkgFrameCrop.y0 = //705136
            isrDataPtr->frameCrop.y0; //705332
      isrDataPtr->lkgFrameCrop.displayWidth = //705140
            isrDataPtr->frameCrop.displayWidth; //705336
      isrDataPtr->lkgFrameCrop.displayHeight = //705144
            isrDataPtr->frameCrop.displayHeight; //705340
      isrDataPtr->lkgFrameCrop.decodedWidth = //705148
            isrDataPtr->frameCrop.decodedWidth; //705344
      isrDataPtr->lkgFrameCrop.decodedHeight = //705152
            isrDataPtr->frameCrop.decodedHeight; //705348
      isrDataPtr->lkgFrameCrop.topFieldSerialNo = //705156
            isrDataPtr->frameCrop.topFieldSerialNo; //705352
      isrDataPtr->lkgFrameCrop.botFieldSerialNo = //705160
            isrDataPtr->frameCrop.botFieldSerialNo; //705356
      isrDataPtr->lkgFrameCrop.currAfd = //705164
            isrDataPtr->frameCrop.currAfd; //705360
      isrDataPtr->lkgFrameCrop.mpegIFrameState = //705176
            isrDataPtr->frameCrop.mpegIFrameState; //705372

      isrDataPtr->frameCrop.frameIdx = //705376
            isrDataPtr->frameIdx; //705396
   }
   //21c4f340
   isrDataPtr->frameCrop.x0 = 0; //705328
   isrDataPtr->frameCrop.y0 = 0; //705332
   isrDataPtr->frameCrop.displayWidth = //705336
         isrDataPtr->frameCrop.decodedWidth; //705344
   isrDataPtr->frameCrop.displayHeight = //705340
         isrDataPtr->frameCrop.decodedHeight; //705348

   isrDataPtr->pctInfo.nextFrameInfo.aspectRatio = //705228
         isrDataPtr->frameCrop.aspectRatio; //705308
   isrDataPtr->pctInfo.nextFrameInfo.frameField = //705232
         isrDataPtr->frameCrop.frameField; //705320
   isrDataPtr->pctInfo.nextFrameInfo.fieldInversion = //705236
         isrDataPtr->frameCrop.fieldInversion; //705324
   isrDataPtr->pctInfo.nextFrameInfo.decodedWidth = //705240
         isrDataPtr->frameCrop.decodedWidth; //705344
   isrDataPtr->pctInfo.nextFrameInfo.decodedHeight = //705244
         isrDataPtr->frameCrop.decodedHeight; //705348

   if ((isrDataPtr->pctInfo.lastFrameInfo.aspectRatio != isrDataPtr->pctInfo.nextFrameInfo.aspectRatio) ||
         (isrDataPtr->pctInfo.lastFrameInfo.frameField != isrDataPtr->pctInfo.nextFrameInfo.frameField) ||
         (isrDataPtr->pctInfo.lastFrameInfo.fieldInversion != isrDataPtr->pctInfo.nextFrameInfo.fieldInversion) ||
         (isrDataPtr->pctInfo.lastFrameInfo.decodedWidth != isrDataPtr->pctInfo.nextFrameInfo.decodedWidth) ||
         (isrDataPtr->pctInfo.lastFrameInfo.decodedHeight != isrDataPtr->pctInfo.nextFrameInfo.decodedHeight))
   {
      //21c4f3c4
      isrDataPtr->pctInfo.paramChangeTrigger = 1;

      if (isrDataPtr->paramChangeCbk != NULL)
      {
         (isrDataPtr->paramChangeCbk)(
               &isrDataPtr->pctInfo.nextFrameInfo,
               &isrDataPtr->pctInfo.lastFrameInfo,
               isrDataPtr->paramChangeOptData);

         isrDataPtr->pctInfo.paramChangeTrigger = 0;
      }
   }
   //21c4f404
   isrDataPtr->pctInfo.lastFrameInfo.aspectRatio =
      isrDataPtr->pctInfo.nextFrameInfo.aspectRatio;
   isrDataPtr->pctInfo.lastFrameInfo.frameField =
      isrDataPtr->pctInfo.nextFrameInfo.frameField;
   isrDataPtr->pctInfo.lastFrameInfo.fieldInversion =
      isrDataPtr->pctInfo.nextFrameInfo.fieldInversion;
   isrDataPtr->pctInfo.lastFrameInfo.decodedWidth =
      isrDataPtr->pctInfo.nextFrameInfo.decodedWidth;
   isrDataPtr->pctInfo.lastFrameInfo.decodedHeight =
      isrDataPtr->pctInfo.nextFrameInfo.decodedHeight;
}


/* 21c4eb88 - todo */
uint32_t FAPI_VIDEC_IsrDisplay0(void)
{
   FAPI_VIDEC_VideoDecoderIsrDataT* isrDataPtr;
   uint32_t r9 = 0;
   
   FAPI_SYS_PRINT_DEBUG(5, "FAPI_VIDEC_IsrDisplay0\n");
   
   FREG_VO_SetDispirqctrl_Dispirq0(0);
   
   if (Data_21f67278 == 0)
   {
      //->21c4eda0
      return r9;
   }

   isrDataPtr = Data_21f67278->isrDataPtr;
   
   if ((isrDataPtr == 0) || (isrDataPtr->inUse == 0))
   {
      //->21c4eda0
      return r9;
   }
   //21c4ebc0
   if ((isrDataPtr->startStopState != FAPI_VIDEC_REQUEST_TO_STOP) &&
         (0 != func_21c2f890()))
   {
      r9 = (uint32_t) Data_21f67278;
   }
   //21c4ebe0
   isrDataPtr->currIsrTimeUsec = FAPI_TIMER_GetTimeStamp(1);
   
   isrDataPtr->isrCurrField = FREG_VO_GetDisppicpos_Currentfield();
   isrDataPtr->isrNextField = 1 - isrDataPtr->isrCurrField;
   
   if (isrDataPtr->enableDisableState == FAPI_VIDEC_REQUEST_TO_FORCE_ENABLE)
   {
      //->21c4eda8
      if (isrDataPtr->isrCurrField == 1)
      {
         FREG_VO_SetVolayerenable_Layerenable(1);
         
         isrDataPtr->enableDisableState = FAPI_VIDEC_FORCE_ENABLED;
      }
      //21c4ec10
   }
   else if (isrDataPtr->enableDisableState == FAPI_VIDEC_REQUEST_TO_FORCE_DISABLE)
   {
      //->21c4edc0
      if (isrDataPtr->isrCurrField == 1)
      {
         FREG_VO_SetVolayerenable_Layerenable(0);
         
         isrDataPtr->enableDisableState = FAPI_VIDEC_FORCE_DISABLED;
      }
      //21c4ec10
   }
   //21c4ec10
   if ((isrDataPtr->bootState == FAPI_VIDEC_BOOTED) &&
      (isrDataPtr->resetState == FAPI_VIDEC_NOT_RESET) &&
         ((isrDataPtr->startStopState == FAPI_VIDEC_STARTED) ||
         (isrDataPtr->startStopState == FAPI_VIDEC_REQUEST_TO_STOP) ||
         (isrDataPtr->mpegIFrameState != FAPI_VIDEC_NON_MPEG_IFRAME_STATE)))
   {
      //21c4ec44
      fapi_videc_set_aud_info_fill_level(isrDataPtr);
      fapi_videc_set_frame_info_fill_level(isrDataPtr);
      
      if (FAPI_VIDEC_ERR_VES_BUFFER_OVERFLOW == 
         fapi_videc_update_buffer_info(isrDataPtr))
      {
         //->21c4ee24
         if (isrDataPtr->vesOverflowCbk != 0)
         {
            (isrDataPtr->vesOverflowCbk)(isrDataPtr->vesOverflowOptData);
         }
      }
      //21c4ec68
      FAPI_SYS_PRINT_DEBUG(6, "isrDataPtr->frameStartDisplay=%d\n",
            isrDataPtr->frameStartDisplay);
      
      if (isrDataPtr->frameStartDisplay == 0) //r1
      {
         FAPI_SYS_PRINT_DEBUG(6, "isrDataPtr->pmcrInfo.targetPlaybackMode=%d\n",
               isrDataPtr->pmcrInfo.targetPlaybackMode);
         
         //->21c4eddc
         if (isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE/*1*/) //r0
         {
            //->21c4f550
            if (isrDataPtr->mpegIFrameState == FAPI_VIDEC_NON_MPEG_IFRAME_STATE) //0)
            {
               //21c4f55c
               if (isrDataPtr->frameInfo.fillLevel > 0)
               {
                  //21c4f56c
                  //r9 = 0; //r1
                  isrDataPtr->frameStartDisplay = 1;
                  //->21c4ed94
                  return 0; //r9;
               }
               //21c4ec80
            }
            else
            {
               //21c4f6a0
               if (isrDataPtr->frameInfo.fillLevel >= 0)
               {
                  //21c4f56c
                  //r9 = 0; //r1
                  isrDataPtr->frameStartDisplay = 1;
                  //->21c4ed94
                  return 0; //r9;
               }
               //21c4ec80
            }
         } //if (isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE)
         //21c4edec
         else if (isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE) //2
         {
            //->21c4ee44
            if (isrDataPtr->frameInfo.fillLevel >= 0)
            {
               isrDataPtr->frameStartDisplay = 1;
               //21c4ee5c
            }
            //21c4ec80
         } //else if (isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE)
         //21c4edf4
         else if (isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE) //3
         {
            //->21c4f6b4
            if (isrDataPtr->mpegIFrameState == FAPI_VIDEC_NON_MPEG_IFRAME_STATE)
            {
               //->21c4edfc
               if (isrDataPtr->frameInfo.fillLevel > 0)
               {
                  //21c4ee0c
                  //r9 = 0;
                  isrDataPtr->frameStartDisplay = 1;
                  //->21c4ed94
                  return 0; //r9;
               }
               //21c4ec80
            }
            else
            {
               //21c4f6c0
               if (isrDataPtr->frameInfo.fillLevel >= 0)
               {
                  //->21c4ee0c
                  //r9 = 0;
                  isrDataPtr->frameStartDisplay = 1;
                  //->21c4ed94
                  return 0; //r9;
               }
               //21c4ec80
            }
         } //else if (isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE)
         else
         {
            //21c4edfc
            if (isrDataPtr->frameInfo.fillLevel > 0)
            {
               //21c4ee0c
               //r9 = 0;
               isrDataPtr->frameStartDisplay = 1;
               //->21c4ed94
               return 0; //r9;
            }
            //21c4ec80
         }
      } //if (isrDataPtr->frameStartDisplay == 0) //r1
      //21c4ec78
      /*else*/ if (isrDataPtr->frameStartDisplay == 1)
      {
         //->21c4ee5c
         FAPI_SYS_PRINT_DEBUG(6, "isrDataPtr->frameDisplayOrderInfo=%d\n",
               isrDataPtr->frameDisplayOrderInfo/*705380*/);

         if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 2)
         {
            //21c4f6d4
            if (isrDataPtr->decoderPlaybackMode == 0)
            {
               //21c4eeac
            }
            else if ((isrDataPtr->decoderPlaybackMode == 1) ||
                  (isrDataPtr->decoderPlaybackMode == 2) ||
                  (isrDataPtr->decoderPlaybackMode == 3) ||
                  (isrDataPtr->decoderPlaybackMode == 4))
            {
               //21c4f6ec
               if (isrDataPtr->frameState == 10)
               {
                  isrDataPtr->frameState = 9;
                  //->21c4f70c
                  func_21c4e204(isrDataPtr);
                  //21c4eeac
               }
               else if (isrDataPtr->frameState == 9)
               {
                  //21c4f70c
                  func_21c4e204(isrDataPtr);
                  //21c4eeac
               }
               //21c4eeac
            }
            else
            {
               //21c4fab8
               if (isrDataPtr->frameState == 2)
               {
                  //21c4eeac
               }
               else 
               {
                  //21c4fac8
                  isrDataPtr->frameState--;
                  
                  if (isrDataPtr->frameState == 9)
                  {
                     func_21c4e204(isrDataPtr);
                  }
                  //21c4eeac
               }
            }
         } //if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 2)
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 3)
         {
            //21c4f740
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 4)
         {
            //21c4f8d0
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 5)
         {
            //21c4f95c
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 6)
         {
            //21c4f9f4
            if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_PLAYBACK_PAUSE) //0)
            {
               //21c4eeac
            }
            else if ((isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE/*1*/) ||
                  (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE/*2*/) ||
                  (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE/*3*/) ||
                  (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_AND_P_ONLY_PLAYBACK_MODE/*4*/))
            {
               //21c4fa0c
               if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_FRAME_2_VSYNC) //11)
               {
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC; //10;
                  //21c4eeac
               }
               if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC) //10)
               {
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_0_VSYNC; //9;
                  //->21c4fa3c
                  func_21c4e204(isrDataPtr);
                  //21c4eeac
               }
               else if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_FRAME_0_VSYNC) //9)
               {
                  //21c4fa3c
                  func_21c4e204(isrDataPtr);
                  //21c4eeac
               }
               //21c4eeac
            }
            else
            {
               //21c5010c
               if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_START) //2)
               {
                  //21c4eeac
               }
               else 
               {
                  //21c5011c
                  isrDataPtr->frameState--;
                  
                  if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_FRAME_0_VSYNC) //9)
                  {
                     //21c5012c
                     func_21c4e204(isrDataPtr);
                  }
                  //21c4eeac
               }
            }
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 8)
         {
            //21c4fc48
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 9)
         {
            //21c4febc
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 10)
         {
            //21c4ff48
         }
         else if (isrDataPtr->frameDisplayOrderInfo/*705380*/ == 11)
         {
            //21c50138
         }
         //21c4eeac / 21929c14
         FAPI_SYS_PRINT_DEBUG(6, "isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state=%d\n",
               isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state);

         if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state //698796
               == FAPI_VIDEC_FRAME_DECODED)
         {
            //21c4eed4
            if (isrDataPtr->videoDecInfoCbk != 0)
            {
               //21c4eee8
               isrDataPtr->videoDecInfoData.rPtr = isrDataPtr->frameInfo.rPtr;
               isrDataPtr->videoDecInfoData.serialNum =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].serialNum;
               isrDataPtr->videoDecInfoData.frameBank =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayFrameBank;
               isrDataPtr->videoDecInfoData.displayWidth =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayWidth;
               isrDataPtr->videoDecInfoData.displayHeight =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayHeight;
               isrDataPtr->videoDecInfoData.decodedWidth =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedWidth;
               isrDataPtr->videoDecInfoData.decodedHeight =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].decodedHeight;
               isrDataPtr->videoDecInfoData.displayOrderInfo =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].displayOrderInfo;
               isrDataPtr->videoDecInfoData.topFieldSerialNo =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].topFieldSerialNo;
               isrDataPtr->videoDecInfoData.botFieldSerialNo =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].botFieldSerialNo;
               isrDataPtr->videoDecInfoData.ptsValidFlag =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].ptsValidFlag;
               isrDataPtr->videoDecInfoData.dtsValidFlag =
                  isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].dtsValidFlag;
               long long bla = isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].pts;
               isrDataPtr->videoDecInfoData.pts = bla+bla;
               bla = isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].dts;
               isrDataPtr->videoDecInfoData.dts = bla+bla;

               (isrDataPtr->videoDecInfoCbk)(&isrDataPtr->videoDecInfoData,
                     isrDataPtr->videoOptData);
            } //if (isrDataPtr->videoDecInfoCbk != 0)
            //21c4eff8            
            func_21927d84(isrDataPtr);
            
            isrDataPtr->frameState = //705300
               FAPI_VIDEC_FRAME_DISPLAY_START;
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state = //698796
               FAPI_VIDEC_FRAME_DISPLAY_START;
         } //if (isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state == FAPI_VIDEC_FRAME_DECODED)
         //21c4f480
         if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_START)
         {
            //21c4f490
            FAPI_SYS_PRINT_DEBUG(4, "21c4f490: isrDataPtr->pecrInfo.playbackEnvironmentChangeReqState=%d\n",
                  isrDataPtr->pecrInfo.playbackEnvironmentChangeReqState);

            if (isrDataPtr->pecrInfo.playbackEnvironmentChangeReqState == 1) //705184 == 1)
            {
               //->21c4f9cc
               isrDataPtr->decoderPlaybackEnvironment = //152
                  isrDataPtr->pecrInfo.currPlaybackEnvironment =
                     isrDataPtr->pecrInfo.targetPlaybackEnvironment; //705192

               if (isrDataPtr->decoderPlaybackEnvironment == FAPI_VIDEC_PVR_PLAYBACK_ENVIRONMENT) //1)
               {
                  //->21c500a8
                  isrDataPtr->pvrInfo.pts = 0; //705216
                  isrDataPtr->pvrInfo.setPtsToStc = 0; //705208
               }
               //21c4f9e8
               isrDataPtr->pecrInfo.playbackEnvironmentChangeReqState = 0;
               //21c4f4a0
            }
            //21c4f4a0
            FAPI_SYS_PRINT_DEBUG(4, "21c4f4a0: isrDataPtr->pmcrInfo.playbackModeChangeReqState=%d\n",
                  isrDataPtr->pmcrInfo.playbackModeChangeReqState);

            if (isrDataPtr->pmcrInfo.playbackModeChangeReqState == 1) //705196 == 1)
            {
               //->21c4f9ac
               isrDataPtr->decoderPlaybackMode = //156
                  isrDataPtr->pmcrInfo.currPlaybackMode =
                     isrDataPtr->pmcrInfo.targetPlaybackMode; //705204
               
               isrDataPtr->pmcrInfo.playbackModeChangeReqState = 0;
            }
            //21c4f4b0
            FAPI_SYS_PRINT_DEBUG(4, "21c4f4b0: isrDataPtr->frameDisplayOrderInfo=%d\n",
                  isrDataPtr->frameDisplayOrderInfo);

            if (isrDataPtr->frameDisplayOrderInfo == 2)
            {
               //->21c4fd78
               FREG_VO_SetFramoffset_Frameoffset(isrDataPtr->frameBank);
               FREG_VO_SetVomode_Vofieldmode(1);
               FREG_VO_SetVomode_Voprogr(1);
               FREG_VO_SetVomode_Vofield(0);
               
               if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_PLAYBACK_PAUSE) //0)
               {
                  //->21c4fef4
                  //r2 = 10;
                  //->21c4fdec
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC; //10;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE) //1)
               {
                  //->21c505c4
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC; //10;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE) //2)
               {
                  //->21c4fef4
                  //r2 = 10;
                  //->21c4fdec
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC; //10;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE) //3)
               {
                  //->21c4fef4
                  //r2 = 10;
                  //->21c4fdec
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC; //10;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_AND_P_ONLY_PLAYBACK_MODE) //4)
               {
                  //->21c4fef4
                  //r2 = 10;
                  //->21c4fdec
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC; //10;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_2X_PLAYBACK_MODE) //5)
               {
                  //21c4fdcc
                  //r2 = 11;
                  //->21c4fdec
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_2_VSYNC; //11;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_4X_PLAYBACK_MODE) //6)
               {
                  //21c4fdd8
                  //r2 = 13;
                  //->21c4fdec
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_4_VSYNC; //13;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_8X_PLAYBACK_MODE) //7)
               {
                  //21c4fde8
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_8_VSYNC; //17;
                  isrDataPtr->frameFieldState = FAPI_VIDEC_TOP_FIELD_FREEZE_STATE; //1;
                  //->21c4f814
               }
               //->21c4f814
               isrDataPtr->invokeAutoScalers = 1; //705408
            } //if (isrDataPtr->frameDisplayOrderInfo == 2)
            else if (isrDataPtr->frameDisplayOrderInfo == 3)
            {
               //->21c4fe04
            }
            else if (isrDataPtr->frameDisplayOrderInfo == 4)
            {
               //->21c4f784
            }
            else if (isrDataPtr->frameDisplayOrderInfo == 5)
            {
               //->21c4fce8
            }
            else if (isrDataPtr->frameDisplayOrderInfo == 6)
            {
               //->21c4fefc
               FAPI_SYS_PRINT_DEBUG(4, "21c4fefc: isrDataPtr->decoderPlaybackMode=%d\n",
                     isrDataPtr->decoderPlaybackMode);

               if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_PLAYBACK_PAUSE) //0)
               {
                  //21c4ff08
                  if (isrDataPtr->frameCrop.decodedHeight >= 1024)
                  {
                     //21c4ff18
                     isrDataPtr->frameCrop.frameField = 0; //705320
                     
                     FREG_VO_SetVomode_Vofieldmode(1);
                     FREG_VO_SetVomode_Voprogr(1);
                     FREG_VO_SetVomode_Vofield(0);
                  }
                  else
                  {
                     //21c50504
                     isrDataPtr->frameCrop.frameField = 1; //705320
                     
                     FREG_VO_SetVomode_Vofieldmode(1);
                     FREG_VO_SetVomode_Voprogr(0);
                     FREG_VO_SetVomode_Vofield(0);
                     //->21c4ff38
                  }
                  //21c4ff38
                  FREG_VO_SetFramoffset_Frameoffset(isrDataPtr->frameBank);
                  //->21c4f814
               }
               //21c50318
               else if ((isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE/*1*/) ||
                     (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE/*2*/) ||
                     (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE/*3*/) ||
                     (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_AND_P_ONLY_PLAYBACK_MODE/*4*/))
               {
                  //21c50324
                  FAPI_SYS_PRINT_DEBUG(4, "isrDataPtr->vesInfo.vesFrameRate=%d\n",
                        isrDataPtr->vesInfo.vesFrameRate);

                  if (isrDataPtr->vesInfo.vesFrameRate == 2397)
                  {
                     //->21c509d8
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 2400)
                  {
                     //->21c509d8
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 2500)
                  {
                     //->21c50c54
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 2997)
                  {
                     //->21c50ac0
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 3000)
                  {
                     //->21c50c54
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 5000)
                  {
                     //->21c50970
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 5994)
                  {
                     //->21c50970
                  }
                  else if (isrDataPtr->vesInfo.vesFrameRate == 6000)
                  {
                     //->21c50970
                  }
                  else
                  {
                     //21c50384
                     if (isrDataPtr->isrCurrField == 1)
                     {
                        //21c50390
                        FREG_VO_SetFramoffset_Frameoffset(isrDataPtr->frameBank);
                     
                        isrDataPtr->frameCrop.frameField = 0; //r4
                        
                        FREG_VO_SetVomode_Vofieldmode(1);
                        FREG_VO_SetVomode_Voprogr(1);
                        FREG_VO_SetVomode_Vofield(0);
                        
                        isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_2_VSYNC; //11;
                     }
                     //->21c4f814
                  }
               }
               //21c50440
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_2X_PLAYBACK_MODE) //5)
               {
                  //->21c50e90
                  //TODO
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_4X_PLAYBACK_MODE) //6)
               {
                  //->21c50d5c
                  //TODO
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_8X_PLAYBACK_MODE) //7)
               {
                  //->21c50458
                  //TODO
               }
               //->21c4f814
               isrDataPtr->invokeAutoScalers = 1; //705408
            } //else if (isrDataPtr->frameDisplayOrderInfo == 6)
            else if (isrDataPtr->frameDisplayOrderInfo == 8)
            {
               //->21c50054
            }
            else if (isrDataPtr->frameDisplayOrderInfo == 9)
            {
               //->21c50204
            }
            else if (isrDataPtr->frameDisplayOrderInfo == 10)
            {
               //->21c50664
            }
            else if (isrDataPtr->frameDisplayOrderInfo == 11)
            {
               //->21c50714
               FREG_VO_SetFramoffset_Frameoffset(isrDataPtr->frameBank);
               FREG_VO_SetVomode_Vofieldmode(1);
               FREG_VO_SetVomode_Voprogr(0);
               FREG_VO_SetVomode_Vofield(0);
               
               if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_PLAYBACK_PAUSE) //0)
               {
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE) //1)
               {
                  //->21c50c44
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_3_VSYNC; //12;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE) //2)
               {
                  //->21c50c44
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_3_VSYNC; //12;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE) //3)
               {
                  //->21c50c44
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_3_VSYNC; //12;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_I_AND_P_ONLY_PLAYBACK_MODE) //4)
               {
                  //->21c50c44
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_3_VSYNC; //12;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_2X_PLAYBACK_MODE) //5)
               {
                  //21c50768
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_6_VSYNC; //15;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_4X_PLAYBACK_MODE) //6)
               {
                  //21c5077c
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_12_VSYNC; //21;
                  //->21c4f814
               }
               else if (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_8X_PLAYBACK_MODE) //7)
               {
                  //21c50790
                  isrDataPtr->frameState = FAPI_VIDEC_FRAME_DISPLAY_FRAME_24_VSYNC; //33;
                  //->21c4f814
               }
               //->21c4f814
               isrDataPtr->invokeAutoScalers = 1; //705408
            } //else if (isrDataPtr->frameDisplayOrderInfo == 11)
            //21c4f500
            if (isrDataPtr->invokeAutoScalers == 1) //705408
            {
               //->21c4f820
               isrDataPtr->invokeAutoScalers = 0; //705408
               
               if ((isrDataPtr->hdAutoScaleCbk != 0) &&
                     (isrDataPtr->hdScalerHandle != 0))
               {
                  //21c4f84c
                  (isrDataPtr->hdAutoScaleCbk)(&isrDataPtr->frameCrop,
                        isrDataPtr->hdScalerHandle, 0);
               }
               //21c4f858
               if ((isrDataPtr->sdAutoScaleCbk != 0) &&
                     (isrDataPtr->sdScalerHandle != 0))
               {
                  //2192b7a4
                  (isrDataPtr->sdAutoScaleCbk)(&isrDataPtr->frameCrop,
                        isrDataPtr->sdScalerHandle, 0);
               }
               //21c4f510
            }
            //21c4f510
            if (isrDataPtr->enableDisableState == FAPI_VIDEC_REQUEST_TO_SYNCHRONIZE_ENABLE) //0)
            {
               //->21c4f920
               FREG_VO_SetVolayerenable_Layerenable(1);
               
               isrDataPtr->enableDisableState = FAPI_VIDEC_SYNCHRONIZE_ENABLED; //2
               //21c4f930
            }
            if (isrDataPtr->enableDisableState == FAPI_VIDEC_SYNCHRONIZE_ENABLED) //2)
            {
               //->21c4f930
               if (isrDataPtr->frameAvailableCbk != NULL)
               {
                  (isrDataPtr->frameAvailableCbk)(isrDataPtr->frameAvailableOptData);
                  
                  isrDataPtr->frameAvailableCbk = NULL;
                  isrDataPtr->frameAvailableOptData = NULL;
               }
            }
            //21c4f524
            isrDataPtr->frameInfo.decodedPic[isrDataPtr->frameInfo.rPtr].state =
               isrDataPtr->frameState;
            //->21c4ec80                        
         } //if (isrDataPtr->frameState == FAPI_VIDEC_FRAME_DISPLAY_START)
         //21c4ec80
      } //if (isrDataPtr->frameStartDisplay == 1)
      //21c4ec80
      if ((isrDataPtr->decoderPlaybackEnvironment == FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT) &&
            (isrDataPtr->mpegIFrameState == FAPI_VIDEC_NON_MPEG_IFRAME_STATE) &&
            (isrDataPtr->decoderPlaybackMode == FAPI_VIDEC_NORMAL_PLAYBACK_MODE))
      {
         //21c4eca4
         isrDataPtr->Data_44 = FAPI_TIMER_GetTimeStamp(1000) -
            isrDataPtr->Data_12;
         
         isrDataPtr->Data_52 = FAPI_TIMER_GetTimeStamp(1000) -
            isrDataPtr->currVcpbDecTimeMsec;
         
         isrDataPtr->Data_60 = FAPI_TIMER_GetTimeStamp(1000) -
            isrDataPtr->Data_28;
         
         if (isrDataPtr->Data_44 < 2000)
         {
            //21c4ed38
            isrDataPtr->Data_200 = 1;
         }
         else
         {
            //21c4ee1c
            isrDataPtr->Data_200 = 0;
         }
         //21c4ed40
         if (isrDataPtr->Data_44 >= 3000)
         {
            //21c4ed5c
            isrDataPtr->healthState = FAPI_VIDEC_DEAD;
         }
         //->21c4fb00
         else if (isrDataPtr->Data_52 >= 3000)
         {
            //21c4fb0c
            isrDataPtr->healthState = FAPI_VIDEC_BAD_HEALTH_L2;
         }
         //21c4ffd4
         else if (isrDataPtr->Data_60 >= 3000)
         {
            //21c4fff4
            isrDataPtr->healthState = FAPI_VIDEC_BAD_HEALTH_L1;
         }
         //21c50288
         else if (isrDataPtr->frameDecError != 0) //705400
         {
            isrDataPtr->healthState = FAPI_VIDEC_BAD_HEALTH_L0;
         }
         else
         {
            isrDataPtr->healthState = FAPI_VIDEC_GOOD_HEALTH;
         }
         //21c4ed64
      }
      //21c4ed64
   }
   //21c4ed64
   isrDataPtr->isrSerialIdx++;
   
   isrDataPtr->Data_36 = FAPI_TIMER_GetTimeStamp(1) -
      isrDataPtr->currIsrTimeUsec;
   
   return r9;
}


/* 21c4d380 - todo */
void func_21c4d380(void)
{
   FAPI_SYS_PRINT_MSG("func_21c4d380\n");
}


/* 21c4e1a4 - complete */
void FAPI_VIDEC_BsrDisplay0(uint32_t a)
{
//   FAPI_SYS_PRINT_MSG("FAPI_VIDEC_BsrDisplay0\n");
   
   FAPI_VIDEC_VideoDecoderHandleT* h = (void*) a;
   
   if (h != 0)
   {
      videc_lock();
      
      if (checkHandle(h) && 
            (h->isrDataPtr != 0) &&
            (h->isrDataPtr->startStopState == FAPI_VIDEC_STARTED))
      {
         if ((h->isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_2X_PLAYBACK_MODE) ||
               (h->isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_4X_PLAYBACK_MODE) ||
               (h->isrDataPtr->pmcrInfo.targetPlaybackMode == FAPI_VIDEC_SLOW_FORWARD_8X_PLAYBACK_MODE))
         {
            func_21c4d380();
         }
      }
      
      videc_unlock();
   }
}


struct Struct_1280 
{
   uint32_t Data_0; //0
   uint32_t Data_4; //4
   uint32_t Data_8; //8
   uint32_t Data_12; //12
   uint32_t Data_16; //16
   uint32_t Data_20; //20
   uint32_t Data_24; //24
   uint32_t Data_0x1c; //28
   uint32_t Data_0x20; //32
   uint32_t Data_0x24; //36
   uint32_t Data_0x28; //40
   uint32_t Data_0x2c; //44
   uint32_t Data_0x30; //48
   uint32_t Data_0x34; //52
   uint32_t Data_0x38; //56
   uint32_t Data_0x3c; //60
   uint32_t Data_0x40; //64
   uint32_t Data_0x44; //68
   uint32_t Data_0x48; //72
   uint32_t Data_0x4c; //76
   uint32_t Data_0x50; //80
   uint32_t Data_0x54; //84
   uint32_t Data_0x58; //88
   uint32_t Data_0x5c; //92
   uint32_t Data_0x60; //96
   uint32_t Data_0x64; //100
   uint32_t Data_0x68; //104
   uint32_t Data_0x6c; //108
   uint32_t Data_0x70; //112
   uint32_t Data_0x74; //116
   uint32_t Data_0x78; //120
   uint32_t Data_0x7c; //124
   uint32_t Data_0x80; //128
   uint32_t Data_0x84; //132
   uint32_t Data_0x88; //136
   uint32_t Data_0x8c; //140
   uint32_t Data_0x90; //144
   uint32_t Data_0x94; //148
   uint32_t Data_0x98; //152
   uint32_t Data_0x9c; //156
   uint32_t Data_0xa0; //160
   uint32_t Data_0xa4; //164
   uint32_t Data_0xa8; //168
   uint32_t Data_0xac; //172
   uint32_t Data_0xb0; //176
   uint32_t Data_0xb4; //180
   uint32_t Data_0xb8; //184
   uint32_t Data_0xbc; //188
   uint32_t Data_0xc0; //192
   uint32_t Data_0xc4; //196
   uint32_t Data_0xc8; //200
   uint32_t Data_0xcc; //204
   uint32_t Data_0xd0; //208
   uint32_t Data_0xd4; //212
   uint32_t Data_0xd8; //216
   uint32_t Data_0xdc; //220
   uint32_t Data_0xe0; //224
   uint32_t Data_0xe4; //228
   uint32_t Data_0xe8; //232
   uint32_t Data_0xec; //236
   uint32_t Data_0xf0; //240
   uint32_t Data_0xf4; //244
   uint32_t Data_0xf8; //248
   uint32_t Data_0xfc; //252
   uint32_t Data_0x100; //256
   uint32_t Data_0x104; //260
   uint32_t Data_0x108; //264
   uint32_t Data_0x10c; //268
   uint32_t Data_0x110; //272
   uint32_t Data_0x114; //276
   uint32_t Data_0x118; //280
   uint32_t Data_0x11c; //284
   uint32_t Data_0x120; //288
   uint32_t Data_0x124; //292
   uint32_t Data_0x128; //296
   uint32_t Data_0x12c; //300
   uint32_t Data_0x130; //304
   uint32_t Data_0x134; //308
   uint32_t Data_0x138; //312
   uint32_t Data_0x13c; //316
   uint32_t Data_0x140; //320
   uint32_t Data_0x144; //324
   uint32_t Data_0x148; //328
   uint32_t Data_0x14c; //332
   uint32_t Data_0x150; //336
   uint32_t Data_0x154; //340
   uint32_t Data_0x158; //344
   uint32_t Data_0x15c; //348
   uint32_t Data_0x160; //352
   uint32_t Data_0x164; //356
   uint32_t Data_0x168; //360
   uint32_t Data_0x16c; //364
   uint32_t Data_0x170; //368
   uint32_t Data_0x174; //372
   uint32_t Data_0x178; //376
   uint32_t Data_0x17c; //380
   uint32_t Data_0x180; //384
   uint32_t Data_0x184; //388
   int fill_0x188; //0x188
   int fill_0x18c; //0x18c
   uint32_t Data_0x190; //0x190
   uint32_t Data_0x194; //0x194
   uint32_t Data_0x198; //0x198
   uint32_t Data_0x19c; //0x19c
   uint32_t Data_0x1a0; //0x1a0
   uint32_t Data_0x1a4; //0x1a4
   uint32_t Data_0x1a8; //0x1a8
   uint32_t Data_0x1ac; //0x1ac
   uint32_t Data_0x1b0; //0x1b0
   uint32_t Data_0x1b4; //0x1b4
   uint32_t Data_0x1b8; //0x1b8
   uint32_t Data_0x1bc; //0x1bc
   uint32_t Data_0x1c0; //0x1c0
   uint32_t Data_0x1c4; //0x1c4
   uint32_t Data_0x1c8; //0x1c8
   uint32_t Data_0x1cc; //0x1cc
   uint32_t Data_0x1d0; //0x1d0
   int fill_0x1d4[7]; //0x1d4  
   uint32_t Data_0x1f0; //0x1f0
   uint32_t Data_0x1f4; //0x1f4
   uint32_t Data_0x1f8; //0x1f8
   uint32_t Data_0x1fc; //0x1fc
   uint32_t Data_0x200; //0x200
   uint32_t Data_0x204; //0x204
   uint32_t Data_0x208; //0x208
   int fill_0x20c; //0x20c
   uint32_t Data_0x210; //0x210
   int fill_0x214[3]; //0x214
   uint32_t Data_0x220; //0x220
   int fill_0x224[3]; //0x224
   uint32_t Data_0x230; //0x230
   int fill_0x234[3]; //0x234
   uint32_t Data_0x240; //0x240
   uint32_t Data_0x244; //0x244
   uint32_t Data_0x248; //0x248
   uint32_t Data_0x24c; //0x24c
   uint32_t Data_0x250; //0x250
   uint32_t Data_0x254; //0x254
   uint32_t Data_0x258; //0x258
   uint32_t Data_0x25c; //0x25c
   uint32_t Data_0x260; //0x260
   uint32_t Data_0x264; //0x264
   uint32_t Data_0x268; //0x268
   uint32_t Data_0x26c; //0x26c
   uint32_t Data_0x270; //0x270
   uint32_t Data_0x274; //0x274
   int fill_0x278[2]; //0x278   
   uint32_t Data_0x280; //0x280
   uint32_t Data_0x284; //0x284
   int fill_0x288[30]; //0x288
   uint32_t Data_0x300; //0x300
   uint32_t Data_0x304; //0x304
   uint32_t Data_0x308; //0x308
   uint32_t Data_0x30c; //0x30c
   uint32_t Data_0x310; //0x310
   uint32_t Data_0x314; //0x314
   uint32_t Data_0x318; //0x318
   uint32_t Data_0x31c; //0x31c
   uint32_t Data_0x320; //0x320
   uint32_t Data_0x324; //0x324
   uint32_t Data_0x328; //0x328
   uint32_t Data_0x32c; //0x32c
   uint32_t Data_0x330; //0x330
   uint32_t Data_0x334; //0x334
   uint32_t Data_0x338; //0x338
   uint32_t Data_0x33c; //0x33c
   uint32_t Data_0x340; //0x340
   uint32_t Data_0x344; //0x344
   int fill_0x348[2]; //0x348
   uint32_t Data_0x350; //0x350
   uint32_t Data_0x354; //0x354
   int fill_0x358[2]; //0x358
   uint32_t Data_0x360; //0x360
   uint32_t Data_0x364; //0x364
   uint32_t Data_0x368; //0x368
   int fill_0x36c; //0x36c
   uint32_t Data_0x370; //0x370
   uint32_t Data_0x374; //0x374
   uint32_t Data_0x378; //0x378
   uint32_t Data_0x37c; //0x37c
   uint32_t Data_0x380; //0x380
   uint32_t Data_0x384; //0x384
   int fill_0x388[2]; //0x388
   uint32_t Data_0x390; //0x390
   uint32_t Data_0x394; //0x394
   uint32_t Data_0x398; //0x398
   uint32_t Data_0x39c; //0x39c
   uint32_t Data_0x3a0; //0x3a0
   uint32_t Data_0x3a4; //0x3a4
   uint32_t Data_0x3a8; //0x3a8
   uint32_t Data_0x3ac; //0x3ac
   uint32_t Data_0x3b0; //0x3b0
   uint32_t Data_0x3b4; //0x3b4
   uint32_t Data_0x3b8; //0x3b8
   int fill_0x3bc; //0x3bc
   uint32_t Data_0x3c0; //0x3c0
   uint32_t Data_0x3c4; //0x3c4
   int fill_0x3c8[14]; //0x3c8
   uint32_t Data_0x400; //0x400
   uint32_t Data_0x404; //0x404
   uint32_t Data_0x408; //0x408
   uint32_t Data_0x40c; //0x40c
   uint32_t Data_0x410; //0x410
   uint32_t Data_0x414; //0x414
   uint32_t Data_0x418; //0x418
   uint32_t Data_0x41c; //0x41c
   uint32_t Data_0x420[32]; //0x420
   int fill_0x4a0[24]; //0x4a0
   //1280
};


static uint32_t func_21926950(uint32_t r8)
{
   uint32_t res;
   
   if (r8 == 2) res = 1;
   else if (r8 == 3) res = 3;
   else if (r8 == 4) res = 4;
   else res = 0;
   
   return res;
}


/* 21c4a238 - todo */
void fapi_videc_get_ood_info(FAPI_VIDEC_VideoDecoderIsrDataT* r6)
{
   unsigned i;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_get_ood_info\n");
    
   unsigned r7 = r6->oodInfo.wPtr;

   volatile struct Struct_1280* r4 = (struct Struct_1280*) 
      (r6->physicalMemoryInfoPtr->oodInfoTableStartAddress) +
      r6->oodInfo.rPtrMemory;

   r6->currVcpbDecTimeMsec = FAPI_TIMER_GetTimeStamp(1000);
   
   r6->oodSerialNum = r6->oodInfo.table[r7].serialNum = r4->Data_0;
   
   unsigned ip = r4->Data_0x400 & 0x3f;
   
   r6->oodInfo.table[r7].afdUserDataActiveFormatFlag =
      (ip & 0x20) >> 5;

   if (r6->oodInfo.table[r7].afdUserDataActiveFormatFlag == 1)
   {
      r6->oodInfo.table[r7].currAfd = r4->Data_0x404 & 0xff;
   }
   else
   {
      r6->oodInfo.table[r7].currAfd = 0;
   }
   
   r6->oodInfo.table[r7].ccUserDataProcessCcDataFlag =
      (ip & 0x10) >> 4;
   
   if (r6->oodInfo.table[r7].ccUserDataProcessCcDataFlag == 1)
   {
      //21c4a47c
      r6->oodInfo.table[r7].ccUserDataCcCount = 
         r4->Data_0x418 & 0x1f;
      //21c4a48c
      unsigned r0 = r4->Data_0x41c & 0x7FFFFFFF;
      
      for (i = 0; i < 31; i++)
      {
         r6->oodInfo.table[r7].ccUserDataCcValid[i] = 
            (r0 & (1 << i)) >> i;
      
      }      
      
      volatile uint32_t* p = r4->Data_0x420;
      i = 0;
      do
      {
         unsigned r3 = *p++;
         
         r6->oodInfo.table[r7].ccUserDataCcType[i] = (r3 & 0x30000) >> 16;
         r6->oodInfo.table[r7].ccUserDataCcData1[i] = (r3 & 0xff00) >> 8;
         r6->oodInfo.table[r7].ccUserDataCcData2[i] = r3 & 0xff;
         
         i++;
      }
      while (p != &r4->Data_0x420[31]);
      //->21c4a32c
   }
   else
   {
      //21c4a2ec
      r6->oodInfo.table[r7].ccUserDataCcCount = 0;
      
      for (i = 0; i < 31; i++)
      {
         //21c4a308
         r6->oodInfo.table[r7].ccUserDataCcValid[i] = 0;
         r6->oodInfo.table[r7].ccUserDataCcType[i] = 0;
         r6->oodInfo.table[r7].ccUserDataCcData1[i] = 0;
         r6->oodInfo.table[r7].ccUserDataCcData2[i] = 0;
      }
   }
   //21c4a32c
   r6->oodInfo.table[r7].barUserDataTopBarFlag = 
      (ip & 8) >> 3;
   
   if (r6->oodInfo.table[r7].barUserDataTopBarFlag == 1)
   {
      r6->oodInfo.table[r7].barUserDataEndOfTopBar = 
         r4->Data_0x408 & 0xFFFF;
   }
   else
   {
      r6->oodInfo.table[r7].barUserDataEndOfTopBar = 0;
   }
   
   r6->oodInfo.table[r7].barUserDataBotBarFlag/*Data_556*/ = 
      (ip & 4) >> 2;
   
   if (r6->oodInfo.table[r7].barUserDataBotBarFlag/*Data_556*/ == 1)
   {
      r6->oodInfo.table[r7].barUserDataStartOfBotBar/*Data_560*/ = 
         r4->Data_0x40c & 0xFFFF;
   }
   else
   {
      r6->oodInfo.table[r7].barUserDataStartOfBotBar/*Data_560*/ = 0;
   }
   
   r6->oodInfo.table[r7].barUserDataLeftBarFlag/*Data_564*/ = 
      (ip & 2) >> 1;
   
   if (r6->oodInfo.table[r7].barUserDataLeftBarFlag/*Data_564*/ == 1)
   {
      r6->oodInfo.table[r7].barUserDataEndOfLeftBar/*Data_568*/ = 
         r4->Data_0x410 & 0xFFFF;
   }
   else
   {
      r6->oodInfo.table[r7].barUserDataEndOfLeftBar/*Data_568*/ = 0;
   }
   
   r6->oodInfo.table[r7].barUserDataRightBarFlag/*Data_572*/ = 
      (ip & 1) >> 0;
   
   if (r6->oodInfo.table[r7].barUserDataRightBarFlag/*Data_572*/ == 1)
   {
      r6->oodInfo.table[r7].barUserDataStartOfRightBar/*Data_576*/ = 
         r4->Data_0x414 & 0xFFFF;
   }
   else
   {
      r6->oodInfo.table[r7].barUserDataStartOfRightBar/*Data_576*/ = 0;
   }
   
   if (r6->decoderType == FAPI_VIDEC_MPEG2_MPHL)
   {
      //21c4a508
      r6->oodInfo.table[r7].MPEG2HorizontalSizeValue = r4->Data_0x300 & 0xFFF; 
      r6->oodInfo.table[r7].MPEG2VerticalSizeValue = r4->Data_0x304 & 0xFFF; 
      r6->oodInfo.table[r7].MPEG2AspectRatioInformation = r4->Data_0x308 & 0x0F; 
      r6->oodInfo.table[r7].MPEG2FrameRateCode = r4->Data_0x30c & 0x0F; 
      r6->oodInfo.table[r7].MPEG2BitrateValue = r4->Data_0x310 & 0x3FFFF; 
      r6->oodInfo.table[r7].MPEG2VbvBufferSizeValue = r4->Data_0x314 & 0x3FF; 
      r6->oodInfo.table[r7].MPEG2ProgressiveSequence = r4->Data_0x320 & 1; 
      r6->oodInfo.table[r7].MPEG2ChromaFormat = r4->Data_0x324 & 3; 
      r6->oodInfo.table[r7].MPEG2HorizontalSizeExtention = r4->Data_0x328 & 3; 
      r6->oodInfo.table[r7].MPEG2VerticalSizeExtention = r4->Data_0x32c & 3; 
      r6->oodInfo.table[r7].MPEG2BitrateExtention = r4->Data_0x330 & 0xFFF; 
      r6->oodInfo.table[r7].MPEG2VbvBufferSizeExtention = r4->Data_0x334 & 0xFF; 
      r6->oodInfo.table[r7].MPEG2DisplayHorizontalSize = r4->Data_0x340 & 0x3FFF; 
      r6->oodInfo.table[r7].MPEG2DisplayVerticalSize = r4->Data_0x344 & 0x3FFF; 
      r6->oodInfo.table[r7].MPEG2ClosedGop = r4->Data_0x350 & 1; 
      r6->oodInfo.table[r7].MPEG2BrokenLink = r4->Data_0x354 & 1; 
      r6->oodInfo.table[r7].MPEG2TemporalReference = r4->Data_0x360 & 0x3FF; 
      r6->oodInfo.table[r7].MPEG2PictureCodingType = r4->Data_0x364 & 3; 
      r6->oodInfo.table[r7].MPEG2VbvDelay = r4->Data_0x368 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEG2PictureStructure = r4->Data_0x370 & 3; 
      r6->oodInfo.table[r7].MPEG2TopFieldFirst = r4->Data_0x374 & 1; 
      r6->oodInfo.table[r7].MPEG2RepeatFirstField = r4->Data_0x378 & 1; 
      r6->oodInfo.table[r7].MPEG2ProgressiveFrame = r4->Data_0x37c & 1; 
      r6->oodInfo.table[r7].MPEG2CompositeDisplayFlag = r4->Data_0x380 & 1; 
      r6->oodInfo.table[r7].MPEG2FieldSequence = r4->Data_0x384 & 3; 
      r6->oodInfo.table[r7].MPEG2ColourDescription = r4->Data_0x390 & 1; 
      r6->oodInfo.table[r7].MPEG2ColourPrimaries = r4->Data_0x394 & 0xFF; 
      r6->oodInfo.table[r7].MPEG2TransferCharacteristics = r4->Data_0x398 & 0xFF; 
      r6->oodInfo.table[r7].MPEG2MatrixCoefficient = r4->Data_0x39c & 0xFF; 
      r6->oodInfo.table[r7].MPEG2NumberOfFrameCenterOffsets = r4->Data_0x3a0 & 0xFF; 
      r6->oodInfo.table[r7].MPEG2FrameCenterHorizontalOffset0 = r4->Data_0x3a4 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEG2FrameCenterVerticalOffset0 = r4->Data_0x3a8 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEG2FrameCenterHorizontalOffset1 = r4->Data_0x3ac & 0xFFFF; 
      r6->oodInfo.table[r7].MPEG2FrameCenterVerticalOffset1 = r4->Data_0x3b0 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEG2FrameCenterHorizontalOffset2 = r4->Data_0x3b4 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEG2FrameCenterVerticalOffset2 = r4->Data_0x3b8 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEGDecError = r4->Data_0x3c0 & 0xFFFF; 
      r6->oodInfo.table[r7].MPEGDecInfo = r4->Data_0x3c4 & 0xFF; 
      
      if (r6->entropyDecInfoCbk != 0)
      {
         //21c4a7c4
         r6->entropyDecInfoData.serialNum = r6->oodInfo.table[r7].serialNum;
         r6->entropyDecInfoData.afdUserDataActiveFormatFlag = r6->oodInfo.table[r7].afdUserDataActiveFormatFlag;
         r6->entropyDecInfoData.currAfd = r6->oodInfo.table[r7].currAfd;
         r6->entropyDecInfoData.ccUserDataProcessCcDataFlag = r6->oodInfo.table[r7].ccUserDataProcessCcDataFlag;
         r6->entropyDecInfoData.ccUserDataCcCount = r6->oodInfo.table[r7].ccUserDataCcCount;
         
         for (i = 0; i < 31; i++)
         {
            r6->entropyDecInfoData.ccUserDataCcValid[i] = r6->oodInfo.table[r7].ccUserDataCcValid[i];
         }
         
         for (i = 0; i < 31; i++)
         {
            r6->entropyDecInfoData.ccUserDataCcType[i] = r6->oodInfo.table[r7].ccUserDataCcType[i];
            r6->entropyDecInfoData.ccUserDataCcData1[i] = r6->oodInfo.table[r7].ccUserDataCcData1[i];
            r6->entropyDecInfoData.ccUserDataCcData2[i] = r6->oodInfo.table[r7].ccUserDataCcData2[i];
         }
         
         r6->entropyDecInfoData.barUserDataTopBarFlag = r6->oodInfo.table[r7].barUserDataTopBarFlag;
         r6->entropyDecInfoData.barUserDataEndOfTopBar = r6->oodInfo.table[r7].barUserDataEndOfTopBar;
         r6->entropyDecInfoData.barUserDataBotBarFlag = r6->oodInfo.table[r7].barUserDataBotBarFlag;
         r6->entropyDecInfoData.barUserDataStartOfBotBar = r6->oodInfo.table[r7].barUserDataStartOfBotBar;
         r6->entropyDecInfoData.barUserDataLeftBarFlag = r6->oodInfo.table[r7].barUserDataLeftBarFlag;
         r6->entropyDecInfoData.barUserDataEndOfLeftBar = r6->oodInfo.table[r7].barUserDataEndOfLeftBar;
         r6->entropyDecInfoData.barUserDataRightBarFlag = r6->oodInfo.table[r7].barUserDataRightBarFlag;
         r6->entropyDecInfoData.barUserDataStartOfRightBar = r6->oodInfo.table[r7].barUserDataStartOfRightBar;

         r6->entropyDecInfoData.MPEG2HorizontalSizeValue = r6->oodInfo.table[r7].MPEG2HorizontalSizeValue;
         r6->entropyDecInfoData.MPEG2VerticalSizeValue = r6->oodInfo.table[r7].MPEG2VerticalSizeValue;
         r6->entropyDecInfoData.MPEG2AspectRatioInformation = r6->oodInfo.table[r7].MPEG2AspectRatioInformation;
         r6->entropyDecInfoData.MPEG2ProgressiveSequence = r6->oodInfo.table[r7].MPEG2ProgressiveSequence;
         r6->entropyDecInfoData.MPEG2ChromaFormat = r6->oodInfo.table[r7].MPEG2ChromaFormat;
         r6->entropyDecInfoData.MPEG2DisplayHorizontalSize = r6->oodInfo.table[r7].MPEG2DisplayHorizontalSize;
         r6->entropyDecInfoData.MPEG2DisplayVerticalSize = r6->oodInfo.table[r7].MPEG2DisplayVerticalSize;
         r6->entropyDecInfoData.MPEG2ClosedGop = r6->oodInfo.table[r7].MPEG2ClosedGop;
         r6->entropyDecInfoData.MPEG2BrokenLink = r6->oodInfo.table[r7].MPEG2BrokenLink;
         r6->entropyDecInfoData.MPEG2PictureCodingType = r6->oodInfo.table[r7].MPEG2PictureCodingType;
         r6->entropyDecInfoData.MPEG2PictureStructure = r6->oodInfo.table[r7].MPEG2PictureStructure;
         r6->entropyDecInfoData.MPEG2TopFieldFirst = r6->oodInfo.table[r7].MPEG2TopFieldFirst;
         r6->entropyDecInfoData.MPEG2RepeatFirstField = r6->oodInfo.table[r7].MPEG2RepeatFirstField;
         r6->entropyDecInfoData.MPEG2ProgressiveFrame = r6->oodInfo.table[r7].MPEG2ProgressiveFrame;
         r6->entropyDecInfoData.MPEG2FieldSequence = r6->oodInfo.table[r7].MPEG2FieldSequence;
      }
      //21c4a9f8
      if (r6->oodInfo.table[r7].MPEGDecError <= 1)
      {
         //21c4b7a4
         r6->oodInfo.table[r7].decodedWidth = r6->oodInfo.table[r7].MPEG2HorizontalSizeValue;
         r6->oodInfo.table[r7].decodedHeight = r6->oodInfo.table[r7].MPEG2VerticalSizeValue;
         
         r6->vesInfo.decodedWidth = r6->oodInfo.table[r7].MPEG2HorizontalSizeValue;
         r6->vesInfo.decodedHeight = r6->oodInfo.table[r7].MPEG2VerticalSizeValue;
         
         if (r6->mpegIFrameState != 0)
         {
            //21c4b7dc
            r6->oodInfo.table[r7].codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;
            r6->vesInfo.proggInter = -1;            
         }
         else
         {
            //21c4b8c4
            if (r6->oodInfo.table[r7].MPEG2ProgressiveSequence == 0)
            {
               r6->oodInfo.table[r7].codedInterlaceProggState = FAPI_VIDEC_IP_INTERLACE;
               r6->vesInfo.proggInter = 0;            
            }
            else if (r6->oodInfo.table[r7].MPEG2ProgressiveSequence == 1)
            {
               r6->oodInfo.table[r7].codedInterlaceProggState = FAPI_VIDEC_IP_PROGRESSIVE;
               r6->vesInfo.proggInter = 1;            
            }
            else
            {
               //21c4b7dc
               r6->oodInfo.table[r7].codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;
               r6->vesInfo.proggInter = -1;            
            }
         }
         //21c4b7ec
         if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 3) r6->vesInfo.vesFrameRate = 2500;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 6) r6->vesInfo.vesFrameRate = 5000;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 1) r6->vesInfo.vesFrameRate = 2397;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 2) r6->vesInfo.vesFrameRate = 2400;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 4) r6->vesInfo.vesFrameRate = 2997;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 5) r6->vesInfo.vesFrameRate = 3000;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 7) r6->vesInfo.vesFrameRate = 5994;
         else if (r6->oodInfo.table[r7].MPEG2FrameRateCode == 8) r6->vesInfo.vesFrameRate = 6000;
         else r6->vesInfo.vesFrameRate = 0;            
         //21c4b880
         func_21c4894c(r6);
         
         if (r6->oodInfo.table[r7].MPEG2AspectRatioInformation == 2) r6->vesInfo.vesAspectRatio = 1;
         else if (r6->oodInfo.table[r7].MPEG2AspectRatioInformation == 3) r6->vesInfo.vesAspectRatio = 3;
         else if (r6->oodInfo.table[r7].MPEG2AspectRatioInformation == 4) r6->vesInfo.vesAspectRatio = 4;
         else r6->vesInfo.vesAspectRatio = 0;
         //->21c4b790
         r6->oodEntropyDecodedAudIdx++;
         //->21c4aa10
      }
      //21c4aa10
      r6->oodInfo.table[r7].decodedPicAspectRatio = r6->vesInfo.vesAspectRatio;
      //->21c4a42c
   } //if (r6->decoderType == FAPI_VIDEC_MPEG2_MPHL)
   else if (r6->decoderType == FAPI_VIDEC_H264_HP41)
   {
      //21c4ab84
      r6->oodInfo.table[r7].H264VclHrdBpPresentFlag = (r4->Data_4 & 4) >> 2;
      r6->oodInfo.table[r7].H264NalHrdBpPresentFlag = (r4->Data_4 & 2) >> 1;
      r6->oodInfo.table[r7].H264BufferingPeriodSeiPresentFlag = (r4->Data_4 & 1) >> 0;
      r6->oodInfo.table[r7].H264SequenceParameterSetId = r4->Data_8 & 0xFF;
      r6->oodInfo.table[r7].H264NalInitialCpbRemovalDelay = r4->Data_12;
      r6->oodInfo.table[r7].H264NalInitialCpbRemovalDelayOffset = r4->Data_16;
      r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay = r4->Data_20;
      r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelayOffset = r4->Data_24;
      r6->oodInfo.table[r7].H264ClockTs2PresentFlag = (r4->Data_0x20 & 0x20) >> 5;
      r6->oodInfo.table[r7].H264ClockTs1PresentFlag = (r4->Data_0x20 & 0x10) >> 4;
      r6->oodInfo.table[r7].H264ClockTs0PresentFlag = (r4->Data_0x20 & 8) >> 3;
      r6->oodInfo.table[r7].H264PicStructurePresentFlag = (r4->Data_0x20 & 4) >> 2;
      r6->oodInfo.table[r7].H264CpbDpbDelaysPresentFlag = (r4->Data_0x20 & 2) >> 1;
      r6->oodInfo.table[r7].H264PicTimingSeiPresentFlag = r4->Data_0x20 & 1;
      r6->oodInfo.table[r7].H264CpbRemovalDelay = r4->Data_0x24;
      r6->oodInfo.table[r7].H264DpbOutputDelay = r4->Data_0x28;
      r6->oodInfo.table[r7].H264PicStructure = r4->Data_0x2c & 0x0F;
      r6->oodInfo.table[r7].H264ClkTimestampFlag0 = r4->Data_0x30 & 1;
      r6->oodInfo.table[r7].H264CtType0 = r4->Data_0x34 & 3;
      r6->oodInfo.table[r7].H264NuitFieldBasedFlag0 = r4->Data_0x38 & 1;
      r6->oodInfo.table[r7].H264CountingType0 = r4->Data_0x3c & 0x1f;
      r6->oodInfo.table[r7].H264FullTimestampFlag0 = r4->Data_0x40 & 1;
      r6->oodInfo.table[r7].H264DiscontinuityFlag0 = r4->Data_0x44 & 1;
      r6->oodInfo.table[r7].H264CntDroppedFlag0 = r4->Data_0x48 & 1;
      r6->oodInfo.table[r7].H264NFrames0 = r4->Data_0x4c & 0xFF;
      r6->oodInfo.table[r7].H264SecondsFlag0 = r4->Data_0x50 & 1;
      r6->oodInfo.table[r7].H264SecondsValue0 = r4->Data_0x54 & 0x3F;
      r6->oodInfo.table[r7].H264MinutesFlag0 = r4->Data_0x58 & 1;
      r6->oodInfo.table[r7].H264MinutesValue0 = r4->Data_0x5c & 0x3F;
      r6->oodInfo.table[r7].H264HoursFlag0 = r4->Data_0x60 & 1;
      r6->oodInfo.table[r7].H264HoursValue0 = r4->Data_0x64 & 0x1F;
      r6->oodInfo.table[r7].H264TimeOffset0 = r4->Data_0x68 & 0x1F;
      r6->oodInfo.table[r7].H264ClkTimestampFlag1 = r4->Data_0x70 & 1;
      r6->oodInfo.table[r7].H264CtType1 = r4->Data_0x74 & 3;
      r6->oodInfo.table[r7].H264NuitFieldBasedFlag1 = r4->Data_0x78 & 1;
      r6->oodInfo.table[r7].H264CountingType1 = r4->Data_0x7c & 0x1F;
      r6->oodInfo.table[r7].H264FullTimestampFlag1 = r4->Data_0x80 & 1;
      r6->oodInfo.table[r7].H264DiscontinuityFlag1 = r4->Data_0x84 & 1;
      r6->oodInfo.table[r7].H264CntDroppedFlag1 = r4->Data_0x88 & 1;
      r6->oodInfo.table[r7].H264NFrames1 = r4->Data_0x8c & 0xFF;
      r6->oodInfo.table[r7].H264SecondsFlag1 = r4->Data_0x90 & 1;
      r6->oodInfo.table[r7].H264SecondsValue1 = r4->Data_0x94 & 0x3F;
      r6->oodInfo.table[r7].H264MinutesFlag1 = r4->Data_0x98 & 1;
      r6->oodInfo.table[r7].H264MinutesValue1 = r4->Data_0x9c & 0x3F;
      r6->oodInfo.table[r7].H264HoursFlag1 = r4->Data_0xa0 & 1;
      r6->oodInfo.table[r7].H264HoursValue1 = r4->Data_0xa4 & 0x1F;
      r6->oodInfo.table[r7].H264TimeOffset1 = r4->Data_0xa8 & 0x1F;
      r6->oodInfo.table[r7].H264ClkTimestampFlag2 = r4->Data_0xb0 & 1;
      r6->oodInfo.table[r7].H264CtType2 = r4->Data_0xb4 & 3;
      r6->oodInfo.table[r7].H264NuitFieldBasedFlag2 = r4->Data_0xb8 & 1;
      r6->oodInfo.table[r7].H264CountingType2 = r4->Data_0xbc & 0x1F;
      r6->oodInfo.table[r7].H264FullTimestampFlag2 = r4->Data_0xc0 & 1;
      r6->oodInfo.table[r7].H264DiscontinuityFlag2 = r4->Data_0xc4 & 1;
      r6->oodInfo.table[r7].H264CntDroppedFlag2 = r4->Data_0xc8 & 1;
      r6->oodInfo.table[r7].H264NFrames2 = r4->Data_0xcc & 0xFF;
      r6->oodInfo.table[r7].H264SecondsFlag2 = r4->Data_0xd0 & 1;
      r6->oodInfo.table[r7].H264SecondsValue2 = r4->Data_0xd4 & 0x3F;
      r6->oodInfo.table[r7].H264MinutesFlag2 = r4->Data_0xd8 & 1;
      r6->oodInfo.table[r7].H264MinutesValue2 = r4->Data_0xdc & 0x3F;
      r6->oodInfo.table[r7].H264HoursFlag2 = r4->Data_0xe0 & 1;
      r6->oodInfo.table[r7].H264HoursValue2 = r4->Data_0xe4 & 0x1F;
      r6->oodInfo.table[r7].H264TimeOffset2 = r4->Data_0xe8 & 0x1F;
      r6->oodInfo.table[r7].H264PanScanSeiPresentFlag = r4->Data_0xf0 & 1;
      r6->oodInfo.table[r7].H264PanScanRectangleId = r4->Data_0xf4;
      r6->oodInfo.table[r7].H264PanScanRectCancelFlag = r4->Data_0xf8 & 1;
      r6->oodInfo.table[r7].H264PanScanCntMinus1 = r4->Data_0xfc & 0x0F;
      r6->oodInfo.table[r7].H264PanScanLeftOffset0 = r4->Data_0x100;
      r6->oodInfo.table[r7].H264PanScanRightOffset0 = r4->Data_0x104;
      r6->oodInfo.table[r7].H264PanScanTopOffset0 = r4->Data_0x108;
      r6->oodInfo.table[r7].H264PanScanBotOffset0 = r4->Data_0x10c;
      r6->oodInfo.table[r7].H264PanScanLeftOffset1 = r4->Data_0x110;
      r6->oodInfo.table[r7].H264PanScanRightOffset1 = r4->Data_0x114;
      r6->oodInfo.table[r7].H264PanScanTopOffset1 = r4->Data_0x118;
      r6->oodInfo.table[r7].H264PanScanBotOffset1 = r4->Data_0x11c;
      r6->oodInfo.table[r7].H264PanScanLeftOffset2 = r4->Data_0x120;
      r6->oodInfo.table[r7].H264PanScanRightOffset2 = r4->Data_0x124;
      r6->oodInfo.table[r7].H264PanScanTopOffset2 = r4->Data_0x128;
      r6->oodInfo.table[r7].H264PanScanBotOffset2 = r4->Data_0x12c;
      r6->oodInfo.table[r7].H264PanScanRectRepetitionPeriod = r4->Data_0x130;
      r6->oodInfo.table[r7].H264RecoveryPointSeiPresentFlag = r4->Data_0x140 & 1;
      r6->oodInfo.table[r7].H264RecoveryFrameCount = r4->Data_0x144 & 0x1FF;
      r6->oodInfo.table[r7].H264ExactMatchFlag = r4->Data_0x148 & 1;
      r6->oodInfo.table[r7].H264BrokenLinkFlag = r4->Data_0x14c & 1;
      r6->oodInfo.table[r7].H264ChangingSliceGroupIdc = r4->Data_0x150 & 3;
      r6->oodInfo.table[r7].H264PrimaryPicType = r4->Data_0x160 & 0xFF;
      r6->oodInfo.table[r7].H264NalRefIdc = r4->Data_0x170 & 0xFF;
      r6->oodInfo.table[r7].H264NalUnitType = r4->Data_0x174 & 0xFF;
      r6->oodInfo.table[r7].H264MaxDpbSize = r4->Data_0x180 & 0xFF;
      r6->oodInfo.table[r7].H264PicWidthInMbsMinus1 = r4->Data_0x190 & 0xFF;
      r6->oodInfo.table[r7].H264FrameHeightInMbs = r4->Data_0x194 & 0xFF;
      r6->oodInfo.table[r7].H264Log2MaxFrameNumMinus4 = r4->Data_0x198 & 0xFF;
      r6->oodInfo.table[r7].H264FrameMbsOnlyFlag = r4->Data_0x19c & 0xFF;
      r6->oodInfo.table[r7].H264MbAdaptiveFrameFieldFlag = r4->Data_0x1a0 & 0xFF;
      r6->oodInfo.table[r7].H264ProfileIdc = r4->Data_0x1a4 & 0xFF;
      r6->oodInfo.table[r7].H264LevelIdc = r4->Data_0x1a8 & 0xFF;
      r6->oodInfo.table[r7].H264FrameCropTopOffset = r4->Data_0x1ac & 0xFFFF;
      r6->oodInfo.table[r7].H264FrameCropBotOffset = r4->Data_0x1b0 & 0xFFFF;
      r6->oodInfo.table[r7].H264FrameCropLeftOffset = r4->Data_0x1b4 & 0xFFFF;
      r6->oodInfo.table[r7].H264FrameCropRightOffset = r4->Data_0x1b8 & 0xFFFF;
      r6->oodInfo.table[r7].H264PicParameterSetId = r4->Data_0x1c0 & 0xFF;
      r6->oodInfo.table[r7].H264SeqParameterSetId = r4->Data_0x1c4 & 0xFF;
      r6->oodInfo.table[r7].H264ChromaQpIndexOffset = r4->Data_0x1c8 & 0xFF;
      r6->oodInfo.table[r7].H264SecondChromaQpIndexOffset = r4->Data_0x1cc & 0xFF;
      r6->oodInfo.table[r7].H264Transform8x8ModeFlag = r4->Data_0x1d0 & 0xFF;
      r6->oodInfo.table[r7].H264FrameNum = r4->Data_0x1f0 & 0xFFFF;
      r6->oodInfo.table[r7].H264IdrPicId = r4->Data_0x1f4 & 0xFFFF;
      r6->oodInfo.table[r7].H264TopFieldOrderCount = r4->Data_0x1f8;
      r6->oodInfo.table[r7].H264BotFieldOrderCount = r4->Data_0x1fc;
      r6->oodInfo.table[r7].H264ChromaFormatIdc = r4->Data_0x200 & 0xFF;
      r6->oodInfo.table[r7].H264FieldPicFlag = r4->Data_0x204 & 0xFF;
      r6->oodInfo.table[r7].H264BotFieldFlag = r4->Data_0x208 & 0xFF;
      r6->oodInfo.table[r7].H264EndOfSequenceRbsp = r4->Data_0x210 & 0xFF;
      r6->oodInfo.table[r7].H264EndOfStreamRbsp = r4->Data_0x220 & 0xFF;
      r6->oodInfo.table[r7].H264BitRate = r4->Data_0x230;
      r6->oodInfo.table[r7].H264AspectRatioInfoPresentFlag = r4->Data_0x240 & 1;
      r6->oodInfo.table[r7].H264AspectRatioIdc = r4->Data_0x244 & 0xFF;
      r6->oodInfo.table[r7].H264SarWidth = r4->Data_0x248 & 0xFFFF;
      r6->oodInfo.table[r7].H264SarHeight = r4->Data_0x24c & 0xFFFF;
      r6->oodInfo.table[r7].H264VideoSignalTypePresentFlag = r4->Data_0x250 & 1;
      r6->oodInfo.table[r7].H264TimingfInfoPresentFlag = (r4->Data_0x250 & 2) >> 1;
      r6->oodInfo.table[r7].H264ColourDescriptionPresentFlag = (r4->Data_0x250 & 4) >> 2;
      r6->oodInfo.table[r7].H264ChromaLocInfoPresentFlag = (r4->Data_0x250 & 8) >> 3;
      r6->oodInfo.table[r7].H264VideoFullRangeFlag = (r4->Data_0x250 & 0x10) >> 4;
      r6->oodInfo.table[r7].H264VideoFormat = r4->Data_0x254 & 0xFF;
      r6->oodInfo.table[r7].H264NumUnitsInTick = r4->Data_0x258;
      r6->oodInfo.table[r7].H264TimeScale = r4->Data_0x25c;
      r6->oodInfo.table[r7].H264FixedFrameRateFlag = r4->Data_0x260;
      r6->oodInfo.table[r7].H264ColourPrimaries = r4->Data_0x264 & 0xFF;
      r6->oodInfo.table[r7].H264TransferCharacteristics = r4->Data_0x268 & 0xFF;
      r6->oodInfo.table[r7].H264MatrixCoefficient = r4->Data_0x26c & 0xFF;
      r6->oodInfo.table[r7].H264ChromaSampleLocTypeTopField = r4->Data_0x270 & 0xFF;
      r6->oodInfo.table[r7].H264ChromaSampleLocTypeBotField = r4->Data_0x274 & 0xFF;
      r6->oodInfo.table[r7].H264DecError = r4->Data_0x280 & 0xFFFF;
      r6->oodInfo.table[r7].H264DecInfo = r4->Data_0x284 & 0xFF;
      
      if (r6->entropyDecInfoCbk != 0)
      {
         //21c4b3ec
         r6->entropyDecInfoData.serialNum = r6->oodInfo.table[r7].serialNum;
         r6->entropyDecInfoData.afdUserDataActiveFormatFlag = r6->oodInfo.table[r7].afdUserDataActiveFormatFlag;
         r6->entropyDecInfoData.currAfd = r6->oodInfo.table[r7].currAfd;
         r6->entropyDecInfoData.ccUserDataProcessCcDataFlag = r6->oodInfo.table[r7].ccUserDataProcessCcDataFlag;
         r6->entropyDecInfoData.ccUserDataCcCount = r6->oodInfo.table[r7].ccUserDataCcCount;
         
         for (i = 0; i < 31; i++)
         {
            r6->entropyDecInfoData.ccUserDataCcValid[i] = r6->oodInfo.table[r7].ccUserDataCcValid[i];
         }
         
         for (i = 0; i < 31; i++)
         {
            r6->entropyDecInfoData.ccUserDataCcType[i] = r6->oodInfo.table[r7].ccUserDataCcType[i];
            r6->entropyDecInfoData.ccUserDataCcData1[i] = r6->oodInfo.table[r7].ccUserDataCcData1[i];
            r6->entropyDecInfoData.ccUserDataCcData2[i] = r6->oodInfo.table[r7].ccUserDataCcData2[i];
         }
         //21c4b4a8
         r6->entropyDecInfoData.barUserDataTopBarFlag = r6->oodInfo.table[r7].barUserDataTopBarFlag;
         r6->entropyDecInfoData.barUserDataEndOfTopBar = r6->oodInfo.table[r7].barUserDataEndOfTopBar;
         r6->entropyDecInfoData.barUserDataBotBarFlag = r6->oodInfo.table[r7].barUserDataBotBarFlag;
         r6->entropyDecInfoData.barUserDataStartOfBotBar = r6->oodInfo.table[r7].barUserDataStartOfBotBar;
         r6->entropyDecInfoData.barUserDataLeftBarFlag = r6->oodInfo.table[r7].barUserDataLeftBarFlag;
         r6->entropyDecInfoData.barUserDataEndOfLeftBar = r6->oodInfo.table[r7].barUserDataEndOfLeftBar;
         r6->entropyDecInfoData.barUserDataRightBarFlag = r6->oodInfo.table[r7].barUserDataRightBarFlag;
         r6->entropyDecInfoData.barUserDataStartOfRightBar = r6->oodInfo.table[r7].barUserDataStartOfRightBar;

         r6->entropyDecInfoData.H264PicStructurePresentFlag = r6->oodInfo.table[r7].H264PicStructurePresentFlag;
         r6->entropyDecInfoData.H264PicStructure = r6->oodInfo.table[r7].H264PicStructure;
         r6->entropyDecInfoData.H264BrokenLinkFlag = r6->oodInfo.table[r7].H264BrokenLinkFlag;
         r6->entropyDecInfoData.H264NalUnitType = r6->oodInfo.table[r7].H264NalUnitType;
         r6->entropyDecInfoData.H264PicWidthInMbsMinus1 = r6->oodInfo.table[r7].H264PicWidthInMbsMinus1;
         r6->entropyDecInfoData.H264FrameHeightInMbs = r6->oodInfo.table[r7].H264FrameHeightInMbs;
         r6->entropyDecInfoData.H264ProfileIdc = r6->oodInfo.table[r7].H264ProfileIdc;
         r6->entropyDecInfoData.H264LevelIdc = r6->oodInfo.table[r7].H264LevelIdc;
         r6->entropyDecInfoData.H264FrameNum = r6->oodInfo.table[r7].H264FrameNum;
         r6->entropyDecInfoData.H264TopFieldOrderCount = r6->oodInfo.table[r7].H264TopFieldOrderCount;
         r6->entropyDecInfoData.H264BotFieldOrderCount = r6->oodInfo.table[r7].H264BotFieldOrderCount;
         r6->entropyDecInfoData.H264FieldPicFlag = r6->oodInfo.table[r7].H264FieldPicFlag;
         r6->entropyDecInfoData.H264BotFieldFlag = r6->oodInfo.table[r7].H264BotFieldFlag;
         r6->entropyDecInfoData.H264AspectRatioInfoPresentFlag = r6->oodInfo.table[r7].H264AspectRatioInfoPresentFlag;
         r6->entropyDecInfoData.H264AspectRatioIdc = r6->oodInfo.table[r7].H264AspectRatioIdc;
         r6->entropyDecInfoData.H264SarWidth = r6->oodInfo.table[r7].H264SarWidth;
         r6->entropyDecInfoData.H264SarHeight = r6->oodInfo.table[r7].H264SarHeight;
         r6->entropyDecInfoData.H264ChromaLocInfoPresentFlag = r6->oodInfo.table[r7].H264ChromaLocInfoPresentFlag;
         r6->entropyDecInfoData.H264ChromaSampleLocTypeTopField = r6->oodInfo.table[r7].H264ChromaSampleLocTypeTopField;
         r6->entropyDecInfoData.H264ChromaSampleLocTypeBotField = r6->oodInfo.table[r7].H264ChromaSampleLocTypeBotField;
      }
      //21c4b670
      if (r6->oodInfo.table[r7].H264DecError <= 1)
      {
         //21c4b688
         if (r6->oodInfo.table[r7].H264PicWidthInMbsMinus1 == 0)
         {
            r6->vesInfo.decodedWidth =
            r6->oodInfo.table[r7].decodedWidth =
               r6->oodInfo.table[r7].H264PicWidthInMbsMinus1;
         }
         else
         {
            r6->vesInfo.decodedWidth =
            r6->oodInfo.table[r7].decodedWidth =
               (r6->oodInfo.table[r7].H264PicWidthInMbsMinus1+1) * 16;
         }
         
         r6->vesInfo.decodedHeight = 
            r6->oodInfo.table[r7].decodedHeight = 
               r6->oodInfo.table[r7].H264FrameHeightInMbs * 16;
         
         if (r6->oodInfo.table[r7].H264FrameMbsOnlyFlag == 1)
         {
            r6->oodInfo.table[r7].codedInterlaceProggState = 1;
            r6->vesInfo.proggInter = 1;
            //->21c4b720
         }
         //21c4b6f0
         else if (r6->oodInfo.table[r7].H264FieldPicFlag == 1)
         {
            r6->oodInfo.table[r7].codedInterlaceProggState = 0;
            r6->vesInfo.proggInter = 0;
            //->21c4b720            
         }
         else if (r6->oodInfo.table[r7].H264PicStructurePresentFlag == 1)
         {
            //->21c4ba8c
            if ((r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 1) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 2) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 3) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 4) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 5) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 6))
            {
               r6->oodInfo.table[r7].codedInterlaceProggState = 0;
               r6->vesInfo.proggInter = 0;
               //->21c4b720            
            }
            else if ((r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 0) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 7) ||
                  (r6->oodInfo.table[r7].H264VclInitialCpbRemovalDelay == 8))
            {
               //21c4baec
               r6->oodInfo.table[r7].codedInterlaceProggState = 1;
               r6->vesInfo.proggInter = 1;
               //->21c4b720            
            }
            else
            {
               //21c4bac4
               r6->oodInfo.table[r7].codedInterlaceProggState = -1;
               r6->vesInfo.proggInter = -1;
               //->21c4b720            
            }
         }
         //21c4b720
         if ((r6->oodInfo.table[r7].H264NumUnitsInTick != 0) &&
               (r6->oodInfo.table[r7].H264TimeScale != 0))
         {
            //21c4b748
            uint64_t r0_r1;
            
            if (r6->oodInfo.table[r7].H264NumUnitsInTick == 1)
            {
               //21c4bafc
               r0_r1 = ((uint64_t)r6->oodInfo.table[r7].H264TimeScale * 100);
               r0_r1 >>= 1;
               r6->vesInfo.vesFrameRate = r0_r1;
            }
            else
            {
               //21c4b750
               r0_r1 = (uint64_t)r6->oodInfo.table[r7].H264TimeScale * 100;
               r6->vesInfo.vesFrameRate = (uint32_t)(r0_r1/r6->oodInfo.table[r7].H264NumUnitsInTick) >> 1;
            }                  
         }
         //21c4b770
         func_21c4894c/*219262c0*/(r6);
         
         if (r6->oodInfo.table[r7].H264AspectRatioInfoPresentFlag == 1)
         {
            //21c4b8f8
            unsigned lr = 0;
            unsigned ip = 0;
            
            if (r6->oodInfo.table[r7].H264AspectRatioIdc != 0)
            {
               //21c4b908
               if (r6->oodInfo.table[r7].H264AspectRatioIdc == 0xFF)
               {
                  //21c4bad8
                  lr = r6->oodInfo.table[r7].H264SarWidth;
                  ip = r6->oodInfo.table[r7].H264SarHeight;
                  //->21c4b9ec
               }
               //21c4b910
               else if ((r6->oodInfo.table[r7].H264AspectRatioIdc - 14) > 240)
               {
                  //21c4b91c
                  if (r6->oodInfo.table[r7].H264AspectRatioIdc == 1)
                  {
                     lr = 1;
                     ip = 1;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 2)
                  {
                     lr = 12;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 3)
                  {
                     lr = 10;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 4)
                  {
                     lr = 16;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 5)
                  {
                     lr = 40;
                     ip = 33;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 6)
                  {
                     lr = 24;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 7)
                  {
                     lr = 20;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 8)
                  {
                     lr = 32;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 9)
                  {
                     lr = 80;
                     ip = 33;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 10)
                  {
                     lr = 18;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 11)
                  {
                     lr = 15;
                     ip = 11;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 12)
                  {
                     lr = 64;
                     ip = 33;
                     //->21c4b9ec
                  }
                  else if (r6->oodInfo.table[r7].H264AspectRatioIdc == 13)
                  {
                     lr = 160;
                     ip = 99;
                     //->21c4b9ec
                  }
                  //21c4b9ec
               }
            }
            //21c4b9ec
            lr *= (r6->oodInfo.table[r7].H264PicWidthInMbsMinus1 + 1) * 100;
            ip *= r6->oodInfo.table[r7].H264FrameHeightInMbs;
            
            if ((lr != 0) && (ip != 0))
            {
               //21c4ba3c
               unsigned r0 = lr / ip;
               
               if ((r0 - 100) < 100)
               {
                  //21c4ba50
                  if ((r0 - 125) < 13)
                  {
                     r6->vesInfo.vesAspectRatio = 1;
                     //->21c4b790
                  }
                  else if ((r0 - 151) < 9)
                  {
                     r6->vesInfo.vesAspectRatio = 2;
                     //->21c4b790
                  }
                  else if ((r0 - 173) < 12)
                  {
                     r6->vesInfo.vesAspectRatio = 3;
                  }
                  //->21c4b790
               }
               //21c4bb1c
               else if ((r0 - 200) < 100)
               {
                  if ((r0 - 215) < 16)
                  {
                     r6->vesInfo.vesAspectRatio = 4;
                     //->21c4b790
                  }
                  else if ((r0 - 231) < 16)
                  {
                     r6->vesInfo.vesAspectRatio = 5;
                  }
                  //->21c4b790
               }
               else
               {
                  //21c4b8b8
                  r6->vesInfo.vesAspectRatio = 0;
               }
            }
            else
            {
               //21c4b8b8
               r6->vesInfo.vesAspectRatio = 0;
            }
         }
         //21c4b790
         r6->oodEntropyDecodedAudIdx++;
         //->21c4aa10
      }
      //21c4aa10
      r6->oodInfo.table[r7].decodedPicAspectRatio = r6->vesInfo.vesAspectRatio;
      //->21c4a42c
   } //else if (r6->decoderType == FAPI_VIDEC_H264_HP41)
   //21c4a42c
   if (r6->oodInfo.rPtrMemory >= (OOD_INFO_TABLE_MAX_ENTRY_NUM-1))
   {
      r6->oodInfo.rPtrMemory = 0;
   }
   else
   {
      r6->oodInfo.rPtrMemory++;
   }
   
   if (r6->oodInfo.wPtr >= (OOD_FIFO_MAX_NUM-1))
   {
      r6->oodInfo.wPtr = 0;
   }
   else
   {
      r6->oodInfo.wPtr++;
   }
   
   r6->oodIdx++;
}


static uint32_t func_219268a8(uint32_t r2)
{
   uint32_t res;
   
   if (r2 == 0)
   {
      res = 0;
   }
   else if (r2 == 1)
   {
      res = 1;
   }
   else
   {
      res = -1;
   }

   return res;
}


static uint32_t func_219272b4(uint32_t a)
{
   uint32_t r0_;
   
   if (a == 3) r0_ = 2500;
   else if (a == 6) r0_ = 5000;
   else if (a == 1) r0_ = 2397;
   else if (a == 2) r0_ = 2400;
   else if (a == 4) r0_ = 2997;
   else if (a == 5) r0_ = 3000;
   else if (a == 7) r0_ = 5994;
   else if (a == 8) r0_ = 6000;
   else r0_ = 0;            

   return r0_;
}


/* 21c4894c - complete */
/* Evolve: 219262c0 - todo */
void func_21c4894c(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
   uint64_t r5 = 2;
   unsigned r2 = 3600;
   
   if ((a->vesInfo.decodedWidth <= 64) &&
         (a->vesInfo.decodedHeight <= 48))
   {
      if (a->decoderType == FAPI_VIDEC_MPEG2_MPHL)
      {
         r5 = 2;
      }
      else if (a->decoderType == FAPI_VIDEC_H264_HP41)
      {
         r5 = 3;
      }
   }
   else if ((a->vesInfo.decodedWidth <= 720) &&
         (a->vesInfo.decodedHeight <= 576))
   {
      r5 = 2;
   }
   else if ((a->vesInfo.decodedWidth <= 1280) &&
         (a->vesInfo.decodedHeight <= 720))
   {
      r5 = 2;
   }
   else if ((a->vesInfo.decodedWidth <= 1440) &&
         (a->vesInfo.decodedHeight <= 576))
   {
      r5 = 2;
   }
   else if ((a->vesInfo.decodedWidth <= 1920) &&
         (a->vesInfo.decodedHeight <= 1088))
   {
      if (a->decoderType == FAPI_VIDEC_MPEG2_MPHL)
      {
         r5 = 2;
      }
      else if (a->decoderType == FAPI_VIDEC_H264_HP41)
      {
         r5 = 1;
      }
   }

   if (a->vesInfo.vesFrameRate != 0)
   {
      r5 *= (uint64_t) (9000000 / a->vesInfo.vesFrameRate);
      a->vesInfo.vesDecoderLatency = r5; 
   }
   else
   {
      a->vesInfo.vesDecoderLatency = r2 * r5;
   }
}


static unsigned func_21926c7c(unsigned sp8, unsigned sp4, unsigned Data_0x190, unsigned Data_0x194)
{
   unsigned r8 = 0;
   
   unsigned r0 = Data_0x190 * sp8 * 100;
   unsigned r1 = Data_0x194 * sp4;
      
   if ((r0 != 0) && 
         (r1 != 0))
   {
      //21926cac
      r0 = r0 / r1;
      
      if ((r0 - 100) < 100)
      {
         //21926cbc
         r0 -= 100;
         
         if ((r0 - 25) <= 12)
         {
            r8 = 1;
         }
         else if ((r0 - 51) <= 8)
         {
            r8 = 2;
         }
         else if ((r0 - 73) <= 11)
         {
            r8 = 3;
         }
      }
      //21926cf0
      else if ((r0 - 200) < 100)
      {
         r0 -= 200;
         
         if ((r0 - 15) <= 15)
         {
            r8 = 4;
         }
         else if ((r0 - 31) <= 15)
         {
            r8 = 5;
         }
      }
   }

   return r8;
}


static void func_219263c0(FAPI_VIDEC_VideoDecoderIsrDataT* r4)
{     
   int r12;
   int r7;
//   int r11;
   
//   int r10 = 1;
   int sp8 = 1;
   int sp4 = 1;
   int r0 = 0;
   unsigned r8 = 0;
      
   int r2/*r5*/ = r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].topFieldSerialNo; //Data_28;
   int r3/*r4*/ = r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].botFieldSerialNo; //Data_32;
   
   if (r4->Data_120 == 1)
   {
      //21c51da8
      if ((r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 6) ||
            (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 10) ||
            (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 11))
      {
         //21c51dc4
         r3 = r2;
      }
   }
   //21c51620
#if 0
   if (r4->Data_0x1f984 == -1)
   {
      for (r0 = 0; r0 < 512; r0++)
      {
         //21c51630
         if (r4->Data_0xf984[r0] == 0)
         {
            r4->Data_0x1f984 = r0;
            break;
         }
      }
      //21c51a44
   }
   //21926454
#else
   for (r0 = 0; r0 < 512; r0++)
   {
      //21c51630
      if ((r4->oodInfo.table/*Data_49508*/[r0].serialNum/*Data_0*/ == r2) ||
            (r4->oodInfo.table/*Data_49508*/[r0].serialNum/*Data_0*/ == r3))
      {
         //21c51658
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].decodedWidth/*Data_16*/ =
            r4->oodInfo.table/*Data_49508*/[r0].decodedWidth/*Data_8*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].decodedHeight/*Data_20*/ =
            r4->oodInfo.table/*Data_49508*/[r0].decodedHeight/*Data_12*/;
         
         if ((r4->decoderAfdState == -1) ||
               (r4->decoderAfdState == 17))
         {
            r8 = 1;
            r4->Data_204 = 0;
            //->21c516cc
         }
         else if (r4->decoderAfdState == 16)
         {
            r8 = 0;
            //->21c51f38
            if (r4->oodInfo.table/*Data_49508*/[r0].afdUserDataActiveFormatFlag/*Data_20*/ != 1)
            {
               //21c51f48
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].afdUserDataActiveFormatFlag/*Data_80*/ = r8; //0
               //->21c516cc
            }
            else
            {
               //21c51f94
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].afdUserDataActiveFormatFlag/*Data_80*/ = 1;
               r4->Data_204 = r4->oodInfo.table/*Data_49508*/[r0].currAfd/*Data_24*/;
               //->21c516cc
            }
         }
         else
         {
            r8 = 0;
            r4->Data_204 = r4->decoderAfdState;
         }
         //21c516cc
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].decodedPicAspectRatio/*Data_68*/ =
            r4->oodInfo.table/*Data_49508*/[r0].decodedPicAspectRatio/*Data_4*/;

         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].currAfd/*Data_84*/ = r4->Data_204;

         if (r4->Data_204 == 2)
         {
            //->21c51dcc
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_16_9; //3;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_16_9; //3;
            //->21c5186c
         }
         else if (r4->Data_204 == 3)
         {
            //->21c51844
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_14_9; //2;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_14_9; //2;
            //21c5186c
         }
         else if (r4->Data_204 == 4)
         {
            //->21c51844
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_16_9; //3;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_16_9; //3;
            //21c5186c
         }
         else if (r4->Data_204 == 9)
         {
            //->21c5202c
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_4_3; //1;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_4_3; //1;
            //21c5186c
         }
         else if (r4->Data_204 == 10)
         {
            //->21c52194
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_16_9; //3;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_16_9; //3;
            //21c5186c
         }
         else if (r4->Data_204 == 11)
         {
            //->21c5252c
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_14_9; //2;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_14_9; //2;
            //21c5186c
         }
         else if (r4->Data_204 == 13)
         {
            //->21c51fc0
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_4_3; //1;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_14_9; //2;
            //21c5186c
         }
         else if (r4->Data_204 == 14)
         {
            //->21c525a4
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_16_9; //3;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_14_9; //2;
            //21c5186c
         }
         else if (r4->Data_204 == 15)
         {
            //->21c525e4
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = FAPI_VIDEC_AR_16_9; //3;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = FAPI_VIDEC_AR_4_3; //1;
            //21c5186c
         }
         else
         {
            //21c51754
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 
               r4->oodInfo.table/*Data_49508*/[r0].decodedPicAspectRatio/*Data_4*/;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 
               r4->oodInfo.table/*Data_49508*/[r0].decodedPicAspectRatio/*Data_4*/;
            //->21c5186c
         }
         //21c5186c
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].codedInterlaceProggState/*Data_88*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].codedInterlaceProggState/*Data_16*/;
         
         if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 2)
         {
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_INTERLACE; //0;
            //->21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 3)
         {
            //->21c518e8
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_INTERLACE; //0;
            //21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 4)
         {
            //->21c518e8
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_INTERLACE; //0;
            //21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 5)
         {
            //->21c518e8
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_INTERLACE; //0;
            //21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 6)
         {
            //->21c51f84
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_PROGRESSIVE; //1;
            //21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 8)
         {
            //->21c518e8
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_INTERLACE; //0;
            //21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 9)
         {
            //->21c518e8
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_INTERLACE; //0;
            //21c518f4
         }
         //->21c51f68
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 10)
         {
            //->21c51f84
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_PROGRESSIVE; //1;
            //21c518f4
         }
         else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 11)
         {
            //->21c51f84
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_IP_PROGRESSIVE; //1;
            //21c518f4
         }
         else
         {
            //->21c51f84
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = FAPI_VIDEC_UNKNOWN_IP; //-1;
            //21c518f4
         }
         //21c518f4
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataTopBarFlag/*Data_96*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataTopBarFlag/*Data_548*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataEndOfTopBar/*Data_100*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataEndOfTopBar/*Data_552*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataBotBarFlag/*Data_104*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataBotBarFlag/*Data_556*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataStartOfBotBar/*Data_108*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataStartOfBotBar/*Data_560*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataLeftBarFlag/*Data_112*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataLeftBarFlag/*Data_564*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataEndOfLeftBar/*Data_116*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataEndOfLeftBar/*Data_568*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataRightBarFlag/*Data_120*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataRightBarFlag/*Data_572*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].barUserDataStartOfRightBar/*Data_124*/ = 
            r4->oodInfo.table/*Data_49508*/[r0].barUserDataStartOfRightBar/*Data_576*/;
         r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 = 1;
         //->21c51a44
         break;
      }
   } //for (r0 = 0; r0 < 512; r0++)
   //21c51a44
#endif

   if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 != 1)
   {
      //21c51a64
      r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 = 0;
      //21c51a74
   }
   else
   {
      //21c51c78
   }
   //21c51a74?
   if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 == 0)
   {
      //21c51a90
      int r1;
      for (r1 = 0; r1 < 64; r1++)
      {
         //21c51ab8         
#if 0
         volatile struct Struct_1280* r0/*lr*/ = (struct Struct_1280*) 
            (r4->physicalMemoryInfoPtr->oodInfoTableStartAddress) + r1;
#else
         volatile struct Struct_1280* r0/*lr*/ = &((struct Struct_1280*) 
            (r4->physicalMemoryInfoPtr->oodInfoTableStartAddress))[r1];
#endif
         if ((r0->Data_0 == r2) ||
               (r0->Data_0) == r3)
         {
            //21c51ac8
            int sp16;
            unsigned ip;
            unsigned r8;
            unsigned r6;
            unsigned sp4 = 0;
            
            unsigned r1/*sl*/ = (r0->Data_0x400 & 0x20) >> 5;
            if (r1 == 1)
            {
               sp4 = r0->Data_0x404 & 0xFF;
            }
            
            if (r4->decoderType == 1)
            {
               //21c52058
               r8 = r0->Data_0x300 & 0xFFF;
               r6 = r0->Data_0x304 & 0xFFF;
               unsigned r5 = r0->Data_0x308 & 0x0F;
               unsigned ip_ = r0->Data_0x30c & 0x0F;
               int r3 = r0->Data_0x320 & 1;
               
               r4->vesInfo.decodedWidth = r8;
               r4->vesInfo.decodedHeight = r6;
               
               if (r3 == 0)
               {
                  sp16 = 0;
                  r4->vesInfo.proggInter = 0; 
               }
               else if (r3 == 1)
               {
                  sp16 = 1;
                  r4->vesInfo.proggInter = 1; 
               }
               else
               {
                  sp16 = -1;
                  r4->vesInfo.proggInter = -1; 
               }
               //21c520b4
               if (ip_ == 3) r4->vesInfo.vesFrameRate = 2500;
               else if (ip_ == 6) r4->vesInfo.vesFrameRate = 5000;
               else if (ip_ == 1) r4->vesInfo.vesFrameRate = 2397;
               else if (ip_ == 2) r4->vesInfo.vesFrameRate = 2400;
               else if (ip_ == 4) r4->vesInfo.vesFrameRate = 2997;
               else if (ip_ == 5) r4->vesInfo.vesFrameRate = 3000;
               else if (ip_ == 7) r4->vesInfo.vesFrameRate = 5994;
               else if (ip_ == 8) r4->vesInfo.vesFrameRate = 6000;
               else r4->vesInfo.vesFrameRate = 0;            
               
               func_21c4894c/*219262c0*/(r4);
               
               if (r5 == 2)
               {
                  //21c52594
                  r4->vesInfo.vesAspectRatio = 1;
                  ip = r4->vesInfo.vesAspectRatio;
                  //->21c51b14
               }
               else if (r5 == 3) 
               {
                  //21c52588
                  r4->vesInfo.vesAspectRatio = r5; //3; //r5;
                  ip = r4->vesInfo.vesAspectRatio;
                  //->21c51b14
               }
               else if (r5 == 4)
               {
                  //21c52588
                  r4->vesInfo.vesAspectRatio = r5; //4; //r5;
                  ip = r4->vesInfo.vesAspectRatio;
                  //->21c51b14
               }
               else
               {
                  r4->vesInfo.vesAspectRatio = 0;
                  ip = r4->vesInfo.vesAspectRatio;
                  //->21c51b14
               }               
               //ip = r4->vesInfo.vesAspectRatio;
               //->21c51b14
            }
            else if (r4->decoderType == 2)
            {
               //21c522cc
               unsigned Data_0x20/*r0*/ = (r0->Data_0x20 & 4) >> 2;
               unsigned Data_0x2c/*r1*/ = r0->Data_0x2c & 0x0f;
               unsigned Data_0x190/*sp12*/ = r0->Data_0x190 & 0xff;
               unsigned Data_0x194/*sp8*/ = r0->Data_0x194 & 0xff;
               unsigned Data_0x19c/*r3*/ = r0->Data_0x19c & 0xff;
               unsigned Data_0x204 = r0->Data_0x204 & 0xff;
               unsigned Data_0x240 = r0->Data_0x240 & 1;
               unsigned Data_0x244 = r0->Data_0x244 & 0xff;
               unsigned Data_0x248 = r0->Data_0x248 & 0xffff;
               unsigned Data_0x24c = r0->Data_0x24c & 0xffff;
               unsigned Data_0x258 = r0->Data_0x258;
               unsigned Data_0x25c = r0->Data_0x25c;

               if (Data_0x190 == 0)
               {
                  r8 = Data_0x190;
                  r4->vesInfo.decodedWidth = r8;
               }
               else
               {
                  r8 = (Data_0x190+1)*16;
                  r4->vesInfo.decodedWidth = r8;
               }
               
               r6 = Data_0x194*16;
               r4->vesInfo.decodedHeight = r6;
               
               if (Data_0x19c == 1)
               {
                  //->21c5257c
                  sp16 = 1;
                  r4->vesInfo.proggInter = 1; 
                  //->21c52374
               }
               //21c5234c
               else if (Data_0x204 == 1)
               {
                  //->21c5257c
                  sp16 = 0;
                  r4->vesInfo.proggInter = 0; 
                  //->21c52374
               }
               //21c5235c
               else if (Data_0x20 == 1)
               {
                  //->21c52568
                  if ((Data_0x2c == 1) ||
                        (Data_0x2c == 2) ||
                        (Data_0x2c == 3) ||
                        (Data_0x2c == 4) ||
                        (Data_0x2c == 5) ||
                        (Data_0x2c == 6))
                  {
                     sp16 = 0;
                     r4->vesInfo.proggInter = 0; 
                     //->21c52374
                  }
                  //21c52678
                  else if ((Data_0x2c == 0) ||
                        (Data_0x2c == 7) ||
                        (Data_0x2c == 8))
                  {
                     sp16 = 1;
                     r4->vesInfo.proggInter = 1; 
                     //->21c52374
                  }
                  else
                  {
                     sp16 = -1;
                     r4->vesInfo.proggInter = -1; 
                     //->21c52374
                  }
               }
               else
               {
                  sp16 = -1;
               }
               //21c52374
               if ((Data_0x258/*r2*/ != 0) && 
                     (Data_0x25c/*ip*/ != 0))
               {
                  //21c52380
                  if (Data_0x258/*r2*/ == 1)
                  {
                     //21c52660
                     uint64_t r0_r1 = (uint64_t)Data_0x25c * 100;
                     r0_r1 >>= 1;
                     r4->vesInfo.vesFrameRate = r0_r1;
                  }
                  else
                  {
                     //21c52388
                     r4->vesInfo.vesFrameRate = 
                        (uint32_t)(((uint64_t)Data_0x25c * 100)/Data_0x258) >> 1;
                  }
               }
               //21c523a0
               func_21c4894c/*219262c0*/(r4);
               
               if (Data_0x240/*sp32*/ == 1)
               {
                  //21c523b4
                  if (Data_0x244/*sp28*/ != 0)
                  {
                     unsigned r0 = 0;
                     unsigned ip_ = 0;
                     
                     if (Data_0x244 == 0xFF)
                     {
                        //21c526a4
                        r0 = Data_0x248/*sp24*/;
                        ip_ = Data_0x24c/*sp20*/;
                        //->21c524a4
                     }
                     //21c523c8
                     else if ((Data_0x244 - 14) < 241)
                     {
                        //21c52158
                        r4->vesInfo.vesAspectRatio = 0;
                     }
                     else
                     {
                        //21c523d4
                        if (Data_0x244 == 1)
                        {
                           r0 = 1;
                           ip_ = 1;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 2)
                        {
                           r0 = 12;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 3)
                        {
                           r0 = 10;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 4)
                        {
                           r0 = 16;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 5)
                        {
                           r0 = 40;
                           ip_ = 33;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 6)
                        {
                           r0 = 24;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 7)
                        {
                           r0 = 20;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 8)
                        {
                           r0 = 32;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 9)
                        {
                           r0 = 80;
                           ip_ = 33;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 10)
                        {
                           r0 = 18;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 11)
                        {
                           r0 = 15;
                           ip_ = 11;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 12)
                        {
                           r0 = 64;
                           ip_ = 33;
                           //->21c524a4
                        }
                        else if (Data_0x244 == 13)
                        {
                           r0 = 160;
                           ip_ = 99;
                           //->21c524a4
                        }
#if 0
                        else
                        {
                           //21c52158
                           r4->vesInfo.vesAspectRatio = 0;
                        }
#endif
                     }
                     //21c524a4
                     r4->vesInfo.vesAspectRatio = 
                        func_21926c7c(r0, ip_, Data_0x190+1, Data_0x194);
                  }
                  else
                  {
                     //21c52158
                     r4->vesInfo.vesAspectRatio = 0;
                  }
               }
               //21c52160
               ip = r4->vesInfo.vesAspectRatio;
               //->21c51b14
            }
            else
            {
               //21c51b00
               
               //TODO
               r8 = 0;
               r6 = 0;
               sp16 = -1;
               ip = 0;
            }
            //21c51b14
#if 0
            if (r4->decoderAfdState == 1)
            {
               r4->Data_204 = 0;
               //->21c51b38
            }
            else if (r4->decoderAfdState == 17)
            {
               r4->Data_204 = 0;
               //->21c51b38
            }
#else
            if ((r4->decoderAfdState == -1) ||
                  (r4->decoderAfdState == 17))
            {
               r4->Data_204 = 0;
               //->21c51b38
            }
#endif
            //21c51b2c
            else if (r4->decoderAfdState == 16)
            {
               //21c52558
               if (r1 == 1)
               {
                  r4->Data_204 = sp4;
               }
            }
            else
            {
               r4->Data_204 = r4->decoderAfdState;
            }
            //21c51b38
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].afdUserDataActiveFormatFlag/*Data_80*/ = r1; //sl;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].decodedWidth/*Data_16*/ = r8;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].decodedHeight/*Data_20*/ = r6;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].decodedPicAspectRatio/*Data_68*/ = ip;
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].currAfd/*Data_84*/ = r4->Data_204;
            //21c51bb0            
            if (r4->Data_204 == 2)
            {
               //->21c51e2c
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 3;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 3;
               //21c51e54
            }
            else if (r4->Data_204 == 3)
            {
               //21c52168
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 2;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 2;
               //->21c51e54
            }
            else if (r4->Data_204 == 4)
            {
               //->21c51e2c
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 3;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 3;
               //21c51e54
            }
            //21c51bd4
            else if (r4->Data_204 == 9)
            {
               //->21c52000
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 1;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 1;
               //21c51e54
            }
            //21c51bdc
            else if (r4->Data_204 == 10)
            {
               //->21c51e2c
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 3;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 3;
               //21c51e54
            }
            //21c51be4
            else if (r4->Data_204 == 11)
            {
               //->21c52168
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 2;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 2;
               //21c51e54
            }
            //21c51bec
            else if (r4->Data_204 == 13)
            {
               //->21c52630
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 1;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 2;
               //21c51e54
            }
            //21c51bf4
            else if (r4->Data_204 == 14)
            {
               //21c51bf8
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 3;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 2;
               //21c51e54
            }
            //21c51c14
            else if (r4->Data_204 == 15)
            {
               //21c52600
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = 3;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = 1;
               //21c51e54
            }
            else
            {
               //21c51c1c
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL0/*Data_72*/ = ip;
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].activePicAspectRatioL1/*Data_76*/ = ip;
            }
            //21c51e54
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].codedInterlaceProggState/*Data_88*/ = sp16;
            
            if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 2)
            {
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 0;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 3)
            {
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 0;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 4)
            {
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 0;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 5)
            {
               //->21c51ff0
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 0;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 6)
            {
               //->21c51ff0
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 1;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 8)
            {
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 0;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 9)
            {
               //->21c525d4
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 0;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 10)
            {
               //->21c525d4
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 1;
               //->21c51f0c
            }
            else if (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].displayOrderInfo/*Data_24*/ == 11)
            {
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = 1;
               //->21c51f0c
            }
            else
            {
               r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].readoutInterlaceProggState/*Data_92*/ = -1;
               //->21c51f0c
            }
            //21c51f0c
            r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 = 3;
            //->21c51c78
            break;
         }
      }
      //->21c51c54
   }
   //21c51c44
   if ((r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 != 1) &&
         (r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 != 3))
   {
      //21c51c54
      r4->frameInfo.decodedPic/*Data_698744*/[r4->frameInfo.wPtr/*Data_705080*/].Data_128 = 2;
   }
   //21c51c78
}


/* 21c5126c - todo */
uint32_t FAPI_VIDEC_IsrDecode0(void)
{
   uint32_t writePos, readPos;
   FAPI_VIDEC_VideoDecoderHandleT* fp;
   FAPI_VIDEC_VideoDecoderIsrDataT* r7;
   uint32_t res = 0;
   uint32_t isrStatus = FREG_VD_GetIntStatusToMcpu();

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_IsrDecode0: isrStatus=0x%x\n",
         isrStatus);

   FREG_VD_SetIntClearToMcpu(isrStatus);

   fp = Data_21f67278;

   if (fp == 0)
   {
      return res;
   }

   r7 = fp->isrDataPtr;

   if ((r7 == 0) || (r7->inUse == 0))
   {
      return res;
   }
   //21c512a8
   r7->isrStatus = isrStatus & ~r7->isrMask;

   if (r7->bootState == FAPI_VIDEC_REQUEST_TO_BOOT)
   {
      //->21c51310
      if (r7->isrStatus & PCPU_MESSAGE_BOOT_DONE) //0x800)
      {
         r7->bootState = FAPI_VIDEC_BOOTED;
         return res;
      }
   }
   //21c512c4
   if (r7->startStopState == FAPI_VIDEC_REQUEST_TO_START)
   {
      //21c51330
      if (r7->isrStatus & PCPU_MESSAGE_DEC_START) //0x100)
      {
         //21c51338
         r7->startStopState = FAPI_VIDEC_STARTED;
         return res;
      }
      //21c512d8
   }
   //21c512d0
   else if (r7->startStopState == FAPI_VIDEC_REQUEST_TO_STOP)
   {
      //->21c51e10
      if (r7->isrStatus & PCPU_MESSAGE_DECODE_END) //0x400)
      {
         //->21c51338
         r7->startStopState = FAPI_VIDEC_STOPPED; //++; // = 2;
         return res;
      }
      //21c512d8
   }
   //21c512d8
   if (r7->resetState == 2)
   {
      //->21c51df8 / 21927944
      if (r7->isrStatus & PCPU_MESSAGE_RESET_READY) //0x200)
      {
         //21c51dfc
         r7->resetState++; // = 3;
         return 0; //->21c51304
      }
      //21c512e4
   }
   
//      res = Data_21f67278; //fp;
//   res = (uint32_t) Data_21f67278; //fp;

   //21c512e4
   if (r7->isrStatus & PCPU_MESSAGE_VCPB_FREE_FIFO_UPDATE) //0x2000)
   {
      //->21c51784         
      writePos = FREG_VD_Read32(VCPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0);
      readPos = FREG_VD_Read32(VCPB_FREE_IDX_FIFO_READ_POS_ADDR_0);

      FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_IsrDecode0: PCPU_MESSAGE_VCPB_FREE_FIFO_UPDATE, writePos=%d, readPos=%d\n",
            writePos, readPos);

      int r4 = writePos - readPos;

      if (r4 < 0) r4 += VCPB_FREE_IDX_FIFO_MAX_NUM;
      
//         while (r4 > 0)
      int r6;
      for (r6 = 0; r6 != r4; )
      {
         //->21c51824
         if (r7->Data_120 == 1)
         {
            fapi_videc_get_ood_info(r7);
            fapi_videc_get_ood_info(r7);
         }
         else
         {
            //21c517b4
            fapi_videc_get_ood_info(r7);
         }
         //21c517bc
         if (r7->entropyDecInfoCbk != 0)
         {
            (r7->entropyDecInfoCbk)(&r7->entropyDecInfoData,
                                     r7->entropyOptData);
         }
         //21c517e0
         r7->audInfo.codedPic/*Data_252*/[r7->audInfo.fPtr/*Data_49412*/].state = FAPI_VIDEC_AUD_STATE_FREE; //Data_60 = 0;

         if (r7->audInfo.fPtr/*Data_49412*/ >= 767)
         {
            r7->audInfo.fPtr/*Data_49412*/ = 0;
         }
         else
         {
            r7->audInfo.fPtr/*Data_49412*/++;
         }

         r6++; 
//            r4--;
         
         if (readPos >= 95)
         {
            readPos = 0;
         }
         else
         {
            readPos++;
         }
      }
      //->21c51e1c
      FREG_VD_Write32(VCPB_FREE_IDX_FIFO_READ_POS_ADDR_0, readPos);
      //->21c512ec

   }
   //21c512ec
   if (r7->isrStatus & PCPU_MESSAGE_VDPB_INFO_UPDATE) //0x1000)
   {
      //->21c51350
      writePos = FREG_VD_Read32(VDPB_DEC_DONE_IDX_FIFO_WRITE_POS_ADDR_0);
      readPos = FREG_VD_Read32(VDPB_DEC_DONE_IDX_FIFO_READ_POS_ADDR_0);

      FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_IsrDecode0: PCPU_MESSAGE_VDPB_INFO_UPDATE, writePos=%d, readPos=%d\n",
            writePos, readPos);

      int sp36 = writePos - readPos;

      if (sp36 < 0) sp36 += VDPB_DEC_DONE_IDX_FIFO_MAX_NUM; //48;

      int sp;
      for (sp = 0; sp != sp36; )
      {
         //21c51390
         r7->frameInfo.decodedPic/*Data_698744*/[r7->frameInfo.wPtr/*Data_705080*/].displayFrameBank/*Data_4*/ =
            FREG_VD_Read32(VDPB_DEC_DONE_IDX_FIFO_START_ADDR_0 + (readPos << 2));
         
         unsigned r11 = 0;
         
         unsigned r10/*r5*/ = r7->frameInfo.decodedPic/*Data_698744*/[r7->frameInfo.wPtr/*Data_705080*/].displayFrameBank/*Data_4*/;
         //r2 = r7->physicalMemoryInfoPtr->vdpbInfoTableStartAddress;
         //r8 = r2 + r5*96;
         volatile uint32_t* r8 = (void*)
            r7->physicalMemoryInfoPtr->vdpbInfoTableStartAddress +
            r10 * VDPB_INFO_TABLE_ENTRY_SIZE;
         //21c513f0
         r7->Data_28 = FAPI_TIMER_GetTimeStamp(1000);
         
         uint32_t r0 = r8[3];
         
         if (r7->decoderPlaybackMode == FAPI_VIDEC_I_ONLY_PLAYBACK_MODE) //3)
         {
            //21c51d8c
            r11 = (r8[6] | r8[7]) & 0xFF;
         }
         
         FAPI_SYS_PRINT_DEBUG(6, "r0=%d, r11=%d\n",
               r0, r11);
         
         //21c51414
         if ((r0 > 1) && (r11 == 0))
         {
            //21c51428
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].displayOrderInfo/*Data_24*/ =
               r8[3];               
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].serialNum =
               r8[0];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].displayWidth/*Data_8*/ =
               r8[1];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].displayHeight/*Data_12*/ =
               r8[2];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].topFieldSerialNo/*Data_28*/ =
               r8[4];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].botFieldSerialNo/*Data_32*/ =
               r8[5];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].topDecError/*Data_56*/ =
               r8[6] & 0xFF;
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].botDecError/*Data_60*/ =
               r8[7] & 0xFF;
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].ptsValidFlag/*Data_36*/ =
               r8[8] & 1;
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].dtsValidFlag/*Data_40*/ =
               r8[9] & 1;
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].pts/*Data_44*/ =
               r8[10];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].dts/*Data_48*/ =
               r8[11];
            
            r7->frameInfo.decodedPic[r7->frameInfo.wPtr].vdpbDispCount/*Data_64*/ =
               r7->vdpbIdx; //705108;
            
            FAPI_SYS_PRINT_DEBUG(6, "r7->frameInfo.wPtr=%d\n",
                  r7->frameInfo.wPtr);
            FAPI_SYS_PRINT_DEBUG(6, "displayOrderInfo=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].displayOrderInfo);
            FAPI_SYS_PRINT_DEBUG(6, "serialNum=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].serialNum);
            FAPI_SYS_PRINT_DEBUG(6, "displayWidth=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].displayWidth);
            FAPI_SYS_PRINT_DEBUG(6, "displayHeight=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].displayHeight);
            FAPI_SYS_PRINT_DEBUG(6, "topFieldSerialNo=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].topFieldSerialNo);
            FAPI_SYS_PRINT_DEBUG(6, "botFieldSerialNo=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].botFieldSerialNo);
            FAPI_SYS_PRINT_DEBUG(6, "topDecError=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].topDecError);
            FAPI_SYS_PRINT_DEBUG(6, "botDecError=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].botDecError);
            FAPI_SYS_PRINT_DEBUG(6, "ptsValidFlag=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].ptsValidFlag);
            FAPI_SYS_PRINT_DEBUG(6, "dtsValidFlag=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].dtsValidFlag);
            FAPI_SYS_PRINT_DEBUG(6, "pts=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].pts);
            FAPI_SYS_PRINT_DEBUG(6, "dts=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].dts);
            FAPI_SYS_PRINT_DEBUG(6, "vdpbDispCount=%d\n",
                  r7->frameInfo.decodedPic[r7->frameInfo.wPtr].vdpbDispCount);

            //21c515e0
            r7->vdpbSerialNum = //Data_705100 = 
               r7->frameInfo.decodedPic/*Data_698744*/[r7->frameInfo.wPtr/*Data_705080*/].serialNum;

            r7->frameInfo.decodedPic/*Data_698744*/[r7->frameInfo.wPtr/*Data_705080*/].state/*Data_52*/ = 0;

            //TODO
            func_219263c0(r7);
            
            if (r7->frameInfo.decodedPic/*Data_698744*/[r7->frameInfo.wPtr/*Data_705080*/].botFieldSerialNo/*Data_32*/ != 
               r7->frameInfo.decodedPic/*Data_698744*/[r7->frameInfo.wPtr/*Data_705080*/].topFieldSerialNo/*Data_28*/)
            {
               r7->Data_705104 += 2;
            }
            else
            {
               r7->Data_705104++;
            }
            
            r7->vdpbDecodedFramesAvailable++;
            
            r7->vdpbIdx++; //Data_705108++;

            if (r7->frameInfo.wPtr/*Data_705080*/ >= 47)
            {
               r7->frameInfo.wPtr/*Data_705080*/ = 0;
            }
            else
            {
               r7->frameInfo.wPtr/*Data_705080*/++;
            }               
            //21c51cf0
         } //if ((r0 > 1) && (r11 == 0))
         else
         {
            //21c51d4c
            uint32_t r4 = FREG_VD_Read32(0x600485c0);
            
            FREG_VD_Write32(0x60048500 + (r4 << 2), r10);
                           
            if (r4 >= 47)
            {
               r4 = 0;
            }
            else
            {
               r4++;
            }
            
            FREG_VD_Write32(0x600485c0, r4); 
            
            FREG_VD_SetIntReqToPcpu(0x10000000);
            //->21c51cf0
         }
         //21c51cf0
         if (r7->frameDecodedCbk != 0)
         {
            (r7->frameDecodedCbk)(r7->frameDecodedOptData);
            
            r7->frameDecodedCbk = 0;
            r7->frameDecodedOptData = 0;
         }
         //21c51d18
         //sp++, r9 = (r9 < 47)? r9+1: 0;
         if (readPos >= 47)
         {
            readPos = 0;
         }
         else
         {
            readPos++;
         }

         sp++;
      }
      //21c51d3c
      FREG_VD_Write32(VDPB_DEC_DONE_IDX_FIFO_READ_POS_ADDR_0, readPos);         
      //->21c512f8
   }
   //21c512f8 / 21927d6c
   res = (uint32_t) fp;

   fapi_videc_update_buffer_info(r7);

   return res;
}


/* 21c47280 - complete */
void FAPI_VIDEC_BsrDecode0(uint32_t a)
{
//   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_BsrDecode0\n"); 
}


/* 21c42e8c - complete */
void func_21c42e8c(int ip, int r1, int r2, int lr)
{
   int32_t res = 0;

   if (videcDriverIsInitialized == 0)
   {
      if ((ip != 0) &&
            (r1 != 0) &&
            (r2 != 0) &&
            (lr != 0))
      {
         Data_21efc808.Data_0 = 1;
         Data_21efc808.Data_4 = ip; //0x20000000
         Data_21efc808.Data_8 = r1; //0x4000000
         Data_21efc808.Data_12 = r2; //0x40000000
         Data_21efc808.Data_16 = lr; //0x4000000
      }
      else
      {
         Data_21efc808.Data_0 = 0;
         Data_21efc808.Data_4 = 0;
         Data_21efc808.Data_8 = 0;
         Data_21efc808.Data_12 = 0;
         Data_21efc808.Data_16 = 0;

         res = -28139;
      }
   }
   else
   {
      res = -28003;
   }

   Data_21efc808.Data_20 = res;
}


/* 21c42f20 - complete */
void FAPI_VIDEC_PreInit(const FAPI_VIDEC_DecoderNumberEnumT
                                  piMemoryForDecoderNumber,
                        const uint32_t piMemoryAllocationType)
{
   unsigned i = 0;

   if ((Data_21efc808.Data_0 == 1) &&
         (Data_21efc808.Data_20 == 0))
   {
      if (videcDriverIsInitialized != 0)
      {
         return;
      }

      if (piMemoryForDecoderNumber == FAPI_VIDEC_DECODER_NUMBER_0)
      {
         videcMemoryData[i].piDone = 0;
         videcMemoryData[i].piError = 0;
         videcMemoryData[i].piMemoryForDecoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
         videcMemoryData[i].piMemoryAllocationType = 0;

         if (Data_21efc808.Data_4 ==
               (piMemoryAllocationType & Data_21efc808.Data_4))
         {
            if ((Data_21efc808.Data_4 <= piMemoryAllocationType) &&
                  (piMemoryAllocationType < (Data_21efc808.Data_8 + Data_21efc808.Data_4)))
            {
               if ((piMemoryAllocationType & 0xfff) == 0)
               {
                  videcMemoryData[i].piDone = 1;
                  videcMemoryData[i].piMemoryForDecoderNumber = piMemoryForDecoderNumber;
                  videcMemoryData[i].piMemoryAllocationType = piMemoryAllocationType;
               }
               else
               {
                  videcMemoryData[i].piError = -28135;
               }
            }
         }
         else if (Data_21efc808.Data_12 ==
                  (piMemoryAllocationType & Data_21efc808.Data_12))
         {
            if ((Data_21efc808.Data_12 <= piMemoryAllocationType) &&
                  (piMemoryAllocationType < (Data_21efc808.Data_16 + Data_21efc808.Data_12)))
            {
               if ((piMemoryAllocationType & 0xfff) == 0)
               {
                  videcMemoryData[i].piDone = 1;
                  videcMemoryData[i].piMemoryForDecoderNumber = piMemoryForDecoderNumber;
                  videcMemoryData[i].piMemoryAllocationType = piMemoryAllocationType;
               }
               else
               {
                  videcMemoryData[i].piError = -28135;
               }
            }
         }
         else if (piMemoryAllocationType == (uint32_t)-1)
         {
            videcMemoryData[i].piDone = 1;
            videcMemoryData[i].piMemoryForDecoderNumber = piMemoryForDecoderNumber;
            videcMemoryData[i].piMemoryAllocationType = piMemoryAllocationType;
         }
         else if (piMemoryAllocationType == (uint32_t)-2)
         {
            videcMemoryData[i].piDone = 1;
            videcMemoryData[i].piMemoryForDecoderNumber = piMemoryForDecoderNumber;
            videcMemoryData[i].piMemoryAllocationType = piMemoryAllocationType;
         }
         else
         {
            videcMemoryData[i].piError = -28135;
         }
      }
   }
   else
   {
      for (i = 0; i < 1; i++)
      {
         videcMemoryData[i].piError = Data_21efc808.Data_20;
      }
   }
}


#define AxiSeqAreaSize 0x100000
#define AxiCcAreaSize 0x480000
#define AxiMvAreaSize 0x80000
#define AxiDvAreaSize 0x2a8000
#define VideoStreamAreaSize 0x800000
#define VcpbInfoTableSize 0x2400
#define VdpbInfoTableSize 0x1200
#define PcpuWorkAreaSize 0x100000
#define DecStartParamsSize 0x100
#define OodInfoTableSize 0x14000



static int32_t func_218ccd34(FAPI_VIDEC_VideoDecoderMemoryDataT* a)
{
   int32_t err_code = 0;
   
//   FAPI_SYS_PRINT_MSG("func_218ccd34\n");

   a->segmentParams.sizeMBytes = 22;
   a->segmentParams.memoryMode = 1;
   a->segmentParams.functionMode = 1;
   a->segmentParams.strategyMode = 1;
   a->segmentParams.alignmentBits = 12;

   a->segmentHandle = FAPI_MMU_CreateSegment(
         &a->segmentParams, &err_code);
   
   if (a->segmentHandle != 0)
   do
   {
      //21c46bc8
      a->virtualMemoryInfo.axiSeqAreaStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x100000);
      
      if (a->virtualMemoryInfo.axiSeqAreaStartAddress == 0)
      {
         //21c46d10
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.axiSeqAreaStartAddress = 0;
         break;
      }
      //21c46bec
      a->virtualMemoryInfo.axiWrapperStartAddress = 
         a->virtualMemoryInfo.axiSeqAreaStartAddress;
      a->virtualMemoryInfo.axiSeqAreaSize = 0x100000;
      
      a->virtualMemoryInfo.axiCcAreaStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x480000);

      if (a->virtualMemoryInfo.axiCcAreaStartAddress == 0)
      {
         //21c46d3c
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.axiCcAreaSize = 0;
         break;
      }
      //21c46c24
      a->virtualMemoryInfo.axiCcAreaSize = 0x480000;
      
      a->virtualMemoryInfo.axiMvAreaStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x80000);
      
      if (a->virtualMemoryInfo.axiMvAreaStartAddress == 0)
      {
         //21c46d58
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.axiMvAreaSize = 0;
         break;
      }
      //21c46c58
      a->virtualMemoryInfo.axiMvAreaSize = 0x80000;
      
      a->virtualMemoryInfo.axiDvAreaStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x2a8000);
      
      if (a->virtualMemoryInfo.axiDvAreaStartAddress == 0)
      {
         //21c46d74
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.axiDvAreaSize = 0;
         break;
      }
      //21c46c8c
      a->virtualMemoryInfo.axiDvAreaSize = 0x2a8000;
      
      a->virtualMemoryInfo.videoStreamAreaStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x800000);
      
      if (a->virtualMemoryInfo.videoStreamAreaStartAddress == 0)
      {
         //21c46d90
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.videoStreamAreaSize = 0;
         break;
      }
      //21c46cc0
      a->virtualMemoryInfo.videoStreamAreaSize = 0x800000;
      
      a->virtualMemoryInfo.vcpbInfoTableStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x2400);
      
      if (a->virtualMemoryInfo.vcpbInfoTableStartAddress == 0)
      {
         //21c46cf4
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.vcpbInfoTableSize = 0;
         break;
      }
      //21c46db0
      a->virtualMemoryInfo.vcpbInfoTableSize = 0x2400;
      
      a->virtualMemoryInfo.vdpbInfoTableStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x1200);
   
      if (a->virtualMemoryInfo.vdpbInfoTableStartAddress == 0)
      {
         //21c46de4
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.vdpbInfoTableSize = 0;
         break;
      }
      //21c46e00
      a->virtualMemoryInfo.vdpbInfoTableSize = 0x1200;
      
      a->virtualMemoryInfo.pcpuWorkAreaStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x100000);

      if (a->virtualMemoryInfo.pcpuWorkAreaStartAddress == 0)
      {
         //21c46e34
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.pcpuWorkAreaSize = 0;
         break;
      }
      //21c46e50
      a->virtualMemoryInfo.pcpuWorkAreaSize = 0x100000;

      a->virtualMemoryInfo.decStartParamsStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x100);

      if (a->virtualMemoryInfo.decStartParamsStartAddress == 0)
      {
         //21c46e84
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.decStartParamsSize = 0;
         break;
      }
      //21c46ea0
      a->virtualMemoryInfo.decStartParamsSize = 0x100;

      a->virtualMemoryInfo.oodInfoTableStartAddress = (uint32_t)
         FAPI_SYS_MALLOC_SEGMENT(a->segmentHandle, 0x14000);

      if (a->virtualMemoryInfo.oodInfoTableStartAddress == 0)
      {
         //21c46ed4
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE; //-28132;
         a->virtualMemoryInfo.oodInfoTableSize = 0;
         break;
      }
      //21c46ef0
      a->virtualMemoryInfo.oodInfoTableSize = 0x14000;

      a->virtualMemoryInfo.memoryInfoAvailable = 1;

      a->physicalMemoryInfo.axiSeqAreaStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.axiSeqAreaStartAddress);

      if (a->physicalMemoryInfo.axiSeqAreaStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.axiSeqAreaSize = 0;
         break;
      }
      //21c46f40
      a->physicalMemoryInfo.axiWrapperStartAddress =
         a->physicalMemoryInfo.axiSeqAreaStartAddress;
      a->physicalMemoryInfo.axiSeqAreaSize = a->virtualMemoryInfo.axiSeqAreaSize;

      a->physicalMemoryInfo.axiCcAreaStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.axiCcAreaStartAddress);

      if (a->physicalMemoryInfo.axiCcAreaStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.axiCcAreaSize = 0;
         break;
      }
      //21c46f8c
      a->physicalMemoryInfo.axiCcAreaSize = a->virtualMemoryInfo.axiCcAreaSize;

      a->physicalMemoryInfo.axiMvAreaStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.axiMvAreaStartAddress);

      if (a->physicalMemoryInfo.axiMvAreaStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.axiMvAreaSize = 0;
         break;
      }
      //21c46fd4
      a->physicalMemoryInfo.axiMvAreaSize = a->virtualMemoryInfo.axiMvAreaSize;

      a->physicalMemoryInfo.axiDvAreaStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.axiDvAreaStartAddress);

      if (a->physicalMemoryInfo.axiDvAreaStartAddress == -1)
      {
         //21c47210
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.axiDvAreaSize = a->virtualMemoryInfo.axiDvAreaSize; //0;
         break;
      }
      //21c4700c
      a->physicalMemoryInfo.axiDvAreaSize = a->virtualMemoryInfo.axiDvAreaSize;

      a->physicalMemoryInfo.videoStreamAreaStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.videoStreamAreaStartAddress);

      if (a->physicalMemoryInfo.videoStreamAreaStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.videoStreamAreaSize = 0;
         break;
      }
      //21c47054
      a->physicalMemoryInfo.videoStreamAreaSize = a->virtualMemoryInfo.videoStreamAreaSize;

      a->physicalMemoryInfo.vcpbInfoTableStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.vcpbInfoTableStartAddress);

      if (a->physicalMemoryInfo.vcpbInfoTableStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.vcpbInfoTableSize = 0;
         break;
      }
      //21c4709c
      a->physicalMemoryInfo.vcpbInfoTableSize = a->virtualMemoryInfo.vcpbInfoTableSize;

      a->physicalMemoryInfo.vdpbInfoTableStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.vdpbInfoTableStartAddress);

      if (a->physicalMemoryInfo.vdpbInfoTableStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.vdpbInfoTableSize = 0;
         break;
      }
      //21c470e4
      a->physicalMemoryInfo.vdpbInfoTableSize = a->virtualMemoryInfo.vdpbInfoTableSize;

      a->physicalMemoryInfo.pcpuWorkAreaStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.pcpuWorkAreaStartAddress);

      if (a->physicalMemoryInfo.pcpuWorkAreaStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.pcpuWorkAreaSize = 0;
         break;
      }
      //21c4712c
      a->physicalMemoryInfo.pcpuWorkAreaSize = a->virtualMemoryInfo.pcpuWorkAreaSize;

      a->physicalMemoryInfo.decStartParamsStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.decStartParamsStartAddress);

      if (a->physicalMemoryInfo.decStartParamsStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.decStartParamsSize = 0;
         break;
      }
      //21c47174
      a->physicalMemoryInfo.decStartParamsSize = a->virtualMemoryInfo.decStartParamsSize;

      a->physicalMemoryInfo.oodInfoTableStartAddress =
            FAPI_SYS_GET_PHYSICAL_ADDRESS(a->virtualMemoryInfo.oodInfoTableStartAddress);

      if (a->physicalMemoryInfo.oodInfoTableStartAddress == -1)
      {
         //21c47230
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE; //-28134;
         a->physicalMemoryInfo.oodInfoTableSize = 0;
         break;
      }
      //21c471a8
      //a->physicalMemoryInfo.oodInfoTableSize = a->virtualMemoryInfo.oodInfoTableSize;

      a->virtualMemoryInfo.ramifsStartAddress =
            FAPI_SYS_GET_VIRTUAL_ADDRESS(Data_21efc808.Data_4);

      if (a->virtualMemoryInfo.ramifsStartAddress == -1)
      {
         err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_VIRTUAL_ADDRESS_UNAVAILABLE; //-28133;
         a->virtualMemoryInfo.ramifsStartAddress = 0;
         break;
      }

      a->physicalMemoryInfo.ramifsStartAddress = Data_21efc808.Data_4;

      a->physicalMemoryInfo.memoryInfoAvailable = 1;
   }
   while (0);
   else 
   {
      //->21c46d28
      err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_SEGMENT_ALLOCATION_FAILURE;
      //->21c4685c
   }
   
   return err_code;
}


/* 21c45674 - complete */
void fapi_videc_clear_handle(FAPI_VIDEC_VideoDecoderHandleT* a)
{
//   FAPI_SYS_PRINT_MSG("fapi_videc_clear_handle\n");

   a->inUse = 0;
   strncpy(a->coreName, "Unknown Decoder", 32);
   a->coreID = (uint64_t)-1;
   a->baseAddress = 0;
   a->decoderBufferSize = 0;
   a->vBankType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
   a->coreSel = -1;
   a->bankSize = 0;
   a->bankNum = 0;
   a->bankNumForBumping = 0;
   a->opParams.version = FAPI_VIDEC_VERSION;
   a->opParams.decoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
   a->opParams.decoderType = FAPI_VIDEC_UNKNOWN_DECODER;
   a->opParams.decodeFrameBankSizeType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
   a->opParams.decoderPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE;
   a->opParams.decoderAfdState = FAPI_VIDEC_UNKNOWN_AFD_STATE;
   a->opParams.decoderDelimiterType = FAPI_VIDEC_UNKNOWN_DELIMITER;
   a->virtualMemoryInfoPtr = 0;
   a->physicalMemoryInfoPtr = 0;
   a->isrDataPtr = 0;
   a->firmwareVersionInFlash = 0;
   a->firmwareVersionSupported = 0;
   a->firmwareVersionMatch = FAPI_VIDEC_UNKNOWN_VERSION_MATCH_STATE;
   a->decoderDisplayMode = FAPI_VIDEC_UNKNOWN_DISPLAY_MODE;
   a->associatedPesParser = FAPI_VIDEC_UNKNOWN_PESPARSER;
   a->ptsLocation = 0;

   a->Start = 0;
   a->Stop = 0;
   a->ShutDown = 0;
   a->Reset = 0;
   a->EnableDisable = 0;
   a->GetVesParams = 0;
   a->GetVesBufferPosition = 0;
   a->GetVesBufferSize = 0;
   a->GetVesFillLevel = 0;
   a->GetVesAvailableSpace = 0;
   a->GetState = 0;
   a->GetHealth = 0;
   a->GetDecodingLatency = 0;
   a->AudCallback = 0;
   a->Recover = 0;
   a->DecodeSingleMpegIFrame = 0;
   a->DisplaySingleMpegIFrame = 0;
   a->DecodeSequenceOfMpegIFrame = 0;
   a->DisplaySequenceOfMpegIFrame = 0;
   a->SetPlaybackMode = 0;
   a->SetPlaybackEnvironment = 0;
   a->SetEntropyDecInfoCallback = 0;
   a->SetVideoDecInfoCallback = 0;
   a->SetAutoScaleCallback = 0;
   a->SetDecoderToHdEncoder = 0;
   a->SetPesParserToDecoder = 0;
   a->SetFrameDecodedCallback = 0;
   a->SetFrameAvailableCallback = 0;
   a->SetVesOverflowCallback = 0;
   a->SetMpegIFrameMode = 0;
   a->SetChannelId = 0;
   a->SetParamChangeCallback = 0;
   a->SetAfdState = 0;
}


/* 21c44720 - complete */
void fapi_videc_release_memory_info_data(FAPI_VIDEC_MemoryInfoDataT* a)
{
//   FAPI_SYS_PRINT_MSG("fapi_videc_release_memory_info_data\n");
   
   if (a != 0)
   {
      a->inUse = 0;
   }
}


/* 21c44730 - todo */
void fapi_videc_clear_isr_data(FAPI_VIDEC_VideoDecoderIsrDataT* isrPtr)
{
    uint32_t idx = 0;

#ifdef FAPI_VIDEC_EXTENDED_INFO
    uint32_t i = 0;
#endif

    isrPtr->inUse = 0;
    isrPtr->isrMask = 0;
    isrPtr->isrStatus = 0;
    isrPtr->isrCurrField = 0;
#if 0
    isrPtr->isrCurrLinePosition = 0;
    isrPtr->currAudDetectTimeMsec = 0;
#endif
    isrPtr->currVcpbDecTimeMsec = 0;
#if 0
    isrPtr->currVdpbDecTimeMsec = 0;
    isrPtr->currHealthChkTimeMsec = 0;
    isrPtr->isrTslAudMsec = 0;
    isrPtr->isrTslVcpbMsec = 0;
    isrPtr->isrTslVdpbMsec = 0;
    isrPtr->isrTslHealthChkMsec = 0;
#endif
    isrPtr->virtualMemoryInfoPtr = 0;
    isrPtr->physicalMemoryInfoPtr = 0;
#if 0
    isrPtr->ppInfo.pesParserType = FAPI_VIDEC_UNKNOWN_PESPARSER;
    isrPtr->ppInfo.ptsLocation = 0;
    isrPtr->fmInfo.state = FAPI_VIDEC_UNKNOWN_VERSION_MATCH_STATE;
    isrPtr->fmInfo.versionInFlash = 0;
    isrPtr->fmInfo.versionSupported = 0;
    isrPtr->abrInfo.audCount = 0;
    isrPtr->abrInfo.audStateVar = 0;
    isrPtr->abrInfo.lastFoundPtr = 0;
    isrPtr->abrInfo.monitorStartTime = 0;
    isrPtr->abrInfo.totalCodedStreamSize = 0;
    isrPtr->abrInfo.bitrate = 0;
    isrPtr->cbrInfo.audCount = 0;
    isrPtr->cbrInfo.audStateVar = 0;
    isrPtr->cbrInfo.lastFoundPtr = 0;
    isrPtr->cbrInfo.monitorStartTime = 0;
    isrPtr->cbrInfo.totalCodedStreamSize = 0;
    isrPtr->cbrInfo.bitrate = 0;
#endif
    isrPtr->channelInfo.blockIndex = 0xFFFFFFFF;
    isrPtr->channelInfo.channelId = 0xFFFFFFFF;
#if 0
    isrPtr->afdInfo.state = FAPI_VIDEC_UNKNOWN_AFD_STATE;
    isrPtr->afdInfo.value = 0;
    isrPtr->delimiterInfo.type = FAPI_VIDEC_UNKNOWN_DELIMITER;
    isrPtr->delimiterInfo.state = FAPI_VIDEC_UNKNOWN_DELIMITER_STATE;
    isrPtr->bufferInfo.startAddress = 0;
#endif
    isrPtr->bufferInfo.size = 0;
    isrPtr->bufferInfo.criticalThreshold = 0;
    isrPtr->bufferInfo.optimalThreshold = 0;
    isrPtr->bufferInfo.fillLevel = 0;
    isrPtr->bufferInfo.availableSpace = 0;
#if 0
    isrPtr->daInfo.lastWptr = 0xFFFFFFFF;
    isrPtr->daInfo.currWptr = 0xFFFFFFFF;
    isrPtr->daInfo.eState = FAPI_VIDEC_UNKNOWN_DATA_AVAILABILE_STATE;
    isrPtr->daInfo.state = FAPI_VIDEC_UNKNOWN_DATA_AVAILABILE_STATE;
    isrPtr->playbackEnvironment = FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT;
    isrPtr->playbackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE;
    isrPtr->streamSegmentMode = FAPI_VIDEC_UNKNOWN_STREAM_SEGMENT_MODE;
#endif
    isrPtr->bootState = FAPI_VIDEC_NOT_BOOTED;
    isrPtr->resetState = FAPI_VIDEC_UNKNOWN_RESET_STATE;
    isrPtr->startStopState = FAPI_VIDEC_UNKNOWN_START_STOP_STATE;
#if 0
    isrPtr->skipRepeatState = FAPI_VIDEC_UNKNOWN_SKIP_REPEAT_STATE;
#endif
    isrPtr->healthState = FAPI_VIDEC_UNKNOWN_HEALTH;
#if 0
    isrPtr->syncState = FAPI_VIDEC_UNKNOWN_SYNC_STATE;
    isrPtr->vesInfo.vesProfile = FAPI_VIDEC_UNKNOWN_PROFILE;
    isrPtr->vesInfo.vesLevel = FAPI_VIDEC_UNKNOWN_LEVEL;
#endif
    isrPtr->vesInfo.vesAverageBitRate = 0;
    isrPtr->vesInfo.vesCurrBitRate = 0;
    isrPtr->vesInfo.vesAspectRatio = FAPI_VIDEC_AR_NONE;
    isrPtr->vesInfo.vesFrameRate = 0;
#if 0
    isrPtr->vesInfo.vesDecoderLatency = 2*FAPI_VIDEC_PTS_TICKS_PER_FRAME_25HZ;
#endif
    isrPtr->vesInfo.proggInter = 0xFFFFFFFF;
    isrPtr->vesInfo.displayWidth = 0;
    isrPtr->vesInfo.displayHeight = 0;
    isrPtr->vesInfo.decodedWidth = 0;
    isrPtr->vesInfo.decodedHeight = 0;
#if 0
    isrPtr->vesInfo.sarWidth = 1;
    isrPtr->vesInfo.sarHeight = 1;
#endif
    isrPtr->audLastPts = 0xFFFFFFFFFFFFFFFFULL;
    isrPtr->audIdx = 0;
    isrPtr->vcpbLoadIdx = 0;
    isrPtr->vcpbIdx = 0;
    isrPtr->oodSerialNum = 0;
    isrPtr->oodEntropyDecodedAudIdx = 0;
    isrPtr->oodIdx = 0;
    isrPtr->vdpbDecodedFramesAvailable = 0;
    isrPtr->vdpbSerialNum = 0;
#if 0
    isrPtr->vdpbVclDecodedAudIdx = 0;
#endif
    isrPtr->vdpbIdx = 0;
    isrPtr->lkgFrameCrop.aspectRatio = FAPI_VIDEC_AR_NONE;
#if 0
    isrPtr->lkgFrameCrop.singleField = FAPI_VIDEC_INVALID_FIELD;
#endif
    isrPtr->lkgFrameCrop.frameField = 0xFFFFFFFF;
    isrPtr->lkgFrameCrop.fieldInversion = 0;
#if 0
    isrPtr->lkgFrameCrop.quarterLineOffset = 0;
    isrPtr->lkgFrameCrop.oneLineOffset = 0;
#endif
    isrPtr->lkgFrameCrop.x0 = 0;
    isrPtr->lkgFrameCrop.y0 = 0;
    isrPtr->lkgFrameCrop.displayWidth = 0;
    isrPtr->lkgFrameCrop.displayHeight = 0;
    isrPtr->lkgFrameCrop.decodedWidth = 0;
    isrPtr->lkgFrameCrop.decodedHeight = 0;
    isrPtr->lkgFrameCrop.topFieldSerialNo = 0;
    isrPtr->lkgFrameCrop.botFieldSerialNo = 0;
    isrPtr->lkgFrameCrop.currAfd = 0;
    isrPtr->lkgFrameCrop.frameIdx = 0;
#if 0
    isrPtr->cucrInfo.vdpbContidionUpdateReq = 0;
    isrPtr->cucrInfo.oodSerialNumContidionUpdateReq = 0xFFFFFFFF;
    isrPtr->cucrInfo.decodedWidth = 0;
    isrPtr->cucrInfo.decodedHeight = 0;
    isrPtr->cucrInfo.lastDecodedWidth = 0;
    isrPtr->cucrInfo.lastDecodedHeight = 0;
    isrPtr->fbcrInfo.mode = FAPI_VIDEC_FBCR_MODE_UNDEFINED;
    isrPtr->fbcrInfo.state = FAPI_VIDEC_FRAME_BANK_SET;
    isrPtr->fbcrInfo.openParamsFbi.decoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
    isrPtr->fbcrInfo.openParamsFbi.decoderType = FAPI_VIDEC_UNKNOWN_DECODER;
    isrPtr->fbcrInfo.openParamsFbi.frameBankSizeType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
    isrPtr->fbcrInfo.openParamsFbi.coreSel = 0xFFFFFFFF;
    isrPtr->fbcrInfo.openParamsFbi.bankSize = 0;
    isrPtr->fbcrInfo.openParamsFbi.bankNum = 0;
    isrPtr->fbcrInfo.openParamsFbi.bankNumForBumping = 0;
    isrPtr->fbcrInfo.currFbi.decoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
    isrPtr->fbcrInfo.currFbi.decoderType = FAPI_VIDEC_UNKNOWN_DECODER;
    isrPtr->fbcrInfo.currFbi.frameBankSizeType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
    isrPtr->fbcrInfo.currFbi.coreSel = 0xFFFFFFFF;
    isrPtr->fbcrInfo.currFbi.bankSize = 0;
    isrPtr->fbcrInfo.currFbi.bankNum = 0;
    isrPtr->fbcrInfo.currFbi.bankNumForBumping = 0;
    isrPtr->fbcrInfo.targetFbi.decoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
    isrPtr->fbcrInfo.targetFbi.decoderType = FAPI_VIDEC_UNKNOWN_DECODER;
    isrPtr->fbcrInfo.targetFbi.frameBankSizeType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
    isrPtr->fbcrInfo.targetFbi.coreSel = 0xFFFFFFFF;
    isrPtr->fbcrInfo.targetFbi.bankSize = 0;
    isrPtr->fbcrInfo.targetFbi.bankNum = 0;
    isrPtr->fbcrInfo.targetFbi.bankNumForBumping = 0;
    isrPtr->edcrInfo.userEnableAfterNumFrames0 = 0xFFFFFFFF;
    isrPtr->edcrInfo.currEnableAfterNumFramesCntr0 = 0;
    isrPtr->edcrInfo.userEnableAfterNumFrames1 = 0;
    isrPtr->edcrInfo.currEnableAfterNumFramesCntr1 = 0;
    isrPtr->edcrInfo.currEnableAfterNumFramesStep = 1;
    isrPtr->edcrInfo.userEdChangeReqState = FAPI_VIDEC_ENABLE_DISABLE_STATE_SET;
    isrPtr->edcrInfo.cuEdChangeReqState = FAPI_VIDEC_ENABLE_DISABLE_STATE_SET;
    isrPtr->edcrInfo.userEnableDisableState = FAPI_VIDEC_ENABLE_FORCE_OFF;
    isrPtr->edcrInfo.cuEnableDisableState = FAPI_VIDEC_ENABLE_FORCE_OFF;
    isrPtr->edcrInfo.currEnableState = FAPI_VIDEC_UNKNOWN_ENABLE_DISABLE_STATE;
#endif
    isrPtr->pecrInfo.playbackEnvironmentChangeReqState = FAPI_VIDEC_DECODER_PLAYBACK_ENVIRONMENT_SET;
    isrPtr->pecrInfo.currPlaybackEnvironment = FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT;
    isrPtr->pecrInfo.targetPlaybackEnvironment = FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT;
    isrPtr->pmcrInfo.playbackModeChangeReqState = FAPI_VIDEC_DECODER_PLAYBACK_MODE_SET;
    isrPtr->pmcrInfo.currPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE;
    isrPtr->pmcrInfo.targetPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE;
#if 0
    isrPtr->sbInfo.ptsToStcState = FAPI_VIDEC_PTS_NOT_SET_TO_STC;
    isrPtr->sbInfo.base = FAPI_VIDEC_UNKNOWN_SYNC_BASE;
    isrPtr->sbInfo.pts = 0;
#endif
    isrPtr->pctInfo.paramChangeTrigger = 0;
    isrPtr->pctInfo.lastFrameInfo.aspectRatio = FAPI_VIDEC_AR_NONE;
    isrPtr->pctInfo.lastFrameInfo.frameField = 0xFFFFFFFF;
    isrPtr->pctInfo.lastFrameInfo.fieldInversion = 0;
    isrPtr->pctInfo.lastFrameInfo.decodedWidth = 0;
    isrPtr->pctInfo.lastFrameInfo.decodedHeight = 0;
    isrPtr->pctInfo.nextFrameInfo.aspectRatio = FAPI_VIDEC_AR_NONE;
    isrPtr->pctInfo.nextFrameInfo.frameField = 0xFFFFFFFF;
    isrPtr->pctInfo.nextFrameInfo.fieldInversion = 0;
    isrPtr->pctInfo.nextFrameInfo.decodedWidth = 0;
    isrPtr->pctInfo.nextFrameInfo.decodedHeight = 0;
#if 0
    isrPtr->odInfo.startTime = 0;
    isrPtr->odInfo.delayInMsec = 0;
    isrPtr->odInfo.delayInPtsTicks = 0;
    isrPtr->odInfo.startDisplayState = FAPI_VIDEC_STOP_DISPLAY;
    isrPtr->difInfo.mode = FAPI_VIDEC_NON_DIRECT_IFRAME_MODE;
    isrPtr->difInfo.state = FAPI_VIDEC_NON_DIRECT_IFRAME_STATE;
    isrPtr->frInfo.encValue = 0;
    isrPtr->frInfo.intpValue = 0;
    isrPtr->frInfo.state = FAPI_VIDEC_UNKNOWN_FRAMERATE;
    isrPtr->psInfo.wPtr = 0;
    isrPtr->psInfo.eState = FAPI_VIDEC_UNKNOWN_PTS_STABILITY_STATE;
    isrPtr->psInfo.state = FAPI_VIDEC_UNKNOWN_PTS_STABILITY_STATE;
    for(idx = 0; idx < PTS_STABILITY_FIFO_MAX_NUM; idx++){
        isrPtr->psInfo.pts[idx] = 0;
    }
    isrPtr->arInfo.state = FAPI_VIDEC_NO_RECOVER;
    isrPtr->arInfo.timeInterval = FAPI_VIDEC_BSR_AUTO_RECOVER_HEALTH_CHECK_TIMELIMIT;
    isrPtr->arInfo.userRequest = FAPI_VIDEC_AUTO_RECOVER_DISABLE;
    isrPtr->frcInfo.encFpsDivider = 1000;
    isrPtr->frcInfo.encFrps = 2500000;
    isrPtr->frcInfo.encFeps = 5000000;
    isrPtr->frcInfo.targetFpsDivider = 1000;
    isrPtr->frcInfo.targetFrps = 0;
    isrPtr->frcInfo.targetFeps = 0;
    isrPtr->frcInfo.frameCntMax = 6;
    isrPtr->frcInfo.frameCnt = 0;
    isrPtr->frcInfo.state = FAPI_VIDEC_UNKNOWN_FRC_STATE;
    isrPtr->displayInfo.mode = FAPI_VIDEC_UNKNOWN_DISPLAY_MODE;
    isrPtr->displayInfo.proggInter = 0xFFFFFFFF;
    isrPtr->frameLastStc = 0;
    isrPtr->frameLastPts = 0;
#endif
    isrPtr->frameFieldState = FAPI_VIDEC_NO_FIELD_FREEZE_STATE;
#if 0
    isrPtr->frameInitialStartState = FAPI_VIDEC_WAIT_FOR_INITIAL_START_STATE;
#endif
    isrPtr->frameState = FAPI_VIDEC_UNKNOWN_FRAME_STATE;
    isrPtr->frameBank = 0;
    isrPtr->frameCrop.aspectRatio = FAPI_VIDEC_AR_NONE;
    isrPtr->frameCrop.activeAspectRatioL0 = FAPI_VIDEC_AR_NONE;
    isrPtr->frameCrop.activeAspectRatioL1 = FAPI_VIDEC_AR_NONE;
#if 0
    isrPtr->frameCrop.sarWidth = 1;
    isrPtr->frameCrop.sarHeight = 1;
    isrPtr->frameCrop.singleField = FAPI_VIDEC_INVALID_FIELD;
#endif
    isrPtr->frameCrop.frameField = 0xFFFFFFFF;
    isrPtr->frameCrop.fieldInversion = 0;
#if 0
    isrPtr->frameCrop.quarterLineOffset = 0;
    isrPtr->frameCrop.oneLineOffset = 0;
#endif
    isrPtr->frameCrop.x0 = 0;
    isrPtr->frameCrop.y0 = 0;
    isrPtr->frameCrop.displayWidth = 0;
    isrPtr->frameCrop.displayHeight = 0;
    isrPtr->frameCrop.decodedWidth = 0;
    isrPtr->frameCrop.decodedHeight = 0;
    isrPtr->frameCrop.topFieldSerialNo = 0;
    isrPtr->frameCrop.botFieldSerialNo = 0;
    isrPtr->frameCrop.currAfd = 0;
    isrPtr->frameCrop.codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;
    isrPtr->frameCrop.readoutInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;
    isrPtr->frameCrop.frameIdx = 0;
    isrPtr->frameDisplayOrderInfo = FAPI_VIDEC_DOI_UNKNOWN;
    isrPtr->frameTopFieldNo = 0;
    isrPtr->frameBotFieldNo = 0;
    isrPtr->frameSerialNum = 0;
    isrPtr->frameIdx = 0;
    isrPtr->frameDecError = 0;
#if 0
    isrPtr->frameFreeIdx = 0;
    isrPtr->lastFrameBankFreeState = FAPI_VIDEC_REQUEST_TO_FREE_LAST_FRAME_BANK_IS_INVALID;
#endif
    isrPtr->invokeAutoScalers = 0;

    isrPtr->entropyDecInfoCbk = 0;
    isrPtr->entropyOptData = 0;
    isrPtr->entropyDecInfoData.serialNum = 0;
    isrPtr->entropyDecInfoData.afdUserDataActiveFormatFlag = 0;

#ifdef FAPI_VIDEC_EXTENDED_INFO
    isrPtr->entropyDecInfoData.ccUserDataProcessCcDataFlag = 0;
    isrPtr->entropyDecInfoData.barUserDataTopBarFlag = 0;
    isrPtr->entropyDecInfoData.barUserDataBotBarFlag = 0;
    isrPtr->entropyDecInfoData.barUserDataLeftBarFlag = 0;
    isrPtr->entropyDecInfoData.barUserDataRightBarFlag = 0;
    isrPtr->entropyDecInfoData.currAfd = 0XFFFFFFFF;
    isrPtr->entropyDecInfoData.barUserDataEndOfTopBar = 0XFFFFFFFF;
    isrPtr->entropyDecInfoData.barUserDataStartOfBotBar = 0XFFFFFFFF;
    isrPtr->entropyDecInfoData.barUserDataEndOfLeftBar = 0XFFFFFFFF;
    isrPtr->entropyDecInfoData.barUserDataStartOfRightBar = 0XFFFFFFFF;
    isrPtr->entropyDecInfoData.ccUserDataCcCount = 0;
    for(i = 0; i < 32; i++){
        isrPtr->entropyDecInfoData.ccUserDataCcValid[i] = 0XFFFFFFFF;
        isrPtr->entropyDecInfoData.ccUserDataCcType[i] = 0XFFFFFFFF;
        isrPtr->entropyDecInfoData.ccUserDataCcData1[i] = 0XFFFFFFFF;
        isrPtr->entropyDecInfoData.ccUserDataCcData2[i] = 0XFFFFFFFF;
    }
#endif

    isrPtr->entropyDecInfoData.MPEG2HorizontalSizeValue = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.MPEG2VerticalSizeValue = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.MPEG2AspectRatioInformation = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.MPEG2ProgressiveSequence = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.MPEG2DisplayHorizontalSize = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.MPEG2DisplayVerticalSize = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264PicStructurePresentFlag = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264PicStructure = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264PicWidthInMbsMinus1 = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264FrameHeightInMbs = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264FieldPicFlag = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264AspectRatioInfoPresentFlag = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264AspectRatioIdc = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264SarWidth = 0xFFFFFFFF;
    isrPtr->entropyDecInfoData.H264SarHeight = 0xFFFFFFFF;
    isrPtr->videoDecInfoCbk = 0;
    isrPtr->videoOptData = 0;
    isrPtr->videoDecInfoData.rPtr = 0;
    isrPtr->videoDecInfoData.serialNum = 0xFFFFFFFF;
    isrPtr->videoDecInfoData.frameBank = 0xFFFFFFFF;
    isrPtr->videoDecInfoData.displayWidth = 0;
    isrPtr->videoDecInfoData.displayHeight = 0;
    isrPtr->videoDecInfoData.decodedWidth = 0;
    isrPtr->videoDecInfoData.decodedHeight = 0;
    isrPtr->videoDecInfoData.displayOrderInfo = FAPI_VIDEC_DOI_UNKNOWN;
    isrPtr->videoDecInfoData.topFieldSerialNo = 0xFFFFFFFF;
    isrPtr->videoDecInfoData.botFieldSerialNo = 0xFFFFFFFF;
    isrPtr->videoDecInfoData.ptsValidFlag = 0;
    isrPtr->videoDecInfoData.dtsValidFlag = 0;
    isrPtr->videoDecInfoData.pts = 0;
    isrPtr->videoDecInfoData.dts = 0;
    isrPtr->hdAutoScaleCbk = 0;
    isrPtr->hdScalerHandle = 0;
    isrPtr->sdAutoScaleCbk = 0;
    isrPtr->sdScalerHandle = 0;
    isrPtr->frameDecodedCbk = 0;
    isrPtr->frameDecodedOptData = 0;
    isrPtr->frameAvailableCbk = 0;
    isrPtr->frameAvailableOptData = 0;
    isrPtr->vesOverflowCbk = 0;
    isrPtr->vesOverflowOptData = 0;
    isrPtr->paramChangeCbk = 0;
    isrPtr->paramChangeOptData = 0;

    isrPtr->audInfo.wPtr = 0;
    isrPtr->audInfo.rPtr = 0;
    isrPtr->audInfo.fPtr = 0;
    isrPtr->audInfo.fillLevel = 0;
    isrPtr->audInfo.fillLevelLimit = 1;
    isrPtr->audInfo.entryPointFound = 0;
    isrPtr->audInfo.seqStartFound = 0;
    isrPtr->audInfo.seqStartPtr = 0;
    for(idx = 0; idx < AUD_FIFO_MAX_NUM; idx++){
#if 0
        isrPtr->audInfo.codedPic[idx].time = 0;
        isrPtr->audInfo.codedPic[idx].headerHitPosition = 0xFFFFFFFF;
        isrPtr->audInfo.codedPic[idx].headerLength = 0;
        isrPtr->audInfo.codedPic[idx].picType = 0xFFFFFFFF;
        isrPtr->audInfo.codedPic[idx].serialNum = 0xFFFFFFFF;
        isrPtr->audInfo.codedPic[idx].decMode = 0xFFFFFFFF;
        isrPtr->audInfo.codedPic[idx].streamFlushMarker = 0;
        isrPtr->audInfo.codedPic[idx].pesHeaderAuFlag = 0;
#endif
        isrPtr->audInfo.codedPic[idx].codedPicPtr = 0;
        isrPtr->audInfo.codedPic[idx].codedPicSize = 0;
#if 0
        isrPtr->audInfo.codedPic[idx].ptsValidFlag = 0;
        isrPtr->audInfo.codedPic[idx].dtsValidFlag = 0;
#endif
        isrPtr->audInfo.codedPic[idx].pts = 0;
        isrPtr->audInfo.codedPic[idx].dts = 0;
        isrPtr->audInfo.codedPic[idx].state = FAPI_VIDEC_AUD_STATE_FREE;
    }

#if 0
    isrPtr->oodInfo.lastSearchStartIdx = 0xFFFFFFFF;
#endif
    isrPtr->oodInfo.wPtr = 0;
    isrPtr->oodInfo.rPtrMemory = 0;
#if 0
    isrPtr->oodInfo.auIdx = 0;
    isrPtr->oodInfo.auStructureInfo = 0;
    isrPtr->oodInfo.auFirstStructIdx = 0;
    isrPtr->oodInfo.auSecondStructIdx = 0;
#endif
    for(idx = 0; idx < OOD_FIFO_MAX_NUM; idx++)
    {
#if 0
        isrPtr->oodInfo.serialNum[idx] = 0xFFFFFFFF;
        isrPtr->oodInfo.decError[idx] = 0xFFFFFFFF;
#endif
        isrPtr->oodInfo.table[idx].decodedPicAspectRatio = FAPI_VIDEC_AR_NONE;
#if 0
        isrPtr->oodInfo.table[idx].sarWidth = 1;
        isrPtr->oodInfo.table[idx].sarHeight = 1;
#endif
        isrPtr->oodInfo.table[idx].decodedWidth = 0;
        isrPtr->oodInfo.table[idx].decodedHeight = 0;
        isrPtr->oodInfo.table[idx].codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;

#ifdef FAPI_VIDEC_EXTENDED_INFO
        isrPtr->oodInfo.table[idx].afdUserDataActiveFormatFlag = 0;
        isrPtr->oodInfo.table[idx].currAfd = 0;
        isrPtr->oodInfo.table[idx].ccUserDataProcessCcDataFlag = 0;
        isrPtr->oodInfo.table[idx].ccUserDataCcCount = 0;
        for(i = 0; i < 32; i++){
            isrPtr->oodInfo.table[idx].ccUserDataCcValid[i] = 0;
            isrPtr->oodInfo.table[idx].ccUserDataCcType[i] = 0;
            isrPtr->oodInfo.table[idx].ccUserDataCcData1[i] = 0;
            isrPtr->oodInfo.table[idx].ccUserDataCcData2[i] = 0;
        }
        isrPtr->oodInfo.table[idx].barUserDataTopBarFlag = 0;
        isrPtr->oodInfo.table[idx].barUserDataEndOfTopBar = 0;
        isrPtr->oodInfo.table[idx].barUserDataBotBarFlag = 0;
        isrPtr->oodInfo.table[idx].barUserDataStartOfBotBar = 0;
        isrPtr->oodInfo.table[idx].barUserDataLeftBarFlag = 0;
        isrPtr->oodInfo.table[idx].barUserDataEndOfLeftBar = 0;
        isrPtr->oodInfo.table[idx].barUserDataRightBarFlag = 0;
        isrPtr->oodInfo.table[idx].barUserDataStartOfRightBar = 0;
#endif
        isrPtr->oodInfo.table[idx].MPEG2HorizontalSizeValue = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].MPEG2VerticalSizeValue = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].MPEG2AspectRatioInformation = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].MPEG2FrameRateCode = 0xFFFFFFFF;
#if 0
        isrPtr->oodInfo.table[idx].MPEG2ProfileLevelIndication = 0xFFFFFFFF;
#endif
        isrPtr->oodInfo.table[idx].MPEG2ProgressiveSequence = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].MPEG2DisplayHorizontalSize = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].MPEG2DisplayVerticalSize = 0xFFFFFFFF;

#if 0
        isrPtr->oodInfo.table[idx].H264VdpbContidionUpdateReq = 0;
#endif
        isrPtr->oodInfo.table[idx].H264PicStructurePresentFlag = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264PicStructure = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264PicWidthInMbsMinus1 = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264FrameHeightInMbs = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264FrameMbsOnlyFlag = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264ProfileIdc = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264LevelIdc = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264FieldPicFlag = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264NumUnitsInTick = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264TimeScale = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264FixedFrameRateFlag = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264AspectRatioInfoPresentFlag = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264AspectRatioIdc = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264SarWidth = 0xFFFFFFFF;
        isrPtr->oodInfo.table[idx].H264SarHeight = 0xFFFFFFFF;
    }

    isrPtr->frameInfo.wPtr = 0;
    isrPtr->frameInfo.rPtr = 0;
    isrPtr->frameInfo.fillLevel = 0;
    isrPtr->frameInfo.fillLevelLimit = 1;
    for(idx = 0; idx < FRAME_FIFO_MAX_NUM; idx++){
        isrPtr->frameInfo.decodedPic[idx].serialNum         = 0xFFFFFFFF;
        isrPtr->frameInfo.decodedPic[idx].displayFrameBank  = 0xFFFFFFFF;
        isrPtr->frameInfo.decodedPic[idx].displayWidth      = 0;
        isrPtr->frameInfo.decodedPic[idx].displayHeight     = 0;
        isrPtr->frameInfo.decodedPic[idx].decodedWidth      = 0;
        isrPtr->frameInfo.decodedPic[idx].decodedHeight     = 0;
        isrPtr->frameInfo.decodedPic[idx].displayOrderInfo  = FAPI_VIDEC_DOI_UNKNOWN;
        isrPtr->frameInfo.decodedPic[idx].topFieldSerialNo  = 0xFFFFFFFF;
        isrPtr->frameInfo.decodedPic[idx].botFieldSerialNo  = 0xFFFFFFFF;
#if 0
        isrPtr->frameInfo.decodedPic[idx].quarterLineOffset = 0;
        isrPtr->frameInfo.decodedPic[idx].oneLineOffset     = 0;
#endif
        isrPtr->frameInfo.decodedPic[idx].ptsValidFlag      = 0;
        isrPtr->frameInfo.decodedPic[idx].dtsValidFlag      = 0;
        isrPtr->frameInfo.decodedPic[idx].pts               = 0;
        isrPtr->frameInfo.decodedPic[idx].dts               = 0;
        isrPtr->frameInfo.decodedPic[idx].state             = FAPI_VIDEC_UNKNOWN_FRAME_STATE;
        isrPtr->frameInfo.decodedPic[idx].topDecError       = 0xFFFFFFFF;
        isrPtr->frameInfo.decodedPic[idx].botDecError       = 0xFFFFFFFF;
        isrPtr->frameInfo.decodedPic[idx].vdpbDispCount     = 0;
        isrPtr->frameInfo.decodedPic[idx].decodedPicAspectRatio = FAPI_VIDEC_AR_NONE;
        isrPtr->frameInfo.decodedPic[idx].activePicAspectRatioL0 = FAPI_VIDEC_AR_NONE;
        isrPtr->frameInfo.decodedPic[idx].activePicAspectRatioL1 = FAPI_VIDEC_AR_NONE;
#if 0
        isrPtr->frameInfo.decodedPic[idx].sarWidth = 1;
        isrPtr->frameInfo.decodedPic[idx].sarHeight = 1;
#endif
        isrPtr->frameInfo.decodedPic[idx].currAfd = 0;
        isrPtr->frameInfo.decodedPic[idx].codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;
        isrPtr->frameInfo.decodedPic[idx].readoutInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP;

#ifdef FAPI_VIDEC_EXTENDED_INFO
        isrPtr->frameInfo.decodedPic[idx].barUserDataTopBarFlag = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataEndOfTopBar = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataBotBarFlag = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataStartOfBotBar = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataLeftBarFlag = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataEndOfLeftBar = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataRightBarFlag = 0;
        isrPtr->frameInfo.decodedPic[idx].barUserDataStartOfRightBar = 0;
#endif
#if 0
        isrPtr->frameInfo.decodedPic[idx].frameInfoAssocationState = FAPI_VIDEC_FRAME_INFO_ASSOCIATION_UNKNOWN_STATE;
#endif
    }
#ifdef FAPI_VIDEC_DEBUG
    isrPtr->trc.rPtr = 0;
    isrPtr->trc.wPtr = 0;
#endif
    isrPtr = 0;
}


/*  - todo */
static int32_t initMemorySegment(FAPI_VIDEC_VideoDecoderMemoryDataT* r4)
{
   int32_t res = 0;

#if 0
   printf("r4->piDone = %d\n", r4->piDone);
   printf("r4->piMemoryAllocationType = 0x%x\n", r4->piMemoryAllocationType);
   printf("Data_21efc808.Data_4 = 0x%x\n", Data_21efc808.Data_4);
   printf("Data_21efc808.Data_12 = 0x%x\n", Data_21efc808.Data_12);
#endif

   if (r4->piDone == 1)
   {
      //21c46890
      if (r4->piMemoryAllocationType == -1)
      {
         //21c46b88
         res = func_218ccd34(r4);
      }
      else if (r4->piMemoryAllocationType != -2)
      {
         //21c468a4
         if (Data_21efc808.Data_4 ==
               (r4->piMemoryAllocationType & Data_21efc808.Data_4))
         {
            //21c46a44
            r4->segmentHandle = 0;
            r4->segmentParams.sizeMBytes = 0;
            r4->segmentParams.memoryMode = 0;
            r4->segmentParams.functionMode = 0;
            r4->segmentParams.strategyMode = 0;
            r4->segmentParams.alignmentBits = 0;

            r4->physicalMemoryInfo.ramifsStartAddress = Data_21efc808.Data_4;
            r4->physicalMemoryInfo.axiWrapperStartAddress = r4->piMemoryAllocationType;
            r4->physicalMemoryInfo.axiSeqAreaStartAddress = r4->piMemoryAllocationType;
            r4->physicalMemoryInfo.axiSeqAreaSize = AxiSeqAreaSize; //0x480000;
            r4->physicalMemoryInfo.axiCcAreaStartAddress =
               r4->physicalMemoryInfo.axiSeqAreaStartAddress + r4->physicalMemoryInfo.axiSeqAreaSize; //AxiSeqAreaSize;
            r4->physicalMemoryInfo.axiCcAreaSize = AxiCcAreaSize; //0x80000
            r4->physicalMemoryInfo.axiMvAreaStartAddress =
               r4->physicalMemoryInfo.axiCcAreaStartAddress + r4->physicalMemoryInfo.axiCcAreaSize; //AxiCcAreaSize;
            r4->physicalMemoryInfo.axiMvAreaSize = AxiMvAreaSize; //0x2a8000
            r4->physicalMemoryInfo.axiDvAreaStartAddress =
               r4->physicalMemoryInfo.axiMvAreaStartAddress + r4->physicalMemoryInfo.axiMvAreaSize; //AxiMvAreaSize;
            r4->physicalMemoryInfo.axiDvAreaSize = AxiDvAreaSize; //0x100000
            r4->physicalMemoryInfo.videoStreamAreaStartAddress =
               r4->physicalMemoryInfo.axiDvAreaStartAddress + r4->physicalMemoryInfo.axiDvAreaSize; //AxiDvAreaSize;
            r4->physicalMemoryInfo.videoStreamAreaSize = VideoStreamAreaSize; //0x800000
            r4->physicalMemoryInfo.vcpbInfoTableStartAddress =
               r4->physicalMemoryInfo.videoStreamAreaStartAddress + r4->physicalMemoryInfo.videoStreamAreaSize; //VideoStreamAreaSize;
            r4->physicalMemoryInfo.vcpbInfoTableSize = VcpbInfoTableSize; //0x2400
            r4->physicalMemoryInfo.vdpbInfoTableStartAddress =
               r4->physicalMemoryInfo.vcpbInfoTableStartAddress + r4->physicalMemoryInfo.vcpbInfoTableSize; //VcpbInfoTableSize;
            r4->physicalMemoryInfo.vdpbInfoTableSize = VdpbInfoTableSize; //0x1200
            r4->physicalMemoryInfo.pcpuWorkAreaStartAddress =
               r4->physicalMemoryInfo.vdpbInfoTableStartAddress + r4->physicalMemoryInfo.vdpbInfoTableSize; //VdpbInfoTableSize;
            r4->physicalMemoryInfo.pcpuWorkAreaSize = PcpuWorkAreaSize; //0x14000
            r4->physicalMemoryInfo.decStartParamsStartAddress =
               r4->physicalMemoryInfo.pcpuWorkAreaStartAddress + r4->physicalMemoryInfo.pcpuWorkAreaSize; //PcpuWorkAreaSize;
            r4->physicalMemoryInfo.decStartParamsSize = DecStartParamsSize; //0x100

            r4->physicalMemoryInfo.oodInfoTableStartAddress =
               r4->physicalMemoryInfo.decStartParamsStartAddress + r4->physicalMemoryInfo.decStartParamsSize; //PcpuWorkAreaSize;
            r4->physicalMemoryInfo.oodInfoTableSize = OodInfoTableSize; //0x14000

            r4->physicalMemoryInfo.memoryInfoAvailable = 1;

            r4->virtualMemoryInfo.ramifsStartAddress = r4->physicalMemoryInfo.ramifsStartAddress;
            r4->virtualMemoryInfo.axiWrapperStartAddress = r4->physicalMemoryInfo.axiWrapperStartAddress;
            r4->virtualMemoryInfo.axiSeqAreaStartAddress = r4->physicalMemoryInfo.axiSeqAreaStartAddress;
            r4->virtualMemoryInfo.axiSeqAreaSize = r4->physicalMemoryInfo.axiSeqAreaSize; //AxiSeqAreaSize; //0x480000;
            r4->virtualMemoryInfo.axiCcAreaStartAddress = r4->physicalMemoryInfo.axiCcAreaStartAddress;
            r4->virtualMemoryInfo.axiCcAreaSize = r4->physicalMemoryInfo.axiCcAreaSize; //AxiCcAreaSize; //0x80000
            r4->virtualMemoryInfo.axiMvAreaStartAddress = r4->physicalMemoryInfo.axiMvAreaStartAddress;
            r4->virtualMemoryInfo.axiMvAreaSize = r4->physicalMemoryInfo.axiMvAreaSize; //AxiMvAreaSize; //0x2a8000
            r4->virtualMemoryInfo.axiDvAreaStartAddress = r4->physicalMemoryInfo.axiDvAreaStartAddress;
            r4->virtualMemoryInfo.axiDvAreaSize = r4->physicalMemoryInfo.axiDvAreaSize; //AxiDvAreaSize; //0x100000
            r4->virtualMemoryInfo.videoStreamAreaStartAddress = r4->physicalMemoryInfo.videoStreamAreaStartAddress;
            r4->virtualMemoryInfo.videoStreamAreaSize = r4->physicalMemoryInfo.videoStreamAreaSize; //VideoStreamAreaSize; //0x800000
            r4->virtualMemoryInfo.vcpbInfoTableStartAddress = r4->physicalMemoryInfo.vcpbInfoTableStartAddress;
            r4->virtualMemoryInfo.vcpbInfoTableSize = r4->physicalMemoryInfo.vcpbInfoTableSize; //VcpbInfoTableSize; //0x2400
            r4->virtualMemoryInfo.vdpbInfoTableStartAddress = r4->physicalMemoryInfo.vdpbInfoTableStartAddress;
            r4->virtualMemoryInfo.vdpbInfoTableSize = r4->physicalMemoryInfo.vdpbInfoTableSize; //VdpbInfoTableSize; //0x1200
            r4->virtualMemoryInfo.pcpuWorkAreaStartAddress = r4->physicalMemoryInfo.pcpuWorkAreaStartAddress;
            r4->virtualMemoryInfo.pcpuWorkAreaSize = r4->physicalMemoryInfo.pcpuWorkAreaSize; //PcpuWorkAreaSize; //0x14000
            r4->virtualMemoryInfo.decStartParamsStartAddress = r4->physicalMemoryInfo.decStartParamsStartAddress;
            r4->virtualMemoryInfo.decStartParamsSize = r4->physicalMemoryInfo.decStartParamsSize; //DecStartParamsSize; //0x100

            r4->virtualMemoryInfo.oodInfoTableStartAddress = r4->physicalMemoryInfo.oodInfoTableStartAddress;
            r4->virtualMemoryInfo.oodInfoTableSize = r4->physicalMemoryInfo.oodInfoTableSize; //OodInfoTableSize; //0x14000

            r4->virtualMemoryInfo.memoryInfoAvailable = 1;
         }
         else if (Data_21efc808.Data_12 ==
            (r4->piMemoryAllocationType & Data_21efc808.Data_12))
         {
            //21c468cc
            r4->segmentHandle = 0;
            r4->segmentParams.sizeMBytes = 0;
            r4->segmentParams.memoryMode = 0;
            r4->segmentParams.functionMode = 0;
            r4->segmentParams.strategyMode = 0;
            r4->segmentParams.alignmentBits = 0;

            r4->physicalMemoryInfo.ramifsStartAddress = Data_21efc808.Data_12;
            r4->physicalMemoryInfo.axiWrapperStartAddress = r4->piMemoryAllocationType;
            r4->physicalMemoryInfo.axiSeqAreaStartAddress = r4->piMemoryAllocationType;
            r4->physicalMemoryInfo.axiSeqAreaSize = AxiSeqAreaSize; //0x480000;
            r4->physicalMemoryInfo.axiCcAreaStartAddress =
               r4->physicalMemoryInfo.axiSeqAreaStartAddress + r4->physicalMemoryInfo.axiSeqAreaSize; //AxiSeqAreaSize;
            r4->physicalMemoryInfo.axiCcAreaSize = AxiCcAreaSize; //0x80000
            r4->physicalMemoryInfo.axiMvAreaStartAddress =
               r4->physicalMemoryInfo.axiCcAreaStartAddress + r4->physicalMemoryInfo.axiCcAreaSize; //AxiCcAreaSize;
            r4->physicalMemoryInfo.axiMvAreaSize = AxiMvAreaSize; //0x2a8000
            r4->physicalMemoryInfo.axiDvAreaStartAddress =
               r4->physicalMemoryInfo.axiMvAreaStartAddress + r4->physicalMemoryInfo.axiMvAreaSize; //AxiMvAreaSize;
            r4->physicalMemoryInfo.axiDvAreaSize = AxiDvAreaSize; //0x100000
            r4->physicalMemoryInfo.videoStreamAreaStartAddress =
               r4->physicalMemoryInfo.axiDvAreaStartAddress + r4->physicalMemoryInfo.axiDvAreaSize; //AxiDvAreaSize;
            r4->physicalMemoryInfo.videoStreamAreaSize = VideoStreamAreaSize; //0x800000
            r4->physicalMemoryInfo.vcpbInfoTableStartAddress =
               r4->physicalMemoryInfo.videoStreamAreaStartAddress + r4->physicalMemoryInfo.videoStreamAreaSize; //VideoStreamAreaSize;
            r4->physicalMemoryInfo.vcpbInfoTableSize = VcpbInfoTableSize; //0x2400
            r4->physicalMemoryInfo.vdpbInfoTableStartAddress =
               r4->physicalMemoryInfo.vcpbInfoTableStartAddress + r4->physicalMemoryInfo.vcpbInfoTableSize; //VcpbInfoTableSize;
            r4->physicalMemoryInfo.vdpbInfoTableSize = VdpbInfoTableSize; //0x1200
            r4->physicalMemoryInfo.pcpuWorkAreaStartAddress =
               r4->physicalMemoryInfo.vdpbInfoTableStartAddress + r4->physicalMemoryInfo.vdpbInfoTableSize; //VdpbInfoTableSize;
            r4->physicalMemoryInfo.pcpuWorkAreaSize = PcpuWorkAreaSize; //0x14000
            r4->physicalMemoryInfo.decStartParamsStartAddress =
               r4->physicalMemoryInfo.pcpuWorkAreaStartAddress + r4->physicalMemoryInfo.pcpuWorkAreaSize; //PcpuWorkAreaSize;
            r4->physicalMemoryInfo.decStartParamsSize = DecStartParamsSize; //0x100

            r4->physicalMemoryInfo.oodInfoTableStartAddress =
               r4->physicalMemoryInfo.decStartParamsStartAddress + r4->physicalMemoryInfo.decStartParamsSize; //PcpuWorkAreaSize;
            r4->physicalMemoryInfo.oodInfoTableSize = OodInfoTableSize; //0x14000

            r4->physicalMemoryInfo.memoryInfoAvailable = 1;

            r4->virtualMemoryInfo.ramifsStartAddress = r4->physicalMemoryInfo.ramifsStartAddress;
            r4->virtualMemoryInfo.axiWrapperStartAddress = r4->physicalMemoryInfo.axiWrapperStartAddress;
            r4->virtualMemoryInfo.axiSeqAreaStartAddress = r4->physicalMemoryInfo.axiSeqAreaStartAddress;
            r4->virtualMemoryInfo.axiSeqAreaSize = r4->physicalMemoryInfo.axiSeqAreaSize; //AxiSeqAreaSize; //0x480000;
            r4->virtualMemoryInfo.axiCcAreaStartAddress = r4->physicalMemoryInfo.axiCcAreaStartAddress;
            r4->virtualMemoryInfo.axiCcAreaSize = r4->physicalMemoryInfo.axiCcAreaSize; //AxiCcAreaSize; //0x80000
            r4->virtualMemoryInfo.axiMvAreaStartAddress = r4->physicalMemoryInfo.axiMvAreaStartAddress;
            r4->virtualMemoryInfo.axiMvAreaSize = r4->physicalMemoryInfo.axiMvAreaSize; //AxiMvAreaSize; //0x2a8000
            r4->virtualMemoryInfo.axiDvAreaStartAddress = r4->physicalMemoryInfo.axiDvAreaStartAddress;
            r4->virtualMemoryInfo.axiDvAreaSize = r4->physicalMemoryInfo.axiDvAreaSize; //AxiDvAreaSize; //0x100000
            r4->virtualMemoryInfo.videoStreamAreaStartAddress = r4->physicalMemoryInfo.videoStreamAreaStartAddress;
            r4->virtualMemoryInfo.videoStreamAreaSize = r4->physicalMemoryInfo.videoStreamAreaSize; //VideoStreamAreaSize; //0x800000
            r4->virtualMemoryInfo.vcpbInfoTableStartAddress = r4->physicalMemoryInfo.vcpbInfoTableStartAddress;
            r4->virtualMemoryInfo.vcpbInfoTableSize = r4->physicalMemoryInfo.vcpbInfoTableSize; //VcpbInfoTableSize; //0x2400
            r4->virtualMemoryInfo.vdpbInfoTableStartAddress = r4->physicalMemoryInfo.vdpbInfoTableStartAddress;
            r4->virtualMemoryInfo.vdpbInfoTableSize = r4->physicalMemoryInfo.vdpbInfoTableSize; //VdpbInfoTableSize; //0x1200
            r4->virtualMemoryInfo.pcpuWorkAreaStartAddress = r4->physicalMemoryInfo.pcpuWorkAreaStartAddress;
            r4->virtualMemoryInfo.pcpuWorkAreaSize = r4->physicalMemoryInfo.pcpuWorkAreaSize; //PcpuWorkAreaSize; //0x14000
            r4->virtualMemoryInfo.decStartParamsStartAddress = r4->physicalMemoryInfo.decStartParamsStartAddress;
            r4->virtualMemoryInfo.decStartParamsSize = r4->physicalMemoryInfo.decStartParamsSize; //DecStartParamsSize; //0x100
            
            r4->virtualMemoryInfo.oodInfoTableStartAddress = r4->physicalMemoryInfo.oodInfoTableStartAddress;
            r4->virtualMemoryInfo.oodInfoTableSize = r4->physicalMemoryInfo.oodInfoTableSize; //OodInfoTableSize; //0x14000

            r4->virtualMemoryInfo.memoryInfoAvailable = 1;
         }
         else
         {
            //21c468c4
            res = -28131;
            //->21c4685c
         }
      }
      //21c46a0c
   }
   else
   {
      //21c46854
      res = -28136;
      //->218cd488
   }

   if (res != 0)
   {
      //21c4685c
      r4->segmentHandle = 0;
      r4->segmentParams.sizeMBytes = 0;
      r4->segmentParams.memoryMode = 0;
      r4->segmentParams.functionMode = 0;
      r4->segmentParams.strategyMode = 0;
      r4->segmentParams.alignmentBits = 0;
   }
   //218cd4a0
   r4->virtualMemoryInfo.error = res;
   r4->physicalMemoryInfo.error = res;
   //218cd4a8
   return res;
}


/* 21c467ec - complete */
int32_t FAPI_VIDEC_Init(void)
{
   int32_t res = 0;
   unsigned i = 0;

   if (videcDriverIsInitialized != 0) return res;

   videcSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);

   if (videcSemaphore == 0)
   {
      return -28009;
   }
   
   for (i = 0; i < 1; i++)
   {
      res = initMemorySegment(&videcMemoryData[i]);
      if (res != 0)
      {
         videcDriverIsInitialized = 0;
      }
      else
      {
         fapi_videc_clear_handle(&videcHandles[i]);
         
         fapi_videc_clear_isr_data(&videcIsrData[i]);
         
         videcDriverIsInitialized = 1;
         videcDriverLoadFirmwaresState = 1;
      }
   } //for (i = 0; i < 1; i++)

   return res;
}


/* 21c4624c - todo */
void FAPI_VIDEC_Exit(void)
{

}

uint32_t fvm0d[0x1000/4]; //21fbda84
uint32_t fvm1d[0x1E000/4]; //21f80a84
uint32_t fvm2d[0x1000/4]; //21f7fa84

uint32_t fvh0d[0x1000/4]; //21fbca84
uint32_t fvh1d[0x1E000/4]; //21f9ea84
uint32_t fvh2d[0x1000/4]; //21f7ea84


static FAPI_VIDEC_MemoryInfoDataT* allocateVirtualMemoryInfo(int* errorCodePtr)
{
#if 0
   unsigned r2 = 0;
   int r3 = 0;
   FAPI_VIDEC_MemoryInfoDataT* r11 = 0;

   for (r2 = 0; r2 < 1; r2++)
   {
      //218ce404
      if ((videcMemoryData[r2].virtualMemoryInfo.inUse == 0) &&
         (videcMemoryData[r2].virtualMemoryInfo.memoryInfoAvailable == 1) &&
         (r3 == 0))
      {
         //218ce424
         videcMemoryData[r2].virtualMemoryInfo.inUse = 1;
         r11 = &videcMemoryData[r2].virtualMemoryInfo;
         //->218ce440
         break;
      }
      //218ce438
   } //for (r2 = 0; r2 < 1; r2++)
   //218ce440
   *errorCodePtr = r3;

   return r11;
#else
   uint32_t index = 0;
   int32_t err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE;
   FAPI_VIDEC_MemoryInfoDataT* memory_info_ptr = 0;

   for(index = 0; index < FAPI_VIDEC_MAX_NUM_DECODERS; index++){
       if((videcMemoryData[index].virtualMemoryInfo.inUse == 0) && (videcMemoryData[index].virtualMemoryInfo.memoryInfoAvailable == 1)){
           err_code = FAPI_OK;
           videcMemoryData[index].virtualMemoryInfo.inUse = 1;
           memory_info_ptr = &videcMemoryData[index].virtualMemoryInfo;
           break;
       }
       else{
           continue;
       }
   }
   if(errorCodePtr != 0){
       *errorCodePtr = err_code;
   }
   return(memory_info_ptr);
#endif
}


static FAPI_VIDEC_MemoryInfoDataT* allocatePhysicalMemoryInfo(int* errorCodePtr)
{
#if 0
   unsigned r2_ = 0;
   int r3_ = 0;
   FAPI_VIDEC_MemoryInfoDataT* r11_ = 0;

   for (r2_ = 0; r2_ < 1; r2_++)
   {
      //218ce460
      if ((videcMemoryData[r2_].physicalMemoryInfo.inUse == 0) &&
         (videcMemoryData[r2_].physicalMemoryInfo.memoryInfoAvailable == 1) &&
         (r3_ == 0))
      {
         //218ce480
         videcMemoryData[r2_].physicalMemoryInfo.inUse = 1;
         r11_ = &videcMemoryData[r2_].physicalMemoryInfo;
         //->218ce49c
         break;
      }
      //218ce494
   } //for (r2_ = 0; r2_ < 1; r2_++)
   //218ce49c
   *errorCodePtr = r3_;

   return r11_;
#else
   uint32_t index = 0;
   int32_t err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE;
   FAPI_VIDEC_MemoryInfoDataT* memory_info_ptr = 0;

   for(index = 0; index < FAPI_VIDEC_MAX_NUM_DECODERS; index++){
       if((videcMemoryData[index].physicalMemoryInfo.inUse == 0) && (videcMemoryData[index].physicalMemoryInfo.memoryInfoAvailable == 1)){
           err_code = FAPI_OK;
           videcMemoryData[index].physicalMemoryInfo.inUse = 1;
           memory_info_ptr = &videcMemoryData[index].physicalMemoryInfo;
           break;
       }
       else{
           continue;
       }
   }
   if(errorCodePtr != 0){
       *errorCodePtr = err_code;
   }
   return(memory_info_ptr);
#endif
}


static FAPI_VIDEC_VideoDecoderIsrDataT* allocateIsrStateMachine(int* errorCodePtr)
{
#if 0
   //218ce4a8
   unsigned r1_ = 0;
   int r2_ = 0;
   FAPI_VIDEC_VideoDecoderIsrDataT* r12 = 0;

   for (r1_ = 0; r1_ < 1; r1_++)
   {
      //218ce4b8
      if ((videcIsrData[r1_].inUse == 0) &&
            (r2_ == 0))
      {
         //218ce4d0
         videcIsrData[r1_].inUse = 1; //r7;
         r12 = &videcIsrData[r1_];
         //->218ce4ec
         break;
      }
      //218ce4e4
   } //for (r1_ = 0; r1_ < 1; r1_++)
   //218ce4ec
   *errorCodePtr = r2_;

   return r12;
#else
   uint32_t index = 0;
   int32_t err_code = FAPI_OK;
   FAPI_VIDEC_VideoDecoderIsrDataT* isr_ptr = 0;

   for(index = 0; index < FAPI_VIDEC_MAX_NUM_DECODERS; index++){
       if(videcIsrData[index].inUse == 0){
           if(err_code == FAPI_OK){
               videcIsrData[index].inUse = 1;
               isr_ptr = &videcIsrData[index];
               break;
           }
           else{
               continue;
           }
       }
   }
   if(errorCodePtr != 0){
       *errorCodePtr = err_code;
   }
   return(isr_ptr);
#endif
}

#if 0

static FAPI_VIDEC_VideoDecoderHandleT* videcAllocateHandle(const FAPI_VIDEC_OpenParamsT* paramsPtr)
{
   int r3 = 0;
   unsigned r1 = 0;
   FAPI_VIDEC_VideoDecoderHandleT* r6 = 0;

   switch (paramsPtr->decoderNumber)
   {
   case 0:
      if (videc0HandleAllocated != 0)
      {
         r3 = 1;
      }
      else
      {
         videc0HandleAllocated = 1;
      }
      break;

   default:
      r3 = 1;
      break;
   }

   if (r3 == 0)
   {
      for (r1 = 0; r1 < 1; r1++)
      {
         if (videcHandles[r1].inUse == 0)
         {
            //21c45914
            //r12 = videcMemoryData(21bf60f0)
            int r3 = 0;

            videcHandles[r1].virtualMemoryInfoPtr =
               allocateVirtualMemoryInfo(&r3);

            if (r3 != 0)
            {
               //->218ce538
               break;
            }
            //218ce454
            videcHandles[r1].physicalMemoryInfoPtr =
               allocatePhysicalMemoryInfo(&r3);

            if (r3 != 0)
            {
               //->218ce538
               break;
            }

            videcHandles[r1].isrDataPtr =
               allocateIsrStateMachine(&r3);

            if (r3 != 0)
            {
               //->218ce538
               break;
            }

            videcHandles[r1].isrDataPtr->virtualMemoryInfoPtr =
               videcHandles[r1].virtualMemoryInfoPtr;
            videcHandles[r1].isrDataPtr->physicalMemoryInfoPtr =
               videcHandles[r1].physicalMemoryInfoPtr;

            videcHandles[r1].inUse = 1;

            r6 = &videcHandles[r1];
            //->218ce538
            break;
         } //if (videcHandles[r1].inUse == 0)
         //218ce518
      } //for (r1 = 0; r1 < 1; r1++)
   }
   else
   {
      switch (paramsPtr->decoderNumber)
      {
      case 0:
         videc0HandleAllocated--;
         break;

      default:
         break;
      }
   }
   //21c45b74
   return r6;
}
#else

static FAPI_VIDEC_VideoDecoderHandleT* allocateHandle
                                      (const FAPI_VIDEC_OpenParamsT* paramsPtr,
                                       int32_t* errorCodePtr)
{
    uint32_t index = 0;
    int32_t err_code = FAPI_OK;
    FAPI_VIDEC_VideoDecoderHandleT* handle_ptr = 0;

    switch(paramsPtr->decoderNumber){
        case FAPI_VIDEC_DECODER_NUMBER_0:
            if(videc0HandleAllocated >= FAPI_VIDEC_MAX_NUM_HANDLES_VIDEC_0){
                err_code = FAPI_VIDEC_ERR_EXCEEDED_MAX_HANDLES;
            }
            else{
                videc0HandleAllocated++;
                err_code = FAPI_OK;
            }
            break;
        case FAPI_VIDEC_UNKNOWN_DECODER_NUMBER:
        default:
                err_code = FAPI_VIDEC_ERR_INVALID_OPEN_PARAMS;
            break;
    };
    if(err_code == FAPI_OK){
        for(index = 0; index < FAPI_VIDEC_MAX_NUM_DECODERS; index++){
            if(videcHandles[index].inUse == 0){
                videcHandles[index].virtualMemoryInfoPtr = allocateVirtualMemoryInfo(&err_code);
                if(err_code != FAPI_OK){
                    err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE;
                    break;
                }
                videcHandles[index].physicalMemoryInfoPtr = allocatePhysicalMemoryInfo(&err_code);
                if(err_code != FAPI_OK){
                    err_code = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE;
                    break;
                }
                videcHandles[index].isrDataPtr = allocateIsrStateMachine(&err_code);
                if(err_code != FAPI_OK){
                    err_code = FAPI_VIDEC_ERR_ISR_STATE_MACHINE_ALLOCATION_FAILURE;
                    break;
                }
#if 0
                videcHandles[index].bsrDecodeDataPtr = allocateBsrDecodeStateMachine(&err_code);
                if(err_code != FAPI_OK){
                    err_code = FAPI_VIDEC_ERR_BSR_STATE_MACHINE_ALLOCATION_FAILURE;
                    break;
                }
                videcHandles[index].bsrDisplayDataPtr = allocateBsrDisplayStateMachine(&err_code);
                if(err_code != FAPI_OK){
                    err_code = FAPI_VIDEC_ERR_BSR_STATE_MACHINE_ALLOCATION_FAILURE;
                    break;
                }
#endif
                else{
                    videcHandles[index].isrDataPtr->virtualMemoryInfoPtr = videcHandles[index].virtualMemoryInfoPtr;
                    videcHandles[index].isrDataPtr->physicalMemoryInfoPtr = videcHandles[index].physicalMemoryInfoPtr;
                    videcHandles[index].inUse = 1;
                    handle_ptr = &videcHandles[index];
                    break;
                }
            }
        }
    }
    else{
        handle_ptr = 0;
        switch(paramsPtr->decoderNumber){
            case FAPI_VIDEC_DECODER_NUMBER_0:
                     videc0HandleAllocated--;
                 break;
            case FAPI_VIDEC_UNKNOWN_DECODER_NUMBER:
            default:
                 break;
        };
    }
    if(errorCodePtr != 0){
        *errorCodePtr = err_code;
    }
    return(handle_ptr);
}

#endif


/* 2192d30c - todo */
void func_2192d30c(void)
{
   FAPI_SYS_PRINT_MSG("func_2192d30c\n");
}


/* 2192dc20 - todo */
void func_2192dc20(void)
{
   FAPI_SYS_PRINT_MSG("func_2192dc20\n");
}


/* 2192dcc4 - todo */
void func_2192dcc4(void)
{
   FAPI_SYS_PRINT_MSG("func_2192dcc4\n");
}




/* 21c45794 - complete */
/* Evolve: 218cf8c4 */
void fapi_videc_release_handle(FAPI_VIDEC_VideoDecoderHandleT* a)
{
//   FAPI_SYS_PRINT_MSG("fapi_videc_release_handle\n");
   
   if (a->opParams.decoderNumber == FAPI_VIDEC_DECODER_NUMBER_0)
   {
      videc0HandleAllocated--;
   }
   
   fapi_videc_release_memory_info_data(a->virtualMemoryInfoPtr);

   fapi_videc_release_memory_info_data(a->physicalMemoryInfoPtr);

   if (a->isrDataPtr != 0)
   {
      fapi_videc_clear_isr_data(a->isrDataPtr);
   }

   fapi_videc_clear_handle(a);
}


/* 21c4bedc - complete */
int32_t fapi_videc_set_ramif(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   unsigned i = 0;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_set_ramif, a->vBankType=%d\n",
         a->vBankType);

   switch (a->vBankType)
   {
   case FAPI_VIDEC_FRAME_BANK_SIZE_1920HD:
      if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_4) == Data_21efc808.Data_4)
      {
         a->bankNum = 16;
      }
      else if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_12) == Data_21efc808.Data_12)
      {
         a->bankNum = 8;         
      }
      else
      {
         a->bankNum = 0;         
      }

      a->bankSize = 832;
      
      FREG_DDRRAMIF_SetRamifVYb_Offset(0x110);
      FREG_DDRRAMIF_SetRamifVCt_Offset(0x230);
      FREG_DDRRAMIF_SetRamifVCb_Offset(0x2b0);
      
      for (i = 0; i < 22; i++)
      {
         FREG_DDRRAMIF_SetRamifVBankn_Adr(i, 
               Data_21e01a08[i]);
      }
      break;
      
   case FAPI_VIDEC_FRAME_BANK_SIZE_1440HD:
      if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_4) == Data_21efc808.Data_4)
      {
         a->bankNum = 22;
      }
      else if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_12) == Data_21efc808.Data_12)
      {
         a->bankNum = 10;         
      }
      else
      {
         a->bankNum = 0;         
      }

      a->bankSize = 624;
      
      FREG_DDRRAMIF_SetRamifVYb_Offset(0xcc);
      FREG_DDRRAMIF_SetRamifVCt_Offset(0x1a4);
      FREG_DDRRAMIF_SetRamifVCb_Offset(0x204);
      
      for (i = 0; i < 22; i++)
      {
         FREG_DDRRAMIF_SetRamifVBankn_Adr(i, 
               Data_21e01a60[i]);
      }
      break;
      
   case FAPI_VIDEC_FRAME_BANK_SIZE_1280HD:
      if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_4) == Data_21efc808.Data_4)
      {
         a->bankNum = 22;
      }
      else if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_12) == Data_21efc808.Data_12)
      {
         a->bankNum = 13;         
      }
      else
      {
         a->bankNum = 0;         
      }
      
      a->bankSize = 360;
      
      FREG_DDRRAMIF_SetRamifVYb_Offset(0x6e);
      FREG_DDRRAMIF_SetRamifVCt_Offset(0xe6);
      FREG_DDRRAMIF_SetRamifVCb_Offset(0x122);
      
      for (i = 0; i < 22; i++)
      {
         FREG_DDRRAMIF_SetRamifVBankn_Adr(i, 
               Data_21e01ab8[i]);
      }
      break;
      
   case FAPI_VIDEC_FRAME_BANK_SIZE_SD:
      if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_4) == Data_21efc808.Data_4)
      {
         a->bankNum = 22;
      }
      else if ((a->physicalMemoryInfoPtr->ramifsStartAddress & Data_21efc808.Data_12) == Data_21efc808.Data_12)
      {
         a->bankNum = 22;
      }
      else
      {
         a->bankNum = 0;         
      }

      a->bankSize = 168;
      
      FREG_DDRRAMIF_SetRamifVYb_Offset(0x36);
      FREG_DDRRAMIF_SetRamifVCt_Offset(0x72);
      FREG_DDRRAMIF_SetRamifVCb_Offset(0x8a);
      
      for (i = 0; i < 22; i++)
      {
         FREG_DDRRAMIF_SetRamifVBankn_Adr(i, 
               Data_21e01b10[i]);
      }
      break;
      
   default:
      a->bankNum = 0;         
      a->bankSize = 0;
      
      FREG_DDRRAMIF_SetRamifVYb_Offset(0);
      FREG_DDRRAMIF_SetRamifVCt_Offset(0);
      FREG_DDRRAMIF_SetRamifVCb_Offset(0);

      for (i = 0; i < 22; i++)
      {
         FREG_DDRRAMIF_SetRamifVBankn_Adr(i, 0);
      }

      break;
   }

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_set_ramif, a->bankNum=%d, a->bankSize=%d\n",
         a->bankNum, a->bankSize);

   FREG_DDRRAMIF_SetRamifVSize_Size(a->vBankType);
   FREG_DDRRAMIF_SetRamifVClk_Pi4(1);
   FREG_DDRRAMIF_SetRamifVClk_Pi3(1);
   FREG_DDRRAMIF_SetRamifVClk_Pi2(1);
   FREG_DDRRAMIF_SetRamifVClk_Pi1(1);
   FREG_DDRRAMIF_SetRamifVClk_Sd(1);
   FREG_DDRRAMIF_SetRamifVCoresel_Sel(a->coreSel);
   FREG_DDRRAMIF_SetRamifVEnable_Mcif(1);
   FREG_DDRRAMIF_SetRamifVEnable_Ref(1);
   
   return 0;
}


/* 21c4a194 - complete */
int fapi_videc_wait_boot(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   uint64_t t;
   uint64_t t1 = FAPI_TIMER_GetTimeStamp(1000);

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_wait_boot: t1=%d\n",
         t1);

   while (1)
   {
      t = FAPI_TIMER_GetTimeStamp(1000);

      t -= t1;

      if (a->isrDataPtr->bootState == FAPI_VIDEC_BOOTED)
      {
         break;
      }

      if (t > FAPI_VIDEC_ISR_BOOT_TIMEOUT) //5000)
      {
         return FAPI_VIDEC_ERR_BOOT_TIMEOUT;
      }

      FAPI_SYS_SLEEP(50);
   }

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_wait_boot: t=%d\n",
         t);

   return 0;
}


/* 21c48a60 - nearly complete */
int32_t fapi_videc_check_firmware_version(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   int32_t res = 0;
   unsigned mpeg2Version = Data_21efc820.mpeg2Version;
   unsigned h264Version = Data_21efc820.h264Version;
   
   a->firmwareVersionInFlash = FREG_VD_Read32(0x60048700);
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_check_firmware_version, a->firmwareVersionInFlash=0x%x, mpeg2Version=0x%x, h264Version=0x%x\n",
         a->firmwareVersionInFlash,
         mpeg2Version, h264Version);

   if ((a->firmwareVersionInFlash & 0xf000000) == 0) //H264
   {
      a->firmwareVersionSupported = (h264Version << 16) >> 16;
      
      if (a->firmwareVersionSupported == (a->firmwareVersionInFlash & ~0xf0ff0000))
      {
         a->firmwareVersionMatch = FAPI_VIDEC_VERSION_MATCH_SUCCESS;
      }
      else
      {
         a->firmwareVersionMatch = FAPI_VIDEC_VERSION_MATCH_FAILURE;
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_VERSION_MISMATCH;
      }
   }
   else if ((a->firmwareVersionInFlash & 0xf000000) == 0x1000000) //MPEG2
   {
      a->firmwareVersionSupported = ((mpeg2Version << 16) >> 16) | 0x1000000;

      if (a->firmwareVersionSupported == (a->firmwareVersionInFlash & ~0xf0ff0000))
      {
         a->firmwareVersionMatch = FAPI_VIDEC_VERSION_MATCH_SUCCESS;
      }
      else
      {
         a->firmwareVersionMatch = FAPI_VIDEC_VERSION_MATCH_FAILURE;
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_VERSION_MISMATCH;
      }
   }
   else
   {
      a->firmwareVersionMatch = FAPI_VIDEC_VERSION_MATCH_FAILURE;
      res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_VERSION_MISMATCH;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_check_firmware_version, res=%d\n",
         res);

   return res;
}


static int32_t fapi_videc_initialize_isr(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   int32_t res = 0;

   a->vBankType = a->opParams.decodeFrameBankSizeType;

   if (a->opParams.decoderType == FAPI_VIDEC_H264_HP41)
   {
      a->coreSel = 0;
   }
   else if (a->opParams.decoderType == FAPI_VIDEC_MPEG2_MPHL)
   {
      a->coreSel = 1;
   }
   //21c4ce2c
   a->isrDataPtr->isrMask = 0;
   a->isrDataPtr->isrStatus = 0;
   a->isrDataPtr->isrSerialIdx = 0;
   a->isrDataPtr->isrCurrField = 0;
   a->isrDataPtr->isrNextField = 1;

   a->isrDataPtr->decoderNumber = a->opParams.decoderNumber;
   a->isrDataPtr->decoderType = a->opParams.decoderType;
   a->isrDataPtr->decodeFrameBankSizeType = a->opParams.decodeFrameBankSizeType;
   a->isrDataPtr->decoderAfdState = a->opParams.decoderAfdState;
   a->isrDataPtr->Data_120 = a->opParams.decoderDelimiterType;
   a->isrDataPtr->Data_128 = a->physicalMemoryInfoPtr->videoStreamAreaStartAddress;
   a->isrDataPtr->bufferInfo.size = a->decoderBufferSize;
   a->isrDataPtr->bufferInfo.criticalThreshold =
      a->decoderBufferSize / 4 * 3;
   a->isrDataPtr->bufferInfo.optimalThreshold =
      a->decoderBufferSize / 2;
   a->isrDataPtr->bufferInfo.fillLevel = 0;
   a->isrDataPtr->bufferInfo.availableSpace =
      a->decoderBufferSize / 2;

   a->isrDataPtr->decoderPlaybackMode = a->opParams.decoderPlaybackMode;
   a->isrDataPtr->decoderDisplayMode = a->decoderDisplayMode;
   a->isrDataPtr->bootState = FAPI_VIDEC_NOT_BOOTED; //-1;
   a->isrDataPtr->resetState = FAPI_VIDEC_NOT_RESET; //0
   a->isrDataPtr->startStopState = FAPI_VIDEC_STOPPED; //2;
   a->isrDataPtr->enableDisableState = FAPI_VIDEC_UNKNOWN_ENABLE_DISABLE_STATE; //-1;
   a->isrDataPtr->Data_180 = -1;
   a->isrDataPtr->healthState = FAPI_VIDEC_GOOD_HEALTH; //0;
   a->isrDataPtr->mpegIFrameState = FAPI_VIDEC_NON_MPEG_IFRAME_STATE; //0;
   a->isrDataPtr->Data_192 = -1;
   a->isrDataPtr->Data_196 = 0;
   a->isrDataPtr->Data_200 = Enum_200_a;
   a->isrDataPtr->Data_204 = 0;
   a->isrDataPtr->vesInfo.vesAverageBitRate = 0; //Data_208 = 0;
   a->isrDataPtr->vesInfo.vesCurrBitRate = 0; //Data_212 = 0;
   a->isrDataPtr->vesInfo.vesAspectRatio = 0; //Data_216 = 0;
   a->isrDataPtr->vesInfo.vesFrameRate = 0; //Data_220 = 0;
   a->isrDataPtr->vesInfo.proggInter = -1; //Data_232 = -1;
   a->isrDataPtr->vesInfo.displayWidth = 0; //Data_236 = 0;
   a->isrDataPtr->vesInfo.displayHeight = 0; //Data_240 = 0;
   a->isrDataPtr->vesInfo.decodedWidth = 0; //Data_244 = 0;
   a->isrDataPtr->vesInfo.decodedHeight = 0; //Data_248 = 0;

   a->isrDataPtr->currIsrTimeUsec = 0;
   a->isrDataPtr->Data_12 = 0;
   a->isrDataPtr->currVcpbDecTimeMsec = 0;
   a->isrDataPtr->Data_28 = 0;
   
   a->isrDataPtr->Data_36 = 0;
   a->isrDataPtr->Data_44 = 0;
   a->isrDataPtr->Data_52 = 0;
   a->isrDataPtr->Data_60 = 0;

   a->isrDataPtr->audLastPts = 0; //Data_49480 = 0;
   a->isrDataPtr->audIdx = 0; //Data_49488 = 0;
   
   a->isrDataPtr->vcpbAddress = 0; //Data_49492 = 0;
   a->isrDataPtr->vcpbLength = 0; //Data_49496 = 0;
   a->isrDataPtr->vcpbLoadIdx = 0; //Data_49500 = 0;
   a->isrDataPtr->vcpbIdx = 0; //Data_49504 = 0;

   a->isrDataPtr->oodSerialNum = 0;
   a->isrDataPtr->oodEntropyDecodedAudIdx = 0;
   a->isrDataPtr->oodIdx = 0;

   a->isrDataPtr->vdpbDecodedFramesAvailable = 0; //Data_705096 = 0;
   a->isrDataPtr->vdpbSerialNum = 0; //Data_705100 = 0;
   a->isrDataPtr->Data_705104 = 0;
   a->isrDataPtr->vdpbIdx = 0; //Data_705108 = 0;
   
   a->isrDataPtr->lkgFrameCrop.aspectRatio = 0; //705112
   a->isrDataPtr->lkgFrameCrop.frameField = -1;
   a->isrDataPtr->lkgFrameCrop.fieldInversion = 0; //705128
   a->isrDataPtr->lkgFrameCrop.x0 = 0;
   a->isrDataPtr->lkgFrameCrop.y0 = 0;
   a->isrDataPtr->lkgFrameCrop.displayWidth = 0;
   a->isrDataPtr->lkgFrameCrop.displayHeight = 0;
   a->isrDataPtr->lkgFrameCrop.decodedWidth = 0; //705148
   a->isrDataPtr->lkgFrameCrop.decodedHeight = 0; //705152
   a->isrDataPtr->lkgFrameCrop.topFieldSerialNo = 0; //705156
   a->isrDataPtr->lkgFrameCrop.botFieldSerialNo = 0; //705160
   a->isrDataPtr->lkgFrameCrop.currAfd = 0; //705164
   a->isrDataPtr->lkgFrameCrop.mpegIFrameState = 0; //705176
   a->isrDataPtr->lkgFrameCrop.frameIdx = 0; //705180
   
   a->isrDataPtr->pecrInfo.playbackEnvironmentChangeReqState = FAPI_VIDEC_DECODER_PLAYBACK_ENVIRONMENT_SET; //Data_705184 = 0;
   a->isrDataPtr->pecrInfo.currPlaybackEnvironment = FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT; //Data_705188 = 0;
   a->isrDataPtr->pecrInfo.targetPlaybackEnvironment = FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT; //0;
   
   a->isrDataPtr->pmcrInfo.playbackModeChangeReqState = FAPI_VIDEC_DECODER_PLAYBACK_MODE_SET; //Data_705196 = 0;
   a->isrDataPtr->pmcrInfo.currPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE; //Data_705200 = -1;
   a->isrDataPtr->pmcrInfo.targetPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE; //Data_705204 = -1;

   a->isrDataPtr->pctInfo.paramChangeTrigger = 0; //705224

   a->isrDataPtr->pctInfo.nextFrameInfo.aspectRatio = 0; //705228
   a->isrDataPtr->pctInfo.nextFrameInfo.frameField = -1; //705232
   a->isrDataPtr->pctInfo.nextFrameInfo.fieldInversion = 0; //705236
   a->isrDataPtr->pctInfo.nextFrameInfo.decodedWidth = 0; //705240
   a->isrDataPtr->pctInfo.nextFrameInfo.decodedHeight = 0; //705244

   a->isrDataPtr->pctInfo.lastFrameInfo.aspectRatio = 0; //705248
   a->isrDataPtr->pctInfo.lastFrameInfo.frameField = -1; //705252
   a->isrDataPtr->pctInfo.lastFrameInfo.fieldInversion = 0; //705256
   a->isrDataPtr->pctInfo.lastFrameInfo.decodedWidth = 0; //705260
   a->isrDataPtr->pctInfo.lastFrameInfo.decodedHeight = 0; //705264

//   a->isrDataPtr->Data_705268 = 0;
//   a->isrDataPtr->Data_705276 = 0;

   a->isrDataPtr->frameFieldState = FAPI_VIDEC_NO_FIELD_FREEZE_STATE;
   a->isrDataPtr->frameStartDisplay = 0;
   a->isrDataPtr->frameState = FAPI_VIDEC_UNKNOWN_FRAME_STATE;
   a->isrDataPtr->frameBank = 0;

   a->isrDataPtr->frameCrop.aspectRatio = 0; //705308
   a->isrDataPtr->frameCrop.frameField = -1; //705320
   a->isrDataPtr->frameCrop.fieldInversion = 0; //705324
   a->isrDataPtr->frameCrop.x0 = 0; //705328
   a->isrDataPtr->frameCrop.y0 = 0; //705332
   a->isrDataPtr->frameCrop.displayWidth = 0; //705336
   a->isrDataPtr->frameCrop.displayHeight = 0; //705340
   a->isrDataPtr->frameCrop.decodedWidth = 0; //705344
   a->isrDataPtr->frameCrop.decodedHeight = 0; //705348
   a->isrDataPtr->frameCrop.topFieldSerialNo = 0; //705352
   a->isrDataPtr->frameCrop.botFieldSerialNo = 0; //705356
   a->isrDataPtr->frameCrop.currAfd = 0; //705360
   a->isrDataPtr->frameCrop.codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP; //705364
   a->isrDataPtr->frameCrop.readoutInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP; //705368
   a->isrDataPtr->frameCrop.mpegIFrameState = 0; //705372
   a->isrDataPtr->frameCrop.frameIdx = 0; //705376

   a->isrDataPtr->frameDisplayOrderInfo = 0; //705380
   a->isrDataPtr->frameTopFieldNo = 0; //705384
   a->isrDataPtr->frameBotFieldNo = 0; //705388
   a->isrDataPtr->frameSerialNum = 0; //705392
   a->isrDataPtr->frameIdx = 0; //705396
   a->isrDataPtr->frameDecError = 0; //705400
   a->isrDataPtr->Data_705404 = 0;
   
   a->isrDataPtr->invokeAutoScalers = 0; //705408

   a->isrDataPtr->Data_705268 = 0;
   a->isrDataPtr->Data_705276 = 0;

   fapi_videc_clear_aud_info_data(a->isrDataPtr);
   fapi_videc_clear_entropy_decoding_data(a->isrDataPtr);
   fapi_videc_clear_video_decoding_data(a->isrDataPtr);

   return res;
}


/* 21c4cdd4 - todo */
int32_t fapi_videc_0initialize(FAPI_VIDEC_VideoDecoderHandleT* a)
{
//   FAPI_SYS_PRINT_MSG("fapi_videc_0initialize\n");
   
   int32_t res = 0;
   
   if ((a->isrDataPtr == 0) ||
         (a->isrDataPtr->inUse != 1))
   {
      res = FAPI_VIDEC_ERR_ISR_ASSOCIATION_FAILURE;
      Data_21f67278 = 0;
   }
   else
   do
   {
      Data_21f67278 = a;
   
      fapi_videc_initialize_isr(a);

      fapi_videc_set_ramif(a);

      fapi_videc_set_start_addresses(a);

      res = fapi_videc_boot_pcpu(a);
      if (res != 0)
      {
         break;
      }

      res = fapi_videc_wait_boot(a);
      if (res != 0)
      {
         break;
      }

      res = fapi_videc_check_firmware_version(a);
   }
   while (0);

   return res;
}


/* 21c4584c - todo */
FAPI_SYS_HandleT FAPI_VIDEC_Open(const FAPI_VIDEC_OpenParamsT* paramsPtr,
                          int32_t* errorCodePtr)
{
//   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_Open\n");
      
   FAPI_VIDEC_VideoDecoderHandleT* r6;
   int32_t res = 0;
   FAPI_SYS_HandleT sp0x20 = 0;
   
   if (videcDriverIsInitialized == 0)
   {
      //21c45ae8
      res = -28004;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }

   if (videcDriverLoadFirmwaresState == 0)
   {
      //21c45ae8
      res = -28004;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      return 0;
   }
   else
   if (videcDriverLoadFirmwaresState == 1)
   {
      //->21c45afc
#if 0
      FAPI_SYS_HandleT r6;
      int32_t sp0x1c = 0;
      FAPI_BOOT_OpenParamsT sp0x18;
      
      sp0x18.version = FAPI_BOOT_VERSION;
      
      r6 = FAPI_BOOT_Open(&sp0x18, &sp0x1c);
      
      if (sp0x1c == 0)
      do
      {
         //21c45bac
         FAPI_BOOT_ImageHeaderT sp4;

         memset(&sp4, 0, sizeof(sp4));
         uint32_t imageVersion = RELEASE_VIDEC_MPEG_0_VERSION; //0x4d30001b;
         
         sp0x1c = FAPI_BOOT_GetImageInfoByVersion(r6, 
               imageVersion, &sp4);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45be0
         sp0x1c = FAPI_BOOT_LoadImageByVersion(r6, 
               imageVersion, (uint32_t) &fvm0d);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45c00
         fvm0sz = sp4.imageSize * 4;
         fvm0la = sp4.loadAddress;
         
         memset(&sp4, 0, sizeof(sp4));
         imageVersion = RELEASE_VIDEC_MPEG_1_VERSION; //0x4d31001b;
                  
         sp0x1c = FAPI_BOOT_GetImageInfoByVersion(r6, 
               imageVersion, &sp4);
         //21c45c4c
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c46068
         sp0x1c = FAPI_BOOT_LoadImageByVersion(r6, 
               imageVersion, (uint32_t) &fvm1d);
         
         if (sp0x1c != 0)
         {
            //->21c45c4c
            break;            
         }
         //21c46088
         fvm1sz = sp4.imageSize * 4;
         fvm1la = sp4.loadAddress;
         
         memset(&sp4, 0, sizeof(sp4));
         imageVersion = RELEASE_VIDEC_MPEG_2_VERSION; //0x4d32001b;
                  
         sp0x1c = FAPI_BOOT_GetImageInfoByVersion(r6, 
               imageVersion, &sp4);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c460d8
         sp0x1c = FAPI_BOOT_LoadImageByVersion(r6, 
               imageVersion, (uint32_t) &fvm2d);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c460f8
         fvm2sz = sp4.imageSize * 4;
         fvm2la = sp4.loadAddress;
         //21c45c58
         memset(&sp4, 0, sizeof(sp4));
         imageVersion = RELEASE_VIDEC_H264_0_VERSION; //0x48302004;
                  
         sp0x1c = FAPI_BOOT_GetImageInfoByVersion(r6, 
               imageVersion, &sp4);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45c90
         sp0x1c = FAPI_BOOT_LoadImageByVersion(r6, 
               imageVersion, (uint32_t) &fvh0d);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45cb0
         fvh0sz = sp4.imageSize * 4;
         fvh0la = sp4.loadAddress;
         
         memset(&sp4, 0, sizeof(sp4));
         imageVersion = RELEASE_VIDEC_H264_1_VERSION; //0x48312004;
                  
         sp0x1c = FAPI_BOOT_GetImageInfoByVersion(r6, 
               imageVersion, &sp4);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45d00
         sp0x1c = FAPI_BOOT_LoadImageByVersion(r6, 
               imageVersion, (uint32_t) &fvh1d);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45d20
         fvh1sz = sp4.imageSize * 4;
         fvh1la = sp4.loadAddress;
         
         memset(&sp4, 0, sizeof(sp4));
         imageVersion = RELEASE_VIDEC_H264_2_VERSION; //0x48322004;
                  
         sp0x1c = FAPI_BOOT_GetImageInfoByVersion(r6, 
               imageVersion, &sp4);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45d70
         sp0x1c = FAPI_BOOT_LoadImageByVersion(r6, 
               imageVersion, (uint32_t) &fvh2d);
         
         if (sp0x1c != 0)
         {
            //->21c45b28
            break;            
         }
         //21c45d90
         fvh2sz = sp4.imageSize * 4;
         fvh2la = sp4.loadAddress;
      }
      while (0);
      //21c45b28
      FAPI_BOOT_Close(r6);
      
      videoDriverLoadFirmwareErrorCode = sp0x1c;
#else
      videoDriverLoadFirmwareErrorCode = videcDriverLoadFirmwares();
#endif
      
      if (/*sp0x1c*/videoDriverLoadFirmwareErrorCode == 0)
      {
         videcDriverLoadFirmwaresState = 2;
         //->21c45894
      }
      else
      {
         //21c45b4c
         if (errorCodePtr != 0)
         {
            *errorCodePtr = videoDriverLoadFirmwareErrorCode; //sp0x1c;
         }
         //->21c45ab8
         return 0;
      }
   } //if (videcDriverLoadFirmwaresState == 1)
   //21c45884
   /*else*/ if (videoDriverLoadFirmwareErrorCode != 0)
   {
      //->21c45b60
      if (errorCodePtr != 0)
      {
         *errorCodePtr = videoDriverLoadFirmwareErrorCode;
      }
      //->21c45ab8
      return 0;
   }
   //21c45894
   if (paramsPtr == 0)
   {
      //21c45f38
      res = -28001;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      //->218ce550
      return 0;
   }
   //21c4589c
   if (paramsPtr->version > FAPI_VIDEC_VERSION)      
   {
      //21c45b7c
      res = -28101;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      //->218ce550
      return 0;
   }
   //21c458ac
   if ((paramsPtr->decodeFrameBankSizeType == FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE) ||
      (paramsPtr->decoderPlaybackMode == FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE) ||
      (paramsPtr->decoderAfdState == FAPI_VIDEC_UNKNOWN_AFD_STATE) ||
      (paramsPtr->decoderDelimiterType == FAPI_VIDEC_UNKNOWN_DELIMITER))
   {
      //21c45aa4
      res = -28102;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      //->218ce550
      return 0;
   }
   //21c458dc
   videc_lock(); //21c4305c
   //21c458e0
#if 0
   r6 = videcAllocateHandle(paramsPtr);
#else
   r6 = allocateHandle(paramsPtr, &res);
#endif
   //218ce538
   videc_unlock();
   //21c45ad0
   if (r6 == 0)
   {
      //218ce544
      res = 0xffff9238;
      if (errorCodePtr != 0)
      {
         *errorCodePtr = res;
      }
      //218ce550
      return 0;
   }
   //21c45990
   videc_lock();

   if ((paramsPtr->decoderType == 1) ||
         (paramsPtr->decoderType == 2))
   {
      //21c45db0
      if (paramsPtr->decoderNumber == 0)
      {
         //218ce57c
         r6->inUse = 1;
         strncpy(r6->coreName, "Videc", 32);

         r6->opParams = *paramsPtr;
         r6->coreID = FAPI_VIDEC_ID;
         r6->decoderBufferSize = FAPI_VIDEC_MAX_VIDEO_STREAM_BUFFER_SIZE[r6->opParams.decoderType];
         r6->baseAddress = FAPI_VIDEC_START_ADDRESS_0;

         r6->Start = fapi_videc_0start; //21c4a058
         r6->Stop = fapi_videc_0stop; //21c49aa4
         r6->ShutDown = fapi_videc_0shutdown; //21c4bebc
         r6->Reset = fapi_videc_0reset; //21c4c5dc
         r6->EnableDisable = fapi_videc_0enabledisable; //21c499a0
         r6->GetVesParams = fapi_videc_0getvesparams; //21c4bb50
         r6->GetVesBufferPosition = fapi_videc_0getvesbufferposition; //21c47334
         r6->GetVesBufferSize = fapi_videc_0getvesbuffersize; //21c4736c
         r6->GetVesFillLevel = fapi_videc_0getvesfilllevel; //21c4e14c
         r6->GetVesAvailableSpace = fapi_videc_0getvesavailablespace; //21c4e0f4
         r6->GetState = fapi_videc_0getstate; //21c47390
         r6->GetHealth = fapi_videc_0gethealth; //21c47494
         r6->GetDecodingLatency = fapi_videc_0getdecodinglatency; //21c474b8
         r6->AudCallback = fapi_videc_0audcallback; //21c4d6d4
         r6->Recover = fapi_videc_0recover; //21c4ca90

         if (paramsPtr->decoderType == 1)
         {
            //21c4602c
            r6->DecodeSingleMpegIFrame = fapi_videc_0decodesinglempegiframe; //21c49d64
            r6->DisplaySingleMpegIFrame = fapi_videc_0displaysinglempegiframe; //21c495ec
            r6->DecodeSequenceOfMpegIFrame = fapi_videc_0decodesequenceofmpegiframe; //21c491c4
            r6->DisplaySequenceOfMpegIFrame = fapi_videc_0displaysequenceofmpegiframe; //21c474fc
            r6->SetMpegIFrameMode = fapi_videc_0setmpegiframemode; //21c47b30
         }
         else
         {
            //21c45e98
            r6->DecodeSingleMpegIFrame = 0;
            r6->DisplaySingleMpegIFrame = 0;
            r6->DecodeSequenceOfMpegIFrame = 0;
            r6->DisplaySequenceOfMpegIFrame = 0;
            r6->SetMpegIFrameMode = 0;
         }
         //21c45eac
         r6->SetPlaybackMode = fapi_videc_0setplaybackmode; //21c47284
         r6->SetPlaybackEnvironment = fapi_videc_0setplaybackenvironment; //21c47300
         r6->SetEntropyDecInfoCallback = fapi_videc_0setentropydecinfocallback; //21c47518
         r6->SetVideoDecInfoCallback = fapi_videc_0setvideodecinfocallback; //21c47570
         r6->SetAutoScaleCallback = fapi_videc_0setautoscalecallback; //21c475c8
         r6->SetDecoderToHdEncoder = fapi_videc_0setdecodertohdencoder; //21c47680
         r6->SetPesParserToDecoder = fapi_videc_0setpesparsertodecoder; //21c478ec
         r6->SetFrameDecodedCallback = fapi_videc_0setframedecodedcallback; //21c47a28
         r6->SetFrameAvailableCallback = fapi_videc_0setframeavailablecallback; //21c47a80
         r6->SetVesOverflowCallback = fapi_videc_0setvesoverflowcallback; //21c47ad8
//         r6->SetMpegIFrameMode = fapi_videc_0setmpegiframemode;
         r6->SetChannelId = fapi_videc_0setchannelid; //21c47b50
         r6->SetParamChangeCallback = fapi_videc_0setparamchangecallback; //21c47bb8
         r6->SetAfdState = fapi_videc_0setafdstate; //21c47c10
         r6->Func_272 = func_21c47c6c;
         //21c45f1c
         res = fapi_videc_0initialize(r6);
      }
      else
      {
         //21c45f50
#if 1
         r6->inUse = 0;
         strncpy(r6->coreName, "Unknown Decoder", 32);
         r6->coreID = -1;
         r6->opParams.version = FAPI_VIDEC_VERSION;
         r6->opParams.decoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
         r6->opParams.decoderType = FAPI_VIDEC_UNKNOWN_DECODER;
         r6->opParams.decodeFrameBankSizeType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
         r6->opParams.decoderPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE;

         r6->Start = 0;
         r6->Stop = 0;
         r6->ShutDown = 0;
         r6->Reset = 0;
         r6->EnableDisable = 0;
         r6->GetVesParams = 0;
         r6->GetVesBufferPosition = 0;
         r6->GetVesBufferSize = 0;
         r6->GetVesFillLevel = 0;
         r6->GetVesAvailableSpace = 0;
         r6->GetState = 0;
         r6->GetHealth = 0;
         r6->GetDecodingLatency = 0;
         r6->AudCallback = 0;
         r6->Recover = 0;
         r6->DecodeSingleMpegIFrame = 0;
         r6->DisplaySingleMpegIFrame = 0;
         r6->DecodeSequenceOfMpegIFrame = 0;
         r6->DisplaySequenceOfMpegIFrame = 0;
         r6->SetPlaybackMode = 0;
         r6->SetPlaybackEnvironment = 0;
         r6->SetEntropyDecInfoCallback = 0;
         r6->SetVideoDecInfoCallback = 0;
         r6->SetAutoScaleCallback = 0;
         r6->SetDecoderToHdEncoder = 0;
         r6->SetPesParserToDecoder = 0;
         r6->SetFrameDecodedCallback = 0;
         r6->SetFrameAvailableCallback = 0;
         r6->SetVesOverflowCallback = 0;
         r6->SetMpegIFrameMode = 0;
         r6->SetChannelId = 0;
         r6->SetParamChangeCallback = 0;
         r6->SetAfdState = 0;
         r6->Func_272 = 0;

         r6->isrDataPtr = 0;
#endif
         res = 0xffff923a;
      }
   }
   else
   {
      //21c459a8
#if 1
      r6->inUse = 0;
      strncpy(r6->coreName, "Unknown Decoder", 32);
      r6->coreID = -1;
      r6->opParams.version = FAPI_VIDEC_VERSION;
      r6->opParams.decoderNumber = FAPI_VIDEC_UNKNOWN_DECODER_NUMBER;
      r6->opParams.decoderType = FAPI_VIDEC_UNKNOWN_DECODER;
      r6->opParams.decodeFrameBankSizeType = FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE;
      r6->opParams.decoderPlaybackMode = FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE;

      r6->Start = 0;
      r6->Stop = 0;
      r6->ShutDown = 0;
      r6->Reset = 0;
      r6->EnableDisable = 0;
      r6->GetVesParams = 0;
      r6->GetVesBufferPosition = 0;
      r6->GetVesBufferSize = 0;
      r6->GetVesFillLevel = 0;
      r6->GetVesAvailableSpace = 0;
      r6->GetState = 0;
      r6->GetHealth = 0;
      r6->GetDecodingLatency = 0;
      r6->AudCallback = 0;
      r6->Recover = 0;
      r6->DecodeSingleMpegIFrame = 0;
      r6->DisplaySingleMpegIFrame = 0;
      r6->DecodeSequenceOfMpegIFrame = 0;
      r6->DisplaySequenceOfMpegIFrame = 0;
      r6->SetPlaybackMode = 0;
      r6->SetPlaybackEnvironment = 0;
      r6->SetEntropyDecInfoCallback = 0;
      r6->SetVideoDecInfoCallback = 0;
      r6->SetAutoScaleCallback = 0;
      r6->SetDecoderToHdEncoder = 0;
      r6->SetPesParserToDecoder = 0;
      r6->SetFrameDecodedCallback = 0;
      r6->SetFrameAvailableCallback = 0;
      r6->SetVesOverflowCallback = 0;
      r6->SetMpegIFrameMode = 0;
      r6->SetChannelId = 0;
      r6->SetParamChangeCallback = 0;
      r6->SetAfdState = 0;
      r6->Func_272 = 0;

      r6->isrDataPtr = 0;
#endif
      res = 0xffff923a;
   }
   //21c45a84
   if (errorCodePtr != 0)
   {
      *errorCodePtr = res; //0xffff923a; //res;
   }

   if (res != 0)
   {
      //->21c45f28
      fapi_videc_release_handle(r6);
      r6 = 0;
   }

   videc_unlock();

//   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_Open: %i\n", res);

   return r6;
}


/* 21c457e4 - complete */
int32_t FAPI_VIDEC_Close(FAPI_SYS_HandleT handle)
{
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_Close\n");
   
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->Stop != 0)
      {
         (h->Stop)(h);
      }
      
      if (h->ShutDown != 0)
      {
         res = (h->ShutDown)();
      }
      else
      {
         res = -28106;
      }
      
      fapi_videc_release_handle(h);
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_Close: %i\n", res);

   return res;
}


/* 21c446cc - complete */
int32_t FAPI_VIDEC_Start(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_Start\n");

   videc_lock();

   if (0 != checkHandle(h))
   {
      if (h->Start != 0)
      {
         res = (h->Start)(h);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_Start: %i\n", res);

   return res;
}


/* 21c44678 - complete */
int32_t FAPI_VIDEC_Stop(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_Stop\n");

   videc_lock();

   if (0 != checkHandle(h))
   {
      if (h->Stop != 0)
      {
         res = (h->Stop)(h);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_Stop: %i\n", res);

   return res;
}


/* 21c4461c - complete */
int32_t FAPI_VIDEC_Reset(FAPI_SYS_HandleT handle,
                         FAPI_VIDEC_ResetEnumT resetType)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_Reset\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->Reset != 0)
      {
         res = (h->Reset)(handle, resetType);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_Reset: %i\n", res);

   return res;
}


/* 21c44578 - complete */
int32_t FAPI_VIDEC_FreezeContinue(FAPI_SYS_HandleT handle,
                     FAPI_VIDEC_FreezeContinueStateEnumT freezeSwitch)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_FreezeContinue\n");

   videc_lock();

   if (freezeSwitch == FAPI_VIDEC_FREEZE_OFF)
   {
      if (0 != checkHandle(handle))
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->Start != 0)
         {
            res = (h->Start)(handle);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }
   }
   else if (freezeSwitch == FAPI_VIDEC_FREEZE_ON)
   {
      if (0 != checkHandle(handle))
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->Reset != 0)
         {
            res = (h->Reset)(handle, FAPI_VIDEC_HARD_RESET);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_FreezeContinue: %i\n", res);

   return res;
}


/* 21c4451c - complete */
int32_t FAPI_VIDEC_EnableDisable(FAPI_SYS_HandleT handle,
                     FAPI_VIDEC_EnableDisableStateEnumT enableSwitch)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_EnableDisable\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->EnableDisable != 0)
      {
         res = (h->EnableDisable)(handle, enableSwitch);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_EnableDisable: %i\n", res);

   return res;
}


/* 21c444c0 - complete */
int32_t FAPI_VIDEC_SetPlaybackMode(FAPI_SYS_HandleT handle,
                                   FAPI_VIDEC_PlaybackModeEnumT mode)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetPlaybackMode\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetPlaybackMode != 0)
      {
         res = (h->SetPlaybackMode)(handle, mode);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetPlaybackMode: %i\n", res);

   return res;
}


/* 21c44464 - complete */
int32_t FAPI_VIDEC_SetPlaybackEnvironment(
                                 FAPI_SYS_HandleT handle,
                                 FAPI_VIDEC_PlaybackEnvironmentEnumT mode)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetPlaybackEnvironment\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetPlaybackEnvironment != 0)
      {
         res = (h->SetPlaybackEnvironment)(handle, mode);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetPlaybackEnvironment: %i\n", res);

   return res;
}


/* 21c443f4 - complete */
int32_t FAPI_VIDEC_GetVesParams(FAPI_SYS_HandleT handle,
                                FAPI_VIDEC_VESParamsT* vesParamsPtr,
                                uint32_t suspendType)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetVesParams\n");

   if (vesParamsPtr == 0) return -28108;

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->GetVesParams != 0)
      {
         res = (h->GetVesParams)(handle, vesParamsPtr, suspendType);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetVesParams: %i\n", res);

   return res;
}


/* 21c4438c - complete */
int32_t FAPI_VIDEC_GetVesBufferPosition(FAPI_SYS_HandleT handle, uint32_t* bufferPtr)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetVesBufferPosition\n");

   if (bufferPtr != 0)
   {
      videc_lock();
      
      if (0 != checkHandle(h))
      {
         if (h->GetVesBufferPosition != 0)
         {
            res = (h->GetVesBufferPosition)(h, bufferPtr);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }
      
      videc_unlock();
   }
   else
   {
      res = -28108;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetVesBufferPosition: %i\n", res);

   return res;
}


/* 21c44324 - complete */
int32_t FAPI_VIDEC_GetVesBufferSize(FAPI_SYS_HandleT handle, uint32_t* bufferSize)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetVesBufferSize\n");
   
   if (bufferSize != 0)
   {
      videc_lock();
      
      if (0 != checkHandle(h))
      {
         if (h->GetVesBufferSize != 0)
         {
            res = (h->GetVesBufferSize)(h, bufferSize);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }
      
      videc_unlock();
   }
   else
   {
      res = -28108;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetVesBufferSize: %i\n", res);

   return res;
}


/* 21c442bc - complete */
int32_t FAPI_VIDEC_GetVesFillLevel(FAPI_SYS_HandleT handle,
                                   uint32_t* fillLevel)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetVesFillLevel\n");

   if (fillLevel == 0) return -28108;

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->GetVesFillLevel != 0)
      {
         res = (h->GetVesFillLevel)(handle, fillLevel);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetVesFillLevel: %i\n", res);

   return res;
}


/* 21c44254 - complete */
int32_t FAPI_VIDEC_GetVesAvailableSpace(FAPI_SYS_HandleT handle,
                                        uint32_t* availableSpace)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetVesAvailableSpace\n");

   if (availableSpace == 0) return -28108;

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->GetVesAvailableSpace != 0)
      {
         res = (h->GetVesAvailableSpace)(handle, availableSpace);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetVesAvailableSpace: %i\n", res);

   return res;
}


/* 21c441f8 - complete */
int32_t FAPI_VIDEC_GetState(FAPI_SYS_HandleT handle,
                            FAPI_VIDEC_GetStateT* getStatePtr)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetState\n");

//   if (getStatePtr == 0) return -28108;

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->GetState != 0)
      {
         res = (h->GetState)(handle, getStatePtr);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetState: %i\n", res);

   return res;
}


/* 21c44190 - complete */
int32_t FAPI_VIDEC_GetHealth(FAPI_SYS_HandleT handle,
                             FAPI_VIDEC_HealthStateEnumT* health)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetHealth\n");

   if (health == 0) return -28108;

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->GetHealth != 0)
      {
         res = (h->GetHealth)(handle, health);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetHealth: %i\n", res);

   return res;
}


/* 21c44134 - complete */
int32_t FAPI_VIDEC_GetDecodingLatency(FAPI_SYS_HandleT handle,
                                      int64_t* decoderLatencyInTicks)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_GetDecodingLatency\n");

//   if (decoderLatencyInTicks == 0) return -28108;

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->GetDecodingLatency != 0)
      {
         res = (h->GetDecodingLatency)(handle, decoderLatencyInTicks);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_GetDecodingLatency: %i\n", res);

   return res;
}


/* 21c4303c - complete */
void FAPI_VIDEC_AudCallback(uint32_t audNum ,
                            uint32_t audSearchPattern,
                            uint32_t foundPtr,
                            FAPI_SYS_HandleT handle)
{
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_AudCallback\n");

   if ((h != 0) && (h->AudCallback != 0))
   {
      (h->AudCallback)(audNum, audSearchPattern, foundPtr, handle);
   }
}


/* 21c440e0 - complete */
int32_t FAPI_VIDEC_Recover(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_Recover\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->Recover != 0)
      {
         res = (h->Recover)(handle);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_Recover: %i\n", res);

   return res;
}


/* 21c44064 - complete */
int32_t FAPI_VIDEC_DecodeSingleMpegIFrame(FAPI_SYS_HandleT handle,
                            uint32_t* dataPtr, uint32_t sizeInBytes)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_DecodeSingleMpegIFrame\n");

   if ((dataPtr == 0) || (sizeInBytes == 0))
   {
      res = -28108;
   }
   else
   {
      videc_lock();

      if (0 != checkHandle(handle))
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->DecodeSingleMpegIFrame != 0)
         {
            res = (h->DecodeSingleMpegIFrame)(handle, dataPtr, sizeInBytes);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }

      videc_unlock();
   }

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_DecodeSingleMpegIFrame: %i\n", res);

   return res;
}


/* 21c44010 - complete */
int32_t FAPI_VIDEC_DisplaySingleMpegIFrame(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_DisplaySingleMpegIFrame\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->DisplaySingleMpegIFrame != 0)
      {
         res = (h->DisplaySingleMpegIFrame)(handle);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_DisplaySingleMpegIFrame: %i\n", res);

   return res;
}


/* 21c43f94 - complete */
int32_t FAPI_VIDEC_DecodeSequenceOfMpegIFrame(FAPI_SYS_HandleT handle,
                         uint32_t* dataPtr, uint32_t sizeInBytes)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_DecodeSequenceOfMpegIFrame\n");

   if ((dataPtr == 0) || (sizeInBytes == 0))
   {
      res = -28108;
   }
   else
   {
      videc_lock();

      if (0 != checkHandle(handle))
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->DecodeSequenceOfMpegIFrame != 0)
         {
            res = (h->DecodeSequenceOfMpegIFrame)(handle, dataPtr, sizeInBytes);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }

      videc_unlock();
   }

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_DecodeSequenceOfMpegIFrame: %i\n", res);

   return res;
}


/* 21c43f40 - complete */
int32_t FAPI_VIDEC_DisplaySequenceOfMpegIFrame(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_DisplaySequenceOfMpegIFrame\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->DisplaySequenceOfMpegIFrame != 0)
      {
         res = (h->DisplaySequenceOfMpegIFrame)(handle);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_DisplaySequenceOfMpegIFrame: %i\n", res);

   return res;
}


/* 21c43ecc - complete */
int32_t FAPI_VIDEC_SetEntropyDecInfoCallback(FAPI_SYS_HandleT handle,
                                  FAPI_VIDEC_EntropyDecInfoCallbackT
                                            entropyDecInfoCallbackFunction,
                                          void* entropyOptData)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetEntropyDecInfoCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      if (entropyDecInfoCallbackFunction == 0)
      {
         res = -28108;
      }
      else
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->SetEntropyDecInfoCallback != 0)
         {
            res = (h->SetEntropyDecInfoCallback)(handle,
                  entropyDecInfoCallbackFunction,
                  entropyOptData);
         }
         else
         {
            res = -28106;
         }
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetEntropyDecInfoCallback: %i\n", res);

   return res;
}


/* 21c43e58 - complete */
int32_t FAPI_VIDEC_SetVideoDecInfoCallback(FAPI_SYS_HandleT handle,
                         FAPI_VIDEC_VideoDecInfoCallbackT
                                     videoDecInfoCallbackFunction,
                                              void* videoOptData)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetVideoDecInfoCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      if (videoDecInfoCallbackFunction == 0)
      {
         res = -28108;
      }
      else
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->SetVideoDecInfoCallback != 0)
         {
            res = (h->SetVideoDecInfoCallback)(handle,
                  videoDecInfoCallbackFunction,
                  videoOptData);
         }
         else
         {
            res = -28106;
         }
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetVideoDecInfoCallback: %i\n", res);

   return res;
}


/* 21c43ddc - complete */
int32_t FAPI_VIDEC_SetAutoScaleCallback(FAPI_SYS_HandleT handle,
                         FAPI_VIDEC_AutoScaleCallbackT
                                        autoScaleCallbackFunction,
                                              void* scalerHandle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetAutoScaleCallback\n");

   if (autoScaleCallbackFunction == 0)
   {
      res = -28108;
   }
   else if (scalerHandle == 0)
   {
      res = -28108;
   }
   else
   {
      videc_lock();

      if (0 != checkHandle(handle))
      {
         FAPI_VIDEC_VideoDecoderHandleT* h = handle;

         if (h->SetAutoScaleCallback != 0)
         {
            res = (h->SetAutoScaleCallback)(handle,
                  autoScaleCallbackFunction,
                  scalerHandle);
         }
         else
         {
            res = -28106;
         }
      }
      else
      {
         res = -28107;
      }

      videc_unlock();
   }

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetAutoScaleCallback: %i\n", res);

   return res;
}


/* 21c43d40 - complete */
int32_t FAPI_VIDEC_SetDecoderToHdEncoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetDecoderToHdEncoder\n");

   if (viencHdHandle == 0)
   {
      h->decoderDisplayMode = FAPI_VIDEC_UNKNOWN_DISPLAY_MODE;

      res = -28120;
   }
   else
   {
      FAPI_VIENC_VideoEncoderHandleT* vh = viencHdHandle;

      if ((vh->opParams.interlaceProgressive == FAPI_VIENC_UNKNOWN_IP_MODE) ||
         (vh->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_PAL) ||
         (vh->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_NTSC) ||
         (vh->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_SECAM))
      {
         h->decoderDisplayMode = FAPI_VIDEC_UNKNOWN_DISPLAY_MODE;

         res = -28120;
      }
      else
      {
         videc_lock();

         if (0 != checkHandle(handle))
         {
            if (h->SetDecoderToHdEncoder != 0)
            {
               res = (h->SetDecoderToHdEncoder)(handle, viencHdHandle);
            }
            else
            {
               res = -28106;
            }
         }
         else
         {
            res = -28107;
         }

         videc_unlock();
      }
   }

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetDecoderToHdEncoder: %i\n", res);

   return res;
}


/* 21c43ce4 - complete */
int32_t FAPI_VIDEC_SetPesParserToDecoder(FAPI_SYS_HandleT handle,
                              FAPI_VIDEC_PesParserEnumT pesParserNum)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetPesParserToDecoder\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetPesParserToDecoder != 0)
      {
         res = (h->SetPesParserToDecoder)(handle, pesParserNum);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetPesParserToDecoder: %i\n", res);

   return res;
}


/* 21c43c80 - complete */
int32_t FAPI_VIDEC_SetFrameDecodedCallback(
          FAPI_SYS_HandleT handle,
          FAPI_VIDEC_FrameDecodedCallbackT
                      frameDecodedCallbackFunction,
          void* frameDecodedOptData)
{
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetFrameDecodedCallback\n");
      
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetFrameDecodedCallback != 0)
      {
         res = (h->SetFrameDecodedCallback)(h, 
               frameDecodedCallbackFunction,
               frameDecodedOptData);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetFrameDecodedCallback: %i\n", res);

   return res;
}


/* 21c43c1c - complete */
int32_t FAPI_VIDEC_SetFrameAvailableCallback(
          FAPI_SYS_HandleT handle,
          FAPI_VIDEC_FrameAvailableCallbackT frameAvailableCallbackFunction,
          void* frameAvailableOptData)
{      
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetFrameAvailableCallback\n");

   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetFrameAvailableCallback != 0)
      {
         res = (h->SetFrameAvailableCallback)(h, 
               frameAvailableCallbackFunction,
               frameAvailableOptData);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetFrameAvailableCallback: %i\n", res);

   return res;
}


/* 21c43bb8 - complete */
int32_t FAPI_VIDEC_SetVesOverflowCallback(
          FAPI_SYS_HandleT handle,
          FAPI_VIDEC_VesOverflowCallbackT vesOverflowCallbackFunction,
          void* vesOverflowOptData)
{      
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetVesOverflowCallback\n");

   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetVesOverflowCallback != 0)
      {
         res = (h->SetVesOverflowCallback)(h, 
               vesOverflowCallbackFunction,
               vesOverflowOptData);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetVesOverflowCallback: %i\n", res);

   return res;
}


/* 21c43b5c - complete */
int32_t FAPI_VIDEC_SetMpegIFrameMode(FAPI_SYS_HandleT handle,
                    FAPI_VIDEC_MpegIFrameModeEnumT mode)
{   
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetMpegIFrameMode\n");

   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetMpegIFrameMode != 0)
      {
         res = (h->SetMpegIFrameMode)(h, mode);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetMpegIFrameMode: %i\n", res);

   return res;
}


/* 21c43af8 - complete */
int32_t FAPI_VIDEC_SetChannelId(FAPI_SYS_HandleT handle,
                                uint32_t blockIndex,
                                uint32_t channelId)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetChannelId\n");

   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetChannelId != 0)
      {
         res = (h->SetChannelId)(h, blockIndex, channelId);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetChannelId: %i\n", res);

   return res;
}


/* 21c43a94 - complete */
int32_t FAPI_VIDEC_SetParamChangeCallback(
          FAPI_SYS_HandleT handle,
          FAPI_VIDEC_ParamChangeCallbackT paramChangeCallbackFunction,
          void* paramChangeOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetParamChangeCallback\n");
      
   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetParamChangeCallback != 0)
      {
         res = (h->SetParamChangeCallback)(h, 
               paramChangeCallbackFunction, 
               paramChangeOptData);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetParamChangeCallback: %i\n", res);

   return res;
}


/* 21c43a38 - complete */
int32_t FAPI_VIDEC_SetAfdState(FAPI_SYS_HandleT handle,
                   FAPI_VIDEC_AfdStateEnumT afdState)
{      
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_SetAfdState\n");

   videc_lock();
   
   if (0 != checkHandle(h))
   {
      if (h->SetAfdState != 0)
      {
         res = (h->SetAfdState)(h, afdState);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }
   
   videc_unlock();
   
   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_SetAfdState: %i\n", res);

   return res;
}


/* 21c439dc - complete */
int32_t func_21c439dc(FAPI_SYS_HandleT handle, int b)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(3, "func_21c439dc\n");

   videc_lock();

   if (0 != checkHandle(h))
   {
      if (h->Func_272 != 0)
      {
         res = (h->Func_272)(h, b);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "func_21c439dc: %i\n", res);

   return res;
}


/* 21c43980 - complete */
int32_t FAPI_VIDEC_ClearEntropyDecInfoCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearEntropyDecInfoCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetEntropyDecInfoCallback != 0)
      {
         res = (h->SetEntropyDecInfoCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearEntropyDecInfoCallback: %i\n", res);

   return res;
}


/* 21c43924 - complete */
int32_t FAPI_VIDEC_ClearVideoDecInfoCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearVideoDecInfoCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetVideoDecInfoCallback != 0)
      {
         res = (h->SetVideoDecInfoCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearVideoDecInfoCallback: %i\n", res);

   return res;
}


/* 21c438c8 - complete */
int32_t FAPI_VIDEC_ClearAutoScaleCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearAutoScaleCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetAutoScaleCallback != 0)
      {
         res = (h->SetAutoScaleCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearAutoScaleCallback: %i\n", res);

   return res;
}


/* 21c43870 - complete */
int32_t FAPI_VIDEC_ClearDecoderToHdEncoder(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearDecoderToHdEncoder\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetDecoderToHdEncoder != 0)
      {
         res = (h->SetDecoderToHdEncoder)(handle, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearDecoderToHdEncoder: %i\n", res);

   return res;
}


/* 21c43818 - complete */
int32_t FAPI_VIDEC_ClearPesParserToDecoder(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearPesParserToDecoder\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetPesParserToDecoder != 0)
      {
         res = (h->SetPesParserToDecoder)(handle, FAPI_VIDEC_NO_PESPARSER);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearPesParserToDecoder: %i\n", res);

   return res;
}


/* 21c437bc - complete */
int32_t FAPI_VIDEC_ClearFrameDecodedCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearFrameDecodedCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetFrameDecodedCallback != 0)
      {
         res = (h->SetFrameDecodedCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearFrameDecodedCallback: %i\n", res);

   return res;
}


/* 21c43760 - complete */
int32_t FAPI_VIDEC_ClearFrameAvailableCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearFrameAvailableCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetFrameAvailableCallback != 0)
      {
         res = (h->SetFrameAvailableCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearFrameAvailableCallback: %i\n", res);

   return res;
}


/* 21c43704 - complete */
int32_t FAPI_VIDEC_ClearVesOverflowCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearVesOverflowCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetVesOverflowCallback != 0)
      {
         res = (h->SetVesOverflowCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearVesOverflowCallback: %i\n", res);

   return res;
}


/* 21c436ac - complete */
int32_t FAPI_VIDEC_ClearMpegIFrameMode(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearMpegIFrameMode\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetMpegIFrameMode != 0)
      {
         res = (h->SetMpegIFrameMode)(handle, FAPI_VIDEC_NON_MPEG_IFRAME_MODE);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearMpegIFrameMode: %i\n", res);

   return res;
}


/* 21c43650 - complete */
int32_t FAPI_VIDEC_ClearChannelId(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearChannelId\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetChannelId != 0)
      {
         res = (h->SetChannelId)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearChannelId: %i\n", res);

   return res;
}


/* 21c435f4 - complete */
int32_t FAPI_VIDEC_ClearParamChangeCallback(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "FAPI_VIDEC_ClearParamChangeCallback\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->SetParamChangeCallback != 0)
      {
         res = (h->SetParamChangeCallback)(handle, 0, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "FAPI_VIDEC_ClearParamChangeCallback: %i\n", res);

   return res;
}



/* 21c4359c - complete */
int32_t func_21c4359c(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c4359c\n");

   videc_lock();

   if (0 != checkHandle(handle))
   {
      FAPI_VIDEC_VideoDecoderHandleT* h = handle;

      if (h->Func_272 != 0)
      {
         res = (h->Func_272)(handle, 0);
      }
      else
      {
         res = -28106;
      }
   }
   else
   {
      res = -28107;
   }

   videc_unlock();

   FAPI_SYS_PRINT_DEBUG(3, "func_21c4359c: %i\n", res);

   return res;
}


/* 21c4be74 - complete */
void func_21c4be74(void)
{
   FREG_VD_SetPbVcpbInfoTablesAddr(0);
   FREG_VD_SetPbVdpbInfoTablesAddr(0);
   FREG_VD_SetPbPcpuWorkAddr(0);
   FREG_VD_SetPbPcpuWorkSize(0);
   FREG_VD_SetPbDecStartParamsAddr(0);
   FREG_VD_SetPbOutcomeOfDecodeAddr(0);
   FREG_VD_SetIntEna(FAPI_VIDEC_HW_INTERRUPT_DISABLE_ALL);
   FREG_VD_SetClkEn(FAPI_VIDEC_HW_CLOCK_DISABLE);
}


/* 21c48b14 - complete */
int fapi_videc_write_pcpu_firmware(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   int res = 0;
   unsigned j, i = 0;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_write_pcpu_firmware\n");

   switch (a->opParams.decoderType)
   {
   case FAPI_VIDEC_MPEG2_MPHL:
      for (i = 0; i < 655360; i += 4)
      {
         FREG_VD_Write32(a->baseAddress + i, 0);
      }

      if (fvm0la == 0)
      {
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND;
      }
      else
      {
         for (j = 0, i = 0; i < fvm0sz; i+=4, j++)
         {
            FREG_VD_Write32(fvm0la + i,
                  fvm0d[j]);
         }
      }

      if (fvm1la == 0)
      {
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND;
      }

      if (res == 0)
      {
         for (j = 0, i = 0; i < fvm1sz; i += 4, j++)
         {
            FREG_VD_Write32(fvm1la + i,
                  fvm1d[j]);
         }
      }

      if (fvm2la == 0)
      {
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND;
      }

      if (res == 0)
      {
         for (j = 0, i = 0; i < fvm2sz; i += 4, j++)
         {
            FREG_VD_Write32(fvm2la + i,
                  fvm2d[j]);
         }
      }
      break;

   case FAPI_VIDEC_H264_HP41:
      for (i = 0; i < 655360; i += 4)
      {
         FREG_VD_Write32(a->baseAddress + i, 0);
      }

      if (fvh0la == 0)
      {
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND;
      }
      else
      {
         for (j = 0, i = 0; i < fvh0sz; i += 4, j++)
         {
            FREG_VD_Write32(fvh0la + i,
                  fvh0d[j]);
         }
      }

      if (fvh1la == 0)
      {
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND;
      }

      if (res == 0)
      {
         for (j = 0, i = 0; i < fvh1sz; i += 4, j++)
         {
            FREG_VD_Write32(fvh1la + i,
                  fvh1d[j]);
         }
      }

      if (fvh2la == 0)
      {
         res = FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND;
      }

      if (res == 0)
      {
         for (j = 0, i = 0; i < fvh2sz; i += 4, j++)
         {
            FREG_VD_Write32(fvh2la + i,
                  fvh2d[j]);
         }
      }
      break;

   default:
      res = FAPI_VIDEC_ERR_INVALID_OPEN_PARAMS;
      break;
   }
   
   return res;
}


/* 21c4c2a8 - complete */
int fapi_videc_boot_pcpu(FAPI_VIDEC_VideoDecoderHandleT* r4)
{
   int res = 0;
      
   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_boot_pcpu: r4->opParams.decoderType=%d\n",
         r4->opParams.decoderType);

   if (r4->isrDataPtr->bootState != FAPI_VIDEC_NOT_BOOTED)
   {
      return res;
   }
   
   r4->isrDataPtr->bootState = FAPI_VIDEC_REQUEST_TO_BOOT;

   switch (r4->opParams.decoderType)
   {
   case FAPI_VIDEC_MPEG2_MPHL:
      FREG_VD_SetCmdReset(FAPI_VIDEC_HW_RESET_ON);
      
      res = fapi_videc_write_pcpu_firmware(r4);
      if (res != 0)
      {
         break; //return res;
      }

      FREG_VD_SetPbVcpbInfoTablesAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->vcpbInfoTableStartAddress);
      FREG_VD_SetPbVdpbInfoTablesAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->vdpbInfoTableStartAddress);
      FREG_VD_SetPbPcpuWorkAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->pcpuWorkAreaStartAddress);
      FREG_VD_SetPbPcpuWorkSize(
            r4->isrDataPtr->physicalMemoryInfoPtr->pcpuWorkAreaSize);
      FREG_VD_SetPbDecStartParamsAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress);
      FREG_VD_SetPbOutcomeOfDecodeAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->oodInfoTableStartAddress);

      r4->bankNumForBumping = 0;

      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[0] =
         r4->isrDataPtr->physicalMemoryInfoPtr->videoStreamAreaStartAddress;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[1] =
         r4->decoderBufferSize;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[2] = 1;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[4] =
         r4->bankNumForBumping;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[5] =
         r4->bankNum;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[6] = 1920;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[7] = 1088;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[8] = 0;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[9] = 0;

      //TODO: FAPI_VIDEC_ERROR_CONCEALMENT_Y_ADDR_0
      FREG_VD_Write32(0x610e2220, 0x10);
      FREG_VD_Write32(0x610e2224, 0x80);
      FREG_VD_Write32(0x610e2228, 0x80);
      
      FREG_VD_SetIntEna(FAPI_VIDEC_HW_INTERRUPT_ENABLE_ALL);
      FREG_VD_SetClkEn(FAPI_VIDEC_HW_CLOCK_ENABLE);
      FREG_VD_SetCmdReset(FAPI_VIDEC_HW_RESET_OFF);

      FREG_VD_SetPcpuRamReadEnable(0x50320000);
      FREG_VD_SetPcpuRamReadEnable(0x40280000);
      FREG_VD_SetPcpuRamReadEnable(0x1c700000);
      break;
      
   case FAPI_VIDEC_H264_HP41:
      FREG_VD_SetCmdReset(FAPI_VIDEC_HW_RESET_ON);
      
      res = fapi_videc_write_pcpu_firmware(r4);
      if (res != 0)
      {
         break; //return res;
      }

      FREG_VD_SetPbVcpbInfoTablesAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->vcpbInfoTableStartAddress);
      FREG_VD_SetPbVdpbInfoTablesAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->vdpbInfoTableStartAddress);
      FREG_VD_SetPbPcpuWorkAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->pcpuWorkAreaStartAddress);
      FREG_VD_SetPbPcpuWorkSize(
            r4->isrDataPtr->physicalMemoryInfoPtr->pcpuWorkAreaSize);
      FREG_VD_SetPbDecStartParamsAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress);
      FREG_VD_SetPbOutcomeOfDecodeAddr(
            r4->isrDataPtr->physicalMemoryInfoPtr->oodInfoTableStartAddress);
          
      switch (r4->vBankType)
      {
      case FAPI_VIDEC_FRAME_BANK_SIZE_1920HD: //0:
         r4->bankNumForBumping = 4;
         break;
         
      case FAPI_VIDEC_FRAME_BANK_SIZE_1440HD: //1:
         r4->bankNumForBumping = 6;
         break;
         
      case FAPI_VIDEC_FRAME_BANK_SIZE_1280HD: //2:
         r4->bankNumForBumping = 9;
         break;
         
      case FAPI_VIDEC_FRAME_BANK_SIZE_SD: //3:
         r4->bankNumForBumping = 16;
         break;
         
      default:
         r4->bankNumForBumping = 0;
         break;
      }

      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[0] =
         r4->isrDataPtr->physicalMemoryInfoPtr->videoStreamAreaStartAddress;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[1] =
         r4->decoderBufferSize;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[2] = 1;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[4] =
         r4->bankNumForBumping;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[5] =
         r4->bankNum;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[6] = 1920;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[7] = 1088;
      ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[8] = 0;
      
      if (r4->isrDataPtr->Data_120 == Enum_120_0)
      {
         ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[9] = 0;
      }
      else if (r4->isrDataPtr->Data_120 == Enum_120_1)
      {
         ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[9] = 1;
      }
      else
      {
         ((uint32_t*)r4->isrDataPtr->physicalMemoryInfoPtr->decStartParamsStartAddress)[9] = 0;
      }

      FREG_VD_Write32(0x610e2220, 0x10);
      FREG_VD_Write32(0x610e2224, 0x80);
      FREG_VD_Write32(0x610e2228, 0x80);
      
      FREG_VD_SetIntEna(FAPI_VIDEC_HW_INTERRUPT_ENABLE_ALL);
      FREG_VD_SetClkEn(FAPI_VIDEC_HW_CLOCK_ENABLE);
      FREG_VD_SetCmdReset(FAPI_VIDEC_HW_RESET_OFF);

      FREG_VD_SetPcpuRamReadEnable(0x50320000);
      FREG_VD_SetPcpuRamReadEnable(0x40280000);
      FREG_VD_SetPcpuRamReadEnable(0x1c700000);
      break;
      
   default:
      return -28102; //break;
   }
   
   return res;
}


/* 21c4c1b8 - complete */
int fapi_videc_set_start_addresses(FAPI_VIDEC_VideoDecoderHandleT* r4)
{
   int res = 0;
   
   FREG_VD_SetStatus(0);
   
   if (r4->coreSel == 0)
   {
      FREG_VD_SetBaseCc_Adr(
            (r4->physicalMemoryInfoPtr->axiCcAreaStartAddress & 0x7fff800) >> 11);
      FREG_VD_SetBaseMw_Adr(
            (r4->physicalMemoryInfoPtr->axiMvAreaStartAddress & 0x7fff800) >> 11);
      FREG_VD_SetBaseDv_Adr(
            (r4->physicalMemoryInfoPtr->axiDvAreaStartAddress & 0x7fff800) >> 11);
   }
   else if (r4->coreSel == 1)
   {
      FREG_VD_SetBaseCc_Adr(0);
      FREG_VD_SetBaseMw_Adr(0);
      FREG_VD_SetBaseDv_Adr(0);
   }

   FREG_VD_SetBaseStm_Adr(
         (r4->physicalMemoryInfoPtr->videoStreamAreaStartAddress & 0x7fff800) >> 11);
   FREG_VD_SetBaseSeq_Adr(
         (r4->physicalMemoryInfoPtr->axiSeqAreaStartAddress & 0x7fff800) >> 11);
   FREG_VD_SetBaseAxp_Adr(
         r4->physicalMemoryInfoPtr->ramifsStartAddress >> 27);
   FREG_VD_SetStatus(0x80);
   FREG_VD_SetWrpConfig(0);
   FREG_VD_SetIrqEnable(3);
   
   return res;
}


/* 21c4305c - complete */
void videc_lock(void)
{
   FAPI_SYS_GET_SEMAPHORE(videcSemaphore, FAPI_SYS_SUSPEND);
}


/* 218cd4fc - complete */
void videc_unlock(void)
{
   FAPI_SYS_SET_SEMAPHORE(videcSemaphore, FAPI_SYS_NO_SUSPEND);
}


/* 21c49cc8 - complete */
int32_t fapi_videc_wait_start(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   uint64_t t;
   uint64_t t1 = FAPI_TIMER_GetTimeStamp(1000);

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_wait_start: t1=%d\n", t1);
   
   while (1)
   {
      t = FAPI_TIMER_GetTimeStamp(1000);

      t -= t1;

      if (a->isrDataPtr->startStopState == FAPI_VIDEC_STARTED)
      {
         break;
      }

      if (t > FAPI_VIDEC_ISR_START_TIMEOUT) //1000)
      {
         return FAPI_VIDEC_ERR_START_TIMEOUT;
      }

      FAPI_SYS_SLEEP(50);
   }

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_wait_start: t=%d\n", t);

   return 0;
}


/* 21c49a08 - complete */
int32_t fapi_videc_wait_stop(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   uint64_t t1 = FAPI_TIMER_GetTimeStamp(1000);

   while (1)
   {
      uint64_t t = FAPI_TIMER_GetTimeStamp(1000);

      t -= t1;

      if (a->isrDataPtr->startStopState == FAPI_VIDEC_STOPPED)
      {
         break;
      }

      if (t > 1000)
      {
         return FAPI_VIDEC_ERR_STOP_TIMEOUT;
      }

      FAPI_SYS_SLEEP(50);
   }

   return 0;
}


/* 21c4a058 - complete */
int32_t fapi_videc_0start(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }

   if (h->isrDataPtr->startStopState != FAPI_VIDEC_STARTED)
   {
      h->isrDataPtr->Data_124 = h->bankNum;
      h->isrDataPtr->decoderDisplayMode = h->decoderDisplayMode;
      h->isrDataPtr->startStopState = FAPI_VIDEC_PREPARE_TO_START;

      FREG_VD_SetIntReqToPcpu(MAINCPU_CMD_DECODE_START);

      h->isrDataPtr->startStopState = FAPI_VIDEC_REQUEST_TO_START;

      res = fapi_videc_wait_start(h);

      h->isrDataPtr->audInfo.seqStartFound = 0;
      h->isrDataPtr->audInfo.entryPointFound = 0;

      if (res == 0)
      {
         h->isrDataPtr->Data_196 = 6;
         h->isrDataPtr->healthState = FAPI_VIDEC_GOOD_HEALTH;
      }
      else
      {
         h->isrDataPtr->Data_196 = 5;
         h->isrDataPtr->healthState = FAPI_VIDEC_DEAD;
      }
   }

   return res;
}


/* 21c484f0 - complete */
void fapi_videc_clear_aud_info_data(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
//   FAPI_SYS_PRINT_MSG("fapi_videc_clear_aud_info_data\n");
   
   unsigned i = 0;
   
   a->audInfo.wPtr = 0;
   a->audInfo.rPtr = 0;
   a->audInfo.fPtr = 0;
   a->audInfo.fillLevel = 0;
   a->audInfo.fillLevelLimit = 1;
   
   a->audInfo.entryPointFound = 0;
   a->audInfo.seqStartFound = 0;
   a->audInfo.seqStartPtr = 0;
   
   a->audInfo.audStateVar = 0;
   a->audInfo.lastFoundPtr = 0;
   
   a->audInfo.monitorStartTimeABR = 0;
   a->audInfo.totalCodedStreamSizeABR = 0;
   
   a->audInfo.audCountCBR = 0;
   a->audInfo.monitorStartTimeCBR = 0;
   a->audInfo.totalCodedStreamSizeCBR = 0;
   
   for (i = 0; i < 768; i++)
   {
      a->audInfo.codedPic[i].Data_0 = -1;
      a->audInfo.codedPic[i].Data_4 = 0;
      a->audInfo.codedPic[i].Data_8 = -1;
      a->audInfo.codedPic[i].Data_12 = -1;
      a->audInfo.codedPic[i].Data_16 = -1;
      a->audInfo.codedPic[i].Data_20 = 0;
      a->audInfo.codedPic[i].Data_24 = 0;
      a->audInfo.codedPic[i].codedPicPtr = -1;
      a->audInfo.codedPic[i].codedPicSize = 0;
      a->audInfo.codedPic[i].Data_36 = 0;
      a->audInfo.codedPic[i].Data_40 = 0;
      a->audInfo.codedPic[i].pts = 0;
      a->audInfo.codedPic[i].dts = 0;
      a->audInfo.codedPic[i].state = FAPI_VIDEC_AUD_STATE_FREE;
   }
}


/* 21c48800 - complete */
void fapi_videc_set_aud_info_fill_level(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
   int r1;
   
   FAPI_SYS_PRINT_DEBUG(5, "fapi_videc_set_aud_info_fill_level\n");
   
   r1 = a->audInfo.wPtr - a->audInfo.fPtr;
   
   if (r1 < 0)
   {
      r1 += 768;
   }
   
   if (r1 >= a->audInfo.fillLevelLimit)
   {
      a->audInfo.fillLevel = r1 - a->audInfo.fillLevelLimit;
   }
   else
   {
      a->audInfo.fillLevel = 0;
   }
}


/* 21c48850 - complete */
void fapi_videc_set_frame_info_fill_level(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
   int r1;
   
   FAPI_SYS_PRINT_DEBUG(5, "fapi_videc_set_frame_info_fill_level\n");
   
   r1 = a->frameInfo.wPtr - a->frameInfo.rPtr;
   
   if (r1 < 0)
   {
      r1 += 48;
   }
   
   if (r1 >= a->frameInfo.fillLevelLimit)
   {
      a->frameInfo.fillLevel = r1 - a->frameInfo.fillLevelLimit;
   }
   else
   {
      a->frameInfo.fillLevel = 0;
   }
}


/* 21c47cb4 - complete */
void fapi_videc_clear_entropy_decoding_data(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
   uint32_t j = 0;
   uint32_t i = 0;

//   FAPI_SYS_PRINT_MSG("fapi_videc_clear_entropy_decoding_data\n");

   a->entropyDecInfoData.serialNum = -1; //705416
   a->entropyDecInfoData.afdUserDataActiveFormatFlag = 0; //705420
   a->entropyDecInfoData.ccUserDataProcessCcDataFlag = 0; //705428
   a->entropyDecInfoData.barUserDataTopBarFlag = 0; //705948
   a->entropyDecInfoData.barUserDataBotBarFlag = 0; //705956
   a->entropyDecInfoData.barUserDataLeftBarFlag = 0; //705964
   a->entropyDecInfoData.barUserDataRightBarFlag = 0; //705972
   a->entropyDecInfoData.currAfd = 0; //705424
   a->entropyDecInfoData.barUserDataEndOfTopBar = 0; //705952
   a->entropyDecInfoData.barUserDataStartOfBotBar = 0; //705960
   a->entropyDecInfoData.barUserDataEndOfLeftBar = 0; //705968
   a->entropyDecInfoData.barUserDataStartOfRightBar = 0; //705976
   a->entropyDecInfoData.ccUserDataCcCount = 0; //705432

   for (i = 0; i < 32; i++)
   {
      a->entropyDecInfoData.ccUserDataCcValid[i] = 0; //705436
      a->entropyDecInfoData.ccUserDataCcType[i] = 0;
      a->entropyDecInfoData.ccUserDataCcData1[i] = 0;
      a->entropyDecInfoData.ccUserDataCcData2[i] = 0;
   }

   a->entropyDecInfoData.MPEG2HorizontalSizeValue = -1; //705980
   a->entropyDecInfoData.MPEG2VerticalSizeValue = -1;
   a->entropyDecInfoData.MPEG2AspectRatioInformation = -1;
   a->entropyDecInfoData.MPEG2ProgressiveSequence = -1;
   a->entropyDecInfoData.MPEG2ChromaFormat = -1;
   a->entropyDecInfoData.MPEG2DisplayHorizontalSize = -1;
   a->entropyDecInfoData.MPEG2DisplayVerticalSize = -1;
   a->entropyDecInfoData.MPEG2ClosedGop = -1;
   a->entropyDecInfoData.MPEG2BrokenLink = -1;
   a->entropyDecInfoData.MPEG2PictureCodingType = -1;
   a->entropyDecInfoData.MPEG2PictureStructure = -1;
   a->entropyDecInfoData.MPEG2TopFieldFirst = -1;
   a->entropyDecInfoData.MPEG2RepeatFirstField = -1;
   a->entropyDecInfoData.MPEG2ProgressiveFrame = -1;
   a->entropyDecInfoData.MPEG2FieldSequence = -1;

   a->entropyDecInfoData.H264PicStructurePresentFlag = -1;
   a->entropyDecInfoData.H264PicStructure = -1;
   a->entropyDecInfoData.H264BrokenLinkFlag = -1;
   a->entropyDecInfoData.H264NalUnitType = -1;
   a->entropyDecInfoData.H264PicWidthInMbsMinus1 = -1;
   a->entropyDecInfoData.H264FrameHeightInMbs = -1;
   a->entropyDecInfoData.H264ProfileIdc = -1;
   a->entropyDecInfoData.H264LevelIdc = -1;
   a->entropyDecInfoData.H264FrameNum = -1;
   a->entropyDecInfoData.H264TopFieldOrderCount = -1;
   a->entropyDecInfoData.H264BotFieldOrderCount = -1;
   a->entropyDecInfoData.H264FieldPicFlag = -1;
   a->entropyDecInfoData.H264BotFieldFlag = -1;
   a->entropyDecInfoData.H264AspectRatioInfoPresentFlag = -1;
   a->entropyDecInfoData.H264AspectRatioIdc = -1;
   a->entropyDecInfoData.H264SarWidth = -1;
   a->entropyDecInfoData.H264SarHeight = -1;
   a->entropyDecInfoData.H264ChromaLocInfoPresentFlag = -1;
   a->entropyDecInfoData.H264ChromaSampleLocTypeTopField = -1;
   a->entropyDecInfoData.H264ChromaSampleLocTypeBotField = -1;

   a->oodInfo.wPtr = 0; //698724
   a->oodInfo.rPtrMemory = 0; //698728

   for (j = 0; j < OOD_FIFO_MAX_NUM; j++)
   {
      //21c47e8c
      a->oodInfo.table[j].serialNum = -1; //49508
      a->oodInfo.table[j].decodedPicAspectRatio = 0; //49512
      a->oodInfo.table[j].decodedWidth = 0; //49516
      a->oodInfo.table[j].decodedHeight = 0; //49520
      a->oodInfo.table[j].afdUserDataActiveFormatFlag = 0; //49528
      a->oodInfo.table[j].currAfd = 0; //49532
      a->oodInfo.table[j].ccUserDataProcessCcDataFlag = 0; //49536
      a->oodInfo.table[j].ccUserDataCcCount = 0; //49540

      for (i = 0; i < 32; i++)
      {
         a->oodInfo.table[j].ccUserDataCcValid[i] = 0; //705436
         a->oodInfo.table[j].ccUserDataCcType[i] = 0;
         a->oodInfo.table[j].ccUserDataCcData1[i] = 0;
         a->oodInfo.table[j].ccUserDataCcData2[i] = 0;
      }

      a->oodInfo.table[j].barUserDataTopBarFlag = 0; //50056
      a->oodInfo.table[j].barUserDataEndOfTopBar = 0;
      a->oodInfo.table[j].barUserDataBotBarFlag = 0;
      a->oodInfo.table[j].barUserDataStartOfBotBar = 0;
      a->oodInfo.table[j].barUserDataLeftBarFlag = 0;
      a->oodInfo.table[j].barUserDataEndOfLeftBar = 0;
      a->oodInfo.table[j].barUserDataRightBarFlag = 0;
      a->oodInfo.table[j].barUserDataStartOfRightBar = 0; //50084

      a->oodInfo.table[j].MPEG2HorizontalSizeValue = -1;
      a->oodInfo.table[j].MPEG2VerticalSizeValue = -1;
      a->oodInfo.table[j].MPEG2AspectRatioInformation = -1;
      a->oodInfo.table[j].MPEG2FrameRateCode = -1;
      a->oodInfo.table[j].MPEG2BitrateValue = -1;
      a->oodInfo.table[j].MPEG2VbvBufferSizeValue = -1;
      a->oodInfo.table[j].MPEG2ProgressiveSequence = -1;
      a->oodInfo.table[j].MPEG2ChromaFormat = -1;
      a->oodInfo.table[j].MPEG2HorizontalSizeExtention = -1;
      a->oodInfo.table[j].MPEG2VerticalSizeExtention = -1;
      a->oodInfo.table[j].MPEG2BitrateExtention = -1;
      a->oodInfo.table[j].MPEG2VbvBufferSizeExtention = -1;
      a->oodInfo.table[j].MPEG2DisplayHorizontalSize = -1;
      a->oodInfo.table[j].MPEG2DisplayVerticalSize = -1;
      a->oodInfo.table[j].MPEG2ClosedGop = -1;
      a->oodInfo.table[j].MPEG2BrokenLink = -1;
      a->oodInfo.table[j].MPEG2TemporalReference = -1;
      a->oodInfo.table[j].MPEG2PictureCodingType = -1;
      a->oodInfo.table[j].MPEG2VbvDelay = -1;
      a->oodInfo.table[j].MPEG2PictureStructure = -1;
      a->oodInfo.table[j].MPEG2TopFieldFirst = -1;
      a->oodInfo.table[j].MPEG2RepeatFirstField = -1;
      a->oodInfo.table[j].MPEG2ProgressiveFrame = -1;
      a->oodInfo.table[j].MPEG2CompositeDisplayFlag = -1;
      a->oodInfo.table[j].MPEG2FieldSequence = -1;
      a->oodInfo.table[j].MPEG2ColourDescription = -1;
      a->oodInfo.table[j].MPEG2ColourPrimaries = -1;
      a->oodInfo.table[j].MPEG2TransferCharacteristics = -1;
      a->oodInfo.table[j].MPEG2MatrixCoefficient = -1;
      a->oodInfo.table[j].MPEG2NumberOfFrameCenterOffsets = -1;
      a->oodInfo.table[j].MPEG2FrameCenterHorizontalOffset0 = -1;
      a->oodInfo.table[j].MPEG2FrameCenterVerticalOffset0 = -1;
      a->oodInfo.table[j].MPEG2FrameCenterHorizontalOffset1 = -1;
      a->oodInfo.table[j].MPEG2FrameCenterVerticalOffset1 = -1;
      a->oodInfo.table[j].MPEG2FrameCenterHorizontalOffset2 = -1;
      a->oodInfo.table[j].MPEG2FrameCenterVerticalOffset2 = -1;
      a->oodInfo.table[j].MPEGDecError = -1;
      a->oodInfo.table[j].MPEGDecInfo = -1;

      a->oodInfo.table[j].H264VclHrdBpPresentFlag = -1;
      a->oodInfo.table[j].H264NalHrdBpPresentFlag = -1;
      a->oodInfo.table[j].H264BufferingPeriodSeiPresentFlag = -1;
//      a->oodInfo.table[j].H264SequenceParameterSetId = -1;
      a->oodInfo.table[j].H264NalInitialCpbRemovalDelay = -1;
      a->oodInfo.table[j].H264NalInitialCpbRemovalDelayOffset = -1;
      a->oodInfo.table[j].H264VclInitialCpbRemovalDelay = -1;
      a->oodInfo.table[j].H264VclInitialCpbRemovalDelayOffset = -1;
      a->oodInfo.table[j].H264ClockTs2PresentFlag = -1;
      a->oodInfo.table[j].H264ClockTs1PresentFlag = -1;
      a->oodInfo.table[j].H264ClockTs0PresentFlag = -1;
      a->oodInfo.table[j].H264PicStructurePresentFlag = -1;
      a->oodInfo.table[j].H264CpbDpbDelaysPresentFlag = -1;
      a->oodInfo.table[j].H264PicTimingSeiPresentFlag = -1;
      a->oodInfo.table[j].H264CpbRemovalDelay = -1;
      a->oodInfo.table[j].H264DpbOutputDelay = -1;
      a->oodInfo.table[j].H264PicStructure = -1;
      a->oodInfo.table[j].H264ClkTimestampFlag0 = -1;
      a->oodInfo.table[j].H264CtType0 = -1;
      a->oodInfo.table[j].H264NuitFieldBasedFlag0 = -1;
      a->oodInfo.table[j].H264CountingType0 = -1;
      a->oodInfo.table[j].H264FullTimestampFlag0 = -1;
      a->oodInfo.table[j].H264DiscontinuityFlag0 = -1;
      a->oodInfo.table[j].H264CntDroppedFlag0 = -1;
      a->oodInfo.table[j].H264NFrames0 = -1;
      a->oodInfo.table[j].H264SecondsFlag0 = -1;
      a->oodInfo.table[j].H264SecondsValue0 = -1;
      a->oodInfo.table[j].H264MinutesFlag0 = -1;
      a->oodInfo.table[j].H264MinutesValue0 = -1;
      a->oodInfo.table[j].H264HoursFlag0 = -1;
      a->oodInfo.table[j].H264HoursValue0 = -1;
      a->oodInfo.table[j].H264TimeOffset0 = -1;
      a->oodInfo.table[j].H264ClkTimestampFlag1 = -1;
      a->oodInfo.table[j].H264CtType1 = -1;
      a->oodInfo.table[j].H264NuitFieldBasedFlag1 = -1;
      a->oodInfo.table[j].H264CountingType1 = -1;
      a->oodInfo.table[j].H264FullTimestampFlag1 = -1;
      a->oodInfo.table[j].H264DiscontinuityFlag1 = -1;
      a->oodInfo.table[j].H264CntDroppedFlag1 = -1;
      a->oodInfo.table[j].H264NFrames1 = -1;
      a->oodInfo.table[j].H264SecondsFlag1 = -1;
      a->oodInfo.table[j].H264SecondsValue1 = -1;
      a->oodInfo.table[j].H264MinutesFlag1 = -1;
      a->oodInfo.table[j].H264MinutesValue1 = -1;
      a->oodInfo.table[j].H264HoursFlag1 = -1;
      a->oodInfo.table[j].H264HoursValue1 = -1;
      a->oodInfo.table[j].H264TimeOffset1 = -1;
      a->oodInfo.table[j].H264ClkTimestampFlag2 = -1;
      a->oodInfo.table[j].H264CtType2 = -1;
      a->oodInfo.table[j].H264NuitFieldBasedFlag2 = -1;
      a->oodInfo.table[j].H264CountingType2 = -1;
      a->oodInfo.table[j].H264FullTimestampFlag2 = -1;
      a->oodInfo.table[j].H264DiscontinuityFlag2 = -1;
      a->oodInfo.table[j].H264CntDroppedFlag2 = -1;
      a->oodInfo.table[j].H264NFrames2 = -1;
      a->oodInfo.table[j].H264SecondsFlag2 = -1;
      a->oodInfo.table[j].H264SecondsValue2 = -1;
      a->oodInfo.table[j].H264MinutesFlag2 = -1;
      a->oodInfo.table[j].H264MinutesValue2 = -1;
      a->oodInfo.table[j].H264HoursFlag2 = -1;
      a->oodInfo.table[j].H264HoursValue2 = -1;
      a->oodInfo.table[j].H264TimeOffset2 = -1;
      a->oodInfo.table[j].H264PanScanSeiPresentFlag = -1;
      a->oodInfo.table[j].H264PanScanRectangleId = -1;
      a->oodInfo.table[j].H264PanScanRectCancelFlag = -1;
      a->oodInfo.table[j].H264PanScanCntMinus1 = -1;
      a->oodInfo.table[j].H264PanScanLeftOffset0 = -1;
      a->oodInfo.table[j].H264PanScanRightOffset0 = -1;
      a->oodInfo.table[j].H264PanScanTopOffset0 = -1;
      a->oodInfo.table[j].H264PanScanBotOffset0 = -1;
      a->oodInfo.table[j].H264PanScanLeftOffset1 = -1;
      a->oodInfo.table[j].H264PanScanRightOffset1 = -1;
      a->oodInfo.table[j].H264PanScanTopOffset1 = -1;
      a->oodInfo.table[j].H264PanScanBotOffset1 = -1;
      a->oodInfo.table[j].H264PanScanLeftOffset2 = -1;
      a->oodInfo.table[j].H264PanScanRightOffset2 = -1;
      a->oodInfo.table[j].H264PanScanTopOffset2 = -1;
      a->oodInfo.table[j].H264PanScanBotOffset2 = -1;
      a->oodInfo.table[j].H264PanScanRectRepetitionPeriod = -1;
      a->oodInfo.table[j].H264RecoveryPointSeiPresentFlag = -1;
      a->oodInfo.table[j].H264RecoveryFrameCount = -1;
      a->oodInfo.table[j].H264ExactMatchFlag = -1;
      a->oodInfo.table[j].H264BrokenLinkFlag = -1;
      a->oodInfo.table[j].H264ChangingSliceGroupIdc = -1;
      a->oodInfo.table[j].H264PrimaryPicType = -1;
      a->oodInfo.table[j].H264NalRefIdc = -1;
      a->oodInfo.table[j].H264NalUnitType = -1;
      a->oodInfo.table[j].H264MaxDpbSize = -1;
      a->oodInfo.table[j].H264PicWidthInMbsMinus1 = -1;
      a->oodInfo.table[j].H264FrameHeightInMbs = -1;
      a->oodInfo.table[j].H264Log2MaxFrameNumMinus4 = -1;
      a->oodInfo.table[j].H264FrameMbsOnlyFlag = -1;
      a->oodInfo.table[j].H264MbAdaptiveFrameFieldFlag = -1;
      a->oodInfo.table[j].H264ProfileIdc = -1;
      a->oodInfo.table[j].H264LevelIdc = -1;
      a->oodInfo.table[j].H264FrameCropTopOffset = -1;
      a->oodInfo.table[j].H264FrameCropBotOffset = -1;
      a->oodInfo.table[j].H264FrameCropLeftOffset = -1;
      a->oodInfo.table[j].H264FrameCropRightOffset = -1;
      a->oodInfo.table[j].H264PicParameterSetId = -1;
      a->oodInfo.table[j].H264SeqParameterSetId = -1;
      a->oodInfo.table[j].H264ChromaQpIndexOffset = -1;
      a->oodInfo.table[j].H264SecondChromaQpIndexOffset = -1;
      a->oodInfo.table[j].H264Transform8x8ModeFlag = -1;
      a->oodInfo.table[j].H264FrameNum = -1;
      a->oodInfo.table[j].H264IdrPicId = -1;
      a->oodInfo.table[j].H264TopFieldOrderCount = -1;
      a->oodInfo.table[j].H264BotFieldOrderCount = -1;
      a->oodInfo.table[j].H264ChromaFormatIdc = -1;
      a->oodInfo.table[j].H264FieldPicFlag = -1;
      a->oodInfo.table[j].H264BotFieldFlag = -1;
      a->oodInfo.table[j].H264EndOfSequenceRbsp = -1;
      a->oodInfo.table[j].H264EndOfStreamRbsp = -1;
      a->oodInfo.table[j].H264BitRate = -1;
      a->oodInfo.table[j].H264AspectRatioInfoPresentFlag = -1;
      a->oodInfo.table[j].H264AspectRatioIdc = -1;
      a->oodInfo.table[j].H264SarWidth = -1;
      a->oodInfo.table[j].H264SarHeight = -1;
      a->oodInfo.table[j].H264VideoSignalTypePresentFlag = -1;
      a->oodInfo.table[j].H264TimingfInfoPresentFlag = -1;
      a->oodInfo.table[j].H264ColourDescriptionPresentFlag = -1;
      a->oodInfo.table[j].H264ChromaLocInfoPresentFlag = -1;
      a->oodInfo.table[j].H264VideoFullRangeFlag = -1;
      a->oodInfo.table[j].H264VideoFormat = -1;
      a->oodInfo.table[j].H264NumUnitsInTick = -1;
      a->oodInfo.table[j].H264TimeScale = -1;
      a->oodInfo.table[j].H264FixedFrameRateFlag = -1;
      a->oodInfo.table[j].H264ColourPrimaries = -1;
      a->oodInfo.table[j].H264TransferCharacteristics = -1;
      a->oodInfo.table[j].H264MatrixCoefficient = -1;
      a->oodInfo.table[j].H264ChromaSampleLocTypeTopField = -1;
      a->oodInfo.table[j].H264ChromaSampleLocTypeBotField = -1;
      a->oodInfo.table[j].H264DecError = -1;
      a->oodInfo.table[j].H264DecInfo = -1;
   }
}


/* 21c48600 - complete */
void fapi_videc_clear_video_decoding_data(FAPI_VIDEC_VideoDecoderIsrDataT* a)
{
//   FAPI_SYS_PRINT_MSG("fapi_videc_clear_video_decoding_data\n");

   uint32_t i = 0;

   a->videoDecInfoData.rPtr = 0; //706128
   a->videoDecInfoData.serialNum = -1;//706132
   a->videoDecInfoData.frameBank = -1; //706136
   a->videoDecInfoData.displayWidth = 0; //706140
   a->videoDecInfoData.displayHeight = 0; //706144
   a->videoDecInfoData.decodedWidth = 0; //706148
   a->videoDecInfoData.decodedHeight = 0; //706152
   a->videoDecInfoData.displayOrderInfo = 0; //706156
   a->videoDecInfoData.topFieldSerialNo = -1; //706160
   a->videoDecInfoData.botFieldSerialNo = -1; //706164
   a->videoDecInfoData.ptsValidFlag = 0; //706168
   a->videoDecInfoData.dtsValidFlag = 0; //706172
   a->videoDecInfoData.pts = 0; //706176
   a->videoDecInfoData.dts = 0; //706184

   a->frameInfo.wPtr = 0; //705080
   a->frameInfo.rPtr = 0; //705084
   a->frameInfo.fillLevel = 0; //705088
   a->frameInfo.fillLevelLimit = 1;//705092

   for (i = 0; i < FRAME_FIFO_MAX_NUM; i++)
   {
      //21c486b8
      a->frameInfo.decodedPic[i].serialNum = -1; //698744
      a->frameInfo.decodedPic[i].displayFrameBank = -1; //698748
      a->frameInfo.decodedPic[i].displayWidth = 0; //698752
      a->frameInfo.decodedPic[i].displayHeight = 0; //698756
      a->frameInfo.decodedPic[i].decodedWidth = 0; //698760
      a->frameInfo.decodedPic[i].decodedHeight = 0; //698764
      a->frameInfo.decodedPic[i].displayOrderInfo = 0; //698768
      a->frameInfo.decodedPic[i].topFieldSerialNo = -1; //698772
      a->frameInfo.decodedPic[i].botFieldSerialNo = -1; //698776
      a->frameInfo.decodedPic[i].ptsValidFlag = 0; //698780
      a->frameInfo.decodedPic[i].dtsValidFlag = 0; //698784
      a->frameInfo.decodedPic[i].pts = 0; //698788
      a->frameInfo.decodedPic[i].dts = 0; //698792
      a->frameInfo.decodedPic[i].state = -1; //698796
      a->frameInfo.decodedPic[i].topDecError = -1; //698800
      a->frameInfo.decodedPic[i].botDecError = -1; //698804
      a->frameInfo.decodedPic[i].vdpbDispCount = 0; //698808
      a->frameInfo.decodedPic[i].decodedPicAspectRatio = 0; //698812
      a->frameInfo.decodedPic[i].activePicAspectRatioL0 = 0; //698816
      a->frameInfo.decodedPic[i].activePicAspectRatioL1 = 0; //698820
      a->frameInfo.decodedPic[i].afdUserDataActiveFormatFlag = 0; //698824
      a->frameInfo.decodedPic[i].currAfd = 0; //698828
      a->frameInfo.decodedPic[i].codedInterlaceProggState = -1; //698832
      a->frameInfo.decodedPic[i].readoutInterlaceProggState = -1; //698836
      a->frameInfo.decodedPic[i].barUserDataTopBarFlag = 0; //698840
      a->frameInfo.decodedPic[i].barUserDataEndOfTopBar = 0; //698844
      a->frameInfo.decodedPic[i].barUserDataBotBarFlag = 0; //698848
      a->frameInfo.decodedPic[i].barUserDataStartOfBotBar = 0; //698852
      a->frameInfo.decodedPic[i].barUserDataLeftBarFlag = 0; //698856
      a->frameInfo.decodedPic[i].barUserDataEndOfLeftBar = 0; //698860
      a->frameInfo.decodedPic[i].barUserDataRightBarFlag = 0; //698864
      a->frameInfo.decodedPic[i].barUserDataStartOfRightBar = 0; //698868
      a->frameInfo.decodedPic[i].Data_128 = -1; //698872
   }
}


/* 21c49aa4 - complete */
int32_t fapi_videc_0stop(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;

   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }

   if (h->isrDataPtr->startStopState != FAPI_VIDEC_STOPPED)
   {
      h->isrDataPtr->startStopState = FAPI_VIDEC_PREPARE_TO_STOP;

      FREG_VD_SetIntReqToPcpu(0x4000000);

      h->isrDataPtr->startStopState = FAPI_VIDEC_REQUEST_TO_STOP;

      res = fapi_videc_wait_stop(h);

      h->isrDataPtr->isrMask = 0;
      h->isrDataPtr->isrStatus = 0;
      h->isrDataPtr->isrSerialIdx = 0;
      h->isrDataPtr->isrCurrField = 0;
      h->isrDataPtr->isrNextField = 1;
      
      h->isrDataPtr->currIsrTimeUsec = 0;
      h->isrDataPtr->Data_12 = 0;
      h->isrDataPtr->currVcpbDecTimeMsec = 0;
      h->isrDataPtr->Data_28 = 0;
      
      h->isrDataPtr->Data_36 = 0;
      h->isrDataPtr->Data_44 = 0;
      h->isrDataPtr->Data_52 = 0;
      h->isrDataPtr->Data_60 = 0;

      h->isrDataPtr->bufferInfo.fillLevel = 0;
      h->isrDataPtr->bufferInfo.availableSpace = 
         h->decoderBufferSize / 2;

      h->isrDataPtr->healthState = FAPI_VIDEC_GOOD_HEALTH;
      h->isrDataPtr->mpegIFrameState = FAPI_VIDEC_NON_MPEG_IFRAME_STATE;
      h->isrDataPtr->Data_192 = -1;
      h->isrDataPtr->Data_196 = 0;
      h->isrDataPtr->Data_200 = Enum_200_a;
      h->isrDataPtr->Data_204 = 0;
      h->isrDataPtr->vesInfo.vesAverageBitRate = 0; //Data_208 = 0;
      h->isrDataPtr->vesInfo.vesCurrBitRate = 0; //Data_212 = 0;
      h->isrDataPtr->vesInfo.vesAspectRatio = FAPI_VIDEC_AR_NONE; //Data_216 = 0;
      h->isrDataPtr->vesInfo.vesFrameRate = 0; //Data_220 = 0;
      h->isrDataPtr->vesInfo.proggInter = -1; //Data_232 = -1;
      h->isrDataPtr->vesInfo.displayWidth = 0; //Data_236 = 0;
      h->isrDataPtr->vesInfo.displayHeight = 0; //Data_240 = 0;
      h->isrDataPtr->vesInfo.decodedWidth = 0; //Data_244 = 0;
      h->isrDataPtr->vesInfo.decodedHeight = 0; //Data_248 = 0;

      h->isrDataPtr->audLastPts = 0; //Data_49480 = 0;
      h->isrDataPtr->audIdx = 0; //Data_49488 = 0;
      
      h->isrDataPtr->vcpbAddress = 0; //Data_49492 = 0;
      h->isrDataPtr->vcpbLength = 0; //Data_49496 = 0;
      h->isrDataPtr->vcpbLoadIdx = 0; //Data_49500 = 0;
      h->isrDataPtr->vcpbIdx = 0; //Data_49504 = 0;

      h->isrDataPtr->oodSerialNum = 0;
      h->isrDataPtr->oodEntropyDecodedAudIdx = 0;
      h->isrDataPtr->oodIdx = 0;

      h->isrDataPtr->vdpbDecodedFramesAvailable = 0; //Data_705096 = 0;
      h->isrDataPtr->vdpbSerialNum = 0; //Data_705100 = 0;
      h->isrDataPtr->Data_705104 = 0;
      h->isrDataPtr->vdpbIdx = 0; //Data_705108 = 0;

      h->isrDataPtr->Data_705268 = 0;
      h->isrDataPtr->Data_705276 = 0;

      h->isrDataPtr->frameFieldState = FAPI_VIDEC_NO_FIELD_FREEZE_STATE;
      h->isrDataPtr->frameStartDisplay = 0;
      h->isrDataPtr->frameState = FAPI_VIDEC_UNKNOWN_FRAME_STATE;

      h->isrDataPtr->frameDisplayOrderInfo = 0; //705380
      h->isrDataPtr->frameTopFieldNo = 0; //705384
      h->isrDataPtr->frameBotFieldNo = 0; //705388
      h->isrDataPtr->frameSerialNum = 0; //705392
      h->isrDataPtr->frameIdx = 0; //705396
      h->isrDataPtr->frameDecError = 0; //705400
      h->isrDataPtr->Data_705404 = 0;
      
      h->isrDataPtr->invokeAutoScalers = 0; //705408

      fapi_videc_clear_aud_info_data(h->isrDataPtr);

      fapi_videc_clear_entropy_decoding_data(h->isrDataPtr);

      fapi_videc_clear_video_decoding_data(h->isrDataPtr);
   }

   return res;
}


/* 21c4bebc - complete */
int32_t fapi_videc_0shutdown(void)
{   
   Data_21f67278 = 0;
   
   func_21c4be74();
   
   return 0;
}


/* 21c4c5dc - todo */
int32_t fapi_videc_0reset(FAPI_SYS_HandleT handle,
                                              FAPI_VIDEC_ResetEnumT resetType)
{
   return 0;
}


/* 21c49538 - complete */
int32_t fapi_videc_wait_enable_disable(FAPI_VIDEC_VideoDecoderHandleT* a)
{
   uint64_t t;
   uint64_t t1 = FAPI_TIMER_GetTimeStamp(1000);

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_wait_enable_disable: t1=%d\n", t1);
   
   while (1)
   {
      t = FAPI_TIMER_GetTimeStamp(1000);

      t -= t1;

      if (a->isrDataPtr->enableDisableState == 
         FAPI_VIDEC_FORCE_ENABLED)
      {
         break;
      }

      if (a->isrDataPtr->enableDisableState == 
         FAPI_VIDEC_FORCE_DISABLED)
      {
         break;
      }
       
      if (a->isrDataPtr->enableDisableState == 
         FAPI_VIDEC_SYNCHRONIZE_ENABLED)
      {
         break;
      }

      if (t > FAPI_VIDEC_ISR_ENABLE_TIMEOUT) //20000)
      {
         return FAPI_VIDEC_ERR_ENABLE_DISABLE_TIMEOUT;
      }

      FAPI_SYS_SLEEP(50);
   }

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_wait_enable_disable: t=%d\n", t);

   return 0;
}


/* 21c499a0 - complete */
int32_t fapi_videc_0enabledisable(FAPI_SYS_HandleT handle,
                              FAPI_VIDEC_EnableDisableStateEnumT enableSwitch)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   
   if (enableSwitch == FAPI_VIDEC_ENABLE_SYNCHRONOUSLY_SUSPEND)
   {
      h->isrDataPtr->enableDisableState = FAPI_VIDEC_REQUEST_TO_SYNCHRONIZE_ENABLE;
      res = fapi_videc_wait_enable_disable(h);
   }
   else if (enableSwitch == FAPI_VIDEC_ENABLE_SYNCHRONOUSLY_NO_SUSPEND)
   {
      h->isrDataPtr->enableDisableState = FAPI_VIDEC_REQUEST_TO_SYNCHRONIZE_ENABLE;
   }
   else if (enableSwitch == FAPI_VIDEC_ENABLE_FORCE_ON)
   {
      h->isrDataPtr->enableDisableState = FAPI_VIDEC_REQUEST_TO_FORCE_ENABLE;
      res = fapi_videc_wait_enable_disable(h);
   }
   else if (enableSwitch == FAPI_VIDEC_ENABLE_FORCE_OFF)
   {
      h->isrDataPtr->enableDisableState = FAPI_VIDEC_REQUEST_TO_FORCE_DISABLE;
      res = fapi_videc_wait_enable_disable(h);
   }
   
   return res;
}


/* 21c4bb50 - todo */
int32_t fapi_videc_0getvesparams(FAPI_SYS_HandleT handle,
                    FAPI_VIDEC_VESParamsT* vesParamsPtr, uint32_t suspendType)
{
   return 0;
}


/* 21c4d244 - complete */
int32_t fapi_videc_update_buffer_info(FAPI_VIDEC_VideoDecoderIsrDataT* r4)
{
   int r5;
   int ip;
   int r3_;
   unsigned fPtr;
   unsigned wPtr;
   unsigned r0;
   int r1;
   unsigned r6;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(5, "fapi_videc_update_buffer_info\n");

   fPtr = r4->audInfo.fPtr;
   if (fPtr == 0)
   {
      fPtr = 767;
   }
   else
   {
      fPtr--;
   }

   r5 = r4->audInfo.codedPic[fPtr].codedPicPtr +
      r4->audInfo.codedPic[fPtr].codedPicSize;

   if (r5 <= (int) r4->bufferInfo.size)
   {
      r1 = 0;
   }
   else
   {
      r1 = r4->bufferInfo.size;
   }

   r6 = r5 - r1;

   wPtr = r4->audInfo.wPtr;
   if (wPtr == 0)
   {
      wPtr = 767;
   }
   else
   {
      wPtr--;
   }

   if ((r4->channelInfo.blockIndex == (uint32_t)-1) ||
         (r4->channelInfo.channelId == (uint32_t)-1))
   {
      r0 = r4->audInfo.codedPic[wPtr].codedPicPtr;
   }
   else
   {
      if (r4->channelInfo.blockIndex == 0)
      {
         r0 = FREG_BM0_GetWrPtr_WrPointer(r4->channelInfo.channelId);
      }
      else if (r4->channelInfo.blockIndex == 1)
      {
         r0 = FREG_BM1_GetWrPtr_WrPointer(r4->channelInfo.channelId);
      }
      else if (r4->channelInfo.blockIndex == 2)
      {
         r0 = FREG_BM2_GetWrPtr_WrPointer(r4->channelInfo.channelId);
      }
      else if (r4->channelInfo.blockIndex == 3)
      {
         r0 = FREG_BM3_GetWrPtr_WrPointer(r4->channelInfo.channelId);
      }
      else
      {
         r0 = r4->audInfo.codedPic[wPtr].codedPicPtr;
      }
   }

   ip = r4->bufferInfo.size;

   r3_ = r0 - r6;

   if (r3_ < 0)
   {
      r1 = r3_ + ip;
   }
   else if (ip >= r3_)
   {
      r1 = r3_;
   }
   else
   {
      r1 = ip;
   }

   if ((int)r4->bufferInfo.criticalThreshold < r1)
   {
      r4->bufferInfo.availableSpace = 0;
      r4->bufferInfo.fillLevel = r4->bufferInfo.criticalThreshold;

      res = FAPI_VIDEC_ERR_VES_BUFFER_OVERFLOW;
   }
   else if ((int)r4->bufferInfo.optimalThreshold <= r1)
   {
      r4->bufferInfo.fillLevel = r4->bufferInfo.optimalThreshold;
      r4->bufferInfo.availableSpace = 0;
   }
   else
   {
      r4->bufferInfo.availableSpace = r4->bufferInfo.optimalThreshold - r1;
      r4->bufferInfo.fillLevel = r1;
   }

   return res;
}


/* 21c4e14c - complete */
int32_t fapi_videc_0getvesfilllevel
              (FAPI_SYS_HandleT handle, uint32_t* fillLevel)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      res = FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   else if (h->isrDataPtr->startStopState == FAPI_VIDEC_STARTED)
   {
      res = fapi_videc_update_buffer_info(h->isrDataPtr);
      
      *fillLevel = h->isrDataPtr->bufferInfo.fillLevel;
   }
   else
   {
      *fillLevel = 0;
      res = FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_RUNNING;
   }
   
   return res;
}


/* 21c4e0f4 - complete */
int32_t fapi_videc_0getvesavailablespace
               (FAPI_SYS_HandleT handle, uint32_t* availableSpace)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      res = FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   else if (h->isrDataPtr->startStopState == FAPI_VIDEC_STARTED)
   {
      res = fapi_videc_update_buffer_info(h->isrDataPtr);
      
      *availableSpace = h->isrDataPtr->bufferInfo.availableSpace;
   }
   else
   {
      *availableSpace = 0;
      res = FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_RUNNING;
   }
   
   return res;
}


/* 21c47494 - complete */
int32_t fapi_videc_0gethealth(FAPI_SYS_HandleT handle,
                  FAPI_VIDEC_HealthStateEnumT* health)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   else
   {
      *health = h->isrDataPtr->healthState;
   }
   
   return res;
}


/* 21c474b8 - complete */
int32_t fapi_videc_0getdecodinglatency(FAPI_SYS_HandleT handle,
                  int64_t* decoderLatencyInTicks)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   else
   {
      *decoderLatencyInTicks = 
         h->isrDataPtr->vesInfo.vesDecoderLatency * 300;      
   }
   
   return res;
}


/* 21c4d6d4 - todo */
void fapi_videc_0audcallback(uint32_t audNum, uint32_t audSearchPattern,
                             uint32_t foundPtr, FAPI_SYS_HandleT handle)
{

}


/* 21c4ca90 - todo */
int32_t fapi_videc_0recover(FAPI_SYS_HandleT handle)
{
   return 0;
}


/* 21c491c4 - todo */
int32_t fapi_videc_0decodesequenceofmpegiframe(FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes)
{
   return 0;
}


/* 21c474fc - todo */
int32_t fapi_videc_0displaysequenceofmpegiframe(FAPI_SYS_HandleT handle)
{
   return 0;
}


/* 21c47518 - complete */
int32_t fapi_videc_0setentropydecinfocallback(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_EntropyDecInfoCallbackT entropyDecInfoCallbackFunction,
             void* entropyOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (entropyDecInfoCallbackFunction == 0)
   {      
      h->isrDataPtr->entropyDecInfoCbk = 0;
      h->isrDataPtr->entropyOptData = 0;
   }
   else
   {
      if (h->isrDataPtr->entropyDecInfoCbk == 0)
      {
         h->isrDataPtr->entropyDecInfoCbk = entropyDecInfoCallbackFunction;
         h->isrDataPtr->entropyOptData = entropyOptData;
      }
      else
      {
         res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
      }
   }
   
   return res;
}


/* 21c47570 - complete */
int32_t fapi_videc_0setvideodecinfocallback(FAPI_SYS_HandleT handle,
                 FAPI_VIDEC_VideoDecInfoCallbackT videoDecInfoCallbackFunction,
                 void* videoOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (videoDecInfoCallbackFunction == 0)
   {      
      h->isrDataPtr->videoDecInfoCbk = 0;
      h->isrDataPtr->videoOptData = 0;
   }
   else
   {
      if (h->isrDataPtr->videoDecInfoCbk == 0)
      {
         h->isrDataPtr->videoDecInfoCbk = videoDecInfoCallbackFunction;
         h->isrDataPtr->videoOptData = videoOptData;
      }
      else
      {
         res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
      }
   }
   
   return res;
}


/* 21c478ec - todo */
int32_t fapi_videc_0setpesparsertodecoder(FAPI_SYS_HandleT handle,
                                       FAPI_VIDEC_PesParserEnumT pesParserNum)
{
   return 0;
}


/* 21c47a28 - complete */
int32_t fapi_videc_0setframedecodedcallback(FAPI_SYS_HandleT handle,
                 FAPI_VIDEC_FrameDecodedCallbackT frameDecodedCallbackFunction,
                 void* frameDecodedOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (frameDecodedCallbackFunction == 0)
   {      
      h->isrDataPtr->frameDecodedCbk = 0;
      h->isrDataPtr->frameDecodedOptData = 0;
   }
   else
   {
      if (h->isrDataPtr->frameDecodedCbk == 0)
      {
         h->isrDataPtr->frameDecodedCbk = frameDecodedCallbackFunction;
         h->isrDataPtr->frameDecodedOptData = frameDecodedOptData;
      }
      else
      {
         res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
      }
   }
   
   return res;
}


/* 21c47a80 - complete */
int32_t fapi_videc_0setframeavailablecallback(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_FrameAvailableCallbackT frameAvailableCallbackFunction,
             void* frameAvailableOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (frameAvailableCallbackFunction == 0)
   {      
      h->isrDataPtr->frameAvailableCbk = 0;
      h->isrDataPtr->frameAvailableOptData = 0;
   }
   else
   {
      if (h->isrDataPtr->frameAvailableCbk == 0)
      {
         h->isrDataPtr->frameAvailableCbk = frameAvailableCallbackFunction;
         h->isrDataPtr->frameAvailableOptData = frameAvailableOptData;
      }
      else
      {
         res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
      }
   }
   
   return res;
}


/* 21c47ad8 - complete */
int32_t fapi_videc_0setvesoverflowcallback(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_VesOverflowCallbackT vesOverflowCallbackFunction,
             void* vesOverflowOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (vesOverflowCallbackFunction == 0)
   {      
      h->isrDataPtr->vesOverflowCbk = 0;
      h->isrDataPtr->vesOverflowOptData = 0;
   }
   else
   {
      if (h->isrDataPtr->vesOverflowCbk == 0)
      {
         h->isrDataPtr->vesOverflowCbk = vesOverflowCallbackFunction;
         h->isrDataPtr->vesOverflowOptData = vesOverflowOptData;
      }
      else
      {
         res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
      }
   }
   
   return res;
}


/* 21c47c10 - complete */
int32_t fapi_videc_0setafdstate(FAPI_SYS_HandleT handle,
                  FAPI_VIDEC_AfdStateEnumT afdState)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if ((afdState == FAPI_VIDEC_AFD_ENABLE_2) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_3) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_4) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_8) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_9) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_10) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_11) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_13) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_14) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_15) ||
         (afdState == FAPI_VIDEC_AFD_ENABLE_AUTO) ||
         (afdState == FAPI_VIDEC_AFD_DISABLE))
   {
      h->isrDataPtr->decoderAfdState = afdState;
   }
   else
   {
      res = FAPI_VIDEC_ERR_INVALID_ARGUEMENT_LIST;
   }
   
   return res;
}


/* 21c47c6c - complete */
int32_t func_21c47c6c(FAPI_SYS_HandleT handle, int32_t a)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if ((h->isrDataPtr->decoderType == FAPI_VIDEC_MPEG2_MPHL) ||
         (h->isrDataPtr->decoderType == FAPI_VIDEC_H264_HP41))
   {
      h->isrDataPtr->Data_705284 = a * (uint64_t)90;
   }
   else
   {
      res = FAPI_VIDEC_ERR_INVALID_ARGUEMENT_LIST;
   }
   
   return res;
}


/* 21c43520 - complete */
uint32_t checkHandle(FAPI_VIDEC_VideoDecoderHandleT* handlePtr)
{
//   FAPI_SYS_PRINT_MSG("checkHandle\n");
   
   if ((handlePtr != 0) &&
      (handlePtr->inUse == 1) &&
      (handlePtr->coreID == FAPI_VIDEC_ID) &&
      (handlePtr->baseAddress != 0) &&
      (handlePtr->opParams.decoderNumber != FAPI_VIDEC_UNKNOWN_DECODER_NUMBER) &&
      (handlePtr->opParams.decoderType != FAPI_VIDEC_UNKNOWN_DECODER) &&
      (handlePtr->opParams.decoderDelimiterType != FAPI_VIDEC_UNKNOWN_DELIMITER) &&
      (handlePtr->isrDataPtr != 0))
   {
      return 1;
   }
  
   return 0;
}


static int32_t videcDriverLoadFirmwares(void)
{
    int32_t err_code = FAPI_OK;
    uint32_t version = 0;
    uint32_t address = 0;
    FAPI_SYS_HandleT handle = 0;
    FAPI_BOOT_OpenParamsT params;
    FAPI_BOOT_ImageHeaderT header;

    params.version = FAPI_BOOT_VERSION;
    // Get the firmwares from Boot driver.
    handle = FAPI_BOOT_Open(&params, &err_code);

    // Get the MPEG Firmwares.
    if(err_code == FAPI_OK){
        memset(&header, 0, sizeof(header));
        version = RELEASE_VIDEC_MPEG_0_VERSION;
        err_code = FAPI_BOOT_GetImageInfoByVersion(handle, version, &header);
        if(err_code == FAPI_OK){
            address = (uint32_t)(void*)fvm0d;
            err_code = FAPI_BOOT_LoadImageByVersion(handle, version, address);
            if(err_code == FAPI_OK){
                fvm0sz = header.imageSize * sizeof(uint32_t);
                fvm0la = header.loadAddress;
            }
        }
    }
    if(err_code == FAPI_OK){
        memset(&header, 0, sizeof(header));
        version = RELEASE_VIDEC_MPEG_1_VERSION;
        err_code = FAPI_BOOT_GetImageInfoByVersion(handle, version, &header);
        if(err_code == FAPI_OK){
            address = (uint32_t)(void*)fvm1d;
            err_code = FAPI_BOOT_LoadImageByVersion(handle, version, address);
            if(err_code == FAPI_OK){
                fvm1sz = header.imageSize * sizeof(uint32_t);
                fvm1la = header.loadAddress;
            }
        }
    }
    if(err_code == FAPI_OK){
        memset(&header, 0, sizeof(header));
        version = RELEASE_VIDEC_MPEG_2_VERSION;
        err_code = FAPI_BOOT_GetImageInfoByVersion(handle, version, &header);
        if(err_code == FAPI_OK){
            address = (uint32_t)(void*)fvm2d;
            err_code = FAPI_BOOT_LoadImageByVersion(handle, version, address);
            if(err_code == FAPI_OK){
                fvm2sz = header.imageSize * sizeof(uint32_t);
                fvm2la = header.loadAddress;
            }
        }
    }

    // Get the H264 Firmwares.
    if(err_code == FAPI_OK){
        memset(&header, 0, sizeof(header));
        version = RELEASE_VIDEC_H264_0_VERSION;
        err_code = FAPI_BOOT_GetImageInfoByVersion(handle, version, &header);
        if(err_code == FAPI_OK){
            address = (uint32_t)(void*)fvh0d;
            err_code = FAPI_BOOT_LoadImageByVersion(handle, version, address);
            if(err_code == FAPI_OK){
                fvh0sz = header.imageSize * sizeof(uint32_t);
                fvh0la = header.loadAddress;
            }
        }
    }
    if(err_code == FAPI_OK){
        memset(&header, 0, sizeof(header));
        version = RELEASE_VIDEC_H264_1_VERSION;
        err_code = FAPI_BOOT_GetImageInfoByVersion(handle, version, &header);
        if(err_code == FAPI_OK){
            address = (uint32_t)(void*)fvh1d;
            err_code = FAPI_BOOT_LoadImageByVersion(handle, version, address);
            if(err_code == FAPI_OK){
                fvh1sz = header.imageSize * sizeof(uint32_t);
                fvh1la = header.loadAddress;
            }
        }
    }
    if(err_code == FAPI_OK){
        memset(&header, 0, sizeof(header));
        version = RELEASE_VIDEC_H264_2_VERSION;
        err_code = FAPI_BOOT_GetImageInfoByVersion(handle, version, &header);
        if(err_code == FAPI_OK){
            address = (uint32_t)(void*)fvh2d;
            err_code = FAPI_BOOT_LoadImageByVersion(handle, version, address);
            if(err_code == FAPI_OK){
                fvh2sz = header.imageSize * sizeof(uint32_t);
                fvh2la = header.loadAddress;
            }
        }
    }
    // Close the boot driver.
    (void)FAPI_BOOT_Close(handle);
    return(err_code);
}

