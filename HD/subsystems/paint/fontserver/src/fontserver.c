/*
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/src/fontserver.c
**
** \brief       Fontserver for different font formats.
**
** This file contains the implementation of the fontserver core API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#include <stdint.h>
#if 0
#include "fapex/abst_types.h"
#else
#include <fapi/sys_services.h>
#endif
#include "osdhandler/osdhandler.h"
#include "fontserver.h"
#include "fontserver_engine.h"

//***************************************************************************
//***************************************************************************
//** Local Defines
//***************************************************************************
//***************************************************************************

#define FONTSERVER_HANDLE_ID (uint32_t)0x666F6E74 // 'font'

#define FONTSERVER_LOCK   FAPI_SYS_GET_SEMAPHORE( fontserverSemaphore, FAPI_SYS_SUSPEND )
#define FONTSERVER_UNLOCK FAPI_SYS_SET_SEMAPHORE( fontserverSemaphore, FAPI_SYS_NO_SUSPEND )

//***************************************************************************
//***************************************************************************
//** Local Structures
//***************************************************************************
//***************************************************************************

/*!
*************************************************************************
** \brief Structure that keeps track of all information about fonts
**        that may be of interest.
**
*************************************************************************
*/
typedef struct
{
    uint32_t*               fontDataPtr;  //!< start address of font data
    uint32_t                fontFileSize; //!< points font file size in bytes
    FONTSERVER_EngineT*     enginePtr;    //!< corresponding font engine
} fontserverInventoryT;

//***************************************************************************
//***************************************************************************
//** Local Data
//***************************************************************************
//***************************************************************************
static uint32_t             fontserverInitialized  = 0; //21f71c9c
static uint32_t             fontserverNumOfFonts   = 0; //21f71ca4
static uint32_t             fontserverNumOfEngines = 0; //21f71ca8
static FONTSERVER_EngineT   fontserverEnginePtr[FONTSERVER_MAX_ENGINE_COUNT]; //21f71cac
static fontserverInventoryT fontserverInventoryPtr[FONTSERVER_MAX_FONT_COUNT]; //21f71d04
static FONTSERVER_HandleT   fontserverHandleArray[FONTSERVER_TOTAL_HANDLE_COUNT]; //21f71d7c
static FAPI_SYS_SemaphoreT  fontserverSemaphore = (FAPI_SYS_SemaphoreT)0; //21f71ca0
static FONTSERVER_FaceIdT   fontserverFaceIdPtrPtr[FONTSERVER_MAX_FONT_COUNT][FONTSERVER_MAX_STYLE_COUNT]; //21f76ffc

//***************************************************************************
//***************************************************************************
//** Local Functions Declaration
//***************************************************************************
//***************************************************************************
static uint16_t fontserverRead2Bytes(const uint8_t* dataPtr);
static uint32_t fontserverRead4Bytes(const uint8_t* dataPtr);
static FONTSERVER_HandleT* fontserverAllocateHandle(void);
static uint32_t fontserverCheckHandle(const FONTSERVER_HandleT* handlePtr);
static void fontserverReleaseHandle(FONTSERVER_HandleT* handlePtr);
static int32_t fontserverSetUpAntiAliasing(FONTSERVER_HandleT* handlePtr);
static uint32_t fontserverSquare(int32_t arg);
static void fontserverResetCharCodeSettings(FONTSERVER_HandleT* handlePtr);
static void fontserverUpdateFaceId(FONTSERVER_HandleT* handlePtr);

//***************************************************************************
//***************************************************************************
//** Global Data
//***************************************************************************
//***************************************************************************

//***************************************************************************
//***************************************************************************
//** Local Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief   Reads 2 bytes from a byte pointer.
**
** \param   dataPtr
**              The pointer to read from.
**
** \return  Retrieved value:
**          - unsigned 16 bit integer value retrieved by the pointer.
**          - 0 if a NULL pointer is passed.
*****************************************************************************
*/
static uint16_t fontserverRead2Bytes(const uint8_t* dataPtr)
{
    uint16_t result = 0;

    if(dataPtr == NULL)
    {
        return(0);
    }
    result  = (uint16_t) *dataPtr;
    result += (uint16_t) ((*(dataPtr+1)) << 8);
    return (result);
}

/*!
*****************************************************************************
** \brief   Reads 4 bytes from a byte pointer.
**
** \param   dataPtr
**              The pointer to read from.
**
** \return  Retrieved value:
**          - unsigned 32 bit integer value retrieved by the pointer.
**          - 0 if a NULL pointer is passed.
*****************************************************************************
*/
static uint32_t fontserverRead4Bytes(const uint8_t* dataPtr)
{
    uint32_t result = 0;

    if(dataPtr == NULL)
    {
        return(0);
    }
    result  = ((*(dataPtr + 0) <<  0)|
               (*(dataPtr + 1) <<  8)|
               (*(dataPtr + 2) << 16)|
               (*(dataPtr + 3) << 24));
    return (result);
}

/*!
********************************************************************************
** \brief Allocate a new handle.
**
** This function allocates a new FONTSERVER handle.
**
** \return
** - (>0) If handle can be allocated
** - (0)  In case of error (no more handles available)
********************************************************************************
*/
static FONTSERVER_HandleT* fontserverAllocateHandle( void )
{
    FONTSERVER_HandleT* handle_ptr = NULL;
    uint32_t index = 0;

    for(index = 0; index < FONTSERVER_TOTAL_HANDLE_COUNT; index++)
    {
        /* search for handle not in use */
        if( !fontserverHandleArray[index].inUse )
        {
            memset(&(fontserverHandleArray[index]), 0, sizeof(FONTSERVER_HandleT));
            /* set in use */
            fontserverHandleArray[index].inUse = 1;
            fontserverHandleArray[index].id = FONTSERVER_HANDLE_ID;
            /* set handle pointer */
            handle_ptr = &(fontserverHandleArray[index]);
            break;
        }
    }
    return(handle_ptr);
}

/*!
********************************************************************************
** \brief Checks a given handle.
**
** This function checks a given FONTSERVER handle.
**
** \return
** - (1) If handle is OK
** - (0) If handle is invalid
********************************************************************************
*/
/* 21c95808 - complete */
static uint32_t fontserverCheckHandle(const FONTSERVER_HandleT* handlePtr)
{
    return(fontserverInitialized && handlePtr && handlePtr->inUse
            && (handlePtr->id == FONTSERVER_HANDLE_ID));
}

/*!
********************************************************************************
** \brief Releases a given handle.
**
** This function de-allocates a given FONTSERVER handle.
********************************************************************************
*/
static void fontserverReleaseHandle(FONTSERVER_HandleT* handlePtr)
{
    /* clear handle context */
    memset( handlePtr, 0, sizeof(FONTSERVER_HandleT) );
    return;
}

/*!
*****************************************************************************
** \brief Set up the colour lookup table used for anti-aliasing.
**
** \param   handlePtr
**              A fontserver handle. Must be checked previously.
**
** \return
**          - FAPI_OK on success or if anti aliasing is disabled.
**          - ...
**
*****************************************************************************
*/
static int32_t fontserverSetUpAntiAliasing(FONTSERVER_HandleT* handlePtr)
{
    int32_t  result           = 0;
    uint32_t bb               = 0;
    int32_t  ii               = 0;
    uint32_t kk               = 0;
    int32_t  clut_col_count   = 0; // OSD/CP clut colour count
    int32_t  aa_col_count     = 0; // count of anti-alias colours
    int32_t  comp1Bg          = 0; // background components
    int32_t  comp2Bg          = 0;
    int32_t  comp3Bg          = 0;
    int32_t  comp4Bg          = 0;
    int32_t  comp1Fg          = 0; // foreground components
    int32_t  comp2Fg          = 0;
    int32_t  comp3Fg          = 0;
    int32_t  comp4Fg          = 0;
    int32_t  comp1Delta       = 0; // differences
    int32_t  comp2Delta       = 0;
    int32_t  comp3Delta       = 0;
    int32_t  comp4Delta       = 0;
    uint32_t curr_colour_diff = 0;
    uint32_t best_colour_diff = 0;
    uint32_t best_colour_idx  = 0;
    uint32_t osd_clut_array[256];
    OSDHANDLER_LayerParamsT layer_params;

    memset(&layer_params, 0, sizeof(OSDHANDLER_LayerParamsT));

    if (handlePtr->antiAlias == FONTSERVER_ANTI_ALIAS_OFF)
    {
        return(FAPI_OK);
    }
    result = OSDHANDLER_GetLayerParameters(handlePtr->layerId, &layer_params);
    if (result != FAPI_OK)
    {
        return(result);
    }
    if((layer_params.bpp < 32) && (handlePtr->curColour >> layer_params.bpp))
    {
        return(FONTSERVER_ERR_BAD_COLOUR);
    }
    clut_col_count = (int32_t)(1UL << layer_params.bpp);

    switch(layer_params.colourMode)
    {
        case(OSDHANDLER_OSD_MODE_CLUT_4BIT):
        case(OSDHANDLER_OSD_MODE_CLUT_8BIT):
        case(OSDHANDLER_CURSOR_MODE_4BIT):
        case(OSDHANDLER_CURSOR_MODE_8BIT):
            result = OSDHANDLER_GetClut(handlePtr->layerId, osd_clut_array);
            if(result != FAPI_OK)
            {
                return(result);
            }
            comp1Fg = ((osd_clut_array[handlePtr->curColour]  & 0xFF000000UL) >> 24);
            comp2Fg = ((osd_clut_array[handlePtr->curColour]  & 0x00FF0000UL) >> 16);
            comp3Fg = ((osd_clut_array[handlePtr->curColour]  & 0x0000FF00UL) >>  8);
            comp4Fg =  (osd_clut_array[handlePtr->curColour]  & 0x000000FFUL);
            for(bb = 0; bb < (uint32_t)clut_col_count; bb++) // for each osd clut entry
            {
                comp1Bg = ((osd_clut_array[bb] & 0xFF000000UL) >> 24);
                comp2Bg = ((osd_clut_array[bb] & 0x00FF0000UL) >> 16);
                comp3Bg = ((osd_clut_array[bb] & 0x0000FF00UL) >>  8);
                comp4Bg =  (osd_clut_array[bb] & 0x000000FFUL);
                comp1Delta = (int32_t) ((int32_t)comp1Fg - (int32_t)comp1Bg);
                comp2Delta = (int32_t) ((int32_t)comp2Fg - (int32_t)comp2Bg);
                comp3Delta = (int32_t) ((int32_t)comp3Fg - (int32_t)comp3Bg);
                comp4Delta = (int32_t) ((int32_t)comp4Fg - (int32_t)comp4Bg);
                aa_col_count = 1 << FONTSERVER_ANTI_ALIAS_BIT_COUNT; // placed here for MISRA Warning 414: Possible division by 0
                for(ii = 0; ii < aa_col_count; ii++) // for each aa colour
                {
                    // desired_colour =
                    //     (((uint32_t)(comp1Bg + ((ii * comp1Delta) / (ii -1)))) << 24) |
                    //     (((uint32_t)(comp2Bg + ((ii * comp2Delta) / (ii -1)))) << 16) |
                    //     (((uint32_t)(comp3Bg + ((ii * comp3Delta) / (ii -1)))) <<  8) |
                    //     (((uint32_t)(comp4Bg + ((ii * comp4Delta) / (ii -1)))) <<  0);
                    best_colour_diff = UINT32_MAX;
                    best_colour_idx = 0;
                    for(kk = 0; kk < (uint32_t)clut_col_count; kk++) // for each osd clut entry
                    {
                        curr_colour_diff = \
                            fontserverSquare(((comp1Bg + \
                                ((ii * comp1Delta) / (aa_col_count - 1)))) - \
                                ((int32_t)((osd_clut_array[kk] & 0xFF000000UL) >> 24))) + \
                            fontserverSquare(((comp2Bg + \
                                ((ii * comp2Delta) / (aa_col_count - 1)))) - \
                                ((int32_t)((osd_clut_array[kk] & 0x00FF0000UL) >> 16))) + \
                            fontserverSquare(((comp3Bg + \
                                ((ii * comp3Delta) / (aa_col_count - 1)))) - \
                                ((int32_t)((osd_clut_array[kk] & 0x0000FF00UL) >>  8))) + \
                            fontserverSquare(((comp4Bg + \
                                ((ii * comp4Delta) / (aa_col_count - 1)))) - \
                                ((int32_t)(osd_clut_array[kk] & 0x000000FFUL)));
                        if(curr_colour_diff < best_colour_diff)
                        {
                            best_colour_diff = curr_colour_diff;
                            best_colour_idx = kk;
                        }
                    }
                    handlePtr->antiAliasClutPtrPtr[bb][ii] = (uint8_t)best_colour_idx;
                }
            }
            break;

        case(OSDHANDLER_OSD_MODE_32_24BIT):
            break;

        case(OSDHANDLER_OSD_MODE_16BIT):
        case(OSDHANDLER_OSD_MODE_4444):
        case(OSDHANDLER_OSD_MODE_5551):
        case(OSDHANDLER_CURSOR_MODE_UNKNOWN):
        case(OSDHANDLER_CURSOR_MODE_1BIT):
        case(OSDHANDLER_CURSOR_MODE_2BIT):
        case(OSDHANDLER_OSD_MODE_UNKNOWN):
        default:
            break;
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Calculates the square of a number.
**
** \param   arg
**              Value that will be squared.
** \return
**          Square of the argument.
**
*****************************************************************************
*/
static uint32_t fontserverSquare(int32_t arg)
{
    return((uint32_t) (arg * arg));
}

/*!
*****************************************************************************
** \brief Gets the memory adress for a pixel at given coordinates for the
          passed layerParamsPtr.
**
** \param   xx
**              x coordinate of the pixel whose memory address will be
**              determined.
** \param   yy
**              y coordinate of the pixel whose memory address will be
**              determined.
** \param   pixelBaseAddrPtr
**              Will point to the 4byte-aligned address in front
**              of the pixel.
** \param   pixelBitOffsetPtr
**              Will point to the address bit offset since
**              the obtained memory address of the pixel may not be aligend to
**              4 bytes. This value will always be less than 32.
** \param   layerParamsPtr
**              Points the information structure of the desired OSD.
**              It covers the base address as well as resolution and bpp of
**              the OSD.
*****************************************************************************
*/
void fontserverGetPixelAddress(uint32_t xx,                 \
                               uint32_t yy,                 \
                               uint32_t* pixelBaseAddrPtr,  \
                               uint32_t* pixelBitOffsetPtr, \
                               const OSDHANDLER_LayerParamsT* layerParamsPtr)
{
    if((pixelBaseAddrPtr == NULL) ||
       (pixelBitOffsetPtr == NULL))
    {
        return;
    }
    *pixelBaseAddrPtr = layerParamsPtr->pictureBase
                        + ((yy * layerParamsPtr->xRes * \
                            layerParamsPtr->bpp) >> 3)
                        + ((xx * layerParamsPtr->bpp) >> 3); // byte pointer
    *pixelBaseAddrPtr -= *pixelBaseAddrPtr % 4; //4-byte aligned address
    *pixelBitOffsetPtr = (xx * layerParamsPtr->bpp) % 32;
    return;
}

/*!
*****************************************************************************
** \brief   Undo settings that have been set up temporarily due to character
**          codes that may change font properties.
**
** \param   handlePtr
**              Must be a checked fontserver handle.
**
*****************************************************************************
*/
static void fontserverResetCharCodeSettings(FONTSERVER_HandleT* handlePtr)
{
    if(handlePtr == NULL)
    {
        return;
    }
    handlePtr->curSize = handlePtr->defSize;
    handlePtr->curFontIndex = handlePtr->defFontIndex;
    if(handlePtr->curColour != handlePtr->defColour)
    {
        handlePtr->curColour = handlePtr->defColour;
        (void)fontserverSetUpAntiAliasing(handlePtr);
    }
    fontserverUpdateFaceId(handlePtr);
    return;
}

/*!
*****************************************************************************
** \brief Update the face id of the handle.
**
** \param   handlePtr
**              Must be a checked fontserver handle.
**
*****************************************************************************
*/
/* 21c958bc - complete */
static void fontserverUpdateFaceId(FONTSERVER_HandleT* handlePtr)
{
    handlePtr->faceIdPtr = &(fontserverFaceIdPtrPtr[handlePtr->curFontIndex][handlePtr->style]);
}

//***************************************************************************
//***************************************************************************
//** API Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief   Initialize the FONTSERVER subsystem.
**
** This function initializes the fontserver system with a given set of
** rendering engines and fonts.
**
** \note    Lint error 923 temporarily disabled within function.
**          Casts from type to type are mandatory here for pointer arithmetics.
**
** \param   initParamsPtr
**              Points to the font initialization parameters such as
**              font engines and font files.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_ALREADY_INITIALIZED
**              if the fontserver has already been initialized.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER (that is needed in order to gain access
**              to the OSDs) has not been initialized previously.
**          - #FONTSERVER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed. Possible reasons:
**              - The passed fontInitParamsPtr is NULL.
**              - It is attempted to initialize the font driver with 0 fonts.
**              - There are more fonts passed than FONTSERVER_MAX_FONT_COUNT.
**              - The referenced init params structure is bad.
**              - The font data pointer or the file size pointer from the
**                initialization structure is NULL.
**              - One of the addresses indicated by the font data pointer
**                is not divisible by 4 without remainder (must be 32-bit
**                capable).
**          - #FONTSERVER_ERR_SEMAPHORE_CREATE if the fontserver semaphore
**              could not be created.
**
** \sa
**          - FONTSERVER_Exit()
**
*****************************************************************************
*/
/* 21c9757c - complete */
int32_t FONTSERVER_Init(const FONTSERVER_InitParamsT* initParamsPtr)
{
    uint32_t*   address_ptr  = NULL;
    uint32_t    ii           = 0;
    int32_t     error_code   = 0;

    if (fontserverInitialized)
    {
        return(FONTSERVER_ERR_ALREADY_INITIALIZED);
    }

    if (!OSDHANDLER_IsInitialized())
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }

    if ((initParamsPtr == NULL)
        || (initParamsPtr->numEngines == 0)
        || (initParamsPtr->numEngines > FONTSERVER_MAX_ENGINE_COUNT)
        || (initParamsPtr->enginesPtr == NULL))
    {
        return (FONTSERVER_ERR_BAD_PARAMETER);
    }

    fontserverSemaphore = FAPI_SYS_CREATE_SEMAPHORE(1);
    if (!fontserverSemaphore)
    {
        return (FONTSERVER_ERR_SEMAPHORE_CREATE);
    }

    // initialize global variables
    memset(fontserverEnginePtr, 0, \
           (sizeof(FONTSERVER_EngineT) * FONTSERVER_MAX_ENGINE_COUNT));
    memset(fontserverInventoryPtr, 0, \
           (sizeof(fontserverInventoryT) * FONTSERVER_MAX_FONT_COUNT));
    memset(fontserverHandleArray, 0, \
            (sizeof(FONTSERVER_HandleT) * FONTSERVER_TOTAL_HANDLE_COUNT));

    fontserverNumOfEngines = initParamsPtr->numEngines;
    fontserverNumOfFonts   = 0;

    // Initialize font engine subsystems:
    address_ptr = initParamsPtr->enginesPtr;
    for (ii = 0; ii < fontserverNumOfEngines; ii++)
    {
        if((*address_ptr) == 0)
        //((FONTSERVER_EngineT*)(*address_ptr) == NULL))
        {
            FONTSERVER_Exit();
            return(FONTSERVER_ERR_BAD_PARAMETER);
        }
        /*lint -save -e923 */
        memcpy(&fontserverEnginePtr[ii], (void*)*address_ptr++, \
               sizeof(FONTSERVER_EngineT));
        /*lint -restore */
        error_code = fontserverEnginePtr[ii].initEngine();
        if(error_code != FAPI_OK)
        {
            FONTSERVER_Exit();
            return(error_code);
        }
    }
    fontserverInitialized = 1;
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Exits the FONTSERVER and shuts down all font engine subsystems.
**
** This function shutdowns the fontserver and clears the font parameters that
** have been provided to FONTSERVER_Init().
**
** \sa
**          - FONTSERVER_Init()
**
*****************************************************************************
*/
/* 21c96364 - complete */
void FONTSERVER_Exit(void)
{
    uint32_t ii = 0;

    for( ii = 0; ii < fontserverNumOfEngines; ii++)
    {
        fontserverEnginePtr[ii].exitEngine();
    }

    for(ii = 0; ii < FONTSERVER_TOTAL_HANDLE_COUNT; ii++)
    {
        if(fontserverHandleArray[ii].inUse)
        {
            (void)FONTSERVER_Close((FAPI_SYS_HandleT)&fontserverHandleArray[ii]);
        }
    }

    // wipe out previous state:

    memset(fontserverEnginePtr, 0, \
           (sizeof(FONTSERVER_EngineT) * FONTSERVER_MAX_ENGINE_COUNT));
    memset(fontserverInventoryPtr, 0, \
           (sizeof(fontserverInventoryT) * FONTSERVER_MAX_FONT_COUNT));
    memset(fontserverHandleArray, 0, \
            (sizeof(FONTSERVER_HandleT) * FONTSERVER_TOTAL_HANDLE_COUNT));

    FAPI_SYS_DESTROY_SEMAPHORE(fontserverSemaphore);
    fontserverSemaphore = 0;

    fontserverNumOfEngines = 0;
    fontserverNumOfFonts   = 0;
    fontserverInitialized  = 0;
    return;
}

/*!
*****************************************************************************
** \brief   Register a new font with the fontserver.
**
** \param   fontDataPtr
**              Points to the beginning of the font file to install.
** \param   fontFileSize
**              Size of the font file in bytes.
** \param   errorCodePtr
**              Optional pointer. Will receive error codes. Possible values:
**                  - #FAPI_OK on success
**                  - #FONTSERVER_ERR_NOT_INITIALIZED if the fontserver
**                      has not yet been initialized.
**                  - #FONTSERVER_ERR_BAD_PARAMETER if the fontDataPtr is
**                      NULL or if the fontFileSize is 0.
**                  - #FONTSERVER_ERR_MAX_FONT_COUNT if the maximum possible
**                      count of fonts has already been registered.
**
** \return
**          A unique number that can be used to identify that font.
**
** \sa
**          - #FONTSERVER_UnregisterFont()
**
*****************************************************************************
*/
/* 21c95fec - complete */
uint32_t FONTSERVER_RegisterFont(uint32_t* fontDataPtr,
                                uint32_t fontFileSize,
                                int32_t* errorCodePtr)
{
    uint32_t ii         = 0;
    uint32_t kk         = 0;
    int32_t  error_code = 0;

    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    if(fontserverInitialized == 0)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_NOT_INITIALIZED;
        return(0);
    }
    if((fontDataPtr == NULL) || (fontFileSize == 0))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return(0);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    for(ii = 0; ii < FONTSERVER_MAX_FONT_COUNT; ii++)
    {
        if(fontserverInventoryPtr[ii].fontDataPtr == NULL) break;
    }
    if(ii >= FONTSERVER_MAX_FONT_COUNT)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_MAX_FONT_COUNT;
        FONTSERVER_UNLOCK;
        return(0);
    }

    fontserverInventoryPtr[ii].fontDataPtr  = fontDataPtr;
    fontserverInventoryPtr[ii].fontFileSize = fontFileSize;

    for(kk = 0; kk < FONTSERVER_MAX_STYLE_COUNT; kk++)
    {
        fontserverFaceIdPtrPtr[ii][kk].filePtr  = fontDataPtr;
        fontserverFaceIdPtrPtr[ii][kk].fileSize = fontFileSize;
        fontserverFaceIdPtrPtr[ii][kk].fontStyle = (FONTSERVER_StyleT)kk;
    }

    for(kk = 0; kk < fontserverNumOfEngines; kk++)
    {
        error_code = fontserverEnginePtr[kk].checkFont \
                    (fontserverInventoryPtr[ii].fontDataPtr, \
                     fontserverInventoryPtr[ii].fontFileSize);
        if(error_code == FAPI_OK)
        {
            break;
        }
    }
    if(error_code != FAPI_OK)
    {
        memset(&fontserverInventoryPtr[ii], 0, sizeof(fontserverInventoryT));
        for(kk = 0; kk < FONTSERVER_MAX_STYLE_COUNT; kk++)
        {
            memset(&fontserverFaceIdPtrPtr[ii][kk], 0, sizeof(FONTSERVER_FaceIdT));
        }
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_FORMAT;
        FONTSERVER_UNLOCK;
        return(0);
    }
    fontserverInventoryPtr[ii].enginePtr = &fontserverEnginePtr[kk];
    fontserverNumOfFonts++;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(ii);
}

/*!
*****************************************************************************
** \brief   Unregister an installed font.
**
** \param   fontIndex
**              The index of the font that will be unregistered.
**
** \return
**          - #FAPI_OK on success
**          - #FONTSERVER_ERR_BAD_PARAMETER if the given fontIndex is invalid.
**
** \sa
**          - #FONTSERVER_RegisterFont()
**
*****************************************************************************
*/
int32_t FONTSERVER_UnregisterFont(uint32_t fontIndex)
{
    uint32_t kk = 0;

    if(fontIndex >= FONTSERVER_MAX_FONT_COUNT)
    {
        return(FONTSERVER_ERR_BAD_PARAMETER);
    }
    if(fontserverInventoryPtr[fontIndex].fontDataPtr == NULL)
    {
        return(FONTSERVER_ERR_BAD_PARAMETER);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    memset(&fontserverInventoryPtr[fontIndex], 0, sizeof(fontserverInventoryT));
    for(kk = 0; kk < FONTSERVER_MAX_STYLE_COUNT; kk++)
    {
        memset(&fontserverFaceIdPtrPtr[fontIndex][kk], 0, sizeof(FONTSERVER_FaceIdT));
    }
    fontserverNumOfFonts--;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Open the FONTSERVER driver.
**
** This function opens an instance of the fontserver driver.
** \param   openParamsPtr
**              Pointer to the open parameters.
** \param   errorCodePtr
**              Optional pointer that will receive error codes.
**              Possible values:
**              - #FONTSERVER_ERR_NOT_INITIALIZED
**              - #FONTSERVER_ERR_BAD_PARAMETER if the openParamsPtr is NULL.
**              - #FONTSERVER_ERR_UNSUPPORTED_VERSION if the driver versions
**                  do not match.
**
** \return
**          - (>0) valid driver instance handle on success.
**          - (0) if the driver could not be opened.
**
** \sa
**          - FONTSERVER_Close
*****************************************************************************
*/
/* 21c97394 - complete */
FAPI_SYS_HandleT FONTSERVER_Open(const FONTSERVER_OpenParamsT* openParamsPtr,
                                 int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr;

    if(errorCodePtr) *errorCodePtr = FAPI_OK;

    if(fontserverInitialized == 0)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_NOT_INITIALIZED;
        return(NULL);
    }
    if(openParamsPtr == NULL)
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return(NULL);
    }
    if(!FAPI_SYS_CHECK_VERSION(openParamsPtr->version, FONTSERVER_VERSION))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_UNSUPPORTED_VERSION;
        return(NULL);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    /* allocate handle */
    handle_ptr = fontserverAllocateHandle();

    if( ! fontserverCheckHandle(handle_ptr) )
    {
        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_MAX_HANDLE_COUNT;
        return(NULL);
    }

    memcpy(&(handle_ptr->openParams), openParamsPtr, sizeof(FONTSERVER_OpenParamsT));

    handle_ptr->defFontIndex = 0;
    handle_ptr->curFontIndex = 0;
    handle_ptr->defSize      = 0;
    handle_ptr->curSize      = 0;
    handle_ptr->defColour    = 0;
    handle_ptr->curColour    = 0;
    handle_ptr->layerId      = 1;
    memset(&handle_ptr->aspectRatio, 0, sizeof(FONTSERVER_AspectRatioT));
    handle_ptr->encoding     = FONTSERVER_ENCODING_8_BIT;
    handle_ptr->antiAlias    = FONTSERVER_ANTI_ALIAS_OFF;
    handle_ptr->style        = FONTSERVER_STYLE_NORMAL;
    fontserverUpdateFaceId(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return(handle_ptr);
}

/*!
*****************************************************************************
** \brief Close the FONTSERVER driver.
**
** This function closes an instance of the FONTSERVER driver. All resources
** associated with the given driver handle will be released.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
** \sa
**          - FONTSERVER_Open()
**
*****************************************************************************
*/
/* 21c962c0 - complete */
int32_t FONTSERVER_Close (FAPI_SYS_HandleT handle)
{
    FONTSERVER_HandleT* fontserver_handle_ptr = (FONTSERVER_HandleT*)handle;

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    /* check handle */
    if( ! fontserverCheckHandle( fontserver_handle_ptr ) )
    {
        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }
    // release handle:
    fontserverReleaseHandle( fontserver_handle_ptr );

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Select a font.
**
** This function selects a font for a handle.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   fontIndex
**              Index of the selected font. The first font has index 0.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**          - #FONTSERVER_ERR_BAD_PARAMETER if the fontIndex parameter is
**              out of range.
**
*****************************************************************************
*/
/* 21c958f0 - complete */
int32_t FONTSERVER_SetFont(FAPI_SYS_HandleT handle, uint32_t fontIndex)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }
    if(fontserverInventoryPtr[fontIndex].fontDataPtr == NULL)
    {
        return(FONTSERVER_ERR_BAD_PARAMETER);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->defFontIndex = fontIndex;
    handle_ptr->curFontIndex = fontIndex;
    fontserverUpdateFaceId(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Set up font size.
**
** This function sets up the font size for a handle.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   size
**              New font size. Pass 0 if you request a font that is not resizable
**              (such as bitmap fonts). The metric (points/pixels) depends
**              on the engine that will be used for calculation.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetSize(FAPI_SYS_HandleT handle, uint32_t size)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->defSize = size;
    handle_ptr->curSize = size;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Set up font colour.
**
** This function sets up the font colour for a handle.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   colour
**              New font colour.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetColour(FAPI_SYS_HandleT handle, uint32_t colour)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->defColour = colour;
    handle_ptr->curColour = colour;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Set up the layerId.
**
** This function selects the layerId for a handle.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   layerId
**              New layerId.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetLayerId(FAPI_SYS_HandleT handle, uint32_t layerId)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->layerId = layerId;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Set up the encoding.
**
** This function sets up the character encoding scheme for a handle.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   encoding
**              New encoding scheme.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetEncoding(FAPI_SYS_HandleT handle, FONTSERVER_EncodingT encoding)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->encoding = encoding;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Set up the aspect ratio of glyphs.
**
** This function sets up the aspect ratio for characters.
** The FONTSERVER_AspectRatioT consists of a nominator and a denominator
** which will be used to calculate the effective width of characters.
** glyphWidth = (nominator/denominator) * originalGlyphWidth
**
** \attention   This parameter may only affect scalable 'outline' fonts. It is
**              not applicable for bitmap fonts.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   aspectRatio
**              New aspect ratio (width by height).
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetAspectRatio(FAPI_SYS_HandleT handle, \
                                  FONTSERVER_AspectRatioT aspectRatio)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->aspectRatio = aspectRatio;

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Set up the font style.
**
** This function sets up the style of a font.
** If the engines supports this features it will try to load a face within
** the font that corresponds to the indicated style. The
** FONTSERVER_STYLE_NORMAL setting always refers to the default face in a font.
**
** \attention   This parameter may only affect outline fonts. It is
**              not applicable for bitmap fonts.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   style
**              New style setting.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetStyle(FAPI_SYS_HandleT handle, FONTSERVER_StyleT style)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->style = style;
    fontserverUpdateFaceId(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Set up anti-aliasing options.
**
**          This function enables/disables anti-aliasing and defines the
**          background colour which will be used for interpolation.
**          For 4-bit and 8-bit OSDs, 8 shades are used for anti-aliasing.
**          For 32-bit OSDs, 256 shades are used.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   antiAliasMode
**              Defines whether to use anti-aliasing or not.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**          - #FONTSERVER_ERR_BAD_COLOUR if the currently set colour
**              does not match the colour mode of the OSD.
**
*****************************************************************************
*/
int32_t FONTSERVER_SetAntiAliasing(FAPI_SYS_HandleT handle,             \
                                   FONTSERVER_AntiAliasT antiAliasMode)
{
    int32_t result = 0;
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    OSDHANDLER_LayerParamsT layer_params;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return (FONTSERVER_ERR_INVALID_HANDLE);
    }
    if(antiAliasMode == FONTSERVER_ANTI_ALIAS_OFF)
    {
        ////////////////
        FONTSERVER_LOCK;
        ////////////////

        handle_ptr->antiAlias = FONTSERVER_ANTI_ALIAS_OFF;

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        return(FAPI_OK);
    }

    result = OSDHANDLER_GetLayerParameters(handle_ptr->layerId, &layer_params);
    if (result != FAPI_OK)
    {
        return(result);
    }
    if((layer_params.bpp < 32) && (handle_ptr->curColour >> layer_params.bpp))
    {
        return(FONTSERVER_ERR_BAD_COLOUR);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    handle_ptr->antiAlias = antiAliasMode;
    result = fontserverSetUpAntiAliasing(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(result);
}

/*!
*****************************************************************************
** \brief   Returns the count of fonts that have been installed at
**          initialization.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**
** \return  Number of available fonts on success.
**
*****************************************************************************
*/
uint32_t FONTSERVER_GetNumOfFonts(FAPI_SYS_HandleT handle, int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    if(errorCodePtr) *errorCodePtr = FAPI_OK;
    return(fontserverNumOfFonts);
}

/*!
*****************************************************************************
** \brief   Retrieves information of an installed font.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   infoPtr
**              References a data structure which will receive
**              the font information associated with the given handle.
**
** \return
**          - #FAPI_OK on success.
**          - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**          - #FONTSERVER_ERR_BAD_PARAMETER if the infoPtr parameter is NULL.
**          - some engine specific error code.
**
*****************************************************************************
*/
int32_t FONTSERVER_GetFontInfo(FAPI_SYS_HandleT handle, \
                               FONTSERVER_InformationT* infoPtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    int32_t error_code = 0;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return(FONTSERVER_ERR_INVALID_HANDLE);
    }
    if (infoPtr == NULL)
    {
        return (FONTSERVER_ERR_BAD_PARAMETER);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    error_code = fontserverInventoryPtr[handle_ptr->defFontIndex].enginePtr->getFontInfo \
                                    (handle_ptr, infoPtr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    if(error_code != FAPI_OK)
    {
        return(error_code);
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Determines the maximum pixel height within a given string.
**
**          This function alway produces positive values.
**
** The height of the highest character of all characters within the string
** is returned. Line breaks are ignored.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   charPtr
**              The string whose maximum pixel height is to be calculated.
** \param   length
**              The number of characters that should be considered for the
**              maximum pixel height. Pass 0 to analyse the whole string.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**              - #FONTSERVER_ERR_BAD_PARAMETER if the given charPtr is NULL.
**              - some engine specific error code.
**
** \return
**          - Maximum pixel height on success.
**          - 0 if an error occured.
**
** \sa
**          - FONTSERVER_GetStringPixelWidth()
**
*****************************************************************************
*/
uint32_t FONTSERVER_GetStringPixelHeight(FAPI_SYS_HandleT handle,       \
                                         const uint8_t* charPtr,        \
                                         uint32_t length,               \
                                         int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    uint32_t max_height     = 0;
    uint32_t height         = 0;
    uint16_t ch_code        = 0xFFFF;
    const uint8_t* chr_ptr  = charPtr;
    uint32_t new_value      = 0;

    if(errorCodePtr)
    {
        *errorCodePtr = FAPI_OK;
    }
    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    if (charPtr == NULL)
    {
        if (errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return (0);
    }
    if(length == 0)
    {
        length = UINT32_MAX;
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    do
    {
        if (handle_ptr->encoding == FONTSERVER_ENCODING_8_BIT)
        {
            ch_code = (uint16_t)*chr_ptr++;
        }
        else // if(handle_ptr->encoding == FONTSERVER_ENCODING_16_BIT)
        {
            ch_code = fontserverRead2Bytes(chr_ptr);
            chr_ptr += 2;
            if((ch_code >= FONTSERVER_PRIVATE_USE_AREA_START)
            && (ch_code <= FONTSERVER_PRIVATE_USE_AREA_END))
            {
                new_value = fontserverRead4Bytes(chr_ptr);
                switch(ch_code)
                {
                    case(FONTSERVER_CHAR_CODE_SET_FONT):
                        if(fontserverInventoryPtr[new_value].fontDataPtr != NULL)
                        {
                            handle_ptr->curFontIndex = new_value;
                            fontserverUpdateFaceId(handle_ptr);
                        }
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_SIZE):
                        handle_ptr->curSize = new_value;
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_COLOUR):
                        break;
                    default:
                        break;
                }
                chr_ptr += 4;
                continue;
            }
        }
        length--;
        if(ch_code == '\0')
        {
            break;
        }
        height = fontserverInventoryPtr[handle_ptr->curFontIndex].enginePtr->getCharHeight \
                                                        (handle_ptr, ch_code, errorCodePtr);
        if (max_height < height)
        {
            max_height = height;
        }
    }while(length != 0);

    fontserverResetCharCodeSettings(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(max_height);
}

/*!
*****************************************************************************
** \brief   Determines the width of a given string in pixels.
**
**          This function may also produce negative values if the string
**          contains control characters that cause a negative advance in
**          the horizontal direction.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   charPtr
**              The string whose pixel length is to be calculated.
** \param   length
**              The number of characters that should be considered for the
**              calculation. Pass 0 to analyse the whole string.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**              - #FONTSERVER_ERR_BAD_PARAMETER if the given charPtr is NULL.
**              - some engine specific error code.
**
** \return
**          - Length of the string in pixels on success.
**          - 0 if an error occured.
**
** \sa
**          - FONTSERVER_GetStringPixelHeight()
**
*****************************************************************************
*/
int32_t FONTSERVER_GetStringPixelWidth (FAPI_SYS_HandleT handle,        \
                                        const uint8_t* charPtr,         \
                                        uint32_t length,                \
                                        int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    const uint8_t* chr_ptr        = charPtr;
    uint16_t ch_code        = 0;
    int32_t pixel_length    = 0;
    uint32_t new_value      = 0;

    if(errorCodePtr)
    {
        *errorCodePtr = FAPI_OK;
    }
    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    if (charPtr == NULL)
    {
        if (errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return (0);
    }
    if (length == 0)
    {
        length = UINT32_MAX;
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    do
    {
        if (handle_ptr->encoding == FONTSERVER_ENCODING_8_BIT)
        {
            ch_code = (uint16_t)*chr_ptr++;
        }
        else // if(handle_ptr->encoding == FONTSERVER_ENCODING_16_BIT)
        {
            ch_code = fontserverRead2Bytes(chr_ptr);
            chr_ptr += 2;
            if((ch_code >= FONTSERVER_PRIVATE_USE_AREA_START)
            && (ch_code <= FONTSERVER_PRIVATE_USE_AREA_END))
            {
                new_value = fontserverRead4Bytes(chr_ptr);
                switch(ch_code)
                {
                    case(FONTSERVER_CHAR_CODE_SET_FONT):
                        if(fontserverInventoryPtr[new_value].fontDataPtr != NULL)
                        {
                            handle_ptr->curFontIndex = new_value;
                            fontserverUpdateFaceId(handle_ptr);
                        }
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_SIZE):
                        handle_ptr->curSize = new_value;
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_COLOUR):
                        break;
                    default:
                        break;
                }
                chr_ptr += 4;
                continue;
            }
        }
        length--;
        if(ch_code == '\0')
        {
            break;
        }
        pixel_length += fontserverInventoryPtr[handle_ptr->curFontIndex].enginePtr->getCharWidth \
                                                            (handle_ptr, ch_code, errorCodePtr);
    }while(length != 0);

    fontserverResetCharCodeSettings(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return (pixel_length);
}

/*!
*****************************************************************************
** \brief   Determines the number of characters of a given string that fit
**          into a given length in pixels.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   charPtr
**              The string to be analysed.
** \param   pixelWidth
**              The maximum length of the string in pixels.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**              - #FONTSERVER_ERR_BAD_PARAMETER if the given charPtr is NULL.
**              - #FONTSERVER_ERR_NEGATIVE_CHAR_ADVANCE
**                  if one of the characters in the string causes a
**                  negative advance to the next character.
**              - some engine specific error code.
**
** \return
**          Number of characters that fit for the length on success.
**
** \sa
**          - FONTSERVER_GetStringPixelWidth()
**
*****************************************************************************
*/
uint32_t FONTSERVER_GetNumCharsFitByPixelWidth (FAPI_SYS_HandleT handle, \
                                          const uint8_t* charPtr,        \
                                          uint32_t pixelWidth,           \
                                          int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    uint32_t char_count         = 0;
    const uint8_t* chr_ptr      = charPtr;
    uint16_t ch_code            = 0;
    uint32_t string_width_sum   = 0;
    int32_t  current_width      = 0;
    uint32_t new_value          = 0;

    if(errorCodePtr)
    {
        *errorCodePtr = FAPI_OK;
    }
    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    if (charPtr == NULL)
    {
        if (errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return(0);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    do
    {
        if (handle_ptr->encoding == FONTSERVER_ENCODING_8_BIT)
        {
            ch_code = (uint16_t)*chr_ptr++;
        }
        else // if(handle_ptr->encoding == FONTSERVER_ENCODING_16_BIT)
        {
            ch_code = fontserverRead2Bytes(chr_ptr);
            chr_ptr += 2;
            if((ch_code >= FONTSERVER_PRIVATE_USE_AREA_START)
            && (ch_code <= FONTSERVER_PRIVATE_USE_AREA_END))
            {
                new_value = fontserverRead4Bytes(chr_ptr);
                switch(ch_code)
                {
                    case(FONTSERVER_CHAR_CODE_SET_FONT):
                        if(fontserverInventoryPtr[new_value].fontDataPtr != NULL)
                        {
                            handle_ptr->curFontIndex = new_value;
                            fontserverUpdateFaceId(handle_ptr);
                        }
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_SIZE):
                        handle_ptr->curSize = new_value;
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_COLOUR):
                        break;
                    default:
                        break;
                }
                chr_ptr += 4;
                continue;
            }
        }
        char_count++;
        if(ch_code == 0)
        {
            break;
        }
        current_width = fontserverInventoryPtr[handle_ptr->curFontIndex].enginePtr->getCharWidth \
                                                            (handle_ptr, ch_code, errorCodePtr);
        if(current_width < 0)
        {
            if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_NEGATIVE_CHAR_ADVANCE;
            fontserverResetCharCodeSettings(handle_ptr);
            FONTSERVER_UNLOCK;
            return(0);
        }
        string_width_sum += (uint32_t)current_width;
    }while(string_width_sum <= pixelWidth);

    fontserverResetCharCodeSettings(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return ((uint32_t)((int32_t)char_count - 1));
}

/*!
*****************************************************************************
** \brief   Prints a single character on an OSD/CP.
**
**          The character is printed at coordinates relative to the origin
**          of the OSD/CP layer.
**
** \note    The passed coordinates describe the top left corner of the
**          character.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   charPtr
**              Points to a single character to be printed.
** \param   xx
**              The x coordinate on the layer where the character will
**              be printed.
** \param   yy
**              The y coordinate on the layer where the character will
**              be printed. It depends on the implementation of the used
**              engine whether this parameter indicates the top border, the
**              bottom border or the baseline of the character. The FBF
**              engine accepts the top border, the freetype engine accepts
**              the baseline.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**              - #FONTSERVER_ERR_BAD_PARAMETER
**                  - if the passed character pointer is NULL.
**                  - if the requested layer has not been started yet.
**              - #FONTSERVER_ERR_BAD_COLOUR if the set colour uses too many
**                  bits in order to fit for the selected OSD.
**              - some OSDHANDLER error code if the OSDHANDLER did not
**                  return with FAPI_OK when retrieving the layer parameters.
**              - #FONTSERVER_ERR_OUT_OF_OSD_SIZE
**                  if the given coordinates are out of bounds of the OSD/CP
**                  resolution.
**              - some engine specific error code.
**
** \return
**          - Horizontal advance value on success (usually positive but may
**            also be negative for special characters).
**
** \sa
**          - FONTSERVER_PrintString()
**
*****************************************************************************
*/
int32_t  FONTSERVER_PrintChar(FAPI_SYS_HandleT handle,          \
                              const uint8_t* charPtr,           \
                              uint32_t xx,                      \
                              uint32_t yy,                      \
                              int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    const uint8_t* chr_ptr   = charPtr;
    int32_t  result          = 0;
    uint16_t ch_code         = 0;
    OSDHANDLER_LayerParamsT layer_params;

    memset(&layer_params, 0, sizeof(OSDHANDLER_LayerParamsT));

    if (errorCodePtr)
    {
        *errorCodePtr = FAPI_OK;
    }
    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    if (charPtr == NULL)
    {
        if (errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return (0);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    result = OSDHANDLER_GetLayerParameters(handle_ptr->layerId, &layer_params);
    if (result != FAPI_OK)
    {
        /* OSDHANDLER not initialized or bad OSD qualifier or no OSD handle
        ** or bad colour mode
        */
        if(errorCodePtr) *errorCodePtr = result;

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        return(0);
    }
    if(layer_params.pictureBase == 0)
    {
        //layer has not been started
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        return(0);
    }
    if((layer_params.bpp < 32) && (handle_ptr->curColour >> layer_params.bpp))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_COLOUR;

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        return(0);
    }
    if (handle_ptr->encoding == FONTSERVER_ENCODING_8_BIT)
    {
        ch_code = (uint16_t)*chr_ptr;
    }
    else // if(handle_ptr->encoding == FONTSERVER_ENCODING_16_BIT)
    {
        ch_code = fontserverRead2Bytes(chr_ptr);
    }
    result = fontserverInventoryPtr[handle_ptr->defFontIndex].enginePtr->writeChar \
                            (handle_ptr,                \
                             ch_code,                   \
                             &layer_params,             \
                             xx,                        \
                             yy,                        \
                             errorCodePtr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    if((errorCodePtr) && (*errorCodePtr != FAPI_OK)) return (0);
    return(result);
}

/*!
*****************************************************************************
** \brief   Prints a string on an OSD/CP.
**
**          The string is printed at coordinates relative to the origin of the
**          OSD/CP layer. Line breaks are ignored. In order to print a string
**          with line breaks split up the string and print its parts
**          individually.
**
** \note
**          The passed coordinates describe the top left corner of the
**          first character in the string.
**
** \note
**          You may pass control codes within the string that select a
**          different font or set a new font colour or size. The settings
**          will be reset to default settings when the string has been printed.
**          All control codes will take the subsequent 4 bytes as their
**          argument where the first byte is the least significant one.
**          Possible control codes are:
**              - FONTSERVER_CHAR_CODE_SET_FONT
**              - FONTSERVER_CHAR_CODE_SET_SIZE
**              - FONTSERVER_CHAR_CODE_SET_COLOUR
**              .
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   charPtr
**              The string to be printed.
** \param   length
**              The count of characters to be printed. Pass 0 to print
**              the whole string.
** \param   xx
**              The x coordinate on the layer where the string will
**              be printed.
** \param   yy
**              The y coordinate on the layer where the string will
**              be printed. It depends on the implementation of the used
**              engine whether this parameter indicates the top border, the
**              bottom border or the baseline of the string. The FBF
**              engine accepts the top border, the freetype engine accepts
**              the baseline.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible values:
**              - #FAPI_OK on success.
**              - #FONTSERVER_ERR_INVALID_HANDLE if the handle is invalid.
**              - #FONTSERVER_ERR_BAD_PARAMETER
**                  - if the passed string is NULL.
**                  - if the requested layer has not been started yet.
**              - #FONTSERVER_ERR_BAD_COLOUR if the set colour uses too many
**                  bits in order to fit for the selected OSD.
**              - some OSDHANDLER error code if the OSDHANDLER did not
**                  return with FAPI_OK when retrieving the layer parameters.
**              - #FONTSERVER_ERR_OUT_OF_OSD_SIZE
**                  if the given coordinates are out of bounds of the OSD/CP
**                  resolution or if the fontserver runs out of bounds of
**                  the OSD/CP while printing the string.
** \return
**          - Horizontal advance value on success (usually positive but may
**            also be negative for special characters).
**
** \sa
**          - FONTSERVER_PrintChar()
**
*****************************************************************************
*/
int32_t  FONTSERVER_PrintString(FAPI_SYS_HandleT handle,        \
                                const uint8_t* charPtr,         \
                                uint32_t length,                \
                                uint32_t xx,                    \
                                uint32_t yy,                    \
                                int32_t* errorCodePtr)
{
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;
    const uint8_t* chr_ptr      = charPtr;  // current string pos
    uint16_t    ch_code         = 0;        // current character code
    int32_t     x_pos           = 0;        // current x position
    uint32_t    y_pos           = 0;        // current y position
    uint32_t    new_value       = 0;        // new value for control codes
    int32_t     result          = 0;
    OSDHANDLER_LayerParamsT layer_params;

    memset(&layer_params, 0, sizeof(OSDHANDLER_LayerParamsT));

    if(errorCodePtr)
    {
        *errorCodePtr = FAPI_OK;
    }
    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    if (charPtr == NULL)
    {
        if (errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;
        return (0);
    }

    ////////////////
    FONTSERVER_LOCK;
    ////////////////

    result = OSDHANDLER_GetLayerParameters(handle_ptr->layerId, &layer_params);
    if (result != FAPI_OK)
    {
        /* OSDHANDLER not initialized or bad OSD qualifier or no OSD handle
        ** or bad colour mode
        */

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        if(errorCodePtr) *errorCodePtr = result;
        return(0);
    }
    if(layer_params.pictureBase == 0)
    {
        //layer has not been started
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_PARAMETER;

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        return(0);
    }
    if((layer_params.bpp < 32) && (handle_ptr->curColour >> layer_params.bpp))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_BAD_COLOUR;

        //////////////////
        FONTSERVER_UNLOCK;
        //////////////////

        return(0);
    }
    if (length == 0)
    {
        length = UINT32_MAX;
    }

    x_pos = (int32_t)xx;
    y_pos = yy;

    // ********************** draw the characters *****************************
    do
    {
        if (handle_ptr->encoding == FONTSERVER_ENCODING_8_BIT)
        {
            ch_code = (uint16_t)*chr_ptr++;
        }
        else // if(handle_ptr->encoding == FONTSERVER_ENCODING_16_BIT)
        {
            ch_code = fontserverRead2Bytes(chr_ptr);
            chr_ptr += 2;
            // Character Control Codes
            if((ch_code >= FONTSERVER_PRIVATE_USE_AREA_START)
            && (ch_code <= FONTSERVER_PRIVATE_USE_AREA_END))
            {
                new_value = fontserverRead4Bytes(chr_ptr);
                switch(ch_code)
                {
                    case(FONTSERVER_CHAR_CODE_SET_FONT):
                        if(fontserverInventoryPtr[new_value].fontDataPtr != NULL)
                        {
                            handle_ptr->curFontIndex = new_value;
                            fontserverUpdateFaceId(handle_ptr);
                        }
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_SIZE):
                        handle_ptr->curSize = new_value;
                        break;
                    case(FONTSERVER_CHAR_CODE_SET_COLOUR):
                        if(!((layer_params.bpp < 32) && (new_value >> layer_params.bpp)))
                        {
                            handle_ptr->curColour = new_value;
                            (void)fontserverSetUpAntiAliasing(handle_ptr);
                        }
                        break;
                    default:
                        break;
                }
                chr_ptr += 4;
                continue;
            }
        }
        length--;
        if (ch_code == '\0')
        {
            break;
        }
        if (x_pos < 0)
        {

            if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_OUT_OF_OSD_SIZE;
            fontserverResetCharCodeSettings(handle_ptr);

            //////////////////
            FONTSERVER_UNLOCK;
            //////////////////

            return(0);
        }
        // add the advance value of the current character:
        x_pos += fontserverInventoryPtr[handle_ptr->curFontIndex].enginePtr->writeChar \
                            (handle_ptr,                \
                             ch_code,                   \
                             &layer_params,             \
                             (uint32_t)x_pos,           \
                             y_pos,                     \
                             &result);
    }while((length != 0) && (result == 0));

    if(result) // an error occured while calling writeChar()
    {
        fontserverResetCharCodeSettings(handle_ptr);
        if(errorCodePtr) *errorCodePtr = result;
        FONTSERVER_UNLOCK;
        return(x_pos - (int32_t)xx);
    }

    fontserverResetCharCodeSettings(handle_ptr);

    //////////////////
    FONTSERVER_UNLOCK;
    //////////////////

    return(x_pos - (int32_t)xx);
}

/*!
*****************************************************************************
** \brief   Determine the font internal character index by the unicode
**          character code.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   chCode
**              Unicode encoding of the character
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible error codes depend on the used engine(s).
**
** \return
**          Internal character index.
**
*****************************************************************************
*/
uint32_t FONTSERVER_Unicode2Index(FAPI_SYS_HandleT handle, \
                                  uint32_t chCode,         \
                                  int32_t* errorCodePtr)
{
    uint32_t result = 0;
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    result = fontserverInventoryPtr[handle_ptr->defFontIndex].enginePtr->unicode2Index \
                                            (handle_ptr, chCode, errorCodePtr);
    return(result);
}

/*!
*****************************************************************************
** \brief   Determine the unicode character code by a font internal
**          character index.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   chIndex
**              Font internal character index.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible error codes depend on the used engine(s).
**
** \return
**          Unicode character coding.
**
*****************************************************************************
*/
uint32_t FONTSERVER_Index2Unicode(FAPI_SYS_HandleT handle, \
                                  uint32_t chIndex,        \
                                  int32_t* errorCodePtr)
{
    uint32_t result = 0;
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    result = fontserverInventoryPtr[handle_ptr->defFontIndex].enginePtr->index2Unicode \
                                                (handle_ptr, chIndex, errorCodePtr);
    return(result);
}

/*!
*****************************************************************************
** \brief   Get kerning information about two characters.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   charLeft
**              The left character.
** \param   charRight
**              The right character.
** \param   errorCodePtr
**              Optional argument that will receive FAPI error codes.
**              Possible error codes depend on the used engine(s).
**
** \return
**          Horizontal kerning distance.
**
*****************************************************************************
*/
int32_t  FONTSERVER_GetKerning(FAPI_SYS_HandleT handle, \
                               uint32_t charLeft,       \
                               uint32_t charRight,      \
                               int32_t* errorCodePtr)
{
    int32_t result = 0;
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        if(errorCodePtr) *errorCodePtr = FONTSERVER_ERR_INVALID_HANDLE;
        return(0);
    }
    result = fontserverInventoryPtr[handle_ptr->defFontIndex].enginePtr->getKerning \
                                    (handle_ptr, charLeft, charRight, errorCodePtr);
    return(result);
}

/*!
*****************************************************************************
** \brief   Retrieves information of a glyph.
**
** \param   handle
**              Driver instance handle previously returned by FONTSERVER_Open.
** \param   chCode
**              Encoding of the character.
**
** \return
**          - #FAPI_OK on success.
**          - Further error codes depend on the used engine(s).
**
*****************************************************************************
*/
int32_t  FONTSERVER_GetGlyphInfo(FAPI_SYS_HandleT handle,             \
                                 uint32_t chCode,                     \
                                 FONTSERVER_GlyphInfoT* glyphInfoPtr)
{
    int32_t result = 0;
    FONTSERVER_HandleT* handle_ptr = (FONTSERVER_HandleT*)handle;

    if( ! fontserverCheckHandle(handle_ptr))
    {
        return(FONTSERVER_ERR_INVALID_HANDLE);
    }
    result = fontserverInventoryPtr[handle_ptr->defFontIndex].enginePtr->getGlyphInfo \
                                                    (handle_ptr, chCode, glyphInfoPtr);
    return(result);
}
