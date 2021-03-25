/*
*****************************************************************************
**
** \file        ./subsystems/paint/draw/src/draw_scale.c
**
** \brief       DRAW Scale Driver
**
** This file contains the implementation of the DRAW driver's core API for
** picture scaling.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2008-2009 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2009      by Fujitsu Microelectronics Limited
**
*****************************************************************************
*/


#include "draw.h"
#include "draw_priv.h"

#if DRAW_ENABLE_RESIZE

#if 0
#include "fapex/abst_types.h"
#else
#include "fapi/sys_services.h"
#endif
#include "osdhandler/osdhandler.h"

//***************************************************************************
//***************************************************************************
//** Local Defines
//***************************************************************************
//***************************************************************************
#define DRAW_MIN_TRANSPARENTCY 0x10

/* Set the precision level here. (more precise is slower and vice-versa) */
#define CALCULATION_DOUBLE_PRECISION 0

#if CALCULATION_DOUBLE_PRECISION
    /* Set to "float" or "double" depending on desired precision. */
    typedef double CALCULATION_TYPE;
#else
    typedef float  CALCULATION_TYPE;
#endif

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
static uint8_t transparentColour = 0; //21f71c98

//***************************************************************************
//***************************************************************************
//** Local Functions Declaration
//***************************************************************************
//***************************************************************************

    static uint32_t  drawFloor          (CALCULATION_TYPE x);
    static uint32_t  drawSquared        (uint32_t x);
    static uint8_t   drawGetPixelRed    (uint32_t *bitmapData,
                                         uint32_t  bitmapWidth,
                                         uint32_t  xVal,
                                         uint32_t  yVal);
    static uint8_t   drawGetPixelGreen  (uint32_t *bitmapData,
                                         uint32_t  bitmapWidth,
                                         uint32_t  xVal,
                                         uint32_t  yVal);
    static uint8_t   drawGetPixelBlue   (uint32_t *bitmapData,
                                         uint32_t  bitmapWidth,
                                         uint32_t  xVal,
                                         uint32_t  yVal);
    static uint8_t   drawGetPixelAlpha  (uint32_t *bitmapData,
                                         uint32_t  bitmapWidth,
                                         uint32_t  xVal,
                                         uint32_t  yVal);
    static uint32_t  drawGetPixelAll    (uint32_t *bitmapData,
                                         uint32_t  bitmapWidth,
                                         uint32_t  xVal,
                                         uint32_t  yVal);
    /* Returns the pointer within the bitmap data, instead of the actual value. */
    static uint32_t* drawGetPixelPtr    (uint32_t *bitmapData,
                                         uint32_t  bitmapWidth,
                                         uint32_t  xVal,
                                         uint32_t  yVal);
    static uint32_t drawGetClutValue    (const DRAW_PicItemT* picPtr,
                                         uint8_t ClutIdx,
                                         uint32_t* clutToUse);
    static uint8_t drawGetBestColor     (uint32_t colorValue,
                                         const uint32_t* clutPtr,
                                         uint8_t a, uint8_t b);

    /*static*/ uint32_t drawExtractBitDepth(DRAW_ColourModeEnumT mode);


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


#define GET_RED(pixelval)       ((uint8_t)(((pixelval) & 0xFF000000) >> 24))
#define GET_GREEN(pixelval)     ((uint8_t)(((pixelval) & 0x00FF0000) >> 16))
#define GET_BLUE(pixelval)      ((uint8_t)(((pixelval) & 0x0000FF00) >> 8))
#define GET_ALPHA(pixelval)     ((uint8_t)((pixelval) & 0x000000FF))


/* 21c861d0 - complete */
static uint32_t drawFloor (CALCULATION_TYPE x)
{
    uint32_t val;

    val = (uint32_t) x;

    return val;
}

/* 21c861dc - complete */
static uint32_t drawSquared (uint32_t x)
{
    return (x * x);
}

/* 21c861e8 - complete */
static uint8_t drawGetPixelAlpha(uint32_t* bitmapData,
                      uint32_t  bitmapWidth,
                      uint32_t  xVal,
                      uint32_t  yVal)
{
    uint32_t    pixelval;
    uint8_t     final;

    if (bitmapData == NULL) return 0;

    pixelval = (uint32_t)*(bitmapData + ((yVal * bitmapWidth) + xVal));
    final = GET_ALPHA(pixelval);

    return final;
}

/* 21c861f8 - complete */
static uint8_t drawGetPixelRed(uint32_t* bitmapData,
                           uint32_t  bitmapWidth,
                           uint32_t  xVal,
                           uint32_t  yVal)
{
    uint32_t    pixelval;
    uint8_t     final;

    if (bitmapData == NULL) return 0;

    pixelval = (uint32_t)*(bitmapData + ((yVal * bitmapWidth) + xVal));
    final = GET_RED(pixelval);

    return final;
}

/* 21c8620c - complete */
static uint8_t drawGetPixelGreen(uint32_t* bitmapData,
                             uint32_t  bitmapWidth,
                             uint32_t  xVal,
                             uint32_t  yVal)
{
    uint32_t    pixelval;
    uint8_t     final;

    if (bitmapData == NULL) return 0;

    pixelval = (uint32_t)*(bitmapData + ((yVal * bitmapWidth) + xVal));
    final = GET_GREEN(pixelval);

    return final;
}

/* 21c86224 - complete */
static uint8_t drawGetPixelBlue(uint32_t* bitmapData,
                            uint32_t  bitmapWidth,
                            uint32_t  xVal,
                            uint32_t  yVal)
{
    uint32_t    pixelval;
    uint8_t     final;

    if (bitmapData == NULL) return 0;

    pixelval = (uint32_t)*(bitmapData + ((yVal * bitmapWidth) + xVal));
    final = GET_BLUE(pixelval);

    return final;
}

/* 21c8623c - complete */
static uint32_t drawGetPixelAll(uint32_t *bitmapData,
                                uint32_t  bitmapWidth,
                                uint32_t  xVal,
                                uint32_t  yVal)
{
    uint32_t    pixelval;

    if (bitmapData == NULL) return 0;

    pixelval = (uint32_t)*(bitmapData + ((yVal * bitmapWidth) + xVal));

    return pixelval;
}

    /* Returns the pointer within the bitmap data, instead of the actual value. */
/* 21c8624c - complete */
static uint32_t* drawGetPixelPtr(uint32_t* bitmapData,
                                 uint32_t  bitmapWidth,
                                 uint32_t  xVal,
                                 uint32_t  yVal)
{
    if (bitmapData == NULL) return 0;

    return (bitmapData + ((yVal * bitmapWidth) + xVal));
}

/* 21c86260 - complete */
static uint32_t drawGetClutValue (const DRAW_PicItemT* picPtr,
                                  uint8_t ClutIdx,
                                  uint32_t* clutToUse)
{
    uint16_t    IndexToFind;
    uint32_t*   pPtr;

    if (picPtr == NULL) return 0;

    if ((ClutIdx < picPtr->clutStartIdx) || (ClutIdx > picPtr->clutEndIdx))
    {
        IndexToFind = 0;
    }
    else
    {
        IndexToFind = ClutIdx;
    }

    pPtr = clutToUse + IndexToFind;

    return (*pPtr);

}


/* 21c8629c - complete */
static uint8_t drawGetBestColor(uint32_t colorValue,
      const uint32_t* clutPtr, uint8_t a, uint8_t b)
{
   uint16_t  x;
   uint32_t  lowestColorDiff = 0xFFFFFFFF;
   uint32_t  currentColorDiff;
   uint8_t   bestColorIdx = 0;
   uint32_t* currPtr;

   if (clutPtr == NULL)
       return 0;

   currPtr = (uint32_t*) clutPtr;

   if( ( colorValue & 0x000000FF) <= DRAW_MIN_TRANSPARENTCY)
   {
       bestColorIdx = transparentColour;
   }
   else
   {
       for (x = a; x < b; x++)
       {
           currentColorDiff = drawSquared((uint32_t)(((colorValue & 0xFF000000) >> 24) -
               (((*currPtr) & (0xFF000000)) >> 24))) +
                              drawSquared((uint32_t)(((colorValue & 0x00FF0000) >> 16) -
               (((*currPtr) & (0x00FF0000)) >> 16))) +
                              drawSquared((uint32_t)(((colorValue & 0x0000FF00) >> 8) -
               (((*currPtr) & (0x0000FF00)) >>  8))) +
                              drawSquared((uint32_t)(((colorValue & 0x000000FF)) -
               (((*currPtr) & (0x000000FF)) )));

           if (currentColorDiff <= lowestColorDiff)
           {
               bestColorIdx = (uint8_t)x;
               lowestColorDiff = currentColorDiff;
           }

           currPtr++;
       }
   }

   return (bestColorIdx);

}


/*!
*****************************************************************************
** \brief   Rescale a FBM picture.
**
** \note    If convPicPtr->fbmHeaderPtr or convPicPtr->dataPtr or
**          convPicPtr->clutPtr equals NULL, memory will be allocated
**          automatically. You have to deallocate this memory when the
**          picture is not needed any more by calling DRAW_FreeFbm().
**          For the clutPtr, memory will be allocated in case of 8-bit, 4-bit,
**          2-bit and 1-bit pictures only.
**
** \param clutPtr
**              Contains CLUT entries that will be used for the converted
**              picture.
** \param picPtr
**              Points to the source picture data which will be rescaled.
** \param convPicPtr
**              Points to a structure that will receive the rescaled picture.
** \param newWidth
**              Width of the converted picture.
** \param newHeight
**              Height of the converted picture.
**
** \return
**        - #FAPI_OK on success
**        - #DRAW_ERR_NOT_INITIALIZED if the DRAW driver is not initialized
**        - #DRAW_ERR_BAD_PARAMETER if
**          - picPtr is NULL
**          - convPicPtr is NULL
**          - (picPtr->clutId == 0) && (picPtr->clutPtr == NULL)
**          - if picPtr->fbmHeaderPtr->colourMode equals one of these:
**            DRAW_COLOURMODE_1BIT, DRAW_COLOURMODE_2BIT, DRAW_COLOURMODE_4BIT,
**            DRAW_COLOURMODE_8BIT, DRAW_COLOURMODE_24BIT, DRAW_COLOURMODE_32BIT
**        - #DRAW_ERR_OUT_OF_MEMORY if there was not enough memory available
**          for allocation in order to store the transcoded FBM picture file.
**
** \sa
**          - DRAW_FreeFbm()
**
*****************************************************************************
*/
/* 21c86394 - todo */
int32_t DRAW_ScalePicture_1(const DRAW_PicItemT* picPtr/*r9*/,
                           DRAW_PicItemT* convPicPtr/*fp*/,
                           const uint32_t newWidth/*r5*/,
                           const uint32_t newHeight/*r6*/)
{
   uint32_t* clutPtr = 0; //r7;
   uint32_t            NWidth  = 0; //sp28
   uint32_t            NHeight = 0; //sp32
   uint32_t            I       = 0;
   uint32_t            J       = 0;
   uint32_t            i       = 0;
   uint32_t            j       = 0;
   uint32_t            OldWidth  = 0; //sp44
   uint32_t            OldHeight = 0; //sp48
   uint32_t            previousI = 0xFFFFFFFFUL; // initialize to (uint32_t)-1UL
   uint32_t*           bitmapDest = NULL; //sp56
   uint32_t*           tempDestPtr = NULL;
   uint32_t            R, G, B, A, colorValue;
   uint32_t            Color00, Color10, Color01, Color11;
   uint32_t*           pixelPtr; //sp132
   int32_t             retValue;
   uint8_t*            ByteVal; //r5
   uint8_t             tempByteVal;
   uint16_t*           TwoByteVal;
   uint32_t            x, y;
   uint32_t*           bitmapSrc = NULL; //sp84
   uint8_t sp88 = 0;
   uint8_t sp92 = 0;
   uint32_t            cnt;
   CALCULATION_TYPE    a;
   CALCULATION_TYPE    b;
   CALCULATION_TYPE    c;
   CALCULATION_TYPE    d;
   CALCULATION_TYPE    multiplier;
   CALCULATION_TYPE    multiplier2;
   CALCULATION_TYPE    multiplier3;
   CALCULATION_TYPE    multiplier4;
   CALCULATION_TYPE    multiplier5;
   CALCULATION_TYPE    multiplier6;
   CALCULATION_TYPE    multiplier7;
   CALCULATION_TYPE    ThetaI;
   CALCULATION_TYPE    ThetaJ;
   
   uint32_t  ClutTable[256]; //sp = &sp176

   if ( ! drawInitialized )
   {
       return(DRAW_ERR_NOT_INITIALIZED);
   }
   if ((picPtr == NULL) || (convPicPtr == NULL))
   {
       return DRAW_ERR_BAD_PARAMETER;
   }

   if ((picPtr->dataPtr == NULL) || (picPtr->fbmHeaderPtr == NULL))
   {
       return DRAW_ERR_BAD_PARAMETER;
   }

   if ((picPtr->fbmHeaderPtr->colourMode == 0) ||
         (picPtr->fbmHeaderPtr->colourMode == 1) ||
         (picPtr->fbmHeaderPtr->colourMode == 2) ||
         (picPtr->fbmHeaderPtr->colourMode == 3) ||
         (picPtr->fbmHeaderPtr->colourMode == 10) ||
         (picPtr->fbmHeaderPtr->colourMode == 11))
   {
      return -2500101;
   }

   //21c86424
   if (convPicPtr->fbmHeaderPtr != NULL)
   {
      //->21c864b0
      if ((convPicPtr->fbmHeaderPtr->colourMode == 0) ||
            (convPicPtr->fbmHeaderPtr->colourMode == 1) ||
            (convPicPtr->fbmHeaderPtr->colourMode == 2) ||
            (convPicPtr->fbmHeaderPtr->colourMode == 3) ||
            (convPicPtr->fbmHeaderPtr->colourMode == 10) ||
            (convPicPtr->fbmHeaderPtr->colourMode == 11))
      {
         return -2500101;
      }
   }
   //21c86430
   if ((picPtr->clutId == 0) && (picPtr->clutPtr == NULL))
   {
      //->21c864cc
      if ((picPtr->fbmHeaderPtr->colourMode == 0) ||
            (picPtr->fbmHeaderPtr->colourMode == 1) ||
            (picPtr->fbmHeaderPtr->colourMode == 2) ||
            (picPtr->fbmHeaderPtr->colourMode == 3) ||
            (picPtr->fbmHeaderPtr->colourMode == 0x10000) ||
            (picPtr->fbmHeaderPtr->colourMode == 0x10001) ||
            (picPtr->fbmHeaderPtr->colourMode == 0x10002) ||
            (picPtr->fbmHeaderPtr->colourMode == 0x10003))
      {
         return DRAW_ERR_BAD_PARAMETER;
      }
   }
   //21c86448
   if (convPicPtr->allocInformation != 0)
   {
      //21c86454
      DRAW_FreeFbm(convPicPtr);
      
      convPicPtr->allocInformation = 0;
   }
   //21c86464
   memset(ClutTable, 0, sizeof(ClutTable));

   if (picPtr->clutId != 0)
   {
      //->21c8812c
       retValue = OSDHANDLER_GetClut(picPtr->clutId, ClutTable);
       if (retValue != FAPI_OK)
           return retValue;
       //->21c8651c
   }
   else
   {
      //21c86488
       switch (picPtr->fbmHeaderPtr->colourMode)
       {
               case DRAW_COLOURMODE_1BIT_RGB:
                  //21c88118
                   memcpy(ClutTable, picPtr->clutPtr, 8);
                   break;
               case DRAW_COLOURMODE_2BIT_RGB:
                  //21c88104
                   memcpy(ClutTable, picPtr->clutPtr, 16);
                   break;
               case DRAW_COLOURMODE_4BIT_RGB:
                  //21c880d4
                   memcpy(ClutTable, picPtr->clutPtr, 64);
                   break;
               case DRAW_COLOURMODE_8BIT_RGB:
                  //21c8650c
                   memcpy(ClutTable, picPtr->clutPtr, 1024);
                   break;

               case DRAW_COLOURMODE_1BIT:
               case DRAW_COLOURMODE_2BIT:
               case DRAW_COLOURMODE_4BIT:
               case DRAW_COLOURMODE_8BIT:
               case DRAW_COLOURMODE_24BIT:
               case DRAW_COLOURMODE_32BIT:
               case DRAW_COLOURMODE_16BIT_RGB:
               case DRAW_COLOURMODE_24BIT_RGB:
               case DRAW_COLOURMODE_32BIT_RGB:

               default:
                  //->21c8651c
                   /* We're not using the ClutTable at all. */
                   break;
       }
   }
   //21c8651c
   /* find transparent colour */
   for(cnt = picPtr->clutStartIdx; cnt <= picPtr->clutEndIdx; cnt++)
   {
       if( (ClutTable[cnt] & 0x000000FF) == 0)
           break;
   }
   //21c86564
   transparentColour = (uint8_t)cnt;

   OldWidth = picPtr->fbmHeaderPtr->width;
   OldHeight = picPtr->fbmHeaderPtr->height;
   NWidth = newWidth;
   NHeight = newHeight;

   if (NWidth < 1)
       NWidth = 1;

   if (NHeight < 1)
       NHeight = 1;

   /* Allocate memory if there is none yet (for the converted picture). */
   if (picPtr->fbmHeaderPtr->colourMode == DRAW_COLOURMODE_32BIT_RGB)
   {
      //->21c87b30
       if (convPicPtr->fbmHeaderPtr == NULL)
       {
          //->21c87c00
           convPicPtr->fbmHeaderPtr = (DRAW_FbmHeaderT *)FAPI_SYS_MALLOC(sizeof(DRAW_FbmHeaderT));
           if (convPicPtr->fbmHeaderPtr == NULL)
           {
              //->21c86730
               DRAW_FreeFbm(convPicPtr);
               return DRAW_ERR_OUT_OF_MEMORY;
           }
           //21c87c28
           convPicPtr->allocInformation |= 0x0001;
           memcpy(convPicPtr->fbmHeaderPtr, picPtr->fbmHeaderPtr, sizeof(DRAW_FbmHeaderT));
           //->21c87b3c
       }
       //21c87b3c
       if (convPicPtr->dataPtr == NULL)
       {
          //21c87bbc
           convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(( (NWidth)*(NHeight)) * sizeof(uint32_t));
           if (convPicPtr->dataPtr == NULL)
           {
              //->21c86730
               DRAW_FreeFbm(convPicPtr);
               return DRAW_ERR_OUT_OF_MEMORY;
           }
           //21c87bec
           convPicPtr->allocInformation |= 0x0002;
           //->21c87b4c
       }
       //21c87b4c
       bitmapSrc/*sp84*/ = picPtr->dataPtr;
       bitmapDest/*sp56*/ = (uint32_t *)(convPicPtr->dataPtr);
       //->21c86634
   }
   else
   {
      //21c865a8
       bitmapSrc = (uint32_t *)FAPI_SYS_MALLOC(( (OldWidth)*(OldHeight)) * sizeof(uint32_t));
       if (bitmapSrc == NULL)
       {
          //->21c86730
           DRAW_FreeFbm(convPicPtr);
           return DRAW_ERR_OUT_OF_MEMORY;
       }
       //21c865d4
       bitmapDest = (uint32_t *)FAPI_SYS_MALLOC(( (NWidth)*(NHeight)) * sizeof(uint32_t));
       if (bitmapDest == NULL)
       {
          //->21c87b18
           FAPI_SYS_FREE(bitmapSrc);
           //->21c86730
           DRAW_FreeFbm(convPicPtr);
           return DRAW_ERR_OUT_OF_MEMORY;
       }
       //21c86600
       if (convPicPtr->fbmHeaderPtr == NULL)
       {
          //->21c866c0
           convPicPtr->fbmHeaderPtr = (DRAW_FbmHeaderT *)FAPI_SYS_MALLOC(sizeof(DRAW_FbmHeaderT));
           if (convPicPtr->fbmHeaderPtr == NULL)
           {
              //21c86704
                FAPI_SYS_FREE(bitmapSrc);
                FAPI_SYS_FREE(bitmapDest);
                //21c86730
                DRAW_FreeFbm(convPicPtr);
                return DRAW_ERR_OUT_OF_MEMORY;
           }
           //21c866e4
           convPicPtr->allocInformation |= 0x0001;
           memcpy(convPicPtr->fbmHeaderPtr, picPtr->fbmHeaderPtr, sizeof(DRAW_FbmHeaderT));
       }
       //21c86610
       if (convPicPtr->dataPtr == NULL)
       {
          //->21c8667c
           x = NWidth;
           switch (picPtr->fbmHeaderPtr->colourMode)
           {
               case DRAW_COLOURMODE_1BIT_RGB:
                  //21c8680c
#if 0
                   while ((x % 8) != 0) // Align to nearest byte
                       x++;
#else
                   if ((x % 8) != 0)
                      x = (x & ~7) + 8;
#endif
                   convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(((x / 8) * NHeight));
                   //->21c86758
                   break;
               case DRAW_COLOURMODE_2BIT_RGB:
                  //21c867d8
#if 0
                   while ((x % 4) != 0) // Align to nearest byte
                       x++;
#else
                   if ((x % 4) != 0)
                      x = (x & ~3) + 4;
#endif
                   convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(((x / 4) * NHeight));
                   //->21c86758
                   break;
               case DRAW_COLOURMODE_4BIT_RGB:
                  //21c867a4
#if 0
                   while ((x % 2) != 0) // Align to nearest byte
                       x++;
#else
                   if ((x % 2) != 0)
                      x = x + 1;
#endif
                   convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(((x / 2) * NHeight));
                   //->21c86758
                   break;
               case DRAW_COLOURMODE_8BIT_RGB:
                  //21c8678c
#if 0
                   while ((x % 4) != 0) // Align to nearest 32-bit quantity
                       x++;
#else
                   x = x;
#endif
                   convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(((x) * NHeight));
                   //->21c86758
                   break;
               case DRAW_COLOURMODE_16BIT_RGB:
                  //21c86774
#if 0
                   while ((x % 4) != 0) // Align to nearest 32-bit quantity
                       x++;
#else
                   x = x;
#endif
                   convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(((x * 2) * NHeight));
                   //->21c86758
                   break;
               case DRAW_COLOURMODE_24BIT_RGB:
                  //21c86740
#if 0
                   while ((x % 4) != 0) // Align to nearest 32-bit quantity
                       x++;
#else
                   x = x;
#endif
                   convPicPtr->dataPtr = (uint32_t *)FAPI_SYS_MALLOC(((x * /*4*/3) * NHeight));
                   //21c86758
                   break;
               /* for 32-bit case, convPicPtr->dataPtr is already assigned. */
               case DRAW_COLOURMODE_1BIT:
               case DRAW_COLOURMODE_2BIT:
               case DRAW_COLOURMODE_4BIT:
               case DRAW_COLOURMODE_8BIT:
               case DRAW_COLOURMODE_24BIT:
               case DRAW_COLOURMODE_32BIT:
               case DRAW_COLOURMODE_32BIT_RGB:
               default:
                  //21c86704
                   break;
           }
           //21c86758
           if (convPicPtr->dataPtr == NULL)
           {
              //21c86704
               FAPI_SYS_FREE (bitmapSrc);
               FAPI_SYS_FREE (bitmapDest);
               DRAW_FreeFbm(convPicPtr);
               return DRAW_ERR_OUT_OF_MEMORY;
           }
           //21c86764
           convPicPtr->allocInformation |= 0x0002;
       }
       //21c8661c
       if ((convPicPtr->clutId == 0) && (convPicPtr->clutPtr == NULL) &&
          ((convPicPtr->fbmHeaderPtr->colourMode == 0x10000) ||
                (convPicPtr->fbmHeaderPtr->colourMode == 0x10001) ||
                (convPicPtr->fbmHeaderPtr->colourMode == 0x10002) ||
                (convPicPtr->fbmHeaderPtr->colourMode == 0x10003)))
       {
           //21c87b6c
           if(picPtr->fbmHeaderPtr->colourMode == DRAW_COLOURMODE_1BIT_RGB)
           {
              //->21c87cc4
               convPicPtr->clutPtr = (uint32_t *)FAPI_SYS_MALLOC(2*sizeof(uint32_t));
           }
           if(picPtr->fbmHeaderPtr->colourMode == DRAW_COLOURMODE_2BIT_RGB)
           {
              //->21c87c9c
               convPicPtr->clutPtr = (uint32_t *)FAPI_SYS_MALLOC(4*sizeof(uint32_t));
           }
           if(picPtr->fbmHeaderPtr->colourMode == DRAW_COLOURMODE_4BIT_RGB)
           {
              //->21c87c74
               convPicPtr->clutPtr = (uint32_t *)FAPI_SYS_MALLOC(16*sizeof(uint32_t));
           }
           if(picPtr->fbmHeaderPtr->colourMode == DRAW_COLOURMODE_8BIT_RGB)
           {
              //->21c87c54
               convPicPtr->clutPtr = (uint32_t *)FAPI_SYS_MALLOC(256*sizeof(uint32_t));
           }
           //21c87ba0
           if (convPicPtr->clutPtr == NULL)
           {
              //->21c86704
               FAPI_SYS_FREE(bitmapSrc);
               FAPI_SYS_FREE(bitmapDest);
               DRAW_FreeFbm(convPicPtr);
               return DRAW_ERR_OUT_OF_MEMORY;
           }
           //21c87bac
           convPicPtr->allocInformation |= 0x0004;
       }
   }
   //21c86634
   //TODO
   tempDestPtr = bitmapDest;
   /* Assign to "bitmapSrc" the bitmap data.  This must contain 32-bit color
      data.  Otherwise, convert original bitmap to 32-bit.  */
   pixelPtr = bitmapSrc;
   switch (picPtr->fbmHeaderPtr->colourMode)
   {
       case DRAW_COLOURMODE_1BIT_RGB:
          //21c87e68
           ByteVal/*r5*/ = (uint8_t *)(picPtr->dataPtr);
           for (y/*r8*/ = 0; y < OldHeight; y++)
           {
              //21c87e90
               for (x/*r7*/ = 0; x < OldWidth; x++)
               {
                  //21c87ea4
                   switch (x % 8)
                   {
                       case 0:
                          //21c8803c
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x80) >> 7), ClutTable); 
                          break;
                       case 1: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x40) >> 6), ClutTable); 
                          break;
                       case 2: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x20) >> 5), ClutTable); 
                          break;
                       case 3: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x10) >> 4), ClutTable); 
                          break;
                       case 4: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x08) >> 3), ClutTable); 
                          break;
                       case 5: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x04) >> 2), ClutTable); 
                          break;
                       case 6: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x02) >> 1), ClutTable); 
                          break;
                       case 7: 
                          *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x01)), ClutTable); 
                          break;
                       default:
                           break;
                   }
                   //21c87f50
                   pixelPtr++;

                   if ((x >= (OldWidth - 1)) || ((x % 8) == 7))
                   {
                      //21c87f94
                       ByteVal++;
                   }
                   //21c87f68
               }
               //21c87f80
           } //for (y/*r8*/ = 0; y < OldHeight; y++)
           //21c87470?
           //21c868b0?
           break;
       case DRAW_COLOURMODE_2BIT_RGB:
           //21c87e0c
           ByteVal = (uint8_t *)(picPtr->dataPtr);
           for (y = 0; y < OldHeight; y++)
           {
               for (x = 0; x < OldWidth; x++)
               {
                   switch (x % 4)
                   {
                       case 0: *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0xC0) >> 6), ClutTable); break;
                       case 1: *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x30) >> 4), ClutTable); break;
                       case 2: *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x0C) >> 2), ClutTable); break;
                       case 3: *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0x03)), ClutTable); break;
                       default:
                           break;

                   }

                   pixelPtr++;

                   if ((x >= (OldWidth - 1)) || ((x % 4) == 3))
                   {
                       ByteVal++;
                   }
               }
           }
           break;
       case DRAW_COLOURMODE_4BIT_RGB:
          //21c87d78
           ByteVal = (uint8_t *)(picPtr->dataPtr);
           for (y = 0; y < OldHeight; y++)
           {
               x = 0;
               while (x < OldWidth)
               {
                   *pixelPtr = drawGetClutValue(picPtr, (((*ByteVal) & 0xF0) >> 4), ClutTable);

                   x++;
                   pixelPtr++;

                   if (x < OldWidth)
                   {
                       *pixelPtr = drawGetClutValue(picPtr, ((*ByteVal) & 0x0F), ClutTable);

                       pixelPtr++;

                   }
                   x++;
                   ByteVal++;
               }
           }
           break;
       case DRAW_COLOURMODE_8BIT_RGB:
          //21c87cec
           ByteVal = (uint8_t *)(picPtr->dataPtr);
           for (y = 0; y < OldHeight; y++)
           {
               for (x = 0; x < OldWidth; x++)
               {
                   *pixelPtr = drawGetClutValue(picPtr, (*ByteVal), ClutTable);

                   pixelPtr++;
                   ByteVal++;
               }

           }
           break;
       case DRAW_COLOURMODE_16BIT_RGB:
          //21c873b8
           TwoByteVal = (uint16_t *)(void*)(picPtr->dataPtr);
           for (y = 0; y < OldHeight; y++)
           {
               for (x = 0; x < OldWidth; x++)
               {
                   //21c873f0
                   // formula is based on getting the appropriate color, multiplying by 8 to get
                   // the 8-bit component value and finally shifting it to the correct location
                   // in the RGBA word
                   *pixelPtr = (((*TwoByteVal) & 0xF800) << 16) + 
                       (((*TwoByteVal) & 0x07C0) << 13) +
                       (((*(TwoByteVal)) & 0x003E) << 10) +
                       (picPtr->globalAlpha & 0xFF);
#if 0
                   if (*TwoByteVal & 0x0001)
                   {
                       *pixelPtr += 0xFF;
                   }
#endif
                   pixelPtr++;
                   TwoByteVal++;
               }
#if 0
               /* Increment original bitmap bytes, to skip alignment padding */
               while ((x % 4) != 0)
               {
                   TwoByteVal++;
                   x++;
               }
#endif
           }
           break;
       case DRAW_COLOURMODE_24BIT_RGB:
          //21c8731c
           ByteVal/*lr*/ = (uint8_t *)(picPtr->dataPtr);
           for (y/*r7*/ = 0; y < OldHeight; y++)
           {
               //21c87338
               for (x/*ip*/ = 0; x < OldWidth; x++)
               {
                   //21c87354
                   *pixelPtr = ((*(ByteVal + 2)) << 24) | 
                       ((*(ByteVal + 1)) << 16) |
                       ((*(ByteVal)) << 8) | 
                       picPtr->globalAlpha;

                   pixelPtr++;
                   ByteVal+= 3;
               }
#if 0
               /* Increment original bitmap bytes, to skip alignment padding */
               while ((x % 4) != 0)
               {
                   ByteVal+= 4;
                   x++;
               }
#endif
           }
           //21c87460
           break;
       case DRAW_COLOURMODE_32BIT_RGB:
          //21c868a4
           /* no more conversion necessary. */
           break;

       case DRAW_COLOURMODE_1BIT:
       case DRAW_COLOURMODE_2BIT:
       case DRAW_COLOURMODE_4BIT:
       case DRAW_COLOURMODE_8BIT:
       case DRAW_COLOURMODE_24BIT:
       case DRAW_COLOURMODE_32BIT:
       default:
          //21c86844
           if (bitmapSrc != picPtr->dataPtr)
           {
               FAPI_SYS_FREE(bitmapSrc);
           }
           if (bitmapDest != convPicPtr->dataPtr)
           {
               FAPI_SYS_FREE(bitmapDest);
           }
           DRAW_FreeFbm(convPicPtr);
           return DRAW_ERR_BAD_PARAMETER;
   }
   //21c868b0?
#if CALCULATION_DOUBLE_PRECISION
   a = OldHeight - 1.0d;
   b = NHeight - 1.0d;
   c = OldWidth - 1.0d;
   d = NWidth - 1.0d;
#else
   a = OldHeight - 1.0f;
   b = NHeight - 1.0f;
   c = OldWidth - 1.0f;
   d = NWidth - 1.0f;
#endif

   multiplier = -a;

   /* Optimization: Multiply by the reciprocal rather than dividing of the dividend (for
   the multiplication operations below. */
#if CALCULATION_DOUBLE_PRECISION
   b = 1.0d/b;
   d = 1.0d/d;
#else
   b = 1.0f/b;
   d = 1.0f/d;
#endif

   for( j=0; j < (NHeight-1) ; j++ )
   {
       multiplier += a;
       ThetaJ = multiplier * b; // = (i * oldHeight) / newHeight
       J   = drawFloor( ThetaJ ); // = floor((i * oldHeight) / newHeight)
       ThetaJ -= J;
       multiplier2 = -c;

       /* Initialize 2x2 Colour Grid */
       Color00 = 0; // current pixel
       Color01 = 0; // pixel below
       Color10 = 0; // pixel on the right
       Color11 = 0; // pixel below on the right

       /* Initialize to -1 */
       previousI = 0xFFFFFFFFUL;

       // all 2x2 Colour Grids
       for( i=0; i < (NWidth-1) ; i++ )
       {
           multiplier2 += c;
           ThetaI = multiplier2 * d; // = (i * oldWidth) / newWidth
           I = drawFloor( ThetaI ); // = floor((i * oldWidth) / newWidth)
           ThetaI -= I;

           if (previousI != I)
           {
               pixelPtr = drawGetPixelPtr(bitmapSrc, OldWidth, I, J);
               Color00 = *pixelPtr;
               pixelPtr++;
               Color10 = *pixelPtr;
               pixelPtr = drawGetPixelPtr(bitmapSrc, OldWidth, I, J+1);
               Color01 = *pixelPtr;
               pixelPtr++;
               Color11 = *pixelPtr;
               previousI = I;
           }
           else
           {
               /* If previous I is the same, then there is no need to update the color grid. */
           }
           multiplier3 = ThetaI * ThetaJ;
           multiplier4 = (1.0 - ThetaI) - ThetaJ;
           multiplier5 = multiplier4 + multiplier3;
           multiplier6 = ThetaI-multiplier3;
           multiplier7 = ThetaJ-multiplier3;


           R = (uint8_t)
                         ( ((multiplier5)*(GET_RED(Color00)))
                          +((multiplier6)*(GET_RED(Color10)))
                          +((multiplier7)*(GET_RED(Color01)))
                          +((multiplier3)*(GET_RED(Color11))) );
           G = (uint8_t)
                         ( ((multiplier5)*(GET_GREEN(Color00)))
                          +((multiplier6)*(GET_GREEN(Color10)))
                          +((multiplier7)*(GET_GREEN(Color01)))
                          +((multiplier3)*(GET_GREEN(Color11))) );
           B = (uint8_t)
                         ( ((multiplier5)*(GET_BLUE(Color00)))
                          +((multiplier6)*(GET_BLUE(Color10)))
                          +((multiplier7)*(GET_BLUE(Color01)))
                          +((multiplier3)*(GET_BLUE(Color11))) );

           A = (uint8_t)
                         ( ((multiplier5)*(GET_ALPHA(Color00)))
                          +((multiplier6)*(GET_ALPHA(Color10)))
                          +((multiplier7)*(GET_ALPHA(Color01)))
                          +((multiplier3)*(GET_ALPHA(Color11))) );

           colorValue = (R << 24) | (G << 16) | (B << 8) | (A);
           *tempDestPtr = colorValue;

           tempDestPtr++;
       }
       // process the last column (no pixels on the right):

       // not precise (~~rk):
       //Color00 = drawGetPixelAll(bitmapSrc, OldWidth, (OldWidth-1), J);
       //Color01 = drawGetPixelAll(bitmapSrc, OldWidth, (OldWidth-1), J+1);

       multiplier2 += c;
       ThetaI = multiplier2 * d;
       I = drawFloor( ThetaI );

       Color00 = drawGetPixelAll(bitmapSrc, OldWidth, I, J);
       Color01 = drawGetPixelAll(bitmapSrc, OldWidth, I, J+1);

       R = (uint8_t)( ((1.0-ThetaJ)*(GET_RED(Color00)))
                         + (ThetaJ*(GET_RED(Color01))) );
       G = (uint8_t)( ((1.0-ThetaJ)*(GET_GREEN(Color00)))
                         + (ThetaJ*(GET_GREEN(Color01))) );
       B = (uint8_t)( ((1.0-ThetaJ)*(GET_BLUE(Color00)))
                         + (ThetaJ*(GET_BLUE(Color01))) );
       A = (uint8_t)( ((1.0-ThetaJ)*(GET_ALPHA(Color00)))
                         + (ThetaJ*(GET_ALPHA(Color01))) );

       colorValue = (R << 24) | (G << 16) | (B << 8) | (A);
       *tempDestPtr = colorValue;
       tempDestPtr++;
   }

   for( i = 0 ; i < (NWidth-1) ; i++ )
   {
       #if CALCULATION_DOUBLE_PRECISION
       // double precision:
       ThetaI = (CALCULATION_TYPE)(i*(OldWidth-1.0d)) / (CALCULATION_TYPE)(NWidth-1.0d);
       #else
       // single precision:
       ThetaI = (CALCULATION_TYPE)(i*(OldWidth-1.0f)) / (CALCULATION_TYPE)(NWidth-1.0f);
       #endif

       I = drawFloor( ThetaI );
       ThetaI -= I;
       R = (uint8_t)  ( ((1.0-ThetaI)*(drawGetPixelRed(bitmapSrc, OldWidth, I, (OldHeight-1))))
                         + (ThetaI*(drawGetPixelRed(bitmapSrc, OldWidth, I, (OldHeight-1)))) );
       G = (uint8_t)  ( ((1.0-ThetaI)*(drawGetPixelGreen(bitmapSrc, OldWidth, I, (OldHeight-1))))
                         + (ThetaI*(drawGetPixelGreen(bitmapSrc, OldWidth, I, (OldHeight-1)))) );
       B = (uint8_t)  ( ((1.0-ThetaI)*(drawGetPixelBlue(bitmapSrc, OldWidth, I, (OldHeight-1))))
                         + (ThetaI*(drawGetPixelBlue(bitmapSrc, OldWidth, I, (OldHeight-1)))) );
       A = (uint8_t)  ( ((1.0-ThetaI)*(drawGetPixelAlpha(bitmapSrc, OldWidth, I, (OldHeight-1))))
                         + (ThetaI*(drawGetPixelAlpha(bitmapSrc, OldWidth, I, (OldHeight-1)))) );

       colorValue = (R << 24) | (G << 16) | (B << 8) | (A);
       *tempDestPtr = colorValue;
       tempDestPtr++;
   }

   *tempDestPtr = drawGetPixelAll(bitmapSrc, OldWidth, (OldWidth - 1), (OldHeight - 1));

   /* Finally, update the type, width, and height information. */
   
   uint32_t r1 = drawExtractBitDepth(convPicPtr->fbmHeaderPtr->colourMode);
  
   if (convPicPtr->clutId == 0)
   {
      if ((convPicPtr->clutPtr != NULL) &&
            (convPicPtr->allocInformation & 0x0004))
      {
         //21c87260
         memcpy(convPicPtr->clutPtr,
               ClutTable, //sp176,
               4 << r1);

         convPicPtr->clutStartIdx = picPtr->clutStartIdx;
         convPicPtr->clutEndIdx = picPtr->clutEndIdx;
      }

      clutPtr = convPicPtr->clutPtr;
   }
   else
   {
      //->21c87498
      retValue = OSDHANDLER_GetClut(convPicPtr->clutId,
            ClutTable); //sp176);
      
      if (retValue != 0)
      {
         //21c874ac         
         if (bitmapSrc/*sp84*/ != picPtr->dataPtr)
         {
            FAPI_SYS_FREE(bitmapSrc);
         }
         //21c874d4
         if (bitmapDest/*sp56*/ != convPicPtr->dataPtr)
         {
            FAPI_SYS_FREE(bitmapDest);
         }
         //21c874fc
         DRAW_FreeFbm(convPicPtr);

         return retValue;
      }
      //->21c87288
      clutPtr = ClutTable;
   }
   //21c87288
   convPicPtr->fbmHeaderPtr->width = NWidth;
   convPicPtr->fbmHeaderPtr->height = NHeight;

   sp88 = convPicPtr->clutStartIdx;
   sp92 = convPicPtr->clutEndIdx;

   //TODO

   /* Perform necessary cleanup and conversion, depending on CLUT-type */
   switch (convPicPtr->fbmHeaderPtr->colourMode)
   {
       case DRAW_COLOURMODE_1BIT_RGB:
          //21c87858
           ByteVal = (uint8_t*)(convPicPtr->dataPtr);
           pixelPtr = bitmapDest;
           for (y/*sp140*/ = 0; y < NHeight; y++)
           {
               //21c8787c
               for (x/*sl*/ = 0; x < NWidth; x++)
               {
                   //21c87890
                   switch (x % 8)
                   {
                       case 0:
                          //21c87a6c
                          *ByteVal = (uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 7);
                          //->21c8795c
                          break;
                       case 1:
                          //21c87a8c
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 6));
                          break;
                       case 2:
                          //21c87a48
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 5));
                          break;
                       case 3:
                          //21c87a24
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 4));
                          break;
                       case 4:
                          //21c87a00
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 3));
                          break;
                       case 5:
                          //21c879dc
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 2));
                          break;
                       case 6:
                          //21c879b8
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 1));
                          break;
                       case 7:
                          //21c8793c
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 0));
                          break;
                       default:
                          //->21c8795c
                           break;
                   }
                   pixelPtr++;
                   if ((x >= (NWidth - 1)) || ((x % 8) == 7))
                   {
                       ByteVal++;
                   }
               }
               //21c87994
           }
           //->21c87518
           break;
       case DRAW_COLOURMODE_2BIT_RGB:
          //21c87800
#if 1
           ByteVal/*r5*/ = (uint8_t*)(convPicPtr->dataPtr);
           pixelPtr/*sp136*/ = bitmapDest;
           for (y/*sp144*/ = 0; y < NHeight; y++)
           {
               //21c87824
               for (x/*sl*/ = 0; x < NWidth; x++)
               {
                   //21c87838
                   switch (x % 4)
                   {
                       case 0:
                          //21c87ad4
                          *ByteVal = (uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 6);
                          break;
                       case 1:
                          //21c87af4
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 4));
                          break;
                       case 2:
                          //21c87ab0
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 2));
                          break;
                       case 3:
                          //21c878c0
                          *ByteVal = (*ByteVal) | ((uint8_t)(drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 0));
                          break;
                       default:
                           break;
                   }
                   //21c878e0
                   pixelPtr++;
                   if ((x >= (NWidth - 1)) || ((x % 4) == 3))
                   {
                       ByteVal++;
                   }
               }
               //21c87918
           }
           //21c87518
#endif
           break;
       case DRAW_COLOURMODE_4BIT_RGB:
          //21c87764
#if 1
           ByteVal = (uint8_t*)(convPicPtr->dataPtr);
           pixelPtr/*r6*/ = bitmapDest;
           for (y/*r8*/ = 0; y < NHeight; y++)
           {
               //21c87780
               x/*r5*/ = 0;
               while ( x < NWidth )
               {
                   tempByteVal = drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92) << 4;
                   //tempByteVal = (uint8_t)(tempByteVal << 4);
                   x++;
                   pixelPtr++;
                   if (x < NWidth)
                   {
                       tempByteVal = (tempByteVal) | (drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92));
                       pixelPtr++;
                   }
                   *ByteVal = tempByteVal;
                   x++;
                   ByteVal++;
               }
               //21c877ec
           }
           //21c87518
#endif
           break;
       case DRAW_COLOURMODE_8BIT_RGB:
           //21c876d0
#if 1
           ByteVal = (uint8_t*)(convPicPtr->dataPtr);
           pixelPtr/*r6*/ = bitmapDest;
           for (y/*sp80*/ = 0; y < NHeight; y++)
           {
               //21c876f0
               for (x/*r4*/ = 0; x < NWidth; x++)
               {
                   *ByteVal = drawGetBestColor(*pixelPtr, clutPtr, /*convPicPtr->clutStartIdx*/sp88, /*convPicPtr->clutEndIdx*/sp92);
                   pixelPtr++;
                   ByteVal++;
               }
               //21c87748
           }
           //21c87518
#endif
           break;
       case DRAW_COLOURMODE_16BIT_RGB:
           //21c87618
#if 1
           convPicPtr->clutId = 0x00000000;
           convPicPtr->clutStartIdx = 0;
           convPicPtr->clutEndIdx = 0;

           TwoByteVal = (uint16_t*)(void*)(convPicPtr->dataPtr);
           pixelPtr = bitmapDest;

           for (y = 0; y < NHeight; y++)
           {
               for (x = 0; x < NWidth; x++)
               {
                   // Must perform successive shifts (rather than only one),
                   // to drop the unnecessary bits during this conversion process
                   *TwoByteVal = ((uint16_t)(((((*pixelPtr) & (0xFF000000)) >> 24) >> 3) << 11)) +
                       ((uint16_t)(((((*pixelPtr) & (0x00FF0000)) >> 16) >> 3) << 6)) +
                       ((uint16_t)(((((*pixelPtr) & (0x0000FF00)) >> 8) >> 3) << 1));
                   if ((*pixelPtr) & 0x000000FF)
                   {
                       *TwoByteVal += 1;
                   }
                   TwoByteVal++;
                   pixelPtr++;
               }
           }
           //->21c87518
#endif
           break;
       case DRAW_COLOURMODE_24BIT_RGB:
           //21c87578
           convPicPtr->clutId = 0x00000000;
           convPicPtr->clutStartIdx = 0;
           convPicPtr->clutEndIdx = 0;

           ByteVal = (uint8_t*)(convPicPtr->dataPtr);
           pixelPtr = bitmapDest;

           for (y = 0; y < NHeight; y++)
           {
               for (x = 0; x < NWidth; x++)
               {
                   //*ByteVal = (uint8_t)(picPtr->globalAlpha); ByteVal++;
                   *ByteVal = (uint8_t)(((*pixelPtr) & 0x0000FF00) >> 8); ByteVal++;
                   *ByteVal = (uint8_t)(((*pixelPtr) & 0x00FF0000) >> 16); ByteVal++;
                   *ByteVal = (uint8_t)(((*pixelPtr) & 0xFF000000) >> 24); ByteVal++;
                   pixelPtr++;
               }
           }
           break;
       case DRAW_COLOURMODE_32BIT_RGB:
           //21c87508
           convPicPtr->clutId = 0x00000000;
           convPicPtr->clutStartIdx = 0;
           convPicPtr->clutEndIdx = 0;
           break;

       case DRAW_COLOURMODE_1BIT:
       case DRAW_COLOURMODE_2BIT:
       case DRAW_COLOURMODE_4BIT:
       case DRAW_COLOURMODE_8BIT:
       case DRAW_COLOURMODE_24BIT:
       case DRAW_COLOURMODE_32BIT:
       default:
          //->21c87518
           break;
   }
   //21c87518
   if (bitmapSrc != picPtr->dataPtr)
   {
       FAPI_SYS_FREE(bitmapSrc);
   }
   if (bitmapDest != convPicPtr->dataPtr)
   {
       FAPI_SYS_FREE(bitmapDest);
   }
   return FAPI_OK;
}

#endif /* DRAW_ENABLE_RESIZE */
