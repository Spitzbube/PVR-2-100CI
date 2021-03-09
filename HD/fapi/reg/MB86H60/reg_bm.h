/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_bm.h
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
#if !defined(FREG_BM_H)
#define FREG_BM_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_BM_ENABLE_DEBUG_PRINT   0
#define FREG_BM_DEBUG_PRINT_FUNCTION printf

#if FREG_BM_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_BM0_BUFSIZE                         FIO_ADDRESS(BM0,0xC8300000UL)
#define FREG_BM0_WRPTR                           FIO_ADDRESS(BM0,0xC8300080UL)
#define FREG_BM0_BASEADDR                        FIO_ADDRESS(BM0,0xC8300100UL)
#define FREG_BM0_RDPTR                           FIO_ADDRESS(BM0,0xC8300180UL)
#define FREG_BM0_IRQMASK                         FIO_ADDRESS(BM0,0xC8300200UL)
#define FREG_BM0_IRQREG                          FIO_ADDRESS(BM0,0xC8300204UL)
#define FREG_BM01_READENABLE                     FIO_ADDRESS(BM01,0xC8300208UL)
#define FREG_BM01_GLOBALOFFSET                   FIO_ADDRESS(BM01,0xC8300210UL)
#define FREG_BM0_ENDIANSWAPWR                    FIO_ADDRESS(BM0,0xC8300218UL)
#define FREG_BM01_BUFLOWLEV                      FIO_ADDRESS(BM01,0xC8300220UL)
#define FREG_BM01_BUFHIGHLEV                     FIO_ADDRESS(BM01,0xC8300240UL)
#define FREG_BM01_STATUSRD                       FIO_ADDRESS(BM01,0xC8300260UL)
#define FREG_BM01_BUFHIGHLEVIRQCLR               FIO_ADDRESS(BM01,0xC8300280UL)
#define FREG_BM01_BUFLOWLEVIRQCLR                FIO_ADDRESS(BM01,0xC83002C0UL)
#define FREG_BM01_BUFSTREAMIRQCLR                FIO_ADDRESS(BM01,0xC8300300UL)
#define FREG_BM1_BUFSIZE                         FIO_ADDRESS(BM1,0xC8300400UL)
#define FREG_BM1_WRPTR                           FIO_ADDRESS(BM1,0xC8300480UL)
#define FREG_BM1_BASEADDR                        FIO_ADDRESS(BM1,0xC8300500UL)
#define FREG_BM1_RDPTR                           FIO_ADDRESS(BM1,0xC8300580UL)
#define FREG_BM1_IRQMASK                         FIO_ADDRESS(BM1,0xC8300600UL)
#define FREG_BM1_IRQREG                          FIO_ADDRESS(BM1,0xC8300604UL)
#define FREG_BM1_ENDIANSWAPWR                    FIO_ADDRESS(BM1,0xC8300618UL)
#define FREG_BM01_AUDVALUE                       FIO_ADDRESS(BM01,0xC83002E0UL)
#define FREG_BM01_AUDCFGEN                       FIO_ADDRESS(BM01,0xC83002F4UL)
#define FREG_BM01_AUDWRPOINTER                   FIO_ADDRESS(BM01,0xC83002E0UL)
#define FREG_BM01_CLEARAUDIRQ                    FIO_ADDRESS(BM01,0xC830021CUL)
#define FREG_BM2_BUFSIZE                         FIO_ADDRESS(BM2,0xC8B00000UL)
#define FREG_BM2_WRPTR                           FIO_ADDRESS(BM2,0xC8B00080UL)
#define FREG_BM2_BASEADDR                        FIO_ADDRESS(BM2,0xC8B00100UL)
#define FREG_BM2_RDPTR                           FIO_ADDRESS(BM2,0xC8B00180UL)
#define FREG_BM2_IRQMASK                         FIO_ADDRESS(BM2,0xC8B00200UL)
#define FREG_BM2_IRQREG                          FIO_ADDRESS(BM2,0xC8B00204UL)
#define FREG_BM23_READENABLE                     FIO_ADDRESS(BM23,0xC8B00208UL)
#define FREG_BM23_GLOBALOFFSET                   FIO_ADDRESS(BM23,0xC8B00210UL)
#define FREG_BM2_ENDIANSWAPWR                    FIO_ADDRESS(BM2,0xC8B00218UL)
#define FREG_BM23_BUFLOWLEV                      FIO_ADDRESS(BM23,0xC8B00220UL)
#define FREG_BM23_BUFHIGHLEV                     FIO_ADDRESS(BM23,0xC8B00240UL)
#define FREG_BM23_STATUSRD                       FIO_ADDRESS(BM23,0xC8B00260UL)
#define FREG_BM23_BUFHIGHLEVIRQCLR               FIO_ADDRESS(BM23,0xC8B00280UL)
#define FREG_BM23_BUFLOWLEVIRQCLR                FIO_ADDRESS(BM23,0xC8B002C0UL)
#define FREG_BM23_BUFSTREAMIRQCLR                FIO_ADDRESS(BM23,0xC8B00300UL)
#define FREG_BM3_BUFSIZE                         FIO_ADDRESS(BM3,0xC8B00400UL)
#define FREG_BM3_WRPTR                           FIO_ADDRESS(BM3,0xC8B00480UL)
#define FREG_BM3_BASEADDR                        FIO_ADDRESS(BM3,0xC8B00500UL)
#define FREG_BM3_RDPTR                           FIO_ADDRESS(BM3,0xC8B00580UL)
#define FREG_BM3_IRQMASK                         FIO_ADDRESS(BM3,0xC8B00600UL)
#define FREG_BM3_IRQREG                          FIO_ADDRESS(BM3,0xC8B00604UL)
#define FREG_BM3_ENDIANSWAPWR                    FIO_ADDRESS(BM3,0xC8B00618UL)
#define FREG_BM23_AUDVALUE                       FIO_ADDRESS(BM23,0xC8B002E0UL)
#define FREG_BM23_AUDCFGEN                       FIO_ADDRESS(BM23,0xC8B002F4UL)
#define FREG_BM23_AUDWRPOINTER                   FIO_ADDRESS(BM23,0xC8B002E0UL)
#define FREG_BM23_CLEARAUDIRQ                    FIO_ADDRESS(BM23,0xC8B0021CUL)
#define FREG_BM0_OVERFLOWIRQ                     FIO_ADDRESS(BM0,0xC8300268UL)
#define FREG_BM1_OVERFLOWIRQ                     FIO_ADDRESS(BM1,0xC8300668UL)
#define FREG_BM2_OVERFLOWIRQ                     FIO_ADDRESS(BM2,0xC8B00268UL)
#define FREG_BM3_OVERFLOWIRQ                     FIO_ADDRESS(BM3,0xC8B00668UL)
#define FREG_BM_HCBSELECT                        FIO_ADDRESS(BM,0xC880011CUL)
#define FREG_BM01_ENDIANSWAPRD                   FIO_ADDRESS(BM01,0xC8300214UL)
#define FREG_BM23_ENDIANSWAPRD                   FIO_ADDRESS(BM23,0xC8B00214UL)
#define FREG_BM01_STATUSRDCLR                    FIO_ADDRESS(BM01,0xC8300264UL)
#define FREG_BM23_STATUSRDCLR                    FIO_ADDRESS(BM23,0xC8B00264UL)

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
extern volatile uint32_t FREG_BM0_IrqMaskMirror;
extern volatile uint32_t FREG_BM01_ReadEnableMirror;
extern volatile uint32_t FREG_BM01_GlobalOffsetMirror;
extern volatile uint32_t FREG_BM0_EndianSwapWrMirror;
extern volatile uint32_t FREG_BM01_BufLowLevMirror[8];
extern volatile uint32_t FREG_BM1_IrqMaskMirror;
extern volatile uint32_t FREG_BM1_EndianSwapWrMirror;
extern volatile uint32_t FREG_BM01_AudValueMirror[5];
extern volatile uint32_t FREG_BM01_AudCfgEnMirror;
extern volatile uint32_t FREG_BM01_ClearAudIrqMirror;
extern volatile uint32_t FREG_BM2_IrqMaskMirror;
extern volatile uint32_t FREG_BM23_ReadEnableMirror;
extern volatile uint32_t FREG_BM23_GlobalOffsetMirror;
extern volatile uint32_t FREG_BM2_EndianSwapWrMirror;
extern volatile uint32_t FREG_BM23_BufLowLevMirror[8];
extern volatile uint32_t FREG_BM3_IrqMaskMirror;
extern volatile uint32_t FREG_BM3_EndianSwapWrMirror;
extern volatile uint32_t FREG_BM23_AudValueMirror[5];
extern volatile uint32_t FREG_BM23_AudCfgEnMirror;
extern volatile uint32_t FREG_BM01_EndianSwapRdMirror;
extern volatile uint32_t FREG_BM23_EndianSwapRdMirror;

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
extern void FREG_BM0_SetBufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetBufSize( uint32_t index, uint32_t value )
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
extern void FREG_BM0_SetBufSize_BufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetBufSize_BufSize( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM0_GetBufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_BUFSIZE+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM0_GetBufSize_BufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetBufSize_BufSize( uint32_t index )
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
extern void FREG_BM0_SetWrPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetWrPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM0_SetWrPtr_WrPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM0_GetWrPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_WRPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM0_GetWrPtr_WrPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetWrPtr_WrPointer( uint32_t index )
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
extern void FREG_BM0_SetBaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetBaseAddr( uint32_t index, uint32_t value )
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
extern void FREG_BM0_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM0_GetBaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_BASEADDR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM0_GetBaseAddr_BaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetBaseAddr_BaseAddr( uint32_t index )
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
extern void FREG_BM0_SetRdPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetRdPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM0_SetRdPtr_RdPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM0_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM0_GetRdPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM0_RDPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM0_GetRdPtr_RdPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM0_GetRdPtr_RdPointer( uint32_t index )
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
extern void FREG_BM0_SetIrqMask( uint32_t value );
#else
INLINE void FREG_BM0_SetIrqMask( uint32_t value )
{
    FREG_BM0_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_IRQMASK)) = value;
}
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
extern void FREG_BM0_SetIrqMask_IrqMask( uint32_t value );
#else
INLINE void FREG_BM0_SetIrqMask_IrqMask( uint32_t value )
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
extern uint32_t FREG_BM0_GetmIrqMask( void );
#else
INLINE uint32_t FREG_BM0_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM0_IrqMaskMirror;
    return( value );
}
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
extern uint32_t FREG_BM0_GetmIrqMask_IrqMask( void );
#else
INLINE uint32_t FREG_BM0_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM0_IrqMaskMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM0_GetIrqReg( void );
#else
INLINE uint32_t FREG_BM0_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM0_IRQREG));
    return( value );
}
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
extern uint32_t FREG_BM0_ExtractIrqReg_IrqReg( uint32_t value );
#else
INLINE uint32_t FREG_BM0_ExtractIrqReg_IrqReg( uint32_t value )
{
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM01_SetReadEnable( uint32_t value );
#else
INLINE void FREG_BM01_SetReadEnable( uint32_t value )
{
    FREG_BM01_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_READENABLE)) = value;
}
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
extern void FREG_BM01_SetReadEnable_Bm01ReadSelect( uint32_t value );
#else
INLINE void FREG_BM01_SetReadEnable_Bm01ReadSelect( uint32_t value )
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
extern void FREG_BM01_SetReadEnable_Bm01ReadEnable( uint32_t value );
#else
INLINE void FREG_BM01_SetReadEnable_Bm01ReadEnable( uint32_t value )
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
extern uint32_t FREG_BM01_GetmReadEnable( void );
#else
INLINE uint32_t FREG_BM01_GetmReadEnable( void )
{
    register uint32_t value = FREG_BM01_ReadEnableMirror;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmReadEnable_Bm01ReadSelect( void );
#else
INLINE uint32_t FREG_BM01_GetmReadEnable_Bm01ReadSelect( void )
{
    register uint32_t value = FREG_BM01_ReadEnableMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmReadEnable_Bm01ReadEnable( void );
#else
INLINE uint32_t FREG_BM01_GetmReadEnable_Bm01ReadEnable( void )
{
    register uint32_t value = FREG_BM01_ReadEnableMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
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
extern void FREG_BM01_SetGlobalOffset( uint32_t value );
#else
INLINE void FREG_BM01_SetGlobalOffset( uint32_t value )
{
    FREG_BM01_GlobalOffsetMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_GLOBALOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_GLOBALOFFSET)) = value;
}
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
extern void FREG_BM01_SetGlobalOffset_Bm01Offset( uint32_t value );
#else
INLINE void FREG_BM01_SetGlobalOffset_Bm01Offset( uint32_t value )
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
extern uint32_t FREG_BM01_GetmGlobalOffset( void );
#else
INLINE uint32_t FREG_BM01_GetmGlobalOffset( void )
{
    register uint32_t value = FREG_BM01_GlobalOffsetMirror;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmGlobalOffset_Bm01Offset( void );
#else
INLINE uint32_t FREG_BM01_GetmGlobalOffset_Bm01Offset( void )
{
    register uint32_t value = FREG_BM01_GlobalOffsetMirror;
    value = ( value & 0xF8000000UL ) >> 27;
    return( value );
}
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
extern void FREG_BM0_SetEndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM0_SetEndianSwapWr( uint32_t value )
{
    FREG_BM0_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM0_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM0_ENDIANSWAPWR)) = value;
}
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
extern void FREG_BM0_SetEndianSwapWr_Bm0EndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM0_SetEndianSwapWr_Bm0EndianSwapWr( uint32_t value )
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
extern uint32_t FREG_BM0_GetmEndianSwapWr( void );
#else
INLINE uint32_t FREG_BM0_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM0_EndianSwapWrMirror;
    return( value );
}
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
extern uint32_t FREG_BM0_GetmEndianSwapWr_Bm0EndianSwapWr( void );
#else
INLINE uint32_t FREG_BM0_GetmEndianSwapWr_Bm0EndianSwapWr( void )
{
    register uint32_t value = FREG_BM0_EndianSwapWrMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM01_SetBufLowLev( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufLowLev( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetBufLowLev_Bm01BufLowLevIrqEn( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufLowLev_Bm01BufLowLevIrqEn( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetBufLowLev_Bm01BufLowLev( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufLowLev_Bm01BufLowLev( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM01_GetmBufLowLev( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetmBufLowLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_BufLowLevMirror[index];
    return( value );
}
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
extern uint32_t FREG_BM01_GetmBufLowLev_Bm01BufLowLevIrqEn( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetmBufLowLev_Bm01BufLowLevIrqEn( uint32_t index )
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
extern uint32_t FREG_BM01_GetmBufLowLev_Bm01BufLowLev( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetmBufLowLev_Bm01BufLowLev( uint32_t index )
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
extern void FREG_BM01_SetBufHighLev( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufHighLev( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetBufHighLev_Bm01BufHighLevIrqEn( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufHighLev_Bm01BufHighLevIrqEn( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetBufHighLev_Bm01BufHighLevLimit( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufHighLev_Bm01BufHighLevLimit( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetBufHighLev_Bm01BufHighLevStreamNb( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetBufHighLev_Bm01BufHighLevStreamNb( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM01_GetBufHighLev( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufHighLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEV+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevIrqEn( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevIrqEn( uint32_t index )
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
extern uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevLimit( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevLimit( uint32_t index )
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
extern uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevStreamNb( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufHighLev_Bm01BufHighLevStreamNb( uint32_t index )
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
extern uint32_t FREG_BM01_GetStatusRd( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_BmStreamStatus( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_BmStreamStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x7F000000UL ) >> 24;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_AudIrq( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_AudIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x00F80000UL ) >> 19;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_LevelIrq( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_LevelIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_Bm0Int( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_Bm0Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_Bm1Int( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_Bm1Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_BufferLowIrqFlag( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_BufferLowIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRd_BufferHighIrqFlag( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRd_BufferHighIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRD));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM01_GetBufHighLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufHighLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFHIGHLEVIRQCLR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM01_GetBufHighLevIrqClr_Bm01BufHighLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufHighLevIrqClr_Bm01BufHighLevIrqClr( uint32_t index )
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
extern uint32_t FREG_BM01_GetBufLowLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufLowLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFLOWLEVIRQCLR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM01_GetBufLowLevIrqClr_Bm01BufLowLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufLowLevIrqClr_Bm01BufLowLevIrqClr( uint32_t index )
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
extern uint32_t FREG_BM01_GetBufStreamIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufStreamIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_BUFSTREAMIRQCLR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM01_GetBufStreamIrqClr_Bm01BufStreamIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetBufStreamIrqClr_Bm01BufStreamIrqClr( uint32_t index )
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
extern void FREG_BM1_SetBufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetBufSize( uint32_t index, uint32_t value )
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
extern void FREG_BM1_SetBufSize_BufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetBufSize_BufSize( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM1_GetBufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_BUFSIZE+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM1_GetBufSize_BufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetBufSize_BufSize( uint32_t index )
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
extern void FREG_BM1_SetWrPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetWrPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM1_SetWrPtr_WrPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM1_GetWrPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_WRPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM1_GetWrPtr_WrPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetWrPtr_WrPointer( uint32_t index )
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
extern void FREG_BM1_SetBaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetBaseAddr( uint32_t index, uint32_t value )
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
extern void FREG_BM1_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM1_GetBaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_BASEADDR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM1_GetBaseAddr_BaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetBaseAddr_BaseAddr( uint32_t index )
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
extern void FREG_BM1_SetRdPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetRdPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM1_SetRdPtr_RdPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM1_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM1_GetRdPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM1_RDPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM1_GetRdPtr_RdPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM1_GetRdPtr_RdPointer( uint32_t index )
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
extern void FREG_BM1_SetIrqMask( uint32_t value );
#else
INLINE void FREG_BM1_SetIrqMask( uint32_t value )
{
    FREG_BM1_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_IRQMASK)) = value;
}
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
extern void FREG_BM1_SetIrqMask_IrqMask( uint32_t value );
#else
INLINE void FREG_BM1_SetIrqMask_IrqMask( uint32_t value )
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
extern uint32_t FREG_BM1_GetmIrqMask( void );
#else
INLINE uint32_t FREG_BM1_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM1_IrqMaskMirror;
    return( value );
}
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
extern uint32_t FREG_BM1_GetmIrqMask_IrqMask( void );
#else
INLINE uint32_t FREG_BM1_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM1_IrqMaskMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM1_GetIrqReg( void );
#else
INLINE uint32_t FREG_BM1_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM1_IRQREG));
    return( value );
}
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
extern uint32_t FREG_BM1_ExtractIrqReg_IrqReg( uint32_t value );
#else
INLINE uint32_t FREG_BM1_ExtractIrqReg_IrqReg( uint32_t value )
{
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM1_SetEndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM1_SetEndianSwapWr( uint32_t value )
{
    FREG_BM1_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM1_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM1_ENDIANSWAPWR)) = value;
}
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
extern void FREG_BM1_SetEndianSwapWr_Bm1EndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM1_SetEndianSwapWr_Bm1EndianSwapWr( uint32_t value )
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
extern uint32_t FREG_BM1_GetmEndianSwapWr( void );
#else
INLINE uint32_t FREG_BM1_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM1_EndianSwapWrMirror;
    return( value );
}
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
extern uint32_t FREG_BM1_GetmEndianSwapWr_Bm1EndianSwapWr( void );
#else
INLINE uint32_t FREG_BM1_GetmEndianSwapWr_Bm1EndianSwapWr( void )
{
    register uint32_t value = FREG_BM1_EndianSwapWrMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM01_SetAudValue( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetAudValue( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetAudValue_AudCompareEn( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetAudValue_AudCompareEn( uint32_t index, uint32_t value )
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
extern void FREG_BM01_SetAudValue_AudValue( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM01_SetAudValue_AudValue( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM01_GetmAudValue( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetmAudValue( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM01_AudValueMirror[index];
    return( value );
}
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
extern uint32_t FREG_BM01_GetmAudValue_AudCompareEn( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetmAudValue_AudCompareEn( uint32_t index )
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
extern uint32_t FREG_BM01_GetmAudValue_AudValue( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetmAudValue_AudValue( uint32_t index )
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
extern void FREG_BM01_SetAudCfgEn( uint32_t value );
#else
INLINE void FREG_BM01_SetAudCfgEn( uint32_t value )
{
    FREG_BM01_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_AUDCFGEN)) = value;
}
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
extern void FREG_BM01_SetAudCfgEn_GlobalAudEnable( uint32_t value );
#else
INLINE void FREG_BM01_SetAudCfgEn_GlobalAudEnable( uint32_t value )
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
extern void FREG_BM01_SetAudCfgEn_AudBufferIndex( uint32_t value );
#else
INLINE void FREG_BM01_SetAudCfgEn_AudBufferIndex( uint32_t value )
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
extern uint32_t FREG_BM01_GetmAudCfgEn( void );
#else
INLINE uint32_t FREG_BM01_GetmAudCfgEn( void )
{
    register uint32_t value = FREG_BM01_AudCfgEnMirror;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmAudCfgEn_GlobalAudEnable( void );
#else
INLINE uint32_t FREG_BM01_GetmAudCfgEn_GlobalAudEnable( void )
{
    register uint32_t value = FREG_BM01_AudCfgEnMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmAudCfgEn_AudBufferIndex( void );
#else
INLINE uint32_t FREG_BM01_GetmAudCfgEn_AudBufferIndex( void )
{
    register uint32_t value = FREG_BM01_AudCfgEnMirror;
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM01_GetAudWrPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetAudWrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM01_AUDWRPOINTER+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM01_GetAudWrPointer_AudWritePointer( uint32_t index );
#else
INLINE uint32_t FREG_BM01_GetAudWrPointer_AudWritePointer( uint32_t index )
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
extern void FREG_BM01_SetClearAudIrq( uint32_t value );
#else
INLINE void FREG_BM01_SetClearAudIrq( uint32_t value )
{
    FREG_BM01_ClearAudIrqMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_CLEARAUDIRQ)) = value;
}
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
extern void FREG_BM01_SetClearAudIrq_Aud4IrqClr( uint32_t value );
#else
INLINE void FREG_BM01_SetClearAudIrq_Aud4IrqClr( uint32_t value )
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
extern void FREG_BM01_SetClearAudIrq_Aud3IrqClr( uint32_t value );
#else
INLINE void FREG_BM01_SetClearAudIrq_Aud3IrqClr( uint32_t value )
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
extern void FREG_BM01_SetClearAudIrq_Aud2IrqClr( uint32_t value );
#else
INLINE void FREG_BM01_SetClearAudIrq_Aud2IrqClr( uint32_t value )
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
extern void FREG_BM01_SetClearAudIrq_Aud1IrqClr( uint32_t value );
#else
INLINE void FREG_BM01_SetClearAudIrq_Aud1IrqClr( uint32_t value )
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
extern void FREG_BM01_SetClearAudIrq_Aud0IrqClr( uint32_t value );
#else
INLINE void FREG_BM01_SetClearAudIrq_Aud0IrqClr( uint32_t value )
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
extern uint32_t FREG_BM01_GetmClearAudIrq( void );
#else
INLINE uint32_t FREG_BM01_GetmClearAudIrq( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmClearAudIrq_Aud4IrqClr( void );
#else
INLINE uint32_t FREG_BM01_GetmClearAudIrq_Aud4IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmClearAudIrq_Aud3IrqClr( void );
#else
INLINE uint32_t FREG_BM01_GetmClearAudIrq_Aud3IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmClearAudIrq_Aud2IrqClr( void );
#else
INLINE uint32_t FREG_BM01_GetmClearAudIrq_Aud2IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmClearAudIrq_Aud1IrqClr( void );
#else
INLINE uint32_t FREG_BM01_GetmClearAudIrq_Aud1IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmClearAudIrq_Aud0IrqClr( void );
#else
INLINE uint32_t FREG_BM01_GetmClearAudIrq_Aud0IrqClr( void )
{
    register uint32_t value = FREG_BM01_ClearAudIrqMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_BM2_SetBufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetBufSize( uint32_t index, uint32_t value )
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
extern void FREG_BM2_SetBufSize_BufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetBufSize_BufSize( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM2_GetBufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_BUFSIZE+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM2_GetBufSize_BufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetBufSize_BufSize( uint32_t index )
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
extern void FREG_BM2_SetWrPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetWrPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM2_SetWrPtr_WrPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM2_GetWrPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_WRPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM2_GetWrPtr_WrPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetWrPtr_WrPointer( uint32_t index )
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
extern void FREG_BM2_SetBaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetBaseAddr( uint32_t index, uint32_t value )
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
extern void FREG_BM2_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM2_GetBaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_BASEADDR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM2_GetBaseAddr_BaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetBaseAddr_BaseAddr( uint32_t index )
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
extern void FREG_BM2_SetRdPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetRdPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM2_SetRdPtr_RdPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM2_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM2_GetRdPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM2_RDPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM2_GetRdPtr_RdPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM2_GetRdPtr_RdPointer( uint32_t index )
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
extern void FREG_BM2_SetIrqMask( uint32_t value );
#else
INLINE void FREG_BM2_SetIrqMask( uint32_t value )
{
    FREG_BM2_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_IRQMASK)) = value;
}
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
extern void FREG_BM2_SetIrqMask_IrqMask( uint32_t value );
#else
INLINE void FREG_BM2_SetIrqMask_IrqMask( uint32_t value )
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
extern uint32_t FREG_BM2_GetmIrqMask( void );
#else
INLINE uint32_t FREG_BM2_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM2_IrqMaskMirror;
    return( value );
}
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
extern uint32_t FREG_BM2_GetmIrqMask_IrqMask( void );
#else
INLINE uint32_t FREG_BM2_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM2_IrqMaskMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM2_GetIrqReg( void );
#else
INLINE uint32_t FREG_BM2_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM2_IRQREG));
    return( value );
}
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
extern uint32_t FREG_BM2_ExtractIrqReg_IrqReg( uint32_t value );
#else
INLINE uint32_t FREG_BM2_ExtractIrqReg_IrqReg( uint32_t value )
{
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM23_SetReadEnable( uint32_t value );
#else
INLINE void FREG_BM23_SetReadEnable( uint32_t value )
{
    FREG_BM23_ReadEnableMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_READENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_READENABLE)) = value;
}
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
extern void FREG_BM23_SetReadEnable_Bm23ReadSelect( uint32_t value );
#else
INLINE void FREG_BM23_SetReadEnable_Bm23ReadSelect( uint32_t value )
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
extern void FREG_BM23_SetReadEnable_Bm23ReadEnable( uint32_t value );
#else
INLINE void FREG_BM23_SetReadEnable_Bm23ReadEnable( uint32_t value )
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
extern uint32_t FREG_BM23_GetmReadEnable( void );
#else
INLINE uint32_t FREG_BM23_GetmReadEnable( void )
{
    register uint32_t value = FREG_BM23_ReadEnableMirror;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmReadEnable_Bm23ReadSelect( void );
#else
INLINE uint32_t FREG_BM23_GetmReadEnable_Bm23ReadSelect( void )
{
    register uint32_t value = FREG_BM23_ReadEnableMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmReadEnable_Bm23ReadEnable( void );
#else
INLINE uint32_t FREG_BM23_GetmReadEnable_Bm23ReadEnable( void )
{
    register uint32_t value = FREG_BM23_ReadEnableMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
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
extern void FREG_BM23_SetGlobalOffset( uint32_t value );
#else
INLINE void FREG_BM23_SetGlobalOffset( uint32_t value )
{
    FREG_BM23_GlobalOffsetMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_GLOBALOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_GLOBALOFFSET)) = value;
}
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
extern void FREG_BM23_SetGlobalOffset_Bm23Offset( uint32_t value );
#else
INLINE void FREG_BM23_SetGlobalOffset_Bm23Offset( uint32_t value )
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
extern uint32_t FREG_BM23_GetmGlobalOffset( void );
#else
INLINE uint32_t FREG_BM23_GetmGlobalOffset( void )
{
    register uint32_t value = FREG_BM23_GlobalOffsetMirror;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmGlobalOffset_Bm23Offset( void );
#else
INLINE uint32_t FREG_BM23_GetmGlobalOffset_Bm23Offset( void )
{
    register uint32_t value = FREG_BM23_GlobalOffsetMirror;
    value = ( value & 0xF8000000UL ) >> 27;
    return( value );
}
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
extern void FREG_BM2_SetEndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM2_SetEndianSwapWr( uint32_t value )
{
    FREG_BM2_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM2_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM2_ENDIANSWAPWR)) = value;
}
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
extern void FREG_BM2_SetEndianSwapWr_Bm2EndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM2_SetEndianSwapWr_Bm2EndianSwapWr( uint32_t value )
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
extern uint32_t FREG_BM2_GetmEndianSwapWr( void );
#else
INLINE uint32_t FREG_BM2_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM2_EndianSwapWrMirror;
    return( value );
}
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
extern uint32_t FREG_BM2_GetmEndianSwapWr_Bm2EndianSwapWr( void );
#else
INLINE uint32_t FREG_BM2_GetmEndianSwapWr_Bm2EndianSwapWr( void )
{
    register uint32_t value = FREG_BM2_EndianSwapWrMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM23_SetBufLowLev( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufLowLev( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetBufLowLev_Bm23BufLowLevIrqEn( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufLowLev_Bm23BufLowLevIrqEn( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetBufLowLev_Bm23BufLowLev( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufLowLev_Bm23BufLowLev( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM23_GetmBufLowLev( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetmBufLowLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_BufLowLevMirror[index];
    return( value );
}
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
extern uint32_t FREG_BM23_GetmBufLowLev_Bm23BufLowLevIrqEn( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetmBufLowLev_Bm23BufLowLevIrqEn( uint32_t index )
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
extern uint32_t FREG_BM23_GetmBufLowLev_Bm23BufLowLev( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetmBufLowLev_Bm23BufLowLev( uint32_t index )
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
extern void FREG_BM23_SetBufHighLev( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufHighLev( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetBufHighLev_Bm23BufHighLevIrqEn( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufHighLev_Bm23BufHighLevIrqEn( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetBufHighLev_Bm23BufHighLevLimit( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufHighLev_Bm23BufHighLevLimit( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetBufHighLev_Bm23BufHighLevStreamNb( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetBufHighLev_Bm23BufHighLevStreamNb( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM23_GetBufHighLev( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufHighLev( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEV+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevIrqEn( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevIrqEn( uint32_t index )
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
extern uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevLimit( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevLimit( uint32_t index )
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
extern uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevStreamNb( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufHighLev_Bm23BufHighLevStreamNb( uint32_t index )
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
extern uint32_t FREG_BM23_GetStatusRd( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_BmStreamStatus( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_BmStreamStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x7F000000UL ) >> 24;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_AudIrq( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_AudIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x00F80000UL ) >> 19;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_LevelIrq( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_LevelIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_Bm2Int( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_Bm2Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x00020000UL ) >> 17;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_Bm3Int( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_Bm3Int( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_BufferLowIrqFlag( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_BufferLowIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRd_BufferHighIrqFlag( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRd_BufferHighIrqFlag( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRD));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM23_GetBufHighLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufHighLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFHIGHLEVIRQCLR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM23_GetBufHighLevIrqClr_Bm23BufHighLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufHighLevIrqClr_Bm23BufHighLevIrqClr( uint32_t index )
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
extern uint32_t FREG_BM23_GetBufLowLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufLowLevIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 8 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFLOWLEVIRQCLR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM23_GetBufLowLevIrqClr_Bm23BufLowLevIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufLowLevIrqClr_Bm23BufLowLevIrqClr( uint32_t index )
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
extern uint32_t FREG_BM23_GetBufStreamIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufStreamIrqClr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_BUFSTREAMIRQCLR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM23_GetBufStreamIrqClr_Bm23BufStreamIrqClr( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetBufStreamIrqClr_Bm23BufStreamIrqClr( uint32_t index )
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
extern void FREG_BM3_SetBufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetBufSize( uint32_t index, uint32_t value )
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
extern void FREG_BM3_SetBufSize_BufSize( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetBufSize_BufSize( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM3_GetBufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetBufSize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_BUFSIZE+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM3_GetBufSize_BufSize( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetBufSize_BufSize( uint32_t index )
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
extern void FREG_BM3_SetWrPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetWrPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM3_SetWrPtr_WrPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetWrPtr_WrPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM3_GetWrPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetWrPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_WRPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM3_GetWrPtr_WrPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetWrPtr_WrPointer( uint32_t index )
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
extern void FREG_BM3_SetBaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetBaseAddr( uint32_t index, uint32_t value )
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
extern void FREG_BM3_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetBaseAddr_BaseAddr( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM3_GetBaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetBaseAddr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_BASEADDR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM3_GetBaseAddr_BaseAddr( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetBaseAddr_BaseAddr( uint32_t index )
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
extern void FREG_BM3_SetRdPtr( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetRdPtr( uint32_t index, uint32_t value )
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
extern void FREG_BM3_SetRdPtr_RdPointer( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM3_SetRdPtr_RdPointer( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM3_GetRdPtr( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetRdPtr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 32 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM3_RDPTR+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM3_GetRdPtr_RdPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM3_GetRdPtr_RdPointer( uint32_t index )
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
extern void FREG_BM3_SetIrqMask( uint32_t value );
#else
INLINE void FREG_BM3_SetIrqMask( uint32_t value )
{
    FREG_BM3_IrqMaskMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_IRQMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_IRQMASK)) = value;
}
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
extern void FREG_BM3_SetIrqMask_IrqMask( uint32_t value );
#else
INLINE void FREG_BM3_SetIrqMask_IrqMask( uint32_t value )
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
extern uint32_t FREG_BM3_GetmIrqMask( void );
#else
INLINE uint32_t FREG_BM3_GetmIrqMask( void )
{
    register uint32_t value = FREG_BM3_IrqMaskMirror;
    return( value );
}
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
extern uint32_t FREG_BM3_GetmIrqMask_IrqMask( void );
#else
INLINE uint32_t FREG_BM3_GetmIrqMask_IrqMask( void )
{
    register uint32_t value = FREG_BM3_IrqMaskMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM3_GetIrqReg( void );
#else
INLINE uint32_t FREG_BM3_GetIrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM3_IRQREG));
    return( value );
}
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
extern uint32_t FREG_BM3_ExtractIrqReg_IrqReg( uint32_t value );
#else
INLINE uint32_t FREG_BM3_ExtractIrqReg_IrqReg( uint32_t value )
{
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM3_SetEndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM3_SetEndianSwapWr( uint32_t value )
{
    FREG_BM3_EndianSwapWrMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM3_ENDIANSWAPWR, value );
    #endif
    *((volatile uint32_t*)(FREG_BM3_ENDIANSWAPWR)) = value;
}
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
extern void FREG_BM3_SetEndianSwapWr_Bm3EndianSwapWr( uint32_t value );
#else
INLINE void FREG_BM3_SetEndianSwapWr_Bm3EndianSwapWr( uint32_t value )
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
extern uint32_t FREG_BM3_GetmEndianSwapWr( void );
#else
INLINE uint32_t FREG_BM3_GetmEndianSwapWr( void )
{
    register uint32_t value = FREG_BM3_EndianSwapWrMirror;
    return( value );
}
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
extern uint32_t FREG_BM3_GetmEndianSwapWr_Bm3EndianSwapWr( void );
#else
INLINE uint32_t FREG_BM3_GetmEndianSwapWr_Bm3EndianSwapWr( void )
{
    register uint32_t value = FREG_BM3_EndianSwapWrMirror;
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM23_SetAudValue( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetAudValue( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetAudValue_AudCompareEn( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetAudValue_AudCompareEn( uint32_t index, uint32_t value )
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
extern void FREG_BM23_SetAudValue_AudValue( uint32_t index, uint32_t value );
#else
INLINE void FREG_BM23_SetAudValue_AudValue( uint32_t index, uint32_t value )
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
extern uint32_t FREG_BM23_GetmAudValue( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetmAudValue( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_BM23_AudValueMirror[index];
    return( value );
}
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
extern uint32_t FREG_BM23_GetmAudValue_AudCompareEn( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetmAudValue_AudCompareEn( uint32_t index )
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
extern uint32_t FREG_BM23_GetmAudValue_AudValue( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetmAudValue_AudValue( uint32_t index )
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
extern void FREG_BM23_SetAudCfgEn( uint32_t value );
#else
INLINE void FREG_BM23_SetAudCfgEn( uint32_t value )
{
    FREG_BM23_AudCfgEnMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_AUDCFGEN, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_AUDCFGEN)) = value;
}
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
extern void FREG_BM23_SetAudCfgEn_GlobalAudEnable( uint32_t value );
#else
INLINE void FREG_BM23_SetAudCfgEn_GlobalAudEnable( uint32_t value )
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
extern void FREG_BM23_SetAudCfgEn_AudBufferIndex( uint32_t value );
#else
INLINE void FREG_BM23_SetAudCfgEn_AudBufferIndex( uint32_t value )
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
extern uint32_t FREG_BM23_GetmAudCfgEn( void );
#else
INLINE uint32_t FREG_BM23_GetmAudCfgEn( void )
{
    register uint32_t value = FREG_BM23_AudCfgEnMirror;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmAudCfgEn_GlobalAudEnable( void );
#else
INLINE uint32_t FREG_BM23_GetmAudCfgEn_GlobalAudEnable( void )
{
    register uint32_t value = FREG_BM23_AudCfgEnMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmAudCfgEn_AudBufferIndex( void );
#else
INLINE uint32_t FREG_BM23_GetmAudCfgEn_AudBufferIndex( void )
{
    register uint32_t value = FREG_BM23_AudCfgEnMirror;
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM23_GetAudWrPointer( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetAudWrPointer( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 5 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_BM23_AUDWRPOINTER+(index*0x4)));
    return( value );
}
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
extern uint32_t FREG_BM23_GetAudWrPointer_AudWritePointer( uint32_t index );
#else
INLINE uint32_t FREG_BM23_GetAudWrPointer_AudWritePointer( uint32_t index )
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
extern void FREG_BM23_SetClearAudIrq( uint32_t value );
#else
INLINE void FREG_BM23_SetClearAudIrq( uint32_t value )
{
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_CLEARAUDIRQ, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_CLEARAUDIRQ)) = value;
}
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
extern uint32_t FREG_BM0_GetOverflowIrq( void );
#else
INLINE uint32_t FREG_BM0_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM0_OVERFLOWIRQ));
    return( value );
}
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
extern uint32_t FREG_BM0_GetOverflowIrq_IrqReg( void );
#else
INLINE uint32_t FREG_BM0_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM0_OVERFLOWIRQ));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM1_GetOverflowIrq( void );
#else
INLINE uint32_t FREG_BM1_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM1_OVERFLOWIRQ));
    return( value );
}
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
extern uint32_t FREG_BM1_GetOverflowIrq_IrqReg( void );
#else
INLINE uint32_t FREG_BM1_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM1_OVERFLOWIRQ));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM2_GetOverflowIrq( void );
#else
INLINE uint32_t FREG_BM2_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM2_OVERFLOWIRQ));
    return( value );
}
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
extern uint32_t FREG_BM2_GetOverflowIrq_IrqReg( void );
#else
INLINE uint32_t FREG_BM2_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM2_OVERFLOWIRQ));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM3_GetOverflowIrq( void );
#else
INLINE uint32_t FREG_BM3_GetOverflowIrq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM3_OVERFLOWIRQ));
    return( value );
}
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
extern uint32_t FREG_BM3_GetOverflowIrq_IrqReg( void );
#else
INLINE uint32_t FREG_BM3_GetOverflowIrq_IrqReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM3_OVERFLOWIRQ));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM_SetHcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect( uint32_t value )
{
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM_HCBSELECT, value );
    #endif
    *((volatile uint32_t*)(FREG_BM_HCBSELECT)) = value;
}
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
extern void FREG_BM_SetHcbSelect_AudioHcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_AudioHcbSelect( uint32_t value )
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
extern void FREG_BM_SetHcbSelect_TtxHcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_TtxHcbSelect( uint32_t value )
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
extern void FREG_BM_SetHcbSelect_SpdifHcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_SpdifHcbSelect( uint32_t value )
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
extern void FREG_BM_SetHcbSelect_I2s3HcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_I2s3HcbSelect( uint32_t value )
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
extern void FREG_BM_SetHcbSelect_I2s2HcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_I2s2HcbSelect( uint32_t value )
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
extern void FREG_BM_SetHcbSelect_I2s1HcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_I2s1HcbSelect( uint32_t value )
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
extern void FREG_BM_SetHcbSelect_I2s0HcbSelect( uint32_t value );
#else
INLINE void FREG_BM_SetHcbSelect_I2s0HcbSelect( uint32_t value )
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
extern uint32_t FREG_BM_GetHcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_AudioHcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_AudioHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_TtxHcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_TtxHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_SpdifHcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_SpdifHcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_I2s3HcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_I2s3HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_I2s2HcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_I2s2HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_I2s1HcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_I2s1HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_BM_GetHcbSelect_I2s0HcbSelect( void );
#else
INLINE uint32_t FREG_BM_GetHcbSelect_I2s0HcbSelect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM_HCBSELECT));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_BM01_SetEndianSwapRd( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd( uint32_t value )
{
    FREG_BM01_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM01_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM01_ENDIANSWAPRD)) = value;
}
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
extern void FREG_BM01_SetEndianSwapRd_AudioRd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_AudioRd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_TtxRd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_TtxRd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_SpdifRd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_SpdifRd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s3Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s3Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s2Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s2Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s1Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s1Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s0Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s0Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_AudioRdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_AudioRdLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_TtxRdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_TtxRdLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_SpdifRdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_SpdifRdLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s3RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s3RdLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s2RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s2RdLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s1RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s1RdLittleEndian( uint32_t value )
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
extern void FREG_BM01_SetEndianSwapRd_I2s0RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM01_SetEndianSwapRd_I2s0RdLittleEndian( uint32_t value )
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
extern uint32_t FREG_BM01_GetmEndianSwapRd( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_AudioRd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_AudioRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_TtxRd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_TtxRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_SpdifRd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_SpdifRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s3Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s3Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s2Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s2Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s1Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s1Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s0Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s0Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_AudioRdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_AudioRdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_TtxRdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_TtxRdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_SpdifRdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_SpdifRdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s3RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s3RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s2RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s2RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s1RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s1RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_BM01_GetmEndianSwapRd_I2s0RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM01_GetmEndianSwapRd_I2s0RdLittleEndian( void )
{
    register uint32_t value = FREG_BM01_EndianSwapRdMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_BM23_SetEndianSwapRd( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd( uint32_t value )
{
    FREG_BM23_EndianSwapRdMirror = value;
    #if FREG_BM_ENABLE_DEBUG_PRINT == 1
        FREG_BM_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_BM", FREG_BM23_ENDIANSWAPRD, value );
    #endif
    *((volatile uint32_t*)(FREG_BM23_ENDIANSWAPRD)) = value;
}
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
extern void FREG_BM23_SetEndianSwapRd_AudioRd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_AudioRd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_TtxRd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_TtxRd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_SpdifRd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_SpdifRd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s3Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s3Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s2Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s2Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s1Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s1Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s0Rd2byteLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s0Rd2byteLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_AudioRdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_AudioRdLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_TtxRdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_TtxRdLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_SpdifRdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_SpdifRdLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s3RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s3RdLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s2RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s2RdLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s1RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s1RdLittleEndian( uint32_t value )
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
extern void FREG_BM23_SetEndianSwapRd_I2s0RdLittleEndian( uint32_t value );
#else
INLINE void FREG_BM23_SetEndianSwapRd_I2s0RdLittleEndian( uint32_t value )
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
extern uint32_t FREG_BM23_GetmEndianSwapRd( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_AudioRd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_AudioRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_TtxRd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_TtxRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_SpdifRd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_SpdifRd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s3Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s3Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s2Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s2Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s1Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s1Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s0Rd2byteLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s0Rd2byteLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_AudioRdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_AudioRdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_TtxRdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_TtxRdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_SpdifRdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_SpdifRdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s3RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s3RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s2RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s2RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s1RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s1RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_BM23_GetmEndianSwapRd_I2s0RdLittleEndian( void );
#else
INLINE uint32_t FREG_BM23_GetmEndianSwapRd_I2s0RdLittleEndian( void )
{
    register uint32_t value = FREG_BM23_EndianSwapRdMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM01_GetStatusRdClr( void );
#else
INLINE uint32_t FREG_BM01_GetStatusRdClr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM01_STATUSRDCLR));
    return( value );
}
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
extern uint32_t FREG_BM01_ExtractStatusRdClr_LevelIrq( uint32_t value );
#else
INLINE uint32_t FREG_BM01_ExtractStatusRdClr_LevelIrq( uint32_t value )
{
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
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
extern uint32_t FREG_BM01_ExtractStatusRdClr_BufferLowIrqFlag( uint32_t value );
#else
INLINE uint32_t FREG_BM01_ExtractStatusRdClr_BufferLowIrqFlag( uint32_t value )
{
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM01_ExtractStatusRdClr_BufferHighIrqFlag( uint32_t value );
#else
INLINE uint32_t FREG_BM01_ExtractStatusRdClr_BufferHighIrqFlag( uint32_t value )
{
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_BM23_GetStatusRdClr( void );
#else
INLINE uint32_t FREG_BM23_GetStatusRdClr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_BM23_STATUSRDCLR));
    return( value );
}
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
extern uint32_t FREG_BM23_ExtractStatusRdClr_LevelIrq( uint32_t value );
#else
INLINE uint32_t FREG_BM23_ExtractStatusRdClr_LevelIrq( uint32_t value )
{
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
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
extern uint32_t FREG_BM23_ExtractStatusRdClr_BufferLowIrqFlag( uint32_t value );
#else
INLINE uint32_t FREG_BM23_ExtractStatusRdClr_BufferLowIrqFlag( uint32_t value )
{
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_BM23_ExtractStatusRdClr_BufferHighIrqFlag( uint32_t value );
#else
INLINE uint32_t FREG_BM23_ExtractStatusRdClr_BufferHighIrqFlag( uint32_t value )
{
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern void FREG_BM_Init( void );

#endif
