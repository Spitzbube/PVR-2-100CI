/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_irq_ctrl.c
**
** \brief     IRQ_CTRL access functions
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
#define FREG_IRQ_CTRL_C

#include <stdint.h>
#include <fapi/reg_irq_ctrl.h>

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
** \brief Writes the entire register "TimerxEnable".
**
** This function writes the given value to the index-th entry of the register
** array TimerxEnable.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_1")))
#endif

void FREG_IRQ_CTRL_SetTimerxEnable( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Endless" of register "TimerxEnable".
**
** - '0': Timer ends after defined cycles
** - '1': Timer runs infinitely 
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Endless" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_2")))
#endif

void FREG_IRQ_CTRL_SetTimerxEnable_Endless( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqEnable" of register "TimerxEnable".
**
** - '0': IRQ generation off
** - '1': IRQ generation on
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqEnable" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_3")))
#endif

void FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enable" of register "TimerxEnable".
**
** - '0': Timer off
** - '1': Timer on
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_4")))
#endif

void FREG_IRQ_CTRL_SetTimerxEnable_Enable( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TimerxEnable".
**
** This function reads the value from the index-th entry of the register
** array TimerxEnable.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_5")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxEnable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Endless" of register "TimerxEnable".
**
** - '0': Timer ends after defined cycles
** - '1': Timer runs infinitely 
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Endless" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_6")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxEnable_Endless( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40)));
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
** \brief Reads the bitgroup "IrqEnable" of register "TimerxEnable".
**
** - '0': IRQ generation off
** - '1': IRQ generation on
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqEnable" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_7")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxEnable_IrqEnable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40)));
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
** \brief Reads the bitgroup "Enable" of register "TimerxEnable".
**
** - '0': Timer off
** - '1': Timer on
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_8")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxEnable_Enable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40)));
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
** \brief Writes the entire register "TimerxCntPre".
**
** This function writes the given value to the index-th entry of the register
** array TimerxCntPre.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_9")))
#endif

void FREG_IRQ_CTRL_SetTimerxCntPre( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PreCount" of register "TimerxCntPre".
**
** Pre counter value (runs from value to 0)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PreCount" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_10")))
#endif

void FREG_IRQ_CTRL_SetTimerxCntPre_PreCount( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TimerxCntPre".
**
** This function reads the value from the index-th entry of the register
** array TimerxCntPre.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_11")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxCntPre( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PreCount" of register "TimerxCntPre".
**
** Pre counter value (runs from value to 0)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "PreCount" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_12")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxCntPre_PreCount( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40)));
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
** \brief Writes the entire register "TimerxCntLow".
**
** This function writes the given value to the index-th entry of the register
** array TimerxCntLow.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_13")))
#endif

void FREG_IRQ_CTRL_SetTimerxCntLow( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "LowCount" of register "TimerxCntLow".
**
** Low counter value (runs from value to 0)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LowCount" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_14")))
#endif

void FREG_IRQ_CTRL_SetTimerxCntLow_LowCount( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TimerxCntLow".
**
** This function reads the value from the index-th entry of the register
** array TimerxCntLow.
**
** Low counter value (runs from value to 0)
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_15")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxCntLow( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LowCount" of register "TimerxCntLow".
**
** Low counter value (runs from value to 0)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "LowCount" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_16")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxCntLow_LowCount( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40)));
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
** \brief Writes the entire register "TimerxCntHigh".
**
** This function writes the given value to the index-th entry of the register
** array TimerxCntHigh.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_17")))
#endif

void FREG_IRQ_CTRL_SetTimerxCntHigh( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "HighCount" of register "TimerxCntHigh".
**
** High counter value (runs from value to 0)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "HighCount" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_18")))
#endif

void FREG_IRQ_CTRL_SetTimerxCntHigh_HighCount( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TimerxCntHigh".
**
** This function reads the value from the index-th entry of the register
** array TimerxCntHigh.
**
** High counter value (runs from value to 0)
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_19")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxCntHigh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "HighCount" of register "TimerxCntHigh".
**
** High counter value (runs from value to 0)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "HighCount" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_20")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxCntHigh_HighCount( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40)));
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
** \brief Writes the entire register "TimerxIrqReset".
**
** This function writes the given value to the index-th entry of the register
** array TimerxIrqReset.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_21")))
#endif

void FREG_IRQ_CTRL_SetTimerxIrqReset( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqReset" of register "TimerxIrqReset".
**
** - READ: actual IRQ status
** - WRITE: clear the IRQ (value independent)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqReset" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_22")))
#endif

void FREG_IRQ_CTRL_SetTimerxIrqReset_IrqReset( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TimerxIrqReset".
**
** This function reads the value from the index-th entry of the register
** array TimerxIrqReset.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_23")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqReset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqReset" of register "TimerxIrqReset".
**
** - READ: actual IRQ status
** - WRITE: clear the IRQ (value independent)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqReset" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_24")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqReset_IrqReset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40)));
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
** \brief Reads the entire register "TimerxIrqCntLow".
**
** This function reads the value from the index-th entry of the register
** array TimerxIrqCntLow.
**
** Captured low counter value by a mask interrupt
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_25")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntLow( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQCNTLOW+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqCntLow" of register "TimerxIrqCntLow".
**
** Captured low counter value by a mask interrupt
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqCntLow" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_26")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntLow_IrqCntLow( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQCNTLOW+(index*0x40)));
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
** \brief Reads the entire register "TimerxIrqCntHigh".
**
** This function reads the value from the index-th entry of the register
** array TimerxIrqCntHigh.
**
** Captured high counter value by a mask interrupt
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_27")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntHigh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQCNTHIGH+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqCntHigh" of register "TimerxIrqCntHigh".
**
** Captured high counter value by a mask interrupt
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqCntHigh" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_28")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntHigh_IrqCntHigh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQCNTHIGH+(index*0x40)));
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
** \brief Writes the entire register "TimerxIrqMask".
**
** This function writes the given value to the index-th entry of the register
** array TimerxIrqMask.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_29")))
#endif

void FREG_IRQ_CTRL_SetTimerxIrqMask( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IrqMask" of register "TimerxIrqMask".
**
** Mask for system IRQs to capture counter values
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_30")))
#endif

void FREG_IRQ_CTRL_SetTimerxIrqMask_IrqMask( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TimerxIrqMask".
**
** This function reads the value from the index-th entry of the register
** array TimerxIrqMask.
**
** Mask for system IRQs to capture counter values
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_31")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqMask( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IrqMask" of register "TimerxIrqMask".
**
** Mask for system IRQs to capture counter values
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "IrqMask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_32")))
#endif

uint32_t FREG_IRQ_CTRL_GetTimerxIrqMask_IrqMask( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40)));
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
** \brief Writes the entire register "Mutexx".
**
** This function writes the given value to the index-th entry of the register
** array Mutexx.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_33")))
#endif

void FREG_IRQ_CTRL_SetMutexx( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_MUTEXX+(index*0x04), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_MUTEXX+(index*0x04))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mutexx" of register "Mutexx".
**
** Mutex x (only used by  software)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mutexx" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_34")))
#endif

void FREG_IRQ_CTRL_SetMutexx_Mutexx( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_MUTEXX+(index*0x04))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_MUTEXX+(index*0x04), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_MUTEXX+(index*0x04))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Mutexx".
**
** This function reads the value from the index-th entry of the register
** array Mutexx.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_35")))
#endif

uint32_t FREG_IRQ_CTRL_GetMutexx( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_MUTEXX+(index*0x04)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mutexx" of register "Mutexx".
**
** Mutex x (only used by  software)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mutexx" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_36")))
#endif

uint32_t FREG_IRQ_CTRL_GetMutexx_Mutexx( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_MUTEXX+(index*0x04)));
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
** \brief Writes the entire register "Arcirqmask".
**
** This function writes the given value to the register "Arcirqmask".
**
** Mask for system IRQs
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_37")))
#endif

void FREG_IRQ_CTRL_SetArcirqmask( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCIRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Arcirqmask" of register "Arcirqmask".
**
** Mask for system IRQs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Arcirqmask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_38")))
#endif

void FREG_IRQ_CTRL_SetArcirqmask_Arcirqmask( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCIRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Arcirqmask".
**
** This function reads the value from the register "Arcirqmask".
**
** Mask for system IRQs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_39")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Arcirqmask" of register "Arcirqmask".
**
** Mask for system IRQs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Arcirqmask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_40")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcirqmask_Arcirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK));
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
** \brief Writes the entire register "Arcirqxor".
**
** This function writes the given value to the register "Arcirqxor".
**
** XOR for system IRQs
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_41")))
#endif

void FREG_IRQ_CTRL_SetArcirqxor( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCIRQXOR, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Arcirqxor" of register "Arcirqxor".
**
** XOR for system IRQs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Arcirqxor" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_42")))
#endif

void FREG_IRQ_CTRL_SetArcirqxor_Arcirqxor( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCIRQXOR, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Arcirqxor".
**
** This function reads the value from the register "Arcirqxor".
**
** XOR for system IRQs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_43")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Arcirqxor" of register "Arcirqxor".
**
** XOR for system IRQs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Arcirqxor" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_44")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcirqxor_Arcirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR));
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
** \brief Reads the entire register "Arcirqstatus".
**
** This function reads the value from the register "Arcirqstatus".
**
** Status for system IRQs (CPU side)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_45")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQSTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Arcirqstatus" of register "Arcirqstatus".
**
** Status for system IRQs (CPU side)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Arcirqstatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_46")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcirqstatus_Arcirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQSTATUS));
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
** \brief Writes the entire register "Arcstatus".
**
** This function writes the given value to the register "Arcstatus".
**
** status register (only used by  software)
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_47")))
#endif

void FREG_IRQ_CTRL_SetArcstatus( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Arcstatus" of register "Arcstatus".
**
** status register (only used by  software)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Arcstatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_48")))
#endif

void FREG_IRQ_CTRL_SetArcstatus_Arcstatus( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Arcstatus".
**
** This function reads the value from the register "Arcstatus".
**
** status register (only used by  software)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_49")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Arcstatus" of register "Arcstatus".
**
** status register (only used by  software)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Arcstatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_50")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcstatus_Arcstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS));
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
** \brief Writes the entire register "Arcjmpaddress".
**
** This function writes the given value to the register "Arcjmpaddress".
**
** jump register (only used by  software)
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_51")))
#endif

void FREG_IRQ_CTRL_SetArcjmpaddress( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCJMPADDRESS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Arcjmpaddress" of register "Arcjmpaddress".
**
** jump register (only used by  software)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Arcjmpaddress" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_52")))
#endif

void FREG_IRQ_CTRL_SetArcjmpaddress_Arcjmpaddress( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCJMPADDRESS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Arcjmpaddress".
**
** This function reads the value from the register "Arcjmpaddress".
**
** jump register (only used by  software)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_53")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Arcjmpaddress" of register "Arcjmpaddress".
**
** jump register (only used by  software)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Arcjmpaddress" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_54")))
#endif

uint32_t FREG_IRQ_CTRL_GetArcjmpaddress_Arcjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS));
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
** \brief Writes the entire register "Armirqmask".
**
** This function writes the given value to the register "Armirqmask".
**
** Mask for system IRQs
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_55")))
#endif

void FREG_IRQ_CTRL_SetArmirqmask( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMIRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Armirqmask" of register "Armirqmask".
**
** Mask for system IRQs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Armirqmask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_56")))
#endif

void FREG_IRQ_CTRL_SetArmirqmask_Armirqmask( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMIRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Armirqmask".
**
** This function reads the value from the register "Armirqmask".
**
** Mask for system IRQs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_57")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Armirqmask" of register "Armirqmask".
**
** Mask for system IRQs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Armirqmask" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_58")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmirqmask_Armirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK));
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
** \brief Writes the entire register "Armirqxor".
**
** This function writes the given value to the register "Armirqxor".
**
** XOR for system IRQs
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_59")))
#endif

void FREG_IRQ_CTRL_SetArmirqxor( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMIRQXOR, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Armirqxor" of register "Armirqxor".
**
** XOR for system IRQs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Armirqxor" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_60")))
#endif

void FREG_IRQ_CTRL_SetArmirqxor_Armirqxor( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMIRQXOR, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Armirqxor".
**
** This function reads the value from the register "Armirqxor".
**
** XOR for system IRQs
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_61")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Armirqxor" of register "Armirqxor".
**
** XOR for system IRQs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Armirqxor" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_62")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmirqxor_Armirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR));
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
** \brief Reads the entire register "Armirqstatus".
**
** This function reads the value from the register "Armirqstatus".
**
** Status for system IRQs (CPU side)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_63")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQSTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Armirqstatus" of register "Armirqstatus".
**
** Status for system IRQs (CPU side)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Armirqstatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_64")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmirqstatus_Armirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQSTATUS));
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
** \brief Writes the entire register "Armstatus".
**
** This function writes the given value to the register "Armstatus".
**
** status register (only used by  software)
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_65")))
#endif

void FREG_IRQ_CTRL_SetArmstatus( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Armstatus" of register "Armstatus".
**
** status register (only used by  software)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Armstatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_66")))
#endif

void FREG_IRQ_CTRL_SetArmstatus_Armstatus( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Armstatus".
**
** This function reads the value from the register "Armstatus".
**
** status register (only used by  software)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_67")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Armstatus" of register "Armstatus".
**
** status register (only used by  software)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Armstatus" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_68")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmstatus_Armstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS));
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
** \brief Writes the entire register "Armjmpaddress".
**
** This function writes the given value to the register "Armjmpaddress".
**
** jump register (only used by  software)
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_69")))
#endif

void FREG_IRQ_CTRL_SetArmjmpaddress( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMJMPADDRESS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Armjmpaddress" of register "Armjmpaddress".
**
** jump register (only used by  software)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Armjmpaddress" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_70")))
#endif

void FREG_IRQ_CTRL_SetArmjmpaddress_Armjmpaddress( uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMJMPADDRESS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Armjmpaddress".
**
** This function reads the value from the register "Armjmpaddress".
**
** jump register (only used by  software)
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_71")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Armjmpaddress" of register "Armjmpaddress".
**
** jump register (only used by  software)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Armjmpaddress" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_72")))
#endif

uint32_t FREG_IRQ_CTRL_GetArmjmpaddress_Armjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS));
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
** \brief Writes the entire register "Gpx".
**
** This function writes the given value to the index-th entry of the register
** array Gpx.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_73")))
#endif

void FREG_IRQ_CTRL_SetGpx( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_GPX+(index*0x04), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_GPX+(index*0x04))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Gpx" of register "Gpx".
**
** 32 bit general purpose register (only used by software)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Gpx" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_74")))
#endif

void FREG_IRQ_CTRL_SetGpx_Gpx( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_IRQ_CTRL_GPX+(index*0x04))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_GPX+(index*0x04), value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_GPX+(index*0x04))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Gpx".
**
** This function reads the value from the index-th entry of the register
** array Gpx.
**
** 32 bit general purpose register (only used by software)
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_75")))
#endif

uint32_t FREG_IRQ_CTRL_GetGpx( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_GPX+(index*0x04)));
    return( value );
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Gpx" of register "Gpx".
**
** 32 bit general purpose register (only used by software)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Gpx" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_IRQ_CTRL_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_IRQ_CTRL_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_IRQ_CTRL_76")))
#endif

uint32_t FREG_IRQ_CTRL_GetGpx_Gpx( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_GPX+(index*0x04)));
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

/*!
********************************************************************************
**
** \brief Initializes the "IRQ_CTRL" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_IRQ_CTRL_Init( void )
{
}
