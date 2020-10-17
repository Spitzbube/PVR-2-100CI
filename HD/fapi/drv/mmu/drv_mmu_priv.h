/*!
********************************************************************************
**
** \file        ./fapi/drv/mmu/src/drv_mmu_priv.h
**
** \brief       MMU Driver private functions.
**
** This file contains the declaration of the MMU HEAP driver private functions.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/
#ifndef FAPI_MMU_PRIV_H
    #define FAPI_MMU_PRIV_H

    //**************************************************************************
    //**************************************************************************
    //** Private Functions
    //**************************************************************************
    //**************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    extern FAPI_SYS_HandleT mmuInternalOpen( FAPI_MMU_OpenParamsT* paramsPtr );
    extern void             mmuInternalClose( FAPI_SYS_HandleT handle );

    #ifdef __cplusplus
    }
    #endif
#endif
