/*!
*****************************************************************************
**
** \file        ./subsystems/fs/fatfs/include/usbdrv.h
** 
** \brief       FATFS driver API for USB mass storage devices.
**
** This file contains the declaration of the FATFS driver API for USB devices.
**
** \attention   THIS SAMPLE CODE IS PROVUSBD AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FATFS_USBDRV_H
    #define FATFS_USBDRV_H

    #include <stdio.h>
    #include <fatfs/fatfs.h>

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
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
        F_DRIVER* USBDRV_Init( unsigned long volumeParamsAddr );
    #ifdef __cplusplus
    }
    #endif

#endif /* FATFS_USBDRV_H */
