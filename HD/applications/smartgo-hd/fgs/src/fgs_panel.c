/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_panel.c
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
** - Info    737: Loss of sign in promotion from int to unsigned int.
** - Info    778: Constant expression evaluates to 0 in operation.
** - Note    961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**                C's operator precedence.
**
*****************************************************************************
*/
/*lint -save -e713 -e737 -e778 -e961 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_panel.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_PANEL_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_PANEL_INIT_S*   fgsPanelGlobal    = NULL; //21f02fdc
/*static*/ FGS_PANEL_DRAWIF_S* fgsPanelDraw = NULL; //21f02fe0

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/


/*static*/ FGS_PANEL_MEMBER_S* FGS_PANEL_SearchMember (FGS_PANEL_INST_S* inst,
                                                   int32_t id);


/* 21baf78c - complete */
int32_t FGS_PANEL_Init (FGS_PANEL_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsPanelGlobal = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_PANEL_INIT_S));
    if ( fgsPanelGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsPanelGlobal) = (*pInitParams);

    fgsPanelDraw = &(fgsPanelGlobal->draw);

    return FAPI_OK;
}


/* 21baf7e4 - complete */
int32_t FGS_PANEL_Open (FGS_PANEL_OPEN_S* pData, int32_t id, FAPI_SYS_HandleT* ph)
{
    FGS_PANEL_INST_S* inst;
    FGS_MEMBER_S      member;
    int32_t           retVal;
    fbool_t           memAllocated = FFALSE;

    if ( (pData == NULL) ||
         (ph    == NULL) ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( pData->pInst != NULL )
    {
        inst = pData->pInst;
    }
    else
    {
        inst = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_PANEL_INST_S));
        if ( inst == NULL )
        {
            return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
        }

        memAllocated = FTRUE;
    }

    memset(inst, 0, sizeof(FGS_PANEL_INST_S));

    inst->memAllocated = memAllocated;
    inst->data         = *pData;
    inst->hasFocus     = FFALSE;
    inst->pMem         = NULL;
    inst->numMembers   = 0;
    inst->focusIdx     = -1;
    inst->autoRefresh  = FTRUE;

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as root panel member */

    memset(&member, 0, sizeof(FGS_MEMBER_S));

    member.h         = (FAPI_SYS_HandleT)inst;
    member.pos       = &(inst->data.pos);
    member.id        = id;
    member.isVisible = FFALSE;
    member.inFront   = pData->inFront;
    member.setFocus  = FGS_PANEL_SetFocus; //osd_window_set_handler
    member.show      = FGS_PANEL_Show;
    member.hide      = FGS_PANEL_Hide;
    member.close     = FGS_PANEL_Close; //osd_window_destroy
    member.refresh   = FGS_PANEL_Refresh;

    retVal = FGS_AddMember(&member, &(inst->pMem));

    if ( (retVal             != FAPI_OK) &&
         (inst->memAllocated == FTRUE) )
    {
        /*FGS_Free*/SYS_MemoryFree(inst);
    }

    return retVal;
}


/* 21baf6fc - complete */
int32_t FGS_PANEL_Close (FAPI_SYS_HandleT h)
{
    FGS_PANEL_INST_S* inst = (FGS_PANEL_INST_S*)h;
    uint16_t               cnt  = 0;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    /* hide panel and all members */
    (void)FGS_PANEL_Hide(h);

    /* remove panel focus */
    (void)FGS_PANEL_SetFocus(h, FFALSE);

    /* close all members */
    while ( cnt < inst->numMembers )
    {
        if ( inst->member[cnt].close != NULL )
        {
            (void)inst->member[cnt].close(inst->member[cnt].h);
        }
        cnt++;
    }

    /* remove from root panel */
    (void)FGS_RemoveMember(inst->pMem);

    if ( inst->memAllocated == FTRUE)
    {
        /*FGS_Free*/SYS_MemoryFree(inst);
    }

    return FAPI_OK;
}


/* 21baf14c - complete */
int32_t FGS_PANEL_AddMember (FAPI_SYS_HandleT h, FGS_PANEL_MEMBER_S* pMember,
                          FGS_PANEL_MEMBER_S** pId)
{
    FGS_PANEL_INST_S*   inst = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMem;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( inst->numMembers >= FGS_PANEL_MEMBERS_MAX )
    {
        return SMARTGO_FGS_ERR_RESOURCES;
    }

    pMem  = inst->member + inst->numMembers;
    *pMem = *pMember;
    *pId  = pMem;

    pMem->isVisible = FFALSE;
    pMem->hasFocus  = FFALSE;

    /* calculate member's absolute position */
    FGS_CalculateAbsPos (pMem, inst->pMem->abspos, inst->pMem->pos, 1, 1);
    pMem->posChg   = FFALSE;

    /* if panel is currently visible, show new member also */
    if ( (inst->pMem->isVisible) &&
         (!(pMem->isHidden))     &&
         (inst->autoRefresh) )
    {
        if ( FGS_GetOverlapStatus(inst->pMem, &(pMem->abspos),
                                  pMem->pos->width,
                                  pMem->pos->height) == FFALSE )
        {
            (void)pMem->show(pMem->h);
            pMem->isVisible = FTRUE;
        }
    }

    inst->numMembers++;

    return FAPI_OK;
}


/* 21baf3d8 - complete */
int32_t FGS_PANEL_Show (FAPI_SYS_HandleT h, fbool_t force)
{
    FGS_PANEL_INST_S*   inst = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMem;
    uint16_t                 cnt;

    if ( (inst->pMem->isVisible == FTRUE) &&
         (force                 == FFALSE) )
    {
        return FAPI_OK;
    }

    /* re-calculate member positions if change in positioning has been
       notified */
    if ( inst->pMem->posChg == FTRUE )
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

    /* draw panel background */
    fgsPanelDraw->draw(h);

    /* show all non-hidden members */
    for ( cnt = 0; cnt < inst->numMembers; cnt++ )
    {
        if ( inst->member[cnt].isHidden ) continue;

        (void)inst->member[cnt].show(inst->member[cnt].h);
        inst->member[cnt].isVisible = FTRUE;
    }

    inst->pMem->isVisible = FTRUE;

    /* refresh panels on top of current panel */
    (void)FGS_HandleMemberShow(inst->pMem);

    return FAPI_OK;
}


/* 21baf35c - complete */
int32_t FGS_PANEL_Hide (FAPI_SYS_HandleT h)
{
    FGS_PANEL_INST_S* inst = (FGS_PANEL_INST_S*)h;
    uint16_t               cnt;

    if ( !(inst->pMem->isVisible) ) return FAPI_OK;

    inst->pMem->isVisible = FFALSE;

    /* hide all members */
    for ( cnt = 0; cnt < inst->numMembers; cnt++ )
    {
        if ( inst->member[cnt].hide != NULL )
        {
            (void)inst->member[cnt].hide(inst->member[cnt].h);
            inst->member[cnt].isVisible = FFALSE;
        }
    }

    /* handle OSD refresh */
    (void)FGS_HandleMemberHide(inst->pMem);

    return FAPI_OK;
}

#if 0

int32_t FGS_PANEL_SetRefreshMode (FAPI_SYS_HandleT h, fbool_t autoRefresh)
{
    FGS_PANEL_INST_S* inst = (FGS_PANEL_INST_S*)h;

    inst->autoRefresh = autoRefresh;
    return FAPI_OK;
}

#endif

/*!
*******************************************************************************
**
** \brief  Refresh a panel or an area on a panel.
**
** \param  h               Panel handle.
** \param  area            Area relative to panel position and size, set to
**                         NULL for refreshing the panel completely.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
******************************************************************************/
/* 21baedbc - complete */
int32_t FGS_PANEL_Refresh (FAPI_SYS_HandleT h, FGS_POS_S* area)
{
    FGS_PANEL_INST_S*   inst = (FGS_PANEL_INST_S*)h;
    uint16_t                 cnt;

    if ( inst->pMem->isVisible == FFALSE ) return FAPI_OK;

    /* draw panel background */
    fgsPanelDraw->refresh(h, area);

    /* refresh all non-hidden members */
    // to do: refresh only overlapping members!!
    for ( cnt = 0; cnt < inst->numMembers; cnt++ )
    {
        if ( inst->member[cnt].isHidden ) continue;

        (void)inst->member[cnt].show(inst->member[cnt].h);
        inst->member[cnt].isVisible = FTRUE;
    }

    return FAPI_OK;
}

#if 0

fbool_t FGS_PANEL_IsVisible (FAPI_SYS_HandleT h)
{
    return ((FGS_PANEL_INST_S*)h)->pMem->isVisible;
}

/* ------------------------------------------------------------------------ */

#endif

/* 21baee54 - complete */
static int32_t FGS_PANEL_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_PANEL_INST_S* inst = (FGS_PANEL_INST_S*)h;

    if ( inst->hasFocus == hasFocus ) return FAPI_OK;

    inst->hasFocus = hasFocus;

    /* call panel's focus-set handler if available */
    if ( inst->data.onFocusSet != NULL )
    {
        inst->data.onFocusSet(inst->data.onFocusSetArg, hasFocus);
    }

    /* set/remove focus on panel member */
    if ( (inst->focusIdx >= 0) &&
         (inst->member[inst->focusIdx].hasFocus != hasFocus) )
    {
        inst->member[inst->focusIdx].hasFocus = hasFocus;

        (void)inst->member[inst->focusIdx].setFocus(inst->member[inst->focusIdx].h,
                                              hasFocus);
    }

    return FAPI_OK;
}


/* 21baeec4 - complete */
int32_t FGS_PANEL_SetMemberFocus (FAPI_SYS_HandleT h, int32_t id)
{
    FGS_PANEL_INST_S*   inst = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMember;
    uint16_t                 newFocus = 0;

    /* search for designated focus member */
    while ( newFocus < inst->numMembers )
    {
        if ( inst->member[newFocus].id == id )
        {
            /* requested id has been found*/
            break;
        }
        newFocus++;
    }

    if ( newFocus >= inst->numMembers ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( inst->member[newFocus].setFocus == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( inst->focusIdx == newFocus ) return FAPI_OK;

    if ( inst->hasFocus )
    {
        /* remove old focus */
        if ( inst->focusIdx >= 0 )
        {
            pMember = &(inst->member[inst->focusIdx]);

            pMember->hasFocus = FFALSE;
            (void)pMember->setFocus(pMember->h, FFALSE);
        }

        /* set new focus */
        pMember = &(inst->member[newFocus]);

        pMember->hasFocus = FTRUE;
        (void)pMember->setFocus(pMember->h, FTRUE);
    }

    inst->focusIdx = newFocus;

    return FAPI_OK;
}

#if 0

int32_t FGS_PANEL_GetMemberFocusID (FAPI_SYS_HandleT h)
{
    FGS_PANEL_INST_S* inst = (FGS_PANEL_INST_S*)h;

    if ( inst->focusIdx < 0 ) return -1;
    else                      return inst->member[inst->focusIdx].id;
}

int32_t FGS_PANEL_SetMemberHideStatus (FAPI_SYS_HandleT h, int32_t id, fbool_t isHidden)
{
    FGS_PANEL_INST_S*   inst    = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMember;

    pMember = FGS_PANEL_SearchMember(inst, id);
    if ( pMember == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( pMember->isHidden == isHidden ) return FAPI_OK;

    pMember->isHidden = isHidden;

    if ( inst->pMem->isVisible )
    {
        if ( isHidden ) /* hide member */
        {
            if ( pMember->hide != NULL )
            {
                (void)pMember->hide(pMember->h);
            }

            pMember->isVisible = FFALSE;

            /* refresh panel */
            if ( inst->autoRefresh )
            {
                (void)FGS_PANEL_Show(h, FTRUE);
            }
        }
        else /* show member */
        {
            if ( inst->autoRefresh )
            {
                (void)pMember->show(pMember->h);
                pMember->isVisible = FTRUE;
            }
        }
    }

    return FAPI_OK;
}

int32_t FGS_PANEL_GetMemberHideStatus (FAPI_SYS_HandleT h, int32_t id, fbool_t* isHidden)
{
    FGS_PANEL_INST_S*   inst    = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMember;

    pMember = FGS_PANEL_SearchMember(inst, id);
    if ( pMember == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    *isHidden = pMember->isHidden;
    return FAPI_OK;
}

int32_t FGS_PANEL_GetMemberAbsPos (FAPI_SYS_HandleT h, int32_t id, FGS_LOC_S* abspos)
{
    FGS_PANEL_INST_S*   inst    = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMember;

    pMember = FGS_PANEL_SearchMember(inst, id);
    if ( pMember == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    // TODO: recalculate absolute position?

    *abspos = pMember->abspos;

    return FAPI_OK;
}

#endif

/* 21baf0d0 - complete */
int32_t FGS_PANEL_RefreshMember (FAPI_SYS_HandleT h, int32_t id)
{
    FGS_PANEL_INST_S*   inst = (FGS_PANEL_INST_S*)h;
    FGS_PANEL_MEMBER_S* pMember;

    if ( !(inst->pMem->isVisible) ) return FAPI_OK;

    pMember = FGS_PANEL_SearchMember(inst, id);
    if ( pMember == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    /* Refresh member if not currently overlapped */
    if ( (!(pMember->isHidden)) &&
         (FGS_GetOverlapStatus(inst->pMem, &(pMember->abspos),
                              pMember->pos->width,
                              pMember->pos->height) == FFALSE) )
    {
        (void)pMember->show(pMember->h);
        pMember->isVisible = FTRUE;
    }

    return FAPI_OK;
}

#if 0

int32_t FGS_PANEL_GetPosition (FAPI_SYS_HandleT h, FGS_POS_S* pos)
{
    FGS_PANEL_INST_S*   inst = (FGS_PANEL_INST_S*)h;

    if ( inst == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    *pos = inst->data.pos;
    return FAPI_OK;
}

#endif

/* 21baf000 - complete */
/*static*/ FGS_PANEL_MEMBER_S* FGS_PANEL_SearchMember (FGS_PANEL_INST_S* inst,
                                                   int32_t id)
{
    uint16_t            cnt = 0;
    FGS_PANEL_MEMBER_S* pMember;

    /* search member */
    while ( cnt < inst->numMembers )
    {
        pMember = inst->member + cnt;

        /* requested id has been found*/
        if ( pMember->id == id ) return pMember;

        cnt++;
    }

    return NULL;
}


/******************************************************************************/
/*lint -restore */
/* END OF FILE */
