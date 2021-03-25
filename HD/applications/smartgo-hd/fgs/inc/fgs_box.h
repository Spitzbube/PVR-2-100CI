/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_box.h
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
#ifndef _FGS_BOX_H_
#define _FGS_BOX_H_

#include "fgs_panel.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

enum // TODO: deprecated: to be removed!
{
    FGS_BOX_IDX_NONFOCUS = 0,
    FGS_BOX_IDX_FOCUS,
    FGS_BOX_IDX_MAX
};

typedef struct
{
    void (*drawBkgr) (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl);  // optional
    
} FGS_BOX_DRAWIF_S;

typedef struct
{
    FGS_BOX_DRAWIF_S draw;
    
} FGS_BOX_INIT_S;

typedef struct
{
    FGS_POS_S           pos;            //!< Box position.
    fbool_t             isHidden;       //!< Hidden-status.
    uint32_t            bkgrType;       //!< User-specific type information.
    FGS_ITEM_S          item[FGS_BOX_IDX_MAX]; // deprecated, to be removed
    FGS_GETITEM_CB      getItem;
    FAPI_SYS_HandleT    getItemArg;
    void*               pInst;
    
} FGS_BOX_OPEN_S;

typedef struct
{
    fbool_t             memAllocated;
    FGS_BOX_OPEN_S      data;
    FGS_PANEL_MEMBER_S* pMem;            //!< pointer to own member structure
    FGS_PANEL_INST_S*   pPanel;          //!< pointer to parent panel
    
} FGS_BOX_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_BOX_Init             (FGS_BOX_INIT_S* pInitParams);
int32_t  FGS_BOX_Open             (FGS_BOX_OPEN_S* pData, int32_t id, 
                                FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);
// deprecated, to be removed
int32_t  FGS_BOX_SetNonFocusItem  (FAPI_SYS_HandleT h, FGS_ITEM_S* pItem);
int32_t  FGS_BOX_SetFocusItem     (FAPI_SYS_HandleT h, FGS_ITEM_S* pItem);
int32_t  FGS_BOX_Clear            (FAPI_SYS_HandleT h);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_BOX_H_ */
/******************************************************************************/
/* END OF FILE */
