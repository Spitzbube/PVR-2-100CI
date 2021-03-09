/*!
*****************************************************************************
**
** \file        ./fapi/drv/clkpwr/src/drv_clkpwr.h
**
** \brief       CLKPWR Driver.
**
** This file contains the declaration of the CLKPWR driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2008 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_CLKPWR_H
    #define FAPI_CLKPWR_H

    #include <fapi/sys_driver.h>

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    /* watchdog settings */
    #define FAPI_CLKPWR_WATCHDOG_MIN_VALUE     0x00001000 //!< minimum value
    #define FAPI_CLKPWR_WATCHDOG_MAX_VALUE     0x0FFFF000 //!< maximum value

    /* basic clock power settings */
    #define FAPI_CLKPWR_ARM                     (0x1 <<  0)
    #define FAPI_CLKPWR_AUDIO                   (0x1 <<  1)
    #define FAPI_CLKPWR_AUDIO_PROCESSOR         (0x1 <<  2)
    #define FAPI_CLKPWR_AXI                     (0x1 <<  3) // on power down - hardware reset required
    #define FAPI_CLKPWR_DDR2_SDRAM              (0x1 <<  4) // on power down - hardware reset required
    #define FAPI_CLKPWR_DMA                     (0x1 <<  5) // on power down - hardware reset required
    #define FAPI_CLKPWR_ETH                     (0x1 <<  6)
    #define FAPI_CLKPWR_I2C                     (0x1 <<  7)
    #define FAPI_CLKPWR_ICC_APB_EFUSE           (0x1 <<  8)
    #define FAPI_CLKPWR_IRQ_CONTROL             (0x1 <<  9) // on power down - hardware reset required
    #define FAPI_CLKPWR_GPIO                    (0x1 << 10)
    #define FAPI_CLKPWR_SFLASH                  (0x1 << 11)
    #define FAPI_CLKPWR_SSP                     (0x1 << 12)
    #define FAPI_CLKPWR_TSD                     (0x1 << 13)
    #define FAPI_CLKPWR_UART_FPC                (0x1 << 14)
    #define FAPI_CLKPWR_UPI                     (0x1 << 15)
    #define FAPI_CLKPWR_USB                     (0x1 << 16)
    #define FAPI_CLKPWR_VIDEO                   (0x1 << 17)
    #define FAPI_CLKPWR_CRITICAL                (0x1 << 18) // RAM and ARM (system stop)

    /* power down settings */
    /*! \brief Disables audio (also processor), tsd, video and reduces ARM speed to 162 MHz. */
    #define FAPI_CLKPWR_BASIC_POWER_DOWN        0x00022007
    /*! \brief Additionally disables... */
    #define FAPI_CLKPWR_GENERIC_POWER_DOWN      0x0003FFF7
    /*! \brief Disables all allowed modules. */
    #define FAPI_CLKPWR_UNIVERSAL_POWER_DOWN    0x0003FFF7 // hardware reset required

    /* wake up settings */
    #define FAPI_CLKPWR_BASIC_WAKE_UP           0x00022007
    #define FAPI_CLKPWR_GENERIC_WAKE_UP         0x0003FFFF
    #define FAPI_CLKPWR_UNIVERSAL_WAKE_UP       0x0001FFC3

    /* PWM settings */
    #define FAPI_CLKPWR_PWM_MAX_VALUE           0x000003FF //!< maximum value

    /*!
    ********************************************************************************
    ** Standard error codes for the driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_CLKPWR_ERR_BAD_PARAMETER         (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_CLKPWR_ERR_OUT_OF_MEMORY         (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_CLKPWR_ERR_ALREADY_INITIALIZED   (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_CLKPWR_ERR_NOT_INITIALIZED       (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FAPI_CLKPWR_ERR_FEATURE_NOT_SUPPORTED (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FAPI_CLKPWR_ERR_TIMEOUT               (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FAPI_CLKPWR_ERR_DEVICE_BUSY           (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FAPI_CLKPWR_ERR_INVALID_HANDLE        (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_CLKPWR_ERR_SEMAPHORE_CREATE      (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FAPI_CLKPWR_ERR_UNSUPPORTED_VERSION   (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_UNSUPPORTED_VERSION)

    /*! The mailqueue could not be created. */
    #define FAPI_CLKPWR_ERR_MAILQUEUE_CREATE      (FAPI_CLKPWR_MODULE_BASE +\
                                                   FAPI_ERR_MAILQUEUE_CREATE)

    /*!
    ********************************************************************************
    ** Additional driver error codes (reserved from -100 to -999)
    **
    ** Each error code shall be decreased in steps of 1.
    ********************************************************************************
    */

    /* \brief CLKPWR error base */
    #define FAPI_CLKPWR_ERR_BASE                (FAPI_CLKPWR_MODULE_BASE - 100)
    /*! \brief Invalid start value for the watchdog. */
    #define FAPI_CLKPWR_ERR_INVALID_START_VALUE (FAPI_CLKPWR_ERR_BASE - 0)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Version of the CLKPWR driver.
    **
    ** This number consists of a \b major version number stored in bits
    ** 16 to 31 (upper word) and a \b minor version number stored in bits
    ** 0 to 15 (lower word).
    ** - The \b major number has to be increased when a parameter change
    **   occurs for the existing driver's API after its first release.
    ** - The \b minor number has to be increased when functions are added to
    **   the existing driver's API after its first release.
    **
    ** \note This value has to be assigend to the \b version field of the
    **       FAPI_CLKPWR_OpenParamsT structure.
    **
    *************************************************************************
    */

    typedef enum {
        FAPI_CLKPWR_VERSION = (int32_t)0x00020001   //!< The current driver version
    } FAPI_CLKPWR_VersionEnumT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the CLKPWR driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    *************************************************************************
    */
    typedef struct {
        /*!
        ** The version of the driver.
        ** \ref FAPI_CLKPWR_VersionEnumT "FAPI_CLKPWR_VERSION".
        */
        FAPI_CLKPWR_VersionEnumT version;
    } FAPI_CLKPWR_OpenParamsT;

    /*!
    *************************************************************************
    ** \brief State of the CLKPWR driver.
    **
    ** This enum defines all states of the CLKPWR driver.
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_CLKPWR_RUNNING       = (int32_t)0, //!< State after FAPI_CLKPWR_Init()
        FAPI_CLKPWR_STAND_BY      = (int32_t)1  //!< Stand by mode
    } FAPI_CLKPWR_StateT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************
    extern FAPI_SYS_DriverT FAPI_CLKPWR_Driver;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
    int32_t          FAPI_CLKPWR_Init(void);
    void             FAPI_CLKPWR_Exit(void);
    FAPI_SYS_HandleT FAPI_CLKPWR_Open(const FAPI_CLKPWR_OpenParamsT* paramsPtr,
                                      int32_t* errorCodePtr);
    int32_t          FAPI_CLKPWR_Close(FAPI_SYS_HandleT handle);
    int32_t          FAPI_CLKPWR_GetPwm(FAPI_SYS_HandleT handle);
    int32_t          FAPI_CLKPWR_GetState(FAPI_SYS_HandleT handle);
    int32_t          FAPI_CLKPWR_Reset(FAPI_SYS_HandleT handle, uint32_t componentMask);
    int32_t          FAPI_CLKPWR_ResetAudioProcessor(void);
    void             FAPI_CLKPWR_ResetTsdBlock(uint32_t blockIndex);
    int32_t          FAPI_CLKPWR_ResetWatchdog(FAPI_SYS_HandleT handle);
    int32_t          FAPI_CLKPWR_SetPwm(FAPI_SYS_HandleT handle, uint32_t pwmValue);
    int32_t          FAPI_CLKPWR_Standby(FAPI_SYS_HandleT handle, uint32_t componentMask);
    int32_t          FAPI_CLKPWR_StartWatchdog(FAPI_SYS_HandleT handle, uint32_t startValue);
    int32_t          FAPI_CLKPWR_StopWatchdog(FAPI_SYS_HandleT handle);
    int32_t          FAPI_CLKPWR_Wakeup(FAPI_SYS_HandleT handle, uint32_t componentMask);
    #ifdef __cplusplus
    }
    #endif
#endif
