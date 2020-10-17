/*!
********************************************************************************
**
** \file        ./fapi/sys/src/sys_error.h
** 
** \brief       System error codes.
**
** This file contains the definition of common ERROR codes which can be used by
** most of the drivers. In addition this file contains module bases for each
** FAPI driver and in-house developed modules.
** The previously mentioned common ERROR codes shall be added to the module
** base if used within a module.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_SYS_ERROR_H
    #define FAPI_SYS_ERROR_H

/*
********************************************************************************
** Common error codes (reserved from 0 to -99)
**
** Each error code shall be decreased in steps of 1.
********************************************************************************
*/
    //! Indication of success.
    #define FAPI_OK                                        0

    //! Bad parameter passed.
    #define FAPI_ERR_BAD_PARAMETER                        -1

    //! Memory allocation failed.
    #define FAPI_ERR_OUT_OF_MEMORY                        -2

    //! Device already initialised.
    #define FAPI_ERR_ALREADY_INITIALIZED                  -3

    //! Device not initialised.
    #define FAPI_ERR_NOT_INITIALIZED                      -4

    //! Feature or function is not available.
    #define FAPI_ERR_FEATURE_NOT_SUPPORTED                -5

    //! Timeout occured.
    #define FAPI_ERR_TIMEOUT                              -6

    //! The device is busy, try again later.
    #define FAPI_ERR_DEVICE_BUSY                          -7

    //! Invalid handle was passed.
    #define FAPI_ERR_INVALID_HANDLE                       -8

    //! Semaphore could not be created.
    #define FAPI_ERR_SEMAPHORE_CREATE                     -9

    //! The driver's used version is not supported.
    #define FAPI_ERR_UNSUPPORTED_VERSION                 -10

    //! Mailqueue coult not be created.
    #define FAPI_ERR_MAILQUEUE_CREATE                    -11

    //! Device/handle is not open.
    #define FAPI_ERR_NOT_OPEN                            -12

    //! Device/handle is already open.
    #define FAPI_ERR_ALREADY_OPEN                        -13

/*
********************************************************************************
**
** FAPI module specific bases (range from -1,000 to -999,000)
**
** Each module base shall be decreased in steps of 1,000.
**
** The module specific error codes shall range from -100 to -999.
********************************************************************************
*/
    //! ATA module base
    #define FAPI_ATA_MODULE_BASE                       -1000

    //! AUDEC module base
    #define FAPI_AUDEC_MODULE_BASE                     -2000

    //! AUOUT module base
    #define FAPI_AUOUT_MODULE_BASE                     -3000

    //! BOOT module base
    #define FAPI_BOOT_MODULE_BASE                      -4000

    //! BM module base
    #define FAPI_BM_MODULE_BASE                        -5000

    //! CLKPWR module base
    #define FAPI_CLKPWR_MODULE_BASE                    -6000

    //! DESC module base
    #define FAPI_DESC_MODULE_BASE                      -7000

    //! DMA module base
    #define FAPI_DMA_MODULE_BASE                       -8000

    //! ETH module base
    #define FAPI_ETH_MODULE_BASE                       -9000

    //! FLASH module base
    #define FAPI_FLASH_MODULE_BASE                    -10000

    //! FPC module base
    #define FAPI_FPC_MODULE_BASE                      -11000

    //! GPIO module base
    #define FAPI_GPIO_MODULE_BASE                     -12000

    //! GPREG module base
    #define FAPI_GPREG_MODULE_BASE                    -13000

    //! HDMI module base
    #define FAPI_HDMI_MODULE_BASE                     -14000

    //! I2C module base
    #define FAPI_I2C_MODULE_BASE                      -15000

    //! ICC module base
    #define FAPI_ICC_MODULE_BASE                      -16000

    //! INTR module base
    #define FAPI_INTR_MODULE_BASE                     -17000

    //! IR module base
    #define FAPI_IR_MODULE_BASE                       -18000

    //! MMU module base
    #define FAPI_MMU_MODULE_BASE                      -19000

    //! SSP module base
    #define FAPI_SSP_MODULE_BASE                      -20000

    //! SYNC module base
    #define FAPI_SYNC_MODULE_BASE                     -21000

    //! TIMER module base
    #define FAPI_TIMER_MODULE_BASE                    -22000

    //! TSD module base
    #define FAPI_TSD_MODULE_BASE                      -23000

    //! TTX module base
    #define FAPI_TTX_MODULE_BASE                      -24000

    //! UART module base
    #define FAPI_UART_MODULE_BASE                     -25000

    //! UPI module base
    #define FAPI_UPI_MODULE_BASE                      -26000

    //! USB module base
    #define FAPI_USB_MODULE_BASE                      -27000

    //! VIDEC module base
    #define FAPI_VIDEC_MODULE_BASE                    -28000

    //! VIENC module base
    #define FAPI_VIENC_MODULE_BASE                    -29000

    //! VISCALE module base
    #define FAPI_VISCALE_MODULE_BASE                  -30000

    //! BOARD module base
    #define FAPI_BOARD_MODULE_BASE                    -31000

    //! BOARDS module base
    #define FAPI_BOARDS_MODULE_BASE                   -32000

/*
********************************************************************************
** Other module specific bases (range from -1,000,000 to -10,000,000,000)
**
** Each module base shall be decreased in steps of 100,000.
********************************************************************************
*/
    /*
    ****************************************************************************
    ** RTOS
    ****************************************************************************
    */

    //! RTOS module base
    #define RTOS_SHARED_MODULE_BASE                 -1000000

    //! FAMOS module base
    #define RTOS_FAMOS_MODULE_BASE                  -1100000

    //! STUB module base
    #define RTOS_STUB_MODULE_BASE                   -1200000


    /*
    ****************************************************************************
    ** Subsystems
    ****************************************************************************
    */

    //! FE module base
    #define SUBSYS_FE_MODULE_BASE                   -2000000

    //! FE (CE6353) module base
    #define SUBSYS_FE_CE6353_MODULE_BASE            -2100000

    //! FE (DSF89000) module base
    #define SUBSYS_FE_DSF89000_MODULE_BASE          -2200000

    //! FE (MB86668) module base
    #define SUBSYS_FE_MB86668_MODULE_BASE           -2300000

    //! PAINT module base
    #define SUBSYS_PAINT_MODULE_BASE                -2400000

    //! PAINT (DRAW) module base
    #define SUBSYS_PAINT_DRAW_MODULE_BASE           -2500000

    //! PAINT (FONT) module base
    #define SUBSYS_PAINT_FONT_MODULE_BASE           -2600000

    //! PAINT (OSDHANDLER) module base
    #define SUBSYS_PAINT_OSDHANDLER_MODULE_BASE     -2700000

    //! STORAGE module base
    #define SUBSYS_STORAGE_MODULE_BASE              -2800000

    //! STORAGE (MMCSD) module base
    #define SUBSYS_STORAGE_MMCSD_MODULE_BASE        -2900000

    //! AUDIO (MIXER) module base
    #define SUBSYS_AUDIO_MIXER_MODULE_BASE          -3000000

    //! FLASH Filesystem module base
    #define SUBSYS_FS_FLASHFS_MODULE_BASE           -3100000

    //! FOTA module base
    #define SUBSYS_FOTA_MODULE_BASE                 -3200000

    //! GPROF module base
    #define SUBSYS_GPROF_MODULE_BASE                -3300000

    //! VIDEO output capture module base
    #define SUBSYS_VOC_MODULE_BASE                  -3400000

    //! VIDEO abstraction layer (VAL) module base
    #define SUBSYS_VIDEO_VAL_MODULE_BASE            -3500000
    
    //! Section filtering abstraction layer (SFAL) module base
    #define SUBSYS_SFAL_MODULE_BASE                 -3600000
    
    //! VIDEO abstraction layer (VAL) module base
    #define SUBSYS_AUDIO_AAL_MODULE_BASE            -3700000

    //! CI Lib module base
    #define SUBSYS_CI_MODULE_BASE                   -3800000

    /*
    ****************************************************************************
    ** Middleware
    ****************************************************************************
    */

    //! PVR module base
    #define MIDDLEWARE_PVR_MODULE_BASE              -5000000


    /*
    ****************************************************************************
    ** Applications
    ****************************************************************************
    */

    //! SmartGo module base
    #define APPLICATION_SMARTGO_MODULE_BASE        -10000000

#endif
