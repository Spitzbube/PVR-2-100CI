/*!
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/src/fontserver_engine.h
**
** \brief       Declarations for the font engine interface.
**
**              This file contains the declaration of the font engine API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FONTSERVER_ENGINE_H
    #define FONTSERVER_ENGINE_H

    #include <stdint.h>
#if 0
    #include "fapex/abst_error.h"
#endif
    #include "fontserver/fontserver.h"
    #include "fontserver/fontserver_shared.h"

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************


    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Internal handle structure.
    *************************************************************************
    */
    typedef struct
    {
        uint32_t                id;             //!< magic number
        uint32_t                inUse : 1;      //!< handle allocation information
        FONTSERVER_OpenParamsT  openParams;     //!< openParams structure
        uint32_t                defFontIndex;   //!< default font
        uint32_t                curFontIndex;   //!< currently active font
        uint32_t                defSize;        //!< font size in pt
        uint32_t                curSize;        //!< currently active size
        uint32_t                defColour;      //!< font colour
        uint32_t                curColour;      //!< currently active colour
        uint32_t                layerId;        //!< defines a OSD layer (may be virtual)
        FONTSERVER_AspectRatioT aspectRatio;    //!< aspect ration correction
        FONTSERVER_EncodingT    encoding;       //!< 8-bit/16-bit encoding
        FONTSERVER_AntiAliasT   antiAlias;      //!< anti-aliasing on/off
        FONTSERVER_StyleT       style;          //!< style settings
        volatile FONTSERVER_FaceIdT* faceIdPtr; //!< unique face ID
        uint8_t                 antiAliasClutPtrPtr[256][1 << FONTSERVER_ANTI_ALIAS_BIT_COUNT];
    } FONTSERVER_HandleT;

    /*!
    *************************************************************************
    ** \brief Unified font engine interface that is used by the fontserver.
    **
    *************************************************************************
    */
    typedef struct
    {
        /*! Initialization of the engine subsystem before any fonts are
        **  registered to this engine.
        **  The return code will be passed through the fontserver interface
        **  when calling FONTSERVER_Init().
        */
        int32_t (* initEngine)(void);

        /*! Shutdown the font driver engine and release allocated resources.
        */
        void (* exitEngine) (void);

        /*! Checks whether a font can be rendered by the engine. If so, FAPI_OK
        **  must be returned. Otherwise any engine specific error code (!= 0).
        **  One may assume that the engine has been initialized successfully
        **  before this function is called.
        */
        int32_t (* checkFont) (uint32_t* fontDataPtr, uint32_t  fileSize); //8

        /*! Retrieve all available information about the font and store it to
        **  the structure of infoPtr.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        **  It may be assumed that the infoPtr is not NULL.
        */
        int32_t (* getFontInfo) (FONTSERVER_HandleT* handlePtr, \
                                 FONTSERVER_InformationT* infoPtr);

        /*! Get the height in pixels of a single character.
        **  Must be a positive value.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        */
        uint32_t (* getCharHeight) (FONTSERVER_HandleT* handlePtr,  \
                                    uint16_t chCode,                \
                                    int32_t* errorCodePtr);

        /*! Get the width in pixels of a single character.
        **  May be positive or negative.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        */
        int32_t  (* getCharWidth) (FONTSERVER_HandleT* handlePtr,  \
                                   uint16_t chCode,                \
                                   int32_t* errorCodePtr);

        /*! Write a single character into the OSD memory and
        **  return the horizontal advance in pixels.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        */
        int32_t  (* writeChar) (FONTSERVER_HandleT* handlePtr,           \
                                uint16_t chCode,                         \
                                OSDHANDLER_LayerParamsT* layerParamsPtr, \
                                uint32_t xx,                             \
                                uint32_t yy,                             \
                                int32_t* errorCodePtr);

        /*! Determine the font internal character index by the unicode
        **  character code.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        */
        uint32_t (* unicode2Index) (FONTSERVER_HandleT* handlePtr, \
                                    uint32_t chCode,               \
                                    int32_t* errorCodePtr);

        /*! Determine the unicode character code by a font internal
        **  character index.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the indicated font has
        **  previously been registered with the engine successfully.
        */
        uint32_t (* index2Unicode) (FONTSERVER_HandleT* handlePtr, \
                                    uint32_t chIndex,              \
                                    int32_t* errorCodePtr);

        /*! Determine the logical kerning of two characters.
        **  The kerning is defined to be the horizontal adjustment of the
        **  x-advance with respect to two specific characters.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        */
        int32_t (* getKerning) (FONTSERVER_HandleT* handlePtr, \
                                uint32_t ch1,                  \
                                uint32_t ch2,                  \
                                int32_t* errorCodePtr);

        /*! Determine information about a single glyph and store it to
        **  the glyphInfoPtr structure.
        **  One may assume that the engine is intialized successfully when
        **  this function is called and that the given handle has already
        **  been checked for validity.
        **  It may be assumed that the infoPtr is not NULL.
        */
        int32_t (* getGlyphInfo) (FONTSERVER_HandleT* handlePtr,        \
                                  uint16_t chCode,                      \
                                  FONTSERVER_GlyphInfoT* glyphInfoPtr);
    } FONTSERVER_EngineT;


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

#endif
