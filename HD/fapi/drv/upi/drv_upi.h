/*!
********************************************************************************
**
** \file        ./fapi/drv/upi/src/drv_upi.h
**
** \brief       UPI Driver.
**
** This file contains the declaration of the UPI driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_UPI_H
    #define FAPI_UPI_H

    #include <fapi/sys_driver.h>

    //**************************************************************************
    //**************************************************************************
    //** Driver specific error codes
    //**************************************************************************
    //**************************************************************************

    #define FAPI_UPI_ERR_BASE FAPI_UPI_MODULE_BASE

    //**************************************************************************
    //**************************************************************************
    //** Defines and Macros
    //**************************************************************************
    //**************************************************************************

    #define FAPI_UPI_DEVICE_0           0 //!< UPI device #0
    #define FAPI_UPI_DEVICE_1           1 //!< UPI device #1
    #define FAPI_UPI_DEVICE_2           2 //!< UPI device #2
    #define FAPI_UPI_DEVICE_COUNT       3 //!< max. number of UPI devices

    #define FAPI_UPI_MODE_INACTIVE      0 //!< device is inactive
    #define FAPI_UPI_MODE_SRAM          1 //!< SRAM or NOR-Flash mode
    #define FAPI_UPI_MODE_IDE           2 //!< IDE mode
    #define FAPI_UPI_MODE_NAND_FLASH    3 //!< NAND-Flash mode
    #define FAPI_UPI_MODE_CI_CM         4 //!< CI Common Memory mode
    #define FAPI_UPI_MODE_CI_AM         5 //!< CI Attribute Memory mode
    #define FAPI_UPI_MODE_CI_IO         6 //!< CI I/O mode
    #define FAPI_UPI_MODE_INDEX_MIN     0 //!< minimum allowed mode
    #define FAPI_UPI_MODE_INDEX_MAX     6 //!< maximum allowed mode

    #define FAPI_UPI_DEFAULTS_FLASH      0 //!< defaults for recommended NOR flash devices
    #define FAPI_UPI_DEFAULTS_CI_AM      1 //!< defaults for CI (type attribute memory)
    #define FAPI_UPI_DEFAULTS_NFLASH     2 //!< defaults for recommended NAND flash devices
    #define FAPI_UPI_DEFAULTS_INDEX_MIN  0 //!< minimum allowed value set
    #define FAPI_UPI_DEFAULTS_INDEX_MAX  2 //!< maximum allowed value set

    //**************************************************************************
    //**************************************************************************
    //** Data types
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief Version of the UPI driver.
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
    **       FAPI_UPI_OpenParamsT structure.
    **
    ****************************************************************************
    */

    typedef enum {
        FAPI_UPI_VERSION = (int32_t)0x00020001   //!< The current driver version
    } FAPI_UPI_VersionEnumT;

    /*!
    ****************************************************************************
    ** \brief Device configuration.
    **
    ** Data structure for holding timing and other configuration
    ** of an UPI device.
    ****************************************************************************
    */
    typedef struct
    {
        uint32_t mode;                  //!< operation mode
        uint32_t latchAddressSetupTime; //!< setup time for latching the address
        uint32_t latchAddressHoldTime;  //!< hold time for latching the address
        uint32_t readAddressTime;       //!< time for reading the address
        uint32_t readDataSetupTime;     //!< setup time for reading data
        uint32_t readDataHoldTime;      //!< hold time for reading data
        uint32_t readRecoveryTime;      //!< recovery time after reading data
        uint32_t writeDataSetupTime;    //!< setup time for writing data
        uint32_t writeDataHoldTime;     //!< hold time for writing data
        uint32_t writeRecoveryTime;     //!< recovery time after writing data
        uint32_t enableWait;            //!< flag to enable the usage of the wait signal line.
        uint32_t enableExternalBuffer;  //!< flag to enable external buffer
        uint32_t chipSelect;            //!< switching write enable to chip select
    } FAPI_UPI_ConfigT;

    /*!
    ****************************************************************************
    ** \brief Status of wait timeout timer.
    **
    ** Data structure for holding status information of wait timeout timer.
    ****************************************************************************
    */
    typedef struct
    {
        uint32_t timeout;  //!< set timeout time
        uint32_t lastTime; //!< last timeout time
        uint32_t isActive; //!< timeout was activated
    } FAPI_UPI_TimerInfoT;

    /*!
    ****************************************************************************
    ** \brief Open parameters for the UPI driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    ****************************************************************************
    */
    typedef struct {
        FAPI_UPI_VersionEnumT version; //!< The version of the driver. \ref FAPI_UPI_VersionEnumT "FAPI_UPI_VERSION".
        uint32_t              index;   //!< index of the UPI device to open, ie. #FAPI_UPI_DEVICE_0
    } FAPI_UPI_OpenParamsT;

    //**************************************************************************
    //**************************************************************************
    //** Global Data
    //**************************************************************************
    //**************************************************************************

    extern FAPI_SYS_DriverT FAPI_UPI_Driver;

    //**************************************************************************
    //**************************************************************************
    //** API Functions
    //**************************************************************************
    //**************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    int32_t          FAPI_UPI_Init( void );
    void             FAPI_UPI_Exit( void );
    FAPI_SYS_HandleT FAPI_UPI_Open( const FAPI_UPI_OpenParamsT* paramsPtr, int32_t* errorCodePtr );
    int32_t          FAPI_UPI_Close( FAPI_SYS_HandleT handle );
    int32_t          FAPI_UPI_SetDefaults( FAPI_SYS_HandleT handle, uint32_t valueSet );
    int32_t          FAPI_UPI_SetConfiguration( FAPI_SYS_HandleT handle, FAPI_UPI_ConfigT* configPtr );
    int32_t          FAPI_UPI_GetConfiguration( FAPI_SYS_HandleT handle, FAPI_UPI_ConfigT* configPtr );
    int32_t          FAPI_UPI_SetWaitTimer( FAPI_SYS_HandleT handle, uint32_t value );
    int32_t          FAPI_UPI_GetWaitTimer( FAPI_SYS_HandleT handle, FAPI_UPI_TimerInfoT* timerInfoPtr );
    int32_t          FAPI_UPI_GetBaseAddress( FAPI_SYS_HandleT handle, uint32_t* addressPtr );
    int32_t          FAPI_UPI_Lock( void );
    void             FAPI_UPI_Unlock( void );

    #ifdef __cplusplus
    }
    #endif
#endif
