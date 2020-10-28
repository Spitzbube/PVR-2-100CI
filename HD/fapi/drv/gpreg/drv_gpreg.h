/*!
********************************************************************************
**
** \file        ./fapi/drv/gpreg/src/drv_gpreg.h
**
** \brief       GPREG Driver.
**
** This file contains the declaration of the GPREG driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_GPREG_H
    #define FAPI_GPREG_H

    #include <fapi/sys_driver.h>

    //**************************************************************************
    //**************************************************************************
    //** Driver specific error codes
    //**************************************************************************
    //**************************************************************************

    #define FAPI_GPREG_ERR_BASE FAPI_GPREG_MODULE_BASE

    //**************************************************************************
    //**************************************************************************
    //** Defines and Macros
    //**************************************************************************
    //**************************************************************************

    #define FAPI_GPREG_UART0    0 //!< internal master/slave cpu UART0 synchronization
    #define FAPI_GPREG_UART1    1 //!< internal master/slave cpu UART1 synchronization
    #define FAPI_GPREG_IRQ31_S1 2 //!< internal master/slave cpu communication via irq31
    #define FAPI_GPREG_IRQ31_V1 3 //!< internal master/slave cpu communication via irq31
    #define FAPI_GPREG_IRQ31_S2 4 //!< internal master/slave cpu communication via irq31
    #define FAPI_GPREG_IRQ31_V2 5 //!< internal master/slave cpu communication via irq31
    #define FAPI_GPREG_RECOVERY 6 //!< user/application specific mutex/register
    #define FAPI_GPREG_USER_1   7 //!< user/application specific mutex/register

    //**************************************************************************
    //**************************************************************************
    //** Data types
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief Version of the GPREG driver.
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
    **       FAPI_GPREG_OpenParamsT structure.
    **
    ****************************************************************************
    */

    typedef enum {
        FAPI_GPREG_VERSION = (int32_t)0x00030000   //!< The current driver version
    } FAPI_GPREG_VersionEnumT;

    /*!
    ****************************************************************************
    ** \brief Open parameters for the GPREG driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    ****************************************************************************
    */
    typedef struct {
        FAPI_GPREG_VersionEnumT version; //!< The version of the driver. \ref FAPI_GPREG_VersionEnumT "FAPI_GPREG_VERSION".
        uint32_t                index;   //!< the index of the general purpose register to access
    } FAPI_GPREG_OpenParamsT;

    //**************************************************************************
    //**************************************************************************
    //** Global Data
    //**************************************************************************
    //**************************************************************************

    extern FAPI_SYS_DriverT FAPI_GPREG_Driver;

    //**************************************************************************
    //**************************************************************************
    //** API Functions
    //**************************************************************************
    //**************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
    int32_t          FAPI_GPREG_Init( void );
    void             FAPI_GPREG_Exit( void );
    FAPI_SYS_HandleT FAPI_GPREG_Open( const FAPI_GPREG_OpenParamsT* pParams, int32_t* errorCodePtr );
    int32_t          FAPI_GPREG_Close( FAPI_SYS_HandleT handlePtr );
    int32_t          FAPI_GPREG_Read( FAPI_SYS_HandleT handlePtr );
    int32_t          FAPI_GPREG_Write( FAPI_SYS_HandleT handlePtr, uint32_t data );
    int32_t          FAPI_GPREG_LockMutex( FAPI_SYS_HandleT handlePtr );
    int32_t          FAPI_GPREG_UnlockMutex( FAPI_SYS_HandleT handlePtr );

    #ifdef __cplusplus
    }
    #endif
#endif
