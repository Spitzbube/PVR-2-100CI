/*!
*****************************************************************************
**
** \file        ./middleware/pvr/src/pvr.h
** 
** \brief       PVR Driver.
**
** This file contains the declaration of the PVR API.
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

#ifndef PVR_H
#define PVR_H

#include <fapi/sys_driver.h>

#if 0

#include <fatfs/api_f.h>

//***********************************************************************
//***********************************************************************
//** Defines and Macros
//***********************************************************************
//***********************************************************************

/*!
** \brief Default mount path used by the file system.
**
** This path will be added to each filename.
*/
#define PVR_DEFAULT_MOUNT_PATH        ""

/*!
** \brief Default extension appended to all files.
** 
** This option is disabled by default.
** 
** \sa    PVR_SetFileExtension()
*/
#define PVR_DEFAULT_FILE_EXTENSION    NULL

/*!
** \brief Default number of digits for split file numbering.
**
** If a file name extension is used, digits will replace it for split files,
** otherwise they are simply appended to the specified filename.
*/
#define PVR_DEFAULT_SPLIT_DIGITS      2

/*!
** \brief Default numbering notation for split files
**
** If a file name extension is used, digits will replace it for split files,
** otherwise they are simply appended to the specified filename.
*/
#define PVR_DEFAULT_SPLIT_USE_DEC     1

/*!
** \brief Maximum length of the mount path name.
**
** The length does not include the ending zero.
*/
#define PVR_PATH_NAME_LENGTH          63

/*!
** \brief Maximum length of a filename.
**
** The length does not include the ending zero.
*/
#define PVR_FILE_NAME_LENGTH          31

/*!
** \brief length of separator between filename and filename extension.
**
** The length does not include the ending zero.
*/
#define PVR_FILE_SEP_LENGTH           1

/*!
** \brief Maximum length of file extension.
**
** The length does not include the ending zero.
*/
#define PVR_FILE_EXT_LENGTH           3

/*!
** \brief Maximum number of tracks (PIDs) to be recorded in one file.
**
** \note  Do not change this value!
*/
#define PVR_MAX_TRACKS                32

/*!
** \brief Maximum length of a name stored in the recorded file.
**
** This name will typically be the service name which might change
** during recording.
**
** The length does not include the ending zero.
*/
#define PVR_NAME_LENGTH               63

/*!
** \brief TS packet size in bytes.
*/
#define PVR_TSPKT_SIZE                188

/*!
** \brief Number of TS packets per data chunk (see #PVR_CHUNK_SIZE).
*/
#define PVR_PKTS_PER_CHUNK            512

/*!
** \brief Size of one data chunk of PVR files in bytes.
**
** This value indicates the number of bytes which are written to
** and read from the hard disk drive in one single operation.
**
** Note that this value must be divisible by 188 (TS packet size)
** and 512 (HDD sector size). So, the minimum value is
** 96256 bytes (94 kbytes).
*/
#define PVR_CHUNK_SIZE                (PVR_TSPKT_SIZE * PVR_PKTS_PER_CHUNK)

/*!
** \brief Number of packets for user data.
**
** The user data is stored at the beginning of the file (starting at
** packet 1) and will be 'hidden' in stuffing packets. Note that
** each packet can contain 184 bytes (4 bytes used for TS header).
**
** The size should not exceed 200 packets.
*/
#define PVR_USER_DATA_PACKETS         32


/*!
** \brief Number of available fast modes.
**
** Fast modes can be individually configured by using the functions
** PVR_GetFastModeConfig and PVR_SetFastModeConfig.
*/
#define PVR_MAX_FAST_MODES            64

/*!
********************************************************************************
** Standard error codes for the driver
********************************************************************************
*/

/*! Bad parameter passed. */
#define MIDDLEWARE_PVR_ERR_BAD_PARAMETER         (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_BAD_PARAMETER)

/*! Memory allocation failed. */
#define MIDDLEWARE_PVR_ERR_OUT_OF_MEMORY         (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_OUT_OF_MEMORY)

/*! Device already initialised. */
#define MIDDLEWARE_PVR_ERR_ALREADY_INITIALIZED   (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_ALREADY_INITIALIZED)

/*! Device not initialised. */
#define MIDDLEWARE_PVR_ERR_NOT_INITIALIZED       (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_NOT_INITIALIZED)

/*! Feature or function is not available. */
#define MIDDLEWARE_PVR_ERR_FEATURE_NOT_SUPPORTED (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_FEATURE_NOT_SUPPORTED)

/*! Timeout occured. */
#define MIDDLEWARE_PVR_ERR_TIMEOUT               (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_TIMEOUT)

/*! The device is busy, try again later. */
#define MIDDLEWARE_PVR_ERR_DEVICE_BUSY           (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_DEVICE_BUSY)

/*! Invalid handle was passed. */
#define MIDDLEWARE_PVR_ERR_INVALID_HANDLE        (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_INVALID_HANDLE)

/*! Semaphore could not be created. */
#define MIDDLEWARE_PVR_ERR_SEMAPHORE_CREATE      (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_SEMAPHORE_CREATE)

/*! The driver's used version is not supported. */
#define MIDDLEWARE_PVR_ERR_UNSUPPORTED_VERSION   (int32_t)(MIDDLEWARE_PVR_MODULE_BASE +\
                                                           FAPI_ERR_UNSUPPORTED_VERSION)


/*!
********************************************************************************
** Additional driver error codes (reserved from -100 to -999)
**
** Each error code shall be decreased in steps of 1.
********************************************************************************
*/

/*! PVR driver specfic error code base. */
#define MIDDLEWARE_PVR_ERR_BASE (int32_t)(MIDDLEWARE_PVR_MODULE_BASE - 100)

/*! PVR driver specific error XXX.
    \note XXX should be replaced by a meaningful name.
*/
#define MIDDLEWARE_PVR_ERR_FILE_HANDLING        (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 0)
#define MIDDLEWARE_PVR_ERR_BAD_FILE_FORMAT      (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 1)
#define MIDDLEWARE_PVR_ERR_FILE_READ            (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 2)
#define MIDDLEWARE_PVR_ERR_BAD_PACKET_SIZE      (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 3)
#define MIDDLEWARE_PVR_ERR_FILE_EXISTS          (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 4)
#define MIDDLEWARE_PVR_ERR_THREAD_ERROR         (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 5)
#define MIDDLEWARE_PVR_ERR_BAD_MODE             (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 6)
#define MIDDLEWARE_PVR_ERR_DISK_WRITE           (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 7)
#define MIDDLEWARE_PVR_ERR_NO_VIDEO             (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 8)
#define MIDDLEWARE_PVR_ERR_NO_TRACK_ASSIGNED    (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 9)
#define MIDDLEWARE_PVR_ERR_WRONG_MARKER_TYPE    (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 10)
#define MIDDLEWARE_PVR_ERR_END_OF_DATA          (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 11)
#define MIDDLEWARE_PVR_ERR_BEGIN_OF_DATA        (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 12)
#define MIDDLEWARE_PVR_ERR_FILE_DOES_NOT_EXIST  (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 13)
#define MIDDLEWARE_PVR_ERR_TSD                  (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 14)
#define MIDDLEWARE_PVR_ERR_BAD_FILE_VERSION     (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 15)
#define MIDDLEWARE_PVR_ERR_NO_BUFFER_SPACE      (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 16)
#define MIDDLEWARE_PVR_ERR_CRYPTO_OP_FAILED     (int32_t)(MIDDLEWARE_PVR_ERR_BASE - 17)

//***********************************************************************
//***********************************************************************
//** Data types
//***********************************************************************
//***********************************************************************

/*!
*************************************************************************
** \brief Version of the PVR driver.
**
** This number consists of a \b major version number stored in bits
** 16 to 31 (upper word) and a \b minor version number stored in bits
** 0 to 15 (lower word).
** - The \b major number has to be increased when a parameter change
**   occurs for the existing driver's API after its first release.
** - The \b minor number has to be increased when functions are added to
**   the existing driver's API after its first release.
**
** \note This value has to be assigend to the \b version field of
**       PVR_RecordOpenT and PVR_PlayOpenT structures.
**
*************************************************************************
*/

typedef enum
{
    PVR_VERSION = (int32_t)0x00020000   //!< The current driver version
    
} PVR_VersionEnumT;


/*!
*******************************************************************************
**
** \brief Streaming data types.
**
**        This type defines the different streaming data types which
**        may be stored in a PVR file and are relevant for playback.
**        
** \note  Only track types where the decoding is controlled by the PVR library
**        are defined here. It is possible to use application-specific track 
**        types (e.g. for DVB subtitle streams, ECM/ECM, ...). 
**        For these types values from PVR_TRACK_TYPE_NUMS to 
**        (PVR_TRACK_TYPE_OTHER - 1) must be used in order to avoid conflicts!
**        
**
** \sa    PVR_FileInfoT
**   <br> PVR_RecordOpenT
**
******************************************************************************/
typedef uint8_t PVR_TrackTypeT;

#define PVR_TRACK_TYPE_VIDEO        0x00    //!< Video stream track.
#define PVR_TRACK_TYPE_AUDIO        0x01    //!< Audio stream track.
#define PVR_TRACK_TYPE_DEPRECATED   0x02    //!< Deprecated audio stream track.
#define PVR_TRACK_TYPE_TTX          0x03    //!< Teletext stream track.
#define PVR_TRACK_TYPE_NUMS         0x04    //!< Number of internally 
                                            //!< controlled streams.
#define PVR_TRACK_TYPE_OTHER        0xFF    //!< Invalid/unspecified track type.


/*!
********************************************************************************
** Streaming type specific data formats
**
** \note Maximum value is 0xF!
********************************************************************************
*/

#define PVR_TRACK_FORMAT_OTHER              0x00  //!< Unknown/other format.

#define PVR_TRACK_FORMAT_VIDEO_MPEG1        0x01  //!< DVB stream_type: 0x01
#define PVR_TRACK_FORMAT_VIDEO_MPEG2        0x02  //!< DVB stream_type: 0x02
#define PVR_TRACK_FORMAT_VIDEO_H264         0x03  //!< DVB stream_type: 0x1B

#define PVR_TRACK_FORMAT_AUDIO_MPEG1        0x01  //!< DVB stream_type: 0x03
#define PVR_TRACK_FORMAT_AUDIO_MPEG2        0x02  //!< DVB stream_type: 0x04
#define PVR_TRACK_FORMAT_AUDIO_AC3          0x03  //!< DVB stream_type: 0x06 + 
                                                  //!< descr.
#define PVR_TRACK_FORMAT_AUDIO_AAC_MPEG2    0x04  //!< AAC: (str_type: 0x0F)
#define PVR_TRACK_FORMAT_AUDIO_AAC_MPEG4    0x05  //!< HE-AAC: (str_type: 0x11)
#define PVR_TRACK_FORMAT_AUDIO_DDPDCV       0x06  //!< E-AC3/DD+ (str_type:
                                                  //!< 0x06 + descr.)

/*!
*******************************************************************************
**
** \brief Recording modes.
**
**        This enumeration type defines the different possible modes or states
**        of a recording instance.
**
** \sa    PVR_SetRecordingMode()
**   <br> PVR_GetRecordingMode()
**
******************************************************************************/
typedef enum
{
    /*!
    ** The recording engine is changing its operation mode.
    ** This is an intermediate state during mode transition.
    */
    PVR_RECORD_MODE_CHANGING,

    /*!
    ** The recording engine is stopped.
    ** This mode will also be entered after opening a recording instance.
    */
    PVR_RECORD_MODE_STOPPED,

    /*!
    ** The recording engine is recording.
    */
    PVR_RECORD_MODE_NORMAL,

    /*!
    ** The recording engine is paused.
    */
    PVR_RECORD_MODE_PAUSE,
} PVR_RecordModeT;


/*!
*******************************************************************************
**
** \brief Recording notification reasons.
**
**        This enumeration type defines the different reasons for a
**        recording instance to call the notification function.
**
** \sa    PVR_RecordCallback
**
******************************************************************************/
typedef enum
{
    /*!
    ** An error occurred during file access, i.e. writing or seeking the file.
    ** The recording engine will be paused, but
    ** data consistency can not be ensured.
    */
    PVR_RECORD_NOTIFY_FILE_ERROR,

    /*!
    ** Writing to the recording reports that the disk is full.
    ** The recording engine will be paused, but
    ** data consistency can not be ensured.
    */
    PVR_RECORD_NOTIFY_DISK_FULL,

    /*!
    ** The buffer filling exceeded the set limit.
    */
    PVR_RECORD_NOTIFY_FILLING,

    /*!
    ** The maximum file size is reached and looping is done.
    ** The write pointer will be moved to the beginning of the file.
    */
    PVR_RECORD_NOTIFY_LOOPING,

    /*!
    ** No data is available.
    ** Due to interruption of the incoming data the recording engine will enter
    ** a special waiting-for-data state.
    */
    PVR_RECORD_NOTIFY_NO_DATA,

    /*!
    ** Data is again available and recording will be continued.
    */
    PVR_RECORD_NOTIFY_DATA,

    /*!
    ** The set maximum file size is reached (or slightly exceeded) and
    ** looping is not enabled.
    ** The recording engine will be stopped immediately.
    */
    PVR_RECORD_NOTIFY_MAX_SIZE,

    /*!
    ** The set stop position is reached and the recording will be stopped.
    */
    PVR_RECORD_NOTIFY_STOP_POSITION,

    /*!
    ** The recording thread is at its performance limit for the specified time
       interval. The recording engine will be paused.
    */
    PVR_RECORD_NOTIFY_PERFORMANCE_LIMIT,
    
} PVR_RecordNotifyT;


/*!
*******************************************************************************
**
** \brief Notification function called by recording engine.
**
**        This function will be called by a recording instance if one of the
**        following events occur:
**        - A file error or another error occurs.
**        - The filling level of the hardware buffer exceeded the set limit.
**        - The maximum file size is reached and looping is done.
**        - The maximum file size is reached and the engine will be stopped.
**
** \param reason  Reason for notification.
** \param error   Error code of occurred error.
**
** \sa    PVR_RecordOpenT
**
******************************************************************************/
typedef void (*PVR_RecordCallback)(FAPI_SYS_HandleT recHandle,
                                   PVR_RecordNotifyT reason);

/*!
*******************************************************************************
**
** \brief Generic playback function called by playback engine.
**
** \param tsd             TSD expection data input by playback engine.
** \param pData           Pointer to data to be fed.
** \param packets         Number of packets contained in data buffer.
** \param discardStuffing If 1, stuffing packets contained in data are ignored.
** \param pMillisNeeded   Optional facility to measure time consumption for
**                        data transfer, set to NULL if not needed.
**
** \sa    PVR_SetPlaybackFunction
**
******************************************************************************/
typedef uint8_t (*PVR_PlaybackFeedOutput)(uint8_t tsd, const uint32_t* pData,
                                          uint32_t packets,
                                          uint8_t discardStuffing,
                                          uint64_t* pMillisNeeded);

#endif

/*!
*******************************************************************************
**
** \brief Playback modes.
**
**        This enumeration type defines the different possible modes or states
**        of a playback instance.
**
** \sa    PVR_SetPlaybackMode()
**   <br> PVR_GetPlaybackMode()
**
******************************************************************************/
typedef enum
{
    /*!
    ** The playback engine is changing its state.
    ** This is an intermediate state during mode transition.
    */
    PVR_PLAY_MODE_CHANGING,

    /*!
    ** The playback engine is stopped.
    */
    PVR_PLAY_MODE_STOPPED,

    /*!
    ** The playback engine is running with normal speed.
    */
    PVR_PLAY_MODE_NORMAL,

    /*!
    ** The playback engine is running in the picture based mode.
    ** This mode can be entered only if the playback file contains video data.
    */
    PVR_PLAY_MODE_FAST,

    /*!
    ** The playback engine is running in slow motion mode.
    ** This mode can be entered only if the playback file contains video data.
    ** For slow motion each top field of a frame is repeated. The number of
    ** repeats is defined by the set speed whereas only values between 1 and 30
    ** are allowed.
    */
    PVR_PLAY_MODE_SLOW,
    /*!
    ** The playback engine is freezing the video and audio.
    ** This mode is new and replaces the combination of FAST_MODE and speed = 0.
    */
    PVR_PLAY_MODE_PAUSE,
    
} PVR_PlayModeT;

#if 0

/*!
*******************************************************************************
**
** \brief Playback notification reasons.
**
**        This enumeration type defines the different reasons for a playback
**        instance to call the notification function.
**
** \sa    PVR_PlayCallback
**
******************************************************************************/
typedef enum
{
    /*!
    ** Empty/invalid notification (internally used).
    */
    PVR_PLAY_NOTIFY_NONE,
    
    /*!
    ** An error occurred while reading the file.
    ** The playback engine will be stopped immediately.
    */
    PVR_PLAY_NOTIFY_FILE_ERROR,

    /*!
    ** The end of data is reached and the playback engine will be stopped.
    ** If the picture based fast mode is active the speed will be set to zero,
    ** so that a still picture is being displayed.
    ** For circular files the end of data is not necessarily the physical
    ** end of the file.
    */
    PVR_PLAY_NOTIFY_END_OF_DATA,

    /*!
    ** The beginning of data is reached and the playback engine will be
    ** paused, i.e. speed set to zero. This event may occur only in
    ** picture based mode.
    */
    PVR_PLAY_NOTIFY_BEGIN_OF_DATA,

    /*!
    ** The current playback position of a circular timeshift file
    ** is overwritten. The playback position will be set a few clusters
    ** ahead of the write position and normal playback will be started.
    */
    PVR_PLAY_NOTIFY_BEGIN_OVERWRITTEN,

    /*!
    ** Data was interrupted during recording at this position.
    ** For example, this event could be used to restart playback to
    ** avoid video macro blocks.
    */
    PVR_PLAY_NOTIFY_GAP_IN_DATA,

    /*!
    ** A tag was set during recording at this position.
    ** Note that the value of the tag might not change.
    */
    PVR_PLAY_NOTIFY_TAG_SET,

    /*!
    ** A name was set during recording at this position.
    ** Note that the value of the name might not change.
    */
    PVR_PLAY_NOTIFY_NAME_SET,

    /*!
    ** In search mode to next or previous I-Frame in a chunk
    ** this notifies that an I-Frame was found. Read pointer
    ** remains at this chunk.
    */
    PVR_PLAY_NOTIFY_IFRAME_LOCKED,
    
} PVR_PlayNotifyT;


/*!
*******************************************************************************
**
** \brief Notification function called by playback engine.
**
**        This function will be called by a playback instance if one of the
**        following events occur:
**        - A file error or another error occurs.
**        - The file end was reached.
**
** \param reason  Reason for notification.
** \param error   Error code of occurred error.
**
** \sa    PVR_PLAY_OPEN_S
**
******************************************************************************/
typedef void (*PVR_PlayCallback)(FAPI_SYS_HandleT playHandle,
                                 PVR_PlayNotifyT reason);


/*!
*******************************************************************************
**
** \brief Playback engine seek modes.
**
**        This enumeration type defines the different seek modes available
**        during playback.
**
**        For all seek modes the following rules apply:
**        - The seek position will be aligned to multiples of data chunks.
**        - If the new position is less than zero it will be set to zero,
**          (the beginning of the file).
**        - If the new position is larger than the size of the file size it
**          will be set to the end of the file.
**
** \sa    PVR_SeekPlayback
**
******************************************************************************/
typedef enum
{
    /*!
    ** Seek to an absolute position in number of data chunks.
    ** The seek value indicates the absolute number of data chunks.
    ** The size of one data chunk is 96256 bytes (94 kbytes).
    */
    PVR_SEEK_MODE_CHUNKS,

    /*!
    ** Seek forward relatively for a number of data chunks.
    ** The seek value indicates the number of data chunks to seek forward.
    ** The size of one data chunk is 96256 bytes (94 kbytes).
    */
    PVR_SEEK_MODE_CHUNKS_FORWARD,

    /*!
    ** Seek backward relatively for a number of data chunks.
    ** The seek value indicates the number of data chunks to seek backward.
    ** The size of one data chunk is 96256 bytes (94 kbytes).
    */
    PVR_SEEK_MODE_CHUNKS_BACKWARD,

    /*!
    ** Seek forward to next name.
    ** If there is no new name the engine will seek to the end of
    ** the file. The seek value has no meaning.
    */
    PVR_SEEK_MODE_NAME_FORWARD,

    /*!
    ** Seek backward to previous name.
    ** If there is no other previous name the engine will seek to the
    ** beginning of the file. The seek value has no meaning.
    */
    PVR_SEEK_MODE_NAME_BACKWARD,

    /*!
    ** Seek forward to next tag.
    */
    PVR_SEEK_MODE_TAG_FORWARD,

    /*!
    ** Seek backward to previous tag.
    */
    PVR_SEEK_MODE_TAG_BACKWARD,

    /*!
    ** Seek forward to next chunk that contains an I-Frame
    */
    PVR_SEEK_MODE_IFRAME_FORWARD,

    /*!
    ** Seek backward to previous chunk that contains an I-Frame
    */
    PVR_SEEK_MODE_IFRAME_BACKWARD,
    
    /*!
    ** Seek to a given playback time. The value argument represents the 
    ** requested playback time in milliseconds.
    */
    PVR_SEEK_MODE_TIME,
    
} PVR_SeekModeT;

typedef enum
{
    PVR_DECMODE_NONE   = -1,    //!< Invalid mode.
    PVR_DECMODE_NORMAL = 0,     //!< Normal playback.
    PVR_DECMODE_PAUSE,          //!< Paused playback.
    PVR_DECMODE_FAST,           //!< Fast forward/backward mode,
                                //!< further specified by modeIndex
    PVR_DECMODE_SLOW,           //!< Slow forward mode, further specified by
                                //!< modeIndex.
    PVR_DECMODE_FEEDDATA,       //!< Special mode where decoder awaits data 
                                //!< units provided by 'feedData' and displays
                                //!< them (e.g. Intra-Frames in case of 
                                //!< video decoder).
    PVR_DECMODE_FEEDCTRL        //!< Special mode that uses decoder interface
                                //!< similar to fast mode type 
                                //!< PVR_FASTMODETYPE_FEED_CONTROLLED, i.e.
                                //!< prepareData and isDataDecoded.
    
} PVR_DecoderModeT;

typedef enum
{
    PVR_DECTYPE_VIDEO = 0,      //!< Video decoder.
    PVR_DECTYPE_AUDIO,          //!< Audio decoder.
    PVR_DECTYPE_AUDIO_2ND,      //!< Second audio decoder (e.g. for SPDIF).
    PVR_DECTYPE_TTX,            //!< Teletext decoder.
    PVR_DECTYPE_NUMS,           //!< Number of decoders.
    
} PVR_DecoderTypeT;

typedef struct
{
    void*       (*open)          (PVR_DecoderTypeT type, void* argPtr);
    int32_t     (*close)         (PVR_DecoderTypeT type, void* argPtr,
                                  void* handlePtr);
    int32_t     (*start)         (PVR_DecoderTypeT type, uint8_t trackIndex,
                                  uint32_t trackData, PVR_TrackTypeT trackType,
                                  uint8_t trackFormat, void* argPtr,
                                  uint16_t pid, void* handlePtr);
    int32_t     (*stop)          (PVR_DecoderTypeT type, void* argPtr, 
                                  uint8_t freeze, void* handlePtr);
    int32_t     (*setMode)       (PVR_DecoderTypeT type, void* argPtr, 
                                  PVR_DecoderModeT mode, uint8_t modeIndex,
                                  void* handlePtr);
    int32_t     (*feedData)      (PVR_DecoderTypeT type, void* argPtr,
                                  const uint8_t* dataPtr, uint32_t dataBytes,
                                  void* handlePtr);
    int32_t     (*resetBuffer)   (PVR_DecoderTypeT type, void* argPtr, 
                                  void* handlePtr);
    uint32_t    (*getBufferSize) (PVR_DecoderTypeT type, void* argPtr,
                                  void* handlePtr);
    uint32_t    (*getBufferLevel)(PVR_DecoderTypeT type, void* argPtr,
                                  void* handlePtr);
    int32_t     (*prepareData)   (PVR_DecoderTypeT type, void* argPtr, 
                                  void* handlePtr);
    uint8_t     (*isDataDecoded) (PVR_DecoderTypeT type, void* argPtr,
                                  void* handlePtr);
    void        (*task)          (PVR_DecoderTypeT type, void* argPtr,
                                  void* handlePtr);
    
} PVR_DecoderControlT;

typedef struct
{
    /*!
    ** Optional argument passed with all callbacks in this structure.
    */
    void*               argPtr;
    
    /*!
    ** Optional control functions for all supported target decoders.
    */
    PVR_DecoderControlT decoder[PVR_DECTYPE_NUMS];
    
    /*!
    ** Optional A/V sync control.
    */
    int32_t             (*avSync)(uint8_t enable, PVR_DecoderTypeT source,
                                  void* argPtr);
    
} PVR_TargetControlT;


/*!
*******************************************************************************
**
** \brief Information about a PVR file.
**
**        This data structure is for holding information about a PVR file.
**
** \sa    PVR_GetFileInfo()
**
******************************************************************************/
typedef struct
{
    /*!
    ** Size of file in data chunks.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t size;

    /*!
    ** Duration in milliseconds.
    */
    uint32_t duration;

    /*!
    ** Offset to start of data within circular recorded files in data chunks.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t offset;

    /*!
    ** Initial tag.
    */
    uint32_t tag;

    /*!
    ** Initial name.
    */
    char_t name[PVR_NAME_LENGTH+1];

    /*!
    ** Number of tracks (PIDs) stored in the file.
    */
    uint8_t numberOfTracks;

    /*!
    ** Type of each track.
    */
    PVR_TrackTypeT trackType[PVR_MAX_TRACKS];

    /*!
    ** Additional user defined track information.
    ** For example, it can be used to store the language for audio tracks.
    */
    uint32_t trackInfo[PVR_MAX_TRACKS];
    
} PVR_FileInfoT;

/*!
*******************************************************************************
**
** \brief Parameters for opening a recording engine instance.
**
**        This data structure is for passing a number of parameters to
**        PVR_OpenRecording() when opening an instance of the recording
**        engine.
**
** \sa    PVR_OpenRecording()
**
******************************************************************************/
typedef struct
{
    /*!
    ** The version of the driver.
    ** \ref PVR_VersionEnumT "PVR_VERSION".
    */
    PVR_VersionEnumT version;

    /*!
    ** Name of file to record.
    ** The filename should not contain the path, but this depends on the
    ** underlying implementation of the file system.
    ** The maximum length is defined by #PVR_FILE_NAME_LENGTH.
    */
    char_t fileName[PVR_FILE_NAME_LENGTH+1];

    /*!
    ** Priority of recording engine thread.
    ** This priority should be higher than the one for playback
    ** to ensure reliable recording.
    ** The valid range depends on the deployed operation system.
    */
    uint8_t threadPriority;

    /*!
    ** Transport stream decoder (TSD) to be used for recording.
    ** This value is limited by #FAPI_TSD_MAX.
    */
    uint8_t tsdBlockIndex;

    /*!
    ** Flag to enable overwriting of an existing file.
    */
    uint8_t overwrite;

    /*!
    ** Base address of the buffer manager's (BM) hardware buffer 31.
    ** This buffer will be used to store the multiplexed transport
    ** stream before writing it to the hard-disk.
    ** 
    ** \note Global offset of corresponding buffer manager is subtracted 
    **       internally.
    */
    uint32_t bufferAddress;

    /*!
    ** Size of the hardware buffer (channel 31).
    ** Size of the buffer manager's (BM) hardware buffer 31.
    ** This buffer will be used to store the multiplexed transport
    ** stream before writing it to the hard-disk.
    ** It should be big enough to buffer several data chunks.
    ** A size of at least 0x80000 is recommended.
    */
    uint32_t bufferSize;

    /*!
    ** Maximum recording size in data chunks.
    ** If the file size reaches this limit the recording engine will
    ** either stop or loop to the beginning of the file
    ** (circular recording).
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t maxSize;

    /*!
    ** Flag to enable circular recording.
    ** Circular recording is particularly useful for implementing
    ** time-shift functionality. For enabling circular recording
    ** a size limit has to be set additionally.
    */
    uint8_t enableLooping;

    /*!
    ** Buffer filling limit for notification.
    ** If the buffer filling exceeds this limit the notification function
    ** will be called. For example, this could be used to take action
    ** to reduce the system load and. If the system load is that high
    ** that the recording engine thread is not processed, this limit will
    **  not be monitored.
    **
    ** \note Checking the buffer filling is not enabled when at least
    **       one PID is recorded as PES!
    **
    ** \sa PVR_RecordNotifyT
    */
    uint32_t fillingLimit;

    /*!
    ** Pointer to callback function.
    */
    PVR_RecordCallback callback;

    /*!
    ** Initial tag.
    ** It is possible to set another tag during recording, for example
    ** to set a user defined marker in the stream.
    ** During playback it is possible to seek to a specified tag.
    */
    uint32_t tag;

    /*!
    ** Initial name.
    ** It is possible to assign another name tag during recording,
    ** for example when the service name changes.
    ** The maximum length is defined in #PVR_NAME_LENGTH.
    */
    char_t name[PVR_NAME_LENGTH+1];

    /*!
    ** PCR PID.
    ** The PCR PID is only used for creating the PMT, i.e. for
    ** recording with enabled swapBytes (and without PES).
    ** If no PCR shall be assigned set this PID to 0x1FFF.
    */
    uint16_t pcrPid;

    /*!
    ** Number of tracks (PES streams) to record.
    ** The maximum number of tracks is defined by #PVR_MAX_TRACKS.
    */
    uint8_t numberOfTracks;

    /*!
    ** PID of each track (PES stream) to record.
    */
    uint16_t trackPid[PVR_MAX_TRACKS];

    /*!
    ** Type of each track (PES stream) to record.
    */
    PVR_TrackTypeT trackType[PVR_MAX_TRACKS];

    /*!
    ** Type-specific stream format of each track, one of PVR_TRACK_FORMAT_XXX.
    */
    uint8_t trackFormat[PVR_MAX_TRACKS];
    
    /*!
    ** Any additional information about each track.
    ** It is not relevant for the playback engine.
    ** It could be used as the language code for audio tracks.
    */
    uint32_t trackInfo[PVR_MAX_TRACKS];

    /*!
    ** Buffer address (optional).
    **
    ** If this PID shall be recorded as PES data (e.g. descrambled data)
    ** an extra buffer must be assigned. The transport stream
    ** decoder will be configured so that it extracts the PID's PES data
    ** into the assigned buffer. The recording engine will then (re-)make transport
    ** stream packets out of the PES data and multiplex them to a transport stream
    ** for recording. Note that no adaption field will be added, i.e. PCR information
    ** will be removed.
    **
    ** Set the buffer address and size to 0 if this PID shall decoded as
    ** transport stream packets (should be preferred -> better performance).
    **
    ** If at least one PID is recorded as PES the TS bytes will be swapped and
    ** arranged in the correct order (see swapBytes of this structure).
    */
    uint32_t trackBufferAddress[PVR_MAX_TRACKS];

    /*!
    ** Buffer size (optional).
    **
    ** \sa trackBufferAddress
    */
    uint32_t trackBufferSize[PVR_MAX_TRACKS];
    
    /*!
    ** Maximum split file size in units of #PVR_CHUNK_SIZE bytes.
    ** 
    ** The library can store a recording in multiple files.
    ** This function defines the default maximum size of one file.
    ** If the size of a file reaches this limit, the recording engine will
    ** close the file and proceed the recording in another file.
    ** 
    ** In case of FAT32 with a maximum file size of 4GB (minus one byte)
    ** this value will be 44620.
    ** The value of 0 will disable file splitting (default setting).
    ** 
    ** \note   File splitting is not possible for circular recordings
    **         (i.e. enableLooping == 1).
    */
    uint32_t fileSplitSize;
    
} PVR_RecordOpenT;


/*!
*******************************************************************************
**
** \brief Information about recording.
**
**        This data structure is for keeping information about a recording
**        process.
**
** \sa    PVR_GetRecordingInfo()
**
******************************************************************************/
typedef struct
{
    /*!
    ** Current size in data chunks.
    ** After looping the size will remain constant.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t size;

    /*!
    ** Current write position in data chunks.
    ** This value equals the current file size until looping occurs.
    ** In this case it indicates the current physical write position
    ** within the file.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t position;

    /*!
    ** Current duration in milliseconds.
    ** The duration will be continuously updated even after looping.
    ** In case of circular recording it represents the total duration
    ** of the recording rather than the duration of the remaining part
    ** of the written data.
    */
    uint32_t duration;

    /*!
    ** Flag to indicate that looping occurred.
    */
    uint8_t hasLooped;

    /*!
    ** Current filling of hardware buffer 31 in bytes.
    */
    uint32_t filling;

    /*!
    ** Current data rate in bits per second.
    ** It indicates the data rate of the data written to hard-disk.
    ** The average over three measurements is taken to avoid big variations.
    */
    uint32_t dataRate;

    /*!
    ** Current number of splits.
    */
    uint16_t splitCount;

    /*!
    ** Current split file size.
    */
    uint32_t splitSize;
    
} PVR_RecordInfoT;

typedef enum
{
    PVR_PLAY_MARKER_GENERAL = 0,           //!< general usage marker
    PVR_PLAY_MARKER_JUMP_IN,               //!< In point of a cut out scene
    PVR_PLAY_MARKER_JUMP_OUT,              //!< Out point of a cut out scene
    PVR_PLAY_MARKER_AB_REPEAT_IN,          //!< In point for AB repeat
    PVR_PLAY_MARKER_AB_REPEAT_OUT,         //!< Out point for AB repeat
    PVR_PLAY_MARKER_NUM,
    
} PVR_PlayMarkerTypeT;

/* Other types can be define in future, e.g. markers for AB repeat, copy area */

/*!
*******************************************************************************
**
** \brief Structure to define markers to be used as jump markers or cut out areas.
**
**
** \sa
**
******************************************************************************/
typedef struct
{
    PVR_PlayMarkerTypeT type;           //!< type of marker
    uint32_t            position;       //!< block marker representing a chunk number
    uint32_t            time;           //!< time data of this chunk
    
} PVR_PlayMarkerT;

/*!
*******************************************************************************
**
** \brief Parameters for opening a playback engine instance.
**
**        This data structure is for passing a number of parameters to
**        PVR_OpenPlayback() when opening an instance of the playback engine.
**
** \sa    PVR_OpenPlayback()
**
******************************************************************************/
typedef struct
{
    /*!
    ** The version of the driver.
    ** \ref PVR_VersionEnumT "PVR_VERSION".
    */
    PVR_VersionEnumT version;

    /*!
    ** Name of file to playback.
    ** The filename should not contain the path, but this depends on the
    ** underlying implementation of the file system.
    ** The maximum length is defined by #PVR_FILE_NAME_LENGTH.
    */
    char_t fileName[PVR_FILE_NAME_LENGTH+1];

    /*!
    ** Priority of playback engine thread used for reading data from device
    ** and controlling the stream decoders.
    ** The valid range depends on the deployed operation system.
    */
    uint8_t readThreadPriority;
    
    /*!
    ** Priority of playback engine thread used for data output either by
    ** feeding it to the target TSD or to pass it to a user-defined function.
    ** The valid range depends on the deployed operation system.
    */
    uint8_t feedThreadPriority;

    /*!
    ** Transport stream decoder (TSD) to be used for playback.
    ** This value is limited by #FAPI_TSD_MAX.
    */
    uint8_t tsdBlockIndex;

    /*!
    ** Base address of hardware buffer for finding I-Frames.
    ** This buffer will be used for searching for still images during
    ** picture based fast modes.
    **
    ** \note Global offset of corresponding buffer manager is subtracted 
    **       internally.
    */
    uint32_t iFrameBufferAddress;

    /*!
    ** Size of hardware buffer for finding I-Frames in bytes.
    ** This buffer will be used for searching for still images during
    ** picture based fast mode. The buffer should be big enough to
    ** hold one I-Frame of the targeted maximum data rate. A value
    ** of 0x50000 is recommended to be compliant with the MPEG2 standard.
    ** 
    ** Note that only half of the buffer size is used for filtering. The second
    ** half is needed for recombining I-Frames splitted by a buffer wraparound.
    ** Hence choose the double amount here, 0xA0000 are recommended.
    */
    uint32_t iFrameBufferSize;
    
    /*!
    ** Hardware buffer to be checked for the filling level.
    ** Before reading TS packets from the file and feeding them
    ** into the transport stream decoder (TSD) the filling level
    ** of this buffer is checked. If this buffer is set to 0
    ** the playback engine will use automatically the video buffer
    ** (VBV) if video data is available or the audio buffer (ABV)
    ** respectively.
    */
    // TODO: not yet supported! needed?
    uint8_t bufferToCheck;

    /*!
    ** Flag to enable the re-initialising of the video decoder when
    ** starting playback. While it enables a proper start of the video
    ** decoder, video is blanked temporarily.
    */
    // TODO: not supported yet!
    uint8_t initVideoDecoderAlways;

    /*!
    ** Pointer to callback function.
    */
    PVR_PlayCallback callback;
    
    /*!
    ** Array of callback functions for each target decoder.
    */
    PVR_TargetControlT targetControl;
    
    /*!
    ** Absolute playback start position in chunks (for non-timeshift playback
       operations only!).
    */
    uint32_t startPosition;
    
} PVR_PlayOpenT;


/*!
*******************************************************************************
**
** \brief Information about playback.
**
**        This data structure is for keeping information about a running
**        playback.
**
** \sa    PVR_GetPlaybackInfo()
**
******************************************************************************/
typedef struct
{
    /*!
    ** Flag to indicate time shifting.
    ** If recording is closed during playback this flag will be set to
    ** 0 (false).
    */
    uint8_t isTimeShifting;

    /*!
    ** Total size in data chunks.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t size;

    /*!
    ** Physical offset to begin of data in data chunks.
    ** This value is greater than 0 for circular recorded files.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t offset;

    /*!
    ** Current physical read position in data chunks.
    ** In case of circular recorded files this value does not represent
    ** the logical position. To obtain the logical position
    ** the offset must be taken into account.
    ** The size of one data chunk is defined by #PVR_CHUNK_SIZE.
    */
    uint32_t position;

    /*!
    ** Total duration in milliseconds.
    ** For circular recorded files this value represents the total recording
    ** time.
    */
    uint32_t duration;

    /*!
    ** Current time in milliseconds.
    ** For circular recorded files the first value might be greater than 0.
    */
    uint32_t time;

    /*!
    ** Current tag.
    */
    uint32_t tag;

    /*!
    ** Current name.
    */
    char_t name[PVR_NAME_LENGTH+1];

    /*!
    ** Current data rate as determined during recording.
    */
    uint32_t dataRate;
    
} PVR_PlayInfoT;

/*!
*******************************************************************************
**
** \brief Track information.
**
**        This data structure holds current track information.
**
** \sa    PVR_GetPlaybackTrackInfo()
**
******************************************************************************/
typedef struct
{
    /*!
    ** Number of tracks (PIDs) stored in the file.
    */
    uint8_t numberOfTracks;

    /*!
    ** Type of each track.
    */
    PVR_TrackTypeT trackType[PVR_MAX_TRACKS];

    /*!
    ** Additional user defined track information.
    ** For example, it can be used to store the language for audio tracks.
    */
    uint32_t trackInfo[PVR_MAX_TRACKS];

    /*!
    ** PID of each track (PES stream).
    */
    uint16_t trackPid[PVR_MAX_TRACKS];
    
    /*!
    ** Type-specific stream format of each track, one of PVR_TRACK_FORMAT_XXX.
    */
    uint8_t trackFormat[PVR_MAX_TRACKS];
    
} PVR_TrackInfoT;

typedef enum
{
    PVR_FASTMODETYPE_IFRAMES = 0,   //!< Feeds only MPEG I-frames via callback 
                                    //!< feedData, allows forward and 
                                    //!< backwards modes.
    PVR_FASTMODETYPE_FEED_ALL,      //!< Feeds all data, decoder can e.g. 
                                    //!< discard every second frame, ...
    PVR_FASTMODETYPE_FEED_NONE,     //!< Feeds no data but seeks at a specified
                                    //!< speed rate.
    PVR_FASTMODETYPE_FEED_CONTROLLED//!< Feeds chunks of TS data controlled by
                                    //!< decoder via callback, allows forward
                                    //!< and backwards modes.
    
} PVR_FastModeTypeT;

typedef struct
{
    int32_t factor;             //!< Realtime multiplying factor, can also be 
                                //!< negative in order to seek in backwards
                                //!< direction.
    
    /*!
    ** Minimum time of showing an I-Frame in milliseconds.
    ** This time represents the minimum duration of showing a still image
    ** during picture based fast mode.
    ** The time for finding and copying an I-Frame
    ** depends on the data rate and current position within the stream.
    ** This might lead to unsteady and wavering display durations of the
    ** I-Frames. In order to avoid this ugly visual effect the playback
    ** engine may measure the search and copy time and depending on this
    ** adds an calculated sleep if necessary.
    ** This parameter may be a value between 0 (off) and 1000 (1 second).
    ** A value of 200 is recommended for streams up to around 8 MBit/s.
    */
    uint32_t displayTime;
    
} PVR_FastModeParamsIFramesT;

typedef struct
{
    uint32_t unused;        //!< Currently no parameters needed.
    
} PVR_FastModeParamsAllT;

typedef struct
{
    int32_t factor;         //!< Realtime multiplying factor, can also be 
                            //!< negative in order to seek in backwards
                            //!< direction.
    
} PVR_FastModeParamsNoneT;

typedef struct
{
    int32_t factor;         //!< Realtime multiplying factor, can also be 
                            //!< negative in order to seek in backwards
                            //!< direction.
    
    /*!
    ** Minimum presentation time of a frame in milliseconds.
    */
    uint32_t displayTime;
    
} PVR_FastModeParamsCtrlT;

typedef union
{
    PVR_FastModeParamsIFramesT  iFrames;    //!< for PVR_FASTMODETYPE_IFRAMES.
    PVR_FastModeParamsAllT      feedAll;    //!< for PVR_FASTMODETYPE_FEED_ALL.
    PVR_FastModeParamsNoneT     feedNone;   //!< for PVR_FASTMODETYPE_FEED_NONE.
    PVR_FastModeParamsCtrlT     feedCtrl;   //!< for PVR_FASTMODETYPE_FEED_CONTROLLED.
    
} PVR_FastModeParamsT;


/*!
*******************************************************************************
**
** \brief Fast mode configuration parameters.
**
** \sa    PVR_GetFastModeConfig(), PVR_SetFastModeConfig()
**
******************************************************************************/
typedef struct
{
    PVR_FastModeTypeT       type;       //!< Type of fast mode.
    PVR_FastModeParamsT     params;     //!< Parameters corresponding to type.
    
} PVR_FastModeConfigT;

/*!
*******************************************************************************
**
** \brief Crypto parameters.
**
**        This data structure holds parameters used for encryption of data
**        before writing to target device or decryption of data after reading
**        from target device.
**
** \sa    PVR_EnableRecordingEncryption(), PVR_EnablePlaybackDecryption()
**
******************************************************************************/
typedef struct
{
    /*!
    ** Most significant bytes of crypto key (bytes 15...8).
    */
    uint32_t keyMSB;
    
    /*!
    ** Least significant bytes of crypto key (bytes 7...0).
    */
    uint32_t keyLSB;
    
} PVR_CryptoParamsT;

#endif

//***********************************************************************
//***********************************************************************
//** Global Data
//***********************************************************************
//***********************************************************************


//***********************************************************************
//***********************************************************************
//** API Functions
//***********************************************************************
//***********************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#if 0

int32_t          PVR_Init               (void);
void             PVR_Exit               (void);

/* general functions */
int32_t          PVR_GetFileInfo        (const char_t* fileNamePtr,
                                         PVR_FileInfoT* fileInfoPtr);
int32_t          PVR_DeleteFile         (const char_t* fileNamePtr);
int32_t          PVR_SetMountPath       (const char_t* pathPtr);
const char_t*    PVR_GetMountPath       (void);
int32_t          PVR_SetFileExtension   (const char_t* extPtr);
const char_t*    PVR_GetFileExtension   (void);
int32_t          PVR_SetFileSplitParams (uint8_t numDigits,
                                         uint8_t decimalNotation);

/* recording engine */
FAPI_SYS_HandleT PVR_OpenRecording (const PVR_RecordOpenT* paramsPtr,
                                    int32_t* errorCodePtr);
int32_t          PVR_CloseRecording (FAPI_SYS_HandleT handle);
int32_t          PVR_SetRecordingMode (FAPI_SYS_HandleT handle,
                                       PVR_RecordModeT recordMode);
int32_t          PVR_GetRecordingMode (FAPI_SYS_HandleT handle,
                                       PVR_RecordModeT* recordModePtr);
int32_t          PVR_SetRecordingPids (FAPI_SYS_HandleT handle,
                                       const uint16_t* trackPidsPtr,
                                       const uint8_t* trackFormatPtr);
int32_t          PVR_SetRecordingPmt (FAPI_SYS_HandleT handle,
                                      uint16_t pmtPid, const uint8_t* pmtPtr,
                                      uint32_t pmtSize,
                                      const uint16_t* trackPidsPtr,
                                      const uint8_t* trackFormatPtr);
int32_t          PVR_SetRecordingTag (FAPI_SYS_HandleT handle, uint32_t tag);
int32_t          PVR_SetRecordingName (FAPI_SYS_HandleT handle,
                                       const char_t* namePtr);
int32_t          PVR_GetRecordingOpen (FAPI_SYS_HandleT handle,
                                       PVR_RecordOpenT* recordOpenPtr);
int32_t          PVR_GetRecordingInfo (FAPI_SYS_HandleT handle,
                                       PVR_RecordInfoT* recordInfoPtr);
int32_t          PVR_SetRecordingStopPos (FAPI_SYS_HandleT handle,
                                          uint32_t position);
int32_t          PVR_GetRecordingStopPos (FAPI_SYS_HandleT handle,
                                          uint32_t* positionPtr);
int32_t          PVR_SetRecordingPerfLimitTimeout (FAPI_SYS_HandleT handle,
                                                   uint32_t timeout);
int32_t          PVR_GetRecordingPerfLimitTimeout (FAPI_SYS_HandleT handle,
                                                   uint32_t* timeoutPtr);
int32_t          PVR_SetRecordingChannels (const uint8_t* channelsPtr);
int32_t          PVR_SetRecordingSourcePlayback (FAPI_SYS_HandleT playHandle,
                                                 FAPI_SYS_HandleT recHandle);
int32_t          PVR_FlushRecordingData (FAPI_SYS_HandleT handle,
                                         PVR_RecordInfoT* recordInfoPtr);
int32_t          PVR_SetFlushingFrequency (FAPI_SYS_HandleT handle,
                                           uint32_t numberOfChunks);
int32_t          PVR_EnableRecordingEncryption(FAPI_SYS_HandleT handle,
                                               const PVR_CryptoParamsT*
                                               paramsPtr);

/* playback engine */
FAPI_SYS_HandleT PVR_OpenPlayback (const PVR_PlayOpenT* paramsPtr,
                                   int32_t* errorCodePtr);
int32_t          PVR_ClosePlayback (FAPI_SYS_HandleT handle);
int32_t          PVR_SeekPlayback (FAPI_SYS_HandleT handle,
                                   PVR_SeekModeT mode, uint32_t value);
int32_t          PVR_SetPlaybackMode (FAPI_SYS_HandleT handle,
                                      PVR_PlayModeT playMode,
                                      uint8_t modeIndex);
int32_t          PVR_GetPlaybackMode (FAPI_SYS_HandleT handle,
                                      PVR_PlayModeT* playModePtr,
                                      uint8_t* modeIndexPtr);
int32_t          PVR_SetPlaybackTrack (FAPI_SYS_HandleT handle,
                                       PVR_DecoderTypeT type,
                                       uint8_t trackIndex, uint32_t trackData);
int32_t          PVR_GetPlaybackTrack (FAPI_SYS_HandleT handle,
                                       PVR_DecoderTypeT type,
                                       uint8_t* trackPtr);
int32_t          PVR_GetPlaybackFileInfo (FAPI_SYS_HandleT handle,
                                          PVR_FileInfoT* fileInfoPtr);
int32_t          PVR_GetPlaybackTrackInfo (FAPI_SYS_HandleT handle,
                                           PVR_TrackInfoT* trackInfoPtr);
int32_t          PVR_GetPlaybackInfo (FAPI_SYS_HandleT handle,
                                      PVR_PlayInfoT* playInfoPtr);
int32_t          PVR_EnablePlaybackOfFrames (FAPI_SYS_HandleT handle,
                                             uint8_t enable);
int32_t          PVR_SetPlaybackFunction (FAPI_SYS_HandleT handle,
                                          PVR_PlaybackFeedOutput function);
int32_t          PVR_EnablePlaybackDecryption(FAPI_SYS_HandleT handle,
                                              const PVR_CryptoParamsT*
                                              paramsPtr);

int32_t          PVR_GetFastModeConfig (uint16_t index,
                                        PVR_FastModeConfigT* configPtr);
int32_t          PVR_SetFastModeConfig (uint16_t index,
                                        const PVR_FastModeConfigT* configPtr);

/* functions that support handling of playback edit markers
   -> NOT IMPLEMENTED YET!
*/
#if 0
int32_t          PVR_InitPlaybackMarker(FAPI_SYS_HandleT handle,
                                      PVR_PlayMarkerT* markerPtr,
                                      uint32_t* numMarkerPtr);
int32_t          PVR_EnablePlaybackMarker(FAPI_SYS_HandleT handle,
                                 uint8_t enable);
int32_t          PVR_SetPlaybackMarker(FAPI_SYS_HandleT handle,
                                       PVR_PlayMarkerTypeT type,
                                       uint32_t maxNumMarker);
int32_t          PVR_RemovePlaybackMarker(FAPI_SYS_HandleT handle,
                                          uint32_t maxNumMarker,
                                          uint32_t* positionPtr);
int32_t          PVR_RepairRecordingHeader(char_t *path, PVR_RecordInfoT* recordInfoPtr);
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif /* PVR_H */
