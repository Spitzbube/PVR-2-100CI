/*!
********************************************************************************
**
** \file        ./fapi/drv/timer/src/drv_timer.h
**
** \brief       TIMER Driver.
**
** This file contains the declaration of the TIMER driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_TIMER_H
    #define FAPI_TIMER_H

    #include <fapi/sys_driver.h>

    //**************************************************************************
    //**************************************************************************
    //** Driver specific error codes
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** Standard error codes for the driver
    ****************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_TIMER_ERR_BAD_PARAMETER \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_TIMER_ERR_OUT_OF_MEMORY \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_TIMER_ERR_ALREADY_INITIALIZED \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_TIMER_ERR_NOT_INITIALIZED \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FAPI_TIMER_ERR_FEATURE_NOT_SUPPORTED \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FAPI_TIMER_ERR_TIMEOUT \
           (FAPI_TIMER_MODULE_BASE+FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FAPI_TIMER_ERR_DEVICE_BUSY \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FAPI_TIMER_ERR_INVALID_HANDLE \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_TIMER_ERR_SEMAPHORE_CREATE \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FAPI_TIMER_ERR_UNSUPPORTED_VERSION \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_UNSUPPORTED_VERSION)

    /*! The mailqueue could not be created. */
    #define FAPI_TIMER_ERR_MAILQUEUE_CREATE \
            (FAPI_TIMER_MODULE_BASE+FAPI_ERR_MAILQUEUE_CREATE)


    //**************************************************************************
    //**************************************************************************
    //** Defines and Macros
    //**************************************************************************
    //**************************************************************************

    #define FAPI_TIMER_TYPE_NONE           0            //!< timer not used
    #define FAPI_TIMER_TYPE_RTOS           1            //!< use timer as RTOS timer tick
    #define FAPI_TIMER_TYPE_SOFT           2            //!< use timer as SOFTWARE timer
    #define FAPI_TIMER_TYPE_HARD           3            //!< use timer as HARDWARE timer

    #define FAPI_TIMER_MODE_ONESHOT        1            //!< the timer fires only once
    #define FAPI_TIMER_MODE_CONTINUOUS     2            //!< the timer runs continuously

    #define FAPI_TIMER_RESOLUTION_1_USEC   1UL          //!< timer resolution 1 usec
    #define FAPI_TIMER_RESOLUTION_10_USEC  10UL         //!< timer resolution 10 usec
    #define FAPI_TIMER_RESOLUTION_100_USEC 100UL        //!< timer resolution 100 usec
    #define FAPI_TIMER_RESOLUTION_1_MSEC   1000UL       //!< timer resolution 1 msec
    #define FAPI_TIMER_RESOLUTION_10_MSEC  10000UL      //!< timer resolution 10 msec
    #define FAPI_TIMER_RESOLUTION_100_MSEC 100000UL     //!< timer resolution 100 msec
    #define FAPI_TIMER_RESOLUTION_1_SEC    1000000UL    //!< timer resolution 1 sec
    #define FAPI_TIMER_RESOLUTION_1_MIN    60000000UL   //!< timer resolution 1 minute
    #define FAPI_TIMER_RESOLUTION_1_HOUR   3600000000UL //!< timer resolution 1 hour

    //**************************************************************************
    //**************************************************************************
    //** Data types
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief Version of the TIMER driver.
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
    **       FAPI_TIMER_OpenParamsT structure.
    **
    ****************************************************************************
    */
    typedef enum {
        FAPI_TIMER_VERSION = (int32_t)0x00020001 //!< The current driver version
    } FAPI_TIMER_VersionEnumT;

    /*!
    ****************************************************************************
    ** \brief Callback function signature.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    ** \param value   The current timer value
    ** \param optData An optional data value
    ****************************************************************************
    */
    typedef void(*FAPI_TIMER_CallbackT)(uint64_t value,uint32_t optData);

    /*!
    ****************************************************************************
    ** \brief Open parameters for the TIMER driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    ** \note
    ** The default behaviour of the callback functions has been changed
    ** since driver version 0x00020000.
    ** In the former version both callback functions where called within
    ** ISR context which could block the entire system. The new default
    ** behaviour now is to executed both callback functions in BSR
    ** (thread) mode with interrupts enabled.
    ** In case you need the former behaviour, you can intruct the driver
    ** to do so by simply setting either "exec1InIsr" or "exec2InIsr"
    ** to a non zero value.
    ** WARNING: if code is executed within callback functions in IRQ context
    **          you must not call any blocking FAPI API function, keep in mind
    **          that nearly all FAPI API functions are calling
    **          FAPI_SYS_GET_SEMPAHORE() in blocking mode to avoid concurrent
    **          access to driver global variables.
    ****************************************************************************
    */
    typedef struct
    {
        FAPI_TIMER_VersionEnumT version;    //!< The version of the driver. \ref FAPI_TIMER_VersionEnumT "FAPI_TIMER_VERSION".
        uint32_t                type_;       //!< the timer type, ie. #FAPI_TIMER_TYPE_SOFT
        uint32_t                mode;       //!< the timer mode, ie. #FAPI_TIMER_MODE_ONESHOT
        uint32_t                resolution; //!< the timer resolution, ie. #FAPI_TIMER_RESOLUTION_1_SEC
        uint32_t                multiplier; //!< the resolution multiplier, ie. 5 for 5 seconds
        FAPI_TIMER_CallbackT    callback1;  //!< optional callback function to be called
        uint32_t                optData1;   //!< optional data passed to callback1
        FAPI_TIMER_CallbackT    callback2;  //!< optional callback function to be called
        uint32_t                optData2;   //!< optional data passed to callback2
        uint32_t                exec1InIsr; //!< optional flag which decides whether to run callback1 in ISR(1) or BSR(0) mode.
        uint32_t                exec2InIsr; //!< optional flag which decides whether to run callback2 in ISR(1) or BSR(0) mode.
    }
    FAPI_TIMER_OpenParamsT;

    //**************************************************************************
    //**************************************************************************
    //** Global Data
    //**************************************************************************
    //**************************************************************************

    extern FAPI_SYS_DriverT FAPI_TIMER_Driver0;
    extern FAPI_SYS_DriverT FAPI_TIMER_Driver1;
    extern FAPI_SYS_DriverT FAPI_TIMER_Driver2;

    //**************************************************************************
    //**************************************************************************
    //** API Functions
    //**************************************************************************
    //**************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    int32_t          FAPI_TIMER_Init( void );
    void             FAPI_TIMER_Exit( void );
    uint32_t         FAPI_TIMER_Isr0( void );
    uint32_t         FAPI_TIMER_Isr1( void );
    uint32_t         FAPI_TIMER_Isr2( void );
    void             FAPI_TIMER_Bsr0( uint32_t privData );
    void             FAPI_TIMER_Bsr1( uint32_t privData );
    void             FAPI_TIMER_Bsr2( uint32_t privData );
    void             FAPI_TIMER_SetClockFrequency( uint32_t freqencyHz );
    void             FAPI_TIMER_SetType( uint32_t index, uint32_t type );
    void             FAPI_TIMER_SetResolution( uint32_t index, uint32_t resolution );
    uint32_t         FAPI_TIMER_GetIndex( uint32_t type );
    uint32_t         FAPI_TIMER_GetResolution( uint32_t index );
    uint64_t         FAPI_TIMER_GetTimeStamp( uint32_t resolution );
    FAPI_SYS_HandleT FAPI_TIMER_Open( FAPI_TIMER_OpenParamsT* openParamsPtr, int32_t* errorCodePtr );
    int32_t          FAPI_TIMER_Close( FAPI_SYS_HandleT handle );
    int32_t          FAPI_TIMER_Start( FAPI_SYS_HandleT handle );
    int32_t          FAPI_TIMER_Stop( FAPI_SYS_HandleT handle );
    uint64_t         FAPI_TIMER_ReadValue( FAPI_SYS_HandleT handle );

    #ifdef __cplusplus
    }
    #endif
#endif

#if 0

#ifndef FAPI_TIMER_H_
#define FAPI_TIMER_H_

extern struct fapi_driver FAPI_TIMER_Driver0; //21efc180 
extern struct fapi_driver FAPI_TIMER_Driver1; //21efc1a4 
extern struct fapi_driver FAPI_TIMER_Driver2; //21efc1c8 


struct fapi_timer_params
{
   int Data_0; //0
   unsigned index; //4
   int type; //8 1=single
   unsigned Data_12; //12
   int Data_16; //16
   void (*Data_20)(unsigned long long, void*); //20
   void* Data_24; //24
   void (*Data_28)(unsigned long long, void*); //28
   void* Data_32; //32
   int Data_36; //36
   int Data_40; //40
   //44
};

extern int FAPI_TIMER_Stop(void*);
extern void* FAPI_TIMER_Open(struct fapi_timer_params*, int*);
extern int FAPI_TIMER_Close(void*);
extern unsigned FAPI_TIMER_GetIndex(unsigned);
extern unsigned long long FAPI_TIMER_GetTimeStamp(unsigned);
extern int FAPI_TIMER_GetResolution(unsigned);
extern void FAPI_TIMER_SetClockFrequency(unsigned);
extern int FAPI_TIMER_Start(void*);
extern unsigned long long FAPI_TIMER_ReadValue(void*);



#endif /*FAPI_TIMER_H_*/

#endif
