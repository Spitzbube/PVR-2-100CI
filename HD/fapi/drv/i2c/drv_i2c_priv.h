/*
********************************************************************************
**
** \file        ./fapi/drv/i2c/src/drv_i2c_priv.h
** 
** \brief       I2C Driver.
**
** This file contains private register functions of the I2C driver.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_I2C_PRIV_H
    #define FAPI_I2C_PRIV_H

    #include <fapi/reg_i2c.h>

/*
********************************************************************************
**
** \brief i2cGetStatusreg0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetStatusreg0
** \sa FREG_I2C2_GetStatusreg0
**
********************************************************************************
*/
INLINE uint32_t i2cGetStatusreg0( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetStatusreg0(index));

    return(FREG_I2C2_GetStatusreg0());
}

/*
********************************************************************************
**
** \brief i2cGetStatusreg1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetStatusreg1
** \sa FREG_I2C2_GetStatusreg1
**
********************************************************************************
*/
INLINE uint32_t i2cGetStatusreg1( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetStatusreg1(index));

    return(FREG_I2C2_GetStatusreg1());
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0
** \sa FREG_I2C2_SetIrqmask0
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0(index, value);
    else
        FREG_I2C2_SetIrqmask0(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_SlRstart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_SlRstart
** \sa FREG_I2C2_SetIrqmask0_SlRstart
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_SlRstart( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_SlRstart(index, value);
    else
        FREG_I2C2_SetIrqmask0_SlRstart(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_StopTrm function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_StopTrm
** \sa FREG_I2C2_SetIrqmask0_StopTrm
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_StopTrm( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_StopTrm(index, value);
    else
        FREG_I2C2_SetIrqmask0_StopTrm(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_SlStopRec function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_SlStopRec
** \sa FREG_I2C2_SetIrqmask0_SlStopRec
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_SlStopRec( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_SlStopRec(index, value);
    else
        FREG_I2C2_SetIrqmask0_SlStopRec(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_MsStopRec function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_MsStopRec
** \sa FREG_I2C2_SetIrqmask0_MsStopRec
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_MsStopRec( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_MsStopRec(index, value);
    else
        FREG_I2C2_SetIrqmask0_MsStopRec(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_RcNack function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_RcNack
** \sa FREG_I2C2_SetIrqmask0_RcNack
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_RcNack( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_RcNack(index, value);
    else
        FREG_I2C2_SetIrqmask0_RcNack(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_SlNack function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_SlNack
** \sa FREG_I2C2_SetIrqmask0_SlNack
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_SlNack( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_SlNack(index, value);
    else
        FREG_I2C2_SetIrqmask0_SlNack(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_SlAck function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_SlAck
** \sa FREG_I2C2_SetIrqmask0_SlAck
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_SlAck( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_SlAck(index, value);
    else
        FREG_I2C2_SetIrqmask0_SlAck(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_DataTrmSl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_DataTrmSl
** \sa FREG_I2C2_SetIrqmask0_DataTrmSl
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_DataTrmSl( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_DataTrmSl(index, value);
    else
        FREG_I2C2_SetIrqmask0_DataTrmSl(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_DataTrmMs function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_DataTrmMs
** \sa FREG_I2C2_SetIrqmask0_DataTrmMs
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_DataTrmMs( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_DataTrmMs(index, value);
    else
        FREG_I2C2_SetIrqmask0_DataTrmMs(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_DataRecSl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_DataRecSl
** \sa FREG_I2C2_SetIrqmask0_DataRecSl
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_DataRecSl( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_DataRecSl(index, value);
    else
        FREG_I2C2_SetIrqmask0_DataRecSl(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_DataRecMs function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_DataRecMs
** \sa FREG_I2C2_SetIrqmask0_DataRecMs
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_DataRecMs( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_DataRecMs(index, value);
    else
        FREG_I2C2_SetIrqmask0_DataRecMs(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_AlStop function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_AlStop
** \sa FREG_I2C2_SetIrqmask0_AlStop
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_AlStop( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_AlStop(index, value);
    else
        FREG_I2C2_SetIrqmask0_AlStop(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_AlData function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_AlData
** \sa FREG_I2C2_SetIrqmask0_AlData
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_AlData( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_AlData(index, value);
    else
        FREG_I2C2_SetIrqmask0_AlData(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_AlAdrsta function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_AlAdrsta
** \sa FREG_I2C2_SetIrqmask0_AlAdrsta
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_AlAdrsta( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_AlAdrsta(index, value);
    else
        FREG_I2C2_SetIrqmask0_AlAdrsta(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_BeStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_BeStart
** \sa FREG_I2C2_SetIrqmask0_BeStart
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_BeStart( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_BeStart(index, value);
    else
        FREG_I2C2_SetIrqmask0_BeStart(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask0_BeStop function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask0_BeStop
** \sa FREG_I2C2_SetIrqmask0_BeStop
**
********************************************************************************
*/
INLINE void i2cSetIrqmask0_BeStop( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask0_BeStop(index, value);
    else
        FREG_I2C2_SetIrqmask0_BeStop(value);
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0
** \sa FREG_I2C2_GetIrqmask0
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0(index));

    return(FREG_I2C2_GetIrqmask0());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_SlRstart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_SlRstart
** \sa FREG_I2C2_GetIrqmask0_SlRstart
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_SlRstart( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_SlRstart(index));

    return(FREG_I2C2_GetIrqmask0_SlRstart());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_StopTrm function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_StopTrm
** \sa FREG_I2C2_GetIrqmask0_StopTrm
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_StopTrm( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_StopTrm(index));

    return(FREG_I2C2_GetIrqmask0_StopTrm());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_SlStopRec function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_SlStopRec
** \sa FREG_I2C2_GetIrqmask0_SlStopRec
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_SlStopRec( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_SlStopRec(index));

    return(FREG_I2C2_GetIrqmask0_SlStopRec());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_MsStopRec function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_MsStopRec
** \sa FREG_I2C2_GetIrqmask0_MsStopRec
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_MsStopRec( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_MsStopRec(index));

    return(FREG_I2C2_GetIrqmask0_MsStopRec());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_RcNack function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_RcNack
** \sa FREG_I2C2_GetIrqmask0_RcNack
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_RcNack( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_RcNack(index));

    return(FREG_I2C2_GetIrqmask0_RcNack());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_SlNack function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_SlNack
** \sa FREG_I2C2_GetIrqmask0_SlNack
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_SlNack( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_SlNack(index));

    return(FREG_I2C2_GetIrqmask0_SlNack());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_SlAck function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_SlAck
** \sa FREG_I2C2_GetIrqmask0_SlAck
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_SlAck( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_SlAck(index));

    return(FREG_I2C2_GetIrqmask0_SlAck());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_DataTrmSl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_DataTrmSl
** \sa FREG_I2C2_GetIrqmask0_DataTrmSl
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_DataTrmSl( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_DataTrmSl(index));

    return(FREG_I2C2_GetIrqmask0_DataTrmSl());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_DataTrmMs function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_DataTrmMs
** \sa FREG_I2C2_GetIrqmask0_DataTrmMs
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_DataTrmMs( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_DataTrmMs(index));

    return(FREG_I2C2_GetIrqmask0_DataTrmMs());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_DataRecSl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_DataRecSl
** \sa FREG_I2C2_GetIrqmask0_DataRecSl
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_DataRecSl( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_DataRecSl(index));

    return(FREG_I2C2_GetIrqmask0_DataRecSl());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_DataRecMs function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_DataRecMs
** \sa FREG_I2C2_GetIrqmask0_DataRecMs
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_DataRecMs( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_DataRecMs(index));

    return(FREG_I2C2_GetIrqmask0_DataRecMs());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_AlStop function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_AlStop
** \sa FREG_I2C2_GetIrqmask0_AlStop
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_AlStop( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_AlStop(index));

    return(FREG_I2C2_GetIrqmask0_AlStop());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_AlData function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_AlData
** \sa FREG_I2C2_GetIrqmask0_AlData
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_AlData( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_AlData(index));

    return(FREG_I2C2_GetIrqmask0_AlData());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_AlAdrsta function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_AlAdrsta
** \sa FREG_I2C2_GetIrqmask0_AlAdrsta
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_AlAdrsta( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_AlAdrsta(index));

    return(FREG_I2C2_GetIrqmask0_AlAdrsta());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_BeStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_BeStart
** \sa FREG_I2C2_GetIrqmask0_BeStart
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_BeStart( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_BeStart(index));

    return(FREG_I2C2_GetIrqmask0_BeStart());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask0_BeStop function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask0_BeStop
** \sa FREG_I2C2_GetIrqmask0_BeStop
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask0_BeStop( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask0_BeStop(index));

    return(FREG_I2C2_GetIrqmask0_BeStop());
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1
** \sa FREG_I2C2_SetIrqmask1
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1(index, value);
    else
        FREG_I2C2_SetIrqmask1(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_AmOngo function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_AmOngo
** \sa FREG_I2C2_SetIrqmask1_AmOngo
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_AmOngo( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_AmOngo(index, value);
    else
        FREG_I2C2_SetIrqmask1_AmOngo(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_AmEnd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_AmEnd
** \sa FREG_I2C2_SetIrqmask1_AmEnd
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_AmEnd( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_AmEnd(index, value);
    else
        FREG_I2C2_SetIrqmask1_AmEnd(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_AmErr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_AmErr
** \sa FREG_I2C2_SetIrqmask1_AmErr
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_AmErr( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_AmErr(index, value);
    else
        FREG_I2C2_SetIrqmask1_AmErr(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_AmMrxReq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_AmMrxReq
** \sa FREG_I2C2_SetIrqmask1_AmMrxReq
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_AmMrxReq( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_AmMrxReq(index, value);
    else
        FREG_I2C2_SetIrqmask1_AmMrxReq(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_AmMtxReq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_AmMtxReq
** \sa FREG_I2C2_SetIrqmask1_AmMtxReq
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_AmMtxReq( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_AmMtxReq(index, value);
    else
        FREG_I2C2_SetIrqmask1_AmMtxReq(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_Occup function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_Occup
** \sa FREG_I2C2_SetIrqmask1_Occup
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_Occup( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_Occup(index, value);
    else
        FREG_I2C2_SetIrqmask1_Occup(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_RdWr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_RdWr
** \sa FREG_I2C2_SetIrqmask1_RdWr
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_RdWr( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_RdWr(index, value);
    else
        FREG_I2C2_SetIrqmask1_RdWr(value);
}

/*
********************************************************************************
**
** \brief i2cSetIrqmask1_SlAdr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetIrqmask1_SlAdr
** \sa FREG_I2C2_SetIrqmask1_SlAdr
**
********************************************************************************
*/
INLINE void i2cSetIrqmask1_SlAdr( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetIrqmask1_SlAdr(index, value);
    else
        FREG_I2C2_SetIrqmask1_SlAdr(value);
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1
** \sa FREG_I2C2_GetIrqmask1
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1(index));

    return(FREG_I2C2_GetIrqmask1());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_AmOngo function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_AmOngo
** \sa FREG_I2C2_GetIrqmask1_AmOngo
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_AmOngo( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_AmOngo(index));

    return(FREG_I2C2_GetIrqmask1_AmOngo());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_AmEnd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_AmEnd
** \sa FREG_I2C2_GetIrqmask1_AmEnd
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_AmEnd( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_AmEnd(index));

    return(FREG_I2C2_GetIrqmask1_AmEnd());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_AmErr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_AmErr
** \sa FREG_I2C2_GetIrqmask1_AmErr
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_AmErr( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_AmErr(index));

    return(FREG_I2C2_GetIrqmask1_AmErr());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_AmMrxReq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_AmMrxReq
** \sa FREG_I2C2_GetIrqmask1_AmMrxReq
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_AmMrxReq( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_AmMrxReq(index));

    return(FREG_I2C2_GetIrqmask1_AmMrxReq());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_AmMtxReq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_AmMtxReq
** \sa FREG_I2C2_GetIrqmask1_AmMtxReq
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_AmMtxReq( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_AmMtxReq(index));

    return(FREG_I2C2_GetIrqmask1_AmMtxReq());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_Occup function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_Occup
** \sa FREG_I2C2_GetIrqmask1_Occup
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_Occup( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_Occup(index));

    return(FREG_I2C2_GetIrqmask1_Occup());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_RdWr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_RdWr
** \sa FREG_I2C2_GetIrqmask1_RdWr
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_RdWr( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_RdWr(index));

    return(FREG_I2C2_GetIrqmask1_RdWr());
}

/*
********************************************************************************
**
** \brief i2cGetIrqmask1_SlAdr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetIrqmask1_SlAdr
** \sa FREG_I2C2_GetIrqmask1_SlAdr
**
********************************************************************************
*/
INLINE uint32_t i2cGetIrqmask1_SlAdr( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetIrqmask1_SlAdr(index));

    return(FREG_I2C2_GetIrqmask1_SlAdr());
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0
** \sa FREG_I2C2_SetControlreg0
**
********************************************************************************
*/
INLINE void i2cSetControlreg0( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0(index, value);
    else
        FREG_I2C2_SetControlreg0(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_SpikeFlt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_SpikeFlt
** \sa FREG_I2C2_SetControlreg0_SpikeFlt
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_SpikeFlt( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_SpikeFlt(index, value);
    else
        FREG_I2C2_SetControlreg0_SpikeFlt(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_OiDlyAl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_OiDlyAl
** \sa FREG_I2C2_SetControlreg0_OiDlyAl
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_OiDlyAl( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_OiDlyAl(index, value);
    else
        FREG_I2C2_SetControlreg0_OiDlyAl(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_AmMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_AmMode
** \sa FREG_I2C2_SetControlreg0_AmMode
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_AmMode( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_AmMode(index, value);
    else
        FREG_I2C2_SetControlreg0_AmMode(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_UseAdd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_UseAdd
** \sa FREG_I2C2_SetControlreg0_UseAdd
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_UseAdd( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_UseAdd(index, value);
    else
        FREG_I2C2_SetControlreg0_UseAdd(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_AmOn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_AmOn
** \sa FREG_I2C2_SetControlreg0_AmOn
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_AmOn( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_AmOn(index, value);
    else
        FREG_I2C2_SetControlreg0_AmOn(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_Reset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_Reset
** \sa FREG_I2C2_SetControlreg0_Reset
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_Reset( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_Reset(index, value);
    else
        FREG_I2C2_SetControlreg0_Reset(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_Start function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_Start
** \sa FREG_I2C2_SetControlreg0_Start
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_Start( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_Start(index, value);
    else
        FREG_I2C2_SetControlreg0_Start(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_Stop function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_Stop
** \sa FREG_I2C2_SetControlreg0_Stop
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_Stop( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_Stop(index, value);
    else
        FREG_I2C2_SetControlreg0_Stop(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg0_Nack function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg0_Nack
** \sa FREG_I2C2_SetControlreg0_Nack
**
********************************************************************************
*/
INLINE void i2cSetControlreg0_Nack( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg0_Nack(index, value);
    else
        FREG_I2C2_SetControlreg0_Nack(value);
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0
** \sa FREG_I2C2_GetControlreg0
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0(index));

    return(FREG_I2C2_GetControlreg0());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_SpikeFlt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_SpikeFlt
** \sa FREG_I2C2_GetControlreg0_SpikeFlt
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_SpikeFlt( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_SpikeFlt(index));

    return(FREG_I2C2_GetControlreg0_SpikeFlt());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_OiDlyAl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_OiDlyAl
** \sa FREG_I2C2_GetControlreg0_OiDlyAl
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_OiDlyAl( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_OiDlyAl(index));

    return(FREG_I2C2_GetControlreg0_OiDlyAl());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_AmMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_AmMode
** \sa FREG_I2C2_GetControlreg0_AmMode
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_AmMode( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_AmMode(index));

    return(FREG_I2C2_GetControlreg0_AmMode());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_UseAdd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_UseAdd
** \sa FREG_I2C2_GetControlreg0_UseAdd
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_UseAdd( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_UseAdd(index));

    return(FREG_I2C2_GetControlreg0_UseAdd());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_AmOn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_AmOn
** \sa FREG_I2C2_GetControlreg0_AmOn
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_AmOn( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_AmOn(index));

    return(FREG_I2C2_GetControlreg0_AmOn());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_Reset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_Reset
** \sa FREG_I2C2_GetControlreg0_Reset
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_Reset( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_Reset(index));

    return(FREG_I2C2_GetControlreg0_Reset());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_Start function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_Start
** \sa FREG_I2C2_GetControlreg0_Start
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_Start( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_Start(index));

    return(FREG_I2C2_GetControlreg0_Start());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_Stop function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_Stop
** \sa FREG_I2C2_GetControlreg0_Stop
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_Stop( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_Stop(index));

    return(FREG_I2C2_GetControlreg0_Stop());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg0_Nack function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg0_Nack
** \sa FREG_I2C2_GetControlreg0_Nack
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg0_Nack( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg0_Nack(index));

    return(FREG_I2C2_GetControlreg0_Nack());
}

/*
********************************************************************************
**
** \brief i2cSetControlreg1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg1
** \sa FREG_I2C2_SetControlreg1
**
********************************************************************************
*/
INLINE void i2cSetControlreg1( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg1(index, value);
    else
        FREG_I2C2_SetControlreg1(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg1_MsSlaAdd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg1_MsSlaAdd
** \sa FREG_I2C2_SetControlreg1_MsSlaAdd
**
********************************************************************************
*/
INLINE void i2cSetControlreg1_MsSlaAdd( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg1_MsSlaAdd(index, value);
    else
        FREG_I2C2_SetControlreg1_MsSlaAdd(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg1_SlSlaAdd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg1_SlSlaAdd
** \sa FREG_I2C2_SetControlreg1_SlSlaAdd
**
********************************************************************************
*/
INLINE void i2cSetControlreg1_SlSlaAdd( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg1_SlSlaAdd(index, value);
    else
        FREG_I2C2_SetControlreg1_SlSlaAdd(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg1_I2cSpeed function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg1_I2cSpeed
** \sa FREG_I2C2_SetControlreg1_I2cSpeed
**
********************************************************************************
*/
INLINE void i2cSetControlreg1_I2cSpeed( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg1_I2cSpeed(index, value);
    else
        FREG_I2C2_SetControlreg1_I2cSpeed(value);
}

/*
********************************************************************************
**
** \brief i2cGetControlreg1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg1
** \sa FREG_I2C2_GetControlreg1
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg1( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg1(index));

    return(FREG_I2C2_GetControlreg1());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg1_MsSlaAdd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg1_MsSlaAdd
** \sa FREG_I2C2_GetControlreg1_MsSlaAdd
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg1_MsSlaAdd( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg1_MsSlaAdd(index));

    return(FREG_I2C2_GetControlreg1_MsSlaAdd());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg1_SlSlaAdd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg1_SlSlaAdd
** \sa FREG_I2C2_GetControlreg1_SlSlaAdd
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg1_SlSlaAdd( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg1_SlSlaAdd(index));

    return(FREG_I2C2_GetControlreg1_SlSlaAdd());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg1_I2cSpeed function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg1_I2cSpeed
** \sa FREG_I2C2_GetControlreg1_I2cSpeed
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg1_I2cSpeed( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg1_I2cSpeed(index));

    return(FREG_I2C2_GetControlreg1_I2cSpeed());
}

/*
********************************************************************************
**
** \brief i2cSetControlreg2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg2
** \sa FREG_I2C2_SetControlreg2
**
********************************************************************************
*/
INLINE void i2cSetControlreg2( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg2(index, value);
    else
        FREG_I2C2_SetControlreg2(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg2_AmTxNum function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg2_AmTxNum
** \sa FREG_I2C2_SetControlreg2_AmTxNum
**
********************************************************************************
*/
INLINE void i2cSetControlreg2_AmTxNum( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg2_AmTxNum(index, value);
    else
        FREG_I2C2_SetControlreg2_AmTxNum(value);
}

/*
********************************************************************************
**
** \brief i2cGetControlreg2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg2
** \sa FREG_I2C2_GetControlreg2
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg2( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg2(index));

    return(FREG_I2C2_GetControlreg2());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg2_AmTxNum function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg2_AmTxNum
** \sa FREG_I2C2_GetControlreg2_AmTxNum
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg2_AmTxNum( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg2_AmTxNum(index));

    return(FREG_I2C2_GetControlreg2_AmTxNum());
}

/*
********************************************************************************
**
** \brief i2cSetControlreg3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg3
** \sa FREG_I2C2_SetControlreg3
**
********************************************************************************
*/
INLINE void i2cSetControlreg3( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg3(index, value);
    else
        FREG_I2C2_SetControlreg3(value);
}

/*
********************************************************************************
**
** \brief i2cSetControlreg3_AmRxNum function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetControlreg3_AmRxNum
** \sa FREG_I2C2_SetControlreg3_AmRxNum
**
********************************************************************************
*/
INLINE void i2cSetControlreg3_AmRxNum( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetControlreg3_AmRxNum(index, value);
    else
        FREG_I2C2_SetControlreg3_AmRxNum(value);
}

/*
********************************************************************************
**
** \brief i2cGetControlreg3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg3
** \sa FREG_I2C2_GetControlreg3
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg3( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg3(index));

    return(FREG_I2C2_GetControlreg3());
}

/*
********************************************************************************
**
** \brief i2cGetControlreg3_AmRxNum function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetControlreg3_AmRxNum
** \sa FREG_I2C2_GetControlreg3_AmRxNum
**
********************************************************************************
*/
INLINE uint32_t i2cGetControlreg3_AmRxNum( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetControlreg3_AmRxNum(index));

    return(FREG_I2C2_GetControlreg3_AmRxNum());
}

/*
********************************************************************************
**
** \brief i2cSetGoreg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetGoreg
** \sa FREG_I2C2_SetGoreg
**
********************************************************************************
*/
INLINE void i2cSetGoreg( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetGoreg(index, value);
    else
        FREG_I2C2_SetGoreg(value);
}

/*
********************************************************************************
**
** \brief i2cSetGoreg_AmStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetGoreg_AmStart
** \sa FREG_I2C2_SetGoreg_AmStart
**
********************************************************************************
*/
INLINE void i2cSetGoreg_AmStart( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetGoreg_AmStart(index, value);
    else
        FREG_I2C2_SetGoreg_AmStart(value);
}

/*
********************************************************************************
**
** \brief i2cSetGoreg_AmReset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetGoreg_AmReset
** \sa FREG_I2C2_SetGoreg_AmReset
**
********************************************************************************
*/
INLINE void i2cSetGoreg_AmReset( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetGoreg_AmReset(index, value);
    else
        FREG_I2C2_SetGoreg_AmReset(value);
}

/*
********************************************************************************
**
** \brief i2cSetGoreg_I2cGo function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetGoreg_I2cGo
** \sa FREG_I2C2_SetGoreg_I2cGo
**
********************************************************************************
*/
INLINE void i2cSetGoreg_I2cGo( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetGoreg_I2cGo(index, value);
    else
        FREG_I2C2_SetGoreg_I2cGo(value);
}

/*
********************************************************************************
**
** \brief i2cGetGoreg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetGoreg
** \sa FREG_I2C2_GetGoreg
**
********************************************************************************
*/
INLINE uint32_t i2cGetGoreg( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetGoreg(index));

    return(FREG_I2C2_GetGoreg());
}

/*
********************************************************************************
**
** \brief i2cGetGoreg_AmStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetGoreg_AmStart
** \sa FREG_I2C2_GetGoreg_AmStart
**
********************************************************************************
*/
INLINE uint32_t i2cGetGoreg_AmStart( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetGoreg_AmStart(index));

    return(FREG_I2C2_GetGoreg_AmStart());
}

/*
********************************************************************************
**
** \brief i2cGetGoreg_AmReset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetGoreg_AmReset
** \sa FREG_I2C2_GetGoreg_AmReset
**
********************************************************************************
*/
INLINE uint32_t i2cGetGoreg_AmReset( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetGoreg_AmReset(index));

    return(FREG_I2C2_GetGoreg_AmReset());
}

/*
********************************************************************************
**
** \brief i2cGetGoreg_I2cGo function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetGoreg_I2cGo
** \sa FREG_I2C2_GetGoreg_I2cGo
**
********************************************************************************
*/
INLINE uint32_t i2cGetGoreg_I2cGo( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetGoreg_I2cGo(index));

    return(FREG_I2C2_GetGoreg_I2cGo());
}

/*
********************************************************************************
**
** \brief i2cSetTxdatareg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetTxdatareg
** \sa FREG_I2C2_SetTxdatareg
**
********************************************************************************
*/
INLINE void i2cSetTxdatareg( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetTxdatareg(index, value);
    else
        FREG_I2C2_SetTxdatareg(value);
}

/*
********************************************************************************
**
** \brief i2cSetTxdatareg_TxDataReg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_SetTxdatareg_TxDataReg
** \sa FREG_I2C2_SetTxdatareg_TxDataReg
**
********************************************************************************
*/
INLINE void i2cSetTxdatareg_TxDataReg( uint32_t index, uint32_t value )
{
    if(index != FAPI_I2C2)
        FREG_I2C_SetTxdatareg_TxDataReg(index, value);
    else
        FREG_I2C2_SetTxdatareg_TxDataReg(value);
}

/*
********************************************************************************
**
** \brief i2cGetTxdatareg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetTxdatareg
** \sa FREG_I2C2_GetTxdatareg
**
********************************************************************************
*/
INLINE uint32_t i2cGetTxdatareg( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetTxdatareg(index));

    return(FREG_I2C2_GetTxdatareg());
}

/*
********************************************************************************
**
** \brief i2cGetTxdatareg_TxDataReg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetTxdatareg_TxDataReg
** \sa FREG_I2C2_GetTxdatareg_TxDataReg
**
********************************************************************************
*/
INLINE uint32_t i2cGetTxdatareg_TxDataReg( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetTxdatareg_TxDataReg(index));

    return(FREG_I2C2_GetTxdatareg_TxDataReg());
}

/*
********************************************************************************
**
** \brief i2cGetRxdatareg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetRxdatareg
** \sa FREG_I2C2_GetRxdatareg
**
********************************************************************************
*/
INLINE uint32_t i2cGetRxdatareg( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetRxdatareg(index));

    return(FREG_I2C2_GetRxdatareg());
}

/*
********************************************************************************
**
** \brief i2cGetRxdatareg_RxDataReg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetRxdatareg_RxDataReg
** \sa FREG_I2C2_GetRxdatareg_RxDataReg
**
********************************************************************************
*/
INLINE uint32_t i2cGetRxdatareg_RxDataReg( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetRxdatareg_RxDataReg(index));

    return(FREG_I2C2_GetRxdatareg_RxDataReg());
}

/*
********************************************************************************
**
** \brief i2cGetTxcntpoi function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetTxcntpoi
** \sa FREG_I2C2_GetTxcntpoi
**
********************************************************************************
*/
INLINE uint32_t i2cGetTxcntpoi( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetTxcntpoi(index));

    return(FREG_I2C2_GetTxcntpoi());
}

/*
********************************************************************************
**
** \brief i2cGetTxcntpoi_AmTxPoi function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetTxcntpoi_AmTxPoi
** \sa FREG_I2C2_GetTxcntpoi_AmTxPoi
**
********************************************************************************
*/
INLINE uint32_t i2cGetTxcntpoi_AmTxPoi( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetTxcntpoi_AmTxPoi(index));

    return(FREG_I2C2_GetTxcntpoi_AmTxPoi());
}

/*
********************************************************************************
**
** \brief i2cGetRxcntpoi function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetRxcntpoi
** \sa FREG_I2C2_GetRxcntpoi
**
********************************************************************************
*/
INLINE uint32_t i2cGetRxcntpoi( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetRxcntpoi(index));

    return(FREG_I2C2_GetRxcntpoi());
}

/*
********************************************************************************
**
** \brief i2cGetRxcntpoi_AmRxPoi function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_I2C_GetRxcntpoi_AmRxPoi
** \sa FREG_I2C2_GetRxcntpoi_AmRxPoi
**
********************************************************************************
*/
INLINE uint32_t i2cGetRxcntpoi_AmRxPoi( uint32_t index )
{
    if(index != FAPI_I2C2)
        return(FREG_I2C_GetRxcntpoi_AmRxPoi(index));

    return(FREG_I2C2_GetRxcntpoi_AmRxPoi());
}

#endif
