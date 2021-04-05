/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_navilist.c
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
** - Info    715: Symbol not referenced.
** - Info    732: Loss of sign (assignment) (int to unsigned short).
** - Info    737: Loss of sign in promotion from int to unsigned int.
** - Note    961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**                C's operator precedence.
**
*****************************************************************************
*/
/*lint -save -e713 -e715 -e732 -e737 -e961 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_navilist.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_LNAVI_SetFocus     (FAPI_SYS_HandleT h, fbool_t hasFocus);
static fbool_t  FGS_LNAVI_Select       (FAPI_SYS_HandleT h);
static void     FGS_LNAVI_IntSetParams (FGS_LNAVI_INST_S* inst,
                                        const FGS_LNAVI_PARAMS_S* params);

static fbool_t typeCenterUp           (FGS_LNAVI_INST_S* inst);
static fbool_t typeCenterDown         (FGS_LNAVI_INST_S* inst);
static fbool_t typeCenterPageUp       (FGS_LNAVI_INST_S* inst);
static fbool_t typeCenterPageDown     (FGS_LNAVI_INST_S* inst);
static void    typeCenterDrawAll      (FGS_LNAVI_INST_S* inst);
static void    typeCenterDrawLine     (FGS_LNAVI_INST_S* inst, uint16_t index);
static int16_t typeCenterGetLineIndex (FGS_LNAVI_INST_S* inst, uint16_t listIdx);

static fbool_t typeScrollUp           (FGS_LNAVI_INST_S* inst);
static fbool_t typeScrollDown         (FGS_LNAVI_INST_S* inst);
static fbool_t typeScrollPageUp       (FGS_LNAVI_INST_S* inst);
static fbool_t typeScrollPageDown     (FGS_LNAVI_INST_S* inst);
static void    typeScrollDrawAll      (FGS_LNAVI_INST_S* inst);
static void    typeScrollDrawLine     (FGS_LNAVI_INST_S* inst, uint16_t index);

static fbool_t typeTxtViewUp          (FGS_LNAVI_INST_S* inst);
static fbool_t typeTxtViewDown        (FGS_LNAVI_INST_S* inst);
static fbool_t typeTxtViewPageUp      (FGS_LNAVI_INST_S* inst);
static fbool_t typeTxtViewPageDown    (FGS_LNAVI_INST_S* inst);
static void    typeTxtViewDrawAll     (FGS_LNAVI_INST_S* inst);
static void    typeTxtViewDrawLine    (FGS_LNAVI_INST_S* inst, uint16_t index);

static void    paintScrollbar         (FGS_LNAVI_INST_S* inst);

static /* FINLINE */ void  paintScrollLine  (FGS_LNAVI_INST_S* inst, uint16_t lineIndex);


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_LNAVI_INIT_S*   fgsLnaviGlobal    = NULL;
static FGS_LNAVI_DRAWIF_S* fgsLnaviDraw = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

static int32_t  FGS_LNAVI_Close   (FAPI_SYS_HandleT h);
static int32_t  FGS_LNAVI_Show    (FAPI_SYS_HandleT h);
static int32_t  FGS_LNAVI_Hide    (FAPI_SYS_HandleT h);


/* 21baea48 - complete */
int32_t FGS_LNAVI_Init (FGS_LNAVI_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsLnaviGlobal = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_LNAVI_INIT_S));
    if ( fgsLnaviGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsLnaviGlobal) = (*pInitParams);

    fgsLnaviDraw = &(fgsLnaviGlobal->draw);

    return FAPI_OK;
}


/* 21baea9c - complete */
int32_t FGS_LNAVI_Open (FGS_LNAVI_OPEN_S* pData, int32_t id, FAPI_SYS_HandleT parent,
                     FAPI_SYS_HandleT* ph)
{
    FGS_LNAVI_INST_S*   inst;
    FGS_PANEL_MEMBER_S  member;
    int32_t             retVal;
    uint16_t            cnt;
    uint16_t            lineWidth;
    fbool_t             memAllocated = FFALSE;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( pData->numColumns > FGS_LNAVI_COL_MAX ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if ( pData->pInst != NULL )
    {
        inst = pData->pInst;
    }
    else
    {
        inst = /*FGS_Malloc*/SYS_MemoryAllocate(sizeof(FGS_LNAVI_INST_S));
        if ( inst == NULL )
        {
            return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
        }

        memAllocated = FTRUE;
    }

    memset(inst, 0, sizeof(FGS_LNAVI_INST_S));

    inst->memAllocated = memAllocated;
    inst->data         = *pData;
    inst->pMem         = NULL;
    inst->pPanel       = (FGS_PANEL_INST_S*)parent;
    inst->autoRefresh  = FTRUE;

    /* adjust parameters */
    FGS_LNAVI_IntSetParams(inst, &(inst->data.params));

    switch ( inst->data.type )
    {
        case FGS_LNAVI_TYPE_FIXEDPOS:
            inst->up          = typeCenterUp;
            inst->down        = typeCenterDown;
            inst->pageUp      = typeCenterPageUp;
            inst->pageDown    = typeCenterPageDown;
            inst->drawAll     = typeCenterDrawAll;
            inst->drawLine    = typeCenterDrawLine;
            break;

        case FGS_LNAVI_TYPE_SCROLL:
            inst->up          = typeScrollUp;
            inst->down        = typeScrollDown;
            inst->pageUp      = typeScrollPageUp;
            inst->pageDown    = typeScrollPageDown;
            inst->drawAll     = typeScrollDrawAll;
            inst->drawLine    = typeScrollDrawLine;
            break;

        case FGS_LNAVI_TYPE_TXTVIEW:
            inst->up          = typeTxtViewUp;
            inst->down        = typeTxtViewDown;
            inst->pageUp      = typeTxtViewPageUp;
            inst->pageDown    = typeTxtViewPageDown;
            inst->drawAll     = typeTxtViewDrawAll;
            inst->drawLine    = typeTxtViewDrawLine;
            break;

        default:
            if ( inst->memAllocated == FTRUE )
            {
                /*FGS_Free*/SYS_MemoryFree(inst);
            }
            return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    if ( inst->data.numColumns == 0 ) inst->data.numColumns = 1;

    if ( inst->data.scrollbarWidth > inst->data.pos.width )
    {
        inst->data.scrollbarWidth = inst->data.pos.width;
    }

    /* ----- check column dimensions --------------------------------------- */

    switch ( inst->data.type )
    {
        case FGS_LNAVI_TYPE_SCROLL:
        case FGS_LNAVI_TYPE_TXTVIEW:
            lineWidth = inst->data.pos.width - inst->data.scrollbarWidth;
            break;

        default:
            lineWidth = inst->data.pos.width;
            break;
    }

    for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
    {
        /* check column start position */
        if ( inst->data.colStart[cnt] >= lineWidth )
        {
            inst->data.colStart[cnt] = (uint16_t)(lineWidth - 1);
        }

        /* check if:
           - column width exceeds total width
           - column width is 0 -> calculate automatically to maximum size */

        if ( ((uint16_t)(inst->data.colStart[cnt] +
                   inst->data.colWidth[cnt]) > lineWidth) ||
             (inst->data.colWidth[cnt] == 0) )
        {
            inst->data.colWidth[cnt] = lineWidth -
                                       inst->data.colStart[cnt];
        }
    }

    *ph = (FAPI_SYS_HandleT)inst;

    /* add as panel member */

    memset(&member, 0, sizeof(FGS_PANEL_MEMBER_S));

    member.h         = (FAPI_SYS_HandleT)inst;
    member.pos       = &(inst->data.pos);
    member.id        = id;
    member.isHidden  = inst->data.isHidden;
    member.setFocus  = FGS_LNAVI_SetFocus;
    member.show      = FGS_LNAVI_Show;
    member.hide      = FGS_LNAVI_Hide;
    member.close     = FGS_LNAVI_Close;

    retVal = FGS_PANEL_AddMember(parent, &member, &(inst->pMem));

    if ( (retVal             != FAPI_OK) &&
         (inst->memAllocated == FTRUE) )
    {
        /*FGS_Free*/SYS_MemoryFree(inst);
    }

    return retVal;
}


/* 21bae9ec - complete */
static int32_t FGS_LNAVI_Close (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S* inst = (FGS_LNAVI_INST_S*)h;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( inst->pMem->hasFocus )
    {
        /* clear key handlers if necessary */
        FGS_ClearAllHandlers();
    }

    if ( inst->memAllocated == FTRUE )
    {
        /*FGS_Free*/SYS_MemoryFree(inst);
    }

    return FAPI_OK;
}


/* 21bad3bc - complete */
static int32_t FGS_LNAVI_Show (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    if ( inst->drawAll != NULL ) inst->drawAll(inst);

    return FAPI_OK;
}


/* 21bad3d8 - complete */
static int32_t FGS_LNAVI_Hide (FAPI_SYS_HandleT h)
{
    //FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    /* nothing to do... */

    return FAPI_OK;
}


/* 21bad3e0 - complete */
fbool_t FGS_LNAVI_Up (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ) return FFALSE;

    if      ( inst->up       == NULL )   return FFALSE;
    else if ( inst->up(inst) == FFALSE ) return FFALSE;

    /* notify change of focus if requested */
    if ( inst->data.onFocusChg != NULL )
    {
        inst->data.onFocusChg(inst->data.onFocusChgArg,
                              inst->pMem->id,
                              inst->data.params.index);
    }

    return FTRUE;
}


/* 21bad44c - complete */
fbool_t FGS_LNAVI_Down (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ) return FFALSE;

    if      ( inst->down       == NULL )   return FFALSE;
    else if ( inst->down(inst) == FFALSE ) return FFALSE;

    /* notify change of focus if requested */
    if ( inst->data.onFocusChg != NULL )
    {
        inst->data.onFocusChg(inst->data.onFocusChgArg,
                              inst->pMem->id,
                              inst->data.params.index);
    }

    return FTRUE;
}


/* 21bad4b8 - complete */
fbool_t FGS_LNAVI_PageUp (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ) return FFALSE;

    if      ( inst->pageUp       == NULL )   return FFALSE;
    else if ( inst->pageUp(inst) == FFALSE ) return FFALSE;

    /* notify change of focus if requested */
    if ( inst->data.onFocusChg != NULL )
    {
        inst->data.onFocusChg(inst->data.onFocusChgArg,
                              inst->pMem->id,
                              inst->data.params.index);
    }

    return FTRUE;
}

/* 21bad524 - complete */
fbool_t FGS_LNAVI_PageDown (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    if ( (inst->pMem->hasFocus  == FFALSE) ||
         (inst->pMem->isVisible == FFALSE) ) return FFALSE;

    if      ( inst->pageDown       == NULL )   return FFALSE;
    else if ( inst->pageDown(inst) == FFALSE ) return FFALSE;

    /* notify change of focus if requested */
    if ( inst->data.onFocusChg != NULL )
    {
        inst->data.onFocusChg(inst->data.onFocusChgArg,
                              inst->pMem->id,
                              inst->data.params.index);
    }

    return FTRUE;
}


/* 21bae96c - todo */
int32_t FGS_LNAVI_SetParams (FAPI_SYS_HandleT h, const FGS_LNAVI_PARAMS_S* params)
{
    FGS_LNAVI_INST_S* inst = (FGS_LNAVI_INST_S*)h;

    if ( inst   == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;
    if ( params == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    FGS_LNAVI_IntSetParams(inst, params);

    /* redraw list if currently visible */
    if ( inst->pMem->isVisible && inst->autoRefresh )
    {
        (void)FGS_PANEL_RefreshMember((FAPI_SYS_HandleT)(inst->pPanel), inst->pMem->id);

        /* notify change of focus if requested */
        if ( inst->data.onFocusChg != NULL )
        {
            inst->data.onFocusChg(inst->data.onFocusChgArg,
                                  inst->pMem->id,
                                  inst->data.params.index);
        }
    }

    return FAPI_OK;
}


/* 21bad590 - complete */
int32_t FGS_LNAVI_GetParams (FAPI_SYS_HandleT h, FGS_LNAVI_PARAMS_S* params)
{
    FGS_LNAVI_INST_S* inst = (FGS_LNAVI_INST_S*)h;

    if ( inst   == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;
    if ( params == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    *params = inst->data.params;

    return FAPI_OK;
}

int32_t  FGS_LNAVI_SetRefreshMode (FAPI_SYS_HandleT h, fbool_t autoRefresh)
{
    FGS_LNAVI_INST_S* inst   = (FGS_LNAVI_INST_S*)h;

    inst->autoRefresh = autoRefresh;
    return FAPI_OK;
}

/* ------------------------------------------------------------------------- */

/* 21bae81c - complete */
static int32_t FGS_LNAVI_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_LNAVI_INST_S* inst   = (FGS_LNAVI_INST_S*)h;

    /* call lists's focus-set handler if available */
    if ( (inst->pMem->isVisible == FTRUE) &&
         (inst->data.onFocusSet != NULL) )
    {
        inst->data.onFocusSet(inst->data.onFocusSetArg, hasFocus);
    }

    /* redraw currently focussed line if visible */
    if ( (inst->pMem->isVisible == FTRUE) &&
         (inst->drawLine        != NULL) )
    {
        inst->drawLine(inst, inst->data.params.index);
    }

    /* install/release GUI key handlers */
    if ( hasFocus )
    {
        FGS_SetKeyHandler       (FGS_KEY_OK,     FGS_LNAVI_Select,   h, FTRUE);

        if ( inst->data.topDownOrient == FTRUE )
        {
            FGS_SetKeyHandler   (FGS_KEY_UP,     FGS_LNAVI_Up,       h, FFALSE);
            FGS_SetKeyHandler   (FGS_KEY_DOWN,   FGS_LNAVI_Down,     h, FFALSE);
            FGS_SetKeyHandler   (FGS_KEY_LEFT,   FGS_LNAVI_PageUp,   h, FFALSE);
            FGS_SetKeyHandler   (FGS_KEY_RIGHT,  FGS_LNAVI_PageDown, h, FFALSE);
        }
        else
        {
            FGS_SetKeyHandler   (FGS_KEY_UP,     FGS_LNAVI_Down,     h, FFALSE);
            FGS_SetKeyHandler   (FGS_KEY_DOWN,   FGS_LNAVI_Up,       h, FFALSE);
            FGS_SetKeyHandler   (FGS_KEY_LEFT,   FGS_LNAVI_PageDown, h, FFALSE);
            FGS_SetKeyHandler   (FGS_KEY_RIGHT,  FGS_LNAVI_PageUp,   h, FFALSE);
        }
    }
    else
    {
        FGS_ClearAllHandlers();
    }

    return FAPI_OK;
}


/* 21bad5d8 - complete */
static fbool_t FGS_LNAVI_Select (FAPI_SYS_HandleT h)
{
    FGS_LNAVI_INST_S*  inst = (FGS_LNAVI_INST_S*)h;

    if ( (!(inst->pMem->hasFocus)) ||
         (!(inst->pMem->isVisible)) ) return FFALSE;

    if ( inst->data.onSelect != NULL )
    {
        inst->data.onSelect(inst->data.onSelectArg,
                            inst->pMem->id,
                            inst->data.params.index);
        return FTRUE;
    }
    else
    {
        return FFALSE;
    }
}


/* 21bad624 - complete */
static void FGS_LNAVI_IntSetParams (FGS_LNAVI_INST_S* inst,
                                    const FGS_LNAVI_PARAMS_S* params)
{
    inst->data.params = *params;

    /* --------------------------------------------------------------------- */

    if ( inst->data.params.numItems == 0 )
    {
        inst->data.params.index = 0;

        if ( inst->data.type != FGS_LNAVI_TYPE_FIXEDPOS )
        {
            inst->data.params.posInVis = 0;
        }
    }
    else
    {
        /* ----- Adjust focus index ---------------------------------------- */

        /* index out of list area ? */
        if ( inst->data.params.index >= inst->data.params.numItems )
        {
            inst->data.params.index = inst->data.params.numItems - 1;
        }

        /* ----- Adjust focus position in visible area --------------------- */

        if ( inst->data.type != FGS_LNAVI_TYPE_FIXEDPOS )
        {
            /* posInVis greater than list index ? */
            if ( inst->data.params.posInVis > inst->data.params.index )
            {
                inst->data.params.posInVis = inst->data.params.index;
            }
            else if ( (inst->data.params.index    < inst->data.numVisLines) &&
                      (inst->data.params.posInVis < inst->data.params.index) )
            {
                inst->data.params.posInVis = inst->data.params.index;
            }
        }

        /* posInVis out of visible area ? */
        if ( (inst->data.numVisLines     >  0) &&
             (inst->data.params.posInVis >= inst->data.numVisLines) )
        {
            inst->data.params.posInVis = inst->data.numVisLines - 1;
        }

        /* posInVis out of number of items ? */
        if ( (inst->data.params.numItems <  inst->data.numVisLines) &&
             (inst->data.params.posInVis >= inst->data.params.numItems) )
        {
            inst->data.params.posInVis = inst->data.params.numItems - 1;
        }
    }
}

/* ------------------------------------------------------------------------- */

static fbool_t typeCenterUp (FGS_LNAVI_INST_S* inst)
{
    if ( inst->data.params.index < 1 )
         inst->data.params.index = inst->data.params.numItems - 1;
    else inst->data.params.index--;

    typeCenterDrawAll(inst);
    return FTRUE;
}

static fbool_t typeCenterDown (FGS_LNAVI_INST_S* inst)
{
    inst->data.params.index++;
    if ( inst->data.params.index >= inst->data.params.numItems )
    {
        inst->data.params.index = 0;
    }

    typeCenterDrawAll(inst);
    return FTRUE;
}

static fbool_t typeCenterPageUp (FGS_LNAVI_INST_S* inst)
{
    if ( inst->data.params.index < inst->data.numVisLines )
    {
        inst->data.params.index = inst->data.params.index +
                                  inst->data.params.numItems -
                                  inst->data.numVisLines;
    }
    else
    {
        inst->data.params.index -= inst->data.numVisLines;
    }

    typeCenterDrawAll(inst);
    return FTRUE;
}

static fbool_t typeCenterPageDown (FGS_LNAVI_INST_S* inst)
{
    inst->data.params.index += inst->data.numVisLines;

    if ( inst->data.params.index >= inst->data.params.numItems )
    {
        inst->data.params.index -= inst->data.params.numItems;
    }

    typeCenterDrawAll(inst);
    return FTRUE;
}

static void typeCenterDrawAll (FGS_LNAVI_INST_S* inst)
{
    uint16_t         y1;
    uint8_t          lineCnt;
    uint16_t         index;
    uint8_t          cnt;
    uint16_t         colX;

    y1 = inst->pMem->abspos.y;

    /* calculate first line's index */
    if ( inst->data.topDownOrient == FTRUE )
    {
        index = inst->data.params.index + inst->data.params.numItems -
                inst->data.params.posInVis;
    }
    else
    {
        index = inst->data.params.index + inst->data.params.posInVis;
    }

    if ( inst->data.params.numItems > 0 )
    {
        while ( index >= inst->data.params.numItems )
        {
            index -= inst->data.params.numItems;
        }
    }

    for ( lineCnt = 0; lineCnt < inst->data.numVisLines; lineCnt++ )
    {
        for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
        {
            memset(inst->pItem + cnt, 0, sizeof(inst->pItem[cnt]));

            inst->pItem[cnt].type = FGS_ITEM_TYPE_NONE;
        }

        if ( inst->data.getItem != NULL )
        {
            /* get string to be printed */
            inst->data.getItem (inst->data.getItemArg, inst->pMem->id, index,
                               (FGS_ITEMSTATE_E)((lineCnt == inst->data.params.posInVis)
                                 ?  FTRUE  :  FFALSE),
                               inst->pItem);
        }

        /* draw current line's background */
        if ( fgsLnaviDraw->drawLineBkgr != NULL )
        {
            fgsLnaviDraw->drawLineBkgr((FAPI_SYS_HandleT)inst,
                                       inst->pPanel,
                                       inst->pMem->abspos.x,
                                       y1,
                                       inst->data.pos.width,
                                       inst->data.rowHeight,
                                       lineCnt, index);
        }

        colX = inst->pMem->abspos.x;

        for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
        {
            if ( inst->pItem[cnt].type != FGS_ITEM_TYPE_NONE )
            {
                (void)FGS_DrawItem (inst->pItem + cnt,
                              colX + inst->data.colStart[cnt], y1,
                              inst->data.colWidth[cnt],
                              inst->data.rowHeight);
            }
        }

        if ( inst->data.topDownOrient == FTRUE )
        {
            index++;
            if ( index >= inst->data.params.numItems ) index = 0;
        }
        else
        {
            if ( index > 0 ) index--;
            else             index = inst->data.params.numItems - 1;
        }

        y1 += inst->data.rowHeight;
    }
}

static void typeCenterDrawLine (FGS_LNAVI_INST_S* inst, uint16_t index)
{
    uint16_t         posY;
    int16_t         lineIdx;
    uint8_t          cnt;
    uint16_t         colX;

    /* calculate index of visible line */
    lineIdx = typeCenterGetLineIndex(inst, index);

    if ( lineIdx < 0 ) return;

    for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
    {
        memset(inst->pItem + cnt, 0, sizeof(inst->pItem[cnt]));

        inst->pItem[cnt].type = FGS_ITEM_TYPE_NONE;
    }

    posY = inst->pMem->abspos.y + (lineIdx * inst->data.rowHeight);

    if ( inst->data.getItem != NULL )
    {
        /* get string to be printed */
        inst->data.getItem (inst->data.getItemArg, inst->pMem->id, index,
                           (FGS_ITEMSTATE_E)((lineIdx == inst->data.params.posInVis)
                                 ? FTRUE : FFALSE),
                           inst->pItem);
    }

    /* draw current line's background */
    if ( fgsLnaviDraw->drawLineBkgr != NULL )
    {
        fgsLnaviDraw->drawLineBkgr((FAPI_SYS_HandleT)inst,
                                   inst->pPanel,
                                   inst->pMem->abspos.x,
                                   posY,
                                   inst->data.pos.width,
                                   inst->data.rowHeight,
                                   lineIdx, index);
    }

    colX = inst->pMem->abspos.x;

    for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
    {
        if ( inst->pItem[cnt].type != FGS_ITEM_TYPE_NONE )
        {
            (void)FGS_DrawItem (inst->pItem + cnt,
                          colX + inst->data.colStart[cnt], posY,
                          inst->data.colWidth[cnt],
                          inst->data.rowHeight);
        }
    }
}

static int16_t typeCenterGetLineIndex (FGS_LNAVI_INST_S* inst, uint16_t listIdx)
{
    int16_t lineIdx = -1;

    if ( listIdx >= inst->data.params.numItems ) return -1;

    if ( inst->data.topDownOrient == FTRUE )
    {
        lineIdx = listIdx - (int16_t)inst->data.params.index +
                  (int16_t)inst->data.params.posInVis;

        if ( lineIdx < 0 ) lineIdx += inst->data.params.numItems;
    }
    else
    {
        lineIdx = (int16_t)inst->data.params.index - listIdx +
                  (int16_t)inst->data.params.posInVis;

        if ( lineIdx >= (int16_t)inst->data.numVisLines )
        {
            lineIdx -= inst->data.params.numItems;
        }
    }

    if ( (lineIdx < 0) ||
         (lineIdx >= (int16_t)inst->data.numVisLines) ) return -1;
    else                                            return lineIdx;
}

/* ------------------------------------------------------------------------- */

static fbool_t typeScrollUp (FGS_LNAVI_INST_S* inst)
{
    fbool_t retVal = FTRUE;

    if ( inst->data.params.index < 1 )
    {
        if ( (!(inst->data.wraparound)) ||
               (inst->data.params.numItems < 1) )
        {
            retVal = FFALSE;
        }
        else
        {
            inst->data.params.index = (uint16_t)(inst->data.params.numItems - 1);

            if ( inst->data.params.index < inst->data.numVisLines )
            {
                inst->data.params.posInVis = inst->data.params.index;
            }
            else if ( inst->data.numVisLines > 0 )
            {
                inst->data.params.posInVis = inst->data.numVisLines - 1;
            }
            else
            {
                inst->data.params.posInVis = 0;
            }

            /* redraw all lines */
            typeScrollDrawAll(inst);
        }
    }
    else
    {
        inst->data.params.index--;
        if ( inst->data.params.posInVis > 0 )
        {
            inst->data.params.posInVis--;

            /* draw only lines that have changed */
            paintScrollLine(inst, inst->data.params.posInVis + 1);
            paintScrollLine(inst, inst->data.params.posInVis);
        }
        else
        {
            /* redraw all lines */
            typeScrollDrawAll(inst);
        }
    }

    return retVal;
}

static fbool_t typeScrollDown (FGS_LNAVI_INST_S* inst)
{
    fbool_t retVal = FTRUE;

    if ( (uint16_t)(inst->data.params.index + 1) >= inst->data.params.numItems )
    {
        if ( (!(inst->data.wraparound)) ||
               (inst->data.params.numItems < 1) )
        {
            retVal = FFALSE;
        }
        else
        {
            inst->data.params.index    = 0;
            inst->data.params.posInVis = 0;

            /* redraw all lines */
            typeScrollDrawAll(inst);
        }
    }
    else
    {
        inst->data.params.index++;

        if ((uint16_t)(inst->data.params.posInVis + 1) < inst->data.numVisLines)
        {
            inst->data.params.posInVis++;

            /* draw only lines that have changed */
            paintScrollLine(inst, inst->data.params.posInVis - 1);
            paintScrollLine(inst, inst->data.params.posInVis);
        }
        else
        {
            /* draw all lines */
            typeScrollDrawAll(inst);
        }
    }

    return retVal;
}

static fbool_t typeScrollPageUp (FGS_LNAVI_INST_S* inst)
{
    uint16_t topIdx;

    if( inst->data.params.numItems < 1 ) return FFALSE;

    if ( !(inst->data.wraparound) )
    {
        /* already on top: do nothing */
        if ( inst->data.params.index < 1 ) return FFALSE;

        /* in top page: jump to top of page */
        else if ( (((uint16_t)(inst->data.params.index -
                          inst->data.params.posInVis) < 1) &&
                    (inst->data.params.index > 0)) ||
                    (inst->data.params.index < inst->data.numVisLines) )
        {
            inst->data.params.index    = 0;
            inst->data.params.posInVis = 0;
        }
        else
        {
            inst->data.params.index -= inst->data.numVisLines;

            if ( inst->data.params.posInVis > inst->data.params.index )
            {
                inst->data.params.posInVis = inst->data.params.index;
            }
        }
    }
    else
    {
        /* in top page? */
        if ( (inst->data.params.index - inst->data.params.posInVis) == 0 )
        {
            /* only one page available: move to top of page */
            if ( inst->data.params.numItems <= inst->data.numVisLines )
            {
                if ( inst->data.params.index > 0 )
                {
                    inst->data.params.index    = 0;
                    inst->data.params.posInVis = 0;
                }
                else
                {
                    return FFALSE;
                }
            }
            /* wraparound to last page */
            else
            {
                topIdx = inst->data.numVisLines *
                         ((uint16_t)(inst->data.params.numItems - 1) /
                         inst->data.numVisLines);

                if ( inst->data.params.posInVis >=
                     (uint16_t)(inst->data.params.numItems - topIdx) )
                {
                    inst->data.params.posInVis = inst->data.params.numItems -
                                                 topIdx - 1;
                }

                inst->data.params.index = topIdx + inst->data.params.posInVis;
            }
        }
        else /* move to previous page */
        {
            if ( (uint16_t)(inst->data.params.index - inst->data.params.posInVis) <
                 inst->data.numVisLines )
            {
                inst->data.params.index    = 0;
                inst->data.params.posInVis = 0;
            }
            else
            {
                inst->data.params.index -= inst->data.numVisLines;
            }
        }
    }

    typeScrollDrawAll(inst);
    return FTRUE;
}

static fbool_t typeScrollPageDown (FGS_LNAVI_INST_S* inst)
{
    uint16_t topIdx;

    if( inst->data.params.numItems < 1 ) return FFALSE;

    if ( !(inst->data.wraparound) )
    {
        /* already at end: do nothing */
        if ( inst->data.params.index >= (uint16_t)(inst->data.params.numItems - 1) )
        {
            return FFALSE;
        }

        /* in bottom page: jump to end of page */
        else if ( (uint16_t)(inst->data.params.index + inst->data.numVisLines) >=
                  inst->data.params.numItems )
        {
            inst->data.params.index = inst->data.params.numItems - 1;

            if ( inst->data.params.numItems >= inst->data.numVisLines )
            {
                inst->data.params.posInVis = inst->data.numVisLines - 1;
            }
            else
            {
                inst->data.params.posInVis = inst->data.params.index;
            }
        }
        else
        {
            inst->data.params.index += inst->data.numVisLines;

            if ( (uint16_t)(inst->data.params.index - inst->data.params.posInVis +
                 inst->data.numVisLines) >= inst->data.params.numItems )
            {
                inst->data.params.posInVis = inst->data.numVisLines -
                                            (inst->data.params.numItems -
                                             inst->data.params.index);
            }
        }
    }
    else
    {
        topIdx = inst->data.params.index - inst->data.params.posInVis;

        /* in last page? */
        if ( (uint16_t)(topIdx + inst->data.numVisLines) >=
             inst->data.params.numItems )
        {
            /* only one page available: move to bottom of page */
            if ( inst->data.params.numItems <= inst->data.numVisLines )
            {
                if ( (uint16_t)(inst->data.params.index + 1) <
                           inst->data.params.numItems )
                {
                    inst->data.params.index    = inst->data.params.numItems - 1;
                    inst->data.params.posInVis = inst->data.params.index -
                                                 topIdx;
                }
                else
                {
                    return FFALSE;
                }
            }
            /* wraparound to first page */
            else
            {
                topIdx = 0;

                if ( inst->data.params.posInVis >= inst->data.params.numItems )
                {
                    inst->data.params.posInVis = (uint16_t)
                                                 (inst->data.params.numItems-1);
                }

                inst->data.params.index = inst->data.params.posInVis;
            }
        }
        else /* move to next page */
        {
            topIdx += inst->data.numVisLines;

            inst->data.params.index += inst->data.numVisLines;

            if ( inst->data.params.index >= inst->data.params.numItems )
            {
                inst->data.params.index = (uint16_t)(inst->data.params.numItems - 1);
            }

            inst->data.params.posInVis = inst->data.params.index - topIdx;
        }
    }

    typeScrollDrawAll(inst);
    return FTRUE;
}

static void typeScrollDrawAll (FGS_LNAVI_INST_S* inst)
{
    uint16_t         lineCnt;

    /* draw lines */
    for ( lineCnt = 0; lineCnt < inst->data.numVisLines; lineCnt++ )
    {
        paintScrollLine(inst, lineCnt);
    }

    paintScrollbar(inst);
}

static void typeScrollDrawLine (FGS_LNAVI_INST_S* inst, uint16_t index)
{
    int16_t lineCnt;

    if ( index >= inst->data.params.numItems ) return;

    lineCnt = (int16_t)index - (int16_t)inst->data.params.index +
              (int16_t)inst->data.params.posInVis;

    if ( (lineCnt < 0) ||
         (lineCnt >= (int16_t)inst->data.numVisLines) ) return;

    paintScrollLine(inst, lineCnt);
}

static /* FINLINE */ void paintScrollLine (FGS_LNAVI_INST_S* inst, uint16_t lineIndex)
{
    uint16_t         y1;
    uint16_t         index;
    uint16_t         lineWidth;
    uint16_t         cnt;
    uint16_t         colX;

    lineWidth = inst->data.pos.width - inst->data.scrollbarWidth;

    index = inst->data.params.index - inst->data.params.posInVis + lineIndex;

    y1    = inst->pMem->abspos.y + (lineIndex * inst->data.rowHeight);

    /* ----- draw lines ----------------------------------------------------- */

    /* draw current line's background */
    if ( fgsLnaviDraw->drawLineBkgr != NULL )
    {
        fgsLnaviDraw->drawLineBkgr((FAPI_SYS_HandleT)inst,
                                   inst->pPanel,
                                   inst->pMem->abspos.x,
                                   y1,
                                   lineWidth,
                                   inst->data.rowHeight,
                                   lineIndex, index);
    }

    if ( index < inst->data.params.numItems )
    {
        for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
        {
            memset(inst->pItem + cnt, 0, sizeof(inst->pItem[cnt]));

            inst->pItem[cnt].type = FGS_ITEM_TYPE_NONE;
        }

        if ( inst->data.getItem != NULL )
        {
            /* get string to be printed */
            inst->data.getItem (inst->data.getItemArg, inst->pMem->id, index,
                                (FGS_ITEMSTATE_E)((index == inst->data.params.posInVis)
                                 ?  FTRUE  :  FFALSE),
                                inst->pItem);
        }

        colX = inst->pMem->abspos.x;

        for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
        {
            if ( inst->pItem[cnt].type != FGS_ITEM_TYPE_NONE )
            {
                (void)FGS_DrawItem (inst->pItem + cnt,
                              colX + inst->data.colStart[cnt], y1,
                              inst->data.colWidth[cnt],
                              inst->data.rowHeight);
            }
        }
    }
}

static void paintScrollbar (FGS_LNAVI_INST_S* inst)
{
    uint16_t         actHeight;
    uint16_t         actPos;

    if ( (inst->data.scrollbarWidth   == 0) ||
         (fgsLnaviDraw->drawScrollbar == NULL) ) return;

    if ( inst->data.scrollHdlHeight > 0 ) /* fixed scroll handle height */
    {
        actHeight = inst->data.scrollHdlHeight;
    }
    else /* automatic calculation of scroll handle height */
    {
        if ( inst->data.params.numItems > inst->data.numVisLines )
        {
            actHeight = (uint32_t)(inst->data.numVisLines * inst->data.pos.height) /
                         inst->data.params.numItems;
        }
        else
        {
            actHeight = inst->data.pos.height;
        }
    }

    if ( actHeight < fgsLnaviGlobal->scrollHdlHeightMin )
    {
        actHeight = fgsLnaviGlobal->scrollHdlHeightMin;
    }

    if ( actHeight > inst->data.pos.height )
    {
        actHeight = inst->data.pos.height;
    }

    if ( inst->data.params.numItems > inst->data.numVisLines )
    {
        actPos =
             (uint32_t)((uint16_t)(inst->data.params.index - inst->data.params.posInVis) *
                   (uint16_t)(inst->data.pos.height - actHeight)) /
              (inst->data.params.numItems - inst->data.numVisLines);
    }
    else
    {
        actPos = 0;
    }

    if ( (uint16_t)(actPos + actHeight) > inst->data.pos.height )
    {
        actPos = inst->data.pos.height - actHeight;
    }

    fgsLnaviDraw->drawScrollbar((FAPI_SYS_HandleT)inst,
                                inst->pPanel,
                                inst->pMem->abspos.x + inst->data.pos.width -
                                inst->data.scrollbarWidth,
                                inst->pMem->abspos.y,
                                inst->data.scrollbarWidth,
                                inst->data.pos.height,
                                actPos, actHeight);
}

/* ------------------------------------------------------------------------- */

static fbool_t typeTxtViewUp (FGS_LNAVI_INST_S* inst)
{
     if ( inst->data.params.index < 1 ) return FFALSE;
     else
     {
         inst->data.params.index--;
     }

     typeTxtViewDrawAll(inst);
     return FTRUE;
}

static fbool_t typeTxtViewDown (FGS_LNAVI_INST_S* inst)
{
    if ( (uint16_t)(inst->data.params.index + inst->data.numVisLines + 1) >
         inst->data.params.numItems ) return FFALSE;
    else
    {
        inst->data.params.index++;
    }

    typeTxtViewDrawAll(inst);
    return FTRUE;
}

static fbool_t typeTxtViewPageUp (FGS_LNAVI_INST_S* inst)
{
    if ( inst->data.params.index < inst->data.numVisLines )
    {
        inst->data.params.index = 0;
    }
    else
    {
        inst->data.params.index -= inst->data.numVisLines;
    }

    typeTxtViewDrawAll(inst);
    return FTRUE;
}

static fbool_t typeTxtViewPageDown (FGS_LNAVI_INST_S* inst)
{
    if ( inst->data.numVisLines >= inst->data.params.numItems )
    {
        inst->data.params.index = 0;
    }
    else
    {
        inst->data.params.index += inst->data.numVisLines;
        if ( (uint16_t)(inst->data.params.index + inst->data.numVisLines) >
              inst->data.params.numItems )
        {
            inst->data.params.index = inst->data.params.numItems -
                                      inst->data.numVisLines;
        }
    }

    typeTxtViewDrawAll(inst);
    return FTRUE;
}

static void typeTxtViewDrawAll (FGS_LNAVI_INST_S* inst)
{
    uint16_t         y1;
    uint16_t         lineCnt;
    uint16_t         index;
    uint16_t         lineWidth;
    uint16_t         cnt;
    uint16_t         colX;

    lineWidth = inst->data.pos.width - inst->data.scrollbarWidth;

    y1 = inst->pMem->abspos.y;

    index = inst->data.params.index;

    /* ----- draw lines ----------------------------------------------------- */

    for ( lineCnt = 0; lineCnt < inst->data.numVisLines; lineCnt++ )
    {
        /* draw current line's background */
        if ( fgsLnaviDraw->drawLineBkgr != NULL )
        {
            fgsLnaviDraw->drawLineBkgr((FAPI_SYS_HandleT)inst,
                                       inst->pPanel,
                                       inst->pMem->abspos.x,
                                       y1,
                                       lineWidth,
                                       inst->data.rowHeight,
                                       lineCnt, index);
        }

        if ( index < inst->data.params.numItems )
        {
            for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
            {
                memset(inst->pItem + cnt, 0, sizeof(inst->pItem[cnt]));

                inst->pItem[cnt].type = FGS_ITEM_TYPE_NONE;
            }

            if ( inst->data.getItem != NULL )
            {
                /* get string to be printed */
                inst->data.getItem (inst->data.getItemArg, inst->pMem->id,
                                    index, (FGS_ITEMSTATE_E)0, inst->pItem);
            }
            colX = inst->pMem->abspos.x;

            for ( cnt = 0; cnt < inst->data.numColumns; cnt++ )
            {
                if ( inst->pItem[cnt].type != FGS_ITEM_TYPE_NONE )
                {
                    (void)FGS_DrawItem (inst->pItem + cnt,
                                  colX + inst->data.colStart[cnt], y1,
                                  inst->data.colWidth[cnt],
                                  inst->data.rowHeight);
                }
            }
        }

        index++;
        y1 += inst->data.rowHeight;
    }

    paintScrollbar(inst);
}

static void typeTxtViewDrawLine (FGS_LNAVI_INST_S* inst, uint16_t index)
{
    // not implemented!
    return;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
