/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_list.h
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
*/
#ifndef _FGS_LIST_H_
#define _FGS_LIST_H_

#include "fgs_panel.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef void    (*FGS_LIST_FOCUSCHG_CB) (FAPI_SYS_HandleT h, uint8_t index, int32_t id);
typedef fbool_t (*FGS_LIST_SELECT_CB)   (FAPI_SYS_HandleT h, int32_t id);
typedef void    (*FGS_LIST_VALCHG_CB)   (FAPI_SYS_HandleT h, int32_t id, FGS_VAL_S val);

typedef struct
{
    void (*drawBkgr) (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl,   // optional
                      const FGS_ITEM_S* item);  
    void (*drawRest) (FAPI_SYS_HandleT h);                            // optional
    
} FGS_ITEM_DRAWIF_S;

typedef struct
{
    void (*drawBkgr)  (FAPI_SYS_HandleT h, uint16_t x, uint16_t y, uint16_t width, uint16_t height);  // optional
    
} FGS_LIST_DRAWIF_S;

typedef struct
{
    FGS_LIST_DRAWIF_S draw;
    
} FGS_LIST_INIT_S;

typedef struct
{
    FGS_POS_S            pos;             //!< list position
    fbool_t              isHidden; //12
    uint32_t             bkgrType;        //!< background type
    fbool_t              topDownOriented; //!< list orientation: 1: TOP/DOWN,
                                          //!<                   0: LEFT/RIGHT
    fbool_t              wraparound;      //!< wraparound mode:  0: suppressed
    fbool_t              autoRefresh;     //!< auto refresh status
    
    FGS_GETITEM_CB       getDescrItem;    //!< optional
    FAPI_SYS_HandleT     getDescrItemArg; //!< optional
    FGS_GETITEM_CB       getItem;         //!< optional
    FAPI_SYS_HandleT     getItemArg;      //!< optional
    
    FGS_FOCUSSET_CB      onFocusSet;    //!< focus-set/remove-callback (opt.)
    FAPI_SYS_HandleT     onFocusSetArg; //!< optional argument for onFocusSet
    FGS_LIST_FOCUSCHG_CB onFocusChg;    //!< focus-change-callback (optional)
    FAPI_SYS_HandleT     onFocusChgArg;
    FGS_LIST_SELECT_CB   onSelect;      //!< select-callback (optional)
    FAPI_SYS_HandleT     onSelectArg;
    FGS_LIST_VALCHG_CB   onValChg;      //!< value-change-callback (optional)
    FAPI_SYS_HandleT     onValChgArg;
    
    void*                pInst;         //!< optional facility to pass a memory 
                                        //!< buffer for instance data
    
} FGS_LIST_OPEN_S;

typedef struct
{
    /* written by parent */
    FGS_LOC_S           abspos;    //!< absolute member position (written by parent)
    fbool_t             posChg;    //!< notifies a change in positioning
    FGS_LIST_OPEN_S*    pParent;   //!< pointer to parent instance's data
    FGS_PANEL_INST_S*   pPanel;    //!< pointer to corresponding panel instance
    fbool_t             isEnabled; //!< enabled/disabled status
    
    /* written by member */
    FAPI_SYS_HandleT    h;           //!< pointer to member instance
    FGS_POS_S*          pos;         //!< member's position and size in parent item
    int32_t             id;          //!< member ID
    fbool_t             isVisible;   //!< visibility status
    fbool_t             hasFocus;    //!< focus status
    fbool_t             isActivated; //!< activation status
    
    FGS_POS_S           descrPos;      //!< item description position in member area
    FGS_POS_S           valuePos;      //!< member value position in member area
    
    int32_t             (*setFocus)    (FAPI_SYS_HandleT h, fbool_t hasFocus);    // mandatory
    int32_t             (*draw)        (FAPI_SYS_HandleT h);                    // mandatory
    int32_t             (*close)       (FAPI_SYS_HandleT h);                    // optional
    
    int32_t             (*activate)    (FAPI_SYS_HandleT h);                    // optional
    int32_t             (*deactivate)  (FAPI_SYS_HandleT h, fbool_t keepChanges); // optional
    int32_t             (*getParams)   (FAPI_SYS_HandleT h, void* params);      // optional
    int32_t             (*setParams)   (FAPI_SYS_HandleT h, const void* params);// optional
    fbool_t             (*up)          (FAPI_SYS_HandleT h);                    // optional
    fbool_t             (*down)        (FAPI_SYS_HandleT h);                    // optional
    fbool_t             (*left)        (FAPI_SYS_HandleT h);                    // optional
    fbool_t             (*right)       (FAPI_SYS_HandleT h);                    // optional
    fbool_t             (*number)      (FAPI_SYS_HandleT h, uint8_t value);          // optional
    fbool_t             (*ok)          (FAPI_SYS_HandleT h);                    // optional
    
} FGS_LIST_MEMBER_S;

typedef struct
{
    fbool_t             memAllocated;
    FGS_LIST_OPEN_S     data;
    FGS_PANEL_MEMBER_S* pMem;            //!< pointer to own member structure
    FGS_PANEL_INST_S*   pPanel;          //!< pointer to parent panel
    
    uint8_t             numMembers;
    FGS_LIST_MEMBER_S   member[FGS_LIST_MEMBERS_MAX];
    int32_t             focusIdx;
    
} FGS_LIST_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t FGS_LIST_Init             (FGS_LIST_INIT_S* pInitParams);
int32_t FGS_LIST_Open             (FGS_LIST_OPEN_S* pData, int32_t id, 
                                   FAPI_SYS_HandleT parent,
                                   FAPI_SYS_HandleT* ph);

int32_t FGS_LIST_AddMember        (FAPI_SYS_HandleT h,
                                   FGS_LIST_MEMBER_S* pMember,
                                   FGS_LIST_MEMBER_S** pId);
int32_t FGS_LIST_SetRefreshMode   (FAPI_SYS_HandleT h, fbool_t autoRefresh);

int32_t FGS_LIST_SetMemberFocus   (FAPI_SYS_HandleT h, int32_t id);
int32_t FGS_LIST_SetMemberFocusAuto(FAPI_SYS_HandleT h, int32_t* id);
int32_t FGS_LIST_GetMemberFocusID (FAPI_SYS_HandleT h);
int32_t FGS_LIST_SetMemberParams  (FAPI_SYS_HandleT h, int32_t id,
                                   const void* params);
int32_t FGS_LIST_GetMemberParams  (FAPI_SYS_HandleT h, int32_t id,
                                   void* params);
int32_t FGS_LIST_GetMemberAbsPos  (FAPI_SYS_HandleT h, int32_t id,
                                   FGS_LOC_S* loc);
int32_t FGS_LIST_RefreshMember    (FAPI_SYS_HandleT h, int32_t id);

int32_t FGS_LIST_SetMemberEnableStatus (FAPI_SYS_HandleT h, int32_t id,
                                        fbool_t enabled);
int32_t FGS_LIST_GetMemberEnableStatus (FAPI_SYS_HandleT h, int32_t id,
                                        fbool_t* enabled);
uint8_t FGS_LIST_GetNumOfMembers  (FAPI_SYS_HandleT h);

fbool_t FGS_LIST_Up               (FAPI_SYS_HandleT h);
fbool_t FGS_LIST_Down             (FAPI_SYS_HandleT h);
fbool_t FGS_LIST_Left             (FAPI_SYS_HandleT h);
fbool_t FGS_LIST_Right            (FAPI_SYS_HandleT h);
fbool_t FGS_LIST_Number           (FAPI_SYS_HandleT h, uint8_t value);
fbool_t FGS_LIST_Ok               (FAPI_SYS_HandleT h);
fbool_t FGS_LIST_Back             (FAPI_SYS_HandleT h);

void  FGS_LIST_DrawItemDescr      (FGS_LIST_MEMBER_S* pMem);


#ifdef __cplusplus
}
#endif

#endif /* _FGS_LIST_H_ */
/******************************************************************************/
/* END OF FILE */
