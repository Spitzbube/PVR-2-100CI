/*!
*****************************************************************************
**
** \file        ./fapi/drv/sync/src/drv_sync.h
**
** \brief       SYNC Driver.
**
** This file contains the declaration of the SYNC driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_SYNC_H
    #define FAPI_SYNC_H

    #include <fapi/sys_driver.h>

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    #define FAPI_SYNC0            0    //!< SYNC0 block
    #define FAPI_SYNC1            1    //!< SYNC1 block

    #define FAPI_SYNC_PCR_BASED   0    //!< SYNC PCR based environment
    #define FAPI_SYNC_PTS_BASED   1    //!< SYNC PTS based environment

    #define FAPI_SYNC_INVALIDATE  0xFFFFFFFF       //!< Invalidate the PCR PID
    #define FAPI_SYNC_STC_MAX     0x25800000000ULL //!< (2^33) * 300

    /*!
    ********************************************************************************
    ** Standard error codes for the driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_SYNC_ERR_BAD_PARAMETER         (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_SYNC_ERR_OUT_OF_MEMORY         (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_SYNC_ERR_ALREADY_INITIALIZED   (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_SYNC_ERR_NOT_INITIALIZED       (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FAPI_SYNC_ERR_FEATURE_NOT_SUPPORTED (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FAPI_SYNC_ERR_TIMEOUT               (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FAPI_SYNC_ERR_DEVICE_BUSY           (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FAPI_SYNC_ERR_INVALID_HANDLE        (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_SYNC_ERR_SEMAPHORE_CREATE      (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FAPI_SYNC_ERR_UNSUPPORTED_VERSION   (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_UNSUPPORTED_VERSION)

    /*! The mailqueue could not be created. */
    #define FAPI_SYNC_ERR_MAILQUEUE_CREATE      (FAPI_SYNC_MODULE_BASE +\
                                                 FAPI_ERR_MAILQUEUE_CREATE)

    /*!
    ********************************************************************************
    ** Additional driver error codes (reserved from -100 to -999)
    **
    ** Each error code shall be decreased in steps of 1.
    ********************************************************************************
    */

    /* SYNC error base */
    #define FAPI_SYNC_ERR_BASE                   (FAPI_SYNC_MODULE_BASE - 100)

    /*! \brief PCR not available. */
    #define FAPI_SYNC_ERR_PCR_NOT_AVAILABLE      (FAPI_SYNC_ERR_BASE - 0)
    /*! \brief STC not available. */
    #define FAPI_SYNC_ERR_STC_NOT_AVAILABLE      (FAPI_SYNC_ERR_BASE - 1)
    /*! \brief TSD returned no handle. */
    #define FAPI_SYNC_ERR_PCR_PID_FAILED         (FAPI_SYNC_ERR_BASE - 2)
    /*! \brief Invalid state to be set. Only error states may be set externally. */
    #define FAPI_SYNC_ERR_INVALID_STATE          (FAPI_SYNC_ERR_BASE - 3)
    /*! \brief Decoder offset is out of range. */
    #define FAPI_SYNC_ERR_INVALID_DECODER_OFFSET (FAPI_SYNC_ERR_BASE - 4)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Version of the SYNC driver.
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
    **       FAPI_SYNC_OpenParamsT structure.
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_SYNC_VERSION = (int32_t)0x00040000   //!< The current driver version
    } FAPI_SYNC_VersionEnumT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the SYNC driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    *************************************************************************
    */
    typedef struct {
        /* \brief The version of the driver.
        **         \ref FAPI_SYNC_VersionEnumT "FAPI_SYNC_VERSION".
        */
        FAPI_SYNC_VersionEnumT version;
        /* \brief SYNC block which shall be used for STC calculation.
        **        (#FAPI_SYNC0, #FAPI_SYNC1)
        */
        uint32_t blockIndex;
    } FAPI_SYNC_OpenParamsT;

    /*!
    *************************************************************************
    ** \brief Status of the SYNC driver.
    **
    ** This data structure covers all possible stati of the SYNC driver.
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_SYNC_INITIAL_STATUS         = (int32_t)0, //!< Initial driver status
        FAPI_SYNC_SYNCHRONISING          = (int32_t)1, //!< Driver is synchronising
        FAPI_SYNC_SYNCHRONISED           = (int32_t)2, //!< Driver is synchronised
        FAPI_SYNC_NO_PCR                 = (int32_t)3, //!< Synchronisation failed
        FAPI_SYNC_TWO_PCRS               = (int32_t)4, //!< Synchronisation failed
        FAPI_SYNC_UNCERTAIN              = (int32_t)5  //!< Synchronisation may reset
    } FAPI_SYNC_StatusT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************
    extern FAPI_SYS_DriverT FAPI_SYNC_Driver;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
    int32_t           FAPI_SYNC_Init(void);
    void              FAPI_SYNC_Exit(void);
    FAPI_SYS_HandleT  FAPI_SYNC_Open(const FAPI_SYNC_OpenParamsT* pParams,
                                     int32_t* errorCodePtr);
    int32_t           FAPI_SYNC_Close(FAPI_SYS_HandleT handle);
    int64_t           FAPI_SYNC_GetDecoderOffset(void);
    uint32_t          FAPI_SYNC_GetEnvironment(void);
    int32_t           FAPI_SYNC_GetPcrStcDifference(uint64_t* pcrStcDifferencePtr);
    int32_t           FAPI_SYNC_GetPcr(uint64_t* pcrPtr);
    uint32_t          FAPI_SYNC_GetPcrPid(void);
    FAPI_SYNC_StatusT FAPI_SYNC_GetStatus(void);
    int32_t           FAPI_SYNC_GetStc(uint64_t* stcPtr);
    uint32_t          FAPI_SYNC_GetStcRegulation(void);
    void              FAPI_SYNC_PcrNotifier(FAPI_SYS_HandleT handle, uint64_t pcr);
    void              FAPI_SYNC_ResetRegulation(void);
    void              FAPI_SYNC_ResetStatus(void);
    int32_t           FAPI_SYNC_SetDecoderOffset(int64_t decoderOffset, uint32_t syncEnvironment);
    int32_t           FAPI_SYNC_SetDpllEnable(uint32_t enableDpll);
    int32_t           FAPI_SYNC_SetEnvironment(uint32_t syncEnvironment);
    int32_t           FAPI_SYNC_SetFd2to54Mhz(uint32_t enable);
    int32_t           FAPI_SYNC_SetPcrPid(uint32_t pid);
    int32_t           FAPI_SYNC_SetStatus(FAPI_SYS_HandleT handle, FAPI_SYNC_StatusT status);
    int32_t           FAPI_SYNC_SetStcRegulation(uint32_t enableStcRegulation);
    #ifdef __cplusplus
    }
    #endif
#endif
