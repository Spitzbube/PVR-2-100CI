/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_item_text.c
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
**
*****************************************************************************
*/
/*lint -save */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_item_text.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_ITEM_TXT_INIT_S*     fgsItemTxtGlobal  = NULL;
static FGS_ITEM_DRAWIF_S*       fgsTxtDraw = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_ITEM_TXT_Close       (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_TXT_Draw        (FAPI_SYS_HandleT h);
//static int32_t  FGS_ITEM_TXT_SetValue    (FAPI_SYS_HandleT h, FGS_VAL_S* pValue);
static int32_t  FGS_ITEM_TXT_SetFocus    (FAPI_SYS_HandleT h, fbool_t hasFocus);


/*  - todo */
int32_t FGS_ITEM_TXT_Init (FGS_ITEM_TXT_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsItemTxtGlobal = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_ITEM_TXT_INIT_S));
    if ( fgsItemTxtGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsItemTxtGlobal) = (*pInitParams);

    fgsTxtDraw = &(fgsItemTxtGlobal->gfx);

    return FAPI_OK;
}


/* 21babe00 - complete */
int32_t FGS_ITEM_TXT_Open (FGS_ITEM_TXT_OPEN_S* pData, int32_t id,
                        FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph)
{
    FGS_ITEM_TXT_INST_S*  inst;
    FGS_LIST_MEMBER_S     member;
    int32_t                  retVal;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    inst = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_ITEM_TXT_INST_S));
    if ( inst == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    inst->data         = *pData;
    inst->pMem         = NULL;

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
    member.setFocus    = FGS_ITEM_TXT_SetFocus;
    member.draw        = FGS_ITEM_TXT_Draw;
    member.close       = FGS_ITEM_TXT_Close;

    retVal = FGS_LIST_AddMember (parent, &member, &(inst->pMem));

    if ( retVal != FAPI_OK )
    {
        /*FGS_Free*/SYS_MemoryFree(inst);
    }

    return retVal;
}


/* 21babd88 - complete */
static int32_t FGS_ITEM_TXT_Close (FAPI_SYS_HandleT h)
{
    FGS_ITEM_TXT_INST_S* inst = (FGS_ITEM_TXT_INST_S*)h;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    /*FGS_Free*/SYS_MemoryFree(inst);

    return FAPI_OK;

}


/* 21babc1c - complete */
static int32_t FGS_ITEM_TXT_Draw (FAPI_SYS_HandleT h)
{
    FGS_ITEM_TXT_INST_S* inst = (FGS_ITEM_TXT_INST_S*)h;
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
                                      inst->pMem->id, 0, state, &item);
    }

    /* paint background */
    if ( fgsTxtDraw->drawBkgr != NULL )
    {
        fgsTxtDraw->drawBkgr (h, inst->pMem->pPanel, &item);
    }

    /* draw description item */
    FGS_LIST_DrawItemDescr(inst->pMem);

    /* draw value item */
    if ( item.type != FGS_ITEM_TYPE_NONE )
    {
        /* draw value item */
        (void)FGS_DrawItem (&item,
                      (uint16_t)(inst->pMem->abspos.x + inst->pMem->valuePos.x),
                      (uint16_t)(inst->pMem->abspos.y + inst->pMem->valuePos.y),
                      inst->pMem->valuePos.width,
                      inst->pMem->valuePos.height);
    }

    /* paint rest */
    if ( fgsTxtDraw->drawRest != NULL )
    {
        fgsTxtDraw->drawRest(h);
    }

    return FAPI_OK;
}

/* 21babd50 - complete */
static int32_t FGS_ITEM_TXT_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_ITEM_TXT_INST_S* inst = (FGS_ITEM_TXT_INST_S*)h;

    if ( inst->pMem->hasFocus == hasFocus ) return FAPI_OK;

    inst->pMem->hasFocus = hasFocus;

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible == FTRUE ) (void)FGS_ITEM_TXT_Draw(h);
    return FAPI_OK;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
