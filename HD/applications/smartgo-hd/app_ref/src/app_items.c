/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_items.c
**
** \brief       Application-specific OSD menu items.
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
** - Warning 641: Converting enum 'anyEnum' to int.
** - Info 713: Loss of precision (assignment) (unsigned int to short).
** - Info 715: Symbol not referenced.
** - Info 737: Loss of sign in promotion from int to unsigned int.
** - Note 961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**   C's operator precedence.
**
*****************************************************************************
*/
/*lint -save -e641 -e713 -e715 -e737 -e961 */
#define DEBUG 0

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "app_menu.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

/* NOTE: when designing menu panels care must be taken not to use these uniqe
         IDs. */

#if 0

enum
{
    MENU_VOLUMEBAR_ID_TITLE = 0,
    MENU_VOLUMEBAR_ID_BAR
};

enum
{
    MAIN_MSGBOX_ID_TEXT = 0
};

enum
{
    MENU_PINDIALOG_ID_TITLE = 0,
    MENU_PINDIALOG_ID_DIGIT        // first PIN digit
    /* leave space here for other digits */
};


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

FSTATIC int32_t MAIN_SignalBoxDraw       (FAPI_SYS_HandleT h);
#endif

FSTATIC fbool_t MENU_SelectListClose     (FAPI_SYS_HandleT h,
                                          fbool_t force);
FSTATIC void    MENU_SelectListOnFocusSet(FAPI_SYS_HandleT h,
                                          fbool_t hasFocus);
FSTATIC fbool_t MENU_SelectListKeys      (FAPI_SYS_HandleT h);
FSTATIC void    MENU_SelectListOnSelect  (FAPI_SYS_HandleT h,
                                          int32_t id,
                                          uint16_t index);

#if 0
FSTATIC int32_t MAIN_VolumeBarDraw       (FAPI_SYS_HandleT h);
FSTATIC fbool_t MAIN_VolumeBarClose      (FAPI_SYS_HandleT h,
                                          fbool_t force);

FSTATIC fbool_t MAIN_ProhibitedClose     (FAPI_SYS_HandleT h,
                                          fbool_t force);
FSTATIC void    MAIN_ProhibitedGetItem   (FAPI_SYS_HandleT h,
                                          int32_t id,
                                          uint32_t index,
                                          FGS_ITEMSTATE_E state,
                                          FGS_ITEM_S* item);

FSTATIC fbool_t MAIN_MsgBoxClose         (FAPI_SYS_HandleT h,
                                          fbool_t force);

FSTATIC fbool_t MENU_PinDialogIntClose   (FAPI_SYS_HandleT h,
                                          fbool_t force);
FSTATIC void    MENU_PinDialogOnFocusSet (FAPI_SYS_HandleT h,
                                          fbool_t hasFocus);
FSTATIC fbool_t MENU_PinDialogKeys       (FAPI_SYS_HandleT h);
FSTATIC fbool_t MENU_PinDialogNumKeys    (FAPI_SYS_HandleT h,
                                          uint8_t value);
FSTATIC void    MENU_PinDialogGetItem    (FAPI_SYS_HandleT h,
                                          int32_t id,
                                          uint32_t index,
                                          FGS_ITEMSTATE_E state,
                                          FGS_ITEM_S* item);

/* ------------------------------------------------------------------------- */

int32_t MAIN_SignalBoxInit (MAIN_SIGBOX_INST_S* inst)
{
    memset(inst, 0, sizeof(MAIN_SIGBOX_INST_S));

    return FAPI_OK;
}

int32_t MAIN_SignalBoxOpen (MAIN_SIGBOX_INST_S* inst,
                         const MAIN_SIGBOX_OPEN_S* openPars)
{
    FGS_BOX_OPEN_S      boxDat;
    FGS_PANEL_MEMBER_S  member;
    int32_t                retVal = FAPI_OK;
    FGS_ITEM_S*         pItem;

    if ( inst->lvlStrHdl != NULL ) return SMARTGO_APPL_ERR_ALREADY_OPEN;

    inst->data = *openPars;

    memset(&boxDat, 0, sizeof(boxDat));
    memset(&member, 0, sizeof(member));

    inst->lvlStrHdl    = NULL;
    inst->qualStrHdl   = NULL;
    inst->paused       = FFALSE;

    do
    {
        boxDat.pos.x          = inst->data.pos.x;
        boxDat.pos.y          = inst->data.pos.y;
        boxDat.pos.width      = inst->data.descrWidth - SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
        boxDat.pos.height     = 2 * SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        boxDat.pos.alignment  = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
        boxDat.bkgrType       = OSD_BOX_BKGR_NONE;

        boxDat.item[FGS_BOX_IDX_FOCUS].type    = FGS_ITEM_TYPE_NONE;

        pItem = boxDat.item + FGS_BOX_IDX_NONFOCUS;

        pItem->type                = FGS_ITEM_TYPE_STRING;
        pItem->align               = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
        pItem->item.str.chr        = OSD_GetStr(STR_GNR_SIGSTRENGTH);
        pItem->item.str.font       = MAIN_FONT;
        pItem->item.str.lineHeight = 0;
        pItem->item.str.col        = OSD_COL_TEXT;

        retVal = FGS_BOX_Open (&boxDat, ITEM_SIGBOX_ID_LVLSTR,
                               inst->data.pnlHdl, &(inst->lvlStrHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        boxDat.pos.y         += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        pItem->item.str.chr   = OSD_GetStr(STR_GNR_SIGQUALITY);

        retVal = FGS_BOX_Open (&boxDat, ITEM_SIGBOX_ID_QUALSTR,
                               inst->data.pnlHdl, &(inst->qualStrHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        inst->itemPos.x         = inst->data.pos.x + inst->data.descrWidth;
        inst->itemPos.y         = inst->data.pos.y;
        inst->itemPos.width     = inst->data.barWidth;
        inst->itemPos.height    = 2 * SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        inst->itemPos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;

        member.h             = (FAPI_SYS_HandleT)inst;
        member.pos           = &(inst->itemPos);
        member.id            = ITEM_SIGBOX_ID_BARS;
        member.isHidden      = FFALSE;
        member.show          = MAIN_SignalBoxDraw;

        retVal = FGS_PANEL_AddMember(inst->data.pnlHdl, &member,
                                     &(inst->pItem));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        (void)TIME_PeriodicTimerLaunch(OSD_PERIODTIMER_SIGNAL, 2); // period: 200 ms
    }
    while ( 0 );

    if ( retVal != FAPI_OK )
    {
        inst->lvlStrHdl  = NULL;
        inst->qualStrHdl = NULL;
    }

    return retVal;
}

int32_t MAIN_SignalBoxClose (MAIN_SIGBOX_INST_S* inst)
{
    if ( inst->lvlStrHdl == NULL ) return FAPI_OK;

    (void)TIME_PeriodicTimerAbort(OSD_PERIODTIMER_SIGNAL);

    /* NOTE: This invalidates only the pointer, as the object itself is removed
             together with the panel it had been assigned to! */

    inst->lvlStrHdl  = NULL;
    inst->qualStrHdl = NULL;
    return FAPI_OK;
}

int32_t MAIN_SignalBoxUpdate (MAIN_SIGBOX_INST_S* inst)
{
    /* test if currently open or paused */
    if ( (inst->lvlStrHdl != NULL) &&
         (!(inst->paused)) )
    {
        (void)FGS_PANEL_RefreshMember(inst->data.pnlHdl, ITEM_SIGBOX_ID_BARS);
    }

    return FAPI_OK;
}

uint32_t MAIN_SignalBoxGetHeight (void)
{
    return 2 * SCALER_GetCurrVal(LIST_LINE_HEIGHT);
}



int32_t MAIN_SignalBoxPause (MAIN_SIGBOX_INST_S* inst)
{
    inst->paused = FTRUE;
    return FAPI_OK;
}

int32_t MAIN_SignalBoxResume (MAIN_SIGBOX_INST_S* inst)
{
    inst->paused = FFALSE;
    return FAPI_OK;
}

int32_t MAIN_SignalBoxSetFeIdx (MAIN_SIGBOX_INST_S* inst, int8_t feIdx)
{
    inst->data.feIdx = feIdx;
    return FAPI_OK;
}

FSTATIC int32_t MAIN_SignalBoxDraw (FAPI_SYS_HandleT h)
{
    MAIN_SIGBOX_INST_S* inst = (MAIN_SIGBOX_INST_S*)h;
    uint32_t                 barColor;
    uint16_t                 strengthCurr = 0;
    uint16_t                 strengthMax  = 1;
    uint16_t                 qualCurr     = 0;
    uint16_t                 qualMax      = 1;

    if ( inst->data.feIdx >= 0 )
    {
        (void)AV_GetSignalStrength (inst->data.feIdx, &(strengthCurr),
                             &(strengthMax));
        (void)AV_GetSignalQuality  (inst->data.feIdx, &(qualCurr),
                             &(qualMax));
    }

    /* ----- draw signal strength bar -------------------------------------- */

    if ( (((uint32_t)(strengthMax) * 1) / 3) > strengthCurr )
    {
        barColor = OSD_COL_RED;
    }
    else if ( (((uint32_t)(strengthMax) * 2) / 3) > strengthCurr )
    {
        barColor = OSD_COL_YELLOW;
    }
    else barColor = OSD_COL_GREEN;

    OSD_DrawStatusBarHorizontal((uint16_t)inst->pItem->abspos.x,
                                inst->pItem->abspos.y + SCALER_GetCurrVal(INNER_FRAME_WIDTH),
                                inst->itemPos.width,
                                SCALER_GetCurrVal(LIST_LINE_HEIGHT) - (2 * SCALER_GetCurrVal(INNER_FRAME_WIDTH)),
                                strengthCurr, strengthMax,
                                barColor,
                                OSD_GetSchemeColor(OSD_SCHEMECOL_PROGRESSBAR_INACT),
                                OSD_GetSchemeColor(OSD_SCHEMECOL_FRAME));

    /* ----- draw signal quality bar --------------------------------------- */

    if ( (((uint32_t)(qualMax) * 1) / 3) > qualCurr )
    {
        barColor = OSD_COL_RED;
    }
    else if ( (((uint32_t)(qualMax) * 2) / 3) > qualCurr )
    {
        barColor = OSD_COL_YELLOW;
    }
    else barColor = OSD_COL_GREEN;

    OSD_DrawStatusBarHorizontal((uint16_t)inst->pItem->abspos.x,
                                inst->pItem->abspos.y + SCALER_GetCurrVal(INNER_FRAME_WIDTH) +
                                SCALER_GetCurrVal(LIST_LINE_HEIGHT),
                                inst->itemPos.width,
                                SCALER_GetCurrVal(LIST_LINE_HEIGHT) - (2 * SCALER_GetCurrVal(INNER_FRAME_WIDTH)),
                                qualCurr, qualMax,
                                barColor, OSD_GetSchemeColor(OSD_SCHEMECOL_PROGRESSBAR_INACT), OSD_GetSchemeColor(OSD_SCHEMECOL_FRAME));

    return FAPI_OK;
}


/* ------------------------------------------------------------------------- */

#endif

/* 21b0db20 - todo */
fbool_t MENU_SelectListOpen (MENU_SELECTLIST_INST_S* inst,
                           const MENU_SELECTLIST_OPEN_S* openParams)
{
    FGS_PANEL_OPEN_S   pnlDat; //sp140
    FGS_LNAVI_OPEN_S   naviDat; //sp4
    int32_t               retVal = FAPI_OK;

    memset(inst, 0, sizeof(MENU_SELECTLIST_INST_S));

    inst->data   = *openParams;
    inst->extIdx = -1;

    memset(&pnlDat, 0, sizeof(FGS_PANEL_OPEN_S));
    memset(&naviDat, 0, sizeof(FGS_LNAVI_OPEN_S));

    do
    {
        pnlDat.bkgrType      = 0x17; //TODO: OSD_PNLTYPE_SELECTLST;
        pnlDat.pos           = inst->data.pos;
        pnlDat.pos.x        -= SCALER_GetCurrVal(OSD_POS_X);
        pnlDat.pos.y        -= SCALER_GetCurrVal(OSD_POS_Y);
        pnlDat.pos.height    = 2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH) +
                               inst->data.numVisLines * SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        pnlDat.onFocusSet    = MENU_SelectListOnFocusSet;
        pnlDat.onFocusSetArg = (FAPI_SYS_HandleT)inst;
        pnlDat.pInst         = &(inst->pnlInst);

        retVal = FGS_PANEL_Open(&pnlDat, 42/*TODO: MENUID_SELECTLIST*/, &(inst->pnlHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        naviDat.pos.x           = SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
        naviDat.pos.y           = SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
        naviDat.pos.width       = pnlDat.pos.width -
                                  2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
        naviDat.pos.height      = pnlDat.pos.height -
                                  2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
        naviDat.pos.alignment   = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
        naviDat.bkgrType        = 0xf00; //OSD_NAVIBKGR_NORMAL | OSD_CORNER_ALL;
        naviDat.type            = FGS_LNAVI_TYPE_SCROLL;
        naviDat.rowHeight       = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        naviDat.scrollbarWidth  = SCALER_GetCurrVal(SCROLLBAR_WIDTH);
        naviDat.numVisLines     = inst->data.numVisLines;
        naviDat.numColumns      = 1;
        naviDat.params.numItems = inst->data.numItems;
        naviDat.params.index    = inst->data.index;
        naviDat.params.posInVis = inst->data.numVisLines;
        naviDat.colStart[0]     = SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
        naviDat.colWidth[0]     = naviDat.pos.width - (2 * SCALER_GetCurrVal(MAIN_TEXT_PAD_X)) -
                                  SCALER_GetCurrVal(SCROLLBAR_WIDTH);
        naviDat.topDownOrient   = FTRUE;
        naviDat.wraparound      = FTRUE;

#if 0
        naviDat.Data_96 = inst->data.Data_32;
        naviDat.Data_92 = inst->data.Data_28;
#endif

        naviDat.getItem         = inst->data.getItem;
        naviDat.getItemArg      = inst->data.getItemArg;

        naviDat.Data_92 = inst->data.Data_28;
        naviDat.Data_96 = inst->data.Data_32;

        naviDat.onSelect        = MENU_SelectListOnSelect;
        naviDat.onSelectArg     = (FAPI_SYS_HandleT)inst;

        naviDat.pInst           = &(inst->lnaviInst);

        retVal = FGS_LNAVI_Open (&naviDat, inst->data.id,
                                 inst->pnlHdl, &(inst->naviHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        inst->extIdx = MENUSTACK_AddExt(MENU_SelectListClose, (FAPI_SYS_HandleT)inst);

        (void)FGS_PANEL_SetMemberFocus(inst->pnlHdl, inst->data.id);
        (void)MENUSTACK_FocusForce    ((int32_t)42/*TODO: MENUID_SELECTLIST*/);
        (void)FGS_PANEL_Show          (inst->pnlHdl, FFALSE); /* turn visibility on */
    }
    while ( 0 );

    if ( retVal != FAPI_OK )
    {
        if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);
        inst->pnlHdl = NULL;
        return FFALSE;
    }

    return FTRUE;
}


/* 21b0c45c - complete */
FSTATIC void MENU_SelectListOnFocusSet (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    DBG_Assert(((MENU_SELECTLIST_INST_S*)h)->pnlHdl != NULL);

    if ( hasFocus )
    {
        FGS_SetAppKeyHandler(FGS_KEY_MENU, MENU_SelectListKeys, h, FTRUE, FFALSE);
        FGS_SetAppKeyHandler(FGS_KEY_BACK, MENU_SelectListKeys, h, FTRUE, FFALSE);
        FGS_SetAppKeyHandler(FGS_KEY_EXIT, MENU_SelectListKeys, h, FTRUE, FFALSE);
    }
    else
    {
        FGS_ClearAppKeyHandler(FGS_KEY_MENU);
        FGS_ClearAppKeyHandler(FGS_KEY_BACK);
        FGS_ClearAppKeyHandler(FGS_KEY_EXIT);
    }
}


/* 21b0c6d4 - complete */
FSTATIC fbool_t MENU_SelectListKeys (FAPI_SYS_HandleT h)
{
    //MENU_SELECTLIST_INST_S* inst    = (MENU_SELECTLIST_INST_S*)h;
    fbool_t                   keyUsed = FTRUE;

    switch ( FGS_GetCurrentKeyCode() )
    {
        case FGS_KEY_MENU:
            /* FALLTHROUGH */
        case FGS_KEY_BACK:
            /* FALLTHROUGH */
        case FGS_KEY_EXIT:
            (void)MENU_SelectListClose (h, FTRUE);
            break;

        default:
            keyUsed = FFALSE;
            break;
    }

    return keyUsed;
}


/* 21b0c654 - complete */
FSTATIC fbool_t MENU_SelectListClose (FAPI_SYS_HandleT h, fbool_t force)
{
    MENU_SELECTLIST_INST_S* inst    = (MENU_SELECTLIST_INST_S*)h;

    /* NOTE: 'force' argument is ignored. It is always possible to close the
             selection list dialogue.  */

    /* close dialog box */
    if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);
    inst->pnlHdl = NULL;

    (void)MENUSTACK_FocusRelease ((int32_t)42/*TODO: MENUID_SELECTLIST*/);
    (void)MENUSTACK_RemoveExt    (inst->extIdx);

    if ( inst->data.onExit != NULL )
    {
        inst->data.onExit(inst->naviHdl, inst->data.id);
    }

    return FTRUE;
}


/* 21b0c6a4 - complete */
FSTATIC void MENU_SelectListOnSelect (FAPI_SYS_HandleT h, int32_t id, uint16_t index)
{
    MENU_SELECTLIST_INST_S* inst    = (MENU_SELECTLIST_INST_S*)h;

    (void)MENU_SelectListClose(h, FTRUE);

    inst->data.onSelect(inst->data.onSelectArg, id, index);
}


#if 0

/* ------------------------------------------------------------------------- */

int32_t MAIN_VolumeBarInit (VOLUMEBAR_INST_S* inst)
{
    memset(inst, 0, sizeof(VOLUMEBAR_INST_S));

    inst->isVisible = FFALSE;
    inst->extIdx    = -1;

    return FAPI_OK;
}

int32_t MAIN_VolumeBarShow (VOLUMEBAR_INST_S* inst)
{
    FGS_PANEL_OPEN_S     pnlDat;
    FGS_BOX_OPEN_S       boxDat;
    FGS_PANEL_MEMBER_S   member;
    int32_t              retVal = FAPI_OK;

    if(appDat->menuHasLayer == FFALSE)
    {
        return FAPI_OK;
    }
    if(inst->pnlHdl == NULL)
    {
        memset(&pnlDat, 0, sizeof(FGS_PANEL_OPEN_S));
        memset(&boxDat, 0, sizeof(FGS_BOX_OPEN_S));
        memset(&member, 0, sizeof(member));

        do
        {
            pnlDat.bkgrType      = OSD_PNLTYPE_MENU;
            pnlDat.pos.width     = SCALER_GetCurrVal(VOLUMEBAR_WIDTH);
            pnlDat.pos.height    = (2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH)) +
                                   SCALER_GetCurrVal(LIST_LINE_HEIGHT) +
                                   SCALER_GetCurrVal(TITLE_LINE_HEIGHT) +
                                   SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
            pnlDat.pos.x         = SCALER_GetCurrVal(MAIN_PAD_X);
            pnlDat.pos.y         = -(int16_t)(SCALER_GetCurrVal(MAIN_PAD_Y) +
                                   pnlDat.pos.height);
            pnlDat.pos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_BOTTOM;
            pnlDat.inFront       = FTRUE;
            pnlDat.pInst         = &(inst->pnlInst);

            retVal = FGS_PANEL_Open(&pnlDat, MENUID_VOLUMEBAR, &(inst->pnlHdl));
            if ( retVal != FAPI_OK )
            {
                break;
            }

            /* ------------------------------------------------------------- */

            boxDat.pos.x           = SCALER_GetCurrVal(OUTER_FRAME_WIDTH) +
                                     SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
            boxDat.pos.y           = SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
            boxDat.pos.width       = pnlDat.pos.width -
                                     2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH) -
                                     2 * SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
            boxDat.pos.height      = SCALER_GetCurrVal(TITLE_LINE_HEIGHT);
            boxDat.pos.alignment   = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
            boxDat.bkgrType        = OSD_BOX_BKGR_NONE | OSD_CORNER_TOP_LEFT;

            boxDat.item[FGS_BOX_IDX_FOCUS].type                   = FGS_ITEM_TYPE_NONE;
            boxDat.item[FGS_BOX_IDX_NONFOCUS].type                = FGS_ITEM_TYPE_STRING;
            boxDat.item[FGS_BOX_IDX_NONFOCUS].align               = FGS_ALIGN_HOR_LEFT |
                                                                    FGS_ALIGN_VER_CENTER;
            boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.chr        = OSD_GetStr(STR_GNR_VOLUME);
            boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.font       = TITLE_FONT;
            boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.lineHeight = 0;
            boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.col        = OSD_COL_TEXT;

            retVal = FGS_BOX_Open (&boxDat, MENU_VOLUMEBAR_ID_TITLE,
                                   inst->pnlHdl, &(inst->titleHdl));
            if ( retVal != FAPI_OK )
            {
                break;
            }

            /* ----------------------------------------------------------------- */

            inst->itemPos.x         = SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
            inst->itemPos.y         = SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
            inst->itemPos.width     = pnlDat.pos.width -
                                      2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
            inst->itemPos.height    = pnlDat.pos.height -
                                      2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
            inst->itemPos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;

            member.h             = (FAPI_SYS_HandleT)inst;
            member.pos           = &(inst->itemPos);
            member.id            = MENU_VOLUMEBAR_ID_BAR;
            member.isHidden      = FFALSE;
            member.show          = MAIN_VolumeBarDraw;

            retVal = FGS_PANEL_AddMember(inst->pnlHdl, &member,
                                         &(inst->pItem));
            if ( retVal != FAPI_OK )
            {
                break;
            }
        }
        while ( 0 );

        if ( retVal != FAPI_OK )
        {
            if ( inst->pnlHdl != NULL )
            {
                (void)FGS_PANEL_Close(inst->pnlHdl);
            }
            inst->pnlHdl = NULL;
        }
        inst->extIdx = MENUSTACK_AddExt(MAIN_VolumeBarClose, (FAPI_SYS_HandleT)inst);

        /* open volumebar panel */
        (void) FGS_PANEL_Show(inst->pnlHdl, FFALSE);

        inst->isVisible = FTRUE;
    }
    if ( !(inst->isVisible) ) /* not visible yet */
    {
        inst->extIdx = MENUSTACK_AddExt(MAIN_VolumeBarClose, (FAPI_SYS_HandleT)inst);

        /* open volumebar panel */
        (void) FGS_PANEL_Show(inst->pnlHdl, FFALSE);

        inst->isVisible = FTRUE;
    }
    else
    {
        (void) FGS_PANEL_RefreshMember(inst->pnlHdl, MENU_VOLUMEBAR_ID_BAR);
    }

    inst->timeOpened = UTILS_GetTimerStamp();

    return FAPI_OK;
}

int32_t MAIN_VolumeBarHide (VOLUMEBAR_INST_S* inst)
{
    int32_t retVal;

    if ( inst->pnlHdl == NULL )
    {
        return FAPI_OK;
    }

    if ( inst->isVisible )
    {
        (void)FGS_PANEL_Hide(inst->pnlHdl);

        inst->isVisible = FFALSE;

        (void)MENUSTACK_RemoveExt(inst->extIdx);
        retVal = FAPI_OK;
    }
    else
    {
        retVal = SMARTGO_APPL_ERR_PROHIBITED;
    }

    retVal = FGS_PANEL_Close(inst->pnlHdl);
    inst->pnlHdl = NULL;

    return retVal;
}

void MAIN_VolumeBarHandleExpiration (VOLUMEBAR_INST_S* inst)
{
    uint16_t displayTime = 1;

    if ( !(inst->isVisible) ) return;

    (void)SETTINGS_DisplayTimeGet (&displayTime);

    if ( UTILS_GetTimerStampInterval(inst->timeOpened,
                                     UTILS_GetTimerStamp()) >=
                                     (uint64_t)(displayTime) * 1000 )
    {
        (void)MAIN_VolumeBarHide(inst);
    }
}

FSTATIC fbool_t MAIN_VolumeBarClose (FAPI_SYS_HandleT h, fbool_t force)
{
    VOLUMEBAR_INST_S* inst = (VOLUMEBAR_INST_S*)h;

    (void)MAIN_VolumeBarHide(inst);
    return FTRUE;
}

FSTATIC int32_t MAIN_VolumeBarDraw (FAPI_SYS_HandleT h)
{
    VOLUMEBAR_INST_S* inst = (VOLUMEBAR_INST_S*)h;
    uint8_t                lvlLeft  = 0;
    uint8_t                lvlRight = 0;
    uint8_t                lvlMax   = 1;
    fbool_t             isMuted  = FFALSE;
    uint32_t               col;

    if ( inst != NULL )
    {
        (void)AV_VolumeGet(&lvlLeft, &lvlRight, &lvlMax, &isMuted);

        if ( isMuted ) col = OSD_COL_TEXT_DISABLED;
        else           col = OSD_COL_BAR_ACTIVE;

        OSD_DrawStatusBarHorizontal(inst->pItem->abspos.x +
                                    SCALER_GetCurrVal(MAIN_TEXT_PAD_X),
                                    inst->pItem->abspos.y +
                                    SCALER_GetCurrVal(TITLE_LINE_HEIGHT),
                                    SCALER_GetCurrVal(VOLUMEBAR_WIDTH) -
                                    (2 * (SCALER_GetCurrVal(OUTER_FRAME_WIDTH) + SCALER_GetCurrVal(MAIN_TEXT_PAD_X))),
                                    SCALER_GetCurrVal(LIST_LINE_HEIGHT),
                                    lvlLeft, lvlMax,
                                    col, OSD_GetSchemeColor(OSD_SCHEMECOL_PROGRESSBAR_INACT), OSD_GetSchemeColor(OSD_SCHEMECOL_FRAME));
    }

    return FAPI_OK;
}

/* ------------------------------------------------------------------------- */

int32_t  MAIN_ProhibitedInit (PROHIBITED_INST_S* inst)
{
    if(inst == NULL)
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    memset(inst, 0, sizeof(PROHIBITED_INST_S));

    inst->isVisible = FFALSE;
    inst->extIdx    = -1;

    return FAPI_OK;
}

FSTATIC void MAIN_ProhibitedGetItem (FAPI_SYS_HandleT h,
                                     int32_t id,
                                     uint32_t index,
                                     FGS_ITEMSTATE_E state,
                                     FGS_ITEM_S* item)
{
    item->type                   = FGS_ITEM_TYPE_ICON;
    item->align                  = FGS_ALIGN_HOR_CENTER |
                                   FGS_ALIGN_VER_CENTER;
    item->item.icon.addr         = OSD_IconGet(ICON_PROHIBITED);
    item->item.icon.drawMode     = FGS_ICONMODE_OVRLAY;
    item->item.icon.bkgrCol      = OSD_COL_BLANK;
    item->item.icon.altBkgrCol   = OSD_COL_BLANK;
}

int32_t MAIN_ProhibitedShow (PROHIBITED_INST_S* inst)
{
    FGS_PANEL_OPEN_S     pnlDat;
    FGS_BOX_OPEN_S       boxDat;
    FAPI_SYS_HandleT     itemHdl;
    int32_t              retVal = FAPI_OK;

    if(inst == NULL)
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    if ( !(inst->isVisible) ) /* not visible yet */
    {
        if ( SYS_GetOperationMode() != SYS_PWRMODE_UP )
        {
            return FAPI_OK;
        }
        if(appDat->menuHasLayer == FFALSE)
        {
            return FAPI_OK;
        }

        memset(&pnlDat, 0, sizeof(FGS_PANEL_OPEN_S));
        memset(&boxDat, 0, sizeof(FGS_BOX_OPEN_S));

        do
        {
            pnlDat.bkgrType      = OSD_PNLTYPE_TRANSPARENT;
            pnlDat.pos.width     = SCALER_GetCurrVal(PROHIBITED_WIDTH);
            pnlDat.pos.height    = SCALER_GetCurrVal(PROHIBITED_HEIGHT);
            pnlDat.pos.x         = -(int16_t)(SCALER_GetCurrVal(PROHIBITED_WIDTH) + SCALER_GetCurrVal(PROHIBITED_PAD_X));
            pnlDat.pos.y         = SCALER_GetCurrVal(PROHIBITED_PAD_Y);
            pnlDat.pos.alignment = FGS_ALIGN_HOR_RIGHT | FGS_ALIGN_VER_TOP;
            pnlDat.inFront       = FTRUE;
            pnlDat.pInst         = &(inst->pnlInst);

            retVal = FGS_PANEL_Open(&pnlDat, MENUID_PROHIBITEDICON, &(inst->pnlHdl));
            if ( retVal != FAPI_OK )
            {
                break;
            }

            /* ----------------------------------------------------------------- */
            boxDat.pos.x           = 0;
            boxDat.pos.y           = 0;
            boxDat.pos.width       = pnlDat.pos.width;
            boxDat.pos.height      = pnlDat.pos.height;
            boxDat.pos.alignment   = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
            boxDat.bkgrType        = OSD_BOX_BKGR_NONE;
            boxDat.getItem         = MAIN_ProhibitedGetItem;
            boxDat.getItemArg      = NULL;

            retVal = FGS_BOX_Open (&boxDat, 0, inst->pnlHdl, &itemHdl);
            if ( retVal != FAPI_OK )
            {
                break;
            }
        }
        while ( 0 );

        if ( retVal != FAPI_OK )
        {
            if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

            inst->pnlHdl = NULL;
        }

        inst->extIdx = MENUSTACK_AddExt(MAIN_ProhibitedClose, (FAPI_SYS_HandleT)inst);

        (void)FGS_PANEL_Show(inst->pnlHdl, FFALSE);

        inst->isVisible = FTRUE;
    }

    /* launch/relaunch expiration timer */
    (void)TIME_SingleTimerLaunch(OSD_TIMER_ICON, 10); // 1 second

    return FAPI_OK;
}

int32_t MAIN_ProhibitedHide (PROHIBITED_INST_S* inst)
{
    if(inst == NULL)
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    if ( inst->pnlHdl == NULL )
    {
        return FAPI_OK;
    }

    (void)TIME_SingleTimerAbort(OSD_TIMER_ICON);

    (void)FGS_PANEL_Hide(inst->pnlHdl);
    (void)FGS_PANEL_Close(inst->pnlHdl);

    inst->isVisible = FFALSE;

    (void)MENUSTACK_RemoveExt(inst->extIdx);

    return FAPI_OK;
}

FSTATIC fbool_t MAIN_ProhibitedClose (FAPI_SYS_HandleT h, fbool_t force)
{
    PROHIBITED_INST_S* inst = (PROHIBITED_INST_S*)h;

    (void)MAIN_ProhibitedHide(inst);
    return FTRUE;
}

/* ------------------------------------------------------------------------- */

int32_t MAIN_MsgBoxInit (MAIN_MSGBOX_INST_S* inst)
{
    memset(inst, 0, sizeof(MAIN_MSGBOX_INST_S));

    inst->extIdx = -1;

    return FAPI_OK;
}

int32_t MAIN_MsgBoxShow (MAIN_MSGBOX_INST_S* inst, const MAIN_MSGBOX_OPEN_S* pars)
{
    uint16_t            textWidth;
    uint8_t             textFont;
    FGS_PANEL_OPEN_S    pnlDat;
    FGS_BOX_OPEN_S      boxDat;
    int32_t             retVal = FAPI_OK;

    if ( pars == NULL )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    inst->permanent = pars->permanent;

    if ( inst->pnlHdl != NULL ) /* hide current message if visible */
    {
        (void)FGS_PANEL_Close(inst->pnlHdl);
        inst->pnlHdl = NULL;
    }

    /* --------------------------------------------------------------------- */

    memset (&pnlDat, 0, sizeof(pnlDat));
    memset (&boxDat, 0, sizeof(boxDat));

    do
    {
        textFont  = MAIN_FONT;
        textWidth = OSD_GetStrWidth(pars->text, -1, textFont);

        pnlDat.bkgrType      = OSD_PNLTYPE_POPUP;
        pnlDat.inFront       = FTRUE;

        if ( pars->width < 0 )
        {
            if ( pars->numLines == 1 )
            {
                pnlDat.pos.width = 2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH) +
                                   textWidth + 2 * SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
            }
            else
            {
                retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
                break;
            }
        }
        else
        {
            pnlDat.pos.width = (uint16_t)pars->width;
        }

        /* align to four pixels */
        pnlDat.pos.width = (pnlDat.pos.width + 3) & 0xFFFFFFFC;

        pnlDat.pos.height    = 2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH) +
                               pars->numLines * SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        pnlDat.pos.x         = 0;
        pnlDat.pos.y         = -(int32_t)(SCALER_GetCurrVal(MAIN_PAD_Y) + pnlDat.pos.height);
        pnlDat.pos.alignment = FGS_ALIGN_HOR_CENTER | FGS_ALIGN_VER_BOTTOM;
        pnlDat.pInst          = &(inst->pnlInst);

        retVal = FGS_PANEL_Open(&pnlDat, MENUID_MSGBOX, &(inst->pnlHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        boxDat.pos.x           = SCALER_GetCurrVal(OUTER_FRAME_WIDTH) +
                                 SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
        boxDat.pos.y           = SCALER_GetCurrVal(OUTER_FRAME_WIDTH);
        boxDat.pos.width       = pnlDat.pos.width -
                                 2 * SCALER_GetCurrVal(OUTER_FRAME_WIDTH) -
                                 2 * SCALER_GetCurrVal(MAIN_TEXT_PAD_X);
        boxDat.pos.height      = pars->numLines * SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        boxDat.pos.alignment   = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
        boxDat.bkgrType        = OSD_BOX_BKGR_POPUP | OSD_CORNER_ALL;

        boxDat.item[FGS_BOX_IDX_FOCUS].type              = FGS_ITEM_TYPE_NONE;

        boxDat.item[FGS_BOX_IDX_NONFOCUS].type           = FGS_ITEM_TYPE_STRING;
        boxDat.item[FGS_BOX_IDX_NONFOCUS].align          = FGS_ALIGN_HOR_CENTER |
                                                           FGS_ALIGN_VER_CENTER;
        boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.chr        = pars->text;
        boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.font       = textFont;
        boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.lineHeight = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        boxDat.item[FGS_BOX_IDX_NONFOCUS].item.str.col        = OSD_COL_TEXT;

        retVal = FGS_BOX_Open (&boxDat, MAIN_MSGBOX_ID_TEXT,
                                inst->pnlHdl, &(inst->titleHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        if ( inst->extIdx < 0 )
        {
            inst->extIdx = MENUSTACK_AddExt(MAIN_MsgBoxClose, (FAPI_SYS_HandleT)inst);
        }

        (void)FGS_PANEL_Show(inst->pnlHdl, FFALSE);
    }
    while ( 0 );

    if ( retVal != FAPI_OK )
    {
        if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

        inst->pnlHdl = NULL;
        inst->extIdx = -1;
    }

    inst->timeOpened = UTILS_GetTimerStamp();

    return retVal;
}

int32_t MAIN_MsgBoxHide (MAIN_MSGBOX_INST_S* inst)
{
    if ( inst->pnlHdl != NULL )
    {
        (void)FGS_PANEL_Close(inst->pnlHdl);
        inst->pnlHdl = NULL;
    }

    (void)MENUSTACK_RemoveExt(inst->extIdx);
    inst->extIdx    = -1;

    return FAPI_OK;
}

void MAIN_MsgBoxHandleExpiration (MAIN_MSGBOX_INST_S* inst)
{
    uint16_t displayTime = 1;

    if ( (inst->pnlHdl == NULL) || (inst->permanent) ) return;

    (void)SETTINGS_DisplayTimeGet (&displayTime);

    if ( UTILS_GetTimerStampInterval(inst->timeOpened,
                                     UTILS_GetTimerStamp()) >=
                                     (uint64_t)(displayTime) * 1000 )
    {
        (void)MAIN_MsgBoxHide(inst);
    }
}

FSTATIC fbool_t MAIN_MsgBoxClose (FAPI_SYS_HandleT h, fbool_t force)
{
    MAIN_MSGBOX_INST_S* inst = (MAIN_MSGBOX_INST_S*)h;

    (void)MAIN_MsgBoxHide(inst);
    return FTRUE;
}

/* -------------------------------------------------------------------------- */

int32_t MENU_PinDialogInit (MENU_PINDIALOG_INST_S* inst)
{
    memset(inst, 0, sizeof(MENU_PINDIALOG_INST_S));

    return FAPI_OK;
}

int32_t MENU_PinDialogOpen (MENU_PINDIALOG_INST_S* inst,
                         const MENU_PINDIALOG_S* openParams)
{
    FGS_PANEL_OPEN_S    pnlDat;
    FGS_BOX_OPEN_S      boxDat;
    int32_t             retVal = FAPI_OK;
    uint8_t             cnt;
    FAPI_SYS_HandleT    boxHdl;

    /* ensure that dialogue is not opened twice */
    if ( inst->pnlHdl != NULL )
    {
        return SMARTGO_APPL_ERR_ALREADY_OPEN;
    }

    if ( openParams->numChars > MENU_PINDIALOG_CHARS_MAX )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    inst->data   = *openParams;
    inst->pinPos = 0;
    inst->extIdx = -1;

    memset(&pnlDat,  0, sizeof(pnlDat));
    memset(&boxDat,  0, sizeof(boxDat));

    do
    {
        pnlDat.bkgrType      = OSD_PNLTYPE_CONFDIALOG;
        pnlDat.pos.x         = 0;
        pnlDat.pos.y         = 0;
        pnlDat.pos.width     = SCALER_GetCurrVal(PINDIALOG_WIDTH);
        pnlDat.pos.height    = SCALER_GetCurrVal(MAIN_TOP_PADDING) + SCALER_GetCurrVal(MAIN_BOT_PADDING) +
                               SCALER_GetCurrVal(TITLE_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_HEIGHT) +
                               2 * SCALER_GetCurrVal(TITLE_TB_PADDING) +
                               2 * SCALER_GetCurrVal(LIST_LINE_PADDING) + SCALER_GetCurrVal(INNER_FRAME_WIDTH);
        pnlDat.pos.alignment = FGS_ALIGN_HOR_CENTER | FGS_ALIGN_VER_CENTER;
        pnlDat.inFront       = FTRUE;
        pnlDat.onFocusSet    = MENU_PinDialogOnFocusSet;
        pnlDat.onFocusSetArg = (FAPI_SYS_HandleT)inst;
        pnlDat.pInst         = &(inst->pnlInst);

        retVal = FGS_PANEL_Open(&pnlDat, MENUID_PINDIALOG, &(inst->pnlHdl));
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----- add title line -------------------------------------------- */

        boxDat.isHidden      = FFALSE;
        boxDat.bkgrType      = OSD_BOX_BKGR_POPUP; // to do: define specific background type!
        boxDat.getItem       = MENU_PinDialogGetItem;
        boxDat.getItemArg    = (FAPI_SYS_HandleT)inst;
        boxDat.pos.x         = SCALER_GetCurrVal(OUTER_FRAME_ALL) + SCALER_GetCurrVal(MAIN_LEFT_PADDING);
        boxDat.pos.y         = SCALER_GetCurrVal(MAIN_TOP_PADDING);
        boxDat.pos.width     = pnlDat.pos.width - ( 2 * SCALER_GetCurrVal(OUTER_FRAME_ALL) ) -
                               SCALER_GetCurrVal(MAIN_LEFT_PADDING) - SCALER_GetCurrVal(MAIN_RIGHT_PADDING);
        boxDat.pos.height    = SCALER_GetCurrVal(TITLE_LINE_HEIGHT);
        boxDat.pos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;

        retVal = FGS_BOX_Open(&boxDat, MENU_PINDIALOG_ID_TITLE,
                              inst->pnlHdl, &boxHdl);
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----- add boxes for PIN digits ---------------------------------- */

        boxDat.pos.x         = (SCALER_GetCurrVal(PINDIALOG_WIDTH) -
                               (MENU_PINDIALOG_CHARS_MAX * SCALER_GetCurrVal(PINDIALOG_DIGITWIDTH)) -
                               ((MENU_PINDIALOG_CHARS_MAX - 1) * SCALER_GetCurrVal(PINDIALOG_DIGITPAD))) / 2;
        boxDat.pos.y        += SCALER_GetCurrVal(TITLE_LINE_HEIGHT) + SCALER_GetCurrVal(INNER_FRAME_WIDTH) +
                               2 * SCALER_GetCurrVal(TITLE_TB_PADDING) +
                               2 * SCALER_GetCurrVal(LIST_LINE_PADDING);
        boxDat.pos.width     = SCALER_GetCurrVal(PINDIALOG_DIGITWIDTH);
        boxDat.pos.height    = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        boxDat.pos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;

        for ( cnt = 0; cnt < inst->data.numChars; cnt++ )
        {
            boxDat.pInst = inst->boxInst + cnt;

            retVal = FGS_BOX_Open(&boxDat, MENU_PINDIALOG_ID_DIGIT + cnt,
                                  inst->pnlHdl, &boxHdl);
            if ( retVal != FAPI_OK )
            {
                break;
            }

            boxDat.pos.x += SCALER_GetCurrVal(PINDIALOG_DIGITWIDTH) + SCALER_GetCurrVal(PINDIALOG_DIGITPAD);
        }

        /* ----------------------------------------------------------------- */

        inst->extIdx = MENUSTACK_AddExt (MENU_PinDialogIntClose,
                                        (FAPI_SYS_HandleT)inst);

        (void)MENUSTACK_FocusForce ((int32_t)MENUID_PINDIALOG);
        (void)FGS_PANEL_Show       (inst->pnlHdl, FFALSE); /* turn visibility on */
    }
    while ( 0 );

    if ( retVal != FAPI_OK )
    {
        if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);
        inst->pnlHdl = NULL;
        return retVal;
    }

    return FAPI_OK;
}

int32_t MENU_PinDialogClose (MENU_PINDIALOG_INST_S* inst)
{
    /* already closed? */
    if ( inst->pnlHdl == NULL ) return FAPI_OK;

    if ( MENU_PinDialogIntClose((FAPI_SYS_HandleT)inst, FFALSE) )
    {
        return FAPI_OK;
    }
    else
    {
        return SMARTGO_APPL_ERR_INTERNAL;
    }
}

int32_t MENU_PinDialogReset (MENU_PINDIALOG_INST_S* inst)
{
    uint8_t cnt;

    /* currently open? */
    if ( inst->pnlHdl == NULL ) return FAPI_OK;

    inst->pinPos = 0;

    MENU_CommonMsgShow(STR_MSG_PASSWORD_ERROR,FFALSE);

    /* refresh PIN digits */
    for ( cnt = 0; cnt < inst->data.numChars; cnt++ )
    {
        (void)FGS_PANEL_RefreshMember(inst->pnlHdl, MENU_PINDIALOG_ID_DIGIT + cnt);
    }

    return FAPI_OK;
}

FSTATIC fbool_t MENU_PinDialogIntClose (FAPI_SYS_HandleT h, fbool_t force)
{
    MENU_PINDIALOG_INST_S* inst = (MENU_PINDIALOG_INST_S*)h;

    /* NOTE: 'force' argument is ignored. No restrictions apply on closing
             a pin list dialogue. */

    /* close dialog box */
    if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

    inst->pnlHdl = NULL;


    (void)MENUSTACK_FocusRelease ((int32_t)MENUID_PINDIALOG);
    (void)MENUSTACK_RemoveExt    (inst->extIdx);
    return FTRUE;
}

FSTATIC void  MENU_PinDialogOnFocusSet (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    MENU_PINDIALOG_INST_S* inst = (MENU_PINDIALOG_INST_S*)h;

    DBG_Assert(inst->pnlHdl != NULL);

    if ( hasFocus )
    {
        FGS_SetAppNumKeyHandler(FGS_KEY_NUMBER, MENU_PinDialogNumKeys, h, FTRUE, FFALSE);
        FGS_SetAppKeyHandler   (FGS_KEY_MENU,   MENU_PinDialogKeys,    h, FTRUE, FFALSE);
        FGS_SetAppKeyHandler   (FGS_KEY_BACK,   MENU_PinDialogKeys,    h, FTRUE, FFALSE);
        FGS_SetAppKeyHandler   (FGS_KEY_EXIT,   MENU_PinDialogKeys,    h, FTRUE, FFALSE);

        if ( inst->data.keyHdlChanUp != NULL )
        {
            FGS_SetAppKeyHandler (FGS_KEY_CHAN_UP, MENU_PinDialogKeys, h, FFALSE, FFALSE);
        }

        if ( inst->data.keyHdlChanDown != NULL )
        {
            FGS_SetAppKeyHandler (FGS_KEY_CHAN_DOWN, MENU_PinDialogKeys, h, FFALSE, FFALSE);
        }
    }
    else
    {
        FGS_ClearAppKeyHandler (FGS_KEY_NUMBER);
        FGS_ClearAppKeyHandler (FGS_KEY_MENU);
        FGS_ClearAppKeyHandler (FGS_KEY_BACK);
        FGS_ClearAppKeyHandler (FGS_KEY_EXIT);

        if ( inst->data.keyHdlChanUp != NULL )
        {
            FGS_ClearAppKeyHandler (FGS_KEY_CHAN_UP);
        }

        if ( inst->data.keyHdlChanDown != NULL )
        {
            FGS_ClearAppKeyHandler (FGS_KEY_CHAN_DOWN);
        }
    }
}

FSTATIC fbool_t MENU_PinDialogKeys (FAPI_SYS_HandleT h)
{
    MENU_PINDIALOG_INST_S* inst    = (MENU_PINDIALOG_INST_S*)h;
    fbool_t                  keyUsed = FFALSE;

    switch ( FGS_GetCurrentKeyCode() )
    {
        case FGS_KEY_MENU:
            /* FALLTHROUGH */
        case FGS_KEY_BACK:
            /* FALLTHROUGH */
        case FGS_KEY_EXIT:
            keyUsed = FTRUE;
            break;

        case FGS_KEY_CHAN_UP:
            keyUsed = inst->data.keyHdlChanUp(inst->data.keyHdlChanUpArg);
            break;

        case FGS_KEY_CHAN_DOWN:
            keyUsed = inst->data.keyHdlChanDown(inst->data.keyHdlChanDownArg);
            break;

        default:
            break;
    }

    if ( keyUsed )
    {
        (void)MENU_PinDialogIntClose(h, FFALSE);
    }

    return keyUsed;
}

FSTATIC fbool_t MENU_PinDialogNumKeys (FAPI_SYS_HandleT h, uint8_t value)
{
    MENU_PINDIALOG_INST_S* inst = (MENU_PINDIALOG_INST_S*)h;

    if ( inst->pinPos < inst->data.numChars )
    {
        inst->pin[inst->pinPos++] = '0' + (char_t)value;

        (void)FGS_PANEL_RefreshMember (inst->pnlHdl,
                                 MENU_PINDIALOG_ID_DIGIT + inst->pinPos - 1);

        if ( inst->pinPos == inst->data.numChars )
        {
            if ( inst->data.onPinEnter != NULL )
            {
                inst->data.onPinEnter (inst->data.arg, inst->pin,
                                       inst->data.numChars);
            }
        }

        return FTRUE;
    }
    else
    {
        return FFALSE;
    }
}

FSTATIC void MENU_PinDialogGetItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                    FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    MENU_PINDIALOG_INST_S* inst = (MENU_PINDIALOG_INST_S*)h;

    switch ( id )
    {
        case MENU_PINDIALOG_ID_TITLE:
            item->type                = FGS_ITEM_TYPE_STRING;
            item->align               = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_CENTER;
            item->item.str.font       = MAIN_FONT;
            item->item.str.lineHeight = 0;
            item->item.str.col        = OSD_COL_TITLE_TEXT;
            item->item.str.chr        = inst->data.titleStr;
            break;

        default:
            if ( (id >= MENU_PINDIALOG_ID_DIGIT) &&
                 (id <  (int32_t)(MENU_PINDIALOG_ID_DIGIT + inst->data.numChars)) )
            {
                item->type                = FGS_ITEM_TYPE_STRING;
                item->align               = FGS_ALIGN_HOR_CENTER | FGS_ALIGN_VER_CENTER;
                item->item.str.font       = MAIN_FONT;
                item->item.str.lineHeight = 0;
                item->item.str.col        = OSD_COL_TEXT;

                if ( (id - MENU_PINDIALOG_ID_DIGIT) < (int32_t)inst->pinPos )
                {
                    item->item.str.chr    = OSD_GetStr(STR_GNR_PIN_DIGITSET);
                }
                else
                {
                    item->item.str.chr    = OSD_GetStr(STR_GNR_PIN_DIGITFREE);
                }
            }
            break;
    }
}

#endif

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
