/*!
********************************************************************************
********************************************************************************
**
** \file        ./fapi/drv/boot/src/drv_boot.h
**
** \brief       BOOT Driver.
**
** This file contains the declaration of the BOOT driver API.
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
#ifndef FAPI_BOOT_H
#define FAPI_BOOT_H

#include "fapi/sys_driver.h"

//******************************************************************************
//******************************************************************************
//** Defines and Macros
//******************************************************************************
//******************************************************************************

#define FAPI_BOOT_MODE_UNKNOWN      0x0UL //!< Unknown boot mode
#define FAPI_BOOT_MODE_DEBUGPORT    0x1UL //!< Application exectured via debug port
#define FAPI_BOOT_MODE_ROMBOOTLDR   0x2UL //!< Application booted by "ROM Bootloader"
#define FAPI_BOOT_MODE_BOOTER       0x3UL //!< Application booted by "booter"

#define FAPI_BOOT_DEVICE_UNKNOWN    0x0UL //!< Unknown boot device
#define FAPI_BOOT_DEVICE_PFLASH     0x1UL //!< The parallel flash device
#define FAPI_BOOT_DEVICE_SFLASH     0x2UL //!< The serial flash device

#define FAPI_BOOT_FIRMWARE_UNKNOWN  0x0UL //!< Unknown firmware location flag
#define FAPI_BOOT_FIRMWARE_EMBEDDED 0x1UL //!< Firmware is embedded in application
#define FAPI_BOOT_FIRMWARE_EXTERNAL 0x2UL //!< Firmware is stored externally

/*!
********************************************************************************
** Standard error codes for the driver
********************************************************************************
*/

/*! Bad parameter passed. */
#define FAPI_BOOT_ERR_BAD_PARAMETER \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_BAD_PARAMETER)

/*! Memory allocation failed. */
#define FAPI_BOOT_ERR_OUT_OF_MEMORY \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY)

/*! Device already initialised. */
#define FAPI_BOOT_ERR_ALREADY_INITIALIZED \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_ALREADY_INITIALIZED)

/*! Device not initialised. */
#define FAPI_BOOT_ERR_NOT_INITIALIZED \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED)

/*! Invalid handle was passed. */
#define FAPI_BOOT_ERR_INVALID_HANDLE \
       (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_INVALID_HANDLE)

/*! Semaphore could not be created. */
#define FAPI_BOOT_ERR_SEMAPHORE_CREATE \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE)

/*! The driver's used version is not supported. */
#define FAPI_BOOT_ERR_UNSUPPORTED_VERSION \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_UNSUPPORTED_VERSION)

/*! The requested feature is not supported. */
#define FAPI_BOOT_ERR_FEATURE_NOT_SUPPORTED \
        (int32_t)(FAPI_BOOT_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED)

/*!
********************************************************************************
** Additional driver error codes (reserved from -100 to -999)
**
** Each error code shall be decreased in steps of 1.
********************************************************************************
*/

/*! \brief Current device is not supported/unknown. */
#define FAPI_BOOT_ERR_DEVICE_UNKNOWN \
        (int32_t)(FAPI_BOOT_MODULE_BASE-101)

/*! \brief Current boot mode is not supported/unknown. */
#define FAPI_BOOT_ERR_MODE_UNKNOWN \
        (int32_t)(FAPI_BOOT_MODULE_BASE-102)

#define FAPI_BOOT_INFO_PTR (FAPI_BOOT_InfoT*)(void*)(FIO_ADDRESS(SRAM,0x02000000UL)+sizeof(BOOT_ROM_SymbolT))

//******************************************************************************
//******************************************************************************
//** Data types
//******************************************************************************
//******************************************************************************

/*!
********************************************************************************
** \brief Version of the BOOT driver.
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
**       #FAPI_BOOT_OpenParamsT structure.
**
********************************************************************************
*/
typedef enum
{
    FAPI_BOOT_VERSION = (int32_t)0x00020000   //!< The current driver version
} FAPI_BOOT_VersionEnumT;

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
    ** \ref FAPI_BOOT_VersionEnumT "FAPI_BOOT_VERSION".
    */
    FAPI_BOOT_VersionEnumT version;
} FAPI_BOOT_OpenParamsT;

/*!
********************************************************************************
** \brief Flash boot header header information.
**
** This data structure contains information about the current booted
** application, this structure is stored within the internal SDRAM.
********************************************************************************
*/
typedef struct
{
    uint32_t bootMode; //0     //!< The boot mode like #FAPI_BOOT_MODE_ROMBOOTLDR
    uint32_t bootDevice; //4   //!< The boot device like #FAPI_BOOT_DEVICE_SFLASH
    uint32_t slotIndex; //8   //!< Current slot index, used only by booter
    uint32_t slotAddress0; //12 //!< Flash start address of 1st slot, used only by booter
    uint32_t slotAddress1; //16 //!< Flash start address of 2nd slot, used only by booter
} FAPI_BOOT_InfoT;

/*!
*******************************************************************************
** \brief Booter image header.
**
** NOTE: Structure size must be a multiple the size of a longword.
**
*******************************************************************************
*/
typedef struct
{
    uint32_t imageVersion; //0 //!< Version number of the image
    uint32_t imageControl; //4 //!< Type of image and execution control
    uint32_t imageSize;    //8 //!< Number of 32bit long words for this data image
    uint32_t loadAddress;  //12 //!< Memory load address where to copy image data to (byte address)
    uint32_t jumpAddress;  //16 //!< Jump address where to branch to, to start the image in RAM (byte address)
    //20
}
FAPI_BOOT_ImageHeaderT;

//******************************************************************************
//******************************************************************************
//** Global Data
//******************************************************************************
//******************************************************************************

extern FAPI_SYS_DriverT FAPI_BOOT_Driver;

//******************************************************************************
//******************************************************************************
//** API Functions
//******************************************************************************
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

int32_t          FAPI_BOOT_Init(void);
void             FAPI_BOOT_Exit(void);
FAPI_SYS_HandleT FAPI_BOOT_Open(const FAPI_BOOT_OpenParamsT* paramsPtr,int32_t* errorCodePtr);
int32_t          FAPI_BOOT_Close(FAPI_SYS_HandleT handle);
int32_t          FAPI_BOOT_GetInfo(FAPI_SYS_HandleT handle,FAPI_BOOT_InfoT* resultBuffer);
int32_t          FAPI_BOOT_GetBootMode(FAPI_SYS_HandleT handle,uint32_t* modeBuffer);
int32_t          FAPI_BOOT_GetBootDevice(FAPI_SYS_HandleT handle,uint32_t* deviceBuffer);
int32_t          FAPI_BOOT_LoadImageByVersion(FAPI_SYS_HandleT handle,uint32_t imageVersion,uint32_t targetAddress);
int32_t          FAPI_BOOT_GetImageInfoByVersion(FAPI_SYS_HandleT handle,uint32_t imageVersion,FAPI_BOOT_ImageHeaderT* infoBuffer);

#ifdef __cplusplus
}
#endif

//******************************************************************************
//******************************************************************************
//** End of file
//******************************************************************************
//******************************************************************************

#endif
