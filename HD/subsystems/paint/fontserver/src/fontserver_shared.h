/*!
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/src/fontserver_shared.h
**
** \brief       Declarations for both public and private interface.
**
**              This file contains the declaration of the fontserver shared API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FONTSERVER_SHARED_H
    #define FONTSERVER_SHARED_H

    #include <stdint.h>
#if 0
    #include "fapex/abst_error.h"
#endif

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    #define FONTSERVER_MAX_FONT_COUNT           10
    #define FONTSERVER_MAX_ENGINE_COUNT         2
    #define FONTSERVER_ANTI_ALIAS_BIT_COUNT     3
    #define FONTSERVER_PRIVATE_USE_AREA_START   0xE000
    #define FONTSERVER_PRIVATE_USE_AREA_END     0xF8FF

    /*!
    ********************************************************************************
    ** Standard error codes for the fontserver
    ********************************************************************************
    */

    /*! Module base for fontserver. */
    #define SUBSYS_PAINT_FONTSERVER_MODULE_BASE (SUBSYS_PAINT_FONT_MODULE_BASE - 1000)

    /*! Bad parameter passed. */
    #define FONTSERVER_ERR_BAD_PARAMETER \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FONTSERVER_ERR_OUT_OF_MEMORY \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FONTSERVER_ERR_ALREADY_INITIALIZED \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FONTSERVER_ERR_NOT_INITIALIZED \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FONTSERVER_ERR_FEATURE_NOT_SUPPORTED \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FONTSERVER_ERR_TIMEOUT \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FONTSERVER_ERR_DEVICE_BUSY \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FONTSERVER_ERR_INVALID_HANDLE \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FONTSERVER_ERR_SEMAPHORE_CREATE \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FONTSERVER_ERR_UNSUPPORTED_VERSION \
            (int32_t)(SUBSYS_PAINT_FONTSERVER_MODULE_BASE + FAPI_ERR_UNSUPPORTED_VERSION)


    /*!
    ****************************************************************************
    ** Additional basic FONTSERVER error codes.
    **
    ** Each error code shall be decreased in steps of 1.
    ****************************************************************************
    */
    /* \brief FONTSERVER error code offset for basic errors*/
    #define FONTSERVER_ERR_BASE_BASIC \
                    (int32_t) (SUBSYS_PAINT_FONTSERVER_MODULE_BASE - 100)

    /*! The fontserver cannot determine the format of a font file that has
    **  been passed during initialization. Either the format is not known
    **  by the registered font engines or it is damaged.
    */
    #define FONTSERVER_ERR_BAD_FORMAT \
                    (int32_t) (FONTSERVER_ERR_BASE_BASIC - 0)

    /*! Returned when attemped to write at coordinates that are out of bounds
    **  of the OSD or CP plane.
    */
    #define FONTSERVER_ERR_OUT_OF_OSD_SIZE \
                    (int32_t) (FONTSERVER_ERR_BASE_BASIC - 1)

    /*! A processed string contains at least one character that causes
    **  a negative offset to the next glyph in the string.
    */
    #define FONTSERVER_ERR_NEGATIVE_CHAR_ADVANCE \
                    (int32_t) (FONTSERVER_ERR_BASE_BASIC - 2)

    /*! The maximum count of handles has been allocated. */
    #define FONTSERVER_ERR_MAX_HANDLE_COUNT \
                    (int32_t) (FONTSERVER_ERR_BASE_BASIC - 3)

    /*! The font colour does not fit to the current OSD colour mode. */
    #define FONTSERVER_ERR_BAD_COLOUR \
                    (int32_t) (FONTSERVER_ERR_BASE_BASIC - 4)

    /*! Maximum number of font slots already allocated. */
    #define FONTSERVER_ERR_MAX_FONT_COUNT \
                    (int32_t) (FONTSERVER_ERR_BASE_BASIC - 5)

    /*!
    ****************************************************************************
    ** Additional FONTSERVER error codes related to the Fujitsu specific
    ** bitmap font format.
    ** Each error code shall be decreased in steps of 1.
    ****************************************************************************
    */
    /* \brief FONTSERVER specific error code offset */
    #define FONTSERVER_ERR_BASE_FBF \
                    (int32_t) (SUBSYS_PAINT_FONTSERVER_MODULE_BASE - 200)

    /*! Can not initialize fontserver due to FBF engine problems. */
    #define FONTSERVER_ERR_FBF_FONT_INIT \
                    (int32_t) (FONTSERVER_ERR_BASE_FBF - 0)

    /*! The FBF file is damaged. */
    #define FONTSERVER_ERR_FBF_BAD_FBF_FILE \
                    (int32_t) (FONTSERVER_ERR_BASE_FBF - 1)

    /*! Error during OSD memory access. */
    #define FONTSERVER_ERR_FBF_MEMORY_FAULT \
                    (int32_t) (FONTSERVER_ERR_BASE_FBF - 2)

    /*! Kerning is not supported for FBF fonts. */
    #define FONTSERVER_ERR_FBF_KERNING_NOT_SUPPORTED \
                    (int32_t) (FONTSERVER_ERR_BASE_FBF - 3)

    /*!
    ****************************************************************************
    ** Additional FONTSERVER error codes related to the freetype library.
    **
    ** Each error code shall be decreased in steps of 1.
    ****************************************************************************
    */
    /* \brief FONTSERVER specific error code offset */
    #define FONTSERVER_ERR_BASE_FT \
                    (int32_t) (SUBSYS_PAINT_FONTSERVER_MODULE_BASE - 300)

    /*! Can not initialize freetype font engine. */
    #define FONTSERVER_ERR_FT_INIT \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 0)

    /*! Can not initialize freetype caching subsystem. */
    #define FONTSERVER_ERR_FT_INIT_CACHE_SUBSYSTEM \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 1)

    /*! Bad font format. */
    #define FONTSERVER_ERR_FT_BAD_FORMAT \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 2)

    /*! Error while calling FTC_Manager_LookupSize(). */
    #define FONTSERVER_ERR_FT_CANNOT_SET_FONT_SIZE \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 3)

    /*! Error while calling FTC_SBitCache_LookupScaler(). */
    #define FONTSERVER_ERR_FT_LOOKUP_SCALER \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 4)

    /*! The requested font size is not supported. */
    #define FONTSERVER_ERR_FT_BAD_FONT_SIZE \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 5)

    /*! The requested style is not present in the selected font. */
    #define FONTSERVER_ERR_FT_STYLE_NOT_AVAILABLE \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 6)

    /*! The FreeType library has not been registered to the fontserver.
    **  Possible reasons are:
    **      - The FreeType library has not been linked to the application.
    **      .
    **  Make sure that the FreeType library is linked in your application
    **  before the FONTSERVER library is linked.
    */
    #define FONTSERVER_ERR_FT_FREETYPE_NOT_REGISTERED \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 7)

    /*! The selected font does not support kerning. */
    #define FONTSERVER_ERR_FT_KERNING_NOT_SUPPORTED \
                    (int32_t) (FONTSERVER_ERR_BASE_FT - 8)


    /*!
    ****************************************************************************
    ** FONTSERVER character codes with special functions
    ****************************************************************************
    */

    /*! This code indicates that a new font index will be set. The
    **  subsequent 32-bit word will be used as the new font index. */
    #define FONTSERVER_CHAR_CODE_SET_FONT \
                FONTSERVER_PRIVATE_USE_AREA_START + 0

    /*! This code indicates that a new font size will be set. The
    **  subsequent 32-bit word will be used as the new font index. */
    #define FONTSERVER_CHAR_CODE_SET_SIZE \
                FONTSERVER_PRIVATE_USE_AREA_START + 1

    /*! This code indicates that a new colour will be set. The
    **  subsequent 32-bit word will be used as the new font index
    **  where the first byte indicates the 8 least significant bits
    **  and the fourth byte indicates the 8 most significant bits
    **  in the colour code. */
    #define FONTSERVER_CHAR_CODE_SET_COLOUR \
                FONTSERVER_PRIVATE_USE_AREA_START + 2


    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Identifier for font file formats.
    *************************************************************************
    */
    typedef enum
    {
        //! Indicator for an unknown file format
        FONTSERVER_FORMAT_UNKNOWN = (int32_t)0,

        //! Indicator for the Fujitsu specific bitmap font format
        FONTSERVER_FORMAT_FBF, //1

        //! Indicator for the TrueType font format
        FONTSERVER_FORMAT_TTF //2
    } FONTSERVER_FormatT;

    /*!
    *************************************************************************
    ** \brief Identifier for character spacing information.
    *************************************************************************
    */
    typedef enum
    {
        FONTSERVER_SPACING_UNDEFINED        = (int32_t)0x00,
        FONTSERVER_SPACING_CHARACTER_CELL   = (int32_t)0x43, // 'C'
        FONTSERVER_SPACING_MONOSPACE        = (int32_t)0x4D, // 'M'
        FONTSERVER_SPACING_PROPORTIONAL     = (int32_t)0x50  // 'P'
    } FONTSERVER_CharSpacingT;

    /*!
    *************************************************************************
    ** \brief Identifier for weight name information.
    *************************************************************************
    */
    typedef enum
    {
        FONTSERVER_WEIGHT_UNDEFINED         = (int32_t)0x00,
        FONTSERVER_WEIGHT_MEDIUM            = (int32_t)0x01,
        FONTSERVER_WEIGHT_THIN              = (int32_t)0x02,
        FONTSERVER_WEIGHT_DELICATE          = (int32_t)0x03,
        FONTSERVER_WEIGHT_EXTRA_LIGHT       = (int32_t)0x04,
        FONTSERVER_WEIGHT_LIGHT             = (int32_t)0x05,
        FONTSERVER_WEIGHT_NORMAL            = (int32_t)0x06,
        FONTSERVER_WEIGHT_SEMI_CONDENSED    = (int32_t)0x07,
        FONTSERVER_WEIGHT_CONDENSED         = (int32_t)0x08,
        FONTSERVER_WEIGHT_SEMI_BOLD         = (int32_t)0x09,
        FONTSERVER_WEIGHT_BOLD              = (int32_t)0x0A,
        FONTSERVER_WEIGHT_HEAVY             = (int32_t)0x0B,
        FONTSERVER_WEIGHT_EXTRA_BOLD        = (int32_t)0x0C,
        FONTSERVER_WEIGHT_EXTRA_HEAVY       = (int32_t)0x0D
    } FONTSERVER_WeightNameT;

    /*!
    *************************************************************************
    ** \brief Identifier for slant name information.
    *************************************************************************
    */
    typedef enum
    {
        FONTSERVER_SLANT_UNDEFINED        = (int32_t)0x00,
        FONTSERVER_SLANT_ITALIC           = (int32_t)0x49, // 'I'
        FONTSERVER_SLANT_OBLIQUE          = (int32_t)0x4F, // 'O'
        FONTSERVER_SLANT_ROMAN            = (int32_t)0x52, // 'R'
        FONTSERVER_SLANT_REVERS_ITALIC    = (int32_t)0x69, // 'i'
        FONTSERVER_SLANT_REVERS_OBLIQUE   = (int32_t)0x6F  // 'o'
    } FONTSERVER_SlantNameT;

    /*!
    *************************************************************************
    ** \brief Fontserver font styles.
    *************************************************************************
    */
    typedef enum
    {
        FONTSERVER_STYLE_NORMAL = 0,
        FONTSERVER_STYLE_ITALIC = 1,
        FONTSERVER_STYLE_BOLD   = 2
    } FONTSERVER_StyleT;

    #define FONTSERVER_MAX_STYLE_COUNT  3

    /*!
    *************************************************************************
    ** \brief Font information structure
    **
    ** This data structure covers all data of a font that may be of
    ** interest by the user or other applications.
    *************************************************************************
    */
    typedef struct
    {
        /*! Font format:                    <br>
        **  0x00   undefined                <br>
        **  0x01   FBF format               <br>
        **  0x02   TTF format
        */
        FONTSERVER_FormatT  fontFormat; //0

        /*! The family name of the font. */
        uint8_t* fontNamePtr; //4

        /*! Copyright information of the font. */
        uint8_t* copyrightInfoPtr; //8

        /*! Number of characters in the copyright string. */
        uint32_t copyrightLength; //12

        /*! Font size. The metric (pixels/points) is engine-dependent. */
        uint32_t size; //16

        /*! Max height of a single glyph. */
        uint32_t maxCharHeight; //20

        /*! Max width of a single glyph. */
        uint32_t maxCharWidth; //24

        /*! Ascender of the font (signed value). */
        int32_t ascender; //28

        /*! Descender of the font (signed value). */
        int32_t descender; //32

        /*! Encoding of the first character within the font. */
        uint32_t startCode; //36

        /*! Encoding of the last character within the font. */
        uint32_t endCode; //40

        /*! Number of characters within the font. */
        uint32_t characterCount; //44

        /*! The number of font units per EM square for this face. */
        uint32_t metricsRes; //48

        /*! Left-most coordinate. */
        int32_t  bBoxXMin; //52

        /*! Right-most coordinate. */
        int32_t  bBoxXMax; //56

        /*! Lower-most coordinate. */
        int32_t  bBoxYMin; //60

        /*! Top-most coordinate. */
        int32_t  bBoxYMax; //64

        /*! Character spacing information:  <br>
        **  0x00 undefined                  <br>
        **  0x43 Character Cell = 'C'       <br>
        **  0x4D Monospace = 'M'            <br>
        **  0x50 Proportional = 'P'
        */
        FONTSERVER_CharSpacingT charSpacing; //68

        /*! The weight name of the font:    <br>
        **  0x00 Undefined                  <br>
        **  0x01 Medium                     <br>
        **  0x02 Thin                       <br>
        **  0x03 Delicate                   <br>
        **  0x04 Extra light                <br>
        **  0x05 Light                      <br>
        **  0x06 Normal                     <br>
        **  0x07 Semi Condensed             <br>
        **  0x08 Condensed                  <br>
        **  0x09 Semi bold                  <br>
        **  0x0A Bold                       <br>
        **  0x0B Heavy                      <br>
        **  0x0C Extra Bold                 <br>
        **  0x0D Extra Heavy
        */
        FONTSERVER_WeightNameT weightName; //72

        /*! The slant name of the font:     <br>
        **  0x00 Undefined                  <br>
        **  0x49 Italic = 'I'               <br>
        **  0x4F Oblique = 'O'              <br>
        **  0x52 Roman = 'R'                <br>
        **  0x69 Revers Italic = 'i'        <br>
        **  0x6F Revers Oblique = 'o'
        */
        FONTSERVER_SlantNameT slantName; //76
        //80
    } FONTSERVER_InformationT;

    /*!
    *************************************************************************
    ** \brief   This structure specifies an aspect ratio conversion factor.
    *************************************************************************
    */
    typedef struct
    {
        /*! the amount to multiply width by*/
        uint32_t numerator;

        /*! the amount to divide width by*/
        uint32_t denominator;
    } FONTSERVER_AspectRatioT;

    /*!
    *************************************************************************
    ** \brief   This structure provides information about a single glyph.
    *************************************************************************
    */
    typedef struct
    {
        uint32_t  width;
        uint32_t  height;
        int32_t   left;
        int32_t   top;
        int32_t   xAdvance;
        int32_t   yAdvance;
        int32_t   pitch;
        const uint8_t** bufPtrPtr;
    } FONTSERVER_GlyphInfoT;

    /*!
    *************************************************************************
    ** \brief   Unique identifier for font faces.
    *************************************************************************
    */
    typedef struct
    {
        uint32_t*               filePtr;
        uint32_t                fileSize;
        FONTSERVER_StyleT       fontStyle;
    } FONTSERVER_FaceIdT;



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

    void  fontserverGetPixelAddress(uint32_t xx,                    \
                                    uint32_t yy,                    \
                                    uint32_t* pixelBaseAddrPtr,     \
                                    uint32_t* pixelBitOffsetPtr,    \
                                    const OSDHANDLER_LayerParamsT* layerParamsPtr);


    #ifdef __cplusplus
    }
    #endif

#endif
