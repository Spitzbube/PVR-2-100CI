/*!
*****************************************************************************
**
** \file        ./subsystems/paint/osdhandler/src/osdhandler_priv.h
**
** \brief       Privately used header file.
**
** This file contains the declaration of private data for the OSDHANDLER.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2008 - 2009 by Fujitsu Microelectronics Limited
**
*****************************************************************************
*/

#ifndef OSDHANDLER_PRIV_H
    #define OSDHANDLER_PRIV_H

    #include <stdio.h>
    #include <stdint.h>
    #include "osdhandler.h"

    //***********************************************************************
    //***********************************************************************
    //** Private Defines and Macros
    //***********************************************************************
    //***********************************************************************

    /*! when converting 16bit (5551) colour to 32 bit true colour,
    **  the 1 bit alpha value 0.
    */
    #define OSDHANDLER_5551_Alpha0            0x80
    #define OSDHANDLER_5551_Alpha1            0xFF
    /*! when converting 8 bit alpha (32bit mode) to 1 bit
    **  alpha (5551 16bit mode), the threshold value
    */
    #define OSDHANDLER_Alpha_Threshold        0x80

    //***********************************************************************
    //***********************************************************************
    //** Private Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Keeps track of variables that are needed for the usage of the
    **        underlying Viscale driver (that provides the OSDs and the
    **        Cursor Plane). One instance of this structure is related to one
    **        specific OSD/CP.
    **
    ** handle:                  OSD/CP handle returned by the viscale driver when
    **                          the layer was opened
    ** allocatedMemPtr:         points to a field that has been allocated for the
    **                          usage of the OSD/CP
    ** isMemoryDynamic:         determines whether the allocatedMemPtr points to a
    **                          memory address that has been returned by
    **                          #FAPI_SYS_MALLOC (any value but 0) or if the
    **                          memory adress is static (0).
    ** fillColour:              colour code that will be used when the whole plane
    **                          is going to be filled up with a colour - this may
    **                          also be a 'transparent colour' in order to clear
    **                          the whole OSD layer and see the underlying layers
    ** scalerParams:            structure defined by the viscale driver that
    **                          keeps important values for an OSD when starting /
    **                          repositioning / rescaling it.
    *************************************************************************
    */
    typedef struct
    {
        FAPI_SYS_HandleT            fd; //0
        uint8_t*                    allocatedMemPtr; //4
        uint32_t                    isMemoryDynamic; //8
        uint32_t                    fillColour; //12
        FAPI_VISCALE_ScalerParamsT  scalerParams; //16
        OSDHANDLER_ColourModeT      colourMode; //1132
        OSDHANDLER_OsdLayoutEnumT   osdLayout; //1136
        uint32_t                    clut[256]; //1140
        //2164
    } OSDHANDLER_OsdCpParamsT;

    #if OSDHANDLER_USE_VIRTUAL_LAYERS
    /*!
    *************************************************************************
    ** \brief   Colour parameters used by the virtual layer system.
    *************************************************************************
    */
    typedef struct
    {
        uint32_t                    colour_mask;
        uint32_t*                   osd_base_ptr;
        uint32_t                    pixel_bit_offset;
        uint32_t                    data_mask;
        uint32_t                    temp_data;
        uint32_t                    data;
        uint32_t                    bpp;
        OSDHANDLER_ARGB__T          rgb;
    } OSDHANDLER_ColourParamsT;
    #endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    //***********************************************************************
    //***********************************************************************
    //** Private Data
    //***********************************************************************
    //***********************************************************************

        #ifdef OSDHANDLER_C

        uint32_t osdhandlerInitialized = 0; //21f71c8c
        FAPI_SYS_HandleT osdhandlerViencHdHandle = 0; //21f71c90
        uint32_t osdhandlerMaxHRES = OSDHANDLER_MAX_HRES; //21efe4cc
        uint32_t osdhandlerMaxVRES = OSDHANDLER_MAX_VRES; //21efe4d0
        OSDHANDLER_OsdCpParamsT osdhandlerOsd1Params; //2206c670
        OSDHANDLER_OsdCpParamsT osdhandlerOsd2Params; //2206cee4
        OSDHANDLER_OsdCpParamsT osdhandlerCpParams; //2206d758

        #if OSDHANDLER_USE_VIRTUAL_LAYERS
        // virtual layer system related data:
        uint32_t osdhandlerGroup1Started = 0;
        uint32_t osdhandlerGroup2Started = 0;
        uint32_t osdhandlerGroup1Shown   = 0;
        uint32_t osdhandlerGroup2Shown   = 0;
        uint32_t osdhandlerGroup1Updated = 1;
        uint32_t osdhandlerGroup2Updated = 1;

        /* Similar to a semaphore that locks the virtual layer system
        ** when the osdhandler is combining the virtual OSDs.
        */
        uint32_t osdhandlerFifoBusy      = 0;
        #endif // OSDHANDLER_USE_VIRTUAL_LAYERS

        #else // OSDHANDLER_C

        extern uint32_t osdhandlerInitialized;
        extern uint32_t osdhandlerMaxHRES;
        extern uint32_t osdhandlerMaxVRES;
        extern OSDHANDLER_OsdCpParamsT osdhandlerOsd1Params;
        extern OSDHANDLER_OsdCpParamsT osdhandlerOsd2Params;
        extern OSDHANDLER_OsdCpParamsT osdhandlerCpParams;

        #if OSDHANDLER_USE_VIRTUAL_LAYERS
        // virtual layer system related data:
        extern uint32_t osdhandlerGroup1Started;
        extern uint32_t osdhandlerGroup2Started;
        extern uint32_t osdhandlerGroup1Shown;
        extern uint32_t osdhandlerGroup2Shown;
        extern uint32_t osdhandlerGroup1Updated;
        extern uint32_t osdhandlerGroup2Updated;
        extern uint32_t osdhandlerFifoBusy;
        #endif // OSDHANDLER_USE_VIRTUAL_LAYERS

        #endif // OSDHANDLER_C

    //***********************************************************************
    //***********************************************************************
    //** Private Function Declarations
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    FAPI_VISCALE_OsdModeEnumT osdhandlerGetOsdColourMode
                           (const OSDHANDLER_ColourModeT osdhandlerColourMode);
    FAPI_VISCALE_CursorModeEnumT osdhandlerGetCpColourMode
                           (const OSDHANDLER_ColourModeT osdhandlerColourMode);
    FAPI_VISCALE_OsdLayoutEnumT osdhandlerGetOsdLayout
                           (const OSDHANDLER_OsdLayoutEnumT osdhandlerLayout);
    OSDHANDLER_OsdCpParamsT* osdhandlerGetOsdCpParams (const uint32_t osdIndex);
    uint32_t osdhandlerGetBitsPerPixel
                           (const OSDHANDLER_OsdCpParamsT* osdCpParamsPtr);
    int32_t osdhandlerSetUpOsdPlane(OSDHANDLER_OsdCpParamsT* osdParamsPtr,
                                    uint8_t* memoryBasePtr);
    void osdhandlerFill (const /*OSDHANDLER_OsdCpParamsT*/FAPI_VISCALE_ScalerParamsT* osdParamsPtr,
                         const uint32_t bpp, uint32_t colour);
    void osdhandlerGetPixelAddress(const uint32_t xx,
                                   const uint32_t yy,
                                   const uint32_t bpp,
                                   OSDHANDLER_OsdCpParamsT* osd_params_ptr,
                                   uint32_t* pixelBaseAddrPtr,
                                   uint32_t* pixelBitOffsetPtr);

#if OSDHANDLER_USE_VIRTUAL_LAYERS
    // virtual layer system related private functions:
    OSDHANDLER_OsdCpParamsT* osdvirtualGetOsdCpParams(const uint32_t layerId);
    int32_t osdvirtualStartLayer(const uint32_t layerId,
                                 OSDHANDLER_OsdCpParamsT* osdCpParamsPtr,
                                 const OSDHANDLER_StartParamsT* startParamsPtr);
    int32_t osdvirtualShowLayer(const uint32_t layerId,
                                OSDHANDLER_OsdCpParamsT* osdCpParamsPtr,
                                uint32_t* errorCodePtr);
    int32_t osdvirtualGlobalAlpha(OSDHANDLER_OsdCpParamsT* osdParamsPtr,
                                  const OSDHANDLER_ModeParamT mode,
                                  const uint32_t level);
#endif // OSDHANDLER_USE_VIRTUAL_LAYERS

    #ifdef __cplusplus
    }
    #endif

#endif // OSDHANDLER_PRIV_H
