/*!
********************************************************************************
**
** \file        ./fapi/board/src/board_ifc.h
**
** \brief       Board Control function Interface (BIC).
**
** This file contains the definition of (HW-platform) board specific control
** functions to be called by FAPI core drivers or other middleware and application code.
**
** \note        The implementation of the real board specific service functions
**              should be done within the board specific source file
**                  "boards/<customer>/<board_name>/<filename>.c"
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/
#ifndef FAPI_BOARD_SERVICES_H
#define FAPI_BOARD_SERVICES_H

#include <fapi/sys_driver.h>

//******************************************************************************
//******************************************************************************
//** Enumerated type definitions
//******************************************************************************
//******************************************************************************

/*!
********************************************************************************
** \brief Control definitions for diagnostic LEDs.
********************************************************************************
*/
typedef enum
{
    FAPI_BOARD_TEST_LED_OFF        = 0x00000000UL,  //!< LED Off
    FAPI_BOARD_TEST_LED_ON         = 0x00000001UL,  //!< LED On
    FAPI_BOARD_GET_TEST_KEY        = 0x00000002UL   //!< Get simple 'test-push-button' status
} FAPI_BOARD_LedCommandT;                           //!< enum definition for 'test-LED' and 'test-push-button'

/*!
********************************************************************************
** \brief Control definitions for RESET signals and SubSystem PowerSupply
********************************************************************************
*/
typedef enum
{
    FAPI_BOARD_RESET_ACTIVE        = 0x00000000UL,  //!< activate ResetControlSignal
    FAPI_BOARD_RESET_INACTIVE      = 0x00000001UL,  //!< de-activate ResetControlSignal
    FAPI_BOARD_RESET_PULSE         = 0x00000002UL,  //!< generate complete Reset-Pulse
    FAPI_BOARD_POWER_OFF           = 0x00000003UL,  //!< Subsystem power-off
    FAPI_BOARD_POWER_ON            = 0x00000004UL,  //!< Subsystem power-on
    FAPI_BOARD_POLL_IRQ_STATUS     = 0x00000005UL,  //!< Checking IRQ status
} FAPI_BOARD_ControlCommandT;                         //!< enumerate definition for 'Reset & Power Control'

/*!
********************************************************************************
** \brief Control definitions if SCART pin (pin#8) is 'input'.
********************************************************************************
*/
typedef enum
{
    FAPI_BOARD_SCART_SB_OFF        = 0x00000000UL,  //!< Pin8 -> 0..2V
    FAPI_BOARD_SCART_SB_16_9       = 0x00000001UL,  //!< Pin8 -> 5V
    FAPI_BOARD_SCART_SB_4_3        = 0x00000002UL,  //!< Pin8 -> 12V
    FAPI_BOARD_SCART_SB_UNDEFINED  = 0x00000003UL,  //!< unspecified
} FAPI_BOARD_ScartSbInputT;                         //!< enumerate definition for 'SCART-pin-8 InputStatus'

/*!
********************************************************************************
** \brief Control definitions if SCART pin (pin#16) is 'input'.
********************************************************************************
*/
typedef enum
{
    FAPI_BOARD_SCART_FB_OFF        = 0x00000000UL,  //!< Pin16 -> 0V
    FAPI_BOARD_SCART_FB_RGB        = 0x00000001UL,  //!< Pin16 -> 1V
} FAPI_BOARD_ScartFbInputT;                         //!< enumerate definition for 'SCART-pin-16 InputStatus'

/*!
********************************************************************************
** \brief Control definitions for SCART 'input-pins' informations.
********************************************************************************
*/
typedef struct
{
    FAPI_BOARD_ScartSbInputT        pin8Info;   //!< SCART pin 8 information
    FAPI_BOARD_ScartFbInputT        pin16Info;  //!< SCART pin 16 information
} FAPI_BOARD_ScartStatusT;                      //!< structure definition for 'SCART-pin-8/16 InputStatus'

/*!
********************************************************************************
** \brief Control definitions for Scart 'output' pins.
********************************************************************************
*/
typedef enum
{
    FAPI_BOARD_SCART_MODE_OFF          = 0x00000000UL, //!< Pin#8 -> 0V
    FAPI_BOARD_SCART_MODE_4_3          = 0x00000001UL, //!< Pin#8 -> 12V
    FAPI_BOARD_SCART_MODE_16_9         = 0x00000002UL, //!< Pin#8 -> 5V
    FAPI_BOARD_SCART_VIDEO_OUTPUT_CVBS = 0x00000003UL, //!< Pin#16 -> 0V
    FAPI_BOARD_SCART_VIDEO_OUTPUT_RGB  = 0x00000004UL, //!<
    FAPI_BOARD_SCART_TV_SOURCE_DVB     = 0x00000005UL, //!< SmartMPEG -> TV-Scart
    FAPI_BOARD_SCART_TV_SOURCE_VCR     = 0x00000006UL, //!< VCR-Sign. -> TV-Scart
    FAPI_BOARD_SCART_VCR_SOURCE_DVB    = 0x00000007UL, //!< SmartMPEG -> VCR-Scart
    FAPI_BOARD_SCART_VCR_SOURCE_TV     = 0x00000008UL, //!< TV-Sign.  -> VCR-Scart
    FAPI_BOARD_SCART_VCR_GET_STATUS    = 0x00000009UL, //!< get 'Scart' StatusInfo NOTE: Info provided via 'void *pOption' pointing to 'FAPI_BOARD_SCART_STATUS_INFO'
} FAPI_BOARD_ScartCommandT;

//******************************************************************************
//******************************************************************************
//** Function prototype definitions (eventually used in FAPI drivers)
//******************************************************************************
//******************************************************************************
/*!
****************************************************************************
** \brief 'BoardInitDetect' hook function signature
** for parameter details see 'FAPI_BOARD_INIT_DETECT_BOARD'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_InitDetectHookT)(
                    uint32_t                    optInitBitFlags,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control Led' hook function signature
** for parameter details see 'FAPI_BOARD_CONTROL_TEST_LED_KEY'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlLedHookT)(
                    int32_t                       index,
                    FAPI_BOARD_LedCommandT        command,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control FrontEnd-Reset/Power' hook function signature
** for parameter details see 'FAPI_BOARD_CONTROL_FE'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlFeHookT)(
                    int32_t                       index,
                    FAPI_BOARD_ControlCommandT      command,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control FrontEnd Detection' hook function signature
** for parameter details see 'FAPI_BOARD_CONTROL_FE_DETECT'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlFeDetectHookT)(
                    int32_t                       index,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control HardDisk-Reset/Power' hook function signature
** for parameter details see 'FAPI_BOARD_CONTROL_HD'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlHdHookT)(
                    int32_t                       index,
                    FAPI_BOARD_ControlCommandT      command,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control Scart-Connector' hook function signature
** for parameter details see 'FAPI_BOARD_CONTROL_SCART'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlScartHookT)(
                    int32_t                       index,
                    FAPI_BOARD_ScartCommandT      command,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control TsPath routing' hook function signature
** for parameter details see 'FAPI_BOARD_EXT_CONTROL_TS_PATH'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlTsPathHookT)(
                    int32_t                       index,
                    uint32_t                      command,
                    void*                         optPtr );

/*!
****************************************************************************
** \brief 'Control Hdmi-Path routing' hook function signature
** for parameter details see 'FAPI_BOARD_EXT_CONTROL_HDMI_PATH'
****************************************************************************
*/
typedef int32_t(*FAPI_BOARD_ControlHdmiPathHookT)(
                    int32_t                       index,
                    uint32_t                      command,
                    void*                         optPtr );


// some 'FAPI' defines for 'diagIsBits' and 'diagAllowBits'
// in below cases 'diagInfoPtr' is a simple string-pointer
#define FAPI_BOARD_DIAG_BITS_ERR_HALT    0x01    //!< severe HW-Error occured, system should 'HALT/REBOOT'
#define FAPI_BOARD_DIAG_BITS_IMPORTANT   0x02    //!< 'important' diagnostic info (no action required)
#define FAPI_BOARD_DIAG_BITS_INTERESTING 0x04    //!< 'interesting' info
#define FAPI_BOARD_DIAG_BITS_JUST_INFO   0x08    //!< 'not so important (but complete)' diagnostic info

// some 'FAPI' defines for 'diagParamFormat' bit-field
#define FAPI_BOARD_DIAG_FORM_JUST_STR   0x00    //!< in this case, 'diagInfoPtr' is a simple string-pointer
#define FAPI_BOARD_DIAG_FORM_USER_SPEC  0x0F    //!< in this case , 'diagInfoPtr','optParamA','optParamB' have special usage

/*!
****************************************************************************
** \brief diagnostic information bit-flags, bit-field signature
**
****************************************************************************
*/
                                        // do not know how to make comment shorter and appear in doxigen !!
typedef union {
    uint32_t allBF;                     //!< all following bit-fields fit into a 'U32-word' so it can be easily passed as a parameter
    struct {
        uint32_t diagIsBits      : 4;   //!< bit-flags indicating what level of diagnostic-info is issued, Note: keep aligned at bit0..., for bit-definitions see #FAPI_BOARD_DIAG_BITS_ERR_HALT, #FAPI_BOARD_DIAG_BITS_IMPORTANT, #FAPI_BOARD_DIAG_BITS_JUST_INFO
        uint32_t diagAllowBits   : 4;   //!< bit-flags to enable/disable certain diagnositc levels/reasons, 'diagAllowBits' have same meaning as 'diagIsBits'
        uint32_t diagParamFormat : 4;   //!< bit-field for interpretation-mode of other diagnostic parameters, see #FAPI_BOARD_DIAG_FORM_JUST_STR, #FAPI_BOARD_DIAG_FORM_USER_SPEC
        uint32_t smallIndexValue : 4;   //!< bit-field for 'small index-value purpose', e.g. fron-end-index, etc.
        uint32_t userDiagIndex   : 8;   //!< byte might be used for 'decode-function-index' purpose, e.g. to be able to route diagnostic outputs, to a specific 'diagnostic print function'
        uint32_t NotUsedYet      : 8;
    } dBf;                              //!< the individual diagnostic Bit-Fields
} FAPI_BOARD_DiagnosticInfoFlagsT;


/*!
****************************************************************************
** \brief 'Diagnostic information' hook function signature
** This function controls the reset-signal and power-supply of the harddisk.
**
** \param diagAllInfoBits 32-bit-value with bit-fields as defined by 'FAPI_BOARD_DiagnosticInfoFlagsT'
** \param diagInfoPtr     (usually) pointer to diagnoistic info-string
** \param optParamA       optional further parameter
** \param optParamB       optional further parameter
**
** \sa FAPI_BOARD_DIAGNOSTIC_TS_PATH, FAPI_BOARD_DIAGNOSTIC_HDMI_PATH, FAPI_BOARD_DIAGNOSTIC_CI_CONTROL, FAPI_BOARD_DIAGNOSTIC_GENERALPURPOSE
**
****************************************************************************
*/
typedef void (*FAPI_BOARD_DiagnosticInfoHookT)(
    uint32_t     diagAllInfoBits,       //!< actually of type 'FAPI_BOARD_DiagnosticInfoFlagsT'
    void*        diagInfoPtr,           //!< usually a string pointer to the informatoin
    uint32_t     optParamA,             //!< optional parameter for specific use
    uint32_t     optParamB );           //!< optional parameter for specific use

//******************************************************************************
//******************************************************************************
//** Control function macros
//******************************************************************************
//******************************************************************************

/*!
********************************************************************************
** \brief register a 'board' init- (and optionally detect) function
**  this function is meant to be called via the 'board_ifc'
**  after fapi-initialization was done, so fapi-drivers could be used for this
**
** \param optInitBitFlags   special bit-flags for future use
** \param optPtr            optional pointer, also for future use
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_INIT_DETECT_FUNCTION( optInitBitFlags , optPtr)                                \
        ( ( FAPI_BOARD_Services.controlHook_BrdInitDetect != 0 )                        \
        ? FAPI_BOARD_Services.controlHook_BrdInitDetect( optInitBitFlags, optPtr )       \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

/*!
********************************************************************************
** \brief Controls a LED.
**
** Controls a diagnostic LED and/or a ScopeTrigger-Pin on the hw-platform
**
** \param index   Index of the LED to be controlled.
** \param command LED value to drive (FAPI_BOARD_LedCommandT).
** \param optPtr  Optional parameters (not used yet).
**
** \sa FAPI_BOARD_LedCommandT
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_CONTROL_TEST_LED_KEY( index, command, optPtr )                       \
        ( ( FAPI_BOARD_Services.controlHook_Led != 0 )                            \
        ? FAPI_BOARD_Services.controlHook_Led( index, command, optPtr )         \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

/*!
********************************************************************************
** \brief Controls the reset-signal and power-supply of the frontend.
**
** This function controls the reset-signal and power-supply of the frontend.
**
** \param index   Index of the frontend to be controlled.
** \param command Type of reset signal (FAPI_BOARD_ControlCommandT).
** \param optPtr  Optional parameters (not used yet).
**
** \sa FAPI_BOARD_ResetPowerCommandT
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_CONTROL_FE( index, command, optPtr )                  \
        ( ( FAPI_BOARD_Services.controlHook_FeReset != 0 )                      \
        ? FAPI_BOARD_Services.controlHook_FeReset( index, command, optPtr )     \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

/*!
********************************************************************************
** \brief Detects the type of a connected frontend .
**
** This function detects the type of a connected frontend by I2C-Probing.
**
** \param index   Index of the frontend to be detected.
** \param optPtr  Frontend handle into which the detected frontend sets its
**                specific function implementations
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_CONTROL_FE_DETECT( index, optPtr )                   \
        ( ( FAPI_BOARD_Services.controlHook_FeDetect != 0 )             \
        ? FAPI_BOARD_Services.controlHook_FeDetect( index, optPtr )     \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

/*!
********************************************************************************
** \brief Controls the reset-signal and power-supply of the harddisk.
**
** This function controls the reset-signal and power-supply of the harddisk.
**
** \param index   Index of the harddisk to be controlled.
** \param command Type of reset signal (FAPI_BOARD_ControlCommandT).
** \param optPtr  Optional parameters, if command equals FAPI_BOARD_POLL_IRQ_STATUS
**                optPtr must point to an uint32_t variable where the resulting
**                status will be written into.
**
** \sa FAPI_BOARD_ResetPowerCommandT
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_CONTROL_HD( index, command, optPtr )                         \
        ( ( FAPI_BOARD_Services.controlHook_HdReset != 0 )                      \
        ? FAPI_BOARD_Services.controlHook_HdReset( index, command, optPtr )     \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

/*!
********************************************************************************
** \brief Controls a specific SCART pin.
**
** This function controls a specific SCART pin.
**
** \param index   Index of the Scart connector to be controlled.
** \param command Type of scart pin command (FAPI_BOARD_ScartCommandT).
** \param optPtr  Optional parameters (not used yet).
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_CONTROL_SCART( index, command, optPtr )                     \
        ( ( FAPI_BOARD_Services.controlHook_Scart != 0 )                       \
        ? FAPI_BOARD_Services.controlHook_Scart( index, command, optPtr )      \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

//=============================================================================
//          Controls with externally defined control codes
//=============================================================================

/*!
********************************************************************************
** \brief Controls possible multiplexers in the TS-data-path.
**
** \param index   Index of the decoder chip TS path inpuut (0=A, 1=B, etc.).
** \param command Specific TS-path (MUX)component related command
** \param optPtr  Optional parameters if needed
**
** \return
** - FAPI_ERR_FEATURE_NOT_SUPPORTED if there is no function registered
** - any other value is the result of the registered function call
********************************************************************************
*/
#define FAPI_BOARD_EXT_CONTROL_TS_PATH( index, command, optPtr )             \
        ( ( FAPI_BOARD_Services.controlHook_TsPath != 0 )                    \
        ? FAPI_BOARD_Services.controlHook_TsPath( index, command, optPtr )   \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

/*!
*******************************************************************************
** \brief Controls possible multiplexers in the HDMI-data-path.
**
*******************************************************************************
*/
#define FAPI_BOARD_EXT_CONTROL_HDMI_PATH( index, command, optPtr )           \
        ( ( FAPI_BOARD_Services.controlHook_TsPath != 0 )                    \
        ? FAPI_BOARD_Services.controlHook_TsPath( index, command, optPtr )   \
        : FAPI_ERR_FEATURE_NOT_SUPPORTED )

//=============================================================================
//          for Diagnostic purpose
//=============================================================================

/*!
******************************************************************************
** \brief interface for notification of 'TS-Path-diagnostic events'
** this 'hook-function' can be used to inform about TS-path control activities
**
** \param flgs defined by 'FAPI_BOARD_DiagnosticInfoFlagsT'
** \param infoPtr most likely a string-pointer describing the activity
** \param optA optional parameter, usually not used
** \param optB optional parameter, usually not used
******************************************************************************
*/
#define FAPI_BOARD_DIAGNOSTIC_TS_PATH( flgs, infoPtr, optA, optB )              \
    if((FAPI_BOARD_Services.diagnosticHook_TsPath)                              \
    && (FAPI_BOARD_Services.dFl_TsPath.dBf.diagAllowBits&flgs))                 \
    {                                                                           \
        FAPI_BOARD_Services.diagnosticHook_TsPath                               \
        (FAPI_BOARD_Services.dFl_TsPath.allBF|flgs, infoPtr, optA, optB);       \
    }                                                                           \

/*!
******************************************************************************
** \brief interface for notification of 'HDMI-Path-diagnostic events'
** this 'hook-function' can be used to inform about HDMI-path control activities
**
** \param flgs defined by 'FAPI_BOARD_DiagnosticInfoFlagsT'
** \param infoPtr most likely a string-pointer describing the activity
** \param optA optional parameter, usually not used
** \param optB optional parameter, usually not used
******************************************************************************
*/
#define FAPI_BOARD_DIAGNOSTIC_HDMI_PATH( flgs, infoPtr, optA, optB )            \
    if ((FAPI_BOARD_Services.diagnosticHook_HdmiPath)                           \
    && (FAPI_BOARD_Services.dFl_HdmiPath.dBf.diagAllowBits&flgs))               \
    {                                                                           \
        FAPI_BOARD_Services.diagnosticHook_HdmiPath                             \
        (FAPI_BOARD_Services.dFl_HdmiPath.allBF|flgs, infoPtr, optA, optB);     \
    }                                                                           \

/*!
******************************************************************************
** \brief interface for notification of 'CI-HW-related controls'
** this 'hook-function' can be used to inform about CH-HW control activities
**
** \param flgs defined by 'FAPI_BOARD_DiagnosticInfoFlagsT'
** \param infoPtr most likely a string-pointer describing the activity
** \param optA optional parameter, usually not used
** \param optB optional parameter, usually not used
******************************************************************************
*/
#define FAPI_BOARD_DIAGNOSTIC_CI_CONTROL( flgs, infoPtr, optA, optB )           \
    if ((FAPI_BOARD_Services.diagnosticHook_CiHwAccess!=NULL)                   \
    &&  (FAPI_BOARD_Services.dFl_CiHwCtl.dBf.diagAllowBits&flgs))               \
    {                                                                           \
        FAPI_BOARD_Services.diagnosticHook_CiHwAccess                           \
        (FAPI_BOARD_Services.dFl_CiHwCtl.allBF|flgs, infoPtr, optA, optB);      \
    }                                                                           \


/*!
******************************************************************************
** \brief interface for notification for 'general purpose use'
** this 'hook-function' can be used to inform about 'user defined activities'
**
** \param flgs defined by 'FAPI_BOARD_DiagnosticInfoFlagsT'
** \param infoPtr most likely a string-pointer describing the activity
** \param optA optional parameter, usually not used
** \param optB optional parameter, usually not used
******************************************************************************
*/
#define FAPI_BOARD_DIAGNOSTIC_GENERALPURPOSE( flgs, infoPtr, optA, optB )       \
    if ((FAPI_BOARD_Services.diagnosticHook_GenPurpose)                         \
    &&  (FAPI_BOARD_Services.dFl_GenPurp.dBf.diagAllowBits&flgs))               \
    { FAPI_BOARD_Services.diagnosticHook_GenPurpose                             \
        (FAPI_BOARD_Services.dFl_GenPurp.allBF|flgs, infoPtr, optA, optB);      \
    }                                                                           \

//******************************************************************************
//******************************************************************************
//** Global data
//******************************************************************************
//******************************************************************************

/*!
********************************************************************************
** \brief The board service interface.
**
** This data structure represents the interface for board specific services
** which can be used to add optional board specific actions to the generic
** FAPI drivers.
**
** interface are:
** - special ATA reset controls
** - special FE reset controls
** - special SCART controls
** - special CI controls
**
** There is no default implementation assigned to all board specific hook
** functions, thery are all initialzed to '0'.
********************************************************************************
*/
typedef struct
{
    FAPI_BOARD_InitDetectHookT      controlHook_BrdInitDetect; //0 //!< hook for 'board driver' 'init-function'

    FAPI_BOARD_ControlLedHookT      controlHook_Led; //4            //!< hook for LED-control
    FAPI_BOARD_ControlFeHookT       controlHook_FeReset; //8        //!< hook for FE-reset
    FAPI_BOARD_ControlFeDetectHookT controlHook_FeDetect; //12      //!< hook for FE-reset
    FAPI_BOARD_ControlHdHookT       controlHook_HdReset; //16       //!< hook for HD-reset
    FAPI_BOARD_ControlScartHookT    controlHook_Scart; //20         //!< hook for SCART-control

    FAPI_BOARD_ControlTsPathHookT   controlHook_TsPath; //24        //!< hook for TS-path-control
    FAPI_BOARD_DiagnosticInfoHookT  diagnosticHook_TsPath; //28     //!< hook for TS-path diagnostic
    FAPI_BOARD_DiagnosticInfoFlagsT dFl_TsPath; //32                //!< bit-flags for 'TS-path diagnostic'

    FAPI_BOARD_ControlHdmiPathHookT controlHook_HdmiPath; //36      //!< hook for HDMI-path-control
    FAPI_BOARD_DiagnosticInfoHookT  diagnosticHook_HdmiPath; //40   //!< hook for HDMI-path diagnostic
    FAPI_BOARD_DiagnosticInfoFlagsT dFl_HdmiPath; //44              //!< bit-flags for 'HDMI-path diagnostic'

    FAPI_BOARD_DiagnosticInfoHookT  diagnosticHook_CiHwAccess; //48 //!< hook for CI-HW activity
    FAPI_BOARD_DiagnosticInfoFlagsT dFl_CiHwCtl; //52 //!< bit-flags for CI-HW activity diagnostic

    FAPI_BOARD_DiagnosticInfoHookT  diagnosticHook_GenPurpose; //56 //!< hook for general purpose diagnostic
    FAPI_BOARD_DiagnosticInfoFlagsT dFl_GenPurp; //60 //!< bit-flags for general purpose diagnostic
    //64
} FAPI_BOARD_ServicesT;


#define FAPI_BOARD_HWCONFIG_VERSION 0xFABE0003UL    //!< magic to validate 'FAPI_BOARD_HwPlatformInfosT'
#define FAPI_BOARD_MAX_TSINP_PATH   0x02            //!< max. supported (effective) TS-Input.Paths

/*!
******************************************************************************
** \brief bit-flags for ApplicationSW-Resource-Handling  FE- and CI-Input options
******************************************************************************
*/
#define FAPI_BOARD_RSRC_TSIN_NONE    0x00    //!< TS input: none.
#define FAPI_BOARD_RSRC_TSIN_FE1     0x01    //!< TS input: Frontend 1.
#define FAPI_BOARD_RSRC_TSIN_FE2     0x02    //!< TS input: Frontend 2.

#define FAPI_BOARD_RSRC_CIIN_NONE    0x00    //!< CI input: none.
#define FAPI_BOARD_RSRC_CIIN_FE1     0x01    //!< CI input: Frontend 1.
#define FAPI_BOARD_RSRC_CIIN_FE2     0x02    //!< CI input: Frontend 2.
#define FAPI_BOARD_RSRC_CIIN_TSGEN   0x04    //!< CI input: other TS (non-frontend).

#define FAPI_BOARD_BITFLAG_PFLASH    0x01    //!< P-Flash available on HW
#define FAPI_BOARD_BITFLAG_SFLASH    0x02    //!< S-Flash available on HW
#define FAPI_BOARD_BITFLAG_NFLASH    0x04    //!< N-Flash available on HW

typedef struct
{
    uint8_t   defaultFeType;        //!< see 'FE_SYSTEM_TYPE_SATELLITE' etc.
    uint8_t   tsPathInputConfig;    //!< TS input (one of FAPI_BOARD_RSRC_TSIN_XXX).
    uint8_t   flagCiPathAval;       //!< '0' or '1'
    uint8_t   inputOptionsCiPath;   //!< CI input options (or'ed
                                    //!< bitfield of FAPI_BOARD_RSRC_CIIN_XXX).
} FAPI_BOARD_FeConfigInfoT;

#define FAPI_BOARD_HD1_P_ATA 0x01   //!< 'P-ATA' HardDisk[1]-Interface availavle
#define FAPI_BOARD_HD2_P_ATA 0x02   //!< 'P-ATA' HardDisk[2]-Interface availavle
#define FAPI_BOARD_HD1_S_ATA 0x10   //!< 'S-ATA' HardDisk[1]-Interface availavle (via S-Ata-Adapter)
#define FAPI_BOARD_HD2_S_ATA 0x20   //!< 'S-ATA' HardDisk[2]-Interface availavle

/*!
*******************************************************************************
** \brief HW-platform/board 'Info-Structure'
******************************************************************************
*/
typedef struct
{
    uint32_t                 MagicAndVersion;        //!< #FAPI_BOARD_HWCONFIG_VERSION
    const char_t            *pHwManufactString;      //!< Manufacturer-Info
    const char_t            *pHwModelString;         //!< HW-Model Info
    const void              *pOptAdditionalInfo;     //!< e.g. can be used for spec. Test purpose
    uint8_t                  flagUsbHostOnly;        //!<
    uint8_t                  typeOfFlashAvailable;   //!< see 'FAPI_BOARD_BITFLAG_PFLASH' etc.
    uint8_t                  AudioConfigurationInfoA;//!< for future use
    uint8_t                  AudioConfigurationInfoB;//!< for future use
    uint8_t                  numberOfAvlFrontEnds;   //!< number of available frontends
    uint8_t                  numberOfAvlCiSlots;     //!< number of available CI-Slots
    FAPI_BOARD_FeConfigInfoT feCfg[FAPI_BOARD_MAX_TSINP_PATH];  //!< FE-CfgData
    uint8_t                  flagHardDiskInterface;  //!< see 'FAPI_BOARD_HD1_P_ATA' etc.
    uint8_t                  flgDdr2MemoryInfos ;    //!< not really used yet

} FAPI_BOARD_HwPlatformInfosT;

extern FAPI_BOARD_ServicesT FAPI_BOARD_Services;

//******************************************************************************
//******************************************************************************
//** Board specific callback hook register functions
//******************************************************************************
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

void FAPI_BOARD_SetBoardInitDetectHook    ( FAPI_BOARD_InitDetectHookT      hookPtr );
void FAPI_BOARD_SetControlTestLedKeyHook  ( FAPI_BOARD_ControlLedHookT      hookPtr );
void FAPI_BOARD_SetControlFeResetHook     ( FAPI_BOARD_ControlFeHookT       hookPtr );
void FAPI_BOARD_SetControlFeDetectHook    ( FAPI_BOARD_ControlFeDetectHookT hookPtr );
void FAPI_BOARD_SetControlHdResetHook     ( FAPI_BOARD_ControlHdHookT       hookPtr );
void FAPI_BOARD_SetControlScartHook       ( FAPI_BOARD_ControlScartHookT    hookPtr );

void FAPI_BOARD_SetControlTsPathHook      ( FAPI_BOARD_ControlTsPathHookT   hookPtr );

void FAPI_BOARD_SetDiagnostic_TsPath      ( FAPI_BOARD_DiagnosticInfoFlagsT diagIndexAndMasksTsPath,
                                            FAPI_BOARD_DiagnosticInfoHookT  hookPtr );

void FAPI_BOARD_SetDiagnostic_EnableBits_TsPath ( uint32_t diagSetTsInfoEnaBits);

void FAPI_BOARD_SetControlHdmiPathHook    ( FAPI_BOARD_ControlHdmiPathHookT hookPtr );

void FAPI_BOARD_SetDiagnostic_HdmiPath    ( FAPI_BOARD_DiagnosticInfoFlagsT diagIndexAndMasksHdmiPath,
                                            FAPI_BOARD_DiagnosticInfoHookT  hookPtr );

void FAPI_BOARD_SetDiagnostic_EnableBits_HdmiPath ( uint32_t diagSetHdmiInfoEnaBits);

void FAPI_BOARD_SetBoardInfo              ( FAPI_BOARD_HwPlatformInfosT *boardHwInfosPtr );
FAPI_BOARD_HwPlatformInfosT * FAPI_BOARD_GetBoardInfo ( void );

void   FAPI_BOARD_SetCiInterface          ( void *ciInterfacePtr );
void * FAPI_BOARD_GetCiInterface          ( void );

void   FAPI_BOARD_SetDiagnostic_CiInterface ( FAPI_BOARD_DiagnosticInfoFlagsT diagIndexAndMasksCiCntr,
                                              FAPI_BOARD_DiagnosticInfoHookT  hookPtr );

void FAPI_BOARD_SetDiagnostic_EnableBits_CiInterface ( uint32_t diagSetCiInfoEnaBit);

void FAPI_BOARD_SetDiagnostic_GeneralPurpose ( FAPI_BOARD_DiagnosticInfoFlagsT diagFlagsUser,
                                               FAPI_BOARD_DiagnosticInfoHookT  hookPtr );

void FAPI_BOARD_SetDiagnostic_EnableBits_GeneralPurpose ( uint32_t diagSetUserInfoEnaBit );

void   FAPI_BOARD_SetMemoryMapInfo     ( void *memMapInfoPtr );
void * FAPI_BOARD_GetMemoryMapInfo     ( void );

#ifdef __cplusplus
}
#endif

/*
********************************************************************************
** End of file
********************************************************************************
*/
#endif

