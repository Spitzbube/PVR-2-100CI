/*
*****************************************************************************
**
** \file        ./subsystems/paint/osdhandler/src/osdhandler.c
**
** \brief       OSD handler for the paint middleware.
**
** This file contains the implementation of the OSDHANDLER API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007-2009 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2008-2009 by Fujitsu Microelectronics Limited
**
*****************************************************************************
*/

/*!
**  Enables/disables DMA driver access for memory intensive operations.
**  Overrides all CPU routines.
*/
#define OSDHANDLER_USE_DMA      0

/*! Enables/disables assembler optimized CPU routines. */
#define OSDHANDLER_USE_ASM      0 //1

#include <stdint.h>
#include <fapi/drv_viscale.h>
#include "osdhandler.h"
#define  OSDHANDLER_C           1
#include "osdhandler_priv.h"

#if OSDHANDLER_USE_VIRTUAL_LAYERS
#include "osdhandler_virtual.h"
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

#if OSDHANDLER_USE_ASM
#include "osdhandler_asm.h"
#endif

// include for SPEED measurements:
//#include <fapi/drv_timer.h>

//***************************************************************************
//***************************************************************************
//** Local Defines
//***************************************************************************
//***************************************************************************
#define DRV_ID_VIOUT_CP    (FAPEXDEV_VIOUT_SUB_MINOR_FIRST + 2)
#define DRV_ID_VIOUT_OSD1  (FAPEXDEV_VIOUT_SUB_MINOR_FIRST + 3)
#define DRV_ID_VIOUT_OSD2  (FAPEXDEV_VIOUT_SUB_MINOR_FIRST + 4)

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

//***************************************************************************
//***************************************************************************
//** Local Functions Declaration
//***************************************************************************
//***************************************************************************

static INLINE void osdhandlerSetUpSystemLimitations(FAPI_SYS_HandleT handle);


//***************************************************************************
//***************************************************************************
//** Global Data
//***************************************************************************
//***************************************************************************


//***************************************************************************
//***************************************************************************
//** Private Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief   Gets the Viscale specific OSD mode that corresponds to a given
**          OSDHANDLER_ColourModeT.
**
**          An OSDHANDLER_ColourModeT declares both, OSD related and CP related
**          modes thus this function returns 'unknown' if a CP related colour
**          mode is provided. Otherwise the valid OSD mode is returned.
**
** \param   osdhandlerColourMode The provided colour mode.
**
** \return  The corresponding colour mode:
**          -   Any of the valid modes on success.
**          -   FAPEX_VIOUT_OSD_MODE_UNKNOWN if the osdhandler colour mode is
**              not related to one of the valid OSD colour modes.
**
** \sa
**          - osdhandlerGetCpColourMode()
**
*****************************************************************************
*/
/* 21c7d0ec - complete */
FAPI_VISCALE_OsdModeEnumT osdhandlerGetOsdColourMode
           (const OSDHANDLER_ColourModeT osdhandlerColourMode)
{
    switch(osdhandlerColourMode)
    {
        case(OSDHANDLER_OSD_MODE_CLUT_4BIT):
            return(FAPI_VISCALE_OSD_MODE_CLUT_4BIT);
        case(OSDHANDLER_OSD_MODE_CLUT_8BIT):
            return(FAPI_VISCALE_OSD_MODE_CLUT_8BIT);
        case(OSDHANDLER_OSD_MODE_16BIT):
            return(FAPI_VISCALE_OSD_MODE_16BIT);
        case(OSDHANDLER_OSD_MODE_4444):
            return(FAPI_VISCALE_OSD_MODE_4444);
        case(OSDHANDLER_OSD_MODE_5551):
            return(FAPI_VISCALE_OSD_MODE_5551);
        case(OSDHANDLER_OSD_MODE_32_24BIT):
            return(FAPI_VISCALE_OSD_MODE_32_24BIT);
        case(OSDHANDLER_OSD_MODE_UNKNOWN):
        case(OSDHANDLER_CURSOR_MODE_UNKNOWN):
        case(OSDHANDLER_CURSOR_MODE_1BIT):
        case(OSDHANDLER_CURSOR_MODE_2BIT):
        case(OSDHANDLER_CURSOR_MODE_4BIT):
        case(OSDHANDLER_CURSOR_MODE_8BIT):
        default:
            return(FAPI_VISCALE_UNKNOWN_OSD_MODE);
    }
}

/*!
*****************************************************************************
** \brief   Gets the Viscale specific CP mode that corresponds to a given
**          OSDHANDLER_ColourModeT.
**
**          An OSDHANDLER_ColourModeT declares both, OSD related and CP related
**          modes thus this function returns 'unknown' if a OSD related colour
**          mode is provided. Otherwise the valid CP mode is returned.
**
** \param   osdhandlerColourMode The provided colour mode.
**
** \return  The corresponding colour mode.
**          -   Any of the valid modes on success.
**          -   FAPEX_VIOUT_CURSOR_MODE_UNKNOWN if the osdhandler colour mode
**              is not related to one of the valid CP colour modes.
**
** \sa
**          - osdhandlerGetOsdColourMode()
**
*****************************************************************************
*/
/* 21c7d14c - complete */
FAPI_VISCALE_CursorModeEnumT osdhandlerGetCpColourMode
                              (const OSDHANDLER_ColourModeT osdhandlerColourMode)
{
    switch(osdhandlerColourMode)
    {
        case(OSDHANDLER_CURSOR_MODE_1BIT):
            return(FAPI_VISCALE_CURSOR_MODE_1BIT);
        case(OSDHANDLER_CURSOR_MODE_2BIT):
            return(FAPI_VISCALE_CURSOR_MODE_2BIT);
        case(OSDHANDLER_CURSOR_MODE_4BIT):
            return(FAPI_VISCALE_CURSOR_MODE_4BIT);
        case(OSDHANDLER_CURSOR_MODE_8BIT):
            return(FAPI_VISCALE_CURSOR_MODE_8BIT);
        case(OSDHANDLER_OSD_MODE_UNKNOWN):
        case(OSDHANDLER_CURSOR_MODE_UNKNOWN):
        case(OSDHANDLER_OSD_MODE_CLUT_4BIT):
        case(OSDHANDLER_OSD_MODE_CLUT_8BIT):
        case(OSDHANDLER_OSD_MODE_16BIT):
        case(OSDHANDLER_OSD_MODE_4444):
        case(OSDHANDLER_OSD_MODE_5551):
        case(OSDHANDLER_OSD_MODE_32_24BIT):
        default:
            return(FAPI_VISCALE_UNKNOWN_CURSOR_MODE);
    }
}

/*!
*****************************************************************************
** \brief   Gets the Viscale specific bit organisation layout mode that
**          corresponds to a given OSDHANDLER_OsdLayoutEnumT mode.
**
** \param   osdhandlerLayout The provided layout mode of the OSDHANDLER.
**
** \return  Viscale specific bit organisation layout mode:
**          -   One of the internal FAPEX_VIOUT_OsdLayoutEnumT modes on
**              success.
**          -   FAPEX_VIOUT_OSD_LAYOUT_UNKNOWN if the osdhandlerLayout
**              mode is unknown.
**
** \sa
**          - osdhandlerGetOsdColourMode()
**          - osdhandlerGetCpColourMode()
**
*****************************************************************************
*/
/* 21c7d194 - complete */
FAPI_VISCALE_OsdLayoutEnumT osdhandlerGetOsdLayout
                            (const OSDHANDLER_OsdLayoutEnumT osdhandlerLayout)
{
    switch(osdhandlerLayout)
    {
        case(OSDHANDLER_OSD_LAYOUT_ARGB):
            return(FAPI_VISCALE_OSD_LAYOUT_ARGB);
        case(OSDHANDLER_OSD_LAYOUT_RGBA):
            return(FAPI_VISCALE_OSD_LAYOUT_RGBA);
        case(OSDHANDLER_OSD_LAYOUT_ACbYCr):
            return(FAPI_VISCALE_OSD_LAYOUT_ACbYCr);
        case(OSDHANDLER_OSD_LAYOUT_CbYCrA):
            return(FAPI_VISCALE_OSD_LAYOUT_CbYCrA);
        case(OSDHANDLER_UNKNOWN_OSD_LAYOUT):
        default:
            return(FAPI_VISCALE_UNKNOWN_OSD_LAYOUT);
    }
}

/*!
*****************************************************************************
** \brief   Returns that internal OSDHANDLER_OsdCpParamsT structure that is
**          related to the given qualifier.
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
**
** \return
**          -   Pointer to the internal OSDHANDLER_OsdCpParamsT structures on
**              success.
**          -   NULL if the qualifier is invalid.
**
*****************************************************************************
*/
/* 21c7d1dc - complete */
OSDHANDLER_OsdCpParamsT* osdhandlerGetOsdCpParams(const uint32_t layerId)
{
#if OSDHANDLER_USE_VIRTUAL_LAYERS
    /*Virtual OSD layers*/
    if (layerId >> 16)
    {
        return(osdvirtualGetOsdCpParams(layerId));
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    /*HW OSD layers*/
    switch(layerId)
    {
        case(1):
            return &osdhandlerOsd1Params;
        case(2):
            return &osdhandlerOsd2Params;
        case(3):
            return &osdhandlerCpParams;
        default:
            return NULL;
    }
}

/*!
*****************************************************************************
** \brief   Returns the number of bits per pixel for the given
**          OSDHANDLER_OsdCpParamsT structure.
**
** \param   osdCpParamsPtr  Covers the colour mode that indicates the count of
**                          bits per pixel.
**
** \return
**          -   Count of bits per pixel on success.
**          -   0 if the mode is unknown or if a NULL pointer is passed.
**
*****************************************************************************
*/
/* 21c7d214 - complete */
uint32_t osdhandlerGetBitsPerPixel
                                (const OSDHANDLER_OsdCpParamsT* osdCpParamsPtr)
{
    if(osdCpParamsPtr == NULL)
    {
        return(0);
    }

    if (osdCpParamsPtr == &osdhandlerCpParams)
    {
        switch (osdCpParamsPtr->scalerParams.cpMode)
        {
            case(FAPI_VISCALE_CURSOR_MODE_1BIT):
                return(1);
            case(FAPI_VISCALE_CURSOR_MODE_2BIT):
                return(2);
            case(FAPI_VISCALE_CURSOR_MODE_4BIT):
                return(4);
            case(FAPI_VISCALE_CURSOR_MODE_8BIT):
                return(8);
            case(FAPI_VISCALE_UNKNOWN_CURSOR_MODE):
            default:
                return(0);
        }
    }
    else
    {
        switch (osdCpParamsPtr->scalerParams.osdMode)
        {
            case (FAPI_VISCALE_OSD_MODE_32_24BIT):
                return(32);
            case (FAPI_VISCALE_OSD_MODE_5551):
                return(16);
            case (FAPI_VISCALE_OSD_MODE_4444):
                return(16);
            case (FAPI_VISCALE_OSD_MODE_16BIT):
                return(16);
            case (FAPI_VISCALE_OSD_MODE_CLUT_8BIT):
                return(8);
            case (FAPI_VISCALE_OSD_MODE_CLUT_4BIT):
                return(4);
            case (FAPI_VISCALE_UNKNOWN_OSD_MODE):
            default:
                return(0);
        }
    }
}

/*!
********************************************************************************
** \brief   Initializes a given OSDHANDLER_OsdCpParamsT structure and prepares
**          it for further usage.
**
**          - The internal resoultion of the plane is set up (each line is a
**            multiple of 128 bytes).
**          - Memory is allocated and aligned to an 1 KiB address if no static
**            memory is used.
**          - Static memory is used if there is a non-null pointer passed through
**            the memoryBasePtr. The given address indicates the memory base
**            for the OSD memory then.
**          - The related OSD plane is filled with the 'fillColour' from
**            the structure referenced by osdParamsPtr.
**
** \note    Lint error 923 temporarily disabled (3 calls) within function.
**          Casts from type to type are mandatory here for pointer
**          arithmetics.
**
** \param osdParamsPtr  The data structure that contains all information that is
**                      needed for the initialization (such as scaling factor,
**                      output resolution, etc.) and all data that are going to
**                      be initialized (such as internal resolution,
**                      memory pointer, picture base address).
** \param memoryBasePtr Memory is allocated dynamically if this pointer is NULL.
**                      Otherwise the memory referenced by this pointer will be
**                      used as OSD memory.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_BAD_PARAMETER for following reasons:
**                  -   the passed argument is NULL.
**                  -   the fill colour has too many bits in order to fit
**                      for the specified colour mode.
**                  -   the osdParamsPtr is actually Cursor Plane related.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the OSD is driven in an unspecified colour mode
**          - #OSDHANDLER_ERR_OUT_OF_MEMORY
**              if there was not enough memory available
**              for allocation.
**
** \sa
**          - osdhandlerSetUpCursorPlane()
**
********************************************************************************
*/
/* 21c7e5f4 - complete */
int32_t osdhandlerSetUpOsdPlane(OSDHANDLER_OsdCpParamsT* osdParamsPtr,
                                uint8_t* memoryBasePtr)
{
    uint32_t  bpp;
    uint32_t  pic_h_res;
    uint32_t  pic_v_res;
    uint32_t  pic_size;
    uint8_t*  base_ptr;

    if(osdParamsPtr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    pic_h_res = osdParamsPtr->scalerParams.inputWindowWidth;
    pic_v_res = osdParamsPtr->scalerParams.inputWindowHeight;

    bpp = osdhandlerGetBitsPerPixel(osdParamsPtr);
    if(bpp == 0)
    {
        return(OSDHANDLER_ERR_BAD_COLOUR_MODE);
    }
    if (((bpp < 32) && (osdParamsPtr->fillColour >> bpp))
    ||  (osdParamsPtr == &osdhandlerCpParams))
    {
        // bad fill colour or bad argument
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }

    // one line must allocate a multiple of 128 bytes:
    // go above for the internal picture width:
    if (pic_h_res % (1024 / bpp))
    {
        // pic_h_res = ((pic_h_res / (1024 / bpp)) + 1) * (1024 / bpp);
        pic_h_res += (1024 / bpp) - (pic_h_res % (1024 / bpp));
    }
    // pic_v_res must be a multiple of 2
    if (pic_v_res % 2)
    {
        pic_v_res++;
    }
    osdParamsPtr->scalerParams.inputPicWidth  = pic_h_res;
    osdParamsPtr->scalerParams.inputPicHeight = pic_v_res;

    if((osdParamsPtr->isMemoryDynamic)
     &&(osdParamsPtr->allocatedMemPtr != NULL))
    {
        FAPI_SYS_FREE(osdParamsPtr->allocatedMemPtr);
        osdParamsPtr->allocatedMemPtr = NULL;
    }

    pic_size = (pic_h_res * pic_v_res * bpp) >> 3;

    if(memoryBasePtr)
    {
        base_ptr = memoryBasePtr;
        osdParamsPtr->isMemoryDynamic = 0;
    }
    else
    {
        // base_ptr needs to be 1 KiB aligned:
        base_ptr = (uint8_t*)
                    FAPI_SYS_MALLOC(pic_size + 1024);
        osdParamsPtr->isMemoryDynamic = 1;
    }
    osdParamsPtr->allocatedMemPtr = base_ptr;
    if(base_ptr == NULL)
    {
        return(OSDHANDLER_ERR_OUT_OF_MEMORY);
    }
    /*lint -save -e923 */
    if((uint32_t)base_ptr % 1024)
    {
        base_ptr += (1024 - (((uint32_t)base_ptr) % 1024));
    }
    osdParamsPtr->scalerParams.picBase = (uint32_t)base_ptr;

    osdhandlerFill(&osdParamsPtr->scalerParams, bpp, osdParamsPtr->fillColour);

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Fills a whole OSD/CP with a given colour.
**
** \note    Make sure that the passed scalerParamsPtr is not NULL.
**          Otherwise the function will abort.
**
** \note    Lint error 923 temporarily disabled (1 call) within function.
**          Cast from type to type is mandatory here for pointer
**          arithmetic.
**
** \param   osdParamsPtr    The data structure that contains all information that is
**                          needed for the initialization (such as scaling factor,
**                          output resolution, etc.) and all data that are going to
**                          be initialized (such as internal resolution,
**                          memory pointer, picture base address).
** \param   bpp             Amount of bits that are needed to represent
**                          the colour of a given pixel.
** \param   colour          Colour code of a single pixel that shall be used
**                          for filling the whole picture.
**
*****************************************************************************
*/
/* 21c7e438 - complete */
void osdhandlerFill (const FAPI_VISCALE_ScalerParamsT* osdParamsPtr,
                     const uint32_t bpp, uint32_t colour)
{
    uint32_t size;
    uint32_t* buf_ptr   = NULL;  // memory-pointer
    uint32_t  ii        = 0;     // temp variable
    uint32_t  colour32  = 0;     // 4-byte colour code that fills up the memory

    if ((osdParamsPtr == 0) || (bpp == 0))
    {
       return;
    }
    
    if ((uint32_t)osdParamsPtr->picBase % 4)
    {
       return;
    }

    // truncate unused bits:
    if (!(bpp >> 5))
    {
        colour &= (1 << bpp) - 1;
    }
    colour32 = colour;
    for (ii = ((32 / bpp) - 1); ii != 0; ii--)
    {
        colour32 = ((colour32 << bpp) | colour);
    }

    size = osdParamsPtr->inputPicWidth * 
       bpp / 32 * osdParamsPtr->inputPicHeight;
    ii = size;
    buf_ptr = (uint32_t*)osdParamsPtr->picBase;
    while(ii--)
    {
        *buf_ptr++ = colour32;
    }
    
    FAPI_SYS_FlushDataCache(osdParamsPtr->picBase, size*4);
}

/*!
*****************************************************************************
** \brief Gets the memory adress for a pixel at given coordinates for the
**          current LayerParams.
**
** \param   xx
**              x coordinate of the pixel whose memory address will be determined
** \param   yy
**              y coordinate of the pixel whose memory address will be determined
** \param   bpp
**              the count of bits per pixel
** \param  osd_params_ptr
**              layer parameter structure that will be examined for identifying
**              the memory address for the given coordinates
** \param   pixelBaseAddrPtr
**              will point to the 4byte-aligned address in front
**              of the pixel
** \param   pixelBitOffsetPtr
**              will point to the address bit offset since
**              the obtained memory address of the pixel may not be aligend to
**              4 bytes. This value will always be less than 32.
*****************************************************************************
*/
/* 21c7d2c4 - complete */
void osdhandlerGetPixelAddress(const uint32_t xx,
                               const uint32_t yy,
                               const uint32_t bpp,
                               OSDHANDLER_OsdCpParamsT* osd_params_ptr,
                               uint32_t* pixelBaseAddrPtr,
                               uint32_t* pixelBitOffsetPtr)
{
    if((pixelBaseAddrPtr == NULL) ||
       (pixelBitOffsetPtr == NULL)||
       (osd_params_ptr == NULL))
    {
        return;
    }
    *pixelBaseAddrPtr = osd_params_ptr->scalerParams.picBase
            + ((yy * osd_params_ptr->scalerParams.inputPicWidth * bpp) >> 3)
            + ((xx * bpp) >> 3); // /8 ==> byte pointer
    *pixelBaseAddrPtr -= *pixelBaseAddrPtr % 4; //4-byte aligned address
    *pixelBitOffsetPtr = (xx * bpp) % 32;
    return;
}

//***************************************************************************
//***************************************************************************
//** Local Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief   Sets up system limitations for the OSDHANDLER.
*****************************************************************************
*/
static void osdhandlerSetUpSystemLimitations(FAPI_SYS_HandleT handle)
{
   FAPI_VISCALE_SystemModeEnumT  system_mode;

    system_mode = FAPI_VISCALE_GetSystemType(handle);
    
    switch(system_mode)
    {
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x2397P):
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x24P):
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x25P):
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x2997P):
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x30P):
            osdhandlerMaxHRES = 1920;
            osdhandlerMaxVRES = 1080;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x50I):
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x5994I):
        case(FAPI_VISCALE_SYSTEM_MODE_1920x1080x60I):
            osdhandlerMaxHRES = 1920;
            osdhandlerMaxVRES =  540;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x2397P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x24P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x25P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x2997P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x30P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x50P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x5994P):
        case(FAPI_VISCALE_SYSTEM_MODE_1280x720x60P):
            osdhandlerMaxHRES = 1280;
            osdhandlerMaxVRES =  720;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_720x576x50I):
            osdhandlerMaxHRES = 1440;
            osdhandlerMaxVRES =  288;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_720x576x50P):
            osdhandlerMaxHRES =  720;
            osdhandlerMaxVRES =  576;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_720x480x5994I):
            osdhandlerMaxHRES = 1440;
            osdhandlerMaxVRES =  240;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_720x480x5994P):
            osdhandlerMaxHRES =  720;
            osdhandlerMaxVRES =  480;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_LCD_640x480x50P_LQ080V3DG01):
            osdhandlerMaxHRES =  640;
            osdhandlerMaxVRES =  480;
            break;
        case(FAPI_VISCALE_SYSTEM_MODE_LCD_1024x768x50P_SVA150XG10TB):
            osdhandlerMaxHRES =  1024;
            osdhandlerMaxVRES =   768;
            break;
        case(FAPI_VISCALE_UNKNOWN_SYSTEM_MODE):
        default:
            break;
    }
    return;
}

//***************************************************************************
//***************************************************************************
//** API Functions
//***************************************************************************
//***************************************************************************


/* 21c7d328 - complete */
FAPI_VISCALE_EncoderEnumT osdhandlerGetEncoderType(int a)
{   
   FAPI_VISCALE_EncoderEnumT res = FAPI_VISCALE_UNKNOWN_ENCODER;
   
   switch (a)
   {
   case 1:
      res = FAPI_VISCALE_ENCODER_PAL;
      break;
   case 2:
      res = FAPI_VISCALE_ENCODER_NTSC;
      break;      
   case 3:
      res = FAPI_VISCALE_ENCODER_SECAM;      
      break;      
   }
   
   return res;
}


/*!
*****************************************************************************
** \brief   Initializes the OSDHANDLER.
**
** This function initializes the osdhandler for given parameters. It allocates
** the OSD handles of the Viscale driver. If one of the OSDs is already in use
** by another application the OSDHANDLER will override the initialization of
** that OSD but it will return an error code as soon as you try to operate
** on it (see #OSDHANDLER_ERR_NO_OSD_HANDLE).
**
** \note    Please make sure that FAPEX_VIOUT_Init() has been called before
**          the OSDHANDLER is used!
**
** \param   initParamsPtr
**              Points to the init parameters such as which OSDs have to
**              be opened, in which colour mode they have to be started,
**              and a colour lookup table for each layer.
** \param   errorCodePtr
**              Will receive error codes related to the allocation
**              of the requested hardware layers. If one of the hardware
**              layers that have been requested could not be opened by
**              the underlying driver, a corresponding error bit will be set.
**              You can easily extract the information whether an error
**              occured while opening a specific layer by combining its
**              corresponding error message with the errorCode by an logical
**              AND.
**              Possible error codes are:
**              - #OSDHANDLER_ERR_CODE_OSD1_OPEN
**              - #OSDHANDLER_ERR_CODE_OSD2_OPEN
**              - #OSDHANDLER_ERR_CODE_CP_OPEN
**              - #OSDHANDLER_ERR_CODE_OSD1_STOP
**              - #OSDHANDLER_ERR_CODE_OSD1_CLOSE
**              - #OSDHANDLER_ERR_CODE_OSD2_STOP
**              - #OSDHANDLER_ERR_CODE_OSD2_CLOSE
**              - #OSDHANDLER_ERR_CODE_CP_STOP
**              - #OSDHANDLER_ERR_CODE_CP_CLOSE
**              .
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK:
**              Initialization was successful - even if one or more OSDs
**              have been overridden as they are already in use
**              In order to see if any OSDs have not
**              been allocated you will have to examine the passed
**              errorCodePtr.
**          - #OSDHANDLER_ERR_ALREADY_INITIALIZED
**              if the OSDHANDLER has already been initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed. Possible reasons:
**              -   The passed pointer is NULL.
**              -   The layout mode of one of the used OSDs is not valid. <br>
**              .
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the OSD is driven in an unspecified colour mode.
**
** \sa
**          - OSDHANDLER_Exit()
**
*****************************************************************************
*/
/* 21c7fbe4 - nearly complete */
int32_t OSDHANDLER_Init(const OSDHANDLER_InitParamsT* initParamsPtr,
                        uint32_t* errorCodePtr)
{
    uint32_t  ii;
    int32_t   result;

    FAPI_VISCALE_OpenParamsT viscaleParams;
    int32_t res = 0;

    if (osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_ALREADY_INITIALIZED);
    }

    if(initParamsPtr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

    memset(&viscaleParams, 0, sizeof(FAPI_VISCALE_OpenParamsT));
    
    memset(&osdhandlerOsd1Params, 0, sizeof(OSDHANDLER_OsdCpParamsT));
    memset(&osdhandlerOsd2Params, 0, sizeof(OSDHANDLER_OsdCpParamsT));
    memset(&osdhandlerCpParams,   0, sizeof(OSDHANDLER_OsdCpParamsT));

    osdhandlerViencHdHandle = initParamsPtr->viencHandle;
    
    if (initParamsPtr->viencHandle == 0)
    {
       return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    
    // ************* OSD 1 Initialization *************
    if (initParamsPtr->osd1InitParams.inUse)
    {
       viscaleParams.version = FAPI_VISCALE_VERSION;
       viscaleParams.scalerType = FAPI_VISCALE_SCALER_OSD1;
       viscaleParams.encoderType = osdhandlerGetEncoderType(initParamsPtr->encoderType);
              
       osdhandlerOsd1Params.fd = FAPI_VISCALE_Open(&viscaleParams, &res);
       osdhandlerOsd1Params.allocatedMemPtr = 0;
       osdhandlerOsd1Params.fillColour = 0;
       osdhandlerOsd1Params.colourMode = initParamsPtr->osd1InitParams.colourMode;
       osdhandlerOsd1Params.osdLayout = initParamsPtr->osd1InitParams.osdLayout;
       
       osdhandlerOsd1Params.scalerParams.osdMode =
           osdhandlerGetOsdColourMode(initParamsPtr->osd1InitParams.colourMode);
       osdhandlerOsd1Params.scalerParams.osdLayout =
           osdhandlerGetOsdLayout(initParamsPtr->osd1InitParams.osdLayout);
       
       if (osdhandlerOsd1Params.fd == 0)
       {
          if(errorCodePtr != NULL)
          {
              *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_OPEN;
          }
       }
       else
       {
          if (osdhandlerGetBitsPerPixel(&osdhandlerOsd1Params) == 0)
          {
#if 1
             if(errorCodePtr != NULL)
             {
                 *errorCodePtr |= OSDHANDLER_Exit();
             }
             else
             {
                 (void)OSDHANDLER_Exit();
             }
             return(OSDHANDLER_ERR_BAD_COLOUR_MODE);             
#else
             goto label_21c80060;
#endif
          }

          if (osdhandlerOsd1Params.scalerParams.osdLayout == -1)
          {
             goto OSDHANDLER_Init_ERROR;
          }

          if (initParamsPtr->osd1InitParams.defaultClutPtr != 0)
          {
             /* set Colour LUT */
             for (ii = 0; ii < 256; ii++)
             {
                osdhandlerOsd1Params.scalerParams.colourLut[ii] =
                          *(initParamsPtr->osd1InitParams.defaultClutPtr + ii);
                 osdhandlerOsd1Params.clut[ii] =
                           *(initParamsPtr->osd1InitParams.defaultClutPtr + ii);
             }
          }

          osdhandlerOsd1Params.scalerParams.useGlobalAlpha = 
             initParamsPtr->osd1InitParams.useGlobalAlpha;
          osdhandlerOsd1Params.scalerParams.globalAlpha = 
             initParamsPtr->osd1InitParams.globalAlpha;
          osdhandlerOsd1Params.scalerParams.layerEnable = 0;
          osdhandlerOsd1Params.scalerParams.frameField = 0;                    
          osdhandlerOsd1Params.scalerParams.inputWindowX0 = 0; //1100
          osdhandlerOsd1Params.scalerParams.inputWindowY0 = 0; //1104
          osdhandlerOsd1Params.scalerParams.inputPicWidth = 0; //1092
          osdhandlerOsd1Params.scalerParams.inputPicHeight = 0; //1096
          osdhandlerOsd1Params.scalerParams.outputWindowX0 = 0; //1116
          osdhandlerOsd1Params.scalerParams.outputWindowY0 = 0; //1120
          osdhandlerOsd1Params.scalerParams.outputWindowWidth = 0; //1124
          osdhandlerOsd1Params.scalerParams.outputWindowHeight = 0; //1128
          
          result = FAPI_VISCALE_SetScalerToHdEncoder(osdhandlerOsd1Params.fd,
                osdhandlerViencHdHandle);
          
          if(result != 0)
          {
              goto OSDHANDLER_Init_ERROR;
          }
       }
    }

    // ************* OSD 2 Initialization *************
    if (initParamsPtr->osd2InitParams.inUse)
    {
       viscaleParams.version = FAPI_VISCALE_VERSION;
       viscaleParams.scalerType = FAPI_VISCALE_SCALER_OSD2;
       viscaleParams.encoderType = osdhandlerGetEncoderType(initParamsPtr->encoderType);
              
       osdhandlerOsd2Params.fd = FAPI_VISCALE_Open(&viscaleParams, &res);
       osdhandlerOsd2Params.allocatedMemPtr = 0;
       osdhandlerOsd2Params.fillColour = 0;
       osdhandlerOsd2Params.colourMode = initParamsPtr->osd2InitParams.colourMode;
       osdhandlerOsd2Params.osdLayout = initParamsPtr->osd2InitParams.osdLayout;
       
       osdhandlerOsd2Params.scalerParams.osdMode =
           osdhandlerGetOsdColourMode(initParamsPtr->osd2InitParams.colourMode);
       osdhandlerOsd2Params.scalerParams.osdLayout =
           osdhandlerGetOsdLayout(initParamsPtr->osd2InitParams.osdLayout);
       
       if (osdhandlerOsd2Params.fd == 0)
       {
          if(errorCodePtr != NULL)
          {
              *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_OPEN;
          }
       }
       else
       {
          if (osdhandlerGetBitsPerPixel(&osdhandlerOsd2Params) == 0)
          {
#if 1
             if(errorCodePtr != NULL)
             {
                 *errorCodePtr |= OSDHANDLER_Exit();
             }
             else
             {
                 (void)OSDHANDLER_Exit();
             }
             return(OSDHANDLER_ERR_BAD_COLOUR_MODE);             
#else
             goto label_21c80060;
#endif
          }

          if (osdhandlerOsd2Params.scalerParams.osdLayout == -1)
          {
             goto OSDHANDLER_Init_ERROR;
          }

          if (initParamsPtr->osd2InitParams.defaultClutPtr != 0)
          {
             /* set Colour LUT */
             for (ii = 0; ii < 256; ii++)
             {
                osdhandlerOsd2Params.scalerParams.colourLut[ii] =
                          *(initParamsPtr->osd2InitParams.defaultClutPtr + ii);
                 osdhandlerOsd2Params.clut[ii] =
                           *(initParamsPtr->osd2InitParams.defaultClutPtr + ii);
             }
          }

          osdhandlerOsd2Params.scalerParams.useGlobalAlpha = 
             initParamsPtr->osd2InitParams.useGlobalAlpha;
          osdhandlerOsd2Params.scalerParams.globalAlpha = 
             initParamsPtr->osd2InitParams.globalAlpha;
          osdhandlerOsd2Params.scalerParams.layerEnable = 0;
          osdhandlerOsd2Params.scalerParams.frameField = 0;                    
          osdhandlerOsd2Params.scalerParams.inputWindowX0 = 0; //1100
          osdhandlerOsd2Params.scalerParams.inputWindowY0 = 0; //1104
          osdhandlerOsd2Params.scalerParams.inputPicWidth = 0; //1092
          osdhandlerOsd2Params.scalerParams.inputPicHeight = 0; //1096
          osdhandlerOsd2Params.scalerParams.outputWindowX0 = 0; //1116
          osdhandlerOsd2Params.scalerParams.outputWindowY0 = 0; //1120
          osdhandlerOsd2Params.scalerParams.outputWindowWidth = 0; //1124
          osdhandlerOsd2Params.scalerParams.outputWindowHeight = 0; //1128
          
          result = FAPI_VISCALE_SetScalerToHdEncoder(osdhandlerOsd2Params.fd,
                osdhandlerViencHdHandle);
          
          if(result != 0)
          {
              goto OSDHANDLER_Init_ERROR;
          }
       }
    }

    // ************* Cursor Plane Initialization *************
    if (initParamsPtr->cpInitParams.inUse)
    {
       viscaleParams.version = FAPI_VISCALE_VERSION;
       viscaleParams.scalerType = FAPI_VISCALE_SCALER_CURSOR_PLANE;
       viscaleParams.encoderType = osdhandlerGetEncoderType(initParamsPtr->encoderType);
              
       osdhandlerCpParams.fd = FAPI_VISCALE_Open(&viscaleParams, &res); 
       osdhandlerCpParams.allocatedMemPtr = 0;
       osdhandlerCpParams.fillColour = 0;
       osdhandlerCpParams.colourMode = initParamsPtr->cpInitParams.colourMode;
       osdhandlerCpParams.osdLayout = initParamsPtr->cpInitParams.osdLayout;
       
       osdhandlerCpParams.scalerParams.cpMode =
          osdhandlerGetCpColourMode(initParamsPtr->cpInitParams.colourMode);
       osdhandlerCpParams.scalerParams.osdLayout =
           osdhandlerGetOsdLayout(initParamsPtr->cpInitParams.osdLayout);
       
       if (osdhandlerCpParams.fd == 0)
       {
          if(errorCodePtr != NULL)
          {
              *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_OPEN;
          }
       }
       else
       {
          if (osdhandlerGetBitsPerPixel(&osdhandlerCpParams) == 0)
          {
#if 1
             if(errorCodePtr != NULL)
             {
                 *errorCodePtr |= OSDHANDLER_Exit();
             }
             else
             {
                 (void)OSDHANDLER_Exit();
             }
             return(OSDHANDLER_ERR_BAD_COLOUR_MODE);             
#else
             goto label_21c80060;
#endif
          }

          if (osdhandlerCpParams.scalerParams.osdLayout != 4)
          {
             goto OSDHANDLER_Init_ERROR;
          }

          if (initParamsPtr->cpInitParams.defaultClutPtr != 0)
          {
             /* set Colour LUT */
             for (ii = 0; ii < 256; ii++)
             {
                osdhandlerCpParams.scalerParams.colourLut[ii] =
                          *(initParamsPtr->cpInitParams.defaultClutPtr + ii);
                 osdhandlerCpParams.clut[ii] =
                           *(initParamsPtr->cpInitParams.defaultClutPtr + ii);
             }
          }

          osdhandlerCpParams.scalerParams.useGlobalAlpha = 
             initParamsPtr->cpInitParams.useGlobalAlpha;
          osdhandlerCpParams.scalerParams.globalAlpha = 
             initParamsPtr->cpInitParams.globalAlpha;
          osdhandlerCpParams.scalerParams.layerEnable = 0;
          osdhandlerCpParams.scalerParams.cpTileNumX = 1;
          osdhandlerCpParams.scalerParams.cpTileNumY = 1;
          osdhandlerCpParams.scalerParams.frameField = 0;   
          osdhandlerCpParams.scalerParams.hilightOnOff = 0;
          osdhandlerCpParams.scalerParams.inputWindowX0 = 0; //1100
          osdhandlerCpParams.scalerParams.inputWindowY0 = 0; //1104
          osdhandlerCpParams.scalerParams.inputPicWidth = 0; //1092
          osdhandlerCpParams.scalerParams.inputPicHeight = 0; //1096
          osdhandlerCpParams.scalerParams.outputWindowX0 = 0; //1116
          osdhandlerCpParams.scalerParams.outputWindowY0 = 0; //1120
          osdhandlerCpParams.scalerParams.outputWindowWidth = 0; //1124
          osdhandlerCpParams.scalerParams.outputWindowHeight = 0; //1128
          
          result = FAPI_VISCALE_SetScalerToHdEncoder(osdhandlerCpParams.fd,
                osdhandlerViencHdHandle);
          
          if(result != 0)
          {
              goto OSDHANDLER_Init_ERROR;
          }
       }
    }

    if (osdhandlerOsd1Params.fd != 0)
    {
       osdhandlerSetUpSystemLimitations(osdhandlerOsd1Params.fd);
    }
    else if (osdhandlerOsd2Params.fd != 0)
    {
       osdhandlerSetUpSystemLimitations(osdhandlerOsd2Params.fd);
    }
    else if (osdhandlerCpParams.fd != 0)
    {
       osdhandlerSetUpSystemLimitations(osdhandlerCpParams.fd);
    }
    
    osdhandlerInitialized = 1;
    return(FAPI_OK);

OSDHANDLER_Init_ERROR:
    if(errorCodePtr != NULL)
    {
        *errorCodePtr |= OSDHANDLER_Exit();
    }
    else
    {
        (void)OSDHANDLER_Exit();
    }
    return(OSDHANDLER_ERR_BAD_PARAMETER);
    
#if 0
label_21c80060:
    if(errorCodePtr != NULL)
    {
        *errorCodePtr |= OSDHANDLER_Exit();
    }
    else
    {
        (void)OSDHANDLER_Exit();
    }
    return(OSDHANDLER_ERR_BAD_COLOUR_MODE);             
#endif
}

/*!
*****************************************************************************
** \brief   Exits the OSDHANDLER. All Layers are stopped,
**          all handles and resources are released.
**
** This function shutdowns the OSDHANDLER. It closes all OSDs, frees
** allocated memory and exits the Viscale driver if it was initialized
** by the OSDHANDLER previously.
**
** \return  Error code that indicates which of the underlying driver calls
**          may have caused problems during exiting. If no errors occured,
**          the error code equals FAPI_OK. Possible error codes are:
**          - #OSDHANDLER_ERR_CODE_OSD1_STOP
**          - #OSDHANDLER_ERR_CODE_OSD1_CLOSE
**          - #OSDHANDLER_ERR_CODE_OSD2_STOP
**          - #OSDHANDLER_ERR_CODE_OSD2_CLOSE
**          - #OSDHANDLER_ERR_CODE_CP_STOP
**          - #OSDHANDLER_ERR_CODE_CP_CLOSE
**
** \sa
**          - OSDHANDLER_Init()
**
*****************************************************************************
*/
/* 21c7fa6c - complete */
uint32_t OSDHANDLER_Exit(void)
{
    uint32_t errorCode = FAPI_OK;
    int32_t  result;

    // close OSD1:
    if(osdhandlerOsd1Params.fd != 0)
    {
        result = FAPI_VISCALE_Stop(osdhandlerOsd1Params.fd);
        
        if(result != 0)
        {
            errorCode |= OSDHANDLER_ERR_CODE_OSD1_STOP;
        }

        result = FAPI_VISCALE_Close(osdhandlerOsd1Params.fd);
        
        if(result != 0)
        {
            errorCode |= OSDHANDLER_ERR_CODE_OSD1_CLOSE;
        }
        osdhandlerOsd1Params.fd = 0;        
    }

    if (osdhandlerOsd1Params.isMemoryDynamic)
    {
       if (osdhandlerOsd1Params.allocatedMemPtr != 0)
       {
          FAPI_SYS_FREE(osdhandlerOsd1Params.allocatedMemPtr);
          osdhandlerOsd1Params.allocatedMemPtr = 0;
       }
    }

    // close OSD2:
    if(osdhandlerOsd2Params.fd != 0)
    {
        result = FAPI_VISCALE_Stop(osdhandlerOsd2Params.fd);
        
        if(result != 0)
        {
            errorCode |= OSDHANDLER_ERR_CODE_OSD2_STOP;
        }

        result = FAPI_VISCALE_Close(osdhandlerOsd2Params.fd);
        
        if(result != 0)
        {
            errorCode |= OSDHANDLER_ERR_CODE_OSD2_CLOSE;
        }
        osdhandlerOsd2Params.fd = 0;
    }

    if (osdhandlerOsd2Params.isMemoryDynamic)
    {
       if (osdhandlerOsd2Params.allocatedMemPtr != 0)
       {
          FAPI_SYS_FREE(osdhandlerOsd2Params.allocatedMemPtr);
          osdhandlerOsd2Params.allocatedMemPtr = 0;
       }
    }

    // close cursor plane:
    if(osdhandlerCpParams.fd != 0)
    {
        result = FAPI_VISCALE_Stop(osdhandlerCpParams.fd);
        
        if(result != 0)
        {
            errorCode |= OSDHANDLER_ERR_CODE_CP_STOP;
        }

        result = FAPI_VISCALE_Close(osdhandlerCpParams.fd);
        
        if(result != 0)
        {
            errorCode |= OSDHANDLER_ERR_CODE_CP_CLOSE;
        }
        osdhandlerCpParams.fd = 0;
    }

    if (osdhandlerCpParams.isMemoryDynamic)
    {
       if (osdhandlerCpParams.allocatedMemPtr != 0)
       {
          FAPI_SYS_FREE(osdhandlerCpParams.allocatedMemPtr);
          osdhandlerCpParams.allocatedMemPtr = 0;
       }
    }

    // Close virtual layer groups. If nothing to close, ignore errors.
#if OSDHANDLER_USE_VIRTUAL_LAYERS
    (void)OSDHANDLER_StopVirtualLayerGroup(0x00010000UL);
    (void)OSDHANDLER_StopVirtualLayerGroup(0x00020000UL);
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osdhandlerInitialized = 0;
    return (errorCode);
}

/*!
*****************************************************************************
** \brief   Gives information whether the OSDHANDLER is initialized.
**
** \return  Flag that indicates whether the OSDHANDLER is initialized:
**          -   0 if the OSDHANDLER is not initialized.
**          -   1 if the OSDHANDLER is initialized.
**
** \sa
**          - OSDHANDLER_Init()
**          - OSDHANDLER_Exit()
**
*****************************************************************************
*/
/* 21c7d354 - complete */
uint32_t OSDHANDLER_IsInitialized(void)
{
    return(osdhandlerInitialized);
}


/*!
*****************************************************************************
** \brief   Starts one OSD/CP layer internally with given dimensions at a given
**          position.
**
** The internal structures of the OSD/CP will be prepared and are made available
** for drawing operations. The layer will not be displayed on the Video Output
** yet. In order to make a layer visible, call OSDHANDLER_ShowLayer() after
** having modified its content.
**
** For virtual layers make sure that the following parameters match with the
** corresponding hardware layer: position, input dimensions, output dimensions
** and frame/field mode.
** If you have set up the output dimensions of the hardware layer with 0
** (which means that the layer will not be scaled and the output dimension is
** automatically set to the input dimension of the layer), you may set the output
** dimension of the virtual layer to both, the input dimension or to 0.
**
** \note    Downscaling more than factor 2 is not possible. If you try though,
**          the picture will be cut off on the bottom side in order
**          to fit for the passed dimensions. However, there might be some
**          lines missing on the bottom of the OSD then.
**
** \note    The inputWidth should be at least 384 pixels for 4-bit mode and
**          256 pixels for the other colour modes. Otherwise the picture
**          may result in fragments due to hardware limitations.
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
** \param   startParamsPtr
**              Points to a structure that specifies input and output
**              resolutions, the position and the frame/field mode of the layer.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_STOP
**              - #OSDHANDLER_ERR_CODE_OSD2_STOP
**              - #OSDHANDLER_ERR_CODE_CP_STOP
**              - #OSDHANDLER_ERR_CODE_OSD1_START
**              - #OSDHANDLER_ERR_CODE_OSD2_START
**              - #OSDHANDLER_ERR_CODE_CP_START
**              - #OSDHANDLER_ERR_CODE_OSD1_RESIZE
**              - #OSDHANDLER_ERR_CODE_OSD2_RESIZE
**              - #OSDHANDLER_ERR_CODE_CP_RESIZE
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success. If there occured errors
**              during calls to the underlying driver, these errors
**              will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED if the OSDHANDLER is not
**              initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER if a passed pointer is NULL.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE for following reasons:
**              -   The OSDHANDLER did not allocate the corresponding handle of
**                  the hardware OSD/CP at initialization.
**              -   The corresponding HW layer of the virtual layer is not
**                  allocated by the OSDHANDLER.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE if the colour mode of the
**              OSD is bad. Set up the colour mode by
**              OSDHANDLER_SetColourMode().
**          - #OSDHANDLER_ERR_OUT_OF_SIZE if it is attempted to exceed
**              the maximum size of the layer. Possible reasons are:
**              -   The input or output resolution of an OSD layer exceeds the
**                  maximum possible resolution (OSDHANDLER_MAX_(HRES|VRES)).
**              -   The dimensions of the Cursor Plane would allocate more than
**                  16 KiB. <br>
**              -   The dimensions of a virtual layer do not fit those of
**                  the corresponding hardware layer.
**          - #OSDHANDLER_ERR_OUT_OF_MEMORY if there was not enough memory
**              available for allocation in order to drive the OSD at the given
**              resolution and in the current colour mode.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED if the corresponding HW layer
**              of the virtual layer has not been started yet.
**
** \sa
**          - OSDHANDLER_StopLayer()
**          - OSDHANDLER_ShowLayer()
**          - OSDHANDLER_HideLayer()
**
*****************************************************************************
*/
/* 21c7f4d4 - complete */
int32_t OSDHANDLER_StartLayer(const uint32_t layerId,
                              const OSDHANDLER_StartParamsT* startParamsPtr,
                              uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*  osd_cp_params_ptr = NULL;
    FAPI_VISCALE_SystemModeEnumT systemMode;
    int32_t   result;

    if (!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(startParamsPtr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if (osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    
    if (0 == osdhandlerGetBitsPerPixel(osd_cp_params_ptr))
    {
       return OSDHANDLER_ERR_BAD_COLOUR_MODE;
    }
    
    if ((startParamsPtr->inputWidth > 1920) ||
          (startParamsPtr->inputHeight > 1080) ||
          (startParamsPtr->outputWidth > 1920) ||
          (startParamsPtr->outputHeight > 1080))
    {
       return OSDHANDLER_ERR_OUT_OF_SIZE;
    }
    
    systemMode = FAPI_VISCALE_GetSystemType(osd_cp_params_ptr->fd);
    
    // virtual OSD layers:
#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(layerId >> 16)
    {
        return (osdvirtualStartLayer(layerId, osd_cp_params_ptr, startParamsPtr));
    }
    else
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    // hardware OSD/CP layers:
    {
        // ************** start the plane  **********************
       OSDHANDLER_StartParamsT sp;
       
       memcpy(&sp, startParamsPtr, sizeof(OSDHANDLER_StartParamsT));
       
       sp.outputWidth = (startParamsPtr->outputWidth != 0)?
             startParamsPtr->outputWidth:
             sp.inputWidth;
       
       sp.outputHeight = (startParamsPtr->outputHeight != 0)?
             startParamsPtr->outputHeight:
             (startParamsPtr->frameBased == 0)?
                    sp.inputHeight / 2: sp.inputHeight;
             
       if ((systemMode == FAPI_VISCALE_SYSTEM_MODE_720x576x50I) || 
             (systemMode == FAPI_VISCALE_SYSTEM_MODE_720x480x5994I))
       {
          sp.xPos *= 2;
          sp.outputWidth *= 2;
       }
       
       if (sp.outputWidth > osdhandlerMaxHRES)
       {
          sp.outputWidth = osdhandlerMaxHRES;
       }
       
       if (sp.outputHeight > osdhandlerMaxVRES)
       {
          sp.outputHeight = osdhandlerMaxVRES;
       }
       
       if ((sp.xPos + sp.outputWidth) > osdhandlerMaxHRES)
       {
          sp.xPos = osdhandlerMaxHRES - sp.outputWidth;
       }
          
       if ((sp.yPos + sp.outputHeight) > osdhandlerMaxVRES)
       {
          sp.yPos = osdhandlerMaxVRES - sp.outputHeight;
       }
       
       result = FAPI_VISCALE_Stop(osd_cp_params_ptr->fd);
        
       if((result != 0) && (errorCodePtr != NULL))
       {
           if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_STOP;
           if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_STOP;
           if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_STOP;
       }
       
       osd_cp_params_ptr->scalerParams.layerEnable = 0;

       if ((osd_cp_params_ptr == &osdhandlerOsd1Params) ||
             (osd_cp_params_ptr == &osdhandlerOsd2Params))
       {
          osd_cp_params_ptr->scalerParams.outputWindowX0     = sp.xPos;
          osd_cp_params_ptr->scalerParams.outputWindowY0     = sp.yPos;
          osd_cp_params_ptr->scalerParams.inputWindowWidth   = sp.inputWidth;
          osd_cp_params_ptr->scalerParams.inputWindowHeight  = sp.inputHeight;
          osd_cp_params_ptr->scalerParams.outputWindowWidth  = sp.outputWidth;
          osd_cp_params_ptr->scalerParams.outputWindowHeight = sp.outputHeight;
          osd_cp_params_ptr->scalerParams.frameField     = (sp.frameBased) ? 1 : 0;
         
          result = osdhandlerSetUpOsdPlane(osd_cp_params_ptr, 
                sp.memoryBasePtr);
           
          if (result != 0)
          {
             return result;
          }           
          
          result = FAPI_VISCALE_Start(osd_cp_params_ptr->fd,
                 &osd_cp_params_ptr->scalerParams);
          
          if((result != 0) && (errorCodePtr != NULL))
          {
              if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_START;
              if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_START;
              if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_START;
          }

          result = FAPI_VISCALE_Resize(osd_cp_params_ptr->fd,
                &osd_cp_params_ptr->scalerParams);
          
          if((result != 0) && (errorCodePtr != NULL))
          {
              if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_RESIZE;
              if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_RESIZE;
              if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_RESIZE;
          }
       }
       else if (osd_cp_params_ptr == &osdhandlerCpParams)
       {
          uint32_t bpp;
          uint32_t pic_h_res;
          uint32_t pic_v_res;
          uint8_t* memoryBasePtr;
          
          memcpy(&sp, startParamsPtr, sizeof(OSDHANDLER_StartParamsT));

          if ((systemMode == FAPI_VISCALE_SYSTEM_MODE_720x576x50I) || 
                (systemMode == FAPI_VISCALE_SYSTEM_MODE_720x480x5994I))
          {
             sp.xPos *= 2;
             sp.inputWidth *= 2;
          }

          sp.outputWidth = sp.inputWidth;          
          sp.outputHeight = (sp.frameBased == 0)?
                sp.inputHeight / 2: sp.inputHeight;
          
          if ((sp.outputWidth > osdhandlerMaxHRES) ||
                (sp.outputHeight > osdhandlerMaxVRES))
          {
             return OSDHANDLER_ERR_OUT_OF_SIZE;
          }
          
          if ((sp.xPos + sp.outputWidth) > osdhandlerMaxHRES)
          {
             sp.xPos = osdhandlerMaxHRES - sp.outputWidth;
          }

          if ((sp.yPos + sp.outputHeight) > osdhandlerMaxVRES)
          {
             sp.yPos = osdhandlerMaxVRES - sp.outputHeight;
          }

          osd_cp_params_ptr->scalerParams.outputWindowX0     = sp.xPos;
          osd_cp_params_ptr->scalerParams.outputWindowY0     = sp.yPos;
          osd_cp_params_ptr->scalerParams.inputWindowWidth   = sp.inputWidth;
          osd_cp_params_ptr->scalerParams.inputWindowHeight  = sp.inputHeight;
          osd_cp_params_ptr->scalerParams.outputWindowWidth  = sp.outputWidth;
          osd_cp_params_ptr->scalerParams.outputWindowHeight = sp.outputHeight;
          osd_cp_params_ptr->scalerParams.frameField     = (sp.frameBased) ? 1 : 0;

          memoryBasePtr = startParamsPtr->memoryBasePtr;
          
          bpp = osdhandlerGetBitsPerPixel(&osdhandlerCpParams);
          
          if (bpp == 0)
          {
             return OSDHANDLER_ERR_BAD_COLOUR_MODE;
          }

          if ((bpp < 32) &&
                (osdhandlerCpParams.fillColour >> bpp))
          {
             return 0xffd6cd1f;
          }

          pic_h_res = osdhandlerCpParams.scalerParams.inputWindowWidth;          
          pic_v_res = osdhandlerCpParams.scalerParams.inputWindowHeight;
          
          if (pic_h_res % (32 / bpp))
          {
             pic_h_res += (32 / bpp) - (pic_h_res % (32 / bpp));
          }
          
          if (pic_v_res % 2)
          {
             pic_v_res++;
          }
                    
          unsigned pic_size = (pic_h_res * pic_v_res * bpp) >> 3;
          if (pic_size > 0x4000)
          {
             return OSDHANDLER_ERR_CP_16KB_EXCEEDED;
          }
          
          osdhandlerCpParams.scalerParams.inputPicWidth = pic_h_res;
          osdhandlerCpParams.scalerParams.inputPicHeight = pic_v_res;
          
          if ((osdhandlerCpParams.isMemoryDynamic) &&
                (osdhandlerCpParams.allocatedMemPtr != 0))
          {
             FAPI_SYS_FREE(osdhandlerCpParams.allocatedMemPtr);
             osdhandlerCpParams.allocatedMemPtr = 0;
          }
          
          if (memoryBasePtr != 0)
          {
             osdhandlerCpParams.isMemoryDynamic = 0;
          }
          else
          {
             memoryBasePtr = FAPI_SYS_MALLOC(pic_size + 4);
             osdhandlerCpParams.isMemoryDynamic = 1;             
          }
          
          osdhandlerCpParams.allocatedMemPtr = memoryBasePtr; 
          
          if (memoryBasePtr == 0)
          {
             return OSDHANDLER_ERR_OUT_OF_MEMORY;
          }

          /*lint -save -e923 */
          if((uint32_t)memoryBasePtr % 4)
          {
             memoryBasePtr += (4 - (((uint32_t)memoryBasePtr) % 4));
          }
          osdhandlerCpParams.scalerParams.picBase = (uint32_t)memoryBasePtr;
          
          osdhandlerFill(&osdhandlerCpParams.scalerParams,
                bpp, osdhandlerCpParams.fillColour);          
       }
       else
       {
          return 0xffd6cd1f;
       }
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Stops a layer.
**
** The layer is stopped. It is not visible on the Video Output any more
** and one will not be able to operate on that OSD/CP until
** OSDHANDLER_StartLayer() is called for the OSD/CP, again. If there was memory
** allocated previously for the usage of that OSD/CP, it is released.
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_STOP
**              - #OSDHANDLER_ERR_CODE_OSD2_STOP
**              - #OSDHANDLER_ERR_CODE_CP_STOP
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success. If there occured errors
**              during calls to the underlying driver, these errors
**              will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED if the OSDHANDLER is not
**              initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER if a passed pointer is NULL.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle
**              of the OSD/CP at initialization.
**
** \sa
**          - OSDHANDLER_StartLayer()
**          - OSDHANDLER_ShowLayer()
**          - OSDHANDLER_HideLayer()
**
*****************************************************************************
*/
/* 21c7f138 - complete */
int32_t OSDHANDLER_StopLayer(const uint32_t layerId,
                             uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*  osd_cp_params_ptr = NULL;
    int32_t  result;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if (osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if (osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    // ONLY for HW layers:
    if(!(layerId >> 16))
    {
        result = FAPI_VISCALE_Stop(osd_cp_params_ptr->fd);
        if((result != 0) && (errorCodePtr != NULL))
        {
            if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_STOP;
            if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_STOP;
            if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_STOP;
        }
        
        osd_cp_params_ptr->scalerParams.layerEnable = 0;
    }

    if (osd_cp_params_ptr->isMemoryDynamic &&
          (osd_cp_params_ptr->allocatedMemPtr != 0))
    {
       FAPI_SYS_FREE(osd_cp_params_ptr->allocatedMemPtr);
    }
    
    osd_cp_params_ptr->allocatedMemPtr = 0;
    
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Set an OSD/CP layer visible.
**
** It is recommended to perform drawing operations on the OSD/CP before it
** is set visible on the Video Output by this function.
** Before this function can be called, the layer must be started by
** means of OSDHANDLER_StartLayer().
**
** \note
**          - On OSD1 and OSD2 you can operate on the layer and see the results
**            instantly even when the layer is visible.
**          - For the Cursor Plane you will need to call this function in
**            order to see the updated content of the picture on the Video
**            output after having taken changes in the picture.
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_ENABLE
**              - #OSDHANDLER_ERR_CODE_OSD2_ENABLE
**              - #OSDHANDLER_ERR_CODE_CP_ENABLE
**              - #OSDHANDLER_ERR_CODE_OSD1_START
**              - #OSDHANDLER_ERR_CODE_OSD2_START
**              - #OSDHANDLER_ERR_CODE_CP_START
**              - #OSDHANDLER_ERR_CODE_OSD1_CLUT
**              - #OSDHANDLER_ERR_CODE_OSD2_CLUT
**              - #OSDHANDLER_ERR_CODE_CP_CLUT
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success. If there occured errors
**              during calls to the underlying driver, these errors
**              will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a passed pointer is NULL.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE for following reasons:
**              -   The OSDHANDLER has not allocated the corresponding handle of
**                  the hardware OSD/CP at initialization.
**              -   The HW layer that is used by a virtual layer  is not
**                  allocated by the OSDHANDLER.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED for following reasons:
**              -   The hardware layer has not been started yet.
**              -   The hardware layer that belongs to the identified virtual
**                  layer has not been started yet.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if either the virtual layer or its corresponding hardware
**              OSD layer is driven in a bad colour mode.
**
** \sa
**          - OSDHANDLER_StartLayer()
**          - OSDHANDLER_HideLayer()
**
*****************************************************************************
*/
/* 21c7f2fc - complete */
int32_t OSDHANDLER_ShowLayer(const uint32_t layerId,
                             uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr   = NULL;
    int32_t                     result              = 0;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    if (osd_cp_params_ptr->allocatedMemPtr == 0)
    {
       return 0xffd6ccb7;
    }
    
    // for virtual OSD layers
#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(layerId >> 16)
    {
        return (osdvirtualShowLayer(layerId, osd_cp_params_ptr, errorCodePtr));
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    // for HW OSD layers:
    result = FAPI_VISCALE_EnableDisable(osd_cp_params_ptr->fd, 
          FAPI_VISCALE_PARAMETER_ON);
    
    if((result != 0) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_ENABLE;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_ENABLE;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_ENABLE;
    }
    osd_cp_params_ptr->scalerParams.layerEnable = 1;
    
    if (osd_cp_params_ptr == &osdhandlerCpParams)
    {
       FAPI_SYS_FlushDataCache(osdhandlerCpParams.scalerParams.picBase,
          osdhandlerCpParams.scalerParams.inputPicWidth *
          osdhandlerCpParams.scalerParams.inputPicHeight * 
          osdhandlerGetBitsPerPixel(osd_cp_params_ptr) / 8);

       result = FAPI_VISCALE_Start(osdhandlerCpParams.fd,
              &osdhandlerCpParams.scalerParams);
       
       if((result != 0) && (errorCodePtr != NULL))
       {
           if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_START;
           if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_START;
           if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_START;
       }
       
       result = FAPI_VISCALE_UpdateClut(osdhandlerCpParams.fd,
             osdhandlerCpParams.clut);
       
       if((result != 0) && (errorCodePtr != NULL))
       {
           if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_CLUT;
           if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_CLUT;
           if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_CLUT;
       }
    }
    
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Set an (hardware) OSD/CP layer invisible without destroying
**          its content.
**
** Sets an layer invisible again. Takes only effect if the layer has been
** set visible previously.
** Before this function can be called, the layer needs to be started
** by means of OSDHANDLER_StartLayer().
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_ENABLE
**              - #OSDHANDLER_ERR_CODE_OSD2_ENABLE
**              - #OSDHANDLER_ERR_CODE_CP_ENABLE
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a passed pointer is NULL.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL if it is attempted to call
**              this function for a virtual layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED
**              if the layer has not been started yet.
**
** \sa
**          - OSDHANDLER_StartLayer()
**          - OSDHANDLER_StopLayer()
**          - OSDHANDLER_ShowLayer()
**
*****************************************************************************
*/
/* 21c7f230 - complete */
int32_t OSDHANDLER_HideLayer(const uint32_t layerId,
                             uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*  osd_cp_params_ptr = NULL;
    int32_t  result;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if (layerId>>16)
    {
        return(OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    if (osd_cp_params_ptr->allocatedMemPtr == 0)
    {
       return 0xffd6ccb7;
    }
    
    result = FAPI_VISCALE_EnableDisable(osd_cp_params_ptr->fd, 
          FAPI_VISCALE_PARAMETER_OFF);
    
    if((result != 0) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_ENABLE;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_ENABLE;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_ENABLE;
    }

    osd_cp_params_ptr->scalerParams.layerEnable = 0;
    
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Sets up the colour mode of an hardware OSD/CP.
**
** The OSD/CP will be stopped and its fill colour code will be set to
** '0x00000000' which is valid for all OSD/CP colour modes.
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
** \param   colourMode
**              Specifies which colour mode is going to be used for the OSD/CP.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_STOP
**              - #OSDHANDLER_ERR_CODE_OSD2_STOP
**              - #OSDHANDLER_ERR_CODE_CP_STOP
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER if a passed pointer is NULL.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL if it is attempted to call
**              this function for a virtual layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to set up a
**              new colour mode for this OSD.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the colour mode is bad.
**              You must not use Cursor Plane related colour modes for OSD and
**              vice versa since they are mentioned as invalid colour modes
**              for each other.
**
** \sa
**          - OSDHANDLER_SetFillColour()
**          - OSDHANDLER_SetLayoutMode()
**
*****************************************************************************
*/
/* 21c7efdc - complete */
int32_t OSDHANDLER_SetColourMode(const uint32_t layerId,
                                 const OSDHANDLER_ColourModeT colourMode,
                                 uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*  osd_cp_params_ptr = NULL;
    uint32_t  bpp;
    int32_t result;

    if(!osdhandlerInitialized)
    {
        return (OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(layerId >> 16)
    {
        return(OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    result = FAPI_VISCALE_Stop(osd_cp_params_ptr->fd);
    if((result != 0) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_STOP;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_STOP;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_STOP;
    }
    
    if (osd_cp_params_ptr->isMemoryDynamic &&
          (osd_cp_params_ptr->allocatedMemPtr != 0))
    {
       FAPI_SYS_FREE(osd_cp_params_ptr->allocatedMemPtr);
    }
    
    osd_cp_params_ptr->allocatedMemPtr = 0;

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    if((osd_cp_params_ptr == &osdhandlerOsd1Params) ||
       (osd_cp_params_ptr == &osdhandlerOsd2Params))
    {
        osd_cp_params_ptr->scalerParams.osdMode =
                                    osdhandlerGetOsdColourMode(colourMode);
    }
    else if (osd_cp_params_ptr == &osdhandlerCpParams)
    {
        osd_cp_params_ptr->scalerParams.cpMode =
                                    osdhandlerGetCpColourMode(colourMode);
    }
    osd_cp_params_ptr->colourMode = colourMode;
    osd_cp_params_ptr->fillColour = 0x00000000; // valid for all modes
    bpp = osdhandlerGetBitsPerPixel(osd_cp_params_ptr);
    if(bpp == 0)
    {
        return(OSDHANDLER_ERR_BAD_COLOUR_MODE);
    }

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief Sets up the colour layout mode of an hardware OSD/CP layer.
**
** The layout mode describes the order of the components in a pixel colour
** as well as the interpretation whether to use the components as Y, Cr and Cb
** values or as R, G and B values. The layer will be stopped before the new
** layout is set up.
** For the Cursor Plane there is only the CbYCrA mode available.
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
** \param   layoutMode
**              Specifies the memory layout mode to set up for the OSD/CP.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_STOP
**              - #OSDHANDLER_ERR_CODE_OSD2_STOP
**              - #OSDHANDLER_ERR_CODE_CP_STOP
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed:
**                  -   The errorCodePtr is NULL.
**                  -   The layout mode is unknown.
**                  -   It is attempted to drive the Cursor Plane in a
**                      different mode than OSDHANDLER_OSD_LAYOUT_CbYCrA.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL if it is attempted to call
**              this function for a virtual layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to set up a
**              new layout mode for this OSD.
**
** \sa
**          - OSDHANDLER_SetColourMode()
**          - OSDHANDLER_SetFillColour()
**
*****************************************************************************
*/
/* 21c7eea4 - complete */
int32_t OSDHANDLER_SetLayoutMode(const uint32_t layerId,
                                 const OSDHANDLER_OsdLayoutEnumT layoutMode,
                                 uint32_t* errorCodePtr)
{
    int32_t result;
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr = NULL;
    FAPI_VISCALE_OsdLayoutEnumT viscale_layout = FAPI_VISCALE_UNKNOWN_OSD_LAYOUT;

    if(!osdhandlerInitialized)
    {
        return (OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if (layerId >> 16)
    {
        return(OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    viscale_layout = osdhandlerGetOsdLayout(layoutMode);
    if (viscale_layout == FAPI_VISCALE_UNKNOWN_OSD_LAYOUT)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    if((osd_cp_params_ptr == &osdhandlerCpParams)
    && (layoutMode != OSDHANDLER_OSD_LAYOUT_CbYCrA))
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
        
    result = FAPI_VISCALE_Stop(osd_cp_params_ptr->fd);
    if((result != 0) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_STOP;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_STOP;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_STOP;
    }
    
    if (osd_cp_params_ptr->isMemoryDynamic &&
          (osd_cp_params_ptr->allocatedMemPtr != 0))
    {
       FAPI_SYS_FREE(osd_cp_params_ptr->allocatedMemPtr);
    }
    
    osd_cp_params_ptr->allocatedMemPtr = 0;

    osd_cp_params_ptr->scalerParams.osdLayout = viscale_layout;
    osd_cp_params_ptr->osdLayout = layoutMode;

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Sets the colour with which an OSD will be filled.
**
** The passed colour will also be used to fill the OSD when OSDHANDLER_Clear()
** is called.
** If the layer has not been started yet, it will not be started. But when
** it is started, all pixels will be initialized with the specified colour.
** If the layer has been started, it will be filled with the given colour
** immediately. All content on the OSD/CP will be wiped out.
**
** \note    - Keep in mind which colour mode is currently selected. If the given
**            colour code is too long (that is: too many used bits), an error
**            code will be returned.
**          - If you like to see the video layer in the background, choose a
**            transparent or semi-transparent colour and put the OSD in front of
**            the video layer by calling OSDHANDLER_PlaneOrder().
**
** \param   layerId qualifier that identifies an OSDHANDLER_OsdCpParamsT
**          structure:
**          - 0x00000001: OSD1
**          - 0x00000002: OSD2
**          - 0x00000003: Cursor Plane
**          - layerId: (group << 16) + virtualLayerId where group is
**            related to OSD1 or OSD2.
** \param   colour
**              Specifies the colour code that will fill the whole OSD/CP.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the colour mode of the OSD is bad.
**              Set up the colour mode by OSDHANDLER_SetColourMode() first.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if the passed colour uses too many bits in order to fit for
**              the current colour mode of the OSD/CP.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to set up a
**              new fill colour for this OSD.
**
** \sa
**          - OSDHANDLER_SetColourMode()
**          - OSDHANDLER_Clear()
**
*****************************************************************************
*/
/* 21c7e554 - complete */
int32_t OSDHANDLER_SetFillColour(const uint32_t layerId, const uint32_t colour)
{
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr = NULL;
    uint32_t                    bpp                 = 0;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    bpp = osdhandlerGetBitsPerPixel(osd_cp_params_ptr);
    if(bpp == 0)
    {
        return(OSDHANDLER_ERR_BAD_COLOUR_MODE);
    }
    if((bpp < 32) && (colour >> bpp)) // bad colour given
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osd_cp_params_ptr->fillColour = colour;

    if (osd_cp_params_ptr->allocatedMemPtr != 0)
    {
       osdhandlerFill(&osd_cp_params_ptr->scalerParams, bpp, colour);
    }
    
    return(FAPI_OK);    
}

/*!
*****************************************************************************
** \brief   Clears the content of an OSD/CP.
**
** The whole OSD/CP is filled with the colour that is set by
** OSDHANDLER_SetFillColour(). If no colour is set up, it will be filled with
** zeros. If the OSD/CP is not started yet, nothing will happen.
**
** \note    Keep in mind that you will have to call OSDHANDLER_ShowLayer() for
**          the Cursor Plane in order to see changes take effect.
**
** \param   layerId
**              qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              The colour mode of the OSD is bad.
**              Set up the colour mode by OSDHANDLER_SetColourMode() first.
**
** \sa
**          - OSDHANDLER_SetFillColour()
**          - OSDHANDLER_BitBlitFill()
**
*****************************************************************************
*/
/* 21c7e4d8 - complete */
int32_t OSDHANDLER_Clear(const uint32_t layerId)
{
    uint32_t bpp;
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr = NULL;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    
    bpp = osdhandlerGetBitsPerPixel(osd_cp_params_ptr);
    if (bpp == 0)
    {
       return OSDHANDLER_ERR_BAD_COLOUR_MODE;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    if (osd_cp_params_ptr->allocatedMemPtr != 0)
    {
       osdhandlerFill(&osd_cp_params_ptr->scalerParams, 
             bpp, osd_cp_params_ptr->fillColour);
    }
    
    return FAPI_OK;
}


/*!
*****************************************************************************
** \brief   Prints a rectangle with one colour on an OSD/CP.
**
** This is a performant function for drawing rectangles with a fix colour
** value. It makes use of DMA if accessible, otherwise the procedure is
** executed via CPU. Make sure that the layer has been started with
** OSDHANDLER_Start() previously and that the passed parameters achieve
** the constraints described below.
**
** \note    Lint error 923 temporarily disabled (5 calls) within function.
**          Cast from type to type is mandatory here for pointer
**          arithmetic.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   xx
**              The x coordinate of the top left corner of the rectangle.
** \param   yy
**              The y coordinate of the top left corner of the rectangle.
** \param   width
**              The width of the rectangle. The whole rectangle must be
**              enclosed by the OSD/CP.
** \param   height
**              The height of the rectangle. The whole rectangle must be
**              enclosed by the OSD/CP.
** \param   colour
**              The colour of the rectangle. It must achieve the requirements
**              for the counts of bits per pixel in the currently selected
**              colour mode of the OSD/CP.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the colour mode of the OSD is bad.
**              Set up the colour mode by OSDHANDLER_SetColourMode() first.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if the colour code uses too many bits.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED
**              if the layer has not been started yet.
**          - #OSDHANDLER_ERR_OUT_OF_SIZE
**              if the passed coordinates/dimensions of the rectangle are
**              out of bounds of the OSD.
**
** \sa
**          - OSDHANDLER_SetFillColour()
**          - OSDHANDLER_Clear()
**
*****************************************************************************
*/
/* 21c7d364 - todo */
int32_t OSDHANDLER_BitBlitFill(const uint32_t layerId,
                               const uint32_t xx,
                               const uint32_t yy,
                               const uint32_t width,
                               const uint32_t height,
                               const uint32_t colour)
{
    uint32_t bpp;
    OSDHANDLER_OsdCpParamsT* osd_cp_params_ptr = NULL;
    uint32_t  ii            = 0; // temporary counter

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }

    uint32_t sp12/*pixel_base_addr*/ = 0;
    uint32_t sp8/*pixel_bit_offset*/ = 0;
    
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    bpp = osdhandlerGetBitsPerPixel(osd_cp_params_ptr);
    if (bpp == 0)
    {
       return OSDHANDLER_ERR_BAD_COLOUR_MODE;
    }
    
    if(/*(bpp < 32) &&*/ (colour >> bpp)) // bad colour given
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }

    if (osd_cp_params_ptr->allocatedMemPtr == 0)
    {
       return 0xffd6ccb7;
    }
    
    if (((xx + width) > osd_cp_params_ptr->scalerParams.inputPicWidth) ||
          ((yy + height) > osd_cp_params_ptr->scalerParams.inputPicHeight))
    {
       return 0xffd6ccb9;
    }
    
    unsigned sl/*colour_32*/ = colour;
    for (ii = ((0x20UL / bpp) - 1); ii != 0; ii--)
    {
       //21c7d438
       sl = ((sl << bpp) | colour);
    }
    //21c7d44c
    osdhandlerGetPixelAddress(xx, yy, bpp, osd_cp_params_ptr, 
          &sp12, &sp8);
    
    unsigned r7 = 
       osd_cp_params_ptr->scalerParams.inputPicWidth * bpp / 32;
    
    unsigned lr;
    int ok = 0;
    
    uint32_t* ip/*addr*/; 
    
    if (sp8 != 0)
    {
       //21c7d488
       lr = (1 << (32 - sp8)) - 1;
       
       //unsigned r2 = bpp * width + sp8;
       
       if (/*r2*/(bpp * width + sp8) < 32)
       {
          //21c7d4a4
          lr &= ((1 << /*r2*/(bpp * width + sp8)) - 1) << (32 - /*r2*/(bpp * width + sp8));
       }
       //21c7d4b4
       ok = 1;
    }    
    else
    {
       //21c7d604
       if ((bpp * width) < 32)
       {
          //21c7d610
          lr = ((1 << (bpp * width)) - 1) << (32 - (bpp * width));
          //->21c7d4b4
          ok = 1;
       }
    }
    //21c7d4b4
    if (ok & (lr != 0))
    {
       //21c7d4bc
       unsigned r1;
       unsigned r2;
       ip = (uint32_t*)sp12;
       //21c7d4cc       
       for (r1 = 0, r2 = 0; r1 < /*sp44*/height; r1++, r2 += r7)
       {
          ip[r2] = (ip[r2] & ~lr) | (sl & lr);
       }
       //->21c7d50c
    }    
    //21c7d504
    ip = (uint32_t*)sp12;
    //21c7d50c
    if ((bpp * width + sp8) > 31)
    {
       unsigned r2 = (bpp * width + sp8);
       if (r2 % 32)
       {
          unsigned r1;
          
          unsigned r3 = ((1 << (r2 % 32)) - 1) << (32 - (r2 % 32));
          
          r2 >>= 5;
          
          for (r1 = 0; r1 < /*sp44*/height; r1++, r2 += r7)
          {
             ip[r2] = (ip[r2] & ~r3) | (sl & r3);
          }
       }
       //21c7d584
    }
    //21c7d584
    uint32_t r0 = (bpp * width + sp8) >> 5;

    if (sp8 != 0)
    {
       //21c7d598
       if (r0 != 0)
       {
          r0--;
       }
       ip = (uint32_t*)sp12 + 1;
    }
    else
    {
       ip = (uint32_t*)sp12;
       //->21c7d5a4
    }
    //21c7d5a4
    uint32_t r2 = r7 - r0;

    //if (r0 != 0)
    {
       //21c7d5ac
       uint32_t lr, r3;
       for (lr = 0; lr < /*sp44*/height; lr++)
       {
          //21c7d5c4
          for (r3 = 0; r3 < r0; r3++)
          {    
             *ip++ = sl;
          }
          //21c7d5ec
          ip += r2;
       }
    }
    //21c7d630
    
#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS
    
    return 0;
}

/*!
*****************************************************************************
** \brief   Sets up the colour lookup table (CLUT) for a specific OSD/CP.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   newClutPtr
**              Points to a field of 256 colour codes, each of 4 bytes.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_CLUT
**              - #OSDHANDLER_ERR_CODE_OSD2_CLUT
**              - #OSDHANDLER_ERR_CODE_CP_CLUT
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a passed pointer is NULL.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
** \sa
**          - OSDHANDLER_SetClutPartially()
**          - OSDHANDLER_GetClut()
**
*****************************************************************************
*/
/* 21c7ed9c - complete */
int32_t OSDHANDLER_SetClut(const uint32_t layerId,
                           uint32_t* newClutPtr,
                           uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT* osd_cp_params_ptr = NULL;
    uint32_t  ii;
    int32_t   result;

    if(!osdhandlerInitialized)
    {
        return (OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(newClutPtr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    // update virtual OSD CLUT:
    if(layerId >> 16)
    {
        for (ii = 0; ii < 256; ii++)
        {
            osd_cp_params_ptr->scalerParams.colourLut[ii] = *(newClutPtr + ii);
            osd_cp_params_ptr->clut[ii] = *(newClutPtr + ii);
        }
        return(FAPI_OK);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    // update hardware OSD CLUTs:
    for (ii = 0; ii < 256; ii++)
    {
       osd_cp_params_ptr->scalerParams.colourLut[ii] = *(newClutPtr + ii);
       osd_cp_params_ptr->clut[ii] = *(newClutPtr + ii);
    }

    // update hardware OSD CLUTs:
    //if(!(layerId >> 16))
    {
        result = FAPI_VISCALE_UpdateClut(osd_cp_params_ptr->fd,
              osd_cp_params_ptr->scalerParams.colourLut);
        if((result != 0) && (errorCodePtr != NULL))
        {
            if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_CLUT;
            if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_CLUT;
            if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_CLUT;
        }
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Sets up the colour lookup table (CLUT) for a specific OSD/CP
**          partially. Only a given count of entries will be updated.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   newClutPtr
**              Points to a field of entryCount colour codes, each of 4 bytes.
** \param   startIndex
**              The index of the first entry in the OSD/CP CLUT that
**              will be updated. The first CLUT entry is indexed by 0.
** \param   entryCount
**              The count of entries in the OSD/CP CLUT that will be modified.
**              If you want to modify one CLUT entry, pass 1.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_CLUT
**              - #OSDHANDLER_ERR_CODE_OSD2_CLUT
**              - #OSDHANDLER_ERR_CODE_CP_CLUT
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed. Possible reasons:
**              -   The newClutPtr is NULL.
**              -   The errorCodePtr is NULL.
**              -   The combination of the startIndex and the entryCount exceed
**                  the boundary of 256 CLUT entries.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
** \sa
**          - OSDHANDLER_SetClut()
**          - OSDHANDLER_GetClut()
**
*****************************************************************************
*/
/* 21c7ec5c - complete */
int32_t OSDHANDLER_SetClutPartially(const uint32_t layerId,
                                    uint32_t*      newClutPtr,
                                    const uint32_t startIndex,
                                    const uint32_t entryCount,
                                    uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT* osd_cp_params_ptr = NULL;
    uint32_t  ii;
    int32_t   result;

    if(!osdhandlerInitialized)
    {
        return (OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if( (newClutPtr   == NULL)
     || ((startIndex + entryCount) > 256) )
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    // update virtual OSD CLUT:
    if(layerId >> 16)
    {
        for(ii = 0; ii < entryCount; ii++)
        {
            osd_cp_params_ptr->scalerParams.colourLut[startIndex + ii] =
                *(newClutPtr + ii);
            osd_cp_params_ptr->clut[startIndex + ii] = *(newClutPtr + ii);
        }
        return(FAPI_OK);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    // update hardware OSD CLUT:
    for(ii = 0; ii < entryCount; ii++)
    {
        osd_cp_params_ptr->clut[startIndex + ii] = *(newClutPtr + ii);
    }
    result = FAPI_VISCALE_UpdateClut(osd_cp_params_ptr->fd,
                                osd_cp_params_ptr->clut );
    if((result != 0) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_CLUT;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_CLUT;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_CLUT;
    }
    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Gets the colour lookup table (CLUT) for a specific OSD/CP.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   destClutPtr
**              Points to a field of 256 CLUT entries (4 bytes each) that
**              will receive the CLUT from the related OSD/CP.
**
** \attention
**          Make sure that the destClutPtr points to a field of 256
**          4-byte-words. The procedure will overwrite all field members!
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if the destClutPtr is NULL.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
** \sa
**          - OSDHANDLER_SetClut()
**          - OSDHANDLER_SetClutPartially()
**
*****************************************************************************
*/
/* 21c7d658 - complete */
int32_t OSDHANDLER_GetClut(const uint32_t layerId, uint32_t* destClutPtr)
{
    OSDHANDLER_OsdCpParamsT* osd_cp_params_ptr = NULL;
    uint32_t  ii;

    if(!osdhandlerInitialized)
    {
        return (OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(destClutPtr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    for (ii = 0; ii < 256; ii++)
    {
        *(destClutPtr + ii) = osd_cp_params_ptr->clut[ii];
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Repositions an OSD/CP to given coordinates.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - virtual layers must not be called.
** \param   xx
**              The new x coordinate of the OSD/CP.
** \param   yy
**              The new y coordinate of the OSD/CP.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_RESIZE
**              - #OSDHANDLER_ERR_CODE_OSD2_RESIZE
**              - #OSDHANDLER_ERR_CODE_CP_RESIZE
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if the passed errorCodePtr is NULL.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL
**              if it is attempted to reposition a virtual layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
** \sa
**          - OSDHANDLER_Start()
**          - OSDHANDLER_Rescale()
**
*****************************************************************************
*/
/* 21c7eb80 - complete */
int32_t OSDHANDLER_Reposition(const uint32_t layerId,
                              const uint32_t xx,
                              const uint32_t yy,
                              uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT* osd_cp_params_ptr = NULL;
    int32_t  result = 0;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if (layerId >> 16)
    {
        return(OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    osd_cp_params_ptr->scalerParams.outputWindowX0 = xx;
    osd_cp_params_ptr->scalerParams.outputWindowY0 = yy;

    result = FAPI_VISCALE_Resize(osd_cp_params_ptr->fd,
                                &osd_cp_params_ptr->scalerParams );
    if((result != 0) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_RESIZE;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_RESIZE;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_RESIZE;
    }
    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Rescales an OSD to a given output resolution. The Cursor Plane
**          can not be rescaled.
**
** \note    Downscaling more than factor 2 is not possible. If you try though,
**          the picture will be cut off on the bottom side in order
**          to fit for the passed dimensions. However, there might be some
**          lines missing on the bottom of the OSD then.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - virtual layers must not be called.
** \param   outputWidth
**              New width of the OSD.
** \param   outputHeight
**              New height of the OSD.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_RESIZE
**              - #OSDHANDLER_ERR_CODE_OSD2_RESIZE
**              - #OSDHANDLER_ERR_CODE_CP_RESIZE
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed:
**              -   The errorCodePtr is NULL.
**              -   The new resolution exceeds the maximum possible resolution
**                  of 1920 x 1080.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL
**              if it is attempted to rescale a virtual layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid:
**              -   The layer does not exist at all.
**              -   The Cursor Plane is addressed. You can not rescale the CP.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
** \sa
**          - OSDHANDLER_Reposition()
**
*****************************************************************************
*/
/* 21c7ea18 - complete */
int32_t OSDHANDLER_Rescale(const uint32_t layerId,
                           const uint32_t outputWidth,
                           const uint32_t outputHeight,
                           uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr = NULL;
    FAPI_VISCALE_SystemModeEnumT systemMode;
    int32_t  result;
    uint32_t finalOutputWidth;
    uint32_t finalOutputHeight;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if((outputWidth  > OSDHANDLER_MAX_HRES) ||
       (outputHeight > OSDHANDLER_MAX_VRES))
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(layerId >> 16)
    {
        return(OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    finalOutputWidth = (outputWidth > osdhandlerMaxHRES) ? \
                            osdhandlerMaxHRES : outputWidth;
    finalOutputHeight = (outputHeight > osdhandlerMaxVRES) ? \
                            osdhandlerMaxVRES : outputHeight;

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if((osd_cp_params_ptr == NULL)
    || (osd_cp_params_ptr == &osdhandlerCpParams))
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }
    
    systemMode = FAPI_VISCALE_GetSystemType(osd_cp_params_ptr->fd);

    if ((systemMode == FAPI_VISCALE_SYSTEM_MODE_720x576x50I) || 
          (systemMode == FAPI_VISCALE_SYSTEM_MODE_720x480x5994I))
    {
       finalOutputWidth *= 2;
       
       if (finalOutputWidth > osdhandlerMaxHRES) 
       {
          finalOutputWidth = osdhandlerMaxHRES;
       }
    }

    osd_cp_params_ptr->scalerParams.outputWindowWidth  = finalOutputWidth;
    osd_cp_params_ptr->scalerParams.outputWindowHeight = finalOutputHeight;

    result = FAPI_VISCALE_Resize( osd_cp_params_ptr->fd,
          &osd_cp_params_ptr->scalerParams );
    if((result != FAPI_OK) && (errorCodePtr != NULL))
    {
        if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_RESIZE;
        if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_RESIZE;
        if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_RESIZE;
    }
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Gets relevant information for drawing on an OSD/CP.
**
** Other paint middleware make use of this function in order to gain access
** to an OSD/CP without having to allocate its handle directly.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   layerParamsPtr
**              Points to a structure that will receive information about the
**              OSD/CP such as the picture base address, resolution and
**              bits per pixel.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if the layerParamsPtr is null.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the colour mode of the OSD is bad.
**              Set up the colour mode by OSDHANDLER_SetColourMode() first.
**
** \sa
**          - OSDHANDLER_GetPixelAddress()
**
*****************************************************************************
*/
/* 21c7d6d8 - complete */
int32_t OSDHANDLER_GetLayerParameters(const uint32_t layerId,
                                      OSDHANDLER_LayerParamsT* layerParamsPtr)
{
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr   = NULL;
    uint32_t  bpp;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(layerParamsPtr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    /*if the HW layer is locked by virtual layer group*/
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    bpp = osdhandlerGetBitsPerPixel(osd_cp_params_ptr);
    if(bpp == 0)
    {
        return(OSDHANDLER_ERR_BAD_COLOUR_MODE);
    }

    layerParamsPtr->pictureBase = osd_cp_params_ptr->allocatedMemPtr? 
          osd_cp_params_ptr->scalerParams.picBase: 0;
    layerParamsPtr->xRes = osd_cp_params_ptr->scalerParams.inputPicWidth;
    layerParamsPtr->yRes = osd_cp_params_ptr->scalerParams.inputPicHeight;
    layerParamsPtr->bpp  = bpp;
    layerParamsPtr->colourMode  = osd_cp_params_ptr->colourMode;
    layerParamsPtr->layoutMode  = osd_cp_params_ptr->osdLayout;
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Gets the memory adress of a pixel at given coordinates on an OSD/CP.
**
** This procedure is useful to gain access to the memory address of a single pixels.
** In order to operate on memory ranges use OSDHANDLER_GetLayerParameters().
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   xx
**              x coordinate of the pixel whose memory address will be determined.
** \param   yy
**              y coordinate of the pixel whose memory address will be determined.
** \param   pixelBaseAddrPtr
**              Will point to the 4byte-aligned address in front of the pixel.
** \param   pixelBitOffsetPtr
**              Will point to the address bit offset since
**              the obtained memory address of the pixel may not be aligend to
**              4 bytes. This value will always be less than 32.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed. Possible reasons:
**              -   The pixelBaseAddrPtr is null.
**              -   The pixelBitOffsetPtr is null.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_LOCKED
**              if the hardware OSD layer is locked since its virtual group
**              has been started previously. You will need to call
**              OSDHANDLER_StopVirtualLayerGroup() first in order to proceed.
**          - #OSDHANDLER_ERR_BAD_COLOUR_MODE
**              if the colour mode of the OSD is bad.
**              Set up the colour mode by OSDHANDLER_SetColourMode() first.
**          - #OSDHANDLER_ERR_LAYER_NOT_STARTED
**              if the layer has not been started yet.
**          - #OSDHANDLER_ERR_OUT_OF_SIZE
**              if the passed coordinates are out of bounds of the OSD.
**
** \sa
**          - OSDHANDLER_GetLayerParameters()
**
*****************************************************************************
*/
/* 21c7d784 - complete */
int32_t OSDHANDLER_GetPixelAddress(const uint32_t layerId,
                                   const uint32_t xx,
                                   const uint32_t yy,
                                   uint32_t* pixelBaseAddrPtr,
                                   uint32_t* pixelBitOffsetPtr)
{
    OSDHANDLER_OsdCpParamsT* osd_cp_params_ptr = NULL;
    uint32_t  bpp       = 0;     // bits per pixel

    if(!osdhandlerInitialized)
    {
        return (OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if((pixelBaseAddrPtr  == NULL) ||
       (pixelBitOffsetPtr == NULL))
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER); // null pointer passed
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID); // bad OSD qualifier given
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if(osd_cp_params_ptr == &osdhandlerOsd1Params)
    {
        if (osdhandlerGroup1Started &&
            osdhandlerGroup1Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
    if(osd_cp_params_ptr == &osdhandlerOsd2Params)
    {
        if (osdhandlerGroup2Started &&
            osdhandlerGroup2Shown)
        {
            return (OSDHANDLER_ERR_VL_LAYER_IS_LOCKED);
        }
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    bpp = osdhandlerGetBitsPerPixel(osd_cp_params_ptr);
    if(bpp == 0)
    {
        return(OSDHANDLER_ERR_BAD_COLOUR_MODE);
    }
    
    if (osd_cp_params_ptr->allocatedMemPtr == 0)
    {
       return 0xffd6ccb7;
    }

    if( (xx >= osd_cp_params_ptr->scalerParams.inputPicWidth)
     || (yy >= osd_cp_params_ptr->scalerParams.inputPicHeight) )
    {
        return(OSDHANDLER_ERR_OUT_OF_SIZE);
    }

    *pixelBaseAddrPtr = osd_cp_params_ptr->scalerParams.picBase
                        + ((yy * osd_cp_params_ptr->scalerParams.inputPicWidth * bpp) >> 3)
                        + ((xx * bpp) >> 3); // /8 ==> byte pointer
    *pixelBaseAddrPtr -= *pixelBaseAddrPtr % 4; //4-byte aligned address
    *pixelBitOffsetPtr = (xx * bpp) % 32;
    return (FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Operates on the GlobalAlpha settings of an OSD/CP.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
** \param   mode
**              Specifies how to operate on the global alpha settings of the
**              OSD/CP and if the level parameter is utilized, how to apply it.
**              Possible modes are:
**              - #OSDHANDLER_PARAMETER_GET returns the global alpha value
**                (even though global alpha may be disabled).
**              - #OSDHANDLER_PARAMETER_SET sets the global alpha value. If you
**                pass a value greater than 255, 255 is applied to the
**                alpha value.
**              - #OSDHANDLER_PARAMETER_INCREASE increases the existing global
**                alpha value by 'level' steps. If you excess 255, the setting
**                will not go beyond that value.
**              - #OSDHANDLER_PARAMETER_DECREASE deceases the existing global
**                alpha value by 'level' steps. If you fall below 0, the
**                setting will stay at 0.
**              - #OSDHANDLER_PARAMETER_ON switches the global alpha mode on.
**              - #OSDHANDLER_PARAMETER_OFF switches the global alpha mode off.
** \param   level
**              The level value will be applied to the global alpha value
**              according to the mode parameter.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if the mode qualifier is bad.
**
*****************************************************************************
*/
/* 21c7e8e4 - todo */
int32_t OSDHANDLER_GlobalAlpha(const uint32_t layerId,
                               const OSDHANDLER_ModeParamT mode,
                               const uint32_t level)
{
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr   = NULL;
    uint32_t  result = FAPI_OK;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    // virtual layers:
    if(layerId >> 16)
    {
        return osdvirtualGlobalAlpha(osd_cp_params_ptr, mode, level);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    // hardware layers:
    switch (mode)
    {
    case OSDHANDLER_PARAMETER_GET:
       result = FAPI_VISCALE_Alpha(osd_cp_params_ptr->fd, 
             FAPI_VISCALE_PARAMETER_GET, 0);
       break;
       
    case OSDHANDLER_PARAMETER_SET:
       osd_cp_params_ptr->scalerParams.globalAlpha = 
          (level >> 8)? 0xff: level;

       FAPI_VISCALE_Alpha(osd_cp_params_ptr->fd, 
             FAPI_VISCALE_PARAMETER_SET, 
             osd_cp_params_ptr->scalerParams.globalAlpha);
       break;
       
    case OSDHANDLER_PARAMETER_INCREASE:
       osd_cp_params_ptr->scalerParams.globalAlpha = 
          ((osd_cp_params_ptr->scalerParams.globalAlpha >> 8) ||
             (level >> 8) ||
             ((osd_cp_params_ptr->scalerParams.globalAlpha + level) >> 8))?
                   0xff: 
                   osd_cp_params_ptr->scalerParams.globalAlpha + level;
          
       FAPI_VISCALE_Alpha(osd_cp_params_ptr->fd, 
             FAPI_VISCALE_PARAMETER_SET, 
             osd_cp_params_ptr->scalerParams.globalAlpha);
       break;
       
    case OSDHANDLER_PARAMETER_DECREASE:
       osd_cp_params_ptr->scalerParams.globalAlpha = 
          (level > osd_cp_params_ptr->scalerParams.globalAlpha)?
                0: osd_cp_params_ptr->scalerParams.globalAlpha - level;

       FAPI_VISCALE_Alpha(osd_cp_params_ptr->fd, 
             FAPI_VISCALE_PARAMETER_SET, 
             osd_cp_params_ptr->scalerParams.globalAlpha);
       break;
       
    case OSDHANDLER_PARAMETER_ON:
       osd_cp_params_ptr->scalerParams.useGlobalAlpha = 1;
       FAPI_VISCALE_Alpha(osd_cp_params_ptr->fd, 
             FAPI_VISCALE_PARAMETER_ON, 0);       
       break;
       
    case OSDHANDLER_PARAMETER_OFF:
       osd_cp_params_ptr->scalerParams.useGlobalAlpha = 0;
       FAPI_VISCALE_Alpha(osd_cp_params_ptr->fd, 
             FAPI_VISCALE_PARAMETER_OFF, 0);
       break;
       
    default:
       result = OSDHANDLER_ERR_BAD_PARAMETER;
       break;
    }
    
    return result;    
}

/*!
*****************************************************************************
** \brief   Fades a plane in or out smoothly.
**
** Since this function works on the global alpha value, you will need to
** enable global alpha to see the effect.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - virtual layers must not be faded.
** \param   mode
**              Specifies whether to fade the plane in or out.
**              Possible modes are:
**              - OSDHANDLER_PARAMETER_ON fades the OSD/CP plane in.
**              - OSDHANDLER_PARAMETER_OFF fades the OSD/CP plane out.
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              one or more of the following error messages may be contained:
**              - #OSDHANDLER_ERR_CODE_OSD1_FADE
**              - #OSDHANDLER_ERR_CODE_OSD2_FADE
**              - #OSDHANDLER_ERR_CODE_CP_FADE
**              .
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed:
**              -   The passed errorCodePtr is NULL.
**              -   The mode qualifier is bad.
**          - #OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL
**              if it is attempted to fade a virtual layer.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if the passed layerId is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
*****************************************************************************
*/
/* 21c7e7e8 - complete */
int32_t OSDHANDLER_PlaneFading(const uint32_t layerId,
                               const OSDHANDLER_ModeParamT mode,
                               uint32_t* errorCodePtr)
{
    OSDHANDLER_OsdCpParamsT*     osd_cp_params_ptr = NULL;
    int32_t  result;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    if (layerId >> 16)
    {
        return(OSDHANDLER_ERR_VL_LAYER_IS_VIRTUAL);
    }
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    switch (mode)
    {
    case OSDHANDLER_PARAMETER_OFF:
       result = FAPI_VISCALE_AutoPlaneFading(osd_cp_params_ptr->fd,
             FAPI_VISCALE_VIDEO_FADE_OUT );
       if ((result != 0) && (errorCodePtr != NULL))
       {
          if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_FADE;
          if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_FADE;
          if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_FADE;
       }
       break;
       
    case OSDHANDLER_PARAMETER_ON:
       result = FAPI_VISCALE_AutoPlaneFading(osd_cp_params_ptr->fd,
             FAPI_VISCALE_VIDEO_FADE_IN );
       if ((result != 0) && (errorCodePtr != NULL))
       {
          if(layerId == 1) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD1_FADE;
          if(layerId == 2) *errorCodePtr |= OSDHANDLER_ERR_CODE_OSD2_FADE;
          if(layerId == 3) *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_FADE;
       }
       break;
       
    default:
       return OSDHANDLER_ERR_BAD_PARAMETER; 
    }    
    
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Switches the highlight function on the Cursor Plane.
**
** The hilight function causes to shift the colour mapping to the CLUT
** by 0x80 (= 10000000 binary). For instance: If you draw a pixel with
** colour code 0x04, you will see the pixel in the colour of CLUT entry 0x84
** on the screen.
** The hilight mode makes sense for the following colour modes only:
**          - #OSDHANDLER_CURSOR_MODE_1BIT
**          - #OSDHANDLER_CURSOR_MODE_2BIT
**          - #OSDHANDLER_CURSOR_MODE_4BIT.
**          .
** In the #OSDHANDLER_CURSOR_MODE_8BIT all 256 colours can be adressed
** anyway so there is no need to switch the hilight on.
**
** \param   onOff
**              Decides whether to switch the hilight on or off.
**              Possible modes are:
**              - #OSDHANDLER_PARAMETER_ON
**              - #OSDHANDLER_PARAMETER_OFF
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              it equals #OSDHANDLER_ERR_CODE_CP_HILIGHT.
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**              If there occured errors during calls to the underlying driver,
**              these errors will be indicated in the errorCodePtr parameter.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed:
**              - The passed errorCodePtr is NULL.
**              - The passed onOff mode param is invalid.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
*****************************************************************************
*/
/* 21c7e758 - complete */
int32_t OSDHANDLER_CursorHilight(const OSDHANDLER_ModeParamT onOff,
                                 uint32_t* errorCodePtr)
{
    int32_t   result;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(errorCodePtr != NULL)
    {
        *errorCodePtr = FAPI_OK;
    }
    if(osdhandlerCpParams.fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    switch(onOff)
    {
    case(OSDHANDLER_PARAMETER_ON):
        result = FAPI_VISCALE_Hilight(osdhandlerCpParams.fd, 
              FAPI_VISCALE_PARAMETER_ON );
        
        if ((result != 0) && (errorCodePtr != NULL))
        {
           *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_HILIGHT;
        }
        break;
        
    case(OSDHANDLER_PARAMETER_OFF):
        result = FAPI_VISCALE_Hilight(osdhandlerCpParams.fd, 
              FAPI_VISCALE_PARAMETER_OFF );
    
        if ((result != 0) && (errorCodePtr != NULL))
        {
           *errorCodePtr |= OSDHANDLER_ERR_CODE_CP_HILIGHT;
        }
        break;
        
     default:
         return(OSDHANDLER_ERR_BAD_PARAMETER);
    }

    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Flush the data cache for the picture of an OSD/CP.
**
** Call this function if you experience remanence or disagreeable
** artefacts on a OSD/CP layer after drawing on it.
**
** \param   layerId
**              Qualifier that identifies an OSDHANDLER_OsdCpParamsT structure:
**              - 0x00000001: OSD1
**              - 0x00000002: OSD2
**              - 0x00000003: Cursor Plane
**              - layerId: (group << 16) + virtualLayerId where group is
**                related to OSD1 or OSD2.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_LAYER_ID
**              if an invalid layerId has been passed.
**          - #OSDHANDLER_ERR_NO_OSD_HANDLE
**              if the OSDHANDLER has not allocated the corresponding handle of
**              the OSD/CP at initialization.
**
*****************************************************************************
*/
/* 21c7e3b4 - complete */
int32_t OSDHANDLER_FlushPicture(const uint32_t layerId)
{
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr = NULL;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layerId);
    if(osd_cp_params_ptr == NULL)
    {
        return(OSDHANDLER_ERR_BAD_LAYER_ID);
    }
    if(osd_cp_params_ptr->fd == 0)
    {
        return(OSDHANDLER_ERR_NO_OSD_HANDLE);
    }

    if (osd_cp_params_ptr->allocatedMemPtr != 0)
    {
       FAPI_SYS_FlushDataCache(osd_cp_params_ptr->scalerParams.picBase,
          osd_cp_params_ptr->scalerParams.inputPicWidth *
          osd_cp_params_ptr->scalerParams.inputPicHeight * 
          osdhandlerGetBitsPerPixel(osd_cp_params_ptr) / 8);
    }
    
    return(FAPI_OK);
}

/*!
*****************************************************************************
** \brief   Operate on the plane order of the Video Plane, both OSD planes
**          and the Cursor Plane.
**
** This function may operate on the plane order in several ways, dependend
** on the mode parameter.
**
** \param   mode
**              Specifies how to operate on the plane order:
**              - OSDHANDLER_PARAMETER_GET: return the current plane order
**              - OSDHANDLER_PARAMETER_SET: set up a new plane order
** \param   lowermost
**              If the mode is OSDHANDLER_PARAMETER_SET, this setting defines
**              which layer will be the lowermost one.
**              Layer coding:
**              - 0: Video Plane
**              - 1: OSD1
**              - 2: OSD2
**              - 3: Cursor Plane
** \param   first
**              If the mode is OSDHANDLER_PARAMETER_SET, this setting defines
**              which layer will be the one above the lowermost layer.
**              Layer coding:
**              - 0: Video Plane
**              - 1: OSD1
**              - 2: OSD2
**              - 3: Cursor Plane
** \param   second
**              If the mode is OSDHANDLER_PARAMETER_SET, this setting defines
**              which layer will be the one above the first one.
**              Layer coding:
**              - 0: Video Plane
**              - 1: OSD1
**              - 2: OSD2
**              - 3: Cursor Plane
** \param   topmost
**              If the mode is OSDHANDLER_PARAMETER_SET, this setting defines
**              which layer will be the topmost one.
**              Layer coding:
**              - 0: Video Plane
**              - 1: OSD1
**              - 2: OSD2
**              - 3: Cursor Plane
** \param   errorCodePtr
**              Will receive error codes related to specific hardware layers.
**              If there occured an error during the underlying driver calls,
**              it equals #OSDHANDLER_ERR_CODE_PLANE_ORDER.
**              If no errors occured, the word equals FAPI_OK. <br>
**              This parameter is optional, it may be NULL if the error
**              code is not of any interest.
**
** \return
**          - #FAPI_OK on success.
**          - #OSDHANDLER_ERR_NOT_INITIALIZED
**              if the OSDHANDLER is not initialized.
**          - #OSDHANDLER_ERR_BAD_PARAMETER
**              if a bad parameter has been passed:
**              -   The mode qualifier is bad.
**              -   Two precedence parameters are equal.
**              -   One of the precedence parameters is greater than 3.
**              -   The passed errorCodePtr is NULL.
**          -   A value greater than zero if the mode parameter is
**              #OSDHANDLER_PARAMETER_GET. The number that is returned follows
**              the subsequent scheme:
**              0x0000[lowermost][first][second][topmost] where each cipher
**              in [] stands for one of the four layers coded as below:
**                  - 0: Video Plane
**                  - 1: OSD1
**                  - 2: OSD2
**                  - 3: Cursor Plane
**
*****************************************************************************
*/
/* 21c7e2c0 - complete */
int32_t OSDHANDLER_PlaneOrder(OSDHANDLER_ModeParamT mode,
                              uint32_t lowermost,
                              uint32_t first,
                              uint32_t second,
                              uint32_t topmost,
                              uint32_t* errorCodePtr)
{
    int32_t  result;

    if(!osdhandlerInitialized)
    {
        return(OSDHANDLER_ERR_NOT_INITIALIZED);
    }
    if(mode == OSDHANDLER_PARAMETER_GET)
    {
        return FAPI_VISCALE_PlaneOrder(mode, 0, 0, 0, 0);
    }
    else if (mode == OSDHANDLER_PARAMETER_SET)
    {
        if((topmost == second) ||
              (topmost == first ) ||
              (topmost == lowermost ) ||
              (second == first) ||
              (second == lowermost) ||
              (first == lowermost) ||
              (topmost   & ~3) ||
              (second    & ~3) ||
              (first     & ~3) ||
              (lowermost & ~3))
        {
            return(OSDHANDLER_ERR_BAD_PARAMETER);
        }
        if(errorCodePtr != NULL)
        {
            *errorCodePtr = FAPI_OK;
        }

        result = FAPI_VISCALE_PlaneOrder(mode, 
              lowermost, first, second, topmost);
        if((result != 0) && (errorCodePtr != NULL))
        {
            *errorCodePtr |= OSDHANDLER_ERR_CODE_PLANE_ORDER;
        }
        return(FAPI_OK);
    }
    else
    {
        return(OSDHANDLER_ERR_BAD_PARAMETER);
    }
}

/*!
*****************************************************************************
** \brief   Calculates the memory consumption for an OSD at a given setup.
**
** Gets the amount of bytes that are needed for starting an OSD with a given
** set of parameters. Use this function in order to make sure that you provide
** enough memory if you give a memoryBasePtr parameter within the
** #OSDHANDLER_StartParamsT when starting an OSD.
** For the Cursor Plane make sure that you provide 16 KiB of memory.
**
** \param   inputWidth
**              The width in pixels of the input picture.
** \param   inputHeight
**              The height in pixels of the input picture.
** \param   colourMode
**              The colour mode the layer will operate.
**
** \return  Memory consumption:
**          -   The amount of consumed bytes on success.
**          -   0 if one or more bad parameters have been passed that would not
**              be able to start the layer. Possible reasons are:
**              -   The maximum resolution of 1920x1080 is exceeded.
**              -   The colour mode is unknown: bits per pixel is 0.
**
*****************************************************************************
*/
uint32_t OSDHANDLER_GetOsdMemConsumption(const uint32_t inputWidth,
                                         const uint32_t inputHeight,
                                         const OSDHANDLER_ColourModeT colourMode)
{
    uint32_t bpp        = 0;
    uint32_t h_res      = 0;
    uint32_t v_res      = 0;

    if((inputWidth > OSDHANDLER_MAX_HRES)
     ||(inputHeight > OSDHANDLER_MAX_VRES))
    {
        return(0);
    }

    switch (colourMode)
    {
        case(OSDHANDLER_OSD_MODE_UNKNOWN):
            bpp = 0;
            break;
        case(OSDHANDLER_OSD_MODE_CLUT_4BIT):
            bpp = 4;
            break;
        case(OSDHANDLER_OSD_MODE_CLUT_8BIT):
            bpp = 8;
            break;
        case(OSDHANDLER_OSD_MODE_16BIT):
        case(OSDHANDLER_OSD_MODE_4444):
        case(OSDHANDLER_OSD_MODE_5551):
            bpp = 16;
            break;
        case(OSDHANDLER_OSD_MODE_32_24BIT):
            bpp = 32;
            break;
        case(OSDHANDLER_CURSOR_MODE_UNKNOWN):
            bpp = 0;
            break;
        case(OSDHANDLER_CURSOR_MODE_1BIT):
            bpp = 1;
            break;
        case(OSDHANDLER_CURSOR_MODE_2BIT):
            bpp = 2;
            break;
        case(OSDHANDLER_CURSOR_MODE_4BIT):
            bpp = 4;
            break;
        case(OSDHANDLER_CURSOR_MODE_8BIT):
            bpp = 8;
            break;
        default:
            bpp = 0;
            break;
    }
    if(bpp == 0)
    {
        return(0);
    }

    h_res = inputWidth;
    v_res = inputHeight;

    // one line must allocate a multiple of 128 bytes:
    if (h_res % (1024 / bpp))
    {
        h_res += (1024 / bpp) - (h_res % (1024 / bpp));
    }
    // v_res must be a multiple of 2
    if (v_res % 2)
    {
        v_res++;
    }
    return(((h_res * v_res * bpp) >> 3) + 1024);
}

/*!
*****************************************************************************
** \brief   Convert a colour code from ARGB to CbYCrA for 32-bit depth.
**
** \param   argbUnion
**              Union that specifies a colour in the ARGB colour scheme.
**
** \return      Word that contains the colour coded in CbYCrA.
**
*****************************************************************************
*/
/* 21c7d95c - complete */
uint32_t OSDHANDLER_ConvertARGB2CbYCrA_union(const OSDHANDLER_ARGB__T argbUnion)
{
    OSDHANDLER_CbYCrA__T cb_y_cr_a;
    cb_y_cr_a.all = 0x00000000UL;

    /* float Y, Cr, Cb;
    Y = 0.587f*(float)G + 0.299f*(float)R + 0.114f*(float)B;
    Cr = 128 + (0.713f * ((float)R - Y));
    Cb = 128 + (0.564f * ((float)B - Y)); */

    cb_y_cr_a.comp.y  =
               ( 16 + ((uint32_t)  (((66 * (int32_t)argbUnion.comp.r) +
                                    (129 * (int32_t)argbUnion.comp.g))+
                                     (25 * (int32_t)argbUnion.comp.b) ) >> 8));
    cb_y_cr_a.comp.cr =
               (128 + ((uint32_t) (((112 * (int32_t)argbUnion.comp.r) -
                                     (94 * (int32_t)argbUnion.comp.g))-
                                     (18 * (int32_t)argbUnion.comp.b) ) >> 8));
    cb_y_cr_a.comp.cb =
               (128 + ((uint32_t)(((-(38 * (int32_t)argbUnion.comp.r))-
                                     (74 * (int32_t)argbUnion.comp.g))+
                                    (112 * (int32_t)argbUnion.comp.b) ) >> 8));
    cb_y_cr_a.comp.alpha = argbUnion.comp.alpha;
    return(cb_y_cr_a.all);
}

/*!
*****************************************************************************
** \brief   Convert a colour code from ARGB to CbYCrA for 32-bit depth.
**
** \param   argbWord
**              Word that specifies a colour in the RGBA colour scheme.
**
** \return  Word that contains the colour coded in CbYCrA.
**
*****************************************************************************
*/
/* 21c7da30 - complete */
uint32_t OSDHANDLER_ConvertARGB2CbYCrA_word(const uint32_t argbWord)
{
    OSDHANDLER_ARGB__T a_r_g_b;
    a_r_g_b.all = argbWord;
    return(OSDHANDLER_ConvertARGB2CbYCrA_union(a_r_g_b));
}

/*!
*****************************************************************************
** \brief   Convert a colour that is coded in ARGB (1555) to a CbYCrA
**          (5551) coded colour value.
**
** \param   argb1555
**              Word that specifies a colour in the ARGB (1555) colour scheme.
**              The most significant bit is alpha, followed by 5 bits red,
**              5 bits green and 5 bits blue colour amounts.
**
** \return  16-bit word that contains the colour coded in CbYCrA (5551).
**
*****************************************************************************
*/
/* 21c7da34 - complete */
uint16_t OSDHANDLER_ConvertARGB2CbYCrA_5551(const uint16_t argb1555)
{
    uint16_t                result  = 0x0000;
    OSDHANDLER_ARGB__T      a_r_g_b;
    OSDHANDLER_CbYCrA__T    cb_y_cr_a;

    a_r_g_b.comp.alpha  = (argb1555 & 0x8000) >> 8;
    a_r_g_b.comp.r      = (argb1555 & 0x7C00) >> 7;
    a_r_g_b.comp.g      = (argb1555 & 0x03E0) >> 2;
    a_r_g_b.comp.b      = (argb1555 & 0x001F) << 3;

    cb_y_cr_a.all = OSDHANDLER_ConvertARGB2CbYCrA_union(a_r_g_b);
    if(argb1555 & 0x8000)
    {
        result |= 0x0001;   // set alpha value
    }
    result |= (cb_y_cr_a.comp.cb >> 3) << 11;
    result |= (cb_y_cr_a.comp.y  >> 3) <<  6;
    result |= (cb_y_cr_a.comp.cr >> 3) <<  1;

    return (result);
}

/*!
*****************************************************************************
** \brief   Convert a colour code from CbYCrA to RGBA for 32-bit depth.
**
** \param   cbycraUnion
**              Union that specifies a colour in the CbYCrA colour scheme.
**
** \return      Word that contains the colour coded in RGBA.
**
*****************************************************************************
*/
/* 21c7daa4 - complete */
uint32_t OSDHANDLER_ConvertCbYCrA2RGBA_union(const OSDHANDLER_CbYCrA__T cbycraUnion)
{
    OSDHANDLER_RGBA__T r_g_b_a;
    r_g_b_a.all = 0x00000000UL;

    r_g_b_a.comp.r  =
            ((uint32_t) (((298 * (int32_t)cbycraUnion.comp.y) +
                          (409 * (int32_t)cbycraUnion.comp.cr)) >> 8 ) - 223);
    r_g_b_a.comp.g  =
            (((uint32_t)(((298 * (int32_t)cbycraUnion.comp.y) -
                          (100 * (int32_t)cbycraUnion.comp.cb)) -
                          (208 * (int32_t)cbycraUnion.comp.cr)) >> 8 ) + 136);
    r_g_b_a.comp.b  =
            ((uint32_t) (((298 * (int32_t)cbycraUnion.comp.y) +
                          (516 * (int32_t)cbycraUnion.comp.cb)) >> 8 ) - 277);
    r_g_b_a.comp.alpha = cbycraUnion.comp.alpha;

    return(r_g_b_a.all);
}

/*!
*****************************************************************************
** \brief   Convert a colour code from CbYCrA to RGBA for 32-bit depth.
**
** \param   cbycraWord
**              Word that specifies a colour in the CbYCrA colour scheme.
**
** \return      Word that contains the colour coded in RGBA.
**
*****************************************************************************
*/
/* 21c7db58 - complete */
uint32_t OSDHANDLER_ConvertCbYCrA2RGBA_word(const uint32_t cbycraWord)
{
    OSDHANDLER_CbYCrA__T cb_y_cr_a_union;
    cb_y_cr_a_union.all = cbycraWord;
    return(OSDHANDLER_ConvertCbYCrA2RGBA_union(cb_y_cr_a_union));
}

/*!
*****************************************************************************
** \brief   Convert a colour that is coded in CbYCrA (5551) to a RGBA
**          (5551) coded colour value mode.
**
** \param   cbycra5551
**              Word that specifies a colour in the CbYCrA(5551) colour scheme.
**              The most significant 5 bits are red, followed by 5 bits green,
**              5 bits blue and 1 bit alpha amount.
**
** \return  16-bit word that contains the colour coded in RGBA (5551).
**
*****************************************************************************
*/
/* 21c7db5c - complete */
uint16_t OSDHANDLER_ConvertCbYCrA2RGBA_5551(const uint16_t cbycra5551)
{
    uint16_t                result  = 0x0000;
    OSDHANDLER_RGBA__T      r_g_b_a;
    OSDHANDLER_CbYCrA__T    cb_y_cr_a;

    // don't care:
    // cb_y_cr_a.comp.alpha = (cbycra5551 & 0x0001) << 7;
    cb_y_cr_a.comp.alpha = 0;
    cb_y_cr_a.comp.cr    = (cbycra5551 & 0x003E) << 2;
    cb_y_cr_a.comp.y     = (cbycra5551 & 0x07C0) >> 3;
    cb_y_cr_a.comp.cb    = (cbycra5551 & 0xF800) >> 8;
    r_g_b_a.all = OSDHANDLER_ConvertCbYCrA2RGBA_union(cb_y_cr_a);

    if(cbycra5551 & 0x0001)
    {
        result |= 0x0001; // set alpha value
    }
    result |= (r_g_b_a.comp.r >> 3) << 11;
    result |= (r_g_b_a.comp.b >> 3) <<  6;
    result |= (r_g_b_a.comp.b >> 3) <<  1;

    return (result);
}

/*!
*****************************************************************************
** \brief   Convert two ARGB pixels to two 16-bit CCIR pixels. The Cb and Cr
**          values will be interpolated, the Y values are individual for the
**          left and right pixel. The alpha values from the ARGB values will
**          be ignored.
**
** \param   leftARGB
**              ARGB value of the left pixel.
** \param   rightARGB
**              ARGB value of the right pixel.
**
** \return  A 32-bit value that contains the CCIR information for two pixels.
**
*****************************************************************************
*/
/* 21c7dbb4 - complete */
uint32_t OSDHANDLER_ConvertRGB2CCIR(const uint32_t leftARGB, const uint32_t rightARGB)
{
    uint32_t ccir = 0; // final ccir value
    OSDHANDLER_ARGB__T   argb_left;
    OSDHANDLER_ARGB__T   argb_right;
    OSDHANDLER_CbYCrA__T cb_y_cr_a_left;
    OSDHANDLER_CbYCrA__T cb_y_cr_a_right;

    argb_left.all = leftARGB;
    argb_right.all = rightARGB;
    cb_y_cr_a_left.all = 0x00000000UL;
    cb_y_cr_a_right.all = 0x00000000UL;

    // calculate left CbYCr value:
    cb_y_cr_a_left.comp.y  =
               ( 16 + ((uint32_t)  (((66 * (int32_t)argb_left.comp.r) +
                                    (129 * (int32_t)argb_left.comp.g))+
                                     (25 * (int32_t)argb_left.comp.b) ) >> 8));
    cb_y_cr_a_left.comp.cr =
               (128 + ((uint32_t) (((112 * (int32_t)argb_left.comp.r) -
                                     (94 * (int32_t)argb_left.comp.g))-
                                     (18 * (int32_t)argb_left.comp.b) ) >> 8));
    cb_y_cr_a_left.comp.cb =
               (128 + ((uint32_t)(((-(38 * (int32_t)argb_left.comp.r))-
                                     (74 * (int32_t)argb_left.comp.g))+
                                    (112 * (int32_t)argb_left.comp.b) ) >> 8));

    // calculate right CbYCr value:
    cb_y_cr_a_right.comp.y  =
               ( 16 + ((uint32_t)  (((66 * (int32_t)argb_right.comp.r) +
                                    (129 * (int32_t)argb_right.comp.g))+
                                     (25 * (int32_t)argb_right.comp.b) ) >> 8));
    cb_y_cr_a_right.comp.cr =
               (128 + ((uint32_t) (((112 * (int32_t)argb_right.comp.r) -
                                     (94 * (int32_t)argb_right.comp.g))-
                                     (18 * (int32_t)argb_right.comp.b) ) >> 8));
    cb_y_cr_a_right.comp.cb =
               (128 + ((uint32_t)(((-(38 * (int32_t)argb_right.comp.r))-
                                     (74 * (int32_t)argb_right.comp.g))+
                                    (112 * (int32_t)argb_right.comp.b) ) >> 8));

    // For the final CCIR value, interpolate Cb and Cr values
    // and keep the Y values individual.
    ccir |= ((cb_y_cr_a_left.comp.cb + cb_y_cr_a_right.comp.cb) / 2) << 24;
    ccir |= ((cb_y_cr_a_left.comp.cr + cb_y_cr_a_right.comp.cr) / 2) <<  8;
    ccir |= cb_y_cr_a_left.comp.y << 16;
    ccir |= cb_y_cr_a_right.comp.y;

    return(ccir);
}



// *****************************************************************************
// *****************************************************************************
// ************************** DEBUG FUNCTIONS **********************************
// *****************************************************************************
// *****************************************************************************
/* 21c7dde8 - complete */
void OSDHANDLERDEBUG_DumpLayerParams(uint32_t layer)
{
    OSDHANDLER_LayerParamsT     layerParams;
    OSDHANDLER_OsdCpParamsT*    osd_cp_params_ptr   = NULL;
    int32_t                     result              = 0;

    result = OSDHANDLER_GetLayerParameters(layer, &layerParams);
    if(result != FAPI_OK)
    {
        FAPI_SYS_PRINT_MSG("attention: GetlayerParameters did not return FAPI_OK. \n");
    }
    osd_cp_params_ptr = osdhandlerGetOsdCpParams(layer);

    if(!osd_cp_params_ptr)
    {
        FAPI_SYS_PRINT_MSG("bad OSD qualifier.");
        return;
    }

    FAPI_SYS_PRINT_MSG("\n");
    FAPI_SYS_PRINT_MSG("------- layer parameters ----------\n");
    FAPI_SYS_PRINT_MSG("picBase    :         0x%08lX\n", layerParams.pictureBase);
    FAPI_SYS_PRINT_MSG("width      :         %d\n",     layerParams.xRes);
    FAPI_SYS_PRINT_MSG("height     :         %d\n",     layerParams.yRes);
    FAPI_SYS_PRINT_MSG("bpp        :         %d\n",     layerParams.bpp);
    FAPI_SYS_PRINT_MSG("colourMode :         %d\n",     layerParams.colourMode);
    FAPI_SYS_PRINT_MSG("layoutMode :         %d\n",     layerParams.layoutMode);

    FAPI_SYS_PRINT_MSG("------- internal parameters -------\n");
    FAPI_SYS_PRINT_MSG("handle:             0x%08lX\n", osd_cp_params_ptr->fd);
    FAPI_SYS_PRINT_MSG("allocated memory:   0x%08lX\n", osd_cp_params_ptr->allocatedMemPtr);
    FAPI_SYS_PRINT_MSG("dynamic mem:        %s\n", osd_cp_params_ptr->isMemoryDynamic? "yes" : "no");
    FAPI_SYS_PRINT_MSG("fill colour:        0x%08lX\n", osd_cp_params_ptr->fillColour);
    FAPI_SYS_PRINT_MSG("layerEnable:        %s\n",osd_cp_params_ptr->scalerParams.layerEnable ? "yes" : "no");
    FAPI_SYS_PRINT_MSG("osdMode:            %d\n", osd_cp_params_ptr->scalerParams.osdMode);
    FAPI_SYS_PRINT_MSG("cpMode:             %d\n",osd_cp_params_ptr->scalerParams.cpMode);

    FAPI_SYS_PRINT_MSG("cpTileNumX:         %d\n",osd_cp_params_ptr->scalerParams.cpTileNumX);
    FAPI_SYS_PRINT_MSG("cpTileNumY:         %d\n",osd_cp_params_ptr->scalerParams.cpTileNumY);
    FAPI_SYS_PRINT_MSG("picBase:            0x%08lX\n", osd_cp_params_ptr->scalerParams.picBase);
    FAPI_SYS_PRINT_MSG("frameField:         %d\n",osd_cp_params_ptr->scalerParams.frameField);
    FAPI_SYS_PRINT_MSG("useGlobalAlpha:     %d\n",osd_cp_params_ptr->scalerParams.useGlobalAlpha);
    FAPI_SYS_PRINT_MSG("globalAlpha:        %d\n",osd_cp_params_ptr->scalerParams.globalAlpha);
    FAPI_SYS_PRINT_MSG("hilightOnOff:       %s\n", osd_cp_params_ptr->scalerParams.hilightOnOff? "on": "off");
    FAPI_SYS_PRINT_MSG("colourLut[256]:     0x%08lX\n",(uint32_t)osd_cp_params_ptr->scalerParams.colourLut);
    FAPI_SYS_PRINT_MSG("inputWindowX0:      %d\n",osd_cp_params_ptr->scalerParams.inputWindowX0);
    FAPI_SYS_PRINT_MSG("inputWindowY0:      %d\n",osd_cp_params_ptr->scalerParams.inputWindowY0);
    FAPI_SYS_PRINT_MSG("inputPicWidth:      %d\n", osd_cp_params_ptr->scalerParams.inputPicWidth);
    FAPI_SYS_PRINT_MSG("inputPicHeight:     %d\n", osd_cp_params_ptr->scalerParams.inputPicHeight);
    FAPI_SYS_PRINT_MSG("inputWindowWidth:   %d\n",osd_cp_params_ptr->scalerParams.inputWindowWidth);
    FAPI_SYS_PRINT_MSG("inputWindowHeight:  %d\n",osd_cp_params_ptr->scalerParams.inputWindowHeight);
    FAPI_SYS_PRINT_MSG("outputWindowX0:     %d\n",osd_cp_params_ptr->scalerParams.outputWindowX0);
    FAPI_SYS_PRINT_MSG("outputWindowY0:     %d\n",osd_cp_params_ptr->scalerParams.outputWindowY0);
    FAPI_SYS_PRINT_MSG("outputWindowWidth:  %d\n",osd_cp_params_ptr->scalerParams.outputWindowWidth);
    FAPI_SYS_PRINT_MSG("outputWindowHeight: %d\n",osd_cp_params_ptr->scalerParams.outputWindowHeight);
    /*lint -save -e923 */
    if((layer == 1) || (layer == 2))
    {
        FAPI_SYS_PRINT_MSG("FREG_VO_OSDMODE:    0x%08lX\n", *((uint32_t*)(0xCB004044UL + ((layer-1)*0x4000))));
    }
    else if (layer == 3)
    {
        FAPI_SYS_PRINT_MSG("FREG_VO_CURSORMODE: 0x%08lX\n", *((uint32_t*)0xCB00C044UL));
    }
    /*lint -restore */
    return;
}



