/*!
*******************************************************************************
**
** \file      gh_sdio.h
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
#ifndef _GH_SDIO_H
#define _GH_SDIO_H
#include <asm/arch/gk7101_reg.h>


#ifdef __LINUX__
#include "reg4linux.h"
#else
#define FIO_ADDRESS(block,address) (address)
#define FIO_MOFFSET(block,moffset) (moffset)
#endif

#ifndef __LINUX__
#include "gtypes.h" /* global type definitions */
#include "gh_lib_cfg.h" /* configuration */
#endif

#define GH_SDIO_ENABLE_DEBUG_PRINT   0
#ifdef __LINUX__
#define GH_SDIO_DEBUG_PRINT_FUNCTION printk
#else
#define GH_SDIO_DEBUG_PRINT_FUNCTION printf
#endif
#ifndef __LINUX__
#if GH_SDIO_ENABLE_DEBUG_PRINT
#include <common.h>
#endif
#endif

/* check configuration */
#ifndef GH_INLINE_LEVEL
  #error "GH_INLINE_LEVEL is not defined!"
#endif
#if GH_INLINE_LEVEL > 2
  #error "GH_INLINE_LEVEL must be set 0, 1 or 2!"
#endif
#ifndef GH_INLINE
  #error "GH_INLINE is not defined!"
#endif

/* disable inlining for debugging */
#ifdef DEBUG
  #undef GH_INLINE_LEVEL
  #define GH_INLINE_LEVEL 0
#endif
#if 0
/*----------------------------------------------------------------------------*/
/* registers                                                                  */
/*----------------------------------------------------------------------------*/
#define REG_SDIO_SYSADDRREG                                 FIO_ADDRESS(SDIO,0x70000000) /* read/write */
#define REG_SDIO_MOD                                        FIO_ADDRESS(SDIO,0x70000004) /* read/write */
#define REG_SDIO_NOR_INT_SIG_EN                             FIO_ADDRESS(SDIO,0x70000006) /* read/write */
#define REG_SDIO_ERR_INT_SIG_EN                             FIO_ADDRESS(SDIO,0x70000008) /* read/write */
#define REG_SDIO_BLK_COU                                    FIO_ADDRESS(SDIO,0x7000000A) /* read/write */
#define REG_SDIO_BLK_SIZ                                    FIO_ADDRESS(SDIO,0x7000000C) /* read/write */
#define REG_SDIO_NOR_INT_STA_EN                             FIO_ADDRESS(SDIO,0x7000000E) /* read/write */
#define REG_SDIO_ERR_INT_STA_EN                             FIO_ADDRESS(SDIO,0x70000010) /* read/write */
#define REG_SDIO_NOR_INT_STA                                FIO_ADDRESS(SDIO,0x70000012) /* read/write */
#define REG_SDIO_ERR_INT_STA                                FIO_ADDRESS(SDIO,0x70000014) /* read/write */
#define REG_SDIO_COMM                                       FIO_ADDRESS(SDIO,0x70000016) /* read/write */
#define REG_SDIO_SF_RST_CTRL                                FIO_ADDRESS(SDIO,0x70000018) /* read/write */
#define REG_SDIO_CLK_CTRL                                   FIO_ADDRESS(SDIO,0x7000001A) /* read/write */
#define REG_SDIO_RESP0REG                                   FIO_ADDRESS(SDIO,0x7000001C) /* read/write */
#define REG_SDIO_RESP1REG                                   FIO_ADDRESS(SDIO,0x70000020) /* read/write */
#define REG_SDIO_RESP2REG                                   FIO_ADDRESS(SDIO,0x70000024) /* read/write */
#define REG_SDIO_RESP3REG                                   FIO_ADDRESS(SDIO,0x70000028) /* read/write */
#define REG_SDIO_CONTROL00REG                               FIO_ADDRESS(SDIO,0x7000002C) /* read/write */
#define REG_SDIO_PRESENTSTATEREG                            FIO_ADDRESS(SDIO,0x70000030) /* read */
#define REG_SDIO_ARGREG                                     FIO_ADDRESS(SDIO,0x70000034) /* read/write */
#define REG_SDIO_CAPREG                                     FIO_ADDRESS(SDIO,0x70000038) /* read */
#define REG_SDIO_AUTOCMD12ERRSTATUSREG                      FIO_ADDRESS(SDIO,0x7000003C) /* read/write */
#define REG_SDIO_BUFFERDATAPORTREG                          FIO_ADDRESS(SDIO,0x70000040) /* read/write */
#endif
/*----------------------------------------------------------------------------*/
/* bit group structures                                                       */
/*----------------------------------------------------------------------------*/
typedef union { /* SDIO_MOD */
    U16 all;
    struct {
        U16 blkcounten                  : 1;
        U16 autocmd12en                 : 1;
        U16 dmaen                       : 1;
        U16                             : 1;
        U16 msblkselect                 : 1;
        U16 datatradirselect            : 1;
        U16                             : 10;
    } bitc;
} GH_SDIO_MOD_S;

typedef union { /* SDIO_NOR_INT_SIG_EN */
    U16 all;
    struct {
        U16 cmdcompletesigen            : 1;
        U16 tracompletesigen            : 1;
        U16 blkgapevesigen              : 1;
        U16 dmaintsigen                 : 1;
        U16 bufwreadysigen              : 1;
        U16 bufrreadysigen              : 1;
        U16 cardinsertionsigen          : 1;
        U16 cardremsigen                : 1;
        U16 cardintsigen                : 1;
        U16                             : 7;
    } bitc;
} GH_SDIO_NOR_INT_SIG_EN_S;

typedef union { /* SDIO_ERR_INT_SIG_EN */
    U16 all;
    struct {
        U16 cmdtimeouterrsigen          : 1;
        U16 cmdendbiterrsigen           : 1;
        U16 cmdindexerrsigen            : 1;
        U16 datatimeouterrsigen         : 1;
        U16 cmdcrcerrsigen              : 1;
        U16 datacrcerrsigen             : 1;
        U16 dataendbiterrsigen          : 1;
        U16                             : 1;
        U16 autocmd12errsigen           : 1;
        U16                             : 7;
    } bitc;
} GH_SDIO_ERR_INT_SIG_EN_S;

typedef union { /* SDIO_BLK_SIZ */
    U16 all;
    struct {
        U16 trablksize                  : 12;
        U16 hostsdmabufsize             : 3;
        U16                             : 1;
    } bitc;
} GH_SDIO_BLK_SIZ_S;

typedef union { /* SDIO_NOR_INT_STA_EN */
    U16 all;
    struct {
        U16 cmdcompletestatusen         : 1;
        U16 tracompletestatusen         : 1;
        U16 blkgapevestatusen           : 1;
        U16 dmaintstatusen              : 1;
        U16 bufwreadystatusen           : 1;
        U16 bufrreadystatusen           : 1;
        U16 cardinsertionstatusen       : 1;
        U16 cardremstatusen             : 1;
        U16 cardintstatusen             : 1;
        U16                             : 7;
    } bitc;
} GH_SDIO_NOR_INT_STA_EN_S;

typedef union { /* SDIO_ERR_INT_STA_EN */
    U16 all;
    struct {
        U16 cmdtimeouterrstatusen       : 1;
        U16 cmdendbiterrstatusen        : 1;
        U16 cmdcrcerrstatusen           : 1;
        U16 cmdindexerrstatusen         : 1;
        U16 datacrcerrstatusen          : 1;
        U16 datatimeouterrstatusen      : 1;
        U16 dataendbiterrstatusen       : 1;
        U16                             : 1;
        U16 autocmd12errstatusen        : 1;
        U16                             : 7;
    } bitc;
} GH_SDIO_ERR_INT_STA_EN_S;

typedef union { /* SDIO_NOR_INT_STA */
    U16 all;
    struct {
        U16 cmdcomplete                 : 1;
        U16 blkgapevent                 : 1;
        U16 dmaint                      : 1;
        U16 tracomplete                 : 1;
        U16 bufwready                   : 1;
        U16 cardinsertion               : 1;
        U16 bufrready                   : 1;
        U16 cardremoval                 : 1;
        U16 cardint                     : 1;
        U16                             : 6;
        U16 errint                      : 1;
    } bitc;
} GH_SDIO_NOR_INT_STA_S;

typedef union { /* SDIO_ERR_INT_STA */
    U16 all;
    struct {
        U16 cmdtimeouterr               : 1;
        U16 cmdcrcerr                   : 1;
        U16 cmdendbiterr                : 1;
        U16 cmdindexerr                 : 1;
        U16 datatimeouterr              : 1;
        U16 datacrcerr                  : 1;
        U16 dataendbiterr               : 1;
        U16                             : 1;
        U16 autocmd12err                : 1;
        U16                             : 7;
    } bitc;
} GH_SDIO_ERR_INT_STA_S;

typedef union { /* SDIO_COMM */
    U16 all;
    struct {
        U16 reptypeselect               : 2;
        U16                             : 1;
        U16 cmdcrcchecken               : 1;
        U16 datapreselect               : 1;
        U16 cmdindexchecken             : 1;
        U16 cmdtype                     : 2;
        U16 cmdindex                    : 6;
        U16                             : 2;
    } bitc;
} GH_SDIO_COMM_S;

typedef union { /* SDIO_SF_RST_CTRL */
    U16 all;
    struct {
        U16 datatimeoutcountervalue     : 4;
        U16                             : 4;
        U16 softwareresetcmdline        : 1;
        U16 softwareresetall            : 1;
        U16 softwareresetdatline        : 1;
        U16                             : 5;
    } bitc;
} GH_SDIO_SF_RST_CTRL_S;

typedef union { /* SDIO_CLK_CTRL */
    U16 all;
    struct {
        U16 internalclken               : 1;
        U16 internalclkstable           : 1;
        U16 sdclken                     : 1;
        U16                             : 5;
        U16 sdclkfreselect              : 8;
    } bitc;
} GH_SDIO_CLK_CTRL_S;

typedef union { /* SDIO_Control00Reg */
    U32 all;
    struct {
        U32                             : 1;
        U32 datatrawidth                : 1;
        U32 sd8bitmode                  : 1;
        U32 hostspeeden                 : 1;
        U32                             : 4;
        U32 sdbuspower                  : 1;
        U32 driveccsd                   : 7;
        U32 stopatblkgapreq             : 1;
        U32 rwaitcontrol                : 1;
        U32 continuereq                 : 1;
        U32 intatblkgap                 : 1;
        U32                             : 4;
        U32 wakeupevetenoncardins       : 1;
        U32 wakeupevetenoncardint       : 1;
        U32 wakeupevetenoncardrem       : 1;
        U32                             : 5;
    } bitc;
} GH_SDIO_CONTROL00REG_S;

typedef union { /* SDIO_PresentStateReg */
    U32 all;
    struct {
        U32 cmdinhibitcmd               : 1;
        U32 datalineactive              : 1;
        U32 cmdinhibitdata              : 1;
        U32                             : 5;
        U32 rtraactive                  : 1;
        U32 bufwen                      : 1;
        U32 wtraactive                  : 1;
        U32 bufren                      : 1;
        U32                             : 4;
        U32 cardinserted                : 1;
        U32 carddetectpinlevel          : 1;
        U32 cardstatestable             : 1;
        U32 wproswipinlevel             : 1;
        U32 data03linesiglevel          : 4;
        U32 cmdlinesiglevel             : 1;
        U32 data47linesiglevel          : 4;
        U32                             : 3;
    } bitc;
} GH_SDIO_PRESENTSTATEREG_S;

typedef union { /* SDIO_CapReg */
    U32 all;
    struct {
        U32                             : 7;
        U32 timeoutclkunit              : 1;
        U32 baseclkfreforsdclk          : 6;
        U32                             : 2;
        U32 extendedmediabussup         : 2;
        U32                             : 3;
        U32 highspeedsup                : 1;
        U32 susressup                   : 1;
        U32 sdmasup                     : 1;
        U32 voltagesup33v               : 1;
        U32 voltagesup30v               : 1;
        U32 voltagesup18v               : 1;
        U32 intmode                     : 1;
        U32                             : 4;
    } bitc;
} GH_SDIO_CAPREG_S;

typedef union { /* SDIO_AutoCmd12ErrStatusReg */
    U32 all;
    struct {
        U32 autocmd12timeouterr         : 1;
        U32 autocmd12crcerr             : 1;
        U32 autocmd12endbiterr          : 1;
        U32 autocmd12notexe             : 1;
        U32 autocmd12indexerr           : 1;
        U32                             : 2;
        U32 cmdnotissuedbyautocmd12err  : 1;
        U32                             : 24;
    } bitc;
} GH_SDIO_AUTOCMD12ERRSTATUSREG_S;


/*----------------------------------------------------------------------------*/
/* mirror variables                                                           */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* register SDIO_SysAddrReg (read/write)                                      */
/*----------------------------------------------------------------------------*/
#if GH_INLINE_LEVEL == 0
/*! \brief Writes the register 'SDIO_SysAddrReg'. */
void GH_SDIO_set_SysAddrReg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_SysAddrReg'. */
U32  GH_SDIO_get_SysAddrReg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_SysAddrReg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SysAddrReg] <-- 0x%08x\n",
                        (REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_SysAddrReg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_SYSADDRREG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_MOD'. */
void GH_SDIO_set_MOD(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_MOD'. */
U16  GH_SDIO_get_MOD(U8 index);
/*! \brief Writes the bit group 'BlkCountEn' of register 'SDIO_MOD'. */
void GH_SDIO_set_MOD_BlkCountEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BlkCountEn' of register 'SDIO_MOD'. */
U8   GH_SDIO_get_MOD_BlkCountEn(U8 index);
/*! \brief Writes the bit group 'AutoCmd12En' of register 'SDIO_MOD'. */
void GH_SDIO_set_MOD_AutoCmd12En(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12En' of register 'SDIO_MOD'. */
U8   GH_SDIO_get_MOD_AutoCmd12En(U8 index);
/*! \brief Writes the bit group 'DmaEn' of register 'SDIO_MOD'. */
void GH_SDIO_set_MOD_DmaEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DmaEn' of register 'SDIO_MOD'. */
U8   GH_SDIO_get_MOD_DmaEn(U8 index);
/*! \brief Writes the bit group 'MSBlkSelect' of register 'SDIO_MOD'. */
void GH_SDIO_set_MOD_MSBlkSelect(U8 index, U8 data);
/*! \brief Reads the bit group 'MSBlkSelect' of register 'SDIO_MOD'. */
U8   GH_SDIO_get_MOD_MSBlkSelect(U8 index);
/*! \brief Writes the bit group 'DataTraDirSelect' of register 'SDIO_MOD'. */
void GH_SDIO_set_MOD_DataTraDirSelect(U8 index, U8 data);
/*! \brief Reads the bit group 'DataTraDirSelect' of register 'SDIO_MOD'. */
U8   GH_SDIO_get_MOD_DataTraDirSelect(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_MOD(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_MOD(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_MOD_BlkCountEn(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkcounten = data;
    *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_BlkCountEn] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_MOD_BlkCountEn(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_BlkCountEn] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkcounten;
}
GH_INLINE void GH_SDIO_set_MOD_AutoCmd12En(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12en = data;
    *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_AutoCmd12En] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_MOD_AutoCmd12En(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_AutoCmd12En] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12en;
}
GH_INLINE void GH_SDIO_set_MOD_DmaEn(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaen = data;
    *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_DmaEn] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_MOD_DmaEn(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_DmaEn] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaen;
}
GH_INLINE void GH_SDIO_set_MOD_MSBlkSelect(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.msblkselect = data;
    *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_MSBlkSelect] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_MOD_MSBlkSelect(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_MOD_MSBlkSelect] --> 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.msblkselect;
}
GH_INLINE void GH_SDIO_set_MOD_DataTraDirSelect(U8 index, U8 data)
{
    GH_SDIO_MOD_S d;
    d.all = *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatradirselect = data;
    *(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_MOD_DataTraDirSelect] <-- 0x%08x\n",
                        (REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_MOD_DataTraDirSelect(U8 index)
{
    GH_SDIO_MOD_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_MOD + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_NOR_INT_SIG_EN'. */
U16  GH_SDIO_get_NOR_INT_SIG_EN(U8 index);
/*! \brief Writes the bit group 'CmdCompleteSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_CmdCompleteSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdCompleteSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_CmdCompleteSigEn(U8 index);
/*! \brief Writes the bit group 'TraCompleteSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_TraCompleteSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'TraCompleteSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_TraCompleteSigEn(U8 index);
/*! \brief Writes the bit group 'BlkGapEveSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_BlkGapEveSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BlkGapEveSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_BlkGapEveSigEn(U8 index);
/*! \brief Writes the bit group 'DmaIntSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_DmaIntSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DmaIntSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_DmaIntSigEn(U8 index);
/*! \brief Writes the bit group 'BufWReadySigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_BufWReadySigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BufWReadySigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_BufWReadySigEn(U8 index);
/*! \brief Writes the bit group 'BufRReadySigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_BufRReadySigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BufRReadySigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_BufRReadySigEn(U8 index);
/*! \brief Writes the bit group 'CardInsertionSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_CardInsertionSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CardInsertionSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_CardInsertionSigEn(U8 index);
/*! \brief Writes the bit group 'CardRemSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_CardRemSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CardRemSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_CardRemSigEn(U8 index);
/*! \brief Writes the bit group 'CardIntSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
void GH_SDIO_set_NOR_INT_SIG_EN_CardIntSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CardIntSigEn' of register 'SDIO_NOR_INT_SIG_EN'. */
U8   GH_SDIO_get_NOR_INT_SIG_EN_CardIntSigEn(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_NOR_INT_SIG_EN(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_CmdCompleteSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcompletesigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CmdCompleteSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_CmdCompleteSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CmdCompleteSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcompletesigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_TraCompleteSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.tracompletesigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_TraCompleteSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_TraCompleteSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_TraCompleteSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.tracompletesigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_BlkGapEveSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkgapevesigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_BlkGapEveSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_BlkGapEveSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_BlkGapEveSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkgapevesigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_DmaIntSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaintsigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_DmaIntSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_DmaIntSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_DmaIntSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaintsigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_BufWReadySigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufwreadysigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_BufWReadySigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_BufWReadySigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_BufWReadySigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwreadysigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_BufRReadySigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufrreadysigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_BufRReadySigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_BufRReadySigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_BufRReadySigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufrreadysigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_CardInsertionSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardinsertionsigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CardInsertionSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_CardInsertionSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CardInsertionSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinsertionsigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_CardRemSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardremsigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CardRemSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_CardRemSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_SIG_EN_CardRemSigEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardremsigen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_SIG_EN_CardIntSigEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardintsigen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_SIG_EN_CardIntSigEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_SIG_EN_CardIntSigEn(U8 index)
{
    GH_SDIO_NOR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_ERR_INT_SIG_EN'. */
U16  GH_SDIO_get_ERR_INT_SIG_EN(U8 index);
/*! \brief Writes the bit group 'CmdTimeoutErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_CmdTimeoutErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdTimeoutErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdTimeoutErrSigEn(U8 index);
/*! \brief Writes the bit group 'CmdEndBitErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_CmdEndBitErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdEndBitErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdEndBitErrSigEn(U8 index);
/*! \brief Writes the bit group 'CmdIndexErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_CmdIndexErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdIndexErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdIndexErrSigEn(U8 index);
/*! \brief Writes the bit group 'DataTimeoutErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_DataTimeoutErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DataTimeoutErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_DataTimeoutErrSigEn(U8 index);
/*! \brief Writes the bit group 'CmdCrcErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_CmdCrcErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdCrcErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdCrcErrSigEn(U8 index);
/*! \brief Writes the bit group 'DataCrcErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_DataCrcErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DataCrcErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_DataCrcErrSigEn(U8 index);
/*! \brief Writes the bit group 'DataEndBitErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_DataEndBitErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DataEndBitErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_DataEndBitErrSigEn(U8 index);
/*! \brief Writes the bit group 'AutoCmd12ErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
void GH_SDIO_set_ERR_INT_SIG_EN_AutoCmd12ErrSigEn(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12ErrSigEn' of register 'SDIO_ERR_INT_SIG_EN'. */
U8   GH_SDIO_get_ERR_INT_SIG_EN_AutoCmd12ErrSigEn(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_ERR_INT_SIG_EN(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_CmdTimeoutErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtimeouterrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdTimeoutErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdTimeoutErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdTimeoutErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtimeouterrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_CmdEndBitErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdendbiterrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdEndBitErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdEndBitErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdEndBitErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdendbiterrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_CmdIndexErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexerrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdIndexErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdIndexErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdIndexErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexerrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_DataTimeoutErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeouterrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_DataTimeoutErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_DataTimeoutErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_DataTimeoutErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeouterrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_CmdCrcErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcerrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_CmdCrcErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_CmdCrcErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_CmdCrcErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcerrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_DataCrcErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datacrcerrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_DataCrcErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_DataCrcErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_DataCrcErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datacrcerrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_DataEndBitErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dataendbiterrsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_DataEndBitErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_DataEndBitErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_SIG_EN_DataEndBitErrSigEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dataendbiterrsigen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_SIG_EN_AutoCmd12ErrSigEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_SIG_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12errsigen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_SIG_EN_AutoCmd12ErrSigEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_SIG_EN_AutoCmd12ErrSigEn(U8 index)
{
    GH_SDIO_ERR_INT_SIG_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_SIG_EN + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_BLK_COU'. */
void GH_SDIO_set_BLK_COU(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_BLK_COU'. */
U16  GH_SDIO_get_BLK_COU(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_BLK_COU(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_COU] <-- 0x%08x\n",
                        (REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_BLK_COU(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_BLK_COU + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_BLK_SIZ'. */
void GH_SDIO_set_BLK_SIZ(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_BLK_SIZ'. */
U16  GH_SDIO_get_BLK_SIZ(U8 index);
/*! \brief Writes the bit group 'TraBlkSize' of register 'SDIO_BLK_SIZ'. */
void GH_SDIO_set_BLK_SIZ_TraBlkSize(U8 index, U16 data);
/*! \brief Reads the bit group 'TraBlkSize' of register 'SDIO_BLK_SIZ'. */
U16  GH_SDIO_get_BLK_SIZ_TraBlkSize(U8 index);
/*! \brief Writes the bit group 'HostSdmaBufSize' of register 'SDIO_BLK_SIZ'. */
void GH_SDIO_set_BLK_SIZ_HostSdmaBufSize(U8 index, U8 data);
/*! \brief Reads the bit group 'HostSdmaBufSize' of register 'SDIO_BLK_SIZ'. */
U8   GH_SDIO_get_BLK_SIZ_HostSdmaBufSize(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_BLK_SIZ(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_SIZ] <-- 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_BLK_SIZ(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BLK_SIZ] --> 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_BLK_SIZ_TraBlkSize(U8 index, U16 data)
{
    GH_SDIO_BLK_SIZ_S d;
    d.all = *(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.trablksize = data;
    *(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_SIZ_TraBlkSize] <-- 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U16  GH_SDIO_get_BLK_SIZ_TraBlkSize(U8 index)
{
    GH_SDIO_BLK_SIZ_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_BLK_SIZ_TraBlkSize] --> 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.trablksize;
}
GH_INLINE void GH_SDIO_set_BLK_SIZ_HostSdmaBufSize(U8 index, U8 data)
{
    GH_SDIO_BLK_SIZ_S d;
    d.all = *(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.hostsdmabufsize = data;
    *(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BLK_SIZ_HostSdmaBufSize] <-- 0x%08x\n",
                        (REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_BLK_SIZ_HostSdmaBufSize(U8 index)
{
    GH_SDIO_BLK_SIZ_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_BLK_SIZ + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_NOR_INT_STA_EN'. */
U16  GH_SDIO_get_NOR_INT_STA_EN(U8 index);
/*! \brief Writes the bit group 'CmdCompleteStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_CmdCompleteStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdCompleteStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_CmdCompleteStatusEn(U8 index);
/*! \brief Writes the bit group 'TraCompleteStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_TraCompleteStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'TraCompleteStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_TraCompleteStatusEn(U8 index);
/*! \brief Writes the bit group 'BlkGapEveStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_BlkGapEveStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BlkGapEveStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_BlkGapEveStatusEn(U8 index);
/*! \brief Writes the bit group 'dmaIntStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_dmaIntStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'dmaIntStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_dmaIntStatusEn(U8 index);
/*! \brief Writes the bit group 'BufWReadyStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_BufWReadyStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BufWReadyStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_BufWReadyStatusEn(U8 index);
/*! \brief Writes the bit group 'BufRReadyStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_BufRReadyStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'BufRReadyStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_BufRReadyStatusEn(U8 index);
/*! \brief Writes the bit group 'CardInsertionStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_CardInsertionStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CardInsertionStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_CardInsertionStatusEn(U8 index);
/*! \brief Writes the bit group 'CardRemStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_CardRemStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CardRemStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_CardRemStatusEn(U8 index);
/*! \brief Writes the bit group 'CardIntStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
void GH_SDIO_set_NOR_INT_STA_EN_CardIntStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CardIntStatusEn' of register 'SDIO_NOR_INT_STA_EN'. */
U8   GH_SDIO_get_NOR_INT_STA_EN_CardIntStatusEn(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_NOR_INT_STA_EN(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_CmdCompleteStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcompletestatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CmdCompleteStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_CmdCompleteStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CmdCompleteStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcompletestatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_TraCompleteStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.tracompletestatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_TraCompleteStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_TraCompleteStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_TraCompleteStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.tracompletestatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_BlkGapEveStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkgapevestatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_BlkGapEveStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_BlkGapEveStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_BlkGapEveStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkgapevestatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_dmaIntStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaintstatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_dmaIntStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_dmaIntStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_dmaIntStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaintstatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_BufWReadyStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufwreadystatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_BufWReadyStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_BufWReadyStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_BufWReadyStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwreadystatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_BufRReadyStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufrreadystatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_BufRReadyStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_BufRReadyStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_BufRReadyStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufrreadystatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_CardInsertionStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardinsertionstatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CardInsertionStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_CardInsertionStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CardInsertionStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinsertionstatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_CardRemStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardremstatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CardRemStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_CardRemStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_EN_CardRemStatusEn] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardremstatusen;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_EN_CardIntStatusEn(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardintstatusen = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_EN_CardIntStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_EN_CardIntStatusEn(U8 index)
{
    GH_SDIO_NOR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_ERR_INT_STA_EN'. */
U16  GH_SDIO_get_ERR_INT_STA_EN(U8 index);
/*! \brief Writes the bit group 'CmdTimeoutErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_CmdTimeoutErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdTimeoutErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdTimeoutErrStatusEn(U8 index);
/*! \brief Writes the bit group 'CmdEndBitErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_CmdEndBitErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdEndBitErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdEndBitErrStatusEn(U8 index);
/*! \brief Writes the bit group 'CmdCrcErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_CmdCrcErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdCrcErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdCrcErrStatusEn(U8 index);
/*! \brief Writes the bit group 'CmdIndexErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_CmdIndexErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdIndexErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_CmdIndexErrStatusEn(U8 index);
/*! \brief Writes the bit group 'DataCrcErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_DataCrcErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DataCrcErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_DataCrcErrStatusEn(U8 index);
/*! \brief Writes the bit group 'DataTimeoutErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_DataTimeoutErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DataTimeoutErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_DataTimeoutErrStatusEn(U8 index);
/*! \brief Writes the bit group 'DataEndBitErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_DataEndBitErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'DataEndBitErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_DataEndBitErrStatusEn(U8 index);
/*! \brief Writes the bit group 'AutoCmd12ErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
void GH_SDIO_set_ERR_INT_STA_EN_AutoCmd12ErrStatusEn(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12ErrStatusEn' of register 'SDIO_ERR_INT_STA_EN'. */
U8   GH_SDIO_get_ERR_INT_STA_EN_AutoCmd12ErrStatusEn(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_ERR_INT_STA_EN(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_CmdTimeoutErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtimeouterrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdTimeoutErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_CmdTimeoutErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdTimeoutErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtimeouterrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_CmdEndBitErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdendbiterrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdEndBitErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_CmdEndBitErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdEndBitErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdendbiterrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_CmdCrcErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcerrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdCrcErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_CmdCrcErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdCrcErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcerrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_CmdIndexErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexerrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_CmdIndexErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_CmdIndexErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_CmdIndexErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexerrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_DataCrcErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datacrcerrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_DataCrcErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_DataCrcErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_DataCrcErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datacrcerrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_DataTimeoutErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeouterrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_DataTimeoutErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_DataTimeoutErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_DataTimeoutErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeouterrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_DataEndBitErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dataendbiterrstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_DataEndBitErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_DataEndBitErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_EN_DataEndBitErrStatusEn] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dataendbiterrstatusen;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_EN_AutoCmd12ErrStatusEn(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_EN_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12errstatusen = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_EN_AutoCmd12ErrStatusEn] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_EN_AutoCmd12ErrStatusEn(U8 index)
{
    GH_SDIO_ERR_INT_STA_EN_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA_EN + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_NOR_INT_STA'. */
U16  GH_SDIO_get_NOR_INT_STA(U8 index);
/*! \brief Writes the bit group 'CmdComplete' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_CmdComplete(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdComplete' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_CmdComplete(U8 index);
/*! \brief Writes the bit group 'BlkGapEvent' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_BlkGapEvent(U8 index, U8 data);
/*! \brief Reads the bit group 'BlkGapEvent' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_BlkGapEvent(U8 index);
/*! \brief Writes the bit group 'DmaInt' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_DmaInt(U8 index, U8 data);
/*! \brief Reads the bit group 'DmaInt' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_DmaInt(U8 index);
/*! \brief Writes the bit group 'TraComplete' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_TraComplete(U8 index, U8 data);
/*! \brief Reads the bit group 'TraComplete' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_TraComplete(U8 index);
/*! \brief Writes the bit group 'BufWReady' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_BufWReady(U8 index, U8 data);
/*! \brief Reads the bit group 'BufWReady' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_BufWReady(U8 index);
/*! \brief Writes the bit group 'CardInsertion' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_CardInsertion(U8 index, U8 data);
/*! \brief Reads the bit group 'CardInsertion' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_CardInsertion(U8 index);
/*! \brief Writes the bit group 'BufRReady' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_BufRReady(U8 index, U8 data);
/*! \brief Reads the bit group 'BufRReady' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_BufRReady(U8 index);
/*! \brief Writes the bit group 'CardRemoval' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_CardRemoval(U8 index, U8 data);
/*! \brief Reads the bit group 'CardRemoval' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_CardRemoval(U8 index);
/*! \brief Writes the bit group 'CardInt' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_CardInt(U8 index, U8 data);
/*! \brief Reads the bit group 'CardInt' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_CardInt(U8 index);
/*! \brief Writes the bit group 'ErrInt' of register 'SDIO_NOR_INT_STA'. */
void GH_SDIO_set_NOR_INT_STA_ErrInt(U8 index, U8 data);
/*! \brief Reads the bit group 'ErrInt' of register 'SDIO_NOR_INT_STA'. */
U8   GH_SDIO_get_NOR_INT_STA_ErrInt(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_NOR_INT_STA(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_NOR_INT_STA(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_CmdComplete(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcomplete = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CmdComplete] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_CmdComplete(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CmdComplete] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcomplete;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_BlkGapEvent(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.blkgapevent = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_BlkGapEvent] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_BlkGapEvent(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_BlkGapEvent] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.blkgapevent;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_DmaInt(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dmaint = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_DmaInt] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_DmaInt(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_DmaInt] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dmaint;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_TraComplete(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.tracomplete = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_TraComplete] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_TraComplete(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_TraComplete] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.tracomplete;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_BufWReady(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufwready = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_BufWReady] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_BufWReady(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_BufWReady] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwready;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_CardInsertion(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardinsertion = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CardInsertion] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_CardInsertion(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CardInsertion] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinsertion;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_BufRReady(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.bufrready = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_BufRReady] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_BufRReady(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_BufRReady] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufrready;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_CardRemoval(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardremoval = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CardRemoval] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_CardRemoval(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CardRemoval] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardremoval;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_CardInt(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cardint = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_CardInt] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_CardInt(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_NOR_INT_STA_CardInt] --> 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardint;
}
GH_INLINE void GH_SDIO_set_NOR_INT_STA_ErrInt(U8 index, U8 data)
{
    GH_SDIO_NOR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.errint = data;
    *(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_NOR_INT_STA_ErrInt] <-- 0x%08x\n",
                        (REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_NOR_INT_STA_ErrInt(U8 index)
{
    GH_SDIO_NOR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_NOR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_ERR_INT_STA'. */
U16  GH_SDIO_get_ERR_INT_STA(U8 index);
/*! \brief Writes the bit group 'CmdTimeoutErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_CmdTimeoutErr(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdTimeoutErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_CmdTimeoutErr(U8 index);
/*! \brief Writes the bit group 'CmdCrcErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_CmdCrcErr(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdCrcErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_CmdCrcErr(U8 index);
/*! \brief Writes the bit group 'CmdEndBitErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_CmdEndBitErr(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdEndBitErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_CmdEndBitErr(U8 index);
/*! \brief Writes the bit group 'CmdIndexErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_CmdIndexErr(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdIndexErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_CmdIndexErr(U8 index);
/*! \brief Writes the bit group 'DataTimeoutErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_DataTimeoutErr(U8 index, U8 data);
/*! \brief Reads the bit group 'DataTimeoutErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_DataTimeoutErr(U8 index);
/*! \brief Writes the bit group 'DataCrcErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_DataCrcErr(U8 index, U8 data);
/*! \brief Reads the bit group 'DataCrcErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_DataCrcErr(U8 index);
/*! \brief Writes the bit group 'DataEndBitErr' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_DataEndBitErr(U8 index, U8 data);
/*! \brief Reads the bit group 'DataEndBitErr' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_DataEndBitErr(U8 index);
/*! \brief Writes the bit group 'AutoCmd12Err' of register 'SDIO_ERR_INT_STA'. */
void GH_SDIO_set_ERR_INT_STA_AutoCmd12Err(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12Err' of register 'SDIO_ERR_INT_STA'. */
U8   GH_SDIO_get_ERR_INT_STA_AutoCmd12Err(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_ERR_INT_STA(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_ERR_INT_STA(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_CmdTimeoutErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtimeouterr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdTimeoutErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_CmdTimeoutErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdTimeoutErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtimeouterr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_CmdCrcErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcerr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdCrcErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_CmdCrcErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdCrcErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcerr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_CmdEndBitErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdendbiterr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdEndBitErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_CmdEndBitErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdEndBitErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdendbiterr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_CmdIndexErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexerr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_CmdIndexErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_CmdIndexErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_CmdIndexErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexerr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_DataTimeoutErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeouterr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_DataTimeoutErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_DataTimeoutErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_DataTimeoutErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeouterr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_DataCrcErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datacrcerr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_DataCrcErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_DataCrcErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_DataCrcErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datacrcerr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_DataEndBitErr(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.dataendbiterr = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_DataEndBitErr] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_DataEndBitErr(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_ERR_INT_STA_DataEndBitErr] --> 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.dataendbiterr;
}
GH_INLINE void GH_SDIO_set_ERR_INT_STA_AutoCmd12Err(U8 index, U8 data)
{
    GH_SDIO_ERR_INT_STA_S d;
    d.all = *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12err = data;
    *(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ERR_INT_STA_AutoCmd12Err] <-- 0x%08x\n",
                        (REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_ERR_INT_STA_AutoCmd12Err(U8 index)
{
    GH_SDIO_ERR_INT_STA_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_ERR_INT_STA + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_COMM'. */
void GH_SDIO_set_COMM(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_COMM'. */
U16  GH_SDIO_get_COMM(U8 index);
/*! \brief Writes the bit group 'RepTypeSelect' of register 'SDIO_COMM'. */
void GH_SDIO_set_COMM_RepTypeSelect(U8 index, U8 data);
/*! \brief Reads the bit group 'RepTypeSelect' of register 'SDIO_COMM'. */
U8   GH_SDIO_get_COMM_RepTypeSelect(U8 index);
/*! \brief Writes the bit group 'CmdCrcCheckEn' of register 'SDIO_COMM'. */
void GH_SDIO_set_COMM_CmdCrcCheckEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdCrcCheckEn' of register 'SDIO_COMM'. */
U8   GH_SDIO_get_COMM_CmdCrcCheckEn(U8 index);
/*! \brief Writes the bit group 'DataPreSelect' of register 'SDIO_COMM'. */
void GH_SDIO_set_COMM_DataPreSelect(U8 index, U8 data);
/*! \brief Reads the bit group 'DataPreSelect' of register 'SDIO_COMM'. */
U8   GH_SDIO_get_COMM_DataPreSelect(U8 index);
/*! \brief Writes the bit group 'CmdIndexCheckEn' of register 'SDIO_COMM'. */
void GH_SDIO_set_COMM_CmdIndexCheckEn(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdIndexCheckEn' of register 'SDIO_COMM'. */
U8   GH_SDIO_get_COMM_CmdIndexCheckEn(U8 index);
/*! \brief Writes the bit group 'CmdType' of register 'SDIO_COMM'. */
void GH_SDIO_set_COMM_CmdType(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdType' of register 'SDIO_COMM'. */
U8   GH_SDIO_get_COMM_CmdType(U8 index);
/*! \brief Writes the bit group 'CmdIndex' of register 'SDIO_COMM'. */
void GH_SDIO_set_COMM_CmdIndex(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdIndex' of register 'SDIO_COMM'. */
U8   GH_SDIO_get_COMM_CmdIndex(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_COMM(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_COMM(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_COMM_RepTypeSelect(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.reptypeselect = data;
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_RepTypeSelect] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_COMM_RepTypeSelect(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_RepTypeSelect] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.reptypeselect;
}
GH_INLINE void GH_SDIO_set_COMM_CmdCrcCheckEn(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdcrcchecken = data;
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdCrcCheckEn] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_COMM_CmdCrcCheckEn(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdCrcCheckEn] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdcrcchecken;
}
GH_INLINE void GH_SDIO_set_COMM_DataPreSelect(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datapreselect = data;
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_DataPreSelect] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_COMM_DataPreSelect(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_DataPreSelect] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datapreselect;
}
GH_INLINE void GH_SDIO_set_COMM_CmdIndexCheckEn(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindexchecken = data;
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdIndexCheckEn] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_COMM_CmdIndexCheckEn(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdIndexCheckEn] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdindexchecken;
}
GH_INLINE void GH_SDIO_set_COMM_CmdType(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdtype = data;
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdType] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_COMM_CmdType(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_COMM_CmdType] --> 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdtype;
}
GH_INLINE void GH_SDIO_set_COMM_CmdIndex(U8 index, U8 data)
{
    GH_SDIO_COMM_S d;
    d.all = *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdindex = data;
    *(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_COMM_CmdIndex] <-- 0x%08x\n",
                        (REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_COMM_CmdIndex(U8 index)
{
    GH_SDIO_COMM_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_COMM + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_SF_RST_CTRL'. */
void GH_SDIO_set_SF_RST_CTRL(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_SF_RST_CTRL'. */
U16  GH_SDIO_get_SF_RST_CTRL(U8 index);
/*! \brief Writes the bit group 'DataTimeoutCounterValue' of register 'SDIO_SF_RST_CTRL'. */
void GH_SDIO_set_SF_RST_CTRL_DataTimeoutCounterValue(U8 index, U8 data);
/*! \brief Reads the bit group 'DataTimeoutCounterValue' of register 'SDIO_SF_RST_CTRL'. */
U8   GH_SDIO_get_SF_RST_CTRL_DataTimeoutCounterValue(U8 index);
/*! \brief Writes the bit group 'SoftwareResetCmdLine' of register 'SDIO_SF_RST_CTRL'. */
void GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine(U8 index, U8 data);
/*! \brief Reads the bit group 'SoftwareResetCmdLine' of register 'SDIO_SF_RST_CTRL'. */
U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetCmdLine(U8 index);
/*! \brief Writes the bit group 'SoftwareResetAll' of register 'SDIO_SF_RST_CTRL'. */
void GH_SDIO_set_SF_RST_CTRL_SoftwareResetAll(U8 index, U8 data);
/*! \brief Reads the bit group 'SoftwareResetAll' of register 'SDIO_SF_RST_CTRL'. */
U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetAll(U8 index);
/*! \brief Writes the bit group 'SoftwareResetDatLine' of register 'SDIO_SF_RST_CTRL'. */
void GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine(U8 index, U8 data);
/*! \brief Reads the bit group 'SoftwareResetDatLine' of register 'SDIO_SF_RST_CTRL'. */
U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetDatLine(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_SF_RST_CTRL(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_SF_RST_CTRL(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_SF_RST_CTRL_DataTimeoutCounterValue(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatimeoutcountervalue = data;
    *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_DataTimeoutCounterValue] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_SF_RST_CTRL_DataTimeoutCounterValue(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_DataTimeoutCounterValue] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatimeoutcountervalue;
}
GH_INLINE void GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.softwareresetcmdline = data;
    *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetCmdLine(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_SoftwareResetCmdLine] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.softwareresetcmdline;
}
GH_INLINE void GH_SDIO_set_SF_RST_CTRL_SoftwareResetAll(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.softwareresetall = data;
    *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_SoftwareResetAll] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetAll(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_SF_RST_CTRL_SoftwareResetAll] --> 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.softwareresetall;
}
GH_INLINE void GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine(U8 index, U8 data)
{
    GH_SDIO_SF_RST_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.softwareresetdatline = data;
    *(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine] <-- 0x%08x\n",
                        (REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_SF_RST_CTRL_SoftwareResetDatLine(U8 index)
{
    GH_SDIO_SF_RST_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_SF_RST_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_CLK_CTRL'. */
void GH_SDIO_set_CLK_CTRL(U8 index, U16 data);
/*! \brief Reads the register 'SDIO_CLK_CTRL'. */
U16  GH_SDIO_get_CLK_CTRL(U8 index);
/*! \brief Writes the bit group 'InternalClkEn' of register 'SDIO_CLK_CTRL'. */
void GH_SDIO_set_CLK_CTRL_InternalClkEn(U8 index, U8 data);
/*! \brief Reads the bit group 'InternalClkEn' of register 'SDIO_CLK_CTRL'. */
U8   GH_SDIO_get_CLK_CTRL_InternalClkEn(U8 index);
/*! \brief Writes the bit group 'InternalClkStable' of register 'SDIO_CLK_CTRL'. */
void GH_SDIO_set_CLK_CTRL_InternalClkStable(U8 index, U8 data);
/*! \brief Reads the bit group 'InternalClkStable' of register 'SDIO_CLK_CTRL'. */
U8   GH_SDIO_get_CLK_CTRL_InternalClkStable(U8 index);
/*! \brief Writes the bit group 'SdClkEn' of register 'SDIO_CLK_CTRL'. */
void GH_SDIO_set_CLK_CTRL_SdClkEn(U8 index, U8 data);
/*! \brief Reads the bit group 'SdClkEn' of register 'SDIO_CLK_CTRL'. */
U8   GH_SDIO_get_CLK_CTRL_SdClkEn(U8 index);
/*! \brief Writes the bit group 'SdclkFreSelect' of register 'SDIO_CLK_CTRL'. */
void GH_SDIO_set_CLK_CTRL_SdclkFreSelect(U8 index, U8 data);
/*! \brief Reads the bit group 'SdclkFreSelect' of register 'SDIO_CLK_CTRL'. */
U8   GH_SDIO_get_CLK_CTRL_SdclkFreSelect(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_CLK_CTRL(U8 index, U16 data)
{
    *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U16  GH_SDIO_get_CLK_CTRL(U8 index)
{
    U16 value = (*(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_CLK_CTRL_InternalClkEn(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.internalclken = data;
    *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_InternalClkEn] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_CLK_CTRL_InternalClkEn(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_InternalClkEn] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.internalclken;
}
GH_INLINE void GH_SDIO_set_CLK_CTRL_InternalClkStable(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.internalclkstable = data;
    *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_InternalClkStable] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_CLK_CTRL_InternalClkStable(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_InternalClkStable] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.internalclkstable;
}
GH_INLINE void GH_SDIO_set_CLK_CTRL_SdClkEn(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sdclken = data;
    *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_SdClkEn] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_CLK_CTRL_SdClkEn(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CLK_CTRL_SdClkEn] --> 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdclken;
}
GH_INLINE void GH_SDIO_set_CLK_CTRL_SdclkFreSelect(U8 index, U8 data)
{
    GH_SDIO_CLK_CTRL_S d;
    d.all = *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sdclkfreselect = data;
    *(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_CLK_CTRL_SdclkFreSelect] <-- 0x%08x\n",
                        (REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_CLK_CTRL_SdclkFreSelect(U8 index)
{
    GH_SDIO_CLK_CTRL_S tmp_value;
    U16 value = (*(volatile U16 *)(REG_SDIO_CLK_CTRL + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_Resp0Reg'. */
void GH_SDIO_set_Resp0Reg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_Resp0Reg'. */
U32  GH_SDIO_get_Resp0Reg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_Resp0Reg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp0Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_Resp0Reg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_RESP0REG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_Resp1Reg'. */
void GH_SDIO_set_Resp1Reg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_Resp1Reg'. */
U32  GH_SDIO_get_Resp1Reg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_Resp1Reg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp1Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_Resp1Reg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_RESP1REG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_Resp2Reg'. */
void GH_SDIO_set_Resp2Reg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_Resp2Reg'. */
U32  GH_SDIO_get_Resp2Reg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_Resp2Reg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp2Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_Resp2Reg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_RESP2REG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_Resp3Reg'. */
void GH_SDIO_set_Resp3Reg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_Resp3Reg'. */
U32  GH_SDIO_get_Resp3Reg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_Resp3Reg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Resp3Reg] <-- 0x%08x\n",
                        (REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_Resp3Reg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_RESP3REG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_Control00Reg'. */
U32  GH_SDIO_get_Control00Reg(U8 index);
/*! \brief Writes the bit group 'DataTraWidth' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_DataTraWidth(U8 index, U8 data);
/*! \brief Reads the bit group 'DataTraWidth' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_DataTraWidth(U8 index);
/*! \brief Writes the bit group 'Sd8BitMode' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_Sd8BitMode(U8 index, U8 data);
/*! \brief Reads the bit group 'Sd8BitMode' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_Sd8BitMode(U8 index);
/*! \brief Writes the bit group 'HostSpeedEn' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_HostSpeedEn(U8 index, U8 data);
/*! \brief Reads the bit group 'HostSpeedEn' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_HostSpeedEn(U8 index);
/*! \brief Writes the bit group 'SdBusPower' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_SdBusPower(U8 index, U8 data);
/*! \brief Reads the bit group 'SdBusPower' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_SdBusPower(U8 index);
/*! \brief Writes the bit group 'DriveCcsd' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_DriveCcsd(U8 index, U8 data);
/*! \brief Reads the bit group 'DriveCcsd' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_DriveCcsd(U8 index);
/*! \brief Writes the bit group 'StopAtBlkGapReq' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_StopAtBlkGapReq(U8 index, U8 data);
/*! \brief Reads the bit group 'StopAtBlkGapReq' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_StopAtBlkGapReq(U8 index);
/*! \brief Writes the bit group 'RWaitControl' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_RWaitControl(U8 index, U8 data);
/*! \brief Reads the bit group 'RWaitControl' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_RWaitControl(U8 index);
/*! \brief Writes the bit group 'ContinueReq' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_ContinueReq(U8 index, U8 data);
/*! \brief Reads the bit group 'ContinueReq' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_ContinueReq(U8 index);
/*! \brief Writes the bit group 'IntAtBlkGap' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_IntAtBlkGap(U8 index, U8 data);
/*! \brief Reads the bit group 'IntAtBlkGap' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_IntAtBlkGap(U8 index);
/*! \brief Writes the bit group 'WakeupEvetEnOnCardIns' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardIns(U8 index, U8 data);
/*! \brief Reads the bit group 'WakeupEvetEnOnCardIns' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardIns(U8 index);
/*! \brief Writes the bit group 'WakeupEvetEnOnCardInt' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardInt(U8 index, U8 data);
/*! \brief Reads the bit group 'WakeupEvetEnOnCardInt' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardInt(U8 index);
/*! \brief Writes the bit group 'WakeupEvetEnOnCardRem' of register 'SDIO_Control00Reg'. */
void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardRem(U8 index, U8 data);
/*! \brief Reads the bit group 'WakeupEvetEnOnCardRem' of register 'SDIO_Control00Reg'. */
U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardRem(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_Control00Reg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_Control00Reg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_Control00Reg_DataTraWidth(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.datatrawidth = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_DataTraWidth] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_DataTraWidth(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_DataTraWidth] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datatrawidth;
}
GH_INLINE void GH_SDIO_set_Control00Reg_Sd8BitMode(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sd8bitmode = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_Sd8BitMode] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_Sd8BitMode(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_Sd8BitMode] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sd8bitmode;
}
GH_INLINE void GH_SDIO_set_Control00Reg_HostSpeedEn(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.hostspeeden = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_HostSpeedEn] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_HostSpeedEn(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_HostSpeedEn] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.hostspeeden;
}
GH_INLINE void GH_SDIO_set_Control00Reg_SdBusPower(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.sdbuspower = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_SdBusPower] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_SdBusPower(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_SdBusPower] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdbuspower;
}
GH_INLINE void GH_SDIO_set_Control00Reg_DriveCcsd(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.driveccsd = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_DriveCcsd] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_DriveCcsd(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_DriveCcsd] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.driveccsd;
}
GH_INLINE void GH_SDIO_set_Control00Reg_StopAtBlkGapReq(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.stopatblkgapreq = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_StopAtBlkGapReq] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_StopAtBlkGapReq(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_StopAtBlkGapReq] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.stopatblkgapreq;
}
GH_INLINE void GH_SDIO_set_Control00Reg_RWaitControl(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.rwaitcontrol = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_RWaitControl] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_RWaitControl(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_RWaitControl] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.rwaitcontrol;
}
GH_INLINE void GH_SDIO_set_Control00Reg_ContinueReq(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.continuereq = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_ContinueReq] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_ContinueReq(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_ContinueReq] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.continuereq;
}
GH_INLINE void GH_SDIO_set_Control00Reg_IntAtBlkGap(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.intatblkgap = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_IntAtBlkGap] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_IntAtBlkGap(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_IntAtBlkGap] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.intatblkgap;
}
GH_INLINE void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardIns(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.wakeupevetenoncardins = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardIns] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardIns(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardIns] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wakeupevetenoncardins;
}
GH_INLINE void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardInt(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.wakeupevetenoncardint = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardInt] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardInt(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardInt] --> 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wakeupevetenoncardint;
}
GH_INLINE void GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardRem(U8 index, U8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.wakeupevetenoncardrem = data;
    *(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_Control00Reg_WakeupEvetEnOnCardRem] <-- 0x%08x\n",
                        (REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_Control00Reg_WakeupEvetEnOnCardRem(U8 index)
{
    GH_SDIO_CONTROL00REG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CONTROL00REG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Reads the register 'SDIO_PresentStateReg'. */
U32  GH_SDIO_get_PresentStateReg(U8 index);
/*! \brief Reads the bit group 'CmdInhibitCmd' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_CmdInhibitCmd(U8 index);
/*! \brief Reads the bit group 'DataLineActive' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_DataLineActive(U8 index);
/*! \brief Reads the bit group 'CmdInhibitData' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_CmdInhibitData(U8 index);
/*! \brief Reads the bit group 'RTraActive' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_RTraActive(U8 index);
/*! \brief Reads the bit group 'BufWEn' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_BufWEn(U8 index);
/*! \brief Reads the bit group 'WTraActive' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_WTraActive(U8 index);
/*! \brief Reads the bit group 'BufREn' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_BufREn(U8 index);
/*! \brief Reads the bit group 'CardInserted' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_CardInserted(U8 index);
/*! \brief Reads the bit group 'CardDetectPinLevel' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_CardDetectPinLevel(U8 index);
/*! \brief Reads the bit group 'CardStatesTable' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_CardStatesTable(U8 index);
/*! \brief Reads the bit group 'WProSwiPinLevel' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_WProSwiPinLevel(U8 index);
/*! \brief Reads the bit group 'Data03LineSigLevel' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_Data03LineSigLevel(U8 index);
/*! \brief Reads the bit group 'CmdLineSigLevel' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_CmdLineSigLevel(U8 index);
/*! \brief Reads the bit group 'Data47LineSigLevel' of register 'SDIO_PresentStateReg'. */
U8   GH_SDIO_get_PresentStateReg_Data47LineSigLevel(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE U32  GH_SDIO_get_PresentStateReg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_CmdInhibitCmd(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CmdInhibitCmd] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdinhibitcmd;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_DataLineActive(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_DataLineActive] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.datalineactive;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_CmdInhibitData(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CmdInhibitData] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdinhibitdata;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_RTraActive(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_RTraActive] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.rtraactive;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_BufWEn(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_BufWEn] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufwen;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_WTraActive(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_WTraActive] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wtraactive;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_BufREn(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_BufREn] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.bufren;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_CardInserted(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CardInserted] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardinserted;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_CardDetectPinLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CardDetectPinLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.carddetectpinlevel;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_CardStatesTable(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CardStatesTable] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cardstatestable;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_WProSwiPinLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_WProSwiPinLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.wproswipinlevel;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_Data03LineSigLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_Data03LineSigLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.data03linesiglevel;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_CmdLineSigLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_PresentStateReg_CmdLineSigLevel] --> 0x%08x\n",
                        (REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.cmdlinesiglevel;
}
GH_INLINE U8   GH_SDIO_get_PresentStateReg_Data47LineSigLevel(U8 index)
{
    GH_SDIO_PRESENTSTATEREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_PRESENTSTATEREG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_ArgReg'. */
void GH_SDIO_set_ArgReg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_ArgReg'. */
U32  GH_SDIO_get_ArgReg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_ArgReg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_ArgReg] <-- 0x%08x\n",
                        (REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_ArgReg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_ARGREG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Reads the register 'SDIO_CapReg'. */
U32  GH_SDIO_get_CapReg(U8 index);
/*! \brief Reads the bit group 'TimeoutClkUnit' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_TimeoutClkUnit(U8 index);
/*! \brief Reads the bit group 'BaseClkFreForSdClk' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_BaseClkFreForSdClk(U8 index);
/*! \brief Reads the bit group 'ExtendedMediaBusSup' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_ExtendedMediaBusSup(U8 index);
/*! \brief Reads the bit group 'HighSpeedSup' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_HighSpeedSup(U8 index);
/*! \brief Reads the bit group 'SusResSup' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_SusResSup(U8 index);
/*! \brief Reads the bit group 'SdmaSup' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_SdmaSup(U8 index);
/*! \brief Reads the bit group 'VoltageSup33v' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_VoltageSup33v(U8 index);
/*! \brief Reads the bit group 'VoltageSup30v' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_VoltageSup30v(U8 index);
/*! \brief Reads the bit group 'VoltageSup18v' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_VoltageSup18v(U8 index);
/*! \brief Reads the bit group 'IntMode' of register 'SDIO_CapReg'. */
U8   GH_SDIO_get_CapReg_IntMode(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE U32  GH_SDIO_get_CapReg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE U8   GH_SDIO_get_CapReg_TimeoutClkUnit(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_TimeoutClkUnit] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.timeoutclkunit;
}
GH_INLINE U8   GH_SDIO_get_CapReg_BaseClkFreForSdClk(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_BaseClkFreForSdClk] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.baseclkfreforsdclk;
}
GH_INLINE U8   GH_SDIO_get_CapReg_ExtendedMediaBusSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_ExtendedMediaBusSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.extendedmediabussup;
}
GH_INLINE U8   GH_SDIO_get_CapReg_HighSpeedSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_HighSpeedSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.highspeedsup;
}
GH_INLINE U8   GH_SDIO_get_CapReg_SusResSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_SusResSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.susressup;
}
GH_INLINE U8   GH_SDIO_get_CapReg_SdmaSup(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_SdmaSup] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.sdmasup;
}
GH_INLINE U8   GH_SDIO_get_CapReg_VoltageSup33v(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_VoltageSup33v] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.voltagesup33v;
}
GH_INLINE U8   GH_SDIO_get_CapReg_VoltageSup30v(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_VoltageSup30v] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.voltagesup30v;
}
GH_INLINE U8   GH_SDIO_get_CapReg_VoltageSup18v(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_CapReg_VoltageSup18v] --> 0x%08x\n",
                        (REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.voltagesup18v;
}
GH_INLINE U8   GH_SDIO_get_CapReg_IntMode(U8 index)
{
    GH_SDIO_CAPREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_CAPREG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_AutoCmd12ErrStatusReg'. */
U32  GH_SDIO_get_AutoCmd12ErrStatusReg(U8 index);
/*! \brief Writes the bit group 'AutoCmd12TimeoutErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12TimeoutErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr(U8 index);
/*! \brief Writes the bit group 'AutoCmd12CrcErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12CrcErr(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12CrcErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12CrcErr(U8 index);
/*! \brief Writes the bit group 'AutoCmd12EndBitErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12EndBitErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr(U8 index);
/*! \brief Writes the bit group 'AutoCmd12NotExe' of register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12NotExe(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12NotExe' of register 'SDIO_AutoCmd12ErrStatusReg'. */
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12NotExe(U8 index);
/*! \brief Writes the bit group 'AutoCmd12IndexErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12IndexErr(U8 index, U8 data);
/*! \brief Reads the bit group 'AutoCmd12IndexErr' of register 'SDIO_AutoCmd12ErrStatusReg'. */
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12IndexErr(U8 index);
/*! \brief Writes the bit group 'CmdNotIssuedByAutoCmd12Err' of register 'SDIO_AutoCmd12ErrStatusReg'. */
void GH_SDIO_set_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err(U8 index, U8 data);
/*! \brief Reads the bit group 'CmdNotIssuedByAutoCmd12Err' of register 'SDIO_AutoCmd12ErrStatusReg'. */
U8   GH_SDIO_get_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_AutoCmd12ErrStatusReg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return value;
}
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12timeouterr = data;
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12TimeoutErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12timeouterr;
}
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12CrcErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12crcerr = data;
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12CrcErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12CrcErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12CrcErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12crcerr;
}
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12endbiterr = data;
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12EndBitErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12endbiterr;
}
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12NotExe(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12notexe = data;
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12NotExe] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12NotExe(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12NotExe] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12notexe;
}
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12IndexErr(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.autocmd12indexerr = data;
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_AutoCmd12IndexErr] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12IndexErr(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

    tmp_value.all = value;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "value = RDREG(0x%08x); \\\\ [GH_SDIO_get_AutoCmd12ErrStatusReg_AutoCmd12IndexErr] --> 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),value);
    #endif
    return tmp_value.bitc.autocmd12indexerr;
}
GH_INLINE void GH_SDIO_set_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err(U8 index, U8 data)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S d;
    d.all = *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000));
    d.bitc.cmdnotissuedbyautocmd12err = data;
    *(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)) = d.all;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err] <-- 0x%08x\n",
                        (REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)),d.all,d.all);
    #endif
}
GH_INLINE U8   GH_SDIO_get_AutoCmd12ErrStatusReg_CmdNotIssuedByAutoCmd12Err(U8 index)
{
    GH_SDIO_AUTOCMD12ERRSTATUSREG_S tmp_value;
    U32 value = (*(volatile U32 *)(REG_SDIO_AUTOCMD12ERRSTATUSREG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Writes the register 'SDIO_BufferDataPortReg'. */
void GH_SDIO_set_BufferDataPortReg(U8 index, U32 data);
/*! \brief Reads the register 'SDIO_BufferDataPortReg'. */
U32  GH_SDIO_get_BufferDataPortReg(U8 index);
#else /* GH_INLINE_LEVEL == 0 */
GH_INLINE void GH_SDIO_set_BufferDataPortReg(U8 index, U32 data)
{
    *(volatile U32 *)(REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)) = data;
    #if GH_SDIO_ENABLE_DEBUG_PRINT
    GH_SDIO_DEBUG_PRINT_FUNCTION( "WRREG(0x%08x,0x%08x); \\\\ [GH_SDIO_set_BufferDataPortReg] <-- 0x%08x\n",
                        (REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)),data,data);
    #endif
}
GH_INLINE U32  GH_SDIO_get_BufferDataPortReg(U8 index)
{
    U32 value = (*(volatile U32 *)(REG_SDIO_BUFFERDATAPORTREG + index * FIO_MOFFSET(SDIO,0x1000)));

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
/*! \brief Initialises the registers and mirror variables. */
void GH_SDIO_init(void);

#ifdef __cplusplus
}
#endif

#endif /* _GH_SDIO_H */

/*----------------------------------------------------------------------------*/
/* end of file                                                                */
/*----------------------------------------------------------------------------*/

