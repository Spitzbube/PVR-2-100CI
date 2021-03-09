/*!
*****************************************************************************
**
** \file        ./fapi/drv/tsd/src/drv_tsd.h
**
** \brief       TSD Driver.
**
** This file contains the declaration of the TSD driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_TSD_H
    #define FAPI_TSD_H

    #include <fapi/sys_driver.h>
    #ifndef FAPI_BM_H
        #include <fapi/drv_bm.h>
    #endif

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************

    #define FAPI_TSD0                    0    //!< TSD0 hardware block
    #define FAPI_TSD1                    1    //!< TSD1 hardware block
    #define FAPI_TSD2                    2    //!< TSD2 hardware block
    #define FAPI_TSD3                    3    //!< TSD3 hardware block

    #define FAPI_TS_A                    0    //!< TS A input channel
    #define FAPI_TS_B                    1    //!< TS B input channel
    #define FAPI_TS_C                    2    //!< TS C input channel
    #define FAPI_TS_OUTPUT               3    //!< TS  output channel
    #define FAPI_TS_DISABLE              9    //!< No TS input (feed via packet RAM)

    #define FAPI_TSD_MAX                 4    //!< Total of TSD HW blocks
    #define FAPI_TSD_CHANNEL_NUM         32   //!< Number of TSD channels
    #define FAPI_TSD_CHANNEL_AUTODETECT -1    //!< Selects the first free channel

    #define FAPI_TSD_IGNORE_BYTE        0x00000000 //!< Ignore provided section byte
    #define FAPI_TSD_FILTER_BYTE        0xFFFFFFFF //!< Filter exactly provided section byte
    #define FAPI_TSD_IGNORE_VERSION     0xFF000000 //!< Ignore the version when filtering
    #define FAPI_TSD_CHECK_VERSION      0x00FF0000 //!< Check the version when filtering

    #define FAPI_TSD_BSR_STACK_SIZE     2048  //!< Stack size of the BSR
    #define FAPI_TSD_BSR_FIFO_DEPTH      256  //!< FIFO depth (number of parallel BSRs)

    /*!
    ********************************************************************************
    ** Standard error codes for the driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_TSD_ERR_BAD_PARAMETER         (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_TSD_ERR_OUT_OF_MEMORY         (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_TSD_ERR_ALREADY_INITIALIZED   (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_TSD_ERR_NOT_INITIALIZED       (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define FAPI_TSD_ERR_FEATURE_NOT_SUPPORTED (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define FAPI_TSD_ERR_TIMEOUT               (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define FAPI_TSD_ERR_DEVICE_BUSY           (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define FAPI_TSD_ERR_INVALID_HANDLE        (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_TSD_ERR_SEMAPHORE_CREATE      (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define FAPI_TSD_ERR_UNSUPPORTED_VERSION   (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_UNSUPPORTED_VERSION)

    /*! The mailqueue could not be created. */
    #define FAPI_TSD_ERR_MAILQUEUE_CREATE      (FAPI_TSD_MODULE_BASE +\
                                                FAPI_ERR_MAILQUEUE_CREATE)

    /*!
    ********************************************************************************
    ** Additional driver error codes (reserved from -100 to -999)
    **
    ** Each error code shall be decreased in steps of 1.
    ********************************************************************************
    */

    /* TSD error base */
    #define FAPI_TSD_ERR_BASE                       (FAPI_TSD_MODULE_BASE - 100)
    /*! \brief The provided PID is invalid. */
    #define FAPI_TSD_ERR_INVALID_PID                (FAPI_TSD_ERR_BASE -  0)
    /*! \brief No PID is associated with the provided TSD handle. */
    #define FAPI_TSD_ERR_NO_PID_ASSIGNED            (FAPI_TSD_ERR_BASE -  1)
    /*! \brief All four PES parsers of a double block were already used. */
    #define FAPI_TSD_ERR_PES_PARSER_COUNT_EXEEDED   (FAPI_TSD_ERR_BASE -  2)
    /*! \brief TSD block has already been configured. */
    #define FAPI_TSD_ERR_NO_RECONFIGURE             (FAPI_TSD_ERR_BASE -  3)
    /*! \brief The number of targets specified is invalid. */
    #define FAPI_TSD_ERR_INVALID_FILTER_SETTINGS    (FAPI_TSD_ERR_BASE -  4)
    /*! \brief PID is already associated with (another) TSD handle. */
    #define FAPI_TSD_ERR_PID_ALREADY_ASSIGNED       (FAPI_TSD_ERR_BASE -  5)
    /*! \brief No buffer channel is mapped to a given TSD channel. */
    #define FAPI_TSD_ERR_NO_MAPPED_BUFFER           (FAPI_TSD_ERR_BASE -  6)
    /*! \brief A notifier has already been assigned. */
    #define FAPI_TSD_ERR_NOTIFIER_ALREADY_ASSIGNED  (FAPI_TSD_ERR_BASE -  7)
    /*! \brief GPIO could not be used */
    #define FAPI_TSD_ERR_GPIO_FAILED                (FAPI_TSD_ERR_BASE -  8)
    /*! \brief No section filter has been assigned to a given TSD channel */
    #define FAPI_TSD_ERR_NO_FILTER_ASSIGNED         (FAPI_TSD_ERR_BASE -  9)
    /*! \brief No PES parser has been assigned to a given TSD channel */
    #define FAPI_TSD_ERR_NO_PES_PARSER_ASSIGNED     (FAPI_TSD_ERR_BASE - 10)
    /*! \brief Synchronisation is disabled */
    #define FAPI_TSD_ERR_SYNC_DISABLED              (FAPI_TSD_ERR_BASE - 11)
    /*! \brief STC has been configured to a different TSD block */
    #define FAPI_TSD_ERR_STC_SELECT                 (FAPI_TSD_ERR_BASE - 12)
    /*! \brief PID is still active - the channel needs to be stopped */
    #define FAPI_TSD_ERR_PID_ACTIVE                 (FAPI_TSD_ERR_BASE - 13)
    /*! \brief An evaluator has already been assigned. */
    #define FAPI_TSD_ERR_EVALUATOR_ALREADY_ASSIGNED (FAPI_TSD_ERR_BASE - 14)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Version of the TSD driver.
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
    **       FAPI_TSD_OpenParamsT structure.
    **
    *************************************************************************
    */

    typedef enum {
        FAPI_TSD_VERSION = (int32_t)0x00040000   //!< The current driver version
    } FAPI_TSD_VersionEnumT;

    /*!
    *************************************************************************
    ** \brief Type definition of the section notify function.
    **
    ** This function prototype is used for the section filter callback functions.
    ** - handle refers to the TSD handle.
    ** - bufferAddress refers to the absolute buffer address where the section
    **   has been stored.
    **   (The first 4 bytes are refering to the target index. further
    **    information can be found in the device manual.)
    ** - bufferLength refers to the section length and possible stuffing bytes.
    ** - crcError determines whether a CRC error has been detected within current
    **   section or not. The read pointer should be moved nevertheless.
    ** - optDataPtr provides optional data for the callback.
    **
    ** \note This function runs in BSR context.
    *************************************************************************
    */
    typedef void (*FAPI_TSD_SectionNotifyT)(FAPI_SYS_HandleT handle, uint32_t bufferAddress,
                                            uint32_t bufferLength, uint32_t crcError,
                                            void* optDataPtr);

    /*!
    *************************************************************************
    ** \brief Type definition of the general notify function.
    **
    ** This function prototype is used for several notifier callback
    ** functions:
    ** - CRC notifier
    ** - Packet notifier
    ** - Scrambled notifier
    **
    ** \note This function runs in ISR context.
    *************************************************************************
    */
    typedef void (*FAPI_TSD_GeneralNotifyT)(FAPI_SYS_HandleT handle, void* optDataPtr);

    /*!
    *************************************************************************
    ** \brief Type definition of the PTS notify function.
    **
    ** This function prototype is used for the PTS IRQ callback functions.
    **
    ** \note This function runs in ISR context.
    *************************************************************************
    */
    typedef void (*FAPI_TSD_PtsNotifyT)(uint64_t pts, void* optDataPtr);

    /*!
    *************************************************************************
    ** \brief Type definition of the PTS evaluator function.
    **
    ** This function prototype is used for the PTS evaluation. It shall
    ** return true if the PTS shall be skipped and false if the PTS shall
    ** not be skipped.
    ** Depending on the result of this function a provided PTS notifier is
    ** called or not.
    ** To disable an evaluation, simply disable the evaluator calling
    ** FAPI_TSD_SetPtsEvaluator() with the enable flag set to 0.
    ** If no evaluator is specified, a default evaluator will be used
    **
    ** \note This function runs in ISR context.
    *************************************************************************
    */
    typedef uint32_t (*FAPI_TSD_PtsEvaluateT)(uint64_t pts, void* optDataPtr);

    /*!
    *************************************************************************
    ** \brief TSD parameters for the TSD block.
    **
    ** This data structure covers all parameters which need to be specified
    ** after initialization and before opening a driver instance.
    **
    *************************************************************************
    */
    typedef struct {
        /* \brief The version of the driver.
        **         \ref FAPI_TSD_VersionEnumT "FAPI_TSD_VERSION".
        */
        FAPI_TSD_VersionEnumT version;
        /* \brief Determines whether the packet end IRQ is enabled (1) or
        **        disabled (0).
        */
        uint32_t              enablePacketEndIrq;
    } FAPI_TSD_TsdSettingsT;

    /*!
    *************************************************************************
    ** \brief TS input parameters for the TSD driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** after initialization and before opening a driver instance.
    **
    *************************************************************************
    */
    typedef struct {
        /*! \brief The version of the driver.
        **         \ref FAPI_TSD_VersionEnumT "FAPI_TSD_VERSION".
        */
        FAPI_TSD_VersionEnumT version; //0
        /*! \brief TS block to receive input off. This value can either be
        **         #FAPI_TS_A, #FAPI_TS_B, #FAPI_TS_C or #FAPI_TS_DISABLE.
        */
        uint32_t              tsSelect; //4
        /*! \brief '0' synchronises on start signal or TS enable signal.
        **         '1' automatically searches for synchronisation bytes 0x47
        **         or 0xB8.
        */
        uint32_t              automaticSync         : 1;
        /*! \brief '0' for high active, '1' for low active. */
        uint32_t              packetStartPolarity   : 1;
        /*! \brief '0' for high active, '1' for low active. */
        uint32_t              enablePolarity        : 1;
        /*! \brief '0' for uninverted clock signal,
        **         '1' for inverted clock signal.
        */
        uint32_t              clockInvert           : 1;
        /*! \brief 'b01' serial with TS packet start signal,
        **         'b10' parallel without TS packet start signal,
        **         'b11' parallel with TS packet start signal.
        */
        uint32_t              serialParallelMode    : 2;
        /* \brief Should be set to 0 */
        uint32_t              sbz                   : 26;
        /* \brief Determines the distance between SYNC bytes (eg. 188 bytes or 204 bytes)
        **        If syncBytesDistance is set to a value other than 0 it is only
        **        evaluated in case automaticSync has been enabled and serialParallelMode
        **        is set to 2 (parallel without TSX_PACKET_START).
        **        Otherwise the default of 204 bytes is used.
        */
        uint32_t              syncByteDistance;
    } FAPI_TSD_TsInputSettingsT;

    /*!
    *************************************************************************
    ** \brief TS output parameters for the TSD driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** after initialization and before opening a driver instance.
    **
    *************************************************************************
    */
    typedef struct {
        /*! \brief The version of the driver.
        **         \ref FAPI_TSD_VersionEnumT "FAPI_TSD_VERSION".
        */
        FAPI_TSD_VersionEnumT version;
        /*! \brief '00' for normal mode,
        **         '01' for TSD0/TSD2 pass mode,
        **         '10' for TSD1/TSD3 pass mode.
        */
        uint32_t              tsOutMode             : 2;
        /*! \brief '0' for uninverted clock signal,
        **        '1' for inverted clock signal.
        */
        uint32_t              clockInvert           : 1;
        /*! \brief '0' does not generate synchronization signals.
        **         '1' generates synchronization signals.
        */
        uint32_t              generateSync          : 1;
        /*! \brief Prescaler (1 byte value) to generate the clock signal.
        **         (162 / prescaler) MHz; prescaler != 0
        */
        uint32_t              prescaler             : 8;
        /* \brief Should be set to 0 */
        uint32_t              sbz                   : 22;
    } FAPI_TSD_TsOutputSettingsT;

    /*!
    *************************************************************************
    ** \brief Open parameters for the TSD driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    *************************************************************************
    */
    typedef struct {
        FAPI_TSD_VersionEnumT version;    //!< The version of the driver. \ref FAPI_TSD_VersionEnumT "FAPI_TSD_VERSION".
        uint32_t              blockIndex; //!< TSD block to use (#FAPI_TSD0, #FAPI_TSD1, #FAPI_TSD2, #FAPI_TSD3)
        int32_t               channelId;  //!< TSD channel (-1, 0, ..., 31) -1 for #FAPI_TSD_CHANNEL_AUTODETECT.
    } FAPI_TSD_OpenParamsT;

    /*!
    *************************************************************************
    ** \brief Collection of sections that can be filtered by the TSD section
    **        filter. The PID value needs to be set to one of these.
    **
    ** This data structure covers all possible sections to be filtered by the
    ** TSD section filter using #FAPI_TSD_SetSectionFilter().
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_TSD_PAT_SECTION_PID     = (int32_t)0x0000, //!< Program association section
        FAPI_TSD_CAT_SECTION_PID     = (int32_t)0x0001, //!< Conditional access section
        FAPI_TSD_TSDT_SECTION_PID    = (int32_t)0x0002, //!< Transport stream description section
        FAPI_TSD_PMT_MIN_SECTION_PID = (int32_t)0x0010, //!< Transport stream program map section
        FAPI_TSD_PMT_MAX_SECTION_PID = (int32_t)0x1FFE, //!< Transport stream program map section
        FAPI_TSD_NIT_SECTION_PID     = (int32_t)0x0010, //!< Network information section
        FAPI_TSD_SDT_SECTION_PID     = (int32_t)0x0011, //!< Service description table
        FAPI_TSD_EIT_SECTION_PID     = (int32_t)0x0012, //!< Event information section
        FAPI_TSD_TDT_SECTION_PID     = (int32_t)0x0014, //!< Time and date section
        FAPI_TSD_BAT_SECTION_PID     = (int32_t)0x0011, //!< Bouquet association section
        FAPI_TSD_RST_SECTION_PID     = (int32_t)0x0013, //!< Running status section
        FAPI_TSD_TOT_SECTION_PID     = (int32_t)0x0014, //!< Time offset section
        FAPI_TSD_ST_MIN_SECTION_PID  = (int32_t)0x0010, //!< Stuffing section
        FAPI_TSD_ST_MAX_SECTION_PID  = (int32_t)0x0014, //!< Stuffing section
        FAPI_TSD_DIT_SECTION_PID     = (int32_t)0x0000, //!< Disconuity information section
        FAPI_TSD_SIT_SECTION_PID     = (int32_t)0x0000  //!< Selection information section
    } FAPI_TSD_SectionPidT;

    /*!
    *************************************************************************
    ** \brief Collection of tables that can be filtered by the TSD section
    **        filter.
    **
    ** This data structure covers all possible tables to be filtered by the
    ** TSD section filter using #FAPI_TSD_SetSectionFilter().
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_TSD_PAT_TABLE          = (int32_t)0x00, //!< Program association section
        FAPI_TSD_CAT_TABLE          = (int32_t)0x01, //!< Conditional access section
        FAPI_TSD_PMT_TABLE          = (int32_t)0x02, //!< Transport stream program map section
        FAPI_TSD_TSDT_TABLE         = (int32_t)0x03, //!< Transport stream description section
        FAPI_TSD_NIT_ATS_TABLE      = (int32_t)0x40, //!< Network information section (actual transport stream)
        FAPI_TSD_NIT_OTS_TABLE      = (int32_t)0x41, //!< Network information section (other transport stream)
        FAPI_TSD_SDT_ATS_TABLE      = (int32_t)0x42, //!< Service description table (actual transport stream)
        FAPI_TSD_SDT_OTS_TABLE      = (int32_t)0x46, //!< Service description table (other transport stream)
        FAPI_TSD_EIT_ATS_PF_TABLE   = (int32_t)0x4E, //!< Event information section (actual transport stream / present following)
        FAPI_TSD_EIT_OTS_PF_TABLE   = (int32_t)0x4F, //!< Event information section (other transport stream / present following)
        FAPI_TSD_BAT_TABLE          = (int32_t)0x4A, //!< Bouquet association section
        FAPI_TSD_TDT_TABLE          = (int32_t)0x70, //!< Time and date section
        FAPI_TSD_RST_TABLE          = (int32_t)0x71, //!< Running status section
        FAPI_TSD_ST_TABLE           = (int32_t)0x72, //!< Stuffing section
        FAPI_TSD_TOT_TABLE          = (int32_t)0x73, //!< Time offset section
        FAPI_TSD_DIT_TABLE          = (int32_t)0x7E, //!< Disconuity information section
        FAPI_TSD_SIT_TABLE          = (int32_t)0x7F, //!< Selection information section
        FAPI_TSD_USER_000_TABLE     = (int32_t)0x80, //!< User defined table 000
        FAPI_TSD_USER_001_TABLE     = (int32_t)0x81, //!< User defined table 001
        FAPI_TSD_USER_002_TABLE     = (int32_t)0x82, //!< User defined table 002
        FAPI_TSD_USER_003_TABLE     = (int32_t)0x83, //!< User defined table 003
        FAPI_TSD_USER_004_TABLE     = (int32_t)0x84, //!< User defined table 004
        FAPI_TSD_USER_005_TABLE     = (int32_t)0x85, //!< User defined table 005
        FAPI_TSD_USER_006_TABLE     = (int32_t)0x86, //!< User defined table 006
        FAPI_TSD_USER_007_TABLE     = (int32_t)0x87, //!< User defined table 007
        FAPI_TSD_USER_008_TABLE     = (int32_t)0x88, //!< User defined table 008
        FAPI_TSD_USER_009_TABLE     = (int32_t)0x89, //!< User defined table 009
        FAPI_TSD_USER_010_TABLE     = (int32_t)0x8A, //!< User defined table 010
        FAPI_TSD_USER_011_TABLE     = (int32_t)0x8B, //!< User defined table 011
        FAPI_TSD_USER_012_TABLE     = (int32_t)0x8C, //!< User defined table 012
        FAPI_TSD_USER_013_TABLE     = (int32_t)0x8D, //!< User defined table 013
        FAPI_TSD_USER_014_TABLE     = (int32_t)0x8E, //!< User defined table 014
        FAPI_TSD_USER_015_TABLE     = (int32_t)0x8F, //!< User defined table 015
        FAPI_TSD_USER_016_TABLE     = (int32_t)0x90, //!< User defined table 016
        FAPI_TSD_USER_017_TABLE     = (int32_t)0x91, //!< User defined table 017
        FAPI_TSD_USER_018_TABLE     = (int32_t)0x92, //!< User defined table 018
        FAPI_TSD_USER_019_TABLE     = (int32_t)0x93, //!< User defined table 019
        FAPI_TSD_USER_020_TABLE     = (int32_t)0x94, //!< User defined table 020
        FAPI_TSD_USER_021_TABLE     = (int32_t)0x95, //!< User defined table 021
        FAPI_TSD_USER_022_TABLE     = (int32_t)0x96, //!< User defined table 022
        FAPI_TSD_USER_023_TABLE     = (int32_t)0x97, //!< User defined table 023
        FAPI_TSD_USER_024_TABLE     = (int32_t)0x98, //!< User defined table 024
        FAPI_TSD_USER_025_TABLE     = (int32_t)0x99, //!< User defined table 025
        FAPI_TSD_USER_026_TABLE     = (int32_t)0x9A, //!< User defined table 026
        FAPI_TSD_USER_027_TABLE     = (int32_t)0x9B, //!< User defined table 027
        FAPI_TSD_USER_028_TABLE     = (int32_t)0x9C, //!< User defined table 028
        FAPI_TSD_USER_029_TABLE     = (int32_t)0x9D, //!< User defined table 029
        FAPI_TSD_USER_030_TABLE     = (int32_t)0x9E, //!< User defined table 030
        FAPI_TSD_USER_031_TABLE     = (int32_t)0x9F, //!< User defined table 031
        FAPI_TSD_USER_032_TABLE     = (int32_t)0xA0, //!< User defined table 032
        FAPI_TSD_USER_033_TABLE     = (int32_t)0xA1, //!< User defined table 033
        FAPI_TSD_USER_034_TABLE     = (int32_t)0xA2, //!< User defined table 034
        FAPI_TSD_USER_035_TABLE     = (int32_t)0xA3, //!< User defined table 035
        FAPI_TSD_USER_036_TABLE     = (int32_t)0xA4, //!< User defined table 036
        FAPI_TSD_USER_037_TABLE     = (int32_t)0xA5, //!< User defined table 037
        FAPI_TSD_USER_038_TABLE     = (int32_t)0xA6, //!< User defined table 038
        FAPI_TSD_USER_039_TABLE     = (int32_t)0xA7, //!< User defined table 039
        FAPI_TSD_USER_040_TABLE     = (int32_t)0xA8, //!< User defined table 040
        FAPI_TSD_USER_041_TABLE     = (int32_t)0xA9, //!< User defined table 041
        FAPI_TSD_USER_042_TABLE     = (int32_t)0xAA, //!< User defined table 042
        FAPI_TSD_USER_043_TABLE     = (int32_t)0xAB, //!< User defined table 043
        FAPI_TSD_USER_044_TABLE     = (int32_t)0xAC, //!< User defined table 044
        FAPI_TSD_USER_045_TABLE     = (int32_t)0xAD, //!< User defined table 045
        FAPI_TSD_USER_046_TABLE     = (int32_t)0xAE, //!< User defined table 046
        FAPI_TSD_USER_047_TABLE     = (int32_t)0xAF, //!< User defined table 047
        FAPI_TSD_USER_048_TABLE     = (int32_t)0xB0, //!< User defined table 048
        FAPI_TSD_USER_049_TABLE     = (int32_t)0xB1, //!< User defined table 049
        FAPI_TSD_USER_051_TABLE     = (int32_t)0xB2, //!< User defined table 051
        FAPI_TSD_USER_052_TABLE     = (int32_t)0xB3, //!< User defined table 052
        FAPI_TSD_USER_053_TABLE     = (int32_t)0xB4, //!< User defined table 053
        FAPI_TSD_USER_054_TABLE     = (int32_t)0xB5, //!< User defined table 054
        FAPI_TSD_USER_055_TABLE     = (int32_t)0xB6, //!< User defined table 055
        FAPI_TSD_USER_056_TABLE     = (int32_t)0xB7, //!< User defined table 056
        FAPI_TSD_USER_057_TABLE     = (int32_t)0xB8, //!< User defined table 057
        FAPI_TSD_USER_058_TABLE     = (int32_t)0xB9, //!< User defined table 058
        FAPI_TSD_USER_059_TABLE     = (int32_t)0xBA, //!< User defined table 059
        FAPI_TSD_USER_060_TABLE     = (int32_t)0xBB, //!< User defined table 060
        FAPI_TSD_USER_061_TABLE     = (int32_t)0xBC, //!< User defined table 061
        FAPI_TSD_USER_062_TABLE     = (int32_t)0xBD, //!< User defined table 062
        FAPI_TSD_USER_063_TABLE     = (int32_t)0xBE, //!< User defined table 063
        FAPI_TSD_USER_064_TABLE     = (int32_t)0xBF, //!< User defined table 064
        FAPI_TSD_USER_065_TABLE     = (int32_t)0xC0, //!< User defined table 065
        FAPI_TSD_USER_066_TABLE     = (int32_t)0xC1, //!< User defined table 066
        FAPI_TSD_USER_067_TABLE     = (int32_t)0xC2, //!< User defined table 067
        FAPI_TSD_USER_068_TABLE     = (int32_t)0xC3, //!< User defined table 068
        FAPI_TSD_USER_069_TABLE     = (int32_t)0xC4, //!< User defined table 069
        FAPI_TSD_USER_070_TABLE     = (int32_t)0xC5, //!< User defined table 070
        FAPI_TSD_USER_071_TABLE     = (int32_t)0xC6, //!< User defined table 071
        FAPI_TSD_USER_072_TABLE     = (int32_t)0xC7, //!< User defined table 072
        FAPI_TSD_USER_073_TABLE     = (int32_t)0xC8, //!< User defined table 073
        FAPI_TSD_USER_074_TABLE     = (int32_t)0xC9, //!< User defined table 074
        FAPI_TSD_USER_075_TABLE     = (int32_t)0xCA, //!< User defined table 075
        FAPI_TSD_USER_076_TABLE     = (int32_t)0xCB, //!< User defined table 076
        FAPI_TSD_USER_077_TABLE     = (int32_t)0xCC, //!< User defined table 077
        FAPI_TSD_USER_078_TABLE     = (int32_t)0xCD, //!< User defined table 078
        FAPI_TSD_USER_079_TABLE     = (int32_t)0xCE, //!< User defined table 079
        FAPI_TSD_USER_080_TABLE     = (int32_t)0xCF, //!< User defined table 080
        FAPI_TSD_USER_081_TABLE     = (int32_t)0xD0, //!< User defined table 081
        FAPI_TSD_USER_082_TABLE     = (int32_t)0xD1, //!< User defined table 082
        FAPI_TSD_USER_083_TABLE     = (int32_t)0xD2, //!< User defined table 083
        FAPI_TSD_USER_084_TABLE     = (int32_t)0xD3, //!< User defined table 084
        FAPI_TSD_USER_085_TABLE     = (int32_t)0xD4, //!< User defined table 085
        FAPI_TSD_USER_086_TABLE     = (int32_t)0xD5, //!< User defined table 086
        FAPI_TSD_USER_087_TABLE     = (int32_t)0xD6, //!< User defined table 087
        FAPI_TSD_USER_088_TABLE     = (int32_t)0xD7, //!< User defined table 088
        FAPI_TSD_USER_089_TABLE     = (int32_t)0xD8, //!< User defined table 089
        FAPI_TSD_USER_090_TABLE     = (int32_t)0xD9, //!< User defined table 090
        FAPI_TSD_USER_091_TABLE     = (int32_t)0xDA, //!< User defined table 091
        FAPI_TSD_USER_092_TABLE     = (int32_t)0xDB, //!< User defined table 092
        FAPI_TSD_USER_093_TABLE     = (int32_t)0xDC, //!< User defined table 093
        FAPI_TSD_USER_094_TABLE     = (int32_t)0xDD, //!< User defined table 094
        FAPI_TSD_USER_095_TABLE     = (int32_t)0xDE, //!< User defined table 095
        FAPI_TSD_USER_096_TABLE     = (int32_t)0xDF, //!< User defined table 096
        FAPI_TSD_USER_097_TABLE     = (int32_t)0xE0, //!< User defined table 097
        FAPI_TSD_USER_098_TABLE     = (int32_t)0xE1, //!< User defined table 098
        FAPI_TSD_USER_099_TABLE     = (int32_t)0xE2, //!< User defined table 099
        FAPI_TSD_USER_100_TABLE     = (int32_t)0xE3, //!< User defined table 100
        FAPI_TSD_USER_101_TABLE     = (int32_t)0xE4, //!< User defined table 101
        FAPI_TSD_USER_102_TABLE     = (int32_t)0xE5, //!< User defined table 102
        FAPI_TSD_USER_103_TABLE     = (int32_t)0xE6, //!< User defined table 103
        FAPI_TSD_USER_104_TABLE     = (int32_t)0xE7, //!< User defined table 104
        FAPI_TSD_USER_105_TABLE     = (int32_t)0xE8, //!< User defined table 105
        FAPI_TSD_USER_106_TABLE     = (int32_t)0xE9, //!< User defined table 106
        FAPI_TSD_USER_107_TABLE     = (int32_t)0xEA, //!< User defined table 107
        FAPI_TSD_USER_108_TABLE     = (int32_t)0xEB, //!< User defined table 108
        FAPI_TSD_USER_109_TABLE     = (int32_t)0xEC, //!< User defined table 109
        FAPI_TSD_USER_110_TABLE     = (int32_t)0xED, //!< User defined table 110
        FAPI_TSD_USER_111_TABLE     = (int32_t)0xEE, //!< User defined table 111
        FAPI_TSD_USER_112_TABLE     = (int32_t)0xEF, //!< User defined table 112
        FAPI_TSD_USER_113_TABLE     = (int32_t)0xF0, //!< User defined table 113
        FAPI_TSD_USER_114_TABLE     = (int32_t)0xF1, //!< User defined table 114
        FAPI_TSD_USER_115_TABLE     = (int32_t)0xF2, //!< User defined table 115
        FAPI_TSD_USER_116_TABLE     = (int32_t)0xF3, //!< User defined table 116
        FAPI_TSD_USER_117_TABLE     = (int32_t)0xF4, //!< User defined table 117
        FAPI_TSD_USER_118_TABLE     = (int32_t)0xF5, //!< User defined table 118
        FAPI_TSD_USER_119_TABLE     = (int32_t)0xF6, //!< User defined table 119
        FAPI_TSD_USER_120_TABLE     = (int32_t)0xF7, //!< User defined table 120
        FAPI_TSD_USER_121_TABLE     = (int32_t)0xF8, //!< User defined table 121
        FAPI_TSD_USER_122_TABLE     = (int32_t)0xF9, //!< User defined table 122
        FAPI_TSD_USER_123_TABLE     = (int32_t)0xFA, //!< User defined table 123
        FAPI_TSD_USER_124_TABLE     = (int32_t)0xFB, //!< User defined table 124
        FAPI_TSD_USER_125_TABLE     = (int32_t)0xFC, //!< User defined table 125
        FAPI_TSD_USER_126_TABLE     = (int32_t)0xFD, //!< User defined table 126
        FAPI_TSD_USER_127_TABLE     = (int32_t)0xFE  //!< User defined table 127

    } FAPI_TSD_TableIdT;

    /*!
    *************************************************************************
    ** \brief Number of tables to be filtered.
    **
    ** This data structure lists all possible numbers of tables to filter
    ** using #FAPI_TSD_SetSectionFilter().
    **
    *************************************************************************
    */
    typedef enum {
        FAPI_TSD_1_TABLE    = (int32_t)1,    //!< 1 Table ID shall be filtered
        FAPI_TSD_2_TABLES   = (int32_t)2,    //!< 2 Table IDs shall be filtered
        FAPI_TSD_4_TABLES   = (int32_t)4,    //!< 4 Table IDs shall be filtered
        FAPI_TSD_8_TABLES   = (int32_t)8,    //!< 8 Table IDs shall be filtered
        FAPI_TSD_12_TABLES  = (int32_t)12,   //!< 12 Table IDs shall be filtered
        FAPI_TSD_16_TABLES  = (int32_t)16,   //!< 16 Table IDs shall be filtered
        FAPI_TSD_20_TABLES  = (int32_t)20,   //!< 20 Table IDs shall be filtered
        FAPI_TSD_24_TABLES  = (int32_t)24,   //!< 24 Table IDs shall be filtered
        FAPI_TSD_28_TABLES  = (int32_t)28,   //!< 28 Table IDs shall be filtered
        FAPI_TSD_32_TABLES  = (int32_t)32    //!< 32 Table IDs shall be filtered
    } FAPI_TSD_NumberOfTablesT;

    /*!
    *************************************************************************
    ** \brief Filter data for the section filter.
    **
    ** This data structure contains a table ID and the according section
    ** bytes to be filtered. The length field describes how many section
    ** bytes are to be filtered using #FAPI_TSD_SetSectionFilter().
    **
    ** \note Section filter bytes that are supposed to be ignored by a filter
    **       can be set to FAPI_TSD_IGNORE_BYTE.
    *************************************************************************
    */
    typedef struct {
        /*! \brief Table ID to be filtered */
        FAPI_TSD_TableIdT       tableId; //0
        /* \brief Number of section bytes to be filtered (section length
        **        (16 bits) is not included)
        */
        uint32_t                numberOfSectionBytes; //4
        /*! \brief Section bytes to be filtered (section length (16 bits) is
        **        not included).
        */
        uint32_t*               sectionBytes; //8
        /*! \brief Filter bytes to mask section bytes (section length (16 bits) is
        **        not included). This array should contain numberOfSectionBytes + 1
        **        elements. The added element contains the filter for the table ID.
        **        (See also #FAPI_TSD_IGNORE_BYTE, #FAPI_TSD_FILTER_BYTE)
        **        In case this parameter is NULL, the target will be skipped.
        */
        uint32_t*               filterBytes; //12
        /*! \brief Enables a single filtering (one shot) if set to '1' and
        **        continuous filtering if set to '0'
        */
        uint32_t                oneShotFiltering; //16
        /*! \brief Notify function to be called in case a matching section was
        **        filtered.
        ** \note  This notifier will be called in BSR context.
        */
        FAPI_TSD_SectionNotifyT notifyFunction; //20
        /*! \brief Optional data which is passed to the notifier. */
        void*                   optData; //24
        /*! \brief The notify function will only be called in case of a new version.
        **        (#FAPI_TSD_CHECK_VERSION to enable or #FAPI_TSD_IGNORE_VERSION to disable)
        */
        uint32_t                notifyOnNewVersion; //28
        //32
    } FAPI_TSD_FilterDataT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************
    extern FAPI_SYS_DriverT FAPI_TSD_Driver0;
    extern FAPI_SYS_DriverT FAPI_TSD_Driver1;
    extern FAPI_SYS_DriverT FAPI_TSD_Driver2;
    extern FAPI_SYS_DriverT FAPI_TSD_Driver3;

    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif
    int32_t          FAPI_TSD_Init(void);
    void             FAPI_TSD_Exit(void);
    uint32_t         FAPI_TSD_Isr01(void);
    uint32_t         FAPI_TSD_Isr23(void);
    void             FAPI_TSD_Bsr(uint32_t privData);
    FAPI_SYS_HandleT FAPI_TSD_Open(const FAPI_TSD_OpenParamsT* paramsPtr,
                                   int32_t* errorCodePtr);
    int32_t          FAPI_TSD_Close(FAPI_SYS_HandleT handle);
    int32_t          FAPI_TSD_SetChannelPid(FAPI_SYS_HandleT handle,
                                            const uint32_t pid,
                                            const uint32_t enableContinuityCheck,
                                            const uint32_t removeTsHeader);
    int32_t          FAPI_TSD_GetChannelPid(FAPI_SYS_HandleT handle);
    int32_t          FAPI_TSD_StartChannel(FAPI_SYS_HandleT handle);
    int32_t          FAPI_TSD_StopChannel(FAPI_SYS_HandleT handle);
    int32_t          FAPI_TSD_SetPesParser(FAPI_SYS_HandleT handle,
                                           uint32_t removeHeader,
                                           uint32_t enableNewPtsIrq,
                                           uint32_t enablePesParser);
    int32_t          FAPI_TSD_Configure(const uint32_t blockIndex, const uint32_t useStc,
                                        const FAPI_TSD_TsInputSettingsT* tsInputSettingsPtr,
                                        const FAPI_TSD_TsOutputSettingsT* tsOutputSettingsPtr);
    int32_t          FAPI_TSD_SetBuffer(FAPI_SYS_HandleT handle,
                                        const FAPI_BM_InfoT bufferInfo);
    int32_t          FAPI_TSD_GetBuffer(FAPI_SYS_HandleT handle,
                                        FAPI_BM_InfoT* bufferInfoPtr);
    int32_t          FAPI_TSD_SetSectionFilter(const FAPI_SYS_HandleT handle,
                                               const FAPI_TSD_NumberOfTablesT numberOfTables,
                                               const FAPI_TSD_FilterDataT* filterDataPtr);
    int32_t          FAPI_TSD_GetSectionFilter(const FAPI_SYS_HandleT handle,
                                               FAPI_TSD_NumberOfTablesT* numberOfTablesPtr,
                                               FAPI_TSD_FilterDataT* filterDataPtr);
    int32_t          FAPI_TSD_ClearSectionFilter(const FAPI_SYS_HandleT handle);
    int32_t          FAPI_TSD_SetSectionFilterMode(const FAPI_SYS_HandleT handle,
                                                   const uint32_t targetIndex,
                                                   const uint32_t oneShotFiltering);
    int32_t          FAPI_TSD_GetSectionFilterMode(const FAPI_SYS_HandleT handle,
                                                   const uint32_t targetIndex);
    int32_t          FAPI_TSD_SetPacketEndNotifier(const FAPI_SYS_HandleT handle,
                                                   FAPI_TSD_GeneralNotifyT notifier,
                                                   void* optDataPtr,
                                                   const uint32_t enableNotifier);
    int32_t          FAPI_TSD_SetScrambledPacketNotifier(const FAPI_SYS_HandleT handle,
                                                         FAPI_TSD_GeneralNotifyT notifier,
                                                         void* optDataPtr,
                                                         const uint32_t enableNotifier,
                                                         const uint32_t enableOneShot);
    int32_t          FAPI_TSD_SetPacketTimeoutNotifier(const FAPI_SYS_HandleT handle,
                                                       FAPI_TSD_GeneralNotifyT notifier,
                                                       void* optDataPtr,
                                                       const uint32_t enableNotifier,
                                                       const uint32_t timeout);
    int32_t          FAPI_TSD_SetPtsNotifier(const FAPI_SYS_HandleT handle,
                                             FAPI_TSD_PtsNotifyT notifier,
                                             void* optDataPtr,
                                             const uint32_t enableNotifier);
    int32_t          FAPI_TSD_SetPtsEvaluator(const FAPI_SYS_HandleT handle,
                                              FAPI_TSD_PtsEvaluateT evaluator,
                                              void* optDataPtr,
                                              const uint32_t enableEvaluator);
    uint32_t         FAPI_TSD_GetPacketControlAddress(uint32_t blockIndex);
    uint32_t         FAPI_TSD_GetPacketRegisterAddress(uint32_t blockIndex, uint32_t index);
    uint32_t         FAPI_TSD_GetLinearPacketRegisterAddress(uint32_t blockIndex, uint32_t index);
    uint32_t         FAPI_TSD_GetLinearPacketAutoRegisterAddress(uint32_t blockIndex, uint32_t index);
    int32_t          FAPI_TSD_SetFreeChannelPid(FAPI_SYS_HandleT handle,
                                                const uint32_t pid,
                                                const uint32_t enableContinuityCheck,
                                                const uint32_t removeTsHeader);
    int32_t          FAPI_TSD_ClearChannelPid(FAPI_SYS_HandleT handle);
    int32_t          FAPI_TSD_GetChannelId(FAPI_SYS_HandleT handle);

    #ifdef __cplusplus
    }
    #endif
#endif
