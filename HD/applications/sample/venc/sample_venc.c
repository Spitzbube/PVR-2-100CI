/******************************************************************************
** \file        adi/test/src/video.c
**
** \brief       ADI layer video(video input/output encode) test.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS
**
** (C) Copyright 2013-2014 by GOKE MICROELECTRONICS CO.,LTD
**
*****************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "adi_types.h"
#include "adi_sys.h"
#include "adi_vi.h"
#include "adi_venc.h"
#include "adi_vout.h"
#include "adi_isp.h"


//*****************************************************************************
//*****************************************************************************
//** Local Defines
//*****************************************************************************
//*****************************************************************************
#define GK_VIDEO_MODE(W,H,F,PI) (((PI<<31)&0x80000000)|((F<<24)&0x3F000000)| \
    (((W/4)<<12)&0x00FFF000)|((H/2)&0x00000FFF))

#define VI_INPUT_WIDTH       1280
#define VI_INPUT_HEIGHT      720
#define VI_INPUT_FPS         25

#define VENC_STREAM1_WIDTH   1280
#define VENC_STREAM1_HEIGHT  720
#define VENC_STREAM2_WIDTH   720
#define VENC_STREAM2_HEIGHT  576
#define VENC_STREAM3_WIDTH   0
#define VENC_STREAM3_HEIGHT  0
#define VENC_STREAM4_WIDTH   VENC_STREAM1_WIDTH
#define VENC_STREAM4_HEIGHT  VENC_STREAM1_HEIGHT

#define TRUE  1
#define FALSE 0


//*****************************************************************************
//*****************************************************************************
//** Local structures
//*****************************************************************************
//*****************************************************************************
typedef struct
{
    GADI_VENC_StreamFormatT streamFormat;
    GADI_VENC_H264ConfigT   h264Conf;
    GADI_VENC_MjpegConfigT  mjpegConf;
}video_encode_stream;


//*****************************************************************************
//*****************************************************************************
//** Global Data
//*****************************************************************************
//*****************************************************************************


//*****************************************************************************
//*****************************************************************************
//** Local Data
//*****************************************************************************
//*****************************************************************************
static GADI_SYS_HandleT viHandle    = NULL;
static GADI_SYS_HandleT voHandle    = NULL;
static GADI_SYS_HandleT vencHandle  = NULL;
static GADI_SYS_HandleT ispHandle  = NULL;


static GADI_VI_SettingParamsT   viParams = {
    .resoluMode = GK_VIDEO_MODE(VI_INPUT_WIDTH, VI_INPUT_HEIGHT, VI_INPUT_FPS, 1),
    .frameRate  = VI_INPUT_FPS,
    .mirrorMode = {GADI_VI_MIRROR_NONE, GADI_VI_BAYER_PATTERN_RG},
};

static GADI_VOUT_SettingParamsT voParams = {
    .voutChannel = GADI_VOUT_B,
    .resoluMode  = GADI_VOUT_RESOLUTION_480I,
    .deviceType  = GADI_VOUT_DEVICE_DISABLE,
};


static GADI_VENC_StreamFormatT streamFormats[GADI_VENC_STREAM_NUM] = {
    {
        .streamId   = GADI_VENC_STREAM_FIRST,
        .encodeType = GADI_VENC_TYPE_H264,
        .channelId  = GADI_VENC_CHANNEL_1,
        .flipRotate = 0,
        .width      = VENC_STREAM1_WIDTH,
        .height     = VENC_STREAM1_HEIGHT,
        .xOffset    = 0,
        .yOffset    = 0,
        .fps        = VI_INPUT_FPS,
        .keepAspRat = 0,
    },
    {
        .streamId   = GADI_VENC_STREAM_SECOND,
        .encodeType = GADI_VENC_TYPE_H264,
        .channelId  = GADI_VENC_CHANNEL_2,
        .flipRotate = 0,
        .width      = VENC_STREAM2_WIDTH,
        .height     = VENC_STREAM2_HEIGHT,
        .xOffset    = 0,
        .yOffset    = 0,
        .fps        = VI_INPUT_FPS,
        .keepAspRat = 0,
    },
    {
        .streamId   = GADI_VENC_STREAM_THIRD,
        .encodeType = GADI_VENC_TYPE_OFF,
        .channelId  = GADI_VENC_CHANNEL_3,
        .flipRotate = 0,
        .width      = VENC_STREAM3_WIDTH,
        .height     = VENC_STREAM3_HEIGHT,
        .xOffset    = 0,
        .yOffset    = 0,
        .fps        = VI_INPUT_FPS,
        .keepAspRat = 0,
    },
    {
        .streamId   = GADI_VENC_STREAM_FORTH,
        .encodeType = GADI_VENC_TYPE_MJPEG,
        .channelId  = GADI_VENC_CHANNEL_1,
        .flipRotate = 0,
        .width      = VENC_STREAM4_WIDTH,
        .height     = VENC_STREAM4_HEIGHT,
        .xOffset    = 0,
        .yOffset    = 0,
        .fps        = GADI_VENC_FPS_3,
        .keepAspRat = 0,
    },
};

static GADI_VENC_H264ConfigT   h264Conf[GADI_VENC_STREAM_NUM] = {
    {
        .streamId    = GADI_VENC_STREAM_FIRST,
        .gopM        = 1,
        .gopN        = 50,
        .idrInterval = 1,
        .gopModel    = 0,
        .profile     = 0,//main profile
        .brcMode     = 0,//*0: CBR; 1: VBR
        .cbrAvgBps   = 4000000,
        .vbrMinbps   = 1000000,
        .vbrMaxbps   = 4000000,
        .adaptQp     = 2,
        .qpMinI      = 14,
        .qpMinP      = 17,
        .qpIWeight   = 2,
        .qpPWeight   = 4,
    },
    {
        .streamId    = GADI_VENC_STREAM_SECOND,
        .gopM        = 1,
        .gopN        = 50,
        .idrInterval = 1,
        .gopModel    = 0,
        .profile     = 0,//main profile
        .brcMode     = 0,//*0: CBR; 1: VBR
        .cbrAvgBps   = 2000000,
        .vbrMinbps   = 1000000,
        .vbrMaxbps   = 2000000,
        .adaptQp     = 2,
        .qpMinI      = 14,
        .qpMinP      = 17,
        .qpIWeight   = 2,
        .qpPWeight   = 4,
    },
    {
        .streamId    = GADI_VENC_STREAM_THIRD,
        .gopM        = 1,
        .gopN        = 50,
        .idrInterval = 1,
        .gopModel    = 0,
        .profile     = 0,//main profile
        .brcMode     = 0,//*0: CBR; 1: VBR
        .cbrAvgBps   = 4000000,
        .vbrMinbps   = 1000000,
        .vbrMaxbps   = 4000000,
        .adaptQp     = 3,
        .qpMinI      = 14,
        .qpMinP      = 17,
        .qpIWeight   = 2,
        .qpPWeight   = 4,
    },
    {
        .streamId    = GADI_VENC_STREAM_FORTH,
        .gopM        = 1,
        .gopN        = 50,
        .idrInterval = 1,
        .gopModel    = 0,
        .profile     = 0,//main profile
        .brcMode     = 0,//*0: CBR; 1: VBR
        .cbrAvgBps   = 4000000,
        .vbrMinbps   = 1000000,
        .vbrMaxbps   = 4000000,
        .adaptQp     = 3,
        .qpMinI      = 14,
        .qpMinP      = 17,
        .qpIWeight   = 2,
        .qpPWeight   = 4,
    },
};

static GADI_VENC_MjpegConfigT  mjpegConf[GADI_VENC_STREAM_NUM] = {
    {
        .streamId     = GADI_VENC_STREAM_FIRST,
        .chromaFormat = 1,//only support  YUV 420
        .quality      = 50,
    },
    {
        .streamId     = GADI_VENC_STREAM_SECOND,
        .chromaFormat = 1,//only support  YUV 420
        .quality      = 50,
    },
    {
        .streamId     = GADI_VENC_STREAM_THIRD,
        .chromaFormat = 1,//only support  YUV 420
        .quality      = 50,
    },
    {
        .streamId     = GADI_VENC_STREAM_FORTH,
        .chromaFormat = 1,//only support  YUV 420
        .quality      = 50,
    },
};

static GADI_VENC_ChannelsParamsT chansParams ={
    .chan1Type               = GADI_VENC_CHANNEL_TYPE_ENCODE,
    .chan1Width              = VENC_STREAM1_WIDTH,
    .chan1Height             = VENC_STREAM1_HEIGHT,
    .chan1DeintlcForIntlcVin = 0,
    .chan2Type               = GADI_VENC_CHANNEL_TYPE_ENCODE,
    .chan2Width              = VENC_STREAM2_WIDTH,
    .chan2Height             = VENC_STREAM2_HEIGHT,
    .chan2DeintlcForIntlcVin = 0,
    .chan3Type               = GADI_VENC_CHANNEL_TYPE_OFF,
    .chan3Width              = 0,
    .chan3Height             = 0,
    .chan3DeintlcForIntlcVin = 0,
    .chan4Type               = GADI_VENC_CHANNEL_TYPE_OFF,
    .chan4Width              = 0,
    .chan4Height             = 0,
    .chan4DeintlcForIntlcVin = 0,
    .intlcScan               = 0,
};

char record_file_name[1024];
unsigned char record_enable = FALSE;
unsigned char runing_enable = FALSE;


//*****************************************************************************
//*****************************************************************************
//** Local Functions Declaration
//*****************************************************************************
//*****************************************************************************
static int sample_init(void);
static int sample_exit(void);
static int sample_isp_init(void);
static int sample_isp_open(void);
static int sample_isp_start(void);
static int sample_isp_stop(void);
static int sample_isp_close(void);
static int sample_isp_exit(void);
static int sample_video_open(void);
static int sample_video_close(void);
static int sample_video_set_params(void);
static int sample_start_encode_streams(void);
static int sample_stop_encode_streams(void);
static void sample_kill_handle(int signo);
static void* sample_read_encode_streams(void *arg);

//*****************************************************************************
//*****************************************************************************
//** APP Functions
//*****************************************************************************
//*****************************************************************************
int main (int argc, char * argv[])
{
    pthread_attr_t  attr;
    pthread_t       videoThreadId;
    int retVal = GADI_OK;

    /*parpase app parameters.*/
    if(argc == 3)
    {
        if(strcmp("-r", argv[1]) == 0)
        {
            record_enable = TRUE;
            strcpy(record_file_name, argv[2]);
            printf("record file enable, file:%s\n", record_file_name);
        }
    }

    retVal = sample_init();
    if(retVal < 0){
        printf("sample_init failed.\n");
        return -1;
    }

    retVal = sample_video_open();
    if(retVal < 0){
        printf("sample_video_open failed.\n");
        return -1;
    }

    retVal = sample_isp_open();
    if(retVal < 0){
        printf("sample_isp_open failed.\n");
        return -1;
    }

    retVal = sample_video_set_params();
    if(retVal < 0){
        printf("sample_video_set_params failed.\n");
        return -1;
    }

    retVal = sample_isp_start();
    if(retVal < 0){
        printf("sample_isp_start failed.\n");
        return -1;
    }

    retVal = sample_start_encode_streams();
    if(retVal < 0){
        printf("sample_start_encode_streams failed.\n");
        return -1;
    }

    signal(SIGINT, sample_kill_handle);
    signal(SIGQUIT, sample_kill_handle);
    signal(SIGTERM, sample_kill_handle);

    runing_enable = TRUE;

    /*creat get bit stream thread.*/
    if (pthread_attr_init(&attr) < 0)
    {
        return -1;
    }

    retVal = pthread_create(&videoThreadId, NULL, sample_read_encode_streams, 0);
    if(retVal != 0){
        return -1;
    }
    if(videoThreadId != 0){
        pthread_join(videoThreadId,NULL);
    }

    return 0;
}



//*****************************************************************************
//*****************************************************************************
//** Local Functions
//*****************************************************************************
//*****************************************************************************
static int sample_init(void)
{
    int retVal = GADI_OK;

    /*system module init.*/
    retVal = gadi_sys_init();
    if(retVal != GADI_OK){
        printf("gadi_sys_init() failed!\n");
        return retVal;
    }

    /*load firmware.*/
    retVal = gadi_sys_load_firmware();
    if(retVal != GADI_OK){
        printf("gadi_sys_load_firmware() failed!\n");
        return retVal;
    }

    /*init vi module.*/
    retVal = gadi_vi_init();
    if(retVal != GADI_OK){
        printf("gadi_vi_init() failed!\n");
        return retVal;
    }

    /*init vi module.*/
    retVal = gadi_vout_init();
    if(retVal != GADI_OK){
        printf("gadi_vout_init() failed!\n");
        return retVal;
    }

    /*init vi module.*/
    retVal = gadi_venc_init();
    if(retVal != GADI_OK){
        printf("gadi_venc_init() failed!\n");
        return retVal;
    }

    /*init isp module.*/
    retVal = sample_isp_init();
    if(retVal != GADI_OK){
        return retVal;
    }

    return retVal;
}

static int sample_exit(void)
{
    int retVal = GADI_OK;

    retVal = gadi_vi_exit();
    retVal = gadi_vout_exit();
    retVal = gadi_venc_exit();
    retVal = gadi_sys_exit();
    retVal = sample_isp_exit();

    return retVal;
}

static int sample_isp_init(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_init();
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_init() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static int sample_isp_open(void)
{
    GADI_ERR                retVal = GADI_OK;
    GADI_ISP_OpenParamsT    openParams;

    openParams.denoiseMode = GADI_ISP_VPS_MERGE_MODE;

    ispHandle = gadi_isp_open(&openParams, &retVal);
    if (ispHandle == NULL || retVal != GADI_OK)
    {
        printf("gadi_isp_open() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static int sample_isp_start(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_load_param(ispHandle, NULL);
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_load_param() failed! ret = %d\n", retVal);
    }

    retVal = gadi_isp_start(ispHandle);
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_start() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static int sample_isp_stop(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_stop(ispHandle);
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_stop() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static int sample_isp_close(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_close(ispHandle);
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_close() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static int sample_isp_exit(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_exit();
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_exit() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static int sample_video_open(void)
{
    int retVal = GADI_OK;

    GADI_VENC_OpenParamsT vencOpenParams;

    viHandle = gadi_vi_open(&retVal);
    if(retVal != GADI_OK){
        printf("gadi_vi_open error\n");
        return retVal;
    }

    /*open vo module.*/
    voHandle = gadi_vout_open(&retVal);
    if(retVal != GADI_OK){
        printf("gadi_vout_open error\n");
        return retVal;
    }

    /*open venc module.*/
    gadi_sys_memset(&vencOpenParams, 0, sizeof(GADI_VENC_OpenParamsT));
    vencOpenParams.viHandle   = viHandle;
    vencOpenParams.voutHandle = voHandle;
    vencHandle = gadi_venc_open(&vencOpenParams, &retVal);
    if(retVal != GADI_OK){
        printf("gadi_venc_open error\n");
        return retVal;
    }

    /*map bit stream buffer.*/
    retVal = gadi_venc_map_bsb(vencHandle);
    if(retVal != GADI_OK){
        printf("gadi_venc_map_bsb fail\n");
    }

    return retVal;
}


static int sample_video_close(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_venc_close(vencHandle);
    if(retVal != GADI_OK){
        printf("gadi_venc_close error\n");
        return retVal;
    }

    retVal = gadi_vout_close(voHandle);
    if(retVal != GADI_OK){
        printf("gadi_vo_close error\n");
        return retVal;
    }

    retVal = gadi_vi_close(viHandle);
    if(retVal != GADI_OK){
        printf("gadi_vi_close error\n");
        return retVal;
    }

    return retVal;
}

static int sample_video_set_params(void)
{
    int retVal = GADI_OK;
    unsigned int  enable, cnt;
    unsigned char encodeType;

    /*video input module: ensure exit preview status.*/
    enable = 0;
    retVal = gadi_vi_enable(viHandle, enable);
    if(retVal != GADI_OK){
        printf("gadi_vi_enable error\n");
        return retVal;
    }

    /*video input module: set video input frame rate and resolution.*/
    retVal = gadi_vi_set_params(viHandle, &viParams);
    if(retVal != GADI_OK){
        printf("gadi_vi_set_params error\n");
        return retVal;
    }

    /*video out module: set video output resolution and output device.*/
    retVal = gadi_vout_set_params(voHandle, &voParams);
    if(retVal != GADI_OK){
        printf("gadi_vo_set_params error\n");
        return retVal;
    }

    /*set channels parameters.*/
    retVal = gadi_venc_set_channels_params(vencHandle, &chansParams);
    if(retVal != GADI_OK){
        printf("set channels parameters error.\n");
        return retVal;
    }

    for (cnt = 0; cnt < GADI_VENC_STREAM_NUM; cnt++){
        encodeType = streamFormats[cnt].encodeType;
        if(encodeType != 0){
            if (gadi_venc_set_stream_format(vencHandle, &streamFormats[cnt]) < 0){
                printf("gadi_venc_set_stream_format error, steamId=%d\n",cnt);
                return -1;
            }

            if(encodeType == GADI_VENC_TYPE_H264){
                if(gadi_venc_set_h264_config(vencHandle, &h264Conf[cnt]) < 0){
                    printf("gadi_venc_set_h264_config error, steamId=%d\n",cnt);
                    return -1;
                }
            }
            else if(encodeType == GADI_VENC_TYPE_MJPEG){
                if(gadi_venc_set_mjpeg_config(vencHandle, &mjpegConf[cnt]) < 0){
                    printf("gadi_venc_set_mjpeg_config error, steamId=%d\n",cnt);
                    return -1;
                }
            }
        }
    }

    enable = 1;
    if(gadi_vi_enable(viHandle, enable) < 0){
        printf("gadi_vi_enable error.\n");
        return -1;
    }

    return GADI_OK;
}

static int sample_start_encode_streams(void)
{
    GADI_ERR retVal = GADI_OK;
    GADI_U8  encodeType;
    GADI_U32 cnt;

    /*start all streams encoding*/
    for (cnt = 0; cnt < GADI_VENC_STREAM_NUM; cnt++){
        encodeType = streamFormats[cnt].encodeType;
        if(encodeType != 0){
            printf("start stream[%d]\n",cnt);
            if(gadi_venc_start_stream(vencHandle, cnt) < 0){
                printf("gadi_venc_start_stream error, streams:%d\n", cnt);
                return -1;
            }
        }
    }
    return retVal;
}

static int sample_stop_encode_streams(void)
{
    GADI_ERR     retVal =  GADI_OK;
    GADI_U8      encodeType;
    GADI_U32     cnt;

    /*stop all streams encoding*/
    for (cnt = 0; cnt < GADI_VENC_STREAM_NUM; cnt++){
        encodeType = streamFormats[cnt].encodeType;
        if(encodeType != 0){
            printf("stop stream[%d]\n",cnt);
            if(gadi_venc_stop_stream(vencHandle, cnt) < 0){
                printf("gadi_venc_stop_stream error, streams:%d\n", cnt);
                return -1;
            }
        }
    }

    return retVal;
}

static void sample_kill_handle(int signo)
{
    runing_enable = FALSE;
    /*wait for exit read encode stream thread.*/
    sleep(1);

    sample_isp_stop();
    sample_stop_encode_streams();
    sample_isp_close();
    sample_video_close();
    sample_exit();

    exit(1);
}


static void* sample_read_encode_streams(void *arg)
{
    unsigned char encodingState = FALSE;
    int fd = -1;
    int chn, i;
    GADI_CHN_AttrT  chnAttr;
    GADI_VENC_StreamT stream;

    if(record_enable){
        /* open a new file to write */
        remove(record_file_name);
        if ((fd = open(record_file_name, O_WRONLY | O_CREAT, 0644)) == -1){
            printf("open %s failed.\n", record_file_name);
            return NULL;
        }
    }

    while(runing_enable){
        for(i = 0; i < GADI_VENC_STREAM_NUM; i ++){
            chn = i;
            if (gadi_venc_query(vencHandle, chn, &chnAttr) < 0){
                printf("gadi_venc_query chn:%d", chn);
                continue;
            }
            if((chnAttr.state == GADI_VENC_STREAM_STATE_ENCODING) ||
               (chnAttr.state == GADI_VENC_STREAM_STATE_STOPPING)){
                encodingState = TRUE;
                break;
            }
        }

        if( encodingState){
            /*BLOCK read.*/
            if (gadi_venc_get_stream(vencHandle, 0XFF, &stream)<0){
                printf("gadi_venc_get_stream chn:%d failed.", stream.stream_id);
            }
            else{
                /*stream end, stream size & stream addr is invalid.*/
                if(stream.stream_end == 1){
                    printf("gadi_venc_get_stream chn:%d stream end.", stream.stream_id);
                }
                else{
                    if(record_enable){
                        /*record encode stream 0.*/
                        if(stream.stream_id == GADI_VENC_STREAM_FIRST){
                            if (write(fd, stream.addr, stream.size) != stream.size){
                                printf("record: write file error, len=%d\n",stream.size);
                            }
                        }
                    }
                    else{
                        /*printf encode stream freame info.*/
                        printf("streamId:%d, frameSize:%d, frameNum:%d, PTS:%lldms,",
                            stream.stream_id, stream.size,
                            stream.frame_num, (stream.PTS / 90));
                        if(stream.pic_type == GADI_VENC_IDR_FRAME)
                            printf("frameType:%s\n","IDR Frame");
                        else if(stream.pic_type == GADI_VENC_I_FRAME)
                            printf("frameType:%s\n","I Frame");
                        else if(stream.pic_type == GADI_VENC_P_FRAME)
                            printf("frameType:%s\n","P Frame");
                        else if(stream.pic_type == GADI_VENC_JPEG_FRAME)
                            printf("frameType:%s\n","JPEG Frame");
                        else
                            printf("frameType:%s\n","Invalid Frame");
                    }
                }
            }
        }
        else{
            printf("--not in encode status.\n");
            usleep(30000);
        }
    }

    close(fd);
    runing_enable = FALSE;

    return NULL;
}

