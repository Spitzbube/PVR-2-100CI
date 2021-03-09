

#define DEBUG 0

#include <fapi/sys_services.h>
#include <fapi/reg_clkpwr.h>
#include <fapi/reg_gpio.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_ve_hd.h>
#include <fapi/reg_vo.h>
#include <fapi/drv_vienc.h>
#include "drv_vienc_priv.h"


extern int32_t func_21c2ffcc(int a);

static int32_t fapi_vienc_hd_set_color_component_dac_power_down(FAPI_VIENC_VideoEncoderHandleT* h);
static int32_t fapi_vienc_hd_set_color_component_yprpb(FAPI_VIENC_VideoEncoderHandleT* h);
static int32_t fapi_vienc_hd_set_color_component_rgb(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c686e4(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c68298(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c67e50(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c67a08(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c675c0(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t fapi_vienc_set_ip_mode_1920x1080x50i(FAPI_VIENC_VideoEncoderHandleT* h);
static int32_t fapi_vienc_set_ip_mode_1920x1080x5994i(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c66ae0(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c66698(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c66250(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c65e08(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c659c0(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c65578(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c65130(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c64cec(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c648a8(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c64364(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c63fe8(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c63928(FAPI_VIENC_VideoEncoderHandleT* h);
int32_t func_21c635a8(FAPI_VIENC_VideoEncoderHandleT* h);
static int32_t fapi_vienc_set_ip_mode_lcd_640x480x50p_LQ080V3DG01(FAPI_VIENC_VideoEncoderHandleT* h);
static int32_t fapi_vienc_set_ip_mode_lcd_1024x768x50P_SVA150XG10TB(FAPI_VIENC_VideoEncoderHandleT* h);


/* 21c63040 - complete */
int32_t fapi_vienc_hd_set_color_component_dac_power_down(FAPI_VIENC_VideoEncoderHandleT* h)
{
   FREG_VE_SetDacPd_Pddac0(1);
   FREG_VE_SetDacPd_Pddac1(1);
   FREG_VE_SetDacPd_Pddac2(1);
   
   h->colourComponent = h->opParams.colourComponent;

   return 0;
}


/* 21c68f98 - todo (inlined) */
int32_t fapi_vienc_set_ip_mode_1920x1080x5994i(FAPI_VIENC_VideoEncoderHandleT* h)
{
//   uint32_t r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_vienc_set_ip_mode_1920x1080x5994i\n");

//   r6 = 2200;
//   r7 = 562;

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      //21c69688
      res = func_21c2ffcc(1);

      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);

      FREG_VO_SetDisphorll_Disphorll(2200); //r6);
      FREG_VO_SetDispversize_Dispversize(562); //r7);
      FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
      FREG_VO_SetDispvehdsync_Vehdhpos(1);
      FREG_VO_SetDispvehdsync_Vehdvpos(0);
      FREG_VO_SetDispvoversync_Dispvoversync(10);
      FREG_VO_SetDispvercfg_Vercount0(0);
      FREG_VO_SetDispvercfg_Secondfieldoffset(1);
      FREG_VO_SetVomode_Vofieldmode(0);
      FREG_VO_SetVomode_Voprogr(1);
      FREG_VO_SetDisphorll1_Disphorll1field(0);
      FREG_VO_SetDisphorll1_Disphorll1(0xfff);
      FREG_VO_SetDispirq0_Dispirq0enable(1);
      FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
      FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
      FREG_VO_SetDispirq0_Dispverposirq0(
            FREG_VO_GetDispversize_Dispversize() - 15);
      FREG_VO_SetDispirq1_Dispirq1enable(1);
      FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
      FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
      FREG_VO_SetDispirq1_Dispverposirq1(3);
      FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
      FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(45);
      FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
      FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
      FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
      FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
      FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1101);
      FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1101);
      FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(562);
      FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2052);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
      FREG_VO_SetDisphdmideverstartstop_Deverstart(20);
      FREG_VO_SetDisphdmideverstartstop_Deverstop(560);
      FREG_VE_HD_SetVideolinesel_0_Start(20);
      FREG_VE_HD_SetVideolinesel_0_End(560);
      FREG_VE_HD_SetVideolinesel_1_Start(583);
      FREG_VE_HD_SetVideolinesel_1_End(1123);

      FREG_VE_HD_SetLevels_Lev0(0);
      FREG_VE_HD_SetLevels_Lev1(300);
      FREG_VE_HD_SetLevels_Lev2(600);
      FREG_VE_HD_SetYlevels_Lev0(0);
      FREG_VE_HD_SetYlevels_Lev1(300);
      FREG_VE_HD_SetYlevels_Lev2(600);

      FREG_VE_HD_SetVindexCnt_Hsync(2);
      FREG_VE_HD_SetVindexCnt_Max(6);
      FREG_VE_HD_SetFilter_Mode(6);
      FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
      FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(0, 659);
      FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(0, 263); //r9);
      FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
      FREG_VE_HD_SetHindexCnt_Max(0, 4);
      FREG_VE_HD_SetVcnt_Count(0, 9);
      FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(1, 1011);
      FREG_VE_HD_SetHlevcnt_2_Level(1, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(1, 43);
      FREG_VE_HD_SetHindexCnt_Max(1, 2);
      FREG_VE_HD_SetVcnt_Count(1, 1);
      FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(2, 147);
      FREG_VE_HD_SetHlevcnt_2_Level(2, 3);
      FREG_VE_HD_SetHlevcnt_2_Count(2, 1919); //r10);
      FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(2, 43);
      FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
      FREG_VE_HD_SetHindexCnt_Max(2, 4);
      FREG_VE_HD_SetVcnt_Count(2, 555);
      FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(3, 1011);
      FREG_VE_HD_SetHlevcnt_2_Level(3, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(3, 43);
      FREG_VE_HD_SetHindexCnt_Max(3, 2);
      FREG_VE_HD_SetVcnt_Count(3, 0);
      FREG_VE_HD_SetHlevcnt_0_Level(4, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(4, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(4, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(4, 87);
      FREG_VE_HD_SetHlevcnt_2_Level(4, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(4, 659); //r6);
      FREG_VE_HD_SetHlevcnt_3_Level(4, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(4, 263); //r9);
      FREG_VE_HD_SetHlevcnt_4_Level(4, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(4, 43);
      FREG_VE_HD_SetHindexCnt_Max(4, 4);
      FREG_VE_HD_SetVcnt_Count(4, 9);
      FREG_VE_HD_SetHlevcnt_0_Level(5, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(5, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(5, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(5, 1011); //r7);
      FREG_VE_HD_SetHlevcnt_2_Level(5, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(5, 43);
      FREG_VE_HD_SetHindexCnt_Max(5, 2);
      FREG_VE_HD_SetVcnt_Count(5, 0);
      FREG_VE_HD_SetHlevcnt_0_Level(6, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(6, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(6, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(6, 147);
      FREG_VE_HD_SetHlevcnt_2_Level(6, 3);
      FREG_VE_HD_SetHlevcnt_2_Count(6, 1919); //r10);
      FREG_VE_HD_SetHlevcnt_3_Level(6, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(6, 43);
      FREG_VE_HD_SetHlevcnt_4_Level(6, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(6, 43);
      FREG_VE_HD_SetHindexCnt_Max(6, 4);
      FREG_VE_HD_SetVcnt_Count(6, 556);

      FREG_VE_HD_SetEnable_En(1);

      FREG_GPIO_SetConfig_LcdRgbEn(0);

      h->enableDisable = 1;
      //->2193c0bc
   }
   else
   {
      //21c68fa8
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);

      FREG_VO_SetDisphorll_Disphorll(2202);
      FREG_VO_SetDispversize_Dispversize(562);
      FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
      FREG_VO_SetDispvehdsync_Vehdhpos(1);
      FREG_VO_SetDispvehdsync_Vehdvpos(0);
      FREG_VO_SetDispvoversync_Dispvoversync(10);
      FREG_VO_SetDispvercfg_Vercount0(0);
      FREG_VO_SetDispvercfg_Secondfieldoffset(2);
      FREG_VO_SetVomode_Vofieldmode(0);
      FREG_VO_SetVomode_Voprogr(1);
      FREG_VO_SetDisphorll1_Disphorll1field(1);
      FREG_VO_SetDisphorll1_Disphorll1(0xe1);
      FREG_VO_SetDispirq0_Dispirq0enable(1);
      FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
      FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
      FREG_VO_SetDispirq0_Dispverposirq0(
            FREG_VO_GetDispversize_Dispversize() - 15);
      FREG_VO_SetDispirq1_Dispirq1enable(1);
      FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
      FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
      FREG_VO_SetDispirq1_Dispverposirq1(3);
      FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
      FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(45);
      FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
      FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
      FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
      FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
      FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1101);
      FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1101);
      FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(562);
      FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2052);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
      FREG_VO_SetDisphdmideverstartstop_Deverstart(20);
      FREG_VO_SetDisphdmideverstartstop_Deverstop(560);
      FREG_VE_HD_SetVideolinesel_0_Start(20);
      FREG_VE_HD_SetVideolinesel_0_End(560);
      FREG_VE_HD_SetVideolinesel_1_Start(583);
      FREG_VE_HD_SetVideolinesel_1_End(1123);

      FREG_VE_HD_SetLevels_Lev0(0);
      FREG_VE_HD_SetLevels_Lev1(300);
      FREG_VE_HD_SetLevels_Lev2(600);
      FREG_VE_HD_SetYlevels_Lev0(0);
      FREG_VE_HD_SetYlevels_Lev1(300);
      FREG_VE_HD_SetYlevels_Lev2(600);

      FREG_VE_HD_SetVindexCnt_Hsync(2);
      FREG_VE_HD_SetVindexCnt_Max(6);
      FREG_VE_HD_SetFilter_Mode(6);
      FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
      FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(0, 660);
      FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(0, 263); //r9);
      FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
      FREG_VE_HD_SetHindexCnt_Max(0, 4);
      FREG_VE_HD_SetVcnt_Count(0, 9);
      FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(1, 1012);
      FREG_VE_HD_SetHlevcnt_2_Level(1, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(1, 43);
      FREG_VE_HD_SetHindexCnt_Max(1, 2);
      FREG_VE_HD_SetVcnt_Count(1, 1);
      FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(2, 147);
      FREG_VE_HD_SetHlevcnt_2_Level(2, 3);
      FREG_VE_HD_SetHlevcnt_2_Count(2, 1919); //r10);
      FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(2, 45);
      FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
      FREG_VE_HD_SetHindexCnt_Max(2, 4);
      FREG_VE_HD_SetVcnt_Count(2, 555);
      FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(3, 1012);
      FREG_VE_HD_SetHlevcnt_2_Level(3, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(3, 43);
      FREG_VE_HD_SetHindexCnt_Max(3, 2);
      FREG_VE_HD_SetVcnt_Count(3, 0);
      FREG_VE_HD_SetHlevcnt_0_Level(4, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(4, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(4, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(4, 87);
      FREG_VE_HD_SetHlevcnt_2_Level(4, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(4, 660);
      FREG_VE_HD_SetHlevcnt_3_Level(4, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(4, 263); //r9);
      FREG_VE_HD_SetHlevcnt_4_Level(4, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(4, 43);
      FREG_VE_HD_SetHindexCnt_Max(4, 4);
      FREG_VE_HD_SetVcnt_Count(4, 9);
      FREG_VE_HD_SetHlevcnt_0_Level(5, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(5, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(5, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(5, 1012);
      FREG_VE_HD_SetHlevcnt_2_Level(5, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(5, 43);
      FREG_VE_HD_SetHindexCnt_Max(5, 2);
      FREG_VE_HD_SetVcnt_Count(5, 0);
      FREG_VE_HD_SetHlevcnt_0_Level(6, 2);
      FREG_VE_HD_SetHlevcnt_0_Count(6, 43);
      FREG_VE_HD_SetHlevcnt_1_Level(6, 1);
      FREG_VE_HD_SetHlevcnt_1_Count(6, 147);
      FREG_VE_HD_SetHlevcnt_2_Level(6, 3);
      FREG_VE_HD_SetHlevcnt_2_Count(6, 1919); //r10);
      FREG_VE_HD_SetHlevcnt_3_Level(6, 1);
      FREG_VE_HD_SetHlevcnt_3_Count(6, 45);
      FREG_VE_HD_SetHlevcnt_4_Level(6, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(6, 43);
      FREG_VE_HD_SetHindexCnt_Max(6, 4);
      FREG_VE_HD_SetVcnt_Count(6, 556);

      FREG_VE_HD_SetEnable_En(1);

      FREG_GPIO_SetConfig_LcdRgbEn(0);

      h->enableDisable = 1;
   }

   return res;
}


/* 21c63070 - complete */
int32_t fapi_vienc_hd_set_color_component_yprpb(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int32_t res = 0;
   
   FREG_VE_HD_SetYuvrgb_Data(0, 0x108);
   FREG_VE_HD_SetYuvrgb_Data(1, 0);
   FREG_VE_HD_SetYuvrgb_Data(2, 0);
   FREG_VE_HD_SetYuvrgb_Data(3, 0xff0);
   FREG_VE_HD_SetYuvrgb_Data(4, 0);
   FREG_VE_HD_SetYuvrgb_Data(5, 0x100);
   FREG_VE_HD_SetYuvrgb_Data(6, 0);
   FREG_VE_HD_SetYuvrgb_Data(7, 0);
   FREG_VE_HD_SetYuvrgb_Data(8, 0);
   FREG_VE_HD_SetYuvrgb_Data(9, 0);
   FREG_VE_HD_SetYuvrgb_Data(10, 0x100);
   FREG_VE_HD_SetYuvrgb_Data(11, 0);
   
   FREG_VE_HD_SetYlevelshift_Rsh(4);
   FREG_VE_HD_SetYlevelshift_Mul(53);
   FREG_VE_HD_SetYlevelshift_Ofs(245);
   
   FREG_VE_HD_SetCrlevelshift_Rsh(3);
   FREG_VE_HD_SetCrlevelshift_Mul(18);
   FREG_VE_HD_SetCrlevelshift_Ofs(12);
   
   FREG_VE_HD_SetCblevelshift_Rsh(3);
   FREG_VE_HD_SetCblevelshift_Mul(18);
   FREG_VE_HD_SetCblevelshift_Ofs(12);
   
   FREG_VE_SetDacPd_Pddac0(0);
   FREG_VE_SetDacPd_Pddac1(0);
   FREG_VE_SetDacPd_Pddac2(0);

   FREG_VE_HD_SetEnable_ConvEn(0);
   FREG_VE_HD_SetEnable_RgbEn(0);
   
   h->colourComponent = h->opParams.colourComponent;
   
   return res;
}


/* 21c63188 - complete */
int32_t fapi_vienc_hd_set_color_component_rgb(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int32_t res = 0;
   unsigned i = 0;
   
   if (h->opParams.encoderType == FAPI_VIENC_ENCODER_HD)
   {
      FREG_VE_HD_SetYuvrgb_Data(0, 0x12a);
      FREG_VE_HD_SetYuvrgb_Data(1, 0x79c);
      FREG_VE_HD_SetYuvrgb_Data(2, 0x730);
      FREG_VE_HD_SetYuvrgb_Data(3, 0x87);
      FREG_VE_HD_SetYuvrgb_Data(4, 0x12a);
      FREG_VE_HD_SetYuvrgb_Data(5, 0x204);
      FREG_VE_HD_SetYuvrgb_Data(6, 0);
      FREG_VE_HD_SetYuvrgb_Data(7, 0x6ec);
      FREG_VE_HD_SetYuvrgb_Data(8, 0x12a);
      FREG_VE_HD_SetYuvrgb_Data(9, 0);
      FREG_VE_HD_SetYuvrgb_Data(10, 0x199);
      FREG_VE_HD_SetYuvrgb_Data(11, 0x721);
      
      FREG_VE_HD_SetYlevelshift_Rsh(4);
      FREG_VE_HD_SetYlevelshift_Mul(0x35);
      FREG_VE_HD_SetYlevelshift_Ofs(0xf5);
      
      FREG_VE_HD_SetCrlevelshift_Rsh(4);
      FREG_VE_HD_SetCrlevelshift_Mul(0x35);
      FREG_VE_HD_SetCrlevelshift_Ofs(0xf5);
      
      FREG_VE_HD_SetCblevelshift_Rsh(4);
      FREG_VE_HD_SetCblevelshift_Mul(0x35);
      FREG_VE_HD_SetCblevelshift_Ofs(0xf5);
      
      FREG_VE_SetDacPd_Pddac0(0);
      FREG_VE_SetDacPd_Pddac1(0);
      FREG_VE_SetDacPd_Pddac2(0);
      
      FREG_VE_HD_SetEnable_ConvEn(1);
      FREG_VE_HD_SetEnable_RgbEn(1);
   }
   else if (h->opParams.encoderType == FAPI_VIENC_ENCODER_LCD)
   {
      FREG_VO_SetDispmixconfenable_Enablergblut(0);
      FREG_VO_SetDispmixconfenable_Enablergbconv(0);
      FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
      FREG_VO_SetDispmixconfenable_Enableyuvconv(0);
      
      FREG_VO_SetMixyuvrgb_Data(0, 0x12a);
      FREG_VO_SetMixyuvrgb_Data(1, 0x204);
      FREG_VO_SetMixyuvrgb_Data(2, 0);
      FREG_VO_SetMixyuvrgb_Data(3, 0x6ec);
      FREG_VO_SetMixyuvrgb_Data(4, 0x12a);
      FREG_VO_SetMixyuvrgb_Data(5, 0x79c);
      FREG_VO_SetMixyuvrgb_Data(6, 0x730);
      FREG_VO_SetMixyuvrgb_Data(7, 0x87);
      FREG_VO_SetMixyuvrgb_Data(8, 0x12a);
      FREG_VO_SetMixyuvrgb_Data(9, 0);
      FREG_VO_SetMixyuvrgb_Data(10, 0x199);
      FREG_VO_SetMixyuvrgb_Data(11, 0x721);
      
      for (i = 0; i < 256; i++)
      {
         FREG_VO_SetYLut_Value(i, i*4);
         FREG_VO_SetCrLut_Value(i, i*4);
         FREG_VO_SetCbLut_Value(i, i*4);
      }
      
      for (i = 0; i < 1024; i++)
      {
         if (i < 64)
         {
            FREG_VO_SetRLut_Value(i, 64);
            FREG_VO_SetGLut_Value(i, 64);
            FREG_VO_SetBLut_Value(i, 64);
         }
         else if (i > 960)
         {
            FREG_VO_SetRLut_Value(i, 960);
            FREG_VO_SetGLut_Value(i, 960);
            FREG_VO_SetBLut_Value(i, 960);
         }
         else
         {
            FREG_VO_SetRLut_Value(i, i);
            FREG_VO_SetGLut_Value(i, i);
            FREG_VO_SetBLut_Value(i, i);
         }         
      }
      
      FREG_VO_SetMixrgbyuv_Data(2, 0x42);
      FREG_VO_SetMixrgbyuv_Data(1, 0x81);
      FREG_VO_SetMixrgbyuv_Data(0, 0x19);
      FREG_VO_SetMixrgbyuv_Data(3, 0x10);
      FREG_VO_SetMixrgbyuv_Data(6, 0xFFFFFFDA); 
      FREG_VO_SetMixrgbyuv_Data(5, 0xFFFFFFB6); 
      FREG_VO_SetMixrgbyuv_Data(4, 0x70);
      FREG_VO_SetMixrgbyuv_Data(7, 0x80);
      FREG_VO_SetMixrgbyuv_Data(10, 0x70);
      FREG_VO_SetMixrgbyuv_Data(9, 0xFFFFFFA2); 
      FREG_VO_SetMixrgbyuv_Data(8, 0xFFFFFFEE); 
      FREG_VO_SetMixrgbyuv_Data(11, 0x80);
      
      FREG_VO_SetDispmixconfenable_Enablergblut(1);
      FREG_VO_SetDispmixconfenable_Enablergbconv(0);
      FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
      FREG_VO_SetDispmixconfenable_Enableyuvconv(1);
   }
   
   h->colourComponent = h->opParams.colourComponent;

   return res;
}


/* 21c68b30 - todo */
int32_t fapi_vienc_hd_start(FAPI_SYS_HandleT handle)
{
   unsigned i; // = 0;
   int32_t res = 0;
   struct
   {
      uint32_t Data_0;
      uint32_t Data_4;
      uint32_t Data_8;
      uint32_t Data_12;
      uint32_t Data_16;
      uint32_t Data_20;
      uint32_t Data_24;
      uint32_t Data_28;
      uint32_t Data_32;
      uint32_t Data_36;
   } dispdachdmictrl = {0};

   FAPI_VIENC_VideoEncoderHandleT* r5 = handle;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_vienc_hd_start: interlaceProgressive=%d, colourComponent=%d, encoderType=%d\n",
         r5->opParams.interlaceProgressive,
         r5->opParams.colourComponent,
         r5->opParams.encoderType);

   if ((r5->opParams.interlaceProgressive == FAPI_VIENC_UNKNOWN_IP_MODE) ||
         (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_PAL) ||
         (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_NTSC) ||
         (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_SECAM))
   {
      //21c68eb8
      FREG_VE_HD_SetEnable_En(0);

      r5->enableDisable = 0;

      return FAPI_VIENC_ERR_INVALID_COMBINATION_OF_OPEN_PARAMS;
   }

   if (r5->opParams.colourComponent == FAPI_VIENC_UNKNOWN_COLOUR_COMPONENT)
   {
      //21c6952c
      FREG_VE_HD_SetEnable_En(0);

      r5->enableDisable = 0;

      return FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
   }

   if (r5->opParams.encoderType == FAPI_VIENC_ENCODER_HD)
   {
      //->21c68f00
      dispdachdmictrl.Data_0 = FREG_VO_GetDispdachdmictrl_Hdmiiodcnt();
      dispdachdmictrl.Data_4 = FREG_VO_GetDispdachdmictrl_Hdmiiopcnt();
      dispdachdmictrl.Data_8 = FREG_VO_GetDispdachdmictrl_Hdmiidrvcnt();
      dispdachdmictrl.Data_12 = FREG_VO_GetDispdachdmictrl_Hdmiirdten();
      dispdachdmictrl.Data_16 = FREG_VO_GetDispdachdmictrl_Hdmiickh();
      dispdachdmictrl.Data_20 = FREG_VO_GetDispdachdmictrl_Hdmihdcpsel();
      dispdachdmictrl.Data_24 = FREG_VO_GetDispdachdmictrl_Hdmici2ca();

      FREG_CLKPWR_SetSoftreset54_ResetHdmi(0);

      FAPI_SYS_SLEEP(50);

      FREG_CLKPWR_SetConfigvo(0);
      FREG_CLKPWR_SetConfigvo(0x000fffff);

      FREG_CLKPWR_SetSoftreset54_ResetHdmi(1);
   }
   //21c68b90
   i = 0;

   FREG_VO_SetDisphorll_Disphorll(0);
   FREG_VO_SetDispversize_Dispversize(0);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(0);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(0);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(0);
   FREG_VO_SetVomode_Vofieldmode(0);
   FREG_VO_SetVomode_Voprogr(1);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0);
   FREG_VO_SetDispirq0_Dispirq0enable(0);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(0);
   FREG_VO_SetDispirq1_Dispirq1enable(0);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(0);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(0);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(0);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(0);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(0);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(0);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(0);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(0);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(0);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(0);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(0);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(0);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(0);

   FREG_VE_HD_SetVideolinesel_0_Start(0);
   FREG_VE_HD_SetVideolinesel_0_End(0);
   FREG_VE_HD_SetVideolinesel_1_Start(0);
   FREG_VE_HD_SetVideolinesel_1_End(0);
   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(0);
   FREG_VE_HD_SetLevels_Lev2(0);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(0);
   FREG_VE_HD_SetYlevels_Lev2(0);
   FREG_VE_HD_SetVindexCnt_Hsync(0);
   FREG_VE_HD_SetVindexCnt_Max(0);
   FREG_VE_HD_SetFilter_Mode(0);

   for (i = 0; i < 11; i++)
   {
      //21c68d0c
      FREG_VE_HD_SetHindexCnt_Max(i, 0);
      FREG_VE_HD_SetHlevcnt_0_Level(i, 0);
      FREG_VE_HD_SetHlevcnt_0_Count(i, 0);
      FREG_VE_HD_SetHlevcnt_1_Level(i, 0);
      FREG_VE_HD_SetHlevcnt_1_Count(i, 0);
      FREG_VE_HD_SetHlevcnt_2_Level(i, 0);
      FREG_VE_HD_SetHlevcnt_2_Count(i, 0);
      FREG_VE_HD_SetHlevcnt_3_Level(i, 0);
      FREG_VE_HD_SetHlevcnt_3_Count(i, 0);
      FREG_VE_HD_SetHlevcnt_4_Level(i, 0);
      FREG_VE_HD_SetHlevcnt_4_Count(i, 0);
      FREG_VE_HD_SetVcnt_Count(i, 0);
   }
   //21c68da8
   FREG_VE_HD_SetEnable_En(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);

   if (r5->opParams.colourComponent == FAPI_VIENC_COMPONENT_DAC_POWER_DOWN)
   {
      //21c68ed8
      fapi_vienc_hd_set_color_component_dac_power_down(r5);
      //->21c68dc4
   }
   //21c68dc4
   /*else*/ if (r5->opParams.colourComponent == FAPI_VIENC_COMPONENT_RGB)
   {
      //21c68dcc
      fapi_vienc_hd_set_color_component_rgb(r5);
      //21c68dd4
   }
   //21c68ee8
   else if (r5->opParams.colourComponent == FAPI_VIENC_COMPONENT_YPrPb)
   {
      //21c68ef4
      fapi_vienc_hd_set_color_component_yprpb(r5);
      //->21c68dd4
   }
   else
   {
      //21c68eec
      return FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
      //->21c68ecc
   }
   //21c68dd4
   if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x2397P)
   {
      //->21c68f74
      res = func_21c686e4(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x24P)
   {
      //->21c694fc
      res = func_21c68298(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x25P)
   {
      //->21c69638
      res = func_21c67e50(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x2997P)
   {
      //->21c69648
      res = func_21c67a08(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x30P)
   {
      //->21c6950c
      res = func_21c675c0(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x50I)
   {
      //->21c69658
      res = fapi_vienc_set_ip_mode_1920x1080x50i(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x5994I)
   {
      //->21c68f98
      res = fapi_vienc_set_ip_mode_1920x1080x5994i(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1920x1080x60I)
   {
      //->21c69668
      res = func_21c66ae0(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x2397P)
   {
      //->21c69678
      res = func_21c66698(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x24P)
   {
      //->21c69b94
      res = func_21c66250(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x25P)
   {
      //->21c69ba4
      res = func_21c65e08(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x2997P)
   {
      //->21c69bb4
      res = func_21c659c0(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x30P)
   {
      //->21c6951c
      res = func_21c65578(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x50P)
   {
      //->21c69bc4
      res = func_21c65130(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x5994P)
   {
      //->21c69bd4
      res = func_21c64cec(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_1280x720x60P)
   {
      //->21c69be4
      res = func_21c648a8(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_720x576x50I)
   {
      //->21c69bf4
      res = func_21c64364(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_720x576x50P)
   {
      //->21c69d0c
      res = func_21c63fe8(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_720x480x5994I)
   {
      //->21c69d1c
      res = func_21c63928(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_720x480x5994P)
   {
      //->21c69d2c
      res = func_21c635a8(r5);
      //->21c68f80
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_LCD_640x480x50P_LQ080V3DG01)
   {
      //->21c69c04
      res = fapi_vienc_set_ip_mode_lcd_640x480x50p_LQ080V3DG01(r5);
   }
   else if (r5->opParams.interlaceProgressive == FAPI_VIENC_IP_MODE_LCD_1024x768x50P_SVA150XG10TB)
   {
      //21c68e8c
      res = fapi_vienc_set_ip_mode_lcd_1024x768x50P_SVA150XG10TB(r5);
   }
   else
   {
      res = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
      //->21c68f88
   }
   //21c68f80
   if (res == 0)
   {
      //21c694a8
      r5->colourComponent = r5->opParams.colourComponent;

      FREG_VO_SetDisprestart(1);
      FREG_VO_SetDisprestart(0x111);

      FREG_VO_SetDispdachdmictrl_Hdmiiodcnt(dispdachdmictrl.Data_0);
      FREG_VO_SetDispdachdmictrl_Hdmiiopcnt(dispdachdmictrl.Data_4);
      FREG_VO_SetDispdachdmictrl_Hdmiidrvcnt(dispdachdmictrl.Data_8);
      FREG_VO_SetDispdachdmictrl_Hdmiirdten(dispdachdmictrl.Data_12);
      FREG_VO_SetDispdachdmictrl_Hdmiickh(dispdachdmictrl.Data_16);
      FREG_VO_SetDispdachdmictrl_Hdmihdcpsel(dispdachdmictrl.Data_20);
      FREG_VO_SetDispdachdmictrl_Hdmici2ca(dispdachdmictrl.Data_24);
      //->21c68ecc
   }
   else
   {
      //21c68f88
      r5->enableDisable = 0;

      FREG_VE_HD_SetEnable_En(0);
      //->21c68ecc
   }
   //21c68ecc
   return res;
}


/* 21c6356c - complete */
int32_t fapi_vienc_hd_stop(FAPI_SYS_HandleT handle)
{
   int32_t res = 0;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;

   h->enableDisable = 0;

   FREG_VE_HD_SetEnable_En(0);
   FREG_VE_SetDacPd_Pddac0(1);
   FREG_VE_SetDacPd_Pddac1(1);
   FREG_VE_SetDacPd_Pddac2(1);
   FREG_GPIO_SetConfig_LcdRgbEn(0);

   return res;
}


/* 21c63520 - complete */
int32_t fapi_vienc_hd_setcolourcomponent(FAPI_SYS_HandleT handle,
            FAPI_VIENC_ComponentEnumT colourComponent)
{
   int32_t res = 0;
   FAPI_VIENC_VideoEncoderHandleT* h = handle;

   if (colourComponent == FAPI_VIENC_COMPONENT_DAC_POWER_DOWN)
   {
      res = fapi_vienc_hd_set_color_component_dac_power_down(h);
      h->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_RGB)
   {
      res = fapi_vienc_hd_set_color_component_rgb(h);
      h->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_YPrPb)
   {
      res = fapi_vienc_hd_set_color_component_yprpb(h);
      h->colourComponent = colourComponent;
   }
   else
   {
      return FAPI_VIENC_ERR_INVALID_ARGUEMENT_LIST;
   }

   return res;
}


/* 21c68e8c - todo */
int32_t fapi_vienc_set_ip_mode_lcd_1024x768x50P_SVA150XG10TB(FAPI_VIENC_VideoEncoderHandleT* h)
{
   uint32_t r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_vienc_set_ip_mode_lcd_1024x768x50P_SVA150XG10TB\n");

   if (h->opParams.colourComponent != 1)
   {
      //21c68e98
      res = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
   }
   //21c69544
   else if (h->gpioDataPtr->inUse == 0)
   {
      //21c69d4c
      res = FAPI_VIENC_ERR_RGB_GPIOS_ALLOCATION_FAILURE;
   }
   //21c69554
   else if (h->gpioDataPtr->clk.inUse == 0)
   {
      //21c69d44
      res = FAPI_VIENC_ERR_CLOCK_GPIOS_ALLOCATION_FAILURE;
   }
   //21c69560
   else if (h->gpioDataPtr->hSync.inUse == 0)
   {
      //21c69d04
      res = FAPI_VIENC_ERR_HSYNC_GPIOS_ALLOCATION_FAILURE;
   }
   //21c6956c
   else if (h->gpioDataPtr->vSync.inUse == 0)
   {
      //21c69d3c
      res = FAPI_VIENC_ERR_VSYNC_GPIOS_ALLOCATION_FAILURE;
   }

   if (res == 0)
   {
      //21c69578
      FREG_CLKPWR_SetFdclksel_Hdmidivider(4);

      r6 = 1188;
      r7 = 999;

      FREG_VO_SetDisphorll_Disphorll(r6); //1188);
      FREG_VO_SetDispversize_Dispversize(r7); //999);
      FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
      FREG_VO_SetDispvercfg_Vercount0(0);
      FREG_VO_SetDispvercfg_Secondfieldoffset(2);
      FREG_VO_SetVomode_Vofieldmode(1);
      FREG_VO_SetVomode_Voprogr(0);
      FREG_VO_SetDispirq0_Dispirq0enable(1);
      FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
      FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
      FREG_VO_SetDispirq0_Dispverposirq0(
            FREG_VO_GetDispversize_Dispversize() - 15);
      FREG_VO_SetDispirq1_Dispirq1enable(1);
      FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
      FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
      FREG_VO_SetDispirq1_Dispverposirq1(3);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstart(100);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1124);
      FREG_VO_SetDisphdmideverstartstop_Deverstart(20);
      FREG_VO_SetDisphdmideverstartstop_Deverstop(788);
      FREG_VE_HD_SetEnable_En(0);
      FREG_GPIO_SetConfig_LcdRgbEn(1);

      h->enableDisable = 1;
   }
   else
   {
      FREG_VE_HD_SetEnable_En(0);
      FREG_GPIO_SetConfig_LcdRgbEn(0);

      h->enableDisable = 0;
   }

   return res;
}


/* 21c69c04 - todo */
int32_t fapi_vienc_set_ip_mode_lcd_640x480x50p_LQ080V3DG01(FAPI_VIENC_VideoEncoderHandleT* h)
{
   uint32_t r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_vienc_set_ip_mode_lcd_640x480x50p_LQ080V3DG01\n");

   if (h->opParams.colourComponent != 1)
   {
      //21c68e98
      res = FAPI_VIENC_ERR_INVALID_OPEN_PARAMS;
   }
   //21c69c10
   else if (h->gpioDataPtr->inUse == 0)
   {
      //21c69d4c
      res = FAPI_VIENC_ERR_RGB_GPIOS_ALLOCATION_FAILURE;
   }
   //21c69c20
   else if (h->gpioDataPtr->clk.inUse == 0)
   {
      //21c69d44
      res = FAPI_VIENC_ERR_CLOCK_GPIOS_ALLOCATION_FAILURE;
   }
   //21c69c2c
   else if (h->gpioDataPtr->hSync.inUse == 0)
   {
      //21c69d04
      res = FAPI_VIENC_ERR_HSYNC_GPIOS_ALLOCATION_FAILURE;
   }
   //21c69c38
   else if (h->gpioDataPtr->vSync.inUse == 0)
   {
      //21c69d3c
      res = FAPI_VIENC_ERR_VSYNC_GPIOS_ALLOCATION_FAILURE;
   }

   if (res == 0)
   {
      //21c69c44
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);

      r6 = 864;
      r7 = 624;

      FREG_VO_SetDisphorll_Disphorll(r6); //864);
      FREG_VO_SetDispversize_Dispversize(r7); //624);
      FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
      FREG_VO_SetDispvercfg_Vercount0(0);
      FREG_VO_SetDispvercfg_Secondfieldoffset(2);
      FREG_VO_SetVomode_Vofieldmode(1);
      FREG_VO_SetVomode_Voprogr(0);
      FREG_VO_SetDispirq0_Dispirq0enable(1);
      FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
      FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
      FREG_VO_SetDispirq0_Dispverposirq0(
            FREG_VO_GetDispversize_Dispversize() - 15);
      FREG_VO_SetDispirq1_Dispirq1enable(1);
      FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
      FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
      FREG_VO_SetDispirq1_Dispverposirq1(3);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstart(132);
      FREG_VO_SetDisphdmidehorstartstop_Dehorstop(772);
      FREG_VO_SetDisphdmideverstartstop_Deverstart(23);
      FREG_VO_SetDisphdmideverstartstop_Deverstop(503);
      FREG_VE_HD_SetEnable_En(0);
      FREG_GPIO_SetConfig_LcdRgbEn(1);

      h->enableDisable = 1;
   }
   else
   {
      FREG_VE_HD_SetEnable_En(0);
      FREG_GPIO_SetConfig_LcdRgbEn(0);

      h->enableDisable = 0;
   }

   return res;
}


/* 21c635a8 - complete */
int32_t func_21c635a8(FAPI_VIENC_VideoEncoderHandleT* h)
{
//   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c635a8\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);      
   }

   FREG_VO_SetDisphorll_Disphorll(858);
   FREG_VO_SetDispversize_Dispversize(524);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(63);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(6);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(0);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2054);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2048);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(123);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(843);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(36);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(516);
   FREG_VE_HD_SetVideolinesel_0_Start(36);
   FREG_VE_HD_SetVideolinesel_0_End(516);
   FREG_VE_HD_SetVideolinesel_1_Start(561);
   FREG_VE_HD_SetVideolinesel_1_End(1041);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 793);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 63);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 61);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 719);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 11);
   FREG_VE_HD_SetVcnt_Count(1, 519);
   FREG_VE_HD_SetHindexCnt_Max(2, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 793);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 63);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 61);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 719);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 11);
   FREG_VE_HD_SetVcnt_Count(3, 519);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c63928 - complete */
int32_t func_21c63928(FAPI_VIENC_VideoEncoderHandleT* h)
{
//   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c63928\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }

//   r6 = 1716;
//   r7 = 262;
   
   FREG_VO_SetDisphorll_Disphorll(1716); //r6);
   FREG_VO_SetDispversize_Dispversize(262); //r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(1);
   FREG_VO_SetVomode_Vofieldmode(0);
   FREG_VO_SetVomode_Voprogr(1);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 10);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(125);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(3);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(0);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(897);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(897);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2050);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(262);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(239);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1679);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(18);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(258);
   FREG_VE_HD_SetVideolinesel_0_Start(18);
   FREG_VE_HD_SetVideolinesel_0_End(258);
   FREG_VE_HD_SetVideolinesel_1_Start(281);
   FREG_VE_HD_SetVideolinesel_1_End(521);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(9);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 793);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 63);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 793);
   FREG_VE_HD_SetVcnt_Count(0, 2);
   FREG_VE_HD_SetHindexCnt_Max(1, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 729);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 127);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 729);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 127);
   FREG_VE_HD_SetVcnt_Count(1, 2);
   FREG_VE_HD_SetHindexCnt_Max(2, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 793);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 63);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 793);
   FREG_VE_HD_SetVcnt_Count(2, 2);
   FREG_VE_HD_SetHindexCnt_Max(3, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 127);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 107);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1439);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 252);
   FREG_VE_HD_SetHindexCnt_Max(4, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(4, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(4, 127);
   FREG_VE_HD_SetHlevcnt_1_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(4, 107);
   FREG_VE_HD_SetHlevcnt_2_Level(4, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(4, 581);
   FREG_VE_HD_SetHlevcnt_3_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(4, 39);
   FREG_VE_HD_SetVcnt_Count(4, 0);
   FREG_VE_HD_SetHindexCnt_Max(5, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(5, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(5, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(5, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(5, 793);
   FREG_VE_HD_SetHlevcnt_2_Level(5, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(5, 63);
   FREG_VE_HD_SetHlevcnt_3_Level(5, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(5, 793);
   FREG_VE_HD_SetVcnt_Count(5, 2);
   FREG_VE_HD_SetHindexCnt_Max(6, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(6, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(6, 729);
   FREG_VE_HD_SetHlevcnt_1_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(6, 127);
   FREG_VE_HD_SetHlevcnt_2_Level(6, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(6, 729);
   FREG_VE_HD_SetHlevcnt_3_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(6, 127);
   FREG_VE_HD_SetVcnt_Count(6, 2);
   FREG_VE_HD_SetHindexCnt_Max(7, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(7, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(7, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(7, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(7, 793);
   FREG_VE_HD_SetHlevcnt_2_Level(7, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(7, 63);
   FREG_VE_HD_SetHlevcnt_3_Level(7, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(7, 793);
   FREG_VE_HD_SetVcnt_Count(7, 2);
   FREG_VE_HD_SetHindexCnt_Max(8, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(8, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(8, 127);
   FREG_VE_HD_SetHlevcnt_1_Level(8, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(8, 107);
   FREG_VE_HD_SetHlevcnt_2_Level(8, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(8, 581);
   FREG_VE_HD_SetHlevcnt_3_Level(8, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(8, 39);
   FREG_VE_HD_SetVcnt_Count(8, 0);
   FREG_VE_HD_SetHindexCnt_Max(9, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(9, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(9, 127);
   FREG_VE_HD_SetHlevcnt_1_Level(9, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(9, 107);
   FREG_VE_HD_SetHlevcnt_2_Level(9, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(9, 1439);
   FREG_VE_HD_SetHlevcnt_3_Level(9, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(9, 39);
   FREG_VE_HD_SetVcnt_Count(9, 252);

   FREG_VE_HD_SetEnable_En(1);

   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* func_21c63fe8 - complete */
int32_t func_21c63fe8(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c63fe8\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);

      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }

   FREG_VO_SetDisphorll_Disphorll(864);
   FREG_VO_SetDispversize_Dispversize(624);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);

   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(65);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(5);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(0);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2053);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2048);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(133);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(853);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(44);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(620);
   FREG_VE_HD_SetVideolinesel_0_Start(44);
   FREG_VE_HD_SetVideolinesel_0_End(620);
   FREG_VE_HD_SetVideolinesel_1_Start(669);
   FREG_VE_HD_SetVideolinesel_1_End(1245);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 799);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 63);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 67);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 719);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 11);
   FREG_VE_HD_SetVcnt_Count(1, 619);
   FREG_VE_HD_SetHindexCnt_Max(2, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 799);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 63);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 67);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 719);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 11);
   FREG_VE_HD_SetVcnt_Count(3, 619);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c64364 - complete */
int32_t func_21c64364(FAPI_VIENC_VideoEncoderHandleT* h)
{
//   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c64364\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(10);
   }

//   r6 = 1728;
//   r7 = 312;
   
   FREG_VO_SetDisphorll_Disphorll(1728); //r6);
   FREG_VO_SetDispversize_Dispversize(312); //r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(1);
   FREG_VO_SetVomode_Vofieldmode(0);
   FREG_VO_SetVomode_Voprogr(1);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 10);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(127);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(3);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(0);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(865);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(865);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2050);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(312);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(265);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1705);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(22);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(310);
   FREG_VE_HD_SetVideolinesel_0_Start(22);
   FREG_VE_HD_SetVideolinesel_0_End(310);
   FREG_VE_HD_SetVideolinesel_1_Start(335);
   FREG_VE_HD_SetVideolinesel_1_End(623);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(2);
   FREG_VE_HD_SetVindexCnt_Max(9);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 735);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 127);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 799);
   FREG_VE_HD_SetVcnt_Count(1, 4);
   FREG_VE_HD_SetHindexCnt_Max(2, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 125);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 137);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1439);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 23);
   FREG_VE_HD_SetVcnt_Count(2, 304);
   FREG_VE_HD_SetHindexCnt_Max(3, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 799);
   FREG_VE_HD_SetVcnt_Count(3, 4);
   FREG_VE_HD_SetHindexCnt_Max(4, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(4, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(4, 735);
   FREG_VE_HD_SetHlevcnt_1_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(4, 127);
   FREG_VE_HD_SetVcnt_Count(4, 4);
   FREG_VE_HD_SetHindexCnt_Max(5, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(5, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(5, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(5, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(5, 799);
   FREG_VE_HD_SetVcnt_Count(5, 4);
   FREG_VE_HD_SetHindexCnt_Max(6, 0);
   FREG_VE_HD_SetHlevcnt_0_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_0_Count(6, 863);
   FREG_VE_HD_SetVcnt_Count(6, 0);
   FREG_VE_HD_SetHindexCnt_Max(7, 3);
   FREG_VE_HD_SetHlevcnt_0_Level(7, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(7, 125);
   FREG_VE_HD_SetHlevcnt_1_Level(7, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(7, 137);
   FREG_VE_HD_SetHlevcnt_2_Level(7, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(7, 1439);
   FREG_VE_HD_SetHlevcnt_3_Level(7, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(7, 23);
   FREG_VE_HD_SetVcnt_Count(7, 303);
   FREG_VE_HD_SetHindexCnt_Max(8, 2);
   FREG_VE_HD_SetHlevcnt_0_Level(8, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(8, 127);
   FREG_VE_HD_SetHlevcnt_1_Level(8, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(8, 119);
   FREG_VE_HD_SetHlevcnt_2_Level(8, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(8, 615);
   FREG_VE_HD_SetVcnt_Count(8, 0);
   FREG_VE_HD_SetHindexCnt_Max(9, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(9, 0);
   FREG_VE_HD_SetHlevcnt_0_Count(9, 63);
   FREG_VE_HD_SetHlevcnt_1_Level(9, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(9, 799);
   FREG_VE_HD_SetVcnt_Count(9, 4);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c648a8 - complete */
int32_t func_21c648a8(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c648a8\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   r6 = 1650;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c64cec - complete */
int32_t func_21c64cec(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c64cec\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(1);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   r6 = 1650;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 69);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c65130 - complete */
int32_t func_21c65130(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c65130\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   r6 = 1980;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 399);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 399);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 399);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 399);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c65578 - complete */
int32_t func_21c65578(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c65578\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }

   r6 = 3300;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c659c0 - complete */
int32_t func_21c659c0(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c659c0\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(1); //218bed54
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }

   r6 = 3300;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c65e08 - complete */
int32_t func_21c65e08(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c65e08\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   r6 = 3960;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 2379);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 2379);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 2379);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 2379);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c66250 - complete */
int32_t func_21c66250(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c66250\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
   }

   r6 = 3300;
   r7 = 749;

   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);

   FREG_VE_HD_SetEnable_En(1);

   FREG_GPIO_SetConfig_LcdRgbEn(0);

   h->enableDisable = 1;
   
   return res;
}


/* 21c66698 - complete */
int32_t func_21c66698(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c66698\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(1); //218bed54
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(4);
   }

   r6 = 3300;
   r7 = 749;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(261);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(1541);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(25);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(745);
   FREG_VE_HD_SetVideolinesel_0_Start(25);
   FREG_VE_HD_SetVideolinesel_0_End(745);
   FREG_VE_HD_SetVideolinesel_1_Start(775);
   FREG_VE_HD_SetVideolinesel_1_End(1495);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 39);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 39);
   FREG_VE_HD_SetVcnt_Count(1, 744);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 39);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 39);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 219);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1279);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 1719);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 39);
   FREG_VE_HD_SetVcnt_Count(3, 744);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c66ae0 - complete */
int32_t func_21c66ae0(FAPI_VIENC_VideoEncoderHandleT* h)
{
   //int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c66ae0\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0); //218bed54
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

//   r6 = 2640;
//   r7 = 562;
   
   FREG_VO_SetDisphorll_Disphorll(2200); //r6);
   FREG_VO_SetDispversize_Dispversize(562); //r7);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(1);
   FREG_VO_SetVomode_Vofieldmode(0);
   FREG_VO_SetVomode_Voprogr(1);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(45);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1101);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1101);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(562);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2052);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(20);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(560);
   FREG_VE_HD_SetVideolinesel_0_Start(20);
   FREG_VE_HD_SetVideolinesel_0_End(560);
   FREG_VE_HD_SetVideolinesel_1_Start(583);
   FREG_VE_HD_SetVideolinesel_1_End(1123);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(2);
   FREG_VE_HD_SetVindexCnt_Max(6);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 659);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 263);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetVcnt_Count(0, 9);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 1011);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 43);
   FREG_VE_HD_SetHindexCnt_Max(1, 2);
   FREG_VE_HD_SetVcnt_Count(1, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetVcnt_Count(2, 555);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 1011);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 43);
   FREG_VE_HD_SetHindexCnt_Max(3, 2);
   FREG_VE_HD_SetVcnt_Count(3, 0);
   FREG_VE_HD_SetHlevcnt_0_Level(4, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(4, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(4, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(4, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(4, 659);
   FREG_VE_HD_SetHlevcnt_3_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(4, 263);
   FREG_VE_HD_SetHlevcnt_4_Level(4, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(4, 43);
   FREG_VE_HD_SetHindexCnt_Max(4, 4);
   FREG_VE_HD_SetVcnt_Count(4, 9);
   FREG_VE_HD_SetHlevcnt_0_Level(5, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(5, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(5, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(5, 1011);
   FREG_VE_HD_SetHlevcnt_2_Level(5, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(5, 43);
   FREG_VE_HD_SetHindexCnt_Max(5, 2);
   FREG_VE_HD_SetVcnt_Count(5, 0);
   FREG_VE_HD_SetHlevcnt_0_Level(6, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(6, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(6, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(6, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(6, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(6, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(6, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(6, 43);
   FREG_VE_HD_SetHindexCnt_Max(6, 4);
   FREG_VE_HD_SetVcnt_Count(6, 556);

   FREG_VE_HD_SetEnable_En(1);

   FREG_GPIO_SetConfig_LcdRgbEn(0);

   h->enableDisable = 1;

   return res;
}


/* 21c67050 - complete */
int32_t fapi_vienc_set_ip_mode_1920x1080x50i(FAPI_VIENC_VideoEncoderHandleT* r4)
{
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "fapi_vienc_set_ip_mode_1920x1080x50i\n");

   if (r4->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0);
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   FREG_VO_SetDisphorll_Disphorll(2640);
   FREG_VO_SetDispversize_Dispversize(562);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(0);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(1);
   FREG_VO_SetVomode_Vofieldmode(0);
   FREG_VO_SetVomode_Voprogr(1);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(45);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1321);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1321);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(562);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2052);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(20);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(560);
   FREG_VE_HD_SetVideolinesel_0_Start(20);
   FREG_VE_HD_SetVideolinesel_0_End(560);
   FREG_VE_HD_SetVideolinesel_1_Start(583);
   FREG_VE_HD_SetVideolinesel_1_End(1123);
   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);
   FREG_VE_HD_SetVindexCnt_Hsync(2);
   FREG_VE_HD_SetVindexCnt_Max(6);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 879);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 263);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetVcnt_Count(0, 9);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 1231);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 43);
   FREG_VE_HD_SetHindexCnt_Max(1, 2);
   FREG_VE_HD_SetVcnt_Count(1, 1);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 483);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetVcnt_Count(2, 555);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 1231);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 43);
   FREG_VE_HD_SetHindexCnt_Max(3, 2);
   FREG_VE_HD_SetVcnt_Count(3, 0);
   FREG_VE_HD_SetHlevcnt_0_Level(4, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(4, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(4, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(4, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(4, 879);
   FREG_VE_HD_SetHlevcnt_3_Level(4, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(4, 263);
   FREG_VE_HD_SetHlevcnt_4_Level(4, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(4, 43);
   FREG_VE_HD_SetHindexCnt_Max(4, 4);
   FREG_VE_HD_SetVcnt_Count(4, 9);
   FREG_VE_HD_SetHlevcnt_0_Level(5, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(5, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(5, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(5, 1231);
   FREG_VE_HD_SetHlevcnt_2_Level(5, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(5, 43);
   FREG_VE_HD_SetHindexCnt_Max(5, 2);
   FREG_VE_HD_SetVcnt_Count(5, 0);
   FREG_VE_HD_SetHlevcnt_0_Level(6, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(6, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(6, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(6, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(6, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(6, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(6, 483);
   FREG_VE_HD_SetHlevcnt_4_Level(6, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(6, 43);
   FREG_VE_HD_SetHindexCnt_Max(6, 4);
   FREG_VE_HD_SetVcnt_Count(6, 556);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   r4->enableDisable = 1;
   
   return res;
}


/* 21c675c0 - complete */
int32_t func_21c675c0(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c675c0\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0); //218bed54
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   r6 = 2200;
   r7 = 1124;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7); //1124);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(41);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(1121);
   FREG_VE_HD_SetVideolinesel_0_Start(41);
   FREG_VE_HD_SetVideolinesel_0_End(1121);
   FREG_VE_HD_SetVideolinesel_1_Start(1166);
   FREG_VE_HD_SetVideolinesel_1_End(2246);
   
   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);
   
   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 43);
   FREG_VE_HD_SetVcnt_Count(1, 1119);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 43);
   FREG_VE_HD_SetVcnt_Count(3, 1119);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c67a08 - complete */
int32_t func_21c67a08(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c67a08\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(1); //218bed54
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);      
   }

   r6 = 2200;
   r7 = 1124;
   
   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7); //1124);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(41);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(1121);
   FREG_VE_HD_SetVideolinesel_0_Start(41);
   FREG_VE_HD_SetVideolinesel_0_End(1121);
   FREG_VE_HD_SetVideolinesel_1_Start(1166);
   FREG_VE_HD_SetVideolinesel_1_End(2246);
   
   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);
   
   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 43);
   FREG_VE_HD_SetVcnt_Count(1, 1119);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 43);
   FREG_VE_HD_SetVcnt_Count(3, 1119);
   
   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


/* 21c67e50 - complete */
int32_t func_21c67e50(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c67e50\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0); //218bed54

      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }

   r6 = 2640;
   r7 = 1124;

   FREG_VO_SetDisphorll_Disphorll(r6);
   FREG_VO_SetDispversize_Dispversize(r7); //1124);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);
   
   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(41);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(1121);
   FREG_VE_HD_SetVideolinesel_0_Start(41);
   FREG_VE_HD_SetVideolinesel_0_End(1121);
   FREG_VE_HD_SetVideolinesel_1_Start(1166);
   FREG_VE_HD_SetVideolinesel_1_End(2246);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 483);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 483);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 43);
   FREG_VE_HD_SetVcnt_Count(1, 1119);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 483);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 483);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 43);
   FREG_VE_HD_SetVcnt_Count(3, 1119);

   FREG_VE_HD_SetEnable_En(1);

   FREG_GPIO_SetConfig_LcdRgbEn(0);

   h->enableDisable = 1;

   return res;
}


/* 21c68298 - complete */
int32_t func_21c68298(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c68298\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(0); //218bed54
      
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }

   r6 = 2750;
   r7 = 1124;

   FREG_VO_SetDisphorll_Disphorll(r6); //2750);
   FREG_VO_SetDispversize_Dispversize(r7); //1124);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);

   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(41);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(1121);
   FREG_VE_HD_SetVideolinesel_0_Start(41);
   FREG_VE_HD_SetVideolinesel_0_End(1121);
   FREG_VE_HD_SetVideolinesel_1_Start(1166);
   FREG_VE_HD_SetVideolinesel_1_End(2246);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 43);
   FREG_VE_HD_SetVcnt_Count(1, 1119);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 43);
   FREG_VE_HD_SetVcnt_Count(3, 1119);

   FREG_VE_HD_SetEnable_En(1);

   FREG_GPIO_SetConfig_LcdRgbEn(0);

   h->enableDisable = 1;

   return res;
}


/* 21c686e4 - complete */
int32_t func_21c686e4(FAPI_VIENC_VideoEncoderHandleT* h)
{
   int r6, r7;
   int32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "func_21c686e4\n");

   if (h->deviceType == FAPI_SYS_DEVICE_ID_MB86H60B)
   {
      res = func_21c2ffcc(1); //218bed54

      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }
   else
   {
      FREG_CLKPWR_SetFdclksel_Hdmidivider(3);
   }

   r6 = 2750;
   r7 = 1124;

   FREG_VO_SetDisphorll_Disphorll(r6); //2750);
   FREG_VO_SetDispversize_Dispversize(r7); //1124);
   FREG_VO_SetDispvehdsync_Vehdfieldsync(1);
   FREG_VO_SetDispvehdsync_Vehdhpos(1);
   FREG_VO_SetDispvehdsync_Vehdvpos(0);
   FREG_VO_SetDispvoversync_Dispvoversync(10);
   FREG_VO_SetDispvercfg_Vercount0(0);
   FREG_VO_SetDispvercfg_Secondfieldoffset(2);
   FREG_VO_SetVomode_Vofieldmode(1);
   FREG_VO_SetVomode_Voprogr(0);
   FREG_VO_SetDisphorll1_Disphorll1field(0);
   FREG_VO_SetDisphorll1_Disphorll1(0xfff);

   FREG_VO_SetDispirq0_Dispirq0enable(1);
   FREG_VO_SetDispirq0_Dispfiedframeirq0(0);
   FREG_VO_SetDispirq0_Dispfiedirq0sel(0);
   FREG_VO_SetDispirq0_Dispverposirq0(
         FREG_VO_GetDispversize_Dispversize() - 15);

   FREG_VO_SetDispirq1_Dispirq1enable(1);
   FREG_VO_SetDispirq1_Dispfiedframeirq1(0);
   FREG_VO_SetDispirq1_Dispfiedirq1sel(0);
   FREG_VO_SetDispirq1_Dispverposirq1(3);

   FREG_VO_SetDispsynchorstartstop_Dispsynchorstart(1);
   FREG_VO_SetDispsynchorstartstop_Dispsynchorstop(41);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1start(1);
   FREG_VO_SetDispsynchor1startstop_Dispsynchor1stop(1);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1start(0);
   FREG_VO_SetDispsyncver1startstop_Dispsyncver1stop(5);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2start(1);
   FREG_VO_SetDispsynchor2startstop_Dispsynchor2stop(1);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2start(2048);
   FREG_VO_SetDispsyncver2startstop_Dispsyncver2stop(2053);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstart(193);
   FREG_VO_SetDisphdmidehorstartstop_Dehorstop(2113);
   FREG_VO_SetDisphdmideverstartstop_Deverstart(41);
   FREG_VO_SetDisphdmideverstartstop_Deverstop(1121);
   FREG_VE_HD_SetVideolinesel_0_Start(41);
   FREG_VE_HD_SetVideolinesel_0_End(1121);
   FREG_VE_HD_SetVideolinesel_1_Start(1166);
   FREG_VE_HD_SetVideolinesel_1_End(2246);

   FREG_VE_HD_SetLevels_Lev0(0);
   FREG_VE_HD_SetLevels_Lev1(300);
   FREG_VE_HD_SetLevels_Lev2(600);
   FREG_VE_HD_SetYlevels_Lev0(0);
   FREG_VE_HD_SetYlevels_Lev1(300);
   FREG_VE_HD_SetYlevels_Lev2(600);

   FREG_VE_HD_SetVindexCnt_Hsync(3);
   FREG_VE_HD_SetVindexCnt_Max(3);
   FREG_VE_HD_SetFilter_Mode(6);
   FREG_VE_HD_SetHindexCnt_Max(0, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(0, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(0, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(0, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(0, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(0, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(0, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(0, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(0, 43);
   FREG_VE_HD_SetVcnt_Count(0, 4);
   FREG_VE_HD_SetHindexCnt_Max(1, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(1, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(1, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(1, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(1, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(1, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(1, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(1, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(1, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(1, 43);
   FREG_VE_HD_SetVcnt_Count(1, 1119);
   FREG_VE_HD_SetHindexCnt_Max(2, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(2, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(2, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(2, 87);
   FREG_VE_HD_SetHlevcnt_2_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_2_Count(2, 1979);
   FREG_VE_HD_SetHlevcnt_3_Level(2, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(2, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(2, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(2, 43);
   FREG_VE_HD_SetVcnt_Count(2, 4);
   FREG_VE_HD_SetHindexCnt_Max(3, 4);
   FREG_VE_HD_SetHlevcnt_0_Level(3, 2);
   FREG_VE_HD_SetHlevcnt_0_Count(3, 43);
   FREG_VE_HD_SetHlevcnt_1_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_1_Count(3, 147);
   FREG_VE_HD_SetHlevcnt_2_Level(3, 3);
   FREG_VE_HD_SetHlevcnt_2_Count(3, 1919);
   FREG_VE_HD_SetHlevcnt_3_Level(3, 1);
   FREG_VE_HD_SetHlevcnt_3_Count(3, 593);
   FREG_VE_HD_SetHlevcnt_4_Level(3, 0);
   FREG_VE_HD_SetHlevcnt_4_Count(3, 43);
   FREG_VE_HD_SetVcnt_Count(3, 1119);

   FREG_VE_HD_SetEnable_En(1);
   
   FREG_GPIO_SetConfig_LcdRgbEn(0);
   
   h->enableDisable = 1;
   
   return res;
}


