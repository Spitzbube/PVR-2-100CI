/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs_item_char.c
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
** - Info    713: Loss of precision (assignment) (unsigned int to short).
** - Info    732: Loss of sign (assignment) (int to unsigned short).
**
*****************************************************************************
*/
/*lint -save -e713 -e732*/

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs_item_char.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/
static int32_t  FGS_ITEM_CHAR_Close        (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_CHAR_Draw         (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_CHAR_SetFocus     (FAPI_SYS_HandleT h, fbool_t hasFocus);
static int32_t  FGS_ITEM_CHAR_GetParams    (FAPI_SYS_HandleT h, void* params);
static int32_t  FGS_ITEM_CHAR_SetParams    (FAPI_SYS_HandleT h, const void* params);
static int32_t  FGS_ITEM_CHAR_Activate     (FAPI_SYS_HandleT h);
static int32_t  FGS_ITEM_CHAR_Deactivate   (FAPI_SYS_HandleT h, fbool_t keepChanges);
static fbool_t  FGS_ITEM_CHAR_Left         (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_CHAR_Right        (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_CHAR_Up           (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_CHAR_Down         (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_CHAR_DeleteThis   (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_CHAR_DeletePrev   (FAPI_SYS_HandleT h);
static fbool_t  FGS_ITEM_CHAR_InsertBlank  (FAPI_SYS_HandleT h);
static void     FGS_ITEM_CHAR_DrawActivated(FGS_ITEM_CHAR_INST_S* inst);

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
static FGS_ITEM_CHAR_INIT_S*    fgsGlobal    = NULL;

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
int32_t FGS_ITEM_CHAR_Init (FGS_ITEM_CHAR_INIT_S* pInitParams)
{
    if ( pInitParams == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsGlobal = FGS_Malloc(sizeof(FGS_ITEM_CHAR_INIT_S));
    if ( fgsGlobal == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }

    (*fgsGlobal) = (*pInitParams);

    return FAPI_OK;
}

int32_t FGS_ITEM_CHAR_Open (FGS_ITEM_CHAR_OPEN_S* pData, int32_t id,
                            FAPI_SYS_HandleT parent, FAPI_SYS_HandleT* ph)
{
    FGS_ITEM_CHAR_INST_S* inst;
    FGS_LIST_MEMBER_S     member;
    int32_t               retVal;

    if ( (pData  == NULL) ||
         (parent == NULL) ||
         (ph     == NULL) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    inst = FGS_Malloc(sizeof(FGS_ITEM_CHAR_INST_S));
    if ( inst == NULL )
    {
        retVal = SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }
    else
    {
        inst->data        = *pData;
        inst->pMem        = NULL;
        inst->strPosCurr  = 0;
        inst->strLenCurr  = 0;

        if ( (uint16_t)(inst->data.params.charMax + 1) > FGS_ITEM_CHAR_MAX_CHARS )
        {
            inst->data.params.charMax  = FGS_ITEM_CHAR_MAX_CHARS - 1;
        }

        retVal = STR_BufOpen (&(inst->tmpStr), FGS_ITEM_CHAR_BUFSIZE,
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
            member.setFocus    = FGS_ITEM_CHAR_SetFocus;
            member.draw        = FGS_ITEM_CHAR_Draw;
            member.close       = FGS_ITEM_CHAR_Close;
            member.activate    = FGS_ITEM_CHAR_Activate;
            member.deactivate  = FGS_ITEM_CHAR_Deactivate;
            member.getParams   = FGS_ITEM_CHAR_GetParams;
            member.setParams   = FGS_ITEM_CHAR_SetParams;
            member.up          = FGS_ITEM_CHAR_Up;
            member.down        = FGS_ITEM_CHAR_Down;
            member.left        = FGS_ITEM_CHAR_Left;
            member.right       = FGS_ITEM_CHAR_Right;

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

static int32_t FGS_ITEM_CHAR_Close (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst = (FGS_ITEM_CHAR_INST_S*)h;

    if (inst == NULL)
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }

    (void)STR_BufClose(&(inst->tmpStr));

    FGS_Free(inst);

    return FAPI_OK;
}

static int32_t FGS_ITEM_CHAR_Draw (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst = (FGS_ITEM_CHAR_INST_S*)h;
    FGS_ITEM_S            item;
    FGS_ITEMSTATE_E       state;

    if ( !(inst->pMem->isVisible) )
    {
        return FAPI_OK;
    }

    memset(&item, 0, sizeof(item));
    item.type = FGS_ITEM_TYPE_NONE;

    if ( inst->pMem->isActivated )
    {
        item = inst->tmpItem;
    }
    else if ( inst->pMem->pParent->getItem != NULL ) /* get item */
    {
        if(!(inst->pMem->isEnabled))
        {
            state = FGS_DISABLED;
        }
        else if (inst->pMem->hasFocus)
        {
            state = FGS_FOCUS;
        }
        else
        {
            state = FGS_NONFOCUS;
        }

        inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                      inst->pMem->id, 0, state, &item);
    }

    /* paint background */
    if ( fgsGlobal->gfx.drawBkgr != NULL )
    {
        fgsGlobal->gfx.drawBkgr (h, inst->pMem->pPanel, &item);
    }

    FGS_LIST_DrawItemDescr(inst->pMem);

    /* draw value item */
    if ( item.type == FGS_ITEM_TYPE_STRING )
    {
        /* Use special draw routine for activated state */
        if ( inst->pMem->isActivated )
        {
            FGS_ITEM_CHAR_DrawActivated(inst);
        }
        else
        {
            /* draw value item */
            (void)FGS_DrawItem (&item,
                          inst->pMem->abspos.x + inst->pMem->valuePos.x,
                          inst->pMem->abspos.y + inst->pMem->valuePos.y,
                          inst->pMem->valuePos.width,
                          inst->pMem->valuePos.height);
        }
    }

    /* paint rest */
    if ( fgsGlobal->gfx.drawRest != NULL )
    {
        fgsGlobal->gfx.drawRest(h);
    }

    return FAPI_OK;
}

static int32_t FGS_ITEM_CHAR_SetFocus (FAPI_SYS_HandleT h, fbool_t hasFocus)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( inst->pMem->hasFocus == hasFocus )
    {
        return FAPI_OK;
    }

    inst->pMem->hasFocus = hasFocus;

    /* assign/release key handlers for additional function keys */
    if ( hasFocus )
    {
        if ( inst->data.keyDeleteThis != FGS_KEY_NONE )
        {
            FGS_SetKeyHandler (inst->data.keyDeleteThis,
                               FGS_ITEM_CHAR_DeleteThis, h, FTRUE);
        }

        if ( inst->data.keyDeletePrev != FGS_KEY_NONE )
        {
            FGS_SetKeyHandler (inst->data.keyDeletePrev,
                               FGS_ITEM_CHAR_DeletePrev, h, FTRUE);
        }

        if ( inst->data.keyInsertBlank != FGS_KEY_NONE )
        {
            FGS_SetKeyHandler (inst->data.keyInsertBlank,
                               FGS_ITEM_CHAR_InsertBlank, h, FTRUE);
        }
    }
    else
    {
        if ( inst->data.keyDeleteThis != FGS_KEY_NONE )
        {
            FGS_ClearKeyHandler(inst->data.keyDeleteThis);
        }

        if ( inst->data.keyDeletePrev != FGS_KEY_NONE )
        {
            FGS_ClearKeyHandler(inst->data.keyDeletePrev);
        }

        if ( inst->data.keyInsertBlank != FGS_KEY_NONE )
        {
            FGS_ClearKeyHandler(inst->data.keyInsertBlank);
        }
    }

    /* redraw item if currently visible */
    if ( inst->pMem->isVisible )
    {
        (void)FGS_ITEM_CHAR_Draw(h);
    }

    return FAPI_OK;
}

int32_t FGS_ITEM_CHAR_GetParams (FAPI_SYS_HandleT h, void* params)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( inst   == NULL )
    {
        return SMARTGO_FGS_ERR_INVALID_HANDLE;
    }
    if ( params == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    *((FGS_ITEM_CHAR_PARAMS_S*)params) = inst->data.params;
    return FAPI_OK;
}

int32_t FGS_ITEM_CHAR_SetParams (FAPI_SYS_HandleT h, const void* params)
{
    FGS_ITEM_CHAR_INST_S*           inst = (FGS_ITEM_CHAR_INST_S*)h;
    const FGS_ITEM_CHAR_PARAMS_S*   pPar = params;

    if ( inst->pMem->isActivated )
    {
        return SMARTGO_FGS_ERR_DEVICE_BUSY;
    }

    /* check parameters */
    if ( (uint16_t)(pPar->charMax + 1) > FGS_ITEM_CHAR_MAX_CHARS )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    inst->data.params = *pPar;

    return FAPI_OK;
}

/* ------------------------------------------------------------------------- */

static int32_t FGS_ITEM_CHAR_Activate (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;
    FGS_ITEMSTATE_E       state;

    if ( inst->pMem->isActivated )
    {
        return FAPI_OK;
    }

    if ( inst->pMem->pParent->getItem == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    if (!(inst->pMem->isEnabled))
    {
        state = FGS_DISABLED;
    }
    else if (inst->pMem->hasFocus)
    {
        state = FGS_FOCUS;
    }
    else
    {
        state = FGS_NONFOCUS;
    }
    memset(&(inst->tmpItem), 0, sizeof(inst->tmpItem));

    /* get current value for temporal storage */
    inst->pMem->pParent->getItem (inst->pMem->pParent->getItemArg,
                                  inst->pMem->id, 0, state, &inst->tmpItem);

    if ( inst->tmpItem.type == FGS_ITEM_TYPE_STRING )
    {
        inst->strLenCurr = STR_BufAppend (&(inst->tmpStr), 0,
                                          inst->tmpItem.item.str.chr,
                                          FGS_ITEM_CHAR_BUFCHARSET);

        inst->strPosCurr = 0;

        inst->pMem->isActivated = FTRUE;

        (void)FGS_ITEM_CHAR_Draw(h);
    }

    return FAPI_OK;
}

static int32_t FGS_ITEM_CHAR_Deactivate (FAPI_SYS_HandleT h, fbool_t keepChanges)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;
    FGS_VAL_S             value;

    if ( inst->pMem->isActivated )
    {
        if ( keepChanges )
        {
            (void)STR_Trim (inst->tmpStr.string, inst->strLenCurr);

            if ( inst->pMem->pParent->onValChg != NULL )
            {
                value.string = inst->tmpStr.string;

                inst->pMem->pParent->onValChg(inst->pMem->pParent->onValChgArg,
                                          inst->pMem->id,
                                          value);
            }
        }

        inst->pMem->isActivated = FFALSE;

        (void)FGS_ITEM_CHAR_Draw(h);
    }

    return FAPI_OK;
}

static fbool_t FGS_ITEM_CHAR_Left (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    if ( inst->strPosCurr >= FGS_ITEM_CHAR_BYTESPERCHAR )
    {
        inst->strPosCurr -= FGS_ITEM_CHAR_BYTESPERCHAR;

        (void)FGS_ITEM_CHAR_Draw(h);
    }

    return FTRUE;
}

static fbool_t FGS_ITEM_CHAR_Right (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    if ( (uint16_t)((uint16_t)(inst->strPosCurr + FGS_ITEM_CHAR_BYTESPERCHAR) /
          FGS_ITEM_CHAR_BYTESPERCHAR) >= inst->data.params.charMax )
    {
        return FTRUE;
    }

    inst->strPosCurr += FGS_ITEM_CHAR_BYTESPERCHAR;

    /* test if string has to be extended */
    if ( inst->strPosCurr >= inst->strLenCurr )
    {
        (void)STR_BufAppend (&(inst->tmpStr), inst->strPosCurr, STR_GetASCII(" "),
                       FGS_ITEM_CHAR_BUFCHARSET);

        inst->strLenCurr += FGS_ITEM_CHAR_BYTESPERCHAR;
    }

    (void)FGS_ITEM_CHAR_Draw(h);
    return FTRUE;
}

static fbool_t FGS_ITEM_CHAR_Up (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;
    SYS_CHAR              chr;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    if ( STR_CharGet (inst->tmpStr.string, inst->strPosCurr, &chr) > 0 )
    {
        /* move character */
        if ( chr == ' ' )
        {
            chr = 'a';
        }
        else if ( chr == 'z' )
        {
            chr = 'A';
        }
        else if ( chr == 'Z' )
        {
            chr = '0';
        }
        else if ( chr == '9' )
        {
            chr = ' ';
        }
        else
        {
            chr++;
        }

        (void) STR_CharSet (inst->tmpStr.string, inst->strPosCurr, chr);
    }

    /* NOTE: the above algorithm does not handle any special characters! */

    (void)FGS_ITEM_CHAR_Draw(h);
    return FTRUE;
}

static fbool_t FGS_ITEM_CHAR_Down (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;
    SYS_CHAR              chr;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    if ( STR_CharGet (inst->tmpStr.string, inst->strPosCurr, &chr) > 0 )
    {
        /* move character */
        if ( chr == ' ' )
        {
            chr = '9';
        }
        else if ( chr == '0' )
        {
            chr = 'Z';
        }
        else if ( chr == 'A' )
        {
            chr = 'z';
        }
        else if ( chr == 'a' )
        {
            chr = ' ';
        }
        else
        {
            chr--;
        }

        (void)STR_CharSet (inst->tmpStr.string, inst->strPosCurr, chr);
    }

    /* NOTE: the above algorithm does not handle any special characters! */

    (void)FGS_ITEM_CHAR_Draw(h);
    return FTRUE;
}

static fbool_t FGS_ITEM_CHAR_DeleteThis (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    if ( (inst->strLenCurr < FGS_ITEM_CHAR_BYTESPERCHAR) ||
         (inst->strPosCurr >= inst->strLenCurr ) )
    {
        return FTRUE;
    }

    (void)STR_CharRemove (inst->tmpStr.string, inst->strPosCurr);

    inst->strLenCurr -= FGS_ITEM_CHAR_BYTESPERCHAR;

    if ( (inst->strLenCurr >= FGS_ITEM_CHAR_BYTESPERCHAR) &&
         (inst->strPosCurr >= inst->strLenCurr) )
    {
        inst->strPosCurr = inst->strLenCurr - FGS_ITEM_CHAR_BYTESPERCHAR;
    }
    else if ( inst->strLenCurr == 0 )
    {
        inst->strPosCurr = 0;

        /* expand emtpy string with blank */
        (void)STR_BufAppend (&(inst->tmpStr), inst->strPosCurr, STR_GetASCII(" "),
                       FGS_ITEM_CHAR_BUFCHARSET);

        inst->strLenCurr += FGS_ITEM_CHAR_BYTESPERCHAR;
    }

    (void)FGS_ITEM_CHAR_Draw(h);
    return FTRUE;
}

static fbool_t FGS_ITEM_CHAR_DeletePrev (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    if ( (inst->strLenCurr < (2 * FGS_ITEM_CHAR_BYTESPERCHAR)) ||
         (inst->strPosCurr < FGS_ITEM_CHAR_BYTESPERCHAR)       ||
         (inst->strPosCurr >= inst->strLenCurr ) )
    {
        return FTRUE;
    }

    (void)STR_CharRemove (inst->tmpStr.string,
                    inst->strPosCurr - FGS_ITEM_CHAR_BYTESPERCHAR);

    inst->strLenCurr -= FGS_ITEM_CHAR_BYTESPERCHAR;
    inst->strPosCurr -= FGS_ITEM_CHAR_BYTESPERCHAR;

    (void)FGS_ITEM_CHAR_Draw(h);
    return FTRUE;
}

static fbool_t FGS_ITEM_CHAR_InsertBlank (FAPI_SYS_HandleT h)
{
    FGS_ITEM_CHAR_INST_S* inst   = (FGS_ITEM_CHAR_INST_S*)h;

    if ( !(inst->pMem->isActivated) )
    {
        return FFALSE;
    }

    /* maximum string size reached? */
    if ( (uint16_t)((uint16_t)(inst->strLenCurr + FGS_ITEM_CHAR_BYTESPERCHAR) /
          FGS_ITEM_CHAR_BYTESPERCHAR) > inst->data.params.charMax )
    {
        return FTRUE;
    }

    /* insert blank character */
    inst->strLenCurr += STR_BufInsertChar (&(inst->tmpStr), inst->strPosCurr,
                                           ' ', FGS_ITEM_CHAR_BUFCHARSET);

    (void)FGS_ITEM_CHAR_Draw(h);
    return FTRUE;
}

static void FGS_ITEM_CHAR_DrawActivated (FGS_ITEM_CHAR_INST_S* inst)
{
    uint16_t        actPos = 0;
    uint16_t        actLen = 0;
    uint16_t        strX, strY, strWidth, strHeight;
    SYS_STRING_S    string;

    /* get absolute position according to alignment */
    FGS_GetPosString (inst->tmpStr.string,
                      -1,
                      inst->tmpItem.item.str.font,
                      inst->tmpItem.align,
                      inst->pMem->abspos.x + inst->pMem->valuePos.x,
                      inst->pMem->abspos.y + inst->pMem->valuePos.y,
                      inst->pMem->valuePos.width,
                      inst->pMem->valuePos.height, - 1,
                      &strX, &strY, &strWidth, &strHeight);

    if ( inst->strPosCurr > 0 )
    {
        actPos = fgsDraw->getStrWidth(inst->tmpStr.string, inst->strPosCurr,
                                      inst->tmpItem.item.str.font);
    }

    string = inst->tmpStr.string;
    string.chr += inst->strPosCurr;

    actLen = fgsDraw->getStrWidth (string, FGS_ITEM_CHAR_BYTESPERCHAR,
                                  inst->tmpItem.item.str.font);

    /* highlight activated pixel */
    if ( fgsGlobal->drawBkgrSelChar != NULL )
    {
        fgsGlobal->drawBkgrSelChar((FAPI_SYS_HandleT)inst,
                                   strX + actPos,
                                   inst->pMem->abspos.y + inst->pMem->valuePos.y,
                                   actLen,
                                   inst->pMem->valuePos.height);
    }

    (void)fgsDraw->printStr (strX, strY,
                       inst->tmpItem.item.str.col,
                       inst->tmpItem.item.str.font,
                       -1, strWidth, -1, inst->tmpStr.string, FTRUE);
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
