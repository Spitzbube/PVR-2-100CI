/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_panel.h
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
#ifndef _FGS_PANEL_H_
#define _FGS_PANEL_H_

#include "fgs.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef struct
{
    void (*draw)   (FAPI_SYS_HandleT h);                    // mandatory
    void (*refresh)(FAPI_SYS_HandleT h, FGS_POS_S* area);   // mandatory
    
} FGS_PANEL_DRAWIF_S;

typedef struct
{
    FGS_PANEL_DRAWIF_S draw;
    
} FGS_PANEL_INIT_S;

typedef struct
{
    FGS_POS_S           pos;         //!< panel dimensions
    uint32_t            bkgrType;    //!< background type
    fbool_t             inFront; /*16*/    //!< Display order, 1: always in front
                                     //!< of other members.
    
    FGS_FOCUSSET_CB     onFocusSet;    //!< focus-set/remove-callback (opt.)
    FAPI_SYS_HandleT    onFocusSetArg; //!< optional argument for onFocusSet
    
    void*               pInst;         //!< optional facility to pass a memory 
                                       //!< buffer for instance data
    
} FGS_PANEL_OPEN_S;

typedef struct
{
    /* written by parent */
    FGS_LOC_S      abspos;      //!< absolute member position (written by parent)
    fbool_t        posChg;      //!< notifies a change in positioning
    fbool_t        isVisible;   //!< visibility status
    fbool_t        hasFocus;    //!< focus status
    
    /* written by member */
    FAPI_SYS_HandleT h;
    FGS_POS_S*     pos;         //!< member's position and size in parent item
    int32_t        id;          //!< member ID
    fbool_t        isHidden;    //!< If FTRUE, panel member is hidden.
    
    int32_t        (*setFocus)    (FAPI_SYS_HandleT h, fbool_t hasFocus);   // optional
    int32_t        (*show)        (FAPI_SYS_HandleT h);                   // mandatory
    int32_t        (*hide)        (FAPI_SYS_HandleT h);                   // optional
    int32_t        (*close)       (FAPI_SYS_HandleT h);                   // optional
    
} FGS_PANEL_MEMBER_S;

typedef struct
{
    fbool_t            memAllocated;
    FGS_PANEL_OPEN_S   data;
    fbool_t            hasFocus;
    FGS_MEMBER_S*      pMem;            //!< pointer to own member structure
    
    uint8_t            numMembers;
    FGS_PANEL_MEMBER_S member[FGS_PANEL_MEMBERS_MAX];
    int32_t            focusIdx;
    fbool_t            autoRefresh;     //!< auto refresh status
    
} FGS_PANEL_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_PANEL_Init                (FGS_PANEL_INIT_S* pInitParams);
int32_t  FGS_PANEL_Open                (FGS_PANEL_OPEN_S* pData, int32_t id,
                                     FAPI_SYS_HandleT* ph);
int32_t  FGS_PANEL_Close               (FAPI_SYS_HandleT h);
int32_t  FGS_PANEL_AddMember           (FAPI_SYS_HandleT h, FGS_PANEL_MEMBER_S* pMember,
                                     FGS_PANEL_MEMBER_S** pId);
int32_t  FGS_PANEL_Show                (FAPI_SYS_HandleT h, fbool_t force);
int32_t  FGS_PANEL_Hide                (FAPI_SYS_HandleT h);
int32_t  FGS_PANEL_Refresh             (FAPI_SYS_HandleT h, FGS_POS_S* area);
fbool_t  FGS_PANEL_IsVisible           (FAPI_SYS_HandleT h);
int32_t  FGS_PANEL_SetRefreshMode      (FAPI_SYS_HandleT h, fbool_t autoRefresh);

int32_t  FGS_PANEL_SetMemberFocus      (FAPI_SYS_HandleT h, int32_t id);
int32_t   FGS_PANEL_GetMemberFocusID    (FAPI_SYS_HandleT h);
int32_t  FGS_PANEL_SetMemberHideStatus (FAPI_SYS_HandleT h, int32_t id, fbool_t isHidden);
int32_t  FGS_PANEL_GetMemberHideStatus (FAPI_SYS_HandleT h, int32_t id, fbool_t* isHidden);
int32_t  FGS_PANEL_RefreshMember       (FAPI_SYS_HandleT h, int32_t id);

int32_t  FGS_PANEL_GetPosition         (FAPI_SYS_HandleT h, FGS_POS_S* pos);
int32_t  FGS_PANEL_GetMemberAbsPos     (FAPI_SYS_HandleT h, int32_t id, FGS_LOC_S* abspos);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_PANEL_H_ */
/******************************************************************************/
/* END OF FILE */
