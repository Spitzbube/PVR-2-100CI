/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_tbox.h
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
#ifndef _FGS_TBOX_H_
#define _FGS_TBOX_H_

#include "fgs_panel.h"

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef struct
{
    void (*drawLineBkgr) (FAPI_SYS_HandleT h, FGS_PANEL_INST_S* pnlHdl,
                          uint16_t x, uint16_t y, uint16_t width, uint16_t height, 
                          uint16_t lineIdx);  // optional
    
} FGS_TBOX_DRAWIF_S;

typedef struct
{
    FGS_TBOX_DRAWIF_S draw;
    
} FGS_TBOX_INIT_S;

typedef struct
{
    FGS_POS_S        pos;         //!< textbox position
    uint32_t              bkgrType;    //!< background type
    
    uint16_t              numLines;    //!< number of text lines
    uint16_t              lineHeight;  //!< line height in pixels
    
} FGS_TBOX_OPEN_S;


typedef struct
{
    char_t                text[FGS_TBOX_MAX_CHAR_PER_LINE];
    FGS_ITEM_S          item;
    
} FGS_TBOX_LINE_S;

typedef struct
{
    FGS_TBOX_OPEN_S     data;
    FGS_PANEL_MEMBER_S* pMem;            //!< pointer to own member structure
    FGS_PANEL_INST_S*   pPanel;          //!< pointer to parent panel
    FGS_TBOX_LINE_S     line[FGS_TBOX_LINES_MAX];
    
} FGS_TBOX_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_TBOX_Init             (FGS_TBOX_INIT_S* pInitParams);
int32_t  FGS_TBOX_Open             (FGS_TBOX_OPEN_S* pData, int32_t id, 
                                 FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);
int32_t  FGS_TBOX_SetText          (FAPI_SYS_HandleT h, uint16_t lineIdx, FGS_STRING_S* txt,
                                 uint8_t alignment);
int32_t  FGS_TBOX_SetType          (FAPI_SYS_HandleT h, uint32_t bkgrType);
int32_t  FGS_TBOX_Clear            (FAPI_SYS_HandleT h);
int32_t  FGS_TBOX_ClearLine        (FAPI_SYS_HandleT h, uint16_t lineIdx);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_TBOX_H_ */
/******************************************************************************/
/* END OF FILE */
