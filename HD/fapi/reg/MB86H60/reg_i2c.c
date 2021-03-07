/*
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_i2c.c
**
** \brief     I2C access functions
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
#define FREG_I2C_C

#include <stdint.h>
#include "reg_i2c.h"

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
** \brief Reads the entire register "Statusreg0".
**
** This function reads the value from the index-th entry of the register
** array Statusreg0.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_1"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_1" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_1")))
#endif

uint32_t FREG_I2C_GetStatusreg0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_STATUSREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SlRstart" of register "Statusreg0".
**
** Slave recognised, repeated start condition in slave mode,
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlRstart" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_2"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_2" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_2")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_SlRstart( uint32_t value )
{
    value = ( value & 0x00008000UL ) >> 15;
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
** \brief Reads the bitgroup "StopTrm" of register "Statusreg0".
**
** Stop condition was sent in master mode
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "StopTrm" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_3"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_3" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_3")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_StopTrm( uint32_t value )
{
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
** \brief Reads the bitgroup "SlStopRec" of register "Statusreg0".
**
** During transfer received stop condition in slave mode
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlStopRec" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_4"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_4" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_4")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_SlStopRec( uint32_t value )
{
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
** \brief Reads the bitgroup "MsStopRec" of register "Statusreg0".
**
** Without transmission or as master received stop condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "MsStopRec" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_5"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_5" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_5")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_MsStopRec( uint32_t value )
{
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
** \brief Reads the bitgroup "RcNack" of register "Statusreg0".
**
** In master transmitter mode: receiver does not ackowledge data
** In slave transmitter mode: master gives no acknowledge on data
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RcNack" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_6"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_6" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_6")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_RcNack( uint32_t value )
{
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
** \brief Reads the bitgroup "SlNack" of register "Statusreg0".
**
** In master mode: Slave gives no acknowledge on address
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlNack" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_7"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_7" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_7")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_SlNack( uint32_t value )
{
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
** \brief Reads the bitgroup "SlAck" of register "Statusreg0".
**
** In master mode: Slave gives acknowledge on address
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAck" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_8"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_8" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_8")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_SlAck( uint32_t value )
{
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
** \brief Reads the bitgroup "DataTrmSl" of register "Statusreg0".
**
** In slave mode: data transmitted
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmSl" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_9"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_9" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_9")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_DataTrmSl( uint32_t value )
{
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
** \brief Reads the bitgroup "DataTrmMs" of register "Statusreg0".
**
** In master mode: data transmitted
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmMs" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_10"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_10" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_10")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_DataTrmMs( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "DataRecSl" of register "Statusreg0".
**
** In slave mode: data received
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecSl" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_11"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_11" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_11")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_DataRecSl( uint32_t value )
{
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
** \brief Reads the bitgroup "DataRecMs" of register "Statusreg0".
**
** In master mode: data received
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecMs" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_12"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_12" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_12")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_DataRecMs( uint32_t value )
{
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
** \brief Reads the bitgroup "AlStop" of register "Statusreg0".
**
** Arbitration lost during stop condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlStop" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_13"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_13" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_13")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_AlStop( uint32_t value )
{
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
** \brief Reads the bitgroup "AlData" of register "Statusreg0".
**
** Arbitration lost during data transfer
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlData" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_14"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_14" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_14")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_AlData( uint32_t value )
{
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
** \brief Reads the bitgroup "AlAdrsta" of register "Statusreg0".
**
** Arbitration lost during addressing or repeated start
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlAdrsta" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_15"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_15" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_15")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_AlAdrsta( uint32_t value )
{
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
** \brief Reads the bitgroup "BeStart" of register "Statusreg0".
**
** Bus error at start condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStart" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_16"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_16" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_16")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_BeStart( uint32_t value )
{
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
** \brief Reads the bitgroup "BeStop" of register "Statusreg0".
**
** Bus error at stop condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStop" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_17"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_17" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_17")))
#endif

uint32_t FREG_I2C_ExtractStatusreg0_BeStop( uint32_t value )
{
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
** \brief Reads the entire register "Statusreg1".
**
** This function reads the value from the index-th entry of the register
** array Statusreg1.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_18"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_18" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_18")))
#endif

uint32_t FREG_I2C_GetStatusreg1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_STATUSREG1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmOngo" of register "Statusreg1".
**
** Auto mode transfer ongoing,
** deleted when AM is finished or block is reset
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmOngo" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_19"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_19" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_19")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_AmOngo( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "AmEnd" of register "Statusreg1".
**
** Auto mode end, transfer is completed,
** flag deleted by reading I2C_StatusReg1
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmEnd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_20"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_20" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_20")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_AmEnd( uint32_t value )
{
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
** \brief Reads the bitgroup "AmErr" of register "Statusreg1".
**
** Auto mode error, set when auto mode was corrupted by any error, flag deleted by reading I2C_StatusReg1
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmErr" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_21"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_21" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_21")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_AmErr( uint32_t value )
{
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
** \brief Reads the bitgroup "AmMrxReq" of register "Statusreg1".
**
** In auto mode and master receiver operation, block requests that the host
** CPU collect a byte from I2C_RxDataReg,
** flag deleted by reading I2C_RxDataReg,
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMrxReq" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_22"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_22" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_22")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_AmMrxReq( uint32_t value )
{
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
** \brief Reads the bitgroup "AmMtxReq" of register "Statusreg1".
**
** In auto mode and master transmitter operation, block requests that the host CPU provide next byte to I2C_TxDataReg,
** In auto mode and master receiver operation with USE_ADD=0, block requests that host CPU shall provide the slave address of external slave device to I2C_RxDataReg,
** flag deleted by writing to I2C_RxDataReg
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMtxReq" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_23"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_23" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_23")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_AmMtxReq( uint32_t value )
{
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
** \brief Reads the bitgroup "Occup" of register "Statusreg1".
**
** Bus occupied, transmission ongoing, direct bit
** - '0': bus free
** - '1': bus occupied
** flag deleted when bus is free (SDA and SCL = 1)
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Occup" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_24"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_24" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_24")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_Occup( uint32_t value )
{
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
** \brief Reads the bitgroup "RdWr" of register "Statusreg1".
**
** Current mode:
** - '0': write mode
** - '1': read mode
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdWr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_25"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_25" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_25")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_RdWr( uint32_t value )
{
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
** \brief Reads the bitgroup "SlAdr" of register "Statusreg1".
**
** Module was addressed as slave,
** flag deleted by reading I2C_StatusReg1
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAdr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_26"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_26" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_26")))
#endif

uint32_t FREG_I2C_ExtractStatusreg1_SlAdr( uint32_t value )
{
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
** \brief Writes the entire register "Irqmask0".
**
** This function writes the given value to the index-th entry of the register
** array Irqmask0.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_27"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_27" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_27")))
#endif

void FREG_I2C_SetIrqmask0( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlRstart" of register "Irqmask0".
**
** Mask Bit for SL_RESTART
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlRstart" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_28"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_28" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_28")))
#endif

void FREG_I2C_SetIrqmask0_SlRstart( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "StopTrm" of register "Irqmask0".
**
** Mask Bit for STOP_TRM
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "StopTrm" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_29"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_29" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_29")))
#endif

void FREG_I2C_SetIrqmask0_StopTrm( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlStopRec" of register "Irqmask0".
**
** Mask Bit for SL_STOP_REC
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlStopRec" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_30"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_30" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_30")))
#endif

void FREG_I2C_SetIrqmask0_SlStopRec( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "MsStopRec" of register "Irqmask0".
**
** Mask Bit for MS_STOP_REC
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "MsStopRec" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_31"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_31" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_31")))
#endif

void FREG_I2C_SetIrqmask0_MsStopRec( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RcNack" of register "Irqmask0".
**
** Mask Bit for RC_NACK
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RcNack" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_32"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_32" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_32")))
#endif

void FREG_I2C_SetIrqmask0_RcNack( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlNack" of register "Irqmask0".
**
** Mask Bit for SL_NACK
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlNack" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_33"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_33" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_33")))
#endif

void FREG_I2C_SetIrqmask0_SlNack( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlAck" of register "Irqmask0".
**
** Mask Bit for SL_ACK
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlAck" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_34"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_34" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_34")))
#endif

void FREG_I2C_SetIrqmask0_SlAck( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataTrmSl" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_SL
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataTrmSl" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_35"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_35" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_35")))
#endif

void FREG_I2C_SetIrqmask0_DataTrmSl( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataTrmMs" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_MS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataTrmMs" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_36"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_36" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_36")))
#endif

void FREG_I2C_SetIrqmask0_DataTrmMs( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataRecSl" of register "Irqmask0".
**
** Mask Bit for DATA_REC_SL
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataRecSl" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_37"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_37" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_37")))
#endif

void FREG_I2C_SetIrqmask0_DataRecSl( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataRecMs" of register "Irqmask0".
**
** Mask Bit for DATA_REC_MS
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataRecMs" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_38"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_38" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_38")))
#endif

void FREG_I2C_SetIrqmask0_DataRecMs( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlStop" of register "Irqmask0".
**
** Mask Bit for AL_STOP
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlStop" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_39"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_39" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_39")))
#endif

void FREG_I2C_SetIrqmask0_AlStop( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlData" of register "Irqmask0".
**
** Mask Bit for AL_DATA
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlData" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_40"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_40" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_40")))
#endif

void FREG_I2C_SetIrqmask0_AlData( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlAdrsta" of register "Irqmask0".
**
** Mask Bit for AL_ADRSTA
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlAdrsta" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_41"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_41" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_41")))
#endif

void FREG_I2C_SetIrqmask0_AlAdrsta( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BeStart" of register "Irqmask0".
**
** Mask Bit for BE_START
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BeStart" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_42"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_42" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_42")))
#endif

void FREG_I2C_SetIrqmask0_BeStart( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BeStop" of register "Irqmask0".
**
** Mask Bit for BE_STOP
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BeStop" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_43"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_43" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_43")))
#endif

void FREG_I2C_SetIrqmask0_BeStop( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Irqmask0".
**
** This function reads the value from the index-th entry of the register
** array Irqmask0.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_44"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_44" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_44")))
#endif

uint32_t FREG_I2C_GetIrqmask0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SlRstart" of register "Irqmask0".
**
** Mask Bit for SL_RESTART
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlRstart" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_45"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_45" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_45")))
#endif

uint32_t FREG_I2C_GetIrqmask0_SlRstart( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x00008000UL ) >> 15;
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
** \brief Reads the bitgroup "StopTrm" of register "Irqmask0".
**
** Mask Bit for STOP_TRM
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "StopTrm" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_46"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_46" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_46")))
#endif

uint32_t FREG_I2C_GetIrqmask0_StopTrm( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SlStopRec" of register "Irqmask0".
**
** Mask Bit for SL_STOP_REC
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlStopRec" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_47"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_47" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_47")))
#endif

uint32_t FREG_I2C_GetIrqmask0_SlStopRec( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "MsStopRec" of register "Irqmask0".
**
** Mask Bit for MS_STOP_REC
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "MsStopRec" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_48"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_48" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_48")))
#endif

uint32_t FREG_I2C_GetIrqmask0_MsStopRec( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "RcNack" of register "Irqmask0".
**
** Mask Bit for RC_NACK
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RcNack" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_49"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_49" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_49")))
#endif

uint32_t FREG_I2C_GetIrqmask0_RcNack( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SlNack" of register "Irqmask0".
**
** Mask Bit for SL_NACK
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlNack" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_50"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_50" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_50")))
#endif

uint32_t FREG_I2C_GetIrqmask0_SlNack( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SlAck" of register "Irqmask0".
**
** Mask Bit for SL_ACK
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAck" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_51"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_51" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_51")))
#endif

uint32_t FREG_I2C_GetIrqmask0_SlAck( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "DataTrmSl" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_SL
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmSl" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_52"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_52" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_52")))
#endif

uint32_t FREG_I2C_GetIrqmask0_DataTrmSl( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "DataTrmMs" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_MS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmMs" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_53"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_53" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_53")))
#endif

uint32_t FREG_I2C_GetIrqmask0_DataTrmMs( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "DataRecSl" of register "Irqmask0".
**
** Mask Bit for DATA_REC_SL
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecSl" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_54"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_54" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_54")))
#endif

uint32_t FREG_I2C_GetIrqmask0_DataRecSl( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "DataRecMs" of register "Irqmask0".
**
** Mask Bit for DATA_REC_MS
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecMs" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_55"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_55" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_55")))
#endif

uint32_t FREG_I2C_GetIrqmask0_DataRecMs( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AlStop" of register "Irqmask0".
**
** Mask Bit for AL_STOP
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlStop" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_56"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_56" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_56")))
#endif

uint32_t FREG_I2C_GetIrqmask0_AlStop( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AlData" of register "Irqmask0".
**
** Mask Bit for AL_DATA
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlData" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_57"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_57" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_57")))
#endif

uint32_t FREG_I2C_GetIrqmask0_AlData( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AlAdrsta" of register "Irqmask0".
**
** Mask Bit for AL_ADRSTA
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlAdrsta" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_58"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_58" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_58")))
#endif

uint32_t FREG_I2C_GetIrqmask0_AlAdrsta( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "BeStart" of register "Irqmask0".
**
** Mask Bit for BE_START
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStart" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_59"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_59" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_59")))
#endif

uint32_t FREG_I2C_GetIrqmask0_BeStart( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "BeStop" of register "Irqmask0".
**
** Mask Bit for BE_STOP
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStop" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_60"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_60" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_60")))
#endif

uint32_t FREG_I2C_GetIrqmask0_BeStop( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
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
** \brief Writes the entire register "Irqmask1".
**
** This function writes the given value to the index-th entry of the register
** array Irqmask1.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_61"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_61" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_61")))
#endif

void FREG_I2C_SetIrqmask1( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmOngo" of register "Irqmask1".
**
** Mask Bit for AM_ONGO
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmOngo" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_62"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_62" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_62")))
#endif

void FREG_I2C_SetIrqmask1_AmOngo( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmEnd" of register "Irqmask1".
**
** Mask Bit for AM_END
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmEnd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_63"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_63" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_63")))
#endif

void FREG_I2C_SetIrqmask1_AmEnd( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmErr" of register "Irqmask1".
**
** Mask Bit for AM_ERR
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmErr" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_64"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_64" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_64")))
#endif

void FREG_I2C_SetIrqmask1_AmErr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmMrxReq" of register "Irqmask1".
**
** Mask Bit for AM_MRX_REQ
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmMrxReq" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_65"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_65" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_65")))
#endif

void FREG_I2C_SetIrqmask1_AmMrxReq( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmMtxReq" of register "Irqmask1".
**
** Mask Bit for AM_MTX_REQ
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmMtxReq" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_66"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_66" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_66")))
#endif

void FREG_I2C_SetIrqmask1_AmMtxReq( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Occup" of register "Irqmask1".
**
** Mask Bit for OCCUP
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Occup" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_67"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_67" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_67")))
#endif

void FREG_I2C_SetIrqmask1_Occup( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RdWr" of register "Irqmask1".
**
** Mask Bit for RD_WR
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RdWr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_68"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_68" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_68")))
#endif

void FREG_I2C_SetIrqmask1_RdWr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlAdr" of register "Irqmask1".
**
** Mask Bit for SL_ADR
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlAdr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_69"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_69" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_69")))
#endif

void FREG_I2C_SetIrqmask1_SlAdr( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Irqmask1".
**
** This function reads the value from the index-th entry of the register
** array Irqmask1.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_70"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_70" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_70")))
#endif

uint32_t FREG_I2C_GetIrqmask1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmOngo" of register "Irqmask1".
**
** Mask Bit for AM_ONGO
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmOngo" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_71"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_71" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_71")))
#endif

uint32_t FREG_I2C_GetIrqmask1_AmOngo( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "AmEnd" of register "Irqmask1".
**
** Mask Bit for AM_END
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmEnd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_72"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_72" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_72")))
#endif

uint32_t FREG_I2C_GetIrqmask1_AmEnd( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmErr" of register "Irqmask1".
**
** Mask Bit for AM_ERR
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmErr" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_73"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_73" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_73")))
#endif

uint32_t FREG_I2C_GetIrqmask1_AmErr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmMrxReq" of register "Irqmask1".
**
** Mask Bit for AM_MRX_REQ
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMrxReq" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_74"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_74" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_74")))
#endif

uint32_t FREG_I2C_GetIrqmask1_AmMrxReq( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmMtxReq" of register "Irqmask1".
**
** Mask Bit for AM_MTX_REQ
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMtxReq" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_75"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_75" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_75")))
#endif

uint32_t FREG_I2C_GetIrqmask1_AmMtxReq( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "Occup" of register "Irqmask1".
**
** Mask Bit for OCCUP
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Occup" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_76"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_76" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_76")))
#endif

uint32_t FREG_I2C_GetIrqmask1_Occup( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "RdWr" of register "Irqmask1".
**
** Mask Bit for RD_WR
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdWr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_77"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_77" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_77")))
#endif

uint32_t FREG_I2C_GetIrqmask1_RdWr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SlAdr" of register "Irqmask1".
**
** Mask Bit for SL_ADR
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAdr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_78"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_78" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_78")))
#endif

uint32_t FREG_I2C_GetIrqmask1_SlAdr( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
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
** \brief Writes the entire register "Controlreg0".
**
** This function writes the given value to the index-th entry of the register
** array Controlreg0.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_79"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_79" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_79")))
#endif

void FREG_I2C_SetControlreg0( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpikeFlt" of register "Controlreg0".
**
** Allows to switch on the spike filter for SCL line:
** - '0': Spike filter for SCL input off
** - '1': Spike filter for SCL input on (eliminates spikes of up
** to 55 ns)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpikeFlt" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_80"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_80" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_80")))
#endif

void FREG_I2C_SetControlreg0_SpikeFlt( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "OiDlyAl" of register "Controlreg0".
**
** Set to 1 when there is a large capacitive load on the SCL line.
** 
** - '0': Bus not released during spikes of longer than 55ns
** - '1': Bus released during spikes of more than 55ns (IýC
** block returns to IDLE state).
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "OiDlyAl" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_81"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_81" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_81")))
#endif

void FREG_I2C_SetControlreg0_OiDlyAl( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmMode" of register "Controlreg0".
**
** Specifies IýC Protocol, in auto mode only:
** - '00': master transmitter
** - '01': master receiver
** - '10': master transmitter/receiver
** - '11': not used
** Protocol:
** - '00': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck ----MaDataX - SlAck - STOP
** - '01': START - MaData0(SlaveAddrRd) - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck - STOP
** - '10': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck -- MaDataX - SlAck -ReSTART - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck -STOP
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmMode" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_82"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_82" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_82")))
#endif

void FREG_I2C_SetControlreg0_AmMode( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000300UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UseAdd" of register "Controlreg0".
**
** Control use of fixed slave address:
** - '0': IýC interface block will request first byte to be sent by
** setting AM_MTX_REQ
** - '1': IýC interface will automatically use MS_SLA_ADD in
** I2C_ControlReg1
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UseAdd" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_83"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_83" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_83")))
#endif

void FREG_I2C_SetControlreg0_UseAdd( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmOn" of register "Controlreg0".
**
** Switch on the auto mode:
** - '0': auto mode disabled
** - '1': auto mode enabled (recommended)
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmOn" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_84"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_84" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_84")))
#endif

void FREG_I2C_SetControlreg0_AmOn( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Reset" of register "Controlreg0".
**
** Synchronous reset of generic block at any time
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Reset" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_85"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_85" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_85")))
#endif

void FREG_I2C_SetControlreg0_Reset( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Start" of register "Controlreg0".
**
** Use in generic mode only: generate start condition
** must not be used in auto mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Start" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_86"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_86" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_86")))
#endif

void FREG_I2C_SetControlreg0_Start( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Stop" of register "Controlreg0".
**
** Use in generic mode only: generate stop condition
** must not be used in auto mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Stop" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_87"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_87" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_87")))
#endif

void FREG_I2C_SetControlreg0_Stop( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Nack" of register "Controlreg0".
**
** Use in generic mode only: in receiver mode no acknowledge is generated,
** must not be used in auto mode
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Nack" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_88"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_88" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_88")))
#endif

void FREG_I2C_SetControlreg0_Nack( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg0".
**
** This function reads the value from the index-th entry of the register
** array Controlreg0.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_89"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_89" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_89")))
#endif

uint32_t FREG_I2C_GetControlreg0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "SpikeFlt" of register "Controlreg0".
**
** Allows to switch on the spike filter for SCL line:
** - '0': Spike filter for SCL input off
** - '1': Spike filter for SCL input on (eliminates spikes of up
** to 55 ns)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpikeFlt" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_90"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_90" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_90")))
#endif

uint32_t FREG_I2C_GetControlreg0_SpikeFlt( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "OiDlyAl" of register "Controlreg0".
**
** Set to 1 when there is a large capacitive load on the SCL line.
** 
** - '0': Bus not released during spikes of longer than 55ns
** - '1': Bus released during spikes of more than 55ns (IýC
** block returns to IDLE state).
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "OiDlyAl" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_91"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_91" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_91")))
#endif

uint32_t FREG_I2C_GetControlreg0_OiDlyAl( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmMode" of register "Controlreg0".
**
** Specifies IýC Protocol, in auto mode only:
** - '00': master transmitter
** - '01': master receiver
** - '10': master transmitter/receiver
** - '11': not used
** Protocol:
** - '00': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck ----MaDataX - SlAck - STOP
** - '01': START - MaData0(SlaveAddrRd) - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck - STOP
** - '10': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck -- MaDataX - SlAck -ReSTART - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck -STOP
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMode" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_92"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_92" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_92")))
#endif

uint32_t FREG_I2C_GetControlreg0_AmMode( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x00000300UL ) >> 8;
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
** \brief Reads the bitgroup "UseAdd" of register "Controlreg0".
**
** Control use of fixed slave address:
** - '0': IýC interface block will request first byte to be sent by
** setting AM_MTX_REQ
** - '1': IýC interface will automatically use MS_SLA_ADD in
** I2C_ControlReg1
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "UseAdd" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_93"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_93" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_93")))
#endif

uint32_t FREG_I2C_GetControlreg0_UseAdd( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "AmOn" of register "Controlreg0".
**
** Switch on the auto mode:
** - '0': auto mode disabled
** - '1': auto mode enabled (recommended)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmOn" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_94"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_94" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_94")))
#endif

uint32_t FREG_I2C_GetControlreg0_AmOn( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "Reset" of register "Controlreg0".
**
** Synchronous reset of generic block at any time
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Reset" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_95"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_95" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_95")))
#endif

uint32_t FREG_I2C_GetControlreg0_Reset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "Start" of register "Controlreg0".
**
** Use in generic mode only: generate start condition
** must not be used in auto mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Start" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_96"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_96" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_96")))
#endif

uint32_t FREG_I2C_GetControlreg0_Start( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "Stop" of register "Controlreg0".
**
** Use in generic mode only: generate stop condition
** must not be used in auto mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Stop" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_97"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_97" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_97")))
#endif

uint32_t FREG_I2C_GetControlreg0_Stop( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "Nack" of register "Controlreg0".
**
** Use in generic mode only: in receiver mode no acknowledge is generated,
** must not be used in auto mode
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Nack" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_98"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_98" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_98")))
#endif

uint32_t FREG_I2C_GetControlreg0_Nack( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
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
** \brief Writes the entire register "Controlreg1".
**
** This function writes the given value to the index-th entry of the register
** array Controlreg1.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_99"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_99" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_99")))
#endif

void FREG_I2C_SetControlreg1( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "MsSlaAdd" of register "Controlreg1".
**
** In auto mode and master transmitter/receiver operation: slave address (7:1) of external slave to be addressed, WR/RD bit is set automatically
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "MsSlaAdd" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_100"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_100" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_100")))
#endif

void FREG_I2C_SetControlreg1_MsSlaAdd( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlSlaAdd" of register "Controlreg1".
**
** In generic mode and slave receiver/transmitter operation: set own slave address
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlSlaAdd" consists of the bits 7..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x000000FEUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_101"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_101" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_101")))
#endif

void FREG_I2C_SetControlreg1_SlSlaAdd( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FEUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2cSpeed" of register "Controlreg1".
**
** Speed of SCL clock in all modes:
** - '0': 100KHz
** - '1': 400KHz
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2cSpeed" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_102"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_102" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_102")))
#endif

void FREG_I2C_SetControlreg1_I2cSpeed( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg1".
**
** This function reads the value from the index-th entry of the register
** array Controlreg1.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_103"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_103" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_103")))
#endif

uint32_t FREG_I2C_GetControlreg1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "MsSlaAdd" of register "Controlreg1".
**
** In auto mode and master transmitter/receiver operation: slave address (7:1) of external slave to be addressed, WR/RD bit is set automatically
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "MsSlaAdd" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_104"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_104" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_104")))
#endif

uint32_t FREG_I2C_GetControlreg1_MsSlaAdd( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x00007F00UL ) >> 8;
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
** \brief Reads the bitgroup "SlSlaAdd" of register "Controlreg1".
**
** In generic mode and slave receiver/transmitter operation: set own slave address
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlSlaAdd" consists of the bits 7..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x000000FEUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_105"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_105" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_105")))
#endif

uint32_t FREG_I2C_GetControlreg1_SlSlaAdd( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x000000FEUL ) >> 1;
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
** \brief Reads the bitgroup "I2cSpeed" of register "Controlreg1".
**
** Speed of SCL clock in all modes:
** - '0': 100KHz
** - '1': 400KHz
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2cSpeed" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_106"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_106" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_106")))
#endif

uint32_t FREG_I2C_GetControlreg1_I2cSpeed( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET)));
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
** \brief Writes the entire register "Controlreg2".
**
** This function writes the given value to the index-th entry of the register
** array Controlreg2.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_107"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_107" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_107")))
#endif

void FREG_I2C_SetControlreg2( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmTxNum" of register "Controlreg2".
**
** In auto mode and master transmitter operation: number of bytes to be transmitted including MS_SLA_ADD, this setting is independent of USE_ADD.
**  In case of master transmitter/receiver mode, the second slave address with READ bit must also be included.
** Example: Start - SlaveAddressWR - SlaveSubAddress - Restart - SlaveAddressRD - Data..... here AM_TX_NUM must be set to 3.
** Even for master receiver mode, a 1 must be programmed.
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmTxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_108"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_108" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_108")))
#endif

void FREG_I2C_SetControlreg2_AmTxNum( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg2".
**
** This function reads the value from the index-th entry of the register
** array Controlreg2.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_109"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_109" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_109")))
#endif

uint32_t FREG_I2C_GetControlreg2( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmTxNum" of register "Controlreg2".
**
** In auto mode and master transmitter operation: number of bytes to be transmitted including MS_SLA_ADD, this setting is independent of USE_ADD.
**  In case of master transmitter/receiver mode, the second slave address with READ bit must also be included.
** Example: Start - SlaveAddressWR - SlaveSubAddress - Restart - SlaveAddressRD - Data..... here AM_TX_NUM must be set to 3.
** Even for master receiver mode, a 1 must be programmed.
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmTxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_110"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_110" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_110")))
#endif

uint32_t FREG_I2C_GetControlreg2_AmTxNum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Writes the entire register "Controlreg3".
**
** This function writes the given value to the index-th entry of the register
** array Controlreg3.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_111"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_111" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_111")))
#endif

void FREG_I2C_SetControlreg3( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmRxNum" of register "Controlreg3".
**
** In auto mode and master receiver operation: number of bytes to be received
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmRxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_112"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_112" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_112")))
#endif

void FREG_I2C_SetControlreg3_AmRxNum( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg3".
**
** This function reads the value from the index-th entry of the register
** array Controlreg3.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_113"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_113" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_113")))
#endif

uint32_t FREG_I2C_GetControlreg3( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmRxNum" of register "Controlreg3".
**
** In auto mode and master receiver operation: number of bytes to be received
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmRxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_114"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_114" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_114")))
#endif

uint32_t FREG_I2C_GetControlreg3_AmRxNum( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Writes the entire register "Goreg".
**
** This function writes the given value to the index-th entry of the register
** array Goreg.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_115"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_115" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_115")))
#endif

void FREG_I2C_SetGoreg( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmStart" of register "Goreg".
**
** Writing to this bit starts the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmStart" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_116"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_116" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_116")))
#endif

void FREG_I2C_SetGoreg_AmStart( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmReset" of register "Goreg".
**
** Writing to this bit resets the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmReset" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_117"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_117" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_117")))
#endif

void FREG_I2C_SetGoreg_AmReset( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2cGo" of register "Goreg".
**
** In generic mode only: writing to this register start the generic IýC block,
** must not be used in auto mode
** it is automatically reset to 0
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2cGo" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_118"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_118" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_118")))
#endif

void FREG_I2C_SetGoreg_I2cGo( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Goreg".
**
** This function reads the value from the index-th entry of the register
** array Goreg.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_119"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_119" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_119")))
#endif

uint32_t FREG_I2C_GetGoreg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmStart" of register "Goreg".
**
** Writing to this bit starts the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmStart" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_120"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_120" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_120")))
#endif

uint32_t FREG_I2C_GetGoreg_AmStart( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmReset" of register "Goreg".
**
** Writing to this bit resets the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmReset" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_121"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_121" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_121")))
#endif

uint32_t FREG_I2C_GetGoreg_AmReset( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "I2cGo" of register "Goreg".
**
** In generic mode only: writing to this register start the generic IýC block,
** must not be used in auto mode
** it is automatically reset to 0
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2cGo" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_122"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_122" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_122")))
#endif

uint32_t FREG_I2C_GetGoreg_I2cGo( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Writes the entire register "Txdatareg".
**
** This function writes the given value to the index-th entry of the register
** array Txdatareg.
**
** \param index Array index to access.
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_123"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_123" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_123")))
#endif

void FREG_I2C_SetTxdatareg( uint32_t index, uint32_t value )
{
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TxDataReg" of register "Txdatareg".
**
** Data to be sent, data must be provided to this register after the AM_MTX_REQ was set
**
** \param index Array index to access.
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TxDataReg" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_124"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_124" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_124")))
#endif

void FREG_I2C_SetTxdatareg_TxDataReg( uint32_t index, uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return;
    #endif
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET))) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET), value );
    #endif
    *((volatile uint32_t*)(FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET))) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Txdatareg".
**
** This function reads the value from the index-th entry of the register
** array Txdatareg.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_125"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_125" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_125")))
#endif

uint32_t FREG_I2C_GetTxdatareg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "TxDataReg" of register "Txdatareg".
**
** Data to be sent, data must be provided to this register after the AM_MTX_REQ was set
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "TxDataReg" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_126"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_126" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_126")))
#endif

uint32_t FREG_I2C_GetTxdatareg_TxDataReg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the entire register "Rxdatareg".
**
** This function reads the value from the index-th entry of the register
** array Rxdatareg.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_127"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_127" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_127")))
#endif

uint32_t FREG_I2C_GetRxdatareg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_RXDATAREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "RxDataReg" of register "Rxdatareg".
**
** Data, which were received, must be collected from the register after the AM_RXT_REQ was set
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RxDataReg" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_128"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_128" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_128")))
#endif

uint32_t FREG_I2C_GetRxdatareg_RxDataReg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_RXDATAREG+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the entire register "Txcntpoi".
**
** This function reads the value from the index-th entry of the register
** array Txcntpoi.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_129"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_129" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_129")))
#endif

uint32_t FREG_I2C_GetTxcntpoi( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_TXCNTPOI+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmTxPoi" of register "Txcntpoi".
**
** In auto mode: value of the internal down counter, decremented by providing new byte via host CPU
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmTxPoi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_130"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_130" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_130")))
#endif

uint32_t FREG_I2C_GetTxcntpoi_AmTxPoi( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_TXCNTPOI+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Reads the entire register "Rxcntpoi".
**
** This function reads the value from the index-th entry of the register
** array Rxcntpoi.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_131"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_131" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_131")))
#endif

uint32_t FREG_I2C_GetRxcntpoi( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_RXCNTPOI+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "AmRxPoi" of register "Rxcntpoi".
**
** In auto mode: value of the internal down counter, decremented after acknowledgement was received from master receiver
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmRxPoi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_132"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_132" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_132")))
#endif

uint32_t FREG_I2C_GetRxcntpoi_AmRxPoi( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_RXCNTPOI+(index*FREG_I2C_MOFFSET)));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Reads the entire register "Statusreg0".
**
** This function reads the value from the register "Statusreg0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_133"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_133" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_133")))
#endif

uint32_t FREG_I2C2_GetStatusreg0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_STATUSREG0));
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
** \brief Extracts the bitgroup "SlRstart" of register "Statusreg0".
**
** Slave recognised, repeated start condition in slave mode,
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlRstart" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_134"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_134" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_134")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_SlRstart( uint32_t value )
{
    value = ( value & 0x00008000UL ) >> 15;
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
** \brief Extracts the bitgroup "StopTrm" of register "Statusreg0".
**
** Stop condition was sent in master mode
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "StopTrm" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_135"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_135" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_135")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_StopTrm( uint32_t value )
{
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
** \brief Extracts the bitgroup "SlStopRec" of register "Statusreg0".
**
** During transfer received stop condition in slave mode
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlStopRec" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_136"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_136" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_136")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_SlStopRec( uint32_t value )
{
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
** \brief Extracts the bitgroup "MsStopRec" of register "Statusreg0".
**
** Without transmission or as master received stop condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "MsStopRec" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_137"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_137" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_137")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_MsStopRec( uint32_t value )
{
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
** \brief Extracts the bitgroup "RcNack" of register "Statusreg0".
**
** In master transmitter mode: receiver does not ackowledge data
** In slave transmitter mode: master gives no acknowledge on data
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RcNack" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_138"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_138" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_138")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_RcNack( uint32_t value )
{
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
** \brief Extracts the bitgroup "SlNack" of register "Statusreg0".
**
** In master mode: Slave gives no acknowledge on address
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlNack" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_139"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_139" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_139")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_SlNack( uint32_t value )
{
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
** \brief Extracts the bitgroup "SlAck" of register "Statusreg0".
**
** In master mode: Slave gives acknowledge on address
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAck" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_140"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_140" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_140")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_SlAck( uint32_t value )
{
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
** \brief Extracts the bitgroup "DataTrmSl" of register "Statusreg0".
**
** In slave mode: data transmitted
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmSl" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_141"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_141" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_141")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_DataTrmSl( uint32_t value )
{
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
** \brief Extracts the bitgroup "DataTrmMs" of register "Statusreg0".
**
** In master mode: data transmitted
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmMs" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_142"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_142" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_142")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_DataTrmMs( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Extracts the bitgroup "DataRecSl" of register "Statusreg0".
**
** In slave mode: data received
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecSl" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_143"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_143" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_143")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_DataRecSl( uint32_t value )
{
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
** \brief Extracts the bitgroup "DataRecMs" of register "Statusreg0".
**
** In master mode: data received
** flag deleted by reading I2C_StatusReg0
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecMs" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_144"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_144" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_144")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_DataRecMs( uint32_t value )
{
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
** \brief Extracts the bitgroup "AlStop" of register "Statusreg0".
**
** Arbitration lost during stop condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlStop" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_145"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_145" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_145")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_AlStop( uint32_t value )
{
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
** \brief Extracts the bitgroup "AlData" of register "Statusreg0".
**
** Arbitration lost during data transfer
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlData" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_146"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_146" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_146")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_AlData( uint32_t value )
{
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
** \brief Extracts the bitgroup "AlAdrsta" of register "Statusreg0".
**
** Arbitration lost during addressing or repeated start
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlAdrsta" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_147"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_147" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_147")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_AlAdrsta( uint32_t value )
{
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
** \brief Extracts the bitgroup "BeStart" of register "Statusreg0".
**
** Bus error at start condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStart" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_148"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_148" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_148")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_BeStart( uint32_t value )
{
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
** \brief Extracts the bitgroup "BeStop" of register "Statusreg0".
**
** Bus error at stop condition
** flag deleted by reading I2C_StatusReg0
** this flag is source for AM_ERR
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStop" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_149"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_149" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_149")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg0_BeStop( uint32_t value )
{
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
** \brief Reads the entire register "Statusreg1".
**
** This function reads the value from the register "Statusreg1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_150"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_150" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_150")))
#endif

uint32_t FREG_I2C2_GetStatusreg1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_STATUSREG1));
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
** \brief Extracts the bitgroup "AmOngo" of register "Statusreg1".
**
** Auto mode transfer ongoing,
** deleted when AM is finished or block is reset
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmOngo" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_151"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_151" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_151")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_AmOngo( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Extracts the bitgroup "AmEnd" of register "Statusreg1".
**
** Auto mode end, transfer is completed,
** flag deleted by reading I2C_StatusReg1
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmEnd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_152"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_152" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_152")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_AmEnd( uint32_t value )
{
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
** \brief Extracts the bitgroup "AmErr" of register "Statusreg1".
**
** Auto mode error, set when auto mode was corrupted by any error, flag deleted by reading I2C_StatusReg1
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmErr" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_153"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_153" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_153")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_AmErr( uint32_t value )
{
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
** \brief Extracts the bitgroup "AmMrxReq" of register "Statusreg1".
**
** In auto mode and master receiver operation, block requests that the host
** CPU collect a byte from I2C_RxDataReg,
** flag deleted by reading I2C_RxDataReg,
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMrxReq" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_154"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_154" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_154")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_AmMrxReq( uint32_t value )
{
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
** \brief Extracts the bitgroup "AmMtxReq" of register "Statusreg1".
**
** In auto mode and master transmitter operation, block requests that the host CPU provide next byte to I2C_TxDataReg,
** In auto mode and master receiver operation with USE_ADD=0, block requests that host CPU shall provide the slave address of external slave device to I2C_RxDataReg,
** flag deleted by writing to I2C_RxDataReg
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMtxReq" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_155"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_155" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_155")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_AmMtxReq( uint32_t value )
{
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
** \brief Extracts the bitgroup "Occup" of register "Statusreg1".
**
** Bus occupied, transmission ongoing, direct bit
** - '0': bus free
** - '1': bus occupied
** flag deleted when bus is free (SDA and SCL = 1)
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "Occup" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_156"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_156" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_156")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_Occup( uint32_t value )
{
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
** \brief Extracts the bitgroup "RdWr" of register "Statusreg1".
**
** Current mode:
** - '0': write mode
** - '1': read mode
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdWr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_157"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_157" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_157")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_RdWr( uint32_t value )
{
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
** \brief Extracts the bitgroup "SlAdr" of register "Statusreg1".
**
** Module was addressed as slave,
** flag deleted by reading I2C_StatusReg1
**
** \param value Register value to extract bitgroup from.
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAdr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_158"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_158" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_158")))
#endif

uint32_t FREG_I2C2_ExtractStatusreg1_SlAdr( uint32_t value )
{
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
** \brief Writes the entire register "Irqmask0".
**
** This function writes the given value to the register "Irqmask0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_159"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_159" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_159")))
#endif

void FREG_I2C2_SetIrqmask0( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlRstart" of register "Irqmask0".
**
** Mask Bit for SL_RESTART
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlRstart" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_160"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_160" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_160")))
#endif

void FREG_I2C2_SetIrqmask0_SlRstart( uint32_t value )
{
    register uint32_t mask = 0x00008000UL;
    value = ( value << 15 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "StopTrm" of register "Irqmask0".
**
** Mask Bit for STOP_TRM
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "StopTrm" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_161"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_161" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_161")))
#endif

void FREG_I2C2_SetIrqmask0_StopTrm( uint32_t value )
{
    register uint32_t mask = 0x00004000UL;
    value = ( value << 14 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlStopRec" of register "Irqmask0".
**
** Mask Bit for SL_STOP_REC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlStopRec" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_162"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_162" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_162")))
#endif

void FREG_I2C2_SetIrqmask0_SlStopRec( uint32_t value )
{
    register uint32_t mask = 0x00002000UL;
    value = ( value << 13 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "MsStopRec" of register "Irqmask0".
**
** Mask Bit for MS_STOP_REC
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "MsStopRec" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_163"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_163" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_163")))
#endif

void FREG_I2C2_SetIrqmask0_MsStopRec( uint32_t value )
{
    register uint32_t mask = 0x00001000UL;
    value = ( value << 12 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RcNack" of register "Irqmask0".
**
** Mask Bit for RC_NACK
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RcNack" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_164"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_164" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_164")))
#endif

void FREG_I2C2_SetIrqmask0_RcNack( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlNack" of register "Irqmask0".
**
** Mask Bit for SL_NACK
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlNack" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_165"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_165" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_165")))
#endif

void FREG_I2C2_SetIrqmask0_SlNack( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlAck" of register "Irqmask0".
**
** Mask Bit for SL_ACK
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlAck" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_166"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_166" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_166")))
#endif

void FREG_I2C2_SetIrqmask0_SlAck( uint32_t value )
{
    register uint32_t mask = 0x00000200UL;
    value = ( value << 9 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataTrmSl" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_SL
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataTrmSl" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_167"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_167" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_167")))
#endif

void FREG_I2C2_SetIrqmask0_DataTrmSl( uint32_t value )
{
    register uint32_t mask = 0x00000100UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataTrmMs" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_MS
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataTrmMs" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_168"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_168" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_168")))
#endif

void FREG_I2C2_SetIrqmask0_DataTrmMs( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataRecSl" of register "Irqmask0".
**
** Mask Bit for DATA_REC_SL
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataRecSl" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_169"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_169" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_169")))
#endif

void FREG_I2C2_SetIrqmask0_DataRecSl( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "DataRecMs" of register "Irqmask0".
**
** Mask Bit for DATA_REC_MS
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "DataRecMs" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_170"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_170" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_170")))
#endif

void FREG_I2C2_SetIrqmask0_DataRecMs( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlStop" of register "Irqmask0".
**
** Mask Bit for AL_STOP
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlStop" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_171"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_171" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_171")))
#endif

void FREG_I2C2_SetIrqmask0_AlStop( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlData" of register "Irqmask0".
**
** Mask Bit for AL_DATA
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlData" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_172"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_172" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_172")))
#endif

void FREG_I2C2_SetIrqmask0_AlData( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AlAdrsta" of register "Irqmask0".
**
** Mask Bit for AL_ADRSTA
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AlAdrsta" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_173"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_173" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_173")))
#endif

void FREG_I2C2_SetIrqmask0_AlAdrsta( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BeStart" of register "Irqmask0".
**
** Mask Bit for BE_START
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BeStart" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_174"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_174" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_174")))
#endif

void FREG_I2C2_SetIrqmask0_BeStart( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "BeStop" of register "Irqmask0".
**
** Mask Bit for BE_STOP
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "BeStop" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_175"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_175" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_175")))
#endif

void FREG_I2C2_SetIrqmask0_BeStop( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 16
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Irqmask0".
**
** This function reads the value from the register "Irqmask0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_176"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_176" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_176")))
#endif

uint32_t FREG_I2C2_GetIrqmask0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "SlRstart" of register "Irqmask0".
**
** Mask Bit for SL_RESTART
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlRstart" consists of the bits 15..15,
**       the given bitgroup value will be shifted left by 15 bits and
**       masked using the bitmask 0x00008000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_177"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_177" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_177")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_SlRstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00008000UL ) >> 15;
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
** \brief Reads the bitgroup "StopTrm" of register "Irqmask0".
**
** Mask Bit for STOP_TRM
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "StopTrm" consists of the bits 14..14,
**       the given bitgroup value will be shifted left by 14 bits and
**       masked using the bitmask 0x00004000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_178"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_178" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_178")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_StopTrm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "SlStopRec" of register "Irqmask0".
**
** Mask Bit for SL_STOP_REC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlStopRec" consists of the bits 13..13,
**       the given bitgroup value will be shifted left by 13 bits and
**       masked using the bitmask 0x00002000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_179"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_179" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_179")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_SlStopRec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "MsStopRec" of register "Irqmask0".
**
** Mask Bit for MS_STOP_REC
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "MsStopRec" consists of the bits 12..12,
**       the given bitgroup value will be shifted left by 12 bits and
**       masked using the bitmask 0x00001000UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_180"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_180" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_180")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_MsStopRec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "RcNack" of register "Irqmask0".
**
** Mask Bit for RC_NACK
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RcNack" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_181"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_181" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_181")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_RcNack( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "SlNack" of register "Irqmask0".
**
** Mask Bit for SL_NACK
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlNack" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_182"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_182" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_182")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_SlNack( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "SlAck" of register "Irqmask0".
**
** Mask Bit for SL_ACK
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAck" consists of the bits 9..9,
**       the given bitgroup value will be shifted left by 9 bits and
**       masked using the bitmask 0x00000200UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_183"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_183" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_183")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_SlAck( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "DataTrmSl" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_SL
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmSl" consists of the bits 8..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000100UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_184"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_184" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_184")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_DataTrmSl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "DataTrmMs" of register "Irqmask0".
**
** Mask Bit for DATA_TRM_MS
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataTrmMs" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_185"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_185" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_185")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_DataTrmMs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "DataRecSl" of register "Irqmask0".
**
** Mask Bit for DATA_REC_SL
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecSl" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_186"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_186" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_186")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_DataRecSl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "DataRecMs" of register "Irqmask0".
**
** Mask Bit for DATA_REC_MS
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "DataRecMs" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_187"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_187" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_187")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_DataRecMs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "AlStop" of register "Irqmask0".
**
** Mask Bit for AL_STOP
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlStop" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_188"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_188" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_188")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_AlStop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "AlData" of register "Irqmask0".
**
** Mask Bit for AL_DATA
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlData" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_189"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_189" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_189")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_AlData( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "AlAdrsta" of register "Irqmask0".
**
** Mask Bit for AL_ADRSTA
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AlAdrsta" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_190"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_190" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_190")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_AlAdrsta( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "BeStart" of register "Irqmask0".
**
** Mask Bit for BE_START
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStart" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_191"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_191" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_191")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_BeStart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Reads the bitgroup "BeStop" of register "Irqmask0".
**
** Mask Bit for BE_STOP
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "BeStop" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_192"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_192" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_192")))
#endif

uint32_t FREG_I2C2_GetIrqmask0_BeStop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
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
** \brief Writes the entire register "Irqmask1".
**
** This function writes the given value to the register "Irqmask1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_193"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_193" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_193")))
#endif

void FREG_I2C2_SetIrqmask1( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmOngo" of register "Irqmask1".
**
** Mask Bit for AM_ONGO
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmOngo" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_194"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_194" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_194")))
#endif

void FREG_I2C2_SetIrqmask1_AmOngo( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmEnd" of register "Irqmask1".
**
** Mask Bit for AM_END
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmEnd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_195"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_195" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_195")))
#endif

void FREG_I2C2_SetIrqmask1_AmEnd( uint32_t value )
{
    register uint32_t mask = 0x00000040UL;
    value = ( value << 6 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmErr" of register "Irqmask1".
**
** Mask Bit for AM_ERR
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmErr" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_196"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_196" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_196")))
#endif

void FREG_I2C2_SetIrqmask1_AmErr( uint32_t value )
{
    register uint32_t mask = 0x00000020UL;
    value = ( value << 5 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmMrxReq" of register "Irqmask1".
**
** Mask Bit for AM_MRX_REQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmMrxReq" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_197"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_197" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_197")))
#endif

void FREG_I2C2_SetIrqmask1_AmMrxReq( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmMtxReq" of register "Irqmask1".
**
** Mask Bit for AM_MTX_REQ
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmMtxReq" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_198"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_198" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_198")))
#endif

void FREG_I2C2_SetIrqmask1_AmMtxReq( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Occup" of register "Irqmask1".
**
** Mask Bit for OCCUP
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Occup" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_199"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_199" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_199")))
#endif

void FREG_I2C2_SetIrqmask1_Occup( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "RdWr" of register "Irqmask1".
**
** Mask Bit for RD_WR
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "RdWr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_200"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_200" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_200")))
#endif

void FREG_I2C2_SetIrqmask1_RdWr( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlAdr" of register "Irqmask1".
**
** Mask Bit for SL_ADR
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlAdr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_201"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_201" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_201")))
#endif

void FREG_I2C2_SetIrqmask1_SlAdr( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 8
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Irqmask1".
**
** This function reads the value from the register "Irqmask1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_202"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_202" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_202")))
#endif

uint32_t FREG_I2C2_GetIrqmask1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "AmOngo" of register "Irqmask1".
**
** Mask Bit for AM_ONGO
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmOngo" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_203"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_203" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_203")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_AmOngo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "AmEnd" of register "Irqmask1".
**
** Mask Bit for AM_END
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmEnd" consists of the bits 6..6,
**       the given bitgroup value will be shifted left by 6 bits and
**       masked using the bitmask 0x00000040UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_204"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_204" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_204")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_AmEnd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "AmErr" of register "Irqmask1".
**
** Mask Bit for AM_ERR
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmErr" consists of the bits 5..5,
**       the given bitgroup value will be shifted left by 5 bits and
**       masked using the bitmask 0x00000020UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_205"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_205" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_205")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_AmErr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "AmMrxReq" of register "Irqmask1".
**
** Mask Bit for AM_MRX_REQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMrxReq" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_206"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_206" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_206")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_AmMrxReq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "AmMtxReq" of register "Irqmask1".
**
** Mask Bit for AM_MTX_REQ
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMtxReq" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_207"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_207" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_207")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_AmMtxReq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "Occup" of register "Irqmask1".
**
** Mask Bit for OCCUP
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Occup" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_208"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_208" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_208")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_Occup( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "RdWr" of register "Irqmask1".
**
** Mask Bit for RD_WR
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RdWr" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_209"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_209" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_209")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_RdWr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Reads the bitgroup "SlAdr" of register "Irqmask1".
**
** Mask Bit for SL_ADR
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlAdr" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_210"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_210" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_210")))
#endif

uint32_t FREG_I2C2_GetIrqmask1_SlAdr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
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
** \brief Writes the entire register "Controlreg0".
**
** This function writes the given value to the register "Controlreg0".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_211"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_211" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_211")))
#endif

void FREG_I2C2_SetControlreg0( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SpikeFlt" of register "Controlreg0".
**
** Allows to switch on the spike filter for SCL line:
** - '0': Spike filter for SCL input off
** - '1': Spike filter for SCL input on (eliminates spikes of up
** to 55 ns)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SpikeFlt" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_212"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_212" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_212")))
#endif

void FREG_I2C2_SetControlreg0_SpikeFlt( uint32_t value )
{
    register uint32_t mask = 0x00000800UL;
    value = ( value << 11 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "OiDlyAl" of register "Controlreg0".
**
** Set to 1 when there is a large capacitive load on the SCL line.
** 
** - '0': Bus not released during spikes of longer than 55ns
** - '1': Bus released during spikes of more than 55ns (IýC
** block returns to IDLE state).
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "OiDlyAl" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_213"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_213" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_213")))
#endif

void FREG_I2C2_SetControlreg0_OiDlyAl( uint32_t value )
{
    register uint32_t mask = 0x00000400UL;
    value = ( value << 10 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmMode" of register "Controlreg0".
**
** Specifies IýC Protocol, in auto mode only:
** - '00': master transmitter
** - '01': master receiver
** - '10': master transmitter/receiver
** - '11': not used
** Protocol:
** - '00': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck ----MaDataX - SlAck - STOP
** - '01': START - MaData0(SlaveAddrRd) - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck - STOP
** - '10': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck -- MaDataX - SlAck -ReSTART - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck -STOP
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmMode" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_214"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_214" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_214")))
#endif

void FREG_I2C2_SetControlreg0_AmMode( uint32_t value )
{
    register uint32_t mask = 0x00000300UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "UseAdd" of register "Controlreg0".
**
** Control use of fixed slave address:
** - '0': IýC interface block will request first byte to be sent by
** setting AM_MTX_REQ
** - '1': IýC interface will automatically use MS_SLA_ADD in
** I2C_ControlReg1
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "UseAdd" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_215"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_215" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_215")))
#endif

void FREG_I2C2_SetControlreg0_UseAdd( uint32_t value )
{
    register uint32_t mask = 0x00000080UL;
    value = ( value << 7 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmOn" of register "Controlreg0".
**
** Switch on the auto mode:
** - '0': auto mode disabled
** - '1': auto mode enabled (recommended)
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmOn" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_216"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_216" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_216")))
#endif

void FREG_I2C2_SetControlreg0_AmOn( uint32_t value )
{
    register uint32_t mask = 0x00000010UL;
    value = ( value << 4 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Reset" of register "Controlreg0".
**
** Synchronous reset of generic block at any time
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Reset" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_217"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_217" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_217")))
#endif

void FREG_I2C2_SetControlreg0_Reset( uint32_t value )
{
    register uint32_t mask = 0x00000008UL;
    value = ( value << 3 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Start" of register "Controlreg0".
**
** Use in generic mode only: generate start condition
** must not be used in auto mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Start" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_218"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_218" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_218")))
#endif

void FREG_I2C2_SetControlreg0_Start( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Stop" of register "Controlreg0".
**
** Use in generic mode only: generate stop condition
** must not be used in auto mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Stop" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_219"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_219" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_219")))
#endif

void FREG_I2C2_SetControlreg0_Stop( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "Nack" of register "Controlreg0".
**
** Use in generic mode only: in receiver mode no acknowledge is generated,
** must not be used in auto mode
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "Nack" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_220"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_220" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_220")))
#endif

void FREG_I2C2_SetControlreg0_Nack( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 9
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg0".
**
** This function reads the value from the register "Controlreg0".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_221"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_221" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_221")))
#endif

uint32_t FREG_I2C2_GetControlreg0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "SpikeFlt" of register "Controlreg0".
**
** Allows to switch on the spike filter for SCL line:
** - '0': Spike filter for SCL input off
** - '1': Spike filter for SCL input on (eliminates spikes of up
** to 55 ns)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SpikeFlt" consists of the bits 11..11,
**       the given bitgroup value will be shifted left by 11 bits and
**       masked using the bitmask 0x00000800UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_222"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_222" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_222")))
#endif

uint32_t FREG_I2C2_GetControlreg0_SpikeFlt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "OiDlyAl" of register "Controlreg0".
**
** Set to 1 when there is a large capacitive load on the SCL line.
** 
** - '0': Bus not released during spikes of longer than 55ns
** - '1': Bus released during spikes of more than 55ns (IýC
** block returns to IDLE state).
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "OiDlyAl" consists of the bits 10..10,
**       the given bitgroup value will be shifted left by 10 bits and
**       masked using the bitmask 0x00000400UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_223"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_223" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_223")))
#endif

uint32_t FREG_I2C2_GetControlreg0_OiDlyAl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "AmMode" of register "Controlreg0".
**
** Specifies IýC Protocol, in auto mode only:
** - '00': master transmitter
** - '01': master receiver
** - '10': master transmitter/receiver
** - '11': not used
** Protocol:
** - '00': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck ----MaDataX - SlAck - STOP
** - '01': START - MaData0(SlaveAddrRd) - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck - STOP
** - '10': START - MaData0(SlaveAddrWr) - SlAck - MaData1 - SlAck -- MaDataX - SlAck -ReSTART - SlAck - SlData0 - MaAck -- SlDataX - NoMaAck -STOP
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmMode" consists of the bits 9..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00000300UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_224"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_224" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_224")))
#endif

uint32_t FREG_I2C2_GetControlreg0_AmMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000300UL ) >> 8;
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
** \brief Reads the bitgroup "UseAdd" of register "Controlreg0".
**
** Control use of fixed slave address:
** - '0': IýC interface block will request first byte to be sent by
** setting AM_MTX_REQ
** - '1': IýC interface will automatically use MS_SLA_ADD in
** I2C_ControlReg1
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "UseAdd" consists of the bits 7..7,
**       the given bitgroup value will be shifted left by 7 bits and
**       masked using the bitmask 0x00000080UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_225"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_225" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_225")))
#endif

uint32_t FREG_I2C2_GetControlreg0_UseAdd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000080UL ) >> 7;
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
** \brief Reads the bitgroup "AmOn" of register "Controlreg0".
**
** Switch on the auto mode:
** - '0': auto mode disabled
** - '1': auto mode enabled (recommended)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmOn" consists of the bits 4..4,
**       the given bitgroup value will be shifted left by 4 bits and
**       masked using the bitmask 0x00000010UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_226"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_226" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_226")))
#endif

uint32_t FREG_I2C2_GetControlreg0_AmOn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "Reset" of register "Controlreg0".
**
** Synchronous reset of generic block at any time
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Reset" consists of the bits 3..3,
**       the given bitgroup value will be shifted left by 3 bits and
**       masked using the bitmask 0x00000008UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_227"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_227" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_227")))
#endif

uint32_t FREG_I2C2_GetControlreg0_Reset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "Start" of register "Controlreg0".
**
** Use in generic mode only: generate start condition
** must not be used in auto mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Start" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_228"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_228" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_228")))
#endif

uint32_t FREG_I2C2_GetControlreg0_Start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "Stop" of register "Controlreg0".
**
** Use in generic mode only: generate stop condition
** must not be used in auto mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Stop" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_229"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_229" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_229")))
#endif

uint32_t FREG_I2C2_GetControlreg0_Stop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Reads the bitgroup "Nack" of register "Controlreg0".
**
** Use in generic mode only: in receiver mode no acknowledge is generated,
** must not be used in auto mode
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "Nack" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_230"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_230" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_230")))
#endif

uint32_t FREG_I2C2_GetControlreg0_Nack( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
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
** \brief Writes the entire register "Controlreg1".
**
** This function writes the given value to the register "Controlreg1".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_231"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_231" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_231")))
#endif

void FREG_I2C2_SetControlreg1( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "MsSlaAdd" of register "Controlreg1".
**
** In auto mode and master transmitter/receiver operation: slave address (7:1) of external slave to be addressed, WR/RD bit is set automatically
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "MsSlaAdd" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_232"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_232" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_232")))
#endif

void FREG_I2C2_SetControlreg1_MsSlaAdd( uint32_t value )
{
    register uint32_t mask = 0x00007F00UL;
    value = ( value << 8 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "SlSlaAdd" of register "Controlreg1".
**
** In generic mode and slave receiver/transmitter operation: set own slave address
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "SlSlaAdd" consists of the bits 7..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x000000FEUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_233"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_233" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_233")))
#endif

void FREG_I2C2_SetControlreg1_SlSlaAdd( uint32_t value )
{
    register uint32_t mask = 0x000000FEUL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2cSpeed" of register "Controlreg1".
**
** Speed of SCL clock in all modes:
** - '0': 100KHz
** - '1': 400KHz
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2cSpeed" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_234"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_234" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_234")))
#endif

void FREG_I2C2_SetControlreg1_I2cSpeed( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg1".
**
** This function reads the value from the register "Controlreg1".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_235"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_235" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_235")))
#endif

uint32_t FREG_I2C2_GetControlreg1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
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
** \brief Reads the bitgroup "MsSlaAdd" of register "Controlreg1".
**
** In auto mode and master transmitter/receiver operation: slave address (7:1) of external slave to be addressed, WR/RD bit is set automatically
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "MsSlaAdd" consists of the bits 14..8,
**       the given bitgroup value will be shifted left by 8 bits and
**       masked using the bitmask 0x00007F00UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_236"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_236" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_236")))
#endif

uint32_t FREG_I2C2_GetControlreg1_MsSlaAdd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
    value = ( value & 0x00007F00UL ) >> 8;
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
** \brief Reads the bitgroup "SlSlaAdd" of register "Controlreg1".
**
** In generic mode and slave receiver/transmitter operation: set own slave address
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "SlSlaAdd" consists of the bits 7..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x000000FEUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_237"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_237" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_237")))
#endif

uint32_t FREG_I2C2_GetControlreg1_SlSlaAdd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
    value = ( value & 0x000000FEUL ) >> 1;
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
** \brief Reads the bitgroup "I2cSpeed" of register "Controlreg1".
**
** Speed of SCL clock in all modes:
** - '0': 100KHz
** - '1': 400KHz
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2cSpeed" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_238"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_238" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_238")))
#endif

uint32_t FREG_I2C2_GetControlreg1_I2cSpeed( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
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
** \brief Writes the entire register "Controlreg2".
**
** This function writes the given value to the register "Controlreg2".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_239"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_239" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_239")))
#endif

void FREG_I2C2_SetControlreg2( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG2, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmTxNum" of register "Controlreg2".
**
** In auto mode and master transmitter operation: number of bytes to be transmitted including MS_SLA_ADD, this setting is independent of USE_ADD.
**  In case of master transmitter/receiver mode, the second slave address with READ bit must also be included.
** Example: Start - SlaveAddressWR - SlaveSubAddress - Restart - SlaveAddressRD - Data..... here AM_TX_NUM must be set to 3.
** Even for master receiver mode, a 1 must be programmed.
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmTxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_240"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_240" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_240")))
#endif

void FREG_I2C2_SetControlreg2_AmTxNum( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG2, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg2".
**
** This function reads the value from the register "Controlreg2".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_241"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_241" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_241")))
#endif

uint32_t FREG_I2C2_GetControlreg2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2));
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
** \brief Reads the bitgroup "AmTxNum" of register "Controlreg2".
**
** In auto mode and master transmitter operation: number of bytes to be transmitted including MS_SLA_ADD, this setting is independent of USE_ADD.
**  In case of master transmitter/receiver mode, the second slave address with READ bit must also be included.
** Example: Start - SlaveAddressWR - SlaveSubAddress - Restart - SlaveAddressRD - Data..... here AM_TX_NUM must be set to 3.
** Even for master receiver mode, a 1 must be programmed.
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmTxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_242"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_242" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_242")))
#endif

uint32_t FREG_I2C2_GetControlreg2_AmTxNum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Writes the entire register "Controlreg3".
**
** This function writes the given value to the register "Controlreg3".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_243"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_243" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_243")))
#endif

void FREG_I2C2_SetControlreg3( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG3, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmRxNum" of register "Controlreg3".
**
** In auto mode and master receiver operation: number of bytes to be received
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmRxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_244"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_244" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_244")))
#endif

void FREG_I2C2_SetControlreg3_AmRxNum( uint32_t value )
{
    register uint32_t mask = 0x0000FFFFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG3, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Controlreg3".
**
** This function reads the value from the register "Controlreg3".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_245"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_245" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_245")))
#endif

uint32_t FREG_I2C2_GetControlreg3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3));
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
** \brief Reads the bitgroup "AmRxNum" of register "Controlreg3".
**
** In auto mode and master receiver operation: number of bytes to be received
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmRxNum" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_246"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_246" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_246")))
#endif

uint32_t FREG_I2C2_GetControlreg3_AmRxNum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Writes the entire register "Goreg".
**
** This function writes the given value to the register "Goreg".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_247"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_247" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_247")))
#endif

void FREG_I2C2_SetGoreg( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_GOREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_GOREG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmStart" of register "Goreg".
**
** Writing to this bit starts the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmStart" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_248"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_248" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_248")))
#endif

void FREG_I2C2_SetGoreg_AmStart( uint32_t value )
{
    register uint32_t mask = 0x00000004UL;
    value = ( value << 2 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_GOREG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_GOREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_GOREG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "AmReset" of register "Goreg".
**
** Writing to this bit resets the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "AmReset" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_249"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_249" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_249")))
#endif

void FREG_I2C2_SetGoreg_AmReset( uint32_t value )
{
    register uint32_t mask = 0x00000002UL;
    value = ( value << 1 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_GOREG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_GOREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_GOREG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "I2cGo" of register "Goreg".
**
** In generic mode only: writing to this register start the generic IýC block,
** must not be used in auto mode
** it is automatically reset to 0
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "I2cGo" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_250"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_250" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_250")))
#endif

void FREG_I2C2_SetGoreg_I2cGo( uint32_t value )
{
    register uint32_t mask = 0x00000001UL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 3
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_GOREG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_GOREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_GOREG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Goreg".
**
** This function reads the value from the register "Goreg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_251"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_251" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_251")))
#endif

uint32_t FREG_I2C2_GetGoreg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
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
** \brief Reads the bitgroup "AmStart" of register "Goreg".
**
** Writing to this bit starts the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmStart" consists of the bits 2..2,
**       the given bitgroup value will be shifted left by 2 bits and
**       masked using the bitmask 0x00000004UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_252"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_252" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_252")))
#endif

uint32_t FREG_I2C2_GetGoreg_AmStart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
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
** \brief Reads the bitgroup "AmReset" of register "Goreg".
**
** Writing to this bit resets the auto mode state machine, it is automatically reset to 0 from the auto mode controller
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmReset" consists of the bits 1..1,
**       the given bitgroup value will be shifted left by 1 bits and
**       masked using the bitmask 0x00000002UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_253"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_253" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_253")))
#endif

uint32_t FREG_I2C2_GetGoreg_AmReset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
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
** \brief Reads the bitgroup "I2cGo" of register "Goreg".
**
** In generic mode only: writing to this register start the generic IýC block,
** must not be used in auto mode
** it is automatically reset to 0
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "I2cGo" consists of the bits 0..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x00000001UL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_254"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_254" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_254")))
#endif

uint32_t FREG_I2C2_GetGoreg_I2cGo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
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
** \brief Writes the entire register "Txdatareg".
**
** This function writes the given value to the register "Txdatareg".
**
** 
**
** \param value Register value to write.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_255"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_255" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_255")))
#endif

void FREG_I2C2_SetTxdatareg( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_TXDATAREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_TXDATAREG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Writes the bitgroup "TxDataReg" of register "Txdatareg".
**
** Data to be sent, data must be provided to this register after the AM_MTX_REQ was set
**
** \param value Bitgroup value to write.
**
** \note internally the bitgroup "TxDataReg" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_256"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_256" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_256")))
#endif

void FREG_I2C2_SetTxdatareg_TxDataReg( uint32_t value )
{
    register uint32_t mask = 0x000000FFUL;
    value = ( value << 0 ) & mask;
    #define REGISTER_BITGROUP_COUNT 1
    #if REGISTER_BITGROUP_COUNT > 1
        value |= ( *((volatile uint32_t*)(FREG_I2C2_TXDATAREG)) & ~mask );
    #endif
    #undef REGISTER_BITGROUP_COUNT
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_TXDATAREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_TXDATAREG)) = value;
}

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code
#endif

#if defined(_ARC)
#pragma Code()
#endif

#endif

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Txdatareg".
**
** This function reads the value from the register "Txdatareg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_257"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_257" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_257")))
#endif

uint32_t FREG_I2C2_GetTxdatareg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXDATAREG));
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
** \brief Reads the bitgroup "TxDataReg" of register "Txdatareg".
**
** Data to be sent, data must be provided to this register after the AM_MTX_REQ was set
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "TxDataReg" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_258"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_258" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_258")))
#endif

uint32_t FREG_I2C2_GetTxdatareg_TxDataReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXDATAREG));
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
** \brief Reads the entire register "Rxdatareg".
**
** This function reads the value from the register "Rxdatareg".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_259"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_259" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_259")))
#endif

uint32_t FREG_I2C2_GetRxdatareg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXDATAREG));
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
** \brief Reads the bitgroup "RxDataReg" of register "Rxdatareg".
**
** Data, which were received, must be collected from the register after the AM_RXT_REQ was set
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "RxDataReg" consists of the bits 7..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000000FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_260"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_260" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_260")))
#endif

uint32_t FREG_I2C2_GetRxdatareg_RxDataReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXDATAREG));
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
** \brief Reads the entire register "Txcntpoi".
**
** This function reads the value from the register "Txcntpoi".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_261"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_261" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_261")))
#endif

uint32_t FREG_I2C2_GetTxcntpoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXCNTPOI));
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
** \brief Reads the bitgroup "AmTxPoi" of register "Txcntpoi".
**
** In auto mode: value of the internal down counter, decremented by providing new byte via host CPU
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmTxPoi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_262"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_262" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_262")))
#endif

uint32_t FREG_I2C2_GetTxcntpoi_AmTxPoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXCNTPOI));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Reads the entire register "Rxcntpoi".
**
** This function reads the value from the register "Rxcntpoi".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_263"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_263" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_263")))
#endif

uint32_t FREG_I2C2_GetRxcntpoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXCNTPOI));
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
** \brief Reads the bitgroup "AmRxPoi" of register "Rxcntpoi".
**
** In auto mode: value of the internal down counter, decremented after acknowledgement was received from master receiver
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "AmRxPoi" consists of the bits 15..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x0000FFFFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_264"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_264" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_264")))
#endif

uint32_t FREG_I2C2_GetRxcntpoi_AmRxPoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXCNTPOI));
    value = ( value & 0x0000FFFFUL ) >> 0;
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
** \brief Reads the entire register "Clkdivider".
**
** This function reads the value from the index-th entry of the register
** array Clkdivider.
**
** 
**
** \param index Array index to access.
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_265"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_265" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_265")))
#endif

uint32_t FREG_I2C_GetClkdivider( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CLKDIVIDER+(index*FREG_I2C_MOFFSET)));
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
** \brief Reads the bitgroup "ClkDivider" of register "Clkdivider".
**
** Sets Clockdivider for IýC serial clock in normal mode.
**  SCL output should be 100kHz according to:
** SCL = Module clock / (2 * Clk_Divider)
**
** \param index Array index to access.
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClkDivider" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_266"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_266" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_266")))
#endif

uint32_t FREG_I2C_GetClkdivider_ClkDivider( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CLKDIVIDER+(index*FREG_I2C_MOFFSET)));
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

#if !defined(FREG_USE_INLINE)
/*!
********************************************************************************
**
** \brief Reads the entire register "Clkdivider".
**
** This function reads the value from the register "Clkdivider".
**
** 
**
** \return Read register value.
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_267"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_267" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_267")))
#endif

uint32_t FREG_I2C2_GetClkdivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CLKDIVIDER));
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
** \brief Reads the bitgroup "ClkDivider" of register "Clkdivider".
**
** Sets Clockdivider for IýC serial clock in normal mode.
**  SCL output should be 100kHz according to:
** SCL = Module clock / (2 * Clk_Divider)
**
** \return Read bitgroup value.
**
** \note internally the bitgroup "ClkDivider" consists of the bits 9..0,
**       the given bitgroup value will be shifted left by 0 bits and
**       masked using the bitmask 0x000003FFUL
**
********************************************************************************
*/

#if defined(__arm__) && !defined(__GNUC__)
#pragma arm section code = ".text$$FREG_I2C_268"
#endif

#if defined(_ARC)
#pragma Code( ".text$$FREG_I2C_268" )
#endif

#if defined(__GNUC__)
__attribute__((section(".text$$FREG_I2C_268")))
#endif

uint32_t FREG_I2C2_GetClkdivider_ClkDivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CLKDIVIDER));
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
** \brief Initializes the "I2C" block.
**
** Initializes all required registers and mirror variables.
**
********************************************************************************
*/
void FREG_I2C_Init( void )
{
}
