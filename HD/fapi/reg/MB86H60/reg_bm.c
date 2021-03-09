/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_bm.c
**
** \brief     BM access functions
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
#define FREG_BM_C

#include <stdint.h>
#include "reg_bm.h"

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
volatile uint32_t FREG_BM0_IrqMaskMirror = 0;
volatile uint32_t FREG_BM01_ReadEnableMirror = 0;
volatile uint32_t FREG_BM01_GlobalOffsetMirror = 0;
volatile uint32_t FREG_BM0_EndianSwapWrMirror = 0;
volatile uint32_t FREG_BM01_BufLowLevMirror[8] = {
    0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_BM1_IrqMaskMirror = 0;
volatile uint32_t FREG_BM1_EndianSwapWrMirror = 0;
volatile uint32_t FREG_BM01_AudValueMirror[5] = {
    0,0,0,0,0
};
volatile uint32_t FREG_BM01_AudCfgEnMirror = 0;
volatile uint32_t FREG_BM01_ClearAudIrqMirror = 0;
volatile uint32_t FREG_BM2_IrqMaskMirror = 0;
volatile uint32_t FREG_BM23_ReadEnableMirror = 0;
volatile uint32_t FREG_BM23_GlobalOffsetMirror = 0;
volatile uint32_t FREG_BM2_EndianSwapWrMirror = 0;
volatile uint32_t FREG_BM23_BufLowLevMirror[8] = {
    0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_BM3_IrqMaskMirror = 0;
volatile uint32_t FREG_BM3_EndianSwapWrMirror = 0;
volatile uint32_t FREG_BM23_AudValueMirror[5] = {
    0,0,0,0,0
};
volatile uint32_t FREG_BM23_AudCfgEnMirror = 0;
volatile uint32_t FREG_BM01_EndianSwapRdMirror = 0;
volatile uint32_t FREG_BM23_EndianSwapRdMirror = 0;

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BufSize".
**
** This function writes the given value to the index-th entry of the register
** array BufSize.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_1")))
#endif

void FREG_BM0_SetBufSize( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_2")))
#endif

void FREG_BM0_SetBufSize_BufSize( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM0_BUFSIZE+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufSize".
**
** This function reads the value from the index-th entry of the register
** array BufSize.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_3")))
#endif

uint32_t FREG_BM0_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_BUFSIZE+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_4")))
#endif

uint32_t FREG_BM0_GetBufSize_BufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_BUFSIZE+(index*0x4)));
    value = ( value & 0x00FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "WrPtr".
**
** This function writes the given value to the index-th entry of the register
** array WrPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_5")))
#endif

void FREG_BM0_SetWrPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_6")))
#endif

void FREG_BM0_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM0_WRPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WrPtr".
**
** This function reads the value from the index-th entry of the register
** array WrPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_7")))
#endif

uint32_t FREG_BM0_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_WRPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_8")))
#endif

uint32_t FREG_BM0_GetWrPtr_WrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_WRPTR+(index*0x4)));
    value = ( value & 0x00FFFFFFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BaseAddr".
**
** This function writes the given value to the index-th entry of the register
** array BaseAddr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_9")))
#endif

void FREG_BM0_SetBaseAddr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_10")))
#endif

void FREG_BM0_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x07FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM0_BASEADDR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseAddr".
**
** This function reads the value from the index-th entry of the register
** array BaseAddr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_11")))
#endif

uint32_t FREG_BM0_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_BASEADDR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_12")))
#endif

uint32_t FREG_BM0_GetBaseAddr_BaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_BASEADDR+(index*0x4)));
    value = ( value & 0x07FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RdPtr".
**
** This function writes the given value to the index-th entry of the register
** array RdPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_13")))
#endif

void FREG_BM0_SetRdPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_14")))
#endif

void FREG_BM0_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFE0UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM0_RDPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RdPtr".
**
** This function reads the value from the index-th entry of the register
** array RdPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_15")))
#endif

uint32_t FREG_BM0_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_RDPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_16")))
#endif

uint32_t FREG_BM0_GetRdPtr_RdPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_RDPTR+(index*0x4)));
    value = ( value & 0x00FFFFE0UL ) >> 5;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "IrqMask".
**
** This function writes the given value to the register "IrqMask".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_17")))
#endif

void FREG_BM0_SetIrqMask( uint32_t value )
{
    FREG_BM0_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_18")))
#endif

void FREG_BM0_SetIrqMask_IrqMask( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM0_IrqMaskMirror & ~mask;
    FREG_BM0_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqMask".
**
** This function reads the value from the register "IrqMask".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_19")))
#endif

uint32_t FREG_BM0_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM0_IrqMaskMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_20")))
#endif

uint32_t FREG_BM0_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM0_IrqMaskMirror;
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
** \brief Reads the entire register "IrqReg".
**
** This function reads the value from the register "IrqReg".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_21")))
#endif

uint32_t FREG_BM0_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM0_IRQREG));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Extracts the bitgroup "IrqReg" of register "IrqReg".
**
** The interrupt register shows in which buffer the overflow occurred.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc. When reading the register, all interrupts are cleared.
** - '0': No IRQ.
** - '1': Buffer overflow occurred in the corresponding buffer.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_22")))
#endif

uint32_t FREG_BM0_ExtractIrqReg_IrqReg( uint32_t value )
{
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
** \brief Writes the entire register "ReadEnable".
**
** This function writes the given value to the register "ReadEnable".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_23")))
#endif

void FREG_BM01_SetReadEnable( uint32_t value )
{
    FREG_BM01_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_READENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01ReadSelect" of register "ReadEnable".
**
** Select HW controlled buffer from BM0 and BM1:
** - '0': buffer 0, buffer 1, ?, buffer 6 in BM0 will be used as HW controlled buffers.
**
** - '1': buffer 0, buffer 1, ?, buffer 6 in BM1 will be used as HW controlled buffers.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01ReadSelect" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_24")))
#endif

void FREG_BM01_SetReadEnable_Bm01ReadSelect( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_BM01_ReadEnableMirror & ~mask;
    FREG_BM01_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_READENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01ReadEnable" of register "ReadEnable".
**
** Enables read access of HW controlled buffers.
**  Bit n corresponds to buffer n.
** - '0': read access of the corresponding buffer is disabled.
** - '1': read access of the corresponding buffer is enabled.
** Bit 6: buffer 6 (for audio).
** Bit 5: buffer 5 (for TTX).
** Bit 4: buffer 4 (for SPDIF).
** Bit 3: buffer 3 (for I2S_3).
** Bit 2: buffer 2 (for I2S_2).
** Bit 1: buffer 1 (for I2S_1).
** Bit 0: buffer 0 (for I2S_0).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01ReadEnable" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_25")))
#endif

void FREG_BM01_SetReadEnable_Bm01ReadEnable( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM01_ReadEnableMirror & ~mask;
    FREG_BM01_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_READENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "ReadEnable".
**
** This function reads the value from the register "ReadEnable".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_26")))
#endif

uint32_t FREG_BM01_GetmReadEnable( void )
{
    register uint32_t value = FREG_BM01_ReadEnableMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01ReadSelect" of register "ReadEnable".
**
** Select HW controlled buffer from BM0 and BM1:
** - '0': buffer 0, buffer 1, ?, buffer 6 in BM0 will be used as HW controlled buffers.
**
** - '1': buffer 0, buffer 1, ?, buffer 6 in BM1 will be used as HW controlled buffers.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01ReadSelect" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_27")))
#endif

uint32_t FREG_BM01_GetmReadEnable_Bm01ReadSelect( void )
{
    register uint32_t value = FREG_BM01_ReadEnableMirror;
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
** \brief Reads the bitgroup "Bm01ReadEnable" of register "ReadEnable".
**
** Enables read access of HW controlled buffers.
**  Bit n corresponds to buffer n.
** - '0': read access of the corresponding buffer is disabled.
** - '1': read access of the corresponding buffer is enabled.
** Bit 6: buffer 6 (for audio).
** Bit 5: buffer 5 (for TTX).
** Bit 4: buffer 4 (for SPDIF).
** Bit 3: buffer 3 (for I2S_3).
** Bit 2: buffer 2 (for I2S_2).
** Bit 1: buffer 1 (for I2S_1).
** Bit 0: buffer 0 (for I2S_0).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01ReadEnable" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_28")))
#endif

uint32_t FREG_BM01_GetmReadEnable_Bm01ReadEnable( void )
{
    register uint32_t value = FREG_BM01_ReadEnableMirror;
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
** \brief Writes the entire register "GlobalOffset".
**
** This function writes the given value to the register "GlobalOffset".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_29")))
#endif

void FREG_BM01_SetGlobalOffset( uint32_t value )
{
    FREG_BM01_GlobalOffsetMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_GLOBALOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_GLOBALOFFSET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01Offset" of register "GlobalOffset".
**
** Global offset for BM0 and BM1.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01Offset" consists of the bits 31..27,
**       the given bitgroup value will be shifted left by 27 bits and
**       masked using the bitmask 0xF8000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_30")))
#endif

void FREG_BM01_SetGlobalOffset_Bm01Offset( uint32_t value )
{
    register uint32_t mask = 0xF8000000UL;
    value = ( value << 27 ) & mask;
    value |= FREG_BM01_GlobalOffsetMirror & ~mask;
    FREG_BM01_GlobalOffsetMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_GLOBALOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_GLOBALOFFSET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "GlobalOffset".
**
** This function reads the value from the register "GlobalOffset".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_31")))
#endif

uint32_t FREG_BM01_GetmGlobalOffset( void )
{
    register uint32_t value = FREG_BM01_GlobalOffsetMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01Offset" of register "GlobalOffset".
**
** Global offset for BM0 and BM1.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01Offset" consists of the bits 31..27,
**       the given bitgroup value will be shifted left by 27 bits and
**       masked using the bitmask 0xF8000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_32")))
#endif

uint32_t FREG_BM01_GetmGlobalOffset_Bm01Offset( void )
{
    register uint32_t value = FREG_BM01_GlobalOffsetMirror;
    value = ( value & 0xF8000000UL ) >> 27;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "EndianSwapWr".
**
** This function writes the given value to the register "EndianSwapWr".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_33")))
#endif

void FREG_BM0_SetEndianSwapWr( uint32_t value )
{
    FREG_BM0_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm0EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM0.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm0EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_34")))
#endif

void FREG_BM0_SetEndianSwapWr_Bm0EndianSwapWr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM0_EndianSwapWrMirror & ~mask;
    FREG_BM0_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "EndianSwapWr".
**
** This function reads the value from the register "EndianSwapWr".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_35")))
#endif

uint32_t FREG_BM0_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM0_EndianSwapWrMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm0EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM0.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm0EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_36")))
#endif

uint32_t FREG_BM0_GetmEndianSwapWr_Bm0EndianSwapWr( void )
{
    register uint32_t value = FREG_BM0_EndianSwapWrMirror;
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
** \brief Writes the entire register "BufLowLev".
**
** This function writes the given value to the index-th entry of the register
** array BufLowLev.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_37")))
#endif

void FREG_BM01_SetBufLowLev( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    FREG_BM01_BufLowLevMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFLOWLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFLOWLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01BufLowLevIrqEn" of register "BufLowLev".
**
** Buffer low level IRQ enable (Buffer 7 to 0.
**  n = buffer number)
** - '0': Low level IRQ disabled.
** - '1': Low level IRQ enabled.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01BufLowLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_38")))
#endif

void FREG_BM01_SetBufLowLev_Bm01BufLowLevIrqEn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 31 ) & mask;
    value |= FREG_BM01_BufLowLevMirror[index] & ~mask;
    FREG_BM01_BufLowLevMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFLOWLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFLOWLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01BufLowLev" of register "BufLowLev".
**
** Buffer low level threshold when IRQ is activated.
**
** Attention: Bit 5 must be always set to 0!
** If number of bytes availabe in the buffer is less than the value BM01_BUF_LOW_LEV[23:6] times 64, a low level IRQ (buffer almost empty IRQ) will be generated.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01BufLowLev" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_39")))
#endif

void FREG_BM01_SetBufLowLev_Bm01BufLowLev( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFE0UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    value |= FREG_BM01_BufLowLevMirror[index] & ~mask;
    FREG_BM01_BufLowLevMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFLOWLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFLOWLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufLowLev".
**
** This function reads the value from the index-th entry of the register
** array BufLowLev.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_40")))
#endif

uint32_t FREG_BM01_GetmBufLowLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_BufLowLevMirror[index];
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufLowLevIrqEn" of register "BufLowLev".
**
** Buffer low level IRQ enable (Buffer 7 to 0.
**  n = buffer number)
** - '0': Low level IRQ disabled.
** - '1': Low level IRQ enabled.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufLowLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_41")))
#endif

uint32_t FREG_BM01_GetmBufLowLev_Bm01BufLowLevIrqEn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 8 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_BufLowLevMirror[index];
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufLowLev" of register "BufLowLev".
**
** Buffer low level threshold when IRQ is activated.
**
** Attention: Bit 5 must be always set to 0!
** If number of bytes availabe in the buffer is less than the value BM01_BUF_LOW_LEV[23:6] times 64, a low level IRQ (buffer almost empty IRQ) will be generated.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufLowLev" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_42")))
#endif

uint32_t FREG_BM01_GetmBufLowLev_Bm01BufLowLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 8 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_BufLowLevMirror[index];
    value = ( value & 0x00FFFFE0UL ) >> 5;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BufHighLev".
**
** This function writes the given value to the index-th entry of the register
** array BufHighLev.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_43")))
#endif

void FREG_BM01_SetBufHighLev( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01BufHighLevIrqEn" of register "BufHighLev".
**
** High level IRQ enable bit.
**
** - '0': High level IRQ disabled.
** - '1': High level IRQ enabled.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01BufHighLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_44")))
#endif

void FREG_BM01_SetBufHighLev_Bm01BufHighLevIrqEn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 31 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01BufHighLevLimit" of register "BufHighLev".
**
** Buffer high level threshold value where IRQ is activated (bits correspond to byte address bits).
**  If number of free bytes in the corresponding buffer is less than this limit times 512, a buffer high level IRQ (buffer almost full IRQ) will be generated.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01BufHighLevLimit" consists of the bits 23..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00FFFF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_45")))
#endif

void FREG_BM01_SetBufHighLev_Bm01BufHighLevLimit( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm01BufHighLevStreamNb" of register "BufHighLev".
**
** Defines for which buffer the limit is applied.
**
** Bit 5: indicates to  which BM the defined buffer belongs.
** - '0': the buffer belongs to BM0.
** - '1': the buffer belongs to BM1.
** Bits [4:0] range from 0 to 31 and defines the buffer number.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm01BufHighLevStreamNb" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_46")))
#endif

void FREG_BM01_SetBufHighLev_Bm01BufHighLevStreamNb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufHighLev".
**
** This function reads the value from the index-th entry of the register
** array BufHighLev.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_47")))
#endif

uint32_t FREG_BM01_GetBufHighLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufHighLevIrqEn" of register "BufHighLev".
**
** High level IRQ enable bit.
**
** - '0': High level IRQ disabled.
** - '1': High level IRQ enabled.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufHighLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_48")))
#endif

uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevIrqEn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4)));
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufHighLevLimit" of register "BufHighLev".
**
** Buffer high level threshold value where IRQ is activated (bits correspond to byte address bits).
**  If number of free bytes in the corresponding buffer is less than this limit times 512, a buffer high level IRQ (buffer almost full IRQ) will be generated.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufHighLevLimit" consists of the bits 23..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00FFFF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_49")))
#endif

uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevLimit( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4)));
    value = ( value & 0x00FFFF00UL ) >> 8;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufHighLevStreamNb" of register "BufHighLev".
**
** Defines for which buffer the limit is applied.
**
** Bit 5: indicates to  which BM the defined buffer belongs.
** - '0': the buffer belongs to BM0.
** - '1': the buffer belongs to BM1.
** Bits [4:0] range from 0 to 31 and defines the buffer number.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufHighLevStreamNb" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_50")))
#endif

uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevStreamNb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4)));
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
** \brief Reads the entire register "StatusRd".
**
** This function reads the value from the register "StatusRd".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_51")))
#endif

uint32_t FREG_BM01_GetStatusRd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BmStreamStatus" of register "StatusRd".
**
** Indicates the BM status.
**
** Bit 30 indicates if some TS packet is being sent to memory.
** - '0': No TS packet is being processed. Both BM0
** and BM1 are in idle state. In this case the bits
** [29:24] are set to 0.
** - '1': A TS packet is being processed. BM0 or
** BM1 is busy.
** Bit 29 indicates which BM is busy (BM0 or BM1).
** - '0': BM0 is busy (if bit 30 is 1).
** - '1': BM1is busy (if bit 30 is 1).
**
** If bit 30 is 1, the bits [28:24] are buffer index and range from 0 to 31. Together with bit 29 these bits indicate which buffer from which BM is being accessed.
**
** If bit 30 is 0, these bits can be ignored.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BmStreamStatus" consists of the bits 30..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x7F000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_52")))
#endif

uint32_t FREG_BM01_GetStatusRd_BmStreamStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x7F000000UL ) >> 24;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudIrq" of register "StatusRd".
**
** IRQ status of AUD's.
**
** Bit 23:
** - '0': AUD value defined in register
** BM01_AUD_VALUE+4*4 is not detected.
** - '1': AUD value defined in register
** BM01_AUD_VALUE+4*4 is detected.
** Bit 22:
** - '0': AUD value defined in register
** BM01_AUD_VALUE+4*3 is not detected.
** - '1': AUD value defined in register
** BM01_AUD_VALUE+4*3 is detected.
** Bit 21, bit 20 and bit 19 are defined similarly.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudIrq" consists of the bits 23..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00F80000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_53")))
#endif

uint32_t FREG_BM01_GetStatusRd_AudIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x00F80000UL ) >> 19;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LevelIrq" of register "StatusRd".
**
** Level IRQ status.
**
** - '0': wether high nor low level IRQ detected.
** - '1': either high or low level IRQ deteced.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LevelIrq" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_54")))
#endif

uint32_t FREG_BM01_GetStatusRd_LevelIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
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
** \brief Reads the bitgroup "Bm0Int" of register "StatusRd".
**
** BM0 overflow IRQ status.
**
** - '0': No buffer in BM0 overflows.
** - '1': Some buffer in BM0 overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm0Int" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_55")))
#endif

uint32_t FREG_BM01_GetStatusRd_Bm0Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
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
** \brief Reads the bitgroup "Bm1Int" of register "StatusRd".
**
** BM1 overflow IRQ status.
**
** - '0': No buffer in BM1 overflows.
** - '1': Some buffer in BM1 overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm1Int" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_56")))
#endif

uint32_t FREG_BM01_GetStatusRd_Bm1Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
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
** \brief Reads the bitgroup "BufferLowIrqFlag" of register "StatusRd".
**
** Low level IRQ status.
**
** Bit 15:
** - '0': Low level IRQ in Hardware controlled buffer 7 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 7
** dectected.
** Bit 14:
** - '0': Low level IRQ in Hardware controlled buffer 6 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 6
** dectected.
** ... ...
** Bit 8:
** - '0': Low level IRQ in Hardware controlled buffer 0 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 0
** dectected.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferLowIrqFlag" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_57")))
#endif

uint32_t FREG_BM01_GetStatusRd_BufferLowIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
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
** \brief Reads the bitgroup "BufferHighIrqFlag" of register "StatusRd".
**
** High level IRQ status.
**
** Bit 7:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is detected.
** Bit 6:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is detected.
** Bit 5, ..., bit 0 are defined similarly.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferHighIrqFlag" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_58")))
#endif

uint32_t FREG_BM01_GetStatusRd_BufferHighIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
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
** \brief Reads the entire register "BufHighLevIrqClr".
**
** This function reads the value from the index-th entry of the register
** array BufHighLevIrqClr.
**
** A read access of this register will clear the high level IRQ corresponding to the address offset n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_59")))
#endif

uint32_t FREG_BM01_GetBufHighLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEVIRQCLR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufHighLevIrqClr" of register "BufHighLevIrqClr".
**
** A read access of this register will clear the high level IRQ corresponding to the address offset n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufHighLevIrqClr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_60")))
#endif

uint32_t FREG_BM01_GetBufHighLevIrqClr_Bm01BufHighLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEVIRQCLR+(index*0x4)));
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
** \brief Reads the entire register "BufLowLevIrqClr".
**
** This function reads the value from the index-th entry of the register
** array BufLowLevIrqClr.
**
** A read access of this register will clear the low level IRQ in buffer n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_61")))
#endif

uint32_t FREG_BM01_GetBufLowLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFLOWLEVIRQCLR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufLowLevIrqClr" of register "BufLowLevIrqClr".
**
** A read access of this register will clear the low level IRQ in buffer n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufLowLevIrqClr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_62")))
#endif

uint32_t FREG_BM01_GetBufLowLevIrqClr_Bm01BufLowLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFLOWLEVIRQCLR+(index*0x4)));
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
** \brief Reads the entire register "BufStreamIrqClr".
**
** This function reads the value from the index-th entry of the register
** array BufStreamIrqClr.
**
** A read access of this register will clear the buffer overflow IRQ in buffer n of BM23  (n = 0, 1, ?, 63).
**  The indices 0 to 31 correspond to buffers in BM0 and the indices 32 to 63 correspond to buffers in BM1.
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_63")))
#endif

uint32_t FREG_BM01_GetBufStreamIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFSTREAMIRQCLR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm01BufStreamIrqClr" of register "BufStreamIrqClr".
**
** A read access of this register will clear the buffer overflow IRQ in buffer n of BM23  (n = 0, 1, ?, 63).
**  The indices 0 to 31 correspond to buffers in BM0 and the indices 32 to 63 correspond to buffers in BM1.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm01BufStreamIrqClr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_64")))
#endif

uint32_t FREG_BM01_GetBufStreamIrqClr_Bm01BufStreamIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFSTREAMIRQCLR+(index*0x4)));
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
** \brief Writes the entire register "BufSize".
**
** This function writes the given value to the index-th entry of the register
** array BufSize.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_65")))
#endif

void FREG_BM1_SetBufSize( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_66")))
#endif

void FREG_BM1_SetBufSize_BufSize( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM1_BUFSIZE+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufSize".
**
** This function reads the value from the index-th entry of the register
** array BufSize.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_67")))
#endif

uint32_t FREG_BM1_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_BUFSIZE+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_68")))
#endif

uint32_t FREG_BM1_GetBufSize_BufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_BUFSIZE+(index*0x4)));
    value = ( value & 0x00FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "WrPtr".
**
** This function writes the given value to the index-th entry of the register
** array WrPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_69")))
#endif

void FREG_BM1_SetWrPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_70")))
#endif

void FREG_BM1_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM1_WRPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WrPtr".
**
** This function reads the value from the index-th entry of the register
** array WrPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_71")))
#endif

uint32_t FREG_BM1_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_WRPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_72")))
#endif

uint32_t FREG_BM1_GetWrPtr_WrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_WRPTR+(index*0x4)));
    value = ( value & 0x00FFFFFFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BaseAddr".
**
** This function writes the given value to the index-th entry of the register
** array BaseAddr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_73")))
#endif

void FREG_BM1_SetBaseAddr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_74")))
#endif

void FREG_BM1_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x07FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM1_BASEADDR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseAddr".
**
** This function reads the value from the index-th entry of the register
** array BaseAddr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_75")))
#endif

uint32_t FREG_BM1_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_BASEADDR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_76")))
#endif

uint32_t FREG_BM1_GetBaseAddr_BaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_BASEADDR+(index*0x4)));
    value = ( value & 0x07FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RdPtr".
**
** This function writes the given value to the index-th entry of the register
** array RdPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_77"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_77" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_77")))
#endif

void FREG_BM1_SetRdPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_78"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_78" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_78")))
#endif

void FREG_BM1_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFE0UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM1_RDPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RdPtr".
**
** This function reads the value from the index-th entry of the register
** array RdPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_79"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_79" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_79")))
#endif

uint32_t FREG_BM1_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_RDPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_80"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_80" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_80")))
#endif

uint32_t FREG_BM1_GetRdPtr_RdPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_RDPTR+(index*0x4)));
    value = ( value & 0x00FFFFE0UL ) >> 5;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "IrqMask".
**
** This function writes the given value to the register "IrqMask".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_81"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_81" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_81")))
#endif

void FREG_BM1_SetIrqMask( uint32_t value )
{
    FREG_BM1_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_82"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_82" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_82")))
#endif

void FREG_BM1_SetIrqMask_IrqMask( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM1_IrqMaskMirror & ~mask;
    FREG_BM1_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqMask".
**
** This function reads the value from the register "IrqMask".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_83"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_83" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_83")))
#endif

uint32_t FREG_BM1_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM1_IrqMaskMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_84"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_84" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_84")))
#endif

uint32_t FREG_BM1_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM1_IrqMaskMirror;
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
** \brief Reads the entire register "IrqReg".
**
** This function reads the value from the register "IrqReg".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_85"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_85" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_85")))
#endif

uint32_t FREG_BM1_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM1_IRQREG));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Extracts the bitgroup "IrqReg" of register "IrqReg".
**
** The interrupt register shows in which buffer the overflow occurred.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc. When reading the register, all interrupts are cleared.
** - '0': No IRQ.
** - '1': Buffer overflow occurred in the corresponding buffer.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_86"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_86" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_86")))
#endif

uint32_t FREG_BM1_ExtractIrqReg_IrqReg( uint32_t value )
{
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
** \brief Writes the entire register "EndianSwapWr".
**
** This function writes the given value to the register "EndianSwapWr".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_87"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_87" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_87")))
#endif

void FREG_BM1_SetEndianSwapWr( uint32_t value )
{
    FREG_BM1_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm1EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM1.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm1EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_88"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_88" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_88")))
#endif

void FREG_BM1_SetEndianSwapWr_Bm1EndianSwapWr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM1_EndianSwapWrMirror & ~mask;
    FREG_BM1_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "EndianSwapWr".
**
** This function reads the value from the register "EndianSwapWr".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_89"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_89" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_89")))
#endif

uint32_t FREG_BM1_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM1_EndianSwapWrMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm1EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM1.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm1EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_90"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_90" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_90")))
#endif

uint32_t FREG_BM1_GetmEndianSwapWr_Bm1EndianSwapWr( void )
{
    register uint32_t value = FREG_BM1_EndianSwapWrMirror;
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
** \brief Writes the entire register "AudValue".
**
** This function writes the given value to the index-th entry of the register
** array AudValue.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_91"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_91" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_91")))
#endif

void FREG_BM01_SetAudValue( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return;
    #endif
    FREG_BM01_AudValueMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDVALUE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDVALUE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudCompareEn" of register "AudValue".
**
** Enables AUD detection.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudCompareEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_92"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_92" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_92")))
#endif

void FREG_BM01_SetAudValue_AudCompareEn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_BM01_AudValueMirror[index] & ~mask;
    FREG_BM01_AudValueMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDVALUE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDVALUE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudValue" of register "AudValue".
**
** The last byte of start code to be searched.
**                          The first 3 bytes are fixed to 0x000001.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudValue" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_93"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_93" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_93")))
#endif

void FREG_BM01_SetAudValue_AudValue( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_BM01_AudValueMirror[index] & ~mask;
    FREG_BM01_AudValueMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDVALUE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDVALUE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "AudValue".
**
** This function reads the value from the index-th entry of the register
** array AudValue.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_94"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_94" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_94")))
#endif

uint32_t FREG_BM01_GetmAudValue( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_AudValueMirror[index];
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudCompareEn" of register "AudValue".
**
** Enables AUD detection.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudCompareEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_95"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_95" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_95")))
#endif

uint32_t FREG_BM01_GetmAudValue_AudCompareEn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 5 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_AudValueMirror[index];
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
** \brief Reads the bitgroup "AudValue" of register "AudValue".
**
** The last byte of start code to be searched.
**                          The first 3 bytes are fixed to 0x000001.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudValue" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_96"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_96" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_96")))
#endif

uint32_t FREG_BM01_GetmAudValue_AudValue( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 5 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_AudValueMirror[index];
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
** \brief Writes the entire register "AudCfgEn".
**
** This function writes the given value to the register "AudCfgEn".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_97"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_97" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_97")))
#endif

void FREG_BM01_SetAudCfgEn( uint32_t value )
{
    FREG_BM01_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDCFGEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "GlobalAudEnable" of register "AudCfgEn".
**
** Enables AUD detection (global) and clears the search pipe line.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "GlobalAudEnable" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_98"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_98" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_98")))
#endif

void FREG_BM01_SetAudCfgEn_GlobalAudEnable( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_BM01_AudCfgEnMirror & ~mask;
    FREG_BM01_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDCFGEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudBufferIndex" of register "AudCfgEn".
**
** Defines buffer in which the AUD serach is applied.
**
** Bit 5 = '0': search the buffer specified by bit [4:0] in BM0.
** Bit 5 = '1': search a buffer specified by bit [4:0] in BM1.
** Bit [4:0]: the buffer number.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudBufferIndex" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_99"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_99" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_99")))
#endif

void FREG_BM01_SetAudCfgEn_AudBufferIndex( uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM01_AudCfgEnMirror & ~mask;
    FREG_BM01_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDCFGEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "AudCfgEn".
**
** This function reads the value from the register "AudCfgEn".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_100"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_100" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_100")))
#endif

uint32_t FREG_BM01_GetmAudCfgEn( void )
{
    register uint32_t value = FREG_BM01_AudCfgEnMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "GlobalAudEnable" of register "AudCfgEn".
**
** Enables AUD detection (global) and clears the search pipe line.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "GlobalAudEnable" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_101"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_101" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_101")))
#endif

uint32_t FREG_BM01_GetmAudCfgEn_GlobalAudEnable( void )
{
    register uint32_t value = FREG_BM01_AudCfgEnMirror;
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
** \brief Reads the bitgroup "AudBufferIndex" of register "AudCfgEn".
**
** Defines buffer in which the AUD serach is applied.
**
** Bit 5 = '0': search the buffer specified by bit [4:0] in BM0.
** Bit 5 = '1': search a buffer specified by bit [4:0] in BM1.
** Bit [4:0]: the buffer number.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudBufferIndex" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_102"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_102" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_102")))
#endif

uint32_t FREG_BM01_GetmAudCfgEn_AudBufferIndex( void )
{
    register uint32_t value = FREG_BM01_AudCfgEnMirror;
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
** \brief Reads the entire register "AudWrPointer".
**
** This function reads the value from the index-th entry of the register
** array AudWrPointer.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_103"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_103" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_103")))
#endif

uint32_t FREG_BM01_GetAudWrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_AUDWRPOINTER+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudWritePointer" of register "AudWrPointer".
**
** Address offset of AUD.
**
** Note: For absolute address, the global offset and the buffer base address need to be added                                (byte address of compare value)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudWritePointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_104"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_104" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_104")))
#endif

uint32_t FREG_BM01_GetAudWrPointer_AudWritePointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_AUDWRPOINTER+(index*0x4)));
    value = ( value & 0x00FFFFFFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "ClearAudIrq".
**
** This function writes the given value to the register "ClearAudIrq".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_105"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_105" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_105")))
#endif

void FREG_BM01_SetClearAudIrq( uint32_t value )
{
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Aud4IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Aud4IrqClr" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_106"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_106" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_106")))
#endif

void FREG_BM01_SetClearAudIrq_Aud4IrqClr( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_BM01_ClearAudIrqMirror & ~mask;
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Aud3IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Aud3IrqClr" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_107"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_107" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_107")))
#endif

void FREG_BM01_SetClearAudIrq_Aud3IrqClr( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    value |= FREG_BM01_ClearAudIrqMirror & ~mask;
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Aud2IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Aud2IrqClr" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_108"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_108" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_108")))
#endif

void FREG_BM01_SetClearAudIrq_Aud2IrqClr( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_BM01_ClearAudIrqMirror & ~mask;
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Aud1IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Aud1IrqClr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_109"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_109" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_109")))
#endif

void FREG_BM01_SetClearAudIrq_Aud1IrqClr( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_BM01_ClearAudIrqMirror & ~mask;
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Aud0IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Aud0IrqClr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_110"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_110" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_110")))
#endif

void FREG_BM01_SetClearAudIrq_Aud0IrqClr( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM01_ClearAudIrqMirror & ~mask;
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "ClearAudIrq".
**
** This function reads the value from the register "ClearAudIrq".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_111"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_111" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_111")))
#endif

uint32_t FREG_BM01_GetmClearAudIrq( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Aud4IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Aud4IrqClr" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_112"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_112" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_112")))
#endif

uint32_t FREG_BM01_GetmClearAudIrq_Aud4IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
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
** \brief Reads the bitgroup "Aud3IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Aud3IrqClr" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_113"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_113" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_113")))
#endif

uint32_t FREG_BM01_GetmClearAudIrq_Aud3IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
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
** \brief Reads the bitgroup "Aud2IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Aud2IrqClr" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_114"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_114" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_114")))
#endif

uint32_t FREG_BM01_GetmClearAudIrq_Aud2IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
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
** \brief Reads the bitgroup "Aud1IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Aud1IrqClr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_115"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_115" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_115")))
#endif

uint32_t FREG_BM01_GetmClearAudIrq_Aud1IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
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
** \brief Reads the bitgroup "Aud0IrqClr" of register "ClearAudIrq".
**
** Writing 0 clears AUD IRQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Aud0IrqClr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_116"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_116" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_116")))
#endif

uint32_t FREG_BM01_GetmClearAudIrq_Aud0IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
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
** \brief Writes the entire register "BufSize".
**
** This function writes the given value to the index-th entry of the register
** array BufSize.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_117"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_117" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_117")))
#endif

void FREG_BM2_SetBufSize( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_118"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_118" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_118")))
#endif

void FREG_BM2_SetBufSize_BufSize( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM2_BUFSIZE+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufSize".
**
** This function reads the value from the index-th entry of the register
** array BufSize.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_119"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_119" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_119")))
#endif

uint32_t FREG_BM2_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_BUFSIZE+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_120"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_120" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_120")))
#endif

uint32_t FREG_BM2_GetBufSize_BufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_BUFSIZE+(index*0x4)));
    value = ( value & 0x00FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "WrPtr".
**
** This function writes the given value to the index-th entry of the register
** array WrPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_121"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_121" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_121")))
#endif

void FREG_BM2_SetWrPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_122"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_122" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_122")))
#endif

void FREG_BM2_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM2_WRPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WrPtr".
**
** This function reads the value from the index-th entry of the register
** array WrPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_123"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_123" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_123")))
#endif

uint32_t FREG_BM2_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_WRPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_124"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_124" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_124")))
#endif

uint32_t FREG_BM2_GetWrPtr_WrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_WRPTR+(index*0x4)));
    value = ( value & 0x00FFFFFFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BaseAddr".
**
** This function writes the given value to the index-th entry of the register
** array BaseAddr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_125"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_125" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_125")))
#endif

void FREG_BM2_SetBaseAddr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_126"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_126" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_126")))
#endif

void FREG_BM2_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x07FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM2_BASEADDR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseAddr".
**
** This function reads the value from the index-th entry of the register
** array BaseAddr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_127"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_127" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_127")))
#endif

uint32_t FREG_BM2_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_BASEADDR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_128"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_128" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_128")))
#endif

uint32_t FREG_BM2_GetBaseAddr_BaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_BASEADDR+(index*0x4)));
    value = ( value & 0x07FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RdPtr".
**
** This function writes the given value to the index-th entry of the register
** array RdPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_129"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_129" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_129")))
#endif

void FREG_BM2_SetRdPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_130"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_130" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_130")))
#endif

void FREG_BM2_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFE0UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM2_RDPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RdPtr".
**
** This function reads the value from the index-th entry of the register
** array RdPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_131"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_131" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_131")))
#endif

uint32_t FREG_BM2_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_RDPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_132"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_132" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_132")))
#endif

uint32_t FREG_BM2_GetRdPtr_RdPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_RDPTR+(index*0x4)));
    value = ( value & 0x00FFFFE0UL ) >> 5;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "IrqMask".
**
** This function writes the given value to the register "IrqMask".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_133"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_133" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_133")))
#endif

void FREG_BM2_SetIrqMask( uint32_t value )
{
    FREG_BM2_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_134"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_134" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_134")))
#endif

void FREG_BM2_SetIrqMask_IrqMask( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM2_IrqMaskMirror & ~mask;
    FREG_BM2_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqMask".
**
** This function reads the value from the register "IrqMask".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_135"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_135" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_135")))
#endif

uint32_t FREG_BM2_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM2_IrqMaskMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_136"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_136" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_136")))
#endif

uint32_t FREG_BM2_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM2_IrqMaskMirror;
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
** \brief Reads the entire register "IrqReg".
**
** This function reads the value from the register "IrqReg".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_137"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_137" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_137")))
#endif

uint32_t FREG_BM2_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM2_IRQREG));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Extracts the bitgroup "IrqReg" of register "IrqReg".
**
** The interrupt register shows in which buffer the overflow occurred.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc. When reading the register, all interrupts are cleared.
** - '0': No IRQ.
** - '1': Buffer overflow occurred in the corresponding buffer.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_138"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_138" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_138")))
#endif

uint32_t FREG_BM2_ExtractIrqReg_IrqReg( uint32_t value )
{
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
** \brief Writes the entire register "ReadEnable".
**
** This function writes the given value to the register "ReadEnable".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_139"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_139" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_139")))
#endif

void FREG_BM23_SetReadEnable( uint32_t value )
{
    FREG_BM23_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_READENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23ReadSelect" of register "ReadEnable".
**
** Select HW controlled buffer from BM2 and BM3:
** - '0': buffer 0, buffer 1, ?, buffer 6 in BM2 will be used as HW controlled buffers.
**
** - '1': buffer 0, buffer 1, ?, buffer 6 in BM3 will be used as HW controlled buffers.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23ReadSelect" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_140"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_140" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_140")))
#endif

void FREG_BM23_SetReadEnable_Bm23ReadSelect( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_BM23_ReadEnableMirror & ~mask;
    FREG_BM23_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_READENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23ReadEnable" of register "ReadEnable".
**
** Enables read access of HW controlled buffers.
**  Bit n corresponds to buffer n.
** - '0': read access of the corresponding buffer is disabled.
** - '1': read access of the corresponding buffer is enabled.
** Bit 6: buffer 6 (for audio).
** Bit 5: buffer 5 (for TTX).
** Bit 4: buffer 4 (for SPDIF).
** Bit 3: buffer 3 (for I2S_3).
** Bit 2: buffer 2 (for I2S_2).
** Bit 1: buffer 1 (for I2S_1).
** Bit 0: buffer 0 (for I2S_0).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23ReadEnable" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_141"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_141" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_141")))
#endif

void FREG_BM23_SetReadEnable_Bm23ReadEnable( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM23_ReadEnableMirror & ~mask;
    FREG_BM23_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_READENABLE)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "ReadEnable".
**
** This function reads the value from the register "ReadEnable".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_142"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_142" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_142")))
#endif

uint32_t FREG_BM23_GetmReadEnable( void )
{
    register uint32_t value = FREG_BM23_ReadEnableMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23ReadSelect" of register "ReadEnable".
**
** Select HW controlled buffer from BM2 and BM3:
** - '0': buffer 0, buffer 1, ?, buffer 6 in BM2 will be used as HW controlled buffers.
**
** - '1': buffer 0, buffer 1, ?, buffer 6 in BM3 will be used as HW controlled buffers.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23ReadSelect" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_143"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_143" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_143")))
#endif

uint32_t FREG_BM23_GetmReadEnable_Bm23ReadSelect( void )
{
    register uint32_t value = FREG_BM23_ReadEnableMirror;
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
** \brief Reads the bitgroup "Bm23ReadEnable" of register "ReadEnable".
**
** Enables read access of HW controlled buffers.
**  Bit n corresponds to buffer n.
** - '0': read access of the corresponding buffer is disabled.
** - '1': read access of the corresponding buffer is enabled.
** Bit 6: buffer 6 (for audio).
** Bit 5: buffer 5 (for TTX).
** Bit 4: buffer 4 (for SPDIF).
** Bit 3: buffer 3 (for I2S_3).
** Bit 2: buffer 2 (for I2S_2).
** Bit 1: buffer 1 (for I2S_1).
** Bit 0: buffer 0 (for I2S_0).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23ReadEnable" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_144"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_144" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_144")))
#endif

uint32_t FREG_BM23_GetmReadEnable_Bm23ReadEnable( void )
{
    register uint32_t value = FREG_BM23_ReadEnableMirror;
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
** \brief Writes the entire register "GlobalOffset".
**
** This function writes the given value to the register "GlobalOffset".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_145"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_145" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_145")))
#endif

void FREG_BM23_SetGlobalOffset( uint32_t value )
{
    FREG_BM23_GlobalOffsetMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_GLOBALOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_GLOBALOFFSET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23Offset" of register "GlobalOffset".
**
** Global offset for BM2 and BM3.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23Offset" consists of the bits 31..27,
**       the given bitgroup value will be shifted left by 27 bits and
**       masked using the bitmask 0xF8000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_146"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_146" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_146")))
#endif

void FREG_BM23_SetGlobalOffset_Bm23Offset( uint32_t value )
{
    register uint32_t mask = 0xF8000000UL;
    value = ( value << 27 ) & mask;
    value |= FREG_BM23_GlobalOffsetMirror & ~mask;
    FREG_BM23_GlobalOffsetMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_GLOBALOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_GLOBALOFFSET)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "GlobalOffset".
**
** This function reads the value from the register "GlobalOffset".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_147"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_147" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_147")))
#endif

uint32_t FREG_BM23_GetmGlobalOffset( void )
{
    register uint32_t value = FREG_BM23_GlobalOffsetMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23Offset" of register "GlobalOffset".
**
** Global offset for BM2 and BM3.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23Offset" consists of the bits 31..27,
**       the given bitgroup value will be shifted left by 27 bits and
**       masked using the bitmask 0xF8000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_148"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_148" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_148")))
#endif

uint32_t FREG_BM23_GetmGlobalOffset_Bm23Offset( void )
{
    register uint32_t value = FREG_BM23_GlobalOffsetMirror;
    value = ( value & 0xF8000000UL ) >> 27;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "EndianSwapWr".
**
** This function writes the given value to the register "EndianSwapWr".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_149"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_149" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_149")))
#endif

void FREG_BM2_SetEndianSwapWr( uint32_t value )
{
    FREG_BM2_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm2EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM2.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm2EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_150"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_150" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_150")))
#endif

void FREG_BM2_SetEndianSwapWr_Bm2EndianSwapWr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM2_EndianSwapWrMirror & ~mask;
    FREG_BM2_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "EndianSwapWr".
**
** This function reads the value from the register "EndianSwapWr".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_151"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_151" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_151")))
#endif

uint32_t FREG_BM2_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM2_EndianSwapWrMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm2EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM2.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm2EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_152"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_152" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_152")))
#endif

uint32_t FREG_BM2_GetmEndianSwapWr_Bm2EndianSwapWr( void )
{
    register uint32_t value = FREG_BM2_EndianSwapWrMirror;
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
** \brief Writes the entire register "BufLowLev".
**
** This function writes the given value to the index-th entry of the register
** array BufLowLev.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_153"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_153" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_153")))
#endif

void FREG_BM23_SetBufLowLev( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    FREG_BM23_BufLowLevMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFLOWLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFLOWLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23BufLowLevIrqEn" of register "BufLowLev".
**
** Buffer low level IRQ enable (Buffer 7 to 0.
**  n = buffer number)
** - '0': Low level IRQ disabled.
** - '1': Low level IRQ enabled.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23BufLowLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_154"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_154" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_154")))
#endif

void FREG_BM23_SetBufLowLev_Bm23BufLowLevIrqEn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 31 ) & mask;
    value |= FREG_BM23_BufLowLevMirror[index] & ~mask;
    FREG_BM23_BufLowLevMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFLOWLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFLOWLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23BufLowLev" of register "BufLowLev".
**
** Buffer low level threshold when IRQ is activated.
**
** Attention: Bit 5 must be always set to 0!
** If number of bytes availabe in the buffer is less than the value BM23_BUF_LOW_LEV[23:6] times 64, a low level IRQ (buffer almost empty IRQ) will be generated.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23BufLowLev" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_155"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_155" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_155")))
#endif

void FREG_BM23_SetBufLowLev_Bm23BufLowLev( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFE0UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    value |= FREG_BM23_BufLowLevMirror[index] & ~mask;
    FREG_BM23_BufLowLevMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFLOWLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFLOWLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufLowLev".
**
** This function reads the value from the index-th entry of the register
** array BufLowLev.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_156"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_156" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_156")))
#endif

uint32_t FREG_BM23_GetmBufLowLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_BufLowLevMirror[index];
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufLowLevIrqEn" of register "BufLowLev".
**
** Buffer low level IRQ enable (Buffer 7 to 0.
**  n = buffer number)
** - '0': Low level IRQ disabled.
** - '1': Low level IRQ enabled.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufLowLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_157"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_157" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_157")))
#endif

uint32_t FREG_BM23_GetmBufLowLev_Bm23BufLowLevIrqEn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 8 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_BufLowLevMirror[index];
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufLowLev" of register "BufLowLev".
**
** Buffer low level threshold when IRQ is activated.
**
** Attention: Bit 5 must be always set to 0!
** If number of bytes availabe in the buffer is less than the value BM23_BUF_LOW_LEV[23:6] times 64, a low level IRQ (buffer almost empty IRQ) will be generated.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufLowLev" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_158"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_158" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_158")))
#endif

uint32_t FREG_BM23_GetmBufLowLev_Bm23BufLowLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 8 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_BufLowLevMirror[index];
    value = ( value & 0x00FFFFE0UL ) >> 5;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BufHighLev".
**
** This function writes the given value to the index-th entry of the register
** array BufHighLev.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_159"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_159" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_159")))
#endif

void FREG_BM23_SetBufHighLev( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23BufHighLevIrqEn" of register "BufHighLev".
**
** High level IRQ enable bit.
**
** - '0': High level IRQ disabled.
** - '1': High level IRQ enabled.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23BufHighLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_160"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_160" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_160")))
#endif

void FREG_BM23_SetBufHighLev_Bm23BufHighLevIrqEn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x80000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 31 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23BufHighLevLimit" of register "BufHighLev".
**
** Buffer high level threshold value where IRQ is activated (bits correspond to byte address bits).
**  If number of free bytes in the corresponding buffer is less than this limit times 512, a buffer high level IRQ (buffer almost full IRQ) will be generated.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23BufHighLevLimit" consists of the bits 23..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00FFFF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_161"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_161" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_161")))
#endif

void FREG_BM23_SetBufHighLev_Bm23BufHighLevLimit( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm23BufHighLevStreamNb" of register "BufHighLev".
**
** Defines for which buffer the limit is applied.
**
** Bit 5: indicates to  which BM the defined buffer belongs.
** - '0': the buffer belongs to BM2.
** - '1': the buffer belongs to BM3.
** Bits [4:0] range from 0 to 31 and defines the buffer number.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm23BufHighLevStreamNb" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_162"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_162" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_162")))
#endif

void FREG_BM23_SetBufHighLev_Bm23BufHighLevStreamNb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_BUFHIGHLEV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufHighLev".
**
** This function reads the value from the index-th entry of the register
** array BufHighLev.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_163"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_163" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_163")))
#endif

uint32_t FREG_BM23_GetBufHighLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufHighLevIrqEn" of register "BufHighLev".
**
** High level IRQ enable bit.
**
** - '0': High level IRQ disabled.
** - '1': High level IRQ enabled.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufHighLevIrqEn" consists of the bits 31..31,
**       the given bitgroup value will be shifted left by 31 bits and
**       masked using the bitmask 0x80000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_164"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_164" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_164")))
#endif

uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevIrqEn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4)));
    value = ( value & 0x80000000UL ) >> 31;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufHighLevLimit" of register "BufHighLev".
**
** Buffer high level threshold value where IRQ is activated (bits correspond to byte address bits).
**  If number of free bytes in the corresponding buffer is less than this limit times 512, a buffer high level IRQ (buffer almost full IRQ) will be generated.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufHighLevLimit" consists of the bits 23..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00FFFF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_165"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_165" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_165")))
#endif

uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevLimit( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4)));
    value = ( value & 0x00FFFF00UL ) >> 8;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufHighLevStreamNb" of register "BufHighLev".
**
** Defines for which buffer the limit is applied.
**
** Bit 5: indicates to  which BM the defined buffer belongs.
** - '0': the buffer belongs to BM2.
** - '1': the buffer belongs to BM3.
** Bits [4:0] range from 0 to 31 and defines the buffer number.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufHighLevStreamNb" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_166"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_166" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_166")))
#endif

uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevStreamNb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4)));
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
** \brief Reads the entire register "StatusRd".
**
** This function reads the value from the register "StatusRd".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_167"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_167" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_167")))
#endif

uint32_t FREG_BM23_GetStatusRd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BmStreamStatus" of register "StatusRd".
**
** Indicates the BM status.
**
** Bit 30 indicates if some TS packet is being sent to memory.
** - '0': No TS packet is being processed. Both BM0
** and BM1 are in idle state. In this case the bits
** [29:24] are set to 0.
** - '1': A TS packet is being processed. BM0 or
** BM1 is busy.
** Bit 29 indicates which BM is busy (BM0 or BM1).
** - '0': BM0 is busy (if bit 30 is 1).
** - '1': BM1is busy (if bit 30 is 1).
**
** If bit 30 is 1, the bits [28:24] are buffer index and range from 0 to 31. Together with bit 29 these bits indicate which buffer from which BM is being accessed.
**
** If bit 30 is 0, these bits can be ignored.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BmStreamStatus" consists of the bits 30..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0x7F000000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_168"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_168" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_168")))
#endif

uint32_t FREG_BM23_GetStatusRd_BmStreamStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x7F000000UL ) >> 24;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudIrq" of register "StatusRd".
**
** IRQ status of AUD's.
**
** Bit 23:
** - '0': AUD value defined in register
** BM01_AUD_VALUE+4*4 is not detected.
** - '1': AUD value defined in register
** BM01_AUD_VALUE+4*4 is detected.
** Bit 22:
** - '0': AUD value defined in register
** BM01_AUD_VALUE+4*3 is not detected.
** - '1': AUD value defined in register
** BM01_AUD_VALUE+4*3 is detected.
** Bit 21, bit 20 and bit 19 are defined similarly.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudIrq" consists of the bits 23..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00F80000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_169"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_169" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_169")))
#endif

uint32_t FREG_BM23_GetStatusRd_AudIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x00F80000UL ) >> 19;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LevelIrq" of register "StatusRd".
**
** Level IRQ status.
**
** - '0': wether high nor low level IRQ detected.
** - '1': either high or low level IRQ deteced.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LevelIrq" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_170"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_170" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_170")))
#endif

uint32_t FREG_BM23_GetStatusRd_LevelIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
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
** \brief Reads the bitgroup "Bm2Int" of register "StatusRd".
**
** BM2 overflow IRQ status.
**
** - '0': No buffer in BM2 overflows.
** - '1': Some buffer in BM2 overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm2Int" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_171"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_171" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_171")))
#endif

uint32_t FREG_BM23_GetStatusRd_Bm2Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
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
** \brief Reads the bitgroup "Bm3Int" of register "StatusRd".
**
** BM3 overflow IRQ status.
**
** - '0': No buffer in BM31 overflows.
** - '1': Some buffer in BM3 overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm3Int" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_172"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_172" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_172")))
#endif

uint32_t FREG_BM23_GetStatusRd_Bm3Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
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
** \brief Reads the bitgroup "BufferLowIrqFlag" of register "StatusRd".
**
** Low level IRQ status.
**
** Bit 15:
** - '0': Low level IRQ in Hardware controlled buffer 7 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 7
** dectected.
** Bit 14:
** - '0': Low level IRQ in Hardware controlled buffer 6 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 6
** dectected.
** ... ...
** Bit 8:
** - '0': Low level IRQ in Hardware controlled buffer 0 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 0
** dectected.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferLowIrqFlag" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_173"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_173" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_173")))
#endif

uint32_t FREG_BM23_GetStatusRd_BufferLowIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
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
** \brief Reads the bitgroup "BufferHighIrqFlag" of register "StatusRd".
**
** High level IRQ status.
**
** Bit 7:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is detected.
** Bit 6:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is detected.
** Bit 5, ..., bit 0 are defined similarly.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferHighIrqFlag" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_174"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_174" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_174")))
#endif

uint32_t FREG_BM23_GetStatusRd_BufferHighIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
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
** \brief Reads the entire register "BufHighLevIrqClr".
**
** This function reads the value from the index-th entry of the register
** array BufHighLevIrqClr.
**
** A read access of this register will clear the high level IRQ corresponding to the address offset n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_175"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_175" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_175")))
#endif

uint32_t FREG_BM23_GetBufHighLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEVIRQCLR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufHighLevIrqClr" of register "BufHighLevIrqClr".
**
** A read access of this register will clear the high level IRQ corresponding to the address offset n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufHighLevIrqClr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_176"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_176" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_176")))
#endif

uint32_t FREG_BM23_GetBufHighLevIrqClr_Bm23BufHighLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEVIRQCLR+(index*0x4)));
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
** \brief Reads the entire register "BufLowLevIrqClr".
**
** This function reads the value from the index-th entry of the register
** array BufLowLevIrqClr.
**
** A read access of this register will clear the low level IRQ in buffer n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_177"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_177" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_177")))
#endif

uint32_t FREG_BM23_GetBufLowLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFLOWLEVIRQCLR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufLowLevIrqClr" of register "BufLowLevIrqClr".
**
** A read access of this register will clear the low level IRQ in buffer n (IRQ 0 to 7).
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufLowLevIrqClr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_178"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_178" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_178")))
#endif

uint32_t FREG_BM23_GetBufLowLevIrqClr_Bm23BufLowLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFLOWLEVIRQCLR+(index*0x4)));
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
** \brief Reads the entire register "BufStreamIrqClr".
**
** This function reads the value from the index-th entry of the register
** array BufStreamIrqClr.
**
** A read access of this register will clear the buffer overflow IRQ in buffer n of BM23  (n = 0, 1, ?, 63).
**  The indices 0 to 31 correspond to buffers in BM2 and the indices 32 to 63 correspond to buffers in BM3.
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_179"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_179" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_179")))
#endif

uint32_t FREG_BM23_GetBufStreamIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFSTREAMIRQCLR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm23BufStreamIrqClr" of register "BufStreamIrqClr".
**
** A read access of this register will clear the buffer overflow IRQ in buffer n of BM23  (n = 0, 1, ?, 63).
**  The indices 0 to 31 correspond to buffers in BM2 and the indices 32 to 63 correspond to buffers in BM3.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm23BufStreamIrqClr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_180"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_180" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_180")))
#endif

uint32_t FREG_BM23_GetBufStreamIrqClr_Bm23BufStreamIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFSTREAMIRQCLR+(index*0x4)));
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
** \brief Writes the entire register "BufSize".
**
** This function writes the given value to the index-th entry of the register
** array BufSize.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_181"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_181" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_181")))
#endif

void FREG_BM3_SetBufSize( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_182"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_182" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_182")))
#endif

void FREG_BM3_SetBufSize_BufSize( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM3_BUFSIZE+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_BUFSIZE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_BUFSIZE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufSize".
**
** This function reads the value from the index-th entry of the register
** array BufSize.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_183"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_183" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_183")))
#endif

uint32_t FREG_BM3_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_BUFSIZE+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BufSize" of register "BufSize".
**
** Buffer size in 1K-byte blocks.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufSize" consists of the bits 23..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_184"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_184" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_184")))
#endif

uint32_t FREG_BM3_GetBufSize_BufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_BUFSIZE+(index*0x4)));
    value = ( value & 0x00FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "WrPtr".
**
** This function writes the given value to the index-th entry of the register
** array WrPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_185"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_185" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_185")))
#endif

void FREG_BM3_SetWrPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_186"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_186" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_186")))
#endif

void FREG_BM3_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM3_WRPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_WRPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_WRPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WrPtr".
**
** This function reads the value from the index-th entry of the register
** array WrPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_187"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_187" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_187")))
#endif

uint32_t FREG_BM3_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_WRPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WrPointer" of register "WrPtr".
**
** Write Pointer (byte address)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "WrPointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_188"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_188" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_188")))
#endif

uint32_t FREG_BM3_GetWrPtr_WrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_WRPTR+(index*0x4)));
    value = ( value & 0x00FFFFFFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BaseAddr".
**
** This function writes the given value to the index-th entry of the register
** array BaseAddr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_189"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_189" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_189")))
#endif

void FREG_BM3_SetBaseAddr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_190"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_190" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_190")))
#endif

void FREG_BM3_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x07FFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM3_BASEADDR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_BASEADDR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_BASEADDR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BaseAddr".
**
** This function reads the value from the index-th entry of the register
** array BaseAddr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_191"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_191" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_191")))
#endif

uint32_t FREG_BM3_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_BASEADDR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BaseAddr" of register "BaseAddr".
**
** Buffer base address can only be set in steps of 1K bytes.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BaseAddr" consists of the bits 26..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x07FFFC00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_192"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_192" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_192")))
#endif

uint32_t FREG_BM3_GetBaseAddr_BaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_BASEADDR+(index*0x4)));
    value = ( value & 0x07FFFC00UL ) >> 10;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RdPtr".
**
** This function writes the given value to the index-th entry of the register
** array RdPtr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_193"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_193" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_193")))
#endif

void FREG_BM3_SetRdPtr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_194"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_194" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_194")))
#endif

void FREG_BM3_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FFFFE0UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM3_RDPTR+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_RDPTR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_RDPTR+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RdPtr".
**
** This function reads the value from the index-th entry of the register
** array RdPtr.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_195"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_195" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_195")))
#endif

uint32_t FREG_BM3_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_RDPTR+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RdPointer" of register "RdPtr".
**
** Read Pointer (byte address).
**  Attention: Bit 5 must be set to 0!
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdPointer" consists of the bits 23..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00FFFFE0UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_196"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_196" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_196")))
#endif

uint32_t FREG_BM3_GetRdPtr_RdPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_RDPTR+(index*0x4)));
    value = ( value & 0x00FFFFE0UL ) >> 5;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "IrqMask".
**
** This function writes the given value to the register "IrqMask".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_197"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_197" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_197")))
#endif

void FREG_BM3_SetIrqMask( uint32_t value )
{
    FREG_BM3_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_198"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_198" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_198")))
#endif

void FREG_BM3_SetIrqMask_IrqMask( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM3_IrqMaskMirror & ~mask;
    FREG_BM3_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_IRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqMask".
**
** This function reads the value from the register "IrqMask".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_199"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_199" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_199")))
#endif

uint32_t FREG_BM3_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM3_IrqMaskMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqMask" of register "IrqMask".
**
** IRQ mask of BM0.
**  Each bit masks the buffer overflow interrupt. Bit 0 corresponds to buffer 0, bit 1 to buffer 1 etc.
** - '0': buffer overflow interrupt enabled.
** - '1': buffer overflow interrupt disabled (masked).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_200"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_200" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_200")))
#endif

uint32_t FREG_BM3_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM3_IrqMaskMirror;
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
** \brief Reads the entire register "IrqReg".
**
** This function reads the value from the register "IrqReg".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_201"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_201" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_201")))
#endif

uint32_t FREG_BM3_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM3_IRQREG));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Extracts the bitgroup "IrqReg" of register "IrqReg".
**
** The interrupt register shows in which buffer the overflow occurred.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc. When reading the register, all interrupts are cleared.
** - '0': No IRQ.
** - '1': Buffer overflow occurred in the corresponding buffer.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_202"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_202" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_202")))
#endif

uint32_t FREG_BM3_ExtractIrqReg_IrqReg( uint32_t value )
{
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
** \brief Writes the entire register "EndianSwapWr".
**
** This function writes the given value to the register "EndianSwapWr".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_203"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_203" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_203")))
#endif

void FREG_BM3_SetEndianSwapWr( uint32_t value )
{
    FREG_BM3_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bm3EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM3.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bm3EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_204"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_204" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_204")))
#endif

void FREG_BM3_SetEndianSwapWr_Bm3EndianSwapWr( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM3_EndianSwapWrMirror & ~mask;
    FREG_BM3_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_ENDIANSWAPWR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "EndianSwapWr".
**
** This function reads the value from the register "EndianSwapWr".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_205"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_205" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_205")))
#endif

uint32_t FREG_BM3_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM3_EndianSwapWrMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bm3EndianSwapWr" of register "EndianSwapWr".
**
** Enables endian swap for buffer 31 to 0 of BM3.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n (n= 0, 1, ?, 31):
** - '0': write big endian (default) in buffer n.
** - '1': write little endian in buffer n.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bm3EndianSwapWr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_206"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_206" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_206")))
#endif

uint32_t FREG_BM3_GetmEndianSwapWr_Bm3EndianSwapWr( void )
{
    register uint32_t value = FREG_BM3_EndianSwapWrMirror;
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
** \brief Writes the entire register "AudValue".
**
** This function writes the given value to the index-th entry of the register
** array AudValue.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_207"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_207" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_207")))
#endif

void FREG_BM23_SetAudValue( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return;
    #endif
    FREG_BM23_AudValueMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDVALUE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDVALUE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudCompareEn" of register "AudValue".
**
** Enables AUD detection.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudCompareEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_208"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_208" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_208")))
#endif

void FREG_BM23_SetAudValue_AudCompareEn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_BM23_AudValueMirror[index] & ~mask;
    FREG_BM23_AudValueMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDVALUE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDVALUE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudValue" of register "AudValue".
**
** The last byte of start code to be searched.
**                          The first 3 bytes are fixed to 0x000001.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudValue" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_209"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_209" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_209")))
#endif

void FREG_BM23_SetAudValue_AudValue( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_BM23_AudValueMirror[index] & ~mask;
    FREG_BM23_AudValueMirror[index] = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDVALUE+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDVALUE+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "AudValue".
**
** This function reads the value from the index-th entry of the register
** array AudValue.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_210"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_210" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_210")))
#endif

uint32_t FREG_BM23_GetmAudValue( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_AudValueMirror[index];
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudCompareEn" of register "AudValue".
**
** Enables AUD detection.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudCompareEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_211"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_211" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_211")))
#endif

uint32_t FREG_BM23_GetmAudValue_AudCompareEn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 5 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_AudValueMirror[index];
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
** \brief Reads the bitgroup "AudValue" of register "AudValue".
**
** The last byte of start code to be searched.
**                          The first 3 bytes are fixed to 0x000001.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudValue" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_212"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_212" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_212")))
#endif

uint32_t FREG_BM23_GetmAudValue_AudValue( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 5 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_AudValueMirror[index];
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
** \brief Writes the entire register "AudCfgEn".
**
** This function writes the given value to the register "AudCfgEn".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_213"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_213" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_213")))
#endif

void FREG_BM23_SetAudCfgEn( uint32_t value )
{
    FREG_BM23_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDCFGEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "GlobalAudEnable" of register "AudCfgEn".
**
** Enables AUD detection (global)                               clears the search pipe line
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "GlobalAudEnable" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_214"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_214" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_214")))
#endif

void FREG_BM23_SetAudCfgEn_GlobalAudEnable( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_BM23_AudCfgEnMirror & ~mask;
    FREG_BM23_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDCFGEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudBufferIndex" of register "AudCfgEn".
**
** Defines buffer in which the AUD serach is applied.
**
** Bit 5 = '0': search the buffer specified by bit [4:0] in BM2.
** Bit 5 = '1': search a buffer specified by bit [4:0] in BM3.
** Bit [4:0]: the buffer number.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudBufferIndex" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_215"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_215" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_215")))
#endif

void FREG_BM23_SetAudCfgEn_AudBufferIndex( uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM23_AudCfgEnMirror & ~mask;
    FREG_BM23_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDCFGEN)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "AudCfgEn".
**
** This function reads the value from the register "AudCfgEn".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_216"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_216" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_216")))
#endif

uint32_t FREG_BM23_GetmAudCfgEn( void )
{
    register uint32_t value = FREG_BM23_AudCfgEnMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "GlobalAudEnable" of register "AudCfgEn".
**
** Enables AUD detection (global)                               clears the search pipe line
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "GlobalAudEnable" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_217"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_217" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_217")))
#endif

uint32_t FREG_BM23_GetmAudCfgEn_GlobalAudEnable( void )
{
    register uint32_t value = FREG_BM23_AudCfgEnMirror;
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
** \brief Reads the bitgroup "AudBufferIndex" of register "AudCfgEn".
**
** Defines buffer in which the AUD serach is applied.
**
** Bit 5 = '0': search the buffer specified by bit [4:0] in BM2.
** Bit 5 = '1': search a buffer specified by bit [4:0] in BM3.
** Bit [4:0]: the buffer number.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudBufferIndex" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_218"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_218" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_218")))
#endif

uint32_t FREG_BM23_GetmAudCfgEn_AudBufferIndex( void )
{
    register uint32_t value = FREG_BM23_AudCfgEnMirror;
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
** \brief Reads the entire register "AudWrPointer".
**
** This function reads the value from the index-th entry of the register
** array AudWrPointer.
**
**
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_219"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_219" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_219")))
#endif

uint32_t FREG_BM23_GetAudWrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_AUDWRPOINTER+(index*0x4)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudWritePointer" of register "AudWrPointer".
**
** Address offset of AUD.
**
** Note: For absolute address, the global offset and the buffer base address need to be added                                (byte address of compare value)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudWritePointer" consists of the bits 23..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00FFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_220"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_220" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_220")))
#endif

uint32_t FREG_BM23_GetAudWrPointer_AudWritePointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_AUDWRPOINTER+(index*0x4)));
    value = ( value & 0x00FFFFFFUL ) >> 0;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "ClearAudIrq".
**
** This function writes the given value to the register "ClearAudIrq".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_221"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_221" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_221")))
#endif

void FREG_BM23_SetClearAudIrq( uint32_t value )
{
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_CLEARAUDIRQ)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "OverflowIrq".
**
** This function reads the value from the register "OverflowIrq".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_222"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_222" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_222")))
#endif

uint32_t FREG_BM0_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM0_OVERFLOWIRQ));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqReg" of register "OverflowIrq".
**
** This interrupt register indicates which buffer in BM0 overflows.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** - '0': Buffer n doesn't overflow.
** - '1': Buffer n overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_223"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_223" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_223")))
#endif

uint32_t FREG_BM0_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM0_OVERFLOWIRQ));
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
** \brief Reads the entire register "OverflowIrq".
**
** This function reads the value from the register "OverflowIrq".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_224"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_224" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_224")))
#endif

uint32_t FREG_BM1_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM1_OVERFLOWIRQ));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqReg" of register "OverflowIrq".
**
** This interrupt register indicates which buffer in BM1 overflows.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n:
** - '0': Buffer n doesn't overflow.
** - '1': Buffer n overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_225"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_225" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_225")))
#endif

uint32_t FREG_BM1_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM1_OVERFLOWIRQ));
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
** \brief Reads the entire register "OverflowIrq".
**
** This function reads the value from the register "OverflowIrq".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_226"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_226" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_226")))
#endif

uint32_t FREG_BM2_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM2_OVERFLOWIRQ));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqReg" of register "OverflowIrq".
**
** This interrupt register indicates which buffer in BM0 overflows.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n:
** - '0': Buffer n doesn't overflow.
** - '1': Buffer n overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_227"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_227" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_227")))
#endif

uint32_t FREG_BM2_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM2_OVERFLOWIRQ));
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
** \brief Reads the entire register "OverflowIrq".
**
** This function reads the value from the register "OverflowIrq".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_228"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_228" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_228")))
#endif

uint32_t FREG_BM3_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM3_OVERFLOWIRQ));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqReg" of register "OverflowIrq".
**
** This interrupt register indicates which buffer in BM1 overflows.
**  Bit 0 corresponds to buffer 0, bit 1 to buffer 1, etc.
** Bit n:
** - '0': Buffer n doesn't overflow.
** - '1': Buffer n overflows.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReg" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_229"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_229" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_229")))
#endif

uint32_t FREG_BM3_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM3_OVERFLOWIRQ));
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
** \brief Writes the entire register "HcbSelect".
**
** This function writes the given value to the register "HcbSelect".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_230"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_230" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_230")))
#endif

void FREG_BM_SetHcbSelect( uint32_t value )
{
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudioHcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) AUDIO:
** - '0': select the HCB AUDIO in BM01.
**
** - '1': select the HCB AUDIO in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudioHcbSelect" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_231"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_231" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_231")))
#endif

void FREG_BM_SetHcbSelect_AudioHcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxHcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) TTX:
** - '0': select the HCB TTX in BM01.
**
** - '1': select the HCB TTX in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxHcbSelect" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_232"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_232" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_232")))
#endif

void FREG_BM_SetHcbSelect_TtxHcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpdifHcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) SPDIF:
** - '0': select the HCB SPDIF in BM01.
**
** - '1': select the HCB SPDIF in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpdifHcbSelect" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_233"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_233" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_233")))
#endif

void FREG_BM_SetHcbSelect_SpdifHcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s3HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_3:
** - '0': select the HCB I2S_3 in BM01.
**
** - '1': select the HCB I2S_3 in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s3HcbSelect" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_234"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_234" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_234")))
#endif

void FREG_BM_SetHcbSelect_I2s3HcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s2HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_2:
** - '0': select the HCB I2S_2 in BM01.
**
** - '1': select the HCB I2S_2 in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s2HcbSelect" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_235"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_235" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_235")))
#endif

void FREG_BM_SetHcbSelect_I2s2HcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s1HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_1:
** - '0': select the HCB I2S_1 in BM01.
**
** - '1': select the HCB I2S_1 in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s1HcbSelect" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_236"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_236" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_236")))
#endif

void FREG_BM_SetHcbSelect_I2s1HcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s0HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_0:
** - '0': select the HCB I2S_0 in BM01.
**
** - '1': select the HCB I2S_0 in BM23.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s0HcbSelect" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_237"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_237" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_237")))
#endif

void FREG_BM_SetHcbSelect_I2s0HcbSelect( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_BM_HCBSELECT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "HcbSelect".
**
** This function reads the value from the register "HcbSelect".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_238"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_238" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_238")))
#endif

uint32_t FREG_BM_GetHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudioHcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) AUDIO:
** - '0': select the HCB AUDIO in BM01.
**
** - '1': select the HCB AUDIO in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudioHcbSelect" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_239"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_239" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_239")))
#endif

uint32_t FREG_BM_GetHcbSelect_AudioHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Reads the bitgroup "TtxHcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) TTX:
** - '0': select the HCB TTX in BM01.
**
** - '1': select the HCB TTX in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxHcbSelect" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_240"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_240" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_240")))
#endif

uint32_t FREG_BM_GetHcbSelect_TtxHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Reads the bitgroup "SpdifHcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) SPDIF:
** - '0': select the HCB SPDIF in BM01.
**
** - '1': select the HCB SPDIF in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpdifHcbSelect" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_241"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_241" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_241")))
#endif

uint32_t FREG_BM_GetHcbSelect_SpdifHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Reads the bitgroup "I2s3HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_3:
** - '0': select the HCB I2S_3 in BM01.
**
** - '1': select the HCB I2S_3 in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s3HcbSelect" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_242"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_242" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_242")))
#endif

uint32_t FREG_BM_GetHcbSelect_I2s3HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Reads the bitgroup "I2s2HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_2:
** - '0': select the HCB I2S_2 in BM01.
**
** - '1': select the HCB I2S_2 in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s2HcbSelect" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_243"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_243" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_243")))
#endif

uint32_t FREG_BM_GetHcbSelect_I2s2HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Reads the bitgroup "I2s1HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_1:
** - '0': select the HCB I2S_1 in BM01.
**
** - '1': select the HCB I2S_1 in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s1HcbSelect" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_244"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_244" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_244")))
#endif

uint32_t FREG_BM_GetHcbSelect_I2s1HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Reads the bitgroup "I2s0HcbSelect" of register "HcbSelect".
**
** Select the hardware controlled buffer (HCB) I2S_0:
** - '0': select the HCB I2S_0 in BM01.
**
** - '1': select the HCB I2S_0 in BM23.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s0HcbSelect" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_245"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_245" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_245")))
#endif

uint32_t FREG_BM_GetHcbSelect_I2s0HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
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
** \brief Writes the entire register "EndianSwapRd".
**
** This function writes the given value to the register "EndianSwapRd".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_246"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_246" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_246")))
#endif

void FREG_BM01_SetEndianSwapRd( uint32_t value )
{
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudioRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables 2-byte endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudioRd2byteLittleEndian" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_247"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_247" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_247")))
#endif

void FREG_BM01_SetEndianSwapRd_AudioRd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxRd2byteLittleEndian" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_248"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_248" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_248")))
#endif

void FREG_BM01_SetEndianSwapRd_TtxRd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpdifRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpdifRd2byteLittleEndian" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_249"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_249" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_249")))
#endif

void FREG_BM01_SetEndianSwapRd_SpdifRd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s3Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s3Rd2byteLittleEndian" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_250"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_250" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_250")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s3Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s2Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s2Rd2byteLittleEndian" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_251"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_251" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_251")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s2Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s1Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s1Rd2byteLittleEndian" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_252"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_252" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_252")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s1Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s0Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s0Rd2byteLittleEndian" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_253"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_253" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_253")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s0Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudioRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudioRdLittleEndian" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_254"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_254" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_254")))
#endif

void FREG_BM01_SetEndianSwapRd_AudioRdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxRdLittleEndian" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_255"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_255" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_255")))
#endif

void FREG_BM01_SetEndianSwapRd_TtxRdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpdifRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpdifRdLittleEndian" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_256"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_256" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_256")))
#endif

void FREG_BM01_SetEndianSwapRd_SpdifRdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s3RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s3RdLittleEndian" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_257"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_257" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_257")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s3RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s2RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s2RdLittleEndian" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_258"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_258" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_258")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s2RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s1RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s1RdLittleEndian" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_259"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_259" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_259")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s1RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s0RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s0RdLittleEndian" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_260"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_260" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_260")))
#endif

void FREG_BM01_SetEndianSwapRd_I2s0RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM01_EndianSwapRdMirror & ~mask;
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "EndianSwapRd".
**
** This function reads the value from the register "EndianSwapRd".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_261"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_261" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_261")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudioRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables 2-byte endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudioRd2byteLittleEndian" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_262"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_262" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_262")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_AudioRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "TtxRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxRd2byteLittleEndian" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_263"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_263" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_263")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_TtxRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "SpdifRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpdifRd2byteLittleEndian" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_264"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_264" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_264")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_SpdifRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s3Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s3Rd2byteLittleEndian" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_265"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_265" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_265")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s3Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s2Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s2Rd2byteLittleEndian" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_266"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_266" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_266")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s2Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s1Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s1Rd2byteLittleEndian" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_267"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_267" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_267")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s1Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s0Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s0Rd2byteLittleEndian" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_268"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_268" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_268")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s0Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "AudioRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudioRdLittleEndian" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_269"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_269" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_269")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_AudioRdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "TtxRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxRdLittleEndian" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_270"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_270" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_270")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_TtxRdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "SpdifRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpdifRdLittleEndian" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_271"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_271" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_271")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_SpdifRdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s3RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s3RdLittleEndian" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_272"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_272" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_272")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s3RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s2RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s2RdLittleEndian" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_273"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_273" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_273")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s2RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s1RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s1RdLittleEndian" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_274"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_274" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_274")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s1RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s0RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s0RdLittleEndian" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_275"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_275" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_275")))
#endif

uint32_t FREG_BM01_GetmEndianSwapRd_I2s0RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
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
** \brief Writes the entire register "EndianSwapRd".
**
** This function writes the given value to the register "EndianSwapRd".
**
**
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_276"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_276" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_276")))
#endif

void FREG_BM23_SetEndianSwapRd( uint32_t value )
{
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudioRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables 2-byte endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudioRd2byteLittleEndian" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_277"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_277" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_277")))
#endif

void FREG_BM23_SetEndianSwapRd_AudioRd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxRd2byteLittleEndian" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_278"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_278" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_278")))
#endif

void FREG_BM23_SetEndianSwapRd_TtxRd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpdifRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpdifRd2byteLittleEndian" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_279"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_279" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_279")))
#endif

void FREG_BM23_SetEndianSwapRd_SpdifRd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s3Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s3Rd2byteLittleEndian" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_280"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_280" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_280")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s3Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s2Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s2Rd2byteLittleEndian" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_281"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_281" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_281")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s2Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s1Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s1Rd2byteLittleEndian" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_282"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_282" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_282")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s1Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s0Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s0Rd2byteLittleEndian" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_283"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_283" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_283")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s0Rd2byteLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AudioRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AudioRdLittleEndian" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_284"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_284" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_284")))
#endif

void FREG_BM23_SetEndianSwapRd_AudioRdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxRdLittleEndian" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_285"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_285" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_285")))
#endif

void FREG_BM23_SetEndianSwapRd_TtxRdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpdifRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpdifRdLittleEndian" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_286"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_286" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_286")))
#endif

void FREG_BM23_SetEndianSwapRd_SpdifRdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s3RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s3RdLittleEndian" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_287"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_287" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_287")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s3RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s2RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s2RdLittleEndian" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_288"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_288" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_288")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s2RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s1RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s1RdLittleEndian" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_289"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_289" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_289")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s1RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2s0RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2s0RdLittleEndian" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_290"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_290" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_290")))
#endif

void FREG_BM23_SetEndianSwapRd_I2s0RdLittleEndian( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_BM23_EndianSwapRdMirror & ~mask;
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "EndianSwapRd".
**
** This function reads the value from the register "EndianSwapRd".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_291"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_291" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_291")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AudioRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables 2-byte endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudioRd2byteLittleEndian" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_292"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_292" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_292")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_AudioRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "TtxRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxRd2byteLittleEndian" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_293"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_293" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_293")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_TtxRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "SpdifRd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpdifRd2byteLittleEndian" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_294"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_294" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_294")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_SpdifRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s3Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s3Rd2byteLittleEndian" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_295"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_295" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_295")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s3Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s2Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s2Rd2byteLittleEndian" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_296"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_296" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_296")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s2Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s1Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s1Rd2byteLittleEndian" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_297"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_297" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_297")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s1Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s0Rd2byteLittleEndian" of register "EndianSwapRd".
**
** Enables  2-byte endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1':  2-byte little endian mode.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s0Rd2byteLittleEndian" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_298"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_298" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_298")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s0Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "AudioRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (audio)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AudioRdLittleEndian" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_299"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_299" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_299")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_AudioRdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "TtxRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (TTX)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxRdLittleEndian" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_300"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_300" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_300")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_TtxRdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "SpdifRdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (SPDIF)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpdifRdLittleEndian" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_301"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_301" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_301")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_SpdifRdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s3RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_3)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s3RdLittleEndian" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_302"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_302" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_302")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s3RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s2RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_2)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s2RdLittleEndian" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_303"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_303" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_303")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s2RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s1RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_1)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s1RdLittleEndian" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_304"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_304" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_304")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s1RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the bitgroup "I2s0RdLittleEndian" of register "EndianSwapRd".
**
** Enables endian swap for the hardware controlled buffer (I2S_0)
** - '0': big endian (default).
**
** - '1': little endian.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2s0RdLittleEndian" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_305"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_305" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_305")))
#endif

uint32_t FREG_BM23_GetmEndianSwapRd_I2s0RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
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
** \brief Reads the entire register "StatusRdClr".
**
** This function reads the value from the register "StatusRdClr".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_306"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_306" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_306")))
#endif

uint32_t FREG_BM01_GetStatusRdClr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRDCLR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Extracts the bitgroup "LevelIrq" of register "StatusRdClr".
**
** Level IRQ status.
**
** - '0': wether high nor low level IRQ detected.
** - '1': either high or low level IRQ deteced.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "LevelIrq" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_307"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_307" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_307")))
#endif

uint32_t FREG_BM01_ExtractStatusRdClr_LevelIrq( uint32_t value )
{
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
** \brief Extracts the bitgroup "BufferLowIrqFlag" of register "StatusRdClr".
**
** Low level IRQ status.
**
** Bit 15:
** - '0': Low level IRQ in Hardware controlled buffer 7 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 7
** dectected.
** Bit 14:
** - '0': Low level IRQ in Hardware controlled buffer 6 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 6
** dectected.
** ... ...
** Bit 8:
** - '0': Low level IRQ in Hardware controlled buffer 0 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 0
** dectected.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferLowIrqFlag" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_308"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_308" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_308")))
#endif

uint32_t FREG_BM01_ExtractStatusRdClr_BufferLowIrqFlag( uint32_t value )
{
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
** \brief Extracts the bitgroup "BufferHighIrqFlag" of register "StatusRdClr".
**
** High level IRQ status.
**
** Bit 7:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is detected.
** Bit 6:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is detected.
** Bit 5, ..., bit 0 are defined similarly.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferHighIrqFlag" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_309"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_309" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_309")))
#endif

uint32_t FREG_BM01_ExtractStatusRdClr_BufferHighIrqFlag( uint32_t value )
{
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
** \brief Reads the entire register "StatusRdClr".
**
** This function reads the value from the register "StatusRdClr".
**
**
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_310"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_310" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_310")))
#endif

uint32_t FREG_BM23_GetStatusRdClr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRDCLR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Extracts the bitgroup "LevelIrq" of register "StatusRdClr".
**
** Level IRQ status.
**
** - '0': wether high nor low level IRQ detected.
** - '1': either high or low level IRQ deteced.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "LevelIrq" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_311"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_311" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_311")))
#endif

uint32_t FREG_BM23_ExtractStatusRdClr_LevelIrq( uint32_t value )
{
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
** \brief Extracts the bitgroup "BufferLowIrqFlag" of register "StatusRdClr".
**
** Low level IRQ status.
**
** Bit 15:
** - '0': Low level IRQ in Hardware controlled buffer 7 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 7
** dectected.
** Bit 14:
** - '0': Low level IRQ in Hardware controlled buffer 6 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 6
** dectected.
** ... ...
** Bit 8:
** - '0': Low level IRQ in Hardware controlled buffer 0 not
** dectected.
** - '1': Low level IRQ in Hardware controlled buffer 0
** dectected.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferLowIrqFlag" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_312"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_312" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_312")))
#endif

uint32_t FREG_BM23_ExtractStatusRdClr_BufferLowIrqFlag( uint32_t value )
{
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
** \brief Extracts the bitgroup "BufferHighIrqFlag" of register "StatusRdClr".
**
** High level IRQ status.
**
** Bit 7:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*7 is detected.
** Bit 6:
** - '0': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is not detected.
** - '1': High level IRQ defined in register
** BM01_BUF_HIGH_LEV+4*6 is detected.
** Bit 5, ..., bit 0 are defined similarly.
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BufferHighIrqFlag" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_BM_313"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_BM_313" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_BM_313")))
#endif

uint32_t FREG_BM23_ExtractStatusRdClr_BufferHighIrqFlag( uint32_t value )
{
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
** \brief Initializes the "BM" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_BM_Init( void )
{
    uint32_t index = 0;
    FREG_BM0_IrqMaskMirror |= ( ( 0xFFFFFFFF << 0 ) & 0xFFFFFFFFUL );
    FREG_BM01_ReadEnableMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_BM01_ReadEnableMirror |= ( ( 0 << 0 ) & 0x0000007FUL );
    FREG_BM0_EndianSwapWrMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
    FREG_BM1_IrqMaskMirror |= ( ( 0xFFFFFFFF << 0 ) & 0xFFFFFFFFUL );
    FREG_BM1_EndianSwapWrMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
    for( index=0; index < 5; index++ )
        FREG_BM01_AudValueMirror[index] |= ( ( 0 << 8 ) & 0x00000100UL );
    for( index=0; index < 5; index++ )
        FREG_BM01_AudValueMirror[index] |= ( ( 0 << 0 ) & 0x000000FFUL );
    FREG_BM01_AudCfgEnMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_BM01_AudCfgEnMirror |= ( ( 0 << 0 ) & 0x0000003FUL );
    FREG_BM01_ClearAudIrqMirror |= ( ( 0 << 4 ) & 0x00000010UL );
    FREG_BM01_ClearAudIrqMirror |= ( ( 0 << 3 ) & 0x00000008UL );
    FREG_BM01_ClearAudIrqMirror |= ( ( 0 << 2 ) & 0x00000004UL );
    FREG_BM01_ClearAudIrqMirror |= ( ( 0 << 1 ) & 0x00000002UL );
    FREG_BM01_ClearAudIrqMirror |= ( ( 0 << 0 ) & 0x00000001UL );
    FREG_BM2_IrqMaskMirror |= ( ( 0xFFFFFFFF << 0 ) & 0xFFFFFFFFUL );
    FREG_BM23_ReadEnableMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_BM23_ReadEnableMirror |= ( ( 0 << 0 ) & 0x0000007FUL );
    FREG_BM2_EndianSwapWrMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
    FREG_BM3_IrqMaskMirror |= ( ( 0xFFFFFFFF << 0 ) & 0xFFFFFFFFUL );
    FREG_BM3_EndianSwapWrMirror |= ( ( 0 << 0 ) & 0xFFFFFFFFUL );
    for( index=0; index < 5; index++ )
        FREG_BM23_AudValueMirror[index] |= ( ( 0 << 8 ) & 0x00000100UL );
    for( index=0; index < 5; index++ )
        FREG_BM23_AudValueMirror[index] |= ( ( 0 << 0 ) & 0x000000FFUL );
    FREG_BM23_AudCfgEnMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_BM23_AudCfgEnMirror |= ( ( 0 << 0 ) & 0x0000003FUL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 14 ) & 0x00004000UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 13 ) & 0x00002000UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 12 ) & 0x00001000UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 11 ) & 0x00000800UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 10 ) & 0x00000400UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 9 ) & 0x00000200UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 6 ) & 0x00000040UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 5 ) & 0x00000020UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 4 ) & 0x00000010UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 3 ) & 0x00000008UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 2 ) & 0x00000004UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 1 ) & 0x00000002UL );
    FREG_BM01_EndianSwapRdMirror |= ( ( 0 << 0 ) & 0x00000001UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 14 ) & 0x00004000UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 13 ) & 0x00002000UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 12 ) & 0x00001000UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 11 ) & 0x00000800UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 10 ) & 0x00000400UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 9 ) & 0x00000200UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 6 ) & 0x00000040UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 5 ) & 0x00000020UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 4 ) & 0x00000010UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 3 ) & 0x00000008UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 2 ) & 0x00000004UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 1 ) & 0x00000002UL );
    FREG_BM23_EndianSwapRdMirror |= ( ( 0 << 0 ) & 0x00000001UL );
}
