/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_item_select.c
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
*****************************************************************************
*/
/*lint -save  */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_item_select.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_ITEM_SEL_Close       (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_SEL_Draw        (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_SEL_SetFocus    (FAPI_SYS_HandleT h, fbool_t hasFocus);
static int32_t  FGS_ITEM_SEL_GetParams   (FAPI_SYS_HandleT h, void* params);
static int32_t  FGS_ITEM_SEL_SetParams   (FAPI_SYS_HandleT h, const void* params);
static fbool_t  FGS_ITEM_SEL_Left        (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_SEL_Right       (FAPI_SYS_HandleT h);
static void     FGS_ITEM_SEL_ValChanged  (FGS_ITEM_SEL_INST_S* inst);
static int32_t  FGS_ITEM_SEL_CheckParams (const FGS_ITEM_SEL_PARAMS_S* params);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_ITEM_SEL_INIT_S*   fgsItemSelGlobal  = NULL;
static FGS_ITEM_DRAWIF_S*     fgsSelDraw = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/


/* 21baba70 - todo */
int32_t FGS_ITEM_SEL_Init (FGS_ITEM_SEL_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsItemSelGlobal = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_ITEM_SEL_INIT_S));
    if ( fgsItemSelGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsItemSelGlobal) = (*pInitParams);

    fgsSelDraw = &(fgsItemSelGlobal->gfx);

    return FAPI_OK;
}


/* 21babac8 - complete */
int32_t FGS_ITEM_SEL_Open (FGS_ITEM_SEL_OPEN_S* pData, int32_t id,
                        FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph)
{
    FGS_ITEM_SEL_INST_S*   inst;
    FGS_LIST_MEMBER_S      member;
    int32_t                retVal;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    retVal = FGS_ITEM_SEL_CheckParams(&(pData->params));
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    inst = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_ITEM_SEL_INST_S));
    if ( inst == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    inst->data = *pData;
    inst->pMem = NULL;

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as list member */

    memset(&member, 0, sizeof(FGS_LIST_MEMBER_S));

    member.h            = (FAPI_SYS_HandleT)inst;
    member.pos          = &(inst->data.pos);
    member.id           = id;
    member.isVisible    = FFALSE;
    member.hasFocus     = FFALSE;
    member.isActivated  = FFALSE;
    member.descrPos     = inst->data.descrPos;
    member.valuePos     = inst->data.valuePos;
    member.setFocus     = FGS_ITEM_SEL_SetFocus;
    member.draw         = FGS_ITEM_SEL_Draw;
    member.close        = FGS_ITEM_SEL_Close;
    member.getParams    = FGS_ITEM_SEL_GetParams;
    member.setParams    = FGS_ITEM_SEL_SetParams;
    member.left         = FGS_ITEM_SEL_Left;
    member.right        = FGS_ITEM_SEL_Right;

    retVal = FGS_LIST_AddMember (parent, &member, &(inst->pMem));

    if ( retVal != FAPI_OK )
    {
        /*FGS_Free*/SYS_MemoryFree(inst);
    }

    return retVal;
}

static int32_t FGS_ITEM_SEL_Close (FAPI_SYS_HandleT h)
{
    FGS_ITEM_SEL_INST_S* inst   = (FGS_ITEM_SEL_INST_S*)h;

    if ( inst == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    /*FGS_Free*/SYS_MemoryFree(inst);

    return FAPI_OK;
}

static int32_t FGS_ITEM_SEL_Draw (FAPI_SYS_HandleT h)
{
    FGS_ITEM_SEL_INST_S* inst = (FGS_ITEM_SEL_INST_S*)h;
    FGS_ITEM_S           item;
    FGS_ITEMSTATE_E      state;

    if ( !(inst->pMem->isVisible) ) return FAPI_OK;

    memset(&item, 0, sizeof(item));
    item.type = FGS_ITEM_TYPE_NONE;

    if ( inst->pMem->pParent->getItem != NULL )
    {
        if      (!(inst->pMem->isEnabled)) state = FGS_DISABLED;
        else if   (inst->pMem->hasFocus)   state = FGS_FOCUS;
        else                               state = FGS_NONFOCUS;

        inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                      inst->pMem->id,
                                      inst->data.params.index, state, &item);
    }

    /* paint background */
    if ( fgsSelDraw->drawBkgr != NULL )
    {
        fgsSelDraw->drawBkgr (h, inst->pMem->pPanel, &item);
    }

    FGS_LIST_DrawItemDescr(inst->pMem);

    /* draw value item */
    (void)FGS_DrawItem (&item,
                  (uint16_t)(inst->pMem->abspos.x + inst->pMem->valuePos.x),
                  (uint16_t)(inst->pMem->abspos.y + inst->pMem->valuePos.y),
                  inst->pMem->valuePos.width,
                  inst->pMem->valuePos.height);

    /* paint rest */
    if ( fgsSelDraw->drawRest != NULL )
    {
        fgsSelDraw->drawRest(h);
    }

    return FAPI_OK;
}

static int32_t FGS_ITEM_SEL_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_ITEM_SEL_INST_S* inst   = (FGS_ITEM_SEL_INST_S*)h;

    if ( inst->pMem->hasFocus != hasFocus )
    {
        inst->pMem->hasFocus = hasFocus;

        /* redraw item if currently visible */
        if ( inst->pMem->isVisible ) (void)FGS_ITEM_SEL_Draw(h);
    }

    return FAPI_OK;
}

static int32_t FGS_ITEM_SEL_GetParams (FAPI_SYS_HandleT h, void* params)
{
    FGS_ITEM_SEL_INST_S* inst   = (FGS_ITEM_SEL_INST_S*)h;

    if ( inst   == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;
    if ( params == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    *((FGS_ITEM_SEL_PARAMS_S*)params) = inst->data.params;
    return FAPI_OK;
}

static int32_t FGS_ITEM_SEL_SetParams (FAPI_SYS_HandleT h, const void* params)
{
    FGS_ITEM_SEL_INST_S*         inst = (FGS_ITEM_SEL_INST_S*)h;
    const FGS_ITEM_SEL_PARAMS_S* pPar = params;
    int32_t                      retVal;

    if ( inst   == NULL )
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    if ( params == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    retVal = FGS_ITEM_SEL_CheckParams(params);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    inst->data.params = *pPar;

    FGS_ITEM_SEL_ValChanged(inst);

    /* redraw item if currently visible */
    if ( (inst->pMem->isVisible) &&
         (inst->pMem->pParent->autoRefresh) )
    {
        (void)FGS_ITEM_SEL_Draw(h);
    }

    return FAPI_OK;
}


static fbool_t FGS_ITEM_SEL_Left (FAPI_SYS_HandleT h)
{
    FGS_ITEM_SEL_INST_S* inst   = (FGS_ITEM_SEL_INST_S*)h;

    if ( inst->data.params.numItems < 2 ) return FFALSE;

    if ( inst->data.params.index == 0 )
    {
        inst->data.params.index = inst->data.params.numItems;
    }

    inst->data.params.index--;

    FGS_ITEM_SEL_ValChanged(inst);

    if ( inst->pMem->isVisible ) (void)FGS_ITEM_SEL_Draw(h);
    return FTRUE;
}

static fbool_t FGS_ITEM_SEL_Right (FAPI_SYS_HandleT h)
{
    FGS_ITEM_SEL_INST_S* inst   = (FGS_ITEM_SEL_INST_S*)h;

    if ( inst->data.params.numItems < 2 ) return FFALSE;

    inst->data.params.index++;

    if ( inst->data.params.index >= (uint32_t)inst->data.params.numItems )
    {
        inst->data.params.index = 0;
    }

    FGS_ITEM_SEL_ValChanged(inst);

    if ( inst->pMem->isVisible ) (void)FGS_ITEM_SEL_Draw(h);
    return FTRUE;
}

static void FGS_ITEM_SEL_ValChanged (FGS_ITEM_SEL_INST_S* inst)
{
    FGS_VAL_S value;

    memset(&value, 0,sizeof(value));

    if ( inst->pMem->pParent->onValChg != NULL )
    {
        value.number = (int32_t)inst->data.params.index;

        inst->pMem->pParent->onValChg(inst->pMem->pParent->onValChgArg,
                                      inst->pMem->id,
                                      value);
    }
}


/* 21bab6d0 - complete */
static int32_t FGS_ITEM_SEL_CheckParams (const FGS_ITEM_SEL_PARAMS_S* params)
{
    if ( (params->numItems > 0) &&
         (params->index    >= (uint32_t)params->numItems) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    return FAPI_OK;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
