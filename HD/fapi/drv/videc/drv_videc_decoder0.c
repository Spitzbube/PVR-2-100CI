

#define DEBUG 0

#include <fapi/sys_services.h>
#include <fapi/reg_vd.h>
#include <fapi/reg_vd_ext.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_viscale_priv.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>
#include <fapi/drv_videc.h>
#include <fapi/drv_videc_priv.h>


int32_t fapi_videc_wait_enable_disable(FAPI_VIDEC_VideoDecoderHandleT*);
int32_t fapi_videc_wait_start(FAPI_VIDEC_VideoDecoderHandleT*);
void fapi_videc_clear_aud_info_data(FAPI_VIDEC_VideoDecoderIsrDataT*);
void fapi_videc_clear_entropy_decoding_data(FAPI_VIDEC_VideoDecoderIsrDataT*);
void fapi_videc_clear_video_decoding_data(FAPI_VIDEC_VideoDecoderIsrDataT*);



/* 21c47300 - complete */
int32_t fapi_videc_0setplaybackenvironment(FAPI_SYS_HandleT handle,
                                     FAPI_VIDEC_PlaybackEnvironmentEnumT mode)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }

   h->isrDataPtr->pecrInfo.targetPlaybackEnvironment = mode; //Data_705192 = mode;
   h->isrDataPtr->pecrInfo.playbackEnvironmentChangeReqState = FAPI_VIDEC_REQUEST_TO_SET_DECODER_PLAYBACK_ENVIRONMENT; //Data_705184 = 1;

   return res;
}


/* 21c47284 - todo */
int32_t fapi_videc_0setplaybackmode(FAPI_SYS_HandleT handle,
                                    FAPI_VIDEC_PlaybackModeEnumT mode)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      res = FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   else if (mode == FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE)
   {
      res = FAPI_VIDEC_ERR_BAD_PARAMETER;
   }
   else if ((h->isrDataPtr->decoderPlaybackEnvironment == FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT) &&
         (mode == FAPI_VIDEC_PLAYBACK_PAUSE))
   {
      res = FAPI_VIDEC_ERR_UNSUPPORTED_FUNCTIONALITY;
   }   
   else
   {
      FAPI_VIDEC_PlaybackModeChangeRequestEnumT request =
         FAPI_VIDEC_REQUEST_TO_SET_DECODER_PLAYBACK_MODE;

      if ((h->isrDataPtr->decoderType == FAPI_VIDEC_H264_HP41) &&
         (mode == FAPI_VIDEC_I_AND_P_ONLY_PLAYBACK_MODE))
      {
         res = FAPI_VIDEC_ERR_UNSUPPORTED_FUNCTIONALITY;
      }
      else
      {
         h->isrDataPtr->pmcrInfo.targetPlaybackMode = mode; //705204
         h->isrDataPtr->pmcrInfo.playbackModeChangeReqState = request; //705196
      }
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0setplaybackmode: res=%d\n", res);

   return res;
}


/* 21c47334 - complete */
int32_t fapi_videc_0getvesbufferposition
                                (FAPI_SYS_HandleT handle, uint32_t* bufferPtr)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   
   if (h->isrDataPtr->Data_128 == 0)
   {
      *bufferPtr = 0;

      res = FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_VIRTUAL_ADDRESS_UNAVAILABLE;
   }
   else
   {
      *bufferPtr = h->isrDataPtr->Data_128; 
   }
   
   return res;
}


/* 21c4736c - complete */
int32_t fapi_videc_0getvesbuffersize
                               (FAPI_SYS_HandleT handle, uint32_t* bufferSize)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED;
   }
   else
   {
      *bufferSize = h->isrDataPtr->bufferInfo.size;
   }
   
   return res;
}


/* 21c49d64 - todo */
int32_t fapi_videc_0decodesinglempegiframe(FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes)
{
   FAPI_VIDEC_VideoDecoderIsrDataT* r7_;
   unsigned r7;
   unsigned i;
   volatile int32_t* p;
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_0decodesinglempegiframe\n");
   
   if (h->isrDataPtr->bootState != FAPI_VIDEC_BOOTED)
   {
      return FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED; //-28126;
   }
   
   if (h->opParams.decoderType != FAPI_VIDEC_MPEG2_MPHL) //1)
   {
      return FAPI_VIDEC_ERR_UNSUPPORTED_FUNCTIONALITY;
   }
   
   if (h->isrDataPtr->mpegIFrameState == FAPI_VIDEC_NON_MPEG_IFRAME_STATE) //0)
   {
      return FAPI_VIDEC_ERR_VIDEO_WRONG_MODE; //-28137;
   }
   
   if (h->isrDataPtr->bufferInfo.size < sizeInBytes)
   {
      return FAPI_VIDEC_ERR_MPEG_IFRAME_EXCEEDS_ES_BUFF; //-28122;
   }
   
   if ((dataPtr[0] != 0x000001b3) &&
         (dataPtr[0] != 0xb3010000))
   {
      return FAPI_VIDEC_ERR_MPEG_IFRAME_WITH_WRONG_HEADER; //-28123;
   }

   h->isrDataPtr->enableDisableState = FAPI_VIDEC_REQUEST_TO_FORCE_DISABLE; //5;
   
   fapi_videc_wait_enable_disable(h);
   
   r7 = sizeInBytes / 4;
   
   if (dataPtr[0] == 0x000001b3)
   {
      //21c49fb0
      volatile uint32_t* ip = dataPtr;
      for (i = 0; i < r7; i++)
      {
         uint32_t r1 = *ip++;
#if 0
         ((uint32_t*)(h->isrDataPtr->physicalMemoryInfoPtr->videoStreamAreaStartAddress))[i] = 
            (r1 >> 24) | 
            ((r1 & 0xff0000) >> 8) |
            ((r1 & 0xff00) << 8) |
            (r1 << 24);         
#else
         ((uint32_t*)(h->isrDataPtr->physicalMemoryInfoPtr->videoStreamAreaStartAddress))[i] = 
            (r1 >> 24) | 
            ((r1 & 0xff0000) >> 8) |
            ((r1 & 0xff00) << 8) |
            (r1 << 24);         
#endif
      }
   }
   else if (dataPtr[0] == 0xb3010000)
   {
      //21c49ffc
      volatile uint32_t* ip = dataPtr;
      for (i = 0; i < r7; i++)
      {
         ((uint32_t*)(h->isrDataPtr->physicalMemoryInfoPtr->videoStreamAreaStartAddress))[i] = 
            *ip++;
      }
   }
   //21c49e08
   h->isrDataPtr->Data_192 = -1;
   h->isrDataPtr->mpegIFrameState = FAPI_VIDEC_MPEG_IFRAME_LOADED_IN_ES; //2;
   h->isrDataPtr->startStopState = FAPI_VIDEC_PREPARE_TO_START; //4;
   
   FREG_VD_SetIntReqToPcpu(MAINCPU_CMD_DECODE_START); //0x1000000);
   
   h->isrDataPtr->startStopState = FAPI_VIDEC_REQUEST_TO_START; //5;

   res = fapi_videc_wait_start(h);
   
   r7_ = h->isrDataPtr;
   p = r7_->physicalMemoryInfoPtr->vcpbInfoTableStartAddress;
   
   FREG_VD_Write32((FREG_VD_Read32(/*0x60048180*/VCPB_DEC_REQ_IDX_FIFO_WRITE_POS_ADDR_0) << 2) + /*0x60048000*/VCPB_DEC_REQ_IDX_FIFO_START_ADDR_0, 0);
   
   p[0] = 0;
   p[1] = 2;
   p[2] = 0;
   p[3] = 0;
   p[4] = 0;
   p[5] = sizeInBytes;
   p[6] = 0;
   p[7] = 0;
   p[8] = 0;
   p[9] = 0;
   p[10] = 0;
   p[11] = 0;
   p[12] = 0;
   p[13] = 0;
   p[14] = 0;
   p[15] = 0;
   p[16] = 0;
   p[17] = 0;
   p[18] = 0;
   p[19] = 0;
   p[20] = 0;
   p[21] = 0;
   p[22] = 0;
   p[23] = 0;
   
   FREG_VD_Write32(/*0x60048180*/VCPB_DEC_REQ_IDX_FIFO_WRITE_POS_ADDR_0, 1);
   
   FREG_VD_SetIntReqToPcpu(MAINCPU_MESSAGE_VCPB_INFO_UPDATE);
   
   p = r7_->physicalMemoryInfoPtr->vcpbInfoTableStartAddress;
   
   FREG_VD_Write32((FREG_VD_Read32(/*0x60048180*/VCPB_DEC_REQ_IDX_FIFO_WRITE_POS_ADDR_0) << 2) + /*0x60048000*/VCPB_DEC_REQ_IDX_FIFO_START_ADDR_0, 0);

   p[24] = 0;
   p[25] = 2;
   p[26] = 1;
   p[27] = 0;
   p[28] = 0;
   p[29] = sizeInBytes;
   p[30] = 0;
   p[31] = 0;
   p[32] = 0;
   p[33] = 0;
   p[34] = 0;
   p[35] = 0;
   p[36] = 0;
   p[37] = 0;
   p[38] = 0;
   p[39] = 0;
   p[40] = 0;
   p[41] = 0;
   p[42] = 0;
   p[43] = 0;
   p[44] = 0;
   p[45] = 0;
   p[46] = 0;
   p[47] = 0;

   FREG_VD_Write32(/*0x60048180*/VCPB_DEC_REQ_IDX_FIFO_WRITE_POS_ADDR_0, 2);
   
   FREG_VD_SetIntReqToPcpu(MAINCPU_MESSAGE_VCPB_INFO_UPDATE);

   h->isrDataPtr->mpegIFrameState = FAPI_VIDEC_MPEG_IFRAME_DECODED;
   h->isrDataPtr->frameCrop.mpegIFrameState = FAPI_VIDEC_MPEG_IFRAME_DECODED;
   
   FAPI_SYS_SLEEP(40);

   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0decodesinglempegiframe: res=%d\n", res);

   return res;
}


/* 21c495ec - nearly complete */
int32_t fapi_videc_0displaysinglempegiframe(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_0displaysinglempegiframe\n");

   if (h->isrDataPtr->mpegIFrameState == FAPI_VIDEC_MPEG_IFRAME_DECODED)
   {
      //21c49604
      h->isrDataPtr->enableDisableState = FAPI_VIDEC_REQUEST_TO_FORCE_ENABLE;

      fapi_videc_wait_enable_disable(h);

      FAPI_VIDEC_VideoDecoderIsrDataT* r4 = h->isrDataPtr;

      r4->mpegIFrameState = FAPI_VIDEC_MPEG_IFRAME_ON_DISPLAY;
      r4->frameState = FAPI_VIDEC_FRAME_DISPLAY_START;
      r4->frameCrop.mpegIFrameState = FAPI_VIDEC_MPEG_IFRAME_ON_DISPLAY;

      uint32_t r7 = FREG_VD_Read32(0x600485c0);

      FREG_VD_Write32(0x60048500 + (r7 << 2),
            r4->frameInfo.decodedPic[r4->frameInfo.rPtr].displayFrameBank);

      r4->vdpbDecodedFramesAvailable--;

      r4->Data_705404 =
            r4->frameInfo.decodedPic[r4->frameInfo.rPtr].vdpbDispCount;

      r4->frameState = FAPI_VIDEC_FRAME_FREED; 
      r4->frameInfo.decodedPic[r4->frameInfo.rPtr].state = FAPI_VIDEC_FRAME_FREED;

      if (r7 > 46)
      {
         r7 = 0;
      }
      else
      {
         r7++;
      }

      FREG_VD_Write32(0x600485c0, r7);

      FREG_VD_SetIntReqToPcpu(MAINCPU_MESSAGE_VDPB_FREE_UPDATE);

      h->isrDataPtr->currIsrTimeUsec = 0;
      h->isrDataPtr->Data_12 = 0;
      h->isrDataPtr->currVcpbDecTimeMsec = 0;
      h->isrDataPtr->Data_28 = 0;

      h->isrDataPtr->Data_36 = 0;
      h->isrDataPtr->Data_44 = 0;
      h->isrDataPtr->Data_52 = 0;
      h->isrDataPtr->Data_60 = 0;

      h->isrDataPtr->isrMask = 0;
      h->isrDataPtr->isrStatus = 0;
      h->isrDataPtr->isrSerialIdx = 0;
      h->isrDataPtr->isrCurrField = 0;
      h->isrDataPtr->isrNextField = 1;

      h->isrDataPtr->bufferInfo.fillLevel = 0;
      h->isrDataPtr->bufferInfo.availableSpace = h->decoderBufferSize >> 1;

      h->isrDataPtr->startStopState = FAPI_VIDEC_STOPPED;
      h->isrDataPtr->healthState = FAPI_VIDEC_GOOD_HEALTH;
      h->isrDataPtr->Data_192 = -1;
      h->isrDataPtr->Data_196 = 0;
      h->isrDataPtr->Data_204 = 0;

      h->isrDataPtr->vesInfo.vesAverageBitRate = 0;
      h->isrDataPtr->vesInfo.vesCurrBitRate = 0;
      h->isrDataPtr->vesInfo.vesAspectRatio = 0;
      h->isrDataPtr->vesInfo.vesFrameRate = 0;
      h->isrDataPtr->vesInfo.proggInter = -1;
      h->isrDataPtr->vesInfo.displayWidth = 0;
      h->isrDataPtr->vesInfo.displayHeight = 0;
      h->isrDataPtr->vesInfo.decodedWidth = 0;
      h->isrDataPtr->vesInfo.decodedHeight = 0;

      h->isrDataPtr->audLastPts = 0;
      h->isrDataPtr->audIdx = 0;

      h->isrDataPtr->vcpbAddress = 0;
      h->isrDataPtr->vcpbLength = 0;
      h->isrDataPtr->vcpbLoadIdx = 0;
      h->isrDataPtr->vcpbIdx = 0;

      h->isrDataPtr->oodSerialNum = 0;
      h->isrDataPtr->oodEntropyDecodedAudIdx = 0;
      h->isrDataPtr->oodIdx = 0;

      h->isrDataPtr->vdpbDecodedFramesAvailable = 0;
      h->isrDataPtr->vdpbSerialNum = 0;
      h->isrDataPtr->Data_705104 = 0;
      h->isrDataPtr->vdpbIdx = 0;

#if 0
      h->isrDataPtr->lkgFrameCrop.aspectRatio = 0;
      h->isrDataPtr->lkgFrameCrop.frameField = -1;
#endif
      h->isrDataPtr->lkgFrameCrop.x0 = 0; //705132
      h->isrDataPtr->lkgFrameCrop.x0 = 0; //705136
      h->isrDataPtr->lkgFrameCrop.displayWidth = 0; //705140
      h->isrDataPtr->lkgFrameCrop.displayWidth = 0; //705144
      h->isrDataPtr->lkgFrameCrop.decodedWidth = 0; //705148
      h->isrDataPtr->lkgFrameCrop.decodedHeight = 0; //705152
      h->isrDataPtr->lkgFrameCrop.topFieldSerialNo = 0; //705156
      h->isrDataPtr->lkgFrameCrop.botFieldSerialNo = 0; //705160
      h->isrDataPtr->lkgFrameCrop.currAfd = 0; //705164
      h->isrDataPtr->lkgFrameCrop.frameIdx = 0; //705180

      h->isrDataPtr->Data_705268 = 0;
      h->isrDataPtr->Data_705276 = 0;
      
      h->isrDataPtr->frameFieldState = FAPI_VIDEC_NO_FIELD_FREEZE_STATE;
      h->isrDataPtr->frameStartDisplay = 0;
      h->isrDataPtr->frameState = FAPI_VIDEC_UNKNOWN_FRAME_STATE;
      h->isrDataPtr->frameBank = 0;

      h->isrDataPtr->frameCrop.aspectRatio = 0; //705308
      h->isrDataPtr->frameCrop.frameField = -1; //705320
      h->isrDataPtr->frameCrop.x0 = 0; //705328
      h->isrDataPtr->frameCrop.y0 = 0; //705332
      h->isrDataPtr->frameCrop.displayWidth = 0; //705336
      h->isrDataPtr->frameCrop.displayHeight = 0; //705340
      h->isrDataPtr->frameCrop.decodedWidth = 0; //705344
      h->isrDataPtr->frameCrop.decodedHeight = 0; //705348
      h->isrDataPtr->frameCrop.topFieldSerialNo = 0; //705352
      h->isrDataPtr->frameCrop.botFieldSerialNo = 0; //705356
      h->isrDataPtr->frameCrop.currAfd = 0; //705360
      h->isrDataPtr->frameCrop.codedInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP; //705364
      h->isrDataPtr->frameCrop.readoutInterlaceProggState = FAPI_VIDEC_UNKNOWN_IP; //705368
      h->isrDataPtr->frameCrop.frameIdx = 0; //705376

      h->isrDataPtr->frameDisplayOrderInfo = 0; //705380
      h->isrDataPtr->frameTopFieldNo = 0; //705384
      h->isrDataPtr->frameBotFieldNo = 0; //705388
      h->isrDataPtr->frameSerialNum = 0; //705392
      h->isrDataPtr->frameIdx = 0; //705396
      h->isrDataPtr->frameDecError = 0; //705400
      
      h->isrDataPtr->Data_705404 = 0; //705404
      
      h->isrDataPtr->invokeAutoScalers = 0; //705408
      
      fapi_videc_clear_aud_info_data(h->isrDataPtr);
      fapi_videc_clear_entropy_decoding_data(h->isrDataPtr);
      fapi_videc_clear_video_decoding_data(h->isrDataPtr);
   }
   else if (h->isrDataPtr->mpegIFrameState != FAPI_VIDEC_MPEG_IFRAME_ON_DISPLAY)
   {
      res = FAPI_VIDEC_ERR_MPEG_IFRAME_NO_DECODED_FRAME_AVAILABLE;
   }
   else if (h->isrDataPtr->frameState != FAPI_VIDEC_FRAME_DISPLAY_START)
   {
      res = FAPI_VIDEC_ERR_MPEG_IFRAME_NO_DECODED_FRAME_AVAILABLE;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0displaysinglempegiframe: res=%d\n", res);

   return res;
}


/* 21c475c8 - complete */
int32_t fapi_videc_0setautoscalecallback(FAPI_SYS_HandleT handle,
                       FAPI_VIDEC_AutoScaleCallbackT autoScaleCallbackFunction,
                       void* scalerHandle)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_0setautoscalecallback\n");
   
   if (autoScaleCallbackFunction != 0)
   {
      FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0setautoscalecallback: scalerHandle->opParams.scalerType=%d\n", 
            ((FAPI_VISCALE_VideoScalerHandleT*)scalerHandle)->opParams.scalerType);

      if (((FAPI_VISCALE_VideoScalerHandleT*)scalerHandle)->opParams.scalerType == 
         FAPI_VISCALE_SCALER_VIDEO)
      {
         if (h->isrDataPtr->hdAutoScaleCbk == 0)
         {
            h->isrDataPtr->hdAutoScaleCbk = 
               autoScaleCallbackFunction;
            h->isrDataPtr->hdScalerHandle = scalerHandle;
         }
         else
         {
            res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
         }
      }
      else if (((FAPI_VISCALE_VideoScalerHandleT*)scalerHandle)->opParams.scalerType == 
         FAPI_VISCALE_SCALER_SD)
      {
         if (h->isrDataPtr->sdAutoScaleCbk == 0)
         {
            h->isrDataPtr->sdAutoScaleCbk = 
               autoScaleCallbackFunction;
            h->isrDataPtr->sdScalerHandle = scalerHandle;
         }
         else
         {
            res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
         }
      }
      else
      {
         res = FAPI_VIDEC_ERR_UNSUPPORTED_FUNCTIONALITY; 
      }
   }
   else
   {   
      h->isrDataPtr->hdAutoScaleCbk = 0;
      h->isrDataPtr->hdScalerHandle = 0;
      
      h->isrDataPtr->sdAutoScaleCbk = 0;
      h->isrDataPtr->sdScalerHandle = 0;
   }
   
   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0setautoscalecallback: res=%d\n", res);

   return res;
}


/* 21c47680 - complete */
int32_t fapi_videc_0setdecodertohdencoder(FAPI_SYS_HandleT handle,
                                               FAPI_SYS_HandleT viencHdHandle)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_0setdecodertohdencoder\n");
   
   if (viencHdHandle != 0)
   {
      FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0setdecodertohdencoder: viencHdHandle->opParams.interlaceProgressive=%d\n",
            ((FAPI_VIENC_VideoEncoderHandleT*)viencHdHandle)->opParams.interlaceProgressive);

      switch (((FAPI_VIENC_VideoEncoderHandleT*)viencHdHandle)->opParams.interlaceProgressive)
      {
      case 3:
         //21c478d4
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x2397P; //1;         
         break;
         
      case 4:
         //21c478c0
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x24P; //2;         
         break;
         
      case 5:
         //21c478ac
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x25P; //3;         
         break;
         
      case 6:
         //21c47898
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x2997P; //4;         
         break;
         
      case 7:
         //21c47884
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x30P; //5;         
         break;
         
      case 8:
         //21c47870
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x50I; //6;         
         break;
         
      case 9:
         //21c4785c
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x5994I; //7;         
         break;
         
      case 10:
         //21c47848
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1920x1080x60I; //8;         
         break;
         
      case 11:
         //21c47834
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x2397P; //9;         
         break;
         
      case 12:
         //21c47820
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x24P; //10;         
         break;
         
      case 13:
         //21c4780c
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x25P; //11;         
         break;
         
      case 14:
         //21c477f8
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x2997P; //12;         
         break;
         
      case 15:
         //21c477e4
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x30P; //13;         
         break;
         
      case 16:
         //21c477d0
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x50P; //14;         
         break;
         
      case 17:
         //21c477bc
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x5994P; //15;         
         break;
         
      case 18:
         //21c477a8
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_1280x720x60P; //16;         
         break;

      case 19:
         //21c47794
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_720x576x50I; //17;         
         break;

      case 20:
         //21c47780
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_720x576x50P; //18;         
         break;

      case 21:
         //21c4776c
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_720x480x5994I; //19;
         break;

      case 22:
         //21c47758
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_720x480x5994P; //20;         
         break;

      case 23:
         //21c47744
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_LCD_640x480x50P_LQ080V3DG01; //21;         
         break;

      case 24:
         //21c47730
         h->decoderDisplayMode = FAPI_VIDEC_DISPLAY_MODE_LCD_1024x768x50P_SVA150XG10TB; //22;         
         break;

      default:
         //21c4770c
         res = FAPI_VIDEC_ERR_INVALID_INITIALIZATION_PARAMS;
         
         h->decoderDisplayMode = FAPI_VIDEC_UNKNOWN_DISPLAY_MODE; //0;
         h->isrDataPtr->decoderDisplayMode = h->decoderDisplayMode;
         break;
      }
   }
   else
   {
      //21c476f4
      h->decoderDisplayMode = FAPI_VIDEC_UNKNOWN_DISPLAY_MODE; //0;
      h->isrDataPtr->decoderDisplayMode = h->decoderDisplayMode;
      return 0;
   }

   h->isrDataPtr->decoderDisplayMode = h->decoderDisplayMode;

   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0setdecodertohdencoder: res=%d\n", res);

   return res;
}


/* 21c47b30 - complete */
int32_t fapi_videc_0setmpegiframemode(FAPI_SYS_HandleT handle,
                   FAPI_VIDEC_MpegIFrameModeEnumT mode)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (mode == FAPI_VIDEC_NON_MPEG_IFRAME_MODE)
   {
      h->isrDataPtr->mpegIFrameState = 
         FAPI_VIDEC_NON_MPEG_IFRAME_STATE;
   }
   else
   {
      h->isrDataPtr->mpegIFrameState = 
         FAPI_VIDEC_MPEG_IFRAME_STATE;
   }
   
   return res;
}


/* 21c47b50 - complete */
int32_t fapi_videc_0setchannelid(FAPI_SYS_HandleT handle, 
               uint32_t blockIndex,
               uint32_t channelId)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_videc_0setchannelid\n");

   if ((blockIndex < 4) &&
         (channelId < 31))
   {
      h->isrDataPtr->channelInfo.blockIndex = blockIndex;
      h->isrDataPtr->channelInfo.channelId = channelId;
   }
   else if ((blockIndex == -1) ||
         (channelId == -1))
   {
      h->isrDataPtr->channelInfo.blockIndex = -1;
      h->isrDataPtr->channelInfo.channelId = -1;
   }
   else
   {
      h->isrDataPtr->channelInfo.blockIndex = -1;
      h->isrDataPtr->channelInfo.channelId = -1;

      res = FAPI_VIDEC_ERR_INVALID_ARGUEMENT_LIST;
   }

   FAPI_SYS_PRINT_DEBUG(3, "fapi_videc_0setchannelid: res=%d\n", res);

   return res;
}


/* 21c47bb8 - complete */
int32_t fapi_videc_0setparamchangecallback(FAPI_SYS_HandleT handle,
                   FAPI_VIDEC_ParamChangeCallbackT paramChangeCallbackFunction,
                   void* paramChangeOptData)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   if (paramChangeCallbackFunction == 0)
   {      
      h->isrDataPtr->paramChangeCbk = 0;
      h->isrDataPtr->paramChangeOptData = 0;
   }
   else
   {
      if (h->isrDataPtr->paramChangeCbk == 0)
      {
         h->isrDataPtr->paramChangeCbk = paramChangeCallbackFunction;
         h->isrDataPtr->paramChangeOptData = paramChangeOptData;
      }
      else
      {
         res = FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED;
      }
   }
   
   return res;
}


/* 21c47390 - complete */
int32_t fapi_videc_0getstate(FAPI_SYS_HandleT handle,
                             FAPI_VIDEC_GetStateT* getStatePtr)
{
   int32_t res = 0;
   FAPI_VIDEC_VideoDecoderHandleT* h = handle;

   getStatePtr->firmwareVersionInFlash = h->firmwareVersionInFlash;
   getStatePtr->firmwareVersionSupported = h->firmwareVersionSupported;
   getStatePtr->decoderType = h->isrDataPtr->decoderType;
   getStatePtr->decodeFrameBankSizeType = h->isrDataPtr->decodeFrameBankSizeType;
   getStatePtr->displayWidth = h->isrDataPtr->frameCrop.displayWidth; //705336;
   getStatePtr->displayHeight = h->isrDataPtr->frameCrop.displayHeight; //705340;
   getStatePtr->decodedWidth = h->isrDataPtr->frameCrop.decodedWidth; //705344;
   getStatePtr->decodedHeight = h->isrDataPtr->frameCrop.decodedHeight; //705348;
   getStatePtr->aspectRatio = h->isrDataPtr->frameCrop.aspectRatio; //705308;
   getStatePtr->activeAspectRatioL0 = h->isrDataPtr->frameCrop.activeAspectRatioL0; //705312
   getStatePtr->activeAspectRatioL1 = h->isrDataPtr->frameCrop.activeAspectRatioL1; //705316;
   getStatePtr->currAfd = h->isrDataPtr->frameCrop.currAfd; //705360;
   getStatePtr->codedInterlaceProggState = h->isrDataPtr->frameCrop.codedInterlaceProggState; //705364;
   getStatePtr->readoutInterlaceProggState = h->isrDataPtr->frameCrop.readoutInterlaceProggState; //705368;
   getStatePtr->vesAverageBitRate = h->isrDataPtr->vesInfo.vesAverageBitRate;
   getStatePtr->vesCurrBitRate = h->isrDataPtr->vesInfo.vesCurrBitRate;
   getStatePtr->vesFrameRate = h->isrDataPtr->vesInfo.vesFrameRate;
   getStatePtr->bootState = h->isrDataPtr->bootState;
   getStatePtr->resetState = h->isrDataPtr->resetState;
   getStatePtr->enableState = h->isrDataPtr->enableDisableState;
   getStatePtr->healthState = h->isrDataPtr->healthState;
   getStatePtr->startState = h->isrDataPtr->startStopState;
   getStatePtr->Data_92 = h->isrDataPtr->Data_196;
   getStatePtr->Data_96 = h->isrDataPtr->Data_200;

   return res;
}


