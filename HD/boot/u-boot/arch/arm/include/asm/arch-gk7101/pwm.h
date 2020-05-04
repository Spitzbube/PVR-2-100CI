/*
*******************************************************************************
**
** \file          pwm.h
**
** \version    $Id$ 
**
** \brief        support for PWM drivers
**
** \attention	THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**           ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**           OMMISSIONS.
**
** (C) Copyright 2015-2025 by Hunan Goke Microelectronics Co., Ltd.
**
*******************************************************************************
*/

#ifndef PWM_H_
#define PWM_H_

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/
/*!
*******************************************************************************
**
** \brief PWM channel number.
**
**
******************************************************************************/
#define PWM_COUNT       4

typedef enum
{
    NORMAL_SPEED,
    SYNC_SPEED,
}PWM_MODE_E;

typedef union { /* PWM_Control */
    uint all;
    struct {
        uint xon                         : 16;
        uint xoff                        : 16;
    } bitc;
} PWM_CONTROL_S;

typedef union { /* PWM_Control1 */
    uint all;
    struct {
        uint xon                         : 16;
        uint xoff                        : 16;
    } bitc;
} PWM_CONTROL1_S;

typedef union { /* PWM_Enable */
    uint all;
    struct {
        uint enb                         : 1;
        uint                             : 31;
    } bitc;
} PWM_ENABLE_S;

typedef union { /* PWM_Mode */
    uint all;
    struct {
        uint divider                     : 10;
        uint mode                        : 1;
        uint                             : 21;
    } bitc;
} PWM_MODE_S;

/*!
*******************************************************************************
**
** \brief PWM operition modes.
**
** 
**
******************************************************************************/
int  PWM_Cycle(uchar channel,PWM_MODE_E mode,uint divider,ushort xon,ushort xoff);
int  PWM_OnOff(uchar channel, uint on);
int  PWM_Close(uchar channel);


#endif

