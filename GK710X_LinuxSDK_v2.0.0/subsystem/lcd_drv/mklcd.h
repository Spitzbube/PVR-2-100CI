/*!
*****************************************************************************
** \file        mklcd.h
**
** \version     $Id: mklcd.h 10214 2016-09-20 11:52:53Z baochao $
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
#ifndef _MKLCD_H_
#define _MKLCD_H_
#include "adi_vout.h"

//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************


//*****************************************************************************
//*****************************************************************************
//** Enumerated types
//*****************************************************************************
//*****************************************************************************

typedef struct
{
    u8 y;
    u8 cb;
    u8 cr;
}GADI_VO_BgColorInfoT;

typedef enum
{
    GADI_VO_LCD_MODE_DISABLE = 0,
    GADI_VO_LCD_MODE_1COLOR_1CYCLE,
    GADI_VO_LCD_MODE_RGB888_3CYCLES,
    GADI_VO_LCD_MODE_RGB565_1CYCLE,
    GADI_VO_LCD_MODE_RGB888_4CYCLES,
    GADI_VO_LCD_MODE_RGB888_1CYCLE,
}GADI_VO_LcdModeInfoEnumT;

typedef enum
{
    GADI_VO_LCD_SEQ_RGB = 0,
    GADI_VO_LCD_SEQ_RBG,
    GADI_VO_LCD_SEQ_GRB,
    GADI_VO_LCD_SEQ_GBR,
    GADI_VO_LCD_SEQ_BRG,
    GADI_VO_LCD_SEQ_BGR,
}GADI_VO_LcdSeqInfoEnumT;

typedef enum
{
    GADI_VO_LCD_CLK_RISING_EDGE    = 0,
    GADI_VO_LCD_CLK_FALLING_EDGE,
}GADI_VO_LcdClkEdgeInfoEnumT;

typedef enum
{
    GADI_VO_SYNC_LOW_ACTIVE   = 0,
    GADI_VO_SYNC_HIGH_ACTIVE  = 1,
}GADI_VO_SyncPolarInfoEnumT;

typedef struct
{
    GADI_VO_SyncPolarInfoEnumT   hsync_polar;
    GADI_VO_SyncPolarInfoEnumT   vsync_polar;

    u16 hsync_back_porch; //Unit--vo_clk_out
    u16 hsync_front_porch;//Unit--vo_clk_out
    u16 vsync_back_porch; //Unit--line
    u16 vsync_front_porch;//Unit--line
    
    u16 vsync_begin_row;//Unit--line
    u16 vsync_end_row;  //Unit--line
    u16 vsync_begin_col;//Unit--vo_clk_out  
    u16 vsync_end_col;  //Unit--vo_clk_out
    u16 hsync_begin_col;//Unit--vo_clk_out
    u16 hsync_end_col;  //Unit--vo_clk_out

}GADI_VO_SyncInfoT;

typedef struct gk_vo_res_info {
    u16 width;
    u16 height;
}GADI_VO_ResInfoT;


typedef struct gk_rgb_hw_info
{
#define GADI_LCD_HW_INFO_MAGIC_START   0x474C4344    // GLCD
    u32                         magic_start;
#define GADI_LCD_HW_INFO_VERSION       0x20160920
    u32                         version;
    u32                         length;             //Bytes of current struct
#define GADI_LCD_HW_INFO_TYPE_RGB      0x00000004  
    u32                         type;               //rgb only

    u32                         file_date;

    GADI_VO_ResInfoT            resolution;         //Output resolution
    GADI_VO_BgColorInfoT        bg_color;           //Background color
    GADI_VO_LcdModeInfoEnumT    mode;               //RGB output mode
    GADI_VO_LcdSeqInfoEnumT     rgb_seq;            //RGB Sequence for 8bit lcd
    
    GADI_VO_LcdClkEdgeInfoEnumT vo_clk_active_edge; //Valid edge for VO output data 
    u32                         vo_clk_in_freq_hz;  //Input clock , 27MHz only
    u8                          vo_clk_div;         //Reserved for future, 1 only

    GADI_VO_SyncInfoT           rgb_sync_timing;    //HSYNC/VSYNC timing
                   
    u8                          back_light;         //0%~100%
#define GADI_LCD_HW_INFO_MAGIC_END     0x4B4C4344   // KLCD
    u32                         magic_end;
}GADI_VO_RgbDrvInfoT;



typedef enum  {
    GADI_VO_I80_8BIT=0,
    GADI_VO_I80_9BIT,
    GADI_VO_I80_16BIT,
    GADI_VO_I80_18BIT,
    GADI_VO_I80_24BIT,
}GADI_VO_I80BusWidthEnumT;

typedef enum  {
    GADI_VO_I80_PIXEL_16BIT=0,
    GADI_VO_I80_PIXEL_18BIT,
    GADI_VO_I80_PIXEL_24BIT,
    GADI_VO_I80_PIXEL_12BIT,
}GADI_VO_I80PixelWidthEnumT;

typedef enum  {//GADI_VO_I80_PIXEL_18BIT only
    GADI_VO_I80_TWICE_1PIXEL = 0,
    GADI_VO_I80_THRICE_2PIXEL,
}GADI_VO_I80TransFormatEnumT;

typedef enum  {
    GADI_VO_I80_CMD_8BIT =0 ,
    GADI_VO_I80_CMD_16BIT,
}GADI_VO_I80CmdWidthEnumT;

typedef enum  {
    GADI_VO_I80_CMD_LITTLE_ENDIAN = 0,    //!< low byte first.
    GADI_VO_I80_CMD_BIG_ENDIAN,           //!< high byte first.
}GADI_VO_I80CmdEndianEnumT;

typedef enum  {
    GADI_VO_I80_LOW_CMD       = 0,
    GADI_VO_I80_HIGH_CMD      = 1,
    GADI_VO_I80_RISING_ACTIVE = 0,
    GADI_VO_I80_FALLING_ACTIVE= 1,
    GADI_VO_I80_LOW_ACTIVE    = 0,
    GADI_VO_I80_HIGH_ACTIVE   = 1,
}GADI_VO_I80PolarEnumT;

typedef struct gk_vo_i80_rst_timing {
    u16 rst_1st_h_ms; //ms
    u16 rst_1st_l_ms; //ms
    u16 rst_2nd_h_ms; //ms
}GADI_VO_I80RstTimingInfoT;

typedef struct gk_vo_i80_trans_timing {
    u16 twrh_ns;//ns
    u16 twrl_ns;//ns
    u16 trdh_ns;//ns
    u16 trdl_ns;//ns
    u16 tas_ns; //ns
    u16 todh_ns;//ns
    u8  csref;//0--wr/rd as reference   1--cs as reference
    u16 pwcsh_wt_ns;//ns when cs_ref=1
    u16 pwcsl_wt_ns;//ns when cs_ref=1
    u16 pwcsh_rd_ns;//ns when cs_ref=1
    u16 pwcsl_rd_ns;//ns when cs_ref=1
}GADI_VO_I80TransTimingInfoT;


typedef struct gk_vo_i80_para {
    GADI_VO_I80BusWidthEnumT        bus_width;      //Width of I80 data bus
    GADI_VO_I80PixelWidthEnumT      pixel_width;    //Width of one pixel
    GADI_VO_I80TransFormatEnumT     trans_format;   //Valid when pixel_width==18bit only
    GADI_VO_I80CmdWidthEnumT        cmd_width;      //Width of I80 command 
    GADI_VO_I80CmdEndianEnumT       cmd_endian;     //Sequence for sending 16-bit command in 8bit data bus
    u16                             wt_cmd;         //Command for writing pixels to LCD model
    u16                             rd_cmd;         //Command for reading pixels from LCD model
    u8                              hw_delay_en;    //Hardware delay(nop) enable
    u16                             hw_delay_cmd;   //Command for delay(nop)
    u16                             hw_delay_ms;    //Delay(nop) time
    GADI_VO_I80PolarEnumT           dc_polar;       //active level for command
    GADI_VO_I80PolarEnumT           cs_polar;       //active edge
    GADI_VO_I80PolarEnumT           lcdrst_polar;   //active level
    GADI_VO_I80PolarEnumT           rd_polar;       //active edge
    GADI_VO_I80PolarEnumT           wt_polar;       //active edge
    GADI_VO_I80RstTimingInfoT       rst_timing;     //Reset lcd model timing
    GADI_VO_I80TransTimingInfoT     trans_timing;   //I80 read&write timing
    u8                              cmd_para_num;   //Number of command and parameter in cmd_para[128]
    u32                             cmd_para[128];
}GADI_VO_I80ParaInfoT;


typedef struct gk_i80_hw_info
{
#define GADI_LCD_HW_INFO_MAGIC_START   0x474C4344    // GLCD
    u32                     magic_start;
#define GADI_LCD_HW_INFO_VERSION       0x20160920
    u32                     version;
    u32                     length;         //Bytes of current struct
#define GADI_LCD_HW_INFO_TYPE_I80      0x00000005  
    u32                     type;           //i80 only
    
    GADI_VO_ResInfoT        resolution;     //Output resolution
    GADI_VO_BgColorInfoT    bg_color;       //Background color

    u32                     file_date;
    GADI_VO_I80ParaInfoT    i80_para;       //I80 parameters
    u8                      back_light;     //0%~100%
#define GADI_LCD_HW_INFO_MAGIC_END     0x4B4C4344    // KLCD
    u32                     magic_end;
}GADI_VO_I80DrvInfoT;

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



#ifdef __cplusplus
}
#endif



#endif /* _MKLCD_H_ */

