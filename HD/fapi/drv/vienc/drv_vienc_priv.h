/*
*****************************************************************************
**
** \file        ./fapi/drv/vienc/src/drv_vienc_priv.h
** 
** \brief       Video Encoder private header file.
**
** This file contains the declaration of the Video decoder interrupt handler.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_VIENC_PRIV_H
    #define FAPI_VIENC_PRIV_H

//***********************************************************************
//***********************************************************************
//** Defines
//***********************************************************************
//***********************************************************************
//!********** TOTAL NUM OF ENCODERS SUPPORTED ON DECATE *****************
#define FAPI_VIENC_MAX_NUM_SD_ENCODERS                                0x1
#define FAPI_VIENC_MAX_NUM_HD_ENCODERS                                0x1

#define FAPI_VIENC_MAX_NUM_ENCODERS   (FAPI_VIENC_MAX_NUM_SD_ENCODERS  +\
                                          FAPI_VIENC_MAX_NUM_HD_ENCODERS)

//! "Vienc   " in hex = 0x5669656e63000000U
#define FAPI_VIENC_ID                               0x5669656e63000000ULL
#define FAPI_VIENC_SD_ENCODER_START_ADDRESS   FIO_ADDRESS(VE, 0xCB013000)
#define FAPI_VIENC_HD_ENCODER_START_ADDRESS                             \
                                           FIO_ADDRESS(VE_HD, 0xCB038000)

//***********************************************************************
//***********************************************************************
//** Data types
//***********************************************************************
//***********************************************************************
/*
*************************************************************************
** \brief structure to handle single gpios.
*************************************************************************
*/
typedef struct {
    uint32_t                                         inUse;
    uint32_t                                         number;
    FAPI_SYS_HandleT                                 handle;
}FAPI_VIENC_SingleGpiosParamsT;
/*
*************************************************************************
** \brief structure to handle gpios.
*************************************************************************
*/
typedef struct {
    uint32_t                                         inUse; //0
    FAPI_VIENC_SingleGpiosParamsT                    pin[24]; //4
    FAPI_VIENC_SingleGpiosParamsT                    clk; //292
    FAPI_VIENC_SingleGpiosParamsT                    hSync; //304
    FAPI_VIENC_SingleGpiosParamsT                    vSync; //316
    //328
}FAPI_VIENC_VideoEncoderGpioDataT;
/*
*************************************************************************
** \brief The Handle Data Structure containing the feilds for opening a 
** Video Decoder. It has fields for Video decoder signature and decoder 
** encoderType.
*************************************************************************
*/
typedef struct {
    //Data structure variables
    uint32_t                                         inUse; //0
    char_t                                           coreName[32]; //4
    uint64_t                                         coreID; //36
    uint32_t                                         baseAddress; //44
    uint32_t                                         deviceType; //48
    FAPI_VIENC_OpenParamsT                           opParams; //52 
    uint32_t                                         enableDisable; //76
    uint32_t                                         enableDisableWss; //80
    FAPI_VIENC_ComponentEnumT                        colourComponent; //84
    FAPI_VIENC_VideoEncoderGpioDataT*                gpioDataPtr; //88

    int32_t (*Start)(FAPI_SYS_HandleT handle); //92
    int32_t (*Stop) (FAPI_SYS_HandleT handle); //96
    int32_t (*EnableDisableWss)(FAPI_SYS_HandleT handle,
                                     FAPI_VIENC_ParameterModeEnumT mode); //100
    int32_t (*SetWssData)(FAPI_SYS_HandleT handle, uint32_t wssData); //104
    int32_t (*GetWssData)(FAPI_SYS_HandleT handle, uint32_t* wssData); //108
    int32_t (*SetColourComponent)(FAPI_SYS_HandleT handle, 
                              FAPI_VIENC_ComponentEnumT colourComponent); //112
    int32_t (*GetColourComponent)(FAPI_SYS_HandleT handle, 
                             FAPI_VIENC_ComponentEnumT* colourComponent); //116
    int32_t (*ChangeColourComponent)(FAPI_SYS_HandleT handle,
                                     FAPI_VIENC_ColourSelectorEnumT col,
                                                        uint32_t offset); //120
    //124
} FAPI_VIENC_VideoEncoderHandleT;
//***********************************************************************
//***********************************************************************
//** Global Data
//***********************************************************************
//***********************************************************************

//***********************************************************************
//***********************************************************************
//** API Functions
//***********************************************************************
//***********************************************************************
//-------------------------Locks-----------------------------------------
void vienc_lock(void);
void vienc_unlock(void);
//-------------------------HD--------------------------------------------
int32_t fapi_vienc_hd_start(FAPI_SYS_HandleT handle);
int32_t fapi_vienc_hd_stop(FAPI_SYS_HandleT handle);
int32_t fapi_vienc_hd_setcolourcomponent(FAPI_SYS_HandleT handle, 
                              FAPI_VIENC_ComponentEnumT colourComponent);
int32_t fapi_vienc_hd_getcolourcomponent(FAPI_SYS_HandleT handle, 
                             FAPI_VIENC_ComponentEnumT* colourComponent);
int32_t fapi_vienc_hd_changecolourcomponent(FAPI_SYS_HandleT handle,
                                      FAPI_VIENC_ColourSelectorEnumT col,
                                                        uint32_t offset);
//-------------------------SD--------------------------------------------
int32_t fapi_vienc_sd_start(FAPI_SYS_HandleT handle);
int32_t fapi_vienc_sd_stop(FAPI_SYS_HandleT handle);
int32_t fapi_vienc_sd_enabledisablewss(FAPI_SYS_HandleT handle,
                                     FAPI_VIENC_ParameterModeEnumT mode);
int32_t fapi_vienc_sd_setwssdata(FAPI_SYS_HandleT handle, 
                                                       uint32_t wssData);
int32_t fapi_vienc_sd_getwssdata(FAPI_SYS_HandleT handle, 
                                                      uint32_t* wssData);
int32_t fapi_vienc_sd_setcolourcomponent(FAPI_SYS_HandleT handle, 
                              FAPI_VIENC_ComponentEnumT colourComponent);
int32_t fapi_vienc_sd_getcolourcomponent(FAPI_SYS_HandleT handle, 
                             FAPI_VIENC_ComponentEnumT* colourComponent);
//-------------------------END-------------------------------------------
    #ifdef __cplusplus
    extern "C" {
    #endif


    #ifdef __cplusplus
    }
    #endif
#endif
