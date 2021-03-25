/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/inc/app_menu.h
**
** \brief       OSD Menu implementation.
**
** Detail description. [\ref app_smartgo_app_ref_menu]
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
#ifndef _APP_MENU_H_
#define _APP_MENU_H_

#if 0

#include "fgs_item_char.h"
#include "fgs_item_check.h"
#endif
#include "fgs_item_text.h"
#if 0
#include "fgs_item_number.h"
#include "fgs_item_select.h"
#endif
#include "fgs_pininput.h"

#include "app_main.h"

#if 0

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

#define MENU_COMMON_PATH_SEPARATOR    '/'   //!< the directory path separator

#define MENU_COMMON_ITEM_BUTTON(a, b)                               \
    do {                                                            \
        (a)->type                 = FGS_ITEM_TYPE_ICON;             \
        (a)->align                = FGS_ALIGN_HOR_LEFT              \
                                  | FGS_ALIGN_VER_CENTER;           \
        (a)->item.icon.addr       = (uint32_t*)OSD_IconGet(b);      \
        (a)->item.icon.drawMode   = FGS_ICONMODE_OVRLAY;            \
        (a)->item.icon.bkgrCol    = OSD_COL_BLANK;                  \
        (a)->item.icon.altBkgrCol = OSD_COL_BLANK;                  \
    } while ( 0 )

#define MENU_COMMON_ITEM_HELPSTR(a, b)                              \
    do {                                                            \
        (a)->type                = FGS_ITEM_TYPE_STRING;            \
        (a)->align               = FGS_ALIGN_HOR_LEFT               \
                                 | FGS_ALIGN_VER_CENTER;            \
        (a)->item.str.font       = HELP_FONT;                       \
        (a)->item.str.lineHeight = 0;                               \
        (a)->item.str.col        = OSD_COL_HELP_TEXT;               \
        (a)->item.str.chr        = OSD_GetStr(b);                   \
    } while ( 0 )

#define MENU_COMMON_ITEM_MENUSTR(a, b, c)                           \
    do {                                                            \
        (a)->type                = FGS_ITEM_TYPE_STRING;            \
        (a)->align               = FGS_ALIGN_HOR_LEFT               \
                                 | FGS_ALIGN_VER_CENTER;            \
        (a)->item.str.chr        = OSD_GetStr(b);                   \
        (a)->item.str.font       = MAIN_FONT;                       \
        (a)->item.str.lineHeight = 0;                               \
                                                                    \
        switch ( c )                                                \
        {                                                           \
            default:                                                \
            case FGS_NONFOCUS:                                      \
                (a)->item.str.col = appDat->txtAttr.colNonFocus;    \
                break;                                              \
                                                                    \
            case FGS_FOCUS:                                         \
                (a)->item.str.col = appDat->txtAttr.colFocus;       \
                break;                                              \
                                                                    \
            case FGS_DISABLED:                                      \
                (a)->item.str.col = appDat->txtAttr.colDisabled;    \
                break;                                              \
        }                                                           \
    } while ( 0 )

#define MENU_COMMON_ITEM_TITLESTR(a, b)                             \
    do {                                                            \
        (a)->type                = FGS_ITEM_TYPE_STRING;            \
        (a)->align               = FGS_ALIGN_HOR_LEFT               \
                                 | FGS_ALIGN_VER_CENTER;            \
        (a)->item.str.font       = TITLE_FONT;                      \
        (a)->item.str.lineHeight = 0;                               \
        (a)->item.str.col        = OSD_COL_TITLE_TEXT;              \
        (a)->item.str.chr        = OSD_GetStr(b);                   \
    } while ( 0 )

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

/* all panel IDs */
typedef enum
{
    MENUID_ROOT = 0,
    MENUID_STARTUP, //1
    MENUID_MAIN,
    MENUID_WELCOME, //3
    MENUID_SYSTEMSETUP,
    MENUID_INFORMATION,
    MENUID_STRSEL,
    MENUID_SETUP,
    MENUID_LANGUAGE,
    MENUID_TIME,
    MENUID_ADVD,
    MENUID_OSD,
    MENUID_PASSWORD,
    MENUID_HDD,
    MENUID_ANTPROG,
    MENUID_TPLIST,
    MENUID_SATLIST,
    MENUID_EXPMOTOR,
    MENUID_SERVLIST,
    MENUID_TUNER,
    MENUID_SATINSTTYPE, //20
    MENUID_TIMERPROG,
    MENUID_TIMEREDIT,
    MENUID_CHANLIST,
    MENUID_STRINF,
    MENUID_SERVMNG,
    MENUID_INFOBAR,
    MENUID_EPGEXT,
    MENUID_EPGSCHED,
    MENUID_VOLUMEBAR,
    MENUID_PROHIBITEDICON,
    MENUID_MSGBOX,
    MENUID_SCAN,
    MENUID_SCANNING,
    MENUID_PLIST,
    MENUID_EDITREC,
    MENUID_PVR,
    MENUID_CONFDIALOG,
    MENUID_CI,
    MENUID_MMI,
    MENUID_SELECTLIST,
    MENUID_RECSTOP,
    MENUID_VIEWER,
    MENUID_MEDIA_ROOT,
    MENUID_MEDIA_DIALOG,
    MENUID_MEDIA_SMALLINFO,
    MENUID_MEDIA_PICINFO,
    MENUID_MEDIA_MUSICINFO,
    MENUID_JPEG,
    MENUID_MP3,
    MENUID_MHEG,
    MENUID_PINDIALOG,
    MENUID_UPDATE,
    MENUID_UPDATEPROGRESS,
    MENUID_EPG,
    MENUID_DEMO,
    MENUID_STRINGEDIT,
    MENUID_MOSAIC,
    MENUID_NETWORK,
    MENUID_NETWORK_IP,
    MENUID_NETWORK_DNS,
    MENUID_NETWORK_INFO

} MENU_PANEL_ID_E;

typedef struct
{
    fbool_t permanent;      //!< FFALSE: non-permanent display of infobar
    int8_t  numberInput;    //!< Optional number input (0...9),
                            //!< other values: no input

} MENU_INFOBAR_PARAMS_S;

#ifdef APPL_RECTIMER_ENABLED

typedef struct
{
    int16_t             timerIndex;   //!< index of existing timer to edit
    RECTIMER_ITEM_S*    newDat;       //!< data of new timer
                                      //!< (valid if timerIndex = -1)
    SYS_SERVLOC_S       newService;   //!< initially selected service of new timer
                                      //!< (valid if timerIndex = -1)
    fbool_t             directCall;   //!< indication that menu was called directly
                                      //!< by instant record request

} MENU_TIMEREDIT_PARAMS_S;

#endif /* APPL_RECTIMER_ENABLED */

typedef struct
{
    FE_SYSTEM_TYPE_E    system;
    int16_t             satLstPos; /* for sat-frontends only */
    int16_t             carrierLstPos;
    fbool_t             lockSat;
    void                (*leaveCb)(int16_t satLstPos, int16_t carrierLstPos);

} MENU_TPLIST_PARAMS_S;

#ifdef APPL_PVR_ENABLED

typedef struct
{
    uint16_t lstPos;

} MENU_EDITREC_PARAMS_S;

#endif /* APPL_PVR_ENABLED */

#ifdef APPL_JPEG_ENABLED

typedef struct
{
    const char_t* path;
    const char_t* filename;

} MENU_JPEG_PARAMS_S;

#endif /* APPL_JPEG_ENABLED */

#ifdef APPL_MP3_ENABLED

typedef struct
{
    const char_t* path;
    const char_t* filename;

} MENU_MP3_PARAMS_S;

#endif /* APPL_MP3_ENABLED */

typedef struct
{
    uint32_t          arg1;         //!< Menu-specific argument
    uint32_t          arg2;         //!< Menu-specific argument
    fbool_t           guided;       //!< FTRUE: start menu in "guided" mode

} MENU_GUIDED_PARAMS_S;

typedef struct
{
    MENUSTACK_ENTRY      entry;     //!< entry function
    MENU_GUIDED_PARAMS_S params;    //!< parameters
    uint32_t             strIdx;    //!< optional string in OSD menu

} MENU_GUIDED_S;

#if defined(APPL_CI_ENABLED) || defined(APPL_CA_ENABLED)

typedef struct
{
    uint8_t              slotIdx;         //!< CI slot identification.
    fbool_t              calledByUser;    //!< FTRUE: called by user,
                                          //!< FFALSE: called by module request.
    CISYS_MODULE_TYPE_E  type;

} MENU_MMI_PARAMS_S;

#endif /* APPL_CI/CA_ENABLED */

typedef void (*MENU_EVT_CB)(void);

typedef struct
{
    SYS_EVTHDR_S  hdr;
    MENU_EVT_CB   cb;

} MENU_EVT_REFRESH_S;


typedef struct
{
    fbool_t             schedMode; //!< Display mode: FTRUE: schedule,
                                   //!< FFALSE: Curr/Next.
    EIT_EVT_TYPE_E      currType;  //!< Currently displayed event type
                                   //!< for non-schedule mode.
    EIT_POS_S           currRef;   //!< Current schedule reference for
                                   //!< schedule mode.
    MENUSTACK_ENTRY     calledFrom;//!< Menu entry which call the EPGEXT.

} MENU_EPGEXT_OPEN_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------- */

int32_t MENU_MainInit           (void);
int32_t MENU_TimerProgInit      (void);
int32_t MENU_TimerEditInit      (void);
int32_t MENU_MosaicInit         (void);
int32_t MENU_SystemSetupInit    (void);
int32_t MENU_InformationInit    (void);
int32_t MENU_LanguageInit       (void);
int32_t MENU_TimeInit           (void);
int32_t MENU_AntProgInit        (void);
int32_t MENU_AudioVideoInit     (void);
int32_t MENU_OsdInit            (void);
int32_t MENU_StreamInfoInit     (void);
int32_t MENU_ScanInit           (void);
int32_t MENU_ScanningInit       (void);
int32_t MENU_TpListInit         (void);
int32_t MENU_SatListInit        (void);
int32_t MENU_ExpMotorInit       (void);
int32_t MENU_ServListInit       (void);
int32_t MENU_WelcomeInit        (void);
int32_t MENU_TunerInit          (void);
int32_t MENU_SatInstTypeInit    (void);
int32_t MENU_PlayListInit       (void);
int32_t MENU_PvrInit            (void);
int32_t MENU_StrSelInit         (void);
int32_t MENU_ServSelectInit     (void);
int32_t MENU_PipSelectInit      (void);
int32_t MENU_ViewerInit         (void);
int32_t MENU_MediaInit          (void);
int32_t MENU_EditRecInit        (void);
int32_t MENU_JPEGInit           (void);
int32_t MENU_MP3Init            (void);
int32_t MENU_CiInit             (void);
int32_t MENU_MmiInit            (void);
int32_t MENU_PasswordInit       (void);
int32_t MENU_InfoInit           (void);
int32_t MENU_EpgGridInit        (void);
int32_t MENU_EpgExtInit         (void);
int32_t MENU_EpgSchedInit       (void);
int32_t MENU_MhegInit           (void);
int32_t MENU_UpdateInit         (void);

#ifdef APPL_ETHERNET_ENABLED
int32_t MENU_NetworkInit        (void);
int32_t MENU_NetworkIpInit      (void);
int32_t MENU_NetworkDnsInit     (void);
int32_t MENU_NetworkInfoInit    (void);
#endif

#ifdef APPL_OAD_FOTA_ENABLED

int32_t MENU_OadInit            (void);
fbool_t MENU_OadSatEntry       (FAPI_SYS_HandleT h, fbool_t test);

void    MENU_OADUPDATE_UpdateInfo  (SYS_NETWORK_S* pnetwork,
                                    TPLIST_ITEM_S* pcarrierInf);

#endif /* #ifdef APPL_OAD_FOTA_ENABLED */

#if (defined APPL_HDD_ENABLED) || (defined APPL_USB_ENABLED)
int32_t MENU_HddInit            (void);
#endif /* (defined APPL_HDD_ENABLED) || (defined APPL_USB_ENABLED) */

int32_t MENU_EditStringInit     (MENU_EDITSTRING_INST_S* inst);

/* ------------------------------------------------------------------------- */

fbool_t MENU_MainEntry         (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_WelcomeEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_TimerProgEntry    (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_TimerEditEntry    (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_MosaicEntry       (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_SystemSetupEntry  (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_InformationEntry  (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_LanguageEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_TimeEntry         (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_AntProgEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_AudioVideoEntry   (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_OsdEntry          (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_StreamInfoEntry   (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ScanSatEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ScanTerrEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ScanCableEntry    (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ScanDirectEntry   (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ScanningEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_TpListEntry       (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_SatListEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ExpMotorEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ServListEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_WelcomeEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_TunerEntry        (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_SatInstTypeEntry  (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ViewerEntry       (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_MediaEntry        (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_JPEGEntry         (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_MP3Entry          (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_UpdateEntry       (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_RootEntry         (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_StandbyEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_PlayListEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_StrSelEntry       (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_ServSelectEntry   (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_PipSelectEntry    (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_EditRecEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_PasswordEntry     (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_TtxtEntry         (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_CiEntry           (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_MhegEntry         (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_EpgGridEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_EpgExtEntry       (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_EpgSchedEntry     (FAPI_SYS_HandleT h, fbool_t test);

#ifdef APPL_ETHERNET_ENABLED
fbool_t MENU_NetworkEntry      (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_NetworkIpEntry    (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_NetworkDnsEntry   (FAPI_SYS_HandleT h, fbool_t test);
fbool_t MENU_NetworkInfoEntry  (FAPI_SYS_HandleT h, fbool_t test);
#endif
#if (defined APPL_HDD_ENABLED) || (defined APPL_USB_ENABLED)
fbool_t MENU_HddEntry          (FAPI_SYS_HandleT h, fbool_t test);
#endif /* (defined APPL_HDD_ENABLED) || (defined APPL_USB_ENABLED) */

/* ----- Common menu OSD functions ----------------------------------------- */

int32_t MENU_CommonAddTitle         (int32_t id, FAPI_SYS_HandleT pnlHdl,
                                     uint16_t pnlWidth,
                                     uint16_t stackedFrameWidth,
                                     uint32_t strIdx,
                                     FGS_GETITEM_CB getTitleItemCb,
                                     void* cbArg);
int32_t MENU_CommonAddGenericTitle  (int32_t id, FGS_GETITEM_CB getItem,
                                     FAPI_SYS_HandleT getItemArg,
                                     FAPI_SYS_HandleT pnlHdl,
                                     uint16_t pnlWidth,
                                     uint16_t stackedFrameWidth);
void MENU_CommonGetItemTitle        (FAPI_SYS_HandleT h, int32_t id,
                                     uint32_t index, FGS_ITEMSTATE_E state,
                                     FGS_ITEM_S* item);
FAPI_SYS_HandleT MENU_CommonAddList (FGS_LIST_OPEN_S* pListPars, int32_t id,
                                     uint16_t stackedFrameWidth,
                                     uint16_t offsetY,
                                     uint16_t width, uint16_t height,
                                     FAPI_SYS_HandleT pnlHdl,
                                     FGS_POS_S* pItemPos,
                                     FGS_POS_S* pDescrPos,
                                     FGS_POS_S* pValuePos,
                                     uint8_t descrPercentage,
                                     int32_t* pRetVal);
FAPI_SYS_HandleT MENU_CommonAddHelpList   (int32_t id, FAPI_SYS_HandleT pnlHdl,
                                     uint16_t stackedFrameWidth,
                                     uint16_t innerWidth, int16_t y,
                                     uint16_t width, uint16_t numLines,
                                     FGS_GETITEM_CB getItem,
                                     FAPI_SYS_HandleT getItemArg);
void MENU_CommonSetHelpDescrParams  (FGS_ITEM_S* item, FGS_ITEMSTATE_E state,
                                     uint32_t strIdx);
#endif
void MENU_CommonSetParamsTitleWHelp (FGS_PANEL_OPEN_S* pnlPars,
                                     uint16_t innerWidth, uint16_t innerHeight,
                                     uint16_t helpWidth, uint8_t  numHelpLines,
                                     uint16_t* stackedFrameWidth);
#if 0
void MENU_CommonSetParamsTitleWBotHelp (FGS_PANEL_OPEN_S* pnlPars,
                                     uint16_t innerWidth,
                                     uint16_t innerHeight,
                                     uint8_t  numHelpLines,
                                     uint16_t* pStackedFrameWidth);
void MENU_CommonSetPanelPos         (FGS_POS_S* pos);
void MENU_CommonSelectListSelected  (FAPI_SYS_HandleT listHdl, int32_t id,
                                     uint16_t index);

void MENU_CommonGetHelpItem         (FAPI_SYS_HandleT h, int32_t id,
                                     uint32_t index, FGS_ITEMSTATE_E state,
                                     FGS_ITEM_S* item);

int32_t MENU_CommonAddMenuExitHelpLine(int16_t xPos, int16_t yPos,
                                    uint16_t width, FAPI_SYS_HandleT pnlHdl);
void MENU_CommonAppendpath         (const char_t* newPath,
                                    const char_t* path, char_t* result,
                                    fbool_t separator,
                                    uint16_t resultLength);
void MENU_CommonMsgShow            (STR_IDX_S msg, fbool_t permanent);
/* ----- "Guided mode" API ------------------------------------------------- */

int32_t  MENU_GuidedInit              (void);
int32_t  MENU_GuidedClear             (void);
int32_t  MENU_GuidedAdd               (const MENU_GUIDED_S* guidedParams);
fbool_t  MENU_GuidedStart             (void);
fbool_t  MENU_GuidedGotoNext          (void);
fbool_t  MENU_GuidedGotoPrevious      (void);
uint32_t MENU_GuidedGetNextStr        (void);

/* ----- Infobar functions ------------------------------------------------- */
int32_t  MENU_InfobarInit     (void);
fbool_t  MENU_InfobarEntry    (FAPI_SYS_HandleT h, fbool_t test);
fbool_t  MENU_InfobarIsVisible(void);

/* ----- Misc. functions --------------------------------------------------- */

void    MENU_StrSelServSelEvent      (const SYS_EVT_SERVICE_S* pEvent);
void    MENU_StrSelPmtUpdate         (void);
void    MENU_StrSelSubLangUpdate     (void);

void    MENU_EpgGridUpdate           (SLIST_SERVIDX servIdx);

void    MENU_EpgSchedUpdate          (void);
void    MENU_EpgSchedUpdateList      (fbool_t resetIndex);

void    MENU_EpgExtUpdate            (const MENU_EPGEXT_OPEN_S* params);

#ifdef APPL_PVR_ENABLED

void    MENU_StrSelPlayEvent         (const SYS_EVT_PVRPLAY_S* pEvent);
int32_t MENU_EditRecGetCurrEvt       (void);

#endif /* APPL_PVR_ENABLED */

void    MENU_TimerProgUpdate         (void);
void    MENU_TunerUpdateLockStatus   (uint8_t feNum, SYS_FE_LOCK_E status);

void    MENU_ServSelectServiceUpdate (const SYS_SERVLOC_S* pServLoc);

void    MENU_TunerRefresh            (void);


#ifdef APPL_JPEG_ENABLED

void    MENU_JPEGHandleTime          (void);
void    MENU_JPEGHandleEvent         (SYS_EVTTYPE_E type, const void* data);

#endif /* APPL_JPEG_ENABLED */

#ifdef APPL_MP3_ENABLED

void    MENU_MP3HandleTime          (void);
void    MENU_MP3HandleEvent         (const MP3_EVT_STATUS_S* data);

#endif /* APPL_MP3_ENABLED */

#ifdef APPL_FILEOP_ENABLED

void    MENU_MediaHandleTime        (void);
void    MENU_MediaHandleEvent       (SYS_EVTTYPE_E type, const void* data);

#endif /* APPL_FILEOP_ENABLED */

void    MENU_PlayListUpdate        (void);

#ifdef APPL_MOSAIC_ENABLED

void  MENU_MosaicProgress       (const SYS_EVT_SERVICE_S* status);
void  MENU_MosaicHandleTime     (void);

#endif /* APPL_MOSAIC_ENABLED */

#if defined(APPL_CI_ENABLED) || defined(APPL_CA_ENABLED)

void  MENU_CiSlotStatusUpdate    (const CISYS_EVT_STATUS_S* data);
void  MENU_MmiSlotStatusUpdate   (const CISYS_EVT_STATUS_S* data);
void  MENU_MmiMmiStatusUpdate    (const CISYS_EVT_MMI_S* data);

#endif /* APPL_CI/CA_ENABLED */

#ifdef APPL_MHEG_ENABLED

int32_t  MENU_MhegStateChange   (MHEG_STATE_E state);
fbool_t  MHEG_MenuTrans         (FAPI_SYS_HandleT h);
void     MENU_MhegSetKeyMask    (const int32_t *keys, size_t keysCount);
fbool_t  MENU_MhegDispatchKey   (FGS_KEY_E key, FGS_KEYTYPE_E keyType, int8_t keyVal);
#endif /* APPL_MHEG_ENABLED */

#ifdef APPL_UPDATE_ENABLED

void MENU_UpdateProgress        (const SYS_EVT_UPDATE_S* data);

#endif /* APPL_UPDATE_ENABLED */

void    MENU_TimeUpdate         (void);
fbool_t MENU_TimeHandleEvt      (MENU_TIME_OPEN_S* params);

fbool_t MENU_EditStringOpen     (MENU_EDITSTRING_INST_S* inst,
                                 MENU_EDITSTRING_OPEN_S* openParams);

#ifdef APPL_PVR_ENABLED

void    MENU_EditRecPlayModeChanged(void);

#endif /* APPL_PVR_ENABLED */

#if (defined APPL_HDD_ENABLED) || (defined APPL_USB_ENABLED)

void    MENU_HddDeviceUpdate    (const SYS_EVT_DEVSTAT_S* pEvt);

#endif /* (defined APPL_HDD_ENABLED) || (defined APPL_USB_ENABLED) */

void    MENU_AudioVideoRefresh  (void);
void    MENU_WelcomeRefresh     (void);
fbool_t MENU_HandleRootKeys     (FGS_KEY_E key);

#ifdef APPL_ETHERNET_ENABLED

void MENU_NetworkIpUpdate   ( void );
void MENU_NetworkInfoUpdate ( void );
void MENU_NetworkDnsUpdate  ( void );

#endif

#ifdef APPL_FATFS_ENABLED
void    MENU_HddFormatFinish   (void);
#endif
/* ------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif

#endif /* _APP_MENU_H_ */
/******************************************************************************/
/* END OF FILE */
