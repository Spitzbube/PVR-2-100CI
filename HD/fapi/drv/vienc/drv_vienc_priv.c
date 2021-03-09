
#define DEBUG 4

#include <fapi/sys_services.h>
#include <fapi/reg_clkpwr.h>
#include <fapi/reg_gpio.h>
#include <fapi/reg_vo.h>
#include <fapi/reg_ve.h>
#include <fapi/reg_ve_hd.h>
#include <fapi/drv_gpio.h>
#include <fapi/drv_vienc.h>
#include <fapi/drv_vienc_priv.h>


static void func_21c69fbc(void);
int func_21c69df0(FAPI_VIENC_VideoEncoderHandleT* handle);
int func_21c6a208(FAPI_VIENC_VideoEncoderHandleT* handle);
int func_21c6a17c(FAPI_VIENC_VideoEncoderHandleT* handle);
int func_21c6a0f0(FAPI_VIENC_VideoEncoderHandleT* handle);
int func_21c69e94(FAPI_VIENC_VideoEncoderHandleT* handle);
int func_21c6a05c(FAPI_VIENC_VideoEncoderHandleT* handle);



/* 21c62de8 - complete */
int32_t fapi_vienc_hd_getcolourcomponent(FAPI_SYS_HandleT handle, 
            FAPI_VIENC_ComponentEnumT* colourComponent)
{
   FAPI_VIENC_VideoEncoderHandleT* r0 = handle;
   
   if (colourComponent == 0)
   {
      return -29109;
   }
   
   if (r0->colourComponent == FAPI_VIENC_UNKNOWN_COLOUR_COMPONENT)
   {
      return -29107;
   }
   
   *colourComponent = r0->colourComponent;
   
   return 0;
}


static INLINE void setRLutValue(unsigned offset)
{
   unsigned i;
   
   for (i = 0; i < 1024; i++)
   {
      unsigned r1 = 64;
      
      if (offset > 63)
      {
         r1 = (offset > 960)? 960: offset;
      }
   
      FREG_VO_SetRLut_Value(i, r1);
      offset++;
   }
}


static INLINE void setGLutValue(unsigned offset)
{
   unsigned i;
      
   for (i = 0; i < 1024; i++)
   {
      unsigned r1 = 64;
      
      if (offset > 63)
      {
         r1 = (offset > 960)? 960: offset;
      }

      FREG_VO_SetGLut_Value(i, r1);
      offset++;
   }         
}


static INLINE void setBLutValue(unsigned offset)
{
   unsigned i;
   
   for (i = 0; i < 1024; i++)
   {
      unsigned r1 = 64;
      
      if (offset > 63)
      {
         r1 = (offset > 960)? 960: offset;
      }

      FREG_VO_SetBLut_Value(i, r1);
      offset++;
   }
}


static INLINE void setRBLutValue(int offset)
{
   unsigned i;
   
   for (i = 0; i < 1024; i++)
   {
      int r1 = 64;
      
      if (offset > 63)
      {
         r1 = (offset > 960)? 960: offset;
      }

      FREG_VO_SetRLut_Value(i, r1);
      FREG_VO_SetBLut_Value(i, r1);
      offset++;
   }         
}


/* 21c62e14 - todo */
int32_t fapi_vienc_hd_changecolourcomponent(
            FAPI_SYS_HandleT handle,
            FAPI_VIENC_ColourSelectorEnumT col,
            uint32_t offset)
{
   FAPI_VIENC_VideoEncoderHandleT* r0 = handle;
   
   if (r0->opParams.encoderType == FAPI_VIENC_ENCODER_HD)
   {
      //21c62e2c
      FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
      FREG_VO_SetDispmixconfenable_Enablergblut(0);
      
      if (col == 0)
      {
         //21c62e44         
         setGLutValue(offset + 8);
      }
      //21c62e90
      else if (col == 1)
      {
         //21c62fa4         
         setRLutValue(offset + 8);
      }
      else
      {
         //21c62ea0
         setRBLutValue(-offset);         
      }
      
      FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
      FREG_VO_SetDispmixconfenable_Enablergblut(1);
//      return 0;
   }
   //21c62ef8
   else if (r0->opParams.encoderType == FAPI_VIENC_ENCODER_LCD)
   {
      FREG_VO_SetDispmixconfenable_Enableyuvlut(0);
      FREG_VO_SetDispmixconfenable_Enablergblut(0);
      
      switch (col)
      {
      case 0:
         //21c62f70
         setBLutValue(offset);
         //->21c62f58
         break;
         
      case 1:
         //21c62ff4
         setRBLutValue(-offset);
         //->21c62f58
         break;
         
      default:
         //21c62f28
         setRLutValue(offset);
         //->21c62f58
         break;
      }
      //21c62f58
      FREG_VO_SetDispmixconfenable_Enablergblut(1);
      FREG_VO_SetDispmixconfenable_Enableyuvlut(1);
   }
   else
   {
      return -29105;
   }
   
   return 0;
}


/* 21c6a6f4 - complete */
void func_21c6a6f4(void)
{
   FREG_VE_SetRgbconf_NtscOn(0);
   FREG_VE_SetCeconf_Secam(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetCeconf_Bwgui(0);
   FREG_VE_SetCeconf_Xsyncmx(0);
   FREG_VE_SetCeconf_Cydly(0);
   FREG_VE_SetCeconf_Cysel(0);
   FREG_VE_SetCeconf_M3db(0);
   FREG_VE_SetCeconf_Pal525(0);
   FREG_VE_SetCeconf_Pal(0);
   FREG_VE_SetCeconf_M1m0(0);
   FREG_VE_SetCeconf_Pslev(0);
   FREG_VE_SetCeburstint_Pal60mEn(0);
   FREG_VE_SetCeburstint_Fscint(0);
   FREG_VE_SetCeburstfra1_Fscfra238(0);
   FREG_VE_SetCeburstfra2_Fscfra70(0);
   FREG_VO_SetSdHorlinelength_HorLl(0);
   FREG_VO_SetSdVersize_VerSize(0);
   FREG_VE_SetSdVohorstart_VoHorStart(0);
   FREG_VE_SetSdVohorstop_VoHorStop(0);
   FREG_VE_SetSdVoverstart_VoVerStart(0);
   FREG_VE_SetSdVoverstop_VoVerStop(0);
   FREG_VO_SetDispcvbsversync(0);
   FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(0);
   FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(0);
   FREG_VO_SetSdvsyncoffset_Field(0);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(0);
   FREG_CLKPWR_SetSoftreset54_ResetVe(0);
   FREG_CLKPWR_SetSoftreset54_ResetVe(1);
}


/* 21c6a5fc - complete */
void func_21c6a5fc(void)
{
   FREG_VE_SetRgbconf_NtscOn(0);
   FREG_VE_SetCeconf_Secam(1);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetCeconf_Bwgui(0);
   FREG_VE_SetCeconf_Xsyncmx(0);
   FREG_VE_SetCeconf_Cydly(0);
   FREG_VE_SetCeconf_Cysel(0);
   FREG_VE_SetCeconf_M3db(0);
   FREG_VE_SetCeconf_Pal525(0);
   FREG_VE_SetCeconf_Pal(0);
   FREG_VE_SetCeconf_M1m0(0);
   FREG_VE_SetCeconf_Pslev(1);
   FREG_VE_SetCeburstint_Pal60mEn(0);
   FREG_VE_SetCeburstint_Fscint(0x541);
   FREG_VE_SetCeburstfra1_Fscfra238(0x3159);
   FREG_VE_SetCeburstfra2_Fscfra70(0x68);
   FREG_VO_SetSdHorlinelength_HorLl(0xd80);
   FREG_VO_SetSdVersize_VerSize(312);
   FREG_VE_SetSdVohorstart_VoHorStart(544);
   FREG_VE_SetSdVohorstop_VoHorStop(3352);
   FREG_VE_SetSdVoverstart_VoVerStart(23);
   FREG_VE_SetSdVoverstop_VoVerStop(311);
   FREG_VO_SetDispcvbsversync(0x100005);
   FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
   FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(310);
   FREG_VO_SetSdvsyncoffset_Field(1);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
}


/* 21c6a500 - complete */
void func_21c6a500(void)
{
   FREG_VE_SetRgbconf_NtscOn(1);
   FREG_VE_SetCeconf_Secam(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetCeconf_Bwgui(0);
   FREG_VE_SetCeconf_Xsyncmx(0);
   FREG_VE_SetCeconf_Cydly(0);
   FREG_VE_SetCeconf_Cysel(0);
   FREG_VE_SetCeconf_M3db(0);
   FREG_VE_SetCeconf_Pal525(0);
   FREG_VE_SetCeconf_Pal(0);
   FREG_VE_SetCeconf_M1m0(3);
   FREG_VE_SetCeconf_Pslev(0);
   FREG_VE_SetCeburstint_Pal60mEn(0);
   FREG_VE_SetCeburstint_Fscint(0x43e);
   FREG_VE_SetCeburstfra1_Fscfra238(0xf7a);
   FREG_VE_SetCeburstfra2_Fscfra70(0xd7);
   FREG_VO_SetSdHorlinelength_HorLl(3432);
   FREG_VO_SetSdVersize_VerSize(262);
   FREG_VE_SetSdVohorstart_VoHorStart(480);
   FREG_VE_SetSdVohorstop_VoHorStop(3320);
   FREG_VE_SetSdVoverstart_VoVerStart(19);
   FREG_VE_SetSdVoverstop_VoVerStop(259);
   FREG_VO_SetDispcvbsversync(0x100005);
   FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
   FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(260);
   FREG_VO_SetSdvsyncoffset_Field(1);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
}


/* 21c6a404 - complete */
static void func_21c6a404(void)
{
   FREG_VE_SetRgbconf_NtscOn(0);
   FREG_VE_SetCeconf_Secam(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetCeconf_Bwgui(0);
   FREG_VE_SetCeconf_Xsyncmx(0);
   FREG_VE_SetCeconf_Cydly(0);
   FREG_VE_SetCeconf_Cysel(0);
   FREG_VE_SetCeconf_M3db(0);
   FREG_VE_SetCeconf_Pal525(1);
   FREG_VE_SetCeconf_Pal(0);
   FREG_VE_SetCeconf_M1m0(0);
   FREG_VE_SetCeconf_Pslev(0);
   FREG_VE_SetCeburstint_Pal60mEn(1);
   FREG_VE_SetCeburstint_Fscint(0x43c);
   FREG_VE_SetCeburstfra1_Fscfra238(0xddf4);
   FREG_VE_SetCeburstfra2_Fscfra70(0x80);
   FREG_VO_SetSdHorlinelength_HorLl(3432);
   FREG_VO_SetSdVersize_VerSize(262);
   FREG_VE_SetSdVohorstart_VoHorStart(480);
   FREG_VE_SetSdVohorstop_VoHorStop(3320);
   FREG_VE_SetSdVoverstart_VoVerStart(19);
   FREG_VE_SetSdVoverstop_VoVerStop(259);
   FREG_VO_SetDispcvbsversync(0x100005);
   FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
   FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(260);
   FREG_VO_SetSdvsyncoffset_Field(1);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
}


/* 21c6a7e4 - todo */
int32_t fapi_vienc_sd_start(FAPI_SYS_HandleT handle)
{
   int r6 = 0;
   
   FAPI_VIENC_VideoEncoderHandleT* r5 = handle;
   
   FAPI_SYS_PRINT_DEBUG(4, "fapi_vienc_sd_start: interlaceProgressive=%d, colourSystem=%d, colourComponent=%d\n",
         r5->opParams.interlaceProgressive,
         r5->opParams.colourSystem,
         r5->opParams.colourComponent);
   
   if (((r5->opParams.interlaceProgressive != 0) &&
         (r5->opParams.interlaceProgressive != 1) &&
         (r5->opParams.interlaceProgressive != 2)) ||
         (r5->opParams.colourSystem == -1) ||
         (r5->opParams.colourComponent == -1))
   {
      //21c6aaa8
      FREG_VO_SetSdHorlinelength_HorLl(0);
      FREG_VO_SetSdVersize_VerSize(1);
      
      r6 = -29102;
      
      r5->enableDisable = 0;
      //->21c6a90c
   }   
   else
   {
      //21c6a810
      func_21c6a6f4();
      
      if (r5->opParams.interlaceProgressive == 2)
      {
         //21c6a914
         if (r5->opParams.colourSystem == 0)
         {
            //21c6a920
            func_21c6a5fc();
            //21c6a924
         }
         else
         {
            //->21c6a8f0
            FREG_VO_SetSdHorlinelength_HorLl(0);
            FREG_VO_SetSdVersize_VerSize(1);
            
            r5->enableDisable = 0;
            
            return -29103;
         }            
      }
      else if (r5->opParams.interlaceProgressive == 1)
      {
         //21c6a8cc
         if (r5->opParams.colourSystem == 1)
         {
            //21c6ab38
            func_21c6a500();
            //->21c6a924            
         }
         else if (r5->opParams.colourSystem == 2)
         {
            //21c6ab50
            FREG_VE_SetRgbconf_NtscOn(1);
            FREG_VE_SetCeconf_Secam(0);
            FREG_VE_SetCeconf_Ipce1sel(0);
            FREG_VE_SetCeconf_Bwgui(0);
            FREG_VE_SetCeconf_Xsyncmx(0);
            FREG_VE_SetCeconf_Cydly(0);
            FREG_VE_SetCeconf_Cysel(0);
            FREG_VE_SetCeconf_M3db(0);
            FREG_VE_SetCeconf_Pal525(0);
            FREG_VE_SetCeconf_Pal(0);
            FREG_VE_SetCeconf_M1m0(3);
            FREG_VE_SetCeconf_Pslev(0);
            FREG_VE_SetCeburstint_Pal60mEn(0);
            FREG_VE_SetCeburstint_Fscint(0x541);
            FREG_VE_SetCeburstfra1_Fscfra238(0x3159);
            FREG_VE_SetCeburstfra2_Fscfra70(0x68);
            FREG_VO_SetSdHorlinelength_HorLl(0xd68);
            FREG_VO_SetSdVersize_VerSize(262);
            FREG_VE_SetSdVohorstart_VoHorStart(480);
            FREG_VE_SetSdVohorstop_VoHorStop(3320);
            FREG_VE_SetSdVoverstart_VoVerStart(19);
            FREG_VE_SetSdVoverstop_VoVerStop(259);
            FREG_VO_SetDispcvbsversync(0x100005);
            FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
            FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(260);
            FREG_VO_SetSdvsyncoffset_Field(1);
            FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
            //->21c6a924
         }
         else if (r5->opParams.colourSystem == 4)
         {
            //21c6ac3c
            FREG_VE_SetRgbconf_NtscOn(0);
            FREG_VE_SetCeconf_Secam(0);
            FREG_VE_SetCeconf_Ipce1sel(0);
            FREG_VE_SetCeconf_Bwgui(0);
            FREG_VE_SetCeconf_Xsyncmx(0);
            FREG_VE_SetCeconf_Cydly(0);
            FREG_VE_SetCeconf_Cysel(0);
            FREG_VE_SetCeconf_M3db(0);
            FREG_VE_SetCeconf_Pal525(1);
            FREG_VE_SetCeconf_Pal(0);
            FREG_VE_SetCeconf_M1m0(0);
            FREG_VE_SetCeconf_Pslev(1);
            //->21c6abb4
            FREG_VE_SetCeburstint_Pal60mEn(1);
            FREG_VE_SetCeburstint_Fscint(0x541);
            FREG_VE_SetCeburstfra1_Fscfra238(0x3159);
            FREG_VE_SetCeburstfra2_Fscfra70(0x68);
            FREG_VO_SetSdHorlinelength_HorLl(0xd68);
            FREG_VO_SetSdVersize_VerSize(262);
            FREG_VE_SetSdVohorstart_VoHorStart(480);
            FREG_VE_SetSdVohorstop_VoHorStop(3320);
            FREG_VE_SetSdVoverstart_VoVerStart(19);
            FREG_VE_SetSdVoverstop_VoVerStop(259);
            FREG_VO_SetDispcvbsversync(0x100005);
            FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
            FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(260);
            FREG_VO_SetSdvsyncoffset_Field(1);
            FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
            //->21c6a924
         }
         else if (r5->opParams.colourSystem == 5)
         {
            //21c6a9c4
            func_21c6a404();
            //->21c6a924
         }
         else
         {
            //21c6a8f0
            FREG_VO_SetSdHorlinelength_HorLl(0);
            FREG_VO_SetSdVersize_VerSize(1);
            
            r5->enableDisable = 0;
            
            return -29103;
         }
      }
      else if (r5->opParams.interlaceProgressive == 0)
      {
         //21c6a830
         if (r5->opParams.colourSystem == 3)
         {
            //21c6aac8
            FREG_VE_SetRgbconf_NtscOn(0);
            FREG_VE_SetCeconf_Secam(0);
            FREG_VE_SetCeconf_Ipce1sel(0);
            FREG_VE_SetCeconf_Bwgui(0);
            FREG_VE_SetCeconf_Xsyncmx(0);
            FREG_VE_SetCeconf_Cydly(0);
            FREG_VE_SetCeconf_Cysel(0);
            FREG_VE_SetCeconf_M3db(0);
            FREG_VE_SetCeconf_Pal525(0);
            FREG_VE_SetCeconf_Pal(1);
            FREG_VE_SetCeconf_M1m0(0);
            //->21c6aa28
            FREG_VE_SetCeconf_Pslev(1);
            FREG_VE_SetCeburstint_Pal60mEn(0);
            FREG_VE_SetCeburstint_Fscint(0x541);
            FREG_VE_SetCeburstfra1_Fscfra238(0x3159);
            FREG_VE_SetCeburstfra2_Fscfra70(0x68);
            FREG_VO_SetSdHorlinelength_HorLl(3456);
            FREG_VO_SetSdVersize_VerSize(312);
            FREG_VE_SetSdVohorstart_VoHorStart(544);
            FREG_VE_SetSdVohorstop_VoHorStop(3352);
            FREG_VE_SetSdVoverstart_VoVerStart(23);
            FREG_VE_SetSdVoverstop_VoVerStop(311);
            FREG_VO_SetDispcvbsversync(0x100005);
            FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
            FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(310);
            FREG_VO_SetSdvsyncoffset_Field(1);
            FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
            //->21c6a924
         }
         else if (r5->opParams.colourSystem == 6)
         {
            //21c6a9cc
            FREG_VE_SetRgbconf_NtscOn(0);
            FREG_VE_SetCeconf_Secam(0);
            FREG_VE_SetCeconf_Ipce1sel(0);
            FREG_VE_SetCeconf_Bwgui(0);
            FREG_VE_SetCeconf_Xsyncmx(0);
            FREG_VE_SetCeconf_Cydly(0);
            FREG_VE_SetCeconf_Cysel(0);
            FREG_VE_SetCeconf_M3db(0);
            FREG_VE_SetCeconf_Pal525(0);
            FREG_VE_SetCeconf_Pal(1);
            FREG_VE_SetCeconf_M1m0(3);
            FREG_VE_SetCeconf_Pslev(0);
            FREG_VE_SetCeburstint_Pal60mEn(0);
            FREG_VE_SetCeburstint_Fscint(0x541);
            FREG_VE_SetCeburstfra1_Fscfra238(0x3159);
            FREG_VE_SetCeburstfra2_Fscfra70(0x68);
            FREG_VO_SetSdHorlinelength_HorLl(3456);
            FREG_VO_SetSdVersize_VerSize(312);
            FREG_VE_SetSdVohorstart_VoHorStart(544);
            FREG_VE_SetSdVohorstop_VoHorStop(3352);
            FREG_VE_SetSdVoverstart_VoVerStart(23);
            FREG_VE_SetSdVoverstop_VoVerStop(311);
            FREG_VO_SetDispcvbsversync(0x100005);
            FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
            FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(310);
            FREG_VO_SetSdvsyncoffset_Field(1);
            FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
            //->21c6a924
         }
         else if (r5->opParams.colourSystem == 7)
         {
            //21c6a84c
            FREG_VE_SetRgbconf_NtscOn(0);
            FREG_VE_SetCeconf_Secam(0);
            FREG_VE_SetCeconf_Ipce1sel(0);
            FREG_VE_SetCeconf_Bwgui(0);
            FREG_VE_SetCeconf_Xsyncmx(0);
            FREG_VE_SetCeconf_Cydly(0);
            FREG_VE_SetCeconf_Cysel(0);
            FREG_VE_SetCeconf_M3db(0);
            FREG_VE_SetCeconf_Pal525(0);
            FREG_VE_SetCeconf_Pal(1);
            FREG_VE_SetCeconf_M1m0(0);
            FREG_VE_SetCeconf_Pslev(1);
            FREG_VE_SetCeburstint_Pal60mEn(0);
            FREG_VE_SetCeburstint_Fscint(0x43e);
            FREG_VE_SetCeburstfra1_Fscfra238(0xd288);
            //->21c6aa48
            FREG_VE_SetCeburstfra2_Fscfra70(0xce);
            FREG_VO_SetSdHorlinelength_HorLl(3456);
            FREG_VO_SetSdVersize_VerSize(312);
            FREG_VE_SetSdVohorstart_VoHorStart(544);
            FREG_VE_SetSdVohorstop_VoHorStop(3352);
            FREG_VE_SetSdVoverstart_VoVerStart(23);
            FREG_VE_SetSdVoverstop_VoVerStop(311);
            FREG_VO_SetDispcvbsversync(0x100005);
            FREG_VE_SetSdhsyncoffset_Sdhsyncoffset(48);
            FREG_VO_SetSdvsyncoffset_Sdvsyncoffset(310);
            FREG_VO_SetSdvsyncoffset_Field(1);
            FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
            //->21c6a924
         }
         else if (r5->opParams.colourSystem == 5)
         {
            //21c6a9c4
            func_21c6a404();
            //->21c6a924
         }
         else
         {
            //21c6a8f0
            FREG_VO_SetSdHorlinelength_HorLl(0);
            FREG_VO_SetSdVersize_VerSize(1);
            
            r5->enableDisable = 0;
            
            return -29103;
         }
      }
      else
      {
         //21c6a8f0
         FREG_VO_SetSdHorlinelength_HorLl(0);
         FREG_VO_SetSdVersize_VerSize(1);
         
         r5->enableDisable = 0;
         
         return -29103;
      }         
      //21c6a924
      if (r5->opParams.crossChrominanceFilter == 1)
      {
         FREG_VE_SetSdCcfilterenable_SdCcfilterenable(1);
      }
      else
      {
         FREG_VE_SetSdCcfilterenable_SdCcfilterenable(0);
      }
      //21c6a934
      if (r5->opParams.colourComponent == 0)
      {
         //21c6a994
         r6 = func_21c69df0(r5);
         //->21c6a9a0
      }
      else if (r5->opParams.colourComponent == 3)
      {
         //21c6ab28
         r6 = func_21c6a208(r5);
         //->21c6a9a0
      }
      else if (r5->opParams.colourComponent == 4)
      {
         //21c6ab40
         r6 = func_21c6a17c(r5);
         //->21c6a9a0
      }
      else if (r5->opParams.colourComponent == 5)
      {
         //21c6ac2c
         r6 = func_21c6a0f0(r5);
         //->21c6a9a0
      }
      else if (r5->opParams.colourComponent == 6)
      {
         //21c6aca4
         r6 = func_21c69e94(r5);
         //->21c6a9a0
      }
      else if (r5->opParams.colourComponent == 7)
      {
         //21c6acb4
         r6 = func_21c6a05c(r5);
      }
      else
      {
         //21c6a964
         r6 = -29102;
      }
      //21c6a9a0
      if (r6 == 0)
      {
         //21c6a9a8
         r5->colourComponent = r5->opParams.colourComponent;
         
         FREG_VE_SetEnc656wss_WssPostTimingMode(1);
         FREG_VE_SetEnc656wss_WssTimingMode(1);
         //->21c6a90c
      }
      else
      {
         //21c6a96c
         r5->enableDisable = 0;
         
         FREG_VO_SetSdhvsynccfg_SdSyncEnable(0);
         FREG_VO_SetSdHorlinelength_HorLl(0);
         FREG_VO_SetSdVersize_VerSize(1);
      }
   }
   //21c6a90c
   return r6;
}


/* 21c6a3b0 - complete */
int32_t fapi_vienc_sd_stop(FAPI_SYS_HandleT handle)
{
   FAPI_VIENC_VideoEncoderHandleT* r5 = handle;

   FREG_VE_SetDacPd_Pddac3(1);
   FREG_VE_SetDacPd_Pddac4(1);
   FREG_VE_SetDacPd_Pddac5(1);
   FREG_VE_SetDacPd_Pddac6(1);
   
   r5->enableDisableWss = 0;
   
   FREG_VE_SetEnc656wss_WssMode(0);
   FREG_VO_SetSdHorlinelength_HorLl(0);
   FREG_VO_SetSdVersize_VerSize(1);
   
   r5->enableDisable = 0;
   
   return 0;
}


/* 21c6a370 - complete */
int32_t fapi_vienc_sd_enabledisablewss(FAPI_SYS_HandleT handle,
                                     FAPI_VIENC_ParameterModeEnumT mode)
{
   FAPI_VIENC_VideoEncoderHandleT* r3 = handle;

   switch (mode)
   {
   case FAPI_VIENC_PARAMETER_ON:
      r3->enableDisableWss = 1;
      FREG_VE_SetEnc656wss_WssMode(1);
      break;
      
   case FAPI_VIENC_PARAMETER_OFF:
      r3->enableDisableWss = 0;
      FREG_VE_SetEnc656wss_WssMode(0);
      break;
   }
   
   return 0;
}


/* 21c6a348 - complete */
int32_t fapi_vienc_sd_setwssdata(FAPI_SYS_HandleT handle, 
                                                       uint32_t wssData)
{
   FAPI_VIENC_VideoEncoderHandleT* r3 = handle;
   
   if (r3->enableDisableWss != 1)
   {
      return -29107;
   }

   FREG_VE_SetWssdata_Wssword(wssData);      

   return 0;
}


/* 21c6a31c - complete */
int32_t fapi_vienc_sd_getwssdata(FAPI_SYS_HandleT handle, 
                                                      uint32_t* wssData)
{
   FAPI_VIENC_VideoEncoderHandleT* r3 = handle;

   if (r3->enableDisableWss != 1)
   {
      return -29107;
   }
   
   *wssData = FREG_VE_GetmWssdata_Wssword();

   return 0;
}


/* 21c69df0 - complete */
int func_21c69df0(FAPI_VIENC_VideoEncoderHandleT* handle)
{
//   printf("21c69df0\n");
   
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r4 = handle;

   FREG_VE_SetLutConf_RgbLutEn(0);
   FREG_VE_SetLutConf_LutSel(0);
   FREG_VE_SetLutConf_LutEn(0);
   FREG_VE_SetRgbconf_Ycrcb(0);
   FREG_VE_SetDacPd_CeFilterFlag(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel4(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel5(1);
   FREG_VE_SetDacPd_Pddac3(0);
   FREG_VE_SetDacPd_Pddac4(1);
   FREG_VE_SetDacPd_Pddac5(1);
   FREG_VE_SetDacPd_Pddac6(1);
   FREG_VE_SetRgbconf_SynconRed(0);
   FREG_VE_SetRgbconf_SynconGree(0);
   FREG_VE_SetRgbconf_SynconBlue(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetRgbconf_Colbar(0);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(0);
   
   r4->enableDisable = 0;
   
   return res;
}


/* 21c6a208 - complete */
int func_21c6a208(FAPI_VIENC_VideoEncoderHandleT* handle)
{
//   printf("21c6a208\n");
  
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r4 = handle;

   func_21c69fbc();
   
   FREG_VE_SetDacPd_CeFilterFlag(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel4(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel5(1);
   FREG_VE_SetDacPd_Pddac3(0);
   FREG_VE_SetDacPd_Pddac4(0);
   FREG_VE_SetDacPd_Pddac5(0);
   FREG_VE_SetDacPd_Pddac6(0);
   FREG_VE_SetRgbconf_SynconRed(0);
   FREG_VE_SetRgbconf_SynconGree(1);
   FREG_VE_SetRgbconf_SynconBlue(0);
   FREG_VE_SetCeconf_Ipce1sel(1);
   FREG_VE_SetRgbconf_Colbar(1);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
   
   r4->enableDisable = 1;

   return res;
}


/* 21c6a17c - complete */
int func_21c6a17c(FAPI_VIENC_VideoEncoderHandleT* handle)
{
//   printf("21c6a17c\n");
   
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r4 = handle;

   func_21c69fbc();
   
   FREG_VE_SetDacPd_CeFilterFlag(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel4(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel5(1);
   FREG_VE_SetDacPd_Pddac3(0);
   FREG_VE_SetDacPd_Pddac4(1);
   FREG_VE_SetDacPd_Pddac5(1);
   FREG_VE_SetDacPd_Pddac6(1);
   FREG_VE_SetRgbconf_SynconRed(0);
   FREG_VE_SetRgbconf_SynconGree(0);
   FREG_VE_SetRgbconf_SynconBlue(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetRgbconf_Colbar(0);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
   
   r4->enableDisable = 1;

   return res;
}


/* 21c6a0f0 - complete */
int func_21c6a0f0(FAPI_VIENC_VideoEncoderHandleT* handle)
{
//   printf("21c6a0f0\n");
   
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r4 = handle;

   func_21c69fbc();
   
   FREG_VE_SetDacPd_CeFilterFlag(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel4(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel5(0);
   FREG_VE_SetDacPd_Pddac3(0);
   FREG_VE_SetDacPd_Pddac4(0);
   FREG_VE_SetDacPd_Pddac5(0);
   FREG_VE_SetDacPd_Pddac6(0);
   FREG_VE_SetRgbconf_SynconRed(0);
   FREG_VE_SetRgbconf_SynconGree(1);
   FREG_VE_SetRgbconf_SynconBlue(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetRgbconf_Colbar(0);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
   
   r4->enableDisable = 1;

   return res;
}


/* 21c6a05c - complete */
int func_21c6a05c(FAPI_VIENC_VideoEncoderHandleT* handle)
{
//   printf("21c6a05c\n");
   
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r4 = handle;

   func_21c69fbc();
   
   FREG_VE_SetRgbconf_Ycrcb(1);
   FREG_VE_SetDacPd_CeFilterFlag(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel4(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel5(1);
   FREG_VE_SetDacPd_Pddac3(0);
   FREG_VE_SetDacPd_Pddac4(0);
   FREG_VE_SetDacPd_Pddac5(0);
   FREG_VE_SetDacPd_Pddac6(0);
   FREG_VE_SetRgbconf_SynconRed(0);
   FREG_VE_SetRgbconf_SynconGree(1);
   FREG_VE_SetRgbconf_SynconBlue(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetRgbconf_Colbar(0);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
   
   r4->enableDisable = 1;

   return res;
}


/* 21c69fbc - complete */
void func_21c69fbc(void)
{
   int r1;
   unsigned r5 = 0;
   
   for (r5 = 0; r5 < 256; r5++)
   {
      FREG_VE_SetLutY_Data(r5, r5*2 + r5/2);
      
      r1 = (r5 - 128)*3;
      if (r1 >= 512) r1 = 511;
      else if (r1 < -512) r1 = -512;
            
      FREG_VE_SetLutCb_Data(r5, r1);

      r1 = r5 - 128;
      r1 = r1*2 + r1/8 + r1/64;
      
      FREG_VE_SetLutCr_Data(r5, r1);
   }
   
   FREG_VE_SetLutConf_RgbLutEn(0);
   FREG_VE_SetLutConf_LutSel(0);
   FREG_VE_SetLutConf_LutEn(0);
}


/* 21c69e94 - complete */
int func_21c69e94(FAPI_VIENC_VideoEncoderHandleT* handle)
{
//   printf("21c69e94\n");
   
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r7 = handle;

#if 0
   func_21c69fbc();
#else
   {
      int r1;
      unsigned r5 = 0;
      
      for (r5 = 0; r5 < 256; r5++)
      {
         FREG_VE_SetLutY_Data(r5, r5*2 + r5/2);
         
         r1 = (r5 - 128)*3;
         if (r1 >= 512) r1 = 511;
         else if (r1 < -512) r1 = -512;
               
         FREG_VE_SetLutCb_Data(r5, r1);

         r1 = r5 - 128;
         r1 = r1*2 + r1/8 + r1/64;
         
         FREG_VE_SetLutCr_Data(r5, r1);
      }
      
      FREG_VE_SetLutConf_RgbLutEn(0);
      FREG_VE_SetLutConf_LutSel(0);
      FREG_VE_SetLutConf_LutEn(0);
   }
#endif
   
   FREG_VE_SetRgbconf_Ycrcb(0);
   FREG_VE_SetDacPd_CeFilterFlag(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel012(0);
   FREG_VO_SetDispdachdmictrl_Dispdacsel4(1);
   FREG_VO_SetDispdachdmictrl_Dispdacsel5(1);
   FREG_VE_SetDacPd_Pddac3(0);
   FREG_VE_SetDacPd_Pddac4(0);
   FREG_VE_SetDacPd_Pddac5(0);
   FREG_VE_SetDacPd_Pddac6(0);
   FREG_VE_SetRgbconf_SynconRed(0);
   FREG_VE_SetRgbconf_SynconGree(0);
   FREG_VE_SetRgbconf_SynconBlue(0);
   FREG_VE_SetCeconf_Ipce1sel(0);
   FREG_VE_SetRgbconf_Colbar(0);
   FREG_VO_SetSdhvsynccfg_SdSyncEnable(1);
   
   r7->enableDisable = 1;

   return res;
}


/* 21c6a294 - complete */
int32_t fapi_vienc_sd_setcolourcomponent(FAPI_SYS_HandleT handle, 
                              FAPI_VIENC_ComponentEnumT colourComponent)
{
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r5 = handle;

   if (colourComponent == FAPI_VIENC_COMPONENT_DAC_POWER_DOWN)
   {
      res = func_21c69df0(r5);
      r5->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_COLOURBAR)
   {
      res = func_21c6a208(r5);
      r5->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_CVBS)
   {
      res = func_21c6a17c(r5);
      r5->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_CVBS_YC)
   {
      res = func_21c6a0f0(r5);
      r5->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_CVBS_RGB)
   {
      res = func_21c69e94(r5);
      r5->colourComponent = colourComponent;
   }
   else if (colourComponent == FAPI_VIENC_COMPONENT_CVBS_YPrPb)
   {
      res = func_21c6a05c(r5);
      r5->colourComponent = colourComponent;
   }
   else
   {
      res = -29109;
   }
      
   return res;
}


/* 21c69dc4 - complete */
int32_t fapi_vienc_sd_getcolourcomponent(FAPI_SYS_HandleT handle, 
                             FAPI_VIENC_ComponentEnumT* colourComponent)
{
   int res = 0;
   FAPI_VIENC_VideoEncoderHandleT* r0 = handle;
   
   if (colourComponent != 0)
   {
      if (r0->colourComponent != -1)
      {
         *colourComponent = r0->colourComponent;
      }
      else
      {
         res = -29107;
      }
   }
   else
   {
      res = -29109;
   }

   return res;
}


