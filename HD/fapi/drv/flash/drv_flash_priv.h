/*
********************************************************************************
********************************************************************************
**
** \file      ./fapi/drv/flash/src/drv_flash_priv.h
**
** \brief     Flash specific private and CFI definitions and macros
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
********************************************************************************
*/
#ifndef FAPI_FLASH_PRIV_H
#define FAPI_FLASH_PRIV_H

/*
********************************************************************************
**
** IDE handle data structure.
**
********************************************************************************
*/
#define FAPI_FLASH_REGION_COUNT_MAX       4    // max. number of erase regions
#define FAPI_FLASH_SECTOR_UNUSED          0xFFFFFFFFUL

#define FAPI_FLASH_PORT_BITS_8            0x01 // device port width  8 bits
#define FAPI_FLASH_PORT_BITS_16           0x02 // device port width 16 bits
#define FAPI_FLASH_PORT_BITS_32           0x04 // device port width 32 bits

#define FAPI_FLASH_DATA_BITS_8            0x01 // device data width  8 bits
#define FAPI_FLASH_DATA_BITS_16           0x02 // device data width 16 bits
#define FAPI_FLASH_DATA_BITS_32           0x04 // device data width 32 bits

#define FAPI_FLASH_CMDSET_UNDEFINED       0x0000
#define FAPI_FLASH_CMDSET_INTEL_EXT       0x0001
#define FAPI_FLASH_CMDSET_SHARP_EXT       FAPI_FLASH_CMDSET_INTEL_EXT
#define FAPI_FLASH_CMDSET_FUJITSU_STD     0x0002
#define FAPI_FLASH_CMDSET_AMD_STD         FAPI_FLASH_CMDSET_FUJITSU_STD
#define FAPI_FLASH_CMDSET_FUJITSU_EXT     0x0004
#define FAPI_FLASH_CMDSET_AMD_EXT         FAPI_FLASH_CMDSET_FUJITSU_EXT
#define FAPI_FLASH_CMDSET_MITSUBISHI_STD  0x0100
#define FAPI_FLASH_CMDSET_RESERVED        0xFFFF

#define FAPI_FLASH_MANUFACTURER_UNDEFINED 0x00
#define FAPI_FLASH_MANUFACTURER_SPANSION  0x01
#define FAPI_FLASH_MANUFACTURER_FUJITSU   0x04
#define FAPI_FLASH_MANUFACTURER_ATMEL     0x1F
#define FAPI_FLASH_MANUFACTURER_STMICRO   0x20
#define FAPI_FLASH_MANUFACTURER_MACRONIX  0xC2
#define FAPI_FLASH_MANUFACTURER_EXELSEMI  0x4A
#define FAPI_FLASH_MANUFACTURER_SAMSUNG   0xEC

#define FAPI_FLASH_DETECT_CHIP_TIMEOUT    2000  //  2 secs
#define FAPI_FLASH_ERASE_SECTOR_TIMEOUT   10000 // 10 secs
#define FAPI_FLASH_ERASE_CHIP_TIMEOUT     60000 // 60 secs
#define FAPI_FLASH_READ_SECTOR_TIMEOUT    10000 // 10 secs
#define FAPI_FLASH_PROGRAM_PAGE_TIMEOUT   20000 // 20 secs

/*
********************************************************************************
**
** FLASH specific data structures
**
********************************************************************************
*/

typedef union
{
    uint8_t  uint8;  // a  8 bit data word
    uint16_t uint16; // a 16 bit data word
    uint32_t uint32; // a 32 bit data word
}
flashWordT;

typedef union
{
    volatile void*     voidPtr;   // a volatile generic void pointer
    volatile uint8_t*  uint8Ptr;  // a volatile  8 bit data pointer
    volatile uint16_t* uint16Ptr; // a volatile 16 bit data pointer
    volatile uint32_t* uint32Ptr; // a volatile 32 bit data pointer
}
flashPtrT;

typedef struct
{
    uint32_t      id;     // the ID to search for
    const char_t* string; // the resulting xref string to return
}
flashIdStrT;

typedef struct
{
    uint32_t sectorCount; // number of sectors in erase region
    uint32_t sectorBytes; // sector size in erase region
}
flashRegionT;

typedef struct
{
    const char_t* deviceName; //0       // human readable flash device string
    uint32_t      eraseRegionCount; //4 // number of used erase regions
    flashRegionT  eraseRegionTable[FAPI_FLASH_REGION_COUNT_MAX]; //8
    uint32_t      portBits; //40        // the width of the port
    uint32_t      dataBits; //44        // the width of the chip
    uint32_t      manufacturerId; //48  // manufacturer id
    uint32_t      deviceId; //52        // device id
    uint32_t      commandSet; //56      // vendor command set identifier
    uint32_t      resetCommand; //60    // vendor specific reset command
    uint32_t      legacyUnlock; //64    // support Intel legacy (un)locking
    //68
}
flashDescriptorT;

typedef struct
{
    uint32_t          deviceId; //0          // combined device & manufacturer code
    uint32_t          deviceBytes; //4       // total bank size in bytes
    uint32_t          sectorCount; //8       // total number of erase units (sectors)
    uint32_t          cfiVersion; //12        // cfi version
    uint32_t          cfiOffset; //16         // offset for cfi query
    flashDescriptorT* descriptorPtr; //20     // a pointer to the current device info block
    uint32_t*         sectorStartArray; //24  // holding the start addresses for all sectors
    uint32_t*         sectorBytesArray; //28  // holding the sector sizes for all sectors
    uint8_t*          sectorProtectArray; //32 // holding protection flags for all sectors
    void*             sectorBuffer; //36      // allocated buffer of max. sector size
    uint32_t          sectorIndex; //40       // index of sector currently in buffer
    uint32_t          sectorStart; //44       // start address of sector currently in buffer
    uint32_t          sectorBytes; //48       // size of sector currently in buffer
    uint32_t          dirtyFlag; //52         // decides whether flush is necessary
    //56
} flashDeviceT;

typedef int32_t(*flashDetectChipT)(flashDeviceT** devicePtrPtr, uint32_t timeout);
typedef int32_t(*flashEraseChipT)(flashDeviceT* devicePtr, uint32_t timeout);
typedef int32_t(*flashEraseSectorT)(flashDeviceT* devicePtr, uint32_t timeout);
typedef int32_t(*flashReadSectorT)(flashDeviceT* devicePtr, uint32_t timeout);
typedef int32_t(*flashWriteSectorT)(flashDeviceT* devicePtr, uint32_t timeout);

// typedef struct
// {
//     uint32_t sectorIndex;
//     uint32_t byteOffset;
//     uint32_t byteCount;
//     void*    bufferPtr;
// } flashDirectT;

typedef int32_t(*flashReadDirectT)(flashDeviceT* devicePtr, uint32_t sectorIndex,
                                   uint32_t byteOffset, uint32_t byteCount,
                                   void* bufferPtr, uint32_t timeout);
typedef int32_t(*flashWriteDirectT)(flashDeviceT* devicePtr, uint32_t sectorIndex,
                                    uint32_t byteOffset, uint32_t byteCount,
                                    const void* bufferPtr, uint32_t timeout);

// typedef int32_t(*flashReadDirectT)(flashDeviceT* devicePtr, flashDirectT* accessInfoPtr, uint32_t timeout);
// typedef int32_t(*flashWriteDirectT)(flashDeviceT* devicePtr, flashDirectT* accessInfoPtr, uint32_t timeout);

typedef struct
{
    uint32_t            inUse; //0              // specifies if block is in use
    uint32_t            deviceType; //4         // device type, either parallel or serial
    FAPI_SYS_SemaphoreT semaphore; //8          // device lock semaphore
    flashDeviceT*       devicePtr; //12          // information about the initialized device
    flashDetectChipT    detectChipFunction; //16 // specific device detection function
    flashEraseChipT     eraseChipFunction; //20  // specific erase chip function
    flashEraseSectorT   eraseSectorFunction; //24 // specific erase sector function
    flashReadSectorT    readSectorFunction; //28 // specific read sector function
    flashWriteSectorT   writeSectorFunction; //32 // specific write sector function
    flashReadDirectT    readDirectFunction; //36  // specific read bytes function
    flashWriteDirectT   writeDirectFunction; //40 // specific write bytes function
    //44
} flashBlockT;

typedef struct
{
    uint32_t               id; //0        // handle ID
    uint32_t               inUse; //4     // specifies if handle is in use
    FAPI_FLASH_OpenParamsT openParams; //8 // open params of the handle
    flashBlockT*           blockPtr; //32  // pointer to the flash block structure
    FAPI_FLASH_VolumeT     volumeInfo; //36 // FS specific valuem information
} flashHandleT;

typedef struct
{
    uint32_t command;   // activate flash device, write-command
    uint32_t address;   // write address
    uint32_t data;      // data read/write
    uint32_t end;       // deactivate flash device
}nflashRegisterT;

/*
********************************************************************************
**
** FLASH specific global variables
**
********************************************************************************
*/
extern flashDescriptorT fapiPFlashDescriptorArray[];
extern flashDescriptorT fapiSFlashDescriptorArray[];
extern flashDescriptorT fapiNFlashDescriptorArray[];
extern uint32_t         pflashBaseAddress;
extern uint32_t         nflashBaseAddress;
extern volatile nflashRegisterT*  nflashRegisterPtr;

/*
********************************************************************************
**
** Function prototypes
**
********************************************************************************
*/
#ifdef __cplusplus
extern "C" {
#endif

uint32_t flashCheckHandle( const flashHandleT* handlePtr );
#if defined(FLASH_DEBUG_CACHE_BUFFER) || defined(FLASH_DEBUG_BLOCK_BUFFER)
void flashPrintBuffer( uint32_t address, uint32_t* buffer, uint32_t words, uint32_t full );
#endif

int32_t pflashDetectChip(  flashDeviceT** devicePtrPtr, uint32_t timeout );
int32_t pflashEraseChip(   flashDeviceT* devicePtr, uint32_t timeout );
int32_t pflashEraseSector( flashDeviceT* devicePtr, uint32_t timeout );
int32_t pflashReadSector(  flashDeviceT* devicePtr, uint32_t timeout );
int32_t pflashWriteSector( flashDeviceT* devicePtr, uint32_t timeout );

int32_t pflashReadDirect(  flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           void* bufferPtr, uint32_t timeout );
int32_t pflashWriteDirect( flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           const void* bufferPtr, uint32_t timeout );

int32_t sflashDetectChip(  flashDeviceT** devicePtrPtr, uint32_t timeout );
int32_t sflashEraseChip(   flashDeviceT* devicePtr, uint32_t timeout );
int32_t sflashEraseSector( flashDeviceT* devicePtr, uint32_t timeout );
int32_t sflashReadSector(  flashDeviceT* devicePtr, uint32_t timeout );
int32_t sflashWriteSector( flashDeviceT* devicePtr, uint32_t timeout );

int32_t sflashReadDirect(  flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           void* bufferPtr, uint32_t timeout );
int32_t sflashWriteDirect( flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           const void* bufferPtr, uint32_t timeout );

int32_t nflashDetectChip(  flashDeviceT** devicePtrPtr, uint32_t timeout );
int32_t nflashEraseChip(   flashDeviceT* devicePtr, uint32_t timeout );
int32_t nflashEraseSector( flashDeviceT* devicePtr, uint32_t timeout );
int32_t nflashReadSector(  flashDeviceT* devicePtr, uint32_t timeout );
int32_t nflashWriteSector( flashDeviceT* devicePtr, uint32_t timeout );

int32_t nflashReadDirect(  flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           void* bufferPtr, uint32_t timeout );
int32_t nflashWriteDirect( flashDeviceT* devicePtr, uint32_t sectorIndex,
                           uint32_t byteOffset, uint32_t bytes,
                           const void* bufferPtr, uint32_t timeout );

#ifdef __cplusplus
}
#endif

#endif
