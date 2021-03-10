/*!
*****************************************************************************
**
** \file        ./subsystems/video/val/src/val.h
**
** \brief       Video abstraction layer (VAL) suitable for live and PVR 
**              playback presentation.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2008-2009 by Fujitsu Microelectronics Limited
**
*****************************************************************************
*/

#ifndef VAL_H
#define VAL_H

#if 0

#include "fapex/abst_types.h"
#include "fapex/abst_libvidec.h"
#include "fapex/abst_libviout.h"

#endif

//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************

/*!
********************************************************************************
** Standard error codes for the module
********************************************************************************
*/

/*! Bad parameter passed. */
#define SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER         (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_BAD_PARAMETER)

/*! Memory allocation failed. */
#define SUBSYS_VIDEO_VAL_ERR_OUT_OF_MEMORY         (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_OUT_OF_MEMORY)

/*! Module already initialised. */
#define SUBSYS_VIDEO_VAL_ERR_ALREADY_INITIALIZED   (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_ALREADY_INITIALIZED)

/*! Module not initialised. */
#define SUBSYS_VIDEO_VAL_ERR_NOT_INITIALIZED       (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_NOT_INITIALIZED)

/*! Feature or function is not available. */
#define SUBSYS_VIDEO_VAL_ERR_FEATURE_NOT_SUPPORTED (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_FEATURE_NOT_SUPPORTED)

/*! Timeout occured. */
#define SUBSYS_VIDEO_VAL_ERR_TIMEOUT               (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_TIMEOUT)

/*! The device is busy, try again later. */
#define SUBSYS_VIDEO_VAL_ERR_DEVICE_BUSY           (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_DEVICE_BUSY)

/*! Invalid handle was passed. */
#define SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE        (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_INVALID_HANDLE)

/*! Semaphore could not be created. */
#define SUBSYS_VIDEO_VAL_ERR_SEMAPHORE_CREATE      (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_SEMAPHORE_CREATE)

/*! The driver's used version is not supported. */
#define SUBSYS_VIDEO_VAL_ERR_UNSUPPORTED_VERSION   (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_UNSUPPORTED_VERSION)

/*! Module has not been opened. */
#define SUBSYS_VIDEO_VAL_ERR_NOT_OPEN              (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_NOT_OPEN)

/*! Module is already open. */
#define SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN          (SUBSYS_VIDEO_VAL_MODULE_BASE +\
                                                           FAPI_ERR_ALREADY_OPEN)

/*!
********************************************************************************
** Additional driver error codes (reserved from -100 to -999)
**
** Each error code shall be decreased in steps of 1.
********************************************************************************
*/

/*! VAL specfic error code base. */
#define SUBSYS_VIDEO_VAL_ERR_BASE   (SUBSYS_VIDEO_VAL_MODULE_BASE - 100)

/*! VAL specific errors. */
#define SUBSYS_VIDEO_VAL_DATA_NOT_AVAILABLE      (SUBSYS_VIDEO_VAL_ERR_BASE - 0)
#define SUBSYS_VIDEO_VAL_ERROR_STATE             (SUBSYS_VIDEO_VAL_ERR_BASE - 1)
#define SUBSYS_VIDEO_VAL_ALREADY_STARTED         (SUBSYS_VIDEO_VAL_ERR_BASE - 2)
#define SUBSYS_VIDEO_VAL_BAD_MODE                (SUBSYS_VIDEO_VAL_ERR_BASE - 3)
#define SUBSYS_VIDEO_VAL_INTERNAL                (SUBSYS_VIDEO_VAL_ERR_BASE - 4)


//*****************************************************************************
//*****************************************************************************
//** Data types
//*****************************************************************************
//*****************************************************************************

/*!
*******************************************************************************
** \brief Environment for which VAL instance is opened.
** 
** This enumeration contains the presentation environments supported by VAL.
*******************************************************************************
*/
typedef enum
{
    VAL_ENV_NONE = -1,      //!< None, internally used only.
    VAL_ENV_LIVE = 0,       //!< Decoding of live broadcast content.
    VAL_ENV_PLAY, //1       //!< Playback of recorded content via PVR lib.
    VAL_ENV_NUMS //2        //!< Number of modes, internally used.

} VAL_EnvironmentT;

/*!
*******************************************************************************
** \brief Video output definitions.
** 
** This enumeration contains the video output types supported by VAL.
*******************************************************************************
*/
typedef enum
{
    VAL_VOUT_NONE = -1,     //!< None, internally used only.
    VAL_VOUT_SD, //0        //!< SD video output.
    VAL_VOUT_HD, //1        //!< HD video output.
    VAL_VOUT_NUMS           //!< Number of outputs, internally used.

} VAL_VideoOutputT;


/*!
*******************************************************************************
** \brief HD analog video encoder mode.
** 
** This enumeration contains the possible modes that are supported by
** analog HD encoder, they also correspond the to respective HDMI
** video settings.
*******************************************************************************
*/
typedef enum
{
    VAL_1920x1080x2397P = 0,        //!< 1080p, 23.97 Hz.
    VAL_1920x1080x24P, //1              //!< 1080p, 24    Hz.
    VAL_1920x1080x25P, //2             //!< 1080p, 25    Hz.
    VAL_1920x1080x2997P, //3            //!< 1080p, 29.97 Hz.
    VAL_1920x1080x30P, //4             //!< 1080p, 30    Hz.
    VAL_1920x1080x50I, //5             //!< 1080i, 50    Hz.
    VAL_1920x1080x5994I, //6           //!< 1080i, 59.94 Hz.
    VAL_1920x1080x60I, //7             //!< 1080i, 60    Hz.
    VAL_1280x720x2397P, //8            //!<  720p, 23.97 Hz.
    VAL_1280x720x24P, //9               //!<  720p, 24    Hz.
    VAL_1280x720x25P, //10              //!<  720p, 25    Hz.
    VAL_1280x720x2997P, //11            //!<  720p, 29.97 Hz.
    VAL_1280x720x30P, //12              //!<  720p, 30    Hz.
    VAL_1280x720x50P, //13              //!<  720p, 50    Hz.
    VAL_1280x720x5994P, //14            //!<  720p, 59.94 Hz.
    VAL_1280x720x60P, //15              //!<  720p, 60    Hz.
    VAL_720x576x50I, //16               //!<  576i, 50    Hz.
    VAL_720x576x50P, //17               //!<  576p, 50    Hz.
    VAL_720x480x5994I, //18             //!<  480i, 59.94 Hz.
    VAL_720x480x5994P //19              //!<  480p, 59.94 Hz.
    
} VAL_HdEncoderT;

/*!
*******************************************************************************
** \brief SD analog video encoder mode.
** 
** This enumeration contains the possible modes that are supported by the
** analog SD encoder.
*******************************************************************************
*/
typedef enum
{
    VAL_SD_OFF = 0,                 //!< VE SD turned off.
    VAL_SD_SECAM,                   //!< Secam System.
    VAL_SD_NTSC,                    //!< NTSC System.
    VAL_SD_NTSC_4_43,               //!< NTSC 443 System.
    VAL_SD_PAL,                     //!< PAL System.
    VAL_SD_PAL60,                   //!< PAL 60 System.
    VAL_SD_PAL_M,                   //!< PAL M System.
    VAL_SD_PAL_N,                   //!< PAL N System.
    VAL_SD_PAL_N_ARG                //!< PAL N Argentina System.
    
} VAL_SdEncoderT;

/*!
*******************************************************************************
** \brief VAL operation mode.
** 
** This enumeration contains the internal operation modes of an opened VAL 
** instance.
*******************************************************************************
*/
typedef enum
{
    VAL_OP_ERROR = -1,      //!< Module is in an error state that needs 
                            //!< VAL_Close to be called for recovery.
    VAL_OP_NONE = 0,        //!< No operation.
    VAL_OP_LIVE, //1        //!< Live stream presentation.
    VAL_OP_PLAY, //2        //!< PVR playback presentation.
    VAL_OP_IFRAME, //3      //!< Decoding of single I-frames (MPEG only!)
    VAL_OP_NUMS             //!< Number of available modes.
    
} VAL_OpEnumT;

/*!
*******************************************************************************
** \brief VAL playback mode.
** 
** This enumeration contains all modes available for playback environment
** #VAL_ENV_PLAY. For live environment, mode is always #VAL_PLAYMODE_NORMAL.
*******************************************************************************
*/
typedef enum
{
    VAL_PLAYMODE_NONE = 0,            //!< Not in playback.
    VAL_PLAYMODE_NORMAL, //1          //!< Normal playback.
    VAL_PLAYMODE_PAUSE, //2           //!< Paused playback.
    VAL_PLAYMODE_FAST_DEC_IONLY, //3  //!< I-frame-only mode controlled by
                                      //!< decoder.
    VAL_PLAYMODE_FAST_DEC_IP, //4     //!< I/P-frame-only mode controlled by 
                                      //!< decoder.
    VAL_PLAYMODE_FAST_LIB_IONLY, //5  //!< "Any-I" mode controlled by PVR lib.
    VAL_PLAYMODE_FAST_NOFEED, //6     //!< Fast seek mode controlled by PVR lib.
    VAL_PLAYMODE_FAST_CONTROLLEDFEED, //7 //!< I-frame-only mode, data fed by PVR
                                      //!< lib, feed control and frame 
                                      //!< extraction done by decoder.
    VAL_PLAYMODE_SLOW_2X, //8         //!< 1/2 speed slow mode.
    VAL_PLAYMODE_SLOW_4X, //9         //!< 1/4 speed slow mode.
    VAL_PLAYMODE_SLOW_8X, //10        //!< 1/8 speed slow mode.
    VAL_PLAYMODE_NUMS
    
} VAL_PlayModeEnumT;

/*!
*******************************************************************************
** \brief Video decoder status.
** 
** This enumeration contains all internal decoder states.
*******************************************************************************
*/
typedef enum
{
    VAL_STATUS_STOPPED = 0,             //!< Decoder is stopped.
    VAL_STATUS_BOOTING, //1             //!< Decoder is starting up.
    VAL_STATUS_RUNNING, //2             //!< Decoder is running.
    VAL_STATUS_NUMS                     //!< Number of states.
    
} VAL_StatusEnumT;

/*!
*******************************************************************************
** \brief Video decoder type.
** 
** This structure describes the decoder type by system and frame bank size.
*******************************************************************************
*/
typedef struct
{
    int32_t                              system; //0        //!< Decoder system.
    int32_t                              frameBankSize; //4 //!< Frame bank size.
    
} VAL_DecoderTypeT;

/*!
*******************************************************************************
** \brief Parameters for transition to "up" mode.
** 
** This structure contains parameters that are passed when bringing the VAL
** system up, i.e. enabling the video output.
*******************************************************************************
*/
typedef struct
{
    VAL_HdEncoderT                       hdSystemType; //0
    VAL_SdEncoderT                       sdSystemType; //4
    FAPI_VISCALE_AspectRatioEnumT        displayAspectRatio[VAL_VOUT_NUMS]; //8
    FAPI_VISCALE_ScalingMethodEnumT      scalingMethod; //16
    //20
} VAL_UpParamsT;

/*!
*******************************************************************************
** \brief Parameters for opening a VAL instance.
** 
** This structure contains parameters that are passed when opening a VAL
** instance, i.e. preparing for video decoding.
*******************************************************************************
*/
typedef struct
{
    VAL_EnvironmentT                     environment; //0 //!< Decoder environment.
    VAL_DecoderTypeT                     decoder; //4     //!< Requested decoder.
    uint8_t                              enableAfd; //12   //!< AFD enable request.
    int Data_16; //16
    //20
} VAL_OpenParamsT;

#if 0

typedef struct
{
   int fill_0; //0
   int fill_4; //4
   int fill_8; //8
   int fill_12; //12
   int fill_16; //16
   int fill_20; //20
   int fill_24; //24
   int fill_28; //28
   int fill_32; //32
   int fill_36; //36
   int fill_40; //40
   int fill_44; //44
   //48
} VAL_Data_2316;

#endif

/*!
*******************************************************************************
** \brief Internal data valid during "up" phase, internally accessed via 
**        pointer returned by VAL_GoUp.
*******************************************************************************
*/
typedef struct
{
    FAPI_SYS_SemaphoreT                  mutexHandle; //0
    
    uint8_t                              up; //4
    void*                                openPtr; //8
    
    FAPI_SYS_HandleT                     viencHandle[VAL_VOUT_NUMS]; //12
    FAPI_SYS_HandleT                     viscaleHandle[VAL_VOUT_NUMS]; //20        
    FAPI_SYS_HandleT                     hdmiHandle; //28
    
    VAL_HdEncoderT                       appHdSystemType; //32
    VAL_SdEncoderT                       appSdSystemType; //36
    VAL_HdEncoderT                       viencHdEncoder; //40
    VAL_SdEncoderT                       viencSdEncoder; //44
//    FAPEX_VIOUT_ScalerParamStrT          vioutParams[VAL_VOUT_NUMS];
    FAPI_VISCALE_ScalerParamsT           sdScalerParams; //48
    FAPI_VISCALE_ScalerParamsT           hdScalerParams; //1164
    FAPI_VISCALE_AspectRatioEnumT        vioutDispAr[VAL_VOUT_NUMS]; //2280
    FAPI_VISCALE_ScalingMethodEnumT      vioutHdScalingMethod; //2288
    uint8_t                              videoBlanked; //2292
    void (*Func_2296)(FAPI_VISCALE_ParamChangeInfoT*, void*); //2296
    void* Data_2300; //2300
    uint8_t                              hdmiConnected; //2304
    uint8_t                              hdmiHaveEDID; //2305
    int                                  Data_2308; //2308
    char                                 bData_2312; //2312
#if 0
    VAL_Data_2316                        Data_2316; //2316
#endif
    //2364
} VAL_DataT;


/*!
*******************************************************************************
** \brief Internal data valid during "open" phase, internally accessed via 
**        pointer returned by VAL_Open.
*******************************************************************************
*/
typedef struct
{
    VAL_OpenParamsT                      openParams; //0
    VAL_DataT*                           dataPtr; //20
#if 0
    int32_t                              tsdId;
    int32_t                              videcId;
#endif
    FAPI_SYS_HandleT                     bmHandle; //24
    FAPI_SYS_HandleT                     tsdHandle; //28
    FAPI_SYS_HandleT                     videcHandle; //32
    
    VAL_DecoderTypeT                     decoder; //36   //!< Current decoder.
    uint32_t                             startFlags; //44
    
    void                                 (*frameAvlCb)(void* optData); //48
    void*                                frameAvlCbArg; //52
    void                                 (*paramChangeCb) //56
                                         (FAPI_VIDEC_FrameInfoStateT* nextFrameInfoPtr,
                                          FAPI_VIDEC_FrameInfoStateT* lastFrameInfoPtr,
                                          void* optData);
    void*                                paramChangeCbArg; //60
    
    uint32_t                             bufferSize; //64
    
    VAL_OpEnumT                          operation; //68
    uint32_t                             pid; //72
//    uint32_t                             pcrFlag; //76
    VAL_PlayModeEnumT                    mode; //76
    uint8_t                              frameAvailable; //80
    uint8_t                              frameDecoded; //81
    VAL_StatusEnumT                      decoderStatus; //84
    
    /*FAPEX_VIDEC_DecFrameInfoStrT */
    struct
    {
       int fill_0[16]; //0
       //64
    }                                    videcFrameInfo; //88
    uint8_t                              videcFrameInfoAvailable; //152
#if 0
    struct
    {
       uint32_t Data_0; //0
       uint32_t Data_4; //4
       unsigned Data_8; //8
       unsigned Data_12; //12
       //16
    } Data_156; //156
#else
    uint32_t Data_156_0;
    uint32_t Data_156_4;
    uint32_t Data_156_8;
    uint32_t Data_156_12;
#endif
    //172
} VAL_OpenT;

#if 0

/*!
*******************************************************************************
** \brief Publicly available VAL status parameters.
** 
** This structure contains VAL's public runtime parameters.
*******************************************************************************
*/
typedef struct
{
    VAL_EnvironmentT                     environment;   //!< Selected
                                                        //!< environment.
    VAL_OpEnumT                          operation;     //!< Current operation.
    VAL_PlayModeEnumT                    mode;          //!< Current playback 
                                                        //!< mode.
    VAL_DecoderTypeT                     decoder;       //!< Current decoder.
    VAL_StatusEnumT                      decoderStatus; //!< Current decoder 
                                                        //!< status.
} VAL_StatusT;


typedef struct
{
   //! Width of current decoded frame in pixels
   uint32_t                             decodedWidth; //0
   //! Height of current decoded frame in lines
   uint32_t                             decodedHeight; //4
} VAL_VESParamStrT;

#endif

//*****************************************************************************
//*****************************************************************************
//** Global Data
//*****************************************************************************
//*****************************************************************************

//*****************************************************************************
//*****************************************************************************
//** API Functions
//*****************************************************************************
//*****************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

/* general interface */

int32_t          VAL_Init               (void);
VAL_DataT*       VAL_GoUp               (const VAL_UpParamsT* paramsPtr,
                                         int32_t* errCodePtr);
#if 0
int32_t          VAL_GoDown             (VAL_DataT* dataPtr);
int32_t          VAL_UpdateHDMIConnectionStatus
                                        (VAL_DataT* dataPtr,
                                         uint8_t* connectedPtr,
                                         uint8_t* changePtr);
int32_t          VAL_GetHDMIConnectionStatus
                                        (VAL_DataT* dataPtr,
                                         uint8_t* connectedPtr);
int32_t          VAL_SetOutputMode      (VAL_DataT* dataPtr,
                                         VAL_HdEncoderT hdSystemType,
                                         VAL_SdEncoderT sdSystemType);
int32_t          VAL_SetDisplayAspectRatio (VAL_DataT* dataPtr,
                                         VAL_VideoOutputT output,
                                         int32_t displayAr);
int32_t          VAL_SetHdScalingMethod (VAL_DataT* dataPtr,
                                         int32_t scalingMethod);
int32_t          VAL_Resize             (VAL_DataT* dataPtr,
                                         uint32_t x0, uint32_t y0,
                                         uint32_t width, uint32_t height);
int32_t          VAL_Crop               (VAL_DataT* dataPtr,
                                         uint32_t x0, uint32_t y0,
                                         uint32_t width, uint32_t height);
int32_t          VAL_Blank              (VAL_DataT* dataPtr,
                                         uint8_t blankOrUnblank);

FAPI_SYS_HandleT VAL_GetHdmi            (VAL_DataT* dataPtr);
#endif
FAPI_SYS_HandleT VAL_GetViencSd         (VAL_DataT* dataPtr);
#if 0
FAPI_SYS_HandleT VAL_GetViencHd         (VAL_DataT* dataPtr);
FAPI_SYS_HandleT VAL_GetViscaleSd       (VAL_DataT* dataPtr);
#endif
FAPI_SYS_HandleT VAL_GetViscaleHd       (VAL_DataT* dataPtr);

VAL_OpenT*       VAL_Open               (VAL_DataT* dataPtr,
                                         const VAL_OpenParamsT* paramsPtr,
                                         int32_t* errCodePtr);
#if 0
int32_t          VAL_Close              (VAL_OpenT* openPtr);

int32_t          VAL_Task               (VAL_OpenT* openPtr);
int32_t          VAL_SetFrameAvailableCb(VAL_OpenT* openPtr,
                                         void (*frameAvlCb)(void* optData),
                                         void* frameAvlCbArg);
int32_t          VAL_SetParamChangeCb   (VAL_OpenT* openPtr,
                                         void (*paramChangeCb)(FAPI_VIDEC_FrameInfoStateT*, 
                                                               FAPI_VIDEC_FrameInfoStateT*, 
                                                               void*),
                                         void* paramChangeCbArg);
int32_t          VAL_Start              (VAL_OpenT* openPtr, uint32_t pid,
                                         VAL_PlayModeEnumT mode, uint32_t pcrFlag);
int32_t          VAL_Stop               (VAL_OpenT* openPtr, uint8_t freeze);
int32_t          VAL_Freeze             (VAL_OpenT* openPtr, uint8_t freezeOn);
int32_t          VAL_Reboot             (VAL_OpenT* openPtr,
                                         const VAL_DecoderTypeT* decoderPtr);
int32_t          VAL_GetStatus          (VAL_OpenT* openPtr,
                                         VAL_StatusT* statusPtr);
int32_t          VAL_GetVideoFrameInfo  (VAL_OpenT* openPtr,
                                         FAPEX_VIDEC_DecFrameInfoStrT*
                                         videcInfoPtr);

int32_t          VAL_Recover            (VAL_OpenT* openPtr);
int32_t          VAL_GetBufferSize      (VAL_OpenT* openPtr, uint32_t* sizePtr);
int32_t          VAL_GetBufferLevel     (VAL_OpenT* openPtr, uint32_t*
                                         levelPtr);
int32_t          VAL_IsFrameAvailable   (VAL_OpenT* openPtr, uint8_t* avlPtr);

FAPI_SYS_HandleT VAL_GetBmHandle        (VAL_OpenT* openPtr);
FAPI_SYS_HandleT VAL_GetTsdHandle       (VAL_OpenT* openPtr);
FAPI_SYS_HandleT VAL_GetVidecHandle     (VAL_OpenT* openPtr);
#endif

/* specific for I-frame presentation operation */

int32_t          VAL_IFrameDecode       (VAL_OpenT* openPtr,
                                         const uint32_t* dataPtr,
                                         uint32_t sizeInBytes);
int32_t          VAL_IFrameDisplay      (VAL_OpenT* openPtr);

#if 0
/* specific for PVR playback operation */

int32_t          VAL_PlayChangeMode     (VAL_OpenT* openPtr,
                                         VAL_PlayModeEnumT mode);
int32_t          VAL_PlayShowIFrame     (VAL_OpenT* openPtr,
                                         const uint32_t* dataPtr,
                                         uint32_t dataBytes);
int32_t          VAL_PlayPrepareNextFrame(VAL_OpenT* openPtr);

int32_t          func_21ca7a28(VAL_DataT* a, VAL_Data_2316* b);

#endif

#ifdef __cplusplus
}
#endif

#endif /* VAL_H */
