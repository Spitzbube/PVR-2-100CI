/*
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/engines/fbf/src/fontserver_engine_fbf.c
**
** \brief       Font engine for FBF font format.
**
**              This file contains the implementation of the FBF engine API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

/*! Enables/disables assembler optimized CPU routines. */
#define ENGFBF_USE_ASM  0

#include <stdint.h>
#if 0
#include "fapex/abst_types.h"
#endif
#include "osdhandler/osdhandler.h"
#include "fontserver/fontserver_engine_fbf.h"

#if ENGFBF_USE_ASM && defined(__arm__) && !defined(__GNUC__)
#include "../../../../osdhandler/src/osdhandler_asm.h"
#endif /* ENGFBF_USE_ASM */

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
** \brief Header structure of a FBF font file
**
** \note  Lint Info 754 temporarily disabled since the magic number is an
**        inherent part of a FBF font file, even if it is not subsequently
**        referenced by the library.
**
** magicNumber:     no importance of this yet
** name:            name of the font and/or short description
** charSpacing:     font spacing information
** weightName:      weight trait of the font
** slantName:       slant trait of the font
** fontOptions:     contains information about the options that have
**                  been used when the font file was created such as
**                  AntiAliasing or copyright information
** fontHeight:      maximum possible height of a character
** fontWidth:       maximum possible width of a character
** numOfBlocks:     number of blocks that are covered in the font file
*************************************************************************
*/
typedef struct
{
    /*lint -esym(754,magicNumber,fontOptions) magicNumber is not referenced */
    uint32_t            magicNumber;
    uint8_t             name[16];
    uint16_t            size;
    int16_t             ascender;
    int16_t             descender;
    uint8_t             charSpacing;
    uint8_t             weightName;
    uint8_t             slantName;
    uint8_t             fontOptions;
    uint16_t            maxCharHeight;
    uint16_t            maxCharWidth;
    uint16_t            numOfBlocks;
} ENGFBF_FbfFileHeadT;

/*!
*************************************************************************
** \brief Header structure of a single block within the font file
**
** firstChar:       encoding of the first character within the block
** lastChar:        encoding of the last character within the block
** bmpBytes:        count of the bytes that are allocated by bitmap data
** blockBytes:      count of bytes of the whole block
**                  (except this header structure)
*************************************************************************
*/
typedef struct
{
    uint32_t            firstChar;
    uint32_t            lastChar;
    uint32_t            bmpBytes;
    uint32_t            blockBytes;
} ENGFBF_BitmapDataBlockInfoT;

/*!
*************************************************************************
** \brief Header structure of a bitmap data section for a single glyph:
**
** width:           actual width of this character
** height:          actual height of this character
** dropY:           count of lines from the top that do not contain
**                  any 'black pixels' (pixels that have to be modified)
*************************************************************************
*/
typedef union
{
    uint32_t            data;
    struct
    {
        unsigned int    width   : 10;
        unsigned int    height  : 11;
        unsigned int    dropY   : 11;
    } charBmpInfo;
} ENGFBF_BitmapDataHeadT;


//***************************************************************************
//***************************************************************************
//** Local Functions Declarations
//***************************************************************************
//***************************************************************************

static int32_t  engfbfInit(void);
static void     engfbfExit(void);
static int32_t  engfbfCheckFont(uint32_t* fontDataPtr, uint32_t  fileSize);
static int32_t  engfbfGetFontInfo (FONTSERVER_HandleT* handlePtr, \
                                   FONTSERVER_InformationT* infoPtr);
static uint32_t engfbfGetCharHeight (FONTSERVER_HandleT* handlePtr,  \
                                     uint16_t chCode,                \
                                     int32_t* errorCodePtr);
static int32_t  engfbfGetCharWidth (FONTSERVER_HandleT* handlePtr,  \
                                    uint16_t chCode,                \
                                    int32_t* errorCodePtr);
static int32_t  engfbfWriteChar (FONTSERVER_HandleT* handlePtr,           \
                                 uint16_t chCode,                         \
                                 OSDHANDLER_LayerParamsT* layerParamsPtr, \
                                 uint32_t xx,                             \
                                 uint32_t yy,                             \
                                 int32_t* errorCodePtr);
static uint32_t engfbfUnicode2Index (FONTSERVER_HandleT* handlePtr, \
                                     uint32_t chCode,               \
                                     int32_t* errorCodePtr);
static uint32_t engfbfIndex2Unicode (FONTSERVER_HandleT* handlePtr, \
                                     uint32_t chIndex,              \
                                     int32_t* errorCodePtr);
static int32_t  engfbfGetKerning (FONTSERVER_HandleT* handlePtr, \
                                  uint32_t ch1,                  \
                                  uint32_t ch2,                  \
                                  int32_t* errorCodePtr);
static int32_t  engfbfGetGlyphInfo (FONTSERVER_HandleT* handlePtr,        \
                                    uint16_t chCode,                      \
                                    FONTSERVER_GlyphInfoT* glyphInfoPtr);
static uint32_t* engfbfGetCharBitmapStartAddr (uint32_t* fontDataPtr, \
                                               const uint32_t character);

//***************************************************************************
//***************************************************************************
//** Local Data
//***************************************************************************
//***************************************************************************

//***************************************************************************
//***************************************************************************
//** Global Data
//***************************************************************************
//***************************************************************************

// The engine interface for the fontserver:
FONTSERVER_EngineT engfbfInterface = {engfbfInit,          \
                                      engfbfExit,          \
                                      engfbfCheckFont,     \
                                      engfbfGetFontInfo,   \
                                      engfbfGetCharHeight, \
                                      engfbfGetCharWidth,  \
                                      engfbfWriteChar,     \
                                      engfbfUnicode2Index, \
                                      engfbfIndex2Unicode, \
                                      engfbfGetKerning,    \
                                      engfbfGetGlyphInfo};

const FONTSERVER_EngineT* FONTSERVER_ENGINE_FBF_INTERFACE_PTR = &engfbfInterface;

//***************************************************************************
//***************************************************************************
//** Local Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief   Initialize the FBF font engine.
**
** This function initializes the FBF font engine.
**
** \return
**          - #FAPI_OK on success.
**
** \sa
**          - engfbfExit()
**
*****************************************************************************
*/
static int32_t engfbfInit(void)
{
    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Exit the FBF font engine.
**
** This function exits the FBF font engine.
**
** \sa
**          - engfbfInit()
**
*****************************************************************************
*/
static void engfbfExit()
{
    return;
}

/*!
*****************************************************************************
** \brief   Check a font if it is a FBF font.
**
**          This function checks whether the passed fontDataPtr is a FBF
**          font file.
**
** \param   fontDataPtr
**              Points to a font file.
** \param   fileSize
**              Size of the font file in bytes.
**
** \return
**          - #FAPI_OK if the font is in FBF format.
**          - #FONTSERVER_ERR_BAD_PARAMETER if the fontDataPtr does not
**              point an FBF font file.
**
*****************************************************************************
*/
static int32_t engfbfCheckFont(uint32_t* fontDataPtr, uint32_t  fileSize)
{
    fileSize = fileSize;

    // Check for magic number in FBF file format.
    if(*fontDataPtr == 0x464f4e54)
    {
        return (FAPI_OK);
    }
    else return (FONTSERVER_ERR_BAD_FORMAT);
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
**
*****************************************************************************
*/
static int32_t engfbfGetFontInfo(FONTSERVER_HandleT* handlePtr, \
                                 FONTSERVER_InformationT* infoPtr)
{
    uint8_t* font_data_ptr = (uint8_t*)handlePtr->faceIdPtr->filePtr;
    uint32_t block_count   = 0;
    uint32_t start_code    = 0;
    uint32_t end_code      = 0;

    infoPtr->fontFormat         = FONTSERVER_FORMAT_FBF;
    infoPtr->fontNamePtr        = \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->name;
    infoPtr->size               = \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->size;
    infoPtr->maxCharHeight      = \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->maxCharHeight;
    infoPtr->maxCharWidth       = \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->maxCharWidth;
    infoPtr->ascender           = \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->ascender;
    infoPtr->descender          = \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->descender;
    infoPtr->charSpacing        = (FONTSERVER_CharSpacingT) \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->charSpacing;
    infoPtr->weightName         = (FONTSERVER_WeightNameT) \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->weightName;
    infoPtr->slantName          = (FONTSERVER_SlantNameT) \
                ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->slantName;

    block_count = ((ENGFBF_FbfFileHeadT*)(void*)font_data_ptr)->numOfBlocks;
    font_data_ptr += sizeof(ENGFBF_FbfFileHeadT);
    if (block_count == 0)
    {
        start_code = 0;
        end_code = 0;
    }
    else
    {
        start_code = ((ENGFBF_BitmapDataBlockInfoT*)(void*)font_data_ptr)->firstChar;
        block_count--;
        // let font_data_ptr point to the beginning of the last block after loop
        while(block_count--)
        {
            font_data_ptr += (sizeof(ENGFBF_BitmapDataBlockInfoT) + \
                    ((ENGFBF_BitmapDataBlockInfoT*)(void*)font_data_ptr)->blockBytes);
        }
        end_code = ((ENGFBF_BitmapDataBlockInfoT*)(void*)font_data_ptr)->lastChar;
    }

    // now get behind the last bitmap data block:
    font_data_ptr += (sizeof(ENGFBF_BitmapDataBlockInfoT) + \
                    ((ENGFBF_BitmapDataBlockInfoT*)(void*)font_data_ptr)->blockBytes);

    infoPtr->startCode          = start_code;
    infoPtr->endCode            = end_code;
    infoPtr->copyrightLength    = *font_data_ptr++;
    infoPtr->copyrightInfoPtr   = font_data_ptr;
    infoPtr->characterCount = (end_code - start_code) + 1;
    infoPtr->metricsRes = 1;
    infoPtr->bBoxXMin = 0;
    infoPtr->bBoxXMax = (int32_t) infoPtr->maxCharWidth / 2;
    infoPtr->bBoxYMin = 0;
    infoPtr->bBoxYMax = (int32_t) infoPtr->maxCharHeight / 2;

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Acquires the height in pixels of a given character for
**          the passed FBF font file.
**          The passed font is assumed to be checked for beeing in FBF
**          format previously.
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
**              - #FONTSERVER_ERR_FBF_BAD_FBF_FILE
**                  if the FBF file is damaged.
**
** \return  Height of the character in pixels on success.
**          0 if the character is not in the set of the selected font
**          or the height of the character is 0 (i.e.: space character).
**
*****************************************************************************
*/
static uint32_t engfbfGetCharHeight(FONTSERVER_HandleT* handlePtr,  \
                                    uint16_t chCode,                \
                                    int32_t* errorCodePtr)
{
    uint32_t*               char_block_ptr = NULL;
    ENGFBF_BitmapDataHeadT  char_bmp_head;
    uint32_t* font_data_ptr = handlePtr->faceIdPtr->filePtr;

    char_block_ptr = (uint32_t*)engfbfGetCharBitmapStartAddr \
                                            (font_data_ptr, chCode);
    if (char_block_ptr == NULL)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FBF_BAD_FBF_FILE;
        return 0;
    }
    char_bmp_head.data = *char_block_ptr;
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return (char_bmp_head.charBmpInfo.height + char_bmp_head.charBmpInfo.dropY);
}

/*!
*****************************************************************************
** \brief   Acquires the width in pixels of a given character for
**          the passed FBF font file. Character width may be negative.
**          The passed font is assumed to be checked for beeing in FBF
**          format previously.
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
**              - #FONTSERVER_ERR_FBF_BAD_FBF_FILE
**                  if the FBF file is damaged.
**
** \return  Width of the character in pixels on success.
**          0 if the character is not in the set of the selected font
**          or the width of the character is 0.
**
*****************************************************************************
*/
static  int32_t engfbfGetCharWidth (FONTSERVER_HandleT* handlePtr,  \
                                    uint16_t chCode,                \
                                    int32_t* errorCodePtr)
{
    uint32_t*               char_block_ptr = NULL;
    ENGFBF_BitmapDataHeadT  char_bmp_head;
    uint32_t* font_data_ptr = handlePtr->faceIdPtr->filePtr;

    char_block_ptr = engfbfGetCharBitmapStartAddr(font_data_ptr, chCode);
    if (char_block_ptr == NULL)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FBF_BAD_FBF_FILE;
        return 0;
    }
    char_bmp_head.data = *char_block_ptr;
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return (char_bmp_head.charBmpInfo.width);
}

/*!
*****************************************************************************
** \brief   Low level function that prints a single character.
**
**          This functions manipulates the OSD memory in a way that
**          the glyph appears on the screen at given coordinates relative to
**          the OSD/CP layer.
**
** \note    - Lint error 923 temporarily disabled (2 calls) within function.
**            Casts from type to type are necessary here for pointer
**            arithmetics.
**          - The xx and yy coordinates indicate the upper left corner
**            of the character (FBF engine specific).
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
**              The y-coordinate on the given plane. For the FBF engine this
**              parameter indicates the top border of the character.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_FBF_BAD_FBF_FILE
**                  if the FBF file is damaged.
**              - #FONTSERVER_ERR_FBF_MEMORY_FAULT
**                  if an error ocurred while accessing the OSD memory.
**              - #FONTSERVER_ERR_OUT_OF_OSD_SIZE
**                  if the requested glyph does not fit into the OSD
**                  plane at given coordinates due to its dimensions.
**
** \return  Count of horizontal pixels of the written character
**          (always positive for FBF fonts).
**
*****************************************************************************
*/
static int32_t  engfbfWriteChar (FONTSERVER_HandleT* handlePtr,             \
                                 uint16_t chCode,                           \
                                 OSDHANDLER_LayerParamsT* layerParamsPtr,   \
                                 uint32_t xx,                               \
                                 uint32_t yy,                               \
                                 int32_t* errorCodePtr)
{
    ENGFBF_BitmapDataHeadT  char_bmp_head;
    uint32_t                x_pos               = 0;
    uint32_t                x_line              = xx;
    uint32_t                y_line              = yy;
    uint32_t                x_size              = 0;
    uint32_t                y_size              = 0;
    uint32_t                pixel_base_addr     = 0;
    uint32_t                pixel_bit_offset    = 0;
    uint32_t                colour_mask         = 0;
    uint32_t                data_mask           = 0;
    uint32_t                single_bit_mask     = 0;
    uint32_t                bpp                 = layerParamsPtr->bpp;
    uint32_t                data                = 0;
    uint32_t*               char_block_ptr      = NULL;
    volatile uint32_t*      addr                = NULL;
    uint32_t*               font_data_ptr       = handlePtr->faceIdPtr->filePtr;

#if ENGFBF_USE_ASM && defined(__arm__) && !defined(__GNUC__)

    OSDHANDLER_RectT destRect;
    uint32_t* layerStart  = (uint32_t*)layerParamsPtr->pictureBase;
    uint32_t  layerStride = (layerParamsPtr->xRes * bpp) >> 3;
#endif /* ENGFBF_USE_ASM */

    if(errorCodePtr) *errorCodePtr = FAPI_OK;

    /*lint -save -e923 */
    char_block_ptr = (uint32_t*)engfbfGetCharBitmapStartAddr \
                                        (font_data_ptr, chCode);
    /*lint -restore */
    if ((char_block_ptr == NULL) || (bpp == 0))
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_FBF_BAD_FBF_FILE;
        }
        return (0);
    }
    // get bitmap data head information of the character:
    char_bmp_head.data = *char_block_ptr++;

    x_size = char_bmp_head.charBmpInfo.width;
    y_size = char_bmp_head.charBmpInfo.height;
    y_line += char_bmp_head.charBmpInfo.dropY;

    // check whether the glyph fits into the OSD plane:
    if((x_size > (layerParamsPtr->xRes - xx))
    || ((char_bmp_head.charBmpInfo.height + char_bmp_head.charBmpInfo.dropY) >
        (layerParamsPtr->yRes - yy)))
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_OUT_OF_OSD_SIZE;
        }
        return(0);
    }

    data = *char_block_ptr++;

    if(bpp >> 5) // bpp >= 32 ?
    {
        colour_mask = 0xFFFFFFFFUL;
    }
    else
    {
        colour_mask = (0x00000001UL << bpp) - 0x00000001UL;
    }

    fontserverGetPixelAddress(x_line,             \
                              y_line,             \
                              &pixel_base_addr,   \
                              &pixel_bit_offset,  \
                              layerParamsPtr);
    /*lint -save -e923 */
    addr = (volatile uint32_t*)pixel_base_addr;
    /*lint -restore */
    if(addr == NULL)
    {
        if(errorCodePtr)
        {
            *errorCodePtr = FONTSERVER_ERR_FBF_MEMORY_FAULT;
        }
        return 0;
    }
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
            // if (pixel_bit_offset > 31)
            if (pixel_bit_offset >> 5)
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
                fontserverGetPixelAddress(x_line,            \
                                          y_line,            \
                                          &pixel_base_addr,  \
                                          &pixel_bit_offset, \
                                          layerParamsPtr);
                /*lint -save -e923 */
                addr = (volatile uint32_t*)pixel_base_addr;
                /*lint -restore */
            } //end if
        } //end while(single_bit_mask)

        /*lint -save -e613 */
        data = *char_block_ptr++;
        /*lint -restore */
        single_bit_mask = 0x80000000;
    } //end while(y_size)

    return ((int32_t)x_size);
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
**
** \return  - The internal character index of the requested character on success.
**
*****************************************************************************
*/
static uint32_t engfbfUnicode2Index (FONTSERVER_HandleT* handlePtr, \
                                     uint32_t chCode,               \
                                     int32_t* errorCodePtr)
{
    uint32_t* font_data_ptr = handlePtr->faceIdPtr->filePtr;
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return(chCode + (((ENGFBF_BitmapDataBlockInfoT*)(void*)font_data_ptr)->firstChar));
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
**
** \return  - The unicode coding for the requested character.
**
*****************************************************************************
*/
static uint32_t engfbfIndex2Unicode (FONTSERVER_HandleT* handlePtr, \
                                     uint32_t chIndex,              \
                                     int32_t* errorCodePtr)
{
    uint32_t* font_data_ptr = handlePtr->faceIdPtr->filePtr;
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return(chIndex - (((ENGFBF_BitmapDataBlockInfoT*)(void*)font_data_ptr)->firstChar));
}

/*!
*****************************************************************************
** \brief   Kerning is not supported for FBF.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   ch1
**              The left character.
** \param   ch2
**              The right character.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FONTSERVER_ERR_FBF_KERNING_NOT_SUPPORTED
**
** \return  0
**
*****************************************************************************
*/
static int32_t  engfbfGetKerning (FONTSERVER_HandleT* handlePtr, \
                                  uint32_t ch1,                  \
                                  uint32_t ch2,                  \
                                  int32_t* errorCodePtr)
{
    handlePtr = handlePtr;
    ch1 = ch1;
    ch2 = ch2;
    if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_FBF_KERNING_NOT_SUPPORTED;
    return(0); // not supported for FBF
}

/*!
*****************************************************************************
** \brief   Determine information about a single glyph.
**
** \param   handlePtr
**              Handle structure that covers all relevant information.
**              Has already been checked for validity by FONTSERVER.
** \param   chCode
**              The unicode character code of the desired character.
** \param   glyphInfoPtr
**              This structure will retrieve the desired glyph information.
**
** \return  - #FAPI_OK on success.
**
*****************************************************************************
*/
static int32_t  engfbfGetGlyphInfo (FONTSERVER_HandleT* handlePtr,        \
                                    uint16_t chCode,                      \
                                    FONTSERVER_GlyphInfoT* glyphInfoPtr)
{
    uint32_t*               char_block_ptr = NULL;
    ENGFBF_BitmapDataHeadT  char_bmp_head;
    uint32_t* font_data_ptr = handlePtr->faceIdPtr->filePtr;

    char_block_ptr = (uint32_t*)engfbfGetCharBitmapStartAddr \
                                            (font_data_ptr, chCode);
    if (char_block_ptr == NULL)
    {
        return FONTSERVER_ERR_FBF_BAD_FBF_FILE;
    }
    char_bmp_head.data = *char_block_ptr++;
    glyphInfoPtr->width      = char_bmp_head.charBmpInfo.width;
    glyphInfoPtr->height     = char_bmp_head.charBmpInfo.height + char_bmp_head.charBmpInfo.dropY;
    glyphInfoPtr->left       = 0;
    glyphInfoPtr->top        = char_bmp_head.charBmpInfo.dropY;
    glyphInfoPtr->xAdvance   = char_bmp_head.charBmpInfo.width;
    glyphInfoPtr->yAdvance   = 0;
    glyphInfoPtr->pitch      = char_bmp_head.charBmpInfo.height;
    *glyphInfoPtr->bufPtrPtr = (uint8_t*)char_block_ptr;
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Calculates the address of the bitmap data of a given character
**          within the passed FBF font file.
**
** \note    Lint error 923 (2 calls) and error 826 (8 calls) temporarily
**          disabled within function.
**          Casts from type to type are mandatory here for pointer arithmetics.
**          Pointer casts are necessary to get access to the structures
**          covered within the font file.
**
** \param   fontDataPtr
**              Points to the start of a FBF font file.
** \param   character
**              Code of the character whose address is to be determined.
**
** \return  Pointer to the bitmap data in the currently selected font on success.
**          NULL pointer if the character is not specified within the
**          currently selected font.
**
*****************************************************************************
*/
static uint32_t* engfbfGetCharBitmapStartAddr(uint32_t* fontDataPtr, \
                                              const uint32_t character)
{
    uint32_t* start_ptr         = NULL;
    uint8_t*  buf_ptr           = NULL;
    uint32_t  temp              = 0;
    uint32_t  block_count       = 0;
    uint32_t  idx_offset        = 0;

    /*lint -save -e826 */
    block_count = ((ENGFBF_FbfFileHeadT*)(uint8_t*)fontDataPtr)->numOfBlocks;
    buf_ptr = ((uint8_t*)(fontDataPtr)) + sizeof(ENGFBF_FbfFileHeadT);
    /* buf_ptr is set to the beginning of the first data block
    ** in the font (at a 32-bit aligned address)
    */
    do
    {
        /* check if the requested character is inside the block
        ** that is referenced by buf_ptr
        */
        if ((character >= (((ENGFBF_BitmapDataBlockInfoT*)buf_ptr)->firstChar)) &&
            (character <= (((ENGFBF_BitmapDataBlockInfoT*)buf_ptr)->lastChar)))
        {
            /* base address of the block => start of bitmap data =>
            ** start of bitmap offsets => specific offset of the character
            ** that indicates the (4-byte) offset of the wanted character
            ** within the bitmapdata section of this block
            */
            idx_offset = \
                *((uint32_t*)
                   (  buf_ptr + sizeof(ENGFBF_BitmapDataBlockInfoT)         \
                    + ((ENGFBF_BitmapDataBlockInfoT*)buf_ptr)->bmpBytes     \
                    + ((character -                                         \
                       (((ENGFBF_BitmapDataBlockInfoT*)buf_ptr)->firstChar))\
                      << 2)                                                 \
                   )                                                        \
                 );
            /* set start_ptr to the location that contains the
            ** bitmap data of the wanted character
            */
            /*lint -save -e923 */
            temp = (uint32_t) \
                   (buf_ptr + sizeof(ENGFBF_BitmapDataBlockInfoT) + (idx_offset<<2));
            if (temp % 4)
            {
                // this may occur if an outdated font file is used
                start_ptr = NULL;
            }
            else
            {
                start_ptr = (uint32_t*)temp;
            }
            break;
            /*lint -restore */
        }
        buf_ptr += sizeof(ENGFBF_BitmapDataBlockInfoT) + \
                   ((ENGFBF_BitmapDataBlockInfoT*)buf_ptr)->blockBytes;
        block_count--;
    }while (block_count);
    /* returns a NULL pointer if the character could not be found in
    ** the character set of the selected font:
    */
    return start_ptr;
}

//***************************************************************************
//***************************************************************************
//** API Functions
//***************************************************************************
//***************************************************************************
