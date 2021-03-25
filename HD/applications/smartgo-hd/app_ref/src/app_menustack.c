/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_menustack.c
**
** \brief       Menu stack module.
**
** Detail description. [\ref app_smartgo_app_ref_menustack]
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
** - Info 715: Symbol 'h' not referenced
**
*****************************************************************************
*/
/*lint -save -e715 */
#define DEBUG 0

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "app_main.h"

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
FSTATIC fbool_t MENUSTACK_LeaveCurrent    (MENUSTACK_INST_S* inst,
                                           MENUSTACK_ITEM_S* pStack);
FSTATIC void    MENUSTACK_FirstToOpen     (MENUSTACK_INST_S* inst);
FSTATIC void    MENUSTACK_LastClosed      (MENUSTACK_INST_S* inst);

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   initPars    TODO
**
** \return  One of the following status codes:
**          - always #FAPI_OK.
**
*******************************************************************************
*/
/* 21b12638 - complete */
int32_t MENUSTACK_Init (MENUSTACK_INIT_S* initPars)
{
    MENUSTACK_INST_S*   inst = &(appDat->menuStack);
    uint16_t            cnt;

    memset(inst, 0, sizeof(MENUSTACK_INST_S));

    inst->pars = *initPars;

    for ( cnt = 0; cnt < MENU_STACKITEMS_MAX; cnt++ )
    {
        inst->menuStack[cnt].entry       = NULL;
        inst->menuStack[cnt].entryArg    = NULL;
        inst->menuStack[cnt].cleanup     = NULL;
        inst->menuStack[cnt].cleanupArg  = NULL;
        inst->menuStack[cnt].dataValid   = FFALSE;
    }

    inst->menuStackLvl       = 0;
    inst->menuStackForceExit = FFALSE;

    for ( cnt = 0; cnt < MENU_EXTITEMS_MAX; cnt++ )
    {
        inst->menuStackExt[cnt].used        = FFALSE;
        inst->menuStackExt[cnt].cleanup     = NULL;
        inst->menuStackExt[cnt].cleanupArg  = NULL;
    }

    inst->focusClaimId = -1;

    memset(inst->Data_504, -1, 96);

#if 0
    inst->focusForceId = -1;
#else
    inst->Data_600 = -1;
#endif

    return FAPI_OK;
}


/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   newEntry    TODO
** \param   arg         TODO
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
/* 21b12404 - complete */
fbool_t MENUSTACK_Up (MENUSTACK_ENTRY newEntry, FAPI_SYS_HandleT arg)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);
    fbool_t           retVal = FFALSE;
    MENUSTACK_ITEM_S* pStack;

    do
    {
        if ( inst->menuStackLvl >= MENU_STACKITEMS_MAX ) break;

        pStack = inst->menuStack + inst->menuStackLvl;

        /* test if requested menu can be opened by passing FTRUE as test argument */
        if ( newEntry(arg, FTRUE) == FFALSE ) break;

        /* leave current menu */
        if ( MENUSTACK_LeaveCurrent(inst, pStack) == FFALSE ) break;

        pStack++;

        /* push entry point for next menu onto stack */
        pStack->entry      = newEntry;
        pStack->entryArg   = arg;
        pStack->cleanup    = NULL;
        pStack->cleanupArg = NULL;
        pStack->dataValid  = FFALSE;

        /* first menu to be opened? */
        MENUSTACK_FirstToOpen(inst);

        inst->menuStackLvl++;

        /* enter new menu */
        retVal = newEntry(arg, FFALSE);

        if ( retVal == FFALSE ) /* fallback to root menu: should not happen */
        {
            /* invalidate cleanup handler in case it has been set by failing
               entry handler */
            pStack->cleanup    = NULL;
            pStack->cleanupArg = NULL;

            /* Return to root menu if existing. */
            retVal = MENUSTACK_Exit(NULL);

            if ( retVal == FFALSE )
            {
                /* fallback has failed: undefined state! */
/*147*/         DBG_Assert( FFALSE );
            }
        }
    } while (0);

    inst->menuStackForceExit = FFALSE;

    return retVal;
}


/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   newEntry    TODO
** \param   arg         TODO
** \param   targetLevel The Menustack level swicht to, -1 keeps current level.
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
/* 21b12288 - todo */
fbool_t MENUSTACK_Switch (MENUSTACK_ENTRY newEntry, FAPI_SYS_HandleT arg,
                          int16_t targetLevel)
{
    MENUSTACK_INST_S*   inst     = &(appDat->menuStack);
    fbool_t             retVal   = FFALSE;
    MENUSTACK_ITEM_S*   pStack;
    uint16_t            newLevel = (targetLevel < 0) ? inst->menuStackLvl
                                                     : (uint16_t)targetLevel;

    do
    {
        if ( targetLevel >= MENU_STACKITEMS_MAX ) break;

        pStack = inst->menuStack + inst->menuStackLvl;

        /* test if requested menu can be opened */
        if ( newEntry(arg, FTRUE) == FFALSE )
        {
#if 0
            if( targetLevel == 0)
#endif
            {
                break;
            }
        }

        /* leave current menu */
        if ( MENUSTACK_LeaveCurrent(inst, pStack) == FFALSE ) break;

        pStack = inst->menuStack + newLevel;

        /* push entry point for next menu onto stack */
        pStack->entry      = newEntry;
        pStack->entryArg   = arg;
        pStack->cleanup    = NULL;
        pStack->cleanupArg = NULL;
        pStack->dataValid  = FFALSE;

        /* first menu to be opened? */
        if ( newLevel > 0 )
        {
            MENUSTACK_FirstToOpen(inst);
        }

        inst->menuStackLvl = newLevel;

        retVal = newEntry(arg, FFALSE);

        if ( retVal == FFALSE ) /* fallback to root menu: should not happen */
        {
            /* invalidate cleanup handler in case it has been set by failing
               entry handler */
            pStack->cleanup    = NULL;
            pStack->cleanupArg = NULL;

            /* Return to root menu if existing. */
            if ( MENUSTACK_Exit(NULL) == FFALSE )
            {
                /* fallback has failed: undefined state! */
/*211*/         DBG_Assert( FFALSE );
            }

            break;
        }

        /* last menu closed? */
        MENUSTACK_LastClosed(inst);
    } while (0);

    inst->menuStackForceExit = FFALSE;

    return retVal;
}

#if 0

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   h   TODO
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
fbool_t MENUSTACK_Back (FAPI_SYS_HandleT h)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);
    fbool_t           retVal = FFALSE;
    MENUSTACK_ITEM_S* pStack;

    do
    {
        if ( inst->menuStackLvl < 1 )
        {
            retVal = FTRUE;
            break;
        }

        pStack = (inst->menuStack + (inst->menuStackLvl - 1));

        /* check if entry point for target menu exists */
        if ( pStack->entry == NULL ) break;

        /* test if requested menu can be opened */
        if ( pStack->entry(NULL, FTRUE) == FFALSE ) break;

        pStack++;

        /* leave current menu */
        if ( MENUSTACK_LeaveCurrent(inst, pStack) == FFALSE ) break;

        pStack--;

        pStack->cleanup    = NULL;
        pStack->cleanupArg = NULL;

        inst->menuStackLvl--;

        retVal = pStack->entry(NULL, FFALSE);

        if ( retVal == FFALSE )
        {
            /* restore stack pointer */
            inst->menuStackLvl++;
            break;
        }

        /* last menu closed? */
        MENUSTACK_LastClosed(inst);
    } while (0);

    inst->menuStackForceExit = FFALSE;

    return retVal;
}

#endif

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   h   TODO
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
/* 21b120c8 - complete */
fbool_t MENUSTACK_Exit (FAPI_SYS_HandleT h)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);
    fbool_t           retVal = FFALSE;
    MENUSTACK_ITEM_S* pStack;
    uint16_t              currLvl = inst->menuStackLvl;

    do
    {
        if ( inst->menuStackLvl < 1 )
        {
            retVal = FTRUE;
            break;
        }

        /* check if entry point for root menu exists */
        if ( inst->menuStack[0].entry == NULL ) break;

        /* test if requested menu can be opened */
        if ( inst->menuStack[0].entry(NULL, FTRUE) ==
             FFALSE )
        {
            break;
        }

        pStack = inst->menuStack + inst->menuStackLvl;

        /* leave current menu */
        if ( MENUSTACK_LeaveCurrent(inst, pStack) == FFALSE ) break;

        pStack = inst->menuStack + 0;

        inst->menuStackLvl = 0;

        pStack->cleanup    = NULL;
        pStack->cleanupArg = NULL;

        /* enter level-0 menu */
        retVal = pStack->entry(NULL, FFALSE);

        if ( retVal == FFALSE )
        {
            /* restore stack pointer */
            inst->menuStackLvl = currLvl;
            break;
        }

        /* last menu closed? */
        MENUSTACK_LastClosed(inst);

    } while (0);

    inst->menuStackForceExit = FFALSE;

    return retVal;
}


/*!
*******************************************************************************
**
** \brief   TODO
**
** \return  the current Menustack level.
**
*******************************************************************************
*/
/* 21b11d00 - complete */
uint16_t MENUSTACK_GetLevel (void)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    return inst->menuStackLvl;
}


/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   data    TODO
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
/* 21b11d1c - complete */
fbool_t MENUSTACK_GetData (uint32_t* data)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    if ( inst->menuStack[inst->menuStackLvl].dataValid == FFALSE )
    {
        return FFALSE;
    }
    else
    {
        *data = inst->menuStack[inst->menuStackLvl].data;
        return FTRUE;
    }
}

#if 0

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   data    TODO
**
*******************************************************************************
*/
void MENUSTACK_SetData (uint32_t data)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    inst->menuStack[inst->menuStackLvl].data      = data;
    inst->menuStack[inst->menuStackLvl].dataValid = FTRUE;
}

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   newEntry    TODO
** \param   arg         TODO
**
*******************************************************************************
*/
void MENUSTACK_SetEntry (MENUSTACK_ENTRY newEntry, FAPI_SYS_HandleT arg)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    inst->menuStack[inst->menuStackLvl].entry    = newEntry;
    inst->menuStack[inst->menuStackLvl].entryArg = arg;
}

#endif

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   newCleanup  TODO
** \param   arg         TODO
**
*******************************************************************************
*/
/* 21b11e18 - complete */
void MENUSTACK_SetCleanup (MENUSTACK_CLEANUP newCleanup, FAPI_SYS_HandleT arg)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    inst->menuStack[inst->menuStackLvl].cleanup    = newCleanup;
    inst->menuStack[inst->menuStackLvl].cleanupArg = arg;
}

#if 0

/*!
*******************************************************************************
**
** \brief   Closing of next menu via MENUSTACK_Switch/-Back or -Exit will be
**          done by force.
**
*******************************************************************************
*/
void MENUSTACK_SetForceMode (void)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    inst->menuStackForceExit = FTRUE;
}

/* ------------------------------------------------------------------------- */

#endif

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   id  TODO
**
** \return  One of the following status codes:
**          - always #FAPI_OK.
**
*******************************************************************************
*/
/* 21b12824 - complete */
int32_t MENUSTACK_FocusClaim (int32_t id)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    inst->focusClaimId = id;

#if 0
    if ( inst->focusForceId < 0 )
    {
        (void)FGS_SetMemberFocus (id);
    }
#else
    if (inst->Data_600 < 0)
    {
        (void)FGS_SetMemberFocus (id);
    }
#endif

    return FAPI_OK;
}

#if 0

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   id  TODO
**
** \return  One of the following status codes:
**          - always #FAPI_OK.
**
*******************************************************************************
*/
int32_t MENUSTACK_FocusRelease (int32_t id)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    if ( id == inst->focusForceId )
    {
        inst->focusForceId = -1;

        (void)FGS_SetMemberFocus (inst->focusClaimId);
    }
    else if ( id == inst->focusClaimId )
    {
        inst->focusClaimId = -1;
    }

    return FAPI_OK;
}

#endif

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   id  TODO
**
** \return  One of the following status codes:
**          - always #FAPI_OK.
**
*******************************************************************************
*/
/* 21b12730 - complete */
int32_t MENUSTACK_FocusForce (int32_t id)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

#if 0
    inst->focusForceId = id;
#else
    inst->Data_600++;
    inst->Data_504[inst->Data_600] = id;
#endif

    (void)FGS_SetMemberFocus (id);

    return FAPI_OK;
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   inst    TODO
** \param   pStack  TODO
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
/* 21b1203c - complete */
/*FSTATIC*/ fbool_t MENUSTACK_LeaveCurrent (MENUSTACK_INST_S* inst,
                                        MENUSTACK_ITEM_S* pStack)
{
    fbool_t retVal = FTRUE;

    /* leave current menu */
    if ( pStack->cleanup != NULL )
    {
        retVal = pStack->cleanup (pStack->cleanupArg,
                                  inst->menuStackForceExit);

        /* A cleanup with "force" option enabled must not fail! */
/*474*/ DBG_Assert(!(inst->menuStackForceExit && (!retVal)));
    }

    inst->menuStackForceExit = FFALSE;

    return retVal;
}

#if 0

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   newCleanup  TODO
** \param   arg         TODO
**
** \return  int32_t index = -1
**
*******************************************************************************
*/
int32_t MENUSTACK_AddExt (MENUSTACK_CLEANUP newCleanup, FAPI_SYS_HandleT arg)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);
    int32_t               index = -1;
    int32_t               cnt;

    for ( cnt = 0; cnt < MENU_EXTITEMS_MAX; cnt++ )
    {
        if ( inst->menuStackExt[cnt].used == FFALSE )
        {
            inst->menuStackExt[cnt].used       = FTRUE;
            inst->menuStackExt[cnt].cleanup    = newCleanup;
            inst->menuStackExt[cnt].cleanupArg = arg;

            /* first menu to be opened? */
            MENUSTACK_FirstToOpen(inst);

            index = cnt;
            inst->numExt++;
            break;
        }
    }

    return index;
}

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   index   TODO
**
** \return  One of the following status codes:
**          - #FAPI_OK.
**          - #APPL_SMARTGO_ERR_BAD_PARAMETER
**
*******************************************************************************
*/
int32_t MENUSTACK_RemoveExt (int32_t index)
{
    MENUSTACK_INST_S* inst = &(appDat->menuStack);

    if ( (index <  0)                 ||
         (index >= MENU_EXTITEMS_MAX) ||
         (inst->numExt < 1) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    if ( inst->menuStackExt[index].used == FTRUE)
    {
        inst->menuStackExt[index].used = FFALSE;
        inst->numExt--;

        /* last menu closed? */
        MENUSTACK_LastClosed(inst);
    }

    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   force   TODO
**
** \return  One of the following status codes:
**          - #FTRUE
**          - #FFALSE
**
*******************************************************************************
*/
fbool_t MENUSTACK_CloseAllExt (fbool_t force)
{
    MENUSTACK_INST_S*   inst = &(appDat->menuStack);
    fbool_t             retVal = FTRUE;
    int32_t             cnt;

    // TODO: ensure that items are removed in order of building

    for ( cnt = MENU_EXTITEMS_MAX - 1; cnt >= 0; cnt-- )
    {
        if ( inst->menuStackExt[cnt].used == FTRUE )
        {
            if ( inst->menuStackExt[cnt].cleanup != NULL )
            {
                retVal = inst->menuStackExt[cnt].cleanup(
                                            inst->menuStackExt[cnt].
                                            cleanupArg, force);

/*551*/         DBG_Assert(!(force && (!retVal)));

                if ( retVal == FFALSE ) break;
            }

            inst->menuStackExt[cnt].used = FFALSE;
        }
    }

    inst->numExt = 0;

    /* last menu closed! */
    MENUSTACK_LastClosed(inst);

    return retVal;
}

#endif

/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   inst    TODO
**
*******************************************************************************
*/
/* 21b11e78 - complete */
/*FSTATIC*/ void MENUSTACK_FirstToOpen (MENUSTACK_INST_S* inst)
{
    if ( inst->pars.firstMenuToOpen == NULL ) return;

    #ifdef APPL_CONAX_ENABLED
    FCNX_EnterMenu();
    #endif /* APPL_CONAX_ENABLED */

    if ( (inst->menuStackLvl == 0) &&
         (inst->numExt       == 0) )
    {
        inst->pars.firstMenuToOpen();
    }
}


/*!
*******************************************************************************
**
** \brief   TODO
**
** \param   inst    TODO
**
*******************************************************************************
*/
/* 21b11f4c - todo */
/*FSTATIC*/ void MENUSTACK_LastClosed (MENUSTACK_INST_S* inst)
{
    if ( inst->pars.lastMenuClosed == NULL ) return;

    #ifdef APPL_CONAX_ENABLED
    FCNX_LeaveMenu();
    #endif /* APPL_CONAX_ENABLED */

    if ( (inst->menuStackLvl == 0) &&
         (inst->numExt       == 0) )
    {
        inst->pars.lastMenuClosed();
    }
}


/******************************************************************************/
/*lint -restore */
/* END OF FILE */
