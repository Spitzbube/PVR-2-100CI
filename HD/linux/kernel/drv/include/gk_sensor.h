/*!
*****************************************************************************
** \file        linux/kernel/drv/include/gk_sensor.h
**
** \version     $Id: gk_sensor.h 10958 2016-11-14 13:04:26Z yanyong $
**
** \brief
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS
**
** (C) Copyright 2012-2016 by GOKE MICROELECTRONICS CO.,LTD
**
*****************************************************************************
*/
#ifndef _GK_SENSOR_H_
#define _GK_SENSOR_H_



//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************
//32-bit
#ifndef DIV_ROUND
#define DIV_ROUND(divident, divider)    (((divident)+((divider)>>1))/(divider))
#endif

//64-bit
#ifndef DO_DIV_ROUND
#define DO_DIV_ROUND(divident, divider) \
    do                                  \
    {                                   \
        (divident) += ((divider)>>1);   \
        do_div((divident), (divider));  \
    } while (0)
#endif



//*****************************************************************************
//*****************************************************************************
//** Enumerated types
//*****************************************************************************
//*****************************************************************************



//*****************************************************************************
//*****************************************************************************
//** Data Structures
//*****************************************************************************
//*****************************************************************************
typedef struct gk_vi_sensor_s
{
    int (*sensor_set_shutter_time)(int handle, u32 shutter_time, u32 extclk, u32 pclk);
    int (*sensor_set_fps)(int handle, u32 fps, u32 extclk, u32 pclk);
    int (*sensor_set_agc_db)(int handle, s32 agc_db);
    int (*sensor_set_update_reg)(int handle);
}GK_Vi_SensorT;


//*****************************************************************************
//*****************************************************************************
//** Global Data
//*****************************************************************************
//*****************************************************************************



//*****************************************************************************
//*****************************************************************************
//** API Functions
//*****************************************************************************
//*****************************************************************************



#ifdef __cplusplus
extern "C" {
#endif

extern int sensor_write_reg_group_ex(int handle, u32* pdata, u32 len, u32 event_flag);
extern int sensor_write_reg_ex(int handle, u32 subaddr, u32 data, u32 event_flag);
extern int sensor_read_reg_ex(int handle, u32 subaddr, u32* pdata, u32 event_flag);
extern void sensor_registry_api(GK_Vi_SensorT* sensor_api);
extern void sensor_unregistry_api(void);


#ifdef __cplusplus
}
#endif



#endif /* _GK_SENSOR_H_ */

