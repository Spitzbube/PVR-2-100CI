/*
*****************************************************************************
**
** \file        ./middleware/pvr/src/pvr.c
** 
** \brief       PVR middleware.
**
** This file contains the implementation of the PVR core API.
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

#include <fapi/sys_services.h>

#if 0

#include <fapi/drv_tsd.h>

#include "pvr.h"
#include "pvr_priv.h"
#include "pvr_record.h"
#include "pvr_play.h"

/*lint -save -e717 -e788 */

/* NOTE: the following LINT statements have been suppressed:
- Info 717: do ... while(0);
- Info 788: enum constant 'anyConst' not used within defaulted switch
*/

//***************************************************************************
//***************************************************************************
//** Local Defines
//***************************************************************************
//***************************************************************************

//***************************************************************************
//***************************************************************************
//** Local Structures
//***************************************************************************
//***************************************************************************

//***************************************************************************
//***************************************************************************
//** Local Data
//***************************************************************************
//***************************************************************************

                            /* to set if PVR library is initialized */
static uint32_t             pvrInitialized  = 0;
                            /* array of PVR handles */
static FAPI_SYS_HandleT     pvrHandleRec [FAPI_TSD_MAX];
static FAPI_SYS_HandleT     pvrHandlePlay[FAPI_TSD_MAX];

//***************************************************************************
//***************************************************************************
//** Local Functions Declaration
//***************************************************************************
//***************************************************************************

static int32_t pvrCheckRecordingHandle (FAPI_SYS_HandleT h);
static int32_t pvrCheckPlaybackHandle  (FAPI_SYS_HandleT h);

//***************************************************************************
//***************************************************************************
//** Global Data
//***************************************************************************
//***************************************************************************


//***************************************************************************
//***************************************************************************
//** Local Functions
//***************************************************************************
//***************************************************************************

static int32_t pvrCheckRecordingHandle (FAPI_SYS_HandleT h)
{
    uint32_t cnt;

    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else if ( h != NULL )
    {
        for ( cnt = 0; cnt < FAPI_TSD_MAX; cnt++ )
        {
            if ( pvrHandleRec[cnt] == h)  return FAPI_OK;
        }
    }

    return MIDDLEWARE_PVR_ERR_INVALID_HANDLE;
}

static int32_t pvrCheckPlaybackHandle (FAPI_SYS_HandleT h)
{
    uint32_t cnt;

    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else if ( h != NULL )
    {
        for ( cnt = 0; cnt < FAPI_TSD_MAX; cnt++ )
        {
            if ( pvrHandlePlay[cnt] == h)  return FAPI_OK;
        }
    }

    return MIDDLEWARE_PVR_ERR_INVALID_HANDLE;
}

//***************************************************************************
//***************************************************************************
//** API Functions
//***************************************************************************
//***************************************************************************

/*!
*****************************************************************************
** \brief Initialize the PVR library.
**
** This function initializes the PVR library.
**
** \attention It is assumed that hardware register layer and FAPI drivers have
**            been initialized before.
**
** \return
**        - #FAPI_OK if initialization was successful
**        - #MIDDLEWARE_PVR_ERR_ALREADY_INITIALIZED if the function has already
**          been called.
**
** \sa PVR_Exit
*****************************************************************************
*/
int32_t PVR_Init(void)
{
    int32_t     result = FAPI_OK;
    uint32_t    cnt;

    do
    {
        /*lint -save -e506 -e774 */
        
        if ( pvrInitialized )
        {
            result = MIDDLEWARE_PVR_ERR_ALREADY_INITIALIZED;
            break;
        }
        else if ( sizeof(PVR_HeaderPacketT) != (2 * PVR_TSPKT_SIZE))
        {
            result = MIDDLEWARE_PVR_ERR_BAD_PACKET_SIZE;
            break;
        }
        
        /* check data chunk size */
        else if ( ((PVR_CHUNK_SIZE % PVR_TSPKT_SIZE) != 0)
               || ((PVR_CHUNK_SIZE % 512           ) != 0) )
        {
            result = MIDDLEWARE_PVR_ERR_BAD_PACKET_SIZE;
            break;
        }
        /*lint -restore */
        
        result = pvrPrivInit();
        if ( result != FAPI_OK )
        {
            break;
        }

        result = pvrRecInit();
        if ( result != FAPI_OK )
        {
            break;
        }

        result = pvrPlayInit();
        if ( result != FAPI_OK )
        {
            break;
        }

        for ( cnt = 0; cnt < FAPI_TSD_MAX; cnt++)
        {
            pvrHandleRec[cnt]  = NULL;
            pvrHandlePlay[cnt] = NULL;
        }

        pvrInitialized = 1;
    }
    while ( 0 );

    return result;
}

/*!
*****************************************************************************
** \brief Exit the PVR library.
**
** This function shuts down the PVR library. All allocated resources will be 
** released.
**
** \sa PVR_Init
*****************************************************************************
*/
void PVR_Exit(void)
{
    if ( pvrInitialized )
    {
        (void)pvrRecExit();
        (void)pvrPlayExit();

        pvrInitialized = 0;
    }
}

/*!
*******************************************************************************
**
** \brief  Provides information about an available PVR file.
**
**         This functions opens the file with the assigned filename and reads
**         the first packet. This header packet contains information about the
**         recorded stream which will be copied to the provided
**         #PVR_FileInfoT data structure. Finally, the file will be closed.
**
** \note   For circular recorded files the tag, name or track PIDs are not
**         necessarily the initial values as they might change during
**         recording.
**
** \param  fileNamePtr  Pointer to filename.
** \param  fileInfoPtr  Pointer to a file info structure PVR_FileInfoT
**                      that shall be filled.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_FILE_FORMAT
**         - #MIDDLEWARE_PVR_ERR_BAD_FILE_VERSION
**         - #MIDDLEWARE_PVR_ERR_FILE_HANDLING
**         - #MIDDLEWARE_PVR_ERR_FILE_READ
**
******************************************************************************/
int32_t PVR_GetFileInfo(const char_t* fileNamePtr, PVR_FileInfoT* fileInfoPtr)
{
    int32_t result;
    
    if ( !pvrInitialized )
    {
        result = MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else if ( (fileNamePtr == NULL) || (fileInfoPtr == NULL) )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else if ( strlen(fileNamePtr) > PVR_FILE_NAME_LENGTH )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrGetFileInfo (fileNamePtr, fileInfoPtr, NULL);
    }
    
    return result;
}

/*!
*******************************************************************************
**
** \brief  Deletes a file.
**
**         This functions deletes a PVR file and all its potentially existing
**         split files. The mount path will be appended to the filename.
**
** \param  fileNamePtr   Pointer to filename.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
******************************************************************************/
int32_t PVR_DeleteFile(const char_t* fileNamePtr)
{
    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else if ( fileNamePtr == NULL )
    {
        return MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else if ( strlen(fileNamePtr) > PVR_FILE_NAME_LENGTH )
    {
        return MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    pvrDeleteFiles(fileNamePtr);

    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Sets the mount path.
**
**         The maximum length of the path is defined in
**         #PVR_PATH_NAME_LENGTH.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetMountPath()
**
******************************************************************************/
int32_t PVR_SetMountPath(const char_t* pathPtr)
{
    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else
    {
        return pvrSetMountPath(pathPtr);
    }
}

/*!
*******************************************************************************
**
** \brief  Returns the current mount path.
**
** \return Pointer to the mount path.
**
** \sa     PVR_SetMountPath()
**
******************************************************************************/
const char_t* PVR_GetMountPath(void)
{
    if ( !pvrInitialized )
    {
        return NULL;
    }
    else
    {
        return pvrGetMountPath();
    }
}

/*!
*******************************************************************************
**
** \brief  Set optional file extension string or disable file extension usage.
**
**         If a file extension is requested, all file names passed with
**         #PVR_OpenRecording and #PVR_OpenPlayback will be extended like this:
**
**         filename.extension
**
**          If a split file is generated, its extension will be replaced by the
**          digits of the split file number, for example:
**
**          1st file:   abc.ts <br>
**          2nd file:   abc.01
**
**          If a filename extension is not used (default), the digits for
**          numbering the split files are simply appended to the file name:
**
**          1st file:   abc <br>
**          2nd file:   abc01
**
** \param  extPtr   Pointer to extension string, maximum number of characters
**                  is #PVR_FILE_EXT_LENGTH. In order to disable usage of a file
**                  extension, pass a NULL pointer.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetFileExtension()
**
******************************************************************************/
int32_t PVR_SetFileExtension (const char_t* extPtr)
{
    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else
    {
        return pvrSetFileExtension(extPtr);
    }
}

/*!
*******************************************************************************
**
** \brief  Returns file extension string.
**
** \return Pointer to file extension string or NULL if file extension usage is
**         disabled.
**
** \sa     PVR_SetFileExtension()
**
******************************************************************************/
const char_t* PVR_GetFileExtension (void)
{
    if ( !pvrInitialized )
    {
        return NULL;
    }
    else
    {
        return pvrGetFileExtension();
    }
}

/*!
*******************************************************************************
**
** \brief  Set parameters for split file name generation.
**
**          This function allows to specify how numbering for split files is
**          performed. See #PVR_DEFAULT_SPLIT_DIGITS and
**          #PVR_DEFAULT_SPLIT_USE_DEC for default behaviour.
**
** \param  numDigits        Number of digits used for number, must be less or
**                          equal to PVR_FILE_EXT_LENGTH.
** \param  decimalNotation  If 0, hexadecimal notation is used,
**                          otherwise decimal digits are used.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_SetFileExtension()
**
******************************************************************************/
int32_t PVR_SetFileSplitParams (uint8_t numDigits, uint8_t decimalNotation)
{
    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else
    {
        return pvrSetFileSplitParams(numDigits, decimalNotation);
    }
}

/*!
*****************************************************************************
** \brief Opens an instance of the recording engine.
**
** \param paramsPtr Pointer to the open parameters.
** \param errorCodePtr Pointer where error code should be stored or 0 if unused.
**
** \return
**         - (>0) valid driver instance handle on success.
**         - (0) if the driver couldn't be opened. For further information
**           about error reason please see errorCodePtr argument.
**
** \sa PVR_CloseRecording
** 
*****************************************************************************
*/
FAPI_SYS_HandleT PVR_OpenRecording (const PVR_RecordOpenT* paramsPtr,
                                    int32_t* errorCodePtr)
{
    char_t              file_path[PVR_FULL_FILEPATH_LENGTH + 1];
    FAPI_SYS_HandleT    handle     = NULL;
    int32_t             error_code = FAPI_OK;
    int32_t             fileRes;
    F_FIND              find;
    
    /* error if driver not initialized */
    if ( pvrInitialized == 0 )
    {
        error_code = MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }

    else if ( paramsPtr == NULL )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    /* check version */
    else if ( !FAPI_SYS_CHECK_VERSION(paramsPtr->version, PVR_VERSION) )
    {
        error_code = MIDDLEWARE_PVR_ERR_UNSUPPORTED_VERSION;
    }

    /* check parameters */
    else if ( (paramsPtr->tsdBlockIndex != FAPI_TSD0)
           && (paramsPtr->tsdBlockIndex != FAPI_TSD1)
           && (paramsPtr->tsdBlockIndex != FAPI_TSD2)
           && (paramsPtr->tsdBlockIndex != FAPI_TSD3) )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    else if ( (paramsPtr->numberOfTracks == 0)
           || (paramsPtr->numberOfTracks >= PVR_MAX_TRACKS) )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    /* check whether size is 1K aligned */
    else if ( (paramsPtr->bufferSize == 0)
          || ((paramsPtr->bufferSize & 0x3FF) != 0) )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    /* check filling limit */
    else if ( paramsPtr->fillingLimit > paramsPtr->bufferSize )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    /* check whether the requested TSD is in use */
    else if ( pvrHandleRec[paramsPtr->tsdBlockIndex] != NULL )
    {
        error_code = MIDDLEWARE_PVR_ERR_TSD;
    }
    
    /* NOTE: paramsPtr is checked again in order to satisfy MISRA */
    
    if ( (error_code == FAPI_OK) && (paramsPtr != NULL) )
    {
        /* create filename */
        pvrGetFilename(file_path, paramsPtr->fileName, 0);
        
        /* check if file exists and delete it if overwriting is enabled */
        fileRes = f_findfirst(file_path, &find);
        if ( fileRes == F_NO_ERROR )
        {
            /* file has been found */
            if ( paramsPtr->overwrite == 0 )
            {
                 error_code = MIDDLEWARE_PVR_ERR_FILE_EXISTS;
            }
            else
            {
                pvrDeleteFiles(paramsPtr->fileName);
            }
        }
        
        /* open recording engine */
        if ( error_code == FAPI_OK )
        {
            error_code = pvrRecOpen(paramsPtr, &handle);
        
            if ( error_code == FAPI_OK )
            {
                /* create and assign handle */
                pvrHandleRec[paramsPtr->tsdBlockIndex] = handle;
            }
            else
            {
                handle = NULL;
            }
        }
    }
    
    if ( errorCodePtr != NULL )
    {
        *errorCodePtr = error_code;
    }
    
    return handle;
}

/*!
*****************************************************************************
** \brief  Closes a recording instance.
**
**         This function destroys the corresponding recording thread,
**         releases the allocated memory and closes the recorded file.
**         If this file is also being played (time-shifting), the related
**         playback instance will be notified.
**
**         The recording instance must not be running, otherwise the
**         function will fail and #MIDDLEWARE_PVR_ERR_BAD_MODE will be returned.
**
** \param handle Valid driver instance handle previously returned by
**               PVR_Open.
**
** \return
**        - #FAPI_OK if driver was successfully closed.
**        - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE if the given handle is invalid.
**
** \sa PVR_OpenRecording
** 
*****************************************************************************
*/
int32_t PVR_CloseRecording (FAPI_SYS_HandleT handle)
{
    PVR_RecordModeT recordMode;
    int32_t         error_code;
    int32_t         cnt;

    error_code = pvrCheckRecordingHandle(handle);

    if ( error_code == FAPI_OK )
    {
        error_code = PVR_GetRecordingMode(handle, &recordMode);

        if ( error_code == FAPI_OK )
        {
            if ( recordMode != PVR_RECORD_MODE_STOPPED )
            {
                error_code = MIDDLEWARE_PVR_ERR_BAD_MODE;
            }
            else
            {
                for ( cnt = 0; cnt < (int32_t)FAPI_TSD_MAX; cnt++)
                {
                    if  ( pvrHandlePlay[cnt] != NULL )
                    {
                        (void)pvrPlayNotifyRecordingClose(pvrHandlePlay[cnt],
                                                          handle);
                    }
                }

                error_code = pvrRecClose(handle);

                if ( error_code == FAPI_OK )
                {
                    for ( cnt = 0; cnt < (int32_t)FAPI_TSD_MAX; cnt++ )
                    {
                        if  ( pvrHandleRec[cnt] == handle )
                        {
                            pvrHandleRec[cnt] = NULL;
                        }
                    }
                }
            }
        }
    }

    return error_code;
}

/*!
*******************************************************************************
**
** \brief  Controls a recording instance.
**
**         This function controls an instance of the recording engine by
**         setting a new operating mode.
**         If the instance is already operating in the requested mode,
**         it will return without an error. If the instance is currently 
**         changing its mode #MIDDLEWARE_PVR_ERR_BAD_MODE will be returned.
**
**         Because changing the mode is done in an asynchronous way it
**         might take some milliseconds until the requested mode is entered.
**         During this state transition the instance will be in the temporary
**         mode #PVR_RECORD_MODE_CHANGING. The current mode can be
**         polled with PVR_GetRecordingMode().
**
**         The following recording modes can be set:
**         - #PVR_RECORD_MODE_NORMAL
**         - #PVR_RECORD_MODE_STOPPED
**         - #PVR_RECORD_MODE_PAUSE
**
** \param  handle      The handle of the recording engine instance.
** \param  recordMode  The new recording mode to enter.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**         - #MIDDLEWARE_PVR_ERR_BAD_MODE
**
** \sa     PVR_GetRecordingMode()
**
******************************************************************************/
int32_t PVR_SetRecordingMode(FAPI_SYS_HandleT handle,
                             PVR_RecordModeT recordMode)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        switch ( recordMode )
        {
            case PVR_RECORD_MODE_NORMAL:
                result = pvrRecStart(handle);
                break;

            case PVR_RECORD_MODE_STOPPED:
                result = pvrRecStop(handle);
                break;

            case PVR_RECORD_MODE_PAUSE:
                result = pvrRecPause(handle);
                break;

            default:
                result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
                break;
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns the current recording mode.
**
**         This function returns the current mode of a recording instance.
**
** \param  handle         The handle of the recording engine instance.
** \param  recordModePtr  Pointer to a recording mode variable
**                        #PVR_RecordModeT to be filled.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_SetRecordingMode()
**
******************************************************************************/
int32_t PVR_GetRecordingMode(FAPI_SYS_HandleT handle,
                             PVR_RecordModeT* recordModePtr)
{
    PVR_RecordModeT rm;
    int32_t         result;

    if ( recordModePtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);
        
        if ( result == FAPI_OK )
        {
            switch ( pvrRecGetInternalState(handle) )
            {
                case REC_STATE_OPENED:
                    rm = PVR_RECORD_MODE_STOPPED;
                    break;
        
                case REC_STATE_REC:
                    rm = PVR_RECORD_MODE_NORMAL;
                    break;
        
                case REC_STATE_REC_NO_DATA:
                    rm = PVR_RECORD_MODE_NORMAL;
                    break;
        
                case REC_STATE_STOPPED:
                    rm = PVR_RECORD_MODE_STOPPED;
                    break;
        
                case REC_STATE_PAUSE:
                    rm = PVR_RECORD_MODE_PAUSE;
                    break;
        
                default:
                    rm = PVR_RECORD_MODE_CHANGING;
                    break;
            }
            
            *recordModePtr = rm;
        }
    }
    
    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets a new tag.
**
**         This function sets a new tag to the recording file.
**         A tag is used to mark a position in the stream.
**         During playback it is possible to seek to such a marked position.
**
** \param  handle  The handle of the recording engine instance.
** \param  tag     The new tag to set.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_SetRecordingName()
**
******************************************************************************/
int32_t PVR_SetRecordingTag(FAPI_SYS_HandleT handle, uint32_t tag)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrRecSetTag (handle, tag);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets a new recording name.
**
**         This function sets a new name to the recording file.
**         This name could e.g. be the service name extracted from DVB service 
**         information (EIT present information).
**
**         The maximum length is defined by #PVR_NAME_LENGTH.
**
** \param  handle  The handle of the recording engine instance.
** \param  namePtr Pointer to the new name to set.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_SetRecordingTag()
**
******************************************************************************/
int32_t PVR_SetRecordingName(FAPI_SYS_HandleT handle, const char_t* namePtr)
{
    int32_t result;

    if ( namePtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else if ( strlen(namePtr) > PVR_NAME_LENGTH )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecSetName(handle, namePtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets new PID and format information for each track.
**
**         This function sets new track PIDs, for example to follow a changed
**         video PID during recording. Also a change in video/audio format can
**         be handled by setting a new trackFormat.
**         The recording engine will stop, re-configure and finally re-start
**         the corresponding TSD channels. A flag will be set within the
**         stream to indicate the PID change and allow for a callback during
**         playback.
**
** \param  handle         The handle of the recording engine instance.
** \param  trackPidsPtr   Pointer to array with the size of current number of
**                        tracks containing the new track PIDs. Set to NULL 
**                        for the case that no PIDs shall be updated.
** 
** \param  trackFormatPtr Pointer to array with the size of current number of
**                        tracks containing the new track format values. Set to
**                        NULL for the case that no track format shall be 
**                        updated.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_SetRecordingPmt()
**
******************************************************************************/
int32_t PVR_SetRecordingPids(FAPI_SYS_HandleT handle,
                             const uint16_t* trackPidsPtr,
                             const uint8_t* trackFormatPtr)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrRecSetPids(handle, trackPidsPtr, trackFormatPtr);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Hands over the PMT and set new PIDS for the recording.
**
**         Calling this function forces the recording engine to use the passed
**         PMT instead of creating it. A PAT will still be created referencing
**         this single PMT. The recording engine will make a copy of the PMT.
**         The recorded PIDs can be updated as well at the same time.
**
** \param  handle         The handle of the recording engine instance.
** \param  pmtPid         The PID of the PMT for the creating the PAT.
** \param  pmtPtr         Pointer to PMT section (max. size 1024 bytes).
** \param  pmtSize        Size of the PMT in bytes.
** \param  trackPidsPtr   Pointer to array with the size of current number of
**                        tracks containing the new track PIDs.
**                        Set to NULL for the case that no PIDs shall be
**                        updated.
** \param  trackFormatPtr Pointer to array with the size of current number of
**                        tracks containing the new track format values.
**                        Set to NULL for the case that no track format shall be
**                        updated.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_SetRecordingPids()
**
******************************************************************************/
int32_t PVR_SetRecordingPmt(FAPI_SYS_HandleT handle, uint16_t pmtPid,
                            const uint8_t* pmtPtr, uint32_t pmtSize,
                            const uint16_t* trackPidsPtr,
                            const uint8_t* trackFormatPtr)
{
    int32_t result;

    if ( pmtPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecSetPmt(handle, pmtPid, pmtPtr, pmtSize,
                                  trackPidsPtr, trackFormatPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns the open parameters.
**
**         This function returns the parameters used when opening the recording
**         instance. Those include the current PIDs of the recording.
**
** \param  handle         The handle of the recording engine instance.
** \param  recordOpenPtr  Pointer to an open recording structure
**                        #PVR_RecordOpenT for storing the requested
**                        information.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_SetRecordingPids()
**
******************************************************************************/
int32_t PVR_GetRecordingOpen(FAPI_SYS_HandleT handle,
                             PVR_RecordOpenT* recordOpenPtr)
{
    int32_t result;

    if ( recordOpenPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecGetOpen(handle, recordOpenPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns information about recording.
**
**         This function returns information about a running recording
**         process. This is for example the current duration or file size.
**
** \param  handle         The handle of the recording engine instance.
** \param  recordInfoPtr  Pointer to a recording info structure
**                        #PVR_RecordInfoT for storing the requested
**                        information.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
******************************************************************************/
int32_t PVR_GetRecordingInfo(FAPI_SYS_HandleT handle,
                             PVR_RecordInfoT* recordInfoPtr)
{
    int32_t result;

    if ( recordInfoPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecGetInfo(handle, recordInfoPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets the stop position.
**
**         This function sets a position at which the recording shall stop.
**         The data chunk at this position will not be overwritten.
**         The position 0xFFFFFFFF means that the stop limit is disabled
**         which is the default setting.
**
**         This function is particularly useful to define a stop limit
**         for circular recordings.
**
** \param  handle     The handle of the recording engine instance.
** \param  position   Physical stop position in #PVR_CHUNK_SIZE.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_GetRecordingStopPos()
**
******************************************************************************/
int32_t PVR_SetRecordingStopPos(FAPI_SYS_HandleT handle, uint32_t position)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrRecSetStopPosition(handle, position);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns the stop position.
**
**         This function returns the currently configured stop position. If 
**         no position is set, 0xFFFFFFFF will be returned.
**
** \param  handle        The handle of the recording engine instance.
** \param  positionPtr   Pointer to a variable for storing the stop position.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_SetRecordingStopPos()
**
******************************************************************************/
int32_t PVR_GetRecordingStopPos(FAPI_SYS_HandleT handle, uint32_t* positionPtr)
{
    int32_t result;

    if ( positionPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecGetStopPosition(handle, positionPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Set performance limit timeout for notification.
**
** If a recording thread is permanently busy with writing input data to the
** target device for the specified time inverval (i.e. no idle time due to
** empty input buffer), the recording will be paused and the notification
** function is called with reason #PVR_RECORD_NOTIFY_PERFORMANCE_LIMIT.
**
** This mechanism can be used to prevent a recording thread from blocking
** lower-priorized PVR operations, e.g. other recordings or playback.
** Set to zero for disabling performance limit monitoring.
**
** \note Checking the performance limit is not enabled when at least
**       one PID is recorded as PES!
**
** \param  handle     The handle of the recording engine instance.
** \param  timeout    Requested timeout in milliseconds. 0 disables performance
**                    monitoring.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetRecordingPerfLimitTimeout()
**
******************************************************************************/
int32_t PVR_SetRecordingPerfLimitTimeout(FAPI_SYS_HandleT handle,
                                         uint32_t timeout)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrRecSetPerfLimitTimeout(handle, timeout);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns the set performance limit timeout value.
**
** \param  handle       The handle of the recording engine instance.
** \param  timeoutPtr   Pointer to a variable for storing the timeout value
**                      expressed in milliseconds.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_SetRecordingPerfLimitTimeout()
**
******************************************************************************/
int32_t PVR_GetRecordingPerfLimitTimeout(FAPI_SYS_HandleT handle,
                                         uint32_t* timeoutPtr)
{
    int32_t result;

    if ( timeoutPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecGetPerfLimitTimeout(handle, timeoutPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets a custom TSD channel assignment for all TSDs used for recording.
**
** \param  channelsPtr    Array of PVR_MAX_TRACKS channel numbers, 0xFF: unused
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
******************************************************************************/
int32_t PVR_SetRecordingChannels(const uint8_t* channelsPtr)
{
    int32_t result;

    if ( channelsPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrRecSetChannels(channelsPtr);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Assign the current playback (on TSD to be recorded) as source of 
**         the recording.
**
** \param  playHandle   The handle of the playback engine instance.
** \param  recHandle    The handle of the recording engine instance.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
******************************************************************************/
int32_t PVR_SetRecordingSourcePlayback (FAPI_SYS_HandleT playHandle,
                                        FAPI_SYS_HandleT recHandle)
{
    int32_t result;
    
    result = pvrCheckRecordingHandle(recHandle);
    
    if (  result == FAPI_OK )
    {
        result = pvrCheckPlaybackHandle(playHandle);
        
        if ( result == FAPI_OK )
        {
            result = pvrPlaySetInternalMode(playHandle);
            
            if ( result == FAPI_OK )
            {
                result = pvrRecSetSourcePlayback(recHandle);
            }
        }
    }
    
    return result;
}

/*!
*******************************************************************************
**
** \brief  Flushes all data of current recording and returns updated record info.
**
** \note By using PVR_SetFlushingFrequency, data flushing can also be
**       automatically performed in a periodic manner.
**
** \param  handle         The handle of the recording engine instance.
** \param  recordInfoPtr  Pointer to a recording info structure
**                        #PVR_RecordInfoT for storing the requested
**                        information.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_FILE_HANDLING
**
** \sa     PVR_SetFlushingFrequency()
**
******************************************************************************/
int32_t PVR_FlushRecordingData(FAPI_SYS_HandleT handle,
                               PVR_RecordInfoT* recordInfoPtr)
{
    int32_t result;

    if ( recordInfoPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckRecordingHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrRecFlushRecordingData(handle, recordInfoPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets the frequency of data flushing or disables periodioc flushing.
**
**         This function sets the number of chunks after which the current
**         recording file will be flushed periodically. The recording header is
**         updated together with the file flushing. Using this feature allows
**         to access the recording event after a power loss. Data up to the
**         last flushing position will be available. Set 'numberOfChunks' to 0
**         in order to disable this feature.
**
** \note   The periodic flushing feature is disabled by default.
**
** \param  handle           The handle of the recording engine instance.
** \param  numberOfChunks   Number of chunks after which file will be flushed
**                          periodically, set to 0 to disable periodic flushing.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
******************************************************************************/
int32_t PVR_SetFlushingFrequency (FAPI_SYS_HandleT handle,
                                  uint32_t numberOfChunks)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrRecSetFlushingFrequency(handle, numberOfChunks);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Enable encryption of recording.
**
**         This function shall be called before actually starting the recording
**         with PVR_SetRecordingMode(). It will cause all data to be recorded 
**         to be encrypted before being written to the target device. For 
**         playback it is required to enable decryption using the same keys. 
**
** \param  handle       The handle of the recording engine instance.
** \param  paramsPtr    Parameters for encryption i.e. keys.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_EnablePlaybackDecryption()
******************************************************************************/
int32_t PVR_EnableRecordingEncryption (FAPI_SYS_HandleT handle,
                                       const PVR_CryptoParamsT* paramsPtr)
{
    int32_t result;

    result = pvrCheckRecordingHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrRecEnableEncryption(handle, paramsPtr);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Opens an instance of the playback engine.
**
**         This function creates an instance of the playback engine.
**         A thread is created and necessary memory is allocated.
**         It also opens the assigned PVR file. The function expects a 
**         PVR_PlayOpenT data structure filled with configuration data.
**         After opening the instance successfully the engine will enter
**         the mode #PVR_PLAY_MODE_STOPPED.
**
**         The function checks also whether the same file is currently
**         being recorded for time-shifting. In this case it will
**         setup an internal link to the recording instance for updating
**         the file size, duration and other information continuously.
**
**         A handle for addressing this instance will be returned.
**
**         The function may fail because of one of the following reasons:
**         - An instance of the playback engine is already open.
**         - No PVR_PlayOpenT is assigned.
**         - The requested TSD does not exist (see #FAPI_TSD_MAX).
**         - The requested TSD is already being used for recording.
**         - The length of the filename exceeds #PVR_FILE_NAME_LENGTH.
**         - The file does not exist.
**
** \param  paramsPtr  Pointer to a PVR_PlayOpenT data structure.
** \param  errorCodePtr Pointer where error code should be stored or 0 if unused.
**
** \return
**         - (>0) valid driver instance handle on success.
**         - (0) if the driver couldn't be opened. For further information
**           about error reason please see errorCodePtr argument.
**
** \sa     PVR_ClosePlayback()
**    <br> PVR_SeekPlayback()
**    <br> PVR_SetPlaybackMode()
**    <br> PVR_GetPlaybackMode()
**    <br> PVR_GetPlaybackFileInfo()
**    <br> PVR_GetPlaybackInfo()
**
******************************************************************************/
FAPI_SYS_HandleT PVR_OpenPlayback(const PVR_PlayOpenT* paramsPtr,
                                  int32_t* errorCodePtr)
{
    char_t              file_path[PVR_FULL_FILEPATH_LENGTH + 1];
    FAPI_SYS_HandleT    handle     = NULL;
    int32_t             error_code = FAPI_OK;
    FAPI_SYS_HandleT    recHandle;
    int32_t             fileRes;
    F_FIND              find;
    uint32_t            cnt;

    /* error if driver not initialized */
    if ( pvrInitialized == 0 )
    {
        error_code = MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }

    else if ( paramsPtr == NULL )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    /* check version */
    else if ( !FAPI_SYS_CHECK_VERSION(paramsPtr->version, PVR_VERSION) )
    {
        error_code = MIDDLEWARE_PVR_ERR_UNSUPPORTED_VERSION;
    }

    /* check parameters */
    else if ( (paramsPtr->tsdBlockIndex != FAPI_TSD0)
           && (paramsPtr->tsdBlockIndex != FAPI_TSD1)
           && (paramsPtr->tsdBlockIndex != FAPI_TSD2)
           && (paramsPtr->tsdBlockIndex != FAPI_TSD3) )
    {
        error_code = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    /* check whether the requested TSD is in use */
    else if ( pvrHandlePlay[paramsPtr->tsdBlockIndex] != NULL )
    {
        error_code = MIDDLEWARE_PVR_ERR_TSD;
    }
    
    /* NOTE: paramsPtr is checked again in order to satisfy MISRA */
    
    if ( (error_code == FAPI_OK) && (paramsPtr != NULL) )
    {
        /* create filename */
        pvrGetFilename(file_path, paramsPtr->fileName, 0);
        
        /* check if file exists */
        fileRes = f_findfirst(file_path, &find);
        if ( fileRes != F_NO_ERROR )
        {
             error_code = MIDDLEWARE_PVR_ERR_FILE_DOES_NOT_EXIST;
        }
        
        /* open playback engine */
        if ( error_code == FAPI_OK )
        {
            /* check if file is being recorded at the moment */
            recHandle = NULL;
        
            for ( cnt = 0; cnt < FAPI_TSD_MAX; cnt++ )
            {
                // FIXME: is this check sufficient? Filenames do not have 
                //        to be unique!
                if ( (pvrHandleRec[cnt] != NULL)
                  && (strcmp(pvrRecGetFilename(pvrHandleRec[cnt]),
                                  paramsPtr->fileName) == 0) )
                {
                    recHandle = pvrHandleRec[cnt];
                }
            }
        
            error_code = pvrPlayOpen(paramsPtr, recHandle, &handle);
            
            if ( error_code == FAPI_OK )
            {
                /* create and assign handle */
                pvrHandlePlay[paramsPtr->tsdBlockIndex] = handle;
            }
            else
            {
                handle = NULL;
            }
        }
    }
    
    if ( errorCodePtr != NULL )
    {
        *errorCodePtr = error_code;
    }

    return handle;
}

/*!
*****************************************************************************
** \brief  Closes a playback instance.
**
**         This function destroys the corresponding playback thread and
**         releases all allocated resources like memory and semaphores.
**
**         The playback  instance must not be running, otherwise the
**         function will fail and #MIDDLEWARE_PVR_ERR_BAD_MODE will be returned.
**
** \param handle Valid driver instance handle previously returned by
**               PVR_Open.
**
** \return
**        - #FAPI_OK if driver was successfully closed.
**        - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE if the given handle is invalid.
**        - #MIDDLEWARE_PVR_ERR_BAD_MODE if playback engine is not in stopped
**          mode.
**
** \sa PVR_OpenPlayback()
** 
*****************************************************************************
*/
int32_t PVR_ClosePlayback(FAPI_SYS_HandleT handle)
{
    int32_t             error_code;
    int32_t             cnt;
    PVR_PlayStateInfoT  stateInfo;

    error_code = pvrCheckPlaybackHandle(handle);

    if ( error_code == FAPI_OK )
    {
        error_code = pvrPlayGetState(handle, &stateInfo);

        if ( error_code == FAPI_OK )
        {
            if ( stateInfo.state != PLAY_STATE_STOPPED )
            {
                error_code = MIDDLEWARE_PVR_ERR_BAD_MODE;
            }
            else
            {
                error_code = pvrPlayClose(handle);

                if ( error_code == FAPI_OK )
                {
                    for ( cnt = 0; cnt < (int32_t)FAPI_TSD_MAX; cnt++ )
                    {
                        if  ( pvrHandlePlay[cnt] == handle )
                        {
                            pvrHandlePlay[cnt] = NULL;
                        }
                    }
                }
            }
        }
    }

    return error_code;
}

/*!
*****************************************************************************
** \brief  Performs seek operation on a playback instance.
**
**         This function seeks to another position. There are several
**         seek operations available defined in #PVR_SeekModeT.
**         Seek operations are only possible in playback modes
**         #PVR_PLAY_MODE_STOPPED and #PVR_PLAY_MODE_PAUSE.
**
** \param  handle   The handle of the playback engine instance.
** \param  mode     Seek mode #PVR_SeekModeT.
** \param  value    Seek position, distance, time etc. depending on mode.
**
** \return
**        - #FAPI_OK if driver was successfully closed.
**        - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE if the given handle is invalid.
**        - #MIDDLEWARE_PVR_ERR_BAD_MODE if playback engine is not in stopped
**          mode.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_MODE
*****************************************************************************
*/
int32_t PVR_SeekPlayback(FAPI_SYS_HandleT handle, PVR_SeekModeT mode,
                         uint32_t value)
{
    int32_t result;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrPlaySeek(handle, mode, value);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Controls a playback instance.
**
**         This function controls an instance of the playback engine by
**         setting a new operation mode.
**         If the instance is already operating in the requested mode,
**         it will come back without an error.
**         If the instance is currently changing its mode
**         #MIDDLEWARE_PVR_ERR_BAD_MODE will be returned.
**
**         Because changing the mode is done in an asynchronous way it
**         might take some milliseconds until the requested mode is entered.
**         During this state transition the instance will be in the temporary
**         mode #PVR_PLAY_MODE_CHANGING. The current mode can be
**         polled with PVR_GetPlaybackMode().
**
**         The following playback modes can be set:
**         - #PVR_PLAY_MODE_STOPPED
**         - #PVR_PLAY_MODE_NORMAL
**         - #PVR_PLAY_MODE_SLOW
**         - #PVR_PLAY_MODE_FAST
**         - #PVR_PLAY_MODE_PAUSE
**
** \param  handle    The handle of the playback engine instance.
** \param  playMode  The new playback mode to set.
** \param  modeIndex The new playback mode index to set.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**         - #MIDDLEWARE_PVR_ERR_BAD_MODE
**
** \sa     PVR_GetPlaybackMode()
**
******************************************************************************/
int32_t PVR_SetPlaybackMode(FAPI_SYS_HandleT handle, PVR_PlayModeT playMode,
                            uint8_t modeIndex)
{
    int32_t result;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        switch ( playMode )
        {
            case PVR_PLAY_MODE_STOPPED:
            case PVR_PLAY_MODE_NORMAL:
            case PVR_PLAY_MODE_SLOW:
            case PVR_PLAY_MODE_FAST:
            case PVR_PLAY_MODE_PAUSE:
                result = pvrPlaySetMode(handle, playMode, modeIndex);
                break;

            default:
                result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
                break;
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns the current playback mode.
**
**         This function returns the current mode of a playback instance.
**
** \param  handle       The handle of the playback engine instance.
** \param  playModePtr  Pointer to a playback mode variable #PVR_PlayModeT
**                      to be filled.
** \param  modeIndexPtr Pointer to a mode index variable to be filled.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_SetPlaybackMode()
**
******************************************************************************/
int32_t PVR_GetPlaybackMode(FAPI_SYS_HandleT handle, PVR_PlayModeT* playModePtr,
                            uint8_t* modeIndexPtr)
{
    PVR_PlayModeT       play_mode;
    int32_t             result;
    PVR_PlayStateInfoT  stateInfo;
    uint8_t             modeIndex  = 0;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrPlayGetState(handle, &stateInfo);

        if ( result == FAPI_OK )
        {
            switch ( stateInfo.state )
            {
                case PLAY_STATE_STOPPED:
                    play_mode = PVR_PLAY_MODE_STOPPED;
                    break;

                case PLAY_STATE_NORMAL:
                    play_mode = PVR_PLAY_MODE_NORMAL;
                    break;

                case PLAY_STATE_FAST_IFRAMES:
                case PLAY_STATE_FAST_ALL:
                case PLAY_STATE_FAST_NONE:
                case PLAY_STATE_FAST_CONTROLLED:
                    play_mode = PVR_PLAY_MODE_FAST;
                    modeIndex = stateInfo.stateIdx;
                    break;

                case PLAY_STATE_PAUSE:
                    play_mode = PVR_PLAY_MODE_PAUSE;
                    break;

                case PLAY_STATE_SLOW:
                    play_mode = PVR_PLAY_MODE_SLOW;
                    modeIndex = stateInfo.stateIdx;
                    break;

                default:
                    
                    /* NOTE: PLAY_STATE_SEEK is a transitional state and thus
                             also mapped as PVR_PLAY_MODE_CHANGING. */
                    
                    play_mode = PVR_PLAY_MODE_CHANGING;
                    break;
            }

            if ( playModePtr != NULL )
            {
                *playModePtr = play_mode;
            }

            if ( modeIndexPtr != NULL )
            {
                *modeIndexPtr = modeIndex;
            }
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Sets a track to playback for a decoder type.
**
**         This function changes the track which is assigned to
**         a decoder such as video or audio decoder. If the track is set
**         to 0xFF, the playback of the related decoder
**         will be stopped. This function could be used e.g. to change
**         the audio language.
**
** \param  handle      The handle of the playback engine instance.
** \param  decoderType The decoder type #PVR_DecoderTypeT.
** \param  trackIndex  The track for this media type (0xFF => not assigned).
** \param  trackData   Optional data passed to corresponding decoder when
**                     starting the track.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetPlaybackTrack()
**
******************************************************************************/
int32_t PVR_SetPlaybackTrack(FAPI_SYS_HandleT handle,
                             PVR_DecoderTypeT decoderType, uint8_t trackIndex,
                             uint32_t trackData)
{
    int32_t result;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrPlaySetTrack(handle, decoderType, trackIndex, trackData);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns the current track assigned to a decoder type.
**
**         The track will be set to 0xFF if there is no track assigned,
**         e.g. because the stream does not contain data suitable for the
**         given decoder type.
**
** \param  handle      The handle of the playback engine instance.
** \param  decoderType The decoder type #PVR_DecoderTypeT.
** \param  trackPtr    Pointer to a variable that shall be filled with the
**                     track.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**         - #MIDDLEWARE_PVR_ERR_NO_TRACK_ASSIGNED
**
** \sa     PVR_SetPlaybackTrack()
**
******************************************************************************/
int32_t PVR_GetPlaybackTrack(FAPI_SYS_HandleT handle,
                             PVR_DecoderTypeT decoderType, uint8_t* trackPtr)
{
    int32_t result;

    if ( trackPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckPlaybackHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrPlayGetTrack(handle, decoderType, trackPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns information about an open playback file.
**
** \param  handle       The handle of the playback engine instance.
** \param  fileInfoPtr  Pointer to a file info structure PVR_FileInfoT that
**                      shall be filled.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetPlaybackInfo()
**
******************************************************************************/
int32_t PVR_GetPlaybackFileInfo(FAPI_SYS_HandleT handle,
                                PVR_FileInfoT* fileInfoPtr)
{
    int32_t result;

    if ( fileInfoPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckPlaybackHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrPlayGetFileInfo(handle, fileInfoPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns information about a running playback.
**
** \param  handle       The handle of the playback engine instance.
** \param  playInfoPtr  Pointer to a play info structure PVR_PlayInfoT that
**                      shall be filled.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetPlaybackFileInfo()
**
******************************************************************************/
int32_t PVR_GetPlaybackInfo(FAPI_SYS_HandleT handle, PVR_PlayInfoT* playInfoPtr)
{
    int32_t result;

    if ( playInfoPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckPlaybackHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrPlayGetPlayInfo(handle, playInfoPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Returns information about tracks included in running playback.
**
** \param  handle        The handle of the playback engine instance.
** \param  trackInfoPtr  Pointer to a track info structure PVR_TrackInfoT that
**                       shall be filled.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa     PVR_GetPlaybackFileInfo()
**    <br> PVR_GetPlaybackInfo()
**
******************************************************************************/
int32_t PVR_GetPlaybackTrackInfo(FAPI_SYS_HandleT handle,
                                 PVR_TrackInfoT* trackInfoPtr)
{
    int32_t result;

    if ( trackInfoPtr == NULL )
    {
        result = MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else
    {
        result = pvrCheckPlaybackHandle(handle);

        if ( result == FAPI_OK )
        {
            result = pvrPlayGetTrackInfo(handle, trackInfoPtr);
        }
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Enables the playback of I-Frames in fast or seek mode.
**
**         This is enabled per default and should only be disabled for special
**         operations, e.g. special seek mechanisms.
**
** \param  handle     The handle of the playback engine instance.
** \param  enable     Flag to enable or display the previewing of I-Frames.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
******************************************************************************/
int32_t PVR_EnablePlaybackOfFrames(FAPI_SYS_HandleT handle, uint8_t enable)
{
    int32_t result;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrPlayEnableFrameView(handle, enable);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Registers a generic function for feeding data during playback.
**
** By default, an internal function will copy data read from the source device
** to the target TSD. Use this function if an alternative playback path is
** required, e.g. routing the TS data through an external device
** before feeding it back via standard TS input. All other playback
** configurations like setting of TSD filters remain.
**
** Note that this function enables TS input. For internal data feeding
**
**
**
** \param  handle     The handle of the playback engine instance.
** \param  function   Feeding function to be called during playback. Set to 0
**                    in order to restore default function.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**         - #MIDDLEWARE_PVR_ERR_BAD_MODE
**
******************************************************************************/
int32_t PVR_SetPlaybackFunction (FAPI_SYS_HandleT handle,
                                 PVR_PlaybackFeedOutput function)
{
    int32_t result;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrPlaySetPlayFunction(handle, function);
    }

    return result;
}

/*!
*******************************************************************************
**
** \brief  Enable decryption of playback.
**
**         This function shall be called before actually starting the playback
**         with PVR_SetPlaybackMode(). It will cause all data read from the 
**         target device to be decrypted before being output. For playback it
**         is required to enable decryption using the same keys. 
**
** \param  handle       The handle of the playback engine instance.
** \param  paramsPtr    Parameters for decryption i.e. keys.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_INVALID_HANDLE
**
** \sa     PVR_EnableRecordingEncryption()
******************************************************************************/
int32_t PVR_EnablePlaybackDecryption (FAPI_SYS_HandleT handle,
                                      const PVR_CryptoParamsT* paramsPtr)
{
    int32_t result;

    result = pvrCheckPlaybackHandle(handle);

    if ( result == FAPI_OK )
    {
        result = pvrPlayEnableDecryption(handle, paramsPtr);
    }

    return result;
}


/*!
*****************************************************************************
** \brief Get a fast mode configuration.
**
** \param index     Requested fast mode index to get configuration for.
** \param configPtr Pointer where fast mode configuration should be written to.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa PVR_SetFastModeConfig
** 
*****************************************************************************
*/
int32_t PVR_GetFastModeConfig (uint16_t index, PVR_FastModeConfigT* configPtr)
{
    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else if ( index >= PVR_MAX_FAST_MODES )
    {
        return MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    return pvrPlayGetFastModeConfig(index, configPtr);
}

/*!
*****************************************************************************
** \brief Set a fast mode configuration.
**
** \param index     Requested fast mode index to set configuration for.
** \param configPtr Pointer to fast mode configuration.
**
** \return Possible error codes:
**         - #FAPI_OK
**         - #MIDDLEWARE_PVR_ERR_NOT_INITIALIZED
**         - #MIDDLEWARE_PVR_ERR_BAD_PARAMETER
**
** \sa PVR_GetFastModeConfig
** 
*****************************************************************************
*/
int32_t PVR_SetFastModeConfig (uint16_t index,
                               const PVR_FastModeConfigT* configPtr)
{
    if ( !pvrInitialized )
    {
        return MIDDLEWARE_PVR_ERR_NOT_INITIALIZED;
    }
    else if ( index >= PVR_MAX_FAST_MODES )
    {
        return MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }
    else if ( configPtr == NULL )
    {
        return MIDDLEWARE_PVR_ERR_BAD_PARAMETER;
    }

    return pvrPlaySetFastModeConfig(index, configPtr);
}

#endif

/*lint -restore */
