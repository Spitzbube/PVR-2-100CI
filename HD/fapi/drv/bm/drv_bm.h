/*!
*****************************************************************************
**
** \file        ./fapi/drv/bm/src/drv_bm.h
**
** \brief       BM Driver.
**
** This file contains the declaration of the BM driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_BM_H
    #define FAPI_BM_H

    #include <fapi/sys_driver.h>

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    /* BM blocks */
    #define FAPI_BM0                   0          //!< BM0 hardware block
    #define FAPI_BM1                   1          //!< BM1 hardware block
    #define FAPI_BM2                   2          //!< BM2 hardware block
    #define FAPI_BM3                   3          //!< BM3 hardware block
    #define FAPI_BM_HW_CONTROLLED      0xFFFFFFFF //!< BM hardware controlled block

    /* BM settings */
    #define FAPI_BM_SWAP                1    //!< Swap data
    #define FAPI_BM_NO_SWAP             0    //!< Don't swap data
    #define FAPI_BM_SWAP_2_BYTES        1    //!< Swap 2 bytes
    #define FAPI_BM_SWAP_4_BYTES        0    //!< Swap 4 bytes
    #define FAPI_BM_CHANNEL_AUTODETECT -1    //!< Selects the first free non-HWCB channel

    /* IRQ enabling/disabling */
    #define FAPI_BM_ENABLE_IRQ           0x1
    #define FAPI_BM_DISABLE_IRQ          0x0
    #define FAPI_BM_DISABLE_BUT_KEEP_IRQ 0xF

    /*!
    ********************************************************************************
    ** Standard error codes for the driver
    ********************************************************************************
    */

    /*! \brief Bad parameter passed. */
    #define FAPI_BM_ERR_BAD_PARAMETER         (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_BAD_PARAMETER)

    /*! \brief Memory allocation failed. */
    #define FAPI_BM_ERR_OUT_OF_MEMORY         (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_OUT_OF_MEMORY)

    /*! \brief Device already initialised. */
    #define FAPI_BM_ERR_ALREADY_INITIALIZED   (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_ALREADY_INITIALIZED)

    /*! \brief Device not initialised. */
    #define FAPI_BM_ERR_NOT_INITIALIZED       (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_NOT_INITIALIZED)

    /*! \brief Feature or function is not available. */
    #define FAPI_BM_ERR_FEATURE_NOT_SUPPORTED (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! \brief Timeout occured. */
    #define FAPI_BM_ERR_TIMEOUT               (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_TIMEOUT)

    /*! \brief The device is busy, try again later. */
    #define FAPI_BM_ERR_DEVICE_BUSY           (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_DEVICE_BUSY)

    /*! \brief Invalid handle was passed. */
    #define FAPI_BM_ERR_INVALID_HANDLE        (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_INVALID_HANDLE)

    /*! \brief Semaphore could not be created. */
    #define FAPI_BM_ERR_SEMAPHORE_CREATE      (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_SEMAPHORE_CREATE)

    /*! \brief The driver's used version is not supported. */
    #define FAPI_BM_ERR_UNSUPPORTED_VERSION   (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_UNSUPPORTED_VERSION)

    /*! \brief The mailqueue could not be created. */
    #define FAPI_BM_ERR_MAILQUEUE_CREATE      (FAPI_BM_MODULE_BASE +\
                                               FAPI_ERR_MAILQUEUE_CREATE)

    /*!
    ********************************************************************************
    ** Additional driver error codes (reserved from -100 to -999)
    **
    ** Each error code shall be decreased in steps of 1.
    ********************************************************************************
    */
    /*! \brief BM error base */
    #define FAPI_BM_ERR_BASE                        (FAPI_BM_MODULE_BASE - 100)
    /*! \brief Pointer was set outside the bounds of the buffer. */
    #define FAPI_BM_ERR_PTR_OUTSIDE_BUFFER_BOUNDS   (FAPI_BM_ERR_BASE -  0)
    /*! \brief All hardware controlled buffers are already in use. */
    #define FAPI_BM_ERR_NO_MORE_HWCB_AVAILABLE      (FAPI_BM_ERR_BASE -  1)
    /*! \brief The hardware controlled buffers are used by a different BM. */
    #define FAPI_BM_ERR_HWCB_USED_BY_OTHER_BM       (FAPI_BM_ERR_BASE -  2)
    /*! \brief The given buffer is not hardware controlled. */
    #define FAPI_BM_ERR_NO_HWCB                     (FAPI_BM_ERR_BASE -  3)
    /*! \brief The provided AUD is not assigned. */
    #define FAPI_BM_ERR_AUD_NOT_ASSIGNED            (FAPI_BM_ERR_BASE -  4)
    /*! \brief Read / Write pointer is out of bounds. The operation is invalid. */
    #define FAPI_BM_ERR_POINTER_OUT_OF_BOUNDS       (FAPI_BM_ERR_BASE -  5)
    /*! \brief The buffer settings have already been set for the given function. */
    #define FAPI_BM_ERR_PURPOSE_ALREADY_ASSIGNED    (FAPI_BM_ERR_BASE -  6)
    /*! \brief The function has not beed defined yet. */
    #define FAPI_BM_ERR_INVALID_PURPOSE             (FAPI_BM_ERR_BASE -  7)
    /*! \brief The function has not beed defined yet. */
    #define FAPI_BM_ERR_PURPOSE_NOT_ASSIGNED        (FAPI_BM_ERR_BASE -  8)
    /*! \brief The buffer does not feature a high level IRQ handling. */
    #define FAPI_BM_ERR_HIGH_LEVEL_IRQ_NOT_ASSIGNED (FAPI_BM_ERR_BASE -  9)
    /*! \brief The buffer does not feature a low level IRQ handling. */
    #define FAPI_BM_ERR_LOW_LEVEL_IRQ_NOT_ASSIGNED  (FAPI_BM_ERR_BASE - 10)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Version of the BM driver.
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
    **       FAPI_BM_OpenParamsT structure.
    **
    *************************************************************************
    */

    typedef enum {
        FAPI_BM_VERSION = (int32_t)0x00040000   //!< The current driver version
    } FAPI_BM_VersionEnumT;

    /*!
    *************************************************************************
    ** \brief Type definition of the callback function.
    **
    ** This function prototype is used for the handler callback functions.<br>
    ** The blockIndex indicates which BM deployed the callback. The
    ** channelIndex is equivalent to the buffer.
    **
    *************************************************************************
    */
    typedef void(*FAPI_BM_CallbackT)(uint32_t blockIndex, uint32_t channelIndex,
                                     void* optData);

    /*!
    *************************************************************************
    ** \brief Type definition of the AUD callback function.
    **
    ** This function prototype is used for the AUD handler callback functions.
    **
    *************************************************************************
    */
    typedef void(*FAPI_BM_AudCallbackT)(uint32_t audIndex,
                                        uint32_t searchPattern,
                                        uint32_t readPointerPosition,
                                        void* optData);

    /*!
    *************************************************************************
    ** \brief Info structure for the BM driver.
    **
    ** This data structure covers the important informative variables of a
    ** given BM handle.
    **
    *************************************************************************
    */
    typedef struct {
        /*!
        ** BM HW block. #FAPI_BM_HW_CONTROLLED will automatically select the
        ** block which controls the hardware controlled buffers.
        ** (#FAPI_BM0, #FAPI_BM1, #FAPI_BM2, #FAPI_BM3)
        */
        uint32_t blockIndex; //0
        /*!
        ** Channel ID (buffer) of the BM HW block.
        ** (0, 1, ..., 31)
        */
        uint32_t channelId; //4
        /*!
        ** The BM's global offset address (physical).
        */
        uint32_t globalOffset; //8
        /*!
        ** Address of the buffer. The absolute address is the BM's global
        ** offset + buffer's address. So if this value is 0, the buffer is
        ** placed at the BM's global address.
        */
        uint32_t address; //12
        /*!
        ** Buffer size in bytes. The size of each channel is limited to 16 MB.
        */
        uint32_t size; //16
        /*!
        ** Determines if the buffer's context is swapped or not.
        */
        uint32_t swapWrite; //20
        /*!
        ** Determines, whether the data read from the buffer is swapped or
        ** not. The reading process refers to reading by hardware.
        */
        uint32_t swapRead; //24
        /*!
        ** Determines the way bytes are swapped.
        */
        uint32_t swapMode; //28
        /*!
        ** Private data of the info structure.
        */
        uint32_t privData; //32
        //36
    } FAPI_BM_InfoT;

        /*!
    *************************************************************************
    ** \brief Reconfiguration structure for the BM driver.
    **
    ** This data structure covers the important informative variables of a
    ** given BM handle that can be reconfigured without closing and opening
    ** the driver's instance.
    **
    *************************************************************************
    */
    typedef struct {
        /*!
        ** Address of the buffer. The absolute address is the BM's global
        ** offset + buffer's address. So if this value is 0, the buffer is
        ** placed at the BM's global address.
        */
        uint32_t address;
        /*!
        ** Buffer size in bytes. The size of each channel is limited to 16 MB.
        */
        uint32_t size;
        /*!
        ** Determines if the buffer's context is swapped or not.
        */
        uint32_t swapWrite;
        /*!
        ** Determines, whether the data read from the buffer is swapped or
        ** not. The reading process refers to reading by hardware.
        */
        uint32_t swapRead;
        /*!
        ** Determines the way bytes are swapped .
        */
        uint32_t swapMode;
    } FAPI_BM_ReconfigureT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the BM driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    *************************************************************************
    */
    typedef struct {
        /*!
        ** The version of the driver.
        ** \ref FAPI_BM_VersionEnumT "FAPI_BM_VERSION".
        */
        FAPI_BM_VersionEnumT version; //0
        /*!
        ** BM HW block. #FAPI_BM_HW_CONTROLLED will automatically select the
        ** block which controls the hardware controlled buffers.
        ** (#FAPI_BM0, #FAPI_BM1, #FAPI_BM2, #FAPI_BM3, #FAPI_BM_HW_CONTROLLED)
        */
        uint32_t          blockIndex; //4
        /*!
        ** Channel ID (buffer) of the BM HW block.
        ** (-1, 0, 1, ..., 31) -1 for #FAPI_BM_CHANNEL_AUTODETECT.
        */
        int32_t           channelId; //8
        /*!
        ** Address of the buffer. The absolute address is the BM's global
        ** offset + buffer's address. So if this value is 0, the buffer is
        ** placed at the BM's global address.
        **
        ** \note This value needs to be 1K aligned.
        */
        uint32_t          address; //12
        /*!
        ** Buffer size in bytes.
        **
        ** \note This value needs to be 1K aligned.
        */
        uint32_t          size; //16
        /*!
        ** This value determines, whether the data written into the buffer is
        ** swapped or not.
        ** (#FAPI_BM_NO_SWAP, #FAPI_BM_SWAP)
        **
        ** \note This applies to all 32 buffers. If the buffer is read by software
        ** and an endian swap is needed, this variable should be set to #FAPI_BM_SWAP.
        */
        uint32_t          swapWrite; //20
        /*!
        ** This value determines, whether the data read from the buffer is
        ** swapped or not. The reading process refers to reading by hardware.
        ** (#FAPI_BM_NO_SWAP, #FAPI_BM_SWAP)
        **
        ** \note This applies to the first 8 HW controlled buffers only.
        */
        uint32_t          swapRead; //24
        /*!
        ** This value determines, whether the data contains 16 bit values or 32
        ** bit values. According to this set up, all 4 bytes are swapped or 2 bytes
        ** are swapped respectively.
        ** (#FAPI_BM_SWAP_4_BYTES, #FAPI_BM_SWAP_2_BYTES)
        **
        ** \note This functionality is for reading only according to swapRead settings.
        */
        uint32_t          swapMode; //28
        //32
    } FAPI_BM_OpenParamsT;

    /*!
    *************************************************************************
    ** \brief Purposes of the buffers.
    **
    ** This data structure covers all defined purposes for certain buffers.
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_BM_I2S0_BUFFER         = (int32_t)0, //!< I2S0 function of BM driver
        FAPI_BM_I2S1_BUFFER         = (int32_t)1, //!< I2S1 function of BM driver
        FAPI_BM_I2S2_BUFFER         = (int32_t)2, //!< I2S2 function of BM driver
        FAPI_BM_I2S3_BUFFER         = (int32_t)3, //!< I2S3 function of BM driver
        FAPI_BM_SPDIF_BUFFER        = (int32_t)4, //!< SPDIF function of BM driver
        FAPI_BM_TELETEXT_BUFFER     = (int32_t)5, //!< Teletext function of BM driver
        FAPI_BM_VIDEO_STREAM_BUFFER = (int32_t)6, //!< Video function of BM driver
        FAPI_BM_AUDIO_STREAM_BUFFER = (int32_t)7  //!< Video function of BM driver
    } FAPI_BM_PurposeT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************
    extern FAPI_SYS_DriverT FAPI_BM_Driver0;
    extern FAPI_SYS_DriverT FAPI_BM_Driver1;
    extern FAPI_SYS_DriverT FAPI_BM_Driver2;
    extern FAPI_SYS_DriverT FAPI_BM_Driver3;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
    int32_t          FAPI_BM_Init(void);
    void             FAPI_BM_Exit(void);
    uint32_t         FAPI_BM_Isr01(void);
    uint32_t         FAPI_BM_Isr23(void);
    void             FAPI_BM_Bsr(uint32_t privData);
    FAPI_SYS_HandleT FAPI_BM_Open(const FAPI_BM_OpenParamsT* pParams,
                                        int32_t* errorCodePtr);
    int32_t          FAPI_BM_Close(FAPI_SYS_HandleT handle);
    int32_t          FAPI_BM_GetBufferFillLevel(const FAPI_SYS_HandleT handle);
    uint32_t         FAPI_BM_GetGlobalOffset(const uint32_t blockIndex);
    uint32_t         FAPI_BM_GetBufferReadPointerPosition(const FAPI_SYS_HandleT handle);
    uint32_t         FAPI_BM_GetBufferWritePointerPosition(const FAPI_SYS_HandleT handle);
    uint8_t*         FAPI_BM_GetBufferReadPointer(const FAPI_SYS_HandleT handle);
    uint8_t*         FAPI_BM_GetBufferWritePointer(const FAPI_SYS_HandleT handle);
    uint32_t         FAPI_BM_GetHardwareControlledBlock(void);
    int32_t          FAPI_BM_MoveBufferReadPointer(FAPI_SYS_HandleT handle, const int32_t readPtrDistance);
    int32_t          FAPI_BM_MoveBufferWritePointer(FAPI_SYS_HandleT handle, const int32_t writePtrDistance);
    int32_t          FAPI_BM_SetBufferReadPointer(FAPI_SYS_HandleT handle,
                                                  const uint32_t readPtrPosition,
                                                  const uint32_t enableOutOfBounds);
    int32_t          FAPI_BM_SetBufferWritePointer(const FAPI_SYS_HandleT handle,
                                                   const uint32_t writePtrPosition,
                                                   const uint32_t enableOutOfBounds);
    void             FAPI_BM_SetGlobalOffset(const uint32_t blockIndex,
                                             const uint32_t globalOffset);
    void             FAPI_BM_SetHardwareControlledBlock(const uint32_t blockIndex);
    int32_t          FAPI_BM_SetReadEnable(FAPI_SYS_HandleT handle, uint32_t readEnable);
    int32_t          FAPI_BM_Write(FAPI_SYS_HandleT handle, void* writeBuffer,
                                   uint32_t length, uint32_t timeout);
    int32_t          FAPI_BM_Read(FAPI_SYS_HandleT handle, void* readBuffer,
                                  uint32_t length, uint32_t timeout);
    int32_t          FAPI_BM_SetAudCallback(FAPI_SYS_HandleT handle,
                                            const uint32_t audIndex,
                                            const uint32_t searchPattern,
                                            FAPI_BM_AudCallbackT callbackFunction,
                                            void* optData);
    int32_t          FAPI_BM_GetAudChannelAssignment(uint32_t blockIndex,
                                                     const uint32_t audIndex);
    int32_t          FAPI_BM_StartAudFiltering(const FAPI_SYS_HandleT handle);
    int32_t          FAPI_BM_StopAudFiltering(const FAPI_SYS_HandleT handle,
                                              const uint32_t audIndex);
    int32_t          FAPI_BM_GetInfo(FAPI_SYS_HandleT handle, FAPI_BM_InfoT* info);
    int32_t          FAPI_BM_SetBufferPurpose(const FAPI_BM_PurposeT bufferPurpose,
                                              const uint32_t blockIndex,
                                              const uint32_t address,
                                              const uint32_t size);
    uint32_t         FAPI_BM_GetAddressByBufferPurpose(const FAPI_BM_PurposeT bufferPurpose);
    int32_t          FAPI_BM_GetBlockIndexByBufferPurpose(const FAPI_BM_PurposeT bufferPurpose);
    uint32_t         FAPI_BM_GetSizeByBufferPurpose(const FAPI_BM_PurposeT bufferPurpose);
    int32_t          FAPI_BM_SetHighLevelIrq(const FAPI_SYS_HandleT handle, FAPI_BM_CallbackT callback, void* optData, uint32_t level, uint32_t enable);
    int32_t          FAPI_BM_GetHighLevelIrq(const FAPI_SYS_HandleT handle);
    int32_t          FAPI_BM_SetLowLevelIrq(const FAPI_SYS_HandleT handle, FAPI_BM_CallbackT callback, void* optData, uint32_t level, uint32_t enable);
    int32_t          FAPI_BM_GetLowLevelIrq(const FAPI_SYS_HandleT handle);
    int32_t          FAPI_BM_SetReadSwap(const FAPI_SYS_HandleT handle, uint32_t swap,
                                         uint32_t mode);
    int32_t          FAPI_BM_SetWriteSwap(const FAPI_SYS_HandleT handle, uint32_t swap);
    int32_t          FAPI_BM_SetOverflowIrq(const FAPI_SYS_HandleT handle, FAPI_BM_CallbackT callback, void* optData, uint32_t enable);
    int32_t          FAPI_BM_Reconfigure(FAPI_SYS_HandleT handle, const FAPI_BM_ReconfigureT* const configPtr, uint32_t checkBufferOverlap);
    #ifdef __cplusplus
    }
    #endif
#endif
