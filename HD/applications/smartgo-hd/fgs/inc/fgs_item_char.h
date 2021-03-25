/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_item_char.h
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
#ifndef _FGS_ITEM_CHAR_H_
#define _FGS_ITEM_CHAR_H_

#include "fgs_list.h"


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

#define FGS_ITEM_CHAR_BYTESPERCHAR  2
#define FGS_ITEM_CHAR_BUFSIZE       (FGS_ITEM_CHAR_MAX_CHARS *  \
                                     FGS_ITEM_CHAR_BYTESPERCHAR) //<! 16-Bit-
                                                                 //!< Unicode!
#define FGS_ITEM_CHAR_BUFCHARSET    SYS_CHARSET_ISO_10646

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef struct
{
    FGS_ITEM_DRAWIF_S gfx;
    void              (*drawBkgrSelChar)(FAPI_SYS_HandleT h, uint16_t x, uint16_t y,
                                         uint16_t width, uint16_t height);
    
} FGS_ITEM_CHAR_INIT_S;

typedef struct
{
    uint16_t                charMax;       //!< not including termination
    
} FGS_ITEM_CHAR_PARAMS_S;

typedef struct
{
    FGS_POS_S              pos;           //!< item area rectangle
    uint32_t                    bkgrType;      //!< background type
    
    FGS_POS_S              descrPos;      //!< description position in item area
    FGS_POS_S              valuePos;      //!< value position in item area
    
    FGS_ITEM_CHAR_PARAMS_S params;
    
    FGS_KEY_E              keyDeleteThis; //!< optional key for delete operation
    FGS_KEY_E              keyDeletePrev; //!< optional key for delete operation
                                          //!< of previous character
    FGS_KEY_E              keyInsertBlank;//!< optional key for insert operation
    
} FGS_ITEM_CHAR_OPEN_S;

typedef struct
{
    FGS_ITEM_CHAR_OPEN_S  data;
    FGS_LIST_MEMBER_S*    pMem;          //!< pointer to own member structure
    
    /* character input handling*/
    FGS_ITEM_S            tmpItem;
    uint16_t              strPosCurr;   //!< Current string position in bytes.
    uint16_t                   strLenCurr;
    
    SYS_STRBUF_S          tmpStr;
    char_t                tmpStrBuf[FGS_ITEM_CHAR_BUFSIZE];
    
} FGS_ITEM_CHAR_INST_S;


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_ITEM_CHAR_Init        (FGS_ITEM_CHAR_INIT_S* pInitParams);
int32_t  FGS_ITEM_CHAR_Open        (FGS_ITEM_CHAR_OPEN_S* pData, int32_t id,
                                 FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_ITEM_CHAR_H_ */
/******************************************************************************/
/* END OF FILE */
