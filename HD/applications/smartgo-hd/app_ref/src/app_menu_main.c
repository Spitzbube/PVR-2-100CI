/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_menu_main.c
**
** \brief       OSD Main menu.
**
** Detail description. [\ref app_smartgo_app_ref_main]
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
** - Info 732: Loss of sign (assignment) (int to unsigned short).
** - Info 737: Loss of sign in promotion from int to unsigned int.
** - Note 961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**   C's operator precedence.
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
    MENU_MAIN_ID_TITLE,
    MENU_MAIN_ID_LIST,
    MENU_MAIN_ID_HELPLIST
};

enum
{
    MENU_MAIN_ID_ENTRY_INSTALLATION,
    MENU_MAIN_ID_ENTRY_USER_SETUP,
    MENU_MAIN_ID_ENTRY_TIMER_SETUP,
    MENU_MAIN_ID_ENTRY_SYSTEM_SETTINGS,
    MENU_MAIN_ID_ENTRY_COMMON_INTERFACE,
    MENU_MAIN_ID_ENTRY_HDD_USB_APPLICATIONS,

    MENU_MAIN_ID_ENTRY_NUMS = 6
};

typedef struct
{
    FAPI_SYS_HandleT    pnlHdl;
    FAPI_SYS_HandleT    listHdl;
    FAPI_SYS_HandleT    listHelpHdl;

#if 0 //TODO
    MENU_TIME_OPEN_S timePars;
#else
    struct
    {
        int strIdx; //0
        int done; //4
        int next; //8
        int fill_12; //12
        //16
    } timePars;
#endif
    //28
}MENU_MAIN_INST_S;

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
/*FSTATIC*/ MENU_MAIN_INST_S* menuMainDat = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
FSTATIC fbool_t MENU_MainLeave        (FAPI_SYS_HandleT h, fbool_t force);
FSTATIC fbool_t MENU_MainOnSelect     (FAPI_SYS_HandleT h, int32_t itemId);
FSTATIC void    MENU_MainGetDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                       FGS_ITEMSTATE_E state, FGS_ITEM_S* item);
/*FSTATIC*/ fbool_t MENU_MainBuild        (FAPI_SYS_HandleT h);
FSTATIC void    MENU_MainOnFocusChg   (FAPI_SYS_HandleT h, uint8_t index, int32_t id);
FSTATIC fbool_t MENU_MainSetupReq     (MENU_MAIN_INST_S* inst);
FSTATIC fbool_t MENU_MainSetupAuthorized (MENU_MAIN_INST_S* inst);
FSTATIC void    MENU_MainOnFocusSet   (FAPI_SYS_HandleT h, fbool_t hasFocus);
FSTATIC void    MENU_MainGetHelpDescrItem (FAPI_SYS_HandleT h,
                                           int32_t id,
                                           uint32_t index,
                                           FGS_ITEMSTATE_E state,
                                           FGS_ITEM_S* item);
FSTATIC void func_21b278b4();
FSTATIC void func_21b278b0();

#ifdef APPL_PARENTAL_ENABLED
FSTATIC void  MENU_MainSetupOnPinEnter (void* arg, const char_t* pin, uint8_t numChars);
#endif /* APPL_PARENTAL_ENABLED */


/* 21b28894 - complete */
int32_t MENU_MainInit (void)
{
    if ( menuMainDat != NULL ) return APPL_SMARTGO_ERR_ALREADY_INITIALIZED;

    menuMainDat = /*UTILS_Malloc*/SYS_MemoryAllocate(sizeof(MENU_MAIN_INST_S));
    if ( menuMainDat == NULL ) return APPL_SMARTGO_ERR_OUT_OF_MEMORY;

    memset(menuMainDat, 0, sizeof(MENU_MAIN_INST_S));

    return FAPI_OK;
}


/* 21b28818 - complete */
fbool_t MENU_MainEntry (FAPI_SYS_HandleT h, fbool_t test)
{
    MENU_MAIN_INST_S* inst = menuMainDat;
    uint32_t               lastFocusItem;

    if ( test == FTRUE )
    {
        return FTRUE;
    }

    (void)MENU_MainBuild((FAPI_SYS_HandleT)inst);

    if ( MENUSTACK_GetData(&lastFocusItem) == FFALSE )
    {
        lastFocusItem = 0;
    }

    /* set list focus on first item */
    (void)FGS_LIST_SetMemberFocus  (inst->listHdl, lastFocusItem);
    (void)FGS_PANEL_SetMemberFocus (inst->pnlHdl, MENU_MAIN_ID_LIST);
    (void)MENUSTACK_FocusClaim     ((int32_t)/*MENUID_MAIN*/2);
    (void)FGS_PANEL_Show           (inst->pnlHdl, FFALSE); /* turn visibility on */

    MENUSTACK_SetCleanup((MENUSTACK_CLEANUP)MENU_MainLeave, (FAPI_SYS_HandleT)inst);

    return FTRUE;
}


/* 21b287c0 - complete */
FSTATIC void MENU_MainOnFocusSet (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
/*173*/    DBG_Assert(((MENU_MAIN_INST_S*)h)->pnlHdl != NULL);

    MAIN_HandleExitKeys(hasFocus);
}


/* 21b28790 - complete */
FSTATIC fbool_t MENU_MainLeave (FAPI_SYS_HandleT h, fbool_t force)
{
    MENU_MAIN_INST_S*   inst = (MENU_MAIN_INST_S*)h;

    if ( inst->pnlHdl != NULL ) (void)FGS_PANEL_Close(inst->pnlHdl);

    (void)MENUSTACK_FocusRelease ((int32_t)/*MENUID_MAIN*/2);

    inst->pnlHdl = NULL;
    return FTRUE;
}


/* 21b28750 - complete */
FSTATIC void MENU_MainOnFocusChg (FAPI_SYS_HandleT h, uint8_t index, int32_t id)
{
    MENU_MAIN_INST_S*   inst = (MENU_MAIN_INST_S*)h;
    FGS_LNAVI_PARAMS_S  naviParams;

    if ( FGS_LNAVI_GetParams(inst->listHelpHdl, &naviParams) == FAPI_OK )
    {
        naviParams.index = id;

        (void)FGS_LNAVI_SetParams(inst->listHelpHdl, &naviParams);
    }
}


/* 21b279d4 - todo */
void func_21b279d4()
{

}


/* 21b278b8 - todo */
void func_21b278b8()
{

}


/* 21b3f0c4 - todo */
void func_21b3f0c4()
{

}


/* 21b28288 - todo */
void func_21b28288()
{
    PVRSYS_STATUS_S sp8; //sp8 +100

    struct
    {
        int fill_0; //0
        int Data_4; //4
        SYS_STRING_S Data_8; //8
        SYS_STRING_S Data_16; //16
        SYS_STRING_S Data_24; //24
        SYS_STRING_S Data_32; //32
        int fill_40[4]; //40
        void (*Data_56)(); //56
        void (*Data_60)(); //60
        int Data_64; //64
        int Data_68; //68
        //72
    } sp108;

    int sp180; //sp180
    unsigned short sp186; //sp186


    if (func_21bc9394(1) != 0)
    {
        func_21b0c620(&appDat->Data_31872);
    }
    else
    {
        func_21b0c620(&appDat->Data_31872);

        if (PVRSYS_GetStatus(&sp8) != 0)
        {
            return;
        }
        //21b285dc
        int r5 = (sp8.numActiveRecs != 0);

        func_21bbdf60(&sp186);

        FAPI_SYS_PRINT_MSG("[main menu]MENU_MainOnSelect, stopRecNeeded=%d, numActTimers=%d\n", r5, sp186);

        func_21bbc5f4(&sp180, 0, 0);

        if ((r5 == 0) && (sp186 == 0) && (sp180 == 0))
        {
            //21b283f8
            MENUSTACK_Up(func_21b3f0c4, 0);
        }
        else
        {
            //21b28344
            memset(&sp108, 0, sizeof(sp108));

            sp108.Data_4 = 1;
            sp108.Data_8 = OSD_GetStr(1074); //"Warning"
            sp108.Data_16 = OSD_GetStr(1410); //"All recordings will be stopped"
            sp108.Data_24 = OSD_GetStr(1411); //"deactivate all timers and stop all recordings"
            sp108.Data_32 = OSD_GetStr(1412); //"back to main menu"
            sp108.Data_56 = func_21b279d4;
            sp108.Data_60 = func_21b278b8;
            sp108.Data_64 = 0;
            sp108.Data_68 = 0;

            return func_21b0e834(&appDat->Data_19332, &sp108); //MENU_ConfDialogOpen?
        }
    }
}


/* 21b3fecc - todo */
void func_21b3fecc()
{

}


/* 21b64ce8 - todo */
void MENU_TimerProgEntry()
{

}


/* 21b359bc - todo */
void func_21b359bc()
{

}


/* 21b6068c - todo */
void func_21b6068c()
{

}


/* 21b406e0 - todo */
void func_21b406e0()
{

}


/* 21b2842c - todo */
FSTATIC fbool_t MENU_MainOnSelect (FAPI_SYS_HandleT h, int32_t itemId)
{
    MENU_MAIN_INST_S*       inst = (MENU_MAIN_INST_S*)h;
    MENUSTACK_ENTRY         newEntry = NULL;
    FAPI_SYS_HandleT        arg = NULL;

    SYS_STRING_S sp; //sp
    PVRSYS_STATUS_S sp8; //sp8

    struct
    {
        int fill_0; //0
        int Data_4; //4
        SYS_STRING_S Data_8; //8
        SYS_STRING_S Data_16; //16
        SYS_STRING_S Data_24; //24
        SYS_STRING_S Data_32; //32
        int fill_40[4]; //40
        void (*Data_56)(); //56
        void (*Data_60)(); //60
        int Data_64; //64
        int Data_68; //68
        //72
    } sp108;

    struct
    {
        SYS_STRING_S Data_0; //0
        char bData_8; //8
        void (*Func_12)(); //12
        int Data_16; //16
        int Data_20; //20
        int fill_24; //24
        int Data_28; //28
        int fill_32; //32
        int Data_36; //36
        int fill_40; //40
        //44
    } sp180;

    struct
    {
        int fill_0[3]; //0
        int Data_12; //12
        //16
    } sp224;
    int sp240; //sp240
    unsigned short sp246; //sp246

    memset(&sp180, 0, sizeof(sp180));
    memset(&sp224, 0, sizeof(sp224));

    switch ( itemId )
    {
        case MENU_MAIN_ID_ENTRY_INSTALLATION:
            //21b284b4
#if 0
            arg      = (FAPI_SYS_HandleT)1; /* any non-zero value! */
            newEntry = MENU_ViewerEntry;
#endif
            func_21bc8e88(&sp224);

            if (sp224.Data_12 & 1)
            {
                sp180.Data_0 = OSD_GetStr(262); //"Enter Current Pin:"
                sp180.bData_8 = 4;
                sp180.Func_12 = func_21b28288;
                sp180.Data_16 = 0;
                sp180.Data_20 = 0;
                sp180.Data_28 = 0;
                sp180.Data_36 = 0;

                func_21b0c8d0(&appDat->Data_31872, &sp180); //MENU_PinDialogOpen?

                return 1;
            }
            else
            {
                //0x21b285a8
                if (PVRSYS_GetStatus(&sp8) != 0)
                {
                    return;
                }
                //21b285dc
                int r5 = (sp8.numActiveRecs != 0);

                func_21bbdf60(&sp246);

                FAPI_SYS_PRINT_MSG("[main menu]MENU_MainOnSelect, stopRecNeeded=%d, numActTimers=%d\n", r5, sp246);

                func_21bbc5f4(&sp240, 0, 0);

                if ((r5 == 0) && (sp246 == 0) && (sp240 == 0))
                {
                    newEntry = func_21b3f0c4;
                    break;
                }
                else
                {
                    //0x21b28648
                    memset(&sp108, 0, sizeof(sp108));

                    sp108.Data_4 = 1;
                    sp108.Data_8 = OSD_GetStr(1074); //"Warning"
                    sp108.Data_16 = OSD_GetStr(1410); //"All recordings will be stopped"
                    sp108.Data_24 = OSD_GetStr(1411); //"deactivate all timers and stop all recordings"
                    sp108.Data_32 = OSD_GetStr(1412); //"back to main menu"
                    sp108.Data_56 = func_21b279d4;
                    sp108.Data_60 = func_21b278b8;
                    sp108.Data_64 = 0;
                    sp108.Data_68 = 0;

                    return func_21b0e834(&appDat->Data_19332, &sp108); //MENU_ConfDialogOpen?
                }
            }

            break;

        case MENU_MAIN_ID_ENTRY_USER_SETUP:
            //21b28524
            newEntry = func_21b3fecc; //MENU_MediaEntry;
            break;

        case MENU_MAIN_ID_ENTRY_TIMER_SETUP:
            //21b28544
#if 0
            newEntry = MENU_PlayListEntry;
#endif
            if (TIME_IsSync() != 0)
            {
                arg = 0;
                newEntry = MENU_TimerProgEntry;

                FAPI_SYS_PRINT_MSG("\n %s %d ", "app_ref/src/app_menu_main.c", 388);
            }
            else
            {
                extern void MENU_TimeEntry();
                //0x21b285bc
                inst->timePars.strIdx = STR_TIME_MSG_TIMERPROG; //156;
                inst->timePars.done = 0;
                inst->timePars.next = 3/*MENU_TIME_NEXT_TIMERPROG_MENU*/;

                arg = &inst->timePars;
                newEntry = MENU_TimeEntry;
            }
            break;

        case MENU_MAIN_ID_ENTRY_SYSTEM_SETTINGS:
            //21b28584
            newEntry = func_21b359bc;
            break;

        case MENU_MAIN_ID_ENTRY_COMMON_INTERFACE:
            //21b28590
#if 0
            newEntry = MENU_MosaicEntry;
#else
            newEntry = func_21b6068c;
#endif
            break;

        case MENU_MAIN_ID_ENTRY_HDD_USB_APPLICATIONS:
            //21b2859c
#if 0
            newEntry = MENU_StrSelEntry ;
#else
            newEntry = func_21b406e0;
#endif
            break;

#if 0
        case MENU_MAIN_ID_ENTRY_SETUP:
            return MENU_MainSetupReq (inst);

        case MENU_MAIN_ID_ENTRY_INFO:
            newEntry = MENU_InformationEntry;
            break;
#endif

        default:
            MENUSTACK_SetData(itemId);
            return 0;
            break;
    }

    /* store last focus */
    MENUSTACK_SetData(itemId);

    return MENUSTACK_Up (newEntry, arg);
}


/* 21b278bc - complete */
FSTATIC void MENU_MainGetDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                    FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    uint32_t strIdx = 0;

    item->item.str.font       = MAIN_FONT;
    item->align               = FGS_ALIGN_HOR_LEFT
                             | FGS_ALIGN_VER_CENTER;
    item->type                = FGS_ITEM_TYPE_STRING;
    item->item.str.lineHeight = 0;

    switch ( id )
    {
        case MENU_MAIN_ID_ENTRY_INSTALLATION: //0
            strIdx = STR_ENTRY_MAIN_INSTALLATION; //68
            break;

        case MENU_MAIN_ID_ENTRY_USER_SETUP: //1
            strIdx = STR_ENTRY_MAIN_USER_SETUP; //69; //STR_ENTRY_MAIN_MEDIA;
            break;

        case MENU_MAIN_ID_ENTRY_TIMER_SETUP: //2
            strIdx = STR_ENTRY_MAIN_TIMER_SETUP; //63; //STR_ENTRY_MAIN_RECORD;
            break;

        case MENU_MAIN_ID_ENTRY_SYSTEM_SETTINGS: //3
            strIdx = STR_ENTRY_MAIN_SYSTEM_SETTINGS; //70; //STR_ENTRY_MAIN_TIMER;
            break;

        case MENU_MAIN_ID_ENTRY_COMMON_INTERFACE: //4
            strIdx = STR_ENTRY_MAIN_COMMON_INTERFACE; //71; //STR_ENTRY_MAIN_MOSAIC;
            break;

        case MENU_MAIN_ID_ENTRY_HDD_USB_APPLICATIONS: //5
            strIdx = STR_ENTRY_MAIN_HDD_USB_APPLICATIONS; //72; //STR_ENTRY_MAIN_STRSEL;
            break;

        default:
            return;
    }

#if 0
    MENU_COMMON_ITEM_MENUSTR(item, strIdx, state);
#else
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
#endif
}


/* 21b2826c - complete */
FSTATIC void MENU_MainGetHelpDescrItem (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                        FGS_ITEMSTATE_E state, FGS_ITEM_S* item)
{
    uint32_t strIdx;

    switch ( index )
    {
        case MENU_MAIN_ID_ENTRY_INSTALLATION:
        case MENU_MAIN_ID_ENTRY_USER_SETUP:
        case MENU_MAIN_ID_ENTRY_TIMER_SETUP:
        case MENU_MAIN_ID_ENTRY_SYSTEM_SETTINGS:
        case MENU_MAIN_ID_ENTRY_COMMON_INTERFACE:
        case MENU_MAIN_ID_ENTRY_HDD_USB_APPLICATIONS:
            strIdx = STR_ENTRY_OK;
            break;

        default:
            return;
    }

    MENU_CommonSetHelpDescrParams(item, state, strIdx);
}


/* 21b27d1c - complete */
/*FSTATIC*/ fbool_t MENU_MainBuild(FAPI_SYS_HandleT h)
{
    MENU_MAIN_INST_S*   inst = (MENU_MAIN_INST_S*)h;
    FGS_PANEL_OPEN_S    pnlPars; //sp176
    FGS_LIST_OPEN_S     listPars; //sp44
    FAPI_SYS_HandleT    itemHdl; //sp248
    FGS_ITEM_TXT_OPEN_S txtPars; //sp136
    struct
    {
        int fill_0[4];
    } sp208; //sp208
    FGS_POS_S           itemPos; //sp236
    FGS_POS_S           descrPos; //sp224
    int32_t             retVal;
    uint16_t            helpWidth; //sp28
    uint16_t            stackedFrameWidth; //sp254
    uint16_t            innerHeight; //sl
    uint32_t            numLines = MENU_MAIN_ID_ENTRY_NUMS; //6

    memset (&pnlPars, 0, sizeof(pnlPars));
    memset (&listPars, 0, sizeof(listPars));
    memset (&txtPars,  0, sizeof(txtPars));

    memset (&sp208, 0, sizeof(sp208));

    memset (&itemPos, 0, sizeof(itemPos));
    memset (&descrPos, 0, sizeof(descrPos));

    helpWidth         = (2 * SCALER_GetCurrVal(HELP_LR_PADDING))
                      + OSD_GetStrWidth (OSD_GetStr(STR_ENTRY_OK),
                                         -1, SYMBOL_FONT);
    innerHeight       = numLines *
                       (SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                      + SCALER_GetCurrVal(LIST_LINE_PADDING));

    do
    {
//        memset (&pnlPars, 0, sizeof(pnlPars));

        MENU_CommonSetParamsTitleWHelp (&pnlPars, SCALER_GetCurrVal(MAIN_WIDTH),
                                        innerHeight, helpWidth,
                                        1, &stackedFrameWidth);

        pnlPars.onFocusSet      = MENU_MainOnFocusSet;
        pnlPars.onFocusSetArg   = (FAPI_SYS_HandleT)inst;
        pnlPars.pInst = appDat;

        MENU_CommonSetPanelPos(&(pnlPars.pos));

        retVal = FGS_PANEL_Open(&pnlPars, /*MENUID_MAIN*/2, &(inst->pnlHdl));
        if ( retVal != FAPI_OK ) break;

        /* ----- create textbox holding title ------------------------------ */

        retVal = MENU_CommonAddTitle(MENU_MAIN_ID_TITLE,
                                     inst->pnlHdl, pnlPars.pos.width,
                                     stackedFrameWidth, STR_TITLE_MAIN,
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
        listPars.bkgrType = 0; //1;
        listPars.topDownOriented = 1;
        listPars.wraparound = 1;

        listPars.getDescrItem    = MENU_MainGetDescrItem;
        listPars.getDescrItemArg = (FAPI_SYS_HandleT)inst;
        listPars.getItem         = func_21b278b4; //MENU_LanguageGetItem;
        listPars.getItemArg      = (FAPI_SYS_HandleT)inst;
        listPars.onFocusChg      = MENU_MainOnFocusChg;
        listPars.onFocusChgArg   = (FAPI_SYS_HandleT)inst;
        listPars.onSelect        = MENU_MainOnSelect;
        listPars.onSelectArg     = (FAPI_SYS_HandleT)inst;
        listPars.onValChg        = func_21b278b0; //MENU_LanguageValChg;
        listPars.onValChgArg     = (FAPI_SYS_HandleT)inst;

        listPars.pInst = &appDat->Data_2456;

#if 0
        inst->listHdl = MENU_CommonAddList (&listPars, MENU_MAIN_ID_LIST,
                                            stackedFrameWidth, 0,
                                            SCALER_GetCurrVal(MAIN_WIDTH),
                                            innerHeight, inst->pnlHdl,
                                            &itemPos, &descrPos, NULL, 100,
                                            &retVal);
        if ( inst->listHdl == NULL ) break;
#else
        retVal = FGS_LIST_Open (&listPars, MENU_MAIN_ID_LIST, inst->pnlHdl, &inst->listHdl);
        if ( retVal != FAPI_OK ) break;
#endif

        itemPos.x = 0;
        itemPos.y = 0;
        itemPos.width = listPars.pos.width;
        itemPos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        itemPos.alignment = 0;

        descrPos.x = SCALER_GetCurrVal(MAIN_LEFT_PADDING);
        descrPos.y = 0;
        descrPos.width = itemPos.width -
                SCALER_GetCurrVal(MAIN_LEFT_PADDING) -
                SCALER_GetCurrVal(MAIN_RIGHT_PADDING);
        descrPos.height = SCALER_GetCurrVal(LIST_LINE_HEIGHT);
        descrPos.alignment = 0;

        /* ----- menu lines ------------------------------------------------ */

        txtPars.bkgrType           = 0; //OSD_LSTITEM_BKGR_NORMAL;
        txtPars.descrPos           = descrPos;
        txtPars.pos                = itemPos;

        /* --- add VIEWER and MEDIA Menu ----------------------------------- */

        txtPars.pos = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, 0/*MENU_MAIN_ID_ENTRY_INSTALLATION*/,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                  + SCALER_GetCurrVal(LIST_LINE_PADDING);

        txtPars.pos = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, 1/*MENU_MAIN_ID_ENTRY_USER_SETUP*/,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                  + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- add PVR Menu -------------------------------------------------*/

        txtPars.pos = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, 2/*MENU_MAIN_ID_ENTRY_TIMER_SETUP*/,
                                inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                   + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- add Timer Menu -----------------------------------------------*/

        txtPars.pos = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, 3/*MENU_MAIN_ID_ENTRY_SYSTEM_SETTINGS*/,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                   + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- add Mosaic Menu ------------------------------------------------*/

        txtPars.pos = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, 4/*MENU_MAIN_ID_ENTRY_COMMON_INTERFACE*/,
                                inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                   + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* --- add Stream Select Menu ----------------------------------------*/

        txtPars.pos = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, 5/*MENU_MAIN_ID_ENTRY_HDD_USB_APPLICATIONS*/,
                                inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                   + SCALER_GetCurrVal(LIST_LINE_PADDING);

#if 0
        /* --- add Config Menu ---------------------------------------------- */

        txtPars.pos                        = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, MENU_MAIN_ID_ENTRY_SETUP,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                   + SCALER_GetCurrVal(LIST_LINE_PADDING);

        /* -----add Information -------------------------------------------- */

        txtPars.pos                        = itemPos;

        retVal = FGS_ITEM_TXT_Open (&txtPars, MENU_MAIN_ID_ENTRY_INFO,
                                    inst->listHdl, &itemHdl);
        if ( retVal != FAPI_OK ) break;

        itemPos.y += SCALER_GetCurrVal(LIST_LINE_HEIGHT)
                   + SCALER_GetCurrVal(LIST_LINE_PADDING);
#endif

        /* ----- Create help list ------------------------------------------ */

        inst->listHelpHdl = MENU_CommonAddHelpList(MENU_MAIN_ID_HELPLIST,
                                        inst->pnlHdl, stackedFrameWidth,
                                        SCALER_GetCurrVal(MAIN_WIDTH),
                                        listPars.pos.y, helpWidth, numLines,
                                        MENU_MainGetHelpDescrItem,
                                        (FAPI_SYS_HandleT)inst);
        if ( inst->listHelpHdl == NULL )
        {
            retVal = -1; //SMARTGO_APPL_ERR_INTERNAL;
            break;
        }

        /* -----Bottom help lines ------------------------------------------ */

        retVal = MENU_CommonAddMenuExitHelpLine (stackedFrameWidth
                          + SCALER_GetCurrVal(OUTER_FRAME_ALL)
                          + SCALER_GetCurrVal(MAIN_LEFT_PADDING),
                          /*-*/ (/*(int32_t)*/-SCALER_GetCurrVal(OUTER_FRAME_ALL) / 2)
                          - SCALER_GetCurrVal(HELP_TB_PADDING)
                          - SCALER_GetCurrVal(HELP_LINE_HEIGHT),
                            pnlPars.pos.width
                          - stackedFrameWidth
                          - (2 * SCALER_GetCurrVal(OUTER_FRAME_ALL))
                          - SCALER_GetCurrVal(MAIN_LEFT_PADDING)
                          - SCALER_GetCurrVal(MAIN_RIGHT_PADDING),
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

FSTATIC fbool_t MENU_MainSetupReq (MENU_MAIN_INST_S* inst)
{
    fbool_t retVal;

    #ifdef APPL_PARENTAL_ENABLED

    MENU_PINDIALOG_S openParams;
    PCTRL_PARAMS_S   pctrlParams;

    if ( PCTRL_GetParams(&pctrlParams) != FAPI_OK ) return FFALSE;

    /* test if setup area is protected */
    if ( (pctrlParams.protectionArea & APP_PROTECTION_SETUP) != 0 )
    {
        memset(&openParams, 0, sizeof(openParams));

        openParams.titleStr   = OSD_GetStr(STR_MSG_PASSWORD_ENTER_PIN);
        openParams.numChars   = PCTRL_PIN_LEN;
        openParams.onPinEnter = MENU_MainSetupOnPinEnter;
        openParams.arg        = inst;

        if ( MENU_PinDialogOpen(&(appDat->pinDialog), &openParams) == FAPI_OK )
        {
            retVal = FTRUE;
        }
        else
        {
            retVal = FFALSE;
        }
    }
    else
    {
    #endif /* APPL_PARENTAL_ENABLED */

        retVal = MENU_MainSetupAuthorized(inst);

    #ifdef APPL_PARENTAL_ENABLED
    }
    #endif /* APPL_PARENTAL_ENABLED */

    return retVal;
}

#ifdef APPL_PARENTAL_ENABLED

FSTATIC void MENU_MainSetupOnPinEnter (void* arg, const char_t* pin, uint8_t numChars)
{
    MENU_MAIN_INST_S* inst       = (MENU_MAIN_INST_S*)arg;
    fbool_t             authorized = FFALSE;

    if ( PCTRL_CheckPin (PCTRL_PIN_MASTER, pin) == FAPI_OK )
    {
        authorized = FTRUE;
    }
    else
    {
        (void)MENU_PinDialogReset(&(appDat->pinDialog));
    }

    (void)MENU_PinDialogClose(&(appDat->pinDialog));

    if ( authorized ) (void)MENU_MainSetupAuthorized(inst);
}

#endif /* APPL_PARENTAL_ENABLED */

FSTATIC fbool_t MENU_MainSetupAuthorized (MENU_MAIN_INST_S* inst)
{
    /* store last focus */
    MENUSTACK_SetData(MENU_MAIN_ID_ENTRY_SETUP);

    return MENUSTACK_Up(MENU_SystemSetupEntry, NULL);
}

#endif


/* 21b278b4 - complete */
FSTATIC void func_21b278b4()
{

}


/* 21b278b0 - complete */
FSTATIC void func_21b278b0()
{

}


/******************************************************************************/
/*lint -restore */
/* END OF FILE */
