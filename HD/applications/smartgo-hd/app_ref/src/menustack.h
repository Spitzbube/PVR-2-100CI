/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/inc/menustack.h
**
** \brief       Menu stack implementation.
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
*/
#ifndef _MENUSTACK_H_
#define _MENUSTACK_H_

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

#define MENU_STACKITEMS_MAX    16  // max. depth of menu hierarchy
#define MENU_EXTITEMS_MAX       8  // max. number of external items

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef fbool_t (*MENUSTACK_ENTRY)   (FAPI_SYS_HandleT h, fbool_t test);
typedef fbool_t (*MENUSTACK_CLEANUP) (FAPI_SYS_HandleT h, fbool_t force);

typedef struct
{
    /* menu's entry point */
    MENUSTACK_ENTRY     entry; //0
    FAPI_SYS_HandleT    entryArg; //4

    /* optional cleanup function */
    MENUSTACK_CLEANUP   cleanup; //8
    FAPI_SYS_HandleT    cleanupArg; //12

    /* menu's general-purpose data */
    fbool_t             dataValid; //16
    uint32_t            data; //20
    //24
} MENUSTACK_ITEM_S;

typedef struct
{
    fbool_t             used; //0
    MENUSTACK_CLEANUP   cleanup; //4
    FAPI_SYS_HandleT    cleanupArg; //8
    //12
} MENUSTACK_EXTITEM_S;

typedef struct
{
    void (*lastMenuClosed) (void); //0
    void (*firstMenuToOpen)(void); //4
    
//    MENUSTACK_ENTRY     fallbackMenu;
//    FAPI_SYS_HandleT    fallbackMenuArg;
    
} MENUSTACK_INIT_S;

typedef struct
{
    MENUSTACK_INIT_S    pars; //0
    
    MENUSTACK_ITEM_S    menuStack[MENU_STACKITEMS_MAX]; //8
    uint16_t            menuStackLvl; //392
    fbool_t             menuStackForceExit; //396
    
    MENUSTACK_EXTITEM_S menuStackExt[MENU_EXTITEMS_MAX]; //
    uint16_t            numExt; //
    
    /* FGS panel focus handling */
    int32_t             focusClaimId;  //!< Panel ID claiming or having focus.
    int                 Data_504[24]; //
//    int16_t             focusForceId;  //!< Panel ID having focus by force.
    int16_t             Data_600;
    //604
} MENUSTACK_INST_S;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  MENUSTACK_Init         (MENUSTACK_INIT_S* initPars);
fbool_t  MENUSTACK_Up           (MENUSTACK_ENTRY newEntry,
                                 FAPI_SYS_HandleT arg);
fbool_t  MENUSTACK_Switch       (MENUSTACK_ENTRY newEntry,
                                 FAPI_SYS_HandleT arg,
                                 int16_t targetLevel);
fbool_t  MENUSTACK_Back         (FAPI_SYS_HandleT h);
fbool_t  MENUSTACK_Exit         (FAPI_SYS_HandleT h);
uint16_t MENUSTACK_GetLevel     (void);
fbool_t  MENUSTACK_GetData      (uint32_t* data);
void     MENUSTACK_SetData      (uint32_t data);
void     MENUSTACK_SetEntry     (MENUSTACK_ENTRY newEntry,
                                 FAPI_SYS_HandleT arg);
void     MENUSTACK_SetCleanup   (MENUSTACK_CLEANUP newCleanup,
                                 FAPI_SYS_HandleT arg);
void     MENUSTACK_SetForceMode (void);

int32_t  MENUSTACK_AddExt       (MENUSTACK_CLEANUP newCleanup,
                                 FAPI_SYS_HandleT arg);
int32_t  MENUSTACK_RemoveExt    (int32_t index);
fbool_t  MENUSTACK_CloseAllExt  (fbool_t force);

int32_t  MENUSTACK_FocusClaim   (int32_t id);
int32_t  MENUSTACK_FocusRelease (int32_t id);
int32_t  MENUSTACK_FocusForce   (int32_t id);

#ifdef __cplusplus
}
#endif

#endif /* _MENUSTACK_H_ */
/******************************************************************************/
/* END OF FILE */
