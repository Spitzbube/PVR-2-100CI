/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_item_number.h
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
#ifndef _FGS_ITEM_NUMBER_H_
#define _FGS_ITEM_NUMBER_H_

#include "fgs_list.h"


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

#define FGS_DECIMAL_PLACES_MAX 4

#define FGS_ITEM_NUM_MAX_CHARS      64

#define FGS_ITEM_NUM_BUFSIZE       (FGS_ITEM_NUM_MAX_CHARS * 2) //<! 16-Bit-
                                                                //!< Unicode!
#define FGS_ITEM_NUM_BUFCHARSET     SYS_CHARSET_ISO_10646

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef enum
{
    FGS_NITEM_TYPE_NUMBER = 0,     //!< number with no special format
    FGS_NITEM_TYPE_TIME,           //!< time
    FGS_NITEM_TYPE_DATE,           //!< date
    FGS_NITEM_TYPE_IP,             //!< IP address
    FGS_NITEM_TYPE_MAC,            //!< MAC address
    
} FGS_ITEM_NUM_TYPE_E;

typedef struct
{
    FGS_ITEM_DRAWIF_S gfx;         //!< mandatory
    
} FGS_ITEM_NUM_INIT_S;

typedef struct
{
    /* parameters needed for "number"-type only */
    int32_t                 minValue;
    int32_t                 maxValue;
    uint8_t                 maxDigits;
    int32_t                 step;
    
} FGS_ITEM_NUM_PARAMS_S;

typedef struct
{
    FGS_POS_S           pos;            //!< item area rectangle
    uint32_t            bkgrType;       //!< background type
    
    FGS_POS_S           descrPos;       //!< description position in item area
    FGS_POS_S           valuePos;       //!< value position in item area
    
    FGS_ITEM_NUM_TYPE_E type;           //!< item type
    fbool_t             wraparound;     //!< wraparound mode: 0: disabled
    
    FGS_ITEM_NUM_PARAMS_S params;
    
} FGS_ITEM_NUM_OPEN_S;

typedef struct
{
    FGS_ITEM_NUM_OPEN_S   data;
    FGS_LIST_MEMBER_S*    pMem;          //!< pointer to own member structure
    
    FGS_ITEM_S            tmpItem;
    FGS_ITEM_S            actItem;
    uint8_t               digit[FGS_ITEM_NUM_DIGITS_MAX];
    
    FGS_VAL_S             inputValue;
    uint32_t              numDigits;
    fbool_t               valueChanged;

    SYS_STRBUF_S          tmpStr;
    char_t                tmpStrBuf[FGS_ITEM_NUM_BUFSIZE];
    
} FGS_ITEM_NUM_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_ITEM_NUM_Init        (FGS_ITEM_NUM_INIT_S* pInitParams);
int32_t  FGS_ITEM_NUM_Open        (FGS_ITEM_NUM_OPEN_S* pData, int32_t id,
                                FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_ITEM_NUMBER_H_ */
/******************************************************************************/
/* END OF FILE */
