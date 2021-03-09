/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_ve.c
**
** \brief     VE access functions
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
#define FREG_VE_C

#include <stdint.h>
#include "reg_ve.h"

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
volatile uint32_t FREG_VE_SdCcfilterlum0Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum1Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum2Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum3Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum4Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum5Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum6Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum7Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum8Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterlum9Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom2Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom3Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom4Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom5Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom6Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom7Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom8Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterchrom9Mirror = 0;
volatile uint32_t FREG_VE_SdCcfilterhorstartMirror = 0;
volatile uint32_t FREG_VE_SdCcfilterhorstopMirror = 0;
volatile uint32_t FREG_VE_SdCcfilterverstartMirror = 0;
volatile uint32_t FREG_VE_SdCcfilterverstopMirror = 0;
volatile uint32_t FREG_VE_SdCcfilterblankstartMirror = 0;
volatile uint32_t FREG_VE_SdCcfilterblankstopMirror = 0;
volatile uint32_t FREG_VE_SdCcfilterenableMirror = 0;
volatile uint32_t FREG_VE_SdHorlinelengthMirror = 0;
volatile uint32_t FREG_VE_SdVersizeMirror = 0;
volatile uint32_t FREG_VE_SdBackgroundMirror = 0;
volatile uint32_t FREG_VE_SdVohorstartMirror = 0;
volatile uint32_t FREG_VE_SdVohorstopMirror = 0;
volatile uint32_t FREG_VE_SdVoverstartMirror = 0;
volatile uint32_t FREG_VE_SdVoverstopMirror = 0;
volatile uint32_t FREG_VE_SdTtxhorstartMirror = 0;
volatile uint32_t FREG_VE_SdhvsynccfgMirror = 0;
volatile uint32_t FREG_VE_SdvsyncoffsetMirror = 0;
volatile uint32_t FREG_VE_SdvsyncevstartMirror = 0;
volatile uint32_t FREG_VE_SdvsyncovstartMirror = 0;
volatile uint32_t FREG_VE_SdvsyncevstopMirror = 0;
volatile uint32_t FREG_VE_SdvsyncovstopMirror = 0;
volatile uint32_t FREG_VE_SdvsyncehstartMirror = 0;
volatile uint32_t FREG_VE_SdvsyncohstartMirror = 0;
volatile uint32_t FREG_VE_SdvsyncehstopMirror = 0;
volatile uint32_t FREG_VE_SdvsyncohstopMirror = 0;
volatile uint32_t FREG_VE_SdhsyncstartMirror = 0;
volatile uint32_t FREG_VE_SdhsyncstopMirror = 0;
volatile uint32_t FREG_VE_SdhsyncoffsetMirror = 0;
volatile uint32_t FREG_VE_VoOsd1clutMirror[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_VE_VoOsd2clutMirror[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_VE_VoCursorclutMirror[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_VE_SdSecfieldoffsetMirror = 0;
volatile uint32_t FREG_VE_RgbconfMirror = 0;
volatile uint32_t FREG_VE_RgblumMirror = 0;
volatile uint32_t FREG_VE_RgbchromMirror = 0;
volatile uint32_t FREG_VE_CeconfMirror = 0;
volatile uint32_t FREG_VE_CeburstintMirror = 0;
volatile uint32_t FREG_VE_Ceburstfra1Mirror = 0;
volatile uint32_t FREG_VE_Ceburstfra2Mirror = 0;
volatile uint32_t FREG_VE_DacPdMirror = 0;
volatile uint32_t FREG_VE_Enc656wssMirror = 0;
volatile uint32_t FREG_VE_Ccline21Mirror = 0;
volatile uint32_t FREG_VE_Ccline284Mirror = 0;
volatile uint32_t FREG_VE_VbidwordsMirror = 0;
volatile uint32_t FREG_VE_WssdataMirror = 0;
volatile uint32_t FREG_VE_LutConfMirror = 0;
volatile uint32_t FREG_VE_LutYMirror[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_VE_LutCrMirror[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_VE_LutCbMirror[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum0".
**
** This function writes the given value to the register "SdCcfilterlum0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_1")))
#endif

void FREG_VE_SetSdCcfilterlum0( uint32_t value )
{
    FREG_VE_SdCcfilterlum0Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM0)) = value;
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
** \brief Writes the bitgroup "YCoeff0" of register "SdCcfilterlum0".
**
** Y coefficient 0 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff0" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_2")))
#endif

void FREG_VE_SetSdCcfilterlum0_YCoeff0( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum0Mirror & ~mask;
    FREG_VE_SdCcfilterlum0Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM0)) = value;
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
** \brief Reads the entire register "SdCcfilterlum0".
**
** This function reads the value from the register "SdCcfilterlum0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_3")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum0( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum0Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff0" of register "SdCcfilterlum0".
**
** Y coefficient 0 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff0" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_4")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum0_YCoeff0( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum0Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum1".
**
** This function writes the given value to the register "SdCcfilterlum1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_5")))
#endif

void FREG_VE_SetSdCcfilterlum1( uint32_t value )
{
    FREG_VE_SdCcfilterlum1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM1)) = value;
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
** \brief Writes the bitgroup "YCoeff1" of register "SdCcfilterlum1".
**
** Y coefficient 1 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_6")))
#endif

void FREG_VE_SetSdCcfilterlum1_YCoeff1( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum1Mirror & ~mask;
    FREG_VE_SdCcfilterlum1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM1)) = value;
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
** \brief Reads the entire register "SdCcfilterlum1".
**
** This function reads the value from the register "SdCcfilterlum1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_7")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum1( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum1Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff1" of register "SdCcfilterlum1".
**
** Y coefficient 1 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_8")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum1_YCoeff1( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum1Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum2".
**
** This function writes the given value to the register "SdCcfilterlum2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_9")))
#endif

void FREG_VE_SetSdCcfilterlum2( uint32_t value )
{
    FREG_VE_SdCcfilterlum2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM2)) = value;
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
** \brief Writes the bitgroup "YCoeff2" of register "SdCcfilterlum2".
**
** Y coefficient 2 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff2" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_10")))
#endif

void FREG_VE_SetSdCcfilterlum2_YCoeff2( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum2Mirror & ~mask;
    FREG_VE_SdCcfilterlum2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM2)) = value;
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
** \brief Reads the entire register "SdCcfilterlum2".
**
** This function reads the value from the register "SdCcfilterlum2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_11")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum2Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff2" of register "SdCcfilterlum2".
**
** Y coefficient 2 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff2" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_12")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum2_YCoeff2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum2Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum3".
**
** This function writes the given value to the register "SdCcfilterlum3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_13")))
#endif

void FREG_VE_SetSdCcfilterlum3( uint32_t value )
{
    FREG_VE_SdCcfilterlum3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM3)) = value;
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
** \brief Writes the bitgroup "YCoeff3" of register "SdCcfilterlum3".
**
** Y coefficient 3 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_14")))
#endif

void FREG_VE_SetSdCcfilterlum3_YCoeff3( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum3Mirror & ~mask;
    FREG_VE_SdCcfilterlum3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM3)) = value;
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
** \brief Reads the entire register "SdCcfilterlum3".
**
** This function reads the value from the register "SdCcfilterlum3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_15")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum3Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff3" of register "SdCcfilterlum3".
**
** Y coefficient 3 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_16")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum3_YCoeff3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum3Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum4".
**
** This function writes the given value to the register "SdCcfilterlum4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_17")))
#endif

void FREG_VE_SetSdCcfilterlum4( uint32_t value )
{
    FREG_VE_SdCcfilterlum4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM4)) = value;
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
** \brief Writes the bitgroup "YCoeff4" of register "SdCcfilterlum4".
**
** Y coefficient 4 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff4" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_18")))
#endif

void FREG_VE_SetSdCcfilterlum4_YCoeff4( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum4Mirror & ~mask;
    FREG_VE_SdCcfilterlum4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM4)) = value;
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
** \brief Reads the entire register "SdCcfilterlum4".
**
** This function reads the value from the register "SdCcfilterlum4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_19")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum4Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff4" of register "SdCcfilterlum4".
**
** Y coefficient 4 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff4" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_20")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum4_YCoeff4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum4Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum5".
**
** This function writes the given value to the register "SdCcfilterlum5".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_21")))
#endif

void FREG_VE_SetSdCcfilterlum5( uint32_t value )
{
    FREG_VE_SdCcfilterlum5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM5)) = value;
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
** \brief Writes the bitgroup "YCoeff5" of register "SdCcfilterlum5".
**
** Y coefficient 5 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_22")))
#endif

void FREG_VE_SetSdCcfilterlum5_YCoeff5( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum5Mirror & ~mask;
    FREG_VE_SdCcfilterlum5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM5)) = value;
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
** \brief Reads the entire register "SdCcfilterlum5".
**
** This function reads the value from the register "SdCcfilterlum5".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_23")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum5Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff5" of register "SdCcfilterlum5".
**
** Y coefficient 5 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_24")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum5_YCoeff5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum5Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum6".
**
** This function writes the given value to the register "SdCcfilterlum6".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_25")))
#endif

void FREG_VE_SetSdCcfilterlum6( uint32_t value )
{
    FREG_VE_SdCcfilterlum6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM6)) = value;
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
** \brief Writes the bitgroup "YCoeff6" of register "SdCcfilterlum6".
**
** Y coefficient 6 (9 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff6" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_26")))
#endif

void FREG_VE_SetSdCcfilterlum6_YCoeff6( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum6Mirror & ~mask;
    FREG_VE_SdCcfilterlum6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM6)) = value;
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
** \brief Reads the entire register "SdCcfilterlum6".
**
** This function reads the value from the register "SdCcfilterlum6".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_27")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum6Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff6" of register "SdCcfilterlum6".
**
** Y coefficient 6 (9 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff6" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_28")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum6_YCoeff6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum6Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum7".
**
** This function writes the given value to the register "SdCcfilterlum7".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_29")))
#endif

void FREG_VE_SetSdCcfilterlum7( uint32_t value )
{
    FREG_VE_SdCcfilterlum7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM7)) = value;
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
** \brief Writes the bitgroup "YCoeff7" of register "SdCcfilterlum7".
**
** Y coefficient 7 (9 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff7" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_30")))
#endif

void FREG_VE_SetSdCcfilterlum7_YCoeff7( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum7Mirror & ~mask;
    FREG_VE_SdCcfilterlum7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM7)) = value;
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
** \brief Reads the entire register "SdCcfilterlum7".
**
** This function reads the value from the register "SdCcfilterlum7".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_31")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum7Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff7" of register "SdCcfilterlum7".
**
** Y coefficient 7 (9 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff7" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_32")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum7_YCoeff7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum7Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum8".
**
** This function writes the given value to the register "SdCcfilterlum8".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_33")))
#endif

void FREG_VE_SetSdCcfilterlum8( uint32_t value )
{
    FREG_VE_SdCcfilterlum8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM8)) = value;
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
** \brief Writes the bitgroup "YCoeff8" of register "SdCcfilterlum8".
**
** Y coefficient 8 (9 bit unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff8" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_34")))
#endif

void FREG_VE_SetSdCcfilterlum8_YCoeff8( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum8Mirror & ~mask;
    FREG_VE_SdCcfilterlum8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM8)) = value;
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
** \brief Reads the entire register "SdCcfilterlum8".
**
** This function reads the value from the register "SdCcfilterlum8".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_35")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum8Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff8" of register "SdCcfilterlum8".
**
** Y coefficient 8 (9 bit unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff8" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_36")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum8_YCoeff8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum8Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterlum9".
**
** This function writes the given value to the register "SdCcfilterlum9".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_37")))
#endif

void FREG_VE_SetSdCcfilterlum9( uint32_t value )
{
    FREG_VE_SdCcfilterlum9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM9)) = value;
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
** \brief Writes the bitgroup "YCoeff9" of register "SdCcfilterlum9".
**
** Y coefficient 9 (9 bit unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_38")))
#endif

void FREG_VE_SetSdCcfilterlum9_YCoeff9( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum9Mirror & ~mask;
    FREG_VE_SdCcfilterlum9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM9)) = value;
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
** \brief Reads the entire register "SdCcfilterlum9".
**
** This function reads the value from the register "SdCcfilterlum9".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_39")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum9Mirror;
    return( value );
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
** \brief Reads the bitgroup "YCoeff9" of register "SdCcfilterlum9".
**
** Y coefficient 9 (9 bit unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_40")))
#endif

uint32_t FREG_VE_GetmSdCcfilterlum9_YCoeff9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum9Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom2".
**
** This function writes the given value to the register "SdCcfilterchrom2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_41")))
#endif

void FREG_VE_SetSdCcfilterchrom2( uint32_t value )
{
    FREG_VE_SdCcfilterchrom2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM2)) = value;
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
** \brief Writes the bitgroup "CCoeff2" of register "SdCcfilterchrom2".
**
** Chrom coefficient 2 (6 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff2" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_42")))
#endif

void FREG_VE_SetSdCcfilterchrom2_CCoeff2( uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom2Mirror & ~mask;
    FREG_VE_SdCcfilterchrom2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM2)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom2".
**
** This function reads the value from the register "SdCcfilterchrom2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_43")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom2Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff2" of register "SdCcfilterchrom2".
**
** Chrom coefficient 2 (6 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff2" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_44")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom2_CCoeff2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom2Mirror;
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom3".
**
** This function writes the given value to the register "SdCcfilterchrom3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_45")))
#endif

void FREG_VE_SetSdCcfilterchrom3( uint32_t value )
{
    FREG_VE_SdCcfilterchrom3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM3)) = value;
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
** \brief Writes the bitgroup "CCoeff3" of register "SdCcfilterchrom3".
**
** Chrom coefficient 3 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_46")))
#endif

void FREG_VE_SetSdCcfilterchrom3_CCoeff3( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom3Mirror & ~mask;
    FREG_VE_SdCcfilterchrom3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM3)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom3".
**
** This function reads the value from the register "SdCcfilterchrom3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_47")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom3Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff3" of register "SdCcfilterchrom3".
**
** Chrom coefficient 3 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_48")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom3_CCoeff3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom3Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom4".
**
** This function writes the given value to the register "SdCcfilterchrom4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_49")))
#endif

void FREG_VE_SetSdCcfilterchrom4( uint32_t value )
{
    FREG_VE_SdCcfilterchrom4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM4)) = value;
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
** \brief Writes the bitgroup "CCoeff4" of register "SdCcfilterchrom4".
**
** Chrom coefficient 4 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff4" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_50")))
#endif

void FREG_VE_SetSdCcfilterchrom4_CCoeff4( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom4Mirror & ~mask;
    FREG_VE_SdCcfilterchrom4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM4)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom4".
**
** This function reads the value from the register "SdCcfilterchrom4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_51")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom4Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff4" of register "SdCcfilterchrom4".
**
** Chrom coefficient 4 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff4" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_52")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom4_CCoeff4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom4Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom5".
**
** This function writes the given value to the register "SdCcfilterchrom5".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_53")))
#endif

void FREG_VE_SetSdCcfilterchrom5( uint32_t value )
{
    FREG_VE_SdCcfilterchrom5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM5)) = value;
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
** \brief Writes the bitgroup "CCoeff5" of register "SdCcfilterchrom5".
**
** Chrom coefficient 5 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_54")))
#endif

void FREG_VE_SetSdCcfilterchrom5_CCoeff5( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom5Mirror & ~mask;
    FREG_VE_SdCcfilterchrom5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM5)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom5".
**
** This function reads the value from the register "SdCcfilterchrom5".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_55")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom5Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff5" of register "SdCcfilterchrom5".
**
** Chrom coefficient 5 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_56")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom5_CCoeff5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom5Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom6".
**
** This function writes the given value to the register "SdCcfilterchrom6".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_57")))
#endif

void FREG_VE_SetSdCcfilterchrom6( uint32_t value )
{
    FREG_VE_SdCcfilterchrom6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM6)) = value;
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
** \brief Writes the bitgroup "CCoeff6" of register "SdCcfilterchrom6".
**
** Chrom coefficient 6 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff6" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_58")))
#endif

void FREG_VE_SetSdCcfilterchrom6_CCoeff6( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom6Mirror & ~mask;
    FREG_VE_SdCcfilterchrom6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM6)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom6".
**
** This function reads the value from the register "SdCcfilterchrom6".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_59")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom6Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff6" of register "SdCcfilterchrom6".
**
** Chrom coefficient 6 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff6" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_60")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom6_CCoeff6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom6Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom7".
**
** This function writes the given value to the register "SdCcfilterchrom7".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_61")))
#endif

void FREG_VE_SetSdCcfilterchrom7( uint32_t value )
{
    FREG_VE_SdCcfilterchrom7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM7)) = value;
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
** \brief Writes the bitgroup "CCoeff7" of register "SdCcfilterchrom7".
**
** Chrom coefficient 7 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff7" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_62")))
#endif

void FREG_VE_SetSdCcfilterchrom7_CCoeff7( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom7Mirror & ~mask;
    FREG_VE_SdCcfilterchrom7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM7)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom7".
**
** This function reads the value from the register "SdCcfilterchrom7".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_63")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom7Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff7" of register "SdCcfilterchrom7".
**
** Chrom coefficient 7 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff7" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_64")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom7_CCoeff7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom7Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom8".
**
** This function writes the given value to the register "SdCcfilterchrom8".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_65")))
#endif

void FREG_VE_SetSdCcfilterchrom8( uint32_t value )
{
    FREG_VE_SdCcfilterchrom8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM8)) = value;
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
** \brief Writes the bitgroup "CCoeff8" of register "SdCcfilterchrom8".
**
** Chrom coefficient 8 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff8" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_66")))
#endif

void FREG_VE_SetSdCcfilterchrom8_CCoeff8( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom8Mirror & ~mask;
    FREG_VE_SdCcfilterchrom8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM8)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom8".
**
** This function reads the value from the register "SdCcfilterchrom8".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_67")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom8Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff8" of register "SdCcfilterchrom8".
**
** Chrom coefficient 8 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff8" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_68")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom8_CCoeff8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom8Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterchrom9".
**
** This function writes the given value to the register "SdCcfilterchrom9".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_69")))
#endif

void FREG_VE_SetSdCcfilterchrom9( uint32_t value )
{
    FREG_VE_SdCcfilterchrom9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM9)) = value;
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
** \brief Writes the bitgroup "CCoeff9" of register "SdCcfilterchrom9".
**
** Chrom coefficient 9 (9 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_70")))
#endif

void FREG_VE_SetSdCcfilterchrom9_CCoeff9( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom9Mirror & ~mask;
    FREG_VE_SdCcfilterchrom9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM9)) = value;
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
** \brief Reads the entire register "SdCcfilterchrom9".
**
** This function reads the value from the register "SdCcfilterchrom9".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_71")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom9Mirror;
    return( value );
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
** \brief Reads the bitgroup "CCoeff9" of register "SdCcfilterchrom9".
**
** Chrom coefficient 9 (9 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_72")))
#endif

uint32_t FREG_VE_GetmSdCcfilterchrom9_CCoeff9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom9Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterhorstart".
**
** This function writes the given value to the register "SdCcfilterhorstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_73")))
#endif

void FREG_VE_SetSdCcfilterhorstart( uint32_t value )
{
    FREG_VE_SdCcfilterhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTART)) = value;
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
** \brief Writes the bitgroup "SdCcfilterhorstart" of register "SdCcfilterhorstart".
**
** horizontal start position when CC filter gets active
** recommended value: 0x200
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterhorstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_74")))
#endif

void FREG_VE_SetSdCcfilterhorstart_SdCcfilterhorstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterhorstartMirror & ~mask;
    FREG_VE_SdCcfilterhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTART)) = value;
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
** \brief Reads the entire register "SdCcfilterhorstart".
**
** This function reads the value from the register "SdCcfilterhorstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_75")))
#endif

uint32_t FREG_VE_GetmSdCcfilterhorstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstartMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterhorstart" of register "SdCcfilterhorstart".
**
** horizontal start position when CC filter gets active
** recommended value: 0x200
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterhorstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_76")))
#endif

uint32_t FREG_VE_GetmSdCcfilterhorstart_SdCcfilterhorstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterhorstop".
**
** This function writes the given value to the register "SdCcfilterhorstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_77"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_77" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_77")))
#endif

void FREG_VE_SetSdCcfilterhorstop( uint32_t value )
{
    FREG_VE_SdCcfilterhorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTOP)) = value;
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
** \brief Writes the bitgroup "SdCcfilterhorstop" of register "SdCcfilterhorstop".
**
** horizontal stop position when CC filter gets de-activated
** recommended value: 0xD60
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterhorstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_78"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_78" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_78")))
#endif

void FREG_VE_SetSdCcfilterhorstop_SdCcfilterhorstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterhorstopMirror & ~mask;
    FREG_VE_SdCcfilterhorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTOP)) = value;
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
** \brief Reads the entire register "SdCcfilterhorstop".
**
** This function reads the value from the register "SdCcfilterhorstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_79"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_79" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_79")))
#endif

uint32_t FREG_VE_GetmSdCcfilterhorstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstopMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterhorstop" of register "SdCcfilterhorstop".
**
** horizontal stop position when CC filter gets de-activated
** recommended value: 0xD60
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterhorstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_80"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_80" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_80")))
#endif

uint32_t FREG_VE_GetmSdCcfilterhorstop_SdCcfilterhorstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterverstart".
**
** This function writes the given value to the register "SdCcfilterverstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_81"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_81" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_81")))
#endif

void FREG_VE_SetSdCcfilterverstart( uint32_t value )
{
    FREG_VE_SdCcfilterverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTART)) = value;
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
** \brief Writes the bitgroup "SdCcfilterverstart" of register "SdCcfilterverstart".
**
** vertical start position when CC filter gets activated
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterverstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_82"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_82" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_82")))
#endif

void FREG_VE_SetSdCcfilterverstart_SdCcfilterverstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterverstartMirror & ~mask;
    FREG_VE_SdCcfilterverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTART)) = value;
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
** \brief Reads the entire register "SdCcfilterverstart".
**
** This function reads the value from the register "SdCcfilterverstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_83"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_83" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_83")))
#endif

uint32_t FREG_VE_GetmSdCcfilterverstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstartMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterverstart" of register "SdCcfilterverstart".
**
** vertical start position when CC filter gets activated
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterverstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_84"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_84" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_84")))
#endif

uint32_t FREG_VE_GetmSdCcfilterverstart_SdCcfilterverstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterverstop".
**
** This function writes the given value to the register "SdCcfilterverstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_85"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_85" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_85")))
#endif

void FREG_VE_SetSdCcfilterverstop( uint32_t value )
{
    FREG_VE_SdCcfilterverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTOP)) = value;
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
** \brief Writes the bitgroup "SdCcfilterverstop" of register "SdCcfilterverstop".
**
** vertical stop position when CC filter gets de-activated
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterverstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_86"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_86" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_86")))
#endif

void FREG_VE_SetSdCcfilterverstop_SdCcfilterverstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterverstopMirror & ~mask;
    FREG_VE_SdCcfilterverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTOP)) = value;
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
** \brief Reads the entire register "SdCcfilterverstop".
**
** This function reads the value from the register "SdCcfilterverstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_87"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_87" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_87")))
#endif

uint32_t FREG_VE_GetmSdCcfilterverstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstopMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterverstop" of register "SdCcfilterverstop".
**
** vertical stop position when CC filter gets de-activated
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterverstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_88"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_88" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_88")))
#endif

uint32_t FREG_VE_GetmSdCcfilterverstop_SdCcfilterverstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterblankstart".
**
** This function writes the given value to the register "SdCcfilterblankstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_89"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_89" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_89")))
#endif

void FREG_VE_SetSdCcfilterblankstart( uint32_t value )
{
    FREG_VE_SdCcfilterblankstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTART)) = value;
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
** \brief Writes the bitgroup "SdCcfilterblankstart" of register "SdCcfilterblankstart".
**
** horizontal blank start of the CC filter
** recommended value: 0x200
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterblankstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_90"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_90" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_90")))
#endif

void FREG_VE_SetSdCcfilterblankstart_SdCcfilterblankstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterblankstartMirror & ~mask;
    FREG_VE_SdCcfilterblankstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTART)) = value;
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
** \brief Reads the entire register "SdCcfilterblankstart".
**
** This function reads the value from the register "SdCcfilterblankstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_91"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_91" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_91")))
#endif

uint32_t FREG_VE_GetmSdCcfilterblankstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstartMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterblankstart" of register "SdCcfilterblankstart".
**
** horizontal blank start of the CC filter
** recommended value: 0x200
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterblankstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_92"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_92" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_92")))
#endif

uint32_t FREG_VE_GetmSdCcfilterblankstart_SdCcfilterblankstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterblankstop".
**
** This function writes the given value to the register "SdCcfilterblankstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_93"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_93" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_93")))
#endif

void FREG_VE_SetSdCcfilterblankstop( uint32_t value )
{
    FREG_VE_SdCcfilterblankstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTOP)) = value;
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
** \brief Writes the bitgroup "SdCcfilterblankstop" of register "SdCcfilterblankstop".
**
** horizontal blank stop of the CC filter
** recommended value: 0xD20
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterblankstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_94"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_94" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_94")))
#endif

void FREG_VE_SetSdCcfilterblankstop_SdCcfilterblankstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterblankstopMirror & ~mask;
    FREG_VE_SdCcfilterblankstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTOP)) = value;
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
** \brief Reads the entire register "SdCcfilterblankstop".
**
** This function reads the value from the register "SdCcfilterblankstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_95"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_95" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_95")))
#endif

uint32_t FREG_VE_GetmSdCcfilterblankstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstopMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterblankstop" of register "SdCcfilterblankstop".
**
** horizontal blank stop of the CC filter
** recommended value: 0xD20
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterblankstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_96"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_96" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_96")))
#endif

uint32_t FREG_VE_GetmSdCcfilterblankstop_SdCcfilterblankstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdCcfilterenable".
**
** This function writes the given value to the register "SdCcfilterenable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_97"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_97" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_97")))
#endif

void FREG_VE_SetSdCcfilterenable( uint32_t value )
{
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
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
** \brief Writes the bitgroup "SdCchalfcoeffmode" of register "SdCcfilterenable".
**
** Switches the CC filter into half coefficient mode.
**  This allows more flexibility in selecting the coefficients. The disadvantage is the loss of resolution. The sum of all coefficients (per phase) is in this case 256 instead of the usual 512.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCchalfcoeffmode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_98"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_98" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_98")))
#endif

void FREG_VE_SetSdCcfilterenable_SdCchalfcoeffmode( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_VE_SdCcfilterenableMirror & ~mask;
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
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
** \brief Writes the bitgroup "SdCcdelaycomp" of register "SdCcfilterenable".
**
** enables one cycle of delay (13.
** 5MHz) on the non-cross color fixed path. Can be used to compensate for differences between non-cc fixed signals and cc-fixed signals
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcdelaycomp" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_99"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_99" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_99")))
#endif

void FREG_VE_SetSdCcfilterenable_SdCcdelaycomp( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_SdCcfilterenableMirror & ~mask;
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
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
** \brief Writes the bitgroup "SdCcfilterenable" of register "SdCcfilterenable".
**
** enables the CC filter
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_100"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_100" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_100")))
#endif

void FREG_VE_SetSdCcfilterenable_SdCcfilterenable( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterenableMirror & ~mask;
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
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
** \brief Reads the entire register "SdCcfilterenable".
**
** This function reads the value from the register "SdCcfilterenable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_101"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_101" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_101")))
#endif

uint32_t FREG_VE_GetmSdCcfilterenable( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    return( value );
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
** \brief Reads the bitgroup "SdCchalfcoeffmode" of register "SdCcfilterenable".
**
** Switches the CC filter into half coefficient mode.
**  This allows more flexibility in selecting the coefficients. The disadvantage is the loss of resolution. The sum of all coefficients (per phase) is in this case 256 instead of the usual 512.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCchalfcoeffmode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_102"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_102" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_102")))
#endif

uint32_t FREG_VE_GetmSdCcfilterenable_SdCchalfcoeffmode( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
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
** \brief Reads the bitgroup "SdCcdelaycomp" of register "SdCcfilterenable".
**
** enables one cycle of delay (13.
** 5MHz) on the non-cross color fixed path. Can be used to compensate for differences between non-cc fixed signals and cc-fixed signals
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcdelaycomp" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_103"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_103" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_103")))
#endif

uint32_t FREG_VE_GetmSdCcfilterenable_SdCcdelaycomp( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
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
** \brief Reads the bitgroup "SdCcfilterenable" of register "SdCcfilterenable".
**
** enables the CC filter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_104"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_104" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_104")))
#endif

uint32_t FREG_VE_GetmSdCcfilterenable_SdCcfilterenable( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdHorlinelength".
**
** This function writes the given value to the register "SdHorlinelength".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_105"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_105" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_105")))
#endif

void FREG_VE_SetSdHorlinelength( uint32_t value )
{
    FREG_VE_SdHorlinelengthMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHORLINELENGTH, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHORLINELENGTH)) = value;
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
** \brief Writes the bitgroup "HorLl" of register "SdHorlinelength".
**
** horizontal line length in 54.
** 0MHz cycles.
** PAL B/G: 3456 = 0xD80
** NTSC M: 3432 = 0xD68
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "HorLl" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_106"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_106" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_106")))
#endif

void FREG_VE_SetSdHorlinelength_HorLl( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdHorlinelengthMirror & ~mask;
    FREG_VE_SdHorlinelengthMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHORLINELENGTH, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHORLINELENGTH)) = value;
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
** \brief Reads the entire register "SdHorlinelength".
**
** This function reads the value from the register "SdHorlinelength".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_107"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_107" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_107")))
#endif

uint32_t FREG_VE_GetmSdHorlinelength( void )
{
    register uint32_t value = FREG_VE_SdHorlinelengthMirror;
    return( value );
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
** \brief Reads the bitgroup "HorLl" of register "SdHorlinelength".
**
** horizontal line length in 54.
** 0MHz cycles.
** PAL B/G: 3456 = 0xD80
** NTSC M: 3432 = 0xD68
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "HorLl" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_108"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_108" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_108")))
#endif

uint32_t FREG_VE_GetmSdHorlinelength_HorLl( void )
{
    register uint32_t value = FREG_VE_SdHorlinelengthMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdVersize".
**
** This function writes the given value to the register "SdVersize".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_109"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_109" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_109")))
#endif

void FREG_VE_SetSdVersize( uint32_t value )
{
    FREG_VE_SdVersizeMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVERSIZE)) = value;
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
** \brief Writes the bitgroup "VerSize" of register "SdVersize".
**
** Output window: stop value of the line counter (lines per field).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VerSize" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_110"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_110" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_110")))
#endif

void FREG_VE_SetSdVersize_VerSize( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVersizeMirror & ~mask;
    FREG_VE_SdVersizeMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVERSIZE)) = value;
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
** \brief Reads the entire register "SdVersize".
**
** This function reads the value from the register "SdVersize".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_111"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_111" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_111")))
#endif

uint32_t FREG_VE_GetmSdVersize( void )
{
    register uint32_t value = FREG_VE_SdVersizeMirror;
    return( value );
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
** \brief Reads the bitgroup "VerSize" of register "SdVersize".
**
** Output window: stop value of the line counter (lines per field).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VerSize" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_112"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_112" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_112")))
#endif

uint32_t FREG_VE_GetmSdVersize_VerSize( void )
{
    register uint32_t value = FREG_VE_SdVersizeMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdBackground".
**
** This function writes the given value to the register "SdBackground".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_113"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_113" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_113")))
#endif

void FREG_VE_SetSdBackground( uint32_t value )
{
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
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
** \brief Writes the bitgroup "BackGroundY" of register "SdBackground".
**
** Luminance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x10 = 16 (black)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_114"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_114" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_114")))
#endif

void FREG_VE_SetSdBackground_BackGroundY( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VE_SdBackgroundMirror & ~mask;
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
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
** \brief Writes the bitgroup "BackGroundCb" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundCb" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_115"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_115" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_115")))
#endif

void FREG_VE_SetSdBackground_BackGroundCb( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_SdBackgroundMirror & ~mask;
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
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
** \brief Writes the bitgroup "BackGroundCr" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundCr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_116"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_116" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_116")))
#endif

void FREG_VE_SetSdBackground_BackGroundCr( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdBackgroundMirror & ~mask;
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
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
** \brief Reads the entire register "SdBackground".
**
** This function reads the value from the register "SdBackground".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_117"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_117" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_117")))
#endif

uint32_t FREG_VE_GetmSdBackground( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    return( value );
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
** \brief Reads the bitgroup "BackGroundY" of register "SdBackground".
**
** Luminance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x10 = 16 (black)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_118"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_118" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_118")))
#endif

uint32_t FREG_VE_GetmSdBackground_BackGroundY( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
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
** \brief Reads the bitgroup "BackGroundCb" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundCb" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_119"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_119" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_119")))
#endif

uint32_t FREG_VE_GetmSdBackground_BackGroundCb( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "BackGroundCr" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundCr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_120"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_120" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_120")))
#endif

uint32_t FREG_VE_GetmSdBackground_BackGroundCr( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdVohorstart".
**
** This function writes the given value to the register "SdVohorstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_121"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_121" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_121")))
#endif

void FREG_VE_SetSdVohorstart( uint32_t value )
{
    FREG_VE_SdVohorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTART)) = value;
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
** \brief Writes the bitgroup "VoHorStart" of register "SdVohorstart".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508
** Typical value for NTSC: 508
** (change only in steps of 4)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoHorStart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_122"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_122" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_122")))
#endif

void FREG_VE_SetSdVohorstart_VoHorStart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVohorstartMirror & ~mask;
    FREG_VE_SdVohorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTART)) = value;
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
** \brief Reads the entire register "SdVohorstart".
**
** This function reads the value from the register "SdVohorstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_123"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_123" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_123")))
#endif

uint32_t FREG_VE_GetmSdVohorstart( void )
{
    register uint32_t value = FREG_VE_SdVohorstartMirror;
    return( value );
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
** \brief Reads the bitgroup "VoHorStart" of register "SdVohorstart".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508
** Typical value for NTSC: 508
** (change only in steps of 4)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoHorStart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_124"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_124" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_124")))
#endif

uint32_t FREG_VE_GetmSdVohorstart_VoHorStart( void )
{
    register uint32_t value = FREG_VE_SdVohorstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdVohorstop".
**
** This function writes the given value to the register "SdVohorstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_125"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_125" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_125")))
#endif

void FREG_VE_SetSdVohorstop( uint32_t value )
{
    FREG_VE_SdVohorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTOP)) = value;
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
** \brief Writes the bitgroup "VoHorStop" of register "SdVohorstop".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508 +(4*720)
** Typical value for NTSC: 508 + (4*720)
** (change only in steps of 4)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoHorStop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_126"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_126" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_126")))
#endif

void FREG_VE_SetSdVohorstop_VoHorStop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVohorstopMirror & ~mask;
    FREG_VE_SdVohorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTOP)) = value;
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
** \brief Reads the entire register "SdVohorstop".
**
** This function reads the value from the register "SdVohorstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_127"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_127" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_127")))
#endif

uint32_t FREG_VE_GetmSdVohorstop( void )
{
    register uint32_t value = FREG_VE_SdVohorstopMirror;
    return( value );
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
** \brief Reads the bitgroup "VoHorStop" of register "SdVohorstop".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508 +(4*720)
** Typical value for NTSC: 508 + (4*720)
** (change only in steps of 4)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoHorStop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_128"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_128" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_128")))
#endif

uint32_t FREG_VE_GetmSdVohorstop_VoHorStop( void )
{
    register uint32_t value = FREG_VE_SdVohorstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdVoverstart".
**
** This function writes the given value to the register "SdVoverstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_129"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_129" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_129")))
#endif

void FREG_VE_SetSdVoverstart( uint32_t value )
{
    FREG_VE_SdVoverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTART)) = value;
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
** \brief Writes the bitgroup "VoVerStart" of register "SdVoverstart".
**
** Insertion window for video.
** 
** Typical value for PAL 23
** Typical value for NTSC: 21
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoVerStart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_130"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_130" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_130")))
#endif

void FREG_VE_SetSdVoverstart_VoVerStart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVoverstartMirror & ~mask;
    FREG_VE_SdVoverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTART)) = value;
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
** \brief Reads the entire register "SdVoverstart".
**
** This function reads the value from the register "SdVoverstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_131"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_131" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_131")))
#endif

uint32_t FREG_VE_GetmSdVoverstart( void )
{
    register uint32_t value = FREG_VE_SdVoverstartMirror;
    return( value );
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
** \brief Reads the bitgroup "VoVerStart" of register "SdVoverstart".
**
** Insertion window for video.
** 
** Typical value for PAL 23
** Typical value for NTSC: 21
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoVerStart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_132"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_132" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_132")))
#endif

uint32_t FREG_VE_GetmSdVoverstart_VoVerStart( void )
{
    register uint32_t value = FREG_VE_SdVoverstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdVoverstop".
**
** This function writes the given value to the register "SdVoverstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_133"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_133" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_133")))
#endif

void FREG_VE_SetSdVoverstop( uint32_t value )
{
    FREG_VE_SdVoverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTOP)) = value;
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
** \brief Writes the bitgroup "VoVerStop" of register "SdVoverstop".
**
** Insertion window for video.
** 
** Typical value for PAL 23 + 288
** Typical value for NTSC: 21 +240
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoVerStop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_134"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_134" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_134")))
#endif

void FREG_VE_SetSdVoverstop_VoVerStop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVoverstopMirror & ~mask;
    FREG_VE_SdVoverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTOP)) = value;
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
** \brief Reads the entire register "SdVoverstop".
**
** This function reads the value from the register "SdVoverstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_135"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_135" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_135")))
#endif

uint32_t FREG_VE_GetmSdVoverstop( void )
{
    register uint32_t value = FREG_VE_SdVoverstopMirror;
    return( value );
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
** \brief Reads the bitgroup "VoVerStop" of register "SdVoverstop".
**
** Insertion window for video.
** 
** Typical value for PAL 23 + 288
** Typical value for NTSC: 21 +240
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoVerStop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_136"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_136" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_136")))
#endif

uint32_t FREG_VE_GetmSdVoverstop_VoVerStop( void )
{
    register uint32_t value = FREG_VE_SdVoverstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdTtxhorstart".
**
** This function writes the given value to the register "SdTtxhorstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_137"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_137" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_137")))
#endif

void FREG_VE_SetSdTtxhorstart( uint32_t value )
{
    FREG_VE_SdTtxhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDTTXHORSTART)) = value;
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
** \brief Writes the bitgroup "TtxEnable" of register "SdTtxhorstart".
**
** enables TTX insertion
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxEnable" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_138"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_138" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_138")))
#endif

void FREG_VE_SetSdTtxhorstart_TtxEnable( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VE_SdTtxhorstartMirror & ~mask;
    FREG_VE_SdTtxhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDTTXHORSTART)) = value;
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
** \brief Writes the bitgroup "TtxHorStart" of register "SdTtxhorstart".
**
** The pixel counter counts 54.
** 0MHz clock cycles. If the pixel counter reaches this value (times 4), the Teletext data will be inserted in the video.
** Typical value for PAL: = 528 (0x210)
** Typical value for Secam: = 540 (0x21C)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxHorStart" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_139"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_139" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_139")))
#endif

void FREG_VE_SetSdTtxhorstart_TtxHorStart( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdTtxhorstartMirror & ~mask;
    FREG_VE_SdTtxhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDTTXHORSTART)) = value;
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
** \brief Reads the entire register "SdTtxhorstart".
**
** This function reads the value from the register "SdTtxhorstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_140"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_140" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_140")))
#endif

uint32_t FREG_VE_GetmSdTtxhorstart( void )
{
    register uint32_t value = FREG_VE_SdTtxhorstartMirror;
    return( value );
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
** \brief Reads the bitgroup "TtxEnable" of register "SdTtxhorstart".
**
** enables TTX insertion
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxEnable" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_141"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_141" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_141")))
#endif

uint32_t FREG_VE_GetmSdTtxhorstart_TtxEnable( void )
{
    register uint32_t value = FREG_VE_SdTtxhorstartMirror;
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
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
** \brief Reads the bitgroup "TtxHorStart" of register "SdTtxhorstart".
**
** The pixel counter counts 54.
** 0MHz clock cycles. If the pixel counter reaches this value (times 4), the Teletext data will be inserted in the video.
** Typical value for PAL: = 528 (0x210)
** Typical value for Secam: = 540 (0x21C)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxHorStart" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_142"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_142" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_142")))
#endif

uint32_t FREG_VE_GetmSdTtxhorstart_TtxHorStart( void )
{
    register uint32_t value = FREG_VE_SdTtxhorstartMirror;
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdhvsynccfg".
**
** This function writes the given value to the register "Sdhvsynccfg".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_143"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_143" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_143")))
#endif

void FREG_VE_SetSdhvsynccfg( uint32_t value )
{
    FREG_VE_SdhvsynccfgMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHVSYNCCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHVSYNCCFG)) = value;
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
** \brief Writes the bitgroup "SdSyncEnable" of register "Sdhvsynccfg".
**
** enables the SD block to become synchronized
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdSyncEnable" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_144"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_144" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_144")))
#endif

void FREG_VE_SetSdhvsynccfg_SdSyncEnable( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VE_SdhvsynccfgMirror & ~mask;
    FREG_VE_SdhvsynccfgMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHVSYNCCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHVSYNCCFG)) = value;
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
** \brief Reads the entire register "Sdhvsynccfg".
**
** This function reads the value from the register "Sdhvsynccfg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_145"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_145" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_145")))
#endif

uint32_t FREG_VE_GetmSdhvsynccfg( void )
{
    register uint32_t value = FREG_VE_SdhvsynccfgMirror;
    return( value );
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
** \brief Reads the bitgroup "SdSyncEnable" of register "Sdhvsynccfg".
**
** enables the SD block to become synchronized
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdSyncEnable" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_146"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_146" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_146")))
#endif

uint32_t FREG_VE_GetmSdhvsynccfg_SdSyncEnable( void )
{
    register uint32_t value = FREG_VE_SdhvsynccfgMirror;
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
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
** \brief Writes the entire register "Sdvsyncoffset".
**
** This function writes the given value to the register "Sdvsyncoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_147"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_147" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_147")))
#endif

void FREG_VE_SetSdvsyncoffset( uint32_t value )
{
    FREG_VE_SdvsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOFFSET)) = value;
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
** \brief Writes the bitgroup "Field" of register "Sdvsyncoffset".
**
** field load value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Field" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_148"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_148" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_148")))
#endif

void FREG_VE_SetSdvsyncoffset_Field( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncoffsetMirror & ~mask;
    FREG_VE_SdvsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOFFSET)) = value;
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
** \brief Writes the bitgroup "Sdvsyncoffset" of register "Sdvsyncoffset".
**
** vertical counter load value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdvsyncoffset" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_149"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_149" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_149")))
#endif

void FREG_VE_SetSdvsyncoffset_Sdvsyncoffset( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncoffsetMirror & ~mask;
    FREG_VE_SdvsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOFFSET)) = value;
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
** \brief Reads the entire register "Sdvsyncoffset".
**
** This function reads the value from the register "Sdvsyncoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_150"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_150" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_150")))
#endif

uint32_t FREG_VE_GetmSdvsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdvsyncoffsetMirror;
    return( value );
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
** \brief Reads the bitgroup "Field" of register "Sdvsyncoffset".
**
** field load value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Field" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_151"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_151" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_151")))
#endif

uint32_t FREG_VE_GetmSdvsyncoffset_Field( void )
{
    register uint32_t value = FREG_VE_SdvsyncoffsetMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Sdvsyncoffset" of register "Sdvsyncoffset".
**
** vertical counter load value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdvsyncoffset" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_152"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_152" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_152")))
#endif

uint32_t FREG_VE_GetmSdvsyncoffset_Sdvsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdvsyncoffsetMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncevstart".
**
** This function writes the given value to the register "Sdvsyncevstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_153"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_153" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_153")))
#endif

void FREG_VE_SetSdvsyncevstart( uint32_t value )
{
    FREG_VE_SdvsyncevstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTART)) = value;
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
** \brief Writes the bitgroup "Vsyncevstartfield" of register "Sdvsyncevstart".
**
** Defines the field where first vsync starts 0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_154"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_154" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_154")))
#endif

void FREG_VE_SetSdvsyncevstart_Vsyncevstartfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncevstartMirror & ~mask;
    FREG_VE_SdvsyncevstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTART)) = value;
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
** \brief Writes the bitgroup "Vsyncevstart" of register "Sdvsyncevstart".
**
** Defines the line where first vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_155"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_155" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_155")))
#endif

void FREG_VE_SetSdvsyncevstart_Vsyncevstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncevstartMirror & ~mask;
    FREG_VE_SdvsyncevstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTART)) = value;
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
** \brief Reads the entire register "Sdvsyncevstart".
**
** This function reads the value from the register "Sdvsyncevstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_156"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_156" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_156")))
#endif

uint32_t FREG_VE_GetmSdvsyncevstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstartMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncevstartfield" of register "Sdvsyncevstart".
**
** Defines the field where first vsync starts 0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_157"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_157" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_157")))
#endif

uint32_t FREG_VE_GetmSdvsyncevstart_Vsyncevstartfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstartMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Vsyncevstart" of register "Sdvsyncevstart".
**
** Defines the line where first vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_158"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_158" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_158")))
#endif

uint32_t FREG_VE_GetmSdvsyncevstart_Vsyncevstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncovstart".
**
** This function writes the given value to the register "Sdvsyncovstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_159"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_159" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_159")))
#endif

void FREG_VE_SetSdvsyncovstart( uint32_t value )
{
    FREG_VE_SdvsyncovstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTART)) = value;
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
** \brief Writes the bitgroup "Vsyncovstartfield" of register "Sdvsyncovstart".
**
** Defines the field where second vsync starts  0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_160"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_160" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_160")))
#endif

void FREG_VE_SetSdvsyncovstart_Vsyncovstartfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncovstartMirror & ~mask;
    FREG_VE_SdvsyncovstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTART)) = value;
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
** \brief Writes the bitgroup "Vsyncovstart" of register "Sdvsyncovstart".
**
** Defines the line where second vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_161"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_161" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_161")))
#endif

void FREG_VE_SetSdvsyncovstart_Vsyncovstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncovstartMirror & ~mask;
    FREG_VE_SdvsyncovstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTART)) = value;
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
** \brief Reads the entire register "Sdvsyncovstart".
**
** This function reads the value from the register "Sdvsyncovstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_162"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_162" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_162")))
#endif

uint32_t FREG_VE_GetmSdvsyncovstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstartMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncovstartfield" of register "Sdvsyncovstart".
**
** Defines the field where second vsync starts  0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_163"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_163" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_163")))
#endif

uint32_t FREG_VE_GetmSdvsyncovstart_Vsyncovstartfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstartMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Vsyncovstart" of register "Sdvsyncovstart".
**
** Defines the line where second vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_164"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_164" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_164")))
#endif

uint32_t FREG_VE_GetmSdvsyncovstart_Vsyncovstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncevstop".
**
** This function writes the given value to the register "Sdvsyncevstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_165"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_165" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_165")))
#endif

void FREG_VE_SetSdvsyncevstop( uint32_t value )
{
    FREG_VE_SdvsyncevstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTOP)) = value;
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
** \brief Writes the bitgroup "Vsyncevstopfield" of register "Sdvsyncevstop".
**
** Defines the field where first vsync stops 0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_166"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_166" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_166")))
#endif

void FREG_VE_SetSdvsyncevstop_Vsyncevstopfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncevstopMirror & ~mask;
    FREG_VE_SdvsyncevstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTOP)) = value;
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
** \brief Writes the bitgroup "Vsyncevstop" of register "Sdvsyncevstop".
**
** Defines the line where first vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_167"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_167" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_167")))
#endif

void FREG_VE_SetSdvsyncevstop_Vsyncevstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncevstopMirror & ~mask;
    FREG_VE_SdvsyncevstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTOP)) = value;
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
** \brief Reads the entire register "Sdvsyncevstop".
**
** This function reads the value from the register "Sdvsyncevstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_168"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_168" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_168")))
#endif

uint32_t FREG_VE_GetmSdvsyncevstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstopMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncevstopfield" of register "Sdvsyncevstop".
**
** Defines the field where first vsync stops 0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_169"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_169" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_169")))
#endif

uint32_t FREG_VE_GetmSdvsyncevstop_Vsyncevstopfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstopMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Vsyncevstop" of register "Sdvsyncevstop".
**
** Defines the line where first vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_170"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_170" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_170")))
#endif

uint32_t FREG_VE_GetmSdvsyncevstop_Vsyncevstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncovstop".
**
** This function writes the given value to the register "Sdvsyncovstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_171"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_171" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_171")))
#endif

void FREG_VE_SetSdvsyncovstop( uint32_t value )
{
    FREG_VE_SdvsyncovstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTOP)) = value;
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
** \brief Writes the bitgroup "Vsyncovstopfield" of register "Sdvsyncovstop".
**
** Defines the field where vsync stops (second stop) 0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_172"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_172" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_172")))
#endif

void FREG_VE_SetSdvsyncovstop_Vsyncovstopfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncovstopMirror & ~mask;
    FREG_VE_SdvsyncovstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTOP)) = value;
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
** \brief Writes the bitgroup "Vsyncovstop" of register "Sdvsyncovstop".
**
** Defines the line where second vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_173"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_173" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_173")))
#endif

void FREG_VE_SetSdvsyncovstop_Vsyncovstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncovstopMirror & ~mask;
    FREG_VE_SdvsyncovstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTOP)) = value;
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
** \brief Reads the entire register "Sdvsyncovstop".
**
** This function reads the value from the register "Sdvsyncovstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_174"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_174" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_174")))
#endif

uint32_t FREG_VE_GetmSdvsyncovstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstopMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncovstopfield" of register "Sdvsyncovstop".
**
** Defines the field where vsync stops (second stop) 0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_175"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_175" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_175")))
#endif

uint32_t FREG_VE_GetmSdvsyncovstop_Vsyncovstopfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstopMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Vsyncovstop" of register "Sdvsyncovstop".
**
** Defines the line where second vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_176"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_176" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_176")))
#endif

uint32_t FREG_VE_GetmSdvsyncovstop_Vsyncovstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncehstart".
**
** This function writes the given value to the register "Sdvsyncehstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_177"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_177" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_177")))
#endif

void FREG_VE_SetSdvsyncehstart( uint32_t value )
{
    FREG_VE_SdvsyncehstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTART)) = value;
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
** \brief Writes the bitgroup "Vsyncehstart" of register "Sdvsyncehstart".
**
** Defines the H-pos where first vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncehstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_178"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_178" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_178")))
#endif

void FREG_VE_SetSdvsyncehstart_Vsyncehstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncehstartMirror & ~mask;
    FREG_VE_SdvsyncehstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTART)) = value;
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
** \brief Reads the entire register "Sdvsyncehstart".
**
** This function reads the value from the register "Sdvsyncehstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_179"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_179" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_179")))
#endif

uint32_t FREG_VE_GetmSdvsyncehstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstartMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncehstart" of register "Sdvsyncehstart".
**
** Defines the H-pos where first vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncehstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_180"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_180" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_180")))
#endif

uint32_t FREG_VE_GetmSdvsyncehstart_Vsyncehstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncohstart".
**
** This function writes the given value to the register "Sdvsyncohstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_181"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_181" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_181")))
#endif

void FREG_VE_SetSdvsyncohstart( uint32_t value )
{
    FREG_VE_SdvsyncohstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTART)) = value;
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
** \brief Writes the bitgroup "Vsyncohstart" of register "Sdvsyncohstart".
**
** Defines the H-pos where second vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncohstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_182"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_182" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_182")))
#endif

void FREG_VE_SetSdvsyncohstart_Vsyncohstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncohstartMirror & ~mask;
    FREG_VE_SdvsyncohstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTART)) = value;
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
** \brief Reads the entire register "Sdvsyncohstart".
**
** This function reads the value from the register "Sdvsyncohstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_183"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_183" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_183")))
#endif

uint32_t FREG_VE_GetmSdvsyncohstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstartMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncohstart" of register "Sdvsyncohstart".
**
** Defines the H-pos where second vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncohstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_184"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_184" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_184")))
#endif

uint32_t FREG_VE_GetmSdvsyncohstart_Vsyncohstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncehstop".
**
** This function writes the given value to the register "Sdvsyncehstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_185"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_185" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_185")))
#endif

void FREG_VE_SetSdvsyncehstop( uint32_t value )
{
    FREG_VE_SdvsyncehstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTOP)) = value;
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
** \brief Writes the bitgroup "Vsyncehstop" of register "Sdvsyncehstop".
**
** Defines the H-pos where first vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncehstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_186"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_186" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_186")))
#endif

void FREG_VE_SetSdvsyncehstop_Vsyncehstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncehstopMirror & ~mask;
    FREG_VE_SdvsyncehstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTOP)) = value;
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
** \brief Reads the entire register "Sdvsyncehstop".
**
** This function reads the value from the register "Sdvsyncehstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_187"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_187" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_187")))
#endif

uint32_t FREG_VE_GetmSdvsyncehstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstopMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncehstop" of register "Sdvsyncehstop".
**
** Defines the H-pos where first vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncehstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_188"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_188" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_188")))
#endif

uint32_t FREG_VE_GetmSdvsyncehstop_Vsyncehstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdvsyncohstop".
**
** This function writes the given value to the register "Sdvsyncohstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_189"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_189" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_189")))
#endif

void FREG_VE_SetSdvsyncohstop( uint32_t value )
{
    FREG_VE_SdvsyncohstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTOP)) = value;
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
** \brief Writes the bitgroup "Vsyncohstop" of register "Sdvsyncohstop".
**
** Defines the H-pos where second vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncohstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_190"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_190" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_190")))
#endif

void FREG_VE_SetSdvsyncohstop_Vsyncohstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncohstopMirror & ~mask;
    FREG_VE_SdvsyncohstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTOP)) = value;
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
** \brief Reads the entire register "Sdvsyncohstop".
**
** This function reads the value from the register "Sdvsyncohstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_191"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_191" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_191")))
#endif

uint32_t FREG_VE_GetmSdvsyncohstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstopMirror;
    return( value );
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
** \brief Reads the bitgroup "Vsyncohstop" of register "Sdvsyncohstop".
**
** Defines the H-pos where second vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncohstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_192"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_192" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_192")))
#endif

uint32_t FREG_VE_GetmSdvsyncohstop_Vsyncohstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdhsyncstart".
**
** This function writes the given value to the register "Sdhsyncstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_193"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_193" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_193")))
#endif

void FREG_VE_SetSdhsyncstart( uint32_t value )
{
    FREG_VE_SdhsyncstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTART)) = value;
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
** \brief Writes the bitgroup "Hsyncstart" of register "Sdhsyncstart".
**
** Defines the H-pos where hsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsyncstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_194"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_194" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_194")))
#endif

void FREG_VE_SetSdhsyncstart_Hsyncstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdhsyncstartMirror & ~mask;
    FREG_VE_SdhsyncstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTART)) = value;
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
** \brief Reads the entire register "Sdhsyncstart".
**
** This function reads the value from the register "Sdhsyncstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_195"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_195" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_195")))
#endif

uint32_t FREG_VE_GetmSdhsyncstart( void )
{
    register uint32_t value = FREG_VE_SdhsyncstartMirror;
    return( value );
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
** \brief Reads the bitgroup "Hsyncstart" of register "Sdhsyncstart".
**
** Defines the H-pos where hsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsyncstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_196"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_196" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_196")))
#endif

uint32_t FREG_VE_GetmSdhsyncstart_Hsyncstart( void )
{
    register uint32_t value = FREG_VE_SdhsyncstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdhsyncstop".
**
** This function writes the given value to the register "Sdhsyncstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_197"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_197" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_197")))
#endif

void FREG_VE_SetSdhsyncstop( uint32_t value )
{
    FREG_VE_SdhsyncstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTOP)) = value;
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
** \brief Writes the bitgroup "Hsyncstop" of register "Sdhsyncstop".
**
** Defines the H-pos where hsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsyncstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_198"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_198" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_198")))
#endif

void FREG_VE_SetSdhsyncstop_Hsyncstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdhsyncstopMirror & ~mask;
    FREG_VE_SdhsyncstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTOP)) = value;
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
** \brief Reads the entire register "Sdhsyncstop".
**
** This function reads the value from the register "Sdhsyncstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_199"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_199" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_199")))
#endif

uint32_t FREG_VE_GetmSdhsyncstop( void )
{
    register uint32_t value = FREG_VE_SdhsyncstopMirror;
    return( value );
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
** \brief Reads the bitgroup "Hsyncstop" of register "Sdhsyncstop".
**
** Defines the H-pos where hsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsyncstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_200"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_200" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_200")))
#endif

uint32_t FREG_VE_GetmSdhsyncstop_Hsyncstop( void )
{
    register uint32_t value = FREG_VE_SdhsyncstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Sdhsyncoffset".
**
** This function writes the given value to the register "Sdhsyncoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_201"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_201" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_201")))
#endif

void FREG_VE_SetSdhsyncoffset( uint32_t value )
{
    FREG_VE_SdhsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCOFFSET)) = value;
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
** \brief Writes the bitgroup "Sdhsyncoffset" of register "Sdhsyncoffset".
**
** horizontal counter load value when frame sync arrives.
** 
** Lower three bit need to be set to 0x4
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdhsyncoffset" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_202"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_202" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_202")))
#endif

void FREG_VE_SetSdhsyncoffset_Sdhsyncoffset( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdhsyncoffsetMirror & ~mask;
    FREG_VE_SdhsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCOFFSET)) = value;
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
** \brief Reads the entire register "Sdhsyncoffset".
**
** This function reads the value from the register "Sdhsyncoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_203"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_203" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_203")))
#endif

uint32_t FREG_VE_GetmSdhsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdhsyncoffsetMirror;
    return( value );
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
** \brief Reads the bitgroup "Sdhsyncoffset" of register "Sdhsyncoffset".
**
** horizontal counter load value when frame sync arrives.
** 
** Lower three bit need to be set to 0x4
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdhsyncoffset" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_204"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_204" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_204")))
#endif

uint32_t FREG_VE_GetmSdhsyncoffset_Sdhsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdhsyncoffsetMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "VoOsd1clut".
**
** This function writes the given value to the index-th entry of the register
** array VoOsd1clut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_205"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_205" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_205")))
#endif

void FREG_VE_SetVoOsd1clut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutCb" of register "VoOsd1clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_206"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_206" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_206")))
#endif

void FREG_VE_SetVoOsd1clut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutY" of register "VoOsd1clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_207"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_207" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_207")))
#endif

void FREG_VE_SetVoOsd1clut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutCr" of register "VoOsd1clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_208"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_208" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_208")))
#endif

void FREG_VE_SetVoOsd1clut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutAlpha" of register "VoOsd1clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_209"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_209" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_209")))
#endif

void FREG_VE_SetVoOsd1clut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
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
** \brief Reads the entire register "VoOsd1clut".
**
** This function reads the value from the index-th entry of the register
** array VoOsd1clut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_210"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_210" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_210")))
#endif

uint32_t FREG_VE_GetmVoOsd1clut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    return( value );
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
** \brief Reads the bitgroup "ClutCb" of register "VoOsd1clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_211"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_211" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_211")))
#endif

uint32_t FREG_VE_GetmVoOsd1clut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
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
** \brief Reads the bitgroup "ClutY" of register "VoOsd1clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_212"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_212" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_212")))
#endif

uint32_t FREG_VE_GetmVoOsd1clut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
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
** \brief Reads the bitgroup "ClutCr" of register "VoOsd1clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_213"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_213" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_213")))
#endif

uint32_t FREG_VE_GetmVoOsd1clut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "ClutAlpha" of register "VoOsd1clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_214"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_214" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_214")))
#endif

uint32_t FREG_VE_GetmVoOsd1clut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "VoOsd2clut".
**
** This function writes the given value to the index-th entry of the register
** array VoOsd2clut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_215"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_215" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_215")))
#endif

void FREG_VE_SetVoOsd2clut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutCb" of register "VoOsd2clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_216"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_216" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_216")))
#endif

void FREG_VE_SetVoOsd2clut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutY" of register "VoOsd2clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_217"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_217" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_217")))
#endif

void FREG_VE_SetVoOsd2clut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutCr" of register "VoOsd2clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_218"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_218" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_218")))
#endif

void FREG_VE_SetVoOsd2clut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutAlpha" of register "VoOsd2clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_219"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_219" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_219")))
#endif

void FREG_VE_SetVoOsd2clut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
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
** \brief Reads the entire register "VoOsd2clut".
**
** This function reads the value from the index-th entry of the register
** array VoOsd2clut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_220"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_220" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_220")))
#endif

uint32_t FREG_VE_GetmVoOsd2clut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    return( value );
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
** \brief Reads the bitgroup "ClutCb" of register "VoOsd2clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_221"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_221" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_221")))
#endif

uint32_t FREG_VE_GetmVoOsd2clut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
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
** \brief Reads the bitgroup "ClutY" of register "VoOsd2clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_222"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_222" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_222")))
#endif

uint32_t FREG_VE_GetmVoOsd2clut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
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
** \brief Reads the bitgroup "ClutCr" of register "VoOsd2clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_223"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_223" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_223")))
#endif

uint32_t FREG_VE_GetmVoOsd2clut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "ClutAlpha" of register "VoOsd2clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_224"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_224" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_224")))
#endif

uint32_t FREG_VE_GetmVoOsd2clut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "VoCursorclut".
**
** This function writes the given value to the index-th entry of the register
** array VoCursorclut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_225"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_225" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_225")))
#endif

void FREG_VE_SetVoCursorclut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutCb" of register "VoCursorclut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_226"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_226" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_226")))
#endif

void FREG_VE_SetVoCursorclut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutY" of register "VoCursorclut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_227"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_227" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_227")))
#endif

void FREG_VE_SetVoCursorclut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutCr" of register "VoCursorclut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_228"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_228" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_228")))
#endif

void FREG_VE_SetVoCursorclut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
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
** \brief Writes the bitgroup "ClutAlpha" of register "VoCursorclut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_229"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_229" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_229")))
#endif

void FREG_VE_SetVoCursorclut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
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
** \brief Reads the entire register "VoCursorclut".
**
** This function reads the value from the index-th entry of the register
** array VoCursorclut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_230"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_230" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_230")))
#endif

uint32_t FREG_VE_GetmVoCursorclut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    return( value );
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
** \brief Reads the bitgroup "ClutCb" of register "VoCursorclut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_231"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_231" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_231")))
#endif

uint32_t FREG_VE_GetmVoCursorclut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
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
** \brief Reads the bitgroup "ClutY" of register "VoCursorclut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_232"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_232" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_232")))
#endif

uint32_t FREG_VE_GetmVoCursorclut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
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
** \brief Reads the bitgroup "ClutCr" of register "VoCursorclut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_233"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_233" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_233")))
#endif

uint32_t FREG_VE_GetmVoCursorclut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "ClutAlpha" of register "VoCursorclut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_234"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_234" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_234")))
#endif

uint32_t FREG_VE_GetmVoCursorclut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "SdSecfieldoffset".
**
** This function writes the given value to the register "SdSecfieldoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_235"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_235" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_235")))
#endif

void FREG_VE_SetSdSecfieldoffset( uint32_t value )
{
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
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
** \brief Writes the bitgroup "VOffsetTtxF1" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VOffsetTtxF1" consists of the bits 20..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x001F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_236"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_236" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_236")))
#endif

void FREG_VE_SetSdSecfieldoffset_VOffsetTtxF1( uint32_t value )
{
    register uint32_t mask = 0x001F0000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
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
** \brief Writes the bitgroup "VOffsetTtxF0" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of first field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VOffsetTtxF0" consists of the bits 12..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00001F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_237"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_237" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_237")))
#endif

void FREG_VE_SetSdSecfieldoffset_VOffsetTtxF0( uint32_t value )
{
    register uint32_t mask = 0x00001F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
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
** \brief Writes the bitgroup "PixelSyncHorVal" of register "SdSecfieldoffset".
**
** horizontal position of pixels relative to sync pulses
** Should be set to 2 (value important for correct CCIR output)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PixelSyncHorVal" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_238"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_238" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_238")))
#endif

void FREG_VE_SetSdSecfieldoffset_PixelSyncHorVal( uint32_t value )
{
    register uint32_t mask = 0x00000060UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
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
** \brief Writes the bitgroup "VerCount0" of register "SdSecfieldoffset".
**
** ver_count bit(0) value when restarted (ver_count start from 0 or 1)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VerCount0" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_239"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_239" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_239")))
#endif

void FREG_VE_SetSdSecfieldoffset_VerCount0( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
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
** \brief Writes the bitgroup "SecFieldOffset" of register "SdSecfieldoffset".
**
** offset for stop value of line counter for second field.
**  VER_SIZE - 2 + SEC_FIELD_OFFSET
** Recommended setting: 1.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SecFieldOffset" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_240"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_240" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_240")))
#endif

void FREG_VE_SetSdSecfieldoffset_SecFieldOffset( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
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
** \brief Reads the entire register "SdSecfieldoffset".
**
** This function reads the value from the register "SdSecfieldoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_241"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_241" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_241")))
#endif

uint32_t FREG_VE_GetmSdSecfieldoffset( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    return( value );
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
** \brief Reads the bitgroup "VOffsetTtxF1" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VOffsetTtxF1" consists of the bits 20..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x001F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_242"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_242" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_242")))
#endif

uint32_t FREG_VE_GetmSdSecfieldoffset_VOffsetTtxF1( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x001F0000UL ) >> 16;
    return( value );
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
** \brief Reads the bitgroup "VOffsetTtxF0" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of first field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VOffsetTtxF0" consists of the bits 12..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00001F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_243"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_243" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_243")))
#endif

uint32_t FREG_VE_GetmSdSecfieldoffset_VOffsetTtxF0( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00001F00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "PixelSyncHorVal" of register "SdSecfieldoffset".
**
** horizontal position of pixels relative to sync pulses
** Should be set to 2 (value important for correct CCIR output)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PixelSyncHorVal" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_244"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_244" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_244")))
#endif

uint32_t FREG_VE_GetmSdSecfieldoffset_PixelSyncHorVal( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00000060UL ) >> 5;
    return( value );
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
** \brief Reads the bitgroup "VerCount0" of register "SdSecfieldoffset".
**
** ver_count bit(0) value when restarted (ver_count start from 0 or 1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VerCount0" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_245"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_245" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_245")))
#endif

uint32_t FREG_VE_GetmSdSecfieldoffset_VerCount0( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
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
** \brief Reads the bitgroup "SecFieldOffset" of register "SdSecfieldoffset".
**
** offset for stop value of line counter for second field.
**  VER_SIZE - 2 + SEC_FIELD_OFFSET
** Recommended setting: 1.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SecFieldOffset" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_246"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_246" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_246")))
#endif

uint32_t FREG_VE_GetmSdSecfieldoffset_SecFieldOffset( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00000007UL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Rgbconf".
**
** This function writes the given value to the register "Rgbconf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_247"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_247" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_247")))
#endif

void FREG_VE_SetRgbconf( uint32_t value )
{
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "Colbar" of register "Rgbconf".
**
** Select for Multiplexer which enables colour Bar (100/100) insertion, see Block Diagram of Colour Encoder
** - '0': no colour bar
** - '1': colour bar on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Colbar" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_248"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_248" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_248")))
#endif

void FREG_VE_SetRgbconf_Colbar( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "Ycrcb" of register "Rgbconf".
**
** Output YCrCb instead of RGB, see Block Diagram of Colour Encoder
** - '0': output analog RGB
** - '1': output analog YCrCb
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ycrcb" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_249"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_249" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_249")))
#endif

void FREG_VE_SetRgbconf_Ycrcb( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "NtscOn" of register "Rgbconf".
**
** If the sync signal is added to the R, G or B signal, the rise and fall time of the edges is dependent on the colour standard.
** 
** Switch to NTSC edge in sync signal
** - '0': PAL
** - '1': NTSC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "NtscOn" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_250"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_250" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_250")))
#endif

void FREG_VE_SetRgbconf_NtscOn( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "BlkOn" of register "Rgbconf".
**
** In standard modes, the RGB De-matrix converts everything which is provided to the input of this block.
**  This bit allows signal blanking during the blanking periods. If the sync signal is inserted, the blanking periods are automatically blanked and this bit has no influence.
** - '0': no blanking of RGB signal
** - '1': blanking enable for RGB signal (during vertical and
** horizontal blanking period 0V is generated.)
** Must be set to 0, if YCRCB = 1
** To allow the adjustment of the brightness (YOFF), this value must be set to 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BlkOn" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_251"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_251" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_251")))
#endif

void FREG_VE_SetRgbconf_BlkOn( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "SynconBlue" of register "Rgbconf".
**
** Insert sync in Blue signal (or Cb), shifted 256 up
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SynconBlue" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_252"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_252" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_252")))
#endif

void FREG_VE_SetRgbconf_SynconBlue( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "SynconGree" of register "Rgbconf".
**
** Insert sync in Green signal (or Y), shifted 256 up
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SynconGree" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_253"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_253" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_253")))
#endif

void FREG_VE_SetRgbconf_SynconGree( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "SynconRed" of register "Rgbconf".
**
** Insert sync in Red signal (or Cr), shifted 256 up
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SynconRed" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_254"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_254" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_254")))
#endif

void FREG_VE_SetRgbconf_SynconRed( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Writes the bitgroup "RegDelayEn" of register "Rgbconf".
**
** Writing 11 to this register delays the RGB path by a clock period of 7 x 13.
** 5MHz. This allows the adjustment of the physical position of the RGB picture relative to the composite picture.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RegDelayEn" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_255"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_255" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_255")))
#endif

void FREG_VE_SetRgbconf_RegDelayEn( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
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
** \brief Reads the entire register "Rgbconf".
**
** This function reads the value from the register "Rgbconf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_256"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_256" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_256")))
#endif

uint32_t FREG_VE_GetmRgbconf( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    return( value );
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
** \brief Reads the bitgroup "Colbar" of register "Rgbconf".
**
** Select for Multiplexer which enables colour Bar (100/100) insertion, see Block Diagram of Colour Encoder
** - '0': no colour bar
** - '1': colour bar on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Colbar" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_257"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_257" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_257")))
#endif

uint32_t FREG_VE_GetmRgbconf_Colbar( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
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
** \brief Reads the bitgroup "Ycrcb" of register "Rgbconf".
**
** Output YCrCb instead of RGB, see Block Diagram of Colour Encoder
** - '0': output analog RGB
** - '1': output analog YCrCb
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ycrcb" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_258"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_258" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_258")))
#endif

uint32_t FREG_VE_GetmRgbconf_Ycrcb( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
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
** \brief Reads the bitgroup "NtscOn" of register "Rgbconf".
**
** If the sync signal is added to the R, G or B signal, the rise and fall time of the edges is dependent on the colour standard.
** 
** Switch to NTSC edge in sync signal
** - '0': PAL
** - '1': NTSC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "NtscOn" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_259"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_259" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_259")))
#endif

uint32_t FREG_VE_GetmRgbconf_NtscOn( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "BlkOn" of register "Rgbconf".
**
** In standard modes, the RGB De-matrix converts everything which is provided to the input of this block.
**  This bit allows signal blanking during the blanking periods. If the sync signal is inserted, the blanking periods are automatically blanked and this bit has no influence.
** - '0': no blanking of RGB signal
** - '1': blanking enable for RGB signal (during vertical and
** horizontal blanking period 0V is generated.)
** Must be set to 0, if YCRCB = 1
** To allow the adjustment of the brightness (YOFF), this value must be set to 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BlkOn" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_260"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_260" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_260")))
#endif

uint32_t FREG_VE_GetmRgbconf_BlkOn( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
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
** \brief Reads the bitgroup "SynconBlue" of register "Rgbconf".
**
** Insert sync in Blue signal (or Cb), shifted 256 up
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SynconBlue" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_261"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_261" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_261")))
#endif

uint32_t FREG_VE_GetmRgbconf_SynconBlue( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "SynconGree" of register "Rgbconf".
**
** Insert sync in Green signal (or Y), shifted 256 up
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SynconGree" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_262"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_262" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_262")))
#endif

uint32_t FREG_VE_GetmRgbconf_SynconGree( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
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
** \brief Reads the bitgroup "SynconRed" of register "Rgbconf".
**
** Insert sync in Red signal (or Cr), shifted 256 up
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SynconRed" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_263"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_263" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_263")))
#endif

uint32_t FREG_VE_GetmRgbconf_SynconRed( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
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
** \brief Reads the bitgroup "RegDelayEn" of register "Rgbconf".
**
** Writing 11 to this register delays the RGB path by a clock period of 7 x 13.
** 5MHz. This allows the adjustment of the physical position of the RGB picture relative to the composite picture.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RegDelayEn" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_264"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_264" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_264")))
#endif

uint32_t FREG_VE_GetmRgbconf_RegDelayEn( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
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
** \brief Writes the entire register "Rgblum".
**
** This function writes the given value to the register "Rgblum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_265"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_265" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_265")))
#endif

void FREG_VE_SetRgblum( uint32_t value )
{
    FREG_VE_RgblumMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBLUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBLUM)) = value;
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
** \brief Writes the bitgroup "Yoff" of register "Rgblum".
**
** Brightness adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Yoff" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_266"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_266" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_266")))
#endif

void FREG_VE_SetRgblum_Yoff( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_RgblumMirror & ~mask;
    FREG_VE_RgblumMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBLUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBLUM)) = value;
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
** \brief Writes the bitgroup "Yval" of register "Rgblum".
**
** Contrast adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Yval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_267"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_267" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_267")))
#endif

void FREG_VE_SetRgblum_Yval( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_RgblumMirror & ~mask;
    FREG_VE_RgblumMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBLUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBLUM)) = value;
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
** \brief Reads the entire register "Rgblum".
**
** This function reads the value from the register "Rgblum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_268"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_268" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_268")))
#endif

uint32_t FREG_VE_GetmRgblum( void )
{
    register uint32_t value = FREG_VE_RgblumMirror;
    return( value );
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
** \brief Reads the bitgroup "Yoff" of register "Rgblum".
**
** Brightness adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Yoff" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_269"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_269" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_269")))
#endif

uint32_t FREG_VE_GetmRgblum_Yoff( void )
{
    register uint32_t value = FREG_VE_RgblumMirror;
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "Yval" of register "Rgblum".
**
** Contrast adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Yval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_270"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_270" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_270")))
#endif

uint32_t FREG_VE_GetmRgblum_Yval( void )
{
    register uint32_t value = FREG_VE_RgblumMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Rgbchrom".
**
** This function writes the given value to the register "Rgbchrom".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_271"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_271" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_271")))
#endif

void FREG_VE_SetRgbchrom( uint32_t value )
{
    FREG_VE_RgbchromMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCHROM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCHROM)) = value;
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
** \brief Writes the bitgroup "Crval" of register "Rgbchrom".
**
** Chrominance CR adjustment of RGB output
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Crval" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_272"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_272" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_272")))
#endif

void FREG_VE_SetRgbchrom_Crval( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_RgbchromMirror & ~mask;
    FREG_VE_RgbchromMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCHROM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCHROM)) = value;
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
** \brief Writes the bitgroup "Cbval" of register "Rgbchrom".
**
** Chrominance CB adjustment of RGB output
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cbval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_273"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_273" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_273")))
#endif

void FREG_VE_SetRgbchrom_Cbval( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_RgbchromMirror & ~mask;
    FREG_VE_RgbchromMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCHROM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCHROM)) = value;
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
** \brief Reads the entire register "Rgbchrom".
**
** This function reads the value from the register "Rgbchrom".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_274"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_274" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_274")))
#endif

uint32_t FREG_VE_GetmRgbchrom( void )
{
    register uint32_t value = FREG_VE_RgbchromMirror;
    return( value );
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
** \brief Reads the bitgroup "Crval" of register "Rgbchrom".
**
** Chrominance CR adjustment of RGB output
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Crval" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_275"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_275" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_275")))
#endif

uint32_t FREG_VE_GetmRgbchrom_Crval( void )
{
    register uint32_t value = FREG_VE_RgbchromMirror;
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "Cbval" of register "Rgbchrom".
**
** Chrominance CB adjustment of RGB output
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cbval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_276"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_276" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_276")))
#endif

uint32_t FREG_VE_GetmRgbchrom_Cbval( void )
{
    register uint32_t value = FREG_VE_RgbchromMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Ceconf".
**
** This function writes the given value to the register "Ceconf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_277"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_277" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_277")))
#endif

void FREG_VE_SetCeconf( uint32_t value )
{
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Secam" of register "Ceconf".
**
** Enables the switching on of SECAM Colour Encoder.
** 
** 0: SECAM off
** 1: SECAM on (PAL bit is ignored)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Secam" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_278"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_278" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_278")))
#endif

void FREG_VE_SetCeconf_Secam( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Ttxen" of register "Ceconf".
**
** Enables teletext feed through for the Colour Encoder:
** 0: vertical and horizontal blanking period is blanked.
** 
** 1: line 6...22 and 318...335 data feed through is allowed for luminance only. Must be set to 1 in case of teletext re-insertion in the vertical 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ttxen" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_279"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_279" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_279")))
#endif

void FREG_VE_SetCeconf_Ttxen( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Ipce1sel" of register "Ceconf".
**
** Input selector of Colour Encoder:
** 0: standard YCrCb input
** 1: COLBAR mux out (see block diagram)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ipce1sel" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_280"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_280" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_280")))
#endif

void FREG_VE_SetCeconf_Ipce1sel( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Bwgui" of register "Ceconf".
**
** Stops the generation of colour carrier generation, results in output without color:
** 0: colour on (normal)
** 1: no colour (also for C output)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bwgui" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_281"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_281" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_281")))
#endif

void FREG_VE_SetCeconf_Bwgui( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Xsyncmx" of register "Ceconf".
**
** Disable the insertion of synchronisation signals to CVBS and Y:
** 0: insertion of synchronisation signals is enabled
** 1: disable synchronisation signal insertion (no sync in CVBS)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xsyncmx" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_282"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_282" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_282")))
#endif

void FREG_VE_SetCeconf_Xsyncmx( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Cydly" of register "Ceconf".
**
** Delay in 27.
** 0MHz cycles of luminance to chrominance or vice versa, dependent on CYSEL:
** Y-delay cydly[2:0] 0...7 cycles of 27MHz
** C-delay cydly[1:0] 0...3 cycles of 27.0MHz, here only the two LSBs are used
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cydly" consists of the bits 10..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000700UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_283"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_283" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_283")))
#endif

void FREG_VE_SetCeconf_Cydly( uint32_t value )
{
    register uint32_t mask = 0x00000700UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Cysel" of register "Ceconf".
**
** Delay luminance or chrominance 0: luminance will be delayed 1: chrominance will be delayed
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cysel" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_284"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_284" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_284")))
#endif

void FREG_VE_SetCeconf_Cysel( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "M3db" of register "Ceconf".
**
** Amplitude of burst in composite and C signal:
** 00: normal,
** 01: burst -3dB,
** 10: +7.
** 2%,
** 11: -7.2%
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M3db" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_285"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_285" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_285")))
#endif

void FREG_VE_SetCeconf_M3db( uint32_t value )
{
    register uint32_t mask = 0x00000060UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Pal525" of register "Ceconf".
**
** PAL 60 mode:
** 0: normal,
** 1: 525 line PAL, 60Hz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pal525" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_286"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_286" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_286")))
#endif

void FREG_VE_SetCeconf_Pal525( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Pal" of register "Ceconf".
**
** This bit allows the selection of PAL or NTSC mode and has influence to following parameters: colour burst amplitude, colour burst phase, rise/fall time & length of sync pulses, length of a horizontal line, number of lines per field/frame, etc.
**  Please ensu
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pal" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_287"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_287" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_287")))
#endif

void FREG_VE_SetCeconf_Pal( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "M1m0" of register "Ceconf".
**
** Clamping and enlargement of Input signal,
** 00 & 01: normal operation (Y: 16.
** ..235)
** if input value of Y is <=16, value is set to 16
** Y Input value 16...235 is amplified to 256...803
** 10: enlargement mode (Y: 32...235)
** if input value of Y is <=32, value is set to 32
** Y Input value 32...235 is amplified to 256...803
** 11: shrink mode (Y:0...235)
** Y value is feed through, no clamping
** Y Input value 0...235 is amplified to 256...803
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M1m0" consists of the bits 2..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000006UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_288"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_288" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_288")))
#endif

void FREG_VE_SetCeconf_M1m0( uint32_t value )
{
    register uint32_t mask = 0x00000006UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Writes the bitgroup "Pslev" of register "Ceconf".
**
** Sync Level for NTSC (for PAL always 20dec = 0x14)
** 0: Sync level for NTSC: 36dec = 0x24
** 1: Sync level for NTSC: 20dec = 0x14
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pslev" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_289"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_289" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_289")))
#endif

void FREG_VE_SetCeconf_Pslev( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
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
** \brief Reads the entire register "Ceconf".
**
** This function reads the value from the register "Ceconf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_290"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_290" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_290")))
#endif

uint32_t FREG_VE_GetmCeconf( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    return( value );
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
** \brief Reads the bitgroup "Secam" of register "Ceconf".
**
** Enables the switching on of SECAM Colour Encoder.
** 
** 0: SECAM off
** 1: SECAM on (PAL bit is ignored)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Secam" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_291"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_291" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_291")))
#endif

uint32_t FREG_VE_GetmCeconf_Secam( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
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
** \brief Reads the bitgroup "Ttxen" of register "Ceconf".
**
** Enables teletext feed through for the Colour Encoder:
** 0: vertical and horizontal blanking period is blanked.
** 
** 1: line 6...22 and 318...335 data feed through is allowed for luminance only. Must be set to 1 in case of teletext re-insertion in the vertical 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ttxen" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_292"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_292" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_292")))
#endif

uint32_t FREG_VE_GetmCeconf_Ttxen( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
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
** \brief Reads the bitgroup "Ipce1sel" of register "Ceconf".
**
** Input selector of Colour Encoder:
** 0: standard YCrCb input
** 1: COLBAR mux out (see block diagram)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ipce1sel" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_293"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_293" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_293")))
#endif

uint32_t FREG_VE_GetmCeconf_Ipce1sel( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
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
** \brief Reads the bitgroup "Bwgui" of register "Ceconf".
**
** Stops the generation of colour carrier generation, results in output without color:
** 0: colour on (normal)
** 1: no colour (also for C output)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bwgui" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_294"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_294" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_294")))
#endif

uint32_t FREG_VE_GetmCeconf_Bwgui( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
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
** \brief Reads the bitgroup "Xsyncmx" of register "Ceconf".
**
** Disable the insertion of synchronisation signals to CVBS and Y:
** 0: insertion of synchronisation signals is enabled
** 1: disable synchronisation signal insertion (no sync in CVBS)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xsyncmx" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_295"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_295" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_295")))
#endif

uint32_t FREG_VE_GetmCeconf_Xsyncmx( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
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
** \brief Reads the bitgroup "Cydly" of register "Ceconf".
**
** Delay in 27.
** 0MHz cycles of luminance to chrominance or vice versa, dependent on CYSEL:
** Y-delay cydly[2:0] 0...7 cycles of 27MHz
** C-delay cydly[1:0] 0...3 cycles of 27.0MHz, here only the two LSBs are used
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cydly" consists of the bits 10..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000700UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_296"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_296" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_296")))
#endif

uint32_t FREG_VE_GetmCeconf_Cydly( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000700UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "Cysel" of register "Ceconf".
**
** Delay luminance or chrominance 0: luminance will be delayed 1: chrominance will be delayed
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cysel" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_297"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_297" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_297")))
#endif

uint32_t FREG_VE_GetmCeconf_Cysel( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
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
** \brief Reads the bitgroup "M3db" of register "Ceconf".
**
** Amplitude of burst in composite and C signal:
** 00: normal,
** 01: burst -3dB,
** 10: +7.
** 2%,
** 11: -7.2%
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M3db" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_298"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_298" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_298")))
#endif

uint32_t FREG_VE_GetmCeconf_M3db( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000060UL ) >> 5;
    return( value );
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
** \brief Reads the bitgroup "Pal525" of register "Ceconf".
**
** PAL 60 mode:
** 0: normal,
** 1: 525 line PAL, 60Hz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pal525" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_299"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_299" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_299")))
#endif

uint32_t FREG_VE_GetmCeconf_Pal525( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
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
** \brief Reads the bitgroup "Pal" of register "Ceconf".
**
** This bit allows the selection of PAL or NTSC mode and has influence to following parameters: colour burst amplitude, colour burst phase, rise/fall time & length of sync pulses, length of a horizontal line, number of lines per field/frame, etc.
**  Please ensu
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pal" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_300"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_300" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_300")))
#endif

uint32_t FREG_VE_GetmCeconf_Pal( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
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
** \brief Reads the bitgroup "M1m0" of register "Ceconf".
**
** Clamping and enlargement of Input signal,
** 00 & 01: normal operation (Y: 16.
** ..235)
** if input value of Y is <=16, value is set to 16
** Y Input value 16...235 is amplified to 256...803
** 10: enlargement mode (Y: 32...235)
** if input value of Y is <=32, value is set to 32
** Y Input value 32...235 is amplified to 256...803
** 11: shrink mode (Y:0...235)
** Y value is feed through, no clamping
** Y Input value 0...235 is amplified to 256...803
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M1m0" consists of the bits 2..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000006UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_301"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_301" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_301")))
#endif

uint32_t FREG_VE_GetmCeconf_M1m0( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000006UL ) >> 1;
    return( value );
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
** \brief Reads the bitgroup "Pslev" of register "Ceconf".
**
** Sync Level for NTSC (for PAL always 20dec = 0x14)
** 0: Sync level for NTSC: 36dec = 0x24
** 1: Sync level for NTSC: 20dec = 0x14
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pslev" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_302"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_302" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_302")))
#endif

uint32_t FREG_VE_GetmCeconf_Pslev( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Ceburstint".
**
** This function writes the given value to the register "Ceburstint".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_303"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_303" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_303")))
#endif

void FREG_VE_SetCeburstint( uint32_t value )
{
    FREG_VE_CeburstintMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTINT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTINT)) = value;
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
** \brief Writes the bitgroup "Pal60mEn" of register "Ceburstint".
**
** Enable PAL 60/M correction.
**  Should be set to 1.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pal60mEn" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_304"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_304" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_304")))
#endif

void FREG_VE_SetCeburstint_Pal60mEn( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_CeburstintMirror & ~mask;
    FREG_VE_CeburstintMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTINT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTINT)) = value;
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
** \brief Writes the bitgroup "Fscint" of register "Ceburstint".
**
** Integer value of colour carrier frequency generator (see formula below)
** for PAL B/G: 0x541 = 1345
** for NTSC M: 0x43E = 1086
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fscint" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_305"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_305" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_305")))
#endif

void FREG_VE_SetCeburstint_Fscint( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_CeburstintMirror & ~mask;
    FREG_VE_CeburstintMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTINT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTINT)) = value;
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
** \brief Reads the entire register "Ceburstint".
**
** This function reads the value from the register "Ceburstint".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_306"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_306" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_306")))
#endif

uint32_t FREG_VE_GetmCeburstint( void )
{
    register uint32_t value = FREG_VE_CeburstintMirror;
    return( value );
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
** \brief Reads the bitgroup "Pal60mEn" of register "Ceburstint".
**
** Enable PAL 60/M correction.
**  Should be set to 1.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pal60mEn" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_307"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_307" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_307")))
#endif

uint32_t FREG_VE_GetmCeburstint_Pal60mEn( void )
{
    register uint32_t value = FREG_VE_CeburstintMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
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
** \brief Reads the bitgroup "Fscint" of register "Ceburstint".
**
** Integer value of colour carrier frequency generator (see formula below)
** for PAL B/G: 0x541 = 1345
** for NTSC M: 0x43E = 1086
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fscint" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_308"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_308" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_308")))
#endif

uint32_t FREG_VE_GetmCeburstint_Fscint( void )
{
    register uint32_t value = FREG_VE_CeburstintMirror;
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Ceburstfra1".
**
** This function writes the given value to the register "Ceburstfra1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_309"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_309" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_309")))
#endif

void FREG_VE_SetCeburstfra1( uint32_t value )
{
    FREG_VE_Ceburstfra1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA1)) = value;
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
** \brief Writes the bitgroup "Fscfra238" of register "Ceburstfra1".
**
** Fractional value of colour carrier frequency generator bit 23 down to 8 (see formula below)
** for PAL B/G: 0x3159
** for NTSC M: 0x0F7A
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fscfra238" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_310"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_310" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_310")))
#endif

void FREG_VE_SetCeburstfra1_Fscfra238( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ceburstfra1Mirror & ~mask;
    FREG_VE_Ceburstfra1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA1)) = value;
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
** \brief Reads the entire register "Ceburstfra1".
**
** This function reads the value from the register "Ceburstfra1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_311"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_311" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_311")))
#endif

uint32_t FREG_VE_GetmCeburstfra1( void )
{
    register uint32_t value = FREG_VE_Ceburstfra1Mirror;
    return( value );
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
** \brief Reads the bitgroup "Fscfra238" of register "Ceburstfra1".
**
** Fractional value of colour carrier frequency generator bit 23 down to 8 (see formula below)
** for PAL B/G: 0x3159
** for NTSC M: 0x0F7A
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fscfra238" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_312"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_312" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_312")))
#endif

uint32_t FREG_VE_GetmCeburstfra1_Fscfra238( void )
{
    register uint32_t value = FREG_VE_Ceburstfra1Mirror;
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Ceburstfra2".
**
** This function writes the given value to the register "Ceburstfra2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_313"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_313" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_313")))
#endif

void FREG_VE_SetCeburstfra2( uint32_t value )
{
    FREG_VE_Ceburstfra2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA2)) = value;
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
** \brief Writes the bitgroup "Fscfra70" of register "Ceburstfra2".
**
** Fractional value of burst frequency generator bits 7 down to 0 (see formula below)
** for PAL B/G: 0x68
** for NTSC M: 0xDF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fscfra70" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_314"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_314" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_314")))
#endif

void FREG_VE_SetCeburstfra2_Fscfra70( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ceburstfra2Mirror & ~mask;
    FREG_VE_Ceburstfra2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA2)) = value;
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
** \brief Reads the entire register "Ceburstfra2".
**
** This function reads the value from the register "Ceburstfra2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_315"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_315" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_315")))
#endif

uint32_t FREG_VE_GetmCeburstfra2( void )
{
    register uint32_t value = FREG_VE_Ceburstfra2Mirror;
    return( value );
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
** \brief Reads the bitgroup "Fscfra70" of register "Ceburstfra2".
**
** Fractional value of burst frequency generator bits 7 down to 0 (see formula below)
** for PAL B/G: 0x68
** for NTSC M: 0xDF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fscfra70" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_316"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_316" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_316")))
#endif

uint32_t FREG_VE_GetmCeburstfra2_Fscfra70( void )
{
    register uint32_t value = FREG_VE_Ceburstfra2Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "DacPd".
**
** This function writes the given value to the register "DacPd".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_317"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_317" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_317")))
#endif

void FREG_VE_SetDacPd( uint32_t value )
{
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "CeFilterFlag" of register "DacPd".
**
** 0: direct output from Color Encoder to DACs (27MHz)
** 1: interpolated output from Color Encoder to DACs (2-tap)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CeFilterFlag" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_318"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_318" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_318")))
#endif

void FREG_VE_SetDacPd_CeFilterFlag( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac6" of register "DacPd".
**
** Power down of DAC6:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac6" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_319"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_319" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_319")))
#endif

void FREG_VE_SetDacPd_Pddac6( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac5" of register "DacPd".
**
** Power down of DAC5:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac5" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_320"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_320" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_320")))
#endif

void FREG_VE_SetDacPd_Pddac5( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac4" of register "DacPd".
**
** Power down of DAC4 and VREF_DAC_4_6:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac4" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_321"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_321" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_321")))
#endif

void FREG_VE_SetDacPd_Pddac4( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac3" of register "DacPd".
**
** Power down of DAC3  and VREF3_DAC_3:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac3" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_322"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_322" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_322")))
#endif

void FREG_VE_SetDacPd_Pddac3( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac2" of register "DacPd".
**
** Power down of DAC2:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac2" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_323"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_323" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_323")))
#endif

void FREG_VE_SetDacPd_Pddac2( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac1" of register "DacPd".
**
** Power down of DAC1:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_324"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_324" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_324")))
#endif

void FREG_VE_SetDacPd_Pddac1( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Writes the bitgroup "Pddac0" of register "DacPd".
**
** Power down of DAC0 and VREF_DAC_0_2:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_325"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_325" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_325")))
#endif

void FREG_VE_SetDacPd_Pddac0( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
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
** \brief Reads the entire register "DacPd".
**
** This function reads the value from the register "DacPd".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_326"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_326" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_326")))
#endif

uint32_t FREG_VE_GetmDacPd( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    return( value );
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
** \brief Reads the bitgroup "CeFilterFlag" of register "DacPd".
**
** 0: direct output from Color Encoder to DACs (27MHz)
** 1: interpolated output from Color Encoder to DACs (2-tap)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CeFilterFlag" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_327"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_327" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_327")))
#endif

uint32_t FREG_VE_GetmDacPd_CeFilterFlag( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
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
** \brief Reads the bitgroup "Pddac6" of register "DacPd".
**
** Power down of DAC6:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac6" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_328"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_328" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_328")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac6( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
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
** \brief Reads the bitgroup "Pddac5" of register "DacPd".
**
** Power down of DAC5:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac5" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_329"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_329" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_329")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac5( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
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
** \brief Reads the bitgroup "Pddac4" of register "DacPd".
**
** Power down of DAC4 and VREF_DAC_4_6:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac4" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_330"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_330" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_330")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac4( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
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
** \brief Reads the bitgroup "Pddac3" of register "DacPd".
**
** Power down of DAC3  and VREF3_DAC_3:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac3" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_331"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_331" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_331")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac3( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
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
** \brief Reads the bitgroup "Pddac2" of register "DacPd".
**
** Power down of DAC2:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac2" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_332"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_332" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_332")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac2( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Pddac1" of register "DacPd".
**
** Power down of DAC1:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_333"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_333" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_333")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac1( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
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
** \brief Reads the bitgroup "Pddac0" of register "DacPd".
**
** Power down of DAC0 and VREF_DAC_0_2:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_334"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_334" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_334")))
#endif

uint32_t FREG_VE_GetmDacPd_Pddac0( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
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
** \brief Writes the entire register "Enc656wss".
**
** This function writes the given value to the register "Enc656wss".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_335"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_335" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_335")))
#endif

void FREG_VE_SetEnc656wss( uint32_t value )
{
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "WssPostTimingMode" of register "Enc656wss".
**
** 1 = blanking after wss signal is conforming to standard
** 0 = old blanking mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WssPostTimingMode" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_336"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_336" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_336")))
#endif

void FREG_VE_SetEnc656wss_WssPostTimingMode( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "Clk27Inv" of register "Enc656wss".
**
** Invert 27.
** 0MHz for ITU-656 Output
** 0: not inverted
** 1: inverted
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk27Inv" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_337"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_337" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_337")))
#endif

void FREG_VE_SetEnc656wss_Clk27Inv( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "WssTimingMode" of register "Enc656wss".
**
** 1 = new timing mode (correct horizontal timing)
** 0 = old timing mode (output frequency is slightly wrong)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WssTimingMode" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_338"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_338" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_338")))
#endif

void FREG_VE_SetEnc656wss_WssTimingMode( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "WssMode" of register "Enc656wss".
**
** WSS insertion: 0: WSS insertion off, 1: WSS insertion on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WssMode" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_339"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_339" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_339")))
#endif

void FREG_VE_SetEnc656wss_WssMode( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "Ccmask" of register "Enc656wss".
**
** Masking input Y & C data of line 21 and line 284 (for NTSC only)
** 0: normal operation,
** 1: masking enabled
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ccmask" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_340"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_340" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_340")))
#endif

void FREG_VE_SetEnc656wss_Ccmask( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "VbidEn" of register "Enc656wss".
**
** VBID insertion for line 20 and line 283 (for NTSC only)
** 0: VBID insertion off
** 1: VBID insertion on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VbidEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_341"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_341" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_341")))
#endif

void FREG_VE_SetEnc656wss_VbidEn( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "CcM" of register "Enc656wss".
**
** Closed caption off/on (for NTSC only)
** 00: closed caption insertion disabled
** 01: closed caption insertion enable for line 21
** 10: closed caption insertion enable for line 284
** 11: closed caption insertion enable for line 21 and line 284
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CcM" consists of the bits 7..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x000000C0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_342"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_342" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_342")))
#endif

void FREG_VE_SetEnc656wss_CcM( uint32_t value )
{
    register uint32_t mask = 0x000000C0UL;
    value = ( value << 6 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "Iprgbsel" of register "Enc656wss".
**
** Input selector for RGB conversion
** 00: YCbCr1
** 10:Color bar 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Iprgbsel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_343"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_343" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_343")))
#endif

void FREG_VE_SetEnc656wss_Iprgbsel( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Writes the bitgroup "Ip656sel" of register "Enc656wss".
**
** Input selector for ITU-R656 Encoder
** 0: YCbCr1
** 1:Color bar 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ip656sel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_344"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_344" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_344")))
#endif

void FREG_VE_SetEnc656wss_Ip656sel( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
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
** \brief Reads the entire register "Enc656wss".
**
** This function reads the value from the register "Enc656wss".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_345"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_345" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_345")))
#endif

uint32_t FREG_VE_GetmEnc656wss( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    return( value );
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
** \brief Reads the bitgroup "WssPostTimingMode" of register "Enc656wss".
**
** 1 = blanking after wss signal is conforming to standard
** 0 = old blanking mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WssPostTimingMode" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_346"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_346" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_346")))
#endif

uint32_t FREG_VE_GetmEnc656wss_WssPostTimingMode( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
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
** \brief Reads the bitgroup "Clk27Inv" of register "Enc656wss".
**
** Invert 27.
** 0MHz for ITU-656 Output
** 0: not inverted
** 1: inverted
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk27Inv" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_347"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_347" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_347")))
#endif

uint32_t FREG_VE_GetmEnc656wss_Clk27Inv( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
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
** \brief Reads the bitgroup "WssTimingMode" of register "Enc656wss".
**
** 1 = new timing mode (correct horizontal timing)
** 0 = old timing mode (output frequency is slightly wrong)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WssTimingMode" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_348"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_348" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_348")))
#endif

uint32_t FREG_VE_GetmEnc656wss_WssTimingMode( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
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
** \brief Reads the bitgroup "WssMode" of register "Enc656wss".
**
** WSS insertion: 0: WSS insertion off, 1: WSS insertion on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WssMode" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_349"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_349" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_349")))
#endif

uint32_t FREG_VE_GetmEnc656wss_WssMode( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
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
** \brief Reads the bitgroup "Ccmask" of register "Enc656wss".
**
** Masking input Y & C data of line 21 and line 284 (for NTSC only)
** 0: normal operation,
** 1: masking enabled
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ccmask" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_350"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_350" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_350")))
#endif

uint32_t FREG_VE_GetmEnc656wss_Ccmask( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
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
** \brief Reads the bitgroup "VbidEn" of register "Enc656wss".
**
** VBID insertion for line 20 and line 283 (for NTSC only)
** 0: VBID insertion off
** 1: VBID insertion on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VbidEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_351"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_351" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_351")))
#endif

uint32_t FREG_VE_GetmEnc656wss_VbidEn( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "CcM" of register "Enc656wss".
**
** Closed caption off/on (for NTSC only)
** 00: closed caption insertion disabled
** 01: closed caption insertion enable for line 21
** 10: closed caption insertion enable for line 284
** 11: closed caption insertion enable for line 21 and line 284
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CcM" consists of the bits 7..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x000000C0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_352"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_352" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_352")))
#endif

uint32_t FREG_VE_GetmEnc656wss_CcM( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x000000C0UL ) >> 6;
    return( value );
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
** \brief Reads the bitgroup "Iprgbsel" of register "Enc656wss".
**
** Input selector for RGB conversion
** 00: YCbCr1
** 10:Color bar 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Iprgbsel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_353"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_353" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_353")))
#endif

uint32_t FREG_VE_GetmEnc656wss_Iprgbsel( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
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
** \brief Reads the bitgroup "Ip656sel" of register "Enc656wss".
**
** Input selector for ITU-R656 Encoder
** 0: YCbCr1
** 1:Color bar 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ip656sel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_354"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_354" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_354")))
#endif

uint32_t FREG_VE_GetmEnc656wss_Ip656sel( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Ccline21".
**
** This function writes the given value to the register "Ccline21".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_355"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_355" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_355")))
#endif

void FREG_VE_SetCcline21( uint32_t value )
{
    FREG_VE_Ccline21Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE21, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE21)) = value;
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
** \brief Writes the bitgroup "L21c2" of register "Ccline21".
**
** Closed caption character 2 of line 21
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L21c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_356"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_356" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_356")))
#endif

void FREG_VE_SetCcline21_L21c2( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_Ccline21Mirror & ~mask;
    FREG_VE_Ccline21Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE21, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE21)) = value;
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
** \brief Writes the bitgroup "L21c1" of register "Ccline21".
**
** Closed caption character 1 of line 21
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L21c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_357"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_357" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_357")))
#endif

void FREG_VE_SetCcline21_L21c1( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ccline21Mirror & ~mask;
    FREG_VE_Ccline21Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE21, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE21)) = value;
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
** \brief Reads the entire register "Ccline21".
**
** This function reads the value from the register "Ccline21".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_358"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_358" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_358")))
#endif

uint32_t FREG_VE_GetmCcline21( void )
{
    register uint32_t value = FREG_VE_Ccline21Mirror;
    return( value );
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
** \brief Reads the bitgroup "L21c2" of register "Ccline21".
**
** Closed caption character 2 of line 21
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L21c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_359"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_359" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_359")))
#endif

uint32_t FREG_VE_GetmCcline21_L21c2( void )
{
    register uint32_t value = FREG_VE_Ccline21Mirror;
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "L21c1" of register "Ccline21".
**
** Closed caption character 1 of line 21
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L21c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_360"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_360" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_360")))
#endif

uint32_t FREG_VE_GetmCcline21_L21c1( void )
{
    register uint32_t value = FREG_VE_Ccline21Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Ccline284".
**
** This function writes the given value to the register "Ccline284".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_361"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_361" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_361")))
#endif

void FREG_VE_SetCcline284( uint32_t value )
{
    FREG_VE_Ccline284Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE284, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE284)) = value;
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
** \brief Writes the bitgroup "L284c2" of register "Ccline284".
**
** Closed caption character 2 of line 284
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L284c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_362"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_362" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_362")))
#endif

void FREG_VE_SetCcline284_L284c2( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_Ccline284Mirror & ~mask;
    FREG_VE_Ccline284Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE284, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE284)) = value;
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
** \brief Writes the bitgroup "L284c1" of register "Ccline284".
**
** Closed caption character 1 of line 284
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L284c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_363"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_363" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_363")))
#endif

void FREG_VE_SetCcline284_L284c1( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ccline284Mirror & ~mask;
    FREG_VE_Ccline284Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE284, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE284)) = value;
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
** \brief Reads the entire register "Ccline284".
**
** This function reads the value from the register "Ccline284".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_364"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_364" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_364")))
#endif

uint32_t FREG_VE_GetmCcline284( void )
{
    register uint32_t value = FREG_VE_Ccline284Mirror;
    return( value );
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
** \brief Reads the bitgroup "L284c2" of register "Ccline284".
**
** Closed caption character 2 of line 284
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L284c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_365"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_365" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_365")))
#endif

uint32_t FREG_VE_GetmCcline284_L284c2( void )
{
    register uint32_t value = FREG_VE_Ccline284Mirror;
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
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
** \brief Reads the bitgroup "L284c1" of register "Ccline284".
**
** Closed caption character 1 of line 284
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L284c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_366"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_366" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_366")))
#endif

uint32_t FREG_VE_GetmCcline284_L284c1( void )
{
    register uint32_t value = FREG_VE_Ccline284Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Vbidwords".
**
** This function writes the given value to the register "Vbidwords".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_367"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_367" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_367")))
#endif

void FREG_VE_SetVbidwords( uint32_t value )
{
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
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
** \brief Writes the bitgroup "EnSecamTtx" of register "Vbidwords".
**
** Use PAL horizontal blanking mode for SECAM signals to allow TTX insertion in SECAM signals.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnSecamTtx" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_368"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_368" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_368")))
#endif

void FREG_VE_SetVbidwords_EnSecamTtx( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
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
** \brief Writes the bitgroup "Vbidw2" of register "Vbidwords".
**
** VBID word 2 (CRCC is generated internal)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vbidw2" consists of the bits 13..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00003FC0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_369"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_369" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_369")))
#endif

void FREG_VE_SetVbidwords_Vbidw2( uint32_t value )
{
    register uint32_t mask = 0x00003FC0UL;
    value = ( value << 6 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
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
** \brief Writes the bitgroup "Vbidw1" of register "Vbidwords".
**
** VBID word 1 (CRCC is generated internal)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vbidw1" consists of the bits 5..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000003CUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_370"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_370" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_370")))
#endif

void FREG_VE_SetVbidwords_Vbidw1( uint32_t value )
{
    register uint32_t mask = 0x0000003CUL;
    value = ( value << 2 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
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
** \brief Writes the bitgroup "Vbidw0" of register "Vbidwords".
**
** VBID word 0 (CRCC is generated internal)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vbidw0" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_371"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_371" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_371")))
#endif

void FREG_VE_SetVbidwords_Vbidw0( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
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
** \brief Reads the entire register "Vbidwords".
**
** This function reads the value from the register "Vbidwords".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_372"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_372" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_372")))
#endif

uint32_t FREG_VE_GetmVbidwords( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    return( value );
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
** \brief Reads the bitgroup "EnSecamTtx" of register "Vbidwords".
**
** Use PAL horizontal blanking mode for SECAM signals to allow TTX insertion in SECAM signals.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnSecamTtx" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_373"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_373" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_373")))
#endif

uint32_t FREG_VE_GetmVbidwords_EnSecamTtx( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
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
** \brief Reads the bitgroup "Vbidw2" of register "Vbidwords".
**
** VBID word 2 (CRCC is generated internal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vbidw2" consists of the bits 13..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00003FC0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_374"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_374" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_374")))
#endif

uint32_t FREG_VE_GetmVbidwords_Vbidw2( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x00003FC0UL ) >> 6;
    return( value );
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
** \brief Reads the bitgroup "Vbidw1" of register "Vbidwords".
**
** VBID word 1 (CRCC is generated internal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vbidw1" consists of the bits 5..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000003CUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_375"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_375" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_375")))
#endif

uint32_t FREG_VE_GetmVbidwords_Vbidw1( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x0000003CUL ) >> 2;
    return( value );
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
** \brief Reads the bitgroup "Vbidw0" of register "Vbidwords".
**
** VBID word 0 (CRCC is generated internal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vbidw0" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_376"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_376" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_376")))
#endif

uint32_t FREG_VE_GetmVbidwords_Vbidw0( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
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
** \brief Writes the entire register "Wssdata".
**
** This function writes the given value to the register "Wssdata".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_377"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_377" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_377")))
#endif

void FREG_VE_SetWssdata( uint32_t value )
{
    FREG_VE_WssdataMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_WSSDATA, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_WSSDATA)) = value;
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
** \brief Writes the bitgroup "Wssword" of register "Wssdata".
**
** Wide Screen Signalling Data
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wssword" consists of the bits 13..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00003FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_378"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_378" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_378")))
#endif

void FREG_VE_SetWssdata_Wssword( uint32_t value )
{
    register uint32_t mask = 0x00003FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_WssdataMirror & ~mask;
    FREG_VE_WssdataMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_WSSDATA, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_WSSDATA)) = value;
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
** \brief Reads the entire register "Wssdata".
**
** This function reads the value from the register "Wssdata".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_379"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_379" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_379")))
#endif

uint32_t FREG_VE_GetmWssdata( void )
{
    register uint32_t value = FREG_VE_WssdataMirror;
    return( value );
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
** \brief Reads the bitgroup "Wssword" of register "Wssdata".
**
** Wide Screen Signalling Data
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wssword" consists of the bits 13..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00003FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_380"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_380" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_380")))
#endif

uint32_t FREG_VE_GetmWssdata_Wssword( void )
{
    register uint32_t value = FREG_VE_WssdataMirror;
    value = ( value & 0x00003FFFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "LutConf".
**
** This function writes the given value to the register "LutConf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_381"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_381" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_381")))
#endif

void FREG_VE_SetLutConf( uint32_t value )
{
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
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
** \brief Writes the bitgroup "RgbLutEn" of register "LutConf".
**
** 0: RGB output without LUTs
** 1: RGB output with LUTs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RgbLutEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_382"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_382" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_382")))
#endif

void FREG_VE_SetLutConf_RgbLutEn( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_VE_LutConfMirror & ~mask;
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
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
** \brief Writes the bitgroup "LutSel" of register "LutConf".
**
** 0: YCrCb input for LUTs
** 1: RGB input for LUTs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LutSel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_383"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_383" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_383")))
#endif

void FREG_VE_SetLutConf_LutSel( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_LutConfMirror & ~mask;
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
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
** \brief Writes the bitgroup "LutEn" of register "LutConf".
**
** 0: without Look-Up-Tables
** 1: with Look-Up-Tables for YCrCb  or RGB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LutEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_384"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_384" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_384")))
#endif

void FREG_VE_SetLutConf_LutEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutConfMirror & ~mask;
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
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
** \brief Reads the entire register "LutConf".
**
** This function reads the value from the register "LutConf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_385"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_385" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_385")))
#endif

uint32_t FREG_VE_GetmLutConf( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    return( value );
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
** \brief Reads the bitgroup "RgbLutEn" of register "LutConf".
**
** 0: RGB output without LUTs
** 1: RGB output with LUTs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RgbLutEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_386"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_386" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_386")))
#endif

uint32_t FREG_VE_GetmLutConf_RgbLutEn( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
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
** \brief Reads the bitgroup "LutSel" of register "LutConf".
**
** 0: YCrCb input for LUTs
** 1: RGB input for LUTs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LutSel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_387"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_387" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_387")))
#endif

uint32_t FREG_VE_GetmLutConf_LutSel( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
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
** \brief Reads the bitgroup "LutEn" of register "LutConf".
**
** 0: without Look-Up-Tables
** 1: with Look-Up-Tables for YCrCb  or RGB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LutEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_388"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_388" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_388")))
#endif

uint32_t FREG_VE_GetmLutConf_LutEn( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
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
** \brief Writes the entire register "LutY".
**
** This function writes the given value to the index-th entry of the register
** array LutY.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_389"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_389" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_389")))
#endif

void FREG_VE_SetLutY( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_LutYMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTY+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTY+(index*0x4))) = value;
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
** \brief Writes the bitgroup "Data" of register "LutY".
**
** Y or R Value (unsigned.
**  Note in case of YCrCb: output values cover the 10 bit DAC range including sync levels.)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_390"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_390" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_390")))
#endif

void FREG_VE_SetLutY_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutYMirror[index] & ~mask;
    FREG_VE_LutYMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTY+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTY+(index*0x4))) = value;
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
** \brief Reads the entire register "LutY".
**
** This function reads the value from the index-th entry of the register
** array LutY.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_391"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_391" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_391")))
#endif

uint32_t FREG_VE_GetmLutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutYMirror[index];
    return( value );
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
** \brief Reads the bitgroup "Data" of register "LutY".
**
** Y or R Value (unsigned.
**  Note in case of YCrCb: output values cover the 10 bit DAC range including sync levels.)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_392"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_392" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_392")))
#endif

uint32_t FREG_VE_GetmLutY_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutYMirror[index];
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "LutCr".
**
** This function writes the given value to the index-th entry of the register
** array LutCr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_393"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_393" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_393")))
#endif

void FREG_VE_SetLutCr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_LutCrMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCR+(index*0x4))) = value;
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
** \brief Writes the bitgroup "Data" of register "LutCr".
**
** CB or G Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_394"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_394" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_394")))
#endif

void FREG_VE_SetLutCr_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutCrMirror[index] & ~mask;
    FREG_VE_LutCrMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCR+(index*0x4))) = value;
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
** \brief Reads the entire register "LutCr".
**
** This function reads the value from the index-th entry of the register
** array LutCr.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_395"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_395" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_395")))
#endif

uint32_t FREG_VE_GetmLutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCrMirror[index];
    return( value );
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
** \brief Reads the bitgroup "Data" of register "LutCr".
**
** CB or G Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_396"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_396" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_396")))
#endif

uint32_t FREG_VE_GetmLutCr_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCrMirror[index];
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "LutCb".
**
** This function writes the given value to the index-th entry of the register
** array LutCb.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_397"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_397" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_397")))
#endif

void FREG_VE_SetLutCb( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_LutCbMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCB+(index*0x4))) = value;
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
** \brief Writes the bitgroup "Data" of register "LutCb".
**
** CR or B Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_398"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_398" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_398")))
#endif

void FREG_VE_SetLutCb_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutCbMirror[index] & ~mask;
    FREG_VE_LutCbMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCB+(index*0x4))) = value;
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
** \brief Reads the entire register "LutCb".
**
** This function reads the value from the index-th entry of the register
** array LutCb.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_399"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_399" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_399")))
#endif

uint32_t FREG_VE_GetmLutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCbMirror[index];
    return( value );
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
** \brief Reads the bitgroup "Data" of register "LutCb".
**
** CR or B Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_400"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_400" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_400")))
#endif

uint32_t FREG_VE_GetmLutCb_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCbMirror[index];
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "VoMixyuvrgb".
**
** This function writes the given value to the index-th entry of the register
** array VoMixyuvrgb.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_401"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_401" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_401")))
#endif

void FREG_VE_SetVoMixyuvrgb( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXYUVRGB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4))) = value;
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
** \brief Writes the bitgroup "Data" of register "VoMixyuvrgb".
**
** YUV2RGB conversion matrix values
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_402"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_402" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_402")))
#endif

void FREG_VE_SetVoMixyuvrgb_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXYUVRGB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4))) = value;
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
** \brief Reads the entire register "VoMixyuvrgb".
**
** This function reads the value from the index-th entry of the register
** array VoMixyuvrgb.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_403"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_403" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_403")))
#endif

uint32_t FREG_VE_GetVoMixyuvrgb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4)));
    return( value );
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
** \brief Reads the bitgroup "Data" of register "VoMixyuvrgb".
**
** YUV2RGB conversion matrix values
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_404"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_404" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_404")))
#endif

uint32_t FREG_VE_GetVoMixyuvrgb_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
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
** \brief Writes the entire register "VoMixrgbyuv".
**
** This function writes the given value to the index-th entry of the register
** array VoMixrgbyuv.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_405"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_405" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_405")))
#endif

void FREG_VE_SetVoMixrgbyuv( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXRGBYUV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4))) = value;
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
** \brief Writes the bitgroup "Data" of register "VoMixrgbyuv".
**
** RGB2YUV conversion matrix values
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_406"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_406" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_406")))
#endif

void FREG_VE_SetVoMixrgbyuv_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXRGBYUV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4))) = value;
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
** \brief Reads the entire register "VoMixrgbyuv".
**
** This function reads the value from the index-th entry of the register
** array VoMixrgbyuv.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_407"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_407" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_407")))
#endif

uint32_t FREG_VE_GetVoMixrgbyuv( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4)));
    return( value );
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
** \brief Reads the bitgroup "Data" of register "VoMixrgbyuv".
**
** RGB2YUV conversion matrix values
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_408"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_408" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_408")))
#endif

uint32_t FREG_VE_GetVoMixrgbyuv_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

/*!
********************************************************************************
**
** \brief Initializes the "VE" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_VE_Init( void )
{
    FREG_VE_SdCcfilterenableMirror |= ( ( 0 << 2 ) & 0x00000004UL );
    FREG_VE_SdCcfilterenableMirror |= ( ( 0 << 1 ) & 0x00000002UL );
    FREG_VE_SdCcfilterenableMirror |= ( ( 0 << 0 ) & 0x00000001UL );
    FREG_VE_SdHorlinelengthMirror |= ( ( 0xD7E << 0 ) & 0x00001FFFUL );
    FREG_VE_SdVersizeMirror |= ( ( 0x138 << 0 ) & 0x000003FFUL );
    FREG_VE_SdBackgroundMirror |= ( ( 0x10 << 16 ) & 0x00FF0000UL );
    FREG_VE_SdBackgroundMirror |= ( ( 0x80 << 8 ) & 0x0000FF00UL );
    FREG_VE_SdBackgroundMirror |= ( ( 0x80 << 0 ) & 0x000000FFUL );
    FREG_VE_SdVohorstartMirror |= ( ( 0 << 0 ) & 0x00001FFFUL );
    FREG_VE_SdVohorstopMirror |= ( ( 0 << 0 ) & 0x00001FFFUL );
    FREG_VE_SdVoverstartMirror |= ( ( 0 << 0 ) & 0x000003FFUL );
    FREG_VE_SdVoverstopMirror |= ( ( 0 << 0 ) & 0x000003FFUL );
    FREG_VE_SdTtxhorstartMirror |= ( ( 0 << 16 ) & 0x00010000UL );
    FREG_VE_SdTtxhorstartMirror |= ( ( 0 << 0 ) & 0x00000FFFUL );
    FREG_VE_SdhvsynccfgMirror |= ( ( 0 << 5 ) & 0x00000020UL );
    FREG_VE_SdvsyncoffsetMirror |= ( ( 0 << 10 ) & 0x00000400UL );
    FREG_VE_SdvsyncoffsetMirror |= ( ( 0 << 0 ) & 0x000003FFUL );
    FREG_VE_SdhsyncoffsetMirror |= ( ( 0 << 0 ) & 0x00001FFFUL );
    FREG_VE_SdSecfieldoffsetMirror |= ( ( 1 << 16 ) & 0x001F0000UL );
    FREG_VE_SdSecfieldoffsetMirror |= ( ( 1 << 8 ) & 0x00001F00UL );
    FREG_VE_SdSecfieldoffsetMirror |= ( ( 3 << 5 ) & 0x00000060UL );
    FREG_VE_SdSecfieldoffsetMirror |= ( ( 0 << 4 ) & 0x00000010UL );
    FREG_VE_SdSecfieldoffsetMirror |= ( ( 1 << 0 ) & 0x00000007UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 12 ) & 0x00001000UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 11 ) & 0x00000800UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 10 ) & 0x00000400UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 9 ) & 0x00000200UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 7 ) & 0x00000080UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 6 ) & 0x00000040UL );
    FREG_VE_RgbconfMirror |= ( ( 0 << 4 ) & 0x00000030UL );
    FREG_VE_RgblumMirror |= ( ( 0x00 << 8 ) & 0x0000FF00UL );
    FREG_VE_RgblumMirror |= ( ( 0x2F << 0 ) & 0x0000007FUL );
    FREG_VE_RgbchromMirror |= ( ( 0x2E << 8 ) & 0x00007F00UL );
    FREG_VE_RgbchromMirror |= ( ( 0x2E << 0 ) & 0x0000007FUL );
    FREG_VE_CeconfMirror |= ( ( 0 << 15 ) & 0x00008000UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 14 ) & 0x00004000UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 13 ) & 0x00002000UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 12 ) & 0x00001000UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 11 ) & 0x00000800UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 8 ) & 0x00000700UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 7 ) & 0x00000080UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 5 ) & 0x00000060UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 4 ) & 0x00000010UL );
    FREG_VE_CeconfMirror |= ( ( 1 << 3 ) & 0x00000008UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 1 ) & 0x00000006UL );
    FREG_VE_CeconfMirror |= ( ( 0 << 0 ) & 0x00000001UL );
    FREG_VE_CeburstintMirror |= ( ( 0 << 12 ) & 0x00001000UL );
    FREG_VE_CeburstintMirror |= ( ( 0x541 << 0 ) & 0x00000FFFUL );
    FREG_VE_Ceburstfra1Mirror |= ( ( 0x3159 << 0 ) & 0x0000FFFFUL );
    FREG_VE_Ceburstfra2Mirror |= ( ( 0x68 << 0 ) & 0x000000FFUL );
    FREG_VE_DacPdMirror |= ( ( 1 << 15 ) & 0x00008000UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 14 ) & 0x00004000UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 13 ) & 0x00002000UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 12 ) & 0x00001000UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 11 ) & 0x00000800UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 10 ) & 0x00000400UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 9 ) & 0x00000200UL );
    FREG_VE_DacPdMirror |= ( ( 1 << 8 ) & 0x00000100UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 15 ) & 0x00008000UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 14 ) & 0x00004000UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 11 ) & 0x00000800UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 10 ) & 0x00000400UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 9 ) & 0x00000200UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 6 ) & 0x000000C0UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 1 ) & 0x00000002UL );
    FREG_VE_Enc656wssMirror |= ( ( 0 << 0 ) & 0x00000001UL );
    FREG_VE_Ccline21Mirror |= ( ( 0 << 8 ) & 0x00007F00UL );
    FREG_VE_Ccline284Mirror |= ( ( 0 << 8 ) & 0x00007F00UL );
    FREG_VE_VbidwordsMirror |= ( ( 0 << 15 ) & 0x00008000UL );
    FREG_VE_VbidwordsMirror |= ( ( 0 << 6 ) & 0x00003FC0UL );
    FREG_VE_VbidwordsMirror |= ( ( 0 << 2 ) & 0x0000003CUL );
    FREG_VE_VbidwordsMirror |= ( ( 0 << 0 ) & 0x00000003UL );
    FREG_VE_WssdataMirror |= ( ( 0 << 0 ) & 0x00003FFFUL );
    FREG_VE_LutConfMirror |= ( ( 0 << 2 ) & 0x00000004UL );
    FREG_VE_LutConfMirror |= ( ( 0 << 1 ) & 0x00000002UL );
    FREG_VE_LutConfMirror |= ( ( 0 << 0 ) & 0x00000001UL );
}
