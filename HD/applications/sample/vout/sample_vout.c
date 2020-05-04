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

//*****************************************************************************
//*****************************************************************************
//** Local structures
//*****************************************************************************
//*****************************************************************************

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
static GADI_SYS_HandleT ispHandle = NULL;

static GADI_VI_SettingParamsT   viParams = {
    .resoluMode = GK_VIDEO_MODE(VI_INPUT_WIDTH, VI_INPUT_HEIGHT, VI_INPUT_FPS, 1),
    .frameRate  = VI_INPUT_FPS,
    .mirrorMode = {GADI_VI_MIRROR_NONE, GADI_VI_BAYER_PATTERN_RG},
};

static GADI_VOUT_SettingParamsT voParams[GADI_VOUT_NUMBER] = {
    {
        .voutChannel = GADI_VOUT_A,
        .resoluMode  = GADI_VOUT_RESOLUTION_WVGA,
        .deviceType  = GADI_VOUT_DEVICE_RGB,
    },
    {
        .voutChannel = GADI_VOUT_B,
        .resoluMode  = GADI_VOUT_RESOLUTION_576I,
        .deviceType  = GADI_VOUT_DEVICE_DISABLE,
    },
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
        .encodeType = GADI_VENC_TYPE_OFF,
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
        .encodeType = GADI_VENC_TYPE_OFF,
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
    .chan4Type               = GADI_VENC_CHANNEL_TYPE_PREVIEW,
    .chan4Width              = 1280,
    .chan4Height             = 720,
    .chan4DeintlcForIntlcVin = 0,
    .intlcScan               = 0,
};

//*****************************************************************************
//*****************************************************************************
//** Local Functions Declaration
//*****************************************************************************
//*****************************************************************************
static int sample_init(void);
static int sample_exit(void);
static GADI_ERR sample_isp_init(void);
static GADI_ERR sample_isp_open(void);
static GADI_ERR sample_isp_start(void);
static GADI_ERR sample_isp_exit(void);
static int sample_video_open(void);
static int sample_video_close(void);
static int sample_video_set_params(void);
static void sample_kill_handle(int signo);

//*****************************************************************************
//*****************************************************************************
//** APP Functions
//*****************************************************************************
//*****************************************************************************
int main (int argc, char * argv[])
{
    int retVal = GADI_OK;

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

    signal(SIGINT, sample_kill_handle);
    signal(SIGQUIT, sample_kill_handle);
    signal(SIGTERM, sample_kill_handle);


    GADI_INFO("please tpye any key twice to exit\n");

    getchar();
    getchar();

    sample_video_close();
    sample_exit();

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

static GADI_ERR sample_isp_init(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_init();
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_init() failed! ret = %d\n", retVal);
    }

    return retVal;
}

static GADI_ERR sample_isp_open(void)
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

static GADI_ERR sample_isp_start(void)
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

static GADI_ERR sample_isp_exit(void)
{
    GADI_ERR retVal = GADI_OK;

    retVal = gadi_isp_stop(ispHandle);
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_stop() failed! ret = %d\n", retVal);
    }

    retVal = gadi_isp_close(ispHandle);
    if (retVal != GADI_OK)
    {
        printf("gadi_isp_close() failed! ret = %d\n", retVal);
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
    GADI_U8  channel;

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
        }
    }

    for(channel = GADI_VOUT_A; channel < GADI_VOUT_NUMBER;  channel++)
    {
        retVal = gadi_vout_set_params(voHandle, &voParams[channel]);
        if(retVal != GADI_OK)
        {
            printf("gadi_vout_set_params:ch%d error\n",channel);
            return retVal;
        }
    }

    enable = 1;
    if(gadi_vi_enable(viHandle, enable) < 0){
        printf("gadi_vi_enable error.\n");
        return -1;
    }

    return GADI_OK;
}

static void sample_kill_handle(int signo)
{
    /*wait for exit read encode stream thread.*/
    sleep(2);

    sample_video_close();
    sample_exit();

    exit(1);
}

