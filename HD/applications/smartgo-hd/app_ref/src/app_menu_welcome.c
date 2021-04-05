/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_menu_welcome.c
**
** \brief       OSD Welcome Screen menu.
**
** Detail description. [\ref app_smartgo_app_ref_welcome]
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
** - Warning 641: Converting enum 'anyEnum' to int
** - Info    713: Loss of precision (assignment) (unsigned int to short).
** - Info    715: Symbol not referenced.
** - Info    732: Loss of sign (assignment) (int to unsigned short).
** - Info    737: Loss of sign in promotion from int to unsigned int.
** - Note    961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**                C's operator precedence.
**
*****************************************************************************
*/
/*lint -save -e641 -e713 -e715 -e732 -e737 -e961 */
#define DEBUG 0

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "app_menu.h"

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

enum
{
    MENU_WELCOME_ID_TITLE = 0,
    MENU_WELCOME_ID_LIST,
    MENU_WELCOME_ID_HELPLIST
};

enum
{
    MENU_WELCOME_ID_ENTRY_LANGUAGE = 0,
    MENU_WELCOME_ID_ENTRY_TIME,
    MENU_WELCOME_ID_ENTRY_ANTENNA,
    MENU_WELCOME_ID_ENTRY_NUMS
};

typedef struct
{
    FAPI_SYS_HandleT    pnlHdl;
    FAPI_SYS_HandleT    listHdl;
    FAPI_SYS_HandleT    listHelpHdl;

}MENU_WELCOME_INST_S;

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
FSTATIC MENU_WELCOME_INST_S* menuWelcomeDat = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
FSTATIC fbool_t MENU_WelcomeLeave           (FAPI_SYS_HandleT h,
                                             fbool_t force);
FSTATIC fbool_t MENU_WelcomeOnSelect        (FAPI_SYS_HandleT h,
                                             int32_t itemId);
FSTATIC void    MENU_WelcomeGetDescrItem    (FAPI_SYS_HandleT h,
                                             int32_t id,
                                             uint32_t index,
                                             FGS_ITEMSTATE_E state,
                                             FGS_ITEM_S* item);
FSTATIC void   MENU_WelcomeGetHelpDescrItem (FAPI_SYS_HandleT h,
                                             int32_t id,
                                             uint32_t index,
                                             FGS_ITEMSTATE_E state,
                                             FGS_ITEM_S* item);
/*FSTATIC*/ fbool_t MENU_WelcomeBuild           (FAPI_SYS_HandleT h);
FSTATIC void    MENU_WelcomeOnFocusChg      (FAPI_SYS_HandleT h,
                                             uint8_t index,
                                             int32_t id);
FSTATIC void    MENU_WelcomeOnFocusSet      (FAPI_SYS_HandleT h,
                                             fbool_t hasFocus);
FSTATIC void func_21b3d480(void);

/* 21b3dc70 - complete */
int32_t MENU_WelcomeInit (void)
{
    if ( menuWelcomeDat != NULL ) return APPL_SMARTGO_ERR_ALREADY_INITIALIZED;

    menuWelcomeDat = SYS_MemoryAllocate(sizeof(MENU_WELCOME_INST_S));
    if ( menuWelcomeDat == NULL ) return APPL_SMARTGO_ERR_OUT_OF_MEMORY;

    memset(menuWelcomeDat, 0, sizeof(MENU_WELCOME_INST_S));

    return FAPI_OK;
}


/* 21b3dbe8 - complete */
fbool_t MENU_WelcomeEntry (FAPI_SYS_HandleT h, fbool_t test)
{
    MENU_WELCOME_INST_S* inst = menuWelcomeDat;
    uint32_t                  lastFocusItem;

    func_21bc22b0();
    func_21bc2f14();

    if ( test == FTRUE ) return FTRUE;

    (void)MENU_WelcomeBuild((FAPI_SYS_HandleT)inst);

    if ( MENUSTACK_GetData(&lastFocusItem) == FFALSE )
    {
        lastFocusItem = 0;
    }

    /* set list focus on first item */
    (void)FGS_LIST_SetMemberFocus  (inst->listHdl, lastFocusItem);
    (void)FGS_PANEL_SetMemberFocus (inst->pnlHdl, 1/*MENU_WELCOME_ID_LIST*/);
    (void)MENUSTACK_FocusClaim     ((int32_t)/*MENUID_WELCOME*/3);
    (void)FGS_PANEL_Show           (inst->pnlHdl, FFALSE); /* turn visibility on */

    MENUSTACK_SetCleanup((MENUSTACK_CLEANUP)MENU_WelcomeLeave, (FAPI_SYS_HandleT)inst);

    return FTRUE;
}


/* 21b3db78 - complete */
FSTATIC void MENU_WelcomeOnFocusSet (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
/*134*/    DBG_Assert(((MENU_WELCOME_INST_S*)h)->pnlHdl != NULL);

    if (func_21ba3e64() != 1) //input.c
    {
        return;
    }

    MAIN_HandleExitKeys(hasFocus);
}


/* 21b3db2c - todo */
FSTATIC fbool_t MENU_WelcomeLeave (FAPI_SYS_HandleT h, fbool_t force)
{
    MENU_WELCOME_INST_S* inst = (MENU_WELCOME_INST_S*)h;

    /* clear factory reset flag */
    if ( !force )
    {
        (void)MAIN_UserDataSet(/*USERDAT_FACTORYFLAG*/2, 0);
    }

    if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

    (void)MENUSTACK_FocusRelease ((int32_t)/*MENUID_WELCOME*/3);

    inst->pnlHdl = NULL;

    func_21b7c96c();
    func_21b0f568();

    return FTRUE;
}


/* 21b3daec - complete */
FSTATIC void MENU_WelcomeOnFocusChg (FAPI_SYS_HandleT h, uint8_t index, int32_t id)
{
    MENU_WELCOME_INST_S*   inst = (MENU_WELCOME_INST_S*)h;
    FGS_LNAVI_PARAMS_S     naviParams;

    if ( FGS_LNAVI_GetParams(inst->listHelpHdl, &naviParams) == FAPI_OK )
    {
        naviParams.index = id;

        (void)FGS_LNAVI_SetParams(inst->listHelpHdl, &naviParams);
    }
}


/* 21b3da80 - complete */
FSTATIC fbool_t MENU_WelcomeOnSelect (FAPI_SYS_HandleT h, int32_t itemId)
{
    fbool_t MENU_LanguageEntry(FAPI_SYS_HandleT h, fbool_t test);
    fbool_t MENU_TimeEntry(FAPI_SYS_HandleT h, fbool_t test);
    fbool_t MENU_AntProgEntry(FAPI_SYS_HandleT h, fbool_t test);

    MENUSTACK_ENTRY   newEntry;
//    FAPI_SYS_HandleT         arg = h;

    if (func_21ba3e64() == 0)
    {
        return FFALSE;
    }

    switch ( itemId )
    {
        case MENU_WELCOME_ID_ENTRY_LANGUAGE: //0
            newEntry = MENU_LanguageEntry;
            break;
        case MENU_WELCOME_ID_ENTRY_TIME: //1
            newEntry = MENU_TimeEntry;
            break;
        case MENU_WELCOME_ID_ENTRY_ANTENNA: //2
            newEntry = MENU_AntProgEntry;
            break;
        default:
            return FFALSE;
    }

    /* store last focus */
    MENUSTACK_SetData(itemId);

    return MENUSTACK_Up(newEntry, /*arg*/0);
}


/* 21b3d484 - complete */
FSTATIC void MENU_WelcomeGetDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                    FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    uint32_t    strIdx;

    item->item.str.font       = MAIN_FONT;
    item->align               = FGS_ALIGN_HOR_LEFT
                             | FGS_ALIGN_VER_CENTER;
    item->type                = FGS_ITEM_TYPE_STRING;
    item->item.str.lineHeight = 0;

    switch ( id )
    {
        case MENU_WELCOME_ID_ENTRY_LANGUAGE:
            strIdx = STR_ENTRY_SYSTEMSETUP_LANG; //82
            break;

        case MENU_WELCOME_ID_ENTRY_TIME:
            strIdx = STR_ENTRY_SYSTEMSETUP_TIME; //83
            break;

        case MENU_WELCOME_ID_ENTRY_ANTENNA:
            strIdx = STR_ENTRY_SYSTEMSETUP_ANTENNA; //68
            break;

        default:
            return;
    }

    item->item.str.chr        = OSD_GetStr(strIdx);

    switch ( state )
    {
        default:
        case FGS_NONFOCUS:
            item->item.str.col = appDat->Data_55472/*txtAttr.colNonFocus*/;
            break;

        case FGS_FOCUS:
            item->item.str.col = appDat->Data_55468/*txtAttr.colFocus*/;
            break;

        case FGS_DISABLED:
            item->item.str.col = appDat->Data_55476/*txtAttr.colDisabled*/;
            break;
    }
}


/* 21b3da64 - complete */
FSTATIC void MENU_WelcomeGetHelpDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                           FGS_ITEMSTATE_E state,
                                           FGS_ITEM_S* item)
{
    uint32_t strIdx;

    switch ( index )
    {
        case MENU_WELCOME_ID_ENTRY_LANGUAGE  :
        case MENU_WELCOME_ID_ENTRY_TIME      :
        case MENU_WELCOME_ID_ENTRY_ANTENNA   : strIdx = STR_ENTRY_OK;
                                               break;
        default:                       return;
    }

    MENU_CommonSetHelpDescrParams(item, state, strIdx);
}


/* 21b3d564 - complete */
/*FSTATIC*/ fbool_t MENU_WelcomeBuild(FAPI_SYS_HandleT h)
{
    MENU_WELCOME_INST_S*    inst = (MENU_WELCOME_INST_S*)h;

//    FAPI_SYS_PRINT_MSG("MENU_WelcomeBuild: TODO\n");

    FGS_PANEL_OPEN_S        pnlPars; //sp172
    FGS_LIST_OPEN_S         listPars; //sp40
    FAPI_SYS_HandleT        itemHdl;
    FGS_ITEM_TXT_OPEN_S     txtPars; //sp132
    FGS_POS_S               itemPos; //sp216
    FGS_POS_S               descrPos; //sp204
    int32_t                 retVal;
    uint16_t                helpWidth;
    uint16_t                stackedFrameWidth;
    uint16_t                innerHeight;
    uint32_t                numLines     = MENU_WELCOME_ID_ENTRY_NUMS;

    memset (&pnlPars, 0, sizeof(pnlPars));

    memset (&listPars, 0, sizeof(listPars));

    memset(&txtPars,  0, sizeof(txtPars));

    memset(&itemPos, 0, sizeof(itemPos));
    memset(&descrPos, 0, sizeof(descrPos));

    helpWidth         = 2*SCALER_GetCurrVal(HELP_LR_PADDING) +
                          OSD_GetStrWidth(OSD_GetStr(/*STR_ENTRY_OK*/317),
                                   -1, /*SYMBOL_FONT*/3);
    innerHeight       = numLines * (SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING));

    do
    {
//        memset (&pnlPars, 0, sizeof(pnlPars));

        MENU_CommonSetParamsTitleWHelp (&pnlPars, SCALER_GetCurrVal(MAIN_WIDTH),
                                        innerHeight, helpWidth, 1,
                                        &stackedFrameWidth);

        pnlPars.onFocusSet      = MENU_WelcomeOnFocusSet;
        pnlPars.onFocusSetArg   = (FAPI_SYS_HandleT)inst;
        pnlPars.pInst = appDat; //21f02400

        MENU_CommonSetPanelPos(&(pnlPars.pos));

        retVal = FGS_PANEL_Open(&pnlPars, /*MENUID_WELCOME*/3, &(inst->pnlHdl));
        if ( retVal != FAPI_OK ) break;

        /* ----- create textbox holding title ------------------------------ */

        retVal = MENU_CommonAddTitle (MENU_WELCOME_ID_TITLE,
                                      inst->pnlHdl, pnlPars.pos.width,
                                      stackedFrameWidth, STR_TITLE_WELCOME,
                                      NULL, NULL);
        if ( retVal != FAPI_OK ) break;

        /* ----- create list ----------------------------------------------- */

//        memset (&listPars, 0, sizeof(listPars));

        listPars.pos.x = SCALER_GetCurrVal(OUTER_FRAME_ALL) +
                         stackedFrameWidth;
        listPars.pos.y = SCALER_GetCurrVal(OUTER_FRAME_ALL) +
                         SCALER_GetCurrVal(INNER_FRAME_WIDTH) +
                         SCALER_GetCurrVal(MAIN_TOP_PADDING) +
                         2 * SCALER_GetCurrVal(TITLE_TB_PADDING) +
                         SCALER_GetCurrVal(TITLE_LINE_HEIGHT) +
                         stackedFrameWidth;
        listPars.pos.width = SCALER_GetCurrVal(MAIN_WIDTH);
        listPars.pos.height = innerHeight;
        listPars.pos.alignment = 0;
//        listPars.isHidden = 0;
        listPars.bkgrType = 0;
        listPars.topDownOriented = 1;
        listPars.wraparound = 1;

        listPars.getDescrItem    = MENU_WelcomeGetDescrItem;
        listPars.getDescrItemArg = (FAPI_SYS_HandleT)inst;
        listPars.getItem = 0;
        listPars.getItemArg = 0;
        //onFocusSet
        listPars.onFocusChg      = MENU_WelcomeOnFocusChg;
        listPars.onFocusChgArg   = (FAPI_SYS_HandleT)inst;
        listPars.onSelect        = MENU_WelcomeOnSelect;
        listPars.onSelectArg     = (FAPI_SYS_HandleT)inst;
        listPars.onValChg = func_21b3d480;
        listPars.onValChgArg = (FAPI_SYS_HandleT)inst;

        listPars.pInst = &appDat->Data_2456;

        retVal = FGS_LIST_Open (&listPars, MENU_WELCOME_ID_LIST, inst->pnlHdl, &inst->listHdl);
        if ( retVal != FAPI_OK ) break;

        /* ----- menu lines -------------------------------------- */

        itemPos.x = 0;
        itemPos.y = 0;
        itemPos.width = listPars.pos.width;
        itemPos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        itemPos.alignment = 0;

        descrPos.x = SCALER_GetCurrVal(MAIN_LEFT_PADDING);
        descrPos.y = 0;
        descrPos.width = listPars.pos.width - SCALER_GetCurrVal(MAIN_LEFT_PADDING) - SCALER_GetCurrVal(MAIN_RIGHT_PADDING);
        descrPos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        descrPos.alignment = 0;

        txtPars.bkgrType           = 0; //OSD_LSTITEM_BKGR_NORMAL;
        txtPars.descrPos           = descrPos;
        txtPars.pos                = itemPos;

        /* --- Language settings --------------------------------------------*/

        retVal = FGS_ITEM_TXT_Open (&txtPars, MENU_WELCOME_ID_ENTRY_LANGUAGE,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- Time settings ------------------------------------------------*/

        txtPars.pos = itemPos;
        retVal = FGS_ITEM_TXT_Open (&txtPars, MENU_WELCOME_ID_ENTRY_TIME,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;
        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- Antenna and program setup ------------------------------------*/

        txtPars.pos = itemPos;
        retVal = FGS_ITEM_TXT_Open (&txtPars, MENU_WELCOME_ID_ENTRY_ANTENNA,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;
        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* ----- Create help list ------------------------------------------ */

        inst->listHelpHdl = MENU_CommonAddHelpList(MENU_WELCOME_ID_HELPLIST,
                                        inst->pnlHdl, stackedFrameWidth,
                                        SCALER_GetCurrVal(MAIN_WIDTH), listPars.pos.y,
                                        helpWidth, numLines,
                                        MENU_WelcomeGetHelpDescrItem,
                                        (FAPI_SYS_HandleT)inst);
        if ( inst->listHelpHdl == NULL )
        {
            retVal = -1;//SMARTGO_APPL_ERR_INTERNAL;
            break;
        }

        /* -----Bottom help lines ------------------------------------------ */

        retVal = MENU_CommonAddMenuExitHelpLine(stackedFrameWidth +
                                                SCALER_GetCurrVal(OUTER_FRAME_ALL) +
                                                SCALER_GetCurrVal(MAIN_LEFT_PADDING),
                                                - /*(int32_t)*/SCALER_GetCurrVal(OUTER_FRAME_ALL) / 2 -
                                                SCALER_GetCurrVal(HELP_TB_PADDING) -
                                                SCALER_GetCurrVal(HELP_LINE_HEIGHT),
                                                pnlPars.pos.width -
                                                stackedFrameWidth -
                                                2 * SCALER_GetCurrVal(OUTER_FRAME_ALL) -
                                                SCALER_GetCurrVal(MAIN_LEFT_PADDING) -
                                                SCALER_GetCurrVal(MAIN_RIGHT_PADDING),
                                                inst->pnlHdl);
        if ( retVal != FAPI_OK ) break;

    } while ( 0 );

    if ( retVal != FAPI_OK )
    {
        if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

        FAPI_SYS_FREE(inst);
        return FFALSE;
    }

    return FTRUE;
}

#if 0

void MENU_WelcomeRefresh(void)
{
    MENU_WELCOME_INST_S* inst = (MENU_WELCOME_INST_S*)menuWelcomeDat;
    uint32_t             lastFocusItem;

    /* check if Menu is open */
    if ( ( inst == NULL ) || ( inst->pnlHdl == NULL ) ) return;

    if ( MENUSTACK_GetData(&lastFocusItem) == FFALSE )
    {
        lastFocusItem = 0;
    }
    /* ----- close menu panel ------------------------------------------ */
    (void)FGS_PANEL_Close(inst->pnlHdl);

    inst->pnlHdl     = NULL;

    (void)MENUSTACK_FocusRelease ((int32_t)MENUID_WELCOME);

    /* ----- re-open menu panel ---------------------------------------- */
    (void)MENU_WelcomeBuild((FAPI_SYS_HandleT)inst);

    (void)FGS_LIST_SetMemberFocus  (inst->listHdl, lastFocusItem);
    (void)FGS_PANEL_SetMemberFocus (inst->pnlHdl, MENU_WELCOME_ID_LIST);
    (void)MENUSTACK_FocusClaim     ((int32_t)MENUID_WELCOME);
    (void)FGS_PANEL_Show           (inst->pnlHdl, FFALSE);
}

#endif

/* 21b3d480 - complete */
FSTATIC void func_21b3d480(void)
{
    /*empty*/
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
