/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/inc/app_lang.h
**
** \brief       OSD language handling.
**
** In this file are all string ID's defined. To add a new string you have to add
** the string ID first. The string it self is place in
** /app_ref/res/all_language.xls, this file contains all strings for all
** languages. The first collumn contains the String ID defined here.
** (The ID-Name MUST be identical and case sensitv). The next collumns contains
** the string in different languages. The first cell of each collumn defines the
** language file name.
**
** Detail description. [\ref app_smartgo_app_ref_language]
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
#ifndef _APP_LANG_H_
#define _APP_LANG_H_

#include "sys_api.h"


/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
#define OSDLANG_MAX          8/*10*/       // max. number of languages
#if 0
#define OSDLANG_NAME_LEN     32       // max. length of language name string

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/
/*!
 * \brief Number of "known" languages, subset of all languages
 */
#define KNOWN_LANG_NUMS           (((uint32_t)STR_LANG_LAST) - ((uint32_t)STR_LANG_OTHER))

#ifdef LANG_LOADFROMFLASH
typedef struct
{
    uint32_t      id;                          // file identification
    uint32_t      revision;                    // file structure revision
    SYS_LANGCODE  langId;                      // language identifier
    char_t        langName[OSDLANG_NAME_LEN];  // language name string

} OSDLANG_FILEHDR;
#endif

#endif

typedef struct
{
    int32_t   idx;
    char_t*   str;

} OSDLANG_ENTRY_S;


typedef struct
{
    SYS_LANGCODE       idx;
    OSDLANG_ENTRY_S*   str;

} OSDLANG_LANG_S;


#include "lng.h"

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#if 0

int32_t         OSD_LANG_Init                    (void);
uint32_t        OSD_LANG_GetNumberOfLangs        (void);
int32_t         OSD_LANG_GetLangInfo             (uint32_t langIdx, SYS_LANGCODE* id);
uint32_t        OSD_LANG_GetLangCurr             (void);
#endif
int32_t         OSD_LANG_Select                  (uint32_t langIdx);
#if 0
SYS_STRING_S    OSD_LANG_GetLanguageString       (SYS_LANGCODE langCode);
SYS_LANGCODE    OSD_LANG_GetKnownLangCodeByIndex (uint16_t index);
uint16_t        OSD_LANG_GetKnownLangIndex       (SYS_LANGCODE langCode);
#endif
SYS_STRING_S    OSD_GetStr                       (uint32_t strIdx);
#if 0
SYS_STRING_S    OSD_GetWeekDayStr                (SYS_TIME_WEEKDAY_E dayOfWeek);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _APP_LANG_H_ */
/******************************************************************************/
/* END OF FILE */
