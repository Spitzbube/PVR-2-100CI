/*!
*****************************************************************************
**
** \file        ./subsystems/paint/osdhandler/src/osdhandler.h
**
** \brief       OSD handler for the paint middleware
**
** This file contains the declaration of the OSDHANDLER API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef OSDHANDLER_H
    #define OSDHANDLER_H

    #include <stdio.h>
    #include <stdint.h>
#if 0
    #include "fapex/abst_types.h"
    #include "fapex/abst_libviout.h"
#else
    #include "fapi/sys_services.h"
#endif

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    //! maximum horizontal resolution for OSDs
    #define OSDHANDLER_MAX_HRES               1920

    //! maximum vertical resolution for OSDs
    #define OSDHANDLER_MAX_VRES               1080

    //! maximum number of hardware layers
    #define OSDHANDLER_MAX_NUM_HW_LAYER             3

    // only for internal debug purposes used
    #define OSDHANDLER_DEBUG                        0

    // enable/disable support for virtual layers
    #ifndef OSDHANDLER_USE_VIRTUAL_LAYERS
    #define OSDHANDLER_USE_VIRTUAL_LAYERS           0
    #endif

    /*!
    ********************************************************************************
    ** Standard error codes for the OSDHANDLER driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define OSDHANDLER_ERR_BAD_PARAMETER \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define OSDHANDLER_ERR_OUT_OF_MEMORY \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define OSDHANDLER_ERR_ALREADY_INITIALIZED \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define OSDHANDLER_ERR_NOT_INITIALIZED \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define OSDHANDLER_ERR_FEATURE_NOT_SUPPORTED \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define OSDHANDLER_ERR_TIMEOUT \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define OSDHANDLER_ERR_DEVICE_BUSY \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define OSDHANDLER_ERR_INVALID_HANDLE \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define OSDHANDLER_ERR_SEMAPHORE_CREATE \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define OSDHANDLER_ERR_UNSUPPORTED_VERSION \
            (int32_t)(SUBSYS_PAINT_OSDHANDLER_MODULE_BASE + FAPI_ERR_UNSUPPORTED_VERSION)


    /*!
    ****************************************************************************
    ** Additional OSDHANDLER driver error codes
    ** that may occur for both, procedure calls for hardware and
    ** virtual layers. (reserved from -100 to -199)
    **
    ** Each error code shall be decreased in steps of 1.
    ****************************************************************************
    */
    /* \brief OSDHANDLER specific error code offset */
    #define OSDHANDLER_ERR_HLVL_BASE \
            (int32_t) (SUBSYS_PAINT_OSDHANDLER_MODULE_BASE - 100)

    //! an invalid layerId has been passed
    #define OSDHANDLER_ERR_BAD_LAYER_ID      (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 0)

    //! There was no handle allocated for the requested OSD/CP at initialization.
    #define OSDHANDLER_ERR_NO_OSD_HANDLE     (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 1)

    //! Returned if attempted to operate an OSD/CP in a bad colour mode.
    #define OSDHANDLER_ERR_BAD_COLOUR_MODE   (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 2)

    //! The passed dimensioning for an OSD/CP would cause it to exceed its maximum size.
    #define OSDHANDLER_ERR_OUT_OF_SIZE       (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 3)

    //! The passed coordinates are out of bounds of the OSD picture.
    #define OSDHANDLER_ERR_OUT_OF_BOUNDS     (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 4)

    //! The layer has not been started yet.
    #define OSDHANDLER_ERR_LAYER_NOT_STARTED (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 5)

    //! The limit of 16 KiB for the Cursor Plane is exceeded.
    #define OSDHANDLER_ERR_CP_16KB_EXCEEDED  (int32_t) (OSDHANDLER_ERR_HLVL_BASE - 6)


    /*!
    ****************************************************************************
    ** Additional OSDHANDLER error codes that may be returned through an
    ** error code pointer parameter. Each error code must allocate a single bit
    ** within a 32-bit word. If the error occured, the bit must be set to 1,
    ** otherwise 0.
    ** This scheme allows multiple error codes to be contained in a single word.
    ****************************************************************************
    */
    /*! OSD1 could not be opened at initialization. */
    #define OSDHANDLER_ERR_CODE_OSD1_OPEN   (uint32_t) 0x00000001

    /*! OSD2 could not be opened at initialization. */
    #define OSDHANDLER_ERR_CODE_OSD2_OPEN   (uint32_t) 0x00000002

    /*! Cursor Plane could not be opened at initialization. */
    #define OSDHANDLER_ERR_CODE_CP_OPEN     (uint32_t) 0x00000004

    /*! OSD1 could not be stopped at exit. */
    #define OSDHANDLER_ERR_CODE_OSD1_CLOSE  (uint32_t) 0x00000008

    /*! OSD2 could not be stopped at exit. */
    #define OSDHANDLER_ERR_CODE_OSD2_CLOSE  (uint32_t) 0x00000010

    /*! Cursor Plane could not be stopped at exit. */
    #define OSDHANDLER_ERR_CODE_CP_CLOSE    (uint32_t) 0x00000020

    /*! OSD1 could not be started by VISCALE. */
    #define OSDHANDLER_ERR_CODE_OSD1_START  (uint32_t) 0x00000040

    /*! OSD2 could not be started by VISCALE. */
    #define OSDHANDLER_ERR_CODE_OSD2_START  (uint32_t) 0x00000080

    /*! Cursor Plane could not be started by VISCALE. */
    #define OSDHANDLER_ERR_CODE_CP_START    (uint32_t) 0x00000100

    /*! OSD1 could not be stopped by VISCALE. */
    #define OSDHANDLER_ERR_CODE_OSD1_STOP   (uint32_t) 0x00000200

    /*! OSD2 could not be stopped by VISCALE. */
    #define OSDHANDLER_ERR_CODE_OSD2_STOP   (uint32_t) 0x00000400

    /*! Cursor Plane could not be stopped by VISCALE. */
    #define OSDHANDLER_ERR_CODE_CP_STOP     (uint32_t) 0x00000800

    /*! OSD1 resize failed. */
    #define OSDHANDLER_ERR_CODE_OSD1_RESIZE (uint32_t) 0x00001000

    /*! OSD2 resize failed. */
    #define OSDHANDLER_ERR_CODE_OSD2_RESIZE (uint32_t) 0x00002000

    /*! Cursor Plane resize failed. */
    #define OSDHANDLER_ERR_CODE_CP_RESIZE   (uint32_t) 0x00004000

    /*! OSD1 enable/disable failed. */
    #define OSDHANDLER_ERR_CODE_OSD1_ENABLE (uint32_t) 0x00008000

    /*! OSD2 enable/disable failed. */
    #define OSDHANDLER_ERR_CODE_OSD2_ENABLE (uint32_t) 0x00010000

    /*! Cursor Plane enable/disable failed. */
    #define OSDHANDLER_ERR_CODE_CP_ENABLE   (uint32_t) 0x00020000

    /*! OSD1 CLUT update failed. */
    #define OSDHANDLER_ERR_CODE_OSD1_CLUT   (uint32_t) 0x00040000

    /*! OSD2 CLUT update failed. */
    #define OSDHANDLER_ERR_CODE_OSD2_CLUT   (uint32_t) 0x00080000

    /*! Cursor Plane CLUT update failed. */
    #define OSDHANDLER_ERR_CODE_CP_CLUT     (uint32_t) 0x00100000

    /*! OSD1 plane fading failed. */
    #define OSDHANDLER_ERR_CODE_OSD1_FADE   (uint32_t) 0x00200000

    /*! OSD2 plane fading failed. */
    #define OSDHANDLER_ERR_CODE_OSD2_FADE   (uint32_t) 0x00400000

    /*! Cursor Plane plane fading failed. */
    #define OSDHANDLER_ERR_CODE_CP_FADE     (uint32_t) 0x00800000

    /*! Hilight function for the Cursor Plane failed. */
    #define OSDHANDLER_ERR_CODE_CP_HILIGHT  (uint32_t) 0x01000000

    /*! Setting up plane order failed. */
    #define OSDHANDLER_ERR_CODE_PLANE_ORDER (uint32_t) 0x02000000

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief OSD and CP related colour modes
    *************************************************************************
    */
    typedef enum
    {
        //! unknown OSD mode
        OSDHANDLER_OSD_MODE_UNKNOWN = (int32_t)0,

        //! 4-bit colour lookup table mode for OSD
        OSDHANDLER_OSD_MODE_CLUT_4BIT = (int32_t)1,

        //! 8-bit colour lookup table mode for OSD
        OSDHANDLER_OSD_MODE_CLUT_8BIT = (int32_t)2,

        //! 16-bit CCIR mode for OSD
        OSDHANDLER_OSD_MODE_16BIT = (int32_t)3,

        //! 16-bit mode for OSD with 4 bits for each component
        OSDHANDLER_OSD_MODE_4444 = (int32_t)4,

        //! 16-bit mode for OSD with 5 bits for each component and a single alpha switch
        OSDHANDLER_OSD_MODE_5551 = (int32_t)5,

        //! 32-bit mode for OSD with 8 bits for each colour component
        OSDHANDLER_OSD_MODE_32_24BIT = (int32_t)6,

        //! unknown mode for the Cursor Plane
        OSDHANDLER_CURSOR_MODE_UNKNOWN = (int32_t)7,

        //! 1-bit colour lookup table mode for Cursor Plane
        OSDHANDLER_CURSOR_MODE_1BIT = (int32_t)8,

        //! 2-bit colour lookup table mode for Cursor Plane
        OSDHANDLER_CURSOR_MODE_2BIT = (int32_t)9,

        //! 4-bit colour lookup table mode for Cursor Plane
        OSDHANDLER_CURSOR_MODE_4BIT = (int32_t)10,

        //! 8-bit colour lookup table mode for Cursor Plane
        OSDHANDLER_CURSOR_MODE_8BIT = (int32_t)11
    } OSDHANDLER_ColourModeT;

    /*!
    ****************************************************************************
    ** \brief bit organisation of pixel data in the OSD memory
    ****************************************************************************
    */
    typedef enum {
        //! Unknown layout format of OSD in memory
        OSDHANDLER_UNKNOWN_OSD_LAYOUT = (int32_t)0,
        //! RGB mode with alpha as most significant byte
        OSDHANDLER_OSD_LAYOUT_ARGB = 1,
        //! RGB mode with alpha as least significant byte
        OSDHANDLER_OSD_LAYOUT_RGBA = 2,
        //! CbYCr mode with alpha as most significant byte
        OSDHANDLER_OSD_LAYOUT_ACbYCr = 3,
        //! CbYCr mode with alpha as least significant byte
        OSDHANDLER_OSD_LAYOUT_CbYCrA = 4
    }OSDHANDLER_OsdLayoutEnumT;

    /*!
    *************************************************************************
    ** \brief   Specifies an encoder type. Needed by the Viscale driver in
    **          order to perform rescale operations.
    *************************************************************************
    */
    typedef enum
    {
        //! Unknown encoder
        OSDHANDLER_UNKNOWN_ENCODER = (int32_t)0,
        //! Scaling for PAL encoder
        OSDHANDLER_ENCODER_PAL,
        //! Scaling for NTSC encoder
        OSDHANDLER_ENCODER_NTSC,
        //! Scaling for SECAM encoder
        OSDHANDLER_ENCODER_SECAM
    } OSDHANDLER_EncoderEnumT;

    /*!
    ****************************************************************************
    ** \brief Enumeration type for user selection of plane order.
    ****************************************************************************
    */
    typedef enum {
        /*! Identifies the Video layer.*/
        OSDHANDLER_VIDEO_PLANE = 0,
        /*! Identifies the OSD1 layer.*/
        OSDHANDLER_OSD1_PLANE = 1,
        /*! Identifies the OSD2 layer.*/
        OSDHANDLER_OSD2_PLANE = 2,
        /*! Identifies the Cursor Plane layer.*/
        OSDHANDLER_CURSOR_PLANE = 3
    }OSDHANDLER_PlaneDataSelectorEnumT;

    /*!
    *************************************************************************
    ** \brief OSD and CP related initialization parameters
    *************************************************************************
    */
    typedef struct
    {
        /*! Specifies whether the driver should try to open the corresponding
        **  OSD layer and allocate the handle. Choose any value but 0 to
        **  open the layer.
        */
        uint32_t                    inUse; //0

        /*! Specifies the Colour Mode in which the OSD is going to be started up.
        **  See OSDHANDLER_ColourModeT for the available modes.
        */
        OSDHANDLER_ColourModeT      colourMode; //4

        /*! Specifies the bit organisation layout of the OSD.
        **  See FAPI_VISCALE_OsdLayoutEnumT for the available modes.
        */
        OSDHANDLER_OsdLayoutEnumT   osdLayout; //8

        /*! Points to a field of 256 colours (4 bytes each). Format: CbYCrA */
        uint32_t*                   defaultClutPtr; //12

        /*! Decides whether the alpha may be set globally for \b all pixels
        **  or if the global alpha value for each pixel is read from the
        **  colour information of the pixel itself.
        */
        uint32_t                    useGlobalAlpha; //16

        /*! Initial global alpha value that is used if global alpha is enabled.
        */
        uint32_t                    globalAlpha; //20
        //24
    } OSDHANDLER_OsdInitParamsT;

    /*!
    *************************************************************************
    ** \brief Init parameters for the OSDHANDLER
    *************************************************************************
    */
    typedef struct
    {
        int encoderType; //0
        FAPI_SYS_HandleT viencHandle; //4
        OSDHANDLER_OsdInitParamsT   osd1InitParams; //!< OSD1 related init params
        OSDHANDLER_OsdInitParamsT   osd2InitParams; //!< OSD2 related init params
        OSDHANDLER_OsdInitParamsT   cpInitParams;   //!< CP related init params
    } OSDHANDLER_InitParamsT;

    /*!
    *************************************************************************
    ** \brief   OSD and CursorPlane (CP) related start parameters.
    **
    ** \note    The actual resolution of the OSD/CP may differ from
    **          that you defined by the width and height parameters
    **          if scaling is set to 0.
    *************************************************************************
    */
    typedef struct
    {
        /*! The x position of the top left corner of the OSD/CP.      */
        uint32_t                    xPos; //0

        /*! The y position of the top left corner of the OSD/CP.      */
        uint32_t                    yPos; //4

        /*! The internal horizontal resolution of the OSD.            */
        uint32_t                    inputWidth; //8

        /*! The internal vertical resolution of the OSD.              */
        uint32_t                    inputHeight; //12

        /*! The horizontal resolution of the OSD on the video output.
        **  If this parameter is 0, no horizontal rescaling will be
        **  performed and the output width will be set to the internal
        **  horizontal resolution.
        */
        uint32_t                    outputWidth; //16

        /*! The vertical resolution of the OSD on the video output.
        **  If this parameter is 0, no vertical rescaling will be performed
        **  and the output height will be set to the internal vertical
        **  resolution for frame based pictures and to half of
        **  the internal vertical resolution for field based pictures.
        **  In order to avoid rescaling, the internal vertical resolution
        **  ('inputHeight') must be a multiple of two in the
        **  field based mode.
        */
        uint32_t                    outputHeight; //20

        /*!
        **  Indicates whether an OSD/CP should be interpreted as
        **  field based or frame based.
        **  If you provide this parameter with a 0, the OSD/CP
        **  memory will be interpreted as a field based picture,
        **  otherwise as a frame based one.
        */
        uint32_t                    frameBased; //24

        /*! Defines the memory base address that will be used for the OSD
        **  that is to be started. If you specify this parameter,
        **  you will have to take care that there is enough memory
        **  available for the chosen resolution at the current colour
        **  mode by calling #OSDHANDLER_GetOsdMemConsumption().
        **  If you set this parameter to NULL, the needed memory will be
        **  allocated from the heap automatically.
        */
        uint8_t*                   memoryBasePtr; //28
    } OSDHANDLER_StartParamsT;

    /*!
    ***************************************************************************
    ** \brief   Specifies how an OSDHANDLER function may behave and
    **          handle the other passed arguments.
    ***************************************************************************
    */
    typedef enum
    {

        OSDHANDLER_PARAMETER_GET = (int32_t)0,  //!< get the value
        OSDHANDLER_PARAMETER_SET,               //!< set the value
        OSDHANDLER_PARAMETER_INCREASE,          //!< increase the value
        OSDHANDLER_PARAMETER_DECREASE,          //!< decrease the value
        OSDHANDLER_PARAMETER_ON,                //!< switch something on
        OSDHANDLER_PARAMETER_OFF                //!< switch something off
    } OSDHANDLER_ModeParamT;

    /*!
    *************************************************************************
    ** \brief Layer parameters structure that is passed to other middleware
    **        from the paint library in order to draw pixels on the
    **        OSDs or the Cursor Plane.
    *************************************************************************
    */
    typedef struct
    {
        /*!
        ** the base address of the content of an OSD/CP is NULL if the OSD
        ** is not started. Therefore there is no memory allocated for the
        ** usage of this OSD.
        */
        uint32_t    pictureBase; //0
        /*! The internal horizontal resolution of the OSD/CP.       */
        uint32_t    xRes; //4
        /*! The internal vertical resolution of the OSD/CP.         */
        uint32_t    yRes; //8
        /*! The count of bits per pixel in the current colour mode. */
        uint32_t    bpp; //12
        /*! The colour mode that is set for the OSD/CP.             */
        OSDHANDLER_ColourModeT colourMode; //16
        /*! The format of the bit organization for one pixel.       */
        OSDHANDLER_OsdLayoutEnumT layoutMode; //20
        //24
    } OSDHANDLER_LayerParamsT;

    /*!
    *************************************************************************
    ** \brief   Union that provides access to an CbYCrA coded colour
    **          component wise and as a whole.
    *************************************************************************
    */
    typedef union
    {
        //! Element that contains the whole CbYCrA coded colour.
        uint32_t all;
        //! Element that contains the CbYCrA coded colour component wise.
        struct
        {
            //! Component that contains the alpha amount only.
            uint32_t alpha : 8;
            //! Component that contains the Cr amount only.
            uint32_t cr    : 8;
            //! Component that contains the Y amount only.
            uint32_t y     : 8;
            //! Component that contains the Cb amount only.
            uint32_t cb    : 8;
        } comp;
    } OSDHANDLER_CbYCrA__T;

    /*!
    *************************************************************************
    ** \brief   Union that provides access to an ARGB coded colour
    **          component wise and as a whole.
    *************************************************************************
    */
    typedef union
    {
        //! Element that contains the whole ARGB coded colour.
        uint32_t all;
        //! Element that contains the ARGB coded colour component wise.
        struct
        {
            //! Component that contains the blue amount only.
            uint32_t b     : 8;
            //! Component that contains the green amount only.
            uint32_t g     : 8;
            //! Component that contains the red amount only.
            uint32_t r     : 8;
            //! Component that contains the alpha amount only.
            uint32_t alpha : 8;
        } comp;
    } OSDHANDLER_ARGB__T;

    /*!
    *************************************************************************
    ** \brief   Union that provides access to an RGBA coded colour
    **          component wise and as a whole.
    *************************************************************************
    */
    typedef union
    {
        //! Element that contains the whole RGBA coded colour.
        uint32_t all;
        //! Element that contains the RGBA coded colour component wise.
        struct
        {
            //! Component that contains the alpha amount only.
            uint32_t alpha : 8;
            //! Component that contains the blue amount only.
            uint32_t b     : 8;
            //! Component that contains the green amount only.
            uint32_t g     : 8;
            //! Component that contains the red amount only.
            uint32_t r     : 8;
        } comp;
    } OSDHANDLER_RGBA__T;

    /*!
    *************************************************************************
    ** \brief   Structure used by OSDHANLDER_SetUpdateArea() function.
    **
    *************************************************************************
    */
    typedef struct
    {
        //! x position
        uint32_t x;
        //! y position
        uint32_t y;
        //! width
        uint32_t width;
        //! height
        uint32_t height;
    } OSDHANDLER_PositionT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************


    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
    int32_t  OSDHANDLER_Init(const OSDHANDLER_InitParamsT* initParamsPtr,
                             uint32_t* errorCodePtr);
    uint32_t  OSDHANDLER_Exit(void);
    uint32_t OSDHANDLER_IsInitialized(void);
    int32_t  OSDHANDLER_StartLayer(const uint32_t layerId,
                                   const OSDHANDLER_StartParamsT* startParamsPtr,
                                   uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_StopLayer(const uint32_t layerId,
                                  uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_ShowLayer(const uint32_t layerId,
                                  uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_HideLayer(const uint32_t layerId,
                                  uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_SetColourMode(const uint32_t layerId,
                                      const OSDHANDLER_ColourModeT colourMode,
                                      uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_SetLayoutMode(const uint32_t layerId,
                                      const OSDHANDLER_OsdLayoutEnumT layoutMode,
                                      uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_SetFillColour(const uint32_t layerId, const uint32_t colour);
    int32_t  OSDHANDLER_Clear(const uint32_t layerId);
    int32_t  OSDHANDLER_BitBlitFill(const uint32_t layerId,
                                    const uint32_t xx,
                                    const uint32_t yy,
                                    const uint32_t width,
                                    const uint32_t height,
                                    const uint32_t colour);
    int32_t  OSDHANDLER_SetClut(const uint32_t layerId,
                                uint32_t* newClutPtr,
                                uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_SetClutPartially(const uint32_t layerId,
                                         uint32_t*      newClutPtr,
                                         const uint32_t startIndex,
                                         const uint32_t entryCount,
                                         uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_GetClut(const uint32_t layerId, uint32_t* destClutPtr);
    int32_t  OSDHANDLER_Reposition(const uint32_t layerId,
                                   const uint32_t xx,
                                   const uint32_t yy,
                                   uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_Rescale(const uint32_t layerId,
                                const uint32_t outputWidth,
                                const uint32_t outputHeight,
                                uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_GetLayerParameters(const uint32_t layerId,
                                           OSDHANDLER_LayerParamsT* layerParamsPtr);
    int32_t  OSDHANDLER_GetPixelAddress(const uint32_t layerId,
                                        const uint32_t xx,
                                        const uint32_t yy,
                                        uint32_t* pixelBaseAddrPtr,
                                        uint32_t* pixelBitOffsetPtr);
    int32_t  OSDHANDLER_GlobalAlpha(const uint32_t layerId,
                                    const OSDHANDLER_ModeParamT mode,
                                    const uint32_t level);
    int32_t  OSDHANDLER_PlaneFading(const uint32_t layerId,
                                    const OSDHANDLER_ModeParamT mode,
                                    uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_CursorHilight(const OSDHANDLER_ModeParamT onOff,
                                      uint32_t* errorCodePtr);
    int32_t  OSDHANDLER_FlushPicture(const uint32_t layerId);
    int32_t  OSDHANDLER_PlaneOrder(OSDHANDLER_ModeParamT mode,
                                   uint32_t lowermost,
                                   uint32_t first,
                                   uint32_t second,
                                   uint32_t topmost,
                                   uint32_t* errorCodePtr);
    uint32_t OSDHANDLER_GetOsdMemConsumption(const uint32_t inputWidth,
                                             const uint32_t inputHeight,
                                             const OSDHANDLER_ColourModeT colourMode);
    uint32_t OSDHANDLER_ConvertARGB2CbYCrA_union(const OSDHANDLER_ARGB__T argbUnion);
    uint32_t OSDHANDLER_ConvertARGB2CbYCrA_word(const uint32_t argbWord);
    uint16_t OSDHANDLER_ConvertARGB2CbYCrA_5551(const uint16_t argb1555);
    uint32_t OSDHANDLER_ConvertCbYCrA2RGBA_union(const OSDHANDLER_CbYCrA__T cbycraUnion);
    uint32_t OSDHANDLER_ConvertCbYCrA2RGBA_word(const uint32_t cbycraWord);
    uint16_t OSDHANDLER_ConvertCbYCrA2RGBA_5551(const uint16_t cbycra5551);
    uint32_t OSDHANDLER_ConvertRGB2CCIR(const uint32_t leftARGB, const uint32_t rightARGB);

    // DEBUG functions:
    void     OSDHANDLERDEBUG_DumpLayerParams(uint32_t layer);

    #ifdef __cplusplus
    }
    #endif

#endif // OSDHANDLER_H
