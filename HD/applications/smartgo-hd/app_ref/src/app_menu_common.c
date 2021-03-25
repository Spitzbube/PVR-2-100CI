/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_menu_common.c
**

** \brief       Common menu-building functions.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
**
******************************************************************************
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


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

#if 0

int32_t MENU_CommonAddTitle (int32_t id, FAPI_SYS_HandleT pnlHdl,
                             uint16_t pnlWidth,
                             uint16_t stackedFrameWidth, uint32_t strIdx,
                             FGS_GETITEM_CB getTitleItemCb, void* cbArg)
{
    FGS_BOX_OPEN_S      boxPars;
    FAPI_SYS_HandleT    titleHdl;

    memset(&boxPars, 0, sizeof(boxPars));

    boxPars.pos.x         = SCALER_GetCurrVal(OUTER_FRAME_ALL) +
                             SCALER_GetCurrVal(MAIN_LEFT_PADDING) +
                             stackedFrameWidth;
    boxPars.pos.y         = SCALER_GetCurrVal(OUTER_FRAME_ALL) -
                            (SCALER_GetCurrVal(OUTER_FRAME_ALL) - SCALER_GetCurrVal(OUTER_FRAME_WIDTH))/2 + /* done for centering */
                             SCALER_GetCurrVal(TITLE_TB_PADDING) +
                             stackedFrameWidth;
    boxPars.pos.width     = pnlWidth - (2*SCALER_GetCurrVal(OUTER_FRAME_ALL)) -
                             SCALER_GetCurrVal(MAIN_RIGHT_PADDING) - stackedFrameWidth;
    boxPars.pos.height    = (2*SCALER_GetCurrVal(TITLE_TB_PADDING)) + SCALER_GetCurrVal(TITLE_LINE_HEIGHT);
    boxPars.pos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    boxPars.bkgrType      = OSD_BOX_BKGR_NONE;
    boxPars.getItem       = MENU_CommonGetItemTitle;
    boxPars.getItemArg    = (FAPI_SYS_HandleT)strIdx;

    return FGS_BOX_Open (&boxPars, id, pnlHdl, &titleHdl);
}

void MENU_CommonGetItemTitle (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                              FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    MENU_COMMON_ITEM_TITLESTR(item, (uint32_t)h);
}

int32_t MENU_CommonAddGenericTitle (int32_t id, FGS_GETITEM_CB getItem,
                                 FAPI_SYS_HandleT getItemArg, FAPI_SYS_HandleT pnlHdl,
                                 uint16_t pnlWidth, uint16_t stackedFrameWidth)
{
    FGS_BOX_OPEN_S  boxPars;
    FAPI_SYS_HandleT       titleHdl;

    memset(&boxPars, 0, sizeof(boxPars));

    boxPars.pos.x         = SCALER_GetCurrVal(OUTER_FRAME_ALL)
                          + SCALER_GetCurrVal(MAIN_LEFT_PADDING)
                          + stackedFrameWidth;
    boxPars.pos.y         = SCALER_GetCurrVal(OUTER_FRAME_ALL)
                          - ((SCALER_GetCurrVal(OUTER_FRAME_ALL)
                          - SCALER_GetCurrVal(OUTER_FRAME_WIDTH)) / 2) /* done for centering */
                          + SCALER_GetCurrVal(TITLE_TB_PADDING)
                          + stackedFrameWidth;
    boxPars.pos.width     = pnlWidth
                          - (2 * SCALER_GetCurrVal(OUTER_FRAME_ALL))
                          - SCALER_GetCurrVal(MAIN_RIGHT_PADDING)
                          - stackedFrameWidth;
    boxPars.pos.height    = (2 * SCALER_GetCurrVal(TITLE_TB_PADDING))
                          + SCALER_GetCurrVal(TITLE_LINE_HEIGHT);
    boxPars.pos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    boxPars.bkgrType      = OSD_BOX_BKGR_NONE;
    boxPars.getItem       = getItem;
    boxPars.getItemArg    = getItemArg;

    return FGS_BOX_Open (&boxPars, id, pnlHdl, &titleHdl);
}

FAPI_SYS_HandleT MENU_CommonAddList (FGS_LIST_OPEN_S* pListPars, int32_t id,
                                     uint16_t stackedFrameWidth,
                                     uint16_t offsetY,
                                     uint16_t width, uint16_t height,
                                     FAPI_SYS_HandleT pnlHdl,
                                     FGS_POS_S* pItemPos,
                                     FGS_POS_S* pDescrPos,
                                     FGS_POS_S* pValuePos,
                                     uint8_t descrPercentage,
                                     int32_t* pRetVal)
{
    FAPI_SYS_HandleT listHdl = NULL;
    int32_t          retVal;
    uint16_t         contentWidth;

    /* NOTE: This function only sets a subset of the required list parameters.
             All other parameters have to be set prior to calling this
             function. */

    pListPars->pos.x           = SCALER_GetCurrVal(OUTER_FRAME_ALL)
                               + stackedFrameWidth;
    pListPars->pos.y           = SCALER_GetCurrVal(OUTER_FRAME_ALL)
                               + SCALER_GetCurrVal(INNER_FRAME_WIDTH)
                               + SCALER_GetCurrVal(MAIN_TOP_PADDING)
                               + (2 * SCALER_GetCurrVal(TITLE_TB_PADDING))
                               + SCALER_GetCurrVal(TITLE_LINE_HEIGHT)
                               + stackedFrameWidth
                               + offsetY;
    pListPars->pos.width       = width;
    pListPars->pos.height      = height;

    pListPars->pos.alignment   = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    pListPars->topDownOriented = FTRUE;
    pListPars->wraparound      = FTRUE;
    pListPars->pInst           = &(appDat->listInst);

    retVal = FGS_LIST_Open (pListPars, id, pnlHdl, &listHdl);

    if ( retVal != FAPI_OK )
    {
        listHdl = NULL;
    }

    if ( pItemPos != NULL )
    {
        memset (pItemPos, 0, sizeof(FGS_POS_S));

        pItemPos->width     = width;
        pItemPos->height    = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        pItemPos->alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    }

    contentWidth = width - SCALER_GetCurrVal(MAIN_LEFT_PADDING)
                         - SCALER_GetCurrVal(MAIN_RIGHT_PADDING);

    /* position of list item descriptors in list entry */
    if ( pDescrPos != NULL )
    {
        memset (pDescrPos, 0, sizeof(FGS_POS_S));

        pDescrPos->x         = SCALER_GetCurrVal(MAIN_LEFT_PADDING);

        if ( descrPercentage < 100 )
        {
            pDescrPos->width = (contentWidth * descrPercentage) / 100;
        }
        else
        {
            pDescrPos->width = contentWidth;
        }

        pDescrPos->height    = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        pDescrPos->alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    }

    /* position of list item values in list entry */
    if ( pValuePos != NULL )
    {
        memset (pValuePos, 0, sizeof(FGS_POS_S));

        if ( pDescrPos != NULL )
        {
            pValuePos->x     = pDescrPos->x + pDescrPos->width;
            pValuePos->width = contentWidth - pDescrPos->width;
        }
        else
        {
            pValuePos->x     = SCALER_GetCurrVal(MAIN_LEFT_PADDING);
            pValuePos->width = contentWidth;
        }

        pValuePos->height    = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        pValuePos->alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    }

    if ( pRetVal != NULL )
    {
        *pRetVal = retVal;
    }

    return listHdl;
}

#endif

/* 21b19f50 - complete */
void MENU_CommonSetParamsTitleWHelp (FGS_PANEL_OPEN_S* pnlPars,
                                     uint16_t innerWidth, uint16_t innerHeight,
                                     uint16_t helpWidth, uint8_t  numHelpLines,
                                     uint16_t* pStackedFrameWidth)
{
    uint16_t stackedFrameWidth = 0;
    /*uint8_t*/int  stackLevel        = 0;

//    if ( pStackedFrameWidth != NULL )
//    {
        stackLevel = /*(uint8_t)*/MENUSTACK_GetLevel();

//        if ( stackLevel > 0 )
        {
            stackLevel--;
        }

        stackedFrameWidth   = stackLevel *
                             (SCALER_GetCurrVal(STACKED_FRAME_DIST)
                            + SCALER_GetCurrVal(OUTER_FRAME_ALL));
        *pStackedFrameWidth = stackedFrameWidth;
//    }

    pnlPars->pos.width       = innerWidth
                             + helpWidth
                             + (2 * SCALER_GetCurrVal(OUTER_FRAME_ALL))
                             + SCALER_GetCurrVal(INNER_FRAME_WIDTH)
                             + stackedFrameWidth;
    pnlPars->pos.height      = innerHeight
                             + *pStackedFrameWidth
                             + (2 * SCALER_GetCurrVal(OUTER_FRAME_ALL))
                             + (2 * SCALER_GetCurrVal(TITLE_TB_PADDING))
                             + SCALER_GetCurrVal(TITLE_LINE_HEIGHT)
                             + SCALER_GetCurrVal(MAIN_TOP_PADDING)
                             + SCALER_GetCurrVal(MAIN_BOT_PADDING)
                             + (2 * SCALER_GetCurrVal(INNER_FRAME_WIDTH));

    if ( numHelpLines > 0 )
    {
        pnlPars->pos.height += (2 * SCALER_GetCurrVal(HELP_TB_PADDING))
                             + (numHelpLines     *
                                SCALER_GetCurrVal(HELP_LINE_HEIGHT))
                             + ((numHelpLines -1) *
                                SCALER_GetCurrVal(HELP_LINE_PADDING));
    }

    pnlPars->bkgrType        = (/*OSD_PNLTYPE_MENUWTITLEWHELP0*/1/*???*/ + numHelpLines)
                             /*| (((uint16_t)stackLevel) << 8)*/
                             | (((uint32_t)helpWidth) << 16);
#if 0
    pnlPars->pInst           = &(appDat->pnlInst);
#endif
}

#if 0

void MENU_CommonSetParamsTitleWBotHelp (FGS_PANEL_OPEN_S* pnlPars,
                                        uint16_t innerWidth,
                                        uint16_t innerHeight,
                                        uint8_t  numHelpLines,
                                        uint16_t* pStackedFrameWidth)
{
    uint16_t stackedFrameWidth = 0;
    uint8_t  stackLevel        = 0;

    if ( pStackedFrameWidth != NULL )
    {
        stackLevel = (uint8_t)MENUSTACK_GetLevel();

        if ( stackLevel > 0 )
        {
            stackLevel--;
        }

        stackedFrameWidth   = stackLevel *
                             (SCALER_GetCurrVal(STACKED_FRAME_DIST)
                            + SCALER_GetCurrVal(OUTER_FRAME_ALL));
        *pStackedFrameWidth = stackedFrameWidth;
    }

    pnlPars->pos.width       = innerWidth
                             + (2 * SCALER_GetCurrVal(OUTER_FRAME_ALL))
                             + SCALER_GetCurrVal(INNER_FRAME_WIDTH)
                             + stackedFrameWidth;

    pnlPars->pos.height      = innerHeight
                             + stackedFrameWidth
                             + (2 * SCALER_GetCurrVal(OUTER_FRAME_ALL))
                             + (2 * SCALER_GetCurrVal(TITLE_TB_PADDING))
                             + SCALER_GetCurrVal(TITLE_LINE_HEIGHT)
                             + SCALER_GetCurrVal(MAIN_TOP_PADDING)
                             + SCALER_GetCurrVal(MAIN_BOT_PADDING)
                             + (2 * SCALER_GetCurrVal(INNER_FRAME_WIDTH));

    if ( numHelpLines > 0 )
    {
        pnlPars->pos.height += (2 * SCALER_GetCurrVal(HELP_TB_PADDING))
                             + (numHelpLines     *
                                SCALER_GetCurrVal(HELP_LINE_HEIGHT))
                             + ((numHelpLines - 1) *
                                SCALER_GetCurrVal(HELP_LINE_PADDING));
    }

    pnlPars->bkgrType        = (OSD_PNLTYPE_MENUWTITLEWBOTHELP0 + numHelpLines)
                             | (((uint16_t)stackLevel) << 8);
    pnlPars->pInst           = &(appDat->pnlInst);
}

#endif

/* 21b19e88 - complete */
void MENU_CommonSetPanelPos (FGS_POS_S* pos)
{
    uint32_t align = 0;

    (void)MAIN_UserDataGet(/*USERDAT_MENUALIGNMENT*/3, &align);

    pos->alignment = (uint8_t)align;

    switch ( pos->alignment & FGS_ALIGN_MASK_HOR )
    {
        case FGS_ALIGN_HOR_LEFT:
            pos->x = SCALER_GetCurrVal(MAIN_HOR_OFFSET);
            break;

        case FGS_ALIGN_HOR_RIGHT:
            pos->x = -(int16_t)(SCALER_GetCurrVal(MAIN_HOR_OFFSET) + pos->width);
            break;

        default:
        case FGS_ALIGN_HOR_CENTER:
            pos->x = 0;
            break;
    }

    switch ( pos->alignment & FGS_ALIGN_MASK_VER )
    {
        case FGS_ALIGN_VER_TOP:
            pos->y = SCALER_GetCurrVal(MAIN_VER_OFFSET);
            break;

        case FGS_ALIGN_VER_BOTTOM:
            pos->y = -(int16_t)(SCALER_GetCurrVal(MAIN_VER_OFFSET) + pos->height);
            break;

        default:
        case FGS_ALIGN_VER_CENTER:
            pos->y = 0;
            break;
    }

}

#if 0

void MENU_CommonSelectListSelected (FAPI_SYS_HandleT listHdl, int32_t id, uint16_t index)
{
    FGS_ITEM_SEL_PARAMS_S selParams;

    if ( FGS_LIST_GetMemberParams(listHdl, id, &selParams) != FAPI_OK )
    {
        return;
    }

    selParams.index = index;

    (void)FGS_LIST_SetMemberParams(listHdl, id, &selParams);
}

FAPI_SYS_HandleT MENU_CommonAddHelpList (int32_t id, FAPI_SYS_HandleT pnlHdl,
                                  uint16_t stackedFrameWidth, uint16_t innerWidth,
                                  int16_t y, uint16_t width, uint16_t numLines,
                                  FGS_GETITEM_CB getItem,
                                  FAPI_SYS_HandleT getItemArg)
{
    FGS_LNAVI_OPEN_S naviPars;
    FAPI_SYS_HandleT        naviHdl;

    memset(&naviPars, 0, sizeof(naviPars));

    naviPars.pos.x             = SCALER_GetCurrVal(OUTER_FRAME_ALL) + innerWidth +
                                 SCALER_GetCurrVal(INNER_FRAME_WIDTH) + SCALER_GetCurrVal(HELP_LR_PADDING) +
                                 stackedFrameWidth;
    naviPars.pos.y             = y;
    naviPars.pos.width         = width - 2 * SCALER_GetCurrVal(HELP_LR_PADDING);
    naviPars.rowHeight         = SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);
    naviPars.pos.height        = numLines * naviPars.rowHeight;
    naviPars.pos.alignment     = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
    naviPars.bkgrType          = OSD_NAVIBKGR_HELP;
    naviPars.type              = FGS_LNAVI_TYPE_SCROLL;
    naviPars.scrollbarWidth    = 0;
    naviPars.numVisLines       = numLines;
    naviPars.numColumns        = 1;
    naviPars.params.numItems   = numLines;
    naviPars.params.index      = 0;
    naviPars.params.posInVis   = 0;
    naviPars.topDownOrient     = FTRUE;
    naviPars.wraparound        = FTRUE;
    naviPars.getItem           = getItem;
    naviPars.getItemArg        = getItemArg;
    naviPars.pInst             = &(appDat->helpNaviInst);

    if ( FGS_LNAVI_Open (&naviPars, id, pnlHdl, &naviHdl) != FAPI_OK )
    {
        return NULL;
    }
    else return naviHdl;
}

void MENU_CommonSetHelpDescrParams (FGS_ITEM_S* item, FGS_ITEMSTATE_E state,
                                    uint32_t strIdx)
{
    item->type                = FGS_ITEM_TYPE_STRING;
    item->align               = FGS_ALIGN_HOR_CENTER | FGS_ALIGN_VER_CENTER;
    item->item.str.chr        = OSD_GetStr(strIdx);
    item->item.str.font       = SYMBOL_FONT;
    item->item.str.lineHeight = 0;

    switch ( state )
    {
        default:
        case FGS_DISABLED:
        case FGS_NONFOCUS: item->item.str.col = OSD_GetSchemeColor(OSD_SCHEMECOL_HELP_BKGR);
                           break;
        case FGS_FOCUS:    item->item.str.col = appDat->txtAttr.colFocus;
                           break;
    }
}

void MENU_CommonGetHelpItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                             FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    uint32_t strIdx;

    switch ( id )
    {
        case ITEM_HELP_KEY_MENU:
            strIdx = STR_KEY_MENU;
            break;

        case ITEM_HELP_KEY_EXIT:
            strIdx = STR_KEY_EXIT;
            break;

        case ITEM_HELP_TEXT_BACK:
            strIdx = STR_HELP_MENU_BACK;
            break;

        case ITEM_HELP_TEXT_CLOSEMENU:
            strIdx = STR_HELP_MENU_EXIT;
            break;

        default:
            return;
    }

    MENU_COMMON_ITEM_HELPSTR(item, strIdx);
}

int32_t MENU_CommonAddMenuExitHelpLine (int16_t xPos, int16_t yPos,
                                     uint16_t width, FAPI_SYS_HandleT pnlHdl)
{
    int32_t           retVal;
    FGS_BOX_OPEN_S boxPars;
    FAPI_SYS_HandleT      itemHdl;

    memset(&boxPars, 0, sizeof(boxPars));

    boxPars.pos.y            = yPos;
    boxPars.pos.height       = SCALER_GetCurrVal(HELP_LINE_HEIGHT);
    boxPars.pos.alignment    = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_BOTTOM;
    boxPars.bkgrType         = OSD_BOX_BKGR_NONE;

    boxPars.getItem          = MENU_CommonGetHelpItem;
    boxPars.getItemArg       = NULL;

    do
    {
        boxPars.pos.x      = xPos;
        boxPars.pos.width  = SCALER_GetCurrVal(HELP_BOT_XOFF) -
                             SCALER_GetCurrVal(MAIN_TEXT_PAD_X);

        retVal = FGS_BOX_Open (&boxPars, ITEM_HELP_KEY_MENU, pnlHdl, &itemHdl);
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        boxPars.pos.x     += SCALER_GetCurrVal(HELP_BOT_XOFF);
        boxPars.pos.width  = (width / 2) - SCALER_GetCurrVal(MAIN_TEXT_PAD_X) - SCALER_GetCurrVal(HELP_BOT_XOFF);

        retVal = FGS_BOX_Open (&boxPars, ITEM_HELP_TEXT_BACK, pnlHdl, &itemHdl);
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        boxPars.pos.x      = xPos + (width / 2);
        boxPars.pos.width  = SCALER_GetCurrVal(HELP_BOT_XOFF) - SCALER_GetCurrVal(MAIN_TEXT_PAD_X);

        retVal = FGS_BOX_Open (&boxPars, ITEM_HELP_KEY_EXIT, pnlHdl, &itemHdl);
        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* ----------------------------------------------------------------- */

        boxPars.pos.x     += SCALER_GetCurrVal(HELP_BOT_XOFF);
        boxPars.pos.width  = (width / 2) - SCALER_GetCurrVal(HELP_BOT_XOFF);

        retVal = FGS_BOX_Open (&boxPars, ITEM_HELP_TEXT_CLOSEMENU, pnlHdl, &itemHdl);
        if ( retVal != FAPI_OK )
        {
            break;
        }

    } while ( 0 );

    return retVal;
}

/*!
******************************************************************************
** \brief This function appends a path to a path.
**
** Appends 'newPath' on 'path' and copies result to 'result'. Separator is
** optionally added.
**
** \param newPath       New path to be appended.
** \param path          Old path to be appended upon.
** \param result        Resulting path, combining newPath and path.
** \param separator     If FTRUE, separator will be appended at end of
**                      resulting string.
** \param resultLength  Total size of result string buffer in bytes.
**
******************************************************************************
*/
void MENU_CommonAppendpath (const char_t* newPath, const char_t* path,
                            char_t* result, fbool_t separator,
                            uint16_t resultLength)
{
    uint16_t i;
    uint16_t n = 0;
    uint16_t copyLength = resultLength;

    if ( copyLength > 0 )
    {
        copyLength--;
    }

    for ( i = 0; i < copyLength; i++ )
    {
        result[i] = path[i];

        if ( path[i] == 0 )
        {
            break;
        }
    }

    for ( ;i < copyLength; i++)
    {
        result[i] = newPath[n];

        if ( newPath[n++] == 0 )
        {
            break;
        }
    }

    if ( separator && (i < copyLength) )
    {
        result[i++] = MENU_COMMON_PATH_SEPARATOR;
    }

    result[i]= 0; /* terminate string */
}


/*!
******************************************************************************
** \brief This function shows the given String ID to the OSD.
**
** The message is shown in on single line and the width is calculated by string
** length.
**
** \param msg       The string ID.
** \param permanent A flag if the message should be shown permanently or not.
**
** \sa
**          - MAIN_MsgBoxHide()
******************************************************************************
*/
void MENU_CommonMsgShow(STR_IDX_S msg, fbool_t permanent)
{
    MAIN_MSGBOX_OPEN_S msgBoxPars;

    if(msg == STR_EMPTYSTRING) return;

    memset(&msgBoxPars, 0, sizeof(msgBoxPars));

    msgBoxPars.permanent = permanent;
    msgBoxPars.numLines  = 1;
    msgBoxPars.width     = -1;
    msgBoxPars.text      = OSD_GetStr(msg);

    if(msgBoxPars.text.chr != NULL)
    {
        FAPI_SYS_PRINT_DEBUG(1,"[MSG] %s\n",msgBoxPars.text.chr);
        (void)MAIN_MsgBoxShow(&(appDat->msgBox), &msgBoxPars);
    }
}

#endif

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
