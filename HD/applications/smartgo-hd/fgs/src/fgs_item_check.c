/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_item_check.c
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
** - Info    732: Loss of sign (assignment) (int to unsigned short).
**
*****************************************************************************
*/
/*lint -save -e732 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_item_check.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/
static int32_t  FGS_ITEM_CHECK_Close       (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_CHECK_Draw        (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_CHECK_SetFocus    (FAPI_SYS_HandleT h, fbool_t hasFocus);
static int32_t  FGS_ITEM_CHECK_GetParams   (FAPI_SYS_HandleT h, void* params);
static int32_t  FGS_ITEM_CHECK_SetParams   (FAPI_SYS_HandleT h, const void* params);
static fbool_t  FGS_ITEM_CHECK_Ok          (FAPI_SYS_HandleT h);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FGS_ITEM_CHECK_INIT_S*   fgsItemCheckGlobal    = NULL;
static FGS_ITEM_DRAWIF_S*       fgsCheckDraw = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

int32_t FGS_ITEM_CHECK_Init  (FGS_ITEM_CHECK_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }
    fgsItemCheckGlobal = FGS_Malloc(sizeof(FGS_ITEM_CHECK_INIT_S));
    if ( fgsItemCheckGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }
    (*fgsItemCheckGlobal) = (*pInitParams);

    fgsCheckDraw = &(fgsItemCheckGlobal->gfx);

    return FAPI_OK;
}

int32_t FGS_ITEM_CHECK_Open  (FGS_ITEM_CHECK_OPEN_S* pData, int32_t id,
                              FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph)
{
    FGS_ITEM_CHECK_INST_S* inst;
    FGS_LIST_MEMBER_S      member;
    int32_t                retVal;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    inst = FGS_Malloc(sizeof(FGS_ITEM_CHECK_INST_S));
    if ( inst == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    inst->data        = *pData;
    inst->pMem        = NULL;

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as list member */

    memset(&member, 0, sizeof(FGS_LIST_MEMBER_S));

    member.h           = (FAPI_SYS_HandleT)inst;
    member.pos         = &(inst->data.pos);
    member.id          = id;
    member.isVisible   = FFALSE;
    member.hasFocus    = FFALSE;
    member.isActivated = FFALSE;
    member.descrPos    = inst->data.descrPos;
    member.valuePos    = inst->data.valuePos;
    member.setFocus    = FGS_ITEM_CHECK_SetFocus;
    member.draw        = FGS_ITEM_CHECK_Draw;
    member.close       = FGS_ITEM_CHECK_Close;
    member.getParams   = FGS_ITEM_CHECK_GetParams;
    member.setParams   = FGS_ITEM_CHECK_SetParams;
    member.ok          = FGS_ITEM_CHECK_Ok;

    retVal = FGS_LIST_AddMember (parent, &member, &(inst->pMem));
    if ( retVal != FAPI_OK )
    {
        FGS_Free(inst);
    }

    return retVal;
}

static int32_t FGS_ITEM_CHECK_Close (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHECK_INST_S* inst = (FGS_ITEM_CHECK_INST_S*)h;

    if (inst == NULL)
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    FGS_Free(inst);

    return FAPI_OK;
}

static int32_t FGS_ITEM_CHECK_Draw  (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHECK_INST_S* inst = (FGS_ITEM_CHECK_INST_S*)h;
    FGS_ITEM_S             item;
    FGS_ITEMSTATE_E        state;

    if ( !(inst->pMem->isVisible) )
    {
        return FAPI_OK;
    }

    memset(&item, 0, sizeof(item));
    item.type = FGS_ITEM_TYPE_NONE;

    if ( inst->pMem->pParent->getItem != NULL )
    {
        if ( !(inst->pMem->isEnabled) )
        {
            state = FGS_DISABLED;
        }
        else if(inst->pMem->hasFocus)
        {
            state = FGS_FOCUS;
        }
        else
        {
            state = FGS_NONFOCUS;
        }

        inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                      inst->pMem->id,
                                      (inst->data.params.active) ? 1 : 0, state, &item);
    }

    /* paint background */
    if ( fgsCheckDraw->drawBkgr != NULL )
    {
        fgsCheckDraw->drawBkgr (h, inst->pMem->pPanel, &item);
    }

    FGS_LIST_DrawItemDescr(inst->pMem);

    /* draw value item */
    if ( item.type != FGS_ITEM_TYPE_NONE )
    {
        /* draw value item */
        (void)FGS_DrawItem (&item,
                      inst->pMem->abspos.x + inst->pMem->valuePos.x,
                      inst->pMem->abspos.y + inst->pMem->valuePos.y,
                      inst->pMem->valuePos.width,
                      inst->pMem->valuePos.height);
    }

    /* paint rest */
    if ( fgsCheckDraw->drawRest != NULL )
    {
        fgsCheckDraw->drawRest(h);
    }

    return FAPI_OK;
}

int32_t FGS_ITEM_CHECK_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_ITEM_CHECK_INST_S* inst = (FGS_ITEM_CHECK_INST_S*)h;

    if ( inst->pMem->hasFocus == hasFocus )
    {
        return FAPI_OK;
    }

    inst->pMem->hasFocus = hasFocus;

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible )
    {
        (void)FGS_ITEM_CHECK_Draw(h);
    }

    return FAPI_OK;
}


int32_t FGS_ITEM_CHECK_GetParams (FAPI_SYS_HandleT h, void* params)
{
    FGS_ITEM_CHECK_INST_S* inst = (FGS_ITEM_CHECK_INST_S*)h;

    if ( inst   == NULL )
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    if ( params == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    *((FGS_ITEM_CHECK_PARAMS_S*)params) = inst->data.params;
    return FAPI_OK;
}

int32_t FGS_ITEM_CHECK_SetParams (FAPI_SYS_HandleT h, const void* params)
{
    FGS_ITEM_CHECK_INST_S* inst = (FGS_ITEM_CHECK_INST_S*)h;

    if ( inst   == NULL )
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    if ( params == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    inst->data.params = *((FGS_ITEM_CHECK_PARAMS_S*)params);

    /* Redraw item if visible */
    if ( (inst->pMem->isVisible) &&
         (inst->pMem->pParent->autoRefresh) )
    {
        (void)FGS_ITEM_CHECK_Draw(h);
    }

    return FAPI_OK;
}

fbool_t FGS_ITEM_CHECK_Ok (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHECK_INST_S* inst = (FGS_ITEM_CHECK_INST_S*)h;
    FGS_VAL_S              value;

    memset(&value, 0 ,sizeof(value));

    /* Toggle activity status */
    inst->data.params.active = (inst->data.params.active == FTRUE) ? FFALSE : FTRUE;

    if ( inst->pMem->pParent->onValChg != NULL )
    {
        value.number = (inst->data.params.active) ? 1 : 0;
        inst->pMem->pParent->onValChg(inst->pMem->pParent->onValChgArg,
                                      inst->pMem->id,
                                      value);
    }

    /* Redraw item if visible */
    if ( inst->pMem->isVisible )
    {
        (void)FGS_ITEM_CHECK_Draw(h);
    }

    return FTRUE;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
