/*!
********************************************************************************
**
** \file        ./fapi/drv/mmu/src/drv_mmu.h
**
** \brief       MMU Driver.
**
** This file contains the declaration of the MMU driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/
#ifndef FAPI_MMU_H
    #define FAPI_MMU_H

    #include <fapi/sys_driver.h>

    //**************************************************************************
    //**************************************************************************
    //** Defines and Macros
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief Version of the MMU driver.
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
    **       FAPI_MMU_OpenParamsT structure.
    **
    ****************************************************************************
    */
    typedef enum
    {
        FAPI_MMU_VERSION = (int32_t)0x00020000 //!< The current driver version
    } FAPI_MMU_VersionEnumT;

    /*!
    ****************************************************************************
    ** \brief Open parameters for the MMU driver.
    **
    ** This data structure covers all parameters which need to be specified
    ** when an instance of the driver is opened.
    **
    ****************************************************************************
    */
    typedef struct
    {
        FAPI_MMU_VersionEnumT version;    //!< The version of the driver. \ref FAPI_MMU_VersionEnumT "FAPI_MMU_VERSION".
        uint32_t              tableIndex; //!< the TLB index, either 0 or 1
    } FAPI_MMU_OpenParamsT;

    /*!
    ** The index to be used in pre-init function calls to setup
    ** FAPI_MMU_HeapHandleSys0 parameters.
    */
    #define FAPI_MMU_HEAP_SEGMENT_INDEX_SYS0     0

    /*!
    ** The index to be used in pre-init function calls to setup
    ** FAPI_MMU_HeapHandleSys1 parameters.
    */
    #define FAPI_MMU_HEAP_SEGMENT_INDEX_SYS1     1

    /*!
    ** The number of heap segment handles which can be allocated.
    */
    #define FAPI_MMU_MAX_SEGMENT_COUNT           8

    /*!
    ** The max. number of heap segment handles which can be pre-initialised.
    ** The first two handles (index '0' and index '1' are generated during
    ** FAPI_MMU_Init() as these heap segments are required by the FAPI and
    ** the RTOS system, all other segments must be created onl the fly by
    ** the application if needed.
    ** - #0 FAPI_MMU_HeapHandleSys0  (uncached, used by most FAPI drivers)
    ** - #1 FAPI_MMU_HeapHandleSys1  (cached, used by FAPI driver and the RTOS)
    */
    #define FAPI_MMU_MAX_PREINIT_COUNT           2

    /*!
    ** Use the first-fit algorithm while searching for an empty space during
    ** allocation of a new heap memory buffer
    */
    #define FAPI_MMU_STRATEGY_FIRSTFIT           1

    /*!
    ** use the best-fit algorithm while searching for an empty space during
    ** allocation of a new heap memory buffer
    */
    #define FAPI_MMU_STRATEGY_BESTFIT            2

    /*!
    ** Use the internal FME memeory chunk alloaction functions
    */
    #define FAPI_MMU_FUNCTION_FME                1

    /*!
    ** Use the open-source 'BGET' library for memory allocation within a
    ** heap segment
    */
    #define FAPI_MMU_FUNCTION_BGET               2

    /*!
    ** Define heap segment as uncached memory area
    */
    #define FAPI_MMU_MEMORY_UNCACHED             1

    /*!
    ** Define heap segment as cached memory area
    */
    #define FAPI_MMU_MEMORY_CACHED               2

    /*!
    ** the number of alignment bits for 8Byte aligned chunks
    */
    #define FAPI_MMU_4BYTE_ALIGNMENT_BITS        2

    /*!
    ** the number of alignment bits for 8Byte aligned chunks
    */
    #define FAPI_MMU_8BYTE_ALIGNMENT_BITS        3

    /*!
    ** the number of alignment bits for 16Byte aligned chunks
    */
    #define FAPI_MMU_16BYTE_ALIGNMENT_BITS       4

    /*!
    ** the number of alignment bits for 32Byte aligned chunks
    */
    #define FAPI_MMU_32BYTE_ALIGNMENT_BITS       5

    /*!
    ** the number of alignment bits for 1KByte aligned chunks
    */
    #define FAPI_MMU_1KBYTE_ALIGNMENT_BITS       10

    /*!
    ** the number of alignment bits for 64KByte aligned chunks
    */
    #define FAPI_MMU_64KBYTE_ALIGNMENT_BITS      16

    /*!
    ** the min. number of alignment bits to be used during allocation
    */
    #define FAPI_MMU_MIN_ALIGNMENT_BITS          FAPI_MMU_8BYTE_ALIGNMENT_BITS

    /*!
    ** the max. number of alignment bits to be used during allocation
    */
    #define FAPI_MMU_MAX_ALIGNMENT_BITS          FAPI_MMU_64KBYTE_ALIGNMENT_BITS

    /*!
    ** the min. segment size in mega bytes.
    */
    #define FAPI_MMU_MIN_SEGMENT_MBYTES          1

    /*!
    ** Use the entire rest of memory for the segment to create, so after
    ** creating a segment of this size no other segment create call can be
    ** made.
    */
    #define FAPI_MMU_MAX_SEGMENT_MBYTES          0xFFF

    /*!
    ****************************************************************************
    ** Standard error codes for the driver
    ****************************************************************************
    */

    /*! Bad parameter passed. */
    #define FAPI_MMU_ERR_BAD_PARAMETER \
            (RTOS_SHARED_MODULE_BASE+FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define FAPI_MMU_ERR_OUT_OF_MEMORY \
             (RTOS_SHARED_MODULE_BASE+FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define FAPI_MMU_ERR_ALREADY_INITIALIZED \
            (RTOS_SHARED_MODULE_BASE+FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define FAPI_MMU_ERR_NOT_INITIALIZED \
            (RTOS_SHARED_MODULE_BASE+FAPI_ERR_NOT_INITIALIZED)

    /*! The driver's used version is not supported. */
    #define FAPI_MMU_ERR_UNSUPPORTED_VERSION \
        (FAPI_MMU_MODULE_BASE+FAPI_ERR_UNSUPPORTED_VERSION)

    /*! Feature or function is not available. */
    #define FAPI_MMU_ERR_FEATURE_NOT_SUPPORTED \
            (RTOS_SHARED_MODULE_BASE+FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Invalid handle was passed. */
    #define FAPI_MMU_ERR_INVALID_HANDLE \
            (RTOS_SHARED_MODULE_BASE+FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define FAPI_MMU_ERR_SEMAPHORE_CREATE \
            (RTOS_SHARED_MODULE_BASE+FAPI_ERR_SEMAPHORE_CREATE)

    /*! Heap segment could not be created. */
    #define FAPI_MMU_ERR_SEGMENT_CREATE \
            (RTOS_SHARED_MODULE_BASE-101)

    //**************************************************************************
    //**************************************************************************
    //** Data types
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief Heap segment creation parameters.
    **
    ** This data structure covers all parameters which need to be specified
    ** while creating a new heap memory segment using the function
    ** FAPI_MMU_CreateSegment().
    ****************************************************************************
    */
    typedef struct {
        /*!
        ** The size in Megabytes to be created as a heap segment, or
        ** #FAPI_MMU_MAX_SEGMENT_MBYTES to alloacte as much memory as
        ** available.
        */
        uint32_t sizeMBytes; //0
        /*!
        ** The type of heap segment to be created, either
        ** #FAPI_MMU_MEMORY_CACHED or #FAPI_MMU_MEMORY_UNCACHED.
        */
        uint32_t memoryMode; //4
        /*!
        ** The type of allocation function to be used, either
        ** #FAPI_MMU_FUNCTION_FME or #FAPI_MMU_FUNCTION_BGET.
        */
        uint32_t functionMode; //8
        /*!
        ** The allocation strategy to be used while allocating new buffers
        ** from the current heap segment. Must be either
        ** #FAPI_MMU_STRATEGY_FIRSTFIT..#FAPI_MMU_STRATEGY_BESTFIT
        */
        uint32_t strategyMode; //12
        /*!
        ** The number of alignment bit to be used for every chunk allocation
        ** ranges from #FAPI_MMU_MIN_ALIGNMENT_BITS..#FAPI_MMU_MAX_ALIGNMENT_BITS,
        ** like #FAPI_MMU_4BYTE_ALIGNMENT_BITS, #FAPI_MMU_8BYTE_ALIGNMENT_BITS,
        ** #FAPI_MMU_16BYTE_ALIGNMENT_BITS, .. #FAPI_MMU_64KBYTE_ALIGNMENT_BITS,
        ** \note This feature can be used only with segments in function
        **       mode #FAPI_MMU_FUNCTION_FME!
        */
        uint32_t alignmentBits; //16
        //20
    } FAPI_MMU_HeapParamsT;

    /*!
    ****************************************************************************
    ** \brief Heap segment information structure.
    **
    ** This data structure covers all parameters returned by the function
    ** FAPI_MMU_GetSegmentInfo().
    ****************************************************************************
    */
    typedef struct {
        /*!
        ** A copy of the FAPI_MMU_HeapParamsT structure passed during the
        ** FAPI_MMU_CreateSegment() call.
        */
        FAPI_MMU_HeapParamsT params;
        /*!
        ** The start address of segment heap memory.
        */
        uint32_t startAddress;
        /*!
        ** The number of unallocated bytes, please note that this size is
        ** just the sum of all availiable free junks.
        */
        uint32_t bytesAvailable;
    } FAPI_MMU_HeapSegmentInfoT;

    //**************************************************************************
    //**************************************************************************
    //** Global Data
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief The global system heap segment for uncached system memory.
    **
    ** This variable is created on the fly during heap initialisation,
    ** it controls the available memory within the uncached heap memory area
    ** used also by FAPI libraries and RTOS functions.
    **
    ****************************************************************************
    */
    extern FAPI_SYS_HandleT FAPI_MMU_HeapHandleSys0;

    /*!
    ****************************************************************************
    ** \brief The global system heap segment for cached system memory.
    **
    ** This variable is created on the fly during heap initialisation,
    ** it controls the available memory within the cached heap memory area
    ** used also by FAPI libraries and RTOS functions.
    **
    ****************************************************************************
    */
    extern FAPI_SYS_HandleT FAPI_MMU_HeapHandleSys1;

    /*!
    ****************************************************************************
    ** \brief The global system heap segment for internal D-TCM data.
    **
    ** This variable is created on the fly during heap initialisation,
    ** it controls the available memory within the internal D-TCM memory
    ** space.
    **
    ****************************************************************************
    */
    extern FAPI_SYS_HandleT FAPI_MMU_HeapHandleDTcm;

    /*!
    ****************************************************************************
    ** \brief The global system heap segment for internal SRAM data.
    **
    ** This variable is created on the fly during heap initialisation,
    ** it controls the available memory within the internal SRAM memory
    ** space.
    **
    ****************************************************************************
    */
    extern FAPI_SYS_HandleT FAPI_MMU_HeapHandleSRam;

    /*!
    ****************************************************************************
    ** \brief The global handle to the MMU driver.
    **
    ** This variable is created on the fly during MMU initialisation,
    ** it is required internally by some MMU API functions.
    **
    ****************************************************************************
    */
    extern FAPI_SYS_DriverT FAPI_MMU_Driver;

    //**************************************************************************
    //**************************************************************************
    //** API Functions
    //**************************************************************************
    //**************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    void             FAPI_MMU_SetSegmentSizeMBytes(uint32_t index,uint32_t sizeMBytes);
    void             FAPI_MMU_SetSegmentStragegyMode(uint32_t index,uint32_t strategyMode);
    void             FAPI_MMU_SetSegmentAlignmentBits(uint32_t index,uint32_t alignmentBits);

    int32_t          FAPI_MMU_Init( void );
    void             FAPI_MMU_Exit( void );
    void             FAPI_MMU_SetTlb1BaseAddr( uint32_t tlb1BaseAddr );
    void             FAPI_MMU_SetTlb2BaseAddr( uint32_t tlb2BaseAddr );
    FAPI_SYS_HandleT FAPI_MMU_Open( FAPI_MMU_OpenParamsT* openParamsPtr, int32_t* errorCodePtr );
    int32_t          FAPI_MMU_Close( FAPI_SYS_HandleT handle );
    uint32_t         FAPI_MMU_GetPhysAddr( uint32_t virtAddr );
    uint32_t         FAPI_MMU_GetVirtAddr( uint32_t physAddr );
    int32_t          FAPI_MMU_ChangeMapEntry( FAPI_SYS_HandleT handle, uint32_t virtAddr,
                                              uint32_t physAddr, uint32_t accessFlags );

    FAPI_SYS_HandleT FAPI_MMU_CreateSegment(const FAPI_MMU_HeapParamsT* paramsPtr,int32_t* errorCodePtr);
    int32_t          FAPI_MMU_ReleaseSegment( FAPI_SYS_HandleT handle );
    FAPI_SYS_HandleT FAPI_MMU_GetSegment( void* memPtr );
    void*            FAPI_MMU_Malloc(FAPI_SYS_HandleT handle, uint32_t bytes);
    void*            FAPI_MMU_Calloc(FAPI_SYS_HandleT handle, uint32_t bytes);
    void*            FAPI_MMU_Realloc(FAPI_SYS_HandleT handle,void* memPtr,uint32_t bytes);
    void*            FAPI_MMU_Free(FAPI_SYS_HandleT handle,void* memPtr);
    FAPI_SYS_HandleT FAPI_MMU_GetSegment( void* memPtr );
    int32_t          FAPI_MMU_GetSegmentInfo( FAPI_SYS_HandleT handle, FAPI_MMU_HeapSegmentInfoT* infoPtr );
    void             FAPI_MMU_ReportMemory(FAPI_SYS_HandleT handle,uint32_t dumpChunks);

    #ifdef __cplusplus
    }
    #endif
#endif
