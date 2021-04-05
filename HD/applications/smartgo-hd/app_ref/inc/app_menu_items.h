/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/inc/app_menu_items.h
**
** \brief       gerneral Menu items.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
**
*****************************************************************************
*/
#ifndef _APP_MENU_ITEMS_H_
#define _APP_MENU_ITEMS_H_

#if 0

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
#define MENU_PINDIALOG_CHARS_MAX         4

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef struct
{
    FAPI_SYS_HandleT    pnlHdl;      //!< Parent panel.
    FGS_LOC_S           pos;         //!< Position in parent panel.
    uint16_t            descrWidth;  //!< Description area width.
    uint16_t            barWidth;    //!< Bar area width.
    int8_t              feIdx;       //!< Initial frontend index.

} MAIN_SIGBOX_OPEN_S;

typedef struct
{
    MAIN_SIGBOX_OPEN_S  data;
    FAPI_SYS_HandleT    lvlStrHdl;
    FAPI_SYS_HandleT    qualStrHdl;

    FGS_PANEL_MEMBER_S* pItem;
    FGS_POS_S           itemPos;

    fbool_t paused;

} MAIN_SIGBOX_INST_S;

typedef struct
{
    FGS_POS_S*      pos;            //!< Position of Conf Dialog
    uint16_t        numDescLines;   //!< Number of lines for description field
    SYS_STRING_S    titleStr;       //!< Title line string
    SYS_STRING_S    infoStr;        //!< additional info string
    SYS_STRING_S    confirmStr;     //!< String for OK option
                                    //!< (NULL: no action, close dialog)
    SYS_STRING_S    declineStr;     //!< String for decline option
                                    //!< (NULL: no action, close dialog)
    SYS_STRING_S    discardStr;     //!< String for discard option
                                    //!< (NULL: no action, close dialog)

    void   (*onConfirm)(void* arg); //!< Optional handler for confirm option
    void   (*onDecline)(void* arg); //!< Optional handler for decline option
    void   (*onDiscard)(void* arg); //!< Optional handler for discard option
    void*  arg;

} MENU_CONFDIALOG_S;

typedef struct
{
    FGS_PANEL_INST_S        pnlInst;

    MENU_CONFDIALOG_S       data;
    FAPI_SYS_HandleT        pnlHdl;

    FGS_PANEL_MEMBER_S*     pItem;
    FGS_POS_S               itemPos;
    int32_t                 extIdx;

} MENU_CONFDIALOG_INST_S;

#endif

typedef struct
{
    FGS_POS_S               pos; /*0*/          //!< Panel position.
    int32_t                 id;  /*12*/          //!< id.
    uint32_t                numVisLines; /*16*/  //!< Number of list lines.
    uint32_t                numItems; /*20*/     //!< Maximum number of list entries
    uint32_t                index; /*24*/        //!< Initial list index.

    int Data_28; //28
    int Data_32; //32

    FGS_GETITEM_CB          getItem; /*36*/      //!<
    FAPI_SYS_HandleT        getItemArg;    //!<
    FGS_LNAVI_SELECT_CB     onSelect;      //!< select-callback
    FAPI_SYS_HandleT        onSelectArg;   //!< optional argument for onSelect
    void (*onExit)(FAPI_SYS_HandleT h, int32_t id); //!< exit-callback
    FAPI_SYS_HandleT        onExitArg;     //!< optional argument for onExit
    //60
} MENU_SELECTLIST_OPEN_S;


typedef struct
{
    FGS_PANEL_INST_S        pnlInst;
    FGS_LNAVI_INST_S        lnaviInst; //2456
    MENU_SELECTLIST_OPEN_S  data; //2992
    FAPI_SYS_HandleT        pnlHdl; //3052
    FAPI_SYS_HandleT        naviHdl; //3056
    int32_t                 extIdx; //3060
    //3064
} MENU_SELECTLIST_INST_S;

#if 0

typedef struct
{
    FGS_PANEL_INST_S        pnlInst;
    FAPI_SYS_HandleT        pnlHdl;
    FAPI_SYS_HandleT        titleHdl;

    FGS_PANEL_MEMBER_S*     pItem;
    FGS_POS_S               itemPos;

    fbool_t                 isVisible;
    uint64_t                timeOpened;
    int32_t                 extIdx;

} VOLUMEBAR_INST_S;

typedef struct
{
    FGS_PANEL_INST_S        pnlInst;
    FAPI_SYS_HandleT        pnlHdl;

    fbool_t                 isVisible;
    int32_t                 extIdx;

} PROHIBITED_INST_S;

typedef struct
{
    FGS_PANEL_INST_S        pnlInst;
    FAPI_SYS_HandleT        pnlHdl;
    FAPI_SYS_HandleT        titleHdl;

    fbool_t                 permanent;
    uint64_t                timeOpened;
    int32_t                 extIdx;

} MAIN_MSGBOX_INST_S;

typedef struct
{
    SYS_STRING_S    text;          //!< text string to be displayed.
    fbool_t         permanent;     //!< FTRUE: permanent display.
    uint8_t         numLines;      //!< Number of lines containing text.
    int16_t         width;         //!< box width: -1: automatic (single line only).

} MAIN_MSGBOX_OPEN_S;

typedef struct
{
    SLIST_TYPE          initialListId;
    int16_t             (*getInitialIndexForList)(SLIST_TYPE listId); //!< index: 0...(n-1): service
                                                                  //!< -1: Rec 1, -2: Rec2
    fbool_t             (*serviceIsAvailable)    (const SYS_SERVLOC_S* pServLoc);
    void                (*onServiceSelect)       (const SYS_SERVLOC_S* pServLoc);

    #ifdef APPL_PVR_ENABLED

    fbool_t         (*recordIsAvailable)     (uint8_t recIdx);
    void            (*onRecordSelect)        (uint8_t recIdx);

    #endif /* APPL_PVR_ENABLED */

    FGS_FOCUSSET_CB onFocusSet;
    FAPI_SYS_HandleT       onFocusSetArg;

} MAIN_SERVBOX_OPEN_S;

typedef struct
{
    MAIN_SERVBOX_OPEN_S     params;
    FAPI_SYS_HandleT        pnlHdl;
    FAPI_SYS_HandleT        naviHdl;
    SLIST_TYPE              currServLst;   // currently presented service list

    FGS_PANEL_MEMBER_S*     pTitleItem;
    FGS_POS_S               titlePos;

    uint8_t                 numRecords;

    SLIST_ITEM_S            currItem;

    #ifdef APPL_LCN_ENABLED
    fbool_t                 showLcn;
    #endif /* APPL_LCN_ENABLED */

} MENU_SERVBOX_INST_S;

typedef struct
{
    SYS_STRING_S        titleStr;

    uint8_t             numChars;

    void                (*onPinEnter)(void* arg, const char_t* pin, uint8_t numChars);
                                             //!< called after entering PIN.
    void*               arg;                 //!< Optional callback argument.

    FGS_KEY_CB          keyHdlChanUp;
    FAPI_SYS_HandleT    keyHdlChanUpArg;
    FGS_KEY_CB          keyHdlChanDown;
    FAPI_SYS_HandleT    keyHdlChanDownArg;

} MENU_PINDIALOG_S;

typedef struct
{
    FGS_PANEL_INST_S    pnlInst;
    FGS_BOX_INST_S      boxInst[MENU_PINDIALOG_CHARS_MAX];

    MENU_PINDIALOG_S    data;
    FAPI_SYS_HandleT    pnlHdl;

    char_t              pin[MENU_PINDIALOG_CHARS_MAX];
    uint8_t             pinPos;

    int32_t             extIdx;

} MENU_PINDIALOG_INST_S;

/* application wide available defines and typedefs for editstring function */
typedef enum
{
    MENU_EDITSTRING_KEY_ALL = 0,
    MENU_EDITSTRING_KEY_NUM,
    MENU_EDITSTRING_KEY_UPPER,
    MENU_EDITSTRING_KEY_LOWER,
    MENU_EDITSTRING_KEY_SPECIAL,

} MENU_EDITSTRING_KEY_STATUS;

typedef struct
{
    SYS_STRING_S            string;         //!< String.
    uint32_t                maxChars;       //!< max. size for resulting string
                                            //!< length. If 0 then internal
                                            //!< maximum is assumed.
    /* this flag is set by the edit function
       FTRUE = edit was successful, string is terminated by zero and can be used,
       FFALSE = edit was canceled or forced stopped. String is not to be used
    */
    fbool_t                   updated;        //!< FTRUE  = edit was successfull

} MENU_EDITSTRING_DATA_S;

typedef struct
{
    FGS_POS_S               pos;            //!< position of edit window
    FGS_GETITEM_CB          editTitle;      //!< get list title string
    FAPI_SYS_HandleT        editTitleArg;   //!< argument
    int32_t                 id;             //!< id of parent process, to be used
                                            //!< for passing to call back functions
    MENU_EDITSTRING_DATA_S  editData;       //!< edit data structure
                                            //!< FFALSE = edit was stopped
    void  (*onExit)(MENU_EDITSTRING_DATA_S* editData, int32_t id);
                                            //!< exit-callback
    FAPI_SYS_HandleT        onExitArg;      //!< optional argument for onExit

} MENU_EDITSTRING_OPEN_S;

typedef struct
{
    FGS_PANEL_INST_S            pnlInst;

    FAPI_SYS_HandleT            pnlHdl;
    int32_t                     extIdx;

    uint8_t                     firstVisChar;
    uint8_t                     strPos;
    uint16_t                    strSize;
    MENU_EDITSTRING_OPEN_S      editPars;
    MENU_EDITSTRING_KEY_STATUS  keyStatus;
    SYS_STRBUF_S                tmpBuf;
    SYS_STRBUF_S                targetBuf;

} MENU_EDITSTRING_INST_S;


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  MENU_ConfDialogInit         (MENU_CONFDIALOG_INST_S* inst);
fbool_t  MENU_ConfDialogOpen         (MENU_CONFDIALOG_INST_S* inst,
                                      const MENU_CONFDIALOG_S* openParams);
fbool_t  MENU_ConfDialogClose        (MENU_CONFDIALOG_INST_S* inst);

int32_t  MAIN_SignalBoxInit          (MAIN_SIGBOX_INST_S* inst);
int32_t  MAIN_SignalBoxOpen          (MAIN_SIGBOX_INST_S* inst,
                                      const MAIN_SIGBOX_OPEN_S* openParams);
int32_t  MAIN_SignalBoxClose         (MAIN_SIGBOX_INST_S* inst);
int32_t  MAIN_SignalBoxUpdate        (MAIN_SIGBOX_INST_S* inst);
int32_t  MAIN_SignalBoxSetFeIdx      (MAIN_SIGBOX_INST_S* inst, int8_t feIdx);
int32_t  MAIN_SignalBoxPause         (MAIN_SIGBOX_INST_S* inst);
int32_t  MAIN_SignalBoxResume        (MAIN_SIGBOX_INST_S* inst);
uint32_t MAIN_SignalBoxGetHeight     (void);

fbool_t  MENU_SelectListOpen         (MENU_SELECTLIST_INST_S* inst,
                                      const MENU_SELECTLIST_OPEN_S* openParams);

int32_t  MAIN_VolumeBarInit          (VOLUMEBAR_INST_S* inst);
int32_t  MAIN_VolumeBarShow          (VOLUMEBAR_INST_S* inst);
int32_t  MAIN_VolumeBarHide          (VOLUMEBAR_INST_S* inst);
void  MAIN_VolumeBarHandleExpiration (VOLUMEBAR_INST_S* inst);

int32_t  MAIN_ProhibitedInit         (PROHIBITED_INST_S* inst);
int32_t  MAIN_ProhibitedShow         (PROHIBITED_INST_S* inst);
int32_t  MAIN_ProhibitedHide         (PROHIBITED_INST_S* inst);

int32_t  MAIN_MsgBoxInit             (MAIN_MSGBOX_INST_S* inst);
int32_t  MAIN_MsgBoxShow             (MAIN_MSGBOX_INST_S* inst,
                                      const MAIN_MSGBOX_OPEN_S* pars);
int32_t  MAIN_MsgBoxHide             (MAIN_MSGBOX_INST_S* inst);
void  MAIN_MsgBoxHandleExpiration    (MAIN_MSGBOX_INST_S* inst);

int32_t  MAIN_ServBoxInit            (MENU_SERVBOX_INST_S* inst);
int32_t  MAIN_ServBoxOpen            (MENU_SERVBOX_INST_S* inst,
                                      const MAIN_SERVBOX_OPEN_S* openParams);
int32_t  MAIN_ServBoxClose           (MENU_SERVBOX_INST_S* inst);
int32_t  MAIN_ServBoxGetCurrList     (MENU_SERVBOX_INST_S* inst,
                                      SLIST_TYPE* listId);
int32_t  MAIN_ServBoxGetCurrIndex    (MENU_SERVBOX_INST_S* inst,
                                      int16_t* index);
int32_t  MAIN_ServBoxSetServLoc      (MENU_SERVBOX_INST_S* inst,
                                      const SYS_SERVLOC_S* pServLoc);
int32_t  MAIN_ServBoxUpdate          (MENU_SERVBOX_INST_S* inst);

int32_t  MENU_PinDialogInit          (MENU_PINDIALOG_INST_S* inst);
int32_t  MENU_PinDialogOpen          (MENU_PINDIALOG_INST_S* inst,
                                      const MENU_PINDIALOG_S* openParams);
int32_t  MENU_PinDialogClose         (MENU_PINDIALOG_INST_S* inst);
int32_t  MENU_PinDialogReset         (MENU_PINDIALOG_INST_S* inst);

#ifdef __cplusplus
}
#endif

#endif

#endif /* _APP_MENU_ITEMS_H_ */
/******************************************************************************/
/* END OF FILE */
