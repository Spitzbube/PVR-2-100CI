/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_vd_ext.h
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
#if !defined(FREG_VD_EXT_H)
#define FREG_VD_EXT_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register 
**
** This function writes the given value to the register "CmdReset".
**
** 
**
** \param address Register address to be written.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VD_Write32( uint32_t address, uint32_t value );
#else
INLINE void FREG_VD_Write32( uint32_t address, uint32_t value )
{
    *((volatile uint32_t*)(FIO_ADDRESS(VD,address))) = value;
}
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
extern uint32_t FREG_VD_Read32( uint32_t address );
#else
INLINE uint32_t FREG_VD_Read32( uint32_t address )
{
    return(*((volatile uint32_t*)(FIO_ADDRESS(VD,address))));
}
#endif

#endif 
