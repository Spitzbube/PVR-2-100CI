/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_sflash.c
**
** \brief     SFLASH access functions
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
#define FREG_SFLASH_C

#include <stdint.h>
#include "reg_sflash.h"

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
** \brief Writes the entire register "Port".
**
** This function writes the given value to the register "Port".
**
** Register for all data which is to be serialized (except commands)
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_1")))
#endif

void FREG_SFLASH_SetPort( uint32_t value )
{
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_PORT, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_PORT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SflashPort" of register "Port".
**
** Register for all data which is to be serialized (except commands)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SflashPort" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_2")))
#endif

void FREG_SFLASH_SetPort_SflashPort( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_SFLASH_PORT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_PORT, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_PORT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Port".
**
** This function reads the value from the register "Port".
**
** Register for all data which is to be serialized (except commands)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_3")))
#endif

uint32_t FREG_SFLASH_GetPort( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_PORT));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SflashPort" of register "Port".
**
** Register for all data which is to be serialized (except commands)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SflashPort" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_4")))
#endif

uint32_t FREG_SFLASH_GetPort_SflashPort( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_PORT));
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
** \brief Writes the entire register "Command".
**
** This function writes the given value to the register "Command".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_5")))
#endif

void FREG_SFLASH_SetCommand( uint32_t value )
{
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_COMMAND, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_COMMAND)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SflashCommand" of register "Command".
**
** Contains SFLASH command which will be executed the next time SFLASH_PORT gets read or written
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SflashCommand" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_6")))
#endif

void FREG_SFLASH_SetCommand_SflashCommand( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_SFLASH_COMMAND)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_COMMAND, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_COMMAND)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Command".
**
** This function reads the value from the register "Command".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_7")))
#endif

uint32_t FREG_SFLASH_GetCommand( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_COMMAND));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SflashCommand" of register "Command".
**
** Contains SFLASH command which will be executed the next time SFLASH_PORT gets read or written
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SflashCommand" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_8")))
#endif

uint32_t FREG_SFLASH_GetCommand_SflashCommand( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_COMMAND));
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
** \brief Writes the entire register "Speed".
**
** This function writes the given value to the register "Speed".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_9")))
#endif

void FREG_SFLASH_SetSpeed( uint32_t value )
{
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_SPEED, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_SPEED)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SflashSpeed" of register "Speed".
**
** - '0': Slow serial clock (13.
** 5 MHz)
** - '1': Fast serial clock (20.25 MHz)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SflashSpeed" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_10")))
#endif

void FREG_SFLASH_SetSpeed_SflashSpeed( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_SFLASH_SPEED)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_SPEED, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_SPEED)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Speed".
**
** This function reads the value from the register "Speed".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_11")))
#endif

uint32_t FREG_SFLASH_GetSpeed( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_SPEED));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SflashSpeed" of register "Speed".
**
** - '0': Slow serial clock (13.
** 5 MHz)
** - '1': Fast serial clock (20.25 MHz)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SflashSpeed" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_SFLASH_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_SFLASH_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_SFLASH_12")))
#endif

uint32_t FREG_SFLASH_GetSpeed_SflashSpeed( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_SPEED));
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

/*!
********************************************************************************
**
** \brief Initializes the "SFLASH" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_SFLASH_Init( void )
{
}
