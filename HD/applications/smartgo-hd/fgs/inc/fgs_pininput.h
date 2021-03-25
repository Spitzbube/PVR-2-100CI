/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_pininput.h
**
** \brief       content description.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
**
*****************************************************************************
*/
#ifndef _FGS_PININPUT_H_
#define _FGS_PININPUT_H_

#include "fgs_panel.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

/*
digitValue: -1:     not entered yet
            others: digit value (0...9)
*/
typedef void  (*FGS_PININPUT_GETITEM_CB)  (FAPI_SYS_HandleT h, int32_t id, uint32_t digitIdx,
                                           int8_t digitValue,
                                           fbool_t clearMode,
                                           FGS_ITEM_S* item,
                                           FGS_POS_S* pos);

typedef void (*FGS_PININPUT_ENTER_CB) (FAPI_SYS_HandleT h, int32_t id, uint8_t* pin, uint8_t pinLen);
typedef void (*FGS_PININPUT_ABORT_CB) (FAPI_SYS_HandleT h, int32_t id);

typedef struct
{
    void (*drawBkgr)      (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl);  // optional
    void (*drawDigitBkgr) (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl,
                           uint16_t x, uint16_t y, uint16_t width, uint16_t height,
                           uint16_t digitIndex);                         // optional

} FGS_PININPUT_DRAWIF_S;

typedef struct
{
    FGS_PININPUT_DRAWIF_S draw;

} FGS_PININPUT_INIT_S;

typedef struct
{
    fbool_t                 clearMode;     //!< FTRUE: Entered PIN values are
                                           //!< readable on OSD.
    uint8_t                 digitPos;      //!< Position of next PIN digit.
    uint8_t                 digitsMax;     //!< Maximum number of PIN digits.

} FGS_PININPUT_PARAMS_S;

typedef struct
{
    FGS_POS_S               pos;           //!< Position and size.
    fbool_t                 isHidden;
    uint32_t                bkgrType;      //!< User-specific type information.
    FGS_PININPUT_PARAMS_S   params;        //!< Dynamic parameters.

    uint8_t*                pinBuf;        //!< Pointer to PIN buffer (must be able
                                           //!< to hold max. number of digits).
    FGS_PININPUT_GETITEM_CB getItem;       //!< optional
    FAPI_SYS_HandleT        getItemArg;    //!< optional
    FGS_FOCUSSET_CB         onFocusSet;    //!< Focus-set/remove-callback (opt.).
    FAPI_SYS_HandleT        onFocusSetArg; //!< Optional argument for onFocusSet.
    FGS_PININPUT_ENTER_CB   onPinEnter;
    FAPI_SYS_HandleT        onPinEnterArg;
    FGS_PININPUT_ABORT_CB   onAbort;
    FAPI_SYS_HandleT        onAbortArg;

    void*                   pInst;

} FGS_PININPUT_OPEN_S;

typedef struct
{
    fbool_t                 memAllocated;
    FGS_PININPUT_OPEN_S     data;
    FGS_PANEL_MEMBER_S*     pMem;        //!< pointer to own member structure
    FGS_PANEL_INST_S*       pPanel;      //!< pointer to parent panel

    uint8_t                pinPos;

} FGS_PININPUT_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_PININPUT_Init        (FGS_PININPUT_INIT_S* pInitParams);
int32_t  FGS_PININPUT_Open        (FGS_PININPUT_OPEN_S* pData, int32_t id,
                                   FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);
int32_t  FGS_PININPUT_SetParams   (FAPI_SYS_HandleT h, const FGS_PININPUT_PARAMS_S* params);
int32_t  FGS_PININPUT_GetParams   (FAPI_SYS_HandleT h, FGS_PININPUT_PARAMS_S* params);

// Reset


#ifdef __cplusplus
}
#endif

#endif /* _FGS_PININPUT_H_ */
/******************************************************************************/
/* END OF FILE */
