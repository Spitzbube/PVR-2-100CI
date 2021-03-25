/*!
*****************************************************************************
**
** \file        ./subsystems/paint/fontserver/engines/fbf/src/fontserver_engine_fbf.h
**
** \brief       Declarations for the FBF engine interface.
**
**              This file contains the declaration of the FBF engine API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2007 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FONTSERVER_ENGINE_FBF_H
    #define FONTSERVER_ENGINE_FBF_H

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

    /*! \brief  Points to the interface of the actual instance of the FBF
    **          font engine.
    */
    extern const FONTSERVER_EngineT* FONTSERVER_ENGINE_FBF_INTERFACE_PTR;

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
