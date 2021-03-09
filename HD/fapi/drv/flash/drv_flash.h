/*!
********************************************************************************
********************************************************************************
**
** \file        ./fapi/drv/flash/src/drv_flash.h
**
** \brief       FLASH Driver.
**
** This file contains the declaration of the FLASH driver API.
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
#ifndef FAPI_FLASH_H
#define FAPI_FLASH_H

#include <stdchar.h>
#include "fapi/sys_driver.h"
#include "boot/flash_header.h"

//******************************************************************************
//******************************************************************************
//** Defines and Macros
//******************************************************************************
//******************************************************************************

#define FAPI_FLASH_DEVICE_PFLASH    0   //!< the parallel flash device
#define FAPI_FLASH_DEVICE_SFLASH    1   //!< the serial flash device
#define FAPI_FLASH_DEVICE_NFLASH    2   //!< the nand flash device

#define FAPI_FLASH_LBA_BYTES        512 //!< for FS we use 512 bytes logical blocks

/*!
********************************************************************************
** Standard error codes for the driver
********************************************************************************
*/

/*! Bad parameter passed. */
#define FAPI_FLASH_ERR_BAD_PARAMETER \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_BAD_PARAMETER)

/*! Memory allocation failed. */
#define FAPI_FLASH_ERR_OUT_OF_MEMORY \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY)

/*! Device already initialised. */
#define FAPI_FLASH_ERR_ALREADY_INITIALIZED \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_ALREADY_INITIALIZED)

/*! Device not initialised. */
#define FAPI_FLASH_ERR_NOT_INITIALIZED \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED)

/*! Feature or function is not available. */
#define FAPI_FLASH_ERR_FEATURE_NOT_SUPPORTED \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED)

/*! Timeout occured. */
#define FAPI_FLASH_ERR_TIMEOUT \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_TIMEOUT)

/*! The device is busy, try again later. */
#define FAPI_FLASH_ERR_DEVICE_BUSY \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_DEVICE_BUSY)

/*! Invalid handle was passed. */
#define FAPI_FLASH_ERR_INVALID_HANDLE \
       (FAPI_FLASH_MODULE_BASE+FAPI_ERR_INVALID_HANDLE)

/*! Semaphore could not be created. */
#define FAPI_FLASH_ERR_SEMAPHORE_CREATE \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE)

/*! The driver's used version is not supported. */
#define FAPI_FLASH_ERR_UNSUPPORTED_VERSION \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_UNSUPPORTED_VERSION)

/*! The mailqueue could not be created. */
#define FAPI_FLASH_ERR_MAILQUEUE_CREATE \
        (FAPI_FLASH_MODULE_BASE+FAPI_ERR_MAILQUEUE_CREATE)

/*!
********************************************************************************
** Additional driver error codes (reserved from -100 to -999)
**
** Each error code shall be decreased in steps of 1.
********************************************************************************
*/

/*! \brief Given device is not supported. */
#define FAPI_FLASH_ERR_DEVICE_NOT_SUPPORTED \
        (FAPI_FLASH_MODULE_BASE-101)

/*! \brief Given sector is protected. */
#define FAPI_FLASH_ERR_SECTOR_PROTECTED \
        (FAPI_FLASH_MODULE_BASE-102)

/*! \brief The magic id is missing. */
#define FAPI_FLASH_ERR_NO_MAGIC_ID_FOUND \
        (FAPI_FLASH_MODULE_BASE-103)

/*! \brief The current flash procedure failed. */
#define FAPI_FLASH_ERR_PROCESS_FAILED \
        (FAPI_FLASH_MODULE_BASE-104)

/*! \brief Flash sector is protected. */
#define FAPI_FLASH_ERR_PROTECTED \
        (FAPI_FLASH_MODULE_BASE-105)

/*! \brief The internal function pointer is invalid. */
#define FAPI_FLASH_ERR_INVALID_FUNCTION \
        (FAPI_FLASH_MODULE_BASE-106)

/*! \brief The internal device pointer is invalid. */
#define FAPI_FLASH_ERR_INVALID_DEVICE \
        (FAPI_FLASH_MODULE_BASE-107)

/*! \brief Allocate extended GPIO address pins failed. */
#define FAPI_FLASH_ERR_EXT_ADDRESS_FAILED \
        (FAPI_FLASH_MODULE_BASE-108)

/*! \brief Flash partition overlap detected. */
#define FAPI_FLASH_ERR_OVERLAP_DETECTED \
        (FAPI_FLASH_MODULE_BASE-108)

//******************************************************************************
//******************************************************************************
//** Data types
//******************************************************************************
//******************************************************************************

/*!
********************************************************************************
** \brief Version of the FLASH driver.
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
**       FAPI_FLASH_OpenParamsT structure.
**
********************************************************************************
*/
typedef enum
{
    FAPI_FLASH_VERSION = (int32_t)0x00020000   //!< The current driver version
} FAPI_FLASH_VersionEnumT;

/*!
********************************************************************************
** \brief Open parameters for the FLASH driver.
**
** This data structure covers all parameters which need to be specified
** when an instance of the driver is opened.
********************************************************************************
*/
typedef struct
{
    /*!
    ** The version of the driver.
    ** \ref FAPI_FLASH_VersionEnumT "FAPI_FLASH_VERSION".
    */
    FAPI_FLASH_VersionEnumT version; //0
    /*!
    ** The device type to open, either the parallel or the serial flash
    */
    uint32_t deviceType; //4
    /*!
    ** The first sector to be used
    */
    uint32_t firstSector; //8
    /*!
    ** The number of sectors to be used, '0' means use all available sectors
    */
    uint32_t sectorCount; //12
    /*!
    ** A flag which decides whether the flash is used by a file system
    ** or not, within a file system an erased sector contains zeros instead
    ** of 0xFF for every byte.
    */
    uint32_t fsysFlag; //16
    /*!
    ** A flag which decides whether to force flushing the current sector
    ** buffer data to flash memory while closing a handle.
    */
    uint32_t forceFlush; //20
    //24
} FAPI_FLASH_OpenParamsT;

/*!
********************************************************************************
** \brief Open parameters for the FLASH driver.
**
** This data structure covers all parameters which need to be specified
** when an instance of the driver is opened.
********************************************************************************
*/
typedef struct
{
    /*!
    ** The number of logical blocks used
    */
    uint32_t lbaCount;
    /*!
    ** The size of logical blocks in bytes
    */
    uint32_t lbaBytes;
    /*!
    ** The first sector to be used, taken from FAPI_FLASH_OpenParamsT
    */
    uint32_t firstSector;
    /*!
    ** The number of sectors to be used, taken from FAPI_FLASH_OpenParamsT
    ** but recalculated to the number of available sectors.
    */
    uint32_t sectorCount;
} FAPI_FLASH_VolumeT;

/*!
********************************************************************************
** \brief Bootable image information.
**
** This data structure contains information about a single image stored in
** flash memory, which is bootable from the rom boot loader.
********************************************************************************
*/
typedef struct
{
    /*!
    ** A data structure containing image information such as
    ** image type (ARM, ARC, etc.) as well as image size, etc.
    ** Please refer also to \ref BOOT_FLASH_ImageT.
    */
    BOOT_FLASH_ImageT imageHeaderInfo;
    /*!
    ** The address inside flash memory space where image data
    ** starts, this address is a simple 32-bit offset address
    ** relative to the flash memory start (0x80000000 for UPI
    ** device #0). The flash driver calculates the real address
    ** inside flash memory space according to gaps if neccessary,
    ** the imageDataAddress field describes a simple non-gap
    ** address.
    */
    uint32_t imageDataAddress;
} FAPI_FLASH_BootImageT;

/*!
********************************************************************************
** \brief Flash boot header header information.
**
** This data structure contains information about all images stored in
** flash memory, which are bootable from the rom boot loader.
********************************************************************************
*/
typedef struct
{
    /*!
    ** The flash header information contains magic id and other information,
    ** please refer to \ref BOOT_FLASH_HeaderT.
    */
    BOOT_FLASH_HeaderT flashHeaderInfo;
    /*!
    ** An array of max. 256 entries containing a copy of the register
    ** value setup from the flash memory.
    ** The number of used entries can be taken from flashHeaderInfo.setupCount
    */
    BOOT_FLASH_SetupT regValArray[256];
    /*!
    ** An array of max. 16 entries containing information about bootable
    ** images.
    ** The number of used entries can be taken from flashHeaderInfo.imageCount
    */
    FAPI_FLASH_BootImageT bootImageArray[16];
    /*!
    ** The number of flash bytes occupied by the current flash boot
    ** header, register value settings and image(s).
    */
    uint32_t bootBytes;
    /*!
    ** The number of flash sectors occupied by the current flash boot
    ** header, register value settings and image(s).
    */
    uint32_t bootSectors;
} FAPI_FLASH_BootInfoT;

//******************************************************************************
//******************************************************************************
//** Global Data
//******************************************************************************
//******************************************************************************

extern FAPI_SYS_DriverT FAPI_FLASH_Driver;

//******************************************************************************
//******************************************************************************
//** API Functions
//******************************************************************************
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

void             FAPI_FLASH_SetEnable(uint32_t deviceType, uint32_t enableFlag);
void             FAPI_FLASH_SetUpiIndex( uint32_t deviceType, uint32_t upiIndex );
int32_t          FAPI_FLASH_Init(void);
void             FAPI_FLASH_Exit(void);
FAPI_SYS_HandleT FAPI_FLASH_Open(const FAPI_FLASH_OpenParamsT* paramsPtr, int32_t* errorCodePtr );
int32_t          FAPI_FLASH_Close(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_EraseChip(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_EraseSector(FAPI_SYS_HandleT handle, uint32_t sectorIndex);
int32_t          FAPI_FLASH_ReadBytes(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, void* bufferPtr);
int32_t          FAPI_FLASH_WriteBytes(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, const void* bufferPtr);
int32_t          FAPI_FLASH_Flush( FAPI_SYS_HandleT handle );
int32_t          FAPI_FLASH_GetDeviceSize(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_GetDeviceId(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_GetManufacturerId(FAPI_SYS_HandleT handle);
const char_t*    FAPI_FLASH_GetDeviceName(FAPI_SYS_HandleT handle);
const char_t*    FAPI_FLASH_GetManufacturerName(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_GetSectorCount(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_GetSectorIndex(FAPI_SYS_HandleT handle, uint32_t address);
int32_t          FAPI_FLASH_GetSectorStart(FAPI_SYS_HandleT handle, uint32_t sectorIndex);
int32_t          FAPI_FLASH_GetSectorBytes(FAPI_SYS_HandleT handle, uint32_t sectorIndex);
int32_t          FAPI_FLASH_IsSectorEmpty(FAPI_SYS_HandleT handle, uint32_t sectorIndex);
int32_t          FAPI_FLASH_IsChipEmpty(FAPI_SYS_HandleT handle);
int32_t          FAPI_FLASH_IsSectorProtected(FAPI_SYS_HandleT handle, uint32_t sectorIndex);
int32_t          FAPI_FLASH_ProtectSector(FAPI_SYS_HandleT handle, uint32_t sectorIndex, uint32_t flag);

#ifdef __cplusplus
}
#endif

//******************************************************************************
//******************************************************************************
//** File system related API Functions
//******************************************************************************
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

int32_t             FAPI_FLASH_ReadBlocks(FAPI_SYS_HandleT handle,void* bufferPtr,uint32_t lbaIndex, uint32_t lbaCount);
int32_t             FAPI_FLASH_WriteBlocks(FAPI_SYS_HandleT handle,void* bufferPtr,uint32_t lbaIndex, uint32_t lbaCount);
FAPI_FLASH_VolumeT* FAPI_FLASH_GetInfo(FAPI_SYS_HandleT handle);

#ifdef __cplusplus
}
#endif

//******************************************************************************
//******************************************************************************
//** File system related API Functions
//******************************************************************************
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

int32_t FAPI_FLASH_ReadBytesDirect(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, void* bufferPtr);
int32_t FAPI_FLASH_WriteBytesDirect(FAPI_SYS_HandleT handle, uint32_t address, uint32_t byteCount, const void* bufferPtr);

#ifdef __cplusplus
}
#endif

//******************************************************************************
//******************************************************************************
//** Boot image related API Functions
//******************************************************************************
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

int32_t FAPI_FLASH_GetBootInfo(FAPI_SYS_HandleT handle, FAPI_FLASH_BootInfoT* resultBuffer);
int32_t FAPI_FLASH_GetBootImageInfoByVersion(FAPI_SYS_HandleT handle, uint32_t imageVersion, BOOT_FLASH_ImageT* headerBuffer);
int32_t FAPI_FLASH_GetBootImageInfoByIndex(FAPI_SYS_HandleT handle, uint32_t imageIndex, BOOT_FLASH_ImageT* headerBuffer);
int32_t FAPI_FLASH_LoadBootImageByVersion(FAPI_SYS_HandleT handle, uint32_t imageVersion, uint32_t targetAddress);
int32_t FAPI_FLASH_LoadBootImageByIndex(FAPI_SYS_HandleT handle, uint32_t imageIndex, uint32_t targetAddress);

int32_t FAPI_FLASH_GetBootFlashType( void );
int32_t FAPI_FLASH_CheckMagicId( FAPI_SYS_HandleT handle, uint32_t magicId );

#ifdef __cplusplus
}
#endif

//******************************************************************************
//******************************************************************************
//** End of file
//******************************************************************************
//******************************************************************************

#endif
