/*
********************************************************************************
**
** \file        ./fapi/drv/bm/src/drv_bm_priv.h
**
** \brief       BM Driver.
**
** This file contains private register functions of the BM driver.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_BM_PRIV_H
    #define FAPI_BM_PRIV_H

    #include <fapi/reg_bm.h>

/* clear the mail queue upon TSD recovery */
void bmClearMailQueue(uint32_t blockIndex);

/*
********************************************************************************
**
** \brief bmSetBufSize function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetBufSize
** \sa FREG_BM1_SetBufSize
** \sa FREG_BM2_SetBufSize
** \sa FREG_BM3_SetBufSize
**
********************************************************************************
*/
INLINE void bmSetBufSize(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetBufSize(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetBufSize(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetBufSize(index, value);
    else
        FREG_BM3_SetBufSize(index, value);
}

/*
********************************************************************************
**
** \brief bmSetBufSize_BufSize function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetBufSize_BufSize
** \sa FREG_BM1_SetBufSize_BufSize
** \sa FREG_BM2_SetBufSize_BufSize
** \sa FREG_BM3_SetBufSize_BufSize
**
********************************************************************************
*/
INLINE void bmSetBufSize_BufSize(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetBufSize_BufSize(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetBufSize_BufSize(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetBufSize_BufSize(index, value);
    else
        FREG_BM3_SetBufSize_BufSize(index, value);
}

/*
********************************************************************************
**
** \brief bmGetBufSize function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetBufSize
** \sa FREG_BM1_GetBufSize
** \sa FREG_BM2_GetBufSize
** \sa FREG_BM3_GetBufSize
**
********************************************************************************
*/
INLINE uint32_t bmGetBufSize(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetBufSize(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetBufSize(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetBufSize(index));
    return(FREG_BM3_GetBufSize(index));
}

/*
********************************************************************************
**
** \brief bmGetBufSize_BufSize function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetBufSize_BufSize
** \sa FREG_BM1_GetBufSize_BufSize
** \sa FREG_BM2_GetBufSize_BufSize
** \sa FREG_BM3_GetBufSize_BufSize
**
********************************************************************************
*/
INLINE uint32_t bmGetBufSize_BufSize(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetBufSize_BufSize(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetBufSize_BufSize(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetBufSize_BufSize(index));
    return(FREG_BM3_GetBufSize_BufSize(index));
}

/*
********************************************************************************
**
** \brief bmSetWrPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetWrPtr
** \sa FREG_BM1_SetWrPtr
** \sa FREG_BM2_SetWrPtr
** \sa FREG_BM3_SetWrPtr
**
********************************************************************************
*/
INLINE void bmSetWrPtr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetWrPtr(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetWrPtr(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetWrPtr(index, value);
    else
        FREG_BM3_SetWrPtr(index, value);
}

/*
********************************************************************************
**
** \brief bmSetWrPtr_WrPointer function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetWrPtr_WrPointer
** \sa FREG_BM1_SetWrPtr_WrPointer
** \sa FREG_BM2_SetWrPtr_WrPointer
** \sa FREG_BM3_SetWrPtr_WrPointer
**
********************************************************************************
*/
INLINE void bmSetWrPtr_WrPointer(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetWrPtr_WrPointer(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetWrPtr_WrPointer(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetWrPtr_WrPointer(index, value);
    else
        FREG_BM3_SetWrPtr_WrPointer(index, value);
}

/*
********************************************************************************
**
** \brief bmGetWrPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetWrPtr
** \sa FREG_BM1_GetWrPtr
** \sa FREG_BM2_GetWrPtr
** \sa FREG_BM3_GetWrPtr
**
********************************************************************************
*/
INLINE uint32_t bmGetWrPtr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetWrPtr(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetWrPtr(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetWrPtr(index));
    return(FREG_BM3_GetWrPtr(index));
}

/*
********************************************************************************
**
** \brief bmGetWrPtr_WrPointer function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetWrPtr_WrPointer
** \sa FREG_BM1_GetWrPtr_WrPointer
** \sa FREG_BM2_GetWrPtr_WrPointer
** \sa FREG_BM3_GetWrPtr_WrPointer
**
********************************************************************************
*/
INLINE uint32_t bmGetWrPtr_WrPointer(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetWrPtr_WrPointer(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetWrPtr_WrPointer(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetWrPtr_WrPointer(index));
    return(FREG_BM3_GetWrPtr_WrPointer(index));
}

/*
********************************************************************************
**
** \brief bmSetBaseAddr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetBaseAddr
** \sa FREG_BM1_SetBaseAddr
** \sa FREG_BM2_SetBaseAddr
** \sa FREG_BM3_SetBaseAddr
**
********************************************************************************
*/
INLINE void bmSetBaseAddr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetBaseAddr(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetBaseAddr(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetBaseAddr(index, value);
    else
        FREG_BM3_SetBaseAddr(index, value);
}

/*
********************************************************************************
**
** \brief bmSetBaseAddr_BaseAddr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetBaseAddr_BaseAddr
** \sa FREG_BM1_SetBaseAddr_BaseAddr
** \sa FREG_BM2_SetBaseAddr_BaseAddr
** \sa FREG_BM3_SetBaseAddr_BaseAddr
**
********************************************************************************
*/
INLINE void bmSetBaseAddr_BaseAddr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetBaseAddr_BaseAddr(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetBaseAddr_BaseAddr(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetBaseAddr_BaseAddr(index, value);
    else
        FREG_BM3_SetBaseAddr_BaseAddr(index, value);
}

/*
********************************************************************************
**
** \brief bmGetBaseAddr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetBaseAddr
** \sa FREG_BM0_GetBaseAddr
** \sa FREG_BM0_GetBaseAddr
** \sa FREG_BM0_GetBaseAddr
**
********************************************************************************
*/
INLINE uint32_t bmGetBaseAddr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetBaseAddr(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetBaseAddr(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetBaseAddr(index));
    return(FREG_BM3_GetBaseAddr(index));
}

/*
********************************************************************************
**
** \brief bmGetBaseAddr_BaseAddr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetBaseAddr_BaseAddr
** \sa FREG_BM1_GetBaseAddr_BaseAddr
** \sa FREG_BM2_GetBaseAddr_BaseAddr
** \sa FREG_BM3_GetBaseAddr_BaseAddr
**
********************************************************************************
*/
INLINE uint32_t bmGetBaseAddr_BaseAddr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetBaseAddr_BaseAddr(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetBaseAddr_BaseAddr(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetBaseAddr_BaseAddr(index));
    return(FREG_BM3_GetBaseAddr_BaseAddr(index));
}

/*
********************************************************************************
**
** \brief bmSetRdPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetRdPtr
** \sa FREG_BM1_SetRdPtr
** \sa FREG_BM2_SetRdPtr
** \sa FREG_BM3_SetRdPtr
**
********************************************************************************
*/
INLINE void bmSetRdPtr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    value &= 0xFFFFFFC0;
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetRdPtr(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetRdPtr(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetRdPtr(index, value);
    else
        FREG_BM3_SetRdPtr(index, value);
}

/*
********************************************************************************
**
** \brief bmSetRdPtr_RdPointer function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetRdPtr_RdPointer
** \sa FREG_BM1_SetRdPtr_RdPointer
** \sa FREG_BM2_SetRdPtr_RdPointer
** \sa FREG_BM3_SetRdPtr_RdPointer
**
********************************************************************************
*/
INLINE void bmSetRdPtr_RdPointer(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetRdPtr_RdPointer(index, value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetRdPtr_RdPointer(index, value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetRdPtr_RdPointer(index, value);
    else
        FREG_BM3_SetRdPtr_RdPointer(index, value);
}

/*
********************************************************************************
**
** \brief bmGetRdPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetRdPtr
** \sa FREG_BM1_GetRdPtr
** \sa FREG_BM2_GetRdPtr
** \sa FREG_BM3_GetRdPtr
**
********************************************************************************
*/
INLINE uint32_t bmGetRdPtr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetRdPtr(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetRdPtr(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetRdPtr(index));
    return(FREG_BM3_GetRdPtr(index));
}

/*
********************************************************************************
**
** \brief bmGetRdPtr_RdPointer function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetRdPtr_RdPointer
** \sa FREG_BM1_GetRdPtr_RdPointer
** \sa FREG_BM2_GetRdPtr_RdPointer
** \sa FREG_BM3_GetRdPtr_RdPointer
**
********************************************************************************
*/
INLINE uint32_t bmGetRdPtr_RdPointer(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetRdPtr_RdPointer(index));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetRdPtr_RdPointer(index));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetRdPtr_RdPointer(index));
    return(FREG_BM3_GetRdPtr_RdPointer(index));
}

/*
********************************************************************************
**
** \brief bmSetIrqMask function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetIrqMask
** \sa FREG_BM1_SetIrqMask
** \sa FREG_BM2_SetIrqMask
** \sa FREG_BM3_SetIrqMask
**
********************************************************************************
*/
INLINE void bmSetIrqMask(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetIrqMask(value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetIrqMask(value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetIrqMask(value);
    else
        FREG_BM3_SetIrqMask(value);
}

/*
********************************************************************************
**
** \brief bmSetIrqMask_IrqMask function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetIrqMask_IrqMask
** \sa FREG_BM1_SetIrqMask_IrqMask
** \sa FREG_BM2_SetIrqMask_IrqMask
** \sa FREG_BM3_SetIrqMask_IrqMask
**
********************************************************************************
*/
INLINE void bmSetIrqMask_IrqMask(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetIrqMask_IrqMask(value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetIrqMask_IrqMask(value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetIrqMask_IrqMask(value);
    else
        FREG_BM3_SetIrqMask_IrqMask(value);
}

/*
********************************************************************************
**
** \brief bmGetmIrqMask function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetmIrqMask
** \sa FREG_BM1_GetmIrqMask
** \sa FREG_BM2_GetmIrqMask
** \sa FREG_BM3_GetmIrqMask
**
********************************************************************************
*/
INLINE uint32_t bmGetmIrqMask(uint32_t blockIndex)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetmIrqMask());
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetmIrqMask());
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetmIrqMask());
    return(FREG_BM3_GetmIrqMask());
}

/*
********************************************************************************
**
** \brief bmGetmIrqMask_IrqMask function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetmIrqMask_IrqMask
** \sa FREG_BM1_GetmIrqMask_IrqMask
** \sa FREG_BM2_GetmIrqMask_IrqMask
** \sa FREG_BM3_GetmIrqMask_IrqMask
**
********************************************************************************
*/
INLINE uint32_t bmGetmIrqMask_IrqMask(uint32_t blockIndex)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetmIrqMask_IrqMask());
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetmIrqMask_IrqMask());
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetmIrqMask_IrqMask());
    return(FREG_BM3_GetmIrqMask_IrqMask());
}

/*
********************************************************************************
**
** \brief bmGetIrqReg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetIrqReg
** \sa FREG_BM1_GetIrqReg
** \sa FREG_BM2_GetIrqReg
** \sa FREG_BM3_GetIrqReg
**
********************************************************************************
*/
INLINE uint32_t bmGetIrqReg(uint32_t blockIndex)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetIrqReg());
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetIrqReg());
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetIrqReg());
    return(FREG_BM3_GetIrqReg());
}

/*
********************************************************************************
**
** \brief bmExtractIrqReg_IrqReg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_ExtractIrqReg_IrqReg
** \sa FREG_BM1_ExtractIrqReg_IrqReg
** \sa FREG_BM2_ExtractIrqReg_IrqReg
** \sa FREG_BM3_ExtractIrqReg_IrqReg
**
********************************************************************************
*/
INLINE uint32_t bmExtractIrqReg_IrqReg(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_ExtractIrqReg_IrqReg(value));
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_ExtractIrqReg_IrqReg(value));
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_ExtractIrqReg_IrqReg(value));
    return(FREG_BM3_ExtractIrqReg_IrqReg(value));
}

/*
********************************************************************************
**
** \brief bmSetReadEnable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetReadEnable
** \sa FREG_BM23_SetReadEnable
**
********************************************************************************
*/
INLINE void bmSetReadEnable(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetReadEnable(value);
    else
        FREG_BM23_SetReadEnable(value);
}

/*
********************************************************************************
**
** \brief bmSetReadEnable_ReadSelect function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetReadEnable_Bm01ReadSelect
** \sa FREG_BM23_SetReadEnable_Bm23ReadSelect
**
********************************************************************************
*/
INLINE void bmSetReadEnable_ReadSelect(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetReadEnable_Bm01ReadSelect(value);
    else
        FREG_BM23_SetReadEnable_Bm23ReadSelect(value);
}

/*
********************************************************************************
**
** \brief bmSetReadEnable_ReadEnable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetReadEnable_Bm01ReadEnable
** \sa FREG_BM23_SetReadEnable_Bm23ReadEnable
**
********************************************************************************
*/
INLINE void bmSetReadEnable_ReadEnable(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetReadEnable_Bm01ReadEnable(value);
    else
        FREG_BM23_SetReadEnable_Bm23ReadEnable(value);
}

/*
********************************************************************************
**
** \brief bmGetmReadEnable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmReadEnable
** \sa FREG_BM23_GetmReadEnable
**
********************************************************************************
*/
INLINE uint32_t bmGetmReadEnable(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmReadEnable());
    return(FREG_BM23_GetmReadEnable());
}

/*
********************************************************************************
**
** \brief bmGetmReadEnable_ReadSelect function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmReadEnable_Bm01ReadSelect
** \sa FREG_BM23_GetmReadEnable_Bm23ReadSelect
**
********************************************************************************
*/
INLINE uint32_t bmGetmReadEnable_ReadSelect(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmReadEnable_Bm01ReadSelect());
    return(FREG_BM23_GetmReadEnable_Bm23ReadSelect());
}

/*
********************************************************************************
**
** \brief bmGetmReadEnable_Bm01ReadEnable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmReadEnable_Bm01ReadEnable
** \sa FREG_BM23_GetmReadEnable_Bm23ReadEnable
**
********************************************************************************
*/
INLINE uint32_t bmGetmReadEnable_ReadEnable(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmReadEnable_Bm01ReadEnable());
    return(FREG_BM23_GetmReadEnable_Bm23ReadEnable());
}

/*
********************************************************************************
**
** \brief bmSetGlobalOffset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetGlobalOffset
** \sa FREG_BM23_SetGlobalOffset
**
********************************************************************************
*/
INLINE void bmSetGlobalOffset(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetGlobalOffset(value);
    else
        FREG_BM23_SetGlobalOffset(value);
}

/*
********************************************************************************
**
** \brief bmSetGlobalOffset_Offset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetGlobalOffset_Bm01Offset
** \sa FREG_BM23_SetGlobalOffset_Bm23Offset
**
********************************************************************************
*/
INLINE void bmSetGlobalOffset_Offset(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetGlobalOffset_Bm01Offset(value);
    else
        FREG_BM23_SetGlobalOffset_Bm23Offset(value);
}

/*
********************************************************************************
**
** \brief bmGetmGlobalOffset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmGlobalOffset
** \sa FREG_BM23_GetmGlobalOffset
**
********************************************************************************
*/
INLINE uint32_t bmGetmGlobalOffset(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmGlobalOffset());
    return(FREG_BM23_GetmGlobalOffset());
}

/*
********************************************************************************
**
** \brief bmGetmGlobalOffset_Offset function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmGlobalOffset_Bm01Offset
** \sa FREG_BM23_GetmGlobalOffset_Bm23Offset
**
********************************************************************************
*/
INLINE uint32_t bmGetmGlobalOffset_Offset(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmGlobalOffset_Bm01Offset());
    return(FREG_BM23_GetmGlobalOffset_Bm23Offset());
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd
** \sa FREG_BM23_SetEndianSwapRd
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd(value);
    else
        FREG_BM23_SetEndianSwapRd(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd_TtxRdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd_TtxRdLittleEndian
** \sa FREG_BM23_SetEndianSwapRd_TtxRdLittleEndian
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd_TtxRdLittleEndian(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd_TtxRdLittleEndian(value);
    else
        FREG_BM23_SetEndianSwapRd_TtxRdLittleEndian(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd_SpdifRdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd_SpdifRdLittleEndian
** \sa FREG_BM23_SetEndianSwapRd_SpdifRdLittleEndian
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd_SpdifRdLittleEndian(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd_SpdifRdLittleEndian(value);
    else
        FREG_BM23_SetEndianSwapRd_SpdifRdLittleEndian(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd_I2s3RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd_I2s3RdLittleEndian
** \sa FREG_BM23_SetEndianSwapRd_I2s3RdLittleEndian
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd_I2s3RdLittleEndian(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd_I2s3RdLittleEndian(value);
    else
        FREG_BM23_SetEndianSwapRd_I2s3RdLittleEndian(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd_I2s2RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd_I2s2RdLittleEndian
** \sa FREG_BM23_SetEndianSwapRd_I2s2RdLittleEndian
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd_I2s2RdLittleEndian(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd_I2s2RdLittleEndian(value);
    else
        FREG_BM23_SetEndianSwapRd_I2s2RdLittleEndian(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd_I2s1RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd_I2s1RdLittleEndian
** \sa FREG_BM23_SetEndianSwapRd_I2s1RdLittleEndian
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd_I2s1RdLittleEndian(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd_I2s1RdLittleEndian(value);
    else
        FREG_BM23_SetEndianSwapRd_I2s1RdLittleEndian(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapRd_I2s0RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetEndianSwapRd_I2s0RdLittleEndian
** \sa FREG_BM23_SetEndianSwapRd_I2s0RdLittleEndian
**
********************************************************************************
*/
INLINE void bmSetEndianSwapRd_I2s0RdLittleEndian(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetEndianSwapRd_I2s0RdLittleEndian(value);
    else
        FREG_BM23_SetEndianSwapRd_I2s0RdLittleEndian(value);
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd
** \sa FREG_BM23_GetmEndianSwapRd
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd());
    return(FREG_BM23_GetmEndianSwapRd());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd_TtxRdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd_TtxRdLittleEndian
** \sa FREG_BM23_GetmEndianSwapRd_TtxRdLittleEndian
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd_TtxRdLittleEndian(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd_TtxRdLittleEndian());
    return(FREG_BM23_GetmEndianSwapRd_TtxRdLittleEndian());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd_SpdifRdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd_SpdifRdLittleEndian
** \sa FREG_BM23_GetmEndianSwapRd_SpdifRdLittleEndian
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd_SpdifRdLittleEndian(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd_SpdifRdLittleEndian());
    return(FREG_BM23_GetmEndianSwapRd_SpdifRdLittleEndian());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd_I2s3RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd_I2s3RdLittleEndian
** \sa FREG_BM23_GetmEndianSwapRd_I2s3RdLittleEndian
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd_I2s3RdLittleEndian(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd_I2s3RdLittleEndian());
    return(FREG_BM23_GetmEndianSwapRd_I2s3RdLittleEndian());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd_Audio2RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd_I2s2RdLittleEndian
** \sa FREG_BM23_GetmEndianSwapRd_I2s2RdLittleEndian
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd_I2s2RdLittleEndian(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd_I2s2RdLittleEndian());
    return(FREG_BM23_GetmEndianSwapRd_I2s2RdLittleEndian());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd_I2s1RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd_I2s1RdLittleEndian
** \sa FREG_BM23_GetmEndianSwapRd_I2s1RdLittleEndian
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd_I2s1RdLittleEndian(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd_I2s1RdLittleEndian());
    return(FREG_BM23_GetmEndianSwapRd_I2s1RdLittleEndian());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapRd_I2s0RdLittleEndian function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetmEndianSwapRd_I2s0RdLittleEndian
** \sa FREG_BM23_GetmEndianSwapRd_I2s0RdLittleEndian
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapRd_I2s0RdLittleEndian(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmEndianSwapRd_I2s0RdLittleEndian());
    return(FREG_BM23_GetmEndianSwapRd_I2s0RdLittleEndian());
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapWr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetEndianSwapWr
** \sa FREG_BM1_SetEndianSwapWr
** \sa FREG_BM2_SetEndianSwapWr
** \sa FREG_BM3_SetEndianSwapWr
**
********************************************************************************
*/
INLINE void bmSetEndianSwapWr(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetEndianSwapWr(value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetEndianSwapWr(value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetEndianSwapWr(value);
    else
        FREG_BM3_SetEndianSwapWr(value);
}

/*
********************************************************************************
**
** \brief bmSetEndianSwapWr_EndianSwapWr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_SetEndianSwapWr_Bm0EndianSwapWr
** \sa FREG_BM1_SetEndianSwapWr_Bm1EndianSwapWr
** \sa FREG_BM2_SetEndianSwapWr_Bm2EndianSwapWr
** \sa FREG_BM3_SetEndianSwapWr_Bm3EndianSwapWr
**
********************************************************************************
*/
INLINE void bmSetEndianSwapWr_EndianSwapWr(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_BM0)
        FREG_BM0_SetEndianSwapWr_Bm0EndianSwapWr(value);
    else if(blockIndex == FAPI_BM1)
        FREG_BM1_SetEndianSwapWr_Bm1EndianSwapWr(value);
    else if(blockIndex == FAPI_BM2)
        FREG_BM2_SetEndianSwapWr_Bm2EndianSwapWr(value);
    else
        FREG_BM3_SetEndianSwapWr_Bm3EndianSwapWr(value);
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapWr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetmEndianSwapWr
** \sa FREG_BM1_GetmEndianSwapWr
** \sa FREG_BM2_GetmEndianSwapWr
** \sa FREG_BM3_GetmEndianSwapWr
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapWr(uint32_t blockIndex)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetmEndianSwapWr());
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetmEndianSwapWr());
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetmEndianSwapWr());
    return(FREG_BM3_GetmEndianSwapWr());
}

/*
********************************************************************************
**
** \brief bmGetmEndianSwapWr_EndianSwapWr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM0_GetmEndianSwapWr_Bm0EndianSwapWr
** \sa FREG_BM1_GetmEndianSwapWr_Bm1EndianSwapWr
** \sa FREG_BM2_GetmEndianSwapWr_Bm2EndianSwapWr
** \sa FREG_BM3_GetmEndianSwapWr_Bm3EndianSwapWr
**
********************************************************************************
*/
INLINE uint32_t bmGetmEndianSwapWr_EndianSwapWr(uint32_t blockIndex)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM0_GetmEndianSwapWr_Bm0EndianSwapWr());
    if(blockIndex == FAPI_BM1)
        return(FREG_BM1_GetmEndianSwapWr_Bm1EndianSwapWr());
    if(blockIndex == FAPI_BM2)
        return(FREG_BM2_GetmEndianSwapWr_Bm2EndianSwapWr());
    return(FREG_BM3_GetmEndianSwapWr_Bm3EndianSwapWr());
}

/*
********************************************************************************
**
** \brief bmSetAudValue function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetAudValue
** \sa FREG_BM23_SetAudValue
**
********************************************************************************
*/
INLINE void bmSetAudValue(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetAudValue(index, value);
    else
        FREG_BM23_SetAudValue(index, value);
}

/*
********************************************************************************
**
** \brief bmSetAudCfgEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetAudCfgEn
** \sa FREG_BM23_SetAudCfgEn
**
********************************************************************************
*/
INLINE void bmSetAudCfgEn(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetAudCfgEn(value);
    else
        FREG_BM23_SetAudCfgEn(value);
}

/*
********************************************************************************
**
** \brief bmGetAudWrPointer function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetAudWrPointer
** \sa FREG_BM23_GetAudWrPointer
**
********************************************************************************
*/
INLINE uint32_t bmGetAudWrPointer(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetAudWrPointer(index));
    return(FREG_BM23_GetAudWrPointer(index));
}

/*
********************************************************************************
**
** \brief bmGetAudWrPointer_AudWritePointer function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetAudWrPointer_AudWritePointer
** \sa FREG_BM23_GetAudWrPointer_AudWritePointer
**
********************************************************************************
*/
INLINE uint32_t bmGetAudWrPointer_AudWritePointer(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetAudWrPointer_AudWritePointer(index));
    return(FREG_BM23_GetAudWrPointer_AudWritePointer(index));
}

/*
********************************************************************************
**
** \brief bmSetClearAudIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetClearAudIrq
** \sa FREG_BM23_SetClearAudIrq
**
********************************************************************************
*/
INLINE void bmSetClearAudIrq(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetClearAudIrq(value);
    else
        FREG_BM23_SetClearAudIrq(value);
}

/*
********************************************************************************
**
** \brief bmSetBufLowLev function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetBufLowLev
** \sa FREG_BM23_SetBufLowLev
**
********************************************************************************
*/
INLINE void bmSetBufLowLev(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetBufLowLev(index, value);
    else
        FREG_BM23_SetBufLowLev(index, value);
}

/*
********************************************************************************
**
** \brief bmSetBufLowLev_BufLowLevIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetBufLowLev_Bm01BufLowLevIrqEn
** \sa FREG_BM23_SetBufLowLev_Bm23BufLowLevIrqEn
**
********************************************************************************
*/
INLINE void bmSetBufLowLev_BufLowLevIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetBufLowLev_Bm01BufLowLevIrqEn(index, value);
    else
        FREG_BM23_SetBufLowLev_Bm23BufLowLevIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief bmGetBufLowLev_BufLowLevIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetBufLowLev_Bm01BufLowLevIrqEn
** \sa FREG_BM23_GetBufLowLev_Bm23BufLowLevIrqEn
**
********************************************************************************
*/
INLINE uint32_t bmGetBufLowLev_BufLowLevIrqEn(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetmBufLowLev_Bm01BufLowLevIrqEn(index));

    return(FREG_BM23_GetmBufLowLev_Bm23BufLowLevIrqEn(index));
}

/*
********************************************************************************
**
** \brief bmSetBufHighLev function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetBufHighLev
** \sa FREG_BM23_SetBufHighLev
**
********************************************************************************
*/
INLINE void bmSetBufHighLev(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetBufHighLev(index, value);
    else
        FREG_BM23_SetBufHighLev(index, value);
}

/*
********************************************************************************
**
** \brief bmSetBufHighLev_BufHighLevIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_SetBufHighLev_Bm01BufHighLevIrqEn
** \sa FREG_BM23_SetBufHighLev_Bm23BufHighLevIrqEn
**
********************************************************************************
*/
INLINE void bmSetBufHighLev_BufHighLevIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        FREG_BM01_SetBufHighLev_Bm01BufHighLevIrqEn(index, value);
    else
        FREG_BM23_SetBufHighLev_Bm23BufHighLevIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief bmGetBufHighLev_BufHighLevIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetBufHighLev_Bm01BufHighLevIrqEn
** \sa FREG_BM23_GetBufHighLev_Bm23BufHighLevIrqEn
**
********************************************************************************
*/
INLINE uint32_t bmGetBufHighLev_BufHighLevIrqEn(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetBufHighLev_Bm01BufHighLevIrqEn(index));

    return(FREG_BM23_GetBufHighLev_Bm23BufHighLevIrqEn(index));
}

/*
********************************************************************************
**
** \brief bmGetStatusRd function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd
** \sa FREG_BM23_GetStatusRd
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRd());
    return(FREG_BM23_GetStatusRd());
}

/*
********************************************************************************
**
** \brief bmGetStatusRd_BmStreamStatus function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd_BmStreamStatus
** \sa FREG_BM23_GetStatusRd_BmStreamStatus
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd_BmStreamStatus(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRd_BmStreamStatus());
    return(FREG_BM23_GetStatusRd_BmStreamStatus());
}

/*
********************************************************************************
**
** \brief bmGetStatusRd_AudIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd_AudIrq
** \sa FREG_BM23_GetStatusRd_AudIrq
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd_AudIrq(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRd_AudIrq());
    return(FREG_BM23_GetStatusRd_AudIrq());
}

/*
********************************************************************************
**
** \brief bmGetStatusRd_LevelIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd_LevelIrq
** \sa FREG_BM23_GetStatusRd_LevelIrq
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd_LevelIrq(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRd_LevelIrq());
    return(FREG_BM23_GetStatusRd_LevelIrq());
}

/*
********************************************************************************
**
** \brief bmGetStatusRd_Int function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd_Bm0Int
** \sa FREG_BM01_GetStatusRd_Bm1Int
** \sa FREG_BM23_GetStatusRd_Bm2Int
** \sa FREG_BM23_GetStatusRd_Bm3Int
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd_Int(uint32_t blockIndex)
{
    if(blockIndex == FAPI_BM0)
        return(FREG_BM01_GetStatusRd_Bm0Int());
    if(blockIndex == FAPI_BM1)
        return(FREG_BM01_GetStatusRd_Bm1Int());
    if(blockIndex == FAPI_BM2)
        return(FREG_BM23_GetStatusRd_Bm2Int());
    return(FREG_BM23_GetStatusRd_Bm3Int());
}

/*
********************************************************************************
**
** \brief bmGetStatusRd_BufferLowIrqFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd_BufferLowIrqFlag
** \sa FREG_BM23_GetStatusRd_BufferLowIrqFlag
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd_BufferLowIrqFlag(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRd_BufferLowIrqFlag());
    return(FREG_BM23_GetStatusRd_BufferLowIrqFlag());
}

/*
********************************************************************************
**
** \brief bmGetStatusRd_BufferHighIrqFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRd_BufferHighIrqFlag
** \sa FREG_BM23_GetStatusRd_BufferHighIrqFlag
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRd_BufferHighIrqFlag(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRd_BufferHighIrqFlag());
    return(FREG_BM23_GetStatusRd_BufferHighIrqFlag());
}

/*
********************************************************************************
**
** \brief bmGetStatusRdClr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetStatusRdClr
** \sa FREG_BM23_GetStatusRdClr
**
********************************************************************************
*/
INLINE uint32_t bmGetStatusRdClr(uint32_t blockIndex)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetStatusRdClr());
    return(FREG_BM23_GetStatusRdClr());
}

/*
********************************************************************************
**
** \brief bmExtractStatusRdClr_LevelIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_ExtractStatusRdClr_LevelIrq
** \sa FREG_BM23_ExtractStatusRdClr_LevelIrq
**
********************************************************************************
*/
INLINE uint32_t bmExtractStatusRdClr_LevelIrq(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_ExtractStatusRdClr_LevelIrq(value));
    return(FREG_BM23_ExtractStatusRdClr_LevelIrq(value));
}

/*
********************************************************************************
**
** \brief bmExtractStatusRdClr_BufferLowIrqFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_ExtractStatusRdClr_BufferLowIrqFlag
** \sa FREG_BM23_ExtractStatusRdClr_BufferLowIrqFlag
**
********************************************************************************
*/
INLINE uint32_t bmExtractStatusRdClr_BufferLowIrqFlag(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_ExtractStatusRdClr_BufferLowIrqFlag(value));
    return(FREG_BM23_ExtractStatusRdClr_BufferLowIrqFlag(value));
}

/*
********************************************************************************
**
** \brief bmExtractStatusRdClr_BufferHighIrqFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_ExtractStatusRdClr_BufferHighIrqFlag
** \sa FREG_BM23_ExtractStatusRdClr_BufferHighIrqFlag
**
********************************************************************************
*/
INLINE uint32_t bmExtractStatusRdClr_BufferHighIrqFlag(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_ExtractStatusRdClr_BufferHighIrqFlag(value));
    return(FREG_BM23_ExtractStatusRdClr_BufferHighIrqFlag(value));
}

/*
********************************************************************************
**
** \brief bmGetBufHighLevIrqClr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetBufHighLevIrqClr
** \sa FREG_BM23_GetBufHighLevIrqClr
**
********************************************************************************
*/
INLINE uint32_t bmGetBufHighLevIrqClr(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetBufHighLevIrqClr(index));
    return(FREG_BM23_GetBufHighLevIrqClr(index));
}

/*
********************************************************************************
**
** \brief bmGetBufHighLev_BufHighLevStreamNb function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetBufHighLev_Bm01BufHighLevStreamNb
** \sa FREG_BM23_GetBufHighLev_Bm23BufHighLevStreamNb
**
********************************************************************************
*/
INLINE uint32_t bmGetBufHighLev_BufHighLevStreamNb(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetBufHighLev_Bm01BufHighLevStreamNb(index));
    return(FREG_BM23_GetBufHighLev_Bm23BufHighLevStreamNb(index));
}

/*
********************************************************************************
**
** \brief bmGetBufLowLevIrqClr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetBufLowLevIrqClr
** \sa FREG_BM23_GetBufLowLevIrqClr
**
********************************************************************************
*/
INLINE uint32_t bmGetBufLowLevIrqClr(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetBufLowLevIrqClr(index));
    return(FREG_BM23_GetBufLowLevIrqClr(index));
}

/*
********************************************************************************
**
** \brief bmGetBufStreamIrqClr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_BM01_GetBufStreamIrqClr
** \sa FREG_BM23_GetBufStreamIrqClr
**
********************************************************************************
*/
INLINE uint32_t bmGetBufStreamIrqClr(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_BM0) || (blockIndex == FAPI_BM1))
        return(FREG_BM01_GetBufStreamIrqClr(index));
    return(FREG_BM23_GetBufStreamIrqClr(index));
}

#endif
