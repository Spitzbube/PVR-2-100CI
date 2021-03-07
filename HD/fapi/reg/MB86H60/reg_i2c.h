/*!
********************************************************************************
**
** \file      ./fapi/reg/src/MB86H60/reg_i2c.h
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
#if !defined(FREG_I2C_H)
#define FREG_I2C_H

#include <stdint.h>
#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#define FREG_I2C_ENABLE_DEBUG_PRINT   0
#define FREG_I2C_DEBUG_PRINT_FUNCTION printf

#if FREG_I2C_ENABLE_DEBUG_PRINT == 1
#include <stdio.h>
#endif

/*
********************************************************************************
**
** Register definitions
**
********************************************************************************
*/
#define FREG_I2C_STATUSREG0                      FIO_ADDRESS(I2C,0xC4000000UL)
#define FREG_I2C_STATUSREG1                      FIO_ADDRESS(I2C,0xC4000004UL)
#define FREG_I2C_IRQMASK0                        FIO_ADDRESS(I2C,0xC4000008UL)
#define FREG_I2C_IRQMASK1                        FIO_ADDRESS(I2C,0xC400000CUL)
#define FREG_I2C_CONTROLREG0                     FIO_ADDRESS(I2C,0xC4000010UL)
#define FREG_I2C_CONTROLREG1                     FIO_ADDRESS(I2C,0xC4000014UL)
#define FREG_I2C_CONTROLREG2                     FIO_ADDRESS(I2C,0xC4000018UL)
#define FREG_I2C_CONTROLREG3                     FIO_ADDRESS(I2C,0xC400001CUL)
#define FREG_I2C_GOREG                           FIO_ADDRESS(I2C,0xC4000024UL)
#define FREG_I2C_TXDATAREG                       FIO_ADDRESS(I2C,0xC4000020UL)
#define FREG_I2C_RXDATAREG                       FIO_ADDRESS(I2C,0xC4000028UL)
#define FREG_I2C_TXCNTPOI                        FIO_ADDRESS(I2C,0xC400002CUL)
#define FREG_I2C_RXCNTPOI                        FIO_ADDRESS(I2C,0xC4000030UL)
#define FREG_I2C2_STATUSREG0                     FIO_ADDRESS(I2C2,0xD3000000UL)
#define FREG_I2C2_STATUSREG1                     FIO_ADDRESS(I2C2,0xD3000004UL)
#define FREG_I2C2_IRQMASK0                       FIO_ADDRESS(I2C2,0xD3000008UL)
#define FREG_I2C2_IRQMASK1                       FIO_ADDRESS(I2C2,0xD300000CUL)
#define FREG_I2C2_CONTROLREG0                    FIO_ADDRESS(I2C2,0xD3000010UL)
#define FREG_I2C2_CONTROLREG1                    FIO_ADDRESS(I2C2,0xD3000014UL)
#define FREG_I2C2_CONTROLREG2                    FIO_ADDRESS(I2C2,0xD3000018UL)
#define FREG_I2C2_CONTROLREG3                    FIO_ADDRESS(I2C2,0xD300001CUL)
#define FREG_I2C2_GOREG                          FIO_ADDRESS(I2C2,0xD3000024UL)
#define FREG_I2C2_TXDATAREG                      FIO_ADDRESS(I2C2,0xD3000020UL)
#define FREG_I2C2_RXDATAREG                      FIO_ADDRESS(I2C2,0xD3000028UL)
#define FREG_I2C2_TXCNTPOI                       FIO_ADDRESS(I2C2,0xD300002CUL)
#define FREG_I2C2_RXCNTPOI                       FIO_ADDRESS(I2C2,0xD3000030UL)
#define FREG_I2C_CLKDIVIDER                      FIO_ADDRESS(I2C,0xC4000034UL)
#define FREG_I2C2_CLKDIVIDER                     FIO_ADDRESS(I2C2,0xD3000034UL)
#define FREG_I2C_MOFFSET                         FIO_MOFFSET(I2C,0x0E000000UL)

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
extern uint32_t FREG_I2C_GetStatusreg0( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetStatusreg0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_STATUSREG0+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_SlRstart( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_SlRstart( uint32_t value )
{
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_StopTrm( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_StopTrm( uint32_t value )
{
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_SlStopRec( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_SlStopRec( uint32_t value )
{
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_MsStopRec( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_MsStopRec( uint32_t value )
{
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_RcNack( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_RcNack( uint32_t value )
{
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_SlNack( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_SlNack( uint32_t value )
{
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_SlAck( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_SlAck( uint32_t value )
{
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_DataTrmSl( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_DataTrmSl( uint32_t value )
{
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_DataTrmMs( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_DataTrmMs( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_DataRecSl( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_DataRecSl( uint32_t value )
{
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_DataRecMs( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_DataRecMs( uint32_t value )
{
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_AlStop( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_AlStop( uint32_t value )
{
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_AlData( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_AlData( uint32_t value )
{
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_AlAdrsta( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_AlAdrsta( uint32_t value )
{
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_BeStart( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_BeStart( uint32_t value )
{
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg0_BeStop( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg0_BeStop( uint32_t value )
{
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_I2C_GetStatusreg1( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetStatusreg1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_STATUSREG1+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_AmOngo( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_AmOngo( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_AmEnd( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_AmEnd( uint32_t value )
{
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_AmErr( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_AmErr( uint32_t value )
{
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_AmMrxReq( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_AmMrxReq( uint32_t value )
{
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_AmMtxReq( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_AmMtxReq( uint32_t value )
{
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_Occup( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_Occup( uint32_t value )
{
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_RdWr( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_RdWr( uint32_t value )
{
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C_ExtractStatusreg1_SlAdr( uint32_t value );
#else
INLINE uint32_t FREG_I2C_ExtractStatusreg1_SlAdr( uint32_t value )
{
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C_SetIrqmask0( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_SlRstart( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_SlRstart( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_StopTrm( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_StopTrm( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_SlStopRec( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_SlStopRec( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_MsStopRec( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_MsStopRec( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_RcNack( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_RcNack( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_SlNack( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_SlNack( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_SlAck( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_SlAck( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_DataTrmSl( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_DataTrmSl( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_DataTrmMs( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_DataTrmMs( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_DataRecSl( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_DataRecSl( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_DataRecMs( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_DataRecMs( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_AlStop( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_AlStop( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_AlData( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_AlData( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_AlAdrsta( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_AlAdrsta( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_BeStart( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_BeStart( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask0_BeStop( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask0_BeStop( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetIrqmask0( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK0+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetIrqmask0_SlRstart( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_SlRstart( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_StopTrm( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_StopTrm( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_SlStopRec( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_SlStopRec( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_MsStopRec( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_MsStopRec( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_RcNack( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_RcNack( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_SlNack( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_SlNack( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_SlAck( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_SlAck( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_DataTrmSl( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_DataTrmSl( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_DataTrmMs( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_DataTrmMs( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_DataRecSl( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_DataRecSl( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_DataRecMs( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_DataRecMs( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_AlStop( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_AlStop( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_AlData( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_AlData( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_AlAdrsta( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_AlAdrsta( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_BeStart( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_BeStart( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask0_BeStop( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask0_BeStop( uint32_t index )
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
extern void FREG_I2C_SetIrqmask1( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_AmOngo( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_AmOngo( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_AmEnd( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_AmEnd( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_AmErr( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_AmErr( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_AmMrxReq( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_AmMrxReq( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_AmMtxReq( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_AmMtxReq( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_Occup( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_Occup( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_RdWr( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_RdWr( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetIrqmask1_SlAdr( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetIrqmask1_SlAdr( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetIrqmask1( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_IRQMASK1+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetIrqmask1_AmOngo( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_AmOngo( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_AmEnd( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_AmEnd( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_AmErr( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_AmErr( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_AmMrxReq( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_AmMrxReq( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_AmMtxReq( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_AmMtxReq( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_Occup( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_Occup( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_RdWr( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_RdWr( uint32_t index )
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
extern uint32_t FREG_I2C_GetIrqmask1_SlAdr( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetIrqmask1_SlAdr( uint32_t index )
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
extern void FREG_I2C_SetControlreg0( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_SpikeFlt( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_SpikeFlt( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_OiDlyAl( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_OiDlyAl( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_AmMode( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_AmMode( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_UseAdd( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_UseAdd( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_AmOn( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_AmOn( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_Reset( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_Reset( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_Start( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_Start( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_Stop( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_Stop( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg0_Nack( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg0_Nack( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetControlreg0( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG0+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetControlreg0_SpikeFlt( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_SpikeFlt( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_OiDlyAl( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_OiDlyAl( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_AmMode( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_AmMode( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_UseAdd( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_UseAdd( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_AmOn( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_AmOn( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_Reset( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_Reset( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_Start( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_Start( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_Stop( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_Stop( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg0_Nack( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg0_Nack( uint32_t index )
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
extern void FREG_I2C_SetControlreg1( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg1( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg1_MsSlaAdd( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg1_MsSlaAdd( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg1_SlSlaAdd( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg1_SlSlaAdd( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg1_I2cSpeed( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg1_I2cSpeed( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetControlreg1( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg1( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG1+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetControlreg1_MsSlaAdd( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg1_MsSlaAdd( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg1_SlSlaAdd( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg1_SlSlaAdd( uint32_t index )
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
extern uint32_t FREG_I2C_GetControlreg1_I2cSpeed( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg1_I2cSpeed( uint32_t index )
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
extern void FREG_I2C_SetControlreg2( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg2( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg2_AmTxNum( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg2_AmTxNum( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetControlreg2( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg2( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG2+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetControlreg2_AmTxNum( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg2_AmTxNum( uint32_t index )
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
extern void FREG_I2C_SetControlreg3( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg3( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetControlreg3_AmRxNum( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetControlreg3_AmRxNum( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetControlreg3( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg3( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CONTROLREG3+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetControlreg3_AmRxNum( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetControlreg3_AmRxNum( uint32_t index )
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
extern void FREG_I2C_SetGoreg( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetGoreg( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetGoreg_AmStart( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetGoreg_AmStart( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetGoreg_AmReset( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetGoreg_AmReset( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetGoreg_I2cGo( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetGoreg_I2cGo( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetGoreg( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetGoreg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_GOREG+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetGoreg_AmStart( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetGoreg_AmStart( uint32_t index )
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
extern uint32_t FREG_I2C_GetGoreg_AmReset( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetGoreg_AmReset( uint32_t index )
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
extern uint32_t FREG_I2C_GetGoreg_I2cGo( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetGoreg_I2cGo( uint32_t index )
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
extern void FREG_I2C_SetTxdatareg( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetTxdatareg( uint32_t index, uint32_t value )
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
extern void FREG_I2C_SetTxdatareg_TxDataReg( uint32_t index, uint32_t value );
#else
INLINE void FREG_I2C_SetTxdatareg_TxDataReg( uint32_t index, uint32_t value )
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
extern uint32_t FREG_I2C_GetTxdatareg( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetTxdatareg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_TXDATAREG+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetTxdatareg_TxDataReg( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetTxdatareg_TxDataReg( uint32_t index )
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
extern uint32_t FREG_I2C_GetRxdatareg( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetRxdatareg( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_RXDATAREG+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetRxdatareg_RxDataReg( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetRxdatareg_RxDataReg( uint32_t index )
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
extern uint32_t FREG_I2C_GetTxcntpoi( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetTxcntpoi( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_TXCNTPOI+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetTxcntpoi_AmTxPoi( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetTxcntpoi_AmTxPoi( uint32_t index )
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
extern uint32_t FREG_I2C_GetRxcntpoi( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetRxcntpoi( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_RXCNTPOI+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetRxcntpoi_AmRxPoi( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetRxcntpoi_AmRxPoi( uint32_t index )
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
extern uint32_t FREG_I2C2_GetStatusreg0( void );
#else
INLINE uint32_t FREG_I2C2_GetStatusreg0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_STATUSREG0));
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_SlRstart( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_SlRstart( uint32_t value )
{
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_StopTrm( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_StopTrm( uint32_t value )
{
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_SlStopRec( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_SlStopRec( uint32_t value )
{
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_MsStopRec( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_MsStopRec( uint32_t value )
{
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_RcNack( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_RcNack( uint32_t value )
{
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_SlNack( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_SlNack( uint32_t value )
{
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_SlAck( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_SlAck( uint32_t value )
{
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_DataTrmSl( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_DataTrmSl( uint32_t value )
{
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_DataTrmMs( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_DataTrmMs( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_DataRecSl( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_DataRecSl( uint32_t value )
{
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_DataRecMs( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_DataRecMs( uint32_t value )
{
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_AlStop( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_AlStop( uint32_t value )
{
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_AlData( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_AlData( uint32_t value )
{
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_AlAdrsta( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_AlAdrsta( uint32_t value )
{
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_BeStart( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_BeStart( uint32_t value )
{
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg0_BeStop( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg0_BeStop( uint32_t value )
{
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetStatusreg1( void );
#else
INLINE uint32_t FREG_I2C2_GetStatusreg1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_STATUSREG1));
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_AmOngo( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_AmOngo( uint32_t value )
{
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_AmEnd( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_AmEnd( uint32_t value )
{
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_AmErr( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_AmErr( uint32_t value )
{
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_AmMrxReq( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_AmMrxReq( uint32_t value )
{
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_AmMtxReq( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_AmMtxReq( uint32_t value )
{
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_Occup( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_Occup( uint32_t value )
{
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_RdWr( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_RdWr( uint32_t value )
{
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_ExtractStatusreg1_SlAdr( uint32_t value );
#else
INLINE uint32_t FREG_I2C2_ExtractStatusreg1_SlAdr( uint32_t value )
{
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetIrqmask0( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK0)) = value;
}
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
extern void FREG_I2C2_SetIrqmask0_SlRstart( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_SlRstart( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_StopTrm( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_StopTrm( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_SlStopRec( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_SlStopRec( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_MsStopRec( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_MsStopRec( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_RcNack( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_RcNack( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_SlNack( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_SlNack( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_SlAck( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_SlAck( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_DataTrmSl( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_DataTrmSl( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_DataTrmMs( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_DataTrmMs( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_DataRecSl( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_DataRecSl( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_DataRecMs( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_DataRecMs( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_AlStop( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_AlStop( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_AlData( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_AlData( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_AlAdrsta( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_AlAdrsta( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_BeStart( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_BeStart( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask0_BeStop( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask0_BeStop( uint32_t value )
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
extern uint32_t FREG_I2C2_GetIrqmask0( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_SlRstart( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_SlRstart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00008000UL ) >> 15;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_StopTrm( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_StopTrm( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00004000UL ) >> 14;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_SlStopRec( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_SlStopRec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00002000UL ) >> 13;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_MsStopRec( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_MsStopRec( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00001000UL ) >> 12;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_RcNack( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_RcNack( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_SlNack( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_SlNack( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_SlAck( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_SlAck( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000200UL ) >> 9;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_DataTrmSl( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_DataTrmSl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000100UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_DataTrmMs( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_DataTrmMs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_DataRecSl( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_DataRecSl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_DataRecMs( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_DataRecMs( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_AlStop( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_AlStop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_AlData( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_AlData( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_AlAdrsta( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_AlAdrsta( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_BeStart( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_BeStart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask0_BeStop( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask0_BeStop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK0));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetIrqmask1( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_IRQMASK1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_IRQMASK1)) = value;
}
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
extern void FREG_I2C2_SetIrqmask1_AmOngo( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_AmOngo( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_AmEnd( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_AmEnd( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_AmErr( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_AmErr( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_AmMrxReq( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_AmMrxReq( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_AmMtxReq( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_AmMtxReq( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_Occup( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_Occup( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_RdWr( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_RdWr( uint32_t value )
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
extern void FREG_I2C2_SetIrqmask1_SlAdr( uint32_t value );
#else
INLINE void FREG_I2C2_SetIrqmask1_SlAdr( uint32_t value )
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
extern uint32_t FREG_I2C2_GetIrqmask1( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_AmOngo( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_AmOngo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_AmEnd( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_AmEnd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000040UL ) >> 6;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_AmErr( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_AmErr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000020UL ) >> 5;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_AmMrxReq( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_AmMrxReq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_AmMtxReq( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_AmMtxReq( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_Occup( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_Occup( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_RdWr( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_RdWr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetIrqmask1_SlAdr( void );
#else
INLINE uint32_t FREG_I2C2_GetIrqmask1_SlAdr( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_IRQMASK1));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetControlreg0( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG0, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0)) = value;
}
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
extern void FREG_I2C2_SetControlreg0_SpikeFlt( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_SpikeFlt( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_OiDlyAl( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_OiDlyAl( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_AmMode( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_AmMode( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_UseAdd( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_UseAdd( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_AmOn( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_AmOn( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_Reset( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_Reset( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_Start( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_Start( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_Stop( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_Stop( uint32_t value )
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
extern void FREG_I2C2_SetControlreg0_Nack( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg0_Nack( uint32_t value )
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
extern uint32_t FREG_I2C2_GetControlreg0( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_SpikeFlt( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_SpikeFlt( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000800UL ) >> 11;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_OiDlyAl( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_OiDlyAl( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000400UL ) >> 10;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_AmMode( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_AmMode( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000300UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_UseAdd( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_UseAdd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000080UL ) >> 7;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_AmOn( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_AmOn( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000010UL ) >> 4;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_Reset( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_Reset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000008UL ) >> 3;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_Start( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_Start( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_Stop( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_Stop( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg0_Nack( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg0_Nack( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG0));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetControlreg1( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg1( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG1, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1)) = value;
}
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
extern void FREG_I2C2_SetControlreg1_MsSlaAdd( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg1_MsSlaAdd( uint32_t value )
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
extern void FREG_I2C2_SetControlreg1_SlSlaAdd( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg1_SlSlaAdd( uint32_t value )
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
extern void FREG_I2C2_SetControlreg1_I2cSpeed( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg1_I2cSpeed( uint32_t value )
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
extern uint32_t FREG_I2C2_GetControlreg1( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg1( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg1_MsSlaAdd( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg1_MsSlaAdd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
    value = ( value & 0x00007F00UL ) >> 8;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg1_SlSlaAdd( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg1_SlSlaAdd( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
    value = ( value & 0x000000FEUL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg1_I2cSpeed( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg1_I2cSpeed( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG1));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetControlreg2( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg2( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG2, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2)) = value;
}
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
extern void FREG_I2C2_SetControlreg2_AmTxNum( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg2_AmTxNum( uint32_t value )
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
extern uint32_t FREG_I2C2_GetControlreg2( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg2( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg2_AmTxNum( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg2_AmTxNum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG2));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetControlreg3( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg3( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_CONTROLREG3, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3)) = value;
}
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
extern void FREG_I2C2_SetControlreg3_AmRxNum( uint32_t value );
#else
INLINE void FREG_I2C2_SetControlreg3_AmRxNum( uint32_t value )
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
extern uint32_t FREG_I2C2_GetControlreg3( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg3( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetControlreg3_AmRxNum( void );
#else
INLINE uint32_t FREG_I2C2_GetControlreg3_AmRxNum( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CONTROLREG3));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetGoreg( uint32_t value );
#else
INLINE void FREG_I2C2_SetGoreg( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_GOREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_GOREG)) = value;
}
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
extern void FREG_I2C2_SetGoreg_AmStart( uint32_t value );
#else
INLINE void FREG_I2C2_SetGoreg_AmStart( uint32_t value )
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
extern void FREG_I2C2_SetGoreg_AmReset( uint32_t value );
#else
INLINE void FREG_I2C2_SetGoreg_AmReset( uint32_t value )
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
extern void FREG_I2C2_SetGoreg_I2cGo( uint32_t value );
#else
INLINE void FREG_I2C2_SetGoreg_I2cGo( uint32_t value )
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
extern uint32_t FREG_I2C2_GetGoreg( void );
#else
INLINE uint32_t FREG_I2C2_GetGoreg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetGoreg_AmStart( void );
#else
INLINE uint32_t FREG_I2C2_GetGoreg_AmStart( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
    value = ( value & 0x00000004UL ) >> 2;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetGoreg_AmReset( void );
#else
INLINE uint32_t FREG_I2C2_GetGoreg_AmReset( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
    value = ( value & 0x00000002UL ) >> 1;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetGoreg_I2cGo( void );
#else
INLINE uint32_t FREG_I2C2_GetGoreg_I2cGo( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_GOREG));
    value = ( value & 0x00000001UL ) >> 0;
    return( value );
}
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
extern void FREG_I2C2_SetTxdatareg( uint32_t value );
#else
INLINE void FREG_I2C2_SetTxdatareg( uint32_t value )
{
    #if FREG_I2C_ENABLE_DEBUG_PRINT == 1
        FREG_I2C_DEBUG_PRINT_FUNCTION( "[%s] 0x%08x <- 0x%08x\n", "FREG_I2C", FREG_I2C2_TXDATAREG, value );
    #endif
    *((volatile uint32_t*)(FREG_I2C2_TXDATAREG)) = value;
}
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
extern void FREG_I2C2_SetTxdatareg_TxDataReg( uint32_t value );
#else
INLINE void FREG_I2C2_SetTxdatareg_TxDataReg( uint32_t value )
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
extern uint32_t FREG_I2C2_GetTxdatareg( void );
#else
INLINE uint32_t FREG_I2C2_GetTxdatareg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXDATAREG));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetTxdatareg_TxDataReg( void );
#else
INLINE uint32_t FREG_I2C2_GetTxdatareg_TxDataReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXDATAREG));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetRxdatareg( void );
#else
INLINE uint32_t FREG_I2C2_GetRxdatareg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXDATAREG));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetRxdatareg_RxDataReg( void );
#else
INLINE uint32_t FREG_I2C2_GetRxdatareg_RxDataReg( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXDATAREG));
    value = ( value & 0x000000FFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetTxcntpoi( void );
#else
INLINE uint32_t FREG_I2C2_GetTxcntpoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXCNTPOI));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetTxcntpoi_AmTxPoi( void );
#else
INLINE uint32_t FREG_I2C2_GetTxcntpoi_AmTxPoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_TXCNTPOI));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_I2C2_GetRxcntpoi( void );
#else
INLINE uint32_t FREG_I2C2_GetRxcntpoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXCNTPOI));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetRxcntpoi_AmRxPoi( void );
#else
INLINE uint32_t FREG_I2C2_GetRxcntpoi_AmRxPoi( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_RXCNTPOI));
    value = ( value & 0x0000FFFFUL ) >> 0;
    return( value );
}
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
extern uint32_t FREG_I2C_GetClkdivider( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetClkdivider( uint32_t index )
{
    register uint32_t value;
    #if defined(FREG_CHECK_INDEX)
        if( index >= 2 )
            return( 0xFFFFFFFFUL );
    #endif
    value = *((volatile uint32_t*)(FREG_I2C_CLKDIVIDER+(index*FREG_I2C_MOFFSET)));
    return( value );
}
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
extern uint32_t FREG_I2C_GetClkdivider_ClkDivider( uint32_t index );
#else
INLINE uint32_t FREG_I2C_GetClkdivider_ClkDivider( uint32_t index )
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
extern uint32_t FREG_I2C2_GetClkdivider( void );
#else
INLINE uint32_t FREG_I2C2_GetClkdivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CLKDIVIDER));
    return( value );
}
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
extern uint32_t FREG_I2C2_GetClkdivider_ClkDivider( void );
#else
INLINE uint32_t FREG_I2C2_GetClkdivider_ClkDivider( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(FREG_I2C2_CLKDIVIDER));
    value = ( value & 0x000003FFUL ) >> 0;
    return( value );
}
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
extern void FREG_I2C_Init( void );

#endif
