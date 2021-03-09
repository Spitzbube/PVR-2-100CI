/*!
*****************************************************************************
**
** \file        ./fapi/drv/viscale/src/drv_viscale.h
**
** \brief       Video Scaler Driver.
**
** This file contains the declaration of the Video Scaler driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/
#ifndef FAPI_VISCALE_H
    #define FAPI_VISCALE_H

#include <fapi/sys_driver.h>

//***********************************************************************
//***********************************************************************
//** Defines and Macros
//***********************************************************************
//***********************************************************************
/*
*************************************************************************
** Defines for general error codes of the module.
*************************************************************************
*/
/*! Bad parameter passed. */
#define FAPI_VISCALE_ERR_BAD_PARAMETER                                  \
                      (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_BAD_PARAMETER)
/*! Memory allocation failed. */
#define FAPI_VISCALE_ERR_OUT_OF_MEMORY                                  \
                      (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_OUT_OF_MEMORY)
/*! Device already initialised. */
#define FAPI_VISCALE_ERR_ALREADY_INITIALIZED                            \
                (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_ALREADY_INITIALIZED)
/*! Device not initialised. */
#define FAPI_VISCALE_ERR_NOT_INITIALIZED                                \
                    (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_NOT_INITIALIZED)
/*! Feature or function is not available. */
#define FAPI_VISCALE_ERR_FEATURE_NOT_SUPPORTED                          \
              (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_FEATURE_NOT_SUPPORTED)
/*! Timeout occured. */
#define FAPI_VISCALE_ERR_TIMEOUT                                        \
                            (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_TIMEOUT)
/*! The device is busy, try again later. */
#define FAPI_VISCALE_ERR_DEVICE_BUSY                                    \
                        (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_DEVICE_BUSY)
/*! Invalid handle was passed. */
#define FAPI_VISCALE_ERR_INVALID_HANDLE                                 \
                     (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_INVALID_HANDLE)
/*! Semaphore could not be created. */
#define FAPI_VISCALE_ERR_SEMAPHORE_CREATE                               \
                   (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_SEMAPHORE_CREATE)
/*! The driver's used version is not supported. */
#define FAPI_VISCALE_ERR_UNSUPPORTED_VERSION                            \
                (FAPI_VISCALE_MODULE_BASE + FAPI_ERR_UNSUPPORTED_VERSION)
/*
*************************************************************************
** Defines for specialized error codes which are very specific
** to the behaviour of this module. These codes are offset by -100 from
** the module´s general error codes.
*************************************************************************
*/
/*!
*************************************************************************
** \brief Error base for VISCALE Driver.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_BASE                                           \
                                         (FAPI_VISCALE_MODULE_BASE - 100)
/*!
*************************************************************************
** \brief Driver version mismatched. Driver update is required.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_DRV_VERSION_CHECK_FAILED                       \
                                            (FAPI_VISCALE_ERR_BASE -   1)
/*!
*************************************************************************
** \brief Opening/scaling params are wrong. Recheck open/scaler params.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_INVALID_INITIALIZATION_PARAMS                  \
                                            (FAPI_VISCALE_ERR_BASE -   2)
/*!
*************************************************************************
** \brief Opening params are wrong. Recheck open params.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_INVALID_OPEN_PARAMS                            \
                                            (FAPI_VISCALE_ERR_BASE -   3)
/*!
*************************************************************************
** \brief Wrong scaling used.
**  Check again the scaler params.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_INVALID_SCALER_PARAMS                          \
                                            (FAPI_VISCALE_ERR_BASE -   4)
/*!
*************************************************************************
** \brief Illogical combination of open params was used.
**  Recheck open params.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_INVALID_COMBINATION_OF_OPEN_PARAMS             \
                                            (FAPI_VISCALE_ERR_BASE -   5)
/*!
*************************************************************************
** \brief Opening multiple instances of driver for the given HW block.
**  First close and then reopen again.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_EXCEEDED_MAX_HANDLES                           \
                                            (FAPI_VISCALE_ERR_BASE -   6)
/*!
*************************************************************************
** \brief This functionality is not supported by the given HW Block.
**  Wrong handle to the HW block was used.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_UNSUPPORTED_FUNCTIONALITY                      \
                                            (FAPI_VISCALE_ERR_BASE -   7)
/*!
*************************************************************************
** \brief Internal check to verify the handle failed.
**  Wrong parameters was used.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_HANDLE_CHECK_FAILED                            \
                                            (FAPI_VISCALE_ERR_BASE -   8)
/*!
*************************************************************************
** \brief Current operation could not be performed, as it may be blocked.
**  Use the related API to enable this functionality.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_HANDLE_OPERATION_BLOCKED                       \
                                            (FAPI_VISCALE_ERR_BASE -   9)
/*!
*************************************************************************
** \brief Wrong handle used.
**  Check again the handle, maybe another handle is expected.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_WRONG_HANDLE                                   \
                                            (FAPI_VISCALE_ERR_BASE -  10)
/*!
*************************************************************************
** \brief Operation has timesout.
**  Check if viscale ISR is being called & a operation request is pending.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_OPERATION_TIMEOUT                              \
                                            (FAPI_VISCALE_ERR_BASE -  11)
/*!
*************************************************************************
** \brief One of the parameter has exceede the premissible max value.
**  Check the maximum value attained by the arguments.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_EXCEEDED_MAX_VALUE                             \
                                            (FAPI_VISCALE_ERR_BASE -  12)
/*!
*************************************************************************
** \brief Opening multiple instances of driver for the given HW block.
**  First close and then reopen again.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_ISR_STATE_MACHINE_ALLOCATION_FAILURE           \
                                           (FAPI_VISCALE_ERR_BASE -   13)
/*!
*************************************************************************
** \brief in valid scaling method.
** Change to correct scaling method.
*************************************************************************
*/
#define FAPI_VISCALE_ERR_INVALID_SCALING_METHOD                         \
                                           (FAPI_VISCALE_ERR_BASE -   14)

//***********************************************************************
//***********************************************************************
//** Enumerated types
//***********************************************************************
//***********************************************************************
/*!
*************************************************************************
** \brief Version of the VISCALE driver.
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
**       FAPI_VISCALE_OpenParamsT structure.
**
*************************************************************************
*/
typedef enum {
    FAPI_VISCALE_VERSION = (int32_t)0x00030002   //!< The current driver version
}FAPI_VISCALE_VersionEnumT;
/*!
****************************************************************************
** \brief to get, Set, Inc , or Decrease the level
****************************************************************************
*/
typedef enum {
    //! Returns the parameters
    FAPI_VISCALE_PARAMETER_GET = (int32_t)0,
    //! Applies the parameters
    FAPI_VISCALE_PARAMETER_SET, //1
    //! Increase by step size as specified
    FAPI_VISCALE_PARAMETER_INCREASE, //2
    //! decrease by step size as specified
    FAPI_VISCALE_PARAMETER_DECREASE, //3
    //! Turns on a specified parameter or feature
    FAPI_VISCALE_PARAMETER_ON, //4
    //! Turns off a specified parameter or feature
    FAPI_VISCALE_PARAMETER_OFF //5
}FAPI_VISCALE_ParameterModeEnumT;
/*!
*************************************************************************
** \brief Open parameters for the Video Scaler driver.
** This enumerrated type specifies the type encoder in use when the
** resizing is to be done.
*************************************************************************
*/
typedef enum {
    //! Unknown encoder
    FAPI_VISCALE_UNKNOWN_ENCODER = (int32_t)-1,
    //! Scaling for PAL encoder
    FAPI_VISCALE_ENCODER_PAL, //0
    //! Scaling for NTSC encoder
    FAPI_VISCALE_ENCODER_NTSC, //1
    //! Scaling for SECAM encoder
    FAPI_VISCALE_ENCODER_SECAM //2
}FAPI_VISCALE_EncoderEnumT;
/*!
*************************************************************************
** \brief Open parameters for the Video Scaler driver.
** This enumerrated type specifies the type encoder in use when the
** resizing is to be done.
*************************************************************************
*/
typedef enum {
    //! Unknown scaler
    FAPI_VISCALE_UNKNOWN_SCALER = (int32_t)-1,
    //! Video scaler
    FAPI_VISCALE_SCALER_VIDEO, //0
    //! OSD1 scaler
    FAPI_VISCALE_SCALER_OSD1, //1
    //! OSD2 scaler
    FAPI_VISCALE_SCALER_OSD2, //2
    //! SD scaler
    FAPI_VISCALE_SCALER_SD, //3
    //! Cursor Plane
    FAPI_VISCALE_SCALER_CURSOR_PLANE //4
}FAPI_VISCALE_ScalerEnumT;
/*!
****************************************************************************
** \brief This qualifier describes the organization of OSD data int he memory
****************************************************************************
*/
typedef enum {
    //! Unknown layout format of OSD in memory
    FAPI_VISCALE_UNKNOWN_OSD_LAYOUT = (int32_t)-1,
    //! RGB mode with alpha as most significant byte
    FAPI_VISCALE_OSD_LAYOUT_ARGB = 1,
    //! RGB mode with alpha as least significant byte
    FAPI_VISCALE_OSD_LAYOUT_RGBA = 2,
    //! CrYCb mode with alpha as most significant byte
    FAPI_VISCALE_OSD_LAYOUT_ACbYCr = 3,
    //! CrYCb mode with alpha as least significant byte
    FAPI_VISCALE_OSD_LAYOUT_CbYCrA = 4
}FAPI_VISCALE_OsdLayoutEnumT;
/*!
****************************************************************************
** \brief OSD Modes enumerated type
****************************************************************************
*/
typedef enum {
    //! Unuknown Mode
    FAPI_VISCALE_UNKNOWN_OSD_MODE = (int32_t)15,
    //! Tru colour 32 or 24 bit OSD
    FAPI_VISCALE_OSD_MODE_32_24BIT = 0,
    //! Tru colour 16 bit 5551 OSD
    FAPI_VISCALE_OSD_MODE_5551 = 1,
    //! Tru colour 14 bit 444 OSD
    FAPI_VISCALE_OSD_MODE_4444 = 2,
    //! 16 bit
    FAPI_VISCALE_OSD_MODE_16BIT = 4,
    //! 4 bit clut
    FAPI_VISCALE_OSD_MODE_CLUT_4BIT = 10,
    //! 8 bit clut
    FAPI_VISCALE_OSD_MODE_CLUT_8BIT = 11
}FAPI_VISCALE_OsdModeEnumT;
/*!
****************************************************************************
** \brief Cursor Plane Modes enumerated type
****************************************************************************
*/
typedef enum {
    //! Unknown mode
    FAPI_VISCALE_UNKNOWN_CURSOR_MODE = (int32_t)4,
    //! 1 bit Cursor
    FAPI_VISCALE_CURSOR_MODE_1BIT = 0,
    //! 2 bit Cursor
    FAPI_VISCALE_CURSOR_MODE_2BIT, //1
    //! 4 bit Cursor
    FAPI_VISCALE_CURSOR_MODE_4BIT, //2
    //! 8 bit Cursor
    FAPI_VISCALE_CURSOR_MODE_8BIT, //3
}FAPI_VISCALE_CursorModeEnumT;
/*!
****************************************************************************
** \brief Enumerated type to fade-in or fade-out video
****************************************************************************
*/
typedef enum {
    //! For fading in video
    FAPI_VISCALE_VIDEO_FADE_IN = (int32_t)0,
    //! For fading out video
    FAPI_VISCALE_VIDEO_FADE_OUT //1
}FAPI_VISCALE_VideoFadingModeEnumT;
/*!
****************************************************************************
** \brief Enumeration type for system mode.
****************************************************************************
*/
typedef enum {
    //! Unknown system mode.
    FAPI_VISCALE_UNKNOWN_SYSTEM_MODE = 0,
    //! System mode is 1920x1080p at 23.97 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x2397P = 1,
    //! System mode is 1920x1080p at 24 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x24P = 2,
    //! System mode is 1920x1080p at 25 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x25P = 3,
    //! System mode is 1920x1080p at 29.97 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x2997P = 4,
    //! System mode is 1920x1080p at 30 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x30P = 5,
    //! System mode is 1920x1080i at 50 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x50I = 6,
    //! System mode is 1920x1080i at 59.94 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x5994I = 7,
    //! System mode is 1920x1080i at 60 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1920x1080x60I = 8,
    //! System mode is 1280x720p at 23.97 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x2397P = 9,
    //! System mode is 1280x720p at 24 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x24P = 10,
    //! System mode is 1280x720p at 25 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x25P = 11,
    //! System mode is 1280x720p at 29.97 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x2997P = 12,
    //! System mode is 1280x720p at 30 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x30P = 13,
    //! System mode is 1280x720p at 50 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x50P = 14,
    //! System mode is 1280x720p at 59.94 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x5994P = 15,
    //! System mode is 1280x720p at 60 Hz.
    FAPI_VISCALE_SYSTEM_MODE_1280x720x60P = 16,
    //! System mode is 720x576i at 50 Hz.
    FAPI_VISCALE_SYSTEM_MODE_720x576x50I = 17,
    //! System mode is 720x576p at 50 Hz.
    FAPI_VISCALE_SYSTEM_MODE_720x576x50P = 18,
    //! System mode is 720x480i at 59.94 Hz.
    FAPI_VISCALE_SYSTEM_MODE_720x480x5994I = 19,
    //! System mode is 720x480p at 59.94 Hz.
    FAPI_VISCALE_SYSTEM_MODE_720x480x5994P = 20,
    //! System mode is 720x480i at 59.94 Hz.
    FAPI_VISCALE_SYSTEM_MODE_LCD_640x480x50P_LQ080V3DG01 = 21,
    //! System mode is 720x480p at 59.94 Hz.
    FAPI_VISCALE_SYSTEM_MODE_LCD_1024x768x50P_SVA150XG10TB = 22
}FAPI_VISCALE_SystemModeEnumT;
/*!
****************************************************************************
** \brief Enumeration type for user defined aspect ratio of the display.
****************************************************************************
*/
typedef enum {
    /*! Aspect ratio is not defined.*/
    FAPI_VISCALE_AR_NONE = 0,
    //! Aspect ratio is 4/3
    FAPI_VISCALE_AR_4_3 = 1,
    //! Aspect ratio is 14/9
    FAPI_VISCALE_AR_14_9 = 2,
    //! Aspect ratio is 16/9 also called wide screen.
    FAPI_VISCALE_AR_16_9 = 3,
    //! Aspect ratio is 20/9 or also called 2.21
    FAPI_VISCALE_AR_221_100 = 4,
    //! Aspect ratio is 235/100 or also called 2.35
    FAPI_VISCALE_AR_235_100 = 5
}FAPI_VISCALE_AspectRatioEnumT;
/*!
****************************************************************************
** \brief Enumeration type for user defined scaling methods.
****************************************************************************
*/
typedef enum {
    /*! User can specify the preferred active area.*/
    FAPI_VISCALE_SM_NONE = 0,
    //! Scaling method specified as Pillar or letter box.
    FAPI_VISCALE_SM_PLBOX = 1,
    //! Scaling method specified as Fullscreen zoom.
    FAPI_VISCALE_SM_FSZOOM = 2,
    //! Scaling method specified as fullscreen center cut out.
    FAPI_VISCALE_SM_FSCCO = 3,
    //! Scaling method specified as let TV scale.
    FAPI_VISCALE_SM_LTVS = 4
}FAPI_VISCALE_ScalingMethodEnumT;
/*!
****************************************************************************
** \brief Enumeration type for user selection of plane order.
****************************************************************************
*/
typedef enum {
    /*! Selects the Video data to be presented onto the relevant plane.*/
    FAPI_VISCALE_VIDEO_ON_PLANE = 0,
    /*! Selects the osd1 data to be presented onto the relevant plane.*/
    FAPI_VISCALE_OSD1_ON_PLANE = 1,
    /*! Selects the osd2 data to be presented onto the relevant plane.*/
    FAPI_VISCALE_OSD2_ON_PLANE = 2,
    /*! Selects the Cursor data to be presented onto the relevant plane.*/
    FAPI_VISCALE_CURSOR_ON_PLANE = 3
}FAPI_VISCALE_PlaneDataSelectorEnumT;
/*!
*******************************************************************************
** \brief Enumerated types for Hnadling of Wss signal on analog SD encoder.
*******************************************************************************
*/
typedef enum {
    /*!   Unknown handling state of Wss Signal.*/
    FAPI_VISCALE_UNKNOWN_WSS_STATE = (int32_t)-1,
    /*!   User defined Wss signal  is 1.*/
    FAPI_VISCALE_WSS_ENABLE_4_3_FULLFORMAT = 1,
    /*!   User defined Wss signal  is 8.*/
    FAPI_VISCALE_WSS_ENABLE_14_9_CENTRE = 8,
    /*!   User defined Wss signal  is 13.*/
    FAPI_VISCALE_WSS_ENABLE_16_9_BOX_CENTRE = 13,
    /*!   User defined Wss signal  is 11.*/
    FAPI_VISCALE_WSS_ENABLE_16_9_BOX_GT_CENTRE = 11,
    /*!   User defined Wss signal  is 7.*/
    FAPI_VISCALE_WSS_ENABLE_4_3_FULL_FORMAT = 7,
    /*!   User defined Wss signal  is 14.*/
    FAPI_VISCALE_WSS_ENABLE_16_9_ANAMORPHIC = 14,
    /*!   Wss process is executed as defined in the stream.*/
    FAPI_VISCALE_WSS_ENABLE_AUTO = 16,
    /*!   The Wss Signaling is disabled.*/
    FAPI_VISCALE_WSS_DISABLE = 0
}FAPI_VISCALE_WssStateEnumT;

//***********************************************************************
//***********************************************************************
//** Local defines
//***********************************************************************
//***********************************************************************
#define FAPI_VISCALE_DisplayAspectRatioEnumT                            \
                                            FAPI_VISCALE_AspectRatioEnumT

//***********************************************************************
//***********************************************************************
//** Data types
//***********************************************************************
//***********************************************************************
/*!
*************************************************************************
** \brief
** This data structure covers all parameters which are need to be
** specified for each scaler object. There are 4 hardware scaler IPs
** in one software scaler object. This data structure has parameters
** for scaling the Video at the video decoder output ONLY.
*************************************************************************
*/
typedef struct {

    //! These are the fields used for setting the Vo scaler.
    //! Enable/Disable the layer.
    uint32_t                             layerEnable; //0
    //! Describes the layout of OSD in the osd memory.
    FAPI_VISCALE_OsdLayoutEnumT          osdLayout; //4
    //! OSD Mode.
    FAPI_VISCALE_OsdModeEnumT            osdMode; //8
    //! Cursor Mode.
    FAPI_VISCALE_CursorModeEnumT         cpMode; //12
    //! Number of tiles in the horizontal direction in the cursor.
    uint32_t                             cpTileNumX; //16
    //! Number of tiles in the vertical direction in the cursor.
    uint32_t                             cpTileNumY; //20
    //! Base pointer to picture to be displayed. An address in Virtual space is expected.
    uint32_t                             picBase; //24
    //! Frame or field to be used
    uint32_t                             frameField; //28
    //! Flag to enable using the global alpha.
    uint32_t                             useGlobalAlpha; //32
    //! global alpha
    uint32_t                             globalAlpha; //36
    //! Cursor/OSD3 picture to be displayed
    uint32_t                             hilightOnOff; //40
    /*! Colour look up table for OSD1,OSD2 and Cursor Plane only.
        Only 256 colours in clut palett are allowed.*/
    uint32_t                             colourLut[256]; //44
    /*! diMode is the descriptor for deinterlacing Mode.
        It is calculated internally and the application must NOT
        Modify this field.*/
    uint32_t                             diMode; //1068
    /*! fieldInversion is the descriptor for indicating reverse field orders.
        It is calculated internally and the application must NOT
        Modify this field.*/
    uint32_t                             fieldInversion; //1072
    /*! Uncropped input picture width. Cropping is allowed only on
        Video plane and OSDs but not on Cursor plane. For OSDs
        the picture width should be memory burst (128 Byte) alligned.*/
    uint32_t                             inputPicWidth; //1076
    /*! Uncropped input picture height. Cropping is allowed only on
        Video plane and OSDs but not on cursor plane.*/
    uint32_t                             inputPicHeight; //1080


    /*! Input picture start pixel position used for cropping on video plane.
        Cropping at top left corner is allowed for Video plane only,
        for OSD and Cursor it s set to 0 internally.*/
    uint32_t                             inputWindowX0; //1084
    /*! Input picture start line position used for cropping on video plane.
        Cropping at top left corner is allowed for Video plane only,
        for OSD and Cursor it s set to 0 internally.*/
    uint32_t                             inputWindowY0; //1088
    /*! Input picture width in terms of luma pixels used for cropping.
        For Cursor plane it is equal to picture width.*/
    uint32_t                             inputWindowWidth; //1092
    /*! Input picture height in terms of luma lines used for cropping.
        For Cursor plane it is equal to picture height.*/
    uint32_t                             inputWindowHeight; //1096

    //! Output picture start position in horizontal direction
    uint32_t                             outputWindowX0; //1100
    //! Output picture start position in vertical direction
    uint32_t                             outputWindowY0; //1104
    /*! Output picture width in terms of luma pixels after scaling.
        For Cursor plane it is equal to picture width as no scaling is
        supported on cursor plane.*/
    uint32_t                             outputWindowWidth; //1108
    /*! Output picture height in terms of luma lines after scaling.
        For Cursor plane it is equal to picture height as no scaling is
        supported on cursor plane.*/
    uint32_t                             outputWindowHeight; //1112
    //1116
} FAPI_VISCALE_ScalerParamsT;
/*!
*************************************************************************
** \brief Parameters that have changed are intimated by this structure.
*************************************************************************
*/
typedef struct {
    /*! Coded Aspect ratio of the frame*/
    FAPI_VISCALE_AspectRatioEnumT        codedAspectRatio; //0
    /*! Display Aspect ratio*/
    FAPI_VISCALE_AspectRatioEnumT        displayAspectRatio; //4
    /*! User defined scaling method*/
    FAPI_VISCALE_ScalingMethodEnumT      scalingMethod; //8
    /*! Current and new value of the Afd*/
    uint32_t                             currAfd; //12
    /*! Current and new value of the Wss*/
    uint32_t                             currWss; //16
    //20
} FAPI_VISCALE_ParamChangeInfoT;
/*!
*************************************************************************
** \brief Open parameters for the Video Scaler driver.
** This data structure covers all parameters which are need to be
** specified when an instance of the driver is opened.
*************************************************************************
*/
typedef struct {
    /*!
    ** The version of the driver.
    ** \ref FAPI_VISCALE_VersionEnumT "FAPI_VISCALE_VERSION".
    */
    FAPI_VISCALE_VersionEnumT version; //0
    //! Open VO,OSD1,OSD2,SD or CP scaler type
    FAPI_VISCALE_ScalerEnumT  scalerType; //4
    //! PAL,NTSC..encoder.
    FAPI_VISCALE_EncoderEnumT encoderType; //8
    //12
} FAPI_VISCALE_OpenParamsT;
/*!
*************************************************************************
** \brief Type definition of the video scaling callback function.
** This function prototype is used for intimating the changed AFD,
** WSS, scaling methods, Aspect ratio.
** This callback is called out of ISR context,
** so careful processing should be carried out within this callback.
*************************************************************************
*/
typedef void(*FAPI_VISCALE_ParamChangeCallbackT)(
                           FAPI_VISCALE_ParamChangeInfoT* paramChangePtr,
                                               void* paramChangeOptData);
//***********************************************************************
//***********************************************************************
//** Global Data
//***********************************************************************
//***********************************************************************
extern FAPI_SYS_DriverT FAPI_VISCALE_Driver0;
//***********************************************************************
//***********************************************************************
//** API Functions
//***********************************************************************
//***********************************************************************

#ifdef __cplusplus
extern "C" {
#endif

    int32_t          FAPI_VISCALE_Init(void);
    void             FAPI_VISCALE_Exit(void);
    uint32_t         FAPI_VISCALE_Isr(void);
    void             FAPI_VISCALE_Bsr(uint32_t arg);
    FAPI_SYS_HandleT FAPI_VISCALE_Open(
                          const FAPI_VISCALE_OpenParamsT* paramsPtr,
                                int32_t* errorCodePtr);
    int32_t          FAPI_VISCALE_Close(FAPI_SYS_HandleT handle);
    uint32_t         FAPI_VISCALE_BackgroundColour(
                                FAPI_VISCALE_ParameterModeEnumT mode,
                                uint8_t Y, uint8_t Cr, uint8_t Cb);
    uint32_t         FAPI_VISCALE_PlaneOrder(
                                 FAPI_VISCALE_ParameterModeEnumT mode,
                                 FAPI_VISCALE_PlaneDataSelectorEnumT plane3,
                                 FAPI_VISCALE_PlaneDataSelectorEnumT plane2,
                                 FAPI_VISCALE_PlaneDataSelectorEnumT plane1,
                                 FAPI_VISCALE_PlaneDataSelectorEnumT plane0);
    int32_t          FAPI_VISCALE_KillOutputs(void);
    int32_t          FAPI_VISCALE_Start(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ScalerParamsT*
                                scaleParamsPtr);
    int32_t          FAPI_VISCALE_Stop(FAPI_SYS_HandleT handle);
    int32_t          FAPI_VISCALE_EnableDisable(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ParameterModeEnumT mode);
    uint32_t         FAPI_VISCALE_Alpha(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ParameterModeEnumT mode,
                                uint32_t level);
    int32_t          FAPI_VISCALE_Resize(FAPI_SYS_HandleT handle ,
                                FAPI_VISCALE_ScalerParamsT*
                                scaleParamsPtr);
    int32_t          FAPI_VISCALE_Hilight(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ParameterModeEnumT mode);
    int32_t          FAPI_VISCALE_AutoPlaneFading(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_VideoFadingModeEnumT fadingMode);
    int32_t          FAPI_VISCALE_AutoPlaneFadingStepSize(FAPI_SYS_HandleT handle,
                                             FAPI_VISCALE_ParameterModeEnumT mode,
                                                           uint32_t* stepSizePtr);
    int32_t          FAPI_VISCALE_UpdateClut(FAPI_SYS_HandleT handle,
                                uint32_t* colour);
    int32_t          FAPI_VISCALE_UpdateSingleClut(FAPI_SYS_HandleT handle,
                                uint32_t entryNumber, uint32_t entryColour);
    void             FAPI_VISCALE_AutoScaler(void* frameCropPtr,
                                FAPI_SYS_HandleT handle,
                                uint32_t suspendType);
    int32_t          FAPI_VISCALE_SetScalerToHdEncoder(FAPI_SYS_HandleT handle,
                                FAPI_SYS_HandleT viencHdHandle);
    int32_t          FAPI_VISCALE_SetScalingMethod(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ScalingMethodEnumT scalingMethod);
    int32_t          FAPI_VISCALE_SetDisplayAspectRatio(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_AspectRatioEnumT displayAr);
    int32_t          FAPI_VISCALE_SetWssState(FAPI_SYS_HandleT handle,
                                              FAPI_VISCALE_WssStateEnumT wssState);
    int32_t          FAPI_VISCALE_SetParamChangeCallback(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_ParamChangeCallbackT
                                                     paramChangeCallbackFunction,
                                                       void* paramChangeOptData);
    int32_t          FAPI_VISCALE_ClearScalerToHdEncoder(FAPI_SYS_HandleT handle);
    int32_t          FAPI_VISCALE_ClearScalingMethod(FAPI_SYS_HandleT handle);
    int32_t          FAPI_VISCALE_ClearDisplayAspectRatio(FAPI_SYS_HandleT handle);
    int32_t          FAPI_VISCALE_ClearParamChangeCallback(FAPI_SYS_HandleT handle);
    FAPI_VISCALE_SystemModeEnumT
                     FAPI_VISCALE_GetSystemType(FAPI_SYS_HandleT handle);
    int32_t          FAPI_VISCALE_GetWssSignal(FAPI_SYS_HandleT handle,
                                                 uint32_t* wssSignalPtr);

#ifdef __cplusplus
    }
    #endif
#endif




