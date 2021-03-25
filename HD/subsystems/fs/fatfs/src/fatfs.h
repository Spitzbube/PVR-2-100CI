/*!
*******************************************************************************
**
** \file      ./subsystems/fs/fatfs/include/fatfs.h
** 
** \brief     User API declaration for the FAT12/16/32 filesystem.
**
**            This header file defines all available user functions
**            and datatypes for the EFFS-FAT filesystem provided by HCC.
**
**            (C) Fujitsu Microelectronics Europe 2002 - 2007
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
******************************************************************************/
#ifndef FATFS_H
    #define FATFS_H
    
    #include <fapi/sys_services.h>
    #include "api_f.h"
    
    /*
    *********************************************************************
    *********************************************************************
    ** Data types 
    *********************************************************************
    *********************************************************************
    */
    
    /*!
    *******************************************************************************
    **
    ** \brief Get Date callback function type.
    **
    ** This type of function is accepted as \b getDate callback by 
    ** the initialization function of the FATFS filesystem. 
    **
    ** \param yearPtr  The address where the year should be stored. 
    **                 Valid value range 1980-2107.
    ** \param monthPtr The address where the month of the year should be stored.
    **                 Valid value range 1-12.
    ** \param dayPtr   The address where the day of the month should be stored.
    **                 Valid value range 1-31.
    **
    ** \return One of the following return codes:
    **   - #FAPI_OK                      to indicate successful operation
    **   - #FAPI_ERR_BAD_PARAMETER       to indicate a wrong argument
    **
    ** \sa FATFS_Init
    **
    *******************************************************************************
    */
    typedef int32_t (*FATFS_GetDateCallbackT)(uint16_t* yearPtr, 
                                              uint16_t* monthPtr, 
                                              uint16_t* dayPtr);
    
    /*!
    *******************************************************************************
    **
    ** \brief Get Time callback function type.
    **
    ** This type of function is accepted as \b getTime callback by 
    ** the initialization function of the FATFS filesystem. 
    **
    ** \param hoursPtr   The address where the hours of the day should be stored.
    **                   Valid value range 0-23.
    ** \param minutesPtr The address where the minutes of the hour should be stored.
    **                   Valid value range 0-59.
    ** \param secondsPtr The address where the seconds of the minute should be stored.
    **                   Valid value range 0-59.
    **
    ** \return One of the following return codes:
    **   - #FAPI_OK                      to indicate successful operation
    **   - #FAPI_ERR_BAD_PARAMETER       to indicate a wrong argument
    **
    ** \sa FATFS_Init
    **
    *******************************************************************************
    */
    typedef int32_t (*FATFS_GetTimeCallbackT)(uint16_t* hoursPtr, 
                                              uint16_t* minutesPtr, 
                                              uint16_t* secondsPtr);
    
    
    /*!
    *******************************************************************************
    **
    ** \brief Get Task ID callback function type.
    **
    ** This type of function is accepted as \b getTaskId callback by 
    ** the initialization function of the FATFS filesystem. 
    **
    ** \return The valid unique ID of the current task/thread.
    **
    ** \sa FATFS_Init
    **
    *******************************************************************************
    */
    typedef uint32_t (*FATFS_GetTaskIdCallbackT)(void);
    
    /*!
    *********************************************************************
    *********************************************************************
    ** This structure represents common initialization parameter for the 
    ** FAT filesystem.
    *********************************************************************
    *********************************************************************
    */        
    typedef struct
    {
      /*! 
          Function to obtain the current date. 
          If NULL constant date 1.1.1980 is assumed. 
      */      
      FATFS_GetDateCallbackT getDateFct;
      
      /*!
          Function to obtain the current time. 
          If NULL constant time 12:00:00 is assumed. 
      */
      
      FATFS_GetTimeCallbackT getTimeFct; 
      /*!
          Function to obtain ID of current task. 
          If NULL a single threaded environment is assumed.
      */
      FATFS_GetTaskIdCallbackT getTaskIdFct;
    } FATFS_InitParamsT; 
 
    /*
    *********************************************************************
    *********************************************************************
    **
    ** Public Functions
    **
    *********************************************************************
    *********************************************************************
    */ 
    #ifdef __cplusplus
    extern "C" {
    #endif
    
    int32_t  FATFS_Init( FATFS_InitParamsT* paramsPtr ); 
    
    #ifdef __cplusplus
    }
    #endif
#endif
