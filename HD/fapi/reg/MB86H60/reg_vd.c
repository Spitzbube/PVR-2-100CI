/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_vd.c
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
#define FREG_VD_C

#include <stdint.h>
#include "reg_vd.h"

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
volatile uint32_t FREG_VD_IntReqToPcpuMirror = 0;
volatile uint32_t FREG_VD_IntReqToMcpuMirror = 0;
volatile uint32_t FREG_VD_IntClearToMcpuMirror = 0;

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "CmdReset".
**
** This function writes the given value to the register "CmdReset".
**
** 
**
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

void FREG_VD_SetCmdReset( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CMDRESET, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CMDRESET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CbusArbRst" of register "CmdReset".
**
** Reset for PCPU_CBUS_ARB block.
** 
** After reset is done, automatically set to 0.
** 1: Reset on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CbusArbRst" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_2")))
#endif

void FREG_VD_SetCmdReset_CbusArbRst( uint32_t value )
{
    register uint32_t mask = 0x00040000UL;
    value = ( value << 18 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CMDRESET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CMDRESET, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CMDRESET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PcpuFrRst" of register "CmdReset".
**
** Reset for a part of PCPU_EU, a part of PCPU_ICNT and a part of PCPU_DCNT.
** 
** In the case of PCPU, after reset is done, the value is same as the value specified by PCPU_STOP.
** In the case of the other CPU, after reset is done, the value is hold.
** 1: Reset on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PcpuFrRst" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_3")))
#endif

void FREG_VD_SetCmdReset_PcpuFrRst( uint32_t value )
{
    register uint32_t mask = 0x00020000UL;
    value = ( value << 17 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CMDRESET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CMDRESET, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CMDRESET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PcpuPeriRst" of register "CmdReset".
**
** After reset is done, automatically set to 0.
** 
** 1: Reset on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PcpuPeriRst" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_4")))
#endif

void FREG_VD_SetCmdReset_PcpuPeriRst( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CMDRESET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CMDRESET, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CMDRESET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "CmdReset".
**
** This function reads the value from the register "CmdReset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_5")))
#endif

uint32_t FREG_VD_GetCmdReset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CMDRESET));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CbusArbRst" of register "CmdReset".
**
** Reset for PCPU_CBUS_ARB block.
** 
** After reset is done, automatically set to 0.
** 1: Reset on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CbusArbRst" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_6")))
#endif

uint32_t FREG_VD_GetCmdReset_CbusArbRst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CMDRESET));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PcpuFrRst" of register "CmdReset".
**
** Reset for a part of PCPU_EU, a part of PCPU_ICNT and a part of PCPU_DCNT.
** 
** In the case of PCPU, after reset is done, the value is same as the value specified by PCPU_STOP.
** In the case of the other CPU, after reset is done, the value is hold.
** 1: Reset on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PcpuFrRst" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_7")))
#endif

uint32_t FREG_VD_GetCmdReset_PcpuFrRst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CMDRESET));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PcpuPeriRst" of register "CmdReset".
**
** After reset is done, automatically set to 0.
** 
** 1: Reset on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PcpuPeriRst" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_8")))
#endif

uint32_t FREG_VD_GetCmdReset_PcpuPeriRst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CMDRESET));
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
** \brief Writes the entire register "ClkEn".
**
** This function writes the given value to the register "ClkEn".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_9")))
#endif

void FREG_VD_SetClkEn( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CLKEN, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CLKEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M6clkenf5ec" of register "ClkEn".
**
** Clk enable at root5 (DMA2) of M6CLK system.
** 
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M6clkenf5ec" consists of the bits 20..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00100000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_10")))
#endif

void FREG_VD_SetClkEn_M6clkenf5ec( uint32_t value )
{
    register uint32_t mask = 0x00100000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CLKEN)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CLKEN, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CLKEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M6clkenf4ec" of register "ClkEn".
**
** Clk enable at root4 (DMA1) of M6CLK system.
** 
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M6clkenf4ec" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_11")))
#endif

void FREG_VD_SetClkEn_M6clkenf4ec( uint32_t value )
{
    register uint32_t mask = 0x00080000UL;
    value = ( value << 19 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CLKEN)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CLKEN, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CLKEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M6clkenf3ec" of register "ClkEn".
**
** Clk enable at root3 (ECPU_PERI) of M2CLK system.
** 
** Value is 1 when it uses application timer except WDT and serial port.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M6clkenf3ec" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_12")))
#endif

void FREG_VD_SetClkEn_M6clkenf3ec( uint32_t value )
{
    register uint32_t mask = 0x00040000UL;
    value = ( value << 18 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CLKEN)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CLKEN, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CLKEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M6clkenf2ec" of register "ClkEn".
**
** Clk enable at root2 (CBUS access exept FF) of M2CLK system.
** 
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M6clkenf2ec" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_13")))
#endif

void FREG_VD_SetClkEn_M6clkenf2ec( uint32_t value )
{
    register uint32_t mask = 0x00020000UL;
    value = ( value << 17 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CLKEN)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CLKEN, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CLKEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M6clkenf1ec" of register "ClkEn".
**
** Clk enable at root1 (ECPU_EU, a part of ECPU_ICNT, a part of ECPU_DCNT) of M6CLK system.
** 
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M6clkenf1ec" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_14")))
#endif

void FREG_VD_SetClkEn_M6clkenf1ec( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_CLKEN)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_CLKEN, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_CLKEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "ClkEn".
**
** This function reads the value from the register "ClkEn".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_15")))
#endif

uint32_t FREG_VD_GetClkEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CLKEN));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M6clkenf5ec" of register "ClkEn".
**
** Clk enable at root5 (DMA2) of M6CLK system.
** 
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M6clkenf5ec" consists of the bits 20..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00100000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_16")))
#endif

uint32_t FREG_VD_GetClkEn_M6clkenf5ec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CLKEN));
    value = ( value & 0x00100000UL ) >> 20;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M6clkenf4ec" of register "ClkEn".
**
** Clk enable at root4 (DMA1) of M6CLK system.
** 
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M6clkenf4ec" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_17")))
#endif

uint32_t FREG_VD_GetClkEn_M6clkenf4ec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CLKEN));
    value = ( value & 0x00080000UL ) >> 19;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M6clkenf3ec" of register "ClkEn".
**
** Clk enable at root3 (ECPU_PERI) of M2CLK system.
** 
** Value is 1 when it uses application timer except WDT and serial port.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M6clkenf3ec" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_18")))
#endif

uint32_t FREG_VD_GetClkEn_M6clkenf3ec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CLKEN));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M6clkenf2ec" of register "ClkEn".
**
** Clk enable at root2 (CBUS access exept FF) of M2CLK system.
** 
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M6clkenf2ec" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_19")))
#endif

uint32_t FREG_VD_GetClkEn_M6clkenf2ec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CLKEN));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M6clkenf1ec" of register "ClkEn".
**
** Clk enable at root1 (ECPU_EU, a part of ECPU_ICNT, a part of ECPU_DCNT) of M6CLK system.
** 
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M6clkenf1ec" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_20")))
#endif

uint32_t FREG_VD_GetClkEn_M6clkenf1ec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_CLKEN));
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
** \brief Writes the entire register "IntReqToPcpu".
**
** This function writes the given value to the register "IntReqToPcpu".
**
** Sends Interrupt request to PCPU
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_21")))
#endif

void FREG_VD_SetIntReqToPcpu( uint32_t value )
{
    FREG_VD_IntReqToPcpuMirror = value;
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTREQTOPCPU, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTREQTOPCPU)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IntReq" of register "IntReqToPcpu".
**
** Sends Interrupt request to PCPU
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IntReq" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_22")))
#endif

void FREG_VD_SetIntReqToPcpu_IntReq( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VD_IntReqToPcpuMirror & ~mask;
    FREG_VD_IntReqToPcpuMirror = value;
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTREQTOPCPU, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTREQTOPCPU)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IntReqToPcpu".
**
** This function reads the value from the register "IntReqToPcpu".
**
** Sends Interrupt request to PCPU
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_23")))
#endif

uint32_t FREG_VD_GetmIntReqToPcpu( void )
{
    register uint32_t value = FREG_VD_IntReqToPcpuMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IntReq" of register "IntReqToPcpu".
**
** Sends Interrupt request to PCPU
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IntReq" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_24")))
#endif

uint32_t FREG_VD_GetmIntReqToPcpu_IntReq( void )
{
    register uint32_t value = FREG_VD_IntReqToPcpuMirror;
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
** \brief Writes the entire register "PcpuRamReadEnable".
**
** This function writes the given value to the register "PcpuRamReadEnable".
**
** Enables the PCPU ram to be dumped.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_25")))
#endif

void FREG_VD_SetPcpuRamReadEnable( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PCPURAMREADENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PCPURAMREADENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PcpuRamEna" of register "PcpuRamReadEnable".
**
** Enables the PCPU ram to be dumped.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PcpuRamEna" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_26")))
#endif

void FREG_VD_SetPcpuRamReadEnable_PcpuRamEna( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PCPURAMREADENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PCPURAMREADENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PCPURAMREADENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PcpuRamReadEnable".
**
** This function reads the value from the register "PcpuRamReadEnable".
**
** Enables the PCPU ram to be dumped.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_27")))
#endif

uint32_t FREG_VD_GetPcpuRamReadEnable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PCPURAMREADENABLE));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PcpuRamEna" of register "PcpuRamReadEnable".
**
** Enables the PCPU ram to be dumped.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PcpuRamEna" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_28")))
#endif

uint32_t FREG_VD_GetPcpuRamReadEnable_PcpuRamEna( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PCPURAMREADENABLE));
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
** \brief Writes the entire register "IntReqToMcpu".
**
** This function writes the given value to the register "IntReqToMcpu".
**
** Sends Interrupt request to MCPU
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_29")))
#endif

void FREG_VD_SetIntReqToMcpu( uint32_t value )
{
    FREG_VD_IntReqToMcpuMirror = value;
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTREQTOMCPU, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTREQTOMCPU)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IntReq" of register "IntReqToMcpu".
**
** Sends Interrupt request to MCPU
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IntReq" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_30")))
#endif

void FREG_VD_SetIntReqToMcpu_IntReq( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VD_IntReqToMcpuMirror & ~mask;
    FREG_VD_IntReqToMcpuMirror = value;
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTREQTOMCPU, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTREQTOMCPU)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IntReqToMcpu".
**
** This function reads the value from the register "IntReqToMcpu".
**
** Sends Interrupt request to MCPU
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_31")))
#endif

uint32_t FREG_VD_GetmIntReqToMcpu( void )
{
    register uint32_t value = FREG_VD_IntReqToMcpuMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IntReq" of register "IntReqToMcpu".
**
** Sends Interrupt request to MCPU
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IntReq" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_32")))
#endif

uint32_t FREG_VD_GetmIntReqToMcpu_IntReq( void )
{
    register uint32_t value = FREG_VD_IntReqToMcpuMirror;
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
** \brief Reads the entire register "IntStatusToMcpu".
**
** This function reads the value from the register "IntStatusToMcpu".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_33")))
#endif

uint32_t FREG_VD_GetIntStatusToMcpu( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTSTATUSTOMCPU));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IntStatus" of register "IntStatusToMcpu".
**
** Interrupts Status to MCPU.
** 
** A write access to this register clears the interrupts to MCPU.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IntStatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_34")))
#endif

uint32_t FREG_VD_GetIntStatusToMcpu_IntStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTSTATUSTOMCPU));
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
** \brief Writes the entire register "IntClearToMcpu".
**
** This function writes the given value to the register "IntClearToMcpu".
**
** Clears interrupts to MPCU.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_35")))
#endif

void FREG_VD_SetIntClearToMcpu( uint32_t value )
{
//    FREG_VD_IntClearToMcpuMirror = value;
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTCLEARTOMCPU, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTCLEARTOMCPU)) = value;
    FREG_VD_IntClearToMcpuMirror = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IntClear" of register "IntClearToMcpu".
**
** Clears interrupts to MPCU.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IntClear" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_36")))
#endif

void FREG_VD_SetIntClearToMcpu_IntClear( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VD_IntClearToMcpuMirror & ~mask;
    FREG_VD_IntClearToMcpuMirror = value;
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTCLEARTOMCPU, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTCLEARTOMCPU)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IntClearToMcpu".
**
** This function reads the value from the register "IntClearToMcpu".
**
** Clears interrupts to MPCU.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_37")))
#endif

uint32_t FREG_VD_GetmIntClearToMcpu( void )
{
    register uint32_t value = FREG_VD_IntClearToMcpuMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IntClear" of register "IntClearToMcpu".
**
** Clears interrupts to MPCU.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IntClear" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_38")))
#endif

uint32_t FREG_VD_GetmIntClearToMcpu_IntClear( void )
{
    register uint32_t value = FREG_VD_IntClearToMcpuMirror;
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
** \brief Writes the entire register "IntEna".
**
** This function writes the given value to the register "IntEna".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_39")))
#endif

void FREG_VD_SetIntEna( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint7en" of register "IntEna".
**
** Interrupt Enable 7.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint7en" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_40")))
#endif

void FREG_VD_SetIntEna_Axiint7en( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint6en" of register "IntEna".
**
** Interrupt Enable 6.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint6en" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_41")))
#endif

void FREG_VD_SetIntEna_Axiint6en( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint5en" of register "IntEna".
**
** Interrupt Enable 5.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint5en" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_42")))
#endif

void FREG_VD_SetIntEna_Axiint5en( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint4en" of register "IntEna".
**
** Interrupt Enable 4.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint4en" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_43")))
#endif

void FREG_VD_SetIntEna_Axiint4en( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint3en" of register "IntEna".
**
** Interrupt Enable 3.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint3en" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_44")))
#endif

void FREG_VD_SetIntEna_Axiint3en( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint2en" of register "IntEna".
**
** Interrupt Enable 2.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint2en" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_45")))
#endif

void FREG_VD_SetIntEna_Axiint2en( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint1en" of register "IntEna".
**
** Interrupt Enable 1.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint1en" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_46")))
#endif

void FREG_VD_SetIntEna_Axiint1en( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Axiint0en" of register "IntEna".
**
** Interrupt Enable 0.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Axiint0en" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_47")))
#endif

void FREG_VD_SetIntEna_Axiint0en( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Amwtoien" of register "IntEna".
**
** Time out interrupt for H.
** 264 Core writing address, data.
** (AXI -BR master)
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Amwtoien" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_48")))
#endif

void FREG_VD_SetIntEna_Amwtoien( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Amrtoien" of register "IntEna".
**
** Time out interrupt for H.
** 264 Core reading address, data.
** (AXI -BRmaster)
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Amrtoien" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_49")))
#endif

void FREG_VD_SetIntEna_Amrtoien( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Aswtoien" of register "IntEna".
**
** Time out interrupt for MainCPU writing address, data.
**  (AXI-BR slave)
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Aswtoien" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_50")))
#endif

void FREG_VD_SetIntEna_Aswtoien( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Asdrtoien" of register "IntEna".
**
** Time out interrupt for MainCPU reading address, data.
**  (AXI-BR slave)
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Asdrtoien" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_51")))
#endif

void FREG_VD_SetIntEna_Asdrtoien( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Crinten" of register "IntEna".
**
** Interrupt for command reset.
** 
** This bit field holds value during command reset.
** 1: ON
** 0: OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Crinten" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_52")))
#endif

void FREG_VD_SetIntEna_Crinten( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 13
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_INTENA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_INTENA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_INTENA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IntEna".
**
** This function reads the value from the register "IntEna".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_53")))
#endif

uint32_t FREG_VD_GetIntEna( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Axiint7en" of register "IntEna".
**
** Interrupt Enable 7.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint7en" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_54")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint7en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint6en" of register "IntEna".
**
** Interrupt Enable 6.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint6en" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_55")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint6en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint5en" of register "IntEna".
**
** Interrupt Enable 5.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint5en" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_56")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint5en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint4en" of register "IntEna".
**
** Interrupt Enable 4.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint4en" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_57")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint4en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint3en" of register "IntEna".
**
** Interrupt Enable 3.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint3en" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_58")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint3en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint2en" of register "IntEna".
**
** Interrupt Enable 2.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint2en" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_59")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint2en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint1en" of register "IntEna".
**
** Interrupt Enable 1.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint1en" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_60")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint1en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Axiint0en" of register "IntEna".
**
** Interrupt Enable 0.
**  From H.264 Core to MainCPU.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axiint0en" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_61")))
#endif

uint32_t FREG_VD_GetIntEna_Axiint0en( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Amwtoien" of register "IntEna".
**
** Time out interrupt for H.
** 264 Core writing address, data.
** (AXI -BR master)
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Amwtoien" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_62")))
#endif

uint32_t FREG_VD_GetIntEna_Amwtoien( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Amrtoien" of register "IntEna".
**
** Time out interrupt for H.
** 264 Core reading address, data.
** (AXI -BRmaster)
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Amrtoien" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_63")))
#endif

uint32_t FREG_VD_GetIntEna_Amrtoien( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Aswtoien" of register "IntEna".
**
** Time out interrupt for MainCPU writing address, data.
**  (AXI-BR slave)
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Aswtoien" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_64")))
#endif

uint32_t FREG_VD_GetIntEna_Aswtoien( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Asdrtoien" of register "IntEna".
**
** Time out interrupt for MainCPU reading address, data.
**  (AXI-BR slave)
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Asdrtoien" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_65")))
#endif

uint32_t FREG_VD_GetIntEna_Asdrtoien( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Reads the bitgroup "Crinten" of register "IntEna".
**
** Interrupt for command reset.
** 
** This bit field holds value during command reset.
** 1: ON
** 0: OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Crinten" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_66")))
#endif

uint32_t FREG_VD_GetIntEna_Crinten( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_INTENA));
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
** \brief Writes the entire register "PbVcpbInfoTablesAddr".
**
** This function writes the given value to the register "PbVcpbInfoTablesAddr".
**
** Parameter at Booting , start address of vcpb info tables on ramif_s.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_67")))
#endif

void FREG_VD_SetPbVcpbInfoTablesAddr( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBVCPBINFOTABLESADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBVCPBINFOTABLESADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PbVcpbInfoTablesAddr" of register "PbVcpbInfoTablesAddr".
**
** Parameter at Booting , start address of vcpb info tables on ramif_s.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PbVcpbInfoTablesAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_68")))
#endif

void FREG_VD_SetPbVcpbInfoTablesAddr_PbVcpbInfoTablesAddr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PBVCPBINFOTABLESADDR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBVCPBINFOTABLESADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBVCPBINFOTABLESADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PbVcpbInfoTablesAddr".
**
** This function reads the value from the register "PbVcpbInfoTablesAddr".
**
** Parameter at Booting , start address of vcpb info tables on ramif_s.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_69")))
#endif

uint32_t FREG_VD_GetPbVcpbInfoTablesAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBVCPBINFOTABLESADDR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PbVcpbInfoTablesAddr" of register "PbVcpbInfoTablesAddr".
**
** Parameter at Booting , start address of vcpb info tables on ramif_s.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PbVcpbInfoTablesAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_70")))
#endif

uint32_t FREG_VD_GetPbVcpbInfoTablesAddr_PbVcpbInfoTablesAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBVCPBINFOTABLESADDR));
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
** \brief Writes the entire register "PbVdpbInfoTablesAddr".
**
** This function writes the given value to the register "PbVdpbInfoTablesAddr".
**
** Parameter at Booting , start address of vdpb info tables on ramif_s.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_71")))
#endif

void FREG_VD_SetPbVdpbInfoTablesAddr( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBVDPBINFOTABLESADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBVDPBINFOTABLESADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PbVdpbInfoTablesAddr" of register "PbVdpbInfoTablesAddr".
**
** Parameter at Booting , start address of vdpb info tables on ramif_s.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PbVdpbInfoTablesAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_72")))
#endif

void FREG_VD_SetPbVdpbInfoTablesAddr_PbVdpbInfoTablesAddr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PBVDPBINFOTABLESADDR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBVDPBINFOTABLESADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBVDPBINFOTABLESADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PbVdpbInfoTablesAddr".
**
** This function reads the value from the register "PbVdpbInfoTablesAddr".
**
** Parameter at Booting , start address of vdpb info tables on ramif_s.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_73")))
#endif

uint32_t FREG_VD_GetPbVdpbInfoTablesAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBVDPBINFOTABLESADDR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PbVdpbInfoTablesAddr" of register "PbVdpbInfoTablesAddr".
**
** Parameter at Booting , start address of vdpb info tables on ramif_s.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PbVdpbInfoTablesAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_74")))
#endif

uint32_t FREG_VD_GetPbVdpbInfoTablesAddr_PbVdpbInfoTablesAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBVDPBINFOTABLESADDR));
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
** \brief Writes the entire register "PbPcpuWorkAddr".
**
** This function writes the given value to the register "PbPcpuWorkAddr".
**
** Parameter at Booting , start address of pcpu work address on ramif_s.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_75")))
#endif

void FREG_VD_SetPbPcpuWorkAddr( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBPCPUWORKADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBPCPUWORKADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PbPcpuWorkAddr" of register "PbPcpuWorkAddr".
**
** Parameter at Booting , start address of pcpu work address on ramif_s.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PbPcpuWorkAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_76")))
#endif

void FREG_VD_SetPbPcpuWorkAddr_PbPcpuWorkAddr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PBPCPUWORKADDR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBPCPUWORKADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBPCPUWORKADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PbPcpuWorkAddr".
**
** This function reads the value from the register "PbPcpuWorkAddr".
**
** Parameter at Booting , start address of pcpu work address on ramif_s.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_77"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_77" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_77")))
#endif

uint32_t FREG_VD_GetPbPcpuWorkAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBPCPUWORKADDR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PbPcpuWorkAddr" of register "PbPcpuWorkAddr".
**
** Parameter at Booting , start address of pcpu work address on ramif_s.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PbPcpuWorkAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_78"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_78" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_78")))
#endif

uint32_t FREG_VD_GetPbPcpuWorkAddr_PbPcpuWorkAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBPCPUWORKADDR));
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
** \brief Writes the entire register "PbPcpuWorkSize".
**
** This function writes the given value to the register "PbPcpuWorkSize".
**
** Parameter at Booting , size address of pcpu work address on ramif_s.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_79"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_79" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_79")))
#endif

void FREG_VD_SetPbPcpuWorkSize( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBPCPUWORKSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBPCPUWORKSIZE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PbPcpuWorkSize" of register "PbPcpuWorkSize".
**
** Parameter at Booting , size address of pcpu work address on ramif_s.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PbPcpuWorkSize" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_80"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_80" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_80")))
#endif

void FREG_VD_SetPbPcpuWorkSize_PbPcpuWorkSize( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PBPCPUWORKSIZE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBPCPUWORKSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBPCPUWORKSIZE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PbPcpuWorkSize".
**
** This function reads the value from the register "PbPcpuWorkSize".
**
** Parameter at Booting , size address of pcpu work address on ramif_s.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_81"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_81" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_81")))
#endif

uint32_t FREG_VD_GetPbPcpuWorkSize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBPCPUWORKSIZE));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PbPcpuWorkSize" of register "PbPcpuWorkSize".
**
** Parameter at Booting , size address of pcpu work address on ramif_s.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PbPcpuWorkSize" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_82"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_82" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_82")))
#endif

uint32_t FREG_VD_GetPbPcpuWorkSize_PbPcpuWorkSize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBPCPUWORKSIZE));
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
** \brief Writes the entire register "PbDecStartParamsAddr".
**
** This function writes the given value to the register "PbDecStartParamsAddr".
**
** Parameter at Booting , start address of Decoding start parameters on ramif_s.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_83"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_83" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_83")))
#endif

void FREG_VD_SetPbDecStartParamsAddr( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBDECSTARTPARAMSADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBDECSTARTPARAMSADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PbDecStartParamsAddr" of register "PbDecStartParamsAddr".
**
** Parameter at Booting , start address of Decoding start parameters on ramif_s.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PbDecStartParamsAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_84"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_84" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_84")))
#endif

void FREG_VD_SetPbDecStartParamsAddr_PbDecStartParamsAddr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PBDECSTARTPARAMSADDR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBDECSTARTPARAMSADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBDECSTARTPARAMSADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PbDecStartParamsAddr".
**
** This function reads the value from the register "PbDecStartParamsAddr".
**
** Parameter at Booting , start address of Decoding start parameters on ramif_s.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_85"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_85" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_85")))
#endif

uint32_t FREG_VD_GetPbDecStartParamsAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBDECSTARTPARAMSADDR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PbDecStartParamsAddr" of register "PbDecStartParamsAddr".
**
** Parameter at Booting , start address of Decoding start parameters on ramif_s.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PbDecStartParamsAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_86"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_86" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_86")))
#endif

uint32_t FREG_VD_GetPbDecStartParamsAddr_PbDecStartParamsAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBDECSTARTPARAMSADDR));
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
** \brief Writes the entire register "PbOutcomeOfDecodeAddr".
**
** This function writes the given value to the register "PbOutcomeOfDecodeAddr".
**
** Parameter at Booting , start address of Outcome of decode tables on ramif_s.
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_87"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_87" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_87")))
#endif

void FREG_VD_SetPbOutcomeOfDecodeAddr( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBOUTCOMEOFDECODEADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBOUTCOMEOFDECODEADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PbOutcomeOfDecodeAddr" of register "PbOutcomeOfDecodeAddr".
**
** Parameter at Booting , start address of Outcome of decode tables on ramif_s.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PbOutcomeOfDecodeAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_88"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_88" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_88")))
#endif

void FREG_VD_SetPbOutcomeOfDecodeAddr_PbOutcomeOfDecodeAddr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_PBOUTCOMEOFDECODEADDR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_PBOUTCOMEOFDECODEADDR, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_PBOUTCOMEOFDECODEADDR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PbOutcomeOfDecodeAddr".
**
** This function reads the value from the register "PbOutcomeOfDecodeAddr".
**
** Parameter at Booting , start address of Outcome of decode tables on ramif_s.
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_89"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_89" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_89")))
#endif

uint32_t FREG_VD_GetPbOutcomeOfDecodeAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBOUTCOMEOFDECODEADDR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PbOutcomeOfDecodeAddr" of register "PbOutcomeOfDecodeAddr".
**
** Parameter at Booting , start address of Outcome of decode tables on ramif_s.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PbOutcomeOfDecodeAddr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_90"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_90" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_90")))
#endif

uint32_t FREG_VD_GetPbOutcomeOfDecodeAddr_PbOutcomeOfDecodeAddr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_PBOUTCOMEOFDECODEADDR));
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
** \brief Writes the entire register "Status".
**
** This function writes the given value to the register "Status".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_91"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_91" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_91")))
#endif

void FREG_VD_SetStatus( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_STATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_STATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bsy" of register "Status".
**
** 0: AXIWRPP is IDLE
** 1: AXIWRPP is BUSY
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bsy" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_92"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_92" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_92")))
#endif

void FREG_VD_SetStatus_Bsy( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_STATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_STATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_STATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "En" of register "Status".
**
** 0: Disable AXIWRPP
** 1: Enable AXIWRPP
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "En" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_93"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_93" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_93")))
#endif

void FREG_VD_SetStatus_En( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_STATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_STATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_STATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rst" of register "Status".
**
** 0: Clear Command Reset
** 1: Set Command Reset
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rst" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_94"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_94" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_94")))
#endif

void FREG_VD_SetStatus_Rst( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_STATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_STATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_STATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Status".
**
** This function reads the value from the register "Status".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_95"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_95" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_95")))
#endif

uint32_t FREG_VD_GetStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_STATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bsy" of register "Status".
**
** 0: AXIWRPP is IDLE
** 1: AXIWRPP is BUSY
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bsy" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_96"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_96" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_96")))
#endif

uint32_t FREG_VD_GetStatus_Bsy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_STATUS));
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
** \brief Reads the bitgroup "En" of register "Status".
**
** 0: Disable AXIWRPP
** 1: Enable AXIWRPP
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "En" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_97"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_97" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_97")))
#endif

uint32_t FREG_VD_GetStatus_En( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_STATUS));
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
** \brief Reads the bitgroup "Rst" of register "Status".
**
** 0: Clear Command Reset
** 1: Set Command Reset
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rst" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_98"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_98" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_98")))
#endif

uint32_t FREG_VD_GetStatus_Rst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_STATUS));
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
** \brief Writes the entire register "BaseCc".
**
** This function writes the given value to the register "BaseCc".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_99"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_99" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_99")))
#endif

void FREG_VD_SetBaseCc( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECC, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECC)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseCc".
**
** COEF Compressed Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_100"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_100" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_100")))
#endif

void FREG_VD_SetBaseCc_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASECC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECC, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECC)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseCc".
**
** This function reads the value from the register "BaseCc".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_101"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_101" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_101")))
#endif

uint32_t FREG_VD_GetBaseCc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECC));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseCc".
**
** COEF Compressed Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_102"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_102" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_102")))
#endif

uint32_t FREG_VD_GetBaseCc_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECC));
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
** \brief Writes the entire register "BaseMw".
**
** This function writes the given value to the register "BaseMw".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_103"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_103" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_103")))
#endif

void FREG_VD_SetBaseMw( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEMW, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEMW)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseMw".
**
** MV Compressed Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_104"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_104" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_104")))
#endif

void FREG_VD_SetBaseMw_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEMW)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEMW, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEMW)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseMw".
**
** This function reads the value from the register "BaseMw".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_105"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_105" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_105")))
#endif

uint32_t FREG_VD_GetBaseMw( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEMW));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseMw".
**
** MV Compressed Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_106"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_106" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_106")))
#endif

uint32_t FREG_VD_GetBaseMw_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEMW));
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
** \brief Writes the entire register "BaseDv".
**
** This function writes the given value to the register "BaseDv".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_107"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_107" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_107")))
#endif

void FREG_VD_SetBaseDv( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEDV, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEDV)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseDv".
**
** Direct Vector Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_108"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_108" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_108")))
#endif

void FREG_VD_SetBaseDv_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEDV)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEDV, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEDV)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseDv".
**
** This function reads the value from the register "BaseDv".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_109"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_109" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_109")))
#endif

uint32_t FREG_VD_GetBaseDv( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEDV));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseDv".
**
** Direct Vector Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_110"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_110" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_110")))
#endif

uint32_t FREG_VD_GetBaseDv_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEDV));
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
** \brief Writes the entire register "BaseSeq".
**
** This function writes the given value to the register "BaseSeq".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_111"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_111" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_111")))
#endif

void FREG_VD_SetBaseSeq( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASESEQ, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASESEQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseSeq".
**
** SEQ DMA Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_112"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_112" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_112")))
#endif

void FREG_VD_SetBaseSeq_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASESEQ)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASESEQ, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASESEQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseSeq".
**
** This function reads the value from the register "BaseSeq".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_113"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_113" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_113")))
#endif

uint32_t FREG_VD_GetBaseSeq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASESEQ));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseSeq".
**
** SEQ DMA Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_114"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_114" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_114")))
#endif

uint32_t FREG_VD_GetBaseSeq_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASESEQ));
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
** \brief Writes the entire register "BaseStm".
**
** This function writes the given value to the register "BaseStm".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_115"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_115" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_115")))
#endif

void FREG_VD_SetBaseStm( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASESTM, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASESTM)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseStm".
**
** Video Stream Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_116"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_116" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_116")))
#endif

void FREG_VD_SetBaseStm_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASESTM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASESTM, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASESTM)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseStm".
**
** This function reads the value from the register "BaseStm".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_117"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_117" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_117")))
#endif

uint32_t FREG_VD_GetBaseStm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASESTM));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseStm".
**
** Video Stream Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_118"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_118" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_118")))
#endif

uint32_t FREG_VD_GetBaseStm_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASESTM));
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
** \brief Writes the entire register "BasePars".
**
** This function writes the given value to the register "BasePars".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_119"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_119" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_119")))
#endif

void FREG_VD_SetBasePars( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEPARS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEPARS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BasePars".
**
** Parser Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_120"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_120" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_120")))
#endif

void FREG_VD_SetBasePars_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEPARS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEPARS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEPARS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BasePars".
**
** This function reads the value from the register "BasePars".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_121"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_121" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_121")))
#endif

uint32_t FREG_VD_GetBasePars( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEPARS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BasePars".
**
** Parser Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_122"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_122" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_122")))
#endif

uint32_t FREG_VD_GetBasePars_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEPARS));
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
** \brief Writes the entire register "BaseVld".
**
** This function writes the given value to the register "BaseVld".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_123"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_123" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_123")))
#endif

void FREG_VD_SetBaseVld( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEVLD, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEVLD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseVld".
**
** VLD Table Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_124"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_124" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_124")))
#endif

void FREG_VD_SetBaseVld_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 16
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEVLD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEVLD, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEVLD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseVld".
**
** This function reads the value from the register "BaseVld".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_125"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_125" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_125")))
#endif

uint32_t FREG_VD_GetBaseVld( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEVLD));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseVld".
**
** VLD Table Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_126"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_126" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_126")))
#endif

uint32_t FREG_VD_GetBaseVld_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEVLD));
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
** \brief Writes the entire register "BaseCvec".
**
** This function writes the given value to the register "BaseCvec".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_127"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_127" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_127")))
#endif

void FREG_VD_SetBaseCvec( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECVEC, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECVEC)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseCvec".
**
** CVECTOR Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_128"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_128" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_128")))
#endif

void FREG_VD_SetBaseCvec_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASECVEC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECVEC, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECVEC)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseCvec".
**
** This function reads the value from the register "BaseCvec".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_129"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_129" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_129")))
#endif

uint32_t FREG_VD_GetBaseCvec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECVEC));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseCvec".
**
** CVECTOR Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_130"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_130" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_130")))
#endif

uint32_t FREG_VD_GetBaseCvec_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECVEC));
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
** \brief Writes the entire register "BaseCpred".
**
** This function writes the given value to the register "BaseCpred".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_131"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_131" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_131")))
#endif

void FREG_VD_SetBaseCpred( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECPRED, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECPRED)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseCpred".
**
** CPRED Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_132"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_132" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_132")))
#endif

void FREG_VD_SetBaseCpred_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASECPRED)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECPRED, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECPRED)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseCpred".
**
** This function reads the value from the register "BaseCpred".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_133"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_133" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_133")))
#endif

uint32_t FREG_VD_GetBaseCpred( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECPRED));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseCpred".
**
** CPRED Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_134"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_134" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_134")))
#endif

uint32_t FREG_VD_GetBaseCpred_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECPRED));
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
** \brief Writes the entire register "BaseCloop".
**
** This function writes the given value to the register "BaseCloop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_135"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_135" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_135")))
#endif

void FREG_VD_SetBaseCloop( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECLOOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECLOOP)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseCloop".
**
** CLOOPFILTER Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_136"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_136" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_136")))
#endif

void FREG_VD_SetBaseCloop_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASECLOOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECLOOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECLOOP)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseCloop".
**
** This function reads the value from the register "BaseCloop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_137"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_137" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_137")))
#endif

uint32_t FREG_VD_GetBaseCloop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECLOOP));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseCloop".
**
** CLOOPFILTER Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_138"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_138" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_138")))
#endif

uint32_t FREG_VD_GetBaseCloop_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECLOOP));
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
** \brief Writes the entire register "BaseCacdc".
**
** This function writes the given value to the register "BaseCacdc".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_139"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_139" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_139")))
#endif

void FREG_VD_SetBaseCacdc( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECACDC, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECACDC)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseCacdc".
**
** CACDCPRED Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_140"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_140" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_140")))
#endif

void FREG_VD_SetBaseCacdc_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASECACDC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASECACDC, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASECACDC)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseCacdc".
**
** This function reads the value from the register "BaseCacdc".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_141"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_141" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_141")))
#endif

uint32_t FREG_VD_GetBaseCacdc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECACDC));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseCacdc".
**
** CACDCPRED Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_142"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_142" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_142")))
#endif

uint32_t FREG_VD_GetBaseCacdc_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASECACDC));
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
** \brief Writes the entire register "BaseEvca".
**
** This function writes the given value to the register "BaseEvca".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_143"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_143" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_143")))
#endif

void FREG_VD_SetBaseEvca( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEEVCA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEEVCA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseEvca".
**
** CVECTOR Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_144"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_144" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_144")))
#endif

void FREG_VD_SetBaseEvca_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEEVCA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEEVCA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEEVCA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseEvca".
**
** This function reads the value from the register "BaseEvca".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_145"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_145" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_145")))
#endif

uint32_t FREG_VD_GetBaseEvca( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEEVCA));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseEvca".
**
** CVECTOR Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_146"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_146" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_146")))
#endif

uint32_t FREG_VD_GetBaseEvca_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEEVCA));
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
** \brief Writes the entire register "BaseEbca".
**
** This function writes the given value to the register "BaseEbca".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_147"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_147" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_147")))
#endif

void FREG_VD_SetBaseEbca( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEEBCA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEEBCA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseEbca".
**
** EBCABCA Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_148"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_148" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_148")))
#endif

void FREG_VD_SetBaseEbca_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEEBCA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEEBCA, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEEBCA)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseEbca".
**
** This function reads the value from the register "BaseEbca".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_149"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_149" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_149")))
#endif

uint32_t FREG_VD_GetBaseEbca( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEEBCA));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseEbca".
**
** EBCABCA Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_150"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_150" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_150")))
#endif

uint32_t FREG_VD_GetBaseEbca_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEEBCA));
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
** \brief Writes the entire register "BaseEpars".
**
** This function writes the given value to the register "BaseEpars".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_151"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_151" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_151")))
#endif

void FREG_VD_SetBaseEpars( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEEPARS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEEPARS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseEpars".
**
** EPARS Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_152"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_152" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_152")))
#endif

void FREG_VD_SetBaseEpars_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEEPARS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEEPARS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEEPARS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseEpars".
**
** This function reads the value from the register "BaseEpars".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_153"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_153" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_153")))
#endif

uint32_t FREG_VD_GetBaseEpars( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEEPARS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseEpars".
**
** EPARS Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_154"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_154" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_154")))
#endif

uint32_t FREG_VD_GetBaseEpars_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEEPARS));
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
** \brief Writes the entire register "BaseAxp".
**
** This function writes the given value to the register "BaseAxp".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_155"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_155" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_155")))
#endif

void FREG_VD_SetBaseAxp( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEAXP, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEAXP)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "BaseAxp".
**
** AXIWRPP MSB Base Address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_156"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_156" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_156")))
#endif

void FREG_VD_SetBaseAxp_Adr( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_BASEAXP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_BASEAXP, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_BASEAXP)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseAxp".
**
** This function reads the value from the register "BaseAxp".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_157"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_157" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_157")))
#endif

uint32_t FREG_VD_GetBaseAxp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEAXP));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "BaseAxp".
**
** AXIWRPP MSB Base Address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_158"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_158" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_158")))
#endif

uint32_t FREG_VD_GetBaseAxp_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_BASEAXP));
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
** \brief Writes the entire register "IrqStatus".
**
** This function writes the given value to the register "IrqStatus".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_159"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_159" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_159")))
#endif

void FREG_VD_SetIrqStatus( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ovf" of register "IrqStatus".
**
** Detect the Overflow of Request Address from MCIF
** can be cleared to write 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ovf" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_160"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_160" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_160")))
#endif

void FREG_VD_SetIrqStatus_Ovf( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Re" of register "IrqStatus".
**
** Detect  RRESP != OK
** can be cleared to write 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Re" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_161"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_161" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_161")))
#endif

void FREG_VD_SetIrqStatus_Re( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Be" of register "IrqStatus".
**
** Detect  BRESP != OK
** can be cleared to write 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Be" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_162"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_162" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_162")))
#endif

void FREG_VD_SetIrqStatus_Be( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqStatus".
**
** This function reads the value from the register "IrqStatus".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_163"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_163" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_163")))
#endif

uint32_t FREG_VD_GetIrqStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQSTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ovf" of register "IrqStatus".
**
** Detect the Overflow of Request Address from MCIF
** can be cleared to write 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ovf" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_164"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_164" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_164")))
#endif

uint32_t FREG_VD_GetIrqStatus_Ovf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQSTATUS));
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
** \brief Reads the bitgroup "Re" of register "IrqStatus".
**
** Detect  RRESP != OK
** can be cleared to write 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Re" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_165"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_165" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_165")))
#endif

uint32_t FREG_VD_GetIrqStatus_Re( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQSTATUS));
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
** \brief Reads the bitgroup "Be" of register "IrqStatus".
**
** Detect  BRESP != OK
** can be cleared to write 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Be" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_166"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_166" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_166")))
#endif

uint32_t FREG_VD_GetIrqStatus_Be( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQSTATUS));
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
** \brief Writes the entire register "IrqEnable".
**
** This function writes the given value to the register "IrqEnable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_167"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_167" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_167")))
#endif

void FREG_VD_SetIrqEnable( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ovf" of register "IrqEnable".
**
** Enable Interrutp Assertion by IRQ_STATUS.
** OVF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ovf" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_168"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_168" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_168")))
#endif

void FREG_VD_SetIrqEnable_Ovf( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_IRQENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Re" of register "IrqEnable".
**
** Enable Interrutp Assertion by IRQ_STATUS.
** RE
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Re" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_169"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_169" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_169")))
#endif

void FREG_VD_SetIrqEnable_Re( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_IRQENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Be" of register "IrqEnable".
**
** Enable Interrutp Assertion by IRQ_STATUS.
** BE
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Be" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_170"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_170" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_170")))
#endif

void FREG_VD_SetIrqEnable_Be( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_IRQENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_IRQENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_IRQENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqEnable".
**
** This function reads the value from the register "IrqEnable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_171"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_171" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_171")))
#endif

uint32_t FREG_VD_GetIrqEnable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQENABLE));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ovf" of register "IrqEnable".
**
** Enable Interrutp Assertion by IRQ_STATUS.
** OVF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ovf" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_172"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_172" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_172")))
#endif

uint32_t FREG_VD_GetIrqEnable_Ovf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQENABLE));
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
** \brief Reads the bitgroup "Re" of register "IrqEnable".
**
** Enable Interrutp Assertion by IRQ_STATUS.
** RE
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Re" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_173"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_173" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_173")))
#endif

uint32_t FREG_VD_GetIrqEnable_Re( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQENABLE));
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
** \brief Reads the bitgroup "Be" of register "IrqEnable".
**
** Enable Interrutp Assertion by IRQ_STATUS.
** BE
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Be" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_174"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_174" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_174")))
#endif

uint32_t FREG_VD_GetIrqEnable_Be( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_IRQENABLE));
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
** \brief Reads the entire register "Erbsadrl".
**
** This function reads the value from the register "Erbsadrl".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_175"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_175" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_175")))
#endif

uint32_t FREG_VD_GetErbsadrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERBSADRL));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Eadrl" of register "Erbsadrl".
**
** Save the address[15:3] which asserts IRQ_STATUS.
** BE
** (it is available only when ENMRI == 0)
** When the error occurs two or more times, the last result is preserved.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Eadrl" consists of the bits 15..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x0000FFF8UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_176"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_176" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_176")))
#endif

uint32_t FREG_VD_GetErbsadrl_Eadrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERBSADRL));
    value = ( value & 0x0000FFF8UL ) >> 3;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Erbsadru".
**
** This function reads the value from the register "Erbsadru".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_177"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_177" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_177")))
#endif

uint32_t FREG_VD_GetErbsadru( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERBSADRU));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Eadru" of register "Erbsadru".
**
** Save the address[31:16] which asserts IRQ_STATUS.
** BE
** (it is available only when ENMRI == 0)
** When the error occurs two or more times, the last result is preserved.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Eadru" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_178"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_178" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_178")))
#endif

uint32_t FREG_VD_GetErbsadru_Eadru( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERBSADRU));
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
** \brief Reads the entire register "Errsadrl".
**
** This function reads the value from the register "Errsadrl".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_179"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_179" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_179")))
#endif

uint32_t FREG_VD_GetErrsadrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERRSADRL));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Eadrl" of register "Errsadrl".
**
** Save the address[15:3] which asserts IRQ_STATUS.
** RE
** (it is available only when ENMRI == 0)
** When the error occurs two or more times, the last result is preserved.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Eadrl" consists of the bits 15..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x0000FFF8UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_180"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_180" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_180")))
#endif

uint32_t FREG_VD_GetErrsadrl_Eadrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERRSADRL));
    value = ( value & 0x0000FFF8UL ) >> 3;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Errsadru".
**
** This function reads the value from the register "Errsadru".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_181"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_181" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_181")))
#endif

uint32_t FREG_VD_GetErrsadru( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERRSADRU));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Eadru" of register "Errsadru".
**
** Save the address[31:16] which asserts IRQ_STATUS.
** RE
** (it is available only when ENMRI == 0)
** When the error occurs two or more times, the last result is preserved.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Eadru" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_182"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_182" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_182")))
#endif

uint32_t FREG_VD_GetErrsadru_Eadru( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_ERRSADRU));
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
** \brief Writes the entire register "WrpConfig".
**
** This function writes the given value to the register "WrpConfig".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_183"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_183" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_183")))
#endif

void FREG_VD_SetWrpConfig( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_WRPCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enmri" of register "WrpConfig".
**
** Enable Multiple Request Issuing
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enmri" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_184"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_184" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_184")))
#endif

void FREG_VD_SetWrpConfig_Enmri( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_WRPCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Nsr" of register "WrpConfig".
**
** (No byte Swap Read)  Execute AXI READ without byte swap
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Nsr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_185"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_185" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_185")))
#endif

void FREG_VD_SetWrpConfig_Nsr( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_WRPCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Nsw" of register "WrpConfig".
**
** (No byte Swap Write)  Execute AXI WRITE without byte swap
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Nsw" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_186"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_186" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_186")))
#endif

void FREG_VD_SetWrpConfig_Nsw( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_WRPCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_WRPCONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WrpConfig".
**
** This function reads the value from the register "WrpConfig".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_187"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_187" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_187")))
#endif

uint32_t FREG_VD_GetWrpConfig( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_WRPCONFIG));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enmri" of register "WrpConfig".
**
** Enable Multiple Request Issuing
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enmri" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_188"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_188" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_188")))
#endif

uint32_t FREG_VD_GetWrpConfig_Enmri( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_WRPCONFIG));
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
** \brief Reads the bitgroup "Nsr" of register "WrpConfig".
**
** (No byte Swap Read)  Execute AXI READ without byte swap
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Nsr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_189"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_189" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_189")))
#endif

uint32_t FREG_VD_GetWrpConfig_Nsr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_WRPCONFIG));
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
** \brief Reads the bitgroup "Nsw" of register "WrpConfig".
**
** (No byte Swap Write)  Execute AXI WRITE without byte swap
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Nsw" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_190"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_190" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_190")))
#endif

uint32_t FREG_VD_GetWrpConfig_Nsw( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_WRPCONFIG));
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
** \brief Reads the entire register "Version".
**
** This function reads the value from the register "Version".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_191"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_191" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_191")))
#endif

uint32_t FREG_VD_GetVersion( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_VERSION));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Version" of register "Version".
**
** VERSION ID register
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Version" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_192"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_192" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_192")))
#endif

uint32_t FREG_VD_GetVersion_Version( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_VERSION));
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
** \brief Writes the entire register "Dummy".
**
** This function writes the given value to the register "Dummy".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_193"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_193" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_193")))
#endif

void FREG_VD_SetDummy( uint32_t value )
{
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_DUMMY, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_DUMMY)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dummy" of register "Dummy".
**
** DUMMY register for EC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dummy" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_194"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_194" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_194")))
#endif

void FREG_VD_SetDummy_Dummy( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VD_DUMMY)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VD_ENABLE_DEBUG_PRINT == 1
        FREG_VD_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VD", FREG_VD_DUMMY, value );
    #endif
    *((volatile uint32_t*)(FREG_VD_DUMMY)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dummy".
**
** This function reads the value from the register "Dummy".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_195"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_195" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_195")))
#endif

uint32_t FREG_VD_GetDummy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_DUMMY));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dummy" of register "Dummy".
**
** DUMMY register for EC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dummy" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_VD_196"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_VD_196" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_VD_196")))
#endif

uint32_t FREG_VD_GetDummy_Dummy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VD_DUMMY));
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


#if 0
void FREG_VD_Write32( uint32_t address, uint32_t value )
{
    *((volatile uint32_t*)(FIO_ADDRESS(VD,address))) = value;
}

uint32_t FREG_VD_Read32( uint32_t address )
{
    return(*((volatile uint32_t*)(FIO_ADDRESS(VD,address))));
}
#endif


/*!
********************************************************************************
**
** \brief Initializes the "VD" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_VD_Init( void )
{
    FREG_VD_IntReqToPcpuMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
    FREG_VD_IntReqToMcpuMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
    FREG_VD_IntClearToMcpuMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
}
