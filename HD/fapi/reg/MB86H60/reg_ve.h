/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_ve.h
**
** \brief     VE access functions
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
#if !defined(FREG_VE_H)
#define FREG_VE_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_VE_ENABLE_DEBUG_PRINT   0
#define FREG_VE_DEBUG_PRINT_FUNCTION printf

#if FREG_VE_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_VE_SDCCFILTERLUM0                   FIO_ADDRESS(VE,0xCB011080UL)
#define FREG_VE_SDCCFILTERLUM1                   FIO_ADDRESS(VE,0xCB011084UL)
#define FREG_VE_SDCCFILTERLUM2                   FIO_ADDRESS(VE,0xCB011088UL)
#define FREG_VE_SDCCFILTERLUM3                   FIO_ADDRESS(VE,0xCB01108CUL)
#define FREG_VE_SDCCFILTERLUM4                   FIO_ADDRESS(VE,0xCB011090UL)
#define FREG_VE_SDCCFILTERLUM5                   FIO_ADDRESS(VE,0xCB011094UL)
#define FREG_VE_SDCCFILTERLUM6                   FIO_ADDRESS(VE,0xCB011098UL)
#define FREG_VE_SDCCFILTERLUM7                   FIO_ADDRESS(VE,0xCB01109CUL)
#define FREG_VE_SDCCFILTERLUM8                   FIO_ADDRESS(VE,0xCB0110A0UL)
#define FREG_VE_SDCCFILTERLUM9                   FIO_ADDRESS(VE,0xCB0110A4UL)
#define FREG_VE_SDCCFILTERCHROM2                 FIO_ADDRESS(VE,0xCB0110C0UL)
#define FREG_VE_SDCCFILTERCHROM3                 FIO_ADDRESS(VE,0xCB0110C4UL)
#define FREG_VE_SDCCFILTERCHROM4                 FIO_ADDRESS(VE,0xCB0110C8UL)
#define FREG_VE_SDCCFILTERCHROM5                 FIO_ADDRESS(VE,0xCB0110CCUL)
#define FREG_VE_SDCCFILTERCHROM6                 FIO_ADDRESS(VE,0xCB0110D0UL)
#define FREG_VE_SDCCFILTERCHROM7                 FIO_ADDRESS(VE,0xCB0110D4UL)
#define FREG_VE_SDCCFILTERCHROM8                 FIO_ADDRESS(VE,0xCB0110D8UL)
#define FREG_VE_SDCCFILTERCHROM9                 FIO_ADDRESS(VE,0xCB0110DCUL)
#define FREG_VE_SDCCFILTERHORSTART               FIO_ADDRESS(VE,0xCB0110E0UL)
#define FREG_VE_SDCCFILTERHORSTOP                FIO_ADDRESS(VE,0xCB0110E4UL)
#define FREG_VE_SDCCFILTERVERSTART               FIO_ADDRESS(VE,0xCB0110E8UL)
#define FREG_VE_SDCCFILTERVERSTOP                FIO_ADDRESS(VE,0xCB0110ECUL)
#define FREG_VE_SDCCFILTERBLANKSTART             FIO_ADDRESS(VE,0xCB0110F0UL)
#define FREG_VE_SDCCFILTERBLANKSTOP              FIO_ADDRESS(VE,0xCB0110F4UL)
#define FREG_VE_SDCCFILTERENABLE                 FIO_ADDRESS(VE,0xCB0110F8UL)
#define FREG_VE_SDHORLINELENGTH                  FIO_ADDRESS(VE,0xCB011000UL)
#define FREG_VE_SDVERSIZE                        FIO_ADDRESS(VE,0xCB011004UL)
#define FREG_VE_SDBACKGROUND                     FIO_ADDRESS(VE,0xCB01101CUL)
#define FREG_VE_SDVOHORSTART                     FIO_ADDRESS(VE,0xCB011040UL)
#define FREG_VE_SDVOHORSTOP                      FIO_ADDRESS(VE,0xCB011044UL)
#define FREG_VE_SDVOVERSTART                     FIO_ADDRESS(VE,0xCB011048UL)
#define FREG_VE_SDVOVERSTOP                      FIO_ADDRESS(VE,0xCB01104CUL)
#define FREG_VE_SDTTXHORSTART                    FIO_ADDRESS(VE,0xCB011050UL)
#define FREG_VE_SDHVSYNCCFG                      FIO_ADDRESS(VE,0xCB011140UL)
#define FREG_VE_SDVSYNCOFFSET                    FIO_ADDRESS(VE,0xCB01114CUL)
#define FREG_VE_SDVSYNCEVSTART                   FIO_ADDRESS(VE,0xCB011100UL)
#define FREG_VE_SDVSYNCOVSTART                   FIO_ADDRESS(VE,0xCB011104UL)
#define FREG_VE_SDVSYNCEVSTOP                    FIO_ADDRESS(VE,0xCB011108UL)
#define FREG_VE_SDVSYNCOVSTOP                    FIO_ADDRESS(VE,0xCB01110CUL)
#define FREG_VE_SDVSYNCEHSTART                   FIO_ADDRESS(VE,0xCB011110UL)
#define FREG_VE_SDVSYNCOHSTART                   FIO_ADDRESS(VE,0xCB011114UL)
#define FREG_VE_SDVSYNCEHSTOP                    FIO_ADDRESS(VE,0xCB011118UL)
#define FREG_VE_SDVSYNCOHSTOP                    FIO_ADDRESS(VE,0xCB01111CUL)
#define FREG_VE_SDHSYNCSTART                     FIO_ADDRESS(VE,0xCB011120UL)
#define FREG_VE_SDHSYNCSTOP                      FIO_ADDRESS(VE,0xCB011124UL)
#define FREG_VE_SDHSYNCOFFSET                    FIO_ADDRESS(VE,0xCB011144UL)
#define FREG_VE_VOOSD1CLUT                       FIO_ADDRESS(VE,0xCB007000UL)
#define FREG_VE_VOOSD2CLUT                       FIO_ADDRESS(VE,0xCB00B000UL)
#define FREG_VE_VOCURSORCLUT                     FIO_ADDRESS(VE,0xCB020000UL)
#define FREG_VE_SDSECFIELDOFFSET                 FIO_ADDRESS(VE,0xCB011008UL)
#define FREG_VE_RGBCONF                          FIO_ADDRESS(VE,0xCB013000UL)
#define FREG_VE_RGBLUM                           FIO_ADDRESS(VE,0xCB013004UL)
#define FREG_VE_RGBCHROM                         FIO_ADDRESS(VE,0xCB013008UL)
#define FREG_VE_CECONF                           FIO_ADDRESS(VE,0xCB01300CUL)
#define FREG_VE_CEBURSTINT                       FIO_ADDRESS(VE,0xCB013010UL)
#define FREG_VE_CEBURSTFRA1                      FIO_ADDRESS(VE,0xCB013014UL)
#define FREG_VE_CEBURSTFRA2                      FIO_ADDRESS(VE,0xCB013018UL)
#define FREG_VE_DACPD                            FIO_ADDRESS(VE,0xCB013020UL)
#define FREG_VE_ENC656WSS                        FIO_ADDRESS(VE,0xCB013028UL)
#define FREG_VE_CCLINE21                         FIO_ADDRESS(VE,0xCB01302CUL)
#define FREG_VE_CCLINE284                        FIO_ADDRESS(VE,0xCB013030UL)
#define FREG_VE_VBIDWORDS                        FIO_ADDRESS(VE,0xCB013034UL)
#define FREG_VE_WSSDATA                          FIO_ADDRESS(VE,0xCB013038UL)
#define FREG_VE_LUTCONF                          FIO_ADDRESS(VE,0xCB013200UL)
#define FREG_VE_LUTY                             FIO_ADDRESS(VE,0xCB013400UL)
#define FREG_VE_LUTCR                            FIO_ADDRESS(VE,0xCB013800UL)
#define FREG_VE_LUTCB                            FIO_ADDRESS(VE,0xCB013C00UL)
#define FREG_VE_VOMIXYUVRGB                      FIO_ADDRESS(VE,0xCB010180UL)
#define FREG_VE_VOMIXRGBYUV                      FIO_ADDRESS(VE,0xCB010200UL)

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
extern volatile uint32_t FREG_VE_SdCcfilterlum0Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum1Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum2Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum3Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum4Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum5Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum6Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum7Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum8Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterlum9Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom2Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom3Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom4Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom5Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom6Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom7Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom8Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterchrom9Mirror;
extern volatile uint32_t FREG_VE_SdCcfilterhorstartMirror;
extern volatile uint32_t FREG_VE_SdCcfilterhorstopMirror;
extern volatile uint32_t FREG_VE_SdCcfilterverstartMirror;
extern volatile uint32_t FREG_VE_SdCcfilterverstopMirror;
extern volatile uint32_t FREG_VE_SdCcfilterblankstartMirror;
extern volatile uint32_t FREG_VE_SdCcfilterblankstopMirror;
extern volatile uint32_t FREG_VE_SdCcfilterenableMirror;
extern volatile uint32_t FREG_VE_SdHorlinelengthMirror;
extern volatile uint32_t FREG_VE_SdVersizeMirror;
extern volatile uint32_t FREG_VE_SdBackgroundMirror;
extern volatile uint32_t FREG_VE_SdVohorstartMirror;
extern volatile uint32_t FREG_VE_SdVohorstopMirror;
extern volatile uint32_t FREG_VE_SdVoverstartMirror;
extern volatile uint32_t FREG_VE_SdVoverstopMirror;
extern volatile uint32_t FREG_VE_SdTtxhorstartMirror;
extern volatile uint32_t FREG_VE_SdhvsynccfgMirror;
extern volatile uint32_t FREG_VE_SdvsyncoffsetMirror;
extern volatile uint32_t FREG_VE_SdvsyncevstartMirror;
extern volatile uint32_t FREG_VE_SdvsyncovstartMirror;
extern volatile uint32_t FREG_VE_SdvsyncevstopMirror;
extern volatile uint32_t FREG_VE_SdvsyncovstopMirror;
extern volatile uint32_t FREG_VE_SdvsyncehstartMirror;
extern volatile uint32_t FREG_VE_SdvsyncohstartMirror;
extern volatile uint32_t FREG_VE_SdvsyncehstopMirror;
extern volatile uint32_t FREG_VE_SdvsyncohstopMirror;
extern volatile uint32_t FREG_VE_SdhsyncstartMirror;
extern volatile uint32_t FREG_VE_SdhsyncstopMirror;
extern volatile uint32_t FREG_VE_SdhsyncoffsetMirror;
extern volatile uint32_t FREG_VE_VoOsd1clutMirror[256];
extern volatile uint32_t FREG_VE_VoOsd2clutMirror[256];
extern volatile uint32_t FREG_VE_VoCursorclutMirror[256];
extern volatile uint32_t FREG_VE_SdSecfieldoffsetMirror;
extern volatile uint32_t FREG_VE_RgbconfMirror;
extern volatile uint32_t FREG_VE_RgblumMirror;
extern volatile uint32_t FREG_VE_RgbchromMirror;
extern volatile uint32_t FREG_VE_CeconfMirror;
extern volatile uint32_t FREG_VE_CeburstintMirror;
extern volatile uint32_t FREG_VE_Ceburstfra1Mirror;
extern volatile uint32_t FREG_VE_Ceburstfra2Mirror;
extern volatile uint32_t FREG_VE_DacPdMirror;
extern volatile uint32_t FREG_VE_Enc656wssMirror;
extern volatile uint32_t FREG_VE_Ccline21Mirror;
extern volatile uint32_t FREG_VE_Ccline284Mirror;
extern volatile uint32_t FREG_VE_VbidwordsMirror;
extern volatile uint32_t FREG_VE_WssdataMirror;
extern volatile uint32_t FREG_VE_LutConfMirror;
extern volatile uint32_t FREG_VE_LutYMirror[256];
extern volatile uint32_t FREG_VE_LutCrMirror[256];
extern volatile uint32_t FREG_VE_LutCbMirror[256];

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum0".
**
** This function writes the given value to the register "SdCcfilterlum0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum0( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum0( uint32_t value )
{
    FREG_VE_SdCcfilterlum0Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff0" of register "SdCcfilterlum0".
**
** Y coefficient 0 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff0" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum0_YCoeff0( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum0_YCoeff0( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum0Mirror & ~mask;
    FREG_VE_SdCcfilterlum0Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM0, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum0".
**
** This function reads the value from the register "SdCcfilterlum0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum0( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum0( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum0Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff0" of register "SdCcfilterlum0".
**
** Y coefficient 0 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff0" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum0_YCoeff0( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum0_YCoeff0( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum0Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum1".
**
** This function writes the given value to the register "SdCcfilterlum1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum1( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum1( uint32_t value )
{
    FREG_VE_SdCcfilterlum1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff1" of register "SdCcfilterlum1".
**
** Y coefficient 1 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum1_YCoeff1( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum1_YCoeff1( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum1Mirror & ~mask;
    FREG_VE_SdCcfilterlum1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum1".
**
** This function reads the value from the register "SdCcfilterlum1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum1( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum1( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum1Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff1" of register "SdCcfilterlum1".
**
** Y coefficient 1 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum1_YCoeff1( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum1_YCoeff1( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum1Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum2".
**
** This function writes the given value to the register "SdCcfilterlum2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum2( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum2( uint32_t value )
{
    FREG_VE_SdCcfilterlum2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff2" of register "SdCcfilterlum2".
**
** Y coefficient 2 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff2" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum2_YCoeff2( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum2_YCoeff2( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum2Mirror & ~mask;
    FREG_VE_SdCcfilterlum2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum2".
**
** This function reads the value from the register "SdCcfilterlum2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum2( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum2Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff2" of register "SdCcfilterlum2".
**
** Y coefficient 2 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff2" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum2_YCoeff2( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum2_YCoeff2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum2Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum3".
**
** This function writes the given value to the register "SdCcfilterlum3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum3( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum3( uint32_t value )
{
    FREG_VE_SdCcfilterlum3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff3" of register "SdCcfilterlum3".
**
** Y coefficient 3 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum3_YCoeff3( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum3_YCoeff3( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum3Mirror & ~mask;
    FREG_VE_SdCcfilterlum3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum3".
**
** This function reads the value from the register "SdCcfilterlum3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum3( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum3Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff3" of register "SdCcfilterlum3".
**
** Y coefficient 3 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum3_YCoeff3( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum3_YCoeff3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum3Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum4".
**
** This function writes the given value to the register "SdCcfilterlum4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum4( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum4( uint32_t value )
{
    FREG_VE_SdCcfilterlum4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff4" of register "SdCcfilterlum4".
**
** Y coefficient 4 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff4" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum4_YCoeff4( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum4_YCoeff4( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum4Mirror & ~mask;
    FREG_VE_SdCcfilterlum4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum4".
**
** This function reads the value from the register "SdCcfilterlum4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum4( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum4Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff4" of register "SdCcfilterlum4".
**
** Y coefficient 4 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff4" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum4_YCoeff4( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum4_YCoeff4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum4Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum5".
**
** This function writes the given value to the register "SdCcfilterlum5".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum5( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum5( uint32_t value )
{
    FREG_VE_SdCcfilterlum5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff5" of register "SdCcfilterlum5".
**
** Y coefficient 5 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum5_YCoeff5( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum5_YCoeff5( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum5Mirror & ~mask;
    FREG_VE_SdCcfilterlum5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum5".
**
** This function reads the value from the register "SdCcfilterlum5".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum5( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum5Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff5" of register "SdCcfilterlum5".
**
** Y coefficient 5 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum5_YCoeff5( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum5_YCoeff5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum5Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum6".
**
** This function writes the given value to the register "SdCcfilterlum6".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum6( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum6( uint32_t value )
{
    FREG_VE_SdCcfilterlum6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM6)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff6" of register "SdCcfilterlum6".
**
** Y coefficient 6 (9 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff6" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum6_YCoeff6( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum6_YCoeff6( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum6Mirror & ~mask;
    FREG_VE_SdCcfilterlum6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM6)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum6".
**
** This function reads the value from the register "SdCcfilterlum6".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum6( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum6Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff6" of register "SdCcfilterlum6".
**
** Y coefficient 6 (9 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff6" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum6_YCoeff6( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum6_YCoeff6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum6Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum7".
**
** This function writes the given value to the register "SdCcfilterlum7".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum7( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum7( uint32_t value )
{
    FREG_VE_SdCcfilterlum7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM7)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff7" of register "SdCcfilterlum7".
**
** Y coefficient 7 (9 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff7" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum7_YCoeff7( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum7_YCoeff7( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum7Mirror & ~mask;
    FREG_VE_SdCcfilterlum7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM7)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum7".
**
** This function reads the value from the register "SdCcfilterlum7".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum7( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum7Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff7" of register "SdCcfilterlum7".
**
** Y coefficient 7 (9 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff7" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum7_YCoeff7( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum7_YCoeff7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum7Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum8".
**
** This function writes the given value to the register "SdCcfilterlum8".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum8( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum8( uint32_t value )
{
    FREG_VE_SdCcfilterlum8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM8)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff8" of register "SdCcfilterlum8".
**
** Y coefficient 8 (9 bit unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff8" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum8_YCoeff8( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum8_YCoeff8( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum8Mirror & ~mask;
    FREG_VE_SdCcfilterlum8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM8)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum8".
**
** This function reads the value from the register "SdCcfilterlum8".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum8( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum8Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff8" of register "SdCcfilterlum8".
**
** Y coefficient 8 (9 bit unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff8" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum8_YCoeff8( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum8_YCoeff8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum8Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterlum9".
**
** This function writes the given value to the register "SdCcfilterlum9".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum9( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum9( uint32_t value )
{
    FREG_VE_SdCcfilterlum9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM9)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YCoeff9" of register "SdCcfilterlum9".
**
** Y coefficient 9 (9 bit unsigned)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterlum9_YCoeff9( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterlum9_YCoeff9( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterlum9Mirror & ~mask;
    FREG_VE_SdCcfilterlum9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERLUM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERLUM9)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterlum9".
**
** This function reads the value from the register "SdCcfilterlum9".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum9( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum9Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YCoeff9" of register "SdCcfilterlum9".
**
** Y coefficient 9 (9 bit unsigned)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterlum9_YCoeff9( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterlum9_YCoeff9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterlum9Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom2".
**
** This function writes the given value to the register "SdCcfilterchrom2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom2( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom2( uint32_t value )
{
    FREG_VE_SdCcfilterchrom2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff2" of register "SdCcfilterchrom2".
**
** Chrom coefficient 2 (6 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff2" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom2_CCoeff2( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom2_CCoeff2( uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom2Mirror & ~mask;
    FREG_VE_SdCcfilterchrom2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom2".
**
** This function reads the value from the register "SdCcfilterchrom2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom2( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom2Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff2" of register "SdCcfilterchrom2".
**
** Chrom coefficient 2 (6 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff2" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom2_CCoeff2( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom2_CCoeff2( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom2Mirror;
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom3".
**
** This function writes the given value to the register "SdCcfilterchrom3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom3( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom3( uint32_t value )
{
    FREG_VE_SdCcfilterchrom3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff3" of register "SdCcfilterchrom3".
**
** Chrom coefficient 3 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom3_CCoeff3( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom3_CCoeff3( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom3Mirror & ~mask;
    FREG_VE_SdCcfilterchrom3Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM3, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom3".
**
** This function reads the value from the register "SdCcfilterchrom3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom3( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom3Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff3" of register "SdCcfilterchrom3".
**
** Chrom coefficient 3 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff3" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom3_CCoeff3( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom3_CCoeff3( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom3Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom4".
**
** This function writes the given value to the register "SdCcfilterchrom4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom4( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom4( uint32_t value )
{
    FREG_VE_SdCcfilterchrom4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff4" of register "SdCcfilterchrom4".
**
** Chrom coefficient 4 (7 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff4" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom4_CCoeff4( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom4_CCoeff4( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom4Mirror & ~mask;
    FREG_VE_SdCcfilterchrom4Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM4, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom4".
**
** This function reads the value from the register "SdCcfilterchrom4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom4( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom4Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff4" of register "SdCcfilterchrom4".
**
** Chrom coefficient 4 (7 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff4" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom4_CCoeff4( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom4_CCoeff4( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom4Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom5".
**
** This function writes the given value to the register "SdCcfilterchrom5".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom5( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom5( uint32_t value )
{
    FREG_VE_SdCcfilterchrom5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff5" of register "SdCcfilterchrom5".
**
** Chrom coefficient 5 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom5_CCoeff5( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom5_CCoeff5( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom5Mirror & ~mask;
    FREG_VE_SdCcfilterchrom5Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM5, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom5".
**
** This function reads the value from the register "SdCcfilterchrom5".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom5( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom5Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff5" of register "SdCcfilterchrom5".
**
** Chrom coefficient 5 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff5" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom5_CCoeff5( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom5_CCoeff5( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom5Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom6".
**
** This function writes the given value to the register "SdCcfilterchrom6".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom6( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom6( uint32_t value )
{
    FREG_VE_SdCcfilterchrom6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM6)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff6" of register "SdCcfilterchrom6".
**
** Chrom coefficient 6 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff6" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom6_CCoeff6( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom6_CCoeff6( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom6Mirror & ~mask;
    FREG_VE_SdCcfilterchrom6Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM6, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM6)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom6".
**
** This function reads the value from the register "SdCcfilterchrom6".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom6( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom6Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff6" of register "SdCcfilterchrom6".
**
** Chrom coefficient 6 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff6" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom6_CCoeff6( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom6_CCoeff6( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom6Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom7".
**
** This function writes the given value to the register "SdCcfilterchrom7".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom7( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom7( uint32_t value )
{
    FREG_VE_SdCcfilterchrom7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM7)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff7" of register "SdCcfilterchrom7".
**
** Chrom coefficient 7 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff7" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom7_CCoeff7( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom7_CCoeff7( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom7Mirror & ~mask;
    FREG_VE_SdCcfilterchrom7Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM7, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM7)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom7".
**
** This function reads the value from the register "SdCcfilterchrom7".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom7( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom7Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff7" of register "SdCcfilterchrom7".
**
** Chrom coefficient 7 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff7" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom7_CCoeff7( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom7_CCoeff7( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom7Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom8".
**
** This function writes the given value to the register "SdCcfilterchrom8".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom8( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom8( uint32_t value )
{
    FREG_VE_SdCcfilterchrom8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM8)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff8" of register "SdCcfilterchrom8".
**
** Chrom coefficient 8 (8 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff8" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom8_CCoeff8( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom8_CCoeff8( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom8Mirror & ~mask;
    FREG_VE_SdCcfilterchrom8Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM8, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM8)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom8".
**
** This function reads the value from the register "SdCcfilterchrom8".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom8( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom8Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff8" of register "SdCcfilterchrom8".
**
** Chrom coefficient 8 (8 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff8" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom8_CCoeff8( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom8_CCoeff8( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom8Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterchrom9".
**
** This function writes the given value to the register "SdCcfilterchrom9".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom9( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom9( uint32_t value )
{
    FREG_VE_SdCcfilterchrom9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM9)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CCoeff9" of register "SdCcfilterchrom9".
**
** Chrom coefficient 9 (9 bit signed)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterchrom9_CCoeff9( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterchrom9_CCoeff9( uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterchrom9Mirror & ~mask;
    FREG_VE_SdCcfilterchrom9Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERCHROM9, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERCHROM9)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterchrom9".
**
** This function reads the value from the register "SdCcfilterchrom9".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom9( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom9Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CCoeff9" of register "SdCcfilterchrom9".
**
** Chrom coefficient 9 (9 bit signed)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CCoeff9" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterchrom9_CCoeff9( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterchrom9_CCoeff9( void )
{
    register uint32_t value = FREG_VE_SdCcfilterchrom9Mirror;
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterhorstart".
**
** This function writes the given value to the register "SdCcfilterhorstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterhorstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterhorstart( uint32_t value )
{
    FREG_VE_SdCcfilterhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterhorstart" of register "SdCcfilterhorstart".
**
** horizontal start position when CC filter gets active
** recommended value: 0x200
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterhorstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterhorstart_SdCcfilterhorstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterhorstart_SdCcfilterhorstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterhorstartMirror & ~mask;
    FREG_VE_SdCcfilterhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterhorstart".
**
** This function reads the value from the register "SdCcfilterhorstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterhorstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterhorstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterhorstart" of register "SdCcfilterhorstart".
**
** horizontal start position when CC filter gets active
** recommended value: 0x200
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterhorstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterhorstart_SdCcfilterhorstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterhorstart_SdCcfilterhorstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterhorstop".
**
** This function writes the given value to the register "SdCcfilterhorstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterhorstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterhorstop( uint32_t value )
{
    FREG_VE_SdCcfilterhorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterhorstop" of register "SdCcfilterhorstop".
**
** horizontal stop position when CC filter gets de-activated
** recommended value: 0xD60
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterhorstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterhorstop_SdCcfilterhorstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterhorstop_SdCcfilterhorstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterhorstopMirror & ~mask;
    FREG_VE_SdCcfilterhorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERHORSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterhorstop".
**
** This function reads the value from the register "SdCcfilterhorstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterhorstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterhorstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterhorstop" of register "SdCcfilterhorstop".
**
** horizontal stop position when CC filter gets de-activated
** recommended value: 0xD60
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterhorstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterhorstop_SdCcfilterhorstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterhorstop_SdCcfilterhorstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterhorstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterverstart".
**
** This function writes the given value to the register "SdCcfilterverstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterverstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterverstart( uint32_t value )
{
    FREG_VE_SdCcfilterverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterverstart" of register "SdCcfilterverstart".
**
** vertical start position when CC filter gets activated
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterverstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterverstart_SdCcfilterverstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterverstart_SdCcfilterverstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterverstartMirror & ~mask;
    FREG_VE_SdCcfilterverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterverstart".
**
** This function reads the value from the register "SdCcfilterverstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterverstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterverstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterverstart" of register "SdCcfilterverstart".
**
** vertical start position when CC filter gets activated
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterverstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterverstart_SdCcfilterverstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterverstart_SdCcfilterverstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterverstop".
**
** This function writes the given value to the register "SdCcfilterverstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterverstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterverstop( uint32_t value )
{
    FREG_VE_SdCcfilterverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterverstop" of register "SdCcfilterverstop".
**
** vertical stop position when CC filter gets de-activated
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterverstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterverstop_SdCcfilterverstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterverstop_SdCcfilterverstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterverstopMirror & ~mask;
    FREG_VE_SdCcfilterverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERVERSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterverstop".
**
** This function reads the value from the register "SdCcfilterverstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterverstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterverstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterverstop" of register "SdCcfilterverstop".
**
** vertical stop position when CC filter gets de-activated
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterverstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterverstop_SdCcfilterverstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterverstop_SdCcfilterverstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterverstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterblankstart".
**
** This function writes the given value to the register "SdCcfilterblankstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterblankstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterblankstart( uint32_t value )
{
    FREG_VE_SdCcfilterblankstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterblankstart" of register "SdCcfilterblankstart".
**
** horizontal blank start of the CC filter
** recommended value: 0x200
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterblankstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterblankstart_SdCcfilterblankstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterblankstart_SdCcfilterblankstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterblankstartMirror & ~mask;
    FREG_VE_SdCcfilterblankstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterblankstart".
**
** This function reads the value from the register "SdCcfilterblankstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterblankstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterblankstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterblankstart" of register "SdCcfilterblankstart".
**
** horizontal blank start of the CC filter
** recommended value: 0x200
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterblankstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterblankstart_SdCcfilterblankstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterblankstart_SdCcfilterblankstart( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterblankstop".
**
** This function writes the given value to the register "SdCcfilterblankstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterblankstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterblankstop( uint32_t value )
{
    FREG_VE_SdCcfilterblankstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterblankstop" of register "SdCcfilterblankstop".
**
** horizontal blank stop of the CC filter
** recommended value: 0xD20
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterblankstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterblankstop_SdCcfilterblankstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterblankstop_SdCcfilterblankstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterblankstopMirror & ~mask;
    FREG_VE_SdCcfilterblankstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERBLANKSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERBLANKSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterblankstop".
**
** This function reads the value from the register "SdCcfilterblankstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterblankstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterblankstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterblankstop" of register "SdCcfilterblankstop".
**
** horizontal blank stop of the CC filter
** recommended value: 0xD20
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterblankstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterblankstop_SdCcfilterblankstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterblankstop_SdCcfilterblankstop( void )
{
    register uint32_t value = FREG_VE_SdCcfilterblankstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdCcfilterenable".
**
** This function writes the given value to the register "SdCcfilterenable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterenable( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterenable( uint32_t value )
{
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCchalfcoeffmode" of register "SdCcfilterenable".
**
** Switches the CC filter into half coefficient mode.
**  This allows more flexibility in selecting the coefficients. The disadvantage is the loss of resolution. The sum of all coefficients (per phase) is in this case 256 instead of the usual 512.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCchalfcoeffmode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterenable_SdCchalfcoeffmode( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterenable_SdCchalfcoeffmode( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_VE_SdCcfilterenableMirror & ~mask;
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcdelaycomp" of register "SdCcfilterenable".
**
** enables one cycle of delay (13.
** 5MHz) on the non-cross color fixed path. Can be used to compensate for differences between non-cc fixed signals and cc-fixed signals
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcdelaycomp" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterenable_SdCcdelaycomp( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterenable_SdCcdelaycomp( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_SdCcfilterenableMirror & ~mask;
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdCcfilterenable" of register "SdCcfilterenable".
**
** enables the CC filter
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdCcfilterenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdCcfilterenable_SdCcfilterenable( uint32_t value );
#else
INLINE void FREG_VE_SetSdCcfilterenable_SdCcfilterenable( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdCcfilterenableMirror & ~mask;
    FREG_VE_SdCcfilterenableMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDCCFILTERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDCCFILTERENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdCcfilterenable".
**
** This function reads the value from the register "SdCcfilterenable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterenable( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterenable( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCchalfcoeffmode" of register "SdCcfilterenable".
**
** Switches the CC filter into half coefficient mode.
**  This allows more flexibility in selecting the coefficients. The disadvantage is the loss of resolution. The sum of all coefficients (per phase) is in this case 256 instead of the usual 512.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCchalfcoeffmode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterenable_SdCchalfcoeffmode( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterenable_SdCchalfcoeffmode( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcdelaycomp" of register "SdCcfilterenable".
**
** enables one cycle of delay (13.
** 5MHz) on the non-cross color fixed path. Can be used to compensate for differences between non-cc fixed signals and cc-fixed signals
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcdelaycomp" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterenable_SdCcdelaycomp( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterenable_SdCcdelaycomp( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdCcfilterenable" of register "SdCcfilterenable".
**
** enables the CC filter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdCcfilterenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdCcfilterenable_SdCcfilterenable( void );
#else
INLINE uint32_t FREG_VE_GetmSdCcfilterenable_SdCcfilterenable( void )
{
    register uint32_t value = FREG_VE_SdCcfilterenableMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdHorlinelength".
**
** This function writes the given value to the register "SdHorlinelength".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdHorlinelength( uint32_t value );
#else
INLINE void FREG_VE_SetSdHorlinelength( uint32_t value )
{
    FREG_VE_SdHorlinelengthMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHORLINELENGTH, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHORLINELENGTH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "HorLl" of register "SdHorlinelength".
**
** horizontal line length in 54.
** 0MHz cycles.
** PAL B/G: 3456 = 0xD80
** NTSC M: 3432 = 0xD68
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "HorLl" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdHorlinelength_HorLl( uint32_t value );
#else
INLINE void FREG_VE_SetSdHorlinelength_HorLl( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdHorlinelengthMirror & ~mask;
    FREG_VE_SdHorlinelengthMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHORLINELENGTH, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHORLINELENGTH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdHorlinelength".
**
** This function reads the value from the register "SdHorlinelength".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdHorlinelength( void );
#else
INLINE uint32_t FREG_VE_GetmSdHorlinelength( void )
{
    register uint32_t value = FREG_VE_SdHorlinelengthMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "HorLl" of register "SdHorlinelength".
**
** horizontal line length in 54.
** 0MHz cycles.
** PAL B/G: 3456 = 0xD80
** NTSC M: 3432 = 0xD68
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "HorLl" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdHorlinelength_HorLl( void );
#else
INLINE uint32_t FREG_VE_GetmSdHorlinelength_HorLl( void )
{
    register uint32_t value = FREG_VE_SdHorlinelengthMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdVersize".
**
** This function writes the given value to the register "SdVersize".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdVersize( uint32_t value );
#else
INLINE void FREG_VE_SetSdVersize( uint32_t value )
{
    FREG_VE_SdVersizeMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVERSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VerSize" of register "SdVersize".
**
** Output window: stop value of the line counter (lines per field).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VerSize" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdVersize_VerSize( uint32_t value );
#else
INLINE void FREG_VE_SetSdVersize_VerSize( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVersizeMirror & ~mask;
    FREG_VE_SdVersizeMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVERSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdVersize".
**
** This function reads the value from the register "SdVersize".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVersize( void );
#else
INLINE uint32_t FREG_VE_GetmSdVersize( void )
{
    register uint32_t value = FREG_VE_SdVersizeMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VerSize" of register "SdVersize".
**
** Output window: stop value of the line counter (lines per field).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VerSize" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVersize_VerSize( void );
#else
INLINE uint32_t FREG_VE_GetmSdVersize_VerSize( void )
{
    register uint32_t value = FREG_VE_SdVersizeMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdBackground".
**
** This function writes the given value to the register "SdBackground".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdBackground( uint32_t value );
#else
INLINE void FREG_VE_SetSdBackground( uint32_t value )
{
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackGroundY" of register "SdBackground".
**
** Luminance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x10 = 16 (black)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdBackground_BackGroundY( uint32_t value );
#else
INLINE void FREG_VE_SetSdBackground_BackGroundY( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VE_SdBackgroundMirror & ~mask;
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackGroundCb" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundCb" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdBackground_BackGroundCb( uint32_t value );
#else
INLINE void FREG_VE_SetSdBackground_BackGroundCb( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_SdBackgroundMirror & ~mask;
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackGroundCr" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundCr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdBackground_BackGroundCr( uint32_t value );
#else
INLINE void FREG_VE_SetSdBackground_BackGroundCr( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdBackgroundMirror & ~mask;
    FREG_VE_SdBackgroundMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdBackground".
**
** This function reads the value from the register "SdBackground".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdBackground( void );
#else
INLINE uint32_t FREG_VE_GetmSdBackground( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackGroundY" of register "SdBackground".
**
** Luminance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x10 = 16 (black)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdBackground_BackGroundY( void );
#else
INLINE uint32_t FREG_VE_GetmSdBackground_BackGroundY( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackGroundCb" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundCb" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdBackground_BackGroundCb( void );
#else
INLINE uint32_t FREG_VE_GetmSdBackground_BackGroundCb( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackGroundCr" of register "SdBackground".
**
** Chrominance value of the background in the SD path.
** This applies to the part where no video is inserted (in cases with less then 720 pixel on the output of the SD scaler). Typical value: 0x80 = 128 (no color)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundCr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdBackground_BackGroundCr( void );
#else
INLINE uint32_t FREG_VE_GetmSdBackground_BackGroundCr( void )
{
    register uint32_t value = FREG_VE_SdBackgroundMirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdVohorstart".
**
** This function writes the given value to the register "SdVohorstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdVohorstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdVohorstart( uint32_t value )
{
    FREG_VE_SdVohorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VoHorStart" of register "SdVohorstart".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508
** Typical value for NTSC: 508
** (change only in steps of 4)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoHorStart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdVohorstart_VoHorStart( uint32_t value );
#else
INLINE void FREG_VE_SetSdVohorstart_VoHorStart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVohorstartMirror & ~mask;
    FREG_VE_SdVohorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdVohorstart".
**
** This function reads the value from the register "SdVohorstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVohorstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdVohorstart( void )
{
    register uint32_t value = FREG_VE_SdVohorstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VoHorStart" of register "SdVohorstart".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508
** Typical value for NTSC: 508
** (change only in steps of 4)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoHorStart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVohorstart_VoHorStart( void );
#else
INLINE uint32_t FREG_VE_GetmSdVohorstart_VoHorStart( void )
{
    register uint32_t value = FREG_VE_SdVohorstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdVohorstop".
**
** This function writes the given value to the register "SdVohorstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdVohorstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdVohorstop( uint32_t value )
{
    FREG_VE_SdVohorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VoHorStop" of register "SdVohorstop".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508 +(4*720)
** Typical value for NTSC: 508 + (4*720)
** (change only in steps of 4)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoHorStop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdVohorstop_VoHorStop( uint32_t value );
#else
INLINE void FREG_VE_SetSdVohorstop_VoHorStop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVohorstopMirror & ~mask;
    FREG_VE_SdVohorstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOHORSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdVohorstop".
**
** This function reads the value from the register "SdVohorstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVohorstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdVohorstop( void )
{
    register uint32_t value = FREG_VE_SdVohorstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VoHorStop" of register "SdVohorstop".
**
** Insertion window for video.
**  (54MHz cycles)
** Typical value for PAL 508 +(4*720)
** Typical value for NTSC: 508 + (4*720)
** (change only in steps of 4)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoHorStop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVohorstop_VoHorStop( void );
#else
INLINE uint32_t FREG_VE_GetmSdVohorstop_VoHorStop( void )
{
    register uint32_t value = FREG_VE_SdVohorstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdVoverstart".
**
** This function writes the given value to the register "SdVoverstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdVoverstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdVoverstart( uint32_t value )
{
    FREG_VE_SdVoverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VoVerStart" of register "SdVoverstart".
**
** Insertion window for video.
** 
** Typical value for PAL 23
** Typical value for NTSC: 21
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoVerStart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdVoverstart_VoVerStart( uint32_t value );
#else
INLINE void FREG_VE_SetSdVoverstart_VoVerStart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVoverstartMirror & ~mask;
    FREG_VE_SdVoverstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdVoverstart".
**
** This function reads the value from the register "SdVoverstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVoverstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdVoverstart( void )
{
    register uint32_t value = FREG_VE_SdVoverstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VoVerStart" of register "SdVoverstart".
**
** Insertion window for video.
** 
** Typical value for PAL 23
** Typical value for NTSC: 21
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoVerStart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVoverstart_VoVerStart( void );
#else
INLINE uint32_t FREG_VE_GetmSdVoverstart_VoVerStart( void )
{
    register uint32_t value = FREG_VE_SdVoverstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdVoverstop".
**
** This function writes the given value to the register "SdVoverstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdVoverstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdVoverstop( uint32_t value )
{
    FREG_VE_SdVoverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VoVerStop" of register "SdVoverstop".
**
** Insertion window for video.
** 
** Typical value for PAL 23 + 288
** Typical value for NTSC: 21 +240
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoVerStop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdVoverstop_VoVerStop( uint32_t value );
#else
INLINE void FREG_VE_SetSdVoverstop_VoVerStop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdVoverstopMirror & ~mask;
    FREG_VE_SdVoverstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVOVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVOVERSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdVoverstop".
**
** This function reads the value from the register "SdVoverstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVoverstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdVoverstop( void )
{
    register uint32_t value = FREG_VE_SdVoverstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VoVerStop" of register "SdVoverstop".
**
** Insertion window for video.
** 
** Typical value for PAL 23 + 288
** Typical value for NTSC: 21 +240
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoVerStop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdVoverstop_VoVerStop( void );
#else
INLINE uint32_t FREG_VE_GetmSdVoverstop_VoVerStop( void )
{
    register uint32_t value = FREG_VE_SdVoverstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdTtxhorstart".
**
** This function writes the given value to the register "SdTtxhorstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdTtxhorstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdTtxhorstart( uint32_t value )
{
    FREG_VE_SdTtxhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDTTXHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxEnable" of register "SdTtxhorstart".
**
** enables TTX insertion
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxEnable" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdTtxhorstart_TtxEnable( uint32_t value );
#else
INLINE void FREG_VE_SetSdTtxhorstart_TtxEnable( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VE_SdTtxhorstartMirror & ~mask;
    FREG_VE_SdTtxhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDTTXHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxHorStart" of register "SdTtxhorstart".
**
** The pixel counter counts 54.
** 0MHz clock cycles. If the pixel counter reaches this value (times 4), the Teletext data will be inserted in the video.
** Typical value for PAL: = 528 (0x210)
** Typical value for Secam: = 540 (0x21C)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxHorStart" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdTtxhorstart_TtxHorStart( uint32_t value );
#else
INLINE void FREG_VE_SetSdTtxhorstart_TtxHorStart( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdTtxhorstartMirror & ~mask;
    FREG_VE_SdTtxhorstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDTTXHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdTtxhorstart".
**
** This function reads the value from the register "SdTtxhorstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdTtxhorstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdTtxhorstart( void )
{
    register uint32_t value = FREG_VE_SdTtxhorstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "TtxEnable" of register "SdTtxhorstart".
**
** enables TTX insertion
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxEnable" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdTtxhorstart_TtxEnable( void );
#else
INLINE uint32_t FREG_VE_GetmSdTtxhorstart_TtxEnable( void )
{
    register uint32_t value = FREG_VE_SdTtxhorstartMirror;
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "TtxHorStart" of register "SdTtxhorstart".
**
** The pixel counter counts 54.
** 0MHz clock cycles. If the pixel counter reaches this value (times 4), the Teletext data will be inserted in the video.
** Typical value for PAL: = 528 (0x210)
** Typical value for Secam: = 540 (0x21C)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxHorStart" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdTtxhorstart_TtxHorStart( void );
#else
INLINE uint32_t FREG_VE_GetmSdTtxhorstart_TtxHorStart( void )
{
    register uint32_t value = FREG_VE_SdTtxhorstartMirror;
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhvsynccfg".
**
** This function writes the given value to the register "Sdhvsynccfg".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdhvsynccfg( uint32_t value );
#else
INLINE void FREG_VE_SetSdhvsynccfg( uint32_t value )
{
    FREG_VE_SdhvsynccfgMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHVSYNCCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHVSYNCCFG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdSyncEnable" of register "Sdhvsynccfg".
**
** enables the SD block to become synchronized
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdSyncEnable" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdhvsynccfg_SdSyncEnable( uint32_t value );
#else
INLINE void FREG_VE_SetSdhvsynccfg_SdSyncEnable( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VE_SdhvsynccfgMirror & ~mask;
    FREG_VE_SdhvsynccfgMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHVSYNCCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHVSYNCCFG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhvsynccfg".
**
** This function reads the value from the register "Sdhvsynccfg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhvsynccfg( void );
#else
INLINE uint32_t FREG_VE_GetmSdhvsynccfg( void )
{
    register uint32_t value = FREG_VE_SdhvsynccfgMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdSyncEnable" of register "Sdhvsynccfg".
**
** enables the SD block to become synchronized
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdSyncEnable" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhvsynccfg_SdSyncEnable( void );
#else
INLINE uint32_t FREG_VE_GetmSdhvsynccfg_SdSyncEnable( void )
{
    register uint32_t value = FREG_VE_SdhvsynccfgMirror;
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncoffset".
**
** This function writes the given value to the register "Sdvsyncoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncoffset( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncoffset( uint32_t value )
{
    FREG_VE_SdvsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Field" of register "Sdvsyncoffset".
**
** field load value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Field" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncoffset_Field( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncoffset_Field( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncoffsetMirror & ~mask;
    FREG_VE_SdvsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sdvsyncoffset" of register "Sdvsyncoffset".
**
** vertical counter load value
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdvsyncoffset" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncoffset_Sdvsyncoffset( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncoffset_Sdvsyncoffset( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncoffsetMirror & ~mask;
    FREG_VE_SdvsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncoffset".
**
** This function reads the value from the register "Sdvsyncoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncoffset( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdvsyncoffsetMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Field" of register "Sdvsyncoffset".
**
** field load value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Field" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncoffset_Field( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncoffset_Field( void )
{
    register uint32_t value = FREG_VE_SdvsyncoffsetMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sdvsyncoffset" of register "Sdvsyncoffset".
**
** vertical counter load value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdvsyncoffset" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncoffset_Sdvsyncoffset( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncoffset_Sdvsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdvsyncoffsetMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncevstart".
**
** This function writes the given value to the register "Sdvsyncevstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncevstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncevstart( uint32_t value )
{
    FREG_VE_SdvsyncevstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncevstartfield" of register "Sdvsyncevstart".
**
** Defines the field where first vsync starts 0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncevstart_Vsyncevstartfield( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncevstart_Vsyncevstartfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncevstartMirror & ~mask;
    FREG_VE_SdvsyncevstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncevstart" of register "Sdvsyncevstart".
**
** Defines the line where first vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncevstart_Vsyncevstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncevstart_Vsyncevstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncevstartMirror & ~mask;
    FREG_VE_SdvsyncevstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncevstart".
**
** This function reads the value from the register "Sdvsyncevstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncevstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncevstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncevstartfield" of register "Sdvsyncevstart".
**
** Defines the field where first vsync starts 0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncevstart_Vsyncevstartfield( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncevstart_Vsyncevstartfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstartMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncevstart" of register "Sdvsyncevstart".
**
** Defines the line where first vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncevstart_Vsyncevstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncevstart_Vsyncevstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncovstart".
**
** This function writes the given value to the register "Sdvsyncovstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncovstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncovstart( uint32_t value )
{
    FREG_VE_SdvsyncovstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncovstartfield" of register "Sdvsyncovstart".
**
** Defines the field where second vsync starts  0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncovstart_Vsyncovstartfield( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncovstart_Vsyncovstartfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncovstartMirror & ~mask;
    FREG_VE_SdvsyncovstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncovstart" of register "Sdvsyncovstart".
**
** Defines the line where second vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncovstart_Vsyncovstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncovstart_Vsyncovstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncovstartMirror & ~mask;
    FREG_VE_SdvsyncovstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncovstart".
**
** This function reads the value from the register "Sdvsyncovstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncovstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncovstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncovstartfield" of register "Sdvsyncovstart".
**
** Defines the field where second vsync starts  0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstartfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncovstart_Vsyncovstartfield( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncovstart_Vsyncovstartfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstartMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncovstart" of register "Sdvsyncovstart".
**
** Defines the line where second vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstart" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncovstart_Vsyncovstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncovstart_Vsyncovstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstartMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncevstop".
**
** This function writes the given value to the register "Sdvsyncevstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncevstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncevstop( uint32_t value )
{
    FREG_VE_SdvsyncevstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncevstopfield" of register "Sdvsyncevstop".
**
** Defines the field where first vsync stops 0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncevstop_Vsyncevstopfield( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncevstop_Vsyncevstopfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncevstopMirror & ~mask;
    FREG_VE_SdvsyncevstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncevstop" of register "Sdvsyncevstop".
**
** Defines the line where first vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncevstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncevstop_Vsyncevstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncevstop_Vsyncevstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncevstopMirror & ~mask;
    FREG_VE_SdvsyncevstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEVSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncevstop".
**
** This function reads the value from the register "Sdvsyncevstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncevstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncevstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncevstopfield" of register "Sdvsyncevstop".
**
** Defines the field where first vsync stops 0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncevstop_Vsyncevstopfield( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncevstop_Vsyncevstopfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstopMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncevstop" of register "Sdvsyncevstop".
**
** Defines the line where first vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncevstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncevstop_Vsyncevstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncevstop_Vsyncevstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncevstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncovstop".
**
** This function writes the given value to the register "Sdvsyncovstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncovstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncovstop( uint32_t value )
{
    FREG_VE_SdvsyncovstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncovstopfield" of register "Sdvsyncovstop".
**
** Defines the field where vsync stops (second stop) 0 = first field 1 = second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncovstop_Vsyncovstopfield( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncovstop_Vsyncovstopfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_SdvsyncovstopMirror & ~mask;
    FREG_VE_SdvsyncovstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncovstop" of register "Sdvsyncovstop".
**
** Defines the line where second vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncovstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncovstop_Vsyncovstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncovstop_Vsyncovstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncovstopMirror & ~mask;
    FREG_VE_SdvsyncovstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOVSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncovstop".
**
** This function reads the value from the register "Sdvsyncovstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncovstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncovstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncovstopfield" of register "Sdvsyncovstop".
**
** Defines the field where vsync stops (second stop) 0 = first field 1 = second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstopfield" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncovstop_Vsyncovstopfield( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncovstop_Vsyncovstopfield( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstopMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncovstop" of register "Sdvsyncovstop".
**
** Defines the line where second vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncovstop" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncovstop_Vsyncovstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncovstop_Vsyncovstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncovstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncehstart".
**
** This function writes the given value to the register "Sdvsyncehstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncehstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncehstart( uint32_t value )
{
    FREG_VE_SdvsyncehstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncehstart" of register "Sdvsyncehstart".
**
** Defines the H-pos where first vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncehstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncehstart_Vsyncehstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncehstart_Vsyncehstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncehstartMirror & ~mask;
    FREG_VE_SdvsyncehstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncehstart".
**
** This function reads the value from the register "Sdvsyncehstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncehstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncehstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncehstart" of register "Sdvsyncehstart".
**
** Defines the H-pos where first vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncehstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncehstart_Vsyncehstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncehstart_Vsyncehstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncohstart".
**
** This function writes the given value to the register "Sdvsyncohstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncohstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncohstart( uint32_t value )
{
    FREG_VE_SdvsyncohstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncohstart" of register "Sdvsyncohstart".
**
** Defines the H-pos where second vsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncohstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncohstart_Vsyncohstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncohstart_Vsyncohstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncohstartMirror & ~mask;
    FREG_VE_SdvsyncohstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncohstart".
**
** This function reads the value from the register "Sdvsyncohstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncohstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncohstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncohstart" of register "Sdvsyncohstart".
**
** Defines the H-pos where second vsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncohstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncohstart_Vsyncohstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncohstart_Vsyncohstart( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncehstop".
**
** This function writes the given value to the register "Sdvsyncehstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncehstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncehstop( uint32_t value )
{
    FREG_VE_SdvsyncehstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncehstop" of register "Sdvsyncehstop".
**
** Defines the H-pos where first vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncehstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncehstop_Vsyncehstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncehstop_Vsyncehstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncehstopMirror & ~mask;
    FREG_VE_SdvsyncehstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCEHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCEHSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncehstop".
**
** This function reads the value from the register "Sdvsyncehstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncehstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncehstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncehstop" of register "Sdvsyncehstop".
**
** Defines the H-pos where first vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncehstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncehstop_Vsyncehstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncehstop_Vsyncehstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncehstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvsyncohstop".
**
** This function writes the given value to the register "Sdvsyncohstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncohstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncohstop( uint32_t value )
{
    FREG_VE_SdvsyncohstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vsyncohstop" of register "Sdvsyncohstop".
**
** Defines the H-pos where second vsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vsyncohstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdvsyncohstop_Vsyncohstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdvsyncohstop_Vsyncohstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdvsyncohstopMirror & ~mask;
    FREG_VE_SdvsyncohstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDVSYNCOHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDVSYNCOHSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvsyncohstop".
**
** This function reads the value from the register "Sdvsyncohstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncohstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncohstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vsyncohstop" of register "Sdvsyncohstop".
**
** Defines the H-pos where second vsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vsyncohstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdvsyncohstop_Vsyncohstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdvsyncohstop_Vsyncohstop( void )
{
    register uint32_t value = FREG_VE_SdvsyncohstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhsyncstart".
**
** This function writes the given value to the register "Sdhsyncstart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdhsyncstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdhsyncstart( uint32_t value )
{
    FREG_VE_SdhsyncstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hsyncstart" of register "Sdhsyncstart".
**
** Defines the H-pos where hsync starts
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsyncstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdhsyncstart_Hsyncstart( uint32_t value );
#else
INLINE void FREG_VE_SetSdhsyncstart_Hsyncstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdhsyncstartMirror & ~mask;
    FREG_VE_SdhsyncstartMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhsyncstart".
**
** This function reads the value from the register "Sdhsyncstart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhsyncstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdhsyncstart( void )
{
    register uint32_t value = FREG_VE_SdhsyncstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hsyncstart" of register "Sdhsyncstart".
**
** Defines the H-pos where hsync starts
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsyncstart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhsyncstart_Hsyncstart( void );
#else
INLINE uint32_t FREG_VE_GetmSdhsyncstart_Hsyncstart( void )
{
    register uint32_t value = FREG_VE_SdhsyncstartMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhsyncstop".
**
** This function writes the given value to the register "Sdhsyncstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdhsyncstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdhsyncstop( uint32_t value )
{
    FREG_VE_SdhsyncstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hsyncstop" of register "Sdhsyncstop".
**
** Defines the H-pos where hsync stops
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsyncstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdhsyncstop_Hsyncstop( uint32_t value );
#else
INLINE void FREG_VE_SetSdhsyncstop_Hsyncstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdhsyncstopMirror & ~mask;
    FREG_VE_SdhsyncstopMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhsyncstop".
**
** This function reads the value from the register "Sdhsyncstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhsyncstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdhsyncstop( void )
{
    register uint32_t value = FREG_VE_SdhsyncstopMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hsyncstop" of register "Sdhsyncstop".
**
** Defines the H-pos where hsync stops
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsyncstop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhsyncstop_Hsyncstop( void );
#else
INLINE uint32_t FREG_VE_GetmSdhsyncstop_Hsyncstop( void )
{
    register uint32_t value = FREG_VE_SdhsyncstopMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhsyncoffset".
**
** This function writes the given value to the register "Sdhsyncoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdhsyncoffset( uint32_t value );
#else
INLINE void FREG_VE_SetSdhsyncoffset( uint32_t value )
{
    FREG_VE_SdhsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sdhsyncoffset" of register "Sdhsyncoffset".
**
** horizontal counter load value when frame sync arrives.
** 
** Lower three bit need to be set to 0x4
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdhsyncoffset" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetSdhsyncoffset_Sdhsyncoffset( uint32_t value );
#else
INLINE void FREG_VE_SetSdhsyncoffset_Sdhsyncoffset( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdhsyncoffsetMirror & ~mask;
    FREG_VE_SdhsyncoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDHSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDHSYNCOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhsyncoffset".
**
** This function reads the value from the register "Sdhsyncoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhsyncoffset( void );
#else
INLINE uint32_t FREG_VE_GetmSdhsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdhsyncoffsetMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sdhsyncoffset" of register "Sdhsyncoffset".
**
** horizontal counter load value when frame sync arrives.
** 
** Lower three bit need to be set to 0x4
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdhsyncoffset" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdhsyncoffset_Sdhsyncoffset( void );
#else
INLINE uint32_t FREG_VE_GetmSdhsyncoffset_Sdhsyncoffset( void )
{
    register uint32_t value = FREG_VE_SdhsyncoffsetMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "VoOsd1clut".
**
** This function writes the given value to the index-th entry of the register
** array VoOsd1clut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd1clut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd1clut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCb" of register "VoOsd1clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd1clut_ClutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd1clut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutY" of register "VoOsd1clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd1clut_ClutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd1clut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCr" of register "VoOsd1clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd1clut_ClutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd1clut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutAlpha" of register "VoOsd1clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd1clut_ClutAlpha( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd1clut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VoOsd1clutMirror[index] & ~mask;
    FREG_VE_VoOsd1clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "VoOsd1clut".
**
** This function reads the value from the index-th entry of the register
** array VoOsd1clut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd1clut( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd1clut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCb" of register "VoOsd1clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd1clut_ClutCb( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd1clut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutY" of register "VoOsd1clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd1clut_ClutY( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd1clut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCr" of register "VoOsd1clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd1clut_ClutCr( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd1clut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutAlpha" of register "VoOsd1clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd1clut_ClutAlpha( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd1clut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd1clutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "VoOsd2clut".
**
** This function writes the given value to the index-th entry of the register
** array VoOsd2clut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd2clut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd2clut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCb" of register "VoOsd2clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd2clut_ClutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd2clut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutY" of register "VoOsd2clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd2clut_ClutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd2clut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCr" of register "VoOsd2clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd2clut_ClutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd2clut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutAlpha" of register "VoOsd2clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetVoOsd2clut_ClutAlpha( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoOsd2clut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VoOsd2clutMirror[index] & ~mask;
    FREG_VE_VoOsd2clutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOOSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOOSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "VoOsd2clut".
**
** This function reads the value from the index-th entry of the register
** array VoOsd2clut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd2clut( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd2clut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCb" of register "VoOsd2clut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd2clut_ClutCb( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd2clut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutY" of register "VoOsd2clut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd2clut_ClutY( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd2clut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCr" of register "VoOsd2clut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd2clut_ClutCr( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd2clut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutAlpha" of register "VoOsd2clut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoOsd2clut_ClutAlpha( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoOsd2clut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoOsd2clutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "VoCursorclut".
**
** This function writes the given value to the index-th entry of the register
** array VoCursorclut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetVoCursorclut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoCursorclut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCb" of register "VoCursorclut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoCursorclut_ClutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoCursorclut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutY" of register "VoCursorclut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoCursorclut_ClutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoCursorclut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCr" of register "VoCursorclut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VE_SetVoCursorclut_ClutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoCursorclut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutAlpha" of register "VoCursorclut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetVoCursorclut_ClutAlpha( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoCursorclut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VoCursorclutMirror[index] & ~mask;
    FREG_VE_VoCursorclutMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOCURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOCURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "VoCursorclut".
**
** This function reads the value from the index-th entry of the register
** array VoCursorclut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoCursorclut( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoCursorclut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCb" of register "VoCursorclut".
**
** Cb Value:
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCb" consists of the bits 31..24,
**       the given bitgroup value will be shifted left by 24 bits and
**       masked using the bitmask 0xFF000000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoCursorclut_ClutCb( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoCursorclut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutY" of register "VoCursorclut".
**
** Y Value
** 16: black
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoCursorclut_ClutY( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoCursorclut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCr" of register "VoCursorclut".
**
** Cr Value
** 128: uncoloured
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoCursorclut_ClutCr( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoCursorclut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutAlpha" of register "VoCursorclut".
**
** Alpha value
** 0: transparent
** 255: solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClutAlpha" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVoCursorclut_ClutAlpha( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmVoCursorclut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_VoCursorclutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "SdSecfieldoffset".
**
** This function writes the given value to the register "SdSecfieldoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetSdSecfieldoffset( uint32_t value );
#else
INLINE void FREG_VE_SetSdSecfieldoffset( uint32_t value )
{
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VOffsetTtxF1" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of second field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VOffsetTtxF1" consists of the bits 20..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x001F0000UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdSecfieldoffset_VOffsetTtxF1( uint32_t value );
#else
INLINE void FREG_VE_SetSdSecfieldoffset_VOffsetTtxF1( uint32_t value )
{
    register uint32_t mask = 0x001F0000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VOffsetTtxF0" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of first field
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VOffsetTtxF0" consists of the bits 12..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00001F00UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdSecfieldoffset_VOffsetTtxF0( uint32_t value );
#else
INLINE void FREG_VE_SetSdSecfieldoffset_VOffsetTtxF0( uint32_t value )
{
    register uint32_t mask = 0x00001F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "PixelSyncHorVal" of register "SdSecfieldoffset".
**
** horizontal position of pixels relative to sync pulses
** Should be set to 2 (value important for correct CCIR output)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "PixelSyncHorVal" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdSecfieldoffset_PixelSyncHorVal( uint32_t value );
#else
INLINE void FREG_VE_SetSdSecfieldoffset_PixelSyncHorVal( uint32_t value )
{
    register uint32_t mask = 0x00000060UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VerCount0" of register "SdSecfieldoffset".
**
** ver_count bit(0) value when restarted (ver_count start from 0 or 1)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VerCount0" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdSecfieldoffset_VerCount0( uint32_t value );
#else
INLINE void FREG_VE_SetSdSecfieldoffset_VerCount0( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SecFieldOffset" of register "SdSecfieldoffset".
**
** offset for stop value of line counter for second field.
**  VER_SIZE - 2 + SEC_FIELD_OFFSET
** Recommended setting: 1.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SecFieldOffset" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern void FREG_VE_SetSdSecfieldoffset_SecFieldOffset( uint32_t value );
#else
INLINE void FREG_VE_SetSdSecfieldoffset_SecFieldOffset( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_SdSecfieldoffsetMirror & ~mask;
    FREG_VE_SdSecfieldoffsetMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_SDSECFIELDOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "SdSecfieldoffset".
**
** This function reads the value from the register "SdSecfieldoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdSecfieldoffset( void );
#else
INLINE uint32_t FREG_VE_GetmSdSecfieldoffset( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VOffsetTtxF1" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of second field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VOffsetTtxF1" consists of the bits 20..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x001F0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdSecfieldoffset_VOffsetTtxF1( void );
#else
INLINE uint32_t FREG_VE_GetmSdSecfieldoffset_VOffsetTtxF1( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x001F0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VOffsetTtxF0" of register "SdSecfieldoffset".
**
** Vertical offset for teletext insertion of first field
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VOffsetTtxF0" consists of the bits 12..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00001F00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdSecfieldoffset_VOffsetTtxF0( void );
#else
INLINE uint32_t FREG_VE_GetmSdSecfieldoffset_VOffsetTtxF0( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00001F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "PixelSyncHorVal" of register "SdSecfieldoffset".
**
** horizontal position of pixels relative to sync pulses
** Should be set to 2 (value important for correct CCIR output)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "PixelSyncHorVal" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdSecfieldoffset_PixelSyncHorVal( void );
#else
INLINE uint32_t FREG_VE_GetmSdSecfieldoffset_PixelSyncHorVal( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00000060UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VerCount0" of register "SdSecfieldoffset".
**
** ver_count bit(0) value when restarted (ver_count start from 0 or 1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VerCount0" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdSecfieldoffset_VerCount0( void );
#else
INLINE uint32_t FREG_VE_GetmSdSecfieldoffset_VerCount0( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SecFieldOffset" of register "SdSecfieldoffset".
**
** offset for stop value of line counter for second field.
**  VER_SIZE - 2 + SEC_FIELD_OFFSET
** Recommended setting: 1.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SecFieldOffset" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmSdSecfieldoffset_SecFieldOffset( void );
#else
INLINE uint32_t FREG_VE_GetmSdSecfieldoffset_SecFieldOffset( void )
{
    register uint32_t value = FREG_VE_SdSecfieldoffsetMirror;
    value = ( value & 0x00000007UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Rgbconf".
**
** This function writes the given value to the register "Rgbconf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf( uint32_t value )
{
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Colbar" of register "Rgbconf".
**
** Select for Multiplexer which enables colour Bar (100/100) insertion, see Block Diagram of Colour Encoder
** - '0': no colour bar
** - '1': colour bar on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Colbar" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_Colbar( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_Colbar( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ycrcb" of register "Rgbconf".
**
** Output YCrCb instead of RGB, see Block Diagram of Colour Encoder
** - '0': output analog RGB
** - '1': output analog YCrCb
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ycrcb" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_Ycrcb( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_Ycrcb( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "NtscOn" of register "Rgbconf".
**
** If the sync signal is added to the R, G or B signal, the rise and fall time of the edges is dependent on the colour standard.
** 
** Switch to NTSC edge in sync signal
** - '0': PAL
** - '1': NTSC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "NtscOn" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_NtscOn( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_NtscOn( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BlkOn" of register "Rgbconf".
**
** In standard modes, the RGB De-matrix converts everything which is provided to the input of this block.
**  This bit allows signal blanking during the blanking periods. If the sync signal is inserted, the blanking periods are automatically blanked and this bit has no influence.
** - '0': no blanking of RGB signal
** - '1': blanking enable for RGB signal (during vertical and
** horizontal blanking period 0V is generated.)
** Must be set to 0, if YCRCB = 1
** To allow the adjustment of the brightness (YOFF), this value must be set to 1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BlkOn" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_BlkOn( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_BlkOn( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SynconBlue" of register "Rgbconf".
**
** Insert sync in Blue signal (or Cb), shifted 256 up
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SynconBlue" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_SynconBlue( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_SynconBlue( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SynconGree" of register "Rgbconf".
**
** Insert sync in Green signal (or Y), shifted 256 up
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SynconGree" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_SynconGree( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_SynconGree( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SynconRed" of register "Rgbconf".
**
** Insert sync in Red signal (or Cr), shifted 256 up
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SynconRed" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_SynconRed( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_SynconRed( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RegDelayEn" of register "Rgbconf".
**
** Writing 11 to this register delays the RGB path by a clock period of 7 x 13.
** 5MHz. This allows the adjustment of the physical position of the RGB picture relative to the composite picture.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RegDelayEn" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbconf_RegDelayEn( uint32_t value );
#else
INLINE void FREG_VE_SetRgbconf_RegDelayEn( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    value |= FREG_VE_RgbconfMirror & ~mask;
    FREG_VE_RgbconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Rgbconf".
**
** This function reads the value from the register "Rgbconf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Colbar" of register "Rgbconf".
**
** Select for Multiplexer which enables colour Bar (100/100) insertion, see Block Diagram of Colour Encoder
** - '0': no colour bar
** - '1': colour bar on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Colbar" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_Colbar( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_Colbar( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ycrcb" of register "Rgbconf".
**
** Output YCrCb instead of RGB, see Block Diagram of Colour Encoder
** - '0': output analog RGB
** - '1': output analog YCrCb
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ycrcb" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_Ycrcb( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_Ycrcb( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "NtscOn" of register "Rgbconf".
**
** If the sync signal is added to the R, G or B signal, the rise and fall time of the edges is dependent on the colour standard.
** 
** Switch to NTSC edge in sync signal
** - '0': PAL
** - '1': NTSC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "NtscOn" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_NtscOn( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_NtscOn( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BlkOn" of register "Rgbconf".
**
** In standard modes, the RGB De-matrix converts everything which is provided to the input of this block.
**  This bit allows signal blanking during the blanking periods. If the sync signal is inserted, the blanking periods are automatically blanked and this bit has no influence.
** - '0': no blanking of RGB signal
** - '1': blanking enable for RGB signal (during vertical and
** horizontal blanking period 0V is generated.)
** Must be set to 0, if YCRCB = 1
** To allow the adjustment of the brightness (YOFF), this value must be set to 1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BlkOn" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_BlkOn( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_BlkOn( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SynconBlue" of register "Rgbconf".
**
** Insert sync in Blue signal (or Cb), shifted 256 up
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SynconBlue" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_SynconBlue( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_SynconBlue( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SynconGree" of register "Rgbconf".
**
** Insert sync in Green signal (or Y), shifted 256 up
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SynconGree" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_SynconGree( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_SynconGree( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SynconRed" of register "Rgbconf".
**
** Insert sync in Red signal (or Cr), shifted 256 up
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SynconRed" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_SynconRed( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_SynconRed( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RegDelayEn" of register "Rgbconf".
**
** Writing 11 to this register delays the RGB path by a clock period of 7 x 13.
** 5MHz. This allows the adjustment of the physical position of the RGB picture relative to the composite picture.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RegDelayEn" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbconf_RegDelayEn( void );
#else
INLINE uint32_t FREG_VE_GetmRgbconf_RegDelayEn( void )
{
    register uint32_t value = FREG_VE_RgbconfMirror;
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Rgblum".
**
** This function writes the given value to the register "Rgblum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetRgblum( uint32_t value );
#else
INLINE void FREG_VE_SetRgblum( uint32_t value )
{
    FREG_VE_RgblumMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBLUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBLUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Yoff" of register "Rgblum".
**
** Brightness adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Yoff" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgblum_Yoff( uint32_t value );
#else
INLINE void FREG_VE_SetRgblum_Yoff( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_RgblumMirror & ~mask;
    FREG_VE_RgblumMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBLUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBLUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Yval" of register "Rgblum".
**
** Contrast adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Yval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetRgblum_Yval( uint32_t value );
#else
INLINE void FREG_VE_SetRgblum_Yval( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_RgblumMirror & ~mask;
    FREG_VE_RgblumMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBLUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBLUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Rgblum".
**
** This function reads the value from the register "Rgblum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgblum( void );
#else
INLINE uint32_t FREG_VE_GetmRgblum( void )
{
    register uint32_t value = FREG_VE_RgblumMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Yoff" of register "Rgblum".
**
** Brightness adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Yoff" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgblum_Yoff( void );
#else
INLINE uint32_t FREG_VE_GetmRgblum_Yoff( void )
{
    register uint32_t value = FREG_VE_RgblumMirror;
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Yval" of register "Rgblum".
**
** Contrast adjustment of RGB outputs or Y output in case of YCrCb output mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Yval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgblum_Yval( void );
#else
INLINE uint32_t FREG_VE_GetmRgblum_Yval( void )
{
    register uint32_t value = FREG_VE_RgblumMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Rgbchrom".
**
** This function writes the given value to the register "Rgbchrom".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetRgbchrom( uint32_t value );
#else
INLINE void FREG_VE_SetRgbchrom( uint32_t value )
{
    FREG_VE_RgbchromMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCHROM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCHROM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Crval" of register "Rgbchrom".
**
** Chrominance CR adjustment of RGB output
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Crval" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbchrom_Crval( uint32_t value );
#else
INLINE void FREG_VE_SetRgbchrom_Crval( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_RgbchromMirror & ~mask;
    FREG_VE_RgbchromMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCHROM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCHROM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cbval" of register "Rgbchrom".
**
** Chrominance CB adjustment of RGB output
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cbval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetRgbchrom_Cbval( uint32_t value );
#else
INLINE void FREG_VE_SetRgbchrom_Cbval( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_RgbchromMirror & ~mask;
    FREG_VE_RgbchromMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_RGBCHROM, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_RGBCHROM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Rgbchrom".
**
** This function reads the value from the register "Rgbchrom".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbchrom( void );
#else
INLINE uint32_t FREG_VE_GetmRgbchrom( void )
{
    register uint32_t value = FREG_VE_RgbchromMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Crval" of register "Rgbchrom".
**
** Chrominance CR adjustment of RGB output
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Crval" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbchrom_Crval( void );
#else
INLINE uint32_t FREG_VE_GetmRgbchrom_Crval( void )
{
    register uint32_t value = FREG_VE_RgbchromMirror;
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cbval" of register "Rgbchrom".
**
** Chrominance CB adjustment of RGB output
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cbval" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmRgbchrom_Cbval( void );
#else
INLINE uint32_t FREG_VE_GetmRgbchrom_Cbval( void )
{
    register uint32_t value = FREG_VE_RgbchromMirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Ceconf".
**
** This function writes the given value to the register "Ceconf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf( uint32_t value )
{
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Secam" of register "Ceconf".
**
** Enables the switching on of SECAM Colour Encoder.
** 
** 0: SECAM off
** 1: SECAM on (PAL bit is ignored)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Secam" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Secam( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Secam( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ttxen" of register "Ceconf".
**
** Enables teletext feed through for the Colour Encoder:
** 0: vertical and horizontal blanking period is blanked.
** 
** 1: line 6...22 and 318...335 data feed through is allowed for luminance only. Must be set to 1 in case of teletext re-insertion in the vertical 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ttxen" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Ttxen( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Ttxen( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ipce1sel" of register "Ceconf".
**
** Input selector of Colour Encoder:
** 0: standard YCrCb input
** 1: COLBAR mux out (see block diagram)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ipce1sel" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Ipce1sel( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Ipce1sel( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bwgui" of register "Ceconf".
**
** Stops the generation of colour carrier generation, results in output without color:
** 0: colour on (normal)
** 1: no colour (also for C output)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bwgui" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Bwgui( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Bwgui( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xsyncmx" of register "Ceconf".
**
** Disable the insertion of synchronisation signals to CVBS and Y:
** 0: insertion of synchronisation signals is enabled
** 1: disable synchronisation signal insertion (no sync in CVBS)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xsyncmx" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Xsyncmx( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Xsyncmx( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cydly" of register "Ceconf".
**
** Delay in 27.
** 0MHz cycles of luminance to chrominance or vice versa, dependent on CYSEL:
** Y-delay cydly[2:0] 0...7 cycles of 27MHz
** C-delay cydly[1:0] 0...3 cycles of 27.0MHz, here only the two LSBs are used
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cydly" consists of the bits 10..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000700UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Cydly( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Cydly( uint32_t value )
{
    register uint32_t mask = 0x00000700UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cysel" of register "Ceconf".
**
** Delay luminance or chrominance 0: luminance will be delayed 1: chrominance will be delayed
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cysel" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Cysel( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Cysel( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M3db" of register "Ceconf".
**
** Amplitude of burst in composite and C signal:
** 00: normal,
** 01: burst -3dB,
** 10: +7.
** 2%,
** 11: -7.2%
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M3db" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_M3db( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_M3db( uint32_t value )
{
    register uint32_t mask = 0x00000060UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pal525" of register "Ceconf".
**
** PAL 60 mode:
** 0: normal,
** 1: 525 line PAL, 60Hz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pal525" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Pal525( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Pal525( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pal" of register "Ceconf".
**
** This bit allows the selection of PAL or NTSC mode and has influence to following parameters: colour burst amplitude, colour burst phase, rise/fall time & length of sync pulses, length of a horizontal line, number of lines per field/frame, etc.
**  Please ensu
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pal" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Pal( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Pal( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "M1m0" of register "Ceconf".
**
** Clamping and enlargement of Input signal,
** 00 & 01: normal operation (Y: 16.
** ..235)
** if input value of Y is <=16, value is set to 16
** Y Input value 16...235 is amplified to 256...803
** 10: enlargement mode (Y: 32...235)
** if input value of Y is <=32, value is set to 32
** Y Input value 32...235 is amplified to 256...803
** 11: shrink mode (Y:0...235)
** Y value is feed through, no clamping
** Y Input value 0...235 is amplified to 256...803
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "M1m0" consists of the bits 2..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000006UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_M1m0( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_M1m0( uint32_t value )
{
    register uint32_t mask = 0x00000006UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pslev" of register "Ceconf".
**
** Sync Level for NTSC (for PAL always 20dec = 0x14)
** 0: Sync level for NTSC: 36dec = 0x24
** 1: Sync level for NTSC: 20dec = 0x14
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pslev" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeconf_Pslev( uint32_t value );
#else
INLINE void FREG_VE_SetCeconf_Pslev( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_CeconfMirror & ~mask;
    FREG_VE_CeconfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CECONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CECONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ceconf".
**
** This function reads the value from the register "Ceconf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Secam" of register "Ceconf".
**
** Enables the switching on of SECAM Colour Encoder.
** 
** 0: SECAM off
** 1: SECAM on (PAL bit is ignored)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Secam" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Secam( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Secam( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ttxen" of register "Ceconf".
**
** Enables teletext feed through for the Colour Encoder:
** 0: vertical and horizontal blanking period is blanked.
** 
** 1: line 6...22 and 318...335 data feed through is allowed for luminance only. Must be set to 1 in case of teletext re-insertion in the vertical 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ttxen" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Ttxen( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Ttxen( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ipce1sel" of register "Ceconf".
**
** Input selector of Colour Encoder:
** 0: standard YCrCb input
** 1: COLBAR mux out (see block diagram)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ipce1sel" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Ipce1sel( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Ipce1sel( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bwgui" of register "Ceconf".
**
** Stops the generation of colour carrier generation, results in output without color:
** 0: colour on (normal)
** 1: no colour (also for C output)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bwgui" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Bwgui( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Bwgui( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xsyncmx" of register "Ceconf".
**
** Disable the insertion of synchronisation signals to CVBS and Y:
** 0: insertion of synchronisation signals is enabled
** 1: disable synchronisation signal insertion (no sync in CVBS)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xsyncmx" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Xsyncmx( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Xsyncmx( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cydly" of register "Ceconf".
**
** Delay in 27.
** 0MHz cycles of luminance to chrominance or vice versa, dependent on CYSEL:
** Y-delay cydly[2:0] 0...7 cycles of 27MHz
** C-delay cydly[1:0] 0...3 cycles of 27.0MHz, here only the two LSBs are used
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cydly" consists of the bits 10..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000700UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Cydly( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Cydly( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000700UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cysel" of register "Ceconf".
**
** Delay luminance or chrominance 0: luminance will be delayed 1: chrominance will be delayed
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cysel" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Cysel( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Cysel( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M3db" of register "Ceconf".
**
** Amplitude of burst in composite and C signal:
** 00: normal,
** 01: burst -3dB,
** 10: +7.
** 2%,
** 11: -7.2%
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M3db" consists of the bits 6..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000060UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_M3db( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_M3db( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000060UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pal525" of register "Ceconf".
**
** PAL 60 mode:
** 0: normal,
** 1: 525 line PAL, 60Hz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pal525" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Pal525( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Pal525( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pal" of register "Ceconf".
**
** This bit allows the selection of PAL or NTSC mode and has influence to following parameters: colour burst amplitude, colour burst phase, rise/fall time & length of sync pulses, length of a horizontal line, number of lines per field/frame, etc.
**  Please ensu
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pal" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Pal( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Pal( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "M1m0" of register "Ceconf".
**
** Clamping and enlargement of Input signal,
** 00 & 01: normal operation (Y: 16.
** ..235)
** if input value of Y is <=16, value is set to 16
** Y Input value 16...235 is amplified to 256...803
** 10: enlargement mode (Y: 32...235)
** if input value of Y is <=32, value is set to 32
** Y Input value 32...235 is amplified to 256...803
** 11: shrink mode (Y:0...235)
** Y value is feed through, no clamping
** Y Input value 0...235 is amplified to 256...803
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "M1m0" consists of the bits 2..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000006UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_M1m0( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_M1m0( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000006UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pslev" of register "Ceconf".
**
** Sync Level for NTSC (for PAL always 20dec = 0x14)
** 0: Sync level for NTSC: 36dec = 0x24
** 1: Sync level for NTSC: 20dec = 0x14
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pslev" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeconf_Pslev( void );
#else
INLINE uint32_t FREG_VE_GetmCeconf_Pslev( void )
{
    register uint32_t value = FREG_VE_CeconfMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Ceburstint".
**
** This function writes the given value to the register "Ceburstint".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstint( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstint( uint32_t value )
{
    FREG_VE_CeburstintMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTINT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTINT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pal60mEn" of register "Ceburstint".
**
** Enable PAL 60/M correction.
**  Should be set to 1.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pal60mEn" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstint_Pal60mEn( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstint_Pal60mEn( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_CeburstintMirror & ~mask;
    FREG_VE_CeburstintMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTINT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTINT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fscint" of register "Ceburstint".
**
** Integer value of colour carrier frequency generator (see formula below)
** for PAL B/G: 0x541 = 1345
** for NTSC M: 0x43E = 1086
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fscint" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstint_Fscint( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstint_Fscint( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_CeburstintMirror & ~mask;
    FREG_VE_CeburstintMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTINT, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTINT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ceburstint".
**
** This function reads the value from the register "Ceburstint".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstint( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstint( void )
{
    register uint32_t value = FREG_VE_CeburstintMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pal60mEn" of register "Ceburstint".
**
** Enable PAL 60/M correction.
**  Should be set to 1.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pal60mEn" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstint_Pal60mEn( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstint_Pal60mEn( void )
{
    register uint32_t value = FREG_VE_CeburstintMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fscint" of register "Ceburstint".
**
** Integer value of colour carrier frequency generator (see formula below)
** for PAL B/G: 0x541 = 1345
** for NTSC M: 0x43E = 1086
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fscint" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstint_Fscint( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstint_Fscint( void )
{
    register uint32_t value = FREG_VE_CeburstintMirror;
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Ceburstfra1".
**
** This function writes the given value to the register "Ceburstfra1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstfra1( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstfra1( uint32_t value )
{
    FREG_VE_Ceburstfra1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fscfra238" of register "Ceburstfra1".
**
** Fractional value of colour carrier frequency generator bit 23 down to 8 (see formula below)
** for PAL B/G: 0x3159
** for NTSC M: 0x0F7A
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fscfra238" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstfra1_Fscfra238( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstfra1_Fscfra238( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ceburstfra1Mirror & ~mask;
    FREG_VE_Ceburstfra1Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA1, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ceburstfra1".
**
** This function reads the value from the register "Ceburstfra1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstfra1( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstfra1( void )
{
    register uint32_t value = FREG_VE_Ceburstfra1Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fscfra238" of register "Ceburstfra1".
**
** Fractional value of colour carrier frequency generator bit 23 down to 8 (see formula below)
** for PAL B/G: 0x3159
** for NTSC M: 0x0F7A
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fscfra238" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstfra1_Fscfra238( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstfra1_Fscfra238( void )
{
    register uint32_t value = FREG_VE_Ceburstfra1Mirror;
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Ceburstfra2".
**
** This function writes the given value to the register "Ceburstfra2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstfra2( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstfra2( uint32_t value )
{
    FREG_VE_Ceburstfra2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Fscfra70" of register "Ceburstfra2".
**
** Fractional value of burst frequency generator bits 7 down to 0 (see formula below)
** for PAL B/G: 0x68
** for NTSC M: 0xDF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Fscfra70" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetCeburstfra2_Fscfra70( uint32_t value );
#else
INLINE void FREG_VE_SetCeburstfra2_Fscfra70( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ceburstfra2Mirror & ~mask;
    FREG_VE_Ceburstfra2Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CEBURSTFRA2, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CEBURSTFRA2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ceburstfra2".
**
** This function reads the value from the register "Ceburstfra2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstfra2( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstfra2( void )
{
    register uint32_t value = FREG_VE_Ceburstfra2Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Fscfra70" of register "Ceburstfra2".
**
** Fractional value of burst frequency generator bits 7 down to 0 (see formula below)
** for PAL B/G: 0x68
** for NTSC M: 0xDF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Fscfra70" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCeburstfra2_Fscfra70( void );
#else
INLINE uint32_t FREG_VE_GetmCeburstfra2_Fscfra70( void )
{
    register uint32_t value = FREG_VE_Ceburstfra2Mirror;
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "DacPd".
**
** This function writes the given value to the register "DacPd".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd( uint32_t value )
{
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CeFilterFlag" of register "DacPd".
**
** 0: direct output from Color Encoder to DACs (27MHz)
** 1: interpolated output from Color Encoder to DACs (2-tap)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CeFilterFlag" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_CeFilterFlag( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_CeFilterFlag( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac6" of register "DacPd".
**
** Power down of DAC6:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac6" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac6( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac6( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac5" of register "DacPd".
**
** Power down of DAC5:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac5" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac5( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac5( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac4" of register "DacPd".
**
** Power down of DAC4 and VREF_DAC_4_6:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac4" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac4( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac4( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac3" of register "DacPd".
**
** Power down of DAC3  and VREF3_DAC_3:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac3" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac3( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac3( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac2" of register "DacPd".
**
** Power down of DAC2:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac2" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac2( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac2( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac1" of register "DacPd".
**
** Power down of DAC1:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac1( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac1( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pddac0" of register "DacPd".
**
** Power down of DAC0 and VREF_DAC_0_2:
** 0: no power down,
** 1: power down
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pddac0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VE_SetDacPd_Pddac0( uint32_t value );
#else
INLINE void FREG_VE_SetDacPd_Pddac0( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_DacPdMirror & ~mask;
    FREG_VE_DacPdMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_DACPD, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_DACPD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "DacPd".
**
** This function reads the value from the register "DacPd".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CeFilterFlag" of register "DacPd".
**
** 0: direct output from Color Encoder to DACs (27MHz)
** 1: interpolated output from Color Encoder to DACs (2-tap)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CeFilterFlag" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_CeFilterFlag( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_CeFilterFlag( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac6" of register "DacPd".
**
** Power down of DAC6:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac6" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac6( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac6( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac5" of register "DacPd".
**
** Power down of DAC5:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac5" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac5( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac5( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac4" of register "DacPd".
**
** Power down of DAC4 and VREF_DAC_4_6:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac4" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac4( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac4( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac3" of register "DacPd".
**
** Power down of DAC3  and VREF3_DAC_3:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac3" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac3( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac3( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac2" of register "DacPd".
**
** Power down of DAC2:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac2" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac2( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac2( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac1" of register "DacPd".
**
** Power down of DAC1:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac1" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac1( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac1( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pddac0" of register "DacPd".
**
** Power down of DAC0 and VREF_DAC_0_2:
** 0: no power down,
** 1: power down
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pddac0" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmDacPd_Pddac0( void );
#else
INLINE uint32_t FREG_VE_GetmDacPd_Pddac0( void )
{
    register uint32_t value = FREG_VE_DacPdMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Enc656wss".
**
** This function writes the given value to the register "Enc656wss".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss( uint32_t value )
{
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WssPostTimingMode" of register "Enc656wss".
**
** 1 = blanking after wss signal is conforming to standard
** 0 = old blanking mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WssPostTimingMode" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_WssPostTimingMode( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_WssPostTimingMode( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Clk27Inv" of register "Enc656wss".
**
** Invert 27.
** 0MHz for ITU-656 Output
** 0: not inverted
** 1: inverted
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Clk27Inv" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_Clk27Inv( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_Clk27Inv( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WssTimingMode" of register "Enc656wss".
**
** 1 = new timing mode (correct horizontal timing)
** 0 = old timing mode (output frequency is slightly wrong)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WssTimingMode" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_WssTimingMode( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_WssTimingMode( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "WssMode" of register "Enc656wss".
**
** WSS insertion: 0: WSS insertion off, 1: WSS insertion on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "WssMode" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_WssMode( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_WssMode( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ccmask" of register "Enc656wss".
**
** Masking input Y & C data of line 21 and line 284 (for NTSC only)
** 0: normal operation,
** 1: masking enabled
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ccmask" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_Ccmask( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_Ccmask( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "VbidEn" of register "Enc656wss".
**
** VBID insertion for line 20 and line 283 (for NTSC only)
** 0: VBID insertion off
** 1: VBID insertion on
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VbidEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_VbidEn( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_VbidEn( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CcM" of register "Enc656wss".
**
** Closed caption off/on (for NTSC only)
** 00: closed caption insertion disabled
** 01: closed caption insertion enable for line 21
** 10: closed caption insertion enable for line 284
** 11: closed caption insertion enable for line 21 and line 284
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CcM" consists of the bits 7..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x000000C0UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_CcM( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_CcM( uint32_t value )
{
    register uint32_t mask = 0x000000C0UL;
    value = ( value << 6 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Iprgbsel" of register "Enc656wss".
**
** Input selector for RGB conversion
** 00: YCbCr1
** 10:Color bar 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Iprgbsel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_Iprgbsel( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_Iprgbsel( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ip656sel" of register "Enc656wss".
**
** Input selector for ITU-R656 Encoder
** 0: YCbCr1
** 1:Color bar 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ip656sel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VE_SetEnc656wss_Ip656sel( uint32_t value );
#else
INLINE void FREG_VE_SetEnc656wss_Ip656sel( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Enc656wssMirror & ~mask;
    FREG_VE_Enc656wssMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_ENC656WSS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_ENC656WSS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Enc656wss".
**
** This function reads the value from the register "Enc656wss".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WssPostTimingMode" of register "Enc656wss".
**
** 1 = blanking after wss signal is conforming to standard
** 0 = old blanking mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WssPostTimingMode" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_WssPostTimingMode( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_WssPostTimingMode( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Clk27Inv" of register "Enc656wss".
**
** Invert 27.
** 0MHz for ITU-656 Output
** 0: not inverted
** 1: inverted
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Clk27Inv" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_Clk27Inv( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_Clk27Inv( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WssTimingMode" of register "Enc656wss".
**
** 1 = new timing mode (correct horizontal timing)
** 0 = old timing mode (output frequency is slightly wrong)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WssTimingMode" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_WssTimingMode( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_WssTimingMode( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "WssMode" of register "Enc656wss".
**
** WSS insertion: 0: WSS insertion off, 1: WSS insertion on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "WssMode" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_WssMode( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_WssMode( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ccmask" of register "Enc656wss".
**
** Masking input Y & C data of line 21 and line 284 (for NTSC only)
** 0: normal operation,
** 1: masking enabled
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ccmask" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_Ccmask( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_Ccmask( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "VbidEn" of register "Enc656wss".
**
** VBID insertion for line 20 and line 283 (for NTSC only)
** 0: VBID insertion off
** 1: VBID insertion on
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VbidEn" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_VbidEn( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_VbidEn( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CcM" of register "Enc656wss".
**
** Closed caption off/on (for NTSC only)
** 00: closed caption insertion disabled
** 01: closed caption insertion enable for line 21
** 10: closed caption insertion enable for line 284
** 11: closed caption insertion enable for line 21 and line 284
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CcM" consists of the bits 7..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x000000C0UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_CcM( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_CcM( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x000000C0UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Iprgbsel" of register "Enc656wss".
**
** Input selector for RGB conversion
** 00: YCbCr1
** 10:Color bar 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Iprgbsel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_Iprgbsel( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_Iprgbsel( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ip656sel" of register "Enc656wss".
**
** Input selector for ITU-R656 Encoder
** 0: YCbCr1
** 1:Color bar 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ip656sel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmEnc656wss_Ip656sel( void );
#else
INLINE uint32_t FREG_VE_GetmEnc656wss_Ip656sel( void )
{
    register uint32_t value = FREG_VE_Enc656wssMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Ccline21".
**
** This function writes the given value to the register "Ccline21".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetCcline21( uint32_t value );
#else
INLINE void FREG_VE_SetCcline21( uint32_t value )
{
    FREG_VE_Ccline21Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE21, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE21)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "L21c2" of register "Ccline21".
**
** Closed caption character 2 of line 21
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L21c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/
extern void FREG_VE_SetCcline21_L21c2( uint32_t value );
#else
INLINE void FREG_VE_SetCcline21_L21c2( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_Ccline21Mirror & ~mask;
    FREG_VE_Ccline21Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE21, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE21)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "L21c1" of register "Ccline21".
**
** Closed caption character 1 of line 21
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L21c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetCcline21_L21c1( uint32_t value );
#else
INLINE void FREG_VE_SetCcline21_L21c1( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ccline21Mirror & ~mask;
    FREG_VE_Ccline21Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE21, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE21)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ccline21".
**
** This function reads the value from the register "Ccline21".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCcline21( void );
#else
INLINE uint32_t FREG_VE_GetmCcline21( void )
{
    register uint32_t value = FREG_VE_Ccline21Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "L21c2" of register "Ccline21".
**
** Closed caption character 2 of line 21
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L21c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCcline21_L21c2( void );
#else
INLINE uint32_t FREG_VE_GetmCcline21_L21c2( void )
{
    register uint32_t value = FREG_VE_Ccline21Mirror;
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "L21c1" of register "Ccline21".
**
** Closed caption character 1 of line 21
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L21c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCcline21_L21c1( void );
#else
INLINE uint32_t FREG_VE_GetmCcline21_L21c1( void )
{
    register uint32_t value = FREG_VE_Ccline21Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Ccline284".
**
** This function writes the given value to the register "Ccline284".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetCcline284( uint32_t value );
#else
INLINE void FREG_VE_SetCcline284( uint32_t value )
{
    FREG_VE_Ccline284Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE284, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE284)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "L284c2" of register "Ccline284".
**
** Closed caption character 2 of line 284
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L284c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/
extern void FREG_VE_SetCcline284_L284c2( uint32_t value );
#else
INLINE void FREG_VE_SetCcline284_L284c2( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VE_Ccline284Mirror & ~mask;
    FREG_VE_Ccline284Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE284, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE284)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "L284c1" of register "Ccline284".
**
** Closed caption character 1 of line 284
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "L284c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VE_SetCcline284_L284c1( uint32_t value );
#else
INLINE void FREG_VE_SetCcline284_L284c1( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_Ccline284Mirror & ~mask;
    FREG_VE_Ccline284Mirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_CCLINE284, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_CCLINE284)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Ccline284".
**
** This function reads the value from the register "Ccline284".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCcline284( void );
#else
INLINE uint32_t FREG_VE_GetmCcline284( void )
{
    register uint32_t value = FREG_VE_Ccline284Mirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "L284c2" of register "Ccline284".
**
** Closed caption character 2 of line 284
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L284c2" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCcline284_L284c2( void );
#else
INLINE uint32_t FREG_VE_GetmCcline284_L284c2( void )
{
    register uint32_t value = FREG_VE_Ccline284Mirror;
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "L284c1" of register "Ccline284".
**
** Closed caption character 1 of line 284
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "L284c1" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmCcline284_L284c1( void );
#else
INLINE uint32_t FREG_VE_GetmCcline284_L284c1( void )
{
    register uint32_t value = FREG_VE_Ccline284Mirror;
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vbidwords".
**
** This function writes the given value to the register "Vbidwords".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetVbidwords( uint32_t value );
#else
INLINE void FREG_VE_SetVbidwords( uint32_t value )
{
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "EnSecamTtx" of register "Vbidwords".
**
** Use PAL horizontal blanking mode for SECAM signals to allow TTX insertion in SECAM signals.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "EnSecamTtx" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_VE_SetVbidwords_EnSecamTtx( uint32_t value );
#else
INLINE void FREG_VE_SetVbidwords_EnSecamTtx( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vbidw2" of register "Vbidwords".
**
** VBID word 2 (CRCC is generated internal)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vbidw2" consists of the bits 13..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00003FC0UL
**
********************************************************************************
*/
extern void FREG_VE_SetVbidwords_Vbidw2( uint32_t value );
#else
INLINE void FREG_VE_SetVbidwords_Vbidw2( uint32_t value )
{
    register uint32_t mask = 0x00003FC0UL;
    value = ( value << 6 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vbidw1" of register "Vbidwords".
**
** VBID word 1 (CRCC is generated internal)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vbidw1" consists of the bits 5..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000003CUL
**
********************************************************************************
*/
extern void FREG_VE_SetVbidwords_Vbidw1( uint32_t value );
#else
INLINE void FREG_VE_SetVbidwords_Vbidw1( uint32_t value )
{
    register uint32_t mask = 0x0000003CUL;
    value = ( value << 2 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vbidw0" of register "Vbidwords".
**
** VBID word 0 (CRCC is generated internal)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vbidw0" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_VE_SetVbidwords_Vbidw0( uint32_t value );
#else
INLINE void FREG_VE_SetVbidwords_Vbidw0( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_VbidwordsMirror & ~mask;
    FREG_VE_VbidwordsMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VBIDWORDS, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VBIDWORDS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vbidwords".
**
** This function reads the value from the register "Vbidwords".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVbidwords( void );
#else
INLINE uint32_t FREG_VE_GetmVbidwords( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "EnSecamTtx" of register "Vbidwords".
**
** Use PAL horizontal blanking mode for SECAM signals to allow TTX insertion in SECAM signals.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "EnSecamTtx" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVbidwords_EnSecamTtx( void );
#else
INLINE uint32_t FREG_VE_GetmVbidwords_EnSecamTtx( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vbidw2" of register "Vbidwords".
**
** VBID word 2 (CRCC is generated internal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vbidw2" consists of the bits 13..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00003FC0UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVbidwords_Vbidw2( void );
#else
INLINE uint32_t FREG_VE_GetmVbidwords_Vbidw2( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x00003FC0UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vbidw1" of register "Vbidwords".
**
** VBID word 1 (CRCC is generated internal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vbidw1" consists of the bits 5..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000003CUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVbidwords_Vbidw1( void );
#else
INLINE uint32_t FREG_VE_GetmVbidwords_Vbidw1( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x0000003CUL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vbidw0" of register "Vbidwords".
**
** VBID word 0 (CRCC is generated internal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vbidw0" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmVbidwords_Vbidw0( void );
#else
INLINE uint32_t FREG_VE_GetmVbidwords_Vbidw0( void )
{
    register uint32_t value = FREG_VE_VbidwordsMirror;
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Wssdata".
**
** This function writes the given value to the register "Wssdata".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetWssdata( uint32_t value );
#else
INLINE void FREG_VE_SetWssdata( uint32_t value )
{
    FREG_VE_WssdataMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_WSSDATA, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_WSSDATA)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wssword" of register "Wssdata".
**
** Wide Screen Signalling Data
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wssword" consists of the bits 13..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00003FFFUL
**
********************************************************************************
*/
extern void FREG_VE_SetWssdata_Wssword( uint32_t value );
#else
INLINE void FREG_VE_SetWssdata_Wssword( uint32_t value )
{
    register uint32_t mask = 0x00003FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_WssdataMirror & ~mask;
    FREG_VE_WssdataMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_WSSDATA, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_WSSDATA)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Wssdata".
**
** This function reads the value from the register "Wssdata".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmWssdata( void );
#else
INLINE uint32_t FREG_VE_GetmWssdata( void )
{
    register uint32_t value = FREG_VE_WssdataMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wssword" of register "Wssdata".
**
** Wide Screen Signalling Data
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wssword" consists of the bits 13..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00003FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmWssdata_Wssword( void );
#else
INLINE uint32_t FREG_VE_GetmWssdata_Wssword( void )
{
    register uint32_t value = FREG_VE_WssdataMirror;
    value = ( value & 0x00003FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "LutConf".
**
** This function writes the given value to the register "LutConf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetLutConf( uint32_t value );
#else
INLINE void FREG_VE_SetLutConf( uint32_t value )
{
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RgbLutEn" of register "LutConf".
**
** 0: RGB output without LUTs
** 1: RGB output with LUTs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RgbLutEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_VE_SetLutConf_RgbLutEn( uint32_t value );
#else
INLINE void FREG_VE_SetLutConf_RgbLutEn( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    value |= FREG_VE_LutConfMirror & ~mask;
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "LutSel" of register "LutConf".
**
** 0: YCrCb input for LUTs
** 1: RGB input for LUTs
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LutSel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VE_SetLutConf_LutSel( uint32_t value );
#else
INLINE void FREG_VE_SetLutConf_LutSel( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    value |= FREG_VE_LutConfMirror & ~mask;
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "LutEn" of register "LutConf".
**
** 0: without Look-Up-Tables
** 1: with Look-Up-Tables for YCrCb  or RGB
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LutEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VE_SetLutConf_LutEn( uint32_t value );
#else
INLINE void FREG_VE_SetLutConf_LutEn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutConfMirror & ~mask;
    FREG_VE_LutConfMirror = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "LutConf".
**
** This function reads the value from the register "LutConf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutConf( void );
#else
INLINE uint32_t FREG_VE_GetmLutConf( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RgbLutEn" of register "LutConf".
**
** 0: RGB output without LUTs
** 1: RGB output with LUTs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RgbLutEn" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutConf_RgbLutEn( void );
#else
INLINE uint32_t FREG_VE_GetmLutConf_RgbLutEn( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LutSel" of register "LutConf".
**
** 0: YCrCb input for LUTs
** 1: RGB input for LUTs
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LutSel" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutConf_LutSel( void );
#else
INLINE uint32_t FREG_VE_GetmLutConf_LutSel( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LutEn" of register "LutConf".
**
** 0: without Look-Up-Tables
** 1: with Look-Up-Tables for YCrCb  or RGB
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LutEn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutConf_LutEn( void );
#else
INLINE uint32_t FREG_VE_GetmLutConf_LutEn( void )
{
    register uint32_t value = FREG_VE_LutConfMirror;
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "LutY".
**
** This function writes the given value to the index-th entry of the register
** array LutY.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetLutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetLutY( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_LutYMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTY+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTY+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "LutY".
**
** Y or R Value (unsigned.
**  Note in case of YCrCb: output values cover the 10 bit DAC range including sync levels.)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetLutY_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetLutY_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutYMirror[index] & ~mask;
    FREG_VE_LutYMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTY+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTY+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "LutY".
**
** This function reads the value from the index-th entry of the register
** array LutY.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutY( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmLutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutYMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "LutY".
**
** Y or R Value (unsigned.
**  Note in case of YCrCb: output values cover the 10 bit DAC range including sync levels.)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutY_Data( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmLutY_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutYMirror[index];
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "LutCr".
**
** This function writes the given value to the index-th entry of the register
** array LutCr.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetLutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetLutCr( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_LutCrMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCR+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "LutCr".
**
** CB or G Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetLutCr_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetLutCr_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutCrMirror[index] & ~mask;
    FREG_VE_LutCrMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCR+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCR+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "LutCr".
**
** This function reads the value from the index-th entry of the register
** array LutCr.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutCr( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmLutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCrMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "LutCr".
**
** CB or G Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutCr_Data( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmLutCr_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCrMirror[index];
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "LutCb".
**
** This function writes the given value to the index-th entry of the register
** array LutCb.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetLutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetLutCb( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VE_LutCbMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCB+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "LutCb".
**
** CR or B Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetLutCb_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetLutCb_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VE_LutCbMirror[index] & ~mask;
    FREG_VE_LutCbMirror[index] = value;
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_LUTCB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_LUTCB+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "LutCb".
**
** This function reads the value from the index-th entry of the register
** array LutCb.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutCb( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmLutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCbMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "LutCb".
**
** CR or B Value (In case of RGB this value is interpreted as unsigned.
**  In case of YCrCb this value is interpreted as signed (0 = no color)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetmLutCb_Data( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetmLutCb_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VE_LutCbMirror[index];
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "VoMixyuvrgb".
**
** This function writes the given value to the index-th entry of the register
** array VoMixyuvrgb.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetVoMixyuvrgb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoMixyuvrgb( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXYUVRGB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "VoMixyuvrgb".
**
** YUV2RGB conversion matrix values
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetVoMixyuvrgb_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoMixyuvrgb_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXYUVRGB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "VoMixyuvrgb".
**
** This function reads the value from the index-th entry of the register
** array VoMixyuvrgb.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetVoMixyuvrgb( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetVoMixyuvrgb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "VoMixyuvrgb".
**
** YUV2RGB conversion matrix values
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetVoMixyuvrgb_Data( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetVoMixyuvrgb_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXYUVRGB+(index*0x4)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "VoMixrgbyuv".
**
** This function writes the given value to the index-th entry of the register
** array VoMixrgbyuv.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VE_SetVoMixrgbyuv( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoMixrgbyuv( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXRGBYUV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "VoMixrgbyuv".
**
** RGB2YUV conversion matrix values
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VE_SetVoMixrgbyuv_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VE_SetVoMixrgbyuv_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VE_ENABLE_DEBUG_PRINT == 1
        FREG_VE_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VE", FREG_VE_VOMIXRGBYUV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "VoMixrgbyuv".
**
** This function reads the value from the index-th entry of the register
** array VoMixrgbyuv.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetVoMixrgbyuv( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetVoMixrgbyuv( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "VoMixrgbyuv".
**
** RGB2YUV conversion matrix values
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VE_GetVoMixrgbyuv_Data( uint32_t index );
#else
INLINE uint32_t FREG_VE_GetVoMixrgbyuv_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VE_VOMIXRGBYUV+(index*0x4)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

/*!
********************************************************************************
**
** \brief Initializes the "VE" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
extern void FREG_VE_Init( void );

#endif
