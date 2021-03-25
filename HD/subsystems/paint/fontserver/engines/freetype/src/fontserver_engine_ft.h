/*!
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/engines/freetype/src/fontserver_engine_ft.h
**
** \brief       Declarations for the freetype engine interface.
**
**              This file contains the declaration of the freetype engine API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FONTSERVER_ENGINE_FT_H
    #define FONTSERVER_ENGINE_FT_H

    #include <stdint.h>
#if 0
    #include "fapex/abst_error.h"
#endif
    #include "fontserver/fontserver_engine.h"

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


    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************

    /*! \brief  Points to the interface of the actual instance of the
    **          freetype font engine.
    */
    extern const FONTSERVER_EngineT* FONTSERVER_ENGINE_FT_INTERFACE_PTR;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************
    #ifdef __cplusplus
    extern "C" {
    #endif

        // additional API functions here

    #ifdef __cplusplus
    }
    #endif
#endif
