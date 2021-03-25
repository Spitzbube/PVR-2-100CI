/*!
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/src/fontserver.h
**
** \brief       Fontserver for different font formats.
**
** This file contains the declaration of the fontserver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FONTSERVER_H
    #define FONTSERVER_H

    #include <stdint.h>
#if 0
    #include "fapex/abst_error.h"
#endif
    #include "fontserver/fontserver_shared.h"

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    // Note: Error codes are defined in fontserver_shared.h

    #define FONTSERVER_TOTAL_HANDLE_COUNT       10

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Enumerates possible encoding schemes.
    *************************************************************************
    */
    typedef enum
    {
        //! Indicator for 8-bit character encoding
        FONTSERVER_ENCODING_8_BIT = (int32_t)0x00000000,

        //! Indicator for 16-bit character encoding
        FONTSERVER_ENCODING_16_BIT

    } FONTSERVER_EncodingT;

    /*!
    *************************************************************************
    ** \brief Init parameters for the fontserver.
    **
    *************************************************************************
    */
    typedef struct
    {
        uint32_t  numEngines;          //!< number of submodules for rendering
        uint32_t* enginesPtr;          //!< points submodule callback functions
    } FONTSERVER_InitParamsT;

    /*!
    *************************************************************************
    ** \brief Version of the FONTSERVER driver.
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
    **       FONTSERVER_OpenParamsT structure.
    **
    *************************************************************************
    */

    typedef enum
    {
        FONTSERVER_VERSION = (int32_t)0x00020000   //!< The current driver version
    } FONTSERVER_VersionEnumT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the FONTSERVER driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    *************************************************************************
    */
    typedef struct
    {
        /*!
           The version of the driver.
           \ref FONTSERVER_VersionEnumT "FONTSERVER_VERSION".
        */
        FONTSERVER_VersionEnumT version;
    } FONTSERVER_OpenParamsT;

    /*!
    *************************************************************************
    ** \brief Anti aliasing options.
    *************************************************************************
    */
    typedef enum
    {
        /*! Disable anti-aliasing. */
        FONTSERVER_ANTI_ALIAS_OFF = 0,

        /*! Enable anti-aliasing. */
        FONTSERVER_ANTI_ALIAS_ON
    } FONTSERVER_AntiAliasT;

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

    int32_t  FONTSERVER_Init(const FONTSERVER_InitParamsT* initParamsPtr);
    void     FONTSERVER_Exit(void);
    uint32_t FONTSERVER_RegisterFont(uint32_t* fontDataPtr,
                                    uint32_t fontFileSize,
                                    int32_t* errorCodePtr);
    int32_t  FONTSERVER_UnregisterFont(uint32_t fontIndex);
    FAPI_SYS_HandleT FONTSERVER_Open(const FONTSERVER_OpenParamsT* openParamsPtr,
                                     int32_t* errorCodePtr);
    int32_t  FONTSERVER_Close (FAPI_SYS_HandleT handle);
    int32_t  FONTSERVER_SetFont(FAPI_SYS_HandleT handle, uint32_t fontIndex);
    int32_t  FONTSERVER_SetSize(FAPI_SYS_HandleT handle, uint32_t size);
    int32_t  FONTSERVER_SetColour(FAPI_SYS_HandleT handle, uint32_t colour);
    int32_t  FONTSERVER_SetLayerId(FAPI_SYS_HandleT handle, uint32_t layerId);
    int32_t  FONTSERVER_SetEncoding(FAPI_SYS_HandleT handle, FONTSERVER_EncodingT encoding);
    int32_t  FONTSERVER_SetAspectRatio(FAPI_SYS_HandleT handle, \
                                       FONTSERVER_AspectRatioT aspectRatio);
    int32_t  FONTSERVER_SetStyle(FAPI_SYS_HandleT handle, FONTSERVER_StyleT style);
    int32_t  FONTSERVER_SetAntiAliasing(FAPI_SYS_HandleT handle,             \
                                        FONTSERVER_AntiAliasT antiAliasMode);
    uint32_t FONTSERVER_GetNumOfFonts(FAPI_SYS_HandleT handle, int32_t* errorCodePtr);
    int32_t  FONTSERVER_GetFontInfo(FAPI_SYS_HandleT handle, \
                                    FONTSERVER_InformationT* infoPtr);
    uint32_t FONTSERVER_GetStringPixelHeight(FAPI_SYS_HandleT handle,       \
                                             const uint8_t* charPtr,        \
                                             uint32_t length,               \
                                             int32_t* errorCodePtr);
    int32_t  FONTSERVER_GetStringPixelWidth (FAPI_SYS_HandleT handle,       \
                                             const uint8_t* charPtr,        \
                                             uint32_t length,               \
                                             int32_t* errorCodePtr);
    uint32_t FONTSERVER_GetNumCharsFitByPixelWidth (FAPI_SYS_HandleT handle,\
                                                    const uint8_t* charPtr, \
                                                    uint32_t pixelWidth,    \
                                                    int32_t* errorCodePtr);
    int32_t  FONTSERVER_PrintChar(FAPI_SYS_HandleT handle,          \
                                  const uint8_t* charPtr,           \
                                  uint32_t xx,                      \
                                  uint32_t yy,                      \
                                  int32_t* errorCodePtr);
    int32_t  FONTSERVER_PrintString(FAPI_SYS_HandleT handle,        \
                                    const uint8_t* charPtr,         \
                                    uint32_t length,                \
                                    uint32_t xx,                    \
                                    uint32_t yy,                    \
                                    int32_t* errorCodePtr);
    uint32_t FONTSERVER_Unicode2Index(FAPI_SYS_HandleT handle, \
                                      uint32_t chCode,         \
                                      int32_t* errorCodePtr);
    uint32_t FONTSERVER_Index2Unicode(FAPI_SYS_HandleT handle, \
                                      uint32_t chIndex,        \
                                      int32_t* errorCodePtr);
    int32_t  FONTSERVER_GetKerning(FAPI_SYS_HandleT handle, \
                                   uint32_t charLeft,       \
                                   uint32_t charRight,      \
                                   int32_t* errorCodePtr);
    int32_t  FONTSERVER_GetGlyphInfo(FAPI_SYS_HandleT handle,   \
                                     uint32_t chCode,           \
                                     FONTSERVER_GlyphInfoT* glyphInfoPtr);

    #ifdef __cplusplus
    }
    #endif
#endif
