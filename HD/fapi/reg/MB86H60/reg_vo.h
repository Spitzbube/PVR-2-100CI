/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_vo.h
**
** \brief     VO access functions
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
#if !defined(FREG_VO_H)
#define FREG_VO_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_VO_ENABLE_DEBUG_PRINT   0
#define FREG_VO_DEBUG_PRINT_FUNCTION printf

#if FREG_VO_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_VO_FRAMOFFSET                       FIO_ADDRESS(VO,0xCB000004UL)
#define FREG_VO_VOVSTARTPOS                      FIO_ADDRESS(VO,0xCB000008UL)
#define FREG_VO_VOHSTARTPOS                      FIO_ADDRESS(VO,0xCB00000CUL)
#define FREG_VO_VOHSIZE                          FIO_ADDRESS(VO,0xCB000010UL)
#define FREG_VO_VOBITPERPIXEL                    FIO_ADDRESS(VO,0xCB000014UL)
#define FREG_VO_VOHORNUM                         FIO_ADDRESS(VO,0xCB00001CUL)
#define FREG_VO_VOHORDENUM                       FIO_ADDRESS(VO,0xCB000020UL)
#define FREG_VO_VOVERNUM                         FIO_ADDRESS(VO,0xCB000024UL)
#define FREG_VO_VOVERDENUM                       FIO_ADDRESS(VO,0xCB000028UL)
#define FREG_VO_VOHORDISPPIXEL                   FIO_ADDRESS(VO,0xCB00002CUL)
#define FREG_VO_VOHORREADPIXEL                   FIO_ADDRESS(VO,0xCB000030UL)
#define FREG_VO_VOINITIALSHIFT                   FIO_ADDRESS(VO,0xCB000034UL)
#define FREG_VO_VOLAYERENABLE                    FIO_ADDRESS(VO,0xCB000040UL)
#define FREG_VO_DISPRESTART                      FIO_ADDRESS(VO,0xCB010000UL)
#define FREG_VO_DISPHORLL                        FIO_ADDRESS(VO,0xCB010004UL)
#define FREG_VO_DISPVERSIZE                      FIO_ADDRESS(VO,0xCB010008UL)
#define FREG_VO_DISPVERCFG                       FIO_ADDRESS(VO,0xCB01000CUL)
#define FREG_VO_DISPVOVERSYNC                    FIO_ADDRESS(VO,0xCB010010UL)
#define FREG_VO_DISPVOHORSTARTSTOP               FIO_ADDRESS(VO,0xCB010014UL)
#define FREG_VO_DISPVOVERSTARTSTOP               FIO_ADDRESS(VO,0xCB010018UL)
#define FREG_VO_DISPOSD1HORSTARTSTOP             FIO_ADDRESS(VO,0xCB01001CUL)
#define FREG_VO_DISPOSD1VERSTARTSTOP             FIO_ADDRESS(VO,0xCB010020UL)
#define FREG_VO_DISPOSD2HORSTARTSTOP             FIO_ADDRESS(VO,0xCB010024UL)
#define FREG_VO_DISPOSD2VERSTARTSTOP             FIO_ADDRESS(VO,0xCB010028UL)
#define FREG_VO_DISPOSD3HORSTARTSTOP             FIO_ADDRESS(VO,0xCB01002CUL)
#define FREG_VO_DISPOSD3VERSTARTSTOP             FIO_ADDRESS(VO,0xCB010030UL)
#define FREG_VO_DISPHDMIDEHORSTARTSTOP           FIO_ADDRESS(VO,0xCB010034UL)
#define FREG_VO_DISPHDMIDEVERSTARTSTOP           FIO_ADDRESS(VO,0xCB010038UL)
#define FREG_VO_DISPCVBSHORSTARTSTOP             FIO_ADDRESS(VO,0xCB010040UL)
#define FREG_VO_DISPCVBSVERSTARTSTOP             FIO_ADDRESS(VO,0xCB010044UL)
#define FREG_VO_DISPBACKGROUND                   FIO_ADDRESS(VO,0xCB010080UL)
#define FREG_VO_VOHFLT                           FIO_ADDRESS(VO,0xCB002000UL)
#define FREG_VO_OSD1HFLT                         FIO_ADDRESS(VO,0xCB006000UL)
#define FREG_VO_OSD2HFLT                         FIO_ADDRESS(VO,0xCB00A000UL)
#define FREG_VO_SDHFLT                           FIO_ADDRESS(VO,0xCB012100UL)
#define FREG_VO_DISPSYNCHORSTARTSTOP             FIO_ADDRESS(VO,0xCB01004CUL)
#define FREG_VO_DISPSYNCHOR1STARTSTOP            FIO_ADDRESS(VO,0xCB010050UL)
#define FREG_VO_DISPSYNCVER1STARTSTOP            FIO_ADDRESS(VO,0xCB010054UL)
#define FREG_VO_DISPSYNCHOR2STARTSTOP            FIO_ADDRESS(VO,0xCB010058UL)
#define FREG_VO_DISPSYNCVER2STARTSTOP            FIO_ADDRESS(VO,0xCB01005CUL)
#define FREG_VO_DISPVEHDSYNC                     FIO_ADDRESS(VO,0xCB010060UL)
#define FREG_VO_DISPSTC0                         FIO_ADDRESS(VO,0xCB010064UL)
#define FREG_VO_DISPSTC1                         FIO_ADDRESS(VO,0xCB010068UL)
#define FREG_VO_DISPIRQ0                         FIO_ADDRESS(VO,0xCB010070UL)
#define FREG_VO_DISPIRQ1                         FIO_ADDRESS(VO,0xCB010074UL)
#define FREG_VO_DISPIRQ2                         FIO_ADDRESS(VO,0xCB010078UL)
#define FREG_VO_DISPIRQCTRL                      FIO_ADDRESS(VO,0xCB01007CUL)
#define FREG_VO_DISPDACHDMICTRL                  FIO_ADDRESS(VO,0xCB010084UL)
#define FREG_VO_DISPMIXCONF                      FIO_ADDRESS(VO,0xCB010088UL)
#define FREG_VO_DISPMIXCONFENABLE                FIO_ADDRESS(VO,0xCB01008CUL)
#define FREG_VO_DISPCRCY                         FIO_ADDRESS(VO,0xCB010090UL)
#define FREG_VO_DISPCRCCR                        FIO_ADDRESS(VO,0xCB010094UL)
#define FREG_VO_DISPCRCCB                        FIO_ADDRESS(VO,0xCB010098UL)
#define FREG_VO_DISPFRAMECOUNTER                 FIO_ADDRESS(VO,0xCB01009CUL)
#define FREG_VO_DISPPICPOS                       FIO_ADDRESS(VO,0xCB0100A0UL)
#define FREG_VO_SDPATHCONFIG                     FIO_ADDRESS(VO,0xCB00C048UL)
#define FREG_VO_VOFILTERMODE                     FIO_ADDRESS(VO,0xCB000038UL)
#define FREG_VO_VOMODE                           FIO_ADDRESS(VO,0xCB000044UL)
#define FREG_VO_OSDGLOBALOFFSET                  FIO_ADDRESS(VO,0xCB004000UL)
#define FREG_VO_OSDHSIZE                         FIO_ADDRESS(VO,0xCB004010UL)
#define FREG_VO_OSDBITPERPIXEL                   FIO_ADDRESS(VO,0xCB004014UL)
#define FREG_VO_OSDHORNUM                        FIO_ADDRESS(VO,0xCB00401CUL)
#define FREG_VO_OSDHORDENUM                      FIO_ADDRESS(VO,0xCB004020UL)
#define FREG_VO_OSDVERNUM                        FIO_ADDRESS(VO,0xCB004024UL)
#define FREG_VO_OSDVERDENUM                      FIO_ADDRESS(VO,0xCB004028UL)
#define FREG_VO_OSDHORDISPPIXEL                  FIO_ADDRESS(VO,0xCB00402CUL)
#define FREG_VO_OSDHORREADPIXEL                  FIO_ADDRESS(VO,0xCB004030UL)
#define FREG_VO_OSDINITIALSHIFT                  FIO_ADDRESS(VO,0xCB004034UL)
#define FREG_VO_OSDFILTERMODE                    FIO_ADDRESS(VO,0xCB004038UL)
#define FREG_VO_LAYERENABLE                      FIO_ADDRESS(VO,0xCB004040UL)
#define FREG_VO_OSDALPHA1                        FIO_ADDRESS(VO,0xCB004048UL)
#define FREG_VO_OSDALPHA2                        FIO_ADDRESS(VO,0xCB00404CUL)
#define FREG_VO_OSDRGBYUV11                      FIO_ADDRESS(VO,0xCB004050UL)
#define FREG_VO_OSDRGBYUV12                      FIO_ADDRESS(VO,0xCB004054UL)
#define FREG_VO_OSDRGBYUV13                      FIO_ADDRESS(VO,0xCB004058UL)
#define FREG_VO_OSDRGBYUV14                      FIO_ADDRESS(VO,0xCB00405CUL)
#define FREG_VO_OSDRGBYUV21                      FIO_ADDRESS(VO,0xCB004060UL)
#define FREG_VO_OSDRGBYUV22                      FIO_ADDRESS(VO,0xCB004064UL)
#define FREG_VO_OSDRGBYUV23                      FIO_ADDRESS(VO,0xCB004068UL)
#define FREG_VO_OSDRGBYUV24                      FIO_ADDRESS(VO,0xCB00406CUL)
#define FREG_VO_OSDRGBYUV31                      FIO_ADDRESS(VO,0xCB004070UL)
#define FREG_VO_OSDRGBYUV32                      FIO_ADDRESS(VO,0xCB004074UL)
#define FREG_VO_OSDRGBYUV33                      FIO_ADDRESS(VO,0xCB004078UL)
#define FREG_VO_OSDRGBYUV34                      FIO_ADDRESS(VO,0xCB00407CUL)
#define FREG_VO_SDVFLT                           FIO_ADDRESS(VO,0xCB012800UL)
#define FREG_VO_CURSORRAM                        FIO_ADDRESS(VO,0xCB024000UL)
#define FREG_VO_SDHORNUM                         FIO_ADDRESS(VO,0xCB00C01CUL)
#define FREG_VO_SDHORDENUM                       FIO_ADDRESS(VO,0xCB00C020UL)
#define FREG_VO_SDVERNUM                         FIO_ADDRESS(VO,0xCB00C024UL)
#define FREG_VO_SDVERDENUM                       FIO_ADDRESS(VO,0xCB00C028UL)
#define FREG_VO_SDFILTERMODE                     FIO_ADDRESS(VO,0xCB00C038UL)
#define FREG_VO_SDHORWRITESTART                  FIO_ADDRESS(VO,0xCB00C02CUL)
#define FREG_VO_SDHORWRITESTOP                   FIO_ADDRESS(VO,0xCB00C030UL)
#define FREG_VO_YLUT                             FIO_ADDRESS(VO,0xCB030000UL)
#define FREG_VO_CRLUT                            FIO_ADDRESS(VO,0xCB031000UL)
#define FREG_VO_CBLUT                            FIO_ADDRESS(VO,0xCB032000UL)
#define FREG_VO_RLUT                             FIO_ADDRESS(VO,0xCB034000UL)
#define FREG_VO_GLUT                             FIO_ADDRESS(VO,0xCB035000UL)
#define FREG_VO_BLUT                             FIO_ADDRESS(VO,0xCB036000UL)
#define FREG_VO_SDENABLE                         FIO_ADDRESS(VO,0xCB00C040UL)
#define FREG_VO_OSDMODE                          FIO_ADDRESS(VO,0xCB004044UL)
#define FREG_VO_CURSORMODE                       FIO_ADDRESS(VO,0xCB00C044UL)
#define FREG_VO_DISPCVBSVERSYNC                  FIO_ADDRESS(VO,0xCB010048UL)
#define FREG_VO_SDHORLINELENGTH                  FIO_ADDRESS(VO,0xCB011000UL)
#define FREG_VO_SDVERSIZE                        FIO_ADDRESS(VO,0xCB011004UL)
#define FREG_VO_SDSECFIELDOFFSET                 FIO_ADDRESS(VO,0xCB011008UL)
#define FREG_VO_SDBACKGROUND                     FIO_ADDRESS(VO,0xCB01101CUL)
#define FREG_VO_SDVOHORSTART                     FIO_ADDRESS(VO,0xCB011040UL)
#define FREG_VO_SDVOHORSTOP                      FIO_ADDRESS(VO,0xCB011044UL)
#define FREG_VO_SDVOVERSTART                     FIO_ADDRESS(VO,0xCB011048UL)
#define FREG_VO_SDVOVERSTOP                      FIO_ADDRESS(VO,0xCB01104CUL)
#define FREG_VO_SDHVSYNCCFG                      FIO_ADDRESS(VO,0xCB011140UL)
#define FREG_VO_SDVSYNCOFFSET                    FIO_ADDRESS(VO,0xCB01114CUL)
#define FREG_VO_SDVSYNCEVSTART                   FIO_ADDRESS(VO,0xCB011100UL)
#define FREG_VO_SDVSYNCOVSTART                   FIO_ADDRESS(VO,0xCB011104UL)
#define FREG_VO_SDVSYNCEVSTOP                    FIO_ADDRESS(VO,0xCB011108UL)
#define FREG_VO_SDVSYNCOVSTOP                    FIO_ADDRESS(VO,0xCB01110CUL)
#define FREG_VO_SDVSYNCEHSTART                   FIO_ADDRESS(VO,0xCB011110UL)
#define FREG_VO_SDVSYNCOHSTART                   FIO_ADDRESS(VO,0xCB011114UL)
#define FREG_VO_SDVSYNCEHSTOP                    FIO_ADDRESS(VO,0xCB011118UL)
#define FREG_VO_SDVSYNCOHSTOP                    FIO_ADDRESS(VO,0xCB01111CUL)
#define FREG_VO_SDHSYNCSTART                     FIO_ADDRESS(VO,0xCB011120UL)
#define FREG_VO_SDHSYNCSTOP                      FIO_ADDRESS(VO,0xCB011124UL)
#define FREG_VO_SDHSYNCOFFSET                    FIO_ADDRESS(VO,0xCB011144UL)
#define FREG_VO_OSD1CLUT                         FIO_ADDRESS(VO,0xCB007000UL)
#define FREG_VO_OSD2CLUT                         FIO_ADDRESS(VO,0xCB00B000UL)
#define FREG_VO_CURSORCLUT                       FIO_ADDRESS(VO,0xCB020000UL)
#define FREG_VO_DISPHORLL1                       FIO_ADDRESS(VO,0xCB0100A8UL)
#define FREG_VO_SDTTXHORSTART                    FIO_ADDRESS(VO,0xCB011050UL)
#define FREG_VO_MIXYUVRGB                        FIO_ADDRESS(VO,0xCB0100C0UL)
#define FREG_VO_MIXRGBYUV                        FIO_ADDRESS(VO,0xCB010100UL)
#define FREG_VO_CURSORVERSIZE                    FIO_ADDRESS(VO,0xCB0100ACUL)

/*
********************************************************************************
**
** Mirror variables for write-only registers
**
********************************************************************************
*/
extern volatile uint32_t FREG_VO_VohfltMirror[128];
extern volatile uint32_t FREG_VO_Osd1hfltMirror[128];
extern volatile uint32_t FREG_VO_Osd2hfltMirror[128];
extern volatile uint32_t FREG_VO_SdhfltMirror[64];
extern volatile uint32_t FREG_VO_SdvfltMirror[64];
extern volatile uint32_t FREG_VO_SdHorlinelengthMirror;
extern volatile uint32_t FREG_VO_SdVersizeMirror;
extern volatile uint32_t FREG_VO_SdSecfieldoffsetMirror;
extern volatile uint32_t FREG_VO_SdBackgroundMirror;
extern volatile uint32_t FREG_VO_SdVohorstartMirror;
extern volatile uint32_t FREG_VO_SdVohorstopMirror;
extern volatile uint32_t FREG_VO_SdVoverstartMirror;
extern volatile uint32_t FREG_VO_SdVoverstopMirror;
extern volatile uint32_t FREG_VO_SdhvsynccfgMirror;
extern volatile uint32_t FREG_VO_SdvsyncoffsetMirror;
extern volatile uint32_t FREG_VO_SdvsyncevstartMirror;
extern volatile uint32_t FREG_VO_SdvsyncovstartMirror;
extern volatile uint32_t FREG_VO_SdvsyncevstopMirror;
extern volatile uint32_t FREG_VO_SdvsyncovstopMirror;
extern volatile uint32_t FREG_VO_SdvsyncehstartMirror;
extern volatile uint32_t FREG_VO_SdvsyncohstartMirror;
extern volatile uint32_t FREG_VO_SdvsyncehstopMirror;
extern volatile uint32_t FREG_VO_SdvsyncohstopMirror;
extern volatile uint32_t FREG_VO_SdhsyncstartMirror;
extern volatile uint32_t FREG_VO_SdhsyncstopMirror;
extern volatile uint32_t FREG_VO_SdhsyncoffsetMirror;
extern volatile uint32_t FREG_VO_Osd1clutMirror[256];
extern volatile uint32_t FREG_VO_Osd2clutMirror[256];
extern volatile uint32_t FREG_VO_CursorclutMirror[256];
extern volatile uint32_t FREG_VO_SdTtxhorstartMirror;

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Framoffset".
**
** This function writes the given value to the register "Framoffset".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetFramoffset( uint32_t value );
#else
INLINE void FREG_VO_SetFramoffset( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_FRAMOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_FRAMOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Frameoffset" of register "Framoffset".
**
** frame offset, indicates which frame to be displayed (from VD)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Frameoffset" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern void FREG_VO_SetFramoffset_Frameoffset( uint32_t value );
#else
INLINE void FREG_VO_SetFramoffset_Frameoffset( uint32_t value )
{
    register uint32_t mask = 0x0000001FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_FRAMOFFSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_FRAMOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_FRAMOFFSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Framoffset".
**
** This function reads the value from the register "Framoffset".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetFramoffset( void );
#else
INLINE uint32_t FREG_VO_GetFramoffset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_FRAMOFFSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Frameoffset" of register "Framoffset".
**
** frame offset, indicates which frame to be displayed (from VD)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Frameoffset" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetFramoffset_Frameoffset( void );
#else
INLINE uint32_t FREG_VO_GetFramoffset_Frameoffset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_FRAMOFFSET));
    value = ( value & 0x0000001FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vovstartpos".
**
** This function writes the given value to the register "Vovstartpos".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVovstartpos( uint32_t value );
#else
INLINE void FREG_VO_SetVovstartpos( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOVSTARTPOS, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOVSTARTPOS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vstartpos" of register "Vovstartpos".
**
** vertical start position
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vstartpos" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVovstartpos_Vstartpos( uint32_t value );
#else
INLINE void FREG_VO_SetVovstartpos_Vstartpos( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOVSTARTPOS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOVSTARTPOS, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOVSTARTPOS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vovstartpos".
**
** This function reads the value from the register "Vovstartpos".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVovstartpos( void );
#else
INLINE uint32_t FREG_VO_GetVovstartpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOVSTARTPOS));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vstartpos" of register "Vovstartpos".
**
** vertical start position
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vstartpos" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVovstartpos_Vstartpos( void );
#else
INLINE uint32_t FREG_VO_GetVovstartpos_Vstartpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOVSTARTPOS));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohstartpos".
**
** This function writes the given value to the register "Vohstartpos".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohstartpos( uint32_t value );
#else
INLINE void FREG_VO_SetVohstartpos( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHSTARTPOS, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHSTARTPOS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hstartpos" of register "Vohstartpos".
**
** horizontal start position in multiple of 128 bytes
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hstartpos" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohstartpos_Hstartpos( uint32_t value );
#else
INLINE void FREG_VO_SetVohstartpos_Hstartpos( uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOHSTARTPOS)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHSTARTPOS, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHSTARTPOS)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohstartpos".
**
** This function reads the value from the register "Vohstartpos".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohstartpos( void );
#else
INLINE uint32_t FREG_VO_GetVohstartpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHSTARTPOS));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hstartpos" of register "Vohstartpos".
**
** horizontal start position in multiple of 128 bytes
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hstartpos" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohstartpos_Hstartpos( void );
#else
INLINE uint32_t FREG_VO_GetVohstartpos_Hstartpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHSTARTPOS));
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohsize".
**
** This function writes the given value to the register "Vohsize".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohsize( uint32_t value );
#else
INLINE void FREG_VO_SetVohsize( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hsize" of register "Vohsize".
**
** horizontal line size in memory in multiple of 128 byte.
**  For Vo it's always one byte per pixel, for OSD it depends on OSD mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsize" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohsize_Hsize( uint32_t value );
#else
INLINE void FREG_VO_SetVohsize_Hsize( uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOHSIZE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohsize".
**
** This function reads the value from the register "Vohsize".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohsize( void );
#else
INLINE uint32_t FREG_VO_GetVohsize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHSIZE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hsize" of register "Vohsize".
**
** horizontal line size in memory in multiple of 128 byte.
**  For Vo it's always one byte per pixel, for OSD it depends on OSD mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsize" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohsize_Hsize( void );
#else
INLINE uint32_t FREG_VO_GetVohsize_Hsize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHSIZE));
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vobitperpixel".
**
** This function writes the given value to the register "Vobitperpixel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVobitperpixel( uint32_t value );
#else
INLINE void FREG_VO_SetVobitperpixel( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOBITPERPIXEL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOBITPERPIXEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bitperpixel" of register "Vobitperpixel".
**
** bit per displayed pixel.
** 
** 1 = 4 bit per pixel                                                            2 = 8 bit per pixel
** 4 = 16 bit per pixel
** 8 = 32 bit per pixel
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bitperpixel" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_VO_SetVobitperpixel_Bitperpixel( uint32_t value );
#else
INLINE void FREG_VO_SetVobitperpixel_Bitperpixel( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOBITPERPIXEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOBITPERPIXEL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOBITPERPIXEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vobitperpixel".
**
** This function reads the value from the register "Vobitperpixel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVobitperpixel( void );
#else
INLINE uint32_t FREG_VO_GetVobitperpixel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOBITPERPIXEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bitperpixel" of register "Vobitperpixel".
**
** bit per displayed pixel.
** 
** 1 = 4 bit per pixel                                                            2 = 8 bit per pixel
** 4 = 16 bit per pixel
** 8 = 32 bit per pixel
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bitperpixel" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVobitperpixel_Bitperpixel( void );
#else
INLINE uint32_t FREG_VO_GetVobitperpixel_Bitperpixel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOBITPERPIXEL));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohornum".
**
** This function writes the given value to the register "Vohornum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohornum( uint32_t value );
#else
INLINE void FREG_VO_SetVohornum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hornum" of register "Vohornum".
**
** horizontal numerator for calculating polyphase filter (add value for modulo counter)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hornum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohornum_Hornum( uint32_t value );
#else
INLINE void FREG_VO_SetVohornum_Hornum( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOHORNUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohornum".
**
** This function reads the value from the register "Vohornum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohornum( void );
#else
INLINE uint32_t FREG_VO_GetVohornum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORNUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hornum" of register "Vohornum".
**
** horizontal numerator for calculating polyphase filter (add value for modulo counter)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hornum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohornum_Hornum( void );
#else
INLINE uint32_t FREG_VO_GetVohornum_Hornum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORNUM));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohordenum".
**
** This function writes the given value to the register "Vohordenum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohordenum( uint32_t value );
#else
INLINE void FREG_VO_SetVohordenum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hordenum" of register "Vohordenum".
**
** horizontal denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hordenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohordenum_Hordenum( uint32_t value );
#else
INLINE void FREG_VO_SetVohordenum_Hordenum( uint32_t value )
{
    register uint32_t mask = 0x0001FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOHORDENUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohordenum".
**
** This function reads the value from the register "Vohordenum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohordenum( void );
#else
INLINE uint32_t FREG_VO_GetVohordenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORDENUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hordenum" of register "Vohordenum".
**
** horizontal denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hordenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohordenum_Hordenum( void );
#else
INLINE uint32_t FREG_VO_GetVohordenum_Hordenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORDENUM));
    value = ( value & 0x0001FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vovernum".
**
** This function writes the given value to the register "Vovernum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVovernum( uint32_t value );
#else
INLINE void FREG_VO_SetVovernum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOVERNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOVERNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vernum" of register "Vovernum".
**
** vertical numerator for calculating polyphase filter (add value for modulo counter)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vernum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVovernum_Vernum( uint32_t value );
#else
INLINE void FREG_VO_SetVovernum_Vernum( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOVERNUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOVERNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOVERNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vovernum".
**
** This function reads the value from the register "Vovernum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVovernum( void );
#else
INLINE uint32_t FREG_VO_GetVovernum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOVERNUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vernum" of register "Vovernum".
**
** vertical numerator for calculating polyphase filter (add value for modulo counter)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vernum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVovernum_Vernum( void );
#else
INLINE uint32_t FREG_VO_GetVovernum_Vernum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOVERNUM));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Voverdenum".
**
** This function writes the given value to the register "Voverdenum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVoverdenum( uint32_t value );
#else
INLINE void FREG_VO_SetVoverdenum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOVERDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOVERDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verdenum" of register "Voverdenum".
**
** vertical denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verdenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVoverdenum_Verdenum( uint32_t value );
#else
INLINE void FREG_VO_SetVoverdenum_Verdenum( uint32_t value )
{
    register uint32_t mask = 0x0001FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOVERDENUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOVERDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOVERDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Voverdenum".
**
** This function reads the value from the register "Voverdenum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVoverdenum( void );
#else
INLINE uint32_t FREG_VO_GetVoverdenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOVERDENUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verdenum" of register "Voverdenum".
**
** vertical denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verdenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVoverdenum_Verdenum( void );
#else
INLINE uint32_t FREG_VO_GetVoverdenum_Verdenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOVERDENUM));
    value = ( value & 0x0001FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohordisppixel".
**
** This function writes the given value to the register "Vohordisppixel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohordisppixel( uint32_t value );
#else
INLINE void FREG_VO_SetVohordisppixel( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORDISPPIXEL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORDISPPIXEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hordisppixel" of register "Vohordisppixel".
**
** horizontal displayed pixel (at the output of the filter)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hordisppixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohordisppixel_Hordisppixel( uint32_t value );
#else
INLINE void FREG_VO_SetVohordisppixel_Hordisppixel( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOHORDISPPIXEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORDISPPIXEL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORDISPPIXEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohordisppixel".
**
** This function reads the value from the register "Vohordisppixel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohordisppixel( void );
#else
INLINE uint32_t FREG_VO_GetVohordisppixel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORDISPPIXEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hordisppixel" of register "Vohordisppixel".
**
** horizontal displayed pixel (at the output of the filter)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hordisppixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohordisppixel_Hordisppixel( void );
#else
INLINE uint32_t FREG_VO_GetVohordisppixel_Hordisppixel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORDISPPIXEL));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohorreadpixel".
**
** This function writes the given value to the register "Vohorreadpixel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohorreadpixel( uint32_t value );
#else
INLINE void FREG_VO_SetVohorreadpixel( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORREADPIXEL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORREADPIXEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horreadpixel" of register "Vohorreadpixel".
**
** horizontal pixel read from line buffer (actual value - 1)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horreadpixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohorreadpixel_Horreadpixel( uint32_t value );
#else
INLINE void FREG_VO_SetVohorreadpixel_Horreadpixel( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOHORREADPIXEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHORREADPIXEL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHORREADPIXEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohorreadpixel".
**
** This function reads the value from the register "Vohorreadpixel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohorreadpixel( void );
#else
INLINE uint32_t FREG_VO_GetVohorreadpixel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORREADPIXEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horreadpixel" of register "Vohorreadpixel".
**
** horizontal pixel read from line buffer (actual value - 1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horreadpixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVohorreadpixel_Horreadpixel( void );
#else
INLINE uint32_t FREG_VO_GetVohorreadpixel_Horreadpixel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOHORREADPIXEL));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Voinitialshift".
**
** This function writes the given value to the register "Voinitialshift".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVoinitialshift( uint32_t value );
#else
INLINE void FREG_VO_SetVoinitialshift( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOINITIALSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOINITIALSHIFT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Initialshiftlum" of register "Voinitialshift".
**
** initial shifted pixels into H-filter.
**  Can be used to adjust horizontal read start position. Initial shift 4 is used to adjust filter output to the first pixel
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Initialshiftlum" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VO_SetVoinitialshift_Initialshiftlum( uint32_t value );
#else
INLINE void FREG_VO_SetVoinitialshift_Initialshiftlum( uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOINITIALSHIFT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOINITIALSHIFT, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOINITIALSHIFT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Voinitialshift".
**
** This function reads the value from the register "Voinitialshift".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVoinitialshift( void );
#else
INLINE uint32_t FREG_VO_GetVoinitialshift( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOINITIALSHIFT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Initialshiftlum" of register "Voinitialshift".
**
** initial shifted pixels into H-filter.
**  Can be used to adjust horizontal read start position. Initial shift 4 is used to adjust filter output to the first pixel
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Initialshiftlum" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVoinitialshift_Initialshiftlum( void );
#else
INLINE uint32_t FREG_VO_GetVoinitialshift_Initialshiftlum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOINITIALSHIFT));
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Volayerenable".
**
** This function writes the given value to the register "Volayerenable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVolayerenable( uint32_t value );
#else
INLINE void FREG_VO_SetVolayerenable( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOLAYERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOLAYERENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Layerenable" of register "Volayerenable".
**
** enables the layer
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Layerenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetVolayerenable_Layerenable( uint32_t value );
#else
INLINE void FREG_VO_SetVolayerenable_Layerenable( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOLAYERENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOLAYERENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOLAYERENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Volayerenable".
**
** This function reads the value from the register "Volayerenable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVolayerenable( void );
#else
INLINE uint32_t FREG_VO_GetVolayerenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOLAYERENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Layerenable" of register "Volayerenable".
**
** enables the layer
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Layerenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVolayerenable_Layerenable( void );
#else
INLINE uint32_t FREG_VO_GetVolayerenable_Layerenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOLAYERENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disprestart".
**
** This function writes the given value to the register "Disprestart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisprestart( uint32_t value );
#else
INLINE void FREG_VO_SetDisprestart( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPRESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPRESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Disppixrep" of register "Disprestart".
**
** (0)pixel repetition on HDMI IF (0 = no rep.
**  1 = rep.)
** (1) 0 = 4:4:4 format, 1 = 4:2:2 format
** (2) 0 = CbCr, 1 = CrCb (CrCb exchange) 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Disppixrep" consists of the bits 14..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00007000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisprestart_Disppixrep( uint32_t value );
#else
INLINE void FREG_VO_SetDisprestart_Disppixrep( uint32_t value )
{
    register uint32_t mask = 0x00007000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPRESTART)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPRESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPRESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispenable" of register "Disprestart".
**
** enables the pixel output on HDMI interface (enables decoupling RAM)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispenable" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisprestart_Dispenable( uint32_t value );
#else
INLINE void FREG_VO_SetDisprestart_Dispenable( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPRESTART)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPRESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPRESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispoutramenable" of register "Disprestart".
**
** enables the display unit to write into output RAM
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispoutramenable" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisprestart_Dispoutramenable( uint32_t value );
#else
INLINE void FREG_VO_SetDisprestart_Dispoutramenable( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPRESTART)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPRESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPRESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispresetn" of register "Disprestart".
**
** enables the horizontal and vertical counter
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispresetn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisprestart_Dispresetn( uint32_t value );
#else
INLINE void FREG_VO_SetDisprestart_Dispresetn( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPRESTART)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPRESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPRESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disprestart".
**
** This function reads the value from the register "Disprestart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisprestart( void );
#else
INLINE uint32_t FREG_VO_GetDisprestart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPRESTART));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Disppixrep" of register "Disprestart".
**
** (0)pixel repetition on HDMI IF (0 = no rep.
**  1 = rep.)
** (1) 0 = 4:4:4 format, 1 = 4:2:2 format
** (2) 0 = CbCr, 1 = CrCb (CrCb exchange) 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Disppixrep" consists of the bits 14..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00007000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisprestart_Disppixrep( void );
#else
INLINE uint32_t FREG_VO_GetDisprestart_Disppixrep( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPRESTART));
    value = ( value & 0x00007000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispenable" of register "Disprestart".
**
** enables the pixel output on HDMI interface (enables decoupling RAM)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispenable" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisprestart_Dispenable( void );
#else
INLINE uint32_t FREG_VO_GetDisprestart_Dispenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPRESTART));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispoutramenable" of register "Disprestart".
**
** enables the display unit to write into output RAM
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispoutramenable" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisprestart_Dispoutramenable( void );
#else
INLINE uint32_t FREG_VO_GetDisprestart_Dispoutramenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPRESTART));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispresetn" of register "Disprestart".
**
** enables the horizontal and vertical counter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispresetn" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisprestart_Dispresetn( void );
#else
INLINE uint32_t FREG_VO_GetDisprestart_Dispresetn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPRESTART));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disphorll".
**
** This function writes the given value to the register "Disphorll".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisphorll( uint32_t value );
#else
INLINE void FREG_VO_SetDisphorll( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHORLL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHORLL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Disphorll" of register "Disphorll".
**
** horizontal line length of HDMI path
** ex.
**  2640 for 1080i\@50Hz 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Disphorll" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphorll_Disphorll( uint32_t value );
#else
INLINE void FREG_VO_SetDisphorll_Disphorll( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHORLL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHORLL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHORLL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disphorll".
**
** This function reads the value from the register "Disphorll".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphorll( void );
#else
INLINE uint32_t FREG_VO_GetDisphorll( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHORLL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Disphorll" of register "Disphorll".
**
** horizontal line length of HDMI path
** ex.
**  2640 for 1080i\@50Hz 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Disphorll" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphorll_Disphorll( void );
#else
INLINE uint32_t FREG_VO_GetDisphorll_Disphorll( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHORLL));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispversize".
**
** This function writes the given value to the register "Dispversize".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispversize( uint32_t value );
#else
INLINE void FREG_VO_SetDispversize( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVERSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispversize" of register "Dispversize".
**
** vertical size of HDMI path (field)
** ex.
**  562 for 1080i\@50Hz.
** This corresponds to 563 lines for the first field when VERCOUNT0 = 0. The second field size depends on SECONDFIELDOFFSET.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispversize" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispversize_Dispversize( uint32_t value );
#else
INLINE void FREG_VO_SetDispversize_Dispversize( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVERSIZE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVERSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispversize".
**
** This function reads the value from the register "Dispversize".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispversize( void );
#else
INLINE uint32_t FREG_VO_GetDispversize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVERSIZE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispversize" of register "Dispversize".
**
** vertical size of HDMI path (field)
** ex.
**  562 for 1080i\@50Hz.
** This corresponds to 563 lines for the first field when VERCOUNT0 = 0. The second field size depends on SECONDFIELDOFFSET.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispversize" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispversize_Dispversize( void );
#else
INLINE uint32_t FREG_VO_GetDispversize_Dispversize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVERSIZE));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispvercfg".
**
** This function writes the given value to the register "Dispvercfg".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispvercfg( uint32_t value );
#else
INLINE void FREG_VO_SetDispvercfg( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVERCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVERCFG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vercount0" of register "Dispvercfg".
**
** bit 0 of vertical counter when counter is restarted (end of field)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vercount0" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvercfg_Vercount0( uint32_t value );
#else
INLINE void FREG_VO_SetDispvercfg_Vercount0( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVERCFG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVERCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVERCFG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Secondfieldoffset" of register "Dispvercfg".
**
** offset for stop value of line counter for second field.
** 
** DISPVER_SIZE - 2 + SEC_FIELD_OFFSET
** for interlaced picture this value needs to be set to 1. The second field will be one line less then first field.
** For progressive picture both fields need to be same size. Register needs to be set to 2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Secondfieldoffset" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvercfg_Secondfieldoffset( uint32_t value );
#else
INLINE void FREG_VO_SetDispvercfg_Secondfieldoffset( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVERCFG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVERCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVERCFG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispvercfg".
**
** This function reads the value from the register "Dispvercfg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvercfg( void );
#else
INLINE uint32_t FREG_VO_GetDispvercfg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVERCFG));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vercount0" of register "Dispvercfg".
**
** bit 0 of vertical counter when counter is restarted (end of field)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vercount0" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvercfg_Vercount0( void );
#else
INLINE uint32_t FREG_VO_GetDispvercfg_Vercount0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVERCFG));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Secondfieldoffset" of register "Dispvercfg".
**
** offset for stop value of line counter for second field.
** 
** DISPVER_SIZE - 2 + SEC_FIELD_OFFSET
** for interlaced picture this value needs to be set to 1. The second field will be one line less then first field.
** For progressive picture both fields need to be same size. Register needs to be set to 2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Secondfieldoffset" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvercfg_Secondfieldoffset( void );
#else
INLINE uint32_t FREG_VO_GetDispvercfg_Secondfieldoffset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVERCFG));
    value = ( value & 0x00000007UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispvoversync".
**
** This function writes the given value to the register "Dispvoversync".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispvoversync( uint32_t value );
#else
INLINE void FREG_VO_SetDispvoversync( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOVERSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOVERSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispvoversync" of register "Dispvoversync".
**
** vertical sync position for VO.
**  Recommended setting is 1.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispvoversync" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvoversync_Dispvoversync( uint32_t value );
#else
INLINE void FREG_VO_SetDispvoversync_Dispvoversync( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVOVERSYNC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOVERSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOVERSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispvoversync".
**
** This function reads the value from the register "Dispvoversync".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvoversync( void );
#else
INLINE uint32_t FREG_VO_GetDispvoversync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOVERSYNC));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispvoversync" of register "Dispvoversync".
**
** vertical sync position for VO.
**  Recommended setting is 1.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispvoversync" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvoversync_Dispvoversync( void );
#else
INLINE uint32_t FREG_VO_GetDispvoversync_Dispvoversync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOVERSYNC));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispvohorstartstop".
**
** This function writes the given value to the register "Dispvohorstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispvohorstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispvohorstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vohorstart" of register "Dispvohorstartstop".
**
** horizontal start position of VO on HDMI path
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vohorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvohorstartstop_Vohorstart( uint32_t value );
#else
INLINE void FREG_VO_SetDispvohorstartstop_Vohorstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vohorstop" of register "Dispvohorstartstop".
**
** horizontal stop position of VO on HDMAI path Difference betweeen start and stop corresponds to picture size (example 1920 pixel)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vohorstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvohorstartstop_Vohorstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispvohorstartstop_Vohorstop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispvohorstartstop".
**
** This function reads the value from the register "Dispvohorstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvohorstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDispvohorstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vohorstart" of register "Dispvohorstartstop".
**
** horizontal start position of VO on HDMI path
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vohorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvohorstartstop_Vohorstart( void );
#else
INLINE uint32_t FREG_VO_GetDispvohorstartstop_Vohorstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vohorstop" of register "Dispvohorstartstop".
**
** horizontal stop position of VO on HDMAI path Difference betweeen start and stop corresponds to picture size (example 1920 pixel)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vohorstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvohorstartstop_Vohorstop( void );
#else
INLINE uint32_t FREG_VO_GetDispvohorstartstop_Vohorstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOHORSTARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispvoverstartstop".
**
** This function writes the given value to the register "Dispvoverstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispvoverstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispvoverstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Voverstart" of register "Dispvoverstartstop".
**
** vertical start position of VO on HDMI path
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Voverstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvoverstartstop_Voverstart( uint32_t value );
#else
INLINE void FREG_VO_SetDispvoverstartstop_Voverstart( uint32_t value )
{
    register uint32_t mask = 0x07FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Voverstop" of register "Dispvoverstartstop".
**
** vertical stop position of VO on HDMI path.
** 
** Difference corresponds to vertical picture size. (example 540 in case of 1080i)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Voverstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvoverstartstop_Voverstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispvoverstartstop_Voverstop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVOVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispvoverstartstop".
**
** This function reads the value from the register "Dispvoverstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvoverstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDispvoverstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Voverstart" of register "Dispvoverstartstop".
**
** vertical start position of VO on HDMI path
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Voverstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvoverstartstop_Voverstart( void );
#else
INLINE uint32_t FREG_VO_GetDispvoverstartstop_Voverstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP));
    value = ( value & 0x07FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Voverstop" of register "Dispvoverstartstop".
**
** vertical stop position of VO on HDMI path.
** 
** Difference corresponds to vertical picture size. (example 540 in case of 1080i)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Voverstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvoverstartstop_Voverstop( void );
#else
INLINE uint32_t FREG_VO_GetDispvoverstartstop_Voverstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVOVERSTARTSTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disposd1horstartstop".
**
** This function writes the given value to the register "Disposd1horstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd1horstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd1horstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD1HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd1horstart" of register "Disposd1horstartstop".
**
** horizontal start position of OSD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd1horstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd1horstartstop_Osd1horstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd1horstartstop_Osd1horstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD1HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd1horstop" of register "Disposd1horstartstop".
**
** horizontal stop position of OSD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd1horstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd1horstartstop_Osd1horstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd1horstartstop_Osd1horstop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD1HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disposd1horstartstop".
**
** This function reads the value from the register "Disposd1horstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd1horstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd1horstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd1horstart" of register "Disposd1horstartstop".
**
** horizontal start position of OSD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd1horstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd1horstartstop_Osd1horstart( void );
#else
INLINE uint32_t FREG_VO_GetDisposd1horstartstop_Osd1horstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd1horstop" of register "Disposd1horstartstop".
**
** horizontal stop position of OSD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd1horstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd1horstartstop_Osd1horstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd1horstartstop_Osd1horstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD1HORSTARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disposd1verstartstop".
**
** This function writes the given value to the register "Disposd1verstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd1verstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd1verstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD1VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd1verstart" of register "Disposd1verstartstop".
**
** vertical start position of OSD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd1verstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd1verstartstop_Osd1verstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd1verstartstop_Osd1verstart( uint32_t value )
{
    register uint32_t mask = 0x07FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD1VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd1verstop" of register "Disposd1verstartstop".
**
** vertical stop position of OSD1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd1verstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd1verstartstop_Osd1verstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd1verstartstop_Osd1verstop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD1VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disposd1verstartstop".
**
** This function reads the value from the register "Disposd1verstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd1verstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd1verstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd1verstart" of register "Disposd1verstartstop".
**
** vertical start position of OSD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd1verstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd1verstartstop_Osd1verstart( void );
#else
INLINE uint32_t FREG_VO_GetDisposd1verstartstop_Osd1verstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP));
    value = ( value & 0x07FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd1verstop" of register "Disposd1verstartstop".
**
** vertical stop position of OSD1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd1verstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd1verstartstop_Osd1verstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd1verstartstop_Osd1verstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD1VERSTARTSTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disposd2horstartstop".
**
** This function writes the given value to the register "Disposd2horstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd2horstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd2horstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD2HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd2horstart" of register "Disposd2horstartstop".
**
** horizontal start position of OSD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd2horstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd2horstartstop_Osd2horstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd2horstartstop_Osd2horstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD2HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd2horstop" of register "Disposd2horstartstop".
**
** horizontal stop position of OSD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd2horstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd2horstartstop_Osd2horstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd2horstartstop_Osd2horstop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD2HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disposd2horstartstop".
**
** This function reads the value from the register "Disposd2horstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd2horstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd2horstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd2horstart" of register "Disposd2horstartstop".
**
** horizontal start position of OSD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd2horstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd2horstartstop_Osd2horstart( void );
#else
INLINE uint32_t FREG_VO_GetDisposd2horstartstop_Osd2horstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd2horstop" of register "Disposd2horstartstop".
**
** horizontal stop position of OSD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd2horstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd2horstartstop_Osd2horstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd2horstartstop_Osd2horstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD2HORSTARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disposd2verstartstop".
**
** This function writes the given value to the register "Disposd2verstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd2verstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd2verstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD2VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd2verstart" of register "Disposd2verstartstop".
**
** vertical start position of OSD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd2verstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd2verstartstop_Osd2verstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd2verstartstop_Osd2verstart( uint32_t value )
{
    register uint32_t mask = 0x07FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD2VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd2verstop" of register "Disposd2verstartstop".
**
** vertical stop position of OSD2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd2verstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd2verstartstop_Osd2verstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd2verstartstop_Osd2verstop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD2VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disposd2verstartstop".
**
** This function reads the value from the register "Disposd2verstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd2verstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd2verstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd2verstart" of register "Disposd2verstartstop".
**
** vertical start position of OSD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd2verstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd2verstartstop_Osd2verstart( void );
#else
INLINE uint32_t FREG_VO_GetDisposd2verstartstop_Osd2verstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP));
    value = ( value & 0x07FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd2verstop" of register "Disposd2verstartstop".
**
** vertical stop position of OSD2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd2verstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd2verstartstop_Osd2verstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd2verstartstop_Osd2verstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD2VERSTARTSTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disposd3horstartstop".
**
** This function writes the given value to the register "Disposd3horstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd3horstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd3horstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD3HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd3horstart" of register "Disposd3horstartstop".
**
** horizontal start position of Cursor
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd3horstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd3horstartstop_Osd3horstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd3horstartstop_Osd3horstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD3HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd3horstop" of register "Disposd3horstartstop".
**
** horizontal stop position of Cursor.
** 
** If horizontal window size is larger then the actual cursor line length, the cursor line will be repeated until window end
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd3horstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd3horstartstop_Osd3horstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd3horstartstop_Osd3horstop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD3HORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disposd3horstartstop".
**
** This function reads the value from the register "Disposd3horstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd3horstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd3horstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd3horstart" of register "Disposd3horstartstop".
**
** horizontal start position of Cursor
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd3horstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd3horstartstop_Osd3horstart( void );
#else
INLINE uint32_t FREG_VO_GetDisposd3horstartstop_Osd3horstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd3horstop" of register "Disposd3horstartstop".
**
** horizontal stop position of Cursor.
** 
** If horizontal window size is larger then the actual cursor line length, the cursor line will be repeated until window end
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd3horstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd3horstartstop_Osd3horstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd3horstartstop_Osd3horstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD3HORSTARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disposd3verstartstop".
**
** This function writes the given value to the register "Disposd3verstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd3verstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd3verstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD3VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd3verstart" of register "Disposd3verstartstop".
**
** vertical start position of Cursor
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd3verstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd3verstartstop_Osd3verstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd3verstartstop_Osd3verstart( uint32_t value )
{
    register uint32_t mask = 0x07FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD3VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd3verstop" of register "Disposd3verstartstop".
**
** vertical stop position of Cursor
** If vertical window size is larger then the actual vertical cursor size, the cursor line will be repeated until window end
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd3verstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisposd3verstartstop_Osd3verstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisposd3verstartstop_Osd3verstop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPOSD3VERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disposd3verstartstop".
**
** This function reads the value from the register "Disposd3verstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd3verstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd3verstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd3verstart" of register "Disposd3verstartstop".
**
** vertical start position of Cursor
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd3verstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd3verstartstop_Osd3verstart( void );
#else
INLINE uint32_t FREG_VO_GetDisposd3verstartstop_Osd3verstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP));
    value = ( value & 0x07FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd3verstop" of register "Disposd3verstartstop".
**
** vertical stop position of Cursor
** If vertical window size is larger then the actual vertical cursor size, the cursor line will be repeated until window end
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd3verstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisposd3verstartstop_Osd3verstop( void );
#else
INLINE uint32_t FREG_VO_GetDisposd3verstartstop_Osd3verstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPOSD3VERSTARTSTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disphdmidehorstartstop".
**
** This function writes the given value to the register "Disphdmidehorstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisphdmidehorstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisphdmidehorstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHDMIDEHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dehorstart" of register "Disphdmidehorstartstop".
**
** horizontal start position of HDMI DE signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dehorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphdmidehorstartstop_Dehorstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisphdmidehorstartstop_Dehorstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHDMIDEHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dehorstop" of register "Disphdmidehorstartstop".
**
** horizontal stop position of HDMI DE signal.
** 
** Defines the part of the picture, which will be transmitted over HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dehorstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphdmidehorstartstop_Dehorstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisphdmidehorstartstop_Dehorstop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHDMIDEHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disphdmidehorstartstop".
**
** This function reads the value from the register "Disphdmidehorstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphdmidehorstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisphdmidehorstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dehorstart" of register "Disphdmidehorstartstop".
**
** horizontal start position of HDMI DE signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dehorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphdmidehorstartstop_Dehorstart( void );
#else
INLINE uint32_t FREG_VO_GetDisphdmidehorstartstop_Dehorstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dehorstop" of register "Disphdmidehorstartstop".
**
** horizontal stop position of HDMI DE signal.
** 
** Defines the part of the picture, which will be transmitted over HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dehorstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphdmidehorstartstop_Dehorstop( void );
#else
INLINE uint32_t FREG_VO_GetDisphdmidehorstartstop_Dehorstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHDMIDEHORSTARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disphdmideverstartstop".
**
** This function writes the given value to the register "Disphdmideverstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisphdmideverstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisphdmideverstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHDMIDEVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Deverstart" of register "Disphdmideverstartstop".
**
** vertical start position of HDMI DE signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Deverstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphdmideverstartstop_Deverstart( uint32_t value );
#else
INLINE void FREG_VO_SetDisphdmideverstartstop_Deverstart( uint32_t value )
{
    register uint32_t mask = 0x07FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHDMIDEVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Deverstop" of register "Disphdmideverstartstop".
**
** verical stop position of HDMI DE signal.
** 
** Defines the part of the picture, which will be transmitted over HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Deverstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphdmideverstartstop_Deverstop( uint32_t value );
#else
INLINE void FREG_VO_SetDisphdmideverstartstop_Deverstop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHDMIDEVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disphdmideverstartstop".
**
** This function reads the value from the register "Disphdmideverstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphdmideverstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDisphdmideverstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Deverstart" of register "Disphdmideverstartstop".
**
** vertical start position of HDMI DE signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Deverstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphdmideverstartstop_Deverstart( void );
#else
INLINE uint32_t FREG_VO_GetDisphdmideverstartstop_Deverstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP));
    value = ( value & 0x07FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Deverstop" of register "Disphdmideverstartstop".
**
** verical stop position of HDMI DE signal.
** 
** Defines the part of the picture, which will be transmitted over HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Deverstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphdmideverstartstop_Deverstop( void );
#else
INLINE uint32_t FREG_VO_GetDisphdmideverstartstop_Deverstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHDMIDEVERSTARTSTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispcvbshorstartstop".
**
** This function writes the given value to the register "Dispcvbshorstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbshorstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbshorstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cvbshorstart" of register "Dispcvbshorstartstop".
**
** horizontal sync of CVBS H-filter (recommended setting 0x10)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cvbshorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbshorstartstop_Cvbshorstart( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbshorstartstop_Cvbshorstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPCVBSHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispcvbshorstartstop".
**
** This function reads the value from the register "Dispcvbshorstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbshorstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbshorstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSHORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cvbshorstart" of register "Dispcvbshorstartstop".
**
** horizontal sync of CVBS H-filter (recommended setting 0x10)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cvbshorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbshorstartstop_Cvbshorstart( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbshorstartstop_Cvbshorstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSHORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispcvbsverstartstop".
**
** This function writes the given value to the register "Dispcvbsverstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbsverstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbsverstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cvbsverstart" of register "Dispcvbsverstartstop".
**
** vertical start CVBS filter control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cvbsverstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbsverstartstop_Cvbsverstart( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbsverstartstop_Cvbsverstart( uint32_t value )
{
    register uint32_t mask = 0x07FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cvbsverstop" of register "Dispcvbsverstartstop".
**
** vertical stop CVBS filter control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cvbsverstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbsverstartstop_Cvbsverstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbsverstartstop_Cvbsverstop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSVERSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispcvbsverstartstop".
**
** This function reads the value from the register "Dispcvbsverstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbsverstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbsverstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cvbsverstart" of register "Dispcvbsverstartstop".
**
** vertical start CVBS filter control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cvbsverstart" consists of the bits 26..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x07FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbsverstartstop_Cvbsverstart( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbsverstartstop_Cvbsverstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP));
    value = ( value & 0x07FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cvbsverstop" of register "Dispcvbsverstartstop".
**
** vertical stop CVBS filter control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cvbsverstop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbsverstartstop_Cvbsverstop( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbsverstartstop_Cvbsverstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSTARTSTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispbackground".
**
** This function writes the given value to the register "Dispbackground".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispbackground( uint32_t value );
#else
INLINE void FREG_VO_SetDispbackground( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackgroundY" of register "Dispbackground".
**
** background Y value in DISP_MIX unit
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackgroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispbackground_BackgroundY( uint32_t value );
#else
INLINE void FREG_VO_SetDispbackground_BackgroundY( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackgroundCr" of register "Dispbackground".
**
** background Cr value in DISP_MIX unit
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackgroundCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispbackground_BackgroundCr( uint32_t value );
#else
INLINE void FREG_VO_SetDispbackground_BackgroundCr( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackgroundCb" of register "Dispbackground".
**
** background Cb value in DISP_MIX unit
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackgroundCb" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispbackground_BackgroundCb( uint32_t value );
#else
INLINE void FREG_VO_SetDispbackground_BackgroundCb( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispbackground".
**
** This function reads the value from the register "Dispbackground".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispbackground( void );
#else
INLINE uint32_t FREG_VO_GetDispbackground( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackgroundY" of register "Dispbackground".
**
** background Y value in DISP_MIX unit
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackgroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispbackground_BackgroundY( void );
#else
INLINE uint32_t FREG_VO_GetDispbackground_BackgroundY( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackgroundCr" of register "Dispbackground".
**
** background Cr value in DISP_MIX unit
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackgroundCr" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispbackground_BackgroundCr( void );
#else
INLINE uint32_t FREG_VO_GetDispbackground_BackgroundCr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackgroundCb" of register "Dispbackground".
**
** background Cb value in DISP_MIX unit
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackgroundCb" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispbackground_BackgroundCb( void );
#else
INLINE uint32_t FREG_VO_GetDispbackground_BackgroundCb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPBACKGROUND));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vohflt".
**
** This function writes the given value to the index-th entry of the register
** array Vohflt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVohflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVohflt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return;
    #endif
    FREG_VO_VohfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vohfilter" of register "Vohflt".
**
** H/V filter coefficient of VO
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vohfilter" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetVohflt_Vohfilter( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVohflt_Vohfilter( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_VohfltMirror[index] & ~mask;
    FREG_VO_VohfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOHFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOHFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vohflt".
**
** This function reads the value from the index-th entry of the register
** array Vohflt.
**
** H/V filter coefficient of VO
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmVohflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmVohflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_VohfltMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vohfilter" of register "Vohflt".
**
** H/V filter coefficient of VO
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vohfilter" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmVohflt_Vohfilter( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmVohflt_Vohfilter( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 128 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_VohfltMirror[index];
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osd1hflt".
**
** This function writes the given value to the index-th entry of the register
** array Osd1hflt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsd1hflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1hflt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return;
    #endif
    FREG_VO_Osd1hfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1HFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1HFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd1hfilter" of register "Osd1hflt".
**
** H/V filter coefficient of OSD1
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd1hfilter" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsd1hflt_Osd1hfilter( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1hflt_Osd1hfilter( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_Osd1hfltMirror[index] & ~mask;
    FREG_VO_Osd1hfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1HFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1HFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osd1hflt".
**
** This function reads the value from the index-th entry of the register
** array Osd1hflt.
**
** H/V filter coefficient of OSD1
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmOsd1hflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1hflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1hfltMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd1hfilter" of register "Osd1hflt".
**
** H/V filter coefficient of OSD1
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd1hfilter" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmOsd1hflt_Osd1hfilter( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1hflt_Osd1hfilter( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 128 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1hfltMirror[index];
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osd2hflt".
**
** This function writes the given value to the index-th entry of the register
** array Osd2hflt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsd2hflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2hflt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return;
    #endif
    FREG_VO_Osd2hfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2HFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2HFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osd2hfilter" of register "Osd2hflt".
**
** H/V filter coefficient of OSD2
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osd2hfilter" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsd2hflt_Osd2hfilter( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2hflt_Osd2hfilter( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_Osd2hfltMirror[index] & ~mask;
    FREG_VO_Osd2hfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2HFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2HFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osd2hflt".
**
** This function reads the value from the index-th entry of the register
** array Osd2hflt.
**
** H/V filter coefficient of OSD2
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmOsd2hflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2hflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 128 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2hfltMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osd2hfilter" of register "Osd2hflt".
**
** H/V filter coefficient of OSD2
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osd2hfilter" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmOsd2hflt_Osd2hfilter( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2hflt_Osd2hfilter( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 128 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2hfltMirror[index];
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhflt".
**
** This function writes the given value to the index-th entry of the register
** array Sdhflt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdhflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetSdhflt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return;
    #endif
    FREG_VO_SdhfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sdhflt" of register "Sdhflt".
**
** HFLT filter coefficients of SD scaler
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdhflt" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdhflt_Sdhflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetSdhflt_Sdhflt( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdhfltMirror[index] & ~mask;
    FREG_VO_SdhfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHFLT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHFLT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhflt".
**
** This function reads the value from the index-th entry of the register
** array Sdhflt.
**
** HFLT filter coefficients of SD scaler
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdhflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmSdhflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_SdhfltMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sdhflt" of register "Sdhflt".
**
** HFLT filter coefficients of SD scaler
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdhflt" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdhflt_Sdhflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmSdhflt_Sdhflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 64 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_SdhfltMirror[index];
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispsynchorstartstop".
**
** This function writes the given value to the register "Dispsynchorstartstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchorstartstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchorstartstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsynchorstart" of register "Dispsynchorstartstop".
**
** horizontal start position of H-sync of HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsynchorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchorstartstop_Dispsynchorstart( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchorstartstop_Dispsynchorstart( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsynchorstop" of register "Dispsynchorstartstop".
**
** horizontal stop position of H-sync for HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsynchorstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchorstartstop_Dispsynchorstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchorstartstop_Dispsynchorstop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHORSTARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispsynchorstartstop".
**
** This function reads the value from the register "Dispsynchorstartstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchorstartstop( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchorstartstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsynchorstart" of register "Dispsynchorstartstop".
**
** horizontal start position of H-sync of HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsynchorstart" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchorstartstop_Dispsynchorstart( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchorstartstop_Dispsynchorstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsynchorstop" of register "Dispsynchorstartstop".
**
** horizontal stop position of H-sync for HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsynchorstop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchorstartstop_Dispsynchorstop( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchorstartstop_Dispsynchorstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHORSTARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispsynchor1startstop".
**
** This function writes the given value to the register "Dispsynchor1startstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchor1startstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchor1startstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHOR1STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsynchor1start" of register "Dispsynchor1startstop".
**
** horizontal start position of V-sync1 of HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsynchor1start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchor1startstop_Dispsynchor1start( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchor1startstop_Dispsynchor1start( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHOR1STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsynchor1stop" of register "Dispsynchor1startstop".
**
** horizontal stop position of V-sync1 for HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsynchor1stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHOR1STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispsynchor1startstop".
**
** This function reads the value from the register "Dispsynchor1startstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchor1startstop( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchor1startstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsynchor1start" of register "Dispsynchor1startstop".
**
** horizontal start position of V-sync1 of HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsynchor1start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchor1startstop_Dispsynchor1start( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchor1startstop_Dispsynchor1start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsynchor1stop" of register "Dispsynchor1startstop".
**
** horizontal stop position of V-sync1 for HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsynchor1stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchor1startstop_Dispsynchor1stop( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchor1startstop_Dispsynchor1stop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR1STARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispsyncver1startstop".
**
** This function writes the given value to the register "Dispsyncver1startstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispsyncver1startstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsyncver1startstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCVER1STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsyncver1start" of register "Dispsyncver1startstop".
**
** vertical start position of V-sync1 of HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsyncver1start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsyncver1startstop_Dispsyncver1start( uint32_t value );
#else
INLINE void FREG_VO_SetDispsyncver1startstop_Dispsyncver1start( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCVER1STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsyncver1stop" of register "Dispsyncver1startstop".
**
** vertical stop position of V-sync1 for HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsyncver1stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCVER1STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispsyncver1startstop".
**
** This function reads the value from the register "Dispsyncver1startstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsyncver1startstop( void );
#else
INLINE uint32_t FREG_VO_GetDispsyncver1startstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsyncver1start" of register "Dispsyncver1startstop".
**
** vertical start position of V-sync1 of HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsyncver1start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsyncver1startstop_Dispsyncver1start( void );
#else
INLINE uint32_t FREG_VO_GetDispsyncver1startstop_Dispsyncver1start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsyncver1stop" of register "Dispsyncver1startstop".
**
** vertical stop position of V-sync1 for HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsyncver1stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsyncver1startstop_Dispsyncver1stop( void );
#else
INLINE uint32_t FREG_VO_GetDispsyncver1startstop_Dispsyncver1stop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCVER1STARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispsynchor2startstop".
**
** This function writes the given value to the register "Dispsynchor2startstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchor2startstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchor2startstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHOR2STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsynchor2start" of register "Dispsynchor2startstop".
**
** horizontal start position of V-sync2 of HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsynchor2start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchor2startstop_Dispsynchor2start( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchor2startstop_Dispsynchor2start( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHOR2STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsynchor2stop" of register "Dispsynchor2startstop".
**
** horizontal stop position of V-sync2 for HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsynchor2stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCHOR2STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispsynchor2startstop".
**
** This function reads the value from the register "Dispsynchor2startstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchor2startstop( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchor2startstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsynchor2start" of register "Dispsynchor2startstop".
**
** horizontal start position of V-sync2 of HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsynchor2start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchor2startstop_Dispsynchor2start( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchor2startstop_Dispsynchor2start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsynchor2stop" of register "Dispsynchor2startstop".
**
** horizontal stop position of V-sync2 for HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsynchor2stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsynchor2startstop_Dispsynchor2stop( void );
#else
INLINE uint32_t FREG_VO_GetDispsynchor2startstop_Dispsynchor2stop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCHOR2STARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispsyncver2startstop".
**
** This function writes the given value to the register "Dispsyncver2startstop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispsyncver2startstop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsyncver2startstop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCVER2STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsyncver2start" of register "Dispsyncver2startstop".
**
** vertical start position of V-sync2 of HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsyncver2start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsyncver2startstop_Dispsyncver2start( uint32_t value );
#else
INLINE void FREG_VO_SetDispsyncver2startstop_Dispsyncver2start( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCVER2STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispsyncver2stop" of register "Dispsyncver2startstop".
**
** vertical stop position of V-sync2 for HDMI
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispsyncver2stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop( uint32_t value );
#else
INLINE void FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPSYNCVER2STARTSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispsyncver2startstop".
**
** This function reads the value from the register "Dispsyncver2startstop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsyncver2startstop( void );
#else
INLINE uint32_t FREG_VO_GetDispsyncver2startstop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsyncver2start" of register "Dispsyncver2startstop".
**
** vertical start position of V-sync2 of HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsyncver2start" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsyncver2startstop_Dispsyncver2start( void );
#else
INLINE uint32_t FREG_VO_GetDispsyncver2startstop_Dispsyncver2start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispsyncver2stop" of register "Dispsyncver2startstop".
**
** vertical stop position of V-sync2 for HDMI
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispsyncver2stop" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispsyncver2startstop_Dispsyncver2stop( void );
#else
INLINE uint32_t FREG_VO_GetDispsyncver2startstop_Dispsyncver2stop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSYNCVER2STARTSTOP));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispvehdsync".
**
** This function writes the given value to the register "Dispvehdsync".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispvehdsync( uint32_t value );
#else
INLINE void FREG_VO_SetDispvehdsync( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVEHDSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vehdfieldsync" of register "Dispvehdsync".
**
** Field position of VE_HD sync pulse
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vehdfieldsync" consists of the bits 28..28,
**       the given bitgroup value will be shifted left by 28 bits and
**       masked using the bitmask 0x10000000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvehdsync_Vehdfieldsync( uint32_t value );
#else
INLINE void FREG_VO_SetDispvehdsync_Vehdfieldsync( uint32_t value )
{
    register uint32_t mask = 0x10000000UL;
    value = ( value << 28 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVEHDSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vehdhpos" of register "Dispvehdsync".
**
** Horizontal position of VE_HD sync pulse
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vehdhpos" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvehdsync_Vehdhpos( uint32_t value );
#else
INLINE void FREG_VO_SetDispvehdsync_Vehdhpos( uint32_t value )
{
    register uint32_t mask = 0x0FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVEHDSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vehdvpos" of register "Dispvehdsync".
**
** Vertical position of VE_HD sync pulse
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vehdvpos" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispvehdsync_Vehdvpos( uint32_t value );
#else
INLINE void FREG_VO_SetDispvehdsync_Vehdvpos( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPVEHDSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispvehdsync".
**
** This function reads the value from the register "Dispvehdsync".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvehdsync( void );
#else
INLINE uint32_t FREG_VO_GetDispvehdsync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vehdfieldsync" of register "Dispvehdsync".
**
** Field position of VE_HD sync pulse
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vehdfieldsync" consists of the bits 28..28,
**       the given bitgroup value will be shifted left by 28 bits and
**       masked using the bitmask 0x10000000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvehdsync_Vehdfieldsync( void );
#else
INLINE uint32_t FREG_VO_GetDispvehdsync_Vehdfieldsync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC));
    value = ( value & 0x10000000UL ) >> 28;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vehdhpos" of register "Dispvehdsync".
**
** Horizontal position of VE_HD sync pulse
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vehdhpos" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvehdsync_Vehdhpos( void );
#else
INLINE uint32_t FREG_VO_GetDispvehdsync_Vehdhpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vehdvpos" of register "Dispvehdsync".
**
** Vertical position of VE_HD sync pulse
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vehdvpos" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispvehdsync_Vehdvpos( void );
#else
INLINE uint32_t FREG_VO_GetDispvehdsync_Vehdvpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPVEHDSYNC));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispstc0".
**
** This function reads the value from the register "Dispstc0".
**
** Current latched STC (32:1)
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispstc0( void );
#else
INLINE uint32_t FREG_VO_GetDispstc0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSTC0));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispstcvalue0" of register "Dispstc0".
**
** Current latched STC (32:1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispstcvalue0" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispstc0_Dispstcvalue0( void );
#else
INLINE uint32_t FREG_VO_GetDispstc0_Dispstcvalue0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSTC0));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispstc1".
**
** This function reads the value from the register "Dispstc1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispstc1( void );
#else
INLINE uint32_t FREG_VO_GetDispstc1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSTC1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispstcvaluemsb" of register "Dispstc1".
**
** Current latched STC (33)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispstcvaluemsb" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispstc1_Dispstcvaluemsb( void );
#else
INLINE uint32_t FREG_VO_GetDispstc1_Dispstcvaluemsb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSTC1));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispstcextentionvalue" of register "Dispstc1".
**
** Current latched STC extention
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispstcextentionvalue" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispstc1_Dispstcextentionvalue( void );
#else
INLINE uint32_t FREG_VO_GetDispstc1_Dispstcextentionvalue( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPSTC1));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispirq0".
**
** This function writes the given value to the register "Dispirq0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq0( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq0( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ0, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispirq0enable" of register "Dispirq0".
**
** Enable for IRQ0
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispirq0enable" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq0_Dispirq0enable( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq0_Dispirq0enable( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ0, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispfiedframeirq0" of register "Dispirq0".
**
** 0 = IRQ on both fields
** 1 = IRQ on field defiend by bit 11 of this register
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispfiedframeirq0" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq0_Dispfiedframeirq0( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq0_Dispfiedframeirq0( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ0, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispfiedirq0sel" of register "Dispirq0".
**
** 0 = IRQ on  field 0 (first field)
** 1 = IRQ on  field 1 (second field) 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispfiedirq0sel" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq0_Dispfiedirq0sel( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq0_Dispfiedirq0sel( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ0, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispverposirq0" of register "Dispirq0".
**
** vertical position of IRQ0
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispverposirq0" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq0_Dispverposirq0( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq0_Dispverposirq0( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ0, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispirq0".
**
** This function reads the value from the register "Dispirq0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq0( void );
#else
INLINE uint32_t FREG_VO_GetDispirq0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ0));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispirq0enable" of register "Dispirq0".
**
** Enable for IRQ0
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispirq0enable" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq0_Dispirq0enable( void );
#else
INLINE uint32_t FREG_VO_GetDispirq0_Dispirq0enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ0));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispfiedframeirq0" of register "Dispirq0".
**
** 0 = IRQ on both fields
** 1 = IRQ on field defiend by bit 11 of this register
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispfiedframeirq0" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq0_Dispfiedframeirq0( void );
#else
INLINE uint32_t FREG_VO_GetDispirq0_Dispfiedframeirq0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ0));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispfiedirq0sel" of register "Dispirq0".
**
** 0 = IRQ on  field 0 (first field)
** 1 = IRQ on  field 1 (second field) 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispfiedirq0sel" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq0_Dispfiedirq0sel( void );
#else
INLINE uint32_t FREG_VO_GetDispirq0_Dispfiedirq0sel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ0));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispverposirq0" of register "Dispirq0".
**
** vertical position of IRQ0
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispverposirq0" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq0_Dispverposirq0( void );
#else
INLINE uint32_t FREG_VO_GetDispirq0_Dispverposirq0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ0));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispirq1".
**
** This function writes the given value to the register "Dispirq1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq1( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq1( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispirq1enable" of register "Dispirq1".
**
** Enable for IRQ1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispirq1enable" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq1_Dispirq1enable( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq1_Dispirq1enable( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispfiedframeirq1" of register "Dispirq1".
**
** 0 = IRQ on both fields
** 1 = IRQ on field defiend by bit 11 of this register
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispfiedframeirq1" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq1_Dispfiedframeirq1( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq1_Dispfiedframeirq1( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispfiedirq1sel" of register "Dispirq1".
**
** 0 = IRQ on  field 0 (first field)
** 1 = IRQ on  field 1 (second field) 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispfiedirq1sel" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq1_Dispfiedirq1sel( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq1_Dispfiedirq1sel( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispverposirq1" of register "Dispirq1".
**
** vertical position of IRQ1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispverposirq1" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq1_Dispverposirq1( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq1_Dispverposirq1( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispirq1".
**
** This function reads the value from the register "Dispirq1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq1( void );
#else
INLINE uint32_t FREG_VO_GetDispirq1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispirq1enable" of register "Dispirq1".
**
** Enable for IRQ1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispirq1enable" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq1_Dispirq1enable( void );
#else
INLINE uint32_t FREG_VO_GetDispirq1_Dispirq1enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ1));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispfiedframeirq1" of register "Dispirq1".
**
** 0 = IRQ on both fields
** 1 = IRQ on field defiend by bit 11 of this register
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispfiedframeirq1" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq1_Dispfiedframeirq1( void );
#else
INLINE uint32_t FREG_VO_GetDispirq1_Dispfiedframeirq1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ1));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispfiedirq1sel" of register "Dispirq1".
**
** 0 = IRQ on  field 0 (first field)
** 1 = IRQ on  field 1 (second field) 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispfiedirq1sel" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq1_Dispfiedirq1sel( void );
#else
INLINE uint32_t FREG_VO_GetDispirq1_Dispfiedirq1sel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ1));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispverposirq1" of register "Dispirq1".
**
** vertical position of IRQ1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispverposirq1" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq1_Dispverposirq1( void );
#else
INLINE uint32_t FREG_VO_GetDispirq1_Dispverposirq1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ1));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispirq2".
**
** This function writes the given value to the register "Dispirq2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmilinkirqen" of register "Dispirq2".
**
** 0 = HDMI LINK IRQ used instead of DISPIRQ2
** 1 = DISPIRQ2 used
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmilinkirqen" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2_Hdmilinkirqen( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2_Hdmilinkirqen( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmilinkirqinv" of register "Dispirq2".
**
** 0 = HDMI LINK IRQ connected through
** 1 = HDMI LINK IRQ inverted
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmilinkirqinv" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2_Hdmilinkirqinv( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2_Hdmilinkirqinv( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispirq2enable" of register "Dispirq2".
**
** Enable for IRQ2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispirq2enable" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2_Dispirq2enable( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2_Dispirq2enable( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispfiedframeirq2" of register "Dispirq2".
**
** 0 = IRQ on both fields
** 1 = IRQ on field defiend by bit 11 of this register
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispfiedframeirq2" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2_Dispfiedframeirq2( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2_Dispfiedframeirq2( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispfiedirq2sel" of register "Dispirq2".
**
** 0 = IRQ on  field 0 (first field)
** 1 = IRQ on  field 1 (second field) 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispfiedirq2sel" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2_Dispfiedirq2sel( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2_Dispfiedirq2sel( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispverposirq2" of register "Dispirq2".
**
** vertical position of IRQ2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispverposirq2" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirq2_Dispverposirq2( uint32_t value );
#else
INLINE void FREG_VO_SetDispirq2_Dispverposirq2( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQ2, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQ2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispirq2".
**
** This function reads the value from the register "Dispirq2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmilinkirqen" of register "Dispirq2".
**
** 0 = HDMI LINK IRQ used instead of DISPIRQ2
** 1 = DISPIRQ2 used
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmilinkirqen" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2_Hdmilinkirqen( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2_Hdmilinkirqen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmilinkirqinv" of register "Dispirq2".
**
** 0 = HDMI LINK IRQ connected through
** 1 = HDMI LINK IRQ inverted
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmilinkirqinv" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2_Hdmilinkirqinv( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2_Hdmilinkirqinv( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispirq2enable" of register "Dispirq2".
**
** Enable for IRQ2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispirq2enable" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2_Dispirq2enable( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2_Dispirq2enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispfiedframeirq2" of register "Dispirq2".
**
** 0 = IRQ on both fields
** 1 = IRQ on field defiend by bit 11 of this register
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispfiedframeirq2" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2_Dispfiedframeirq2( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2_Dispfiedframeirq2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispfiedirq2sel" of register "Dispirq2".
**
** 0 = IRQ on  field 0 (first field)
** 1 = IRQ on  field 1 (second field) 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispfiedirq2sel" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2_Dispfiedirq2sel( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2_Dispfiedirq2sel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispverposirq2" of register "Dispirq2".
**
** vertical position of IRQ2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispverposirq2" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirq2_Dispverposirq2( void );
#else
INLINE uint32_t FREG_VO_GetDispirq2_Dispverposirq2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQ2));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispirqctrl".
**
** This function writes the given value to the register "Dispirqctrl".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispirqctrl( uint32_t value );
#else
INLINE void FREG_VO_SetDispirqctrl( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQCTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispirq2" of register "Dispirqctrl".
**
** DISP_IRQ2 status signal
** Writing 0 clears IRQ2
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispirq2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirqctrl_Dispirq2( uint32_t value );
#else
INLINE void FREG_VO_SetDispirqctrl_Dispirq2( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQCTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispirq1" of register "Dispirqctrl".
**
** DISP_IRQ2 status signal
** Writing 0 clears IRQ1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispirq1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirqctrl_Dispirq1( uint32_t value );
#else
INLINE void FREG_VO_SetDispirqctrl_Dispirq1( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQCTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispirq0" of register "Dispirqctrl".
**
** DISP_IRQ2 status signal
** Writing 0 clears IRQ0
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispirq0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispirqctrl_Dispirq0( uint32_t value );
#else
INLINE void FREG_VO_SetDispirqctrl_Dispirq0( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPIRQCTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispirqctrl".
**
** This function reads the value from the register "Dispirqctrl".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirqctrl( void );
#else
INLINE uint32_t FREG_VO_GetDispirqctrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispirq2" of register "Dispirqctrl".
**
** DISP_IRQ2 status signal
** Writing 0 clears IRQ2
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispirq2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirqctrl_Dispirq2( void );
#else
INLINE uint32_t FREG_VO_GetDispirqctrl_Dispirq2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispirq1" of register "Dispirqctrl".
**
** DISP_IRQ2 status signal
** Writing 0 clears IRQ1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispirq1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirqctrl_Dispirq1( void );
#else
INLINE uint32_t FREG_VO_GetDispirqctrl_Dispirq1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispirq0" of register "Dispirqctrl".
**
** DISP_IRQ2 status signal
** Writing 0 clears IRQ0
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispirq0" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispirqctrl_Dispirq0( void );
#else
INLINE uint32_t FREG_VO_GetDispirqctrl_Dispirq0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPIRQCTRL));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispdachdmictrl".
**
** This function writes the given value to the register "Dispdachdmictrl".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispdacsel5" of register "Dispdachdmictrl".
**
** DAC5 input select
** 1 = SD RGB G signal
** 0 = SD C signal  
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispdacsel5" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Dispdacsel5( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Dispdacsel5( uint32_t value )
{
    register uint32_t mask = 0x00080000UL;
    value = ( value << 19 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispdacsel4" of register "Dispdachdmictrl".
**
** DAC4 input select
** 1 = SD RGB R signal
** 0 = SD Y signal  
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispdacsel4" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Dispdacsel4( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Dispdacsel4( uint32_t value )
{
    register uint32_t mask = 0x00040000UL;
    value = ( value << 18 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispdacsel012" of register "Dispdachdmictrl".
**
** DAC012 input select
** 0 = VE_HD input
** 1 = SD RGB input
** 2 = CVBS (DAC0), Y(DAC1), C(DAC2)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispdacsel012" consists of the bits 17..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00030000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Dispdacsel012( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Dispdacsel012( uint32_t value )
{
    register uint32_t mask = 0x00030000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmiiopcnt" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmiiopcnt" consists of the bits 14..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00007000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmiiopcnt( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmiiopcnt( uint32_t value )
{
    register uint32_t mask = 0x00007000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmiiodcnt" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmiiodcnt" consists of the bits 10..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000700UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmiiodcnt( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmiiodcnt( uint32_t value )
{
    register uint32_t mask = 0x00000700UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmiidrvcnt" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmiidrvcnt" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmiidrvcnt( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmiidrvcnt( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmiirdten" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmiirdten" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmiirdten( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmiirdten( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmiickh" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmiickh" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmiickh( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmiickh( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmihdcpsel" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmihdcpsel" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmihdcpsel( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmihdcpsel( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hdmici2ca" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hdmici2ca" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispdachdmictrl_Hdmici2ca( uint32_t value );
#else
INLINE void FREG_VO_SetDispdachdmictrl_Hdmici2ca( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 10
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPDACHDMICTRL, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispdachdmictrl".
**
** This function reads the value from the register "Dispdachdmictrl".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispdacsel5" of register "Dispdachdmictrl".
**
** DAC5 input select
** 1 = SD RGB G signal
** 0 = SD C signal  
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispdacsel5" consists of the bits 19..19,
**       the given bitgroup value will be shifted left by 19 bits and
**       masked using the bitmask 0x00080000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Dispdacsel5( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Dispdacsel5( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00080000UL ) >> 19;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispdacsel4" of register "Dispdachdmictrl".
**
** DAC4 input select
** 1 = SD RGB R signal
** 0 = SD Y signal  
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispdacsel4" consists of the bits 18..18,
**       the given bitgroup value will be shifted left by 18 bits and
**       masked using the bitmask 0x00040000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Dispdacsel4( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Dispdacsel4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00040000UL ) >> 18;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispdacsel012" of register "Dispdachdmictrl".
**
** DAC012 input select
** 0 = VE_HD input
** 1 = SD RGB input
** 2 = CVBS (DAC0), Y(DAC1), C(DAC2)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispdacsel012" consists of the bits 17..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00030000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Dispdacsel012( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Dispdacsel012( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00030000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmiiopcnt" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmiiopcnt" consists of the bits 14..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00007000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmiiopcnt( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmiiopcnt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00007000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmiiodcnt" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmiiodcnt" consists of the bits 10..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000700UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmiiodcnt( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmiiodcnt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00000700UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmiidrvcnt" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmiidrvcnt" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmiidrvcnt( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmiidrvcnt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmiirdten" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmiirdten" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmiirdten( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmiirdten( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmiickh" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmiickh" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmiickh( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmiickh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmihdcpsel" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmihdcpsel" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmihdcpsel( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmihdcpsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hdmici2ca" of register "Dispdachdmictrl".
**
** HDMI control signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hdmici2ca" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispdachdmictrl_Hdmici2ca( void );
#else
INLINE uint32_t FREG_VO_GetDispdachdmictrl_Hdmici2ca( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPDACHDMICTRL));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispmixconf".
**
** This function writes the given value to the register "Dispmixconf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconf( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconf( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dispmixvoa" of register "Dispmixconf".
**
** Alpha value of video in disp_mix module
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dispmixvoa" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconf_Dispmixvoa( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconf_Dispmixvoa( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mix3inselect" of register "Dispmixconf".
**
** Select input of mixer 3
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mix3inselect" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconf_Mix3inselect( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconf_Mix3inselect( uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mix2inselect" of register "Dispmixconf".
**
** Select input of mixer 2
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mix2inselect" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconf_Mix2inselect( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconf_Mix2inselect( uint32_t value )
{
    register uint32_t mask = 0x00000300UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mix1inselect" of register "Dispmixconf".
**
** Select input of mixer 1
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mix1inselect" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconf_Mix1inselect( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconf_Mix1inselect( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mix0inselect" of register "Dispmixconf".
**
** Select input of mixer 0
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mix0inselect" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconf_Mix0inselect( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconf_Mix0inselect( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONF, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispmixconf".
**
** This function reads the value from the register "Dispmixconf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconf( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONF));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispmixvoa" of register "Dispmixconf".
**
** Alpha value of video in disp_mix module
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispmixvoa" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconf_Dispmixvoa( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconf_Dispmixvoa( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONF));
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mix3inselect" of register "Dispmixconf".
**
** Select input of mixer 3
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mix3inselect" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconf_Mix3inselect( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconf_Mix3inselect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONF));
    value = ( value & 0x00003000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mix2inselect" of register "Dispmixconf".
**
** Select input of mixer 2
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mix2inselect" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconf_Mix2inselect( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconf_Mix2inselect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONF));
    value = ( value & 0x00000300UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mix1inselect" of register "Dispmixconf".
**
** Select input of mixer 1
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mix1inselect" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconf_Mix1inselect( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconf_Mix1inselect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONF));
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mix0inselect" of register "Dispmixconf".
**
** Select input of mixer 0
** 0 = VO
** 1 = OSD1
** 2 = OSD2
** 3 = OSD3(cursor)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mix0inselect" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconf_Mix0inselect( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconf_Mix0inselect( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONF));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispmixconfenable".
**
** This function writes the given value to the register "Dispmixconfenable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconfenable( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconfenable( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONFENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enablergblut" of register "Dispmixconfenable".
**
** 0 = RGB LUT not enabled
** 1 = RGB LUT enabled                                                                      
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enablergblut" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconfenable_Enablergblut( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconfenable_Enablergblut( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONFENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enablergbconv" of register "Dispmixconfenable".
**
** 0 = no RGB to YUV conversion
** 1 = RGB to YUV conversion                                                                       
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enablergbconv" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconfenable_Enablergbconv( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconfenable_Enablergbconv( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONFENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enableyuvlut" of register "Dispmixconfenable".
**
** 0 = YUV LUT not enabled
** 1 = YUV LUT enabled                                                                      
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enableyuvlut" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconfenable_Enableyuvlut( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconfenable_Enableyuvlut( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONFENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enableyuvconv" of register "Dispmixconfenable".
**
** 0 = no YUV to RGB conversion
** 1 = YUV to RGB conversion                                                                       
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enableyuvconv" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispmixconfenable_Enableyuvconv( uint32_t value );
#else
INLINE void FREG_VO_SetDispmixconfenable_Enableyuvconv( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPMIXCONFENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispmixconfenable".
**
** This function reads the value from the register "Dispmixconfenable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconfenable( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconfenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enablergblut" of register "Dispmixconfenable".
**
** 0 = RGB LUT not enabled
** 1 = RGB LUT enabled                                                                      
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enablergblut" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconfenable_Enablergblut( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconfenable_Enablergblut( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enablergbconv" of register "Dispmixconfenable".
**
** 0 = no RGB to YUV conversion
** 1 = RGB to YUV conversion                                                                       
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enablergbconv" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconfenable_Enablergbconv( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconfenable_Enablergbconv( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enableyuvlut" of register "Dispmixconfenable".
**
** 0 = YUV LUT not enabled
** 1 = YUV LUT enabled                                                                      
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enableyuvlut" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconfenable_Enableyuvlut( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconfenable_Enableyuvlut( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enableyuvconv" of register "Dispmixconfenable".
**
** 0 = no YUV to RGB conversion
** 1 = YUV to RGB conversion                                                                       
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enableyuvconv" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispmixconfenable_Enableyuvconv( void );
#else
INLINE uint32_t FREG_VO_GetDispmixconfenable_Enableyuvconv( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPMIXCONFENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispcrcy".
**
** This function reads the value from the register "Dispcrcy".
**
** Y value of CRC counter
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcrcy( void );
#else
INLINE uint32_t FREG_VO_GetDispcrcy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCRCY));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispcrcy" of register "Dispcrcy".
**
** Y value of CRC counter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispcrcy" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcrcy_Dispcrcy( void );
#else
INLINE uint32_t FREG_VO_GetDispcrcy_Dispcrcy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCRCY));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispcrccr".
**
** This function reads the value from the register "Dispcrccr".
**
** CR value of CRC counter
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcrccr( void );
#else
INLINE uint32_t FREG_VO_GetDispcrccr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCRCCR));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispcrccr" of register "Dispcrccr".
**
** CR value of CRC counter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispcrccr" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcrccr_Dispcrccr( void );
#else
INLINE uint32_t FREG_VO_GetDispcrccr_Dispcrccr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCRCCR));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispcrccb".
**
** This function reads the value from the register "Dispcrccb".
**
** CB value of CRC counter
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcrccb( void );
#else
INLINE uint32_t FREG_VO_GetDispcrccb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCRCCB));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dispcrccb" of register "Dispcrccb".
**
** CB value of CRC counter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dispcrccb" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcrccb_Dispcrccb( void );
#else
INLINE uint32_t FREG_VO_GetDispcrccb_Dispcrccb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCRCCB));
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispframecounter".
**
** This function reads the value from the register "Dispframecounter".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispframecounter( void );
#else
INLINE uint32_t FREG_VO_GetDispframecounter( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPFRAMECOUNTER));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Framecounter" of register "Dispframecounter".
**
** frame counter value
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Framecounter" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispframecounter_Framecounter( void );
#else
INLINE uint32_t FREG_VO_GetDispframecounter_Framecounter( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPFRAMECOUNTER));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disppicpos".
**
** This function reads the value from the register "Disppicpos".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisppicpos( void );
#else
INLINE uint32_t FREG_VO_GetDisppicpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPPICPOS));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Currenthpos" of register "Disppicpos".
**
** current H pos of disp controller
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Currenthpos" consists of the bits 27..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x0FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisppicpos_Currenthpos( void );
#else
INLINE uint32_t FREG_VO_GetDisppicpos_Currenthpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPPICPOS));
    value = ( value & 0x0FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Currentfield" of register "Disppicpos".
**
** current field of disp controller
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Currentfield" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisppicpos_Currentfield( void );
#else
INLINE uint32_t FREG_VO_GetDisppicpos_Currentfield( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPPICPOS));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Currentvpos" of register "Disppicpos".
**
** current V pos of disp controller
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Currentvpos" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisppicpos_Currentvpos( void );
#else
INLINE uint32_t FREG_VO_GetDisppicpos_Currentvpos( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPPICPOS));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdpathconfig".
**
** This function writes the given value to the register "Sdpathconfig".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdpathconfig( uint32_t value );
#else
INLINE void FREG_VO_SetSdpathconfig( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDPATHCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YDelaySd" of register "Sdpathconfig".
**
** Pixel delay for Y signal in SD path
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YDelaySd" consists of the bits 7..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000000E0UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdpathconfig_YDelaySd( uint32_t value );
#else
INLINE void FREG_VO_SetSdpathconfig_YDelaySd( uint32_t value )
{
    register uint32_t mask = 0x000000E0UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDPATHCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CrcbDelaySd" of register "Sdpathconfig".
**
** Pixel delay for CrCb signal in SD path (recommended setting 1)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CrcbDelaySd" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdpathconfig_CrcbDelaySd( uint32_t value );
#else
INLINE void FREG_VO_SetSdpathconfig_CrcbDelaySd( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDPATHCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CrcbExchange" of register "Sdpathconfig".
**
** exchanges Cr and Cb pixels ON SD path
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CrcbExchange" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdpathconfig_CrcbExchange( uint32_t value );
#else
INLINE void FREG_VO_SetSdpathconfig_CrcbExchange( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDPATHCONFIG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdpathconfig".
**
** This function reads the value from the register "Sdpathconfig".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdpathconfig( void );
#else
INLINE uint32_t FREG_VO_GetSdpathconfig( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YDelaySd" of register "Sdpathconfig".
**
** Pixel delay for Y signal in SD path
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "YDelaySd" consists of the bits 7..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000000E0UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdpathconfig_YDelaySd( void );
#else
INLINE uint32_t FREG_VO_GetSdpathconfig_YDelaySd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG));
    value = ( value & 0x000000E0UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CrcbDelaySd" of register "Sdpathconfig".
**
** Pixel delay for CrCb signal in SD path (recommended setting 1)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CrcbDelaySd" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdpathconfig_CrcbDelaySd( void );
#else
INLINE uint32_t FREG_VO_GetSdpathconfig_CrcbDelaySd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG));
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CrcbExchange" of register "Sdpathconfig".
**
** exchanges Cr and Cb pixels ON SD path
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "CrcbExchange" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdpathconfig_CrcbExchange( void );
#else
INLINE uint32_t FREG_VO_GetSdpathconfig_CrcbExchange( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDPATHCONFIG));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vofiltermode".
**
** This function writes the given value to the index-th entry of the register
** array Vofiltermode.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Veraddphase" of register "Vofiltermode".
**
** two LSB of vertical counter are used as phase information for V-filter coefficients
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Veraddphase" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode_Veraddphase( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode_Veraddphase( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horaddphase" of register "Vofiltermode".
**
** two LSB of horizontal counter are used as phase information for H-filter coefficients
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horaddphase" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode_Horaddphase( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode_Horaddphase( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verfilterup" of register "Vofiltermode".
**
** 0 = less output then input lines
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verfilterup" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode_Verfilterup( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode_Verfilterup( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verfilteron" of register "Vofiltermode".
**
** enable for vertical filter
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verfilteron" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode_Verfilteron( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode_Verfilteron( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horfilterup" of register "Vofiltermode".
**
** 0 = less output then input pixel
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horfilterup" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode_Horfilterup( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode_Horfilterup( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horfilteron" of register "Vofiltermode".
**
** enable for horizontal filter
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horfilteron" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetVofiltermode_Horfilteron( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetVofiltermode_Horfilteron( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vofiltermode".
**
** This function reads the value from the index-th entry of the register
** array Vofiltermode.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Veraddphase" of register "Vofiltermode".
**
** two LSB of vertical counter are used as phase information for V-filter coefficients
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Veraddphase" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode_Veraddphase( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode_Veraddphase( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horaddphase" of register "Vofiltermode".
**
** two LSB of horizontal counter are used as phase information for H-filter coefficients
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horaddphase" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode_Horaddphase( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode_Horaddphase( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verfilterup" of register "Vofiltermode".
**
** 0 = less output then input lines
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verfilterup" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode_Verfilterup( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode_Verfilterup( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verfilteron" of register "Vofiltermode".
**
** enable for vertical filter
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verfilteron" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode_Verfilteron( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode_Verfilteron( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horfilterup" of register "Vofiltermode".
**
** 0 = less output then input pixel
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horfilterup" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode_Horfilterup( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode_Horfilterup( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horfilteron" of register "Vofiltermode".
**
** enable for horizontal filter
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horfilteron" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVofiltermode_Horfilteron( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetVofiltermode_Horfilteron( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_VOFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Vomode".
**
** This function writes the given value to the register "Vomode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetVomode( uint32_t value );
#else
INLINE void FREG_VO_SetVomode( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vofieldmode" of register "Vomode".
**
** 0 = normal interlaced mode
** 1 = progressive or single field output
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vofieldmode" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_VO_SetVomode_Vofieldmode( uint32_t value );
#else
INLINE void FREG_VO_SetVomode_Vofieldmode( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Voprogr" of register "Vomode".
**
** 0 = source read in progressive
** 1 = source read with field info from bit 14
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Voprogr" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern void FREG_VO_SetVomode_Voprogr( uint32_t value );
#else
INLINE void FREG_VO_SetVomode_Voprogr( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vofield" of register "Vomode".
**
** selects the field to be displayed (single field display)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vofield" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern void FREG_VO_SetVomode_Vofield( uint32_t value );
#else
INLINE void FREG_VO_SetVomode_Vofield( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_VOMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_VOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_VOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Vomode".
**
** This function reads the value from the register "Vomode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVomode( void );
#else
INLINE uint32_t FREG_VO_GetVomode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOMODE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vofieldmode" of register "Vomode".
**
** 0 = normal interlaced mode
** 1 = progressive or single field output
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vofieldmode" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVomode_Vofieldmode( void );
#else
INLINE uint32_t FREG_VO_GetVomode_Vofieldmode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOMODE));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Voprogr" of register "Vomode".
**
** 0 = source read in progressive
** 1 = source read with field info from bit 14
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Voprogr" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVomode_Voprogr( void );
#else
INLINE uint32_t FREG_VO_GetVomode_Voprogr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOMODE));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vofield" of register "Vomode".
**
** selects the field to be displayed (single field display)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vofield" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetVomode_Vofield( void );
#else
INLINE uint32_t FREG_VO_GetVomode_Vofield( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_VOMODE));
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdglobaloffset".
**
** This function writes the given value to the index-th entry of the register
** array Osdglobaloffset.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdglobaloffset( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdglobaloffset( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDGLOBALOFFSET+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDGLOBALOFFSET+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Globaloffset" of register "Osdglobaloffset".
**
** global address offset for layer
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Globaloffset" consists of the bits 31..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0xFFFFFC00UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdglobaloffset_Globaloffset( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdglobaloffset_Globaloffset( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFC00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDGLOBALOFFSET+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDGLOBALOFFSET+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDGLOBALOFFSET+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdglobaloffset".
**
** This function reads the value from the index-th entry of the register
** array Osdglobaloffset.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdglobaloffset( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdglobaloffset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDGLOBALOFFSET+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Globaloffset" of register "Osdglobaloffset".
**
** global address offset for layer
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Globaloffset" consists of the bits 31..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0xFFFFFC00UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdglobaloffset_Globaloffset( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdglobaloffset_Globaloffset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDGLOBALOFFSET+(index*0x4000)));
    value = ( value & 0xFFFFFC00UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdhsize".
**
** This function writes the given value to the index-th entry of the register
** array Osdhsize.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhsize( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhsize( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHSIZE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHSIZE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hsize" of register "Osdhsize".
**
** horizontal line size in memory.
**  It must be a multiple of 128 byte.  The actual line size depends on the OSD mode
** 4bit = 256 pixel
** 8 bit = 128 pixel
** 16 bit = 64 pixel
** 32 bit = 32 pixel
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hsize" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhsize_Hsize( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhsize_Hsize( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000003FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDHSIZE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHSIZE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHSIZE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdhsize".
**
** This function reads the value from the index-th entry of the register
** array Osdhsize.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhsize( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhsize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHSIZE+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hsize" of register "Osdhsize".
**
** horizontal line size in memory.
**  It must be a multiple of 128 byte.  The actual line size depends on the OSD mode
** 4bit = 256 pixel
** 8 bit = 128 pixel
** 16 bit = 64 pixel
** 32 bit = 32 pixel
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hsize" consists of the bits 5..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000003FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhsize_Hsize( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhsize_Hsize( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHSIZE+(index*0x4000)));
    value = ( value & 0x0000003FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdbitperpixel".
**
** This function writes the given value to the index-th entry of the register
** array Osdbitperpixel.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdbitperpixel( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdbitperpixel( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDBITPERPIXEL+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDBITPERPIXEL+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bitperpixel" of register "Osdbitperpixel".
**
** bit per displayed pixel.
** 
** 1 = 4 bit per pixel
** 2 = 8 bit per pixel
** 4 = 16 bit per pixel
** 8 = 32 bit per pixel
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bitperpixel" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdbitperpixel_Bitperpixel( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdbitperpixel_Bitperpixel( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDBITPERPIXEL+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDBITPERPIXEL+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDBITPERPIXEL+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdbitperpixel".
**
** This function reads the value from the index-th entry of the register
** array Osdbitperpixel.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdbitperpixel( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdbitperpixel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDBITPERPIXEL+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bitperpixel" of register "Osdbitperpixel".
**
** bit per displayed pixel.
** 
** 1 = 4 bit per pixel
** 2 = 8 bit per pixel
** 4 = 16 bit per pixel
** 8 = 32 bit per pixel
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bitperpixel" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdbitperpixel_Bitperpixel( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdbitperpixel_Bitperpixel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDBITPERPIXEL+(index*0x4000)));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdhornum".
**
** This function writes the given value to the index-th entry of the register
** array Osdhornum.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhornum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhornum( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORNUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORNUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hornum" of register "Osdhornum".
**
** horizontal numerator for calculating polyphase filter (add value for modulo counter)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hornum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhornum_Hornum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhornum_Hornum( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDHORNUM+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORNUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORNUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdhornum".
**
** This function reads the value from the index-th entry of the register
** array Osdhornum.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhornum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhornum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORNUM+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hornum" of register "Osdhornum".
**
** horizontal numerator for calculating polyphase filter (add value for modulo counter)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hornum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhornum_Hornum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhornum_Hornum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORNUM+(index*0x4000)));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdhordenum".
**
** This function writes the given value to the index-th entry of the register
** array Osdhordenum.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhordenum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhordenum( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORDENUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORDENUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hordenum" of register "Osdhordenum".
**
** horizontal denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hordenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhordenum_Hordenum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhordenum_Hordenum( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0001FFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDHORDENUM+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORDENUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORDENUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdhordenum".
**
** This function reads the value from the index-th entry of the register
** array Osdhordenum.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhordenum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhordenum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORDENUM+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hordenum" of register "Osdhordenum".
**
** horizontal denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hordenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhordenum_Hordenum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhordenum_Hordenum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORDENUM+(index*0x4000)));
    value = ( value & 0x0001FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdvernum".
**
** This function writes the given value to the index-th entry of the register
** array Osdvernum.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdvernum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdvernum( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDVERNUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDVERNUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vernum" of register "Osdvernum".
**
** vertical numerator for calculating polyphase filter (add value for modulo counter)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vernum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdvernum_Vernum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdvernum_Vernum( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDVERNUM+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDVERNUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDVERNUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdvernum".
**
** This function reads the value from the index-th entry of the register
** array Osdvernum.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdvernum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdvernum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDVERNUM+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vernum" of register "Osdvernum".
**
** vertical numerator for calculating polyphase filter (add value for modulo counter)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vernum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdvernum_Vernum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdvernum_Vernum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDVERNUM+(index*0x4000)));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdverdenum".
**
** This function writes the given value to the index-th entry of the register
** array Osdverdenum.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdverdenum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdverdenum( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDVERDENUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDVERDENUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verdenum" of register "Osdverdenum".
**
** vertical denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verdenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdverdenum_Verdenum( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdverdenum_Verdenum( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0001FFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDVERDENUM+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDVERDENUM+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDVERDENUM+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdverdenum".
**
** This function reads the value from the index-th entry of the register
** array Osdverdenum.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdverdenum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdverdenum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDVERDENUM+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verdenum" of register "Osdverdenum".
**
** vertical denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verdenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdverdenum_Verdenum( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdverdenum_Verdenum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDVERDENUM+(index*0x4000)));
    value = ( value & 0x0001FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdhordisppixel".
**
** This function writes the given value to the index-th entry of the register
** array Osdhordisppixel.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhordisppixel( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhordisppixel( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORDISPPIXEL+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORDISPPIXEL+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hordisppixel" of register "Osdhordisppixel".
**
** horizontal displayed pixel (at the output of the filter)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hordisppixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhordisppixel_Hordisppixel( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhordisppixel_Hordisppixel( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDHORDISPPIXEL+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORDISPPIXEL+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORDISPPIXEL+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdhordisppixel".
**
** This function reads the value from the index-th entry of the register
** array Osdhordisppixel.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhordisppixel( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhordisppixel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORDISPPIXEL+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hordisppixel" of register "Osdhordisppixel".
**
** horizontal displayed pixel (at the output of the filter)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hordisppixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhordisppixel_Hordisppixel( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhordisppixel_Hordisppixel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORDISPPIXEL+(index*0x4000)));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdhorreadpixel".
**
** This function writes the given value to the index-th entry of the register
** array Osdhorreadpixel.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhorreadpixel( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhorreadpixel( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORREADPIXEL+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORREADPIXEL+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horreadpixel" of register "Osdhorreadpixel".
**
** horizontal pixel read from line buffer (actual value - 1)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horreadpixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdhorreadpixel_Horreadpixel( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdhorreadpixel_Horreadpixel( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDHORREADPIXEL+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDHORREADPIXEL+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDHORREADPIXEL+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdhorreadpixel".
**
** This function reads the value from the index-th entry of the register
** array Osdhorreadpixel.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhorreadpixel( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhorreadpixel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORREADPIXEL+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horreadpixel" of register "Osdhorreadpixel".
**
** horizontal pixel read from line buffer (actual value - 1)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horreadpixel" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdhorreadpixel_Horreadpixel( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdhorreadpixel_Horreadpixel( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDHORREADPIXEL+(index*0x4000)));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdinitialshift".
**
** This function writes the given value to the index-th entry of the register
** array Osdinitialshift.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdinitialshift( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdinitialshift( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDINITIALSHIFT+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDINITIALSHIFT+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Initialshift" of register "Osdinitialshift".
**
** initial shifted pixels into H-filter.
**  Can be used to adjust horizontal read start position. Initial shift 4 is used to adjust filter output to the first pixel
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Initialshift" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdinitialshift_Initialshift( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdinitialshift_Initialshift( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000007FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDINITIALSHIFT+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDINITIALSHIFT+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDINITIALSHIFT+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdinitialshift".
**
** This function reads the value from the index-th entry of the register
** array Osdinitialshift.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdinitialshift( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdinitialshift( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDINITIALSHIFT+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Initialshift" of register "Osdinitialshift".
**
** initial shifted pixels into H-filter.
**  Can be used to adjust horizontal read start position. Initial shift 4 is used to adjust filter output to the first pixel
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Initialshift" consists of the bits 6..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000007FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdinitialshift_Initialshift( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdinitialshift_Initialshift( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDINITIALSHIFT+(index*0x4000)));
    value = ( value & 0x0000007FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdfiltermode".
**
** This function writes the given value to the index-th entry of the register
** array Osdfiltermode.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Veraddphase" of register "Osdfiltermode".
**
** two LSB of vertical counter are used as phase information for V-filter coefficients
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Veraddphase" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode_Veraddphase( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode_Veraddphase( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horaddphase" of register "Osdfiltermode".
**
** two LSB of horizontal counter are used as phase information for H-filter coefficients
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horaddphase" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode_Horaddphase( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode_Horaddphase( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verfilterup" of register "Osdfiltermode".
**
** 0 = less output then input lines
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verfilterup" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode_Verfilterup( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode_Verfilterup( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verfilteron" of register "Osdfiltermode".
**
** enable for vertical filter
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verfilteron" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode_Verfilteron( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode_Verfilteron( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horfilterup" of register "Osdfiltermode".
**
** 0 = less output then input pixel
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horfilterup" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode_Horfilterup( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode_Horfilterup( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horfilteron" of register "Osdfiltermode".
**
** enable for horizontal filter
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horfilteron" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdfiltermode_Horfilteron( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdfiltermode_Horfilteron( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDFILTERMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdfiltermode".
**
** This function reads the value from the index-th entry of the register
** array Osdfiltermode.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Veraddphase" of register "Osdfiltermode".
**
** two LSB of vertical counter are used as phase information for V-filter coefficients
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Veraddphase" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode_Veraddphase( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode_Veraddphase( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horaddphase" of register "Osdfiltermode".
**
** two LSB of horizontal counter are used as phase information for H-filter coefficients
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horaddphase" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode_Horaddphase( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode_Horaddphase( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verfilterup" of register "Osdfiltermode".
**
** 0 = less output then input lines
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verfilterup" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode_Verfilterup( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode_Verfilterup( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verfilteron" of register "Osdfiltermode".
**
** enable for vertical filter
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verfilteron" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode_Verfilteron( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode_Verfilteron( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horfilterup" of register "Osdfiltermode".
**
** 0 = less output then input pixel
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horfilterup" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode_Horfilterup( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode_Horfilterup( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horfilteron" of register "Osdfiltermode".
**
** enable for horizontal filter
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horfilteron" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdfiltermode_Horfilteron( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdfiltermode_Horfilteron( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDFILTERMODE+(index*0x4000)));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Layerenable".
**
** This function writes the given value to the index-th entry of the register
** array Layerenable.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetLayerenable( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetLayerenable( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_LAYERENABLE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_LAYERENABLE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Layerenable" of register "Layerenable".
**
** enables the layer
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Layerenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetLayerenable_Layerenable( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetLayerenable_Layerenable( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_LAYERENABLE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_LAYERENABLE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_LAYERENABLE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Layerenable".
**
** This function reads the value from the index-th entry of the register
** array Layerenable.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetLayerenable( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetLayerenable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_LAYERENABLE+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Layerenable" of register "Layerenable".
**
** enables the layer
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Layerenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetLayerenable_Layerenable( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetLayerenable_Layerenable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_LAYERENABLE+(index*0x4000)));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdalpha1".
**
** This function writes the given value to the index-th entry of the register
** array Osdalpha1.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdalpha1( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdalpha1( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDALPHA1+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDALPHA1+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osdalpha1" of register "Osdalpha1".
**
** Alpha blending value for OSD/Graphic layer.
**  Used for CCIR and YCrCb mode only. In all other modes, the alpha blending value is in the CLUT or in the data stream.
** 0: fully transparent:
** 255: fully solid
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osdalpha1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdalpha1_Osdalpha1( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdalpha1_Osdalpha1( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDALPHA1+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDALPHA1+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDALPHA1+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdalpha1".
**
** This function reads the value from the index-th entry of the register
** array Osdalpha1.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdalpha1( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdalpha1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDALPHA1+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osdalpha1" of register "Osdalpha1".
**
** Alpha blending value for OSD/Graphic layer.
**  Used for CCIR and YCrCb mode only. In all other modes, the alpha blending value is in the CLUT or in the data stream.
** 0: fully transparent:
** 255: fully solid
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osdalpha1" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdalpha1_Osdalpha1( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdalpha1_Osdalpha1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDALPHA1+(index*0x4000)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdalpha2".
**
** This function writes the given value to the index-th entry of the register
** array Osdalpha2.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdalpha2( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdalpha2( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDALPHA2+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDALPHA2+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osdalpha2" of register "Osdalpha2".
**
** Second alpha blending value for OSD 5551 mode
** If the alpha bit is 0, then alpha1 is used if alpha bit is 1 the alpha2 is used
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osdalpha2" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdalpha2_Osdalpha2( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdalpha2_Osdalpha2( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDALPHA2+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDALPHA2+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDALPHA2+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdalpha2".
**
** This function reads the value from the index-th entry of the register
** array Osdalpha2.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdalpha2( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdalpha2( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDALPHA2+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osdalpha2" of register "Osdalpha2".
**
** Second alpha blending value for OSD 5551 mode
** If the alpha bit is 0, then alpha1 is used if alpha bit is 1 the alpha2 is used
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osdalpha2" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdalpha2_Osdalpha2( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdalpha2_Osdalpha2( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDALPHA2+(index*0x4000)));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv11".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv11.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv11( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv11( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV11+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV11+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv11" of register "Osdrgbyuv11".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv11" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv11_Rgbyuv11( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv11_Rgbyuv11( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV11+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV11+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV11+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv11".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv11.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv11( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv11( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV11+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv11" of register "Osdrgbyuv11".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv11" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv11_Rgbyuv11( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv11_Rgbyuv11( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV11+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv12".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv12.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv12( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv12( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV12+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV12+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv12" of register "Osdrgbyuv12".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv12" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv12_Rgbyuv12( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv12_Rgbyuv12( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV12+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV12+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV12+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv12".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv12.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv12( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv12( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV12+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv12" of register "Osdrgbyuv12".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv12" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv12_Rgbyuv12( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv12_Rgbyuv12( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV12+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv13".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv13.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv13( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv13( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV13+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV13+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv13" of register "Osdrgbyuv13".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv13" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv13_Rgbyuv13( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv13_Rgbyuv13( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV13+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV13+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV13+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv13".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv13.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv13( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv13( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV13+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv13" of register "Osdrgbyuv13".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv13" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv13_Rgbyuv13( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv13_Rgbyuv13( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV13+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv14".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv14.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv14( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv14( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV14+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV14+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv14" of register "Osdrgbyuv14".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv14" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv14_Rgbyuv14( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv14_Rgbyuv14( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV14+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV14+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV14+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv14".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv14.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv14( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv14( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV14+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv14" of register "Osdrgbyuv14".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv14" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv14_Rgbyuv14( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv14_Rgbyuv14( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV14+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv21".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv21.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv21( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv21( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV21+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV21+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv21" of register "Osdrgbyuv21".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv21" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv21_Rgbyuv21( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv21_Rgbyuv21( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV21+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV21+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV21+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv21".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv21.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv21( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv21( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV21+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv21" of register "Osdrgbyuv21".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv21" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv21_Rgbyuv21( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv21_Rgbyuv21( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV21+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv22".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv22.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv22( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv22( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV22+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV22+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv22" of register "Osdrgbyuv22".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv22" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv22_Rgbyuv22( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv22_Rgbyuv22( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV22+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV22+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV22+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv22".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv22.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv22( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv22( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV22+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv22" of register "Osdrgbyuv22".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv22" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv22_Rgbyuv22( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv22_Rgbyuv22( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV22+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv23".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv23.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv23( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv23( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV23+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV23+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv23" of register "Osdrgbyuv23".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv23" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv23_Rgbyuv23( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv23_Rgbyuv23( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV23+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV23+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV23+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv23".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv23.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv23( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv23( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV23+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv23" of register "Osdrgbyuv23".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv23" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv23_Rgbyuv23( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv23_Rgbyuv23( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV23+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv24".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv24.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv24( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv24( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV24+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV24+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv24" of register "Osdrgbyuv24".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv24" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv24_Rgbyuv24( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv24_Rgbyuv24( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV24+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV24+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV24+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv24".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv24.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv24( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv24( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV24+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv24" of register "Osdrgbyuv24".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv24" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv24_Rgbyuv24( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv24_Rgbyuv24( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV24+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv31".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv31.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv31( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv31( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV31+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV31+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv31" of register "Osdrgbyuv31".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv31" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv31_Rgbyuv31( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv31_Rgbyuv31( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV31+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV31+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV31+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv31".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv31.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv31( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv31( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV31+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv31" of register "Osdrgbyuv31".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv31" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv31_Rgbyuv31( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv31_Rgbyuv31( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV31+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv32".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv32.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv32( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv32( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV32+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV32+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv32" of register "Osdrgbyuv32".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv32" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv32_Rgbyuv32( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv32_Rgbyuv32( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV32+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV32+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV32+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv32".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv32.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv32( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv32( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV32+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv32" of register "Osdrgbyuv32".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv32" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv32_Rgbyuv32( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv32_Rgbyuv32( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV32+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv33".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv33.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv33( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv33( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV33+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV33+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv33" of register "Osdrgbyuv33".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv33" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv33_Rgbyuv33( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv33_Rgbyuv33( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV33+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV33+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV33+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv33".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv33.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv33( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv33( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV33+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv33" of register "Osdrgbyuv33".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv33" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv33_Rgbyuv33( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv33_Rgbyuv33( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV33+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdrgbyuv34".
**
** This function writes the given value to the index-th entry of the register
** array Osdrgbyuv34.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv34( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv34( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV34+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV34+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rgbyuv34" of register "Osdrgbyuv34".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rgbyuv34" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdrgbyuv34_Rgbyuv34( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdrgbyuv34_Rgbyuv34( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000001FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDRGBYUV34+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDRGBYUV34+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDRGBYUV34+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdrgbyuv34".
**
** This function reads the value from the index-th entry of the register
** array Osdrgbyuv34.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv34( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv34( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV34+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rgbyuv34" of register "Osdrgbyuv34".
**
** RGB2YUV conversion factor
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rgbyuv34" consists of the bits 8..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000001FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdrgbyuv34_Rgbyuv34( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdrgbyuv34_Rgbyuv34( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDRGBYUV34+(index*0x4000)));
    value = ( value & 0x000001FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvflt".
**
** This function writes the given value to the index-th entry of the register
** array Sdvflt.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdvflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetSdvflt( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return;
    #endif
    FREG_VO_SdvfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVFLT+(index*0x8), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVFLT+(index*0x8))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sdvflt" of register "Sdvflt".
**
** VFLT filter coefficients of SD scaler
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdvflt" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdvflt_Sdvflt( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetSdvflt_Sdvflt( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFFFFFFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvfltMirror[index] & ~mask;
    FREG_VO_SdvfltMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVFLT+(index*0x8), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVFLT+(index*0x8))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvflt".
**
** This function reads the value from the index-th entry of the register
** array Sdvflt.
**
** VFLT filter coefficients of SD scaler
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdvflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmSdvflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 64 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_SdvfltMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sdvflt" of register "Sdvflt".
**
** VFLT filter coefficients of SD scaler
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdvflt" consists of the bits 31..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0xFFFFFFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdvflt_Sdvflt( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmSdvflt_Sdvflt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 64 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_SdvfltMirror[index];
    value = ( value & 0xFFFFFFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Cursorram".
**
** This function writes the given value to the index-th entry of the register
** array Cursorram.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetCursorram( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCursorram( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 4096 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORRAM+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORRAM+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhornum".
**
** This function writes the given value to the register "Sdhornum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdhornum( uint32_t value );
#else
INLINE void FREG_VO_SetSdhornum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hornum" of register "Sdhornum".
**
** horizontal numerator for calculating polyphase filter (add value for modulo counter)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hornum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdhornum_Hornum( uint32_t value );
#else
INLINE void FREG_VO_SetSdhornum_Hornum( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDHORNUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhornum".
**
** This function reads the value from the register "Sdhornum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhornum( void );
#else
INLINE uint32_t FREG_VO_GetSdhornum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORNUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hornum" of register "Sdhornum".
**
** horizontal numerator for calculating polyphase filter (add value for modulo counter)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hornum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhornum_Hornum( void );
#else
INLINE uint32_t FREG_VO_GetSdhornum_Hornum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORNUM));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhordenum".
**
** This function writes the given value to the register "Sdhordenum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdhordenum( uint32_t value );
#else
INLINE void FREG_VO_SetSdhordenum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Hordenum" of register "Sdhordenum".
**
** horizontal denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Hordenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdhordenum_Hordenum( uint32_t value );
#else
INLINE void FREG_VO_SetSdhordenum_Hordenum( uint32_t value )
{
    register uint32_t mask = 0x0001FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDHORDENUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhordenum".
**
** This function reads the value from the register "Sdhordenum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhordenum( void );
#else
INLINE uint32_t FREG_VO_GetSdhordenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORDENUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Hordenum" of register "Sdhordenum".
**
** horizontal denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Hordenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhordenum_Hordenum( void );
#else
INLINE uint32_t FREG_VO_GetSdhordenum_Hordenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORDENUM));
    value = ( value & 0x0001FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdvernum".
**
** This function writes the given value to the register "Sdvernum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdvernum( uint32_t value );
#else
INLINE void FREG_VO_SetSdvernum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVERNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVERNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Vernum" of register "Sdvernum".
**
** vertical numerator for calculating polyphase filter (add value for modulo counter)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Vernum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdvernum_Vernum( uint32_t value );
#else
INLINE void FREG_VO_SetSdvernum_Vernum( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDVERNUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVERNUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVERNUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdvernum".
**
** This function reads the value from the register "Sdvernum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdvernum( void );
#else
INLINE uint32_t FREG_VO_GetSdvernum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDVERNUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Vernum" of register "Sdvernum".
**
** vertical numerator for calculating polyphase filter (add value for modulo counter)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Vernum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdvernum_Vernum( void );
#else
INLINE uint32_t FREG_VO_GetSdvernum_Vernum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDVERNUM));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdverdenum".
**
** This function writes the given value to the register "Sdverdenum".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdverdenum( uint32_t value );
#else
INLINE void FREG_VO_SetSdverdenum( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVERDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVERDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verdenum" of register "Sdverdenum".
**
** vertical denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verdenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdverdenum_Verdenum( uint32_t value );
#else
INLINE void FREG_VO_SetSdverdenum_Verdenum( uint32_t value )
{
    register uint32_t mask = 0x0001FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDVERDENUM)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVERDENUM, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVERDENUM)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdverdenum".
**
** This function reads the value from the register "Sdverdenum".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdverdenum( void );
#else
INLINE uint32_t FREG_VO_GetSdverdenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDVERDENUM));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verdenum" of register "Sdverdenum".
**
** vertical denumerator for calculating polyphase filter (modulo part) max.
**  value 0x10000
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verdenum" consists of the bits 16..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0001FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdverdenum_Verdenum( void );
#else
INLINE uint32_t FREG_VO_GetSdverdenum_Verdenum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDVERDENUM));
    value = ( value & 0x0001FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdfiltermode".
**
** This function writes the given value to the register "Sdfiltermode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Veraddphase" of register "Sdfiltermode".
**
** two LSB of vertical counter are used as phase information for V-filter coefficients
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Veraddphase" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode_Veraddphase( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode_Veraddphase( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horaddphase" of register "Sdfiltermode".
**
** two LSB of horizontal counter are used as phase information for H-filter coefficients
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horaddphase" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode_Horaddphase( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode_Horaddphase( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verfilterup" of register "Sdfiltermode".
**
** 0 = less output then input lines
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verfilterup" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode_Verfilterup( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode_Verfilterup( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Verfilteron" of register "Sdfiltermode".
**
** enable for vertical filter
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Verfilteron" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode_Verfilteron( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode_Verfilteron( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horfilterup" of register "Sdfiltermode".
**
** 0 = less output then input pixel
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horfilterup" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode_Horfilterup( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode_Horfilterup( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horfilteron" of register "Sdfiltermode".
**
** enable for horizontal filter
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horfilteron" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdfiltermode_Horfilteron( uint32_t value );
#else
INLINE void FREG_VO_SetSdfiltermode_Horfilteron( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDFILTERMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDFILTERMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdfiltermode".
**
** This function reads the value from the register "Sdfiltermode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Veraddphase" of register "Sdfiltermode".
**
** two LSB of vertical counter are used as phase information for V-filter coefficients
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Veraddphase" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode_Veraddphase( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode_Veraddphase( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horaddphase" of register "Sdfiltermode".
**
** two LSB of horizontal counter are used as phase information for H-filter coefficients
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horaddphase" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode_Horaddphase( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode_Horaddphase( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verfilterup" of register "Sdfiltermode".
**
** 0 = less output then input lines
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verfilterup" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode_Verfilterup( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode_Verfilterup( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Verfilteron" of register "Sdfiltermode".
**
** enable for vertical filter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Verfilteron" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode_Verfilteron( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode_Verfilteron( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horfilterup" of register "Sdfiltermode".
**
** 0 = less output then input pixel
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horfilterup" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode_Horfilterup( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode_Horfilterup( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horfilteron" of register "Sdfiltermode".
**
** enable for horizontal filter
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horfilteron" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdfiltermode_Horfilteron( void );
#else
INLINE uint32_t FREG_VO_GetSdfiltermode_Horfilteron( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDFILTERMODE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhorwritestart".
**
** This function writes the given value to the register "Sdhorwritestart".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdhorwritestart( uint32_t value );
#else
INLINE void FREG_VO_SetSdhorwritestart( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORWRITESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORWRITESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horwritestart" of register "Sdhorwritestart".
**
** horizontal start of writing filtered data to buffer
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horwritestart" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdhorwritestart_Horwritestart( uint32_t value );
#else
INLINE void FREG_VO_SetSdhorwritestart_Horwritestart( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDHORWRITESTART)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORWRITESTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORWRITESTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhorwritestart".
**
** This function reads the value from the register "Sdhorwritestart".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhorwritestart( void );
#else
INLINE uint32_t FREG_VO_GetSdhorwritestart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORWRITESTART));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horwritestart" of register "Sdhorwritestart".
**
** horizontal start of writing filtered data to buffer
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horwritestart" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhorwritestart_Horwritestart( void );
#else
INLINE uint32_t FREG_VO_GetSdhorwritestart_Horwritestart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORWRITESTART));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdhorwritestop".
**
** This function writes the given value to the register "Sdhorwritestop".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdhorwritestop( uint32_t value );
#else
INLINE void FREG_VO_SetSdhorwritestop( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORWRITESTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORWRITESTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Horwritestop" of register "Sdhorwritestop".
**
** horizontal stop of writing filtered data to buffer (in total 720 pixel typically)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Horwritestop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdhorwritestop_Horwritestop( uint32_t value );
#else
INLINE void FREG_VO_SetSdhorwritestop_Horwritestop( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDHORWRITESTOP)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORWRITESTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORWRITESTOP)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdhorwritestop".
**
** This function reads the value from the register "Sdhorwritestop".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhorwritestop( void );
#else
INLINE uint32_t FREG_VO_GetSdhorwritestop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORWRITESTOP));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Horwritestop" of register "Sdhorwritestop".
**
** horizontal stop of writing filtered data to buffer (in total 720 pixel typically)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Horwritestop" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdhorwritestop_Horwritestop( void );
#else
INLINE uint32_t FREG_VO_GetSdhorwritestop_Horwritestop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDHORWRITESTOP));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "YLut".
**
** This function writes the given value to the index-th entry of the register
** array YLut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetYLut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetYLut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_YLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_YLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Value" of register "YLut".
**
** Y LUT
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetYLut_Value( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetYLut_Value( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_YLUT+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_YLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_YLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "YLut".
**
** This function reads the value from the index-th entry of the register
** array YLut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetYLut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetYLut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_YLUT+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Value" of register "YLut".
**
** Y LUT
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetYLut_Value( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetYLut_Value( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_YLUT+(index*0x4)));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "CrLut".
**
** This function writes the given value to the index-th entry of the register
** array CrLut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetCrLut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCrLut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CRLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CRLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Value" of register "CrLut".
**
** Cr LUT
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetCrLut_Value( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCrLut_Value( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CRLUT+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CRLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CRLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "CrLut".
**
** This function reads the value from the index-th entry of the register
** array CrLut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCrLut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetCrLut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_CRLUT+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Value" of register "CrLut".
**
** Cr LUT
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCrLut_Value( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetCrLut_Value( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_CRLUT+(index*0x4)));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "CbLut".
**
** This function writes the given value to the index-th entry of the register
** array CbLut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetCbLut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCbLut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CBLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CBLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Value" of register "CbLut".
**
** Cb LUT
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetCbLut_Value( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCbLut_Value( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CBLUT+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CBLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CBLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "CbLut".
**
** This function reads the value from the index-th entry of the register
** array CbLut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCbLut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetCbLut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_CBLUT+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Value" of register "CbLut".
**
** Cb LUT
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCbLut_Value( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetCbLut_Value( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_CBLUT+(index*0x4)));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RLut".
**
** This function writes the given value to the index-th entry of the register
** array RLut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetRLut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetRLut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_RLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_RLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Value" of register "RLut".
**
** R LUT
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetRLut_Value( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetRLut_Value( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_RLUT+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_RLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_RLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RLut".
**
** This function reads the value from the index-th entry of the register
** array RLut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetRLut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetRLut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_RLUT+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Value" of register "RLut".
**
** R LUT
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetRLut_Value( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetRLut_Value( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_RLUT+(index*0x4)));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "GLut".
**
** This function writes the given value to the index-th entry of the register
** array GLut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetGLut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetGLut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_GLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_GLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Value" of register "GLut".
**
** G LUT
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetGLut_Value( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetGLut_Value( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_GLUT+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_GLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_GLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "GLut".
**
** This function reads the value from the index-th entry of the register
** array GLut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetGLut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetGLut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_GLUT+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Value" of register "GLut".
**
** G LUT
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetGLut_Value( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetGLut_Value( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_GLUT+(index*0x4)));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "BLut".
**
** This function writes the given value to the index-th entry of the register
** array BLut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetBLut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetBLut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_BLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_BLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Value" of register "BLut".
**
** B LUT
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetBLut_Value( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetBLut_Value( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_BLUT+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_BLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_BLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "BLut".
**
** This function reads the value from the index-th entry of the register
** array BLut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetBLut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetBLut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_BLUT+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Value" of register "BLut".
**
** B LUT
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Value" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetBLut_Value( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetBLut_Value( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 1024 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_BLUT+(index*0x4)));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Sdenable".
**
** This function writes the given value to the register "Sdenable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetSdenable( uint32_t value );
#else
INLINE void FREG_VO_SetSdenable( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sdenable" of register "Sdenable".
**
** enables the SD path
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sdenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdenable_Sdenable( uint32_t value );
#else
INLINE void FREG_VO_SetSdenable_Sdenable( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_SDENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Sdenable".
**
** This function reads the value from the register "Sdenable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdenable( void );
#else
INLINE uint32_t FREG_VO_GetSdenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sdenable" of register "Sdenable".
**
** enables the SD path
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sdenable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetSdenable_Sdenable( void );
#else
INLINE uint32_t FREG_VO_GetSdenable_Sdenable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_SDENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osdmode".
**
** This function writes the given value to the index-th entry of the register
** array Osdmode.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osdfieldmode" of register "Osdmode".
**
** OSD field display mode
** 0 = interlaced
** 1 = progressive
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osdfieldmode" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_Osdfieldmode( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_Osdfieldmode( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CbSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CbSelect" consists of the bits 15..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x0000C000UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_CbSelect( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_CbSelect( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000C000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "YSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "YSelect" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_YSelect( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_YSelect( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00003000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "CrSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "CrSelect" consists of the bits 11..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000C00UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_CrSelect( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_CrSelect( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000C00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlphaSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlphaSelect" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_AlphaSelect( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_AlphaSelect( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000300UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RgbEnable" of register "Osdmode".
**
** selects RGB mode
** 0 = YCbCr mode
** 1 = RGB mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RgbEnable" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_RgbEnable( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_RgbEnable( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlphaSource" of register "Osdmode".
**
** alpha value selection
** 0 = internal alpha value (=standard alpha value of the layer)
** 1 = external alpha value (=incoming)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlphaSource" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_AlphaSource( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_AlphaSource( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Osdmode" of register "Osdmode".
**
** selects the OSD mode
** '0000' = 32/24 bit mode*
** '0001' = 5551 mode*
** '0010' = 4444 mode*
** '0100' = 16 bit mode*
** '1010' = 4 bit mode
** '1011' = 8 bit mode
** *not supported on OSD 2
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Osdmode" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_VO_SetOsdmode_Osdmode( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsdmode_Osdmode( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSDMODE+(index*0x4000), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osdmode".
**
** This function reads the value from the index-th entry of the register
** array Osdmode.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osdfieldmode" of register "Osdmode".
**
** OSD field display mode
** 0 = interlaced
** 1 = progressive
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osdfieldmode" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_Osdfieldmode( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_Osdfieldmode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x00010000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CbSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "CbSelect" consists of the bits 15..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x0000C000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_CbSelect( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_CbSelect( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x0000C000UL ) >> 14;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "YSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "YSelect" consists of the bits 13..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00003000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_YSelect( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_YSelect( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x00003000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "CrSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "CrSelect" consists of the bits 11..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000C00UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_CrSelect( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_CrSelect( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x00000C00UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AlphaSelect" of register "Osdmode".
**
** left shift from default position by n*4 bits to be able to switch the order of Cb, Y, Cr and alpha
** (default should be 0) 
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlphaSelect" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_AlphaSelect( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_AlphaSelect( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x00000300UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "RgbEnable" of register "Osdmode".
**
** selects RGB mode
** 0 = YCbCr mode
** 1 = RGB mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RgbEnable" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_RgbEnable( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_RgbEnable( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "AlphaSource" of register "Osdmode".
**
** alpha value selection
** 0 = internal alpha value (=standard alpha value of the layer)
** 1 = external alpha value (=incoming)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlphaSource" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_AlphaSource( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_AlphaSource( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Osdmode" of register "Osdmode".
**
** selects the OSD mode
** '0000' = 32/24 bit mode*
** '0001' = 5551 mode*
** '0010' = 4444 mode*
** '0100' = 16 bit mode*
** '1010' = 4 bit mode
** '1011' = 8 bit mode
** *not supported on OSD 2
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Osdmode" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetOsdmode_Osdmode( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetOsdmode_Osdmode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_OSDMODE+(index*0x4000)));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Cursormode".
**
** This function writes the given value to the register "Cursormode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetCursormode( uint32_t value );
#else
INLINE void FREG_VO_SetCursormode( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "LineOffset" of register "Cursormode".
**
** line offset
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LineOffset" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VO_SetCursormode_LineOffset( uint32_t value );
#else
INLINE void FREG_VO_SetCursormode_LineOffset( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CURSORMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "LutMode" of register "Cursormode".
**
** selects LUT mode
** '00' = 1 bit mode
** '01' = 2 bit mode
** '10' = 4 bit mode
** '11' = 8 bit mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "LutMode" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern void FREG_VO_SetCursormode_LutMode( uint32_t value );
#else
INLINE void FREG_VO_SetCursormode_LutMode( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CURSORMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "HlMode" of register "Cursormode".
**
** If not in 8 bit mode, this bit is used as MSB of the CLUT RAM.
**  It allows to switch beteen two CLUTs by changing a single bit.
** 0 = lower 128 CLUT inputs are used
** 1 =  upper 128 CLUT inputs are used
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "HlMode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_VO_SetCursormode_HlMode( uint32_t value );
#else
INLINE void FREG_VO_SetCursormode_HlMode( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CURSORMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cursorfieldmode" of register "Cursormode".
**
** 0 = interlaced
** 1 = progressive
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cursorfieldmode" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_VO_SetCursormode_Cursorfieldmode( uint32_t value );
#else
INLINE void FREG_VO_SetCursormode_Cursorfieldmode( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CURSORMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enable" of register "Cursormode".
**
** enable signal
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_VO_SetCursormode_Enable( uint32_t value );
#else
INLINE void FREG_VO_SetCursormode_Enable( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CURSORMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Cursormode".
**
** This function reads the value from the register "Cursormode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursormode( void );
#else
INLINE uint32_t FREG_VO_GetCursormode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORMODE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LineOffset" of register "Cursormode".
**
** line offset
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LineOffset" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursormode_LineOffset( void );
#else
INLINE uint32_t FREG_VO_GetCursormode_LineOffset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORMODE));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "LutMode" of register "Cursormode".
**
** selects LUT mode
** '00' = 1 bit mode
** '01' = 2 bit mode
** '10' = 4 bit mode
** '11' = 8 bit mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "LutMode" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursormode_LutMode( void );
#else
INLINE uint32_t FREG_VO_GetCursormode_LutMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORMODE));
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "HlMode" of register "Cursormode".
**
** If not in 8 bit mode, this bit is used as MSB of the CLUT RAM.
**  It allows to switch beteen two CLUTs by changing a single bit.
** 0 = lower 128 CLUT inputs are used
** 1 =  upper 128 CLUT inputs are used
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "HlMode" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursormode_HlMode( void );
#else
INLINE uint32_t FREG_VO_GetCursormode_HlMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORMODE));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cursorfieldmode" of register "Cursormode".
**
** 0 = interlaced
** 1 = progressive
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cursorfieldmode" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursormode_Cursorfieldmode( void );
#else
INLINE uint32_t FREG_VO_GetCursormode_Cursorfieldmode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORMODE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enable" of register "Cursormode".
**
** enable signal
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursormode_Enable( void );
#else
INLINE uint32_t FREG_VO_GetCursormode_Enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORMODE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Dispcvbsversync".
**
** This function writes the given value to the register "Dispcvbsversync".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbsversync( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbsversync( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSVERSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cvbshorsync" of register "Dispcvbsversync".
**
** horizontal sync position for SD controller (H/V counter)
** needs to be set to 0x0001
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cvbshorsync" consists of the bits 28..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x1FFF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbsversync_Cvbshorsync( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbsversync_Cvbshorsync( uint32_t value )
{
    register uint32_t mask = 0x1FFF0000UL;
    value = ( value << 16 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSVERSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cvbsversync" of register "Dispcvbsversync".
**
** vertical sync position for SD controller (H/V counter)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cvbsversync" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDispcvbsversync_Cvbsversync( uint32_t value );
#else
INLINE void FREG_VO_SetDispcvbsversync_Cvbsversync( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPCVBSVERSYNC, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Dispcvbsversync".
**
** This function reads the value from the register "Dispcvbsversync".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbsversync( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbsversync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cvbshorsync" of register "Dispcvbsversync".
**
** horizontal sync position for SD controller (H/V counter)
** needs to be set to 0x0001
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cvbshorsync" consists of the bits 28..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x1FFF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbsversync_Cvbshorsync( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbsversync_Cvbshorsync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC));
    value = ( value & 0x1FFF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cvbsversync" of register "Dispcvbsversync".
**
** vertical sync position for SD controller (H/V counter)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cvbsversync" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDispcvbsversync_Cvbsversync( void );
#else
INLINE uint32_t FREG_VO_GetDispcvbsversync_Cvbsversync( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPCVBSVERSYNC));
    value = ( value & 0x00000FFFUL ) >> 0;
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
extern void FREG_VO_SetSdHorlinelength( uint32_t value );
#else
INLINE void FREG_VO_SetSdHorlinelength( uint32_t value )
{
    FREG_VO_SdHorlinelengthMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORLINELENGTH, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORLINELENGTH)) = value;
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
extern void FREG_VO_SetSdHorlinelength_HorLl( uint32_t value );
#else
INLINE void FREG_VO_SetSdHorlinelength_HorLl( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdHorlinelengthMirror & ~mask;
    FREG_VO_SdHorlinelengthMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHORLINELENGTH, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHORLINELENGTH)) = value;
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
extern uint32_t FREG_VO_GetmSdHorlinelength( void );
#else
INLINE uint32_t FREG_VO_GetmSdHorlinelength( void )
{
    register uint32_t value = FREG_VO_SdHorlinelengthMirror;
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
extern uint32_t FREG_VO_GetmSdHorlinelength_HorLl( void );
#else
INLINE uint32_t FREG_VO_GetmSdHorlinelength_HorLl( void )
{
    register uint32_t value = FREG_VO_SdHorlinelengthMirror;
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
extern void FREG_VO_SetSdVersize( uint32_t value );
#else
INLINE void FREG_VO_SetSdVersize( uint32_t value )
{
    FREG_VO_SdVersizeMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVERSIZE)) = value;
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
extern void FREG_VO_SetSdVersize_VerSize( uint32_t value );
#else
INLINE void FREG_VO_SetSdVersize_VerSize( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdVersizeMirror & ~mask;
    FREG_VO_SdVersizeMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVERSIZE)) = value;
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
extern uint32_t FREG_VO_GetmSdVersize( void );
#else
INLINE uint32_t FREG_VO_GetmSdVersize( void )
{
    register uint32_t value = FREG_VO_SdVersizeMirror;
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
extern uint32_t FREG_VO_GetmSdVersize_VerSize( void );
#else
INLINE uint32_t FREG_VO_GetmSdVersize_VerSize( void )
{
    register uint32_t value = FREG_VO_SdVersizeMirror;
    value = ( value & 0x000003FFUL ) >> 0;
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
extern void FREG_VO_SetSdSecfieldoffset( uint32_t value );
#else
INLINE void FREG_VO_SetSdSecfieldoffset( uint32_t value )
{
    FREG_VO_SdSecfieldoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDSECFIELDOFFSET)) = value;
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
extern void FREG_VO_SetSdSecfieldoffset_VOffsetTtxF1( uint32_t value );
#else
INLINE void FREG_VO_SetSdSecfieldoffset_VOffsetTtxF1( uint32_t value )
{
    register uint32_t mask = 0x001F0000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VO_SdSecfieldoffsetMirror & ~mask;
    FREG_VO_SdSecfieldoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDSECFIELDOFFSET)) = value;
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
extern void FREG_VO_SetSdSecfieldoffset_VOffsetTtxF0( uint32_t value );
#else
INLINE void FREG_VO_SetSdSecfieldoffset_VOffsetTtxF0( uint32_t value )
{
    register uint32_t mask = 0x00001F00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VO_SdSecfieldoffsetMirror & ~mask;
    FREG_VO_SdSecfieldoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDSECFIELDOFFSET)) = value;
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
extern void FREG_VO_SetSdSecfieldoffset_SecFieldOffset( uint32_t value );
#else
INLINE void FREG_VO_SetSdSecfieldoffset_SecFieldOffset( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdSecfieldoffsetMirror & ~mask;
    FREG_VO_SdSecfieldoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDSECFIELDOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDSECFIELDOFFSET)) = value;
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
extern uint32_t FREG_VO_GetmSdSecfieldoffset( void );
#else
INLINE uint32_t FREG_VO_GetmSdSecfieldoffset( void )
{
    register uint32_t value = FREG_VO_SdSecfieldoffsetMirror;
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
extern uint32_t FREG_VO_GetmSdSecfieldoffset_VOffsetTtxF1( void );
#else
INLINE uint32_t FREG_VO_GetmSdSecfieldoffset_VOffsetTtxF1( void )
{
    register uint32_t value = FREG_VO_SdSecfieldoffsetMirror;
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
extern uint32_t FREG_VO_GetmSdSecfieldoffset_VOffsetTtxF0( void );
#else
INLINE uint32_t FREG_VO_GetmSdSecfieldoffset_VOffsetTtxF0( void )
{
    register uint32_t value = FREG_VO_SdSecfieldoffsetMirror;
    value = ( value & 0x00001F00UL ) >> 8;
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
extern uint32_t FREG_VO_GetmSdSecfieldoffset_SecFieldOffset( void );
#else
INLINE uint32_t FREG_VO_GetmSdSecfieldoffset_SecFieldOffset( void )
{
    register uint32_t value = FREG_VO_SdSecfieldoffsetMirror;
    value = ( value & 0x00000007UL ) >> 0;
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
extern void FREG_VO_SetSdBackground( uint32_t value );
#else
INLINE void FREG_VO_SetSdBackground( uint32_t value )
{
    FREG_VO_SdBackgroundMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackGroundY" of register "SdBackground".
**
** Here the luminance value of the background (plane zero) can be defined.
**  Typical value: 0x10 = 16 (black)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdBackground_BackGroundY( uint32_t value );
#else
INLINE void FREG_VO_SetSdBackground_BackGroundY( uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VO_SdBackgroundMirror & ~mask;
    FREG_VO_SdBackgroundMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackGroundCb" of register "SdBackground".
**
** Here the chrominance Cb value of the background (plane zero) can be defined.
**  Typical value: 0x80 = 128 (uncoloured)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundCb" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdBackground_BackGroundCb( uint32_t value );
#else
INLINE void FREG_VO_SetSdBackground_BackGroundCb( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    value |= FREG_VO_SdBackgroundMirror & ~mask;
    FREG_VO_SdBackgroundMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDBACKGROUND)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BackGroundCr" of register "SdBackground".
**
** Here the chrominance Cr value of the background (plane zero) can be defined.
**  Typical value: 0x80 = 128 (uncoloured)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BackGroundCr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdBackground_BackGroundCr( uint32_t value );
#else
INLINE void FREG_VO_SetSdBackground_BackGroundCr( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdBackgroundMirror & ~mask;
    FREG_VO_SdBackgroundMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDBACKGROUND, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDBACKGROUND)) = value;
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
extern uint32_t FREG_VO_GetmSdBackground( void );
#else
INLINE uint32_t FREG_VO_GetmSdBackground( void )
{
    register uint32_t value = FREG_VO_SdBackgroundMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "BackGroundY" of register "SdBackground".
**
** Here the luminance value of the background (plane zero) can be defined.
**  Typical value: 0x10 = 16 (black)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundY" consists of the bits 23..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00FF0000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdBackground_BackGroundY( void );
#else
INLINE uint32_t FREG_VO_GetmSdBackground_BackGroundY( void )
{
    register uint32_t value = FREG_VO_SdBackgroundMirror;
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
** Here the chrominance Cb value of the background (plane zero) can be defined.
**  Typical value: 0x80 = 128 (uncoloured)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundCb" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdBackground_BackGroundCb( void );
#else
INLINE uint32_t FREG_VO_GetmSdBackground_BackGroundCb( void )
{
    register uint32_t value = FREG_VO_SdBackgroundMirror;
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
** Here the chrominance Cr value of the background (plane zero) can be defined.
**  Typical value: 0x80 = 128 (uncoloured)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BackGroundCr" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdBackground_BackGroundCr( void );
#else
INLINE uint32_t FREG_VO_GetmSdBackground_BackGroundCr( void )
{
    register uint32_t value = FREG_VO_SdBackgroundMirror;
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
extern void FREG_VO_SetSdVohorstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdVohorstart( uint32_t value )
{
    FREG_VO_SdVohorstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOHORSTART)) = value;
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
** Typical value for PAL 544
** Typical value for NTSC: 508
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoHorStart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdVohorstart_VoHorStart( uint32_t value );
#else
INLINE void FREG_VO_SetSdVohorstart_VoHorStart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdVohorstartMirror & ~mask;
    FREG_VO_SdVohorstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOHORSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdVohorstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdVohorstart( void )
{
    register uint32_t value = FREG_VO_SdVohorstartMirror;
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
** Typical value for PAL 544
** Typical value for NTSC: 508
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoHorStart" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdVohorstart_VoHorStart( void );
#else
INLINE uint32_t FREG_VO_GetmSdVohorstart_VoHorStart( void )
{
    register uint32_t value = FREG_VO_SdVohorstartMirror;
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
extern void FREG_VO_SetSdVohorstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdVohorstop( uint32_t value )
{
    FREG_VO_SdVohorstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOHORSTOP)) = value;
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
** Typical value for PAL 544 +(4*720)
** Typical value for NTSC: 508 + (4*720)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "VoHorStop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdVohorstop_VoHorStop( uint32_t value );
#else
INLINE void FREG_VO_SetSdVohorstop_VoHorStop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdVohorstopMirror & ~mask;
    FREG_VO_SdVohorstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOHORSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOHORSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdVohorstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdVohorstop( void )
{
    register uint32_t value = FREG_VO_SdVohorstopMirror;
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
** Typical value for PAL 544 +(4*720)
** Typical value for NTSC: 508 + (4*720)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "VoHorStop" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdVohorstop_VoHorStop( void );
#else
INLINE uint32_t FREG_VO_GetmSdVohorstop_VoHorStop( void )
{
    register uint32_t value = FREG_VO_SdVohorstopMirror;
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
extern void FREG_VO_SetSdVoverstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdVoverstart( uint32_t value )
{
    FREG_VO_SdVoverstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOVERSTART)) = value;
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
extern void FREG_VO_SetSdVoverstart_VoVerStart( uint32_t value );
#else
INLINE void FREG_VO_SetSdVoverstart_VoVerStart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdVoverstartMirror & ~mask;
    FREG_VO_SdVoverstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOVERSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOVERSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdVoverstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdVoverstart( void )
{
    register uint32_t value = FREG_VO_SdVoverstartMirror;
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
extern uint32_t FREG_VO_GetmSdVoverstart_VoVerStart( void );
#else
INLINE uint32_t FREG_VO_GetmSdVoverstart_VoVerStart( void )
{
    register uint32_t value = FREG_VO_SdVoverstartMirror;
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
extern void FREG_VO_SetSdVoverstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdVoverstop( uint32_t value )
{
    FREG_VO_SdVoverstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOVERSTOP)) = value;
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
extern void FREG_VO_SetSdVoverstop_VoVerStop( uint32_t value );
#else
INLINE void FREG_VO_SetSdVoverstop_VoVerStop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdVoverstopMirror & ~mask;
    FREG_VO_SdVoverstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVOVERSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVOVERSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdVoverstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdVoverstop( void )
{
    register uint32_t value = FREG_VO_SdVoverstopMirror;
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
extern uint32_t FREG_VO_GetmSdVoverstop_VoVerStop( void );
#else
INLINE uint32_t FREG_VO_GetmSdVoverstop_VoVerStop( void )
{
    register uint32_t value = FREG_VO_SdVoverstopMirror;
    value = ( value & 0x000003FFUL ) >> 0;
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
extern void FREG_VO_SetSdhvsynccfg( uint32_t value );
#else
INLINE void FREG_VO_SetSdhvsynccfg( uint32_t value )
{
    FREG_VO_SdhvsynccfgMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHVSYNCCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHVSYNCCFG)) = value;
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
extern void FREG_VO_SetSdhvsynccfg_SdSyncEnable( uint32_t value );
#else
INLINE void FREG_VO_SetSdhvsynccfg_SdSyncEnable( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    value |= FREG_VO_SdhvsynccfgMirror & ~mask;
    FREG_VO_SdhvsynccfgMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHVSYNCCFG, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHVSYNCCFG)) = value;
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
extern uint32_t FREG_VO_GetmSdhvsynccfg( void );
#else
INLINE uint32_t FREG_VO_GetmSdhvsynccfg( void )
{
    register uint32_t value = FREG_VO_SdhvsynccfgMirror;
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
extern uint32_t FREG_VO_GetmSdhvsynccfg_SdSyncEnable( void );
#else
INLINE uint32_t FREG_VO_GetmSdhvsynccfg_SdSyncEnable( void )
{
    register uint32_t value = FREG_VO_SdhvsynccfgMirror;
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
extern void FREG_VO_SetSdvsyncoffset( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncoffset( uint32_t value )
{
    FREG_VO_SdvsyncoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOFFSET)) = value;
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
extern void FREG_VO_SetSdvsyncoffset_Field( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncoffset_Field( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VO_SdvsyncoffsetMirror & ~mask;
    FREG_VO_SdvsyncoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOFFSET)) = value;
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
extern void FREG_VO_SetSdvsyncoffset_Sdvsyncoffset( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncoffset_Sdvsyncoffset( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncoffsetMirror & ~mask;
    FREG_VO_SdvsyncoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOFFSET)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncoffset( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncoffset( void )
{
    register uint32_t value = FREG_VO_SdvsyncoffsetMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncoffset_Field( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncoffset_Field( void )
{
    register uint32_t value = FREG_VO_SdvsyncoffsetMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncoffset_Sdvsyncoffset( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncoffset_Sdvsyncoffset( void )
{
    register uint32_t value = FREG_VO_SdvsyncoffsetMirror;
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
extern void FREG_VO_SetSdvsyncevstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncevstart( uint32_t value )
{
    FREG_VO_SdvsyncevstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEVSTART)) = value;
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
extern void FREG_VO_SetSdvsyncevstart_Vsyncevstartfield( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncevstart_Vsyncevstartfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VO_SdvsyncevstartMirror & ~mask;
    FREG_VO_SdvsyncevstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEVSTART)) = value;
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
extern void FREG_VO_SetSdvsyncevstart_Vsyncevstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncevstart_Vsyncevstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncevstartMirror & ~mask;
    FREG_VO_SdvsyncevstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEVSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncevstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncevstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncevstartMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncevstart_Vsyncevstartfield( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncevstart_Vsyncevstartfield( void )
{
    register uint32_t value = FREG_VO_SdvsyncevstartMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncevstart_Vsyncevstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncevstart_Vsyncevstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncevstartMirror;
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
extern void FREG_VO_SetSdvsyncovstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncovstart( uint32_t value )
{
    FREG_VO_SdvsyncovstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOVSTART)) = value;
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
extern void FREG_VO_SetSdvsyncovstart_Vsyncovstartfield( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncovstart_Vsyncovstartfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VO_SdvsyncovstartMirror & ~mask;
    FREG_VO_SdvsyncovstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOVSTART)) = value;
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
extern void FREG_VO_SetSdvsyncovstart_Vsyncovstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncovstart_Vsyncovstart( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncovstartMirror & ~mask;
    FREG_VO_SdvsyncovstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOVSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOVSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncovstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncovstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncovstartMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncovstart_Vsyncovstartfield( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncovstart_Vsyncovstartfield( void )
{
    register uint32_t value = FREG_VO_SdvsyncovstartMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncovstart_Vsyncovstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncovstart_Vsyncovstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncovstartMirror;
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
extern void FREG_VO_SetSdvsyncevstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncevstop( uint32_t value )
{
    FREG_VO_SdvsyncevstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEVSTOP)) = value;
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
extern void FREG_VO_SetSdvsyncevstop_Vsyncevstopfield( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncevstop_Vsyncevstopfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VO_SdvsyncevstopMirror & ~mask;
    FREG_VO_SdvsyncevstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEVSTOP)) = value;
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
extern void FREG_VO_SetSdvsyncevstop_Vsyncevstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncevstop_Vsyncevstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncevstopMirror & ~mask;
    FREG_VO_SdvsyncevstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEVSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncevstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncevstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncevstopMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncevstop_Vsyncevstopfield( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncevstop_Vsyncevstopfield( void )
{
    register uint32_t value = FREG_VO_SdvsyncevstopMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncevstop_Vsyncevstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncevstop_Vsyncevstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncevstopMirror;
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
extern void FREG_VO_SetSdvsyncovstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncovstop( uint32_t value )
{
    FREG_VO_SdvsyncovstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOVSTOP)) = value;
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
extern void FREG_VO_SetSdvsyncovstop_Vsyncovstopfield( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncovstop_Vsyncovstopfield( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    value |= FREG_VO_SdvsyncovstopMirror & ~mask;
    FREG_VO_SdvsyncovstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOVSTOP)) = value;
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
extern void FREG_VO_SetSdvsyncovstop_Vsyncovstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncovstop_Vsyncovstop( uint32_t value )
{
    register uint32_t mask = 0x000003FFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncovstopMirror & ~mask;
    FREG_VO_SdvsyncovstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOVSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOVSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncovstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncovstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncovstopMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncovstop_Vsyncovstopfield( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncovstop_Vsyncovstopfield( void )
{
    register uint32_t value = FREG_VO_SdvsyncovstopMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncovstop_Vsyncovstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncovstop_Vsyncovstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncovstopMirror;
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
extern void FREG_VO_SetSdvsyncehstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncehstart( uint32_t value )
{
    FREG_VO_SdvsyncehstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEHSTART)) = value;
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
extern void FREG_VO_SetSdvsyncehstart_Vsyncehstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncehstart_Vsyncehstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncehstartMirror & ~mask;
    FREG_VO_SdvsyncehstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEHSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncehstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncehstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncehstartMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncehstart_Vsyncehstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncehstart_Vsyncehstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncehstartMirror;
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
extern void FREG_VO_SetSdvsyncohstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncohstart( uint32_t value )
{
    FREG_VO_SdvsyncohstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOHSTART)) = value;
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
extern void FREG_VO_SetSdvsyncohstart_Vsyncohstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncohstart_Vsyncohstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncohstartMirror & ~mask;
    FREG_VO_SdvsyncohstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOHSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOHSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncohstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncohstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncohstartMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncohstart_Vsyncohstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncohstart_Vsyncohstart( void )
{
    register uint32_t value = FREG_VO_SdvsyncohstartMirror;
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
extern void FREG_VO_SetSdvsyncehstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncehstop( uint32_t value )
{
    FREG_VO_SdvsyncehstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEHSTOP)) = value;
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
extern void FREG_VO_SetSdvsyncehstop_Vsyncehstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncehstop_Vsyncehstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncehstopMirror & ~mask;
    FREG_VO_SdvsyncehstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCEHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCEHSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncehstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncehstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncehstopMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncehstop_Vsyncehstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncehstop_Vsyncehstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncehstopMirror;
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
extern void FREG_VO_SetSdvsyncohstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncohstop( uint32_t value )
{
    FREG_VO_SdvsyncohstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOHSTOP)) = value;
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
extern void FREG_VO_SetSdvsyncohstop_Vsyncohstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdvsyncohstop_Vsyncohstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdvsyncohstopMirror & ~mask;
    FREG_VO_SdvsyncohstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDVSYNCOHSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDVSYNCOHSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdvsyncohstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncohstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncohstopMirror;
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
extern uint32_t FREG_VO_GetmSdvsyncohstop_Vsyncohstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdvsyncohstop_Vsyncohstop( void )
{
    register uint32_t value = FREG_VO_SdvsyncohstopMirror;
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
extern void FREG_VO_SetSdhsyncstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdhsyncstart( uint32_t value )
{
    FREG_VO_SdhsyncstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHSYNCSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHSYNCSTART)) = value;
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
extern void FREG_VO_SetSdhsyncstart_Hsyncstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdhsyncstart_Hsyncstart( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdhsyncstartMirror & ~mask;
    FREG_VO_SdhsyncstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHSYNCSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHSYNCSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdhsyncstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdhsyncstart( void )
{
    register uint32_t value = FREG_VO_SdhsyncstartMirror;
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
extern uint32_t FREG_VO_GetmSdhsyncstart_Hsyncstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdhsyncstart_Hsyncstart( void )
{
    register uint32_t value = FREG_VO_SdhsyncstartMirror;
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
extern void FREG_VO_SetSdhsyncstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdhsyncstop( uint32_t value )
{
    FREG_VO_SdhsyncstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHSYNCSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHSYNCSTOP)) = value;
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
extern void FREG_VO_SetSdhsyncstop_Hsyncstop( uint32_t value );
#else
INLINE void FREG_VO_SetSdhsyncstop_Hsyncstop( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdhsyncstopMirror & ~mask;
    FREG_VO_SdhsyncstopMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHSYNCSTOP, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHSYNCSTOP)) = value;
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
extern uint32_t FREG_VO_GetmSdhsyncstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdhsyncstop( void )
{
    register uint32_t value = FREG_VO_SdhsyncstopMirror;
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
extern uint32_t FREG_VO_GetmSdhsyncstop_Hsyncstop( void );
#else
INLINE uint32_t FREG_VO_GetmSdhsyncstop_Hsyncstop( void )
{
    register uint32_t value = FREG_VO_SdhsyncstopMirror;
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
extern void FREG_VO_SetSdhsyncoffset( uint32_t value );
#else
INLINE void FREG_VO_SetSdhsyncoffset( uint32_t value )
{
    FREG_VO_SdhsyncoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHSYNCOFFSET)) = value;
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
extern void FREG_VO_SetSdhsyncoffset_Sdhsyncoffset( uint32_t value );
#else
INLINE void FREG_VO_SetSdhsyncoffset_Sdhsyncoffset( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    value |= FREG_VO_SdhsyncoffsetMirror & ~mask;
    FREG_VO_SdhsyncoffsetMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDHSYNCOFFSET, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDHSYNCOFFSET)) = value;
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
extern uint32_t FREG_VO_GetmSdhsyncoffset( void );
#else
INLINE uint32_t FREG_VO_GetmSdhsyncoffset( void )
{
    register uint32_t value = FREG_VO_SdhsyncoffsetMirror;
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
extern uint32_t FREG_VO_GetmSdhsyncoffset_Sdhsyncoffset( void );
#else
INLINE uint32_t FREG_VO_GetmSdhsyncoffset_Sdhsyncoffset( void )
{
    register uint32_t value = FREG_VO_SdhsyncoffsetMirror;
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osd1clut".
**
** This function writes the given value to the index-th entry of the register
** array Osd1clut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsd1clut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1clut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VO_Osd1clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCb" of register "Osd1clut".
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
extern void FREG_VO_SetOsd1clut_ClutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1clut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VO_Osd1clutMirror[index] & ~mask;
    FREG_VO_Osd1clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutY" of register "Osd1clut".
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
extern void FREG_VO_SetOsd1clut_ClutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1clut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VO_Osd1clutMirror[index] & ~mask;
    FREG_VO_Osd1clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCr" of register "Osd1clut".
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
extern void FREG_VO_SetOsd1clut_ClutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1clut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VO_Osd1clutMirror[index] & ~mask;
    FREG_VO_Osd1clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutAlpha" of register "Osd1clut".
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
extern void FREG_VO_SetOsd1clut_ClutAlpha( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd1clut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_Osd1clutMirror[index] & ~mask;
    FREG_VO_Osd1clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD1CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD1CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osd1clut".
**
** This function reads the value from the index-th entry of the register
** array Osd1clut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmOsd1clut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1clut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1clutMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCb" of register "Osd1clut".
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
extern uint32_t FREG_VO_GetmOsd1clut_ClutCb( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1clut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1clutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutY" of register "Osd1clut".
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
extern uint32_t FREG_VO_GetmOsd1clut_ClutY( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1clut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1clutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCr" of register "Osd1clut".
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
extern uint32_t FREG_VO_GetmOsd1clut_ClutCr( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1clut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1clutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutAlpha" of register "Osd1clut".
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
extern uint32_t FREG_VO_GetmOsd1clut_ClutAlpha( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd1clut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd1clutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Osd2clut".
**
** This function writes the given value to the index-th entry of the register
** array Osd2clut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetOsd2clut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2clut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VO_Osd2clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCb" of register "Osd2clut".
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
extern void FREG_VO_SetOsd2clut_ClutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2clut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VO_Osd2clutMirror[index] & ~mask;
    FREG_VO_Osd2clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutY" of register "Osd2clut".
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
extern void FREG_VO_SetOsd2clut_ClutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2clut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VO_Osd2clutMirror[index] & ~mask;
    FREG_VO_Osd2clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCr" of register "Osd2clut".
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
extern void FREG_VO_SetOsd2clut_ClutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2clut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VO_Osd2clutMirror[index] & ~mask;
    FREG_VO_Osd2clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutAlpha" of register "Osd2clut".
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
extern void FREG_VO_SetOsd2clut_ClutAlpha( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetOsd2clut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_Osd2clutMirror[index] & ~mask;
    FREG_VO_Osd2clutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_OSD2CLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_OSD2CLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Osd2clut".
**
** This function reads the value from the index-th entry of the register
** array Osd2clut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmOsd2clut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2clut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2clutMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCb" of register "Osd2clut".
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
extern uint32_t FREG_VO_GetmOsd2clut_ClutCb( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2clut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2clutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutY" of register "Osd2clut".
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
extern uint32_t FREG_VO_GetmOsd2clut_ClutY( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2clut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2clutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCr" of register "Osd2clut".
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
extern uint32_t FREG_VO_GetmOsd2clut_ClutCr( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2clut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2clutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutAlpha" of register "Osd2clut".
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
extern uint32_t FREG_VO_GetmOsd2clut_ClutAlpha( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmOsd2clut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_Osd2clutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Cursorclut".
**
** This function writes the given value to the index-th entry of the register
** array Cursorclut.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetCursorclut( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCursorclut( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    FREG_VO_CursorclutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCb" of register "Cursorclut".
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
extern void FREG_VO_SetCursorclut_ClutCb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCursorclut_ClutCb( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0xFF000000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 24 ) & mask;
    value |= FREG_VO_CursorclutMirror[index] & ~mask;
    FREG_VO_CursorclutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutY" of register "Cursorclut".
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
extern void FREG_VO_SetCursorclut_ClutY( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCursorclut_ClutY( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00FF0000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 16 ) & mask;
    value |= FREG_VO_CursorclutMirror[index] & ~mask;
    FREG_VO_CursorclutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutCr" of register "Cursorclut".
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
extern void FREG_VO_SetCursorclut_ClutCr( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCursorclut_ClutCr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    value |= FREG_VO_CursorclutMirror[index] & ~mask;
    FREG_VO_CursorclutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "ClutAlpha" of register "Cursorclut".
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
extern void FREG_VO_SetCursorclut_ClutAlpha( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetCursorclut_ClutAlpha( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    value |= FREG_VO_CursorclutMirror[index] & ~mask;
    FREG_VO_CursorclutMirror[index] = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORCLUT+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORCLUT+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Cursorclut".
**
** This function reads the value from the index-th entry of the register
** array Cursorclut.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmCursorclut( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmCursorclut( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 256 )
            return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_CursorclutMirror[index];
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCb" of register "Cursorclut".
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
extern uint32_t FREG_VO_GetmCursorclut_ClutCb( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmCursorclut_ClutCb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_CursorclutMirror[index];
    value = ( value & 0xFF000000UL ) >> 24;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutY" of register "Cursorclut".
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
extern uint32_t FREG_VO_GetmCursorclut_ClutY( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmCursorclut_ClutY( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_CursorclutMirror[index];
    value = ( value & 0x00FF0000UL ) >> 16;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutCr" of register "Cursorclut".
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
extern uint32_t FREG_VO_GetmCursorclut_ClutCr( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmCursorclut_ClutCr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_CursorclutMirror[index];
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "ClutAlpha" of register "Cursorclut".
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
extern uint32_t FREG_VO_GetmCursorclut_ClutAlpha( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetmCursorclut_ClutAlpha( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
    if( index >= 256 )
        return( 0xFFFFFFFFUL );
    #endif
    value = FREG_VO_CursorclutMirror[index];
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Disphorll1".
**
** This function writes the given value to the register "Disphorll1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetDisphorll1( uint32_t value );
#else
INLINE void FREG_VO_SetDisphorll1( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHORLL1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHORLL1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Disphorll1field" of register "Disphorll1".
**
** Defines the field on which the additional line length is implemented
** 0 = field 1 (second field)
** 1 = both fields
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Disphorll1field" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphorll1_Disphorll1field( uint32_t value );
#else
INLINE void FREG_VO_SetDisphorll1_Disphorll1field( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHORLL1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHORLL1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHORLL1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Disphorll1" of register "Disphorll1".
**
** horizontal line length of last line, if this value is smaller then the DISPHORLL then this value is used as last line length, else the normal LL is used (default)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Disphorll1" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetDisphorll1_Disphorll1( uint32_t value );
#else
INLINE void FREG_VO_SetDisphorll1_Disphorll1( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_DISPHORLL1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_DISPHORLL1, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_DISPHORLL1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Disphorll1".
**
** This function reads the value from the register "Disphorll1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphorll1( void );
#else
INLINE uint32_t FREG_VO_GetDisphorll1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHORLL1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Disphorll1field" of register "Disphorll1".
**
** Defines the field on which the additional line length is implemented
** 0 = field 1 (second field)
** 1 = both fields
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Disphorll1field" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphorll1_Disphorll1field( void );
#else
INLINE uint32_t FREG_VO_GetDisphorll1_Disphorll1field( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHORLL1));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Disphorll1" of register "Disphorll1".
**
** horizontal line length of last line, if this value is smaller then the DISPHORLL then this value is used as last line length, else the normal LL is used (default)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Disphorll1" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetDisphorll1_Disphorll1( void );
#else
INLINE uint32_t FREG_VO_GetDisphorll1_Disphorll1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_DISPHORLL1));
    value = ( value & 0x00000FFFUL ) >> 0;
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
extern void FREG_VO_SetSdTtxhorstart( uint32_t value );
#else
INLINE void FREG_VO_SetSdTtxhorstart( uint32_t value )
{
    FREG_VO_SdTtxhorstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDTTXHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxEn" of register "SdTtxhorstart".
**
** Teletext insertion enable bit
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxEn" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern void FREG_VO_SetSdTtxhorstart_TtxEn( uint32_t value );
#else
INLINE void FREG_VO_SetSdTtxhorstart_TtxEn( uint32_t value )
{
    register uint32_t mask = 0x00010000UL;
    value = ( value << 16 ) & mask;
    value |= FREG_VO_SdTtxhorstartMirror & ~mask;
    FREG_VO_SdTtxhorstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDTTXHORSTART)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TtxHorStart" of register "SdTtxhorstart".
**
** The pixel counter counts 54.
** 0MHz clock cycles. If the pixel counter reaches this value (times 4), the Teletext data will be inserted in the video plane (plane 1). Typical value for PAL: = 528 --> 132
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TtxHorStart" consists of the bits 11..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000FFCUL
**
********************************************************************************
*/
extern void FREG_VO_SetSdTtxhorstart_TtxHorStart( uint32_t value );
#else
INLINE void FREG_VO_SetSdTtxhorstart_TtxHorStart( uint32_t value )
{
    register uint32_t mask = 0x00000FFCUL;
    value = ( value << 2 ) & mask;
    value |= FREG_VO_SdTtxhorstartMirror & ~mask;
    FREG_VO_SdTtxhorstartMirror = value;
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_SDTTXHORSTART, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_SDTTXHORSTART)) = value;
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
extern uint32_t FREG_VO_GetmSdTtxhorstart( void );
#else
INLINE uint32_t FREG_VO_GetmSdTtxhorstart( void )
{
    register uint32_t value = FREG_VO_SdTtxhorstartMirror;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "TtxEn" of register "SdTtxhorstart".
**
** Teletext insertion enable bit
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxEn" consists of the bits 16..16,
**       the given bitgroup value will be shifted left by 16 bits and
**       masked using the bitmask 0x00010000UL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdTtxhorstart_TtxEn( void );
#else
INLINE uint32_t FREG_VO_GetmSdTtxhorstart_TtxEn( void )
{
    register uint32_t value = FREG_VO_SdTtxhorstartMirror;
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
** 0MHz clock cycles. If the pixel counter reaches this value (times 4), the Teletext data will be inserted in the video plane (plane 1). Typical value for PAL: = 528 --> 132
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TtxHorStart" consists of the bits 11..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000FFCUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetmSdTtxhorstart_TtxHorStart( void );
#else
INLINE uint32_t FREG_VO_GetmSdTtxhorstart_TtxHorStart( void )
{
    register uint32_t value = FREG_VO_SdTtxhorstartMirror;
    value = ( value & 0x00000FFCUL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Mixyuvrgb".
**
** This function writes the given value to the index-th entry of the register
** array Mixyuvrgb.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetMixyuvrgb( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetMixyuvrgb( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_MIXYUVRGB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_MIXYUVRGB+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "Mixyuvrgb".
**
** YUV2RGB conversion matrix values (signed)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetMixyuvrgb_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetMixyuvrgb_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_MIXYUVRGB+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_MIXYUVRGB+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_MIXYUVRGB+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Mixyuvrgb".
**
** This function reads the value from the index-th entry of the register
** array Mixyuvrgb.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetMixyuvrgb( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetMixyuvrgb( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_MIXYUVRGB+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "Mixyuvrgb".
**
** YUV2RGB conversion matrix values (signed)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetMixyuvrgb_Data( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetMixyuvrgb_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_MIXYUVRGB+(index*0x4)));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Mixrgbyuv".
**
** This function writes the given value to the index-th entry of the register
** array Mixrgbyuv.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetMixrgbyuv( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetMixrgbyuv( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_MIXRGBYUV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_MIXRGBYUV+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "Mixrgbyuv".
**
** RGB2YUV conversion matrix values (signed)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_VO_SetMixrgbyuv_Data( uint32_t index, uint32_t value );
#else
INLINE void FREG_VO_SetMixrgbyuv_Data( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_MIXRGBYUV+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_MIXRGBYUV+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_VO_MIXRGBYUV+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Mixrgbyuv".
**
** This function reads the value from the index-th entry of the register
** array Mixrgbyuv.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetMixrgbyuv( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetMixrgbyuv( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_MIXRGBYUV+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "Mixrgbyuv".
**
** RGB2YUV conversion matrix values (signed)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetMixrgbyuv_Data( uint32_t index );
#else
INLINE uint32_t FREG_VO_GetMixrgbyuv_Data( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 12 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_VO_MIXRGBYUV+(index*0x4)));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "Cursorversize".
**
** This function writes the given value to the register "Cursorversize".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_VO_SetCursorversize( uint32_t value );
#else
INLINE void FREG_VO_SetCursorversize( uint32_t value )
{
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORVERSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cursorversize" of register "Cursorversize".
**
** Total cursor size in 32bit words.
** 
** This value is used for vertical repetition of cursor
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cursorversize" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern void FREG_VO_SetCursorversize_Cursorversize( uint32_t value );
#else
INLINE void FREG_VO_SetCursorversize_Cursorversize( uint32_t value )
{
    register uint32_t mask = 0x00000FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_VO_CURSORVERSIZE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_VO_ENABLE_DEBUG_PRINT == 1
        FREG_VO_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_VO", FREG_VO_CURSORVERSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_VO_CURSORVERSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Cursorversize".
**
** This function reads the value from the register "Cursorversize".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursorversize( void );
#else
INLINE uint32_t FREG_VO_GetCursorversize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORVERSIZE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cursorversize" of register "Cursorversize".
**
** Total cursor size in 32bit words.
** 
** This value is used for vertical repetition of cursor
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cursorversize" consists of the bits 11..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_VO_GetCursorversize_Cursorversize( void );
#else
INLINE uint32_t FREG_VO_GetCursorversize_Cursorversize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_VO_CURSORVERSIZE));
    value = ( value & 0x00000FFFUL ) >> 0;
    return( value );
}
#endif

/*!
********************************************************************************
**
** \brief Initializes the "VO" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
extern void FREG_VO_Init( void );

#endif
