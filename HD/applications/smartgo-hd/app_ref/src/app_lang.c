/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/src/app_lang.c
**
** \brief       OSD language management.
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
**
** \note The following LINT statements have been suppressed:
**
** - Warning 641: Converting enum 'abc' to int.
** - Note    961: Violates MISRA 2004 Advisory Rule 19.1, only preprocessor
**                statements and comments before include
*****************************************************************************
*/
/*lint -save -e641 -e961 */

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "app_main.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

// will not be supported by SmartGo-HD
//#define LANG_LOADFROMFLASH

/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

typedef struct
{
    fbool_t         available;      //!< The stored language is available.
    SYS_LANGCODE    id;             //!< ISO language ID.

    #ifdef LANG_LOADFROMFLASH

    uint32_t       fileId;          //!< Resource fileId.
    uint32_t       size;            //!< Size of data area in bytes.

    #else

    OSDLANG_ENTRY_S* pStr;          //!< Pointer to string table.

    #endif /* LANG_LOADFROMFLASH */

} OSD_LANG_S;

typedef struct
{
    char_t**        strDef;                //!< String table for default language.
    char_t**        strCurr; /*4*/              //!< String table for current language.

    #ifdef LANG_LOADFROMFLASH
    uint8_t*        strBuf;             //!< Buffer holding current language string.
    #endif /* LANG_LOADFROMFLASH */

    OSD_LANG_S      langAvl[OSDLANG_MAX];
    uint32_t        langNums; /*104*/      //!< Total number of languages available.
    uint32_t        langCurr; /*108*/      //!< Current language index.
    uint32_t        langDef; /*112*/       //!< Index of default language.

} LANGUAGE_DATA_S;

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

/*!
 * \brief Main storage structure of the SmartGo-HD language moduel.
 *
 * This storage module is allocated in OSD_LANG_Init().
 *
 */
LANGUAGE_DATA_S *langDat = NULL; //21f02438

/*!
 * \brief This dummy string is used if no string is found eighter in the
 *        selected OSD language or in the default language.
 */
char_t dummyStr[] = "";

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

#ifndef LANG_LOADFROMFLASH

/*FSTATIC*/ fbool_t OSD_LANG_Add           (SYS_LANGCODE id, OSDLANG_ENTRY_S* pStr);
FSTATIC void    OSD_LANG_LoadFromArray (OSDLANG_ENTRY_S* pStr, char_t** strTable);

#endif /* LANG_LOADFROMFLASH */

/*!
*******************************************************************************
**
** \brief   This function initialze the SmartGo-HD OSD language module.
**
** \note    The option to load languages form flash is not implemented.
**
** \return  One of the following status codes:
**          - #FAPI_OK
**          - #APPL_SMARTGO_ERR_ALREADY_INITIALIZED
**          - #APPL_SMARTGO_ERR_OUT_OF_MEMORY
**          - return codes form OSD_LANG_Select()
**          - return codes form SETTINGS_OsdLangGet()
******************************************************************************/
/* 21b14c50 - todo */
int32_t OSD_LANG_Init (void)
{
    int32_t             retVal;

    #ifdef LANG_LOADFROMFLASH
    FLASHFS_HANDLE      file = NULL;
    FLASHFS_FILE_InfoT  fileInfo;
    uint32_t            fileId;
    uint32_t            fileRev;
    OSDLANG_FILEHDR     fileHdr;
    OSDLANG_ENTRY_S*    pString;
    #endif /* LANG_LOADFROMFLASH */

    uint16_t            cnt = 0;
    SYS_LANGCODE        langStored;

    if(langDat != NULL)
    {
        return APPL_SMARTGO_ERR_ALREADY_INITIALIZED;
    }

    langDat = SYS_MemoryAllocate(sizeof(LANGUAGE_DATA_S));
    if(langDat == NULL)
    {
        return APPL_SMARTGO_ERR_OUT_OF_MEMORY;
    }

    memset(langDat, 0, sizeof(LANGUAGE_DATA_S));

    #ifdef LANG_LOADFROMFLASH
    langDat->strBuf = NULL;
    #endif /* LANG_LOADFROMFLASH */

    langDat->langNums = 0;
    langDat->langCurr = 0;
    langDat->langDef  = 0;  /* first language is default language */

    /* allocate and clear memory for current and default lang strings */
    langDat->strCurr = (char_t**)SYS_MemoryAllocate(sizeof(char_t*) * STR_NUMS);
    if ( langDat->strCurr == NULL )
    {
        return APPL_SMARTGO_ERR_OUT_OF_MEMORY;
    }

    langDat->strDef  = (char_t**)SYS_MemoryAllocate(sizeof(char_t*) * STR_NUMS);
    if ( langDat->strDef == NULL )
    {
        return APPL_SMARTGO_ERR_OUT_OF_MEMORY;
    }

    memset(langDat->strCurr, 0, sizeof(char_t*) * STR_NUMS);
    memset(langDat->strDef, 0, sizeof(char_t*) * STR_NUMS);

    for ( cnt = 0; cnt < OSDLANG_MAX; cnt++ )
    {
        langDat->langAvl[cnt].available = FFALSE;
    }

    #ifdef LANG_LOADFROMFLASH
    /* ----- add default language to language pool ------------------------- */
    pString = &(osdDefStr[0]);

    while ( pString->idx >= 0 )
    {
        if ( pString->idx < STR_NUMS )
        {
            langDat->strDef[pString->idx] = pString->str;
        }

        pString++;
    }

    langDat->langAvl[langDat->langNums].available   = FTRUE;
    langDat->langAvl[langDat->langNums].id          = LANG_ENGLISH;
    langDat->langAvl[langDat->langNums].size        = 0;
    langDat->langAvl[langDat->langNums].fileId      = 0;

    langDat->langNums++;

    /* ----- scan for available languages ---------------------------------- */

    fileId  = FILEID_LANGUAGE_0;
    fileRev = FILEREV_LANGUAGE_0;
    while(langDat->langNums < OSDLANG_MAX)
    {
        file = FLASHFS_Open(fileId, FLASHFS_OPEN_READ, NULL);
        if ( file == NULL )
        {
            FAPI_SYS_PRINT_DEBUG(2,"Lang file opening failed!\n");
        }
        /* ----- read file header ------------------------------------------ */
        if(FLASHFS_Read (file, sizeof(OSDLANG_FILEHDR), &fileHdr, NULL)
            != sizeof(OSDLANG_FILEHDR) )
        {
        //    break;              /* file read error, file too small */
        }
        else if((fileHdr.id       != fileId) ||
                (fileHdr.revision != fileRev))
        {
            langDat->langAvl[langDat->langNums].available = FTRUE;
            langDat->langAvl[langDat->langNums].id   = fileHdr.langId;
            FLASHFS_GetInfo(file, &fileInfo);
            langDat->langAvl[langDat->langNums].size = fileInfo.size -
                                                       sizeof(OSDLANG_FILEHDR);

            langDat->langAvl[langDat->langNums].fileId = fileId;

            langDat->langNums++;
        }
        if ( file != NULL )
        {
            FLASHFS_Close(file);
        }
    }
    #else

    /* ----- add all available languages to pool --------------------------- */

#if 0
    for(cnt=0;lng_str[cnt].str != NULL;cnt++)
    {
        if(OSD_LANG_Add(lng_str[cnt].idx, lng_str[cnt].str) == FFALSE)
        {
            break;
        }
    }
#else
    OSD_LANG_Add(LANG_ENGLISH, lng_english_str);
    OSD_LANG_Add(LANG_FRENCH, lng_french_str);
    OSD_LANG_Add(LANG_GERMAN, lng_german_str);
    OSD_LANG_Add(LANG_TURKISH, lng_turkish_str);
    OSD_LANG_Add(LANG_ITALIAN, lng_italian_str);
    OSD_LANG_Add(LANG_CZECH, lng_czech_str);
    OSD_LANG_Add(LANG_SWEDISH, lng_swedish_str);
    OSD_LANG_Add(LANG_SPANISH, lng_spanish_str);
#endif

    /* default language */
    OSD_LANG_LoadFromArray (/*lng_str[0].str*/lng_english_str, langDat->strDef); /* load default language */

    #endif /* LANG_LOADFROMFLASH */

    /* ----- choose initial language --------------------------------------- */

    retVal = SETTINGS_OsdLangGet(&langStored);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    /* test if stored language is available */
#if 1
    for ( cnt = 0; cnt < OSDLANG_MAX; cnt++ )
#else
    cnt = 0;
    while (1)
#endif
    {
#if 1
        if ( langDat->langAvl[cnt].available == FFALSE )
        {
            continue;
        }
        if ( langDat->langAvl[cnt].id == langStored )
        {
            break;
        }
#else
        if ( langDat->langAvl[cnt].available &&
                ( langDat->langAvl[cnt].id == langStored ))
        {
            break;
        }

        cnt++;
        if ( cnt >= OSDLANG_MAX )
        {
            cnt = langDat->langDef;
            break;
        }
#endif
    }

#if 1
    /* language ID has not been found: set default langauge */
    if ( cnt >= OSDLANG_MAX )
    {
        cnt = langDat->langDef;
    }
#endif

    return OSD_LANG_Select(cnt);
}


/* 21b12864 - complete */
uint32_t OSD_LANG_GetNumberOfLangs (void)
{
#if 0
    if( langDat == NULL )
    {
        return 0;
    }
#endif
    return langDat->langNums;
}


/* 21b12878 - complete */
uint32_t OSD_LANG_GetLangCurr (void)
{
#if 0
    if( langDat == NULL )
    {
        return 0;
    }
#endif
    return langDat->langCurr;
}


/* 21b1288c - complete */
int32_t OSD_LANG_GetLangInfo (uint32_t langIdx, SYS_LANGCODE* id)
{
    if ( langIdx >= langDat->langNums )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }
    if ( id   != NULL )
    {
        (*id) = langDat->langAvl[langIdx].id;
    }

    return FAPI_OK;
}

#ifdef LANG_LOADFROMFLASH

int32_t OSD_LANG_Select (uint32_t langIdx)
{
    uint8_t*            newBuf = NULL;
    uint32_t            fileId;
    FLASHFS_HANDLE      file = NULL;
    uint32_t            bufSize;
    uint32_t            bufPos;
    uint32_t            idx;
    fbool_t             endDetected;

    if ( langIdx >= langDat->langNums ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    /* default language requested? */
    if ( langIdx == langDat->langDef )
    {
        memcpy(langDat->strCurr, langDat->strDef, sizeof(char_t*) * STR_NUMS);

        /* release current string memory */
        if ( langDat->strBuf != NULL )
        {
            FAPI_SYS_FREE(langDat->strBuf);
            langDat->strBuf = NULL;
        }
    }
    /* load language string from file */
    else
    {
        newBuf = (uint8_t*)UTILS_Malloc(langDat->langAvl[langIdx].size);
        if ( newBuf == NULL )
        {
            FAPI_SYS_PRINT_DEBUG(2,"Language memory allocation failed!\n");
            return APPL_SMARTGO_ERR_OUT_OF_MEMORY;
        }

        fileId = langDat->langAvl[langIdx].fileId;

        /* load data from file */
        file = FLASHFS_Open(fileId, FLASHFS_OPEN_READ,NULL);
        if ( file == NULL )
        {
            FAPI_SYS_PRINT_DEBUG(2,"Language file opening failed!\n");
            FAPI_SYS_FREE(newBuf);
            return APPL_SMARTGO_ERR_BAD_PARAMETER; /* error code to be changed */
        }

        /* set position to start of data area */
        FLASHFS_Seek(file,sizeof(OSDLANG_FILEHDR),SEEK_SET);

        bufSize = langDat->langAvl[langIdx].size;

        if ( FLASHFS_Read (file, bufSize, newBuf, NULL) != bufSize )
        {
            FAPI_SYS_PRINT_DEBUG(2,"Language file reading failed!\n");

            FAPI_SYS_FREE(newBuf);
            FLASHFS_Close(file);
            return APPL_SMARTGO_ERR_BAD_PARAMETER; /* error code to be changed */
        }
        FLASHFS_Close(file);

        /* release current string memory */
        if ( langDat->strBuf != NULL )
        {
            FAPI_SYS_FREE(langDat->strBuf);
        }

        langDat->strBuf = newBuf;

        /* clear pointer array */
        memset(langDat->strCurr, 0, sizeof(char_t*) * STR_NUMS);

        /* parse strings in buffer */
        bufPos      = 0;
        endDetected = FTRUE;

        while ( (bufPos + 5) <= bufSize ) // 4 bytes ID + 1 byte string required
        {
            if ( endDetected == FTRUE )
            {
                endDetected = FFALSE;

                idx =        newBuf[bufPos]              |
                      (((uint32_t)newBuf[bufPos + 1]) <<  8)  |
                      (((uint32_t)newBuf[bufPos + 2]) << 16)  |
                      (((uint32_t)newBuf[bufPos + 3]) << 24);

                if ( idx < STR_NUMS )
                {
                    langDat->strCurr[idx] = (char_t*)(newBuf + bufPos + 4);
                }

                bufPos += 4;
            }
            else
            {
                if ( newBuf[bufPos] == 0 )
                {
                    endDetected = FTRUE;
                }

                bufPos++;
            }
        }
    }

    langDat->langCurr = langIdx;

    /* store language setting */
    (void)SETTINGS_OsdLangSet (langDat->langAvl[langIdx].id);

    return FAPI_OK;
}

#else

/* 21b14b88 - complete */
int32_t OSD_LANG_Select (uint32_t langIdx)
{
    if ( langIdx >= langDat->langNums )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    /* default language requested? */
    if ( langIdx == langDat->langDef )
    {
        memcpy(langDat->strCurr, langDat->strDef, sizeof(char_t*) * STR_NUMS);
    }
    else
    {
        /* load language strings */
        OSD_LANG_LoadFromArray(langDat->langAvl[langIdx].pStr, langDat->strCurr);
    }

    langDat->langCurr = langIdx;

    /* store language setting */
    (void)SETTINGS_OsdLangSet (langDat->langAvl[langIdx].id);

    /* handle special strings */
   (void)SLIST_ListNameSet(/*SLIST_TV*/0x100, OSD_GetStr(STR_ENTRY_SERVLIST_GLOBTV));
   (void)SLIST_ListNameSet(/*SLIST_RADIO*/0x101, OSD_GetStr(STR_ENTRY_SERVLIST_GLOBRADIO));

#if 0
   /* handle time and date formats */
   switch(langDat->langAvl[langIdx].id)
   {
       default:
       case LANG_ENGLISH:
           appDat->timeFormat      = FGS_FORMAT_TIME_DAYTIME;
           appDat->dataFormatNorm  = FGS_FORMAT_DATE_INT_NORM;
           appDat->dataFormatShort = FGS_FORMAT_DATE_INT_SHORT;
           break;
       case LANG_FRENCH:
       case LANG_GERMAN:
           appDat->timeFormat      = FGS_FORMAT_TIME_DAYTIME;
           appDat->dataFormatNorm  = FGS_FORMAT_DATE_EUROPE_NORM;
           appDat->dataFormatShort = FGS_FORMAT_DATE_EUROPE_SHORT;
           break;
   }
#endif
    return FAPI_OK;
}

#endif /* LANG_LOADFROMFLASH */


/* 21b128d8 - complete */
SYS_STRING_S OSD_GetStr (uint32_t strIdx)
{
    SYS_STRING_S str;

//    memset(&str,0,sizeof(SYS_STRING_S));

    str.cs = SYS_CHARSET_UTF8;

    if(langDat == NULL)
    {
        str.chr = dummyStr;
        return str;
    }
    /* valid index? */
    if ( strIdx >= STR_NUMS )
    {
        str.chr = dummyStr;
    }
    /* defined in current OSD language */
    else if ( langDat->strCurr[strIdx] != NULL )
    {
        str.chr = langDat->strCurr[strIdx];
    }
    /* MUST be defined in default OSD language */
    else
    {
        str.chr = langDat->strDef[strIdx];
    }

    return str;
}

SYS_STRING_S OSD_GetWeekDayStr (SYS_TIME_WEEKDAY_E dayOfWeek)
{
    uint32_t dayId;

    switch ( dayOfWeek )
    {
        default:
        case SYS_TIME_WEEKDAY_MONDAY:    dayId = STR_GNR_MONDAY;    break;
        case SYS_TIME_WEEKDAY_TUESDAY:   dayId = STR_GNR_TUESDAY;   break;
        case SYS_TIME_WEEKDAY_WEDNESDAY: dayId = STR_GNR_WEDNESDAY; break;
        case SYS_TIME_WEEKDAY_THURSDAY:  dayId = STR_GNR_THURSDAY;  break;
        case SYS_TIME_WEEKDAY_FRIDAY:    dayId = STR_GNR_FRIDAY;    break;
        case SYS_TIME_WEEKDAY_SATURDAY:  dayId = STR_GNR_SATURDAY;  break;
        case SYS_TIME_WEEKDAY_SUNDAY:    dayId = STR_GNR_SUNDAY;    break;
    }

    return OSD_GetStr(dayId);
}
#ifndef LANG_LOADFROMFLASH

/* 21b1293c - complete */
/*FSTATIC*/ fbool_t OSD_LANG_Add (SYS_LANGCODE id, OSDLANG_ENTRY_S* pStr)
{
    if ( langDat->langNums >= OSDLANG_MAX )
    {
        return FFALSE;
    }

    langDat->langAvl[langDat->langNums].available = FTRUE;
    langDat->langAvl[langDat->langNums].id        = id;
    langDat->langAvl[langDat->langNums].pStr      = pStr;

    langDat->langNums++;
    return FTRUE;
}

/* 21b14b34 - complete */
FSTATIC void OSD_LANG_LoadFromArray (OSDLANG_ENTRY_S* pStr, char_t** strTable)
{
    memset(strTable, 0, sizeof(char_t*) * STR_NUMS);

    while ( pStr->idx >= 0 )
    {
        if ( pStr->idx < STR_NUMS )
        {
            strTable[pStr->idx] = pStr->str;
        }

        pStr++;
    }
}

#endif /* LANG_LOADFROMFLASH */


/* 21b12994 - todo */
SYS_STRING_S OSD_LANG_GetLanguageString(SYS_LANGCODE langCode)
{
    uint32_t index;

    switch ( langCode )
    {
        default                     : index = STR_LANG_OTHER       ; break;
        case LANG_ALBANIAN          : index = STR_LANG_ALBANIAN    ; break;
        case LANG_BULGARIAN         : index = STR_LANG_BULGARIAN   ; break;
        case LANG_CZECH             : index = STR_LANG_CZECH       ; break;
        case LANG_WELSH             : index = STR_LANG_WELSH       ; break;
        case LANG_DANISH            : index = STR_LANG_DANISH      ; break;
        case LANG_DUTCH             : index = STR_LANG_DUTCH       ; break;
        case LANG_ENGLISH           : index = STR_LANG_ENGLISH     ; break;
        case LANG_ESTONIAN          : index = STR_LANG_ESTONIAN    ; break;
        case LANG_FRENCH            : index = STR_LANG_FRENCH      ; break;
        case LANG_GERMAN            : index = STR_LANG_GERMAN      ; break;
        case LANG_ICELANDIC         : index = STR_LANG_ICELANDIC   ; break;
        case LANG_ITALIAN           : index = STR_LANG_ITALIAN     ; break;
        case LANG_SPANISH           : index = STR_LANG_SPANISH     ; break;
        case LANG_GREEK             : index = STR_LANG_GREEK       ; break;
        case LANG_FINNISH           : index = STR_LANG_FINNISH     ; break;
        case LANG_IRISH             : index = STR_LANG_IRISH       ; break;
        case LANG_CROATIAN          : index = STR_LANG_CROATIAN    ; break;
        case LANG_HUNGARIAN         : index = STR_LANG_HUNGARIAN   ; break;
        case LANG_KOREAN            : index = STR_LANG_KOREAN      ; break;
        case LANG_LATVIAN_LETTISH   : index = STR_LANG_LETTISH     ; break;
        case LANG_NORWEGIAN         : index = STR_LANG_NORWEGIAN   ; break;
        case LANG_POLISH            : index = STR_LANG_POLISH      ; break;
        case LANG_PORTUGUESE        : index = STR_LANG_PORTUGUESE  ; break;
        case LANG_ROMANIAN          : index = STR_LANG_ROMANIAN    ; break;
        case LANG_RUSSIAN           : index = STR_LANG_RUSSIAN     ; break;
        case LANG_SLOVAK            : index = STR_LANG_SLOVAK      ; break;
        case LANG_SERBIAN           : index = STR_LANG_SERBIAN     ; break;
        case LANG_SWEDISH           : index = STR_LANG_SWEDISH     ; break;
        case LANG_TURKISH           : index = STR_LANG_TURKISH     ; break;
        case LANG_CHINESE           : index = STR_LANG_CHINESE     ; break;
        case LANG_ARABIC            : index = STR_LANG_ARABIC      ; break;
        case LANG_BRETON            : index = STR_LANG_BRETON      ; break;
        case LANG_CATALAN           : index = STR_LANG_CATALAN     ; break;
        case LANG_CORSICAN          : index = STR_LANG_CORSICAN    ; break;
        case LANG_BASQUE            : index = STR_LANG_BASQUE      ; break;
        case LANG_PERSIAN           : index = STR_LANG_PERSIAN     ; break;
        case LANG_FAROESE           : index = STR_LANG_FAROESE     ; break;
        case LANG_SCOTS_GAELIC      : index = STR_LANG_SCOTS_GAELIC; break;
        case LANG_GALICIAN          : index = STR_LANG_GALICIAN    ; break;
        case LANG_HEBREW            : index = STR_LANG_HEBREW      ; break;
        case LANG_JAPANESE          : index = STR_LANG_JAPANESE    ; break;
        case LANG_YIDDISH           : index = STR_LANG_YIDDISH     ; break;
        case LANG_GREENLANDIC       : index = STR_LANG_GREENLANDIC ; break;
        case LANG_KANNADA           : index = STR_LANG_KANNADA     ; break;
        case LANG_LITHUANIAN        : index = STR_LANG_LITHUANIAN  ; break;
        case LANG_MACEDONIAN        : index = STR_LANG_MACEDONIAN  ; break;
        case LANG_MOLDAVIAN         : index = STR_LANG_MOLDAVIAN   ; break;
        case LANG_MALTESE           : index = STR_LANG_MALTESE     ; break;
        case LANG_SLOVENIAN         : index = STR_LANG_SLOVENIAN   ; break;
        case LANG_UKRAINIAN         : index = STR_LANG_UKRAINIAN   ; break;
        case LANG_AFAR              : index = STR_LANG_AFAR        ; break;
        case LANG_ABKHAZIAN         : index = STR_LANG_ABKHAZIAN   ; break;
        case LANG_AFRIKAANS         : index = STR_LANG_AFRIKAANS   ; break;
        case LANG_AMHARIC           : index = STR_LANG_AMHARIC     ; break;
        case LANG_ASSAMESE          : index = STR_LANG_ASSAMESE    ; break;
        case LANG_AYMARA            : index = STR_LANG_AYMARA      ; break;
        case LANG_AZERBAIJANI       : index = STR_LANG_AZERBAIJANI ; break;
        case LANG_BASHKIR           : index = STR_LANG_BASHKIR     ; break;
        case LANG_BYELORUSSIAN      : index = STR_LANG_BYELORUSSIAN; break;
        case LANG_BIHARI            : index = STR_LANG_BIHARI      ; break;
        case LANG_BISLAMA           : index = STR_LANG_BISLAMA     ; break;
        case LANG_BENGALI           : index = STR_LANG_BENGALI     ; break;
        case LANG_TIBETAN           : index = STR_LANG_TIBETAN     ; break;
        case LANG_ESPERANTO         : index = STR_LANG_ESPERANTO   ; break;
        case LANG_FIJI              : index = STR_LANG_FIJI        ; break;
        case LANG_FRISIAN           : index = STR_LANG_FRISIAN     ; break;
        case LANG_GUARANI           : index = STR_LANG_GUARANI     ; break;
        case LANG_GUJARATI          : index = STR_LANG_GUJARATI    ; break;
        case LANG_HAUSA             : index = STR_LANG_HAUSA       ; break;
        case LANG_HINDI             : index = STR_LANG_HINDI       ; break;
        case LANG_ARMENIAN          : index = STR_LANG_ARMENIAN    ; break;
        case LANG_INTERLINGUA       : index = STR_LANG_INTERLINGUA ; break;
        case LANG_INTERLINGUE       : index = STR_LANG_INTERLINGUE ; break;
        case LANG_INUPIAK           : index = STR_LANG_INUPIAK     ; break;
        case LANG_INDONESIAN        : index = STR_LANG_INDONESIAN  ; break;
        case LANG_JAVANESE          : index = STR_LANG_JAVANESE    ; break;
        case LANG_GEORGIAN          : index = STR_LANG_GEORGIAN    ; break;
        case LANG_KAZAKH            : index = STR_LANG_KAZAKH      ; break;
        case LANG_CAMBODIAN         : index = STR_LANG_CAMBODIAN   ; break;
        case LANG_KASHMIRI          : index = STR_LANG_KASHMIRI    ; break;
        case LANG_KURDISH           : index = STR_LANG_KURDISH     ; break;
        case LANG_KIRGHIZ           : index = STR_LANG_KIRGHIZ     ; break;
        case LANG_LATIN             : index = STR_LANG_LATIN       ; break;
        case LANG_LINGALA           : index = STR_LANG_LINGALA     ; break;
        case LANG_LAOTHIAN          : index = STR_LANG_LAOTHIAN    ; break;
        case LANG_MALAGASY          : index = STR_LANG_MALAGASY    ; break;
        case LANG_MAORI             : index = STR_LANG_MAORI       ; break;
        case LANG_MALAYALAM         : index = STR_LANG_MALAYALAM   ; break;
        case LANG_MONGOLIAN         : index = STR_LANG_MONGOLIAN   ; break;
        case LANG_MARATHI           : index = STR_LANG_MARATHI     ; break;
        case LANG_MALAY             : index = STR_LANG_MALAY       ; break;
        case LANG_BURMESE           : index = STR_LANG_BURMESE     ; break;
        case LANG_NAURU             : index = STR_LANG_NAURU       ; break;
        case LANG_NEPALI            : index = STR_LANG_NEPALI      ; break;
        case LANG_OCCITAN           : index = STR_LANG_OCCITAN     ; break;
        case LANG_AFAN_OROMO        : index = STR_LANG_AFAN_OROMO  ; break;
        case LANG_ORIYA             : index = STR_LANG_ORIYA       ; break;
        case LANG_PUNJABI           : index = STR_LANG_PUNJABI     ; break;
        case LANG_PASHTO            : index = STR_LANG_PASHTO      ; break;
        case LANG_QUECHUA           : index = STR_LANG_QUECHUA     ; break;
        case LANG_RHAETO_ROMANCE    : index = STR_LANG_RHAETO_ROMANCE; break;
        case LANG_KURUNDI           : index = STR_LANG_KURUNDI     ; break;
        case LANG_KINYARWANDA       : index = STR_LANG_KINYARWANDA ; break;
        case LANG_SANSKRIT          : index = STR_LANG_SANSKRIT    ; break;
        case LANG_SINDHI            : index = STR_LANG_SINDHI      ; break;
        case LANG_SANGHO            : index = STR_LANG_SANGHO      ; break;
        case LANG_SINGHALESE        : index = STR_LANG_SINGHALESE  ; break;
        case LANG_SAMOAN            : index = STR_LANG_SAMOAN      ; break;
        case LANG_SHONA             : index = STR_LANG_SHONA       ; break;
        case LANG_SOMALI            : index = STR_LANG_SOMALI      ; break;
        case LANG_SISWATI           : index = STR_LANG_SISWATI     ; break;
        case LANG_SESOTHO           : index = STR_LANG_SESOTHO     ; break;
        case LANG_SUNDANESE         : index = STR_LANG_SUNDANESE   ; break;
        case LANG_SWAHILI           : index = STR_LANG_SWAHILI     ; break;
        case LANG_TAMIL             : index = STR_LANG_TAMIL       ; break;
        case LANG_TELUGU            : index = STR_LANG_TELUGU      ; break;
        case LANG_TAJIK             : index = STR_LANG_TAJIK       ; break;
        case LANG_THAI              : index = STR_LANG_THAI        ; break;
        case LANG_TIGRINYA          : index = STR_LANG_TIGRINYA    ; break;
        case LANG_TURKMEN           : index = STR_LANG_TURKMEN     ; break;
        case LANG_TAGALOG           : index = STR_LANG_TAGALOG     ; break;
        case LANG_SETSWANA          : index = STR_LANG_SETSWANA    ; break;
        case LANG_TONGA             : index = STR_LANG_TONGA       ; break;
        case LANG_TSONGA            : index = STR_LANG_TSONGA      ; break;
        case LANG_TATAR             : index = STR_LANG_TATAR       ; break;
        case LANG_TWI               : index = STR_LANG_TWI         ; break;
        case LANG_URDU              : index = STR_LANG_URDU        ; break;
        case LANG_UZBEK             : index = STR_LANG_UZBEK       ; break;
        case LANG_VIETNAMESE        : index = STR_LANG_VIETNAMESE  ; break;
        case LANG_VOLAPUK           : index = STR_LANG_VOLAPUK     ; break;
        case LANG_WOLOF             : index = STR_LANG_WOLOF       ; break;
        case LANG_XHOSA             : index = STR_LANG_XHOSA       ; break;
        case LANG_YORUBA            : index = STR_LANG_YORUBA      ; break;
        case LANG_ZULU              : index = STR_LANG_ZULU        ; break;
        case LANG_NONE              : index = STR_LANG_NONE        ; break;
    }

    return OSD_GetStr(index);
}


/* 21b136f0 - todo */
uint16_t OSD_LANG_GetKnownLangIndex (SYS_LANGCODE langCode)
{
    uint32_t index;

    switch ( langCode )
    {
        default                     : index = STR_LANG_OTHER       ; break;
        case LANG_ALBANIAN          : index = STR_LANG_ALBANIAN    ; break;
        case LANG_BULGARIAN         : index = STR_LANG_BULGARIAN   ; break;
        case LANG_CZECH             : index = STR_LANG_CZECH       ; break;
        case LANG_WELSH             : index = STR_LANG_WELSH       ; break;
        case LANG_DANISH            : index = STR_LANG_DANISH      ; break;
        case LANG_DUTCH             : index = STR_LANG_DUTCH       ; break;
        case LANG_ENGLISH           : index = STR_LANG_ENGLISH     ; break;
        case LANG_ESTONIAN          : index = STR_LANG_ESTONIAN    ; break;
        case LANG_FRENCH            : index = STR_LANG_FRENCH      ; break;
        case LANG_GERMAN            : index = STR_LANG_GERMAN      ; break;
        case LANG_ICELANDIC         : index = STR_LANG_ICELANDIC   ; break;
        case LANG_ITALIAN           : index = STR_LANG_ITALIAN     ; break;
        case LANG_SPANISH           : index = STR_LANG_SPANISH     ; break;
        case LANG_GREEK             : index = STR_LANG_GREEK       ; break;
        case LANG_FINNISH           : index = STR_LANG_FINNISH     ; break;
        case LANG_IRISH             : index = STR_LANG_IRISH       ; break;
        case LANG_CROATIAN          : index = STR_LANG_CROATIAN    ; break;
        case LANG_HUNGARIAN         : index = STR_LANG_HUNGARIAN   ; break;
        case LANG_KOREAN            : index = STR_LANG_KOREAN      ; break;
        case LANG_LATVIAN_LETTISH   : index = STR_LANG_LETTISH     ; break;
        case LANG_NORWEGIAN         : index = STR_LANG_NORWEGIAN   ; break;
        case LANG_POLISH            : index = STR_LANG_POLISH      ; break;
        case LANG_PORTUGUESE        : index = STR_LANG_PORTUGUESE  ; break;
        case LANG_ROMANIAN          : index = STR_LANG_ROMANIAN    ; break;
        case LANG_RUSSIAN           : index = STR_LANG_RUSSIAN     ; break;
        case LANG_SLOVAK            : index = STR_LANG_SLOVAK      ; break;
        case LANG_SERBIAN           : index = STR_LANG_SERBIAN     ; break;
        case LANG_SWEDISH           : index = STR_LANG_SWEDISH     ; break;
        case LANG_TURKISH           : index = STR_LANG_TURKISH     ; break;
        case LANG_CHINESE           : index = STR_LANG_CHINESE     ; break;
        case LANG_ARABIC            : index = STR_LANG_ARABIC      ; break;
        case LANG_BRETON            : index = STR_LANG_BRETON      ; break;
        case LANG_CATALAN           : index = STR_LANG_CATALAN     ; break;
        case LANG_CORSICAN          : index = STR_LANG_CORSICAN    ; break;
        case LANG_BASQUE            : index = STR_LANG_BASQUE      ; break;
        case LANG_PERSIAN           : index = STR_LANG_PERSIAN     ; break;
        case LANG_FAROESE           : index = STR_LANG_FAROESE     ; break;
        case LANG_SCOTS_GAELIC      : index = STR_LANG_SCOTS_GAELIC; break;
        case LANG_GALICIAN          : index = STR_LANG_GALICIAN    ; break;
        case LANG_HEBREW            : index = STR_LANG_HEBREW      ; break;
        case LANG_JAPANESE          : index = STR_LANG_JAPANESE    ; break;
        case LANG_YIDDISH           : index = STR_LANG_YIDDISH     ; break;
        case LANG_GREENLANDIC       : index = STR_LANG_GREENLANDIC ; break;
        case LANG_KANNADA           : index = STR_LANG_KANNADA     ; break;
        case LANG_LITHUANIAN        : index = STR_LANG_LITHUANIAN  ; break;
        case LANG_MACEDONIAN        : index = STR_LANG_MACEDONIAN  ; break;
        case LANG_MOLDAVIAN         : index = STR_LANG_MOLDAVIAN   ; break;
        case LANG_MALTESE           : index = STR_LANG_MALTESE     ; break;
        case LANG_SLOVENIAN         : index = STR_LANG_SLOVENIAN   ; break;
        case LANG_UKRAINIAN         : index = STR_LANG_UKRAINIAN   ; break;
        case LANG_AFAR              : index = STR_LANG_AFAR        ; break;
        case LANG_ABKHAZIAN         : index = STR_LANG_ABKHAZIAN   ; break;
        case LANG_AFRIKAANS         : index = STR_LANG_AFRIKAANS   ; break;
        case LANG_AMHARIC           : index = STR_LANG_AMHARIC     ; break;
        case LANG_ASSAMESE          : index = STR_LANG_ASSAMESE    ; break;
        case LANG_AYMARA            : index = STR_LANG_AYMARA      ; break;
        case LANG_AZERBAIJANI       : index = STR_LANG_AZERBAIJANI ; break;
        case LANG_BASHKIR           : index = STR_LANG_BASHKIR     ; break;
        case LANG_BYELORUSSIAN      : index = STR_LANG_BYELORUSSIAN; break;
        case LANG_BIHARI            : index = STR_LANG_BIHARI      ; break;
        case LANG_BISLAMA           : index = STR_LANG_BISLAMA     ; break;
        case LANG_BENGALI           : index = STR_LANG_BENGALI     ; break;
        case LANG_TIBETAN           : index = STR_LANG_TIBETAN     ; break;
        case LANG_ESPERANTO         : index = STR_LANG_ESPERANTO   ; break;
        case LANG_FIJI              : index = STR_LANG_FIJI        ; break;
        case LANG_FRISIAN           : index = STR_LANG_FRISIAN     ; break;
        case LANG_GUARANI           : index = STR_LANG_GUARANI     ; break;
        case LANG_GUJARATI          : index = STR_LANG_GUJARATI    ; break;
        case LANG_HAUSA             : index = STR_LANG_HAUSA       ; break;
        case LANG_HINDI             : index = STR_LANG_HINDI       ; break;
        case LANG_ARMENIAN          : index = STR_LANG_ARMENIAN    ; break;
        case LANG_INTERLINGUA       : index = STR_LANG_INTERLINGUA ; break;
        case LANG_INTERLINGUE       : index = STR_LANG_INTERLINGUE ; break;
        case LANG_INUPIAK           : index = STR_LANG_INUPIAK     ; break;
        case LANG_INDONESIAN        : index = STR_LANG_INDONESIAN  ; break;
        case LANG_JAVANESE          : index = STR_LANG_JAVANESE    ; break;
        case LANG_GEORGIAN          : index = STR_LANG_GEORGIAN    ; break;
        case LANG_KAZAKH            : index = STR_LANG_KAZAKH      ; break;
        case LANG_CAMBODIAN         : index = STR_LANG_CAMBODIAN   ; break;
        case LANG_KASHMIRI          : index = STR_LANG_KASHMIRI    ; break;
        case LANG_KURDISH           : index = STR_LANG_KURDISH     ; break;
        case LANG_KIRGHIZ           : index = STR_LANG_KIRGHIZ     ; break;
        case LANG_LATIN             : index = STR_LANG_LATIN       ; break;
        case LANG_LINGALA           : index = STR_LANG_LINGALA     ; break;
        case LANG_LAOTHIAN          : index = STR_LANG_LAOTHIAN    ; break;
        case LANG_MALAGASY          : index = STR_LANG_MALAGASY    ; break;
        case LANG_MAORI             : index = STR_LANG_MAORI       ; break;
        case LANG_MALAYALAM         : index = STR_LANG_MALAYALAM   ; break;
        case LANG_MONGOLIAN         : index = STR_LANG_MONGOLIAN   ; break;
        case LANG_MARATHI           : index = STR_LANG_MARATHI     ; break;
        case LANG_MALAY             : index = STR_LANG_MALAY       ; break;
        case LANG_BURMESE           : index = STR_LANG_BURMESE     ; break;
        case LANG_NAURU             : index = STR_LANG_NAURU       ; break;
        case LANG_NEPALI            : index = STR_LANG_NEPALI      ; break;
        case LANG_OCCITAN           : index = STR_LANG_OCCITAN     ; break;
        case LANG_AFAN_OROMO        : index = STR_LANG_AFAN_OROMO  ; break;
        case LANG_ORIYA             : index = STR_LANG_ORIYA       ; break;
        case LANG_PUNJABI           : index = STR_LANG_PUNJABI     ; break;
        case LANG_PASHTO            : index = STR_LANG_PASHTO      ; break;
        case LANG_QUECHUA           : index = STR_LANG_QUECHUA     ; break;
        case LANG_RHAETO_ROMANCE    : index = STR_LANG_RHAETO_ROMANCE; break;
        case LANG_KURUNDI           : index = STR_LANG_KURUNDI     ; break;
        case LANG_KINYARWANDA       : index = STR_LANG_KINYARWANDA ; break;
        case LANG_SANSKRIT          : index = STR_LANG_SANSKRIT    ; break;
        case LANG_SINDHI            : index = STR_LANG_SINDHI      ; break;
        case LANG_SANGHO            : index = STR_LANG_SANGHO      ; break;
        case LANG_SINGHALESE        : index = STR_LANG_SINGHALESE  ; break;
        case LANG_SAMOAN            : index = STR_LANG_SAMOAN      ; break;
        case LANG_SHONA             : index = STR_LANG_SHONA       ; break;
        case LANG_SOMALI            : index = STR_LANG_SOMALI      ; break;
        case LANG_SISWATI           : index = STR_LANG_SISWATI     ; break;
        case LANG_SESOTHO           : index = STR_LANG_SESOTHO     ; break;
        case LANG_SUNDANESE         : index = STR_LANG_SUNDANESE   ; break;
        case LANG_SWAHILI           : index = STR_LANG_SWAHILI     ; break;
        case LANG_TAMIL             : index = STR_LANG_TAMIL       ; break;
        case LANG_TELUGU            : index = STR_LANG_TELUGU      ; break;
        case LANG_TAJIK             : index = STR_LANG_TAJIK       ; break;
        case LANG_THAI              : index = STR_LANG_THAI        ; break;
        case LANG_TIGRINYA          : index = STR_LANG_TIGRINYA    ; break;
        case LANG_TURKMEN           : index = STR_LANG_TURKMEN     ; break;
        case LANG_TAGALOG           : index = STR_LANG_TAGALOG     ; break;
        case LANG_SETSWANA          : index = STR_LANG_SETSWANA    ; break;
        case LANG_TONGA             : index = STR_LANG_TONGA       ; break;
        case LANG_TSONGA            : index = STR_LANG_TSONGA      ; break;
        case LANG_TATAR             : index = STR_LANG_TATAR       ; break;
        case LANG_TWI               : index = STR_LANG_TWI         ; break;
        case LANG_URDU              : index = STR_LANG_URDU        ; break;
        case LANG_UZBEK             : index = STR_LANG_UZBEK       ; break;
        case LANG_VIETNAMESE        : index = STR_LANG_VIETNAMESE  ; break;
        case LANG_VOLAPUK           : index = STR_LANG_VOLAPUK     ; break;
        case LANG_WOLOF             : index = STR_LANG_WOLOF       ; break;
        case LANG_XHOSA             : index = STR_LANG_XHOSA       ; break;
        case LANG_YORUBA            : index = STR_LANG_YORUBA      ; break;
        case LANG_ZULU              : index = STR_LANG_ZULU        ; break;
        case LANG_NONE              : index = STR_LANG_NONE        ; break;
    }

    return (uint16_t)(index - STR_LANG_OTHER);
}


/* 21b1423c - todo */
SYS_LANGCODE OSD_LANG_GetKnownLangCodeByIndex (uint16_t index)
{
    SYS_LANGCODE langCode;
    uint32_t     strIdx = index + STR_LANG_OTHER;

    switch ( strIdx )
    {
        default:
        case STR_LANG_OTHER         : langCode = LANG_NOTSPECIFIED   ; break;
        case STR_LANG_ALBANIAN      : langCode = LANG_ALBANIAN       ; break;
        case STR_LANG_BULGARIAN     : langCode = LANG_BULGARIAN      ; break;
        case STR_LANG_CZECH         : langCode = LANG_CZECH          ; break;
        case STR_LANG_WELSH         : langCode = LANG_WELSH          ; break;
        case STR_LANG_DANISH        : langCode = LANG_DANISH         ; break;
        case STR_LANG_DUTCH         : langCode = LANG_DUTCH          ; break;
        case STR_LANG_ENGLISH       : langCode = LANG_ENGLISH        ; break;
        case STR_LANG_ESTONIAN      : langCode = LANG_ESTONIAN       ; break;
        case STR_LANG_FRENCH        : langCode = LANG_FRENCH         ; break;
        case STR_LANG_GERMAN        : langCode = LANG_GERMAN         ; break;
        case STR_LANG_ICELANDIC     : langCode = LANG_ICELANDIC      ; break;
        case STR_LANG_ITALIAN       : langCode = LANG_ITALIAN        ; break;
        case STR_LANG_SPANISH       : langCode = LANG_SPANISH        ; break;
        case STR_LANG_GREEK         : langCode = LANG_GREEK          ; break;
        case STR_LANG_FINNISH       : langCode = LANG_FINNISH        ; break;
        case STR_LANG_IRISH         : langCode = LANG_IRISH          ; break;
        case STR_LANG_CROATIAN      : langCode = LANG_CROATIAN       ; break;
        case STR_LANG_HUNGARIAN     : langCode = LANG_HUNGARIAN      ; break;
        case STR_LANG_KOREAN        : langCode = LANG_KOREAN         ; break;
        case STR_LANG_LETTISH       : langCode = LANG_LATVIAN_LETTISH; break;
        case STR_LANG_NORWEGIAN     : langCode = LANG_NORWEGIAN      ; break;
        case STR_LANG_POLISH        : langCode = LANG_POLISH         ; break;
        case STR_LANG_PORTUGUESE    : langCode = LANG_PORTUGUESE     ; break;
        case STR_LANG_ROMANIAN      : langCode = LANG_ROMANIAN       ; break;
        case STR_LANG_RUSSIAN       : langCode = LANG_RUSSIAN        ; break;
        case STR_LANG_SLOVAK        : langCode = LANG_SLOVAK         ; break;
        case STR_LANG_SERBIAN       : langCode = LANG_SERBIAN        ; break;
        case STR_LANG_SWEDISH       : langCode = LANG_SWEDISH        ; break;
        case STR_LANG_TURKISH       : langCode = LANG_TURKISH        ; break;
        case STR_LANG_CHINESE       : langCode = LANG_CHINESE        ; break;
        case STR_LANG_ARABIC        : langCode = LANG_ARABIC        ; break;
        case STR_LANG_BRETON        : langCode = LANG_BRETON        ; break;
        case STR_LANG_CATALAN       : langCode = LANG_CATALAN       ; break;
        case STR_LANG_CORSICAN      : langCode = LANG_CORSICAN      ; break;
        case STR_LANG_BASQUE        : langCode = LANG_BASQUE        ; break;
        case STR_LANG_PERSIAN       : langCode = LANG_PERSIAN       ; break;
        case STR_LANG_FAROESE       : langCode = LANG_FAROESE       ; break;
        case STR_LANG_SCOTS_GAELIC  : langCode = LANG_SCOTS_GAELIC  ; break;
        case STR_LANG_GALICIAN      : langCode = LANG_GALICIAN      ; break;
        case STR_LANG_HEBREW        : langCode = LANG_HEBREW        ; break;
        case STR_LANG_JAPANESE      : langCode = LANG_JAPANESE      ; break;
        case STR_LANG_YIDDISH       : langCode = LANG_YIDDISH       ; break;
        case STR_LANG_GREENLANDIC   : langCode = LANG_GREENLANDIC   ; break;
        case STR_LANG_KANNADA       : langCode = LANG_KANNADA       ; break;
        case STR_LANG_LITHUANIAN    : langCode = LANG_LITHUANIAN    ; break;
        case STR_LANG_MACEDONIAN    : langCode = LANG_MACEDONIAN    ; break;
        case STR_LANG_MOLDAVIAN     : langCode = LANG_MOLDAVIAN     ; break;
        case STR_LANG_MALTESE       : langCode = LANG_MALTESE       ; break;
        case STR_LANG_SLOVENIAN     : langCode = LANG_SLOVENIAN     ; break;
        case STR_LANG_UKRAINIAN     : langCode = LANG_UKRAINIAN     ; break;
        case STR_LANG_AFAR          : langCode = LANG_AFAR          ; break;
        case STR_LANG_ABKHAZIAN     : langCode = LANG_ABKHAZIAN     ; break;
        case STR_LANG_AFRIKAANS     : langCode = LANG_AFRIKAANS     ; break;
        case STR_LANG_AMHARIC       : langCode = LANG_AMHARIC       ; break;
        case STR_LANG_ASSAMESE      : langCode = LANG_ASSAMESE      ; break;
        case STR_LANG_AYMARA        : langCode = LANG_AYMARA        ; break;
        case STR_LANG_AZERBAIJANI   : langCode = LANG_AZERBAIJANI   ; break;
        case STR_LANG_BASHKIR       : langCode = LANG_BASHKIR       ; break;
        case STR_LANG_BYELORUSSIAN  : langCode = LANG_BYELORUSSIAN  ; break;
        case STR_LANG_BIHARI        : langCode = LANG_BIHARI        ; break;
        case STR_LANG_BISLAMA       : langCode = LANG_BISLAMA       ; break;
        case STR_LANG_BENGALI       : langCode = LANG_BENGALI       ; break;
        case STR_LANG_TIBETAN       : langCode = LANG_TIBETAN       ; break;
        case STR_LANG_ESPERANTO     : langCode = LANG_ESPERANTO     ; break;
        case STR_LANG_FIJI          : langCode = LANG_FIJI          ; break;
        case STR_LANG_FRISIAN       : langCode = LANG_FRISIAN       ; break;
        case STR_LANG_GUARANI       : langCode = LANG_GUARANI       ; break;
        case STR_LANG_GUJARATI      : langCode = LANG_GUJARATI      ; break;
        case STR_LANG_HAUSA         : langCode = LANG_HAUSA         ; break;
        case STR_LANG_HINDI         : langCode = LANG_HINDI         ; break;
        case STR_LANG_ARMENIAN      : langCode = LANG_ARMENIAN      ; break;
        case STR_LANG_INTERLINGUA   : langCode = LANG_INTERLINGUA   ; break;
        case STR_LANG_INTERLINGUE   : langCode = LANG_INTERLINGUE   ; break;
        case STR_LANG_INUPIAK       : langCode = LANG_INUPIAK       ; break;
        case STR_LANG_INDONESIAN    : langCode = LANG_INDONESIAN    ; break;
        case STR_LANG_JAVANESE      : langCode = LANG_JAVANESE      ; break;
        case STR_LANG_GEORGIAN      : langCode = LANG_GEORGIAN      ; break;
        case STR_LANG_KAZAKH        : langCode = LANG_KAZAKH        ; break;
        case STR_LANG_CAMBODIAN     : langCode = LANG_CAMBODIAN     ; break;
        case STR_LANG_KASHMIRI      : langCode = LANG_KASHMIRI      ; break;
        case STR_LANG_KURDISH       : langCode = LANG_KURDISH       ; break;
        case STR_LANG_KIRGHIZ       : langCode = LANG_KIRGHIZ       ; break;
        case STR_LANG_LATIN         : langCode = LANG_LATIN         ; break;
        case STR_LANG_LINGALA       : langCode = LANG_LINGALA       ; break;
        case STR_LANG_LAOTHIAN      : langCode = LANG_LAOTHIAN      ; break;
        case STR_LANG_MALAGASY      : langCode = LANG_MALAGASY      ; break;
        case STR_LANG_MAORI         : langCode = LANG_MAORI         ; break;
        case STR_LANG_MALAYALAM     : langCode = LANG_MALAYALAM     ; break;
        case STR_LANG_MONGOLIAN     : langCode = LANG_MONGOLIAN     ; break;
        case STR_LANG_MARATHI       : langCode = LANG_MARATHI       ; break;
        case STR_LANG_MALAY         : langCode = LANG_MALAY         ; break;
        case STR_LANG_BURMESE       : langCode = LANG_BURMESE       ; break;
        case STR_LANG_NAURU         : langCode = LANG_NAURU         ; break;
        case STR_LANG_NEPALI        : langCode = LANG_NEPALI        ; break;
        case STR_LANG_OCCITAN       : langCode = LANG_OCCITAN       ; break;
        case STR_LANG_AFAN_OROMO    : langCode = LANG_AFAN_OROMO    ; break;
        case STR_LANG_ORIYA         : langCode = LANG_ORIYA         ; break;
        case STR_LANG_PUNJABI       : langCode = LANG_PUNJABI       ; break;
        case STR_LANG_PASHTO        : langCode = LANG_PASHTO        ; break;
        case STR_LANG_QUECHUA       : langCode = LANG_QUECHUA       ; break;
        case STR_LANG_RHAETO_ROMANCE: langCode = LANG_RHAETO_ROMANCE; break;
        case STR_LANG_KURUNDI       : langCode = LANG_KURUNDI       ; break;
        case STR_LANG_KINYARWANDA   : langCode = LANG_KINYARWANDA   ; break;
        case STR_LANG_SANSKRIT      : langCode = LANG_SANSKRIT      ; break;
        case STR_LANG_SINDHI        : langCode = LANG_SINDHI        ; break;
        case STR_LANG_SANGHO        : langCode = LANG_SANGHO        ; break;
        case STR_LANG_SINGHALESE    : langCode = LANG_SINGHALESE    ; break;
        case STR_LANG_SAMOAN        : langCode = LANG_SAMOAN        ; break;
        case STR_LANG_SHONA         : langCode = LANG_SHONA         ; break;
        case STR_LANG_SOMALI        : langCode = LANG_SOMALI        ; break;
        case STR_LANG_SISWATI       : langCode = LANG_SISWATI       ; break;
        case STR_LANG_SESOTHO       : langCode = LANG_SESOTHO       ; break;
        case STR_LANG_SUNDANESE     : langCode = LANG_SUNDANESE     ; break;
        case STR_LANG_SWAHILI       : langCode = LANG_SWAHILI       ; break;
        case STR_LANG_TAMIL         : langCode = LANG_TAMIL         ; break;
        case STR_LANG_TELUGU        : langCode = LANG_TELUGU        ; break;
        case STR_LANG_TAJIK         : langCode = LANG_TAJIK         ; break;
        case STR_LANG_THAI          : langCode = LANG_THAI          ; break;
        case STR_LANG_TIGRINYA      : langCode = LANG_TIGRINYA      ; break;
        case STR_LANG_TURKMEN       : langCode = LANG_TURKMEN       ; break;
        case STR_LANG_TAGALOG       : langCode = LANG_TAGALOG       ; break;
        case STR_LANG_SETSWANA      : langCode = LANG_SETSWANA      ; break;
        case STR_LANG_TONGA         : langCode = LANG_TONGA         ; break;
        case STR_LANG_TSONGA        : langCode = LANG_TSONGA        ; break;
        case STR_LANG_TATAR         : langCode = LANG_TATAR         ; break;
        case STR_LANG_TWI           : langCode = LANG_TWI           ; break;
        case STR_LANG_URDU          : langCode = LANG_URDU          ; break;
        case STR_LANG_UZBEK         : langCode = LANG_UZBEK         ; break;
        case STR_LANG_VIETNAMESE    : langCode = LANG_VIETNAMESE    ; break;
        case STR_LANG_VOLAPUK       : langCode = LANG_VOLAPUK       ; break;
        case STR_LANG_WOLOF         : langCode = LANG_WOLOF         ; break;
        case STR_LANG_XHOSA         : langCode = LANG_XHOSA         ; break;
        case STR_LANG_YORUBA        : langCode = LANG_YORUBA        ; break;
        case STR_LANG_ZULU          : langCode = LANG_ZULU          ; break;
        case STR_LANG_NONE          : langCode = LANG_NONE          ; break;
    }

    return langCode;
}

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
