/*
*****************************************************************************
**
** \file        ./subsystems/paint/draw/src/draw.c
**
** \brief       DRAW Driver
**
** This file contains the implementation of the DRAW driver's core API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2008-2009 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2008-2009 by Fujitsu Microelectronics Limited
**
*****************************************************************************
*/

#include "fapi/sys_services.h"
#include "osdhandler/osdhandler.h"
#include "draw.h"
#include "draw_priv.h"
#if DRAW_ENABLE_PNG == 1
#include "png/png.h"
#endif

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


//***************************************************************************
//***************************************************************************
//** Local Data
//***************************************************************************
//***************************************************************************

uint32_t drawInitialized = 0; //21f71c94


//***************************************************************************
//***************************************************************************
//** Local Functions Declaration
//***************************************************************************
//***************************************************************************
static void drawGetPixelAddress(const uint32_t xx,              \
                                const uint32_t yy,              \
                                uint32_t* pixelBaseAddrPtr,     \
                                uint32_t* pixelBitOffsetPtr,    \
                                OSDHANDLER_LayerParamsT* layerParamsPtr);
static uint32_t drawReadBytes(uint8_t* bytePtr, uint32_t nn);
static OSDHANDLER_ColourModeT drawExtractFujitsuBitmapOsdMode(DRAW_ColourModeEnumT mode);
static OSDHANDLER_ColourModeT drawExtractFujitsuBitmapCpMode(DRAW_ColourModeEnumT mode);
static OSDHANDLER_OsdLayoutEnumT drawExtractFBMLayoutMode(DRAW_ColourModeEnumT mode);
/*static*/ uint32_t drawExtractBitDepth(DRAW_ColourModeEnumT mode);
#if DRAW_ENABLE_PNG == 1
static void drawPngWarning(png_structp pngPtr, png_const_charp msgPtr);
static void drawPngError(png_structp pngPtr, png_const_charp msgPtr);
static png_voidp drawPngMalloc(png_structp pngPtr, png_size_t bytes);
static void drawPngFree(png_structp pngPtr, png_voidp memPtr);
static void drawPngReadData(png_structp pngPtr, png_bytep dataPtr, png_size_t length);
static void drawPngTransformRGBA2CbYCrA(png_structp pngPtr, png_row_infop rowInfoPtr, png_bytep rowDataPtr);
static void drawPngTransformARGB2ACbYCr(png_structp pngPtr, png_row_infop rowInfoPtr, png_bytep rowDataPtr);
#endif

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
static void drawGetPixelAddress(const uint32_t xx,           \
                                const uint32_t yy,           \
                                uint32_t* pixelBaseAddrPtr,  \
                                uint32_t* pixelBitOffsetPtr, \
                                OSDHANDLER_LayerParamsT* layerParamsPtr)
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
** \brief   Read nn bytes from a pointer and return the result in a 4byte word.
**
** \param   bytePtr points to the location where to begin with reading the bytes
** \param   nn      the count of bytes that will be read
**
** \return          - 0 if nn is 0 or greater than 4.
**                  - the read value on success
*****************************************************************************
*/
static uint32_t drawReadBytes(uint8_t* bytePtr, uint32_t nn)
{
    uint32_t result = 0x00000000UL;
    uint32_t ii     = 0UL;

    if(nn > 4)
    {
        return (result);
    }

    for(ii = 0; ii < nn; ii++)
    {
        result = (*bytePtr++ << (ii << 3)) | result;
    }
    return(result);
}

/*!
*****************************************************************************
** \brief   Read a colour (that is coded as ARGB in win bitmap files) as a
**          RGBA colour and return it.
**
** \param   srcPtr  Points to an ARGB coded 32-bit colour value.
**
** \return          RGBA coded 32-bit colour value.
*****************************************************************************
*/
static uint32_t drawReadRgbaColour(uint8_t* srcPtr)
{
    return ((drawReadBytes(srcPtr, 3) << 8) | (*(srcPtr + 3)));
}

/*!
*****************************************************************************
** \brief           Extracts an OSDHANDLER related OSD colour mode
**                  from a DRAW related one.
**
** \param   mode    DRAW related colour mode.
**
** \return          OSDHANDLER related OSD colour mode.
**
*****************************************************************************
*/
static OSDHANDLER_ColourModeT drawExtractFujitsuBitmapOsdMode(DRAW_ColourModeEnumT mode)
{
    uint32_t modeInt = (uint32_t)mode;
    switch(modeInt)
    {
        case(0x00000002):
        case(0x00010002):
            return(OSDHANDLER_OSD_MODE_CLUT_4BIT);
        case(0x00000003):
        case(0x00010003):
            return(OSDHANDLER_OSD_MODE_CLUT_8BIT);
        case(0x00010009):
            return(OSDHANDLER_OSD_MODE_5551);
        case(0x0000000A):
        case(0x0000000B):
        case(0x0001000A):
        case(0x0001000B):
            return(OSDHANDLER_OSD_MODE_32_24BIT);
        case(0x00000000):
        case(0x00000001):
        case(0x00010000):
        case(0x00010001):
        default:
            return(OSDHANDLER_OSD_MODE_UNKNOWN);
    }
}

/*!
*****************************************************************************
** \brief           Extracts an OSDHANDLER related Cursor Plane colour mode
**                  from a DRAW related one.
**
** \param   mode    DRAW related colour mode.
**
** \return          OSDHANDLER related Cursor Plane colour mode.
**
*****************************************************************************
*/
static OSDHANDLER_ColourModeT drawExtractFujitsuBitmapCpMode(DRAW_ColourModeEnumT mode)
{
    uint32_t modeInt = (uint32_t) mode;
    switch(modeInt)
    {
        case(0x00000000):
        case(0x00010000):
            return(OSDHANDLER_CURSOR_MODE_1BIT);
        case(0x00000001):
        case(0x00010001):
            return(OSDHANDLER_CURSOR_MODE_2BIT);
        case(0x00000002):
        case(0x00010002):
            return(OSDHANDLER_CURSOR_MODE_4BIT);
        case(0x00000003):
        case(0x00010003):
            return(OSDHANDLER_CURSOR_MODE_8BIT);
        case(0x0000000A):
        case(0x0000000B):
        case(0x00010009):
        case(0x0001000A):
        case(0x0001000B):
        default:
            return(OSDHANDLER_OSD_MODE_UNKNOWN);
    }
}

/*!
*****************************************************************************
** \brief           Extracts an OSDHANDLER related colour layout mode
**                  from a DRAW related colour mode.
**
** \param   mode    DRAW related colour mode.
**
** \return          OSDHANDLER_OsdLayoutEnumT corresponding to the colour mode.
**
*****************************************************************************
*/
static OSDHANDLER_OsdLayoutEnumT drawExtractFBMLayoutMode(DRAW_ColourModeEnumT mode)
{
    uint32_t modeInt = (uint32_t)mode;
    switch(modeInt)
    {
        case(0x00000000):
        case(0x00000001):
        case(0x00000002):
        case(0x00000003):
        case(0x0000000A):
        case(0x0000000B):
            return(OSDHANDLER_OSD_LAYOUT_CbYCrA);
        case(0x00010000):
        case(0x00010001):
        case(0x00010002):
        case(0x00010003):
        case(0x00010009):
        case(0x0001000A):
        case(0x0001000B):
            return(OSDHANDLER_OSD_LAYOUT_RGBA);
        default:
            return(OSDHANDLER_UNKNOWN_OSD_LAYOUT);
    }
}

/*!
*****************************************************************************
** \brief           Gets the amount of bits per pixel for a specified
**                  colour mode.
**
** \param   mode    DRAW related colour mode.
**
** \return          count of bits per pixel.
**
*****************************************************************************
*/
/*static*/ uint32_t drawExtractBitDepth(DRAW_ColourModeEnumT mode)
{
    uint32_t modeInt = (uint32_t)mode;
    switch(modeInt)
    {
        case(0x00000000):
        case(0x00010000):
            return(1);
        case(0x00000001):
        case(0x00010001):
            return(2);
        case(0x00000002):
        case(0x00010002):
            return(4);
        case(0x00000003):
        case(0x00010003):
            return(8);
        case(0x00010009):
            return(16);
        case(0x0000000A):
        case(0x0001000A):
            return(24);
        case(0x0000000B):
        case(0x0001000B):
            return(32);
        default:
            return(0);
    }
}

#if DRAW_ENABLE_PNG == 1
/*!
*******************************************************************************
**
** \brief Print a PNG warning message.
**
** This function prints the given PNG warning message using
** FAPI_SYS_PRINT_MSG.
**
** \note This function must be set via "png_set_error_fn()" in order to be used
**       instead of the default inbuild libc based function.
**
** \param pngPtr Pointer to the png structure to access, currently unused.
** \param msgPtr The warning message to be printed.
**
*******************************************************************************
**/
static void drawPngWarning(png_structp pngPtr, png_const_charp msgPtr)
{
    FAPI_SYS_PRINT_MSG("\n[libpng] Warning: %s\n", msgPtr);
}

/*!
*******************************************************************************
**
** \brief Print a PNG error message.
**
** This function prints the given PNG error message using
** FAPI_SYS_PRINT_MSG.
**
** \note This function must be set via "png_set_error_fn()" in order to be used
**       instead of the default inbuild libc based function.
**
** \param pngPtr Pointer to the png structure to access, currently unused.
** \param msgPtr The error message to be printed.
**
*******************************************************************************
**/
static void drawPngError(png_structp pngPtr, png_const_charp msgPtr)
{
    FAPI_SYS_PRINT_MSG("\n[libpng] Error: %s\n", msgPtr);
    longjmp(png_jmpbuf(pngPtr), 1);
}

/*!
*******************************************************************************
**
** \brief Allocate dynamic memory
**
** This function allocated the given number of bytes from the dynamical heap
** memory space by FAPI_SYS_MALLOC.
**
** \note This function must be set via "png_set_mem_fn()" in order to be used
**       instead of the default inbuild libc based function.
**
** \param pngPtr  Pointer to the png structure to access, currently unused.
** \param bytes The number of bytes to allocate.
**
** \return
** - NULL in case of error, no more memory available
** - non-NULL, a pointer to the allocated memory block
**
*******************************************************************************
**/
static png_voidp drawPngMalloc(png_structp pngPtr, png_size_t bytes)
{
    png_voidp memPtr;
    memPtr = FAPI_SYS_MALLOC(bytes);
    return(memPtr);
}

/*!
*******************************************************************************
**
** \brief Release dynamic memory.
**
** This function releases a previously allocated dynamical memory block from
** the heap memory space by FAPI_SYS_FREE.
**
** \note This function must be set via "png_set_mem_fn()" in order to be used
**       instead of the default inbuild libc based function.
**
** \param pngPtr    Pointer to the png structure to access, currently unused.
** \param memPtr    The address of the memory block to release.
**
*******************************************************************************
**/
static void drawPngFree(png_structp pngPtr, png_voidp memPtr)
{
    FAPI_SYS_FREE(memPtr);
    return;
}

/*!
*******************************************************************************
**
** \brief Read PNG data from file
**
** This function replaces the filesystem related read function from the libpng.
**
** \note This function must be set via "png_set_read_fn()" in order to be used
**       instead of the default inbuild libc based function.
**
** \param pngPtr  The PNG data structure to access.
** \param dataPtr A pointer to a data buffer that will be filled with PNG data.
** \param length  The number of bytes to be written.
**
*******************************************************************************
**/
static void drawPngReadData(png_structp pngPtr, png_bytep dataPtr, png_size_t length)
{
    void*   result;
    uint8_t **pos_ptr_ptr;

    pos_ptr_ptr = png_get_io_ptr(pngPtr);
    result = memcpy(dataPtr, *pos_ptr_ptr, length);
    *pos_ptr_ptr += length;
    if(! result)
    {
        png_error(pngPtr, "Error on drawPngReadData\n");
    }
    return;
}

/*!
*******************************************************************************
**
** \brief Color transformation function: RGBA to CbYCrA
**
** This callback function transforms the color values from RGBA into CbYCrA
** format as expected by the OSD engine in OSDHANDLER_OSD_LAYOUT_CbYCrA mode.
**
** \param pngPtr     The PNG data structure to access.
** \param rowInfoPtr The PNG row information data to image information from.
** \param rowDataPtr The PNG data buffer to modify.
**
*******************************************************************************
*/
/* 21c84620 - complete */
static void drawPngTransformRGBA2CbYCrA(png_structp pngPtr, png_row_infop rowInfoPtr, png_bytep rowDataPtr)
{
    OSDHANDLER_ARGB__T a_r_g_b_word;
    OSDHANDLER_CbYCrA__T cb_y_cr_a_word;
    uint32_t ii;

    ii = rowInfoPtr->rowbytes / 4;
    while(ii--)
    {
        a_r_g_b_word.comp.alpha  = * rowDataPtr;
        a_r_g_b_word.comp.b      = *(rowDataPtr + 1);
        a_r_g_b_word.comp.g      = *(rowDataPtr + 2);
        a_r_g_b_word.comp.r      = *(rowDataPtr + 3);
        cb_y_cr_a_word.all  = OSDHANDLER_ConvertARGB2CbYCrA_union(a_r_g_b_word);
        * rowDataPtr        = cb_y_cr_a_word.comp.alpha;
        *(rowDataPtr + 1)   = cb_y_cr_a_word.comp.cr;
        *(rowDataPtr + 2)   = cb_y_cr_a_word.comp.y;
        *(rowDataPtr + 3)   = cb_y_cr_a_word.comp.cb;
        rowDataPtr += 4;
    }
    return;
}

/*!
*******************************************************************************
**
** \brief Color transformation function: ARGB to ACbYCr
**
** This callback function transforms the color values from ARGB into ACbYCr
** format as expected by the OSD engine in OSDHANDLER_OSD_LAYOUT_ACbYCr mode.
**
** \param pngPtr     The PNG data structure to access.
** \param rowInfoPtr The PNG row information data to image information from.
** \param rowDataPtr The PNG data buffer to modify.
**
*******************************************************************************
*/
static void drawPngTransformARGB2ACbYCr(png_structp pngPtr, png_row_infop rowInfoPtr, png_bytep rowDataPtr)
{
    uint32_t a_r_g_b_word;
    uint32_t cb_y_cr_a_word;
    uint32_t ii;

    ii = rowInfoPtr->rowbytes / 4;
    while(ii--)
    {
        a_r_g_b_word =   (* rowDataPtr)              | // B
                         (*(rowDataPtr + 1)) <<  8   | // G
                        ((*(rowDataPtr + 2)) << 16)  | // R
                        ((*(rowDataPtr + 3)) << 24);   // A
        cb_y_cr_a_word = OSDHANDLER_ConvertARGB2CbYCrA_word(a_r_g_b_word);

        *rowDataPtr       = (cb_y_cr_a_word & 0x0000FF00UL) >>  8; // Cr
        *(rowDataPtr + 1) = (cb_y_cr_a_word & 0x00FF0000UL) >> 16; // Y
        *(rowDataPtr + 2) = (cb_y_cr_a_word & 0xFF000000UL) >> 24; // Cb
        *(rowDataPtr + 3) = (cb_y_cr_a_word & 0x000000FFUL);       // A
        rowDataPtr += 4;
    }
    return;
}
#endif /* DRAW_ENABLE_PNG == 1 */

//***************************************************************************
//***************************************************************************
//** API Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief Initialize the DRAW driver.
**
** This function initializes the driver.
**
**
** \return
**        - #FAPI_OK if initialization was successful
**        - #DRAW_ERR_ALREADY_INITIALIZED if the DRAW driver has already been
**          initialized
**        - #OSDHANDLER_ERR_NOT_INITIALIZED If the OSDHANDLER (that is needed in
**          order to use this driver) has not been initialized previously.
**
** \sa
**          - DRAW_Exit()
**
*****************************************************************************
*/
/* 21c86190 - complete */
int32_t DRAW_Init(void)
{
    if (drawInitialized)
    {
        return(DRAW_ERR_ALREADY_INITIALIZED);
    }

    if (!OSDHANDLER_IsInitialized())
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }

    drawInitialized = 1;

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Exit the DRAW driver
**
** This function shutdowns the driver.
**
** \sa
**          - DRAW_Init()
**
*****************************************************************************
*/
/* 21c80504 - complete */
void DRAW_Exit(void)
{
    drawInitialized = 0;
    return;
}

/*!
*****************************************************************************
** \brief   Draws a rectangle with round corners.
**
** \note    - You can draw a circle by drawing a square and provide the
**            roundRadius as the half of the side length of the square. <br>
**            The center of the circle is therefore
**            (xx + (width / 2)), (yy + (width / 2)) for width = height.
**          - If you want to draw a simple rectangle without round corners,
**            please use OSDHANDLER_BitBlitFill(). This one has less overhead.
**          - Lint error 923 temporarily disabled (6 calls) within function.
**            Casts from type to type are mandatory here for pointer
**            arithmetics.
**
** \param   layerId
                Specifies on which layer the rectangle has to be drawn.
**              Pass 1 or 2 for OSD1 or OSD2 respectively and 3 for the CP.
** \param   xx
**              The x coordinate on the layer where the rectangle will be drawn.
** \param   yy
**              The y coordinate on the layer where the rectangle will be drawn.
** \param   width
**              The width of the rectangle.
** \param   height
**              The height of the rectangle.
** \param   roundRadius
**              The radius of the quarter circles for the round corners.
** \param   colour
**              The colour in which the rectangle will appear on the OSD/CP.
**
** \return
**          - #FAPI_OK on success
**          - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized
**          - #OSDHANDLER_ERR_BAD_LAYER_ID The passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
**            opened at the initialization of the OSDHANDLER.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
**            is bad. Set up the colour mode by OSDHANDLER_SetColourMode.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the requested layer
**            has not been started yet.
**          - #DRAW_ERR_BAD_PARAMETER
**            - if  the roundRadius is larger than a half of the smaller side.
**            - if the rectangle does not fit into the plane due to its
**              dimensions.
**            - if the passed colour has too many bits in order to fit for the
**              colour mode that the OSD/CP is driven by.
**
** \sa
**          - OSDHANDLER_BitBlitFill()
**
*****************************************************************************
*/
/* 21c85a60 - complete */
int32_t DRAW_RoundRectangle(const uint32_t layerId,
                            const uint32_t xx,
                            const uint32_t yy,
                            const uint32_t width,
                            const uint32_t height,
                            const uint32_t roundRadius,
                            const uint32_t colour)
{
    OSDHANDLER_LayerParamsT  draw_layer_params;
    int32_t   result        = 0; // receives results from other FAPI calls
    uint32_t* addr_1_ptr    = 0; // pointer to the address space of pixel 1
    uint32_t  addr_1        = 0; // address of pointer 1
    uint32_t  addr_offset_1 = 0; // pixel offset for pixel 1
    uint32_t* addr_2_ptr    = 0; // pointer to the address space of pixel 2
    uint32_t  addr_2        = 0; // address of pointer 2
    uint32_t  addr_offset_2 = 0; // pixel offset for pixel 2
    uint32_t  bpp           = 0; // count of bits per pixel
    uint32_t  colour_mask   = 0; // used to write single pixels in a whole word
    uint32_t  colour_32     = 0; // 32 bit colour value
    uint32_t  ii            = 0; // temporary counter
    uint32_t  x_pos_horn    = 0; // x position for the horn algorithm
    uint32_t  x_pos         = 0; // actual x position
    uint32_t  y_pos         = 0; // y position for both horn and application
    int32_t   dd            = 0; // control variable for the horn algorithm
    uint32_t  x_flag        = 0; // flag used in Horn-algorithm
    uint32_t  dword_count   = 0; // counter for 32-bit words
    uint32_t  bit_count     = 0; // counter for single bits
    uint32_t  alternate     = 0; // switch variable

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }
    memset(&draw_layer_params, 0, sizeof(draw_layer_params));
    result = OSDHANDLER_GetLayerParameters(layerId, &draw_layer_params);
    if (result != FAPI_OK)
    {
        return(result);
        // may be:
        //- #OSDHANDLER_ERR_BAD_LAYER_ID if an invalid OSD qualifier is given
        //- #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
        //  opened at initialization
        //- #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
        //  is bad. Set up the colour mode by OSDHANDLER_SetColourMode
    }
    if(draw_layer_params.pictureBase == 0)
    {
        return(OSDHANDLER_ERR_LAYER_NOT_STARTED);
    }
    if((roundRadius > (width / 2))
     ||(roundRadius > (height / 2))
     ||((xx + width) > draw_layer_params.xRes)
     ||((yy + height) > draw_layer_params.yRes)
     ||((draw_layer_params.bpp < 32) && (colour >> draw_layer_params.bpp))
     // already checked by GetLayerParameters implicitly though:
     ||(draw_layer_params.bpp == 0)
     ||(draw_layer_params.bpp > 32))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    bpp = draw_layer_params.bpp;
    colour_32 = colour;
    for (ii = ((0x20UL / bpp) - 1); ii != 0; ii--)
    {
        colour_32 = ((colour_32 << (bpp % 32)) | colour);
    }

    // draw the mid square, errors already checked implicitly:
    (void)OSDHANDLER_BitBlitFill(layerId,
                                 xx + roundRadius,
                                 yy + roundRadius,
                                 width  - (roundRadius << 1),
                                 height - (roundRadius << 1),
                                 colour);
    if(roundRadius == 0) return (FAPI_OK);

    // draw the top rectangle:
    (void)OSDHANDLER_BitBlitFill(layerId,
                                 xx + roundRadius,
                                 yy,
                                 width - (roundRadius << 1),
                                 roundRadius,
                                 colour);

    // draw the bottom rectangle:
    (void)OSDHANDLER_BitBlitFill(layerId,
                                 xx + roundRadius,
                                 (yy + height) - roundRadius,
                                 width - (roundRadius << 1),
                                 roundRadius,
                                 colour);

    // draw the left rectangle:
    (void)OSDHANDLER_BitBlitFill(layerId,
                                 xx,
                                 yy + roundRadius,
                                 roundRadius,
                                 height - (roundRadius << 1),
                                 colour);

    // draw the right rectangle:
    (void)OSDHANDLER_BitBlitFill(layerId,
                                 (xx + width) - roundRadius,
                                 yy + roundRadius,
                                 roundRadius,
                                 height - (roundRadius << 1),
                                 colour);

    // **************** Horn-algorithm ****************
    // roundRadius is known to be greater than 0.
    dd              = - (int32_t)roundRadius;
    x_pos_horn      = roundRadius;
    x_pos           = (x_pos_horn == 0) ? 0 : (x_pos_horn - 1);
    y_pos           = 0;

    while(y_pos <= x_pos)
    {
        // draw a line in each quarter circle:

        alternate = 2;
        while(alternate)
        {
            if(alternate == 2)
            {
                // RIGHT SIDE:
                // right top:
                drawGetPixelAddress((xx + width) - roundRadius,
                                    (yy + (roundRadius - 1)) - y_pos,
                                    &addr_1,
                                    &addr_offset_1,
                                    &draw_layer_params);
                // right bottom:
                drawGetPixelAddress((xx + width) - roundRadius,
                                    (yy + height + y_pos) - roundRadius,
                                    &addr_2,
                                    &addr_offset_2,
                                    &draw_layer_params);
            }
            else
            {
                // LEFT SIDE:
                // left top:
                drawGetPixelAddress((xx + (roundRadius - 1)) - x_pos,
                                    (yy + (roundRadius - 1)) - y_pos,
                                    &addr_1,
                                    &addr_offset_1,
                                    &draw_layer_params);
                // left bottom:
                drawGetPixelAddress((xx + (roundRadius - 1)) - x_pos,
                                    (yy + height + y_pos) - roundRadius,
                                    &addr_2,
                                    &addr_offset_2,
                                    &draw_layer_params);
            }
            /*lint -save -e923 */
            addr_1_ptr = (uint32_t*)addr_1;
            addr_2_ptr = (uint32_t*)addr_2;
            /*lint -restore */
            bit_count = (x_pos + 1) * bpp;

            // write the first single pixels:
            if(addr_offset_1)
            {
                colour_mask = ((1 << (32 - addr_offset_1)) - 1);

                if((addr_offset_1 + bit_count) < 32)
                {
                    colour_mask &=
                        ((0x01UL << (addr_offset_1 + bit_count)) - 0x01UL) <<
                                    (0x20UL - (addr_offset_1 + bit_count));
                        bit_count = 0;
                }
                else
                {
                    bit_count -= (32 - addr_offset_1);

                }
                *addr_1_ptr = (*addr_1_ptr & ~colour_mask) |
                                            (colour_32 & colour_mask);
                addr_1_ptr++;
                *addr_2_ptr = (*addr_2_ptr & ~colour_mask) |
                                            (colour_32 & colour_mask);
                addr_2_ptr++;
            }

            // write whole 32-bit words:
            dword_count = bit_count / 32;
            while(dword_count--)
            {
                *addr_1_ptr++ = colour_32;
                *addr_2_ptr++ = colour_32;
            }
            bit_count %= 32;

            // write remaining single pixels:
            if(bit_count)
            {
                colour_mask = ((0x01UL << bit_count) - 0x01) <<
                                                (0x20UL - bit_count);
                *addr_1_ptr = (*addr_1_ptr & ~colour_mask) |
                                            (colour_32 & colour_mask);
                *addr_2_ptr = (*addr_2_ptr & ~colour_mask) |
                                            (colour_32 & colour_mask);
            }

            // now operate on switched x_pos and y_pos values of the eighth circle:
            if(x_flag)
            {
                // write out a whole line:
                if(alternate == 2)
                {
                    // RIGHT SIDE:
                    // right top:
                    drawGetPixelAddress((xx + width) - roundRadius,
                                        (yy + (roundRadius - 1)) - x_pos,
                                        &addr_1,
                                        &addr_offset_1,
                                        &draw_layer_params);
                    // right bottom:
                    drawGetPixelAddress((xx + width) - roundRadius,
                                        (yy + height + x_pos) - roundRadius,
                                        &addr_2,
                                        &addr_offset_2,
                                        &draw_layer_params);
                }
                else
                {
                    // LEFT SIDE:
                    // left top:
                    drawGetPixelAddress((xx + (roundRadius - 1)) - y_pos,
                                        (yy + (roundRadius - 1)) - x_pos,
                                        &addr_1,
                                        &addr_offset_1,
                                        &draw_layer_params);
                    // left bottom:
                    drawGetPixelAddress((xx + (roundRadius - 1)) - y_pos,
                                        (yy + height + x_pos) - roundRadius,
                                        &addr_2,
                                        &addr_offset_2,
                                        &draw_layer_params);
                }
                /*lint -save -e923 */
                addr_1_ptr = (uint32_t*)addr_1;
                addr_2_ptr = (uint32_t*)addr_2;
                /*lint -restore */
                bit_count = (y_pos + 1) * bpp;

                // write the first single pixels:
                if(addr_offset_1)
                {
                    colour_mask = ((1 << (32 - addr_offset_1)) - 1);

                    if((addr_offset_1 + bit_count) < 32)
                    {
                        colour_mask &=
                            ((0x01UL << (addr_offset_1 + bit_count)) - 0x01UL)
                            << (0x20UL - (addr_offset_1 + bit_count));
                        bit_count = 0;
                    }
                    else
                    {
                        bit_count -= (32 - addr_offset_1);
                    }
                    *addr_1_ptr = (*addr_1_ptr & ~colour_mask) |
                                            (colour_32 & colour_mask);
                    addr_1_ptr++;
                    *addr_2_ptr = (*addr_2_ptr & ~colour_mask) |
                                            (colour_32 & colour_mask);
                    addr_2_ptr++;
                }

                // write whole words:
                dword_count = bit_count / 32;
                while(dword_count--)
                {
                    *addr_1_ptr++ = colour_32;
                    *addr_2_ptr++ = colour_32;
                }
                bit_count %= 32;

                // write the last single pixels:
                if(bit_count)
                {
                    colour_mask = ((0x01UL << bit_count) - 0x01UL) <<
                                                    (0x20UL - bit_count);
                    *addr_1_ptr = (*addr_1_ptr & ~colour_mask) |
                                                (colour_32 & colour_mask);
                    *addr_2_ptr = (*addr_2_ptr & ~colour_mask) |
                                                (colour_32 & colour_mask);
                }
            }
            else
            {
                // simply write the single pixel,
                // the rest has already been processed
                if(alternate == 2)
                {
                    // right top:
                    drawGetPixelAddress((xx + width + y_pos) - roundRadius,
                                        (yy + (roundRadius - 1)) - x_pos,
                                        &addr_1,
                                        &addr_offset_1,
                                        &draw_layer_params);
                    // right bottom:
                    drawGetPixelAddress((xx + width + y_pos) - roundRadius,
                                        (yy + height + x_pos) - roundRadius,
                                        &addr_2,
                                        &addr_offset_2,
                                        &draw_layer_params);
                }
                else
                {
                    // left top:
                    drawGetPixelAddress((xx + (roundRadius - 1)) - y_pos,
                                        (yy + (roundRadius - 1)) - x_pos,
                                        &addr_1,
                                        &addr_offset_1,
                                        &draw_layer_params);
                    // left bottom:
                    drawGetPixelAddress((xx + (roundRadius - 1)) - y_pos,
                                        (yy + height + x_pos) - roundRadius,
                                        &addr_2,
                                        &addr_offset_2,
                                        &draw_layer_params);
                }
                /*lint -save -e923 */
                addr_1_ptr = (uint32_t*)addr_1;
                addr_2_ptr = (uint32_t*)addr_2;
                /*lint -restore */

                if(bpp >> 5)
                {
                    *addr_1_ptr = colour_32;
                    *addr_2_ptr = colour_32;
                }
                else
                {
                    colour_mask = ((0x01UL << bpp) - 0x01UL) <<
                                   (0x20UL - (bpp + addr_offset_1));
                    *addr_1_ptr = (*addr_1_ptr & (~colour_mask)) |
                                            (colour_32 & colour_mask);
                    *addr_2_ptr = (*addr_2_ptr & (~colour_mask)) |
                                            (colour_32 & colour_mask);
                }
            }
            alternate--;
        }

        // proceed with the Horn-Algorithm:
        dd = dd + 1 + (int32_t)(y_pos << 1);
        y_pos++;
        if(dd > 0)
        {
            dd = (dd + 2) - (int32_t)(x_pos_horn << 1);
            x_pos_horn = (x_pos_horn == 0) ? 0 : (x_pos_horn - 1);
            x_pos      = (x_pos_horn == 0) ? 0 : (x_pos_horn - 1);
            x_flag     = 1; // x_pos has been decremented in the last iteration
        }
        else
        {
            x_flag = 0; // x_pos is the same as before
        }
    }
    // ********** end of Horn-algorithm ***************


    // ========================= obsolete code ============================

    // step_size = 0x20UL / bpp;
    // colour_mask = (bpp >> 5) ? 0xFFFFFFFFUL : ((0x0001UL << bpp) - 1);
    //
    // while(y_pos < height)
    // {
    //     drawGetPixelAddress(xx, (y_pos + yy),
    //                         &pixel_base_addr, &pixel_bit_offset);
    //     /*lint -save -e923 */
    //     addr = (uint32_t*)pixel_base_addr;
    //     /*lint -restore */
    //     x_pos = 0;
    //
    //     while(x_pos < width)
    //     {
    //         // see if the pixel needs to be processed individually:
    //         if((pixel_bit_offset)
    //         || (x_pos > (width - step_size))
    //         || ((y_pos < roundRadius)
    //             && ((x_pos < roundRadius) ||
    //                 (x_pos > ((width - roundRadius) - step_size))))
    //         || ((y_pos >= (height - roundRadius))
    //             && ((x_pos < roundRadius) ||
    //                 (x_pos > ((width - roundRadius) - step_size)))))
    //         {
    //             // if so, see if it has to be drawn:
    //             if(drawCheckPixel(x_pos, y_pos, width, height,
    //                               roundRadius, step_size, pixel_bit_offset))
    //             {
    //                 data_mask = colour_mask <<
    //                             ((0x20UL - (bpp+pixel_bit_offset)) & 0x001FUL);
    //                 *addr = (*addr & (~data_mask)) |
    //                         (colour <<
    //                           ((0x20UL - (bpp + pixel_bit_offset)) & 0x001FUL));
    //             }
    //             pixel_bit_offset += bpp;
    //             if(pixel_bit_offset >> 5)
    //             {
    //                 pixel_bit_offset = 0;
    //                 addr++;
    //             }
    //             x_pos++;
    //         }
    //         // if not, the pixel will alway be written: process groups of pixels
    //         else
    //         {
    //             if((y_pos < roundRadius) || (y_pos >= (height - roundRadius)))
    //             {
    //                 ii = (step_size > roundRadius) ?
    //                      ((width - x_pos) / step_size) :
    //                      (((width - roundRadius) - x_pos) / step_size);
    //             }
    //             else
    //             {
    //                 ii = (width - x_pos) / step_size;
    //             }
    //             x_pos += ii * step_size;
    //             while(ii--)
    //             {
    //                 *addr++ = colour_32;
    //             }
    //         }
    //     }
    //     y_pos++;
    // }
    // FAPI_SYS_FlushDataCache(draw_layer_params.pictureBase,
    //                        (draw_layer_params.xRes *
    //                         draw_layer_params.yRes *
    //                         draw_layer_params.bpp) >> 3);

    // ======================= end of obsolete code =======================

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Draw an array of rectangles.
**
** \param   layerId Specifies the layer on which will be drawn.
** \param   count   Count of DRAW_AreaT elements in the array.
** \param   rectPtr Array of DRAW_AreaT structures.
** \param   colour  The colour in which the rectangles will appear.
**
** \return
**          - #FAPI_OK on success
**          - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**          - #DRAW_ERR_BAD_PARAMETER if
**            - rectPtr is NULL.
**            - colour uses more bits than the specified layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID The passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
**            opened at the initialization of the OSDHANDLER.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**            if the hardware OSD layer is locked since its virtual group
**            has been started previously. You will need to call
**            OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
**            is bad. Set up the colour mode by OSDHANDLER_SetColourMode.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the requested layer has
**            not been started.
**
*****************************************************************************
*/
/* 21c85998 - complete */
int32_t DRAW_RectangleArray(const uint32_t  layerId,
                            const uint32_t count,
                            DRAW_RectangleT* rectPtr,
                            const uint32_t colour)
{
    uint32_t ii; // temporary counter
    int32_t result; // result from other function calls
    OSDHANDLER_LayerParamsT  draw_layer_params;

    memset(&draw_layer_params, 0, sizeof(draw_layer_params));
    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }
    if(rectPtr == NULL)
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }
    result = OSDHANDLER_GetLayerParameters(layerId, &draw_layer_params);
    if (result != FAPI_OK)
    {
        return(result);
        // may be:
        //- #OSDHANDLER_ERR_BAD_LAYER_ID if an invalid OSD qualifier is given.
        //- #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
        //  opened at initialization.
        //- #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
        //    if the hardware OSD layer is locked since its virtual group
        //    has been started previously. You will need to call
        //    OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
        //- #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
        //  is bad. Set up the colour mode by OSDHANDLER_SetColourMode().
    }
    if(colour >> draw_layer_params.bpp)
    {
        // colour uses too many bits
        return(DRAW_ERR_BAD_PARAMETER);
    }
    ii = count;
    for(ii = 0; ii < count; ii++)
    {
        result = OSDHANDLER_BitBlitFill(layerId,
                                        rectPtr[ii].xPos,
                                        rectPtr[ii].yPos,
                                        rectPtr[ii].width,
                                        rectPtr[ii].height,
                                        colour);

        if(result != FAPI_OK) return(result);
        //  - #OSDHANDLER_ERR_LAYER_NOT_STARTED
        //      if the layer has not been started yet.
        //  - #OSDHANDLER_ERR_OUT_OF_SIZE
        //      if the passed coordinates/dimensions of the rectangle are
        //      out of bounds of the OSD.

    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Parse a bitmap file into a bitmap header file structure.
**          This is useful if you need to access properties of a bitmap
**          file such as resolution, bits per pixel, dpi, etc.
**
** \param   headPtr will get all parameters that are specified within a
**          bitmap file head.
** \param   filePtr should point to the start of a bitmap file.
**
** \return  FAPI_OK on success
*****************************************************************************
*/
/* 21c805ec - complete */
int32_t DRAW_ParseBitmap(DRAW_BmpFileHeadT* headPtr, uint8_t* filePtr)
{
    headPtr->identifier         = drawReadBytes(filePtr + 0x00000000, 2);
    headPtr->fileSize           = drawReadBytes(filePtr + 0x00000002, 4);
    headPtr->reserved           = drawReadBytes(filePtr + 0x00000006, 4);
    headPtr->bitmapDataOffset   = drawReadBytes(filePtr + 0x0000000A, 4);
    headPtr->bitmapHeaderSize   = drawReadBytes(filePtr + 0x0000000E, 4);
    headPtr->width              = drawReadBytes(filePtr + 0x00000012, 4);
    headPtr->height             = drawReadBytes(filePtr + 0x00000016, 4);
    headPtr->planes             = drawReadBytes(filePtr + 0x0000001A, 2);
    headPtr->bitsPerPixel       = drawReadBytes(filePtr + 0x0000001C, 2);
    headPtr->compression        = drawReadBytes(filePtr + 0x0000001E, 4);
    headPtr->bitmapDataSize     = drawReadBytes(filePtr + 0x00000022, 4);
    headPtr->hResolution        = drawReadBytes(filePtr + 0x00000026, 4);
    headPtr->vResolution        = drawReadBytes(filePtr + 0x0000002A, 4);
    headPtr->colours            = drawReadBytes(filePtr + 0x0000002E, 4);
    headPtr->importantColours   = drawReadBytes(filePtr + 0x00000032, 4);
    headPtr->palettePtr         = filePtr + 0x00000036;
    headPtr->bitmapDataPtr      = filePtr + headPtr->bitmapDataOffset;

    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Draws a win bitmap at given coordinates relative to the origin
**          of the OSD/CP layer.
**
** \param   layerId
**              specifies on which layer the bitmap has to be drawn.
**              Pass 1 or 2 for OSD1 or OSD2 respectively and 3 for the CP.
** \param   xx
**              the x coordinate on the layer where the picture will be drawn.
** \param   yy
**              the y coordinate on the layer where the picture will be drawn.
** \param   mode
**              Determines whether to set up the colour lookup table (CLUT)
**              that is provided by the bitmap file in the OSD. Possible values
**              are:
**              - DRAW_SET_UP_CLUT sets the whole CLUT of the OSD
**              - DRAW_DO_NOT_SET_UP_CLUT leaves the CLUT unmodified
**              This setting does only affect 1-bit, 4-bit and 8-bit bitmap
**              files since 16-bit, 24-bit and 32-bit modes are true colour
**              modes and do not need a CLUT.
** \param   bmpPtr
**              points to the bitmap file.
** \param   errorCodePtr
**              Will receive error codes that may occur when calling underlying
**              drivers (OSDHANDLER calls VISCALE driver). The error code is
**              is formatted as described in the documentation of the OSDHANDLER.
**              If no errors occur, it will equal FAPI_OK. Argument is optional,
**              may be NULL.
**
** \return
**        - #FAPI_OK on success.
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**        - #OSDHANDLER_ERR_BAD_LAYER_ID The passed layerId is invalid.
**        - #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
**          opened at the initialization of the OSDHANDLER.
**        - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**          if the hardware OSD layer is locked since its virtual group
**          has been started previously. You will need to call
**          OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**        - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
**          is bad. Set up the colour mode by OSDHANDLER_SetColourMode.
**        - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the requested layer has
**          not been started.
**        - #DRAW_ERR_BAD_PARAMETER
**          - A bad mode is passed.
**          - The bmpPtr argument is NULL.
**        - #DRAW_ERR_OUT_OF_OSD_SIZE if the picture does not fit into the
**          the OSD/CP plane due to its dimensions and/or its position on the
**          OSD/CP.
**        - #DRAW_ERR_WRONG_COLOUR_MODE if the colour mode of the bitmap does
**          not fit for the colour mode that the OSD/CP is running. Both colour
**          modes need to have the same amount of bits per pixel! The only
**          exclusion is the OSDHANDLER_OSD_MODE_TRU_COLOUR_32BIT_24BIT
**          that is valid for both 24-bit and 32-bit bitmaps.
**        - #DRAW_ERR_WRONG_LAYOUT_MODE if the OSDHANDLER_OsdLayoutEnumT mode
**          that the OSD/CP is running is not supported for drawing bitmap
**          files. Run the OSD/CP in OSDHANDLER_OSD_LAYOUT_ARGB or in
**          OSDHANDLER_OSD_LAYOUT_CbYCrA mode.
**        - #DRAW_ERR_BITMAP_NOT_SUPPORTED if the bitmap file is not supported.
**          This driver supports uncompressed win bitmap files in all
**          possible bit depths.
**
** \note    Lint error 923 temporarily disabled (13 calls) within function.
**          Casts from type to type are mandatory here for pointer
**          arithmetics.
**
** \attention   If you draw the bitmap file on an OSD/CP that is running in
**              OSDHANDLER_OSD_LAYOUT_ARGB mode, it will be displayed much
**              faster than in the OSDHANDLER_OSD_LAYOUT_CbYCrA mode since the
**              RGB mode does not need any colour conversions. <br><br>
**              For 4-bit and 1-bit bitmaps you can enhance the performance
**              of the driver by drawing the bitmap at a xx position
**              with a certain alignment:
**              - For 4-bit bitmaps choose xx as an even number in order to
**                enhance speed.
**              - For 1-bit bitmaps chooose xx as a multiple of 8 in order to
**              enhance speed.
**
**              If you do not keep the suggested alignments, the bitmap will be
**              drawn pixel accurate but with much less performance.
**
** \sa
**          - DRAW_Fbm()
**
*****************************************************************************
*/
/* 21c84a80 - todo */
int32_t DRAW_Bitmap(const uint32_t  layerId,
                    const uint32_t  xx,
                    const uint32_t  yy,
                    const DRAW_ModeEnumT mode,
                    uint8_t* bmpPtr,
                    uint32_t* errorCodePtr)
{
    OSDHANDLER_LayerParamsT  draw_layer_params;
    DRAW_BmpFileHeadT   bmp_head;
    int32_t             result              = 0;
    uint32_t            tmpErrorCode        = 0;
    uint32_t            ii                  = 0;
    uint32_t            line                = 0;
    uint32_t            colour_mask         = 0x00000000UL;
    uint32_t            data_mask           = 0x00000000UL;
    uint32_t            pixel_base_addr     = 0;
    uint32_t            pixel_bit_offset    = 0;
    uint32_t            copy_steps          = 0;
    uint32_t            copy_rest           = 0;
    uint32_t*           osd_word_ptr        = NULL;
    uint8_t*            bmp_byte_ptr        = NULL;
    uint32_t            align_rest;
    uint32_t            bmp_clut_array[256];

    memset(&bmp_head, 0, sizeof(bmp_head));
    memset(&draw_layer_params, 0, sizeof(draw_layer_params));
    if(errorCodePtr) *errorCodePtr = FAPI_OK;

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }
    if(bmpPtr == NULL)
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }
    result = OSDHANDLER_GetLayerParameters(layerId, &draw_layer_params);
    if (result != FAPI_OK)
    {
        return(result);
        // may be:
        //- #OSDHANDLER_ERR_BAD_LAYER_ID if an invalid OSD qualifier is given
        //- #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
        //  opened at initialization
        //- #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
        //  is bad. Set up the colour mode by OSDHANDLER_SetColourMode
    }
    (void)DRAW_ParseBitmap(&bmp_head, bmpPtr);

    if(draw_layer_params.pictureBase == 0)
    {
        return(OSDHANDLER_ERR_LAYER_NOT_STARTED);
    }
    if(!((mode == DRAW_SET_UP_CLUT) || (mode == DRAW_DO_NOT_SET_UP_CLUT)))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    if(((xx + bmp_head.width)  > draw_layer_params.xRes)
     ||((yy + bmp_head.height) > draw_layer_params.yRes))
    {
        return(DRAW_ERR_OUT_OF_OSD_SIZE);
    }

    if(!
         (((bmp_head.bitsPerPixel ==  1) && (draw_layer_params.bpp ==  1))
        ||((bmp_head.bitsPerPixel ==  2) && (draw_layer_params.bpp ==  2))
        ||((bmp_head.bitsPerPixel ==  4) && (draw_layer_params.bpp ==  4))
        ||((bmp_head.bitsPerPixel ==  8) && (draw_layer_params.bpp ==  8))
        ||((bmp_head.bitsPerPixel == 16) && (draw_layer_params.bpp == 16))
        ||((bmp_head.bitsPerPixel == 24) && (draw_layer_params.bpp == 32))
        ||((bmp_head.bitsPerPixel == 32) && (draw_layer_params.bpp == 32))
         )
      )
    {
        return(DRAW_ERR_WRONG_COLOUR_MODE);
    }

    if(!
        ((draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
       ||(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA))
      )
    {
        return(DRAW_ERR_WRONG_LAYOUT_MODE);
    }

    if((bmp_head.identifier != 0x00004D42UL)
    || (bmp_head.compression))
    {
        return(DRAW_ERR_BITMAP_NOT_SUPPORTED);
    }

    line = 0;
    bmp_byte_ptr = bmp_head.bitmapDataPtr;

    // ***************************
    // draw the bitmap on the OSD:
    // ***************************

    // ***************************
    // process 32-bit bitmap:
    // ***************************
    if(bmp_head.bitsPerPixel == 32)
    {
        while(line < bmp_head.height)
        {
            drawGetPixelAddress( xx,
                                 (yy + bmp_head.height) - (line + 1),
                                 &pixel_base_addr,
                                 &pixel_bit_offset,
                                 &draw_layer_params );
            /*lint -save -e923 */
            osd_word_ptr = (uint32_t*)pixel_base_addr;
            /*lint -restore */
            copy_steps = bmp_head.width;

            if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                // simply copy the pixels:
                while(copy_steps--)
                {
                    *osd_word_ptr++ = drawReadBytes(bmp_byte_ptr, 4);
                    bmp_byte_ptr += 4;
                }
            }
            else if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                // transform colours for each pixel:
                while(copy_steps--)
                {
                    *osd_word_ptr++ = OSDHANDLER_ConvertARGB2CbYCrA_word
                                               (drawReadBytes(bmp_byte_ptr, 4));
                    bmp_byte_ptr += 4;
                }
            }

            // align to next line:
            align_rest = ((uint32_t)bmp_byte_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                bmp_byte_ptr += 4 - align_rest;
            }
            /*lint -restore */
            line++;
        }
    }

    // ***************************
    // process 24-bit bitmap:
    // ***************************
    else if(bmp_head.bitsPerPixel == 24)
    {
        while(line < bmp_head.height)
        {
            drawGetPixelAddress( xx,
                                 (yy + bmp_head.height) - (line + 1),
                                 &pixel_base_addr,
                                 &pixel_bit_offset,
                                 &draw_layer_params );
            /*lint -save -e923 */
            osd_word_ptr = (uint32_t*)pixel_base_addr;
            /*lint -restore */
            copy_steps = bmp_head.width;

            if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                // simply copy the pixels:
                while(copy_steps--)
                {
                    *osd_word_ptr++ = (drawReadBytes(bmp_byte_ptr, 3) |
                                       0xFF000000UL);
                    bmp_byte_ptr += 3;
                }
            }
            else if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                // transform colours for each pixel:
                while(copy_steps--)
                {
                    *osd_word_ptr++ = OSDHANDLER_ConvertARGB2CbYCrA_word
                                (drawReadBytes(bmp_byte_ptr, 3) | 0xFF000000UL);
                    bmp_byte_ptr += 3;
                }
            }

            // align to next line:
            align_rest = ((uint32_t)bmp_byte_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                bmp_byte_ptr += 4 - align_rest;
            }
            /*lint -restore */
            line++;
        }
    }

    // ***************************
    // process 16-bit bitmap:
    // ***************************
    else if(bmp_head.bitsPerPixel == 16)
    {
        while(line < bmp_head.height)
        {
            drawGetPixelAddress( xx,
                                 (yy + bmp_head.height) - (line + 1),
                                 &pixel_base_addr,
                                 &pixel_bit_offset,
                                 &draw_layer_params );
            /*lint -save -e923 */
            osd_word_ptr = (uint32_t*)pixel_base_addr;
            /*lint -restore */
            copy_steps = bmp_head.width;


            if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                // simply copy the pixels:

                copy_rest = copy_steps % 2;
                copy_steps >>= 1;

                while(copy_steps--)
                {
                    ii  = (uint32_t)*bmp_byte_ptr++ << 16;
                    ii |= (uint32_t)*bmp_byte_ptr++ << 24;
                    ii |= (uint32_t)*bmp_byte_ptr++ <<  0;
                    ii |= (uint32_t)*bmp_byte_ptr++ <<  8;
                    *osd_word_ptr++ = ii;
                }

                if(copy_rest)
                {
                    ii  = ((uint32_t)*bmp_byte_ptr++) << 16;
                    ii |= ((uint32_t)*bmp_byte_ptr++) << 24;
                    *osd_word_ptr = (*osd_word_ptr & 0x0000FFFFUL) | ii;
                }
            }
            else if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                // transform colours for each pixel:

                copy_rest = copy_steps % 2;
                copy_steps >>= 1;

                while(copy_steps--)
                {
                    ii = (uint32_t)(OSDHANDLER_ConvertARGB2CbYCrA_5551
                                (((uint32_t)*bmp_byte_ptr) |
                                (((uint32_t)*(bmp_byte_ptr+1)) << 8))) << 16;
                    bmp_byte_ptr += 2;
                    ii |= (uint32_t)OSDHANDLER_ConvertARGB2CbYCrA_5551
                                (((uint32_t)*bmp_byte_ptr) |
                                (((uint32_t)*(bmp_byte_ptr+1)) << 8));
                    bmp_byte_ptr += 2;
                    *osd_word_ptr++ = ii;
                }

                if(copy_rest)
                {
                    ii  = (uint32_t)OSDHANDLER_ConvertARGB2CbYCrA_5551
                                (((uint32_t)*bmp_byte_ptr) |
                                (((uint32_t)*(bmp_byte_ptr+1)) << 8)) << 16;
                    bmp_byte_ptr += 2;
                    *osd_word_ptr = (*osd_word_ptr & 0x0000FFFFUL) | ii;
                }
            }

            // align to next line:
            align_rest = ((uint32_t)bmp_byte_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                bmp_byte_ptr += 4 - align_rest;
            }
            /*lint -restore */
            line++;
        }
    }

    // ***************************
    // process 8-bit bitmap:
    // ***************************
    else if(bmp_head.bitsPerPixel == 8)
    {
        colour_mask = 0x000000FFUL;

        if(mode == DRAW_SET_UP_CLUT)
        {
            // set up the colour lookup table:
            memset(bmp_clut_array, 0, sizeof(bmp_clut_array));
            // bmp_byte_ptr is used for traversing the colour palette here:
            bmp_byte_ptr = bmp_head.palettePtr;
            if(bmp_head.colours == 0) bmp_head.colours = 0x0100UL;
            if(bmp_head.colours > 0x0100UL) bmp_head.colours = 0x0100UL;

            if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                for(line = 0; line < bmp_head.colours; line++)
                {
                    bmp_clut_array[line] = drawReadBytes(bmp_byte_ptr, 4);
                    bmp_byte_ptr += 4;
                }
            }
            else if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                for(line = 0; line < bmp_head.colours; line++)
                {
                    bmp_clut_array[line] = OSDHANDLER_ConvertARGB2CbYCrA_word
                                               (drawReadBytes(bmp_byte_ptr, 4));
                    bmp_byte_ptr += 4;
                }
            }
            // possible errors already checked above:
            (void)OSDHANDLER_SetClut(layerId, bmp_clut_array, &tmpErrorCode);
            if(errorCodePtr) *errorCodePtr |= tmpErrorCode;
        }

        line = 0;
        bmp_byte_ptr = bmp_head.bitmapDataPtr;

        // draw the picture:
        while(line < bmp_head.height)
        {
            drawGetPixelAddress( xx,
                                 (yy + bmp_head.height) - (line + 1),
                                 &pixel_base_addr,
                                 &pixel_bit_offset,
                                 &draw_layer_params );

            /*lint -save -e923 */
            osd_word_ptr = (uint32_t*) pixel_base_addr;
            /*lint -restore */

            copy_steps = bmp_head.width;

            // easiest way but least performance:
            //while(copy_steps--)
            //{
            //    data_mask = colour_mask <<
            //                    (0x0020UL - (pixel_bit_offset + 8));
            //    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
            //                    ((uint32_t)*bmp_byte_ptr++ <<
            //                        (0x0020UL - (pixel_bit_offset + 8)));
            //    pixel_bit_offset += 8;
            //    if(pixel_bit_offset >> 5)
            //    {
            //        pixel_bit_offset = 0;
            //        osd_word_ptr++;
            //    }
            //}

            if(pixel_bit_offset)
            {
                for(ii = (0x20UL - pixel_bit_offset) >> 3; ii > 0; ii--)
                {
                    data_mask = colour_mask <<
                                    ((0x0018UL - pixel_bit_offset) & 0x001FUL);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((uint32_t)*bmp_byte_ptr++ <<
                                    ((0x0018UL - pixel_bit_offset) & 0x001FUL));
                    pixel_bit_offset += 8;
                    copy_steps--;
                }
                osd_word_ptr++;
                pixel_bit_offset = 0;
            }

            // now copy 4byte-wise
            copy_rest = copy_steps % 4;
            copy_steps >>= 2;
            while(copy_steps--)
            {
                ii  = (uint32_t)*bmp_byte_ptr++ << 24;
                ii |= (uint32_t)*bmp_byte_ptr++ << 16;
                ii |= (uint32_t)*bmp_byte_ptr++ <<  8;
                ii |= (uint32_t)*bmp_byte_ptr++;
                *osd_word_ptr++ = ii;
            }

            if(copy_rest)
            {
                while(copy_rest--)
                {
                    data_mask = colour_mask << (0x0018UL - pixel_bit_offset);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((uint32_t)*bmp_byte_ptr++ <<
                                        (0x0018UL - pixel_bit_offset));
                    pixel_bit_offset += 8;
                }
            }

            // align to next line:
            align_rest = ((uint32_t)bmp_byte_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                bmp_byte_ptr += 4 - align_rest;
            }
            /*lint -restore */
            line++;
        }
    }

    // ***************************
    // process 4-bit bitmap:
    // ***************************
    else if(bmp_head.bitsPerPixel == 4)
    {
        if(mode == DRAW_SET_UP_CLUT)
        {
            // set up the colour lookup table:
            memset(bmp_clut_array, 0, sizeof(bmp_clut_array));
            // bmp_byte_ptr is used for traversing the colour palette here:
            bmp_byte_ptr = bmp_head.palettePtr;
            if(bmp_head.colours == 0) bmp_head.colours = 0x0010UL;
            if(bmp_head.colours > 0x0100UL) bmp_head.colours = 0x0100UL;

            if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                for(line = 0; line < bmp_head.colours; line++)
                {
                    bmp_clut_array[line] = drawReadBytes(bmp_byte_ptr, 4);
                    bmp_byte_ptr += 4;
                }
            }
            else if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                for(line = 0; line < bmp_head.colours; line++)
                {
                    bmp_clut_array[line] = OSDHANDLER_ConvertARGB2CbYCrA_word
                                               (drawReadBytes(bmp_byte_ptr, 4));
                    bmp_byte_ptr += 4;
                }
            }
            (void)OSDHANDLER_SetClut(layerId, bmp_clut_array, &tmpErrorCode);
            if(errorCodePtr) *errorCodePtr |= tmpErrorCode;
        }

        line = 0;
        bmp_byte_ptr = bmp_head.bitmapDataPtr;

        // draw the picture:
        while(line < bmp_head.height)
        {
            drawGetPixelAddress( xx,
                                 (yy + bmp_head.height) - (line + 1),
                                 &pixel_base_addr,
                                 &pixel_bit_offset,
                                 &draw_layer_params );

            /*lint -save -e923 */
            osd_word_ptr = (uint32_t*) pixel_base_addr;
            /*lint -restore */

            copy_steps = bmp_head.width;

            if(pixel_bit_offset % 8)
            {
                // this mode is entered if the x position of the bitmap is odd:
                // ATTENTION: pixel accurate algorithm but low performance!

                // ii serves as a flag that decides whether to read the upper or
                // the lower 4 bits of a byte from the bitmap file:
                ii = 1;
                colour_mask = 0x0000000FUL;

                while(copy_steps)
                {
                    data_mask = colour_mask <<
                                    ((0x001CUL - pixel_bit_offset) & 0x001FUL);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((ii ?
                                     ((*bmp_byte_ptr & 0xF0UL) >> 4):
                                     (*bmp_byte_ptr++ & 0x0FUL)) <<
                                     ((0x001CUL - pixel_bit_offset) & 0x001FUL));
                    ii = !ii;
                    pixel_bit_offset += 4;
                    if(pixel_bit_offset >> 5)
                    {
                        pixel_bit_offset = 0;
                        osd_word_ptr++;
                    }
                    copy_steps--;
                }
                if(!ii)
                {
                    bmp_byte_ptr++;
                }
            }
            else
            {
                // high performance algorithm for even x positions of the bmp:

                colour_mask = 0x000000FFUL;

                // write the first bytes:
                while((pixel_bit_offset) && (copy_steps >> 1))
                {
                    data_mask = colour_mask << (0x0018UL - pixel_bit_offset);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((uint32_t)*bmp_byte_ptr++ <<
                                        (0x0018UL - pixel_bit_offset));
                    pixel_bit_offset += 8;
                    copy_steps -= 2;
                    if(pixel_bit_offset >> 5)
                    {
                        pixel_bit_offset = 0;
                        osd_word_ptr++;
                    }
                }

                // now copy 4-byte-wise:
                copy_rest = copy_steps % 8;
                copy_steps >>= 3;
                while(copy_steps--)
                {
                    ii  = (uint32_t)*bmp_byte_ptr++ << 24;
                    ii |= (uint32_t)*bmp_byte_ptr++ << 16;
                    ii |= (uint32_t)*bmp_byte_ptr++ <<  8;
                    ii |= (uint32_t)*bmp_byte_ptr++;
                    *osd_word_ptr++ = ii;
                }

                copy_steps = copy_rest >> 1;
                copy_rest %= 2;

                // copy the remaining bytes:

                while(copy_steps)
                {
                    data_mask = colour_mask <<
                                    ((0x0018UL - pixel_bit_offset) & 0x001FUL);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((uint32_t)*bmp_byte_ptr++ <<
                                    ((0x0018UL - pixel_bit_offset) & 0x001FUL));
                    pixel_bit_offset += 8;
                    copy_steps--;
                }

                // if the horizontal resolution is uneven, write the last pixel:
                if(copy_rest)
                {
                    colour_mask = 0x0000000FUL;
                    data_mask = colour_mask <<
                                    ((0x001CUL - pixel_bit_offset) & 0x001FUL);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    (((*bmp_byte_ptr++ & 0x00F0UL) >> 4) <<
                                    ((0x001CUL - pixel_bit_offset) & 0x001FUL));
                }
            }

            // align to next line:
            align_rest = ((uint32_t)bmp_byte_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                bmp_byte_ptr += 4 - align_rest;
            }
            /*lint -restore */
            line++;
        }
    }

    // ***************************
    // process 1-bit bitmap:
    // ***************************
    else if(bmp_head.bitsPerPixel == 1)
    {
        if(mode == DRAW_SET_UP_CLUT)
        {
            // set up the colour lookup table:
            memset(bmp_clut_array, 0, sizeof(bmp_clut_array));
            // bmp_byte_ptr is used for traversing the colour palette here:
            bmp_byte_ptr = bmp_head.palettePtr;
            if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                for(line = 0; line < 2; line++)
                {
                    bmp_clut_array[line]  = drawReadBytes(bmp_byte_ptr, 4);
                    bmp_clut_array[line] |= 0xFF000000UL;
                    bmp_byte_ptr += 4;
                }
            }
            else if(draw_layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                for(line = 0; line < 2; line++)
                {
                    bmp_clut_array[line] = OSDHANDLER_ConvertARGB2CbYCrA_word
                                               (drawReadBytes(bmp_byte_ptr, 4));
                    bmp_clut_array[line] |= 0x000000FFUL;
                    bmp_byte_ptr += 4;
                }
            }
            (void)OSDHANDLER_SetClut(layerId, bmp_clut_array, &tmpErrorCode);
            if(errorCodePtr) *errorCodePtr |= tmpErrorCode;
        }

        line = 0;
        bmp_byte_ptr = bmp_head.bitmapDataPtr;

        // draw the picture:
        while(line < bmp_head.height)
        {
            drawGetPixelAddress( xx,
                                 (yy + bmp_head.height) - (line + 1),
                                 &pixel_base_addr,
                                 &pixel_bit_offset,
                                 &draw_layer_params );

            /*lint -save -e923 */
            osd_word_ptr = (uint32_t*) pixel_base_addr;
            /*lint -restore */

            copy_steps = bmp_head.width;

            if(pixel_bit_offset % 8)
            {
                /* this mode is entered if the x position of the bitmap is
                ** not a multiple of 8. Therefore there is a misalignment
                ** of the data in the bitmap file in reference to the OSD
                ** plane and the single pixels need to be shifted.
                ** ATTENTION: low performance!
                */

                ii = 7;
                data_mask = 0x0001UL << (0x001FUL - pixel_bit_offset);
                while(copy_steps)
                {
                    if(*bmp_byte_ptr & (0x01UL << ii))
                    {
                        *osd_word_ptr |= data_mask;
                    }
                    else
                    {
                        *osd_word_ptr &= (~data_mask);
                    }
                    if (ii == 0)
                    {
                        ii = 7;
                        bmp_byte_ptr++;
                    }
                    else
                    {
                        ii--;
                    }
                    pixel_bit_offset++;
                    data_mask >>= 1;
                    if(pixel_bit_offset >> 5)
                    {
                        pixel_bit_offset = 0;
                        data_mask = 0x80000000UL;
                        osd_word_ptr++;
                    }
                    copy_steps--;
                }
                if(ii != 7)
                {
                    bmp_byte_ptr++;
                }
            }
            else
            {
                // high performance algorithm for xx = a multiple of 8

                colour_mask = 0x000000FFUL;

                // write the first bytes:
                while((pixel_bit_offset) && (copy_steps >> 3))
                {
                    data_mask = colour_mask << (0x0018UL - pixel_bit_offset);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((uint32_t)*bmp_byte_ptr++ <<
                                        (0x0018UL - pixel_bit_offset));
                    pixel_bit_offset += 8;
                    copy_steps -= 8;
                    if(pixel_bit_offset >> 5)
                    {
                        pixel_bit_offset = 0;
                        osd_word_ptr++;
                    }
                }

                // now copy 4-byte-wise:
                copy_rest = copy_steps % 32;
                copy_steps >>= 5;
                while(copy_steps--)
                {
                    ii  = (uint32_t)*bmp_byte_ptr++ << 24;
                    ii |= (uint32_t)*bmp_byte_ptr++ << 16;
                    ii |= (uint32_t)*bmp_byte_ptr++ <<  8;
                    ii |= (uint32_t)*bmp_byte_ptr++;
                    *osd_word_ptr++ = ii;
                }

                copy_steps = copy_rest >> 3;
                copy_rest %= 8;

                // copy the remaining bytes:

                while(copy_steps)
                {
                    data_mask = colour_mask <<
                                    ((0x0018UL - pixel_bit_offset) & 0x001FUL);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((uint32_t)*bmp_byte_ptr++ <<
                                    ((0x0018UL - pixel_bit_offset) & 0x001FUL));
                    pixel_bit_offset += 8;
                    copy_steps--;
                }

                // copy the last pixels if any
                if(copy_rest)
                {
                    colour_mask = (0x0001UL << copy_rest) - 0x0001UL;
                    data_mask = colour_mask <<
                                ((0x0020UL - (pixel_bit_offset + copy_rest))
                                & 0x001FUL);
                    *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    (
                                     ((uint32_t)*bmp_byte_ptr++ >>
                                                (8 - copy_rest)) <<
                                     (((0x0020UL -
                                       (pixel_bit_offset + copy_rest)))
                                      & 0x001FUL)
                                    );
                }
            }
            // align to next line:
            align_rest = ((uint32_t)bmp_byte_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                bmp_byte_ptr += 4 - align_rest;
            }
            /*lint -restore */
            line++;
        }
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Detects the type of a picture file.
**
** \param   typePtr
**              Will receive information about the picture file type.
** \param   filePtr
**              Points to the file whose type will be detected.
**
** \return  - FAPI_OK on success.
**          - DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**          - DRAW_ERR_BAD_PARAMETER if one or both passed pointers are NULL.
**          - DRAW_ERR_UNKNOWN_FILE_TYPE if the type of filePtr
**              is not supported.
*****************************************************************************
*/
/* 21c80704 - complete */
int32_t DRAW_DetectFile(DRAW_PictureFileTypeT* typePtr, uint8_t* filePtr)
{
    uint32_t identifier = 0;
    uint8_t* workPtr = filePtr;

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }
    if((typePtr == NULL) || (filePtr == NULL))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    // check for bitmap files:
    identifier = drawReadBytes(workPtr, 2);
    if(identifier == 0x00004D42UL)
    {
        *typePtr = DRAW_PIC_FILE_TYPE_BMP;
        return(FAPI_OK);
    }

    // check for Fujitsu bitmap files:
    workPtr = filePtr;
    identifier = drawReadBytes(workPtr, 4);
    if((identifier == 0x00010000UL)
    || (identifier == 0x00010001UL)
    || (identifier == 0x00010002UL)
    || (identifier == 0x00010003UL)
    || (identifier == 0x00010009UL)
    || (identifier == 0x0001000AUL)
    || (identifier == 0x0001000BUL))
    {
        *typePtr = DRAW_PIC_FILE_TYPE_FBM;
        return(FAPI_OK);
    }

    // check for dat (old Fujitsu format) files:
    workPtr = filePtr;
    identifier = drawReadBytes(workPtr, 4);
    if((identifier == 0x00000000UL)
    || (identifier == 0x00000001UL)
    || (identifier == 0x00000002UL)
    || (identifier == 0x00000003UL)
    || (identifier == 0x0000000AUL)
    || (identifier == 0x0000000BUL))
    {
        *typePtr = DRAW_PIC_FILE_TYPE_DAT;
        return(FAPI_OK);
    }

#if DRAW_ENABLE_PNG == 1
    // check for PNG files:
    workPtr = filePtr;
    identifier = drawReadBytes(workPtr, 4);
    if(identifier == 0x474E5089UL)
    {
        *typePtr = DRAW_PIC_FILE_TYPE_PNG;
        return(FAPI_OK);
    }
#endif

    *typePtr = DRAW_PIC_FILE_TYPE_UNKNOWN;
    return(DRAW_ERR_UNKNOWN_FILE_TYPE);
}

/*!
*****************************************************************************
** \brief   Read a raw Fujitsu DAT bitmap file and store it locally
**          as a DRAW_PicItemT.
**
** \note    If picItemPtr->fbmHeaderPtr or picItemPtr->dataPtr or
**          picItemPtr->clutPtr equals NULL, memory will be allocated
**          automatically. You have to deallocate this memory when the
**          picture is not needed any more by calling DRAW_FreeFbm().
**          For the clutPtr, memory will be allocated in case of 8-bit, 4-bit
**          and 1-bit pictures only.
**
** \param filePtr
**              Points to the raw Fujitsu DAT file data.
** \param picItemPtr
**              Points to a structure that will receive the picture data.
** \return
**        - #FAPI_OK on success
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized
**        - #DRAW_ERR_BAD_PARAMETER if one of the pointer arguments is NULL.
**        - #DRAW_ERR_OUT_OF_MEMORY if there was not enough memory for
**          allocation.
**        - #DRAW_ERR_UNKNOWN_FILE_TYPE if the colour mode of the file is
**          unknown.
**
** \sa
**          - DRAW_ReadFile_BMP()
**          - DRAW_ReadFile_FBM()
**          - DRAW_ReadFile_PNG()
**          - DRAW_FreeFbm()
**
*****************************************************************************
*/
/* 21c84878 - complete */
int32_t DRAW_ReadFile_DAT(uint32_t* filePtr, DRAW_PicItemT* picItemPtr)
{
    uint32_t* src32_ptr     = NULL;
    uint32_t* dst32_ptr     = NULL;
    uint8_t*  src8_ptr      = NULL;
    uint8_t*  dst8_ptr      = NULL;
    uint32_t  tmp           = 0; // temporary counter
    uint32_t  tempVal       = 0; // temporary usage for colour conversion
    uint32_t  bpp           = 0; // bits per pixel

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }

    if((filePtr == NULL) || (picItemPtr == NULL))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    // reset dynamic allocation information:
    picItemPtr->allocInformation = 0x0000;

    // allocate memory for FBM header if needed
    if(picItemPtr->fbmHeaderPtr == NULL)
    {
        picItemPtr->fbmHeaderPtr = FAPI_SYS_MALLOC(sizeof(DRAW_FbmHeaderT));
        if(picItemPtr->fbmHeaderPtr == NULL)
        {
            DRAW_FreeFbm(picItemPtr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        picItemPtr->allocInformation |= 0x0001;
    }

    // Get the colour mode and indicate the converted colour space:
    src32_ptr = filePtr;
    tmp = *src32_ptr++ + 0x00010000UL;
    bpp = drawExtractBitDepth((DRAW_ColourModeEnumT)tmp);
    if(bpp == 0)
    {
        return(DRAW_ERR_UNKNOWN_FILE_TYPE);
    }
    picItemPtr->fbmHeaderPtr->colourMode = (DRAW_ColourModeEnumT)tmp;

    // Get the dimensions:
    picItemPtr->fbmHeaderPtr->width  = *src32_ptr++;
    picItemPtr->fbmHeaderPtr->height = *src32_ptr++;

    // count of bytes per line:
    tmp = picItemPtr->fbmHeaderPtr->width * bpp;    // bits per line
    tmp = (tmp % 8) ? ((tmp / 8) + 1) : (tmp / 8);  // bytes per line

    // bitmap size in bytes:
    tmp = tmp * picItemPtr->fbmHeaderPtr->height;

    // allocate memory if needed
    if(picItemPtr->dataPtr == NULL)
    {
        picItemPtr->dataPtr = FAPI_SYS_MALLOC(tmp);
        if(picItemPtr->dataPtr == NULL)
        {
            DRAW_FreeFbm(picItemPtr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        picItemPtr->allocInformation |= 0x0002;
    }

    if(bpp == 32)
    {
        dst32_ptr = picItemPtr->dataPtr;
        tmp = picItemPtr->fbmHeaderPtr->width *
              picItemPtr->fbmHeaderPtr->height;
        while(tmp--)
        {
            *dst32_ptr++ = OSDHANDLER_ConvertCbYCrA2RGBA_word(*src32_ptr++);
        }
    }
    else if(bpp == 24)
    {
        dst8_ptr = (uint8_t*)picItemPtr->dataPtr;
        src8_ptr = (uint8_t*)src32_ptr;
        tmp = picItemPtr->fbmHeaderPtr->width *
              picItemPtr->fbmHeaderPtr->height;
        while(tmp--)
        {
            tempVal = OSDHANDLER_ConvertCbYCrA2RGBA_word(
                        ((drawReadBytes(src8_ptr, 3) << 8) | 0x000000FFUL));
            *dst8_ptr++ = (tempVal & 0x0000FF00UL) >> 8;
            *dst8_ptr++ = (tempVal & 0x00FF0000UL) >> 16;
            *dst8_ptr++ = (tempVal & 0xFF000000UL) >> 24;
        }
    }
    else
    {
        // for CLUT modes just copy the CLUT reference entries:
        memcpy(picItemPtr->dataPtr, src32_ptr, tmp);
    }

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Read a raw Win bitmap bitmap file (bmp) and store it locally
**          as a DRAW_PicItemT.
**
** \note    If picItemPtr->fbmHeaderPtr or picItemPtr->dataPtr or
**          picItemPtr->clutPtr equals NULL, memory will be allocated
**          automatically. You have to deallocate this memory when the
**          picture is not needed any more by calling DRAW_FreeFbm().
**          For the clutPtr, memory will be allocated in case of 8-bit, 4-bit
**          and 1-bit pictures only.
**
** \param filePtr
**              Points to the raw bitmap (bmp) data.
** \param picItemPtr
**              Points to a structure that will receive the picture data.
**
** \return
**        - #FAPI_OK on success
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized
**        - #DRAW_ERR_BAD_PARAMETER if one of the pointer arguments is NULL.
**        - #DRAW_ERR_BITMAP_NOT_SUPPORTED if the passed filePtr points
**          to a file that is not supported by the driver.
**        - #DRAW_ERR_OUT_OF_MEMORY if there was not enough memory available
**          for allocation in order to store the transcoded FBM picture file.
**
** \sa
**          - DRAW_ReadFile_FBM()
**          - DRAW_ReadFile_DAT()
**          - DRAW_ReadFile_PNG()
**          - DRAW_FreeFbm()
**
*****************************************************************************
*/
/* 21c808b4 - todo */
int32_t DRAW_ReadFile_BMP(uint32_t* filePtr, DRAW_PicItemT* picItemPtr)
{
    DRAW_ColourModeEnumT colour_mode    = (DRAW_ColourModeEnumT)0;
    uint32_t  tmp                       = 0; // temporary usages
    uint16_t  tmp16                     = 0; // temporary 16-bit word
    uint32_t  line_counter              = 0; // counter for lines in the FBM
    uint32_t  line_length               = 0; // line length of FBM in bytes
    uint8_t*  src8_ptr                  = NULL;
    uint8_t*  dst8_ptr                  = NULL;
    uint16_t* dst16_ptr                 = NULL;
    uint32_t* dst32_ptr                 = NULL;
    DRAW_BmpFileHeadT   bmp_head;
    uint32_t            align_rest;

    memset(&bmp_head, 0, sizeof(bmp_head));

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }

    if((filePtr == NULL) || (picItemPtr == NULL))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    // reset dynamic allocation information:
    picItemPtr->allocInformation = 0x0000;

    // allocate memory for FBM header if needed
    if(picItemPtr->fbmHeaderPtr == NULL)
    {
        picItemPtr->fbmHeaderPtr = FAPI_SYS_MALLOC(sizeof(DRAW_FbmHeaderT));
        if(picItemPtr->fbmHeaderPtr == NULL)
        {
            DRAW_FreeFbm(picItemPtr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        picItemPtr->allocInformation |= 0x0001;
    }

    // Retrieve bitmap information:
    (void)DRAW_ParseBitmap(&bmp_head, (uint8_t*)filePtr);

    if((bmp_head.identifier != 0x00004D42UL)
    || (bmp_head.compression))
    {
        return(DRAW_ERR_BITMAP_NOT_SUPPORTED);
    }

    // Get the colour mode:
    switch(bmp_head.bitsPerPixel)
    {
        case(1):
            colour_mode = DRAW_COLOURMODE_1BIT_RGB;
            break;
        case(4):
            colour_mode = DRAW_COLOURMODE_4BIT_RGB;
            break;
        case(8):
            colour_mode = DRAW_COLOURMODE_8BIT_RGB;
            break;
        case(16):
            colour_mode = DRAW_COLOURMODE_16BIT_RGB;
            break;
        case(24):
            colour_mode = DRAW_COLOURMODE_24BIT_RGB;
            break;
        case(32):
            colour_mode = DRAW_COLOURMODE_32BIT_RGB;
            break;
        default:
            return(DRAW_ERR_BITMAP_NOT_SUPPORTED);
    }
    picItemPtr->fbmHeaderPtr->colourMode = colour_mode;

    // Get the dimensions:
    picItemPtr->fbmHeaderPtr->width  = bmp_head.width;
    picItemPtr->fbmHeaderPtr->height = bmp_head.height;

    // copy picture data to new picture file and drop onerous bitmap offsets:

    // process 32-bit bitmap data:
    if(bmp_head.bitsPerPixel == 32)
    {
        line_length = bmp_head.width * 4;

        // if there is no picture data adress given, calculate
        // the picture size and allocate memory automatically:
        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr = FAPI_SYS_MALLOC(bmp_head.height*line_length);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }

        line_counter = bmp_head.height;
        src8_ptr = bmp_head.bitmapDataPtr;

        while(line_counter--)
        {
            dst32_ptr = picItemPtr->dataPtr +
                        (line_counter * bmp_head.width);

            tmp = bmp_head.width;
            while(tmp--)
            {
                *dst32_ptr++ = drawReadBytes(src8_ptr, 4); // A.B.G.R. -> RGBA
                src8_ptr += 4;
            }
            // drop bitmap offsets:
            align_rest = ((uint32_t)src8_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                src8_ptr += 4 - align_rest;
            }
            /*lint -restore */
        }
    }
    // process 24-bit bitmap data:
    else if (bmp_head.bitsPerPixel == 24)
    {
        line_length = bmp_head.width * 3;

        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr = FAPI_SYS_MALLOC(bmp_head.height*line_length);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }

        line_counter = bmp_head.height;
        src8_ptr = bmp_head.bitmapDataPtr;
        dst8_ptr = (uint8_t*)picItemPtr->dataPtr;

        while(line_counter--)
        {
            dst8_ptr = (uint8_t*)picItemPtr->dataPtr +
                       (line_counter * line_length);
            tmp = bmp_head.width * 3;
            while(tmp--)
            {
                // keep byte-order in 24-bit mode: B.G.R.
                *dst8_ptr++ = *src8_ptr++;
            }
            // drop bitmap offsets:
            align_rest = ((uint32_t)src8_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                src8_ptr += 4 - align_rest;
            }
            /*lint -restore */
        }
    }
    // process 16-bit bitmap data:
    else if (bmp_head.bitsPerPixel == 16)
    {
        line_length = bmp_head.width * 2;

        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr = FAPI_SYS_MALLOC(bmp_head.height*line_length);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }

        line_counter = bmp_head.height;
        src8_ptr = (uint8_t*)bmp_head.bitmapDataPtr;

        while(line_counter--)
        {
            dst16_ptr = (uint16_t*)picItemPtr->dataPtr +
                        (line_counter * bmp_head.width);

            tmp = bmp_head.width;
            while(tmp--)
            {
                tmp16 = (uint16_t)(((*(src8_ptr + 1)) << 8) | (*src8_ptr));
                *dst16_ptr++ = ( ((tmp16 & 0x8000) >> 15 ) |
                                 ((tmp16 & 0x7C00) <<  1 ) |
                                 ((tmp16 & 0x03E0) <<  1 ) |
                                 ((tmp16 & 0x001F) <<  1 ) );
                src8_ptr += 2;
            }
            // drop bitmap offsets:
            align_rest = ((uint32_t)src8_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                src8_ptr += 4 - align_rest;
            }
            /*lint -restore */
        }
    }
    // process 8-bit bitmap data:
    else if (bmp_head.bitsPerPixel == 8)
    {
        line_length = bmp_head.width;

        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr = FAPI_SYS_MALLOC(bmp_head.height*line_length);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }

        // read the CLUT:
        if(picItemPtr->clutPtr == NULL)
        {
            picItemPtr->clutPtr = FAPI_SYS_MALLOC(1024); // 256 x 4 words
            if(picItemPtr->clutPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0004;
        }
        memset(picItemPtr->clutPtr, 0, 1024); // 256x4
        tmp = bmp_head.colours;
        if(tmp == 0) tmp = 0x0100UL;
        if(tmp > 0x0100UL) tmp = 0x0100UL;
        src8_ptr = bmp_head.palettePtr;
        dst32_ptr = picItemPtr->clutPtr;
        while(tmp--)
        {
            *dst32_ptr++ = drawReadRgbaColour(src8_ptr);
            src8_ptr += 4;
        }

        // read the bitmap data:
        line_counter = bmp_head.height;
        src8_ptr = bmp_head.bitmapDataPtr;

        while(line_counter--)
        {
            dst8_ptr = (uint8_t*)picItemPtr->dataPtr +
                       (line_counter * bmp_head.width);

            tmp = bmp_head.width;
            while(tmp--)
            {
                *dst8_ptr++ = *src8_ptr++;
            }
            // drop bitmap offsets:
            align_rest = ((uint32_t)src8_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                src8_ptr += 4 - align_rest;
            }
            /*lint -restore */
        }

    }
    // process 4-bit bitmap data:
    else if (bmp_head.bitsPerPixel == 4)
    {
        // reserve a whole byte for the last outstanding pixel:
        line_length = (bmp_head.width % 2) ?
                      ((bmp_head.width / 2) + 1) :
                      (bmp_head.width / 2);

        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr = FAPI_SYS_MALLOC(bmp_head.height*line_length);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }

        // read the CLUT:
        if(picItemPtr->clutPtr == NULL)
        {
            picItemPtr->clutPtr = FAPI_SYS_MALLOC(1024); // 256 x 4 words
            if(picItemPtr->clutPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0004;
        }
        memset(picItemPtr->clutPtr, 0, 1024); // 256x4
        tmp = bmp_head.colours;
        if(tmp == 0) tmp = 0x0010UL; // 16 colours
        if(tmp > 0x0100UL) tmp = 0x0100UL;
        src8_ptr = bmp_head.palettePtr;
        dst32_ptr = picItemPtr->clutPtr;
        while(tmp--)
        {
            *dst32_ptr++ = drawReadRgbaColour(src8_ptr);
            src8_ptr += 4;
        }

        // read the bitmap data:
        line_counter = bmp_head.height;
        src8_ptr = bmp_head.bitmapDataPtr;

        while(line_counter--)
        {
            dst8_ptr = (uint8_t*)picItemPtr->dataPtr +
                       (line_counter * line_length);

            tmp = line_length;
            while(tmp--)
            {
                *dst8_ptr++ = *src8_ptr++;
            }
            // drop bitmap offsets:
            align_rest = ((uint32_t)src8_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                src8_ptr += 4 - align_rest;
            }
            /*lint -restore */
        }
    }
    // process 1-bit bitmap data:
    else if (bmp_head.bitsPerPixel == 1)
    {
        // reserve a whole byte for the last outstanding pixels:
        line_length = (bmp_head.width % 8) ?
                      ((bmp_head.width / 8) + 1) :
                      (bmp_head.width / 8);

        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr = FAPI_SYS_MALLOC(bmp_head.height*line_length);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }

        // read the CLUT:
        if(picItemPtr->clutPtr == NULL)
        {
            picItemPtr->clutPtr = FAPI_SYS_MALLOC(1024); // 256 x 4 words
            if(picItemPtr->clutPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0004;
        }
        memset(picItemPtr->clutPtr, 0, 1024); // 256x4
        tmp = bmp_head.colours;
        if(tmp == 0) tmp = 0x0004UL; // 4 colours
        if(tmp > 0x0100UL) tmp = 0x0100UL;
        src8_ptr = bmp_head.palettePtr;
        dst32_ptr = picItemPtr->clutPtr;
        while(tmp--)
        {
            *dst32_ptr++ = drawReadRgbaColour(src8_ptr);
            src8_ptr += 4;
        }

        // read the bitmap data:
        line_counter = bmp_head.height;
        src8_ptr = bmp_head.bitmapDataPtr;

        while(line_counter--)
        {
            dst8_ptr = (uint8_t*)picItemPtr->dataPtr +
                       (line_counter * line_length);

            tmp = line_length;
            while(tmp--)
            {
                *dst8_ptr++ = *src8_ptr++;
            }
            // drop bitmap offsets:
            align_rest = ((uint32_t)src8_ptr - (uint32_t)bmp_head.bitmapDataPtr) % 4;
            if (align_rest)
            {
                src8_ptr += 4 - align_rest;
            }
            /*lint -restore */
        }
    }
    return(FAPI_OK);
}

#if DRAW_ENABLE_PNG == 1
/*!
*****************************************************************************
** \brief   Read a PNG picture file and store it as a DRAW_PicItemT.
**
** \note    If picItemPtr->fbmHeaderPtr or picItemPtr->dataPtr or
**          picItemPtr->clutPtr equals NULL, memory will be allocated
**          automatically. You have to deallocate this memory when the
**          picture is not needed any more by calling DRAW_FreeFbm().
**          For the clutPtr, memory will be allocated in case CLUT
**          colour modes only.
**
** \param filePtr
**              Points to the raw PNG data.
** \param picItemPtr
**              Points to a structure that will receive the picture data.
**
** \return
**        - #FAPI_OK on success
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized
**        - #DRAW_ERR_BAD_PARAMETER if one of the pointer arguments is NULL.
**        - #DRAW_ERR_OUT_OF_MEMORY if there was not enough memory available
**          for allocation in order to store the transcoded FBM picture file.
**        - #DRAW_ERR_PNG_NOT_SUPPORTED if the passed PNG can not be processed.
**
** \sa
**          - DRAW_ReadFile_FBM()
**          - DRAW_ReadFile_DAT()
**          - DRAW_ReadFile_BMP()
**          - DRAW_FreeFbm()
**
*****************************************************************************
*/
int32_t DRAW_ReadFile_PNG(uint32_t* filePtr, DRAW_PicItemT* picItemPtr)
{
    int32_t         result              = 0;
    uint8_t*        png_read_ptr        = (uint8_t*)filePtr;
    png_structp     png_ptr             = NULL; // internal PNG structure
    png_infop       info_ptr            = NULL; // PNG information
    png_infop       end_ptr             = NULL;
    png_colorp      png_palette_ptr     = NULL;
    int32_t         palette_size        = 0;
    uint8_t**       row_ptr_ptr         = NULL;
    uint32_t        png_width           = 0;
    uint32_t        png_height          = 0;
    uint32_t        ii                  = 0; // temporary counter

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }

    if((filePtr == NULL) || (picItemPtr == NULL))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    // reset dynamic allocation information:
    picItemPtr->allocInformation = 0x0000;

    // allocate memory for FBM header if needed
    if(picItemPtr->fbmHeaderPtr == NULL)
    {
        picItemPtr->fbmHeaderPtr = FAPI_SYS_MALLOC(sizeof(DRAW_FbmHeaderT));
        if(picItemPtr->fbmHeaderPtr == NULL)
        {
            DRAW_FreeFbm(picItemPtr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        picItemPtr->allocInformation |= 0x0001;
    }

    // Compare the PNG signature file header:
    if(png_sig_cmp(png_read_ptr, 0, DRAW_PNG_SIGNATURE_BYTES) != 0)
    {
        DRAW_FreeFbm(picItemPtr);
        return(DRAW_ERR_PNG_NOT_SUPPORTED);
    }
    png_read_ptr += DRAW_PNG_SIGNATURE_BYTES;

    // create internal png structure and assign FAPI specific
    // heap memory management and error and warning reporting functions
    png_ptr = png_create_read_struct_2
        (PNG_LIBPNG_VER_STRING, // version string
         NULL,                  // user_error_ptr
         drawPngError,          // user_error_fn
         drawPngWarning,        // user_warning_fn
         NULL,                  // user_mem_ptr
         drawPngMalloc,         // user_malloc_fn
         drawPngFree);          // user_free_fn
    if (!png_ptr)
    {
        DRAW_FreeFbm(picItemPtr);
        return (DRAW_ERR_PNG_INIT);
    }
    if (result)
    {
        FAPI_SYS_PRINT_MSG("\n[libpng] png_create_read_struct_2: user_error_ptr = %d\n", result);
    }

    // create info structure:
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        DRAW_FreeFbm(picItemPtr);
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        return (DRAW_ERR_PNG_INIT);
    }

    end_ptr = png_create_info_struct(png_ptr);
    if (!end_ptr)
    {
        DRAW_FreeFbm(picItemPtr);
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
        return (DRAW_ERR_PNG_INIT);
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
        return (DRAW_ERR_PNG_DECODE);
    }

    png_set_sig_bytes(png_ptr, DRAW_PNG_SIGNATURE_BYTES);
    png_set_read_fn(png_ptr, (voidp)&png_read_ptr, drawPngReadData);
    png_read_info(png_ptr, info_ptr);

    // get dimensions:
    png_width  = png_get_image_width(png_ptr, info_ptr);
    png_height = png_get_image_height(png_ptr, info_ptr);
    picItemPtr->fbmHeaderPtr->width = png_width;
    picItemPtr->fbmHeaderPtr->height = png_height;

    // switch colour mode:
    // 32-bit (or 64-bit ==> downsampling to 32 bit)
    if((png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
    || (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA))
    {
        if (png_get_bit_depth(png_ptr, info_ptr) == 16)
        {
            png_set_strip_16(png_ptr); // limit to 8 bit per channel
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
        {
            png_set_packing(png_ptr);
            png_set_bgr(png_ptr);
            png_set_swap_alpha(png_ptr);
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
        {
            png_set_gray_to_rgb(png_ptr);
            png_set_gray_1_2_4_to_8(png_ptr);
            png_set_bgr(png_ptr);
            png_set_swap_alpha(png_ptr);
        }
        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr =
                FAPI_SYS_MALLOC(png_height * png_width * sizeof(uint32_t));
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }
        row_ptr_ptr = FAPI_SYS_MALLOC(png_height * sizeof(uint32_t*));
        if(!row_ptr_ptr)
        {
            DRAW_FreeFbm(picItemPtr);
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        for(ii = 0; ii < png_height; ii++)
        {
            row_ptr_ptr[ii] = (uint8_t*) picItemPtr->dataPtr +
                                (ii * png_width * sizeof(uint32_t));
        }
        png_set_rows(png_ptr, info_ptr, row_ptr_ptr);
        png_read_update_info(png_ptr, info_ptr);
        png_read_image(png_ptr, row_ptr_ptr);
        FAPI_SYS_FREE(row_ptr_ptr);

        // Store processed colour mode:
        picItemPtr->fbmHeaderPtr->colourMode = DRAW_COLOURMODE_32BIT_RGB;
    }
    // 24-bit (or 48-bit ==> downsampling to 24 bit)
    else if((png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
    ||      (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY))
    {
        if (png_get_bit_depth(png_ptr, info_ptr) == 16)
        {
            png_set_strip_16(png_ptr); // limit to 8 bit per channel
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
        {
            png_set_packing(png_ptr);
            png_set_bgr(png_ptr);
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
        {
            png_set_gray_to_rgb(png_ptr);
            png_set_gray_1_2_4_to_8(png_ptr);
            png_set_bgr(png_ptr);
        }
        if(picItemPtr->dataPtr == NULL)
        {
            picItemPtr->dataPtr =
                FAPI_SYS_MALLOC(png_height * png_width * 3);
            if(picItemPtr->dataPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0002;
        }
        row_ptr_ptr = FAPI_SYS_MALLOC(png_height * sizeof(uint32_t*));
        if(!row_ptr_ptr)
        {
            DRAW_FreeFbm(picItemPtr);
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        for(ii = 0; ii < png_height; ii++)
        {
            row_ptr_ptr[ii] = (uint8_t*) picItemPtr->dataPtr + (ii * png_width * 3);
        }
        png_set_rows(png_ptr, info_ptr, row_ptr_ptr);
        png_read_update_info(png_ptr, info_ptr);
        png_read_image(png_ptr, row_ptr_ptr);
        FAPI_SYS_FREE(row_ptr_ptr);

        // Store processed colour mode:
        picItemPtr->fbmHeaderPtr->colourMode = DRAW_COLOURMODE_24BIT_RGB;
    }
    // 8-bit or 4-bit
    else if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
    {
        if(png_get_bit_depth(png_ptr, info_ptr) == 8)
        {
            if(picItemPtr->dataPtr == NULL)
            {
                picItemPtr->dataPtr =
                    FAPI_SYS_MALLOC(png_height * png_width * sizeof(uint8_t));
                if(picItemPtr->dataPtr == NULL)
                {
                    DRAW_FreeFbm(picItemPtr);
                    png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                    return(DRAW_ERR_OUT_OF_MEMORY);
                }
                picItemPtr->allocInformation |= 0x0002;
            }
            row_ptr_ptr = FAPI_SYS_MALLOC(png_height * sizeof(uint32_t*));
            if(!row_ptr_ptr)
            {
                DRAW_FreeFbm(picItemPtr);
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            for(ii = 0; ii < png_height; ii++)
            {
                row_ptr_ptr[ii] = (uint8_t*) picItemPtr->dataPtr + (ii * png_width);
            }
            png_set_rows(png_ptr, info_ptr, row_ptr_ptr);
            png_read_update_info(png_ptr, info_ptr);
            png_read_image(png_ptr, row_ptr_ptr);
            FAPI_SYS_FREE(row_ptr_ptr);

            picItemPtr->fbmHeaderPtr->colourMode = DRAW_COLOURMODE_8BIT_RGB;
        }
        else if(png_get_bit_depth(png_ptr, info_ptr) == 4)
        {
            if(picItemPtr->dataPtr == NULL)
            {
                picItemPtr->dataPtr =
                    FAPI_SYS_MALLOC(png_height * ((png_width + 1) / 2));
                if(picItemPtr->dataPtr == NULL)
                {
                    DRAW_FreeFbm(picItemPtr);
                    png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                    return(DRAW_ERR_OUT_OF_MEMORY);
                }
                picItemPtr->allocInformation |= 0x0002;
            }
            row_ptr_ptr = FAPI_SYS_MALLOC(png_height * sizeof(uint32_t*));
            if(!row_ptr_ptr)
            {
                DRAW_FreeFbm(picItemPtr);
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            for(ii = 0; ii < png_height; ii++)
            {
                row_ptr_ptr[ii] = (uint8_t*) picItemPtr->dataPtr +
                                            (ii * ((png_width + 1) / 2));
            }
            png_set_rows(png_ptr, info_ptr, row_ptr_ptr);
            png_read_update_info(png_ptr, info_ptr);
            png_read_image(png_ptr, row_ptr_ptr);
            FAPI_SYS_FREE(row_ptr_ptr);

            picItemPtr->fbmHeaderPtr->colourMode = DRAW_COLOURMODE_4BIT_RGB;
        }
        else
        {
            DRAW_FreeFbm(picItemPtr);
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_PNG_NOT_SUPPORTED);
        }
        // Copy CLUT to FBM:
        if(picItemPtr->clutPtr == NULL)
        {
            picItemPtr->clutPtr = FAPI_SYS_MALLOC(1024); // 256 x 4 words
            if(picItemPtr->clutPtr == NULL)
            {
                DRAW_FreeFbm(picItemPtr);
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            picItemPtr->allocInformation |= 0x0004;
        }
        memset(picItemPtr->clutPtr, 0, 1024); // 256x4
        png_get_PLTE(png_ptr, info_ptr, &png_palette_ptr, (int*)(void*)&palette_size);
        for(ii = 0; ii < palette_size; ii++)
        {
            picItemPtr->clutPtr[ii] =
                    (((png_palette_ptr + ii)->red)   << 24) |
                    (((png_palette_ptr + ii)->green) << 16) |
                    (((png_palette_ptr + ii)->blue)  <<  8) |
                    0x000000FFUL;
        }
    }
    else
    {
        DRAW_FreeFbm(picItemPtr);
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
        return(DRAW_ERR_OUT_OF_MEMORY);
    }
    // cleanup:
    png_read_end(png_ptr, end_ptr);
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
    return(FAPI_OK);
}
#endif /* DRAW_ENABLE_PNG == 1 */

/*!
*****************************************************************************
** \brief   Read a raw Fujitsu specific bitmap file (FBM) and store it locally
**          as a DRAW_PicItemT.
**
** \note    If picItemPtr->fbmHeaderPtr or picItemPtr->dataPtr or
**          picItemPtr->clutPtr equals NULL, memory will be allocated
**          automatically. You have to deallocate this memory when the
**          picture is not needed any more by calling DRAW_FreeFbm().
**          For the clutPtr, memory will be allocated in case of 8-bit, 4-bit
**          and 1-bit pictures only.
**
** \param filePtr
**              Points to the raw Fujitsu specific bitmap file (FBM) data.
** \param picItemPtr
**              Points to a structure that will receive the picture data.
**
** \return
**        - #FAPI_OK on success
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**        - #DRAW_ERR_BAD_PARAMETER if one of the pointer arguments is NULL.
**        - #DRAW_ERR_OUT_OF_MEMORY if there could be no memory allocated.
**        - #DRAW_ERR_UNKNOWN_FILE_TYPE if the file type is unknown.
**
** \sa
**          - DRAW_ReadFile_BMP()
**          - DRAW_ReadFile_DAT()
**          - DRAW_ReadFile_PNG()
**          - DRAW_FreeFbm()
**
*****************************************************************************
*/
/* 21c846a0 - complete */
int32_t DRAW_ReadFile_FBM(uint32_t* filePtr, DRAW_PicItemT* picItemPtr)
{
    uint32_t* word_ptr      = NULL;
    uint32_t  tmp           = 0;
    uint32_t  bpp           = 0;

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }

    if((filePtr == NULL) || (picItemPtr == NULL))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    // reset dynamic allocation information:
    picItemPtr->allocInformation = 0x0000;

    // allocate memory for FBM header if needed
    if(picItemPtr->fbmHeaderPtr == NULL)
    {
        picItemPtr->fbmHeaderPtr = FAPI_SYS_MALLOC(sizeof(DRAW_FbmHeaderT));
        if(picItemPtr->fbmHeaderPtr == NULL)
        {
            DRAW_FreeFbm(picItemPtr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        picItemPtr->allocInformation |= 0x0001;
    }

    // Get the colour mode:
    word_ptr = filePtr;
    tmp = *word_ptr++;
    bpp = drawExtractBitDepth((DRAW_ColourModeEnumT)tmp);
    if(bpp == 0)
    {
        return(DRAW_ERR_UNKNOWN_FILE_TYPE);
    }
    picItemPtr->fbmHeaderPtr->colourMode = (DRAW_ColourModeEnumT)tmp;

    // Get the dimensions:
    picItemPtr->fbmHeaderPtr->width  = *word_ptr++;
    picItemPtr->fbmHeaderPtr->height = *word_ptr++;

    tmp = picItemPtr->fbmHeaderPtr->width * bpp;    // bits per line
    tmp = (tmp % 8) ? ((tmp / 8) + 1) : (tmp / 8);  // bytes per line

    // bitmap size in bytes:
    tmp = tmp * picItemPtr->fbmHeaderPtr->height;

    // allocate memory if needed
    if(picItemPtr->dataPtr == NULL)
    {
        picItemPtr->dataPtr = FAPI_SYS_MALLOC(tmp);
        if(picItemPtr->dataPtr == NULL)
        {
            DRAW_FreeFbm(picItemPtr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        picItemPtr->allocInformation |= 0x0002;
    }

    // copy picture data to new picture file:
    memcpy(picItemPtr->dataPtr, word_ptr, tmp);

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Draw a Fujitsu specific bitmap file on an OSD.
**
**  This function draws a Fujitsu specific bitmap file on a specified osd layer.
**  It accepts a pointer to the header of the file as well as a bitmap data
**  pointer. In a DRAW_PicItemT structure, these arguments are the fbmHeaderPtr
**  and the dataPtr. A DRAW_PicItemT can be generated from a raw Fujitsu
**  specific bitmap file, a win bitmap file, a PNG file or an outdated Fujitsu
**  specific DAT file by calling DRAW_ReadFile_FBM(), DRAW_ReadFile_BMP(),
**  DRAW_ReadFile_PNG() or DRAW_ReadFile_DAT() respectively.
**
** \param   layerId
**              Identifies an OSD/CP layer.
** \param   xx
**              The x coordinate of the bitmap. It is relative to the top
**              left corner of the OSD layer.
** \param   yy
**              The y coordinate of the bitmap. It is relative to the top
**              left corner of the OSD layer.
** \param   hdrPtr
**              Contains information about width, height and colour encoding
**              of the picture.
** \param   picPtr
**              Points to the raw bitmap data.
**
** \return
**        - #FAPI_OK on success.
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**        - #OSDHANDLER_ERR_BAD_LAYER_ID The passed layerId is invalid.
**        - #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
**          opened at the initialization of the OSDHANDLER.
**        - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
**          is bad. Set up the colour mode by OSDHANDLER_SetColourMode.
**        - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the requested layer has
**          not been started.
**        - #DRAW_ERR_OUT_OF_OSD_SIZE if the picture does not fit into the
**          the OSD/CP plane due to its dimensions and/or its position on the
**          OSD/CP.
**        - #DRAW_ERR_WRONG_COLOUR_MODE if the colour mode of the bitmap does
**          not fit for the colour mode that the OSD/CP is running. Both colour
**          modes need to have the same amount of bits per pixel! The only
**          exclusion is the OSDHANDLER_OSD_MODE_TRU_COLOUR_32BIT_24BIT
**          that is valid for both 24-bit and 32-bit bitmaps.
**        - #DRAW_ERR_WRONG_LAYOUT_MODE if the OSDHANDLER_OsdLayoutEnumT mode
**          that the OSD/CP is running is not supported for drawing bitmap
**          files. Run the OSD/CP in OSDHANDLER_OSD_LAYOUT_RGBA.
**        - #DRAW_ERR_BAD_PARAMETER The passed layerId is unknown.
**        - #DRAW_ERR_BITMAP_NOT_SUPPORTED if the bitmap file is not supported.
**
** \sa
**          - DRAW_Bitmap()
**          - DRAW_ReadFile_BMP()
**          - DRAW_ReadFile_FBM()
**          - DRAW_ReadFile_DAT()
**          - DRAW_ReadFile_PNG()
**
*****************************************************************************
*/
int32_t DRAW_Fbm(const uint32_t layerId,
                 const uint32_t xx,
                 const uint32_t yy,
                 DRAW_FbmHeaderT* hdrPtr,
                 uint32_t* picPtr)
{
    OSDHANDLER_LayerParamsT  draw_layer_params;
    int32_t   result            = 0; // FAPI status word results
    uint32_t  bpp               = 0; // count of bits per pixel
    uint32_t  line              = 0; // temporary line counter
    uint32_t  ii                = 0; // temporary counter
    uint32_t  copy_steps        = 0; // pixel counter
    uint32_t  copy_rest         = 0; // keeps track of remaining pixels to copy
    uint32_t  pixel_base_addr   = 0; // 32-bit base address of a pixel
    uint32_t  pixel_bit_offset  = 0; // address offset for the pixel
    uint32_t  colour_mask       = 0; // colour mask
    uint32_t  data_mask         = 0; // mask for OSD memory
    uint32_t* dst32_ptr         = NULL; // 32-bit pointer for osd access
    uint32_t* src32_ptr         = NULL; // 32-bit pointer for picture access
    uint16_t* src16_ptr         = NULL; // 16-bit pointer for picture access
    uint8_t*  src8_ptr          = NULL; //  8-bit pointer for picture access

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }

    memset(&draw_layer_params, 0, sizeof(draw_layer_params));
    result = OSDHANDLER_GetLayerParameters(layerId, &draw_layer_params);
    if (result != FAPI_OK)
    {
        return(result);
        // may be:
        //- #OSDHANDLER_ERR_BAD_LAYER_ID if an invalid OSD qualifier is given
        //- #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
        //  opened at initialization
        //- #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
        //  is bad. Set up the colour mode by OSDHANDLER_SetColourMode()
    }

    // check if the layer is started:
    if(draw_layer_params.pictureBase == 0)
    {
        return(OSDHANDLER_ERR_LAYER_NOT_STARTED);
    }

    // check picture dimensions and position:
    if(((xx + hdrPtr->width)  > draw_layer_params.xRes)
     ||((yy + hdrPtr->height) > draw_layer_params.yRes))
    {
        return(DRAW_ERR_OUT_OF_OSD_SIZE);
    }

    // check the colour and layout modes:
    if((layerId == 1) || ((layerId & 0xFFFFFF00) == 0x00010000)
    || (layerId == 2) || ((layerId & 0xFFFFFF00) == 0x00020000)){
        // OSD1 and OSD2:
        if (draw_layer_params.colourMode  !=
            drawExtractFujitsuBitmapOsdMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_COLOUR_MODE);
        }
        if(draw_layer_params.layoutMode !=
           drawExtractFBMLayoutMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_LAYOUT_MODE);
        }
    }
    else if ((layerId == 3) || ((layerId & 0xFFFFFF00) == 0x00030000)){
        // Cursor Plane:
        if (draw_layer_params.colourMode  !=
            drawExtractFujitsuBitmapCpMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_COLOUR_MODE);
        }
        if(draw_layer_params.layoutMode !=
           drawExtractFBMLayoutMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_LAYOUT_MODE);
        }
    }
    else
    {
        return(DRAW_ERR_BAD_PARAMETER); // bad OSD qualifier
    }

    // empty picture:
    if((hdrPtr->width == 0) || (hdrPtr->height == 0))
    {
        return(FAPI_OK); // nothing to do
    }

    // copy the picture data to OSD memory:

    bpp = drawExtractBitDepth(hdrPtr->colourMode);

    switch(bpp)
    {

        // ***************************
        // process 32-bit bitmap:
        // ***************************
        case(32):

            line = 0;
            src32_ptr = picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width;
                while(copy_steps--)
                {
                    *dst32_ptr++ = *src32_ptr++;
                }
                line++;
            }
            break;

        // ***************************
        // process 24-bit bitmap:
        // ***************************
        case(24):

            line = 0;
            src8_ptr = (uint8_t*)picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width;
                while(copy_steps--)
                {
                    *dst32_ptr++ = ((drawReadBytes(src8_ptr, 3) << 8) |
                                       0x000000FFUL);
                    src8_ptr += 3;
                }
                line++;
            }
            break;

        // ***************************
        // process 16-bit bitmap:
        // ***************************
        case(16):

            line = 0;
            src16_ptr = (uint16_t*)(void*)picPtr;
            if(xx % 2)
            {
                // swap pixels
                while(line < hdrPtr->height)
                {
                    drawGetPixelAddress( xx,
                                         yy + line,
                                         &pixel_base_addr,
                                         &pixel_bit_offset,
                                         &draw_layer_params );
                    /*lint -save -e923 */
                    dst32_ptr = (uint32_t*)pixel_base_addr;
                    /*lint -restore */
                    copy_steps = hdrPtr->width; // at least 1

                    // write the first pixel:
                    ii = (uint32_t) *src16_ptr++;
                    *dst32_ptr = (*dst32_ptr & 0xFFFF0000UL) | ii;
                    dst32_ptr++;
                    copy_steps--;

                    copy_rest = copy_steps % 2;
                    copy_steps >>= 1;
                    // write whole words:
                    while(copy_steps--)
                    {
                        ii  = (uint32_t)*src16_ptr++ << 16;
                        ii |= (uint32_t)*src16_ptr++;
                        *dst32_ptr++ = ii;
                    }
                    // write the last pixel:
                    if(copy_rest)
                    {
                        ii  = ((uint32_t)*src16_ptr++) << 16;
                        *dst32_ptr = (*dst32_ptr & 0x0000FFFFUL) | ii;
                    }
                    line++;
                }
            }
            else
            {
                // keep pixel order as is
                while(line < hdrPtr->height)
                {
                    drawGetPixelAddress( xx,
                                         yy + line,
                                         &pixel_base_addr,
                                         &pixel_bit_offset,
                                         &draw_layer_params );
                    /*lint -save -e923 */
                    dst32_ptr = (uint32_t*)pixel_base_addr;
                    /*lint -restore */
                    copy_steps = hdrPtr->width >> 1;
                    while(copy_steps--)
                    {
                        ii  = (uint32_t)*src16_ptr++ << 16;
                        ii |= (uint32_t)*src16_ptr++;
                        *dst32_ptr++ = ii;
                    }
                    if(hdrPtr->width % 2)
                    {
                        ii  = ((uint32_t)*src16_ptr++) << 16;
                        *dst32_ptr = (*dst32_ptr & 0x0000FFFFUL) | ii;
                    }
                    line++;
                }
            }
            break;

        // ***************************
        // process 8-bit bitmap:
        // ***************************
        case(8):

            line = 0;
            colour_mask = 0x000000FFUL;
            src8_ptr = (uint8_t*)picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width; // at least 1, count of pixels

                if(pixel_bit_offset)
                {
                    for(ii = (0x20UL - pixel_bit_offset) >> 3; ii > 0; ii--)
                    {
                        if(copy_steps)
                        {
                            data_mask = colour_mask <<
                                    (0x0018UL - pixel_bit_offset);
                            *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                    ((uint32_t)*src8_ptr++ <<
                                    (0x0018UL - pixel_bit_offset));
                            pixel_bit_offset += 8;
                            copy_steps--;
                        }
                    }
                    dst32_ptr++;
                    pixel_bit_offset = 0;
                }

                copy_rest = copy_steps % 4; // count of remaining pixels
                copy_steps >>= 2;           // count of 32-bit words
                while(copy_steps--)
                {
                    ii  = (uint32_t)*src8_ptr++ << 24;
                    ii |= (uint32_t)*src8_ptr++ << 16;
                    ii |= (uint32_t)*src8_ptr++ <<  8;
                    ii |= (uint32_t)*src8_ptr++;
                    *dst32_ptr++ = ii;
                }
                if(copy_rest)
                {
                    while(copy_rest--)
                    {
                        data_mask = colour_mask <<
                                        (0x0018UL - pixel_bit_offset);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((uint32_t)*src8_ptr++ <<
                                        (0x0018UL - pixel_bit_offset));
                        pixel_bit_offset += 8;
                    }
                }
                line++;
            }
            break;

        // ***************************
        // process 4-bit bitmap:
        // ***************************
        case(4):

            line = 0;
            src8_ptr = (uint8_t*)picPtr;

            // draw the picture:
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );

                /*lint -save -e923 */
                dst32_ptr = (uint32_t*) pixel_base_addr;
                /*lint -restore */

                copy_steps = hdrPtr->width;

                if(pixel_bit_offset % 8)
                {
                    // this mode is entered if the x position of the bitmap is odd:
                    // ATTENTION: pixel accurate algorithm but low performance!

                    // ii serves as a flag that decides whether to read the upper or
                    // the lower 4 bits of a byte from the bitmap file:
                    ii = 1;
                    colour_mask = 0x0000000FUL;

                    while(copy_steps)
                    {
                        data_mask = colour_mask << (0x001CUL - pixel_bit_offset);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((ii ?
                                         ((*src8_ptr & 0xF0UL) >> 4):
                                         (*src8_ptr++ & 0x0FUL)) <<
                                         (0x001CUL - pixel_bit_offset));
                        ii = !ii;
                        pixel_bit_offset += 4;
                        if(pixel_bit_offset >> 5)
                        {
                            pixel_bit_offset = 0;
                            dst32_ptr++;
                        }
                        copy_steps--;
                    }
                    if(!ii)
                    {
                        src8_ptr++;
                    }
                }
                else
                {
                    // high performance algorithm for even x positions of the bmp:

                    colour_mask = 0x000000FFUL;

                    // write the first bytes:
                    while((pixel_bit_offset) && (copy_steps >> 1))
                    {
                        data_mask = colour_mask << (0x0018UL - pixel_bit_offset);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((uint32_t)*src8_ptr++ <<
                                            (0x0018UL - pixel_bit_offset));
                        pixel_bit_offset += 8;
                        copy_steps -= 2;
                        if(pixel_bit_offset >> 5)
                        {
                            pixel_bit_offset = 0;
                            dst32_ptr++;
                        }
                    }

                    // now copy 4-byte-wise:
                    copy_rest = copy_steps % 8;
                    copy_steps >>= 3;
                    while(copy_steps--)
                    {
                        ii  = (uint32_t)*src8_ptr++ << 24;
                        ii |= (uint32_t)*src8_ptr++ << 16;
                        ii |= (uint32_t)*src8_ptr++ <<  8;
                        ii |= (uint32_t)*src8_ptr++;
                        *dst32_ptr++ = ii;
                    }

                    copy_steps = copy_rest >> 1;
                    copy_rest %= 2;

                    // copy the remaining bytes:

                    while(copy_steps)
                    {
                        data_mask = colour_mask << (0x0018UL - pixel_bit_offset);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((uint32_t)*src8_ptr++ <<
                                        (0x0018UL - pixel_bit_offset));
                        pixel_bit_offset += 8;
                        copy_steps--;
                    }

                    // if the horizontal resolution is uneven, write the last pixel:
                    if(copy_rest)
                    {
                        colour_mask = 0x0000000FUL;
                        data_mask = colour_mask <<
                                        ((0x001CUL - pixel_bit_offset) & 0x001FUL);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        (((*src8_ptr++ & 0x00F0UL) >> 4) <<
                                        ((0x001CUL - pixel_bit_offset) & 0x001FUL));
                    }
                }
                line++;
            }
            break;

        // ***************************
        // process 2-bit bitmap:
        // ***************************
        case(2): return(DRAW_ERR_BITMAP_NOT_SUPPORTED);

        // ***************************
        // process 1-bit bitmap:
        // ***************************
        case(1):

            line = 0;
            src8_ptr = (uint8_t*)picPtr;

            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );

                /*lint -save -e923 */
                dst32_ptr = (uint32_t*) pixel_base_addr;
                /*lint -restore */

                copy_steps = hdrPtr->width;

                if(pixel_bit_offset % 8)
                {
                    /* this mode is entered if the x position of the bitmap is
                    ** not a multiple of 8. Therefore there is a misalignment
                    ** of the data in the bitmap file in reference to the OSD
                    ** plane and the single pixels need to be shifted.
                    ** ATTENTION: low performance!
                    */

                    ii = 7;
                    data_mask = 0x0001UL << (0x001FUL - pixel_bit_offset);
                    while(copy_steps)
                    {
                        if(*src8_ptr & (0x01UL << ii))
                        {
                            *dst32_ptr |= data_mask;
                        }
                        else
                        {
                            *dst32_ptr &= (~data_mask);
                        }
                        if (ii == 0)
                        {
                            ii = 7;
                            src8_ptr++;
                        }
                        else
                        {
                            ii--;
                        }
                        pixel_bit_offset++;
                        data_mask >>= 1;
                        if(pixel_bit_offset >> 5)
                        {
                            pixel_bit_offset = 0;
                            data_mask = 0x80000000UL;
                            dst32_ptr++;
                        }
                        copy_steps--;
                    }
                    if(ii != 7)
                    {
                        src8_ptr++;
                    }
                }
                else
                {
                    // high performance algorithm for xx = a multiple of 8

                    colour_mask = 0x000000FFUL;

                    // write the first bytes:
                    while((pixel_bit_offset) && (copy_steps >> 3))
                    {
                        data_mask = colour_mask << (0x0018UL - pixel_bit_offset);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((uint32_t)*src8_ptr++ <<
                                            (0x0018UL - pixel_bit_offset));
                        pixel_bit_offset += 8;
                        copy_steps -= 8;
                        if(pixel_bit_offset >> 5)
                        {
                            pixel_bit_offset = 0;
                            dst32_ptr++;
                        }
                    }

                    // now copy 4-byte-wise:
                    copy_rest = copy_steps % 32;
                    copy_steps >>= 5;
                    while(copy_steps--)
                    {
                        ii  = (uint32_t)*src8_ptr++ << 24;
                        ii |= (uint32_t)*src8_ptr++ << 16;
                        ii |= (uint32_t)*src8_ptr++ <<  8;
                        ii |= (uint32_t)*src8_ptr++;
                        *dst32_ptr++ = ii;
                    }

                    copy_steps = copy_rest >> 3;
                    copy_rest %= 8;

                    // copy the remaining bytes:

                    while(copy_steps)
                    {
                        data_mask = colour_mask <<
                                        ((0x0018UL - pixel_bit_offset) & 0x001FUL);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((uint32_t)*src8_ptr++ <<
                                        ((0x0018UL - pixel_bit_offset) & 0x001FUL));
                        pixel_bit_offset += 8;
                        copy_steps--;
                    }

                    // copy the last pixels if any
                    if(copy_rest)
                    {
                        colour_mask = (0x0001UL << copy_rest) - 0x0001UL;
                        data_mask = colour_mask <<
                                    ((0x0020UL - (pixel_bit_offset + copy_rest))
                                    & 0x001FUL);
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        (
                                         ((uint32_t)*src8_ptr++ >>
                                                    (8 - copy_rest)) <<
                                         (((0x0020UL -
                                           (pixel_bit_offset + copy_rest)))
                                          & 0x001FUL)
                                        );
                    }
                }
                line++;
            }
            break;

        // ***************************
        // process illegal bit values:
        // ***************************
        default: return(DRAW_ERR_BITMAP_NOT_SUPPORTED);
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Draw a masked Fujitsu specific bitmap file on an OSD.
**
**          This function draws a Fujitsu specific bitmap file on a specified
**          OSD layer. Pixels with a specific colour value (maskColour)
**          from the source picture file will not be drawn on the OSD.
**          Therefore it is possible to draw a picture on a background
**          so that those pixels from the picture that match the maskColour
**          appear transparent.
**          The function accepts a pointer to the header of the picture file as
**          well as a bitmap data pointer. In a DRAW_PicItemT structure,
**          these arguments are the fbmHeaderPtr and the dataPtr.
**
** \param   layerId
**              Identifies an OSD/CP layer.
** \param   xx
**              The x coordinate of the bitmap. It is relative to the top
**              left corner of the OSD layer.
** \param   yy
**              The y coordinate of the bitmap. It is relative to the top
**              left corner of the OSD layer.
** \param   hdrPtr
**              Contains information about width, height and colour encoding
**              of the picture.
** \param   picPtr
**              Points to the raw bitmap data.
** \param   maskColour
**              Pixels from the picture that match this colour code will not be
**              drawn on the OSD.
**
** \return
**        - #FAPI_OK on success.
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**        - #OSDHANDLER_ERR_BAD_LAYER_ID The passed layerId is invalid.
**        - #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
**          opened at the initialization of the OSDHANDLER.
**        - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
**          is bad. Set up the colour mode by OSDHANDLER_SetColourMode().
**        - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the requested layer has
**          not been started.
**        - #DRAW_ERR_OUT_OF_OSD_SIZE if the picture does not fit into the
**          the OSD/CP plane due to its dimensions and/or its position on the
**          OSD/CP.
**        - #DRAW_ERR_WRONG_COLOUR_MODE if the colour mode of the bitmap does
**          not fit for the colour mode that the OSD/CP is running. Both colour
**          modes need to have the same amount of bits per pixel! The only
**          exclusion is the OSDHANDLER_OSD_MODE_TRU_COLOUR_32BIT_24BIT
**          that is valid for both 24-bit and 32-bit bitmaps.
**        - #DRAW_ERR_WRONG_LAYOUT_MODE if the OSDHANDLER_OsdLayoutEnumT mode
**          that the OSD/CP is running is not supported for drawing bitmap
**          files. Run the OSD/CP in OSDHANDLER_OSD_LAYOUT_RGBA.
**        - #DRAW_ERR_BAD_PARAMETER
**              - The passed layerId is unknown.
**              - The passed maskColour uses too many bits.
**        - #DRAW_ERR_BITMAP_NOT_SUPPORTED if the bitmap file is not supported.
**
** \sa
**          - DRAW_Bitmap()
**          - DRAW_ReadFile_BMP()
**          - DRAW_ReadFile_FBM()
**          - DRAW_ReadFile_DAT()
**
*****************************************************************************
*/
/* 21c81170 - complete */
int32_t DRAW_Fbm_Overlay(const uint32_t layerId,
                         const uint32_t xx,
                         const uint32_t yy,
                         DRAW_FbmHeaderT* hdrPtr,
                         uint32_t* picPtr,
                         uint32_t  maskColour)
{
    OSDHANDLER_LayerParamsT  draw_layer_params;
    int32_t   result            = 0; // FAPI status word results
    uint32_t  bpp               = 0; // count of bits per pixel
    uint32_t  line              = 0; // temporary line counter
    uint32_t  ii                = 0; // temporary counter
    uint32_t  temp              = 0; // temporary value
    uint32_t  copy_steps        = 0; // pixel counter
    uint32_t  copy_rest         = 0; // keeps track of remaining pixels to copy
    uint32_t  pixel_base_addr   = 0; // 32-bit base address of a pixel
    uint32_t  pixel_bit_offset  = 0; // address offset for the pixel
    uint32_t  colour_mask       = 0; // colour mask
    uint32_t  data_mask         = 0; // mask for OSD memory
    uint32_t* dst32_ptr         = NULL; // 32-bit pointer for osd access
    uint32_t* src32_ptr         = NULL; // 32-bit pointer for picture access
    uint16_t* src16_ptr         = NULL; // 16-bit pointer for picture access
    uint8_t*  src8_ptr          = NULL; //  8-bit pointer for picture access

    if(!drawInitialized)
    {
        return 0xffd9da5c; //(FAPI_ERR_NOT_INITIALIZED);
    }
    memset(&draw_layer_params, 0, sizeof(draw_layer_params));
    result = OSDHANDLER_GetLayerParameters(layerId, &draw_layer_params);
    if (result != FAPI_OK)
    {
        return(result);
        // may be:
        //- #OSDHANDLER_ERR_BAD_LAYER_ID if an invalid OSD qualifier is given
        //- #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
        //  opened at initialization
        //- #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
        //  is bad. Set up the colour mode by OSDHANDLER_SetColourMode()
    }

    // check if the layer is started:
    if(draw_layer_params.pictureBase == 0)
    {
        return(OSDHANDLER_ERR_LAYER_NOT_STARTED);
    }

    // check picture dimensions and position:
    if(((xx + hdrPtr->width) > draw_layer_params.xRes)
     ||((yy + hdrPtr->height) > draw_layer_params.yRes))
    {
        return(DRAW_ERR_OUT_OF_OSD_SIZE);
    }

    // check the colour and layout modes:
    if((layerId == 1) || ((layerId & 0xFFFFFF00) == 0x00010000)
    || (layerId == 2) || ((layerId & 0xFFFFFF00) == 0x00020000)){
        // OSD1 and OSD2:
        if (draw_layer_params.colourMode  !=
            drawExtractFujitsuBitmapOsdMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_COLOUR_MODE);
        }
        if(draw_layer_params.layoutMode !=
           drawExtractFBMLayoutMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_LAYOUT_MODE);
        }
    }
    else if ((layerId == 3) || ((layerId & 0xFFFFFF00) == 0x00030000)){
        // Cursor Plane:
        if (draw_layer_params.colourMode  !=
            drawExtractFujitsuBitmapCpMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_COLOUR_MODE);
        }
        if(draw_layer_params.layoutMode !=
           drawExtractFBMLayoutMode(hdrPtr->colourMode))
        {
            return(DRAW_ERR_WRONG_LAYOUT_MODE);
        }
    }
    else
    {
        return(DRAW_ERR_BAD_PARAMETER); // bad OSD qualifier, must not happen
    }

    bpp = drawExtractBitDepth(hdrPtr->colourMode);
    if((bpp < 32) && (maskColour >> bpp))
    {
        return(DRAW_ERR_BAD_PARAMETER); // maskColour uses too many bits
    }

    // empty picture:
    if((hdrPtr->width == 0) || (hdrPtr->height == 0))
    {
        return(FAPI_OK); // nothing to do
    }

    // copy the picture data to OSD memory:
    switch(bpp)
    {
        // ***************************
        // process 32-bit bitmap:
        // ***************************
        case 32:
            line = 0;
            src32_ptr = picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width;
                while(copy_steps--)
                {
                    if(*src32_ptr != maskColour)
                    {
                        *dst32_ptr = *src32_ptr;
                    }
                    src32_ptr++;
                    dst32_ptr++;
                }
                line++;
            }
            break;

        // ***************************
        // process 24-bit bitmap:
        // ***************************
        case 24:
            line = 0;
            src8_ptr = (uint8_t*)picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width;
                while(copy_steps--)
                {
                    ii = drawReadBytes(src8_ptr, 3);
                    if(ii != maskColour)
                    {
                        *dst32_ptr = (ii << 8) | 0x000000FFUL;
                    }
                    dst32_ptr++;
                    src8_ptr += 3;
                }
                line++;
            }
            break;

        // ***************************
        // process 16-bit bitmap:
        // ***************************
        case 16:
            line = 0;
            src16_ptr = (uint16_t*)(void*)picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width; // at least 1

                if(xx % 2) // if (pixel_bit_offset == 16)
                {
                    // write the first pixel:
                    ii = (uint32_t) *src16_ptr++;
                    if(ii != maskColour)
                    {
                        *dst32_ptr = (*dst32_ptr & 0xFFFF0000UL) | ii;
                    }
                    dst32_ptr++;
                    copy_steps--;
                }

                copy_rest = copy_steps % 2;
                copy_steps >>= 1;
                // write whole words:
                while(copy_steps--)
                {
                    ii = (uint32_t) *src16_ptr++;
                    if(ii != maskColour)
                    {
                        *dst32_ptr = (*dst32_ptr & 0x0000FFFFUL) | (ii << 16);
                    }
                    ii = (uint32_t) *src16_ptr++;
                    if(ii != maskColour)
                    {
                        *dst32_ptr = (*dst32_ptr & 0xFFFF0000UL) | ii;
                    }
                    dst32_ptr++;
                }
                // write the last pixel:
                if(copy_rest)
                {
                    ii = (uint32_t) *src16_ptr++;
                    if(ii != maskColour)
                    {
                        *dst32_ptr = (*dst32_ptr & 0x0000FFFFUL) | (ii << 16);
                    }
                }
                line++;
            }
            break;

        // ***************************
        // process 8-bit bitmap:
        // ***************************
        case  8:
            line = 0;
            colour_mask = 0x000000FFUL;
            src8_ptr = (uint8_t*)picPtr;
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );
                /*lint -save -e923 */
                dst32_ptr = (uint32_t*)pixel_base_addr;
                /*lint -restore */
                copy_steps = hdrPtr->width; // at least 1, count of pixels

                if(pixel_bit_offset)
                {
                    for(ii = (0x20UL - pixel_bit_offset) >> 3; ii > 0; ii--)
                    {
                        if(copy_steps)
                        {
                            if(*src8_ptr != maskColour)
                            {
                                data_mask = colour_mask <<
                                        (0x0018UL - pixel_bit_offset);
                                *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                        ((uint32_t)*src8_ptr <<
                                        (0x0018UL - pixel_bit_offset));
                            }
                            src8_ptr++;
                            pixel_bit_offset += 8;
                            copy_steps--;
                        }
                    }
                    dst32_ptr++;
                    pixel_bit_offset = 0;
                }

                copy_rest = copy_steps % 4; // count of remaining pixels
                copy_steps >>= 2;           // count of 32-bit words
                while(copy_steps--)
                {
                    ii  = *dst32_ptr;
                    if(*src8_ptr != maskColour)
                    {
                        ii &= 0x00FFFFFFUL;
                        ii |= (uint32_t)*src8_ptr << 24;
                    }
                    src8_ptr++;
                    if(*src8_ptr != maskColour)
                    {
                        ii &= 0xFF00FFFFUL;
                        ii |= (uint32_t)*src8_ptr << 16;
                    }
                    src8_ptr++;
                    if(*src8_ptr != maskColour)
                    {
                        ii &= 0xFFFF00FFUL;
                        ii |= (uint32_t)*src8_ptr <<  8;
                    }
                    src8_ptr++;
                    if(*src8_ptr != maskColour)
                    {
                        ii &= 0xFFFFFF00UL;
                        ii |= (uint32_t)*src8_ptr;
                    }
                    src8_ptr++;
                    *dst32_ptr = ii;
                    dst32_ptr++;
                }
                if(copy_rest)
                {
                    while(copy_rest--)
                    {
                        if(*src8_ptr != maskColour)
                        {
                            data_mask = colour_mask <<
                                            (0x0018UL - pixel_bit_offset);
                            *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                            ((uint32_t)*src8_ptr <<
                                            (0x0018UL - pixel_bit_offset));
                        }
                        src8_ptr++;
                        pixel_bit_offset += 8;
                    }
                }
                line++;
            }
            break;

        // ***************************
        // process 4-bit bitmap:
        // ***************************
        case  4:

            line = 0;
            src8_ptr = (uint8_t*)picPtr;

            // draw the picture:
            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );

                /*lint -save -e923 */
                dst32_ptr = (uint32_t*) pixel_base_addr;
                /*lint -restore */

                copy_steps = hdrPtr->width;

                // ii serves as a flag that decides whether to read the upper or
                // the lower 4 bits of a byte from the bitmap file:
                ii = 1;
                colour_mask = 0x0000000FUL;

                while(copy_steps)
                {
                    data_mask = colour_mask << (0x001CUL - pixel_bit_offset);
                    temp = ii ? ((*src8_ptr   & 0x000000F0UL) >> 4) :
                                 (*src8_ptr++ & 0x0000000FUL);

                    if(temp != maskColour)
                    {
                        *dst32_ptr = (*dst32_ptr & (~data_mask)) |
                                     (temp << (0x001CUL - pixel_bit_offset));
                    }

                    ii = !ii;
                    pixel_bit_offset += 4;
                    if(pixel_bit_offset >> 5)
                    {
                        pixel_bit_offset = 0;
                        dst32_ptr++;
                    }
                    copy_steps--;
                }
                if(!ii)
                {
                    src8_ptr++;
                }
                line++;
            }
            break;

        // ***************************
        // process 2-bit bitmap:
        // ***************************
        case  2: return(DRAW_ERR_BITMAP_NOT_SUPPORTED);

        // ***************************
        // process 1-bit bitmap:
        // ***************************
        case  1:

            line = 0;
            src8_ptr = (uint8_t*)picPtr;

            while(line < hdrPtr->height)
            {
                drawGetPixelAddress( xx,
                                     yy + line,
                                     &pixel_base_addr,
                                     &pixel_bit_offset,
                                     &draw_layer_params );

                /*lint -save -e923 */
                dst32_ptr = (uint32_t*) pixel_base_addr;
                /*lint -restore */

                copy_steps = hdrPtr->width;

                ii = 7;
                data_mask = 0x0001UL << (0x001FUL - pixel_bit_offset);
                while(copy_steps)
                {
                    if(*src8_ptr & (0x01UL << ii))
                    {
                        if(~maskColour)
                        {
                            *dst32_ptr |= data_mask;
                        }
                    }
                    else if (maskColour)
                    {
                        *dst32_ptr &= (~data_mask);
                    }
                    if (ii == 0)
                    {
                        ii = 7;
                        src8_ptr++;
                    }
                    else
                    {
                        ii--;
                    }
                    pixel_bit_offset++;
                    data_mask >>= 1;
                    if(pixel_bit_offset >> 5)
                    {
                        pixel_bit_offset = 0;
                        data_mask = 0x80000000UL;
                        dst32_ptr++;
                    }
                    copy_steps--;
                }
                if(ii != 7)
                {
                    src8_ptr++;
                }
                line++;
            }
            break;

        // ***************************
        // process illegal bit values:
        // ***************************
        default:
            return(DRAW_ERR_BITMAP_NOT_SUPPORTED);
    }
    return(FAPI_OK);
}
/*!
*****************************************************************************
** \brief   Frees members of a DRAW_PicItemT structure that have been
**          allocated dynamically by the DRAW library before.
**
** \note    You will have to call this function for all picture files
**          that you passed to one of the DRAW_ReadFile_... functions
**          while one of the pointers fbmHeaderPtr, dataPtr or the
**          clutPtr have been NULL, in order to free memory again.
**
** \param   picItemPtr  Points to a picture file that is not needed any more
**                      and whose memory will be freed.
**
*****************************************************************************
*/
/* 21c80830 - complete */
void DRAW_FreeFbm(DRAW_PicItemT* picItemPtr)
{
    if(picItemPtr->allocInformation & 0x0001)
    {
        FAPI_SYS_FREE(picItemPtr->fbmHeaderPtr);
    }
    if(picItemPtr->allocInformation & 0x0002)
    {
        FAPI_SYS_FREE(picItemPtr->dataPtr);
    }
    if(picItemPtr->allocInformation & 0x0004)
    {
        FAPI_SYS_FREE(picItemPtr->clutPtr);
    }
    
    picItemPtr->allocInformation = 0;
    
    return;
}

#if DRAW_ENABLE_PNG == 1
/*!
*****************************************************************************
** \brief   Draws a PNG picture on an OSD/CP or virtual layer.
**
** \param   layerId
**              Specifies on which layer the PNG will be drawn.
** \param   xx
**              The x coordinate on the layer where the picture will be drawn.
** \param   yy
**              The y coordinate on the layer where the picture will be drawn.
** \param   mode
**              Determines whether to set up the layer with the colour lookup
**              table (CLUT) that is provided by the PNG file. Possible values
**              are:
**              - DRAW_SET_UP_CLUT sets the whole CLUT of the OSD
**              - DRAW_DO_NOT_SET_UP_CLUT leaves the CLUT unmodified
** \param   pngPtr
**              Points to the PNG file in memory.
** \param   errorCodePtr
**              Will receive error codes that may occur when calling underlying
**              drivers (OSDHANDLER calls VISCALE driver). The error code is
**              is formatted as described in the documentation of the OSDHANDLER.
**              If no errors occur, it will equal FAPI_OK. Argument is optional,
**              may be NULL.
**
** \return
**        - #FAPI_OK on success.
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized.
**        - #DRAW_ERR_BAD_PARAMETER
**          - A bad mode is passed.
**          - The pngPtr argument is NULL.
**        - #OSDHANDLER_ERR_BAD_LAYER_ID The passed layerId is invalid.
**        - #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
**          opened at the initialization of the OSDHANDLER.
**        - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**          if the hardware OSD layer is locked since its virtual group
**          has been started previously. You will need to call
**          OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**        - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
**          is bad. Set up the colour mode by OSDHANDLER_SetColourMode.
**        - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the requested layer has
**          not been started.
**        - #DRAW_ERR_PNG_NOT_SUPPORTED if the file can not be processed as PNG.
**        - #DRAW_ERR_PNG_INIT if something wrent up while setting up the
**          PNG library.
**        - #DRAW_ERR_OUT_OF_OSD_SIZE if the picture does not fit into the
**          the OSD/CP plane due to its dimensions and/or its position on the
**          OSD/CP.
**        - #DRAW_ERR_WRONG_COLOUR_MODE if the colour mode of the PNG does
**          not fit for the colour mode that the OSD/CP is running.
**        - #DRAW_ERR_OUT_OF_MEMORY if the system is out of memory.
**
*****************************************************************************
*/
int32_t DRAW_PNG   (const uint32_t  layerId,
                    const uint32_t  xx,
                    const uint32_t  yy,
                    const DRAW_ModeEnumT mode,
                    uint8_t* pngPtr,
                    uint32_t* errorCodePtr)
{
    int32_t         result              = 0;
    uint32_t        ii                  = 0;
    uint32_t        kk                  = 0;
    png_structp     png_ptr             = NULL; // internal PNG structure
    png_infop       info_ptr            = NULL; // PNG information
    png_infop       end_ptr             = NULL;
    uint8_t**       row_ptr_ptr         = NULL; // array of row pointers
    uint8_t*        png_read_ptr        = pngPtr;
    uint32_t*       osd_word_ptr        = NULL;
    uint32_t        osd_base_addr       = 0;
    uint32_t        osd_offset          = 0;
    uint32_t        png_width           = 0;
    uint32_t        png_height          = 0;
    uint32_t        tmp1                = 0; // temporary colour value for CbYCrA scheme
    uint32_t        tmp2                = 0; // temporary colour value for CCIR scheme
    uint32_t        colour_mask         = 0;
    uint32_t        data_mask           = 0;
    uint32_t*       png_rowbuffer_ptr   = NULL; // temporary buffer for PNG data
    uint32_t*       png_buf_read_32_ptr = NULL; // pointer used for reading the buffer
    uint8_t*        png_buf_read_8_ptr  = NULL; // pointer used for reading the buffer
    //png_color_16    bg_col;                     // background colour
    //png_color_16p   bg_col_ptr = NULL;          // background colour pointer
    int32_t         palette_size        = 0;
    png_colorp      png_palette_ptr     = NULL;
    uint32_t        osd_palette_ptr[256];
    OSDHANDLER_LayerParamsT  layer_params;

    memset(&layer_params, 0, sizeof(layer_params));
    memset(osd_palette_ptr, 0, sizeof(osd_palette_ptr));
    // memset(&bg_col, 0, sizeof(png_color_16));

    if(errorCodePtr) *errorCodePtr = FAPI_OK;

    if(!drawInitialized)
    {
        return(DRAW_ERR_NOT_INITIALIZED);
    }
    if(pngPtr == NULL)
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }
    result = OSDHANDLER_GetLayerParameters(layerId, &layer_params);
    if (result != FAPI_OK)
    {
        return(result);
        // may be:
        //- #OSDHANDLER_ERR_BAD_LAYER_ID if an invalid OSD qualifier is given
        //- #OSDHANDLER_ERR_NO_OSD_HANDLE if the requested OSD has not been
        //  opened at initialization
        //- #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the OSD
        //  is bad. Set up the colour mode by OSDHANDLER_SetColourMode
    }
    if(layer_params.pictureBase == 0)
    {
        return(OSDHANDLER_ERR_LAYER_NOT_STARTED);
    }
    if(!((mode == DRAW_SET_UP_CLUT) || (mode == DRAW_DO_NOT_SET_UP_CLUT)))
    {
        return(DRAW_ERR_BAD_PARAMETER);
    }

    // Compare the PNG signature file header:
    if(png_sig_cmp(png_read_ptr, 0, DRAW_PNG_SIGNATURE_BYTES) != 0)
    {
        return(DRAW_ERR_PNG_NOT_SUPPORTED);
    }
    png_read_ptr += DRAW_PNG_SIGNATURE_BYTES;

    // create internal png structure and assign FAPI specific
    // heap memory management and error and warning reporting functions
    png_ptr = png_create_read_struct_2
        (PNG_LIBPNG_VER_STRING, // version string
         NULL,                  // user_error_ptr
         drawPngError,          // user_error_fn
         drawPngWarning,        // user_warning_fn
         NULL,                  // user_mem_ptr
         drawPngMalloc,         // user_malloc_fn
         drawPngFree);          // user_free_fn
    if (!png_ptr)
    {
        return (DRAW_ERR_PNG_INIT);
    }
    if (result)
    {
        FAPI_SYS_PRINT_MSG("\n[libpng] png_create_read_struct_2: user_error_ptr = %d\n", result);
    }

    // create info structure:
    info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        return (DRAW_ERR_PNG_INIT);
    }

    end_ptr = png_create_info_struct(png_ptr);
    if (!end_ptr)
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
        return (DRAW_ERR_PNG_INIT);
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
        return (DRAW_ERR_PNG_DECODE);
    }

    png_set_sig_bytes(png_ptr, DRAW_PNG_SIGNATURE_BYTES);
    png_set_read_fn(png_ptr, (voidp)&png_read_ptr, drawPngReadData);
    //png_set_keep_unknown_chunks(png_ptr, PNG_HANDLE_CHUNK_AS_DEFAULT, NULL, 0);
    png_read_info(png_ptr, info_ptr);

    png_width  = png_get_image_width(png_ptr, info_ptr);
    png_height = png_get_image_height(png_ptr, info_ptr);

    if(((xx + png_width) > layer_params.xRes)
     ||((yy + png_height) > layer_params.yRes))
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
        return(DRAW_ERR_OUT_OF_OSD_SIZE);
    }

    // only if PNG_NO_FLOATING_POINT_SUPPORTED is not defined in PNG-lib:
    //if (png_get_bKGD(png_ptr, info_ptr, &bg_col_ptr))
    //{
    //    png_set_background(png_ptr, bg_col_ptr, PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);
    //}
    //else
    //{
    //    bg_col.red   = 0; //(1 << 16) - 1;
    //    bg_col.green = 0; //(1 << 16) - 1;
    //    bg_col.blue  = 0; //(1 << 16) - 1;
    //    bg_col.gray  = 0; //(1 << 16) - 1;
    //    png_set_background(png_ptr, &bg_col, PNG_BACKGROUND_GAMMA_SCREEN, 0, 1.0);
    //}

        if(layer_params.colourMode == OSDHANDLER_OSD_MODE_32_24BIT)
    {
        if((layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
        || (layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ACbYCr))
        {
            if (png_get_bit_depth(png_ptr, info_ptr) == 16)
            {
                png_set_strip_16(png_ptr); // limit to 8 bit per channel
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
            {
                png_set_packing(png_ptr);
                png_set_palette_to_rgb(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
            }

            // add a filler byte in left of the RGB data
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
            }

            // expand gray scale images to RGB with fixed alpha (0xFF)
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
            }

            if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ACbYCr)
            {
                png_set_read_user_transform_fn(png_ptr, drawPngTransformARGB2ACbYCr);
            }
        }
        else if((layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_RGBA)
             || (layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA))
        {
            if (png_get_bit_depth(png_ptr, info_ptr) == 16)
            {
                png_set_strip_16(png_ptr); // limit to 8 bit per channel
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
            {
                png_set_packing(png_ptr);
                png_set_palette_to_rgb(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_BEFORE);
            }

            // add a filler byte in left of the RGB data
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_BEFORE);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
                png_set_swap_alpha(png_ptr);
            }

            // expand gray scale images to RGB with fixed alpha (0xFF)
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_BEFORE);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
            {
                png_set_swap_alpha(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_gray_to_rgb(png_ptr);
                png_set_bgr(png_ptr);
            }
            if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                png_set_read_user_transform_fn(png_ptr, drawPngTransformRGBA2CbYCrA);
            }
        }

        // write out to 32-bit OSD:
        row_ptr_ptr = FAPI_SYS_MALLOC(png_height * sizeof(uint32_t*));
        if(!row_ptr_ptr)
        {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        for(ii = 0; ii < png_height; ii++)
        {
            drawGetPixelAddress(xx, yy + ii, &osd_base_addr, &osd_offset, &layer_params);
            row_ptr_ptr[ii] = (uint8_t*)(void*)osd_base_addr;
        }
        png_set_rows(png_ptr, info_ptr, row_ptr_ptr);
        png_read_update_info(png_ptr, info_ptr);
        png_read_image(png_ptr, row_ptr_ptr);
        FAPI_SYS_FREE(row_ptr_ptr);
    }
    else if(layer_params.colourMode == OSDHANDLER_OSD_MODE_16BIT) // CCIR mode
    {
        if(layer_params.layoutMode != OSDHANDLER_OSD_LAYOUT_CbYCrA)
        {
            // CCIR mode is only supported for CbYCrA layout which
            // actually results in a CbY1CrY2 layout that represents
            // two pixels with same Cb and Cr values in a 32-bit word.
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_WRONG_LAYOUT_MODE);
        }
        // first set up the PNG library to present its data in 32-bit ARGB format
        if (png_get_bit_depth(png_ptr, info_ptr) == 16)
        {
            png_set_strip_16(png_ptr); // limit to 8 bit per channel
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
        {
            png_set_packing(png_ptr);
            png_set_palette_to_rgb(png_ptr);
            png_set_bgr(png_ptr);
            png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
        }
        // add a filler byte in left of the RGB data
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
        {
            png_set_packing(png_ptr);
            png_set_bgr(png_ptr);
            png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
        {
            png_set_packing(png_ptr);
            png_set_bgr(png_ptr);
        }
        // expand gray scale images to RGB with fixed alpha (0xFF)
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
        {
            png_set_gray_to_rgb(png_ptr);
            png_set_gray_1_2_4_to_8(png_ptr);
            png_set_bgr(png_ptr);
            png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
        }
        if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
        {
            png_set_gray_to_rgb(png_ptr);
            png_set_gray_1_2_4_to_8(png_ptr);
            png_set_bgr(png_ptr);
        }

        // set up a buffer that holds a single PNG row
        png_rowbuffer_ptr = FAPI_SYS_MALLOC(png_width * sizeof(uint32_t));
        if(png_rowbuffer_ptr == NULL)
        {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }

        for(ii = 0; ii < png_height; ii++)
        {
            kk = png_width;

            // for each row copy PNG data into the buffer in ARGB format
            png_read_row(png_ptr, (png_bytep)png_rowbuffer_ptr, NULL);
            png_buf_read_32_ptr = png_rowbuffer_ptr;

            // use osd_base_addr pointer to iterate the 32-bit CCIR values:
            drawGetPixelAddress(xx, yy + ii, &osd_base_addr, &osd_offset, &layer_params);

            // first write a single pixel if xx is odd:
            if(xx % 2)
            {
                tmp1 = OSDHANDLER_ConvertARGB2CbYCrA_word(*png_buf_read_32_ptr++);
                tmp2 = *((uint32_t*)osd_base_addr);
                // mask values to 0 that will be modified:
                *((uint32_t*)osd_base_addr) &= ~0xFF00FFFFUL;
                // Interpolate the Cb value:
                *((uint32_t*)osd_base_addr) |=
                    ((((tmp1 & 0xFF000000UL) >> 24) + ((tmp2 &0xFF000000UL) >> 24)) / 2) << 24;
                // Interpolate the Cr value:
                *((uint32_t*)osd_base_addr) |=
                    ((((tmp1 & 0x0000FF00UL) >> 8) + ((tmp2 &0x0000FF00UL) >> 8)) / 2) << 8;
                // Write out the Y value of the right pixel:
                *((uint32_t*)osd_base_addr) |= (tmp1 & 0x00FF0000UL) >> 16;
                osd_base_addr += 4;
                kk--;
            }
            kk >>= 1;
            while (kk--)
            {
                *((uint32_t*)osd_base_addr) =
                    OSDHANDLER_ConvertRGB2CCIR(*png_buf_read_32_ptr, *(png_buf_read_32_ptr+1));
                png_buf_read_32_ptr += 2;
                osd_base_addr += 4;
            }
            // write out the last pixel individually if necessary:
            if((((xx % 2) == 0) && (png_width % 2))
            || ((xx % 2) && ((png_width % 2) == 0)))
            {
                tmp1 = OSDHANDLER_ConvertARGB2CbYCrA_word(*png_buf_read_32_ptr++);
                tmp2 = *((uint32_t*)osd_base_addr);
                // mask values to 0 that will be modified:
                *((uint32_t*)osd_base_addr) &= ~0xFFFFFF00UL;
                // Interpolate the Cb value:
                *((uint32_t*)osd_base_addr) |=
                    ((((tmp1 & 0xFF000000UL) >> 24) + ((tmp2 &0xFF000000UL) >> 24)) / 2) << 24;
                // Interpolate the Cr value:
                *((uint32_t*)osd_base_addr) |=
                    ((((tmp1 & 0x0000FF00UL) >> 8) + ((tmp2 &0x0000FF00UL) >> 8)) / 2) << 8;
                // Write out the Y value of the left pixel:
                *((uint32_t*)osd_base_addr) |= (tmp1 & 0x00FF0000UL);
                osd_base_addr += 4;
            }
        }
        FAPI_SYS_FREE(png_rowbuffer_ptr);
    }
    else if((layer_params.colourMode == OSDHANDLER_OSD_MODE_5551)
    ||      (layer_params.colourMode == OSDHANDLER_OSD_MODE_4444))
    {
        if((layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
        || (layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ACbYCr))
        {
            if (png_get_bit_depth(png_ptr, info_ptr) == 16)
            {
                png_set_strip_16(png_ptr); // limit to 8 bit per channel
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
            {
                png_set_packing(png_ptr);
                png_set_palette_to_rgb(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
            }

            // add a filler byte in left of the RGB data
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
            }

            // expand gray scale images to RGB with fixed alpha (0xFF)
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
            }
            if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ACbYCr)
            {
                png_set_read_user_transform_fn(png_ptr, drawPngTransformARGB2ACbYCr);
            }
        }
        else if((layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_RGBA)
             || (layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA))
        {
            if (png_get_bit_depth(png_ptr, info_ptr) == 16)
            {
                png_set_strip_16(png_ptr); // limit to 8 bit per channel
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
            {
                png_set_packing(png_ptr);
                png_set_palette_to_rgb(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_BEFORE);
            }

            // add a filler byte in left of the RGB data
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_BEFORE);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
            {
                png_set_packing(png_ptr);
                png_set_bgr(png_ptr);
                png_set_swap_alpha(png_ptr);
            }

            // expand gray scale images to RGB with fixed alpha (0xFF)
            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
                png_set_filler(png_ptr, 0xFF, PNG_FILLER_BEFORE);
            }

            if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
            {
                png_set_gray_to_rgb(png_ptr);
                png_set_gray_1_2_4_to_8(png_ptr);
                png_set_bgr(png_ptr);
                png_set_swap_alpha(png_ptr);
            }
            if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                png_set_read_user_transform_fn(png_ptr, drawPngTransformRGBA2CbYCrA);
            }
        }
        // set up a buffer that holds a single PNG row
        png_rowbuffer_ptr = FAPI_SYS_MALLOC(png_width * sizeof(uint32_t));
        if(png_rowbuffer_ptr == NULL)
        {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_OUT_OF_MEMORY);
        }
        for(ii = 0; ii < png_height; ii++)
        {
            // for each row copy PNG data into the buffer in ARGB format
            png_read_row(png_ptr, (png_bytep)png_rowbuffer_ptr, NULL);
            png_buf_read_32_ptr = png_rowbuffer_ptr;
            drawGetPixelAddress(xx, yy + ii, &osd_base_addr, &osd_offset, &layer_params);
            kk = png_width;
            if(layer_params.colourMode == OSDHANDLER_OSD_MODE_5551)
            {
                if((layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
                || (layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ACbYCr))
                {
                    if (xx % 2)
                    {
                        *((uint32_t*)osd_base_addr) &= 0xFFFF0000UL;
                        *((uint32_t*)osd_base_addr) |=
                            ((*png_buf_read_32_ptr & 0xFF000000UL) ? (1UL << 15) : 0) |
                            ((*png_buf_read_32_ptr & 0x00F80000UL) >> 9) |
                            ((*png_buf_read_32_ptr & 0x0000F800UL) >> 6) |
                            ((*png_buf_read_32_ptr & 0x000000F8UL) >> 3);
                        kk--;
                        png_buf_read_32_ptr += 1;
                        osd_base_addr += 4;
                    }
                    kk >>= 1;
                    while(kk--)
                    {
                        *((uint32_t*)osd_base_addr) =
                            ((*png_buf_read_32_ptr & 0xFF000000UL) ? (1UL << 31) : 0) |
                            ((*png_buf_read_32_ptr & 0x00F80000UL) <<  7) |
                            ((*png_buf_read_32_ptr & 0x0000F800UL) << 10) |
                            ((*png_buf_read_32_ptr & 0x000000F8UL) << 13) |
                            ((*(png_buf_read_32_ptr + 1) & 0xFF000000UL) ? (1UL << 15) : 0) |
                            ((*(png_buf_read_32_ptr + 1) & 0x00F80000UL) >> 9) |
                            ((*(png_buf_read_32_ptr + 1) & 0x0000F800UL) >> 6) |
                            ((*(png_buf_read_32_ptr + 1) & 0x000000F8UL) >> 3);
                        png_buf_read_32_ptr += 2;
                        osd_base_addr += 4;
                    }
                    if(((xx % 2) && (!(png_width % 2)))
                    || ((!(xx % 2)) && (png_width % 2)))
                    {
                        *((uint32_t*)osd_base_addr) &= 0x0000FFFFUL;
                        *((uint32_t*)osd_base_addr) |=
                            ((*png_buf_read_32_ptr & 0xFF000000UL) ? (1UL << 31) : 0) |
                            ((*png_buf_read_32_ptr & 0x00F80000UL) <<  7) |
                            ((*png_buf_read_32_ptr & 0x0000F800UL) << 10) |
                            ((*png_buf_read_32_ptr & 0x000000F8UL) << 13);
                    }
                }
                else if((layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_RGBA)
                ||      (layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA))
                {
                    if (xx % 2)
                    {
                        *((uint32_t*)osd_base_addr) &= 0xFFFF0000UL;
                        *((uint32_t*)osd_base_addr) |=
                            ((*png_buf_read_32_ptr & 0xF8000000UL) >> 16) |
                            ((*png_buf_read_32_ptr & 0x00F80000UL) >> 13) |
                            ((*png_buf_read_32_ptr & 0x0000F800UL) >> 10) |
                            ((*png_buf_read_32_ptr & 0x000000FFUL) ? 1UL : 0UL);
                        kk--;
                        png_buf_read_32_ptr += 1;
                        osd_base_addr += 4;
                    }
                    kk >>= 1;
                    while(kk--)
                    {
                        *((uint32_t*)osd_base_addr) =
                            ((*png_buf_read_32_ptr & 0xF8000000UL)      ) |
                            ((*png_buf_read_32_ptr & 0x00F80000UL) <<  3) |
                            ((*png_buf_read_32_ptr & 0x0000F800UL) <<  6) |
                            ((*png_buf_read_32_ptr & 0x000000FFUL) ? (1UL << 16) : 0UL) |
                            ((*(png_buf_read_32_ptr + 1) & 0xF8000000UL) >> 16) |
                            ((*(png_buf_read_32_ptr + 1) & 0x00F80000UL) >> 13) |
                            ((*(png_buf_read_32_ptr + 1) & 0x0000F800UL) >> 10) |
                            ((*(png_buf_read_32_ptr + 1) & 0x000000FFUL) ? 1UL : 0UL);
                        png_buf_read_32_ptr += 2;
                        osd_base_addr += 4;
                    }
                    if(((xx % 2) && (!(png_width % 2)))
                    || ((!(xx % 2)) && (png_width % 2)))
                    {
                        *((uint32_t*)osd_base_addr) &= 0x0000FFFFUL;
                        *((uint32_t*)osd_base_addr) |=
                            ((*png_buf_read_32_ptr & 0xF8000000UL)      ) |
                            ((*png_buf_read_32_ptr & 0x00F80000UL) <<  3) |
                            ((*png_buf_read_32_ptr & 0x0000F800UL) <<  6) |
                            ((*png_buf_read_32_ptr & 0x000000FFUL) ? (1UL << 16) : 0UL);
                    }
                }
            }
            else if(layer_params.colourMode == OSDHANDLER_OSD_MODE_4444)
            {
                if (xx % 2)
                {
                    *((uint32_t*)osd_base_addr) &= 0xFFFF0000UL;
                    *((uint32_t*)osd_base_addr) |=
                        ((*png_buf_read_32_ptr & 0xF0000000UL) >> 16) |
                        ((*png_buf_read_32_ptr & 0x00F00000UL) >> 12) |
                        ((*png_buf_read_32_ptr & 0x0000F000UL) >>  8) |
                        ((*png_buf_read_32_ptr & 0x000000F0UL) >>  4);
                    kk--;
                    png_buf_read_32_ptr += 1;
                    osd_base_addr += 4;
                }
                kk >>= 1;
                while(kk--)
                {
                    *((uint32_t*)osd_base_addr) =
                        ((*png_buf_read_32_ptr & 0xF0000000UL)      ) |
                        ((*png_buf_read_32_ptr & 0x00F00000UL) <<  4) |
                        ((*png_buf_read_32_ptr & 0x0000F000UL) <<  8) |
                        ((*png_buf_read_32_ptr & 0x000000F0UL) << 12) |
                        ((*(png_buf_read_32_ptr + 1) & 0xF0000000UL) >> 16) |
                        ((*(png_buf_read_32_ptr + 1) & 0x00F00000UL) >> 12) |
                        ((*(png_buf_read_32_ptr + 1) & 0x0000F000UL) >>  8) |
                        ((*(png_buf_read_32_ptr + 1) & 0x000000F0UL) >>  4);
                    png_buf_read_32_ptr += 2;
                    osd_base_addr += 4;
                }
                if(((xx % 2) && (!(png_width % 2)))
                || ((!(xx % 2)) && (png_width % 2)))
                {
                    *((uint32_t*)osd_base_addr) &= 0x0000FFFFUL;
                    *((uint32_t*)osd_base_addr) |=
                        ((*png_buf_read_32_ptr & 0xF0000000UL)      ) |
                        ((*png_buf_read_32_ptr & 0x00F00000UL) <<  4) |
                        ((*png_buf_read_32_ptr & 0x0000F000UL) <<  8) |
                        ((*png_buf_read_32_ptr & 0x000000F0UL) << 12);
                }
            }
        }
        FAPI_SYS_FREE(png_rowbuffer_ptr);
    }
    else if((layer_params.colourMode == OSDHANDLER_OSD_MODE_CLUT_8BIT)
    ||      (layer_params.colourMode == OSDHANDLER_OSD_MODE_CLUT_4BIT))
    {
        if(png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_PALETTE)
        {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
            return(DRAW_ERR_PNG_NOT_SUPPORTED);
        }
        if(layer_params.colourMode == OSDHANDLER_OSD_MODE_CLUT_8BIT)
        {
            if(png_get_bit_depth(png_ptr, info_ptr) != 8)
            {
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_WRONG_COLOUR_MODE);
            }
            png_rowbuffer_ptr = FAPI_SYS_MALLOC(png_width * sizeof(uint8_t));
            if(png_rowbuffer_ptr == NULL)
            {
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            for(ii = 0; ii < png_height; ii++)
            {
                kk = png_width;
                // for each row copy PNG data into the buffer in ARGB format
                png_read_row(png_ptr, (png_bytep)png_rowbuffer_ptr, NULL);
                png_buf_read_8_ptr = (uint8_t*)png_rowbuffer_ptr;
                drawGetPixelAddress(xx, yy + ii, &osd_base_addr, &osd_offset, &layer_params);

                // handle leading pixels:
                if(osd_offset)
                {
                    while(osd_offset)
                    {
                        colour_mask = 0x000000FFUL << (24 - osd_offset);
                        *((uint32_t*)osd_base_addr) &= ~colour_mask;
                        *((uint32_t*)osd_base_addr) |= *png_buf_read_8_ptr++ << (24 - osd_offset);
                        osd_offset = (osd_offset + 8) % 32;
                    }
                    osd_base_addr += 4;
                }
                kk >>= 2;
                while(kk--)
                {
                    *((uint32_t*)osd_base_addr) =
                        (*png_buf_read_8_ptr     << 24) |
                        (*(png_buf_read_8_ptr+1) << 16) |
                        (*(png_buf_read_8_ptr+2) <<  8) |
                        (*(png_buf_read_8_ptr+3)      );
                        png_buf_read_8_ptr += 4;
                        osd_base_addr += 4;
                }
                // handle trailing pixels:
                kk = png_width - ((4 - (xx % 4)) % 4); // strip leading pixel count
                kk %= 4; // count of remaining pixels
                while(kk--)
                {
                    colour_mask = 0x000000FFUL << (24 - osd_offset);
                    *((uint32_t*)osd_base_addr) &= ~colour_mask;
                    *((uint32_t*)osd_base_addr) |= *png_buf_read_8_ptr++ << (24 - osd_offset);
                    osd_offset = (osd_offset + 8) % 32;
                }
                osd_base_addr += 4;
            }
        }
        else if(layer_params.colourMode == OSDHANDLER_OSD_MODE_CLUT_4BIT)
        {
            if(png_get_bit_depth(png_ptr, info_ptr) != 4)
            {
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_WRONG_COLOUR_MODE);
            }
            //png_rowbuffer_ptr = FAPI_SYS_MALLOC(((png_width + 1) * layer_params.bpp) / 8);
            png_rowbuffer_ptr = FAPI_SYS_MALLOC(png_width);
            if(png_rowbuffer_ptr == NULL)
            {
                png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
                return(DRAW_ERR_OUT_OF_MEMORY);
            }
            for(ii = 0; ii < png_height; ii++)
            {
                kk = png_width;
                // for each row copy PNG data into the buffer in ARGB format
                png_read_row(png_ptr, (png_bytep)png_rowbuffer_ptr, NULL);
                png_buf_read_8_ptr = (uint8_t*)png_rowbuffer_ptr;
                drawGetPixelAddress(xx, yy + ii, &osd_base_addr, &osd_offset, &layer_params);
                osd_word_ptr = (uint32_t*) osd_base_addr;

                // if xx is odd, the 4-bit values will have to be swapped:
                if(osd_offset % 8)
                {
                    tmp1 = 1;
                    colour_mask = 0x0000000FUL;
                    while(kk)
                    {
                        // tmp1 serves as a flag that decides whether to read the upper
                        // or the lower 4 bits of a byte from the bitmap file:
                        data_mask = colour_mask <<
                                    ((0x001CUL - osd_offset) & 0x001FUL);
                        *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                    ((tmp1 ?
                                     ((*png_buf_read_8_ptr & 0xF0UL) >> 4):
                                     (*png_buf_read_8_ptr++ & 0x0FUL)) <<
                                     ((0x001CUL - osd_offset) & 0x001FUL));
                        tmp1 = !tmp1;
                        osd_offset += 4;
                        if(osd_offset >> 5)
                        {
                            osd_offset = 0;
                            osd_word_ptr++;
                        }
                        kk--;
                    }
                    if(!tmp1)
                    {
                        png_buf_read_8_ptr++;
                    }
                }
                else
                {
                    colour_mask = 0x000000FFUL;
                    // write the first bytes:
                    while((osd_offset) && (kk >> 1))
                    {
                        data_mask = colour_mask << (0x0018UL - osd_offset);
                        *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                        ((uint32_t)*png_buf_read_8_ptr++ <<
                                            (0x0018UL - osd_offset));
                        osd_offset += 8;
                        kk -= 2;
                        if(osd_offset >> 5)
                        {
                            osd_offset = 0;
                            osd_word_ptr++;
                        }
                    }

                    // now copy 4-byte-wise:
                    // tmp1 serves as a counter for remaining copy steps here
                    tmp1 = kk % 8;
                    kk >>= 3;
                    while(kk--)
                    {
                        tmp2  = (uint32_t)*png_buf_read_8_ptr++ << 24;
                        tmp2 |= (uint32_t)*png_buf_read_8_ptr++ << 16;
                        tmp2 |= (uint32_t)*png_buf_read_8_ptr++ <<  8;
                        tmp2 |= (uint32_t)*png_buf_read_8_ptr++;
                        *osd_word_ptr++ = tmp2;
                    }

                    kk = tmp1 >> 1;
                    tmp1 %= 2;

                    // copy the remaining bytes:

                    while(kk)
                    {
                        data_mask = colour_mask <<
                                        ((0x0018UL - osd_offset) & 0x001FUL);
                        *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                        ((uint32_t)*png_buf_read_8_ptr++ <<
                                        ((0x0018UL - osd_offset) & 0x001FUL));
                        osd_offset += 8;
                        kk--;
                    }

                    // if the horizontal resolution is uneven, write the last pixel:
                    if(tmp1)
                    {
                        colour_mask = 0x0000000FUL;
                        data_mask = colour_mask <<
                                        ((0x001CUL - osd_offset) & 0x001FUL);
                        *osd_word_ptr = (*osd_word_ptr & (~data_mask)) |
                                        (((*png_buf_read_8_ptr++ & 0x00F0UL) >> 4) <<
                                        ((0x001CUL - osd_offset) & 0x001FUL));
                    }
                }
            }
        }
        FAPI_SYS_FREE(png_rowbuffer_ptr);

        if(mode == DRAW_SET_UP_CLUT)
        {
            png_get_PLTE(png_ptr, info_ptr, &png_palette_ptr, (int*)(void*)&palette_size);

            // copy the palette into a OSD capable CLUT:
            if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ARGB)
            {
                for(ii = 0; ii < palette_size; ii++)
                {
                    osd_palette_ptr[ii] =
                            0xFF000000UL |
                            (((png_palette_ptr + ii)->red)  << 16) |
                            (((png_palette_ptr + ii)->green) << 8) |
                            (((png_palette_ptr + ii)->blue));
                }
            }
            else if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_RGBA)
            {
                for(ii = 0; ii < palette_size; ii++)
                {
                    osd_palette_ptr[ii] =
                            (((png_palette_ptr + ii)->red)   << 24) |
                            (((png_palette_ptr + ii)->green) << 16) |
                            (((png_palette_ptr + ii)->blue)  <<  8) |
                            0x000000FFUL;
                }
            }
            else if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_ACbYCr)
            {
                for(ii = 0; ii < palette_size; ii++)
                {
                    osd_palette_ptr[ii] = (OSDHANDLER_ConvertARGB2CbYCrA_word
                                (
                                0xFF000000UL |
                                (((png_palette_ptr + ii)->red)  << 16) |
                                (((png_palette_ptr + ii)->green) << 8) |
                                (((png_palette_ptr + ii)->blue))
                                ) >> 8) | 0xFF000000UL;
                }
            }
            else if(layer_params.layoutMode == OSDHANDLER_OSD_LAYOUT_CbYCrA)
            {
                for(ii = 0; ii < palette_size; ii++)
                {
                    osd_palette_ptr[ii] = OSDHANDLER_ConvertARGB2CbYCrA_word
                                (
                                0xFF000000UL |
                                (((png_palette_ptr + ii)->red)  << 16) |
                                (((png_palette_ptr + ii)->green) << 8) |
                                (((png_palette_ptr + ii)->blue))
                                );
                }
            }
            // possible error code already checked
            (void)OSDHANDLER_SetClutPartially(layerId, osd_palette_ptr, 0, palette_size, NULL);
        }
    }
    else // colourMode
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
        return(DRAW_ERR_WRONG_COLOUR_MODE);
    }
    // cleanup:
    png_read_end(png_ptr, end_ptr);
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_ptr);
    return(FAPI_OK);
}
#endif /* DRAW_ENABLE_PNG == 1 */
