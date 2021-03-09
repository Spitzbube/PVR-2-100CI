/*!
*****************************************************************************
**
** \file        ./fapi/drv/vienc/src/drv_vienc.h
**
** \brief       Video Encoder Driver
**
** This file contains the declaration of the Video Encoder Driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_VIENC_H
    #define FAPI_VIENC_H

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
#define FAPI_VIENC_ERR_BAD_PARAMETER                                    \
                        (FAPI_VIENC_MODULE_BASE + FAPI_ERR_BAD_PARAMETER)
/*! Memory allocation failed. */
#define FAPI_VIENC_ERR_OUT_OF_MEMORY                                    \
                        (FAPI_VIENC_MODULE_BASE + FAPI_ERR_OUT_OF_MEMORY)
/*! Device already initialised. */
#define FAPI_VIENC_ERR_ALREADY_INITIALIZED                              \
                  (FAPI_VIENC_MODULE_BASE + FAPI_ERR_ALREADY_INITIALIZED)
/*! Device not initialised. */
#define FAPI_VIENC_ERR_NOT_INITIALIZED                                  \
                      (FAPI_VIENC_MODULE_BASE + FAPI_ERR_NOT_INITIALIZED)
/*! Feature or function is not available. */
#define FAPI_VIENC_ERR_FEATURE_NOT_SUPPORTED                            \
                (FAPI_VIENC_MODULE_BASE + FAPI_ERR_FEATURE_NOT_SUPPORTED)
/*! Timeout occured. */
#define FAPI_VIENC_ERR_TIMEOUT                                          \
                              (FAPI_VIENC_MODULE_BASE + FAPI_ERR_TIMEOUT)
/*! The device is busy, try again later. */
#define FAPI_VIENC_ERR_DEVICE_BUSY                                      \
                          (FAPI_VIENC_MODULE_BASE + FAPI_ERR_DEVICE_BUSY)
/*! Invalid handle was passed. */
#define FAPI_VIENC_ERR_INVALID_HANDLE                                   \
                       (FAPI_VIENC_MODULE_BASE + FAPI_ERR_INVALID_HANDLE)
/*! Semaphore could not be created. */
#define FAPI_VIENC_ERR_SEMAPHORE_CREATE                                 \
                     (FAPI_VIENC_MODULE_BASE + FAPI_ERR_SEMAPHORE_CREATE)
/*! The driver's used version is not supported. */
#define FAPI_VIENC_ERR_UNSUPPORTED_VERSION                              \
                  (FAPI_VIENC_MODULE_BASE + FAPI_ERR_UNSUPPORTED_VERSION)
/*
*************************************************************************
** Defines for specialized error codes which are very specific
** to the behaviour of this module. These codes are offset by -100 from
** the module´s general error codes.
*************************************************************************
*/
/*!
*************************************************************************
** \brief Error base for VIENC Driver.
*************************************************************************
*/
#define FAPI_VIENC_ERR_BASE                                             \
                                           (FAPI_VIENC_MODULE_BASE - 100)
/*!
*************************************************************************
** \brief Driver version mismatched. Driver update is required.
*************************************************************************
*/
#define FAPI_VIENC_ERR_DRV_VERSION_CHECK_FAILED                         \
                                              (FAPI_VIENC_ERR_BASE -   1)
/*!
*************************************************************************
** \brief Opening params are wrong. Recheck open params.
*************************************************************************
*/
#define FAPI_VIENC_ERR_INVALID_OPEN_PARAMS                              \
                                              (FAPI_VIENC_ERR_BASE -   2)
/*!
*************************************************************************
** \brief Illogical combination of open params was used.
**  Recheck open params.
*************************************************************************
*/
#define FAPI_VIENC_ERR_INVALID_COMBINATION_OF_OPEN_PARAMS               \
                                              (FAPI_VIENC_ERR_BASE -   3)
/*!
*************************************************************************
** \brief Opening multiple instances of driver for the given HW block.
**  First close and then reopen again.
*************************************************************************
*/
#define FAPI_VIENC_ERR_EXCEEDED_MAX_HANDLES                             \
                                              (FAPI_VIENC_ERR_BASE -   4)
/*!
*************************************************************************
** \brief This functionality is not supported by the given HW Block.
**  Wrong handle to the HW block was used.
*************************************************************************
*/
#define FAPI_VIENC_ERR_UNSUPPORTED_FUNCTIONALITY                        \
                                              (FAPI_VIENC_ERR_BASE -   5)
/*!
*************************************************************************
** \brief Internal check to verify the handle failed.
**  Wrong parameters was used.
*************************************************************************
*/
#define FAPI_VIENC_ERR_HANDLE_CHECK_FAILED                              \
                                              (FAPI_VIENC_ERR_BASE -   6)
/*!
*************************************************************************
** \brief Current operation could not be performed, as it may be blocked.
**  Use the related API to enable this functionality.
*************************************************************************
*/
#define FAPI_VIENC_ERR_HANDLE_OPERATION_BLOCKED                         \
                                              (FAPI_VIENC_ERR_BASE -   7)
/*!
*************************************************************************
** \brief Check if the device concerned is supported.
*************************************************************************
*/
#define FAPI_VIENC_ERR_UNKNOWN_DEVICE                                   \
                                              (FAPI_VIENC_ERR_BASE -   8)
/*!
*************************************************************************
** \brief wrong arguement.
                          Check if the arguement is has unexpected value.
*************************************************************************
*/
#define FAPI_VIENC_ERR_INVALID_ARGUEMENT_LIST                           \
                                              (FAPI_VIENC_ERR_BASE -   9)
/*!
*************************************************************************
** \brief Gpio problem. Check if the allocation had succeeded.
*************************************************************************
*/
#define FAPI_VIENC_ERR_RGB_GPIOS_ALLOCATION_FAILURE                     \
                                              (FAPI_VIENC_ERR_BASE -  10)
/*!
*************************************************************************
** \brief Gpio problem. Check if the allocation had succeeded.
*************************************************************************
*/
#define FAPI_VIENC_ERR_HSYNC_GPIOS_ALLOCATION_FAILURE                   \
                                              (FAPI_VIENC_ERR_BASE -  11)
/*!
*************************************************************************
** \brief Gpio problem. Check if the allocation had succeeded.
*************************************************************************
*/
#define FAPI_VIENC_ERR_VSYNC_GPIOS_ALLOCATION_FAILURE                   \
                                              (FAPI_VIENC_ERR_BASE -  12)
/*!
*************************************************************************
** \brief Gpio problem. Check if the allocation had succeeded.
*************************************************************************
*/
#define FAPI_VIENC_ERR_CLOCK_GPIOS_ALLOCATION_FAILURE                   \
                                              (FAPI_VIENC_ERR_BASE -  13)
//***********************************************************************
//***********************************************************************
//** Enumerrated encoderTypes
//***********************************************************************
//***********************************************************************
/*!
*************************************************************************
** \brief Version of the VIENC driver.
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
**       FAPI_VIENC_OpenParamsT structure.
**
*************************************************************************
*/
typedef enum {
    FAPI_VIENC_VERSION = (int32_t)0x00020001   //!< The current driver version
} FAPI_VIENC_VersionEnumT;
/*!
****************************************************************************
** \brief to get, Set, Inc , or Decrease the level
****************************************************************************
*/
typedef enum {
    //! Turn on a specified parameter or feature
    FAPI_VIENC_PARAMETER_ON,
    //! Turns off a specified parameter or feature
    FAPI_VIENC_PARAMETER_OFF
}FAPI_VIENC_ParameterModeEnumT;
/*!
*******************************************************************************
** \brief Enumerated type for colour system types.
*******************************************************************************
*/
typedef enum {
    /*! Specifies an unknown colour system encoderType*/
    FAPI_VIENC_UNKNOWN_COLOUR_SYSTEM = (int32_t)-1,
    /*! Specifies \b SECAM system colour. */
    FAPI_VIENC_COLOUR_SYSTEM_SECAM,
    /*! Specifies \b NTSC system colour. */
    FAPI_VIENC_COLOUR_SYSTEM_NTSC,
    /*! Specifies \b NTSC_4_43 system colour. */
    FAPI_VIENC_COLOUR_SYSTEM_NTSC_4_43,
    /*! Specifies \b PAL system colour. */
    FAPI_VIENC_COLOUR_SYSTEM_PAL,
    /*! Specifies \b PAL60 system colour. */
    FAPI_VIENC_COLOUR_SYSTEM_PAL_60,
    /*! Specifies \b PAL_M system colour. */
    FAPI_VIENC_COLOUR_SYSTEM_PAL_M,
    /*! Specifies \b PAL_N system colour.
    *  This is PAL-N except for Argentinia. It uses the same colour carrier
    *  freq as PAL-BGHI but the pedestal is different.
    */
    FAPI_VIENC_COLOUR_SYSTEM_PAL_N,
    /*! Specifies \b PAL_N_ARG system colour.
    *  This is PAL-N used only  in Argentinia. It has a different colour
    * carrier freq than PAL-BGHI.
    */
    FAPI_VIENC_COLOUR_SYSTEM_PAL_N_ARG
} FAPI_VIENC_ColourSystemEnumT;
/*!
*******************************************************************************
** \brief Enumerated type for analog encoder types.
*******************************************************************************
*/
typedef enum {
    /*! Specifies an unknown encoder encoderType*/
    FAPI_VIENC_UNKNOWN_ENCODER = (int32_t)-1,
    /*! Specifies an LCD output encoderType*/
    FAPI_VIENC_ENCODER_LCD, //0
    /*! Specifies a SD encoder encoderType*/
    FAPI_VIENC_ENCODER_SD, //1
    /*! Specifies a HD encoder encoderType*/
    FAPI_VIENC_ENCODER_HD //2
} FAPI_VIENC_EncoderEnumT;
/*!
*******************************************************************************
** \brief Enumerated type for analog encoder modes. Defines 50/60 Hz and I/P
** system.
*******************************************************************************
*/
typedef enum {
    /*! Specifies an unknown interlace or progressive encoderType*/
    FAPI_VIENC_UNKNOWN_IP_MODE = (int32_t)-1,

    /*! PAL Interlace mode available on VE SD*/
    FAPI_VIENC_IP_MODE_PAL, //0
    /*! PAL Interlace mode available on VE SD*/
    FAPI_VIENC_IP_MODE_NTSC, //1
    /*! PAL Interlace mode available on VE SD*/
    FAPI_VIENC_IP_MODE_SECAM, //2

    /*! 23.97 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 1080 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x2397P, //3
    /*! 24 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 1080 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x24P, //4
    /*! 25 Hz Progressive mode available on VE HD
        Active video region is 1920 pixels x 1080 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x25P, //5
    /*! 29.97 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 1080 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x2997P, //6
    /*! 30 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 1080 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x30P, //7
    /*! 50 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 540 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x50I, //8
    /*! 59.94 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 540 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x5994I, //9
    /*! 60 Hz Interlace mode available on VE HD
        Active video region is 1920 pixels x 540 lines.*/
    FAPI_VIENC_IP_MODE_1920x1080x60I, //10
    /*! 23.97 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x2397P, //11
    /*! 24 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x24P, //12
    /*! 25 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x25P, //13
    /*! 29.97 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x2997P, //14
    /*! 30 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x30P, //15
    /*! 50 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x50P, //16
    /*! 59.94 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x5994P, //17
    /*! 60 Hz Progressive mode available on VE HD
        Active video region is 1280 pixels x 720 lines.*/
    FAPI_VIENC_IP_MODE_1280x720x60P, //18
    /*! 50 Hz Interlace mode available on VE HD
        Active video region is 1440 pixels x 288 lines.*/
    FAPI_VIENC_IP_MODE_720x576x50I, //19
    /*! 50 Hz Progressive mode available on VE HD
        Active video region is 720 pixels x 576 lines.*/
    FAPI_VIENC_IP_MODE_720x576x50P, //20
    /*! 59.94 Hz Interlace mode available on VE HD
        Active video region is 1440 pixels x 240 lines.*/
    FAPI_VIENC_IP_MODE_720x480x5994I, //21
    /*! 59.94 Hz Progressive mode available on VE HD
        Active video region is 720 pixels x 480 lines.*/
    FAPI_VIENC_IP_MODE_720x480x5994P, //22
    /*! LCD progressive display available on GPIOs only
        The frame rate is same that of VE HD */
    FAPI_VIENC_IP_MODE_LCD_640x480x50P_LQ080V3DG01, //23
    /*! LCD progressive display available on GPIOs only
        The frame rate is same that of VE HD */
    FAPI_VIENC_IP_MODE_LCD_1024x768x50P_SVA150XG10TB //24
} FAPI_VIENC_InterlaceProgressiveEnumT;
/*!
*******************************************************************************
** \brief Enumerated type for output signal defination.
*******************************************************************************
*/
typedef enum {
    /*! Specifies an unknown colour component*/
    FAPI_VIENC_UNKNOWN_COLOUR_COMPONENT = (int32_t)-1,
    /*! Powers down the DACs of VE SD or VE HD*/
    FAPI_VIENC_COMPONENT_DAC_POWER_DOWN, //0

    /*! Specifies RGB output on VE HD ONLY*/
    FAPI_VIENC_COMPONENT_RGB, //1
    /*! Specifies YPrPb output on VE HD ONLY*/
    FAPI_VIENC_COMPONENT_YPrPb, //2

    /*! Specifies a standard \b COLOUR \b BAR. on VE SD only */
    FAPI_VIENC_COMPONENT_COLOURBAR, //3
    /*! Specifies only CVBS on VE SD ONLY*/
    FAPI_VIENC_COMPONENT_CVBS, //4
    /*! Specifies CVBS with YC output on VE SD ONLY for S Video*/
    FAPI_VIENC_COMPONENT_CVBS_YC, //5
    /*! Specifies CVBS with RGB output on VE SD ONLY*/
    FAPI_VIENC_COMPONENT_CVBS_RGB, //6
    /*! Specifies CVBS with YPrPb output on VE SD ONLY*/
    FAPI_VIENC_COMPONENT_CVBS_YPrPb //7
} FAPI_VIENC_ComponentEnumT;
/*!
*******************************************************************************
** \brief Enumerated type for switching on/off the cross chrominance filter.
** \note This feature is applicable to SD encoder only.
*******************************************************************************
*/
typedef enum {
    /*! Specifies an unknown Cross chrominance filter state*/
    FAPI_VIENC_UNKNOWN_CROSS_CHROMIANACE_FILTER = (int32_t)-1,
    /*! Parameter to turn off Cross chrominance filter*/
    FAPI_VIENC_CROSS_CHROMIANACE_FILTER_OFF,
    /*! Parameter to turn on Cross chrominance filter*/
    FAPI_VIENC_CROSS_CHROMIANACE_FILTER_ON
} FAPI_VIENC_CrossChrominanceFilterEnumT;
/*!
*******************************************************************************
** \brief Enumerated type for analog encoder modes clock setup.
*******************************************************************************
*/
typedef enum {
    /*! Clocks setup for unknown system system*/
    FAPI_VIENC_INIT_CLOCKS_UNKNOWN = (int32_t)-1,
    /*! Clocks setup for 1920 x 1080 23.97 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x2397P,
    /*! Clocks setup for 1920 x 1080 24 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x24P,
    /*! Clocks setup for 1920 x 1080 25 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x25P,
    /*! Clocks setup for 1920 x 1080 29.97 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x2997P,
    /*! Clocks setup for 1920 x 1080 30 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x30P,
    /*! Clocks setup for 1920 x 1080 50 Hz Interlace system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x50I,
    /*! Clocks setup for 1920 x 1080 59.94 Hz Interlace system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x5994I,
    /*! Clocks setup for 1920 x 1080 60 Hz Interlace system*/
    FAPI_VIENC_INIT_CLOCKS_1920x1080x60I,
    /*! Clocks setup for 1280 x 720 23.97 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x2397P,
    /*! Clocks setup for 1280 x 720 24 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x24P,
    /*! Clocks setup for 1280 x 720 25 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x25P,
    /*! Clocks setup for 1280 x 720 25 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x2997P,
    /*! Clocks setup for 1280 x 720 25 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x30P,
    /*! Clocks setup for 1280 x 720 50 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x50P,
    /*! Clocks setup for 1280 x 720 59.94 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x5994P,
    /*! Clocks setup for 1280 x 720 60 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_1280x720x60P,
    /*! Clocks setup for 720 x 576 50 Hz Interlace system*/
    FAPI_VIENC_INIT_CLOCKS_720x576x50I,
    /*! Clocks setup for 720 x 576 50 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_720x576x50P,
    /*! Clocks setup for 720 x 480 59.94 Hz Interlace system*/
    FAPI_VIENC_INIT_CLOCKS_720x480x5994I,
    /*! Clocks setup for 720 x 480 59.94 Hz Progressive system*/
    FAPI_VIENC_INIT_CLOCKS_720x480x5994P,
    /*! Clocks setup for any LCD system*/
    FAPI_VIENC_INIT_CLOCKS_LCD
} FAPI_VIENC_InitClocksEnumT;
/*!
****************************************************************************
** \brief Enumeration type for RGB Colours.
****************************************************************************
*/
typedef enum {
    /*! Selects the red colour component.*/
    FAPI_VIENC_RED = 0,
    /*! Selects the Green colour component.*/
    FAPI_VIENC_GREEN = 1,
    /*! Selects the BLUE colour component.*/
    FAPI_VIENC_BLUE = 2,
}FAPI_VIENC_ColourSelectorEnumT;
//***********************************************************************
//***********************************************************************
//** Data encoderTypes
//***********************************************************************
//***********************************************************************
/*!
*************************************************************************
** \brief Open parameters for the Video Encoder driver.
**
** This data structure covers all parameters which need to be specified
** when an instance of the driver is opened.
**
*************************************************************************
*/
typedef struct {
    /*!
    ** The version of the driver.
    ** \ref FAPI_VIENC_VersionEnumT "FAPI_VIENC_VERSION".
    */
    FAPI_VIENC_VersionEnumT version; //0
    /*! Specifies SD / HD or LCD mode.*/
    FAPI_VIENC_EncoderEnumT                   encoderType; //4
    /*! Specifies Interlace or Progressive mode.*/
    FAPI_VIENC_InterlaceProgressiveEnumT      interlaceProgressive; //8
    /*! Specifies the video encoder to be opened for which colour system.
        For LCD and HD encoderType this parameter is ignored.*/
    FAPI_VIENC_ColourSystemEnumT              colourSystem; //12
    /*! This parameter is used only for VE HD nad LCD.
        It specifies if RGB or YPrPb is generated.
        For VE SD set it to CVBS.*/
    FAPI_VIENC_ComponentEnumT                 colourComponent; //16
    /*! This parameter is used only for VE SD.
        It is a switch to turn on or off Cross-chrominance filter.
        In default or an unknown state CC filter is turned off.*/
    FAPI_VIENC_CrossChrominanceFilterEnumT    crossChrominanceFilter; //20
    //24
} FAPI_VIENC_OpenParamsT;
//***********************************************************************
//***********************************************************************
//** Global Data
//***********************************************************************
//***********************************************************************
extern FAPI_SYS_DriverT FAPI_VIENC_Driver0;
//***********************************************************************
//***********************************************************************
//** API Functions
//***********************************************************************
//***********************************************************************
#ifdef __cplusplus
extern "C" {
#endif
int32_t          FAPI_VIENC_Init(void);
void             FAPI_VIENC_Exit(void);
int32_t          FAPI_VIENC_InitClocks(
                                  FAPI_VIENC_InitClocksEnumT initClkSys);
FAPI_SYS_HandleT FAPI_VIENC_Open(const FAPI_VIENC_OpenParamsT* paramsPtr,
                                                  int32_t* errorCodePtr);
int32_t          FAPI_VIENC_Close(FAPI_SYS_HandleT handle);
int32_t          FAPI_VIENC_Start(FAPI_SYS_HandleT handle);
int32_t          FAPI_VIENC_Stop(FAPI_SYS_HandleT handle);
FAPI_VIENC_InterlaceProgressiveEnumT
                 FAPI_VIENC_GetSystemType(FAPI_SYS_HandleT handle);
int32_t          FAPI_VIENC_EnableDisableWss(FAPI_SYS_HandleT handle,
                                     FAPI_VIENC_ParameterModeEnumT mode);
int32_t          FAPI_VIENC_SetWssData(FAPI_SYS_HandleT handle,
                                                       uint32_t wssData);
int32_t          FAPI_VIENC_GetWssData(FAPI_SYS_HandleT handle,
                                                      uint32_t* wssData);
int32_t          FAPI_VIENC_SetColourComponent(FAPI_SYS_HandleT handle,
                              FAPI_VIENC_ComponentEnumT colourComponent);
int32_t          FAPI_VIENC_GetColourComponent(FAPI_SYS_HandleT handle,
                             FAPI_VIENC_ComponentEnumT* colourComponent);
int32_t          FAPI_VIENC_ChangeColourComponent(
                             FAPI_SYS_HandleT handle,
                                      FAPI_VIENC_ColourSelectorEnumT col,
                                                        uint32_t offset);

#ifdef __cplusplus
}
#endif
#endif
