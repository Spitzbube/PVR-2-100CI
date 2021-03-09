/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_gpio.h
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
#if !defined(FREG_GPIO_H)
#define FREG_GPIO_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_GPIO_ENABLE_DEBUG_PRINT   0
#define FREG_GPIO_DEBUG_PRINT_FUNCTION printf

#if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_GPIO_DATAOUT                        FIO_ADDRESS(GPIO,0xC3000000UL)
#define FREG_GPIO_DATAIN                         FIO_ADDRESS(GPIO,0xC3000200UL)
#define FREG_GPIO_IRQCFG                         FIO_ADDRESS(GPIO,0xC30004C0UL)
#define FREG_GPIO_CONFIG                         FIO_ADDRESS(GPIO,0xC30004C4UL)
#define FREG_GPIO_IRQSTATUS                      FIO_ADDRESS(GPIO,0xC3000400UL)
#define FREG_GPIO_INPUT_31_0                     FIO_ADDRESS(GPIO,0xC3000404UL)
#define FREG_GPIO_INPUT_63_32                    FIO_ADDRESS(GPIO,0xC3000408UL)
#define FREG_GPIO_INPUT_95_64                    FIO_ADDRESS(GPIO,0xC300040CUL)
#define FREG_GPIO_PWMSETTING                     FIO_ADDRESS(GPIO,0xC30004ECUL)

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
extern volatile uint32_t FREG_GPIO_DataOutMirror[96];
extern volatile uint32_t FREG_GPIO_DataInMirror[67];
extern volatile uint32_t FREG_GPIO_IrqCfgMirror;
extern volatile uint32_t FREG_GPIO_ConfigMirror;
extern volatile uint32_t FREG_GPIO_PwmSettingMirror;

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
extern void FREG_GPIO_SetDataOut( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataOut( uint32_t index, uint32_t value )
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
extern void FREG_GPIO_SetDataOut_DataEnableInv( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataOut_DataEnableInv( uint32_t index, uint32_t value )
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
extern void FREG_GPIO_SetDataOut_DataOutInv( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataOut_DataOutInv( uint32_t index, uint32_t value )
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
extern void FREG_GPIO_SetDataOut_DataEnExchange( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataOut_DataEnExchange( uint32_t index, uint32_t value )
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
extern void FREG_GPIO_SetDataOut_DataEnSel( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataOut_DataEnSel( uint32_t index, uint32_t value )
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
extern void FREG_GPIO_SetDataOut_DataOutSel( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataOut_DataOutSel( uint32_t index, uint32_t value )
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
extern uint32_t FREG_GPIO_GetmDataOut( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataOut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 96 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataOutMirror[index];
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmDataOut_DataEnableInv( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataOut_DataEnableInv( uint32_t index )
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
extern uint32_t FREG_GPIO_GetmDataOut_DataOutInv( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataOut_DataOutInv( uint32_t index )
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
extern uint32_t FREG_GPIO_GetmDataOut_DataEnExchange( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataOut_DataEnExchange( uint32_t index )
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
extern uint32_t FREG_GPIO_GetmDataOut_DataEnSel( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataOut_DataEnSel( uint32_t index )
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
extern uint32_t FREG_GPIO_GetmDataOut_DataOutSel( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataOut_DataOutSel( uint32_t index )
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
extern void FREG_GPIO_SetDataIn( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataIn( uint32_t index, uint32_t value )
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
extern void FREG_GPIO_SetDataIn_DataInSel( uint32_t index, uint32_t value );
#else
INLINE void FREG_GPIO_SetDataIn_DataInSel( uint32_t index, uint32_t value )
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
extern uint32_t FREG_GPIO_GetmDataIn( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataIn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 67 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_GPIO_DataInMirror[index];
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmDataIn_DataInSel( uint32_t index );
#else
INLINE uint32_t FREG_GPIO_GetmDataIn_DataInSel( uint32_t index )
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
extern void FREG_GPIO_SetIrqCfg( uint32_t value );
#else
INLINE void FREG_GPIO_SetIrqCfg( uint32_t value )
{
    FREG_GPIO_IrqCfgMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_IRQCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_IRQCFG)) = value;
}
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
extern void FREG_GPIO_SetIrqCfg_IrqClear( uint32_t value );
#else
INLINE void FREG_GPIO_SetIrqCfg_IrqClear( uint32_t value )
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
extern void FREG_GPIO_SetIrqCfg_IrqMode( uint32_t value );
#else
INLINE void FREG_GPIO_SetIrqCfg_IrqMode( uint32_t value )
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
extern void FREG_GPIO_SetIrqCfg_IrqInput( uint32_t value );
#else
INLINE void FREG_GPIO_SetIrqCfg_IrqInput( uint32_t value )
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
extern uint32_t FREG_GPIO_GetmIrqCfg( void );
#else
INLINE uint32_t FREG_GPIO_GetmIrqCfg( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmIrqCfg_IrqClear( void );
#else
INLINE uint32_t FREG_GPIO_GetmIrqCfg_IrqClear( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmIrqCfg_IrqMode( void );
#else
INLINE uint32_t FREG_GPIO_GetmIrqCfg_IrqMode( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmIrqCfg_IrqInput( void );
#else
INLINE uint32_t FREG_GPIO_GetmIrqCfg_IrqInput( void )
{
    register uint32_t value = FREG_GPIO_IrqCfgMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
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
extern void FREG_GPIO_SetConfig( uint32_t value );
#else
INLINE void FREG_GPIO_SetConfig( uint32_t value )
{
    FREG_GPIO_ConfigMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_CONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_CONFIG)) = value;
}
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
extern void FREG_GPIO_SetConfig_LcdRgbEn( uint32_t value );
#else
INLINE void FREG_GPIO_SetConfig_LcdRgbEn( uint32_t value )
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
extern void FREG_GPIO_SetConfig_FlashAddrEn( uint32_t value );
#else
INLINE void FREG_GPIO_SetConfig_FlashAddrEn( uint32_t value )
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
extern uint32_t FREG_GPIO_GetmConfig( void );
#else
INLINE uint32_t FREG_GPIO_GetmConfig( void )
{
    register uint32_t value = FREG_GPIO_ConfigMirror;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmConfig_LcdRgbEn( void );
#else
INLINE uint32_t FREG_GPIO_GetmConfig_LcdRgbEn( void )
{
    register uint32_t value = FREG_GPIO_ConfigMirror;
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmConfig_FlashAddrEn( void );
#else
INLINE uint32_t FREG_GPIO_GetmConfig_FlashAddrEn( void )
{
    register uint32_t value = FREG_GPIO_ConfigMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetIrqStatus( void );
#else
INLINE uint32_t FREG_GPIO_GetIrqStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_IRQSTATUS));
    return( value );
}
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
extern uint32_t FREG_GPIO_GetIrqStatus_GpioIrq( void );
#else
INLINE uint32_t FREG_GPIO_GetIrqStatus_GpioIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_IRQSTATUS));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetInput_31_0( void );
#else
INLINE uint32_t FREG_GPIO_GetInput_31_0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_31_0));
    return( value );
}
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
extern uint32_t FREG_GPIO_GetInput_31_0_Input310( void );
#else
INLINE uint32_t FREG_GPIO_GetInput_31_0_Input310( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_31_0));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetInput_63_32( void );
#else
INLINE uint32_t FREG_GPIO_GetInput_63_32( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_63_32));
    return( value );
}
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
extern uint32_t FREG_GPIO_GetInput_63_32_Input6332( void );
#else
INLINE uint32_t FREG_GPIO_GetInput_63_32_Input6332( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_63_32));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetInput_95_64( void );
#else
INLINE uint32_t FREG_GPIO_GetInput_95_64( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_95_64));
    return( value );
}
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
extern uint32_t FREG_GPIO_GetInput_95_64_Input9564( void );
#else
INLINE uint32_t FREG_GPIO_GetInput_95_64_Input9564( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_GPIO_INPUT_95_64));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_GPIO_SetPwmSetting( uint32_t value );
#else
INLINE void FREG_GPIO_SetPwmSetting( uint32_t value )
{
    FREG_GPIO_PwmSettingMirror = value;
    #if FREG_GPIO_ENABLE_DEBUG_PRINT == 1
        FREG_GPIO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_GPIO", FREG_GPIO_PWMSETTING, value );
    #endif
    *((volatile uint32_t*)(FREG_GPIO_PWMSETTING)) = value;
}
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
extern void FREG_GPIO_SetPwmSetting_PwmSetting( uint32_t value );
#else
INLINE void FREG_GPIO_SetPwmSetting_PwmSetting( uint32_t value )
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
extern uint32_t FREG_GPIO_GetmPwmSetting( void );
#else
INLINE uint32_t FREG_GPIO_GetmPwmSetting( void )
{
    register uint32_t value = FREG_GPIO_PwmSettingMirror;
    return( value );
}
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
extern uint32_t FREG_GPIO_GetmPwmSetting_PwmSetting( void );
#else
INLINE uint32_t FREG_GPIO_GetmPwmSetting_PwmSetting( void )
{
    register uint32_t value = FREG_GPIO_PwmSettingMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
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
extern void FREG_GPIO_Init( void );

#endif
