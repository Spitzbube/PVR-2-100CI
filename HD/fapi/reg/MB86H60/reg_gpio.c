/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_gpio.c
**
** \brief     GPIO access functions
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
#define FREG_GPIO_C

#include <stdint.h>
#include "reg_gpio.h"

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
volatile uint32_t FREG_GPIO_DataOutMirror[96] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
volatile uint32_t FREG_GPIO_DataInMirror[67] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0
};
volatile uint32_t FREG_GPIO_IrqCfgMirror = 0;
volatile uint32_t FREG_GPIO_ConfigMirror = 0;
volatile uint32_t FREG_GPIO_PwmSettingMirror = 0;

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "DataOut".
**
** This function writes the given value to the index-th entry of the register
** array DataOut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_1")))
#endif

void FREG_GPIO_SetDataOut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return;
    #endif
    FREG_GPIO_DataOutMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAOUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAOUT+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataEnableInv" of register "DataOut".
**
** - '0': normal mode
** - '1': invert mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataEnableInv" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_2")))
#endif

void FREG_GPIO_SetDataOut_DataEnableInv( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00040000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return;
    #endif
    value = ( value << 18 ) & mask;
    value |= FREG_GPIO_DataOutMirror[index] & ~mask;
    FREG_GPIO_DataOutMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAOUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAOUT+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataOutInv" of register "DataOut".
**
** - '0': normal mode
** - '1': invert mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataOutInv" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_3")))
#endif

void FREG_GPIO_SetDataOut_DataOutInv( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00020000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return;
    #endif
    value = ( value << 17 ) & mask;
    value |= FREG_GPIO_DataOutMirror[index] & ~mask;
    FREG_GPIO_DataOutMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAOUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAOUT+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataEnExchange" of register "DataOut".
**
** exchanges the data and the enable pin of the GPIO
** - '0': normal mode
** - '1': exchange mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataEnExchange" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_4")))
#endif

void FREG_GPIO_SetDataOut_DataEnExchange( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_GPIO_DataOutMirror[index] & ~mask;
    FREG_GPIO_DataOutMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAOUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAOUT+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataEnSel" of register "DataOut".
**
** selects one of the functional enable to be feed to the GPIO
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataEnSel" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_5")))
#endif

void FREG_GPIO_SetDataOut_DataEnSel( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000F00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_GPIO_DataOutMirror[index] & ~mask;
    FREG_GPIO_DataOutMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAOUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAOUT+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataOutSel" of register "DataOut".
**
** selects one of the functional output to be feed to the GPIO
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataOutSel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_6")))
#endif

void FREG_GPIO_SetDataOut_DataOutSel( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_GPIO_DataOutMirror[index] & ~mask;
    FREG_GPIO_DataOutMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAOUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAOUT+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "DataOut".
**
** This function reads the value from the index-th entry of the register
** array DataOut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_7")))
#endif

uint32_t FREG_GPIO_GetmDataOut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DataEnableInv" of register "DataOut".
**
** - '0': normal mode
** - '1': invert mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataEnableInv" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_8")))
#endif

uint32_t FREG_GPIO_GetmDataOut_DataEnableInv( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 96 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
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
** \brief Reads the bitgroup "DataOutInv" of register "DataOut".
**
** - '0': normal mode
** - '1': invert mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataOutInv" consists of the bits 17..17,
**       the given bitgroup value will be shifted left by 17 bits and
**       masked using the bitmask 0x00020000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_9")))
#endif

uint32_t FREG_GPIO_GetmDataOut_DataOutInv( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 96 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
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
** \brief Reads the bitgroup "DataEnExchange" of register "DataOut".
**
** exchanges the data and the enable pin of the GPIO
** - '0': normal mode
** - '1': exchange mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataEnExchange" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_10")))
#endif

uint32_t FREG_GPIO_GetmDataOut_DataEnExchange( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 96 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
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
** \brief Reads the bitgroup "DataEnSel" of register "DataOut".
**
** selects one of the functional enable to be feed to the GPIO
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataEnSel" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_11")))
#endif

uint32_t FREG_GPIO_GetmDataOut_DataEnSel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 96 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
    value = ( value & 0x00000F00UL ) >> 8;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DataOutSel" of register "DataOut".
**
** selects one of the functional output to be feed to the GPIO
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataOutSel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_12")))
#endif

uint32_t FREG_GPIO_GetmDataOut_DataOutSel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 96 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
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
** \brief Writes the entire register "DataIn".
**
** This function writes the given value to the index-th entry of the register
** array DataIn.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_13")))
#endif

void FREG_GPIO_SetDataIn( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 67 )
            return;
    #endif
    FREG_GPIO_DataInMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAIN+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAIN+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataInSel" of register "DataIn".
**
** selects one of the GPIO?s input to be feed to the corresponding functional input
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataInSel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_14")))
#endif

void FREG_GPIO_SetDataIn_DataInSel( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 67 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_GPIO_DataInMirror[index] & ~mask;
    FREG_GPIO_DataInMirror[index] = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_DATAIN+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_DATAIN+(index*0x4))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "DataIn".
**
** This function reads the value from the index-th entry of the register
** array DataIn.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_15")))
#endif

uint32_t FREG_GPIO_GetmDataIn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 67 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataInMirror[index];
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DataInSel" of register "DataIn".
**
** selects one of the GPIO?s input to be feed to the corresponding functional input
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataInSel" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_16")))
#endif

uint32_t FREG_GPIO_GetmDataIn_DataInSel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 67 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataInMirror[index];
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
** \brief Writes the entire register "IrqCfg".
**
** This function writes the given value to the register "IrqCfg".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_17")))
#endif

void FREG_GPIO_SetIrqCfg( uint32_t value )
{
    FREG_GPIO_IrqCfgMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_IRQCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_IRQCFG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqClear" of register "IrqCfg".
**
** IRQ clear
** - '0' = IRQ active
** - '1' = IRQ cleared
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqClear" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_18")))
#endif

void FREG_GPIO_SetIrqCfg_IrqClear( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_GPIO_IrqCfgMirror & ~mask;
    FREG_GPIO_IrqCfgMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_IRQCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_IRQCFG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqMode" of register "IrqCfg".
**
** IRQ mode
** - '0' = rising edge
** - '1' = falling edge
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqMode" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_19")))
#endif

void FREG_GPIO_SetIrqCfg_IrqMode( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_GPIO_IrqCfgMirror & ~mask;
    FREG_GPIO_IrqCfgMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_IRQCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_IRQCFG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqInput" of register "IrqCfg".
**
** selects one of the GPIO?s input to be feed to the IRQ logic
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqInput" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_20")))
#endif

void FREG_GPIO_SetIrqCfg_IrqInput( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_GPIO_IrqCfgMirror & ~mask;
    FREG_GPIO_IrqCfgMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_IRQCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_IRQCFG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "IrqCfg".
**
** This function reads the value from the register "IrqCfg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_21")))
#endif

uint32_t FREG_GPIO_GetmIrqCfg( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqClear" of register "IrqCfg".
**
** IRQ clear
** - '0' = IRQ active
** - '1' = IRQ cleared
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqClear" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_22")))
#endif

uint32_t FREG_GPIO_GetmIrqCfg_IrqClear( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
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
** \brief Reads the bitgroup "IrqMode" of register "IrqCfg".
**
** IRQ mode
** - '0' = rising edge
** - '1' = falling edge
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqMode" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_23")))
#endif

uint32_t FREG_GPIO_GetmIrqCfg_IrqMode( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
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
** \brief Reads the bitgroup "IrqInput" of register "IrqCfg".
**
** selects one of the GPIO?s input to be feed to the IRQ logic
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqInput" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_24")))
#endif

uint32_t FREG_GPIO_GetmIrqCfg_IrqInput( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
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
** \brief Writes the entire register "Config".
**
** This function writes the given value to the register "Config".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_25")))
#endif

void FREG_GPIO_SetConfig( uint32_t value )
{
    FREG_GPIO_ConfigMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_CONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_CONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "LcdRgbEn" of register "Config".
**
** - '0' = GPIO 95.
** .72 can be mapped to any function
** - '1' = GPIO 95..72 used for digital 24bit RGB output
** (R: GPIO 79..72 ; G: GPIO 87..80 ; B: GPIO 95..88)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LcdRgbEn" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_26")))
#endif

void FREG_GPIO_SetConfig_LcdRgbEn( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    value |= FREG_GPIO_ConfigMirror & ~mask;
    FREG_GPIO_ConfigMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_CONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_CONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "FlashAddrEn" of register "Config".
**
** GPIO Pin 40:
** - '0' = GPIO 63.
** .48 can be mapped to any function
** - '1' = GPIO 63..48 used for FLASH address (UPI)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "FlashAddrEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_27")))
#endif

void FREG_GPIO_SetConfig_FlashAddrEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_GPIO_ConfigMirror & ~mask;
    FREG_GPIO_ConfigMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_CONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_CONFIG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Config".
**
** This function reads the value from the register "Config".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_28")))
#endif

uint32_t FREG_GPIO_GetmConfig( void )
{
    register uint32_t value = FREG_GPIO_ConfigMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LcdRgbEn" of register "Config".
**
** - '0' = GPIO 95.
** .72 can be mapped to any function
** - '1' = GPIO 95..72 used for digital 24bit RGB output
** (R: GPIO 79..72 ; G: GPIO 87..80 ; B: GPIO 95..88)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LcdRgbEn" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_29")))
#endif

uint32_t FREG_GPIO_GetmConfig_LcdRgbEn( void )
{
    register uint32_t value = FREG_GPIO_ConfigMirror;
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
** \brief Reads the bitgroup "FlashAddrEn" of register "Config".
**
** GPIO Pin 40:
** - '0' = GPIO 63.
** .48 can be mapped to any function
** - '1' = GPIO 63..48 used for FLASH address (UPI)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "FlashAddrEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_30")))
#endif

uint32_t FREG_GPIO_GetmConfig_FlashAddrEn( void )
{
    register uint32_t value = FREG_GPIO_ConfigMirror;
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
#pragma arm section code = ".text$$FREG_GPIO_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_31")))
#endif

uint32_t FREG_GPIO_GetIrqStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_IRQSTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "GpioIrq" of register "IrqStatus".
**
** IRQ_line of GPIO IRQ controller
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "GpioIrq" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_32")))
#endif

uint32_t FREG_GPIO_GetIrqStatus_GpioIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_IRQSTATUS));
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
** \brief Reads the entire register "Input_31_0".
**
** This function reads the value from the register "Input_31_0".
**
** Lower 32 GPIO inputs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_33")))
#endif

uint32_t FREG_GPIO_GetInput_31_0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_31_0));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Input310" of register "Input_31_0".
**
** Lower 32 GPIO inputs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Input310" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_34")))
#endif

uint32_t FREG_GPIO_GetInput_31_0_Input310( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_31_0));
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
** \brief Reads the entire register "Input_63_32".
**
** This function reads the value from the register "Input_63_32".
**
** Middle 32 GPIO inputs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_35")))
#endif

uint32_t FREG_GPIO_GetInput_63_32( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_63_32));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Input6332" of register "Input_63_32".
**
** Middle 32 GPIO inputs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Input6332" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_36")))
#endif

uint32_t FREG_GPIO_GetInput_63_32_Input6332( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_63_32));
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
** \brief Reads the entire register "Input_95_64".
**
** This function reads the value from the register "Input_95_64".
**
** Upper 32 GPIO inputs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_37")))
#endif

uint32_t FREG_GPIO_GetInput_95_64( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_95_64));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Input9564" of register "Input_95_64".
**
** Upper 32 GPIO inputs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Input9564" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_38")))
#endif

uint32_t FREG_GPIO_GetInput_95_64_Input9564( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_95_64));
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
** \brief Writes the entire register "PwmSetting".
**
** This function writes the given value to the register "PwmSetting".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_39")))
#endif

void FREG_GPIO_SetPwmSetting( uint32_t value )
{
    FREG_GPIO_PwmSettingMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_PWMSETTING, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_PWMSETTING)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PwmSetting" of register "PwmSetting".
**
** Modulation factor for PWM:
** Up-counter value is being compared to this value.
** 
** counter value <   PWM_SETTING: PWM_output is '0',
** counter value >= PWM_SETTING: PWM_output is '1'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PwmSetting" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_40")))
#endif

void FREG_GPIO_SetPwmSetting_PwmSetting( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_GPIO_PwmSettingMirror & ~mask;
    FREG_GPIO_PwmSettingMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_PWMSETTING, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_PWMSETTING)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "PwmSetting".
**
** This function reads the value from the register "PwmSetting".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_41")))
#endif

uint32_t FREG_GPIO_GetmPwmSetting( void )
{
    register uint32_t value = FREG_GPIO_PwmSettingMirror;
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PwmSetting" of register "PwmSetting".
**
** Modulation factor for PWM:
** Up-counter value is being compared to this value.
** 
** counter value <   PWM_SETTING: PWM_output is '0',
** counter value >= PWM_SETTING: PWM_output is '1'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PwmSetting" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_GPIO_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_GPIO_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_GPIO_42")))
#endif

uint32_t FREG_GPIO_GetmPwmSetting_PwmSetting( void )
{
    register uint32_t value = FREG_GPIO_PwmSettingMirror;
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

/*!
********************************************************************************
**
** \brief Initializes the "GPIO" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_GPIO_Init( void )
{
    uint32_t index = 0;
    for( index=0; index < 96; index++ )
        FREG_GPIO_DataOutMirror[index] |= ( ( 0 << 18 ) & 0x00040000UL );
    for( index=0; index < 96; index++ )
        FREG_GPIO_DataOutMirror[index] |= ( ( 0 << 17 ) & 0x00020000UL );
    for( index=0; index < 96; index++ )
        FREG_GPIO_DataOutMirror[index] |= ( ( 0 << 16 ) & 0x00010000UL );
    for( index=0; index < 96; index++ )
        FREG_GPIO_DataOutMirror[index] |= ( ( 1 << 8 ) & 0x00000F00UL );
    for( index=0; index < 96; index++ )
        FREG_GPIO_DataOutMirror[index] |= ( ( 0 << 0 ) & 0x0000007FUL );
    for( index=0; index < 67; index++ )
        FREG_GPIO_DataInMirror[index] |= ( ( 0 << 0 ) & 0x0000007FUL );
    FREG_GPIO_IrqCfgMirror |= ( ( 1 << 9 ) & 0x00000200UL );
    FREG_GPIO_IrqCfgMirror |= ( ( 0 << 8 ) & 0x00000100UL );
    FREG_GPIO_IrqCfgMirror |= ( ( 0 << 0 ) & 0x0000007FUL );
    FREG_GPIO_ConfigMirror |= ( ( 0 << 3 ) & 0x00000008UL );
    FREG_GPIO_ConfigMirror |= ( ( 0 << 0 ) & 0x00000001UL );
}
