/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_clkpwr.h
**
** \brief     CLKPWR access functions
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
#if !defined(FREG_CLKPWR_H)
#define FREG_CLKPWR_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_CLKPWR_ENABLE_DEBUG_PRINT   0
#define FREG_CLKPWR_DEBUG_PRINT_FUNCTION printf

#if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_CLKPWR_CLK324ENABLE                 FIO_ADDRESS(CLKPWR,0xCA000000UL)
#define FREG_CLKPWR_CLK162ENABLE                 FIO_ADDRESS(CLKPWR,0xCA000004UL)
#define FREG_CLKPWR_CLK81ENABLE                  FIO_ADDRESS(CLKPWR,0xCA000008UL)
#define FREG_CLKPWR_CLK54ENABLE                  FIO_ADDRESS(CLKPWR,0xCA00000CUL)
#define FREG_CLKPWR_SOFTRESET162                 FIO_ADDRESS(CLKPWR,0xCA000018UL)
#define FREG_CLKPWR_SOFTRESET54                  FIO_ADDRESS(CLKPWR,0xCA000024UL)
#define FREG_CLKPWR_FD2DELTA                     FIO_ADDRESS(CLKPWR,0xCA000028UL)
#define FREG_CLKPWR_FD2DIFFDELTA                 FIO_ADDRESS(CLKPWR,0xCA00002CUL)
#define FREG_CLKPWR_FD2MODTRESH                  FIO_ADDRESS(CLKPWR,0xCA000030UL)
#define FREG_CLKPWR_DACCLKSELECT                 FIO_ADDRESS(CLKPWR,0xCA000034UL)
#define FREG_CLKPWR_WATCHDOG                     FIO_ADDRESS(CLKPWR,0xCA00003CUL)
#define FREG_CLKPWR_FDCLKSEL                     FIO_ADDRESS(CLKPWR,0xCA000040UL)
#define FREG_CLKPWR_PLLCLKSEL                    FIO_ADDRESS(CLKPWR,0xCA000044UL)
#define FREG_CLKPWR_FDPRESCALE                   FIO_ADDRESS(CLKPWR,0xCA000050UL)
#define FREG_CLKPWR_FD0AUDIO                     FIO_ADDRESS(CLKPWR,0xCA000054UL)
#define FREG_CLKPWR_FD1AUDIO                     FIO_ADDRESS(CLKPWR,0xCA000058UL)
#define FREG_CLKPWR_DPLLDIVCOUNTHDMI             FIO_ADDRESS(CLKPWR,0xCA000060UL)
#define FREG_CLKPWR_DPLLDIVCOUNTFD1              FIO_ADDRESS(CLKPWR,0xCA000064UL)
#define FREG_CLKPWR_DPLLDIVCOUNTFD2              FIO_ADDRESS(CLKPWR,0xCA000068UL)
#define FREG_CLKPWR_CONFIGARM                    FIO_ADDRESS(CLKPWR,0xCA000070UL)
#define FREG_CLKPWR_DPLLDIVCOUNTFD3              FIO_ADDRESS(CLKPWR,0xCA00006CUL)
#define FREG_CLKPWR_CONFIGVO                     FIO_ADDRESS(CLKPWR,0xCA000078UL)
#define FREG_CLKPWR_SOFTRESET81                  FIO_ADDRESS(CLKPWR,0xCA00001CUL)
#define FREG_CLKPWR_DPLLCONFIG                   FIO_ADDRESS(CLKPWR,0xCA00004CUL)
#define FREG_CLKPWR_FD2AUDIO                     FIO_ADDRESS(CLKPWR,0xCA00005CUL)
#define FREG_CLKPWR_CONFIGDMACAUDIO              FIO_ADDRESS(CLKPWR,0xCA000074UL)
#define FREG_CLKPWR_CONFIGVD                     FIO_ADDRESS(CLKPWR,0xCA00007CUL)

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
** \brief Writes the entire register "Clk324enable".
**
** This function writes the given value to the register "Clk324enable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk324enable( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk324enable( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK324ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK324ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk324DdrEn" of register "Clk324enable".
**
** enable signal for clk to DDR IF V
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk324DdrEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk324enable_Clk324DdrEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk324enable_Clk324DdrEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK324ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK324ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK324ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Clk324enable".
**
** This function reads the value from the register "Clk324enable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk324enable( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk324enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK324ENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk324DdrEn" of register "Clk324enable".
**
** enable signal for clk to DDR IF V
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk324DdrEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk324enable_Clk324DdrEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk324enable_Clk324DdrEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK324ENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Clk162enable".
**
** This function writes the given value to the register "Clk162enable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk162enable( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk162enable( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK162ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk162UpiEn" of register "Clk162enable".
**
** enable signal for clk UPI IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk162UpiEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk162enable_Clk162UpiEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk162enable_Clk162UpiEn( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK162ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk162DdrEn" of register "Clk162enable".
**
** enable signal for clk DDR IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk162DdrEn" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk162enable_Clk162DdrEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk162enable_Clk162DdrEn( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK162ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk162AxiEn" of register "Clk162enable".
**
** enable signal for clk AXI IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk162AxiEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk162enable_Clk162AxiEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk162enable_Clk162AxiEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK162ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Clk162enable".
**
** This function reads the value from the register "Clk162enable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk162enable( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk162enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk162UpiEn" of register "Clk162enable".
**
** enable signal for clk UPI IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk162UpiEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk162enable_Clk162UpiEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk162enable_Clk162UpiEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk162DdrEn" of register "Clk162enable".
**
** enable signal for clk DDR IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk162DdrEn" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk162enable_Clk162DdrEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk162enable_Clk162DdrEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk162AxiEn" of register "Clk162enable".
**
** enable signal for clk AXI IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk162AxiEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk162enable_Clk162AxiEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk162enable_Clk162AxiEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK162ENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Clk81enable".
**
** This function writes the given value to the register "Clk81enable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81SflashEn" of register "Clk81enable".
**
** clock enable for SFLASH
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81SflashEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81SflashEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81SflashEn( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81SspEn" of register "Clk81enable".
**
** clock enable for both SSP
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81SspEn" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81SspEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81SspEn( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81FpcEn" of register "Clk81enable".
**
** clock enable for FPC and UART_0 AND UART_1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81FpcEn" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81FpcEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81FpcEn( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81Iic2En" of register "Clk81enable".
**
** clock enable for IIC_2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81Iic2En" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81Iic2En( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81Iic2En( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81IicEn" of register "Clk81enable".
**
** clock enable for IIC_0, IIC_1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81IicEn" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81IicEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81IicEn( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81IccEn" of register "Clk81enable".
**
** clock enable for ICC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81IccEn" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81IccEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81IccEn( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81GpioEn" of register "Clk81enable".
**
** clock enable for GPIO
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81GpioEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81GpioEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81GpioEn( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81PeriEn" of register "Clk81enable".
**
** clock enable for IRQ control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81PeriEn" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81PeriEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81PeriEn( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk81AxiEn" of register "Clk81enable".
**
** clock enable for AXI bus and SDRAM
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk81AxiEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk81enable_Clk81AxiEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk81enable_Clk81AxiEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK81ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Clk81enable".
**
** This function reads the value from the register "Clk81enable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81SflashEn" of register "Clk81enable".
**
** clock enable for SFLASH
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81SflashEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81SflashEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81SflashEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81SspEn" of register "Clk81enable".
**
** clock enable for both SSP
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81SspEn" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81SspEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81SspEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81FpcEn" of register "Clk81enable".
**
** clock enable for FPC and UART_0 AND UART_1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81FpcEn" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81FpcEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81FpcEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81Iic2En" of register "Clk81enable".
**
** clock enable for IIC_2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81Iic2En" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81Iic2En( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81Iic2En( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81IicEn" of register "Clk81enable".
**
** clock enable for IIC_0, IIC_1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81IicEn" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81IicEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81IicEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81IccEn" of register "Clk81enable".
**
** clock enable for ICC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81IccEn" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81IccEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81IccEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81GpioEn" of register "Clk81enable".
**
** clock enable for GPIO
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81GpioEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81GpioEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81GpioEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81PeriEn" of register "Clk81enable".
**
** clock enable for IRQ control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81PeriEn" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81PeriEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81PeriEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk81AxiEn" of register "Clk81enable".
**
** clock enable for AXI bus and SDRAM
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk81AxiEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk81enable_Clk81AxiEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk81enable_Clk81AxiEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK81ENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Clk54enable".
**
** This function writes the given value to the register "Clk54enable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk54enable( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk54enable( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK54ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk54En" of register "Clk54enable".
**
** enable signal for 54MHz clk
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk54En" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk54enable_Clk54En( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk54enable_Clk54En( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK54ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk27En" of register "Clk54enable".
**
** enable signal for 27MHz clk
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk27En" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetClk54enable_Clk27En( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetClk54enable_Clk27En( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CLK54ENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Clk54enable".
**
** This function reads the value from the register "Clk54enable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk54enable( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk54enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk54En" of register "Clk54enable".
**
** enable signal for 54MHz clk
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk54En" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk54enable_Clk54En( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk54enable_Clk54En( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk27En" of register "Clk54enable".
**
** enable signal for 27MHz clk
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk27En" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetClk54enable_Clk27En( void );
#else
INLINE uint32_t FREG_CLKPWR_GetClk54enable_Clk27En( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CLK54ENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Softreset162".
**
** This function writes the given value to the register "Softreset162".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset162( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset162( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET162, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetSdram1621" of register "Softreset162".
**
** reset of 162 MHz registers in top_SDRAM (logic)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetSdram1621" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset162_ResetSdram1621( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset162_ResetSdram1621( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET162, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetUpi" of register "Softreset162".
**
** reset of UPI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetUpi" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset162_ResetUpi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset162_ResetUpi( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET162, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetSdram1622" of register "Softreset162".
**
** reset of 162 MHz registers in top_SDRAM
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetSdram1622" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset162_ResetSdram1622( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset162_ResetSdram1622( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET162, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetAxi162" of register "Softreset162".
**
** reset of 162 MHz registers in AXI IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetAxi162" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset162_ResetAxi162( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset162_ResetAxi162( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET162, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Softreset162".
**
** This function reads the value from the register "Softreset162".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset162( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset162( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetSdram1621" of register "Softreset162".
**
** reset of 162 MHz registers in top_SDRAM (logic)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetSdram1621" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset162_ResetSdram1621( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset162_ResetSdram1621( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetUpi" of register "Softreset162".
**
** reset of UPI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetUpi" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset162_ResetUpi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset162_ResetUpi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetSdram1622" of register "Softreset162".
**
** reset of 162 MHz registers in top_SDRAM
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetSdram1622" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset162_ResetSdram1622( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset162_ResetSdram1622( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetAxi162" of register "Softreset162".
**
** reset of 162 MHz registers in AXI IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetAxi162" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset162_ResetAxi162( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset162_ResetAxi162( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET162));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Softreset54".
**
** This function writes the given value to the register "Softreset54".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset54( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset54( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET54, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetHdmi" of register "Softreset54".
**
** reset of HDMI (all 74.
** 25 MHz registers)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetHdmi" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset54_ResetHdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset54_ResetHdmi( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET54, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetVe" of register "Softreset54".
**
** reset of VE (all 54 MHz registers)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetVe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset54_ResetVe( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset54_ResetVe( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET54, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Softreset54".
**
** This function reads the value from the register "Softreset54".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset54( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset54( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetHdmi" of register "Softreset54".
**
** reset of HDMI (all 74.
** 25 MHz registers)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetHdmi" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset54_ResetHdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset54_ResetHdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetVe" of register "Softreset54".
**
** reset of VE (all 54 MHz registers)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetVe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset54_ResetVe( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset54_ResetVe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET54));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fd2delta".
**
** This function writes the given value to the register "Fd2delta".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2delta( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2delta( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2DELTA, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2DELTA)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2delta" of register "Fd2delta".
**
** FD2 delta value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2delta" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2delta_Fd2delta( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2delta_Fd2delta( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2DELTA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2DELTA, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2DELTA)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fd2delta".
**
** This function reads the value from the register "Fd2delta".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2delta( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2delta( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2DELTA));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2delta" of register "Fd2delta".
**
** FD2 delta value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2delta" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2delta_Fd2delta( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2delta_Fd2delta( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2DELTA));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fd2diffdelta".
**
** This function writes the given value to the register "Fd2diffdelta".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2diffdelta( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2diffdelta( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2DIFFDELTA, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2DIFFDELTA)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2diffdelta" of register "Fd2diffdelta".
**
** FD2 diff delta value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2diffdelta" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2diffdelta_Fd2diffdelta( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2diffdelta_Fd2diffdelta( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2DIFFDELTA)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2DIFFDELTA, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2DIFFDELTA)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fd2diffdelta".
**
** This function reads the value from the register "Fd2diffdelta".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2diffdelta( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2diffdelta( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2DIFFDELTA));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2diffdelta" of register "Fd2diffdelta".
**
** FD2 diff delta value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2diffdelta" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2diffdelta_Fd2diffdelta( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2diffdelta_Fd2diffdelta( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2DIFFDELTA));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fd2modtresh".
**
** This function writes the given value to the register "Fd2modtresh".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2modtresh( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2modtresh( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2MODTRESH, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2MODTRESH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2modtresh" of register "Fd2modtresh".
**
** FD2 modulo treshold value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2modtresh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2modtresh_Fd2modtresh( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2modtresh_Fd2modtresh( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2MODTRESH)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2MODTRESH, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2MODTRESH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fd2modtresh".
**
** This function reads the value from the register "Fd2modtresh".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2modtresh( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2modtresh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2MODTRESH));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2modtresh" of register "Fd2modtresh".
**
** FD2 modulo treshold value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2modtresh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2modtresh_Fd2modtresh( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2modtresh_Fd2modtresh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2MODTRESH));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dacclkselect".
**
** This function writes the given value to the register "Dacclkselect".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDacclkselect( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDacclkselect( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DACCLKSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dac2Clksel" of register "Dacclkselect".
**
** clk select for DAC2, 0 = HDMI_clk, 1 = 54MHz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dac2Clksel" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDacclkselect_Dac2Clksel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDacclkselect_Dac2Clksel( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DACCLKSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dac1Clksel" of register "Dacclkselect".
**
** clk select for DAC1, 0 = HDMI_clk, 1 = 54MHz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dac1Clksel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDacclkselect_Dac1Clksel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDacclkselect_Dac1Clksel( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DACCLKSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dac0Clksel" of register "Dacclkselect".
**
** clk select for DAC0, 0 = HDMI_clk, 1 = 54MHz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dac0Clksel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDacclkselect_Dac0Clksel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDacclkselect_Dac0Clksel( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DACCLKSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dacclkselect".
**
** This function reads the value from the register "Dacclkselect".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDacclkselect( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDacclkselect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dac2Clksel" of register "Dacclkselect".
**
** clk select for DAC2, 0 = HDMI_clk, 1 = 54MHz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dac2Clksel" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDacclkselect_Dac2Clksel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDacclkselect_Dac2Clksel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dac1Clksel" of register "Dacclkselect".
**
** clk select for DAC1, 0 = HDMI_clk, 1 = 54MHz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dac1Clksel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDacclkselect_Dac1Clksel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDacclkselect_Dac1Clksel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dac0Clksel" of register "Dacclkselect".
**
** clk select for DAC0, 0 = HDMI_clk, 1 = 54MHz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dac0Clksel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDacclkselect_Dac0Clksel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDacclkselect_Dac0Clksel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DACCLKSELECT));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Watchdog".
**
** This function writes the given value to the register "Watchdog".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetWatchdog( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetWatchdog( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_WATCHDOG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_WATCHDOG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Watchdog" of register "Watchdog".
**
** watchdog value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Watchdog" consists of the bits 27..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x0FFFF000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetWatchdog_Watchdog( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetWatchdog_Watchdog( uint32_t value )
{
    register uint32_t mask = 0x0FFFF000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_WATCHDOG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_WATCHDOG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_WATCHDOG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Watchdog".
**
** This function reads the value from the register "Watchdog".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetWatchdog( void );
#else
INLINE uint32_t FREG_CLKPWR_GetWatchdog( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_WATCHDOG));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Watchdog" of register "Watchdog".
**
** watchdog value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Watchdog" consists of the bits 27..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x0FFFF000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetWatchdog_Watchdog( void );
#else
INLINE uint32_t FREG_CLKPWR_GetWatchdog_Watchdog( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_WATCHDOG));
    value = ( value & 0x0FFFF000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fdclksel".
**
** This function writes the given value to the register "Fdclksel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Plloutdivider" of register "Fdclksel".
**
** Output divider of PLL macro, needs to be always set to default value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Plloutdivider" consists of the bits 28..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x1F000000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_Plloutdivider( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_Plloutdivider( uint32_t value )
{
    register uint32_t mask = 0x1F000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pllfbdivider" of register "Fdclksel".
**
** FB divider of PLL macro, needs to be always set to default value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pllfbdivider" consists of the bits 20..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x001F0000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_Pllfbdivider( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_Pllfbdivider( uint32_t value )
{
    register uint32_t mask = 0x001F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmidivider" of register "Fdclksel".
**
** Output divider of HDMI clock generation.
**  (HDMIDIVIDER+1)*2 gives the division ratio of the 594MHz clock.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmidivider" consists of the bits 12..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00001F00UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_Hdmidivider( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_Hdmidivider( uint32_t value )
{
    register uint32_t mask = 0x00001F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClkHdmiEn" of register "Fdclksel".
**
** enables HDMI clock generation
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClkHdmiEn" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_ClkHdmiEn( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_ClkHdmiEn( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Selfd1clk" of register "Fdclksel".
**
** switches between old FD1(108MHz) and new FD1(1296MHz)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Selfd1clk" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_Selfd1clk( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_Selfd1clk( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Selfd2clk" of register "Fdclksel".
**
** switches between old FD2(108MHz) and new FD2(1296MHz)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Selfd2clk" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_Selfd2clk( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_Selfd2clk( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Div648" of register "Fdclksel".
**
** output divider of clock generation module                           00 = PLL clock not divided (normal mode)                                                 01 = divide by 2                                                              10 = divide by 4                                                              11 = divide by 16                                                             note: this will affect all clocks in the system except HDMI clock and FD clocks
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Div648" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdclksel_Div648( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdclksel_Div648( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fdclksel".
**
** This function reads the value from the register "Fdclksel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Plloutdivider" of register "Fdclksel".
**
** Output divider of PLL macro, needs to be always set to default value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Plloutdivider" consists of the bits 28..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x1F000000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_Plloutdivider( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_Plloutdivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x1F000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pllfbdivider" of register "Fdclksel".
**
** FB divider of PLL macro, needs to be always set to default value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pllfbdivider" consists of the bits 20..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x001F0000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_Pllfbdivider( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_Pllfbdivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x001F0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmidivider" of register "Fdclksel".
**
** Output divider of HDMI clock generation.
**  (HDMIDIVIDER+1)*2 gives the division ratio of the 594MHz clock.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmidivider" consists of the bits 12..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00001F00UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_Hdmidivider( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_Hdmidivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x00001F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClkHdmiEn" of register "Fdclksel".
**
** enables HDMI clock generation
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClkHdmiEn" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_ClkHdmiEn( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_ClkHdmiEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Selfd1clk" of register "Fdclksel".
**
** switches between old FD1(108MHz) and new FD1(1296MHz)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Selfd1clk" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_Selfd1clk( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_Selfd1clk( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Selfd2clk" of register "Fdclksel".
**
** switches between old FD2(108MHz) and new FD2(1296MHz)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Selfd2clk" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_Selfd2clk( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_Selfd2clk( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Div648" of register "Fdclksel".
**
** output divider of clock generation module                           00 = PLL clock not divided (normal mode)                                                 01 = divide by 2                                                              10 = divide by 4                                                              11 = divide by 16                                                             note: this will affect all clocks in the system except HDMI clock and FD clocks
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Div648" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdclksel_Div648( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdclksel_Div648( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDCLKSEL));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Pllclksel".
**
** This function writes the given value to the register "Pllclksel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetPllclksel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetPllclksel( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_PLLCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Secondpllsync" of register "Pllclksel".
**
** signals which clk is currently used (if switch occurred)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Secondpllsync" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetPllclksel_Secondpllsync( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetPllclksel_Secondpllsync( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_PLLCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Secondpllautoswitch" of register "Pllclksel".
**
** auto switch enable (input clock is switched at minimum input phase difference)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Secondpllautoswitch" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetPllclksel_Secondpllautoswitch( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetPllclksel_Secondpllautoswitch( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_PLLCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Secondclksel" of register "Pllclksel".
**
** switches to the second 27MHz clock input
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Secondclksel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetPllclksel_Secondclksel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetPllclksel_Secondclksel( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_PLLCLKSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Pllclksel".
**
** This function reads the value from the register "Pllclksel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetPllclksel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetPllclksel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Secondpllsync" of register "Pllclksel".
**
** signals which clk is currently used (if switch occurred)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Secondpllsync" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetPllclksel_Secondpllsync( void );
#else
INLINE uint32_t FREG_CLKPWR_GetPllclksel_Secondpllsync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Secondpllautoswitch" of register "Pllclksel".
**
** auto switch enable (input clock is switched at minimum input phase difference)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Secondpllautoswitch" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetPllclksel_Secondpllautoswitch( void );
#else
INLINE uint32_t FREG_CLKPWR_GetPllclksel_Secondpllautoswitch( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Secondclksel" of register "Pllclksel".
**
** switches to the second 27MHz clock input
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Secondclksel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetPllclksel_Secondclksel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetPllclksel_Secondclksel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_PLLCLKSEL));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fdprescale".
**
** This function writes the given value to the register "Fdprescale".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdprescale( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdprescale( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDPRESCALE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd3divider" of register "Fdprescale".
**
** divider on FD3 clock output (div*2 = actual divide value)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd3divider" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdprescale_Fd3divider( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdprescale_Fd3divider( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDPRESCALE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2divider" of register "Fdprescale".
**
** divider on FD2 clock output (div*2 = actual divide value)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2divider" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdprescale_Fd2divider( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdprescale_Fd2divider( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDPRESCALE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd1divider" of register "Fdprescale".
**
** divider on FD1 clock output (div*2 = actual divide value)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd1divider" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdprescale_Fd1divider( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdprescale_Fd1divider( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDPRESCALE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Audiosrate" of register "Fdprescale".
**
** sample rate setting for 108MHz audio clock generation
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Audiosrate" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFdprescale_Audiosrate( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFdprescale_Audiosrate( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FDPRESCALE, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fdprescale".
**
** This function reads the value from the register "Fdprescale".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdprescale( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdprescale( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd3divider" of register "Fdprescale".
**
** divider on FD3 clock output (div*2 = actual divide value)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd3divider" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdprescale_Fd3divider( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdprescale_Fd3divider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2divider" of register "Fdprescale".
**
** divider on FD2 clock output (div*2 = actual divide value)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2divider" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdprescale_Fd2divider( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdprescale_Fd2divider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd1divider" of register "Fdprescale".
**
** divider on FD1 clock output (div*2 = actual divide value)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd1divider" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdprescale_Fd1divider( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdprescale_Fd1divider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Audiosrate" of register "Fdprescale".
**
** sample rate setting for 108MHz audio clock generation
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Audiosrate" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFdprescale_Audiosrate( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFdprescale_Audiosrate( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FDPRESCALE));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fd0audio".
**
** This function writes the given value to the register "Fd0audio".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd0audio( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd0audio( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD0AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetFd0" of register "Fd0audio".
**
** resets the FD1 clock generator
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetFd0" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd0audio_ResetFd0( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd0audio_ResetFd0( uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    value = ( value << 31 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD0AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd0rest" of register "Fd0audio".
**
** rest of integer division FD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd0rest" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd0audio_Fd0rest( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd0audio_Fd0rest( uint32_t value )
{
    register uint32_t mask = 0x3FF00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD0AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd0modulo" of register "Fd0audio".
**
** modulo value for FD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd0modulo" consists of the bits 17..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0003FF00UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd0audio_Fd0modulo( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd0audio_Fd0modulo( uint32_t value )
{
    register uint32_t mask = 0x0003FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD0AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd0muxsel" of register "Fd0audio".
**
** integer part divider FD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd0muxsel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd0audio_Fd0muxsel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd0audio_Fd0muxsel( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD0AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fd0audio".
**
** This function reads the value from the register "Fd0audio".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd0audio( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd0audio( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetFd0" of register "Fd0audio".
**
** resets the FD1 clock generator
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetFd0" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd0audio_ResetFd0( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd0audio_ResetFd0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO));
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd0rest" of register "Fd0audio".
**
** rest of integer division FD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd0rest" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd0audio_Fd0rest( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd0audio_Fd0rest( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO));
    value = ( value & 0x3FF00000UL ) >> 20;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd0modulo" of register "Fd0audio".
**
** modulo value for FD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd0modulo" consists of the bits 17..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0003FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd0audio_Fd0modulo( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd0audio_Fd0modulo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO));
    value = ( value & 0x0003FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd0muxsel" of register "Fd0audio".
**
** integer part divider FD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd0muxsel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd0audio_Fd0muxsel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd0audio_Fd0muxsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD0AUDIO));
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fd1audio".
**
** This function writes the given value to the register "Fd1audio".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd1audio( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd1audio( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD1AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetFd1" of register "Fd1audio".
**
** resets the FD2 clock generator
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetFd1" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd1audio_ResetFd1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd1audio_ResetFd1( uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    value = ( value << 31 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD1AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd1rest" of register "Fd1audio".
**
** rest of integer division FD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd1rest" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd1audio_Fd1rest( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd1audio_Fd1rest( uint32_t value )
{
    register uint32_t mask = 0x3FF00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD1AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd1modulo" of register "Fd1audio".
**
** modulo value for FD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd1modulo" consists of the bits 17..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0003FF00UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd1audio_Fd1modulo( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd1audio_Fd1modulo( uint32_t value )
{
    register uint32_t mask = 0x0003FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD1AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd1muxsel" of register "Fd1audio".
**
** integer part divider FD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd1muxsel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd1audio_Fd1muxsel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd1audio_Fd1muxsel( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD1AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fd1audio".
**
** This function reads the value from the register "Fd1audio".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd1audio( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd1audio( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetFd1" of register "Fd1audio".
**
** resets the FD2 clock generator
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetFd1" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd1audio_ResetFd1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd1audio_ResetFd1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO));
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd1rest" of register "Fd1audio".
**
** rest of integer division FD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd1rest" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd1audio_Fd1rest( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd1audio_Fd1rest( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO));
    value = ( value & 0x3FF00000UL ) >> 20;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd1modulo" of register "Fd1audio".
**
** modulo value for FD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd1modulo" consists of the bits 17..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0003FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd1audio_Fd1modulo( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd1audio_Fd1modulo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO));
    value = ( value & 0x0003FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd1muxsel" of register "Fd1audio".
**
** integer part divider FD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd1muxsel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd1audio_Fd1muxsel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd1audio_Fd1muxsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD1AUDIO));
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dplldivcounthdmi".
**
** This function writes the given value to the register "Dplldivcounthdmi".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcounthdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcounthdmi( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTHDMI, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTHDMI)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Divdpllhdmi" of register "Dplldivcounthdmi".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0. Each pulse removes/adds 1/12 of the 594MHz clock cycle.
** Example: to change HDMI clock (74.25MHz) by 10Hz
** 594MHz need to be changed by 80Hz =>
** 12 cycle per clock pulse => 960 pulses per second required
** 81000000/960 => 84375
** Calculated Value -1 has to be programmed to this register.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Divdpllhdmi" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcounthdmi_Divdpllhdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcounthdmi_Divdpllhdmi( uint32_t value )
{
    register uint32_t mask = 0x07FFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTHDMI)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTHDMI, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTHDMI)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dplldivcounthdmi".
**
** This function reads the value from the register "Dplldivcounthdmi".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcounthdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcounthdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTHDMI));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Divdpllhdmi" of register "Dplldivcounthdmi".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0. Each pulse removes/adds 1/12 of the 594MHz clock cycle.
** Example: to change HDMI clock (74.25MHz) by 10Hz
** 594MHz need to be changed by 80Hz =>
** 12 cycle per clock pulse => 960 pulses per second required
** 81000000/960 => 84375
** Calculated Value -1 has to be programmed to this register.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Divdpllhdmi" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcounthdmi_Divdpllhdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcounthdmi_Divdpllhdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTHDMI));
    value = ( value & 0x07FFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dplldivcountfd1".
**
** This function writes the given value to the register "Dplldivcountfd1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcountfd1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcountfd1( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTFD1, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Divdpllfd1" of register "Dplldivcountfd1".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0.
** Calculated Value -1 has to be programmed to this register.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Divdpllfd1" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcountfd1_Divdpllfd1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcountfd1_Divdpllfd1( uint32_t value )
{
    register uint32_t mask = 0x07FFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTFD1, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dplldivcountfd1".
**
** This function reads the value from the register "Dplldivcountfd1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcountfd1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcountfd1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Divdpllfd1" of register "Dplldivcountfd1".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0.
** Calculated Value -1 has to be programmed to this register.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Divdpllfd1" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcountfd1_Divdpllfd1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcountfd1_Divdpllfd1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD1));
    value = ( value & 0x07FFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dplldivcountfd2".
**
** This function writes the given value to the register "Dplldivcountfd2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcountfd2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcountfd2( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTFD2, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Divdpllfd2" of register "Dplldivcountfd2".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0.
** Calculated Value -1 has to be programmed to this register.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Divdpllfd2" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcountfd2_Divdpllfd2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcountfd2_Divdpllfd2( uint32_t value )
{
    register uint32_t mask = 0x07FFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTFD2, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dplldivcountfd2".
**
** This function reads the value from the register "Dplldivcountfd2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcountfd2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcountfd2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Divdpllfd2" of register "Dplldivcountfd2".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0.
** Calculated Value -1 has to be programmed to this register.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Divdpllfd2" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcountfd2_Divdpllfd2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcountfd2_Divdpllfd2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD2));
    value = ( value & 0x07FFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Configarm".
**
** This function writes the given value to the register "Configarm".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigarm( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigarm( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGARM, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Resetarm" of register "Configarm".
**
** reset to ARM
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Resetarm" consists of the bits 19..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x000F0000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigarm_Resetarm( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigarm_Resetarm( uint32_t value )
{
    register uint32_t mask = 0x000F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGARM, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confarm7" of register "Configarm".
**
** clock select for ARM core (0 = 324MHz, 1 = 162MHz)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confarm7" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigarm_Confarm7( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigarm_Confarm7( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGARM, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confarm2" of register "Configarm".
**
** enable for 162_1 clock
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confarm2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigarm_Confarm2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigarm_Confarm2( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGARM, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confarm1" of register "Configarm".
**
** enable for 162_0 clock
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confarm1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigarm_Confarm1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigarm_Confarm1( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGARM, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confarm0" of register "Configarm".
**
** enable for 324MHz clock
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confarm0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigarm_Confarm0( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigarm_Confarm0( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGARM, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Configarm".
**
** This function reads the value from the register "Configarm".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigarm( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigarm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Resetarm" of register "Configarm".
**
** reset to ARM
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Resetarm" consists of the bits 19..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x000F0000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigarm_Resetarm( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigarm_Resetarm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM));
    value = ( value & 0x000F0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confarm7" of register "Configarm".
**
** clock select for ARM core (0 = 324MHz, 1 = 162MHz)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confarm7" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigarm_Confarm7( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigarm_Confarm7( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confarm2" of register "Configarm".
**
** enable for 162_1 clock
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confarm2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigarm_Confarm2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigarm_Confarm2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confarm1" of register "Configarm".
**
** enable for 162_0 clock
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confarm1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigarm_Confarm1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigarm_Confarm1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confarm0" of register "Configarm".
**
** enable for 324MHz clock
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confarm0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigarm_Confarm0( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigarm_Confarm0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGARM));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dplldivcountfd3".
**
** This function writes the given value to the register "Dplldivcountfd3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcountfd3( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcountfd3( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTFD3, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Divdpllfd3" of register "Dplldivcountfd3".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0.
** Calculated Value -1 has to be programmed to this register.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Divdpllfd3" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDplldivcountfd3_Divdpllfd3( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDplldivcountfd3_Divdpllfd3( uint32_t value )
{
    register uint32_t mask = 0x07FFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLDIVCOUNTFD3, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dplldivcountfd3".
**
** This function reads the value from the register "Dplldivcountfd3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcountfd3( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcountfd3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD3));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Divdpllfd3" of register "Dplldivcountfd3".
**
** DPLL step frequency (counted with 81MHz).
**  Down-counter to 0.
** Calculated Value -1 has to be programmed to this register.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Divdpllfd3" consists of the bits 26..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x07FFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDplldivcountfd3_Divdpllfd3( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDplldivcountfd3_Divdpllfd3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLDIVCOUNTFD3));
    value = ( value & 0x07FFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Configvo".
**
** This function writes the given value to the register "Configvo".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo19" of register "Configvo".
**
** reset of OSD2_SCALER, CURSOR
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo19" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo19( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo19( uint32_t value )
{
    register uint32_t mask = 0x00080000UL;
    value = ( value << 19 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo18" of register "Configvo".
**
** reset of OSD1_SCALER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo18" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo18( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo18( uint32_t value )
{
    register uint32_t mask = 0x00040000UL;
    value = ( value << 18 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo17" of register "Configvo".
**
** reset of VO_SCALER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo17" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo17( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo17( uint32_t value )
{
    register uint32_t mask = 0x00020000UL;
    value = ( value << 17 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo16" of register "Configvo".
**
** reset of VO
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo16" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo16( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo16( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo15" of register "Configvo".
**
** enable for clock 81MHz in HDMI_LINK_WRAPPER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo15" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo15( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo15( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo13" of register "Configvo".
**
** enable for clock 81MHz in OSD2_SCALER, CURSOR
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo13" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo13( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo13( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo12" of register "Configvo".
**
** enable for clock 81MHz in OSD1_SCALER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo12" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo12( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo12( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo11" of register "Configvo".
**
** enable for clock 81MHz in VO_SCALER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo11" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo11( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo11( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo10" of register "Configvo".
**
** enable for clock 81MHz in SD_SCALER, VO_CONFIG
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo10" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo10( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo10( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo7" of register "Configvo".
**
** enable for clock 162MHz in OSD2_SCALER, CURSOR
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo7" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo7( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo7( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo6" of register "Configvo".
**
** enable for clock 162MHz in OSD1_SCALER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo6" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo6( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo6( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo5" of register "Configvo".
**
** enable for clock 162MHz in VO_SCALER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo5" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo5( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo5( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo4" of register "Configvo".
**
** enable for clock 162MHz in VO and HDMI_LINK_WRAPPER
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo4" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo4( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo4( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo0" of register "Configvo".
**
** enable for clock 324MHz in VO
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvo_Confvo0( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvo_Confvo0( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Configvo".
**
** This function reads the value from the register "Configvo".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo19" of register "Configvo".
**
** reset of OSD2_SCALER, CURSOR
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo19" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo19( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo19( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00080000UL ) >> 19;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo18" of register "Configvo".
**
** reset of OSD1_SCALER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo18" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo18( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo18( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo17" of register "Configvo".
**
** reset of VO_SCALER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo17" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo17( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo17( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo16" of register "Configvo".
**
** reset of VO
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo16" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo16( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo16( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo15" of register "Configvo".
**
** enable for clock 81MHz in HDMI_LINK_WRAPPER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo15" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo15( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo15( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo13" of register "Configvo".
**
** enable for clock 81MHz in OSD2_SCALER, CURSOR
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo13" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo13( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo13( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo12" of register "Configvo".
**
** enable for clock 81MHz in OSD1_SCALER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo12" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo12( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo12( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo11" of register "Configvo".
**
** enable for clock 81MHz in VO_SCALER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo11" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo11( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo11( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo10" of register "Configvo".
**
** enable for clock 81MHz in SD_SCALER, VO_CONFIG
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo10" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo10( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo10( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo7" of register "Configvo".
**
** enable for clock 162MHz in OSD2_SCALER, CURSOR
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo7" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo7( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo7( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo6" of register "Configvo".
**
** enable for clock 162MHz in OSD1_SCALER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo6" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo6( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo6( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo5" of register "Configvo".
**
** enable for clock 162MHz in VO_SCALER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo5" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo5( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo5( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo4" of register "Configvo".
**
** enable for clock 162MHz in VO and HDMI_LINK_WRAPPER
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo4" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo4( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo0" of register "Configvo".
**
** enable for clock 324MHz in VO
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvo_Confvo0( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvo_Confvo0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVO));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Softreset81".
**
** This function writes the given value to the register "Softreset81".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetSflash" of register "Softreset81".
**
** reset of SFLASH module
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetSflash" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetSflash( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetSflash( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetSsp" of register "Softreset81".
**
** reset of both SSP IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetSsp" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetSsp( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetSsp( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetUartFpc" of register "Softreset81".
**
** reset of UART_0, UART_1 and FPC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetUartFpc" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetUartFpc( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetUartFpc( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetI2c2" of register "Softreset81".
**
** reset of I2C_2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetI2c2" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetI2c2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetI2c2( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetI2c01" of register "Softreset81".
**
** reset of I2C_0 and I2C_1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetI2c01" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetI2c01( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetI2c01( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetApbEIcc" of register "Softreset81".
**
** reset of ICC module
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetApbEIcc" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetApbEIcc( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetApbEIcc( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetGpio" of register "Softreset81".
**
** reset of GPIO module
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetGpio" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetGpio( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetGpio( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetIrqCtrl" of register "Softreset81".
**
** reset of IRQ control module
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetIrqCtrl" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_ResetIrqCtrl( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_ResetIrqCtrl( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Reserved" of register "Softreset81".
**
** Must be 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Reserved" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetSoftreset81_Reserved( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetSoftreset81_Reserved( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_SOFTRESET81, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Softreset81".
**
** This function reads the value from the register "Softreset81".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetSflash" of register "Softreset81".
**
** reset of SFLASH module
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetSflash" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetSflash( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetSflash( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetSsp" of register "Softreset81".
**
** reset of both SSP IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetSsp" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetSsp( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetSsp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetUartFpc" of register "Softreset81".
**
** reset of UART_0, UART_1 and FPC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetUartFpc" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetUartFpc( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetUartFpc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetI2c2" of register "Softreset81".
**
** reset of I2C_2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetI2c2" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetI2c2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetI2c2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetI2c01" of register "Softreset81".
**
** reset of I2C_0 and I2C_1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetI2c01" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetI2c01( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetI2c01( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetApbEIcc" of register "Softreset81".
**
** reset of ICC module
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetApbEIcc" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetApbEIcc( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetApbEIcc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetGpio" of register "Softreset81".
**
** reset of GPIO module
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetGpio" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetGpio( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetGpio( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetIrqCtrl" of register "Softreset81".
**
** reset of IRQ control module
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetIrqCtrl" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_ResetIrqCtrl( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_ResetIrqCtrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Reserved" of register "Softreset81".
**
** Must be 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Reserved" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetSoftreset81_Reserved( void );
#else
INLINE uint32_t FREG_CLKPWR_GetSoftreset81_Reserved( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_SOFTRESET81));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dpllconfig".
**
** This function writes the given value to the register "Dpllconfig".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PptCountReg" of register "Dpllconfig".
**
** Frequency of PPT correction pulses for (60Hz*1.
** 001) 324 MHz counter). Each pulse removes/adds 1/12 of the 594MHz clock cycle. To correct by factor 1.001, 45 needs to be programmed. (3240000000/(12x594000))
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PptCountReg" consists of the bits 24..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x01FF0000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_PptCountReg( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_PptCountReg( uint32_t value )
{
    register uint32_t mask = 0x01FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IncFreqfd3" of register "Dpllconfig".
**
** frequency will be incremented
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IncFreqfd3" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_IncFreqfd3( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_IncFreqfd3( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "EnDpllfd3" of register "Dpllconfig".
**
** enables DPLL on FD3 clock generation
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnDpllfd3" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_EnDpllfd3( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_EnDpllfd3( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IncFreqfd2" of register "Dpllconfig".
**
** frequency will be incremented
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IncFreqfd2" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_IncFreqfd2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_IncFreqfd2( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "EnDpllfd2" of register "Dpllconfig".
**
** enables DPLL on FD2 clock generation
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnDpllfd2" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_EnDpllfd2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_EnDpllfd2( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IncFreqfd1" of register "Dpllconfig".
**
** frequency will be incremented
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IncFreqfd1" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_IncFreqfd1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_IncFreqfd1( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "EnDpllfd1" of register "Dpllconfig".
**
** enables DPLL on FD1 clock generation
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnDpllfd1" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_EnDpllfd1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_EnDpllfd1( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "EnPptHdmi" of register "Dpllconfig".
**
** enables PPT correction on HDMI clock generation
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnPptHdmi" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_EnPptHdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_EnPptHdmi( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IncPptHdmi" of register "Dpllconfig".
**
** increments HDMI frequency
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IncPptHdmi" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_IncPptHdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_IncPptHdmi( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IncFreqhdmi" of register "Dpllconfig".
**
** frequency will be incremented
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IncFreqhdmi" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_IncFreqhdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_IncFreqhdmi( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "EnDpllhdmi" of register "Dpllconfig".
**
** enables DPLL on HDMI clock generation (594MHz)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnDpllhdmi" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetDpllconfig_EnDpllhdmi( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetDpllconfig_EnDpllhdmi( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 11
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_DPLLCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dpllconfig".
**
** This function reads the value from the register "Dpllconfig".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PptCountReg" of register "Dpllconfig".
**
** Frequency of PPT correction pulses for (60Hz*1.
** 001) 324 MHz counter). Each pulse removes/adds 1/12 of the 594MHz clock cycle. To correct by factor 1.001, 45 needs to be programmed. (3240000000/(12x594000))
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PptCountReg" consists of the bits 24..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x01FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_PptCountReg( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_PptCountReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x01FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IncFreqfd3" of register "Dpllconfig".
**
** frequency will be incremented
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IncFreqfd3" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqfd3( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqfd3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "EnDpllfd3" of register "Dpllconfig".
**
** enables DPLL on FD3 clock generation
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnDpllfd3" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllfd3( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllfd3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IncFreqfd2" of register "Dpllconfig".
**
** frequency will be incremented
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IncFreqfd2" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqfd2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqfd2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "EnDpllfd2" of register "Dpllconfig".
**
** enables DPLL on FD2 clock generation
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnDpllfd2" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllfd2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllfd2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IncFreqfd1" of register "Dpllconfig".
**
** frequency will be incremented
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IncFreqfd1" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqfd1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqfd1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "EnDpllfd1" of register "Dpllconfig".
**
** enables DPLL on FD1 clock generation
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnDpllfd1" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllfd1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllfd1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "EnPptHdmi" of register "Dpllconfig".
**
** enables PPT correction on HDMI clock generation
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnPptHdmi" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_EnPptHdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_EnPptHdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IncPptHdmi" of register "Dpllconfig".
**
** increments HDMI frequency
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IncPptHdmi" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_IncPptHdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_IncPptHdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IncFreqhdmi" of register "Dpllconfig".
**
** frequency will be incremented
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IncFreqhdmi" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqhdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_IncFreqhdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "EnDpllhdmi" of register "Dpllconfig".
**
** enables DPLL on HDMI clock generation (594MHz)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnDpllhdmi" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllhdmi( void );
#else
INLINE uint32_t FREG_CLKPWR_GetDpllconfig_EnDpllhdmi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_DPLLCONFIG));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Fd2audio".
**
** This function writes the given value to the register "Fd2audio".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2audio( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2audio( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ResetFd2" of register "Fd2audio".
**
** resets the FD3 clock generator
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ResetFd2" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2audio_ResetFd2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2audio_ResetFd2( uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    value = ( value << 31 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2rest" of register "Fd2audio".
**
** rest of integer division FD3
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2rest" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2audio_Fd2rest( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2audio_Fd2rest( uint32_t value )
{
    register uint32_t mask = 0x3FF00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2modulo" of register "Fd2audio".
**
** modulo value for FD3
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2modulo" consists of the bits 17..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0003FF00UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2audio_Fd2modulo( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2audio_Fd2modulo( uint32_t value )
{
    register uint32_t mask = 0x0003FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fd2muxsel" of register "Fd2audio".
**
** integer part divider FD3
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fd2muxsel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetFd2audio_Fd2muxsel( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetFd2audio_Fd2muxsel( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_FD2AUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Fd2audio".
**
** This function reads the value from the register "Fd2audio".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2audio( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2audio( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ResetFd2" of register "Fd2audio".
**
** resets the FD3 clock generator
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ResetFd2" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2audio_ResetFd2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2audio_ResetFd2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO));
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2rest" of register "Fd2audio".
**
** rest of integer division FD3
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2rest" consists of the bits 29..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x3FF00000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2audio_Fd2rest( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2audio_Fd2rest( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO));
    value = ( value & 0x3FF00000UL ) >> 20;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2modulo" of register "Fd2audio".
**
** modulo value for FD3
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2modulo" consists of the bits 17..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0003FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2audio_Fd2modulo( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2audio_Fd2modulo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO));
    value = ( value & 0x0003FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fd2muxsel" of register "Fd2audio".
**
** integer part divider FD3
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fd2muxsel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetFd2audio_Fd2muxsel( void );
#else
INLINE uint32_t FREG_CLKPWR_GetFd2audio_Fd2muxsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_FD2AUDIO));
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Configdmacaudio".
**
** This function writes the given value to the register "Configdmacaudio".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau23" of register "Configdmacaudio".
**
** reset Audio output
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau23" consists of the bits 23..23,
**       the given bitgroup value will be shifted left by 23 bits and
**       masked using the bitmask 0x00800000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau23( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau23( uint32_t value )
{
    register uint32_t mask = 0x00800000UL;
    value = ( value << 23 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau22" of register "Configdmacaudio".
**
** reset Ethernet
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau22" consists of the bits 22..22,
**       the given bitgroup value will be shifted left by 22 bits and
**       masked using the bitmask 0x00400000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau22( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau22( uint32_t value )
{
    register uint32_t mask = 0x00400000UL;
    value = ( value << 22 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau21" of register "Configdmacaudio".
**
** reset USB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau21" consists of the bits 21..21,
**       the given bitgroup value will be shifted left by 21 bits and
**       masked using the bitmask 0x00200000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau21( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau21( uint32_t value )
{
    register uint32_t mask = 0x00200000UL;
    value = ( value << 21 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau20" of register "Configdmacaudio".
**
** reset DMA
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau20" consists of the bits 20..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00100000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau20( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau20( uint32_t value )
{
    register uint32_t mask = 0x00100000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau19" of register "Configdmacaudio".
**
** reset TSD23
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau19" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau19( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau19( uint32_t value )
{
    register uint32_t mask = 0x00080000UL;
    value = ( value << 19 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau18" of register "Configdmacaudio".
**
** reset TSD01
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau18" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau18( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau18( uint32_t value )
{
    register uint32_t mask = 0x00040000UL;
    value = ( value << 18 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau17" of register "Configdmacaudio".
**
** reset Audio processor
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau17" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau17( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau17( uint32_t value )
{
    register uint32_t mask = 0x00020000UL;
    value = ( value << 17 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau16" of register "Configdmacaudio".
**
** reset AXI_modules
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau16" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau16( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau16( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau15" of register "Configdmacaudio".
**
** enable for 81 clock AUDIO
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau15" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau15( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau15( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau14" of register "Configdmacaudio".
**
** enable for 81 clock USB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau14" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau14( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau14( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau13" of register "Configdmacaudio".
**
** enable for 81 clock Ethernet
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau13" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau13( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau13( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau12" of register "Configdmacaudio".
**
** enable for 81 clock TSD23
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau12" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau12( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau12( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau11" of register "Configdmacaudio".
**
** enable for 81 clock TSD01
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau11" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau11( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau11( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau10" of register "Configdmacaudio".
**
** enable for 81 clock AXI_IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau10" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau10( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau10( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau9" of register "Configdmacaudio".
**
** enable for 162 clock Audio processor
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau9" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau9( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau9( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau7" of register "Configdmacaudio".
**
** enable for 162 clock DMA_USB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau7" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau7( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau7( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau6" of register "Configdmacaudio".
**
** enable for 162 clock TSD23
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau6" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau6( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau6( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau5" of register "Configdmacaudio".
**
** enable for 162 clock TSD01
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau5" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau5( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau5( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau4" of register "Configdmacaudio".
**
** enable for 162 clock AXI_IF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau4" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau4( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau4( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau2" of register "Configdmacaudio".
**
** clock select for Audio processor core
** 0 = 324MHz, 1 = 162MHz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau2( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau1" of register "Configdmacaudio".
**
** enable for 324MHz clock Audio processor
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau1( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confdmacau0" of register "Configdmacaudio".
**
** enable for 324MHz clock TSD's
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confdmacau0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau0( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigdmacaudio_Confdmacau0( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 22
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGDMACAUDIO, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Configdmacaudio".
**
** This function reads the value from the register "Configdmacaudio".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau23" of register "Configdmacaudio".
**
** reset Audio output
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau23" consists of the bits 23..23,
**       the given bitgroup value will be shifted left by 23 bits and
**       masked using the bitmask 0x00800000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau23( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau23( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00800000UL ) >> 23;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau22" of register "Configdmacaudio".
**
** reset Ethernet
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau22" consists of the bits 22..22,
**       the given bitgroup value will be shifted left by 22 bits and
**       masked using the bitmask 0x00400000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau22( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau22( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00400000UL ) >> 22;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau21" of register "Configdmacaudio".
**
** reset USB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau21" consists of the bits 21..21,
**       the given bitgroup value will be shifted left by 21 bits and
**       masked using the bitmask 0x00200000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau21( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau21( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00200000UL ) >> 21;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau20" of register "Configdmacaudio".
**
** reset DMA
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau20" consists of the bits 20..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00100000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau20( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau20( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00100000UL ) >> 20;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau19" of register "Configdmacaudio".
**
** reset TSD23
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau19" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau19( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau19( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00080000UL ) >> 19;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau18" of register "Configdmacaudio".
**
** reset TSD01
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau18" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau18( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau18( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau17" of register "Configdmacaudio".
**
** reset Audio processor
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau17" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau17( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau17( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau16" of register "Configdmacaudio".
**
** reset AXI_modules
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau16" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau16( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau16( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau15" of register "Configdmacaudio".
**
** enable for 81 clock AUDIO
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau15" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau15( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau15( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau14" of register "Configdmacaudio".
**
** enable for 81 clock USB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau14" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau14( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau14( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau13" of register "Configdmacaudio".
**
** enable for 81 clock Ethernet
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau13" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau13( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau13( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau12" of register "Configdmacaudio".
**
** enable for 81 clock TSD23
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau12" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau12( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau12( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau11" of register "Configdmacaudio".
**
** enable for 81 clock TSD01
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau11" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau11( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau11( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau10" of register "Configdmacaudio".
**
** enable for 81 clock AXI_IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau10" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau10( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau10( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau9" of register "Configdmacaudio".
**
** enable for 162 clock Audio processor
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau9" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau9( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau9( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau7" of register "Configdmacaudio".
**
** enable for 162 clock DMA_USB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau7" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau7( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau7( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau6" of register "Configdmacaudio".
**
** enable for 162 clock TSD23
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau6" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau6( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau6( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau5" of register "Configdmacaudio".
**
** enable for 162 clock TSD01
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau5" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau5( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau5( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau4" of register "Configdmacaudio".
**
** enable for 162 clock AXI_IF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau4" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau4( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau2" of register "Configdmacaudio".
**
** clock select for Audio processor core
** 0 = 324MHz, 1 = 162MHz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau1" of register "Configdmacaudio".
**
** enable for 324MHz clock Audio processor
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confdmacau0" of register "Configdmacaudio".
**
** enable for 324MHz clock TSD's
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confdmacau0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau0( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigdmacaudio_Confdmacau0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGDMACAUDIO));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Configvd".
**
** This function writes the given value to the register "Configvd".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvd( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvd( uint32_t value )
{
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVD, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvd17" of register "Configvd".
**
** reset of AXI_WRAP in VD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvd17" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvd_Confvd17( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvd_Confvd17( uint32_t value )
{
    register uint32_t mask = 0x00020000UL;
    value = ( value << 17 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVD, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvd16" of register "Configvd".
**
** reset of VD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvd16" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvd_Confvd16( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvd_Confvd16( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVD, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo2" of register "Configvd".
**
** enable for clock 81MHz in VD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvd_Confvo2( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvd_Confvo2( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVD, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvo1" of register "Configvd".
**
** enable for clock 162MHz in VD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvo1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvd_Confvo1( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvd_Confvo1( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVD, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Confvd0" of register "Configvd".
**
** enable for clock 216MHz in VD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Confvd0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_CLKPWR_SetConfigvd_Confvd0( uint32_t value );
#else
INLINE void FREG_CLKPWR_SetConfigvd_Confvd0( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_CLKPWR_ENABLE_DEBUG_PRINT == 1
        FREG_CLKPWR_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_CLKPWR", FREG_CLKPWR_CONFIGVD, value );
    #endif
    *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Configvd".
**
** This function reads the value from the register "Configvd".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvd( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvd17" of register "Configvd".
**
** reset of AXI_WRAP in VD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvd17" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvd_Confvd17( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvd_Confvd17( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvd16" of register "Configvd".
**
** reset of VD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvd16" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvd_Confvd16( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvd_Confvd16( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo2" of register "Configvd".
**
** enable for clock 81MHz in VD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvd_Confvo2( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvd_Confvo2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvo1" of register "Configvd".
**
** enable for clock 162MHz in VD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvo1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvd_Confvo1( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvd_Confvo1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Confvd0" of register "Configvd".
**
** enable for clock 216MHz in VD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Confvd0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_CLKPWR_GetConfigvd_Confvd0( void );
#else
INLINE uint32_t FREG_CLKPWR_GetConfigvd_Confvd0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_CLKPWR_CONFIGVD));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

/*!
********************************************************************************
**
** \brief Initializes the "CLKPWR" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
extern void FREG_CLKPWR_Init( void );

#endif
