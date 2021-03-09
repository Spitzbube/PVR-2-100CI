/*
********************************************************************************
**
** \file        ./fapi/drv/tsd/src/drv_tsd_priv.h
**
** \brief       Private TSD Driver functions.
**
** This file contains private register functions of the TSD driver.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_TSD_PRIV_H
    #define FAPI_TSD_PRIV_H

    #include <fapi/reg_tsd.h>


/*
********************************************************************************
**
** \brief tsdExtractIrq_FilterTargetIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_ExtractIrq_FilterTargetIndex
** \sa FREG_TSD23_ExtractIrq_FilterTargetIndex
**
********************************************************************************
*/
INLINE uint32_t tsdExtractIrq_FilterTargetIndex(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_ExtractIrq_FilterTargetIndex(value));
    return(FREG_TSD23_ExtractIrq_FilterTargetIndex(value));
}

/*
********************************************************************************
**
** \brief tsdExtractIrq_IrqAvailable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_ExtractIrq_IrqAvailable
** \sa FREG_TSD23_ExtractIrq_IrqAvailable
**
********************************************************************************
*/
INLINE uint32_t tsdExtractIrq_IrqAvailable(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_ExtractIrq_IrqAvailable(value));
    return(FREG_TSD23_ExtractIrq_IrqAvailable(value));
}

/*
********************************************************************************
**
** \brief tsdExtractIrq_IrqValue function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_ExtractIrq_IrqValue
** \sa FREG_TSD23_ExtractIrq_IrqValue
**
********************************************************************************
*/
INLINE uint32_t tsdExtractIrq_IrqValue(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_ExtractIrq_IrqValue(value));
    return(FREG_TSD23_ExtractIrq_IrqValue(value));
}

/*
********************************************************************************
**
** \brief tsdExtractIrq_PidIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_ExtractIrq_PidIndex
** \sa FREG_TSD23_ExtractIrq_PidIndex
**
********************************************************************************
*/
INLINE uint32_t tsdExtractIrq_PidIndex(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_ExtractIrq_PidIndex(value));
    return(FREG_TSD23_ExtractIrq_PidIndex(value));
}

/*
********************************************************************************
**
** \brief tsdExtractIrq_PidIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_ExtractIrq_Tsd1Select
** \sa FREG_TSD23_ExtractIrq_Tsd3Select
**
********************************************************************************
*/
INLINE uint32_t tsdExtractIrq_Tsd13Select(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_ExtractIrq_Tsd1Select(value));
    return(FREG_TSD23_ExtractIrq_Tsd3Select(value));
}

/*
********************************************************************************
**
** \brief tsdGetCurrentStcLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetCurrentStcLower
** \sa FREG_TSD23_GetCurrentStcLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetCurrentStcLower(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetCurrentStcLower());
    return(FREG_TSD23_GetCurrentStcLower());
}

/*
********************************************************************************
**
** \brief tsdGetCurrentStcLower_CurrentStcBaseLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetCurrentStcLower_CurrentStcBaseLower
** \sa FREG_TSD23_GetCurrentStcLower_CurrentStcBaseLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetCurrentStcLower_CurrentStcBaseLower(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetCurrentStcLower_CurrentStcBaseLower());
    return(FREG_TSD23_GetCurrentStcLower_CurrentStcBaseLower());
}

/*
********************************************************************************
**
** \brief tsdGetCurrentStcLower_CurrentStcExt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetCurrentStcLower_CurrentStcExt
** \sa FREG_TSD23_GetCurrentStcLower_CurrentStcExt
**
********************************************************************************
*/
INLINE uint32_t tsdGetCurrentStcLower_CurrentStcExt(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetCurrentStcLower_CurrentStcExt());
    return(FREG_TSD23_GetCurrentStcLower_CurrentStcExt());
}

/*
********************************************************************************
**
** \brief tsdGetCurrentStcUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetCurrentStcUpper
** \sa FREG_TSD23_GetCurrentStcUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetCurrentStcUpper(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetCurrentStcUpper());
    return(FREG_TSD23_GetCurrentStcUpper());
}

/*
********************************************************************************
**
** \brief tsdGetCurrentStcUpper_CurrentStcBaseUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetCurrentStcUpper_CurrentStcBaseUpper
** \sa FREG_TSD23_GetCurrentStcUpper_CurrentStcBaseUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetCurrentStcUpper_CurrentStcBaseUpper(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetCurrentStcUpper_CurrentStcBaseUpper());
    return(FREG_TSD23_GetCurrentStcUpper_CurrentStcBaseUpper());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl
** \sa FREG_TSD23_GetInputCtrl
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl());
    return(FREG_TSD23_GetInputCtrl());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts0AmSync function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts0AmSync
** \sa FREG_TSD23_GetInputCtrl_Ts2AmSync
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts02AmSync(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts0AmSync());
    return(FREG_TSD23_GetInputCtrl_Ts2AmSync());
}

/*
********************************************************************************
**
** \brief tsdetInputCtrl_Ts02Clk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts0Clk
** \sa FREG_TSD23_GetInputCtrl_Ts2Clk
**
********************************************************************************
*/
INLINE uint32_t tsdetInputCtrl_Ts02Clk(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts0Clk());
    return(FREG_TSD23_GetInputCtrl_Ts2Clk());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts02En function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts0En
** \sa FREG_TSD23_GetInputCtrl_Ts0En
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts02En(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts0En());
    return(FREG_TSD23_GetInputCtrl_Ts2En());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts02PacketStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts0PacketStart
** \sa FREG_TSD23_GetInputCtrl_Ts2PacketStart
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts02PacketStart(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts0PacketStart());
    return(FREG_TSD23_GetInputCtrl_Ts2PacketStart());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts02SerialParallelMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts0SerialParallelMode
** \sa FREG_TSD23_GetInputCtrl_Ts2SerialParallelMode
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts02SerialParallelMode(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts0SerialParallelMode());
    return(FREG_TSD23_GetInputCtrl_Ts2SerialParallelMode());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts13AmSync function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts1AmSync
** \sa FREG_TSD23_GetInputCtrl_Ts3AmSync
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts13AmSync(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts1AmSync());
    return(FREG_TSD23_GetInputCtrl_Ts3AmSync());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts13Clk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts1Clk
** \sa FREG_TSD23_GetInputCtrl_Ts3Clk
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts13Clk(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts1Clk());
    return(FREG_TSD23_GetInputCtrl_Ts3Clk());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts13En function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts1En
** \sa FREG_TSD23_GetInputCtrl_Ts3En
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts13En(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts1En());
    return(FREG_TSD23_GetInputCtrl_Ts3En());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts13PacketStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts1PacketStart
** \sa FREG_TSD23_GetInputCtrl_Ts3PacketStart
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts13PacketStart(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts1PacketStart());
    return(FREG_TSD23_GetInputCtrl_Ts3PacketStart());
}

/*
********************************************************************************
**
** \brief tsdGetInputCtrl_Ts13SerialParallelMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputCtrl_Ts1SerialParallelMode
** \sa FREG_TSD23_GetInputCtrl_Ts3SerialParallelMode
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputCtrl_Ts13SerialParallelMode(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputCtrl_Ts1SerialParallelMode());
    return(FREG_TSD23_GetInputCtrl_Ts3SerialParallelMode());
}

/*
********************************************************************************
**
** \brief tsdGetInputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputTimeout
** \sa FREG_TSD23_GetInputTimeout
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputTimeout(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputTimeout());
    return(FREG_TSD23_GetInputTimeout());
}

/*
********************************************************************************
**
** \brief tsdGetInputTimeout_InputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInputTimeout_InputTimeout
** \sa FREG_TSD23_GetInputTimeout_InputTimeout
**
********************************************************************************
*/
INLINE uint32_t tsdGetInputTimeout_InputTimeout(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInputTimeout_InputTimeout());
    return(FREG_TSD23_GetInputTimeout_InputTimeout());
}

/*
********************************************************************************
**
** \brief tsdGetInRamCfg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInRamCfg
** \sa FREG_TSD23_GetInRamCfg
**
********************************************************************************
*/
INLINE uint32_t tsdGetInRamCfg(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInRamCfg());
    return(FREG_TSD23_GetInRamCfg());
}

/*
********************************************************************************
**
** \brief tsdGetInRamCfg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInRamCfg_DisableTsInput0
** \sa FREG_TSD01_GetInRamCfg_DisableTsInput1
** \sa FREG_TSD23_GetInRamCfg_DisableTsInput2
** \sa FREG_TSD23_GetInRamCfg_DisableTsInput3
**
********************************************************************************
*/
INLINE uint32_t tsdGetInRamCfg_DisableTsInput(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD01_GetInRamCfg_DisableTsInput0());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD01_GetInRamCfg_DisableTsInput1());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD23_GetInRamCfg_DisableTsInput2());

    return(FREG_TSD23_GetInRamCfg_DisableTsInput3());
}

/*
********************************************************************************
**
** \brief tsdGetInRamCfg_GenerateSyncSignal function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInRamCfg_GenerateSyncSignal
** \sa FREG_TSD23_GetInRamCfg_GenerateSyncSignal
**
********************************************************************************
*/
INLINE uint32_t tsdGetInRamCfg_GenerateSyncSignal(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInRamCfg_GenerateSyncSignal());
    return(FREG_TSD23_GetInRamCfg_GenerateSyncSignal());
}

/*
********************************************************************************
**
** \brief tsdGetInRamCfg_InvertTsOutClk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInRamCfg_InvertTsOutClk
** \sa FREG_TSD23_GetInRamCfg_InvertTsOutClk
**
********************************************************************************
*/
INLINE uint32_t tsdGetInRamCfg_InvertTsOutClk(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInRamCfg_InvertTsOutClk());
    return(FREG_TSD23_GetInRamCfg_InvertTsOutClk());
}

/*
********************************************************************************
**
** \brief tsdGetInRamCfg_InvertTsOutClk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInRamCfg_TsOutClkPrescaler
** \sa FREG_TSD23_GetInRamCfg_TsOutClkPrescaler
**
********************************************************************************
*/
INLINE uint32_t tsdGetInRamCfg_TsOutClkPrescaler(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInRamCfg_TsOutClkPrescaler());
    return(FREG_TSD23_GetInRamCfg_TsOutClkPrescaler());
}

/*
********************************************************************************
**
** \brief tsdGetInRamCfg_TsOutMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetInRamCfg_TsOutMode
** \sa FREG_TSD23_GetInRamCfg_TsOutMode
**
********************************************************************************
*/
INLINE uint32_t tsdGetInRamCfg_TsOutMode(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetInRamCfg_TsOutMode());
    return(FREG_TSD23_GetInRamCfg_TsOutMode());
}

/*
********************************************************************************
**
** \brief tsdGetIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrq
** \sa FREG_TSD23_GetIrq
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrq(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrq());
    return(FREG_TSD23_GetIrq());
}

/*
********************************************************************************
**
** \brief tsdGetIrqDbg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg
** \sa FREG_TSD23_GetIrqDbg
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg(index));
    return(FREG_TSD23_GetIrqDbg(index));
}

/*
********************************************************************************
**
** \brief tsdGetIrqDbg_FilterTargetIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg_FilterTargetIndex
** \sa FREG_TSD23_GetIrqDbg_FilterTargetIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg_FilterTargetIndex(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg_FilterTargetIndex(index));
    return(FREG_TSD23_GetIrqDbg_FilterTargetIndex(index));
}

/*
********************************************************************************
**
** \brief tsdGetIrqDbg_IrqAvailable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg_IrqAvailable
** \sa FREG_TSD23_GetIrqDbg_IrqAvailable
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg_IrqAvailable(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg_IrqAvailable(index));
    return(FREG_TSD23_GetIrqDbg_IrqAvailable(index));
}


/*
********************************************************************************
**
** \brief tsdGetIrqDbg_IrqFifoOvf function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg_IrqFifoOvf
** \sa FREG_TSD23_GetIrqDbg_IrqFifoOvf
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg_IrqFifoOvf(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg_IrqFifoOvf(index));
    return(FREG_TSD23_GetIrqDbg_IrqFifoOvf(index));
}

/*
********************************************************************************
**
** \brief tsdGetIrqDbg_IrqValue function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg_IrqValue
** \sa FREG_TSD23_GetIrqDbg_IrqValue
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg_IrqValue(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg_IrqValue(index));
    return(FREG_TSD23_GetIrqDbg_IrqValue(index));
}

/*
********************************************************************************
**
** \brief tsdGetIrqDbg_PidIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg_PidIndex
** \sa FREG_TSD23_GetIrqDbg_PidIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg_PidIndex(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg_PidIndex(index));
    return(FREG_TSD23_GetIrqDbg_PidIndex(index));
}

/*
********************************************************************************
**
** \brief tsdGetIrqDbg_Tsd1Select function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqDbg_Tsd1Select
** \sa FREG_TSD23_GetIrqDbg_Tsd3Select
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqDbg_Tsd1Select(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqDbg_Tsd1Select(index));
    return(FREG_TSD23_GetIrqDbg_Tsd3Select(index));
}

/*
********************************************************************************
**
** \brief tsdGetIrqRdPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqRdPtr
** \sa FREG_TSD23_GetIrqRdPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqRdPtr(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqRdPtr());
    return(FREG_TSD23_GetIrqRdPtr());
}

/*
********************************************************************************
**
** \brief tsdGetIrqRdPtr_IrqRdPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqRdPtr_IrqRdPtr
** \sa FREG_TSD23_GetIrqRdPtr_IrqRdPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqRdPtr_IrqRdPtr(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqRdPtr_IrqRdPtr());
    return(FREG_TSD23_GetIrqRdPtr_IrqRdPtr());
}

/*
********************************************************************************
**
** \brief tsdGetIrqWrPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqWrPtr
** \sa FREG_TSD23_GetIrqWrPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqWrPtr(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqWrPtr());
    return(FREG_TSD23_GetIrqWrPtr());
}

/*
********************************************************************************
**
** \brief tsdGetIrqWrPtr_IrqWrPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetIrqWrPtr_IrqWrPtr
** \sa FREG_TSD23_GetIrqWrPtr_IrqWrPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetIrqWrPtr_IrqWrPtr(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetIrqWrPtr_IrqWrPtr());
    return(FREG_TSD23_GetIrqWrPtr_IrqWrPtr());
}

/*
********************************************************************************
**
** \brief tsdGetLoadPcr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetLoadPcr
** \sa FREG_TSD23_GetLoadPcr
**
********************************************************************************
*/
INLINE uint32_t tsdGetLoadPcr(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetLoadPcr());
    return(FREG_TSD23_GetLoadPcr());
}

/*
********************************************************************************
**
** \brief tsdGetLoadPcr_LoadPcrFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetLoadPcr_LoadPcrFlag
** \sa FREG_TSD23_GetLoadPcr_LoadPcrFlag
**
********************************************************************************
*/
INLINE uint32_t tsdGetLoadPcr_LoadPcrFlag(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetLoadPcr_LoadPcrFlag());
    return(FREG_TSD23_GetLoadPcr_LoadPcrFlag());
}

/*
********************************************************************************
**
** \brief tsdGetmIrqClear function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetmIrqClear
** \sa FREG_TSD23_GetmIrqClear
**
********************************************************************************
*/
INLINE uint32_t tsdGetmIrqClear(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetmIrqClear());
    return(FREG_TSD23_GetmIrqClear());
}

/*
********************************************************************************
**
** \brief tsdGetmIrqClear_ClearAllIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetmIrqClear_ClearAllIrq
** \sa FREG_TSD23_GetmIrqClear_ClearAllIrq
**
********************************************************************************
*/
INLINE uint32_t tsdGetmIrqClear_ClearAllIrq(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetmIrqClear_ClearAllIrq());
    return(FREG_TSD23_GetmIrqClear_ClearAllIrq());
}

/*
********************************************************************************
**
** \brief tsdGetPacketCounter function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketCounter
** \sa FREG_TSD23_GetPacketCounter
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCounter(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketCounter());
    return(FREG_TSD23_GetPacketCounter());
}

/*
********************************************************************************
**
** \brief tsdGetPacketCounter_PacketCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketCounter_PacketCnt
** \sa FREG_TSD23_GetPacketCounter_PacketCnt
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCounter_PacketCnt(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketCounter_PacketCnt());
    return(FREG_TSD23_GetPacketCounter_PacketCnt());
}

/*
********************************************************************************
**
** \brief tsdGetPacketStc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketStc
** \sa FREG_TSD23_GetPacketStc
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketStc(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketStc());
    return(FREG_TSD23_GetPacketStc());
}

/*
********************************************************************************
**
** \brief tsdGetPacketStc_PacketStcBase function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketStc_PacketStcBase
** \sa FREG_TSD23_GetPacketStc_PacketStcBase
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketStc_PacketStcBase(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketStc_PacketStcBase());
    return(FREG_TSD23_GetPacketStc_PacketStcBase());
}

/*
********************************************************************************
**
** \brief tsdGetPacketStc_PacketStcExt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketStc_PacketStcExt
** \sa FREG_TSD23_GetPacketStc_PacketStcExt
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketStc_PacketStcExt(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketStc_PacketStcExt());
    return(FREG_TSD23_GetPacketStc_PacketStcExt());
}

/*
********************************************************************************
**
** \brief tsdGetPacketStcMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketStcMode
** \sa FREG_TSD23_GetPacketStcMode
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketStcMode(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketStcMode());
    return(FREG_TSD23_GetPacketStcMode());
}

/*
********************************************************************************
**
** \brief tsdGetPacketStcMode_StoreAllPacketStc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPacketStcMode_StoreAllPacketStc
** \sa FREG_TSD23_GetPacketStcMode_StoreAllPacketStc
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketStcMode_StoreAllPacketStc(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPacketStcMode_StoreAllPacketStc());
    return(FREG_TSD23_GetPacketStcMode_StoreAllPacketStc());
}

/*
********************************************************************************
**
** \brief tsdGetPcrLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPcrLower
** \sa FREG_TSD23_GetPcrLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetPcrLower(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPcrLower());
    return(FREG_TSD23_GetPcrLower());
}

/*
********************************************************************************
**
** \brief tsdGetPcrLower_PcrBaseLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPcrLower_PcrBaseLower
** \sa FREG_TSD23_GetPcrLower_PcrBaseLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetPcrLower_PcrBaseLower(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPcrLower_PcrBaseLower());
    return(FREG_TSD23_GetPcrLower_PcrBaseLower());
}

/*
********************************************************************************
**
** \brief tsdGetPcrLower_PcrExt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPcrLower_PcrExt
** \sa FREG_TSD23_GetPcrLower_PcrExt
**
********************************************************************************
*/
INLINE uint32_t tsdGetPcrLower_PcrExt(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPcrLower_PcrExt());
    return(FREG_TSD23_GetPcrLower_PcrExt());
}

/*
********************************************************************************
**
** \brief tsdGetPcrUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPcrUpper
** \sa FREG_TSD23_GetPcrUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetPcrUpper(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPcrUpper());
    return(FREG_TSD23_GetPcrUpper());
}

/*
********************************************************************************
**
** \brief tsdGetPcrUpper_PcrBaseUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPcrUpper_PcrBaseUpper
** \sa FREG_TSD23_GetPcrUpper_PcrBaseUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetPcrUpper_PcrBaseUpper(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPcrUpper_PcrBaseUpper());
    return(FREG_TSD23_GetPcrUpper_PcrBaseUpper());
}

/*
********************************************************************************
**
** \brief tsdGetPesCfg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPesCfg
** \sa FREG_TSD23_GetPesCfg
**
********************************************************************************
*/
INLINE uint32_t tsdGetPesCfg(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPesCfg(index));
    return(FREG_TSD23_GetPesCfg(index));
}

/*
********************************************************************************
**
** \brief tsdGetPesCfg_NewPtsIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPesCfg_NewPtsIrqEn
** \sa FREG_TSD23_GetPesCfg_NewPtsIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetPesCfg_NewPtsIrqEn(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPesCfg_NewPtsIrqEn(index));
    return(FREG_TSD23_GetPesCfg_NewPtsIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetPesCfg_PesEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPesCfg_PesEn
** \sa FREG_TSD23_GetPesCfg_PesEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetPesCfg_PesEn(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPesCfg_PesEn(index));
    return(FREG_TSD23_GetPesCfg_PesEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetPesCfg_PidIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPesCfg_PidIndex
** \sa FREG_TSD23_GetPesCfg_PidIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetPesCfg_PidIndex(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPesCfg_PidIndex(index));
    return(FREG_TSD23_GetPesCfg_PidIndex(index));
}

/*
********************************************************************************
**
** \brief tsdGetPesCfg_RemovePesHeader function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPesCfg_RemovePesHeader
** \sa FREG_TSD23_GetPesCfg_RemovePesHeader
**
********************************************************************************
*/
INLINE uint32_t tsdGetPesCfg_RemovePesHeader(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPesCfg_RemovePesHeader(index));
    return(FREG_TSD23_GetPesCfg_RemovePesHeader(index));
}

/*
********************************************************************************
**
** \brief tsdGetPesCfg_Tsd13Select function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPesCfg_Tsd1Select
** \sa FREG_TSD23_GetPesCfg_Tsd3Select
**
********************************************************************************
*/
INLINE uint32_t tsdGetPesCfg_Tsd13Select(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPesCfg_Tsd1Select(index));
    return(FREG_TSD23_GetPesCfg_Tsd3Select(index));
}

/*
********************************************************************************
**
** \brief tsdGetPts_0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPts_0
** \sa FREG_TSD23_GetPts_0
**
********************************************************************************
*/
INLINE uint32_t tsdGetPts_0(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPts_0(index));
    return(FREG_TSD23_GetPts_0(index));
}

/*
********************************************************************************
**
** \brief tsdGetPts_0_PtsLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPts_0_PtsLower
** \sa FREG_TSD23_GetPts_0_PtsLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetPts_0_PtsLower(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPts_0_PtsLower(index));
    return(FREG_TSD23_GetPts_0_PtsLower(index));
}

/*
********************************************************************************
**
** \brief tsdGetPts_1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPts_1
** \sa FREG_TSD23_GetPts_1
**
********************************************************************************
*/
INLINE uint32_t tsdGetPts_1(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPts_1(index));
    return(FREG_TSD23_GetPts_1(index));
}

/*
********************************************************************************
**
** \brief tsdGetPts_1_PtsMsb function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetPts_1_PtsMsb
** \sa FREG_TSD23_GetPts_1_PtsMsb
**
********************************************************************************
*/
INLINE uint32_t tsdGetPts_1_PtsMsb(uint32_t blockIndex, uint32_t index)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetPts_1_PtsMsb(index));
    return(FREG_TSD23_GetPts_1_PtsMsb(index));
}

/*
********************************************************************************
**
** \brief tsdGetReadSignalDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetReadSignalDistance
** \sa FREG_TSD23_GetReadSignalDistance
**
********************************************************************************
*/
INLINE uint32_t tsdGetReadSignalDistance(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetReadSignalDistance());
    return(FREG_TSD23_GetReadSignalDistance());
}

/*
********************************************************************************
**
** \brief tsdGetReadSignalDistance_RdSignalDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetReadSignalDistance_RdSignalDistance
** \sa FREG_TSD23_GetReadSignalDistance_RdSignalDistance
**
********************************************************************************
*/
INLINE uint32_t tsdGetReadSignalDistance_RdSignalDistance(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetReadSignalDistance_RdSignalDistance());
    return(FREG_TSD23_GetReadSignalDistance_RdSignalDistance());
}

/*
********************************************************************************
**
** \brief tsdGetStartDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStartDistance
** \sa FREG_TSD23_GetStartDistance
**
********************************************************************************
*/
INLINE uint32_t tsdGetStartDistance(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStartDistance());
    return(FREG_TSD23_GetStartDistance());
}

/*
********************************************************************************
**
** \brief tsdGetStartDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStartDistance_Ts0StartDistance
** \sa FREG_TSD23_GetStartDistance_Ts2StartDistance
**
********************************************************************************
*/
INLINE uint32_t tsdGetStartDistance_Ts02StartDistance(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStartDistance_Ts0StartDistance());
    return(FREG_TSD23_GetStartDistance_Ts2StartDistance());
}

/*
********************************************************************************
**
** \brief tsdGetStartDistance_Ts3StartDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStartDistance_Ts1StartDistance
** \sa FREG_TSD23_GetStartDistance_Ts3StartDistance
**
********************************************************************************
*/
INLINE uint32_t tsdGetStartDistance_Ts3StartDistance(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStartDistance_Ts1StartDistance());
    return(FREG_TSD23_GetStartDistance_Ts3StartDistance());
}

/*
********************************************************************************
**
** \brief tsdGetStatus function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStatus
** \sa FREG_TSD23_GetStatus
**
********************************************************************************
*/
INLINE uint32_t tsdGetStatus(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStatus());
    return(FREG_TSD23_GetStatus());
}

/*
********************************************************************************
**
** \brief tsdGetStatus_PidIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStatus_PidIndex
** \sa FREG_TSD23_GetStatus_PidIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetStatus_PidIndex(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStatus_PidIndex());
    return(FREG_TSD23_GetStatus_PidIndex());
}

/*
********************************************************************************
**
** \brief tsdGetStatus_PidMatch function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStatus_PidMatch
** \sa FREG_TSD23_GetStatus_PidMatch
**
********************************************************************************
*/
INLINE uint32_t tsdGetStatus_PidMatch(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStatus_PidMatch());
    return(FREG_TSD23_GetStatus_PidMatch());
}

/*
********************************************************************************
**
** \brief tsdGetStatus_PidMatchValid function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStatus_PidMatchValid
** \sa FREG_TSD23_GetStatus_PidMatchValid
**
********************************************************************************
*/
INLINE uint32_t tsdGetStatus_PidMatchValid(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStatus_PidMatchValid());
    return(FREG_TSD23_GetStatus_PidMatchValid());
}

/*
********************************************************************************
**
** \brief tsdGetStatus_Tsd1Select function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStatus_Tsd1Select
** \sa FREG_TSD23_GetStatus_Tsd3Select
**
********************************************************************************
*/
INLINE uint32_t tsdGetStatus_Tsd13Select(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStatus_Tsd1Select());
    return(FREG_TSD23_GetStatus_Tsd3Select());
}

/*
********************************************************************************
**
** \brief tsdGetStatus_TsdActive function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetStatus_TsdActive
** \sa FREG_TSD23_GetStatus_TsdActive
**
********************************************************************************
*/
INLINE uint32_t tsdGetStatus_TsdActive(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetStatus_TsdActive());
    return(FREG_TSD23_GetStatus_TsdActive());
}

/*
********************************************************************************
**
** \brief tsdGetValidInputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetValidInputTimeout
** \sa FREG_TSD23_GetValidInputTimeout
**
********************************************************************************
*/
INLINE uint32_t tsdGetValidInputTimeout(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetValidInputTimeout());
    return(FREG_TSD23_GetValidInputTimeout());
}

/*
********************************************************************************
**
** \brief tsdGetValidInputTimeout_ValidInputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetValidInputTimeout_ValidInputTimeout
** \sa FREG_TSD23_GetValidInputTimeout_ValidInputTimeout
**
********************************************************************************
*/
INLINE uint32_t tsdGetValidInputTimeout_ValidInputTimeout(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetValidInputTimeout_ValidInputTimeout());
    return(FREG_TSD23_GetValidInputTimeout_ValidInputTimeout());
}

/*
********************************************************************************
**
** \brief tsdGetValidPacketCounter function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetValidPacketCounter
** \sa FREG_TSD23_GetValidPacketCounter
**
********************************************************************************
*/
INLINE uint32_t tsdGetValidPacketCounter(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetValidPacketCounter());
    return(FREG_TSD23_GetValidPacketCounter());
}

/*
********************************************************************************
**
** \brief tsdGetValidPacketCounter_ValidPacketCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_GetValidPacketCounter_ValidPacketCnt
** \sa FREG_TSD23_GetValidPacketCounter_ValidPacketCnt
**
********************************************************************************
*/
INLINE uint32_t tsdGetValidPacketCounter_ValidPacketCnt(uint32_t blockIndex)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        return(FREG_TSD01_GetValidPacketCounter_ValidPacketCnt());
    return(FREG_TSD23_GetValidPacketCounter_ValidPacketCnt());
}

/*
********************************************************************************
**
** \brief tsdSetCurrentStcLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetCurrentStcLower
** \sa FREG_TSD23_SetCurrentStcLower
**
********************************************************************************
*/
INLINE void tsdSetCurrentStcLower(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetCurrentStcLower(value);
    else
        FREG_TSD23_SetCurrentStcLower(value);
}

/*
********************************************************************************
**
** \brief tsdSetCurrentStcLower_CurrentStcBaseLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetCurrentStcLower_CurrentStcBaseLower
** \sa FREG_TSD23_SetCurrentStcLower_CurrentStcBaseLower
**
********************************************************************************
*/
INLINE void tsdSetCurrentStcLower_CurrentStcBaseLower(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetCurrentStcLower_CurrentStcBaseLower(value);
    else
        FREG_TSD23_SetCurrentStcLower_CurrentStcBaseLower(value);
}

/*
********************************************************************************
**
** \brief tsdSetCurrentStcLower_CurrentStcExt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetCurrentStcLower_CurrentStcExt
** \sa FREG_TSD23_SetCurrentStcLower_CurrentStcExt
**
********************************************************************************
*/
INLINE void tsdSetCurrentStcLower_CurrentStcExt(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetCurrentStcLower_CurrentStcExt(value);
    else
        FREG_TSD23_SetCurrentStcLower_CurrentStcExt(value);
}

/*
********************************************************************************
**
** \brief tsdSetCurrentStcUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetCurrentStcUpper
** \sa FREG_TSD23_SetCurrentStcUpper
**
********************************************************************************
*/
INLINE void tsdSetCurrentStcUpper(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetCurrentStcUpper(value);
    else
        FREG_TSD23_SetCurrentStcUpper(value);
}

/*
********************************************************************************
**
** \brief tsdSetCurrentStcUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetCurrentStcUpper_CurrentStcBaseUpper
** \sa FREG_TSD23_SetCurrentStcUpper_CurrentStcBaseUpper
**
********************************************************************************
*/
INLINE void tsdSetCurrentStcUpper_CurrentStcBaseUpper(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetCurrentStcUpper_CurrentStcBaseUpper(value);
    else
        FREG_TSD23_SetCurrentStcUpper_CurrentStcBaseUpper(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl
** \sa FREG_TSD23_SetInputCtrl
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl(value);
    else
        FREG_TSD23_SetInputCtrl(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts0AmSync
** \sa FREG_TSD23_SetInputCtrl_Ts2AmSync
**
********************************************************************************
*/
INLINE void FREG_TSD01_SetInputCtrl_Ts02AmSync(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts0AmSync(value);
    else
        FREG_TSD23_SetInputCtrl_Ts2AmSync(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts02Clk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts0Clk
** \sa FREG_TSD23_SetInputCtrl_Ts2Clk
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts02Clk(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts0Clk(value);
    else
        FREG_TSD23_SetInputCtrl_Ts2Clk(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts02En function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts0En
** \sa FREG_TSD23_SetInputCtrl_Ts0En
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts02En(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts0En(value);
    else
        FREG_TSD23_SetInputCtrl_Ts2En(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts02PacketStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts0PacketStart
** \sa FREG_TSD23_SetInputCtrl_Ts2PacketStart
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts02PacketStart(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts0PacketStart(value);
    else
        FREG_TSD23_SetInputCtrl_Ts2PacketStart(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts02SerialParallelMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts0SerialParallelMode
** \sa FREG_TSD23_SetInputCtrl_Ts2SerialParallelMode
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts02SerialParallelMode(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts0SerialParallelMode(value);
    else
        FREG_TSD23_SetInputCtrl_Ts2SerialParallelMode(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts13AmSync function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts1AmSync
** \sa FREG_TSD23_SetInputCtrl_Ts3AmSync
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts13AmSync(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts1AmSync(value);
    else
        FREG_TSD23_SetInputCtrl_Ts3AmSync(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts13Clk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts1Clk
** \sa FREG_TSD23_SetInputCtrl_Ts3Clk
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts13Clk(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts1Clk(value);
    else
        FREG_TSD23_SetInputCtrl_Ts3Clk(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts13En function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts1En
** \sa FREG_TSD23_SetInputCtrl_Ts3En
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts13En(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts1En(value);
    else
        FREG_TSD23_SetInputCtrl_Ts3En(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts13PacketStart function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts1PacketStart
** \sa FREG_TSD23_SetInputCtrl_Ts3PacketStart
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts13PacketStart(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts1PacketStart(value);
    else
        FREG_TSD23_SetInputCtrl_Ts3PacketStart(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputCtrl_Ts13SerialParallelMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputCtrl_Ts1SerialParallelMode
** \sa FREG_TSD23_SetInputCtrl_Ts3SerialParallelMode
**
********************************************************************************
*/
INLINE void tsdSetInputCtrl_Ts13SerialParallelMode(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputCtrl_Ts1SerialParallelMode(value);
    else
        FREG_TSD23_SetInputCtrl_Ts3SerialParallelMode(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputTimeout
** \sa FREG_TSD23_SetInputTimeout
**
********************************************************************************
*/
INLINE void tsdSetInputTimeout(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputTimeout(value);
    else
        FREG_TSD23_SetInputTimeout(value);
}

/*
********************************************************************************
**
** \brief tsdSetInputTimeout_InputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInputTimeout_InputTimeout
** \sa FREG_TSD23_SetInputTimeout_InputTimeout
**
********************************************************************************
*/
INLINE void tsdSetInputTimeout_InputTimeout(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInputTimeout_InputTimeout(value);
    else
        FREG_TSD23_SetInputTimeout_InputTimeout(value);
}

/*
********************************************************************************
**
** \brief tsdSetInRamCfg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInRamCfg
** \sa FREG_TSD23_SetInRamCfg
**
********************************************************************************
*/
INLINE void tsdSetInRamCfg(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInRamCfg(value);
    else
        FREG_TSD23_SetInRamCfg(value);
}

/*
********************************************************************************
**
** \brief tsdSetInRamCfg_DisableTsInput02 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInRamCfg_DisableTsInput0
** \sa FREG_TSD01_SetInRamCfg_DisableTsInput1
** \sa FREG_TSD23_SetInRamCfg_DisableTsInput2
** \sa FREG_TSD23_SetInRamCfg_DisableTsInput3
**
********************************************************************************
*/
INLINE void tsdSetInRamCfg_DisableTsInput(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD01_SetInRamCfg_DisableTsInput0(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD01_SetInRamCfg_DisableTsInput1(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD23_SetInRamCfg_DisableTsInput2(value);
    else if(blockIndex == FAPI_TSD3)
        FREG_TSD23_SetInRamCfg_DisableTsInput3(value);
}

/*
********************************************************************************
**
** \brief tsdSetInRamCfg_GenerateSyncSignal function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInRamCfg_GenerateSyncSignal
** \sa FREG_TSD23_SetInRamCfg_GenerateSyncSignal
**
********************************************************************************
*/
INLINE void tsdSetInRamCfg_GenerateSyncSignal(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInRamCfg_GenerateSyncSignal(value);
    else
        FREG_TSD23_SetInRamCfg_GenerateSyncSignal(value);
}

/*
********************************************************************************
**
** \brief tsdSetInRamCfg_InvertTsOutClk function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInRamCfg_InvertTsOutClk
** \sa FREG_TSD23_SetInRamCfg_InvertTsOutClk
**
********************************************************************************
*/
INLINE void tsdSetInRamCfg_InvertTsOutClk(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInRamCfg_InvertTsOutClk(value);
    else
        FREG_TSD23_SetInRamCfg_InvertTsOutClk(value);
}

/*
********************************************************************************
**
** \brief tsdSetInRamCfg_TsOutClkPrescaler function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInRamCfg_TsOutClkPrescaler
** \sa FREG_TSD23_SetInRamCfg_TsOutClkPrescaler
**
********************************************************************************
*/
INLINE void tsdSetInRamCfg_TsOutClkPrescaler(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInRamCfg_TsOutClkPrescaler(value);
    else
        FREG_TSD23_SetInRamCfg_TsOutClkPrescaler(value);
}

/*
********************************************************************************
**
** \brief tsdSetInRamCfg_TsOutMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetInRamCfg_TsOutMode
** \sa FREG_TSD23_SetInRamCfg_TsOutMode
**
********************************************************************************
*/
INLINE void tsdSetInRamCfg_TsOutMode(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetInRamCfg_TsOutMode(value);
    else
        FREG_TSD23_SetInRamCfg_TsOutMode(value);
}

/*
********************************************************************************
**
** \brief tsdSetIrqClear function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetIrqClear
** \sa FREG_TSD23_SetIrqClear
**
********************************************************************************
*/
INLINE void tsdSetIrqClear(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetIrqClear(value);
    else
        FREG_TSD23_SetIrqClear(value);
}

/*
********************************************************************************
**
** \brief tsdSetIrqClear_ClearAllIrq function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetIrqClear_ClearAllIrq
** \sa FREG_TSD23_SetIrqClear_ClearAllIrq
**
********************************************************************************
*/
INLINE void tsdSetIrqClear_ClearAllIrq(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetIrqClear_ClearAllIrq(value);
    else
        FREG_TSD23_SetIrqClear_ClearAllIrq(value);
}

/*
********************************************************************************
**
** \brief tsdSetLoadPcr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetLoadPcr
** \sa FREG_TSD23_SetLoadPcr
**
********************************************************************************
*/
INLINE void tsdSetLoadPcr(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetLoadPcr(value);
    else
        FREG_TSD23_SetLoadPcr(value);
}

/*
********************************************************************************
**
** \brief tsdSetLoadPcr_LoadPcrFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetLoadPcr_LoadPcrFlag
** \sa FREG_TSD23_SetLoadPcr_LoadPcrFlag
**
********************************************************************************
*/
INLINE void tsdSetLoadPcr_LoadPcrFlag(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetLoadPcr_LoadPcrFlag(value);
    else
        FREG_TSD23_SetLoadPcr_LoadPcrFlag(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCounter function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPacketCounter
** \sa FREG_TSD23_SetPacketCounter
**
********************************************************************************
*/
INLINE void tsdSetPacketCounter(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPacketCounter(value);
    else
        FREG_TSD23_SetPacketCounter(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCounter_PacketCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPacketCounter_PacketCnt
** \sa FREG_TSD23_SetPacketCounter_PacketCnt
**
********************************************************************************
*/
INLINE void tsdSetPacketCounter_PacketCnt(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPacketCounter_PacketCnt(value);
    else
        FREG_TSD23_SetPacketCounter_PacketCnt(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketStcMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPacketStcMode
** \sa FREG_TSD23_SetPacketStcMode
**
********************************************************************************
*/
INLINE void tsdSetPacketStcMode(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPacketStcMode(value);
    else
        FREG_TSD23_SetPacketStcMode(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketStcMode_StoreAllPacketStc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPacketStcMode_StoreAllPacketStc
** \sa FREG_TSD23_SetPacketStcMode_StoreAllPacketStc
**
********************************************************************************
*/
INLINE void tsdSetPacketStcMode_StoreAllPacketStc(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPacketStcMode_StoreAllPacketStc(value);
    else
        FREG_TSD23_SetPacketStcMode_StoreAllPacketStc(value);
}

/*
********************************************************************************
**
** \brief tsdSetPesCfg function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPesCfg
** \sa FREG_TSD23_SetPesCfg
**
********************************************************************************
*/
INLINE void tsdSetPesCfg(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPesCfg(index, value);
    else
        FREG_TSD23_SetPesCfg(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPesCfg_NewPtsIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPesCfg_NewPtsIrqEn
** \sa FREG_TSD23_SetPesCfg_NewPtsIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPesCfg_NewPtsIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPesCfg_NewPtsIrqEn(index, value);
    else
        FREG_TSD23_SetPesCfg_NewPtsIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPesCfg_PesEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPesCfg_PesEn
** \sa FREG_TSD23_SetPesCfg_PesEn
**
********************************************************************************
*/
INLINE void tsdSetPesCfg_PesEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPesCfg_PesEn(index, value);
    else
        FREG_TSD23_SetPesCfg_PesEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPesCfg_PidIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPesCfg_PidIndex
** \sa FREG_TSD23_SetPesCfg_PidIndex
**
********************************************************************************
*/
INLINE void tsdSetPesCfg_PidIndex(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPesCfg_PidIndex(index, value);
    else
        FREG_TSD23_SetPesCfg_PidIndex(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPesCfg_RemovePesHeader function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPesCfg_RemovePesHeader
** \sa FREG_TSD23_SetPesCfg_RemovePesHeader
**
********************************************************************************
*/
INLINE void tsdSetPesCfg_RemovePesHeader(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPesCfg_RemovePesHeader(index, value);
    else
        FREG_TSD23_SetPesCfg_RemovePesHeader(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPesCfg_Tsd13Select function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetPesCfg_Tsd1Select
** \sa FREG_TSD23_SetPesCfg_Tsd3Select
**
********************************************************************************
*/
INLINE void tsdSetPesCfg_Tsd13Select(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetPesCfg_Tsd1Select(index, value);
    else
        FREG_TSD23_SetPesCfg_Tsd3Select(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetReadSignalDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetReadSignalDistance
** \sa FREG_TSD23_SetReadSignalDistance
**
********************************************************************************
*/
INLINE void tsdSetReadSignalDistance(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetReadSignalDistance(value);
    else
        FREG_TSD23_SetReadSignalDistance(value);
}

/*
********************************************************************************
**
** \brief tsdSetReadSignalDistance_RdSignalDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetReadSignalDistance_RdSignalDistance
** \sa FREG_TSD23_SetReadSignalDistance_RdSignalDistance
**
********************************************************************************
*/
INLINE void tsdSetReadSignalDistance_RdSignalDistance(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetReadSignalDistance_RdSignalDistance(value);
    else
        FREG_TSD23_SetReadSignalDistance_RdSignalDistance(value);
}

/*
********************************************************************************
**
** \brief tsdSetStartDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetStartDistance
** \sa FREG_TSD23_SetStartDistance
**
********************************************************************************
*/
INLINE void tsdSetStartDistance(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetStartDistance(value);
    else
        FREG_TSD23_SetStartDistance(value);
}

/*
********************************************************************************
**
** \brief tsdSetStartDistance_Ts02StartDistance function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetStartDistance_Ts0StartDistance
** \sa FREG_TSD01_SetStartDistance_Ts1StartDistance
** \sa FREG_TSD23_SetStartDistance_Ts2StartDistance
** \sa FREG_TSD23_SetStartDistance_Ts3StartDistance
**
********************************************************************************
*/
INLINE void tsdSetStartDistance_TsStartDistance(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD01_SetStartDistance_Ts0StartDistance(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD01_SetStartDistance_Ts1StartDistance(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD23_SetStartDistance_Ts2StartDistance(value);
    else
        FREG_TSD23_SetStartDistance_Ts3StartDistance(value);
}

/*
********************************************************************************
**
** \brief tsdSetValidInputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetValidInputTimeout
** \sa FREG_TSD23_SetValidInputTimeout
**
********************************************************************************
*/
INLINE void tsdSetValidInputTimeout(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetValidInputTimeout(value);
    else
        FREG_TSD23_SetValidInputTimeout(value);
}

/*
********************************************************************************
**
** \brief tsdSetValidInputTimeout_ValidInputTimeout function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetValidInputTimeout_ValidInputTimeout
** \sa FREG_TSD23_SetValidInputTimeout_ValidInputTimeout
**
********************************************************************************
*/
INLINE void tsdSetValidInputTimeout_ValidInputTimeout(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetValidInputTimeout_ValidInputTimeout(value);
    else
        FREG_TSD23_SetValidInputTimeout_ValidInputTimeout(value);
}

/*
********************************************************************************
**
** \brief tsdSetValidPacketCounter function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetValidPacketCounter
** \sa FREG_TSD23_SetValidPacketCounter
**
********************************************************************************
*/
INLINE void tsdSetValidPacketCounter(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetValidPacketCounter(value);
    else
        FREG_TSD23_SetValidPacketCounter(value);
}

/*
********************************************************************************
**
** \brief tsdSetValidPacketCounter_ValidPacketCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD01_SetValidPacketCounter_ValidPacketCnt
** \sa FREG_TSD23_SetValidPacketCounter_ValidPacketCnt
**
********************************************************************************
*/
INLINE void tsdSetValidPacketCounter_ValidPacketCnt(uint32_t blockIndex, uint32_t value)
{
    if((blockIndex == FAPI_TSD0) || (blockIndex == FAPI_TSD1))
        FREG_TSD01_SetValidPacketCounter_ValidPacketCnt(value);
    else
        FREG_TSD23_SetValidPacketCounter_ValidPacketCnt(value);
}

/*
********************************************************************************
**
** \brief tsdGetCrc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetCrc
** \sa FREG_TSD1_GetCrc
** \sa FREG_TSD2_GetCrc
** \sa FREG_TSD3_GetCrc
**
********************************************************************************
*/
INLINE uint32_t tsdGetCrc(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetCrc(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD0_GetCrc(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD0_GetCrc(index));
    return(FREG_TSD0_GetCrc(index));
}

/*
********************************************************************************
**
** \brief tsdGetCrc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetCrc_Crc
** \sa FREG_TSD1_GetCrc_Crc
** \sa FREG_TSD2_GetCrc_Crc
** \sa FREG_TSD3_GetCrc_Crc
**
********************************************************************************
*/
INLINE uint32_t tsdGetCrc_Crc(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetCrc_Crc(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD0_GetCrc_Crc(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD0_GetCrc_Crc(index));
    return(FREG_TSD0_GetCrc_Crc(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscEvenKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscEvenKeyLower
** \sa FREG_TSD1_GetmDscEvenKeyLower
** \sa FREG_TSD2_GetmDscEvenKeyLower
** \sa FREG_TSD3_GetmDscEvenKeyLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscEvenKeyLower(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscEvenKeyLower(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscEvenKeyLower(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscEvenKeyLower(index));
    return(FREG_TSD3_GetmDscEvenKeyLower(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscEvenKeyLower_EvenKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscEvenKeyLower_EvenKeyLower
** \sa FREG_TSD1_GetmDscEvenKeyLower_EvenKeyLower
** \sa FREG_TSD2_GetmDscEvenKeyLower_EvenKeyLower
** \sa FREG_TSD3_GetmDscEvenKeyLower_EvenKeyLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscEvenKeyLower_EvenKeyLower(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscEvenKeyLower_EvenKeyLower(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscEvenKeyLower_EvenKeyLower(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscEvenKeyLower_EvenKeyLower(index));
    return(FREG_TSD3_GetmDscEvenKeyLower_EvenKeyLower(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscEvenKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscEvenKeyUpper
** \sa FREG_TSD1_GetmDscEvenKeyUpper
** \sa FREG_TSD2_GetmDscEvenKeyUpper
** \sa FREG_TSD3_GetmDscEvenKeyUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscEvenKeyUpper(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscEvenKeyUpper(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscEvenKeyUpper(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscEvenKeyUpper(index));
    return(FREG_TSD3_GetmDscEvenKeyUpper(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscEvenKeyUpper_EvenKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscEvenKeyUpper_EvenKeyUpper
** \sa FREG_TSD1_GetmDscEvenKeyUpper_EvenKeyUpper
** \sa FREG_TSD2_GetmDscEvenKeyUpper_EvenKeyUpper
** \sa FREG_TSD3_GetmDscEvenKeyUpper_EvenKeyUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscEvenKeyUpper_EvenKeyUpper(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscEvenKeyUpper_EvenKeyUpper(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscEvenKeyUpper_EvenKeyUpper(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscEvenKeyUpper_EvenKeyUpper(index));
    return(FREG_TSD3_GetmDscEvenKeyUpper_EvenKeyUpper(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscOddKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscOddKeyLower
** \sa FREG_TSD1_GetmDscOddKeyLower
** \sa FREG_TSD2_GetmDscOddKeyLower
** \sa FREG_TSD3_GetmDscOddKeyLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscOddKeyLower(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscOddKeyLower(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscOddKeyLower(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscOddKeyLower(index));
    return(FREG_TSD3_GetmDscOddKeyLower(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscOddKeyLower_OddKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscOddKeyLower_OddKeyLower
** \sa FREG_TSD1_GetmDscOddKeyLower_OddKeyLower
** \sa FREG_TSD2_GetmDscOddKeyLower_OddKeyLower
** \sa FREG_TSD3_GetmDscOddKeyLower_OddKeyLower
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscOddKeyLower_OddKeyLower(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscOddKeyLower_OddKeyLower(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscOddKeyLower_OddKeyLower(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscOddKeyLower_OddKeyLower(index));
    return(FREG_TSD3_GetmDscOddKeyLower_OddKeyLower(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscOddKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscOddKeyUpper
** \sa FREG_TSD1_GetmDscOddKeyUpper
** \sa FREG_TSD2_GetmDscOddKeyUpper
** \sa FREG_TSD3_GetmDscOddKeyUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscOddKeyUpper(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscOddKeyUpper(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscOddKeyUpper(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscOddKeyUpper(index));
    return(FREG_TSD3_GetmDscOddKeyUpper(index));
}

/*
********************************************************************************
**
** \brief tsdGetmDscOddKeyUpper_OddKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmDscOddKeyUpper_OddKeyUpper
** \sa FREG_TSD1_GetmDscOddKeyUpper_OddKeyUpper
** \sa FREG_TSD2_GetmDscOddKeyUpper_OddKeyUpper
** \sa FREG_TSD3_GetmDscOddKeyUpper_OddKeyUpper
**
********************************************************************************
*/
INLINE uint32_t tsdGetmDscOddKeyUpper_OddKeyUpper(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmDscOddKeyUpper_OddKeyUpper(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmDscOddKeyUpper_OddKeyUpper(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmDscOddKeyUpper_OddKeyUpper(index));
    return(FREG_TSD3_GetmDscOddKeyUpper_OddKeyUpper(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket0
** \sa FREG_TSD1_GetmLinPacket0
** \sa FREG_TSD2_GetmLinPacket0
** \sa FREG_TSD3_GetmLinPacket0
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket0(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket0(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket0(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket0(index));
    return(FREG_TSD3_GetmLinPacket0(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket0_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket0_TspWord
** \sa FREG_TSD1_GetmLinPacket0_TspWord
** \sa FREG_TSD2_GetmLinPacket0_TspWord
** \sa FREG_TSD3_GetmLinPacket0_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket0_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket0_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket0_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket0_TspWord(index));
    return(FREG_TSD3_GetmLinPacket0_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket1
** \sa FREG_TSD1_GetmLinPacket1
** \sa FREG_TSD2_GetmLinPacket1
** \sa FREG_TSD3_GetmLinPacket1
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket1(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket1(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket1(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket1(index));
    return(FREG_TSD3_GetmLinPacket1(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket1_TspWord
** \sa FREG_TSD1_GetmLinPacket1_TspWord
** \sa FREG_TSD2_GetmLinPacket1_TspWord
** \sa FREG_TSD3_GetmLinPacket1_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket1_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket1_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket1_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket1_TspWord(index));
    return(FREG_TSD3_GetmLinPacket1_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket2
** \sa FREG_TSD1_GetmLinPacket2
** \sa FREG_TSD2_GetmLinPacket2
** \sa FREG_TSD3_GetmLinPacket2
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket2(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket2(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket2(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket2(index));
    return(FREG_TSD3_GetmLinPacket2(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket2_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket2_TspWord
** \sa FREG_TSD1_GetmLinPacket2_TspWord
** \sa FREG_TSD2_GetmLinPacket2_TspWord
** \sa FREG_TSD3_GetmLinPacket2_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket2_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket2_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket2_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket2_TspWord(index));
    return(FREG_TSD3_GetmLinPacket2_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket3
** \sa FREG_TSD1_GetmLinPacket3
** \sa FREG_TSD2_GetmLinPacket3
** \sa FREG_TSD3_GetmLinPacket3
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket3(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket3(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket3(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket3(index));
    return(FREG_TSD3_GetmLinPacket3(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacket3_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacket3_TspWord
** \sa FREG_TSD1_GetmLinPacket3_TspWord
** \sa FREG_TSD2_GetmLinPacket3_TspWord
** \sa FREG_TSD3_GetmLinPacket3_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacket3_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacket3_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacket3_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacket3_TspWord(index));
    return(FREG_TSD3_GetmLinPacket3_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto0
** \sa FREG_TSD1_GetmLinPacketAuto0
** \sa FREG_TSD2_GetmLinPacketAuto0
** \sa FREG_TSD3_GetmLinPacketAuto0
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto0(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto0(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto0(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto0(index));
    return(FREG_TSD3_GetmLinPacketAuto0(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto0_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto0_TspWord
** \sa FREG_TSD1_GetmLinPacketAuto0_TspWord
** \sa FREG_TSD2_GetmLinPacketAuto0_TspWord
** \sa FREG_TSD3_GetmLinPacketAuto0_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto0_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto0_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto0_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto0_TspWord(index));
    return(FREG_TSD3_GetmLinPacketAuto0_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto1
** \sa FREG_TSD1_GetmLinPacketAuto1
** \sa FREG_TSD2_GetmLinPacketAuto1
** \sa FREG_TSD3_GetmLinPacketAuto1
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto1(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto1(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto1(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto1(index));
    return(FREG_TSD3_GetmLinPacketAuto1(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto1_TspWord
** \sa FREG_TSD1_GetmLinPacketAuto1_TspWord
** \sa FREG_TSD2_GetmLinPacketAuto1_TspWord
** \sa FREG_TSD3_GetmLinPacketAuto1_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto1_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto1_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto1_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto1_TspWord(index));
    return(FREG_TSD3_GetmLinPacketAuto1_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto2
** \sa FREG_TSD1_GetmLinPacketAuto2
** \sa FREG_TSD2_GetmLinPacketAuto2
** \sa FREG_TSD3_GetmLinPacketAuto2
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto2(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto2(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto2(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto2(index));
    return(FREG_TSD3_GetmLinPacketAuto2(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto2_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto2_TspWord
** \sa FREG_TSD1_GetmLinPacketAuto2_TspWord
** \sa FREG_TSD2_GetmLinPacketAuto2_TspWord
** \sa FREG_TSD3_GetmLinPacketAuto2_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto2_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto2_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto2_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto2_TspWord(index));
    return(FREG_TSD3_GetmLinPacketAuto2_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto3
** \sa FREG_TSD1_GetmLinPacketAuto3
** \sa FREG_TSD2_GetmLinPacketAuto3
** \sa FREG_TSD3_GetmLinPacketAuto3
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto3(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto3(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto3(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto3(index));
    return(FREG_TSD3_GetmLinPacketAuto3(index));
}

/*
********************************************************************************
**
** \brief tsdGetmLinPacketAuto3_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmLinPacketAuto3_TspWord
** \sa FREG_TSD1_GetmLinPacketAuto3_TspWord
** \sa FREG_TSD2_GetmLinPacketAuto3_TspWord
** \sa FREG_TSD3_GetmLinPacketAuto3_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmLinPacketAuto3_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmLinPacketAuto3_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmLinPacketAuto3_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmLinPacketAuto3_TspWord(index));
    return(FREG_TSD3_GetmLinPacketAuto3_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket0
** \sa FREG_TSD1_GetmPacket0
** \sa FREG_TSD2_GetmPacket0
** \sa FREG_TSD3_GetmPacket0
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket0(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket0(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket0(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket0(index));
    return(FREG_TSD3_GetmPacket0(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket0_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket0_TspWord
** \sa FREG_TSD1_GetmPacket0_TspWord
** \sa FREG_TSD2_GetmPacket0_TspWord
** \sa FREG_TSD3_GetmPacket0_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket0_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket0_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket0_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket0_TspWord(index));
    return(FREG_TSD3_GetmPacket0_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket1
** \sa FREG_TSD1_GetmPacket1
** \sa FREG_TSD2_GetmPacket1
** \sa FREG_TSD3_GetmPacket1
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket1(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket1(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket1(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket1(index));
    return(FREG_TSD3_GetmPacket1(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket1_TspWord
** \sa FREG_TSD1_GetmPacket1_TspWord
** \sa FREG_TSD2_GetmPacket1_TspWord
** \sa FREG_TSD3_GetmPacket1_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket1_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket1_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket1_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket1_TspWord(index));
    return(FREG_TSD3_GetmPacket1_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket2
** \sa FREG_TSD1_GetmPacket2
** \sa FREG_TSD2_GetmPacket2
** \sa FREG_TSD3_GetmPacket2
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket2(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket2(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket2(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket2(index));
    return(FREG_TSD3_GetmPacket2(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket2_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket2_TspWord
** \sa FREG_TSD1_GetmPacket2_TspWord
** \sa FREG_TSD2_GetmPacket2_TspWord
** \sa FREG_TSD3_GetmPacket2_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket2_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket2_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket2_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket2_TspWord(index));
    return(FREG_TSD3_GetmPacket2_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket3
** \sa FREG_TSD1_GetmPacket3
** \sa FREG_TSD2_GetmPacket3
** \sa FREG_TSD3_GetmPacket3
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket3(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket3(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket3(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket3(index));
    return(FREG_TSD3_GetmPacket3(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPacket3_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPacket3_TspWord
** \sa FREG_TSD1_GetmPacket3_TspWord
** \sa FREG_TSD2_GetmPacket3_TspWord
** \sa FREG_TSD3_GetmPacket3_TspWord
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPacket3_TspWord(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPacket3_TspWord(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPacket3_TspWord(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPacket3_TspWord(index));
    return(FREG_TSD3_GetmPacket3_TspWord(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1
** \sa FREG_TSD1_GetmPidConfig_1
** \sa FREG_TSD2_GetmPidConfig_1
** \sa FREG_TSD3_GetmPidConfig_1
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1(index));
    return(FREG_TSD3_GetmPidConfig_1(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_BufferIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_BufferIndex
** \sa FREG_TSD1_GetmPidConfig_1_BufferIndex
** \sa FREG_TSD2_GetmPidConfig_1_BufferIndex
** \sa FREG_TSD3_GetmPidConfig_1_BufferIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_BufferIndex(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_BufferIndex(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_BufferIndex(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_BufferIndex(index));
    return(FREG_TSD3_GetmPidConfig_1_BufferIndex(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_DescramblerIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_DescramblerIndex
** \sa FREG_TSD1_GetmPidConfig_1_DescramblerIndex
** \sa FREG_TSD2_GetmPidConfig_1_DescramblerIndex
** \sa FREG_TSD3_GetmPidConfig_1_DescramblerIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_DescramblerIndex(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_DescramblerIndex(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_DescramblerIndex(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_DescramblerIndex(index));
    return(FREG_TSD3_GetmPidConfig_1_DescramblerIndex(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_DuplicateIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_DuplicateIrqEn
** \sa FREG_TSD1_GetmPidConfig_1_DuplicateIrqEn
** \sa FREG_TSD2_GetmPidConfig_1_DuplicateIrqEn
** \sa FREG_TSD3_GetmPidConfig_1_DuplicateIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_DuplicateIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_DuplicateIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_DuplicateIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_DuplicateIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_1_DuplicateIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_NullPacketIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_NullPacketIrqEn
** \sa FREG_TSD1_GetmPidConfig_1_NullPacketIrqEn
** \sa FREG_TSD2_GetmPidConfig_1_NullPacketIrqEn
** \sa FREG_TSD3_GetmPidConfig_1_NullPacketIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_NullPacketIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_NullPacketIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_NullPacketIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_NullPacketIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_1_NullPacketIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_OffsetMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_OffsetMode
** \sa FREG_TSD1_GetmPidConfig_1_OffsetMode
** \sa FREG_TSD2_GetmPidConfig_1_OffsetMode
** \sa FREG_TSD3_GetmPidConfig_1_OffsetMode
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_OffsetMode(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_OffsetMode(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_OffsetMode(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_OffsetMode(index));
    return(FREG_TSD3_GetmPidConfig_1_OffsetMode(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_Pcr1AfLt7IrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_Pcr1AfLt7IrqEn
** \sa FREG_TSD1_GetmPidConfig_1_Pcr1AfLt7IrqEn
** \sa FREG_TSD2_GetmPidConfig_1_Pcr1AfLt7IrqEn
** \sa FREG_TSD3_GetmPidConfig_1_Pcr1AfLt7IrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_Pcr1AfLt7IrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_Pcr1AfLt7IrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_Pcr1AfLt7IrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_Pcr1AfLt7IrqEn(index));
    return(FREG_TSD3_GetmPidConfig_1_Pcr1AfLt7IrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_1_Pl0AfNe183IrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_1_Pl0AfNe183IrqEn
** \sa FREG_TSD1_GetmPidConfig_1_Pl0AfNe183IrqEn
** \sa FREG_TSD2_GetmPidConfig_1_Pl0AfNe183IrqEn
** \sa FREG_TSD3_GetmPidConfig_1_Pl0AfNe183IrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_1_Pl0AfNe183IrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_1_Pl0AfNe183IrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_1_Pl0AfNe183IrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_1_Pl0AfNe183IrqEn(index));
    return(FREG_TSD3_GetmPidConfig_1_Pl0AfNe183IrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2
** \sa FREG_TSD1_GetmPidConfig_2
** \sa FREG_TSD2_GetmPidConfig_2
** \sa FREG_TSD3_GetmPidConfig_2
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2(index));
    return(FREG_TSD3_GetmPidConfig_2(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_BypassDsc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_BypassDsc
** \sa FREG_TSD1_GetmPidConfig_2_BypassDsc
** \sa FREG_TSD2_GetmPidConfig_2_BypassDsc
** \sa FREG_TSD3_GetmPidConfig_2_BypassDsc
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_BypassDsc(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_BypassDsc(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_BypassDsc(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_BypassDsc(index));
    return(FREG_TSD3_GetmPidConfig_2_BypassDsc(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_CcCheck function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_CcCheck
** \sa FREG_TSD1_GetmPidConfig_2_CcCheck
** \sa FREG_TSD2_GetmPidConfig_2_CcCheck
** \sa FREG_TSD3_GetmPidConfig_2_CcCheck
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_CcCheck(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_CcCheck(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_CcCheck(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_CcCheck(index));
    return(FREG_TSD3_GetmPidConfig_2_CcCheck(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_CcIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_CcIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_CcIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_CcIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_CcIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_CcIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_CcIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_CcIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_CcIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_CcIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_CrcErrIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_CrcErrIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_CrcErrIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_CrcErrIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_CrcErrIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_CrcErrIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_CrcErrIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_CrcErrIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_CrcErrIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_CrcErrIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_DuplicateCheck function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_DuplicateCheck
** \sa FREG_TSD1_GetmPidConfig_2_DuplicateCheck
** \sa FREG_TSD2_GetmPidConfig_2_DuplicateCheck
** \sa FREG_TSD3_GetmPidConfig_2_DuplicateCheck
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_DuplicateCheck(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_DuplicateCheck(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_DuplicateCheck(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_DuplicateCheck(index));
    return(FREG_TSD3_GetmPidConfig_2_DuplicateCheck(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_ExtractPcr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_ExtractPcr
** \sa FREG_TSD1_GetmPidConfig_2_ExtractPcr
** \sa FREG_TSD2_GetmPidConfig_2_ExtractPcr
** \sa FREG_TSD3_GetmPidConfig_2_ExtractPcr
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_ExtractPcr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_ExtractPcr(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_ExtractPcr(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_ExtractPcr(index));
    return(FREG_TSD3_GetmPidConfig_2_ExtractPcr(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_InputTimeoutIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_InputTimeoutIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_InputTimeoutIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_InputTimeoutIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_InputTimeoutIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_InputTimeoutIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_InputTimeoutIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_InputTimeoutIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_InputTimeoutIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_InputTimeoutIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_NewPcrIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_NewPcrIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_NewPcrIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_NewPcrIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_NewPcrIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_NewPcrIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_NewPcrIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_NewPcrIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_NewPcrIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_NewPcrIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_NTarget function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_NTarget
** \sa FREG_TSD1_GetmPidConfig_2_NTarget
** \sa FREG_TSD2_GetmPidConfig_2_NTarget
** \sa FREG_TSD3_GetmPidConfig_2_NTarget
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_NTarget(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_NTarget(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_NTarget(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_NTarget(index));
    return(FREG_TSD3_GetmPidConfig_2_NTarget(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_PacketEndIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_PacketEndIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_PacketEndIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_PacketEndIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_PacketEndIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_PacketEndIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_PacketEndIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_PacketEndIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_PacketEndIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_PacketEndIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_PesPayload function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_PesPayload
** \sa FREG_TSD1_GetmPidConfig_2_PesPayload
** \sa FREG_TSD2_GetmPidConfig_2_PesPayload
** \sa FREG_TSD3_GetmPidConfig_2_PesPayload
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_PesPayload(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_PesPayload(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_PesPayload(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_PesPayload(index));
    return(FREG_TSD3_GetmPidConfig_2_PesPayload(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_PsiCcCheckMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_PsiCcCheckMode
** \sa FREG_TSD1_GetmPidConfig_2_PsiCcCheckMode
** \sa FREG_TSD2_GetmPidConfig_2_PsiCcCheckMode
** \sa FREG_TSD3_GetmPidConfig_2_PsiCcCheckMode
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_PsiCcCheckMode(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_PsiCcCheckMode(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_PsiCcCheckMode(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_PsiCcCheckMode(index));
    return(FREG_TSD3_GetmPidConfig_2_PsiCcCheckMode(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_PusIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_PusIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_PusIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_PusIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_PusIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_PusIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_PusIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_PusIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_PusIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_PusIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_ScrambledPacketIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_ScrambledPacketIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_ScrambledPacketIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_ScrambledPacketIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_ScrambledPacketIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_ScrambledPacketIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_ScrambledPacketIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_ScrambledPacketIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_ScrambledPacketIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_ScrambledPacketIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_SectionEndIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_SectionEndIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_SectionEndIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_SectionEndIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_SectionEndIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_SectionEndIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_SectionEndIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_SectionEndIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_SectionEndIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_SectionEndIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_StoreCompletePacket function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_StoreCompletePacket
** \sa FREG_TSD1_GetmPidConfig_2_StoreCompletePacket
** \sa FREG_TSD2_GetmPidConfig_2_StoreCompletePacket
** \sa FREG_TSD3_GetmPidConfig_2_StoreCompletePacket
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_StoreCompletePacket(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_StoreCompletePacket(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_StoreCompletePacket(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_StoreCompletePacket(index));
    return(FREG_TSD3_GetmPidConfig_2_StoreCompletePacket(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_TargetLength function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_TargetLength
** \sa FREG_TSD1_GetmPidConfig_2_TargetLength
** \sa FREG_TSD2_GetmPidConfig_2_TargetLength
** \sa FREG_TSD3_GetmPidConfig_2_TargetLength
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_TargetLength(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_TargetLength(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_TargetLength(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_TargetLength(index));
    return(FREG_TSD3_GetmPidConfig_2_TargetLength(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidConfig_2_ValidInputTimeoutIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidConfig_2_ValidInputTimeoutIrqEn
** \sa FREG_TSD1_GetmPidConfig_2_ValidInputTimeoutIrqEn
** \sa FREG_TSD2_GetmPidConfig_2_ValidInputTimeoutIrqEn
** \sa FREG_TSD3_GetmPidConfig_2_ValidInputTimeoutIrqEn
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidConfig_2_ValidInputTimeoutIrqEn(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidConfig_2_ValidInputTimeoutIrqEn(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidConfig_2_ValidInputTimeoutIrqEn(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidConfig_2_ValidInputTimeoutIrqEn(index));
    return(FREG_TSD3_GetmPidConfig_2_ValidInputTimeoutIrqEn(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidValue function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidValue
** \sa FREG_TSD1_GetmPidValue
** \sa FREG_TSD2_GetmPidValue
** \sa FREG_TSD3_GetmPidValue
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidValue(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidValue(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidValue(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidValue(index));
    return(FREG_TSD3_GetmPidValue(index));
}

/*
********************************************************************************
**
** \brief tsdGetmPidValue_PidBit function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmPidValue_PidBit
** \sa FREG_TSD1_GetmPidValue_PidBit
** \sa FREG_TSD2_GetmPidValue_PidBit
** \sa FREG_TSD3_GetmPidValue_PidBit
**
********************************************************************************
*/
INLINE uint32_t tsdGetmPidValue_PidBit(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmPidValue_PidBit(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmPidValue_PidBit(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmPidValue_PidBit(index));
    return(FREG_TSD3_GetmPidValue_PidBit(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfPtr
** \sa FREG_TSD1_GetmSfPtr
** \sa FREG_TSD2_GetmSfPtr
** \sa FREG_TSD3_GetmSfPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfPtr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfPtr(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfPtr(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfPtr(index));
    return(FREG_TSD3_GetmSfPtr(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfPtr_Eol function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfPtr_Eol
** \sa FREG_TSD1_GetmSfPtr_Eol
** \sa FREG_TSD2_GetmSfPtr_Eol
** \sa FREG_TSD3_GetmSfPtr_Eol
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfPtr_Eol(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfPtr_Eol(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfPtr_Eol(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfPtr_Eol(index));
    return(FREG_TSD3_GetmSfPtr_Eol(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfPtr_NxtDepPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfPtr_NxtDepPtr
** \sa FREG_TSD1_GetmSfPtr_NxtDepPtr
** \sa FREG_TSD2_GetmSfPtr_NxtDepPtr
** \sa FREG_TSD3_GetmSfPtr_NxtDepPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfPtr_NxtDepPtr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfPtr_NxtDepPtr(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfPtr_NxtDepPtr(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfPtr_NxtDepPtr(index));
    return(FREG_TSD3_GetmSfPtr_NxtDepPtr(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfTargets function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfTargets
** \sa FREG_TSD1_GetmSfTargets
** \sa FREG_TSD2_GetmSfTargets
** \sa FREG_TSD3_GetmSfTargets
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfTargets(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfTargets(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfTargets(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfTargets(index));
    return(FREG_TSD3_GetmSfTargets(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfTargets_FilterEnable0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfTargets_FilterEnable0
** \sa FREG_TSD1_GetmSfTargets_FilterEnable0
** \sa FREG_TSD2_GetmSfTargets_FilterEnable0
** \sa FREG_TSD3_GetmSfTargets_FilterEnable0
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfTargets_FilterEnable0(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfTargets_FilterEnable0(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfTargets_FilterEnable0(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfTargets_FilterEnable0(index));
    return(FREG_TSD3_GetmSfTargets_FilterEnable0(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfTargets_FilterEnable1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfTargets_FilterEnable1
** \sa FREG_TSD1_GetmSfTargets_FilterEnable1
** \sa FREG_TSD2_GetmSfTargets_FilterEnable1
** \sa FREG_TSD3_GetmSfTargets_FilterEnable1
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfTargets_FilterEnable1(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfTargets_FilterEnable1(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfTargets_FilterEnable1(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfTargets_FilterEnable1(index));
    return(FREG_TSD3_GetmSfTargets_FilterEnable1(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfTargets_SecData0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfTargets_SecData0
** \sa FREG_TSD1_GetmSfTargets_SecData0
** \sa FREG_TSD2_GetmSfTargets_SecData0
** \sa FREG_TSD3_GetmSfTargets_SecData0
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfTargets_SecData0(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfTargets_SecData0(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfTargets_SecData0(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfTargets_SecData0(index));
    return(FREG_TSD3_GetmSfTargets_SecData0(index));
}

/*
********************************************************************************
**
** \brief tsdGetmSfTargets_SecData1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetmSfTargets_SecData1
** \sa FREG_TSD1_GetmSfTargets_SecData1
** \sa FREG_TSD2_GetmSfTargets_SecData1
** \sa FREG_TSD3_GetmSfTargets_SecData1
**
********************************************************************************
*/
INLINE uint32_t tsdGetmSfTargets_SecData1(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetmSfTargets_SecData1(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetmSfTargets_SecData1(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetmSfTargets_SecData1(index));
    return(FREG_TSD3_GetmSfTargets_SecData1(index));
}

/*
********************************************************************************
**
** \brief tsdGetPacketCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPacketCtrl
** \sa FREG_TSD1_GetPacketCtrl
** \sa FREG_TSD2_GetPacketCtrl
** \sa FREG_TSD3_GetPacketCtrl
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCtrl(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPacketCtrl());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPacketCtrl());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPacketCtrl());
    return(FREG_TSD3_GetPacketCtrl());
}

/*
********************************************************************************
**
** \brief tsdGetPacketCtrl_PacketBufValid0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPacketCtrl_PacketBufValid0
** \sa FREG_TSD1_GetPacketCtrl_PacketBufValid0
** \sa FREG_TSD2_GetPacketCtrl_PacketBufValid0
** \sa FREG_TSD3_GetPacketCtrl_PacketBufValid0
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCtrl_PacketBufValid0(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPacketCtrl_PacketBufValid0());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPacketCtrl_PacketBufValid0());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPacketCtrl_PacketBufValid0());
    return(FREG_TSD3_GetPacketCtrl_PacketBufValid0());
}

/*
********************************************************************************
**
** \brief tsdGetPacketCtrl_PacketBufValid1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPacketCtrl_PacketBufValid1
** \sa FREG_TSD1_GetPacketCtrl_PacketBufValid1
** \sa FREG_TSD2_GetPacketCtrl_PacketBufValid1
** \sa FREG_TSD3_GetPacketCtrl_PacketBufValid1
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCtrl_PacketBufValid1(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPacketCtrl_PacketBufValid1());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPacketCtrl_PacketBufValid1());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPacketCtrl_PacketBufValid1());
    return(FREG_TSD3_GetPacketCtrl_PacketBufValid1());
}

/*
********************************************************************************
**
** \brief tsdGetPacketCtrl_PacketBufValid2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPacketCtrl_PacketBufValid2
** \sa FREG_TSD1_GetPacketCtrl_PacketBufValid2
** \sa FREG_TSD2_GetPacketCtrl_PacketBufValid2
** \sa FREG_TSD3_GetPacketCtrl_PacketBufValid2
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCtrl_PacketBufValid2(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPacketCtrl_PacketBufValid2());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPacketCtrl_PacketBufValid2());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPacketCtrl_PacketBufValid2());
    return(FREG_TSD3_GetPacketCtrl_PacketBufValid2());
}

/*
********************************************************************************
**
** \brief tsdGetPacketCtrl_PacketBufValid3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPacketCtrl_PacketBufValid3
** \sa FREG_TSD1_GetPacketCtrl_PacketBufValid3
** \sa FREG_TSD2_GetPacketCtrl_PacketBufValid3
** \sa FREG_TSD3_GetPacketCtrl_PacketBufValid3
**
********************************************************************************
*/
INLINE uint32_t tsdGetPacketCtrl_PacketBufValid3(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPacketCtrl_PacketBufValid3());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPacketCtrl_PacketBufValid3());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPacketCtrl_PacketBufValid3());
    return(FREG_TSD3_GetPacketCtrl_PacketBufValid3());
}

/*
********************************************************************************
**
** \brief tsdGetPidChannelActive function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPidChannelActive
** \sa FREG_TSD1_GetPidChannelActive
** \sa FREG_TSD2_GetPidChannelActive
** \sa FREG_TSD3_GetPidChannelActive
**
********************************************************************************
*/
INLINE uint32_t tsdGetPidChannelActive(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPidChannelActive(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPidChannelActive(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPidChannelActive(index));
    return(FREG_TSD3_GetPidChannelActive(index));
}

/*
********************************************************************************
**
** \brief tsdGetPidChannelActive_FirstPacketFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPidChannelActive_FirstPacketFlag
** \sa FREG_TSD1_GetPidChannelActive_FirstPacketFlag
** \sa FREG_TSD2_GetPidChannelActive_FirstPacketFlag
** \sa FREG_TSD3_GetPidChannelActive_FirstPacketFlag
**
********************************************************************************
*/
INLINE uint32_t tsdGetPidChannelActive_FirstPacketFlag(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPidChannelActive_FirstPacketFlag(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPidChannelActive_FirstPacketFlag(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPidChannelActive_FirstPacketFlag(index));
    return(FREG_TSD3_GetPidChannelActive_FirstPacketFlag(index));
}

/*
********************************************************************************
**
** \brief tsdGetPidChannelActive_PidChannelEnable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetPidChannelActive_PidChannelEnable
** \sa FREG_TSD1_GetPidChannelActive_PidChannelEnable
** \sa FREG_TSD2_GetPidChannelActive_PidChannelEnable
** \sa FREG_TSD3_GetPidChannelActive_PidChannelEnable
**
********************************************************************************
*/
INLINE uint32_t tsdGetPidChannelActive_PidChannelEnable(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetPidChannelActive_PidChannelEnable(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetPidChannelActive_PidChannelEnable(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetPidChannelActive_PidChannelEnable(index));
    return(FREG_TSD3_GetPidChannelActive_PidChannelEnable(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl
** \sa FREG_TSD1_GetSbCtrl
** \sa FREG_TSD2_GetSbCtrl
** \sa FREG_TSD3_GetSbCtrl
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl(index));
    return(FREG_TSD3_GetSbCtrl(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl_FilterIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl_FilterIndex
** \sa FREG_TSD1_GetSbCtrl_FilterIndex
** \sa FREG_TSD2_GetSbCtrl_FilterIndex
** \sa FREG_TSD3_GetSbCtrl_FilterIndex
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl_FilterIndex(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl_FilterIndex(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl_FilterIndex(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl_FilterIndex(index));
    return(FREG_TSD3_GetSbCtrl_FilterIndex(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl_FilterMatch function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl_FilterMatch
** \sa FREG_TSD1_GetSbCtrl_FilterMatch
** \sa FREG_TSD2_GetSbCtrl_FilterMatch
** \sa FREG_TSD3_GetSbCtrl_FilterMatch
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl_FilterMatch(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl_FilterMatch(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl_FilterMatch(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl_FilterMatch(index));
    return(FREG_TSD3_GetSbCtrl_FilterMatch(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl_PaddingCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl_PaddingCnt
** \sa FREG_TSD1_GetSbCtrl_PaddingCnt
** \sa FREG_TSD2_GetSbCtrl_PaddingCnt
** \sa FREG_TSD3_GetSbCtrl_PaddingCnt
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl_PaddingCnt(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl_PaddingCnt(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl_PaddingCnt(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl_PaddingCnt(index));
    return(FREG_TSD3_GetSbCtrl_PaddingCnt(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl_RdPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl_RdPtr
** \sa FREG_TSD1_GetSbCtrl_RdPtr
** \sa FREG_TSD2_GetSbCtrl_RdPtr
** \sa FREG_TSD3_GetSbCtrl_RdPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl_RdPtr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl_RdPtr(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl_RdPtr(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl_RdPtr(index));
    return(FREG_TSD3_GetSbCtrl_RdPtr(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl_ResidueCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl_ResidueCnt
** \sa FREG_TSD1_GetSbCtrl_ResidueCnt
** \sa FREG_TSD2_GetSbCtrl_ResidueCnt
** \sa FREG_TSD3_GetSbCtrl_ResidueCnt
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl_ResidueCnt(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl_ResidueCnt(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl_ResidueCnt(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl_ResidueCnt(index));
    return(FREG_TSD3_GetSbCtrl_ResidueCnt(index));
}

/*
********************************************************************************
**
** \brief tsdGetSbCtrl_WrPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSbCtrl_WrPtr
** \sa FREG_TSD1_GetSbCtrl_WrPtr
** \sa FREG_TSD2_GetSbCtrl_WrPtr
** \sa FREG_TSD3_GetSbCtrl_WrPtr
**
********************************************************************************
*/
INLINE uint32_t tsdGetSbCtrl_WrPtr(uint32_t blockIndex, uint32_t index)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSbCtrl_WrPtr(index));
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSbCtrl_WrPtr(index));
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSbCtrl_WrPtr(index));
    return(FREG_TSD3_GetSbCtrl_WrPtr(index));
}

/*
********************************************************************************
**
** \brief tsdGetSfActive function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSfActive
** \sa FREG_TSD1_GetSfActive
** \sa FREG_TSD2_GetSfActive
** \sa FREG_TSD3_GetSfActive
**
********************************************************************************
*/
INLINE uint32_t tsdGetSfActive(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSfActive());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSfActive());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSfActive());
    return(FREG_TSD3_GetSfActive());
}

/*
********************************************************************************
**
** \brief tsdGetSfActive_SfActive function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_GetSfActive_SfActive
** \sa FREG_TSD1_GetSfActive_SfActive
** \sa FREG_TSD2_GetSfActive_SfActive
** \sa FREG_TSD3_GetSfActive_SfActive
**
********************************************************************************
*/
INLINE uint32_t tsdGetSfActive_SfActive(uint32_t blockIndex)
{
    if(blockIndex == FAPI_TSD0)
        return(FREG_TSD0_GetSfActive_SfActive());
    if(blockIndex == FAPI_TSD1)
        return(FREG_TSD1_GetSfActive_SfActive());
    if(blockIndex == FAPI_TSD2)
        return(FREG_TSD2_GetSfActive_SfActive());
    return(FREG_TSD3_GetSfActive_SfActive());
}

/*
********************************************************************************
**
** \brief tsdSetCrc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetCrc
** \sa FREG_TSD1_SetCrc
** \sa FREG_TSD2_SetCrc
** \sa FREG_TSD3_SetCrc
**
********************************************************************************
*/
INLINE void tsdSetCrc(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetCrc(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetCrc(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetCrc(index, value);
    else
        FREG_TSD3_SetCrc(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetCrc_Crc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetCrc_Crc
** \sa FREG_TSD1_SetCrc_Crc
** \sa FREG_TSD2_SetCrc_Crc
** \sa FREG_TSD3_SetCrc_Crc
**
********************************************************************************
*/
INLINE void tsdSetCrc_Crc(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetCrc_Crc(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetCrc_Crc(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetCrc_Crc(index, value);
    else
        FREG_TSD3_SetCrc_Crc(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscEvenKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscEvenKeyLower
** \sa FREG_TSD1_SetDscEvenKeyLower
** \sa FREG_TSD2_SetDscEvenKeyLower
** \sa FREG_TSD3_SetDscEvenKeyLower
**
********************************************************************************
*/
INLINE void tsdSetDscEvenKeyLower(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscEvenKeyLower(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscEvenKeyLower(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscEvenKeyLower(index, value);
    else
        FREG_TSD3_SetDscEvenKeyLower(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscEvenKeyLower_EvenKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscEvenKeyLower_EvenKeyLower
** \sa FREG_TSD1_SetDscEvenKeyLower_EvenKeyLower
** \sa FREG_TSD2_SetDscEvenKeyLower_EvenKeyLower
** \sa FREG_TSD3_SetDscEvenKeyLower_EvenKeyLower
**
********************************************************************************
*/
INLINE void tsdSetDscEvenKeyLower_EvenKeyLower(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscEvenKeyLower_EvenKeyLower(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscEvenKeyLower_EvenKeyLower(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscEvenKeyLower_EvenKeyLower(index, value);
    else
        FREG_TSD3_SetDscEvenKeyLower_EvenKeyLower(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscEvenKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscEvenKeyUpper
** \sa FREG_TSD1_SetDscEvenKeyUpper
** \sa FREG_TSD2_SetDscEvenKeyUpper
** \sa FREG_TSD3_SetDscEvenKeyUpper
**
********************************************************************************
*/
INLINE void tsdSetDscEvenKeyUpper(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscEvenKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscEvenKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscEvenKeyUpper(index, value);
    else
        FREG_TSD3_SetDscEvenKeyUpper(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscEvenKeyUpper_EvenKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscEvenKeyUpper_EvenKeyUpper
** \sa FREG_TSD1_SetDscEvenKeyUpper_EvenKeyUpper
** \sa FREG_TSD2_SetDscEvenKeyUpper_EvenKeyUpper
** \sa FREG_TSD3_SetDscEvenKeyUpper_EvenKeyUpper
**
********************************************************************************
*/
INLINE void tsdSetDscEvenKeyUpper_EvenKeyUpper(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscEvenKeyUpper_EvenKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscEvenKeyUpper_EvenKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscEvenKeyUpper_EvenKeyUpper(index, value);
    else
        FREG_TSD3_SetDscEvenKeyUpper_EvenKeyUpper(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscOddKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscOddKeyLower
** \sa FREG_TSD1_SetDscOddKeyLower
** \sa FREG_TSD2_SetDscOddKeyLower
** \sa FREG_TSD3_SetDscOddKeyLower
**
********************************************************************************
*/
INLINE void tsdSetDscOddKeyLower(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscOddKeyLower(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscOddKeyLower(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscOddKeyLower(index, value);
    else
        FREG_TSD3_SetDscOddKeyLower(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscOddKeyLower_OddKeyLower function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscOddKeyLower_OddKeyLower
** \sa FREG_TSD1_SetDscOddKeyLower_OddKeyLower
** \sa FREG_TSD2_SetDscOddKeyLower_OddKeyLower
** \sa FREG_TSD3_SetDscOddKeyLower_OddKeyLower
**
********************************************************************************
*/
INLINE void tsdSetDscOddKeyLower_OddKeyLower(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscOddKeyLower_OddKeyLower(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscOddKeyLower_OddKeyLower(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscOddKeyLower_OddKeyLower(index, value);
    else
        FREG_TSD3_SetDscOddKeyLower_OddKeyLower(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscOddKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscOddKeyUpper
** \sa FREG_TSD1_SetDscOddKeyUpper
** \sa FREG_TSD2_SetDscOddKeyUpper
** \sa FREG_TSD3_SetDscOddKeyUpper
**
********************************************************************************
*/
INLINE void tsdSetDscOddKeyUpper(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscOddKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscOddKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscOddKeyUpper(index, value);
    else
        FREG_TSD3_SetDscOddKeyUpper(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetDscOddKeyUpper_OddKeyUpper function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetDscOddKeyUpper_OddKeyUpper
** \sa FREG_TSD1_SetDscOddKeyUpper_OddKeyUpper
** \sa FREG_TSD2_SetDscOddKeyUpper_OddKeyUpper
** \sa FREG_TSD3_SetDscOddKeyUpper_OddKeyUpper
**
********************************************************************************
*/
INLINE void tsdSetDscOddKeyUpper_OddKeyUpper(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetDscOddKeyUpper_OddKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetDscOddKeyUpper_OddKeyUpper(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetDscOddKeyUpper_OddKeyUpper(index, value);
    else
        FREG_TSD3_SetDscOddKeyUpper_OddKeyUpper(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket0
** \sa FREG_TSD1_SetLinPacket0
** \sa FREG_TSD2_SetLinPacket0
** \sa FREG_TSD3_SetLinPacket0
**
********************************************************************************
*/
INLINE void tsdSetLinPacket0(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket0(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket0(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket0(index, value);
    else
        FREG_TSD3_SetLinPacket0(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket0_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket0_TspWord
** \sa FREG_TSD1_SetLinPacket0_TspWord
** \sa FREG_TSD2_SetLinPacket0_TspWord
** \sa FREG_TSD3_SetLinPacket0_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacket0_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket0_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket0_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket0_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacket0_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket1
** \sa FREG_TSD1_SetLinPacket1
** \sa FREG_TSD2_SetLinPacket1
** \sa FREG_TSD3_SetLinPacket1
**
********************************************************************************
*/
INLINE void tsdSetLinPacket1(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket1(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket1(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket1(index, value);
    else
        FREG_TSD3_SetLinPacket1(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket1_TspWord
** \sa FREG_TSD1_SetLinPacket1_TspWord
** \sa FREG_TSD2_SetLinPacket1_TspWord
** \sa FREG_TSD3_SetLinPacket1_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacket1_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket1_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket1_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket1_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacket1_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket2
** \sa FREG_TSD1_SetLinPacket2
** \sa FREG_TSD2_SetLinPacket2
** \sa FREG_TSD3_SetLinPacket2
**
********************************************************************************
*/
INLINE void tsdSetLinPacket2(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket2(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket2(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket2(index, value);
    else
        FREG_TSD3_SetLinPacket2(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket2_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket2_TspWord
** \sa FREG_TSD1_SetLinPacket2_TspWord
** \sa FREG_TSD2_SetLinPacket2_TspWord
** \sa FREG_TSD3_SetLinPacket2_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacket2_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket2_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket2_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket2_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacket2_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket3
** \sa FREG_TSD1_SetLinPacket3
** \sa FREG_TSD2_SetLinPacket3
** \sa FREG_TSD3_SetLinPacket3
**
********************************************************************************
*/
INLINE void tsdSetLinPacket3(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket3(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket3(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket3(index, value);
    else
        FREG_TSD3_SetLinPacket3(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacket3_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacket3_TspWord
** \sa FREG_TSD1_SetLinPacket3_TspWord
** \sa FREG_TSD2_SetLinPacket3_TspWord
** \sa FREG_TSD3_SetLinPacket3_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacket3_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacket3_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacket3_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacket3_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacket3_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto0
** \sa FREG_TSD1_SetLinPacketAuto0
** \sa FREG_TSD2_SetLinPacketAuto0
** \sa FREG_TSD3_SetLinPacketAuto0
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto0(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto0(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto0(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto0(index, value);
    else
        FREG_TSD3_SetLinPacketAuto0(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto0_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto0_TspWord
** \sa FREG_TSD1_SetLinPacketAuto0_TspWord
** \sa FREG_TSD2_SetLinPacketAuto0_TspWord
** \sa FREG_TSD3_SetLinPacketAuto0_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto0_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto0_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto0_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto0_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacketAuto0_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto1
** \sa FREG_TSD1_SetLinPacketAuto1
** \sa FREG_TSD2_SetLinPacketAuto1
** \sa FREG_TSD3_SetLinPacketAuto1
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto1(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto1(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto1(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto1(index, value);
    else
        FREG_TSD3_SetLinPacketAuto1(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto1_TspWord
** \sa FREG_TSD1_SetLinPacketAuto1_TspWord
** \sa FREG_TSD2_SetLinPacketAuto1_TspWord
** \sa FREG_TSD3_SetLinPacketAuto1_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto1_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto1_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto1_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto1_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacketAuto1_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto2
** \sa FREG_TSD1_SetLinPacketAuto2
** \sa FREG_TSD2_SetLinPacketAuto2
** \sa FREG_TSD3_SetLinPacketAuto2
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto2(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto2(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto2(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto2(index, value);
    else
        FREG_TSD3_SetLinPacketAuto2(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto2_TspWord
** \sa FREG_TSD1_SetLinPacketAuto2_TspWord
** \sa FREG_TSD2_SetLinPacketAuto2_TspWord
** \sa FREG_TSD3_SetLinPacketAuto2_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto2_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto2_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto2_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto2_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacketAuto2_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto3
** \sa FREG_TSD1_SetLinPacketAuto3
** \sa FREG_TSD2_SetLinPacketAuto3
** \sa FREG_TSD3_SetLinPacketAuto3
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto3(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto3(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto3(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto3(index, value);
    else
        FREG_TSD3_SetLinPacketAuto3(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetLinPacketAuto3_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetLinPacketAuto3_TspWord
** \sa FREG_TSD1_SetLinPacketAuto3_TspWord
** \sa FREG_TSD2_SetLinPacketAuto3_TspWord
** \sa FREG_TSD3_SetLinPacketAuto3_TspWord
**
********************************************************************************
*/
INLINE void tsdSetLinPacketAuto3_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetLinPacketAuto3_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetLinPacketAuto3_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetLinPacketAuto3_TspWord(index, value);
    else
        FREG_TSD3_SetLinPacketAuto3_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket0
** \sa FREG_TSD1_SetPacket0
** \sa FREG_TSD2_SetPacket0
** \sa FREG_TSD3_SetPacket0
**
********************************************************************************
*/
INLINE void tsdSetPacket0(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket0(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket0(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket0(index, value);
    else
        FREG_TSD3_SetPacket0(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket0_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket0_TspWord
** \sa FREG_TSD1_SetPacket0_TspWord
** \sa FREG_TSD2_SetPacket0_TspWord
** \sa FREG_TSD3_SetPacket0_TspWord
**
********************************************************************************
*/
INLINE void tsdSetPacket0_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket0_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket0_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket0_TspWord(index, value);
    else
        FREG_TSD3_SetPacket0_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket1
** \sa FREG_TSD1_SetPacket1
** \sa FREG_TSD2_SetPacket1
** \sa FREG_TSD3_SetPacket1
**
********************************************************************************
*/
INLINE void tsdSetPacket1(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket1(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket1(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket1(index, value);
    else
        FREG_TSD3_SetPacket1(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket1_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket1_TspWord
** \sa FREG_TSD1_SetPacket1_TspWord
** \sa FREG_TSD2_SetPacket1_TspWord
** \sa FREG_TSD3_SetPacket1_TspWord
**
********************************************************************************
*/
INLINE void tsdSetPacket1_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket1_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket1_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket1_TspWord(index, value);
    else
        FREG_TSD3_SetPacket1_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket2
** \sa FREG_TSD1_SetPacket2
** \sa FREG_TSD2_SetPacket2
** \sa FREG_TSD3_SetPacket2
**
********************************************************************************
*/
INLINE void tsdSetPacket2(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket2(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket2(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket2(index, value);
    else
        FREG_TSD3_SetPacket2(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket2_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket2_TspWord
** \sa FREG_TSD1_SetPacket2_TspWord
** \sa FREG_TSD2_SetPacket2_TspWord
** \sa FREG_TSD3_SetPacket2_TspWord
**
********************************************************************************
*/
INLINE void tsdSetPacket2_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket2_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket2_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket2_TspWord(index, value);
    else
        FREG_TSD3_SetPacket2_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket3
** \sa FREG_TSD1_SetPacket3
** \sa FREG_TSD2_SetPacket3
** \sa FREG_TSD3_SetPacket3
**
********************************************************************************
*/
INLINE void tsdSetPacket3(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket3(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket3(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket3(index, value);
    else
        FREG_TSD3_SetPacket3(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacket3_TspWord function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacket3_TspWord
** \sa FREG_TSD1_SetPacket3_TspWord
** \sa FREG_TSD2_SetPacket3_TspWord
** \sa FREG_TSD3_SetPacket3_TspWord
**
********************************************************************************
*/
INLINE void tsdSetPacket3_TspWord(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacket3_TspWord(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacket3_TspWord(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacket3_TspWord(index, value);
    else
        FREG_TSD3_SetPacket3_TspWord(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacketCtrl
** \sa FREG_TSD1_SetPacketCtrl
** \sa FREG_TSD2_SetPacketCtrl
** \sa FREG_TSD3_SetPacketCtrl
**
********************************************************************************
*/
INLINE void tsdSetPacketCtrl(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacketCtrl(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacketCtrl(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacketCtrl(value);
    else
        FREG_TSD3_SetPacketCtrl(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCtrl_PacketBufValid0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacketCtrl_PacketBufValid0
** \sa FREG_TSD1_SetPacketCtrl_PacketBufValid0
** \sa FREG_TSD2_SetPacketCtrl_PacketBufValid0
** \sa FREG_TSD3_SetPacketCtrl_PacketBufValid0
**
********************************************************************************
*/
INLINE void tsdSetPacketCtrl_PacketBufValid0(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacketCtrl_PacketBufValid0(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacketCtrl_PacketBufValid0(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacketCtrl_PacketBufValid0(value);
    else
        FREG_TSD3_SetPacketCtrl_PacketBufValid0(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCtrl_PacketBufValid1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacketCtrl_PacketBufValid1
** \sa FREG_TSD1_SetPacketCtrl_PacketBufValid1
** \sa FREG_TSD2_SetPacketCtrl_PacketBufValid1
** \sa FREG_TSD3_SetPacketCtrl_PacketBufValid1
**
********************************************************************************
*/
INLINE void tsdSetPacketCtrl_PacketBufValid1(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacketCtrl_PacketBufValid1(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacketCtrl_PacketBufValid1(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacketCtrl_PacketBufValid1(value);
    else
        FREG_TSD3_SetPacketCtrl_PacketBufValid1(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCtrl_PacketBufValid2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacketCtrl_PacketBufValid2
** \sa FREG_TSD1_SetPacketCtrl_PacketBufValid2
** \sa FREG_TSD2_SetPacketCtrl_PacketBufValid2
** \sa FREG_TSD3_SetPacketCtrl_PacketBufValid2
**
********************************************************************************
*/
INLINE void tsdSetPacketCtrl_PacketBufValid2(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacketCtrl_PacketBufValid2(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacketCtrl_PacketBufValid2(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacketCtrl_PacketBufValid2(value);
    else
        FREG_TSD3_SetPacketCtrl_PacketBufValid2(value);
}

/*
********************************************************************************
**
** \brief tsdSetPacketCtrl_PacketBufValid3 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPacketCtrl_PacketBufValid3
** \sa FREG_TSD1_SetPacketCtrl_PacketBufValid3
** \sa FREG_TSD2_SetPacketCtrl_PacketBufValid3
** \sa FREG_TSD3_SetPacketCtrl_PacketBufValid3
**
********************************************************************************
*/
INLINE void tsdSetPacketCtrl_PacketBufValid3(uint32_t blockIndex, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPacketCtrl_PacketBufValid3(value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPacketCtrl_PacketBufValid3(value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPacketCtrl_PacketBufValid3(value);
    else
        FREG_TSD3_SetPacketCtrl_PacketBufValid3(value);
}

/*
********************************************************************************
**
** \brief tsdSetPidChannelActive function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidChannelActive
** \sa FREG_TSD1_SetPidChannelActive
** \sa FREG_TSD2_SetPidChannelActive
** \sa FREG_TSD3_SetPidChannelActive
**
********************************************************************************
*/
INLINE void tsdSetPidChannelActive(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidChannelActive(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidChannelActive(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidChannelActive(index, value);
    else
        FREG_TSD3_SetPidChannelActive(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidChannelActive_FirstPacketFlag function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidChannelActive_FirstPacketFlag
** \sa FREG_TSD1_SetPidChannelActive_FirstPacketFlag
** \sa FREG_TSD2_SetPidChannelActive_FirstPacketFlag
** \sa FREG_TSD3_SetPidChannelActive_FirstPacketFlag
**
********************************************************************************
*/
INLINE void tsdSetPidChannelActive_FirstPacketFlag(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidChannelActive_FirstPacketFlag(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidChannelActive_FirstPacketFlag(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidChannelActive_FirstPacketFlag(index, value);
    else
        FREG_TSD3_SetPidChannelActive_FirstPacketFlag(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidChannelActive_PidChannelEnable function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidChannelActive_PidChannelEnable
** \sa FREG_TSD1_SetPidChannelActive_PidChannelEnable
** \sa FREG_TSD2_SetPidChannelActive_PidChannelEnable
** \sa FREG_TSD3_SetPidChannelActive_PidChannelEnable
**
********************************************************************************
*/
INLINE void tsdSetPidChannelActive_PidChannelEnable(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidChannelActive_PidChannelEnable(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidChannelActive_PidChannelEnable(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidChannelActive_PidChannelEnable(index, value);
    else
        FREG_TSD3_SetPidChannelActive_PidChannelEnable(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1
** \sa FREG_TSD1_SetPidConfig_1
** \sa FREG_TSD2_SetPidConfig_1
** \sa FREG_TSD3_SetPidConfig_1
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1(index, value);
    else
        FREG_TSD3_SetPidConfig_1(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_BufferIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_BufferIndex
** \sa FREG_TSD1_SetPidConfig_1_BufferIndex
** \sa FREG_TSD2_SetPidConfig_1_BufferIndex
** \sa FREG_TSD3_SetPidConfig_1_BufferIndex
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_BufferIndex(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_BufferIndex(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_BufferIndex(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_BufferIndex(index, value);
    else
        FREG_TSD3_SetPidConfig_1_BufferIndex(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_DescramblerIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_DescramblerIndex
** \sa FREG_TSD1_SetPidConfig_1_DescramblerIndex
** \sa FREG_TSD2_SetPidConfig_1_DescramblerIndex
** \sa FREG_TSD3_SetPidConfig_1_DescramblerIndex
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_DescramblerIndex(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_DescramblerIndex(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_DescramblerIndex(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_DescramblerIndex(index, value);
    else
        FREG_TSD3_SetPidConfig_1_DescramblerIndex(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_DuplicateIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_DuplicateIrqEn
** \sa FREG_TSD1_SetPidConfig_1_DuplicateIrqEn
** \sa FREG_TSD2_SetPidConfig_1_DuplicateIrqEn
** \sa FREG_TSD3_SetPidConfig_1_DuplicateIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_DuplicateIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_DuplicateIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_DuplicateIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_DuplicateIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_1_DuplicateIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_NullPacketIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_NullPacketIrqEn
** \sa FREG_TSD1_SetPidConfig_1_NullPacketIrqEn
** \sa FREG_TSD2_SetPidConfig_1_NullPacketIrqEn
** \sa FREG_TSD3_SetPidConfig_1_NullPacketIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_NullPacketIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_NullPacketIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_NullPacketIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_NullPacketIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_1_NullPacketIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_OffsetMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_OffsetMode
** \sa FREG_TSD1_SetPidConfig_1_OffsetMode
** \sa FREG_TSD2_SetPidConfig_1_OffsetMode
** \sa FREG_TSD3_SetPidConfig_1_OffsetMode
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_OffsetMode(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_OffsetMode(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_OffsetMode(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_OffsetMode(index, value);
    else
        FREG_TSD3_SetPidConfig_1_OffsetMode(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_Pcr1AfLt7IrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_Pcr1AfLt7IrqEn
** \sa FREG_TSD1_SetPidConfig_1_Pcr1AfLt7IrqEn
** \sa FREG_TSD2_SetPidConfig_1_Pcr1AfLt7IrqEn
** \sa FREG_TSD3_SetPidConfig_1_Pcr1AfLt7IrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_Pcr1AfLt7IrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_Pcr1AfLt7IrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_Pcr1AfLt7IrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_Pcr1AfLt7IrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_1_Pcr1AfLt7IrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_Pl0AfNe183IrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_Pl0AfNe183IrqEn
** \sa FREG_TSD1_SetPidConfig_1_Pl0AfNe183IrqEn
** \sa FREG_TSD2_SetPidConfig_1_Pl0AfNe183IrqEn
** \sa FREG_TSD3_SetPidConfig_1_Pl0AfNe183IrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_Pl0AfNe183IrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_Pl0AfNe183IrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_Pl0AfNe183IrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_Pl0AfNe183IrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_1_Pl0AfNe183IrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_1_Pl1AfGt183IrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_1_Pl1AfGt183IrqEn
** \sa FREG_TSD1_SetPidConfig_1_Pl1AfGt183IrqEn
** \sa FREG_TSD2_SetPidConfig_1_Pl1AfGt183IrqEn
** \sa FREG_TSD3_SetPidConfig_1_Pl1AfGt183IrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_1_Pl1AfGt183IrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_1_Pl1AfGt183IrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_1_Pl1AfGt183IrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_1_Pl1AfGt183IrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_1_Pl1AfGt183IrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2
** \sa FREG_TSD1_SetPidConfig_2
** \sa FREG_TSD2_SetPidConfig_2
** \sa FREG_TSD3_SetPidConfig_2
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2(index, value);
    else
        FREG_TSD3_SetPidConfig_2(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_BypassDsc function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_BypassDsc
** \sa FREG_TSD1_SetPidConfig_2_BypassDsc
** \sa FREG_TSD2_SetPidConfig_2_BypassDsc
** \sa FREG_TSD3_SetPidConfig_2_BypassDsc
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_BypassDsc(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_BypassDsc(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_BypassDsc(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_BypassDsc(index, value);
    else
        FREG_TSD3_SetPidConfig_2_BypassDsc(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_CcCheck function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_CcCheck
** \sa FREG_TSD1_SetPidConfig_2_CcCheck
** \sa FREG_TSD2_SetPidConfig_2_CcCheck
** \sa FREG_TSD3_SetPidConfig_2_CcCheck
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_CcCheck(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_CcCheck(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_CcCheck(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_CcCheck(index, value);
    else
        FREG_TSD3_SetPidConfig_2_CcCheck(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_CcIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_CcIrqEn
** \sa FREG_TSD1_SetPidConfig_2_CcIrqEn
** \sa FREG_TSD2_SetPidConfig_2_CcIrqEn
** \sa FREG_TSD3_SetPidConfig_2_CcIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_CcIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_CcIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_CcIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_CcIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_CcIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_CrcErrIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_CrcErrIrqEn
** \sa FREG_TSD1_SetPidConfig_2_CrcErrIrqEn
** \sa FREG_TSD2_SetPidConfig_2_CrcErrIrqEn
** \sa FREG_TSD3_SetPidConfig_2_CrcErrIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_CrcErrIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_CrcErrIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_CrcErrIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_CrcErrIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_CrcErrIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_DuplicateCheck function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_DuplicateCheck
** \sa FREG_TSD1_SetPidConfig_2_DuplicateCheck
** \sa FREG_TSD2_SetPidConfig_2_DuplicateCheck
** \sa FREG_TSD3_SetPidConfig_2_DuplicateCheck
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_DuplicateCheck(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_DuplicateCheck(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_DuplicateCheck(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_DuplicateCheck(index, value);
    else
        FREG_TSD3_SetPidConfig_2_DuplicateCheck(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_ExtractPcr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_ExtractPcr
** \sa FREG_TSD1_SetPidConfig_2_ExtractPcr
** \sa FREG_TSD2_SetPidConfig_2_ExtractPcr
** \sa FREG_TSD3_SetPidConfig_2_ExtractPcr
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_ExtractPcr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_ExtractPcr(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_ExtractPcr(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_ExtractPcr(index, value);
    else
        FREG_TSD3_SetPidConfig_2_ExtractPcr(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_InputTimeoutIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_InputTimeoutIrqEn
** \sa FREG_TSD1_SetPidConfig_2_InputTimeoutIrqEn
** \sa FREG_TSD2_SetPidConfig_2_InputTimeoutIrqEn
** \sa FREG_TSD3_SetPidConfig_2_InputTimeoutIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_InputTimeoutIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_InputTimeoutIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_InputTimeoutIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_InputTimeoutIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_InputTimeoutIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_NewPcrIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_NewPcrIrqEn
** \sa FREG_TSD1_SetPidConfig_2_NewPcrIrqEn
** \sa FREG_TSD2_SetPidConfig_2_NewPcrIrqEn
** \sa FREG_TSD3_SetPidConfig_2_NewPcrIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_NewPcrIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_NewPcrIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_NewPcrIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_NewPcrIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_NewPcrIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_NTarget function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_NTarget
** \sa FREG_TSD1_SetPidConfig_2_NTarget
** \sa FREG_TSD2_SetPidConfig_2_NTarget
** \sa FREG_TSD3_SetPidConfig_2_NTarget
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_NTarget(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_NTarget(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_NTarget(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_NTarget(index, value);
    else
        FREG_TSD3_SetPidConfig_2_NTarget(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_PacketEndIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_PacketEndIrqEn
** \sa FREG_TSD1_SetPidConfig_2_PacketEndIrqEn
** \sa FREG_TSD2_SetPidConfig_2_PacketEndIrqEn
** \sa FREG_TSD3_SetPidConfig_2_PacketEndIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_PacketEndIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_PacketEndIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_PacketEndIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_PacketEndIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_PacketEndIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_PesPayload function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_PesPayload
** \sa FREG_TSD1_SetPidConfig_2_PesPayload
** \sa FREG_TSD2_SetPidConfig_2_PesPayload
** \sa FREG_TSD3_SetPidConfig_2_PesPayload
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_PesPayload(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_PesPayload(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_PesPayload(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_PesPayload(index, value);
    else
        FREG_TSD3_SetPidConfig_2_PesPayload(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_PsiCcCheckMode function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_PsiCcCheckMode
** \sa FREG_TSD1_SetPidConfig_2_PsiCcCheckMode
** \sa FREG_TSD2_SetPidConfig_2_PsiCcCheckMode
** \sa FREG_TSD3_SetPidConfig_2_PsiCcCheckMode
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_PsiCcCheckMode(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_PsiCcCheckMode(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_PsiCcCheckMode(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_PsiCcCheckMode(index, value);
    else
        FREG_TSD3_SetPidConfig_2_PsiCcCheckMode(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_PtrTarget function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_PtrTarget
** \sa FREG_TSD1_SetPidConfig_2_PtrTarget
** \sa FREG_TSD2_SetPidConfig_2_PtrTarget
** \sa FREG_TSD3_SetPidConfig_2_PtrTarget
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_PtrTarget(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_PtrTarget(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_PtrTarget(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_PtrTarget(index, value);
    else
        FREG_TSD3_SetPidConfig_2_PtrTarget(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_PusIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_PusIrqEn
** \sa FREG_TSD1_SetPidConfig_2_PusIrqEn
** \sa FREG_TSD2_SetPidConfig_2_PusIrqEn
** \sa FREG_TSD3_SetPidConfig_2_PusIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_PusIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_PusIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_PusIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_PusIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_PusIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_ScrambledPacketIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_ScrambledPacketIrqEn
** \sa FREG_TSD1_SetPidConfig_2_ScrambledPacketIrqEn
** \sa FREG_TSD2_SetPidConfig_2_ScrambledPacketIrqEn
** \sa FREG_TSD3_SetPidConfig_2_ScrambledPacketIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_ScrambledPacketIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_ScrambledPacketIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_ScrambledPacketIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_ScrambledPacketIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_ScrambledPacketIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_SectionEndIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_SectionEndIrqEn
** \sa FREG_TSD1_SetPidConfig_2_SectionEndIrqEn
** \sa FREG_TSD2_SetPidConfig_2_SectionEndIrqEn
** \sa FREG_TSD3_SetPidConfig_2_SectionEndIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_SectionEndIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_SectionEndIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_SectionEndIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_SectionEndIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_SectionEndIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_StoreCompletePacket function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_StoreCompletePacket
** \sa FREG_TSD1_SetPidConfig_2_StoreCompletePacket
** \sa FREG_TSD2_SetPidConfig_2_StoreCompletePacket
** \sa FREG_TSD3_SetPidConfig_2_StoreCompletePacket
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_StoreCompletePacket(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_StoreCompletePacket(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_StoreCompletePacket(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_StoreCompletePacket(index, value);
    else
        FREG_TSD3_SetPidConfig_2_StoreCompletePacket(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_TargetLength function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_TargetLength
** \sa FREG_TSD1_SetPidConfig_2_TargetLength
** \sa FREG_TSD2_SetPidConfig_2_TargetLength
** \sa FREG_TSD3_SetPidConfig_2_TargetLength
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_TargetLength(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_TargetLength(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_TargetLength(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_TargetLength(index, value);
    else
        FREG_TSD3_SetPidConfig_2_TargetLength(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidConfig_2_ValidInputTimeoutIrqEn function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidConfig_2_ValidInputTimeoutIrqEn
** \sa FREG_TSD1_SetPidConfig_2_ValidInputTimeoutIrqEn
** \sa FREG_TSD2_SetPidConfig_2_ValidInputTimeoutIrqEn
** \sa FREG_TSD3_SetPidConfig_2_ValidInputTimeoutIrqEn
**
********************************************************************************
*/
INLINE void tsdSetPidConfig_2_ValidInputTimeoutIrqEn(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidConfig_2_ValidInputTimeoutIrqEn(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidConfig_2_ValidInputTimeoutIrqEn(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidConfig_2_ValidInputTimeoutIrqEn(index, value);
    else
        FREG_TSD3_SetPidConfig_2_ValidInputTimeoutIrqEn(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidValue function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidValue
** \sa FREG_TSD1_SetPidValue
** \sa FREG_TSD2_SetPidValue
** \sa FREG_TSD3_SetPidValue
**
********************************************************************************
*/
INLINE void tsdSetPidValue(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidValue(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidValue(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidValue(index, value);
    else
        FREG_TSD3_SetPidValue(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetPidValue_PidBit function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetPidValue_PidBit
** \sa FREG_TSD1_SetPidValue_PidBit
** \sa FREG_TSD2_SetPidValue_PidBit
** \sa FREG_TSD3_SetPidValue_PidBit
**
********************************************************************************
*/
INLINE void tsdSetPidValue_PidBit(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetPidValue_PidBit(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetPidValue_PidBit(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetPidValue_PidBit(index, value);
    else
        FREG_TSD3_SetPidValue_PidBit(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl
** \sa FREG_TSD1_SetSbCtrl
** \sa FREG_TSD2_SetSbCtrl
** \sa FREG_TSD3_SetSbCtrl
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl(index, value);
    else
        FREG_TSD3_SetSbCtrl(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl_FilterIndex function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl_FilterIndex
** \sa FREG_TSD1_SetSbCtrl_FilterIndex
** \sa FREG_TSD2_SetSbCtrl_FilterIndex
** \sa FREG_TSD3_SetSbCtrl_FilterIndex
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl_FilterIndex(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl_FilterIndex(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl_FilterIndex(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl_FilterIndex(index, value);
    else
        FREG_TSD3_SetSbCtrl_FilterIndex(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl_FilterMatch function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl_FilterMatch
** \sa FREG_TSD1_SetSbCtrl_FilterMatch
** \sa FREG_TSD2_SetSbCtrl_FilterMatch
** \sa FREG_TSD3_SetSbCtrl_FilterMatch
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl_FilterMatch(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl_FilterMatch(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl_FilterMatch(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl_FilterMatch(index, value);
    else
        FREG_TSD3_SetSbCtrl_FilterMatch(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl_PaddingCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl_PaddingCnt
** \sa FREG_TSD1_SetSbCtrl_PaddingCnt
** \sa FREG_TSD2_SetSbCtrl_PaddingCnt
** \sa FREG_TSD3_SetSbCtrl_PaddingCnt
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl_PaddingCnt(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl_PaddingCnt(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl_PaddingCnt(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl_PaddingCnt(index, value);
    else
        FREG_TSD3_SetSbCtrl_PaddingCnt(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl_RdPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl_RdPtr
** \sa FREG_TSD1_SetSbCtrl_RdPtr
** \sa FREG_TSD2_SetSbCtrl_RdPtr
** \sa FREG_TSD3_SetSbCtrl_RdPtr
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl_RdPtr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl_RdPtr(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl_RdPtr(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl_RdPtr(index, value);
    else
        FREG_TSD3_SetSbCtrl_RdPtr(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl_ResidueCnt function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl_ResidueCnt
** \sa FREG_TSD1_SetSbCtrl_ResidueCnt
** \sa FREG_TSD2_SetSbCtrl_ResidueCnt
** \sa FREG_TSD3_SetSbCtrl_ResidueCnt
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl_ResidueCnt(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl_ResidueCnt(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl_ResidueCnt(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl_ResidueCnt(index, value);
    else
        FREG_TSD3_SetSbCtrl_ResidueCnt(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSbCtrl_WrPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSbCtrl_WrPtr
** \sa FREG_TSD1_SetSbCtrl_WrPtr
** \sa FREG_TSD2_SetSbCtrl_WrPtr
** \sa FREG_TSD3_SetSbCtrl_WrPtr
**
********************************************************************************
*/
INLINE void tsdSetSbCtrl_WrPtr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSbCtrl_WrPtr(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSbCtrl_WrPtr(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSbCtrl_WrPtr(index, value);
    else
        FREG_TSD3_SetSbCtrl_WrPtr(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfPtr
** \sa FREG_TSD1_SetSfPtr
** \sa FREG_TSD2_SetSfPtr
** \sa FREG_TSD3_SetSfPtr
**
********************************************************************************
*/
INLINE void tsdSetSfPtr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfPtr(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfPtr(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfPtr(index, value);
    else
        FREG_TSD3_SetSfPtr(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfPtr_Eol function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfPtr_Eol
** \sa FREG_TSD1_SetSfPtr_Eol
** \sa FREG_TSD2_SetSfPtr_Eol
** \sa FREG_TSD3_SetSfPtr_Eol
**
********************************************************************************
*/
INLINE void tsdSetSfPtr_Eol(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfPtr_Eol(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfPtr_Eol(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfPtr_Eol(index, value);
    else
        FREG_TSD3_SetSfPtr_Eol(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfPtr_NxtDepPtr function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfPtr_NxtDepPtr
** \sa FREG_TSD1_SetSfPtr_NxtDepPtr
** \sa FREG_TSD2_SetSfPtr_NxtDepPtr
** \sa FREG_TSD3_SetSfPtr_NxtDepPtr
**
********************************************************************************
*/
INLINE void tsdSetSfPtr_NxtDepPtr(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfPtr_NxtDepPtr(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfPtr_NxtDepPtr(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfPtr_NxtDepPtr(index, value);
    else
        FREG_TSD3_SetSfPtr_NxtDepPtr(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfTargets function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfTargets
** \sa FREG_TSD1_SetSfTargets
** \sa FREG_TSD2_SetSfTargets
** \sa FREG_TSD3_SetSfTargets
**
********************************************************************************
*/
INLINE void tsdSetSfTargets(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfTargets(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfTargets(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfTargets(index, value);
    else
        FREG_TSD3_SetSfTargets(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfTargets_FilterEnable0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfTargets_FilterEnable0
** \sa FREG_TSD1_SetSfTargets_FilterEnable0
** \sa FREG_TSD2_SetSfTargets_FilterEnable0
** \sa FREG_TSD3_SetSfTargets_FilterEnable0
**
********************************************************************************
*/
INLINE void tsdSetSfTargets_FilterEnable0(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfTargets_FilterEnable0(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfTargets_FilterEnable0(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfTargets_FilterEnable0(index, value);
    else
        FREG_TSD3_SetSfTargets_FilterEnable0(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfTargets_FilterEnable1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfTargets_FilterEnable1
** \sa FREG_TSD1_SetSfTargets_FilterEnable1
** \sa FREG_TSD2_SetSfTargets_FilterEnable1
** \sa FREG_TSD3_SetSfTargets_FilterEnable1
**
********************************************************************************
*/
INLINE void tsdSetSfTargets_FilterEnable1(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfTargets_FilterEnable1(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfTargets_FilterEnable1(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfTargets_FilterEnable1(index, value);
    else
        FREG_TSD3_SetSfTargets_FilterEnable1(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfTargets_SecData0 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfTargets_SecData0
** \sa FREG_TSD1_SetSfTargets_SecData0
** \sa FREG_TSD2_SetSfTargets_SecData0
** \sa FREG_TSD3_SetSfTargets_SecData0
**
********************************************************************************
*/
INLINE void tsdSetSfTargets_SecData0(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfTargets_SecData0(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfTargets_SecData0(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfTargets_SecData0(index, value);
    else
        FREG_TSD3_SetSfTargets_SecData0(index, value);
}

/*
********************************************************************************
**
** \brief tsdSetSfTargets_SecData1 function handler.
**
** This function handles the described function according to the specified
** hardware block.
**
** \sa FREG_TSD0_SetSfTargets_SecData1
** \sa FREG_TSD1_SetSfTargets_SecData1
** \sa FREG_TSD2_SetSfTargets_SecData1
** \sa FREG_TSD3_SetSfTargets_SecData1
**
********************************************************************************
*/
INLINE void tsdSetSfTargets_SecData1(uint32_t blockIndex, uint32_t index, uint32_t value)
{
    if(blockIndex == FAPI_TSD0)
        FREG_TSD0_SetSfTargets_SecData1(index, value);
    else if(blockIndex == FAPI_TSD1)
        FREG_TSD1_SetSfTargets_SecData1(index, value);
    else if(blockIndex == FAPI_TSD2)
        FREG_TSD2_SetSfTargets_SecData1(index, value);
    else
        FREG_TSD3_SetSfTargets_SecData1(index, value);
}

#endif
