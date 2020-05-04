/******************************************************************************
** \file        adi/test/src/audio.c
**
** \brief       ADI layer audio(record/play) test.
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
#include <unistd.h>
#include <fcntl.h>

#include "adi_sys.h"
#include "adi_audio.h"

//*****************************************************************************
//*****************************************************************************
//** Local Defines
//*****************************************************************************
//*****************************************************************************
#define DEFAULT_RECORD_STREAM_FILE       "record_audio.dat"
#define DEFAULT_PLAYBACK_STREAM_FILE      "Sofia_audio.dat" //"playback_audio.dat"

#define AUDIO_PLAYBACK_THREAD_PRIORITY  3
#define AUDIO_PLAYBACK_THREAD_STACKSIZE 2048
#define AUDIO_PLAYBACK_THREAD_NAME      "audio_playback"

#define AUDIO_RECORD_THREAD_PRIORITY    4
#define AUDIO_RECORD_THREAD_STACKSIZE   2048
#define AUDIO_RECORD_THREAD_NAME        "audio_record"

#define AUDIO_LOOPBACK_THREAD_PRIORITY    4
#define AUDIO_LOOPBACK_THREAD_STACKSIZE   2048
#define AUDIO_LOOPBACK_THREAD_NAME        "audio_loopback"
//*****************************************************************************
//*****************************************************************************
//** Local structures
//*****************************************************************************
//*****************************************************************************
typedef struct
{
    GADI_BOOL runningFlags;
    GADI_U32 frameLen;
    GADI_SYS_ThreadHandleT  threadHandle;
} SAMPLE_AUDIO_PthreadArgsT;

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
SAMPLE_AUDIO_PthreadArgsT pthreadArgs;
GADI_AUDIO_SampleFormatEnumT sampleFormat = GADI_AUDIO_SAMPLE_FORMAT_A_LAW;//GADI_AUDIO_SAMPLE_FORMAT_RAW_PCM,GADI_AUDIO_SAMPLE_FORMAT_MU_LAW, GADI_AUDIO_SAMPLE_FORMAT_A_LAW
GADI_U32 audioFrameLen;
//*****************************************************************************
//*****************************************************************************
//** Local Functions Declaration
//*****************************************************************************
//*****************************************************************************

//*****************************************************************************
//*****************************************************************************
//** API Functions
//*****************************************************************************
//*****************************************************************************

//*****************************************************************************
//*****************************************************************************
//** Local Functions
//*****************************************************************************
//*****************************************************************************
/*!
******************************************************************************
** sample usage
******************************************************************************
*/
GADI_VOID sample_audio_usage(void)
{
    printf("\nusage: sample audio command\n");
    printf("\t1,AI record(get audio stream from AI and write to file) \n");
    printf("\t2,AO playback(get audio stream from file and send to ao)\n");
    printf("\n");
}
/*!
******************************************************************************
** sample: ai start
******************************************************************************
*/
GADI_ERR sample_audio_ai_start(GADI_AUDIO_AioAttrT *pstAioAttr,GADI_AUDIO_SampleFormatEnumT sampleFormat)
{
    GADI_ERR retVal;
    
    retVal = gadi_audio_set_sample_format(gadi_audio_ai_get_fd(), sampleFormat);
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_set_sample_format failed(%d)\n",retVal);
        return -1;
    }

    /* set AI dev attr */
    retVal = gadi_audio_ai_set_attr(pstAioAttr);
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_ai_set_attr failed(%d)\n",retVal);
        return -1;
    }

    /* enable AI*/
    retVal = gadi_audio_ai_enable();
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_ai_enable failed(%d)\n",retVal);
        return -1;
    }

    return GADI_OK;
}
/*!
******************************************************************************
** sample: ai stop
******************************************************************************
*/
GADI_ERR sample_audio_ai_stop()
{
    GADI_ERR retVal;

    /* disable AI*/
    retVal = gadi_audio_ai_disable();
    if (retVal){
        GADI_ERROR("gadi_audio_ai_disable failed(%d)\n",retVal);
        return -1;
    }

    return GADI_OK;
}

/*!
******************************************************************************
** sample: audio ai thread
******************************************************************************
*/
GADI_VOID sample_audio_ai_to_file_process(void *arg)
{
    const char *name = DEFAULT_RECORD_STREAM_FILE;
    int fd = -1;
    GADI_AUDIO_AioFrameT audio_frame;
    SAMPLE_AUDIO_PthreadArgsT *pstPthreadArgs = (SAMPLE_AUDIO_PthreadArgsT*)arg;
    GADI_BOOL flag = GADI_TRUE;

    /* open a new file to write */
    remove(name);
    if ((fd = open(name, O_WRONLY | O_CREAT, 0644)) == -1)
    {
        GADI_ERROR("open %s failed.\n", name);
        return;
    }

    /* record */
    while (GADI_TRUE == pstPthreadArgs->runningFlags)
    {
        if(gadi_audio_ai_get_frame(&audio_frame, flag) == GADI_OK)
        {
           if (write(fd, audio_frame.virAddr, audio_frame.len) != audio_frame.len)
           {
               GADI_ERROR("audio_record: write file error, len=%d\n",audio_frame.len);
           }
        }

    }

    close(fd);
    pstPthreadArgs->runningFlags = GADI_FALSE;

    return;
}

/*!
******************************************************************************
** sample: Create the thread to get audio stream from AI and write to file
******************************************************************************
*/
GADI_ERR sample_audio_creat_ai_to_file_porc()
{
    SAMPLE_AUDIO_PthreadArgsT *pstPthreadArgs = &pthreadArgs;

    pstPthreadArgs->runningFlags = GADI_TRUE;
    pstPthreadArgs->frameLen = audioFrameLen;
    
    gadi_sys_thread_create(sample_audio_ai_to_file_process,
                           (GADI_VOID*)pstPthreadArgs,
                           AUDIO_RECORD_THREAD_PRIORITY,
                           AUDIO_RECORD_THREAD_STACKSIZE,
                           AUDIO_RECORD_THREAD_NAME,
                           &pstPthreadArgs->threadHandle);
    return GADI_OK;
}

/*!
******************************************************************************
** sample: Destory the thread to get audio stream from AI and write to file
******************************************************************************
*/ 
GADI_ERR sample_audio_destory_ai_to_file_porc()
{
    SAMPLE_AUDIO_PthreadArgsT *pstPthreadArgs = &pthreadArgs;

    pstPthreadArgs->runningFlags = GADI_FALSE;
    
    gadi_sys_wait_end_thread(pstPthreadArgs->threadHandle);
    
    return GADI_OK;
}

/*!
******************************************************************************
** sample: audio ai record
******************************************************************************
*/
GADI_ERR sample_audio_ai_record(GADI_AUDIO_AioAttrT *pstAioAttr, 
                                        GADI_AUDIO_SampleFormatEnumT sampleFormat)
{
    GADI_ERR retVal;

    if (NULL == pstAioAttr) {
        GADI_ERROR("pstAioAttr is null\n");
        return -1;
    }

    retVal = sample_audio_ai_start(pstAioAttr, sampleFormat);
    if(retVal != GADI_OK) {
        return retVal;
    }

    retVal = sample_audio_creat_ai_to_file_porc();
    if(retVal != GADI_OK) {
        return retVal;
    }

    GADI_INFO("please tpye any key twice to exit\n");

    getchar();
    getchar();

    sample_audio_destory_ai_to_file_porc();
    sample_audio_ai_stop();

    return retVal;
}

/*!
******************************************************************************
** sample: ao start
******************************************************************************
*/
GADI_ERR sample_audio_ao_start(GADI_AUDIO_AioAttrT *pstAioAttr,GADI_AUDIO_SampleFormatEnumT sampleFormat)
{
    GADI_ERR retVal;
    
    retVal = gadi_audio_set_sample_format(gadi_audio_ao_get_fd(), sampleFormat);
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_set_sample_format failed(%d)\n",retVal);
        return -1;
    }

    /* set AO dev attr */
    retVal = gadi_audio_ao_set_attr(pstAioAttr);
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_ao_set_attr failed(%d)\n",retVal);
        return -1;
    }

    /* enable AO*/
    retVal = gadi_audio_ao_enable();
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_ao_enable failed(%d)\n",retVal);
        return -1;
    }

    return GADI_OK;
}
/*!
******************************************************************************
** sample: ao stop
******************************************************************************
*/
GADI_ERR sample_audio_ao_stop()
{
    GADI_ERR retVal;

    /* disable AO*/
    retVal = gadi_audio_ao_disable();
    if (retVal != GADI_OK){
        GADI_ERROR("gadi_audio_ao_disable failed(%d)\n",retVal);
        return -1;
    }


    return GADI_OK;
}
/*!
******************************************************************************
** sample: audio file to ao thread
******************************************************************************
*/
GADI_VOID sample_audio_file_to_ao_process(GADI_VOID *arg)
{
    const char *name = DEFAULT_PLAYBACK_STREAM_FILE;
    int fd = -1;
    unsigned int  count  = 0;
    GADI_AUDIO_AioFrameT audio_frame;
    SAMPLE_AUDIO_PthreadArgsT *pstPthreadArgs = (SAMPLE_AUDIO_PthreadArgsT*)arg;
    GADI_BOOL flag = GADI_TRUE;
    int retVal = 0;
    

    if ((fd = open(name, O_RDONLY, 0)) == -1) {
        GADI_ERROR("open %s failed.\n",name);
        return;
    }
    
    audio_frame.len = pstPthreadArgs->frameLen;
    audio_frame.virAddr = (GADI_U8*)gadi_sys_malloc(audio_frame.len);
    if (NULL == audio_frame.virAddr)
    {
        GADI_ERROR("malloc failed!\n");
        return;
    }
    
    while (GADI_TRUE == pstPthreadArgs->runningFlags)
    {
        if(!retVal) {
            count = read(fd, audio_frame.virAddr, audio_frame.len);
        }
        if (count == 0) {
            lseek(fd, 0, SEEK_SET);
        }
        if(count == audio_frame.len) {
            retVal = gadi_audio_ao_send_frame(&audio_frame,flag);
        }
    }

    free(audio_frame.virAddr);
    close(fd);
    pstPthreadArgs->runningFlags = GADI_FALSE;

    return;
}

/*!
******************************************************************************
** sample: Create the thread to get audio stream from file and send to ao
******************************************************************************
*/
GADI_ERR sample_audio_creat_file_to_ao_porc()
{
    SAMPLE_AUDIO_PthreadArgsT *pstPthreadArgs = &pthreadArgs;

    pstPthreadArgs->runningFlags = GADI_TRUE;
    pstPthreadArgs->frameLen = audioFrameLen;
    
    gadi_sys_thread_create(sample_audio_file_to_ao_process,
                           (GADI_VOID*)pstPthreadArgs,
                           AUDIO_PLAYBACK_THREAD_PRIORITY,
                           AUDIO_PLAYBACK_THREAD_STACKSIZE,
                           AUDIO_PLAYBACK_THREAD_NAME,
                           &pstPthreadArgs->threadHandle);
    return GADI_OK;
}

/*!
******************************************************************************
** sample: Destory the thread to get audio stream from file and send to ao
******************************************************************************
*/ 
GADI_ERR sample_audio_destory_file_to_ao_porc()
{
    SAMPLE_AUDIO_PthreadArgsT *pstPthreadArgs = &pthreadArgs;

    pstPthreadArgs->runningFlags = GADI_FALSE;
    
    gadi_sys_wait_end_thread(pstPthreadArgs->threadHandle);
    
    return GADI_OK;
}

/*!
******************************************************************************
** sample: audio ao playback
******************************************************************************
*/
GADI_ERR sample_audio_ao_playback(GADI_AUDIO_AioAttrT *pstAioAttr, 
                                        GADI_AUDIO_SampleFormatEnumT sampleFormat)
{
    GADI_ERR retVal;

    if (NULL == pstAioAttr) {
        GADI_ERROR("pstAioAttr is null\n");
        return -1;
    }

    retVal = sample_audio_ao_start(pstAioAttr, sampleFormat);
    if(retVal != GADI_OK) {
        return retVal;
    }

    retVal = sample_audio_creat_file_to_ao_porc();
    if(retVal != GADI_OK) {
        return retVal;
    }
    
    GADI_INFO("please tpye any key twice to exit\n");

    getchar();
    getchar();

    sample_audio_destory_file_to_ao_porc();
    sample_audio_ao_stop();

    return retVal;
}

/*!
******************************************************************************
** main function
******************************************************************************
*/
GADI_ERR main(int argc, char *argv[])
{
    char ch;
    GADI_AUDIO_AioAttrT aio_attr;
    GADI_ERR retVal;

    retVal = gadi_sys_init();
    if (retVal != GADI_OK)
    {
        GADI_ERROR("gadi_sys_init failed!(%d)\n", retVal);
        return -1;
    }
    retVal = gadi_audio_init();
    if (retVal != GADI_OK)
    {
        GADI_ERROR("gadi_audio_init failed!(%d)\n", retVal);
        return -1;
    }

    /* config aio dev attr */
    aio_attr.bitWidth = GADI_AUDIO_BIT_WIDTH_16;//PCM:16bit GADI_AUDIO_BIT_WIDTH_16  , g711 a:
    aio_attr.soundMode = GADI_AUDIO_SOUND_MODE_SINGLE;
    aio_attr.sampleRate = GADI_AUDIO_SAMPLE_RATE_8000;
    aio_attr.frameSamples = 160;
    aio_attr.frameNum = 30;


    /* calculate frame size */
    if (sampleFormat == GADI_AUDIO_SAMPLE_FORMAT_RAW_PCM) {
        audioFrameLen = aio_attr.frameSamples * (aio_attr.bitWidth >> 3);
    } else {
        audioFrameLen = aio_attr.frameSamples * (aio_attr.bitWidth >> 3) / 2;
    }
    //gadi_audio_ai_set_gain(12);//add set ai_gain ,ÎÞÔ´mic:15 ,Ê°ÒôÆ÷:8
    sample_audio_usage();

    while ((ch = getchar()) != 'q')
    {
        switch (ch)
        {
            case '1':
            {
                retVal = sample_audio_ai_record(&aio_attr, sampleFormat);
                break;
            }
            case '2':
            {
                retVal = sample_audio_ao_playback(&aio_attr, sampleFormat);
                break;
            }
            default:
            {
                sample_audio_usage();
                break;
            }
        }
    }

    gadi_sys_exit();
    gadi_audio_exit();
    
    return retVal;
}

