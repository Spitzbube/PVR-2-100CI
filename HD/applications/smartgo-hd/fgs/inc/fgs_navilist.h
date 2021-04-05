/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_navilist.h
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
#ifndef _FGS_NAVILIST_H_
#define _FGS_NAVILIST_H_

#include "fgs_panel.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef void  (*FGS_LNAVI_FOCUSCHG_CB)(FAPI_SYS_HandleT h, int32_t id, uint16_t focusIndex);
typedef void  (*FGS_LNAVI_SELECT_CB)  (FAPI_SYS_HandleT h, int32_t id, uint16_t index);

typedef enum
{
    FGS_LNAVI_TYPE_FIXEDPOS = 0, //!< Wraparound list, focussed item always on 
                                 //!< fixed position.
    FGS_LNAVI_TYPE_SCROLL, /*1*/      //!< Scroll list.
    FGS_LNAVI_TYPE_TXTVIEW,      //!< Scroll viewer for multiline text.
    
} FGS_LNAVI_TYPE_E;


typedef struct
{
    void (*drawLineBkgr)  (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl,
                           uint16_t x, uint16_t y, uint16_t width, uint16_t height,
                           uint16_t lineCnt, uint16_t listIndex);  // optional
    // lineCnt: index of visible line; index: line index in list (may be beyond list size)
    void (*drawScrollbar) (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl, 
                           uint16_t x, uint16_t y, uint16_t width, uint16_t height,
                           uint16_t activePos, uint16_t activeHeight);    // optional
    
} FGS_LNAVI_DRAWIF_S;

typedef struct
{
    /*! Global draw interface */
    FGS_LNAVI_DRAWIF_S draw;
    
    /*! Minimum height of scrollbar handle in pixels (useful for automatic 
        height calculation). */
    uint16_t                scrollHdlHeightMin;
    
} FGS_LNAVI_INIT_S;

typedef struct
{
    uint16_t                numItems;  /*0*/       //!< Number of list items.
    uint16_t                index;     /*2*/       //!< Focussed list index.
    uint16_t                posInVis;  /*4*/       //!< Position of focussed list index
                                              //!< in visible area.
    //6
} FGS_LNAVI_PARAMS_S;

typedef struct
{
    FGS_POS_S               pos;              //!< List position.
    fbool_t                 isHidden; /*12*/
    uint32_t                bkgrType; /*16*/        //!< Background type.
    
    FGS_LNAVI_TYPE_E        type; /*20*/            //!< List type.
    uint16_t                rowHeight; /*24*/       //!< Row height in pixels.
    uint16_t                scrollbarWidth; /*26*/  //!< Width of scrollbar in pixels
                                              //!< (0: no scrollbar).
    uint16_t                scrollHdlHeight; /*28*/ //!< Height of scrollbar handle in
                                              //!< pixels (0: automatic calculation).
    uint16_t                numVisLines; /*30*/     //!< Number of visible lines.
    uint8_t                 numColumns; /*32*/      //!< Number of columns per line.
    FGS_LNAVI_PARAMS_S      params;  /*36*/         //!< Dynamic parameters.
    uint16_t                colStart[FGS_LNAVI_COL_MAX]; //44
    uint16_t                colWidth[FGS_LNAVI_COL_MAX]; //64
    fbool_t                 topDownOrient; /*84*/   // 1 if list is printed in
                                              // ascending order from top line.
    fbool_t                 wraparound; /*88*/      //!< 1 for wraparound mode.
    
    int Data_92; //92
    int Data_96; //96

    FGS_GETITEM_CB          getItem; /*100*/      //!< Callback for acquiring line items.
    FAPI_SYS_HandleT        getItemArg; /*104*/   //!< Optional callback argument.
    FGS_FOCUSSET_CB         onFocusSet;    //!< Focus-set/remove-callback (opt.).
    FAPI_SYS_HandleT        onFocusSetArg; //!< Optional argument for onFocusSet.
    FGS_LNAVI_FOCUSCHG_CB   onFocusChg;    //!< Focus-change callback (optional).
    FAPI_SYS_HandleT        onFocusChgArg; //!< Optional argument for onFocusChg.
    FGS_LNAVI_SELECT_CB     onSelect; /*124*/     //!< Select-callback (opt.).
    FAPI_SYS_HandleT        onSelectArg;   //!< Optional argument for onSelect.
    
    void*                   pInst; /*132*/        //!< Optional facility to pass a memory
                                         //!< buffer for instance data.
    //136
} FGS_LNAVI_OPEN_S;

struct fgs_lnavi_inst_s
{
    fbool_t               memAllocated;
    FGS_LNAVI_OPEN_S      data;
    FGS_PANEL_MEMBER_S*   pMem;            //!< Pointer to own member structure.
    FGS_PANEL_INST_S*     pPanel;          //!< Pointer to parent panel.
    fbool_t               autoRefresh;     //!< Auto-refresh status.
    
    FGS_ITEM_S            pItem[FGS_LNAVI_COL_MAX];
    
    fbool_t (*up)         (struct fgs_lnavi_inst_s* inst);
    fbool_t (*down)       (struct fgs_lnavi_inst_s* inst);
    fbool_t (*pageUp)     (struct fgs_lnavi_inst_s* inst);
    fbool_t (*pageDown)   (struct fgs_lnavi_inst_s* inst);
    void  (*drawAll)      (struct fgs_lnavi_inst_s* inst);
    void  (*drawLine)     (struct fgs_lnavi_inst_s* inst, uint16_t index);
};

typedef struct fgs_lnavi_inst_s FGS_LNAVI_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_LNAVI_Init             (FGS_LNAVI_INIT_S* pInitParams);
int32_t  FGS_LNAVI_Open             (FGS_LNAVI_OPEN_S* pData, int32_t id, 
                                  FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);

fbool_t FGS_LNAVI_Up               (FAPI_SYS_HandleT h);
fbool_t FGS_LNAVI_Down             (FAPI_SYS_HandleT h);
fbool_t FGS_LNAVI_PageUp           (FAPI_SYS_HandleT h);
fbool_t FGS_LNAVI_PageDown         (FAPI_SYS_HandleT h);

int32_t  FGS_LNAVI_SetParams        (FAPI_SYS_HandleT h, const FGS_LNAVI_PARAMS_S* params);
int32_t  FGS_LNAVI_GetParams        (FAPI_SYS_HandleT h, FGS_LNAVI_PARAMS_S* params);

int32_t  FGS_LNAVI_SetRefreshMode   (FAPI_SYS_HandleT h, fbool_t autoRefresh);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_NAVILIST_H_ */
/******************************************************************************/
/* END OF FILE */
