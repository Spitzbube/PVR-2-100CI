/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_sflash.h
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
#if !defined(FREG_SFLASH_H)
#define FREG_SFLASH_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_SFLASH_ENABLE_DEBUG_PRINT   0
#define FREG_SFLASH_DEBUG_PRINT_FUNCTION printf

#if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_SFLASH_PORT                         FIO_ADDRESS(SFLASH,0xC0000000UL)
#define FREG_SFLASH_COMMAND                      FIO_ADDRESS(SFLASH,0xC0000004UL)
#define FREG_SFLASH_SPEED                        FIO_ADDRESS(SFLASH,0xC0000008UL)

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
extern void FREG_SFLASH_SetPort( uint32_t value );
#else
INLINE void FREG_SFLASH_SetPort( uint32_t value )
{
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_PORT, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_PORT)) = value;
}
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
extern void FREG_SFLASH_SetPort_SflashPort( uint32_t value );
#else
INLINE void FREG_SFLASH_SetPort_SflashPort( uint32_t value )
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
extern uint32_t FREG_SFLASH_GetPort( void );
#else
INLINE uint32_t FREG_SFLASH_GetPort( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_PORT));
    return( value );
}
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
extern uint32_t FREG_SFLASH_GetPort_SflashPort( void );
#else
INLINE uint32_t FREG_SFLASH_GetPort_SflashPort( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_PORT));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_SFLASH_SetCommand( uint32_t value );
#else
INLINE void FREG_SFLASH_SetCommand( uint32_t value )
{
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_COMMAND, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_COMMAND)) = value;
}
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
extern void FREG_SFLASH_SetCommand_SflashCommand( uint32_t value );
#else
INLINE void FREG_SFLASH_SetCommand_SflashCommand( uint32_t value )
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
extern uint32_t FREG_SFLASH_GetCommand( void );
#else
INLINE uint32_t FREG_SFLASH_GetCommand( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_COMMAND));
    return( value );
}
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
extern uint32_t FREG_SFLASH_GetCommand_SflashCommand( void );
#else
INLINE uint32_t FREG_SFLASH_GetCommand_SflashCommand( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_COMMAND));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern void FREG_SFLASH_SetSpeed( uint32_t value );
#else
INLINE void FREG_SFLASH_SetSpeed( uint32_t value )
{
    #if FREG_SFLASH_ENABLE_DEBUG_PRINT == 1
        FREG_SFLASH_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_SFLASH", FREG_SFLASH_SPEED, value );
    #endif
    *((volatile uint32_t*)(FREG_SFLASH_SPEED)) = value;
}
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
extern void FREG_SFLASH_SetSpeed_SflashSpeed( uint32_t value );
#else
INLINE void FREG_SFLASH_SetSpeed_SflashSpeed( uint32_t value )
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
extern uint32_t FREG_SFLASH_GetSpeed( void );
#else
INLINE uint32_t FREG_SFLASH_GetSpeed( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_SPEED));
    return( value );
}
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
extern uint32_t FREG_SFLASH_GetSpeed_SflashSpeed( void );
#else
INLINE uint32_t FREG_SFLASH_GetSpeed_SflashSpeed( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_SFLASH_SPEED));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_SFLASH_Init( void );

#endif
