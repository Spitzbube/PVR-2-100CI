/*!
********************************************************************************
**
** \file        ./fapi/sys/src/sys_driver.h
**
** \brief       System driver interface.
**
** This file contains the declaration of the system driver interface.
** It must be implemented by each core driver to support the standard
** system intialization with the target environment.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
********************************************************************************
*/

#ifndef FAPI_SYS_DRIVER_H
    #define FAPI_SYS_DRIVER_H

    #ifndef __LINUX__
        #include <stdlib.h>
        #include <stdio.h>
        #include <stdint.h>
        #include <stdchar.h>
        #include <limits.h>
        #include <string.h>
    #else
        #include "fapi_linux_stdhdr.h"
    #endif

    #include <fapi/sys_error.h>

    //**************************************************************************
    //**************************************************************************
    //** Defines and Macros
    //**************************************************************************
    //**************************************************************************
    #define FAPI_SYS_CHECK_VERSION(EXT_VERSION, INT_VERSION) \
                (((EXT_VERSION)>(INT_VERSION)) ? 0 : 1)

    #ifndef __LINUX__
        #define FAPI_DIV64(dividend,divisor) ((dividend)/(divisor))
        #define FAPI_ABS64(n)                (llabs(n))
    #else
    #endif

    //**************************************************************************
    //**************************************************************************
    //** Data types
    //**************************************************************************
    //**************************************************************************

    /*!
    ****************************************************************************
    ** \brief The generic type of a driver handle.
    **
    ** This type represents a handle for a driver instance. It is returned
    ** by the driver's \b Open function and must be provided as first
    ** parameter to each API call.
    ** The content of the handle is driver specific and must not be
    ** interpreted by the system.
    ****************************************************************************
    */
    typedef void* FAPI_SYS_HandleT;

    /*!
    ****************************************************************************
    ** \brief The BSR execution directive type.
    **
    ** This enumeration represents the valid settings for the execution
    ** directive of a driver's background service routine (BSR).
    **
    ** \sa FAPI_SYS_DriverT::bsrExecution
    ****************************************************************************
    */
    typedef enum {

        /*!
        ************************************************************************
        ** \brief Undefined BSR execution.
        **
        ** This setting should be given if either no
        ** FAPI_SYS_DriverT::bsrFunc is registered or if no particular
        ** execution directive exists for the driver. In that case the
        ** operating environment can choose any method it wants.
        ************************************************************************
        */
        FAPI_SYS_BSR_EXEC_UNDEFINED, //0

        /*!
        ************************************************************************
        ** \brief Thread based BSR execution.
        **
        ** This setting must be given if the background service routine
        ** should be executed in thread context.
        ** The operating environment should realize this directive if it
        ** supports threads or tasks. It is responsible to prioritize the
        ** BSR thread in such a way that it will be executed as soon as the
        ** related ISR has been processed.
        **
        ** \note If used within a non-RTOS environment, the application shall
        **       poll the BSR to avoid dead locks.
        ************************************************************************
        */
        FAPI_SYS_BSR_EXEC_THREAD, //1

        /*!
        ************************************************************************
        ** \brief IRQ based BSR execution.
        **
        ** This setting must be given if the background service routine
        ** should be executed in interrupt context. This can either be the
        ** interruptible soft-IRQ context (as for example a tasklet in Linux)
        ** or the hard-IRQ context of the related ISR.
        ************************************************************************
        */
        FAPI_SYS_BSR_EXEC_IRQ, //2
    } FAPI_SYS_BsrExecutionEnumT;


    /*!
    ****************************************************************************
    ** \brief The system driver interface.
    **
    ** This data structure represents the interface to be implemented by
    ** each FAPI core driver. It abstracts from the driver's functionality
    ** and is used by an operating environment for driver registration and
    ** initialization.
    **
    ****************************************************************************
    */
    typedef struct {

        /*!
        ************************************************************************
        ** \brief Pointer to the driver's name.
        **
        ** Each driver should register with a name (e.g. "UART", "TSD", ...)
        ** which the operating environment may use for loging or debuging
        ** purpose.
        ************************************************************************
        */
        const char* driverNamePtr;

        /*!
        ************************************************************************
        ** \brief The IRQ number of the driver.
        **
        ** For an interrupt driven driver this field contains the IRQ number
        ** for which the operating environment should register the ISR.
        ** If the driver doesn't handle an interrupt it must be set to (-1).
        **
        ** \sa isrFunc
        ************************************************************************
        */
        int32_t     irqNo;

        /*!
        ************************************************************************
        ** \brief The execution directive for background service routine (BSR).
        **
        ** This field contains an execution directive to indicate how the
        ** operating environment should call a given BSR. If the environment
        ** has multiple options (soft-IRQ,workqueue,thread,...) it should
        ** consider it to choose the most suitable method.
        **
        ** \sa bsrFunc
        ************************************************************************
        */
        FAPI_SYS_BsrExecutionEnumT bsrExecution;

        /*!
        ************************************************************************
        ** \brief Initialize the driver.
        **
        ** This function initializes the driver. Initialization should be done
        ** with commonly used parameters.
        **
        ** \note This function is \b mandatory. It will be called from the
        **       operating environment during system and device initialization.
        **
        ** \attention
        **       - The function <b>must not</b> call any
        **         <b>FREG_<i>XXXX</i>_Init()</b> function since they will
        **         be called centrally by
        **         #FAPI_SYS_Init().
        **       - During initialization no system services from
        **         #FAPI_SYS_ServicesT
        **         can be used since their particular implementation might
        **         depend on other drivers which are not initialized yet.
        **
        ** \return
        **         - #FAPI_OK if initialization was successful
        **         - (<0) driver specifc error code
        **
        ** \sa exitDriverFunc
        ************************************************************************
        */
        int32_t (*initDriverFunc)(void);

        /*!
        ************************************************************************
        ** \brief Exit the driver.
        **
        ** This function shutdowns the driver and safely disables the hardware
        ** block it controls. Pending accesses should be flushed and all
        ** allocated resources must be released.
        **
        ** \note This function is \b mandatory. It will be called from the
        **       operating environment to stop the device usage.
        **
        ** \sa initDriverFunc
        ************************************************************************
        */
        void (*exitDriverFunc)(void);

        /*!
        ************************************************************************
        ** \brief Interrupt service routine (ISR) of the driver.
        **
        ** This function is needed for each interrupt driven driver. The
        ** operating environment is responsible to call it from its internal
        ** interrupt system if the given IRQ occurs.
        ** The function handles at least the timing critical part of the IRQ.
        ** It should be as short and fast as possible to avoid negative
        ** impacts on overall latency. Time consuming and less critical
        ** operations should be handled in FAPI_SYS_DriverT::bsrFunc.
        **
        ** \attention It is assumed an ISR will not be interrupted.
        **
        ** \attention Since it runs in interrupt context it is not allowed
        **            to use blocking service macros like:
        **            - FAPI_SYS_SLEEP
        **            - FAPI_SYS_GET_SEMAPHORE
        **            - ...
        **
        ** \note This function is \b optional. If the driver doesn't handle
        **       an interrupt it must be set to NULL.
        **
        ** \return
        **         - The IRQ data for background processing. The operating
        **           environment has to take care to pass the data to the
        **           \ref bsrFunc if there is one.
        **         - (0) if no further background processing is required.
        **
        ** \sa irqNo
        ** \sa bsrFunc
        ************************************************************************
        */
        uint32_t (*isrFunc) (void);

        /*!
        ************************************************************************
        ** \brief Background service routine (BSR) of the driver.
        **
        ** This function should be used by an interrupt driven driver to
        ** swap out time consuming but less time critical IRQ operations
        ** to an interruptible part of the operating environment. This can
        ** either be a task or thread or even a soft-IRQ context.
        ** It depends on the capabilities of the operating environment how
        ** the function can actually be executed. However if there are multiple
        ** options the execution directive (FAPI_SYS_DriverT::bsrExecution)
        ** should help to choose the best suitable method in a particular
        ** environment.
        ** In either case the operating environment is responsible to execute
        ** the BSR as soon as the related ISR has been executed.
        **
        ** \attention Since it may run in interrupt or workqueue context
        **            it is not allowed to use blocking service macros like:
        **            - FAPI_SYS_SLEEP
        **            - FAPI_SYS_GET_SEMAPHORE
        **            - ...
        **
        ** \param irqData The IRQ data for background processing provided by
        **                the ISR.
        **
        ** \note This function is \b optional. If the driver doesn't require
        **       background processing it must be set to NULL.
        **
        ** \sa isrFunc
        ** \sa bsrExecution
        ************************************************************************
        */
        void  (*bsrFunc) (uint32_t privData);

        /*!
        ************************************************************************
        ** \brief The stack size to be allocated for the BSR thread.
        **
        ** This field contains a hint for the operating system about the stack
        ** size (in 32-bit long words) to be allocated while creating the
        ** BSR thread.
        ************************************************************************
        */
        uint32_t bsrStackSize;

        /*!
        ************************************************************************
        ** \brief The callback fifo depth to be allocated for the BSR thread.
        **
        ** This field contains a hint for the operating system about the fifo
        ** depth to be allocated while creating the BSR thread.
        ************************************************************************
        */
        uint32_t bsrFifoDepth;
    } FAPI_SYS_DriverT;

    #ifdef __cplusplus
    extern "C" {
    #endif
    #ifdef __cplusplus
    }
    #endif
#endif
