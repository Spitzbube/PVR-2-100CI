/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_box.c
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
** - Info    732: Loss of sign (assignment) (int to unsigned short).
**
*****************************************************************************
*/
/*lint -save -e715 -e732 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_box.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/
static int32_t fgsBoxSetFocus(FAPI_SYS_HandleT h, fbool_t hasFocus);
static int32_t fgsBoxShow    (FAPI_SYS_HandleT h);
static int32_t fgsBoxHide    (FAPI_SYS_HandleT h);
static int32_t fgsBoxClose   (FAPI_SYS_HandleT h);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FGS_BOX_INIT_S*    boxGlobal  = NULL;
static FGS_BOX_DRAWIF_S*  boxDraw    = NULL;

/*---------------------------------------------------------------------------*/
/* API Functions                                                             */
/*---------------------------------------------------------------------------*/

/*!
*************************************************************************
** \brief   This function initialise the FGS Box module.
**
** \param   pInitParams     Initialise parameter for FGS Box module
**
** \return  One of the following status codes:
**          - #FAPI_OK if FGS Box module was initialised succesfully
**          - #SMARTGO_FGS_ERR_BAD_PARAMETER
**          - #SMARTGO_FGS_ERR_OUT_OF_MEMORY
**
*************************************************************************/
int32_t FGS_BOX_Init (FGS_BOX_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    boxGlobal = FGS_Malloc(sizeof(FGS_BOX_INIT_S));
    if ( boxGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }
    (*boxGlobal) = (*pInitParams);
    boxDraw      = &(boxGlobal->draw);

    return FAPI_OK;
}

/*!
*************************************************************************
** \brief   This function opens a FGS Box item.
**
** \param   pData    Open parameter for the FGS Box item.
** \param   id       The FGS box item identyfier.
** \param   parent   The parent FGS panel item.
** \param   ph       A pointer to store the FGS Box item handle.
**
** \return  One of the following status codes:
**          - #FAPI_OK in case the FGS Box item was opened successfully.
**          - #SMARTGO_FGS_ERR_BAD_PARAMETER
**          - #SMARTGO_FGS_ERR_OUT_OF_MEMORY
**
** \sa
**          - fgsBoxClose()
**          - FGS_PANEL_AddMember()
**
*************************************************************************/
int32_t FGS_BOX_Open (FGS_BOX_OPEN_S* pData, int32_t id,
                      FAPI_SYS_HandleT parent,
                      FAPI_SYS_HandleT* ph)
{
    FGS_BOX_INST_S*     inst;
    FGS_PANEL_MEMBER_S  member;
    int32_t             retVal;
    fbool_t             memAllocated = FFALSE;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }
    if ( pData->pInst != NULL )
    {
        inst = pData->pInst;
    }
    else
    {
        inst = FGS_Malloc(sizeof(FGS_BOX_INST_S));
        if ( inst == NULL )
        {
            return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
        }
        memAllocated = FTRUE;
    }

    memset(inst, 0, sizeof(FGS_BOX_INST_S));

    inst->memAllocated = memAllocated;
    inst->data         = *pData;
    inst->pMem         = NULL;
    inst->pPanel       = (FGS_PANEL_INST_S*)parent;

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as panel member */

    memset(&member, 0, sizeof(FGS_PANEL_MEMBER_S));

    member.h         = (FAPI_SYS_HandleT)inst;
    member.pos       = &(inst->data.pos);
    member.id        = id;
    member.isHidden  = inst->data.isHidden;
    member.setFocus  = fgsBoxSetFocus;
    member.show      = fgsBoxShow;
    member.hide      = fgsBoxHide;
    member.close     = fgsBoxClose;

    retVal = FGS_PANEL_AddMember(parent, &member, &(inst->pMem));
    if ( (retVal             != FAPI_OK) &&
         (inst->memAllocated == FTRUE) )
    {
        FGS_Free(inst);
    }

    return retVal;
}


/*!
*************************************************************************
** \brief   This function removes the item content and set the box content type
**          to FGS_ITEM_TYPE_NONE
**
** \param   h       The FGS Box handle
**
** \return  One of the following status codes:
**          - #FAPI_OK
**
*************************************************************************/
int32_t FGS_BOX_Clear (FAPI_SYS_HandleT h)
{
    FGS_BOX_INST_S* inst   = (FGS_BOX_INST_S*)h;
    uint8_t         cnt;

    if ( inst->data.getItem == NULL )
    {
        for ( cnt = 0; cnt < FGS_BOX_IDX_MAX; cnt++ )
        {
            inst->data.item[cnt].type = FGS_ITEM_TYPE_NONE;
        }

        /* redraw item if currently visible */
        if ( inst->pMem->isVisible )
        {
            (void)FGS_PANEL_RefreshMember((FAPI_SYS_HandleT)inst->pPanel, inst->pMem->id);
        }
    }

    return FAPI_OK;
}

/*!
*************************************************************************
** \brief   This function is deprecated, to be removed!!!
**
** \attention deprecated, to be removed !!!
**
** \param   h       The FGS Box handle
** \param   pItem   ---
**
** \return  One of the following status codes:
**          - #FAPI_OK
**          - #SMARTGO_FGS_ERR_BAD_PARAMETER
**
*************************************************************************/
int32_t FGS_BOX_SetNonFocusItem (FAPI_SYS_HandleT h, FGS_ITEM_S* pItem)
{
    FGS_BOX_INST_S* inst   = (FGS_BOX_INST_S*)h;
    uint8_t         idx    = FGS_BOX_IDX_NONFOCUS;

    if ( (h     == NULL) ||
         (pItem == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    if ( inst->data.getItem == NULL )
    {
        inst->data.item[idx] = *pItem;

        /* redraw item if currently visible */
        if (    inst->pMem->isVisible &&
             (!(inst->pMem->hasFocus)) )
        {
            (void)FGS_PANEL_RefreshMember((FAPI_SYS_HandleT)inst->pPanel, inst->pMem->id);
        }
    }

    return FAPI_OK;
}

/*!
*************************************************************************
** \brief   This function is deprecated, to be removed!!!
**
** \attention deprecated, to be removed !!!
**
** \param   h       The FGS Box handle
** \param   pItem   ---
**
** \return  One of the following status codes:
**          - #FAPI_OK
**          - #SMARTGO_FGS_ERR_BAD_PARAMETER
**
*************************************************************************/
int32_t FGS_BOX_SetFocusItem (FAPI_SYS_HandleT h, FGS_ITEM_S* pItem)
{
    FGS_BOX_INST_S* inst   = (FGS_BOX_INST_S*)h;
    uint8_t         idx    = FGS_BOX_IDX_FOCUS;

    if ( (h     == NULL) ||
         (pItem == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    if ( inst->data.getItem == NULL )
    {
        inst->data.item[idx] = *pItem;

        /* redraw item if currently visible */
        if ( inst->pMem->isVisible &&
             inst->pMem->hasFocus )
        {
            (void)FGS_PANEL_RefreshMember((FAPI_SYS_HandleT)inst->pPanel, inst->pMem->id);
        }
    }

    return FAPI_OK;
}


/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/


/*!
*************************************************************************
** \brief   This function closes a previously opend FGS Box item.
**
** \param   h   The FGS Box handle.
**
** \return  One of the following status codes:
**          - #FAPI_OK
**          - #SMARTGO_FGS_ERR_INVALID_HANDLE
**
** \sa
**          - FGS BOX_Open()
**
*************************************************************************/
static int32_t fgsBoxClose (FAPI_SYS_HandleT h)
{
    FGS_BOX_INST_S*  inst = (FGS_BOX_INST_S*)h;

    if (inst == NULL)
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    if ( inst->memAllocated == FTRUE )
    {
        FGS_Free(inst);
    }

    return FAPI_OK;
}

/*!
*************************************************************************
** \brief   This function show a previously opened FGS Box item.
**
** \param   h   The FGS Box handle.
**
** \return  One of the following status codes:
**          - #FAPI_OK (allways)
**
** \sa
**          - FGS BOX_Open()
**
*************************************************************************/
static int32_t fgsBoxShow (FAPI_SYS_HandleT h)
{
    FGS_BOX_INST_S*   inst = (FGS_BOX_INST_S*)h;
    FGS_ITEM_S        item;
    FGS_ITEMSTATE_E   state;

    memset(&item, 0, sizeof(item));
    item.type = FGS_ITEM_TYPE_NONE;

    if ( inst->data.getItem != NULL )
    {
        if ( inst->pMem->hasFocus )
        {
            state = FGS_FOCUS;
        }
        else
        {
            state = FGS_NONFOCUS;
        }

        inst->data.getItem (inst->data.getItemArg,
                             inst->pMem->id, 0, state, &item);
    }
    else // deprecated, to be removed!
    {
        if ( !(inst->pMem->hasFocus) )
        {
            item = inst->data.item[FGS_BOX_IDX_NONFOCUS];
        }
        else
        {
            item = inst->data.item[FGS_BOX_IDX_FOCUS];
        }
    }

    if ( boxDraw->drawBkgr != NULL )
    {
        boxDraw->drawBkgr(h, inst->pPanel);
    }

    /* draw value item */
    if ( item.type != FGS_ITEM_TYPE_NONE )
    {
        (void)FGS_DrawItem (&item, inst->pMem->abspos.x,
                             inst->pMem->abspos.y,
                             inst->data.pos.width,
                             inst->data.pos.height);
    }

    return FAPI_OK;
}

/*!
*************************************************************************
** \brief   This function Hide a previously shown FGS Box item.
**
** \note    function is currently doing nothing !!!
**
** \param   h   The FGS Box handle.
**
** \return  One of the following status codes:
**          - #FAPI_OK (allways)
**
** \sa
**          - FGS BOX_Show()
**
*************************************************************************/
static int32_t fgsBoxHide (FAPI_SYS_HandleT h)
{
    //FGS_BOX_INST_S*   inst = (FGS_BOX_INST_S*)h;

    return FAPI_OK;
}

static int32_t fgsBoxSetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_BOX_INST_S* inst   = (FGS_BOX_INST_S*)h;

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible )
    {
        (void)FGS_PANEL_RefreshMember((FAPI_SYS_HandleT)inst->pPanel, inst->pMem->id);
    }

    return FAPI_OK;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
