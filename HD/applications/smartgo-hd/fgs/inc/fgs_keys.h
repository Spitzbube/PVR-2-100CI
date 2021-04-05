/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs_keys.h
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
#ifndef _FGS_KEYS_H_
#define _FGS_KEYS_H_


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef enum
{
    FGS_KEY_NONE = 0,
    FGS_KEY_UP = 1, //1
    FGS_KEY_DOWN = 2, //2
    FGS_KEY_LEFT = 3, //3
    FGS_KEY_RIGHT = 4, //4
    FGS_KEY_NUMBER = 5, //5
    FGS_KEY_OK = 6, //6
    FGS_KEY_BACK = 7, //7
    FGS_KEY_CHAN_UP = 8, //8
    FGS_KEY_CHAN_DOWN,
    FGS_KEY_RED,
    FGS_KEY_GREEN,
    FGS_KEY_YELLOW,
    FGS_KEY_BLUE,
    FGS_KEY_STANDBY,
    FGS_KEY_EXIT = 15, //15
    FGS_KEY_TEXT,
    FGS_KEY_APPL,
    FGS_KEY_MENU = 18, //18
    FGS_KEY_HIDE,
    FGS_KEY_NAVI,
    FGS_KEY_TV,
    FGS_KEY_INFO,
    FGS_KEY_MUTE = 23, //23
    FGS_KEY_VOL_UP = 24, //24
    FGS_KEY_VOL_DOWN = 25, //25
    FGS_KEY_RECORD = 26, //26
    FGS_KEY_PLAY,
    FGS_KEY_STOP,
    FGS_KEY_FF,
    FGS_KEY_REW,
    FGS_KEY_PAUSE,
    /* -------------*/
    FGS_KEY_PIP,
    FGS_KEY_PIPCHANNEL,
    FGS_KEY_PIPEXCHGMAIN,
    FGS_KEY_PIPPOSITION,
    FGS_KEY_REWSLOW,
    FGS_KEY_PVR,
    FGS_KEY_FFSLOW,
    FGS_KEY_SAT,
    FGS_KEY_HELP,
    FGS_KEY_RECALL,
    FGS_KEY_BLOCK,
    FGS_KEY_PAGEUP,
    FGS_KEY_CUT,
    FGS_KEY_BOOKMARK,
    FGS_KEY_JUMPMARK,
    FGS_KEY_PAGEDOWN,
    FGS_KEY_ZOOM,
    FGS_KEY_FAV,
    FGS_KEY_ASPECTRATIO,
    FGS_KEY_F1 = 51, //51
    FGS_KEY_F2,
    FGS_KEY_F3,
    FGS_KEY_F4,
    FGS_KEY_NUMS = 67               //!< number of managed keys
    
} FGS_KEY_E;

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#endif /* _FGS_KEYS_H_ */
/******************************************************************************/
/* END OF FILE */
