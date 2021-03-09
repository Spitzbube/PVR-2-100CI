/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_ve_hd.c
**
** \brief     VE_HD access functions
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
#define FREG_VE_HD_C

#include <stdint.h>
#include "reg_ve_hd.h"

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Enable".
**
** This function writes the given value to the register "Enable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_1")))
#endif

void FREG_VE_HD_SetEnable( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ConvEn" of register "Enable".
**
** 3x4 matix enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ConvEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_2")))
#endif

void FREG_VE_HD_SetEnable_ConvEn( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RgbEn" of register "Enable".
**
** RGB modus enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RgbEn" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_3")))
#endif

void FREG_VE_HD_SetEnable_RgbEn( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "En" of register "Enable".
**
** Videoencoder enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "En" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_4")))
#endif

void FREG_VE_HD_SetEnable_En( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_ENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Enable".
**
** This function reads the value from the register "Enable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_5")))
#endif

uint32_t FREG_VE_HD_GetEnable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_ENABLE));
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
** \brief Reads the bitgroup "ConvEn" of register "Enable".
**
** 3x4 matix enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ConvEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_6")))
#endif

uint32_t FREG_VE_HD_GetEnable_ConvEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_ENABLE));
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
** \brief Reads the bitgroup "RgbEn" of register "Enable".
**
** RGB modus enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RgbEn" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_7")))
#endif

uint32_t FREG_VE_HD_GetEnable_RgbEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_ENABLE));
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
** \brief Reads the bitgroup "En" of register "Enable".
**
** Videoencoder enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "En" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_8")))
#endif

uint32_t FREG_VE_HD_GetEnable_En( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_ENABLE));
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
** \brief Writes the entire register "Ylevelshift".
**
** This function writes the given value to the register "Ylevelshift".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_9")))
#endif

void FREG_VE_HD_SetYlevelshift( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rsh" of register "Ylevelshift".
**
** Right shift (unsigned: max = 5)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rsh" consists of the bits 26..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x07000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_10")))
#endif

void FREG_VE_HD_SetYlevelshift_Rsh( uint32_t value )
{
    register uint32_t mask = 0x07000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mul" of register "Ylevelshift".
**
** Multiplier (unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mul" consists of the bits 22..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x007F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_11")))
#endif

void FREG_VE_HD_SetYlevelshift_Mul( uint32_t value )
{
    register uint32_t mask = 0x007F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ofs" of register "Ylevelshift".
**
** Offset (signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ofs" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_12")))
#endif

void FREG_VE_HD_SetYlevelshift_Ofs( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ylevelshift".
**
** This function reads the value from the register "Ylevelshift".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_13")))
#endif

uint32_t FREG_VE_HD_GetYlevelshift( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT));
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
** \brief Reads the bitgroup "Rsh" of register "Ylevelshift".
**
** Right shift (unsigned: max = 5)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rsh" consists of the bits 26..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x07000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_14")))
#endif

uint32_t FREG_VE_HD_GetYlevelshift_Rsh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT));
    value = ( value & 0x07000000UL ) >> 24;
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
** \brief Reads the bitgroup "Mul" of register "Ylevelshift".
**
** Multiplier (unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mul" consists of the bits 22..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x007F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_15")))
#endif

uint32_t FREG_VE_HD_GetYlevelshift_Mul( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT));
    value = ( value & 0x007F0000UL ) >> 16;
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
** \brief Reads the bitgroup "Ofs" of register "Ylevelshift".
**
** Offset (signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ofs" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_16")))
#endif

uint32_t FREG_VE_HD_GetYlevelshift_Ofs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELSHIFT));
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
** \brief Writes the entire register "Crlevelshift".
**
** This function writes the given value to the register "Crlevelshift".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_17")))
#endif

void FREG_VE_HD_SetCrlevelshift( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CRLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rsh" of register "Crlevelshift".
**
** Right shift (unsigned: max = 5)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rsh" consists of the bits 26..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x07000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_18")))
#endif

void FREG_VE_HD_SetCrlevelshift_Rsh( uint32_t value )
{
    register uint32_t mask = 0x07000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CRLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mul" of register "Crlevelshift".
**
** Multiplier (unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mul" consists of the bits 22..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x007F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_19")))
#endif

void FREG_VE_HD_SetCrlevelshift_Mul( uint32_t value )
{
    register uint32_t mask = 0x007F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CRLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ofs" of register "Crlevelshift".
**
** Offset (signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ofs" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_20")))
#endif

void FREG_VE_HD_SetCrlevelshift_Ofs( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CRLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Crlevelshift".
**
** This function reads the value from the register "Crlevelshift".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_21")))
#endif

uint32_t FREG_VE_HD_GetCrlevelshift( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT));
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
** \brief Reads the bitgroup "Rsh" of register "Crlevelshift".
**
** Right shift (unsigned: max = 5)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rsh" consists of the bits 26..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x07000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_22")))
#endif

uint32_t FREG_VE_HD_GetCrlevelshift_Rsh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT));
    value = ( value & 0x07000000UL ) >> 24;
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
** \brief Reads the bitgroup "Mul" of register "Crlevelshift".
**
** Multiplier (unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mul" consists of the bits 22..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x007F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_23")))
#endif

uint32_t FREG_VE_HD_GetCrlevelshift_Mul( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT));
    value = ( value & 0x007F0000UL ) >> 16;
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
** \brief Reads the bitgroup "Ofs" of register "Crlevelshift".
**
** Offset (signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ofs" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_24")))
#endif

uint32_t FREG_VE_HD_GetCrlevelshift_Ofs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CRLEVELSHIFT));
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
** \brief Writes the entire register "Cblevelshift".
**
** This function writes the given value to the register "Cblevelshift".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_25")))
#endif

void FREG_VE_HD_SetCblevelshift( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CBLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rsh" of register "Cblevelshift".
**
** Right shift (unsigned: max = 5)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rsh" consists of the bits 26..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x07000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_26")))
#endif

void FREG_VE_HD_SetCblevelshift_Rsh( uint32_t value )
{
    register uint32_t mask = 0x07000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CBLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mul" of register "Cblevelshift".
**
** Multiplier (unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mul" consists of the bits 22..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x007F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_27")))
#endif

void FREG_VE_HD_SetCblevelshift_Mul( uint32_t value )
{
    register uint32_t mask = 0x007F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CBLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ofs" of register "Cblevelshift".
**
** Offset (signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ofs" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_28")))
#endif

void FREG_VE_HD_SetCblevelshift_Ofs( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_CBLEVELSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Cblevelshift".
**
** This function reads the value from the register "Cblevelshift".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_29")))
#endif

uint32_t FREG_VE_HD_GetCblevelshift( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT));
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
** \brief Reads the bitgroup "Rsh" of register "Cblevelshift".
**
** Right shift (unsigned: max = 5)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rsh" consists of the bits 26..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x07000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_30")))
#endif

uint32_t FREG_VE_HD_GetCblevelshift_Rsh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT));
    value = ( value & 0x07000000UL ) >> 24;
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
** \brief Reads the bitgroup "Mul" of register "Cblevelshift".
**
** Multiplier (unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mul" consists of the bits 22..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x007F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_31")))
#endif

uint32_t FREG_VE_HD_GetCblevelshift_Mul( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT));
    value = ( value & 0x007F0000UL ) >> 16;
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
** \brief Reads the bitgroup "Ofs" of register "Cblevelshift".
**
** Offset (signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ofs" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_32")))
#endif

uint32_t FREG_VE_HD_GetCblevelshift_Ofs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_CBLEVELSHIFT));
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
** \brief Writes the entire register "VindexCnt".
**
** This function writes the given value to the register "VindexCnt".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_33")))
#endif

void FREG_VE_HD_SetVindexCnt( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VINDEXCNT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hsync" of register "VindexCnt".
**
** Used set for horizontal sync generation on Cr/Cb
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsync" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_34")))
#endif

void FREG_VE_HD_SetVindexCnt_Hsync( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VINDEXCNT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Max" of register "VindexCnt".
**
** Maximum of used level sets
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Max" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_35")))
#endif

void FREG_VE_HD_SetVindexCnt_Max( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VINDEXCNT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "VindexCnt".
**
** This function reads the value from the register "VindexCnt".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_36")))
#endif

uint32_t FREG_VE_HD_GetVindexCnt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT));
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
** \brief Reads the bitgroup "Hsync" of register "VindexCnt".
**
** Used set for horizontal sync generation on Cr/Cb
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsync" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_37")))
#endif

uint32_t FREG_VE_HD_GetVindexCnt_Hsync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT));
    value = ( value & 0x000000F0UL ) >> 4;
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
** \brief Reads the bitgroup "Max" of register "VindexCnt".
**
** Maximum of used level sets
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Max" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_38")))
#endif

uint32_t FREG_VE_HD_GetVindexCnt_Max( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VINDEXCNT));
    value = ( value & 0x0000000FUL ) >> 0;
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
** \brief Writes the entire register "Levels".
**
** This function writes the given value to the register "Levels".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_39")))
#endif

void FREG_VE_HD_SetLevels( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_LEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Lev2" of register "Levels".
**
** Level 2 for sync generation of chrominances
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Lev2" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_40")))
#endif

void FREG_VE_HD_SetLevels_Lev2( uint32_t value )
{
    register uint32_t mask = 0x3FF00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_LEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Lev1" of register "Levels".
**
** Level 1 for sync generation of chrominances
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Lev1" consists of the bits 19..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x000FFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_41")))
#endif

void FREG_VE_HD_SetLevels_Lev1( uint32_t value )
{
    register uint32_t mask = 0x000FFC00UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_LEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Lev0" of register "Levels".
**
** Level 0 for sync generation of chrominances
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Lev0" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_42")))
#endif

void FREG_VE_HD_SetLevels_Lev0( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_LEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_LEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Levels".
**
** This function reads the value from the register "Levels".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_43")))
#endif

uint32_t FREG_VE_HD_GetLevels( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_LEVELS));
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
** \brief Reads the bitgroup "Lev2" of register "Levels".
**
** Level 2 for sync generation of chrominances
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Lev2" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_44")))
#endif

uint32_t FREG_VE_HD_GetLevels_Lev2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_LEVELS));
    value = ( value & 0x3FF00000UL ) >> 20;
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
** \brief Reads the bitgroup "Lev1" of register "Levels".
**
** Level 1 for sync generation of chrominances
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Lev1" consists of the bits 19..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x000FFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_45")))
#endif

uint32_t FREG_VE_HD_GetLevels_Lev1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_LEVELS));
    value = ( value & 0x000FFC00UL ) >> 10;
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
** \brief Reads the bitgroup "Lev0" of register "Levels".
**
** Level 0 for sync generation of chrominances
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Lev0" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_46")))
#endif

uint32_t FREG_VE_HD_GetLevels_Lev0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_LEVELS));
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
** \brief Writes the entire register "Filter".
**
** This function writes the given value to the register "Filter".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_47")))
#endif

void FREG_VE_HD_SetFilter( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_FILTER, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_FILTER)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mode" of register "Filter".
**
** horizontal filter mode
** 0: no filter
** 1: 2-tap filter
** 2: 4-tap filter
** 5: 2-tap filter only on sync
** 6: 4-tap filter only on sync
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mode" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_48")))
#endif

void FREG_VE_HD_SetFilter_Mode( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_FILTER)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_FILTER, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_FILTER)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Filter".
**
** This function reads the value from the register "Filter".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_49")))
#endif

uint32_t FREG_VE_HD_GetFilter( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_FILTER));
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
** \brief Reads the bitgroup "Mode" of register "Filter".
**
** horizontal filter mode
** 0: no filter
** 1: 2-tap filter
** 2: 4-tap filter
** 5: 2-tap filter only on sync
** 6: 4-tap filter only on sync
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mode" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_50")))
#endif

uint32_t FREG_VE_HD_GetFilter_Mode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_FILTER));
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
** \brief Writes the entire register "Ylevels".
**
** This function writes the given value to the register "Ylevels".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_51")))
#endif

void FREG_VE_HD_SetYlevels( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Lev2" of register "Ylevels".
**
** Level 2 for sync generation of luminance or RGB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Lev2" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_52")))
#endif

void FREG_VE_HD_SetYlevels_Lev2( uint32_t value )
{
    register uint32_t mask = 0x3FF00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Lev1" of register "Ylevels".
**
** Level 1 for sync generation of luminance or RGB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Lev1" consists of the bits 19..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x000FFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_53")))
#endif

void FREG_VE_HD_SetYlevels_Lev1( uint32_t value )
{
    register uint32_t mask = 0x000FFC00UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Lev0" of register "Ylevels".
**
** Level 0 for sync generation of luminance or RGB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Lev0" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_54")))
#endif

void FREG_VE_HD_SetYlevels_Lev0( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YLEVELS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YLEVELS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ylevels".
**
** This function reads the value from the register "Ylevels".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_55")))
#endif

uint32_t FREG_VE_HD_GetYlevels( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELS));
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
** \brief Reads the bitgroup "Lev2" of register "Ylevels".
**
** Level 2 for sync generation of luminance or RGB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Lev2" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_56")))
#endif

uint32_t FREG_VE_HD_GetYlevels_Lev2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELS));
    value = ( value & 0x3FF00000UL ) >> 20;
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
** \brief Reads the bitgroup "Lev1" of register "Ylevels".
**
** Level 1 for sync generation of luminance or RGB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Lev1" consists of the bits 19..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x000FFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_57")))
#endif

uint32_t FREG_VE_HD_GetYlevels_Lev1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELS));
    value = ( value & 0x000FFC00UL ) >> 10;
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
** \brief Reads the bitgroup "Lev0" of register "Ylevels".
**
** Level 0 for sync generation of luminance or RGB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Lev0" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_58")))
#endif

uint32_t FREG_VE_HD_GetYlevels_Lev0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_YLEVELS));
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
** \brief Writes the entire register "Videolinesel_0".
**
** This function writes the given value to the register "Videolinesel_0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_59")))
#endif

void FREG_VE_HD_SetVideolinesel_0( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VIDEOLINESEL_0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Start" of register "Videolinesel_0".
**
** Vertival active video start position (setting 1)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_60")))
#endif

void FREG_VE_HD_SetVideolinesel_0_Start( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VIDEOLINESEL_0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "End" of register "Videolinesel_0".
**
** Vertival active video end position (setting 1)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "End" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_61")))
#endif

void FREG_VE_HD_SetVideolinesel_0_End( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VIDEOLINESEL_0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Videolinesel_0".
**
** This function reads the value from the register "Videolinesel_0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_62")))
#endif

uint32_t FREG_VE_HD_GetVideolinesel_0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0));
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
** \brief Reads the bitgroup "Start" of register "Videolinesel_0".
**
** Vertival active video start position (setting 1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_63")))
#endif

uint32_t FREG_VE_HD_GetVideolinesel_0_Start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0));
    value = ( value & 0x0FFF0000UL ) >> 16;
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
** \brief Reads the bitgroup "End" of register "Videolinesel_0".
**
** Vertival active video end position (setting 1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "End" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_64")))
#endif

uint32_t FREG_VE_HD_GetVideolinesel_0_End( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_0));
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
** \brief Writes the entire register "Videolinesel_1".
**
** This function writes the given value to the register "Videolinesel_1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_65")))
#endif

void FREG_VE_HD_SetVideolinesel_1( uint32_t value )
{
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VIDEOLINESEL_1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Start" of register "Videolinesel_1".
**
** Vertival active video start position (setting 2)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_66")))
#endif

void FREG_VE_HD_SetVideolinesel_1_Start( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VIDEOLINESEL_1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "End" of register "Videolinesel_1".
**
** Vertival active video end position (setting 2)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "End" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_67")))
#endif

void FREG_VE_HD_SetVideolinesel_1_End( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VIDEOLINESEL_1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Videolinesel_1".
**
** This function reads the value from the register "Videolinesel_1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_68")))
#endif

uint32_t FREG_VE_HD_GetVideolinesel_1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1));
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
** \brief Reads the bitgroup "Start" of register "Videolinesel_1".
**
** Vertival active video start position (setting 2)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_69")))
#endif

uint32_t FREG_VE_HD_GetVideolinesel_1_Start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1));
    value = ( value & 0x0FFF0000UL ) >> 16;
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
** \brief Reads the bitgroup "End" of register "Videolinesel_1".
**
** Vertival active video end position (setting 2)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "End" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_70")))
#endif

uint32_t FREG_VE_HD_GetVideolinesel_1_End( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VE_HD_VIDEOLINESEL_1));
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
** \brief Writes the entire register "Hlevcnt_0".
**
** This function writes the given value to the index-th entry of the register
** array Hlevcnt_0.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_71")))
#endif

void FREG_VE_HD_SetHlevcnt_0( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_0+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Level" of register "Hlevcnt_0".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_72")))
#endif

void FREG_VE_HD_SetHlevcnt_0_Level( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_0+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Count" of register "Hlevcnt_0".
**
** Horizontal pixel count for level 0 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_73")))
#endif

void FREG_VE_HD_SetHlevcnt_0_Count( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_0+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Hlevcnt_0".
**
** This function reads the value from the index-th entry of the register
** array Hlevcnt_0.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_74")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20)));
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
** \brief Reads the bitgroup "Level" of register "Hlevcnt_0".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_75")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_0_Level( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20)));
    value = ( value & 0x00003000UL ) >> 12;
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
** \brief Reads the bitgroup "Count" of register "Hlevcnt_0".
**
** Horizontal pixel count for level 0 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_76")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_0_Count( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_0+(index*0x20)));
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
** \brief Writes the entire register "Hlevcnt_1".
**
** This function writes the given value to the index-th entry of the register
** array Hlevcnt_1.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_77"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_77" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_77")))
#endif

void FREG_VE_HD_SetHlevcnt_1( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_1+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Level" of register "Hlevcnt_1".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_78"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_78" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_78")))
#endif

void FREG_VE_HD_SetHlevcnt_1_Level( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_1+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Count" of register "Hlevcnt_1".
**
** Horizontal pixel count for level 1 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_79"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_79" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_79")))
#endif

void FREG_VE_HD_SetHlevcnt_1_Count( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_1+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Hlevcnt_1".
**
** This function reads the value from the index-th entry of the register
** array Hlevcnt_1.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_80"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_80" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_80")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20)));
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
** \brief Reads the bitgroup "Level" of register "Hlevcnt_1".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_81"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_81" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_81")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_1_Level( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20)));
    value = ( value & 0x00003000UL ) >> 12;
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
** \brief Reads the bitgroup "Count" of register "Hlevcnt_1".
**
** Horizontal pixel count for level 1 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_82"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_82" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_82")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_1_Count( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_1+(index*0x20)));
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
** \brief Writes the entire register "Hlevcnt_2".
**
** This function writes the given value to the index-th entry of the register
** array Hlevcnt_2.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_83"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_83" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_83")))
#endif

void FREG_VE_HD_SetHlevcnt_2( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_2+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Level" of register "Hlevcnt_2".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_84"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_84" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_84")))
#endif

void FREG_VE_HD_SetHlevcnt_2_Level( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_2+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Count" of register "Hlevcnt_2".
**
** Horizontal pixel count for level 2 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_85"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_85" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_85")))
#endif

void FREG_VE_HD_SetHlevcnt_2_Count( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_2+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Hlevcnt_2".
**
** This function reads the value from the index-th entry of the register
** array Hlevcnt_2.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_86"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_86" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_86")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_2( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20)));
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
** \brief Reads the bitgroup "Level" of register "Hlevcnt_2".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_87"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_87" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_87")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_2_Level( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20)));
    value = ( value & 0x00003000UL ) >> 12;
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
** \brief Reads the bitgroup "Count" of register "Hlevcnt_2".
**
** Horizontal pixel count for level 2 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_88"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_88" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_88")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_2_Count( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_2+(index*0x20)));
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
** \brief Writes the entire register "Hlevcnt_3".
**
** This function writes the given value to the index-th entry of the register
** array Hlevcnt_3.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_89"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_89" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_89")))
#endif

void FREG_VE_HD_SetHlevcnt_3( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_3+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Level" of register "Hlevcnt_3".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_90"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_90" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_90")))
#endif

void FREG_VE_HD_SetHlevcnt_3_Level( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_3+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Count" of register "Hlevcnt_3".
**
** Horizontal pixel count for level 3 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_91"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_91" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_91")))
#endif

void FREG_VE_HD_SetHlevcnt_3_Count( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_3+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Hlevcnt_3".
**
** This function reads the value from the index-th entry of the register
** array Hlevcnt_3.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_92"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_92" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_92")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_3( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20)));
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
** \brief Reads the bitgroup "Level" of register "Hlevcnt_3".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_93"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_93" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_93")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_3_Level( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20)));
    value = ( value & 0x00003000UL ) >> 12;
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
** \brief Reads the bitgroup "Count" of register "Hlevcnt_3".
**
** Horizontal pixel count for level 3 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_94"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_94" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_94")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_3_Count( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_3+(index*0x20)));
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
** \brief Writes the entire register "Hlevcnt_4".
**
** This function writes the given value to the index-th entry of the register
** array Hlevcnt_4.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_95"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_95" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_95")))
#endif

void FREG_VE_HD_SetHlevcnt_4( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_4+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Level" of register "Hlevcnt_4".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_96"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_96" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_96")))
#endif

void FREG_VE_HD_SetHlevcnt_4_Level( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_4+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Count" of register "Hlevcnt_4".
**
** Horizontal pixel count for level 4 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_97"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_97" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_97")))
#endif

void FREG_VE_HD_SetHlevcnt_4_Count( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HLEVCNT_4+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Hlevcnt_4".
**
** This function reads the value from the index-th entry of the register
** array Hlevcnt_4.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_98"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_98" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_98")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_4( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20)));
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
** \brief Reads the bitgroup "Level" of register "Hlevcnt_4".
**
** Level index defined in register VE_HD_YLEVELS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Level" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_99"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_99" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_99")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_4_Level( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20)));
    value = ( value & 0x00003000UL ) >> 12;
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
** \brief Reads the bitgroup "Count" of register "Hlevcnt_4".
**
** Horizontal pixel count for level 4 (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Count" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_100"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_100" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_100")))
#endif

uint32_t FREG_VE_HD_GetHlevcnt_4_Count( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HLEVCNT_4+(index*0x20)));
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
** \brief Writes the entire register "HindexCnt".
**
** This function writes the given value to the index-th entry of the register
** array HindexCnt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_101"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_101" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_101")))
#endif

void FREG_VE_HD_SetHindexCnt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HINDEXCNT+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HINDEXCNT+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Max" of register "HindexCnt".
**
** Used horizontal levels (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Max" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_102"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_102" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_102")))
#endif

void FREG_VE_HD_SetHindexCnt_Max( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_HINDEXCNT+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_HINDEXCNT+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_HINDEXCNT+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "HindexCnt".
**
** This function reads the value from the index-th entry of the register
** array HindexCnt.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_103"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_103" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_103")))
#endif

uint32_t FREG_VE_HD_GetHindexCnt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HINDEXCNT+(index*0x20)));
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
** \brief Reads the bitgroup "Max" of register "HindexCnt".
**
** Used horizontal levels (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Max" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_104"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_104" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_104")))
#endif

uint32_t FREG_VE_HD_GetHindexCnt_Max( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_HINDEXCNT+(index*0x20)));
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
** \brief Writes the entire register "Vcnt".
**
** This function writes the given value to the index-th entry of the register
** array Vcnt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_105"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_105" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_105")))
#endif

void FREG_VE_HD_SetVcnt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VCNT+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VCNT+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Count" of register "Vcnt".
**
** Vertical count of level set (of max.
**  11 level sets)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Count" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_106"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_106" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_106")))
#endif

void FREG_VE_HD_SetVcnt_Count( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_VCNT+(index*0x20))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_VCNT+(index*0x20), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_VCNT+(index*0x20))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vcnt".
**
** This function reads the value from the index-th entry of the register
** array Vcnt.
**
** Vertical count of level set (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_107"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_107" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_107")))
#endif

uint32_t FREG_VE_HD_GetVcnt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_VCNT+(index*0x20)));
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
** \brief Reads the bitgroup "Count" of register "Vcnt".
**
** Vertical count of level set (of max.
**  11 level sets)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Count" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_108"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_108" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_108")))
#endif

uint32_t FREG_VE_HD_GetVcnt_Count( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 11 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_VCNT+(index*0x20)));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
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
** \brief Writes the entire register "Yuvrgb".
**
** This function writes the given value to the index-th entry of the register
** array Yuvrgb.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_109"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_109" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_109")))
#endif

void FREG_VE_HD_SetYuvrgb( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YUVRGB+(index*0x04), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YUVRGB+(index*0x04))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "Yuvrgb".
**
** 3x4 conversion matrix for e.
** g. RGB  (signed values)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_110"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_110" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_110")))
#endif

void FREG_VE_HD_SetYuvrgb_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_HD_YUVRGB+(index*0x04))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_HD_ENABLE_DEBUG_PRINT == 1
        FREG_VE_HD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE_HD", FREG_VE_HD_YUVRGB+(index*0x04), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_HD_YUVRGB+(index*0x04))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Yuvrgb".
**
** This function reads the value from the index-th entry of the register
** array Yuvrgb.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_111"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_111" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_111")))
#endif

uint32_t FREG_VE_HD_GetYuvrgb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_YUVRGB+(index*0x04)));
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
** \brief Reads the bitgroup "Data" of register "Yuvrgb".
**
** 3x4 conversion matrix for e.
** g. RGB  (signed values)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VE_HD_112"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VE_HD_112" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VE_HD_112")))
#endif

uint32_t FREG_VE_HD_GetYuvrgb_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_HD_YUVRGB+(index*0x04)));
    value = ( value & 0x000007FFUL ) >> 0;
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
** \brief Initializes the "VE_HD" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_VE_HD_Init( void )
{
}
