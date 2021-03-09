/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_ddrramif.h
**
** \brief     DDRRAMIF access functions
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
#if !defined(FREG_DDRRAMIF_H)
#define FREG_DDRRAMIF_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_DDRRAMIF_ENABLE_DEBUG_PRINT   0
#define FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION printf

#if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_DDRRAMIF_RAMIFSVERSION              FIO_ADDRESS(DDRRAMIF,0xDD000000UL)
#define FREG_DDRRAMIF_RAMIFSDUMMYFF              FIO_ADDRESS(DDRRAMIF,0xDD000004UL)
#define FREG_DDRRAMIF_RAMIFSENABLE               FIO_ADDRESS(DDRRAMIF,0xDD000008UL)
#define FREG_DDRRAMIF_RAMIFSSTATUS               FIO_ADDRESS(DDRRAMIF,0xDD00000CUL)
#define FREG_DDRRAMIF_RAMIFSSDRAMTYPE            FIO_ADDRESS(DDRRAMIF,0xDD000100UL)
#define FREG_DDRRAMIF_RAMIFSACSPEC_1             FIO_ADDRESS(DDRRAMIF,0xDD000104UL)
#define FREG_DDRRAMIF_RAMIFSACSPEC_2             FIO_ADDRESS(DDRRAMIF,0xDD000108UL)
#define FREG_DDRRAMIF_RAMIFSACSPEC_3             FIO_ADDRESS(DDRRAMIF,0xDD00010CUL)
#define FREG_DDRRAMIF_RAMIFSACSPEC_4             FIO_ADDRESS(DDRRAMIF,0xDD000110UL)
#define FREG_DDRRAMIF_RAMIFSACSPEC_5             FIO_ADDRESS(DDRRAMIF,0xDD000114UL)
#define FREG_DDRRAMIF_RAMIFSDATADELAY            FIO_ADDRESS(DDRRAMIF,0xDD000118UL)
#define FREG_DDRRAMIF_RAMIFSODTMODE              FIO_ADDRESS(DDRRAMIF,0xDD000200UL)
#define FREG_DDRRAMIF_RAMIFSODTDELAY1            FIO_ADDRESS(DDRRAMIF,0xDD000204UL)
#define FREG_DDRRAMIF_RAMIFSODTDELAY2            FIO_ADDRESS(DDRRAMIF,0xDD000208UL)
#define FREG_DDRRAMIF_RAMIFSODTDELAY3            FIO_ADDRESS(DDRRAMIF,0xDD00020CUL)
#define FREG_DDRRAMIF_RAMIFSODTDELAY4            FIO_ADDRESS(DDRRAMIF,0xDD000210UL)
#define FREG_DDRRAMIF_RAMIFSPIRLOMODE            FIO_ADDRESS(DDRRAMIF,0xDD000300UL)
#define FREG_DDRRAMIF_RAMIFSPIRLORID             FIO_ADDRESS(DDRRAMIF,0xDD000304UL)
#define FREG_DDRRAMIF_RAMIFSPIRLOWID             FIO_ADDRESS(DDRRAMIF,0xDD000308UL)
#define FREG_DDRRAMIF_RAMIFSMACRORST             FIO_ADDRESS(DDRRAMIF,0xDD000500UL)
#define FREG_DDRRAMIF_RAMIFSDLLSET               FIO_ADDRESS(DDRRAMIF,0xDD000504UL)
#define FREG_DDRRAMIF_RAMIFSOCDSET               FIO_ADDRESS(DDRRAMIF,0xDD000508UL)
#define FREG_DDRRAMIF_RAMIFSOCDRESULT            FIO_ADDRESS(DDRRAMIF,0xDD00050CUL)
#define FREG_DDRRAMIF_RAMIFSODTSET               FIO_ADDRESS(DDRRAMIF,0xDD000510UL)
#define FREG_DDRRAMIF_RAMIFSIOCONTSET            FIO_ADDRESS(DDRRAMIF,0xDD000514UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMCMD             FIO_ADDRESS(DDRRAMIF,0xDD000600UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMDEF             FIO_ADDRESS(DDRRAMIF,0xDD000604UL)
#define FREG_DDRRAMIF_RAMIFSIOLOCK               FIO_ADDRESS(DDRRAMIF,0xDD000608UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMADR             FIO_ADDRESS(DDRRAMIF,0xDD00060CUL)
#define FREG_DDRRAMIF_RAMIFSSDRAMDATAH           FIO_ADDRESS(DDRRAMIF,0xDD000610UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMDATAL           FIO_ADDRESS(DDRRAMIF,0xDD000614UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMMASK            FIO_ADDRESS(DDRRAMIF,0xDD000618UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0          FIO_ADDRESS(DDRRAMIF,0xDD00061CUL)
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1          FIO_ADDRESS(DDRRAMIF,0xDD000620UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2          FIO_ADDRESS(DDRRAMIF,0xDD000624UL)
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3          FIO_ADDRESS(DDRRAMIF,0xDD000628UL)
#define FREG_DDRRAMIF_RAMIFVVERSION              FIO_ADDRESS(DDRRAMIF,0xDE000000UL)
#define FREG_DDRRAMIF_RAMIFVDUMMYFF              FIO_ADDRESS(DDRRAMIF,0xDE000004UL)
#define FREG_DDRRAMIF_RAMIFVENABLE               FIO_ADDRESS(DDRRAMIF,0xDE000008UL)
#define FREG_DDRRAMIF_RAMIFVSTATUS               FIO_ADDRESS(DDRRAMIF,0xDE00000CUL)
#define FREG_DDRRAMIF_RAMIFVCLK                  FIO_ADDRESS(DDRRAMIF,0xDE000010UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMTYPE            FIO_ADDRESS(DDRRAMIF,0xDE000100UL)
#define FREG_DDRRAMIF_RAMIFVACSPEC_2             FIO_ADDRESS(DDRRAMIF,0xDE000104UL)
#define FREG_DDRRAMIF_RAMIFVACSPEC_5             FIO_ADDRESS(DDRRAMIF,0xDE000110UL)
#define FREG_DDRRAMIF_RAMIFVDATADELAY            FIO_ADDRESS(DDRRAMIF,0xDE000114UL)
#define FREG_DDRRAMIF_RAMIFVODTDELAY1            FIO_ADDRESS(DDRRAMIF,0xDE000204UL)
#define FREG_DDRRAMIF_RAMIFVODTDELAY2            FIO_ADDRESS(DDRRAMIF,0xDE000208UL)
#define FREG_DDRRAMIF_RAMIFVODTDELAY3            FIO_ADDRESS(DDRRAMIF,0xDE00020CUL)
#define FREG_DDRRAMIF_RAMIFVODTDELAY4            FIO_ADDRESS(DDRRAMIF,0xDE000210UL)
#define FREG_DDRRAMIF_RAMIFVMACRORST             FIO_ADDRESS(DDRRAMIF,0xDE000500UL)
#define FREG_DDRRAMIF_RAMIFVDLLSET               FIO_ADDRESS(DDRRAMIF,0xDE000504UL)
#define FREG_DDRRAMIF_RAMIFVOCDSET               FIO_ADDRESS(DDRRAMIF,0xDE000508UL)
#define FREG_DDRRAMIF_RAMIFVOCDRESULT            FIO_ADDRESS(DDRRAMIF,0xDE00050CUL)
#define FREG_DDRRAMIF_RAMIFVODTSET               FIO_ADDRESS(DDRRAMIF,0xDE000510UL)
#define FREG_DDRRAMIF_RAMIFVIOCONTSET            FIO_ADDRESS(DDRRAMIF,0xDE000514UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMCMD             FIO_ADDRESS(DDRRAMIF,0xDE000600UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMDEF             FIO_ADDRESS(DDRRAMIF,0xDE000604UL)
#define FREG_DDRRAMIF_RAMIFVIOLOCK               FIO_ADDRESS(DDRRAMIF,0xDE000608UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMADR             FIO_ADDRESS(DDRRAMIF,0xDE00060CUL)
#define FREG_DDRRAMIF_RAMIFVSDRAMDATAH           FIO_ADDRESS(DDRRAMIF,0xDE000610UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMDATAL           FIO_ADDRESS(DDRRAMIF,0xDE000614UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMMASK            FIO_ADDRESS(DDRRAMIF,0xDE000618UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0          FIO_ADDRESS(DDRRAMIF,0xDE00061CUL)
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1          FIO_ADDRESS(DDRRAMIF,0xDE000620UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2          FIO_ADDRESS(DDRRAMIF,0xDE000624UL)
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3          FIO_ADDRESS(DDRRAMIF,0xDE000628UL)
#define FREG_DDRRAMIF_RAMIFVCORESEL              FIO_ADDRESS(DDRRAMIF,0xDE000700UL)
#define FREG_DDRRAMIF_RAMIFVBANKN                FIO_ADDRESS(DDRRAMIF,0xDE000800UL)
#define FREG_DDRRAMIF_RAMIFVYB                   FIO_ADDRESS(DDRRAMIF,0xDE000858UL)
#define FREG_DDRRAMIF_RAMIFVCT                   FIO_ADDRESS(DDRRAMIF,0xDE00085CUL)
#define FREG_DDRRAMIF_RAMIFVCB                   FIO_ADDRESS(DDRRAMIF,0xDE000860UL)
#define FREG_DDRRAMIF_RAMIFVSIZE                 FIO_ADDRESS(DDRRAMIF,0xDE000864UL)
#define FREG_DDRRAMIF_RAMIFVERROR                FIO_ADDRESS(DDRRAMIF,0xDE000A00UL)

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
** \brief Reads the entire register "RamifSVersion".
**
** This function reads the value from the register "RamifSVersion".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSVersion( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSVersion( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSVERSION));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mm" of register "RamifSVersion".
**
** Integer part of RTL version (decimal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mm" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSVersion_Mm( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSVersion_Mm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSVERSION));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Nn" of register "RamifSVersion".
**
** Fractional part of RTL version (decimal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Nn" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSVersion_Nn( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSVersion_Nn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSVERSION));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSDummyFf".
**
** This function writes the given value to the register "RamifSDummyFf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDummyFf( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDummyFf( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDUMMYFF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDUMMYFF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dummy" of register "RamifSDummyFf".
**
** Dummy
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dummy" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDummyFf_Dummy( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDummyFf_Dummy( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDUMMYFF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDUMMYFF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDUMMYFF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSDummyFf".
**
** This function reads the value from the register "RamifSDummyFf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDummyFf( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDummyFf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDUMMYFF));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dummy" of register "RamifSDummyFf".
**
** Dummy
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dummy" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDummyFf_Dummy( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDummyFf_Dummy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDUMMYFF));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSEnable".
**
** This function writes the given value to the register "RamifSEnable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSEnable( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSEnable( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ref" of register "RamifSEnable".
**
** Auto Refresh Enable
** We recommend that you set this bit to '0' when you issue SDRAM command consciously using the command registers.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ref" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSEnable_Ref( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSEnable_Ref( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSEnable".
**
** This function reads the value from the register "RamifSEnable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSEnable( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSEnable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ref" of register "RamifSEnable".
**
** Auto Refresh Enable
** We recommend that you set this bit to '0' when you issue SDRAM command consciously using the command registers.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ref" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSEnable_Ref( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSEnable_Ref( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSStatus".
**
** This function reads the value from the register "RamifSStatus".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSStatus( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSTATUS));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bsy" of register "RamifSStatus".
**
** RAMIF_S Busy
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bsy" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSStatus_Bsy( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSStatus_Bsy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSTATUS));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramType".
**
** This function writes the given value to the register "RamifSSdramType".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramType( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramType( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMTYPE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMTYPE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ramtype" of register "RamifSSdramType".
**
** RAM Size
** - '00': 256MBit
** - '01': 512MBit
** - '10': 1GBit
** - '11': not used
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ramtype" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramType_Ramtype( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramType_Ramtype( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMTYPE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMTYPE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMTYPE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramType".
**
** This function reads the value from the register "RamifSSdramType".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramType( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramType( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMTYPE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ramtype" of register "RamifSSdramType".
**
** RAM Size
** - '00': 256MBit
** - '01': 512MBit
** - '10': 1GBit
** - '11': not used
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ramtype" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramType_Ramtype( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramType_Ramtype( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMTYPE));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSAcSpec_1".
**
** This function writes the given value to the register "RamifSAcSpec_1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_1( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Al" of register "RamifSAcSpec_1".
**
** Additive Latency
** Range: 0 - 5
** (RCD-AL) should be positive odd number.
** 
** Set '4' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Al" consists of the bits 15..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x0000F000UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_1_Al( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_1_Al( uint32_t value )
{
    register uint32_t mask = 0x0000F000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wl" of register "RamifSAcSpec_1".
**
** Write Latency
** Range: (AL+1) =< WL =< (AL+4)
** Set '8' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wl" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_1_Wl( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_1_Wl( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rcd" of register "RamifSAcSpec_1".
**
** RAS-CAS Delay
** Range: 5 - 9
** Set '5' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rcd" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_1_Rcd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_1_Rcd( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSAcSpec_1".
**
** This function reads the value from the register "RamifSAcSpec_1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Al" of register "RamifSAcSpec_1".
**
** Additive Latency
** Range: 0 - 5
** (RCD-AL) should be positive odd number.
** 
** Set '4' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Al" consists of the bits 15..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x0000F000UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1_Al( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1_Al( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1));
    value = ( value & 0x0000F000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wl" of register "RamifSAcSpec_1".
**
** Write Latency
** Range: (AL+1) =< WL =< (AL+4)
** Set '8' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wl" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1_Wl( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1_Wl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rcd" of register "RamifSAcSpec_1".
**
** RAS-CAS Delay
** Range: 5 - 9
** Set '5' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rcd" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1_Rcd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_1_Rcd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_1));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSAcSpec_2".
**
** This function writes the given value to the register "RamifSAcSpec_2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_2( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtp" of register "RamifSAcSpec_2".
**
** Read to Precharge
** Range: Greater or equal to '2'
** Set '3' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtp" consists of the bits 15..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x0000F000UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_2_Rtp( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_2_Rtp( uint32_t value )
{
    register uint32_t mask = 0x0000F000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wr" of register "RamifSAcSpec_2".
**
** Write Recovery
** Range: Greater or equal to '0'
** Set '5' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wr" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_2_Wr( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_2_Wr( uint32_t value )
{
    register uint32_t mask = 0x00000F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rp" of register "RamifSAcSpec_2".
**
** Precharge command period
** Range: Grater or equal to '1'
** Set '5' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rp" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_2_Rp( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_2_Rp( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rrd" of register "RamifSAcSpec_2".
**
** RAS to RAS
** Range: Even number greater or equal to '2'
** Set '4' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rrd" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_2_Rrd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_2_Rrd( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSAcSpec_2".
**
** This function reads the value from the register "RamifSAcSpec_2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtp" of register "RamifSAcSpec_2".
**
** Read to Precharge
** Range: Greater or equal to '2'
** Set '3' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtp" consists of the bits 15..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x0000F000UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Rtp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Rtp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2));
    value = ( value & 0x0000F000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wr" of register "RamifSAcSpec_2".
**
** Write Recovery
** Range: Greater or equal to '0'
** Set '5' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wr" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Wr( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Wr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2));
    value = ( value & 0x00000F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rp" of register "RamifSAcSpec_2".
**
** Precharge command period
** Range: Grater or equal to '1'
** Set '5' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rp" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Rp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Rp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rrd" of register "RamifSAcSpec_2".
**
** RAS to RAS
** Range: Even number greater or equal to '2'
** Set '4' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rrd" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Rrd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_2_Rrd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_2));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSAcSpec_3".
**
** This function writes the given value to the register "RamifSAcSpec_3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_3( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_3( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtw" of register "RamifSAcSpec_3".
**
** Read to Write
** Range: Even number greater or equal to '2'
** Set '4' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtw" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_3_Rtw( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_3_Rtw( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtr" of register "RamifSAcSpec_3".
**
** Write to Read
** Range: Greater or equal to '2', and (WL+WTR)=<15
** Set '3' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtr" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_3_Wtr( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_3_Wtr( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSAcSpec_3".
**
** This function reads the value from the register "RamifSAcSpec_3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_3( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtw" of register "RamifSAcSpec_3".
**
** Read to Write
** Range: Even number greater or equal to '2'
** Set '4' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtw" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_3_Rtw( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_3_Rtw( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtr" of register "RamifSAcSpec_3".
**
** Write to Read
** Range: Greater or equal to '2', and (WL+WTR)=<15
** Set '3' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtr" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_3_Wtr( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_3_Wtr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_3));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSAcSpec_4".
**
** This function writes the given value to the register "RamifSAcSpec_4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_4( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_4( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ras" of register "RamifSAcSpec_4".
**
** Active to Precharge
** Range: Greater or equal to '1'
** Set '15' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ras" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_4_Ras( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_4_Ras( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rfc" of register "RamifSAcSpec_4".
**
** Refresh to Active / Refresh to Refresh
** Range: Greater or equal to '2'
** Set '25' for DDR2 (256MBit)
** Set '35' for DDR2 (512MBit)
** Set '42' for DDR2 (1GBit)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rfc" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_4_Rfc( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_4_Rfc( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSAcSpec_4".
**
** This function reads the value from the register "RamifSAcSpec_4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_4( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ras" of register "RamifSAcSpec_4".
**
** Active to Precharge
** Range: Greater or equal to '1'
** Set '15' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ras" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_4_Ras( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_4_Ras( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rfc" of register "RamifSAcSpec_4".
**
** Refresh to Active / Refresh to Refresh
** Range: Greater or equal to '2'
** Set '25' for DDR2 (256MBit)
** Set '35' for DDR2 (512MBit)
** Set '42' for DDR2 (1GBit)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rfc" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_4_Rfc( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_4_Rfc( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_4));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSAcSpec_5".
**
** This function writes the given value to the register "RamifSAcSpec_5".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_5( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_5( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_5, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Refi" of register "RamifSAcSpec_5".
**
** Average periodic refresh interval
** Issues auto refresh command 4 times every 'REFI *4'
** interval.
** 
** Set '0x0980' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Refi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSAcSpec_5_Refi( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSAcSpec_5_Refi( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_5)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSACSPEC_5, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSAcSpec_5".
**
** This function reads the value from the register "RamifSAcSpec_5".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_5( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_5( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_5));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Refi" of register "RamifSAcSpec_5".
**
** Average periodic refresh interval
** Issues auto refresh command 4 times every 'REFI *4'
** interval.
** 
** Set '0x0980' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Refi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_5_Refi( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSAcSpec_5_Refi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSACSPEC_5));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSDataDelay".
**
** This function writes the given value to the register "RamifSDataDelay".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDataDelay( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDataDelay( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDATADELAY, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wdelay" of register "RamifSDataDelay".
**
** WDELAY
** Range: 5 - 6
** Set '6' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wdelay" consists of the bits 8..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000001E0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDataDelay_Wdelay( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDataDelay_Wdelay( uint32_t value )
{
    register uint32_t mask = 0x000001E0UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDATADELAY, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rdelay" of register "RamifSDataDelay".
**
** RDELAY
** Range: 18 - 20
** Set '19' for DDR2.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rdelay" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDataDelay_Rdelay( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDataDelay_Rdelay( uint32_t value )
{
    register uint32_t mask = 0x0000001FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDATADELAY, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSDataDelay".
**
** This function reads the value from the register "RamifSDataDelay".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDataDelay( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDataDelay( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wdelay" of register "RamifSDataDelay".
**
** WDELAY
** Range: 5 - 6
** Set '6' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wdelay" consists of the bits 8..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000001E0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDataDelay_Wdelay( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDataDelay_Wdelay( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY));
    value = ( value & 0x000001E0UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rdelay" of register "RamifSDataDelay".
**
** RDELAY
** Range: 18 - 20
** Set '19' for DDR2.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rdelay" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDataDelay_Rdelay( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDataDelay_Rdelay( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDATADELAY));
    value = ( value & 0x0000001FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOdtMode".
**
** This function writes the given value to the register "RamifSOdtMode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtMode( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtMode( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IoMode" of register "RamifSOdtMode".
**
** ODT control for IO
** - '00': OFF
** - '01': Read phase only
** - '10': From Read phase to Write phase
** - '11': Write phase only
** Set '01' for normal use
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IoMode" consists of the bits 3..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000000CUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtMode_IoMode( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtMode_IoMode( uint32_t value )
{
    register uint32_t mask = 0x0000000CUL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdMode" of register "RamifSOdtMode".
**
** ODT control for SDRAM
** - '00': OFF
** - '01': Read phase only
** - '10': From Read phase to Write phase
** - '11': Write phase only
** Set '01' for normal use
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdMode" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtMode_SdMode( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtMode_SdMode( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOdtMode".
**
** This function reads the value from the register "RamifSOdtMode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtMode( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IoMode" of register "RamifSOdtMode".
**
** ODT control for IO
** - '00': OFF
** - '01': Read phase only
** - '10': From Read phase to Write phase
** - '11': Write phase only
** Set '01' for normal use
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IoMode" consists of the bits 3..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000000CUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtMode_IoMode( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtMode_IoMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE));
    value = ( value & 0x0000000CUL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdMode" of register "RamifSOdtMode".
**
** ODT control for SDRAM
** - '00': OFF
** - '01': Read phase only
** - '10': From Read phase to Write phase
** - '11': Write phase only
** Set '01' for normal use
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdMode" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtMode_SdMode( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtMode_SdMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTMODE));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOdtDelay1".
**
** This function writes the given value to the register "RamifSOdtDelay1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay1( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtoh" of register "RamifSOdtDelay1".
**
** RTOH
** Set '7' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtoh" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay1_Rtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay1_Rtoh( uint32_t value )
{
    register uint32_t mask = 0x000003E0UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtol" of register "RamifSOdtDelay1".
**
** RTOL
** Set '16' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtol" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay1_Rtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay1_Rtol( uint32_t value )
{
    register uint32_t mask = 0x0000001FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOdtDelay1".
**
** This function reads the value from the register "RamifSOdtDelay1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtoh" of register "RamifSOdtDelay1".
**
** RTOH
** Set '7' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtoh" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay1_Rtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay1_Rtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1));
    value = ( value & 0x000003E0UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtol" of register "RamifSOdtDelay1".
**
** RTOL
** Set '16' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtol" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay1_Rtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay1_Rtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY1));
    value = ( value & 0x0000001FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOdtDelay2".
**
** This function writes the given value to the register "RamifSOdtDelay2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay2( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtol" of register "RamifSOdtDelay2".
**
** WTOL
** Set '10' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtol" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay2_Wtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay2_Wtol( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtoh" of register "RamifSOdtDelay2".
**
** WTOH
** Set '15' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtoh" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay2_Wtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay2_Wtoh( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOdtDelay2".
**
** This function reads the value from the register "RamifSOdtDelay2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtol" of register "RamifSOdtDelay2".
**
** WTOL
** Set '10' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtol" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay2_Wtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay2_Wtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtoh" of register "RamifSOdtDelay2".
**
** WTOH
** Set '15' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtoh" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay2_Wtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay2_Wtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY2));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOdtDelay3".
**
** This function writes the given value to the register "RamifSOdtDelay3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay3( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay3( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtoh" of register "RamifSOdtDelay3".
**
** WTOL
** Set '5' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtoh" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay3_Wtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay3_Wtoh( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtol" of register "RamifSOdtDelay3".
**
** WTOH
** Set '9' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtol" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay3_Wtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay3_Wtol( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOdtDelay3".
**
** This function reads the value from the register "RamifSOdtDelay3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay3( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtoh" of register "RamifSOdtDelay3".
**
** WTOL
** Set '5' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtoh" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay3_Wtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay3_Wtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtol" of register "RamifSOdtDelay3".
**
** WTOH
** Set '9' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtol" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay3_Wtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay3_Wtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY3));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOdtDelay4".
**
** This function writes the given value to the register "RamifSOdtDelay4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay4( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay4( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtol" of register "RamifSOdtDelay4".
**
** RTOL
** Set '2' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtol" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay4_Rtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay4_Rtol( uint32_t value )
{
    register uint32_t mask = 0x000003E0UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtoh" of register "RamifSOdtDelay4".
**
** RTOH
** Set '11' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtoh" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtDelay4_Rtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtDelay4_Rtoh( uint32_t value )
{
    register uint32_t mask = 0x0000001FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTDELAY4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOdtDelay4".
**
** This function reads the value from the register "RamifSOdtDelay4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay4( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtol" of register "RamifSOdtDelay4".
**
** RTOL
** Set '2' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtol" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay4_Rtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay4_Rtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4));
    value = ( value & 0x000003E0UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtoh" of register "RamifSOdtDelay4".
**
** RTOH
** Set '11' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtoh" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay4_Rtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtDelay4_Rtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTDELAY4));
    value = ( value & 0x0000001FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSPirloMode".
**
** This function writes the given value to the register "RamifSPirloMode".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloMode( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloMode( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Failsafe" of register "RamifSPirloMode".
**
** Fail-safe function
** - '0': Disable
** - '1': Enable
** Set '0' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Failsafe" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloMode_Failsafe( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloMode_Failsafe( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Enable" of register "RamifSPirloMode".
**
** Accepts more than 128bytes burst R/W request from the H.
** 264 Core. When this bit is set to '1', the RAMIF_S take the value of PIRLO_RID and PIRLO_WID, and rejects any requests from other masters during continuous access from the H.264 Core.
** - '0': Disable
** - '1': Enable
** Set '1' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Enable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloMode_Enable( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloMode_Enable( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLOMODE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSPirloMode".
**
** This function reads the value from the register "RamifSPirloMode".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloMode( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Failsafe" of register "RamifSPirloMode".
**
** Fail-safe function
** - '0': Disable
** - '1': Enable
** Set '0' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Failsafe" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloMode_Failsafe( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloMode_Failsafe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Enable" of register "RamifSPirloMode".
**
** Accepts more than 128bytes burst R/W request from the H.
** 264 Core. When this bit is set to '1', the RAMIF_S take the value of PIRLO_RID and PIRLO_WID, and rejects any requests from other masters during continuous access from the H.264 Core.
** - '0': Disable
** - '1': Enable
** Set '1' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Enable" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloMode_Enable( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloMode_Enable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOMODE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSPirloRid".
**
** This function writes the given value to the register "RamifSPirloRid".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloRid( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloRid( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLORID, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLORID)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rid" of register "RamifSPirloRid".
**
** Read ID for the H.
** 264 Core to identify the request from the H.264 Core on AXI bus
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rid" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloRid_Rid( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloRid_Rid( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLORID)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLORID, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLORID)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSPirloRid".
**
** This function reads the value from the register "RamifSPirloRid".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloRid( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloRid( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLORID));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rid" of register "RamifSPirloRid".
**
** Read ID for the H.
** 264 Core to identify the request from the H.264 Core on AXI bus
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rid" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloRid_Rid( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloRid_Rid( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLORID));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSPirloWid".
**
** This function writes the given value to the register "RamifSPirloWid".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloWid( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloWid( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLOWID, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOWID)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wid" of register "RamifSPirloWid".
**
** Write ID for the H.
** 264 Core to identify the request from the H.264 Core on AXI bus
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wid" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSPirloWid_Wid( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSPirloWid_Wid( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOWID)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSPIRLOWID, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOWID)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSPirloWid".
**
** This function reads the value from the register "RamifSPirloWid".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloWid( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloWid( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOWID));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wid" of register "RamifSPirloWid".
**
** Write ID for the H.
** 264 Core to identify the request from the H.264 Core on AXI bus
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wid" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSPirloWid_Wid( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSPirloWid_Wid( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSPIRLOWID));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSMacroRst".
**
** This function writes the given value to the register "RamifSMacroRst".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSMacroRst( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSMacroRst( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adj" of register "RamifSMacroRst".
**
** Reset for ODT function
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adj" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSMacroRst_Adj( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSMacroRst_Adj( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dllrst" of register "RamifSMacroRst".
**
** Reset for DLL
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dllrst" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSMacroRst_Dllrst( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSMacroRst_Dllrst( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Irstx" of register "RamifSMacroRst".
**
** Reset for IO macro
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Irstx" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSMacroRst_Irstx( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSMacroRst_Irstx( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSMacroRst".
**
** This function reads the value from the register "RamifSMacroRst".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSMacroRst( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSMacroRst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adj" of register "RamifSMacroRst".
**
** Reset for ODT function
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adj" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSMacroRst_Adj( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSMacroRst_Adj( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dllrst" of register "RamifSMacroRst".
**
** Reset for DLL
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dllrst" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSMacroRst_Dllrst( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSMacroRst_Dllrst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Irstx" of register "RamifSMacroRst".
**
** Reset for IO macro
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Irstx" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSMacroRst_Irstx( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSMacroRst_Irstx( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSMACRORST));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSDllSet".
**
** This function writes the given value to the register "RamifSDllSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDllSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDllSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Udset" of register "RamifSDllSet".
**
** Code change cycle control for DLL
** Set '0010' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Udset" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDllSet_Udset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDllSet_Udset( uint32_t value )
{
    register uint32_t mask = 0x00000F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Degsl1" of register "RamifSDllSet".
**
** Delay control-1 for DLL
** Set '0' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Degsl1" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDllSet_Degsl1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDllSet_Degsl1( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sft1" of register "RamifSDllSet".
**
** Delay control-2 for DLL
** Set '110' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sft1" consists of the bits 6..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000070UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDllSet_Sft1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDllSet_Sft1( uint32_t value )
{
    register uint32_t mask = 0x00000070UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Degsl0" of register "RamifSDllSet".
**
** Delay control-3 for DLL
** Set '0' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Degsl0" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDllSet_Degsl0( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDllSet_Degsl0( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sft0" of register "RamifSDllSet".
**
** Delay control-4 for DLL
** Set '110' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sft0" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSDllSet_Sft0( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSDllSet_Sft0( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSDllSet".
**
** This function reads the value from the register "RamifSDllSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDllSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDllSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Udset" of register "RamifSDllSet".
**
** Code change cycle control for DLL
** Set '0010' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Udset" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Udset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Udset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET));
    value = ( value & 0x00000F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Degsl1" of register "RamifSDllSet".
**
** Delay control-1 for DLL
** Set '0' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Degsl1" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Degsl1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Degsl1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sft1" of register "RamifSDllSet".
**
** Delay control-2 for DLL
** Set '110' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sft1" consists of the bits 6..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000070UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Sft1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Sft1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET));
    value = ( value & 0x00000070UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Degsl0" of register "RamifSDllSet".
**
** Delay control-3 for DLL
** Set '0' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Degsl0" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Degsl0( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Degsl0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sft0" of register "RamifSDllSet".
**
** Delay control-4 for DLL
** Set '110' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sft0" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Sft0( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSDllSet_Sft0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSDLLSET));
    value = ( value & 0x00000007UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOcdSet".
**
** This function writes the given value to the register "RamifSOcdSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOcdSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOcdSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Zsel" of register "RamifSOcdSet".
**
** Resistance value for OCD calibration
** - '0': 40?
** - '1': 28?
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Zsel" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOcdSet_Zsel( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOcdSet_Zsel( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pol" of register "RamifSOcdSet".
**
** Polarity for OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pol" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOcdSet_Pol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOcdSet_Pol( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ocd" of register "RamifSOcdSet".
**
** Set '1' for OCD calibration.
** 
** In case of OCD calibration, IODT should be set to '0'.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ocd" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOcdSet_Ocd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOcdSet_Ocd( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ds" of register "RamifSOcdSet".
**
** Setting value according to OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOcdSet_Ds( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOcdSet_Ds( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOcdSet".
**
** This function reads the value from the register "RamifSOcdSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Zsel" of register "RamifSOcdSet".
**
** Resistance value for OCD calibration
** - '0': 40?
** - '1': 28?
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Zsel" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Zsel( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Zsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pol" of register "RamifSOcdSet".
**
** Polarity for OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pol" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Pol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Pol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ocd" of register "RamifSOcdSet".
**
** Set '1' for OCD calibration.
** 
** In case of OCD calibration, IODT should be set to '0'.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ocd" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Ocd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Ocd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ds" of register "RamifSOcdSet".
**
** Setting value according to OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Ds( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdSet_Ds( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDSET));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOcdResult".
**
** This function reads the value from the register "RamifSOcdResult".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdResult( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdResult( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDRESULT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cp" of register "RamifSOcdResult".
**
** Result of OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cp" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOcdResult_Cp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOcdResult_Cp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSOCDRESULT));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSOdtSet".
**
** This function writes the given value to the register "RamifSOdtSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Zsel" of register "RamifSOdtSet".
**
** Resistance value for ODT calibration
** - '0': 150? or 100?
** - '1': 75? or 50?
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Zsel" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtSet_Zsel( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtSet_Zsel( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Off" of register "RamifSOdtSet".
**
** ODT function ON/OFF
** - '0': ON
** - '1': OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Off" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtSet_Off( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtSet_Off( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Avset" of register "RamifSOdtSet".
**
** ODT averaging number
** - '00': 32 times
** - '01': 64 times
** - '10': 128 times
** - '11': 256 times
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Avset" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSOdtSet_Avset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSOdtSet_Avset( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSOdtSet".
**
** This function reads the value from the register "RamifSOdtSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Zsel" of register "RamifSOdtSet".
**
** Resistance value for ODT calibration
** - '0': 150? or 100?
** - '1': 75? or 50?
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Zsel" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtSet_Zsel( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtSet_Zsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Off" of register "RamifSOdtSet".
**
** ODT function ON/OFF
** - '0': ON
** - '1': OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Off" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtSet_Off( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtSet_Off( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Avset" of register "RamifSOdtSet".
**
** ODT averaging number
** - '00': 32 times
** - '01': 64 times
** - '10': 128 times
** - '11': 256 times
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Avset" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSOdtSet_Avset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSOdtSet_Avset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSODTSET));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSIoContSet".
**
** This function writes the given value to the register "RamifSIoContSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dqp" of register "RamifSIoContSet".
**
** Control of flight time.
** 
** Set '01' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dqp" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet_Dqp( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet_Dqp( uint32_t value )
{
    register uint32_t mask = 0x00000300UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cken" of register "RamifSIoContSet".
**
** SDRAM clock enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cken" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet_Cken( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet_Cken( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Susp" of register "RamifSIoContSet".
**
** IO suspend
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Susp" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet_Susp( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet_Susp( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cval" of register "RamifSIoContSet".
**
** Loopback IO delay control
** - '00': about 1200ps
** - '01': about 1450ps
** - '10': about 1700ps
** - '11': about 1950ps
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cval" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet_Cval( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet_Cval( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rl" of register "RamifSIoContSet".
**
** Read Latency
** - '000': RL=2
** - '001': RL=3
** - '010': RL=4
** - '011': RL=5
** - '100': RL=6
** - '101': RL=7
** - '110': RL=8
** - '111': RL=9
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rl" consists of the bits 3..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x0000000EUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet_Rl( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet_Rl( uint32_t value )
{
    register uint32_t mask = 0x0000000EUL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bl" of register "RamifSIoContSet".
**
** Burst Length
** - '0': BL=4
** - '1': BL=8
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bl" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoContSet_Bl( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoContSet_Bl( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSIoContSet".
**
** This function reads the value from the register "RamifSIoContSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dqp" of register "RamifSIoContSet".
**
** Control of flight time.
** 
** Set '01' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dqp" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Dqp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Dqp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    value = ( value & 0x00000300UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cken" of register "RamifSIoContSet".
**
** SDRAM clock enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cken" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Cken( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Cken( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Susp" of register "RamifSIoContSet".
**
** IO suspend
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Susp" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Susp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Susp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cval" of register "RamifSIoContSet".
**
** Loopback IO delay control
** - '00': about 1200ps
** - '01': about 1450ps
** - '10': about 1700ps
** - '11': about 1950ps
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cval" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Cval( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Cval( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rl" of register "RamifSIoContSet".
**
** Read Latency
** - '000': RL=2
** - '001': RL=3
** - '010': RL=4
** - '011': RL=5
** - '100': RL=6
** - '101': RL=7
** - '110': RL=8
** - '111': RL=9
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rl" consists of the bits 3..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x0000000EUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Rl( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Rl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    value = ( value & 0x0000000EUL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bl" of register "RamifSIoContSet".
**
** Burst Length
** - '0': BL=4
** - '1': BL=8
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bl" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Bl( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoContSet_Bl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOCONTSET));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramCmd".
**
** This function writes the given value to the register "RamifSSdramCmd".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ocd" of register "RamifSSdramCmd".
**
** When this bit is set to '1', the values of SDRAM_OCD_DT0,1,2,3 registers are driven sequentially on DQ after WL latency.
**  This bit is used for OCD calibration."
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ocd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Ocd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Ocd( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Odt" of register "RamifSSdramCmd".
**
** ODT signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Odt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Odt( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cke" of register "RamifSSdramCmd".
**
** CKE signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Cke( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Cke( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcs" of register "RamifSSdramCmd".
**
** XCS signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Xcs( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Xcs( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xras" of register "RamifSSdramCmd".
**
** XRAS signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Xras( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Xras( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcas" of register "RamifSSdramCmd".
**
** XCAS signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Xcas( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Xcas( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xwe" of register "RamifSSdramCmd".
**
** XWE signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramCmd_Xwe( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramCmd_Xwe( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramCmd".
**
** This function reads the value from the register "RamifSSdramCmd".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ocd" of register "RamifSSdramCmd".
**
** When this bit is set to '1', the values of SDRAM_OCD_DT0,1,2,3 registers are driven sequentially on DQ after WL latency.
**  This bit is used for OCD calibration."
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ocd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Ocd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Ocd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Odt" of register "RamifSSdramCmd".
**
** ODT signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Odt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Odt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cke" of register "RamifSSdramCmd".
**
** CKE signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Cke( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Cke( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcs" of register "RamifSSdramCmd".
**
** XCS signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xcs( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xcs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xras" of register "RamifSSdramCmd".
**
** XRAS signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xras( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xras( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcas" of register "RamifSSdramCmd".
**
** XCAS signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xcas( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xcas( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xwe" of register "RamifSSdramCmd".
**
** XWE signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xwe( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramCmd_Xwe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMCMD));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramDef".
**
** This function writes the given value to the register "RamifSSdramDef".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Odt" of register "RamifSSdramDef".
**
** 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef_Odt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef_Odt( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cke" of register "RamifSSdramDef".
**
** When the write access to SDRAM_CMD register occurs,
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef_Cke( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef_Cke( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcs" of register "RamifSSdramDef".
**
** the value of Bit[5:0] are driven one cyle on each signal line,
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef_Xcs( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef_Xcs( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xras" of register "RamifSSdramDef".
**
** and then they are held with the value of Bit[5:0] of
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef_Xras( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef_Xras( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcas" of register "RamifSSdramDef".
**
** SDRAM_DEF register.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef_Xcas( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef_Xcas( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xwe" of register "RamifSSdramDef".
**
** 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDef_Xwe( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDef_Xwe( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramDef".
**
** This function reads the value from the register "RamifSSdramDef".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Odt" of register "RamifSSdramDef".
**
** 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Odt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Odt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cke" of register "RamifSSdramDef".
**
** When the write access to SDRAM_CMD register occurs,
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Cke( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Cke( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcs" of register "RamifSSdramDef".
**
** the value of Bit[5:0] are driven one cyle on each signal line,
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xcs( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xcs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xras" of register "RamifSSdramDef".
**
** and then they are held with the value of Bit[5:0] of
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xras( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xras( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcas" of register "RamifSSdramDef".
**
** SDRAM_DEF register.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xcas( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xcas( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xwe" of register "RamifSSdramDef".
**
** 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xwe( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDef_Xwe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDEF));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSIoLock".
**
** This function writes the given value to the register "RamifSIoLock".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoLock( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoLock( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Iodt" of register "RamifSIoLock".
**
** IODT signal of IO macro is fixed to '1', when this bit is set to '1'.
** "
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Iodt" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoLock_Iodt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoLock_Iodt( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xdqen" of register "RamifSIoLock".
**
** XDQEN forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xdqen" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoLock_Xdqen( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoLock_Xdqen( uint32_t value )
{
    register uint32_t mask = 0x00000F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xdqsen" of register "RamifSIoLock".
**
** XDQSEN forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xdqsen" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoLock_Xdqsen( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoLock_Xdqsen( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dqs" of register "RamifSIoLock".
**
** DQS forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dqs" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSIoLock_Dqs( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSIoLock_Dqs( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSIoLock".
**
** This function reads the value from the register "RamifSIoLock".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoLock( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoLock( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Iodt" of register "RamifSIoLock".
**
** IODT signal of IO macro is fixed to '1', when this bit is set to '1'.
** "
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Iodt" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Iodt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Iodt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xdqen" of register "RamifSIoLock".
**
** XDQEN forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xdqen" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Xdqen( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Xdqen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK));
    value = ( value & 0x00000F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xdqsen" of register "RamifSIoLock".
**
** XDQSEN forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xdqsen" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Xdqsen( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Xdqsen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dqs" of register "RamifSIoLock".
**
** DQS forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dqs" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Dqs( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSIoLock_Dqs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSIOLOCK));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramAdr".
**
** This function writes the given value to the register "RamifSSdramAdr".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramAdr( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramAdr( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMADR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ba" of register "RamifSSdramAdr".
**
** Bank address forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ba" consists of the bits 15..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x0000E000UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramAdr_Ba( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramAdr_Ba( uint32_t value )
{
    register uint32_t mask = 0x0000E000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMADR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "RamifSSdramAdr".
**
** Address[12:0] forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramAdr_Adr( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramAdr_Adr( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMADR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramAdr".
**
** This function reads the value from the register "RamifSSdramAdr".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramAdr( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramAdr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ba" of register "RamifSSdramAdr".
**
** Bank address forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ba" consists of the bits 15..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x0000E000UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramAdr_Ba( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramAdr_Ba( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR));
    value = ( value & 0x0000E000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "RamifSSdramAdr".
**
** Address[12:0] forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramAdr_Adr( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramAdr_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMADR));
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramDataH".
**
** This function writes the given value to the register "RamifSSdramDataH".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDataH( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDataH( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDATAH, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifSSdramDataH".
**
** DQ[31:16] forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDataH_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDataH_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAH)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDATAH, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramDataH".
**
** This function reads the value from the register "RamifSSdramDataH".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDataH( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDataH( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAH));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifSSdramDataH".
**
** DQ[31:16] forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDataH_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDataH_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAH));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramDataL".
**
** This function writes the given value to the register "RamifSSdramDataL".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDataL( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDataL( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDATAL, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifSSdramDataL".
**
** DQ[15:0] forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramDataL_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramDataL_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMDATAL, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramDataL".
**
** This function reads the value from the register "RamifSSdramDataL".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDataL( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDataL( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifSSdramDataL".
**
** DQ[15:0] forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramDataL_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramDataL_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMDATAL));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramMask".
**
** This function writes the given value to the register "RamifSSdramMask".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramMask( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramMask( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMMASK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mask" of register "RamifSSdramMask".
**
** SDRAM DQM forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mask" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramMask_Mask( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramMask_Mask( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMMASK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMMASK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramMask".
**
** This function reads the value from the register "RamifSSdramMask".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramMask( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramMask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMMASK));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mask" of register "RamifSSdramMask".
**
** SDRAM DQM forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mask" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramMask_Mask( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramMask_Mask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMMASK));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramOcdDt0".
**
** This function writes the given value to the register "RamifSSdramOcdDt0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt0( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt0( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifSSdramOcdDt0".
**
** SDRAM data: DT0=DQ[15:0] for OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt0_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt0_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramOcdDt0".
**
** This function reads the value from the register "RamifSSdramOcdDt0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt0( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifSSdramOcdDt0".
**
** SDRAM data: DT0=DQ[15:0] for OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt0_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt0_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramOcdDt1".
**
** This function writes the given value to the register "RamifSSdramOcdDt1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt1( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifSSdramOcdDt1".
**
** SDRAM data: DT1=DQ[31:16] for OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt1_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt1_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramOcdDt1".
**
** This function reads the value from the register "RamifSSdramOcdDt1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifSSdramOcdDt1".
**
** SDRAM data: DT1=DQ[31:16] for OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt1_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt1_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramOcdDt2".
**
** This function writes the given value to the register "RamifSSdramOcdDt2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt2( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifSSdramOcdDt2".
**
** SDRAM data: DT2=DQ[47:32] for OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt2_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt2_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramOcdDt2".
**
** This function reads the value from the register "RamifSSdramOcdDt2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifSSdramOcdDt2".
**
** SDRAM data: DT2=DQ[47:32] for OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt2_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt2_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifSSdramOcdDt3".
**
** This function writes the given value to the register "RamifSSdramOcdDt3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt3( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt3( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifSSdramOcdDt3".
**
** SDRAM data: DT3=DQ[63:48] for OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifSSdramOcdDt3_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifSSdramOcdDt3_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifSSdramOcdDt3".
**
** This function reads the value from the register "RamifSSdramOcdDt3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt3( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifSSdramOcdDt3".
**
** SDRAM data: DT3=DQ[63:48] for OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt3_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifSSdramOcdDt3_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVVersion".
**
** This function reads the value from the register "RamifVVersion".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVVersion( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVVersion( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVVERSION));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mm" of register "RamifVVersion".
**
** Integer part of RTL version (decimal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mm" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVVersion_Mm( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVVersion_Mm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVVERSION));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Nn" of register "RamifVVersion".
**
** Fractional part of RTL version (decimal)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Nn" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVVersion_Nn( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVVersion_Nn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVVERSION));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVDummyFf".
**
** This function writes the given value to the register "RamifVDummyFf".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDummyFf( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDummyFf( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDUMMYFF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDUMMYFF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dummy" of register "RamifVDummyFf".
**
** Dummy
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dummy" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDummyFf_Dummy( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDummyFf_Dummy( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDUMMYFF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDUMMYFF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDUMMYFF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVDummyFf".
**
** This function reads the value from the register "RamifVDummyFf".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDummyFf( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDummyFf( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDUMMYFF));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dummy" of register "RamifVDummyFf".
**
** Dummy
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dummy" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDummyFf_Dummy( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDummyFf_Dummy( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDUMMYFF));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVEnable".
**
** This function writes the given value to the register "RamifVEnable".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVEnable( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVEnable( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mcif" of register "RamifVEnable".
**
** MCIF request acceptance
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mcif" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVEnable_Mcif( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVEnable_Mcif( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ref" of register "RamifVEnable".
**
** Auto Refresh Enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ref" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVEnable_Ref( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVEnable_Ref( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVENABLE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVEnable".
**
** This function reads the value from the register "RamifVEnable".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVEnable( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVEnable( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mcif" of register "RamifVEnable".
**
** MCIF request acceptance
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mcif" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVEnable_Mcif( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVEnable_Mcif( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ref" of register "RamifVEnable".
**
** Auto Refresh Enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ref" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVEnable_Ref( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVEnable_Ref( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVENABLE));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVStatus".
**
** This function reads the value from the register "RamifVStatus".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVStatus( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVStatus( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSTATUS));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "McifW" of register "RamifVStatus".
**
** MCIF Write request
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "McifW" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVStatus_McifW( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVStatus_McifW( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSTATUS));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "McifR" of register "RamifVStatus".
**
** MCIF Read request
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "McifR" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVStatus_McifR( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVStatus_McifR( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSTATUS));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Axi" of register "RamifVStatus".
**
** AXI status
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Axi" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVStatus_Axi( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVStatus_Axi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSTATUS));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVClk".
**
** This function writes the given value to the register "RamifVClk".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVClk( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVClk( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCLK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pi4" of register "RamifVClk".
**
** PICLK_4RV control:
** - '0': Clock is not distributed
** - '1': Clock is distributed
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pi4" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVClk_Pi4( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVClk_Pi4( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCLK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pi3" of register "RamifVClk".
**
** PICLK_3RV control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pi3" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVClk_Pi3( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVClk_Pi3( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCLK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pi2" of register "RamifVClk".
**
** PICLK_2RV control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pi2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVClk_Pi2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVClk_Pi2( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCLK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pi1" of register "RamifVClk".
**
** PICLK_1RV control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pi1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVClk_Pi1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVClk_Pi1( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCLK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sd" of register "RamifVClk".
**
** SDCLK_1RV control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sd" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVClk_Sd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVClk_Sd( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCLK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVClk".
**
** This function reads the value from the register "RamifVClk".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVClk( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVClk( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pi4" of register "RamifVClk".
**
** PICLK_4RV control:
** - '0': Clock is not distributed
** - '1': Clock is distributed
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pi4" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi4( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pi3" of register "RamifVClk".
**
** PICLK_3RV control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pi3" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi3( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pi2" of register "RamifVClk".
**
** PICLK_2RV control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pi2" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pi1" of register "RamifVClk".
**
** PICLK_1RV control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pi1" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVClk_Pi1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sd" of register "RamifVClk".
**
** SDCLK_1RV control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sd" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVClk_Sd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVClk_Sd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCLK));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramType".
**
** This function writes the given value to the register "RamifVSdramType".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramType( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramType( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMTYPE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMTYPE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ramtype" of register "RamifVSdramType".
**
** RAM Size
** - '00': 256MBit
** - '01': 512MBit
** - '10': 1GBit
** - '11': not used
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ramtype" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramType_Ramtype( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramType_Ramtype( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMTYPE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMTYPE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMTYPE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramType".
**
** This function reads the value from the register "RamifVSdramType".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramType( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramType( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMTYPE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ramtype" of register "RamifVSdramType".
**
** RAM Size
** - '00': 256MBit
** - '01': 512MBit
** - '10': 1GBit
** - '11': not used
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ramtype" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramType_Ramtype( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramType_Ramtype( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMTYPE));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVAcSpec_2".
**
** This function writes the given value to the register "RamifVAcSpec_2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVAcSpec_2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVAcSpec_2( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ras" of register "RamifVAcSpec_2".
**
** Active to Precharge
** Range: Greater or equal to '2'
** Set to '15'
** [7:0];RFC;0;"Refresh to Active / Refresh to Refresh
** Range: Greater or equal to '2'
** Set to '25' for device with 256 Mbit
** Set to '35' for device with 512 Mbit
** Set to '42' for device with 1Gbit
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ras" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVAcSpec_2_Ras( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVAcSpec_2_Ras( uint32_t value )
{
    register uint32_t mask = 0x0000FF00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVACSPEC_2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVAcSpec_2".
**
** This function reads the value from the register "RamifVAcSpec_2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ras" of register "RamifVAcSpec_2".
**
** Active to Precharge
** Range: Greater or equal to '2'
** Set to '15'
** [7:0];RFC;0;"Refresh to Active / Refresh to Refresh
** Range: Greater or equal to '2'
** Set to '25' for device with 256 Mbit
** Set to '35' for device with 512 Mbit
** Set to '42' for device with 1Gbit
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ras" consists of the bits 15..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x0000FF00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_2_Ras( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_2_Ras( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_2));
    value = ( value & 0x0000FF00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVAcSpec_5".
**
** This function writes the given value to the register "RamifVAcSpec_5".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVAcSpec_5( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVAcSpec_5( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVACSPEC_5, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Refi" of register "RamifVAcSpec_5".
**
** Average periodic refresh interval
** Issues auto refresh command 4 times every 'REFI *4'
** interval.
** 
** Set to '0x0980' 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Refi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVAcSpec_5_Refi( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVAcSpec_5_Refi( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_5)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVACSPEC_5, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_5)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVAcSpec_5".
**
** This function reads the value from the register "RamifVAcSpec_5".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_5( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_5( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_5));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Refi" of register "RamifVAcSpec_5".
**
** Average periodic refresh interval
** Issues auto refresh command 4 times every 'REFI *4'
** interval.
** 
** Set to '0x0980' 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Refi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_5_Refi( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVAcSpec_5_Refi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVACSPEC_5));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVDataDelay".
**
** This function writes the given value to the register "RamifVDataDelay".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDataDelay( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDataDelay( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDATADELAY, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "IoMode" of register "RamifVDataDelay".
**
** ODT control for IO
** - '00': OFF
** - '01': ON in Read phase only
** - '10': ON from Read phase to Write phase
** - '11': OFF in Write phase only
** Set '01' for normal use
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "IoMode" consists of the bits 3..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000000CUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDataDelay_IoMode( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDataDelay_IoMode( uint32_t value )
{
    register uint32_t mask = 0x0000000CUL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDATADELAY, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SdMode" of register "RamifVDataDelay".
**
** ODT control for SDRAM
** - '00': OFF
** - '01': ON in Write phase only
** - '10': ON from Write phase to Read phase
** - '11': OFF in Read phase only
** Set '01' for normal use
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SdMode" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDataDelay_SdMode( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDataDelay_SdMode( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDATADELAY, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVDataDelay".
**
** This function reads the value from the register "RamifVDataDelay".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDataDelay( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDataDelay( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "IoMode" of register "RamifVDataDelay".
**
** ODT control for IO
** - '00': OFF
** - '01': ON in Read phase only
** - '10': ON from Read phase to Write phase
** - '11': OFF in Write phase only
** Set '01' for normal use
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "IoMode" consists of the bits 3..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x0000000CUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDataDelay_IoMode( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDataDelay_IoMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY));
    value = ( value & 0x0000000CUL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "SdMode" of register "RamifVDataDelay".
**
** ODT control for SDRAM
** - '00': OFF
** - '01': ON in Write phase only
** - '10': ON from Write phase to Read phase
** - '11': OFF in Read phase only
** Set '01' for normal use
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SdMode" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDataDelay_SdMode( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDataDelay_SdMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDATADELAY));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVOdtDelay1".
**
** This function writes the given value to the register "RamifVOdtDelay1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay1( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtoh" of register "RamifVOdtDelay1".
**
** RTOH
** Range: Greater or equal to '20'
** Set '5' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtoh" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay1_Rtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay1_Rtoh( uint32_t value )
{
    register uint32_t mask = 0x000003E0UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtol" of register "RamifVOdtDelay1".
**
** RTOL
** Range: Greater or equal to '20'
** Set '15' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtol" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay1_Rtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay1_Rtol( uint32_t value )
{
    register uint32_t mask = 0x0000001FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOdtDelay1".
**
** This function reads the value from the register "RamifVOdtDelay1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtoh" of register "RamifVOdtDelay1".
**
** RTOH
** Range: Greater or equal to '20'
** Set '5' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtoh" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay1_Rtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay1_Rtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1));
    value = ( value & 0x000003E0UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtol" of register "RamifVOdtDelay1".
**
** RTOL
** Range: Greater or equal to '20'
** Set '15' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtol" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay1_Rtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay1_Rtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY1));
    value = ( value & 0x0000001FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVOdtDelay2".
**
** This function writes the given value to the register "RamifVOdtDelay2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay2( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtol" of register "RamifVOdtDelay2".
**
** WTOL
** Set '9' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtol" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay2_Wtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay2_Wtol( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtoh" of register "RamifVOdtDelay2".
**
** WTOH
** Set '14' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtoh" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay2_Wtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay2_Wtoh( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOdtDelay2".
**
** This function reads the value from the register "RamifVOdtDelay2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtol" of register "RamifVOdtDelay2".
**
** WTOL
** Set '9' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtol" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay2_Wtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay2_Wtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtoh" of register "RamifVOdtDelay2".
**
** WTOH
** Set '14' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtoh" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay2_Wtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay2_Wtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY2));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVOdtDelay3".
**
** This function writes the given value to the register "RamifVOdtDelay3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay3( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay3( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtoh" of register "RamifVOdtDelay3".
**
** WTOL
** Set '4' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtoh" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay3_Wtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay3_Wtoh( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Wtol" of register "RamifVOdtDelay3".
**
** WTOH
** Set '8' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Wtol" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay3_Wtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay3_Wtol( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOdtDelay3".
**
** This function reads the value from the register "RamifVOdtDelay3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay3( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtoh" of register "RamifVOdtDelay3".
**
** WTOL
** Set '4' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtoh" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay3_Wtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay3_Wtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Wtol" of register "RamifVOdtDelay3".
**
** WTOH
** Set '8' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Wtol" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay3_Wtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay3_Wtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY3));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVOdtDelay4".
**
** This function writes the given value to the register "RamifVOdtDelay4".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay4( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay4( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtol" of register "RamifVOdtDelay4".
**
** RTOL
** Range: Greater or equal to '20'
** Set '0' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtol" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay4_Rtol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay4_Rtol( uint32_t value )
{
    register uint32_t mask = 0x000003E0UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rtoh" of register "RamifVOdtDelay4".
**
** RTOH
** Range: Greater or equal to '20'
** Set '10' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rtoh" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtDelay4_Rtoh( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtDelay4_Rtoh( uint32_t value )
{
    register uint32_t mask = 0x0000001FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTDELAY4, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOdtDelay4".
**
** This function reads the value from the register "RamifVOdtDelay4".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay4( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay4( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtol" of register "RamifVOdtDelay4".
**
** RTOL
** Range: Greater or equal to '20'
** Set '0' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtol" consists of the bits 9..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x000003E0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay4_Rtol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay4_Rtol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4));
    value = ( value & 0x000003E0UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rtoh" of register "RamifVOdtDelay4".
**
** RTOH
** Range: Greater or equal to '20'
** Set '10' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rtoh" consists of the bits 4..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000001FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay4_Rtoh( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtDelay4_Rtoh( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTDELAY4));
    value = ( value & 0x0000001FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVMacroRst".
**
** This function writes the given value to the register "RamifVMacroRst".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVMacroRst( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVMacroRst( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adj" of register "RamifVMacroRst".
**
** Reset for ODT function
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adj" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVMacroRst_Adj( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVMacroRst_Adj( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dllrst" of register "RamifVMacroRst".
**
** Reset for DLL
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dllrst" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVMacroRst_Dllrst( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVMacroRst_Dllrst( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Irstx" of register "RamifVMacroRst".
**
** Reset for IO macro
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Irstx" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVMacroRst_Irstx( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVMacroRst_Irstx( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVMACRORST, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVMacroRst".
**
** This function reads the value from the register "RamifVMacroRst".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVMacroRst( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVMacroRst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adj" of register "RamifVMacroRst".
**
** Reset for ODT function
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adj" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVMacroRst_Adj( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVMacroRst_Adj( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dllrst" of register "RamifVMacroRst".
**
** Reset for DLL
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dllrst" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVMacroRst_Dllrst( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVMacroRst_Dllrst( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Irstx" of register "RamifVMacroRst".
**
** Reset for IO macro
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Irstx" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVMacroRst_Irstx( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVMacroRst_Irstx( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVMACRORST));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVDllSet".
**
** This function writes the given value to the register "RamifVDllSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDllSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDllSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Udset" of register "RamifVDllSet".
**
** Code change cycle control for DLL
** Set '0010' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Udset" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDllSet_Udset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDllSet_Udset( uint32_t value )
{
    register uint32_t mask = 0x00000F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Degsl1" of register "RamifVDllSet".
**
** Delay control-1 for DLL
** Set '0' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Degsl1" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDllSet_Degsl1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDllSet_Degsl1( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sft1" of register "RamifVDllSet".
**
** Delay control-2 for DLL
** Set '110' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sft1" consists of the bits 6..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000070UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDllSet_Sft1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDllSet_Sft1( uint32_t value )
{
    register uint32_t mask = 0x00000070UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Degsl0" of register "RamifVDllSet".
**
** Delay control-3 for DLL
** Set '0' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Degsl0" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDllSet_Degsl0( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDllSet_Degsl0( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sft0" of register "RamifVDllSet".
**
** Delay control-4 for DLL
** Set '110' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sft0" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVDllSet_Sft0( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVDllSet_Sft0( uint32_t value )
{
    register uint32_t mask = 0x00000007UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 5
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVDLLSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVDllSet".
**
** This function reads the value from the register "RamifVDllSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDllSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDllSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Udset" of register "RamifVDllSet".
**
** Code change cycle control for DLL
** Set '0010' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Udset" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Udset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Udset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET));
    value = ( value & 0x00000F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Degsl1" of register "RamifVDllSet".
**
** Delay control-1 for DLL
** Set '0' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Degsl1" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Degsl1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Degsl1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sft1" of register "RamifVDllSet".
**
** Delay control-2 for DLL
** Set '110' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sft1" consists of the bits 6..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000070UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Sft1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Sft1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET));
    value = ( value & 0x00000070UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Degsl0" of register "RamifVDllSet".
**
** Delay control-3 for DLL
** Set '0' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Degsl0" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Degsl0( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Degsl0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sft0" of register "RamifVDllSet".
**
** Delay control-4 for DLL
** Set '110' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sft0" consists of the bits 2..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000007UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Sft0( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVDllSet_Sft0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVDLLSET));
    value = ( value & 0x00000007UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVOcdSet".
**
** This function writes the given value to the register "RamifVOcdSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOcdSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOcdSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Zsel" of register "RamifVOcdSet".
**
** Resistance value for OCD calibration
** - '0': 40?
** - '1': 28?
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Zsel" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOcdSet_Zsel( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOcdSet_Zsel( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Pol" of register "RamifVOcdSet".
**
** Polarity for OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Pol" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOcdSet_Pol( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOcdSet_Pol( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ocd" of register "RamifVOcdSet".
**
** Set '1' for OCD calibration.
** 
** In case of OCD calibration, IODT should be set to '0'.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ocd" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOcdSet_Ocd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOcdSet_Ocd( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ds" of register "RamifVOcdSet".
**
** Setting value according to OCD calibration
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOcdSet_Ds( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOcdSet_Ds( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVOCDSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOcdSet".
**
** This function reads the value from the register "RamifVOcdSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Zsel" of register "RamifVOcdSet".
**
** Resistance value for OCD calibration
** - '0': 40?
** - '1': 28?
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Zsel" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Zsel( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Zsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Pol" of register "RamifVOcdSet".
**
** Polarity for OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Pol" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Pol( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Pol( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ocd" of register "RamifVOcdSet".
**
** Set '1' for OCD calibration.
** 
** In case of OCD calibration, IODT should be set to '0'.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ocd" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Ocd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Ocd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ds" of register "RamifVOcdSet".
**
** Setting value according to OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ds" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Ds( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdSet_Ds( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDSET));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOcdResult".
**
** This function reads the value from the register "RamifVOcdResult".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdResult( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdResult( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDRESULT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cp" of register "RamifVOcdResult".
**
** Result of OCD calibration
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cp" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOcdResult_Cp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOcdResult_Cp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVOCDRESULT));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVOdtSet".
**
** This function writes the given value to the register "RamifVOdtSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Zsel" of register "RamifVOdtSet".
**
** Resistance value for ODT calibration
** - '0': 150? or 100?
** - '1': 75? or 50?
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Zsel" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtSet_Zsel( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtSet_Zsel( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Off" of register "RamifVOdtSet".
**
** ODT function ON/OFF
** - '0': ON
** - '1': OFF
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Off" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtSet_Off( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtSet_Off( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Avset" of register "RamifVOdtSet".
**
** ODT averaging number
** - '00': 32 times
** - '01': 64 times
** - '10': 128 times
** - '11': 256 times
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Avset" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVOdtSet_Avset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVOdtSet_Avset( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVODTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVOdtSet".
**
** This function reads the value from the register "RamifVOdtSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Zsel" of register "RamifVOdtSet".
**
** Resistance value for ODT calibration
** - '0': 150? or 100?
** - '1': 75? or 50?
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Zsel" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtSet_Zsel( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtSet_Zsel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Off" of register "RamifVOdtSet".
**
** ODT function ON/OFF
** - '0': ON
** - '1': OFF
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Off" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtSet_Off( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtSet_Off( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Avset" of register "RamifVOdtSet".
**
** ODT averaging number
** - '00': 32 times
** - '01': 64 times
** - '10': 128 times
** - '11': 256 times
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Avset" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVOdtSet_Avset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVOdtSet_Avset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVODTSET));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVIoContSet".
**
** This function writes the given value to the register "RamifVIoContSet".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dqp" of register "RamifVIoContSet".
**
** Control of flight time.
** 
** Set '01' for normal use.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dqp" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet_Dqp( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet_Dqp( uint32_t value )
{
    register uint32_t mask = 0x00000300UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cken" of register "RamifVIoContSet".
**
** SDRAM clock enable
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cken" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet_Cken( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet_Cken( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Susp" of register "RamifVIoContSet".
**
** IO suspend
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Susp" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet_Susp( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet_Susp( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cval" of register "RamifVIoContSet".
**
** Loopback IO delay control
** - '00': about 1200ps
** - '01': about 1450ps
** - '10': about 1700ps
** - '11': about 1950ps
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cval" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet_Cval( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet_Cval( uint32_t value )
{
    register uint32_t mask = 0x00000030UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Rl" of register "RamifVIoContSet".
**
** Read Latency
** - '000': RL=2
** - '001': RL=3
** - '010': RL=4
** - '011': RL=5
** - '100': RL=6
** - '101': RL=7
** - '110': RL=8
** - '111': RL=9
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Rl" consists of the bits 3..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x0000000EUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet_Rl( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet_Rl( uint32_t value )
{
    register uint32_t mask = 0x0000000EUL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Bl" of register "RamifVIoContSet".
**
** Burst Length
** - '0': BL=4
** - '1': BL=8
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Bl" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoContSet_Bl( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoContSet_Bl( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOCONTSET, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVIoContSet".
**
** This function reads the value from the register "RamifVIoContSet".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dqp" of register "RamifVIoContSet".
**
** Control of flight time.
** 
** Set '01' for normal use.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dqp" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Dqp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Dqp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    value = ( value & 0x00000300UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cken" of register "RamifVIoContSet".
**
** SDRAM clock enable
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cken" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Cken( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Cken( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Susp" of register "RamifVIoContSet".
**
** IO suspend
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Susp" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Susp( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Susp( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cval" of register "RamifVIoContSet".
**
** Loopback IO delay control
** - '00': about 1200ps
** - '01': about 1450ps
** - '10': about 1700ps
** - '11': about 1950ps
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cval" consists of the bits 5..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000030UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Cval( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Cval( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    value = ( value & 0x00000030UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Rl" of register "RamifVIoContSet".
**
** Read Latency
** - '000': RL=2
** - '001': RL=3
** - '010': RL=4
** - '011': RL=5
** - '100': RL=6
** - '101': RL=7
** - '110': RL=8
** - '111': RL=9
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Rl" consists of the bits 3..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x0000000EUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Rl( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Rl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    value = ( value & 0x0000000EUL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Bl" of register "RamifVIoContSet".
**
** Burst Length
** - '0': BL=4
** - '1': BL=8
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Bl" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Bl( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoContSet_Bl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOCONTSET));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramCmd".
**
** This function writes the given value to the register "RamifVSdramCmd".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ocd" of register "RamifVSdramCmd".
**
** When this bit is set to '1', the values of SDRAM_OCD_DT0,1,2,3 registers are driven sequentially on DQ after WL latency.
**  This bit is used for OCD calibration."
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ocd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Ocd( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Ocd( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Odt" of register "RamifVSdramCmd".
**
** ODT signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Odt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Odt( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cke" of register "RamifVSdramCmd".
**
** CKE signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Cke( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Cke( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcs" of register "RamifVSdramCmd".
**
** XCS signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Xcs( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Xcs( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xras" of register "RamifVSdramCmd".
**
** XRAS signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Xras( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Xras( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcas" of register "RamifVSdramCmd".
**
** XCAS signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Xcas( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Xcas( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xwe" of register "RamifVSdramCmd".
**
** XWE signal control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramCmd_Xwe( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramCmd_Xwe( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 7
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMCMD, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramCmd".
**
** This function reads the value from the register "RamifVSdramCmd".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ocd" of register "RamifVSdramCmd".
**
** When this bit is set to '1', the values of SDRAM_OCD_DT0,1,2,3 registers are driven sequentially on DQ after WL latency.
**  This bit is used for OCD calibration."
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ocd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Ocd( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Ocd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Odt" of register "RamifVSdramCmd".
**
** ODT signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Odt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Odt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cke" of register "RamifVSdramCmd".
**
** CKE signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Cke( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Cke( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcs" of register "RamifVSdramCmd".
**
** XCS signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xcs( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xcs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xras" of register "RamifVSdramCmd".
**
** XRAS signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xras( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xras( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcas" of register "RamifVSdramCmd".
**
** XCAS signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xcas( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xcas( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xwe" of register "RamifVSdramCmd".
**
** XWE signal control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xwe( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramCmd_Xwe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMCMD));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramDef".
**
** This function writes the given value to the register "RamifVSdramDef".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Odt" of register "RamifVSdramDef".
**
** 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef_Odt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef_Odt( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Cke" of register "RamifVSdramDef".
**
** When the write access to SDRAM_CMD register occurs,
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef_Cke( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef_Cke( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcs" of register "RamifVSdramDef".
**
** the value of Bit[5:0] are driven one cyle on each signal line,
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef_Xcs( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef_Xcs( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xras" of register "RamifVSdramDef".
**
** and then they are held with the value of Bit[5:0] of
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef_Xras( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef_Xras( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xcas" of register "RamifVSdramDef".
**
** SDRAM_DEF register.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef_Xcas( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef_Xcas( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xwe" of register "RamifVSdramDef".
**
** 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDef_Xwe( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDef_Xwe( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 6
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDEF, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramDef".
**
** This function reads the value from the register "RamifVSdramDef".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Odt" of register "RamifVSdramDef".
**
** 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Odt" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Odt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Odt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Cke" of register "RamifVSdramDef".
**
** When the write access to SDRAM_CMD register occurs,
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Cke" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Cke( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Cke( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcs" of register "RamifVSdramDef".
**
** the value of Bit[5:0] are driven one cyle on each signal line,
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcs" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xcs( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xcs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xras" of register "RamifVSdramDef".
**
** and then they are held with the value of Bit[5:0] of
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xras" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xras( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xras( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xcas" of register "RamifVSdramDef".
**
** SDRAM_DEF register.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xcas" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xcas( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xcas( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xwe" of register "RamifVSdramDef".
**
** 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xwe" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xwe( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDef_Xwe( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDEF));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVIoLock".
**
** This function writes the given value to the register "RamifVIoLock".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoLock( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoLock( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Iodt" of register "RamifVIoLock".
**
** IODT signal of IO macro is fixed to '1', when this bit is set to '1'.
** "
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Iodt" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoLock_Iodt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoLock_Iodt( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xdqen" of register "RamifVIoLock".
**
** XDQEN forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xdqen" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoLock_Xdqen( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoLock_Xdqen( uint32_t value )
{
    register uint32_t mask = 0x00000F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Xdqsen" of register "RamifVIoLock".
**
** XDQSEN forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Xdqsen" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoLock_Xdqsen( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoLock_Xdqsen( uint32_t value )
{
    register uint32_t mask = 0x000000F0UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Dqs" of register "RamifVIoLock".
**
** DQS forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Dqs" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVIoLock_Dqs( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVIoLock_Dqs( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 4
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVIOLOCK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVIoLock".
**
** This function reads the value from the register "RamifVIoLock".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoLock( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoLock( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Iodt" of register "RamifVIoLock".
**
** IODT signal of IO macro is fixed to '1', when this bit is set to '1'.
** "
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Iodt" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Iodt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Iodt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xdqen" of register "RamifVIoLock".
**
** XDQEN forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xdqen" consists of the bits 11..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000F00UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Xdqen( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Xdqen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK));
    value = ( value & 0x00000F00UL ) >> 8;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Xdqsen" of register "RamifVIoLock".
**
** XDQSEN forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Xdqsen" consists of the bits 7..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x000000F0UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Xdqsen( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Xdqsen( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK));
    value = ( value & 0x000000F0UL ) >> 4;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Dqs" of register "RamifVIoLock".
**
** DQS forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Dqs" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Dqs( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVIoLock_Dqs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVIOLOCK));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramAdr".
**
** This function writes the given value to the register "RamifVSdramAdr".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramAdr( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramAdr( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMADR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Ba" of register "RamifVSdramAdr".
**
** Bank address forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Ba" consists of the bits 15..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x0000E000UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramAdr_Ba( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramAdr_Ba( uint32_t value )
{
    register uint32_t mask = 0x0000E000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMADR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "RamifVSdramAdr".
**
** Address[12:0] forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramAdr_Adr( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramAdr_Adr( uint32_t value )
{
    register uint32_t mask = 0x00001FFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 2
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMADR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramAdr".
**
** This function reads the value from the register "RamifVSdramAdr".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramAdr( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramAdr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Ba" of register "RamifVSdramAdr".
**
** Bank address forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Ba" consists of the bits 15..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x0000E000UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramAdr_Ba( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramAdr_Ba( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR));
    value = ( value & 0x0000E000UL ) >> 13;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "RamifVSdramAdr".
**
** Address[12:0] forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 12..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00001FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramAdr_Adr( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramAdr_Adr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMADR));
    value = ( value & 0x00001FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramDataH".
**
** This function writes the given value to the register "RamifVSdramDataH".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDataH( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDataH( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDATAH, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifVSdramDataH".
**
** DQ[31:16] forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDataH_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDataH_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAH)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDATAH, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAH)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramDataH".
**
** This function reads the value from the register "RamifVSdramDataH".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDataH( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDataH( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAH));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifVSdramDataH".
**
** DQ[31:16] forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDataH_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDataH_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAH));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramDataL".
**
** This function writes the given value to the register "RamifVSdramDataL".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDataL( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDataL( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDATAL, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifVSdramDataL".
**
** DQ[15:0] forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramDataL_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramDataL_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMDATAL, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramDataL".
**
** This function reads the value from the register "RamifVSdramDataL".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDataL( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDataL( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifVSdramDataL".
**
** DQ[15:0] forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramDataL_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramDataL_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMDATAL));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramMask".
**
** This function writes the given value to the register "RamifVSdramMask".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramMask( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramMask( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMMASK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Mask" of register "RamifVSdramMask".
**
** SDRAM DQM forced control
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Mask" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramMask_Mask( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramMask_Mask( uint32_t value )
{
    register uint32_t mask = 0x0000000FUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMMASK)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMMASK, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMMASK)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramMask".
**
** This function reads the value from the register "RamifVSdramMask".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramMask( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramMask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMMASK));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Mask" of register "RamifVSdramMask".
**
** SDRAM DQM forced control
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Mask" consists of the bits 3..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000000FUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramMask_Mask( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramMask_Mask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMMASK));
    value = ( value & 0x0000000FUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramOcdDt0".
**
** This function writes the given value to the register "RamifVSdramOcdDt0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt0( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt0( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifVSdramOcdDt0".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[15:0].
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt0_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt0_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramOcdDt0".
**
** This function reads the value from the register "RamifVSdramOcdDt0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt0( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifVSdramOcdDt0".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[15:0].
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt0_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt0_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramOcdDt1".
**
** This function writes the given value to the register "RamifVSdramOcdDt1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt1( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt1( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifVSdramOcdDt1".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[31:16].
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt1_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt1_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramOcdDt1".
**
** This function reads the value from the register "RamifVSdramOcdDt1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt1( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifVSdramOcdDt1".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[31:16].
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt1_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt1_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramOcdDt2".
**
** This function writes the given value to the register "RamifVSdramOcdDt2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt2( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt2( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifVSdramOcdDt2".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[47:32].
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt2_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt2_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramOcdDt2".
**
** This function reads the value from the register "RamifVSdramOcdDt2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt2( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifVSdramOcdDt2".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[47:32].
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt2_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt2_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSdramOcdDt3".
**
** This function writes the given value to the register "RamifVSdramOcdDt3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt3( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt3( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Data" of register "RamifVSdramOcdDt3".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[63:48].
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSdramOcdDt3_Data( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSdramOcdDt3_Data( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSdramOcdDt3".
**
** This function reads the value from the register "RamifVSdramOcdDt3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt3( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Data" of register "RamifVSdramOcdDt3".
**
** This value is sent to SDRAM as 4bit burst code DT0 in DDR2 specification, and appear in RAMIF_V porrt as DQ[63:48].
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Data" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt3_Data( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSdramOcdDt3_Data( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVCoresel".
**
** This function writes the given value to the register "RamifVCoresel".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVCoresel( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVCoresel( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCORESEL, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCORESEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Sel" of register "RamifVCoresel".
**
** Selects core:
** - '0': H.
** 264 Core
** - '1': MPEG Core
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Sel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVCoresel_Sel( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVCoresel_Sel( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCORESEL)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCORESEL, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCORESEL)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVCoresel".
**
** This function reads the value from the register "RamifVCoresel".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVCoresel( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVCoresel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCORESEL));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Sel" of register "RamifVCoresel".
**
** Selects core:
** - '0': H.
** 264 Core
** - '1': MPEG Core
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Sel" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVCoresel_Sel( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVCoresel_Sel( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCORESEL));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVBankn".
**
** This function writes the given value to the index-th entry of the register
** array RamifVBankn.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVBankn( uint32_t index, uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVBankn( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 21 )
            return;
    #endif
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Adr" of register "RamifVBankn".
**
** The first address of Bank n
** The first address of the bank is specified by the unit of 4kbyte (A set value is BANK_ADDRESS (byte expression)/4096).
**  
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Adr" consists of the bits 14..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00007FFFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVBankn_Adr( uint32_t index, uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVBankn_Adr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00007FFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 21 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4), value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4))) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVBankn".
**
** This function reads the value from the index-th entry of the register
** array RamifVBankn.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVBankn( uint32_t index );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVBankn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 21 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4)));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Adr" of register "RamifVBankn".
**
** The first address of Bank n
** The first address of the bank is specified by the unit of 4kbyte (A set value is BANK_ADDRESS (byte expression)/4096).
**  
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Adr" consists of the bits 14..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00007FFFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVBankn_Adr( uint32_t index );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVBankn_Adr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 21 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVBANKN+(index*0x4)));
    value = ( value & 0x00007FFFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVYb".
**
** This function writes the given value to the register "RamifVYb".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVYb( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVYb( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVYB, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVYB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Offset" of register "RamifVYb".
**
** Offset from the first address of Luma Top area to the first address of Luma Bottom area
** The offset is set by the unit of 4kbyte (A set value is value (byte expression)/4096).
**  
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Offset" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVYb_Offset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVYb_Offset( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVYB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVYB, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVYB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVYb".
**
** This function reads the value from the register "RamifVYb".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVYb( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVYb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVYB));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Offset" of register "RamifVYb".
**
** Offset from the first address of Luma Top area to the first address of Luma Bottom area
** The offset is set by the unit of 4kbyte (A set value is value (byte expression)/4096).
**  
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Offset" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVYb_Offset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVYb_Offset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVYB));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVCt".
**
** This function writes the given value to the register "RamifVCt".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVCt( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVCt( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCT, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Offset" of register "RamifVCt".
**
** Offset from the first address of Luma Top area to the first address of Chroma Top area
** The offset is set by the unit of 4kbyte (A set value is value (byte expression)/4096).
**  
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Offset" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVCt_Offset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVCt_Offset( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCT)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCT, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCT)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVCt".
**
** This function reads the value from the register "RamifVCt".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVCt( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVCt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCT));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Offset" of register "RamifVCt".
**
** Offset from the first address of Luma Top area to the first address of Chroma Top area
** The offset is set by the unit of 4kbyte (A set value is value (byte expression)/4096).
**  
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Offset" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVCt_Offset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVCt_Offset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCT));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVCb".
**
** This function writes the given value to the register "RamifVCb".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVCb( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVCb( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCB, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Offset" of register "RamifVCb".
**
** Offset from the first address of Luma Top area to the first address of Chroma Bottom area
** The offset is set by the unit of 4kbyte (A set value is value (byte expression)/4096).
**  
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Offset" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVCb_Offset( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVCb_Offset( uint32_t value )
{
    register uint32_t mask = 0x000007FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCB)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVCB, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCB)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVCb".
**
** This function reads the value from the register "RamifVCb".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVCb( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVCb( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCB));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Offset" of register "RamifVCb".
**
** Offset from the first address of Luma Top area to the first address of Chroma Bottom area
** The offset is set by the unit of 4kbyte (A set value is value (byte expression)/4096).
**  
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Offset" consists of the bits 10..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000007FFUL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVCb_Offset( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVCb_Offset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVCB));
    value = ( value & 0x000007FFUL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVSize".
**
** This function writes the given value to the register "RamifVSize".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSize( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSize( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Size" of register "RamifVSize".
**
** Image size setting
** A horizontal image size is selected as follows:
** - '00': 1920
** - '01': 1440
** - '10': 1280
** - '11':   720
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Size" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVSize_Size( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVSize_Size( uint32_t value )
{
    register uint32_t mask = 0x00000003UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSIZE)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVSIZE, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSIZE)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVSize".
**
** This function reads the value from the register "RamifVSize".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSize( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSize( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSIZE));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Size" of register "RamifVSize".
**
** Image size setting
** A horizontal image size is selected as follows:
** - '00': 1920
** - '01': 1440
** - '10': 1280
** - '11':   720
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Size" consists of the bits 1..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000003UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVSize_Size( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVSize_Size( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVSIZE));
    value = ( value & 0x00000003UL ) >> 0;
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the entire register "RamifVError".
**
** This function writes the given value to the register "RamifVError".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVError( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVError( uint32_t value )
{
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVERROR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVERROR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Err" of register "RamifVError".
**
** It is shown that the access by an illegal parameter came to the address space for VOUT of AXI.
**  After the access is generated, it becomes one. To reset it, 0 is written.
** - '0': The access by an illegal parameter has not been
** generated
** - '1': The access by an illegal parameter was generated in
** the past. 
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Err" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_SetRamifVError_Err( uint32_t value );
#else
INLINE void FREG_DDRRAMIF_SetRamifVError_Err( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVERROR)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_DDRRAMIF_ENABLE_DEBUG_PRINT == 1
        FREG_DDRRAMIF_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_DDRRAMIF", FREG_DDRRAMIF_RAMIFVERROR, value );
    #endif
    *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVERROR)) = value;
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "RamifVError".
**
** This function reads the value from the register "RamifVError".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVError( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVError( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVERROR));
    return( value );
}
#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the bitgroup "Err" of register "RamifVError".
**
** It is shown that the access by an illegal parameter came to the address space for VOUT of AXI.
**  After the access is generated, it becomes one. To reset it, 0 is written.
** - '0': The access by an illegal parameter has not been
** generated
** - '1': The access by an illegal parameter was generated in
** the past. 
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Err" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/
extern uint32_t FREG_DDRRAMIF_GetRamifVError_Err( void );
#else
INLINE uint32_t FREG_DDRRAMIF_GetRamifVError_Err( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_DDRRAMIF_RAMIFVERROR));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
#endif

/*!
********************************************************************************
**
** \brief Initializes the "DDRRAMIF" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
extern void FREG_DDRRAMIF_Init( void );

#endif
