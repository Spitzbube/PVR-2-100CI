/******************************************************************************
**
** \file      gh_sdio.c
**
** \brief     SDIO.
**
**            Copyright:   2012 - 2013 (C) GoKe Microelectronics ShangHai Branch
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** \note      Do not modify this file as it is generated automatically.
**
******************************************************************************/
#include "gh_sdio.h"
#include <asm/io.h>
#include <asm/arch-gk7101/io.h>

/*----------------------------------------------------------------------------*/
/* mirror variables                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* register SDIO_SysAddrReg (read/write)                                      */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_SysAddrReg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SysAddrReg] <-- 0x%08x\n",
                        (REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_SysAddrReg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SysAddrReg] --> 0x%08x\n",
                        (REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_MOD (read/write)                                             */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_MOD(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_MOD(U8 index)
{
    U16 value = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_MOD_BlkCountEn(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkcounten = data;
    gk_sd_writew(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_BlkCountEn] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_MOD_BlkCountEn(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_BlkCountEn] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkcounten;
}
void GH_SDIO_set_MOD_AutoCmd12En(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12en = data;
    gk_sd_writew(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_AutoCmd12En] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_MOD_AutoCmd12En(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_AutoCmd12En] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12en;
}
void GH_SDIO_set_MOD_DmaEn(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaen = data;
    gk_sd_writew((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_DmaEn] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_MOD_DmaEn(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_DmaEn] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaen;
}
void GH_SDIO_set_MOD_MSBlkSelect(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.msblkselect = data;
    gk_sd_writew((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_MSBlkSelect] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_MOD_MSBlkSelect(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_MSBlkSelect] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.msblkselect;
}
void GH_SDIO_set_MOD_DataTraDirSelect(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = gk_sd_readw(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatradirselect = data;
    gk_sd_writew((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_DataTraDirSelect] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_MOD_DataTraDirSelect(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_DataTraDirSelect] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatradirselect;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_NOR_INT_SIG_EN (read/write)                                  */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_NOR_INT_SIG_EN(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_NOR_INT_SIG_EN(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_NOR_INT_SIG_EN_CmdCompleteSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcompletesigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CmdCompleteSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_CmdCompleteSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CmdCompleteSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcompletesigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_TraCompleteSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.tracompletesigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_TraCompleteSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_TraCompleteSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_TraCompleteSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.tracompletesigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_BlkGapEveSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkgapevesigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_BlkGapEveSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_BlkGapEveSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_BlkGapEveSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkgapevesigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_DmaIntSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaintsigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_DmaIntSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_DmaIntSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_DmaIntSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaintsigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_BufWReadySigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufwreadysigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_BufWReadySigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_BufWReadySigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_BufWReadySigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwreadysigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_BufRReadySigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufrreadysigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_BufRReadySigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_BufRReadySigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_BufRReadySigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufrreadysigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_CardInsertionSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardinsertionsigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CardInsertionSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_CardInsertionSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CardInsertionSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinsertionsigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_CardRemSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardremsigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CardRemSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_CardRemSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CardRemSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardremsigen;
}
void GH_SDIO_set_NOR_INT_SIG_EN_CardIntSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardintsigen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CardIntSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_SIG_EN_CardIntSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CardIntSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardintsigen;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_ERR_INT_SIG_EN (read/write)                                  */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_ERR_INT_SIG_EN(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_ERR_INT_SIG_EN(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_ERR_INT_SIG_EN_CmdTimeoutErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtimeouterrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdTimeoutErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdTimeoutErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdTimeoutErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtimeouterrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_CmdEndBitErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdendbiterrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdEndBitErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdEndBitErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdEndBitErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdendbiterrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_CmdIndexErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexerrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdIndexErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdIndexErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdIndexErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexerrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_DataTimeoutErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeouterrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_DataTimeoutErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_DataTimeoutErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_DataTimeoutErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeouterrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_CmdCrcErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcerrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdCrcErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdCrcErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdCrcErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcerrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_DataCrcErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datacrcerrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_DataCrcErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_DataCrcErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_DataCrcErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datacrcerrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_DataEndBitErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dataendbiterrsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_DataEndBitErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_DataEndBitErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_DataEndBitErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dataendbiterrsigen;
}
void GH_SDIO_set_ERR_INT_SIG_EN_AutoCmd12ErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12errsigen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_AutoCmd12ErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_SIG_EN_AutoCmd12ErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_AutoCmd12ErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12errsigen;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_BLK_COU (read/write)                                         */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_BLK_COU(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_COU] <-- 0x%08x\n",
                        (REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_BLK_COU(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BLK_COU] --> 0x%08x\n",
                        (REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_BLK_SIZ (read/write)                                         */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_BLK_SIZ(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_SIZ] <-- 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_BLK_SIZ(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BLK_SIZ] --> 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_BLK_SIZ_TraBlkSize(U8 index, U16 data)
{
    GH_SDIO_BLK_SIZ_S d;
    d.all = gk_sd_readw(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.trablksize = data;
    gk_sd_writew((REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_SIZ_TraBlkSize] <-- 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U16  GH_SDIO_get_BLK_SIZ_TraBlkSize(U8 index)
{
    GH_SDIO_BLK_SIZ_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BLK_SIZ_TraBlkSize] --> 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.trablksize;
}
void GH_SDIO_set_BLK_SIZ_HostSdmaBufSize(U8 index, U8 data)
{
    GH_SDIO_BLK_SIZ_S d;
    d.all = gk_sd_readw(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.hostsdmabufsize = data;
    gk_sd_writew((REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_SIZ_HostSdmaBufSize] <-- 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_BLK_SIZ_HostSdmaBufSize(U8 index)
{
    GH_SDIO_BLK_SIZ_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BLK_SIZ_HostSdmaBufSize] --> 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.hostsdmabufsize;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_NOR_INT_STA_EN (read/write)                                  */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_NOR_INT_STA_EN(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_NOR_INT_STA_EN(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_NOR_INT_STA_EN_CmdCompleteStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcompletestatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CmdCompleteStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_CmdCompleteStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CmdCompleteStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcompletestatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_TraCompleteStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.tracompletestatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_TraCompleteStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_TraCompleteStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_TraCompleteStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.tracompletestatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_BlkGapEveStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkgapevestatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_BlkGapEveStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_BlkGapEveStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_BlkGapEveStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkgapevestatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_dmaIntStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaintstatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_dmaIntStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_dmaIntStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_dmaIntStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaintstatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_BufWReadyStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufwreadystatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_BufWReadyStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_BufWReadyStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_BufWReadyStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwreadystatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_BufRReadyStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufrreadystatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_BufRReadyStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_BufRReadyStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_BufRReadyStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufrreadystatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_CardInsertionStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardinsertionstatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CardInsertionStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_CardInsertionStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CardInsertionStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinsertionstatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_CardRemStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardremstatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CardRemStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_CardRemStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CardRemStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardremstatusen;
}
void GH_SDIO_set_NOR_INT_STA_EN_CardIntStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardintstatusen = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CardIntStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_EN_CardIntStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CardIntStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardintstatusen;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_ERR_INT_STA_EN (read/write)                                  */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_ERR_INT_STA_EN(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_ERR_INT_STA_EN(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_ERR_INT_STA_EN_CmdTimeoutErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtimeouterrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdTimeoutErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdTimeoutErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdTimeoutErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtimeouterrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_CmdEndBitErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdendbiterrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdEndBitErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdEndBitErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdEndBitErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdendbiterrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_CmdCrcErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcerrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdCrcErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdCrcErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdCrcErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcerrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_CmdIndexErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexerrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdIndexErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdIndexErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdIndexErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexerrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_DataCrcErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datacrcerrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_DataCrcErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_DataCrcErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_DataCrcErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datacrcerrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_DataTimeoutErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeouterrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_DataTimeoutErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_DataTimeoutErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_DataTimeoutErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeouterrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_DataEndBitErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dataendbiterrstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_DataEndBitErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_DataEndBitErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_DataEndBitErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dataendbiterrstatusen;
}
void GH_SDIO_set_ERR_INT_STA_EN_AutoCmd12ErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12errstatusen = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_AutoCmd12ErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_EN_AutoCmd12ErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_AutoCmd12ErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12errstatusen;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_NOR_INT_STA (read/write)                                     */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_NOR_INT_STA(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)), data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_NOR_INT_STA(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_NOR_INT_STA_CmdComplete(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcomplete = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CmdComplete] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_CmdComplete(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CmdComplete] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcomplete;
}
void GH_SDIO_set_NOR_INT_STA_BlkGapEvent(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkgapevent = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_BlkGapEvent] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_BlkGapEvent(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_BlkGapEvent] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkgapevent;
}
void GH_SDIO_set_NOR_INT_STA_DmaInt(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaint = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_DmaInt] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_DmaInt(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_DmaInt] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaint;
}
void GH_SDIO_set_NOR_INT_STA_TraComplete(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.tracomplete = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_TraComplete] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_TraComplete(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_TraComplete] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.tracomplete;
}
void GH_SDIO_set_NOR_INT_STA_BufWReady(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufwready = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_BufWReady] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_BufWReady(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_BufWReady] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwready;
}
void GH_SDIO_set_NOR_INT_STA_CardInsertion(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardinsertion = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CardInsertion] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_CardInsertion(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CardInsertion] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinsertion;
}
void GH_SDIO_set_NOR_INT_STA_BufRReady(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufrready = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_BufRReady] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_BufRReady(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_BufRReady] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufrready;
}
void GH_SDIO_set_NOR_INT_STA_CardRemoval(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardremoval = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CardRemoval] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_CardRemoval(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CardRemoval] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardremoval;
}
void GH_SDIO_set_NOR_INT_STA_CardInt(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardint = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CardInt] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_CardInt(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CardInt] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardint;
}
void GH_SDIO_set_NOR_INT_STA_ErrInt(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.errint = data;
    gk_sd_writew((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_ErrInt] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_NOR_INT_STA_ErrInt(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_ErrInt] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.errint;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_ERR_INT_STA (read/write)                                     */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_ERR_INT_STA(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_ERR_INT_STA(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_ERR_INT_STA_CmdTimeoutErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtimeouterr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdTimeoutErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_CmdTimeoutErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdTimeoutErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtimeouterr;
}
void GH_SDIO_set_ERR_INT_STA_CmdCrcErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcerr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdCrcErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_CmdCrcErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdCrcErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcerr;
}
void GH_SDIO_set_ERR_INT_STA_CmdEndBitErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdendbiterr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdEndBitErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_CmdEndBitErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdEndBitErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdendbiterr;
}
void GH_SDIO_set_ERR_INT_STA_CmdIndexErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexerr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdIndexErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_CmdIndexErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdIndexErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexerr;
}
void GH_SDIO_set_ERR_INT_STA_DataTimeoutErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeouterr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_DataTimeoutErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_DataTimeoutErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_DataTimeoutErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeouterr;
}
void GH_SDIO_set_ERR_INT_STA_DataCrcErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datacrcerr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_DataCrcErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_DataCrcErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_DataCrcErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datacrcerr;
}
void GH_SDIO_set_ERR_INT_STA_DataEndBitErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dataendbiterr = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_DataEndBitErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_DataEndBitErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_DataEndBitErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dataendbiterr;
}
void GH_SDIO_set_ERR_INT_STA_AutoCmd12Err(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = gk_sd_readw(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12err = data;
    gk_sd_writew((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_AutoCmd12Err] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_ERR_INT_STA_AutoCmd12Err(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_AutoCmd12Err] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12err;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_COMM (read/write)                                            */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_COMM(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_COMM(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_COMM_RepTypeSelect(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = gk_sd_readw(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.reptypeselect = data;
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_RepTypeSelect] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_COMM_RepTypeSelect(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_RepTypeSelect] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.reptypeselect;
}
void GH_SDIO_set_COMM_CmdCrcCheckEn(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = gk_sd_readw(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcchecken = data;
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdCrcCheckEn] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_COMM_CmdCrcCheckEn(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdCrcCheckEn] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcchecken;
}
void GH_SDIO_set_COMM_DataPreSelect(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = gk_sd_readw(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datapreselect = data;
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_DataPreSelect] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_COMM_DataPreSelect(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_DataPreSelect] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datapreselect;
}
void GH_SDIO_set_COMM_CmdIndexCheckEn(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = gk_sd_readw(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexchecken = data;
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdIndexCheckEn] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_COMM_CmdIndexCheckEn(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdIndexCheckEn] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexchecken;
}
void GH_SDIO_set_COMM_CmdType(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = gk_sd_readw(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtype = data;
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdType] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_COMM_CmdType(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdType] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtype;
}
void GH_SDIO_set_COMM_CmdIndex(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = gk_sd_readw(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindex = data;
    gk_sd_writew((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdIndex] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_COMM_CmdIndex(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdIndex] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindex;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_SF_RST_CTRL (read/write)                                     */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_SF_RST_CTRL(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_SF_RST_CTRL(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_SF_RST_CTRL_DataTimeoutCounterValue(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeoutcountervalue = data;
    gk_sd_writew((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_DataTimeoutCounterValue] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_SF_RST_CTRL_DataTimeoutCounterValue(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_DataTimeoutCounterValue] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeoutcountervalue;
}
void GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.softwareresetcmdline = data;
    gk_sd_writew((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetCmdLine(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_SoftwareResetCmdLine] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.softwareresetcmdline;
}
void GH_SDIO_set_SF_RST_CTRL_SoftwareResetAll(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.softwareresetall = data;
    gk_sd_writew((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_SoftwareResetAll] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetAll(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_SoftwareResetAll] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.softwareresetall;
}
void GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.softwareresetdatline = data;
    gk_sd_writew((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetDatLine(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_SoftwareResetDatLine] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.softwareresetdatline;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_CLK_CTRL (read/write)                                        */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_CLK_CTRL(U8 index, U16 data)
{
    gk_sd_writew((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U16  GH_SDIO_get_CLK_CTRL(U8 index)
{
    U16 value = gk_sd_readw((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_CLK_CTRL_InternalClkEn(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.internalclken = data;
    gk_sd_writew((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_InternalClkEn] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_CLK_CTRL_InternalClkEn(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_InternalClkEn] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.internalclken;
}
void GH_SDIO_set_CLK_CTRL_InternalClkStable(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.internalclkstable = data;
    gk_sd_writew((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_InternalClkStable] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_CLK_CTRL_InternalClkStable(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_InternalClkStable] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.internalclkstable;
}
void GH_SDIO_set_CLK_CTRL_SdClkEn(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sdclken = data;
    gk_sd_writew((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_SdClkEn] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_CLK_CTRL_SdClkEn(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_SdClkEn] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdclken;
}
void GH_SDIO_set_CLK_CTRL_SdclkFreSelect(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = gk_sd_readw(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sdclkfreselect = data;
    gk_sd_writew((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_SdclkFreSelect] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_CLK_CTRL_SdclkFreSelect(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = gk_sd_readw((REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_SdclkFreSelect] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdclkfreselect;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_Resp0Reg (read/write)                                        */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_Resp0Reg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp0Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_Resp0Reg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Resp0Reg] --> 0x%08x\n",
                        (REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_Resp1Reg (read/write)                                        */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_Resp1Reg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp1Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_Resp1Reg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Resp1Reg] --> 0x%08x\n",
                        (REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_Resp2Reg (read/write)                                        */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_Resp2Reg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp2Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_Resp2Reg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Resp2Reg] --> 0x%08x\n",
                        (REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_Resp3Reg (read/write)                                        */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_Resp3Reg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp3Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_Resp3Reg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Resp3Reg] --> 0x%08x\n",
                        (REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_Control00Reg (read/write)                                    */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_Control00Reg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_Control00Reg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_Control00Reg_DataTraWidth(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatrawidth = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_DataTraWidth] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_DataTraWidth(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_DataTraWidth] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatrawidth;
}
void GH_SDIO_set_Control00Reg_Sd8BitMode(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sd8bitmode = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_Sd8BitMode] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_Sd8BitMode(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_Sd8BitMode] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sd8bitmode;
}
void GH_SDIO_set_Control00Reg_HostSpeedEn(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.hostspeeden = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_HostSpeedEn] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_HostSpeedEn(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_HostSpeedEn] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.hostspeeden;
}
void GH_SDIO_set_Control00Reg_SdBusPower(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sdbuspower = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_SdBusPower] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_SdBusPower(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_SdBusPower] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdbuspower;
}
void GH_SDIO_set_Control00Reg_DriveCcsd(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.driveccsd = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_DriveCcsd] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_DriveCcsd(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_DriveCcsd] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.driveccsd;
}
void GH_SDIO_set_Control00Reg_StopAtBlkGapReq(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.stopatblkgapreq = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_StopAtBlkGapReq] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_StopAtBlkGapReq(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_StopAtBlkGapReq] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.stopatblkgapreq;
}
void GH_SDIO_set_Control00Reg_RWaitControl(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.rwaitcontrol = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_RWaitControl] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_RWaitControl(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_RWaitControl] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.rwaitcontrol;
}
void GH_SDIO_set_Control00Reg_ContinueReq(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.continuereq = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_ContinueReq] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_ContinueReq(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_ContinueReq] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.continuereq;
}
void GH_SDIO_set_Control00Reg_IntAtBlkGap(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.intatblkgap = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_IntAtBlkGap] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_IntAtBlkGap(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_IntAtBlkGap] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.intatblkgap;
}
void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardIns(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.wakeupevetenoncardins = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardIns] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardIns(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardIns] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wakeupevetenoncardins;
}
void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardInt(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.wakeupevetenoncardint = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardInt] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardInt(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardInt] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wakeupevetenoncardint;
}
void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardRem(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.wakeupevetenoncardrem = data;
    gk_sd_writel((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardRem] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardRem(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardRem] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wakeupevetenoncardrem;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_PresentStateReg (read)                                       */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
U32  GH_SDIO_get_PresentStateReg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
U8   GH_SDIO_get_PresentStateReg_CmdInhibitCmd(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CmdInhibitCmd] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdinhibitcmd;
}
U8   GH_SDIO_get_PresentStateReg_DataLineActive(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_DataLineActive] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datalineactive;
}
U8   GH_SDIO_get_PresentStateReg_CmdInhibitData(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CmdInhibitData] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdinhibitdata;
}
U8   GH_SDIO_get_PresentStateReg_RTraActive(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_RTraActive] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.rtraactive;
}
U8   GH_SDIO_get_PresentStateReg_BufWEn(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_BufWEn] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwen;
}
U8   GH_SDIO_get_PresentStateReg_WTraActive(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_WTraActive] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wtraactive;
}
U8   GH_SDIO_get_PresentStateReg_BufREn(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_BufREn] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufren;
}
U8   GH_SDIO_get_PresentStateReg_CardInserted(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CardInserted] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinserted;
}
U8   GH_SDIO_get_PresentStateReg_CardDetectPinLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CardDetectPinLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.carddetectpinlevel;
}
U8   GH_SDIO_get_PresentStateReg_CardStatesTable(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CardStatesTable] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardstatestable;
}
U8   GH_SDIO_get_PresentStateReg_WProSwiPinLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_WProSwiPinLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wproswipinlevel;
}
U8   GH_SDIO_get_PresentStateReg_Data03LineSigLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_Data03LineSigLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.data03linesiglevel;
}
U8   GH_SDIO_get_PresentStateReg_CmdLineSigLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CmdLineSigLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdlinesiglevel;
}
U8   GH_SDIO_get_PresentStateReg_Data47LineSigLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_Data47LineSigLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.data47linesiglevel;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_ArgReg (read/write)                                          */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_ArgReg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ArgReg] <-- 0x%08x\n",
                        (REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_ArgReg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ArgReg] --> 0x%08x\n",
                        (REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_CapReg (read)                                                */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
U32  GH_SDIO_get_CapReg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
U8   GH_SDIO_get_CapReg_TimeoutClkUnit(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_TimeoutClkUnit] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.timeoutclkunit;
}
U8   GH_SDIO_get_CapReg_BaseClkFreForSdClk(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_BaseClkFreForSdClk] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.baseclkfreforsdclk;
}
U8   GH_SDIO_get_CapReg_ExtendedMediaBusSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_ExtendedMediaBusSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.extendedmediabussup;
}
U8   GH_SDIO_get_CapReg_HighSpeedSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_HighSpeedSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.highspeedsup;
}
U8   GH_SDIO_get_CapReg_SusResSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_SusResSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.susressup;
}
U8   GH_SDIO_get_CapReg_SdmaSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_SdmaSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdmasup;
}
U8   GH_SDIO_get_CapReg_VoltageSup33v(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_VoltageSup33v] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.voltagesup33v;
}
U8   GH_SDIO_get_CapReg_VoltageSup30v(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_VoltageSup30v] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.voltagesup30v;
}
U8   GH_SDIO_get_CapReg_VoltageSup18v(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_VoltageSup18v] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.voltagesup18v;
}
U8   GH_SDIO_get_CapReg_IntMode(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_IntMode] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.intmode;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_AutoCmd12ErrStatusReg (read/write)                           */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_AutoCmd12ErrStatusReg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_AutoCmd12ErrStatusReg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = gk_sd_readl(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12timeouterr = data;
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12timeouterr;
}
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12CrcErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = gk_sd_readl(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12crcerr = data;
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12CrcErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12CrcErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12CrcErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12crcerr;
}
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = gk_sd_readl(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12endbiterr = data;
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12endbiterr;
}
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12NotExe(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = gk_sd_readl(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12notexe = data;
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12NotExe] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12NotExe(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12NotExe] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12notexe;
}
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12IndexErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = gk_sd_readl(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12indexerr = data;
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12IndexErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12IndexErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12IndexErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12indexerr;
}
void GH_SDIO_set_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = gk_sd_readl(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdnotissuedbyautocmd12err = data;
    gk_sd_writel((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = gk_sd_readl((REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdnotissuedbyautocmd12err;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* register SDIO_BufferDataPortReg (read/write)                               */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
void GH_SDIO_set_BufferDataPortReg(U8 index, U32 data)
{
    gk_sd_writel((REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BufferDataPortReg] <-- 0x%08x\n",
                        (REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)),data);
    #endif
}
U32  GH_SDIO_get_BufferDataPortReg(U8 index)
{
    U32 value = gk_sd_readl((REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BufferDataPortReg] --> 0x%08x\n",
                        (REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
#endif /* GH_INLINE_LEVEL == 0 */

/*----------------------------------------------------------------------------*/
/* init function                                                              */
/*----------------------------------------------------------------------------*/
void GH_SDIO_init(void)
{
    int i;

    for (i=0; i<3; i++)
    {
        GH_SDIO_set_SysAddrReg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_MOD(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_NOR_INT_SIG_EN(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_ERR_INT_SIG_EN(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_BLK_COU(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_BLK_SIZ(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_NOR_INT_STA_EN(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_ERR_INT_STA_EN(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_NOR_INT_STA(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_ERR_INT_STA(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_COMM(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_SF_RST_CTRL(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_CLK_CTRL(i, (U16)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_Resp0Reg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_Resp1Reg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_Resp2Reg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_Resp3Reg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_Control00Reg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_ArgReg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_AutoCmd12ErrStatusReg(i, (U32)0x00000000);
    }
    for (i=0; i<3; i++)
    {
        GH_SDIO_set_BufferDataPortReg(i, (U32)0x00000000);
    }
    /* read read-clear registers in order to set mirror variables */
}

/*----------------------------------------------------------------------------*/
/* end of file                                                                */
/*----------------------------------------------------------------------------*/

