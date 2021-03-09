/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_upi.h
**
** \brief     UPI access functions
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
#if !defined(FREG_UPI_H)
#define FREG_UPI_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_UPI_ENABLE_DEBUG_PRINT   0
#define FREG_UPI_DEBUG_PRINT_FUNCTION printf

#if FREG_UPI_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_UPI_ADDREXT                         FIO_ADDRESS(UPI,0x980000C0UL)
#define FREG_UPI_CSSEL                           FIO_ADDRESS(UPI,0x980000C4UL)
#define FREG_UPI_CSMODE                          FIO_ADDRESS(UPI,0x980000C8UL)
#define FREG_UPI_WAITTIME                        FIO_ADDRESS(UPI,0x98000030UL)
#define FREG_UPI_WAITTIMEEN                      FIO_ADDRESS(UPI,0x98000034UL)
#define FREG_UPI_LASTWAITTIME                    FIO_ADDRESS(UPI,0x98000038UL)
#define FREG_UPI_WAITTIMESTATUS                  FIO_ADDRESS(UPI,0x9800003CUL)
#define FREG_UPI_ATACTRL                         FIO_ADDRESS(UPI,0x98001000UL)
#define FREG_UPI_ATASTAT                         FIO_ADDRESS(UPI,0x98001004UL)
#define FREG_UPI_ATAPCTR                         FIO_ADDRESS(UPI,0x98001008UL)
#define FREG_UPI_ATAPFTR0                        FIO_ADDRESS(UPI,0x9800100CUL)
#define FREG_UPI_ATAPFTR1                        FIO_ADDRESS(UPI,0x98001010UL)
#define FREG_UPI_ATADTR0                         FIO_ADDRESS(UPI,0x98001014UL)
#define FREG_UPI_ATADTR1                         FIO_ADDRESS(UPI,0x98001018UL)
#define FREG_UPI_MODEX                           FIO_ADDRESS(UPI,0x98000000UL)
#define FREG_UPI_TALSX                           FIO_ADDRESS(UPI,0x98000004UL)
#define FREG_UPI_TALHX                           FIO_ADDRESS(UPI,0x98000008UL)
#define FREG_UPI_TRSX                            FIO_ADDRESS(UPI,0x9800000CUL)
#define FREG_UPI_TRDSX                           FIO_ADDRESS(UPI,0x98000010UL)
#define FREG_UPI_TRDHX                           FIO_ADDRESS(UPI,0x98000014UL)
#define FREG_UPI_TRRX                            FIO_ADDRESS(UPI,0x98000018UL)
#define FREG_UPI_TWSX                            FIO_ADDRESS(UPI,0x9800001CUL)
#define FREG_UPI_TWPX                            FIO_ADDRESS(UPI,0x98000020UL)
#define FREG_UPI_TWRX                            FIO_ADDRESS(UPI,0x98000024UL)
#define FREG_UPI_WMMASKX                         FIO_ADDRESS(UPI,0x98000028UL)
#define FREG_UPI_BUFENX                          FIO_ADDRESS(UPI,0x9800002CUL)
#define FREG_UPI_ATADB                           FIO_ADDRESS(UPI,0x9800103CUL)

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
extern volatile uint32_t FREG_UPI_WaittimeMirror;
extern volatile uint32_t FREG_UPI_WaittimeenMirror;

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Addrext".
**
** This function writes the given value to the register "Addrext".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAddrext( uint32_t value );
#else
INLINE void FREG_UPI_SetAddrext( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ADDREXT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ADDREXT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Addrext".
**
** This function reads the value from the register "Addrext".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAddrext( void );
#else
INLINE uint32_t FREG_UPI_GetAddrext( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ADDREXT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Cssel".
**
** This function writes the given value to the register "Cssel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetCssel( uint32_t value );
#else
INLINE void FREG_UPI_SetCssel( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CsSel" of register "Cssel".
**
**  - '00': UPI_DEV0      -->  UPI_CS_N(0)
** UPI_DEV1      -->  UPI_CS_N(1)
** ATA_CS         -->  UPI_CS_N(2)
** 
** - '01':  UPI_DEV0/1  -->  UPI_CS_N(0)
** UPI_DEV2     -->  UPI_CS_N(1)
** ATA_CS        -->  UPI_CS_N(2)
** 
** - '10': UPI_DEV0/1/2 -->  UPI_CS_N(0)
** ATA_CS1        -->  UPI_CS_N(1)
** ATA_CS0        -->  UPI_CS_N(2)
** 
** - '11': UPI_DEV0       -->  UPI_CS_N(0)
** UPI_DEV1       -->  UPI_CS_N(1)
** UPI_DEV2       -->  UPI_CS_N(2)
** Note: ATA_CS corresponds to the hardware-wired: ATA_CS0 AND ATA_CS1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CsSel" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_UPI_SetCssel_CsSel( uint32_t value );
#else
INLINE void FREG_UPI_SetCssel_CsSel( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSSEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSSEL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSSEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Cssel".
**
** This function reads the value from the register "Cssel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCssel( void );
#else
INLINE uint32_t FREG_UPI_GetCssel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSSEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CsSel" of register "Cssel".
**
**  - '00': UPI_DEV0      -->  UPI_CS_N(0)
** UPI_DEV1      -->  UPI_CS_N(1)
** ATA_CS         -->  UPI_CS_N(2)
** 
** - '01':  UPI_DEV0/1  -->  UPI_CS_N(0)
** UPI_DEV2     -->  UPI_CS_N(1)
** ATA_CS        -->  UPI_CS_N(2)
** 
** - '10': UPI_DEV0/1/2 -->  UPI_CS_N(0)
** ATA_CS1        -->  UPI_CS_N(1)
** ATA_CS0        -->  UPI_CS_N(2)
** 
** - '11': UPI_DEV0       -->  UPI_CS_N(0)
** UPI_DEV1       -->  UPI_CS_N(1)
** UPI_DEV2       -->  UPI_CS_N(2)
** Note: ATA_CS corresponds to the hardware-wired: ATA_CS0 AND ATA_CS1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CsSel" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCssel_CsSel( void );
#else
INLINE uint32_t FREG_UPI_GetCssel_CsSel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSSEL));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Csmode".
**
** This function writes the given value to the register "Csmode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetCsmode( uint32_t value );
#else
INLINE void FREG_UPI_SetCsmode( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs2Wemode" of register "Csmode".
**
** - '0': UPI_DEV2 chip select in standard mode
** - '1': UPI_DEV2 chip select follows UPI_WE_N signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs2Wemode" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_UPI_SetCsmode_Cs2Wemode( uint32_t value );
#else
INLINE void FREG_UPI_SetCsmode_Cs2Wemode( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs1Wemode" of register "Csmode".
**
** - '0': UPI_DEV1 chip select in standard mode
** - '1': UPI_DEV1 chip select follows UPI_WE_N signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs1Wemode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_UPI_SetCsmode_Cs1Wemode( uint32_t value );
#else
INLINE void FREG_UPI_SetCsmode_Cs1Wemode( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs2Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV2 chip select
** - '1': Invert UPI_DEV2 chip select when CS2_WEMODE='1'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs2Invert" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_UPI_SetCsmode_Cs2Invert( uint32_t value );
#else
INLINE void FREG_UPI_SetCsmode_Cs2Invert( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cs1Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV1 chip select
** - '1': Invert UPI_DEV1 chip select when CS1_WEMODE='1'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cs1Invert" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_UPI_SetCsmode_Cs1Invert( uint32_t value );
#else
INLINE void FREG_UPI_SetCsmode_Cs1Invert( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_CSMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_CSMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_CSMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Csmode".
**
** This function reads the value from the register "Csmode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCsmode( void );
#else
INLINE uint32_t FREG_UPI_GetCsmode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cs2Wemode" of register "Csmode".
**
** - '0': UPI_DEV2 chip select in standard mode
** - '1': UPI_DEV2 chip select follows UPI_WE_N signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs2Wemode" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCsmode_Cs2Wemode( void );
#else
INLINE uint32_t FREG_UPI_GetCsmode_Cs2Wemode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cs1Wemode" of register "Csmode".
**
** - '0': UPI_DEV1 chip select in standard mode
** - '1': UPI_DEV1 chip select follows UPI_WE_N signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs1Wemode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCsmode_Cs1Wemode( void );
#else
INLINE uint32_t FREG_UPI_GetCsmode_Cs1Wemode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cs2Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV2 chip select
** - '1': Invert UPI_DEV2 chip select when CS2_WEMODE='1'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs2Invert" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCsmode_Cs2Invert( void );
#else
INLINE uint32_t FREG_UPI_GetCsmode_Cs2Invert( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cs1Invert" of register "Csmode".
**
** - '0': Do not invert UPI_DEV1 chip select
** - '1': Invert UPI_DEV1 chip select when CS1_WEMODE='1'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cs1Invert" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetCsmode_Cs1Invert( void );
#else
INLINE uint32_t FREG_UPI_GetCsmode_Cs1Invert( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_CSMODE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Waittime".
**
** This function writes the given value to the register "Waittime".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetWaittime( uint32_t value );
#else
INLINE void FREG_UPI_SetWaittime( uint32_t value )
{
    FREG_UPI_WaittimeMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIME, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIME)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WaitTime" of register "Waittime".
**
** Wait Timer, in multiple of 1024 162MHz cycles
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WaitTime" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetWaittime_WaitTime( uint32_t value );
#else
INLINE void FREG_UPI_SetWaittime_WaitTime( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_UPI_WaittimeMirror & ~mask;
    FREG_UPI_WaittimeMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIME, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIME)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Waittime".
**
** This function reads the value from the register "Waittime".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetmWaittime( void );
#else
INLINE uint32_t FREG_UPI_GetmWaittime( void )
{
    register uint32_t value = FREG_UPI_WaittimeMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitTime" of register "Waittime".
**
** Wait Timer, in multiple of 1024 162MHz cycles
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitTime" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetmWaittime_WaitTime( void );
#else
INLINE uint32_t FREG_UPI_GetmWaittime_WaitTime( void )
{
    register uint32_t value = FREG_UPI_WaittimeMirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Waittimeen".
**
** This function writes the given value to the register "Waittimeen".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetWaittimeen( uint32_t value );
#else
INLINE void FREG_UPI_SetWaittimeen( uint32_t value )
{
    FREG_UPI_WaittimeenMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIMEEN, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIMEEN)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WaitTimeEn" of register "Waittimeen".
**
** Enables Wait Timer
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WaitTimeEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_UPI_SetWaittimeen_WaitTimeEn( uint32_t value );
#else
INLINE void FREG_UPI_SetWaittimeen_WaitTimeEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_UPI_WaittimeenMirror & ~mask;
    FREG_UPI_WaittimeenMirror = value;
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WAITTIMEEN, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WAITTIMEEN)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Waittimeen".
**
** This function reads the value from the register "Waittimeen".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetmWaittimeen( void );
#else
INLINE uint32_t FREG_UPI_GetmWaittimeen( void )
{
    register uint32_t value = FREG_UPI_WaittimeenMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitTimeEn" of register "Waittimeen".
**
** Enables Wait Timer
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitTimeEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetmWaittimeen_WaitTimeEn( void );
#else
INLINE uint32_t FREG_UPI_GetmWaittimeen_WaitTimeEn( void )
{
    register uint32_t value = FREG_UPI_WaittimeenMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Lastwaittime".
**
** This function reads the value from the register "Lastwaittime".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetLastwaittime( void );
#else
INLINE uint32_t FREG_UPI_GetLastwaittime( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_LASTWAITTIME));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LastWaitTime" of register "Lastwaittime".
**
** Last Wait Time, in multiple of 1024 162MHz cycles
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LastWaitTime" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetLastwaittime_LastWaitTime( void );
#else
INLINE uint32_t FREG_UPI_GetLastwaittime_LastWaitTime( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_LASTWAITTIME));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Waittimestatus".
**
** This function reads the value from the register "Waittimestatus".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetWaittimestatus( void );
#else
INLINE uint32_t FREG_UPI_GetWaittimestatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_WAITTIMESTATUS));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitLineStatus" of register "Waittimestatus".
**
** Wait Line Status
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitLineStatus" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetWaittimestatus_WaitLineStatus( void );
#else
INLINE uint32_t FREG_UPI_GetWaittimestatus_WaitLineStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_WAITTIMESTATUS));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WaitTimeAct" of register "Waittimestatus".
**
** Wait Timer activated
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WaitTimeAct" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetWaittimestatus_WaitTimeAct( void );
#else
INLINE uint32_t FREG_UPI_GetWaittimestatus_WaitTimeAct( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_WAITTIMESTATUS));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atactrl".
**
** This function writes the given value to the register "Atactrl".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Timeoutcnt" of register "Atactrl".
**
** Timeout counter setting
** - '0'  : timeout counter disabled
** - '>0': timeout counter enabled
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Timeoutcnt" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Timeoutcnt( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Timeoutcnt( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmaba" of register "Atactrl".
**
** Multiword DMA buffer access (FIFO access)
** - '0': External DMA engine controls buffer access
** - '1': Buffer access via register DTxDB, DRxDB enabled
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmaba" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Dmaba( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Dmaba( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmaen" of register "Atactrl".
**
** Multiword DMA enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmaen" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Dmaen( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Dmaen( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmadir" of register "Atactrl".
**
** Multiword DMA direction
** - '1': write to HD
** - '0': read from HD
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmadir" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Dmadir( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Dmadir( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Belec1" of register "Atactrl".
**
** Big Endian Little Endian conversion device 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Belec1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Belec1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Belec1( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Belec0" of register "Atactrl".
**
** Big Endian Little Endian conversion device 0
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Belec0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Belec0( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Belec0( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ideen" of register "Atactrl".
**
** IDE Enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ideen" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Ideen( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Ideen( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fte1" of register "Atactrl".
**
** Fast Timing device1 enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fte1" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Fte1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Fte1( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fte0" of register "Atactrl".
**
** Fast Timing device0 enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fte0" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Fte0( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Fte0( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pwpp" of register "Atactrl".
**
** PIO write Ping-Pong enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pwpp" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_Pwpp( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_Pwpp( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IordyenFt1" of register "Atactrl".
**
** Fast Timing device1 IORDY enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IordyenFt1" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_IordyenFt1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_IordyenFt1( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IordyenFt0" of register "Atactrl".
**
** Fast Timing device0 IORDY enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IordyenFt0" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_IordyenFt0( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_IordyenFt0( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IordyenCt" of register "Atactrl".
**
** Compatible timing IORDY enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IordyenCt" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_IordyenCt( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_IordyenCt( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AtaBufEn" of register "Atactrl".
**
** Activates BUF_EN in ATA Mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AtaBufEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtactrl_AtaBufEn( uint32_t value );
#else
INLINE void FREG_UPI_SetAtactrl_AtaBufEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 14
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATACTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATACTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATACTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atactrl".
**
** This function reads the value from the register "Atactrl".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Timeoutcnt" of register "Atactrl".
**
** Timeout counter setting
** - '0'  : timeout counter disabled
** - '>0': timeout counter enabled
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Timeoutcnt" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Timeoutcnt( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Timeoutcnt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmaba" of register "Atactrl".
**
** Multiword DMA buffer access (FIFO access)
** - '0': External DMA engine controls buffer access
** - '1': Buffer access via register DTxDB, DRxDB enabled
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmaba" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Dmaba( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Dmaba( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmaen" of register "Atactrl".
**
** Multiword DMA enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmaen" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Dmaen( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Dmaen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmadir" of register "Atactrl".
**
** Multiword DMA direction
** - '1': write to HD
** - '0': read from HD
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmadir" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Dmadir( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Dmadir( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Belec1" of register "Atactrl".
**
** Big Endian Little Endian conversion device 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Belec1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Belec1( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Belec1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Belec0" of register "Atactrl".
**
** Big Endian Little Endian conversion device 0
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Belec0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Belec0( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Belec0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ideen" of register "Atactrl".
**
** IDE Enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ideen" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Ideen( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Ideen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fte1" of register "Atactrl".
**
** Fast Timing device1 enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fte1" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Fte1( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Fte1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fte0" of register "Atactrl".
**
** Fast Timing device0 enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fte0" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Fte0( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Fte0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pwpp" of register "Atactrl".
**
** PIO write Ping-Pong enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pwpp" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_Pwpp( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_Pwpp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IordyenFt1" of register "Atactrl".
**
** Fast Timing device1 IORDY enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IordyenFt1" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_IordyenFt1( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_IordyenFt1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IordyenFt0" of register "Atactrl".
**
** Fast Timing device0 IORDY enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IordyenFt0" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_IordyenFt0( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_IordyenFt0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IordyenCt" of register "Atactrl".
**
** Compatible timing IORDY enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IordyenCt" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_IordyenCt( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_IordyenCt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AtaBufEn" of register "Atactrl".
**
** Activates BUF_EN in ATA Mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AtaBufEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtactrl_AtaBufEn( void );
#else
INLINE uint32_t FREG_UPI_GetAtactrl_AtaBufEn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATACTRL));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atastat".
**
** This function writes the given value to the register "Atastat".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmafifof" of register "Atastat".
**
** DMA fifo free lines
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmafifof" consists of the bits 23..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00F00000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Dmafifof( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Dmafifof( uint32_t value )
{
    register uint32_t mask = 0x00F00000UL;
    value = ( value << 20 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmafifou" of register "Atastat".
**
** DMA fifo used lines
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmafifou" consists of the bits 19..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x000F0000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Dmafifou( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Dmafifou( uint32_t value )
{
    register uint32_t mask = 0x000F0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmatip" of register "Atastat".
**
** DMA transfer in progress
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmatip" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Dmatip( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Dmatip( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmabe" of register "Atastat".
**
** DMA buffer empty
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmabe" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Dmabe( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Dmabe( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmabf" of register "Atastat".
**
** DMA buffer full
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmabf" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Dmabf( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Dmabf( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dmarq" of register "Atastat".
**
** DMARQ line status
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dmarq" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Dmarq( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Dmarq( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Piotip" of register "Atastat".
**
** Programmed IO transfer in progress
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Piotip" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Piotip( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Piotip( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pwppf" of register "Atastat".
**
** PIO write Ping-Pong full
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pwppf" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Pwppf( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Pwppf( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Timeout" of register "Atastat".
**
** Timeout flag, cleared by writing '0'
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Timeout" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtastat_Timeout( uint32_t value );
#else
INLINE void FREG_UPI_SetAtastat_Timeout( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATASTAT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATASTAT, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATASTAT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atastat".
**
** This function reads the value from the register "Atastat".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmafifof" of register "Atastat".
**
** DMA fifo free lines
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmafifof" consists of the bits 23..20,
**       the given bitgroup value will be shifted left by 20 bits and
**       masked using the bitmask 0x00F00000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Dmafifof( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Dmafifof( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00F00000UL ) >> 20;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmafifou" of register "Atastat".
**
** DMA fifo used lines
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmafifou" consists of the bits 19..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x000F0000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Dmafifou( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Dmafifou( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x000F0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmatip" of register "Atastat".
**
** DMA transfer in progress
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmatip" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Dmatip( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Dmatip( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmabe" of register "Atastat".
**
** DMA buffer empty
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmabe" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Dmabe( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Dmabe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmabf" of register "Atastat".
**
** DMA buffer full
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmabf" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Dmabf( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Dmabf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dmarq" of register "Atastat".
**
** DMARQ line status
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dmarq" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Dmarq( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Dmarq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Piotip" of register "Atastat".
**
** Programmed IO transfer in progress
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Piotip" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Piotip( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Piotip( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pwppf" of register "Atastat".
**
** PIO write Ping-Pong full
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pwppf" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Pwppf( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Pwppf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Timeout" of register "Atastat".
**
** Timeout flag, cleared by writing '0'
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Timeout" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtastat_Timeout( void );
#else
INLINE uint32_t FREG_UPI_GetAtastat_Timeout( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATASTAT));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atapctr".
**
** This function writes the given value to the register "Atapctr".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapctr( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapctr( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atapctr".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapctr_Teoc( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapctr_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T4" of register "Atapctr".
**
** DIOW-data hold
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapctr_T4( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapctr_T4( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T2" of register "Atapctr".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapctr_T2( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapctr_T2( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T1" of register "Atapctr".
**
** Address valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapctr_T1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapctr_T1( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPCTR, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPCTR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atapctr".
**
** This function reads the value from the register "Atapctr".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapctr( void );
#else
INLINE uint32_t FREG_UPI_GetAtapctr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atapctr".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapctr_Teoc( void );
#else
INLINE uint32_t FREG_UPI_GetAtapctr_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T4" of register "Atapctr".
**
** DIOW-data hold
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapctr_T4( void );
#else
INLINE uint32_t FREG_UPI_GetAtapctr_T4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T2" of register "Atapctr".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapctr_T2( void );
#else
INLINE uint32_t FREG_UPI_GetAtapctr_T2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T1" of register "Atapctr".
**
** Address valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapctr_T1( void );
#else
INLINE uint32_t FREG_UPI_GetAtapctr_T1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPCTR));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atapftr0".
**
** This function writes the given value to the register "Atapftr0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr0( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr0( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atapftr0".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr0_Teoc( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr0_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T4" of register "Atapftr0".
**
** DIOW-data hold
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr0_T4( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr0_T4( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T2" of register "Atapftr0".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr0_T2( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr0_T2( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T1" of register "Atapftr0".
**
** Address valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr0_T1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr0_T1( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atapftr0".
**
** This function reads the value from the register "Atapftr0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr0( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atapftr0".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr0_Teoc( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr0_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T4" of register "Atapftr0".
**
** DIOW-data hold
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr0_T4( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr0_T4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T2" of register "Atapftr0".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr0_T2( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr0_T2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T1" of register "Atapftr0".
**
** Address valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr0_T1( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr0_T1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR0));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atapftr1".
**
** This function writes the given value to the register "Atapftr1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr1( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atapftr1".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr1_Teoc( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr1_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T4" of register "Atapftr1".
**
** DIOW-data hold
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr1_T4( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr1_T4( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T2" of register "Atapftr1".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr1_T2( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr1_T2( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "T1" of register "Atapftr1".
**
** Address valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtapftr1_T1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtapftr1_T1( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATAPFTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATAPFTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atapftr1".
**
** This function reads the value from the register "Atapftr1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr1( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atapftr1".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr1_Teoc( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr1_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T4" of register "Atapftr1".
**
** DIOW-data hold
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T4" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr1_T4( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr1_T4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T2" of register "Atapftr1".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T2" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr1_T2( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr1_T2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "T1" of register "Atapftr1".
**
** Address valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "T1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtapftr1_T1( void );
#else
INLINE uint32_t FREG_UPI_GetAtapftr1_T1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATAPFTR1));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atadtr0".
**
** This function writes the given value to the register "Atadtr0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr0( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr0( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atadtr0".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr0_Teoc( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr0_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Td" of register "Atadtr0".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr0_Td( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr0_Td( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Tm" of register "Atadtr0".
**
** CS(1:0) valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr0_Tm( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr0_Tm( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR0, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atadtr0".
**
** This function reads the value from the register "Atadtr0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr0( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atadtr0".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr0_Teoc( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr0_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Td" of register "Atadtr0".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr0_Td( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr0_Td( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Tm" of register "Atadtr0".
**
** CS(1:0) valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr0_Tm( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr0_Tm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR0));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atadtr1".
**
** This function writes the given value to the register "Atadtr1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr1( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Teoc" of register "Atadtr1".
**
** End of Cycle Time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr1_Teoc( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr1_Teoc( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Td" of register "Atadtr1".
**
** DIOR-/DIOW-pulse width
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr1_Td( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr1_Td( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Tm" of register "Atadtr1".
**
** CS(1:0) valid to DIOR/DIOW
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadtr1_Tm( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadtr1_Tm( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADTR1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADTR1, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADTR1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atadtr1".
**
** This function reads the value from the register "Atadtr1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr1( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Teoc" of register "Atadtr1".
**
** End of Cycle Time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Teoc" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr1_Teoc( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr1_Teoc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Td" of register "Atadtr1".
**
** DIOR-/DIOW-pulse width
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Td" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr1_Td( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr1_Td( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Tm" of register "Atadtr1".
**
** CS(1:0) valid to DIOR/DIOW
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Tm" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadtr1_Tm( void );
#else
INLINE uint32_t FREG_UPI_GetAtadtr1_Tm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADTR1));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "ModeX".
**
** This function writes the given value to the index-th entry of the register
** array ModeX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetModeX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetModeX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_MODEX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiMode" of register "ModeX".
**
** Device Mode Selection
** 
** 0x0: Device is inactive
** 0x1: SRAM modes
** 0x2: IDE mode
** 0x3: NAND-Flash mode
** 0x4: CI Common Memory mode
** 0x5: CI Attribute Memory mode
** 0x6: CI I/O mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiMode" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern void FREG_UPI_SetModeX_UpiMode( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetModeX_UpiMode( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_MODEX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "ModeX".
**
** This function reads the value from the index-th entry of the register
** array ModeX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetModeX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetModeX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiMode" of register "ModeX".
**
** Device Mode Selection
** 
** 0x0: Device is inactive
** 0x1: SRAM modes
** 0x2: IDE mode
** 0x3: NAND-Flash mode
** 0x4: CI Common Memory mode
** 0x5: CI Attribute Memory mode
** 0x6: CI I/O mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiMode" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetModeX_UpiMode( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetModeX_UpiMode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_MODEX+(index*0x40)));
    value = ( value & 0x00000007UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TalsX".
**
** This function writes the given value to the index-th entry of the register
** array TalsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTalsX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTalsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTals" of register "TalsX".
**
** Address Latch Setup Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTals" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTalsX_UpiTals( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTalsX_UpiTals( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TalsX".
**
** This function reads the value from the index-th entry of the register
** array TalsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTalsX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTalsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTals" of register "TalsX".
**
** Address Latch Setup Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTals" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTalsX_UpiTals( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTalsX_UpiTals( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALSX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TalhX".
**
** This function writes the given value to the index-th entry of the register
** array TalhX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTalhX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTalhX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTalh" of register "TalhX".
**
** Address Latch Hold Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTalh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTalhX_UpiTalh( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTalhX_UpiTalh( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TALHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TalhX".
**
** This function reads the value from the index-th entry of the register
** array TalhX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTalhX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTalhX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTalh" of register "TalhX".
**
** Address Latch Hold Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTalh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTalhX_UpiTalh( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTalhX_UpiTalh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TALHX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TrsX".
**
** This function writes the given value to the index-th entry of the register
** array TrsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTrsX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrs" of register "TrsX".
**
** Read Address Setup Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrs" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTrsX_UpiTrs( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrsX_UpiTrs( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrsX".
**
** This function reads the value from the index-th entry of the register
** array TrsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrsX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrs" of register "TrsX".
**
** Read Address Setup Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrs" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrsX_UpiTrs( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrsX_UpiTrs( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRSX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TrdsX".
**
** This function writes the given value to the index-th entry of the register
** array TrdsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTrdsX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrdsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrds" of register "TrdsX".
**
** Read Data Setup/Strobe Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTrdsX_UpiTrds( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrdsX_UpiTrds( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrdsX".
**
** This function reads the value from the index-th entry of the register
** array TrdsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrdsX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrdsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrds" of register "TrdsX".
**
** Read Data Setup/Strobe Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrdsX_UpiTrds( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrdsX_UpiTrds( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDSX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TrdhX".
**
** This function writes the given value to the index-th entry of the register
** array TrdhX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTrdhX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrdhX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrdh" of register "TrdhX".
**
** Read Data Hold Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrdh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTrdhX_UpiTrdh( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrdhX_UpiTrdh( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRDHX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrdhX".
**
** This function reads the value from the index-th entry of the register
** array TrdhX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrdhX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrdhX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrdh" of register "TrdhX".
**
** Read Data Hold Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrdh" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrdhX_UpiTrdh( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrdhX_UpiTrdh( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRDHX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TrrX".
**
** This function writes the given value to the index-th entry of the register
** array TrrX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTrrX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrrX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTrr" of register "TrrX".
**
** Read Recovery Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTrr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTrrX_UpiTrr( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTrrX_UpiTrr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TRRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TrrX".
**
** This function reads the value from the index-th entry of the register
** array TrrX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrrX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrrX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTrr" of register "TrrX".
**
** Read Recovery Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTrr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTrrX_UpiTrr( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTrrX_UpiTrr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TRRX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TwsX".
**
** This function writes the given value to the index-th entry of the register
** array TwsX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTwsX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTwsX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTws" of register "TwsX".
**
** Write Address Setup Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTws" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTwsX_UpiTws( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTwsX_UpiTws( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWSX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TwsX".
**
** This function reads the value from the index-th entry of the register
** array TwsX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTwsX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTwsX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTws" of register "TwsX".
**
** Write Address Setup Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTws" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTwsX_UpiTws( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTwsX_UpiTws( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWSX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TwpX".
**
** This function writes the given value to the index-th entry of the register
** array TwpX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTwpX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTwpX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWPX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTwp" of register "TwpX".
**
** Write Pulse Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTwp" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTwpX_UpiTwp( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTwpX_UpiTwp( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWPX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TwpX".
**
** This function reads the value from the index-th entry of the register
** array TwpX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTwpX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTwpX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTwp" of register "TwpX".
**
** Write Pulse Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTwp" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTwpX_UpiTwp( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTwpX_UpiTwp( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWPX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "TwrX".
**
** This function writes the given value to the index-th entry of the register
** array TwrX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetTwrX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTwrX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiTwr" of register "TwrX".
**
** Write Recovery Time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiTwr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetTwrX_UpiTwr( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetTwrX_UpiTwr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_TWRX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "TwrX".
**
** This function reads the value from the index-th entry of the register
** array TwrX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTwrX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTwrX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiTwr" of register "TwrX".
**
** Write Recovery Time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiTwr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetTwrX_UpiTwr( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetTwrX_UpiTwr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_TWRX+(index*0x40)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "WmmaskX".
**
** This function writes the given value to the index-th entry of the register
** array WmmaskX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetWmmaskX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetWmmaskX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WMMASKX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiWmmask" of register "WmmaskX".
**
** Wait Mask Bit (0: wait inactive, 1: wait active)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiWmmask" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_UPI_SetWmmaskX_UpiWmmask( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetWmmaskX_UpiWmmask( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_WMMASKX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "WmmaskX".
**
** This function reads the value from the index-th entry of the register
** array WmmaskX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetWmmaskX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetWmmaskX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiWmmask" of register "WmmaskX".
**
** Wait Mask Bit (0: wait inactive, 1: wait active)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiWmmask" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetWmmaskX_UpiWmmask( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetWmmaskX_UpiWmmask( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_WMMASKX+(index*0x40)));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BufenX".
**
** This function writes the given value to the index-th entry of the register
** array BufenX.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetBufenX( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetBufenX( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_BUFENX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UpiBufen" of register "BufenX".
**
** External Buffer Enable (0: no external buffer, 1: external buffer)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UpiBufen" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_UPI_SetBufenX_UpiBufen( uint32_t index, uint32_t value );
#else
INLINE void FREG_UPI_SetBufenX_UpiBufen( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_BUFENX+(index*0x40), value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BufenX".
**
** This function reads the value from the index-th entry of the register
** array BufenX.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetBufenX( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetBufenX( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "UpiBufen" of register "BufenX".
**
** External Buffer Enable (0: no external buffer, 1: external buffer)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UpiBufen" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetBufenX_UpiBufen( uint32_t index );
#else
INLINE uint32_t FREG_UPI_GetBufenX_UpiBufen( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 3 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_UPI_BUFENX+(index*0x40)));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Atadb".
**
** This function writes the given value to the register "Atadb".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadb( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadb( uint32_t value )
{
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData3" of register "Atadb".
**
** Transmit / Receive Data 1[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 2[7:0] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData3" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadb_DmaData3( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadb_DmaData3( uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    value = ( value << 24 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData2" of register "Atadb".
**
** Transmit / Receive Data 1[7:0] (with BeLeC = '0') /
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData2" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadb_DmaData2( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadb_DmaData2( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData1" of register "Atadb".
**
** Transmit / Receive Data 2[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 1 [7:0] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData1" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadb_DmaData1( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadb_DmaData1( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DmaData0" of register "Atadb".
**
** Transmit / Receive Data 2[7:0] (with BeLeC = '0')/
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DmaData0" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_UPI_SetAtadb_DmaData0( uint32_t value );
#else
INLINE void FREG_UPI_SetAtadb_DmaData0( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_UPI_ATADB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_UPI_ENABLE_DEBUG_PRINT == 1
        FREG_UPI_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_UPI", FREG_UPI_ATADB, value );
    #endif
    *((volatile uint32_t*)(FREG_UPI_ATADB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Atadb".
**
** This function reads the value from the register "Atadb".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadb( void );
#else
INLINE uint32_t FREG_UPI_GetAtadb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DmaData3" of register "Atadb".
**
** Transmit / Receive Data 1[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 2[7:0] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData3" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadb_DmaData3( void );
#else
INLINE uint32_t FREG_UPI_GetAtadb_DmaData3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DmaData2" of register "Atadb".
**
** Transmit / Receive Data 1[7:0] (with BeLeC = '0') /
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData2" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadb_DmaData2( void );
#else
INLINE uint32_t FREG_UPI_GetAtadb_DmaData2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DmaData1" of register "Atadb".
**
** Transmit / Receive Data 2[15:8] (with BeLeC = '0') /
** Transmit / Receive Data 1 [7:0] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData1" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadb_DmaData1( void );
#else
INLINE uint32_t FREG_UPI_GetAtadb_DmaData1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "DmaData0" of register "Atadb".
**
** Transmit / Receive Data 2[7:0] (with BeLeC = '0')/
** Transmit / Receive Data 2[15:8] (with BeLeC = '1')
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DmaData0" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_UPI_GetAtadb_DmaData0( void );
#else
INLINE uint32_t FREG_UPI_GetAtadb_DmaData0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_UPI_ATADB));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

/*!
********************************************************************************
**
** \brief Initializes the "UPI" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
extern void FREG_UPI_Init( void );

#endif


#if 0

#ifndef REG_UPI_H_
#define REG_UPI_H_


extern void FREG_UPI_Init(void);
extern void FREG_UPI_SetCssel(int);
extern int FREG_UPI_GetCssel(void);
extern void FREG_UPI_SetWaittime_WaitTime(int);
extern int FREG_UPI_GetmWaittime_WaitTime(void);
extern void FREG_UPI_SetWaittimeen_WaitTimeEn(int);
extern int FREG_UPI_GetLastwaittime_LastWaitTime(void);
extern int FREG_UPI_GetWaittimestatus_WaitTimeAct(void);
extern void func_21c74e74(int);
extern void func_21c74e84(int);
extern void func_21c74ea8(int);
extern void func_21c74ecc(int);
extern void func_21c74ef0(int);
extern void func_21c74f14(int);
extern void func_21c74f38(int);
extern void func_21c74f5c(int);
extern void func_21c74f80(int);
extern void func_21c74fa4(int);
extern void func_21c74fc8(int);
extern void func_21c74fec(int);
extern void func_21c75010(int);
extern int func_21c75030(void);
extern int func_21c75048(void);
extern int func_21c75058(void);
extern void func_21c75070(int);
extern void func_21c75080(int);
extern void func_21c7509c(int);
extern void func_21c750c0(int);
extern void func_21c750e4(int);
extern void func_21c75104(int);
extern void func_21c75120(int);
extern void func_21c75144(int);
extern void func_21c75168(int);
extern void func_21c75188(int);
extern void func_21c751a4(int);
extern void func_21c751c8(int);
extern void func_21c751ec(int);
extern void func_21c7520c(int);
extern void func_21c75228(int);
extern void func_21c7524c(int);
extern void func_21c7526c(int);
extern void func_21c75288(int);
extern void func_21c752ac(int);
extern void FREG_UPI_SetModeX_UpiMode(int, unsigned);
extern int FREG_UPI_GetModeX_UpiMode(int);
extern void FREG_UPI_SetTalsX_UpiTals(int, int);
extern int FREG_UPI_GetTalsX_UpiTals(int);
extern void FREG_UPI_SetTalhX_UpiTalh(int, int);
extern int FREG_UPI_GetTalhX_UpiTalh(int);
extern void FREG_UPI_SetTrsX_UpiTrs(int, int);
extern int FREG_UPI_GetTrsX_UpiTrs(int);
extern void FREG_UPI_SetTrdsX_UpiTrds(int, int);
extern int FREG_UPI_GetTrdsX_UpiTrds(int);
extern void FREG_UPI_SetTrdhX_UpiTrdh(int, int);
extern int FREG_UPI_GetTrdhX_UpiTrdh(int);
extern void FREG_UPI_SetTrrX_UpiTrr(int, int);
extern int FREG_UPI_GetTrrX_UpiTrr(int);
extern void FREG_UPI_SetTwsX_UpiTws(int, int);
extern int FREG_UPI_GetTwsX_UpiTws(int);
extern void FREG_UPI_SetTwpX_UpiTwp(int, int);
extern int FREG_UPI_GetTwpX_UpiTwp(int);
extern void FREG_UPI_SetTwrX_UpiTwr(int, int);
extern int FREG_UPI_GetTwrX_UpiTwr(int);
extern void FREG_UPI_SetWmmaskX_UpiWmmask(int, int);
extern int FREG_UPI_GetWmmaskX_UpiWmmask(int);
extern void FREG_UPI_SetBufenX_UpiBufen(int, int);
extern int FREG_UPI_GetBufenX_UpiBufen(int);
extern int func_21c754ac(void);



#endif /*REG_UPI_H_*/


#endif
