/*
*****************************************************************************
**
** \file        ./fapi/drv/viscale/src/drv_viscale_priv.h
** 
** \brief       Privately used header file.
**
** This file contains the declaration of the private data of Viscale driver.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_VISCALE_PRIV_H
    #define FAPI_VISCALE_PRIV_H

//**************************************************************************
//**************************************************************************
//** Defines and Macros
//**************************************************************************
//**************************************************************************
//!************* BASE ADDRESSES OF SCALERS *********************************
#define FAPI_VISCALE_BASE_ADDRESS_VIDEO_SCALER_0 FIO_ADDRESS(VO, 0xCB000000)
#define FAPI_VISCALE_BASE_ADDRESS_OSD_SCALER_1   FIO_ADDRESS(VO, 0xCB004000)
#define FAPI_VISCALE_BASE_ADDRESS_OSD_SCALER_2   FIO_ADDRESS(VO, 0xCB008000)
#define FAPI_VISCALE_BASE_ADDRESS_SD_SCALER_3    FIO_ADDRESS(VO, 0xCB00C000)
#define FAPI_VISCALE_BASE_ADDRESS_CP_SCALER_4    FIO_ADDRESS(VO, 0xCB010000)
//!************* TIME AND LIMITS *******************************************
#define FAPI_VISCALE_OSD_MAX_OUTPUT_WINDOW_WIDTH                        2000
#define FAPI_VISCALE_OSD_MAX_OUTPUT_WINDOW_HEIGHT                       1100
#define FAPI_VISCALE_PLANE_MIN_OUTPUT_WINDOW_X0                            5
#define FAPI_VISCALE_PLANE_MIN_OUTPUT_WINDOW_Y0                            5
//!************* SUPPORTED SCALERS *****************************************
#define FAPI_VISCALE_MAX_NUM_VIDEO_SCALERS                              0x01
#define FAPI_VISCALE_MAX_NUM_OSD1_SCALERS                               0x01
#define FAPI_VISCALE_MAX_NUM_OSD2_SCALERS                               0x01
#define FAPI_VISCALE_MAX_NUM_SD_SCALERS                                 0x01
#define FAPI_VISCALE_MAX_NUM_CP_SCALERS                                 0x01
#define FAPI_VISCALE_MAX_NUM_SCALERS                                       \
                                      (FAPI_VISCALE_MAX_NUM_VIDEO_SCALERS +\
                                       FAPI_VISCALE_MAX_NUM_OSD1_SCALERS  +\
                                       FAPI_VISCALE_MAX_NUM_OSD2_SCALERS  +\
                                       FAPI_VISCALE_MAX_NUM_SD_SCALERS    +\
                                       FAPI_VISCALE_MAX_NUM_CP_SCALERS)
//!************* SIGNATURE *************************************************
//! "Viscaler" in hex = 0x56697363616c6572
#define FAPI_VISCALE_ID                                0x56697363616c6572ULL
#define FAPI_VISCALE_ISR_TIMEOUT                                         500
//!************* MACROS ****************************************************
#define CLIP(MAX,MIN,val)      (val > MAX) ? MAX : ((val < MIN) ? MIN : val)
#define FAPI_VISCALE_TOP_FIELD                                    0x00000000
#define FAPI_VISCALE_BOT_FIELD                                    0x00000001

//**************************************************************************
//**************************************************************************
//** Enumerated types
//**************************************************************************
//**************************************************************************
/*
****************************************************************************
** \brief Enumerated type to fade-in or fade-out video for the internal
** state.
****************************************************************************
*/
typedef enum {
    FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_IN = (int32_t)0,
    FAPI_VISCALE_INTERNAL_FADING_IN, //1
    FAPI_VISCALE_INTERNAL_FADE_IN_DONE, //2
    FAPI_VISCALE_INTERNAL_REQUEST_TO_FADE_OUT, //3
    FAPI_VISCALE_INTERNAL_FADING_OUT, //4
    FAPI_VISCALE_INTERNAL_FADE_OUT_DONE //5
}FAPI_VISCALE_InternalVideoFadingModeEnumT;
/*
****************************************************************************
** \brief Enumerated type to ENABLE OR DISABLE
****************************************************************************
*/
typedef enum {
    FAPI_VISCALE_REQUEST_TO_FORCE_DISABLE = (int32_t)0,
    FAPI_VISCALE_FORCE_DISABLED, //1
    FAPI_VISCALE_REQUEST_TO_FORCE_ENABLE, //2
    FAPI_VISCALE_FORCE_ENABLED //3
}FAPI_VISCALE_EnableStatesEnumT;
/*
****************************************************************************
** \brief Enumerated type for internal state of the filters.
****************************************************************************
*/
typedef enum {
    FAPI_VISCALE_FILTERS_UPDATED = (int32_t)0,
    FAPI_VISCALE_REQUEST_TO_UPDATE_FILTERS //1
}FAPI_VISCALE_FilterStatesEnumT;
/*
****************************************************************************
** \brief SD Scaler Modes enumerated type
****************************************************************************
*/
typedef enum {
    //! Unknown sd scaler mode
    FAPI_VISCALE_UNKNOWN_SD_SCALER_MODE = 0,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x2397P_TO_5994I = 1,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x24P_TO_5994I = 2,
    //! Predefined sd scaler mode for PAL.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x25P_TO_50I = 3,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x2997P_TO_5994I = 4,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x30P_TO_5994I = 5,
    //! Predefined sd scaler mode for PAL.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x50I_TO_50I = 6,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x5994I_TO_5994I = 7,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1920x1080x60I_TO_5994I = 8,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x2397P_TO_5994I = 9,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x24P_TO_5994I = 10,
    //! Predefined sd scaler mode for PAL.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x25P_TO_50I = 11,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x2997P_TO_5994I = 12,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x30P_TO_5994I = 13,
    //! Predefined sd scaler mode for PAL.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x50P_TO_50I = 14,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x5994P_TO_5994I = 15,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_1280x720x60P_TO_5994I = 16,
    //! Predefined sd scaler mode for PAL.
    FAPI_VISCALE_SD_SCALER_MODE_720x576x50I_TO_50I = 17,
    //! Predefined sd scaler mode for PAL.
    FAPI_VISCALE_SD_SCALER_MODE_720x576x50P_TO_50I = 18,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_720x480x5994I_TO_5994I = 19,
    //! Predefined sd scaler mode for NTSC.
    FAPI_VISCALE_SD_SCALER_MODE_720x480x5994P_TO_5994I = 20,
    //! Predefined sd scaler mode for LCD.
    FAPI_VISCALE_SD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01_TO_50I = 21,
    //! Predefined sd scaler mode for LCD.
    FAPI_VISCALE_SD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB_TO_50I = 22,
    //! Unsupported sd scaler mode.
    FAPI_VISCALE_UNSUPPORTED_SD_SCALER_MODE = 255
}FAPI_VISCALE_SdScalerModeEnumT;
/*
****************************************************************************
** \brief Video Scaler Modes enumerated type
****************************************************************************
*/
typedef enum {
    //! Unknown hd scaler mode
    FAPI_VISCALE_UNKNOWN_HD_SCALER_MODE = 0,
    //! Predefined hd scaler mode to scale any pic to 1920x1080p.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2397P = 1,
    //! Predefined hd scaler mode to scale any pic to 1920x1080p.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x24P = 2,
    //! Predefined hd scaler mode to scale any pic to 1920x1080p.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x25P = 3,
    //! Predefined hd scaler mode to scale any pic to 1920x1080p.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x2997P = 4,
    //! Predefined hd scaler mode to scale any pic to 1920x1080p.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x30P = 5,
    //! Predefined hd scaler mode to scale any pic to 1920x1080i.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x50I = 6,
    //! Predefined hd scaler mode to scale any pic to 1920x1080i.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x5994I = 7,
    //! Predefined hd scaler mode to scale any pic to 1920x1080i.
    FAPI_VISCALE_HD_SCALER_MODE_1920x1080x60I = 8,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x2397P = 9,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x24P = 10,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x25P = 11,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x2997P = 12,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x30P = 13,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x50P = 14,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x5994P = 15,
    //! Predefined hd scaler mode to scale any pic to 1280x720p.
    FAPI_VISCALE_HD_SCALER_MODE_1280x720x60P = 16,
    //! Predefined hd scaler mode to scale any pic to 720x576i.
    FAPI_VISCALE_HD_SCALER_MODE_720x576x50I = 17,
    //! Predefined hd scaler mode to scale any pic to 720x576p.
    FAPI_VISCALE_HD_SCALER_MODE_720x576x50P = 18,
    //! Predefined hd scaler mode to scale any pic to 720x480i.
    FAPI_VISCALE_HD_SCALER_MODE_720x480x5994I = 19,
    //! Predefined hd scaler mode to scale any pic to 720x480p.
    FAPI_VISCALE_HD_SCALER_MODE_720x480x5994P = 20,
    //! Predefined sd scaler mode for LCD.
    FAPI_VISCALE_HD_SCALER_MODE_LCD_640x480x50P_LQ080V3DG01 = 21,
    //! Predefined sd scaler mode for LCD.
    FAPI_VISCALE_HD_SCALER_MODE_LCD_1024x768x50P_SVA150XG10TB = 22
}FAPI_VISCALE_HdScalerModeEnumT;
/*!
****************************************************************************
** \brief Enumeration type for User scaling request.
****************************************************************************
*/
typedef enum {
    //! User Request served.
    FAPI_VISCALE_USER_SCALER_REQUEST_DONE = 0,
    //! User Request served.
    FAPI_VISCALE_AUTO_SCALER_REQUEST_DONE = 1,
    //! User request pending.
    FAPI_VISCALE_USER_SCALER_REQUEST = 2,
    //! User request pending.
    FAPI_VISCALE_AUTO_SCALER_REQUEST = 3
}FAPI_VISCALE_ScalerRequestTypeEnumT;
//***********************************************************************
//***********************************************************************
//** Data types
//***********************************************************************
//***********************************************************************
typedef struct{
    uint32_t                                          startX0; //0
    uint32_t                                          startY0; //4
    uint32_t                                          horSize; //8
    uint32_t                                          verSize; //12

    // Some SD specific stuff
    uint32_t                                          sdHorWriteStart; //16
    uint32_t                                          sdHorWriteStop; //20
    uint32_t                                          sdDispcvbshorstartstop; //24
    //28
}FAPI_VISCALE_ActiveRegionDataT;
/*
*************************************************************************
** \brief The Data Structure containing the fields for mapping the user 
** and autoscaler requests onto the Vo Scaler´s H/W.
** \sa FAPI_VISCALE_VideoScalerHandleT
*************************************************************************
*/
typedef struct {
    uint32_t                                          diMode; //0
    uint32_t                                          fieldInversion; //4
    uint32_t                                          frameField; //8
    uint32_t                                          inputPicWidth; //12
    uint32_t                                          inputPicHeight; //16
    uint32_t                                          inputWindowX0; //20
    uint32_t                                          inputWindowY0; //24
    uint32_t                                          inputWindowWidth; //28
    uint32_t                                          inputWindowHeight; //32
    uint32_t                                          outputWindowX0; //36
    uint32_t                                          outputWindowY0; //40
    uint32_t                                          outputWindowWidth; //44
    uint32_t                                          outputWindowHeight; //48
    //52
}FAPI_VISCALE_VoRequestMapsDataT;
/*
*************************************************************************
** \brief The Data Structure containing the fields for mapping the
** special handling of SD scaler.
*************************************************************************
*/
typedef struct {
    uint32_t                                          inputHorStart; //0
    uint32_t                                          inputHorStop; //4
    uint32_t                                          inputVerStart; //8
    uint32_t                                          inputVerStop; //12
    uint32_t                                          outputHorStart; //16
    uint32_t                                          outputHorStop; //20
    uint32_t                                          outputVerStart; //24
    uint32_t                                          outputVerStop; //28
    uint32_t                                          sdHorWriteStart; //32
    uint32_t                                          sdHorWriteStop; //36
    uint32_t                                          sdDispcvbshorstartstop; //40
    //44
}FAPI_VISCALE_SdRequestMapsDataT;
/*
*************************************************************************
** \brief The Data Structure containing the feilds for operating the
** Scaler inside the ISR.
** \sa FAPI_VISCALE_VideoScalerHandleT
*************************************************************************
*/
typedef struct {

    //Hor Filter variables
    uint32_t                                          hSize; //0
    int32_t                                           initalShift; //4
    uint32_t                                          horDispPixel; //8
    uint32_t                                          horReadPixel; //12

    uint32_t                                          hStartPos; //16
    uint32_t                                          horAddPhase; //20
    uint32_t                                          horFilterOn; //24
    uint32_t                                          horFilterUp; //28
    uint32_t                                          horD; //32
    uint32_t                                          horN; //36

    //Field invert order indicator
    uint32_t                                          fieldInversion; //40

    //Ver Filter variables
    uint32_t                                          vStartPos; //44
    uint32_t                                          verAddPhase; //48
    uint32_t                                          verFilterOn; //52
    uint32_t                                          verFilterUp; //56
    uint32_t                                          verD; //60
    uint32_t                                          verN; //64

    //Output window variables
    uint32_t                                          horStart; //68
    uint32_t                                          horStop; //72
    uint32_t                                          verStart; //76
    uint32_t                                          verStop; //80

    //Sd Filter maps
    FAPI_VISCALE_SdRequestMapsDataT                   sdScalerReq; //84

    //Coefficients
    uint32_t                                          coefficients[128]; //128

} FAPI_VISCALE_VideoFilterSettingsDataT;
/*
*****************************************************************************
** \brief The Data Structure containing the feilds for operating the
** Scaler ISR.
** \sa FAPI_VISCALE_VideoScalerHandleT
****************************************************************************
*/
typedef struct {

    //ISR State machine type.
    uint32_t                                          inUse; //0
    //ISR State machine type.
    FAPI_VISCALE_ScalerEnumT                          scalerType; //4

    //Fading State variables
    FAPI_VISCALE_InternalVideoFadingModeEnumT         iFadeState; //8
    int32_t                                           iFadeLimitValue; //12
    int32_t                                           iFadeCurrValue; //16
    int32_t                                           iFadeStepSize; //20

    //Enable/Disable State variables
    FAPI_VISCALE_EnableStatesEnumT                    iEnableState; //24

    //Request State variables
    FAPI_VISCALE_ScalerRequestTypeEnumT               iUserScalerReqState; //28
    FAPI_VISCALE_ScalerRequestTypeEnumT               iAutoScalerReqState; //32

    //Filter State variables
    FAPI_VISCALE_FilterStatesEnumT                    iFilterState; //36
    FAPI_VISCALE_VideoFilterSettingsDataT             iFilter; //40

    // Callbacks
    FAPI_VISCALE_ParamChangeInfoT                     paramChangeInfo; //680
    FAPI_VISCALE_ParamChangeCallbackT                 paramChangeCbk; //700
    void*                                             paramChangeOptData; //704
    //708
} FAPI_VISCALE_VideoScalerIsrDataT;
/*
*************************************************************************
** \brief Handle parameters for the Video Scaler driver.
** This data structure covers all parameters which need to be specified
** when an instance of the driver is opened.It also has feilds for Video
** scaler signature and scaler´s base address.
*************************************************************************
*/
typedef struct {
    uint32_t                                inUse; //0
    char_t                                  coreName[32]; //4
    uint64_t                                coreID; //36
    uint32_t                                baseAddress; //44
    FAPI_VISCALE_OpenParamsT                opParams; //48
    FAPI_VISCALE_SdScalerModeEnumT          sdMode; //60
    FAPI_VISCALE_HdScalerModeEnumT          hdMode; //64
    uint32_t                                pixPerBurst; //68
    uint32_t                                bitsPerPix; //72
    FAPI_VISCALE_ScalerParamsT              scalerParams; //76
    FAPI_VISCALE_ScalerParamsT              userRawScalerReq; //1192
    FAPI_VISCALE_AspectRatioEnumT           inputAspectRatio; //2308
    FAPI_VISCALE_AspectRatioEnumT           inputActiveAspectRatioL0; //2312
    FAPI_VISCALE_AspectRatioEnumT           inputActiveAspectRatioL1; //2316
    FAPI_VISCALE_AspectRatioEnumT           userDisplayAspectRatio; //2320
    FAPI_VISCALE_AspectRatioEnumT           displayAspectRatioL0; //2324
    FAPI_VISCALE_AspectRatioEnumT           displayAspectRatioL1; //2328
    FAPI_VISCALE_ScalingMethodEnumT         userScalingMethod; //2332
    FAPI_VISCALE_ScalingMethodEnumT         scalingMethod; //2336
    FAPI_VISCALE_ScalingMethodEnumT         fill_2340; //2340
    FAPI_VISCALE_VoRequestMapsDataT         afdScalerReq; //2344
    FAPI_VISCALE_VoRequestMapsDataT         userScalerReq; //2396
    FAPI_VISCALE_VoRequestMapsDataT         smScalerReq; //2448
    FAPI_VISCALE_VoRequestMapsDataT         autoScalerReq; //2500
    uint32_t                                currAfd; //2552
    FAPI_VISCALE_WssStateEnumT              userWssState; //2556
    FAPI_VISCALE_WssStateEnumT              wssState; //2560
    uint32_t                                currWss; //2564
//    int fill; //2564
    FAPI_VISCALE_VideoScalerIsrDataT*       isrDataPtr; //2568

    int32_t  (*Start)(FAPI_SYS_HandleT handle, 
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr); //2572
    int32_t  (*Stop)(FAPI_SYS_HandleT handle); //2576
    int32_t  (*EnableDisable)(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode); //2580
    uint32_t (*Alpha)(FAPI_SYS_HandleT handle,
                   FAPI_VISCALE_ParameterModeEnumT mode, uint32_t level); //2584
    int32_t  (*Resize)(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr); //2588
    int32_t  (*Hilight)(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode); //2592
    int32_t  (*AutoPlaneFading)(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode); //2596
    int32_t  (*AutoPlaneFadingStepSize)(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr); //2600
    int32_t  (*UpdateClut)(FAPI_SYS_HandleT handle, uint32_t* colour); //2604
    int32_t  (*UpdateSingleClut)(FAPI_SYS_HandleT handle,
                             uint32_t entryNumber, uint32_t entryColour); //2608
    void     (*AutoScale)(void* frameCropPtr, FAPI_SYS_HandleT handle, 
                                                   uint32_t suspendType); //2612
    int32_t  (*SetScalerToHdEncoder)(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle); //2616
    int32_t  (*SetScalingMethod)(FAPI_SYS_HandleT handle,
                          FAPI_VISCALE_ScalingMethodEnumT scalingMethod); //2620
    int32_t  (*SetDisplayAspectRatio)(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_AspectRatioEnumT displayAr); //2624
    int32_t  (*SetWssState)(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_WssStateEnumT wssState); //2628
    int32_t  (*SetParamChangeCallback)(FAPI_SYS_HandleT handle,
                  FAPI_VISCALE_ParamChangeCallbackT 
                                             paramChangeCallbackFunction,
                                               void* paramChangeOptData); //2632
    int32_t  (*GetWssSignal)(FAPI_SYS_HandleT handle,
                                                 uint32_t* wssSignalPtr); //2636
    //2640
} FAPI_VISCALE_VideoScalerHandleT;
//***********************************************************************
//***********************************************************************
//** Global Data & API
//***********************************************************************
//***********************************************************************
extern FAPI_VISCALE_VideoScalerIsrDataT
                            viscaleIsrData[FAPI_VISCALE_MAX_NUM_SCALERS];
//***********************************************************************
//***********************************************************************
//** API Functions
//***********************************************************************
//***********************************************************************

//***********************************************************************
//***********************************************************************
//** Local Data
//***********************************************************************
//***********************************************************************

//***********************************************************************
//***********************************************************************
//** Local APIs
//***********************************************************************
//***********************************************************************
//-------------------------Locks-----------------------------------------
void viscale_lock(void);
void viscale_unlock(void);
//-------------------------General---------------------------------------
void HSCALE(FAPI_VISCALE_VideoScalerHandleT* handlePtr, uint32_t layer, 
            uint32_t doubling_factor);
void VSCALE(FAPI_VISCALE_VideoScalerHandleT* handlePtr, uint32_t layer);
//-------------------------VO--------------------------------------------
int32_t fapi_viscale_vostart(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_vostop(FAPI_SYS_HandleT handle);
int32_t fapi_viscale_voenabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode);
uint32_t fapi_viscale_voalpha(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                         uint32_t level);
int32_t fapi_viscale_voresize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_voautoplanefading(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode);
int32_t fapi_viscale_voautoplanefadingstepsize(FAPI_SYS_HandleT handle, 
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr);
void    fapi_viscale_voautoscaler(void* frameCropPtr,
                          FAPI_SYS_HandleT handle, uint32_t suspendType);
int32_t fapi_viscale_setvoscalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle);
int32_t fapi_viscale_setvoscalingmethod(FAPI_SYS_HandleT handle,
                          FAPI_VISCALE_ScalingMethodEnumT scalingMethod);
int32_t fapi_viscale_setvodisplayaspectratio(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_AspectRatioEnumT displayAr);
int32_t fapi_viscale_setvowssstate(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_WssStateEnumT wssState);
int32_t  fapi_viscale_getvowsssignal(FAPI_SYS_HandleT handle,
                                                 uint32_t* wssSignalPtr);
int32_t  fapi_viscale_vosetparamchangecallback(FAPI_SYS_HandleT handle,
                  FAPI_VISCALE_ParamChangeCallbackT 
                                             paramChangeCallbackFunction,
                                               void* paramChangeOptData);
//-----------------------OSD1--------------------------------------------
int32_t fapi_viscale_osd1start(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_osd1stop(FAPI_SYS_HandleT handle);
int32_t fapi_viscale_osd1enabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode);
uint32_t fapi_viscale_osd1alpha(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                         uint32_t level);
int32_t fapi_viscale_osd1resize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_osd1autoplanefading(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode);
int32_t fapi_viscale_osd1autoplanefadingstepsize(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr);
int32_t fapi_viscale_osd1updateclut
                             (FAPI_SYS_HandleT handle, uint32_t* colour);
int32_t fapi_viscale_osd1updatesingleclut
                          (FAPI_SYS_HandleT handle, uint32_t entryNumber,
                                                   uint32_t entryColour);
int32_t fapi_viscale_setosd1scalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle);
//-----------------------OSD2--------------------------------------------
int32_t fapi_viscale_osd2start(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_osd2stop(FAPI_SYS_HandleT handle);
int32_t fapi_viscale_osd2enabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode);
uint32_t fapi_viscale_osd2alpha(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                         uint32_t level);
int32_t fapi_viscale_osd2resize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_osd2autoplanefading(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode);
int32_t fapi_viscale_osd2autoplanefadingstepsize(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr);
int32_t fapi_viscale_osd2updateclut
                             (FAPI_SYS_HandleT handle, uint32_t* colour);
int32_t fapi_viscale_osd2updatesingleclut
                          (FAPI_SYS_HandleT handle, uint32_t entryNumber,
                                                   uint32_t entryColour);
int32_t fapi_viscale_setosd2scalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle);
//-------------------------SD--------------------------------------------
int32_t fapi_viscale_sdstart(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_sdstop(FAPI_SYS_HandleT handle);
int32_t fapi_viscale_sdenabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode);
int32_t fapi_viscale_sdresize(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
void fapi_viscale_sdautoscaler(void* frameCropPtr,
                          FAPI_SYS_HandleT handle, uint32_t suspendType);
int32_t fapi_viscale_setsdscalertohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle);
int32_t fapi_viscale_setsddisplayaspectratio(FAPI_SYS_HandleT handle,
                                FAPI_VISCALE_AspectRatioEnumT displayAr);
//-------------------------CP--------------------------------------------
int32_t fapi_viscale_cpstart(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_cpstop(FAPI_SYS_HandleT handle);
int32_t fapi_viscale_cpenabledisable(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode);
int32_t fapi_viscale_cphilight(FAPI_SYS_HandleT handle,
                                   FAPI_VISCALE_ParameterModeEnumT mode);
uint32_t fapi_viscale_cpalpha(FAPI_SYS_HandleT handle,
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                         uint32_t level);
int32_t fapi_viscale_cpreposition(FAPI_SYS_HandleT handle,
                             FAPI_VISCALE_ScalerParamsT* scaleParamsPtr);
int32_t fapi_viscale_cpautoplanefading(FAPI_SYS_HandleT handle,
                           FAPI_VISCALE_VideoFadingModeEnumT fadingMode);
int32_t fapi_viscale_cpautoplanefadingstepsize(FAPI_SYS_HandleT handle, 
                                    FAPI_VISCALE_ParameterModeEnumT mode,
                                                  uint32_t* stepSizePtr);
int32_t fapi_viscale_cpupdateclut
                             (FAPI_SYS_HandleT handle, uint32_t* colour);
int32_t fapi_viscale_cpupdatesingleclut
                          (FAPI_SYS_HandleT handle, uint32_t entryNumber,
                                                   uint32_t entryColour);
int32_t fapi_viscale_setcptohdencoder(FAPI_SYS_HandleT handle,
                                         FAPI_SYS_HandleT viencHdHandle);
//-------------------------END-------------------------------------------

    #ifdef __cplusplus
    extern "C" {
    #endif


    #ifdef __cplusplus
    }
    #endif
#endif
