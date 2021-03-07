/*!
********************************************************************************
**
** \file        ./fapi/drv/i2c/src/drv_i2c.h
**
** \brief       I2C Driver.
**
** This file contains the declaration of the I2C driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_I2C_H
    #define FAPI_I2C_H

    #include <fapi/sys_driver.h>

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    #define FAPI_I2C0             0    //!< I2C0 hardware block
    #define FAPI_I2C1             1    //!< I2C1 hardware block
    #define FAPI_I2C2             2    //!< I2C2 hardware block

    /*!
    ********************************************************************************
    ** Standard error codes for the driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_I2C_ERR_BAD_PARAMETER         (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_I2C_ERR_OUT_OF_MEMORY         (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_I2C_ERR_ALREADY_INITIALIZED   (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_I2C_ERR_NOT_INITIALIZED       (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FAPI_I2C_ERR_FEATURE_NOT_SUPPORTED (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FAPI_I2C_ERR_TIMEOUT               (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FAPI_I2C_ERR_DEVICE_BUSY           (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FAPI_I2C_ERR_INVALID_HANDLE        (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_I2C_ERR_SEMAPHORE_CREATE      (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FAPI_I2C_ERR_UNSUPPORTED_VERSION   (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_UNSUPPORTED_VERSION)

    /*! The mailqueue could not be created. */
    #define FAPI_I2C_ERR_MAILQUEUE_CREATE      (FAPI_I2C_MODULE_BASE +\
                                                FAPI_ERR_MAILQUEUE_CREATE)

    /*!
    ********************************************************************************
    ** Additional driver error codes (reserved from -100 to -999)
    **
    ** Each error code shall be decreased in steps of 1.
    ********************************************************************************
    */

    /* I2C error base */
    #define FAPI_I2C_ERR_BASE           (FAPI_I2C_MODULE_BASE - 100)
    /*! \brief Another user is using the I2C device. */
    #define FAPI_I2C_ERR_BUSY           (FAPI_I2C_ERR_BASE -  0)
    /*! \brief The I2C channel has been occupied. */
    #define FAPI_I2C_ERR_BUS_OCCUP      (FAPI_I2C_ERR_BASE -  1)
    /*! \brief Slave received stop condition. */
    #define FAPI_I2C_ERR_SL_STOP_REC    (FAPI_I2C_ERR_BASE -  2)
    /*! \brief Receiver gives no acknowledge on data. */
    #define FAPI_I2C_ERR_RC_NACK        (FAPI_I2C_ERR_BASE -  3)
    /*! \brief Bus error at stop condition. */
    #define FAPI_I2C_ERR_BE_STOP        (FAPI_I2C_ERR_BASE -  4)
    /*! \brief Bus error at start condition. */
    #define FAPI_I2C_ERR_BE_START       (FAPI_I2C_ERR_BASE -  5)
    /*! \brief Arbitration lost during addressing or repeated start. */
    #define FAPI_I2C_ERR_AL_ADRSTA      (FAPI_I2C_ERR_BASE -  6)
    /*! \brief Arbitration lost during data transfer. */
    #define FAPI_I2C_ERR_AL_DATA        (FAPI_I2C_ERR_BASE -  7)
    /*! \brief Arbitration lost during stop condition. */
    #define FAPI_I2C_ERR_AL_STOP        (FAPI_I2C_ERR_BASE -  8)
    /*! \brief Slave gives no acknowledge on address. */
    #define FAPI_I2C_ERR_SL_NACK        (FAPI_I2C_ERR_BASE -  9)
    /*! \brief No transmission or as master received stop condition. */
    #define FAPI_I2C_ERR_MS_STOP_REC    (FAPI_I2C_ERR_BASE - 10)
    /*! \brief Automode transmit/receive error. */
    #define FAPI_I2C_ERR_AMDMA          (FAPI_I2C_ERR_BASE - 11)
    /*! \brief Function unsupported with current configuration. */
    #define FAPI_I2C_ERR_UNSUPPORTED    (FAPI_I2C_ERR_BASE - 12)
    /*! \brief GPIO error */
    #define FAPI_I2C_ERR_GPIO_FAILED    (FAPI_I2C_ERR_BASE - 13)
    /*! \brief Timer error */
    #define FAPI_I2C_ERR_TIMER_FAILED   (FAPI_I2C_ERR_BASE - 14)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Version of the I2C driver.
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
    **       FAPI_I2C_OpenParamsT structure.
    **
    *************************************************************************
    */

    typedef enum {
        FAPI_I2C_VERSION = (int32_t)0x00020000 //!< The current driver version
    } FAPI_I2C_VersionEnumT;

    /*!
    *******************************************************************************
    **
    ** \brief I2C datarate speed modes.
    **
    ** This enumeration specifies the speed of the I2C bus.
    **
    ** \sa    FAPI_I2C_OpenParamsT
    **
    *******************************************************************************
    */
    typedef enum
    {
        FAPI_I2C_100KBPS = (int32_t)1, //!< 100kHz datarate.
        FAPI_I2C_400KBPS = (int32_t)2  //!< 400kHz datarate.
    }FAPI_I2C_SpeedT;

    /*!
    ****************************************************************************
    **
    ** \brief Protocol modes.
    **
    ** This enumeration specifies which protocol shall be used.
    ** #FAPI_I2C_RESTART_PROTOCOL is used in case a restart has to be sent after
    ** the addressing sequence.
    **
    ** \sa    FAPI_I2C_SetProtocol()
    **
    ****************************************************************************
    */
    typedef enum
    {
        FAPI_I2C_COMMON_PROTOCOL  = (int32_t)0,  //!< Common protocol.
        FAPI_I2C_RESTART_PROTOCOL = (int32_t)1   //!< Protocol with restart.
    } FAPI_I2C_ProtocolT;

    /*!
    ****************************************************************************
    **
    ** \brief I2C types.
    **
    ** This enumeration specifies whether the I2C bus shall be run in HW mode
    ** or in SW mode.
    **
    ** \sa    FAPI_I2C_OpenParamsT
    **
    ****************************************************************************
    */
    typedef enum
    {
        FAPI_I2C_HARDWARE = (int32_t)0,  //!< I2C hardware driver.
        FAPI_I2C_SOFTWARE = (int32_t)1   //!< I2C software driver.
    } FAPI_I2C_TypeT;

    /*!
    ****************************************************************************
    **
    ** \brief I2C operation modes.
    **
    ** This enumeration covers all possible modes of operation. Software mode
    ** is determined by #FAPI_I2C_TypeT.
    **
    ** \sa    FAPI_I2C_SetOperationMode()
    **
    ****************************************************************************
    */
    typedef enum
    {
        FAPI_I2C_GENERIC_MASTER_MODE = (int32_t)0, //!< Generic master mode.
        FAPI_I2C_GENERIC_SLAVE_MODE  = (int32_t)1, //!< Generic slave mode.
        FAPI_I2C_AUTO_MASTER_MODE    = (int32_t)2  //!< Auto master mode.
    }FAPI_I2C_OperationModeT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the I2C driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    ** \sa    FAPI_I2C_Open()
    **
    *************************************************************************
    */
    typedef struct {
        FAPI_I2C_VersionEnumT version;      //!< The version of the driver. \ref FAPI_I2C_VersionEnumT "FAPI_I2C_VERSION".
        uint32_t              blockIndex;   //!< The I2C HW block to be used. #FAPI_I2C0, #FAPI_I2C1, #FAPI_I2C2
        FAPI_I2C_SpeedT       speed;        //!< The speed to be used by I2C. #FAPI_I2C_100KBPS, #FAPI_I2C_400KBPS
        FAPI_I2C_ProtocolT    protocol;     //!< The protocol to be used. #FAPI_I2C_COMMON_PROTOCOL, #FAPI_I2C_RESTART_PROTOCOL
        uint32_t              slaveAddress; //!< The physical address of the slave device.
        FAPI_I2C_TypeT        type;         //!< The type of I2C driver. #FAPI_I2C_HARDWARE, #FAPI_I2C_SOFTWARE
        uint32_t              timeOut;      //!< I2C minimum timeout is 100 ms
    } FAPI_I2C_OpenParamsT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************
    extern FAPI_SYS_DriverT FAPI_I2C_Driver0;
    extern FAPI_SYS_DriverT FAPI_I2C_Driver1;
    extern FAPI_SYS_DriverT FAPI_I2C_Driver2;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    int32_t          FAPI_I2C_Init(void);
    void             FAPI_I2C_Exit(void);
    uint32_t         FAPI_I2C_Isr0(void);
    uint32_t         FAPI_I2C_Isr1(void);
    uint32_t         FAPI_I2C_Isr2(void);
    FAPI_SYS_HandleT FAPI_I2C_Open(const FAPI_I2C_OpenParamsT* pParams,
                                   int32_t* errorCodePtr);
    void             FAPI_I2C_Reset(FAPI_SYS_HandleT handle);
    int32_t          FAPI_I2C_Close(const FAPI_SYS_HandleT handle);
    void             FAPI_I2C_CancelProcess(const FAPI_SYS_HandleT handle);
    int32_t          FAPI_I2C_Process(const FAPI_SYS_HandleT handle,
                                      uint8_t* dataPtr,
                                      const uint32_t dataLength);
    int32_t          FAPI_I2C_Read(const FAPI_SYS_HandleT handle,
                                   const uint8_t msSlaveAddress,
                                   uint8_t* txDataPtr,
                                   const uint32_t txDataLength,
                                   uint8_t* rxDataPtr,
                                   uint32_t rxDataLength);
    int32_t          FAPI_I2C_Write(const FAPI_SYS_HandleT handle,
                                    const uint8_t msSlaveAddress,
                                    uint8_t* txDataPtr,
                                    const uint32_t txDataLength);
    void             FAPI_I2C_SetOperationMode(const uint32_t blockIndex,
                                               const FAPI_I2C_OperationModeT operationMode);
    int32_t          FAPI_I2C_SetProtocol(const FAPI_SYS_HandleT handle,
                                          const FAPI_I2C_ProtocolT protocol);
    void             FAPI_I2C_SetMaxHandleCount(const uint32_t blockIndex,
                                                const uint32_t maximum);

    #ifdef __cplusplus
    }
    #endif
#endif



#if 0

struct fapi_i2c_params
{
   unsigned Data_0; //0
   unsigned Data_4; //4
   unsigned Data_8; //8
   unsigned Data_12; //12
   unsigned Data_16; //16
   unsigned Data_20; //20
   unsigned Data_24; //24
   //28
};

#endif


