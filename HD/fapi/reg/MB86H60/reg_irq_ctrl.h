/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_irq_ctrl.h
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
#if !defined(FREG_IRQ_CTRL_H)
#define FREG_IRQ_CTRL_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT   0
#define FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION printf

#if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_IRQ_CTRL_TIMERXENABLE               FIO_ADDRESS(IRQ_CTRL,0xCF000000UL)
#define FREG_IRQ_CTRL_TIMERXCNTPRE               FIO_ADDRESS(IRQ_CTRL,0xCF000004UL)
#define FREG_IRQ_CTRL_TIMERXCNTLOW               FIO_ADDRESS(IRQ_CTRL,0xCF000008UL)
#define FREG_IRQ_CTRL_TIMERXCNTHIGH              FIO_ADDRESS(IRQ_CTRL,0xCF00000CUL)
#define FREG_IRQ_CTRL_TIMERXIRQRESET             FIO_ADDRESS(IRQ_CTRL,0xCF000018UL)
#define FREG_IRQ_CTRL_TIMERXIRQCNTLOW            FIO_ADDRESS(IRQ_CTRL,0xCF00001CUL)
#define FREG_IRQ_CTRL_TIMERXIRQCNTHIGH           FIO_ADDRESS(IRQ_CTRL,0xCF000020UL)
#define FREG_IRQ_CTRL_TIMERXIRQMASK              FIO_ADDRESS(IRQ_CTRL,0xCF000024UL)
#define FREG_IRQ_CTRL_MUTEXX                     FIO_ADDRESS(IRQ_CTRL,0xCF000100UL)
#define FREG_IRQ_CTRL_ARCIRQMASK                 FIO_ADDRESS(IRQ_CTRL,0xCF000200UL)
#define FREG_IRQ_CTRL_ARCIRQXOR                  FIO_ADDRESS(IRQ_CTRL,0xCF000204UL)
#define FREG_IRQ_CTRL_ARCIRQSTATUS               FIO_ADDRESS(IRQ_CTRL,0xCF000208UL)
#define FREG_IRQ_CTRL_ARCSTATUS                  FIO_ADDRESS(IRQ_CTRL,0xCF000210UL)
#define FREG_IRQ_CTRL_ARCJMPADDRESS              FIO_ADDRESS(IRQ_CTRL,0xCF000214UL)
#define FREG_IRQ_CTRL_ARMIRQMASK                 FIO_ADDRESS(IRQ_CTRL,0xCF000300UL)
#define FREG_IRQ_CTRL_ARMIRQXOR                  FIO_ADDRESS(IRQ_CTRL,0xCF000304UL)
#define FREG_IRQ_CTRL_ARMIRQSTATUS               FIO_ADDRESS(IRQ_CTRL,0xCF000308UL)
#define FREG_IRQ_CTRL_ARMSTATUS                  FIO_ADDRESS(IRQ_CTRL,0xCF000310UL)
#define FREG_IRQ_CTRL_ARMJMPADDRESS              FIO_ADDRESS(IRQ_CTRL,0xCF000314UL)
#define FREG_IRQ_CTRL_GPX                        FIO_ADDRESS(IRQ_CTRL,0xCF000380UL)

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
extern void FREG_IRQ_CTRL_SetTimerxEnable( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxEnable( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxEnable_Endless( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxEnable_Endless( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxEnable_IrqEnable( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxEnable_Enable( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxEnable_Enable( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxEnable( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxEnable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXENABLE+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxEnable_Endless( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxEnable_Endless( uint32_t index )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxEnable_IrqEnable( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxEnable_IrqEnable( uint32_t index )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxEnable_Enable( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxEnable_Enable( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetTimerxCntPre( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxCntPre( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxCntPre_PreCount( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxCntPre_PreCount( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxCntPre( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxCntPre( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTPRE+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxCntPre_PreCount( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxCntPre_PreCount( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetTimerxCntLow( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxCntLow( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxCntLow_LowCount( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxCntLow_LowCount( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxCntLow( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxCntLow( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTLOW+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxCntLow_LowCount( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxCntLow_LowCount( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetTimerxCntHigh( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxCntHigh( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxCntHigh_HighCount( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxCntHigh_HighCount( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxCntHigh( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxCntHigh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXCNTHIGH+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxCntHigh_HighCount( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxCntHigh_HighCount( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetTimerxIrqReset( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxIrqReset( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxIrqReset_IrqReset( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxIrqReset_IrqReset( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqReset( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqReset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQRESET+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqReset_IrqReset( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqReset_IrqReset( uint32_t index )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntLow( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntLow( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQCNTLOW+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntLow_IrqCntLow( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntLow_IrqCntLow( uint32_t index )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntHigh( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntHigh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQCNTHIGH+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntHigh_IrqCntHigh( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqCntHigh_IrqCntHigh( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetTimerxIrqMask( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxIrqMask( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetTimerxIrqMask_IrqMask( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetTimerxIrqMask_IrqMask( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqMask( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqMask( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_TIMERXIRQMASK+(index*0x40)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetTimerxIrqMask_IrqMask( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetTimerxIrqMask_IrqMask( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetMutexx( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetMutexx( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetMutexx_Mutexx( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetMutexx_Mutexx( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetMutexx( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetMutexx( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_MUTEXX+(index*0x04)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetMutexx_Mutexx( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetMutexx_Mutexx( uint32_t index )
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
extern void FREG_IRQ_CTRL_SetArcirqmask( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcirqmask( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCIRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArcirqmask_Arcirqmask( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcirqmask_Arcirqmask( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArcirqmask( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArcirqmask_Arcirqmask( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcirqmask_Arcirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQMASK));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArcirqxor( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcirqxor( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCIRQXOR, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArcirqxor_Arcirqxor( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcirqxor_Arcirqxor( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArcirqxor( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArcirqxor_Arcirqxor( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcirqxor_Arcirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQXOR));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArcirqstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQSTATUS));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArcirqstatus_Arcirqstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcirqstatus_Arcirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCIRQSTATUS));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArcstatus( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcstatus( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArcstatus_Arcstatus( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcstatus_Arcstatus( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArcstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArcstatus_Arcstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcstatus_Arcstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCSTATUS));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArcjmpaddress( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcjmpaddress( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARCJMPADDRESS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArcjmpaddress_Arcjmpaddress( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArcjmpaddress_Arcjmpaddress( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArcjmpaddress( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArcjmpaddress_Arcjmpaddress( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArcjmpaddress_Arcjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARCJMPADDRESS));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArmirqmask( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmirqmask( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMIRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArmirqmask_Armirqmask( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmirqmask_Armirqmask( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArmirqmask( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArmirqmask_Armirqmask( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmirqmask_Armirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQMASK));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArmirqxor( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmirqxor( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMIRQXOR, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArmirqxor_Armirqxor( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmirqxor_Armirqxor( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArmirqxor( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArmirqxor_Armirqxor( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmirqxor_Armirqxor( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQXOR));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArmirqstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQSTATUS));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArmirqstatus_Armirqstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmirqstatus_Armirqstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMIRQSTATUS));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArmstatus( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmstatus( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMSTATUS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArmstatus_Armstatus( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmstatus_Armstatus( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArmstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArmstatus_Armstatus( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmstatus_Armstatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMSTATUS));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetArmjmpaddress( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmjmpaddress( uint32_t value )
{
    #if FREG_IRQ_CTRL_ENABLE_DEBUG_PRINT == 1
        FREG_IRQ_CTRL_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_IRQ_CTRL", FREG_IRQ_CTRL_ARMJMPADDRESS, value );
    #endif
    *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS)) = value;
}
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
extern void FREG_IRQ_CTRL_SetArmjmpaddress_Armjmpaddress( uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetArmjmpaddress_Armjmpaddress( uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetArmjmpaddress( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetArmjmpaddress_Armjmpaddress( void );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetArmjmpaddress_Armjmpaddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_ARMJMPADDRESS));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_IRQ_CTRL_SetGpx( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetGpx( uint32_t index, uint32_t value )
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
extern void FREG_IRQ_CTRL_SetGpx_Gpx( uint32_t index, uint32_t value );
#else
INLINE void FREG_IRQ_CTRL_SetGpx_Gpx( uint32_t index, uint32_t value )
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
extern uint32_t FREG_IRQ_CTRL_GetGpx( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetGpx( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_IRQ_CTRL_GPX+(index*0x04)));
    return( value );
}
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
extern uint32_t FREG_IRQ_CTRL_GetGpx_Gpx( uint32_t index );
#else
INLINE uint32_t FREG_IRQ_CTRL_GetGpx_Gpx( uint32_t index )
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
extern void FREG_IRQ_CTRL_Init( void );

#endif
