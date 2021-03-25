/*
********************************************************************************
********************************************************************************
**
** \file        ./subsystems/fs/flashfs/src/flashfs.c
**
** \brief       A simple file system for accessing files on flash
**              (serial/parallel) drive.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
********************************************************************************
*/
#include <fapi/sys_services.h>
#include <fapi/drv_timer.h>
#if 0
#include <rtos/rtos.h>
#endif

#include "flashfs.h"
#if 0
#include "fapex/abst_types.h"
#include "fapex/abst_lib.h"
#endif

#ifndef _LINUX_FAPI
#include <fapi/drv_flash.h>
#else
#include "fapex/abst_libvrflash.h"
#endif


#define FLASHFS_MAGIC_NUM       0x20080808
#define FLASHFS_SIGNATURE       0x57349564

#define FLASHFS_THREAD_NAME     "FlashFS"

#define FLASHFS_READ_FLAG       0x01
#define FLASHFS_WRITE_FLAG      0x02
#define FLASHFS_APPEND_FLAG     0x04

#define FLASHFS_READ_FC_DIRECT      1
#define FLASHFS_WRITE_FC_DIRECT     1

/* local data types */

typedef enum
{
    FLASHFS_CMD_WRITE,
    FLASHFS_CMD_READ,
    FLASHFS_CMD_FLUSH,
    FLASHFS_CMD_ERASE

} flashfsCmdTypeT;

typedef struct
{
    uint32_t            addr;
    void*               buf;
    uint32_t            length;

} flashfsCmdWriteParamsT;

typedef struct
{
    uint32_t            addr;
    void*               buf;
    uint32_t            length;

} flashfsCmdReadParamsT;

typedef struct
{
    uint32_t            first_sector;
    uint32_t            num_sector;

} flashfsCmdEraseParamsT;

typedef struct
{
    flashfsCmdTypeT     type;
    union
    {
        flashfsCmdWriteParamsT   write;
        flashfsCmdReadParamsT    read;
        flashfsCmdEraseParamsT   erase;

    } pars;

    FLASHFS_CALLBACK_T  cb;
    /*FAPEX_SYS_MailboxT*/void*  mailbox;

} flashfsCmdParamsT;

typedef struct
{
    uint32_t                magic_num;
    uint32_t                signature;
    uint32_t                revision;
    uint32_t                id;
    uint32_t                actual_length;

} flashfsFileHeaderT;

typedef struct
{
    FLASHFS_FILE_T* file;

    uint32_t        valid;

    uint32_t        start_addr;     /* start address of the file in flash */
    uint32_t        marker_offset;  /* for FCDATA only, position of the first marker */
    uint32_t        entry_offset;   /* offset of data in the file */
    uint32_t        chksum_offset;  /* offset of checksum in the file */
    uint32_t        size;           /* max. size of the file, excluding header & checksum */
    uint32_t        actual_length;  /* actual length of data stored in flash, not used for FCDATA */
    uint32_t        entry_pos;      /* current data position */

    uint8_t         dirty_flag;     /* indicate the file has been modified, not used for FCDATA */
    uint8_t         open_mode;      /* read/write/append mode */

    /*FAPEX_SYS_MailboxT*/void*   mailboxHandle;  /* use mailbox to sync r/w interthread communication */

    int32_t         (*readFct)(FLASHFS_HANDLE file, uint32_t length, void* buf, FLASHFS_CALLBACK_T cb);
    int32_t         (*writeFct)(FLASHFS_HANDLE file, uint32_t length, const void* buf, FLASHFS_CALLBACK_T cb);
    int32_t         (*seekFct)(FLASHFS_HANDLE file, int32_t offset, int32_t origin);
    int32_t         (*getInfoFct)(FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf);
    int32_t         (*closeFct)(FLASHFS_HANDLE file);

} flashfsFileHandleT;

typedef struct
{
    FAPI_SYS_HandleT    flashHandle; //0

    uint32_t            first_sector; //4
    uint32_t            num_sector; //8

    FLASHFS_FILE_T      file[FLASHFS_FILE_MAX_NUM]; //12
    /*FAPEX_SYS_ThreadT*/void*   fileThread[FLASHFS_FILE_MAX_NUM];   /* keep track of the thread which opens the file */
                                                            /* we also only allow one instance of file being opened */
    uint32_t            num_file; //2956

    uint32_t*               threadStack;
    /*FAPEX_SYS_ThreadT*/void*       threadHandle;
    /*FAPEX_SYS_SemaphoreT*/void*    sysMutexHandle;
    /*FAPEX_SYS_MailboxT*/void*      sysMailbox;
    /*FAPEX_SYS_MailqueueT*/void*    cmdMailHandle;
} flashfsT;

/* local data */
static flashfsT*        flashfsInst = NULL; //21f77c4c

/* local functions */
static FLASHFS_FILE_T*  flashfs_GetFileById(flashfsT* inst, uint32_t file_id);
static int32_t          flashfs_GetFileIndex(flashfsT* inst, uint32_t file_id);
static int32_t          flashfs_SendCmd(const flashfsCmdParamsT* params);
static int32_t          flashfs_WaitForCmdCompletion(/*FAPEX_SYS_MailboxT*/void* mailbox);
static void             flashfs_ThreadFunction(void* arg);
static int32_t          semistatic_FileRead(FLASHFS_HANDLE file, uint32_t length, void* buf, FLASHFS_CALLBACK_T cb);
static int32_t          semistatic_FileWrite(FLASHFS_HANDLE file, uint32_t length, const void* buf, FLASHFS_CALLBACK_T cb);
static int32_t          semistatic_FileSeek(FLASHFS_HANDLE file, int32_t offset, int32_t origin);
static int32_t          semistatic_FileGetInfo(FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf);
static int32_t          semistatic_FileClose(FLASHFS_HANDLE file);
static int32_t          fcdata_FileRead(FLASHFS_HANDLE file, uint32_t length, void* buf, FLASHFS_CALLBACK_T cb);
static int32_t          fcdata_FileWrite(FLASHFS_HANDLE file, uint32_t length, const void* buf, FLASHFS_CALLBACK_T cb);
static int32_t          fcdata_FileGetInfo(FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf);
static int32_t          fcdata_FileFormat(FLASHFS_HANDLE file);


//**************************************************************************
//**************************************************************************
//** API Functions
//**************************************************************************
//**************************************************************************

/*!
*****************************************************************************
** \brief Initialize the FLASHFS file system.
**
** This function initializes the file system.
**
** \param   initParams
**
** \return
**        - #FAPI_OK if initialization was successful
**        - #FLASHFS_ERR_ALREADY_INITIALIZED if the file system has already been
**          initialized
**        - #FLASHFS_ERR_BAD_PARAMETER
**        - #FLASHFS_ERR_OUT_OF_MEMORY
**        - #FLASHFS_ERR_INVALID_ALLOCATION if file overlaps in allocation table
**        - #FLASHFS_ERR_DUPLICATED_ID if file ID isn't unique
**        - #RTOS resource error codes
** \sa
**          - FLASHFS_Exit()
**
*****************************************************************************
*/
/* 21cb0698 - complete */
int32_t FLASHFS_Init(const FLASHFS_InitParamsT* initParams)
{
#ifndef _LINUX_FAPI
    FAPI_FLASH_OpenParamsT  flashParams;
#else
    FAPEX_VRFLASH_OpenParamsT flashParams;
#endif
    uint32_t                cnt1, cnt2;
    uint32_t                sectorStart1, sectorEnd1;
    uint32_t                sectorStart2, sectorEnd2;
    int32_t                 err = FAPI_OK;

    if ( flashfsInst != NULL ) /* support only one type of flash in the system?? */
    {
        return (FLASHFS_ERR_ALREADY_INITIALIZED);
    }

    if ( !initParams )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if ( initParams->num_file > FLASHFS_FILE_MAX_NUM )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    for(;;)
    {
        /* initialize the file allocation table */
        flashfsInst = FAPI_SYS_MALLOC(sizeof(flashfsT));
        if ( flashfsInst == NULL )
        {
            err = (FLASHFS_ERR_OUT_OF_MEMORY);
            break;
        }

        /* copy allocation table to local */
        memcpy(flashfsInst->file, initParams->file,
               initParams->num_file*sizeof(FLASHFS_FILE_T));

        flashfsInst->num_file     = initParams->num_file;
        flashfsInst->first_sector = initParams->first_sector;
        flashfsInst->num_sector   = initParams->num_sector;

        /* check conflicts in file allocation */
        for ( cnt1 = 0; cnt1 < flashfsInst->num_file; cnt1++)
        {
            /* check file type */
            if ( (flashfsInst->file[cnt1].type != FLASHFS_FILE_SEMI_STATIC) &&
                 (flashfsInst->file[cnt1].type != FLASHFS_FILE_FREQ_CHANGING) )
            {
                err = FLASHFS_ERR_BAD_PARAMETER;
                break;
            }

            /* check the flash layout */
            if (    (flashfsInst->file[cnt1].num_sector      == 0)
                 || (flashfsInst->file[cnt1].sector_offset   >= flashfsInst->num_sector)
                 || ((flashfsInst->file[cnt1].sector_offset   +
                      (flashfsInst->file[cnt1].num_sector - 1)) >= flashfsInst->num_sector) )
            {
                err = FLASHFS_ERR_INVALID_ALLOCATION;
                break;
            }

            for ( cnt2 = cnt1 + 1; cnt2 < flashfsInst->num_file; cnt2++ )
            {
                /* file id must be unique */
                if ( flashfsInst->file[cnt1].id == flashfsInst->file[cnt2].id )
                {
                    err = FLASHFS_ERR_DUPLICATED_ID;
                    break;
                }

                sectorStart1 = flashfsInst->file[cnt1].sector_offset;
                sectorStart2 = flashfsInst->file[cnt2].sector_offset;
                sectorEnd1   = flashfsInst->file[cnt1].sector_offset +
                               (flashfsInst->file[cnt1].num_sector - 1);
                sectorEnd2   = flashfsInst->file[cnt2].sector_offset +
                               (flashfsInst->file[cnt2].num_sector - 1);
                if ( ((sectorStart1 >= sectorStart2) &&
                      (sectorStart1 <= sectorEnd2))  ||
                     ((sectorEnd1 >= sectorStart2)   &&
                      (sectorEnd1 <= sectorEnd2)) )
                {
                    err = FLASHFS_ERR_INVALID_ALLOCATION;
                    break;
                }
            }

            if ( err != FAPI_OK ) break;
        }

        if ( err != FAPI_OK ) break;

#ifndef _LINUX_FAPI
        flashParams.version      = FAPI_FLASH_VERSION;
        flashParams.firstSector  = initParams->first_sector;
        flashParams.sectorCount  = initParams->num_sector;
        flashParams.fsysFlag     = 0;
        flashParams.deviceType   = initParams->device_type;
        flashParams.forceFlush   = 0;

        flashfsInst->flashHandle = FAPI_FLASH_Open(&flashParams, &err);
#else
        flashParams.version      = FAPEX_VRFLASH_VERSION;
        flashParams.firstSector  = initParams->first_sector;
        flashParams.sectorCount  = initParams->num_sector;
        flashParams.fsysFlag     = 0;
        flashParams.deviceType   = FAPEX_VRFLASH_DEVICE_PFLASH;
        flashParams.forceFlush   = 0;

        flashfsInst->flashHandle = FAPEX_VRFLASH_Open(&flashParams, &err);
#endif
        if ( flashfsInst->flashHandle == NULL ) break;

        /* create the FLASHFS thread */
        flashfsInst->threadStack = FAPI_SYS_MALLOC(initParams->stack_size*4);
        if ( !flashfsInst->threadStack )
        {
            err = (FLASHFS_ERR_OUT_OF_MEMORY);
            break;
        }

        flashfsInst->threadHandle = rtos_thread_create(flashfsInst->threadStack,
                                                       initParams->stack_size,
                                                       initParams->priority,
                                                       flashfs_ThreadFunction,
                                                       0,
                                                       0,
                                                       FLASHFS_THREAD_NAME );
        if( !flashfsInst->threadHandle )
        {
            err = rtos_get_current_thread_error();
            FAPI_SYS_PRINT_DEBUG( 3, "Creating FLASHFS thread failed, %d\n", err);
            break;
        }

        /* mailbox to sync formatting/deleting thread wrt FLASHFS thread */
        flashfsInst->sysMailbox = rtos_mailbox_create(4); /* 4 bytes */
        if ( !flashfsInst->sysMailbox )
        {
            err = rtos_get_current_thread_error();
            FAPI_SYS_PRINT_DEBUG( 3, "Creating mailbox failed, %d", err);
            break;
        }

        /* mailqueue is used to send command from calling thread to FLASHFS thread */
        flashfsInst->cmdMailHandle = RTOS_CreateMailqueue(1, sizeof(flashfsCmdParamsT));

        if( !flashfsInst->cmdMailHandle )
        {
            err = rtos_get_current_thread_error();
            FAPI_SYS_PRINT_DEBUG( 3, "Creating mailbox failed, %d\n", err);
            break;
        }

        /* only one thread is allowed to send command to FLASHFS thread at a time*/
        flashfsInst->sysMutexHandle = rtos_create_semaphore(1);
        if( !flashfsInst->cmdMailHandle )
        {
            err = rtos_get_current_thread_error();
            FAPI_SYS_PRINT_DEBUG( 3, "Creating mailbox failed, %d\n", err);
            break;
        }

        break; //end of for(;;)
    }

    if ( err != FAPI_OK )
    {
        if ( flashfsInst->sysMailbox )
        {
            (void)RTOS_DestroyMailbox(flashfsInst->sysMailbox);
        }

        if ( flashfsInst->sysMutexHandle )
        {
            (void)rtos_delete_semaphore(flashfsInst->sysMutexHandle);
        }

        if ( flashfsInst->cmdMailHandle )
        {
            (void)RTOS_DestroyMailqueue(flashfsInst->cmdMailHandle);
        }

        if ( flashfsInst->threadHandle )
        {
            (void)rtos_delete_thread(flashfsInst->threadHandle);
        }

        if ( flashfsInst->threadStack )
        {
            FAPI_SYS_FREE(flashfsInst->threadStack);
        }

        if ( flashfsInst->flashHandle )
        {
#ifndef _LINUX_FAPI
            (void)FAPI_FLASH_Close(flashfsInst->flashHandle);
#else
            (void)FAPEX_VRFLASH_Close(flashfsInst->flashHandle);
#endif
        }

        if ( flashfsInst )
        {
            FAPI_SYS_FREE(flashfsInst);
        }
    }

    return err;
}

/*!
*****************************************************************************
** \brief Exit the FLASHFS file system
**
** This function shuts down the file system
**
** \sa
**          - FLASHFS_Init()
**
*****************************************************************************
*/
/* 21cb05d0 - complete */
void FLASHFS_Exit(void)
{
    if ( flashfsInst != NULL )
    {
        if ( flashfsInst->sysMailbox )
        {
            (void)RTOS_DestroyMailbox(flashfsInst->sysMailbox);
        }

        if ( flashfsInst->sysMutexHandle )
        {
            (void)rtos_delete_semaphore(flashfsInst->sysMutexHandle);
        }

        if ( flashfsInst->cmdMailHandle )
        {
            (void)RTOS_DestroyMailqueue(flashfsInst->cmdMailHandle);
        }

        if ( flashfsInst->threadHandle )
        {
            (void)rtos_delete_thread(flashfsInst->threadHandle);
        }

        if ( flashfsInst->threadStack )
        {
            FAPI_SYS_FREE(flashfsInst->threadStack);
        }

        if ( flashfsInst->flashHandle )
        {
#ifndef _LINUX_FAPI
            (void)FAPI_FLASH_Close(flashfsInst->flashHandle);
#else
            (void)FAPEX_VRFLASH_Close(flashfsInst->flashHandle);
#endif
        }

        FAPI_SYS_FREE(flashfsInst);
        flashfsInst = NULL;
    }
}

/*!
*****************************************************************************
** \brief Open a FLASHFS file.
**
** This function opens a FLASHFS file. The given open parameter
** specifies the file ID to access as well as file open mode.
**
** \attention Each file can be opened only once.
**
** \param file_id FLASHFS file ID.
** \param errorCodePtr The pointer to error code for knowing the cause
**                      of internal failure.
**
** \return
**         - (>0) valid FLASHFS file handle on success.
**         - (0) if the FLASHFS file  couldn't be opened.
**
** \sa FLASHFS_Close
*****************************************************************************
*/
/* 21cafadc - complete */
FLASHFS_HANDLE FLASHFS_Open(uint32_t file_id, const char_t* mode,
                            int32_t* errCodePtr)
{
    flashfsFileHandleT*     fileHandle;
    flashfsFileHeaderT      header;
    uint32_t                cnt, bitCnt;
    uint32_t                marker, mask;
    uint32_t                addr;
    int32_t                 fileIdx;
    uint32_t                sectorIdx;
    uint32_t                sectorSize;
    uint32_t                checksum1, checksum2;
    int32_t                 err = FAPI_OK;
    uint8_t                 tmp;
    int32_t                 retVal;

    if ( flashfsInst == NULL )
    {
        err = FLASHFS_ERR_NOT_INITIALIZED;
        if ( errCodePtr ) *errCodePtr = err;
        return (0);
    }


    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    /* initialize the file handle */
    fileHandle = FAPI_SYS_MALLOC(sizeof(flashfsFileHandleT));
    if ( fileHandle == NULL)
    {
        (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

        if ( errCodePtr ) *errCodePtr = FLASHFS_ERR_OUT_OF_MEMORY;
        return (0);
    }

    for(;;)
    {
        memset(fileHandle, 0, sizeof(flashfsFileHandleT));

        /* check whether the file has been opened already */
        fileIdx = flashfs_GetFileIndex(flashfsInst, file_id);
        if ( fileIdx < 0 )
        {
            err = FLASHFS_ERR_BAD_PARAMETER;
            break;
        }

        if ( flashfsInst->fileThread[fileIdx] != (/*FAPEX_SYS_ThreadT*/void*)0 )
        {
            err = FLASHFS_ERR_ALREADY_OPEN;
            break;
        }

        /* locate file allocation info */
        fileHandle->file = flashfs_GetFileById(flashfsInst, file_id);

        if ( fileHandle->file == NULL )
        {
            err = FLASHFS_ERR_BAD_PARAMETER;
            break;
        }

        /* opening mode */
        if ( strcmp(mode, "r") == 0 )
        {
            fileHandle->open_mode |= FLASHFS_READ_FLAG;
        }
        else if ( strcmp(mode, "w") == 0 )
        {
            fileHandle->open_mode |= FLASHFS_WRITE_FLAG;
        }
        else if ( strcmp(mode, "a") == 0 )
        {
            fileHandle->open_mode |= FLASHFS_APPEND_FLAG;
        }
        else
        {
            err = FLASHFS_ERR_BAD_PARAMETER;
            break;
        }

        /* locate the file on the flash */
        sectorIdx              = flashfsInst->first_sector + fileHandle->file->sector_offset;
#ifndef _LINUX_FAPI
        retVal = FAPI_FLASH_GetSectorStart( flashfsInst->flashHandle,
                                             sectorIdx);
#else
        retVal = FAPEX_VRFLASH_GetSectorStart( flashfsInst->flashHandle,
                                             sectorIdx);
#endif
        if(retVal < 0)
        {
            err = retVal;
            break;
        }
        fileHandle->start_addr = (uint32_t)retVal;
        fileHandle->size = 0;
        for ( cnt = 0; cnt < fileHandle->file->num_sector; cnt++ )
        {
#ifndef _LINUX_FAPI
            retVal = FAPI_FLASH_GetSectorBytes( flashfsInst->flashHandle,
                                                sectorIdx);
#else
            retVal = FAPEX_VRFLASH_GetSectorBytes( flashfsInst->flashHandle,
                                                sectorIdx);
#endif
            if(retVal < 0)
            {
                err = retVal;
                break;
            }
            sectorSize = (uint32_t)retVal;
            fileHandle->size += sectorSize;
            sectorIdx++;
        }

        /* check whether the file is present on the flash */
#ifndef _LINUX_FAPI
        err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle,
                                    fileHandle->start_addr,
                                    sizeof(flashfsFileHeaderT),
                                    &header);
#else
        err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle,
                                    fileHandle->start_addr,
                                    sizeof(flashfsFileHeaderT),
                                    &header);
#endif
        if ( err != FAPI_OK ) break;

        FAPI_SYS_PRINT_DEBUG( 3, "FILE HEADER\n" );
        FAPI_SYS_PRINT_DEBUG( 3, "%s\n",fileHandle->file->name);
        FAPI_SYS_PRINT_DEBUG( 3, "magic number  : 0x%x\n", header.magic_num );
        FAPI_SYS_PRINT_DEBUG( 3, "signature     : 0x%x\n", header.signature );
        FAPI_SYS_PRINT_DEBUG( 3, "revision      : %d\n",  header.revision );
        FAPI_SYS_PRINT_DEBUG( 3, "id            : %d\n",  header.id );
        FAPI_SYS_PRINT_DEBUG( 3, "actual length : %d\n",  header.actual_length );

        fileHandle->valid = 1;

        if ( (header.magic_num != FLASHFS_MAGIC_NUM )         ||
             (header.signature != FLASHFS_SIGNATURE )         ||
             (header.revision  != fileHandle->file->revision) ||
             (header.id        != fileHandle->file->id) )
        {
            /* valid file has not been found on the flash */
            fileHandle->valid = 0;
            if ( (fileHandle->open_mode & FLASHFS_READ_FLAG) == FLASHFS_READ_FLAG )
            {
                err = FLASHFS_ERR_FILE_NOT_EXIST;
                break;
            }
        }

        if ( fileHandle->file->type == FLASHFS_FILE_SEMI_STATIC )
        {
            /* set up writing position parameters */
            fileHandle->entry_offset   = sizeof(flashfsFileHeaderT);

            sectorIdx                  = ((flashfsInst->first_sector        +
                                           fileHandle->file->sector_offset) +
                                           fileHandle->file->num_sector ) - 1;
#ifndef _LINUX_FAPI
            retVal = FAPI_FLASH_GetSectorStart(flashfsInst->flashHandle,
                                               sectorIdx);
#else
            retVal = FAPEX_VRFLASH_GetSectorStart(flashfsInst->flashHandle,
                                               sectorIdx);
#endif
            if(retVal < 0)
            {
                err = retVal;
                break;
            }
            fileHandle->chksum_offset  =  (uint32_t)retVal;
#ifndef _LINUX_FAPI
            retVal = (FAPI_FLASH_GetSectorBytes( flashfsInst->flashHandle, sectorIdx)-4);
#else
            retVal = (FAPEX_VRFLASH_GetSectorBytes( flashfsInst->flashHandle, sectorIdx)-4);
#endif
            if(retVal < 0)
            {
                err = retVal;
                break;
            }
            fileHandle->chksum_offset += (uint32_t)retVal;
            fileHandle->chksum_offset -= fileHandle->start_addr;

            FAPI_SYS_PRINT_DEBUG( 3, "start addr     : 0x%08x\n", fileHandle->start_addr );
            FAPI_SYS_PRINT_DEBUG( 3, "entry offset   : 0x%08x\n", fileHandle->entry_offset );
            FAPI_SYS_PRINT_DEBUG( 3, "checksum offset: 0x%08x\n", fileHandle->chksum_offset );

            if ( !fileHandle->valid )
            {
                fileHandle->actual_length = 0;
            }
            else
            {
                /* verify with checksum */
                fileHandle->actual_length = header.actual_length;

                if ( fileHandle->actual_length > 0 )
                {
                    checksum1 = 0;
                    for ( cnt = 0; cnt < fileHandle->actual_length; cnt++)
                    {
                        addr = fileHandle->start_addr + fileHandle->entry_offset + cnt;
#ifndef _LINUX_FAPI
                        err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle,
                                                   addr, 1, &tmp);
#else
                        err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle,
                                                   addr, 1, &tmp);
#endif
                        if ( err != FAPI_OK ) break;

                        FAPI_SYS_PRINT_DEBUG( 5, "Read byte 0x%02x\n", tmp );
                        checksum1 += tmp;
                    }
                    checksum1 ^= 0xFFFFFFFF;

                    addr = fileHandle->start_addr + fileHandle->chksum_offset;
#ifndef _LINUX_FAPI
                    err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, addr,
                                               4, &checksum2);
#else
                    err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, addr,
                                               4, &checksum2);
#endif
                    if ( err != FAPI_OK ) break;

                    if ( checksum1 != checksum2 )
                    {
                        FAPI_SYS_PRINT_DEBUG( 3, "checksum failed, computed 0x%x, read 0x%x\n", checksum1, checksum2 );
                        fileHandle->valid         = 0;
                        fileHandle->actual_length = 0;
                    }
                    else if ( (fileHandle->open_mode & FLASHFS_APPEND_FLAG) == FLASHFS_APPEND_FLAG )
                    {
                        if(fileHandle->actual_length > 0)
                        {
                            fileHandle->entry_pos = fileHandle->actual_length - 1;
                        } else {
                            fileHandle->entry_pos = 0;
                        }
                    }
                }
            }

            fileHandle->readFct    = semistatic_FileRead;
            fileHandle->writeFct   = semistatic_FileWrite;
            fileHandle->seekFct    = semistatic_FileSeek;
            fileHandle->getInfoFct = semistatic_FileGetInfo;
            fileHandle->closeFct   = semistatic_FileClose;
        }
        else if ( fileHandle->file->type == FLASHFS_FILE_FREQ_CHANGING )
        {
            /* initialize the marking algorithm, consider 4 bytes alignment for serial flash */
            /* internal adjustment */
            fileHandle->file->chunk_size = ((fileHandle->file->chunk_size+3)>>2)<<2;
            fileHandle->marker_offset    = (((fileHandle->start_addr +
                                           sizeof(flashfsFileHeaderT) + 3)>>2)<<2) -
                                           fileHandle->start_addr;
            fileHandle->entry_offset     = fileHandle->marker_offset +
                                           ((((((fileHandle->size - fileHandle->marker_offset)/
                                           fileHandle->file->chunk_size)>>3) + 3 )>>2)<<2);

            fileHandle->entry_offset    += sizeof(flashfsFileHeaderT);

            FAPI_SYS_PRINT_DEBUG( 3, "start addr: 0x%08x\n", fileHandle->start_addr );
            FAPI_SYS_PRINT_DEBUG( 3, "chunk size: %d\n", fileHandle->file->chunk_size );
            FAPI_SYS_PRINT_DEBUG( 3, "marker_offset: 0x%08x\n", fileHandle->marker_offset );
            FAPI_SYS_PRINT_DEBUG( 3, "entry offset: 0x%08x\n", fileHandle->entry_offset );

            /* locate the current writing position */
            fileHandle->entry_pos = 0;
            if ( fileHandle->valid )
            {
                addr   = fileHandle->start_addr + fileHandle->marker_offset;
                cnt    = 0;
                bitCnt = 0;
                /* start with coarse search */
                for(;;)
                {
#ifndef _LINUX_FAPI
                    err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, addr,
                                               4, &marker);
#else
                    err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, addr,
                                               4, &marker);
#endif
                    if ( err != FAPI_OK ) break;

                    FAPI_SYS_PRINT_DEBUG( 3, "marker = 0x%08x\n", marker );

                    if ( marker == 0xFFFFFFFF ) break;

                    cnt++;
                    addr += 4;
                }

                if ( err != FAPI_OK ) break;

                FAPI_SYS_PRINT_DEBUG( 3,"coarse marker position %d\n", cnt );

                /* fine search */
                if ( cnt > 0 )
                {
                    cnt--;
                    addr -= 4;

#ifndef _LINUX_FAPI
                    err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, addr,
                                               4, &marker);
#else
                    err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, addr,
                                               4, &marker);
#endif
                    if ( err != FAPI_OK ) break;

                    while ( bitCnt < 32 )
                    {
                        mask = 0x1<<bitCnt;
                        //DBG_Debug2("FCDATA_SearchLastPosition, data=0x%x, mask=0x%x\n", data, mask);
                        if ( (mask & marker) != 0 ) break;

                        bitCnt++;
                    }

                }

                fileHandle->entry_pos = ((cnt*32) + bitCnt)*fileHandle->file->chunk_size;

                FAPI_SYS_PRINT_DEBUG( 3,"current entry position %d, coarse %d, bit %d\n", fileHandle->entry_pos,
                                                                         cnt,
                                                                         bitCnt);

            }

            fileHandle->readFct    = fcdata_FileRead;
            fileHandle->writeFct   = fcdata_FileWrite;
            fileHandle->seekFct    = NULL;
            fileHandle->getInfoFct = fcdata_FileGetInfo;
        }
        else
        {
            err = FLASHFS_ERR_FEATURE_NOT_SUPPORTED;
            break;
        }

        fileHandle->mailboxHandle = rtos_mailbox_create(4);
        if ( !fileHandle->mailboxHandle )
        {
            err = rtos_get_current_thread_error();
            FAPI_SYS_PRINT_DEBUG( 3, "Creating mailbox failed, %d", err);
            break;
        }
        break; // end of for(;;)
    }

    if ( err != FAPI_OK )
    {
        if ( fileHandle->mailboxHandle )
        {
            (void)RTOS_DestroyMailbox(fileHandle->mailboxHandle);
        }

        FAPI_SYS_FREE(fileHandle);

        (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

        if ( errCodePtr ) *errCodePtr = err;
        return (0);
    }

    /* saves the current thread info */
    if(fileIdx < 0)
    {
        (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
        if ( errCodePtr ) *errCodePtr = FLASHFS_ERR_BAD_PARAMETER;
        return (0);
    }
    flashfsInst->fileThread[fileIdx] = rtos_get_current_thread();

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    if ( errCodePtr ) *errCodePtr = FAPI_OK;
    return (fileHandle);
}

/*!
*****************************************************************************
** \brief Closes a FLASHFS file.
**
** This function closes an instance of the FLASHFS file. All resources
** associated with the given file handle will be released.
**
** \attention After the file is closed the given handle is invalid and
**            must not be further used.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
**
** \return
**         - #FAPI_OK on success
**         - #other error code when invoking callback function
**
** \sa FLASHFS_Open
*****************************************************************************
*/
/* 21cafa30 - complete */
int32_t FLASHFS_Close(FLASHFS_HANDLE file)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    int32_t             fileIdx;
    int32_t             err;

    if ( fileHandle == 0 ) return (FLASHFS_ERR_BAD_PARAMETER);

    if ( fileHandle->closeFct )
    {
        err = fileHandle->closeFct((FLASHFS_HANDLE)fileHandle);
        if ( err != FAPI_OK )
            return (err);
    }

    if ( fileHandle->mailboxHandle )
    {
        (void)RTOS_DestroyMailbox(fileHandle->mailboxHandle);
    }

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    /* release the file thread */
    fileIdx = flashfs_GetFileIndex(flashfsInst, fileHandle->file->id);
    flashfsInst->fileThread[fileIdx] = (/*FAPEX_SYS_ThreadT*/void*)0;

    FAPI_SYS_FREE(file);

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return FAPI_OK;
}


/* 21caf448 - complete */
void FLASHFS_Unlock(void)
{
   (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
}


/* 21caf1f8 - complete */
void FLASHFS_Lock(void)
{
   (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);
}


/*!
*****************************************************************************
** \brief Read from FLASHFS file.
**
** This function reads data from the file for a given length.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param length Number of bytes to read.
** \param buf Pointer where the read data should be stored.
**                The caller is responsible to provide enough space for
**                length bytes.
** \param cb Callback function to report reading status in non-blocking reading mode
**
** \return >0 Number of read bytes.
**
** \sa FLASHFS_Open <br>
**     FLASHFS_Read
**     FLASHFS_Write
*****************************************************************************
*/
/* 21caf3b4 - complete */
int32_t FLASHFS_Read(FLASHFS_HANDLE file, uint32_t length, void* buf,
                     FLASHFS_CALLBACK_T cb)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    int32_t             err;

    if ( (fileHandle == NULL) || (buf == NULL) )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if ( fileHandle->readFct == NULL )
    {
        return (FLASHFS_ERR_FEATURE_NOT_SUPPORTED);
    }

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    err = fileHandle->readFct((FLASHFS_HANDLE)fileHandle, length, buf, cb);

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return err;
}

/*!
*****************************************************************************
** \brief Write to FLASHFS file.
**
** This function writes data to the file for a given length.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param length Number of bytes to write.
** \param buf Pointer where the write data is stored.
** \param cb Callback function to report writing status in non-blocking writing mode
**
** \return >0 Number of write bytes.
**
** \sa FLASHFS_Open <br>
**     FLASHFS_Read
**     FLASHFS_Write
*****************************************************************************
*/
/* 21caf314 - complete */
int32_t FLASHFS_Write(FLASHFS_HANDLE file, uint32_t length, const void* buf,
                      FLASHFS_CALLBACK_T cb)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    int32_t             err;

    if ( (fileHandle == NULL) || (buf == NULL) )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if ( (fileHandle->open_mode & FLASHFS_READ_FLAG) == FLASHFS_READ_FLAG )
    {
        return (FLASHFS_ERR_PROHIBITED);
    }

    if ( fileHandle->writeFct == NULL )
    {
        return (FLASHFS_ERR_FEATURE_NOT_SUPPORTED);
    }

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    err = fileHandle->writeFct(file, length, buf, cb);

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return err;
}

/*!
*****************************************************************************
** \brief Seek in the FLASHFS file.
**
** This function moves a file pointer inside the file.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param offset Number of bytes to seek, backwards if negative.
** \param origin Starting position to seek
**
** \return #FAPI_OK on success.
**
** \sa FLASHFS_Open <br>
**     FLASHFS_Read
**     FLASHFS_Write
*****************************************************************************
*/
/* 21caf294 - complete */
int32_t FLASHFS_Seek(FLASHFS_HANDLE file, int32_t offset, int32_t origin)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    int32_t             err;

    if ( fileHandle == 0 )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if ( fileHandle->seekFct == NULL )
        return (FLASHFS_ERR_FEATURE_NOT_SUPPORTED);

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    err = fileHandle->seekFct(file, offset, origin);

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return err;
}

/*!
*******************************************************************************
**
** \brief  Get information of a FLASHFS file
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param   inf pointer to store file info structure
**
** \return Possible return codes:
**         - #FAPI_OK
**         - #FE_ERR_BAD_PARAMETER
**         - #FLASHFS_ERR_FEATURE_NOT_SUPPORTED
**         - #Other error codes from callback functions
**
** \sa     FLASHFS_Open()
**
*******************************************************************************
*/
/* 21caf210 - complete */
int32_t FLASHFS_GetInfo(FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    int32_t             err;

    if ( (fileHandle == 0) || (inf == 0) )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }
    if ( fileHandle->getInfoFct == NULL )
        return (FLASHFS_ERR_FEATURE_NOT_SUPPORTED);

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    err = fileHandle->getInfoFct(file, inf);

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return err;
}

/*!
*******************************************************************************
**
** \brief  Delete a FLASHFS file
**
** \attention After the file is deleted the given file is permanently destroyed and space is freed.
**                  Used with caution.
**
** \param id Valid file ID.
**
** \return Possible return codes:
**         - #FAPI_OK
**         - #FE_ERR_BAD_PARAMETER
**         - #Other error codes
**
** \sa     FLASHFS_Init()
**
*******************************************************************************
*/
/* 21caf8d4 - complete */
int32_t FLASHFS_Delete (uint32_t id)
{
    int32_t             err = FAPI_OK;
    int32_t             addr;
    FLASHFS_FILE_T*     filePtr;
    flashfsCmdParamsT   cmd;
    flashfsFileHeaderT  header;

    if ( flashfsInst == NULL )
    {
        return FLASHFS_ERR_NOT_INITIALIZED;
    }

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    filePtr = flashfs_GetFileById(flashfsInst, id);

    if ( filePtr == NULL )
    {
        err = FLASHFS_ERR_BAD_PARAMETER;
    }
    else
    {
        /* Delete only if valid file is detected. */
#ifndef _LINUX_FAPI
        addr = FAPI_FLASH_GetSectorStart(flashfsInst->flashHandle,
                                        flashfsInst->first_sector + filePtr->sector_offset);
#else
        addr = FAPEX_VRFLASH_GetSectorStart(flashfsInst->flashHandle,
                                        flashfsInst->first_sector + filePtr->sector_offset);
#endif
        if ( addr >= 0 ) // otherwise addr contains error code
        {
#ifndef _LINUX_FAPI
            err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, (uint32_t)addr,
                                       sizeof(flashfsFileHeaderT), &header);
#else
            err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, (uint32_t)addr,
                                       sizeof(flashfsFileHeaderT), &header);
#endif
            if (    (err == FAPI_OK)
                 && (header.magic_num == FLASHFS_MAGIC_NUM)
                 && (header.signature == FLASHFS_SIGNATURE)
                 && (header.revision  == filePtr->revision)
                 && (header.id        == filePtr->id) )
            {
                /* Delete file by erasing its first sector. */
                memset(&cmd, 0, sizeof(flashfsCmdParamsT));
                cmd.type                    = FLASHFS_CMD_ERASE;
                cmd.pars.erase.first_sector = flashfsInst->first_sector + filePtr->sector_offset;
                cmd.pars.erase.num_sector   = 1;
                cmd.mailbox                 = flashfsInst->sysMailbox;

                err = flashfs_SendCmd(&cmd);
                if ( err != FAPI_OK )
                {
                    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
                    return (err);
                }

                err = flashfs_WaitForCmdCompletion(flashfsInst->sysMailbox);
                if ( err != FAPI_OK )
                {
                    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
                    return (err);
                }
            }
        } else {
            err = addr;
        }
    }

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return err;
}

/*!
*******************************************************************************
**
** \brief  Delete a FLASHFS file
**
** \attention All current data stored in the file system will be destroyed after formatting.
**            Use with caution.
**
** \return Possible return codes:
**         - #FAPI_OK
**         - #FLASHFS_ERR_NOT_INITIALIZED
**         - #Other error codes
**
** \sa     FLASHFS_Init()
**
*******************************************************************************
*/
/* 21caf620 - complete */
int32_t FLASHFS_Format (void)
{
    flashfsCmdParamsT   cmd;
    int32_t             err = FAPI_OK;

    (void)rtos_request_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_SUSPEND);

    if ( flashfsInst == NULL )
    {
        err = FLASHFS_ERR_NOT_INITIALIZED;
    }
    else
    {
        /* erase all sectors */
        memset(&cmd, 0, sizeof(flashfsCmdParamsT));
        cmd.type                    = FLASHFS_CMD_ERASE;
        cmd.pars.erase.first_sector = flashfsInst->first_sector;
        cmd.pars.erase.num_sector   = flashfsInst->num_sector;
        cmd.mailbox                 = flashfsInst->sysMailbox;

        err = flashfs_SendCmd(&cmd);
        if ( err != FAPI_OK )
        {
            (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
            return (err);
        }

        err = flashfs_WaitForCmdCompletion(flashfsInst->sysMailbox);
        if ( err != FAPI_OK )
        {
            (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
            return (err);
        }
    }

    (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);

    return err;
}

//**************************************************************************
//**************************************************************************
//** Local Functions
//**************************************************************************
//**************************************************************************

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
**
** \brief  Scan for file handle with file ID
**
*******************************************************************************
*/
/* 21caf058 - complete */
static FLASHFS_FILE_T* flashfs_GetFileById(flashfsT* inst, uint32_t file_id)
{
    uint32_t cnt;

    for ( cnt = 0; cnt < inst->num_file; cnt++ )
    {
        if ( inst->file[cnt].id == file_id )
        {
            return inst->file + cnt;
        }
    }

    return NULL;
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
**
** \brief  Translate the file ID to file index used internally
**
*******************************************************************************
*/
/* 21caf0c4 - complete */
static int32_t flashfs_GetFileIndex(flashfsT* inst, uint32_t file_id)
{
    uint32_t cnt;

    for ( cnt = 0; cnt < inst->num_file; cnt++ )
    {
        if ( inst->file[cnt].id == file_id )
        {
            return (int32_t)cnt;
        }
    }

    return (-1);
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
**
** \brief  Send a file system command to notify the background task, as well as the
** detailed command info
**
*******************************************************************************
*/
/* 21caf460 - complete */
static int32_t flashfs_SendCmd(const flashfsCmdParamsT* params)
{
    uint32_t err;

    err = RTOS_SetMailqueue(flashfsInst->cmdMailHandle, (void*)params, 0,
                             FAPI_SYS_NO_SUSPEND);
    if ( err == 0 )
    {
        (void)rtos_release_semaphore(flashfsInst->sysMutexHandle, FAPI_SYS_NO_SUSPEND);
        return (rtos_get_current_thread_error());
    }

    return (FAPI_OK);
}

/*!
*******************************************************************************
**
** \brief  Blocking function call to wait for the background task to complete the command
** processing
**
*******************************************************************************
*/
/* 21caf4ac - complete */
static int32_t flashfs_WaitForCmdCompletion(/*FAPEX_SYS_MailboxT*/void* mailbox)
{
    int32_t err;
    int32_t mail;

    if ( rtos_mailbox_receive(mailbox, &mail, FAPI_SYS_SUSPEND) == 0 )
    {
        err = rtos_get_current_thread_error();
        return (err);
    }

    if ( mail != FAPI_OK )
    {
        err = mail;
        return (err);
    }

    return (FAPI_OK);
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
**
** \brief  FLASHFS thread function to process file system commands in background
**
** This function waits from file system commands to access the physical device via low level
** driver. The supported commands include READ, WRITE, FLUSH and ERASE. Upon
** completion, a message will be sent back to calling thread to signal completion, or a callback
** function will be invoked to report the status to the host in non-blocking access.
**
** \sa     FLASHFS_Init()
**
*******************************************************************************
*/
/* 21cb0af4 - complete */
static void flashfs_ThreadFunction(void* arg)
{
    flashfsCmdParamsT   cmd;
    uint32_t            status;
    uint32_t            cnt;
    int32_t             err = FLASHFS_ERR_BAD_PARAMETER;;

    //MISRA
    arg = arg;

    for(;;)
    {
        (void)RTOS_GetMailqueue(flashfsInst->cmdMailHandle, &cmd, FAPI_SYS_SUSPEND);

        FAPI_SYS_PRINT_DEBUG( 3, "flashfs_ThreadFunction cmd received\n" );
        FAPI_SYS_PRINT_DEBUG( 3, "cmd type: %d \n", cmd.type );

        status = 1;
        switch ( cmd.type )
        {
            case FLASHFS_CMD_WRITE:
#ifndef _LINUX_FAPI
                err = FAPI_FLASH_WriteBytes(flashfsInst->flashHandle, cmd.pars.write.addr,
                                            cmd.pars.write.length, cmd.pars.write.buf);
#else
                err = FAPEX_VRFLASH_WriteBytes(flashfsInst->flashHandle, cmd.pars.write.addr,
                                            cmd.pars.write.length, cmd.pars.write.buf);
#endif
                /* free the writing buffer */
                FAPI_SYS_FREE(cmd.pars.write.buf);

                break;

            case FLASHFS_CMD_READ:
#ifndef _LINUX_FAPI
                err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, cmd.pars.read.addr,
                                           cmd.pars.read.length, cmd.pars.read.buf);
#else
                err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, cmd.pars.read.addr,
                                           cmd.pars.read.length, cmd.pars.read.buf);
#endif
                break;

            case FLASHFS_CMD_FLUSH:
#ifndef _LINUX_FAPI
                err = FAPI_FLASH_Flush(flashfsInst->flashHandle);
#else
                err = FAPEX_VRFLASH_Flush(flashfsInst->flashHandle);
#endif
                break;

            case FLASHFS_CMD_ERASE:
                for ( cnt = 0; cnt < cmd.pars.erase.num_sector; cnt++ )
                {
#ifndef _LINUX_FAPI
                    err = FAPI_FLASH_EraseSector(flashfsInst->flashHandle,
                                                 cmd.pars.erase.first_sector + cnt);
#else
                    err = FAPEX_VRFLASH_EraseSector(flashfsInst->flashHandle,
                                                 cmd.pars.erase.first_sector + cnt);
#endif
                    if ( err != FAPI_OK ) break;
                }
                break;

            default:
                FAPI_SYS_PRINT_DEBUG( 3, "unknown command, err\n" );
                status = 0;
                break;
        }

        if ( status )
        {
            if ( err != FAPI_OK )
            {
                FAPI_SYS_PRINT_DEBUG( 3, "access flash failed, %d\n", err );
                if ( cmd.cb )
                {
                    cmd.cb(err);
                } else {
                    (void)rtos_mailbox_send(cmd.mailbox, &err, FAPI_SYS_NO_SUSPEND);
                }
                continue;
            }

            FAPI_SYS_PRINT_DEBUG( 3, "cmd processed successfully\n" );

            if ( cmd.cb )
            {
                cmd.cb(FAPI_OK);
            } else {
                (void)rtos_mailbox_send(cmd.mailbox, &err, FAPI_SYS_NO_SUSPEND);
            }
        }

        //FAPI_SYS_SLEEP( 10 );
        rtos_wait(10);
    }
}

/* ------------------------------------------------------------------------- */

/*!
*******************************************************************************
**
** \brief  Read data from a semi static file
**
** This function reads data from the file for a given length.  A reading command is issued to
** background task to do the actual reading.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param length Number of bytes to read.
** \param buf Pointer where the read data should be stored.
**                The caller is responsible to provide enough space for
**                length bytes.
** \param cb Callback function to report reading status in non-blocking reading mode
**
** \return >0 Number of read bytes.
**         - #FAPI_OK
**         - #FLASHFS_ERR_BAD_PARAMETER
**         - #FLASHFS_ERR_END_OF_FILE
**         - #Other error codes
**
** \sa     FLASHFS_Init() <br>
**            FLASHFS_Read
**
*******************************************************************************
*/
/* 21caf4dc - complete */
static int32_t semistatic_FileRead(FLASHFS_HANDLE file, uint32_t length,
                                   void* buf, FLASHFS_CALLBACK_T cb)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    uint32_t            addr;
    flashfsCmdParamsT   cmd;
    int32_t             err;

    /* check reading out of boundary */
    if ( (fileHandle->entry_pos + length) > fileHandle->size )
    {
        FAPI_SYS_PRINT_MSG("\n %s %d file=%x FileRead size=%x over entry=%x length=%x",
              "src/flashfs.c", 1428, file,
              fileHandle->size,
              fileHandle->entry_pos,
              length);

        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if ( (fileHandle->entry_pos + length) > fileHandle->actual_length )
    {
       FAPI_SYS_PRINT_MSG("\n %s %d file=%x actual=%x over entry=%x length=%x",
             "src/flashfs.c", 1435, file,
             fileHandle->actual_length,
             fileHandle->entry_pos,
             length);

        return (FLASHFS_ERR_END_OF_FILE);
    }

    addr = fileHandle->start_addr + fileHandle->entry_offset +
           fileHandle->entry_pos;

    memset(&cmd, 0, sizeof(flashfsCmdParamsT));
    cmd.type             = FLASHFS_CMD_READ;
    cmd.pars.read.addr   = addr;
    cmd.pars.read.buf    = buf;
    cmd.pars.read.length = length;
    cmd.cb               = cb;
    cmd.mailbox          = fileHandle->mailboxHandle;

    err = flashfs_SendCmd(&cmd);
    if ( err != FAPI_OK )
    {
        return (err);
    }

    if ( cb == NULL )
    {
        err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
        if ( err != FAPI_OK ) return err;
    }

    fileHandle->entry_pos += length;
    return (int32_t)length;
}

/*!
*******************************************************************************
**
** \brief  Write data to a semi static file
**
** This function writes data to the file for a given length.  A writing command is issued to
** background task to do the actual writing.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param length Number of bytes to write.
** \param buf Pointer where the write data is stored.
** \param cb Callback function to report writing status in non-blocking writing mode
**
** \return >0 Number of written bytes.
**         - #FAPI_OK
**         - #FLASHFS_ERR_BAD_PARAMETER
**         - #FLASHFS_ERR_OUT_OF_MEMORY
**         - #Other error codes
**
** \sa     FLASHFS_Init() <br>
**            FLASHFS_Write
**
*******************************************************************************
*/
/* 21cb0494 - complete */
static int32_t semistatic_FileWrite(FLASHFS_HANDLE file, uint32_t length,
                                    const void* buf, FLASHFS_CALLBACK_T cb)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    flashfsCmdParamsT   cmd;
    void*               writeBuf;
    int32_t             err;

    /* check writing out of boundary */
    if ( (fileHandle->entry_pos + length) > fileHandle->size )
    {
       FAPI_SYS_PRINT_MSG("\n %s %d file=%x FileWrite size=%x over entry=%x length=%x",
             "src/flashfs.c", 1503,
             file, fileHandle->size,
             fileHandle->entry_pos, length);

        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    writeBuf = FAPI_SYS_MALLOC(length);
    if ( writeBuf == NULL )
    {
        return (FLASHFS_ERR_OUT_OF_MEMORY);
    }
    memcpy(writeBuf, buf, length);

    memset(&cmd, 0, sizeof(flashfsCmdParamsT));
    cmd.type              = FLASHFS_CMD_WRITE;
    cmd.pars.write.addr   = fileHandle->start_addr + fileHandle->entry_offset +
                            fileHandle->entry_pos;
    cmd.pars.write.buf    = writeBuf;
    cmd.pars.write.length = length;
    cmd.cb                = cb;
    cmd.mailbox           = fileHandle->mailboxHandle;

    err = flashfs_SendCmd(&cmd);
    if ( err != FAPI_OK )
    {
        return (err);
    }

    if ( cb == NULL )
    {
        err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
        if ( err != FAPI_OK ) return err;
    }

    fileHandle->entry_pos  += length;
    fileHandle->dirty_flag = 1;

    if ( fileHandle->actual_length < fileHandle->entry_pos )
    {
        fileHandle->actual_length = fileHandle->entry_pos;
    }

    return (int32_t)length;
}

/*!
*****************************************************************************
** \brief Seek in a semi static file.
**
** This function moves a file pointer inside the file.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param offset Number of bytes to seek, backwards if negative.
** \param origin Starting position to seek
**
** \return #FAPI_OK on success.
**
** \sa FLASHFS_Open <br>
**     semistatic_FileRead
**     semistatic_FileWrite
*****************************************************************************
*/
/* 21caf114 - complete */
static int32_t semistatic_FileSeek(FLASHFS_HANDLE file, int32_t offset,
                                   int32_t origin)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;

    switch ( origin )
    {
        case SEEK_SET:
            if ( (offset < 0) && (fileHandle->actual_length > (uint32_t)abs(offset) ) )
            {
                return (FLASHFS_ERR_BAD_PARAMETER);
            }
            fileHandle->entry_pos = (uint32_t)abs(offset);
            break;

        case SEEK_CUR:
            if(offset < 0)
            {
                fileHandle->entry_pos -= (uint32_t)abs(offset);
            } else {
                fileHandle->entry_pos += (uint32_t)abs(offset);
            }
            break;

        case SEEK_END:
            if ( (offset > 0) && (fileHandle->actual_length > (uint32_t)abs(offset) ) )
            {
                return (FLASHFS_ERR_BAD_PARAMETER);
            }
            fileHandle->entry_pos = fileHandle->actual_length - (uint32_t)abs(offset);
            break;

        default:
            return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if      ( fileHandle->entry_pos >= fileHandle->size ) fileHandle->entry_pos = fileHandle->size - 1;

    return FAPI_OK;
}

/*!
*******************************************************************************
**
** \brief  Get information of a semi static file
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param   inf pointer to store file info structure
**
** \return Possible return codes:
**         - #FAPI_OK
**
** \sa     FLASHFS_Open()
**
*******************************************************************************
*/
/* 21cb0154 - complete */
static int32_t semistatic_FileGetInfo(FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;

    inf->type           = fileHandle->file->type;
    inf->id             = fileHandle->file->id;
    inf->start_addr     = fileHandle->start_addr;
    inf->size           = fileHandle->size;
    inf->actual_length  = fileHandle->actual_length;
    inf->chunk_size     = 0;
    inf->revision       = fileHandle->file->revision;
    strcpy(inf->name, fileHandle->file->name);

    return FAPI_OK;
}

/*!
*****************************************************************************
** \brief Closes a semi static file.
**
** This function does additional task for semi static file closing, to compute the checksum
** and then flush the buffer
**
** \attention After the file is closed the given handle is invalid and
**            must not be further used.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
**
** \return
**         - #FAPI_OK on success
**         - #other error codes
**
** \sa FLASHFS_Open
*****************************************************************************
*/
/* 21caf6e4 - complete */
static int32_t semistatic_FileClose(FLASHFS_HANDLE file)
{
    flashfsFileHandleT*     fileHandle = (flashfsFileHandleT*)file;
    flashfsFileHeaderT*     header;
    flashfsCmdParamsT       cmd;
    uint32_t                checksum = 0;
    uint32_t                addr;
    uint8_t                 tmp;
    uint32_t*               writeBuf;
    uint32_t                cnt;
    int32_t                 err;

    if ( fileHandle->dirty_flag )
    {
        /* update the header */
        header = FAPI_SYS_MALLOC(sizeof(flashfsFileHeaderT));
        if(header == NULL)
        {
            return (FLASHFS_ERR_OUT_OF_MEMORY);
        }
        header->magic_num     = FLASHFS_MAGIC_NUM;
        header->signature     = FLASHFS_SIGNATURE;
        header->revision      = fileHandle->file->revision;
        header->id            = fileHandle->file->id;
        header->actual_length = fileHandle->actual_length;

        memset(&cmd, 0, sizeof(flashfsCmdParamsT));
        cmd.type              = FLASHFS_CMD_WRITE;
        cmd.pars.write.addr   = fileHandle->start_addr;
        cmd.pars.write.buf    = header;
        cmd.pars.write.length = sizeof(flashfsFileHeaderT);
        cmd.cb                = NULL;
        cmd.mailbox           = fileHandle->mailboxHandle;

        err = flashfs_SendCmd(&cmd);
        if ( err != FAPI_OK )
        {
            return (err);
        }

        err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
        if ( err != FAPI_OK ) return err;

        /* compute the checksum */
        for ( cnt = 0; cnt < fileHandle->actual_length; cnt++)
        {
            addr = fileHandle->start_addr + fileHandle->entry_offset + cnt;
#ifndef _LINUX_FAPI
            err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, addr, 1, &tmp);
#else
            err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, addr, 1, &tmp);
#endif
            if ( err != FAPI_OK ) return (err);

            FAPI_SYS_PRINT_DEBUG( 5, "Read byte 0x%02x\n", tmp );
            checksum += tmp;
        }
        checksum ^= 0xFFFFFFFF;

        writeBuf = FAPI_SYS_MALLOC(sizeof(uint32_t));
        if(writeBuf == NULL)
        {
            return (FLASHFS_ERR_OUT_OF_MEMORY);
        }
        *writeBuf = checksum;

        memset(&cmd, 0, sizeof(flashfsCmdParamsT));
        cmd.type              = FLASHFS_CMD_WRITE;
        cmd.pars.write.addr   = fileHandle->start_addr + fileHandle->chksum_offset;
        cmd.pars.write.buf    = writeBuf;
        cmd.pars.write.length = sizeof(uint32_t);
        cmd.cb                = NULL;
        cmd.mailbox           = fileHandle->mailboxHandle;

        err = flashfs_SendCmd(&cmd);
        if ( err != FAPI_OK )
        {
            return (err);
        }

        err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
        if ( err != FAPI_OK ) return err;

        memset(&cmd, 0, sizeof(flashfsCmdParamsT));
        cmd.type    = FLASHFS_CMD_FLUSH;
        cmd.mailbox = fileHandle->mailboxHandle;

        err = flashfs_SendCmd(&cmd);
        if ( err != FAPI_OK )
        {
            return (err);
        }

        err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
        if ( err != FAPI_OK ) return err;

        fileHandle->dirty_flag = 0;
    }

    return (FAPI_OK);
}

/*!
*******************************************************************************
**
** \brief  Read data from a frequently changing file
**
** This function reads data from the file for a given length.  Depending on the access
**  mode, a reading command is issued to background task to do the actual reading, or
** the actual reading is proceeded immediately. length is ignored here, the last chunk
** entry is always returned.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param length Number of bytes to read.
** \param buf Pointer where the read data should be stored.
**                The caller is responsible to provide enough space for
**                length bytes.
** \param cb Callback function to report reading status in non-blocking reading mode
**
** \return >0 Number of read bytes.
**         - #FAPI_OK
**         - #FLASHFS_ERR_BAD_PARAMETER
**         - #FLASHFS_ERR_END_OF_FILE
**         - #Other error codes
**
** \sa     FLASHFS_Init() <br>
**            FLASHFS_Read
**
*******************************************************************************
*/
static int32_t fcdata_FileRead(FLASHFS_HANDLE file, uint32_t length, void* buf,
                               FLASHFS_CALLBACK_T cb)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    #ifndef FLASHFS_READ_FC_DIRECT
    flashfsCmdParamsT   cmd;
    #endif
    uint32_t            addr;
    int32_t             err;

    if ( length < fileHandle->file->chunk_size )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    if ( fileHandle->entry_pos == 0 )
    {
        return (FLASHFS_ERR_END_OF_FILE);
    }

    /* retrieve the last entry */
    addr = ((fileHandle->start_addr + fileHandle->entry_offset) +
             fileHandle->entry_pos) - fileHandle->file->chunk_size;

    #ifdef FLASHFS_READ_FC_DIRECT

    if ( cb )
        return (FLASHFS_ERR_FEATURE_NOT_SUPPORTED);

#ifndef _LINUX_FAPI
    err = FAPI_FLASH_ReadBytes(flashfsInst->flashHandle, addr,
                               fileHandle->file->chunk_size, buf);
#else
    err = FAPEX_VRFLASH_ReadBytes(flashfsInst->flashHandle, addr,
                               fileHandle->file->chunk_size, buf);
#endif
    if ( err != FAPI_OK ) return (err);

    #else
    memset(&cmd, 0, sizeof(flashfsCmdParamsT));
    cmd.type             = FLASHFS_CMD_READ;
    cmd.pars.read.addr   = addr;
    cmd.pars.read.buf    = buf;
    cmd.pars.read.length = length;
    cmd.cb               = cb;
    cmd.mailbox          = fileHandle->mailboxHandle;

    err = flashfs_SendCmd(&cmd);
    if ( err != FAPI_OK )
    {
        return (err);
    }

    if ( cb == NULL )
    {
        err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
        if ( err != FAPI_OK ) return err;
    }

    #endif

    return (int32_t)fileHandle->file->chunk_size;
}

/*!
*******************************************************************************
**
** \brief  Write data to a frequently changing file
**
** This function writes data to the file for a given length.  Depending on the access
**  mode, a writing  command is issued to background task to do the actual writing, or
** the actual writing is proceeded immediately. length is ignored here,  data buffer of
** a chunk size is entered.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param length Number of bytes to write.
** \param buf Pointer where the write data is stored.
** \param cb Callback function to report writing status in non-blocking writing mode
**
** \return >0 Number of written bytes.
**         - #FAPI_OK
**         - #FLASHFS_ERR_BAD_PARAMETER
**         - #FLASHFS_ERR_OUT_OF_MEMORY
**         - #Other error codes
**
** \sa     FLASHFS_Init() <br>
**            FLASHFS_Write
**
*******************************************************************************
*/
/* 21cb0290 - complete */
static int32_t fcdata_FileWrite(FLASHFS_HANDLE file, uint32_t length,
                                const void* buf, FLASHFS_CALLBACK_T cb)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    #ifndef FLASHFS_WRITE_FC_DIRECT
        flashfsCmdParamsT   cmd;
        void*               writeBuf;
    #endif
    uint32_t            addr;
    uint32_t            marker;
    uint32_t            markerPos, bitPos;
    uint32_t            numChunk;
    int32_t             err;

    if ( cb )
        return (FLASHFS_ERR_FEATURE_NOT_SUPPORTED);

    if ( !fileHandle->valid )
    {
        /* format the file */
        (void)fcdata_FileFormat((FLASHFS_HANDLE)fileHandle);

        fileHandle->valid = 1;
    }

    if ( length != fileHandle->file->chunk_size )
    {
        return (FLASHFS_ERR_BAD_PARAMETER);
    }

    /* check the writing boundary, format if necessary */
    if ( (fileHandle->entry_pos + fileHandle->file->chunk_size) > fileHandle->size )
    {
        err = fcdata_FileFormat((FLASHFS_HANDLE)fileHandle);
        if ( err != FAPI_OK ) return err;

        fileHandle->entry_pos = 0;
    }

    /* write at the current entry position */
    addr = fileHandle->start_addr + fileHandle->entry_offset + fileHandle->entry_pos;

    #ifdef FLASHFS_WRITE_FC_DIRECT
#ifndef _LINUX_FAPI
        err  = FAPI_FLASH_WriteBytesDirect(flashfsInst->flashHandle, addr,
                                           fileHandle->file->chunk_size, buf);
#else
        err  = FAPEX_VRFLASH_WriteBytesDirect(flashfsInst->flashHandle, addr,
                                           fileHandle->file->chunk_size, buf);
#endif
        if ( err != FAPI_OK ) return (err);
    #else
        writeBuf = FAPI_SYS_MALLOC(length);
        if ( writeBuf == NULL )
        {
            err = (FLASHFS_ERR_BASE + FAPI_ERR_OUT_OF_MEMORY);
            return (err);
        }
        memcpy(writeBuf, buf, length);

        memset(&cmd, 0, sizeof(flashfsCmdParamsT));
        cmd.type              = FLASHFS_CMD_WRITE;
        cmd.pars.write.addr   = addr;
        cmd.pars.write.buf    = writeBuf;
        cmd.pars.write.length = length;
        cmd.cb                = cb;
        cmd.mailbox           = fileHandle->mailboxHandle;

        err = flashfs_SendCmd(&cmd);
        if ( err != FAPI_OK )
        {
            return (err);
        }

        if ( !cb )
        {
            err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
            if ( err != FAPI_OK ) return err;
        }
    #endif
    fileHandle->entry_pos += fileHandle->file->chunk_size;

    /* update the bit field */
    numChunk  = fileHandle->entry_pos / fileHandle->file->chunk_size;
    markerPos = numChunk>>5; /* divided by 32 */
    bitPos    = numChunk%32;

    marker    = (uint32_t)(0xFFFFFFFF)<<bitPos;
    addr      = fileHandle->start_addr + fileHandle->marker_offset + (markerPos*4);

    FAPI_SYS_PRINT_DEBUG( 3, "fcdata_FileWrite, addr 0x%08x, marker 0x%08x\n", addr, marker );

    #ifdef FLASHFS_WRITE_FC_DIRECT
#ifndef _LINUX_FAPI
        err = FAPI_FLASH_WriteBytesDirect(flashfsInst->flashHandle, addr, 4,
                                          &marker);
#else
        err = FAPEX_VRFLASH_WriteBytesDirect(flashfsInst->flashHandle, addr, 4,
                                          &marker);
#endif
        if ( err != FAPI_OK ) return (err);
        if ( (markerPos > 0) && (bitPos == 0))
        {
            /* clear maker position -1 because it is not cleared yet when a new
               maker positon is used */
            marker = 0x00000000;
#ifndef _LINUX_FAPI
            err = FAPI_FLASH_WriteBytesDirect(flashfsInst->flashHandle, addr-4, 4,
                                              &marker);
#else
            err = FAPEX_VRFLASH_WriteBytesDirect(flashfsInst->flashHandle, addr-4, 4,
                                              &marker);
#endif
            if ( err != FAPI_OK ) return (err);
        }
    #else
        writeBuf = FAPI_SYS_MALLOC(4);
        if ( writeBuf == NULL )
        {
            err = (FLASHFS_ERR_BASE + FAPI_ERR_OUT_OF_MEMORY);
            return (err);
        }
        (*(uint32_t*)writeBuf) = marker;

        memset(&cmd, 0, sizeof(flashfsCmdParamsT));
        cmd.type              = FLASHFS_CMD_WRITE;
        cmd.pars.write.addr   = addr;
        cmd.pars.write.buf    = writeBuf;
        cmd.pars.write.length = 4;
        cmd.cb                = cb;
        cmd.mailbox           = fileHandle->mailboxHandle;

        err = flashfs_SendCmd(&cmd);
        if ( err != FAPI_OK )
        {
            return (err);
        }

        if ( !cb )
        {
            err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
            if ( err != FAPI_OK ) return err;
        }
    #endif
    return (int32_t)fileHandle->file->chunk_size;
}

/*!
*******************************************************************************
**
** \brief  Get information of a frequently file
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
** \param   inf pointer to store file info structure
**
** \return Possible return codes:
**         - #FAPI_OK
**
** \sa     FLASHFS_Open()
**
*******************************************************************************
*/
/* 21cb00f8 - complete */
static int32_t fcdata_FileGetInfo(FLASHFS_HANDLE file, FLASHFS_FILE_InfoT* inf)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;

    inf->type           = fileHandle->file->type;
    inf->id             = fileHandle->file->id;
    inf->start_addr     = fileHandle->start_addr;
    inf->size           = fileHandle->size;
    inf->actual_length  = fileHandle->entry_pos;
    inf->chunk_size     = fileHandle->file->chunk_size;
    inf->revision       = fileHandle->file->revision;
    strcpy(inf->name, fileHandle->file->name);

    return (FAPI_OK);
}

/*!
*******************************************************************************
**
** \brief  Format a frequently changing file
**
** This function erases the contents inside a frequently changing file, and then sets up the
** file header for further read/write operation.
**
** \attention All current data stored in the file will be destroyed after formatting.
**            Use with caution.
**
** \param file Valid file instance handle previously returned by
**               FLASHFS_Open.
**
** \return Possible return codes:
**         - #FAPI_OK
**         - #Other error codes
**
** \sa     FLASHFS_Init()
**
*******************************************************************************
*/
/* 21cb01a8 - complete */
static int32_t fcdata_FileFormat(FLASHFS_HANDLE file)
{
    flashfsFileHandleT* fileHandle = (flashfsFileHandleT*)file;
    flashfsFileHeaderT  header;
    flashfsCmdParamsT   cmd;
    void*               writeBuf;
    int32_t             addr;
    int32_t             err;
    uint32_t            sectorIdx = flashfsInst->first_sector +
                                    fileHandle->file->sector_offset;

    FAPI_SYS_PRINT_DEBUG( 3, "fcdata_FileFormat, formatting..\n");

    /* erase first */
    memset(&cmd, 0, sizeof(flashfsCmdParamsT));
    cmd.type                    = FLASHFS_CMD_ERASE;
    cmd.pars.erase.first_sector = sectorIdx;
    cmd.pars.erase.num_sector   = fileHandle->file->num_sector;
    cmd.mailbox                 = fileHandle->mailboxHandle;

    err = flashfs_SendCmd(&cmd);
    if ( err != FAPI_OK )
        return (err);

    err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
    if ( err != FAPI_OK )
        return (err);

    /* program header */
    sectorIdx = flashfsInst->first_sector + fileHandle->file->sector_offset;
#ifndef _LINUX_FAPI
    addr = FAPI_FLASH_GetSectorStart(flashfsInst->flashHandle, sectorIdx);
#else
    addr = FAPEX_VRFLASH_GetSectorStart(flashfsInst->flashHandle, sectorIdx);
#endif
    if(addr < 0)
    {
        // addr contains error code if < 0
        return addr;
    }

    header.magic_num     = FLASHFS_MAGIC_NUM;
    header.signature     = FLASHFS_SIGNATURE;
    header.revision      = fileHandle->file->revision;
    header.id            = fileHandle->file->id;
    header.actual_length = 0;

    writeBuf = FAPI_SYS_MALLOC(sizeof(flashfsFileHeaderT));
    if ( writeBuf == NULL )
    {
        err = (FLASHFS_ERR_OUT_OF_MEMORY);
        return (err);
    }
    memcpy(writeBuf, &header, sizeof(flashfsFileHeaderT));

    memset(&cmd, 0, sizeof(flashfsCmdParamsT));
    cmd.type              = FLASHFS_CMD_WRITE;
    cmd.pars.write.addr   = (uint32_t)addr;
    cmd.pars.write.buf    = writeBuf;
    cmd.pars.write.length = sizeof(flashfsFileHeaderT);
    cmd.cb                = NULL;
    cmd.mailbox           = fileHandle->mailboxHandle;

    err = flashfs_SendCmd(&cmd);
    if ( err != FAPI_OK )
    {
        return (err);
    }

    err = flashfs_WaitForCmdCompletion(fileHandle->mailboxHandle);
    if ( err != FAPI_OK ) return err;

    return (FAPI_OK);
}

