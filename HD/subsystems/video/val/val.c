/*
*****************************************************************************
**
** \file        ./subsystems/video/val/src/val.c
**
** \brief       Video abstraction interface suitable for live and PVR playback.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2008-2009 by Fujitsu Microelectronics Limited
**
*****************************************************************************
*/

#define DEBUG 4

#define VAL_FASTMODE_SPEEDUP

#include <fapi/sys_services.h>
#include <fapi/drv_bm.h>
#include <fapi/drv_tsd.h>
#include <fapi/drv_videc.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_viscale.h>
#include <fapi/drv_hdmi.h>

#if 0
#include "fapex/abst_types.h"
#include "fapex/abst_libvienc.h"
#include "fapex/abst_libviout.h"
#include "fapex/abst_libvidec.h"
#include "fapex/abst_libtsd.h"
#include "fapex/abst_libhdmi.h"
#endif
#include "val.h"


//*****************************************************************************
//*****************************************************************************
//** Defines and macros
//*****************************************************************************
//*****************************************************************************

#define VAL_DEFAULT_HDSYS           VAL_1920x1080x50I //5
#define VAL_DEFAULT_SDSYS           VAL_SD_PAL //4
#define VAL_DEFAULT_AR_SD           FAPI_VISCALE_AR_NONE
#define VAL_DEFAULT_AR_HD           FAPI_VISCALE_AR_16_9
#define VAL_DEFAULT_SM_HD           FAPI_VISCALE_SM_PLBOX

#if 0
#define VAL_DEFAULT_DECODERFBSIZE   FAPEX_VIDEC_FRAME_BANK_SIZE_1920HD

#define VAL_HDMI_HDP_STATUS_MASK        0x0F
#define VAL_HDMI_HPD_STATUS_CONNECTED   0x06


//*****************************************************************************
//*****************************************************************************
//** Global functions
//*****************************************************************************
//*****************************************************************************

//***************************************************************************
//***************************************************************************
//** Global Data
//***************************************************************************
//***************************************************************************
int32_t        fd_VIOUT = -1;
extern int32_t fd_TSD[];

//***************************************************************************
//***************************************************************************
//** Local Defines
//***************************************************************************
//***************************************************************************
#define VIDEO_TSD_CHANNEL     9
#define DRV_ID_TSD0_VIDEO_CH  (FAPEXDEV_TSD0_SUB_MINOR_FIRST + VIDEO_TSD_CHANNEL)
#define DRV_ID_VIOUT          (FAPEXDEV_VIOUT_CMN_MINOR)
#define DRV_ID_VIOUT_HD       (FAPEXDEV_VIOUT_SUB_MINOR_FIRST + 0)
#define DRV_ID_VIOUT_SD       (FAPEXDEV_VIOUT_SUB_MINOR_FIRST + 1)
#define DRV_ID_VIDEC          (FAPEXDEV_VIDEC_MINOR_FIRST)
#define DRV_ID_VIENC          (FAPEXDEV_VIENC_CMN_MINOR)
#define DRV_ID_VIENC_HD       (FAPEXDEV_VIENC_SUB_MINOR_FIRST + 0)
#define DRV_ID_VIENC_SD       (FAPEXDEV_VIENC_SUB_MINOR_FIRST + 1)
#define DRV_ID_HDMI           (FAPEXDEV_HDMI_MINOR_FIRST)

//*****************************************************************************
//*****************************************************************************
//** Local data
//*****************************************************************************
//*****************************************************************************

#endif
static VAL_DataT    gnrDat; //21f77258
static VAL_OpenT    openDat; //21f77b94
static VAL_DataT*   gnrDataPtr  = NULL; //21f77254

//*****************************************************************************
//*****************************************************************************
//** Local Functions Declaration
//*****************************************************************************
//*****************************************************************************

static int32_t VAL_IntGoUp         (VAL_DataT* dataPtr,
                                    VAL_HdEncoderT hdSystemType,
                                    VAL_SdEncoderT sdSystemType);
#if 0
static int32_t VAL_IntGoDown       (VAL_DataT* dataPtr);
#endif
static int32_t VAL_IntOpen         (VAL_OpenT* openPtr,
                                    const VAL_OpenParamsT* paramsPtr);
#if 0
static int32_t VAL_IntClose        (VAL_OpenT* openPtr);
static int32_t VAL_IntStart        (VAL_OpenT* openPtr, uint32_t pid,
                                    VAL_PlayModeEnumT mode,
                                    uint8_t checkDecoderType);
static int32_t VAL_IntStop         (VAL_OpenT* openPtr, uint8_t freeze);
static int32_t VAL_IntReboot       (VAL_OpenT* openPtr,
                                    const VAL_DecoderTypeT* decoderPtr);
#endif
static int32_t VAL_ArgCheckOpen    (const VAL_OpenT* openPtr);

static int32_t VAL_ViencInitClocks (VAL_HdEncoderT hdSys);
static int32_t VAL_ViencOpen       (VAL_DataT* dataPtr,
                                    VAL_HdEncoderT hdSys,
                                    VAL_SdEncoderT sdSys);
static int32_t VAL_ViencClose      (VAL_DataT* dataPtr);

static int32_t VAL_HdmiOpen        (VAL_DataT* dataPtr);
static int32_t VAL_HdmiClose       (VAL_DataT* dataPtr);
#if 0
static int32_t VAL_HdmiUpdateStatus(VAL_DataT* dataPtr, uint8_t* connectedPtr,
                                    uint8_t* changePtr);
#endif

static int32_t VAL_ViscaleOpen     (VAL_DataT* dataPtr,
                                    VAL_HdEncoderT hdSys);
static int32_t VAL_ViscaleClose    (VAL_DataT* dataPtr);
static void    VAL_ViscaleParamChgCb(FAPI_VISCALE_ParamChangeInfoT* paramChangePtr,
                                    void* paramChangeOptData);

static int32_t VAL_ChannelOpen  (VAL_OpenT* openPtr, const VAL_OpenParamsT* paramsPtr, int);
#if 0
static int32_t VAL_ChannelClose (VAL_OpenT* openPtr);
static int32_t VAL_ChannelStart (VAL_OpenT* openPtr, uint16_t pid);
static int32_t VAL_ChannelStop  (VAL_OpenT* openPtr);
#endif

static int32_t VAL_VidecOpen       (VAL_OpenT* openPtr,
                                    const VAL_DecoderTypeT* decoderPtr,
                                    uint8_t enableAfd,
                                    VAL_EnvironmentT environment,
                                    int Data_16);
static int32_t VAL_VidecClose      (VAL_OpenT* openPtr);
#if 0
static int32_t VAL_VidecStart      (VAL_OpenT* openPtr,
                                    int32_t mode,
                                    uint8_t feedViaTsd,
                                    uint8_t checkDecoderType);
static int32_t VAL_VidecStop       (VAL_OpenT* openPtr, uint8_t freeze);
static void    VAL_VidecFrameAvlCb (void* optData);
static void    VAL_VidecFrameDecCb (void* optData);
static void    VAL_VidecFrameInfoCb(void* optData);
#endif
static void    VAL_VidecParamChgCb (FAPI_VIDEC_FrameInfoStateT* nextFrameInfoPtr,
                                    FAPI_VIDEC_FrameInfoStateT* lastFrameInfoPtr,
                                    void* optData);
#if 0
static int32_t VAL_GetFrameBankSize(const /*FAPEX_VIDEC_VESParamStrT*/VAL_VESParamStrT* paramsPtr,
                                    int32_t* fbSizePtr);

void func_21ca7b24(void* frameDecodedOptData);
void func_21ca7b30(void* frameAvailableOptData);
void func_21ca7b54(FAPI_VIDEC_VideoDecInfoStateT* videoDecInfoPtr,
                   void* videoOptData);

/*lint -save -e717 -e788 */

/* NOTE: the following LINT statements have been suppressed:
- Info 717: do ... while(0);
- Info 788: enum constant 'anyConst' not used within defaulted switch
*/

//*****************************************************************************
//*****************************************************************************
//** Local Functions
//*****************************************************************************
//*****************************************************************************
#endif

/*!
*******************************************************************************
** \brief   Initialize video interface library.
**
** \param   -
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_ALREADY_INITIALIZED  Already initialized.
**
** \note    This function shall be called once at system startup. Use VAL_GoUp
**          and VAL_GoDown to perform transitions between active and standby
**          mode.
**
** \sa      VAL_GoUp, VAL_GoDown
*******************************************************************************
*/
/* 21caa848 - complete */
int32_t VAL_Init (void)
{
    int32_t err_code = FAPI_OK;

    if ( gnrDataPtr != NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_ALREADY_INITIALIZED;
    }
    else
    {
        gnrDataPtr = &gnrDat;
        
        memset(gnrDataPtr, 0, sizeof(VAL_DataT));
        
        /* create semaphore for mutual exclusion purposes */
        gnrDataPtr->mutexHandle = rtos_create_semaphore(1);
        if ( gnrDataPtr->mutexHandle == NULL )
        {
            err_code = SUBSYS_VIDEO_VAL_ERR_SEMAPHORE_CREATE;
        }
        else
        {
            gnrDataPtr->appHdSystemType          = VAL_DEFAULT_HDSYS;
            gnrDataPtr->appSdSystemType          = VAL_DEFAULT_SDSYS;
            gnrDataPtr->viencHdEncoder           = VAL_DEFAULT_HDSYS;
            gnrDataPtr->viencSdEncoder           = VAL_DEFAULT_SDSYS;
            gnrDataPtr->vioutDispAr[VAL_VOUT_SD] = VAL_DEFAULT_AR_SD;
            gnrDataPtr->vioutDispAr[VAL_VOUT_HD] = VAL_DEFAULT_AR_HD;
            gnrDataPtr->vioutHdScalingMethod     = VAL_DEFAULT_SM_HD;
        }
        
        FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Init: %i\n", err_code);
    }

    return err_code;
}

/*!
*******************************************************************************
** \brief   Initialize and open video output.
**
** \param   paramsPtr   Default video parameters.
** \param   errCodePtr  Optionally returns error_status. Set to NULL if not
**                      needed.
**
** \return  NULL in case of failure, handle for further usage on success.
**
** \note    This shall be called after returning from standby. The returned
**          pointer is used for general video output operations and is passed
**          to VAL_Open.
**
** \sa      VAL_GoDown, VAL_Open
*******************************************************************************
*/
/* 21caa770 - todo */
VAL_DataT* VAL_GoUp (const VAL_UpParamsT* paramsPtr, int32_t* errCodePtr)
{
    VAL_DataT*  dataPtr = gnrDataPtr;
    int32_t     err_code = FAPI_OK;

    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_NOT_INITIALIZED;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        if ( !(dataPtr->up) )
        {
            if ( paramsPtr != NULL )
            {
                dataPtr->appHdSystemType = paramsPtr->hdSystemType;
                dataPtr->appSdSystemType = paramsPtr->sdSystemType;
                dataPtr->viencHdEncoder  = paramsPtr->hdSystemType;
                dataPtr->viencSdEncoder  = paramsPtr->sdSystemType;
                dataPtr->vioutDispAr[VAL_VOUT_SD] = paramsPtr->displayAspectRatio[VAL_VOUT_SD];
                dataPtr->vioutDispAr[VAL_VOUT_HD] = paramsPtr->displayAspectRatio[VAL_VOUT_HD];
                dataPtr->vioutHdScalingMethod     = paramsPtr->scalingMethod;
                
                dataPtr->Data_2308 = 0;
                dataPtr->bData_2312 = 0;
            }
            
            dataPtr->videoBlanked  = 0;
            dataPtr->hdmiConnected = 0;
            
            err_code = VAL_IntGoUp (dataPtr, dataPtr->appHdSystemType,
                                    dataPtr->appSdSystemType);
        
            if ( err_code == FAPI_OK )
            {
                dataPtr->up      = 1;
                dataPtr->openPtr = NULL;
            }
        }
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    if ( errCodePtr != NULL )
    {
        *errCodePtr = err_code;
    }

    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_GoUp: %i\n", err_code);

    if ( err_code != FAPI_OK )
    {
        dataPtr = NULL;
    }

    return dataPtr;
}

#if 0
/*!
*******************************************************************************
** \brief   Close video output.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  Invalid handle.
**
** \note    This shall be called before entering standby.
**
** \sa      VAL_GoUp
*******************************************************************************
*/
int32_t VAL_GoDown (VAL_DataT* dataPtr)
{
    int32_t err_code = FAPI_OK;
    
    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        if ( dataPtr->up )
        {
            /* close if still open */
            if ( dataPtr->openPtr != NULL )
            {
                err_code = VAL_IntClose(dataPtr->openPtr);
                
                /* mark instance as closed */
                dataPtr->openPtr = NULL;
            }
            if(err_code == FAPI_OK) {
                err_code = VAL_IntGoDown(dataPtr);
            
                dataPtr->up = 0;
            }
        }
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_GoDown: %i\n", err_code);

    return err_code;
}

/*!
*******************************************************************************
** \brief   Check HDMI connection for plug/unplugging.
**
** This function shall be regularly called (e.g. once a second) in order to
** be able to react on HDMI plug/unplug events. Please note that this module
** only handles the correct handling of video. HDMI audio must be restarted
** on connection as well (see AAL layer). Use this function for triggering the
** restart.
** 
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   connectedPtr    Returns HDMI connection information if a non-NULL
**                          pointer is passed (1: connected, 0: not connected).
** \param   changePtr       Returns HDMI connection change indication if a 
**                          non-NULL pointer is passed (1: connection status
**                          has changed since last calling of this function,
**                          0: not changed).
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  Invalid handle.
**
*******************************************************************************
*/
int32_t VAL_UpdateHDMIConnectionStatus (VAL_DataT* dataPtr,
                                        uint8_t* connectedPtr,
                                        uint8_t* changePtr)
{
    int32_t err_code = FAPI_OK;
    
    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
#if 0
    else if ( dataPtr->vioutId < 0 )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
#endif
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        err_code = VAL_HdmiUpdateStatus(dataPtr, connectedPtr, changePtr);
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Return current HDMI connection status.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   connectedPtr    Returns connection information if a non-NULL pointer
**                          is passed (1: connected, 0: unconnected).
**
** \return  Possible return codes:
**          - FAPI_OK                              Successful completion.
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  NULL-pointer passed as
**                                                 dataPtr.
*******************************************************************************
*/
int32_t VAL_GetHDMIConnectionStatus (VAL_DataT* dataPtr, uint8_t* connectedPtr)
{
    int32_t err_code;
    
    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        if ( connectedPtr != NULL )
        {
            *connectedPtr = dataPtr->hdmiConnected;
        }
        
        err_code = FAPI_OK;
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Modifies SD and HD video output system.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   hdSystemType    Requested HD system type.
** \param   sdSystemType    Requested SD system type.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  dataPtr is invalid.
*******************************************************************************
*/
/* 21caa628 - complete */
int32_t VAL_SetOutputMode (VAL_DataT* dataPtr, VAL_HdEncoderT hdSystemType,
                           VAL_SdEncoderT sdSystemType)
{
    VAL_OpenT*          openPtr       = NULL;
    int32_t             err_code      = FAPI_OK;
    VAL_OpEnumT         currOperation = VAL_OP_NONE;
    uint32_t            currPid       = 0;
    VAL_PlayModeEnumT   currMode      = VAL_PLAYMODE_NONE;
    VAL_OpenParamsT     openParams;

    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        memset(&openParams, 0, sizeof(openParams)); /* satisfy MISRA */
        
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        do
        {
            if ( dataPtr->openPtr != NULL )
            {
                openPtr = dataPtr->openPtr;
                
                currOperation = openPtr->operation;
                currPid       = openPtr->pid;
                currMode      = openPtr->mode;
                openParams    = openPtr->openParams;
                
                do
                {
                    /* Stop potentially running decoder. */
                    err_code = VAL_IntStop(openPtr, 0);
                    if ( err_code != FAPI_OK )
                    {
                        break;
                    }

                    err_code = VAL_IntClose(openPtr);
                    if ( err_code != FAPI_OK )
                    {
                        break;
                    }
                }
                while ( 0 );

                if ( err_code != FAPI_OK )
                {
                    openPtr->operation = VAL_OP_ERROR;
                    break;
                }
            }

            /*err_code =*/ VAL_IntGoDown(dataPtr);
#if 0
            if(err_code != FAPI_OK) {
                break;
            }
#endif

            /*err_code =*/ VAL_IntGoUp  (dataPtr, hdSystemType, sdSystemType);
#if 0
            if(err_code != FAPI_OK) {
                break;
            }
#endif

            dataPtr->appHdSystemType = hdSystemType;
            dataPtr->appSdSystemType = sdSystemType;

            if ( openPtr != NULL )
            {
                do
                {
                    err_code = VAL_IntOpen(openPtr, &openParams);
                    if ( err_code != FAPI_OK )
                    {
                        break;
                    }

                    if ( (currOperation == VAL_OP_LIVE)
                      || (currOperation == VAL_OP_PLAY) )
                    {
                        /* Restart video with parameters from previous start. */

                        err_code = VAL_IntStart (openPtr, currPid, currMode, 0);

                        if ( err_code != FAPI_OK )
                        {
                            break;
                        }
                    }
                }
                while ( 0 );

                if ( err_code != FAPI_OK )
                {
                    openPtr->operation = VAL_OP_ERROR;
                    break;
                }
            }

        } while ( 0 );
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }

    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_SetOutputMode: %i\n", err_code);

    return err_code;
}

/*!
*******************************************************************************
** \brief   Set user-defined display aspect ratio.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
** \param   output      Video output to set aspect ratio for.
** \param   displayAr   Requested display aspect ratio.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  dataPtr is invalid.
*******************************************************************************
*/
int32_t VAL_SetDisplayAspectRatio (VAL_DataT* dataPtr,
                                   VAL_VideoOutputT output,
                                   int32_t displayAr)
{
    int32_t err_code;

    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else if ( output >= VAL_VOUT_NUMS )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        dataPtr->vioutDispAr[output] = displayAr;

#if 0
        err_code = FAPEX_VIOUT_Ioctl(dataPtr->vioutSubId[output],
                                     FAPEX_IOCCOM_VIOUT_SET_ASPECT_RATIO,
                                     (FAPEXIOCARG3_T)dataPtr->vioutDispAr[output]);
#endif
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
        
        err_code = FAPI_OK;
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_SetDisplayAspectRatio: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Set scaling method of HD scaler.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   scalingMethod   Requested scaling method.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  dataPtr is invalid.
*******************************************************************************
*/
int32_t VAL_SetHdScalingMethod (VAL_DataT* dataPtr,
                                int32_t scalingMethod)
{
    FAPEX_VIOUT_ScalerParamStrT  *spPtr;
    int32_t err_code;
    
    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
//        spPtr = dataPtr->vioutParams + (int32_t)VAL_VOUT_HD;

        spPtr->mode               = scalingMethod;
        spPtr->osdByteOrder       = FAPEX_VIOUT_OSD_LAYOUT_UNKNOWN;
        spPtr->cpTileNumX         = 0;
        spPtr->cpTileNumY         = 0;
        spPtr->flagFrameField     = 0;
        spPtr->inputWindowX0      = 0;
        spPtr->inputWindowY0      = 0;
        spPtr->inputWindowWidth   = 0;
        spPtr->inputWindowHeight  = 0;
        spPtr->outputWindowX0     = 0;
        spPtr->outputWindowY0     = 0;
        spPtr->outputWindowWidth  = 0;
        spPtr->outputWindowHeight = 0;

#if 0
        err_code = FAPEX_VIOUT_Ioctl(dataPtr->vioutSubId[VAL_VOUT_HD],
                                     FAPEX_IOCCOM_VIOUT_SET_SCALER_PARAMS,
                                     (FAPEXIOCARG3_T)spPtr);
#endif
        
        if ( err_code == FAPI_OK )
        {
            dataPtr->vioutHdScalingMethod = scalingMethod;
        }
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_SetHdScalingMethod: %i\n", err_code);
    
    return err_code;
}


/*!
*******************************************************************************
** \brief   Set parameters for video output window.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
** \param   x0          Horizontal start position in pixels.
** \param   y0          Vertical start position in pixels.
** \param   width       Width in pixels.
** \param   height      Height in pixels.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  dataPtr is invalid.
**
** \sa      VAL_Crop
*******************************************************************************
*/
int32_t VAL_Resize (VAL_DataT* dataPtr, uint32_t x0, uint32_t y0,
                    uint32_t width, uint32_t height)
{
    int32_t                      err_code;
    FAPEX_VIOUT_ScalerParamStrT* spPtr;

    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
//        spPtr = dataPtr->vioutParams + (int32_t)VAL_VOUT_HD;
        
        spPtr->outputWindowX0     = (uint32_t)x0;
        spPtr->outputWindowY0     = (uint32_t)y0;
        spPtr->outputWindowWidth  = (uint32_t)width;
        spPtr->outputWindowHeight = (uint32_t)height;
        
#if 0
        err_code = FAPEX_VIOUT_Ioctl(dataPtr->vioutSubId[VAL_VOUT_HD],
                                     FAPEX_IOCCOM_VIOUT_SET_RESIZE,
                                     (FAPEXIOCARG3_T)spPtr);
#endif
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Resize: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Set video window to be taken as input for scaling.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
** \param   x0          Horizontal start position in pixels.
** \param   y0          Vertical start position in pixels.
** \param   width       Width in pixels.
** \param   height      Height in pixels.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  dataPtr is invalid.
**
** \sa      VAL_Resize
*******************************************************************************
*/
int32_t VAL_Crop (VAL_DataT* dataPtr, uint32_t x0, uint32_t y0,
                  uint32_t width, uint32_t height)
{
    int32_t                      err_code;
    FAPEX_VIOUT_ScalerParamStrT* spPtr;

    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
//        spPtr = dataPtr->vioutParams + (int32_t)VAL_VOUT_HD;

        spPtr->inputWindowX0     = (uint32_t)x0;
        spPtr->inputWindowY0     = (uint32_t)y0;
        spPtr->inputWindowWidth  = (uint32_t)width;
        spPtr->inputWindowHeight = (uint32_t)height;
        
#if 0
        err_code = FAPEX_VIOUT_Ioctl(dataPtr->vioutSubId[VAL_VOUT_HD],
                                     FAPEX_IOCCOM_VIOUT_SET_RESIZE,
                                     (FAPEXIOCARG3_T)spPtr);
#endif
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Crop: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Blank or unblank video output.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   blankOrUnblank  true (1): blank, false (0): unblank video output
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  dataPtr is invalid.
*******************************************************************************
*/
int32_t VAL_Blank (VAL_DataT* dataPtr, uint8_t blankOrUnblank)
{
    int32_t     err_code = FAPI_OK;
    VAL_OpenT*  openPtr;
    
    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        if ( dataPtr->videoBlanked != blankOrUnblank )
        {
            dataPtr->videoBlanked = blankOrUnblank;
        
            openPtr = (VAL_OpenT*)(dataPtr->openPtr);
        
            if ( (openPtr                != NULL)
              && (openPtr->decoderStatus == VAL_STATUS_RUNNING) )
            {
#if 0
                if ( blankOrUnblank )
                {
                    err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                                 FAPEX_IOCCOM_VIDEC_SET_DISPOFF,
                                                 (FAPEXIOCARG3_T)NULL);
                }
                else
                {
                    err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                                 FAPEX_IOCCOM_VIDEC_SET_DISPON,
                                                 (FAPEXIOCARG3_T)FAPEX_VIDEC_ENABLE_FORCE_ON);
                }
#endif
            }
        }
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Blank(%i): %i\n", blankOrUnblank,
                            err_code);
    
    return err_code;
}

#endif

/*!
*******************************************************************************
** \brief   Get current HDMI driver handle.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
/* 21ca7a8c - complete */
FAPI_SYS_HandleT VAL_GetHdmi (VAL_DataT* dataPtr)
{
    return dataPtr->hdmiHandle;
}

/*!
*******************************************************************************
** \brief   Get current SD video encoder driver handle.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
/* 21ca7a94 - complete */
FAPI_SYS_HandleT VAL_GetViencSd (VAL_DataT* dataPtr)
{
    return dataPtr->viencHandle[VAL_VOUT_SD];
}

/*!
*******************************************************************************
** \brief   Get current HD video encoder driver handle.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
/* 21ca7a9c - complete */
FAPI_SYS_HandleT VAL_GetViencHd (VAL_DataT* dataPtr)
{
    return dataPtr->viencHandle[VAL_VOUT_HD];
}

/*!
*******************************************************************************
** \brief   Get current SD video scaler driver handle.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
FAPI_SYS_HandleT VAL_GetViscaleSd (VAL_DataT* dataPtr)
{
    return dataPtr->viscaleHandle[VAL_VOUT_SD];
}

/*!
*******************************************************************************
** \brief   Get current HD video scaler driver handle.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
/* 21ca7aac - complete */
FAPI_SYS_HandleT VAL_GetViscaleHd (VAL_DataT* dataPtr)
{
    return dataPtr->viscaleHandle[VAL_VOUT_HD];
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
** \brief   Open video for decoding.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
** \param   paramsPtr   Open parameters.
** \param   errCodePtr  Optionally returns error_status. Set to NULL if not
**                      needed.
**
** \return  NULL in case of failure, handle for further usage on success.
**
** \note    This shall be called before any video decoding (for live or one of
**          the PVR playback modes) is started. The returned pointer is
**          pointer is used for all further operations related to decoding
**          until the module is closed by VAL_Close.
**
** \sa      VAL_Close
*******************************************************************************
*/
/* 21ca8f8c - complete */
VAL_OpenT* VAL_Open (VAL_DataT* dataPtr, const VAL_OpenParamsT* paramsPtr,
                     int32_t* errCodePtr)
{
    int32_t    err_code = FAPI_OK;
    VAL_OpenT* openPtr  = &openDat;

    if ( dataPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else if ( paramsPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
    }
    else
    {
        (void)rtos_request_semaphore(dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
        
        if ( dataPtr->openPtr != NULL )
        {
            err_code = SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
        }
        else
        {
            memset(openPtr, 0, sizeof(VAL_OpenT));
            
            err_code = VAL_IntOpen (openPtr, paramsPtr);
            
            if ( err_code == FAPI_OK )
            {
                /* successfully opened: link structures */
                openPtr->dataPtr = dataPtr;
                dataPtr->openPtr = openPtr;
            }
        }
        
        rtos_release_semaphore(dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    }
    
    if ( errCodePtr != NULL )
    {
        *errCodePtr = err_code;
    }

    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Open: %i\n", err_code);

    if ( err_code != FAPI_OK )
    {
        return NULL;
    }
    else
    {
        return openPtr;
    }
}

#if 0

/*!
*******************************************************************************
** \brief   Close video decoding.
**
** \param   openPtr     Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  Invalid handle.
**
** \note    This shall be called after decoding of a stream is finished, e.g.
**          on service change or stopping of a PVR playback (i.e. any time the
**          source TS potentially changes). After the function return with
**          FAPI_OK, 'openPtr' is no longer valid.
**
** \sa      VAL_Open
*******************************************************************************
*/
/* 21ca8b24 - complete */
int32_t VAL_Close (VAL_OpenT* openPtr)
{
    int32_t err_code = FAPI_OK;
    
    if ( openPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        if ( openPtr->dataPtr->openPtr == openPtr )
        {
            (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                         FAPI_SYS_SUSPEND);
            
            /*err_code =*/ VAL_IntClose(openPtr);
        
            /* mark instance as closed */
            openPtr->dataPtr->openPtr = NULL;
            
            rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                                   FAPI_SYS_NO_SUSPEND);
        }
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Close: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Start video decoding/presentation.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   pid             PID of video stream to be decoded.
** \param   mode            Initial playback mode (for environment
**                          VAL_ENV_PLAY only).
** \param   pcrFlag         0 : PCR's pid is not equal to pid.
**                          1 : PCR's pid is equal to pid.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_Stop
*******************************************************************************
*/
/* 21ca9530 - complete */
int32_t VAL_Start (VAL_OpenT* openPtr, uint32_t pid, VAL_PlayModeEnumT mode, uint32_t pcrFlag)
{
    int32_t err_code;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
//        openPtr->pcrFlag = pcrFlag;

        err_code = VAL_IntStart (openPtr, pid, mode, 1);
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Start: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Stop video decoding and output.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   freeze          If true, freeze last picture instead of blanking
**                          video.
**
** \return  Possible return codes:
**
** \sa      VAL_Start
*******************************************************************************
*/
int32_t VAL_Stop (VAL_OpenT* openPtr, uint8_t freeze)
{
    int32_t err_code;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
        err_code = VAL_IntStop(openPtr, freeze);
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Stop: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Freeze or unfreeze video.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   freezeOn          If true, freeze video, else unfreeze it.
**
** \return  Possible return codes:
**
** \sa      VAL_Stop, VAL_Start
*******************************************************************************
*/
int32_t VAL_Freeze (VAL_OpenT* openPtr, uint8_t freezeOn)
{
    int32_t  err_code;
    int32_t  freezeSwitch;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        if ( freezeOn ) freezeSwitch = FAPEX_VIDEC_FREEZE_ON;
        else            freezeSwitch = FAPEX_VIDEC_FREEZE_OFF;
        
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
#if 0
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_VIDEC_SET_FREEZE_MODE,
                                     (FAPEXIOCARG3_T)freezeSwitch);
#endif
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Freeze: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Function that handles video-related tasks in application context.
**
** Should be regularly called by application, handles booting of correct
** video decoder for H.264.
**
** \param   openPtr           Handle returned by VAL_Open.
**
** \return  Possible return codes:
**
*******************************************************************************
*/
/* 21ca958c - todo */
int32_t VAL_Task (VAL_OpenT* openPtr)
{
    int32_t                   err_code;
    VAL_DecoderTypeT          decoder;
    /*FAPEX_VIDEC_VESParamStrT*/VAL_VESParamStrT  params;
    FAPI_VIDEC_VESParamsT sp;
    int32_t res = 0;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        //21ca95b0
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);

        if ( (openPtr->operation != VAL_OP_LIVE)
          && (openPtr->operation != VAL_OP_PLAY) )
        {
            err_code = FAPI_OK;
        }
        //21ca95e4
        else if ( openPtr->decoderStatus == VAL_STATUS_BOOTING )
        {
            //21ca9674
            /* NOTE: This is handling is only needed for H.264 ! */
            
            FAPI_SYS_PRINT_DEBUG(1, "\n%lld FAPEX_IOCCOM_VIDEC_GET_VES_PARAMS start\n",
                                    FAPEX_TIMER_GetTimeStamp(FAPEX_TIMER_RESOLUTION_1_MSEC));

#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_VIDEC_GET_VES_PARAMS,
                                         (FAPEXIOCARG3_T)&params);
            if ( err_code == FAPI_OK )
#else
            if (0 == FAPI_VIDEC_GetVesParams(openPtr->videcHandle, &sp, 0))
#endif
            {
                FAPI_SYS_PRINT_DEBUG(1, "\n%lld FAPEX_IOCCOM_VIDEC_GET_VES_PARAMS end\n",
                                        FAPEX_TIMER_GetTimeStamp(FAPEX_TIMER_RESOLUTION_1_MSEC));

                decoder.system        = openPtr->decoder.system;
                decoder.frameBankSize = VAL_DEFAULT_DECODERFBSIZE;
                params.decodedWidth = sp.decodedWidth;
                params.decodedHeight = sp.decodedHeight;
                
                if ( VAL_GetFrameBankSize (&params, &(decoder.frameBankSize))
                     != FAPI_OK )
                {
                    FAPI_SYS_PRINT_DEBUG(3, "[VAL]: Unknown framebank size, choose default!\n");
                    
                    /* choose default decoder type */
                    decoder.frameBankSize = VAL_DEFAULT_DECODERFBSIZE;
                }
                
                FAPI_SYS_PRINT_DEBUG(3, "[VAL]: Suggested fb size %i, current %i!\n",
                                        decoder.frameBankSize,
                                        openPtr->decoder.frameBankSize);
                
                if ( decoder.frameBankSize != openPtr->decoder.frameBankSize )
                {
                    res = VAL_IntReboot(openPtr, &decoder);

                    FAPI_SYS_PRINT_DEBUG(3, "[VAL] Rebooting video decoder: %i\n",
                                            err_code);
                }
                else
                {
                   //21ca970c
                   FAPI_VIDEC_SetFrameDecodedCallback(openPtr->videcHandle,
                         func_21ca7b24, openPtr);

                   FAPI_VIDEC_SetFrameAvailableCallback(openPtr->videcHandle,
                         func_21ca7b30, openPtr);

                   FAPI_VIDEC_SetVideoDecInfoCallback(openPtr->videcHandle,
                         func_21ca7b54, openPtr);

                   if (openPtr->dataPtr->videoBlanked == 0)
                   {
                      res = FAPI_VIDEC_EnableDisable(openPtr->videcHandle,
                            FAPI_VIDEC_ENABLE_SYNCHRONOUSLY_NO_SUSPEND);
                   }
                }
                //21ca96dc
                if (res != 0)
                {
                   err_code = res;
                }
                else
                {
                    openPtr->decoderStatus = VAL_STATUS_RUNNING;
                }
            }
            else {
                FAPI_SYS_PRINT_DEBUG(2, "[VAL] FAPEX_IOCCOM_VIDEC_GET_VES_PARAMS: %i\n",
                                        err_code);
            }
        }
        else if ( openPtr->decoderStatus == VAL_STATUS_RUNNING )
        {
           //21ca95f8
           params.decodedWidth = openPtr->Data_156_8; //.Data_8;
           params.decodedHeight = openPtr->Data_156_12; //.Data_12;

           if ((openPtr->Data_156_0/*.Data_0*/ != openPtr->Data_156_8/*.Data_8*/) ||
                 (openPtr->Data_156_4/*.Data_4*/ != openPtr->Data_156_12/*.Data_12*/))
           {
              //21ca9614
              openPtr->Data_156_0/*.Data_0*/ = params.decodedWidth;
              openPtr->Data_156_4/*.Data_4*/ = params.decodedHeight;

              if (openPtr->decoder.system == 2)
              {
                 decoder.system        = openPtr->decoder.system;
                 decoder.frameBankSize = VAL_DEFAULT_DECODERFBSIZE;

                 if ( VAL_GetFrameBankSize (&params, &(decoder.frameBankSize))
                      == FAPI_OK )
                 {
                    //21ca964c
                    if (decoder.frameBankSize != openPtr->decoder.frameBankSize)
                    {
                       //21ca965c
                       err_code = VAL_IntReboot(openPtr, &decoder);
                    }
                 }
              }
           }
           //21ca95d0
        }
        else {
            //->21ca95d0
            FAPI_SYS_PRINT_DEBUG(2, "[VAL] VAL_Task openPtr->decoderStatus != VAL_STATUS_BOOTING\n");
        }
        //21ca95d0
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Set notification function to be called once the first video frame
**          has been decoded and displayed.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   frameAvlCb        Notification function, NULL disables notification.
** \param   frameAvlCbArg     Optional parameter passed with frameAvlCb.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
*******************************************************************************
*/
/* 21ca7d58 - complete */
int32_t VAL_SetFrameAvailableCb(VAL_OpenT* openPtr,
                                void (*frameAvlCb)(void* optData),
                                void* frameAvlCbArg)
{
    int32_t err_code;

    err_code = VAL_ArgCheckOpen(openPtr);

    if ( err_code == FAPI_OK )
    {
        openPtr->frameAvlCb    = frameAvlCb;
        openPtr->frameAvlCbArg = frameAvlCbArg;
    }

    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_SetFrameAvailableCb: %i\n", err_code);

    return err_code;
}

/*!
*******************************************************************************
** \brief   Set notification function to be informed about parameter changes
**          in the current video stream.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   paramChangeCb     Notification function, NULL disables notification.
** \param   paramChangeCbArg  Optional parameter passed with paramChangeCb.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
*******************************************************************************
*/
/* 21ca7d34 - complete */
int32_t VAL_SetParamChangeCb (VAL_OpenT* openPtr,
                              void (*paramChangeCb)(FAPI_VIDEC_FrameInfoStateT*, 
                                                    FAPI_VIDEC_FrameInfoStateT*, 
                                                    void*),
                              void* paramChangeCbArg)
{
    int32_t err_code;

    err_code = VAL_ArgCheckOpen(openPtr);

    if ( err_code == FAPI_OK )
    {
        openPtr->paramChangeCb    = paramChangeCb;
        openPtr->paramChangeCbArg = paramChangeCbArg;
    }

    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_SetParamChangeCb: %i\n", err_code);

    return err_code;
}

/*!
*******************************************************************************
** \brief   Allows to reboot video decoder for new decoder type at runtime.
**
** Current video operation will be maintained, i.e. restarting of video
** after reboot is not necessary.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   decoderPtr        Pointer to structure describing requested decoder
**                            type.
**
** \return  Possible return codes:
**
** \sa      VAL_Stop, VAL_Start
*******************************************************************************
*/
/* 21ca94cc - complete */
int32_t VAL_Reboot (VAL_OpenT* openPtr, const VAL_DecoderTypeT* decoderPtr)
{
    int32_t err_code;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code != FAPI_OK )
    {
        /* do nothing */
    }
    else if ( decoderPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
    }
    else
    {
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
        err_code = VAL_IntReboot(openPtr, decoderPtr);
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_Reboot: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Perform video decoder recovery.
**
** \param   openPtr           Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE Invalid (NULL) handle passed.
**          - SUBSYS_VIDEO_VAL_ERR_NOT_OPEN       VAL is not open.
**
*******************************************************************************
*/
int32_t VAL_Recover (VAL_OpenT* openPtr)
{
    int32_t err_code;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
#if 0
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_VIDEC_RECOVER,
                                     (FAPEXIOCARG3_T)NULL);
#endif
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Return buffer size of video ES input buffer.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   sizePtr           Returns buffer size if a non-NULL pointer is
**                            passed.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_GetBufferLevel
*******************************************************************************
*/
/* 21ca7ab4 - complete */
int32_t VAL_GetBufferSize (VAL_OpenT* openPtr, uint32_t* sizePtr)
{
    if ( sizePtr != NULL )
    {
//        if ( openPtr != NULL )
        {
            *sizePtr = openPtr->bufferSize;
        }
#if 0
        else
        {
            *sizePtr = 0;
        }
#endif
    }
    return FAPI_OK;
}

/*!
*******************************************************************************
** \brief   Return current filling level of video ES input buffer.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   levelPtr          Returns filling level if a non-NULL pointer is
**                            passed.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_GetBufferSize
*******************************************************************************
*/
/* 21ca8828 - complete */
int32_t VAL_GetBufferLevel (VAL_OpenT* openPtr, uint32_t* levelPtr)
{
//    FAPEX_TSD_ReadInfoStrT  readInfo;
    int32_t  err_code = FAPI_OK;
    uint32_t level    = 0;
    
//    if ( (openPtr != NULL) && (openPtr->videcId >= 0) )
    if (openPtr->videcHandle != 0)
    {
#if 0
        err_code = FAPEX_TSD_Ioctl(openPtr->tsdId,
                                   FAPEX_IOCCOM_TSD_GET_BUFFER_READINFO,
                                   (FAPEXIOCARG3_T)&readInfo);
#else
        err_code = FAPI_VIDEC_GetVesFillLevel(openPtr->videcHandle, &level);
#endif
        
        if ( err_code != FAPI_OK )
        {
            level = 0;
        }
        else
        {
            //level = readInfo.fillSize;
            if ( level > openPtr->bufferSize )
            {
                level = openPtr->bufferSize;
            }
        }
    }
    
    if ( levelPtr != NULL )
    {
        *levelPtr = level;
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Informs if first frame after video startup has been displayed..
**
** \note Frame availability is reset in VAL_IntStart, VAL_PlayChangeMode and
**       VAL_PlayPrepareNextFrame.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   avlPtr          Returns frame availability status (true, false)
**                          if a non-NULL pointer is passed.
**
** \return  Possible return codes:
**          - FAPI_OK                               Successful completion.
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE   NULL-pointer passed as
**                                                  openPtr.
*******************************************************************************
*/
/* 21ca7ac8 - complete */
int32_t VAL_IsFrameAvailable (VAL_OpenT* openPtr, uint8_t* avlPtr)
{
    int32_t err_code;
    
    if ( openPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        if ( avlPtr != NULL )
        {
            *avlPtr = openPtr->frameDecoded;
        }
        
        err_code = FAPI_OK;
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Return current VAL module status.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   statusPtr         Returns status information if a non-NULL pointer
**                            is passed.
**
** \return  Possible return codes:
**          - FAPI_OK                              Successful completion.
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE  NULL-pointer passed as
**                                                 openPtr.
*******************************************************************************
*/
/* 21ca87a8 - complete */
int32_t VAL_GetStatus (VAL_OpenT* openPtr, VAL_StatusT* statusPtr)
{
    int32_t err_code;
    
    if ( openPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else
    {
        if ( statusPtr != NULL )
        {
            memset(statusPtr, 0, sizeof (VAL_StatusT));
            
            statusPtr->environment   = openPtr->openParams.environment;
            statusPtr->operation     = openPtr->operation;
            statusPtr->mode          = openPtr->mode;
            statusPtr->decoderStatus = openPtr->decoderStatus;
            statusPtr->decoder       = openPtr->decoder;
        }
        
        err_code = FAPI_OK;
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Get detailed information on currently displayed video frame.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   videcInfoPtr      Returns video frame information if a non-NULL
**                            pointer is passed and return value is FAPI_OK.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**          - SUBSYS_VIDEO_VAL_DATA_NOT_AVAILABLE No frame info available (yet).
*******************************************************************************
*/
/* 21ca7ccc - todo */
int32_t VAL_GetVideoFrameInfo (VAL_OpenT* openPtr,
                               FAPEX_VIDEC_DecFrameInfoStrT* videcInfoPtr)
{
    int32_t err_code;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        if ( openPtr->videcFrameInfoAvailable == 0 )
        {
            err_code = SUBSYS_VIDEO_VAL_DATA_NOT_AVAILABLE;
        }
        else if ( videcInfoPtr != NULL )
        {
//            *videcInfoPtr = openPtr->videcFrameInfo;
           memcpy(videcInfoPtr, &openPtr->videcFrameInfo, 64);
        }
    }
    
    return err_code;
}

/* 21ca7af0 - complete */
FAPI_SYS_HandleT VAL_GetBmHandle (VAL_OpenT* openPtr)
{
    return openPtr->bmHandle;
}

/*!
*******************************************************************************
** \brief   Get current TSD driver handle.
**
** \param   openPtr           Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
/* 21ca7af8 - complete */
FAPI_SYS_HandleT VAL_GetTsdHandle (VAL_OpenT* openPtr)
{
#if 0
    if(openPtr == NULL) {
        return -1;
    }
#endif
    return openPtr->tsdHandle;
}

/*!
*******************************************************************************
** \brief   Get current VIDEC driver handle.
**
** \param   openPtr           Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - Driver handle (may be -1)
*******************************************************************************
*/
/* 21ca7b00 - complete */
FAPI_SYS_HandleT VAL_GetVidecHandle (VAL_OpenT* openPtr)
{
#if 0
    if(openPtr == NULL) {
        return -1;
    }
#endif
    return openPtr->videcHandle;
}

/* ------------------------------------------------------------------------- */
#endif

/*!
*******************************************************************************
** \brief   Decode an MPEG-I-Frame.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   dataPtr         Source data (MPEG 1/2 ES), endianess is detected
**                          automatically.
** \param   sizeInBytes     Data size in bytes.
**
** \return  Possible return codes:
**          - FAPI_OK                           Successful completion.
**          - SUBSYS_VIDEO_VAL_ALREADY_STARTED  Decoding is already active.
**          - SUBSYS_VIDEO_VAL_ERR_FEATURE_NOT_SUPPORTED Currently selected
**                                              decoder is not an MPEG decoder.
**
** \sa      VAL_IFrameDisplay
*******************************************************************************
*/
/* 21ca85f4 - complete */
int32_t VAL_IFrameDecode (VAL_OpenT* openPtr, const uint32_t* dataPtr,
                          uint32_t sizeInBytes)
{
    int32_t err_code = FAPI_OK;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
        if ( openPtr->operation != VAL_OP_NONE )
        {
            err_code = SUBSYS_VIDEO_VAL_ALREADY_STARTED;
        }
        else if ( openPtr->decoder.system != FAPI_VIDEC_MPEG2_MPHL )
        {
            err_code = SUBSYS_VIDEO_VAL_ERR_FEATURE_NOT_SUPPORTED;
        }
        else
        {
            do
            {
               FAPI_VIDEC_SetAutoScaleCallback(openPtr->videcHandle,
                     FAPI_VISCALE_AutoScaler,
                     openPtr->dataPtr->viscaleHandle[VAL_VOUT_HD]);

               FAPI_VIDEC_SetAutoScaleCallback(openPtr->videcHandle,
                     FAPI_VISCALE_AutoScaler,
                     openPtr->dataPtr->viscaleHandle[VAL_VOUT_SD]);
               
               err_code = FAPI_VIDEC_SetDecoderToHdEncoder(openPtr->videcHandle,
                     openPtr->dataPtr->viencHandle[VAL_VOUT_HD]);

               if(err_code != FAPI_OK) {
                   break;
               }
               
               err_code = FAPI_VIDEC_SetPlaybackMode(openPtr->videcHandle,
                     FAPI_VIDEC_NORMAL_PLAYBACK_MODE);

               if(err_code != FAPI_OK) {
                   break;
               }

               err_code = FAPI_VIDEC_SetMpegIFrameMode(openPtr->videcHandle, 1);
               if ( err_code != FAPI_OK )
               {
                   break;
               }      
               
               err_code = FAPI_VIDEC_DecodeSingleMpegIFrame(openPtr->videcHandle,
                     (void*) dataPtr, sizeInBytes);

               if ( err_code != FAPI_OK )
               {
                   break;
               }      

               openPtr->dataPtr->hdScalerParams.inputPicWidth = 0;
               openPtr->dataPtr->hdScalerParams.inputPicHeight = 0;
               openPtr->dataPtr->hdScalerParams.inputWindowX0 = 0;
               openPtr->dataPtr->hdScalerParams.inputWindowY0 = 0;
               openPtr->dataPtr->hdScalerParams.inputWindowWidth = 0;
               openPtr->dataPtr->hdScalerParams.inputWindowHeight = 0;
               
               FAPI_VISCALE_SetDisplayAspectRatio(openPtr->dataPtr->viscaleHandle[VAL_VOUT_HD],
                     openPtr->dataPtr->vioutDispAr[VAL_VOUT_HD]);

               FAPI_VISCALE_SetDisplayAspectRatio(openPtr->dataPtr->viscaleHandle[VAL_VOUT_SD],
                     openPtr->dataPtr->vioutDispAr[VAL_VOUT_SD]);

               FAPI_VISCALE_Resize(openPtr->dataPtr->viscaleHandle[VAL_VOUT_HD],
                     &openPtr->dataPtr->hdScalerParams);

               FAPI_VISCALE_Resize(openPtr->dataPtr->viscaleHandle[VAL_VOUT_SD],
                     &openPtr->dataPtr->sdScalerParams);

                openPtr->operation = VAL_OP_IFRAME;
            }
            while ( 0 );
            
            if(err_code != FAPI_OK) 
            {
               FAPI_VIDEC_ClearAutoScaleCallback(openPtr->videcHandle);
            }
        }
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_IFrameDecode: %i\n", err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Display an MPEG-I-Frame decoded with VAL_IFrameDecode.
**
** \param   openPtr         Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_BAD_MODE   No I-Frame has been decoded.
**
** \sa      VAL_IFrameDecode
*******************************************************************************
*/
/* 21ca8438 - complete */
int32_t VAL_IFrameDisplay (VAL_OpenT* openPtr)
{
    int32_t err_code;
    
    err_code = VAL_ArgCheckOpen(openPtr);
    
    if ( err_code == FAPI_OK )
    {
        (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle,
                                     FAPI_SYS_SUSPEND);
        
        if ( openPtr->operation != VAL_OP_IFRAME )
        {
            err_code = SUBSYS_VIDEO_VAL_BAD_MODE;
        }
        else
        {
#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_VIDEC_DISP_SINGLE_I_FRAME,
                                         (FAPEXIOCARG3_T)NULL);
#else
            err_code = FAPI_VIDEC_DisplaySingleMpegIFrame(openPtr->videcHandle);
#endif
        }
        
        rtos_release_semaphore(openPtr->dataPtr->mutexHandle,
                               FAPI_SYS_NO_SUSPEND);
    }
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] VAL_IFrameDisplay: %i\n", err_code);
    
    return err_code;
}

#if 0

/*!
*******************************************************************************
** \brief   Change mode of playback operation.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   mode            Requested playback mode.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**          - SUBSYS_VIDEO_VAL_BAD_MODE Module is not in PVR playback operation.
**
** \sa      VAL_Start, VAL_Stop
*******************************************************************************
*/
int32_t VAL_PlayChangeMode (VAL_OpenT* openPtr, VAL_PlayModeEnumT mode)
{
    int32_t                         err_code      = FAPI_OK;
    uint8_t                         unfreezeVideo = 0;
    int32_t                         videcMode;
    uint8_t                         restart       = 0;
    FAPEX_VIDEC_StartParamStrT      decStartParam;
    
    FAPI_SYS_PRINT_DEBUG(3, "[VAL] Change playback mode: %i -> %i\n",
                            openPtr->mode, mode);
    
    if ( openPtr == NULL )
    {
        return SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else if ( openPtr->operation != VAL_OP_PLAY )
    {
        return SUBSYS_VIDEO_VAL_BAD_MODE;
    }
    else if ( mode >= VAL_PLAYMODE_NUMS )
    {
        return SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
    }
    else if ( mode == openPtr->mode )
    {
        return FAPI_OK;
    }
    
    (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
    
    /* ----- freeze/reset video -------------------------------------------- */

    /* Handle all non-seamless transitions. */

    if ( (mode          == VAL_PLAYMODE_FAST_DEC_IONLY)
      || (mode          == VAL_PLAYMODE_FAST_DEC_IP)
      || (mode          == VAL_PLAYMODE_FAST_LIB_IONLY)
      || (mode          == VAL_PLAYMODE_FAST_CONTROLLEDFEED)
      || (openPtr->mode == VAL_PLAYMODE_FAST_DEC_IONLY)
      || (openPtr->mode == VAL_PLAYMODE_FAST_DEC_IP)
      || (openPtr->mode == VAL_PLAYMODE_FAST_LIB_IONLY)
      || (openPtr->mode == VAL_PLAYMODE_FAST_CONTROLLEDFEED) )
    {
        err_code = VAL_ChannelStop (openPtr);
        if(err_code != FAPI_OK) {
            goto VAL_PlayChangeMode_end;
        }

        /* Handle special cases where simply freezing and unfreezing of the
           video is not sufficient. */

        if ( (mode          == VAL_PLAYMODE_FAST_DEC_IONLY)
          || (mode          == VAL_PLAYMODE_FAST_CONTROLLEDFEED)
          || (openPtr->mode == VAL_PLAYMODE_FAST_DEC_IONLY)
          || (openPtr->mode == VAL_PLAYMODE_FAST_CONTROLLEDFEED) )
        {
            /* Both of these modes use the I_ONLY mode provided by the video
               firmware. Resetting the video decoder is necessary when entering
               or leaving this mode */
#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_RESET,
                                         (FAPEXIOCARG3_T)FAPEX_VIDEC_HARD_RESET);
#endif
            if(err_code != FAPI_OK) {
                goto VAL_PlayChangeMode_end;
            }
            restart = 1;
        }
        else if ( openPtr->mode == VAL_PLAYMODE_PAUSE )
        {
            if ( mode == VAL_PLAYMODE_FAST_LIB_IONLY )
            {
                // TODO: add error handling!

#if 0
                err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                             FAPEX_IOCCOM_RESET,
                                             (FAPEXIOCARG3_T)FAPEX_VIDEC_HARD_RESET);
#endif
                if(err_code != FAPI_OK) {
                    goto VAL_PlayChangeMode_end;
                }

#if 0
                err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                             FAPEX_IOCCOM_VIDEC_SET_PLAYBACK_MODE,
                                             (FAPEXIOCARG3_T)FAPEX_VIDEC_PLAYBACK_MODE_I_ONLY);
#endif
                if(err_code != FAPI_OK) {
                    goto VAL_PlayChangeMode_end;
                }
            }
            restart = 1;
        }
        else
        {
#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_VIDEC_SET_FREEZE_MODE,
                                         (FAPEXIOCARG3_T)FAPEX_VIDEC_FREEZE_ON);
#endif
            if(err_code != FAPI_OK) {
                goto VAL_PlayChangeMode_end;
            }
            unfreezeVideo = 1;
        }
        
        if ( mode != VAL_PLAYMODE_FAST_LIB_IONLY )
        {
            err_code = VAL_ChannelStart (openPtr, openPtr->pid);
            if(err_code != FAPI_OK) {
                goto VAL_PlayChangeMode_end;
            }
        }
    }
    
    /* ----- change decoder mode ------------------------------------------- */
    
    switch ( mode )
    {
        default:
        case VAL_PLAYMODE_FAST_LIB_IONLY:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_NORMAL;
            break;

        case VAL_PLAYMODE_NORMAL:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_NORMAL;
            break;

        case VAL_PLAYMODE_PAUSE:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_PAUSE;
            break;

        case VAL_PLAYMODE_FAST_DEC_IONLY:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_I_ONLY;
            break;

        case VAL_PLAYMODE_FAST_DEC_IP:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_I_AND_P_ONLY;
            break;

        case VAL_PLAYMODE_FAST_CONTROLLEDFEED:
            #ifdef VAL_FASTMODE_SPEEDUP
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_I_ONLY;
            #else
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_FIRST_I_ONLY;
            #endif /* VAL_FASTMODE_SPEEDUP */
            break;

        case VAL_PLAYMODE_SLOW_2X:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_2X;
            break;

        case VAL_PLAYMODE_SLOW_4X:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_4X;
            break;

        case VAL_PLAYMODE_SLOW_8X:
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_8X;
            break;
    }
    
    if ( videcMode != FAPEX_VIDEC_PLAYBACK_MODE_UNKNOWN )
    {
#if 0
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_VIDEC_SET_PLAYBACK_MODE,
                                     (FAPEXIOCARG3_T)videcMode);
#endif
        if(err_code != FAPI_OK) {
            goto VAL_PlayChangeMode_end;
        }
    }
    
    /* ----- unfreeze video ------------------------------------------------ */
    
    openPtr->frameAvailable = 0;
    openPtr->frameDecoded   = 0;
    
    openPtr->startFlags = FAPEX_VIDEC_NOTIFY_FLAGS_DEC_AVAILABLE |
                          FAPEX_VIDEC_NOTIFY_FLAGS_DISP_AVAILABLE;
    
    if ( unfreezeVideo )
    {
#if 0
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_VIDEC_SET_FREEZE_MODE,
                                     (FAPEXIOCARG3_T)FAPEX_VIDEC_FREEZE_OFF);
#endif
    }
    else if ( restart )
    {
        decStartParam.outputMode   = FAPEX_VIDEC_ENABLE_SYNCHRONOUSLY_NO_SUSPEND;
        decStartParam.playbackMode = videcMode;
        decStartParam.flags        = openPtr->startFlags;

#if 0
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_START,
                                     (FAPEXIOCARG3_T)&decStartParam);
#endif
    }

    if ( err_code == FAPI_OK )
    {
        openPtr->mode  = mode;
    }

VAL_PlayChangeMode_end:

    rtos_release_semaphore(openPtr->dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Decode and display an I-frame as part of a series (e.g. fast mode).
**
** This function is to be used in playback mode VAL_PLAYMODE_FAST_LIB_IONLY
** only. As long as the playback mode is not changed, it may be called multiple
** times in order to show a sequence of I-frames without blanking in between.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   dataPtr         Source data (MPEG 1/2 ES), endianess is detected
**                          automatically.
** \param   dataBytes       Data size in bytes.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**          - SUBSYS_VIDEO_VAL_BAD_MODE Module is not in PVR playback operation.
*******************************************************************************
*/
int32_t VAL_PlayShowIFrame (VAL_OpenT* openPtr, const uint32_t* dataPtr,
                            uint32_t dataBytes)
{
    FAPEX_VIDEC_ESdataParamStrT  esDataParam;
    int32_t err_code;
    
    // FIXME: add openPtr check?
    
    (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
    
    if ( openPtr->operation != VAL_OP_PLAY )
    {
        err_code = SUBSYS_VIDEO_VAL_BAD_MODE;
    }
    else
    {
        //FAPI_SYS_PRINT_MSG("SHOW I: %p, %i bytes\n", dataPtr, dataBytes);
        
        // TODO: check if in correct decoder mode! (use also for live?)
        
        esDataParam.data = (uint32_t*)dataPtr;
        esDataParam.size = dataBytes;

#if 0
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_VIDEC_DEC_SEQUENCE_I_FRAME,
                                     (FAPEXIOCARG3_T)&esDataParam);
        if ( err_code == FAPI_OK )
        {
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_VIDEC_DISP_SEQUENCE_I_FRAME,
                                         (FAPEXIOCARG3_T)NULL);
        }
#endif
    }
    
    rtos_release_semaphore(openPtr->dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    
    return err_code;
}


/* 21ca7b24 - todo */
void func_21ca7b24(void* frameDecodedOptData)
{
   FAPI_SYS_PRINT_MSG("func_21ca7b24\n");
}


/* 21ca7b30 - todo */
void func_21ca7b30(void* frameAvailableOptData)
{
   FAPI_SYS_PRINT_MSG("func_21ca7b30\n");
}


/* 21ca7b54 - todo */
void func_21ca7b54(FAPI_VIDEC_VideoDecInfoStateT* videoDecInfoPtr,
      void* videoOptData)
{
   FAPI_SYS_PRINT_MSG("func_21ca7b54\n");
}


/*!
*******************************************************************************
** \brief   Prepare decoding of next I-frame for special playback mode.
**
** This function is to be used in playback mode
** VAL_PLAYMODE_FAST_CONTROLLEDFEED only. It should be called before the first
** data is fed via TSD. In order to realise a sequence of I-frames, it should
** be called periodically AFTER the decoder has indicated that a frame has been
** displayed and BEFORE data for the new frame has been fed.
**
** \param   openPtr         Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**          - SUBSYS_VIDEO_VAL_BAD_MODE Module is not in correct playback mode
**                                      for this operation.
*******************************************************************************
*/
/* 21ca7d7c - complete */
int32_t VAL_PlayPrepareNextFrame (VAL_OpenT* openPtr)
{
    #ifndef VAL_FASTMODE_SPEEDUP
    FAPEX_VIDEC_StartParamStrT  decStartParam;
    #endif
    int32_t err_code = FAPI_OK;
    
    // FIXME: add openPtr check?
    
    (void)rtos_request_semaphore(openPtr->dataPtr->mutexHandle, FAPI_SYS_SUSPEND);
    
    do
    {
        if ( openPtr->operation != VAL_OP_PLAY )
        {
            err_code = SUBSYS_VIDEO_VAL_BAD_MODE;
            break;
        }
        else if ( openPtr->mode != VAL_PLAYMODE_FAST_CONTROLLEDFEED )
        {
            err_code = SUBSYS_VIDEO_VAL_BAD_MODE;
            break;
        }
        
        #ifndef VAL_FASTMODE_SPEEDUP
        
        err_code = VAL_ChannelStop (openPtr);
        if(err_code != FAPI_OK) {
            break;
        }

        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_RESET,
                                     (FAPEXIOCARG3_T)FAPEX_VIDEC_HARD_RESET);
        if(err_code != FAPI_OK) {
            break;
        }

        err_code = VAL_ChannelStart (openPtr, openPtr->pid);
        if ( err_code != FAPI_OK )
        {
            break;
        }

        #endif /* VAL_FASTMODE_SPEEDUP */
        
        #ifndef VAL_FASTMODE_SPEEDUP
        
        decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_FIRST_I_ONLY;
        
        #endif /* VAL_FASTMODE_SPEEDUP */
        
        err_code = FAPI_VIDEC_SetPlaybackMode(openPtr->videcHandle,
              FAPI_VIDEC_I_ONLY_PLAYBACK_MODE);
                
        if ( err_code != FAPI_OK )
        {
            break;
        }
        
        if (openPtr->decoder.system == 1)
        {
           //21ca7e1c
           err_code = FAPI_VIDEC_SetMpegIFrameMode(openPtr->videcHandle, 0);
           if ( err_code != FAPI_OK )
           {
               break;
           }                      
        }
        //21ca7de8
        func_21c2f7a4();

        openPtr->frameAvailable = 0;
        openPtr->frameDecoded   = 0;
      
        FAPI_VIDEC_SetFrameDecodedCallback(openPtr->videcHandle, 
              func_21ca7b24, openPtr);

        FAPI_VIDEC_SetFrameAvailableCallback(openPtr->videcHandle, 
              func_21ca7b30, openPtr);

#if 0
        openPtr->startFlags = FAPEX_VIDEC_NOTIFY_FLAGS_DEC_AVAILABLE |
                              FAPEX_VIDEC_NOTIFY_FLAGS_DISP_AVAILABLE;
#endif
        
        #ifndef VAL_FASTMODE_SPEEDUP
        
        if ( !(openPtr->dataPtr->videoBlanked) )
        {
            decStartParam.outputMode = FAPEX_VIDEC_ENABLE_SYNCHRONOUSLY_NO_SUSPEND;
        }
        else {
            decStartParam.outputMode = FAPEX_VIDEC_ENABLE_FORCE_OFF;
        }
        decStartParam.flags = openPtr->startFlags;
        
        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_START,
                                     (FAPEXIOCARG3_T)&decStartParam);
        
        #endif /* VAL_FASTMODE_SPEEDUP */
    }
    while ( 0 );

    rtos_release_semaphore(openPtr->dataPtr->mutexHandle, FAPI_SYS_NO_SUSPEND);
    
    return err_code;
}

/* ------------------------------------------------------------------------- */

#endif


/* 21ca976c - todo */
int VAL_HdmiSetVideoParams(VAL_DataT* dataPtr, int b, int c, int d, int e)
{
   FAPI_SYS_PRINT_MSG("VAL_HdmiSetVideoParams\n");
   
   return 0;
}

/*!
*******************************************************************************
** \brief   Internal function, wakeup VAL module.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   hdSystemType    Requested HD system type.
** \param   sdSystemType    Requested SD system type.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_IntGoDown
*******************************************************************************
*/
/* 21ca9e60 - complete */
static int32_t VAL_IntGoUp (VAL_DataT* dataPtr, VAL_HdEncoderT hdSystemType,
                            VAL_SdEncoderT sdSystemType)
{
    int32_t err_code = FAPI_OK;

    do
    {
        err_code = VAL_ViencInitClocks (hdSystemType);
        if ( err_code != FAPI_OK )
        {
            break;
        }
        err_code = VAL_ViencOpen(dataPtr, hdSystemType, sdSystemType);
        if ( err_code != FAPI_OK )
        {
            break;
        }

        err_code = VAL_HdmiOpen(dataPtr);
        if ( err_code != FAPI_OK )
        {
            break;
        }

        if (dataPtr->hdmiHandle != 0)
        {
           func_21ca9a94(dataPtr, 0, 0, 0);
           
#if 0
           if (dataPtr->hdmiConnected)
#endif
           {
              //->21caa5c4
              if (0 == VAL_HdmiSetVideoParams(dataPtr,
                    hdSystemType, 
                    dataPtr->Data_2308,
                    dataPtr->bData_2312,
                    0))
              {
                 FAPI_HDMI_VIDEO_Start(dataPtr->hdmiHandle);
              }
           }
        }
        //21caa2c4    
        err_code = VAL_ViscaleOpen (dataPtr, hdSystemType);
        if ( err_code != FAPI_OK )
        {
            break;
        }
    }
    while ( 0 );

    if ( err_code != FAPI_OK )
    {
        (void)VAL_HdmiClose    (dataPtr);
        (void)VAL_ViscaleClose (dataPtr);
        (void)VAL_ViencClose   (dataPtr);
    }

    return err_code;
}

#if 0

/*!
*******************************************************************************
** \brief   Internal function, shutdown VAL module.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_IntGoUp
*******************************************************************************
*/
/* 21ca9dd4 - complete */
static int32_t VAL_IntGoDown (VAL_DataT* dataPtr)
{
    int32_t err_code = 0;

    VAL_HdmiClose(dataPtr);
    VAL_ViscaleClose(dataPtr);
    VAL_ViencClose(dataPtr);

    return err_code;
}

#endif

/*!
*******************************************************************************
** \brief   Internal function, open VAL module.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   paramsPtr       Open parameters.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_IntClose
*******************************************************************************
*/
/* 21ca8b80 - todo */
static int32_t VAL_IntOpen (VAL_OpenT* openPtr/*r5*/,
                   const VAL_OpenParamsT* paramsPtr/*r6*/)
{
    int32_t err_code = FAPI_OK;

    openPtr->openParams              = *paramsPtr;
    openPtr->decoder                 = paramsPtr->decoder; //36/40
    openPtr->startFlags              = 0; //44
    openPtr->bufferSize              = 0; //64
    openPtr->operation               = VAL_OP_NONE; //68
    openPtr->pid                     = 0; //72
    openPtr->mode                    = VAL_PLAYMODE_NONE; //76
    openPtr->decoderStatus           = VAL_STATUS_STOPPED; //84
    openPtr->videcFrameInfoAvailable = 0; //152

    err_code = VAL_VidecOpen (openPtr, &(paramsPtr->decoder),
                              paramsPtr->enableAfd,
                              paramsPtr->environment,
                              paramsPtr->Data_16);

    if ( err_code == FAPI_OK )
    {
        err_code = VAL_ChannelOpen (openPtr, 
              paramsPtr, paramsPtr->Data_16);
        
        if ( err_code != FAPI_OK )
        {
            (void)VAL_VidecClose (openPtr);
        }
    }

    return err_code;
}

#if 0

/*!
*******************************************************************************
** \brief   Internal function, close VAL module.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   paramsPtr       Open parameters.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_IntClose
*******************************************************************************
*/
/* 21ca8ac8 - complete */
static int32_t VAL_IntClose (VAL_OpenT* openPtr)
{
    VAL_IntStop(openPtr, 0);
    VAL_VidecClose(openPtr);
    VAL_ChannelClose(openPtr);

    return FAPI_OK;
}

/*!
*******************************************************************************
** \brief   Internal function for starting video decoding/output.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   pid               Video stream PID.
** \param   operation         Requested operation.
** \param   mode              Requested playback mode.
** \param   checkDecoderType  If true, trigger decoder type check for H.264.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ALREADY_STARTED   Video already started.
**          - SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER Invalid playback mode
**                                               requested.
** \sa      VAL_Stop
*******************************************************************************
*/
/* 21ca902c - todo */
static int32_t VAL_IntStart (VAL_OpenT* openPtr, uint32_t pid,
                             VAL_PlayModeEnumT mode, uint8_t checkDecoderType)
{
    int32_t                         err_code;
    int32_t                         videcMode; //r9
    uint8_t                         feedViaTsd = 1; //sp
    VAL_OpEnumT                     operation; //sp4

    err_code = VAL_ArgCheckOpen(openPtr);

    if ( err_code != FAPI_OK )
    {
        return err_code;
    }
    else if ( openPtr->operation != VAL_OP_NONE )
    {
        return SUBSYS_VIDEO_VAL_ALREADY_STARTED;
    }

    switch ( openPtr->openParams.environment )
    {
        case VAL_ENV_LIVE:
            operation = VAL_OP_LIVE;
            break;

        case VAL_ENV_PLAY:
            operation = VAL_OP_PLAY;
            break;

        default:
            return SUBSYS_VIDEO_VAL_INTERNAL;
    }

    switch ( mode )
    {
        case VAL_PLAYMODE_NORMAL:
            //21ca91d0
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_NORMAL;
            break;

        case VAL_PLAYMODE_FAST_LIB_IONLY:
            //21ca9198
            videcMode  = FAPEX_VIDEC_PLAYBACK_MODE_NORMAL;
            feedViaTsd = 0;
            break;

        case VAL_PLAYMODE_PAUSE:
            //21ca91c0
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_PAUSE;
            break;

        case VAL_PLAYMODE_FAST_DEC_IONLY:
            //21ca90cc
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_I_ONLY;
            break;

        case VAL_PLAYMODE_FAST_DEC_IP:
            //21ca91a8
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_I_AND_P_ONLY;
            break;

        case VAL_PLAYMODE_FAST_CONTROLLEDFEED:
            //21ca90cc
            #ifdef VAL_FASTMODE_SPEEDUP
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_I_ONLY;
            #else
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_FIRST_I_ONLY;
            #endif /* VAL_FASTMODE_SPEEDUP */
            break;

        case VAL_PLAYMODE_SLOW_2X:
            //21ca9200
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_2X;
            break;

        case VAL_PLAYMODE_SLOW_4X:
            //21ca91f0
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_4X;
            break;

        case VAL_PLAYMODE_SLOW_8X:
            //21ca91e0
            videcMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_8X;
            break;

        default:
            //21ca91b8
            return SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
    }

    do
    {
        err_code = VAL_ChannelStart (openPtr, pid);
        if ( err_code != FAPI_OK ) break;
        //21ca90ec
        err_code = VAL_VidecStart (openPtr, videcMode,
                                   feedViaTsd, checkDecoderType);
        if ( err_code != FAPI_OK ) break;

        openPtr->operation = operation;
        openPtr->pid       = pid;
        openPtr->mode      = mode;
    }
    while ( 0 );

    if ( err_code != FAPI_OK )
    {
        (void)VAL_VidecStop   (openPtr, 0);
        (void)VAL_ChannelStop (openPtr);
    }

    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, stop video decoding and output.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   freeze            Video stream PID.
**
** \return  Possible return codes:
**
** \sa      VAL_Start
*******************************************************************************
*/
/* 21ca8a04 - complete */
static int32_t VAL_IntStop (VAL_OpenT* openPtr, uint8_t freeze)
{
    int32_t err_code = FAPI_OK;
    
    if ( openPtr->operation == VAL_OP_ERROR )
    {
        err_code = SUBSYS_VIDEO_VAL_ERROR_STATE;
    }
    else if ( openPtr->operation != VAL_OP_NONE )
    {
        /*err_code =*/ VAL_VidecStop(openPtr, freeze);
#if 0
        if(err_code != FAPI_OK) {
            return err_code;
        }
#endif
        /*err_code =*/ VAL_ChannelStop(openPtr);
        /*if(err_code == FAPI_OK)*/ {
            openPtr->operation = VAL_OP_NONE;
            openPtr->pid       = 0;
            openPtr->mode      = VAL_PLAYMODE_NONE;
        }
    }
    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, reboots video decoder for new decoder type at 
**          runtime.
**
** Current video operation will be maintained, i.e. restarting of video
** after reboot is not necessary.
**
** \param   openPtr           Handle returned by VAL_Open.
** \param   decoderPtr        Pointer to structure describing requested decoder
**                            type.
**
** \return  Possible return codes:
**
*******************************************************************************
*/
/* 21ca9414 - nearly complete */
static int32_t VAL_IntReboot (VAL_OpenT* openPtr,
                              const VAL_DecoderTypeT* decoderPtr)
{
    int32_t             err_code = FAPI_OK;
    VAL_OpenParamsT     openParams;
    VAL_OpEnumT         currOperation;
    uint32_t            currPid;
    VAL_PlayModeEnumT   currMode;
    
    do
    {
        currOperation = openPtr->operation;
        currPid       = openPtr->pid;
        currMode      = openPtr->mode;
        
        openParams         = openPtr->openParams;
        openParams.decoder = *decoderPtr;
        
        /* Stop potentially running decoder. */
        err_code = VAL_IntStop(openPtr, 0);
        if ( err_code != FAPI_OK )
        {
            break;
        }
        
        err_code = VAL_IntClose(openPtr);
        if ( err_code != FAPI_OK )
        {
            break;
        }
        
        err_code = VAL_IntOpen(openPtr, &openParams);
        if ( err_code != FAPI_OK )
        {
            break;
        }
        
        if ( (currOperation == VAL_OP_LIVE)
          || (currOperation == VAL_OP_PLAY) )
        {
            /* Restart video with parameters from previous start. */
            
            err_code = VAL_IntStart (openPtr, currPid, currMode, 0);
            if ( err_code != FAPI_OK )
            {
                break;
            }
        }
    }
    while ( 0 );
    
    if ( err_code != FAPI_OK )
    {
        openPtr->operation = VAL_OP_ERROR;
    }
    
    return err_code;
}

#endif

/*!
*******************************************************************************
** \brief   Internal function, open video input data channel.
**
** \param   openPtr         Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ChannelClose
*******************************************************************************
*/
static int32_t VAL_ChannelOpen (VAL_OpenT* openPtr,
      const VAL_OpenParamsT* paramsPtr, int r7)
{
   //21ca8cbc
#if 0
    struct Struct_21c128e8 
    {
       int Data_0; //0
       int Data_4; //4
       int Data_8; //8
       int Data_12; //12
       int Data_16; //16
       int Data_20; //20
       int Data_24; //24
       int Data_28; //28
       int Data_32; //32
       //36
    } sp24; //sp24
#else
    FAPI_BM_InfoT sp24; //sp24
#endif
    FAPI_BM_OpenParamsT sp60; //sp60
    FAPI_TSD_OpenParamsT sp124; //sp124
#if 0
    FAPEX_TSD_OpenSubIdParamStrT  pidChParam;
    FAPEX_TSD_PesParamStrT        pesParam;
#endif
    
    int32_t  err_code = FAPI_OK;
    uint32_t sp140 = 0;
    uint32_t sp136 = 0;
       
    if ((openPtr->tsdHandle != 0) ||
          (openPtr->bmHandle != 0))
    {
        return SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
    }
#if 0
    if (openPtr->Data_24 != 0)
    {
        return SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
    }
#endif
    if (openPtr->videcHandle == 0)
    {
        return -3500104;
    }
    //21ca8d08
    do
    {
        err_code = FAPI_VIDEC_GetVesBufferPosition(openPtr->videcHandle, &sp140);        
        if ( err_code != FAPI_OK )
        {
            //->21ca8d1c
            break;
        }
        //21ca8d78
        err_code = FAPI_VIDEC_GetVesBufferSize(openPtr->videcHandle, &sp136);
        if ( err_code != FAPI_OK )
        {
            //->21ca8d1c
            break;
        }
        //21ca8d94
        sp60.version = FAPI_BM_VERSION;
        sp60.blockIndex = 0;
        sp60.channelId = -1;
        sp60.address = sp140 - FAPI_BM_GetGlobalOffset(0);
        sp60.size = sp136;
        sp60.swapWrite = 1;
        sp60.swapRead = 0;
        sp60.swapMode = 0;
                
        openPtr->bmHandle = FAPI_BM_Open(&sp60, &err_code);   
        if (openPtr->bmHandle == 0)
        {
           //21ca8f20
           break;
        }
        //21ca8de8
        openPtr->bufferSize = sp60.size >> 1;
        
        FAPI_BM_SetBufferReadPointer(openPtr->bmHandle,
              0xfffc00, 1);

        sp124.version = 0x00050000; //FAPI_TSD_VERSION;
        sp124.blockIndex = 0;
        sp124.channelId = -1;
        
        openPtr->tsdHandle = FAPI_TSD_Open(&sp124, &err_code);
        if (openPtr->tsdHandle == 0)
        {
            FAPI_SYS_PRINT_MSG("FAPI_TSD_Open failed\n");
           //21ca8f20
           break;
        }
        //21ca8e28
        err_code = FAPI_BM_GetInfo(openPtr->bmHandle, &sp24);
        if ( err_code != FAPI_OK )
        {
            //->21ca8d1c
            break;
        }
        //21ca8e44
        err_code = FAPI_TSD_SetBuffer(openPtr->tsdHandle, sp24);
        if ( err_code != FAPI_OK )
        {
            //->21ca8d1c
            break;
        }
        //21ca8e7c
#if 1
        int r1 = ((paramsPtr->decoder.system == 2) &&
              (/*paramsPtr->Data_16*/r7 == 1));
#endif
        
        int r4 = err_code = FAPI_TSD_SetPesParser(openPtr->tsdHandle,
#if 1
              r1 ^ 1, 
#else
              ((paramsPtr->decoder.system != 2) ||
              (/*paramsPtr->Data_16*/r7 != 1)),
#endif
              1, 1);
        
        if ( err_code < FAPI_OK )
        {
            //->21ca8d1c
            break;
        }
        //21ca8eb4
        err_code = 0;
        
        err_code = FAPI_VIDEC_SetChannelId(openPtr->videcHandle,
              sp24.blockIndex, sp24.channelId);

        if ( err_code != FAPI_OK )
        {
            //->21ca8d1c
            break;
        }
        //21ca8ed4
        openPtr->startFlags = 0;
        
        if ((sp124.blockIndex == 2) ||
              (sp124.blockIndex == 3))
        {
           //21ca8f34
           if (r4 == 0)
           {
              openPtr->startFlags = 5;
           }
           else if (r4 == 1)
           {
              openPtr->startFlags = 6;
           }
           else if (r4 == 2)
           {
              openPtr->startFlags = 7;
           }
           else if (r4 == 3)
           {
              openPtr->startFlags = 8;
           }
        }
        else
        {
           //21ca8ee8
           if (r4 == 0)
           {
              openPtr->startFlags = 1;
           }
           else if (r4 == 1)
           {
              openPtr->startFlags = 2;
           }
           else if (r4 == 2)
           {
              openPtr->startFlags = 3;
           }
           else if (r4 == 3)
           {
              openPtr->startFlags = 4;
           }
        }

#if 0
       /* open Video TSD channel */
        pidChParam.channelNo = VIDEO_TSD_CHANNEL;
        pidChParam.sub_id    = DRV_ID_TSD0_VIDEO_CH;

        err_code = FAPEX_TSD_Ioctl((FAPEXIOCARG1_T)fd_TSD[0],
                                   FAPEX_IOCCOM_OPEN_SUBID,
                                   (FAPEXIOCARG3_T)&pidChParam);
        if ( err_code != FAPI_OK )
        {
            FAPI_SYS_PRINT_DEBUG(2, "[VAL] tsd channel open error: %d\n", err_code);
            break;
        }
        openPtr->tsdId = pidChParam.sub_id;

        pesParam.pid              = openPtr->pid;
        pesParam.flags            = FAPEX_TSD_FLTFLAGS_RM_PES_HEADER | FAPEX_TSD_FLTFLAGS_PTS |
                                    FAPEX_TSD_FLTFLAGS_SWAPWR_SWAP | FAPEX_TSD_FLTFLAGS_SWAPMODE_4BYTE;
        pesParam.bufferSize       = (openPtr->decoder.system == FAPEX_VIDEC_CODEC_TYPE_MPEG2) ?
                                    0x003FFC00 : 0x007FFC00;
        pesParam.bufferThresholdH = pesParam.bufferSize;
        pesParam.bufferThresholdL = 0;
        pesParam.streamType       = FAPEX_TSD_STREAMTYPE_VIDEO;

        err_code = FAPEX_TSD_Ioctl(openPtr->tsdId,
                                   FAPEX_IOCCOM_TSD_SET_PES_FILTER,
                                   (FAPEXIOCARG3_T)&pesParam);
        if ( err_code != FAPI_OK )
        {
            break;
        }
        openPtr->bufferSize = pesParam.bufferSize;
#endif
    }
    while ( 0 );

    if ( err_code != FAPI_OK )
    {
        //21ca8d1c
        FAPI_SYS_PRINT_DEBUG(2, "[VAL] VAL_ChannelOpen failed: %i\n", err_code);

//        if ( openPtr->tsdId >= 0 )
        if ( openPtr->tsdHandle != 0 )
        {
           //21ca8d28
#if 0
            (void)FAPEX_TSD_Ioctl((FAPEXIOCARG1_T)openPtr->tsdId,
                                   FAPEX_IOCCOM_CLOSE_SUBID,
                                   (FAPEXIOCARG3_T)NULL);
            openPtr->tsdId = -1;
#else
            FAPI_TSD_Close(openPtr->tsdHandle);
            openPtr->tsdHandle = 0;
#endif
        }
        
        if ( openPtr->bmHandle != 0 )
        {
           //21ca8d40
           FAPI_BM_Close(openPtr->bmHandle);
           openPtr->bmHandle = 0;
        }
        //21ca8d4c
    }

    return err_code;
}

#if 0

/*!
*******************************************************************************
** \brief   Internal function, close video input data channel.
**
** \param   openPtr         Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ChannelOpen
*******************************************************************************
*/
static int32_t VAL_ChannelClose (VAL_OpenT* openPtr)
{
    int32_t err_code = FAPI_OK;

    if (openPtr->tsdHandle != 0)
    {
        err_code = FAPI_TSD_Close(openPtr->tsdHandle);           
    }
      
    if ( err_code == FAPI_OK )
    {
       openPtr->tsdHandle = 0;
       
       if (openPtr->bmHandle != 0)
       {
           err_code = FAPI_BM_Close(openPtr->bmHandle);
           
           if ( err_code == FAPI_OK )
           {
              openPtr->bmHandle = 0; 
           }
       }       
    }

    openPtr->bufferSize = 0;

    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, start video input data channel.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   pid             PID of stream to be decoded.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ChannelStop
*******************************************************************************
*/
/* 21ca8034 - complete */
static int32_t VAL_ChannelStart (VAL_OpenT* openPtr, uint16_t pid)
{
//    FAPEX_TSD_PidParamStrT  pidParam;
    int32_t err_code = FAPI_OK;

    if ( (openPtr->tsdHandle  == 0)
      || (openPtr->bmHandle == 0)
      || (openPtr->videcHandle == 0) )
    {
        return SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }

    do
    {
        //21ca8078
        err_code = FAPI_TSD_SetChannelPid(openPtr->tsdHandle, pid, 0, 1);

        if ( err_code != FAPI_OK ) break;

        extern int32_t func_21c31e88(FAPI_SYS_HandleT, int,
              FAPI_SYS_HandleT, int);

        err_code = func_21c31e88(openPtr->tsdHandle, 0,
              openPtr->videcHandle, 0);

        if ( err_code != FAPI_OK ) break;

        err_code = FAPI_TSD_SetPtsEvaluator(openPtr->tsdHandle, 0, 0, 0);

        if ( err_code != FAPI_OK ) break;
        //21ca80bc
        if (openPtr->decoder.system != 2)
        {
           //21ca80c8
           err_code = FAPI_BM_SetAudCallback(openPtr->bmHandle, 0,
                 0xb3,
                 FAPI_VIDEC_AudCallback, openPtr->videcHandle);

           if ( err_code != FAPI_OK ) break;
           //21ca80e8
           err_code = FAPI_BM_SetAudCallback(openPtr->bmHandle, 1,
                 0x00,
                 FAPI_VIDEC_AudCallback, openPtr->videcHandle);
        }
        else
        {
           //21ca8130
           err_code = FAPI_BM_SetAudCallback(openPtr->bmHandle, 2,
                 (openPtr->openParams.Data_16 == 1)? 0xe0: 0x09,
                 FAPI_VIDEC_AudCallback, openPtr->videcHandle);
           //->21ca8108
        }
        //21ca8108
        if ( err_code != FAPI_OK ) break;

        err_code = FAPI_BM_StartAudFiltering(openPtr->bmHandle);

        if ( err_code != FAPI_OK ) break;

        extern int32_t func_21c34fec(FAPI_SYS_HandleT handle);

        err_code = func_21c34fec(openPtr->tsdHandle);

#if 0
        pidParam.pid   = pid;
        pidParam.flags = (openPtr->pcrFlag != 0) ? FAPEX_TSD_FLTFLAGS_PCR : 0;

        err_code = FAPEX_TSD_Ioctl(openPtr->tsdId,
                                   FAPEX_IOCCOM_TSD_SET_PID_VALUE,
                                   (FAPEXIOCARG3_T)&pidParam);

        if ( err_code != FAPI_OK ) break;

        err_code = FAPEX_TSD_Ioctl(openPtr->tsdId,
                                   FAPEX_IOCCOM_START,
                                   (FAPEXIOCARG3_T)NULL);
        if ( err_code != FAPI_OK ) break;
#endif
    }
    while ( 0 );

    if ( err_code != FAPI_OK )
    {
        FAPI_SYS_PRINT_DEBUG(2, "[VAL] VAL_ChannelStart (pid %i) failed: %i\n",
                                pid, err_code);
    }

    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, stop video input data channel.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   pid             PID of stream to be decoded.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ChannelStart
*******************************************************************************
*/
/* 21ca7fa8 - complete */
static int32_t VAL_ChannelStop (VAL_OpenT* openPtr)
{
    int32_t err_code = FAPI_OK;

    if ((openPtr->tsdHandle != 0) &&
          (openPtr->bmHandle != 0))
    {
#if 0
        err_code = FAPEX_TSD_Ioctl(openPtr->tsdId,
                                   FAPEX_IOCCOM_STOP,
                                   (FAPEXIOCARG3_T)NULL);
#endif
        
        func_21c354a4(openPtr->tsdHandle);
      
        do
        {
           err_code = FAPI_BM_SetBufferReadPointer(openPtr->bmHandle,
                 0xfffc00, 1);
   
           if (err_code != FAPI_OK)
           {
              break;              
           }
  
           err_code = FAPI_BM_SetBufferWritePointer(openPtr->bmHandle,
                 0, 0);

           if (err_code != FAPI_OK)
           {
              break;
           }
           
           FAPI_BM_StopAudFiltering(openPtr->bmHandle, 0);
           FAPI_BM_StopAudFiltering(openPtr->bmHandle, 1);
        }
        while (0);
    }

    if ( err_code != FAPI_OK )
    {
        FAPI_SYS_PRINT_DEBUG(2, "[VAL] VAL_ChannelStop failed: %i\n", err_code);
    }

    return err_code;
}

#endif

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
** \brief   Internal function, performs pre-initialisation of clocks.
**
** \param   hdSys           Requested HD video output system.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
*******************************************************************************
*/
static int32_t VAL_ViencInitClocks (VAL_HdEncoderT hdSys)
{
   FAPI_VIENC_InitClocksEnumT  clkSys;

    switch ( hdSys )
    {
        case VAL_1920x1080x2397P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x2397P;
            break;

        case VAL_1920x1080x24P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x24P;
            break;

        case VAL_1920x1080x25P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x25P;
            break;

        case VAL_1920x1080x2997P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x2997P;
            break;

        case VAL_1920x1080x30P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x30P;
            break;

        case VAL_1920x1080x50I:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x50I;
            break;

        case VAL_1920x1080x5994I:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x5994I;
            break;

        case VAL_1920x1080x60I:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1920x1080x60I;
            break;

        case VAL_1280x720x2397P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x2397P;
            break;

        case VAL_1280x720x24P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x24P;
            break;

        case VAL_1280x720x25P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x25P;
            break;

        case VAL_1280x720x2997P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x2997P;
            break;

        case VAL_1280x720x30P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x30P;
            break;

        case VAL_1280x720x50P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x50P;
            break;

        case VAL_1280x720x5994P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x5994P;
            break;

        case VAL_1280x720x60P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_1280x720x60P;
            break;

        case VAL_720x576x50I:
            clkSys = FAPI_VIENC_INIT_CLOCKS_720x576x50I;
            break;

        case VAL_720x576x50P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_720x576x50P;
            break;

        case VAL_720x480x5994I:
            clkSys = FAPI_VIENC_INIT_CLOCKS_720x480x5994I;
            break;

        case VAL_720x480x5994P:
            clkSys = FAPI_VIENC_INIT_CLOCKS_720x480x5994P;
            break;

        default:
            clkSys = FAPI_VIENC_INIT_CLOCKS_UNKNOWN;
            break;
    }

    return FAPI_VIENC_InitClocks(clkSys);
}


/*!
*******************************************************************************
** \brief   Internal function, open and start VIENC driver.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
** \param   hdSys       Requested HD video output system.
** \param   sdSys       Requested SD video output system.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ViencClose
*******************************************************************************
*/
static int32_t VAL_ViencOpen (VAL_DataT* dataPtr, VAL_HdEncoderT hdSys,
                              VAL_SdEncoderT sdSys)
{
    int32_t                         err_code = FAPI_OK;
    FAPI_VIENC_OpenParamsT viencParams;
    
    if ((dataPtr->viencHandle[VAL_VOUT_SD] != 0) ||
          (dataPtr->viencHandle[VAL_VOUT_HD] != 0))
    {
        return SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
    }
    
    do
    {
        dataPtr->viencHdEncoder = hdSys;
        dataPtr->viencSdEncoder = sdSys;

        viencParams.version = FAPI_VIENC_VERSION;
        viencParams.encoderType = FAPI_VIENC_ENCODER_HD;
        viencParams.colourSystem = FAPI_VIENC_UNKNOWN_COLOUR_SYSTEM;
        viencParams.colourComponent = FAPI_VIENC_COMPONENT_YPrPb;
        viencParams.crossChrominanceFilter = FAPI_VIENC_UNKNOWN_CROSS_CHROMIANACE_FILTER;

        if(hdSys == VAL_1920x1080x2397P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x2397P;
        }
        else if(hdSys == VAL_1920x1080x24P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x24P;
        }
        else if(hdSys == VAL_1920x1080x25P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x25P;
        }
        else if(hdSys == VAL_1920x1080x2997P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x2997P;
        }
        else if(hdSys == VAL_1920x1080x30P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x30P;
        }
        else if(hdSys == VAL_1920x1080x50I){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x50I;
        }
        else if(hdSys == VAL_1920x1080x5994I){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x5994I;
        }
        else if(hdSys == VAL_1920x1080x60I){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x60I;
        }
        else if(hdSys == VAL_1280x720x2397P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x2397P;
        }
        else if(hdSys == VAL_1280x720x24P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x24P;
        }
        else if(hdSys == VAL_1280x720x25P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x25P;
        }
        else if(hdSys == VAL_1280x720x2997P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x2997P;
        }
        else if(hdSys == VAL_1280x720x30P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x30P;
        }
        else if(hdSys == VAL_1280x720x50P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x50P;
        }
        else if(hdSys == VAL_1280x720x5994P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x5994P;
        }
        else if(hdSys == VAL_1280x720x60P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1280x720x60P;
        }
        else if(hdSys == VAL_720x576x50I){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_720x576x50I;
        }
        else if(hdSys == VAL_720x576x50P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_720x576x50P;
        }
        else if(hdSys == VAL_720x480x5994I){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_720x480x5994I;
        }
        else if(hdSys == VAL_720x480x5994P){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_720x480x5994P;
        }
        else{
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_1920x1080x50I;
        }

        dataPtr->viencHandle[VAL_VOUT_HD] = 
           FAPI_VIENC_Open(&viencParams, &err_code);
        
        if (dataPtr->viencHandle[VAL_VOUT_HD] == 0)
        {
           break;
        }
        
        err_code = FAPI_VIENC_Start(dataPtr->viencHandle[VAL_VOUT_HD]);

        if ( err_code != FAPI_OK )
        {
            break;
        }

        viencParams.version = FAPI_VIENC_VERSION;
        viencParams.encoderType = FAPI_VIENC_ENCODER_SD;
        if (sdSys < 17)
        {
           viencParams.colourComponent = FAPI_VIENC_COMPONENT_CVBS_YC;           
        }
        else
        {
           viencParams.colourComponent = FAPI_VIENC_COMPONENT_CVBS_RGB;
        }
        viencParams.crossChrominanceFilter = FAPI_VIENC_CROSS_CHROMIANACE_FILTER_OFF;

        if//(sdSys == VAL_SD_SECAM){
           ((sdSys == 9) || (sdSys == 17)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_SECAM;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_SECAM;
        }
        else if//(sdSys == VAL_SD_NTSC){
           ((sdSys == 10) || (sdSys == 18)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_NTSC;
        }
        else if//(sdSys == VAL_SD_NTSC_4_43){
           ((sdSys == 11) || (sdSys == 19)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_NTSC_4_43;
        }
        else if//(sdSys == VAL_SD_PAL){
           ((sdSys == 12) || (sdSys == 20)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_PAL;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL;
        }
        else if//(sdSys == VAL_SD_PAL60){
           ((sdSys == 13) || (sdSys == 21)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_60;
        }
        else if//(sdSys == VAL_SD_PAL_M){
           ((sdSys == 14) || (sdSys == 22)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_M;
        }
        else if//(sdSys == VAL_SD_PAL_N){
           ((sdSys == 15) || (sdSys == 23)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_PAL;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_N;
        }
        else if//(sdSys == VAL_SD_PAL_N_ARG){
           ((sdSys == 16) || (sdSys == 24)){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_PAL;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_N_ARG;
        }
        else if(sdSys == VAL_SD_SECAM){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_SECAM;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_SECAM;
        }
        else if(sdSys == VAL_SD_NTSC){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_NTSC;
        }
        else if(sdSys == VAL_SD_NTSC_4_43){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_NTSC_4_43;
        }
        else if(sdSys == VAL_SD_PAL){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_PAL;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL;
        }
        else if(sdSys == VAL_SD_PAL60){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_60;
        }
        else if(sdSys == VAL_SD_PAL_M){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_M;
        }
        else if(sdSys == VAL_SD_PAL_N){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_PAL;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_N;
        }
        else if(sdSys == VAL_SD_PAL_N_ARG){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_PAL;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_PAL_N_ARG;
        }
        else if(sdSys == VAL_SD_OFF){
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_NTSC;
            viencParams.colourComponent      = FAPI_VIENC_COMPONENT_DAC_POWER_DOWN;
        }
        else{
            viencParams.interlaceProgressive = FAPI_VIENC_IP_MODE_NTSC;
            viencParams.colourSystem         = FAPI_VIENC_COLOUR_SYSTEM_NTSC;
            viencParams.colourComponent      = FAPI_VIENC_COMPONENT_DAC_POWER_DOWN;
        }

        dataPtr->viencHandle[VAL_VOUT_SD] = 
           FAPI_VIENC_Open(&viencParams, &err_code);
        
        if (dataPtr->viencHandle[VAL_VOUT_SD] == 0)
        {
           break;
        }
        
        err_code = FAPI_VIENC_Start(dataPtr->viencHandle[VAL_VOUT_SD]);
    }
    while ( 0 );

    return err_code;
}


/*!
*******************************************************************************
** \brief   Internal function, close VIENC driver.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ViencOpen
*******************************************************************************
*/
/* 21ca9d84 - complete */
static int32_t VAL_ViencClose (VAL_DataT* dataPtr)
{
    int32_t             err_code = FAPI_OK;
    VAL_VideoOutputT    output;

    for ( output = VAL_VOUT_SD; output < VAL_VOUT_NUMS; output++ )
    {
        if ( dataPtr->viencHandle[output] != 0 )
        {
           err_code = FAPI_VIENC_Close(dataPtr->viencHandle[output]);
           
           if ( err_code == FAPI_OK )
           {
               dataPtr->viencHandle[output] = 0;
           }
           else
           {
               FAPI_SYS_PRINT_DEBUG(2, "[VAL] Close dataPtr->viencSubId[%d] failed. %d\n",
                                       output, err_code);
               return err_code;
           }
        }
    }
    
    return err_code;
}

#if 0

/* 21ca7e40 - complete */
int32_t func_21ca7e40(void* a,
      void (*b)(FAPI_VISCALE_ParamChangeInfoT*, void*), void* c)
{
   int32_t res = 0;
   VAL_DataT* dataPtr = a;
   
   if (dataPtr != 0)
   {
      rtos_request_semaphore(dataPtr->mutexHandle, -1);
      
      dataPtr->Func_2296 = b;
      dataPtr->Data_2300 = c;
      
      rtos_release_semaphore(dataPtr->mutexHandle, 0);
   }
   else
   {
      res = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE; //-3500008;
   }
   
   return res;
}

#endif


/* 21ca7b08 - complete */
static void VAL_ViscaleParamChgCb(FAPI_VISCALE_ParamChangeInfoT* paramChangePtr,
      void* paramChangeOptData)
{
   VAL_DataT* dataPtr = paramChangeOptData;
   
   //FAPI_SYS_PRINT_MSG("VAL_ViscaleParamChgCb\n");
      
   if (dataPtr->Func_2296 != NULL)
   {
      (dataPtr->Func_2296)(paramChangePtr, dataPtr->Data_2300);
   }
}

/*!
*******************************************************************************
** \brief   Internal function, open and start VISCALE driver.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
** \param   hdSys       Requested HD video output system.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ViscaleClose
*******************************************************************************
*/
static int32_t VAL_ViscaleOpen (VAL_DataT* dataPtr, VAL_HdEncoderT hdSys)
{
   uint32_t i;
   unsigned e;
    int32_t                       err_code = FAPI_OK;
    FAPI_VISCALE_OpenParamsT viscaleParams;

    if ((dataPtr->viscaleHandle[VAL_VOUT_SD] != 0) ||
          (dataPtr->viscaleHandle[VAL_VOUT_HD] != 0))
    {
        return SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
    }
    else if ( dataPtr->viencHandle[VAL_VOUT_HD] == 0 )
    {
        return SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    
    FAPI_VISCALE_BackgroundColour(5, 160, 97, 52);
    
    viscaleParams.version = FAPI_VISCALE_VERSION;
    viscaleParams.scalerType = FAPI_VISCALE_SCALER_VIDEO;
    
    e = 1 << hdSys;
    if ((hdSys >= 20) || ((e & 0xcdbdb) == 0))
    {
       viscaleParams.encoderType = FAPI_VISCALE_ENCODER_PAL;
    }
    else 
    {
       viscaleParams.encoderType = FAPI_VISCALE_ENCODER_NTSC;
    }
    
    dataPtr->viscaleHandle[VAL_VOUT_HD] = 
       FAPI_VISCALE_Open(&viscaleParams, &err_code);
    
    if (dataPtr->viscaleHandle[VAL_VOUT_HD] == 0)
    {
       return err_code; 
    }
    
    FAPI_VISCALE_ScalerParamsT* scalerParams = &dataPtr->hdScalerParams;
    
    dataPtr->hdScalerParams.layerEnable = 0;
    dataPtr->hdScalerParams.osdLayout = FAPI_VISCALE_UNKNOWN_OSD_LAYOUT;
    dataPtr->hdScalerParams.osdMode = FAPI_VISCALE_UNKNOWN_OSD_MODE;
    dataPtr->hdScalerParams.cpMode = FAPI_VISCALE_UNKNOWN_CURSOR_MODE;
    dataPtr->hdScalerParams.cpTileNumX = 0;
    dataPtr->hdScalerParams.cpTileNumY = 0;
    dataPtr->hdScalerParams.picBase = 0;
    dataPtr->hdScalerParams.frameField = 0;
    dataPtr->hdScalerParams.useGlobalAlpha = 1;
    dataPtr->hdScalerParams.globalAlpha = 0xFF;
    dataPtr->hdScalerParams.hilightOnOff = 0;
    
    for (i = 0; i < 256; i++)
    {
       dataPtr->hdScalerParams.colourLut[i] = 0;
    }
    
    dataPtr->hdScalerParams.inputPicWidth = 0;
    dataPtr->hdScalerParams.inputPicHeight = 0;
    dataPtr->hdScalerParams.inputWindowX0 = 0;
    dataPtr->hdScalerParams.inputWindowY0 = 0;
    dataPtr->hdScalerParams.inputWindowWidth = 0;
    dataPtr->hdScalerParams.inputWindowHeight = 0;
    dataPtr->hdScalerParams.outputWindowX0 = 0;
    dataPtr->hdScalerParams.outputWindowY0 = 0;
    dataPtr->hdScalerParams.outputWindowWidth = 0;
    dataPtr->hdScalerParams.outputWindowHeight = 0;
    
    err_code = FAPI_VISCALE_SetScalerToHdEncoder(
          dataPtr->viscaleHandle[VAL_VOUT_HD],
          dataPtr->viencHandle[VAL_VOUT_HD]);
    
    err_code = FAPI_VISCALE_SetScalingMethod(
          dataPtr->viscaleHandle[VAL_VOUT_HD],
          dataPtr->vioutHdScalingMethod);
    
    err_code = FAPI_VISCALE_SetDisplayAspectRatio(
          dataPtr->viscaleHandle[VAL_VOUT_HD],
          dataPtr->vioutDispAr[VAL_VOUT_HD]);
    
    err_code = FAPI_VISCALE_SetParamChangeCallback(
          dataPtr->viscaleHandle[VAL_VOUT_HD],
          VAL_ViscaleParamChgCb, dataPtr);
    
    err_code = FAPI_VISCALE_Start(
          dataPtr->viscaleHandle[VAL_VOUT_HD], scalerParams);
    
    err_code = FAPI_VISCALE_Resize(
          dataPtr->viscaleHandle[VAL_VOUT_HD], scalerParams); 

    err_code = FAPI_VISCALE_EnableDisable(
          dataPtr->viscaleHandle[VAL_VOUT_HD], 
          FAPI_VISCALE_PARAMETER_ON);
    
    FAPI_VISCALE_Alpha(
          dataPtr->viscaleHandle[VAL_VOUT_HD], 
          FAPI_VISCALE_PARAMETER_ON, 255);
    
    viscaleParams.scalerType = FAPI_VISCALE_SCALER_SD;
    
    dataPtr->viscaleHandle[VAL_VOUT_SD] = 
       FAPI_VISCALE_Open(&viscaleParams, &err_code);
    
    if (dataPtr->viscaleHandle[VAL_VOUT_SD] == 0)
    {
       return err_code;
    }
    
    err_code = FAPI_VISCALE_SetScalerToHdEncoder(
          dataPtr->viscaleHandle[VAL_VOUT_SD],
          dataPtr->viencHandle[VAL_VOUT_HD]);

    err_code = FAPI_VISCALE_SetDisplayAspectRatio(
          dataPtr->viscaleHandle[VAL_VOUT_SD],
          dataPtr->vioutDispAr[VAL_VOUT_SD]);

    err_code = FAPI_VISCALE_Start(
          dataPtr->viscaleHandle[VAL_VOUT_SD],
          &dataPtr->sdScalerParams);
    
    err_code = FAPI_VISCALE_Resize(
          dataPtr->viscaleHandle[VAL_VOUT_SD],
          &dataPtr->sdScalerParams);

    err_code = FAPI_VISCALE_EnableDisable(
          dataPtr->viscaleHandle[VAL_VOUT_SD], 
          FAPI_VISCALE_PARAMETER_ON);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, close VISCALE driver.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_ViscaleOpen
*******************************************************************************
*/
/* 21ca9d34 - complete */
static int32_t VAL_ViscaleClose (VAL_DataT* dataPtr)
{
    int32_t             err_code = FAPI_OK;
    VAL_VideoOutputT    output;

    for ( output = VAL_VOUT_SD; output < VAL_VOUT_NUMS; output++ )
    {
        if ( dataPtr->viscaleHandle[output] != 0 )
        {
            err_code = FAPI_VISCALE_Close(dataPtr->viscaleHandle[output]);
            if ( err_code == FAPI_OK )
            {
                dataPtr->viscaleHandle[output] = 0;
            }
            else
            {
                FAPI_SYS_PRINT_DEBUG(2, "[VAL] Close dataPtr->vioutSubId[%d] failed. %d\n",
                                        output, err_code);
                break;
            }
        }
    }

    return err_code;
}

/* ------------------------------------------------------------------------- */


/* 21ca9a94 - todo */
void func_21ca9a94(VAL_DataT* dataPtr, int b, int c, int d)
{
   FAPI_SYS_PRINT_MSG("func_21ca9a94\n");
}

/*!
*******************************************************************************
** \brief   Internal function, open HDMI driver.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_HdmiSetup, VAL_HdmiClose
*******************************************************************************
*/
static int32_t VAL_HdmiOpen (VAL_DataT* dataPtr)
{
   int32_t err_code = 0;
   FAPI_HDMI_OpenParamsT hdmiParams;
   
    if (dataPtr->hdmiHandle != 0)
    {
        return SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
    }
    
    dataPtr->hdmiHaveEDID  = 0;
    
    hdmiParams.version = FAPI_HDMI_VERSION;
    hdmiParams.block = 1;
    
    dataPtr->hdmiHandle = FAPI_HDMI_Open(&hdmiParams, &err_code);
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, close HDMI driver.
**
** \param   dataPtr     Handle returned by VAL_GoUp.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_HdmiSetup, VAL_HdmiOpen
*******************************************************************************
*/
/* 21ca9d04 - complete */
static int32_t VAL_HdmiClose (VAL_DataT* dataPtr)
{
    int32_t err_code = FAPI_OK;

    if ( dataPtr->hdmiHandle != 0 )
    {
       func_21c2118c/*FAPI_HDMI_VIDEO_Stop?*/(dataPtr->hdmiHandle);
       
        err_code = FAPI_HDMI_Close (dataPtr->hdmiHandle);

        if ( err_code == FAPI_OK )
        {
            dataPtr->hdmiHandle   = 0;
            dataPtr->hdmiHaveEDID = 0;
        }
        else {
            FAPI_SYS_PRINT_DEBUG(2, "[VAL] VAL_HdmiClose failed. %d\n", err_code);
        }
    }

    return err_code;
}

#if 0

/*!
*******************************************************************************
** \brief   Internal function, update HDMI connection status.
**
** \param   dataPtr         Handle returned by VAL_GoUp.
** \param   connectedPtr    Returns HDMI connection information if a non-NULL
**                          pointer is passed (1: connected, 0: not connected).
** \param   changePtr       Returns HDMI connection change indication if a 
**                          non-NULL pointer is passed (1: connection status
**                          has changed since last calling of this function, 
**                          0: not changed).
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_HdmiOpen, VAL_HdmiClose
*******************************************************************************
*/
static int32_t VAL_HdmiUpdateStatus (VAL_DataT* dataPtr, uint8_t* connectedPtr,
                                     uint8_t* changePtr)
{
    int32_t hpd_status;
    int32_t status;
    uint8_t statusChanged = 0;

#if 0
    if(dataPtr->hdmiId < 0) {
        goto VAL_HdmiUpdateStatus_end;
    }

    FAPEX_HDMI_Ioctl(dataPtr->hdmiId,
                     FAPEX_IOCCOM_HDMI_CHECK_HPD,
                     (FAPEXIOCARG3_T)&hpd_status );

    //FAPI_SYS_PRINT_MSG("FAPI_HDMI_CheckHPD: %X\n", hpd_status);
    
    if ( dataPtr->hdmiHaveEDID == 0 )
    {
        FAPEX_HDMI_Ioctl(dataPtr->hdmiId,
                         FAPEX_IOCCOM_HDMI_READ_EDID,
                         (FAPEXIOCARG3_T)&status );

        if ( status != FAPEX_HDMI_STATUS_OK )
        {
            FAPI_SYS_PRINT_DEBUG(2, "[VAL] FAPEX_IOCCOM_HDMI_READ_EDID failed!\n");
        }
        else
        {
            dataPtr->hdmiHaveEDID = 1;
        }
    }
#endif
    
    if ( (hpd_status & VAL_HDMI_HDP_STATUS_MASK) 
          == VAL_HDMI_HPD_STATUS_CONNECTED )
    {
        if ( dataPtr->hdmiConnected == 0 )
        {
            FAPI_SYS_PRINT_DEBUG(3,"[VAL] HDMI CONNECTION DETECTED\n");
            
            dataPtr->hdmiConnected = 1;
            
            statusChanged = 1;
        }
    }
    else
    {
        if ( dataPtr->hdmiConnected )
        {
            FAPI_SYS_PRINT_DEBUG(3,"[VAL] HDMI UNCONNECTED\n");
            
            statusChanged = 1;
        }
        
        dataPtr->hdmiConnected = 0;
        dataPtr->hdmiHaveEDID  = 0;
    }

VAL_HdmiUpdateStatus_end:

    if ( connectedPtr != NULL )
    {
        *connectedPtr = dataPtr->hdmiConnected;
    }

    if ( changePtr != NULL )
    {
        *changePtr = statusChanged;
    }

    return FAPI_OK;
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
** \brief   Internal function, check task for frame availability and information.
**
** \param   optData           Used to pass openPtr.
**
** \return  -
**
*******************************************************************************
*/
static void VAL_VidecCheckTask(void *optData)
{
    VAL_OpenT* openPtr = (VAL_OpenT*)optData;
    int32_t  ret;

#if 0
    while(1)
    {
        ret = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                FAPEX_IOCCOM_VIDEC_GET_DEC_FRAME_INFO,
                                (FAPEXIOCARG3_T)&openPtr->videcFrameInfo);
        if(ret == 0) {
            if(openPtr->videcFrameInfo.enableFlag & FAPEX_VIDEC_INFO_DEC_AVAILABLE) {
                VAL_VidecFrameAvlCb(optData);
            }
            if(openPtr->videcFrameInfo.enableFlag & FAPEX_VIDEC_INFO_DISP_AVAILABLE) {
                VAL_VidecFrameDecCb(optData);
            }
            if(openPtr->videcFrameInfo.enableFlag & FAPEX_VIDEC_INFO_DISP_ENABLE) {
                VAL_VidecFrameInfoCb(optData);
            }
            if(openPtr->videcFrameInfo.enableFlag & FAPEX_VIDEC_INFO_DISP_CHANGED) {
                VAL_VidecParamChgCb(optData);
            }
            if(openPtr->videcFrameInfo.enableFlag & FAPEX_VIDEC_INFO_STOPPED) {
                break;
            }
        }
        else {
            break;
        }
    }
    openPtr->checkThread = NULL;
#endif
}

#endif

/*!
*******************************************************************************
** \brief   Internal function, open video decoder driver.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   decoderPtr      Requested decoder.
** \param   enableAfd       Set to true if AFD handling shall be enabled.
** \param   environment     Requested environment (live or playback).
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_VidecClose
*******************************************************************************
*/
static int32_t VAL_VidecOpen (VAL_OpenT* openPtr,
                              const VAL_DecoderTypeT* decoderPtr,
                              uint8_t enableAfd,
                              VAL_EnvironmentT environment,
                              int Data_16)
{
    int32_t                    err_code = FAPI_OK; //sp144
    FAPI_VIDEC_OpenParamsT params; //sp92

    if ( openPtr->videcHandle != 0)
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_ALREADY_OPEN;
    }
    else
    {
        params.version = 0x9000a; //FAPI_VIDEC_VERSION
        params.decoderNumber = 0;
        params.decoderType = decoderPtr->system;
        params.decodeFrameBankSizeType = decoderPtr->frameBankSize;
                
        if (decoderPtr->system == 2)
        {
           params.Data_28 = Data_16; //sp120
        }
        else
        {
           params.Data_28 = 0;
        }

        params.decoderPlaybackMode = FAPI_VIDEC_NORMAL_PLAYBACK_MODE; //1;

        if ( enableAfd )
        {
            params.decoderAfdState = FAPI_VIDEC_AFD_ENABLE_AUTO; //16;
        }
        else
        {
            params.decoderAfdState = FAPI_VIDEC_AFD_DISABLE; //17;
        }

        switch ( environment )
        {
            case VAL_ENV_LIVE:
                params.decoderPlaybackEnvironment = FAPI_VIDEC_LIVE_PLAYBACK_ENVIRONMENT; //0;
                break;

            case VAL_ENV_PLAY:
                params.decoderPlaybackEnvironment = FAPI_VIDEC_PVR_PLAYBACK_ENVIRONMENT; //1;
                break;

            default:
                err_code = SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
                break;
        }

        if ( err_code == FAPI_OK )
        {
            openPtr->videcHandle = FAPI_VIDEC_Open(&params, &err_code);

//            FAPI_SYS_PRINT_MSG("FAPI_VIDEC_Open: err_code=%d", err_code);

            if (openPtr->videcHandle != 0)
            {
               //21ca8c94
               openPtr->Data_156_0 = 0;
               openPtr->Data_156_4 = 0;
               openPtr->Data_156_8 = 0;
               openPtr->Data_156_12 = 0;
               
               err_code = FAPI_VIDEC_SetParamChangeCallback(
                     openPtr->videcHandle,
                     VAL_VidecParamChgCb,
                     openPtr);
               
               if (err_code != 0)
               {
                  //->21ca8d5c
                  FAPI_VIDEC_Close(openPtr->videcHandle);
                  
                  openPtr->videcHandle = 0;
                  //21ca8d68
               }
               //21ca8cbc
            }
            //21ca8d68
        }
    }

    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, close video decoder driver.
**
** \param   openPtr         Handle returned by VAL_Open.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_VidecOpen
*******************************************************************************
*/
/* 21ca8aa4 - complete */
static int32_t VAL_VidecClose (VAL_OpenT* openPtr)
{
    int32_t err_code = FAPI_OK;

    if ( openPtr->videcHandle != 0 )
    {
        err_code = FAPI_VIDEC_Close(openPtr->videcHandle);

        openPtr->videcHandle = 0;
    }

    return err_code;
}


#if 0

/*!
*******************************************************************************
** \brief   Internal function, start video decoder driver.
**
** \param   openPtr             Handle returned by VAL_Open.
** \param   operation           Requested operation.
** \param   mode                Requested playback mode.
** \param   feedViaTsd          Set to true to indicate data feeding via TSD
**                              (normal operation), only special playback modes
**                              require direct feeding of data.
** \param   checkDecoderType    Needed for H.264 decoder: First startup is
**                              preliminary, decoder matching is checked after
**                              stream parameters are available.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_VidecStop
*******************************************************************************
*/
static int32_t VAL_VidecStart (VAL_OpenT* openPtr,
                               int32_t mode, //r9
                               uint8_t feedViaTsd, //sp
                               uint8_t checkDecoderType)
{
    int32_t                         err_code = FAPI_OK;
    uint32_t fp = 0;
    VAL_EnvironmentT sl = VAL_ENV_NONE;
//    FAPEX_VIDEC_StartParamStrT      decStartParam;
//    FAPEX_VIOUT_ResizeParamStrT     resizeParam;

    FAPI_SYS_PRINT_DEBUG(4, "VAL_VidecStart: mode=%d, feedViaTsd=%d\n", 
          mode, feedViaTsd);
    
    if ( openPtr->videcHandle == 0 )
    {
        return SUBSYS_VIDEO_VAL_INTERNAL;
    }
    
    do
    {
       FAPI_VIDEC_SetAutoScaleCallback(openPtr->videcHandle,
             FAPI_VISCALE_AutoScaler,
             openPtr->dataPtr->viscaleHandle[VAL_VOUT_HD]);

       FAPI_VIDEC_SetAutoScaleCallback(openPtr->videcHandle,
             FAPI_VISCALE_AutoScaler,
             openPtr->dataPtr->viscaleHandle[VAL_VOUT_SD]);

       err_code = FAPI_VIDEC_SetDecoderToHdEncoder(openPtr->videcHandle,
             openPtr->dataPtr->viencHandle[VAL_VOUT_HD]);
     
       if (err_code != 0)
       {
          //->21ca9158
          break;
       }
       
       sl = openPtr->openParams.environment;

       if (mode == 1)
       {
          fp = openPtr->startFlags;
       }
       
       FAPI_SYS_PRINT_DEBUG(4, "VAL_VidecStart: sl=%d, fp=%d\n", 
             sl, fp);
       
       if (sl == 0)
       {
          //->21ca93c0
          sl = 0;
          FAPI_VIDEC_SetPlaybackEnvironment(openPtr->videcHandle, sl);
          func_21c2f7a4();
          func_21c2f91c(1);
          //->21ca9224
       }
       else if (sl == 1)
       {
          //->21ca9210
          sl = 1;
          func_21c2f91c(0);
          FAPI_VIDEC_SetPlaybackEnvironment(openPtr->videcHandle, sl);
       }
       else
       {
          err_code = SUBSYS_VIDEO_VAL_INTERNAL;
          //->21ca9158
          break;
       }
       //21ca9224
       err_code = FAPI_VIDEC_SetPesParserToDecoder(openPtr->videcHandle, fp);
       if (err_code != 0)
       {
          //->21ca9158
          break;
       }
       
       err_code = FAPI_VIDEC_SetPlaybackMode(openPtr->videcHandle, mode);
       if (err_code != 0)
       {
          //->21ca9158
          break;
       }
       
       if (openPtr->decoder.system == 1)
       {
          //->21ca93dc
          err_code = FAPI_VIDEC_SetMpegIFrameMode(openPtr->videcHandle, 
                feedViaTsd/*sp*/ ^ 1);
          
          if (err_code != 0)
          {
             //->21ca9158
             break;
          }
       }
       //21ca9258
#if 0
       /* Set frame availability callback only if video decoder will not
          potentially be rebooted. On those cases it will be set after reboot
          condition has been checked. */
       if ( (!checkDecoderType)
         || (openPtr->decoder.system != FAPEX_VIDEC_CODEC_TYPE_H264) )
       {
           openPtr->startFlags = FAPEX_VIDEC_NOTIFY_FLAGS_DEC_AVAILABLE |
                                 FAPEX_VIDEC_NOTIFY_FLAGS_DISP_AVAILABLE |
                                 FAPEX_VIDEC_NOTIFY_FLAGS_FRAME_INFO;
       }
       else {
           openPtr->startFlags = 0;
       }
#else
       openPtr->frameAvailable          = 0;
       openPtr->frameDecoded            = 0;
       openPtr->videcFrameInfoAvailable = 0;
       
       if ((checkDecoderType/*r6*/ == 0) ||
             (openPtr->decoder.system != FAPI_VIDEC_H264_HP41/*2*/))
       {
          //21ca927c
          FAPI_VIDEC_SetFrameDecodedCallback(openPtr->videcHandle,
                func_21ca7b24, openPtr);
          
          FAPI_VIDEC_SetFrameAvailableCallback(openPtr->videcHandle, 
                func_21ca7b30, openPtr);
          
          FAPI_VIDEC_SetVideoDecInfoCallback(openPtr->videcHandle,
                func_21ca7b54, openPtr);
       }
#endif

       //21ca92ac
       err_code = FAPI_VIDEC_Start(openPtr->videcHandle);
       if (err_code != 0)
       {
          //->21ca9158
          break;
       }
       //21ca92bc
       FAPI_SYS_PRINT_DEBUG(4, "VAL_VidecStart: checkDecoderType=%d, openPtr->decoder.system=%d, openPtr->dataPtr->videoBlanked=%d\n", 
             checkDecoderType,
             openPtr->decoder.system,
             openPtr->dataPtr->videoBlanked);
       
       if ( checkDecoderType )
       {
           //21ca92c4
           switch ( openPtr->decoder.system )
           {
               case FAPEX_VIDEC_CODEC_TYPE_H264:
                   //21ca92cc
                   /* NOTE: Do not unblank yet. Wait for picture parameters
                            in order to determine if booted video decoder is
                            correct (see VAL_Task). */
                   openPtr->decoderStatus = VAL_STATUS_BOOTING;
                   break;

               default:
               case FAPEX_VIDEC_CODEC_TYPE_MPEG2:
                   //21ca92dc
                   /* NOTE: All MPEG types: unblank immediately */

                   openPtr->decoderStatus = VAL_STATUS_RUNNING;

                   if (openPtr->dataPtr->videoBlanked == 0)
                   {
                      //21ca92f4
                      err_code = FAPI_VIDEC_EnableDisable(openPtr->videcHandle,
                            sl);
                   }

                   break;
           }
       }
       else
       {
           //21ca938c
           openPtr->decoderStatus  = VAL_STATUS_RUNNING;

           if (openPtr->dataPtr->videoBlanked == 0)
           {
              //21ca93a4
              err_code = FAPI_VIDEC_EnableDisable(openPtr->videcHandle,
                    sl);

              if (err_code != 0)
              {
                 //->21ca9158
                 break;
              }
              //21ca93b8
           }
       }
       //21ca9308
       openPtr->dataPtr->hdScalerParams.inputPicWidth = 0;
       openPtr->dataPtr->hdScalerParams.inputPicHeight = 0;
       openPtr->dataPtr->hdScalerParams.inputWindowX0 = 0;
       openPtr->dataPtr->hdScalerParams.inputWindowY0 = 0;
       openPtr->dataPtr->hdScalerParams.inputWindowWidth = 0;
       openPtr->dataPtr->hdScalerParams.inputWindowHeight = 0;

       FAPI_VISCALE_Resize(openPtr->dataPtr->viscaleHandle[VAL_VOUT_HD],
             &openPtr->dataPtr->hdScalerParams);

       FAPI_VISCALE_Resize(openPtr->dataPtr->viscaleHandle[VAL_VOUT_SD],
             &openPtr->dataPtr->sdScalerParams);

#if 0       
        // ToDo for feedViaTsd


        switch(mode) {
            case VAL_PLAYMODE_NORMAL:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_NORMAL;
                break;
            case VAL_PLAYMODE_FAST_LIB_IONLY:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_NORMAL;
                break;
            case VAL_PLAYMODE_PAUSE:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_PAUSE;
                break;
            case VAL_PLAYMODE_FAST_DEC_IONLY:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_I_ONLY;
                break;
            case VAL_PLAYMODE_FAST_DEC_IP:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_I_AND_P_ONLY;
                break;
            case VAL_PLAYMODE_FAST_CONTROLLEDFEED:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_FIRST_I_ONLY;
                break;
            case VAL_PLAYMODE_SLOW_2X:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_2X;
                break;
            case VAL_PLAYMODE_SLOW_4X:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_4X;
                break;
            case VAL_PLAYMODE_SLOW_8X:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_SLOW_FORWARD_8X;
                break;
            default:
                decStartParam.playbackMode = FAPEX_VIDEC_PLAYBACK_MODE_UNKNOWN;
        }
        decStartParam.outputMode = FAPEX_VIDEC_ENABLE_SYNCHRONOUSLY_SUSPEND;
        decStartParam.flags      = openPtr->startFlags;

        err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                     FAPEX_IOCCOM_START,
                                     (FAPEXIOCARG3_T)&decStartParam);
        if ( err_code != FAPI_OK )
        {
            FAPI_SYS_PRINT_DEBUG(2, "[VAL] VAL_VidecStart: Videc start error! %d\n", err_code);
            break;
        }
#endif
    }
    while ( 0 );

    if ( err_code != FAPI_OK )
    {
       //21ca9158
#if 0
        (void)FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                FAPEX_IOCCOM_STOP,
                                (FAPEXIOCARG3_T)NULL);
#endif

        FAPI_VIDEC_Stop(openPtr->videcHandle);
        FAPI_VIDEC_ClearAutoScaleCallback(openPtr->videcHandle);
        FAPI_VIDEC_ClearVideoDecInfoCallback(openPtr->videcHandle);
        
        openPtr->decoderStatus = VAL_STATUS_STOPPED;
    }

    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, stop video decoder driver.
**
** \param   openPtr         Handle returned by VAL_Open.
** \param   freeze          If true, freeze last picture instead of blanking
**                          video.
**
** \return  Possible return codes:
**          - FAPI_OK  Successful completion.
**
** \sa      VAL_VidecStart
*******************************************************************************
*/
/* 21ca8984 - todo */
static int32_t VAL_VidecStop (VAL_OpenT* openPtr, uint8_t freeze)
{
    int32_t err_code = FAPI_OK;

    if ( openPtr->videcHandle != 0 )
    {
        if ( freeze )
        {
           //21ca89d0
#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_VIDEC_SET_FREEZE_MODE,
                                         (FAPEXIOCARG3_T)FAPEX_VIDEC_FREEZE_ON);
#else
            err_code = FAPI_VIDEC_FreezeContinue(openPtr->videcHandle,
                  FAPI_VIDEC_FREEZE_ON);
#endif
        }
        else
        {
           //21ca89a8
#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_VIDEC_SET_FREEZE_MODE,
                                         (FAPEXIOCARG3_T)FAPEX_VIDEC_FREEZE_OFF);
#else
            err_code = FAPI_VIDEC_EnableDisable(openPtr->videcHandle,
                  FAPI_VIDEC_ENABLE_FORCE_OFF);
#endif
        }
        
        if ( err_code == FAPI_OK )
        {
           //21ca89e4
#if 0
            err_code = FAPEX_VIDEC_Ioctl(openPtr->videcId,
                                         FAPEX_IOCCOM_STOP,
                                         (FAPEXIOCARG3_T)NULL);
#else
            err_code = FAPI_VIDEC_Stop(openPtr->videcHandle);
            
            FAPI_VIDEC_ClearAutoScaleCallback(openPtr->videcHandle);
            
            FAPI_VIDEC_ClearVideoDecInfoCallback(openPtr->videcHandle);
#endif
        }
        
        openPtr->decoderStatus = VAL_STATUS_STOPPED;
    
        func_21c2f7a4(); //->fapi_sync.c
    }
    
    return err_code;
}

/*!
*******************************************************************************
** \brief   Internal function, callback indicating that frame has been decoded.
**
** \param   optData           Used to pass openPtr.
**
** \return  -
**
*******************************************************************************
*/
static void VAL_VidecFrameDecCb (void* optData)
{
    VAL_OpenT* openPtr = (VAL_OpenT*)optData;
    
    FAPI_SYS_PRINT_DEBUG(4, "[VAL] Callback: Video frame decoded!\n");
    
    openPtr->frameDecoded = 1;
}

/*!
*******************************************************************************
** \brief   Internal function, frame availability callback.
**
** \param   optData           Used to pass openPtr.
**
** \return  -
**
*******************************************************************************
*/
static void VAL_VidecFrameAvlCb (void* optData)
{
    VAL_OpenT* openPtr = (VAL_OpenT*)optData;

    FAPI_SYS_PRINT_DEBUG(4, "[VAL] Callback: Video frame available!\n");

    openPtr->frameAvailable = 1;

    if ( openPtr->frameAvlCb != NULL )
    {
        openPtr->frameAvlCb(openPtr->frameAvlCbArg);
    }
}

/*!
*******************************************************************************
** \brief   Internal function, frame information callback.
**
** \param   optData           Used to pass openPtr.
**
** \return  -
**
*******************************************************************************
*/
static void VAL_VidecFrameInfoCb (void* optData)
{
    VAL_OpenT* openPtr = (VAL_OpenT*)optData;
    
    openPtr->videcFrameInfoAvailable = 1;
}

#endif

/* 21ca7b98 - complete */
static void VAL_VidecParamChgCb(FAPI_VIDEC_FrameInfoStateT* nextFrameInfoPtr,
      FAPI_VIDEC_FrameInfoStateT* lastFrameInfoPtr, void* optData)
{
   VAL_OpenT* openPtr = (VAL_OpenT*)optData;

   FAPI_SYS_PRINT_DEBUG(4, "[VAL] Callback: Video parameters changed!\n");

   FAPI_SYS_PRINT_DEBUG(4, "[VAL] nextFrameInfoPtr->aspectRatio=%d\n",
         nextFrameInfoPtr->aspectRatio);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] nextFrameInfoPtr->frameField=%d\n",
         nextFrameInfoPtr->frameField);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] nextFrameInfoPtr->fieldInversion=%d\n",
         nextFrameInfoPtr->fieldInversion);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] nextFrameInfoPtr->decodedWidth=%d\n",
         nextFrameInfoPtr->decodedWidth);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] nextFrameInfoPtr->decodedHeight=%d\n",
         nextFrameInfoPtr->decodedHeight);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] lastFrameInfoPtr->aspectRatio=%d\n",
         lastFrameInfoPtr->aspectRatio);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] lastFrameInfoPtr->frameField=%d\n",
         lastFrameInfoPtr->frameField);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] lastFrameInfoPtr->fieldInversion=%d\n",
         lastFrameInfoPtr->fieldInversion);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] lastFrameInfoPtr->decodedWidth=%d\n",
         lastFrameInfoPtr->decodedWidth);
   FAPI_SYS_PRINT_DEBUG(4, "[VAL] lastFrameInfoPtr->decodedHeight=%d\n",
         lastFrameInfoPtr->decodedHeight);

   if ((nextFrameInfoPtr->decodedWidth != 0) &&
         (nextFrameInfoPtr->decodedHeight != 0))
   {
      openPtr->Data_156_8 = nextFrameInfoPtr->decodedWidth;
      openPtr->Data_156_12 = nextFrameInfoPtr->decodedHeight;
   }
   
   if ( openPtr->paramChangeCb != NULL )
   {
       openPtr->paramChangeCb(nextFrameInfoPtr,
                              lastFrameInfoPtr, 
                              openPtr->paramChangeCbArg);
   }
}

#if 0

/*!
*******************************************************************************
** \brief   Internal function, determines frame bank size out of picture
**          dimensions
**
** \param   paramsPtr         VES parameters containing pictures dimensions.
** \param   fbSizePtr         Returns frame bank size on success.
**
** \return  Possible return codes:
**          - FAPI_OK                             Successful completion.
**          - SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER  Invalid picture parameters.
**
*******************************************************************************
*/
/* 21ca7bd4 - complete */
static int32_t VAL_GetFrameBankSize (const /*FAPEX_VIDEC_VESParamStrT*/VAL_VESParamStrT* paramsPtr,
                                     int32_t* fbSizePtr)
{
    int32_t err_code = FAPI_OK;

    if ( (paramsPtr->decodedWidth  <= 64)
      && (paramsPtr->decodedHeight <= 48) )
    {
        //Undeterministic parameters case.
        *fbSizePtr = VAL_DEFAULT_DECODERFBSIZE;
    }
    else if ( (paramsPtr->decodedWidth  <= 720)
           && (paramsPtr->decodedHeight <= 576) )
    {
        *fbSizePtr = FAPEX_VIDEC_FRAME_BANK_SIZE_SD;
    }
    else if ( (paramsPtr->decodedWidth  <= 1280)
           && (paramsPtr->decodedHeight <= 720) )
    {
        *fbSizePtr = FAPEX_VIDEC_FRAME_BANK_SIZE_1280HD;
    }
    else if ( (paramsPtr->decodedWidth  <= 1440)
           && (paramsPtr->decodedHeight <= 576) )
    {
        *fbSizePtr = FAPEX_VIDEC_FRAME_BANK_SIZE_1440HD;
    }
    else if ( (paramsPtr->decodedWidth  <= 1920)
           && (paramsPtr->decodedHeight <= 1088) )
    {
        *fbSizePtr = FAPEX_VIDEC_FRAME_BANK_SIZE_1920HD;
    }
    else
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_BAD_PARAMETER;
    }

    return err_code;
}

#endif

/*!
*******************************************************************************
** \brief   Internal function, checks validity of openPtr handle.
**
** \param   openPtr           Pointer to be checked.
**
** \return  Possible return codes:
**          - SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE   Handle is a NULL pointer.
**          - SUBSYS_VIDEO_VAL_ERROR_STATE          Module is in an error state,
**                                                  needs to be closed by
**                                                  using VAL_Close.
**          - SUBSYS_VIDEO_VAL_ERR_NOT_OPEN         VAL is not open.
**
*******************************************************************************
*/
/* 21ca7c88 - complete */
static int32_t VAL_ArgCheckOpen (const VAL_OpenT* openPtr)
{
    int32_t err_code;

    if ( openPtr == NULL )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE;
    }
    else if ( /*(openPtr->dataPtr == NULL) ||*/ 
          (openPtr->dataPtr->openPtr != openPtr) )
    {
        err_code = SUBSYS_VIDEO_VAL_ERR_NOT_OPEN;
    }
    else if ( openPtr->operation == VAL_OP_ERROR )
    {
        err_code = SUBSYS_VIDEO_VAL_ERROR_STATE;
    }
    else
    {
        err_code = FAPI_OK;
    }

    return err_code;
}

#if 0

/* 21ca7a28 - complete */
int32_t func_21ca7a28(VAL_DataT* a, VAL_Data_2316* b)
{
   int32_t err_code = FAPI_OK;

//   FAPI_SYS_PRINT_MSG("func_21ca7a28\n");

   if (a == 0)
   {
      err_code = SUBSYS_VIDEO_VAL_ERR_INVALID_HANDLE; //-3500008;
   }
   else if (a->hdmiHaveEDID == 0)
   {
      err_code = SUBSYS_VIDEO_VAL_DATA_NOT_AVAILABLE; //-3500100;
   }
   else if (b != 0)
   {
      *b = a->Data_2316;
   }

   return err_code;
}

#endif

/*lint -restore */
