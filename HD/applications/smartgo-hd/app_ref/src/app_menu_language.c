/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_menu_language.c
**
** \brief       OSD Language menu.
**
** Detail description. [\ref app_smartgo_app_ref_language]
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
** - Info    713: loss of precision
** - Info    715: symbol 'anySymb' not referenced
** - Info    732: Loss of sign (assignment) (int to unsigned short).
** - Info    737: loss of sign in promotion from int to unsigned int
** - Info    774: Boolean within 'if' always evaluates to True.
** - Note    961: Violates MISRA 2004 Advisory Rule 12.1,
**                dependence placed on C's operator precedence;
**
*****************************************************************************
*/
/*lint -save -e641 -e656 -e713 -e715 -e732 -e737 -e774 -e961 */
#define DEBUG 0

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "app_menu.h"

    SYS_STRING_S    OSD_LANG_GetLanguageString       (SYS_LANGCODE langCode);
    SYS_LANGCODE    OSD_LANG_GetKnownLangCodeByIndex (uint16_t index);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

// #define __USE_PREPAIRED_MENU_SUBTITLE_ENTRY__
/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

enum
{
    MENU_LANGUAGE_ID_TITLE = 0,
    MENU_LANGUAGE_ID_LIST,
    MENU_LANGUAGE_ID_HELPLIST
};

enum
{
    MENU_LANGUAGE_ID_ENTRY_OSD = 0,
    MENU_LANGUAGE_ID_ENTRY_AUDIO1,
    MENU_LANGUAGE_ID_ENTRY_AUDIO2,
    #if 1//(defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
    MENU_LANGUAGE_ID_ENTRY_SUBT1,
    MENU_LANGUAGE_ID_ENTRY_SUBT2,
    #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) end */
    MENU_LANGUAGE_ID_ENTRY_NUMS //5
};


typedef struct
{
    FAPI_SYS_HandleT    pnlHdl;
    FAPI_SYS_HandleT    listHdl;
    FAPI_SYS_HandleT    listHelpHdl;
    int fill_12; //12
    //16
}MENU_LANGUAGE_INST_S;

FSTATIC MENU_LANGUAGE_INST_S* menuLanguageDat = NULL;

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
FSTATIC fbool_t MENU_LanguageLeave             (FAPI_SYS_HandleT h, fbool_t force);

FSTATIC fbool_t MENU_LanguageOnSelect          (FAPI_SYS_HandleT h, int32_t itemId);
FSTATIC void  MENU_LanguageValChg            (FAPI_SYS_HandleT h,
                                              int32_t itemId,
                                              FGS_VAL_S newVal);
FSTATIC void  MENU_LanguageGetItem           (FAPI_SYS_HandleT h,
                                              int32_t id,
                                              uint32_t index,
                                              FGS_ITEMSTATE_E state,
                                              FGS_ITEM_S* item);
FSTATIC void  MENU_LanguageGetDescrItem      (FAPI_SYS_HandleT h,
                                              int32_t id,
                                              uint32_t index,
                                              FGS_ITEMSTATE_E state,
                                              FGS_ITEM_S* item);
FSTATIC void MENU_LanguageGetHelpDescrItem   (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                              FGS_ITEMSTATE_E state,
                                              FGS_ITEM_S* item);
/*FSTATIC*/ fbool_t MENU_LanguageBuild           (FAPI_SYS_HandleT h);
FSTATIC void    MENU_LanguageOnFocusChg      (FAPI_SYS_HandleT h, uint8_t index, int32_t id);
FSTATIC void    MENU_LanguageOnFocusSet      (FAPI_SYS_HandleT h, fbool_t hasFocus);



/*!
*******************************************************************************
**
** \brief  Initial function for the OSD Language Menu
**
** \return FAPI_OK
**
******************************************************************************/
/* 21b27858 - complete */
int32_t MENU_LanguageInit (void)
{
    if ( menuLanguageDat != NULL ) return APPL_SMARTGO_ERR_ALREADY_INITIALIZED;

    menuLanguageDat = /*UTILS_Malloc*/SYS_MemoryAllocate(sizeof(MENU_LANGUAGE_INST_S));
    if ( menuLanguageDat == NULL ) return APPL_SMARTGO_ERR_OUT_OF_MEMORY;

    memset(menuLanguageDat, 0, sizeof(MENU_LANGUAGE_INST_S));

    return FAPI_OK;
}


/*!
*******************************************************************************
**
** \brief  Entry function.
**
** \param h      Address of menu handle.
** \param test   entry test.
**
** \return FTRUE
**
******************************************************************************/
/* 21b277dc - complete */
fbool_t MENU_LanguageEntry (FAPI_SYS_HandleT h, fbool_t test)
{
    MENU_LANGUAGE_INST_S* inst = menuLanguageDat;
    uint32_t                   lastFocusItem;

    if ( test == FTRUE ) return FTRUE;

    (void)MENU_LanguageBuild((FAPI_SYS_HandleT)inst);

    if ( MENUSTACK_GetData(&lastFocusItem) == FFALSE )
    {
        lastFocusItem = MENU_LANGUAGE_ID_ENTRY_OSD;
    }

    /* set list focus on first item */
    (void)FGS_LIST_SetMemberFocus  (inst->listHdl, lastFocusItem);
    (void)FGS_PANEL_SetMemberFocus (inst->pnlHdl, MENU_LANGUAGE_ID_LIST);
    (void)MENUSTACK_FocusClaim     ((int32_t)/*MENUID_LANGUAGE*/8);
    /* turn visibility on */
    (void)FGS_PANEL_Show           (inst->pnlHdl, FFALSE);

    MENUSTACK_SetCleanup((MENUSTACK_CLEANUP)MENU_LanguageLeave,
                         (FAPI_SYS_HandleT)inst);

    return FTRUE;
}


/*!
*******************************************************************************
**
** \brief  This function is call when the menu gets/lose the panel focus.
**
** \param h        Address of menu handle.
** \param hasFocus If the menu has focus or not.
**
******************************************************************************/
/* 21b27784 - complete */
FSTATIC void MENU_LanguageOnFocusSet (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
/*175*/    DBG_Assert(((MENU_LANGUAGE_INST_S*)h)->pnlHdl != NULL);

    MAIN_HandleExitKeys(hasFocus);
}


/*!
*******************************************************************************
**
** \brief  Activates the help icons for the current menu list item.
**
** \param h        Address of menu handle.
** \param index    unused.
** \param id       List id gets focus.
**
******************************************************************************/
/* 21b27744 - complete */
FSTATIC void MENU_LanguageOnFocusChg (FAPI_SYS_HandleT h, uint8_t index, int32_t id)
{
    MENU_LANGUAGE_INST_S*  inst = (MENU_LANGUAGE_INST_S*)h;
    FGS_LNAVI_PARAMS_S     naviParams;

    if ( FGS_LNAVI_GetParams(inst->listHelpHdl, &naviParams) == FAPI_OK )
    {
        naviParams.index = id;

        (void)FGS_LNAVI_SetParams(inst->listHelpHdl, &naviParams);
    }
}


/*!
*******************************************************************************
**
** \brief  Leave the Scan Menu.
**
** More detailed description
**
** \param h        Address of menu handle.
** \param force    .
**
** \return FTRUE
******************************************************************************/
/* 21b27704 - complete */
FSTATIC fbool_t MENU_LanguageLeave (FAPI_SYS_HandleT h, fbool_t force)
{
    MENU_LANGUAGE_INST_S* inst = (MENU_LANGUAGE_INST_S*)h;

    if ( force == FFALSE )
    {
        MAIN_SaveSettingsIfChanged();
    }
    if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

    (void)MENUSTACK_FocusRelease ((int32_t)/*MENUID_LANGUAGE*/8);

    inst->pnlHdl = NULL;
    return FTRUE;
}


/*!
*******************************************************************************
**
** \brief  Handles the OK-key for the selected Listitem.
**
** \param h        Address of menu handle.
** \param itemId   Listitem Id.
**
** \return FTRUE
**         FFALSE
******************************************************************************/
/* 21b275ec - complete */
FSTATIC fbool_t MENU_LanguageOnSelect (FAPI_SYS_HandleT h, int32_t itemId)
{
    MENU_LANGUAGE_INST_S*    inst = (MENU_LANGUAGE_INST_S*)h;
    MENUSTACK_ENTRY          newEntry = NULL;
    FAPI_SYS_HandleT                arg = NULL;
    uint8_t                       subLines;
    MENU_SELECTLIST_OPEN_S   selectLst; //sp
    FGS_ITEM_SEL_PARAMS_S    selParams; //sp60
    FGS_LOC_S                memberLoc; //sp68
    fbool_t                    openSelectLst = FFALSE;

    switch ( itemId )
    {
        case MENU_LANGUAGE_ID_ENTRY_OSD:
            openSelectLst = FTRUE;
            subLines = 3; //2;
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO1:
            openSelectLst   = FTRUE;
            subLines        = 5; //2;
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO2:
            openSelectLst = FTRUE;
            subLines = 5; //2;
        break;
        #if 1//(defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
        case     MENU_LANGUAGE_ID_ENTRY_SUBT1  :
            openSelectLst   = FTRUE;
            subLines = 5; //2;
        break;
        case     MENU_LANGUAGE_ID_ENTRY_SUBT2  :
            openSelectLst = FTRUE;
            subLines = 5; //2;
        break;
        #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) end */

        default:
            return FFALSE;
    }

    if ( openSelectLst )
    {
        memset(&memberLoc, 0, sizeof(memberLoc));
        memset(&selectLst, 0, sizeof(selectLst));
        memset(&selParams, 0, sizeof(selParams));

        (void)FGS_LIST_GetMemberAbsPos (inst->listHdl, itemId, &(memberLoc));
        (void)FGS_LIST_GetMemberParams (inst->listHdl, itemId, &selParams);

        selectLst.pos.width     = SCALER_GetCurrVal(SUB_LIST_WIDTH);
        selectLst.pos.height    = 0; /* is calculated internally */
        selectLst.pos.x         = memberLoc.x + SCALER_GetCurrVal(MAIN_WIDTH) -
                                  selectLst.pos.width;
        selectLst.pos.y         = memberLoc.y;
        selectLst.pos.alignment = FGS_ALIGN_HOR_LEFT | FGS_ALIGN_VER_TOP;
        selectLst.id            = itemId;
        selectLst.numVisLines   = subLines;
        selectLst.numItems      = selParams.numItems;
        selectLst.index         = selParams.index;
        selectLst.getItem       = MENU_LanguageGetItem;
        selectLst.getItemArg    = h;
        selectLst.onSelect      = MENU_CommonSelectListSelected;
        selectLst.onSelectArg   = inst->listHdl;
        selectLst.onExit        = NULL;
        selectLst.onExitArg     = NULL;

        return MENU_SelectListOpen(&(appDat->Data_15772/*selectLstInst*/), &selectLst);
    }
    else
    {
        /* store last focus */
        MENUSTACK_SetData(itemId);
        if( newEntry == NULL) return FFALSE;
        else                  return MENUSTACK_Up(newEntry, arg);
    }
}


/*!
*******************************************************************************
**
** \brief  Handles the Value change for the selected Listitem.
**
** \param h        Address of menu handle.
** \param itemId   Listitem Id.
** \param newVal   New Value for Listitem.
**
******************************************************************************/
/* 21b273c4 - complete */
FSTATIC void MENU_LanguageValChg (FAPI_SYS_HandleT h, int32_t itemId, FGS_VAL_S newVal)
{
//    FAPI_SYS_PRINT_MSG("MENU_LanguageValChg: TODO\n");

    SYS_LANGCODE landID;
    struct
    {
        int Data_0; //0
        int Data_4; //4
    } sp;
    uint32_t r7;

    switch ( itemId )
    {
        case MENU_LANGUAGE_ID_ENTRY_OSD :
            //21b273f8
            (void)OSD_LANG_Select(newVal.number);

            OSD_LANG_GetLangInfo(newVal.number, &landID);
            r7 = OSD_LANG_GetKnownLangIndex(landID);
            SETTINGS_AudioLangPrefSet(0, landID);
            SETTINGS_UILangPrefSet(0, landID);

            sp.Data_0 = 0;
            sp.Data_4 = 0;

            if (0 == FGS_LIST_GetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 1, &sp))
            {
                //21b275d4
                sp.Data_4 = r7;
                FGS_LIST_SetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 1, &sp);
            }
            //21b27458
            SETTINGS_AudioLangPrefSet(1, landID);
            SETTINGS_UILangPrefSet(1, landID);

            sp.Data_0 = 0;
            sp.Data_4 = 0;

            if (0 == FGS_LIST_GetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 2, &sp))
            {
                //21b275bc
                sp.Data_4 = r7;
                FGS_LIST_SetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 2, &sp);
            }
            //21b27490
            SETTINGS_SubtLangPrefSet(0, landID);

            sp.Data_0 = 0;
            sp.Data_4 = 0;

            if (0 == FGS_LIST_GetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 3, &sp))
            {
                //0x21b275a4
                sp.Data_4 = r7;
                FGS_LIST_SetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 3, &sp);
            }
            //21b274bc
            SETTINGS_SubtLangPrefSet(1, landID);

            sp.Data_0 = 0;
            sp.Data_4 = 0;

            if (0 == FGS_LIST_GetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 4, &sp))
            {
                //0x21b2758c
                sp.Data_4 = r7;
                FGS_LIST_SetMemberParams(((MENU_LANGUAGE_INST_S*)h)->listHdl, 4, &sp);
            }
            //0x21b274e8
            (void)FGS_PANEL_Refresh ( ((MENU_LANGUAGE_INST_S*)h)->pnlHdl, NULL);
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO1:
            (void)SETTINGS_AudioLangPrefSet (0, OSD_LANG_GetKnownLangCodeByIndex
                                          (newVal.number));
            (void)SETTINGS_UILangPrefSet    (0, OSD_LANG_GetKnownLangCodeByIndex
                                          (newVal.number));
//            (void)AV_UpdateAudioSelect();
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO2:
            (void)SETTINGS_AudioLangPrefSet (1, OSD_LANG_GetKnownLangCodeByIndex
                                          (newVal.number));
            (void)SETTINGS_UILangPrefSet    (1, OSD_LANG_GetKnownLangCodeByIndex
                                          (newVal.number));
//            (void)AV_UpdateAudioSelect();
            break;

        #if 1//(defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
        case MENU_LANGUAGE_ID_ENTRY_SUBT1:
            (void)SETTINGS_SubtLangPrefSet (0, OSD_LANG_GetKnownLangCodeByIndex
                                          (newVal.number));
//            (void)AV_UpdateSubttSelect();
            break;

        case MENU_LANGUAGE_ID_ENTRY_SUBT2:
            (void)SETTINGS_SubtLangPrefSet (1, OSD_LANG_GetKnownLangCodeByIndex
                                          (newVal.number));
//            (void)AV_UpdateSubttSelect();
            break;
        #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) end */

        default:
            break;
    }
}


/*!
*******************************************************************************
**
** \brief  Set the descriptions for each listitem.
**
** \param h        Address of menu handle.
** \param id       Listitem Id.
** \param index    Current index of listitem.
** \param state    Status of listitem.
** \param item     Pointer on listitem.
******************************************************************************/
/* 21b26bcc - complete */
FSTATIC void MENU_LanguageGetDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                      FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    uint32_t strIdx;

    item->item.str.font       = MAIN_FONT;
    item->align               = FGS_ALIGN_HOR_LEFT
                             | FGS_ALIGN_VER_CENTER;
    item->type                = FGS_ITEM_TYPE_STRING;
    item->item.str.lineHeight = 0;

    switch ( id )
    {
        case MENU_LANGUAGE_ID_ENTRY_OSD:
            strIdx = STR_ENTRY_LANGUAGE_OSD;
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO1:
            strIdx = STR_ENTRY_LANGUAGE_AUDIO1;
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO2:
            strIdx = STR_ENTRY_LANGUAGE_AUDIO2;
            break;

        #if 1 //(defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)

        case MENU_LANGUAGE_ID_ENTRY_SUBT1:
            strIdx = STR_ENTRY_LANGUAGE_SUBT1;
            break;

        case MENU_LANGUAGE_ID_ENTRY_SUBT2:
            strIdx = STR_ENTRY_LANGUAGE_SUBT2;
            break;

        #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) */

        default:
            return;
    }

//    MENU_COMMON_ITEM_MENUSTR(item, strIdx, state);
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


/* 21b273ac - complete */
FSTATIC void MENU_LanguageGetHelpDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                            FGS_ITEMSTATE_E state,
                                            FGS_ITEM_S* item)
{
    uint32_t strIdx;

    switch ( index )
    {
        case MENU_LANGUAGE_ID_ENTRY_OSD    :
        case MENU_LANGUAGE_ID_ENTRY_AUDIO1 :
        case MENU_LANGUAGE_ID_ENTRY_AUDIO2 :
        #if 1//(defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
        case MENU_LANGUAGE_ID_ENTRY_SUBT1  :
        case MENU_LANGUAGE_ID_ENTRY_SUBT2  :
        #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) end */
            strIdx = STR_ENTRY_LOKR;
            break;

        default:  return;
    }

    MENU_CommonSetHelpDescrParams(item, state, strIdx);
}

/*!
*******************************************************************************
**
** \brief  Set the value (e.g. text, number, icon, ...) for each listitem.
**
** \param h        Address of menu handle.
** \param id       Listitem Id.
** \param index    Current index of listitem.
** \param state    Status of listitem.
** \param item     Pointer on listitem.
******************************************************************************/
/* 21b272a8 - complete */
FSTATIC void MENU_LanguageGetItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                   FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    SYS_LANGCODE landID;
    SYS_LANGCODE prefLang;

    switch ( id )
    {
        case MENU_LANGUAGE_ID_ENTRY_OSD:
            (void)OSD_LANG_GetLangInfo (index, &landID);
            item->item.str.chr = OSD_LANG_GetLanguageString(landID);
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO1:
            prefLang = OSD_LANG_GetKnownLangCodeByIndex(index);
            item->item.str.chr = OSD_LANG_GetLanguageString(prefLang);
            break;

        case MENU_LANGUAGE_ID_ENTRY_AUDIO2:
            prefLang = OSD_LANG_GetKnownLangCodeByIndex(index);
            item->item.str.chr = OSD_LANG_GetLanguageString(prefLang);
            break;

        #if 1//(defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)

        case MENU_LANGUAGE_ID_ENTRY_SUBT1:
            prefLang = OSD_LANG_GetKnownLangCodeByIndex(index);
                item->item.str.chr = OSD_LANG_GetLanguageString(prefLang);
            break;

        case MENU_LANGUAGE_ID_ENTRY_SUBT2:
            prefLang = OSD_LANG_GetKnownLangCodeByIndex(index);
            item->item.str.chr = OSD_LANG_GetLanguageString(prefLang);
            break;
        #endif /* (defined APPL_SUBTT_ENABLED) || defined APPL_TTXT_ENABLED) end */

        default:  return;
    }

    item->type                = FGS_ITEM_TYPE_STRING;
    item->align               = FGS_ALIGN_HOR_RIGHT | FGS_ALIGN_VER_CENTER;
    item->item.str.font       = MAIN_FONT;
    item->item.str.lineHeight = 0;

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


/*!
*******************************************************************************
**
** \brief  Builds the menu pannel and its members.
**
** \param h        Address of menu handle.
**
** \return FTRUE
**         FFALSE
******************************************************************************/
/* 21b26cd8 - todo */
/*FSTATIC*/ fbool_t MENU_LanguageBuild(FAPI_SYS_HandleT h)
{
    MENU_LANGUAGE_INST_S* inst = (MENU_LANGUAGE_INST_S*)h;
    FGS_PANEL_OPEN_S      pnlPars;
    FGS_LIST_OPEN_S       listPars;
    FAPI_SYS_HandleT      itemHdl;
    FGS_ITEM_SEL_OPEN_S   selPars;
    FGS_POS_S             itemPos;
    FGS_POS_S             valuePos;
    FGS_POS_S             descrPos;
    SYS_LANGCODE          prefLang;
    int32_t               retVal;
    uint16_t              helpWidth;
    uint16_t              stackedFrameWidth;
    uint16_t              innerHeight;
    uint32_t              numLines = MENU_LANGUAGE_ID_ENTRY_NUMS;
    uint16_t width;
#if 0
    uint16_t contentWidth;
    uint16_t lr;
#endif

    memset (&pnlPars, 0, sizeof(pnlPars));
    memset (&listPars, 0, sizeof(listPars));
    memset(&itemPos, 0, sizeof(FGS_POS_S));
    memset(&descrPos, 0, sizeof(FGS_POS_S));
    memset(&valuePos, 0, sizeof(FGS_POS_S));

    helpWidth         = 2*SCALER_GetCurrVal(HELP_LR_PADDING) +
                          OSD_GetStrWidth(OSD_GetStr(STR_ENTRY_LOKR),
                                   -1,SYMBOL_FONT);
    innerHeight       = numLines
                      * (SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                       + SCALER_GetCurrVal(LIST_LINE_PADDING));

    do
    {
//        memset (&pnlPars, 0, sizeof(pnlPars));

        MENU_CommonSetParamsTitleWHelp (&pnlPars, SCALER_GetCurrVal(MAIN_WIDTH),
                                        innerHeight, helpWidth,
                                        1, &stackedFrameWidth);

        pnlPars.onFocusSet      = MENU_LanguageOnFocusSet;
        pnlPars.onFocusSetArg   = (FAPI_SYS_HandleT)inst;

        pnlPars.pInst = appDat;

        MENU_CommonSetPanelPos(&(pnlPars.pos));

        retVal = FGS_PANEL_Open(&pnlPars, /*MENUID_LANGUAGE*/8, &(inst->pnlHdl));
        if ( retVal != FAPI_OK ) break;

        /* ----- create textbox holding title ------------------------------ */

        retVal = MENU_CommonAddTitle(MENU_LANGUAGE_ID_TITLE,
                                     inst->pnlHdl, pnlPars.pos.width,
                                     stackedFrameWidth, STR_TITLE_LANGUAGE,
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
        listPars.bkgrType = 1;
        listPars.topDownOriented = 1;
        listPars.wraparound = 1;


        listPars.getDescrItem    = MENU_LanguageGetDescrItem;
        listPars.getDescrItemArg = (FAPI_SYS_HandleT)inst;
        listPars.getItem         = MENU_LanguageGetItem;
        listPars.getItemArg      = (FAPI_SYS_HandleT)inst;
        listPars.onFocusChg      = MENU_LanguageOnFocusChg;
        listPars.onFocusChgArg   = (FAPI_SYS_HandleT)inst;
        listPars.onSelect        = MENU_LanguageOnSelect;
        listPars.onSelectArg     = (FAPI_SYS_HandleT)inst;
        listPars.onValChg        = MENU_LanguageValChg;
        listPars.onValChgArg     = (FAPI_SYS_HandleT)inst;

        listPars.pInst = &appDat->Data_2456;

#if 0
        inst->listHdl = MENU_CommonAddList (&listPars, MENU_LANGUAGE_ID_LIST,
                                            stackedFrameWidth, 0,
                                            SCALER_GetCurrVal(MAIN_WIDTH),
                                            innerHeight, inst->pnlHdl,
                                            &itemPos, &descrPos, &valuePos, 75,
                                            &retVal);
        if ( inst->listHdl == NULL ) break;
#else
        retVal = FGS_LIST_Open(&listPars, MENU_LANGUAGE_ID_LIST, inst->pnlHdl, &inst->listHdl);
        if ( retVal != FAPI_OK ) break;
#endif

        itemPos.x = 0;
        itemPos.y = 0;
        itemPos.width = listPars.pos.width;
        itemPos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        itemPos.alignment = 0;

        width = 3 * (itemPos.width - SCALER_GetCurrVal(MAIN_LEFT_PADDING)
                             - SCALER_GetCurrVal(MAIN_RIGHT_PADDING));

        descrPos.x = SCALER_GetCurrVal(MAIN_LEFT_PADDING);
        descrPos.y = 0;
        descrPos.width = width / 4;
        descrPos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        descrPos.alignment = 0;

        valuePos.x = descrPos.x + descrPos.width;
        valuePos.y = 0;
        valuePos.width = itemPos.width -
                descrPos.width -
                SCALER_GetCurrVal(MAIN_LEFT_PADDING) -
                SCALER_GetCurrVal(MAIN_RIGHT_PADDING);
        valuePos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        valuePos.alignment = 0;

        /* --- OSD Language --------------------------------------------*/

        selPars.pos                 = itemPos;
        selPars.bkgrType            = 0; //OSD_LSTITEM_BKGR_NORMAL;
        selPars.descrPos            = descrPos;
        selPars.valuePos            = valuePos;
        selPars.params.numItems     = OSD_LANG_GetNumberOfLangs ();
        selPars.params.index        = OSD_LANG_GetLangCurr ();

        retVal = FGS_ITEM_SEL_Open (&selPars,
                                    MENU_LANGUAGE_ID_ENTRY_OSD,
                                    inst->listHdl,
                                    &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- Audio language 1 ------------------------------------------------*/

        prefLang = LANG_NOTSPECIFIED;

        (void)SETTINGS_AudioLangPrefGet   (0, &prefLang);

        selPars.pos                 = itemPos;
        selPars.params.numItems     = 135; //KNOWN_LANG_NUMS;
        selPars.params.index        = OSD_LANG_GetKnownLangIndex(prefLang);

        retVal = FGS_ITEM_SEL_Open (&selPars,
                                    MENU_LANGUAGE_ID_ENTRY_AUDIO1,
                                    inst->listHdl,
                                    &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- Audio language 2 ---------------------------------------------*/

        prefLang = LANG_NOTSPECIFIED;

        (void)SETTINGS_AudioLangPrefGet   (1, &prefLang);

        selPars.pos                 = itemPos;
        selPars.params.numItems     = 135; //KNOWN_LANG_NUMS;
        selPars.params.index        = OSD_LANG_GetKnownLangIndex(prefLang);

        retVal = FGS_ITEM_SEL_Open (&selPars, MENU_LANGUAGE_ID_ENTRY_AUDIO2,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- Subtitle language 1 ------------------------------------------------*/
//        #if (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
        prefLang = LANG_NOTSPECIFIED;

        (void)SETTINGS_SubtLangPrefGet   (0, &prefLang);

        selPars.pos                 = itemPos;
        selPars.params.numItems     = 135; //KNOWN_LANG_NUMS;
        selPars.params.index        = OSD_LANG_GetKnownLangIndex(prefLang);

        retVal = FGS_ITEM_SEL_Open (&selPars,
                                    MENU_LANGUAGE_ID_ENTRY_SUBT1,
                                    inst->listHdl,
                                    &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- Subtitle language 2 ---------------------------------------------*/

        prefLang = LANG_NOTSPECIFIED;

        (void)SETTINGS_SubtLangPrefGet   (1, &prefLang);

        selPars.pos                 = itemPos;
        selPars.params.numItems     = 135; //KNOWN_LANG_NUMS;
        selPars.params.index        = OSD_LANG_GetKnownLangIndex(prefLang);

        retVal = FGS_ITEM_SEL_Open (&selPars, MENU_LANGUAGE_ID_ENTRY_SUBT2,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT) + SCALER_GetCurrVal(LIST_LINE_PADDING);
//        #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) end */

        /* ----- Create help list ------------------------------------------ */

        inst->listHelpHdl = MENU_CommonAddHelpList(MENU_LANGUAGE_ID_HELPLIST,
                                        inst->pnlHdl, stackedFrameWidth,
                                        SCALER_GetCurrVal(MAIN_WIDTH),
                                        listPars.pos.y, helpWidth, numLines,
                                        MENU_LanguageGetHelpDescrItem,
                                        (FAPI_SYS_HandleT)inst);
        if ( inst->listHelpHdl == NULL )
        {
            retVal = -1; //SMARTGO_APPL_ERR_INTERNAL;
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
        return FFALSE;
    }

    return FTRUE;
}


/******************************************************************************/
/*lint -restore */
/* END OF FILE */
