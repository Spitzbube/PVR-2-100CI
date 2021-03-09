/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_sdram.h
**
** \brief     SDRAM access functions
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** (C) Copyright 2006-2008 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/
#if !defined(FREG_SDRAM_H)
#define FREG_SDRAM_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#endif

/*
********************************************************************************
**
** Memory location definition
**
********************************************************************************
*/
#define FREG_SDRAM_BASE_ADDRESS FIO_ADDRESS(SRAM,0x02000000UL)

#endif
