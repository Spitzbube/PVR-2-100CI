/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_upi.c
**
** \brief     UPI access functions
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
#define FREG_UPI_C

#include <stdint.h>
#include "reg_upi.h"

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
volatile uint32_t FREG_UPI_WaittimeMirror = 0;
volatile uint32_t FREG_UPI_WaittimeenMirror = 0;

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Addrext".
**
** This function writes the given value to the register "Addrext".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_1")))
#endif

void FREG_UPI_SetAddrext( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ADDREXT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ADDREXT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Addrext".
**
** This function reads the value from the register "Addrext".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_2")))
#endif

uint32_t FREG_UPI_GetAddrext( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ADDREXT));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Cssel".
**
** This function writes the given value to the register "Cssel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_3")))
#endif

void FREG_UPI_SetCssel( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSSEL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CsSel" of register "Cssel".
**
**  - '00': UPI_DEV0      -->  UPI_CS_N(0)
** UPI_DEV1      -->  UPI_CS_N(1)
** ATA_CS         -->  UPI_CS_N(2)
** 
** - '01':  UPI_DEV0/1  -->  UPI_CS_N(0)
** UPI_DEV2     -->  UPI_CS_N(1)
** ATA_CS        -->  UPI_CS_N(2)
** 
** - '10': UPI_DEV0/1/2 -->  UPI_CS_N(0)
** ATA_CS1        -->  UPI_CS_N(1)
** ATA_CS0        -->  UPI_CS_N(2)
** 
** - '11': UPI_DEV0       -->  UPI_CS_N(0)
** UPI_DEV1       -->  UPI_CS_N(1)
** UPI_DEV2       -->  UPI_CS_N(2)
** Note: ATA_CS corresponds to the hardware-wired: ATA_CS0 AND ATA_CS1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CsSel" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_4")))
#endif

void FREG_UPI_SetCssel_CsSel( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSSEL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Cssel".
**
** This function reads the value from the register "Cssel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_5")))
#endif

uint32_t FREG_UPI_GetCssel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSSEL));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CsSel" of register "Cssel".
**
**  - '00': UPI_DEV0      -->  UPI_CS_N(0)
** UPI_DEV1      -->  UPI_CS_N(1)
** ATA_CS         -->  UPI_CS_N(2)
** 
** - '01':  UPI_DEV0/1  -->  UPI_CS_N(0)
** UPI_DEV2     -->  UPI_CS_N(1)
** ATA_CS        -->  UPI_CS_N(2)
** 
** - '10': UPI_DEV0/1/2 -->  UPI_CS_N(0)
** ATA_CS1        -->  UPI_CS_N(1)
** ATA_CS0        -->  UPI_CS_N(2)
** 
** - '11': UPI_DEV0       -->  UPI_CS_N(0)
** UPI_DEV1       -->  UPI_CS_N(1)
** UPI_DEV2       -->  UPI_CS_N(2)
** Note: ATA_CS corresponds to the hardware-wired: ATA_CS0 AND ATA_CS1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CsSel" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_6")))
#endif

uint32_t FREG_UPI_GetCssel_CsSel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSSEL));
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
** \brief Writes the entire register "Csmode".
**
** This function writes the given value to the register "Csmode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_7")))
#endif

void FREG_UPI_SetCsmode( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs2Wemode" of register "Csmode".
**
** - '0': UPI_DEV2 chip select in standard mode
** - '1': UPI_DEV2 chip select follows UPI_WE_N signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs2Wemode" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_8")))
#endif

void FREG_UPI_SetCsmode_Cs2Wemode( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs1Wemode" of register "Csmode".
**
** - '0': UPI_DEV1 chip select in standard mode
** - '1': UPI_DEV1 chip select follows UPI_WE_N signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs1Wemode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_9")))
#endif

void FREG_UPI_SetCsmode_Cs1Wemode( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs2Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV2 chip select
** - '1': Invert UPI_DEV2 chip select when CS2_WEMODE='1'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs2Invert" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_10")))
#endif

void FREG_UPI_SetCsmode_Cs2Invert( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs1Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV1 chip select
** - '1': Invert UPI_DEV1 chip select when CS1_WEMODE='1'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs1Invert" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_11")))
#endif

void FREG_UPI_SetCsmode_Cs1Invert( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Csmode".
**
** This function reads the value from the register "Csmode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_12")))
#endif

uint32_t FREG_UPI_GetCsmode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cs2Wemode" of register "Csmode".
**
** - '0': UPI_DEV2 chip select in standard mode
** - '1': UPI_DEV2 chip select follows UPI_WE_N signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs2Wemode" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_13")))
#endif

uint32_t FREG_UPI_GetCsmode_Cs2Wemode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
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
** \brief Reads the bitgroup "Cs1Wemode" of register "Csmode".
**
** - '0': UPI_DEV1 chip select in standard mode
** - '1': UPI_DEV1 chip select follows UPI_WE_N signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs1Wemode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_14")))
#endif

uint32_t FREG_UPI_GetCsmode_Cs1Wemode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
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
** \brief Reads the bitgroup "Cs2Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV2 chip select
** - '1': Invert UPI_DEV2 chip select when CS2_WEMODE='1'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs2Invert" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_15")))
#endif

uint32_t FREG_UPI_GetCsmode_Cs2Invert( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
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
** \brief Reads the bitgroup "Cs1Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV1 chip select
** - '1': Invert UPI_DEV1 chip select when CS1_WEMODE='1'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs1Invert" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_16")))
#endif

uint32_t FREG_UPI_GetCsmode_Cs1Invert( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
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
** \brief Writes the entire register "Waittime".
**
** This function writes the given value to the register "Waittime".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_17")))
#endif

void FREG_UPI_SetWaittime( uint32_t value )
{
    FREG_UPI_WaittimeMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIME, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIME)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WaitTime" of register "Waittime".
**
** Wait Timer, in multiple of 1024 162MHz cycles
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WaitTime" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_18")))
#endif

void FREG_UPI_SetWaittime_WaitTime( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_UPI_WaittimeMirror & ~mask;
    FREG_UPI_WaittimeMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIME, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIME)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Waittime".
**
** This function reads the value from the register "Waittime".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_19")))
#endif

uint32_t FREG_UPI_GetmWaittime( void )
{
    register uint32_t value = FREG_UPI_WaittimeMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitTime" of register "Waittime".
**
** Wait Timer, in multiple of 1024 162MHz cycles
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitTime" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_20")))
#endif

uint32_t FREG_UPI_GetmWaittime_WaitTime( void )
{
    register uint32_t value = FREG_UPI_WaittimeMirror;
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
** \brief Writes the entire register "Waittimeen".
**
** This function writes the given value to the register "Waittimeen".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_21")))
#endif

void FREG_UPI_SetWaittimeen( uint32_t value )
{
    FREG_UPI_WaittimeenMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIMEEN, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIMEEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WaitTimeEn" of register "Waittimeen".
**
** Enables Wait Timer
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WaitTimeEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_22")))
#endif

void FREG_UPI_SetWaittimeen_WaitTimeEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_UPI_WaittimeenMirror & ~mask;
    FREG_UPI_WaittimeenMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIMEEN, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIMEEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Waittimeen".
**
** This function reads the value from the register "Waittimeen".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_23")))
#endif

uint32_t FREG_UPI_GetmWaittimeen( void )
{
    register uint32_t value = FREG_UPI_WaittimeenMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitTimeEn" of register "Waittimeen".
**
** Enables Wait Timer
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitTimeEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_24")))
#endif

uint32_t FREG_UPI_GetmWaittimeen_WaitTimeEn( void )
{
    register uint32_t value = FREG_UPI_WaittimeenMirror;
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
** \brief Reads the entire register "Lastwaittime".
**
** This function reads the value from the register "Lastwaittime".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_25")))
#endif

uint32_t FREG_UPI_GetLastwaittime( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_LASTWAITTIME));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LastWaitTime" of register "Lastwaittime".
**
** Last Wait Time, in multiple of 1024 162MHz cycles
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LastWaitTime" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_26")))
#endif

uint32_t FREG_UPI_GetLastwaittime_LastWaitTime( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_LASTWAITTIME));
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
** \brief Reads the entire register "Waittimestatus".
**
** This function reads the value from the register "Waittimestatus".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_27")))
#endif

uint32_t FREG_UPI_GetWaittimestatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_WAITTIMESTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitLineStatus" of register "Waittimestatus".
**
** Wait Line Status
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitLineStatus" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_28")))
#endif

uint32_t FREG_UPI_GetWaittimestatus_WaitLineStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_WAITTIMESTATUS));
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
** \brief Reads the bitgroup "WaitTimeAct" of register "Waittimestatus".
**
** Wait Timer activated
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitTimeAct" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_29")))
#endif

uint32_t FREG_UPI_GetWaittimestatus_WaitTimeAct( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_WAITTIMESTATUS));
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
** \brief Writes the entire register "Atactrl".
**
** This function writes the given value to the register "Atactrl".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_30")))
#endif

void FREG_UPI_SetAtactrl( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Timeoutcnt" of register "Atactrl".
**
** Timeout counter setting
** - '0'  : timeout counter disabled
** - '>0': timeout counter enabled
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Timeoutcnt" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_31")))
#endif

void FREG_UPI_SetAtactrl_Timeoutcnt( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmaba" of register "Atactrl".
**
** Multiword DMA buffer access (FIFO access)
** - '0': External DMA engine controls buffer access
** - '1': Buffer access via register DTxDB, DRxDB enabled
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmaba" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_32")))
#endif

void FREG_UPI_SetAtactrl_Dmaba( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmaen" of register "Atactrl".
**
** Multiword DMA enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmaen" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_33")))
#endif

void FREG_UPI_SetAtactrl_Dmaen( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmadir" of register "Atactrl".
**
** Multiword DMA direction
** - '1': write to HD
** - '0': read from HD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmadir" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_34")))
#endif

void FREG_UPI_SetAtactrl_Dmadir( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Belec1" of register "Atactrl".
**
** Big Endian Little Endian conversion device 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Belec1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_35")))
#endif

void FREG_UPI_SetAtactrl_Belec1( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Belec0" of register "Atactrl".
**
** Big Endian Little Endian conversion device 0
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Belec0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_36")))
#endif

void FREG_UPI_SetAtactrl_Belec0( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ideen" of register "Atactrl".
**
** IDE Enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ideen" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_37")))
#endif

void FREG_UPI_SetAtactrl_Ideen( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fte1" of register "Atactrl".
**
** Fast Timing device1 enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fte1" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_38")))
#endif

void FREG_UPI_SetAtactrl_Fte1( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fte0" of register "Atactrl".
**
** Fast Timing device0 enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fte0" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_39")))
#endif

void FREG_UPI_SetAtactrl_Fte0( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pwpp" of register "Atactrl".
**
** PIO write Ping-Pong enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pwpp" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_40")))
#endif

void FREG_UPI_SetAtactrl_Pwpp( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IordyenFt1" of register "Atactrl".
**
** Fast Timing device1 IORDY enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IordyenFt1" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_41")))
#endif

void FREG_UPI_SetAtactrl_IordyenFt1( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IordyenFt0" of register "Atactrl".
**
** Fast Timing device0 IORDY enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IordyenFt0" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_42")))
#endif

void FREG_UPI_SetAtactrl_IordyenFt0( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IordyenCt" of register "Atactrl".
**
** Compatible timing IORDY enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IordyenCt" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_43")))
#endif

void FREG_UPI_SetAtactrl_IordyenCt( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AtaBufEn" of register "Atactrl".
**
** Activates BUF_EN in ATA Mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AtaBufEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_44")))
#endif

void FREG_UPI_SetAtactrl_AtaBufEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atactrl".
**
** This function reads the value from the register "Atactrl".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_45")))
#endif

uint32_t FREG_UPI_GetAtactrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Timeoutcnt" of register "Atactrl".
**
** Timeout counter setting
** - '0'  : timeout counter disabled
** - '>0': timeout counter enabled
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Timeoutcnt" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_46")))
#endif

uint32_t FREG_UPI_GetAtactrl_Timeoutcnt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Dmaba" of register "Atactrl".
**
** Multiword DMA buffer access (FIFO access)
** - '0': External DMA engine controls buffer access
** - '1': Buffer access via register DTxDB, DRxDB enabled
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmaba" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_47")))
#endif

uint32_t FREG_UPI_GetAtactrl_Dmaba( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Dmaen" of register "Atactrl".
**
** Multiword DMA enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmaen" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_48")))
#endif

uint32_t FREG_UPI_GetAtactrl_Dmaen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Dmadir" of register "Atactrl".
**
** Multiword DMA direction
** - '1': write to HD
** - '0': read from HD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmadir" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_49")))
#endif

uint32_t FREG_UPI_GetAtactrl_Dmadir( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Belec1" of register "Atactrl".
**
** Big Endian Little Endian conversion device 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Belec1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_50")))
#endif

uint32_t FREG_UPI_GetAtactrl_Belec1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Belec0" of register "Atactrl".
**
** Big Endian Little Endian conversion device 0
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Belec0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_51")))
#endif

uint32_t FREG_UPI_GetAtactrl_Belec0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Ideen" of register "Atactrl".
**
** IDE Enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ideen" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_52")))
#endif

uint32_t FREG_UPI_GetAtactrl_Ideen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Fte1" of register "Atactrl".
**
** Fast Timing device1 enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fte1" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_53")))
#endif

uint32_t FREG_UPI_GetAtactrl_Fte1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Fte0" of register "Atactrl".
**
** Fast Timing device0 enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fte0" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_54")))
#endif

uint32_t FREG_UPI_GetAtactrl_Fte0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "Pwpp" of register "Atactrl".
**
** PIO write Ping-Pong enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pwpp" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_55")))
#endif

uint32_t FREG_UPI_GetAtactrl_Pwpp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "IordyenFt1" of register "Atactrl".
**
** Fast Timing device1 IORDY enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IordyenFt1" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_56")))
#endif

uint32_t FREG_UPI_GetAtactrl_IordyenFt1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "IordyenFt0" of register "Atactrl".
**
** Fast Timing device0 IORDY enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IordyenFt0" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_57")))
#endif

uint32_t FREG_UPI_GetAtactrl_IordyenFt0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "IordyenCt" of register "Atactrl".
**
** Compatible timing IORDY enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IordyenCt" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_58")))
#endif

uint32_t FREG_UPI_GetAtactrl_IordyenCt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Reads the bitgroup "AtaBufEn" of register "Atactrl".
**
** Activates BUF_EN in ATA Mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AtaBufEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_59")))
#endif

uint32_t FREG_UPI_GetAtactrl_AtaBufEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
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
** \brief Writes the entire register "Atastat".
**
** This function writes the given value to the register "Atastat".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_60")))
#endif

void FREG_UPI_SetAtastat( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmafifof" of register "Atastat".
**
** DMA fifo free lines
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmafifof" consists of the bits 23..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00F00000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_61")))
#endif

void FREG_UPI_SetAtastat_Dmafifof( uint32_t value )
{
    register uint32_t mask = 0x00F00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmafifou" of register "Atastat".
**
** DMA fifo used lines
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmafifou" consists of the bits 19..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x000F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_62")))
#endif

void FREG_UPI_SetAtastat_Dmafifou( uint32_t value )
{
    register uint32_t mask = 0x000F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmatip" of register "Atastat".
**
** DMA transfer in progress
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmatip" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_63")))
#endif

void FREG_UPI_SetAtastat_Dmatip( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmabe" of register "Atastat".
**
** DMA buffer empty
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmabe" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_64")))
#endif

void FREG_UPI_SetAtastat_Dmabe( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmabf" of register "Atastat".
**
** DMA buffer full
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmabf" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_65")))
#endif

void FREG_UPI_SetAtastat_Dmabf( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmarq" of register "Atastat".
**
** DMARQ line status
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmarq" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_66")))
#endif

void FREG_UPI_SetAtastat_Dmarq( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Piotip" of register "Atastat".
**
** Programmed IO transfer in progress
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Piotip" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_67")))
#endif

void FREG_UPI_SetAtastat_Piotip( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pwppf" of register "Atastat".
**
** PIO write Ping-Pong full
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pwppf" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_68")))
#endif

void FREG_UPI_SetAtastat_Pwppf( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Timeout" of register "Atastat".
**
** Timeout flag, cleared by writing '0'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Timeout" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_69")))
#endif

void FREG_UPI_SetAtastat_Timeout( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atastat".
**
** This function reads the value from the register "Atastat".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_70")))
#endif

uint32_t FREG_UPI_GetAtastat( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmafifof" of register "Atastat".
**
** DMA fifo free lines
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmafifof" consists of the bits 23..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00F00000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_71")))
#endif

uint32_t FREG_UPI_GetAtastat_Dmafifof( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00F00000UL ) >> 20;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmafifou" of register "Atastat".
**
** DMA fifo used lines
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmafifou" consists of the bits 19..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x000F0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_72")))
#endif

uint32_t FREG_UPI_GetAtastat_Dmafifou( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x000F0000UL ) >> 16;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmatip" of register "Atastat".
**
** DMA transfer in progress
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmatip" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_73")))
#endif

uint32_t FREG_UPI_GetAtastat_Dmatip( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Reads the bitgroup "Dmabe" of register "Atastat".
**
** DMA buffer empty
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmabe" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_74")))
#endif

uint32_t FREG_UPI_GetAtastat_Dmabe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Reads the bitgroup "Dmabf" of register "Atastat".
**
** DMA buffer full
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmabf" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_75")))
#endif

uint32_t FREG_UPI_GetAtastat_Dmabf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Reads the bitgroup "Dmarq" of register "Atastat".
**
** DMARQ line status
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmarq" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_76")))
#endif

uint32_t FREG_UPI_GetAtastat_Dmarq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Reads the bitgroup "Piotip" of register "Atastat".
**
** Programmed IO transfer in progress
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Piotip" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_77"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_77" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_77")))
#endif

uint32_t FREG_UPI_GetAtastat_Piotip( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Reads the bitgroup "Pwppf" of register "Atastat".
**
** PIO write Ping-Pong full
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pwppf" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_78"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_78" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_78")))
#endif

uint32_t FREG_UPI_GetAtastat_Pwppf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Reads the bitgroup "Timeout" of register "Atastat".
**
** Timeout flag, cleared by writing '0'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Timeout" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_79"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_79" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_79")))
#endif

uint32_t FREG_UPI_GetAtastat_Timeout( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
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
** \brief Writes the entire register "Atapctr".
**
** This function writes the given value to the register "Atapctr".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_80"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_80" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_80")))
#endif

void FREG_UPI_SetAtapctr( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atapctr".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_81"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_81" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_81")))
#endif

void FREG_UPI_SetAtapctr_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T4" of register "Atapctr".
**
** DIOW-data hold
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_82"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_82" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_82")))
#endif

void FREG_UPI_SetAtapctr_T4( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T2" of register "Atapctr".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_83"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_83" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_83")))
#endif

void FREG_UPI_SetAtapctr_T2( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T1" of register "Atapctr".
**
** Address valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_84"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_84" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_84")))
#endif

void FREG_UPI_SetAtapctr_T1( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atapctr".
**
** This function reads the value from the register "Atapctr".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_85"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_85" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_85")))
#endif

uint32_t FREG_UPI_GetAtapctr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atapctr".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_86"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_86" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_86")))
#endif

uint32_t FREG_UPI_GetAtapctr_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
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
** \brief Reads the bitgroup "T4" of register "Atapctr".
**
** DIOW-data hold
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_87"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_87" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_87")))
#endif

uint32_t FREG_UPI_GetAtapctr_T4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
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
** \brief Reads the bitgroup "T2" of register "Atapctr".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_88"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_88" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_88")))
#endif

uint32_t FREG_UPI_GetAtapctr_T2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
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
** \brief Reads the bitgroup "T1" of register "Atapctr".
**
** Address valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_89"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_89" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_89")))
#endif

uint32_t FREG_UPI_GetAtapctr_T1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
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
** \brief Writes the entire register "Atapftr0".
**
** This function writes the given value to the register "Atapftr0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_90"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_90" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_90")))
#endif

void FREG_UPI_SetAtapftr0( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atapftr0".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_91"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_91" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_91")))
#endif

void FREG_UPI_SetAtapftr0_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T4" of register "Atapftr0".
**
** DIOW-data hold
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_92"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_92" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_92")))
#endif

void FREG_UPI_SetAtapftr0_T4( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T2" of register "Atapftr0".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_93"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_93" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_93")))
#endif

void FREG_UPI_SetAtapftr0_T2( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T1" of register "Atapftr0".
**
** Address valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_94"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_94" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_94")))
#endif

void FREG_UPI_SetAtapftr0_T1( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atapftr0".
**
** This function reads the value from the register "Atapftr0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_95"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_95" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_95")))
#endif

uint32_t FREG_UPI_GetAtapftr0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atapftr0".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_96"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_96" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_96")))
#endif

uint32_t FREG_UPI_GetAtapftr0_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
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
** \brief Reads the bitgroup "T4" of register "Atapftr0".
**
** DIOW-data hold
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_97"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_97" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_97")))
#endif

uint32_t FREG_UPI_GetAtapftr0_T4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
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
** \brief Reads the bitgroup "T2" of register "Atapftr0".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_98"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_98" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_98")))
#endif

uint32_t FREG_UPI_GetAtapftr0_T2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
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
** \brief Reads the bitgroup "T1" of register "Atapftr0".
**
** Address valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_99"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_99" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_99")))
#endif

uint32_t FREG_UPI_GetAtapftr0_T1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
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
** \brief Writes the entire register "Atapftr1".
**
** This function writes the given value to the register "Atapftr1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_100"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_100" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_100")))
#endif

void FREG_UPI_SetAtapftr1( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atapftr1".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_101"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_101" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_101")))
#endif

void FREG_UPI_SetAtapftr1_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T4" of register "Atapftr1".
**
** DIOW-data hold
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_102"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_102" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_102")))
#endif

void FREG_UPI_SetAtapftr1_T4( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T2" of register "Atapftr1".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_103"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_103" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_103")))
#endif

void FREG_UPI_SetAtapftr1_T2( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T1" of register "Atapftr1".
**
** Address valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_104"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_104" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_104")))
#endif

void FREG_UPI_SetAtapftr1_T1( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atapftr1".
**
** This function reads the value from the register "Atapftr1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_105"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_105" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_105")))
#endif

uint32_t FREG_UPI_GetAtapftr1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atapftr1".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_106"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_106" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_106")))
#endif

uint32_t FREG_UPI_GetAtapftr1_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
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
** \brief Reads the bitgroup "T4" of register "Atapftr1".
**
** DIOW-data hold
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_107"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_107" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_107")))
#endif

uint32_t FREG_UPI_GetAtapftr1_T4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
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
** \brief Reads the bitgroup "T2" of register "Atapftr1".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_108"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_108" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_108")))
#endif

uint32_t FREG_UPI_GetAtapftr1_T2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
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
** \brief Reads the bitgroup "T1" of register "Atapftr1".
**
** Address valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_109"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_109" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_109")))
#endif

uint32_t FREG_UPI_GetAtapftr1_T1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
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
** \brief Writes the entire register "Atadtr0".
**
** This function writes the given value to the register "Atadtr0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_110"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_110" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_110")))
#endif

void FREG_UPI_SetAtadtr0( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atadtr0".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_111"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_111" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_111")))
#endif

void FREG_UPI_SetAtadtr0_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Td" of register "Atadtr0".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_112"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_112" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_112")))
#endif

void FREG_UPI_SetAtadtr0_Td( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Tm" of register "Atadtr0".
**
** CS(1:0) valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_113"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_113" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_113")))
#endif

void FREG_UPI_SetAtadtr0_Tm( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atadtr0".
**
** This function reads the value from the register "Atadtr0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_114"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_114" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_114")))
#endif

uint32_t FREG_UPI_GetAtadtr0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atadtr0".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_115"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_115" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_115")))
#endif

uint32_t FREG_UPI_GetAtadtr0_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
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
** \brief Reads the bitgroup "Td" of register "Atadtr0".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_116"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_116" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_116")))
#endif

uint32_t FREG_UPI_GetAtadtr0_Td( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
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
** \brief Reads the bitgroup "Tm" of register "Atadtr0".
**
** CS(1:0) valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_117"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_117" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_117")))
#endif

uint32_t FREG_UPI_GetAtadtr0_Tm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
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
** \brief Writes the entire register "Atadtr1".
**
** This function writes the given value to the register "Atadtr1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_118"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_118" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_118")))
#endif

void FREG_UPI_SetAtadtr1( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atadtr1".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_119"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_119" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_119")))
#endif

void FREG_UPI_SetAtadtr1_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Td" of register "Atadtr1".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_120"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_120" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_120")))
#endif

void FREG_UPI_SetAtadtr1_Td( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Tm" of register "Atadtr1".
**
** CS(1:0) valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_121"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_121" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_121")))
#endif

void FREG_UPI_SetAtadtr1_Tm( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atadtr1".
**
** This function reads the value from the register "Atadtr1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_122"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_122" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_122")))
#endif

uint32_t FREG_UPI_GetAtadtr1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atadtr1".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_123"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_123" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_123")))
#endif

uint32_t FREG_UPI_GetAtadtr1_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
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
** \brief Reads the bitgroup "Td" of register "Atadtr1".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_124"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_124" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_124")))
#endif

uint32_t FREG_UPI_GetAtadtr1_Td( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
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
** \brief Reads the bitgroup "Tm" of register "Atadtr1".
**
** CS(1:0) valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_125"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_125" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_125")))
#endif

uint32_t FREG_UPI_GetAtadtr1_Tm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
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
** \brief Writes the entire register "ModeX".
**
** This function writes the given value to the index-th entry of the register
** array ModeX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_126"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_126" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_126")))
#endif

void FREG_UPI_SetModeX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_MODEX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiMode" of register "ModeX".
**
** Device Mode Selection
** 
** 0x0: Device is inactive
** 0x1: SRAM modes
** 0x2: IDE mode
** 0x3: NAND-Flash mode
** 0x4: CI Common Memory mode
** 0x5: CI Attribute Memory mode
** 0x6: CI I/O mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiMode" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_127"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_127" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_127")))
#endif

void FREG_UPI_SetModeX_UpiMode( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_MODEX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "ModeX".
**
** This function reads the value from the index-th entry of the register
** array ModeX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_128"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_128" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_128")))
#endif

uint32_t FREG_UPI_GetModeX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiMode" of register "ModeX".
**
** Device Mode Selection
** 
** 0x0: Device is inactive
** 0x1: SRAM modes
** 0x2: IDE mode
** 0x3: NAND-Flash mode
** 0x4: CI Common Memory mode
** 0x5: CI Attribute Memory mode
** 0x6: CI I/O mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiMode" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_129"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_129" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_129")))
#endif

uint32_t FREG_UPI_GetModeX_UpiMode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40)));
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
** \brief Writes the entire register "TalsX".
**
** This function writes the given value to the index-th entry of the register
** array TalsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_130"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_130" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_130")))
#endif

void FREG_UPI_SetTalsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTals" of register "TalsX".
**
** Address Latch Setup Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTals" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_131"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_131" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_131")))
#endif

void FREG_UPI_SetTalsX_UpiTals( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TalsX".
**
** This function reads the value from the index-th entry of the register
** array TalsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_132"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_132" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_132")))
#endif

uint32_t FREG_UPI_GetTalsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTals" of register "TalsX".
**
** Address Latch Setup Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTals" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_133"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_133" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_133")))
#endif

uint32_t FREG_UPI_GetTalsX_UpiTals( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40)));
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
** \brief Writes the entire register "TalhX".
**
** This function writes the given value to the index-th entry of the register
** array TalhX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_134"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_134" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_134")))
#endif

void FREG_UPI_SetTalhX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTalh" of register "TalhX".
**
** Address Latch Hold Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTalh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_135"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_135" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_135")))
#endif

void FREG_UPI_SetTalhX_UpiTalh( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TalhX".
**
** This function reads the value from the index-th entry of the register
** array TalhX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_136"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_136" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_136")))
#endif

uint32_t FREG_UPI_GetTalhX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTalh" of register "TalhX".
**
** Address Latch Hold Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTalh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_137"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_137" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_137")))
#endif

uint32_t FREG_UPI_GetTalhX_UpiTalh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40)));
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
** \brief Writes the entire register "TrsX".
**
** This function writes the given value to the index-th entry of the register
** array TrsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_138"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_138" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_138")))
#endif

void FREG_UPI_SetTrsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrs" of register "TrsX".
**
** Read Address Setup Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrs" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_139"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_139" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_139")))
#endif

void FREG_UPI_SetTrsX_UpiTrs( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrsX".
**
** This function reads the value from the index-th entry of the register
** array TrsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_140"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_140" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_140")))
#endif

uint32_t FREG_UPI_GetTrsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrs" of register "TrsX".
**
** Read Address Setup Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrs" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_141"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_141" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_141")))
#endif

uint32_t FREG_UPI_GetTrsX_UpiTrs( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40)));
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
** \brief Writes the entire register "TrdsX".
**
** This function writes the given value to the index-th entry of the register
** array TrdsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_142"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_142" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_142")))
#endif

void FREG_UPI_SetTrdsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrds" of register "TrdsX".
**
** Read Data Setup/Strobe Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_143"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_143" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_143")))
#endif

void FREG_UPI_SetTrdsX_UpiTrds( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrdsX".
**
** This function reads the value from the index-th entry of the register
** array TrdsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_144"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_144" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_144")))
#endif

uint32_t FREG_UPI_GetTrdsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrds" of register "TrdsX".
**
** Read Data Setup/Strobe Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_145"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_145" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_145")))
#endif

uint32_t FREG_UPI_GetTrdsX_UpiTrds( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40)));
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
** \brief Writes the entire register "TrdhX".
**
** This function writes the given value to the index-th entry of the register
** array TrdhX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_146"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_146" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_146")))
#endif

void FREG_UPI_SetTrdhX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrdh" of register "TrdhX".
**
** Read Data Hold Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrdh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_147"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_147" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_147")))
#endif

void FREG_UPI_SetTrdhX_UpiTrdh( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrdhX".
**
** This function reads the value from the index-th entry of the register
** array TrdhX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_148"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_148" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_148")))
#endif

uint32_t FREG_UPI_GetTrdhX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrdh" of register "TrdhX".
**
** Read Data Hold Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrdh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_149"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_149" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_149")))
#endif

uint32_t FREG_UPI_GetTrdhX_UpiTrdh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40)));
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
** \brief Writes the entire register "TrrX".
**
** This function writes the given value to the index-th entry of the register
** array TrrX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_150"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_150" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_150")))
#endif

void FREG_UPI_SetTrrX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrr" of register "TrrX".
**
** Read Recovery Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_151"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_151" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_151")))
#endif

void FREG_UPI_SetTrrX_UpiTrr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrrX".
**
** This function reads the value from the index-th entry of the register
** array TrrX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_152"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_152" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_152")))
#endif

uint32_t FREG_UPI_GetTrrX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrr" of register "TrrX".
**
** Read Recovery Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_153"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_153" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_153")))
#endif

uint32_t FREG_UPI_GetTrrX_UpiTrr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40)));
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
** \brief Writes the entire register "TwsX".
**
** This function writes the given value to the index-th entry of the register
** array TwsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_154"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_154" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_154")))
#endif

void FREG_UPI_SetTwsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTws" of register "TwsX".
**
** Write Address Setup Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTws" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_155"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_155" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_155")))
#endif

void FREG_UPI_SetTwsX_UpiTws( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TwsX".
**
** This function reads the value from the index-th entry of the register
** array TwsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_156"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_156" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_156")))
#endif

uint32_t FREG_UPI_GetTwsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTws" of register "TwsX".
**
** Write Address Setup Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTws" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_157"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_157" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_157")))
#endif

uint32_t FREG_UPI_GetTwsX_UpiTws( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40)));
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
** \brief Writes the entire register "TwpX".
**
** This function writes the given value to the index-th entry of the register
** array TwpX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_158"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_158" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_158")))
#endif

void FREG_UPI_SetTwpX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWPX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTwp" of register "TwpX".
**
** Write Pulse Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTwp" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_159"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_159" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_159")))
#endif

void FREG_UPI_SetTwpX_UpiTwp( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWPX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TwpX".
**
** This function reads the value from the index-th entry of the register
** array TwpX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_160"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_160" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_160")))
#endif

uint32_t FREG_UPI_GetTwpX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTwp" of register "TwpX".
**
** Write Pulse Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTwp" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_161"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_161" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_161")))
#endif

uint32_t FREG_UPI_GetTwpX_UpiTwp( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40)));
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
** \brief Writes the entire register "TwrX".
**
** This function writes the given value to the index-th entry of the register
** array TwrX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_162"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_162" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_162")))
#endif

void FREG_UPI_SetTwrX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTwr" of register "TwrX".
**
** Write Recovery Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTwr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_163"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_163" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_163")))
#endif

void FREG_UPI_SetTwrX_UpiTwr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TwrX".
**
** This function reads the value from the index-th entry of the register
** array TwrX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_164"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_164" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_164")))
#endif

uint32_t FREG_UPI_GetTwrX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTwr" of register "TwrX".
**
** Write Recovery Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTwr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_165"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_165" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_165")))
#endif

uint32_t FREG_UPI_GetTwrX_UpiTwr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40)));
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
** \brief Writes the entire register "WmmaskX".
**
** This function writes the given value to the index-th entry of the register
** array WmmaskX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_166"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_166" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_166")))
#endif

void FREG_UPI_SetWmmaskX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WMMASKX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiWmmask" of register "WmmaskX".
**
** Wait Mask Bit (0: wait inactive, 1: wait active)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiWmmask" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_167"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_167" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_167")))
#endif

void FREG_UPI_SetWmmaskX_UpiWmmask( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WMMASKX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WmmaskX".
**
** This function reads the value from the index-th entry of the register
** array WmmaskX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_168"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_168" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_168")))
#endif

uint32_t FREG_UPI_GetWmmaskX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiWmmask" of register "WmmaskX".
**
** Wait Mask Bit (0: wait inactive, 1: wait active)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiWmmask" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_169"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_169" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_169")))
#endif

uint32_t FREG_UPI_GetWmmaskX_UpiWmmask( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40)));
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
** \brief Writes the entire register "BufenX".
**
** This function writes the given value to the index-th entry of the register
** array BufenX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_170"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_170" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_170")))
#endif

void FREG_UPI_SetBufenX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_BUFENX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiBufen" of register "BufenX".
**
** External Buffer Enable (0: no external buffer, 1: external buffer)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiBufen" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_171"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_171" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_171")))
#endif

void FREG_UPI_SetBufenX_UpiBufen( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_BUFENX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufenX".
**
** This function reads the value from the index-th entry of the register
** array BufenX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_172"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_172" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_172")))
#endif

uint32_t FREG_UPI_GetBufenX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiBufen" of register "BufenX".
**
** External Buffer Enable (0: no external buffer, 1: external buffer)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiBufen" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_173"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_173" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_173")))
#endif

uint32_t FREG_UPI_GetBufenX_UpiBufen( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40)));
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
** \brief Writes the entire register "Atadb".
**
** This function writes the given value to the register "Atadb".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_174"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_174" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_174")))
#endif

void FREG_UPI_SetAtadb( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData3" of register "Atadb".
**
** Transmit / Receive Data 1[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 2[7:0] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData3" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_175"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_175" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_175")))
#endif

void FREG_UPI_SetAtadb_DmaData3( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData2" of register "Atadb".
**
** Transmit / Receive Data 1[7:0] (with BeLeC = '0') /
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData2" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_176"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_176" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_176")))
#endif

void FREG_UPI_SetAtadb_DmaData2( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData1" of register "Atadb".
**
** Transmit / Receive Data 2[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 1 [7:0] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData1" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_177"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_177" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_177")))
#endif

void FREG_UPI_SetAtadb_DmaData1( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData0" of register "Atadb".
**
** Transmit / Receive Data 2[7:0] (with BeLeC = '0')/
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData0" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_178"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_178" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_178")))
#endif

void FREG_UPI_SetAtadb_DmaData0( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atadb".
**
** This function reads the value from the register "Atadb".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_179"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_179" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_179")))
#endif

uint32_t FREG_UPI_GetAtadb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DmaData3" of register "Atadb".
**
** Transmit / Receive Data 1[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 2[7:0] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData3" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_180"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_180" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_180")))
#endif

uint32_t FREG_UPI_GetAtadb_DmaData3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
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
** \brief Reads the bitgroup "DmaData2" of register "Atadb".
**
** Transmit / Receive Data 1[7:0] (with BeLeC = '0') /
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData2" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_181"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_181" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_181")))
#endif

uint32_t FREG_UPI_GetAtadb_DmaData2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
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
** \brief Reads the bitgroup "DmaData1" of register "Atadb".
**
** Transmit / Receive Data 2[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 1 [7:0] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData1" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_182"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_182" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_182")))
#endif

uint32_t FREG_UPI_GetAtadb_DmaData1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
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
** \brief Reads the bitgroup "DmaData0" of register "Atadb".
**
** Transmit / Receive Data 2[7:0] (with BeLeC = '0')/
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData0" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_UPI_183"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_UPI_183" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_UPI_183")))
#endif

uint32_t FREG_UPI_GetAtadb_DmaData0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
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

/*!
********************************************************************************
**
** \brief Initializes the "UPI" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_UPI_Init( void )
{
    FREG_UPI_WaittimeMirror |= ( ( 0 << 0 ) & 0x000000FFUL );
    FREG_UPI_WaittimeenMirror |= ( ( 0 << 0 ) & 0x00000001UL );
}
