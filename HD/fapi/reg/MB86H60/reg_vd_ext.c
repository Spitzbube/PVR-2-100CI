/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_vd_ext.c
**
** \brief     VD access functions
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** \note      Do not modify this file as it is generated automatically.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/
#define FREG_VD_EXT_C

#include <stdint.h>
#include "reg_vd_ext.h"

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register 
**
** This function writes the given value to the register .
**
** 
**
** \param address Register address to be written.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_1")))
#endif

void FREG_VD_Write32( uint32_t address, uint32_t value )
{
    *((volatile uint32_t*)(FIO_ADDRESS(VD,address))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register 
**
** This function reads from the given address.
**
** 
**
** \param address Register address to be read.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_1")))
#endif

uint32_t FREG_VD_Read32( uint32_t address )
{
    return(*((volatile uint32_t*)(FIO_ADDRESS(VD,address))));
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif


#endif

 
