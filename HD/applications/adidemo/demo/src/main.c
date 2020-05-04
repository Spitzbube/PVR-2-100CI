/******************************************************************************
** \file        adi/test/src/main.c
**
** \brief       ADI layer test.
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
#include <getopt.h>
#include <signal.h>

#include "adi_sys.h"
#include "adi_pwm.h"
#include "adi_gpio.h"

#include "vi.h"
#include "vout.h"
#include "venc.h"
#include "isp.h"
#include "shell.h"
#include "gpio.h"
#include "spi.h"
#include "ir.h"
#include "osd.h"
#include "pm.h"
#ifdef AUDIO_I2S_MODE
#include "i2s.h"
#else
#include "audio.h"
#endif
#include "pda.h"
#include "pwm.h"
#include "fb.h"
#include "vdec.h"
#include "interrupts.h"
#include "rtsp.h"
#include "web.h"
#include "tuning.h"
#include "ircut.h"
#include "onvif.h"

//*****************************************************************************
//*****************************************************************************
//** Local Defines
//*****************************************************************************
//*****************************************************************************
#define ADI_TEST_DEBUG_LEVEL    GADI_SYS_LOG_LEVLE_INFO

#define APP_VIDEO_CONFIGURATION_FILE_PATH "/usr/local/bin/video.xml"

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

GADI_SYS_HandleT pwmHandle = NULL;

//*****************************************************************************
//*****************************************************************************
//** Local Functions Declaration
//*****************************************************************************
//*****************************************************************************

static const char *shortOptions = "hadb";
static struct option longOptions[] =
{
    {"help",            0, 0, 'h'},
    {"all",             0, 0, 'a'},
    {"audio",           0, 0, 'd'},
    {"background",      0, 0, 'b'},
    {0,                 0, 0, 0}
};
static GADI_S32 work_mode = 0;
static GADI_S32 daemon_flag = 0;

#define set_daemon_mode()       ({daemon_flag = 1;})
#define set_audio_mode()         ({work_mode = 3;})
#define set_module_mode()        ({work_mode = 2;})
#define set_all_work_mode()      ({work_mode = 1;})

#define is_daemon_mode()        (daemon_flag == 1)
#define is_audio_mode()         (work_mode == 3)
#define is_module_mode()        (work_mode == 2)
#define is_all_work_mode()      (work_mode == 1)

//*****************************************************************************
//*****************************************************************************
//** Local Functions
//*****************************************************************************
//*****************************************************************************

GADI_ERR app_initialize(void)
{
    GADI_ERR   err      = GADI_OK;
    GADI_U32   streamId = 0;

    /* set debug level*/
    err = gadi_sys_set_log_level(ADI_TEST_DEBUG_LEVEL);

    /* system module init.*/
    err |= gadi_sys_init();
    if(!is_audio_mode()) {
        err = gadi_sys_load_firmware();
    }

    if(!is_audio_mode()) {

        /*load video configuration file.*/
        err = gdm_vi_parse_config_file(APP_VIDEO_CONFIGURATION_FILE_PATH);
        if(err != 0) {
            printf("load vi configuration file:%s failed.\n", APP_VIDEO_CONFIGURATION_FILE_PATH);
        }
        err = gdm_vout_parse_config_file(APP_VIDEO_CONFIGURATION_FILE_PATH);
        if(err != 0) {
            printf("load vout configuration file:%s failed.\n", APP_VIDEO_CONFIGURATION_FILE_PATH);
        }
        err = gdm_venc_parse_config_file(APP_VIDEO_CONFIGURATION_FILE_PATH);
        if(err != 0) {
            printf("load venc configuration file:%s failed.\n", APP_VIDEO_CONFIGURATION_FILE_PATH);
        }

        /* init video modules.*/
        err = gdm_vi_init();
        err |= gdm_vout_init();
        err |= gdm_venc_init();
        err |= gdm_vi_open();
        err |= gdm_vout_open();
        err |= gdm_venc_open();

        /* init isp modules. */
        err |= isp_init();
        err |= isp_open();

        if (err != GADI_OK) {
            printf("Applicantions initialize failed!\n");
            exit(-1);
        }

        gdm_vi_setup();
        gdm_vout_setup();
        gdm_venc_setup();
        gdm_vout_setup_after();

        for (streamId = 0; streamId < GADI_VENC_STREAM_NUM; streamId++)
        {
            err =  gdm_venc_start_encode_stream(streamId);
            if(err != 0)
            {
                printf("start stream[%d]\n",streamId);
            }
        }


        isp_start();


        /*init osd modules.*/
        err = osd_init();
        err = osd_open();

        /*init pm modules.*/
        err = pm_init();
        err = pm_open();

        /*init audio modules.*/
#ifdef AUDIO_I2S_MODE
        err = gdm_i2s_init();
#else
        err = gdm_audio_init();
#endif  

        err = rtsp_server_start();

        err = web_open();

        err = onvif_open();
    }
    else {
        /*init audio modules.*/
#ifdef AUDIO_I2S_MODE
        err = gdm_i2s_init();
#else
        err = gdm_audio_init();
#endif    
    }

    if (!is_daemon_mode())
        shell_init(GADI_SYS_THREAD_PRIO_DEFAULT);

    return err;
}

void app_main_task(void *data)
{
    if(app_initialize() < 0)
    {
        exit(1);
    }

    (void)shell_registercommand(
        "?",
        shell_helpcommand,
        "display all available commands,you can get the command help,Like \"? !\"," \
        "show the brief of command \"!\" ",
        "To get more help about a specific command simply pass the command\n" \
        "as optional argument to ?\n"                                         \
        "Example: ?       displays all available commands, one per line\n"    \
        "Example: ? !     displays a more detailed help for the ! command\n"
    );
    if(!is_audio_mode()) {
        gdm_venc_register_testcase();
        gdm_vi_register_testcase();
        isp_register_testcase();
        gpio_register_testcase();
        spi_register_testcase();
        ir_register_testcase();
        osd_register_testcase();
        pm_register_testcase();
#ifdef AUDIO_I2S_MODE
        gdm_i2s_register_testcase();
#else
        gdm_audio_register_testcase();
#endif
        pda_register_testcase();
        pwm_register_testcase();
        fb_register_testcase();
        vdec_register_testcase();
        interrupt_register_testcase();
        rtsp_register_testcase();
        tuning_register_testcase();
        web_register_testcase();
        ircut_register_testcase();
        onvif_register_testcase();
    }else {
        interrupt_register_testcase();
#ifdef AUDIO_I2S_MODE
        gdm_i2s_register_testcase();
#else
        gdm_audio_register_testcase();
#endif

    }

    while(1)
    {
        gadi_sys_thread_sleep(1000);
    }

}

static GADI_VOID usage(int argc, char* argv[])
{
    printf("%s Usage:\n", argv[0]);
    printf("    -h,--help                 help print usage manual.\n");
    printf("    -a,--all                  all of module initialize and start working.\n");
    printf("    -d,--audio                only running audio program.\n");
    printf("    -b,--background           background run program.\n");
    printf("\n");
    printf("Example:\n");
    printf("    #%s -a\n", argv[0]);
}

static GADI_VOID params_prase(int argc, char* argv[])
{
    GADI_S32 option_index;
    GADI_S8  ch;

    while ((ch = getopt_long(argc, argv, shortOptions, longOptions, &option_index)) != -1)
    {
        switch (ch)
        {
        case 'a':
            set_all_work_mode();
            break;
        case 'd':
            set_audio_mode();
            break;
        case 'b':
            set_daemon_mode();
            break;
        case 'h':
        default:
            usage(argc, argv);
            break;
        }
    }

    optind = 1;
}

static GADI_BOOL check_params_error(void)
{
    return (is_audio_mode() || is_all_work_mode()) ? GADI_FALSE : GADI_TRUE;
}

void enter_daemon(void)
{
    pid_t pid;

    if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) {
        printf("Can't signal SIGCHLD\n");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid != 0) {
        exit(0);
    }

    setsid();

    if ((pid = fork()))
        exit(0);
    else if (pid < 0)
        exit(1);

    if (signal(SIGCHLD, SIG_DFL) == SIG_ERR) {
        printf("Can't signal SIGCHLD\n");
        exit(1);
    }

    umask(0);
}

int main(int argc, char ** argv)
{
    if (argc < 2) {
        GADI_ERROR("Put param error!!");
        usage(argc, argv);
        return -1;
    }

    params_prase(argc, argv);

    if (check_params_error()) {
        return -1;
    }

    if (is_daemon_mode()) {
        enter_daemon();
    }
    gadi_sys_thread_create(app_main_task, NULL, GADI_SYS_THREAD_PRIO_DEFAULT,
        GADI_SYS_THREAD_STATCK_SIZE_DEFAULT, "MainTask", NULL);
    gadi_sys_multi_task_start();

    exit(0);
}


