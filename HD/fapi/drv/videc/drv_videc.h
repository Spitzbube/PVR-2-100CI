/*!
*******************************************************************************
**
** \file        ./fapi/drv/videc/src/drv_videc.h
**
** \brief       Video Decoder Driver.
**
** This file contains the declaration of the Video decoder driver API.
** It is the top level Video driver file for all the video decoders.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*******************************************************************************
*/

#ifndef FAPI_VIDEC_H
    #define FAPI_VIDEC_H

#include <fapi/sys_driver.h>

//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************
/*
*******************************************************************************
** Defines for general error codes of the module.
*******************************************************************************
*/
/*! Bad parameter passed. */
#define FAPI_VIDEC_ERR_BAD_PARAMETER                                          \
                              (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_BAD_PARAMETER)
/*! Memory allocation failed. */
#define FAPI_VIDEC_ERR_OUT_OF_MEMORY                                          \
                              (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_OUT_OF_MEMORY)
/*! Device already initialised. */
#define FAPI_VIDEC_ERR_ALREADY_INITIALIZED                                    \
                        (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_ALREADY_INITIALIZED)
/*! Device not initialised. */
#define FAPI_VIDEC_ERR_NOT_INITIALIZED                                        \
                            (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_NOT_INITIALIZED)
/*! Feature or function is not available. */
#define FAPI_VIDEC_ERR_FEATURE_NOT_SUPPORTED                                  \
                      (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_FEATURE_NOT_SUPPORTED)
/*! Timeout occured. */
#define FAPI_VIDEC_ERR_TIMEOUT                                                \
                                    (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_TIMEOUT)
/*! The device is busy, try again later. */
#define FAPI_VIDEC_ERR_DEVICE_BUSY                                            \
                                (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_DEVICE_BUSY)
/*! Invalid handle was passed. */
#define FAPI_VIDEC_ERR_INVALID_HANDLE                                         \
                             (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_INVALID_HANDLE)
/*! Semaphore could not be created. */
#define FAPI_VIDEC_ERR_SEMAPHORE_CREATE                                       \
                           (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_SEMAPHORE_CREATE)
/*! The driver's used version is not supported. */
#define FAPI_VIDEC_ERR_UNSUPPORTED_VERSION                                    \
                        (FAPI_VIDEC_MODULE_BASE + FAPI_ERR_UNSUPPORTED_VERSION)
/*
*******************************************************************************
** Defines for specialized error codes which are very specific
** to the behaviour of this module. These codes are offset by -100 from
** the module큦 general error codes.
*******************************************************************************
*/
/*!
*******************************************************************************
** \brief Error base for VIDEC Driver local errors.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_BASE                      (FAPI_VIDEC_MODULE_BASE - 100)
/*!
*******************************************************************************
** \brief Driver version mismatched. Driver update is required.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_DRV_VERSION_CHECK_FAILED                               \
                                                    (FAPI_VIDEC_ERR_BASE -   1)
/*!
*******************************************************************************
** \brief Opening params are wrong. Recheck open params.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_INVALID_OPEN_PARAMS                                    \
                                                    (FAPI_VIDEC_ERR_BASE -   2)
/*!
*******************************************************************************
** \brief Illogical combination of open params was used.
**  Recheck open params.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_INVALID_COMBINATION_OF_OPEN_PARAMS                     \
                                                    (FAPI_VIDEC_ERR_BASE -   3)
/*!
*******************************************************************************
** \brief Opening multiple instances of driver for the given HW block.
**  First close and then reopen again.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_EXCEEDED_MAX_HANDLES                                   \
                                                    (FAPI_VIDEC_ERR_BASE -   4)
/*!
*******************************************************************************
** \brief Opening multiple instances of driver for the given HW block.
**  First close and then reopen again.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_ISR_STATE_MACHINE_ALLOCATION_FAILURE                   \
                                                    (FAPI_VIDEC_ERR_BASE -   5)
/*!
*******************************************************************************
** \brief This functionality is not supported by the given HW Block.
**  Wrong handle to the HW block was used.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_UNSUPPORTED_FUNCTIONALITY                              \
                                                    (FAPI_VIDEC_ERR_BASE -   6)
/*!
*******************************************************************************
** \brief Internal check to verify the handle failed.
**  Wrong parameters was used.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_HANDLE_CHECK_FAILED                                    \
                                                    (FAPI_VIDEC_ERR_BASE -   7)
/*!
*******************************************************************************
** \brief Invalid arguement list. Recheck arguement list, maybe some of the
**  non-null expected arguements are set to null.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_INVALID_ARGUEMENT_LIST                                 \
                                                    (FAPI_VIDEC_ERR_BASE -   8)
/*!
*******************************************************************************
** \brief Parallel and serial flash could not be found.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_FIRMWARE_FLASH_FAILURE                                 \
                                                    (FAPI_VIDEC_ERR_BASE -   9)
/*!
*******************************************************************************
** \brief Firmware version mismatched the VIDEC driver version.
** Update video decoder firmwares in the flash.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEC_FIRMWARE_VERSION_MISMATCH                        \
                                                    (FAPI_VIDEC_ERR_BASE -  10)
/*!
*******************************************************************************
** \brief Firmware not found in the flash.
** Burn the missing video decoder firmwares in the flash.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEC_FIRMWARE_NOT_FOUND                               \
                                                    (FAPI_VIDEC_ERR_BASE -  11)
/*!
*******************************************************************************
** \brief Booting timeout. Failure to boot causes timeout.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_BOOT_TIMEOUT                                           \
                                                    (FAPI_VIDEC_ERR_BASE -  12)
/*!
*******************************************************************************
** \brief Start timeout. Failure to start causes timeout.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_START_TIMEOUT                                          \
                                                    (FAPI_VIDEC_ERR_BASE -  13)
/*!
*******************************************************************************
** \brief Stopping timeout. Failure to stop causes timeout.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_STOP_TIMEOUT                                           \
                                                    (FAPI_VIDEC_ERR_BASE -  14)
/*!
*******************************************************************************
** \brief Reset timeout. Failure to reset causes timeout.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_RESET_TIMEOUT                                          \
                                                    (FAPI_VIDEC_ERR_BASE -  15)
/*!
*******************************************************************************
** \brief Enable/Disable video timeout.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_ENABLE_DISABLE_TIMEOUT                                 \
                                                    (FAPI_VIDEC_ERR_BASE -  16)
/*!
*******************************************************************************
** \brief Synchro Enable/Disable timeout.
** This error means that no video frames were decoded. So unsupported stream
** error is returned. A scrambled or encrypted stream shall also generate this
** error. A non MPEG-TS compliant stream that does not contain AUDs shall also
** generate this error.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_UNSUPPORTED_STREAM                                     \
                                                    (FAPI_VIDEC_ERR_BASE -  17)
/*!
*******************************************************************************
** \brief Call back is already assigned so no new assignment is allowed.
** A video close, followed by open and reassignment of callback is required.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_CALLBACK_ALREADY_ASSIGNED                              \
                                                    (FAPI_VIDEC_ERR_BASE -  18)
/*!
*******************************************************************************
** \brief Certain error states are only relevant while the video decoder is
** running. For example retreiving the health of video decoder.
** If this error is generated then start the video decoder first and then
** call the API.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_RUNNING                              \
                                                    (FAPI_VIDEC_ERR_BASE -  19)
/*!
*******************************************************************************
** \brief This error may arise if the handle passed was not the expected handle.
** or a 0 handle was passed. Check that handle passed is the right one to the
** expected H/W block and is not null.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_WRONG_HANDLE                                           \
                                                    (FAPI_VIDEC_ERR_BASE -  20)
/*!
*******************************************************************************
** \brief This error may arise if the handle of VE HD passed is wrong. Or if
** unexpected parameters are passed for preinitialization.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_INVALID_INITIALIZATION_PARAMS                          \
                                                    (FAPI_VIDEC_ERR_BASE -  21)
/*!
*******************************************************************************
** \brief This error may arise if the MPEG I frame to be loaded into memory
** exceeds the size if circular VES buffer. Use a smaller frame.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_MPEG_IFRAME_EXCEEDS_ES_BUFF                           \
                                                   (FAPI_VIDEC_ERR_BASE -  22)
/*!
*******************************************************************************
** \brief This error may arise if the MPEG I frame that is to be loaded into
** memory has wrong format, byte swapped, without sequence header or not a
** MPEG frame at all. In this case the first word has to be sequence header
** with right byte order, the mpeg I frame elementary stream should be
** examined.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_MPEG_IFRAME_WITH_WRONG_HEADER                         \
                                                   (FAPI_VIDEC_ERR_BASE -  23)
/*!
*******************************************************************************
** \brief This error may arise if the MPEG I frame that is to be loaded into
** memory has wrong format, byte swapped, without sequence header or not a
** MPEG frame at all and hence no decoded frame is available in the frame memory.
** First a decoded frame must be available in the frame buffer before display
** process is initiated otherwise this error may result. Ensure that decoding
** process had ended without errors.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_MPEG_IFRAME_NO_DECODED_FRAME_AVAILABLE                 \
                                                    (FAPI_VIDEC_ERR_BASE -  24)
/*!
*******************************************************************************
** \brief This error may arise if the ISR state machine큦 association to the
** video decoder H/W block fails. It may also be due to wrong allocation of
** ISR state. Close followed by Open may solve the problem.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_ISR_ASSOCIATION_FAILURE                                \
                                                    (FAPI_VIDEC_ERR_BASE -  25)
/*!
*******************************************************************************
** \brief Certain error states are only relevant while the video decoder is
** booted. For example starting a unbooted video decoder shall result in this
** error:
** If this error is generated then boot the video decoder first and then
** call the API.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_DECODER_NOT_BOOTED                               \
                                                    (FAPI_VIDEC_ERR_BASE -  26)
/*!
*******************************************************************************
** \brief Video elementary stream overflow error code.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VES_BUFFER_OVERFLOW                                    \
                                                    (FAPI_VIDEC_ERR_BASE -  27)
/*!
*******************************************************************************
** \brief Incorrect playback environment.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_INCORRECT_PLAYBACK_ENVIRONMENT                         \
                                                    (FAPI_VIDEC_ERR_BASE -  28)
/*!
*******************************************************************************
** \brief Timeout occured while fetching the the first PTS in PVR environment.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_FIRST_PTS_FETCH_TIMEOUT                                \
                                                    (FAPI_VIDEC_ERR_BASE -  29)
/*!
*******************************************************************************
** \brief PTS was not found in the stream under PVR environment.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_FIRST_PTS_NOT_FOUND                                    \
                                                    (FAPI_VIDEC_ERR_BASE -  30)
/*!
*******************************************************************************
** \brief Video decoder memory segment allocation failure.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_MEMORY_SEGMENT_ALLOCATION_FAILURE                \
                                                    (FAPI_VIDEC_ERR_BASE -  31)
/*!
*******************************************************************************
** \brief Video decoder memory chunks within the segment allocation failure.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_ALLOCATION_FAILURE                  \
                                                    (FAPI_VIDEC_ERR_BASE -  32)
/*!
*******************************************************************************
** \brief Video decoder memory chunk큦 virual address to physical address
** translation failure generates this error.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_VIRTUAL_ADDRESS_UNAVAILABLE         \
                                                    (FAPI_VIDEC_ERR_BASE -  33)
/*!
*******************************************************************************
** \brief Video decoder memory chunk큦 virual address to physical address
** translation failure generates this error.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_MEMORY_CHUNK_PHYSICAL_ADDRESS_UNAVAILABLE        \
                                                    (FAPI_VIDEC_ERR_BASE -  34)
/*!
*******************************************************************************
** \brief Video decoder memory chunk큦 static address is outside supported
** size of SRAM_S or if it is within the memory range but not 4K boundary
** alligned .i.e lower 12 bits must be 0.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_MEMORY_SEGMENT_STATIC_ADDRESS_INVALID            \
                                                    (FAPI_VIDEC_ERR_BASE -  35)
/*!
*******************************************************************************
** \brief Video decoder큦 pre initialization had failed.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_DRIVER_PREINITIALIZATION_FAILURE                 \
                                                    (FAPI_VIDEC_ERR_BASE -  36)
/*!
*******************************************************************************
** \brief Video decoder큦 error is MPEG I frame mode is not set.
*******************************************************************************
*/
#define FAPI_VIDEC_ERR_VIDEO_WRONG_MODE                                       \
                                                    (FAPI_VIDEC_ERR_BASE -  37)
//*****************************************************************************
//*****************************************************************************
//** Data types
//*****************************************************************************
//*****************************************************************************

//*****************************************************************************
//*****************************************************************************
//** Enumerated types
//*****************************************************************************
//*****************************************************************************
/*!
*******************************************************************************
** \brief Version of the VIDEC driver.
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
**       FAPI_VIDEC_OpenParamsT structure.
**
*******************************************************************************
*/
typedef enum {
    //!   Current version number of the video driver.
    FAPI_VIDEC_VERSION = (int32_t)0x9000a, //0x00080009,
}FAPI_VIDEC_VersionEnumT;
/*!
*******************************************************************************
** \brief Informs the user the current aspect ratio.
** It is internal state of the decoder.
*******************************************************************************
*/
typedef enum {
    //!   Unknown aspect ratio.
    FAPI_VIDEC_AR_NONE = 0,
    //!   Aspect ratio is 4:3.
    FAPI_VIDEC_AR_4_3 = 1,
    //!   Aspect ratio is 14:9.
    FAPI_VIDEC_AR_14_9 = 2,
    //!   Aspect ratio is 16:9.
    FAPI_VIDEC_AR_16_9 = 3,
    //!   Aspect ratio is 221:100.
    FAPI_VIDEC_AR_221_100 = 4,
    //!   Aspect ratio is 235:100.
    FAPI_VIDEC_AR_235_100 = 5
}FAPI_VIDEC_AspectRatioEnumT;
/*!
*******************************************************************************
** \brief Informs the user if the video decoder is in resetState or any other
** intermediate state.
** It is internal state of the decoder.
*******************************************************************************
*/
typedef enum {
    //!   Unknown reset state before booting.
    FAPI_VIDEC_UNKNOWN_RESET_STATE = (int32_t)-1,
    //!   Non reset state, after reset is completed this state is the final state.
    FAPI_VIDEC_NOT_RESET, //0
    //!   Request to reset the video core and the driver as well.
    FAPI_VIDEC_REQUEST_TO_RESET, //1
    //!   Request to reset the video core and the driver as well is served
    //!   and now will return to FAPI_VIDEC_NOT_RESET state.
    FAPI_VIDEC_RESET_DONE //2
}FAPI_VIDEC_HardResetStatesEnumT;
/*!
*******************************************************************************
** \brief Informs the user if the video decoder is in bootState or any other
** intermediate state.
** It is internal state of the decoder.
*******************************************************************************
*/
typedef enum {
    //!   Not booted state.
    FAPI_VIDEC_NOT_BOOTED = (int32_t)-1,
    //!   Request to bootState the video core.
    FAPI_VIDEC_REQUEST_TO_BOOT,
    //!   Video core is in the booted state.
    FAPI_VIDEC_BOOTED
}FAPI_VIDEC_BootStateEnumT;
/*!
*******************************************************************************
** \brief Informs the user if the video decoder is in stop/start or any
** intermediate state.
** It is internal state of the decoder.
*******************************************************************************
*/
typedef enum {
    //!   Unknown start stop state.
    FAPI_VIDEC_UNKNOWN_START_STOP_STATE = (int32_t)-1,
    //!   Prepare to stop.
    FAPI_VIDEC_PREPARE_TO_STOP, //0
    //!   Request to stop.
    FAPI_VIDEC_REQUEST_TO_STOP, //1
    //!   Request to stop is served.
    FAPI_VIDEC_STOPPED, //2
    //!   Software Stop only. Video decoding stops after first I Frame decode.
    FAPI_VIDEC_STOPPED_AFTER_FIRST_IFRAME, //3
    //!   Prepare to start video decoder.
    FAPI_VIDEC_PREPARE_TO_START, //4
    //!   Request to start video decoding as well.
    FAPI_VIDEC_REQUEST_TO_START, //5
    //!   Request to start is served.
    FAPI_VIDEC_STARTED //6
}FAPI_VIDEC_StartStopStatesEnumT;
/*!
*******************************************************************************
** \brief Informs the user if the video decoder is in Enable/Disable state.
** It is internal state of the decoder.
*******************************************************************************
*/
typedef enum {
    //!   Unknown enable/disable state.
    FAPI_VIDEC_UNKNOWN_ENABLE_DISABLE_STATE = (int32_t)-1,
    //!   Request to synchronize enable with first decoded frame.
    FAPI_VIDEC_REQUEST_TO_SYNCHRONIZE_ENABLE, //0
    //!   Request to synchronize enable with first decoded frame is pending.
    FAPI_VIDEC_SYNCHRONIZE_ENABLING, //1
    //!   Request to synchronize enable with first decoded frame is served.
    FAPI_VIDEC_SYNCHRONIZE_ENABLED, //2
    //!   Request to forcefully enable on the next occuring Frame sync.
    FAPI_VIDEC_REQUEST_TO_FORCE_ENABLE, //3
    //!   Request to forcefully enable on the next occuring Frame sync is done.
    FAPI_VIDEC_FORCE_ENABLED, //4
    //!   Request to forcefully disable on the next occuring Frame sync.
    FAPI_VIDEC_REQUEST_TO_FORCE_DISABLE, //5
    //!   Request to forcefully disable on the next occuring Frame sync is done.
    FAPI_VIDEC_FORCE_DISABLED //6
}FAPI_VIDEC_EnableStatesEnumT;
/*!
*******************************************************************************
** \brief to Enable or Disable Video on the VO block.
** It is state of an user command.
*******************************************************************************
*/
typedef enum {
    /*! Enables the video to the VO block in sync with the first decoded frame
        while waiting for the first frame to be decoded. This parameter causes
        a timed blocking action.*/
    FAPI_VIDEC_ENABLE_SYNCHRONOUSLY_SUSPEND = (int32_t)-1,
    /*! Enables the video to the VO block in sync with the first decoded
        frame. This causes a non-blocking call*/
    FAPI_VIDEC_ENABLE_SYNCHRONOUSLY_NO_SUSPEND, //0
    //! Enables the video to the VO block on the subsequent VBI.
    FAPI_VIDEC_ENABLE_FORCE_ON, //1
    //! Disables the video to the VO block on the subsequent VBI.
    FAPI_VIDEC_ENABLE_FORCE_OFF //2
}FAPI_VIDEC_EnableDisableStateEnumT;
/*!
*******************************************************************************
** \brief to Freeze or Continue Video on the VO block.
** It is state of an user command.
*******************************************************************************
*/
typedef enum {
    //! Continues the video to the VO block.
    FAPI_VIDEC_FREEZE_OFF = (int32_t)0,
    //! Freezes the video to the VO block.
    FAPI_VIDEC_FREEZE_ON
}FAPI_VIDEC_FreezeContinueStateEnumT;
/*!
*******************************************************************************
** \brief Defines if video decoder큦 health.
*******************************************************************************
*/
typedef enum {
  /*! Specifies an unknown health of the Video decoder*/
  FAPI_VIDEC_UNKNOWN_HEALTH = (int32_t)-1,
  /*! Specifies good health as everything is running normally.*/
  FAPI_VIDEC_GOOD_HEALTH, //0
  /*! Specifies bad health of level 0, a reset is not required. Still VD is in recoverable state.*/
  FAPI_VIDEC_BAD_HEALTH_L0, //1
  /*! Specifies bad health of level 1, a reset is not required. Still VD is in recoverable state.*/
  FAPI_VIDEC_BAD_HEALTH_L1, //2
  /*! Specifies bad health of level 2, a reset is not required. Still VD is in recoverable state.*/
  FAPI_VIDEC_BAD_HEALTH_L2, //3
  /*! Specifies dead state, a complete reboot is required. VD is non-recoverable state.*/
  FAPI_VIDEC_DEAD //4
} FAPI_VIDEC_HealthStateEnumT;
/*!
*******************************************************************************
** \brief Defines the decoder number to be opened.
*******************************************************************************
*/
typedef enum {
  /*! Unonown decoder number*/
  FAPI_VIDEC_UNKNOWN_DECODER_NUMBER = (int32_t)-1,
  /*! Parameter to Open decoder number 0*/
  FAPI_VIDEC_DECODER_NUMBER_0 = 0
} FAPI_VIDEC_DecoderNumberEnumT;
/*!
*******************************************************************************
** \brief Types of Video Decoders supported are MPEG2,H.264,VC1 and AVS.
** Other decoding standards are not supported. The GetStatus shall also
** inform the user the current decoder type in use.
*******************************************************************************
*/
typedef enum {
    //!   Unknown type decoder
    FAPI_VIDEC_UNKNOWN_DECODER = (int32_t)0,
    //!   MPEG2 decoder Main profile , High Level
    FAPI_VIDEC_MPEG2_MPHL = 1,
    //!   H.264 decoder High profile , Level 4.1
    FAPI_VIDEC_H264_HP41 = 2,
    //!   VC1 decoder Advanced profile , Level 3
    FAPI_VIDEC_VC1_APL3 = 3,
    //!   AVS decoder , Level 6.0
    FAPI_VIDEC_AVS_L60 = 4
}FAPI_VIDEC_DecoderEnumT;
/*!
*******************************************************************************
** \brief Opening parameter for Video decoder core. Specifies the
** the size of picture to be decoded. The size is measured in pixels
** per horizontal line. It is used to configure internal frame banks.
*******************************************************************************
*/
typedef enum {
    //!   Unknown Frame bank Size
    FAPI_VIDEC_UNKNOWN_FRAME_BANK_SIZE = (int32_t)-1,
    //!   1920 pixels per one decoded picture line
    FAPI_VIDEC_FRAME_BANK_SIZE_1920HD = 0,
    //!   1440 pixels per one decoded picture line
    FAPI_VIDEC_FRAME_BANK_SIZE_1440HD = 1,
    //!   1280 pixels per one decoded picture line
    FAPI_VIDEC_FRAME_BANK_SIZE_1280HD = 2,
    //!   720 pixels per one decoded picture line
    FAPI_VIDEC_FRAME_BANK_SIZE_SD = 3
}FAPI_VIDEC_DecoderFrameBankSizeEnumT;
/*!
*******************************************************************************
** \brief Playback Mode for trick modes.
** It supports normal and I_ONLY modes.
*******************************************************************************
*/
typedef enum {
    //! Unknown playback mode.
    FAPI_VIDEC_UNKNOWN_PLAYBACK_MODE = (int32_t)-1,
    //! Pauses the playback in PVR environment otherwise the request is rejected.
    FAPI_VIDEC_PLAYBACK_PAUSE = 0,
    //! Continues to play the video normally.
    FAPI_VIDEC_NORMAL_PLAYBACK_MODE = 1,
    //! Displays only the first occuring I Frame.
    FAPI_VIDEC_FIRST_I_ONLY_PLAYBACK_MODE = 2,
    //! Continues to play the video in the trick mode I_ONLY.
    FAPI_VIDEC_I_ONLY_PLAYBACK_MODE = 3,
    /*! Continues to play the video in the trick mode skipping B frames.
        This mode is available for MPEG streams only.*/
    FAPI_VIDEC_I_AND_P_ONLY_PLAYBACK_MODE = 4,
    //! Continues to play the video in the trick mode slow forward 2 times.
    FAPI_VIDEC_SLOW_FORWARD_2X_PLAYBACK_MODE = 5,
    //! Continues to play the video in the trick mode slow forward 4 times.
    FAPI_VIDEC_SLOW_FORWARD_4X_PLAYBACK_MODE = 6,
    //! Continues to play the video in the trick mode slow forward 8 times.
    FAPI_VIDEC_SLOW_FORWARD_8X_PLAYBACK_MODE = 7
}FAPI_VIDEC_PlaybackModeEnumT;
/*!
*******************************************************************************
** \brief Opening parameter for Video decoder core. Specifies the
** the option of applying or not applying the AFD (Active format Descriptors)
** to the decoded picture.
*******************************************************************************
*/
typedef enum {
    /*!   Unknown user request on how to handle AFD data if present. if the
          state is unknown then video decoder shall fail to open.*/
    FAPI_VIDEC_UNKNOWN_AFD_STATE = (int32_t)-1,
    /*!   User defined Afd is 2.*/
    FAPI_VIDEC_AFD_ENABLE_2 = 2,
    /*!   User defined Afd is 3.*/
    FAPI_VIDEC_AFD_ENABLE_3 = 3,
    /*!   User defined Afd is 4.*/
    FAPI_VIDEC_AFD_ENABLE_4 = 4,
    /*!   User defined Afd is 8.*/
    FAPI_VIDEC_AFD_ENABLE_8 = 8,
    /*!   User defined Afd is 9.*/
    FAPI_VIDEC_AFD_ENABLE_9 = 9,
    /*!   User defined Afd is 10.*/
    FAPI_VIDEC_AFD_ENABLE_10 = 10,
    /*!   User defined Afd is 11.*/
    FAPI_VIDEC_AFD_ENABLE_11 = 11,
    /*!   User defined Afd is 13.*/
    FAPI_VIDEC_AFD_ENABLE_13 = 13,
    /*!   User defined Afd is 14.*/
    FAPI_VIDEC_AFD_ENABLE_14 = 14,
    /*!   User defined Afd is 15.*/
    FAPI_VIDEC_AFD_ENABLE_15 = 15,
    /*!   Afd process is executed as defined in the stream.*/
    FAPI_VIDEC_AFD_ENABLE_AUTO = 16,
    /*!   The AFD data application to the decoded picture shall be discarded
          in case the AFD data is present.*/
    FAPI_VIDEC_AFD_DISABLE = 17
}FAPI_VIDEC_AfdStateEnumT;
/*!
*******************************************************************************
** \brief Parameter for defining the PES parser that is to be associated with
** the video decoder.
*******************************************************************************
*/
typedef enum {
    /*!   Unknown pes parser.*/
    FAPI_VIDEC_UNKNOWN_PESPARSER = (int32_t)-1,
    /*!   No pes parser association. This would disable the synchronization.*/
    FAPI_VIDEC_NO_PESPARSER,
    /*!   The TSD01큦 Pes parser 0 is used for PTS extraction.*/
    FAPI_VIDEC_TSD01_PESPARSER_0,
    /*!   The TSD01큦 Pes parser 1 is used for PTS extraction.*/
    FAPI_VIDEC_TSD01_PESPARSER_1,
    /*!   The TSD01큦 Pes parser 2 is used for PTS extraction.*/
    FAPI_VIDEC_TSD01_PESPARSER_2,
    /*!   The TSD01큦 Pes parser 3 is used for PTS extraction.*/
    FAPI_VIDEC_TSD01_PESPARSER_3,
    /*!   The TSD23큦 Pes parser 0 is used for PTS extraction.*/
    FAPI_VIDEC_TSD23_PESPARSER_0,
    /*!   The TSD23큦 Pes parser 1 is used for PTS extraction.*/
    FAPI_VIDEC_TSD23_PESPARSER_1,
    /*!   The TSD23큦 Pes parser 2 is used for PTS extraction.*/
    FAPI_VIDEC_TSD23_PESPARSER_2,
    /*!   The TSD23큦 Pes parser 3 is used for PTS extraction.*/
    FAPI_VIDEC_TSD23_PESPARSER_3,
}FAPI_VIDEC_PesParserEnumT;
/*!
*******************************************************************************
** \brief Parameter for defining the environment of operation of
** the video decoder.
*******************************************************************************
*/
typedef enum {
    /*!   Live broadcast environment.*/
    FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT = 0,
    /*!   recorded live PVR environment.*/
    FAPI_VIDEC_PVR_PLAYBACK_ENVIRONMENT = 1
}FAPI_VIDEC_PlaybackEnvironmentEnumT;
/*!
*******************************************************************************
** \brief Parameter for defining the reset type of
** the video decoder.
*******************************************************************************
*/
typedef enum {
    /*!   Software reset of VD.*/
    FAPI_VIDEC_SOFT_RESET = 0,
    /*!   Hard reset of VD, It also causes internal rebooting.*/
    FAPI_VIDEC_HARD_RESET = 1
}FAPI_VIDEC_ResetEnumT;
/*!
*******************************************************************************
** \brief Parameter for defining the reset type of
** the video decoder.
*******************************************************************************
*/
typedef enum {
    /*!   Set mode to normal where the data is fed via TSD.*/
    FAPI_VIDEC_NON_MPEG_IFRAME_MODE = 0,
    /*!   Set mode to Mpeg I frame where the data is fed directly into ES buffer.*/
    FAPI_VIDEC_MPEG_IFRAME_MODE = 1
}FAPI_VIDEC_MpegIFrameModeEnumT;
/*
*******************************************************************************
** \brief Defines if video decoder is to handle progressive or
** Interlace coded material.
*******************************************************************************
*/
typedef enum {
  /* Specifies an unknown interlace or progressive video decoder*/
  FAPI_VIDEC_UNKNOWN_IP = (int32_t)-1,
  /* Interlace decoding mode of video decoder*/
  FAPI_VIDEC_IP_INTERLACE, //0
  /* Progressive decoding mode of video decoder*/
  FAPI_VIDEC_IP_PROGRESSIVE //1
} FAPI_VIDEC_InterlaceProggStateT;

typedef enum {
   Enum_200_a = (int32_t)-1,
   Enum_200_0, //0
} Enum_200;

typedef enum {
   Enum_120_0, //0
   Enum_120_1, //1
} Enum_120;



//*****************************************************************************
//*****************************************************************************
//** Data Structures
//*****************************************************************************
//*****************************************************************************
/*!
*******************************************************************************
** \brief Opening parameters for a Video Decoder.
** It has fields for Video decoder number and decoder type. The
** "decoderNumber" field runs from 0 to Maximum number of Video
** decoders supported.
** The field "decoderType" can be any one of the following:
*******************************************************************************
*/
typedef struct {
    /*! The version of the driver.
    ** \ref FAPI_VIDEC_VersionEnumT "FAPI_VIDEC_VERSION".
    */
    FAPI_VIDEC_VersionEnumT              version; //0
    //! Decoder number to be opened or Index
    FAPI_VIDEC_DecoderNumberEnumT        decoderNumber; //4
    //! Open decoder to decode a stream of this type.
    FAPI_VIDEC_DecoderEnumT              decoderType; //8
    //! Open decoder to decode a stream of this maximum horizontal size.
    FAPI_VIDEC_DecoderFrameBankSizeEnumT decodeFrameBankSizeType; //12
    //! This mode parameter is used for entering or exiting trickmodes.
    FAPI_VIDEC_PlaybackModeEnumT         decoderPlaybackMode; //16
    //! This mode parameter is used for defining live or pvr playback environment.
    FAPI_VIDEC_PlaybackEnvironmentEnumT  decoderPlaybackEnvironment; //20
    //! Option to enable or disable AFD application.
    FAPI_VIDEC_AfdStateEnumT             decoderAfdState; //24
    Enum_120                             Data_28; //28
    
}FAPI_VIDEC_OpenParamsT;
/*!
*******************************************************************************
** \brief Video elementary stream (VES) parameters of a known pid stream.
** The following parameters are updated on invoking the relevant call.
** It is used to know the VES parameters after entropy decoding and then
** if necessary the video decoder can be restarted in correct mode.
*******************************************************************************
*/
typedef struct {
    //! Average  of the stream큦 bitrate
    uint32_t                             vesAverageBitRate; //0
    //! currentbitrate averaged over last 1 second
    uint32_t                             vesCurrBitRate; //4
    //! Aspect Ratio of current decoded frame
    FAPI_VIDEC_AspectRatioEnumT          vesAspectRatio; //8
    //! Frame rate.
    uint32_t                             vesFrameRate; //12
    //! Decoder Latency of video decoding pipeline.
    int64_t                              vesDecoderLatency; //16
    //! This mode parameter is used to define interlace or progressive modes.
    uint32_t                             proggInter; //24
    //! Width of display picture in pixels
    uint32_t                             displayWidth; //28
    //! Width of display picture in pixels
    uint32_t                             displayHeight; //32
    //! Width of current decoded frame in pixels
    uint32_t                             decodedWidth; //36
    //! Height of current decoded frame in lines
    uint32_t                             decodedHeight; //40
    //44
}FAPI_VIDEC_VESParamsT;
/*!
*******************************************************************************
** \brief Status parameters for a Video Decoder.
** These parameters shall be updated on invoking. It can
** also be used to determine the decoder capabilities and the current
** state for diagnostic purposes.
*******************************************************************************
*/
typedef struct {

    /*! Firmware version of the video firmware as in flash.
        The firmware version in the flash is available only if the video decoder
        is already booted.
    */
    uint32_t                             firmwareVersionInFlash; //0
    //! Firmware version of the video firmware that is supported by fapi.
    uint32_t                             firmwareVersionSupported; //4
    //! Decoder type.
    FAPI_VIDEC_DecoderEnumT              decoderType; //8
    //! Memory layout for a maximum sized frame.
    FAPI_VIDEC_DecoderFrameBankSizeEnumT decodeFrameBankSizeType; //12
    //! Width of display picture in pixels
    uint32_t                             displayWidth; //16
    //! Width of display picture in pixels
    uint32_t                             displayHeight; //20
    //! Width of current decoded frame in pixels
    uint32_t                             decodedWidth; //24
    //! Height of current decoded frame in lines
    uint32_t                             decodedHeight; //28
    //! Aspect Ratio of current decoded frame
    FAPI_VIDEC_AspectRatioEnumT          aspectRatio; //32
    //! Aspect Ratio of current decoded frame큦 active video region.
    FAPI_VIDEC_AspectRatioEnumT          activeAspectRatioL0; //36
    //! Aspect Ratio of current decoded frame큦 active video region큦 shoot & protect region.
    FAPI_VIDEC_AspectRatioEnumT          activeAspectRatioL1; //40

    FAPI_VIDEC_InterlaceProggStateT      codedInterlaceProggState; //44
    FAPI_VIDEC_InterlaceProggStateT      readoutInterlaceProggState; //48
    //! AFD associated with the current frame.
    uint32_t                             currAfd; //52
    //Stream variables
    /*! Average bit rate of Video elementary stream in bits per second
        It is averaged since the start of video stream*/
    uint32_t                             vesAverageBitRate; //56
    /*! Current bit rate of Video elementary stream in bits per second
        It is averaged over the last 5 pictures.*/
    uint32_t                             vesCurrBitRate; //60
    /*! Frame rate of the input video elementary stream.*/
    uint32_t                             vesFrameRate; //64    
    //State variables
    //! Boot State
    FAPI_VIDEC_BootStateEnumT            bootState; //68 60
    //! Reset State
    FAPI_VIDEC_HardResetStatesEnumT      resetState; //72 64
    //! Enable State
    FAPI_VIDEC_EnableStatesEnumT         enableState; //76 68
    //! Start State
    FAPI_VIDEC_StartStopStatesEnumT      startState; //80 72
    //! Freeze State
    FAPI_VIDEC_FreezeContinueStateEnumT  freezeState; //84?
    //! Health State
    FAPI_VIDEC_HealthStateEnumT          healthState; //88
    uint32_t Data_92; 
    Enum_200 Data_96;
}FAPI_VIDEC_GetStateT;
/*!
*******************************************************************************
** \brief Status parameters for a Video frame.
** These patameters are updated and the call back API is called.
** This provides the parameters that are obtained after Entropy decoding.
*******************************************************************************
*/
typedef struct {
    uint32_t                             serialNum; //0 705416

    uint32_t                             afdUserDataActiveFormatFlag; //4 705420
    uint32_t                             currAfd; //8 705424

    uint32_t                             ccUserDataProcessCcDataFlag; //12 705428
    uint32_t                             ccUserDataCcCount; //16 705432
    uint32_t                             ccUserDataCcValid[32]; //20 705436
    uint32_t                             ccUserDataCcType[32]; //148
    uint32_t                             ccUserDataCcData1[32]; //276
    uint32_t                             ccUserDataCcData2[32]; //404

    uint32_t                             barUserDataTopBarFlag; //532 705948
    uint32_t                             barUserDataEndOfTopBar; //536 705952
    uint32_t                             barUserDataBotBarFlag; //540 705956
    uint32_t                             barUserDataStartOfBotBar; //544 705960
    uint32_t                             barUserDataLeftBarFlag; //548 705964
    uint32_t                             barUserDataEndOfLeftBar; //552 705968
    uint32_t                             barUserDataRightBarFlag; //556 705972
    uint32_t                             barUserDataStartOfRightBar; //560 705976

    uint32_t                             MPEG2HorizontalSizeValue; //564 705980
    uint32_t                             MPEG2VerticalSizeValue; //568
    uint32_t                             MPEG2AspectRatioInformation; //572
    uint32_t                             MPEG2ProgressiveSequence; //576
    uint32_t                             MPEG2ChromaFormat; //580
    uint32_t                             MPEG2DisplayHorizontalSize; //584
    uint32_t                             MPEG2DisplayVerticalSize; //588
    uint32_t                             MPEG2ClosedGop; //592
    uint32_t                             MPEG2BrokenLink; //596
    uint32_t                             MPEG2PictureCodingType; //600
    uint32_t                             MPEG2PictureStructure; //604
    uint32_t                             MPEG2TopFieldFirst; //608
    uint32_t                             MPEG2RepeatFirstField; //612
    uint32_t                             MPEG2ProgressiveFrame; //616
    uint32_t                             MPEG2FieldSequence; //620

    uint32_t                             H264PicStructurePresentFlag;
    uint32_t                             H264PicStructure;
    uint32_t                             H264BrokenLinkFlag;
    uint32_t                             H264NalUnitType;
    uint32_t                             H264PicWidthInMbsMinus1;
    uint32_t                             H264FrameHeightInMbs;
    uint32_t                             H264ProfileIdc;
    uint32_t                             H264LevelIdc;
    uint32_t                             H264FrameNum;
    uint32_t                             H264TopFieldOrderCount;
    uint32_t                             H264BotFieldOrderCount;
    uint32_t                             H264FieldPicFlag;
    uint32_t                             H264BotFieldFlag;
    uint32_t                             H264AspectRatioInfoPresentFlag;
    uint32_t                             H264AspectRatioIdc;
    uint32_t                             H264SarWidth;
    uint32_t                             H264SarHeight;
    uint32_t                             H264ChromaLocInfoPresentFlag;
    uint32_t                             H264ChromaSampleLocTypeTopField;
    uint32_t                             H264ChromaSampleLocTypeBotField;
}FAPI_VIDEC_EntropyDecInfoStateT;
/*!
*******************************************************************************
** \brief Status parameters for a Video frame.
** These patameters are updated and the call back API is called.
** This provides the parameters that are obtained after video decoding.
*******************************************************************************
*/
typedef struct {
    int32_t                              rPtr; //0
    uint32_t                             serialNum; //4
    uint32_t                             frameBank; //8
    uint32_t                             displayWidth; //12
    uint32_t                             displayHeight; //16
    uint32_t                             decodedWidth; //20
    uint32_t                             decodedHeight; //24
    uint32_t                             displayOrderInfo; //28
    uint32_t                             topFieldSerialNo; //32
    uint32_t                             botFieldSerialNo; //36
    uint32_t                             ptsValidFlag; //40
    uint32_t                             dtsValidFlag; //44
    uint64_t                             pts; //48
    uint64_t                             dts; //56
    //64
}FAPI_VIDEC_VideoDecInfoStateT;
/*!
*******************************************************************************
** \brief Status parameters for a Video frame.
** These patameters are updated and the call back API is called.
** This provides the parameters that are obtained after video decoding.
*******************************************************************************
*/
typedef struct {
    FAPI_VIDEC_AspectRatioEnumT          aspectRatio;
    uint32_t                             frameField;
    uint32_t                             fieldInversion;
    uint32_t                             decodedWidth;
    uint32_t                             decodedHeight;
}FAPI_VIDEC_FrameInfoStateT;

/*!
*******************************************************************************
** \brief Type definition of the entropy decoding callback function.
** This function prototype is used for calling the entropy decoding
** callback functions.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_EntropyDecInfoCallbackT)(
                            FAPI_VIDEC_EntropyDecInfoStateT* entropyDecInfoPtr,
                                                         void* entropyOptData);
/*!
*******************************************************************************
** \brief Type definition of the video decoding, video callback function.
** This function prototype is used for calling the video decoding
** callback functions.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_VideoDecInfoCallbackT)(
                                FAPI_VIDEC_VideoDecInfoStateT* videoDecInfoPtr,
                                                           void* videoOptData);
/*!
*******************************************************************************
** \brief Type definition of the Auto Scaling callback function.
** This function prototype is used for calling the
** Auto Scaling callback functions.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_AutoScaleCallbackT)(void* frameCropPtr,
                                                 FAPI_SYS_HandleT scalerHandle,
                                                         uint32_t suspendType);
/*!
*******************************************************************************
** \brief Type definition of the stream info callback function.
** This function prototype is used for intimating the user if the stream is
** decodable or not. If the stream is decodable then it is called just after
** the first frame is decoded. This callback is called out of ISR context,
** so careful processing should be carried out within this callback.
** After the callback is called it clears itself internally, so it shall
** be called only once and would require another set call.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_FrameDecodedCallbackT)(void* frameDecodedOptData);
/*!
*******************************************************************************
** \brief Type definition of the stream info callback function.
** This function prototype is used for intimating the user if the stream is
** decodable or not. If the stream is decodable then it is called just before
** the first frame is displayed. This callback is called out of ISR context,
** so careful processing should be carried out within this callback.
** After the callback is called it clears itself internally, so it shall
** be called only once and would require another set call.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_FrameAvailableCallbackT)(void* frameAvailableOptData);
/*!
*******************************************************************************
** \brief Type definition of the stream info callback function.
** This function prototype is used for intimating the user if the stream in
** the Video Elementary stream buffer has overflowed.
** This callback is called out of ISR context,
** so careful processing should be carried out within this callback.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_VesOverflowCallbackT)(void* vesOverflowOptData);
/*!
*******************************************************************************
** \brief Type definition of the picture parameter change callback function.
** This function prototype is used for intimating the user if the picture size
** or it큦 aspect ratio has changed with respect to the last picture.
** This callback is called out of ISR context,
** so careful processing should be carried out within this callback.
** This function is used to set the call back which shall be called
** in case the picture parameters change. The callback shall be called 
** out of ISR context so no blocking or time consuming processing should be done.
** Preferably only initiation of Signal or events are allowed. Extreme care is 
** suggested for non-blocking system calls and blocking or timed-blocking system
** calls are forbidded. Furthermore this callback should not contain any
** critical section.
*******************************************************************************
*/
typedef void(*FAPI_VIDEC_ParamChangeCallbackT)(
                                  FAPI_VIDEC_FrameInfoStateT* nextFrameInfoPtr,
                                  FAPI_VIDEC_FrameInfoStateT* lastFrameInfoPtr,
                                                     void* paramChangeOptData);

//*****************************************************************************
//*****************************************************************************
//** Local defines
//*****************************************************************************
//*****************************************************************************
#define FAPI_VIDEC_AfdEnableDisableEnumT               FAPI_VIDEC_AfdStateEnumT
#define decoderAfdEnableDisable                                 decoderAfdState

//*****************************************************************************
//*****************************************************************************
//** Global Data
//*****************************************************************************
//*****************************************************************************
extern FAPI_SYS_DriverT FAPI_VIDEC_Driver0;
extern FAPI_SYS_DriverT FAPI_VIDEC_Driver1;
//*****************************************************************************
//*****************************************************************************
//** API Functions
//*****************************************************************************
//*****************************************************************************
#ifdef __cplusplus
extern "C" {
#endif

    void func_21c42e8c(int, int, int, int);

    void               FAPI_VIDEC_PreInit(const FAPI_VIDEC_DecoderNumberEnumT
                                                      piMemoryForDecoderNumber,
                                        const uint32_t piMemoryAllocationType);
    int32_t            FAPI_VIDEC_GetPreInitError(
                                          const FAPI_VIDEC_DecoderNumberEnumT
                                                     piMemoryForDecoderNumber);
    int32_t            FAPI_VIDEC_GetFirmwareVersion(
                                     const FAPI_VIDEC_DecoderEnumT decoderType,
                                                    uint32_t* firmwareVersion);
    int32_t            FAPI_VIDEC_Init(void);
    void               FAPI_VIDEC_Exit(void);
    uint32_t           FAPI_VIDEC_IsrDecode0(void);
    void               FAPI_VIDEC_BsrDecode0(uint32_t arg);
    uint32_t           FAPI_VIDEC_IsrDisplay0(void);
    void               FAPI_VIDEC_BsrDisplay0(uint32_t arg);
    int32_t            FAPI_VIDEC_ReportMemory(void);
    FAPI_SYS_HandleT   FAPI_VIDEC_Open(const FAPI_VIDEC_OpenParamsT* paramsPtr,
                                                        int32_t* errorCodePtr);
    int32_t            FAPI_VIDEC_Close(FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_Reset(FAPI_SYS_HandleT handle,
                                              FAPI_VIDEC_ResetEnumT resetType);
    int32_t            FAPI_VIDEC_FreezeContinue(FAPI_SYS_HandleT handle,
                             FAPI_VIDEC_FreezeContinueStateEnumT freezeSwitch);
    int32_t            FAPI_VIDEC_Start(FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_Stop(FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_EnableDisable(FAPI_SYS_HandleT handle,
                              FAPI_VIDEC_EnableDisableStateEnumT enableSwitch);
    int32_t            FAPI_VIDEC_SetPlaybackMode(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_PlaybackModeEnumT mode);
    int32_t            FAPI_VIDEC_SetPlaybackEnvironment(
                                                       FAPI_SYS_HandleT handle,
                                     FAPI_VIDEC_PlaybackEnvironmentEnumT mode);
    int32_t            FAPI_VIDEC_GetVesParams(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_VESParamsT* vesParamsPtr,
                                                         uint32_t suspendType);
    int32_t            FAPI_VIDEC_GetVesBufferPosition(FAPI_SYS_HandleT handle,
                                                          uint32_t* bufferPtr);
    int32_t            FAPI_VIDEC_GetVesBufferSize(FAPI_SYS_HandleT handle,
                                                         uint32_t* bufferSize);
    int32_t            FAPI_VIDEC_GetVesFillLevel(FAPI_SYS_HandleT handle,
                                                          uint32_t* fillLevel);
    int32_t            FAPI_VIDEC_GetVesAvailableSpace(FAPI_SYS_HandleT handle,
                                                     uint32_t* availableSpace);
    int32_t            FAPI_VIDEC_GetState(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_GetStateT* getStatePtr);
    int32_t            FAPI_VIDEC_GetHealth(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_HealthStateEnumT* health);
    int32_t            FAPI_VIDEC_GetDecodingLatency(FAPI_SYS_HandleT handle,
                                               int64_t* decoderLatencyInTicks);
    void               FAPI_VIDEC_AudCallback(uint32_t audNum ,
                              uint32_t audSearchPattern, uint32_t foundPtr,
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_Recover(FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_DecodeSingleMpegIFrame(
                                                       FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes);
    int32_t            FAPI_VIDEC_DisplaySingleMpegIFrame(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_DecodeSequenceOfMpegIFrame(
                                                       FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes);
    int32_t            FAPI_VIDEC_DisplaySequenceOfMpegIFrame(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_SetEntropyDecInfoCallback(
                                                       FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_EntropyDecInfoCallbackT
                                                entropyDecInfoCallbackFunction,
                                                         void* entropyOptData);
    int32_t            FAPI_VIDEC_SetVideoDecInfoCallback(
                                                       FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_VideoDecInfoCallbackT
                                                  videoDecInfoCallbackFunction,
                                                           void* videoOptData);
    int32_t            FAPI_VIDEC_SetAutoScaleCallback(FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_AutoScaleCallbackT
                                                     autoScaleCallbackFunction,
                                                           void* scalerHandle);
    int32_t            FAPI_VIDEC_SetDecoderToHdEncoder(
                                                       FAPI_SYS_HandleT handle,
                                               FAPI_SYS_HandleT viencHdHandle);
    int32_t            FAPI_VIDEC_SetPesParserToDecoder(
                                                       FAPI_SYS_HandleT handle,
                                       FAPI_VIDEC_PesParserEnumT pesParserNum);
    int32_t            FAPI_VIDEC_SetFrameDecodedCallback(
                                                       FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_FrameDecodedCallbackT
                                                  frameDecodedCallbackFunction,
                                                    void* frameDecodedOptData);
    int32_t            FAPI_VIDEC_SetFrameAvailableCallback(
                                                       FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_FrameAvailableCallbackT
                                                frameAvailableCallbackFunction,
                                                  void* frameAvailableOptData);
    int32_t            FAPI_VIDEC_SetVesOverflowCallback(
                                                       FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_VesOverflowCallbackT
                                                   vesOverflowCallbackFunction,
                                                     void* vesOverflowOptData);
    int32_t            FAPI_VIDEC_SetMpegIFrameMode(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_MpegIFrameModeEnumT mode);
    int32_t            FAPI_VIDEC_SetChannelId(FAPI_SYS_HandleT handle,
                                                           uint32_t blockIndex,
                                                           uint32_t channelId);
    int32_t            FAPI_VIDEC_SetParamChangeCallback(
                                                       FAPI_SYS_HandleT handle,
                                      FAPI_VIDEC_ParamChangeCallbackT
                                                   paramChangeCallbackFunction,
                                                     void* paramChangeOptData);
    int32_t            FAPI_VIDEC_SetAfdState(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_AfdStateEnumT afdState);
    int32_t            FAPI_VIDEC_ClearEntropyDecInfoCallback(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearVideoDecInfoCallback(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearAutoScaleCallback(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearDecoderToHdEncoder(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearPesParserToDecoder(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearFrameDecodedCallback(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearFrameAvailableCallback(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearVesOverflowCallback(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearMpegIFrameMode(
                                                      FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearChannelId(FAPI_SYS_HandleT handle);
    int32_t            FAPI_VIDEC_ClearParamChangeCallback(
                                                      FAPI_SYS_HandleT handle);

    //Functions for debugging
    void               dump_pcpu_memory(void);

#ifdef __cplusplus
}
#endif
#endif




