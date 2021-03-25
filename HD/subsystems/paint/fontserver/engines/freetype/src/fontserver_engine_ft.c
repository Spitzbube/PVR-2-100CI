/*
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/engines/freetype/src/fontserver_engine_ft.c
**
** \brief       Font engine for TrueType/OpenType font format.
**
**              This file contains the implementation of the
**              freetype engine API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

/*! Enables/disables assembler optimized CPU routines. Default value: 1 */
#define ENGFT_USE_ASM  1

#include <stdint.h>
#if 0
#include "fapex/abst_types.h"
#endif
#include "osdhandler/osdhandler.h"
#include "fontserver/fontserver_engine_ft.h"

//FreeType 2.35 font engine
#include <freetype/ft2build.h>
#include FT_FREETYPE_H
#include FT_CACHE_H //freetype caching subsystem

#if ENGFT_USE_ASM && defined(__arm__) && !defined(__GNUC__)
#include "../../../../osdhandler/src/osdhandler_asm.h"
#endif /* ENGFT_USE_ASM */

//***************************************************************************
//***************************************************************************
//** Local Defines
//***************************************************************************
//***************************************************************************


//***************************************************************************
//***************************************************************************
//** Local Structures
//***************************************************************************
//***************************************************************************

/*!
*************************************************************************
** \brief   Structure that defines custom face identification for freetype
**          caching subsystem.
*************************************************************************
*/
typedef enum
{
    engftUninitialized = 0,
    engftOnlyCacheInitialized,
    engftFullInitialized
} ENGFT_InitStateT;

//***************************************************************************
//***************************************************************************
//** Local Functions Declarations
//***************************************************************************
//***************************************************************************

static int32_t  engftInit(void);
static void     engftExit(void);
static int32_t  engftCheckFont(uint32_t* fontDataPtr, uint32_t  fileSize);
static int32_t  engftGetFontInfo (FONTSERVER_HandleT* handlePtr,  \
                                  FONTSERVER_InformationT* infoPtr);
static uint32_t engftGetCharHeight (FONTSERVER_HandleT* handlePtr,   \
                                    uint16_t chCode,                 \
                                    int32_t* errorCodePtr);
static  int32_t engftGetCharWidth (FONTSERVER_HandleT* handlePtr,   \
                                   uint16_t chCode,                 \
                                   int32_t* errorCodePtr);
static int32_t  engftWriteChar (FONTSERVER_HandleT* handlePtr,           \
                                uint16_t chCode,                         \
                                OSDHANDLER_LayerParamsT* layerParamsPtr, \
                                uint32_t xx,                             \
                                uint32_t yy,                             \
                                int32_t* errorCodePtr);
static uint32_t engftUnicode2Index (FONTSERVER_HandleT* handlePtr,  \
                                    uint32_t chCode,                \
                                    int32_t* errorCodePtr);
static uint32_t engftIndex2Unicode (FONTSERVER_HandleT* handlePtr,  \
                                    uint32_t chIndex,               \
                                    int32_t* errorCodePtr);
static int32_t  engftGetKerning (FONTSERVER_HandleT* handlePtr,   \
                                 uint32_t ch1,                    \
                                 uint32_t ch2,                    \
                                 int32_t* errorCodePtr);
static int32_t  engftGetGlyphInfo (FONTSERVER_HandleT* handlePtr,   \
                                   uint16_t chCode,                 \
                                   FONTSERVER_GlyphInfoT* glyphInfoPtr);
static FT_Error engftFaceRequester( FTC_FaceID  fontFtcFaceId, \
                                    FT_Library  lib,           \
                                    FT_Pointer  requestData,  \
                                    FT_Face*    aface );
static int32_t engftCompareStyles(uint32_t ftFlag, FONTSERVER_StyleT style);

//***************************************************************************
//***************************************************************************
//** Local Data
//***************************************************************************
//***************************************************************************

/*! Initialization level of the freetype font engine:
**  0: uninitialized
**  1: caching subsystem initialized, font engine uninitialized
**  2: both caching subsystem and font engine initialized
**/
static ENGFT_InitStateT engftInitLevel = engftUninitialized;

// top level instance of the ft library:
static FT_Library       engftFtLibrary;
// specify size of glyph bitmaps:
static FTC_ScalerRec    engftFtScaler;
// cache manager:
static FTC_Manager      engftFtCacheManager;
// cache for small bitmaps:
static FTC_SBitCache    engftFtSbitCache;
// cache for the character map:
static FTC_CMapCache    engftFtCmapCache;
// small bitmaps:
static FTC_SBit         engftFtSbit;

//***************************************************************************
//***************************************************************************
//** Global Data
//***************************************************************************
//***************************************************************************

// The engine interface for the fontserver:
FONTSERVER_EngineT engftInterface = {engftInit,          \
                                     engftExit,          \
                                     engftCheckFont,     \
                                     engftGetFontInfo,   \
                                     engftGetCharHeight, \
                                     engftGetCharWidth,  \
                                     engftWriteChar,     \
                                     engftUnicode2Index, \
                                     engftIndex2Unicode, \
                                     engftGetKerning,    \
                                     engftGetGlyphInfo};

const FONTSERVER_EngineT* FONTSERVER_ENGINE_FT_INTERFACE_PTR = &engftInterface;

//***************************************************************************
//***************************************************************************
//** Local Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief   Initialize the freetype font engine.
**
**          This function initializes the freetype font engine.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_FT_INIT if the freetype engine could not be
**              initialized due to some internal error.
**          - #FONTSERVER_ERR_FT_INIT_CACHE_SUBSYSTEM if the freetype engine
**              could not be initialized due to the freetype caching subsystem.
**
** \sa
**          - engftExit()
**
*****************************************************************************
*/
static int32_t engftInit(void)
{
    FT_Error                error        = 0;   // FreeType error code
    int32_t                 error_code   = 0;   // FAPI error code
#ifndef _LINUX_FAPI
    FAPI_MMU_HeapParamsT    heap_params;

    memset(&heap_params, 0, sizeof(heap_params));
#endif /* _LINUX_FAPI */

    // init locally global data:
    memset(&engftFtScaler, 0, sizeof(FTC_ScalerRec));

    error_code = FAPI_OK;

#ifndef _LINUX_FAPI
    if((engftInitLevel == engftUninitialized) && (FT_memory_segment == NULL))
    {
        heap_params.sizeMBytes    = 1;
        heap_params.memoryMode    = FAPI_MMU_MEMORY_CACHED;
        heap_params.functionMode  = FAPI_MMU_FUNCTION_BGET;
        heap_params.strategyMode  = FAPI_MMU_STRATEGY_BESTFIT;
        heap_params.alignmentBits = FAPI_MMU_MAX_ALIGNMENT_BITS;
        FT_memory_segment = FAPI_MMU_CreateSegment(&heap_params, &error_code);
        // DEBUG message:
        //FAPI_MMU_ReportMemory(FT_memory_segment, 1);
        if( (FT_memory_segment == NULL) || (error_code != FAPI_OK))
        {
            return (FONTSERVER_ERR_FT_INIT);
        }
    }
#endif /* _LINUX_FAPI */
    if(engftInitLevel == engftUninitialized)
    {
        /*Initialize freetype 2 library*/
        error = FT_Init_FreeType(&engftFtLibrary);
        if (error)
        {
            return (FONTSERVER_ERR_FT_INIT);
        }
        /*Creates a new cache manager.*/
        error = FTC_Manager_New( engftFtLibrary,
                                 0,    /* max_faces, default 2 */
                                 0,    /* max_sizes, default 4 */
                                 0,    /* max_bytes, default 200KB */
                                 engftFaceRequester,
                                 NULL, /* don't need this.  */
                                 &engftFtCacheManager );
        if (error)
        {
            return (FONTSERVER_ERR_FT_INIT_CACHE_SUBSYSTEM);
        }
        /*Create a new charmap cache.*/
        error = FTC_CMapCache_New(engftFtCacheManager, &engftFtCmapCache);
        if (error)
        {
            return (FONTSERVER_ERR_FT_INIT_CACHE_SUBSYSTEM);
        }
        /*Creates a new cache to store small glyph bitmaps.*/
        error = FTC_SBitCache_New(engftFtCacheManager, &engftFtSbitCache);
        if (error)
        {
            return (FONTSERVER_ERR_FT_INIT_CACHE_SUBSYSTEM);
        }
    }

    // determine pixel/point size mode (pixel mode active):
    engftFtScaler.face_id = NULL;
    engftFtScaler.pixel   = 1;
    engftFtScaler.x_res   = 0;
    engftFtScaler.y_res   = 0;

    engftInitLevel = engftFullInitialized;
    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Exit the freetype font engine.
**
**          This function exits the freetype font engine.
**
** \sa
**          - engftInit()
**
*****************************************************************************
*/
static void engftExit()
{
    /*Destroys a given cache manager after emptying it.*/
    //FTC_Manager_Done(fontFtCacheManager);

    // only reset the static cache manager:
    FTC_Manager_Reset(engftFtCacheManager);

    memset(&engftFtScaler, 0, sizeof(engftFtScaler));

    engftInitLevel = engftOnlyCacheInitialized;
    return;
}

/*!
*****************************************************************************
** \brief   Check a font if it is a TrueType/OpenType font.
**
**          This function checks whether the passed fontDataPtr
**          may be processed by the freetype font engine.
**
** \param   fontDataPtr
**              Points to a font file.
** \param   fileSize
**              Font file size in bytes.
**
** \return
**          - #FAPI_OK if the font is usable.
**          - #FONTSERVER_ERR_BAD_FORMAT if the magic number of the font
**              file does not fit a TTF/OTF font.
**
*****************************************************************************
*/
static int32_t engftCheckFont(uint32_t* fontDataPtr, uint32_t  fileSize)
{
    fileSize = fileSize;

    // Check for magic number in TTF/OTF file format.
    if(*fontDataPtr != 0x00000100)
    {
        return (FONTSERVER_ERR_BAD_FORMAT);
    }
    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Retrieve font information.
**
**          This function retrieves as much information as possible of the
**          passed font and stores it to the infoPtr structure.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   infoPtr
**              Will receive all available information about the font.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_FT_BAD_FORMAT if the font can not
**              be processed by the engine.
**
*****************************************************************************
*/
static int32_t engftGetFontInfo(FONTSERVER_HandleT* handlePtr,  \
                                FONTSERVER_InformationT* infoPtr)
{
    uint32_t    px_size         = handlePtr->defSize;
    int32_t     ascender        = 0;
    int32_t     descender       = 0;
    int32_t     maxCharHeight   = 0;
    int32_t     maxCharWidth    = 0;
    FT_Error    error           = 0;
    uint32_t    character       = 0;
    FT_UInt     gindex          = 0;
    FT_Face     face            = NULL;
    FT_Size     size            = NULL;

    error = FTC_Manager_LookupFace \
                    (engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if (error)
    {
        return(FONTSERVER_ERR_FT_BAD_FORMAT);
    }

    engftFtScaler.face_id = (FTC_FaceID)(void*)handlePtr->faceIdPtr;
    engftFtScaler.width = handlePtr->aspectRatio.denominator ? \
        ((px_size * handlePtr->aspectRatio.numerator) /        \
        handlePtr->aspectRatio.denominator) : px_size;
    engftFtScaler.height  = px_size;
    error = FTC_Manager_LookupSize                   \
                        (engftFtCacheManager,        \
                         &engftFtScaler,             \
                         &size);
    if (error)
    {
        return (FONTSERVER_ERR_FT_CANNOT_SET_FONT_SIZE);
    }

    infoPtr->fontFormat    = FONTSERVER_FORMAT_TTF;
    if(face != NULL)
    {
        infoPtr->fontNamePtr   = (uint8_t*)face->family_name;
        infoPtr->metricsRes    = face->units_per_EM;
        infoPtr->bBoxXMin      = face->bbox.xMin;
        infoPtr->bBoxXMax      = face->bbox.xMax;
        infoPtr->bBoxYMin      = face->bbox.yMin;
        infoPtr->bBoxYMax      = face->bbox.yMax;
        infoPtr->startCode     = FT_Get_First_Char(face, &gindex);
        character = infoPtr->startCode;
        while(gindex != 0)
        {
            character = FT_Get_Next_Char(face, character, &gindex);
        }
        infoPtr->endCode = character;
        infoPtr->characterCount = (uint32_t)face->num_glyphs;
    }
    infoPtr->size              = px_size;
    if(size != NULL)
    {
        ascender        = (int32_t)(size->metrics.ascender);
        descender       = (int32_t)(size->metrics.descender);
        maxCharHeight   = (int32_t)(size->metrics.height);
        maxCharWidth    = (int32_t)(size->metrics.max_advance);

        // right shift with sign extension:
        infoPtr->ascender      = (int32_t)((ascender < 0) ?
                                 ((((uint32_t)ascender)>>6) | 0xFC000000) :
                                 (((uint32_t)ascender)>>6));
        infoPtr->descender     = (int32_t)((descender < 0) ?
                                 ((((uint32_t)descender)>>6) | 0xFC000000) :
                                 (((uint32_t)descender)>>6));
        infoPtr->maxCharHeight = (int32_t)((maxCharHeight < 0) ?
                                 ((((uint32_t)maxCharHeight)>>6) | 0xFC000000) :
                                 (((uint32_t)maxCharHeight)>>6));
        infoPtr->maxCharWidth  = (int32_t)((maxCharWidth < 0) ?
                                 ((((uint32_t)maxCharWidth)>>6) | 0xFC000000) :
                                 (((uint32_t)maxCharWidth)>>6));
    }
    infoPtr->charSpacing   = FONTSERVER_SPACING_UNDEFINED;
    infoPtr->weightName    = FONTSERVER_WEIGHT_UNDEFINED;
    infoPtr->slantName     = FONTSERVER_SLANT_UNDEFINED; //(uint8_t*)face->style_name;
    infoPtr->copyrightLength = 0;
    infoPtr->copyrightInfoPtr = NULL;
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Acquires the height in pixels of a given character for
**          the indicated font.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   chCode
**              The character whose height is to be calculated.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_FT_LOOKUP_SCALER
**                  if there occured an error while calling the scaler
**                  of the freetype library.
**              - #FONTSERVER_ERR_FT_BAD_FORMAT if the font can not
**                  be processed by the engine.
**
** \return  Height of the character in pixels on success.
**          0 if the character is not in the set of the selected font
**          or the height of the character is 0 (i.e.: space character).
**
*****************************************************************************
*/
static uint32_t engftGetCharHeight(FONTSERVER_HandleT* handlePtr,   \
                                   uint16_t chCode,                 \
                                   int32_t* errorCodePtr)
{
    FT_Error error         = 0;
    FT_UInt  glyph_index   = 0;
    FT_ULong ft_load_flags = 0;
    uint8_t  cmap_index    = 0;
    FT_Face  face          = NULL;

    error = FTC_Manager_LookupFace \
                    (engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if (error)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_BAD_FORMAT;
        return(0);
    }
    cmap_index = face->charmap ? (uint8_t)FT_Get_Charmap_Index(face->charmap) : 0;

    engftFtScaler.face_id = (FTC_FaceID)(void*)handlePtr->faceIdPtr;
    engftFtScaler.width = handlePtr->aspectRatio.denominator ?     \
        ((handlePtr->curSize * handlePtr->aspectRatio.numerator) / \
        handlePtr->aspectRatio.denominator) : handlePtr->curSize;
    engftFtScaler.height = handlePtr->curSize;
    glyph_index = FTC_CMapCache_Lookup                             \
                  (engftFtCmapCache, (FTC_FaceID)(void*)handlePtr->faceIdPtr, cmap_index, chCode);

    /* load glyph image into the slot (erase previous one) */
    if(handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_ON)
    {
        ft_load_flags = FT_LOAD_DEFAULT;
    }
    else
    {
        ft_load_flags = FT_LOAD_MONOCHROME;
    }
    error = FTC_SBitCache_LookupScaler         \
            (engftFtSbitCache, &engftFtScaler, \
             ft_load_flags, glyph_index, &engftFtSbit, NULL);
    if ((error) || (engftFtSbit == NULL))
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_FT_LOOKUP_SCALER;
        }
        return 0;
    }
    return (engftFtSbit->height);
}

/*!
*****************************************************************************
** \brief   Acquires the width in pixels of a given character for
**          the indicated font.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   chCode
**              The character whose width is to be calculated.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_FT_LOOKUP_SCALER
**                  if there occured an error while calling the scaler
**                  of the freetype library.
**              - #FONTSERVER_ERR_FT_BAD_FORMAT if the font can not
**                  be processed by the engine.
**
** \return  Width of the character in pixels on success.
**          0 if the character is not in the set of the selected font
**          or the width of the character is 0 (i.e.: space character).
**
*****************************************************************************
*/
static  int32_t engftGetCharWidth (FONTSERVER_HandleT* handlePtr,   \
                                   uint16_t chCode,                 \
                                   int32_t* errorCodePtr)
{
    FT_Error error         = 0;
    FT_UInt  glyph_index   = 0;
    FT_ULong ft_load_flags = 0;
    uint8_t  cmap_index    = 0;
    FT_Face  face          = NULL;

    error = FTC_Manager_LookupFace \
                    (engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if (error)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_BAD_FORMAT;
        return(0);
    }
    cmap_index = face->charmap ? (uint8_t)FT_Get_Charmap_Index(face->charmap) : 0;

    glyph_index = FTC_CMapCache_Lookup                               \
                  (engftFtCmapCache, (FTC_FaceID)(void*)handlePtr->faceIdPtr, cmap_index, chCode);
    /* load glyph image into the slot (erase previous one) */
    engftFtScaler.face_id = (FTC_FaceID)(void*)handlePtr->faceIdPtr;
    engftFtScaler.width = handlePtr->aspectRatio.denominator ?     \
        ((handlePtr->curSize * handlePtr->aspectRatio.numerator) / \
        handlePtr->aspectRatio.denominator) : handlePtr->curSize;
    engftFtScaler.height = handlePtr->curSize;
    if(handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_ON)
    {
        ft_load_flags = FT_LOAD_DEFAULT;
    }
    else
    {
        ft_load_flags = FT_LOAD_MONOCHROME;
    }
    error = FTC_SBitCache_LookupScaler         \
            (engftFtSbitCache, &engftFtScaler, \
             ft_load_flags, glyph_index, &engftFtSbit, NULL);
    if ((error) || (engftFtSbit == NULL))
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_FT_LOOKUP_SCALER;
        }
        return 0;
    }
    //return (engftFtSbit->width);
    return(engftFtSbit->xadvance);
}

/*!
*****************************************************************************
** \brief   Low level function that prints a single character on an OSD/CP.
**
**          This functions manipulates the OSD memory in a way that
**          the glyph appears on the screen at given coordinates relative to
**          the OSD/CP layer.
**
** \note    - Lint error 923 temporarily disabled (2 calls) within function.
**            Casts from type to type are necessary here for pointer
**            arithmetics.
**          - The yy coordinate indicates the baseline of the character
**            (freetype engine specific).
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   chCode
**              The code of the character that will be displayed.
** \param   layerParamsPtr
**              Points to the layer parameter structure which contains
**              all needed information of the OSD which will be manipulated.
** \param   xx
**              The x-coordinate on the given plane.
** \param   yy
**              The y-coordinate on the given plane. For the freetype engine
**              this parameter indicates the baseline of the character.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_FT_LOOKUP_SCALER
**                  if there occured an error while calling the scaler
**                  of the freetype library.
**              - #FONTSERVER_ERR_OUT_OF_OSD_SIZE
**                  if the character does not fit into the OSD plane
**                  at given coordinates.
**              - #FONTSERVER_ERR_FT_BAD_FORMAT if the font can not
**                  be processed by the engine.
**
** \return  Count of horizontal pixels of the written character
**              (may be negative for TTF fonts).
**
*****************************************************************************
*/
static int32_t engftWriteChar (FONTSERVER_HandleT* handlePtr,           \
                               uint16_t chCode,                         \
                               OSDHANDLER_LayerParamsT* layerParamsPtr, \
                               uint32_t xx,                             \
                               uint32_t yy,                             \
                               int32_t* errorCodePtr)
{
    uint32_t                x_pos               = 0;
    uint32_t                x_line              = 0;
    uint32_t                y_line              = 0;
    uint32_t                x_size              = 0;
    uint32_t                y_size              = 0;
    uint32_t                pixel_base_addr     = 0;
    uint32_t                pixel_bit_offset    = 0;
    uint32_t                colour_mask         = 0;
    uint32_t                data_mask           = 0;
    uint32_t                single_bit_mask     = 0;
    uint32_t                bpp                 = 0;
    uint32_t                data                = 0;
    int32_t                 comp1Bg             = 0; // background components
    int32_t                 comp2Bg             = 0;
    int32_t                 comp3Bg             = 0;
    int32_t                 comp4Bg             = 0;
    int32_t                 comp1Delta          = 0; // differences
    int32_t                 comp2Delta          = 0;
    int32_t                 comp3Delta          = 0;
    int32_t                 comp4Delta          = 0;
    uint8_t*                buf_read_ptr        = NULL;
    volatile uint32_t*      addr                = NULL;
    FT_UInt                 glyph_index         = 0;
    FT_Error                error               = 0;
    FT_ULong                ft_load_flags       = 0;
    FT_Face                 face                = NULL;
    uint8_t                 cmap_index          = 0;

#if ENGFT_USE_ASM && defined(__arm__) && !defined(__GNUC__)

    OSDHANDLER_RectT destRect;
    /*lint -save -e923 */
    uint32_t *layerStart = (uint32_t*)layerParamsPtr->pictureBase;
    /*lint -restore */
    uint32_t layerStride = (layerParamsPtr->xRes * layerParamsPtr->bpp) >> 3;
#endif /* ENGFT_USE_ASM */

    bpp = layerParamsPtr->bpp;

    error = FTC_Manager_LookupFace \
                    (engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if (error)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_BAD_FORMAT;
        return(0);
    }
    cmap_index = face->charmap ? (uint8_t)FT_Get_Charmap_Index(face->charmap) : 0;

    /* retrieve glyph index from character code */
    glyph_index = FTC_CMapCache_Lookup                 \
        (engftFtCmapCache, (FTC_FaceID)(void*)handlePtr->faceIdPtr, cmap_index, chCode);

    /* load glyph image into the slot (erase previous one) */
    engftFtScaler.face_id = (FTC_FaceID)(void*)handlePtr->faceIdPtr;
    engftFtScaler.width = handlePtr->aspectRatio.denominator ?     \
        ((handlePtr->curSize * handlePtr->aspectRatio.numerator) / \
        handlePtr->aspectRatio.denominator) : handlePtr->curSize;
    engftFtScaler.height = handlePtr->curSize;
    if(handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_ON)
    {
        ft_load_flags = FT_LOAD_DEFAULT;
    }
    else
    {
        ft_load_flags = FT_LOAD_MONOCHROME;
    }
    error = FTC_SBitCache_LookupScaler         \
            (engftFtSbitCache, &engftFtScaler, \
             ft_load_flags, glyph_index, &engftFtSbit, NULL);
    if ((error) || (engftFtSbit == NULL))
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_FT_LOOKUP_SCALER;
        }
        return 0;
    }

    //FAPI_SYS_PRINT_MSG("[fontserver/engft] xx + engftFtSbit->left = %d \n",
    //                    ((int32_t)xx + ((int32_t)engftFtSbit->left)));
    //FAPI_SYS_PRINT_MSG("[fontserver/engft] yy - engftFtSbit->top = %d \n",
    //                    (int32_t)yy - ((int32_t)engftFtSbit->top));
    //FAPI_SYS_PRINT_MSG("[fontserver/engft] engftFtSbit->width = %d \n",
    //                    (int32_t)engftFtSbit->width);
    //FAPI_SYS_PRINT_MSG("[fontserver/engft] engftFtSbit->height = %d \n",
    //                    (int32_t)engftFtSbit->height);

    // check for OSD boundary violations and set up y_line and x_line variables:
    if((((int32_t)xx + ((int32_t)engftFtSbit->left)) < 0)
    || (((int32_t)yy - ((int32_t)engftFtSbit->top)) < 0)
    || ((((int32_t)xx + ((int32_t)engftFtSbit->left)) + \
          (int32_t)engftFtSbit->width) > (int32_t)layerParamsPtr->xRes)
    || ((((int32_t)yy - ((int32_t)engftFtSbit->top)) + \
          (int32_t)engftFtSbit->height) > (int32_t)layerParamsPtr->yRes))
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_OUT_OF_OSD_SIZE;
        }
        return(0);
    }

    if((handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_ON)
    &&  ( (layerParamsPtr->colourMode == OSDHANDLER_OSD_MODE_32_24BIT)
        ||(layerParamsPtr->colourMode == OSDHANDLER_OSD_MODE_CLUT_8BIT)
        ||(layerParamsPtr->colourMode == OSDHANDLER_OSD_MODE_CLUT_4BIT)
        ||(layerParamsPtr->colourMode == OSDHANDLER_CURSOR_MODE_8BIT)
        ||(layerParamsPtr->colourMode == OSDHANDLER_CURSOR_MODE_4BIT)))
    {
        x_size = ((uint32_t)engftFtSbit->pitch);
        y_size = engftFtSbit->height;
        x_line = (uint32_t)((int32_t)xx + ((int32_t)engftFtSbit->left));
        y_line = (uint32_t)((int32_t)yy - (int32_t)engftFtSbit->top);

        // check if character has any pixels at all:
        if(x_size == 0)
        {
            return(engftFtSbit->xadvance);
        }

        buf_read_ptr = (uint8_t*)engftFtSbit->buffer;
        if(buf_read_ptr == NULL)
        {
            return(engftFtSbit->xadvance);
        }
        if(bpp >> 5) // bpp >= 32 ?
        {
            colour_mask = 0xFFFFFFFFUL;
        }
        else
        {
            colour_mask = (0x00000001UL << bpp) - 0x00000001UL;
        }

        fontserverGetPixelAddress(x_line, y_line, &pixel_base_addr, \
                                  &pixel_bit_offset, layerParamsPtr);
        /*lint -save -e923 */
        addr = (volatile uint32_t*)pixel_base_addr;
        /*lint -restore */
        if(addr == NULL) return 0;

        while (y_size)
        {
            if(*buf_read_ptr) // check if pixel is active
            {
                switch(layerParamsPtr->colourMode)
                {
                    case(OSDHANDLER_OSD_MODE_32_24BIT):
                        if(*buf_read_ptr == 0xFF)
                        {
                            *addr = handlePtr->curColour;
                        }
                        else
                        {
                            comp1Bg = ((*addr & 0xFF000000UL) >> 24);
                            comp2Bg = ((*addr & 0x00FF0000UL) >> 16);
                            comp3Bg = ((*addr & 0x0000FF00UL) >>  8);
                            comp4Bg =  (*addr & 0x000000FFUL);
                            comp1Delta = (int32_t) ((int32_t)((handlePtr->curColour & 0xFF000000UL) >> 24)) - comp1Bg;
                            comp2Delta = (int32_t) ((int32_t)((handlePtr->curColour & 0x00FF0000UL) >> 16)) - comp2Bg;
                            comp3Delta = (int32_t) ((int32_t)((handlePtr->curColour & 0x0000FF00UL) >>  8)) - comp3Bg;
                            comp4Delta = (int32_t) ((int32_t) (handlePtr->curColour & 0x000000FFUL)       ) - comp4Bg;
                            *addr = \
                                (((uint32_t)(comp1Bg + ((*buf_read_ptr * comp1Delta) / 255))) << 24) |
                                (((uint32_t)(comp2Bg + ((*buf_read_ptr * comp2Delta) / 255))) << 16) |
                                (((uint32_t)(comp3Bg + ((*buf_read_ptr * comp3Delta) / 255))) <<  8) |
                                (((uint32_t)(comp4Bg + ((*buf_read_ptr * comp4Delta) / 255))) <<  0);
                        }
                        break;
                    case(OSDHANDLER_OSD_MODE_CLUT_8BIT):
                    case(OSDHANDLER_OSD_MODE_CLUT_4BIT):
                    case(OSDHANDLER_CURSOR_MODE_8BIT):
                    case(OSDHANDLER_CURSOR_MODE_4BIT):
                        data_mask = colour_mask << (0x20UL - (pixel_bit_offset + bpp));
                        if(*buf_read_ptr == 255)
                        {
                            *addr = ((*addr) & (~data_mask)) |
                                    (handlePtr->curColour << (0x20UL - (pixel_bit_offset + bpp)));
                        }
                        else
                        {   /*lint -save -e778 */ // Constant expression may evaluate to 0
                            data = (*addr) & (~data_mask);
                            data |= (handlePtr->antiAliasClutPtrPtr\
                                    [((*addr) & data_mask)>> (0x20UL - (pixel_bit_offset + bpp))]\
                                    [*buf_read_ptr >> (8 - FONTSERVER_ANTI_ALIAS_BIT_COUNT)] \
                                    << (0x20UL - (pixel_bit_offset + bpp)));
                            *addr = data;
                            /*lint -restore */
                        }
                        break;
                    case(OSDHANDLER_OSD_MODE_16BIT): // CCIR
                    case(OSDHANDLER_OSD_MODE_4444):
                    case(OSDHANDLER_OSD_MODE_5551):
                    case(OSDHANDLER_CURSOR_MODE_2BIT):
                    case(OSDHANDLER_CURSOR_MODE_1BIT):
                    case(OSDHANDLER_OSD_MODE_UNKNOWN):
                    case(OSDHANDLER_CURSOR_MODE_UNKNOWN):
                    default:
                        break;
                }
            }
            pixel_bit_offset += bpp;
            if (pixel_bit_offset >> 5) // if (pixel_bit_offset > 31)
            {
                pixel_bit_offset = 0;
                addr++;
            }
            buf_read_ptr++;
            x_pos++;
            if(x_pos >= x_size)
            {
                x_pos = 0;
                y_line++;
                y_size--;
                if(!y_size) break;
                fontserverGetPixelAddress(x_line, y_line, &pixel_base_addr, \
                                          &pixel_bit_offset, layerParamsPtr);
                /*lint -save -e923 */
                addr = (volatile uint32_t*)pixel_base_addr;
                /*lint -restore */
            } //endif
        }
    }
    else // if(handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_OFF) and further colour modes
    {
        x_size = ((uint32_t)engftFtSbit->pitch) << 3;
        y_size = engftFtSbit->height;
        x_line = (uint32_t)((int32_t)xx + ((int32_t)engftFtSbit->left));
        y_line = (uint32_t)((int32_t)yy - (int32_t)engftFtSbit->top);

        // check if character has any pixels at all:
        if(x_size == 0)
        {
            return(engftFtSbit->xadvance);
        }
#if ENGFT_USE_ASM && defined(__arm__) && !defined(__GNUC__)
        if(bpp >= 8)
        {
            destRect.x = x_line;
            destRect.y = y_line;
            destRect.w = x_size;
            destRect.h = engftFtSbit->height;
            destRect.c = handlePtr->curColour;

            switch(bpp)
            {
            case 8:
                OSD_Blit1bppBEto8bpp ((uint8_t*)layerStart,
                                      &destRect,
                                      layerStride,
                                      (uint32_t*)(void*)engftFtSbit->buffer);
                return(engftFtSbit->xadvance);
            case 16:
                OSD_Blit1bppBEto16bpp((uint16_t*)layerStart,
                                      &destRect,
                                      layerStride,
                                      (uint32_t*)(void*)engftFtSbit->buffer);
                return(engftFtSbit->xadvance);
            case 32:
                OSD_Blit1bppBEto32bpp(layerStart,
                                      &destRect,
                                      layerStride,
                                      (uint32_t*)(void*)engftFtSbit->buffer);
                return(engftFtSbit->xadvance);
            default:
                break;
            }
        }
#endif /* ENGFT_USE_ASM */
        buf_read_ptr = (uint8_t*)engftFtSbit->buffer;
        if(buf_read_ptr == NULL)
        {
            return(engftFtSbit->xadvance);
        }
        /* Reverse the byte order for each 32 bit of bitmap data for correct display  */
        data |= (*buf_read_ptr++) << 24;
        data |= (*buf_read_ptr++) << 16;
        data |= (*buf_read_ptr++) <<  8;
        data |= (*buf_read_ptr++);

        if(bpp >> 5) // bpp >= 32 ?
        {
            colour_mask = 0xFFFFFFFFUL;
        }
        else
        {
            colour_mask = (0x00000001UL << bpp) - 0x00000001UL;
        }

        fontserverGetPixelAddress(x_line, y_line, &pixel_base_addr, \
                                  &pixel_bit_offset, layerParamsPtr);
        /*lint -save -e923 */
        addr = (volatile uint32_t*)pixel_base_addr;
        /*lint -restore */
        if(addr == NULL) return 0;

        single_bit_mask = 0x80000000; // 10000000 00000000 00000000 00000000

        while (y_size)
        {
            while (single_bit_mask)
            {
                if (data & single_bit_mask) // if current pixel is active...
                {
                    // 32 bits per pixel
                    if (bpp >> 5)
                    {
                        *addr = handlePtr->curColour;
                    }
                    // colour modes with less or equal 16 bits
                    else
                    {
                        /* shift the data_mask to the beginning of the bit sequence
                        ** at which the bitmap information is to be stored in *addr
                        */
                        data_mask = colour_mask << (0x20UL - (pixel_bit_offset + bpp));
                        /* overwrite the block within *addr that is relevant for
                        ** the current pixel and keep the remaining data as is:
                        */
                        *addr = ((*addr) & (~data_mask)) |
                                 (handlePtr->curColour << (0x20UL - (pixel_bit_offset + bpp)));
                    }
                }
                pixel_bit_offset += bpp;
                if (pixel_bit_offset >> 5) // if (pixel_bit_offset > 31)
                {
                    pixel_bit_offset = 0;
                    addr++;
                }
                single_bit_mask >>= 1;
                x_pos++;
                if (x_pos >= x_size) // check end of Pixel-Line
                {
                    x_pos = 0;
                    y_line++;
                    y_size--;

                    if (!y_size)
                    {
                        break;
                    }
                    fontserverGetPixelAddress(x_line, y_line, &pixel_base_addr, \
                                                &pixel_bit_offset, layerParamsPtr);
                    /*lint -save -e923 */
                    addr = (volatile uint32_t*)pixel_base_addr;
                    /*lint -restore */
                } //end if
            } //end while(single_bit_mask)

            data = 0;
            data |= (*buf_read_ptr++) << 24;
            data |= (*buf_read_ptr++) << 16;
            data |= (*buf_read_ptr++) <<  8;
            data |= (*buf_read_ptr++);
            single_bit_mask = 0x80000000;
        } //end while(y_size)
    }
    return(engftFtSbit->xadvance);
}

/*!
*****************************************************************************
** \brief   Determine the font internal character index by the unicode
**          character code.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   chCode
**              The unicode character code of the desired character.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK
**              - #FONTSERVER_ERR_FT_BAD_FORMAT
**
** \return  - 0 on failure.
**          - The internal character index of the requested character on success.
**
*****************************************************************************
*/
static uint32_t engftUnicode2Index (FONTSERVER_HandleT* handlePtr,  \
                                    uint32_t chCode,                \
                                    int32_t* errorCodePtr)
{
    FT_Face face = NULL;
    FT_Error error = 0;

    error = FTC_Manager_LookupFace(engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if(error)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_BAD_FORMAT;
        return(0);
    }
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return (FT_Get_Char_Index(face, chCode));
}

/*!
*****************************************************************************
** \brief   Determine the unicode character code by the font internal
**          character index.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   chIndex
**              The internal character index.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK
**              - #FONTSERVER_ERR_FT_BAD_FORMAT
**
** \return  - 0 on failure.
**          - The unicode coding for the requested character.
**
*****************************************************************************
*/
static uint32_t engftIndex2Unicode (FONTSERVER_HandleT* handlePtr,  \
                                    uint32_t chIndex,               \
                                    int32_t* errorCodePtr)
{
    FT_ULong charcode = 0;
    FT_UInt  gindex = 0;
    FT_Face face = NULL;
    FT_Error error = 0;

    error = FTC_Manager_LookupFace(engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if(error)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_BAD_FORMAT;
        return(0);
    }
    charcode = FT_Get_First_Char(face, &gindex);
    while((gindex != chIndex) && (gindex != 0))
    {
        charcode = FT_Get_Next_Char(face, charcode, &gindex);
    }
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return(charcode);
}

/*!
*****************************************************************************
** \brief   Determine the logical kerning of two characters.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   ch1
**              Character code of the left character.
** \param   ch2
**              Character code of the right character.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK
**              - #FONTSERVER_ERR_FT_BAD_FORMAT
**              - #FONTSERVER_ERR_FT_KERNING_NOT_SUPPORTED
**
** \return  - 0 if the face object contains no kerning data.
**          - logical kerning in horizontal direction.
**
*****************************************************************************
*/
static int32_t engftGetKerning(FONTSERVER_HandleT* handlePtr,   \
                               uint32_t ch1,                    \
                               uint32_t ch2,                    \
                               int32_t* errorCodePtr)
{
    FT_Vector       kerndata;
    FT_Face         face        = NULL;
    FT_Error error = 0;

    error = FTC_Manager_LookupFace(engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if(error)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_BAD_FORMAT;
        return(0);
    }
    if(!FT_HAS_KERNING(face))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_KERNING_NOT_SUPPORTED;
        return(0);
    }
    //Return the kerning vector in original font units.
    if(FT_Get_Kerning( face, ch1, ch2, (FT_UInt)FT_KERNING_UNSCALED, &kerndata))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FT_KERNING_NOT_SUPPORTED;
        return(0);
    }
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return kerndata.x;
}

/*!
*****************************************************************************
** \brief   Determine information about a single glyph.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   fontIndex
**              Unique indicator for a font that has been registered
**              successfully to this driver previously.
** \param   pxSize
**              Determines the font size in pixels for which the glyph
**              information will be determined.
** \param   aspectRatio
**              Determines the ratio of horizontal and vertical size.
** \param   chCode
**              The unicode character code of the desired character.
** \param   glyphInfoPtr
**              This structure will retrieve the desired glyph information.
**
** \return  - #FAPI_OK on success.
**          - #FONTSERVER_ERR_FT_LOOKUP_SCALER if an error occured when
**              calling FTC_SBitCache_LookupScaler().
**          - #FONTSERVER_ERR_FT_BAD_FORMAT if the font can not
**              be processed by the engine.
**
*****************************************************************************
*/
static int32_t  engftGetGlyphInfo (FONTSERVER_HandleT* handlePtr,   \
                                   uint16_t chCode,                 \
                                   FONTSERVER_GlyphInfoT* glyphInfoPtr)
{
    FT_Error error         = 0;
    FT_UInt  glyph_index   = 0;
    FT_ULong ft_load_flags = 0;
    FT_Face  face          = NULL;
    uint8_t  cmap_index    = 0;

    error = FTC_Manager_LookupFace \
                    (engftFtCacheManager, (FTC_FaceID)(void*)handlePtr->faceIdPtr, &face);
    if (error)
    {
        return(FONTSERVER_ERR_FT_BAD_FORMAT);
    }
    cmap_index = face->charmap ? (uint8_t)FT_Get_Charmap_Index(face->charmap) : 0;

    glyph_index = FTC_CMapCache_Lookup                             \
                    (engftFtCmapCache, (FTC_FaceID)(void*)handlePtr->faceIdPtr, cmap_index, chCode);
    /* load glyph image into the slot (erase previous one) */
    engftFtScaler.face_id = (FTC_FaceID)(void*)handlePtr->faceIdPtr;
    engftFtScaler.width = handlePtr->aspectRatio.denominator ?     \
        ((handlePtr->defSize * handlePtr->aspectRatio.numerator) / \
        handlePtr->aspectRatio.denominator) : handlePtr->defSize;
    engftFtScaler.height = handlePtr->defSize;
    if(handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_ON)
    {
        ft_load_flags = FT_LOAD_DEFAULT;
    }
    else
    {
        ft_load_flags = FT_LOAD_MONOCHROME;
    }
    error = FTC_SBitCache_LookupScaler         \
            (engftFtSbitCache, &engftFtScaler, \
             ft_load_flags, glyph_index, &engftFtSbit, NULL);
    if ((error) || (engftFtSbit == NULL))
    {
        return (FONTSERVER_ERR_FT_LOOKUP_SCALER);
    }
    glyphInfoPtr->width      = engftFtSbit->width;
    glyphInfoPtr->height     = engftFtSbit->height;
    glyphInfoPtr->left       = engftFtSbit->left;
    glyphInfoPtr->top        = engftFtSbit->top;
    glyphInfoPtr->xAdvance   = engftFtSbit->xadvance;
    glyphInfoPtr->yAdvance   = engftFtSbit->yadvance;
    glyphInfoPtr->pitch      = engftFtSbit->pitch;
    *glyphInfoPtr->bufPtrPtr = engftFtSbit->buffer;
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   The face requester is a function provided by the client application
**          to the cache manager, whose role is to translate an 'abstract' face
**          ID into a real FT_Face object.
**
** \param   fontFtcFaceId
**              The engine specific face object to be resolved.
** \param   lib
**              A handle to a FreeType library object.
** \param   requestData
**              Not needed here.
** \param   aface
**              A new FT_Face handle.
**
** \return  0 on success. Oterhwise some FreeType specific error code.
**
*****************************************************************************
*/
static FT_Error engftFaceRequester( FTC_FaceID  fontFtcFaceId, \
                                    FT_Library  lib,           \
                                    FT_Pointer  requestData,   \
                                    FT_Face*    aface )
{
    FT_Error error = 0;
    uint32_t ii = 0;
    FONTSERVER_FaceIdT* face_id_ptr = NULL;

    requestData = requestData; // dummy access to sate MISRA
    lib = lib;

    face_id_ptr = (FONTSERVER_FaceIdT*)(void*)fontFtcFaceId;
    ii = 0;
    do
    {
        error = FT_New_Memory_Face(engftFtLibrary,                   \
                                   (FT_Byte*)(face_id_ptr->filePtr), \
                                   (int32_t)face_id_ptr->fileSize,   \
                                   (int32_t)ii,                      \
                                   aface);
        if(error)
        {
            // return(error);
            return(FONTSERVER_ERR_FT_STYLE_NOT_AVAILABLE);
        }
        ii++;
    }while((ii < (uint32_t)(**aface).num_faces)
        && (engftCompareStyles((uint32_t)(**aface).face_flags, face_id_ptr->fontStyle)));

    if(engftCompareStyles((uint32_t)(**aface).face_flags, face_id_ptr->fontStyle))
    {
        return(0);
    }
    else
    {
        return(FONTSERVER_ERR_FT_STYLE_NOT_AVAILABLE);
    }
}

/*!
*****************************************************************************
** \brief   Check whether a Freetype style flag and a Fontserver style
**          parameter match.
**
** \param   ftFlag  The freetype style flag
** \param   style   The fontserver style parameter
**
** \return  1 if the flags match. 0 otherwise.
**
*****************************************************************************
*/
static int32_t engftCompareStyles(uint32_t ftFlag, FONTSERVER_StyleT style)
{
    //if(((ftFlag == 0) && (style == FONTSERVER_STYLE_NORMAL))
    //|| ((ftFlag == FT_STYLE_FLAG_ITALIC) && (style == FONTSERVER_STYLE_ITALIC))
    //|| ((ftFlag == FT_STYLE_FLAG_BOLD) && (style == FONTSERVER_STYLE_BOLD)))
    //{
    //    return(1);
    //}
    //return(0);
    if(((style == FONTSERVER_STYLE_ITALIC) && (ftFlag != FT_STYLE_FLAG_ITALIC))
    || ((style == FONTSERVER_STYLE_BOLD) && (ftFlag != FT_STYLE_FLAG_BOLD)))
    {
        return(0);
    }
    else
    {
        return(1);
    }
}

//***************************************************************************
//***************************************************************************
//** API Functions
//***************************************************************************
//***************************************************************************
