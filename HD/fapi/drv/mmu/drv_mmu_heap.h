/*!
********************************************************************************
**
** \file        ./fapi/drv/mmu/src/drv_mmu_heap.h
**
** \brief       MMU Driver heap memory management private functions.
**
** This file contains the declaration of the MMU HEAP driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/
#ifndef FAPI_MMU_HEAP_H
    #define FAPI_MMU_HEAP_H

    #include <fapi/sys_driver.h>

    //**************************************************************************
    //**************************************************************************
    //** Defines and Macros
    //**************************************************************************
    //**************************************************************************

    /*
    ****************************************************************************
    **
    ** The following two external symbols are required by the heap memory
    ** management functions to detect the start and the end of memory space
    ** to be used as "heap2".
    **
    ****************************************************************************
    */
    #if defined(__arm__) && !defined(__GNUC__)
    extern uint32_t __heap2_start__; // symbols defined in RVDS startup file
    extern uint32_t __heap2_end__;   // "boot/startup/arm1176_stack_heap.c"
    #endif

    #if defined(__arm__) && defined(__GNUC__)
    extern char_t __heap2_start__[]; // symbols defined by the GCC linker script
    extern char_t __heap2_end__[];   // "env/make/gcc-static.ld"
    #endif

    //**************************************************************************
    //**************************************************************************
    //** API Functions
    //**************************************************************************
    //**************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    int32_t FAPI_MMU_InitHeap(void);
    void    FAPI_MMU_ExitHeap(void);

    #ifdef __cplusplus
    }
    #endif
#endif
