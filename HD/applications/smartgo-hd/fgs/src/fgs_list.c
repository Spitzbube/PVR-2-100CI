/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_list.c
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
** - Info    713: Loss of precision (assignment) (unsigned int to short).
** - Info    732: Loss of sign (assignment) (int to unsigned short).
** - Info    737: Loss of sign in promotion from int to unsigned int.
** - Info    778: Constant expression evaluates to 0 in operation.
** - Note    961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**                C's operator precedence.
**
*****************************************************************************
*/
/*lint -save -e641 -e713 -e715 -e732 -e737 -e778 -e961 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_list.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

static int32_t FGS_LIST_SetFocus       (FAPI_SYS_HandleT h, fbool_t hasFocus);
static fbool_t FGS_LIST_ItemDeactivate (FGS_LIST_INST_S* inst, fbool_t keepChanges);
static fbool_t FGS_LIST_NextItem       (FGS_LIST_INST_S* inst, fbool_t keepChanges);
static fbool_t FGS_LIST_PreviousItem   (FGS_LIST_INST_S* inst, fbool_t keepChanges);


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

#define FGS_LIST_FindMember(a, id)                                      \
        (a) = 0;                                                        \
        do                                                              \
        {                                                               \
            while ( (a) < inst->numMembers )                            \
            {                                                           \
                if ( inst->member[(a)].id == id )                       \
                {                                                       \
                    break;                                              \
                }                                                       \
                (a)++;                                                  \
            }                                                           \
                                                                        \
            if ( (a) >= inst->numMembers ) return SMARTGO_FGS_ERR_BAD_PARAMETER; \
        }                                                               \
        while ( 0 )


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_LIST_INIT_S*   fgsListGlobal    = NULL;
static FGS_LIST_DRAWIF_S* fgsListDraw  = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_LIST_Close  (FAPI_SYS_HandleT h);
static int32_t  FGS_LIST_Show   (FAPI_SYS_HandleT h);
static int32_t  FGS_LIST_Hide   (FAPI_SYS_HandleT h);

int32_t FGS_LIST_Init (FGS_LIST_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsListGlobal = FGS_Malloc(sizeof(FGS_LIST_INIT_S));
    if ( fgsListGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsListGlobal) = (*pInitParams);

    fgsListDraw = &(fgsListGlobal->draw);

    return FAPI_OK;
}

int32_t FGS_LIST_Open (FGS_LIST_OPEN_S* pData, int32_t id,
                       FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph)
{
    FGS_LIST_INST_S*    inst;
    FGS_PANEL_MEMBER_S  member;
    int32_t             retVal;
    fbool_t             memAllocated = FFALSE;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( pData->pInst != NULL )
    {
        inst = pData->pInst;
    }
    else
    {
        inst = FGS_Malloc(sizeof(FGS_LIST_INST_S));
        if ( inst == NULL )
        {
            return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
        }

        memAllocated = FTRUE;
    }

    memset(inst, 0, sizeof(FGS_LIST_INST_S));

    inst->memAllocated     = memAllocated;
    inst->data             = *pData;
    inst->pMem             = NULL;
    inst->pPanel           = (FGS_PANEL_INST_S*)parent;
    inst->numMembers       = 0;
    inst->focusIdx         = -1;
    inst->data.autoRefresh = FTRUE; /* always start with auto-refresh enabled*/

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as panel member */

    memset(&member, 0, sizeof(FGS_PANEL_MEMBER_S));

    member.h         = (FAPI_SYS_HandleT)inst;
    member.pos       = &(inst->data.pos);
    member.id        = id;
    member.isHidden  = inst->data.isHidden;
    member.setFocus  = FGS_LIST_SetFocus;
    member.show      = FGS_LIST_Show;
    member.hide      = FGS_LIST_Hide;
    member.close     = FGS_LIST_Close;

    retVal = FGS_PANEL_AddMember(parent, &member, &(inst->pMem));

    if ( (retVal             != FAPI_OK) &&
         (inst->memAllocated == FTRUE) )
    {
        FGS_Free(inst);
    }

    return retVal;
}

static int32_t FGS_LIST_Close (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst = (FGS_LIST_INST_S*)h;
    uint16_t              cnt  = 0;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( inst->pMem->hasFocus )
    {
        /* clear key handlers if necessary */
        FGS_ClearAllHandlers();
    }

    /* close all members */
    while ( cnt < inst->numMembers )
    {
        if ( inst->member[cnt].close != NULL )
        {
            (void)inst->member[cnt].close(inst->member[cnt].h);
        }
        cnt++;
    }

    if ( inst->memAllocated == FTRUE )
    {
        FGS_Free(inst);
    }

    return FAPI_OK;
}

int32_t FGS_LIST_AddMember (FAPI_SYS_HandleT h, FGS_LIST_MEMBER_S* pMember,
                         FGS_LIST_MEMBER_S** pId)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    FGS_LIST_MEMBER_S*  pMem;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( inst->numMembers >= FGS_LIST_MEMBERS_MAX )
    {
        return SMARTGO_FGS_ERR_RESOURCES;
    }

    /* to do: adjust positions of description and value in case of not
       fitting into item rectangle! */

    /* choose position to add member to */
    pMem  = inst->member + inst->numMembers;

    *pMem = *pMember; /* store member data */
    *pId  = pMem;     /* provide pointer to data to member */

    /* calculate member's absolute position */
    FGS_CalculateAbsPos (pMem, inst->pMem->abspos, inst->pMem->pos, 1, 1);
    pMem->posChg    = FFALSE;
    pMem->pParent   = &(inst->data); /* provide pointer on list instance data */
    pMem->pPanel    = inst->pPanel;
    pMem->isEnabled = FTRUE;

    /* if list is currently visible, draw new member */
    if ( inst->pMem->isVisible )
    {
        pMem->isVisible = FTRUE;
        (void)pMem->draw(pMem->h);
    }
    else
    {
        pMem->isVisible = FFALSE;
    }

    inst->numMembers++;

    return FAPI_OK;
}

static int32_t FGS_LIST_Show (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S*   inst = (FGS_LIST_INST_S*)h;
    FGS_LIST_MEMBER_S* pMem;
    uint16_t                cnt;

    /* re-calculate member positions if change in positioning has been
       notified */
    if ( inst->pMem->posChg )
    {
        for ( cnt = 0; cnt < inst->numMembers; cnt++ )
        {
            pMem = inst->member + cnt;

            /* calculate member's absolute position */
            FGS_CalculateAbsPos (pMem, inst->pMem->abspos, inst->pMem->pos,
                                 1, 1);
            pMem->posChg   = FTRUE;
        }

        inst->pMem->posChg = FFALSE;
    }

    /* draw list background */
    if ( fgsListDraw->drawBkgr != NULL )
    {
        fgsListDraw->drawBkgr(h, inst->pMem->abspos.x,
                                 inst->pMem->abspos.y,
                                 inst->data.pos.width,
                                 inst->data.pos.height);
    }

    /* draw all members */
    for ( cnt = 0; cnt < inst->numMembers; cnt++ )
    {
        inst->member[cnt].isVisible = FTRUE;
        (void)inst->member[cnt].draw(inst->member[cnt].h);
    }

    return FAPI_OK;
}

static int32_t FGS_LIST_Hide (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S*   inst = (FGS_LIST_INST_S*)h;
    uint16_t                cnt;

    /* update visibility status of all members */
    for ( cnt = 0; cnt < inst->numMembers; cnt++ )
    {
        inst->member[cnt].isVisible = FFALSE;
    }

    return FAPI_OK;
}

int32_t FGS_LIST_SetRefreshMode (FAPI_SYS_HandleT h, fbool_t autoRefresh)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;

    inst->data.autoRefresh = autoRefresh;
    return FAPI_OK;
}

int32_t FGS_LIST_SetMemberFocus (FAPI_SYS_HandleT h, int32_t id)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    FGS_LIST_MEMBER_S*  pMember;
    int32_t             retVal;
    uint16_t            newFocus;

    FGS_LIST_FindMember(newFocus, id);

    /* ensure that member to be focussed is enabled */
    if ( inst->member[newFocus].isEnabled == FFALSE )
    {
        return SMARTGO_FGS_ERR_PROHIBITED;
    }

    /* remove old focus */
    if ( inst->focusIdx >= 0 )
    {
        pMember = &(inst->member[inst->focusIdx]);

        retVal = pMember->setFocus(pMember->h, FFALSE);
        if ( retVal != FAPI_OK )
        {
            return retVal;
        }
    }

    /* set new focus */
    pMember = &(inst->member[newFocus]);

    retVal = pMember->setFocus(pMember->h, FTRUE);

    if ( retVal == FAPI_OK )
    {
        /* notify change of focus if requested */
        if ( inst->data.onFocusChg != NULL )
        {
            inst->data.onFocusChg(inst->data.onFocusChgArg,
                                  (uint8_t)newFocus,
                                  inst->member[newFocus].id);
        }
    }

    inst->focusIdx = newFocus;

    return FAPI_OK;
}

/* Set focus to first non-disabled list member, returns selected ID on
   success. */
int32_t FGS_LIST_SetMemberFocusAuto (FAPI_SYS_HandleT h, int32_t* id)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    FGS_LIST_MEMBER_S*  pMember;
    int32_t             retVal;
    uint8_t             newFocus = 0;

    while ( newFocus < inst->numMembers )
    {
        if ( inst->member[newFocus].isEnabled  )
        {
            break;
        }

        newFocus++;
    }

    if ( newFocus == inst->numMembers )
    {
        return SMARTGO_FGS_ERR_PROHIBITED;
    }

    /* remove old focus */
    if ( inst->focusIdx >= 0 )
    {
        pMember = &(inst->member[inst->focusIdx]);

        retVal = pMember->setFocus(pMember->h, FFALSE);
        if ( retVal != FAPI_OK )
        {
            return retVal;
        }
    }

    /* set new focus */
    pMember = &(inst->member[newFocus]);

    retVal = pMember->setFocus(pMember->h, FTRUE);

    if ( retVal == FAPI_OK )
    {
        /* notify change of focus if requested */
        if ( inst->data.onFocusChg != NULL )
        {
            inst->data.onFocusChg(inst->data.onFocusChgArg, newFocus,
                                  inst->member[newFocus].id);
        }
    }

    inst->focusIdx = newFocus;

    if ( id != NULL )
    {
        *id = inst->member[newFocus].id;
    }

    return FAPI_OK;
}

int32_t FGS_LIST_GetMemberFocusID (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;

    if ( inst->focusIdx < 0 ) return -1;
    else                      return inst->member[inst->focusIdx].id;
}

int32_t FGS_LIST_SetMemberParams (FAPI_SYS_HandleT h, int32_t id, const void* params)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    int32_t                retVal;
    uint16_t                 cnt;

    FGS_LIST_FindMember(cnt, id);

    if ( inst->member[cnt].setParams != NULL )
    {
        retVal = inst->member[cnt].setParams(inst->member[cnt].h, params);
    }
    else
    {
        retVal = SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    return retVal;
}

int32_t FGS_LIST_GetMemberParams (FAPI_SYS_HandleT h, int32_t id, void* params)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    int32_t                retVal;
    uint16_t                 cnt;

    FGS_LIST_FindMember(cnt, id);

    if ( inst->member[cnt].getParams != NULL )
    {
        retVal = inst->member[cnt].getParams(inst->member[cnt].h, params);
    }
    else
    {
        retVal = SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    return retVal;
}

int32_t FGS_LIST_GetMemberAbsPos (FAPI_SYS_HandleT h, int32_t id, FGS_LOC_S* loc)
{
    FGS_LIST_INST_S*    inst   = (FGS_LIST_INST_S*)h;
    int32_t                retVal = FAPI_OK;
    uint16_t                 cnt;

    FGS_LIST_FindMember(cnt, id);

    // TODO: hier Neuberechnung falls posChg == FTRUE ?

    *loc = inst->member[cnt].abspos;
    return retVal;
}

int32_t FGS_LIST_SetMemberEnableStatus (FAPI_SYS_HandleT h, int32_t id,
                                        fbool_t enabled)
{
    FGS_LIST_INST_S*    inst    = (FGS_LIST_INST_S*)h;
    FGS_LIST_MEMBER_S*  pMember = NULL;
    int32_t             retVal  = FAPI_OK;
    uint16_t            cnt;

    FGS_LIST_FindMember(cnt, id);

    pMember = inst->member + cnt;

    if ( pMember->isEnabled != enabled )
    {
        pMember->isEnabled = enabled;

        /* If currently focussed list item is disabled, select
           another item automatically. */
        if ( (!enabled) && (inst->focusIdx == cnt) )
        {
            if ( !(FGS_LIST_PreviousItem (inst, FFALSE)) )
            {
                (void)FGS_LIST_NextItem (inst, FFALSE);
            }
        }

        /* redraw if item is visible */
        if ( (pMember->isVisible     == FTRUE) &&
             (inst->data.autoRefresh == FTRUE) )(void)pMember->draw(pMember->h);
    }

    return retVal;
}

int32_t FGS_LIST_GetMemberEnableStatus (FAPI_SYS_HandleT h, int32_t id, fbool_t* enabled)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    uint16_t                 cnt;

    FGS_LIST_FindMember(cnt, id);

    *enabled = inst->member[cnt].isEnabled;
    return FAPI_OK;
}


uint8_t FGS_LIST_GetNumOfMembers (FAPI_SYS_HandleT h)
{
    return ((FGS_LIST_INST_S*)h)->numMembers;
}

int32_t  FGS_LIST_RefreshMember (FAPI_SYS_HandleT h, int32_t id)
{
    FGS_LIST_INST_S*    inst = (FGS_LIST_INST_S*)h;
    uint16_t                 cnt;

    FGS_LIST_FindMember(cnt, id);

    return inst->member[cnt].draw(inst->member[cnt].h);
}

fbool_t FGS_LIST_Up (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;
    fbool_t          retVal = FFALSE;

    if ( (!(inst->pMem->isVisible)) ||
         (inst->focusIdx < 0) ) return FFALSE;

    /* pass to member */
    if ( (inst->member[inst->focusIdx].isEnabled == FTRUE) &&
         (inst->member[inst->focusIdx].up        != NULL) )
    {
        retVal = inst->member[inst->focusIdx].up
                (inst->member[inst->focusIdx].h);
    }

    /* if unused by member, move to previous member */
    if ( (retVal == FFALSE) &&
         (inst->data.topDownOriented == FTRUE) )
    {
        retVal = FGS_LIST_PreviousItem(inst, FTRUE);
    }

    return retVal;
}

fbool_t FGS_LIST_Down (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;
    fbool_t          retVal = FFALSE;

    if ( (!(inst->pMem->isVisible)) ||
         (inst->focusIdx < 0) ) return FFALSE;

    /* pass to member */
    if ( (inst->member[inst->focusIdx].isEnabled == FTRUE) &&
         (inst->member[inst->focusIdx].down      != NULL) )
    {
        retVal = inst->member[inst->focusIdx].down
                (inst->member[inst->focusIdx].h);
    }

    /* if unused by member, move to next member */
    if ( (retVal == FFALSE) &&
         (inst->data.topDownOriented == FTRUE) )
    {
        retVal = FGS_LIST_NextItem(inst, FTRUE);
    }

    return retVal;
}

fbool_t FGS_LIST_Left (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;
    fbool_t          retVal = FFALSE;

    if ( (!(inst->pMem->isVisible)) ||
         (inst->focusIdx < 0) ) return FFALSE;

    /* pass to member */
    if ( (inst->member[inst->focusIdx].isEnabled == FTRUE) &&
         (inst->member[inst->focusIdx].left      != NULL) )
    {
        retVal = inst->member[inst->focusIdx].left
                (inst->member[inst->focusIdx].h);
    }

    /* if unused by member, move to previous member */
    if ( (retVal == FFALSE) &&
         (inst->data.topDownOriented == FFALSE) )
    {
        retVal = FGS_LIST_PreviousItem(inst, FTRUE);
    }

    return retVal;
}

fbool_t FGS_LIST_Right (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;
    fbool_t          retVal = FFALSE;

    if ( (!(inst->pMem->isVisible)) ||
         (inst->focusIdx < 0) ) return FFALSE;

    /* pass to member */
    if ( (inst->member[inst->focusIdx].isEnabled == FTRUE) &&
         (inst->member[inst->focusIdx].right     != NULL) )
    {
        retVal = inst->member[inst->focusIdx].right
                (inst->member[inst->focusIdx].h);
    }

    /* if unused by member, move to next member */
    if ( (retVal == FFALSE) &&
         (inst->data.topDownOriented == FFALSE) )
    {
        retVal = FGS_LIST_NextItem(inst, FTRUE);
    }

    return retVal;
}

fbool_t FGS_LIST_Number (FAPI_SYS_HandleT h, uint8_t value)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;
    fbool_t          retVal = FFALSE;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ||
         (inst->focusIdx         < 0) ) return FFALSE;

    if ( inst->member[inst->focusIdx].isEnabled == FTRUE )
    {
        /* attempt to activate if not already active */
        if ( (inst->member[inst->focusIdx].activate    != NULL)  &&
             (inst->member[inst->focusIdx].isActivated == FFALSE) )
        {
            if ( inst->member[inst->focusIdx].activate
                (inst->member[inst->focusIdx].h) == FAPI_OK )
            {
                retVal = FTRUE;
            }
        }

        if ( (inst->member[inst->focusIdx].number != NULL) &&
             (inst->member[inst->focusIdx].number
             (inst->member[inst->focusIdx].h, value) == FTRUE) )
        {
            retVal = FTRUE;
        }
    }

    return retVal;
}

fbool_t FGS_LIST_Ok (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ||
         (inst->focusIdx         < 0) ) return FFALSE;

    if ( inst->member[inst->focusIdx].isEnabled == FTRUE )
    {
        /* test if handling for OK button is registered */
        if ( inst->member[inst->focusIdx].ok != NULL )
        {
            return inst->member[inst->focusIdx].ok
                  (inst->member[inst->focusIdx].h);
        }

        /* submit and deactivate if currently active */
        else if ( inst->member[inst->focusIdx].isActivated == FTRUE )
        {
            return FGS_LIST_ItemDeactivate(inst, FTRUE);
        }
        /* activate if not active */
        else if ( inst->member[inst->focusIdx].activate != NULL )
        {
            if ( inst->member[inst->focusIdx].activate
                (inst->member[inst->focusIdx].h) == FAPI_OK )
            {
                return FTRUE;
            }
        }
        else if ( inst->data.onSelect != NULL )
        {
            return inst->data.onSelect (inst->data.onSelectArg,
                                        inst->member[inst->focusIdx].id);
        }
    }

    return FFALSE;
}

fbool_t FGS_LIST_Back (FAPI_SYS_HandleT h)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ||
         (inst->focusIdx         < 0) ) return FFALSE;

    if ( (inst->member[inst->focusIdx].isEnabled   == FTRUE) &&
         (inst->member[inst->focusIdx].isActivated == FTRUE) &&
         (inst->member[inst->focusIdx].deactivate  != NULL) )
    {
        if ( inst->member[inst->focusIdx].deactivate
            (inst->member[inst->focusIdx].h, FFALSE) == FAPI_OK )
        {
            return FTRUE;
        }
    }

    return FFALSE;
}

void FGS_LIST_DrawItemDescr (FGS_LIST_MEMBER_S* pMem)
{
    FGS_ITEM_S      descrItem;
    FGS_ITEMSTATE_E state;

    if ( pMem->pParent->getDescrItem == NULL ) return;

    memset(&descrItem, 0, sizeof(descrItem));

    descrItem.type = FGS_ITEM_TYPE_NONE;

    if      ( !(pMem->isEnabled) ) state = FGS_DISABLED;
    else if ( pMem->hasFocus )     state = FGS_FOCUS;
    else                           state = FGS_NONFOCUS;

    pMem->pParent->getDescrItem(pMem->pParent->getDescrItemArg,
                                pMem->id, 0, state, &descrItem);

    (void)FGS_DrawItem (&descrItem,
                  (uint16_t)(pMem->abspos.x + pMem->descrPos.x),
                  (uint16_t)(pMem->abspos.y + pMem->descrPos.y),
                  pMem->descrPos.width,
                  pMem->descrPos.height);
}

static int32_t FGS_LIST_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_LIST_INST_S* inst   = (FGS_LIST_INST_S*)h;

    /* call lists's focus-set handler if available */
    if (  inst->pMem->isVisible &&
         (inst->data.onFocusSet != NULL) )
    {
        inst->data.onFocusSet(inst->data.onFocusSetArg, hasFocus);
    }

    /* set/remove focus on list member */
    if ( inst->focusIdx >= 0 )
    {
        (void)inst->member[inst->focusIdx].setFocus(
                                                inst->member[inst->focusIdx].h,
                                                hasFocus);

        /* notify change of focus if requested */
        if ( hasFocus &&
            (inst->data.onFocusChg != NULL) )
        {
            inst->data.onFocusChg(inst->data.onFocusChgArg,
                                  (uint8_t)inst->focusIdx,
                                  inst->member[inst->focusIdx].id);
        }
    }

    /* install/release GUI key handlers */
    if ( hasFocus )
    {
        FGS_SetKeyHandler   (FGS_KEY_UP,     FGS_LIST_Up,       h, FFALSE);
        FGS_SetKeyHandler   (FGS_KEY_DOWN,   FGS_LIST_Down,     h, FFALSE);
        FGS_SetKeyHandler   (FGS_KEY_LEFT,   FGS_LIST_Left,     h, FFALSE);
        FGS_SetKeyHandler   (FGS_KEY_RIGHT,  FGS_LIST_Right,    h, FFALSE);
        FGS_SetKeyHandler   (FGS_KEY_OK,     FGS_LIST_Ok,       h, FTRUE);
        FGS_SetKeyHandler   (FGS_KEY_BACK,   FGS_LIST_Back,     h, FTRUE);
        FGS_SetNumKeyHandler(FGS_KEY_NUMBER, FGS_LIST_Number,   h, FTRUE);
    }
    else
    {
        FGS_ClearAllHandlers();
    }

    return FAPI_OK;
}

static fbool_t FGS_LIST_ItemDeactivate (FGS_LIST_INST_S* inst,
                                         fbool_t keepChanges)
{
    if ( (inst->member[inst->focusIdx].isActivated == FTRUE) &&
         (inst->member[inst->focusIdx].deactivate  != NULL) )
    {
        if ( inst->member[inst->focusIdx].deactivate
            (inst->member[inst->focusIdx].h, keepChanges) == FAPI_OK )
        {
            return FTRUE;
        }
    }

    return FFALSE;
}

static fbool_t FGS_LIST_NextItem (FGS_LIST_INST_S* inst, fbool_t keepChanges)
{
    int32_t nextIdx = -1;
    int32_t idxCnt  = inst->focusIdx;

    if ( inst->numMembers < 1 ) return FFALSE;

    /* ----- search for next item to be focussed --------------------------- */

    do
    {
        idxCnt++; /* proceed by one step */

        /* test for wraparound condition */
        if ( idxCnt >= (int32_t)inst->numMembers )
        {
            if ( inst->data.wraparound == FTRUE )
            {
                idxCnt = 0;
            }
            else
            {
                break;
            }
        }

        if ( idxCnt == inst->focusIdx ) break; /* end of loop */

        /* only enabled items may be focussed */
        if ( inst->member[idxCnt].isEnabled == FTRUE )
        {
            nextIdx = idxCnt;
        }
    }
    while ( nextIdx < 0 );

    if ( nextIdx < 0 ) return FFALSE;

    /* --------------------------------------------------------------------- */

    /* deactivate current item if necessary */
    (void)FGS_LIST_ItemDeactivate(inst, keepChanges);

    /* remove focus from current item */
    (void)inst->member[inst->focusIdx].setFocus (inst->member[inst->focusIdx].
                                                 h, FFALSE);

    /* set new focus */
    inst->focusIdx = nextIdx;
    (void)inst->member[inst->focusIdx].setFocus (inst->member[inst->focusIdx].
                                                 h, FTRUE);

    /* notify change of focus if requested */
    if ( inst->data.onFocusChg != NULL )
    {
        inst->data.onFocusChg(inst->data.onFocusChgArg,
                              (uint8_t)inst->focusIdx,
                              inst->member[inst->focusIdx].id);
    }

    return FTRUE;
}

static fbool_t FGS_LIST_PreviousItem (FGS_LIST_INST_S* inst, fbool_t keepChanges)
{
    int32_t nextIdx = -1;
    int32_t idxCnt  = inst->focusIdx;

    if ( inst->numMembers < 1 ) return FFALSE;

    /* ----- search for "previous" item to be focussed --------------------- */

    do
    {
        idxCnt--; /* proceed by one step */

        /* test for wraparound condition */
        if ( idxCnt < 0 )
        {
            if ( inst->data.wraparound == FTRUE )
            {
                idxCnt = (int32_t)inst->numMembers - 1;
            }
            else
            {
                break;
            }
        }

        if ( idxCnt == inst->focusIdx ) break; /* end of loop */

        /* only enabled items may be focussed */
        if ( inst->member[idxCnt].isEnabled == FTRUE )
        {
            nextIdx = idxCnt;
        }
    }
    while ( nextIdx < 0 );

    if ( nextIdx < 0 ) return FFALSE;

    /* --------------------------------------------------------------------- */

    /* deactivate current item if necessary */
    (void)FGS_LIST_ItemDeactivate(inst, keepChanges);

    /* remove focus from current item */
    (void)inst->member[inst->focusIdx].setFocus(inst->member[inst->focusIdx].
                                          h, FFALSE);

    /* set new focus */
    inst->focusIdx = nextIdx;
    (void)inst->member[inst->focusIdx].setFocus(inst->member[inst->focusIdx].
                                          h, FTRUE);

    /* notify change of focus if requested */
    if ( inst->data.onFocusChg != NULL )
    {
        inst->data.onFocusChg(inst->data.onFocusChgArg,
                              (uint8_t)inst->focusIdx,
                              inst->member[inst->focusIdx].id);
    }

    return FTRUE;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
