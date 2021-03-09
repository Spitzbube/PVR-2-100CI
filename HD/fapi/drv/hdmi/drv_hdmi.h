/*!
*****************************************************************************
**
** \file        ./fapi/drv/hdmi/src/drv_hdmi.h
**
** \brief       HDMI Driver.
**
** This file contains the declaration of the HDMI driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_HDMI_H
    #define FAPI_HDMI_H

    #include <fapi/sys_driver.h>

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************
    #define FAPI_HDMI_VIDEO                   1          //!< Video hardware block
    #define FAPI_HDMI_AUDIO                   2          //!< Audio hardware block
    #define FAPI_HDMI_HDCP                    4          //!< HDCP hardware block
    #define FAPI_HDMI_ALL                     7          //!< ALL hardware block

    #define FAPI_HDMI_RGB                     0          //!< RGB
    #define FAPI_HDMI_YUV422                  1          //!< YUV422
    #define FAPI_HDMI_YUV444                  2          //!< YUV444

    #define FAPI_HDMI_SCAN_NO_DATA            0          //!< No data
    #define FAPI_HDMI_OVERSCAN                1          //!< overscanned display
    #define FAPI_HDMI_UNDERSCAN               2          //!< underscanned display

    #define FAPI_HDMI_SPDIF                   0x02       //!< SPDIF
    #define FAPI_HDMI_I2S0                    0x10       //!< I2S Channel0
    #define FAPI_HDMI_I2S1                    0x20       //!< I2S Channel1
    #define FAPI_HDMI_I2S2                    0x40       //!< I2S Channel2
    #define FAPI_HDMI_I2S3                    0x80       //!< I2S Channel3

    #define FAPI_HDMI_CLK_256_FS              1          //!< Audio clock is 256*fs
    #define FAPI_HDMI_CLK_384_FS              2          //!< Audio clock is 384*fs

    #define FAPI_HDMI_32000Hz                 1          //!< Sample Rate 32kHz
    #define FAPI_HDMI_44100Hz                 2          //!< Sample Rate 44.1kHz
    #define FAPI_HDMI_48000Hz                 3          //!< Sample Rate 48kHz
    #define FAPI_HDMI_96000Hz                 5          //!< Sample Rate 96kHz

    #define HDMI_AUDIO_SRC_DISABLE            0          //!< disable Audio Source
    #define HDMI_AUDIO_SRC_HALF               1          //!< Audio Source 1/2
    #define HDMI_AUDIO_SRC_QUATER             3          //!< Audio Source 1/4

    /* Audio InfoFrame coding type */
    #define FAPI_HDMI_AUDIO_REFER_TO_STREAM   0          //!< Refer to Stream Header
    #define FAPI_HDMI_AUDIO_PCM               1          //!< IEC 60958-3
    #define FAPI_HDMI_AUDIO_AC3               2          //!< ATSC A/52B
    #define FAPI_HDMI_AUDIO_MPEG1             3          //!< ISO/IEC 11172-3 Layer1 ot Layer2
    #define FAPI_HDMI_AUDIO_MP3               4          //!< ISO/IEC 11172-3 Layer3
    #define FAPI_HDMI_AUDIO_MPEG2             5          //!< ISO/IEC 13818-3
    #define FAPI_HDMI_AUDIO_AAC               6          //!< ISO/IEC 14496-3
    #define FAPI_HDMI_AUDIO_DTS               7          //!< ETSI TS 102 114
    #define FAPI_HDMI_AUDIO_ATRAC             8          //!< IEC 61909

    /* speaker assignment */
    #define FAPI_HDMI_SPEAKER_UNDEF           0x00       //!< undefine
    #define FAPI_HDMI_SPEAKER_FL              0x01       //!< Front Left
    #define FAPI_HDMI_SPEAKER_FR              0x02       //!< Front Right
    #define FAPI_HDMI_SPEAKER_LFE             0x03       //!< Low Frequency Effect
    #define FAPI_HDMI_SPEAKER_FC              0x04       //!< Front Center
    #define FAPI_HDMI_SPEAKER_RL              0x05       //!< Rear Left
    #define FAPI_HDMI_SPEAKER_RR              0x06       //!< Rear right
    #define FAPI_HDMI_SPEAKER_RC              0x07       //!< Rear Center
    #define FAPI_HDMI_SPEAKER_FLC             0x08       //!< Front Left Center
    #define FAPI_HDMI_SPEAKER_FRC             0x09       //!< Front Right Center
    #define FAPI_HDMI_SPEAKER_RLC             0x0a       //!< Rear Left Center
    #define FAPI_HDMI_SPEAKER_RRC             0x0b       //!< Rear Right Center

    /* Hot Plug Detect status */
    #define FAPI_HDMI_STATUS_HPD              2          //!< HPD status bit
    #define FAPI_HDMI_STATUS_RSEN             4          //!< RSEN status bit


    /*!
    ********************************************************************************
    ** Standard error codes for the driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_HDMI_ERR_BAD_PARAMETER         (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_HDMI_ERR_OUT_OF_MEMORY         (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_HDMI_ERR_ALREADY_INITIALIZED   (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_HDMI_ERR_NOT_INITIALIZED       (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FAPI_HDMI_ERR_FEATURE_NOT_SUPPORTED (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FAPI_HDMI_ERR_TIMEOUT               (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FAPI_HDMI_ERR_DEVICE_BUSY           (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FAPI_HDMI_ERR_INVALID_HANDLE        (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_HDMI_ERR_SEMAPHORE_CREATE      (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FAPI_HDMI_ERR_UNSUPPORTED_VERSION   (FAPI_HDMI_MODULE_BASE +\
                                                 FAPI_ERR_UNSUPPORTED_VERSION)

    /*!
    ********************************************************************************
    ** Additional driver error codes (reserved from -100 to -999)
    **
    ** Each error code shall be decreased in steps of 1.
    ********************************************************************************
    */

    /* \brief HDMI error base */
    #define FAPI_HDMI_ERR_BASE                 (FAPI_HDMI_MODULE_BASE - 100)
    /*! \brief HDMI open parameters error */
    #define FAPI_HDMI_ERR_OPEN_PARAM           (FAPI_HDMI_ERR_BASE -  0)
    /*! \brief HDMI parameters error */
    #define FAPI_HDMI_ERR_PARAMETER            (FAPI_HDMI_ERR_BASE -  1)
    /*! \brief HDMI I2C open error */
    #define FAPI_HDMI_ERR_I2C_OPEN             (FAPI_HDMI_ERR_BASE - 10)
    /*! \brief HDMI EDID read error */
    #define FAPI_HDMI_ERR_EDID                 (FAPI_HDMI_ERR_BASE - 20)
    /*! \brief HDMI DDC timeout error */
    #define FAPI_HDMI_ERR_DDC_TIMEOUT          (FAPI_HDMI_ERR_BASE - 21)
    /*! \brief HDMI HDCP timeout occured */
    #define FAPI_HDMI_ERR_HDCP_TIMEOUT         (FAPI_HDMI_ERR_BASE - 30)
    /*! \brief HDMI HDCP exceed device count */
    #define FAPI_HDMI_ERR_HDCP_MAX_DEVS_EXCEED (FAPI_HDMI_ERR_BASE - 31)
    /*! \brief HDMI HDCP cascade exceeded */
    #define FAPI_HDMI_ERR_HDCP_MAX_CASCADE_EXCEEDED (FAPI_HDMI_ERR_BASE - 32)
    /*! \brief HDMI HDCP SHA-1 mismatch */
    #define FAPI_HDMI_ERR_HDCP_SHA_1_MISMATCH  (FAPI_HDMI_ERR_BASE - 33)
    /*! \brief HDMI HDCP AN DDC Error */
    #define FAPI_HDMI_ERR_HDCP_AN_DDC          (FAPI_HDMI_ERR_BASE - 34)
    /*! \brief HDMI HDCP AKSV DDC Error */
    #define FAPI_HDMI_ERR_HDCP_AKSV_DDC        (FAPI_HDMI_ERR_BASE - 35)
    /*! \brief HDMI HDCP BKSV Error */
    #define FAPI_HDMI_ERR_HDCP_BKSV            (FAPI_HDMI_ERR_BASE - 36)
    /*! \brief HDMI HDCP RI failure */
    #define FAPI_HDMI_ERR_HDCP_RI_FAILURE      (FAPI_HDMI_ERR_BASE - 37)
    /*! \brief HDMI HDCP RI failure */
    #define FAPI_HDMI_ERR_HDCP_RI_NOT_ABAILABLE (FAPI_HDMI_ERR_BASE - 38)
    /*! \brief HDMI HPD not detect */
    #define FAPI_HDMI_ERR_HPD_NOT_DETECT       (FAPI_HDMI_ERR_BASE - 40)
    /*! \brief HDMI HDCP BKSV exist in Revocation Lists */
    #define FAPI_HDMI_ERR_EXIST_IN_REVOCATION_LISTS     (FAPI_HDMI_ERR_BASE - 41)
    /*! |brief HDCP feature is not available. */
    #define FAPI_HDMI_ERR_HDCP_NOT_SUPPORT     (FAPI_HDMI_ERR_BASE - 42)
    /*! \brief HDMI HDCP AKSV Error */
    #define FAPI_HDMI_ERR_HDCP_AKSV            (FAPI_HDMI_ERR_BASE - 43)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************
    /*!
    *************************************************************************
    ** \brief Version of the HDMI driver.
    **
    ** This number consists of a \b major version number stored in bits
    ** 16 to 31 (upper word) and a \b minor version number stored in bits
    ** 0 to 15 (lower word).
    ** - The \b major number has to be increased when a parameter change
    **   occurs for the existing driver's API after its first release.
    ** - The \b minor number has to be increased when functions are added to
    **   the existing driver's API after its first release.
    **
    ** \note This value has to be assigend to the \b version field of the
    **       FAPI_HDMI_OpenParamsT structure.
    **
    *************************************************************************
    */

    typedef enum {
        FAPI_HDMI_VERSION = 0x00010001   //!< The current driver version
    } FAPI_HDMI_VersionEnumT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the HDMI driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    *************************************************************************
    */

    typedef struct {
        /*!
           The version of the driver.
           \ref FAPI_HDMI_VersionEnumT "FAPI_HDMI_VERSION".
        */
        FAPI_HDMI_VersionEnumT version;

        /*!
            One of the possible block views.
            - #FAPI_HDMI_VIDEO
            - #FAPI_HDMI_AUDIO
            ....
        */
        uint32_t               block;

        /*!
           The HDMI I2C (I2C2) driver handle for the controled hdmi Tx.
        */

    } FAPI_HDMI_OpenParamsT;

    /*!
    *************************************************************************
    ** \brief Set/Get Video parameters for the HDMI driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an information on the video is set and get.
    **
    ** Not all combinations of inputType and outputType are permissible,
    ** the combinations NOT supported are:
    **    inputType=FAPI_HDMI_YUV444, outputType=FAPI_HDMI_YUV422
    **    inputType=FAPI_HDMI_RGB,    outputType=FAPI_HDMI_YUV444
    **    inputType=FAPI_HDMI_RGB,    outputType=FAPI_HDMI_YUV422
    **
    ** \sa    FAPI_HDMI_SetVideoParameters()
    ** \sa    FAPI_HDMI_GetVideoParameters()
    **
    *************************************************************************
    */
    typedef struct {
        uint32_t            inputType;    //!< Input type #FAPI_HDMI_RGB, #FAPI_HDMI_YUV422, #FAPI_HDMI_YUV444
        uint32_t            outputType;   //!< Output type #FAPI_HDMI_RGB, #FAPI_HDMI_YUV422, #FAPI_HDMI_YUV444
        uint32_t            videoCode;    //!< Video code
        /*!
            Scan information
            - #FAPI_HDMI_SCAN_NO_DATA
            - #FAPI_HDMI_OVERSCAN
            - #FAPI_HDMI_UNDERSCAN
        */
        uint32_t            scanInfo;     //!< Scan information
        /*!
            Active Format Discription
        refer to CEA-861B table9 AVI InfoFrame Data Byte2
        refer to ETSI TS 101 154 V1.8.1 Table B-5
        */
        uint32_t            activeFormat; //!< Active format
    } FAPI_HDMI_VideoParamsT;

    /*!
    *************************************************************************
    ** \brief Set/Get Audio parameters for the HDMI driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an information on the audio is set and get.
    **
    ** \sa    FAPI_HDMI_SetAudioParameters()
    ** \sa    FAPI_HDMI_GetAudioParameters()
    **
    *************************************************************************
    */
    typedef struct {
        uint16_t left; //!< The speaker assigned to the left channel of the I2S interface.
        uint16_t right; //!< The speaker assigned to the right channel of the I2S interface.
    } FAPI_HDMI_SpeakerAssignmentT;

    /*!
    *************************************************************************
    ** \brief Set/Get Audio parameters for the HDMI driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an information on the audio is set and get.
    **
    ** \sa    FAPI_HDMI_SetAudioParameters()
    ** \sa    FAPI_HDMI_GetAudioParameters()
    **
    *************************************************************************
    */
    typedef struct {
        uint32_t            mode;         //!< Audio Mode #FAPI_HDMI_I2S1+FAPI_HDMI_I2Sx, #FAPI_HDMI_SPDIF
        uint32_t            audioClock;   //!< Audio clock #FAPI_HDMI_CLK_256_FS, #FAPI_HDMI_CLK_384_FS
        uint32_t            polarity;     //!< 0: left channel is sent when lrclk is low, 1: left channel is sent when lrclk is high.
        uint32_t            format;       //!< Audio data format format1,2,3 (only for I2S)
        uint32_t            source;       //!< Audio source #HDMI_AUDIO_SRC_DISABLE, #HDMI_AUDIO_SRC_HALF, #HDMI_AUDIO_SRC_QUATER
        /*!
            Audio InfoFrame coding type
            - #FAPI_HDMI_AUDIO_REFER_TO_STREAM
            - #FAPI_HDMI_AUDIO_PCM
            - #FAPI_HDMI_AUDIO_AC3
            - #FAPI_HDMI_AUDIO_MPEG1
            - #FAPI_HDMI_AUDIO_MP3
            - #FAPI_HDMI_AUDIO_MPEG2
            - #FAPI_HDMI_AUDIO_AAC
            - #FAPI_HDMI_AUDIO_DTS
            - #FAPI_HDMI_AUDIO_ATRAC
        */
        uint32_t            codingType;   //!< Audio coding type
        uint32_t            levelShiftValue; //!< Audio level shift value. refer to CEA-861B table23 Audio InfoFrame Data Byte5
        uint32_t            downMixFlag;     //!< Audio down-mix inhibit flag. refer to CEA-861B table24 Audio InfoFrame Data Byte5
        /*!
            Audio Speaker assignment
            - #FAPI_HDMI_SPEAKER_UNDEF
            - #FAPI_HDMI_SPEAKER_FL
            - #FAPI_HDMI_SPEAKER_FR
            - #FAPI_HDMI_SPEAKER_LFE
            - #FAPI_HDMI_SPEAKER_FC
            - #FAPI_HDMI_SPEAKER_RL
            - #FAPI_HDMI_SPEAKER_RR
            - #FAPI_HDMI_SPEAKER_RC
            - #FAPI_HDMI_SPEAKER_FLC
            - #FAPI_HDMI_SPEAKER_FRC
            - #FAPI_HDMI_SPEAKER_RLC
            - #FAPI_HDMI_SPEAKER_RRC
        */
        FAPI_HDMI_SpeakerAssignmentT speakerMapping[4];
    } FAPI_HDMI_AudioParamsT;

    /*!
    *************************************************************************
    ** \brief Set/Get Audio parameters for the HDMI driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an information on the edid is get.
    **
    ** \sa    FAPI_HDMI_GetEDID_Info()
    **
    *************************************************************************
    */
    typedef struct {
        uint32_t            supportData;  //!< support data refer to CEA861-B Table28 Byte3
        uint32_t            videoCode1;   //!< bitmap of video short descriptor data refer to CEA861-B Table37
        uint32_t            videoCode2;   //!< bitmap of video short descriptor data
        uint32_t            videoCode3;   //!< bitmap of video short descriptor data
        uint32_t            videoCode4;   //!< bitmap of video short descriptor data
        uint32_t            audioData;    //!< audio short descriptor data refer to CEA861-B Table33,34
        uint32_t            speakerData;  //!< speaker allocation data block refer to CEA861-B Table36
        uint32_t            vsdbData6;    //!< extension data VSDB Byte6
        uint32_t            videoLatency; //!< video latency VSDB Byte 9
        uint32_t            audioLatency; //!< audio latency VSDB byte 10
        uint32_t            interlacedVideoLatency;    //!< interlaced video VSDB Byte11
        uint32_t            interlacedAudioLatency;    //!< interlaced audio VSDB Byte12
    } FAPI_HDMI_EdidInfoT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************
    extern FAPI_SYS_DriverT FAPI_HDMI_Driver;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    int32_t          FAPI_HDMI_Init(void);
    void             FAPI_HDMI_Exit(void);
    FAPI_SYS_HandleT FAPI_HDMI_Open(const FAPI_HDMI_OpenParamsT* pParams,
                                    int32_t* errorCodePtr);
    int32_t          FAPI_HDMI_Close(FAPI_SYS_HandleT handle);

    int32_t          FAPI_HDMI_GetPhysicalAddressInEDID(FAPI_SYS_HandleT handle, uint32_t* physAddrPtr);
    int32_t          FAPI_HDMI_ReadEDID(FAPI_SYS_HandleT handle);
    int32_t          FAPI_HDMI_LinkHDCP(FAPI_SYS_HandleT handle);

    int32_t          FAPI_HDMI_VIDEO_Start( FAPI_SYS_HandleT handle );
    int32_t          FAPI_HDMI_AUDIO_Start( FAPI_SYS_HandleT handle );
    void             FAPI_HDMI_VIDEO_Stop( FAPI_SYS_HandleT handle );
    void             FAPI_HDMI_AUDIO_Stop( FAPI_SYS_HandleT handle );
    int32_t          FAPI_HDMI_SetVideoParameters(FAPI_SYS_HandleT handle,
                                                  FAPI_HDMI_VideoParamsT* pVParams);
    int32_t          FAPI_HDMI_GetVideoParameters(FAPI_SYS_HandleT handle,
                                                  FAPI_HDMI_VideoParamsT* pVParams);

    int32_t          FAPI_HDMI_SetAudioParameters(FAPI_SYS_HandleT handle,
                                                  FAPI_HDMI_AudioParamsT* pAParams);
    int32_t          FAPI_HDMI_GetAudioParameters(FAPI_SYS_HandleT handle,
                                                  FAPI_HDMI_AudioParamsT* pAParams);
    int32_t          FAPI_HDMI_SetAudioSampleFrequency(FAPI_SYS_HandleT handle,
                                                       uint32_t sampleFreq);

    int32_t          FAPI_HDMI_CheckHPD(FAPI_SYS_HandleT handle );

    int32_t          FAPI_HDMI_CheckHDCPState(FAPI_SYS_HandleT handle );

    int32_t          FAPI_HDMI_GetEDID_Info(FAPI_SYS_HandleT handle,
                                            FAPI_HDMI_EdidInfoT* pEdidInfo);
    int32_t          FAPI_HDMI_SetRevocationList(FAPI_SYS_HandleT handle,
                                                  uint8_t* deviceKsv,
                                                  uint32_t numDevices);
    int32_t          FAPI_HDMI_UpdateAviInfoFrame(FAPI_SYS_HandleT handle );


    #ifdef __cplusplus
    }
    #endif
#endif
