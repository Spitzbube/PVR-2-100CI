/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_pininput.c
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
**
** \note The following LINT statements have been suppressed:
**
** - Info    715: Symbol not referenced.
*****************************************************************************
*/
/*lint -save -e715 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_pininput.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_PININPUT_SetFocus   (FAPI_SYS_HandleT h, fbool_t hasFocus);
static int32_t  FGS_PININPUT_Show       (FAPI_SYS_HandleT h);
static int32_t  FGS_PININPUT_Hide       (FAPI_SYS_HandleT h);
static int32_t  FGS_PININPUT_Close      (FAPI_SYS_HandleT h);
static fbool_t  FGS_PININPUT_Abort      (FAPI_SYS_HandleT h);
static fbool_t  FGS_PININPUT_Number     (FAPI_SYS_HandleT h, uint8_t value);
static int32_t  FGS_PININPUT_DrawDigit  (FAPI_SYS_HandleT h, uint8_t digitIdx);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_PININPUT_INIT_S*    pinGlobal  = NULL;
static FGS_PININPUT_DRAWIF_S*  pinDraw    = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

int32_t FGS_PININPUT_Init (FGS_PININPUT_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    pinGlobal = FGS_Malloc(sizeof(FGS_PININPUT_INIT_S));
    if ( pinGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*pinGlobal) = (*pInitParams);
    pinDraw      = &(pinGlobal->draw);

    return FAPI_OK;
}

int32_t FGS_PININPUT_Open (FGS_PININPUT_OPEN_S* pData, int32_t id, FAPI_SYS_HandleT parent,
                        FAPI_SYS_HandleT* ph)
{
    FGS_PININPUT_INST_S* inst;
    FGS_PANEL_MEMBER_S   member;
    int32_t              retVal;
    fbool_t              memAllocated = FFALSE;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( pData->pInst != NULL )
    {
        inst = pData->pInst;
    }
    else
    {
        inst = FGS_Malloc(sizeof(FGS_PININPUT_INST_S));
        if ( inst == NULL )
        {
            return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
        }

        memAllocated = FTRUE;
    }

    memset(inst, 0, sizeof(FGS_PININPUT_INST_S));

    inst->memAllocated = memAllocated;
    inst->data         = *pData;
    inst->pMem         = NULL;
    inst->pPanel       = (FGS_PANEL_INST_S*)parent;

    inst->data.params.digitPos = 0;

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as panel member */

    memset(&member, 0, sizeof(FGS_PANEL_MEMBER_S));

    member.h         = (FAPI_SYS_HandleT)inst;
    member.pos       = &(inst->data.pos);
    member.id        = id;
    member.isHidden  = inst->data.isHidden;
    member.setFocus  = FGS_PININPUT_SetFocus;
    member.show      = FGS_PININPUT_Show;
    member.hide      = FGS_PININPUT_Hide;
    member.close     = FGS_PININPUT_Close;

    retVal = FGS_PANEL_AddMember(parent, &member, &(inst->pMem));

    if ( (retVal             != FAPI_OK) &&
         (inst->memAllocated == FTRUE) )
    {
        FGS_Free(inst);
    }

    return retVal;
}

int32_t FGS_PININPUT_SetParams (FAPI_SYS_HandleT h, const FGS_PININPUT_PARAMS_S* params)
{
    FGS_PININPUT_INST_S* inst = (FGS_PININPUT_INST_S*)h;

    if ( inst   == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;
    if ( params == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    inst->data.params = *params;

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible )
    {
        (void)FGS_PININPUT_Show(h);
    }

    return FAPI_OK;
}

int32_t FGS_PININPUT_GetParams (FAPI_SYS_HandleT h, FGS_PININPUT_PARAMS_S* params)
{
    FGS_PININPUT_INST_S* inst = (FGS_PININPUT_INST_S*)h;

    if ( inst   == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;
    if ( params == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    *params = inst->data.params;

    return FAPI_OK;
}

static int32_t FGS_PININPUT_Close (FAPI_SYS_HandleT h)
{
    FGS_PININPUT_INST_S*  inst = (FGS_PININPUT_INST_S*)h;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( inst->memAllocated == FTRUE)
    {
        FGS_Free(inst);
    }

    return FAPI_OK;
}

static int32_t FGS_PININPUT_Show (FAPI_SYS_HandleT h)
{
    FGS_PININPUT_INST_S* inst = (FGS_PININPUT_INST_S*)h;
    uint8_t                   cnt;

    if ( pinDraw->drawBkgr != NULL )
    {
        pinDraw->drawBkgr(h, inst->pPanel);
    }

    for ( cnt = 0; cnt < inst->data.params.digitsMax; cnt++ )
    {
        (void)FGS_PININPUT_DrawDigit(h, cnt);
    }

    return FAPI_OK;
}

static int32_t FGS_PININPUT_DrawDigit (FAPI_SYS_HandleT h, uint8_t digitIdx)
{
    FGS_PININPUT_INST_S* inst = (FGS_PININPUT_INST_S*)h;
    FGS_ITEM_S           item;
    FGS_POS_S            itemPos;
    int8_t               digitValue;

    memset(&item,    0, sizeof(item));
    memset(&itemPos, 0, sizeof(itemPos));

    if ( digitIdx >= inst->data.params.digitPos )
    {
         digitValue = -1;
    }
    else
    {
        digitValue = (int8_t)inst->data.pinBuf[digitIdx];
    }

    item.type = FGS_ITEM_TYPE_NONE;

    inst->data.getItem (inst->data.getItemArg,
                        inst->pMem->id,
                        digitIdx,
                        digitValue,
                        inst->data.params.clearMode,
                        &item, &itemPos);

    if ( pinDraw->drawDigitBkgr != NULL )
    {
        pinDraw->drawDigitBkgr (h, inst->pPanel,
                                (uint16_t)(inst->pMem->abspos.x + itemPos.x),
                                (uint16_t)(inst->pMem->abspos.y + itemPos.y),
                                itemPos.width,
                                itemPos.height,
                                digitIdx);
    }

    if ( item.type != FGS_ITEM_TYPE_NONE )
    {
        (void)FGS_DrawItem (&item,
                      (uint16_t)(inst->pMem->abspos.x + itemPos.x),
                      (uint16_t)(inst->pMem->abspos.y + itemPos.y),
                      itemPos.width,
                      itemPos.height);
    }

    return FAPI_OK;
}

static int32_t FGS_PININPUT_Hide (FAPI_SYS_HandleT h)
{
    //FGS_PININPUT_INST_S*   inst = (FGS_PININPUT_INST_S*)h;

    /* nothing to do...*/

    return FAPI_OK;
}

static int32_t FGS_PININPUT_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_PININPUT_INST_S* inst   = (FGS_PININPUT_INST_S*)h;

    /* call item's focus-set handler if available */
    if (  inst->pMem->isVisible &&
         (inst->data.onFocusSet != NULL) )
    {
        inst->data.onFocusSet(inst->data.onFocusSetArg, hasFocus);
    }

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible )
    {
        (void)FGS_PANEL_RefreshMember((FAPI_SYS_HandleT)inst->pPanel, inst->pMem->id);
    }

    /* install/release GUI key handlers */
    if ( hasFocus )
    {
        FGS_SetNumKeyHandler(FGS_KEY_NUMBER, FGS_PININPUT_Number, h, FTRUE);
        FGS_SetKeyHandler   (FGS_KEY_MENU,   FGS_PININPUT_Abort,  h, FTRUE);
        FGS_SetKeyHandler   (FGS_KEY_EXIT,   FGS_PININPUT_Abort,  h, FTRUE);
    }
    else
    {
        FGS_ClearAllHandlers();
    }

    return FAPI_OK;
}

static fbool_t FGS_PININPUT_Abort (FAPI_SYS_HandleT h)
{
    FGS_PININPUT_INST_S* inst = (FGS_PININPUT_INST_S*)h;

    if ( inst->data.onAbort != NULL )
    {
        inst->data.onAbort(inst->data.onAbortArg, inst->pMem->id);
    }

    return FTRUE;
}

static fbool_t FGS_PININPUT_Number (FAPI_SYS_HandleT h, uint8_t value)
{
    FGS_PININPUT_INST_S* inst = (FGS_PININPUT_INST_S*)h;

    if ( inst->data.params.digitPos < inst->data.params.digitsMax )
    {
        inst->data.pinBuf[inst->data.params.digitPos++] = value;

        if ( inst->pMem->isVisible )
        {
            (void)FGS_PININPUT_DrawDigit(h, inst->data.params.digitPos - 1);

            if ( inst->data.params.digitPos < inst->data.params.digitsMax )
            {
                (void)FGS_PININPUT_DrawDigit(h, inst->data.params.digitPos);
            }
        }

        if ( (inst->data.params.digitPos == inst->data.params.digitsMax) &&
             (inst->data.onPinEnter != NULL) )
        {
            inst->data.onPinEnter(inst->data.onPinEnterArg,
                                  inst->pMem->id,
                                  inst->data.pinBuf,
                                  inst->data.params.digitPos);
        }

        return FTRUE;
    }
    else
    {
        return FFALSE;
    }
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
