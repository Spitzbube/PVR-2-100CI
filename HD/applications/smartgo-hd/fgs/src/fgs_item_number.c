/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_item_number.c
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
**
** \note The following LINT statements have been suppressed:
**
** - Info    732: Loss of sign (assignment) (int to unsigned short).
** - Info    737: Loss of sign in promotion from int to unsigned int.
**
*****************************************************************************
*/
/*lint -save -e732 -e737 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_item_number.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

static int32_t        FGS_ITEM_NUM_Close         (FAPI_SYS_HandleT h);
static int32_t        FGS_ITEM_NUM_Draw          (FAPI_SYS_HandleT h);
static int32_t        FGS_ITEM_NUM_SetFocus      (FAPI_SYS_HandleT h,
                                                   fbool_t hasFocus);
static int32_t        FGS_ITEM_NUM_Activate      (FAPI_SYS_HandleT h);
static int32_t        FGS_ITEM_NUM_Deactivate    (FAPI_SYS_HandleT h,
                                                   fbool_t keepChanges);
static int32_t        FGS_ITEM_NUM_GetParams     (FAPI_SYS_HandleT h,
                                                   void* params);
static int32_t        FGS_ITEM_NUM_SetParams     (FAPI_SYS_HandleT h,
                                                   const void* params);
static fbool_t        FGS_ITEM_NUM_Left          (FAPI_SYS_HandleT h);
static fbool_t        FGS_ITEM_NUM_Right         (FAPI_SYS_HandleT h);
static fbool_t        FGS_ITEM_NUM_Number        (FAPI_SYS_HandleT h,
                                                   uint8_t value);
static FGS_ITEM_S*    FGS_ITEM_NUM_GetActiveItem (FGS_ITEM_NUM_INST_S* inst);
static int32_t        FGS_ITEM_NUM_CheckParams   (FGS_ITEM_NUM_TYPE_E type,
                                                   FGS_ITEM_NUM_PARAMS_S* params);
static int32_t        FGS_ITEM_NUM_CheckDate     (SYS_DATE_S date);
/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

static FGS_ITEM_NUM_INIT_S*     fgsItemNumGlobal   = NULL;
static FGS_ITEM_DRAWIF_S*       fgsNumDraw  = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

int32_t FGS_ITEM_NUM_Init (FGS_ITEM_NUM_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsItemNumGlobal = FGS_Malloc(sizeof(FGS_ITEM_NUM_INIT_S));
    if ( fgsItemNumGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsItemNumGlobal) = (*pInitParams);

    fgsNumDraw = &(fgsItemNumGlobal->gfx);

    return FAPI_OK;
}

int32_t FGS_ITEM_NUM_Open (FGS_ITEM_NUM_OPEN_S* pData, int32_t id,
                           FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph)
{
    FGS_ITEM_NUM_INST_S*  inst;
    FGS_LIST_MEMBER_S     member;
    int32_t               retVal;
    FGS_ITEM_NUM_PARAMS_S tmpPars;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    tmpPars = pData->params;

    retVal = FGS_ITEM_NUM_CheckParams(pData->type, &tmpPars);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    inst = FGS_Malloc(sizeof(FGS_ITEM_NUM_INST_S));
    if ( inst == NULL )
    {
        retVal = SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }
    else
    {
        inst->data         = *pData;
        inst->data.params  = tmpPars;
        inst->pMem         = NULL;
        inst->numDigits    = 0;
        inst->valueChanged = FFALSE;

        retVal = STR_BufOpen (&(inst->tmpStr), FGS_ITEM_NUM_BUFSIZE,
                              inst->tmpStrBuf);

        if ( retVal == FAPI_OK )
        {
            *ph = (FAPI_SYS_HandleT)inst;

            /* add as list member */

            memset(&member, 0, sizeof(FGS_LIST_MEMBER_S));

            member.h           = (FAPI_SYS_HandleT)inst;
            member.pos         = &(inst->data.pos);
            member.id          = id;
            member.isVisible   = FFALSE;
            member.hasFocus    = FFALSE;
            member.isActivated = FFALSE;
            member.descrPos    = inst->data.descrPos;
            member.valuePos    = inst->data.valuePos;
            member.setFocus    = FGS_ITEM_NUM_SetFocus;
            member.draw        = FGS_ITEM_NUM_Draw;
            member.close       = FGS_ITEM_NUM_Close;
            member.activate    = FGS_ITEM_NUM_Activate;
            member.deactivate  = FGS_ITEM_NUM_Deactivate;
            member.getParams   = FGS_ITEM_NUM_GetParams;
            member.setParams   = FGS_ITEM_NUM_SetParams;
            member.left        = FGS_ITEM_NUM_Left;
            member.right       = FGS_ITEM_NUM_Right;
            member.number      = FGS_ITEM_NUM_Number;

            retVal = FGS_LIST_AddMember (parent, &member, &(inst->pMem));

            if ( retVal != FAPI_OK )
            {
                (void)STR_BufClose(&(inst->tmpStr));
            }
        }

        if ( retVal != FAPI_OK )
        {
            FGS_Free(inst);
        }
    }

    return retVal;
}

static int32_t FGS_ITEM_NUM_Close (FAPI_SYS_HandleT h)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    (void)STR_BufClose(&(inst->tmpStr));

    FGS_Free(inst);

    return FAPI_OK;

}

static int32_t FGS_ITEM_NUM_Draw (FAPI_SYS_HandleT h)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;
    FGS_ITEM_S           currItem;
    FGS_ITEM_S*          pItem = &currItem;
    FGS_ITEMSTATE_E      state;

    if ( !(inst->pMem->isVisible) ) return FAPI_OK;

    memset(&currItem, 0, sizeof(currItem));
    currItem.type = FGS_ITEM_TYPE_NONE;

    if ( inst->pMem->isActivated )
    {
       /* Generated special item in activated state */
        pItem = FGS_ITEM_NUM_GetActiveItem (inst);
    }
    else if ( inst->pMem->pParent->getItem != NULL ) /* get item */
    {
        if      (!(inst->pMem->isEnabled)) state = FGS_DISABLED;
        else if   (inst->pMem->hasFocus)   state = FGS_FOCUS;
        else                               state = FGS_NONFOCUS;

        inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                      inst->pMem->id, 0, state, &currItem);
    }

    /* paint background */
    if ( fgsNumDraw->drawBkgr != NULL )
    {
        fgsNumDraw->drawBkgr (h, inst->pMem->pPanel, pItem);
    }

    FGS_LIST_DrawItemDescr(inst->pMem);

    /* draw value item */
    (void)FGS_DrawItem (pItem,
                       inst->pMem->abspos.x + inst->pMem->valuePos.x,
                       inst->pMem->abspos.y + inst->pMem->valuePos.y,
                       inst->pMem->valuePos.width,
                       inst->pMem->valuePos.height);

    /* paint rest */
    if ( fgsNumDraw->drawRest != NULL )
    {
        fgsNumDraw->drawRest(h);
    }

    return FAPI_OK;
}

int32_t  FGS_ITEM_NUM_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;

    if ( inst->pMem->hasFocus == hasFocus ) return FAPI_OK;

    inst->pMem->hasFocus = hasFocus;

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible ) (void)FGS_ITEM_NUM_Draw(h);
    return FAPI_OK;
}

int32_t  FGS_ITEM_NUM_Activate (FAPI_SYS_HandleT h)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;
    FGS_ITEMSTATE_E      state;

    if (inst == NULL) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( inst->pMem->isActivated ) return FAPI_OK;

    if ( inst->pMem->pParent->getItem == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    if      (!(inst->pMem->isEnabled)) state = FGS_DISABLED;
    else if   (inst->pMem->hasFocus)   state = FGS_FOCUS;
    else                               state = FGS_NONFOCUS;

    memset(&(inst->tmpItem), 0, sizeof(inst->tmpItem));

    /* get current value for temporal storage */
    inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                  inst->pMem->id, 0, state, &(inst->tmpItem));

    /* activation not possible for all types */
    switch ( inst->data.type )
    {
        case FGS_NITEM_TYPE_NUMBER:
            inst->inputValue.number = 0;
            break;

        case FGS_NITEM_TYPE_TIME:
            inst->inputValue.time = inst->tmpItem.item.time.value;
            break;

        case FGS_NITEM_TYPE_DATE:
            inst->inputValue.date = inst->tmpItem.item.date.value;
            break;

        case FGS_NITEM_TYPE_IP:
            memcpy(inst->inputValue.ip,inst->tmpItem.item.ip.value,sizeof(FAPI_ETH_Ip4T));
            break;

        case FGS_NITEM_TYPE_MAC:
            memcpy(inst->inputValue.mac,inst->tmpItem.item.mac.value,sizeof(FAPI_ETH_MacT));
            break;

        default:
            return SMARTGO_FGS_ERR_PROHIBITED;
    }

    inst->numDigits         = 0;
    inst->valueChanged      = FFALSE;
    inst->pMem->isActivated = FTRUE;

    (void)FGS_ITEM_NUM_Draw(h);

    return FAPI_OK;
}

int32_t  FGS_ITEM_NUM_Deactivate (FAPI_SYS_HandleT h, fbool_t keepChanges)
{
    FGS_ITEM_NUM_INST_S* inst    = (FGS_ITEM_NUM_INST_S*)h;
    fbool_t              valueOk = FFALSE;
    uint32_t             cnt;

    if ( inst == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;

    if ( !(inst->pMem->isActivated) ) return FAPI_OK;

    /* activation/deactivation not possible for all types */
    switch ( inst->data.type )
    {
        case FGS_NITEM_TYPE_NUMBER:
        case FGS_NITEM_TYPE_TIME:
        case FGS_NITEM_TYPE_DATE:
        case FGS_NITEM_TYPE_IP:
        case FGS_NITEM_TYPE_MAC:
            break;

        default:
            return SMARTGO_FGS_ERR_PROHIBITED;
    }

    if ( keepChanges && (inst->valueChanged) )
    {
        switch ( inst->data.type )
        {
            case FGS_NITEM_TYPE_NUMBER:

                /* calculate number value from digit array */
                inst->inputValue.number = 0;

                for ( cnt = 0; cnt < inst->numDigits; cnt++ )
                {
                    inst->inputValue.number *= 10;
                    inst->inputValue.number += inst->digit[cnt];
                }

                if ( (inst->inputValue.number <= inst->data.params.maxValue) &&
                     (inst->inputValue.number >= inst->data.params.minValue) )
                {
                    valueOk = FTRUE;
                }
                break;

            case FGS_NITEM_TYPE_TIME:
            case FGS_NITEM_TYPE_DATE:
            case FGS_NITEM_TYPE_IP:
            case FGS_NITEM_TYPE_MAC:
                valueOk = FTRUE;
                break;

            default:
                break;
        }

        if ( valueOk )
        {
            if ( inst->pMem->pParent->onValChg != NULL )
            {
                inst->pMem->pParent->onValChg(inst->pMem->pParent->onValChgArg,
                                              inst->pMem->id,
                                              inst->inputValue);
            }
        }
    }

    inst->pMem->isActivated = FFALSE;

    (void)FGS_ITEM_NUM_Draw(h);

    return FAPI_OK;
}

int32_t FGS_ITEM_NUM_GetParams (FAPI_SYS_HandleT h, void* params)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;

    if ( inst   == NULL ) return SMARTGO_FGS_ERR_INVALID_HANDLE;
    if ( params == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    *((FGS_ITEM_NUM_PARAMS_S*)params) = inst->data.params;
    return FAPI_OK;
}

int32_t FGS_ITEM_NUM_SetParams (FAPI_SYS_HandleT h, const void* params)
{
    FGS_ITEM_NUM_INST_S*  inst   = (FGS_ITEM_NUM_INST_S*)h;
    int32_t               retVal = FAPI_OK;
    FGS_ITEM_NUM_PARAMS_S tmpPars;

    if ( inst   == NULL )
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    if ( params == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    if ( inst->pMem->isActivated )
    {
        return SMARTGO_FGS_ERR_DEVICE_BUSY;
    }

    tmpPars = *((FGS_ITEM_NUM_PARAMS_S*)params);

    retVal = FGS_ITEM_NUM_CheckParams(inst->data.type, &tmpPars);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    inst->data.params = tmpPars;

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible &&
         inst->pMem->pParent->autoRefresh ) (void)FGS_ITEM_NUM_Draw(h);

    return retVal;
}

fbool_t FGS_ITEM_NUM_Left (FAPI_SYS_HandleT h)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;
    FGS_ITEMSTATE_E      state;
    FGS_ITEM_S           item;
    FGS_VAL_S            newValue;
    fbool_t              valChanged = FFALSE;

    if ( inst == NULL ) return FFALSE;

    if ( inst->pMem->pParent->getItem == NULL )return FFALSE;

    if      (!(inst->pMem->isEnabled)) state = FGS_DISABLED;
    else if   (inst->pMem->hasFocus)   state = FGS_FOCUS;
    else                               state = FGS_NONFOCUS;

    memset(&item,     0, sizeof(item));
    memset(&newValue, 0, sizeof(newValue));

    /* get current value for temporal storage */
    inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                  inst->pMem->id, 0, state, &item);

    switch ( inst->data.type )
    {
        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_NUMBER:
            if ( inst->pMem->isActivated ) return FFALSE;

            if ( item.item.number.value >=
                (inst->data.params.minValue + inst->data.params.step) )
            {
                if ( (item.item.number.value % inst->data.params.step) != 0 )
                {
                    item.item.number.value -= item.item.number.value %
                                              inst->data.params.step;
                }
                else
                {
                    item.item.number.value -= inst->data.params.step;
                }
            }
            else if ( !(inst->data.wraparound) )
            {
                item.item.number.value = inst->data.params.minValue;
            }
            else
            {
                item.item.number.value = inst->data.params.maxValue;
            }

            valChanged      = FTRUE;
            newValue.number = item.item.number.value;
            break;

        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_TIME:
            if ( inst->pMem->isActivated )
            {
                if ( inst->numDigits > 0 ) inst->numDigits--;
            }
            else
            {
                /* subtract a minute from current value */
                TIME_AddSeconds(&(item.item.time.value), NULL, -60);

                valChanged    = FTRUE;
                newValue.time = item.item.time.value;
            }
            break;

        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_DATE:

            /* subtract a day from current date */
            TIME_AddDays(&(item.item.date.value), -1);

            valChanged    = FTRUE;
            newValue.date = item.item.date.value;
            break;

        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_IP:
        case FGS_NITEM_TYPE_MAC:
        default:
            return FFALSE;
    }

    if ( valChanged && (inst->pMem->pParent->onValChg != NULL) )
    {
        inst->pMem->pParent->onValChg(inst->pMem->pParent->onValChgArg,
                                      inst->pMem->id, newValue);
    }

    (void)FGS_ITEM_NUM_Draw(h);

    return FTRUE;
}

fbool_t FGS_ITEM_NUM_Right (FAPI_SYS_HandleT h)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;
    FGS_ITEMSTATE_E      state;
    FGS_ITEM_S           item;
    FGS_VAL_S            newValue;
    fbool_t              valChanged = FFALSE;

    if ( inst == NULL ) return FFALSE;

    if ( inst->pMem->pParent->getItem == NULL ) return FFALSE;

    if      (!(inst->pMem->isEnabled)) state = FGS_DISABLED;
    else if   (inst->pMem->hasFocus)   state = FGS_FOCUS;
    else                               state = FGS_NONFOCUS;

    memset(&item,     0, sizeof(item));
    memset(&newValue, 0, sizeof(newValue));

    /* get current value for temporal storage */
    inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                  inst->pMem->id, 0, state, &item);

    switch ( inst->data.type )
    {
        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_NUMBER:
            if ( inst->pMem->isActivated ) return FFALSE;

            item.item.number.value += inst->data.params.step;

            if ( (item.item.number.value % inst->data.params.step) != 0 )
            {
                item.item.number.value -= item.item.number.value %
                                          inst->data.params.step;
            }

            if (item.item.number.value > inst->data.params.maxValue)
            {
                if ( inst->data.wraparound == FFALSE )
                {
                    item.item.number.value = inst->data.params.maxValue;
                }
                else
                {
                    item.item.number.value = inst->data.params.minValue;
                }
            }

            valChanged      = FTRUE;
            newValue.number = item.item.number.value;
            break;

        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_TIME:
            if ( inst->pMem->isActivated )
            {
                if ( inst->numDigits < 3 ) inst->numDigits++;
            }
            else
            {
                /* add a minute to current value */
                TIME_AddSeconds(&(item.item.time.value), NULL, 60);

                valChanged    = FTRUE;
                newValue.time = item.item.time.value;
            }
            break;

        /* ----------------------------------------------------------------- */

        case FGS_NITEM_TYPE_DATE:

            /* add a day to current date */
            TIME_AddDays(&(item.item.date.value), 1);

            valChanged    = FTRUE;
            newValue.date = item.item.date.value;
            break;

        case FGS_NITEM_TYPE_IP:
        case FGS_NITEM_TYPE_MAC:
        default:
            return FFALSE;
    }

    if ( valChanged && (inst->pMem->pParent->onValChg != NULL) )
    {
        inst->pMem->pParent->onValChg(inst->pMem->pParent->onValChgArg,
                                      inst->pMem->id,
                                      newValue);
    }

    (void)FGS_ITEM_NUM_Draw(h);

    return FTRUE;
}

fbool_t FGS_ITEM_NUM_Number (FAPI_SYS_HandleT h, uint8_t value)
{
    FGS_ITEM_NUM_INST_S* inst = (FGS_ITEM_NUM_INST_S*)h;
    uint32_t             tmpUpper;
    uint32_t             tmpLower;
    uint8_t              maxDigits = 0;
    uint8_t              tenth;

    if ( inst == NULL )                      return FFALSE;
    if ( inst->pMem->isActivated == FFALSE ) return FFALSE;

    switch ( inst->data.type )
    {
        case FGS_NITEM_TYPE_NUMBER:
            if ( inst->numDigits >= inst->data.params.maxDigits )
            {
                /* Reset input if max. number of digits is reached */
                inst->numDigits = 0;
            }

            inst->digit[inst->numDigits++] = value;
            inst->valueChanged             = FTRUE;

            #if 0
            tempVal = (inst->inputValue.number * 10) + value;

            // FIXME: needed?
            if ( (tempVal         <= inst->data.params.maxValue) &&
                 (inst->numDigits <  inst->data.params.maxDigits) )
            {
                inst->valueChanged      = FTRUE;
                inst->inputValue.number = tempVal;
                inst->numDigits++;
            }
            #endif
            break;

        case FGS_NITEM_TYPE_TIME:

            switch ( inst->numDigits )
            {
                case 0: /* set hours: tens */
                    if ( value > 2 ) break;

                    inst->inputValue.time.hour %= 10;
                    inst->inputValue.time.hour += (uint8_t)(value * 10);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;

                case 1: /* set hours: units */
                    if ( ((uint8_t)(inst->inputValue.time.hour / 10) >= 2) &&
                         (value > 3) )
                    {
                        break;
                    }

                    inst->inputValue.time.hour /= 10;
                    inst->inputValue.time.hour *= 10;
                    inst->inputValue.time.hour += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;

                case 2: /* set minutes: tens */
                    if ( value > 5 ) break;

                    inst->inputValue.time.minute %= 10;
                    inst->inputValue.time.minute += (uint8_t)(value * 10);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;

                case 3: /* set minutes: units */

                    inst->inputValue.time.minute /= 10;
                    inst->inputValue.time.minute *= 10;
                    inst->inputValue.time.minute += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;

                default:
                    break;
            }

            /* deactivate item if last digit has been input */
            if ( inst->numDigits >= 4 )
            {
                (void)FGS_ITEM_NUM_Deactivate (h, FTRUE);
                return FTRUE;
            }
            break;

        case FGS_NITEM_TYPE_DATE:

            switch (inst->tmpItem.item.date.format)
            {
                // yyyy-mm-dd: International format
                case FGS_FORMAT_DATE_INT_NORM:
                    maxDigits = 8;
                    switch ( inst->numDigits )
                    {
                        case 0: /* set year: x000 */
                            if ( value > 2 ) break; /* max 2199 */

                            inst->inputValue.date.year %= 1000;
                            inst->inputValue.date.year += (value * 1000);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 1: /* set year: 0x00 */
                            if ( ((uint8_t)(inst->inputValue.date.year / 1000) >= 2) &&
                                 (value > 1) ) break; /* max 2199 */

                            tmpUpper  = inst->inputValue.date.year;
                            tmpUpper /= 1000;
                            tmpUpper *= 1000;
                            tmpLower  = inst->inputValue.date.year;
                            tmpLower %=  100;
                            inst->inputValue.date.year = tmpUpper + (value*100) + tmpLower;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 2: /* set year: 00x0 */
                            tmpUpper  = inst->inputValue.date.year;
                            tmpUpper /= 100;
                            tmpUpper *= 100;
                            tmpLower  = inst->inputValue.date.year;
                            tmpLower %=  10;
                            inst->inputValue.date.year = tmpUpper + (value*10) + tmpLower;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 3: /* set year: 000x */
                            inst->inputValue.date.year /= 10;
                            inst->inputValue.date.year *= 10;
                            inst->inputValue.date.year += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 4: /* set month x0 */
                            if (value > 1) break;

                            inst->inputValue.date.month %= 10;
                            inst->inputValue.date.month += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 5: /* set month 0x */
                            if ( ((uint8_t)(inst->inputValue.date.month / 10) >= 1) &&
                                 (value > 2) ) break; /* 12 month */

                            inst->inputValue.date.month /= 10;
                            inst->inputValue.date.month *= 10;
                            inst->inputValue.date.month += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 6: /* day x0 */
                            if ( value > 3 ) break; /* 31 days */

                            inst->inputValue.date.day %= 10;
                            inst->inputValue.date.day += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 7: /* day 0x */
                            if ( ((uint8_t)(inst->inputValue.date.day / 10) >= 3) &&
                                 (value > 1) ) break; /* 31 days */

                            inst->inputValue.date.day /= 10;
                            inst->inputValue.date.day *= 10;
                            inst->inputValue.date.day += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        default:
                            /* do nothing */
                            break;
                    }
                    break;

                // mm-dd: Internation format without year
                case FGS_FORMAT_DATE_INT_SHORT:
                    maxDigits = 4;
                    /* set default year to create a valid date */
                    inst->inputValue.date.year = 2000;
                    switch ( inst->numDigits )
                    {
                        case 0: /* set month x0 */
                            if (value > 1) break;

                            inst->inputValue.date.month %= 10;
                            inst->inputValue.date.month += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 1: /* set month 0x */
                            if ( ((uint8_t)(inst->inputValue.date.month / 10) >= 1) &&
                                 (value > 2) ) break; /* 12 month */

                            inst->inputValue.date.month /= 10;
                            inst->inputValue.date.month *= 10;
                            inst->inputValue.date.month += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 2: /* day x0 */
                            if ( value > 3 ) break; /* 31 days */

                            inst->inputValue.date.day %= 10;
                            inst->inputValue.date.day += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 3: /* day 0x */
                            if ( ((uint8_t)(inst->inputValue.date.day / 10) >= 3) &&
                                 (value > 1) ) break; /* 31 days */

                            inst->inputValue.date.day /= 10;
                            inst->inputValue.date.day *= 10;
                            inst->inputValue.date.day += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        default:
                            /* do nothing */
                            break;
                    }
                    break;

                //dd.mm.yyyy: European notation
                case FGS_FORMAT_DATE_EUROPE_NORM:
                    maxDigits = 8;
                    switch ( inst->numDigits )
                    {
                        case 0: /* day x0 */
                            if ( value > 3 ) break; /* 31 days */

                            inst->inputValue.date.day %= 10;
                            inst->inputValue.date.day += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 1: /* day 0x */
                            if ( ((uint8_t)(inst->inputValue.date.day / 10) >= 3) &&
                                 (value > 1) ) break; /* 31 days */

                            inst->inputValue.date.day /= 10;
                            inst->inputValue.date.day *= 10;
                            inst->inputValue.date.day += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 2: /* set month x0 */
                            if (value > 1) break;

                            inst->inputValue.date.month %= 10;
                            inst->inputValue.date.month += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 3: /* set month 0x */
                            if ( ((uint8_t)(inst->inputValue.date.month / 10) >= 1) &&
                                 (value > 2) ) break; /* 12 month */

                            inst->inputValue.date.month /= 10;
                            inst->inputValue.date.month *= 10;
                            inst->inputValue.date.month += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 4: /* set year: x000 */
                            if ( value > 2 ) break; /* max 2199 */

                            inst->inputValue.date.year %= 1000;
                            inst->inputValue.date.year += (value * 1000);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 5: /* set year: 0x00 */
                            if ( ((uint8_t)(inst->inputValue.date.year / 1000) >= 2) &&
                                 (value > 1) ) break; /* max 2199 */

                            tmpUpper  = inst->inputValue.date.year;
                            tmpUpper /= 1000;
                            tmpUpper *= 1000;
                            tmpLower  = inst->inputValue.date.year;
                            tmpLower %=  100;
                            inst->inputValue.date.year = tmpUpper + (value*100) + tmpLower;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 6: /* set year: 00x0 */
                            tmpUpper  = inst->inputValue.date.year;
                            tmpUpper /= 100;
                            tmpUpper *= 100;
                            tmpLower  = inst->inputValue.date.year;
                            tmpLower %=  10;
                            inst->inputValue.date.year = tmpUpper + (value*10) + tmpLower;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 7: /* set year: 000x */
                            inst->inputValue.date.year /= 10;
                            inst->inputValue.date.year *= 10;
                            inst->inputValue.date.year += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        default:
                            /* do nothing */
                            break;
                    }
                    break;

                // dd.mm.: European notation without year
                case FGS_FORMAT_DATE_EUROPE_SHORT:
                    maxDigits = 4;
                    /* set default year to create a valid date */
                    inst->inputValue.date.year = 2000;
                    switch ( inst->numDigits )
                    {
                        case 0: /* day x0 */
                            if ( value > 3 ) break; /* 31 days */

                            inst->inputValue.date.day %= 10;
                            inst->inputValue.date.day += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 1: /* day 0x */
                            if ( ((uint8_t)(inst->inputValue.date.day / 10) >= 3) &&
                                 (value > 1) ) break; /* 31 days */

                            inst->inputValue.date.day /= 10;
                            inst->inputValue.date.day *= 10;
                            inst->inputValue.date.day += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 2: /* set month x0 */
                            if (value > 1) break;

                            inst->inputValue.date.month %= 10;
                            inst->inputValue.date.month += (uint8_t)(value * 10);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        case 3: /* set month 0x */
                            if ( ((uint8_t)(inst->inputValue.date.month / 10) >= 1) &&
                                 (value > 2) ) break; /* 12 month */

                            inst->inputValue.date.month /= 10;
                            inst->inputValue.date.month *= 10;
                            inst->inputValue.date.month += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;

                        default:
                            /* do nothing */
                            break;
                    }
                    break;

                default:
                    /* do nothing */
                    break;
            }

            /* deactivate item if last digit has been input */
            if ( inst->numDigits >= maxDigits )
            {
                /* check here if date is valid */
                if ( FGS_ITEM_NUM_CheckDate(inst->inputValue.date) == FAPI_OK )
                {
                    (void)FGS_ITEM_NUM_Deactivate (h, FTRUE);
                }
                else
                {
                    (void)FGS_ITEM_NUM_Deactivate (h, FFALSE);
                }

                return FTRUE;
            }
            break;

        case FGS_NITEM_TYPE_IP:
            switch (inst->tmpItem.item.ip.format)
            {
                case FGS_FORMAT_IP_V4:
                    switch ( inst->numDigits )
                    {
                        case 0: /*  x00.000.000.000 */
                            if ( value > 2 ) break; /* max 255 */

                            inst->inputValue.ip[0] %= 100;
                            inst->inputValue.ip[0] += (uint8_t)(value * 100);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 1: /*  0x0.000.000.000 */
                            if ( ((uint8_t)(inst->inputValue.ip[0] / 100) >= 2) &&
                                  (value > 5) ) break; /* max 255 */

                            // 00x
                            tenth = inst->inputValue.ip[0] % 10;

                            // x00
                            inst->inputValue.ip[0] /= 100;
                            inst->inputValue.ip[0] *= 100;

                            // 0x0
                            inst->inputValue.ip[0] += (uint8_t)(value * 10);

                            inst->inputValue.ip[0] += tenth;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 2: /*  00x.000.000.000 */
                            if ( ((uint8_t)(inst->inputValue.ip[0] / 10) >= 25) &&
                                 (value > 5) ) break; /* max 255 */

                            inst->inputValue.ip[0] /= 10;
                            inst->inputValue.ip[0] *= 10;
                            inst->inputValue.ip[0] += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 3: /*  000.x00.000.000 */
                            if ( value > 2 ) break; /* max 255 */

                            inst->inputValue.ip[1] %= 100;
                            inst->inputValue.ip[1] += (uint8_t)(value * 100);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 4: /*  000.0x0.000.000 */
                            if ( ((uint8_t)(inst->inputValue.ip[1] / 100) >= 2) &&
                                  (value > 5) ) break; /* max 255 */

                            // 00x
                            tenth = inst->inputValue.ip[1] % 10;

                            // x00
                            inst->inputValue.ip[1] /= 100;
                            inst->inputValue.ip[1] *= 100;

                            // 0x0
                            inst->inputValue.ip[1] += (uint8_t)(value * 10);

                            inst->inputValue.ip[1] += tenth;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 5: /*  000.00x.000.000 */
                            if ( ((uint8_t)(inst->inputValue.ip[1] / 10) >= 25) &&
                                 (value > 5) ) break; /* max 255 */

                            inst->inputValue.ip[1] /= 10;
                            inst->inputValue.ip[1] *= 10;
                            inst->inputValue.ip[1] += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 6: /*  000.000.x00.000 */
                            if ( value > 2 ) break; /* max 255 */

                            inst->inputValue.ip[2] %= 100;
                            inst->inputValue.ip[2] += (uint8_t)(value * 100);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 7: /*  000.000.0x0.000 */
                            if ( ((uint8_t)(inst->inputValue.ip[2] / 100) >= 2) &&
                                  (value > 5) ) break; /* max 255 */

                            // 00x
                            tenth = inst->inputValue.ip[2] % 10;

                            // x00
                            inst->inputValue.ip[2] /= 100;
                            inst->inputValue.ip[2] *= 100;

                            // 0x0
                            inst->inputValue.ip[2] += (uint8_t)(value * 10);

                            inst->inputValue.ip[2] += tenth;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 8: /*  000.000.00x.000 */
                            if ( ((uint8_t)(inst->inputValue.ip[2] / 10) >= 25) &&
                                 (value > 5) ) break; /* max 255 */

                            inst->inputValue.ip[2] /= 10;
                            inst->inputValue.ip[2] *= 10;
                            inst->inputValue.ip[2] += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 9: /*  000.000.000.x00 */
                            if ( value > 2 ) break; /* max 255 */

                            inst->inputValue.ip[3] %= 100;
                            inst->inputValue.ip[3] += (uint8_t)(value * 100);

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 10: /*  000.000.000.0x0 */
                            if ( ((uint8_t)(inst->inputValue.ip[3] / 100) >= 2) &&
                                  (value > 5) ) break; /* max 255 */

                            // 00x
                            tenth = inst->inputValue.ip[3] % 10;

                            // x00
                            inst->inputValue.ip[3] /= 100;
                            inst->inputValue.ip[3] *= 100;

                            // 0x0
                            inst->inputValue.ip[3] += (uint8_t)(value * 10);

                            inst->inputValue.ip[3] += tenth;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        case 11: /*  000.000.000.00x */
                            if ( ((uint8_t)(inst->inputValue.ip[3] / 10) >= 25) &&
                                 (value > 5) ) break; /* max 255 */

                            inst->inputValue.ip[3] /= 10;
                            inst->inputValue.ip[3] *= 10;
                            inst->inputValue.ip[3] += value;

                            inst->valueChanged = FTRUE;
                            inst->numDigits++;
                            break;
                        default:
                            break;
                    }

                break;
                case FGS_FORMAT_IP_V6: /* notsupported yet */
                default:
                break;
            }
            break;

        case FGS_NITEM_TYPE_MAC:
            switch ( inst->numDigits )
            {
                case 0: /*  x0:00:00:00:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[0] &= 0x0F;
                    inst->inputValue.mac[0] += (uint8_t)(value << 4);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 1: /*  0x:00:00:00:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[0] &= 0xF0;
                    inst->inputValue.mac[0] += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 2: /*  00:x0:00:00:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[1] &= 0x0F;
                    inst->inputValue.mac[1] += (uint8_t)(value << 4);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 3: /*  00:0x:00:00:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[1] &= 0xF0;
                    inst->inputValue.mac[1] += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 4: /*  00:00:x0:00:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[2] &= 0x0F;
                    inst->inputValue.mac[2] += (uint8_t)(value << 4);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 5: /*  00:00:0x:00:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[2] &= 0xF0;
                    inst->inputValue.mac[2] += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 6: /*  00:00:00:x0:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[3] &= 0x0F;
                    inst->inputValue.mac[3] += (uint8_t)(value << 4);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 7: /*  00:00:00:0x:00:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[3] &= 0xF0;
                    inst->inputValue.mac[3] += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 8: /*  00:00:00:00:x0:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[4] &= 0x0F;
                    inst->inputValue.mac[4] += (uint8_t)(value << 4);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 9: /*  00:00:00:00:0x:00 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[4] &= 0xF0;
                    inst->inputValue.mac[4] += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 10: /*  00:00:00:00:00:x0 */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[5] &= 0x0F;
                    inst->inputValue.mac[5] += (uint8_t)(value << 4);

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                case 11: /*  00:00:00:00:00:0x */
                    if ( value > 0x0F ) break; /* max 0xFF */

                    inst->inputValue.mac[5] &= 0xF0;
                    inst->inputValue.mac[5] += value;

                    inst->valueChanged = FTRUE;
                    inst->numDigits++;
                    break;
                default:
                    break;
            }
            break;
        default:
            return FFALSE;
    }

    (void)FGS_ITEM_NUM_Draw(h);

    return FTRUE;
}

static FGS_ITEM_S* FGS_ITEM_NUM_GetActiveItem (FGS_ITEM_NUM_INST_S* inst)
{
    uint32_t strLen = 0;
    uint32_t bufPos = 0;
    char_t   tmpBuf[FGS_ITEM_NUM_MAX_CHARS];
    uint16_t cnt;

    /* convert any item into a temporary string item */
    inst->actItem.type                   = FGS_ITEM_TYPE_STRING;
    inst->actItem.align                  = inst->tmpItem.align;
    inst->actItem.item.str.lineHeight    = 0;

    tmpBuf[0] = 0;

    switch ( inst->data.type )
    {
        case FGS_NITEM_TYPE_NUMBER:
            inst->actItem.item.str.font = inst->tmpItem.item.number.font;
            inst->actItem.item.str.col  = inst->tmpItem.item.number.col;

            if ( inst->tmpItem.item.number.decimalPlaces == 0 )
            {
                for ( cnt = 0; cnt < inst->numDigits; cnt++ )
                {
                    tmpBuf[strLen++] = (char_t)inst->digit[cnt] + '0';
                }

                tmpBuf[strLen++] = '_';
            }
            else
            {
                if ( inst->tmpItem.item.number.decimalPlaces >= inst->numDigits )
                {
                    tmpBuf[strLen++] = '.';

                    for ( cnt = 0; cnt < (inst->tmpItem.item.number.decimalPlaces - inst->numDigits); cnt++ )
                    {
                        //tmpBuf[strLen++] = '0';
                        tmpBuf[strLen++] = '_';
                    }

                    for ( cnt = 0; cnt < inst->numDigits; cnt++ )
                    {
                        tmpBuf[strLen++] = (char_t)inst->digit[cnt] + '0';
                    }
                }
                else
                {
                    for ( cnt = 0; cnt < inst->numDigits; cnt++ )
                    {
                        tmpBuf[strLen++] = (char_t)inst->digit[cnt] + '0';
                    }

                    for ( cnt = (strLen - 1);
                          cnt >= (strLen - inst->tmpItem.item.number.decimalPlaces);
                          cnt-- )
                    {
                        tmpBuf[cnt + 1] = tmpBuf[cnt];
                    }

                    tmpBuf[cnt + 1] = '.';
                    strLen++;
                }
            }

            tmpBuf[strLen] = 0; /* terminate string */

            bufPos += STR_BufAppend (&(inst->tmpStr), bufPos,
                                     STR_GetASCII(tmpBuf),
                                     FGS_ITEM_NUM_BUFCHARSET);
            /* append unit if necessary */
            if ( (!(STR_IsEmpty(inst->tmpItem.item.number.unitStr))) )
            {
                bufPos += STR_BufAppend (&(inst->tmpStr), bufPos,
                                         STR_GetASCII(" "),
                                         FGS_ITEM_NUM_BUFCHARSET);

                bufPos += STR_BufAppend (&(inst->tmpStr), bufPos,
                              inst->tmpItem.item.number.unitStr,
                                         FGS_ITEM_NUM_BUFCHARSET);
            }
            break;

        case FGS_NITEM_TYPE_TIME:
            inst->actItem.item.str.font = inst->tmpItem.item.time.font;
            inst->actItem.item.str.col  = inst->tmpItem.item.time.col;

            sprintf(tmpBuf, "%02i:%02i",
                    inst->inputValue.time.hour,
                    inst->inputValue.time.minute);

            switch ( inst->numDigits )
            {
                case 0:   tmpBuf[0] = '_'; break;
                case 1:   tmpBuf[1] = '_'; break;
                case 2:   tmpBuf[3] = '_'; break;
                case 3:   tmpBuf[4] = '_'; break;
                default:  break;
            }

            (void)STR_BufAppend (&(inst->tmpStr), 0, STR_GetASCII(tmpBuf),
                           FGS_ITEM_NUM_BUFCHARSET);
            break;

        case FGS_NITEM_TYPE_DATE:
            inst->actItem.item.str.font = inst->tmpItem.item.date.font;
            inst->actItem.item.str.col  = inst->tmpItem.item.date.col;

            switch(inst->tmpItem.item.date.format)
            {
                case FGS_FORMAT_DATE_INT_NORM:
                    sprintf(tmpBuf, "%04i-%02i-%02i",
                            inst->inputValue.date.year,
                            inst->inputValue.date.month,
                            inst->inputValue.date.day);

                    switch ( inst->numDigits )
                    {
                        case 0:   tmpBuf[0] = '_'; break;
                        case 1:   tmpBuf[1] = '_'; break;
                        case 2:   tmpBuf[2] = '_'; break;
                        case 3:   tmpBuf[3] = '_'; break;
                        case 4:   tmpBuf[5] = '_'; break;
                        case 5:   tmpBuf[6] = '_'; break;
                        case 6:   tmpBuf[8] = '_'; break;
                        case 7:   tmpBuf[9] = '_'; break;
                        default:  break;
                    }
                    break;
                case FGS_FORMAT_DATE_INT_SHORT:
                    sprintf(tmpBuf, "%02i-%02i",
                            inst->inputValue.date.month,
                            inst->inputValue.date.day);

                    switch ( inst->numDigits )
                    {
                        case 0:   tmpBuf[0] = '_'; break;
                        case 1:   tmpBuf[1] = '_'; break;
                        case 2:   tmpBuf[3] = '_'; break;
                        case 3:   tmpBuf[4] = '_'; break;
                        default:  break;
                    }
                    break;
                case FGS_FORMAT_DATE_EUROPE_NORM:
                    sprintf(tmpBuf, "%02i.%02i.%04i",
                            inst->inputValue.date.day,
                            inst->inputValue.date.month,
                            inst->inputValue.date.year);

                    switch ( inst->numDigits )
                    {
                        case 0:   tmpBuf[0] = '_'; break;
                        case 1:   tmpBuf[1] = '_'; break;
                        case 2:   tmpBuf[3] = '_'; break;
                        case 3:   tmpBuf[4] = '_'; break;
                        case 4:   tmpBuf[6] = '_'; break;
                        case 5:   tmpBuf[7] = '_'; break;
                        case 6:   tmpBuf[8] = '_'; break;
                        case 7:   tmpBuf[9] = '_'; break;
                        default:  break;
                    }
                    break;
                case FGS_FORMAT_DATE_EUROPE_SHORT:
                    sprintf(tmpBuf, "%02i.%02i",
                            inst->inputValue.date.day,
                            inst->inputValue.date.month);

                    switch ( inst->numDigits )
                    {
                        case 0:   tmpBuf[0] = '_'; break;
                        case 1:   tmpBuf[1] = '_'; break;
                        case 2:   tmpBuf[3] = '_'; break;
                        case 3:   tmpBuf[4] = '_'; break;
                        default:  break;
                    }
                    break;

                default:
                    /* do nothing */
                    break;
            }

            (void)STR_BufAppend (&(inst->tmpStr), 0, STR_GetASCII(tmpBuf),
                           FGS_ITEM_NUM_BUFCHARSET);
            break;

        case FGS_NITEM_TYPE_IP:
            inst->actItem.item.str.font = inst->tmpItem.item.ip.font;
            inst->actItem.item.str.col  = inst->tmpItem.item.ip.col;

            switch(inst->tmpItem.item.ip.format)
            {
                case FGS_FORMAT_IP_V4:
                    sprintf(tmpBuf, "%03i.%03i.%03i.%03i",
                            inst->inputValue.ip[0],
                            inst->inputValue.ip[1],
                            inst->inputValue.ip[2],
                            inst->inputValue.ip[3]);

                    switch ( inst->numDigits )
                    {
                        case  0:   tmpBuf[0] = '_'; break;
                        case  1:   tmpBuf[1] = '_'; break;
                        case  2:   tmpBuf[2] = '_'; break;

                        case  3:   tmpBuf[4] = '_'; break;
                        case  4:   tmpBuf[5] = '_'; break;
                        case  5:   tmpBuf[6] = '_'; break;

                        case  6:   tmpBuf[8]  = '_'; break;
                        case  7:   tmpBuf[9]  = '_'; break;
                        case  8:   tmpBuf[10] = '_'; break;

                        case  9:   tmpBuf[12] = '_'; break;
                        case 10:   tmpBuf[13] = '_'; break;
                        case 11:   tmpBuf[14] = '_'; break;
                        default:  break;
                    }
                    break;
                case FGS_FORMAT_IP_V6:
                default:
                    /* do nothing */
                    break;
            }
            (void)STR_BufAppend (&(inst->tmpStr), 0, STR_GetASCII(tmpBuf),
                           FGS_ITEM_NUM_BUFCHARSET);
            break;

        case FGS_NITEM_TYPE_MAC:
            inst->actItem.item.str.font = inst->tmpItem.item.mac.font;
            inst->actItem.item.str.col  = inst->tmpItem.item.mac.col;

            sprintf(tmpBuf, "%02X:%02X:%02X:%02X:%02X:%02X:",
                            inst->inputValue.mac[0],
                            inst->inputValue.mac[1],
                            inst->inputValue.mac[2],
                            inst->inputValue.mac[3],
                            inst->inputValue.mac[4],
                            inst->inputValue.mac[5]);

            switch ( inst->numDigits )
            {
                case  0:   tmpBuf[0] = '_'; break;
                case  1:   tmpBuf[1] = '_'; break;

                case  2:   tmpBuf[3] = '_'; break;
                case  3:   tmpBuf[4] = '_'; break;

                case  4:   tmpBuf[6] = '_'; break;
                case  5:   tmpBuf[7] = '_'; break;

                case  6:   tmpBuf[9]  = '_'; break;
                case  7:   tmpBuf[10] = '_'; break;

                case  8:   tmpBuf[12] = '_'; break;
                case  9:   tmpBuf[13] = '_'; break;

                case 10:   tmpBuf[15] = '_'; break;
                case 11:   tmpBuf[16] = '_'; break;
                default:  break;
            }
            (void)STR_BufAppend (&(inst->tmpStr), 0, STR_GetASCII(tmpBuf),
                           FGS_ITEM_NUM_BUFCHARSET);
            break;
        default:
            inst->actItem.type = FGS_ITEM_TYPE_NONE;
            break;
    }

    inst->actItem.item.str.chr = inst->tmpStr.string;

    return &(inst->actItem);
}

static int32_t FGS_ITEM_NUM_CheckParams (FGS_ITEM_NUM_TYPE_E type,
                                      FGS_ITEM_NUM_PARAMS_S* params)
{
    int32_t retVal = FAPI_OK;

    switch ( type )
    {
        case FGS_NITEM_TYPE_NUMBER:
            /* align min/max values to "step"-grid */
            params->minValue -= params->minValue % params->step;
            params->maxValue -= params->maxValue % params->step;

            if ( params->minValue > params->maxValue )
            {
                retVal = SMARTGO_FGS_ERR_BAD_PARAMETER;
            }
            else if ( params->maxDigits > FGS_ITEM_NUM_DIGITS_MAX )
            {
                params->maxDigits = FGS_ITEM_NUM_DIGITS_MAX;
            }
            break;

        case FGS_NITEM_TYPE_TIME:
        case FGS_NITEM_TYPE_DATE:
        case FGS_NITEM_TYPE_IP:
        case FGS_NITEM_TYPE_MAC:
            break;

        default:
            retVal = SMARTGO_FGS_ERR_BAD_PARAMETER;
            break;
    }

    return retVal;
}

static int32_t FGS_ITEM_NUM_CheckDate(SYS_DATE_S date)
{
    uint8_t daysinmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint8_t days = daysinmonth[date.month-1];

    if( ( date.month      == 2) &&
            ((date.year &  3) == 0) )
    {
        days++;
    }

    if ( ( date.day   <= days ) &&
         ( date.month <= 12   ) &&
         ( date.year  <= 2199 ) &&
         ( date.year  >= 1900 ) )
    {
        return FAPI_OK;
    }

    return SMARTGO_FGS_ERR_BAD_PARAMETER;

}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
