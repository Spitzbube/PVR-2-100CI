/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/sys/src/pvr_sys.c
**
** \brief       PVR control functions.
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
*****************************************************************************
*/
/*lint -save  */
#define DEBUG 0

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/

#include "fapi/sys_services.h"
#include <fapi/drv_sync.h>

#include "sys_api.h"

#if 0

#include <flashfs/flashfs.h>

#endif

#include <pvr/pvr.h>

#if 0

#include "av.h"
#include "eit.h"
#include "pvr_list.h"
#include "event_queue.h"
#include "sys_time.h"
#include "pvr_sys.h"

#ifdef APPL_SUBTT_ENABLED
#include "subtitle.h"
#endif /* APPL_SUBTT_ENABLED */

#ifdef APPL_TTXT_ENABLED
#include "teletext.h"
#endif /* APPL_TTXT_ENABLED */

#include "utils.h"

/*---------------------------------------------------------------------------*/
/* private data declarations                                                 */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/

/* NOTE: If PVRSYS_ENCRYPTION_ENABLED is defined, encryption for recordings and
         decryption of playback will be enabled. This will apply on all
         playbacks and recordings. Currently no mechanism is available to
         detect if a PVR recording is encrypted or not. Playing a clear file
         with decryption enabled or playing a crypted file without decryption
         enabled will fail. */
#undef PVRSYS_ENCRYPTION_ENABLED

#endif

#define PVRSYS_BUFALIGN_SIZE        0x00000400
#define PVRSYS_BUFALIGN_MASK        0xFFFFFC00

#define PVRSYS_BUFREC_SIZE          (/*PVR_CHUNK_SIZE*/512*188 * 10)

#define PVRSYS_BUFPLAY_SIZE         (/*PVR_CHUNK_SIZE*/512*188 * 8)

#if 0

#define PVRSYS_RECFILE_EXTENSION    "ts"

/* define application-specific track types */
#define PVR_TRACK_TYPE_ECM          (PVR_TRACK_TYPE_NUMS + 0)
#define PVR_TRACK_TYPE_EMM          (PVR_TRACK_TYPE_NUMS + 1)
#define PVR_TRACK_TYPE_TELETEXT     (PVR_TRACK_TYPE_NUMS + 2)
#define PVR_TRACK_TYPE_SUBTITLES    (PVR_TRACK_TYPE_NUMS + 3)

#define PVR_REC_ADD_SDT              //!< If defined, add SDT to CA recordings.

#define PVR_LIB_TIMEOUT        10000 //!< Timeout when waiting for state
                                     //!< changes in pvr_lib.
#define PVR_TIMEOUT_RETRIES      100 //!< Number of retries in polling loops.
#define PVR_TIMEOUT_SLEEPTIME     50 //!< Timeout in ms is: sleeptime * retries.
#define PVR_PERFLIMIT_TIMEOUT   6000 //!< Timeout in ms.

#define PVR_FATFS_FILESIZE_MAX   0x7FFFFFFF   // 2 GB - 1 Byte

// FIXME: track handling still needed?
#define PVR_REC_LOWER_TRACKS      6  //!< Tracks assigned in HW-controlled
                                     //!< channel area.
#define PVR_REC_UPPER_TRACKS      19 //!< Tracks assigned in upper channel area.
#if 0
#define PVR_REC_LOWER_START        1
#define PVR_REC_UPPER_START       10
#endif

#define PVR_REC_TRACKS_MAX        (PVR_REC_LOWER_TRACKS + PVR_REC_UPPER_TRACKS)

#define PVR_REC_VIDEO_MAX          1
#define PVR_REC_AUDIO_MAX          5
#define PVR_REC_TTX_MAX            2
#define PVR_REC_SUBTT_MAX          4
#define PVR_REC_EMM_MAX            5
#define PVR_REC_ECM_MAX            6

// FIXME: maybe not necessary anymore
/* NOTE: (Sum of PVR_REC_XXX_MAX values + 2) <= PVR_REC_TRACKS_MAX
         The additional 2 tracks are needed for EIT/CAT filtering. CAT is only
         recorded for scrambled services that are to be descrambled by CI
         during playback.

         TSD Channel assigment for recording TSDs 2/3 is as follows:

          0      Used by fd_pip (TSD-3 only)
          1...6  PVR_REC_LOWER_START: Passed to PVR lib for recording.
          7...9  Used by SmartGo-HD for PAT/PMT/CAT
         10...28 PVR_REC_UPPER_START: Passed to PVR lib for recording.
         29      Used by SmartGo-HD for PIP.
         30      Used by PVR lib for playback.
         31      "buffer 31" used by PVR lib for generation of TS to be
                 recorded.
*/

#define PVR_PID_NONE          0xFFFF    //!< Marks track as unused.

#if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

/* Constants for TS playback feature */
#define PVR_LW_PER_PKT              47  //!< TS packet size in longwords.
#define PVR_TSPKTS_PER_LOOP         200 //!< Number of packets in one transfer
                                        //!< loop

#endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */


#define PVR_CASYS_IDS_MAX           128

#if (PVR_REC_TRACKS_MAX > PVR_MAX_TRACKS )
    #error PVR configuration error!
#endif

#define PVRSYS_FLUSH_CHUNKS  256    //!< Number of recorded chunks after which
                                    //!< recording data will be periodically
                                    //!< flushed.

#define PVRSYS_PLAYMODE_FAST_NUMS   (PVRSYS_PLAYMODE_FF_NUMS + \
                                     PVRSYS_PLAYMODE_FR_NUMS)

#endif


/*---------------------------------------------------------------------------*/
/* local datatypes                                                           */
/*---------------------------------------------------------------------------*/

typedef struct
{
    uint32_t              id;                  //!< file identification
    uint32_t              revision;            //!< file revision

    /* currently empty: no PVR-specific information is stored */

    uint32_t              idEnd;               //!< file identification

} PVRSYS_FILEHDR_S;


typedef struct
{
    uint32_t              bufAddr; //0

    fbool_t               active; //4
#if 0
    fbool_t               internal;        //!< FTRUE if descrambled recording
                                           //!< of internal playback.
#if 0 //TODO
    RSRC_CFG_S            cfg;
#endif
    PVRLST_IDX            lstIdx;
    uint32_t              maxFileSize;
#if 0 //TODO
    SLIST_SERVIDX         servIdx;
#endif
    fbool_t               addCaStreams;   //!< FTRUE: Add ECM/EMM + CAT
    fbool_t               toBeDescr;      //!< Some content is yet to be
                                          //!< descrambled.
#else
    int fill_8[16]; //8
#endif

    FAPI_SYS_HandleT      handle; /*72*/        //!< Handle of recording instance.

#if 0
    PSISI_PMT_S           pmt;
    PSISI_CAT_S           cat;
#else
    int fill_76[398]; //8
#endif
    //1668
} PVRSYS_RECDAT_S;


typedef struct
{
    uint32_t              bufAddr; //0

    fbool_t               active; //4
    fbool_t               internal; /*8*/       //!< FTRUE if internal playback for
                                           //!< recording descrambled.

#if 0

    RSRC_CFG_S            cfg;
    PVRLST_IDX            lstIdx;
    int8_t                recIdx;
    PVRSYS_TIMESHIFTPOS_E pos;
    PVRSYS_PLAY_STATUS_E  mode;
    int16_t               speedIndex;
    uint32_t              filePos;
    SYS_PLAYPREF_S        strPref;
#else
    int fill_12[19]; //12 / 5128
#endif
    fbool_t               rerouting; /*88/5204*/
    fbool_t               rewindWait; //92/5208

    FAPI_SYS_HandleT      handle; /*96/5212*/    //!< playback handle

#if 0
    SYS_STREAM_INFO_S     stream;     //!< stream information
    uint8_t               audioRef[SYS_AUDIO_STR_MAX];
#else
    int fill_100[23]; //100/5216
#endif
    int8_t                audioMainIdx; //192/5308
    int8_t                audioSpdifIdx; //193/5309

#if 0
    /* Addition parameters and buffers for external TS playback feature. */

    #if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

    RTOS_SemaphoreT      tsFeedMutex;
    RTOS_SemaphoreT      tsTransferSemaphore;

    #endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

    #ifdef APPL_EDITMARKER_ENABLED
    /* block marker data storage */
    PVR_BLOCK_MARKER_ITEM_S blockMarkerData;
    #endif /* APPL_EDITMARKER_ENABLED */
#endif

    /* flag to lock certain playback modes in case there is no video */
    fbool_t             lockTrickModes; //196/5312

#if 0
    PVR_PlayInfoT       playInfo;
#else
    int fill_5316[25]; // /5316
#endif
    //
} PVRSYS_PLAYDAT_S;


typedef struct
{
    PVRSYS_FILEHDR_S cfg; //0

    PVRSYS_STATUS_S     currStatus; //12
    PVRSYS_RECDAT_S     rec[3/*RSRC_REC_MAX*/]; /*112*/ // Index 0: TSD-2, 1: TSD-3.
    PVRSYS_PLAYDAT_S    play; //5116
#if 0
    uint8_t             devAvl;            //!< Bitfield holding avail. devices.

    #ifdef PVRSYS_ENCRYPTION_ENABLED
    PVR_CryptoParamsT   cryptoParams;      //!< Parameters for optional
                                           //!< encryption/decryption feature.
    #endif /* PVRSYS_ENCRYPTION_ENABLED */
#endif
    //5416
} PVRSYS_DATA_S;

#if 0

enum
{
    PVRSYS_FASTCFG_MPEG = 0,    //!< Fast mode config. for MPEG video streams.
    PVRSYS_FASTCFG_H264,        //!< Fast mode config. for H.264 video streams.
    PVRSYS_FASTCFG_NOVIDEO,     //!< Fast mode config. for audio-only streams.
    PVRSYS_FASTCFG_NUMS
};

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/

#endif

static PVRSYS_DATA_S* pvrDat = NULL; //21f03008
void* Data_21f0300c; //21f0300c
void* Data_21f03010; //21f03010
void* Data_21f03014; //21f03014

void (*Data_21f7e368)(); //21f7e368


#if 0

static PVRSYS_FastModeCfgT fastCfgMPEG[PVRSYS_PLAYMODE_FAST_NUMS] =
{
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200, -256, 256 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200, -128, 128 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,  -64,  64 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,  -32,  32 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,  -16,  16 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,   -8,   8 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,   -4,   4 },   // FR
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,   -2,   2 },   // FR
    { VAL_PLAYMODE_FAST_DEC_IP,            0,    0,   2 },   // FF
    { VAL_PLAYMODE_FAST_DEC_IONLY,         0,    0,   4 },   // FF
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,    8,   8 },   // FF
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,   16,  16 },   // FF
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,   32,  32 },   // FF
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,   64,  64 },   // FF
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,  128, 128 },   // FF
    { VAL_PLAYMODE_FAST_LIB_IONLY,       200,  256, 256 }    // FF
};

static PVRSYS_FastModeCfgT fastCfgH264[PVRSYS_PLAYMODE_FAST_NUMS] =
{
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200, -256, 256 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200, -128, 128 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,  -64,  64 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,  -32,  32 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,  -16,  16 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,   -8,   8 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,   -4,   4 },   // FR
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,   -2,   2 },   // FR
    { VAL_PLAYMODE_FAST_DEC_IONLY,         0,    0,   2 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,    4,   4 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,    8,   8 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,   16,  16 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,   32,  32 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,   64,  64 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,  128, 128 },   // FF
    { VAL_PLAYMODE_FAST_CONTROLLEDFEED,  200,  256, 256 }    // FF
};

static PVRSYS_FastModeCfgT fastCfgAudio[PVRSYS_PLAYMODE_FAST_NUMS] =
{
    { VAL_PLAYMODE_FAST_NOFEED,            0, -256, 256 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0, -128, 128 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,  -64,  64 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,  -32,  32 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,  -16,  16 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,   -8,   8 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,   -4,   4 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,   -2,   2 },   // FR
    { VAL_PLAYMODE_FAST_NOFEED,            0,    2,   2 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,    4,   4 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,    8,   8 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,   16,  16 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,   32,  32 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,   64,  64 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,  128, 128 },   // FF
    { VAL_PLAYMODE_FAST_NOFEED,            0,  256, 256 }    // FF
};

#endif

/*static PVRSYS_FastModeCfgT*/void* pFastCfg[/*PVRSYS_FASTCFG_NUMS*/3] = { /*fastCfgMPEG,
                                                              fastCfgH264,
                                                              fastCfgAudio*/ }; //21d79514

#if 0

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

FSTATIC fbool_t  PVRSYS_SettingsLoad        (void);
FSTATIC void     PVRSYS_SettingsDefaultsSet (void);

FSTATIC void     PVRSYS_RecCallback     (FAPI_SYS_HandleT handle,
                                         PVR_RecordNotifyT reason);
FSTATIC void     PVRSYS_PlayCallback    (FAPI_SYS_HandleT handle,
                                         PVR_PlayNotifyT reason);
FSTATIC int32_t  PVRSYS_IntPlayPrepare  (PVRLST_IDX idx, int8_t recIdx,
                                         PVRSYS_PLAY_TYPE_E type,
                                         PVRSYS_TIMESHIFTPOS_E pos,
                                         PVRSYS_PLAY_STATUS_E mode,
                                         uint32_t filePos, int16_t speedIndex,
                                         const SYS_PLAYPREF_S* pPref,
                                         const RSRC_CFG_S* cfg);
FSTATIC int32_t  PVRSYS_IntPlayStart    (const PSISI_PMT_S* pPmt);
FSTATIC int32_t  PVRSYS_IntPlayStop     (fbool_t userInitiated,
                                         fbool_t sendEvent);
FSTATIC int32_t  PVRSYS_IntPlaySetMode  (FAPI_SYS_HandleT playHandle,
                                         PVRSYS_PLAY_STATUS_E mode,
                                         int16_t speedIndex, fbool_t internal);
FSTATIC void     PVRSYS_PlayChooseStreams(const SYS_PLAYPREF_S* pPref);
FSTATIC void     PVRSYS_PlayRewindPosition(PVRSYS_PLAYDAT_S* pPlayDat);
FSTATIC void     PVRSYS_SendPbEvent     (PVRSYS_PLAY_EVENT_E action,
                                         const PVRSYS_STATPLAY_S* mode,
                                         fbool_t userInitiated);
FSTATIC void     PVRSYS_SendRecEvent    (PVRSYS_REC_EVENT_E action,
                                         uint8_t recIdx);
FSTATIC int32_t  PVRSYS_PlayUpdateStreams(const PSISI_PMT_S* pPmt);
FSTATIC int32_t  PVRSYS_IntRecPrepare   (SYS_DEVICE_E device,
                                         const char_t* dirName,
                                         SYS_STRING_S recordName,
                                         SLIST_SERVIDX servIdx,
                                         RECTIMER_IDX timerIdx,
                                         uint32_t maxFileSize, uint8_t* recIdx);
FSTATIC int32_t  PVRSYS_IntRecStart     (uint8_t recIdx,
                                         const PSISI_PMT_S* pPmt);

FSTATIC int32_t  PVRSYS_SetFastModes    (const PVRSYS_FastModeCfgT* pCfg,
                                         uint16_t* index);

FSTATIC int32_t  PVRSYS_PlayChangeMode          (FAPI_SYS_HandleT handlePlay,
                                                 PVR_PlayModeT mode,
                                                 uint8_t modeIndex);
FSTATIC int32_t  PVRSYS_PlayWaitForTransitionEnd(FAPI_SYS_HandleT handle);
FSTATIC int32_t  PVRSYS_PlayWaitForMode         (FAPI_SYS_HandleT handle,
                                                 PVR_PlayModeT mode,
                                                 uint8_t modeIndex);
FSTATIC int32_t  PVRSYS_PlaySpeedToFastModeIdx  (FAPI_SYS_HandleT playHandle,
                                                 int16_t speedIndex,
                                                 uint8_t* pModeIndex);
FSTATIC int32_t  PVRSYS_PlayFastModeIdxToSpeed  (uint8_t modeIndex,
                                                 int16_t* pSpeed);
FSTATIC uint16_t PVRSYS_PlayGetFastSpeedFactor  (uint8_t modeIndex);
FSTATIC uint16_t PVRSYS_PlayGetSlowSpeedFactor  (uint8_t modeIndex);
FSTATIC int32_t  PVRSYS_PlaySeek                (FAPI_SYS_HandleT handle,
                                                 PVR_SeekModeT mode,
                                                 uint32_t value,
                                                 fbool_t internal);
FSTATIC int32_t  PVRSYS_RecWaitForTransitionEnd (FAPI_SYS_HandleT handle);
FSTATIC int32_t  PVRSYS_RecSetModeAndWait       (FAPI_SYS_HandleT handle,
                                                 PVR_RecordModeT mode);
FSTATIC int32_t  PVRSYS_RecWaitForStart         (uint8_t recIdx);
FSTATIC int32_t  PVRSYS_RecGetFileEndPos        (int8_t recIdx,
                                                 uint32_t* position);
FSTATIC int32_t  PVRSYS_RecAssignTracks         (PVRSYS_RECDAT_S* pRecDat,
                                                 PVR_RecordOpenT* recOpen);
FSTATIC int32_t  PVRSYS_RecSetTracks            (PVRSYS_RECDAT_S* pRecDat,
                                                 PVR_RecordOpenT* recOpen,
                                                 fbool_t* pidChange);
FSTATIC void     PVRSYS_RecSetPid               (uint8_t* index,
                                                 PVR_RecordOpenT* pParams,
                                                 uint16_t trackPid,
                                                 uint8_t trackFormat,
                                                 fbool_t* pidChange);
FSTATIC void     PVRSYS_RecAddCaInfo            (uint16_t ca_system_id,
                                                 uint16_t* pIds,
                                                 uint16_t* numIds);
FSTATIC fbool_t  PVRSYS_IsInCaInfo              (uint16_t ca_system_id,
                                                 uint16_t* pIds,
                                                 uint16_t numIds);
FSTATIC int32_t  PVRSYS_GetRecIndexByTsd        (uint8_t tsdIdx,
                                                 uint8_t* pRecIdx);

#if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

FSTATIC void    PVR_TsFeedDone            (int32_t status, uint32_t bytes);
FSTATIC int32_t PVR_IntDescrRecPrepare    (SYS_DEVICE_E device,
                                           const char_t* dirName,
                                           SYS_STRING_S recordName,
                                           const PVR_LIST_ITEM_S* pLstItem,
                                           const RSRC_CFG_S* cfg,
                                           RECTIMER_IDX timerIdx,
                                           uint8_t* recIdx);
FSTATIC int32_t PVRSYS_IntDescrPlayStop   ();

#endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

/*---------------------------------------------------------------------------*/
/* public functions                                                          */
/*---------------------------------------------------------------------------*/

#endif


/* 21bb6384 - todo */
void func_21bb6384()
{
    FAPI_SYS_PRINT_MSG("func_21bb6384: TODO\n");
}


/* 21bb8718 - todo */
int32_t PVRSYS_Init()
{
    int32_t             retVal = FAPI_OK;
    uint16_t            cnt;
    //uint8_t             tsdChannels[PVR_MAX_TRACKS];
    uint16_t            index;

    DBG_Assert(pvrDat == NULL);

#if 0
    /* Test if maximum flash file size is sufficient. */
    retVal = FLASH_CheckFileSize (FILEID_PVRDAT, sizeof(PVRSYS_FILEHDR_S));

    if ( retVal != FAPI_OK )
    {
        FAPI_SYS_PRINT_MSG("FLASH_CheckFileSize retVal=%x\n", retVal);
        return retVal;
    }
#endif

    pvrDat = /*UTILS_Malloc*/SYS_MemoryAllocate(sizeof(PVRSYS_DATA_S));
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_OUT_OF_MEMORY;

    do
    {
        memset (pvrDat, 0, sizeof(PVRSYS_DATA_S));

        Data_21f0300c = rtos_create_semaphore(1);

        Data_21f03010 = rtos_create_semaphore(1);

        Data_21f03014 = rtos_create_semaphore(1);

        memset(pvrDat, 0, sizeof(PVRSYS_DATA_S));

        /* ----------------------------------------------------------------- */

        for ( cnt = 0; cnt < 2/*RSRC_REC_MAX*/; cnt++ )
        {
            pvrDat->rec[cnt].bufAddr = (uint32_t)FAPI_SYS_MALLOC_UNCACHED(
                                                    PVRSYS_BUFREC_SIZE
                                                  + PVRSYS_BUFALIGN_SIZE);

            if ( pvrDat->rec[cnt].bufAddr == 0 )
            {
                retVal = APPL_SMARTGO_ERR_OUT_OF_MEMORY;
                break;
            }
            else
            {
                /* align addresses to 1K-border */
                pvrDat->rec[cnt].bufAddr += PVRSYS_BUFALIGN_SIZE;
                pvrDat->rec[cnt].bufAddr &= PVRSYS_BUFALIGN_MASK;
            }
        }

        if ( retVal != FAPI_OK )
        {
            break;
        }

        pvrDat->play.bufAddr = (uint32_t)FAPI_SYS_MALLOC_UNCACHED(
                                                       PVRSYS_BUFPLAY_SIZE
                                                     + PVRSYS_BUFALIGN_SIZE);
        if ( pvrDat->play.bufAddr == 0 )
        {
            retVal = APPL_SMARTGO_ERR_OUT_OF_MEMORY;
            break;
        }

        /* align address to 1K-border */
        pvrDat->play.bufAddr += PVRSYS_BUFALIGN_SIZE;
        pvrDat->play.bufAddr &= PVRSYS_BUFALIGN_MASK;

        /* ----------------------------------------------------------------- */

        #if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

        if ( CISYS_TSPlaybackAvailable() )
        {
            pvrDat->play.tsFeedMutex = RTOS_CreateSemaphore(1);
            if ( pvrDat->play.tsFeedMutex == NULL )
            {
                return APPL_ERR_SMARTGO_SYS_RESOURCES;
            }

            pvrDat->play.tsTransferSemaphore = RTOS_CreateSemaphore(0);
            if ( pvrDat->play.tsTransferSemaphore == NULL )
            {
                return APPL_ERR_SMARTGO_SYS_RESOURCES;
            }
        }

        #endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

        /* ----- init and configure PVR library ---------------------------- */

        retVal = PVRDEC_Init(); /* init decoder interface */
        if ( retVal != FAPI_OK ) 
        {
//            FAPI_SYS_PRINT_MSG("PVRDEC_Init retVal=%x\n", retVal);
            break;
        }
        
        retVal = PVR_Init(); /* init PVR library */
        if ( retVal != FAPI_OK ) 
        {
//            FAPI_SYS_PRINT_MSG("PVR_Init retVal=%x\n", retVal);
            break;
        }
        
        /* ----- configure file name handling ------------------------------ */

        retVal = PVR_SetFileExtension  ("ts"/*PVRSYS_RECFILE_EXTENSION*/);
        if ( retVal != FAPI_OK ) 
        {
//            FAPI_SYS_PRINT_MSG("PVR_SetFileExtension retVal=%x\n", retVal);
            break;
        }

        retVal = PVR_SetFileSplitParams (2, 1); /* 2 digits, decimal notation */
        if ( retVal != FAPI_OK ) 
        {
//            FAPI_SYS_PRINT_MSG("PVR_SetFileSplitParams retVal=%x\n", retVal);
            break;
        }

        /* ----- configure fast modes -------------------------------------- */

        /*

        NOTE: Fast modes are configured as follows:
        -  0 ...  7     FF modes MPEG
        -  8 ... 15     FR modes MPEG
        - 16 ... 23     FF modes H.264
        - 24 ... 31     FR modes H.264
        - 32 ... 39     FF modes audio
        - 40 ... 47     FR modes audio

        Speed is approximately doubled with each fast mode index, starting with
        2x normal speed.
        */

        index = 0;

        for ( cnt = 0; cnt < 3/*PVRSYS_FASTCFG_NUMS*/; cnt++ )
        {
            retVal = PVRSYS_SetFastModes(pFastCfg[cnt], &index);
            if ( retVal != FAPI_OK ) 
            {
//                FAPI_SYS_PRINT_MSG("PVRSYS_SetFastModes retVal=%x\n", retVal);
                break;
            }
        }

#if 0
        /* ----- generate crypto key --------------------------------------- */

        #ifdef PVRSYS_ENCRYPTION_ENABLED

        memset (&(pvrDat->cryptoParams), 0, sizeof(pvrDat->cryptoParams));

        /* TODO: Choose a unique value e.g. chip ID in order to restrict
                 data access to the box it has been recorded with. */
        pvrDat->cryptoParams.keyMSB = 0x01234567;
        pvrDat->cryptoParams.keyLSB = 0x89ABCDEF;

        #endif /* PVRSYS_ENCRYPTION_ENABLED */

#endif
    }
    while ( 0 );

    if ( retVal != FAPI_OK )
    {
//        FAPI_SYS_PRINT_MSG("PVRSYS_Init retVal=%x\n", retVal);
        return retVal;
    }

    /* --------------------------------------------------------------------- */

    // FIXME: track handling still needed?
    #if 0
    for ( cnt = 0; cnt < PVR_MAX_TRACKS; cnt++ )
    {
        if ( cnt >= PVR_REC_TRACKS_MAX ) tsdChannels[cnt] = 0xFF;
        else if ( cnt < PVR_REC_LOWER_TRACKS )
        {
            tsdChannels[cnt] = PVR_REC_LOWER_START + cnt;
        }
        else
        {
            tsdChannels[cnt] = PVR_REC_UPPER_START + cnt - PVR_REC_LOWER_TRACKS;
        }
    }

    retVal = PVR_SetRecordingChannels(tsdChannels);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }
    #endif

    /* --------------------------------------------------------------------- */

    /* init PVR list management */
    retVal = /*PVR_LIST_Init*/pvr_list_init();
    if ( retVal != FAPI_OK ) 
    {
//        FAPI_SYS_PRINT_MSG("PVR_Init retVal=%x\n", retVal);
        return retVal;
    }

    pvrDat->currStatus.numActiveRecs    = 0;
    pvrDat->currStatus.bkgrRecIdx       = -1;
    pvrDat->currStatus.play.type        = PLAY_TYPE_NONE;
    pvrDat->currStatus.play.status      = PLAY_STATUS_INACTIVE;
    pvrDat->currStatus.play.speedIndex  = 0;
    pvrDat->currStatus.play.speedFactor = 0;
    pvrDat->currStatus.play.recIdx      = -1;
    pvrDat->currStatus.play.lstIdx      = -1;

    for ( cnt = 0; cnt < /*RSRC_REC_MAX*/3; cnt++ )
    {
        pvrDat->currStatus.rec[cnt].status    = REC_STATUS_INACTIVE;
        pvrDat->currStatus.rec[cnt].type      = REC_TYPE_NONE;
        pvrDat->currStatus.rec[cnt].timerIdx  = RECTIMER_INVALID;
        pvrDat->currStatus.rec[cnt].servIdx   = 0;
    }

    for ( cnt = 0; cnt < /*RSRC_REC_MAX*/2; cnt++ )
    {
        pvrDat->rec[cnt].active = FFALSE;
        pvrDat->rec[cnt].handle = NULL;
    }

    pvrDat->play.active         = FFALSE;
    pvrDat->play.internal       = FFALSE;
    pvrDat->play.handle         = NULL;
    pvrDat->play.rerouting      = FFALSE;
    pvrDat->play.audioMainIdx   = -1;
    pvrDat->play.audioSpdifIdx  = -1;
    pvrDat->play.lockTrickModes = FTRUE;

    Data_21f7e368 = func_21bb6384;

#if 0
    /* ----- Load PVR settings --------------------------------------------- */

    FAPI_SYS_PRINT_DEBUG(1,"[PVR] Load settings\n");
    if ( PVRSYS_SettingsLoad() == FFALSE )
    {
        FAPI_SYS_PRINT_DEBUG(1,"[PVR] Set default settings\n");
        PVRSYS_SettingsDefaultsSet();
    }
#endif

    return FAPI_OK;
}

#if 0

int32_t PVRSYS_Wakeup ()
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    return FAPI_OK;
}

int32_t PVRSYS_Shutdown ()
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    PVRSYS_AbortAllOperations();

    return FAPI_OK;
}

void PVRSYS_AbortAllOperations ()
{
    int8_t cnt;

    (void)PVRSYS_PlayStop();

    for ( cnt = 0; cnt < RSRC_REC_MAX; cnt++ )
    {
        (void)PVRSYS_RecordStop (cnt, FFALSE);
    }

    (void)AV_Nop(); /* sleep until last command has been performed */
}

/* abort all operations on given device */
void PVRSYS_AbortDeviceOperations (SYS_DEVICE_E device)
{
    PVR_LIST_ITEM_S lstItem;
    int32_t         retVal;
    int8_t          cnt;
    fbool_t         stopDescrRec = FFALSE;

    /* ----- check playback ------------------------------------------------ */

    if ( pvrDat->play.active )
    {
        retVal = PVR_LIST_GetItemByIndex (pvrDat->play.lstIdx, &lstItem, NULL);

        if ( (retVal         == FAPI_OK) &&
             (lstItem.device == device) )
        {
            if ( !(pvrDat->play.internal) ) /* normal playback */
            {
                (void)PVRSYS_IntPlayStop(FFALSE, FTRUE);
            }
            else /* internal playback for descrambling */
            {
                /* associated recording must be stopped */
                stopDescrRec = FTRUE;
            }
        }
    }

    /* ----- check recordings ---------------------------------------------- */

    for ( cnt = 0; cnt < RSRC_REC_MAX; cnt++ )
    {
        if ( !(pvrDat->rec[cnt].active) ) continue;

        if ( PVR_LIST_GetItemByIndex (pvrDat->rec[cnt].lstIdx, &lstItem, NULL)
              == FAPI_OK )
        {
            if ( lstItem.device == device )
            {
                (void)PVRSYS_RecordStop (cnt, FFALSE);
            }
            else if ( stopDescrRec &&
                      (pvrDat->currStatus.rec[cnt].type == REC_TYPE_DESCRREC) )
            {
                (void)PVRSYS_RecordStop (cnt, FFALSE);
            }
        }
    }

    (void)AV_Nop(); /* sleep until last command has been performed */
}

/* Stop any operations on given service */
int32_t PVRSYS_InvalidateService (SLIST_SERVIDX servIdx)
{
    int8_t   cnt;
    fbool_t  keepFile;

    if ( servIdx < 0 ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    for ( cnt = 0; cnt < RSRC_REC_MAX; cnt++ )
    {
        if ( (pvrDat->currStatus.rec[cnt].status  != REC_STATUS_INACTIVE) &&
             (pvrDat->currStatus.rec[cnt].servIdx == servIdx) )
        {
            keepFile = (pvrDat->currStatus.rec[cnt].type == REC_TYPE_BACKGROUND)
                       ? FFALSE : FTRUE;

            (void)PVRSYS_RecordStop (cnt, keepFile);
        }
    }

    return FAPI_OK;
}

void PVRSYS_PMTReceived (const SYS_EVT_PMT_S* pEvt)
{
    uint8_t             recIdx;
    PVRSYS_RECDAT_S*    pRecDat;
    fbool_t             pidChange;
    PVR_RecordOpenT     recOpen;

    if ( (pEvt->operation & RSRC_OP_PLAY) != 0 )
    {
        FAPI_SYS_PRINT_DEBUG(4,"[PVR] Play: PMT received: version %i\n",
                   pEvt->version_number);

        if ( pvrDat->play.handle != NULL )
        {
            PSISI_PMT_S currPmt;

            if ( PSISI_PMT_Get(pEvt->tsdIdx, &currPmt) == FAPI_OK )
            {
                (void)PVRSYS_PlayUpdateStreams(&currPmt);

                PVRSYS_PlayRewindPosition(&(pvrDat->play));
            }
        }
    }

    else if ( (pEvt->operation & RSRC_OP_RECANY) != 0 )
    {
        FAPI_SYS_PRINT_DEBUG(4,"[PVR] Rec: PMT received: version %i\n",
                   pEvt->version_number);

        recIdx  = ((pEvt->operation & RSRC_OP_REC1) != 0) ? 0 : 1;
        pRecDat = pvrDat->rec + recIdx;

        if ( pRecDat->active )
        {
            if ( PSISI_PMT_Get(pEvt->tsdIdx, &(pRecDat->pmt)) == FAPI_OK )
            {
                if ( pRecDat->handle == NULL )
                {
                    /* Recording has not yet started */
                    (void)PVRSYS_IntRecStart (recIdx, &(pRecDat->pmt));
                }
                else
                {
                    /* Recording is already active, check for necessary PID
                       changes */
                    if ( PVR_GetRecordingOpen(pRecDat->handle, &recOpen) ==
                         FAPI_OK )
                    {
                        if ( (PVRSYS_RecSetTracks (pRecDat, &recOpen,
                                                   &pidChange) == FAPI_OK) )
                        {
                            (void)PVR_SetRecordingPmt (pRecDat->handle,
                                                       pRecDat->pmt.pid,
                                                       (uint8_t*)
                                                       (pRecDat->pmt.buf),
                                                       pRecDat->pmt.bufSize,
                                                       recOpen.trackPid,
                                                       recOpen.trackFormat);
                        }
                    }
                }
            }
        }
    }
}

/*lint -save -e715 */
void PVRSYS_CATReceived (const SYS_EVT_CAT_S* pEvt)
{
    #ifdef APPL_CI_ENABLED

    PVRSYS_RECDAT_S*    pRecDat;
    uint8_t             recIdx;
    int32_t             retVal;

    retVal = PVRSYS_GetRecIndexByTsd(pEvt->tsdIdx, &recIdx);
    if ( retVal != FAPI_OK ) return;

    pRecDat = pvrDat->rec + recIdx;

    /* check if not-yet-started recording waits for CAT */

    if ( (pRecDat->active)         &&
         (pRecDat->handle == NULL) &&
         (pRecDat->addCaStreams) )
    {
        if ( PSISI_CAT_Get(pEvt->tsdIdx, &(pRecDat->cat)) == FAPI_OK )
        {
            (void)PVRSYS_IntRecStart (recIdx, &(pRecDat->pmt));
        }
    }

    #endif /* APPL_CI_ENABLED */
}
/*lint -restore */

void PVRSYS_PlayEvent (PVR_PlayNotifyT event)
{
    DBG_Assert(pvrDat != NULL);

    switch ( event )
    {
        case PVR_PLAY_NOTIFY_FILE_ERROR:
        case PVR_PLAY_NOTIFY_END_OF_DATA:
            pvrDat->currStatus.play.status      = PLAY_STATUS_STOP;
            pvrDat->currStatus.play.speedIndex  = 0;
            pvrDat->currStatus.play.speedFactor = 0;
            break;

        case PVR_PLAY_NOTIFY_BEGIN_OF_DATA:
            pvrDat->currStatus.play.status      = PLAY_STATUS_PAUSE;
            pvrDat->currStatus.play.speedIndex  = 0;
            pvrDat->currStatus.play.speedFactor = 0;
            break;

        default:
            break;
    }
}

void PVRSYS_RecEvent (uint8_t recIdx, PVR_RecordNotifyT event)
{
    DBG_Assert(pvrDat != NULL);

    if ( recIdx >= RSRC_REC_MAX ) return;

    switch ( event )
    {
        case PVR_RECORD_NOTIFY_FILE_ERROR:
        case PVR_RECORD_NOTIFY_DISK_FULL:
        case PVR_RECORD_NOTIFY_MAX_SIZE:
        case PVR_RECORD_NOTIFY_STOP_POSITION:
        case PVR_RECORD_NOTIFY_PERFORMANCE_LIMIT:
            if ( pvrDat->currStatus.rec[recIdx].status == REC_STATUS_ACTIVE )
            {
                pvrDat->currStatus.rec[recIdx].status = REC_STATUS_STOP;
            }
            break;

        default:
            break;
    }
}

#ifdef APPL_CI_ENABLED

void PVRSYS_CAMRemoved (uint8_t recIdx, RSRC_TS_E ts)
{
    PVRSYS_RECDAT_S*    pRecDat = pvrDat->rec + recIdx;
    PVR_LIST_ITEM_S     pvrItem;

    if ( recIdx >= RSRC_REC_MAX ) return;

    /* If a recording used CI for descrambling, update its 'scrambled'
       flag. */

    if ( (pRecDat->active)    &&
         (pRecDat->cfg.useCi) &&
         (pRecDat->cfg.ts == ts) )
    {
        if ( (pRecDat->toBeDescr) &&
             (PVR_LIST_GetItemByIndex(pRecDat->lstIdx, &pvrItem, NULL)
             == FAPI_OK) )
        {
            pvrItem.flags |= PVR_LIST_FLAG_SCRAMBLED;

            /* Store updated status. */
            (void)PVR_LIST_SetItem (&pvrItem, pRecDat->lstIdx, FFALSE);
        }
    }
}

#endif /* APPL_CI_ENABLED */

#endif

/* ------------------------------------------------------------------------- */

/* 21bb4d7c - todo */
int32_t PVRSYS_GetStatus (PVRSYS_STATUS_S* status)
{
    PVR_PlayModeT   playMode      = PVR_PLAY_MODE_NORMAL;
    uint8_t         playModeIndex = 0;
    int32_t         retVal = FAPI_OK;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    /* ----- update playback status ---------------------------------------- */

    if ( (pvrDat->play.handle == NULL) ||
          pvrDat->play.internal )
    {
        pvrDat->currStatus.play.type        = PLAY_TYPE_NONE;
        pvrDat->currStatus.play.status      = PLAY_STATUS_INACTIVE;
        pvrDat->currStatus.play.speedIndex  = 0;
        pvrDat->currStatus.play.speedFactor = 0;
        pvrDat->currStatus.play.recIdx      = -1;
        pvrDat->currStatus.play.lstIdx      = -1;
    }
    else
    {
        retVal = PVR_GetPlaybackMode (pvrDat->play.handle, &playMode,
                                      &playModeIndex);

        if ( retVal == FAPI_OK )
        {
            switch ( playMode )
            {
                case PVR_PLAY_MODE_STOPPED:
                    pvrDat->currStatus.play.status      = PLAY_STATUS_STOP;
                    pvrDat->currStatus.play.speedIndex  = 0;
                    pvrDat->currStatus.play.speedFactor = 0;
                    break;

                case PVR_PLAY_MODE_NORMAL:
                    pvrDat->currStatus.play.status      = PLAY_STATUS_NORMAL;
                    pvrDat->currStatus.play.speedIndex  = 0;
                    pvrDat->currStatus.play.speedFactor = 1;
                    break;

                case PVR_PLAY_MODE_FAST:
                    pvrDat->currStatus.play.status = PLAY_STATUS_FAST;

                    retVal = PVRSYS_PlayFastModeIdxToSpeed(playModeIndex,
                                                           &(pvrDat->currStatus.
                                                             play.speedIndex));

                    pvrDat->currStatus.play.speedFactor =
                                  PVRSYS_PlayGetFastSpeedFactor(playModeIndex);
                    break;

                case PVR_PLAY_MODE_PAUSE:
                    pvrDat->currStatus.play.status      = PLAY_STATUS_PAUSE;
                    pvrDat->currStatus.play.speedIndex  = 0;
                    pvrDat->currStatus.play.speedFactor = 0;
                    break;

                case PVR_PLAY_MODE_SLOW:
                    pvrDat->currStatus.play.status     = PLAY_STATUS_SLOW;
                    pvrDat->currStatus.play.speedIndex = (int16_t)playModeIndex;
                    pvrDat->currStatus.play.speedFactor =
                                PVRSYS_PlayGetSlowSpeedFactor(playModeIndex);
                    break;

                default:
                case PVR_PLAY_MODE_CHANGING:
                    /* do nothing */
                    break;
            }
        }
    }

    if ( retVal == FAPI_OK )
    {
        *status = pvrDat->currStatus;
    }

    return retVal;
}

#if 0

/*!
*******************************************************************************
**
** \brief  Check if any PVR recording is active.
**
** \return  FTRUE    a recording is active
**          FFALSE   no recordings are active
**
******************************************************************************/
fbool_t PVRSYS_IsRecording(void)
{
    fbool_t retVal = FFALSE;

    if(pvrDat != NULL)
    {
        /* -----in case of Record(s) running ------------------------------- */
        if(pvrDat->currStatus.numActiveRecs > 0)
        {
            retVal = FTRUE;
        }
    }
    return retVal;
}

/*!
*******************************************************************************
**
** \brief  Start a PVR record.
**
** \attention  It is assumed that the service to be recorded is already
**             selected on the target frontend. The passed service list
**             parameters are only used to get the service name and PIDs to
**             be recorded.
**
** \param   device      TODO
** \param   dirName     TODO
** \param   recordName  Name of recording.
** \param   servIdx     TODO
** \param   timerIdx    TODO
** \param   recIdx      TODO
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
** \sa PVRSYS_RecordStop
******************************************************************************/
int32_t PVRSYS_RecordStart (SYS_DEVICE_E device, const char_t* dirName,
                            SYS_STRING_S recordName, SLIST_SERVIDX servIdx,
                            RECTIMER_IDX timerIdx, uint8_t* recIdx)
{
    // TODO: timerIdx auf Gültigkeit abprüfen?

    return PVRSYS_IntRecPrepare (device, dirName, recordName, servIdx,
                                 timerIdx, 0, recIdx);
}

/*
maxFileSize is in units of Megabytes (1024 * 1024 Bytes)
*/
int32_t PVRSYS_RecordBackgroundStart (SYS_DEVICE_E device, const char_t* dirName,
                                      SYS_STRING_S recordName, SLIST_SERVIDX servIdx,
                                      uint32_t maxFileSize, uint8_t* recIdx)
{
    return PVRSYS_IntRecPrepare (device, dirName, recordName, servIdx,
                                 RECTIMER_INVALID, maxFileSize, recIdx);
}

#if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

int32_t PVRSYS_DescrRecordStart (SYS_DEVICE_E device, const char_t* dirName,
                                 SYS_STRING_S recordName, PVRLST_IDX idx,
                                 RECTIMER_IDX timerIdx, uint8_t* recIdx)
{
    PVRSYS_PLAYDAT_S*  play   = &(pvrDat->play);
    int32_t            retVal = FAPI_OK;
    PVR_LIST_ITEM_S    pvrItem;
    SYS_DEV_STAT_S     devStat;
    RSRC_CFG_S         opCfg;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    retVal = PVR_LIST_GetItemByIndex(idx, &pvrItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;

    /* is source device available? */
    retVal = SYS_DeviceGetStatus(pvrItem.device, &devStat);

    if ( (retVal != FAPI_OK) ||
         (devStat.mountStatus != SYS_DEV_FS_MOUNTED) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    retVal = RSRC_DescrRecordAvailable (idx, RSRC_OP_ANY & (~RSRC_OP_PLAY),
                                        NULL, &opCfg);
    if ( retVal != FAPI_OK ) return retVal;

    /* stop potentially running playback */
    retVal = PVRSYS_IntPlayStop(FTRUE, FTRUE);
    if ( retVal != FAPI_OK ) return retVal;

    /* If CAM is needed and available but blocked by another operation NOT
       using it, attempt to free path by rerouting other operations. */

    if ( (!(opCfg.useCi)) && ((opCfg.ciMatch[RSRC_TS_A]) ||
                              (opCfg.ciMatch[RSRC_TS_B])) )
    {
        (void)CISYS_FreeTsPathForCI (opCfg.ciMatch[RSRC_TS_A] ? RSRC_TS_A :
                                     RSRC_TS_B);

        retVal = RSRC_DescrRecordAvailable (idx, RSRC_OP_ANY & (~RSRC_OP_PLAY),
                                            NULL, &opCfg);
        if ( retVal != FAPI_OK ) return retVal;
    }

    /* ----- handle playback ----------------------------------------------- */

    (void)SYS_DeviceSetAccessStatus (pvrItem.device, FTRUE);

    #ifdef APPL_HDD_ENABLED

    /* Trigger HDD spinup in order to minimize playback startup time. */

    if ( pvrItem.device == SYS_DEV_HDD )
    {
        (void)HDD_Spinup (FFALSE, 0);
    }

    #endif /* APPL_HDD_ENABLED */

    play->active         = FTRUE;
    play->internal       = FTRUE;
    play->cfg            = opCfg;
    play->lstIdx         = idx;
    play->recIdx         = -1;
    play->pos            = PVRSYS_TIMESHIFT_BEGIN;
    play->mode           = PLAY_STATUS_NORMAL;
    play->speedIndex     = 0;
    play->filePos        = 0;
    play->rewindWait     = FTRUE;
    play->lockTrickModes = FTRUE;

    memset (&(play->strPref), 0, sizeof(play->strPref));

    play->strPref.langAudio = LANG_NOTSPECIFIED;
    play->strPref.spdifPref = FFALSE;
    play->strPref.langSpdif = LANG_NOTSPECIFIED;

    retVal = AV_DescrRecordStart (&opCfg);
    if ( retVal != FAPI_OK )
    {
        (void)SYS_DeviceSetAccessStatus (pvrItem.device, FFALSE);
        return retVal;
    }

    /* Ensure that A/V-commands issued by AV_DescrRecordStart have already been
       performed. */
    (void)AV_Nop();

    retVal = PVRSYS_IntPlayStart (NULL);
    if ( retVal != FAPI_OK )
    {
        AV_DescrRecordStop ();

        play->active = FFALSE;

        /* NOTE: releasing of device access via SYS_DeviceSetAccessStatus is
                 done in PVRSYS_IntDescrPlayStop, called by PVRSYS_IntPlayStart
                 on error! */

        return retVal;
    }

    /* ----- handle recording ---------------------------------------------- */

    retVal = PVR_IntDescrRecPrepare (device, dirName, recordName, &pvrItem,
                                     &opCfg, timerIdx, recIdx);
    if ( retVal != FAPI_OK )
    {
        PVRSYS_IntDescrPlayStop();

        /* NOTE: releasing of device access via SYS_DeviceSetAccessStatus is
                 done in PVRSYS_IntDescrPlayStop! */
    }

    return FAPI_OK;
}

int32_t PVRSYS_DescrRecReroute (const RSRC_CFG_S* cfg)
{
    PVRSYS_PLAYDAT_S*   play = &(pvrDat->play);
    PVRSYS_RECDAT_S*    pRecDat;
    PVR_PlayInfoT       playInf;
    int32_t             retVal;
    PVRLST_IDX          lstIdx;
    PVR_LIST_ITEM_S     pvrItem;
    uint8_t             recIndex;
    fbool_t             restartPlay;
    uint32_t            restartPos;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    FAPI_SYS_PRINT_DEBUG(1,"[PVR] Reroute DescrRec: TS %i,useCi %i\n", cfg->ts, cfg->useCi);

    if ( (!(play->active)) || (!(play->internal)) ) return FAPI_OK;

    retVal = PVRSYS_GetRecIndexByTsd(cfg->tsdIdx, &recIndex);
    if ( retVal != FAPI_OK ) return retVal;

    DBG_Assert(recIndex < RSRC_REC_MAX);

    pRecDat = pvrDat->rec + recIndex;

    /* store PVR list index for restarting of playback */
    lstIdx = play->lstIdx;

    retVal = PVR_LIST_GetItemByIndex(lstIdx, &pvrItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;

    /* --------------------------------------------------------------------- */

    retVal = AV_DescrRecordReroute (cfg);
    if ( retVal != FAPI_OK ) return retVal;

    pRecDat->cfg = *cfg;

    /* ----- restart playback from last position --------------------------- */

    restartPlay = FFALSE;
    restartPos  = 0;

    if ( play->handle != NULL )
    {
        if ( (PVR_GetPlaybackInfo (play->handle, &playInf) == FAPI_OK) &&
             (playInf.position < playInf.size) )
        {
            restartPlay = FTRUE;
            restartPos  = playInf.position;
        }
    }
    else
    {
        /* Playback operation not yet started. */
        restartPlay = FTRUE;
    }

    /* stop currently running internal playback */
    retVal = PVRSYS_IntDescrPlayStop();
    if ( retVal != FAPI_OK ) return retVal;

    if ( restartPlay )
    {
        (void)SYS_DeviceSetAccessStatus (pvrItem.device, FTRUE);

        #ifdef APPL_HDD_ENABLED

        /* Trigger HDD spinup in order to minimize playback startup time. */

        if ( pvrItem.device == SYS_DEV_HDD )
        {
            (void)HDD_Spinup (FFALSE, 0);
        }

        #endif /* APPL_HDD_ENABLED */

        play->active         = FTRUE;
        play->internal       = FTRUE;
        play->cfg            = *cfg;
        play->lstIdx         = lstIdx;
        play->recIdx         = -1;
        play->pos            = PVRSYS_TIMESHIFT_BEGIN;
        play->mode           = PLAY_STATUS_NORMAL;
        play->speedIndex     = 0;
        play->filePos        = restartPos;
        play->rewindWait     = FTRUE;
        play->lockTrickModes = FTRUE;

        memset (&(play->strPref), 0, sizeof(play->strPref));

        play->strPref.langAudio = LANG_NOTSPECIFIED;
        play->strPref.spdifPref = FFALSE;
        play->strPref.langSpdif = LANG_NOTSPECIFIED;

        /* Ensure that A/V-commands issued by PVRSYS_PlayStop have already been
           performed. */
        (void)AV_Nop();

        retVal = PVRSYS_IntPlayStart (NULL);
        if ( retVal != FAPI_OK )
        {
            play->active = FFALSE;

            /* NOTE: releasing of device access via SYS_DeviceSetAccessStatus is
                     done in PVRSYS_IntDescrPlayStop, called by
                     PVRSYS_IntPlayStart on error! */
        }
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_IntDescrPlayStop ()
{
    PVRSYS_PLAYDAT_S* play = &(pvrDat->play);
    PVR_LIST_ITEM_S   lstItem;
    int32_t           retVal;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (!(play->active)) || (!(play->internal)) ) return FAPI_OK;

    retVal = PVR_LIST_GetItemByIndex (play->lstIdx, &lstItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;

    if ( play->handle != NULL )
    {
        retVal = PVRSYS_PlayChangeMode (play->handle, PVR_PLAY_MODE_STOPPED, 0);
        if ( retVal != FAPI_OK ) return retVal;

        (void)PVR_ClosePlayback(play->handle);

        play->handle = NULL;
    }

    play->active        = FFALSE;
    play->internal      = FFALSE;
    play->audioMainIdx  = -1;
    play->audioSpdifIdx = -1;

    pvrDat->currStatus.play.type        = PLAY_TYPE_NONE;
    pvrDat->currStatus.play.status      = PLAY_STATUS_INACTIVE;
    pvrDat->currStatus.play.speedIndex  = 0;
    pvrDat->currStatus.play.speedFactor = 0;
    pvrDat->currStatus.play.recIdx      = -1;
    pvrDat->currStatus.play.lstIdx      = -1;

    (void)SYS_DeviceSetAccessStatus (lstItem.device, FFALSE);

    return FAPI_OK;
}

#endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

/*!
*******************************************************************************
**
** \brief  Stop recording.
**
** \return -
**
** \sa PVRSYS_RecordStart
******************************************************************************/
int32_t PVRSYS_RecordStop (int8_t recIdx, fbool_t keepFile)
{
    PVR_RecordInfoT     recInfo;
    PVRSYS_RECDAT_S*    pRecDat;
    int32_t             retVal;
    PVR_LIST_ITEM_S     lstItem;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( pvrDat->currStatus.numActiveRecs < 1 ) return FAPI_OK;

    if ( (recIdx < 0) || (recIdx >= RSRC_REC_MAX) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    pRecDat = pvrDat->rec + recIdx;

    if ( !(pRecDat->active) ) return FAPI_OK;

    memset (&recInfo, 0, sizeof(recInfo));

    if ( pRecDat->handle != NULL )
    {
        retVal = PVRSYS_RecSetModeAndWait (pRecDat->handle,
                                           PVR_RECORD_MODE_STOPPED);
        if ( retVal != FAPI_OK ) return retVal;

        retVal = PVR_GetRecordingInfo (pRecDat->handle, &recInfo);
        if ( retVal != FAPI_OK ) return retVal;

        (void)PVR_CloseRecording  (pRecDat->handle);

        pRecDat->handle = NULL;
    }

    pRecDat->active = FFALSE;

    switch ( pvrDat->currStatus.rec[recIdx].type )
    {
        default:
        case REC_TYPE_NORMAL:
        case REC_TYPE_BACKGROUND:
            (void)AV_RecordStop ((uint8_t)recIdx);
            break;

        #if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

        case REC_TYPE_DESCRREC:
            AV_DescrRecordStop ();
            break;

        #endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */
    }

    /* --------------------------------------------------------------------- */

    /* get recording information */
    retVal = PVR_LIST_GetItemByIndex (pRecDat->lstIdx , &lstItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;

    (void)SYS_DeviceSetAccessStatus(lstItem.device, FFALSE);

    /* keep record only if data has been recorded. */
    if ( keepFile && (recInfo.size > 0) )
    {
        /* add size and duration information */
        lstItem.size     = recInfo.size;
        lstItem.duration = TIME_ConvToTime(recInfo.duration / 1000);

        (void)PVR_LIST_SetItem (&lstItem, pRecDat->lstIdx, FTRUE);
    }
    else
    {
        (void)PVR_LIST_RemoveItemByIndex(pRecDat->lstIdx);
    }

    /* ----- handle assocatiated playback (descramble recording only) ------ */

    #if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

    if ( pvrDat->currStatus.rec[recIdx].type == REC_TYPE_DESCRREC )
    {
        PVRSYS_IntDescrPlayStop ();
    }

    #endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

    /* ----- update current PVR status ------------------------------------- */

    if ( pvrDat->currStatus.rec[recIdx].type == REC_TYPE_BACKGROUND )
    {
        /* remove background recording reference if background recording is
           stopped. */
        pvrDat->currStatus.bkgrRecIdx = -1;
    }

    pvrDat->currStatus.numActiveRecs--;

    pvrDat->currStatus.rec[recIdx].status   = REC_STATUS_INACTIVE;
    pvrDat->currStatus.rec[recIdx].type     = REC_TYPE_NONE;
    pvrDat->currStatus.rec[recIdx].timerIdx = RECTIMER_INVALID;
    pvrDat->currStatus.rec[recIdx].servIdx  = 0;

    /* Handle potentially pending playback request */
    if ( (pvrDat->play.active)         &&
         (pvrDat->play.handle == NULL) &&
         (pvrDat->play.recIdx == recIdx) )
    {
        (void)PVRSYS_IntPlayStop(FFALSE, FTRUE);
    }

    PVRSYS_SendRecEvent(PVR_REC_STOP, (uint8_t)recIdx); /* notify record end */
    return FAPI_OK;
}

/*lint -save -e661 */
int32_t PVRSYS_RecordReroute (const RSRC_CFG_S* cfg)
{
    PVRSYS_RECDAT_S*    pRecDat;
    uint8_t             recIndex;
    int32_t             retVal;

    FAPI_SYS_PRINT_DEBUG(1,"[PVR] Reroute Rec: TS %i,useCi %i\n", cfg->ts, cfg->useCi);

    retVal = PVRSYS_GetRecIndexByTsd(cfg->tsdIdx, &recIndex);
    if ( retVal != FAPI_OK ) return retVal;

    DBG_Assert(recIndex < RSRC_REC_MAX);

    pRecDat = pvrDat->rec + recIndex;

    if ( !(pRecDat->active) )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    retVal = AV_RecordReroute (cfg);
    if ( retVal != FAPI_OK ) return retVal;

    pRecDat->cfg = *cfg;

    return FAPI_OK;
}
/*lint -restore */

/*!
*******************************************************************************
**
** \brief  Start playback of currently recorded item ("timeshift").
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
******************************************************************************/
int32_t PVRSYS_PlayRecStart (int8_t recIdx, PVRSYS_TIMESHIFTPOS_E pos,
                             PVRSYS_PLAY_STATUS_E mode, int16_t speedIndex,
                             const SYS_PLAYPREF_S* pPref,
                             const RSRC_CFG_S* cfg)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (pvrDat->currStatus.numActiveRecs < 1) ||
         (recIdx <  0) ||
         (recIdx >= RSRC_REC_MAX) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    return PVRSYS_IntPlayPrepare (pvrDat->rec[recIdx].lstIdx, recIdx,
                                  PLAY_TYPE_TIMESHIFT, pos, mode, 0, speedIndex,
                                  pPref, cfg);
}

/*!
*******************************************************************************
**
** \brief   Start playback of a recorded item.
**
** \param   lstPos  Position in playback list.
** \param   filePos Start position in data chunks.
** \param   pPref   Optional stream preferences, set to NULL if not needed.
** \param   cfg     Optional resource configuration, if set to NULL default
**                  configuration will be generated internally.
**
** \return  One of the following status codes:
**          - #FAPI_OK if successful
**
** \sa
**          - PVRSYS_PlayStop()
**
******************************************************************************/
int32_t PVRSYS_PlayStart (int16_t lstPos, uint32_t filePos,
                          const SYS_PLAYPREF_S* pPref, const RSRC_CFG_S* cfg)
{
    int32_t     retVal;
    PVRLST_IDX  idx;

    retVal = PVR_LIST_GetIndex (lstPos, &idx);
    if ( retVal != FAPI_OK ) return retVal;
    return PVRSYS_PlayStartByIndex(idx, filePos, pPref, cfg);
}

int32_t PVRSYS_PlayStartByIndex (PVRLST_IDX idx, uint32_t filePos,
                                 const SYS_PLAYPREF_S* pPref,
                                 const RSRC_CFG_S* cfg)
{
    int32_t             retVal = FAPI_OK;
    PVRSYS_PLAY_TYPE_E  playType;
    int8_t              recIdx;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    retVal = PVR_LIST_GetItemByIndex(idx, NULL, &recIdx);
    if ( retVal != FAPI_OK ) return retVal;

    if ( recIdx >= 0 ) /* file is still being recorded */
    {
        playType = PLAY_TYPE_TIMESHIFT;
    }
    else /* file is not recorded anymore */
    {
        playType = PLAY_TYPE_NORMAL;
    }

    return PVRSYS_IntPlayPrepare (idx, recIdx, playType,
                                  PVRSYS_TIMESHIFT_BEGIN, PLAY_STATUS_NORMAL,
                                  filePos, 0, pPref, cfg);
}

/*!
*******************************************************************************
**
** \brief   Start playback of a recorded item.
**
** \param   path    The path of the plaback on filesystem. (e.g a:/PVR/REC_0001.
** \param   filePos Start position in data chunks.
** \param   pPref   Optional stream preferences, set to NULL if not needed.
** \param   cfg     Optional resource configuration, if set to NULL default
**                  configuration will be generated internally.
**
** \return  One of the following status codes:
**          - #FAPI_OK if successful
**          - #APPL_SMARTGO_ERR_BAD_PARAMETER if path is NULL.
**
** \sa
**          - PVRSYS_PlayStart()
**          - PVRSYS_PlayStop()
**
******************************************************************************/
int32_t PVRSYS_PlayStartByPath (const char_t* path,
                                uint32_t filePos,
                                const SYS_PLAYPREF_S* pPref,
                                const RSRC_CFG_S* cfg)
{
    int32_t     retVal;
    PVRLST_IDX  idx;

    if ( path == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    retVal = PVR_LIST_GetIndexByPath(path, &idx);

    if ( retVal == FAPI_OK )
    {
        retVal = PVRSYS_PlayStart (idx, filePos, pPref, cfg);
    }

    return retVal;
}

/*!
*******************************************************************************
**
** \brief   Stop playback.
**
** \return  One of the following status codes:
**          - #FAPI_OK
**          - #APPL_SMARTGO_ERR_NOT_INITIALIZED
**
** \sa PVRSYS_PlayStart
******************************************************************************/
int32_t PVRSYS_PlayStop (void)
{
    int32_t retVal;

    if ( pvrDat == NULL )
    {
        retVal = APPL_SMARTGO_ERR_NOT_INITIALIZED;
    }
    else
    {
        retVal = PVRSYS_IntPlayStop(FTRUE, FTRUE);
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_IntPlayStop (fbool_t userInitiated, fbool_t sendEvent)
{
    PVRSYS_PLAYDAT_S*   play = &(pvrDat->play);
    PVR_LIST_ITEM_S     lstItem;
    PVR_PlayInfoT       playInf;
    int32_t             retVal;

    if ( (!(play->active)) || (play->internal) ) return FAPI_OK;

    retVal = PVR_LIST_GetItemByIndex (play->lstIdx,
                                      &lstItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;

    if ( play->handle != NULL )
    {
        /* get current playback info */
        retVal = PVRSYS_PlayGetInfo(&playInf);
        if ( retVal != FAPI_OK ) return retVal;

        retVal = PVRSYS_PlayChangeMode (play->handle, PVR_PLAY_MODE_STOPPED, 0);
        if ( retVal != FAPI_OK ) return retVal;

        (void)PVR_ClosePlayback(play->handle);

        if ( playInf.position >= playInf.size )
        {
            lstItem.lastStop = -1;
        }
        else
        {
            lstItem.lastStop = (int32_t)playInf.position;
        }

        /* and write stop position to Meta Data file */
        (void)PVR_LIST_SetItem (&lstItem, play->lstIdx, FFALSE);

        #ifdef APPL_EDITMARKER_ENABLED

        /* write block marker data */
        PVR_LIST_SetMarker (play->lstIdx, &(play->blockMarkerData));

        #endif /* APPL_EDITMARKER_ENABLED */
    }

    play->active        = FFALSE;
    play->internal      = FFALSE;
    play->audioMainIdx  = -1;
    play->audioSpdifIdx = -1;

    pvrDat->currStatus.play.type        = PLAY_TYPE_NONE;
    pvrDat->currStatus.play.status      = PLAY_STATUS_INACTIVE;
    pvrDat->currStatus.play.speedIndex  = 0;
    pvrDat->currStatus.play.speedFactor = 0;
    pvrDat->currStatus.play.recIdx      = -1;
    pvrDat->currStatus.play.lstIdx      = -1;

    (void)AV_PlayStop();

    (void)SYS_DeviceSetAccessStatus(lstItem.device, FFALSE);

    if ( play->handle != NULL )
    {
        play->handle = NULL;

        if ( sendEvent )
        {
            PVRSYS_SendPbEvent (PVR_PLAY_STOP, &(pvrDat->currStatus.play),
                                userInitiated);
        }
    }

    return retVal;
}

int32_t PVRSYS_PlayReroute (const RSRC_CFG_S* cfg)
{
    PVRSYS_PLAYDAT_S*   play   = &(pvrDat->play);
    PVR_PlayInfoT       playInf;
    int32_t             retVal;

    FAPI_SYS_PRINT_DEBUG(1,"[PVR] Reroute Play: TS %i,useCi %i\n", cfg->ts, cfg->useCi);

    if ( (!(play->active)) || (play->internal) ) return FAPI_OK;

    retVal = PVRSYS_PlayGetInfo (&playInf);

    if ( retVal == FAPI_OK )
    {
        if ( playInf.position < playInf.size )
        {
            play->rerouting = FTRUE;

            /* (Re-)start playback from last position */
            retVal = PVRSYS_PlayStartByIndex (play->lstIdx, playInf.position,
                                              NULL, cfg);

            play->rerouting = FFALSE;

            // to do: adjust positioning for circular files?
        }
        else
        {
            (void)PVRSYS_IntPlayStop(FFALSE, FTRUE);
        }
    }

    return retVal;
}

/*!
*******************************************************************************
**
** \brief  Modify playback mode.
**
** \param  mode   One of the following playback modes
**                - PLAY_STATUS_NORMAL
**                - PLAY_STATUS_PAUSE
**                - PLAY_STATUS_FAST
**                - PLAY_STATUS_SLOW
** \param  speedIndex  Speed argument used for modes PLAY_STATUS_FAST and
**                     PLAY_STATUS_SLOW in the following way:
**                     - PLAY_STATUS_SLOW: 0...(PVRSYS_PLAYMODE_SF_NUMS-1)
**                     - PLAY_STATUS_FAST: 0...(PVRSYS_PLAYMODE_FF_NUMS-1)
**                                              for forward modes
**                                        -1...(-PVRSYS_PLAYMODE_FR_NUMS)
**                                              for backwards modes.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
** \sa PVRSYS_PlayModeGet
******************************************************************************/
int32_t PVRSYS_PlaySetMode (PVRSYS_PLAY_STATUS_E mode, int16_t speedIndex)
{
    int32_t retVal = FAPI_OK;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (pvrDat->play.handle == NULL) ||
         (pvrDat->play.internal) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }
    // FIXME: still needed?
    if ( (pvrDat->play.lockTrickModes) && (mode == PLAY_STATUS_SLOW) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    retVal = PVRSYS_IntPlaySetMode (pvrDat->play.handle, mode, speedIndex,
                                    pvrDat->play.internal);

    if ( retVal == FAPI_OK )
    {
        PVRSYS_SendPbEvent (PVR_PLAY_MODECHANGE, &(pvrDat->currStatus.play),
                            FTRUE);
    }

    return retVal;
}


/*!
*******************************************************************************
**
** \brief   Jump to absolute or relative position
**
** This function allows to jump from current read out position of a recorded
** file either to a relative or absolute position. The jump value can be
** of type time or data chunks. A relative jump can have a negative jumValue,
** an absolute jump not.
**
** \param   jumpValue   Either blocks or seconds
** \param   jumpMode    Requested jump mode.
**
** \return  One of the following status codes:
**          - #FAPI_OK if successful
**          - #APPL_SMARTGO_ERR_NOT_INITIALIZED
**          - #APPL_SMARTGO_ERR_BAD_PARAMETER
**          - #SMARTGO_SYS_ERR_INTERNAL
**
** \sa
******************************************************************************/
int32_t PVRSYS_PlayJump (int32_t jumpValue, PVRSYS_JUMP_MODE_E jumpMode)
{
    PVRSYS_PLAYDAT_S*   play      = &(pvrDat->play);
    int32_t             retVal    = FAPI_OK;
    PVR_SeekModeT       seekMode  = PVR_SEEK_MODE_CHUNKS;
    uint32_t            seekValue = 0;
    PVR_PlayInfoT       playInfo;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (play->handle == NULL) ||
         (play->internal) ) return SMARTGO_SYS_ERR_PROHIBITED;

    switch ( jumpMode )
    {
        case PVR_JUMP_DATA_REL:

            if ( jumpValue < 0 )
            {
                seekValue = (uint32_t)(-1 * jumpValue);
                seekMode  = PVR_SEEK_MODE_CHUNKS_BACKWARD;
            }
            else
            {
                seekValue = (uint32_t)(jumpValue);
                seekMode  = PVR_SEEK_MODE_CHUNKS_FORWARD;
            }
            break;

        case PVR_JUMP_DATA_ABS:

            if ( jumpValue < 0 )
            {
                retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            }
            else
            {
                seekValue = (uint32_t)jumpValue;
                seekMode  = PVR_SEEK_MODE_CHUNKS;
            }
            break;

        case PVR_JUMP_TIME_REL:

            retVal = PVR_GetPlaybackInfo (play->handle, &playInfo);

            if ( retVal == FAPI_OK )
            {
                seekValue = (uint32_t)(playInfo.time / 1000);

                if ( (jumpValue < 0)
                  && ((-1 * jumpValue) > (int32_t)seekValue) )
                {
                    seekValue = 0;
                }
                else
                {
                    /*lint -save -e737 */
                    seekValue = (uint32_t)
                                ((seekValue + jumpValue) * 1000);
                    /*lint -restore */
                }

                seekMode = PVR_SEEK_MODE_TIME;
            }
            break;

        case PVR_JUMP_TIME_ABS:

            if ( jumpValue < 0 )
            {
                retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            }
            else
            {
                seekValue = (uint32_t)(jumpValue * 1000); /* convert to ms */
            }

            seekMode = PVR_SEEK_MODE_TIME;
            break;

        case PVR_JUMP_IFRAME_AND_LOCK:

            if ( jumpValue < 0 )
            {
                seekMode  = PVR_SEEK_MODE_IFRAME_BACKWARD;
                seekValue = 0; /* parameter is unused for this mode */
            }
            else
            {
                seekMode  = PVR_SEEK_MODE_IFRAME_FORWARD;
                seekValue = 0; /* parameter is unused for this mode */
            }
            break;

        default:
            retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            break;
    }

    if ( retVal == FAPI_OK )
    {
        retVal = PVRSYS_PlaySeek (play->handle, seekMode, seekValue,
                                  play->internal);
    }

    return retVal;
}

/*!
*******************************************************************************
**
** \brief  Seek to start of playback file.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
******************************************************************************/
int32_t PVRSYS_PlaySeekToStart()
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (pvrDat->play.handle == NULL) ||
         (pvrDat->play.internal) ) return SMARTGO_SYS_ERR_PROHIBITED;

    return PVRSYS_PlaySeek (pvrDat->play.handle, PVR_SEEK_MODE_CHUNKS, 0,
                            pvrDat->play.internal);
}

/*!
*******************************************************************************
**
** \brief  Get information on current playback.
**
** \param  pInf  playback information data is returned here
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
******************************************************************************/
int32_t PVRSYS_PlayGetInfo (PVR_PlayInfoT* pInf)
{
    PVRSYS_PLAYDAT_S*   play   = &(pvrDat->play);
    int32_t             retVal = FAPI_OK;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;
    if ( pInf   == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    if ( play->rerouting )
    {
        /* Playback is being rerouted: pass last known playback info. */

        *pInf = play->playInfo;
    }
    else if ( (play->handle == NULL) || (play->internal) )
    {
        /* Playback not yet started: no information available. */

        retVal = SMARTGO_SYS_ERR_PROHIBITED;
    }
    else
    {
        retVal = PVR_GetPlaybackInfo (play->handle, pInf);

        if ( retVal == FAPI_OK )
        {
            if ( play->rewindWait )
            {
                /* Playback is being set up: pass last known playback
                   position. */

                pInf->time     = play->playInfo.time;
                pInf->offset   = play->playInfo.offset;
                pInf->position = play->playInfo.position;
            }
            else
            {
                play->playInfo = *pInf;
            }
        }
    }

    return retVal;
}

int32_t PVRSYS_PlayGetStreamInfo (SYS_STREAM_INFO_S* pInf)
{
    int32_t retVal = FAPI_OK;

    if ( pvrDat == NULL )
    {
        retVal = APPL_SMARTGO_ERR_NOT_INITIALIZED;
    }
    else if ( (pvrDat->play.handle == NULL) ||
              (pvrDat->play.internal) )
    {
        retVal = SMARTGO_SYS_ERR_PROHIBITED;
    }
    else if ( pInf != NULL )
    {
        *pInf = pvrDat->play.stream;
    }

    return retVal;
}

int32_t PVRSYS_PlayGetAudioStream (int8_t* index)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (pvrDat->play.handle == NULL) ||
         (pvrDat->play.internal) ) return SMARTGO_SYS_ERR_PROHIBITED;

    *index = pvrDat->play.audioMainIdx;
    return FAPI_OK;
}

int32_t PVRSYS_PlaySetAudioStream (int8_t index)
{
    PVRSYS_PLAYDAT_S*       play   = &(pvrDat->play);
    SYS_STREAMINF_AUDIO_S*  pAudio = &(play->stream.audio);
    SYS_EVT_AUDIO_S         ctrlEvent;
    SYS_LANGCODE            newPrefLang  = LANG_NOTSPECIFIED; /* satisfy MISRA */
    uint8_t                 reqTrack     = 0; /* satisfy MISRA */
    uint8_t                 reqTrackData = 0; /* satisfy MISRA */
    int32_t                 retVal       = FAPI_OK;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (play->handle == NULL)
      || (play->internal) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    if ( index < 0 )
    {
        reqTrack     = 0xFF;
        reqTrackData = 0;

        /* update language preference */
        newPrefLang = LANG_NOTSPECIFIED;
    }
    else if ( ((uint8_t)index) < pAudio->numStreams )
    {
        reqTrack     = play->audioRef[index];
        reqTrackData = pAudio->stream[index].channel;

        /* update language preference */
        newPrefLang  = pAudio->stream[index].langCode;
    }
    else
    {
        retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    if ( retVal == FAPI_OK )
    {
        retVal = PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_AUDIO,
                                       reqTrack, reqTrackData);

        if ( retVal == FAPI_OK )
        {
            play->audioMainIdx = index;

            play->strPref.langAudio = newPrefLang;

            ctrlEvent.hdr.type   = EVT_AUDIOSTREAM_CHANGED;
            ctrlEvent.hdr.length = sizeof(ctrlEvent);
            ctrlEvent.newIdx     = index;
            ctrlEvent.state      = SYS_PRESSTATE_PLAYBACK;

            (void)EVT_Send(&ctrlEvent, "Audio select");
        }
    }

    return retVal;
}

int32_t PVRSYS_PlayGetSPDIFStatus (AV_SPDIF_STATUS_E* type, int8_t* index)
{
    int32_t retVal = FAPI_OK;

    if ( pvrDat == NULL )
    {
        retVal = APPL_SMARTGO_ERR_NOT_INITIALIZED;
    }
    else if ( (pvrDat->play.handle == NULL) ||
              (pvrDat->play.internal) )
    {
        retVal = SMARTGO_SYS_ERR_PROHIBITED;
    }
    else if ( pvrDat->play.audioSpdifIdx < 0 )
    {
        if ( pvrDat->play.audioMainIdx < 0 )
        {
            *type  = SPDIFSTATUS_DISABLED;
            *index = -1;
        }
        else
        {
            *type  = SPDIFSTATUS_CURRPCM;
            *index = -1;
        }
    }
    else
    {
        *type  = SPDIFSTATUS_PASSTHROUGH;
        *index = pvrDat->play.audioSpdifIdx;
    }

    return retVal;
}

int32_t PVRSYS_PlaySetSPDIFStatus (AV_SPDIF_STATUS_E type, int8_t index)
{
    PVRSYS_PLAYDAT_S*       play     = &(pvrDat->play);
    SYS_STREAMINF_AUDIO_S*  pAudio   = &(play->stream.audio);
    SYS_EVT_SPDIF_S         ctrlEvent;
    int32_t                 retVal   = FAPI_OK;
    uint8_t                 reqTrack;

    if ( pvrDat == NULL )
    {
        return APPL_SMARTGO_ERR_NOT_INITIALIZED;
    }

    if ( (play->handle == NULL)
      || (play->internal) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    ctrlEvent.hdr.type   = EVT_SPDIFSTREAM_CHANGED;
    ctrlEvent.hdr.length = sizeof(ctrlEvent);
    ctrlEvent.state      = SYS_PRESSTATE_PLAYBACK;

    switch ( type )
    {
        default:
            retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            break;

        case SPDIFSTATUS_CURRPCM:
            retVal = PVR_SetPlaybackTrack (play->handle,
                                           PVR_DECTYPE_AUDIO_2ND, 0xFF,
                                           SYS_AUDIOCHAN_LEFT);
            if ( retVal == FAPI_OK )
            {
                play->audioSpdifIdx     = -1;

                play->strPref.spdifPref = FTRUE;
                play->strPref.spdifMode = SPDIFMODE_PCMONLY;
                play->strPref.langSpdif = play->strPref.langAudio;

                ctrlEvent.newIdx = -1;

                (void)EVT_Send(&ctrlEvent, "SPDIF select");
            }
            break;

        case SPDIFSTATUS_PASSTHROUGH:
            if ( index < 0 )
            {
                /* choose first compliant stream in list */
                index = AVINT_AudioSPDIFFindFirst (pAudio);
            }

            if ( (index < 0)
              || (index >= (int8_t)(pAudio->numStreams))
              || (!(AVINT_AudioIsSPDIFCompliant(pAudio->stream[index].
                                                format))) )
            {
                retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            }
            else
            {
                reqTrack = play->audioRef[index];

                retVal = PVR_SetPlaybackTrack (play->handle,
                                               PVR_DECTYPE_AUDIO_2ND,
                                               reqTrack, SYS_AUDIOCHAN_LEFT);

                if ( retVal == FAPI_OK )
                {
                    play->audioSpdifIdx     = index;

                    play->strPref.spdifPref = FTRUE;
                    play->strPref.spdifMode = SPDIFMODE_PREFERPASSTHROUGH;
                    play->strPref.langSpdif = pAudio->stream[index].langCode;

                    ctrlEvent.newIdx = index;

                    (void)EVT_Send(&ctrlEvent, "SPDIF select");
                }
            }
            break;
    }

    return retVal;
}

fbool_t PVRSYS_PlayPidAvailable (uint16_t pid)
{
    PVRSYS_PLAYDAT_S* play     = &(pvrDat->play);
    uint8_t           trackCnt = 0;
    PVR_TrackInfoT    trackInf;

    if ( pvrDat == NULL ) return FFALSE;

    if ( (pvrDat->play.handle == NULL) ||
         (pvrDat->play.internal) ) return FFALSE;

    if ( PVR_GetPlaybackTrackInfo (play->handle, &trackInf) != FAPI_OK )
    {
        return FFALSE;
    }

    while ( trackCnt < trackInf.numberOfTracks )
    {
        if ( trackInf.trackPid[trackCnt] == pid ) return FTRUE;

        trackCnt++;
    }

    return FFALSE;
}

/*!
*******************************************************************************
**
** \brief  Remove all entries of given device from PVR list.
**
** \param  device  Device that has been removed.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
** \sa PVRSYS_DeviceSyncDirectory, PVRSYS_SyncByPath, PVRSYS_SyncItem
******************************************************************************/
int32_t PVRSYS_DeviceRemoved (SYS_DEVICE_E device)
{
    FAPI_SYS_PRINT_DEBUG(4,"[PVR] Device removed: device %i \n", device);

    if ( (device >= SYS_DEV_NUMS) ||
         (device < (SYS_DEVICE_E)0) ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    pvrDat->devAvl &= (~((uint8_t)(0x01 << ((uint8_t)device))));

    return PVR_LIST_DeviceRemoved(device);
}

/*!
*******************************************************************************
**
** \brief  Scan directory on given device for PVR items.
**
** All existing entries referring to given directory are removed from PVR list
** before scanning for new items is performed.
**
** \param  device  Device to be scanned.
** \param  path    Directory relative to device's root directory to be synced.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
** \sa PVRSYS_DeviceRemoved, PVRSYS_SyncByPath, PVRSYS_SyncItem
******************************************************************************/
int32_t PVRSYS_DeviceSyncDirectory (SYS_DEVICE_E device, const char_t* path)
{
    FAPI_SYS_PRINT_DEBUG(4,"[PVR] Sync Directory '%s' (device %i) \n", path, device);

    if ( (device >= SYS_DEV_NUMS) ||
         (device < (SYS_DEVICE_E)0) ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    pvrDat->devAvl |= (0x01 << (uint8_t)device);

    return PVR_LIST_SyncDevice(device, path);
}

fbool_t PVRSYS_DeviceIsSynced (SYS_DEVICE_E device)
{
    fbool_t retVal;

    if ( (device >= SYS_DEV_NUMS)
      || (device < (SYS_DEVICE_E)0) )
    {
        retVal = FFALSE;
    }
    else
    {
        retVal = ((pvrDat->devAvl & (0x01 << (uint8_t)device)) != 0) ? FTRUE
                                                                     : FFALSE;
    }

    return retVal;
}

#ifdef APPL_EDITMARKER_ENABLED

/*!
*******************************************************************************
**
** \brief  Get block marker data of current playback.
**
**
** \param  pBlockData  pointer to PVR_BLOCK_MARKER_ITEM_S.
**
** \return One of the following status codes:
**         - #FAPI_OK                         if successful
**         - #APPL_SMARTGO_ERR_NOT_INITIALIZED local data structure not initialised
**         - #APPL_SMARTGO_ERR_BAD_PARAMETER  if param pointer is NULL
**         - #APPL_ERR_SMARTGO_DATA_NOT_AVL no data available
**
** \sa PVRSYS_DeviceRemoved, PVRSYS_SyncByPath, PVRSYS_SyncItem
******************************************************************************/
int32_t PVRSYS_PlayGetBlockData(PVR_BLOCK_MARKER_ITEM_S* pBlockData)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;
    if ( pBlockData == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    /* no valid data available if there is no active playback */
    if ( pvrDat->currStatus.play.type == PLAY_TYPE_NONE )
        return APPL_ERR_SMARTGO_DATA_NOT_AVL;

    *pBlockData = pvrDat->play.blockMarkerData;
    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Set block marker data of current playback.
**
**
** \param  blockData  data structure PVR_BLOCK_MARKER_ITEM_S.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
** \sa PVRSYS_DeviceRemoved, PVRSYS_SyncByPath, PVRSYS_SyncItem
******************************************************************************/
int32_t PVRSYS_PlaySetBlockData(PVR_BLOCK_MARKER_ITEM_S* pBlockData)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    /* makes no sense to write data because no playback is active */
    if ( pvrDat->currStatus.play.type == PLAY_TYPE_NONE )
        return APPL_ERR_SMARTGO_DATA_NOT_AVL;

    pvrDat->play.blockMarkerData = *pBlockData;
    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Read block marker data and initialise them to PVR lib
**
** All existing entries referring to given directory are removed from PVR list
** before scanning for new items is performed.
**
** \param  idx  index of type #PVRLST_IDX.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
**
** \sa PVRSYS_DeviceRemoved, PVRSYS_SyncByPath, PVRSYS_SyncItem
******************************************************************************/
int32_t PVRSYS_PlayOpenAndValidateBlockMarker(PVRLST_IDX  idx)
{
    int32_t     retVal;
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    /* makes no sense to continue because no playback is active */
    if ( pvrDat->currStatus.play.type == PLAY_TYPE_NONE )
        return APPL_ERR_SMARTGO_DATA_NOT_AVL;

    memset( &(pvrDat->play.blockMarkerData), 0, sizeof(PVR_BLOCK_MARKER_ITEM_S));
    retVal = PVR_LIST_GetMarkerByIdx(idx, &(pvrDat->play.blockMarkerData));
    if ( retVal != FAPI_OK ) return retVal;

    retVal = PVRSYS_PlayInitMarker (&(pvrDat->play.blockMarkerData.marker[0]),
                             ((uint32_t*)&(pvrDat->play.blockMarkerData.numBlockMarker)));
    if ( retVal != FAPI_OK ) return retVal;

    retVal = PVRSYS_PlayEnableMarker (FTRUE);
    return retVal;
}

#endif /* APPL_EDITMARKER_ENABLED */

/*!
*******************************************************************************
**
** \brief  Get information on current recording.
**
** \param  recIdx  Requested recording index.
** \param  pInfo   Record information data is returned here.
** \param  pParams Additional record information data is returned here.
**
** \return One of the following status codes:
**         - #FAPI_OK if successful
******************************************************************************/
int32_t PVRSYS_RecordGetInfo (int8_t recIdx, PVR_LIST_ITEM_S* pInfo,
                              PVR_RecordInfoT* pParams)
{
    int32_t retVal = FAPI_OK;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (recIdx < 0) || (recIdx >= RSRC_REC_MAX) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    if ( !(pvrDat->rec[recIdx].active) ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    if ( pInfo != NULL )
    {
        retVal = PVR_LIST_GetItemByIndex(pvrDat->rec[recIdx].lstIdx, pInfo,
                                         NULL);
        if ( retVal != FAPI_OK ) return retVal;
    }

    if ( pParams != NULL )
    {
        if ( pvrDat->rec[recIdx].handle == NULL )
        {
            /* Recording has not started yet */
            memset (pParams, 0, sizeof(PVR_RecordInfoT));
        }
        else
        {
            retVal = PVR_GetRecordingInfo (pvrDat->rec[recIdx].handle, pParams);
        }
    }

    return retVal;
}



/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

FSTATIC int32_t PVRSYS_SetFastModes (const PVRSYS_FastModeCfgT* pCfg,
                                     uint16_t* index)
{
    PVR_FastModeConfigT fmConfig;
    int32_t             retVal = FAPI_OK;
    uint16_t            cnt;

    memset (&fmConfig, 0, sizeof(fmConfig));

    for ( cnt = 0; cnt < PVRSYS_PLAYMODE_FAST_NUMS; cnt++ )
    {
        switch ( pCfg[cnt].videoMode )
        {
            case VAL_PLAYMODE_FAST_DEC_IP:
            case VAL_PLAYMODE_FAST_DEC_IONLY:
                fmConfig.type = PVR_FASTMODETYPE_FEED_ALL;
                break;

            case VAL_PLAYMODE_FAST_NOFEED:
                fmConfig.type                   = PVR_FASTMODETYPE_FEED_NONE;
                fmConfig.params.feedNone.factor = pCfg[cnt].factor;
                break;

            case VAL_PLAYMODE_FAST_CONTROLLEDFEED:
                fmConfig.type = PVR_FASTMODETYPE_FEED_CONTROLLED;
                fmConfig.params.feedCtrl.factor      = pCfg[cnt].factor;
                fmConfig.params.feedCtrl.displayTime = pCfg[cnt].
                                                       iFrameDisplayTime;
                break;

            default:
            case VAL_PLAYMODE_FAST_LIB_IONLY:
                fmConfig.type                       = PVR_FASTMODETYPE_IFRAMES;
                fmConfig.params.iFrames.factor      = pCfg[cnt].factor;
                fmConfig.params.iFrames.displayTime = pCfg[cnt].
                                                      iFrameDisplayTime;
                break;
        }

        retVal = PVR_SetFastModeConfig(*index + cnt, &fmConfig);
        if ( retVal != FAPI_OK ) break;
    }

    *index += cnt;

    return retVal;
}

FSTATIC int32_t PVRSYS_PlaySpeedToFastModeIdx (FAPI_SYS_HandleT playHandle,
                                               int16_t speedIndex,
                                               uint8_t* pModeIndex)
{
    int32_t         retVal;
    PVR_TrackInfoT  trackInfo;
    uint8_t         track   = 0xFF;
    int32_t         fastCfg = PVRSYS_FASTCFG_MPEG;

    if ( (speedIndex < (-PVRSYS_PLAYMODE_FR_NUMS))
      || (speedIndex >=  PVRSYS_PLAYMODE_FF_NUMS) )
    {
        retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
    }
    else
    {
        retVal = PVR_GetPlaybackTrack (playHandle, PVR_DECTYPE_VIDEO,
                                       &track);

        if ( retVal == FAPI_OK )
        {
            retVal = PVR_GetPlaybackTrackInfo (playHandle, &trackInfo);

            if ( retVal == FAPI_OK )
            {
                switch ( trackInfo.trackFormat[track] )
                {
                    default:
                    case PVR_TRACK_FORMAT_VIDEO_MPEG1:
                    case PVR_TRACK_FORMAT_VIDEO_MPEG2:
                        fastCfg = PVRSYS_FASTCFG_MPEG;
                        break;

                    case PVR_TRACK_FORMAT_VIDEO_H264:
                        fastCfg = PVRSYS_FASTCFG_H264;
                        break;
                }
            }
        }
#if 0
        else if ( retVal == SUBSYS_PVR_ERR_NO_TRACK_ASSIGNED )
        {
            fastCfg = PVRSYS_FASTCFG_NOVIDEO;
            retVal  = FAPI_OK;
        }
#endif
    }

    if ( retVal == FAPI_OK )
    {
        *pModeIndex = (uint8_t)((fastCfg * PVRSYS_PLAYMODE_FAST_NUMS)
                                + speedIndex + PVRSYS_PLAYMODE_FR_NUMS);
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_PlayFastModeIdxToSpeed (uint8_t modeIndex,
                                               int16_t* pSpeed)
{
    int32_t retVal;

    if ( modeIndex >= (PVRSYS_FASTCFG_NUMS * PVRSYS_PLAYMODE_FAST_NUMS) )
    {
        retVal = SMARTGO_SYS_ERR_INTERNAL;
    }
    else
    {
        *pSpeed = (modeIndex % PVRSYS_PLAYMODE_FAST_NUMS)
                  -  PVRSYS_PLAYMODE_FR_NUMS;

        retVal = FAPI_OK;
    }

    return retVal;
}

uint16_t PVRSYS_PlayGetFastSpeedFactor (uint8_t modeIndex)
{
    uint16_t speedFactor = 0;

    if ( modeIndex < (PVRSYS_FASTCFG_NUMS * PVRSYS_PLAYMODE_FAST_NUMS) )
    {
        speedFactor = pFastCfg[modeIndex / PVRSYS_PLAYMODE_FAST_NUMS]
                              [modeIndex % PVRSYS_PLAYMODE_FAST_NUMS].
                              speedFactor;
    }

    return speedFactor;
}

uint16_t PVRSYS_PlayGetSlowSpeedFactor (uint8_t modeIndex)
{
    PVRSYS_SlowModeCfgT modeCfg;

    modeCfg.speedFactor = 0;

    (void)PVRSYS_GetSlowModeConfig (modeIndex, &modeCfg);

    return modeCfg.speedFactor;
}


int32_t PVRSYS_GetFastModeConfig (uint16_t index, PVRSYS_FastModeCfgT* cfgPtr)
{
    int32_t result;

    if ( index >= (PVRSYS_FASTCFG_NUMS * PVRSYS_PLAYMODE_FAST_NUMS) )
    {
        result = APPL_SMARTGO_ERR_BAD_PARAMETER;
    }
    else
    {
        *cfgPtr = pFastCfg[index / PVRSYS_PLAYMODE_FAST_NUMS]
                          [index % PVRSYS_PLAYMODE_FAST_NUMS];

        result = FAPI_OK;
    }

    return result;
}

int32_t PVRSYS_GetSlowModeConfig (uint16_t index, PVRSYS_SlowModeCfgT* cfgPtr)
{
    memset(cfgPtr, 0, sizeof(PVRSYS_SlowModeCfgT));

    switch ( index )
    {
        case 0:
            cfgPtr->videoMode   = VAL_PLAYMODE_SLOW_2X;
            cfgPtr->speedFactor = 2;
            break;

        case 1:
            cfgPtr->videoMode   = VAL_PLAYMODE_SLOW_4X;
            cfgPtr->speedFactor = 4;
            break;

        default:
            cfgPtr->videoMode   = VAL_PLAYMODE_SLOW_8X;
            cfgPtr->speedFactor = 8;
            break;
    }

    return FAPI_OK;
}

FSTATIC int32_t PVRSYS_PlayWaitForTransitionEnd (FAPI_SYS_HandleT handle)
{
    PVR_PlayModeT   playMode;
    int32_t         retVal;
    uint64_t        tStart = UTILS_GetTimerStamp();

    do
    {
        retVal = PVR_GetPlaybackMode (handle, &playMode, NULL);

        if ( retVal != FAPI_OK )
        {
            return retVal;
        }

        if ( playMode != PVR_PLAY_MODE_CHANGING ) return FAPI_OK;

        FAPI_SYS_SLEEP (PVR_TIMEOUT_SLEEPTIME);
    }
    while ( UTILS_GetTimerStampInterval(tStart, UTILS_GetTimerStamp())
            < PVR_LIB_TIMEOUT );

    FAPI_SYS_PRINT_DEBUG(2,"PVRSYS_PlayWaitForTransitionEnd: Timeout \n");

    return APPL_SMARTGO_ERR_TIMEOUT;
}

FSTATIC int32_t PVRSYS_RecWaitForTransitionEnd (FAPI_SYS_HandleT handle)
{
    PVR_RecordModeT recMode;
    int32_t         retVal;
    uint64_t        tStart = UTILS_GetTimerStamp();

    do
    {
        retVal = PVR_GetRecordingMode (handle, &recMode);

        if ( retVal != FAPI_OK )
        {
            return retVal;
        }

        if ( recMode != PVR_RECORD_MODE_CHANGING ) return FAPI_OK;

        FAPI_SYS_SLEEP (PVR_TIMEOUT_SLEEPTIME);
    }
    while ( UTILS_GetTimerStampInterval(tStart, UTILS_GetTimerStamp())
            < PVR_LIB_TIMEOUT );

    FAPI_SYS_PRINT_DEBUG(2,"PVRSYS_RecWaitForTransitionEnd: Timeout \n");

    return APPL_SMARTGO_ERR_TIMEOUT;
}

FSTATIC int32_t PVRSYS_PlayChangeMode (FAPI_SYS_HandleT handlePlay,
                                       PVR_PlayModeT mode, uint8_t modeIndex)
{
    PVR_PlayModeT   playMode;
    uint8_t         playModeIndex;
    PVR_PlayModeT   lastPlayMode;
    int32_t         retVal;
    uint64_t        tStart = UTILS_GetTimerStamp();
    fbool_t         timeout;

    retVal = PVR_GetPlaybackMode (handlePlay, &playMode, &playModeIndex);

    if ( retVal == FAPI_OK )
    {
        if ( (playMode      != mode)
          || (playModeIndex != modeIndex) )
        {
            lastPlayMode = playMode;

            (void)PVR_SetPlaybackMode (handlePlay, mode, modeIndex);

            timeout = FTRUE;

            do
            {
                retVal = PVR_GetPlaybackMode (handlePlay, &playMode,
                                              &playModeIndex);

                if ( retVal != FAPI_OK )
                {
                    break;
                }
                else if ( (playMode      == mode)
                       && (playModeIndex == modeIndex) )
                {
                    /* requested mode successfully set */
                    timeout = FFALSE;
                    break;
                }
                else if ( (playMode != lastPlayMode)
                       && (playMode != PVR_PLAY_MODE_CHANGING) )
                {
                    /* mode has been changed by pvr_lib, set requested mode
                       again */
                    lastPlayMode = playMode;

                    (void)PVR_SetPlaybackMode (handlePlay, mode, modeIndex);
                }

                FAPI_SYS_SLEEP (PVR_TIMEOUT_SLEEPTIME);
            }
            while ( UTILS_GetTimerStampInterval(tStart, UTILS_GetTimerStamp())
                    < PVR_LIB_TIMEOUT );

            if ( (retVal == FAPI_OK) && timeout )
            {
                retVal = APPL_SMARTGO_ERR_TIMEOUT;

                FAPI_SYS_PRINT_DEBUG(2,"[PVR] PVRSYS_PlayChangeMode %i: Timeout \n", mode);
            }
        }
    }

    FAPI_SYS_PRINT_DEBUG(4,"[PVR] Change to mode %i index %i: result %i\n", mode,
               modeIndex, retVal);
    return retVal;
}

FSTATIC int32_t PVRSYS_PlayWaitForMode (FAPI_SYS_HandleT handlePlay,
                                        PVR_PlayModeT mode, uint8_t modeIndex)
{
    PVR_PlayModeT   playMode;
    uint8_t         playModeIndex;
    int32_t         retVal;
    uint64_t        tStart = UTILS_GetTimerStamp();

    do
    {
        retVal = PVR_GetPlaybackMode (handlePlay, &playMode, &playModeIndex);

        if ( retVal != FAPI_OK )
        {
            return retVal;
        }

        if ( (playMode      == mode)
          && (playModeIndex == modeIndex) ) return FAPI_OK;

        FAPI_SYS_SLEEP(PVR_TIMEOUT_SLEEPTIME);
    }
    while ( UTILS_GetTimerStampInterval(tStart, UTILS_GetTimerStamp())
            < PVR_LIB_TIMEOUT );

    FAPI_SYS_PRINT_DEBUG(2,"[PVR] PVRSYS_PlayWaitForMode: Timeout \n");

    return APPL_SMARTGO_ERR_TIMEOUT;
}

FSTATIC int32_t PVRSYS_RecSetModeAndWait (FAPI_SYS_HandleT handle,
                                          PVR_RecordModeT mode)
{
    PVR_RecordModeT recMode;
    PVR_RecordModeT lastRecMode;
    int32_t         retVal;
    uint64_t        tStart = UTILS_GetTimerStamp();
    fbool_t         timeout;

    retVal = PVR_GetRecordingMode (handle, &recMode);

    if ( retVal == FAPI_OK )
    {
        if ( recMode != mode )
        {
            lastRecMode = recMode;

            (void)PVR_SetRecordingMode (handle, mode);

            timeout = FTRUE;

            do
            {
                retVal = PVR_GetRecordingMode (handle, &recMode);

                if ( retVal != FAPI_OK )
                {
                    break;
                }
                else if ( recMode == mode )
                {
                    /* requested mode successfully set */
                    timeout = FFALSE;
                    break;
                }
                else if ( (recMode != lastRecMode)
                       && (recMode != PVR_RECORD_MODE_CHANGING) )
                {
                    /* mode has been changed by pvr_lib, set requested mode
                       again */
                    lastRecMode = recMode;

                    (void)PVR_SetRecordingMode (handle, mode);
                }

                FAPI_SYS_SLEEP (PVR_TIMEOUT_SLEEPTIME);
            }
            while ( UTILS_GetTimerStampInterval(tStart, UTILS_GetTimerStamp())
                    < PVR_LIB_TIMEOUT );

            if ( (retVal == FAPI_OK) && timeout )
            {
                retVal = APPL_SMARTGO_ERR_TIMEOUT;

                FAPI_SYS_PRINT_DEBUG(2,"[PVR] PVRSYS_RecSetModeAndWait %i: Timeout \n", mode);
            }
        }
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_RecWaitForStart (uint8_t recIdx)
{
    PVR_RecordInfoT recInfo;
    int32_t         retVal;
    uint64_t        tStart = UTILS_GetTimerStamp();

    if ( pvrDat->rec[recIdx].handle == NULL )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    do
    {
        retVal = PVR_GetRecordingInfo (pvrDat->rec[recIdx].handle, &recInfo);

        if ( retVal != FAPI_OK )
        {
            return retVal;
        }

        /* wait for first data chunk to be written to target device */
        if ( recInfo.size > 0 ) return FAPI_OK;

        FAPI_SYS_SLEEP (PVR_TIMEOUT_SLEEPTIME);
    }
    while ( UTILS_GetTimerStampInterval(tStart, UTILS_GetTimerStamp())
            < PVR_LIB_TIMEOUT );

    FAPI_SYS_PRINT_DEBUG(2,"[PVR] PVRSYS_RecWaitForStart: Timeout \n");

    return APPL_SMARTGO_ERR_TIMEOUT;
}


FSTATIC int32_t PVRSYS_PlaySeek (FAPI_SYS_HandleT handle, PVR_SeekModeT mode,
                                 uint32_t value, fbool_t internal)
{
    PVR_PlayModeT playMode;
    int32_t       retVal;
    fbool_t       modeChanged = FFALSE;



    do
    {
        retVal = PVRSYS_PlayWaitForTransitionEnd (handle);

        if ( retVal != FAPI_OK )
        {
            break;
        }

        retVal = PVR_GetPlaybackMode(handle, &playMode, NULL);

        if ( retVal != FAPI_OK )
        {
            break;
        }

        /* to avoid discontinuous packet disable subtt and ttx*/
        #ifdef APPL_SUBTT_ENABLED
        SUBTT_Enable   (FFALSE, SYS_SUSPENDSRC_PLAY);
        #endif /* APPL_SUBTT_ENABLED */

        #ifdef APPL_TTXT_ENABLED
        TTXSUBTT_Enable(FFALSE, SYS_SUSPENDSRC_PLAY);
        #endif /* APPL_TTXT_ENABLED */

        if ( (playMode != PVR_PLAY_MODE_PAUSE)
          && (playMode != PVR_PLAY_MODE_STOPPED) )
        {
            retVal = PVRSYS_PlayChangeMode (handle, PVR_PLAY_MODE_PAUSE, 0);
            if ( retVal != FAPI_OK )
            {
                break;
            }

            modeChanged = FTRUE;
        }

        retVal = PVR_SeekPlayback (handle, mode, value);

        if ( retVal != FAPI_OK )
        {
            break;
        }

        if ( modeChanged )
        {
            retVal = PVRSYS_PlayWaitForMode (handle, PVR_PLAY_MODE_PAUSE, 0);
        }
        else
        {
            retVal = PVRSYS_PlayWaitForTransitionEnd (handle);
        }

        if ( (retVal == FAPI_OK) && (!internal) )
        {
            /* Playback position has changed: Trigger refresh of EIT events */
            (void)EIT_RequestNewEvents(NULL);
        }

    } while(0);

    #ifdef APPL_SUBTT_ENABLED
    SUBTT_Enable(FTRUE, SYS_SUSPENDSRC_PLAY );
    #endif /* APPL_SUBTT_ENABLED */

    #ifdef APPL_TTXT_ENABLED
    TTXSUBTT_Enable(FTRUE, SYS_SUSPENDSRC_PLAY);
    #endif /* APPL_TTXT_ENABLED */

    return retVal;
}

FSTATIC int32_t PVRSYS_RecGetFileEndPos (int8_t recIdx, uint32_t* position)
{
    PVR_RecordInfoT recInfo;
    int32_t         retVal;

    if ( (recIdx < 0) || (recIdx >= RSRC_REC_MAX) )
    {
        retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
    }
    else if ( pvrDat->rec[recIdx].handle == NULL )
    {
        retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
    }
    else
    {
        retVal = PVR_GetRecordingInfo(pvrDat->rec[recIdx].handle, &recInfo);

        if ( retVal == FAPI_OK )
        {
            /* NOTE: This is OK for both normal and circular recordings. Once a
                     circular file has looped for the first time, size
                     parameter will not increase anymore. */
            *position = recInfo.size;

            if ( *position > 0 ) (*position)--;
        }
    }

    return retVal;
}

/*
timerIdx: if RECTIMER_INVALID record is background recording!
maxFileSize: 0: linear recording, > 0: circular recording
*/
/*lint -save -e661 */
FSTATIC int32_t PVRSYS_IntRecPrepare (SYS_DEVICE_E device, const char_t* dirName,
                                      SYS_STRING_S recordName,
                                      SLIST_SERVIDX servIdx,
                                      RECTIMER_IDX timerIdx, uint32_t maxFileSize,
                                      uint8_t* recIdx)
{
    int32_t            retVal = FAPI_OK;
    RSRC_CFG_S         recCfg;
    uint8_t            recIndex;
    PVRSYS_RECDAT_S*   pRecDat;
    PVR_LIST_ITEM_S    lstItem;
    fbool_t            hasSynced;
    SYS_DEV_STAT_S     devStat;

    if ( pvrDat == NULL )
    {
        return APPL_SMARTGO_ERR_NOT_INITIALIZED;
    }

    if ( (device >= SYS_DEV_NUMS) ||
         (device < (SYS_DEVICE_E)0) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    /* is target device available? */
    retVal = SYS_DeviceGetStatus(device, &devStat);

    if ( (retVal != FAPI_OK) ||
         (devStat.mountStatus != SYS_DEV_FS_MOUNTED) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    if ( pvrDat->currStatus.numActiveRecs >= RSRC_REC_MAX )
    {
        return SMARTGO_SYS_ERR_RSRC_RECORD;
    }
    else if ( (timerIdx == RECTIMER_INVALID) &&
              (pvrDat->currStatus.bkgrRecIdx != -1) )
    {
        /* background record requested and already running */
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    retVal = RSRC_ServiceAvlForRecord(servIdx, RSRC_OP_ANY, NULL, &recCfg);
    if ( retVal != FAPI_OK ) return retVal;

    retVal = PVRSYS_GetRecIndexByTsd(recCfg.tsdIdx, &recIndex);
    if ( retVal != FAPI_OK ) return retVal;

    DBG_Assert(recIndex < RSRC_REC_MAX);

    pRecDat = pvrDat->rec + recIndex;

    if ( (pRecDat->active) || (pRecDat->handle != NULL) )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    pRecDat->addCaStreams = FFALSE;
    pRecDat->toBeDescr    = FFALSE;

    memset (&(pRecDat->pmt), 0, sizeof(pRecDat->pmt));
    memset (&(pRecDat->cat), 0, sizeof(pRecDat->cat));

    /* --------------------------------------------------------------------- */

    memset (&lstItem, 0, sizeof(lstItem));

    retVal = SLIST_GetServByIndex (servIdx, &(lstItem.service));
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    lstItem.device   = device;
    lstItem.lastStop = -1;          /* initialize last stop position */
    lstItem.flags    = 0;

    /* check if CA information must be included in order to be used for TS
       playback. */

    #ifdef APPL_CI_ENABLED

    /* NOTE: CA streams are added to recording if the following preconditions
             are met:
             - Service is not to be descrambled during recording by embedded CA.
             - Service is potentially scrambled.
             - TS playback feature is available for at least one CI input.
    */

    if ( (recCfg.cas == RSRC_CAS_NONE) &&
         CISYS_TSPlaybackAvailable() )
    {
        (void)SLIST_CaInfoGet (servIdx, &(lstItem.caInfo));

        if ( lstItem.caInfo.numIds > 0 )
        {
            pRecDat->addCaStreams = FTRUE;
        }
    }

    #endif /* APPL_CI_ENABLED */

    /* NOTE: PVR_LIST_FLAG_SCRAMBLED will be updated if CAM is removed during
             recording. */

    if ( (lstItem.caInfo.numIds > 0)    &&
         (recCfg.cas == RSRC_CAS_NONE)  &&
         (!(recCfg.useCi)) )
    {
        lstItem.flags |= PVR_LIST_FLAG_SCRAMBLED;
    }

    if ( (lstItem.caInfo.numIds > 0) &&
         recCfg.useCi )
    {
        pRecDat->toBeDescr = FTRUE;
    }

    /* check if circular or linear recording is requested */
    if ( maxFileSize > 0 ) /* circular recording */
    {
        /* invalidate timer index */
        timerIdx = RECTIMER_INVALID;
    }

    /* ----- setup record list item ---------------------------------------- */

    /* Store requested recording name. */
    (void)STR_Copy (recordName, lstItem.name, &(lstItem.nameCharSet),
                    recordName.cs, PVR_NAME_LENGTH);

    /* If name is not available, try service name */
    if ( STR_IsEmpty (STR_Build(lstItem.nameCharSet, lstItem.name)) )
    {
        (void)STR_Copy (STR_Build(lstItem.service.nameCharSet,
                            lstItem.service.name),
                  lstItem.name, &(lstItem.nameCharSet),
                  lstItem.service.nameCharSet, PVR_NAME_LENGTH);
    }

    if ( timerIdx == RECTIMER_INVALID )
    {
        lstItem.type = REC_TYPE_BACKGROUND;
    }
    else
    {
        lstItem.type = REC_TYPE_NORMAL;
    }

    /* store start time and date */
    retVal = TIME_TimeAndDateGetUtc (&(lstItem.startTime),
                                     &(lstItem.startDate), &hasSynced);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }
    else if ( !hasSynced )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    /* ----- prepare recording --------------------------------------------- */

    pRecDat->lstIdx = -1;

    do
    {
        retVal = PVR_LIST_AddRecordItem (&lstItem, recIndex, dirName,
                                         &(pRecDat->lstIdx));
        if ( retVal != FAPI_OK ) break;

        retVal = AV_RecordStart (&recCfg);
        if ( retVal != FAPI_OK ) break;

        #ifdef APPL_HDD_ENABLED

        /* Trigger HDD spinup in order to minimize recording startup time. */

        if ( device == SYS_DEV_HDD )
        {
            retVal = HDD_Spinup (FFALSE, 0);
            if ( retVal != FAPI_OK ) break;
        }

        #endif /* APPL_HDD_ENABLED */

    } while ( 0 );

    if ( retVal != FAPI_OK )
    {
        (void)AV_RecordStop (recIndex);

        if ( pRecDat->lstIdx >= 0 )
        {
            (void)PVR_LIST_RemoveItemByIndex(pRecDat->lstIdx);
        }

        return retVal;
    }

    /* ----- update current PVR status ------------------------------------- */

    (void)SYS_DeviceSetAccessStatus(device, FTRUE);

    pvrDat->currStatus.numActiveRecs++;
    pvrDat->currStatus.rec[recIndex].status   = REC_STATUS_ACTIVE;
    pvrDat->currStatus.rec[recIndex].timerIdx = timerIdx;
    pvrDat->currStatus.rec[recIndex].servIdx  = servIdx;

    /* background recording */
    if ( pvrDat->currStatus.rec[recIndex].timerIdx == RECTIMER_INVALID )
    {
        pvrDat->currStatus.rec[recIndex].type = REC_TYPE_BACKGROUND;
        pvrDat->currStatus.bkgrRecIdx         = (int8_t)recIndex;
    }
    else /* normal recording */
    {
        pvrDat->currStatus.rec[recIndex].type = REC_TYPE_NORMAL;
    }

    PVRSYS_SendRecEvent(PVR_REC_START, recIndex); /* notify record start */

    pRecDat->active       = FTRUE;
    pRecDat->internal     = FFALSE;
    pRecDat->cfg          = recCfg;
    pRecDat->maxFileSize  = maxFileSize;
    pRecDat->servIdx      = servIdx;

    *recIdx = recIndex;

    return FAPI_OK;
}
/*lint -restore */

FSTATIC int32_t PVRSYS_IntRecStart (uint8_t recIdx, const PSISI_PMT_S* pPmt)
{
    PVRSYS_RECDAT_S*    pRecDat = pvrDat->rec + recIdx;
    int32_t             retVal  = FAPI_OK;
    PVR_RecordOpenT     recOpen;
    PVR_LIST_ITEM_S     lstItem;
    fbool_t             pidChange; /* unused */

    if ( !(pRecDat->active) ||
          (pRecDat->handle != NULL) ) return SMARTGO_SYS_ERR_INTERNAL;

    /* ----- all required tables available? -------------------------------- */

    if ( !(pRecDat->pmt.available) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    #ifdef APPL_CI_ENABLED

    /* check if CAT is needed and if it is available: needed for TS playback
       via CI feature only. */

    if ( pRecDat->addCaStreams )
    {
        if ( !(pRecDat->cat.sect.allAvailable) )
        {
            return SMARTGO_SYS_ERR_PROHIBITED;
        }
    }

    #endif /* APPL_CI_ENABLED */

    /* ----- setup recording parameters ------------------------------------ */

    /* NOTE: With these settings, stream will be stored TS-compliant in
             little-endian byte order. */

    memset (&recOpen, 0, sizeof(recOpen));

    recOpen.version = PVR_VERSION;

    switch ( recIdx )
    {
        case 0:  recOpen.threadPriority = THREAD_PRIO_PVR_REC_HI; break;
        default: recOpen.threadPriority = THREAD_PRIO_PVR_REC_LO; break;
    }

    recOpen.tsdBlockIndex = pRecDat->cfg.tsdIdx;
    recOpen.overwrite     = 1;
    recOpen.callback      = PVRSYS_RecCallback;
    recOpen.bufferAddress = pRecDat->bufAddr;
    recOpen.bufferSize    = PVRSYS_BUFREC_SIZE;

    /* check if circular or linear recording is requested */
    if ( pRecDat->maxFileSize > 0 ) /* circular recording */
    {
        /* Calculate number of data chunks needed.
           NOTE: The following calculation avoids overflows. */
        recOpen.maxSize  = (pRecDat->maxFileSize / PVR_CHUNK_SIZE) *
                           1024 * 1024;

        if ( (pRecDat->maxFileSize % PVR_CHUNK_SIZE) > 0 )
        {
            recOpen.maxSize += ((pRecDat->maxFileSize % PVR_CHUNK_SIZE)
                               * 1024 * 1024) / PVR_CHUNK_SIZE;
            recOpen.maxSize++;
        }

        recOpen.enableLooping  = 1;
    }
    else /* linear recording */
    {
        recOpen.maxSize        = 0;             /* no size limit */
        recOpen.enableLooping  = 0;             /* no circular recording */
    }

    recOpen.fillingLimit       = 0;             /* no notification */
    recOpen.tag                = 0;
    recOpen.fileSplitSize      = PVR_FATFS_FILESIZE_MAX / PVR_CHUNK_SIZE;

    /* --------------------------------------------------------------------- */

    do
    {
        retVal = PVR_LIST_GetItemByIndex(pRecDat->lstIdx, &lstItem, NULL);
        if ( retVal != FAPI_OK ) break;

        retVal = PVR_LIST_GetFilename (pRecDat->lstIdx, recOpen.fileName,
                                       PVR_FILE_NAME_LENGTH + 1);
        if ( retVal != FAPI_OK ) break;

        retVal = SYS_DevicePreAccess (lstItem.device);
        if ( retVal != FAPI_OK ) break;

        retVal = PVRSYS_SetMountPath (lstItem.device);
        if ( retVal != FAPI_OK ) break;

        retVal = PVRSYS_RecAssignTracks (pRecDat, &recOpen);
        if ( retVal != FAPI_OK ) break;

        retVal = PVRSYS_RecSetTracks (pRecDat, &recOpen, &pidChange);
        if ( retVal != FAPI_OK ) break;

        (void)STR_Copy (STR_Build(lstItem.nameCharSet, lstItem.name),
                        recOpen.name, NULL, SYS_CHARSET_ASCII,
                        // FIXME: + 1 necessary here ?
                        PVR_NAME_LENGTH + 1);

        pRecDat->handle = PVR_OpenRecording(&recOpen, &retVal);
        if ( pRecDat->handle == NULL )
        {
            retVal = SMARTGO_SYS_ERR_INTERNAL;
            break;
        }

        #ifdef PVRSYS_ENCRYPTION_ENABLED

        retVal = PVR_EnableRecordingEncryption (pRecDat->handle,
                                                &(pvrDat->cryptoParams));
        if ( retVal != FAPI_OK ) break;

        #endif /* PVRSYS_ENCRYPTION_ENABLED */

        retVal = PVR_SetRecordingPmt (pRecDat->handle, pPmt->pid,
                                     (uint8_t*)(pPmt->buf), pPmt->bufSize,
                                     NULL, NULL);
        if ( retVal != FAPI_OK ) break;

        retVal = PVR_SetFlushingFrequency(pRecDat->handle, PVRSYS_FLUSH_CHUNKS);
        if ( retVal != FAPI_OK ) break;

        retVal = PVR_SetRecordingPerfLimitTimeout (pRecDat->handle,
                                                   PVR_PERFLIMIT_TIMEOUT);
        if ( retVal != FAPI_OK ) break;

        if ( (pRecDat->internal)   &&
             (pvrDat->play.active) &&
             (pvrDat->play.handle != NULL) )
        {
            (void)PVR_SetRecordingSourcePlayback (pvrDat->play.handle,
                                                  pRecDat->handle);
        }

        (void)PVR_SetRecordingMode (pRecDat->handle, PVR_RECORD_MODE_NORMAL);

        retVal = PVRSYS_RecWaitForTransitionEnd(pRecDat->handle);
        if ( retVal != FAPI_OK ) break;
    }
    while ( 0 );

    /* Handle potentially pending playback request */
    if ( (pvrDat->play.active)         &&
         (pvrDat->play.handle == NULL) &&
         (pvrDat->play.recIdx == recIdx) )
    {
        if ( retVal == FAPI_OK )
        {
            (void)PVRSYS_IntPlayStart(pPmt);
        }
        else
        {
            (void)PVRSYS_IntPlayStop(FFALSE, FTRUE);
        }
    }

    if ( retVal != FAPI_OK )
    {
        if ( pRecDat->handle != NULL )
        {
            (void)PVR_CloseRecording(pRecDat->handle);
            pRecDat->handle = NULL;
        }
    }

    return retVal;
}

/*
cfg - Can be used to optionally pass an already available resource
      configuration. If set to NULL, function will generate a standard
      configuration internally.
*/
FSTATIC int32_t PVRSYS_IntPlayPrepare (PVRLST_IDX idx, int8_t recIdx,
                                       PVRSYS_PLAY_TYPE_E type,
                                       PVRSYS_TIMESHIFTPOS_E pos,
                                       PVRSYS_PLAY_STATUS_E mode,
                                       uint32_t filePos, int16_t speedIndex,
                                       const SYS_PLAYPREF_S* pPref,
                                       const RSRC_CFG_S* cfg)
{
    PVRSYS_PLAYDAT_S*   play   = &(pvrDat->play);
    int32_t             retVal = FAPI_OK;
    PVR_LIST_ITEM_S     pvrItem;
    SYS_DEV_STAT_S      devStat;
    SLIST_SERVIDX       servIdx;
    PSISI_PMT_S         currRecPmt;
    RSRC_CFG_S          playCfg;
    fbool_t             freezeVideo;

    retVal = PVR_LIST_GetItemByIndex(idx, &pvrItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;
    /* is requested recording available? */
    if ( (recIdx >= 0) &&
         (!(pvrDat->rec[recIdx].active)) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    /* is source device available? */
    retVal = SYS_DeviceGetStatus(pvrItem.device, &devStat);

    if ( (retVal != FAPI_OK) ||
         (devStat.mountStatus != SYS_DEV_FS_MOUNTED) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    if ( cfg != NULL )
    {
        playCfg = *cfg;
    }
    else
    {
        retVal = RSRC_PlaybackAvailable (idx,
                                         RSRC_OP_ANY &
                                         (~(RSRC_OP_LIVE | RSRC_OP_PLAY)),
                                         NULL, &playCfg);
        if ( retVal != FAPI_OK ) return retVal;
    }

    /* ----- stop running presentation ------------------------------------- */

    if ( (type == PLAY_TYPE_TIMESHIFT) && (recIdx >= 0) )
    {
        freezeVideo = FTRUE;
    }
    else
    {
        freezeVideo = FFALSE;
    }

    retVal = SYS_StopPresentation (RSRC_OP_LIVE | RSRC_OP_PLAY, freezeVideo);
    if ( retVal != FAPI_OK ) return retVal;

    /* --------------------------------------------------------------------- */

    if ( (type == PLAY_TYPE_TIMESHIFT) && (recIdx >= 0) )
    {
        servIdx = pvrDat->currStatus.rec[recIdx].servIdx;
    }
    else
    {
        servIdx = SLIST_SERVIDX_PLAY;
    }

    retVal = AV_PlayStart(idx, servIdx, &playCfg);
    if ( retVal != FAPI_OK ) return retVal;

    (void)SYS_DeviceSetAccessStatus(pvrItem.device, FTRUE);

    #ifdef APPL_HDD_ENABLED

    /* Trigger HDD spinup in order to minimize playback startup time. */

    if ( pvrItem.device == SYS_DEV_HDD )
    {
        (void)HDD_Spinup (FFALSE, 0);
    }

    #endif /* APPL_HDD_ENABLED */

    play->active         = FTRUE;
    play->internal       = FFALSE;
    play->cfg            = playCfg;
    play->lstIdx         = idx;
    play->recIdx         = recIdx;
    play->pos            = pos;
    play->mode           = mode;
    play->speedIndex     = speedIndex;
    play->filePos        = filePos;
    play->lockTrickModes = FTRUE;

    if ( pos == PVRSYS_TIMESHIFT_BEGIN )
    {
        play->rewindWait = FTRUE;
    }
    else
    {
        play->rewindWait = FFALSE;
    }

    if ( !(play->rerouting) )
    {
        memset (&(play->playInfo), 0, sizeof(play->playInfo));
    }

    if ( pPref != NULL )
    {
        play->strPref = *pPref;
    }
    else
    {
        memset (&(play->strPref), 0, sizeof(play->strPref));

        play->strPref.langAudio = LANG_NOTSPECIFIED;
        play->strPref.spdifPref = FFALSE;
        play->strPref.langSpdif = LANG_NOTSPECIFIED;
    }

    /* Ensure that commands issued by AV_PlayStart have already been
       performed. */
    (void)AV_Nop();

    /* test if playback can be directly started: Either the source is not
       a current recording or the requested recording has already been
       started. */
    if ( recIdx < 0 )
    {
        retVal = PVRSYS_IntPlayStart(NULL);
    }
    else if ( pvrDat->rec[recIdx].handle != NULL )
    {
        /* Special timeshift backwards playback handling: pass current
           recording PMT if available */
        if ( (pos == PVRSYS_TIMESHIFT_END) &&
             (PSISI_PMT_Get(pvrDat->rec[recIdx].cfg.tsdIdx, &currRecPmt) ==
             FAPI_OK) )
        {
            retVal = PVRSYS_IntPlayStart(&currRecPmt);
        }
        else
        {
            retVal = PVRSYS_IntPlayStart(NULL);
        }
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_IntPlayStart (const PSISI_PMT_S* pPmt)
{
    PVRSYS_PLAYDAT_S*  play   = &(pvrDat->play);
    int32_t            retVal = FAPI_OK;
    PVR_LIST_ITEM_S    pvrItem;
    PVR_PlayOpenT      playOpen;
    PVR_RecordInfoT    recInfo;
    uint32_t           position = 0;
    uint8_t            numRetries = PVR_TIMEOUT_RETRIES;

    if ( !(play->active) ||
          (play->handle != NULL) ) return SMARTGO_SYS_ERR_INTERNAL;

    retVal = PVR_LIST_GetItemByIndex(play->lstIdx, &pvrItem, NULL);
    if ( retVal != FAPI_OK ) return retVal;

    if ( play->recIdx >= 0 )
    {
        /* ensure that data has already been recorded before starting
           playback */
        retVal = PVRSYS_RecWaitForStart ((uint8_t)(play->recIdx));
        if ( retVal != FAPI_OK ) return retVal;
    }

    do
    {
        memset (&playOpen, 0, sizeof(playOpen));

        playOpen.version = PVR_VERSION;

        retVal = PVR_LIST_GetFilename (play->lstIdx, playOpen.fileName,
                                       PVR_FILE_NAME_LENGTH + 1);
        if ( retVal != FAPI_OK ) break;

        /* open playback */

        playOpen.readThreadPriority     = THREAD_PRIO_PVR_PLAY_READ;
        playOpen.feedThreadPriority     = THREAD_PRIO_PVR_PLAY_FEED;
        playOpen.tsdBlockIndex          = play->cfg.tsdIdx;
        playOpen.iFrameBufferAddress    = play->bufAddr;
        playOpen.iFrameBufferSize       = PVRSYS_BUFPLAY_SIZE;

        /* NOTE: This parameter is currently unused in pvr_lib. */
        playOpen.bufferToCheck          = 0;

        // TODO: this handling is to be changed!
        #if 0
        /* Prevent PVR lib from resetting video decoder when:
           - starting timeshift playback (last live video frame remains).
           - starting offline descrambling (does not use video decoder at all).
        */

        if ( (play->recIdx >= 0) || (play->internal) )
        {
            playOpen.initVideoDecoderAlways = 0;
        }
        else
        {
            playOpen.initVideoDecoderAlways = 1;
        }

        #else

        /* NOTE: This parameter is currently unused in pvr_lib. */
        playOpen.initVideoDecoderAlways = 0;

        #endif

        if ( !(play->internal) )
        {
            playOpen.callback = (PVR_PlayCallback)PVRSYS_PlayCallback;
        }
        else if ( !(play->cfg.useCi) )
        {
            /* In case of internal playback without CI, data is fed internally
               (faster than realtime) to TSD. This is why buffer 31 must be
               prevented from overflowing. */

            // to do: does not work yet!
            //playOpen.bufferToCheck = 31;
        }

        /* attach decoder interface functions */
        PVRDEC_RegisterFunctions (&(playOpen.targetControl));

        /* ----------------------------------------------------------------- */

        retVal = SYS_DevicePreAccess (pvrItem.device);
        if ( retVal != FAPI_OK ) break;

        (void)FAPI_SYNC_SetEnvironment(FAPI_SYNC_VIDEO_PTS_BASED);

        (void)PVRSYS_SetMountPath(pvrItem.device);

        /*lint -save -e506 */
        do
        {
            play->handle = PVR_OpenPlayback(&playOpen, &retVal);

            if ( play->handle != NULL )
            {
                break;
            }
#if 0
            else if ( retVal != SUBSYS_PVR_ERR_FILE_HANDLING )
            {
                /* NOTE: Above error code is possible when playing file
                         currently being recorded. No date has been written
                         to file yet. */
                break;
            }
#endif

            FAPI_SYS_SLEEP (PVR_TIMEOUT_SLEEPTIME);

            if ( (numRetries--) == 0 )
            {
                retVal = APPL_SMARTGO_ERR_TIMEOUT;
                break;
            }

        } while ( 1 );
        /*lint -restore */

        if ( retVal != FAPI_OK )
        {
            break;
        }

        #ifdef PVRSYS_ENCRYPTION_ENABLED

        retVal = PVR_EnablePlaybackDecryption (play->handle,
                                               &(pvrDat->cryptoParams));
        if ( retVal != FAPI_OK ) break;

        #endif /* PVRSYS_ENCRYPTION_ENABLED */

        /* ----------------------------------------------------------------- */

        if ( pPmt != NULL )
        {
            (void)PVRSYS_PlayUpdateStreams(pPmt);

            PVRSYS_PlayRewindPosition(play);
        }
        else
        {
            /* all streams disabled until first PMT is received! */

            (void)PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_VIDEO,
                                        0xFF, 0);
            (void)PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_AUDIO,
                                        0xFF, 0);
            (void)PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_AUDIO_2ND,
                                        0xFF, 0);

            play->audioMainIdx   = -1;
            play->audioSpdifIdx  = -1;
        }

        /* ----------------------------------------------------------------- */

        #if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

        if ( (play->cfg.useCi) &&
             (play->cfg.ciInput == FAPI_BOARD_RSRC_CIIN_TSGEN) )
        {
            FAPI_SYS_PRINT_DEBUG(1,"[PVR] Use external TS playback! \n");

            (void)PVR_SetPlaybackFunction (play->handle, PVR_TsFeedData);
        }

        #endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

        retVal = FAPI_OK;

        if ( play->recIdx >= 0 )
        {
            pvrDat->currStatus.play.type   = PLAY_TYPE_TIMESHIFT;
            pvrDat->currStatus.play.recIdx = play->recIdx;

            switch ( play->pos )
            {
                default:
                case PVRSYS_TIMESHIFT_BEGIN:

                    retVal = PVR_GetRecordingInfo (pvrDat->rec[play->recIdx].
                                                   handle, &recInfo);

                    if ( retVal == FAPI_OK )
                    {
                        /*  NOTE: On circular recording place read pointer some
                                  chunks ahead of the write pointer to avoid
                                  becoming chased up. */
                        if ( recInfo.hasLooped ) position = 10;
                        else                     position = 0;
                    }
                    break;

                case PVRSYS_TIMESHIFT_CURRRECPOS:

                    retVal = PVR_GetRecordingInfo (pvrDat->rec[play->recIdx].
                                                   handle, &recInfo);

                    if ( retVal == FAPI_OK )
                    {
                        position = recInfo.position;

                        if ( position > 0 ) position--;
                    }
                    break;

                case PVRSYS_TIMESHIFT_END:

                    retVal = PVRSYS_RecGetFileEndPos(play->recIdx, &position);

                    if ( retVal == FAPI_OK )
                    {
                        /* reduce position by 1 to avoid sudden End Of File
                           reached */
                        if ( position > 0 ) position --;
                    }
                    break;
            }

            if ( retVal != FAPI_OK ) break;
        }
        else if ( !(play->internal) )
        {
            pvrDat->currStatus.play.type   = PLAY_TYPE_NORMAL;
            pvrDat->currStatus.play.recIdx = -1;

            position = play->filePos;
        }
        else
        {
            /* internal playback used for descrambled recording, do not set
               states */

            position = play->filePos;
        }

        retVal = PVRSYS_PlaySeek (play->handle, PVR_SEEK_MODE_CHUNKS,
                                  position, play->internal);
        if ( retVal != FAPI_OK ) break;

        retVal = PVRSYS_IntPlaySetMode (play->handle, play->mode,
                                        play->speedIndex, play->internal);
        if ( retVal != FAPI_OK ) break;

        if ( !(play->internal) )
        {
            pvrDat->currStatus.play.lstIdx = play->lstIdx;

            #ifdef APPL_EDITMARKER_ENABLED

            /* read block marker data */
            (void)PVR_PlayOpenAndValidateBlockMarker(pvrDat->currStatus.play.
                                                     lstIdx);

            #endif /* APPL_EDITMARKER_ENABLED */

            /* Trigger refresh of EIT events */
            (void)EIT_RequestNewEvents(NULL);

            PVRSYS_SendPbEvent (PVR_PLAY_START, &(pvrDat->currStatus.play),
                                FTRUE);
        }
    }
    while ( 0 );

    if ( retVal != FAPI_OK )
    {
        if ( !(play->internal) )
        {
            (void)PVRSYS_IntPlayStop(FTRUE, FFALSE);
        }

        #if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

        else
        {
            PVRSYS_IntDescrPlayStop();
        }

        #endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_IntPlaySetMode (FAPI_SYS_HandleT playHandle,
                                       PVRSYS_PLAY_STATUS_E mode,
                                       int16_t speedIndex, fbool_t internal)
{
    int32_t         retVal;
    PVR_PlayModeT   reqMode       = PVR_PLAY_MODE_CHANGING; /* satisfy MISRA */
    uint8_t         reqModeIndex  = 0;
    PVR_PlayModeT   currMode      = PVR_PLAY_MODE_NORMAL;
    uint8_t         currModeIndex = 0;
    PVR_PlayInfoT   playInfo;
    fbool_t         setStopPos   = FFALSE;
    fbool_t         clearStopPos = FFALSE;
    uint16_t        speedFactor  = 0;

    #if (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
    fbool_t         subttEnable  = FFALSE;
    #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) */

    retVal = PVR_GetPlaybackMode (playHandle, &currMode, &currModeIndex);

    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    switch ( mode )
    {
        case PLAY_STATUS_NORMAL:
            reqMode      = PVR_PLAY_MODE_NORMAL;
            reqModeIndex = 0;
            speedFactor  = 1;
            clearStopPos = FTRUE;

            #if (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)
            subttEnable  = FTRUE;
            #endif /* (defined APPL_SUBTT_ENABLED)
                   || (defined APPL_TTXT_ENABLED) */
            break;

        case PLAY_STATUS_PAUSE:
            reqMode      = PVR_PLAY_MODE_PAUSE;
            reqModeIndex = 0;
            speedFactor  = 0;
            setStopPos   = FTRUE;
            break;

        case PLAY_STATUS_FAST:

            reqMode = PVR_PLAY_MODE_FAST;

            retVal = PVRSYS_PlaySpeedToFastModeIdx (playHandle, speedIndex,
                                                    &reqModeIndex);

            if ( retVal == FAPI_OK )
            {
                speedFactor  = PVRSYS_PlayGetFastSpeedFactor(reqModeIndex);
            }

            clearStopPos = FTRUE;
            break;

        case PLAY_STATUS_SLOW:

            if ( (speedIndex <  0)
              || (speedIndex >= PVRSYS_PLAYMODE_SF_NUMS) )
            {
                retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            }
            else
            {
                reqMode      = PVR_PLAY_MODE_SLOW;
                reqModeIndex = (uint8_t)speedIndex;
                speedFactor  = PVRSYS_PlayGetSlowSpeedFactor(reqModeIndex);
                clearStopPos = FTRUE;
            }
            break;

        default:
            retVal = APPL_SMARTGO_ERR_BAD_PARAMETER;
            break;
    }

    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    if ( (reqMode == currMode) && (reqModeIndex == currModeIndex) )
    {
        /* requested mode is already set */
        return FAPI_OK;
    }

    /* Set record stop position if a pause mode is requested */
    if ( (!internal)                                             &&
         setStopPos                                              &&
         (pvrDat->currStatus.play.type   == PLAY_TYPE_TIMESHIFT) &&
         (pvrDat->currStatus.play.recIdx >= 0) )
    {
        if ( PVR_GetPlaybackInfo (playHandle, &playInfo) == FAPI_OK )
        {
            (void)PVR_SetRecordingStopPos (pvrDat->rec[pvrDat->currStatus.play.
                                           recIdx].handle, playInfo.position);
        }
    }

    retVal = PVRSYS_PlayChangeMode (playHandle, reqMode, reqModeIndex);

    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    if ( !internal )
    {
        // FIXME: extend on other modes as well? why only slow and normal?
        if ( (reqMode == PVR_PLAY_MODE_NORMAL)
          || (reqMode == PVR_PLAY_MODE_SLOW) )
        {
            /* Trigger refresh of EIT events */
            (void)EIT_RequestNewEvents(NULL);
        }

        /* Clear record stop position if a non-pause mode is requested */
        if ( clearStopPos &&
             (pvrDat->currStatus.play.type   == PLAY_TYPE_TIMESHIFT) &&
             (pvrDat->currStatus.play.recIdx >= 0) )
        {
            (void)PVR_SetRecordingStopPos (pvrDat->rec[pvrDat->currStatus.play.
                                           recIdx].handle, 0xFFFFFFFF);
        }

        pvrDat->currStatus.play.status      = mode;
        pvrDat->currStatus.play.speedIndex  = speedIndex;
        pvrDat->currStatus.play.speedFactor = speedFactor;
    }

    #if (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED)

    if ( internal ) subttEnable = FFALSE;

    #endif /* (defined APPL_SUBTT_ENABLED) || (defined APPL_TTXT_ENABLED) */

    #ifdef APPL_SUBTT_ENABLED

    SUBTT_Enable (subttEnable, SYS_SUSPENDSRC_PLAY);

    #endif /* APPL_SUBTT_ENABLED */

    #ifdef APPL_TTXT_ENABLED

    TTXSUBTT_Enable (subttEnable, SYS_SUSPENDSRC_PLAY);

    #endif /* APPL_TTXT_ENABLED */

    return retVal;
}

#if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

FSTATIC int32_t PVRSYS_IntDescrRecPrepare (SYS_DEVICE_E device,
                                           const char_t* dirName,
                                           SYS_STRING_S recordName,
                                           const PVR_LIST_ITEM_S* pLstItem,
                                           const RSRC_CFG_S* cfg,
                                           RECTIMER_IDX timerIdx,
                                           uint8_t* recIdx)
{
    int32_t             retVal = FAPI_OK;
    PVRSYS_PLAYDAT_S*   play   = &(pvrDat->play);
    PVRSYS_RECDAT_S*    pRecDat;
    uint8_t             recIndex;
    SYS_DEV_STAT_S      devStat;
    PVR_LIST_ITEM_S     lstItem;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( (device >= SYS_DEV_NUMS) ||
         (device < (SYS_DEVICE_E)0) )
    {
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    /* is target device available? */
    retVal = SYS_DeviceGetStatus(device, &devStat);

    if ( (retVal != FAPI_OK) ||
         (devStat.mountStatus != SYS_DEV_FS_MOUNTED) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    if ( pvrDat->currStatus.numActiveRecs >= RSRC_REC_MAX )
    {
        return SMARTGO_SYS_ERR_RSRC_RECORD;
    }
    else if ( timerIdx == RECTIMER_INVALID )
    {
        /* background record requested */
        return APPL_SMARTGO_ERR_BAD_PARAMETER;
    }

    retVal = PVRSYS_GetRecIndexByTsd(cfg->tsdIdx, &recIndex);
    if ( retVal != FAPI_OK ) return retVal;

    DBG_Assert(recIndex < RSRC_REC_MAX);

    pRecDat = pvrDat->rec + recIndex;

    if ( (pRecDat->active) || (pRecDat->handle != NULL) )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    pRecDat->addCaStreams = FFALSE;

    memset (&(pRecDat->pmt), 0, sizeof(pRecDat->pmt));
    memset (&(pRecDat->cat), 0, sizeof(pRecDat->cat));

    /* ----- setup record list item ---------------------------------------- */

    lstItem = *pLstItem;

    lstItem.device   = device;      /* update target device */
    lstItem.lastStop = -1;          /* intialize last stop position */

    /* check if source recording has content left to be descrambled. */

    pRecDat->toBeDescr = ((lstItem.flags & PVR_LIST_FLAG_SCRAMBLED) != 0) ?
                         FTRUE : FFALSE;

    /* NOTE: PVR_LIST_FLAG_SCRAMBLED will be updated if CAM is removed during
             recording. */

    if ( (lstItem.caInfo.numIds == 0)   ||
         (cfg->cas != RSRC_CAS_NONE)    ||
         (cfg->useCi) )
    {
        lstItem.flags &= (~PVR_LIST_FLAG_SCRAMBLED);
    }

    (void)STR_Copy (recordName, lstItem.name, &(lstItem.nameCharSet),
              recordName.cs, PVR_NAME_LENGTH);

    /* ----- prepare recording --------------------------------------------- */

    if ( lstItem.caInfo.numIds > 0 )
    {
        pRecDat->addCaStreams = FTRUE;
    }

    pRecDat->lstIdx = -1;

    do
    {
        retVal = PVR_LIST_AddRecordItem (&lstItem, recIndex, dirName,
                                         &(pRecDat->lstIdx));
        if ( retVal != FAPI_OK ) break;

        #ifdef APPL_HDD_ENABLED

        /* Trigger HDD spinup in order to minimize recording startup time. */

        if ( device == SYS_DEV_HDD )
        {
            retVal = HDD_Spinup (FFALSE, 0);
            if ( retVal != FAPI_OK ) break;
        }

        #endif /* APPL_HDD_ENABLED */

    } while ( 0 );

    if ( retVal != FAPI_OK )
    {
        if ( pRecDat->lstIdx >= 0 )
        {
            (void)PVR_LIST_RemoveItemByIndex(pRecDat->lstIdx);
        }

        return retVal;
    }

    /* ----- update current PVR status ------------------------------------- */

    (void)SYS_DeviceSetAccessStatus(device, FTRUE);

    pvrDat->currStatus.numActiveRecs++;
    pvrDat->currStatus.rec[recIndex].status   = REC_STATUS_ACTIVE;
    pvrDat->currStatus.rec[recIndex].timerIdx = timerIdx;
    pvrDat->currStatus.rec[recIndex].servIdx  = SLIST_SERVIDX_PLAY;
    pvrDat->currStatus.rec[recIndex].type     = REC_TYPE_DESCRREC;

    PVRSYS_SendRecEvent(PVR_REC_START, recIndex); /* notify record start */

    pRecDat->active       = FTRUE;
    pRecDat->internal     = FTRUE;
    pRecDat->cfg          = *cfg;
    pRecDat->maxFileSize  = 0;
    pRecDat->servIdx      = SLIST_SERVIDX_PLAY;

    *recIdx = recIndex;

    return FAPI_OK;
}

#endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */


/*lint -save -e774 */
FSTATIC int32_t PVRSYS_RecAssignTracks (PVRSYS_RECDAT_S* pRecDat,
                                        PVR_RecordOpenT* recOpen)
{
    uint8_t tracksCurr     = 0;
    uint8_t tracksMax      = PVR_MAX_TRACKS;
    uint8_t numTracks;

    if ( tracksMax > PVR_REC_TRACKS_MAX )
    {
        tracksMax = PVR_REC_TRACKS_MAX;
    }

    recOpen->numberOfTracks = tracksMax;

    /* initialize track array */
    for ( numTracks = 0; numTracks < tracksMax; numTracks++ )
    {
        recOpen->trackType  [numTracks] = PVR_TRACK_TYPE_OTHER;
        recOpen->trackInfo  [numTracks] = 0;
        recOpen->trackPid   [numTracks] = PVR_PID_NONE;
        recOpen->trackFormat[numTracks] = PVR_TRACK_FORMAT_OTHER;
    }

    /* Reserve track for EIT */
    if ( tracksCurr < tracksMax )
    {
        recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_OTHER;
    }

    /* Reserve track for CAT (+ SDT) */
    if ( pRecDat->addCaStreams )
    {
        if ( tracksCurr < tracksMax )
        {
            recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_OTHER;
        }

        #ifdef PVR_REC_ADD_SDT

        if ( tracksCurr < tracksMax )
        {
            recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_OTHER;
        }

        #endif /* PVR_REC_ADD_SDT */
    }

    for ( numTracks = 0; numTracks < PVR_REC_VIDEO_MAX; numTracks++ )
    {
        if ( tracksCurr >= tracksMax ) break;

        recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_VIDEO;
    }

    for ( numTracks = 0; numTracks < PVR_REC_AUDIO_MAX; numTracks++ )
    {
        if ( tracksCurr >= tracksMax ) break;

        recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_AUDIO;
    }

    for ( numTracks = 0; numTracks < PVR_REC_TTX_MAX; numTracks++ )
    {
        if ( tracksCurr >= tracksMax ) break;

        recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_TELETEXT;
    }

    for ( numTracks = 0; numTracks < PVR_REC_SUBTT_MAX; numTracks++ )
    {
        if ( tracksCurr >= tracksMax ) break;

        recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_SUBTITLES;
    }

    if ( pRecDat->addCaStreams )
    {
        for ( numTracks = 0; numTracks < PVR_REC_ECM_MAX; numTracks++ )
        {
            if ( tracksCurr >= tracksMax ) break;

            recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_ECM;
        }

        for ( numTracks = 0; numTracks < PVR_REC_EMM_MAX; numTracks++ )
        {
            if ( tracksCurr >= tracksMax ) break;

            recOpen->trackType[tracksCurr++] = PVR_TRACK_TYPE_EMM;
        }
    }

    return FAPI_OK;
}
/*lint -restore */

FSTATIC int32_t PVRSYS_RecSetTracks (PVRSYS_RECDAT_S* pRecDat,
                                     PVR_RecordOpenT* recOpen,
                                     fbool_t* pidChange)
{
    PSISI_PMT_STREAM_S      stream;
    PSISI_DESC_S            desc;
    SYS_STREAMINF_AUDIO_S   strAudio;
    uint8_t                 tracksCurr = 0;
    uint8_t                 endTrack;
    uint16_t                pmtPos;
    int32_t                 retVal;
    uint32_t                cnt;
    PSISI_PMT_S*            pPmt = &(pRecDat->pmt);
    uint16_t                pmtInfoLen;
    uint16_t                loopPos;
    uint16_t                trackPid;
    uint8_t                 trackFormat;

    *pidChange = FFALSE;

    /* ----- all required tables available? -------------------------------- */

    if ( !(pPmt->available) )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    #ifdef APPL_CI_ENABLED

    /* check if CAT is needed and if it is available: needed for TS playback
       via CI feature only. */

    if ( pRecDat->addCaStreams )
    {
        if ( !(pRecDat->cat.sect.allAvailable) )
        {
            return SMARTGO_SYS_ERR_PROHIBITED;
        }
    }

    #endif /* APPL_CI_ENABLED */

    /* ----- assign EIT stream --------------------------------------------- */

    /* Record EIT */
    if ( tracksCurr < recOpen->numberOfTracks )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, ISO_EIT_PID,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    /* Record CAT */
    if ( (pRecDat->addCaStreams) && (tracksCurr < recOpen->numberOfTracks) )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, ISO_CAT_PID,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    #ifdef PVR_REC_ADD_SDT

    /* Record SDT */
    if ( (pRecDat->addCaStreams) && (tracksCurr < recOpen->numberOfTracks) )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, ISO_SDT_PID,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    #endif /* PVR_REC_ADD_SDT */

    /* ----- assign video streams ------------------------------------------ */

    endTrack = tracksCurr + PVR_REC_VIDEO_MAX;
    if ( endTrack > recOpen->numberOfTracks )
    {
        endTrack = recOpen->numberOfTracks;
    }

    retVal = PSISI_PMT_StreamParseInit(pPmt, &pmtPos);
    if ( retVal != FAPI_OK ) return retVal;

    while ( PSISI_PMT_StreamParseGetNext(pPmt, &pmtPos, &stream)
            == FAPI_OK )
    {
        if ( tracksCurr >= endTrack ) break;

        switch ( stream.type )
        {
            case STRTYPE_VIDEO_MPEG1:
                trackFormat = PVR_TRACK_FORMAT_VIDEO_MPEG1;
                break;

            case STRTYPE_VIDEO_MPEG2:
                trackFormat = PVR_TRACK_FORMAT_VIDEO_MPEG2;
                break;

            case STRTYPE_VIDEO_H264:
                trackFormat = PVR_TRACK_FORMAT_VIDEO_H264;
                break;

            default:
                trackFormat = PVR_TRACK_FORMAT_OTHER;
                break;
        }

        if ( trackFormat != PVR_TRACK_FORMAT_OTHER )
        {
            PVRSYS_RecSetPid (&tracksCurr, recOpen, stream.pid,
                              trackFormat, pidChange);
        }
    }

    while ( tracksCurr < endTrack )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, PVR_PID_NONE,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    /* ----- assign audio streams ------------------------------------------ */

    strAudio.numStreams = 0;

    endTrack = tracksCurr + PVR_REC_AUDIO_MAX;
    if ( endTrack > recOpen->numberOfTracks )
    {
        endTrack = recOpen->numberOfTracks;
    }

    retVal = PSISI_PMT_StreamParseInit(pPmt, &pmtPos);
    if ( retVal != FAPI_OK ) return retVal;

    while ( PSISI_PMT_StreamParseGetNext(pPmt, &pmtPos, &stream) == FAPI_OK )
    {
        if ( tracksCurr >= endTrack ) break;

        switch ( stream.type )
        {
            case STRTYPE_AUDIO_MPEG1:
                trackFormat = PVR_TRACK_FORMAT_AUDIO_MPEG1;
                break;

            case STRTYPE_AUDIO_MPEG2:
                trackFormat = PVR_TRACK_FORMAT_AUDIO_MPEG2;
                break;

            case STRTYPE_AUDIO_AAC_MPEG2:
                trackFormat = PVR_TRACK_FORMAT_AUDIO_AAC_MPEG2;
                break;

            case STRTYPE_AUDIO_AAC_MPEG4:
                trackFormat = PVR_TRACK_FORMAT_AUDIO_AAC_MPEG4;
                break;

            case STRTYPE_AUDIO_AC3_ATSC_A52:
                trackFormat = PVR_TRACK_FORMAT_AUDIO_AC3;
                break;

            case STRTYPE_PRIVDATA:
                if ( PSISI_DescFind (stream.esInfoStart, stream.esInfoLen,
                                     AC_3_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    trackFormat = PVR_TRACK_FORMAT_AUDIO_AC3;
                }
                else if ( PSISI_DescFind (stream.esInfoStart, stream.esInfoLen,
                                          DDPDCV_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    trackFormat = PVR_TRACK_FORMAT_AUDIO_DDPDCV;
                }
                else
                {
                    trackFormat = PVR_TRACK_FORMAT_OTHER;
                }
                break;

            default:
                trackFormat = PVR_TRACK_FORMAT_OTHER;
                break;
        }

        if ( trackFormat != PVR_TRACK_FORMAT_OTHER )
        {
            /* NOTE: format argument is not relevant here: dummy value is
               passed. */
            if ( PSISI_PMT_AddAudioStreams (&stream, SYS_AUDIO_ALL,
                                            &strAudio) > 0 )
            {
                PVRSYS_RecSetPid (&tracksCurr, recOpen, stream.pid,
                                  trackFormat, pidChange);
            }
        }
    }

    while ( tracksCurr < endTrack )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, PVR_PID_NONE,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    /* ----- assign TTX streams ------------------------------------------- */

    endTrack = tracksCurr + PVR_REC_TTX_MAX;
    if ( endTrack > recOpen->numberOfTracks )
    {
        endTrack = recOpen->numberOfTracks;
    }

    retVal = PSISI_PMT_StreamParseInit(pPmt, &pmtPos);
    if ( retVal != FAPI_OK ) return retVal;

    while ( PSISI_PMT_StreamParseGetNext(pPmt, &pmtPos, &stream) == FAPI_OK )
    {
        if ( tracksCurr >= endTrack ) break;

        switch ( stream.type )
        {
            case STRTYPE_PRIVDATA:
                /* NOTE: Multiple Subtt/TTX streams per PID might be available.
                         If a single descriptor is found, track is recorded. */
                if ( PSISI_DescFind (stream.esInfoStart, stream.esInfoLen,
                                     TELETEXT_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    PVRSYS_RecSetPid (&tracksCurr, recOpen,
                                      stream.pid, PVR_TRACK_FORMAT_OTHER,
                                      pidChange);
                }
                break;

            default:
                break;
        }
    }

    while ( tracksCurr < endTrack )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, PVR_PID_NONE,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    /* ----- assign DVB subtitle streams ----------------------------------- */

    endTrack = tracksCurr + PVR_REC_SUBTT_MAX;
    if ( endTrack > recOpen->numberOfTracks )
    {
        endTrack = recOpen->numberOfTracks;
    }

    retVal = PSISI_PMT_StreamParseInit(pPmt, &pmtPos);
    if ( retVal != FAPI_OK ) return retVal;

    while ( PSISI_PMT_StreamParseGetNext(pPmt, &pmtPos, &stream) == FAPI_OK )
    {
        if ( tracksCurr >= endTrack ) break;

        switch ( stream.type )
        {
            case STRTYPE_PRIVDATA:
                /* NOTE: Multiple Subtt/TTX streams per PID might be available.
                         If a single descriptor is found, track is recorded. */
                if ( PSISI_DescFind (stream.esInfoStart, stream.esInfoLen,
                                     SUBTITLING_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    PVRSYS_RecSetPid (&tracksCurr, recOpen,
                                      stream.pid, PVR_TRACK_FORMAT_OTHER,
                                      pidChange);
                }
                break;

            default:
                break;
        }
    }

    while ( tracksCurr < endTrack )
    {
        PVRSYS_RecSetPid (&tracksCurr, recOpen, PVR_PID_NONE,
                          PVR_TRACK_FORMAT_OTHER, pidChange);
    }

    if ( pRecDat->addCaStreams )
    {
        uint16_t numCaInfoIds = 0;
        uint16_t ca_system_id[PVR_CASYS_IDS_MAX];

        /* ----- assign ECM streams (from PMT) ----------------------------- */

        endTrack = tracksCurr + PVR_REC_ECM_MAX;
        if ( endTrack > recOpen->numberOfTracks )
        {
            endTrack = recOpen->numberOfTracks;
        }

        /* Add all program-related CA streams. */

        pmtInfoLen = UTILS_RdU16Masked (pPmt->buf + 10, 0x0FFF);
        loopPos    = 0;

        while ( PSISI_DescParseGetNext(pPmt->buf + 12, &loopPos, pmtInfoLen,
                                       &desc) == FAPI_OK )
        {
            if ( tracksCurr >= endTrack ) break;

            if ( desc.tag == CA_DESCRIPTOR )
            {
                PVRSYS_RecAddCaInfo (UTILS_RdU16Masked (desc.start + 2, 0xFFFF),
                                     ca_system_id, &numCaInfoIds);

                trackPid = UTILS_RdU16Masked (desc.start + 4, 0x1FFF);

                PVRSYS_RecSetPid (&tracksCurr, recOpen,
                                  trackPid, PVR_TRACK_FORMAT_OTHER, pidChange);
            }
        }

        /* Add all ES-related streams corresponding to a recorded ES. */

        retVal = PSISI_PMT_StreamParseInit(pPmt, &pmtPos);
        if ( retVal != FAPI_OK ) return retVal;

        while ( PSISI_PMT_StreamParseGetNext(pPmt, &pmtPos, &stream)
                == FAPI_OK )
        {
            /* Add CA streams only if particular stream is one of the streams
               assigned for recording! */

            for ( cnt = 0; cnt < tracksCurr; cnt++ )
            {
                if ( recOpen->trackPid[cnt] == stream.pid ) break;
            }

            if ( cnt >= tracksCurr ) break;

            loopPos = 0;

            while ( PSISI_DescParseGetNext(stream.esInfoStart, &loopPos,
                                           stream.esInfoLen, &desc )
                                           == FAPI_OK )
            {
                if ( tracksCurr >= endTrack ) break;

                /* Add all CA-related streams */

                if ( desc.tag == CA_DESCRIPTOR )
                {
                    PVRSYS_RecAddCaInfo (UTILS_RdU16Masked (desc.start + 2,
                                         0xFFFF), ca_system_id, &numCaInfoIds);

                    trackPid = UTILS_RdU16Masked (desc.start + 4, 0x1FFF);

                    PVRSYS_RecSetPid (&tracksCurr, recOpen,
                                      trackPid, PVR_TRACK_FORMAT_OTHER,
                                      pidChange);
                }
            }
        }

        while ( tracksCurr < endTrack )
        {
            PVRSYS_RecSetPid (&tracksCurr, recOpen, PVR_PID_NONE,
                              PVR_TRACK_FORMAT_OTHER, pidChange);
        }

        /* ----- assign EMM streams (from CAT) ----------------------------- */

        endTrack = tracksCurr + PVR_REC_EMM_MAX;
        if ( endTrack > recOpen->numberOfTracks )
        {
            endTrack = recOpen->numberOfTracks;
        }

        for ( cnt = 0; cnt < pRecDat->cat.numStreams; cnt++ )
        {
            if ( tracksCurr >= endTrack ) break;

            /* Only those streams are recorded whose ca_system_id matches
               one of the already recorded streams from PMT. As CAT contains
               multiplex-wide CA information a lot of streams might not be
               needed for target program. */

            if ( !(PVRSYS_IsInCaInfo (pRecDat->cat.stream[cnt].ca_system_id,
                                      ca_system_id, numCaInfoIds)) ) continue;

            PVRSYS_RecSetPid (&tracksCurr, recOpen,
                              pRecDat->cat.stream[cnt].pid,
                              PVR_TRACK_FORMAT_OTHER, pidChange);
        }

        while ( tracksCurr < endTrack )
        {
            PVRSYS_RecSetPid (&tracksCurr, recOpen, PVR_PID_NONE,
                              PVR_TRACK_FORMAT_OTHER, pidChange);
        }
    }

    /* --------------------------------------------------------------------- */

    FAPI_SYS_PRINT_DEBUG(4,"[PVR] %i recording tracks: \n", recOpen->numberOfTracks);

    for ( cnt = 0; cnt < recOpen->numberOfTracks; cnt++ )
    {
        FAPI_SYS_PRINT_DEBUG(4,"[PVR] -- Track %2i: type %2i - PID 0x%04X \n", cnt,
                   recOpen->trackType[cnt],
                   recOpen->trackPid[cnt]);
    }

    return FAPI_OK;
}

FSTATIC void PVRSYS_RecSetPid (uint8_t* index, PVR_RecordOpenT* pParams,
                               uint16_t trackPid, uint8_t trackFormat,
                               fbool_t* pidChange)
{
    uint8_t cnt;

    /* test if PID has already been assigned */
    if ( trackPid < 0x1FFF )
    {
        for ( cnt = 0; cnt < (*index); cnt++ )
        {
            /* Discard PIDs already assigned! */
            if ( pParams->trackPid[cnt] == trackPid )
            {
                FAPI_SYS_PRINT_DEBUG(4,"[PVR] PID 0x%04X already assigned!\n", trackPid);
                return;
            }
        }
    }

    if ( pParams->trackPid[*index] != trackPid ) *pidChange = FTRUE;

    pParams->trackPid   [*index] = trackPid;
    pParams->trackFormat[*index] = trackFormat;

    (*index)++;
}

FSTATIC void PVRSYS_RecAddCaInfo (uint16_t ca_system_id, uint16_t* pIds,
                                  uint16_t* numIds)
{
    uint8_t cnt = 0;

    if ( (*numIds) >= PVR_CASYS_IDS_MAX ) return;

    ca_system_id &= 0xFF00; /* Store and compare only most significant byte */

    while ( cnt < (*numIds) )
    {
        if ( pIds[cnt++] == ca_system_id )
        {
            /* already in list */
            return;
        }
    }

    /* No match found, append to list */
    pIds[(*numIds)++] = ca_system_id;
}

FSTATIC fbool_t PVRSYS_IsInCaInfo (uint16_t ca_system_id, uint16_t* pIds,
                                   uint16_t numIds)
{
    uint8_t cnt = 0;

    ca_system_id &= 0xFF00; /* Compare only most significant byte */

    while ( cnt < numIds )
    {
        if ( ca_system_id == pIds[cnt++] ) return FTRUE;
    }

    return FFALSE;
}

FSTATIC void PVRSYS_PlayRewindPosition (PVRSYS_PLAYDAT_S* pPlayDat)
{
    if ( pPlayDat->rewindWait )
    {
        (void)PVRSYS_PlaySeek (pPlayDat->handle, PVR_SEEK_MODE_CHUNKS,
                               pPlayDat->filePos, pPlayDat->internal);
    }

    /* choose streams according to latest preference */
    PVRSYS_PlayChooseStreams(&(pPlayDat->strPref));

    if ( pPlayDat->rewindWait )
    {
        (void)PVRSYS_IntPlaySetMode (pPlayDat->handle, pPlayDat->mode,
                                     pPlayDat->speedIndex, pPlayDat->internal);

        pPlayDat->rewindWait = FFALSE;
    }
}

FSTATIC void PVRSYS_PlayChooseStreams (const SYS_PLAYPREF_S* pPref)
{
    PVRSYS_PLAYDAT_S* play = &(pvrDat->play);
    uint8_t           cnt;
    int8_t            indexMainAudio  = -1;
    int8_t            indexSpdifAudio = -1;
    SYS_SPDIF_MODE_E  defSpdifMode    = SPDIFMODE_PCMONLY;
    SYS_LANGCODE      prefLang;
    uint8_t           reqTrack;
    uint8_t           reqTrackData;
    PVR_TrackInfoT    trackInf;

    /* NOTE: Audio stream selection is performed in the following order:
       1. If a language request has been passed, it is attempted to choose
          accordingly.
       2. If a general audio language preference has been set, it is used for
          stream selection.
       3. If all selections fail, language information is ignored and the
          first available stream is chosen.
    */

    /* ----- choose main audio stream -------------------------------------- */

    if ( pPref != NULL ) prefLang = pPref->langAudio;
    else                 prefLang = LANG_NOTSPECIFIED;

    indexMainAudio = AVINT_AudioChooseStream (&(play->stream.audio),
                                              SYS_AUDIO_ALL, prefLang, FTRUE);

    if ( indexMainAudio >= 0 )
    {
        reqTrack     = play->audioRef[indexMainAudio];
        reqTrackData = play->stream.audio.stream[indexMainAudio].channel;
    }
    else
    {
        reqTrack     = 0xFF;
        reqTrackData = 0;
    }

    (void)PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_AUDIO, reqTrack,
                                reqTrackData);

    play->audioMainIdx = indexMainAudio;

    /* ----- choose video stream ------------------------------------------- */

    play->lockTrickModes = FTRUE;

    if ( PVR_GetPlaybackTrackInfo (play->handle, &trackInf) == FAPI_OK )
    {
        for ( cnt = 0; cnt < trackInf.numberOfTracks; cnt++ )
        {
            /* choose first available video stream in list */
            if ( (trackInf.trackType[cnt] == PVR_TRACK_TYPE_VIDEO)
               && (trackInf.trackPid[cnt] > 0)
               && (trackInf.trackPid[cnt] < 0x1FFF) )
            {
                (void)PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_VIDEO,
                                            cnt, 0);

                play->lockTrickModes = FFALSE;
                break;
            }
        }
    }

    /* ----- choose SPDIF audio stream ------------------------------------- */

    (void)SETTINGS_DefaultSPDIFModeGet(&defSpdifMode);

    if ( (pPref != NULL)    &&
         (pPref->spdifPref) &&
         (pPref->spdifMode == SPDIFMODE_PCMONLY) )
    {
        /* PCM output is forced: do nothing */
    }
    else if ( ((pPref == NULL) || (!(pPref->spdifPref))) &&
              (defSpdifMode == SPDIFMODE_PCMONLY) )
    {
        /* PCM output is set by default: do nothing */
    }
    else
    {
        /* language explicitly requested? */
        if ( (pPref != NULL)    &&
             (pPref->spdifPref) &&
             (pPref->spdifMode == SPDIFMODE_PREFERPASSTHROUGH) )
        {
            prefLang = pPref->langSpdif;
        }
        else
        {
            prefLang = LANG_NOTSPECIFIED;
        }

        indexSpdifAudio = AVINT_AudioChooseSPDIFStream (&(play->stream.audio),
                                                        prefLang);
    }

    if ( indexSpdifAudio >= 0 )
    {
        reqTrack = play->audioRef[indexSpdifAudio];
    }
    else
    {
        reqTrack = 0xFF;
    }

    (void)PVR_SetPlaybackTrack (play->handle, PVR_DECTYPE_AUDIO_2ND,
                                reqTrack, SYS_AUDIOCHAN_LEFT);

    play->audioSpdifIdx = indexSpdifAudio;
}

FSTATIC void PVRSYS_SendPbEvent (PVRSYS_PLAY_EVENT_E action,
                                 const PVRSYS_STATPLAY_S* mode,
                                 fbool_t userInitiated)
{
    SYS_EVT_PVRPLAY_S ctrlEvent;

    ctrlEvent.hdr.type      = EVT_PVR_PLAYBACK;
    ctrlEvent.hdr.length    = sizeof(ctrlEvent);
    ctrlEvent.action        = action;
    ctrlEvent.mode          = *mode;
    ctrlEvent.userInitiated = userInitiated;

    (void)EVT_Send(&ctrlEvent, "PVR Play");
}

FSTATIC void PVRSYS_SendRecEvent (PVRSYS_REC_EVENT_E action, uint8_t recIdx)
{
    SYS_EVT_PVRREC_S ctrlEvent;

    ctrlEvent.hdr.type   = EVT_PVR_RECORD;
    ctrlEvent.hdr.length = sizeof(ctrlEvent);
    ctrlEvent.action     = action;
    ctrlEvent.recIdx     = recIdx;

    (void)EVT_Send(&ctrlEvent, "PVR Rec");
}

FSTATIC int32_t PVRSYS_PlayUpdateStreams (const PSISI_PMT_S* pPmt)
{
    PSISI_PMT_STREAM_S     pmtStream;
    PVRSYS_PLAYDAT_S*      play   = &(pvrDat->play);
    SYS_STREAMINF_AUDIO_S* pAudio = &(play->stream.audio);
    PVR_TrackInfoT         trackInf;
    uint16_t               pmtPos;
    int32_t                retVal;
    uint8_t                track;
    uint8_t                refPos = 0;
    uint8_t                audioFormat;

    /* Clear all stream information */
    memset (&(play->stream), 0, sizeof(SYS_STREAM_INFO_S));

    if ( PVR_GetPlaybackTrackInfo (play->handle, &trackInf) != FAPI_OK )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    retVal = PSISI_PMT_StreamParseInit(pPmt, &pmtPos);
    if ( retVal != FAPI_OK )
    {
        return retVal;
    }

    play->stream.valid = 1; /* mark structure data as valid */

    /* NOTE: PCR PID value is set even if PID is not part of the recording. */

    play->stream.pcr = LD_PID(pPmt->buf + 8);

    while ( PSISI_PMT_StreamParseGetNext (pPmt, &pmtPos, &pmtStream)
            == FAPI_OK )
    {
        /* check if stream has been recorded */
        for ( track = 0; track < trackInf.numberOfTracks; track++ )
        {
            if ( trackInf.trackPid[track] == pmtStream.pid ) break;
        }

        /* skip stream if not part of the recording */
        if ( track >= trackInf.numberOfTracks ) continue;

        audioFormat = SYS_AUDIO_NUMS;

        switch ( pmtStream.type )
        {
            case STRTYPE_VIDEO_MPEG1:
            case STRTYPE_VIDEO_MPEG2:
            case STRTYPE_VIDEO_H264:
            case STRTYPE_VIDEO_VC1:
                if( play->stream.video.stream[0].pid == 0 )
                {
                    play->stream.video.stream[0].pid    = pmtStream.pid;
                    play->stream.video.stream[0].format = (uint8_t)pmtStream.type;
                }
                break;

            case STRTYPE_AUDIO_MPEG1:
            case STRTYPE_AUDIO_MPEG2:
                audioFormat = SYS_AUDIO_MPEG;
                break;

            case STRTYPE_AUDIO_AAC_MPEG2:
                audioFormat = SYS_AUDIO_AAC;
                break;

            case STRTYPE_AUDIO_AAC_MPEG4:
                audioFormat = SYS_AUDIO_HEAAC;
                break;

            case STRTYPE_AUDIO_AC3_ATSC_A52:
                audioFormat = SYS_AUDIO_AC3;
                break;

            case STRTYPE_PRIVDATA:
                if ( PSISI_DescFind(pmtStream.esInfoStart, pmtStream.esInfoLen,
                                  TELETEXT_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    play->stream.ttx = pmtStream.pid;
                }

                if ( PSISI_DescFind (pmtStream.esInfoStart, pmtStream.esInfoLen,
                                     AC_3_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    audioFormat = SYS_AUDIO_AC3;
                }
                else if ( PSISI_DescFind (pmtStream.esInfoStart,
                                          pmtStream.esInfoLen,
                                          DDPDCV_DESCRIPTOR, NULL) == FAPI_OK )
                {
                    audioFormat = SYS_AUDIO_DDPDCV;
                }
                break;

            default:
                break;
        }

        /* audio stream found? */
        if ( (audioFormat != SYS_AUDIO_NUMS)
          && (pAudio->numStreams < SYS_AUDIO_STR_MAX) )
        {
            (void)PSISI_PMT_AddAudioStreams (&pmtStream, audioFormat, pAudio);

            /* NOTE: Multiple entries might have been added from a single
                    stream (-> dual channel), thus 'while' is used here! */
            while ( refPos < pAudio->numStreams )
            {
                play->audioRef[refPos++] = track;
            }
        }
    }

    return FAPI_OK;
}

FSTATIC void PVRSYS_RecCallback (FAPI_SYS_HandleT handle,
                                 PVR_RecordNotifyT reason)
{
    SYS_EVT_RECEVT_S    ctrlEvent;
    uint8_t             recIdx;

    for ( recIdx = 0; recIdx < RSRC_REC_MAX; recIdx++ )
    {
        if ( (pvrDat->rec[recIdx].active)
          && (pvrDat->rec[recIdx].handle == handle) )
        {
            break;
        }
    }

    if ( recIdx >= RSRC_REC_MAX )
    {
        /* no associated recording found */
        return;
    }

    FAPI_SYS_PRINT_DEBUG(1,"\n>>> REC Callback (idx %i) = ", recIdx);

    switch (reason)
    {
        case PVR_RECORD_NOTIFY_FILE_ERROR:        FAPI_SYS_PRINT_DEBUG(1,"FILE ERROR");
                                                  break;
        case PVR_RECORD_NOTIFY_DISK_FULL:         FAPI_SYS_PRINT_DEBUG(1,"DISK FULL");
                                                  break;
        case PVR_RECORD_NOTIFY_MAX_SIZE:          FAPI_SYS_PRINT_DEBUG(1,"MAX SIZE");
                                                  break;
        case PVR_RECORD_NOTIFY_STOP_POSITION:     FAPI_SYS_PRINT_DEBUG(1,"STOP POS");
                                                  break;
        case PVR_RECORD_NOTIFY_FILLING:           FAPI_SYS_PRINT_DEBUG(1,"FILLING");
                                                  break;
        case PVR_RECORD_NOTIFY_LOOPING:           FAPI_SYS_PRINT_DEBUG(1,"LOOPING");
                                                  break;
        case PVR_RECORD_NOTIFY_NO_DATA:           FAPI_SYS_PRINT_DEBUG(1,"NO DATA");
                                                  break;
        case PVR_RECORD_NOTIFY_DATA:              FAPI_SYS_PRINT_DEBUG(1,"DATA");
                                                  break;
        case PVR_RECORD_NOTIFY_PERFORMANCE_LIMIT: FAPI_SYS_PRINT_DEBUG(1,"PERFORMANCE LIMIT");
                                                  break;
        default:                                  FAPI_SYS_PRINT_DEBUG(1,"%u", (uint32_t)reason);
                                                  break;
    }

    FAPI_SYS_PRINT_DEBUG(1,"\n");

    ctrlEvent.hdr.type   = EVT_PVR_RECEVENT;
    ctrlEvent.hdr.length = sizeof(ctrlEvent);
    ctrlEvent.event      = reason;
    ctrlEvent.recIdx     = recIdx;

    (void)EVT_Send(&ctrlEvent, "Rec evt");
}

/*lint -save -e715 */
FSTATIC void PVRSYS_PlayCallback (FAPI_SYS_HandleT playHandle,
                                  PVR_PlayNotifyT reason)
{
    SYS_EVT_PLAYEVT_S ctrlEvent;

    FAPI_SYS_PRINT_DEBUG(1,">>> Playback Callback = ");

    switch (reason)
    {
        case PVR_PLAY_NOTIFY_FILE_ERROR:    FAPI_SYS_PRINT_DEBUG(1,"FILE ERROR\n");    break;
        case PVR_PLAY_NOTIFY_END_OF_DATA:   FAPI_SYS_PRINT_DEBUG(1,"END OF DATA\n");   break;
        case PVR_PLAY_NOTIFY_BEGIN_OF_DATA: FAPI_SYS_PRINT_DEBUG(1,"BEGIN OF DATA\n"); break;
        case PVR_PLAY_NOTIFY_GAP_IN_DATA:   FAPI_SYS_PRINT_DEBUG(1,"GAP IN DATA");     break;
        case PVR_PLAY_NOTIFY_TAG_SET:       FAPI_SYS_PRINT_DEBUG(1,"TAG SET");         break;
        case PVR_PLAY_NOTIFY_NAME_SET:      FAPI_SYS_PRINT_DEBUG(1,"NAME SET");        break;
        case PVR_PLAY_NOTIFY_IFRAME_LOCKED: FAPI_SYS_PRINT_DEBUG(1,"IFRAME FOUND AND LOCKED"); break;
        default:                            FAPI_SYS_PRINT_DEBUG(1,"%u", (uint32_t)reason); break;
    }

    FAPI_SYS_PRINT_DEBUG(1,"\n");

    ctrlEvent.hdr.type   = EVT_PVR_PLAYEVENT;
    ctrlEvent.hdr.length = sizeof(ctrlEvent);
    ctrlEvent.event      = reason;

    (void)EVT_Send(&ctrlEvent, "Play evt");
}
/*lint -restore */


/* ------------------------------------------------------------------------- */

FSTATIC fbool_t PVRSYS_SettingsLoad ()
{
    FLASHFS_HANDLE  file;
    fbool_t         retVal = FFALSE;

    file = FLASHFS_Open (FILEID_PVRDAT, FLASHFS_OPEN_READ, NULL);
    if ( file == NULL )
    {
        return FFALSE;
    }

    do
    {
        /* read file header */
        if ( FLASHFS_Read (file, sizeof(PVRSYS_FILEHDR_S), &(pvrDat->cfg), NULL)
             != (int32_t)(sizeof(PVRSYS_FILEHDR_S)) ) break;

        if ( (pvrDat->cfg.id       != FILEID_PVRDAT) ||
             (pvrDat->cfg.idEnd    != FILEID_PVRDAT) ||
             (pvrDat->cfg.revision != FILEREV_PVRDAT) )
        {
            break;
        }

        retVal = FTRUE;
    }
    while ( 0 );

    (void)FLASHFS_Close(file);

    return retVal;
}

int32_t PVRSYS_SettingsSave ()
{
    FLASHFS_HANDLE  file;
    int32_t         retVal = FAPI_OK;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    file = FLASHFS_Open (FILEID_PVRDAT, FLASHFS_OPEN_WRITE, &retVal);

    if ( file != NULL )
    {
        pvrDat->cfg.id       = FILEID_PVRDAT;
        pvrDat->cfg.idEnd    = FILEID_PVRDAT;
        pvrDat->cfg.revision = FILEREV_PVRDAT;

        /* write header */
        if ( FLASHFS_Write(file, sizeof(PVRSYS_FILEHDR_S), &(pvrDat->cfg), NULL)
             !=  (int32_t)(sizeof(PVRSYS_FILEHDR_S)) )
        {
            retVal = SMARTGO_SYS_ERR_INTERNAL;
        }

        (void)FLASHFS_Close(file);
    }

    return retVal;
}

FSTATIC void PVRSYS_SettingsDefaultsSet ()
{
    if ( SYS_GetConfig()->setPvrDefaults != NULL )
    {
        SYS_GetConfig()->setPvrDefaults();
    }
}

void PVRSYS_RestoreDefaults ()
{
    if ( pvrDat == NULL ) return;

    /* Delete stored data */
    (void)FLASHFS_Delete(FILEID_PVRDAT);

    PVRSYS_SettingsDefaultsSet();
}

int32_t PVRSYS_SetMountPath (SYS_DEVICE_E device)
{
    int32_t  retVal;
    uint32_t strPos;

    strPos = (uint32_t)SYS_DeviceGetMountPath (device, sysData->strBuf,
                                               SYS_STRBUF_SIZE);

    if ( (strPos + 1) >= SYS_STRBUF_SIZE )
    {
        retVal = SMARTGO_SYS_ERR_INTERNAL;
    }
    else
    {
        (void)UTILS_strncpy(sysData->strBuf + strPos, "/",
                            SYS_STRBUF_SIZE - strPos);

        retVal = PVR_SetMountPath(sysData->strBuf);
    }

    return retVal;
}

FSTATIC int32_t PVRSYS_GetRecIndexByTsd (uint8_t tsdIdx, uint8_t* pRecIdx)
{
    int32_t retVal = FAPI_OK;

    switch ( tsdIdx )
    {
        case RSRC_TSD_REC1:
            *pRecIdx = 0;
            break;

        case RSRC_TSD_REC2:
            *pRecIdx = 1;
            break;

        default:
            retVal = SMARTGO_SYS_ERR_INTERNAL;
    }

    return retVal;
}

/* ------------------------------------------------------------------------- */

#if defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED)

FSTATIC void PVRSYS_TsFeedDone (int32_t status, uint32_t bytes)
{
    (void)RTOS_SetSemaphore (pvrDat->play.tsTransferSemaphore,
                             FAPI_SYS_NO_SUSPEND);
}

fbool_t PVRSYS_TsFeedData (uint8_t tsd, const uint32_t* pData, uint32_t packets,
                           uint32_t* pMillisNeeded)
{
    static char_t       DSTR_TsOut[] = "TsPlyOut";
    PVRSYS_PLAYDAT_S*   play = &(pvrDat->play);
    volatile uint32_t*  pBuf;
    uint32_t            lwToTransfer;
    uint32_t            cnt;

    /* This debugging feature is not supported yet! */
    if ( pMillisNeeded != NULL ) *pMillisNeeded = 0;

    (void)RTOS_GetSemaphore(play->tsFeedMutex, FAPI_SYS_SUSPEND);
    FD_GHW_UpiBusLock(DSTR_TsOut);                        // EddieNote: moved locking into ApplicationLevel-SW

    for ( cnt = 0; cnt < packets; cnt += PVR_TSPKTS_PER_LOOP )
    {
        if ( (cnt + PVR_TSPKTS_PER_LOOP) <= packets )
        {
             lwToTransfer = PVR_TSPKTS_PER_LOOP;
        }
        else
        {
            lwToTransfer = packets - cnt;
        }

        lwToTransfer *= PVR_LW_PER_PKT;

        pBuf = (volatile uint32_t*)(void*)(pData + (cnt * PVR_LW_PER_PKT));

        // to do: support swapped TS data (for PES recording?) !
        FD_FHW_TxTsDataDmaAtaUpiCpld (1, lwToTransfer, pBuf,
                                      PVR_TsFeedDone);

        (void)RTOS_GetSemaphore(play->tsTransferSemaphore, FAPI_SYS_SUSPEND);
        FD_GHW_UpiBusUnlock(DSTR_TsOut);
    }

    (void)RTOS_SetSemaphore (play->tsFeedMutex, FAPI_SYS_NO_SUSPEND);

    return FTRUE;
}

#endif /* defined(APPL_CI_ENABLED) && defined(APPL_DESCRREC_ENABLED) */

#ifdef APPL_EDITMARKER_ENABLED

/*!
*******************************************************************************
**
** \brief  Initialize for current playback marker data to PVR lib.
**
**         The application has to take care to allocate memory for keeping marker
**         data. The handling of the contents is completely done by the driver.
**         The marker are arranged everytime in a increasing consecutive
**         order by the driver when inserting or removing a marker entry.
**         By this function the dirver knows where to place new marker structure
**         entries and which counter to use.
**
** \param  pMarker    pointer to marker data structure
** \param  pNumMarker pointer to number of marker valid
**
**
** \return One of the following status codes:
**         - #FAPI_OK                           successful
**         - #APPL_SMARTGO_ERR_NOT_INITIALIZED  main data structure is not initialized
**         - #APPL_SMARTGO_ERR_BAD_PARAMETER    at bad parameter
**         - #SMARTGO_SYS_ERR_INTERNAL          driver call failed
******************************************************************************/
int32_t PVRSYS_PlayInitMarker (FDVR_PLAY_MARKER_S* pMarker, uint32_t* pNumMarker)
{
    int32_t ferr;

    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;
    if ( pvrDat->play.handle == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;
    if ( (ferr = FDVR_InitPlaybackMarker(pvrDat->play.handle, pMarker, pNumMarker)) != FDVR_OK )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Initialize for current playback marker data to FDVR lib.
** \attention   Calling this function with value FTRUE also forces the playback
**              driver to read again the marker list and reset the internal
**              pointer to new areas for special handling.
**
** \param  enable  enable the driver to handle marker during playback
**
** \return One of the following status codes:
**         - #FAPI_OK                           successful
**         - #APPL_SMARTGO_ERR_NOT_INITIALIZED  main data structure is not initialized
**         - #APPL_SMARTGO_ERR_BAD_PARAMETER    at bad parameter
**         - #SMARTGO_SYS_ERR_INTERNAL          driver call failed
******************************************************************************/
int32_t PVRSYS_PlayEnableMarker (fbool_t enable)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( pvrDat->play.handle == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    if ( FDVR_EnablePlaybackMarker(pvrDat->play.handle, enable) != FDVR_OK )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Set/change type of marker at current position.
**
** \param  type         marker type of #FDVR_PLAY_MARKER_TYPE_E
** \param  maxNumMarker maximum number of markers reserved
**
** \attention           Maximum nuber of marker MUST really be correct. The
**                      assumes that the memory is reserved and writed data
**                      to this location.
**
** \return  One of the following status codes:
**          - #FAPI_OK                          successful
**          - #APPL_SMARTGO_ERR_NOT_INITIALIZED pvr data structur is not initialized
**          - #APPL_SMARTGO_ERR_BAD_PARAMETER   passed argument is invalid
**          - #SMARTGO_SYS_ERR_INTERNAL         playback driver returns error.
** \sa      PVRSYS_PlayRemoveMarker
******************************************************************************/
int32_t PVRSYS_PlaySetMarker (FDVR_PLAY_MARKER_TYPE_E type, uint32_t maxNumMarker)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( pvrDat->play.handle == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    if ( pvrDat->play.lockTrickModes )
    {
        return SMARTGO_SYS_ERR_PROHIBITED;
    }

    if ( FDVR_SetPlaybackMarker(pvrDat->play.handle, type, maxNumMarker) != FDVR_OK )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }
    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Remove marker.
**
** \param  maxNumMarker maximum number of markers defined by application.
** \param  pPosition    pointer to position of marker to be removed. NULL if
**                      not needed and playback driver should look at current
**                      playback position.
**
** \return  One of the following status codes:
**          - #FAPI_OK if successful
** \sa      PVRSYS_PlaySetMarker
******************************************************************************/
int32_t PVRSYS_PlayRemoveMarker (uint32_t maxNumMarker, uint32_t* pPosition)
{
    if ( pvrDat == NULL ) return APPL_SMARTGO_ERR_NOT_INITIALIZED;

    if ( pvrDat->play.handle == NULL ) return APPL_SMARTGO_ERR_BAD_PARAMETER;

    if ( FDVR_RemovePlaybackMarker(pvrDat->play.handle, maxNumMarker, pPosition) != FDVR_OK )
    {
        return SMARTGO_SYS_ERR_INTERNAL;
    }

    return FAPI_OK;
}

#endif /* APPL_EDITMARKER_ENABLED */

#endif

/******************************************************************************/
/*lint -restore */
/* END OF FILE */
