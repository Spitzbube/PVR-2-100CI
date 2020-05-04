/*
*******************************************************************************
**
** \file          pwm.c
**
** \version    $Id$
**
** \brief        Generic PWM drivers
**
** \attention	THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**           ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**           OMMISSIONS.
**
** (C) Copyright 2015-2025 by Hunan Goke Microelectronics Co., Ltd.
**
*******************************************************************************
*/

#include <common.h>
#include <asm/io.h>
#include <asm/arch-gk7101/pwm.h>
#include <asm/arch-gk7101/gk7101_reg.h>
#include <asm/arch-gk7101/io.h>

/*
*******************************************************************************
**Funtion Declaration
*******************************************************************************
*/
int pwm_set(unchar channel, PWM_MODE_E mode, uint freq, ushort duty);
int pwm_on_off(unchar channel, uint on);
int pwm_close(unchar channel);
void pwm_set_mode(unchar index, uchar data);
void pwm_set_enable(unchar index, uchar data);
void pwm_set_divider(unchar index, uint divider);
void pwm_set_control(unchar index, uint data);
void pwm_set_control1(unchar index, uint data);


/*
*******************************************************************************
**
** \brief           : Support for PWM driver.
**
** \param [in]    channel:    pwm channel 0~channel 3
**                     mode   :    0    NORMAL_SPEED Mode
**                                     1    SYNC_SPEED Mode
**                     freq     :    pwm output frequency which should be less than 1MHz
**                     duty    :     pwm duty cycle , 1~100 which indicates 1%~100%
**
** \return
**        - 0                          : On success.
**        - -1                        : Invalid parameter
**
*******************************************************************************
*/
int pwm_set(unchar channel, PWM_MODE_E mode, uint freq, ushort duty)
{
    ushort divider = 0;
    ushort xon;
    ushort xoff;
    uint   ampCoeff = 100;
    uint   pwmClk = 2156000;//unit:Hz
    uint   ratio;

    if (freq > 1000000)
    {
        printf("Error: PWM parameter is invalid, the max frequency can be set is 1000000Hz.\n");
        return -1;
    }

    ratio = pwmClk / freq;
    xon = pwmClk / freq * duty / ampCoeff;
    xoff = pwmClk / freq * (100 - duty) / ampCoeff;
    xon--;
    xoff--;

    if (xon == 0 || xoff == 0)
    {
        printf("Error: PWM parameter is invalid, the duty should be 50 in this frequency.\n");
        return -1;
    }

    if(mode == NORMAL_SPEED)
    {
        pwm_set_mode(channel, 0);
        pwm_set_divider(channel, divider);
        pwm_set_control(channel, ((uint)xoff << 16 | (uint)xon));
        //printf("PWM channel: %d, PWM mode: %d, PWM frequency: %dHz, PWM duty cycle: %d%%\n", channel, mode, freq, duty);
    }
    else if(mode == SYNC_SPEED)
    {
        pwm_set_mode(channel, 1);
        pwm_set_divider(channel, divider);
        pwm_set_control1(channel, ((uint)xoff << 16 | (uint)xon));
        //printf("PWM channel: %d, PWM mode: %d, PWM frequency: %dHz, PWM duty cycle: %d%%\n", channel, mode, freq, duty);
    }
}

int pwm_on_off(unchar channel, uint on)
{

    if (on == 0)
    {
        pwm_set_enable(channel, 0);
    }
    else
    {
        pwm_set_enable(channel, 1);
    }
    return 0;
}

int pwm_close(unchar channel)
{
    pwm_set_enable(channel, 0);
    return 0;
}

void pwm_set_mode(unchar index, uchar data)
{
    PWM_MODE_S val;

    val.all = gk_pwm_readl(REG_PWM_MODE + index * 0x00001000);
    val.bitc.mode = data;
    gk_pwm_writel((REG_PWM_MODE + index * 0x00001000), val.all);
}

void pwm_set_enable(unchar index, uchar data)
{
    PWM_ENABLE_S val;

    val.all = gk_pwm_readl(REG_PWM_ENABLE + index * 0x00001000);
    val.bitc.enb = data;
    gk_pwm_writel((REG_PWM_ENABLE + index * 0x00001000), val.all);
}

void pwm_set_divider(unchar index, uint divider)
{
    PWM_MODE_S val;

    val.all = gk_pwm_readl(REG_PWM_MODE + + index * 0x00001000);
    val.bitc.divider = divider;
    gk_pwm_writel((REG_PWM_MODE + index * 0x00001000), val.all);
}

void pwm_set_control(unchar index, uint data)
{
    gk_pwm_writel((REG_PWM_CTRL0 + index * 0x00001000), data);
}

void pwm_set_control1(unchar index, uint data)
{
    gk_pwm_writel((REG_PWM_CTRL1 + index * 0x00001000), data);
}

