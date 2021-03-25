/******************************************************************************
**
** \file      ./subsystems/fs/flashfs/src/flashfs.h
**
** \brief     A simfple file system for accessing files on flash
**           (serial/parallel) drive.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
******************************************************************************/

#ifndef  _FLASHFS_H_
#define  _FLASHFS_H_

#include <stdio.h>
#if 0
#include "fapex/abst_types.h"
#endif

/*!
********************************************************************************
** Standard error codes for the driver
********************************************************************************
*/

/*! Bad parameter passed. */
#define FLASHFS_ERR_BAD_PARAMETER \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_BAD_PARAMETER)

/*! Memory allocation failed. */
#define FLASHFS_ERR_OUT_OF_MEMORY \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY)

/*! Device already initialised. */
#define FLASHFS_ERR_ALREADY_INITIALIZED \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_ALREADY_INITIALIZED)

/*! Device not initialised. */
#define FLASHFS_ERR_NOT_INITIALIZED \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED)

/*! Feature or function is not available. */
#define FLASHFS_ERR_FEATURE_NOT_SUPPORTED \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED)

/*! Timeout occured. */
#define FLASHFS_ERR_TIMEOUT \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_TIMEOUT)

/*! The device is busy, try again later. */
#define FLASHFS_ERR_DEVICE_BUSY \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_DEVICE_BUSY)

/*! Invalid handle was passed. */
#define FLASHFS_ERR_INVALID_HANDLE \
       (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_INVALID_HANDLE)

/*! Semaphore could not be created. */
#define FLASHFS_ERR_SEMAPHORE_CREATE \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE)

/*! The driver's used version is not supported. */
#define FLASHFS_ERR_UNSUPPORTED_VERSION \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_UNSUPPORTED_VERSION)

/*! The mailqueue could not be created. */
#define FLASHFS_ERR_MAILQUEUE_CREATE \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_MAILQUEUE_CREATE)

/*! Device/handle is not open. */
#define FLASHFS_ERR_NOT_OPEN \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_NOT_OPEN)

/*! Device/handle is already open. */
#define FLASHFS_ERR_ALREADY_OPEN \
        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE+FAPI_ERR_ALREADY_OPEN)

/*!
********************************************************************************
** Additional driver error codes (reserved from -100 to -999)
**
** Each error code shall be decreased in steps of 1.
********************************************************************************
*/

/*! Given device is not supported, only serial or parallel flash device is recognized. */
#define FLASHFS_ERR_INVALID_DEVICE      (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-100)
/*! Poor file allocation resulting, overlapping */
#define FLASHFS_ERR_INVALID_ALLOCATION  (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-101)
/*! Duplicated file ID found in allocation table */
#define FLASHFS_ERR_DUPLICATED_ID       (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-102)
/*! Failure to open a non-existant file */
#define FLASHFS_ERR_FILE_NOT_EXIST      (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-103)
/*! Checksum verification failed at file open */
#define FLASHFS_ERR_CHECKSUM            (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-104)
/*! Reading pointer reaching end of file */
#define FLASHFS_ERR_END_OF_FILE         (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-105)
/*! File operation prohibited by open mode */
#define FLASHFS_ERR_PROHIBITED          (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-106)
/*! This File is not a valid file */
#define FLASHFS_ERR_INVALID_FILE        (int32_t)(SUBSYS_FS_FLASHFS_MODULE_BASE-107)

//**************************************************************************
//**************************************************************************
//** Defines and Macros
//**************************************************************************
//**************************************************************************

#define FLASHFS_FILE_MAX_NUM        32
#define FLASHFS_FILE_NAME_MAX_LEN   64

#define FLASHFS_OPEN_READ           "r" //!< Open file for reading.
#define FLASHFS_OPEN_WRITE          "w" //!< Open file for writing,
                                        //!< truncate to zero if existing.
#define FLASHFS_OPEN_APPEND         "a" //!< Open file for append writing.

//**************************************************************************
//**************************************************************************
//** Data types
//**************************************************************************
//**************************************************************************

#define FLASHFS_HANDLE FAPI_SYS_HandleT

/*! Callback function to report file operation status in blocking mode */
typedef void (*FLASHFS_CALLBACK_T)(int32_t event);

typedef enum
{
    /*! normal file */
    FLASHFS_FILE_SEMI_STATIC,
    /* frequently changing data, writing by chunk */
    FLASHFS_FILE_FREQ_CHANGING,

} FLASHFS_FILE_TypeEnumT;


/*!
****************************************************************************
** \brief file openning structure
**
****************************************************************************
*/
typedef struct
{
    /*! File ID */
    uint32_t                id; //0
    /*! File name, optional */
    char_t                  name[FLASHFS_FILE_NAME_MAX_LEN]; //4
    /*! File type, only FLASHFS_FILE_SEMI_STATIC or FLASHFS_FILE_FREQ_CHANGING is supported */
    FLASHFS_FILE_TypeEnumT  type; //68
    /*! File revision */
    uint32_t                revision; //72
    /*! File address, offset of sector relative to the first sector of the file system */
    uint32_t                sector_offset; //76
    /*! Number of sectors to be used by the file */
    uint32_t                num_sector; //80
    /*! if the file is FLASHFS_FILE_FREQ_CHANGING, chunk_size is expected and
    ** must be multiple of 4 bytes, for memory alignment */
    uint32_t                chunk_size; //84
    //88
} FLASHFS_FILE_T;

/*!
****************************************************************************
** \brief file information structure
**
****************************************************************************
*/
typedef struct
{
    /*! File ID */
    uint32_t                id;
    /*! File name, if specified */
    char_t                  name[FLASHFS_FILE_NAME_MAX_LEN];
    /*! File type, either FLASHFS_FILE_SEMI_STATIC or FLASHFS_FILE_FREQ_CHANGING */
    FLASHFS_FILE_TypeEnumT  type;
    /*! Exact starting address of file on the flash */
    uint32_t                start_addr;
    /*! Max. file size */
    uint32_t                size;
    /*! Actual file size */
    uint32_t                actual_length;
    /*! Chunk size for FLASHFS_FILE_FREQ_CHANGING file */
    uint32_t                chunk_size;
    /*! File revision */
    uint32_t                revision;

} FLASHFS_FILE_InfoT;

/*!
****************************************************************************
** \brief file system initialization structure
**
****************************************************************************
*/
typedef struct
{
    /*! Flash device parameters, only serial or parallel flash device is supported */
    uint32_t            device_type; //0
    /*! Beginning sector in the flash device to hold the file system */
    uint32_t            first_sector; //4
    /*! Number of sectors allocated for the file system */
    uint32_t            num_sector; //8

    /*! File system task parameters */
    uint32_t            stack_size; //12
    uint32_t            priority; //16
    uint32_t            flag; //20

    /*! file allocation table */
    FLASHFS_FILE_T*     file; //24
    uint32_t            num_file; //28

} FLASHFS_InitParamsT;

//**************************************************************************
//**************************************************************************
//** API Functions
//**************************************************************************
//**************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

int32_t        FLASHFS_Init     (const FLASHFS_InitParamsT* initParams);
void           FLASHFS_Exit     (void);
FLASHFS_HANDLE FLASHFS_Open     (uint32_t id, const char_t* mode,
                                 int32_t* errCodePtr);
int32_t        FLASHFS_Close    (FLASHFS_HANDLE file);
int32_t        FLASHFS_Read     (FLASHFS_HANDLE file, uint32_t length,
                                 void* buf, FLASHFS_CALLBACK_T cb);
int32_t        FLASHFS_Write    (FLASHFS_HANDLE file, uint32_t length,
                                 const void* buf, FLASHFS_CALLBACK_T cb);
int32_t        FLASHFS_Seek     (FLASHFS_HANDLE file, int32_t offset,
                                 int32_t origin);
int32_t        FLASHFS_GetInfo  (FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf);
int32_t        FLASHFS_Delete   (uint32_t id);
int32_t        FLASHFS_Format   (void);

#ifdef __cplusplus
}
#endif

#endif /* _FLASHFS_H_ */
