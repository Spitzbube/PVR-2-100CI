/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_item_text.h
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
#ifndef _FGS_ITEM_TEXT_H_
#define _FGS_ITEM_TEXT_H_

#include "fgs_list.h"


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef struct
{
    FGS_ITEM_DRAWIF_S gfx;         //!< mandatory
    
} FGS_ITEM_TXT_INIT_S;

typedef struct
{
    FGS_POS_S          pos; /*0*/        //!< item area rectangle
    uint32_t           bkgrType; /*12*/   //!< background type
    
    FGS_POS_S          descrPos; /*16*/     //!< description position in item area
    FGS_POS_S          valuePos;      //!< value position in item area
    
} FGS_ITEM_TXT_OPEN_S;

typedef struct
{
    FGS_ITEM_TXT_OPEN_S   data;
    FGS_LIST_MEMBER_S*    pMem;          //!< pointer to own member structure
    
} FGS_ITEM_TXT_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

// TODO: to be renamed: is general item
int32_t  FGS_ITEM_TXT_Init        (FGS_ITEM_TXT_INIT_S* pInitParams);
int32_t  FGS_ITEM_TXT_Open        (FGS_ITEM_TXT_OPEN_S* pData, int32_t id,
                                FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_ITEM_TEXT_H_ */
/******************************************************************************/
/* END OF FILE */
