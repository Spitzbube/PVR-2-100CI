/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/src/fgs.c
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
** - Warning 641: Converting enum 'anyEnum' to int
** - Info    713: Loss of precision (assignment) (unsigned int to short).
** - Info    732: Loss of sign (assignment) (int to unsigned short).
** - Info    737: Loss of sign in promotion from int to unsigned int.
** - Note    961: Violates MISRA 2004 Advisory Rule 12.1, dependence placed on
**                C's operator precedence.
**
*****************************************************************************
*/
/*lint -save -e641 -e713 -e732 -e737 -e961 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "fgs.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

#define FGS_STRBUFCHARS      128
#define FGS_STRBUFCHARSET    SYS_CHARSET_ISO_10646   //!< Character set used.

#define FGS_HIDE_AREA_MAX   32

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

typedef struct
{
    /* handler installed by GUI */
    FGS_KEY_CB_S        cb;
    FAPI_SYS_HandleT    data;
    fbool_t             blockRep;

    /* handler installed by application */
    FGS_APPKEY_HDL_S    appHdl;

} FGS_KEY_HANDLER_S;

typedef struct
{
    FGS_MEMBER_S* pMember;

} FGS_ORDER_S;

typedef struct
{
    FGS_INIT_S        data;
    uint8_t           numMembers; //40
    FGS_MEMBER_S      member[FGS_MEMBERS_MAX];
    int32_t           focusIdx; //812
    FGS_ORDER_S       order[FGS_MEMBERS_MAX];   //!< Display order (0: top)

    SYS_STRBUF_S      strBuf; //880
    char_t            asciiBuf[FGS_STRBUFCHARS]; //900
    SYS_STRING_S      asciiStr; //1028

    /* key handling data */
    FGS_KEY_HANDLER_S keyHdl[/*FGS_KEY_NUMS*/67];
    FGS_KEY_E         currKey; //2912
    FGS_KEYTYPE_E     currType; //2916
    int8_t            currValue; //2920

    FGS_AREA_S        hideArea[FGS_HIDE_AREA_MAX];
    uint16_t          numAreas;
    //3184
} FGS_INST_S;

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*static*/ FGS_INST_S*   fgsInst = NULL;
        FGS_DRAWIF_S* fgsDraw = NULL; // external access to draw interface

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

static void    FGS_DrawString          (SYS_STRING_S  itemStr,
                                        uint8_t       itemFont,
                                        uint8_t       itemAlign,
                                        uint32_t      itemCol,
                                        uint16_t      x,
                                        uint16_t      y,
                                        uint16_t      width,
                                        uint16_t      height,
                                        int32_t       strWidth,
                                        int32_t       numBytes);

static void    FGS_DrawMultiLineString (SYS_STRING_S  itemStr,
                                        uint8_t       itemFont,
                                        uint8_t       itemAlign,
                                        uint32_t      itemCol,
                                        uint8_t       lineHeight,
                                        uint16_t      x,
                                        uint16_t      y,
                                        uint16_t      width,
                                        uint16_t      height);

/*static*/ int32_t FGS_SearchMember        ( int32_t      id);
/*static*/ fbool_t FGS_AreaCheck           ( uint16_t*     areaIdx,
                                         FGS_MEMBER_S* pMem);

/* 21ba8d28 - nearly complete */
int32_t FGS_Init(FGS_INIT_S* pInitParams)
{
    int32_t retVal;

    if ( ( pInitParams == NULL ) /*||
         ( pInitParams->mem.get == NULL ) ||
         ( pInitParams->mem.release == NULL )*/ )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    fgsInst = SYS_MemoryAllocate/*pInitParams->mem.get*/(sizeof(FGS_INST_S));
    if ( fgsInst == NULL )
    {
        return SMARTGO_FGS_ERR_OUT_OF_MEMORY;
    }
    memset(fgsInst, 0, sizeof(FGS_INST_S));

    fgsInst->data       = *pInitParams;
    fgsInst->numMembers = 0;
    fgsInst->focusIdx   = -1;

    fgsInst->currKey    = FGS_KEY_NONE;
    fgsInst->currType   = FGS_KEYTYPE_PRESSED;
    fgsInst->currValue  = -1;

    fgsDraw = &(fgsInst->data.draw);

    /* ensure that grid setting is not zero */
    if ( fgsInst->data.gridX == 0 )
    {
        fgsInst->data.gridX = 1;
    }
    if ( fgsInst->data.gridY == 0 )
    {
        fgsInst->data.gridY = 1;
    }

    retVal = STR_BufOpen (&(fgsInst->strBuf), FGS_STRBUFCHARS, NULL);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    fgsInst->asciiStr.cs  = SYS_CHARSET_ASCII;
    fgsInst->asciiStr.chr = fgsInst->asciiBuf;

    return FAPI_OK;
}

#if 0

int32_t FGS_Exit (void)
{
    uint8_t       cnt = 0;
    FGS_MEMBER_S* pMem;

    if ( fgsInst == NULL )
    {
        return FAPI_OK;
    }

    /* close all members */
    pMem = &(fgsInst->member[0]);

    /* search used entry */
    while ( cnt++ < FGS_MEMBERS_MAX )
    {
        if ( pMem->pos == NULL )
        {
            continue;
        }

        if ( pMem->close != NULL )
        {
            (void)pMem->close(pMem->h);
        }

        pMem++;
    }

    /* free all resources */
    (void)STR_BufClose (&(fgsInst->strBuf));

    FGS_Free(fgsInst);

    fgsInst = NULL;
    fgsDraw = NULL;

    return FAPI_OK;
}

#endif

/* 21ba5e50 - complete */
int32_t FGS_AddMember (FGS_MEMBER_S* pMember, FGS_MEMBER_S** pId)
{
    int16_t         cnt;
    int16_t         orderPos;
    FGS_MEMBER_S*   pMem;
    FGS_ORDER_S     orderPars;

    if ( fgsInst->numMembers >= FGS_MEMBERS_MAX )
    {
        return SMARTGO_FGS_ERR_RESOURCES;
    }

    pMem = &(fgsInst->member[0]);

    /* search for free entry */
    for ( cnt = 0; cnt < FGS_MEMBERS_MAX; cnt++ )
    {
        if ( pMem->pos == NULL )
        {
            break;
        }
        pMem++;
    }

    if ( cnt >= FGS_MEMBERS_MAX )
    {
        return SMARTGO_FGS_ERR_RESOURCES;
    }

    *pMem = *pMember;
    *pId  = pMem;

    /* calculate member's absolute position */
    FGS_CalculateAbsPos (pMem, fgsInst->data.pos, &(fgsInst->data.pos),
                         fgsInst->data.gridX, fgsInst->data.gridY);
    pMem->posChg   = FFALSE;

    /* ----- enqueue in display order -------------------------------------- */

    orderPars.pMember = pMem;

    if ( pMem->inFront )
    {
        orderPos = 0; /* insert on top */
    }
    else
    {
        /* insert behind last "top" member */
        for ( orderPos = 0; orderPos < (int16_t)fgsInst->numMembers; orderPos++ )
        {
            if ( !(fgsInst->order[orderPos].pMember->inFront) )
            {
                break;
            }
        }
    }

    for ( cnt = (int16_t)fgsInst->numMembers - 1; cnt >= orderPos; cnt-- )
    {
        fgsInst->order[cnt + 1] = fgsInst->order[cnt];
    }

    fgsInst->order[orderPos] = orderPars;

    /* --------------------------------------------------------------------- */

    fgsInst->numMembers++;

    return FAPI_OK;
}


/* 21ba8574 - complete */
int32_t FGS_RemoveMember (FGS_MEMBER_S* id)
{
    FGS_MEMBER_S*   pMember;
    int16_t         cnt;

    if ( (id == NULL) ||
         (fgsInst->numMembers < 1) )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    /* test if member to be removed is currently focussed */
    if ( (fgsInst->focusIdx >= 0) &&
         (&(fgsInst->member[fgsInst->focusIdx]) == id) )
    {
        pMember = &(fgsInst->member[fgsInst->focusIdx]);

        (void)pMember->setFocus(pMember->h, FFALSE);

        fgsInst->focusIdx = -1;
    }

    /* remove entry */
    memset(id, 0, sizeof(FGS_MEMBER_S));

    /* ----- remove from display queue ------------------------------------- */

    for ( cnt = 0; cnt < (int16_t)fgsInst->numMembers; cnt++ )
    {
        if ( fgsInst->order[cnt].pMember == id )
        {
            break;
        }
    }

    for ( ; cnt < (int16_t)fgsInst->numMembers - 1; cnt++ )
    {
        fgsInst->order[cnt] = fgsInst->order[cnt + 1];
    }

    /* --------------------------------------------------------------------- */

    fgsInst->numMembers--;

    return FAPI_OK;
}


/* Redraws all members in front of given member if necessary */
/* 21ba8308 - complete */
int32_t FGS_HandleMemberShow (FGS_MEMBER_S* pMember)
{
    int16_t         cnt;
    int16_t         drawCnt;
    fbool_t         toDraw[FGS_MEMBERS_MAX]; // = {FFALSE};
    int16_t         newPos = -1;
    FGS_MEMBER_S*   pMemCurr;
    FGS_MEMBER_S*   pMemComp;
    FGS_AREA_S      overlap;

    /* ----- search member in display order list --------------------------- */

    for ( cnt = 0; cnt < (int16_t)fgsInst->numMembers; cnt++ )
    {
        if ( fgsInst->order[cnt].pMember == pMember )
        {
            newPos      = cnt;
            toDraw[cnt] = FTRUE;
        }
        else
        {
            toDraw[cnt] = FFALSE;
        }
    }

    if ( newPos < 0 )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    /* ----- test which members situated above new member have to be redrawn */

    for ( cnt = newPos - 1; cnt >= 0; cnt-- )
    {
        pMemCurr = fgsInst->order[cnt].pMember;

        if ( !(pMemCurr->isVisible) )
        {
            continue;
        }
        /* test for overlap condition in already-drawn members lying under
           currently tested member */
        for ( drawCnt = cnt + 1; drawCnt <= newPos; drawCnt++ )
        {
            if ( !(toDraw[drawCnt]) )
            {
                continue;
            }
            if ( !(fgsInst->order[drawCnt].pMember->isVisible) )
            {
                continue;
            }
            pMemComp = fgsInst->order[drawCnt].pMember;

            overlap = FGS_GetOverlapArea (&(pMemCurr->abspos),
                                          pMemCurr->pos->width,
                                          pMemCurr->pos->height,
                                          &(pMemComp->abspos),
                                          pMemComp->pos->width,
                                          pMemComp->pos->height);

            if ( (overlap.width  > 0) &&
                 (overlap.height > 0) )
            {
                toDraw[cnt] = FTRUE;
                break;
            }
        }
    }

    /* ----- redraw necessary members -------------------------------------- */

    for ( cnt = newPos - 1; cnt >= 0; cnt-- )
    {
        if ( toDraw[cnt] )
        {
            pMemCurr = fgsInst->order[cnt].pMember;

            (void)pMemCurr->show(pMemCurr->h, FTRUE);
        }
    }

    return FAPI_OK;
}


/* to do:
- refresh only partial areas of member objects (also for FGS_HandleMemberShow)
*/
/* 21ba7f14 - complete */
int32_t FGS_HandleMemberHide (FGS_MEMBER_S* hiddenMember)
{
    int16_t         cnt;
    int16_t         drawCnt;
    uint16_t        areaCnt;
    fbool_t         toDraw[FGS_MEMBERS_MAX];
    FGS_MEMBER_S*   pMemCurr;
    FGS_MEMBER_S*   pMemComp;
    FGS_AREA_S      overlap;
    FGS_AREA_S      hideArea;
    fbool_t         calcStatus;

    for ( cnt = 0; cnt < FGS_MEMBERS_MAX; cnt++ )
    {
        toDraw[cnt] = FFALSE;
    }

    /* ----- test which members have to be redrawn ------------------------- */

    for ( cnt = (int16_t)fgsInst->numMembers - 1; cnt >= 0; cnt-- )
    {
        pMemCurr = fgsInst->order[cnt].pMember;

        if ( !(pMemCurr->isVisible) )
        {
            continue;
        }
        /* test if member overlaps with hidden member */
        overlap = FGS_GetOverlapArea (&(pMemCurr->abspos),
                                     pMemCurr->pos->width,
                                     pMemCurr->pos->height,
                                     &(hiddenMember->abspos),
                                     hiddenMember->pos->width,
                                     hiddenMember->pos->height);

        if ( (overlap.width  > 0) &&
             (overlap.height > 0) )
        {
            toDraw[cnt] = FTRUE;
        }
        else
        {
            /* test for overlap condition in already-drawn members lying under
               currently tested member */
            for ( drawCnt = cnt + 1;
                  drawCnt < (int16_t)fgsInst->numMembers;
                  drawCnt++ )
            {
                if ( !(toDraw[drawCnt]) )
                {
                    continue;
                }
                if ( !(fgsInst->order[drawCnt].pMember->isVisible) )
                {
                    continue;
                }
                pMemComp = fgsInst->order[drawCnt].pMember;

                overlap = FGS_GetOverlapArea (&(pMemCurr->abspos),
                                              pMemCurr->pos->width,
                                              pMemCurr->pos->height,
                                              &(pMemComp->abspos),
                                              pMemComp->pos->width,
                                              pMemComp->pos->height);

                if ( (overlap.width  > 0) &&
                     (overlap.height > 0) )
                {
                    toDraw[cnt] = FTRUE;
                    break;
                }
            }
        }
    }

    /* ----- clear member requested for hide ------------------------------- */

    hideArea.x      = hiddenMember->abspos.x;
    hideArea.y      = hiddenMember->abspos.y;
    hideArea.width  = hiddenMember->pos->width;
    hideArea.height = hiddenMember->pos->height;

    if ( fgsInst->data.optimizedHide )
    {
        fgsInst->hideArea[0] = hideArea;

        fgsInst->numAreas = 1;

        calcStatus = FTRUE;

        /* test each member for overlapping */
        for ( cnt = 0; cnt < (int16_t)fgsInst->numMembers; cnt++ )
        {
            pMemCurr = fgsInst->order[cnt].pMember;

            /* do not compare hidden member with itself! */
            if ( pMemCurr == hiddenMember )
            {
                continue;
            }
            if ( !(pMemCurr->isVisible) )
            {
                continue;
            }
            areaCnt = 0;

            /* test each area with current member for overlapping */
            while ( areaCnt < fgsInst->numAreas )
            {
                calcStatus = FGS_AreaCheck(&areaCnt, pMemCurr);
                if ( !calcStatus )
                {
                    break;
                }
            }
            if ( !calcStatus )
            {
                break;
            }
        }
    }
    else
    {
        calcStatus = FFALSE;
    }

    if ( calcStatus ) /* successful area calculation */
    {
        for ( cnt = 0; cnt < (int16_t)fgsInst->numAreas; cnt++ )
        {
            fgsDraw->clearArea (fgsInst->hideArea + cnt);
        }
    }
    else /* clear whole member area as a fallback operation */
    {
        fgsDraw->clearArea (&hideArea);
    }

    /* ----- redraw necessary members -------------------------------------- */

    for ( cnt = (int16_t)fgsInst->numMembers - 1; cnt >= 0; cnt-- )
    {
        if ( toDraw[cnt] )
        {
            pMemCurr = fgsInst->order[cnt].pMember;

            (void)pMemCurr->show(pMemCurr->h, FTRUE);
        }
    }

    return FAPI_OK;
}

#if 0

int32_t FGS_SetMemberPosition (int32_t id, const FGS_POS_S* pos)
{
    int32_t         idx;
    fbool_t         redraw;
    FGS_MEMBER_S*   pMember;

    idx = FGS_SearchMember(id);
    if ( idx < 0 )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }
    pMember = fgsInst->member + idx;

    redraw = pMember->isVisible; /* store visibility status */

    if ( redraw )
    {
        (void)pMember->hide(pMember->h);
    }
    /* store new position information */
    *(pMember->pos) = *pos;

    /* re-calculate member's absolute position */
    FGS_CalculateAbsPos (pMember, fgsInst->data.pos, &(fgsInst->data.pos),
                         fgsInst->data.gridX, fgsInst->data.gridY);
    pMember->posChg   = FTRUE;

    /* redraw if panel has been visible before */
    if ( redraw )
    {
        (void)pMember->show(pMember->h, FTRUE);
    }
    return FAPI_OK;
}

void FGS_GetFrameDimensions (FGS_POS_S* pos)
{
    *pos = fgsInst->data.pos;
}

int32_t FGS_SetFrameDimensions (FGS_POS_S* newPos)
{
    uint8_t         cnt = 0;
    FGS_MEMBER_S*   pMem;
    fbool_t         repaint;

    if ( newPos == NULL )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }
    /* store new dimensions */
    fgsInst->data.pos = *newPos;

    /* redraw all members */
    pMem = &(fgsInst->member[0]);

    while ( cnt++ < FGS_MEMBERS_MAX )
    {
        if ( pMem->pos == NULL )
        {
            continue;
        }
        repaint = pMem->isVisible;

        if ( repaint == FTRUE )
        {
            (void)pMem->hide(pMem->h);
        }

        /* re-calculate member's absolute position */
        FGS_CalculateAbsPos (pMem, fgsInst->data.pos, &(fgsInst->data.pos),
                             fgsInst->data.gridX, fgsInst->data.gridY);
        pMem->posChg   = FTRUE;

        /* redraw if panel has been visible before */
        if ( repaint == FTRUE )
        {
            (void)pMem->show(pMem->h, FTRUE);
        }

        /* TODO: draw members in reverse display order in order to avoid
                 overlapping problems */

        pMem++;
    }

    return FAPI_OK;
}

#endif

/* 21ba62ec - complete */
int32_t FGS_SetMemberFocus (int32_t id)
{
    FGS_MEMBER_S*   pMember;
    int32_t         retVal;
    int32_t         newFocus;

    /* search for designated focus member */
    newFocus = FGS_SearchMember(id);
    if ( newFocus < 0 )
    {
        return SMARTGO_FGS_ERR_BAD_PARAMETER;
    }

    /* remove old focus */
    if ( fgsInst->focusIdx >= 0 )
    {
        pMember = &(fgsInst->member[fgsInst->focusIdx]);

        retVal = pMember->setFocus(pMember->h, FFALSE);

        if ( retVal != FAPI_OK )
        {
            return retVal;
        }
        else
        {
            fgsInst->focusIdx = -1;
        }
    }

    /* set new focus */
    pMember = &(fgsInst->member[newFocus]);

    retVal = pMember->setFocus(pMember->h, FTRUE);
    if ( retVal == FAPI_OK )
    {
        fgsInst->focusIdx = newFocus;
    }

    return retVal;
}

#if 0

int32_t FGS_GetMemberFocusID (void)
{
    if ( fgsInst->focusIdx < 0 )
    {
        return -1;
    }
    else
    {
        return fgsInst->member[fgsInst->focusIdx].id;
    }
}

#endif

/* 21ba62a8 - complete */
/*static*/ int32_t FGS_SearchMember (int32_t id)
{
    int32_t cnt = 0;

    /* search member */
    while ( cnt < FGS_MEMBERS_MAX )
    {
        if ( (fgsInst->member[cnt].pos != NULL) &&
             (fgsInst->member[cnt].id   == id) )
        {
            /* requested id has been found*/
            return cnt;
        }

        cnt++;
    }

    return -1;
}

#if 0

/* ------------------------------------------------------------------------- */

fbool_t FGS_DispatchKey (FGS_KEY_E key, FGS_KEYTYPE_E type, int8_t numVal)
{
    FGS_KEY_HANDLER_S*  pHdl     = NULL;
    fbool_t             retVal   = FFALSE;

    if ( (key >= FGS_KEY_NUMS) ||
         (key == FGS_KEY_NONE) ||
         (numVal > 9) )
    {
        return FFALSE;
    }

    /* store key info to be queried by handlers */
    fgsInst->currKey    = key;
    fgsInst->currType   = type;
    fgsInst->currValue  = numVal;

    pHdl = fgsInst->keyHdl + key;

    /* ----- call GUI handler first, if not suppressed by application -- */

    if ( (pHdl->appHdl.suppressGui == FFALSE) &&
         (pHdl->cb.all             != NULL) )
    {
        if ( ((pHdl->blockRep == FTRUE) &&
              (type           != FGS_KEYTYPE_REPEATED)) ||
              (pHdl->blockRep == FFALSE) )
        {
            if ( numVal < 0 ) retVal = pHdl->cb.btn(pHdl->data);
            else              retVal = pHdl->cb.num(pHdl->data, numVal);
        }
        else
        {
            retVal = FTRUE;
        }
    }

    /* ----- if GUI did not use key, call aplication handler ----------- */

    if ( retVal == FFALSE )
    {
        if ( pHdl->appHdl.cb.all != NULL )
        {
            if ( ((pHdl->appHdl.blockRep == FTRUE) &&
                  (type                  != FGS_KEYTYPE_REPEATED)) ||
                  (pHdl->appHdl.blockRep == FFALSE) )
            {
                if ( numVal < 0 ) retVal = pHdl->appHdl.cb.btn(pHdl->appHdl.data);
                else              retVal = pHdl->appHdl.cb.num(pHdl->appHdl.data,
                                                               numVal);
            }
            else
            {
                retVal = FTRUE;
            }
        }
    }

    /* Reset "current key" parameters */
    fgsInst->currKey   = FGS_KEY_NONE;
    fgsInst->currType  = FGS_KEYTYPE_PRESSED;
    fgsInst->currValue = -1;

    return retVal;
}

void FGS_SetKeyHandler (FGS_KEY_E key,
                        FGS_KEY_CB callback,
                        FAPI_SYS_HandleT data,
                        fbool_t blockRepeated)
{
    fgsInst->keyHdl[key].cb.btn   = callback;
    fgsInst->keyHdl[key].data     = data;
    fgsInst->keyHdl[key].blockRep = blockRepeated;
}

void FGS_SetNumKeyHandler (FGS_KEY_E key, FGS_KEYNUM_CB callback,
                           FAPI_SYS_HandleT data, fbool_t blockRepeated)
{
    fgsInst->keyHdl[key].cb.num   = callback;
    fgsInst->keyHdl[key].data     = data;
    fgsInst->keyHdl[key].blockRep = blockRepeated;
}

void  FGS_ClearKeyHandler (FGS_KEY_E key)
{
    fgsInst->keyHdl[key].cb.all = NULL;
}

/* clears all GUI handlers */
void FGS_ClearAllHandlers (void)
{
    uint32_t cnt;

    for ( cnt = 0; cnt < FGS_KEY_NUMS; cnt++ )
    {
        fgsInst->keyHdl[cnt].cb.all = NULL;
    }
}

void FGS_SetAppKeyHandler (FGS_KEY_E key, FGS_KEY_CB callback,
                           FAPI_SYS_HandleT data, fbool_t blockRepeated,
                           fbool_t suppressGui)
{
    fgsInst->keyHdl[key].appHdl.cb.btn      = callback;
    fgsInst->keyHdl[key].appHdl.data        = data;
    fgsInst->keyHdl[key].appHdl.blockRep    = blockRepeated;
    fgsInst->keyHdl[key].appHdl.suppressGui = suppressGui;
}

void FGS_SetAppNumKeyHandler (FGS_KEY_E key, FGS_KEYNUM_CB callback,
                              FAPI_SYS_HandleT data, fbool_t blockRepeated,
                              fbool_t suppressGui)
{
    fgsInst->keyHdl[key].appHdl.cb.num      = callback;
    fgsInst->keyHdl[key].appHdl.data        = data;
    fgsInst->keyHdl[key].appHdl.blockRep    = blockRepeated;
    fgsInst->keyHdl[key].appHdl.suppressGui = suppressGui;
}

FGS_APPKEY_HDL_S FGS_GetAppKeyHandler (FGS_KEY_E key)
{
    return fgsInst->keyHdl[key].appHdl;
}

void FGS_WriteAppKeyHandler (FGS_KEY_E key, FGS_APPKEY_HDL_S* hdl)
{
    fgsInst->keyHdl[key].appHdl = *hdl;
}

void FGS_ClearAppKeyHandler (FGS_KEY_E key)
{
    fgsInst->keyHdl[key].appHdl.cb.all      = NULL;
    fgsInst->keyHdl[key].appHdl.suppressGui = FFALSE;
}

void FGS_ClearAllAppKeyHandlers (void)
{
    uint32_t cnt;

    for ( cnt = 0; cnt < FGS_KEY_NUMS; cnt++ )
    {
        fgsInst->keyHdl[cnt].appHdl.cb.all      = NULL;
        fgsInst->keyHdl[cnt].appHdl.suppressGui = FFALSE;
    }
}

void FGS_GetAllAppKeyHandlers (FGS_APPKEY_HDL_S* pHdl)
{
    uint32_t cnt;

    for ( cnt = 0; cnt < FGS_KEY_NUMS; cnt++ )
    {
        pHdl[cnt] = fgsInst->keyHdl[cnt].appHdl;
    }
}

void FGS_WriteAllAppKeyHandlers (FGS_APPKEY_HDL_S* pHdl)
{
    uint32_t cnt;

    for ( cnt = 0; cnt < FGS_KEY_NUMS; cnt++ )
    {
        fgsInst->keyHdl[cnt].appHdl = pHdl[cnt];
    }
}

FGS_KEY_E FGS_GetCurrentKeyCode (void)
{
    return fgsInst->currKey;
}

int8_t FGS_GetCurrentKeyVal (void)
{
    return fgsInst->currValue;
}

#endif

/*
Returns coordinates of overlapping area between abspos1 and abspos2, relative
to abspos2.

If no overlapping area exists, all members of returned structure are set to 0.
*/
/* 21ba7de8 - complete */
FGS_AREA_S FGS_GetOverlapArea (FGS_LOC_S* abspos1,
                               uint16_t width1,
                               uint16_t height1,
                               FGS_LOC_S* abspos2,
                               uint16_t width2,
                               uint16_t height2)
{
    FGS_AREA_S  overlap;
    int16_t     diff;

    memset(&overlap, 0, sizeof(overlap));

    /* ----- horizontal -------------------------------------------- */

    diff = abspos1->x - abspos2->x;

    if ( diff > 0 )
    {
        if ( (uint16_t)diff < width2 )
        {
            overlap.x     = diff;
            overlap.width = width2 - diff;

            if ( overlap.width > width1 )
            {
                overlap.width = width1;
            }
        }
    }
    else
    {
        diff += (int16_t)(width1);

        if ( diff > 0 )
        {
            overlap.x     = 0;
            overlap.width = (uint16_t)diff;

            if ( overlap.width > width2 )
            {
                overlap.width = width2;
            }
        }
    }

    /* ----- vertical ---------------------------------------------- */

    diff = abspos1->y - abspos2->y;

    if ( diff > 0 )
    {
        if ( (uint16_t)diff < height2 )
        {
            overlap.y      = diff;
            overlap.height = height2 - diff;

            if ( overlap.height > height1 )
            {
                overlap.height = height1;
            }
        }
    }
    else
    {
        diff += (int16_t)height1;

        if ( diff > 0 )
        {
            overlap.y      = 0;
            overlap.height = (uint16_t)diff;

            if ( overlap.height > height2 )
            {
                overlap.height = height2;
            }
        }
    }

    return overlap;
}

#if 0

/*
pMember: FGS member that contains position parameters abspos, width and height
*/
fbool_t FGS_GetOverlapStatus (FGS_MEMBER_S* pMember, const FGS_LOC_S* abspos,
                            uint16_t width, uint16_t height)
{
    fbool_t         overlapStatus = FFALSE;
    uint8_t            cnt;
    int16_t           diff;
    FGS_MEMBER_S* pMemCurr;
    uint8_t            ovl;

    /* test for overlap with all members placed in front of requested
       member */
    for ( cnt = 0; cnt < fgsInst->numMembers; cnt++ )
    {
        ovl = 0;

        pMemCurr = fgsInst->order[cnt].pMember;

        if ( !(pMemCurr->isVisible) ) continue;

        if ( pMemCurr == pMember ) break;

        /* ----- horizontal ------------------------------------------------ */

        diff = pMemCurr->abspos.x - abspos->x;

        if ( diff > 0 )
        {
            if ( (uint16_t)diff < width )
            {
                ovl |= 1;
            }
        }
        else
        {
            diff += (int16_t)(pMemCurr->pos->width);

            if ( diff > 0 )
            {
                ovl |= 1;
            }
        }

        /* ----- vertical -------------------------------------------------- */

        diff = pMemCurr->abspos.y - abspos->y;

        if ( diff > 0 )
        {
            if ( (uint16_t)diff < height )
            {
                ovl |= 2;
            }
        }
        else
        {
            diff += (int16_t)pMemCurr->pos->height;

            if ( diff > 0 )
            {
                ovl |= 2;
            }
        }

        if ( (ovl & 3) == 3 )
        {
            overlapStatus = FTRUE;
            break;
        }

    }

    return overlapStatus;
}

/* ------------------------------------------------------------------------- */

void FGS_GetPosString (SYS_STRING_S string, int32_t numBytes, uint8_t font, uint8_t align,
                       uint16_t x, uint16_t y, uint16_t width, uint16_t height, int32_t stringWidth,
                       uint16_t* strX, uint16_t* strY, uint16_t* strWidth, uint16_t* strHeight)
{
    uint8_t ascent  = 0;
    uint8_t descent = 0;
    int8_t  offsetY = 0;

    /* get string dimensions */
    fgsDraw->getFontPars (font, &ascent, &descent, &offsetY);

    if ( stringWidth >= 0 )
    {
        *strWidth  = (uint16_t)stringWidth;
    }
    else
    {
        *strWidth = fgsDraw->getStrWidth (string, numBytes, font);
    }

    *strHeight = ascent + descent;

    if ( *strWidth > width   ) *strWidth  = width;

    switch ( align & FGS_ALIGN_MASK_HOR )
    {
        default:
        case FGS_ALIGN_HOR_LEFT:
            *strX = x;
            break;

        case FGS_ALIGN_HOR_RIGHT:
            *strX = x + width - *strWidth;
            break;

        case FGS_ALIGN_HOR_CENTER:
            *strX = x + (((uint16_t)(width -  *strWidth)) / 2);
            break;
    }

    switch ( align & FGS_ALIGN_MASK_VER )
    {
        default:
        case FGS_ALIGN_VER_TOP:
            *strY = y;
            break;

        case FGS_ALIGN_VER_BOTTOM:
            *strY =y + height - (ascent + descent);
            break;

        case FGS_ALIGN_VER_CENTER:
            *strY = y + (((uint16_t)(height - ascent)) / 2);
            break;
    }

    (*strY) += offsetY;
}

void FGS_GetPosIcon (const uint32_t* addr, uint8_t align,
                     uint16_t x, uint16_t y, uint16_t width, uint16_t height,
                     uint16_t* iconX, uint16_t* iconY)
{
    uint32_t              iconWidth;
    uint32_t              iconHeight;
    const DRAW_PicItemT*  picPtr = (const DRAW_PicItemT*)(void*)addr;

    /* get icon dimensions */
    iconWidth  = picPtr->fbmHeaderPtr->width;
    iconHeight = picPtr->fbmHeaderPtr->height;

    if ( iconWidth  > width  ) iconWidth = width;
    if ( iconHeight > height ) iconHeight = height;

    switch ( align & FGS_ALIGN_MASK_HOR )
    {
        default:
        case FGS_ALIGN_HOR_LEFT:
            *iconX = x;
            break;

        case FGS_ALIGN_HOR_RIGHT:
            *iconX = x + width - iconWidth;
            break;

        case FGS_ALIGN_HOR_CENTER:
            *iconX = x + (((uint16_t)(width -  iconWidth)) / 2);
            break;
    }

    switch ( align & FGS_ALIGN_MASK_VER )
    {
        default:
        case FGS_ALIGN_VER_TOP:
            *iconY = y;
            break;

        case FGS_ALIGN_VER_BOTTOM:
            *iconY = y + height - iconHeight;
            break;

        case FGS_ALIGN_VER_CENTER:
            *iconY = y + (((uint16_t)(height -  iconHeight)) / 2);
            break;
    }
}

int32_t FGS_DrawItem (const FGS_ITEM_S* item, uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    int32_t      retVal = FAPI_OK;
    uint32_t     itemCol        = 0;
    uint8_t      itemFont       = 0;
    uint8_t      itemLineHeight = 0;
    fbool_t      drawStr        = FFALSE;
    fbool_t      multiLine      = FFALSE;
    uint32_t     bufPos         = 0;
    uint32_t     strLen;
    SYS_STRING_S itemStr;
    uint16_t     itemX, itemY;
    uint16_t     cnt;

    if ( item == NULL ) return SMARTGO_FGS_ERR_BAD_PARAMETER;

    STR_Clear (&itemStr);
    memset(fgsInst->asciiBuf,0,FGS_STRBUFCHARS);

    switch ( item->type )
    {
        case FGS_ITEM_TYPE_GENERIC:
            if ( item->item.gnr.cb != NULL )
            {
                item->item.gnr.cb (item->item.gnr.cbArg, item->align,
                                   x, y, width, height);
            }
            break;

        case FGS_ITEM_TYPE_STRING:

            itemCol  = item->item.str.col;
            itemFont = item->item.str.font;
            itemStr  = item->item.str.chr;

            if ( (item->item.str.lineHeight > 0) &&
                 (height >= (uint16_t)(2 * (item->item.str.lineHeight))) )
            {
                /* multi-line drawing enabled */
                itemLineHeight = (uint8_t)item->item.str.lineHeight;
                multiLine      = FTRUE;
            }

            drawStr  = FTRUE;
            break;

        /* ----------------------------------------------------------------- */

        case FGS_ITEM_TYPE_ICON:
            if ( (item->item.icon.addr != NULL) &&
                 (fgsDraw->drawBitmap  != NULL) )
            {
                FGS_GetPosIcon(item->item.icon.addr, item->align,
                               x, y, width, height,
                               &itemX, &itemY);

                (void)fgsDraw->drawBitmap (itemX, itemY, &(item->item.icon));
            }
            break;

        /* ----------------------------------------------------------------- */

        case FGS_ITEM_TYPE_TIME:

            switch ( item->item.time.format )
            {
                default:
                case FGS_FORMAT_TIME_DAYTIME:
                    sprintf(fgsInst->asciiBuf, "%02i:%02d",
                            item->item.time.value.hour,
                            item->item.time.value.minute);
                    break;

                case FGS_FORMAT_TIME_PLAYTIME:
                    if ( item->item.time.value.hour == 0 )
                    {
                        sprintf(fgsInst->asciiBuf, "%2i:%02d",
                                item->item.time.value.minute,
                                item->item.time.value.second);
                    }
                    else
                    {
                        sprintf(fgsInst->asciiBuf, "%2i:%02d:%02d",
                                item->item.time.value.hour,
                                item->item.time.value.minute,
                                item->item.time.value.second);
                    }
                    break;

                case FGS_FORMAT_TIME_NEGPLAYTIME:
                    if ( item->item.time.value.hour == 0 )
                    {
                        sprintf(fgsInst->asciiBuf, "-%2i:%02d",
                                item->item.time.value.minute,
                                item->item.time.value.second);
                    }
                    else
                    {
                        sprintf(fgsInst->asciiBuf, "-%2i:%02d:%02d",
                                item->item.time.value.hour,
                                item->item.time.value.minute,
                                item->item.time.value.second);
                    }
                    break;
            }

            itemCol  = item->item.time.col;
            itemFont = item->item.time.font;
            itemStr  = fgsInst->asciiStr;
            drawStr  = FTRUE;
            break;

        case FGS_ITEM_TYPE_DATE:

            switch ( item->item.date.format )
            {
                default:
                case FGS_FORMAT_DATE_INT_NORM:
                    sprintf(fgsInst->asciiBuf, "%04i-%02i-%02i",
                            item->item.date.value.year,
                            item->item.date.value.month,
                            item->item.date.value.day);
                    break;

                case FGS_FORMAT_DATE_INT_SHORT:
                    sprintf(fgsInst->asciiBuf, "%02i-%02i",
                            item->item.date.value.month,
                            item->item.date.value.day);
                    break;

                case FGS_FORMAT_DATE_EUROPE_NORM:
                    sprintf(fgsInst->asciiBuf, "%02i.%02i.%04i",
                            item->item.date.value.day,
                            item->item.date.value.month,
                            item->item.date.value.year);
                    break;

                case FGS_FORMAT_DATE_EUROPE_SHORT:
                    sprintf(fgsInst->asciiBuf, "%02i.%02i.",
                            item->item.date.value.day,
                            item->item.date.value.month);
                    break;
            }

            itemCol  = item->item.date.col;
            itemFont = item->item.date.font;
            itemStr  = fgsInst->asciiStr;
            drawStr  = FTRUE;
            break;

        case FGS_ITEM_TYPE_IP:

            switch ( item->item.ip.format )
            {
                default:
                case FGS_FORMAT_IP_V4:
                    sprintf(fgsInst->asciiBuf, "%i.%i.%i.%i",
                            item->item.ip.value[0],
                            item->item.ip.value[1],
                            item->item.ip.value[2],
                            item->item.ip.value[3]);
                    break;

                case FGS_FORMAT_IP_V6:
                    break;
            }

            itemCol  = item->item.ip.col;
            itemFont = item->item.ip.font;
            itemStr  = fgsInst->asciiStr;
            drawStr  = FTRUE;
            break;

        case FGS_ITEM_TYPE_MAC:
            sprintf(fgsInst->asciiBuf, "%02X:%02X:%02X:%02X:%02X:%02X",
                    item->item.mac.value[0],
                    item->item.mac.value[1],
                    item->item.mac.value[2],
                    item->item.mac.value[3],
                    item->item.mac.value[4],
                    item->item.mac.value[5]);

            itemCol  = item->item.mac.col;
            itemFont = item->item.mac.font;
            itemStr  = fgsInst->asciiStr;
            drawStr  = FTRUE;
            break;

        case FGS_ITEM_TYPE_NUMBER:

            switch ( item->item.number.format )
            {
                default:
                case FGS_FORMAT_NUM_NORM:
                    sprintf(fgsInst->asciiBuf, "%li", item->item.number.value);

                    /* add decimal point if necessary */
                    if ( item->item.number.decimalPlaces > 0 )
                    {
                        strLen = strlen(fgsInst->asciiBuf);

                        if ( item->item.number.decimalPlaces >= strLen )
                        {
                            strLen = 0;
                            fgsInst->asciiBuf[strLen++] = '0';
                            fgsInst->asciiBuf[strLen++] = '.';

                            switch ( item->item.number.decimalPlaces )
                            {
                                case 1: sprintf(fgsInst->asciiBuf + strLen, "%.1li", item->item.number.value); break;
                                case 2: sprintf(fgsInst->asciiBuf + strLen, "%.2li", item->item.number.value); break;
                                case 3: sprintf(fgsInst->asciiBuf + strLen, "%.3li", item->item.number.value); break;

                                default:
                                case 4: sprintf(fgsInst->asciiBuf + strLen, "%.4li", item->item.number.value); break;
                            }

                            strLen += item->item.number.decimalPlaces;
                        }
                        else
                        {
                            for ( cnt = (strLen - 1);
                                  cnt >= (strLen - item->item.number.decimalPlaces);
                                  cnt-- )
                            {
                                fgsInst->asciiBuf[cnt + 1] = fgsInst->asciiBuf[cnt];
                            }

                            fgsInst->asciiBuf[cnt + 1] = '.';
                            strLen++;
                        }
                    }

                    bufPos += STR_BufAppend (&(fgsInst->strBuf), bufPos,
                                             fgsInst->asciiStr,
                                             FGS_STRBUFCHARSET);
                    break;

                case FGS_FORMAT_NUM_SIGNEDHOURS:
                    if ( item->item.number.value > 0 )
                    {
                        sprintf(fgsInst->asciiBuf, "+ %02li:00", item->item.number.value);
                    }
                    else if ( item->item.number.value < 0 )
                    {
                        sprintf(fgsInst->asciiBuf, "- %02li:00", -(item->item.number.value));
                    }
                    else
                    {
                        sprintf(fgsInst->asciiBuf, "00:00");
                    }

                    bufPos += STR_BufAppend (&(fgsInst->strBuf), bufPos,
                                             fgsInst->asciiStr,
                                             FGS_STRBUFCHARSET);
                    break;
            }

            if ( !(STR_IsEmpty(item->item.number.unitStr)) )
            {
                bufPos += STR_BufAppend (&(fgsInst->strBuf), bufPos,
                                         STR_GetASCII(" "), FGS_STRBUFCHARSET);

                bufPos += STR_BufAppend (&(fgsInst->strBuf), bufPos,
                                         item->item.number.unitStr,
                                         FGS_STRBUFCHARSET);
            }

            itemCol  = item->item.number.col;
            itemFont = item->item.number.font;
            itemStr  = fgsInst->strBuf.string;
            drawStr  = FTRUE;
            break;

        default:
            retVal = SMARTGO_FGS_ERR_BAD_PARAMETER;
            break;
    }

    if ( drawStr                     &&
         (!(STR_IsEmpty(itemStr)))   &&
         (fgsDraw->printStr != NULL) )
    {
        if ( !multiLine )
        {
            FGS_DrawString (itemStr, itemFont, item->align, itemCol,
                            x, y, width, height, -1, -1);
        }
        else
        {
            FGS_DrawMultiLineString (itemStr, itemFont, item->align, itemCol,
                                     itemLineHeight,
                                     x, y, width, height);
        }
    }

    return retVal;
}

/*!
*******************************************************************************
**
** \brief  Create multi-line string.
**
** This function can be used to either calculate the number of lines needed
** for a string and/or to get position and size of each line.
**
** \param  string       Target string to be processed.
** \param  lineWidth    Line width of target rectangle in pixels.
** \param  font         Font to be used when rendering the text into the OSD.
** \param  lineParsed   Optional callback to get start and length of each line.
**                      Set to NULL if not used. If callback returns FFALSE,
**                      parsing is aborted, the current line not being added
**                      to the returned number of strings.
**
** \return Number of lines parsed; If lineParsed callback is set to NULL,
**         the total number of lines is returned.
**
******************************************************************************/
uint16_t FGS_GetLinesFromString (SYS_STRING_S             string,
                                       uint16_t          lineWidth,
                                       uint8_t           font,
                                       FGS_LINEPARSED_CB lineParsed)
{
    SYS_STRING_S    pLine = string; /* points to start of curr. line */
    SYS_STRING_S    pCurr = string; /* points to curr. position */
    SYS_STRING_S    tmpLine;
    SYS_STRING_S    tmpStr;
    fbool_t         stringEnd    = FFALSE;
    uint16_t        numLines     = 0;
    uint32_t        numBlankChars;
    uint32_t        numBlankBytes;
    uint32_t        bytesPerLine  = 0;
    uint16_t        charPerWord;
    uint32_t        bytesPerWord;
    uint32_t        tmpBytesPerWord;
    uint16_t        charCnt;
    fbool_t         abort;
    uint16_t        pixPerChar;
    uint16_t        pixPerLine   = 0;
    uint16_t        pixPerWord;
    uint16_t        tmpPixPerWord;
    uint16_t        pixPerBlank;
    SYS_CHAR        currChar;
    uint32_t        bytesPerChar;

    pixPerBlank = fgsDraw->getStrWidth (STR_GetASCII(" "), -1, font);

    while ( !stringEnd )
    {
        /* get number of blanks preceding next word to be processed. */
        numBlankChars = 0;
        numBlankBytes = 0;

        bytesPerChar = STR_CharGet (pCurr, numBlankBytes, &currChar);

        while ( (bytesPerChar > 0) && (currChar == ' ') )
        {
            numBlankBytes += bytesPerChar;
            numBlankChars++;

            bytesPerChar = STR_CharGet (pCurr, numBlankBytes, &currChar);
        }

        /* get number of characters of next word */

        tmpLine      = pCurr;
        tmpLine.chr += numBlankBytes;
        charPerWord  = 0;
        bytesPerWord = 0;
        abort        = FFALSE;

        while ( !abort )
        {
            bytesPerChar = STR_CharGet (tmpLine, bytesPerWord, &currChar);

            switch ( currChar )
            {
                case 0:         /* string end */
                    stringEnd = FTRUE;
                    /* FALLTHROUGH */

                case STR_CHAR_BLANK:        /* blank */
                case STR_CHAR_LINEBREAK:    /* line end */
                    abort = FTRUE;
                    break;

                default:        /* any other character */
                    bytesPerWord += bytesPerChar;
                    charPerWord++;
                    break;
            }
        }

        /* get word's pixel width */
        pixPerWord = fgsDraw->getStrWidth (tmpLine, bytesPerWord, font);

        /* perform line handling */

        if ( (uint16_t)(pixPerLine + (numBlankChars * pixPerBlank) + pixPerWord) >
             lineWidth )
        {
            /* current word + preceding blanks do not fit into current line:
               discard blanks, move current word into next line */

            /* print current line */

            if ( pixPerLine > 0 )
            {
                if ( lineParsed != NULL )
                {
                    if ( !(lineParsed (numLines, pLine, bytesPerLine)) ) break;
                }

                pLine.chr += bytesPerLine + numBlankBytes;

                bytesPerLine = 0;
                pixPerLine  = 0;
                numLines++;
            }

            pCurr.chr += numBlankBytes;

            abort = FFALSE;

            while ( pixPerWord > lineWidth )
            {
                /* single word is wider than line width: split it! */

                tmpPixPerWord = 0;
                tmpBytesPerWord = 0;
                tmpStr          = pCurr;

                for ( charCnt = 0; charCnt < charPerWord; charCnt++ )
                {
                    bytesPerChar = STR_CharGet (tmpStr, 0, NULL);

                    if ( bytesPerChar == 0 )
                    {
                        /* should never happen! */
                        break;
                    }

                    pixPerChar = fgsDraw->getStrWidth (tmpStr, bytesPerChar,
                                                       font);

                    if ( (uint16_t)(tmpPixPerWord + pixPerChar) > lineWidth )
                    {
                        break;
                    }
                    else
                    {
                        tmpPixPerWord += pixPerChar;
                        tmpBytesPerWord += bytesPerChar;
                        tmpStr.chr      += bytesPerChar;
                    }
                }

                if ( lineParsed != NULL )
                {
                    if ( !(lineParsed (numLines, pCurr, tmpBytesPerWord)) )
                    {
                        abort = FTRUE;
                        break;
                    }
                }

                numLines++;

                if ( pixPerWord > tmpPixPerWord ) pixPerWord -= tmpPixPerWord;
                else                              pixPerWord  = 0;

                charPerWord -= charCnt;

                if ( bytesPerWord > tmpBytesPerWord )
                {
                    bytesPerWord -= tmpBytesPerWord;
                }
                else
                {
                    bytesPerWord = 0;
                }

                pCurr.chr += tmpBytesPerWord;
            }

            if ( abort ) break;

            pixPerLine   = pixPerWord;
            bytesPerLine = bytesPerWord;
            pLine        = pCurr;
            pCurr.chr   += bytesPerWord;
        }
        else if ( charPerWord < 1 )
        {
            /* line break detected: discard blanks, flush current line */

            if ( (pixPerLine > 0) || (!stringEnd) )
            {
                if ( lineParsed != NULL )
                {
                    if ( !(lineParsed (numLines, pLine, bytesPerLine)) ) break;
                }

                numLines++;
            }

            pixPerLine   = 0;
            bytesPerLine = 0;

            pCurr.chr   += numBlankBytes + STR_CharGet (tmpLine, 0, NULL);
            pLine        = pCurr;
        }
        else
        {
            /* add word to current line. */

            pixPerLine   += (numBlankChars * pixPerBlank) + pixPerWord;
            bytesPerLine += numBlankBytes + bytesPerWord;

            pCurr.chr    += numBlankBytes + bytesPerWord;
        }

        if ( stringEnd )
        {
            /* flush unfinished last line */

            if ( pixPerLine > 0 )
            {
                if ( lineParsed != NULL )
                {
                    if ( !(lineParsed (numLines, pLine, bytesPerLine)) ) break;
                }

                numLines++;
            }
        }
    }

    return numLines;
}

static void FGS_DrawString (SYS_STRING_S    itemStr,
                                  uint8_t  itemFont,
                                  uint8_t  itemAlign,
                                  uint32_t itemCol,
                                  uint16_t x,
                                  uint16_t y,
                                  uint16_t width,
                                  uint16_t height,
                              int32_t strWidth,
                              int32_t numBytes)
{
    uint16_t    itemX;
    uint16_t    itemY;
    uint16_t    itemWidth;
    uint16_t    itemHeight;

    if ( numBytes == 0 )
    {
        return;
    }
    else if ( numBytes < 0 )
    {
        numBytes = STR_GetLineEnd (itemStr);
    }

    FGS_GetPosString (itemStr, numBytes, itemFont, itemAlign,
                     x, y, width, height, strWidth,
                     &itemX, &itemY, &itemWidth, &itemHeight);

    (void)fgsDraw->printStr (itemX, itemY, itemCol, itemFont, numBytes,
                             itemWidth, strWidth, itemStr, FTRUE);
}

static void FGS_DrawMultiLineString (SYS_STRING_S string, uint8_t font,
                                     uint8_t itemAlign, uint32_t itemCol, uint8_t lineHeight,
                                     uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    SYS_STRING_S    pLine = string; /* points to start of curr. line */
    SYS_STRING_S    pCurr = string; /* points to curr. position */
    uint16_t        posY        = 0;
    SYS_STRING_S    tmpLine;
    SYS_STRING_S    tmpStr;
    fbool_t         stringEnd    = FFALSE;
    uint32_t        numBlankChars;
    uint32_t        numBlankBytes;
    uint32_t        bytesPerLine = 0;
    uint16_t        charPerWord;
    uint32_t        bytesPerWord;
    uint32_t        tmpBytesPerWord;
    uint16_t        charCnt;
    fbool_t         abort;
    uint16_t        pixPerChar;
    uint16_t        pixPerLine   = 0;
    uint16_t        pixPerWord;
    uint16_t        tmpPixPerWord;
    uint16_t        pixPerBlank;
    SYS_CHAR        currChar;
    uint32_t        bytesPerChar;

    if ( height < lineHeight ) return;

    pixPerBlank = fgsDraw->getStrWidth (STR_GetASCII(" "), -1, font);

    while ( !stringEnd )
    {
        /* get number of blanks preceding next word to be processed. */
        numBlankChars = 0;
        numBlankBytes = 0;

        bytesPerChar = STR_CharGet (pCurr, numBlankBytes, &currChar);

        while ( (bytesPerChar > 0) && (currChar == ' ') )
        {
            numBlankBytes += bytesPerChar;
            numBlankChars++;

            bytesPerChar = STR_CharGet (pCurr, numBlankBytes, &currChar);
        }

        /* get number of characters of next word */

        tmpLine      = pCurr;
        tmpLine.chr += numBlankBytes;
        charPerWord  = 0;
        bytesPerWord = 0;
        abort        = FFALSE;

        while ( !abort )
        {
            bytesPerChar = STR_CharGet (tmpLine, bytesPerWord, &currChar);

            switch ( currChar )
            {
                case 0:         /* string end */
                    stringEnd = FTRUE;
                    /* FALLTHROUGH */

                case STR_CHAR_BLANK:        /* blank */
                case STR_CHAR_LINEBREAK:    /* line end */
                    abort = FTRUE;
                    break;

                default:        /* any other character */
                    bytesPerWord += bytesPerChar;
                    charPerWord++;
                    break;
            }
        }

        /* get word's pixel width */
        pixPerWord = fgsDraw->getStrWidth (tmpLine, bytesPerWord, font);

        /* perform line handling */

        if ( (uint16_t)(pixPerLine + (numBlankChars * pixPerBlank) + pixPerWord) >
             width )
        {
            /* current word + preceding blanks do not fit into current line:
               discard blanks, move current word into next line */

            /* print current line */

            if ( pixPerLine > 0 )
            {
                FGS_DrawString (pLine, font, itemAlign, itemCol,
                                x, posY + y, width, lineHeight, pixPerLine,
                                bytesPerLine);

                pLine.chr += bytesPerLine + numBlankBytes;

                bytesPerLine = 0;
                pixPerLine  = 0;
                posY       += lineHeight;

                /* test if another line is available */
                if ( (uint16_t)(posY + lineHeight) > height )
                {
                    break;
                }
            }

            pCurr.chr += numBlankBytes;

            abort = FFALSE;

            while ( pixPerWord > width )
            {
                /* single word is wider than line width: split it! */

                tmpPixPerWord = 0;
                tmpBytesPerWord = 0;
                tmpStr          = pCurr;

                for ( charCnt = 0; charCnt < charPerWord; charCnt++ )
                {
                    bytesPerChar = STR_CharGet (tmpStr, 0, NULL);

                    if ( bytesPerChar == 0 )
                    {
                        /* should never happen! */
                        break;
                    }

                    pixPerChar = fgsDraw->getStrWidth (tmpStr, bytesPerChar,
                                                       font);

                    if ( (uint16_t)(tmpPixPerWord + pixPerChar) > width )
                    {
                        break;
                    }
                    else
                    {
                        tmpPixPerWord += pixPerChar;
                        tmpBytesPerWord += bytesPerChar;
                        tmpStr.chr      += bytesPerChar;
                    }
                }

                /* print current line */

                FGS_DrawString (pCurr, font, itemAlign, itemCol,
                                x, posY + y, width, lineHeight, tmpPixPerWord,
                                tmpBytesPerWord);

                posY += lineHeight;

                /* test if another line is available */
                if ( (uint16_t)(posY + lineHeight) > height )
                {
                    abort = FTRUE;
                    break;
                }

                if ( pixPerWord > tmpPixPerWord ) pixPerWord -= tmpPixPerWord;
                else                              pixPerWord  = 0;

                charPerWord -= charCnt;

                if ( bytesPerWord > tmpBytesPerWord )
                {
                    bytesPerWord -= tmpBytesPerWord;
                }
                else
                {
                    bytesPerWord = 0;
                }

                pCurr.chr += tmpBytesPerWord;
            }

            if ( abort ) break;

            pixPerLine   = pixPerWord;
            bytesPerLine = bytesPerWord;

            pLine        = pCurr;
            pCurr.chr   += bytesPerWord;
        }
        else if ( charPerWord < 1 )
        {
            /* line break detected: discard blanks, flush current line */

            FGS_DrawString (pLine, font, itemAlign, itemCol,
                            x, posY + y, width, lineHeight, pixPerLine,
                            bytesPerLine);

            posY += lineHeight;

            /* test if another line is available */
            if ( (uint16_t)(posY + lineHeight) > height )
            {
                break;
            }

            pixPerLine   = 0;
            bytesPerLine = 0;

            pCurr.chr   += numBlankBytes + STR_CharGet (tmpLine, 0, NULL);
            pLine        = pCurr;
        }
        else
        {
            /* add word to current line. */

            pixPerLine   += (numBlankChars * pixPerBlank) + pixPerWord;
            bytesPerLine += numBlankBytes + bytesPerWord;

            pCurr.chr    += numBlankBytes + bytesPerWord;
        }

        if ( stringEnd )
        {
            /* flush unfinished last line */

            if ( pixPerLine > 0 )
            {
                FGS_DrawString (pLine, font, itemAlign, itemCol,
                                x, posY + y, width, lineHeight, pixPerLine,
                                bytesPerLine);
            }
        }
    }
}

/* ------------------------------------------------------------------------- */

fbool_t FGS_AreaOccupied (int32_t memberId, FGS_AREA_S* pArea)
{
    uint16_t        cnt;
    FGS_MEMBER_S*   pMem;

    /* test each member for overlapping */
    for ( cnt = 0; cnt < fgsInst->numMembers; cnt++ )
    {
        pMem = fgsInst->order[cnt].pMember;

        if ( !(pMem->isVisible) )
        {
            continue;
        }
        if ( pMem->id == memberId )
        {
            continue;
        }

        if ( ((uint16_t)(pMem->abspos.x)                     < (uint16_t)(pArea->x + pArea->width))  &&
             ((uint16_t)(pMem->abspos.x + pMem->pos->width)  > (uint16_t)(pArea->x))                 &&
             ((uint16_t)(pMem->abspos.y)                     < (uint16_t)(pArea->y + pArea->height)) &&
             ((uint16_t)(pMem->abspos.y + pMem->pos->height) > (uint16_t)(pArea->y)) )
        {
            return FTRUE;
        }
    }

    return FFALSE;
}

#endif

/* 21ba6d74 - complete */
/*static*/ fbool_t FGS_AreaCheck (uint16_t* areaIdx, FGS_MEMBER_S* pMem)
{
    FGS_AREA_S  newArea[4]; /* Max. number of areas current one is split into */
    uint8_t     newAreaCnt = 0;
    FGS_AREA_S* pArea = fgsInst->hideArea + (*areaIdx);
    int32_t     diff;
    uint16_t    memX2, memY2, areaX2, areaY2;
    fbool_t     retVal = FTRUE;
    int16_t     cnt;

//    memset(newArea, 0 ,sizeof(FGS_AREA_S)*4);

    memX2  = pMem->abspos.x + pMem->pos->width;
    memY2  = pMem->abspos.y + pMem->pos->height;
    areaX2 = pArea->x + pArea->width;
    areaY2 = pArea->y + pArea->height;

    /* ----- test if area overlaps with member ----------------------------- */

    if ( ((uint16_t)(pMem->abspos.x) < areaX2)          &&
         (memX2                 > (uint16_t)(pArea->x)) &&
         ((uint16_t)(pMem->abspos.y) < areaY2)          &&
         (memY2                 > (uint16_t)(pArea->y)) )
    {
        /* overlap: OK! */
    }
    else
    {
        (*areaIdx)++;
        return FTRUE;
    }

    /* ----- top area ------------------------------------------------------ */

    diff = (int32_t)pMem->abspos.y - (int32_t)pArea->y;

    if ( diff > 0 )
    {
        newArea[newAreaCnt].x      = pArea->x;
        newArea[newAreaCnt].y      = pArea->y;
        newArea[newAreaCnt].width  = pArea->width;
        newArea[newAreaCnt].height = (uint16_t)diff;

        newAreaCnt++;
    }

    /* ----- left area ----------------------------------------------------- */

    diff = (int32_t)pMem->abspos.x - (int32_t)pArea->x;

    if ( diff > 0 )
    {
        newArea[newAreaCnt].x      = pArea->x;
        newArea[newAreaCnt].width  = (uint16_t)diff;

        if ( (uint16_t)pMem->abspos.y < pArea->y )
        {
            newArea[newAreaCnt].y = pArea->y;
        }
        else
        {
            newArea[newAreaCnt].y = pMem->abspos.y;
        }

        if ( memY2 > areaY2 ) newArea[newAreaCnt].height = areaY2 -
                                                           pMem->abspos.y;
        else                  newArea[newAreaCnt].height = pMem->pos->height;

        newAreaCnt++;
    }

    /* ----- right area ---------------------------------------------------- */

    diff = (int32_t)areaX2 - (int32_t)memX2;

    if ( diff > 0 )
    {
        newArea[newAreaCnt].x      = memX2;
        newArea[newAreaCnt].width  = (uint16_t)diff;

        if ( (uint16_t)pMem->abspos.y < pArea->y )
        {
            newArea[newAreaCnt].y = pArea->y;
        }
        else
        {
            newArea[newAreaCnt].y = pMem->abspos.y;
        }

        if ( memY2 > areaY2 ) newArea[newAreaCnt].height = areaY2 -
                                                           pMem->abspos.y;
        else                  newArea[newAreaCnt].height = pMem->pos->height;

        newAreaCnt++;
    }

    /* ----- bottom area --------------------------------------------------- */

    diff = (int32_t)(pArea->y + pArea->height) -
           (int32_t)(pMem->pos->height + pMem->abspos.y);

    if ( diff > 0 )
    {
        newArea[newAreaCnt].x      = pArea->x;
        newArea[newAreaCnt].y      = memY2;
        newArea[newAreaCnt].width  = pArea->width;
        newArea[newAreaCnt].height = (uint16_t)diff;

        newAreaCnt++;
    }

    /* ---- Handle new areas ----------------------------------------------- */

    if ( newAreaCnt == 0 )
    {
        /* Area is completely overlapped by member, remove it! */
        for ( cnt = (*areaIdx); cnt < (int16_t)(fgsInst->numAreas - 1); cnt++ )
        {
            fgsInst->hideArea[cnt] = fgsInst->hideArea[cnt + 1];
        }

        if ( fgsInst->numAreas > 0 ) fgsInst->numAreas--;
    }
    else if ( (uint16_t)(newAreaCnt - 1 + fgsInst->numAreas) > FGS_HIDE_AREA_MAX )
    {
        retVal = FFALSE;
    }
    else
    {
        /* Replace area by new areas
           (-> existing one removed, new ones inserted!) */

        for ( cnt = (fgsInst->numAreas - 1); cnt > (int16_t)(*areaIdx); cnt-- )
        {
            fgsInst->hideArea[cnt + newAreaCnt - 1] = fgsInst->hideArea[cnt];
        }

        fgsInst->numAreas += (uint8_t)(newAreaCnt - 1);

        /* insert new areas */
        for ( cnt = 0; cnt < (int16_t)newAreaCnt; cnt++ )
        {
            fgsInst->hideArea[(*areaIdx)++] = newArea[cnt];
        }
    }

    return retVal;
}

#if 0

/*!
*******************************************************************************
** \brief   Gets NON zero'd cached memory of size 'size'.
**
** \param   size    requested memory size.
**
** \return  Pointer to alloced memory, NULL in case of error.
**
** \sa
**          - FGS_Free()
**
*******************************************************************************
*/
void* FGS_Malloc(uint32_t size)
{
    if( fgsInst == NULL)
    {
        return NULL;
    }
    return fgsInst->data.mem.get(size);
}

/*!
*******************************************************************************
** \brief   Release the memory.
**
** \param   mem_ptr     Memory to be released.
**
** \sa
**          - FGS_Malloc()
**
*******************************************************************************
*/
void FGS_Free(void *mem_ptr)
{
    if( fgsInst == NULL)
    {
        return;
    }
    fgsInst->data.mem.release(mem_ptr);
}

#endif

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
